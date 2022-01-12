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
        int size = nums.size();
        if (size == 0){
            return 0;
        }

        // 特判
        if (nums[size - 1] < target){
            return size;
        }
        int left = 0;
        int right = size - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            //严格小于target的元素一定不是解
            if (nums[mid] < target){
                left = mid + 1;//下一轮搜索区间是[mid + 1, right]

            }
            else {
                right = mid;
            }
        }
       return left;
    }
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> nums = {1,1,2,5,7,8,9};
    int target = 6;
    int out = so1.searchInsert(nums, target);
    cout<<out<<endl;


    //待测试方法

    

    //结果打印
    
    return 0;
}