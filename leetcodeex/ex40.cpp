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
    string addBinary(string a, string b){
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
    }

    if (carry){
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }

};


//测试
int main()
{
    //测试用例
    Solution so1;
    string out = so1.addBinary( "1001", "1111");
    cout<<out<< endl;

    

    //待测试方法

    

    //结果打印
    
    return 0;
}