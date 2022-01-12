#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
#include<cassert>
using namespace std;


//LeetCode解答
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits) {
        assert(!digits.empty());
        int carry = 1;
        int N = digits.size();
        int i = N - 1;
        while (i >= 0){
            int sum = digits[i] + carry;
            int digit = sum % 10;
            carry = sum / 10;
            digits[i] = digit;
            i--;
        }

        if (carry > 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;

    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    vector<int> num = {1,2,4,6 };
    vector<int> out = so1.plusOne(num);
    for (int i = 0; i < num.size(); i++){
        cout<<num[i]<<endl;
        cout<<endl;
    }

    

    //待测试方法

    

    //结果打印
    
    return 0;
}