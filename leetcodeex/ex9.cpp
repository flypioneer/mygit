#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<unordered_map>
using namespace std;


//LeetCode解答
class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> m = {{"I",1},{"IV",3},{"IX",8},{"V",5},{"X",10},{"XL",30},{"XC",80},{"L",50},{"C", 100},{"CD",300},{"CM",800},{"D",500},{"M",1000}};
        int r = m[s.substr(0, 1)];
        for(int i = 1; i < s.size(); ++i)
        {
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;

    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    int a = so1.romanToInt("IV");
    cout<<a<<endl;


    //待测试方法

    

    //结果打印
    
    return 0;
}