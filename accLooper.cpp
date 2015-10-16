#include "accLooper.h"

accLooper::accLooper(string ttree_file, string tail, Meson meson, int nevent, int ievent,bool barrel)
  : treeLooper(ttree_file, tail, meson, nevent, ievent),
    barrel_(barrel),
    all_pt_h(Form("all_pt_h_%s", tail.c_str()), Form("all_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Alleptance", tail.c_str()), nb_pt_, 0., 100.),
    all_y_h(Form("all_y_h_%s", tail.c_str()), Form("all_y_%s_h;|y^{#mu^{+}#mu^{-}}|;Alleptance", tail.c_str()), nb_y_, rapmin_, rapmax_),
    all_y_pt_h(Form("all_y_pt_h_%s", tail.c_str()), Form("all_y_pt_%s_h;|y^{#mu^{+}#mu^{-}}|;p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), nb_y_, rapmin_, rapmax_,  nb_pt_, 0., 100.),

    pas_pt_h(Form("pas_pt_h_%s", tail.c_str()), Form("pas_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Paseptance", tail.c_str()), nb_pt_, 0., 100.),
    pas_y_h(Form("pas_y_h_%s", tail.c_str()), Form("pas_y_%s_h;|y^{#mu^{+}#mu^{-}}|;Paseptance", tail.c_str()), nb_y_, rapmin_, rapmax_),
    pas_y_pt_h(Form("pas_y_pt_h_%s", tail.c_str()), Form("pas_y_pt_%s_h;|y^{#mu^{+}#mu^{-}}|;p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), nb_y_, rapmin_, rapmax_,  nb_pt_, 0., 100.),

    acc_pt_h(Form("acc_pt_h_%s", tail.c_str()), Form("acc_pt_%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);Acceptance", tail.c_str()), nb_pt_, 0., 100.),
    acc_y_h(Form("acc_y_h_%s", tail.c_str()), Form("acc_y_%s_h;|y^{#mu^{+}#mu^{-}}|;Acceptance", tail.c_str()), nb_y_, rapmin_, rapmax_),
    acc_y_pt_h(Form("acc_y_pt_h_%s", tail.c_str()), Form("acc_y_pt_%s_h;|y^{#mu^{+}#mu^{-}}|;p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), nb_y_, rapmin_, rapmax_,  nb_pt_, 0., 100.),
    err_acc_y_pt_h(Form("err_acc_y_pt_h_%s", tail.c_str()), Form("err_acc_y_pt_%s_h;|y^{#mu^{+}#mu^{-}}|;p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), nb_y_, rapmin_, rapmax_,  nb_pt_, 0., 100.)

{

  all_pt_h.Sumw2(true);
  all_y_h.Sumw2(true);
  all_y_pt_h.Sumw2(true);

  pas_pt_h.Sumw2(true);
  pas_y_h.Sumw2(true);
  pas_y_pt_h.Sumw2(true);

  tree->SetBranchStatus("*", 0);
  tree->SetBranchStatus("nmuons", 1);
  tree->SetBranchStatus("gen_dimuon_p4", 1);
  tree->SetBranchStatus("gen_muonP_p4", 1);
  tree->SetBranchStatus("gen_muonN_p4", 1);
}

accLooper::~accLooper() {
}



void accLooper::doLoop() {
  for (int i = ievent_; i < max_entry; i++) {
    if ((i%(max_entry/10)) == 0) cout << i << " / " << max_entry << endl;
    tree->GetEntry(i);
    //if (nmuons <= 2) {

      Double_t gen_dimuon_pt = gen_dimuon_p4->Pt();
      Double_t gen_dimuon_y = TMath::Abs(gen_dimuon_p4->Rapidity());

      all_y_pt_h.Fill(gen_dimuon_y, gen_dimuon_pt);

      if (acceptanceCut(gen_dimuon_p4, gen_muonP_p4, gen_muonN_p4, meson_, barrel_)) {
        pas_y_pt_h.Fill(gen_dimuon_y, gen_dimuon_pt);
      }
    //}
  }
}

void accLooper::doAcc() {
  acc_y_pt_h.Divide(&pas_y_pt_h, &all_y_pt_h, 1., 1., "B");

  acc_y_pt_h.SetMaximum(1.);
  acc_y_pt_h.SetMinimum(0.);

}

void accLooper::doAccErr() {
  Double_t e;
  Int_t nx = acc_y_pt_h.GetNbinsX();
  Int_t ny = acc_y_pt_h.GetNbinsY();

  for (Int_t i=1; i<nx; i++){
     for (Int_t j=1; j<ny; j++){
        e = acc_y_pt_h.GetBinError(i,j);
        err_acc_y_pt_h.SetBinContent(i,j,e);
        err_acc_y_pt_h.SetBinError(i,j,0.);
     }
  }

  err_acc_y_pt_h.SetMaximum(1.);
  err_acc_y_pt_h.SetMinimum(0.);

}

