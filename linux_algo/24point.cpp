/*
24点游戏：输入4个0-9的整数，数字允许重复，但每个数字仅允许使用一次，通过加减乘除，得到值为m
输出：1表示可解，0表示不可解
*/

//使用暴力法
#include<iostream>
#include<vector>
using namespace std;


/*
使用暴力法，遍历所有的可能，使用flag记录算法个数
使用check()函数，针对输入的数据a,b,c,d进行检查，有五种情况：
1.都不相同，则不作调整;
2.有且仅有两个相同，那么把相应的相同的元素放在c和d 的位置；
3.有两组数字分别相同(比如a=c,b=d,但是a,b不等)，那么把相同的放在一起；
4.有三个相同，那么把他们发在b,c,d的位置；
5.全部相同，那么不做调整
通过检查，可以减少运算的次数

*/

int flag=0;
// 检查所有的排列组合
int Calculate(float x, float y, float z, float w, int result)
{
    if (x+y+z+w==result) {cout<<x<<"+"<<y<<"+"<<z<<"+"<<w<<"="<<result<<endl;flag++;} 
    else if (x+y+z-w==result) {cout<<x<<"+"<<y<<"+"<<z<<"-"<<w<<"="<<result<<endl;flag++;}  
    else if ((x+y)*(z+w)==result) {cout<<"("<<x<<"+"<<y<<")*("<<z<<"+"<<w<<")="<<result<<endl;flag++;}   
    else if ((x-y)*(z+w)==result) {cout<<"("<<x<<"-"<<y<<")*("<<z<<"+"<<w<<")="<<result<<endl;flag++;}   
    else if ((x-y)*(z-w)==result) {cout<<"("<<x<<"-"<<y<<")*("<<z<<"-"<<w<<")="<<result<<endl;flag++;}   
    else if ((x+y+z)*w==result) {cout<<"("<<x<<"+"<<y<<"+"<<z<<")*"<<w<<"=result"<<result<<endl;flag++;}   
    else if ((x-y-z)*w==result) {cout<<"("<<x<<"-"<<y<<"-"<<z<<")*"<<w<<"="<<result<<endl;flag++;}   
    else if ((x+y-z)*w==result) {cout<<"("<<x<<"+"<<y<<"-"<<z<<")*"<<w<<"="<<result<<endl;flag++;}  
	else if ((x-y+z)*w==result) {cout<<"("<<x<<"-"<<y<<"+"<<z<<")*"<<w<<"="<<result<<endl;flag++;} 
    else if ((x*y*z)/w==result) {cout<<"("<<x<<"*"<<y<<"*"<<z<<")/"<<w<<"="<<result<<endl;flag++;}   
    else if ((x*y)*(z+w)==result) {cout<<"("<<x<<"*"<<y<<")*("<<z<<"+"<<w<<")="<<result<<endl;flag++;}   
    else if ((x*y)*(z-w)==result) {cout<<"("<<x<<"*"<<y<<")*("<<z<<"-"<<w<<")="<<result<<endl;flag++;}  
    else if ((x*y)*z-w==result) {cout<<"("<<x<<"*"<<y<<")*("<<z<<")-"<<w<<"="<<result<<endl;flag++;}   
    else if ((x*y)*z+w==result) {cout<<"("<<x<<"*"<<y<<")*("<<z<<")+"<<w<<"="<<result<<endl;flag++;}  
    else if (x*y*z*w==result) {cout<<x<<"*"<<y<<"*"<<z<<"*"<<w<<"="<<result<<endl;flag++;} 
    else if ((x+y)+(z/w)==result) {cout<<"("<<x<<"+"<<y<<")+("<<z<<"/"<<w<<")"<<"="<<result<<endl;flag++;}  
    else if ((x+y)*(z/w)==result) {cout<<"("<<x<<"+"<<y<<")*("<<z<<"/"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)+z+w==result) {cout<<"("<<x<<"*"<<y<<")+"<<z<<"+"<<w<<"="<<result<<endl;flag++;}  
    else if ((x*y)+z-w==result) {cout<<"("<<x<<"*"<<y<<")+"<<z<<"-"<<w<<"="<<result<<endl;flag++;}   
    else if ((x*y)-(z/w)==result) {cout<<"("<<x<<"*"<<y<<")-("<<z<<"/"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)+(z/w)==result) {cout<<"("<<x<<"*"<<y<<")-("<<z<<"/"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)-z-w==result) {cout<<"("<<x<<"*"<<y<<")-"<<z<<"-"<<w<<"="<<result<<endl;flag++;}   
    else if ((x*y)+(z*w)==result) {cout<<"("<<x<<"*"<<y<<")+("<<z<<"*"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)-(z*w)==result) {cout<<"("<<x<<"*"<<y<<")-("<<z<<"*"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)/(z*w)==result) {cout<<"("<<x<<"*"<<y<<")/("<<z<<"*"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)/(z-w)==result) {cout<<"("<<x<<"*"<<y<<")/("<<z<<"-"<<w<<")"<<"="<<result<<endl;flag++;}   
    else if ((x*y)/(z+w)==result) {cout<<"("<<x<<"*"<<y<<")/("<<z<<"+"<<w<<")"<<"="<<result<<endl;flag++;}
    else if ((x*y+z)/w==result) {cout<<"("<<x<<"*"<<y<<"+"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x*y-z)/w==result) {cout<<"("<<x<<"*"<<y<<"-"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x/y+z)/w==result) {cout<<"("<<x<<"/"<<y<<"+"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x/y-z)/w==result) {cout<<"("<<x<<"/"<<y<<"-"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x+y*z)/w==result) {cout<<"("<<x<<"+"<<y<<"*"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x+y/z)/w==result) {cout<<"("<<x<<"+"<<y<<"/"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x-y*z)/w==result) {cout<<"("<<x<<"-"<<y<<"*"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x-y/z)/w==result) {cout<<"("<<x<<"-"<<y<<"/"<<z<<")/"<<w<<"="<<result<<endl;flag++;}
    else if ((x-y)*z+w==result) {cout<<"("<<x<<"-"<<y<<")"<<"*"<<z<<"+"<<w<<endl;flag++;}
    else if ((x-y)*z-w==result) {cout<<"("<<x<<"-"<<y<<")"<<"*"<<z<<"-"<<w<<endl;flag++;}
    else if ((x+y)*z+w==result) {cout<<"("<<x<<"+"<<y<<")"<<"*"<<z<<"+"<<w<<endl;flag++;}
    else if ((x+y)*z-w==result) {cout<<"("<<x<<"+"<<y<<")"<<"*"<<z<<"-"<<w<<endl;flag++;}
    else if ((x-y)/z-w==result) {cout<<"("<<x<<"-"<<y<<")"<<"/"<<z<<"-"<<w<<endl;flag++;}
    else if ((x+y)/z-w==result) {cout<<"("<<x<<"+"<<y<<")"<<"/"<<z<<"-"<<w<<endl;flag++;}
    else if ((x-y)/z+w==result) {cout<<"("<<x<<"-"<<y<<")"<<"/"<<z<<"+"<<w<<endl;flag++;}
    else if ((x+y)/z+w==result) {cout<<"("<<x<<"+"<<y<<")"<<"/"<<z<<"-"<<w<<endl;flag++;}
	else if ((x/y-z)*w==result) {cout<<"("<<x<<"/"<<y<<"-"<<z<<")*"<<w<<"="<<result<<endl;flag++;}
	else if ((x/y+z)*w==result) {cout<<"("<<x<<"/"<<y<<"+"<<z<<")*"<<w<<"="<<result<<endl;flag++;}
	else if ((x*y-z)*w==result) {cout<<"("<<x<<"*"<<y<<"-"<<z<<")*"<<w<<"="<<result<<endl;flag++;}
	else if ((x*y-z)*w==result) {cout<<"("<<x<<"*"<<y<<"-"<<z<<")*"<<w<<"="<<result<<endl;flag++;}
	return 0;   
}
int check(int *a, int *b, int *c, int *d)
{
	int temp;
	if((*a)!=(*b)&&(*a)!=(*c)&&(*a)!=(*d)&&(*b)!=(*c)&&(*b)!=(*d)&&(*c)!=(*d))//都不相等，则不做调整 
		return 0;
	else if((*a)==(*b)&&(*a)==(*c)&&(*a)==(*d))//都相等，也不做调整 
		return 4;
	else if((*a)==(*b)&&(*a)==(*c)&&(*a)!=(*d)) //其中三个相等 
	{
		temp=(*d);
		(*d)=(*a);
		(*a)=temp;
		return 3;
	}
	else if((*a)==(*b)&&(*a)==(*d)&&(*a)!=(*c)) //其中三个相等 
	{
		temp=(*c);
		(*c)=(*a);
		(*a)=temp;
		return 3;
	}
	else if((*a)==(*c)&&(*a)==(*d)&&(*a)!=(*b)) //其中三个相等 
	{
		temp=(*b);
		(*b)=(*a);
		(*a)=temp;
		return 3;
	}
	else if((*b)==(*c)&&(*b)==(*d)&&(*b)!=(*a)) //其中三个相等 
		return 3;
	else if((*a)==(*b)&&(*a)!=(*c)&&(*a)!=(*d)&&(*c)!=(*d)) //其中两个相等 
	{
		temp=(*c);
		(*c)=(*a);
		(*a)=temp;
		temp=(*d);
		(*d)=(*b);
		(*b)=temp;
		return 1;
	}
	else if((*a)==(*c)&&(*a)!=(*b)&&(*a)!=(*d)&&(*b)!=(*d))//其中两个相等
	{
		temp=(*d);
		(*d)=(*a);
		(*a)=temp;
		return 1;
	}
	else if((*a)==(*d)&&(*a)!=(*b)&&(*a)!=(*c)&&(*b)!=(*c))//其中两个相等
	{
		temp=(*c);
		(*c)=(*a);
		(*a)=temp;
		return 1;
	}
	else if((*b)==(*c)&&(*b)!=(*a)&&(*b)!=(*d)&&(*a)!=(*d))//其中两个相等
	{
		temp=(*d);
		(*d)=(*b);
		(*b)=temp;
		return 1;
	}
	else if((*b)==(*d)&&(*b)!=(*a)&&(*b)!=(*c)&&(*a)!=(*c))//其中两个相等
	{
		temp=(*c);
		(*c)=(*b);
		(*b)=temp;
		return 1;
	}
	else if((*c)==(*d)&&(*c)!=(*a)&&(*c)!=(*b)&&(*a)!=(*b))//其中两个相等
		return 1;
	else if((*a)==(*b)&&(*c)==(*d)&&(*a)!=(*c))//其中两组两个相等
		return 2;
	else if((*a)==(*c)&&(*b)==(*d)&&(*a)!=(*b))//其中两组两个相等
	{
		temp=(*b);
		(*b)=(*c);
		(*c)=temp;
		return 2;
	}
	else   //其中两组两个相等
	{
		temp=(*b);
		(*b)=(*d);
		(*d)=temp;
		return 2;
	}
}

