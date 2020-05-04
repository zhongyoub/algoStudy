/*
从csv文件中读取数据
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

string trim(string &str)
{
    // string.find_first_not_of('\t\r\n')在字符串str中从0开的始索引，返回首次不匹配的位置
    str.erase(0,str.find_first_not_of('\r\n'));
    str.erase(str.find_last_not_of('\r\n'));
    return str;
}

//字符串转换为数字
int strtoint(string str)
{
    int num=0;
    for(int i=0;i<str.length();i++)
    {
        num=num*10+str[0]-'0';
    }
    return num;
}


int main(int argc, char **argv)
{
    cout<<"usage: ./fstream filename"<<endl;
    ifstream fin(argv[1]);
    string line;
    while(getline(fin, line))
    {
        cout<<"origin string:"<<line<<endl;
        //将整行字符串读入字符串流
        istringstream sin(line);
        vector<string> res;
        string field;
        //以 ，分割
        while(getline(sin, field, ','))
        {
            res.push_back(field);
        }
        string name=trim(res[0]);
        int value=strtoint(trim(res[1]));
    }
}