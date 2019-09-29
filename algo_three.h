#pragma once

/*
数组的山峰问题
我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
B.length >= 3
存在 0 < i < B.length - 1 使得 B[0] < B[1] < … B[i-1] < B[i] > B[i+1] > … > B[B.length - 1]
（注意：B 可以是 A 的任意子数组，包括整个数组 A。）
（1）给出一个整数数组 A，返回最长 “山脉” 的长度。如果不含有 “山脉” 则返回 0。
（2）输出山脉
*/
/*
从左到右扫描，是否满足山脉性质，如果满足,则tempMax++, 不满足，则更新当前得到山脉的长度maxLen, 继续下一个
*/
int getMaxMoutain(int a[], int n);


int getMaxmoutian2(int a[], int n);
