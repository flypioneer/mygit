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
    int climbStairs(int n){
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.climbStairs(2);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}