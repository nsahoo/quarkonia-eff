#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TMath.h"

#include "accLooper.h"
#include "plot.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector <int> colors = {2, 4, 1, 6, 8};

void beauty_h(TH1 * histo, unsigned int i) {
  histo->Scale(1./histo->GetEntries());
  if (i > colors.size()) {
    cout << "not known color: " << i << endl;
    exit(1);
  }
  histo->SetLineColor(colors.at(i));
  histo->SetStats(false);
  histo->SetLineWidth(2);
}

int main(int argc, char **argv) {

  vector<pair<string, string> > dimuons;
  dimuons.push_back(make_pair("inputs/rootuple-Onia2MuMu_JPsiMM-PGun-PtFlat-NF.root", "JPsi"));

  vector <plot> plots;
  vector <TH1D> histos;

  for (unsigned int i = 0; i < dimuons.size(); i++) { // for each different dimuon
    accLooper DimuonAcc(dimuons.at(i).first, dimuons.at(i).second);
    DimuonAcc.doLoop();
    DimuonAcc.doAcc();

    TH2D acc_h = DimuonAcc.getAcc();
    plot acc_plot(acc_h.GetName());
    acc_plot.setDir("./plots/acc/");
    acc_plot.plot2D(&acc_h, "COLZ");
  }


  // for (unsigned int  i = 0; i < plots.size(); i++ ) {
  //   plots.at(i).plotAll();
  // }

  return EXIT_SUCCESS;
}
