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


void run_TSelector_SusyNtuple_n0150_WZ() {

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

      gSystem->Setenv("ROOTCOREDIR", "/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");

      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "TSelector_SusyNtuple"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      
      ch = new TChain("susyNt");

      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");

ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.179974.Sherpa_CT10_lllnu_WZ_MassiveCB.SusyNt.e2203_s1581_s1586_r4485_r4540_p1512_n0150.140208030336/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.179974.Sherpa_CT10_lllnu_WZ_MassiveCB.SusyNt.e2203_s1581_s1586_r4485_r4540_p1512_n0150.140210094749/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.179975.Sherpa_CT10_lnununu_WZ_MassiveCB.SusyNt.e2203_s1581_s1586_r4485_r4540_p1512_n0150.140209021518/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183585.Sherpa_CT10_ZWtoeeqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023333/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183587.Sherpa_CT10_ZWtomumuqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023447/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183589.Sherpa_CT10_ZWtotautauqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023557/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183591.Sherpa_CT10_ZWtonunuqq_MassiveCB.SusyNt.e2463_s1581_s1586_r4485_r4540_p1512_n0150.140208030751/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183735.Sherpa_CT10_WZtoenuqq_MassiveCB.SusyNt.e2347_s1581_s1586_r4485_r4540_p1512_n0150.140209021820/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183737.Sherpa_CT10_WZtomunuqq_MassiveCB.SusyNt.e2347_s1581_s1586_r4485_r4540_p1512_n0150.140209021919/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183739.Sherpa_CT10_WZtotaunuqq_MassiveCB.SusyNt.e2347_s1581_s1586_r4485_r4540_p1512_n0150.140208031157/*");      
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.167007.MadGraphPythia_AUET2BCTEQ6L1_ZWWStar_lllnulnu.SusyNt.e1466_s1499_s1504_r3658_r3549_p1512_n0150.131227064602/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.177999.Sherpa_CT10_llnunu_ZZ_MassiveCB.SusyNt.e2136_s1581_s1586_r4485_r4540_p1512_n0150.140209021344/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183586.Sherpa_CT10_ZZtoeeqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023409/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183588.Sherpa_CT10_ZZtomumuqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023522/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.183590.Sherpa_CT10_ZZtotautauqq_MassiveCB.SusyNt.e2370_s1581_s1586_r4485_r4540_p1512_n0150.140129023630/*");

ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.126894.Sherpa_CT10_llll_ZZ.SusyNt.e2399_s1581_s1586_r4485_r4540_p1512_n0150.140130221248/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.167008.MadGraphPythia_AUET2BCTEQ6L1_ZZZStar_nunullll.SusyNt.e1466_s1499_s1504_r3658_r3549_p1512_n0150.131227064651/*");
ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0150/WZ/user.gerbaudo.mc12_8TeV.179396.gg2ZZJimmy_AUET2CT10_ZZ4lep_2lepFilt.SusyNt.e2279_s1499_s1504_r3658_r3549_p1512_n0150.131227073603/*");





      

	    


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

