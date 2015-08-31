#ifndef ACCCUT_H
#define ACCCUT_H

#include "TLorentzVector.h"
#include "enums.h"

bool acceptanceCut(TLorentzVector * gen_dimuon_p4,
                   TLorentzVector * gen_muonP_p4,
                   TLorentzVector * gen_muonN_p4,
                   Meson meson = JPsi);
#endif
