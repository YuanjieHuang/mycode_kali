package test;
public class ManyTreeNode 
{
/** ���ڵ�*/
private TreeNode data;
/** ��������*/
private List childList; 
/** 
* ���캯�� 
* 
* @param data ���ڵ� 
*/ 
public ManyTreeNode(TreeNode data) 
{ 
this.data = data; 
this.childList = new ArrayList (); 
} 
/** 
* ���캯�� 
* 
* @param data ���ڵ� 
* @param childList �������� 
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