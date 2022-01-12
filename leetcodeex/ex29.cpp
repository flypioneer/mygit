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
    int removeElement(vector<int>& nums, int val){
        //双指针从0开始
        //如果与val相等就快指针+1，到不相等时，把快的指针值赋给慢指针
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()){
            if (nums[fast] != val){
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> nums = {1,1,2,3,5,7,8};
    int out = so1.removeElement(nums, 5);
    cout<< out << endl;
    for (int i = 0; i < out; i++)
    cout<< nums[i]<< endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}