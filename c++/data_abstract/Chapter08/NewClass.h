#include <iostream>using namespace std;template <class T>class NewClass{public:   NewClass();   NewClass(T initialData);   void setData(T newData);   T getData();   void display();private:   T theData;}; // end classtemplate <class T>NewClass<T>::NewClass(){} // end default constructortemplate <class T>NewClass<T>::NewClass(T initialData)                     : theData(initialData){} // end constructortemplate <class T>void NewClass<T>::setData(T newData){   theData = newData;} // end setDatatemplate <class T>T NewClass<T>::getData(){   return theData;} // end getDatatemplate <class T>void NewClass<T>::display(){   cout << theData;} // end display