//中序遍历二叉树T, 并对其进行中序线索化 
template <class T>
ThreadBinaryTreeNode <T>*  InOrderThreading(ThreadBinaryTreeNode <T>* T) 
{

    ThreadBinaryTreeNode <T>* Thrt; 			//Thrt指向线索化之后的头结点
    Thrt = GetThrNode('', Link, Thread);   		//建头结点
    Thrt->AssignRight(Thrt);  					//右指针回指
    if (T == NULL)  Thrt->AssignLeft(Thrt);   	//若二叉树空, 则左指针回指
    else {
        Thrt->AssignLeft(T);   pre = Thrt;
        InThread(T, pre); 						//中序遍历进行中序线索化
        pre->AssignRight(Thrt);  
        pre->AssignRTag(Thread);
        Thrt->AssignRight(pre);  				//最后一个结点线索化
    }
    return Thrt;
} 
