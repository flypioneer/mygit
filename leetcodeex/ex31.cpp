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
    int strStr(string haystack, string needle){
        if(needle.length() == 0)
        return 0;
        if(haystack.length() ==0 ||haystack.length() < needle.length())
        return -1;
        if(haystack == needle)
        return 0;

        for(int i = 0; i <(haystack.length() - needle.length() + 1);++i){
            if(haystack[i] == needle[0]){
                bool judge = true;
                for (int j = 0; j < needle.length(); ++j){
                if(haystack[i + j] == needle[j])
                    continue;
                else{
                    judge = false;
                    break;
                }
                }
                if(judge)
                return i;
            }
            else
            continue;
        }
        return -1;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    string haystack = "hello";
    string needle = "ll";
    int out = so1.strStr(haystack, needle);
    cout<<out<<endl;

    //待测试方法

    

    //结果打印
    
    return 0;
}