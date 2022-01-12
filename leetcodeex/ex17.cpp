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
    bool isPalindrome(int x){
        //特殊情况：
        //1，如上所述，当x < 0时，x 不是回文数；
        //2,同样地，如果数字的最后一位是0,为了使该数字为回文，则其第一位数字也为0，只有0满足这一属性。
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber){
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        //当数字长度为奇数时，我们可以通过revertedNumber /10去除处于中位的数字。
        //由于处于中位的数字不影响回文(它总是与自己相等)，所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;

    
    }
};


//测试
int main()
{
    //测试用例
    Solution so1;
    bool ret = so1.isPalindrome(54242);
    cout<< ret << endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}