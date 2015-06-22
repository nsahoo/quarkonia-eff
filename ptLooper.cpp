#include "ptLooper.h"

ptLooper::ptLooper(string ttree_file, string tail, int nevent, int ievent) : treeLooper(ttree_file, tail, nevent, ievent),
                                                                             dimuonPt_h(Form("dimuonPt_h_%s", tail.c_str()), Form("dimuonPt%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.),
                                                                             dimuonPt4_h(Form("dimuonPt4_h_%s", tail.c_str()), Form("dimuonPt4%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.),
                                                                             dimuonEta_h(Form("dimuonEta_h_%s", tail.c_str()), Form("dimuonEta%s_h;#eta^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, -2.5, 2.5),
                                                                             dimuonEta4_h(Form("dimuonEta4_h_%s", tail.c_str()), Form("dimuonEta4%s_h;#eta^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 50, -2.5, 2.5),
                                                                             muPN_mass_h(Form("muPN_mass_h_%s", tail.c_str()), Form("muPN_mass%s_h;M^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, 2.4, 4.4),
                                                                             mass_h(Form("mass_h_%s", tail.c_str()), Form("mass%s_h;M^{#mu^{+}#mu^{-}};a.u.", tail.c_str()), 100, 2.4, 4.4),
                                                                             dimuonPtTriggered_h(Form("dimuonPtTriggered_h_%s", tail.c_str()), Form("dimuonPtTriggered%s_h;p^{#mu^{+}#mu^{-}}_{T} (GeV);a.u.", tail.c_str()), 100, 0., 30.),
                                                                             dimuonpteta_h(Form("dimuonpteta_h_%s", tail.c_str()), Form("dimuonpteta_h%s;#eta^{#mu^{+}#mu^{-}};p^{#mu^{+}#mu^{-}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5, 100, 0., 30.),
                                                                             muonpteta_h(Form("muonpteta_h_%s", tail.c_str()), Form("muonpteta_h%s;#eta^{#mu^{#pm}};p^{#mu^{#pm}}_{T} (GeV)", tail.c_str()), 100, -2.5, 2.5, 100, 0., 30.)
{

  dimuonPt_h.Sumw2(true);
  dimuonPt4_h.Sumw2(true);
  dimuonEta_h.Sumw2(true);
  dimuonEta4_h.Sumw2(true);
  muPN_mass_h.Sumw2(true);
  mass_h.Sumw2(true);
  dimuonPtTriggered_h.Sumw2(true);

}



ptLooper::~ptLooper() {
}

void ptLooper::doLoop() {

  for (int i = ievent_; i < max_entry; i++) {
    if (i % 100000 == 0) cout << i << " / " << max_entry << endl;
    tree->GetEntry(i);

    TLorentzVector muPN;
    muPN = *muonP_p4 + *muonN_p4;
    muPN_mass_h.Fill(muPN.M());

    mass_h.Fill(dimuon_p4->M());

    dimuonPt_h.Fill(dimuon_p4->Pt());
    dimuonEta_h.Fill(dimuon_p4->Eta());

    dimuonpteta_h.Fill(dimuon_p4->Eta(), dimuon_p4->Pt());

    muonpteta_h.Fill(muonP_p4->Eta(), muonP_p4->Pt());
    muonpteta_h.Fill(muonN_p4->Eta(), muonN_p4->Pt());

    if (muonP_p4->Pt() > 4. && muonN_p4->Pt()>4.) {
      dimuonPt4_h.Fill(dimuon_p4->Pt());
      dimuonEta4_h.Fill(dimuon_p4->Eta());
    }

    if (simul_Jpsi_trigger(muonP_p4, muonN_p4, dimuon_p4)) {
      dimuonPtTriggered_h.Fill(dimuon_p4->Pt());
    }
  }

  histos1D.push_back(dimuonPt_h);
  histos1D.push_back(dimuonPt4_h);
  histos1D.push_back(dimuonEta_h);
  histos1D.push_back(dimuonEta4_h);
  histos1D.push_back(muPN_mass_h);
  histos1D.push_back(mass_h);
  histos1D.push_back(dimuonPtTriggered_h);

}

bool ptLooper::simul_Jpsi_trigger(TLorentzVector * mu1, TLorentzVector * mu2, TLorentzVector * dimuon) {
  if ( ((mu1->Pt() > 10. && mu2->Pt() > 0.) ||
        (mu2->Pt() > 10. && mu1->Pt() > 0.)) && dimuon->Pt()>16.) return true;

  if ( abs(mu1->Eta())<1.6 && abs(mu2->Eta())<1.6 && dimuon->Pt()>10.) return true;

  return false;

}
