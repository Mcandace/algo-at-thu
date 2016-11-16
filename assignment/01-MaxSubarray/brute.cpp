/*
 * 4.1 - max subarray
 * brute
 * just pick 2 days' prices and do subtraction
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

    vector<int> price; // 未知數目 用vector儲存
    int tmp;
    while (fin >> tmp) // 讀到文件結束為止
        price.push_back(tmp); // 將值依次加入價格數組

    const int lastDay = price.size() - 1; // 最後一天價格的下標
    int buyDay, sellDay, i, j, curBenefit;
    tmp = 0; // 用tmp記錄最大獲利
    for (i = 0; i < lastDay; ++i) // 對於買入的日期循環
    {
        for (j = i + 1; j <= lastDay; ++j) // 對賣出日期循環
        {
            curBenefit = price[j] - price[i]; // 當前情況下獲利
            if (tmp < curBenefit) // 若超過之前的最大獲利
            {
                tmp = curBenefit; // 更新最大獲利
                buyDay = i; // 更新買入日期
                sellDay = j; // 更新賣出日期
            }
        }
    }
    if (tmp > 0) // 若有獲利
        cout << "第" << buyDay << "日收盤買進第" << sellDay << "日收盤賣出就對了！" << endl;
    else // 若不可能獲利
        cout << "別買了" << endl;

    fin.close(); // 關閉文件
    cout << "執行時間: " << clock() - startTime << "ms" << endl; // 輸出程式運行時間
    return 0;
}

