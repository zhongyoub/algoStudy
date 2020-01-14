/*
进制转换：将一个整数转化为给定的进制表示，
如：12345(10)=30071(8)
假设n=(d_m...d_2d_1d_0)(x)=d_m * x^m + ... + d_2 * x^2 +d_1 * x^1 +d_0 * x^0
 

*/

#include <iostream>
#include <string>
#include <stack>


using namespace std;

void convert(stack<char>& s, int n, int base)
{
    static char digit[]={'0','1','2','3','4','5','6','7','9'};
    if(n)
    {
        s.push(digit[n%base]);
        convert(s, n/base, base);
    }
}


