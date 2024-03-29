/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include "objectcounter.hpp"
#include <iostream>

template <typename CharT>
class MyString : public ObjectCounter<MyString<CharT> > {
  //...
};

int main()
{
    MyString<char> s1, s2;
    MyString<wchar_t> ws;

    std::cout << "number of MyString<char>:    " 
              << MyString<char>::live() << std::endl;
    std::cout << "number of MyString<wchar_t>: " 
              << MyString<wchar_t>::live() << std::endl;
}
