#include "particle.h"
#include "event.h"

#include "TTree.h"
#include "TFile.h"
#include "TRandom.h"

void simulate(Int_t nevt=10, Int_t npart=5)
{
  // simple simulation of particles

  gRandom->SetSeed(0);
  event *ev=new event;

  TFile fout("test.root","recreate");
  TTree t("t","t");
  t.Branch("event",&ev);

  for (Int_t iev=0; iev<nevt; ++iev) {
    Double_t z=gRandom->Gaus(0, 5);
    std::array<double, 3> v={0., 0., z};
    ev->SetVertex(v);

    for (Int_t ipart=0; ipart<npart; ++ipart) {
      Double_t px=gRandom->Gaus(0.,1.);
      Double_t py=gRandom->Gaus(0.,1.);
      Double_t pz=gRandom->Gaus(0.,1.);

      std::array<double, 3> mom={px,py,pz};
      ev->AddParticle(particle(mom));
    }
    t.Fill();
    ev->ResetEvent();
  }
  fout.Write();
  fout.Close();
  delete ev;
}

int main() {
  simulate();
  return 0;
}


