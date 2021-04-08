class Node:
 def __init__(self, nodeidex='0', t=0, waterlever=0.0, pro=0.0, \
              k1state=1, k2state=0, k3state=1, isk1ok=True, isk2ok=True, isk3ok=True):
  self.nodeidex = nodeidex
  self.t = t
  self.__waterlever = waterlever
  self.__pro = pro
  self.__k1state = k1state
  self.__k2state = k2state
  self.__k3state = k3state
  self.__isk1ok = isk1ok
  self.__isk2ok = isk1ok
  self.__isk3ok = isk1ok

 def get_nodeindex(self):
  return nodeindex

 def set_nodeindex(self, nodeindex):
  self.nodeidex = nodeindex

 nodeindex = property(get_nodeindex, set_nodeindex)

 def __str__(self):
  return 'nodeidex={0}\t,t={1}\t,waterlever={2}\t,pro={3}\t,k1state={4}\t,k2state={5}\t,k3state={6}\t,isk1ok={7}\t,isk2ok={8}\t,isk3ok={9}\n'.format(
   self.nodeidex, self.t, self.__waterlever, self.__pro, \
   self.__k1state, self.__k2state, self.__k3state, self.__isk1ok, \
   self.__isk2ok, self.__isk3ok)

# f = open("d:/a.txt", "w")
# # str=f.readlines()
# # f.tell()
# # for line in f:
# #     print(line, end='')
node=Node()
list1 =(node)
# list1.append(node)


# list2 = []
# for x in list2:

def fun0(list1):
 node = list1[0]
 node.nodeidex = node.nodeidex + '0'
 print(node)
 # f.write(node)
 list1.append(node)
 # return list1


def fun1(list1):
 node = list1[0]
 node.nodeidex = node.nodeidex + '1'
 print(node)
 # list1.append(node)
 # return list1


def fun2(node, list1):
 node.nodeidex = node.nodeidex + '2'
 print(node)
 # list1.append(node)
 return list1


def fun3(node, list1):
 node.nodeidex = node.nodeidex + '3'
 print(node)
 list1.append(node)
 return list1


fun0(list1)
fun1(list1)
# fun2(node)
# fun3(node)

# for i in list1:
#  print(i)
 # list2 = list1
 # list1.clear()
