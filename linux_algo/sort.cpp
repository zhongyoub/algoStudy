/*
排序
思想：将两个有序的数组归并为一个有序的数组

非稳定排序：希尔排序，快速排序
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

/*
冒泡排序:两两比较，根据大小交换位置
*/
void bubbleSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i;j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
}

/*
选择排序：选择最大或最小的排序
*/
void selectSort1(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void selectSort2(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_index])
                min_index=j;
        }
        if(i!=min_index)
        {
            int temp=i;
            a[i]=a[min_index];
            a[min_index]=a[temp];
        }
    }
}

/*
插入排序：将前i个元素当作已经排好序的元素，后面元素按序插入
*/
void insertSort(int a[], int n)
{
    //前面0...i-1个元素已经排好序
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        {
            int j=i-1;
            int x=a[i];
            while(j>-1 && x<a[j])   //移动已经排好序的数组，空出一个位置
            {
                a[j+1]=a[j];
                j--
            }
            a[j+1]=x;      
        }
    }
}

/*
希尔排序:
通过某个增量将数组划分为若干组，然后分组进行插入排序，
随后逐步缩小增量，继续按组进行插入排序操作，直至增量为1
*/
void shellSort(int a[], int n)
{
    int gap, i, j;
    int temp;
    for(gap=len>>2; gap>0; gap>>=1)
        for(i=gap;i<len;i++)
        {
            temp=a[i];
            for(j=i-gap; j>=0 && a[i]>temp; j-=gap)
                a[j+gap]=a[j];
            a[j+gap]=temp;
        }
}

/*
快速排序：取一个分割点，将小于的放在左边，大于的放在右边，然后在对两边的部分使用递归的方式进行排序
*/
int partition(int a[], int low, int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(low<high && a[high]>=pivot)
            --high;
        a[low]=a[high];    //while退出，则low==high 或a[high]<pivot;
        while(low<high && a[low]<=pivot)    //while退出，则a[low]>pivot,
            ++low;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quickSort(int a[], int left, int right)
{
    if(low < high)
    {
        int pivoit=partition(a,left,right);
        quickSort(a,left,pivoit-1);
        quickSort(a,pivot+1,right);
    }
}

/*
堆是一个近似完全二叉树的结构
最大堆：每个结点的值都大于或等于其左右孩子结点的值
最小堆：每个结点的值都小于或等于其他左右孩子结点的值
堆排序：
（1）将待排序数组构成最大堆，此时，整个序列的最大值就是堆顶的根节点
（2）将其与末尾元素进行交换，此时末尾就为最大值
（3）然后将剩余n-1个元素重新构成一个堆，如此反复
*/
//构建最大堆
/*
父节点i的左子节点在位置(2i+1)
父节点i的右子节点在位置(2i+2)
子节点i的父节点在位置floor((i-1)/2)
*/
void  max_heapify(int arr[], int start ,int end)
{
    //父节点和子节点
    int dad=start;
    int son=dad*2+1;
    while(son<=end)
    {
        if(son+1<=end && arr[son]<arr[son+1])   //选择子节点大的
            son++;
        if(arr[dad]>arr[son])
            retrun;
        else
        {
            swap(&arr[dad], &arr[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
//堆排序
void heap_sort(int arr[], int len)
{   //初始化，i从最后一个父节点开始调制
    int i;
    for(i=len/2-1;i>=0;i--)
        max_heapify(arr, i, len-1);
    //先将第一个元素和已经排好元素前一位做交换，在重新调整，直到排序完全
    for(i=len-1; i>0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr,0,i-1);
    }
}
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


int main(int argc, char* argv[])
{
    //mergeSort2(arr,8);
    mergeSort(0, 8);
    for(int i=0;i<8;i++)
        cout<<arr[i]<<endl;
    return 0;
}
