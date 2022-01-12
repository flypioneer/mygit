#include<iostream>
#include<algorithm>
using namespace std;

typedef struct 
{
    int x;
    int y;
}Position; //位置

int m[30][30]; //地图
Position here;
Position nex; //当前位置，　下一个位置
Position DIR[4]={0,1,1,0,0,-1,-1,0}; //右下左上方向数组

void Init(int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n;j++)  //方格阵列初始化为0
            m[i][j]=0;
    }
    for(int j=0; j<=n+1; j++) //方格阵列上下围墙
        m[0][j]=m[n+1][j]=-1;
    for(int i=0; i<=n+1; i++)  //方格阵列左右围墙
        m[i][0]=m[i][n+1]=-1;
}

void Print(int start, int endi)  //start,endi为开始和结束下标
{
    for(int i=start; i<=endi;i++)
    {
        cout<<m[i][start];
        for(int j=start+1; j<=endi;j++)
            cout<<"\t"<<m[i][j];
        cout<<endl;
    }
    cout<<endl;
}

//n: 原问题规模
//m: 地图矩阵
void Solve(int n)
{
    here.x=1; //左上角有蛋糕的位置
    here.y=1;
    int dirIndex=0;
    int num=1;
    m[1][1]=1;
    while(num<n*n)
    {
        nex.x=here.x + DIR[dirIndex].x;
        nex.y=here.y + DIR[dirIndex].y;
        if(m[nex.x][nex.y]==0) //判断下一个位置是否有蛋糕
        {
            m[nex.x][nex.y]=++num;//吃了蛋糕，拉出的数字加1
            here=nex;  //以nex为当前位置，继续走
        }
        else
            dirIndex=(dirIndex+1)%4; //换下一个方向，按右下左上顺序继续吃蛋糕
    }
}

int main()
{
    int n=0;
    cout<<"请输入大于1小于等于20的整数n:"<<endl;
    cin>>n;
    while(n<1||n>20)
    {
        cout<<"请输入大于1小于等于20的整数n:"<<endl;
        cin>>n;
    }
    Init(n);
    Print(0,n+1);
    Solve(n);
    Print(1,n);
    return 0;
}
