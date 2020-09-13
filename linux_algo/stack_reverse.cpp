/*
（1）栈实现逆序:将栈底元素移到栈顶
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
//栈逆转
void reverse(stack<int>& s)
{
    if(s.empty())
        return;
    move_bottom_top(s);    //实现栈顶和栈底交换
    int top1=s.top();
    s.pop();
    reverse(s);
    s.push(top1);
}


/*
将栈中元素排序：将栈顶到栈底从大到小排序，只能额外申请一个栈，不能使用其他的数据结构
这类似于汉诺塔问题
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

/*
不借助其他的栈，实现栈的排序
解：这里是从大到小排序，则可以取最大的放在栈顶，在递归逆转，则实现了从大到小的排序
    如果是从小到大排序，则取出最小的放在栈顶，然后递归逆转，则实现了排序
*/
void move_max_top(stack<int>& s)
{
    if(s.empty())
        return;
    int top1=s.top();
    s.pop();
    if(!s.empty())
    {
        move_max_top(s);
        int top2=s.top();
        if(top1<top2)
        {
            s.pop();
            s.push(top1);
            s.push(top2);
        }
    }
}

void sort(stack<int>& s)
{
    if(s.empty())
        return;
    move_max_top(s);
    int top=s.pop();
    sort(s);
    s.push(top);
}



int main(int argc, char**argv)
{
    stack<int> s;
    s.push(4);
    s.push(2);
    s.push(3);
    s.push(5);
    sort(s);
    while(!s.empty())
    {
        printf("%d\n",s.top());
        s.pop();
    }
    return 0;
}

