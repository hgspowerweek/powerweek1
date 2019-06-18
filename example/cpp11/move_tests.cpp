#include <vector>
#include <iostream>

class Foo {
  public: 
    Foo(int i) : val(i) {}
    Foo(const Foo&& other) : val(std::move(other.val)) 
    {
      std::cout << "Foo(const Foo&& other)\n";
    }
    const Foo& operator= (const Foo&& other)
    {
      val = std::move(other.val);
      std::cout << "operator= (const Foo&& other)\n";
      return *this;
    }
    Foo(const Foo& other) : val(other.val) 
    {
      std::cout << "Foo(const Foo& other)\n";
    }
    const Foo& operator= (const Foo& other)
    {
      val = other.val;
      std::cout << "operator= (const Foo& other)\n";
      return *this;
    }

    std::vector<int> val; 
};

Foo f(Foo foo) { return foo; }
Foo getFoo() { Foo f(10000); return f; }

int main() {
  std::cout << "\ncall constructor\n";
  Foo f3(2);

  std::cout << "\ncall copy constructor\n";
  Foo foo = f3; 

  std::cout << "\ncheck what happens\n";
  foo = f(Foo(1));
  std::cout << foo.val.size() << '\n';

  std::cout << "\ngetFoo()\n";
  foo = getFoo();
  std::cout << foo.val.size() << '\n';

  std::cout << "\nexplicit move\n";
  Foo foo2 = std::move(Foo(1));
  std::cout << foo2.val.size() << '\n';
}

