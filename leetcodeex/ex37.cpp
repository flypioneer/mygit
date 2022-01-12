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
    int lengthOfLastWord(string s){
        int ans = 0;
        int rear = 0;
        for(auto x: s){
            if(x == ' '){
                rear = ans? ans : rear;
                ans = 0;
            }
            else ans++;

        }
        return ans? ans : rear;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.lengthOfLastWord("hello world ! ");
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}