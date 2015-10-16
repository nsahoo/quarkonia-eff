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

void plot2D(TH2D * h) {
    plot plot2D(h->GetName());
    plot2D.setDir("./plots/acc/");
    plot2D.plot2D(h, "COLZ");
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
  DimuonAcc.doAccErr();

  TH2D acc_h = DimuonAcc.getAcc();
  TH2D err_acc_h = DimuonAcc.getAccErr();
  TH2D all_h = DimuonAcc.getAccAll();
  TH2D pas_h = DimuonAcc.getAccPas();
  plot2D(&acc_h);
  plot2D(&err_acc_h);
  plot2D(&all_h);
  plot2D(&pas_h);

  return EXIT_SUCCESS;
}
