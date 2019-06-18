//**************************************************************************
//* This file is property of and copyright by ....                         *
//* All rights reserved.                                                   *
//*                                                                        *
//* Primary Authors: Matthias Richter <Matthias.Richter@ift.uib.no>        *
//*                                                                        *
//* Permission to use, copy, modify and distribute this software and its   *
//* documentation strictly for non-commercial purposes is hereby granted   *
//* without fee, provided that the above copyright notice appears in all   *
//* copies and that both the copyright notice and this permission notice   *
//* appear in the supporting documentation. The authors make no claims     *
//* about the suitability of this software for any purpose. It is          *
//* provided "as is" without express or implied warranty.                  *
//**************************************************************************

/** @file   twoparticle.C
    @author Matthias Richter
    @date   2013-11-25
    @brief  A simple macro with surprises for the purpose of valgrind and gdb training
*/

/** @mainpage A test project

    @section intro Introduction
    This file serves as example for the training on development tools during the
    <a class="el" href="http://aliceinfo.cern.ch">
    H-QM Power Week 4 - November 2013 </a> .

    @section execution Running the program
    Run it in ROOT CINT:
    <pre> root -l -b -q twoparticle.C </pre>
    Much faster: compile in ACLIC and run:
    <pre> root -l -b -q twoparticle.C++</pre>

    Compiling the program
    <pre>g++ -I`root-config --incdir` `root-config --libs` -lEG -std=c++17 -o twoparticle twoparticle.C</pre>
    Running the compiled program
    <pre>./twoparticle</pre>

    @section Links Links
    check section @ref functions for documentation of functions
*/

/**
 * @defgroup functions The functions
 * In this group, all functions of the project are collected.
 */

// include header files for the porpose of compilation
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TParticle.h"
#include "TSystem.h"
#include "TH1.h"
#include "TH2.h"
#include "TF2.h"
#include "TObjArray.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TRandom.h"
#include "TStopwatch.h"
#include <cstdlib>
using namespace std;
#endif

// forward declaration of functions
/**
 * Load libraries
 * @return 0 on success
 * @ingroup functions
 */
int LoadLibraries();

/**
 * Generate some particles of mass 140 MeV according to a distribution in
 * phi and pT
 * @note the caller needs to do the cleanup
 * @return pointer to TObjArray of TParticle instances
 * @ingroup functions
 */
TObjArray* GenerateParticles(TF2* distribution);

/**
 * Read particle properties into references of float variables
 * @note this function is probably deprecated
 *
 * @param part     the particle instance
 * @param phi      target for phi value
 * @param eta      target for eta value
 * @return 0 on success
 * @ingroup functions
 */
int GetProperties(const TParticle part, float& phi, float& eta);

/**
 * Correlate two particles
 * @param trigger        trigger particle
 * @param associated     associated particle
 * @param hDeltaphiDist  histogram for delta phi 1D distribution
 * @param hDeltaPhiVsDeltaEta  histogram for delta phi - delta eta 2D distribution
 * @return 0 on success
 * @ingroup functions
 */
int Correlate(const TParticle trigger, const TParticle associated, TH1 *hDeltaphiDist, TH2* hDeltaPhiVsDeltaEta);

/**
 * Pi constant to be used within the calculations
 */
const Float_t Pii = 3.14159;

/**
 * The steering function.
 * @param nevent      number of events
 * @return 0 on success
 * @ingroup functions
 */
