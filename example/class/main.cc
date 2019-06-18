#include <iostream>

#include "particle.h"

int main()
{
  particle p;
  particle_spin p_spin;

  p.decay();

  p_spin.decay();

  particle &p_ref = p;
  p_ref.decay();

  p_ref = p_spin;
  p_ref.decay();

  particle p2(p);

  particle p3 = p;

  particle p4;
  p4 = p;

  particle p5(p_spin);

  return 0;
}
