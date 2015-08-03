ROOTCFLAGS    = $(shell root-config --cflags)
ROOTGLIBS     = $(shell root-config --glibs)

CXX           = clang++
CXXFLAGS      = -fPIC -ansi -D_GNU_SOURCE -O2 -Wall -Wextra
CXXDEBUG      = -O -g

ifeq ($(DEB),1)
	CXXFLAGS += $(CXXDEBUG)
endif

ROOTLIBSFILTERED  = $(filter-out -lNew, $(ROOTGLIBS))

###########
# TARGETS #
###########

all: acc eff effSingle

acc: acc.cc accLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o acc  $(ROOTLIBSFILTERED) acc.cc treeLooper.o accLooper.o accCut.o plot.o

eff: eff.cc effLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o eff  $(ROOTLIBSFILTERED) eff.cc treeLooper.o effLooper.o accCut.o plot.o

effSingle: effSingle.cc effSingleLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o effSingle  $(ROOTLIBSFILTERED) effSingle.cc treeLooper.o effSingleLooper.o accCut.o plot.o

quarkonia: quarkonia.cc ptLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o quarkonia  $(ROOTLIBSFILTERED) quarkonia.cc treeLooper.o ptLooper.o plot.o

treeLooper: treeLooper.cpp
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o treeLooper.o treeLooper.cpp

ptLooper: ptLooper.cpp treeLooper
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o ptLooper.o ptLooper.cpp

accLooper: accLooper.cpp treeLooper accCut
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o accLooper.o accLooper.cpp

effLooper: effLooper.cpp treeLooper accCut
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o effLooper.o effLooper.cpp

effSingleLooper: effSingleLooper.cpp treeLooper accCut
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o effSingleLooper.o effSingleLooper.cpp

plot: plot.cc
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o plot.o plot.cc

accCut: accCut.cpp
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o accCut.o accCut.cpp

clean:
	rm -rf quarkonia acc treeLooper.o ptLooper.o plot.o accLooper.o accCut.o eff effLooper.o effSingle effSingleLooper.o
