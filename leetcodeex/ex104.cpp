/* 常量和变量说明
n: 长钢条的长度
p[]:价格数组
*/

#define LEN 100

int Top_Down_Cut_Rod(int p[], int n){//自顶向下
    int r = 0;
    int i;
    if (n == 0)
    {
        return 0;
    }
    for (i = 1; i < n; i++)
    {
        int tmp = p[i] + Top_Down_Cut_Rod(p, n - i);
        r = (r >= tmp) ? r : tmp;
    }
    return r;
}

int Bottom_Up_Cut_Rod(int p[], int n)
{
    //自底向上
    int r[LEN] = {0};
    int temp = 0;
    int i, j;
    for(j = 1; j <= n; j++)
    {
        temp = 0;
        for(i = 1; i <=j; i++)
        {
            temp= temp>=p[i] + r[j - i]?temp:p[i]+r[j-i];
        }
        r[j] = temp;
    }
    return r[n];
}