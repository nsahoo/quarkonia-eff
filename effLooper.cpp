#include "effLooper.h"

effLooper::effLooper(string ttree_file, string tail, int nevent, int ievent)
  : treeLooper(ttree_file, tail, nevent, ievent),
    all_pt_h(Form("all_pt_h_%s", tail.c_str()), Form("all_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Alleptance", tail.c_str()), 100, 0., 100.),
    all_y_h(Form("all_y_h_%s", tail.c_str()), Form("all_y_%s_h;y^{#mu^{+}#mu^{-}};Alleptance", tail.c_str()), 100, -2.5, 2.5),
    all_y_pt_h(Form("all_y_pt_h_%s", tail.c_str()), Form("all_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    pas_reco_pt_h(Form("pas_reco_pt_h_%s", tail.c_str()), Form("pas_reco_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Paseptance", tail.c_str()), 100, 0., 100.),
    pas_reco_y_h(Form("pas_reco_y_h_%s", tail.c_str()), Form("pas_reco_y_%s_h;y^{#mu^{+}#mu^{-}};Paseptance", tail.c_str()), 100, -2.5, 2.5),
    pas_reco_y_pt_h(Form("pas_reco_y_pt_h_%s", tail.c_str()), Form("pas_reco_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    pas_trig_pt_h(Form("pas_trig_pt_h_%s", tail.c_str()), Form("pas_trig_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Paseptance", tail.c_str()), 100, 0., 100.),
    pas_trig_y_h(Form("pas_trig_y_h_%s", tail.c_str()), Form("pas_trig_y_%s_h;y^{#mu^{+}#mu^{-}};Paseptance", tail.c_str()), 100, -2.5, 2.5),
    pas_trig_y_pt_h(Form("pas_trig_y_pt_h_%s", tail.c_str()), Form("pas_trig_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    eff_reco_pt_h(Form("eff_reco_pt_h_%s", tail.c_str()), Form("eff_reco_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Acceptance", tail.c_str()), 100, 0., 100.),
    eff_reco_y_h(Form("eff_reco_y_h_%s", tail.c_str()), Form("eff_reco_y_%s_h;y^{#mu^{+}#mu^{-}};Acceptance", tail.c_str()), 100, -2.5, 2.5),
    eff_reco_y_pt_h(Form("eff_reco_y_pt_h_%s", tail.c_str()), Form("eff_reco_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    eff_trig_pt_h(Form("eff_trig_pt_h_%s", tail.c_str()), Form("eff_trig_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Acceptance", tail.c_str()), 100, 0., 100.),
    eff_trig_y_h(Form("eff_trig_y_h_%s", tail.c_str()), Form("eff_trig_y_%s_h;y^{#mu^{+}#mu^{-}};Acceptance", tail.c_str()), 100, -2.5, 2.5),
    eff_trig_y_pt_h(Form("eff_trig_y_pt_h_%s", tail.c_str()), Form("eff_trig_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.),

    eff_tot_pt_h(Form("eff_tot_pt_h_%s", tail.c_str()), Form("eff_tot_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Acceptance", tail.c_str()), 100, 0., 100.),
    eff_tot_y_h(Form("eff_tot_y_h_%s", tail.c_str()), Form("eff_tot_y_%s_h;y^{#mu^{+}#mu^{-}};Acceptance", tail.c_str()), 100, -2.5, 2.5),
    eff_tot_y_pt_h(Form("eff_tot_y_pt_h_%s", tail.c_str()), Form("eff_tot_y_pt_%s_h;y^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5,  100, 0., 100.)

{
  all_pt_h.Sumw2(true);
  all_y_h.Sumw2(true);
  all_y_pt_h.Sumw2(true);

  pas_reco_pt_h.Sumw2(true);
  pas_reco_y_h.Sumw2(true);
  pas_reco_y_pt_h.Sumw2(true);

  pas_trig_pt_h.Sumw2(true);
  pas_trig_y_h.Sumw2(true);
  pas_trig_y_pt_h.Sumw2(true);

  tree->SetBranchStatus("*", 0);
  tree->SetBranchStatus("nmuons", 1);
  tree->SetBranchStatus("nonia", 1);
  tree->SetBranchStatus("trigger", 1);
  tree->SetBranchStatus("gen_dimuon_p4", 1);
  tree->SetBranchStatus("gen_muonP_p4", 1);
  tree->SetBranchStatus("gen_muonN_p4", 1);
}

effLooper::~effLooper() {
}

bool effLooper::triggerTest() {
  if (  ((trigger & 8) == 8) || ((trigger & 1) == 1) )
    {
    return true;
  }
  return false;
}

void effLooper::doLoop() {
  for (int i = ievent_; i < max_entry; i++) {
    if (i % 100000 == 0) cout << i << " / " << max_entry << endl;
    tree->GetEntry(i);
    if (nmuons <= 2) {

      Double_t gen_dimuon_pt = gen_dimuon_p4->Pt();
      Double_t gen_dimuon_y = gen_dimuon_p4->Rapidity();

      if (acceptanceCut(gen_dimuon_p4, gen_muonP_p4, gen_muonN_p4)) {
        all_y_pt_h.Fill(gen_dimuon_y, gen_dimuon_pt);
        if (nonia==1) {
          pas_reco_y_pt_h.Fill(gen_dimuon_y, gen_dimuon_pt);
          if (triggerTest()) {
            pas_trig_y_pt_h.Fill(gen_dimuon_y, gen_dimuon_pt);
          }
        }
      }
    }
  }
}

void effLooper::doEff() {
  eff_reco_y_pt_h.Divide(&pas_reco_y_pt_h, &all_y_pt_h, 1., 1., "B");
  eff_trig_y_pt_h.Divide(&pas_trig_y_pt_h, &pas_reco_y_pt_h, 1., 1., "B");
  eff_tot_y_pt_h.Divide(&pas_trig_y_pt_h, &all_y_pt_h, 1., 1., "B");

  eff_reco_y_pt_h.SetMaximum(1.);
  eff_reco_y_pt_h.SetMinimum(0.);
  eff_trig_y_pt_h.SetMaximum(1.);
  eff_trig_y_pt_h.SetMinimum(0.);
  eff_tot_y_pt_h.SetMaximum(1.);
  eff_tot_y_pt_h.SetMinimum(0.);
}
