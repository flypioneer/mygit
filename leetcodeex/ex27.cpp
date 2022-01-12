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
    int removeDuplicates(vector<int>& nums){
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()),nums.end());
        return nums.size();
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> nums = {1,1,2,2,5,6};
    int out = so1.removeDuplicates(nums);
    cout<< out<< endl;

    //待测试方法

    

    //结果打印
    
    return 0;
}