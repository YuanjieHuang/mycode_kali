template <class Object>
class CursorListItr;     

template <class Object>
class CursorList { 
public:
    CursorList();
    CursorList(const CursorList & rhs);
    ~CursorList();

    bool isEmpty() const;
    void makeEmpty();
    CursorListItr<Object> first() const;
    void insert(const Object & x, const CursorListItr<Object> & p);
    CursorListItr<Object> find(const Object & x) const;
    CursorListItr<Object> findPrevious(const Object & x) const;
    void remove(const Object & x);
public:
    struct CursorNode {
        CursorNode() : next(0) {}
    private:
        CursorNode(const Object & theElement, int n)
                   :element(theElement), next(n) {}

        Object element;
        int next;

        friend class CursorList<Object>;
        friend class CursorListItr<Object>;
    };
private:
    int header;

    static vector<CursorNode> cursorSpace;

    static void initializeCursorSpace();
    static int alloc();
    static void free(int p);

    friend class CursorListItr<Object>;
};

//CursorListItr类：维护 "当前位置"
template <class Object>
class CursorListItr {
public:
    CursorListItr() : current(0) {}
    bool isPastEnd() const
    { return current == 0; }
    void advance()
    { 
        if (!isPastEnd())
            current = CursorList<Object>::cursorSpace[current].next; 
    }
    const Object & retrieve() const
    { 
        if (isPastEnd()) throw BadIterator();
        return CursorList<Object>::cursorSpace[current].element; 
    }
private:
    int current;       //当前位置
    friend class CursorList<Object>;

    CursorListItr(int theNode) : current(theNode) { }
};
#endif

