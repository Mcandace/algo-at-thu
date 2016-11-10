/*
 * dynamic programming
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

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
    const int len = priceDiff.size();
    int maxSum = priceDiff[0], buyDay = 0, sellDay = 1, maxEver = 0;
    for (int i = 1; i < len; ++i)
    {
        if (maxSum > 0) // if maxBene[sell at previous day] > 0, then add this day in and remain the "buy date"
        {
            maxSum += priceDiff[i]; // new maxBene
            if (priceDiff[i] >= 0 && maxSum >= maxEver) // if higher(equal okay) maxBene, then modify the sell date to this day
            {
                maxEver = maxSum;
                sellDay = i + 1;
            }
        }
        else //if maxBene[sell at previous day] < 0, then just rather buy in on this day, i.e., dump the previous record
        {
            maxSum = priceDiff[i]; // start from today
            buyDay = i;
            if (maxEver < maxSum) // update max ever num if possible
                maxEver = maxSum;
        }
    }
    if (maxEver > 0)
        cout << "buyDay: " << buyDay + 1 << ", sellDay: " << sellDay << endl;
    else
        cout << "don't fucking even buy" << endl;
    fin.close();
    cout << "執行時間: " << clock() - startTime << "ms" << endl; // 輸出此段程式運行時間
    return 0;
}

