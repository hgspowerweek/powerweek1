#include <iostream>
#include <unistd.h>
#include <omp.h>

int main()
{
  const int n = 2, m = 2;
  #pragma omp parallel for collapse(2)
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= m; j++)
    {
      printf("%d %d %d\n", i, j, omp_get_thread_num());
      usleep(200);
    }
}
