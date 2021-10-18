package test;
public class ManyTreeNode 
{
/** 树节点*/
private TreeNode data;
/** 子树集合*/
private List childList; 
/** 
* 构造函数 
* 
* @param data 树节点 
*/ 
public ManyTreeNode(TreeNode data) 
{ 
this.data = data; 
this.childList = new ArrayList (); 
} 
/** 
* 构造函数 
* 
* @param data 树节点 
* @param childList 子树集合 
*/ 
public ManyTreeNode(TreeNode data, List childList) 
{ 
this.data = data; 
this.childList = childList; 
} 
public TreeNode getData() { 
return data; 
} 
public void setData(TreeNode data) { 
this.data = data; 
} 
public List getChildList() { 
return childList; 
} 
public void setChildList(List childList) { 
this.childList = childList; 
} 
} 