enum Tags{LEFT,RIGHT};
template <class T>
class StackElement { 
public:
    BinaryTreeNode<T> *pointer;
    Tags tag;
};
