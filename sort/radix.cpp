/*
 * radix sort
 * fixed radix of 10
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int i, maxNum = 0;
    while (cin >> i)
    {
        num.push_back(i);
        if (maxNum < i)
            maxNum = i;
    }

    const int len = num.size(); // # of array elements
    const int digit = log10(maxNum) + 1; // i.e., # of radix sort main loop
    const int myRadix = 10; // here, radix is fixed to be 10
    int cdf[myRadix]; // for counting sort
    int copyArray[len]; // to store a copy of num (neede in counting sort)
    int* vectorPointer = &num[0]; // for memcpy
    const size_t bitLen = len * sizeof(int); // the bits to copy
    const size_t bucketSize = sizeof(cdf);
    int base = 1; // (num/base)%10 is the certain digit
    for (i = 1; i <= digit; ++i) // radix sort main loop
    {
        memset(cdf, 0, bucketSize); // initialize the 10 buckets
        memcpy(copyArray, vectorPointer, bitLen); // copy the array
        // counting sort
        for (int j = 0; j < len; ++j)
          ++cdf[(copyArray[j]/base)%10]; // ele/base MOD 10 is the key
        for (int j = 1; j < myRadix; ++j)
          cdf[j] += cdf[j-1];
        for (int j = len - 1; j >= 0; --j)
        {
            int numOnThisDigit = (copyArray[j] / base) % 10;
            num[cdf[numOnThisDigit]-1] = copyArray[j];
            --cdf[numOnThisDigit];
        }
        base *= 10; // move one digit forward
    }

    cout << "\nsorted array:" << endl << num[0];
    for (i = 1; i < len; ++i)
        cout << " " << num[i];
    cout << endl;

    return 0;
}

