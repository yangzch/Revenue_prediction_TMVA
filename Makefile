CXX           = g++

INCLUDEDIR       = ./
CXX	         += -I$(INCLUDEDIR)


ROOTFLAGS = $(shell root-config --cflags)
ROOTLIBS  = $(shell root-config --libs)

TMVADIR   = /home/zongchang/software/root/include/TMVA
ROOTFLAGS += -I$(TMVADIR)
ROOTLIBS  += -lTMVA

#Objects = ntuple.o
all: TMVARegression TMVARegressionApplication 


TMVARegression: TMVARegression.cxx
	$(CXX) -o $@ TMVARegression.cxx $(ROOTFLAGS) $(ROOTLIBS)


TMVARegressionApplication: TMVARegressionApplication.cxx
	$(CXX) -o $@ TMVARegressionApplication.cxx $(ROOTFLAGS) $(ROOTLIBS)


