/*
使用new分配一个指定输入大小的二维数组
*/

#include<iostream>
using namespace std;

int main()
{
    int arr2[2][2]={{1,1},{2,2}};
    int *arr1[2];
    int *arr3;
    arr3=new int(0);
    *arr3=arr2[0][0];
    arr1[0]=arr2[0];
    arr1[1]=arr2[1];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<arr1[i][j]<<endl;

    cout<<*arr3<<endl;
    delete arr3;
    
    cout<<"--------"<<endl;
    //定义一个二维数组
    int n;
    cout<<"请输入矩阵的列数"<<endl;
    cin>>n;
    int **arr=new int*[n]; //二维数组分配内存（外层）
    for(int i=0;i<n;++i)
    {
        arr[i]=new int[n];  //二维数组分配内存（外层）
    }
    for(int i=0;i<n;++i)
     //   arr[i]=arr2[i];    这里这样会导致内存释放出错
    
        for(int j=0;j<n;++j)
            arr[i][j]=arr1[i][j];
    
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            cout<<arr[i][j]<<endl;
    //销毁内存
    for(int i=0;i<n;i++)
    {
        delete[] arr[i];
        arr[i]=NULL;
    }
    delete[] arr;
    arr=NULL;
    return 0;
}