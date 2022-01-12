#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    int numberOfMatches(int n)
    {
        int k = 0;
        while(n > 1){
            if(n%2 ==0){
            n = n/2;
            k = k + n;
            }
            else{
                n = (n+1)/2;
                k = k + (n-1);
            }
        }
        return k;
    }
};

int main()
{
    Solution so1;
    int a  = 14;
    int b = so1.numberOfMatches(a);
    cout<<b<<endl;
    
}