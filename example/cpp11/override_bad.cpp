#include <iostream>

class Foo {
  public:
  virtual void print(const char* something) {
    std::cout << "Foo prints " << something << '\n';
  }
};

// print in Bar and Foo are differenct (const in Bar)
// so print in Bar will not override print in Foo
class Bar : public Foo {
  public:
  virtual void print(const char* something) const {
    std::cout << "Bar prints " << something << '\n';
  }
};

// if you intend to override a base class function tell the compiler so.
// it will give an error if there is no matching function, e.g.
//class Bar : public Foo {
  //public:
  //virtual void print(const char* something) const override {
    //std::cout << "Bar prints " << something << '\n';
  //}
//};

int main ()
{
  Bar bar;
  Foo &foo = bar;
  foo.print("hi");
}

