/*
进制转换：将一个整数转化为给定的进制表示
解：该整数除以进制，然后倒序输出即可

*/

#include <iostream>
#include <string>
#include <stack>


using namespace std;


void convert1(int n, int base)
{
    if(n!=0)
    {
        int remainder=n%base;
        convert1(n/base, base);
        printf("%d",remainder);
    }
}

/*
递归实现
*/
void convert2(stack<char>& s, int n, int base)
{
    static char digit[]={'0','1','2','3','4','5','6','7','9'};
    if(n)
    {
        s.push(digit[n%base]);
        convert2(s, n/base, base);
    }
}

/*
迭代实现
*/
void convert3(stack<int>& s, int n, int base)
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
    convert2(s,10241,16);
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}