#include "effSingleLooper.h"

effSingleLooper::effSingleLooper(string ttree_file, string tail, int nevent, int ievent)
  : treeLooper(ttree_file, tail, nevent, ievent),
    all_pt_h(Form("all_pt_h_%s", tail.c_str()), Form("all_pt_%s_h;p^{#mu}_{T} (GeV);Acceptance", tail.c_str()), 100, 0., 100.),
    all_eta_h(Form("all_eta_h_%s", tail.c_str()), Form("all_eta_%s_h;#eta^{#mu};Alleptance", tail.c_str()), 100, -2.5, 2.5),
    all_eta_pt_h(Form("all_eta_pt_h_%s", tail.c_str()), Form("all_eta_pt_%s_h;#eta^{#mu};p^{#mu}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    pas_pt_h(Form("pas_pt_h_%s", tail.c_str()), Form("pas_pt_%s_h;p^{#mu}_{T} (GeV);Paseptance", tail.c_str()), 100, 0., 100.),
    pas_eta_h(Form("pas_eta_h_%s", tail.c_str()), Form("pas_eta_%s_h;#eta^{#mu};Paseptance", tail.c_str()), 100, -2.5, 2.5),
    pas_eta_pt_h(Form("pas_eta_pt_h_%s", tail.c_str()), Form("pas_eta_pt_%s_h;#eta^{#mu};p^{#mu}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    eff_pt_h(Form("effSingle_pt_h_%s", tail.c_str()), Form("effSingle_pt_%s_h;p^{#mu}_{T} (GeV);Acceptance", tail.c_str()), 100, 0., 100.),
    eff_eta_h(Form("effSingle_eta_h_%s", tail.c_str()), Form("effSingle_eta_%s_h;#eta^{#mu};Acceptance", tail.c_str()), 100, -2.5, 2.5),
    eff_eta_pt_h(Form("effSingle_eta_pt_h_%s", tail.c_str()), Form("effSingle_eta_pt_%s_h;#eta^{#mu};p^{#mu}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.)

{
  all_pt_h.Sumw2(true);
  all_eta_h.Sumw2(true);
  all_eta_pt_h.Sumw2(true);

  pas_pt_h.Sumw2(true);
  pas_eta_h.Sumw2(true);
  pas_eta_pt_h.Sumw2(true);

  tree->SetBranchStatus("*", 0);
  tree->SetBranchStatus("nmuons", 1);
  tree->SetBranchStatus("gen_dimuon_p4", 1);
  tree->SetBranchStatus("gen_muonP_p4", 1);
  tree->SetBranchStatus("gen_muonN_p4", 1);
  tree->SetBranchStatus("muonP_p4", 1);
  tree->SetBranchStatus("muonN_p4", 1);
}

effSingleLooper::~effSingleLooper() {
}

bool effSingleLooper::MC_matched(TLorentzVector *m1, TLorentzVector *m2) {

  Double_t DeltaR0 = 0.1;
  Double_t DeltaPtRel0 = 0.1;

  Double_t DeltaR = m1->DeltaR(*m2);
  Double_t Delta_pt = TMath::Abs(m2->Pt()-m1->Pt());
  Double_t Delta_pt_rel = Delta_pt / m2->Pt();
  if (DeltaR < DeltaR0 && Delta_pt_rel < DeltaPtRel0) return true;
  return false;

}

void effSingleLooper::doLoop() {
  for (int i = ievent_; i < max_entry; i++) {
    if (i % 100000 == 0) cout << i << " / " << max_entry << endl;
    tree->GetEntry(i);
    if (nmuons <= 2) {

      Double_t gen_muonP_pt = gen_muonP_p4->Pt();
      Double_t gen_muonN_pt = gen_muonN_p4->Pt();
      Double_t gen_muonP_eta = gen_muonP_p4->Eta();
      Double_t gen_muonN_eta = gen_muonN_p4->Eta();

      if (acceptanceCut(gen_dimuon_p4, gen_muonP_p4, gen_muonN_p4)) {
        all_eta_pt_h.Fill(gen_muonP_eta, gen_muonP_pt);
        all_eta_pt_h.Fill(gen_muonN_eta, gen_muonN_pt);
        if (MC_matched(muonP_p4, gen_muonP_p4)) {
          if (muonP_p4->Pt() > 0.5) {
             pas_eta_pt_h.Fill(gen_muonP_eta, gen_muonP_pt);
          }
        }
        if (MC_matched(muonN_p4, gen_muonN_p4)) {
          if (muonN_p4->Pt() > 0.5) {
            pas_eta_pt_h.Fill(gen_muonN_eta, gen_muonN_pt);
          }
        }
      }
    }
  }
}

void effSingleLooper::doEff() {
  eff_eta_pt_h.Divide(&pas_eta_pt_h, &all_eta_pt_h, 1., 1., "B");

  eff_eta_pt_h.SetMaximum(1.);
  eff_eta_pt_h.SetMinimum(0.);
}