int twoparticle(const int nevent=10)
{
  TH1F *hDeltaphiDist = new TH1F("hDeltaphiDist","hDeltaphiDist",180,-0.5*Pii,1.5*Pii);
  TH2F *hDeltaPhiVsDeltaEta = new TH2F("hDeltaPhiVsDeltaEta","hDeltaPhiVsDeltaEta",40,-2.0,2.0,30,-0.5*Pii,1.5*Pii);
  TF2* particleDistribution = new TF2("particleDistribution","x*exp(-2.0*x)*(1+2*0.04*(5.0*x-x*x)*cos(2*(y-[0]))+2*0.04*(5.0*x-x*x)*cos(3*(y-[1])))",0,5,0,TMath::TwoPi());

  // Load libraries
  LoadLibraries();

  TStopwatch timer;
  timer.Start();

  for (int iev=0; iev<nevent; iev++){
    TObjArray* theparticles = GenerateParticles(particleDistribution);
    int nofParticles=theparticles->GetEntriesFast();
    cout << " event no: " << iev << "   " << nofParticles << " particle(s)" << endl;
    for (int ct=0; ct<nofParticles; ct++) {
      TParticle* trigger=(TParticle*)theparticles->At(ct);
      if (!trigger) continue;
      for (int ca=0; ca<nofParticles; ca++) {
	if (ct==ca) continue;
	TParticle* associated=(TParticle*)theparticles->At(ca);
	if (!associated) continue;
	Correlate(*trigger, *associated, hDeltaphiDist, hDeltaPhiVsDeltaEta);
      }
    }
    delete theparticles;
  }
  timer.Stop();
  printf("Realtime=%7.3f s, Cpu=%7.3f s\n",timer.RealTime(),timer.CpuTime());

  TCanvas* c1 = new TCanvas("c1","two-particle phi correlation",800,800);
  c1->Divide(2, 1);
  c1->cd(1);
  hDeltaphiDist->Draw();
  c1->cd(2);
  hDeltaPhiVsDeltaEta->Draw("surf2");
  TFile output("result.root", "RECREATE");
  c1->Write();
  output.Close();

  return 0;
}

int LoadLibraries()
{
#ifdef __CINT__
  gSystem->Load("libEG");
#endif //__CINT__

  return 0;
}

TObjArray* GenerateParticles(TF2* distribution)
{
  TObjArray* particles=new TObjArray;
  particles->SetOwner(kTRUE);
  Int_t nParticles = gRandom->Poisson(1000);
  double pTrans=-1.;
  double phi=-1.;

  for (Int_t cParticle=0; cParticle<nParticles; cParticle++) {
    distribution->GetRandom2(pTrans,phi);
    double ypart = gRandom->Gaus(0.0,4.0);
    double MassT = TMath::Sqrt(0.140*0.140+pTrans*pTrans);
    double Pz = MassT*TMath::SinH(ypart);

    TParticle* mypart = new TParticle();
    mypart->SetMomentum(pTrans*cos(phi), pTrans*sin(phi), Pz, MassT);

    particles->Add(mypart);
  }
  return particles;
}

int GetProperties(const TParticle part, float& phi, float& eta)
{
  /// lets assume it's smart to centralize the access to particle properties
  /// in a function
  phi=part.Phi();
  eta=part.Eta();

  return 0;
}

int Correlate(const TParticle trigger, const TParticle associated, TH1 *hDeltaphiDist, TH2* hDeltaPhiVsDeltaEta)
{
  float phi = trigger.Phi();
  if (phi<0) phi += 2*Pii;
  float eta= trigger.Eta();

  float associatedPhi = associated.Phi();
  if (phi<0) associatedPhi += 2*Pii;
  float associatedEta= associated.Eta();

  float DeltaPhi = associatedPhi - phi;
  float DeltaEta = associatedEta - eta;

  if (DeltaPhi<-0.5*Pii) DeltaPhi += 2*Pii;
  if (DeltaPhi>1.5*Pii) DeltaPhi -= 2*Pii;

  hDeltaphiDist->Fill(DeltaPhi);
  hDeltaPhiVsDeltaEta->Fill(DeltaEta, DeltaPhi);
  return 0;
}

#ifndef __CINT__
/**
 * main function - entry point for the compiled program
 * The compiled program can be started with the number of events as parameter.
 * @param  argc   number of command line arguments
 * @param  argv   array of command line arguments
 * @return 0 on success
 * @ingroup functions
 */
int main(int argc, char** argv)
{
  int n = -1;
  if (argc > 1)
    n = strtol(argv[1], NULL, 0);

  int retVal = 0;
  if (n > 0)
    retVal = twoparticle(n); // call with the parameter
  else {
    retVal = twoparticle(); // use default parameter of function
  }

  return retVal;
}
#endif
