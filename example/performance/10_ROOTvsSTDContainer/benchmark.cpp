#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../base/timer.h"
#include "point.h"
#include "TObjArray.h"
#include <vector>

#define SIZE (1024*1024*10)
#define ITER (1)


int main(int argc, char** argv)
{
  // an stl vector
  std::vector<Point> stlvector;
  {
    int sign = 1;
    for (int i = 0; i < SIZE; ++i) {
      sign *= -1;
      stlvector.emplace_back(sign*i, i);
    }
  }

  // an ordinary ROOT vector container
  TObjArray rootvector;

  {
    int sign = 1;
    for (int i = 0; i < SIZE; ++i) {
      sign *= -1;
      // NOTE: we don't care about raw pointers and ownership for this benchmark
      rootvector.Add(new TPoint(sign*i, i));
    }
  }


  HighResTimer timer;
  timer.Reset();
  timer.Start();
  for (int i = 0;i < ITER;i++)
  {
    // demonstration of STL sorting
    std::sort(stlvector.begin(), stlvector.end(), [](Point const& a, Point const& b) { return a.x < b.x; }); 
  }
  timer.Stop();
  printf("STL version, Time: %6.3f\n", timer.GetElapsedTime());
    
  timer.Reset();
  timer.Start();
  for (int i = 0;i < ITER;i++)
  {
    rootvector.Sort();
  }
  timer.Stop();
  printf("ROOT version, Time: %6.3f\n", timer.GetElapsedTime());
  return 0;
}
