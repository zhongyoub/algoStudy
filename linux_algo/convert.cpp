/*
进制转换：将一个整数转化为给定的进制表示，
*/

#include <iostream>
#include <string>
#include <stack>


using namespace std;

/*
递归实现
*/
void convert(stack<char>& s, int n, int base)
{
    static char digit[]={'0','1','2','3','4','5','6','7','9'};
    if(n)
    {
        s.push(digit[n%base]);
        convert(s, n/base, base);
    }
}

/*
迭代实现
*/
void convert1(stack<int>& s, int n, int base)
{
    while(n)
    {
        s.push(n%base);
        n/=base;
    }
}

int main()
{
    stack<char> s;
    convert(s,10241,16);
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}