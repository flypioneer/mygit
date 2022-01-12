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
        int len = nums.size();
        for (int i = 0; i < len; i++){
            if (nums[i] == val){
                for (int j = i; j < len -1; j++){
                    nums[j] = nums[j + 1];
                }
                i--;//i以后的值都往前移了一位，所以i要减一。
                len--;//数组长度减一
            }
        }
        return len;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> num1 = {1,2,3,4,5,6,7};
    int out = so1.removeElement(num1, 5);
    cout<< out<< endl;

    for(int i = 0; i < out; i++){
        cout<<num1[i]<<endl;
        
    }
    

    //待测试方法

    

    //结果打印
    
    return 0;
}