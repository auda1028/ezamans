#include <stdio.h>

int main()
{
    int n;//case數
    int T[1000];//儲存每個case的結果

    //讀取case數
    scanf("%d", &n);
    int i;

    //讀取每個case的資料並計算結果
    for (i = 0; i < n; i++)
    {
        int days;//需要模擬的天數
        int day[4000] = {}; // day[i]紀錄每一天是否有派對 i表示第i天
        scanf("%d", &days);
        int j;

        // 標記週末 (週六、週日)為不可舉辦派對的日子 設定為-1
        for (j = 1; j <= days; j++)
        {
            // 禮拜日設為第一天(1) 禮拜五設為第六天(6) 禮拜六設為第七天(7)
            if (j % 7 == 6 || j % 7 == 0)
            {
                day[j] = -1;
            }
        }

        // 部門數? 英文沒看懂
        int party;
        scanf("%d", &party);
        for (j = 0; j < party; j++)
        {
            // 讀取頻率
            int dd = 0;
            scanf("%d", &dd);
            int k;
            for (k = days; k > 0; k--)
            {
                if (k % dd == 0 && day[k] != -1) // 被整除且不是週末
                {
                    day[k] = 1;
                }
            }
        }

        // 計算少上幾天班
        int count = 0;
        for (j = 1; j <= days; j++)
        {
            if (day[j] == 1)//被標記為1的天數
            {
                count++;
            }
        }

        T[i] = count; //儲存結果
    }

    //輸出每個case的結果
    for (i = 0; i < n; i++)
    {
        printf("%d\n", T[i]);
    }
    return 0;
}
