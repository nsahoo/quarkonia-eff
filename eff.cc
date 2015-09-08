#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TMath.h"

#include "effLooper.h"
#include "plot.h"
#include "options.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

void plot2D(TH2D * h) {
    plot plot2D(h->GetName());
    plot2D.setDir("./plots/eff/");
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

  effLooper DimuonEff(inputfile, tail, meson, -1, 0, barrel);
  DimuonEff.doLoop();
  DimuonEff.doEff();

  TH2D recoEff = DimuonEff.getRecoEff();
  TH2D trigEff = DimuonEff.getTrigEff();
  TH2D totEff = DimuonEff.getTotEff();
  plot2D(&recoEff);
  plot2D(&trigEff);
  plot2D(&totEff);

  return EXIT_SUCCESS;
}
