package test;

import java.util.Comparator;

public class TreeNodeComparator implements Comparator
{
@Override
public int compare(Object obj1, Object obj2)
{
TreeNode treeNode1 = (TreeNode) obj1;
TreeNode treeNode2 = (TreeNode) obj2;
return treeNode1.compareTo(treeNode2);
}
}