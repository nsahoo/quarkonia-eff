#include "ptLooper.h"

ptLooper::ptLooper(string ttree_file, string tail, int nevent, int ievent) : treeLooper(ttree_file, tail, nevent, ievent)
{

  dimuonPt_h = new TH1D(Form("dimuonPt_h_%s", tail.c_str()), Form("dimuonPt%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.);
  histos1D.push_back(dimuonPt_h);

  dimuonPt4_h = new TH1D(Form("dimuonPt4_h_%s", tail.c_str()), Form("dimuonPt4%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.);
  histos1D.push_back(dimuonPt4_h);

  dimuonEta_h = new TH1D(Form("dimuonEta_h_%s", tail.c_str()), Form("dimuonEta%s_h;#eta^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, -2.5, 2.5);
  histos1D.push_back(dimuonEta_h);

  dimuonEta4_h = new TH1D(Form("dimuonEta4_h_%s", tail.c_str()), Form("dimuonEta4%s_h;#eta^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 50, -2.5, 2.5);
  histos1D.push_back(dimuonEta4_h);

  muPN_mass_h = new TH1D(Form("muPN_mass_h_%s", tail.c_str()), Form("muPN_mass%s_h;M^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, 2.4, 4.4);
  histos1D.push_back(muPN_mass_h);

   mass_h = new TH1D(Form("mass_h_%s", tail.c_str()), Form("mass%s_h;M^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, 2.4, 4.4);
  histos1D.push_back(mass_h);

  dimuonPtTriggered_h = new TH1D(Form("dimuonPtTriggered_h_%s", tail.c_str()), Form("dimuonPtTriggered%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.);
  histos1D.push_back(dimuonPtTriggered_h);

  dimuonpteta_h = new TH2D(Form("dimuonpteta_h_%s", tail.c_str()), Form("dimuonpteta_h%s;#eta^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5, 100, 0., 30.);
  muonpteta_h = new TH2D(Form("muonpteta_h_%s", tail.c_str()), Form("muonpteta_h%s;#eta^{#mu^{#pm}};p^{#mu^{#pm}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5, 100, 0., 30.);

}



ptLooper::~ptLooper() {
  if (dimuonPt_h) delete dimuonPt_h;
}

void ptLooper::doLoop() {

  for (int i = ievent_; i < max_entry; i++) {
    if (i % 100000 == 0) cout << i << " / " << max_entry << endl;
    tree->GetEntry(i);

    TLorentzVector muPN;
    muPN = *muonP_p4 + *muonN_p4;
    muPN_mass_h->Fill(muPN.M());

    mass_h->Fill(dimuon_p4->M());

    dimuonPt_h->Fill(dimuon_p4->Pt());
    dimuonEta_h->Fill(dimuon_p4->Eta());

    dimuonpteta_h->Fill(dimuon_p4->Eta(), dimuon_p4->Pt());

    muonpteta_h->Fill(muonP_p4->Eta(), muonP_p4->Pt());
    muonpteta_h->Fill(muonN_p4->Eta(), muonN_p4->Pt());

    if (muonP_p4->Pt() > 4. && muonN_p4->Pt()>4.) {
      dimuonPt4_h->Fill(dimuon_p4->Pt());
      dimuonEta4_h->Fill(dimuon_p4->Eta());
    }

    if (simul_Jpsi_trigger(muonP_p4, muonN_p4, dimuon_p4)) {
      dimuonPtTriggered_h->Fill(dimuon_p4->Pt());
    }
  }
}

bool ptLooper::simul_Jpsi_trigger(TLorentzVector * mu1, TLorentzVector * mu2, TLorentzVector * dimuon) {
  if ( ((mu1->Pt() > 10. && mu2->Pt() > 0.) ||
        (mu2->Pt() > 10. && mu1->Pt() > 0.)) && dimuon->Pt()>16.) return true;

  if ( abs(mu1->Eta())<1.6 && abs(mu2->Eta())<1.6 && dimuon->Pt()>10.) return true;

  return false;

}
