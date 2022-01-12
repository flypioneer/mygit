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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for (int i = 0; i != n; ++i){
            nums1[m + i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};
    so1.merge(num1,3,num2,3);
    for(int i = 0; i<= 5; i ++){
        cout<<num1[i]<<endl;

    }
    

    //待测试方法

    

    //结果打印
    
    return 0;
}