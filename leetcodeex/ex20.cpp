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
    string longestCommonPrefix(vector<string>& strs){
        if (!strs.size()){
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        for (int i = 0; i < length; ++i){
            char c = strs[0][i];
            for (int j = 1; j < count; ++j){
                if (i == strs[j].size() || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];

    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<string> a = {"fly","flow","flower","flight"};
    string out = so1.longestCommonPrefix(a);
    cout<< out<< endl;
    cout << endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}