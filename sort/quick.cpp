/*
 * quick sort
 * random pivot
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;

int partition(vector<int> & num, int left, int right)
{
    int pivot = num[right]; // pivot to compare with
    int wall = left - 1; // initial wall location
    for (int cur = left; cur < right; ++cur) // for every num in the array, expect the pivot itself
        if (num[cur] <= pivot) // if the num <= pivot
        {
            // move the wall to right, making room for this "smaller" num
            int tmp = num[++wall]; // put it in this "newly-made" room by swap
            num[wall] = num[cur];
            num[cur] = tmp;
        }
    num[right] = num[++wall]; // make room for the pivot, and swap it to the due place
    num[wall] = pivot;
    return wall;
}

int randomPartition(vector<int> & num, int left, int right)
{
    // swap the last num of the subarray with a random one
    int random = rand() % (right - left + 1) + left;
    if (random != right)
    {
        int tmp = num[right];
        num[right] = num[random];
        num[random] = tmp;
    }
    return partition(num, left, right);
}

void quicksort(vector<int> & num, int left, int right)
{
    if (left < right)
    {
        int wall = randomPartition(num, left, right);
        quicksort(num, left, wall - 1);
        quicksort(num, wall + 1, right);
    }
}

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int i;
    while (cin >> i)
        num.push_back(i);
    const int maxIndex = num.size() - 1;
    srand((unsigned)time(NULL));
    quicksort(num, 0, maxIndex);
    cout << "sorted array:" << endl << num[0];
    for (i = 1; i <= maxIndex; ++i)
        cout << " " << num[i];
    cout << endl;
    return 0;
}

