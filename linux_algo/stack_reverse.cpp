/*
（1）栈实现逆序
（2）对栈中元素排序(栈顶到栈底从大到小排序)
*/

#include<iostream>
#include<stack>

using namespace std;

//使用递归，将栈底元素移到栈顶位置，栈顶和栈底交换
void move_bottom_top(stack<int>& s)
{
    if(s.empty())
        return;
    int top1=s.top();
    s.pop();
    if(!s.empty())
    {
        move_bottom_top(s);
        int top2=s.top();
        s.pop();
        s.push(top1);
        s.push(top2);
        return ;
    }
}

/*
将栈中元素排序：将栈顶到栈底从大到小排序，只能额外申请一个栈，不能使用其他的数据结构
这个类似宇
分析：只能额外申请一个栈，则可以借助该栈作为中间存储，如果新的tmp栈实现从小到达排列，在放入原先栈即可
（1）cur=s.pop()，如果cur<=tmp.top()，则可以直接放入
（2）如果cur>tmp.top()，则需要先将tmp中的存入s,在将cur存入tmp
*/
void sortStack(stack<int> &s)
{
    if(s.empty())
        return;
    stack<int> tmp;
    while(!s.empty())
    {
        int cur=s.top();
        s.pop();
        while(!tmp.empty() && cur> tmp.top())
        {
            s.push(tmp.top());
            tmp.pop();
        }
        tmp.push(cur);
    }
    while(!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}

int main(int argc, char**argv)
{
    stack<int> s;
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(5);
    sortStack(s);
    while(!s.empty())
    {
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}

