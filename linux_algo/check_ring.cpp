/*
问题：判断单向链表中是否存在环，时间复杂度满足O(n),如果有环，找出环的入口位置,并且求出环大小
分析，该链表时一个单项链表，即环的

如果链表中存在环，则遍历的时候同一个节点遍历了两次
(1)穷举发：从链表的头节点开始遍历，每次遍历遍历一个新的节点，则需要再从头开始遍历到新节点前一个节点
(2)对每个遍历节点的的ID进行哈希运算，并存储，到遍历一个新的节点时，则比较新节点的哈希值和原先哈希集合中的值作比较
(3)使用快，慢指针。刚开始两者都位于head,快指针遍历一遍后，如果和慢指针指向相同节点，则存在环
(4)使用集合存储遍历的节点(集合没有元素重复)，如果存储到某个节点，集合大小不变，则有环

解：
（1）使用快慢指针fastPointer,slowPointer，由于每次都至少走一步，则规定slowPointer每次走一步，fastPointer每次走两步。
如果有环，则两者未来某时候一定相遇。
假设slowPointer在环入口，距离链表头为L,fastPointer距离slowPointer为S,则S+2t-t=nR => S+t=nR，总存在S,t,R满足上述条件。

（2）假设环长为R,环入口距离链表头L。如果两指针在某节点相遇，并且此节点距离距离环入口为S,则慢指针走了S+L，快指针走了L+S+nR。
此时，fastPointer时slowPointer速度的两倍，则L+S+nR=2(L+S) => L+S=nR
当n=1,则在相遇节点时，fastPointer比slowPointer多走了一圈，L=R-S,R-S表示从相遇节点到环的距离，如果采用两个指针每次都走一步，
一个从链表头开始，一个从相遇节点开始，则在环入口出相遇。
当n>1,L=nR-S=(n-1)R+R-S,则从相遇节点出发块的指针走几个环后一定和从链表头走的指着相遇。

（3）环的大小可以在相遇节点在走一圈即可求出

*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct ListNode{
    int value;
    struct ListNode *next;
}ListNode;

//添加
ListNode* addNode(ListNode* head, int value)
{
    ListNode *node=new ListNode();
    node->next=NULL;
    node->value=value;
    ListNode* p=head;
    if(head==NULL)
        head=node;
    else
    {
        while(p!=NULL)
            p=p->next;
        p->next=node;
    }
    return head;
}

//遍历list
void travelList(ListNode* node)
{
    if(node==NULL)
        return;
    while(node!=NULL)
    {
        cout<<node->value<<'\t';
        node=node->next;
    }
}

// delete ListNode
ListNode* removeNode(ListNode* head, int value)
{
    ListNode* node=head;
    if(head=NULL)
    {
        cout<<"List is NULL"<<endl;
        return NULL;
    }
    else if(node->value==value)
    {
        head=head->next;
        delete node;
        node=NULL;
    }
    else
    {
        while(node->next && node->next->value!=value)
        {
            node=node->next;
        }
        if(node->next!=NULL && node->next->value==value)
        {
            node->next=node->next->next;
            delete node->next;
            node->next=NULL;
        }
    }
    return head;
}

/*
检查list是否有环
*/
bool chceckCycle(ListNode* head)
{
    ListNode* slowPointer=head;
    ListNode* fastPointer=head;
    if(head==NULL)
        return false;
    while(fastPointer && fastPointer->next)
    {
        slowPointer=slowPointer->next;
        fastPointer=fastPointer->next;
        if(slowPointer=fastPointer)
            return true;
    }
    return false;
}

/*
查找环入口，首先找到相遇点
*/

ListNode* checkEntrance(ListNode* head)
{
    ListNode* fastPointer;
    ListNode* slowPointer;
    while(fastPointer && fastPointer->next)
    {
        slowPointer=slowPointer->next;
        fastPointer=fastPointer->next->next;
        if(fastPointer==slowPointer)
            break;
    }
    if(fastPointer==NULL || fastPointer->next==NULL)
        return NULL;
    ListNode* arcossNode=slowPointer;
    slowPointer=head;
    while(arcossNode!=slowPointer)
    {
        arcossNode=arcossNode->next;
        slowPointer=slowPointer->next;
    }
    return slowPointer;
    
}


int main()
{
    return 0;
}