#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TF1.h"

/*

.L example.C+
example();

TFile f("output.root");
gROOT->cd();
TTree *t=(TTree*)f.Get("tree");
t->Draw("particle.Pt()");

*/
void example(Int_t bufsize = 32000)
{
  TF1 fpt("fpt","x*(1+(sqrt(x*x+0.14^2)-0.14)/(7.24*0.12))^(-7.24)",0.1,100);

  TFile f("output.root","recreate");
  TTree t("tree","tree");
  Float_t z=0.;
  TLorentzVector *v=new TLorentzVector;

  t.Branch("z",&z);
  t.Branch("particle",&v, bufsize);

  for (Int_t ientry=0; ientry<100000; ++ientry) {
    z=gRandom->Gaus(0,5);

    Double_t phi = gRandom->Uniform(0.0, TMath::TwoPi());
    Double_t eta = gRandom->Uniform(-1, 1);
    Double_t pt  = fpt.GetRandom();
    v->SetPtEtaPhiM(pt,eta,phi,.14);

    t.Fill();
  }

  f.Write();
  f.Close();
  delete v;
}
