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
        vector<int> obj; //创建一个向量存储容器　int

    int removeDuplicates(vector<int>& nums){
        if(nums.size() == 0)
        return 0;
        int i = 0;
        vector<int> obj; //创建一个向量存储容器　int

        for(int j = 0; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                obj.push_back(nums[i]);
                
            }
        }
        
        return i + 1;
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
    for (int i = 0; i < out; i++){
        cout<<nums[i]<<endl;
    }
    

    //待测试方法

    

    //结果打印
    
    return 0;
}