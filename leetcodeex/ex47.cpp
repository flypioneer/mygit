#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<cmath>
using namespace std;


//LeetCode解答
class Solution
{
public:
    int climbStairs(int n){
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int) round(fibn / sqrt5);
    }

  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.climbStairs(5);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}