/*
 * bucket sort
 *
 * use (A[i] / (A.max+1) * A.length)
 * to allocate the array elements into
 * the corresponding buckets
 *
 * use insertion sort to sort within
 * a bucket if necessary
 */

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& A)
{
    const int len = A.size();
    for (int i = 1; i < len; ++i)
    {
        const int key = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] > key; --j)
            A[j+1] = A[j];
        A[j+1] = key;
    }
}

struct bucketInfo
{
    int elementNum;
    vector<int> element;
    bucketInfo(): elementNum(0) {} // default no element
};

void bucketSort(const vector<int>& A, const int& len, const int& scale)
{
    bucketInfo buckets[len]; // build as many buckets as A.length
    for (int i = 0; i < len; ++i) // put nums into buckets
    {
        int key = (A[i] * len) / scale; // the # of the bucket to be put in
        // A ∈ [0, scale)
        // A/scale ∈ [0,1)
        // A/scale*len ∈ [0,len)
        buckets[key].element.push_back(A[i]); // put it in
        ++buckets[key].elementNum; // increase counter
    }
    for (int i = 0; i < len; ++i) // check all the buckets
        if (buckets[i].elementNum> 1) // if more than one in it
            insertionSort(buckets[i].element); // insertion sort
    // buckets can't be *static* here, so just output in this function
    cout << endl << "sorted array:" << endl;
    for (int i = 0; i < len; ++i)
        if (buckets[i].elementNum)
            for (int j = 0; j < buckets[i].elementNum; ++j)
                cout << buckets[i].element[j] << endl;
}

int main()
{
    cout << "input the array please:" << endl;
    vector<int> num;
    int i, k = -1;
    while (cin >> i) // input: all positive int
    {
        num.push_back(i);
        if (k < i)
            k = i;
    }
    const int len = num.size();
    bucketSort(num, len, k+1);
    return 0;
}

