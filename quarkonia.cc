#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TMath.h"

#include "ptLooper.h"
#include "plot.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

vector <int> colors = {2, 4, 1};

void beauty_h(TH1 * histo, int i) {
  histo->Scale(1./histo->GetEntries());
  histo->SetLineColor(colors.at(i));
  histo->SetStats(false);
  histo->SetLineWidth(2);
}

int main(int argc, char **argv) {

  vector <string> inputFiles = {"/Users/lucamartini/Downloads/PsiMM-dataset-skim-pthat1.root",
                                "/Users/lucamartini/Downloads/PsiMM-dataset-skim-pthat2.root",
                                "/Users/lucamartini/Downloads/PsiMM-dataset-skim-pthat5.root"};
  vector <string> tail = {"_pthat1", "_pthat2", "_pthat5"};
  //  vector <string> hname = {"dimuonpt", "dimuonpt4", "dimuoneta", "dimuoneta4", "muPN_mass", "mass"};

  vector <plot*> plots;
  vector <TH1D *> histos;

  for (unsigned int i = 0; i < inputFiles.size(); i++) {
    ptLooper * JpsiHat = new ptLooper(inputFiles.at(i), tail.at(i));
    JpsiHat->doLoop();

    histos = JpsiHat->get_histos1D();

    for (unsigned int j = 0; j < histos.size(); j++ ){
      beauty_h(histos.at(j), i);
      string histo_name(histos.at(j)->GetName());
      size_t found = histo_name.find("_h_");
      if (found != string::npos) {
        histo_name = histo_name.substr(0, found);
      }
      else {
        cout << "histo name must contain _h_ !! " << endl;
        return 1;
      }

      if (i == 0) {
        plot * plot_i = new plot(histo_name);
        plot_i->setDir("./plots/");
        plots.push_back(plot_i);
      }
      plots.at(j)->add(histos.at(j));
    }

    plot * plot2Ddimu = new plot(Form("dimuonpteta%s", tail.at(i).c_str()));
    plot2Ddimu->setDir("./plots/");
    TH2D * histo2Ddimu = JpsiHat->get_dimuonpteta_h();
    histo2Ddimu->Scale(1./histo2Ddimu->GetEntries());
    plot2Ddimu->plot2D(histo2Ddimu, "COLZ");

    plot * plot2Dmu = new plot(Form("muonpteta%s", tail.at(i).c_str()));
    plot2Dmu->setDir("./plots/");
    TH2D * histo2Dmu = JpsiHat->get_muonpteta_h();
    histo2Dmu->Scale(1./histo2Dmu->GetEntries());
    plot2Dmu->plot2D(histo2Dmu, "COLZ");

  }

  for (unsigned int  i = 0; i < plots.size(); i++ ) {
    plots.at(i)->plotAll();
  }




  // print h123

  return EXIT_SUCCESS;
}
