/*
判断一个整数是否是回文数，其二进制是否是回文数

回文数是指正序（从左往右）和倒序（从右往左）读都是一样的整数
十进制整数：如121
二进制：11011
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 

/*
判断一十进制整数是否是回文数
解题
1. 可以取出整数的每位数字，使用数组存放
2. 将整数转化为字符串
*/

bool isPalin1(int num)
{
    if(num<0)
        return false;
    int a[32]={0};
    int i=-1;
    while(num>0)
    {
        ++i;
        a[i]=num%10;
        num=num/10;
    }
    int len=i+1;
    for(int start=0, end=i; start<=len/2 && end>=len/2; ++start, --end)
    {
        if(a[start]!=a[end])
            return false;
    }
    return true;
}

// 将整数转换为字符串,使用snprintf()
int isPalin2(int num)
{
    if(num<0)
        return false;
    char a[32];
    memset(a,0,sizeof(a));
    snprintf(a, 32, "%d",num);
    int len=strlen(a);
    for(int start=0, end=len-1; start<=len/2 && end>=len/2; ++start, --end)
    {
        if(a[start]!=a[end])
            return false;
    }
    return true;
}

/*
判断一个整数的二进制是否是回文数
解
1. 将整数转化为二进制，使用数组存放
2. 计算二进制的长度，使用&操作
*/
bool isPalin3(int x)
{
    int num=1mlen=1,t=x>>1;
    //计算二进制长度
    while(t)
    {
        num<<=1;
        t>>=1;
        len++;
    }
    len/=2;
    while(len--)
    {
        if((num&x==0) && (x&1)!=0)
            return 0;
        x&=(~num);
			x>>=1;
			num>>=2;
		}
		return 1;
    }

}

bool isPalindrome(int x) {//十进制
        if(x<0)return 0;
        int num=1,len=1;
        while(x/num>=10){
            num*=10;
            len++;
        }
        len/=2;
        while(len--){
            if(x%10!=x/num){
                return 0;
            }
            x=x-(x/num)*num;
            num/=100;
            x/=10;
        }
        return 1;
    }


int main()
{
    int num;
    cout<<"please input a integer number"<<endl;
    cin>>num;
    if(isPalin2(num))
        cout<<num<<" is a palindrome"<<endl;
    else 
        cout<<num<<" is not a palindrome"<<endl;
    return 0;
}
