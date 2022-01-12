#include<unistd.h>
#include<iostream>
#include<string>
using namespace std;

class Officer{
public:
    Officer(int, bool, bool,string,string);
    int age;
    bool sex;
    bool edu;
    string dep;
    string name;    
};

Officer::Officer(int age, bool sex, bool edu,string n, string s)
{   age = age;
    sex = true;
    edu = true;
    dep = n;
    name = s;
}

Officer ofc[] = {
        Officer(50,true,false,"001","黄富"),
        Officer(50,false,false,"001","黄从容"),
        Officer(45,false,false,"001","黄丹"),
        Officer(40,false,true,"001","袁瑾"),
        Officer(30,false,true,"001","战晓慧"),
        Officer(25,true,true,"001","陈祺阳"),
        Officer(50,true,false,"002","谭第权"),
        Officer(50,true,false,"002","陈彪"),
        Officer(40,false,false,"002","莫春梅"),
        Officer(38,true,true,"002","樊坤"),
        Officer(30,true,true,"002","李俊景"),
        Officer(25,false,true,"002","古怡敏"),
        Officer(50,true,false,"003","何家华"),
        Officer(50,true,false,"003","姚锦华"),
        Officer(40,false,true,"003","王小清"),
        Officer(35,false,true,"003","杨柳"),
        Officer(25,false,true,"003","王泽地"),
        Officer(25,false,true,"003","黄旭"),
        Officer(50,true,false,"004","许鸿飞"),
        Officer(45,true,false,"004","陈昭"),
        Officer(40,false,true,"004","高辉"),
        Officer(35,false,true,"004","潘伟思"),
        Officer(30,false,true,"004","毕恒"),
        Officer(25,true,true,"004","陈滨滨"),
        Officer(50,true,false,"005","廖远明"),
        Officer(50,true,false,"005","罗成源"),
        Officer(40,true,true,"005","李健波"),
        Officer(35,false,true,"005","武婧婧"),
        Officer(25,false,true,"005","韩梦旗"),
        Officer(45,false,true,"005","赖淳贤"),
        Officer(50,true,false,"006","王柯养"),
        Officer(45,true,false,"006","陈泽南"),
        Officer(40,true,true,"006","陶亮"),
        Officer(35,false,true,"006","姚露露"),
        Officer(25,false,true,"006","金倩"),
        Officer(20,true,true,"006","无名氏"),
        
    };



int main()
{
    
int i,j,k,l,m,n ;
    
bool a = ofc[i].dep != ofc[j].dep && ofc[i].dep != ofc[k].dep &&ofc[i].dep!= ofc[l].dep &&
        ofc[i].dep !=ofc[m].dep && ofc[i].dep!=ofc[n].dep && ofc[j].dep!=ofc[k].dep
        && ofc[j].dep!=ofc[l].dep&& ofc[j].dep!=ofc[m].dep && ofc[j].dep!=ofc[n].dep
        && ofc[k].dep!=ofc[l].dep && ofc[k].dep!=ofc[m].dep && ofc[k].dep!=ofc[n].dep&&
        ofc[l].dep!=ofc[m].dep && ofc[l].dep!=ofc[n].dep &&ofc[m].dep!=ofc[n].dep;
                                
bool b =  ofc[i].age >= 40 && ofc[j].age <= 30 ;
bool c =  ofc[i].edu == true;

    for(i=0; i<= 35;i++)
    {
        for(j=0; j<=35; j++)
        {
            for(k=0;k<=35; k++ )
            {
                for(l=0; l<=35; l++)
                {
                    for(m=0; m<=35;m++)
                    {
                        for(n=0; n<=35; n++)
                            {
                                if (  a && b )
                                {   
                                cout<<ofc[i].name;
                                // i++;
                                cout<<ofc[j].name;
                                 // j++;
                                cout<<ofc[k].name;
                                // k++;
                                cout<<ofc[l].name;
                                // l++;
                                cout<<ofc[m].name;
                                // m++;
                                cout<<ofc[n].name;
                                // n++;
                                cout<<endl;
                                }
                                 else
                                    continue;
                                                
                            
                                }
                                    
                                }
                            
                
                            }
                    }
                }
            }
        
        
    cout<<"所有的组合全在上面了！"<<endl;
    return 0;
}