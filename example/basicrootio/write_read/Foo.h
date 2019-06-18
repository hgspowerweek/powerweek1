#pragma once

#include <string>

struct Foo {
  Foo() = default; // needed by ROOT IO
  Foo(const std::string& s, float x) :  x{x} {}
  std::string name;
  float x = 0;
};
