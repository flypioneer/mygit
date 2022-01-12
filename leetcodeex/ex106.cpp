#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0, maxAns = nums[0];
        for(const auto &x: nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

int main()
{
    Solution so;
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    int b = so.maxSubArray(a);
    cout<<b<<endl;
}