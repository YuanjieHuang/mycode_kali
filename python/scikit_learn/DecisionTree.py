# 加载红酒数据集
from sklearn.datasets import load_wine
# 导入决策树分类器
from sklearn.tree import DecisionTreeClassifier
# 导入分割数据集的方法
from sklearn.model_selection import train_test_split
# 导入科学计算包
import numpy as np
# 加载红酒数据集
wine_dataset=load_wine()
# 分割训练集与测试集
X_train,X_test,y_train,y_test=train_test_split(wine_dataset['data'],wine_dataset['target'],test_size=0.2,random_state=0)
# 创建决策时分类器--ID3算法
tree_model=DecisionTreeClassifier(criterion="entropy")
# 喂入数据
tree_model.fit(X_train,y_train)
# 打印模型评分
print(tree_model.score(X_test,y_test))
# 给出一组数据预测分类
X_wine_test=np.array([[11.8,4.39,2.39,29,82,2.86,3.53,0.21,2.85,2.8,.75,3.78,490]])
predict_result=tree_model.predict(X_wine_test)
print(predict_result)
print("分类结果：{}".format(wine_dataset['target_names'][predict_result]))