#include "treeLooper.h"

treeLooper::treeLooper(string ttree_file, string tail, int nevent, int ievent) :
  tail_(tail),
  nevent_(nevent),
  ievent_(ievent)
{

  cout << "opening " << ttree_file << endl;
  input_f = new TFile(ttree_file.c_str());
  tree = (TTree*)input_f->Get("rootuple/oniaTree");

  events = tree->GetEntries();
  if (nevent == -1) nevent = events;
  max_entry = min(ievent + nevent, events);

  dimuon_p4 = 0;
  muonP_p4 = 0;
  muonN_p4 = 0;
  gen_dimuon_p4 = 0;
  gen_muonP_p4 = 0;
  gen_muonN_p4 = 0;

  tree->SetBranchAddress("run", &run, &b_run);
  tree->SetBranchAddress("event", &event, &b_event);
  tree->SetBranchAddress("irank", &irank, &b_irank);
  tree->SetBranchAddress("dimuon_p4", &dimuon_p4, &b_dimuon_p4);
  tree->SetBranchAddress("muonP_p4", &muonP_p4, &b_muonP_p4);
  tree->SetBranchAddress("muonN_p4", &muonN_p4, &b_muonN_p4);
  tree->SetBranchAddress("MassErr", &MassErr, &b_MassErr);
  tree->SetBranchAddress("vProb", &vProb, &b_vProb);
  tree->SetBranchAddress("DCA", &DCA, &b_DCA);
  tree->SetBranchAddress("ppdlPV", &ppdlPV, &b_ppdlPV);
  tree->SetBranchAddress("ppdlErrPV", &ppdlErrPV, &b_ppdlErrPV);
  tree->SetBranchAddress("cosAlpha", &cosAlpha, &b_cosAlpha);
  tree->SetBranchAddress("numPrimaryVertices", &numPrimaryVertices, &b_numPrimaryVertices);
  tree->SetBranchAddress("dimuon_pdgId", &dimuon_pdgId, &b_dimuon_pdgId);
  tree->SetBranchAddress("gen_dimuon_p4", &gen_dimuon_p4, &b_gen_dimuon_p4);
  tree->SetBranchAddress("gen_muonP_p4", &gen_muonP_p4, &b_gen_muonP_p4);
  tree->SetBranchAddress("gen_muonN_p4", &gen_muonN_p4, &b_gen_muonN_p4);

}

treeLooper::~treeLooper() {
  if (input_f) input_f->Close();
}
