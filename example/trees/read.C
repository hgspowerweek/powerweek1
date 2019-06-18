#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TROOT.h"
#include "TH1.h"
#include "TCanvas.h"

void read(const char* filename)
{

  TH1F *hPt=new TH1F("hPt","p_{T}; p_{T} (GeV/c)", 100,0,10);
  TH1F *hZ=new TH1F("hZ","z; z (cm)", 100,-10,10);
  TFile f(filename);
  gROOT->cd();

  TTree *t=(TTree*)f.Get("tree");

  Float_t z=0.;
  TLorentzVector *v=nullptr;

  t->SetBranchAddress("z",&z);
  t->SetBranchAddress("particle",&v);
  //t->SetBranchStatus("*",0);
  //t->SetBranchStatus("z",1);

  for (Int_t iev=0; iev<t->GetEntries(); ++iev) {
    t->GetEntry(iev);
    hPt->Fill(v->Pt());
    hZ->Fill(z);
  }

  TCanvas *c=new TCanvas("c","c");
  c->Divide(2);
  c->cd(1);
  hPt->Draw();
  c->cd(2);
  hZ->Draw();

  delete v;
}

