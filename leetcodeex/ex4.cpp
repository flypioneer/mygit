#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
using namespace std;


//LeetCode解答
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while(x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT32_MAX / 10 || (rev == INT32_MAX /10 && pop > 7 ))
            return 0;
            if (rev < INT32_MIN / 10 || (rev == INT32_MIN / 10 && pop < -8))
            return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
   //解答过程
};


//测试
int main()
{
    Solution so1;
    int out;
    out = so1.reverse(3270);
    cout<< out <<endl;
    //测试用例
    

    //待测试方法

    

    //结果打印
    
    return 0;
}