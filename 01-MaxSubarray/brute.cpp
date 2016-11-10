/*
 * 4.1 - max subarray
 * brute force
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
    //cin >> prevDay;
    //while (cin >> nextDay)
    {
        priceDiff.push_back(nextDay - prevDay); // 將差值依次加入差價數組
        prevDay = nextDay;
    }

    // 預設最大獲利為第0天買入第1天賣出，以及相應的購入、售出日期
    int maxBenefit = priceDiff[0], buyDay = 0, sellDay = 1, curBenefit;
    const int lastDay = priceDiff.size() - 1; // 最後一天的下標
    for (prevDay = 0; prevDay < lastDay; ++prevDay) // 對於買入的日期循環
    {
        //當天買入次日賣出的獲利
        for (curBenefit = priceDiff[prevDay], nextDay = prevDay; nextDay <= lastDay; curBenefit += priceDiff[++nextDay])
        {
            if (maxBenefit < curBenefit)
            {
                maxBenefit = curBenefit;
                buyDay = prevDay;
                sellDay = nextDay;
            }
        }
    }
    if (maxBenefit > 0)
        cout << "第" << buyDay + 1 << "日買進第" << sellDay + 1 << "日賣出就對了！" << endl;
    else
        cout << "別買了，必虧" << endl;

    fin.close();
    cout << "執行時間: " << clock() - startTime << "ms" << endl; // 輸出此段程式運行時間
    return 0;
}

