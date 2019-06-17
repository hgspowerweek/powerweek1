/*

compile the code with

g++ main.cpp hello_fn.cpp -o hello_world -Wall
 
*/

// include the header file with the definition of the hello function
#include "hello_fn.h"

int main()
{
  // the cout and endl commands resides in a so-called namespace
  // in order to use it globally we have to let the compiler know
  hello("world");
  return 0;
}

