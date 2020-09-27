/*
汉诺塔问题：有三根柱子：A,B,C，其中柱子A上面有从小到大叠好的n个圆盘，
现在要求将A柱子上的圆盘移动到C柱子上去，每次移动一个盘子，且大盘不能位于小盘的上面
求移动的步骤和移动的次数
*/


/*
这种移动盘类似栈的先进后出，可以使用递归的解法
（1）：将n-1个圆盘移动到B；
（2）：将第n个移到到C
（3）：在将n-1个移到C 
假设圆盘的编号从上到下依次为1，2，3...n 
*/

#include<iostream>
using namespace std;

//将编号为NUM的从N移到M
void print(int num, char N, char M)
{
    cout<<"Move "<<num<<" from:"<<N<<" to "<<M<<endl;
}
// 表示将n个圆盘经过b从a移到c
void move(int n, char a, char b, char c)
{
    if(n==1)
    {
        print(n,a,c);
        return;
    }
    else{
        move(n-1, a,c,b);
        print(n, a,c);
        move(n-1,b,a,c);
    }

}
int main()
{
    int count;
    cin>>count;
    move(count,'A','B','C');
    return 0;
}