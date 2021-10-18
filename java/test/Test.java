public class Test 
{ 
	public static void main(String[] args) 
	{ 
	Set treeNodes = new TreeSet (new TreeNodeComparator()); 
	boolean open = false;treeNodes.add(new TreeNode("system","system","root", 101, open,"4")); 
	treeNodes.add(new TreeNode("test1","test1","test4", 102, open,"1")); 
	treeNodes.add(new TreeNode("test2","test2","test3", 103, open,"2")); 
	treeNodes.add(new TreeNode("test3","test3","system", 104, open,"3")); 
	treeNodes.add(new TreeNode("test4","test4","test3", 105, open,"5")); 
	treeNodes.add(new TreeNode("test5","test5","system", 106, open,"6"));System.out.println(treeNodes.size()); 
	try 
	{ 
	System.out.println(TreeUtil.createXML(TreeUtil.createTree(treeNodes))); 
	} 
	catch (Exception e) 
	{ 
	e.printStackTrace(); 
	} 
	} 
}
