#include <iostream>
#include <unistd.h>

void f()
{
  printf("started f()\n");
  sleep(2);
  printf("finished f()\n");
}

void g()
{
  printf("started g()\n");
  sleep(4);
  printf("finished g()\n");
}

int main()
{
  printf("main started\n");

  #pragma omp parallel sections
  {
    #pragma omp section
    f();
    #pragma omp section
    g();
  }

  printf("main finished\n");
}
