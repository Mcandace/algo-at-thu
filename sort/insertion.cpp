/*
 * insertion sort
 * input: int array without number clarified
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int tmp;
    while (cin >> tmp)
        num.push_back(tmp);
    int i, j;
    const int len = num.size();
    for (i = 1; i < len; ++i)
    {
        tmp = num[i];
        for (j = i - 1; j >=0 && num[j] > tmp; --j)
            num[j+1] = num[j];
        num[j+1] = tmp;
    }
    cout << "sorted array:" << endl << num.at(0);
    for (i = 1; i < len; ++i)
        cout << " " << num[i];
    cout << endl;
    return 0;
}

