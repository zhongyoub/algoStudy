/*
一个平面上有n个点，求最多有多少个点在同一条直线上
*/

/*
解
取两点构成直线，然后计算他们的斜率，然后遍历其他的点，计算与前面一点的斜率是否相同，需要解决斜率精度问题
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
计算最大公约数
*/
int gcd(int a, int b)
{
    if(b==0)
        return a;
    else 
        return gcd(b, a%b);
}


struct Point{
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int a,int b):x(a),y(b){}
};

int maxPoints(vector<Point>& points)
{
    int count=0;
    for(int i=0;i<pints.size();i++)
    {
        //固定points[i],遍历其他点，记录不同斜率个数
        map<pair<int, int>, int> m;
        int cnt=0;
        int samePointCnt=0;
        for(int j=i+1;j<points.size();j++)
        {
            if(points[j].x==points[i].x && points[j].y==points[i].y)
                ++samePointCnt;
            else
            {
                int diffx=points[i].x-points[j].x;
                int diify=points[i].y-points[j].y;
                int g=gcd(diffy, diffx);
                diffx/=g;
                diffy/g;
                //添加到map
                cnt=max(cnt, ++m[make_pair(diffx, diffy)]);
            }
        }
        count =max(count,cnt+samePointCnt+1)；
    }   
    return count;
}