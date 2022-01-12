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
    string longestCommonPrefix(vector<string>& strs)
    {
        if (!strs.size())
        {
            return "";
        }
        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i)
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size())
            {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1,const string& str2)
    {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while( index < length && str1[index] == str2[index])
        {
           ++index; 
        }
        return str1.substr(0, index);
    }

  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<string> strs = {"flower","flow","flight"};
    string out = so1.longestCommonPrefix(strs);
    cout<< out<< endl;
    cout<< endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}