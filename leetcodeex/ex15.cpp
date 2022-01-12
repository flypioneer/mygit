#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<unordered_map>
using namespace std;


//LeetCode解答
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
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
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> a = {2,7,11,15};
    vector<int> ret = so1.twoSum(a, 9);
    for (auto i : ret)
     
    cout<< i << endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}