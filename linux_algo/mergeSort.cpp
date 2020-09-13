/*
归并排序
思想：将两个有序的数组归并为一个有序的数组
*/

#include <iostream>
using namespace std;

int arr[8]={6,3,2,7,1,5,8,4};
void merge(int lo, int mi, int hi)   //左右两个有序的子数组 arr[0, mi)和array[mi,hi)
{
    int* A=arr+lo;
    int lb=mi-lo;
    int* B=new int[lb];
    for(int i=0; i<lb; i++)
        B[i]=A[i];
    int lc=hi-mi;
    int* C=arr+mi;
    for(int i=0,j=0,k=0;(j<lb)||(k<lc);)
    {
        if((j<lb) && (!(k<lc)||(B[j]<=C[k])))  
            A[i++]=B[j++];
        if((k<lc) && (!(j<lb)||(C[k]<B[j])))
            A[i++]=C[k++];
    }
    delete []B;
}

void mergeSort(int lo, int hi)
{
    if((hi-lo)<2)
        return;
    int mi=(lo+hi)>>1;
    mergeSort(lo,mi);
    mergeSort(mi,hi);
    merge(lo,mi,hi);
}


void merge2(int *A, int *L, int left, int* R, int right)
{
    int i,j,k;
    i=j=k=0;
    while(i<left && j<right)
    {
        if(L[i]<R[j])
            A[k++]=L[i++];
        else
            A[k++]=R[j++];
    }
    while(i<left) A[k++]=L[i++];
    while(j<right) A[k++]=R[j++];
}
void mergeSort2(int* A, int n)
{
    if(n<2)
        return;
    int mid;
    int *L, *R;
    mid=n>>1;
    L=new int[mid];
    R=new int[n-mid];
    for(int i=0;i<mid;i++) L[i]=A[i];
    for(int i=mid;i<n;i++) R[i-mid]=A[i];
    mergeSort2(L,mid);
    mergeSort2(R,n-mid);      // sorting the right subarray
	merge2(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
	// the delete operations is very important
	delete [] R;
	delete [] L;
}

int main(int argc, char* argv[])
{
    //mergeSort2(arr,8);
    mergeSort(0, 8);
    for(int i=0;i<8;i++)
        cout<<arr[i]<<endl;
    return 0;
}
