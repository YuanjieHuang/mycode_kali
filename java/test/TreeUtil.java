package test;

import java.util.*;

public final class TreeUtil 
{ 
private TreeUtil(){} 
public static ManyNodeTree createTree(Set treeNodes) 
{ 
return createTree("root","���ڵ�", treeNodes); 
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
//ɾ����ӳɹ��Ľڵ� 
queue.remove(); 
} 
else 
{ 
//�����ʧ�ܵĽڵ����·���ڵ���еĶ�β 
queue.remove(); 
queue.add(treeNode); 
} 
} 
return manyNodeTree; 
} 
private static boolean addChild(ManyTreeNode manyTreeNode, TreeNode treeNode) 
{ 
//����ӵĽڵ��ǵ�ǰ�ڵ�ĺ��� 
if(manyTreeNode.getData().getId().equals(treeNode.getParentId())) 
{ 
//��ӽڵ㵽��ǰ�ڵ� 
manyTreeNode.getChildList().add(new ManyTreeNode(treeNode)); 
return true; 
} 
else//����ӽڵ㲻�ǵ�ǰ�ڵ�ĺ��� 
{ 
//�鿴����ӵĽڵ��Ƿ��ǵ�ǰ�ڵ㺢�ӵĺ��� 
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
* ����XML�����ļ� 
* 
* @param manyNodeTree ����� 
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