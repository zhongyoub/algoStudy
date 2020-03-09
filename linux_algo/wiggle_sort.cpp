/**
 * 给定一个数组，实现a[i-1]<a[i]>a[i+1] 或 a[i-1]>a[i]<a[i+1]
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000
int array[1000];

int partition(vector<int> &number, int begin, int end, int *count)
{
    if (number.size() == 1)
        return number[0];
    int index = number[begin];
    int low = begin, high = end;
    while (low < high)
    {
        while ((high > low) && (number[high] >= index))
            high--;
        if (high > low)
        {
            number[low++] = number[high];
            *count++;
        }

        while ((low < high) && (number[low] <= index))
            low++;
        if (low < high)
        {
            number[high--] = number[low];
            *count++;
        }
    }
    number[low] = index;
    return low;
}

int wiggleSort1(vector<int> &nums)
{
    int count = 0;
    if (nums.size() <= 2)
        return 0;
    int len = nums.size();
    int begin = 0, end = len - 1, mid = begin + (end - begin) / 2;
    int index = partition(nums, begin, end, &count);
    while (index != mid)
    {
        if (index < mid)
            begin = index + 1;
        else
            end = index - 1;
        index = partition(nums, begin, end, &count);
    }

    mid = nums[index];
    int n = len;
// Index-rewiring.
#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        int pos = (1 + 2 * (j)) % (n | 1);
        if (A(j) > mid)
        {
            swap(A(i++), A(j++));
            count++;
        }
        else if (A(j) < mid)
        {
            swap(A(j), A(k--));
            count++;
        }
        else
            j++;
    }
    return count;
}

/*
void quickSelect(vector<int> &nums, int begin, int end, int n){
        int t = nums[end - 1];
        int i = begin, j = begin;
        while(j < end){
            if(nums[j] <= t){
                swap(nums[i++], nums[j++]);
            }
            else{
                ++j;
            }
        }
        if(i - 1 > n){
            quickSelect(nums, begin, i - 1, n);
        }
        else if(i <= n){
            quickSelect(nums, i, end, n);
        }
    }
}

void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        quickSelect(nums, 0, len, len / 2);
        auto midptr = nums.begin() + len / 2;
        int mid = *midptr;
        
        // 3-way-partition
        int i = 0, j = 0, k = nums.size() - 1;
        while(j < k){
            if(nums[j] > mid){
                swap(nums[j], nums[k]);
                --k;
            }
            else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }
        
        if(nums.size() % 2) 
            ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
}
*/


int main()
{
    vector<int>vc;
    int n, count;
    cout << "请输入数组的数目" << endl;
    cin >> n;
    if (n > MAX)
    {
        cout << "数组数目太大" << endl;
        return 0;
    }
    cout << "请输入数组" << endl;
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    vc.insert(vc.begin(), array, array+n);
    count = wiggleSort1(vc);
    cout<<count<<endl;
    for (int i = 0; i < vc.size(); i++)
        cout << vc[i]<< endl;

    return 0;
}

