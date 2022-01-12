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
    int searchInsert(vector<int>& nums, int target){
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right){
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> nums = {1,2,3,5,7,8};
    int target = 6;
    int out = so1.searchInsert(nums, target);
    cout<<out<<endl;

    

    //待测试方法

    

    //结果打印
    
    return 0;
}