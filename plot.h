#ifndef PLOT_H
#define PLOT_H

#include "TCanvas.h"
#include "TList.h"
#include "TH1D.h"
#include "TH2D.h"

#include <string>
#include <vector>
#include <memory>

using namespace std;

class plot {
 public:
  plot(string name, int x = 600, int y = 600);
  ~plot();

  void plot1D(TH1D * h);
  void plot2D(TH2D * h, string options = "COL");

  void setTail(string newTail) {tail = newTail;};
  void setDir(string newDir) {dir = newDir;};

  void add(TH1D h1);
  void plotAll();

 private:
  string name_;
  string tail;
  string dir;
  shared_ptr <TCanvas> c;

  vector <TH1D > Hists;

};


#endif
