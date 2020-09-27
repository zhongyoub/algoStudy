/*
24点游戏：输入4个0-9的整数，数字允许重复，但每个数字仅允许使用一次，通过加减乘除，得到值为m
输出：1表示可解，0表示不可解
*/

/*
解题思路：一个由4个数和3个运算符的运算，可以使用列表存储目前的全部数字，每次从列表中选择2个数字，在选择一种运算符
重复上述所有的步骤，直到列表中只剩下1个数字
（1）除法运算为实数除法，因此结果为浮点数，列表中存储的数字也是浮点数，判断结果是否为m时，应该考虑精度差，使用1e-6
（2）除法运算中，除数不能为0，判断除数是佛为0可以使用精度误差，当一个数字值的绝对值小时1e-6,则可以认为为0
*/
#include <iostream>
#include <vector>
using namespace std;

static const double EPSILON = 1e-6;
static const int ADD=0, MULTIPLY=1, SUBSTRACT=2, DIVIDE=3; 

bool judge(vector<int> & nums, int &object)
{
    vector<double> v;
    for(int &num: nums)
        v.emplace_back(num);           //emplace_back(): 类似push_back()
    return solve(v, object);
}
bool solve(vecotr<double> &vec1, int &object)
{
    if(vec1.size()==0)
        return false;
    if(vec1.size()==1)
        return fabs(vec1[0]-object)<EPSILON;
    int size=vec1.size();
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i!=j)
            {
                vector<double> vec2=vector<double>();
                for(int k=0;k<size;k++)
                {
                    if(k!=i && k!=j)
                        vec2.emplace_back(vec1[k]);
                }
                for(int k=0;k<4;k++)
                {
                    if(k<2 && i>j)
                        continue;
                    if(k==ADD)
                        vec2.emplace_back(vec1[i]+vec[j]);
                    else if(k==MULTIPLY)
                        vec2.emplace_back(vec1[i]*vec[j]);
                    else if(k==SUBSTRACT)
                        vec2.emplace_back(vec1[i]-vec[j]);
                    else if(k==DIVIDE)
                    {
                        if(fabs(vec1[j])<EPSILON)
                            continue;
                        vec2.emplace_back(vec1[i]/vec1[j]);
                    }
                    if(solve(vec2,object))
                        return true;
                    vec2.pop_back();
                }
            }
        }
    
    }
    return false;
}



