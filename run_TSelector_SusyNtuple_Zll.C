// ROOT 
#include "TROOT.h"
#include "TFile.h"
#include "TProof.h"
#include "TProofMgr.h"
#include "TProofLog.h"
#include "TDSet.h"
#include "TEnv.h"
#include "TString.h"
#include "TStopwatch.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TRegexp.h"
#include "TChain.h"

// STL 
#include <iostream>
#include <sstream>
#include <fstream>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std ;


//
// Add filelist to the TDSet
//

void get_files(TDSet* set_mc, TString filelist_path) {

    cout << ">> Input file name(s): " << endl ;
    ifstream file_handler(filelist_path.Data()) ;
    while (!file_handler.eof()) {
        TString buf ;
        file_handler >> buf ;
        TRegexp pattern("^$") ;
        if (buf.Index(pattern)>=0)
            continue ;
        cout << "  " << buf << endl ;
        set_mc->Add(buf) ;
    }
    file_handler.close() ;

}

int run_TSelector_SusyNtuple_Zll(TString InputPath) {

    TString options = TString(""); //TString(tag.c_str()) ;
    TString outputfile = "";
    string richtigerString = InputPath;
    int Position = -1;
    
    Position = richtigerString.find("mc12_8TeV.");
    outputfile = "histos_Zmm_" +  richtigerString.substr(Position+10,6)  + "_METresolution_25GeV.root";
    Position = richtigerString.find("p1542_n0145");
//     if (Position>0){
//       int PositionPeriod = richtigerString.find("period");
//       outputfile = "histos_Zmm_" +  richtigerString.substr(PositionPeriod,7) + "_" + richtigerString.substr(Position+12,12)  + "_data.root";
//     }
    
    if (Position>0){
//       int PositionPeriod = richtigerString.find("period");
      outputfile = "histos_Zmm_" +  richtigerString.substr(Position+11,6)  + "_MC.root";
    }
    
    
//     Position = richtigerString.find("45_bg");
//     if (Position>0){
//       outputfile = "histos_ZTauTau_" +  richtigerString.substr(Position+6,2)  + "_proof.root";
//     }
//     else{
//       Position = richtigerString.find("45_signal");
//       if (Position>0){
//       outputfile = "histos_ZTauTau_" +  richtigerString.substr(Position+3,2)  + "_proof.root";
//       }
//     }
    if(outputfile == ""){
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      cout << "EMPTY OUPTPUTFILE STRING" << endl;
      cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      abort();
    }
    cout << "outputfile " << outputfile << endl;
//      TProof::AddEnvVar("PROOF_INITCMD", TString("echo source /data/etp/jwittkowski/analysis_SUSYTools_03_04/RootCore/scripts/setup.sh")) ;
    TString proof_server_address = TString("") ; 
//     proof_server_address = gSystem->GetFromPipe("pod-info -c");
    TProofMgr* mgr = TProofMgr::Create(proof_server_address) ;
    gEnv->SetValue( "ProofServ.Sandbox", "/nobackup/etp2/Josephine.Wittkowski/proof");
    TProof *proof = mgr->CreateSession() ;
//     
//     //make tarballs RootCore.par and TSelector_SusyNtuple_Zll.par, before:
//     
    proof->Load("/data/etp/jwittkowski/analysis_SUSYTools_03_04/RootCore/scripts/load_packages.C") ;
//     proof->UploadPackage("TSelector_SusyNtuple_Zll.par", TProof::kRemoveOld) ; // kRemoveOld: old ones will be removed anyways
//     proof->EnablePackage("TSelector_SusyNtuple_Zll") ;
// 
// 
//     //proof->SetLogLevel(-1) ;
// 
//     // statistics 
//     gEnv->SetValue("Proof.StatsHist", 0) ;
//     gEnv->SetValue("Proof.StatsTrace", 0) ;
//     gEnv->SetValue("Proof.SlaveStatsTrace", 0) ;
// 
//     TDSet* set = new TDSet("TTree", "susyNt") ;
//     TChain *ch;
//     ch = new TChain("susyNt");
//     ch->Add(InputPath);
//     set = new TDSet(*ch);
//     Long64_t nEntries = ch->GetEntries();
//     cout << "number of Entries being processes: " << nEntries << endl;
// 
// //     p->Process(set,selectorName); // run_TSelector_SusyNtuple_Zll_Zll on the TDSet
//     
// //     get_files(set, TString(inputFile.c_str())) ;
//     //set->Print() ;
//     int ret = 0 ;
//     ret = set->Process("TSelector_SusyNtuple_Zll", options.Data()) ;
// 
//     TProofLog *log = mgr->GetSessionLogs() ;                                                    
//     int proof_log_flag = log->Save("*", "log_run_TSelector_SusyNtuple_TSelector_all_workers.txt") ;
//     
//     
// 
//     TFile* output_file = new TFile(outputfile, "recreate") ;
// 
// //     TFile* output_file = new TFile("output.root", "recreate") ;
//     // Retrieve objects                                                         
//     TList* list = proof->GetOutputList() ;
//     TIter next_object((TList*) list);
//     TObject* obj ;
//     cout << "-- Retrieved objects:" << endl ;
//     output_file->cd() ;
//     while ((obj = next_object())) { TString objname = obj->GetName() ; cout << " " << objname << endl ; obj->Write() ; }
// 
//     // Write output file
//     output_file->Write() ;
//     output_file->Close() ;
//     cout << "outputfile: " << outputfile << endl;
// 
// 
//     proof->Close() ;
//     mgr->Close() ;
// 
//     delete set ;
//     delete proof ;
//     delete mgr ;


    abort();
}
