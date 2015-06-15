#ifndef TREELOOPER_H
#define TREELOOPER_H

#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TH1D.h"

//#include <vector>
#include <string>
#include <iostream>

using namespace std;

class treeLooper {
 public:
  treeLooper(string ttree_file = "file.root", string tail = "", int nevent = -1, int ievent = 0);
  ~treeLooper();

  int get_entries() {return events;};
  virtual void doLoop() = 0;

 protected:
  TFile * input_f;
  TTree * tree;

  string tail_;
  int events;
  int nevent_;
  int ievent_;
  int max_entry;

  // Declaration of leaf types
  Int_t           run;
  Int_t           event;
  Int_t           irank;
  TLorentzVector  *dimuon_p4;
  TLorentzVector  *muonP_p4;
  TLorentzVector  *muonN_p4;
  Float_t         MassErr;
  Float_t         vProb;
  Float_t         DCA;
  Float_t         ppdlPV;
  Float_t         ppdlErrPV;
  Float_t         cosAlpha;
  Int_t           numPrimaryVertices;
  Int_t           dimuon_pdgId;
  TLorentzVector  *gen_dimuon_p4;
  TLorentzVector  *gen_muonP_p4;
  TLorentzVector  *gen_muonN_p4;

  // List of branches
  TBranch        *b_run;   //!
  TBranch        *b_event;   //!
  TBranch        *b_irank;   //!
  TBranch        *b_dimuon_p4;   //!
  TBranch        *b_muonP_p4;   //!
  TBranch        *b_muonN_p4;   //!
  TBranch        *b_MassErr;   //!
  TBranch        *b_vProb;   //!
  TBranch        *b_DCA;   //!
  TBranch        *b_ppdlPV;   //!
  TBranch        *b_ppdlErrPV;   //!
  TBranch        *b_cosAlpha;   //!
  TBranch        *b_numPrimaryVertices;   //!
  TBranch        *b_dimuon_pdgId;   //!
  TBranch        *b_gen_dimuon_p4;   //!
  TBranch        *b_gen_muonP_p4;   //!
  TBranch        *b_gen_muonN_p4;   //!


};


#endif
