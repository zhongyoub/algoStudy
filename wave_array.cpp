/*
给一数组，计算最少经过多少次转换可以转换为波动数组，波动数组定义：Vn<min(Vn-1,Vn+1)或Vn>max(Vn-1,Vn+1)，
转换含义为两数对调
例：1,2,3,4,5,6,7 经过2次
1,7,3,4,5,6,2
1,7,3,5,4,6,2
 
问题一：给数组，输出任一转换后的波动数组；
问题二：给数组，输出最少转换次数及转换后的波动数组。

大小大排序，或是小大小排序

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define max 1000
int array[1000];

//比较
int compare(int a, int b)
{
    if (a>b)
        return 0;
    if(a<b)
        return 1;
    if(a==b)
        return 2;
    return 0;
}

//小大小大排序，也可以大小大小方式排序
void change(int *a, int n)
{
    for(int i=1;i<n;i++)
    {
        int *num1=&a[i-1];
        int *num2=&a[i];
        if(i%2==0)     //偶序号数
        {
            if(compare(*num1, *num2)==1)     // 奇序号数 < 偶序号数
            {
                swap(*num1, *num2);
            }
        }
        else          //当为奇序号
        {
            if(compare(*num1, *num2)==0)     // 奇序号数 < 偶序号数
            {
                swap(*num1, *num2);
            }
        }
    }
}

int condition(int a, int b ,int c)
{
    if( (a<=b && b>=c) || (a>=b && b<=c))
        return 1;
    return 0;
}

/*
数组元素放置到波峰波谷，交换的次数最少
*/
int change2(int *a, int n)
{
    int count=0;
    if(n<=2)
        return 0;
    
    int mid=n/2;

    /*
    for(int i=1, j=n-2; i<=n/2,j>=n/2;i++,j--)
    {
        if(!condition(a[i-1],a[i],a[i+1]) && !condition(a[j-1],a[j],a[j+1]))
        {
            swap(a[i], a[j+1]);
            count++;
        }
        else if(!condition(a[i-1],a[i],a[i+1]) && condition(a[j-1],a[j],a[j+1]))   
        {
            if(a[i-1]<a[i] && a[i]<a[i+1])
            {
                swap(a[i],a[i+1]);
                count++;
            }
            else if(a[i-1]>a[i] && a[i]>a[i+1])
            {
                 swap(a[i-1],a[i]);
                 count++;
            }
        }
        else if(condition(a[i-1],a[i],a[i+1]) && !condition(a[j-1],a[j],a[j+1]))   
        {
            if(a[j-1]<a[j] && a[j]<a[j+1])
            {
                 swap(a[j],a[j+1]);
                 count++;
            }
            else if(a[j-1]>a[j] && a[j]>a[j+1])
            {
                  swap(a[j-1],a[j]);
                  count++;
            }
        }
    }
    int mid=n/2;
    if(a[mid-1]<a[mid] && a[mid]<a[mid+1])
    {
        swap(a[mid],a[mid+1]);
        count++;
    }
    else if(a[mid-1]>a[mid] && a[mid]>a[mid+1])
    {
        swap(a[mid-1],a[mid]);
        count++;
    }
    */

   return count;
}

int main()
{
    int n;
    cout<<"请输入数组的数目"<<endl;
    cin>>n;
    if(n>max)
    {
        cout<<"数组数目太大";
        return 0;
    }
    cout<<"请输入数组"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    change(array, n);
    for(int i=0;i<n;i++)
        cout<<array[i]<<endl;

    return 0;
}