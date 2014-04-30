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


void run_TSelector_SusyNtuple_excess_n0150_Muons() {

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

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");

      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "TSelector_SusyNtuple_excess"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      
      ch = new TChain("susyNt");

      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
//       ch->Add(InputPath);
//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WH/user.gerbaudo.mc12_8TeV.177501.Herwigpp_sM_wA_noslep_notauhad_WH_2Lep_1.SusyNt.e2149_s1581_s1586_r3658_r3549_p1512_n0150.140109072637/*");
  
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226151514/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226151758/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226203337/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226151930/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152018/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152109/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152200/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152435/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152553/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131228094336/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131228094828/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131229043510/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231162901/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152650/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152756/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226152856/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226153202/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226153306/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226153515/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226153839/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154050/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154327/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154449/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154558/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131228092743/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131229044511/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231002033/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231164124/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231203925/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231204250/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140101203454/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102190447/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102191229/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102193540/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102195240/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102195507/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102201509/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140104001555/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140104003250/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154751/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226154935/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155030/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155124/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155347/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131228132319/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131229044707/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231003808/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231205008/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155532/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155716/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226203514/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231004055/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231004157/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226155900/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226160318/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226160415/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226160625/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131226204922/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231004955/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231164816/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.131231205647/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140101204812/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102060848/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102202402/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102202542/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0150.140102203341/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226160717/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226160944/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161045/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226211026/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131231005410/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161154/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161416/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161525/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161643/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226161755/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226162025/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226162152/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226205607/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131231010554/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131231165146/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226162404/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226162457/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131226162705/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131228130740/*");
    ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/Muons/user.gerbaudo.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0150.131231011056/*");

  

     

	    


      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;


      TSelector_SusyNtuple_excess* SusyNtupleObject = new TSelector_SusyNtuple_excess();
      SusyNtupleObject->buildSumwMap(ch);
//       TString options="NtSys_NOM";
      ch->Process(SusyNtupleObject);
      delete SusyNtupleObject;
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

