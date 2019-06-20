#include <Vc/Vc>
#include <iostream>

using Vc::float_v;
using Vc::all_of;
using Vc::any_of;
using Vc::none_of;
using Vc::some_of;

void print_horizontal(const auto& mask);

int main()
{
  float sa[8] = {0,4,5,2,9,4,6,8};
  float sb[8] = {1,8,7,3,10,1,0, 9};
  float sc[8] = {1,5,6,3,10,5,7,9};

  float_v a(sa), b(sb), c(sc);

  auto m1 = a < b; 
  auto m2 = a < c;
  auto m3 = c < a;

  std::cout << a << " < " << b << " = " << m1 << "\n";
  print_horizontal(m1);
  std::cout << a << " < " << c << " = " << m2 << "\n";
  print_horizontal(m2);
  std::cout << c << " < " << a << " = " << m3 << "\n";
  print_horizontal(m3);

  const Vc::int_v ia(Vc::IndexesFromZero);
  const Vc::int_v ib(Vc::int_v::IndexesFromZero().rotated(2));
  std::cout << ia << " < " << ib << " = " << (ia<ib) << std::endl;

  return 1;
}

void print_horizontal(const auto& mask)
{
  std::cout << "all_of: " << all_of(mask) << "\n";
  std::cout << "any_of: " << any_of(mask) << "\n";
  std::cout << "none_of: " << none_of(mask) << "\n";
  std::cout << "some_of: " << some_of(mask) << "\n";
}
