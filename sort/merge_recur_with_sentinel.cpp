#include <iostream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

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
    left.push_back(INF);
    right.assign(it+mid+1, it+end+1);
    right.push_back(INF);
    int leftIndex = 0, rightIndex = 0, thruIndex = start;
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
    }
}

