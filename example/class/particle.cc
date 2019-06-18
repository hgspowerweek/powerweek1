#include <iostream>
#include <stdio.h>
#include <cstring>

#include "particle.h"

namespace {
  using std::memcpy;
}

particle::particle() :
  p()
{
  std::cout << this << ": particle constructor called"<< std::endl;
}

particle::~particle()
{
  std::cout << this << ": particle destructor called" << std::endl;
}

particle::particle(const particle &rhs)
{
  std::cout << this << ": particle copy constructor called" << std::endl;

  memcpy(&p, &rhs.p, sizeof(p));
}

particle& particle::operator=(const particle &rhs)
{
  std::cout << this << ": particle assignment operator called" << std::endl;

  if (this != &rhs)
    memcpy(&p, &rhs.p, sizeof(p));

  return *this;
}

void particle::decay()
{
  std::cout << this << ": particle decay called" << std::endl;
}

particle_spin::particle_spin() :
  particle()
{
  std::cout << this << ": particle_spin constructor called" << std::endl;
}

particle_spin::~particle_spin()
{
  std::cout << this << ": particle_spin destructor called" << std::endl;
}

void particle_spin::decay()
{
  std::cout << this << ": particle_spin decay called" << std::endl;
}
