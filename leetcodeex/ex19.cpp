#include<string>
#include<iostream>
using namespace std;

int main()
{
    string s("12345asdf");
    string a = s.substr(0,5);
    cout<< a << endl;
}