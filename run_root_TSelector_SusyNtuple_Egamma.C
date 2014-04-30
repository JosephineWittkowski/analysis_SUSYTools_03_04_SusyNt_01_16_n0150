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


void run_root_TSelector_SusyNtuple_Egamma() {

//  TString options = TString(""); //TString(tag.c_str()) ;
// //     TString outputfile = "test.root";
//     string richtigerString = InputPath;
// //     int Position = richtigerString.find("mc12_8TeV.");
// //     outputfile = "histos_ZTauTau_" +  richtigerString.substr(Position+10,6)  + "_proof.root";
//     
//     int Position = -1;
//     Position = richtigerString.find("45_bg");
//     if (Position>0){
//       outputfile = "histos_test_" +  richtigerString.substr(Position+6,2)  + ".root";
//     }
//     else{
//       Position = richtigerString.find("45_signal");
//       if (Position>0){
//       outputfile = "histos_test_" +  richtigerString.substr(Position+3,2)  + ".root";
//       }
//     }
//     if(outputfile == ""){
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       cout << "EMPTY OUPTPUTFILE STRING" << endl;
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       abort();
//     }
//     cout << "outputfile= " << outputfile << endl;
    
      cout<<"Have you set up RootCore via  \"source RootCore/scripts/setup.sh\" ?"<<endl;  

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04_Egamma/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");

      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "TSelector_SusyNtuple"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;

      ch = new TChain("susyNt");


      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
   //======================================             1                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161315/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161341/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161402/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161438/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161523/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161605/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161633/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161714/*");
//---------------------------      
      //======================================             2                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161844/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161941/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162006/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162029/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162345/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162454/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001418/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162600/*");
      //---------------------------
      //======================================             3                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162701/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163028/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163147/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163249/*");      
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001607/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001635/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163344/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163424/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163609/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163708/*");      
      //---------------------------
      //======================================             4                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163819/*");  
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163947/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164048/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001810/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164142/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164215/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164247/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164312/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164417/*");
//       ---------------------------
      //======================================             5                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164445/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164506/*"); 
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164536/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164607/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709051000/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709211606/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164723/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164818/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164908/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164947/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165040/*");
      //---------------------------
      //======================================             6                                 ============================================================================================
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709051609/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709211909/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165112/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165144/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165203/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165221/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165250/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165406/*");


      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;


      TSelector_SusyNtuple* susyAna = new TSelector_SusyNtuple();
      susyAna->buildSumwMap(ch);
      ch->Process(susyAna);
      delete susyAna;
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

