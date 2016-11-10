/*
 * 4.1 - max subarray
 * divide and conquer
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

// 記錄最大子數組左右邊界下標和數值的struct，
// 可用作返回值。
struct maxSubarrayInfo
{
    int low, high, sum;
    maxSubarrayInfo(int low_, int high_, int sum_):
        low(low_), high(high_), sum(sum_) { }
};

maxSubarrayInfo maxCrossSubarray(const vector<int> & mother, int low, int mid, int high)
{
    int i, curSum, // 循環變量i, curSum記錄當前加和
        leftSum = mother[mid], rightSum = mother[mid+1], // leftSum和rightSum為左/右子序列最大和,初始化為初始可能值
        leftSumIndex = mid, rightSumIndex = mid + 1; // 記錄最大和時的下標，初始化同上

    for (curSum = mother[(i = mid)]; i >= low; curSum += mother[--i]) // 尋找左邊子序列最大
        if (leftSum < curSum)
        {
            leftSum = curSum;
            leftSumIndex = i;
        }

    for (curSum = mother[(i = mid + 1)]; i <= high; curSum += mother[++i]) // 尋找右邊子序列最大
        if (rightSum < curSum)
        {
            rightSum = curSum;
            rightSumIndex = i;
        }

    return maxSubarrayInfo(leftSumIndex, rightSumIndex, leftSum + rightSum);
}

maxSubarrayInfo maxSubarray(const vector<int> & mother, int low, int high)
{
    if (low == high) // 只有一個值時，無需解決，直接返回
        return maxSubarrayInfo(low, high, mother[low]);

    int mid = low + (high - low) / 2; // 計算中點 ps避免 (low + high) 可能的溢出
    maxSubarrayInfo leftMax = maxSubarray(mother, low, mid); // 最大和出現在左側
    maxSubarrayInfo rightMax = maxSubarray(mother, mid+1, high); // 最大和出現在右側
    maxSubarrayInfo midMax = maxCrossSubarray(mother, low, mid, high); //最大和跨過中點

    // 比較結果，返回三者中最大值
    if (leftMax.sum > rightMax.sum && leftMax.sum > midMax.sum)
        return leftMax;
    if (rightMax.sum > leftMax.sum && rightMax.sum > midMax.sum)
        return rightMax;
    return midMax;
}

int main()
{
    ifstream fin("input.txt", ios::in); // 建立文件流以讀取文件中數據
    if (!fin.is_open()) // 檢查以防文件打開失敗
    {
        cout << "打開輸入文件錯誤" << endl;
        return -1;
    }

    double startTime = clock(); // 記錄程式開始時刻
    int prevDay, nextDay; // nextDay - prevDay 即為相鄰兩日的差價
    vector<int> priceDiff; // 未知數目 用vector儲存
    fin >> prevDay; // 先讀入 day0 價格
    while (fin >> nextDay) // 讀到文件結束為止
    {
        priceDiff.push_back(nextDay - prevDay); // 將差值依次加入差價數組
        prevDay = nextDay;
    }
    const int maxIndex = priceDiff.size() - 1; // 最大下標

    maxSubarrayInfo result = maxSubarray(priceDiff, 0, maxIndex); // 調用函數，對整個數組計算
    if (result.sum > 0) // 若有獲利
        cout << "第" << result.low + 1 << "日買進第" << result.high + 1 << "日賣出就對了！" << endl;
    else // 若不可能獲利
        cout << "別買了" << endl;

    fin.close(); // 關閉文件
    cout << "執行時間: " << clock() - startTime << "ms" << endl; // 輸出此段程式運行時間
    return 0;
}

