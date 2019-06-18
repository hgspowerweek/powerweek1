#ifndef PARTICLE_H
#define PARTICLE_H

#include <math.h>
#include <array>

class particle {
public:
  particle();
  virtual ~particle();
  particle(const particle &rhs);
  particle& operator=(const particle &rhs);

  float pt() const
  { return sqrt(p[0]*p[0] + p[1]*p[1]); }

  virtual void decay();

protected:
  std::array<float, 4> p;
};

class particle_spin : public particle {
public:
  particle_spin();
  virtual ~particle_spin();

  virtual void decay();

protected:
  float spin;
};

#endif
