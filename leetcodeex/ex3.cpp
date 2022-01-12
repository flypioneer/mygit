#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<unordered_map>
using namespace std;


//LeetCode解答
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;

        }
        return {};
    }
    
    
       //解答过程
};


//测试
int main()
{
    //测试用例
    
    

    //待测试方法
    Solution s;
    vector<int> out;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    out = s.twoSum(nums, target);
    for (auto i : out)
    cout<< i << endl;

    

    //结果打印
    
    return 0;
}