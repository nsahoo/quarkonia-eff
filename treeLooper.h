#ifndef TREELOOPER_H
#define TREELOOPER_H

#include "CommonFuncs.h"

#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"

#include <string>
#include <iostream>

using namespace std;

class treeLooper {
public:
  treeLooper(string ttree_file = "file.root", string tail = "", Meson meson = JPsi, int nevent = -1, int ievent = 0);
  virtual ~treeLooper();

  int get_entries() {return events;};
  virtual void doLoop() = 0;

protected:
  TFile * input_f;
  TTree * tree;

  string tail_;
  Meson meson_;
  int events;
  int nevent_;
  int ievent_;
  int max_entry;

  // Declaration of leaf types
  UInt_t          run;
  ULong64_t       event;
  UInt_t          lumiblock;
  UInt_t          nonia;
  UInt_t          nmuons;
  UInt_t          trigger;
  Int_t           charge;
  TLorentzVector  *dimuon_p4;
  TLorentzVector  *muonP_p4;
  TLorentzVector  *muonN_p4;
  Float_t         MassErr;
  Float_t         vProb;
  Float_t         DCA;
  Float_t         ppdlPV;
  Float_t         ppdlErrPV;
  Float_t         ppdlBS;
  Float_t         ppdlErrBS;
  Float_t         cosAlpha;
  Float_t         lxyPV;
  Float_t         lxyBS;
  UInt_t          numPrimaryVertices;
  Int_t           mother_pdgId;
  Int_t           dimuon_pdgId;
  TLorentzVector  *gen_dimuon_p4;
  TLorentzVector  *gen_muonP_p4;
  TLorentzVector  *gen_muonN_p4;

  // List of branches
  TBranch        *b_run;   //!
  TBranch        *b_event;   //!
  TBranch        *b_lumiblock;   //!
  TBranch        *b_nonia;   //!
  TBranch        *b_nmuons;   //!
  TBranch        *b_trigger;   //!
  TBranch        *b_charge;   //!
  TBranch        *b_dimuon_p4;   //!
  TBranch        *b_muonP_p4;   //!
  TBranch        *b_muonN_p4;   //!
  TBranch        *b_MassErr;   //!
  TBranch        *b_vProb;   //!
  TBranch        *b_DCA;   //!
  TBranch        *b_ppdlPV;   //!
  TBranch        *b_ppdlErrPV;   //!
  TBranch        *b_ppdlBS;   //!
  TBranch        *b_ppdlErrBS;   //!
  TBranch        *b_cosAlpha;   //!
  TBranch        *b_lxyPV;   //!
  TBranch        *b_lxyBS;   //!
  TBranch        *b_numPrimaryVertices;   //!
  TBranch        *b_mother_pdgId;   //!
  TBranch        *b_dimuon_pdgId;   //!
  TBranch        *b_gen_dimuon_p4;   //!
  TBranch        *b_gen_muonP_p4;   //!
  TBranch        *b_gen_muonN_p4;   //!

};

#endif
