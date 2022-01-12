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
    int fib(int n){
        int arr[2] = {0, 1};
        for (int i = 2; i <= n; ++i){
            arr[i & 1] = (arr[0] + arr[1]) % (int)(1e9 + 7);
        }
        return arr[n & 1];
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int arrout = so1.fib(20);
    for(int i = 0; i < 20; i++){
        cout<<arrout<<endl;
        cout<<endl;
    }
    

    //待测试方法

    

    //结果打印
    
    return 0;
}