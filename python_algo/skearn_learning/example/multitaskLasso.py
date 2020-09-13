'''
多任务稀疏的联合特征选择
'''
import matplotlib.pyplot as plt
import numpy as np

from sklearn.linear_model import MultiTaskLasso, Lasso

rng = np.random.RandomState(42)

# Generate some 2D coefficients with sine waves with random frequency and phase
n_samples, n_features, n_tasks = 100, 30, 40
n_relevant_features = 5
coef = np.zeros((n_tasks, n_features))       # 40*30 
print(coef.shape) 
times = np.linspace(0, 2 * np.pi, n_tasks) 
for k in range(n_relevant_features):
    coef[:, k] = np.sin((1. + rng.randn(1)) * times + 3 * rng.randn(1))

#print(coef.T)  # coef.T 转置矩阵

X = rng.randn(n_samples, n_features)      # 100*30


Y = np.dot(X, coef.T) + rng.randn(n_samples, n_tasks)        #f(x)= coef *X +random()

coef_lasso_ = np.array([Lasso(alpha=0.5).fit(X, y).coef_ for y in Y.T])
coef_multi_task_lasso_ = MultiTaskLasso(alpha=1.).fit(X, Y).coef_

# #############################################################################
# Plot support and time series
fig = plt.figure(figsize=(8, 5))
plt.subplot(1, 2, 1)
plt.spy(coef_lasso_)
plt.xlabel('Feature')
plt.ylabel('Time (or Task)')
plt.text(10, 5, 'Lasso')
plt.subplot(1, 2, 2)
plt.spy(coef_multi_task_lasso_)
plt.xlabel('Feature')
plt.ylabel('Time (or Task)')
plt.text(10, 5, 'MultiTaskLasso')
fig.suptitle('Coefficient non-zero location')

feature_to_plot = 0
plt.figure()
lw = 2
plt.plot(coef[:, feature_to_plot], color='seagreen', linewidth=lw, label='Ground truth')        #原始系数

plt.plot(coef_lasso_[:, feature_to_plot], color='cornflowerblue', linewidth=lw, label='Lasso')   #fit()结果

plt.plot(coef_multi_task_lasso_[:, feature_to_plot], color='gold', linewidth=lw, label='MultiTaskLasso')    #MultiTaskLasso()结果， 优于fit()

plt.legend(loc='upper center')
plt.axis('tight')
plt.ylim([-1.1, 1.1])
plt.show()