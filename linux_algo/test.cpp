'''
测试
'''
#include <iostream>
using namespace std;

int find(int e, int first, int last, int array[], int n)
{
    while((first<last--) && (e!=array[last]));
    return last;
}

int main(int argc, char **argv)
{

    int array[10]={1,2,3,4,5,6,7,8,9,10};
    int object=1;
    int result=find(object, 0, 9, array, 10);
    cout<<result;
    cout<<"test"<<endl;
    return 0;
}