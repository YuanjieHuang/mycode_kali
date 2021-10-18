package test;
public class TreeNode implements Comparable 
{
/** �ڵ�id*/
private String id;
/** �ı�����*/
private String text;
/** ���ڵ�id*/
private String parentId;
/** ˳���, ���ڽڵ�����*/
private int order;
/** �ڵ��Ƿ��, Ĭ��Ϊfalse*/
private boolean open = false;
/** attachInfo����Ψһ*/
private String attachInfo;
@Override
public int compareTo(Object obj) 
{
TreeNode treeNode= (TreeNode) obj;
return (this.order - treeNode.order);
}
/**
* ���캯��
*
* @param id �ڵ�id
* @param text �ı�����
* @param parentId ���ڵ�id
* @param order ˳���
* @param open �Ƿ�򿪽ڵ�,Ĭ��Ϊfalse
* @param attachInfo ������Ϣ, ����Ψһ
*/
public TreeNode(String id, String text, String parentId, int order, boolean open, String attachInfo) 
{
this.id = id;
this.text = text;
this.parentId = parentId;
this.order = order;
this.open = open;
this.attachInfo = attachInfo;
}
public String getId() {
return id;
}
public void setId(String id) {
this.id = id;
}
public String getText() {
return text;
}
public void setText(String text) {
this.text = text;
}
public String getParentId() {
return parentId;
}
public void setParentId(String parentId) {
this.parentId = parentId;
}
public int getOrder() {
return order;
}
public void setOrder(int order) {
this.order = order;
}
public boolean isOpen() {
return open;
}
public void setOpen(boolean open) {
this.open = open;
}
public String getAttachInfo() {
return attachInfo;
}
public void setAttachInfo(String attachInfo) {
this.attachInfo = attachInfo;
}
@Override
public int hashCode() {
final int prime = 31;
int result = 1;
result = prime * result + ((id == null) ? 0 : id.hashCode());
return result;
}
@Override
public boolean equals(Object obj) {
if (this == obj)
return true;
if (obj == null)
return false;
if (getClass() != obj.getClass())
return false;
TreeNode other = (TreeNode) obj;
if (id == null) {
if (other.id != null)
return false;
} else if (!id.equals(other.id))
return false;
return true;
}
}



