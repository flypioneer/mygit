#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
using namespace std;


//LeetCode解答
class Solution
{
   //解答过程
public:
    int maxProfit(vector<int>& prices)
    {
        int n = (int)prices.size(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};


//测试
int main()
{ 
    Solution so1;
    
    int out;
    vector<int> A = {7,1,5,3,6,4};
   out = so1.maxProfit( A );
  cout <<out<< endl;
    //测试用例
    

    //待测试方法

    

    //结果打印
    
    return 0;
}