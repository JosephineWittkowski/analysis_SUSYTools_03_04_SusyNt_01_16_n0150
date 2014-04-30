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


void run_TSelector_SusyNtuple_Truth_n0150_ZV() {

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

      TString selectorName = "TSelector_SusyNtuple_Truth"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      
      ch = new TChain("susyNt");

      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
//       ch->Add(InputPath);
      
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129477.PowhegPythia8_WZ_Wm11Z11_mll0p250d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227021043/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129478.PowhegPythia8_WZ_Wm11Z13_mll0p4614d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227021123/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129479.PowhegPythia8_WZ_Wm11Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227021259/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129480.PowhegPythia8_WZ_Wm13Z11_mll0p250d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227021431/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129481.PowhegPythia8_WZ_Wm13Z13_mll0p4614d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227021513/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129482.PowhegPythia8_WZ_Wm13Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227021639/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129483.PowhegPythia8_WZ_Wm15Z11_mll0p250d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227021854/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129484.PowhegPythia8_WZ_Wm15Z13_mll0p4614d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227022109/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129485.PowhegPythia8_WZ_Wm15Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227022321/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129486.PowhegPythia8_WZ_W11Z11_mll0p250d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.140108191016/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129487.PowhegPythia8_WZ_W11Z13_mll0p4614d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.140108191133/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129488.PowhegPythia8_WZ_W11Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227022657/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129489.PowhegPythia8_WZ_W13Z11_mll0p250d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227022831/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129490.PowhegPythia8_WZ_W13Z13_mll0p4614d0_2L5.SusyNt.e1300_s1469_s1470_r3542_r3549_p1512_n0150.131227022915/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129491.PowhegPythia8_WZ_W13Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227023042/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129492.PowhegPythia8_WZ_W15Z11_mll0p250d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.140109025018/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129493.PowhegPythia8_WZ_W15Z13_mll0p4614d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227023518/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.129494.PowhegPythia8_WZ_W15Z15_mll3p804d0_2L5.SusyNt.e2372_s1469_s1470_r3542_r3549_p1512_n0150.131227023736/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.SusyNt.e1466_s1499_s1504_r3658_r3549_p1512_n0150.131227064602/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.SusyNt.e1466_s1499_s1504_r3658_r3549_p1512_n0150.131227064651/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183585.Sherpa_CT10_ZWtoeeqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023333/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183586.Sherpa_CT10_ZZtoeeqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023409/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183587.Sherpa_CT10_ZWtomumuqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023447/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183588.Sherpa_CT10_ZZtomumuqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023522/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183589.Sherpa_CT10_ZWtotautauqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023557/*");
      ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183590.Sherpa_CT10_ZZtotautauqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023630/*");

      
      

	    


      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;


      TSelector_SusyNtuple_Truth* SusyNtupleObject = new TSelector_SusyNtuple_Truth();
//       SusyNtupleObject->buildSumwMap(ch);
//       TString options="NtSys_NOM";
      ch->Process(SusyNtupleObject);
      delete SusyNtupleObject;
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

