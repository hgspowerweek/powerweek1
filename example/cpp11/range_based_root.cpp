#include <vector>
#include <iostream>

#include "TClonesArray.h"
#include "TParticle.h"
using std::cout;

int main()
{
  TClonesArray arr("TParticle");
  for (int i=0; i<10; ++i) {
    TParticle& part = *static_cast<TParticle*>(arr.ConstructedAt(i));
    part.SetPdgCode(i);
  }

  for (auto o : arr) {
    TParticle& part = *static_cast<TParticle*>(o);
    std::cout << "Pdg code: " <<  part.GetPdgCode() << '\n';
  }

}
