#include <stdio.h>

int main()
{
    int ans[150] = {};
    char input;
    int time; // 換行次數
    int count = 0;

    scanf("%d", &time); // 讀取換行次數

    // 一個字元一個字元讀取
    while (scanf("%c", &input) != EOF)
    {
        // 將char轉成int (ascii碼)
        int temp = (int)input;

        // 字母a到z轉成A到Z
        if (temp >= 97 && temp <= 122)
        {
            // 小寫字母轉成大寫字母ascii碼 -32
            temp -= 32;
            ans[temp]++; // ans[i]表示用askii碼表示的i的字母出現次數
        }
        else if (temp >= 65 && temp <= 90)
        {
            ans[temp]++; // ans[i]表示用askii碼表示的i的字母出現次數
        }

        // askii碼10表示換行(\n)
        else if (temp == 10)
        {
            count++;
        }
        // 當換行次數達到time時跳出迴圈
        if (count == time + 1)
        {
            break;
        }
    }

    int i;
    int max = 0;
    // 第一個for迴圈找出出現次數最多的字母次數
    for (i = 65; i <= 90; i++)
    {
        if (ans[i] > max)
        {
            max = ans[i];
        }
    }
    // 第二個for迴圈從出現次數最多的字母開始印出
    // 有因為ans陣列的i是按照askii碼排序的
    // 所以i不需要再排序
    for (i = max; i > 0; i--)
    {
        int j;
        for (j = 65; j <= 90; j++)
        {
            if (ans[j] == i)
            {
                //%c跟%d中間有個空格
                printf("%c %d\n", (char)j, ans[j]);
            }
        }
    }
    return 0;
}
