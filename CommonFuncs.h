#ifndef ACCCUT_H
#define ACCCUT_H

#include "TLorentzVector.h"
#include "enums.h"

bool acceptanceCut(TLorentzVector * dimu_p4,
                   TLorentzVector * muP_p4,
                   TLorentzVector * muN_p4,
                   Meson meson = JPsi,
                   bool in_barrel = false);
#endif
