/*
给定一个n（0<n<10)阶方阵，顺时针旋转m(0<=m<=1000)次，求旋转后的矩阵
解：每次旋转相当于旋转90度，旋转4次后恢复为原样

解：二维数组的转换公式为a[i][j]=a[i*rank+j]


*/
#include<iostream>
using namespace std;

#define M 10000
#define N 10

int main()
{
    int m,n;
    cout<<"请输入旋转次数和方阵的阶数"<<endl;
    cin>>m>>n;
    int **matrix=new int*[n];  //分配二维数组内存（外层）
    int **new_matrix=new int*[n];
    for(int i=0;i<n;i++)
    {
         matrix[i]=new int[n];
         new_matrix[i]=new int[n];
    }
       
    cout<<"请输入方阵"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];
    }
    if(m<=M)
        m=m%4;
    if(m==1)
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
    //释放内存
    for(int i=0;i<n;i++)
    {
        if(matrix[i]!=NULL)
        {
            delete [] matrix[i];
            matrix[i]=NULL;
        }
        if(new_matrix[i]!=NULL)
        {
            delete[] new_matrix[i];
            new_matrix[i]=NULL;
        }
    }
    if(matrix!=NULL)
    {
        delete[] matrix;
        matrix=NULL;
    }
    if(new_matrix!=NULL)
    {
        delete[] new_matrix;
        new_matrix=NULL;
    }
    return 0;
}


