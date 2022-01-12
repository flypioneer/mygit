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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int i , j ;
        for (i = 0; i <nums.size() - 1; i++)
        {
            for(j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }

        }
        return {i, j};
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> a = {2,7,11,15};
    vector<int> out = so1.twoSum(a, 9);
    for(auto i : out)
    cout<< i  << endl;

    //待测试方法

    

    //结果打印
    
    return 0;
}