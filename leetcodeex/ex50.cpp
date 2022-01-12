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
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while(p1 < m || p2 < n){
            if (p1 == m){
                cur = nums2[p2++];
            }else if (p2 == n){
                cur = nums1[p1++];
            }else if (nums1[p1] < nums2[p2]){
                cur = nums1[p1++];
            }else{
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for(int i = 0; i != m + n; ++i){
            nums1[i] = sorted[i];
        }
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
    for(int i = 0; i <= 5; i++){
        cout<<num1[i]<<endl;

    }
    

    //待测试方法

    

    //结果打印
    
    return 0;
}