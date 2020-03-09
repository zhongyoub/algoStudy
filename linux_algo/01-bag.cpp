#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cstring>

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

 01背包问题
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