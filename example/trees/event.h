#ifndef EVENT_H_
#define EVENT_H_

#include <vector>
#include "particle.h"

class event  {
  public:
    event() : fParticles(), fVertex() {}
    event(const event& ev) = default;
    event& operator=(const event& ev) = default;
    ~event() = default;

    void AddParticle(const particle& part);
    const particle& GetParticle(size_t i) const;

    void SetVertex(const std::array<double, 3>& vertex)       { fVertex = vertex; }

    const std::array<double, 3>& GetVertex() const { return fVertex; }

    size_t GetNumberOfParticles()  const { return fParticles.size();       }

    std::vector<particle>& GetParticles() { return fParticles; }

    void ResetEvent();

  private:

    std::vector<particle> fParticles;  // array of particles
    std::array<double, 3> fVertex;  // vertex position
};
#endif
