// ********************************************************// Header file QueueL.h for the ADT queue.// ADT list implementation.// ********************************************************#include "ListP.h"  //  ADT list operations#include "QueueException.h"typedef ListItemType QueueItemType;class Queue{public:// constructors and destructor:   Queue();                     // default constructor   Queue(const Queue& Q);       // copy constructor   ~Queue();                    // destructor// Queue operations:   bool isEmpty() const;   void enqueue(QueueItemType newItem)          throw(QueueException);   void dequeue() throw(QueueException);   void dequeue(QueueItemType& queueFront)          throw(QueueException);   void getFront(QueueItemType& queueFront) const          throw(QueueException);private:   List aList;  // list of queue items};  // end queue class// End of header file.