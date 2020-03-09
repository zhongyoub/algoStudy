#include<iostream>
#include<map>
#include<string>

using namespace std;

/*
【字符串类型】给一串数字，输出这些数字能够组成的合法的最大时间，数字不够则用零补全
例：
输入：“274536”
输出：“23:57:46”
*/

map<int, int>mm;
string res = "";

//
int get(int mx) {
	int i = mx;
	for (; i >= 0; i--) {
		if (mm[i] > 0) {
			mm[i]--;
			return i;
		}
	}
	return  - 1;
}

void init() {
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		mm[i] = 0;
	}
}

void push(int k) {
	if (-1 != k) {
		res.push_back(k + '0');
	}
	else {
		res.push_back('0');
	}
}

bool string_check(string s)
{
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		int temp = (int)s[i];
		if (temp >= 48 && temp <= 57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
		return true;
}

int main()
{
	string s;
	//输入数字字符串
	cin >> s;
	//检查输入是否全为数字
	if (!string_check(s))
		return -1;
	int len  = s.length();
	int i, j, k, l;
	// 字符串中每个字符转换为map的key,value是数字的个数
	for (i = 0; i < len; i++) {
		mm[(int)(s[i] - '0')]++;
	}
	k  = get(2);
	push(k);
	if (2 == k) {
		push(get(3));
	}
	else {
		push(get(9));
	}
	res.push_back(':');
	push(get(5));
	push(get(9));
	res.push_back(':');
	push(get(5));
	push(get(9));
	cout << res << endl;
	return 0;
}