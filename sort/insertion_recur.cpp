/*
 * practice 2.3-4
 * insertion sort with recursion
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * @para bounday: is the max index accessible
 */
void InsertRecur(vector<int> & num, int boundary)
{
    if (boundary)
    {
        int i = boundary - 1, end = num[boundary];
        InsertRecur(num, i);
        for (; i >= 0 && num[i] > end; --i)
            num[i+1] = num[i];
        num[i+1] = end;
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
    InsertRecur(num, maxIndex);
    cout << "sorted array:" << endl << num[0];
    for (i = 1; i <= maxIndex; ++i)
        cout << " " << num[i];
    cout << endl;
    return 0;
}

