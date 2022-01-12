#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution so1;
    vector<int> a = {3,2,4};
    int b = 6;
    vector<int> c = so1.twoSum(a,b);
    for(auto i :c)
    cout<<i<<endl;
}