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
        int count = 0;
        for (int i = s.length() - 1; i >=0; --i){
            if (s[i] == ' ' && count != 0){
                break;
            }else if (s[i] != ' '){
                count++;
            }
        }
        return count;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int out = so1.lengthOfLastWord("hello world         ");
    cout << out<< endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}