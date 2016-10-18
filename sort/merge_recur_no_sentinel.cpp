#include <iostream>
#include <vector>
using namespace std;

void devide(vector<int> &, int, int);
void merge(vector<int> &, int, int, int);

int main()
{
    vector<int> num;
    int tmp;
    while (cin >> tmp)
        num.push_back(tmp);
    int i;
    const int len = num.size();
    devide(num, 0, len - 1);
    cout << "sorted array:" << endl << num.at(0);
    for (i = 1; i < len; ++i)
        cout << " " << num.at(i);
    cout << endl;
    return 0;
}

void devide(vector<int> & num, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        devide(num, start, mid);
        devide(num, mid+1, end);
        merge(num, start, mid, end);
    }
}

void merge(vector<int> & num, int start, int mid, int end)
{
    vector<int> left, right;
    vector<int>::iterator it = num.begin();
    left.assign(it+start, it+mid+1);
    right.assign(it+mid+1, it+end+1);
    int leftIndex = 0, rightIndex = 0, thruIndex = start, leftIndexMax = mid - start + 1, rightIndexMax = end - mid;
    bool leftDone = false; //true for left used up, false for right used up
    for (it = num.begin() + thruIndex; thruIndex <= end; ++thruIndex)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            *it = left[leftIndex];
            ++leftIndex;
        }
        else
        {
            *it = right[rightIndex];
            ++rightIndex;
        }
        ++it;
        if (leftIndex == leftIndexMax)
        {
            leftDone = true;
            break;
        }
        if (rightIndex == rightIndexMax)
        {
            leftDone = false;
            break;
        }
    }
    if (leftDone)
    {
        for (; rightIndex < rightIndexMax; ++rightIndex, ++it)
            *it = right[rightIndex];
    }
    else
    {
        for (; leftIndex < leftIndexMax; ++leftIndex, ++it)
            *it = left[leftIndex];
    }
}

