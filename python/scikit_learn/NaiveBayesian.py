#鸢尾花数据集
from sklearn.datasets import load_iris
#导入朴素贝叶斯模型，这里选用高斯分类器
from sklearn.naive_bayes import GaussianNB
#载入数据集
X,y=load_iris(return_X_y=True)
bayes_modle=GaussianNB()
#训练数据
bayes_modle.fit(X,y)
#使用模型进行分类预测
result=bayes_modle.predict(X)
print(result)
#对模型评分
model_score=bayes_modle.score(X,y)
print(model_score)