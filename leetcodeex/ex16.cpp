#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
using namespace std;


//LeetCode解答
class Solution
{
public:
    int reverse (int x)
    {
        int rev = 0;
        while (x != 0)
        {
            //每次取末尾数字
            int tmp = x % 10;
            //判断是否大于最大32位整数
            if (rev > 214748364 || (rev == 214748364 && tmp >7))
            {
                return 0;
            }
            //判断是否小于最小32位整数
            if (rev < -214748364 || (rev == -214748364 && tmp < -8))
            {
                return 0;
            }
            rev = rev *10 + tmp;
            x /= 10;
        }
        return rev;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.reverse(3520);
    cout<< out << endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}