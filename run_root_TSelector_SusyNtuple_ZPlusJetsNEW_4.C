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


void run_root_TSelector_SusyNtuple_ZPlusJetsNEW_4() {

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
      


ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.SusyNt.e1669_s1581_s1586_r3658_r3549_p1512_n0145.130710080424/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.SusyNt.e1669_s1581_s1586_r3658_r3549_p1512_n0145.130710080445/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.173045.Sherpa_CT10_DYtautauM08to15.SusyNt.e1669_s1581_s1586_r3658_r3549_p1512_n0145.130710215141/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200332.AlpgenPythia_Auto_P2011C_ZeebbNp0.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190110/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190121/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200333.AlpgenPythia_Auto_P2011C_ZeebbNp1.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190136/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190148/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200334.AlpgenPythia_Auto_P2011C_ZeebbNp2.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130713001142/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200335.AlpgenPythia_Auto_P2011C_ZeebbNp3incl.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190200/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200340.AlpgenPythia_Auto_P2011C_ZmumubbNp0.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190212/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190224/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200341.AlpgenPythia_Auto_P2011C_ZmumubbNp1.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130709060631/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200342.AlpgenPythia_Auto_P2011C_ZmumubbNp2.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190236/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200343.AlpgenPythia_Auto_P2011C_ZmumubbNp3incl.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190248/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200348.AlpgenPythia_Auto_P2011C_ZtautaubbNp0.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190300/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200349.AlpgenPythia_Auto_P2011C_ZtautaubbNp1.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190312/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200350.AlpgenPythia_Auto_P2011C_ZtautaubbNp2.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190323/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200351.AlpgenPythia_Auto_P2011C_ZtautaubbNp3incl.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190335/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200432.AlpgenPythia_Auto_P2011C_ZeeccNp0.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190346/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200433.AlpgenPythia_Auto_P2011C_ZeeccNp1.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190400/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200434.AlpgenPythia_Auto_P2011C_ZeeccNp2.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190413/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200435.AlpgenPythia_Auto_P2011C_ZeeccNp3incl.SusyNt.e1930_s1581_s1586_r3658_r3549_p1512_n0145.130708190423/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200440.AlpgenPythia_Auto_P2011C_ZmumuccNp0.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190435/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200441.AlpgenPythia_Auto_P2011C_ZmumuccNp1.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190446/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200442.AlpgenPythia_Auto_P2011C_ZmumuccNp2.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190458/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200443.AlpgenPythia_Auto_P2011C_ZmumuccNp3incl.SusyNt.e1931_s1581_s1586_r3658_r3549_p1512_n0145.130708190514/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200448.AlpgenPythia_Auto_P2011C_ZtautauccNp0.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190526/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200449.AlpgenPythia_Auto_P2011C_ZtautauccNp1.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190537/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200450.AlpgenPythia_Auto_P2011C_ZtautauccNp2.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190548/*");
ch->Add("/data/etp5/jwittkow/SusyNtuples_n0145_bg_new2/user.sfarrell.mc12_8TeV.200451.AlpgenPythia_Auto_P2011C_ZtautauccNp3incl.SusyNt.e1932_s1581_s1586_r3658_r3549_p1512_n0145.130708190558/*");



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

