#include "CommonFuncs.h"

bool acceptanceCut(TLorentzVector * gen_dimuon_p4,
                   TLorentzVector * gen_muonP_p4,
                   TLorentzVector * gen_muonN_p4,
                   Meson meson,
                   bool in_barrel) {
  if (meson == JPsi) {
    if ( in_barrel ) {  // barrel
      if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2
          && gen_dimuon_p4->Pt()>10.
          && gen_muonP_p4->Pt()>3.5
          && gen_muonN_p4->Pt()>3.5
          ) {
          return true;
      }
    }
    else { // endcap
      if (gen_dimuon_p4->Pt()>16.
          && (
              ( gen_muonP_p4->Pt()>8.
                && gen_muonN_p4->Pt()>3.5
                )
              ||
              ( gen_muonP_p4->Pt()>3.5
                && gen_muonN_p4->Pt()>8.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Psi2S) {
    if (in_barrel ) {
      if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2
          && gen_dimuon_p4->Pt()>8.
          && gen_muonP_p4->Pt()>3.5
          && gen_muonN_p4->Pt()>3.5
          ) {
        return true;
      }
    }
    else { // endcap
      if (gen_dimuon_p4->Pt()>13.
          && (
              ( gen_muonP_p4->Pt()>7.
                && gen_muonN_p4->Pt()>3.5
                )
              ||
              ( gen_muonP_p4->Pt()>3.5
                && gen_muonN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Ups1S) {
    if (in_barrel ) {
      if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2
          && gen_dimuon_p4->Pt()>8.
          && gen_muonP_p4->Pt()>3.5
          && gen_muonN_p4->Pt()>3.5
          ) {
        return true;
      }
    }
    else { // endcap
      if (gen_dimuon_p4->Pt()>13.
          && (
              ( gen_muonP_p4->Pt()>7.
                && gen_muonN_p4->Pt()>3.5
                )
              ||
              ( gen_muonP_p4->Pt()>3.5
                && gen_muonN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Ups2S) {
    if (in_barrel) {
      if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2
          && gen_dimuon_p4->Pt()>8.
          && gen_muonP_p4->Pt()>3.5
          && gen_muonN_p4->Pt()>3.5
        ) {
        return true;
      }
    }
    else { // endcap
      if (gen_dimuon_p4->Pt()>13.
          && (
              ( gen_muonP_p4->Pt()>7.
                && gen_muonN_p4->Pt()>3.5
                )
              ||
              ( gen_muonP_p4->Pt()>3.5
                && gen_muonN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Ups3S) {
    if (in_barrel) {
      if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2
          && gen_dimuon_p4->Pt()>8.
          && gen_muonP_p4->Pt()>3.5
          && gen_muonN_p4->Pt()>3.5
          ) {
        return true;
      }
    }
    else { // endcap
      if (gen_dimuon_p4->Pt()>13.
          && (
              ( gen_muonP_p4->Pt()>7.
                && gen_muonN_p4->Pt()>3.5
                )
              ||
              ( gen_muonP_p4->Pt()>3.5
                && gen_muonN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  return false;
}
