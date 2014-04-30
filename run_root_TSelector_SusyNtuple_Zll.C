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

// void throwException(string str){
// 	// necessary because cint does not handle thrown errors correctly
// 	cout <<"Exception raised "<< str<<endl;
// 	throw(str);
// 	abort();
// }; 


void run_root_TSelector_SusyNtuple_Zll() {

    
      cout<<"Have you set up RootCore via  \"source RootCore/scripts/setup.sh\" ?"<<endl;  

      gSystem->Setenv("ROOTCOREDIR", "/data/etp/jwittkowski/analysis_SUSYTools_03_04/RootCore");
      gSystem->SetIncludePath("-I$ROOTCOREDIR/include/");

      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+"); 

      TString selectorName = "TSelector_SusyNtuple_Zll"; // !!! enter the name of your Selector (without _C.so)

      TChain *ch;

      ch = new TChain("susyNt");


      TString processLine = ".L " + selectorName + ".cpp++g";
      TString execLine;

      gROOT->ProcessLine(processLine); // need to add this, or PoD at LRZ will not be able to load the .so
      gROOT->ProcessLine(".x $ROOTCOREDIR/scripts/load_packages.C+");


//       ch->Add("/data/etp6/jwittkow/SusyNtuple_testdir/126893_n0145/*");

//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110809.AlpgenPythia_P2011C_ZmumuccNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082423/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110810.AlpgenPythia_P2011C_ZmumuccNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082438/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110811.AlpgenPythia_P2011C_ZmumuccNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082455/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110812.AlpgenPythia_P2011C_ZmumuccNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082512/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110821.AlpgenPythia_P2011C_ZmumubbNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082715/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110822.AlpgenPythia_P2011C_ZmumubbNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082726/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110823.AlpgenPythia_P2011C_ZmumubbNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708183304_rev117446/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.110824.AlpgenPythia_P2011C_ZmumubbNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082749/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117660.AlpgenPythia_P2011C_ZmumuNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083011/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117661.AlpgenPythia_P2011C_ZmumuNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083034/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117662.AlpgenPythia_P2011C_ZmumuNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083226/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117663.AlpgenPythia_P2011C_ZmumuNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083302/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117664.AlpgenPythia_P2011C_ZmumuNp4.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083316/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.117665.AlpgenPythia_P2011C_ZmumuNp5.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708083335/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.146840.AlpgenJimmy_Auto_ZmumuNp0Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130710093018/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.146841.AlpgenJimmy_Auto_ZmumuNp1Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181815/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.146842.AlpgenJimmy_Auto_ZmumuNp2Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181829/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.146843.AlpgenJimmy_Auto_ZmumuNp3Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181840/*");
//     ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zmm/user.sfarrell.mc12_8TeV.146844.AlpgenJimmy_Auto_ZmumuNp4Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181900_rev117470/*");

      
      
      
      
      
      
      
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.146830.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp0Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181643/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.146831.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp1Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181655/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.146832.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp2Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130710092943/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.146833.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp3Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181719/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.146834.AlpgenJimmy_Auto_AUET2CTEQ6L1_ZeeNp4Excl_Mll10to60.SusyNt.e1600_s1499_s1504_r3658_r3549_p1512_n0145.130708181730_rev117454/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110805.AlpgenPythia_P2011C_ZeeccNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082325/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110806.AlpgenPythia_P2011C_ZeeccNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082336/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110807.AlpgenPythia_P2011C_ZeeccNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082351/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110808.AlpgenPythia_P2011C_ZeeccNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082408/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110817.AlpgenPythia_P2011C_ZeebbNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082627/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110818.AlpgenPythia_P2011C_ZeebbNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082638/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110819.AlpgenPythia_P2011C_ZeebbNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082650/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.110820.AlpgenPythia_P2011C_ZeebbNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082703/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117650.AlpgenPythia_P2011C_ZeeNp0.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117651.AlpgenPythia_P2011C_ZeeNp1.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117652.AlpgenPythia_P2011C_ZeeNp2.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082920/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117653.AlpgenPythia_P2011C_ZeeNp3.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082933/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117654.AlpgenPythia_P2011C_ZeeNp4.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082945/*");
ch->Add("/data/etp6/jwittkow/SusyNtuples_n0145_Zee/user.sfarrell.mc12_8TeV.117655.AlpgenPythia_P2011C_ZeeNp5.SusyNt.e1477_s1499_s1504_r3658_r3549_p1512_n0145.130708082958/*");      
      
      
      
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165423/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165447/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165507/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165547/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165619/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165710/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165732/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165801/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165829/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165907/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708165935/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170005/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051736/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212230/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212332/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212411/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170128/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170157/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170223/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170245/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170315/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051801/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170353/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170420/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170458/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170524/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170550/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170614/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170645/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709051836/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130709212549/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170738/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170757/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170819/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170844/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170905/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708170956/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171047/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171104/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171121/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171154/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171226/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171251/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171315/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171342/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171402/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171419/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Muons.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708171442/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171503_rev117460/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171521/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171541/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171559/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171646/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130710002540/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171724/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171804/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171839/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171907/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708171941/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172025/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172123/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709052308/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709213130/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172211/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172233/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172252/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Muons/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Muons.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708172319/*");







// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161315/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161341/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161402/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodA.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161438/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161523/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161605/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161633/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161714/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodB.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161844/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708161941/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162006/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162029/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162345/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162454/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodC.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001418/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162600/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708162701/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163028/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163147/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163249/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001607/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodD.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001635/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163344/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163424/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodE.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163609/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163708/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163819/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708163947/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164048/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodG.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130710001810/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164142/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164215/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164247/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164312/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodH.physics_Egamma.PhysCont.SusyNt.repro14_v01_p1542_n0145.130708164417/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164445/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164506/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164536/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164607/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709051000/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodI.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709211606/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164723/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164818/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164908/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708164947/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165040/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709051609/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodJ.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130709211909/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165112/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165144/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165203/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165221/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165250/*");
// ch->Add("/nobackup/etp2/Josephine.Wittkowski/SusyNtuples_n0145_data/Egamma/user.sfarrell.group.phys-susy.data12_8TeV.periodL.physics_Egamma.PhysCont.SusyNt.t0pro14_v01_p1542_n0145.130708165406/*");



      Long64_t nEntries = ch->GetEntries();
      ch->ls();

      cout << "all entries: " << nEntries << endl;


      TSelector_SusyNtuple_Zll* susyAna = new TSelector_SusyNtuple_Zll();
      susyAna->buildSumwMap(ch);
      ch->Process(susyAna);
      delete susyAna;
      
      if (ch) {delete ch; ch=0;}

  abort();
  }

