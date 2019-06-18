#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <array>
#include <complex>  // for std::sqrt

class particle {
  public:
    particle() : fMom() {}
    particle(const std::array<double, 3>& mom) : fMom(mom) {;}
    particle(const particle &part) = default;
    particle& operator= (const particle &part) = default;

    ~particle() = default;

    std::array<double, 3>& GetMomentum() { return fMom; }

    double pt() const { return std::sqrt(fMom[0]*fMom[0] + fMom[1]*fMom[1]); }

  private:
    std::array<double, 3> fMom;  // momentum vector px, py, pz
};

#endif
