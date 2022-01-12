#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
//#include <windows.h>
#include <list>
#include <time.h>
#include <math.h>
#include <cstring>
# define Max 100
using namespace std;
int num; //总共上课的门数
string store[4][5]; //用来存储
float flag[5][5]; //用来储存单双周的情况
char major[20];
char username[10];
int number;
struct project
{
    int pri; //确定优先级
    char name[60]; //课程名称
    char teacher[10];//任课老师名字
    int data[2]; //课程的特殊需求
    string code;  //课程代号
    int period; //课程学时
    int count; //一周上课次数
    int odd_even; //是否有单双周
    bool operator == (project p)
    {
        if (p.code == code)
            return true;
        return false;
    }
};
list <project> l;


 bool cmp(const project &p1, const project &p2)
 {
     if (p2.pri < p1.pri)
        return true;
    return false;
 }

 //储存课表
 void Store()
 {
     FILE *fpt;
     fpt = fopen("课表.txt", "w");
     
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|                               %s课表                                   |\n",major);
    fprintf(fpt,"|                                                                             |\n");
    fprintf(fpt,"|-----------------------------------------------------------------------------|\n");
    for (int s=0; s < 2; s++)
    {}
}

int main()
{
    system("color F0");
    //log();
    //menu();
    int  select;
    srand(time(NULL));
    printf("请输入所需操作的对应代号:");
    while (scanf("%d", &select) && select)
    {
        while (select < 0 || select > 5)
        {
            printf("输入有误，请重新输入:");
            scanf("%d",&select);
        }
        switch (select)
        {
            //创建课表
            case 1:
                {
                    system("cls"); //清理屏幕，准备写入
                    //CreateSchedule();
                    system("cls"); //清理屏幕，准备写入
                }
                break;
            
            //修改课程表
            case 2:
            {
                system("cls"); //清理屏幕，准备写入
                printf("|---------------------------------------------------------------------------|\n");
                printf("|                                                                           |\n");
                printf("|                              %s课表                                  |\n",major);
                printf("|                                                                           |\n");
                printf("|---------------------------------------------------------------------------|\n");
                //ReviseProject();
                //Print();
                printf("--------如您已经修改成功请选择保存－－－－－")；
            }
            break;

            //保存课程表
            case 3:
            {
                system("cls"); //清理屏幕，准备写入
                Store();
                printf("现在课表信息已经存放在“课表.txt文件中”.");
                system("pause");
                system("cls");

            }
            break;

            //输出一个课表
            case 4:
            {
                system("cls"); //清理屏幕，准备写入
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                               %s课表                                  \n",major);
                printf("                                                                             \n");
                printf("-----------------------------------------------------------------------------\n");
                printf("                                                                             \n");
                printf("                  姓名：%s",username);
                printf("               学号：%d                 \n",number);
                printf("                                                                             \n");
                printf("-----------------------------------------------------------------------------\n");
                Print();
                system("pause");

            }
            break;
            //查询课表
            case 5:
            {
                system("cls");
                //Inquiry();
            }
            break;
        }
        system("cls"); //清理屏幕，准备写入
        //menu();
        printf("请输入所需操作的对应代号：");
    }
    printf("感谢您的使用！\n");
    system("pause");
    return 0;

}