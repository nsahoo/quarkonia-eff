#ifndef PLOT_H
#define PLOT_H

#include "TCanvas.h"
#include "TList.h"
#include "TH1D.h"
#include "TH2D.h"

#include <string>
#include <vector>

using namespace std;

class plot {
 public:
  plot(std::string name, int x = 600, int y = 600);
  ~plot();

  void plot1D(TH1D * h);
  void plot2D(TH2D * h, string options = "COL");

  void setTail(std::string newTail) {tail = newTail;};
  void setDir(std::string newDir) {dir = newDir;};

  void add(TH1 *h1);
  void plotAll();

 private:
  TCanvas * c;
  std::string name_;
  std::string tail;
  std::string dir;

  std::vector <TH1 *> Hists;


};


#endif
