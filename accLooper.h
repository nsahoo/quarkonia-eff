#ifndef ACCLOOPER_H
#define ACCLOOPER_H

#include "treeLooper.h"

#include "accCut.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TMathBase.h"

#include <iostream>
#include <vector>

class accLooper : public treeLooper {
 public:
  accLooper(string ttree_file = "file.root", string tail = "", int nevent = -1, int ievent = 0);
  virtual ~accLooper();

  virtual void doLoop();

  void doAcc();

  TH2D getAcc(){return acc_y_pt_h;};

  //protected:
  //  bool acceptanceCut();

private:

  TH1D all_pt_h;
  TH1D all_y_h;
  TH2D all_y_pt_h;

  TH1D pas_pt_h;
  TH1D pas_y_h;
  TH2D pas_y_pt_h;

  TH1D acc_pt_h;
  TH1D acc_y_h;
  TH2D acc_y_pt_h;


};

#endif
