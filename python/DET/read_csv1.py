import csv
import numpy as np
from matplotlib import pyplot as plt

#read csv file


filename='out~snc01.csv'
#打开文件并将结果文件对象存储在f中
with open(filename) as f:
    #创建一个与该文件相关联的reader对象
    reader=csv.reader(f)
    #只调用一次next()方法，得到文件的第一行，将第一行数据中的每一个元素存储在列表中
    header_row=next(reader)
#    print(header_row)

#打印文件头及其位置
#    for index,column_header in enumerate(header_row):
#        print(index,column_header)

#从文件中获取第二列的值（该列表示最高气温）
    p280s,p180s,p345s,times=[],[],[],[]
    #遍历文件中余下的各行
    #reader对象从其当前所在的位置继续读取CSV文件，每次都自动返回当前所处位置的下一行
    for row in reader:
        #转换为数字，便于后面让matplotlib能够读取它们
        p280=float(row[5])
        p280s.append(p280)
        time=float(row[2])
        times.append(time)
        p180=float(row[6])
        p180s.append(p180)
        p345=float(row[7])
        p345s.append(p345)

fig=plt.figure()
plt.plot(times,p280s)
#plt.title("voidg_345010000",fontsize=16)
#plt.xlabel('time',fontsize=16)
#plt.ylabel('gas percentage',fontsize=16)
#plt.tick_params(axis='both',which='major',labelsize=16)
plt.show()
