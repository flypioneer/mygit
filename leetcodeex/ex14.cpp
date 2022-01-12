#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<map>
using namespace std;


//LeetCode解答
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int,int> a; //建立hash表存放数组元素
        vector<int> b(2,-1); //存放结果　
        for (int i = 0; i < nums.size(); i++)
            a.insert(map<int,int>::value_type(nums[i], i));
        for (int i = 0; i < nums.size(); i++)
        {
            if(a.count(target - nums[i] ) > 0 && (a[target - nums[i] != i]))
            //判断是否找到目标元素且目标元素不能是本身
            {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }   
        return b;

    };
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> vec = {2,7,11,15};
    vector<int> out = so1.twoSum(vec, 9);
    for (auto i : out)
    cout<< i << endl;

    

    //待测试方法

    

    //结果打印
    
    return 0;
}