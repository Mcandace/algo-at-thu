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
    vector<int>::const_iterator it = num.begin(); // for the generation of left and right, see below
    vector<int> left(it+start, it+mid+1), right(it+mid+1, it+end+1);
    /*
     * leftIndex: points to the num under manipulation in the left array now.
     * leftIndexMax: the max index (accessible) of left array.
     * the same for right-xxx.
     */
    int leftIndex = 0, rightIndex = 0, leftIndexMax = mid - start, rightIndexMax = end - mid - 1;
    for (; start <= end; ++start)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            num[start] = left[leftIndex];
            if (leftIndex == leftIndexMax)
            {
                /* if left index reached the boundary,
                 * then just copy the rest in right to mother.
                 * and finish the merge part afterwards.
                 */
                for (++start; start <= end; ++start, ++rightIndex)
                    num[start] = right[rightIndex];
                return;
            }
            ++leftIndex;
        }
        else
        {
            num[start] = right[rightIndex];
            if (rightIndex == rightIndexMax)
            {
                // same as above
                for (++start; start <= end; ++start, ++leftIndex)
                    num[start] = left[leftIndex];
                return;
            }
            ++rightIndex;
        }
    }
}

