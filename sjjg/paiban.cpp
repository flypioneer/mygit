#include<unistd.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Officer{
public:
    Officer(int, int,string);
    int nightnum;
    int daynum;
    int num;
    string name;

};

Officer::Officer(int nightnum, int daynum,  string s)
{
    name = s;
    nightnum = nightnum;
    daynum = daynum;
    num = nightnum * 3 + daynum * 2;

}

struct compare_by_num
{
    bool operator() (const  Officer & lhs, const Officer  & rhs)
    {
        return lhs.num < rhs.num;
    }
};

Officer ofc[] = {
        Officer(2,3,"袁瑾"),
        Officer(2,3,"罗成源"),
        Officer(2,3,"莫春梅"),
        Officer(3,2,"董龙"),
        Officer(3,2,"樊坤"),
        Officer(2,3,"黄国春"),
        Officer(2,3,"战晓慧"),
        Officer(2,3,"严潇"),
        Officer(2,3,"胡欣杭"),
        Officer(3,2,"李冰"),
        Officer(1,4,"鲁劼"),
        Officer(1,3,"肖丽雅"),
        Officer(2,2,"许鸿飞"),
        Officer(1,1,"王泽地"),
        Officer(3,1,"何家华"),
        Officer(3,1,"黄丹"),
        Officer(2,2,"姚露露"),
        Officer(2,2,"潘伟思"),
        Officer(2,2,"陈国华"),
        Officer(2,2,"袁玉芳"),
        Officer(3,1,"王世忠"),
        Officer(2,3,"蒋普"),
        Officer(3,1,"王晓强"),
        Officer(3,2,"付裕宏"),
        Officer(3,2,"罗振文"),
        Officer(2,3,"杨克勤"),
        Officer(1,3,"蓝小庆"),
        Officer(3,1,"敖锦光"),
        Officer(3,1,"洪丽玲"),
        Officer(2,1,"李旭峰"),
};


int main()
{
    int i, j, k, l, m, n;
    //Officer ofc[];
    std::sort(ofc, ofc+30, compare_by_num()); 
    for (i = 0; i < 7; i++)
    {
        cout<<"上夜班的人是"<<ofc[i].name<<endl;
        ofc[i].nightnum += 1;

    } 
    for (i = 8; i < 12; i ++)
    {
        cout<<"上白班的人是"<<ofc[i].name<<endl;
        ofc[i].daynum += 1 ;
    } 


}