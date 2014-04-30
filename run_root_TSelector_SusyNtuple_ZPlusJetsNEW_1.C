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


void run_root_TSelector_SusyNtuple_ZPlusJetsNEW_1() {

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

      TString selectorName = "TSelector_SusyNtuple"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;
      
      ch = new TChain("susyNt");

      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");
      
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147105.AlpgenPythia_Auto_P2011C_ZeeNp0.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130711110642/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147105.AlpgenPythia_Auto_P2011C_ZeeNp0.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130712075048/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147105.AlpgenPythia_Auto_P2011C_ZeeNp0.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130713000355/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147106.AlpgenPythia_Auto_P2011C_ZeeNp1.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130708185230/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147107.AlpgenPythia_Auto_P2011C_ZeeNp2.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130711110708/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147108.AlpgenPythia_Auto_P2011C_ZeeNp3.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130708185306/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147109.AlpgenPythia_Auto_P2011C_ZeeNp4.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130708185318/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147110.AlpgenPythia_Auto_P2011C_ZeeNp5incl.SusyNt.e1879_s1581_s1586_r3658_r3549_p1512_n0145.130708185332/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147113.AlpgenPythia_Auto_P2011C_ZmumuNp0.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130711110756/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147114.AlpgenPythia_Auto_P2011C_ZmumuNp1.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130711110816/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147115.AlpgenPythia_Auto_P2011C_ZmumuNp2.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130711110839/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147116.AlpgenPythia_Auto_P2011C_ZmumuNp3.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130708185453/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147117.AlpgenPythia_Auto_P2011C_ZmumuNp4.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130708185508/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147118.AlpgenPythia_Auto_P2011C_ZmumuNp5incl.SusyNt.e1880_s1581_s1586_r3658_r3549_p1512_n0145.130708185521/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147121.AlpgenPythia_Auto_P2011C_ZtautauNp0.SusyNt.e1881_s1581_s1586_r3658_r3549_p1512_n0145.130710211438/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147121.AlpgenPythia_Auto_P2011C_ZtautauNp0.SusyNt.e1881_s1581_s1586_r3658_r3549_p1512_n0145.130710211503/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147121.AlpgenPythia_Auto_P2011C_ZtautauNp0.SusyNt.e1881_s1581_s1586_r3658_r3549_p1512_n0145.130711110938/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147122.AlpgenPythia_Auto_P2011C_ZtautauNp1.SusyNt.e1881_s1581_s1586_r3658_r3549_p1512_n0145.130711085119/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.147122.AlpgenPythia_Auto_P2011C_ZtautauNp1.SusyNt.e1881_s1581_s1586_r3658_r3549_p1512_n0145.130711111032/*");



//       ch->Add(InputPath);
//       ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_bg_new/WZ_SherpaVVtotautauqq/user.sfarrell.mc12_8TeV.157816.Sherpa_CT10_VVtotautauqq.SusyNt.e1515_s1499_s1504_r3658_r3549_p1512_n0145.130708082025/*");



//       ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161315/user.sfarrell.116519._00003.susyNt.root");
      
//       ch->Add("/data/etp6/jwittkow/SusyNtuple_testdir/126893_n0145/*");
//       ch->Add("/data/etp6/jwittkow/user.gerbaudo.mc12_8TeV.126893.Sherpa_CT10_lllnu_WZ.SusyNt.e1434_s1499_s1504_r3658_r3549_p1512_n0145dev4.131220015824/*");
      
//       ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_bg_new/ttbar105200/*");

//             ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_signal_samples/user.gerbaudo.mc12_8TeV.177503.Herwigpp_sM_wA_noslep_notauhad_WH_2Lep_3.SusyNt.e2149_s1581_s1586_r3658_r3549_p1512_n0145.130806161345/user.gerbaudo.023459._00001.susyNt.root");
      
      

	    


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

