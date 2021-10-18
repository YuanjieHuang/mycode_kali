package test;
public class ManyNodeTree 
{ 
/** 根节点*/ 
private ManyTreeNode root; 
/** 
* 构造函数 
* 
* @param rootId 根结点编号 
* @param rootName 根节点名称 
*/ 
public ManyNodeTree(String rootId, String rootName) 
{ 
this.root = new ManyTreeNode(new TreeNode(rootId, rootName, null, -1, false, null)); 
} 
public ManyTreeNode getRoot() { 
return root; 
} 
} 