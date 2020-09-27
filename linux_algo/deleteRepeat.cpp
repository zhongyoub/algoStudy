/*
删除字符串中所有重复出现的字符，如 hello,xiaomi,处理完之后变成helo,xiam
*/

/*
解题思路：可以使用哈希表存储表字符串，然后对每个字符检查是否在哈希表中，
没有则说明是第一次出现，则添加到哈希表汇总并添加到新的字符串末尾
也可以使用bool型哈希表
*/

#include<iostream>
#include<cstring>
using namespace std;

void deleteRepeat(char *str, char *back)
{
    if(str==NULL || strlen(str)==1)
    {
        back=str;
        return;
    }
    bool hashtable[256];
    for(int i=0;i<256;i++)
        hashtable[i]=false;
    int len=strlen(str);
    int j=0;
    for(int i=0;i<len;i++)
    {
        if(!hashtable[*(str+i)])            
        {
            hashtable[*(str+i)]=true;
            back[j++]=str[i];
        }
    }
    back[j]='\0';
}
int main()
{
    char* str1="hello, xiaomi, this is a test";
    char str2[30]={0};
    deleteRepeat(str1, str2);
    cout<<str2<<endl;
    return 0;
}