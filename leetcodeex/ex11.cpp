#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;


//LeetCode解答
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<char> stk;
        for (char ch:s){
            if (pairs.count(ch)){
                if (stk.empty() || stk.top() != pairs[ch]){
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    bool out ;
    string s = "{}";
    out = so1.isValid(s);
    cout<<out<<endl;
    cout<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}