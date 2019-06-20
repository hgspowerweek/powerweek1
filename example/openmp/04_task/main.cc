#include <omp.h>
#include <iostream>
#include <unistd.h>
#include <deque>

void f(int w)
{
  printf("now sleeping for %i in thread %i\n", w, omp_get_thread_num());
  sleep(w);
}

int main()
{
  std::deque<int> list = { 5, 2, 3, 4, 1 };

  #pragma omp parallel
  #pragma omp single
  for (auto i : list) {
    #pragma omp task
    f(i);
  }
}
