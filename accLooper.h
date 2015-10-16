#ifndef ACCLOOPER_H
#define ACCLOOPER_H

#include "treeLooper.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TMathBase.h"

#include <iostream>
#include <vector>

class accLooper : public treeLooper {
 public:
  accLooper(string ttree_file = "file.root", string tail = "", Meson meson = JPsi, int nevent = -1, int ievent = 0, bool barrel = false);
  virtual ~accLooper();

  virtual void doLoop();

  void doAcc();
  void doAccErr();

  TH2D getAcc(){return acc_y_pt_h;};
  TH2D getAccErr(){return err_acc_y_pt_h;};
  TH2D getAccAll(){return all_y_pt_h;};
  TH2D getAccPas(){return pas_y_pt_h;};

private:

  const Int_t nb_y_  =  25;
  const Int_t nb_pt_ = 100;
  const Double_t rapmin_ = 0.;
  const Double_t rapmax_ = 2.5; 
  const bool barrel_;
  TH1D all_pt_h;
  TH1D all_y_h;
  TH2D all_y_pt_h;

  TH1D pas_pt_h;
  TH1D pas_y_h;
  TH2D pas_y_pt_h;

  TH1D acc_pt_h;
  TH1D acc_y_h;
  TH2D acc_y_pt_h;

  TH2D err_acc_y_pt_h;

};

#endif
