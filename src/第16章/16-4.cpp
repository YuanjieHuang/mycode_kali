　　template <class elemType>
　　class linkList {
　　private:
　　    struct Node {
　　        elemType  data;
　　        Node  *next;
　　
　　        Node(const elemType &x, Node  *N = NULL) { data = x; next = N;}
　　        Node():next(NULL) {}
　　    ～Node() {}
　　    };
　　
　　    Node  *head; 
　　    void makeEmpty();
　　
　　public:
　　    linkList()   { head = new Node;   }
　　    ～linkList()  { makeEmpty();  delete head;}
　　    class Itr {
　　    private:  Node  *current; //用指向Node的指针表示对象位置
　　    public:
　　        Itr(Node *p) {current = p;}
　　        bool operator()() const  { return current != NULL; }
　　        bool isHead() const {return current == head;}
　　        const elemType &operator*() const {return current->data;}
　　        void operator++() {current = current->next; }
　　
　　        friend class linkList<elemType>;
　　    }; 
　　
　　    void insert(Itr &p, const elemType &x) 
　　    {   p.current->next = new node(x, p.current->next);
　　        p.current = p.current->next; 
　　    }
　　    void erase(Itr &p) 
　　    {   Node  *q = p.current->next;
　　        if (!q) return;
　　        p.current->next = q->next; delete q;
　　    }
　　    Itr begin() {return Itr(head->next);}
　　    Itr GetHead() {return Itr(head);}
　　};
　　
