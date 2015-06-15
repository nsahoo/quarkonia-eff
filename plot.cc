#include "plot.h"

plot::plot(std::string name, int x, int y) : name_(name), tail(""),
                           dir("./") {
  c = new TCanvas(name_.c_str(), name_.c_str(), x, y);
}

void plot::plot1D(TH1D * h) {
  c->cd();
  h->Draw();
  c->Print(Form("%s/%s%s.pdf", dir.c_str(), name_.c_str(), tail.c_str()));
  h->SaveAs(Form("%s/%s%s.root", dir.c_str(), name_.c_str(), tail.c_str()));
}

void plot::plot2D(TH2D * h, string options) {
  c->cd();
  c->SetGrid(1, 1);
  h->SetStats(0);
  h->Draw(options.c_str());
  c->Print(Form("%s/%s%s.pdf", dir.c_str(), name_.c_str(), tail.c_str()));
  h->SaveAs(Form("%s/%s%s.root", dir.c_str(), name_.c_str(), tail.c_str()));
}

void plot::add(TH1 *h1) {

   if (!h1) return;
   Hists.push_back(h1);
}

void plot::plotAll() {

  c->cd();
  double max = 0;
  for (unsigned int i = 0; i < Hists.size(); i++) {
     if (Hists.at(i)->GetMaximum() > max) max = Hists.at(i)->GetMaximum();
  }
  Hists.at(0)->SetMaximum(1.1*max);
  for (unsigned int i = 0; i < Hists.size(); i++) {
    if (i == 0) Hists.at(i)->Draw();
    else Hists.at(i)->Draw("same");
  }
  std::string title(Hists.at(0)->GetTitle());
  std::size_t found =title.find("dimuonEta4");
  if (found!=std::string::npos) {
    c->BuildLegend(0.3, 0.27, 0.68, 0.48);
  }
  else {
    std::size_t found =title.find("dimuonEta");
    if (found!=std::string::npos) {
      c->BuildLegend(0.3, 0.57, 0.68, 0.78);
    }
    else c->BuildLegend();
  }
  Hists.at(0)->SetTitle("");
  c->Print(Form("%s/%s%s.pdf", dir.c_str(), name_.c_str(), tail.c_str()));

}

plot::~plot() {
}
