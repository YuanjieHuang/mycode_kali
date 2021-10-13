#logistic算法
#从 scikit-learn库导入线性模型中的logistic回归算法
from sklearn.linear_model import LogisticRegression
#导入sklearn 中的自带数据集 鸢尾花数据集
from sklearn.datasets import load_iris
# skleran 提供的分割数据集的方法
from sklearn.model_selection import train_test_split
#载入鸢尾花数据集
iris_dataset=load_iris()
# data 数组的每一行对应一朵花，列代表每朵花的四个测量数据，分别是：花瓣的长度，宽度，花萼的长度、宽度
print("data数组类型: {}".format(type(iris_dataset['data'])))
# 前五朵花的数据
print("前五朵花数据:\n{}".format(iris_dataset['data'][:5]))
#分割数据集训练集，测试集
X_train,X_test,Y_train,Y_test=train_test_split(iris_dataset['data'],iris_dataset['target'],random_state=0)
#训练模型
#设置最大迭代次数为3000，默认为1000.不更改会出现警告提示
log_reg = LogisticRegression(max_iter=3000)
#给模型喂入数据
clm=log_reg.fit(X_train,Y_train)
#使用模型对测试集分类预测,并打印分类结果
print(clm.predict(X_test))
#最后使用性能评估器，测试模型优良，用测试集对模型进行评分
print(clm.score(X_test,Y_test))