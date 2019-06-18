#include "event.h"

void event::AddParticle(const particle& part)
{
  // add a particle to the internal array
  fParticles.push_back(part);
}

/// get the particle at position i
/// @param i particle position
const particle& event::GetParticle(size_t i) const
{ 
  return fParticles.at(i); 
}

/// Reset all event data, clear particle array and vertex information
void event::ResetEvent()
{
  fVertex.fill(0.);
  fParticles.clear();
}

