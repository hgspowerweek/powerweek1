#include <iostream>
using std::cout;

void print(int *i) { std::cout << "integer pointer: " << i << '\n'; }
void print(int i) { std::cout << "integer: " << i << '\n'; }

int main()
{
  print(0);
  // to decalre a null pointer always use nullptr, it is type safe
  print(nullptr);
}
