package test;

import java.util.*;

public final class TreeUtil 
{ 
private TreeUtil(){} 
public static ManyNodeTree createTree(Set treeNodes) 
{ 
return createTree("root","根节点", treeNodes); 
} 
public static ManyNodeTree createTree(String rootId, String rootName, Set treeNodes) 
{ 
if(treeNodes == null || treeNodes.isEmpty()) 
return null; 
Queue queue = new LinkedList (); 
ManyNodeTree manyNodeTree = new ManyNodeTree(rootId, rootName); 
for(TreeNode treeNode : treeNodes) 
{ 
queue.add(treeNode); 
} 
while(!queue.isEmpty()) 
{ 
TreeNode treeNode = queue.element(); 
boolean result = addChild(manyNodeTree.getRoot(), treeNode); 
if(result) 
{ 
//删除添加成功的节点 
queue.remove(); 
} 
else 
{ 
//将添加失败的节点重新放入节点队列的队尾 
queue.remove(); 
queue.add(treeNode); 
} 
} 
return manyNodeTree; 
} 
private static boolean addChild(ManyTreeNode manyTreeNode, TreeNode treeNode) 
{ 
//被添加的节点是当前节点的孩子 
if(manyTreeNode.getData().getId().equals(treeNode.getParentId())) 
{ 
//添加节点到当前节点 
manyTreeNode.getChildList().add(new ManyTreeNode(treeNode)); 
return true; 
} 
else//被添加节点不是当前节点的孩子 
{ 
//查看被添加的节点是否是当前节点孩子的孩子 
for(ManyTreeNode child : manyTreeNode.getChildList()) 
{ 
if(addChild(child, treeNode)) 
{ 
return true; 
} 
} 
return false; 
} 
} 
/** 
* XML 
* 
* @param manyTreeNode 
* @return 
*/ 
private static StringBuilder createXML(ManyTreeNode manyTreeNode) 
{ 
StringBuilder xml = new StringBuilder(); 
for (ManyTreeNode item : manyTreeNode.getChildList()) 
{ 
if(!item.getChildList().isEmpty()) 
{ 
xml.append(" "); 
xml.append(createXML(item)); 
xml.append(" "); 
} 
else 
{ 
xml.append(" "); 
} 
} 
return xml; 
} 
/** 
* 创建XML数据文件 
* 
* @param manyNodeTree 多叉树 
* @return 
*/ 
public static String createXML(ManyNodeTree manyNodeTree) 
{ 
StringBuilder xml = new StringBuilder(); 
xml.append("<?xml version='1.0' encoding='UTF-8'?> "); 
xml.append(createXML(manyNodeTree.getRoot())); 
xml.append(" "); 
return xml.toString(); 
} 
} 