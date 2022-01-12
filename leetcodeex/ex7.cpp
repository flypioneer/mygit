#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
using namespace std;


//LeetCode解答
class Solution
{
   //解答过程
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i)
        {
            int x = nums[i], y = nums[i + 1];
            if (x > y)
            {
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end()))
                {
                    return true;
                }
                nums[i] = x; //复原
                nums[i + 1] = y;
                return is_sorted(nums.begin(), nums.end());
            }
        }
    return true;
    }
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> A = {3,1,2,4,0};
    bool out = so1.checkPossibility(A);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}