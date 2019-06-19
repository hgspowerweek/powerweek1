#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fenv.h>

float getSum(float* numbers, unsigned int count)
{
  float sum = 0;
  for (unsigned int i = count - 1;i >= 0;i--) sum += numbers[i];
  return sum;
}

void inverse(float* numbers, unsigned int count)
{
  for (unsigned int i = 0;i <= count;i++)
  {
    numbers[i] = 1. / numbers[i];
  }
}

int main(int argc, char** argv)
{
  //feenableexcept
  feraiseexcept(FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW); //Enable floating point exceptions

  {
    float* numbers = new float[10000];
    getSum(numbers, 10000);
    delete[] numbers;
  }
  printf("Block 1 passed\n");

  {
    float numbers[10];
    for (int i = 0;i < 10;i++) numbers[i] = i;
    printf("Value of number[5]: %f\n", numbers[5]);
    inverse(numbers, 10);
    printf("Value of number[5]: %f (Can you use a gdb watchpoint to find out when this changed?)\n", numbers[5]);
  }
  printf("Block 2 passed\n");

  return(0);
}
