#include <vector>
#include <iostream>
using std::cout;

int main()
{

  cout << "const auto& vector\n";
  std::vector<int> v{1,4,5};
  for (const auto& val : v) std::cout << val << '\n';


  float arr[]={4.,5.,6.};
  // val is a const reference to the value in the array and cannot be modified
  cout << "const auto& val\n";
  for (const auto& val : arr) std::cout << val << '\n';

  // val is a reference to the value in the array and can be modified
  cout << "auto& val - square the value\n";
  for (auto& val : arr) val*=val;
  for (const auto& val : arr) std::cout << val << '\n';

  // val is _copy_ of the value. You can work on it, but modifying it will
  // not modify the value will not modify the value in the array
  cout << "auto val - square the value\n";
  for (auto val : arr) val*=val;
  for (const auto& val : arr) std::cout << val << '\n';
}
