#include<iostream>
using namespace std;

//线索二叉树的存储结点
typedef struct BTnode
{
    char data;  //结点数据域
    struct BTnode *lchild, *rchild;  //左右孩子指针
    int ltag,rtag;
}BTnode, *BTtree;

//全局变量pre
BTtree pre;

//创建二叉树(补空法)
void CreateBiTree(BTtree &T)
{
    //按先序次序输入二叉树中结点的值(一个字符)，创建二叉链表表示的二叉树T
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;  //递归结束，建空树
    else
    {
        T=new BTnode;
        T->data=ch;  //生成根结点
        CreateBiTree(T->lchild);//递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}

void InThread(BTtree &p) //中序线索化
{
    //pre是全局变量，指向当前结点p的前驱
    if(p)
    {
        InThread(p->lchild);  //左子树递归线索化
        if(!p->lchild)   //p的左孩子为空
        {
            p->ltag=1;  //给p加上左线索
            p->lchild=pre; //p的左孩子指针指向pre(前驱)
        }
        else
            p->ltag=0;
        if(pre)
        {
            if(!pre->rchild)  //pre的右孩子为空
            {
                pre->rtag=1; //给pre加上右线索
                pre->rchild=p; //pre的右孩子指针指向p(后继)
            }
            else
                pre->rtag=0;
        }
        pre=p; //保持pre指向p的前驱
        InThread(p->rchild); //右子树递归线索化
    }
}

void CreateInThread(BTtree &T) //创建中序线索二叉树
{
    pre=NULL; //初始化为空
    if(T)
    {
        InThread(T); //中序线索化
        pre->rchild=NULL; //处理遍历的最后一个结点，其后继为空
        pre->rtag=1;
    }
}

void Inorder(BTtree T) //中序遍历二叉树
{
    if(T)
    {
        Inorder(T->lchild);
        cout<<T->data<<" ";
        Inorder(T->rchild);
    }
}

void InorderThread(BTtree T) //遍历中序线索二叉树
{
    BTtree p;
    p=T;
    while(p)
    {
        while(p->ltag==0) p=p->lchild; //找最左结点
        cout<<p->data<<" "; //输出结点信息
        while(p->rtag==1&&p->rchild) //右孩子为线索化，指向后继
        {
            p=p->rchild;  //访问后继结点
            cout<<p->data<<" "; //输出结点信息

        }
        p=p->rchild;  //转向p的右子树
    }
}

int main()
{
    BTtree  tree;
    cout<<"请输入先序创建二叉树的序列(补空法)：\n";//例如ABD##E##CF#G###
    CreateBiTree(tree);  //创建二叉树
    cout<<"二叉树的中序遍历结果: \n";
    Inorder(tree);   //中序遍历二叉树
    cout<<endl;
    CreateInThread(tree);  //创建中序线索二叉树
    cout<<"中序线索二叉树的遍历结果：\n";
    InorderThread(tree); //遍历中序线索二叉树
    return 0;
}
