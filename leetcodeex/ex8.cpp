#include<iostream>    // std::cout
#include<vector>      // std::array
#include<queue>
#include<unistd.h>
#include<algorithm>   //　std::is_sorted
#include<list>        //  std::list
using namespace std;

//以普通函数的方式自定义排序规则
bool mycomp1(int i, int j)
    {
        return (i > j);
    }

//以函数对象的方式自定义排序规则
class mycomp2
{
public:
    bool operator()(int i , int j)
    {
        return (i > j);
    }
};

//LeetCode解答
class Solution
{
   //解答过程

};


//测试
int main()
{
    vector<int> myvector{3,1,2,4};
    list<int> mylist{1,2,3,4};
    //调用第2种语法格式的is_sorted()函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(), mycomp2()))
    {
        cout <<"开始对 myvector 容器排序"<< endl;
        //对 myvector容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出myvector容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it)
        {
            cout<< *it << " ";
        }
        cout<< endl;
    }

    //调用第一种语法格式的is_sorted()函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end()))
    {
        cout<<"开始对mylist排序"<< endl;
    }
    return 0;
    //测试用例
    

    //待测试方法

    

    //结果打印
    
    return 0;
}