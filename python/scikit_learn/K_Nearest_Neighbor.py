#加载红酒数据集
from sklearn.datasets import load_wine
#KNN分类算法
from sklearn.neighbors import KNeighborsClassifier
#分割训练集与测试集
from sklearn.model_selection import train_test_split
#导入numpy
import numpy as np
#加载数据集
wine_dataset=load_wine()
#查看数据集对应的键
print("红酒数据集的键:\n{}".format(wine_dataset.keys()))
print("数据集描述:\n{}".format(wine_dataset['data'].shape))
# data 为数据集数据;target 为样本标签
#分割数据集，比例为 训练集：测试集 = 8:2
X_train,X_test,y_train,y_test=train_test_split(wine_dataset['data'],wine_dataset['target'],test_size=0.2,random_state=0)
#构建knn分类模型，并指定 k 值
KNN=KNeighborsClassifier(n_neighbors=10)
#使用训练集训练模型
KNN.fit(X_train,y_train)
#评估模型的得分
score=KNN.score(X_test,y_test)
print(score)
#给出一组数据对酒进行分类
X_wine_test=np.array([[11.8,4.39,2.39,29,82,2.86,3.53,0.21,2.85,2.8,.75,3.78,490]])
predict_result=KNN.predict(X_wine_test)
print(predict_result)
print("分类结果：{}".format(wine_dataset['target_names'][predict_result]))