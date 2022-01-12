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
    string countAndSay(int n){
        string a;
        if (n > 1) { a = countAndSay(n - 1);}
        else { return "1";}
        int i = 0, k = 0;
        char ss = a[0];
        string target;
        while (i < a.size()){
            while (ss == a[i++]){

            }
            i -= 1;
            target.push_back('0' + i - k);
            target.push_back(ss);
            ss = a[i];
            k = i;
        }     
        return target;
    }
  
};


//测试
int main()
{
    //测试用例
    Solution s1;
    int n = 20;
    string out = s1.countAndSay(n);
    cout<<out<<endl;
    

    //待测试方法

    

    //结果打印
    
    return 0;
}