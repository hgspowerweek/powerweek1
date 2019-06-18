#include <iostream>
using std::cout;

void print(int *i) { std::cout << "integer pointer: " << i << '\n'; }
void print(int i) { std::cout << "integer: " << i << '\n'; }

int main()
{
  print(0);
  // NULL is ambiguous, compilation will fail
  print(NULL);
}
