package test;
public class ManyNodeTree 
{ 
/** ���ڵ�*/ 
private ManyTreeNode root; 
/** 
* ���캯�� 
* 
* @param rootId ������� 
* @param rootName ���ڵ����� 
*/ 
public ManyNodeTree(String rootId, String rootName) 
{ 
this.root = new ManyTreeNode(new TreeNode(rootId, rootName, null, -1, false, null)); 
} 
public ManyTreeNode getRoot() { 
return root; 
} 
} 