#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std; 



// struct that behaves as a unary function
template <typename elementType>
struct DisplayElement
{
    void operator () (const elementType& element) const
    {
        cout << element << ' ';
    }
};

int unary_pradicate ()
{
    vector <int> vecIntegers;

    for (int nCount = 0; nCount < 10; ++ nCount)
        vecIntegers.push_back (nCount);

    list<char> listChars;
    for (char nChar = 'a'; nChar < 'k'; ++nChar)
        listChars.push_back (nChar);

    cout << "Displaying the vector of integers: " << endl;

    // Display the array of integers
    for_each ( vecIntegers.begin ()    // Start of range
          , vecIntegers.end ()        // End of range
          , DisplayElement <int> () ); // Unary function object

    cout << endl << endl;
    cout << "Displaying the list of characters: " << endl;

    // Display the list of characters
    for_each ( listChars.begin ()        // Start of range
          , listChars.end ()        // End of range
          , DisplayElement <char> () );// Unary function object
        //   第3个指定对范围类的每个元素调用的函数，如对vector调用DispalyElement::operate(). 

    return 0;
}

template<typename elementType>
struct DisplayElementKeepCount
{
   int Count;

   // Constructor
   DisplayElementKeepCount() : Count(0) {}

   // Display the element, hold count!
   void operator()(const elementType& element)
   {
      ++ Count;
      cout << element<< ' ';
   }
};

int unary_predicate_nonconst()
{
   vector<int> vecIntegers;
   for(int nCount = 0; nCount< 10; ++ nCount)
      vecIntegers.push_back(nCount);

   cout << "Displaying the vector of integers: "<< endl; 

   // Display the array of integers
   DisplayElementKeepCount<int> Result;
   Result = for_each( vecIntegers.begin()   // Start of range
                     , vecIntegers.end()        // End of range
                    // ,Result); //也可以用这行代替下一行
     , DisplayElementKeepCount<int>() );// function object

   cout << endl<< endl;

   // Use the state stores in the return value of for_each!
   cout << "'"<< Result.Count<< "' elements were displayed!"<< endl;

   return 0;
}

template <typename numberType>
struct IsMultiple
{
   numberType Divisor;

   IsMultiple (const numberType& divisor)
   {
      Divisor = divisor;
   }

   bool operator () (const numberType& element) const
   {
      // Check if the dividend is a multiple of the divisor
      return ((element % Divisor) == 0);
   }
};

int my_find_if ()
{
   vector <int> vecIntegers;
   cout << "The vector contains the following sample values: ";

   // Insert sample values: 25 - 31
   for (int nCount = 25; nCount < 32; ++ nCount)
   {
      vecIntegers.push_back (nCount);
      cout << nCount << ' ';
   }
   cout << endl << "Enter divisor (> 0): ";
   int Divisor = 2;
   cin >> Divisor;

   // Find the first element that is a multiple of 4 in the collection
   auto iElement = find_if ( vecIntegers.begin ()
                      , vecIntegers.end ()
                      , IsMultiple<int>(Divisor) );  

   if (iElement != vecIntegers.end ())
   {
      cout << "First element in vector divisible by " << Divisor;
      cout << ": " << *iElement << endl;
    }

   return 0;
}
int main()
{
    unary_pradicate ();
    unary_predicate_nonconst();
    return 0;
}

#if 0
#include <algorithm>
#include <string>
using namespace std;




class CompareStringNoCase
{
public:
   bool operator () (const string& str1, const string& str2) const
   {
     string str1LowerCase;
     // Assign space
     str1LowerCase.resize (str1.size ());
     // Convert every character to the lower case
     transform (str1.begin (), str1.end (), str1LowerCase.begin (), tolower);

     string str2LowerCase;
     str2LowerCase.resize (str2.size ());
     transform (str2.begin (), str2.end (), str2LowerCase.begin (), tolower);

     return (str1LowerCase < str2LowerCase);
   }
};

#include <vector>
#include <iostream>

template <typename T>
void DisplayContents (const T& Input)
{
   for(auto iElement = Input.cbegin() // auto, cbegin and cend: c++11 
      ; iElement != Input.cend ()
      ; ++ iElement )
      cout << *iElement << endl;
}

int main ()
{
   // Define a vector of string to hold names
   vector <string> vecNames;

   // Insert some sample names in to the vector
   vecNames.push_back ("jim");
   vecNames.push_back ("Jack");
   vecNames.push_back ("Sam");
   vecNames.push_back ("Anna");

   cout << "The names in vector in order of insertion: " << endl;
   DisplayContents(vecNames);

   cout << "Names after sorting using default std::less<>: " << endl;
   sort(vecNames.begin(), vecNames.end());
   DisplayContents(vecNames);

   cout << "Names after sorting using predicate that ignores case:" << endl;
   sort(vecNames.begin(), vecNames.end(), CompareStringNoCase());
   DisplayContents(vecNames);

   return 0;
}
#endif