int main()  
{ 
	int a,b,c,d;  
	m_ret: //做标记  
	cout<<"请输入4个数据"<<endl;  
	cout<<" 第一个数：";  
	cin>>a;  
	cout<<" 第二个数：";  
	cin>>b;  
	cout<<" 第三个数：";  
	cin>>c;  
	cout<<" 第四个数：";  
	cin>>d;  
	cout<<"输出所有算法如下："<<endl;  
	if ((a<0)||(a>13)||(b<0)||(b>13)||(c<0)||(c>13)||(d<0)||(d>13))  
	{ 
		cout<<"你输入的输入不对，重新输入"<<endl;  
		goto m_ret; 
	} // 返回标记，重复输入 
	if(check(&a,&b,&c,&d)==0)//分成五种情况，都不想等，有两个相等(两种)，有三个相等，有四个相等 ,并且把相等的往后放 
	{
		Calculate(a,b,c,d); Calculate(a,b,d,c); Calculate(a,c,d,b);  
		Calculate(a,c,b,d); Calculate(a,d,b,c); Calculate(a,d,c,b);  
		Calculate(b,a,c,d); Calculate(b,a,d,c); Calculate(b,c,a,d);  
		Calculate(b,c,d,a); Calculate(b,d,c,a); Calculate(b,d,a,c);  
		Calculate(c,a,b,d); Calculate(c,a,d,b); Calculate(c,b,d,a);  
		Calculate(c,b,a,d); Calculate(c,d,a,b); Calculate(c,d,b,a);  
		Calculate(d,a,b,c); Calculate(d,a,c,b); Calculate(d,b,c,a);  
		Calculate(d,b,a,c); Calculate(d,c,a,b); Calculate(d,c,b,a); 
	}
	else if(check(&a,&b,&c,&d)==1)  //只有一组一样的，即交换后的c和d 
	{
		Calculate(a,b,c,d);
		Calculate(a,c,d,b);  
		Calculate(a,c,b,d); Calculate(a,d,c,b);
		Calculate(b,a,c,d); Calculate(b,c,a,d);  
		Calculate(b,c,d,a);   
		Calculate(c,a,b,d); Calculate(c,a,d,b); Calculate(c,b,d,a);  
		Calculate(c,b,a,d); Calculate(c,d,a,b); Calculate(c,d,b,a);  
	}
	else if(check(&a,&b,&c,&d)==2)  //有两组一样的，即交换后的a和b    c和d
	{
		Calculate(a,b,c,d); Calculate(a,c,d,b); Calculate(a,c,b,d);
		Calculate(c,a,b,d); Calculate(c,a,d,b); Calculate(c,d,a,b);
	}
	else if(check(&a,&b,&c,&d)==3)
	{
		Calculate(a,b,c,d);Calculate(b,a,c,d);
		Calculate(c,b,a,d);Calculate(d,b,c,a);
	}
	else
		Calculate(a,b,c,d);
	if(flag==0)
		cout<<"-1"<<endl;
	else
		cout<<"一共有"<<flag<<"种算法"<<endl;
	return 0;
}  