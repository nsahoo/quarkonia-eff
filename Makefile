ROOTCFLAGS    = $(shell root-config --cflags)
ROOTGLIBS     = $(shell root-config --glibs)

CXX           = g++
CXXFLAGS      = -fPIC -ansi -D_GNU_SOURCE -O2 -Wall -Wextra
CXXDEBUG      = -O -g

ifeq ($(DEB),1)
	CXXFLAGS += $(CXXDEBUG)
endif

ROOTLIBSFILTERED  = $(filter-out -lNew, $(ROOTGLIBS))

###########
# TARGETS #
###########

all: acc eff #effSingle

acc: acc.cc accLooper plot options
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o acc  $(ROOTLIBSFILTERED) acc.cc treeLooper.o accLooper.o CommonFuncs.o plot.o options.o

eff: eff.cc effLooper plot options
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o eff  $(ROOTLIBSFILTERED) eff.cc treeLooper.o effLooper.o CommonFuncs.o plot.o options.o

#effSingle: effSingle.cc effSingleLooper plot
#	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o effSingle  $(ROOTLIBSFILTERED) effSingle.cc treeLooper.o effSingleLooper.o CommonFuncs.o plot.o

quarkonia: quarkonia.cc ptLooper plot
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) -o quarkonia  $(ROOTLIBSFILTERED) quarkonia.cc treeLooper.o ptLooper.o plot.o

treeLooper: treeLooper.cpp
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o treeLooper.o treeLooper.cpp

ptLooper: ptLooper.cpp treeLooper
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o ptLooper.o ptLooper.cpp

accLooper: accLooper.cpp treeLooper CommonFuncs
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o accLooper.o accLooper.cpp

effLooper: effLooper.cpp treeLooper CommonFuncs
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o effLooper.o effLooper.cpp

effSingleLooper: effSingleLooper.cpp treeLooper CommonFuncs
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o effSingleLooper.o effSingleLooper.cpp

plot: plot.cc
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o plot.o plot.cc

CommonFuncs: CommonFuncs.cpp
	$(CXX) -c $(CXXFLAGS) $(ROOTCFLAGS) -o CommonFuncs.o CommonFuncs.cpp

options: options.cc
	$(CXX) -c $(CXXFLAGS) -o options.o options.cc

clean:
	rm -rf quarkonia acc treeLooper.o ptLooper.o plot.o accLooper.o CommonFuncs.o eff effLooper.o effSingle effSingleLooper.o options.o
