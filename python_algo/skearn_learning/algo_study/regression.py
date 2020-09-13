'''
广义线性模型
y=w_0+w_1*x_1+w_2*x_2...w_p*x_p
'''

from sklearn import linear_model
import numpy as np

'''
最小二乘法
'''
def  test1():
    reg=linear_model.LinearRegression()
    reg.fit([[0,0],[1,1],[2,2]],[0,1,2])
    linear_model.LinearRegression(copy_X=True, fit_intercept=True, n_jobs=1, normalize=False)
    print(reg.intercept_)      # w_0
    print(reg.coef_)           # w_1, w_2


'''
岭回归
'''
def test2():
    reg=linear_model.Ridge(alpha=0.5)
    reg.fit([[0,0],[0,0],[1,1]],[0,.1,1])
    linear_model.Ridge(alpha=0.5, copy_X=True, fit_intercept=True, max_iter=None,
    normalize=False, random_state=None, solver='auto', tol=0.001)
    print(reg.intercept_)    
    print(reg.coef_)   


def test3():
    a=np.arange(1,11)
    print(a)
    b=a[2:np.newaxis]    #此处的np.newaxis是数组的长度
    print(b.shape)       #shape用于查看数组或矩阵的维数
    b=a[:,np.newaxis]    #相当于转置
    print(b,b.shape)
    c=np.logspace(0,10,10)  #创建等比例的数组，开始为0,结束点为10,0个
    print(c)

   # print(np.logspace(-10,2,10))  #

'''
广义交叉验证:RigdgeCV通过内置的关于alpha参数的交叉验证来实现岭回归
默认为留一验证法
'''
def test4():
    reg=linear_model.RidgeCV(alphas=[0.1,1.0,10.0])
    reg.fit([[0,0],[0,0],[1,1]],[0,.1,1])
    '''
    linear_model.RidgeCV(alphas=[0.1,1.0,10.0],cv=None, fit_intercept=True,
    scoring=None,normalize=False)
    '''
    print(reg.alpha_)
    
'''
Lasso:拟合稀疏稀疏的线性模型,倾向使用具有较少参数值的i情况
有效地减少给定解决方案所依赖变量的数量
'''
def test5():
    reg=linear_model.Lasso(alpha=0.1)
    reg.fit([[0,0],[1,1]],[0,1])
    '''
    linear_model.Lasso(alpha=0.1,copy_X=True, fit_intercept=True,
    normalize=False,positive=False,precompute=False,
    random_state=None,selection='cyclic',tol=0.0001,warm_start=False)
    '''
    print(reg.predict([[1,1]]))

'''
Lasso 交叉验证：通过设置LassoCV 和LassoLarsCV的alpha参数
'''
def test6():
    reg=linear_model.LassoCV(alphas=[0.1,1.0,10.0])
    reg.fit([[0,0],[3,3],[1,1]],[0,2,1])
    '''
    linear_model.RidgeCV(alphas=[0.1,1.0,10.0],cv=None, fit_intercept=True,
    scoring=None,normalize=False)
    '''
    print(reg.coef_)

'''
设置MultiTaskElasticNetCV,实现多折交叉验证
'''
def test7():
    from sklearn import linear_model
    clf=linear_model.MultiTaskElasticNetCV(cv=3)
    dataset_x=[[0,0], [1,1], [2,2]]
    dataset_y=[[0,0],[1,1],[2,3]]
    clf.fit(dataset_x, dataset_y)
    w_list=clf.coef_
    c_list=clf.intercept_
    print(w_list)
    print(c_list)

'''
LassLars是一个使用最小角回归(LARS)算法的lasso模型
'''
def  test8():
    from sklearn import linear_model
    reg=linear_model.LassoLars(alpha=0.1)
    reg.fit([[0,0],[1,1]],[0,1])
    print(reg.coef_)

if __name__=="__main__":
    #test6()
    #test7()
    test8()
    