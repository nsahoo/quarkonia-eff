#ifndef PTLOOPER_H
#define PTLOOPER_H

#include "treeLooper.h"

#include "TH1D.h"
#include "TH2D.h"

#include <iostream>
#include <vector>

class ptLooper : public treeLooper {
 public:
  ptLooper(string ttree_file = "file.root", string tail = "", int nevent = -1, int ievent = 0);
  ~ptLooper();

  void doLoop();

  TH1D * get_dimuonPt_h() {return dimuonPt_h;};
  TH1D * get_dimuonPt4_h() {return dimuonPt4_h;};
  TH1D * get_dimuonEta_h() {return dimuonEta_h;};
  TH1D * get_dimuonEta4_h() {return dimuonEta4_h;};

  TH1D * get_muPN_mass_h() {return muPN_mass_h;};
  TH1D * get_mass_h() {return mass_h;};

  vector <TH1D*> get_histos1D() {return histos1D;};

  TH2D * get_dimuonpteta_h() {return dimuonpteta_h;};
  TH2D * get_muonpteta_h() {return muonpteta_h;};

 private:

  TH1D * dimuonPt_h;
  TH1D * dimuonPt4_h;

  TH1D * dimuonEta_h;
  TH1D * dimuonEta4_h;

  TH1D * muPN_mass_h;
  TH1D * mass_h;

  vector <TH1D*> histos1D;

  TH2D * dimuonpteta_h;
  TH2D * muonpteta_h;

  bool simul_Jpsi_trigger(TLorentzVector * mu1, TLorentzVector * mu2, TLorentzVector * dimuon);

  TH1D * dimuonPtTriggered_h;
};

#endif
