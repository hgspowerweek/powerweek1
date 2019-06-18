#include <iostream>

class Foo {
  public:
    // final functions cannot be overridden, the compiler will throw an error
  virtual void print(const char* something) const final {
    std::cout << "Foo prints " << something << '\n';
  }
};

class Bar : public Foo {
  public:
  void print(const char* something) const override {
    std::cout << "Bar prints " << something << '\n';
  }
};

int main ()
{
  Bar bar;
  Foo &foo = bar;
  foo.print("hi");
}

