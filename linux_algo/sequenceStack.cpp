/*
顺序栈：栈的顺序存储结构是利用一组地址连续的存储单元依次存放自栈底
的元素，同时附设指针top只是栈顶元素在栈中的位置，以top=-1表示空栈
*/

#include <iostream>
using namespace std;

typedef struct seqStack{
    int data[20];
    int top;
}seqStack;


//顺序栈初始化
void  initStack(seqStack& ssack)
{
    ssack.top=-1;
}

//判断顺序栈是否为空
bool isEmpty(seqStack& st)
{
    if(st.top==-1)
        return true;
    return false;
}

//顺序栈进栈
int push(seqStack & st, int value)
{
    if(st.top==20) //存储已满
        return 0;
    else
    {
        st.data[++st.top]=value;
        return 1;
    }
}

//顺序栈出栈
int pop(seqStack& st, int& value)
{
    if(isEmpty(st))
        return 0;
    else
    {
        value=st.data[st.top--];
        return 1;
    }
}

int main(int argc, char **argv)
{
    seqStack s;
    int x;
    initStack(s);
    for(int i=0;i<10;i++)
    {
        cin>>x;
        push(s,x);
    }
    int t;
    for(int i=0;i<10;i++)
    {
        pop(s,t);
        cout<<t<<endl;
    }
    return 0;
}