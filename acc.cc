#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TMath.h"

#include "accLooper.h"
#include "plot.h"
#include "options.h"

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

  options opt(argc, argv);
  // int ievent = opt.get_ievent();
  // int nevent = opt.get_nevent();
  string tail = opt.get_tail();
  string inputfile = opt.get_file();
  Meson meson = opt.get_meson();
  bool barrel = opt.get_barrel();

  accLooper DimuonAcc(inputfile, tail, meson, -1, 0, barrel);
  DimuonAcc.doLoop();
  DimuonAcc.doAcc();

  TH2D acc_h = DimuonAcc.getAcc();
  plot acc_plot(acc_h.GetName());
  acc_plot.setDir("./plots/acc/");
  acc_plot.plot2D(&acc_h, "COLZ");

  return EXIT_SUCCESS;
}
