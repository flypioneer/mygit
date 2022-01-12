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
        int max = INT_MIN;
        int numsSize = int(nums.size());
        for (int i = 0; i < numsSize; i++)
        {
            int sum = 0;
            for (int j = i; j < numsSize; j++)
            {
                sum += nums[j];
                if (sum > max)
                {
                    max = sum;
                }
            }
        }
        return max;

    }
};

int main()
{
    Solution so1;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int b = so1.maxSubArray(a);
    cout<<b<<endl;
}