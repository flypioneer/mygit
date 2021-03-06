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
     int minLength = min_element(strs.begin(),strs.end(), [](const string& s, const string& t) {return s.size() < t.size();})->size();
     int low = 0, high = minLength;
     while (low < high){
         int mid = (high - low + 1) / 2 + low;
         if (isCommonPrefix(strs, mid)){
             low = mid;

         }
         else {
             high = mid - 1;
         }
     }
     return strs[0].substr(0, low);
        
    }

    bool isCommonPrefix(const vector<string>& strs, int length){
        string str0 = strs[0].substr(0, length);
        int count = strs.size();
        for (int i = 1; i < count; ++i){
            string str = strs[i];
            for (int j = 0; j < length; ++j){
                if (str0[j] != str[j]){
                    return false;
                }
            }
        }
        return true;

    }
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<string> a = {"fly","flower","flight","flow"};
    string out = so1.longestCommonPrefix(a);
    cout<< out<< endl;
    cout<< endl;

    //待测试方法

    

    //结果打印
    
    return 0;
}