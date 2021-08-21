按层次次序遍历以当前结点为根的树, 利用一个辅助队列 
templateclass T 
void TreeTLevelOrder() 
{ 
    Queue q; 
    if (!IsEmpty()) {  若树不为空树, 开始树的层次遍历 
        TreeNode p = current ; 	保存当前结点   
        q.QInsert(current);  		当前结点入队 
        while (!q.QEmpty()) { 
            current = q.QDelete(); 	出队一个结点, 设为当前结点
            visit(); 访问当前结点 
            FirstChild(); 
            将当前结点的所有子结点入队 
            while (!IsEmpty()) { 
                q.QInsert(current); 
                NextBrother(); 
            } 
        }       
        current = p; 恢复当前结点 
    }
} 
