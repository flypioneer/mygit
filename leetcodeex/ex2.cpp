#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
using namespace std;


//LeetCode解答
class Solution
{
public:
    vector<int> twoSum(vector<int> & nums, int target)
    {
    int i , j;
    for(i = 0; i <nums.size() - 1; i++)
    {
        for (j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {i, j};
    
    }   //解答过程
};


//测试
int main()
{
    //待测试方法
    Solution s;
    vector<int> ret;
    //测试用例
    vector<int> nums = {2,7,11,5};
    int target = 9;
    ret = s.twoSum(nums, target);
    for(auto i : ret)
    cout<< i << endl;


    

    //结果打印
    
    return 0;
}