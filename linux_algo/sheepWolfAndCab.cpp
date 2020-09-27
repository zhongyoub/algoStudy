/*
农夫过河问题：农夫需要把狼、羊、菜和自己运到河对岸去，只有农夫能够划船，而且船比较小，
除农夫之外每次只能运一种东西，还有一个棘手问题，就是如果没有农夫看着，羊会偷吃菜，狼会吃羊。
请考虑一种方法，让农夫能够安全地安排这些东西和他自己过河。
*/

/*
使用1和0表示过河和没过河
菜，狼，羊，人四者之间的状态：0000，1000，0100，0010，1100，1111，0111，1011，1101，0011
*/

#include<iostream>
#include<vector>
#include <string>
#include<queue>
#include<stack>
using namespace std;

struct Node {
    string status; //菜，狼，羊，人的状态，A岸=0,B岸=1，例如初始状态“0000”
    int way;       // 初始状态-1， 0-3分别表示带菜，狼，羊，不带
    int father;
    Node(stirng s, int w, int f): status(s), way(w), father(f){}
};

vector<Node> nodes;
// S[] 表示四者是在哪边
string S[10]={"0000","1000","0100","0010","1100","1111","0111","1011","1101","0011"};
const string S_NULL="";

string crossRiver(string status, int way)
{
    if(way==3){      //不带
        status[3]='1'-status[3]+'0';     //从一边到另一边
    }
    else if(status[way]!=status[3])     //要带的和自己不在一边的肯定不能带
        return S_NULL;
    else status[way]='1'-staus[3]+'0';

    //  如果是合法的状态，则可以
    for(int i=0;i<10;i++)
    {
        if(status==S[i])
            return status;
    }
    return S_NULL;
}

int BFS()
{
    nodes.push_back(Node("0000",-1,-1));
    int idx=0;
    while(true)
    {
        Node node=nodes[idx];
        string status=node.status;
        //都到另一边
        if(status=="1111")
            return idx;
        //选择三种方式
        for(int i=0;i<4;i++)
        {
            string t=status;
            if((t=crossRiver(status, i))!=S_NULL)
                nodes.push_back(Node(t, i, idx));
        }
        idx++;
    }
}

void print(stack<int> s)
{
    while(!s.empty())
    {
       int way, status;
        way = nodes[s.top()].way;
        status = nodes[s.top()].status[3] - '0';
        s.pop();
        switch (way) {
            case 0: printf("vegetable_"); break;
            case 1: printf("wolf_"); break;
            case 2: printf("sheep_"); break;
            case 3: printf("nothing_"); break;
        }
        if (status == 1) {
            printf("go\n");
        }
        else {
            printf("come\n");
        }
    }
    printf("succeed\n");
}

int main(){
    int ret = BFS();
    stack<int> s;
    s.push(ret);
    //ret 是成功时的最后一个结点
    while (nodes[ret].father != 0) {
        ret = nodes[ret].father;
        s.push(ret);
    }
    Print(s);
    return 0;
}
