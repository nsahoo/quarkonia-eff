ROOTCFLAGS    = $(shell root-config --cflags)
ROOTGLIBS     = $(shell root-config --glibs)

CXX           = clang++
CXXFLAGS      = -fPIC -ansi -D_GNU_SOURCE -O2 -Wall -Wextra
#LDFLAGS       = -g3

ROOTLIBSFILTERED  = $(filter-out -lNew, $(ROOTGLIBS))

INCLUDEDIR       = ./
CXX	         += -I$(INCLUDEDIR)

###########
# TARGETS #
###########

all: quarkonia

quarkonia: quarkonia.cc ptLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o quarkonia  $(ROOTLIBSFILTERED) quarkonia.cc treeLooper ptLooper plot

treeLooper: treeLooper.cpp
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o treeLooper  treeLooper.cpp

ptLooper: ptLooper.cpp treeLooper
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o ptLooper ptLooper.cpp

plot: plot.cc
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o plot  plot.cc

clean:
	rm -rf quarkonia treeLooper ptLooper plot
