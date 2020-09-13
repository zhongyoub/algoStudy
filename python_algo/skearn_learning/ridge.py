
'''
测试岭回归中aplha参数的影响
min||Wx-y||^ +alpha||w||^2

'''
from sklearn import linear_model
import numpy as np
from matplotlib import pyplot as plt

# X is the 10x10 Hilbert matrix  
x= 1. / (np.arange(1, 11) + np.arange(0, 10)[:, np.newaxis])   # 在np.newaxis位置增加一维
print(x)
y=np.ones(10)     


n_alphas=200
alphas=np.logspace(-10,2,n_alphas)     #创建等比数列
print(alphas)

coefs=[]
for a in alphas:
    ridge=linear_model.Ridge(alpha=a, fit_intercept=False)
    ridge.fit(x,y)
    coefs.append(ridge.coef_)

#display result
ax=plt.gca()
ax.plot(alphas,coefs)
ax.set_xscale('log')
ax.set_xlim(ax.get_xlim()[::-1])  # reverse axis
plt.xlabel('alpha')
plt.ylabel('weights')
plt.title('Ridge coefficients as a function of the regularization')
plt.axis('tight')
plt.show()
