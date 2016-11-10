/*
 * counting sort
 * NOTE: index!
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int i, k = -1;
    while (cin >> i)
    {
        num.push_back(i);
        if (k < i)
            k = i;
    }
    const int len = num.size();

    int *cdf = new int [k+1], *sorted = new int [len];
    memset(cdf, 0, sizeof(int) * (k + 1));

    for (i=0; i<len; ++i) // calc pdf first
        ++cdf[num[i]];

    for (i=1; i<=k; ++i) // calc cdf now
        cdf[i] += cdf[i-1];

    for (i=len-1; i>=0; --i)
    {
        // for n numbers, the max num's cdf is n,
        // but the index for this max num is n-1
        sorted[cdf[num[i]]-1] = num[i];
        --cdf[num[i]];
    }

    cout << "sorted array:" << endl << sorted[0];
    for (i = 1; i < len; ++i)
        cout << " " << sorted[i];
    cout << endl;
    delete [] sorted;
    delete [] cdf;
    return 0;
}


