#include "CommonFuncs.h"

bool acceptanceCut(TLorentzVector * dimu_p4,
                   TLorentzVector * muP_p4,
                   TLorentzVector * muN_p4,
                   Meson meson,
                   bool in_barrel) {
  if (meson == JPsi) {
    if ( in_barrel ) {  // barrel
      if (//TMath::Abs(dimu_p4->Rapidity())<1.2 &&
             dimu_p4->Pt()>10.
          && muP_p4->Pt()>3.5
          && muN_p4->Pt()>3.5
          ) {
          return true;
      }
    }
    else { // endcap
      if (dimu_p4->Pt()>16.
          && (
              ( muP_p4->Pt()>8.
                && muN_p4->Pt()>3.5
                )
              ||
              ( muP_p4->Pt()>3.5
                && muN_p4->Pt()>8.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Psi2S) {
    if (in_barrel ) {
      if ( //TMath::Abs(dimu_p4->Rapidity())<1.2 &&
             dimu_p4->Pt()>8.
          && muP_p4->Pt()>3.5
          && muN_p4->Pt()>3.5
          ) {
        return true;
      }
    }
    else { // endcap
      if (dimu_p4->Pt()>13.
          && (
              ( muP_p4->Pt()>7.
                && muN_p4->Pt()>3.5
                )
              ||
              ( muP_p4->Pt()>3.5
                && muN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  if (meson == Ups1S || meson == Ups2S || meson == Ups3S) {
    if (in_barrel ) {
      if (//TMath::Abs(dimu_p4->Rapidity())<1.2 &&
             dimu_p4->Pt()>8.
          && muP_p4->Pt()>4.
          && muN_p4->Pt()>4.
          ) {
        return true;
      }
    }
    else { // endcap
      if (dimu_p4->Pt()>13.
          && (
              ( muP_p4->Pt()>7.
                && muN_p4->Pt()>3.5
                )
              ||
              ( muP_p4->Pt()>3.5
                && muN_p4->Pt()>7.
                )
              )
          ) {
        return true;
      }
    }
  }

  return false;
}
