#include <list>#include <iostream>#include <string>using namespace std;// define a list of pointer stringstypedef list<string*, allocator<string*> > STRING_PTR;// override the default behavior of sorttemplate<> struct std::greater<string*>{       // override operator() to create a function object        bool operator() (string* s1, string *s2)      {         return (*s1) > (*s2);      }};int main(){           // create a list of pointer strings and a list iterator      STRING_PTR groceryList;      STRING_PTR::iterator i;      // create pointers to strings in a random order      // insert the string pointers to the end of the list       string* str = new string ("apples");      groceryList.insert(groceryList.end(), str);      str = new string ("bread");      groceryList.insert(groceryList.end(), str);      str = new string ("juice");      groceryList.insert(groceryList.end(), str);      str = new string ("carrots");      groceryList.insert(groceryList.end(), str);      cout << "Number of items on my grocery list: "            << groceryList.size() << endl;      // sort with the overridden function object      groceryList.sort(greater<string*>());      // print out the list of strings      cout << "Items after the predicate sort are:" << endl;      i = groceryList.begin();      while (i != groceryList.end())      (   cout << (*(*i)).c_str() << endl;          i++;      }}