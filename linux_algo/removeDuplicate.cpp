/*
删除数组中重复的元素
*/
#include <iostream>
using namespace std;

int array[10]={1,1,1,1,1,1,1,1,1,1};
int size=10;
int remove_sequence(int lo, int hi)
{
    if(lo==hi)
        return 0;
    while(hi<size)
        array[lo++]=array[hi++];
    size=lo;
    return hi-lo;
}
int remove(int index)
{
    int object=array[index];
    remove_sequence(index,index+1);
    return object;
}

int unqify()
{
    int oldsize=size;
    int i=1;
    while(i<size)
        array[i-1]==array[i]?remove(i):i++;     //这里很重要
    return oldsize-size;    
}
int unqifyImrove()
{
    int i=0, j=0;
    while(++j<size)
        if(array[i]!=array[j])
            array[++i]=array[j];
    size=++i;
    return (j-i);     //返回被删除元素的个数
}

int main() {
    unqify();
	for(int i=0;i<size;i++)
	    cout<<array[i]<<endl;
	return 0;
}