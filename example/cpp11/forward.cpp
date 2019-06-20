#include <vector>
#include <iostream>
#include <utility>

// An example showing
// how we can construct a particle instance
// directly in the underlying container managed privately
// by an event class

class Particle {
  double x{};
  double y{};
 public:
  Particle(double x, double y) : x(x), y(y) {};
  Particle() = default;
  Particle (Particle &&) = default;	
  ~Particle() {
    std::cerr << "particle destructed\n";
  }
};

class Event {
  std::vector<Particle> particles{};
 public:
  Event() { particles.reserve(10); }

  // this is readable but still makes a copy(!?)
  void addParticle1(Particle&& p) {
    particles.push_back(std::move(p));
  }

  // The interface allows to construct
  // the particle directly within the storage container.
  // We use the parameter pack method in order not having
  // to repeat the list of Particle constructor arguments.
  template < class... Args >
  void addParticle2(Args&&... args) {
    particles.emplace_back(std::forward<Args>(args)...);
  }

};

int main() {
  Event event;
  // prefer this (no temporary will be created)
  event.addParticle2(1.0, 2.0);

  // over this (temporary will be created)
  event.addParticle1(Particle(2.0, 3.0));
  return 0;
}
