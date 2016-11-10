/*
 * brute
 * not creating price differnce array
 * but just pick 2 days and substraction
 *
 * for check use
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
        price.push_back(tmp); // 將值依次加入差價數組

    tmp = 0;
    int buyDay = 0, sellDay = 0, i, j, curBenefit;
    const int lastDay = price.size() - 1; // 最後一天的下標
    for (i=0; i<lastDay; ++i) // 對於買入的日期循環
    {
        for (j=i+1; j<=lastDay; ++j)
        {
            curBenefit = price[j] - price[i];
            if (tmp < curBenefit)
            {
                tmp = curBenefit;
                sellDay = j;
                buyDay = i;
            }
        }
    }
    if (tmp > 0)
        cout << "第" << buyDay + 1 << "日買進第" << sellDay << "日賣出就對了！" << endl;
    else
        cout << "別買了，必虧" << endl;

    fin.close();
    cout << "執行時間: " << clock() - startTime << "ms" << endl; // 輸出此段程式運行時間
    return 0;
}


