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

int run(TString InputPath) {

    TString options = TString(""); //TString(tag.c_str()) ;
    TString outputfile = "test.root";
//     string richtigerString = InputPath;
// //     int Position = richtigerString.find("mc12_8TeV.");
// //     outputfile = "histos_ZTauTau_" +  richtigerString.substr(Position+10,6)  + "_proof.root";
//     
//     int Position = -1;
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
//     if(outputfile == ""){
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       cout << "EMPTY OUPTPUTFILE STRING" << endl;
//       cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
//       abort();
//     }
    cout << "outputfile " << outputfile << endl;

    TProof::AddEnvVar("PROOF_INITCMD", TString("bash /data/etp/jwittkowski/analysis_SUSYTools_03_04/RootCore/scripts/setup.sh")) ;
    
    TString proof_server_address = TString("") ; 
//      proof_server_address = gSystem->GetFromPipe("pod-info -c");
    TProofMgr* mgr = TProofMgr::Create(proof_server_address) ;

    TProof *proof = mgr->CreateSession() ;
    
    //make tarballs RootCore.par and TSelector_SusyNtuple.par, before:

//     proof->Load("/data/etp/jwittkowski/analysis_SUSYTools_03_04/RootCore/scripts/load_packages.C") ;
//     proof->UploadPackage("TSelector_SusyNtuple_Zll.par", TProof::kRemoveOld) ; // kRemoveOld: old ones will be removed anyways
//     proof->EnablePackage("TSelector_SusyNtuple_Zll") ;
// 
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
//     int ret = 0 ;
//     ret = set->Process("TSelector_SusyNtuple", options.Data()) ;
// 
//     TProofLog *log = mgr->GetSessionLogs() ;                                                    
//     int proof_log_flag = log->Save("*", "log_runSelector_all_workers.txt") ;
//     
//     
// 
//     TFile* output_file = new TFile(outputfile, "recreate") ;
//                                                     
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

    abort();
}

