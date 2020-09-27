/*
（1）给定一个包含非负数的数组和一个整数K,数组中是否包含连续的子数组(长度>=1)，和为K的倍数
（2）求最短子数组
*/

#include <iostream>
#include <Map>
using namespace std;

/*
使用暴力法,求所有的子数组和
*/
bool checkSubarraySum1(int a[], int n, int k)
{
    for(int start=0; start<n; start++)
    {
        int sum=0;
        for(int j=start;j<n;j++)
        {
            sum+=a[j];
            if(sum==k || k!=0 && sum%k==0)
                return true;
        }
    }
}

bool checkSubarraySum2(int a[], int n, int k)
{
    for(int start=0; start<n; start++)
    {
        for(int end=start+1;end<=n;end++)
        {
            int sum=0;
            for(int i=start;i<end;i++)
            {
                sum+=a[i];
                if(sum==k||(k!=0 && sum%k==0))
                    return true;
            }
        }
    }
}

/*
如果一个元素开始开始的后面若干个数的和能够整除k,那么这个元素加上若干个元素依次取余 k 后相加再取余 k 则一定还是等于这个元素。
举例说明：例如数组  [23,2,4,6,7] k = 6，也就是 23+((2%6)+(4%6))%6 = 23，所以2+4为6的整倍数
可以使用hashmap存储a[0..i]%k的余数，key为i，如果在a[j=i+1...n]存在相同的value，则子数组长度为j-i
*/

int getMinlen(int a[], int n ,int k)
{
    map<int, int> hashmap;
    int sum=0;
    for(int i=0; i<n;i++)
    {
        sum+=a[i];
        if(k!=0 && sum%k!=0)
            map[i]=sum%k;
    }
}