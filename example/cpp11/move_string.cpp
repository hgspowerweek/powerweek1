// move example
#include <utility>      // std::move
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <string>       // std::string

int main () {
  std::string foo = "foo-string";
  std::string bar = "bar-string";
  std::vector<std::string> myvector;

  myvector.push_back (foo);                    // copies
  myvector.push_back (std::move(bar));         // moves

  std::cout << "foo is: " << foo << '\n';
  std::cout << "bar is: " << bar << '\n';

  std::cout << "myvector contains:";
  for (const auto& x:myvector) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}
