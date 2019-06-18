#include <iostream>

int main()
{
  enum class Fruits { Apple, Pear, Orange };
  enum class Colours { Blue, White, Orange };

  // in case of stronly typed enums the compiler will give an error.
  // If operations are really needed once can cast into another type
  bool b = Fruits::Orange == Colours::Orange; // what?

  std::cout << b << '\n';
}

