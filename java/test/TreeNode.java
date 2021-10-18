package test;
public class TreeNode implements Comparable 
{
/** 节点id*/
private String id;
/** 文本内容*/
private String text;
/** 父节点id*/
private String parentId;
/** 顺序号, 用于节点排序*/
private int order;
/** 节点是否打开, 默认为false*/
private boolean open = false;
/** attachInfo必须唯一*/
private String attachInfo;
@Override
public int compareTo(Object obj) 
{
TreeNode treeNode= (TreeNode) obj;
return (this.order - treeNode.order);
}
/**
* 构造函数
*
* @param id 节点id
* @param text 文本内容
* @param parentId 父节点id
* @param order 顺序号
* @param open 是否打开节点,默认为false
* @param attachInfo 附加信息, 必须唯一
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



