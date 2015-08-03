#include "accCut.h"

bool acceptanceCut(TLorentzVector * gen_dimuon_p4,
                   TLorentzVector * gen_muonP_p4,
                   TLorentzVector * gen_muonN_p4) {
  if (TMath::Abs(gen_dimuon_p4->Rapidity())<1.2) { // barrel
    if (gen_dimuon_p4->Pt()>10.
        && gen_muonP_p4->Pt()>3.5
        && gen_muonN_p4->Pt()>3.5
        ) {
      return true;
    }
  }
  else { // endcap
    if (gen_dimuon_p4->Pt()>16.
        && (
            ( gen_muonP_p4->Pt()>11.
              && gen_muonN_p4->Pt()>3.5
              )
            ||
            ( gen_muonP_p4->Pt()>3.5
              && gen_muonN_p4->Pt()>11.
              )
            )
        ) {
      return true;
    }
  }
  return false;
}
