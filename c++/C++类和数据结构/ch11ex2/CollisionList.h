// CollisionList.h -- class for a linked list as a data structuretemplate <class DataType>struct Node {	DataType info;	Node<DataType> *next;	Node<DataType> *dlnext;	Node<DataType> *dlback;};// CollisionList maintains a current position in list after each function call// If an object of a struct is used for DataType, the == operator must be // overloaded for it; the left and right operands are both DataType objects// the == comparison is used for finding elements, usually by key value// For find, retrieve and remove functions, if you are using an object as an element, a // typical use would be to set the key of the desired object to find or remove, then pass // the object into the function.// The constructor, copy constructor, overloaded assignment operator, and insert function// can throw an exception if out of heap memory.template <class DataType>class CollisionList{public:	CollisionList( );	CollisionList( const CollisionList<DataType> & aplist );	~CollisionList( );	CollisionList<DataType> & operator =( const CollisionList<DataType> & rlist );	void insert( const DataType & element ); // current position is inserted node	bool first( DataType & listEl );	  // returns first element of list in listEl										  // and current position is set to this element; 										  // if list is empty, returns false and there is										  // no current position; otherwise, returns true	inline bool getNext( DataType & listEl );	  // retrieves the next element of a linked list										  // beyond the last element that was retrieved										  // by first or getNext functions and returns										  // it in listEl;										  // current position is set to this element.										  // if no element exists at this position, 										  // getNext returns false and there is no 										  // current position; returns true otherwise		bool find ( const DataType & element );  // returns true if element is found									      // returns false if element is not found										  // if found, found element becomes current										  // position in list; if not found, there is										  // no current position	bool retrieve( DataType & element );  // like find, except returns found element	bool replace( const DataType & newElement ); // replaces element at current position 											   // in list with newElement; returns false if											  // there is no current position (no list 											// modification occurs); returns true otherwise 	bool remove( DataType & element );    // returns true if element is found										  // returns false if element is not found										  // if found, element is set to found element;										  // no current position after use	bool isEmpty( ) const;				  // returns true if linked list is empty										  // returns false otherwise; current position										  // unchanged	void makeEmpty( );					  // no current position	Node<DataType> *getcurrent( ) const;  // retrieves current pointerprivate:	Node<DataType> *start;	Node<DataType> *current;			  // points to node at current position		inline void deepCopy( const CollisionList<DataType> & original );};#include "CollisionList.cpp"