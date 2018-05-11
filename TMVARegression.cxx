#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream> 
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

int main( int argc, char** argv ) 
{

   //gRandom->SetSeed(0);

   //---------------------------------------------------------------
   // Default MVA methods to be trained + tested
   std::map<std::string,int> Use;

   // --- Mutidimensional likelihood and Nearest-Neighbour methods
   Use["PDERS"]           = 0;
   Use["PDEFoam"]         = 0; 
   Use["KNN"]             = 0;
   // 
   // --- Linear Discriminant Analysis
   Use["LD"]		  = 0;
   // 
   // --- Function Discriminant analysis
   Use["FDA_GA"]          = 0;
   Use["FDA_MC"]          = 0;
   Use["FDA_MT"]          = 0;
   Use["FDA_GAMT"]        = 0;
   // 
   // --- Neural Network
   Use["MLP"]             = 1; 
   // 
   // --- Support Vector Machine 
   Use["SVM"]             = 0;
   // 
   // --- Boosted Decision Trees
   Use["BDT"]             = 0;
   Use["BDTG"]            = 0;
   // ---------------------------------------------------------------

   std::cout << std::endl;
   std::cout << "==> Start TMVARegression" << std::endl;

   // Select methods (don't look at this code - not of interest)

   std::cout << "Running the following methods" << std::endl;
   if (argc>1) {
      for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) it->second = 0;
   }
   for (int i=1; i<argc; i++) {
      std::string regMethod(argv[i]);
      if (Use.find(regMethod) == Use.end()) {
         std::cout << "Method " << regMethod << " not known in TMVA under this name. Please try one of:" << std::endl;
         for (std::map<std::string,int>::iterator it = Use.begin(); it != Use.end(); it++) std::cout << it->first << " ";
         std::cout << std::endl;
         return 1;
      }
      Use[regMethod] = kTRUE;
   }

   // --- Here the preparation phase begins

   // Create a new root output file
   TString outfileName( "TMVAReg.root" );
   TFile* outputFile = TFile::Open( outfileName, "RECREATE" );

   // Create the factory object. Later you can choose the methods
   // whose performance you'd like to investigate. The factory will
   // then run the performance analysis for you.
   //
   // The first argument is the base of the name of all the
   // weightfiles in the directory weight/ 
   //
   // The second argument is the output file for the training results
   // All TMVA output can be suppressed by removing the "!" (not) in 
   // front of the "Silent" argument in the option string
   TMVA::Factory *factory = new TMVA::Factory( "TMVARegression", outputFile, 
                                               "!V:!Silent:Color:DrawProgressBar" );

   // If you wish to modify default settings 
   // (please check "src/Config.h" to see all available global options)
   //    (TMVA::gConfig().GetVariablePlotting()).fTimesRMS = 8.0;
   //    (TMVA::gConfig().GetIONames()).fWeightFileDir = "myWeightDirectory";

   // Define the input variables that shall be used for the MVA training
   // note that you may also use variable expressions, such as: "3*var1/var2*abs(var3)"
   // [all types of expressions that can also be parsed by TTree::Draw( "expression" )]
   //factory->AddVariable( "NN_date[4]", "Variable NN_date[4]", "units", 'I' );
   factory->AddVariable( "days", "Variable days", "units", 'F' );
   factory->AddVariable( "bigcity", "Variable bigcity", "units", 'F' );
   factory->AddVariable( "smallcity", "Variable smallcity", "units", 'F' );
   factory->AddVariable( "fctype", "Variable fctype", "units", 'F' );
   factory->AddVariable( "iltype", "Variable iltype", "units", 'F' );
   factory->AddVariable( "dttype", "Variable dttype", "units", 'F' );
   //factory->AddVariable( "mbtype", "Variable mbtype", "units", 'F' );
   factory->AddVariable( "P1", "Variable P1", "units", 'F' );
   factory->AddVariable( "P2", "Variable P2", "units", 'F' );
   factory->AddVariable( "P3", "Variable P3", "units", 'F' );
   factory->AddVariable( "P4", "Variable P4", "units", 'F' );
   factory->AddVariable( "P5", "Variable P5", "units", 'F' );
   factory->AddVariable( "P6", "Variable P6", "units", 'F' );
   factory->AddVariable( "P7", "Variable P7", "units", 'F' );
   factory->AddVariable( "P8", "Variable P8", "units", 'F' );
   factory->AddVariable( "P9", "Variable P9", "units", 'F' );
   factory->AddVariable( "P10", "Variable P10", "units", 'F' );
   factory->AddVariable( "P11", "Variable P11", "units", 'F' );
   factory->AddVariable( "P12", "Variable P12", "units", 'F' );
   factory->AddVariable( "P13", "Variable P13", "units", 'F' );
   factory->AddVariable( "P14", "Variable P14", "units", 'F' );
   factory->AddVariable( "P15", "Variable P15", "units", 'F' );
   factory->AddVariable( "P16", "Variable P16", "units", 'F' );
   factory->AddVariable( "P17", "Variable P17", "units", 'F' );
   factory->AddVariable( "P18", "Variable P18", "units", 'F' );
   factory->AddVariable( "P19", "Variable P19", "units", 'F' );
   factory->AddVariable( "P20", "Variable P20", "units", 'F' );
   factory->AddVariable( "P21", "Variable P21", "units", 'F' );
   factory->AddVariable( "P22", "Variable P22", "units", 'F' );
   factory->AddVariable( "P23", "Variable P23", "units", 'F' );
   factory->AddVariable( "P24", "Variable P24", "units", 'F' );
   factory->AddVariable( "P25", "Variable P25", "units", 'F' );
   factory->AddVariable( "P26", "Variable P26", "units", 'F' );
   factory->AddVariable( "P27", "Variable P27", "units", 'F' );
   factory->AddVariable( "P28", "Variable P28", "units", 'F' );
   factory->AddVariable( "P29", "Variable P29", "units", 'F' );
   factory->AddVariable( "P30", "Variable P30", "units", 'F' );
   factory->AddVariable( "P31", "Variable P31", "units", 'F' );
   factory->AddVariable( "P32", "Variable P32", "units", 'F' );
   factory->AddVariable( "P33", "Variable P33", "units", 'F' );
   factory->AddVariable( "P34", "Variable P34", "units", 'F' );
   factory->AddVariable( "P35", "Variable P35", "units", 'F' );
   factory->AddVariable( "P36", "Variable P36", "units", 'F' );
   factory->AddVariable( "P37", "Variable P37", "units", 'F' );

   // You can add so-called "Spectator variables", which are not used in the MVA training, 
   // but will appear in the final "TestTree" produced by TMVA. This TestTree will contain the 
   // input variables, the response values of all trained MVAs, and the spectator variables
   //factory->AddSpectator( "spec1:=var1*2",  "Spectator 1", "units", 'F' );
   //factory->AddSpectator( "spec2:=var1*3",  "Spectator 2", "units", 'F' );

   // Add the variable carrying the regression target
   factory->AddTarget( "revenue" ); 

   // It is also possible to declare additional targets for multi-dimensional regression, ie:
   //factory->AddTarget( "NN_hlow" );
   // BUT: this is currently ONLY implemented for MLP

   // Read training and test data (see TMVAClassification for reading ASCII files)
   // load the signal and background event samples from ROOT trees
   TFile *input(0);
   TString fname = "/home/zcyang/train/rev/rootdata/train_rp.root";
   if (!gSystem->AccessPathName( fname )) 
      input = TFile::Open( fname ); // check if file in local directory exists
   else 
      input = TFile::Open( "http://root.cern.ch/files/tmva_reg_example.root" ); // if not: download from ROOT server
   
   if (!input) {
      std::cout << "ERROR: could not open data file" << std::endl;
      exit(1);
   }
   std::cout << "--- TMVARegression           : Using input file: " << input->GetName() << std::endl;

   // --- Register the regression tree
   TTree *regTree = (TTree*)input->Get("Features");

   // global event weights per tree (see below for setting event-wise weights)
   Double_t regWeight  = 1.0;   

   // You can add an arbitrary number of regression trees
   factory->AddRegressionTree( regTree, regWeight );

   // This would set individual event weights (the variables defined in the 
   // expression need to exist in the original TTree)
   //factory->SetWeightExpression( "weight", "Regression" );

   // Apply additional cuts on the signal and background samples (can be different)
   TCut mycut = "";

   // tell the factory to use all remaining events in the trees after training for testing:
   factory->PrepareTrainingAndTestTree( mycut,
                                        "nTrain_Regression=100:nTest_Regression=37:SplitMode=Random:NormMode=NumEvents:!V" );

   // If no numbers of events are given, half of the events in the tree are used 
   // for training, and the other half for testing:
   //    factory->PrepareTrainingAndTestTree( mycut, "SplitMode=random:!V" );  

   // ---- Book MVA methods
   //
   // please lookup the various method configuration options in the corresponding cxx files, eg:
   // src/MethoCuts.cxx, etc, or here: http://tmva.sourceforge.net/optionRef.html
   // it is possible to preset ranges in the option string in which the cut optimisation should be done:
   // "...:CutRangeMin[2]=-1:CutRangeMax[2]=1"...", where [2] is the third input variable

   // PDE - RS method
   if (Use["PDERS"])
      factory->BookMethod( TMVA::Types::kPDERS, "PDERS", 
                           "!H:!V:NormTree=T:VolumeRangeMode=Adaptive:KernelEstimator=Gauss:GaussSigma=0.3:NEventsMin=40:NEventsMax=60:VarTransform=None" );
   // And the options strings for the MinMax and RMS methods, respectively:
   //      "!H:!V:VolumeRangeMode=MinMax:DeltaFrac=0.2:KernelEstimator=Gauss:GaussSigma=0.3" );   
   //      "!H:!V:VolumeRangeMode=RMS:DeltaFrac=3:KernelEstimator=Gauss:GaussSigma=0.3" );   

   if (Use["PDEFoam"])
       factory->BookMethod( TMVA::Types::kPDEFoam, "PDEFoam", 
			    "!H:!V:MultiTargetRegression=F:TargetSelection=Mpv:TailCut=0.001:VolFrac=0.0666:nActiveCells=500:nSampl=2000:nBin=5:Compress=T:Kernel=None:Nmin=10:VarTransform=None" );

   // K-Nearest Neighbour classifier (KNN)
   if (Use["KNN"])
      factory->BookMethod( TMVA::Types::kKNN, "KNN", 
                           "nkNN=20:ScaleFrac=0.8:SigmaFact=1.0:Kernel=Gaus:UseKernel=F:UseWeight=T:!Trim" );

   // Linear discriminant
   if (Use["LD"])
      factory->BookMethod( TMVA::Types::kLD, "LD", 
                           "!H:!V:VarTransform=None" );

	// Function discrimination analysis (FDA) -- test of various fitters - the recommended one is Minuit (or GA or SA)
   if (Use["FDA_MC"]) 
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MC",
                          "!H:!V:Formula=(0)+(1)*x0+(2)*x1:ParRanges=(-100,100);(-100,100);(-100,100):FitMethod=MC:SampleSize=100000:Sigma=0.1:VarTransform=D" );
   
   if (Use["FDA_GA"]) // can also use Simulated Annealing (SA) algorithm (see Cuts_SA options) .. the formula of this example is good for parabolas
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GA",
                           "!H:!V:Formula=(0)+(1)*x0+(2)*x1:ParRanges=(-100,100);(-100,100);(-100,100):FitMethod=GA:PopSize=100:Cycles=3:Steps=30:Trim=True:SaveBestGen=1:VarTransform=Norm" );

   if (Use["FDA_MT"]) 
      factory->BookMethod( TMVA::Types::kFDA, "FDA_MT",
                           "!H:!V:Formula=(0)+(1)*x0+(2)*x1:ParRanges=(-100,100);(-100,100);(-100,100);(-10,10):FitMethod=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=2:UseImprove:UseMinos:SetBatch" );

   if (Use["FDA_GAMT"]) 
      factory->BookMethod( TMVA::Types::kFDA, "FDA_GAMT",
                           "!H:!V:Formula=(0)+(1)*x0+(2)*x1:ParRanges=(-100,100);(-100,100);(-100,100):FitMethod=GA:Converger=MINUIT:ErrorLevel=1:PrintLevel=-1:FitStrategy=0:!UseImprove:!UseMinos:SetBatch:Cycles=1:PopSize=5:Steps=5:Trim" );

   // Neural network (MLP)
   if (Use["MLP"])
      factory->BookMethod( TMVA::Types::kMLP, "MLP", "!H:!V:VarTransform=Norm:NeuronType=tanh:NCycles=20000:HiddenLayers=N+20:TestRate=6:TrainingMethod=BFGS:Sampling=0.3:SamplingEpoch=0.8:ConvergenceImprove=1e-6:ConvergenceTests=15:!UseRegulator" );

   // Support Vector Machine
   if (Use["SVM"])
      factory->BookMethod( TMVA::Types::kSVM, "SVM", "Gamma=0.25:Tol=0.001:VarTransform=Norm" );

   // Boosted Decision Trees
   if (Use["BDT"])
     factory->BookMethod( TMVA::Types::kBDT, "BDT",
                           "!H:!V:NTrees=20:MinNodeSize=1.0%:BoostType=AdaBoostR2:SeparationType=RegressionVariance:nCuts=20:PruneMethod=CostComplexity:PruneStrength=30" );

   if (Use["BDTG"])
     factory->BookMethod( TMVA::Types::kBDT, "BDTG",
                           "!H:!V:NTrees=25::BoostType=Grad:Shrinkage=0.1:UseBaggedBoost:BaggedSampleFraction=0.5nCuts=20:MaxDepth=6:MaxDepth=6" );
   // --------------------------------------------------------------------------------------------------

   // ---- Now you can tell the factory to train, test, and evaluate the MVAs

   // Train MVAs using the set of training events
   factory->TrainAllMethods();

   // ---- Evaluate all MVAs using the set of test events
   factory->TestAllMethods();

   // ----- Evaluate and compare performance of all configured MVAs
   factory->EvaluateAllMethods();    

   // --------------------------------------------------------------
   
   // Save the output
   outputFile->Close();

   std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
   std::cout << "==> TMVARegression is done!" << std::endl;      

   delete factory;

   std::cout << std::endl;
   std::cout << "==> Too view the results, launch the GUI: \"root -l TMVARegGui.C\"" << std::endl;
   std::cout << std::endl;
}

