#include <iostream>

int main()
{
  enum Animals {Bear, Cat};
  enum Birds {Eagle, Duck};

  // normal enums automatically convert to intrinsic types (e.g. int) so one
  // can compare and operate on different enum variable, which can be error
  // prone
  bool b = Bear == Eagle; // what?

  std::cout << "Bear == Eagle: " << b << '\n';
}

