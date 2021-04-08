# import pickle
# myList=[1,2,3,"sunck is a good man"]
# path=r"D:\day5.txt"
# f=open(path, "wb")
# pickle.dump(myList, f)
# f.close()
#
# # 读取
# f1=open(path, "rb")
# tempList=pickle.load(f1)
# print(tempList)
# f1.close()

import os
# print(os.name)# nt->windows posix->Linux\Unix\Mac OS X
# print(os.uname)
# print(os.environ)
# print(os.environ.get())
# print(os.curdir)
# print(os.getcwd)
# print(os.listdir(r"D:\"))
# os.mkdir("huang")
# os.rmdir("huang")
# print(os.stat("huang"))
# os.rename()
# os.remove("d:\day5.txt")
# os.system("notepad")#运行shell命令
# os.system("write")
# os.system("mspaint")
# os.system("msconfig")
# os.system("taskkill /f /im notepad.exe")
# print(os.path.abspath("."))
import win32con
import win32gui
#找出窗体
QQWin=win32gui.FindWindow("TXGuiFoundation","QQ")
#隐藏窗体
win32gui.ShowWindow(QQWin,win32con.SW_HIDE)
#显示窗体
win32gui.ShowWindow(QQWin,win32con.SW_SHOW)

import win32com.client
dehua=win32com.client.Dispatch("SAPI.SPVOICE")
dehua.Speak("sunck")