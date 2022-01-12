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
    int mySqrt(int x){
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true){
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 -xi) < 1e-7){
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.mySqrt(25);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}