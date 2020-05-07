#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;

/*
【数组类型】客户经理小郭明下有n个客户，每个客户持有部分可用资金，现行内推出理财产品P0001，
客户经理小郭争取到总额度100万元，需在名下客户内选择5个客户，要求5个客户名下的可用资金总和最接近总额度100万元。
输入：以csv文件格式给出姓名和可用资金（单位：万）的列表，如
张三,23
李四,12
王五,33

输出：
5个客户姓名和需占用的总额度。

分析：该问题是从中选取5个数，最接近100，并且输出选取的，可能存在多种组合
*/

/*
vector< map<int, vector<string> > >vv(5);

int main()
{
	int i, j, k, l;
	char ssch[1024];
	const char *del = ",";
	//输入
	memset(ssch,0,sizeof(ssch));
	while(cin>>ssch)
	{
		if (strcmp(ssch, "end"))
			break;
		//对输入的字符串进行分割
		char *tokenPtr = strtok(ssch, del);    //sentence必须是一个char数组，不能是定义成指针形式
		string name(tokenPtr);
		tokenPtr = strtok(NULL, del);
		k = 0;
		l = strlen(tokenPtr);
		//数字字符串转换为整数
		for (i = 0; i < l; i++) {
			k = k * 10 + tokenPtr[i] - '0';
		}
		// cout<<name<<"-->>"<<k;
		int tsum = 0;
		for (i = 3; i >= 0; i--) {
			map<int, vector<string> >tmpm = vv[i];
			if (tmpm.size() == 0)continue;

			for ( map<int, vector<string> >::iterator it = tmpm.begin(); it != tmpm.end(); it++) {
				tsum = it->first + k;
				// cout<<"tsum-->"<<tsum<<endl;
				if (tsum > 100)continue;
				if (vv[i + 1].find(tsum) != vv[i + 1].end()) {

				}
				else {
					vv[i + 1][tsum] = it->second;
					vv[i + 1][tsum].push_back(name);
				}
			}
		}
		if (vv[0].find(k) == vv[0].end()) {
			vv[0][k]={name};        // problem 
			// cout<<"----"<<endl;
		}

	}

	int tmax = -1;
	vector<string> tres;
	for (map<int, vector<string> >::iterator it = vv[4].begin(); it != vv[4].end(); it++) {
		cout<< "----" << endl;
		if (it->first > tmax) {
			tmax = it->first;
			tres = it->second;
		}
	}

	cout << "总金额：" << tmax << endl;
	cout << "客户姓名：";
	for (i = 0; i<tres.size(); i++) {
		cout << tres[i] << "---";
	}
	cout << endl;
	return 0;
}
*/
vector<map<int,vector<string> > > vv(5);
int main()
{
	int i,j,k,l;
	string s="";
	char ssch[1024];
	const char *del = ",";
	while(cin>>s){
		// char * sstr = s.c_str;
		memset(ssch,0,sizeof(ssch));
		strncpy(ssch,s.c_str(),s.length()+1);
		char *tokenPtr=strtok(ssch,del);  //ssch必须是一个char数组，不能是定义成指针形式
		string name(tokenPtr);
		tokenPtr=strtok(NULL,del);
		k=0;
		l=strlen(tokenPtr);
		for(i=0;i<l;i++){
			k=k*10+tokenPtr[i]-'0';
		}
		// cout<<name<<"-->>"<<k;
		int tsum=0;
		for(i=3;i>=0;i--){
			map<int,vector<string>>tmpm=vv[i];
			if(tmpm.size()==0)
				continue;

			for(map<int,vector<string> >::iterator it=tmpm.begin();it!=tmpm.end();it++){
				tsum=it->first+k;
				// cout<<"tsum-->"<<tsum<<endl;
				if(tsum>100)continue;
				if(vv[i+1].find(tsum)!=vv[i+1].end()){

				}
				else{
					vv[i+1][tsum]=it->second;
					vv[i+1][tsum].push_back(name);
				}
			}
		}
		if(vv[0].find(k)==vv[0].end())
		{
			vv[0][k]={name};
			// cout<<"----"<<endl;
		}
	}

	int tmax=-1;
	vector<string> tres;
	for(map<int,vector<string> >::iterator it=vv[4].begin();it!=vv[4].end();it++){
		cout<<"----"<<endl;
		if(it->first > tmax){
			tmax=it->first;
			tres=it->second;
		}
	}

	cout<<"总金额："<<tmax<<endl;
	cout<<"客户姓名：";
	for(i=0;i<tres.size();i++){
		cout<<tres[i]<<"---";
	}
	cout<<endl;
	return 0;
}

/*
从一堆数中取5个数，和最接近100，可以看为容量为100，选择5件商品的背包问题
定义m(i,j,N)为从前i个数中取出N个数的和为j。
第i个数分为选与不选
（1）if value[i]>100-j, m[i,j,N]=m[i-1,j,N]
（2）if value[i]<=100-j, m[i,j,N]=max{m[i-1,j,N],m[i-1,j-value[i],N-1]+value[i]}
如果使用
该问题要求选择5个，考虑需要将选择的数据输出，需要记录路径
count: 客户数量, N不超过1000
value: 100
*/
int m[1001][101][5];
int findMax(int count, int value)
{
	for(int i=0;i<=value;i++)
		m[0][i]=0;
	for(int j=0;j<=count;j++)
		m[j][0]=0;
	for(int i=1; i<=count;i++)
	{
		for(int j=1;j<=value;j++)
	}
}

/*
使用二进制序列，长度为客户数量，其中1表示选择该客户，0 不是不选该客户
列如：加入客户数为8人，二进制 1111 1000 表示选取后面五个。
对于guest_count,则二进制长度为guest_count，其值范围为0- 2^guest_count-1
现在将所有可能的选取转变为遍历一个数组(数组长度为2^guest_count-1)
然后通过迭代计算满足1的个数为5，确定实际的值。
二进制和实际值之间的映射关系：1110左边的第一个1对应数组【1，2，3，4】中的1 
可以通过移位： 1<<index, index为数组的下表确定是否选取了数组中的元素
如 1<<3 =1000 & 14 (1110) =1000,表示选取数组了的 1
所以，i & (1<<index)!=0 表示选取了arr[index]
*/
map<int, map<string, int> > findGuest(vector< map<string, int>>& mapGuest, int guest_count, int count)
{
	map<int, map<string, int> > res;
	int bit=1<<guest_count;
	for(int i=1; i<bit; i++)
	{
		if(getNumber(i)==count)     //满足选取的数目为5个数
		{
			int sum;
			map<string, int>::iterator iter;
			map<string,int> tmp;
			for(int j=0;j<guest_count;j++)
			{
				if((i & 1<<j)!=0)    // 选取了guest[j]
				{
					iter=mapGuest[j].begin();
					sum+=iter->second;
					tmp.insert(pair<string,int>(iter->first,iter->second));
				}
			}
			res[sum]=tmp;   
		}
	}
	return res;
}

/*
计算一个数的二进制有多少个1
*/
int getNumber(int num)
{
	int count=0;
	while(num)
	{
		num &= (num-1);
		count++;
	}
	return count;
}

/*
 找出最接近M的结果：可能和M相等，或是小于M ，输出结果
 */
void findNearest(map<int, map<string, int>> & res)
{

}

