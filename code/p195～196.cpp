template<class T> 
void Tree<T>::PreOrder() 
{ 
    if (!IsEmpty()) { 
        visit(); 						//访问当前结点 
        TreeNode<T>*p = current;  		//保存当前结点 
        int k = FirstChild();         	//将当前结点定位到它的第一个子结点 
        //先根遍历当前结点的诸子树 
        while(k) { 
            PreOrder(); 
            k = NextBrother(); 
        } 
        current = p; //恢复当前指针 
    } 
}
