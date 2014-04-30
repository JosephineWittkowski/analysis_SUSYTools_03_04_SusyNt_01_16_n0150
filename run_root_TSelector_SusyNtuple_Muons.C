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


void run_root_TSelector_SusyNtuple_Muons() {

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

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04/RootCore");
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
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165423/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165447/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165507/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165547/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165619/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165710/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165732/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165801/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165829/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165907/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165935/*");
      //-------------------------------
      //======================================             2                                  ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170005/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051736/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212230/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212332/*");   
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212411/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170128/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170157/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170223/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170245/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170315/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051801/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170353/*");
      //-------------------------------
//======================================             3                                 ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170420/*");      
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170458/*");  
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170524/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170550/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170614/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170645/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051836/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212549/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170738/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170757/*");
      //-------------------------------
      //======================================             4                                 ============================================================================================
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170819/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170844/*");    
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170905/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170956/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171047/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171104/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171121/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171154/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171226/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171251/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171315/*");
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171342/*");
//       //-------------------------------
     //======================================             5                                  ============================================================================================
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171402/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171419/*");  
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171442/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171503_rev117460/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171521/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171541/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171559/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171646/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130710002540/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171724/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171804/*");
      //-------------------------------
      //======================================             6                                  ============================================================================================
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171839/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171907/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171941/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172025/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172123/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709052308/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709213130/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172211/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172233/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172252/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172319/*");


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

