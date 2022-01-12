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
    int mysqrt(int x){
        if (x == 0){
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.mysqrt(22);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}