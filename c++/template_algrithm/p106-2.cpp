template <class T>
GLNode<T>* GenList::Copy(GLNode<T>  * ls) {
    GLNode<T> *q = NULL;
    if (ls != NULL) {
        q = new GLNode<T> (ls->tag, NULL);
        q->tag = ls->tag;
        if  (ls->tag == 0) q->data = ls->data;
        else { 
            q-> hp = Copy(ls->hp);          
            q-> tp = Copy(ls->tp);
        }
    }
    return q;
}
