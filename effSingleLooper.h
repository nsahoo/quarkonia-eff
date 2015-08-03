#ifndef EFFSINGLELOOPER_H
#define EFFSINGLELOOPER_H

#include "treeLooper.h"

#include "accCut.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TMathBase.h"

#include <iostream>
#include <vector>

class effSingleLooper : public treeLooper {
 public:
  effSingleLooper(string ttree_file = "file.root", string tail = "", int nevent = -1, int ievent = 0);
  virtual ~effSingleLooper();

  virtual void doLoop();

  void doEff();

  TH2D getRecoEff(){return eff_eta_pt_h;};

private:

  bool MC_matched(TLorentzVector * m1, TLorentzVector * m2);

  TH1D all_pt_h;
  TH1D all_eta_h;
  TH2D all_eta_pt_h;

  TH1D pas_pt_h;
  TH1D pas_eta_h;
  TH2D pas_eta_pt_h;

  TH1D eff_pt_h;
  TH1D eff_eta_h;
  TH2D eff_eta_pt_h;

};

#endif
