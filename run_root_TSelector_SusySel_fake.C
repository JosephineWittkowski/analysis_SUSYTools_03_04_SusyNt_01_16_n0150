// Ask me if you have questions/problems. Thomas M.
// Version 0.1.5
// Start with root runSelector.C
// please read all comments with // !!! up to line 115
// You have to make some changes at various places
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TBranch.h"
#include "TFileCollection.h"


#include <TH2.h>
#include <map>
#include <TColor.h>
#include <TH1.h>
#include <TTree.h>
#include <TNtuple.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <sstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h> 
#include <iostream>
#include <math.h>
#include "string.h"
#include "TSystem.h"
#include "TProof.h"
#include "TDSet.h"
#include "TError.h" // for debugging with ddd

void throwException(string str){
	// necessary because cint does not handle thrown errors correctly
	cout <<"Exception raised "<< str<<endl;
	throw(str);
	abort();
}; 


void run_root_TSelector_SusySel_fake(TString InputPath) {


    
      cout<<"Have you set up RootCore via  \"source RootCore/scripts/setup.sh\" ?"<<endl;  

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");
//       gROOT->ProcessLine("#include <vector>");
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "SusySel"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      ch = new TChain("SusySel");


      TString processLine = ".L " + selectorName + ".C++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
//       ch->Add(InputPath);

      ch->Add("/data/etp3/jwittkow/analysis_SUSYTools_03_04/Egamma_skimslim_SusySel.root");
      ch->Add("/data/etp3/jwittkow/analysis_SUSYTools_03_04/Muons_skimslim_SusySel.root");



      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;
      
      ch->Process("SusySel.C+g");
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

