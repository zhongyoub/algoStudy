/*
栈实现逆序及排序
这个问题类似于将一堆的铁饼叠起来，最底下为最大的，最上面为最小的
*/

#include<iostream>
#include<stack>

using namespace std;

//将栈底元素移到栈顶位置，栈顶和栈第交换
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

