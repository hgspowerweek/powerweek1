#include "Position.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>

int main() {
  TFile file("positions.root", "RECREATE");

  // create a TTree to hold our positions
  TTree tree("PosTree", "PosTree");

  Position pos; 
  // make a branch holding positions
  tree.Branch("Position", "Position", &pos);

  // a toy loop to fill the TBranch/TTree with many
  // Position "instances"
  for (int i=0; i<100000; ++i) {
    // gRandom is the default RNG instance of ROOT
    pos.setX(gRandom->Uniform(1));
    pos.setY(gRandom->Uniform(1));
    pos.setZ(gRandom->Gaus(0,5));

    // this fills the tree (it uses the registered variables in the branch definition)
    tree.Fill();
  }

  // write tree
  tree.Write();
  file.Close();

  return 0;
}
