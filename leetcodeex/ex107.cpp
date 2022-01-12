#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<limits.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
       //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
       int result = INT_MIN;
       int numsSize = int(nums.size());
       int sum = 0;
       for (int i = 0; i < numsSize; i++)
       {
           sum += nums[i];
           result = max(result, sum);
           //如果sum < 0,重新开始找子序串
           if (sum < 0)
           {
               sum = 0;
           }
       }
        return result;
    }

};

int main()
{
    Solution so1;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int b = so1.maxSubArray(a);
    cout<<b<<endl;


}