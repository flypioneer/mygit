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
    int mySqrt(int x){
        int l = 0, r = x, ans = -1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
            
        }
        return ans;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.mySqrt(9);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}