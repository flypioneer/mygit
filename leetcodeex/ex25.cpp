#include<iostream>
#include<vector>
#include<queue>
#include<unistd.h>
#include<algorithm>
using namespace std;


//LeetCode解答
struct ListNode {
    int val;  //定义val变量值，存储节点值
    struct ListNode *next;
    //定义next指针，指向下一个节点，维持节点连接
    ListNode(int x) : val(x), next(NULL) {}
        
};

ListNode* creatList()
{
    ListNode* prehead = new ListNode(-1);
    ListNode* dummy = prehead;
    cout<< "输入链表，通过-1终止输入；"<< endl;
    while (true)
    {
        int value;
        cin >> value;
        cout<< "->";
        if (value == -1)
        break;
        ListNode* donecreatList = new ListNode(value);
        dummy->next = donecreatList;
        dummy = dummy->next;

    }
    cout << endl;
    return prehead->next;
}

void printList(ListNode* head)
{
    if (!head)
    {
        return;
    }
    ListNode* forprintList;
    forprintList = head;
    while (forprintList)
    {
        cout<<" "<< forprintList->val;
        forprintList = forprintList->next;
    }
    cout<< endl;
}

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        else if (l2 == nullptr)
        {
            return l1;
        }
        else if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

    }
  
};


//测试
int main()
{
    //测试用例
    Solution so1;
    ListNode* l1 = creatList();
    ListNode* l2 = creatList();
    ListNode* RES = NULL;
    cout<<"给定链表："<< endl;
    printList(l1);
    printList(l2);
    RES = so1.mergeTwoLists(l1, l2);
    cout<<"返回："<<endl;
    printList(RES);
    
    
    
    //待测试方法

    

    //结果打印
    
    return 0;
}