#include<iostream>
using namespace std;
/*
方阵旋转m次
*/
#define M 10000
#define N 10

int main()
{
    int m,n;
    int matrix[N][N]={0};
    int new_matrix[N][N]={0};
    cout<<"请输入旋转次数和方阵的阶数"<<endl;
    cin>>m>>n;
    cout<<"请输入方阵"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    if(m<=M)
        m=m%4;
    if(n==1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                new_matrix[i][j]=matrix[n-j-1][i];
            }
    }
    else if(m==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                new_matrix[i][j]=matrix[n-i-1][n-j-1];
            }
    }
    else if(m==3)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                new_matrix[i][j]=matrix[j][n-i-1];
    }
    else 
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                new_matrix[i][j]=matrix[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<new_matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}


