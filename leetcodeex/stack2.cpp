// stack::swap
#include <iostream>   //std::cout
#include <stack>      //std::stack

int main()
{
    std::stack<int> foo, bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push(111); bar.push(222);

    foo.swap(bar);

    std::cout << "size of foo: "<< foo.size() << '\n';
    std::cout << "size of bar: "<< bar.size() << '\n';

    while (!foo.empty())
    {
        std::cout<<foo.top()<<'\n';
        foo.pop();
    }

    while (!bar.empty())
    {
        std::cout<<bar.top()<<'\n';
        bar.pop();
    }
        
    return 0;

}