/*
 * heap sort
 *
 * NOTE: index!!
 * since index start from 0 to n-1,
 * left son = i * 2 + 1,
 * right son = i * 2 + 2.
 * max accessible non-leaf node's index is "floor(SIZE / 2) - 1"
 */

#include <iostream>
#include <vector>
using namespace std;

int maxIndex; // max index of the accessible value
void maxheapify(vector<int> & heap, int i)
{
    int leftSon = i * 2 + 1, rightSon = leftSon + 1, greatest = i;
    if (leftSon > maxIndex) // left son has overflowed, no need to proceed
        return ;
    else if (heap[leftSon] > heap[i]) //left son still in
        greatest = leftSon;
    if (rightSon <= maxIndex && heap[rightSon] > heap[greatest])
        greatest = rightSon;
    if (greatest != i)
    {
        int tmp = heap[greatest];
        heap[greatest] = heap[i];
        heap[i] = tmp;
        maxheapify(heap, greatest);
    }
}

void buildMaxheap(vector<int> & heap)
{
    maxIndex = heap.size() - 1; // initialize here
    for (int i = maxIndex / 2; i >= 0; --i)
        maxheapify(heap, i);
}

void heapsort(vector<int> & heap)
{
    buildMaxheap(heap);
    for (int i = maxIndex; i > 0; --i)
    {
        int tmp = heap[0];
        heap[0] = heap[i];
        heap[i] = tmp;
        --maxIndex;
        maxheapify(heap, 0);
    }
}

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int i;
    while (cin >> i)
        num.push_back(i);
    const int len = num.size();
    heapsort(num);
    cout << "sorted array:" << endl << num[0];
    for (i = 1; i < len; ++i)
        cout << " " << num[i];
    cout << endl;
    return 0;
}

