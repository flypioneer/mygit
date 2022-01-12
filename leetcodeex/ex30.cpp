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
        if ( needle == "") //空则返回0
        return 0;
        int hlen = haystack.length();
        int nlen = needle.length();
        int i, j;
        for (i = 0; i < hlen; i++){
            for (j = 0; j < nlen; j++)
                if (haystack[i + j] != needle[j])
                break; //不符合就结束本轮匹配
            if(j == nlen)
                return i;
            }
            return -1;
        


    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    string haystack = "aaaaaaa";
    string needle = "ba";
    int out = so1.strStr(haystack, needle);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}