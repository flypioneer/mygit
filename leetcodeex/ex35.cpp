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
    int maxSubArray(vector<int>& nums){
        int pre = 0, maxAns = nums[0];
        for (const auto &x : nums){
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int out = so1.maxSubArray(nums);
    cout<<out<<endl;

    

    //待测试方法

    

    //结果打印
    
    return 0;
}