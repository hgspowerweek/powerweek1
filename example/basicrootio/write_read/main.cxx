#include "Foo.h"
#include <TFile.h>
#include <TClass.h>
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

int main() {
  Foo f("hello world", 1.2);
  TFile file("fooserialized.root", "RECREATE");

  // write object to file; registered under key foo
  file.WriteObjectAny((void*)&f, TClass::GetClass("Foo"), "foo");

  // retrieve from file; instantiate another object (has to be pointer)
  Foo *anotherFoo = nullptr;
  file.GetObject("foo", anotherFoo);

  // verify that the new object has same
  // properties as old one
  assser(anotherFoo != nullptr);
  assert(anotherFoo->x != f.x);
  assert(anotherFoo->name.compare(f.name) == 0);
  
  return 0;
}
