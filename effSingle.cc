#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TMath.h"

#include "effSingleLooper.h"
#include "plot.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void plot2D(TH2D * h) {
    plot plot2D(h->GetName());
    plot2D.setDir("./plots/effSingle/");
    plot2D.plot2D(h, "COLZ");
}

int main(int argc, char **argv) {

  vector<pair<string, string> > dimuons;
  dimuons.push_back(make_pair("inputs/rootuple-Onia2MuMu_JPsiMM-PGun-PtFlat-NF.root", "JPsi"));

  vector <plot> plots;
  vector <TH1D> histos;

  for (unsigned int i = 0; i < dimuons.size(); i++) { // for each different dimuon
    effSingleLooper MuonEff(dimuons.at(i).first, dimuons.at(i).second);
    MuonEff.doLoop();
    MuonEff.doEff();

    TH2D Eff = MuonEff.getRecoEff();
    plot2D(&Eff);
  }

  return EXIT_SUCCESS;
}
