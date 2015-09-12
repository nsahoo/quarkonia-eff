#ifndef EFFLOOPER_H
#define EFFLOOPER_H

#include "treeLooper.h"

#include "CommonFuncs.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TMathBase.h"

#include <iostream>
#include <vector>

class effLooper : public treeLooper {
 public:
  effLooper(string ttree_file = "file.root", string tail = "", Meson meson = JPsi, int nevent = -1, int ievent = 0, bool barrel = false);
  virtual ~effLooper();

  virtual void doLoop();

  void doEff();

  TH2D getRecoEff(){return eff_reco_y_pt_h;};
  TH2D getTrigEff(){return eff_trig_y_pt_h;};
  TH2D getTotEff(){return eff_tot_y_pt_h;};

private:

  bool triggerTest();

  const bool barrel_;
  const Double_t minm_[5] = {2.91,3.4, 8.6,8.6,8.6};
  const Double_t maxm_[5] = {3.29,4.0,11.5,11.5,11.5};

  TH1D all_pt_h;
  TH1D all_y_h;
  TH2D all_y_pt_h;

  TH1D pas_reco_pt_h;
  TH1D pas_reco_y_h;
  TH2D pas_reco_y_pt_h;

  TH1D pas_trig_pt_h;
  TH1D pas_trig_y_h;
  TH2D pas_trig_y_pt_h;

  TH1D eff_reco_pt_h;
  TH1D eff_reco_y_h;
  TH2D eff_reco_y_pt_h;

  TH1D eff_trig_pt_h;
  TH1D eff_trig_y_h;
  TH2D eff_trig_y_pt_h;

  TH1D eff_tot_pt_h;
  TH1D eff_tot_y_h;
  TH2D eff_tot_y_pt_h;


};

#endif
