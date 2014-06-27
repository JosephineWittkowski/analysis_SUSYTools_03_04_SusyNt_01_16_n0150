#ifndef SusyAna_TSelector_SusyNtuple_h
#define SusyAna_TSelector_SusyNtuple_h

//////////////////////////////////////////////////////////
// General script to implement basic selection with all //
// signal region cut methods.                           //
//////////////////////////////////////////////////////////


// Root Packages
#include "TTree.h"
// #include "TProofOutputFile.h"
// #include "TSystem.h"
// Susy Common
#include "SusyNtuple/SusyNtAna.h"
#include "SusyNtuple/SusyNtTools.h"
#include "SusyNtuple/DilTrigLogic.h"
#include "SUSYTools/SUSYObjDef.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"
#include "SusyNtuple/SusyDefs.h"
#include "SusyNtuple/WhTruthExtractor.h"
#include "Mt2/mt2_bisect.h" 
#include "SusyMatrixMethod/DiLeptonMatrixMethod.h"
#include "TH1.h"
#include "TH2.h"
#include "mmc/mmc.cpp"
#include "MultiLep/CutflowTools.h"

#include "MultiLep/MuonD3PDObject.h"
#include "MultiLep/ElectronD3PDObject.h"
#include "MultiLep/VertexD3PDObject.h"
#include "MultiLep/METD3PDObject.h"
#include "MultiLep/JetD3PDObject.h"
#include "MultiLep/TrackD3PDObject.h"
#include "MultiLep/JetTools.h"
#include "MultiLep/LeptonInfo.h"

#ifndef __CINT__
#include "ChargeFlip/chargeFlip.h"
#else
class chargeFlip ;
#endif

#include <fstream>

class TSelector_SusyNtuple : public SusyNtAna
{

  public:
    TH1F* h_storeSumwMcid;
    
    TH1F* cutflow_EE;
    TH1F* cutflow_EE_ALL;
    
    TH1F* cutflow_MM;
    TH1F* cutflow_MM_ALL;
    
    TH1F* cutflow_EM;
    TH1F* cutflow_EM_ALL;
    
    TH1F* cutflow_ME;
    TH1F* cutflow_ME_ALL;
    
    TH1F* h_DeltaR_ljOR_EE;
    TH1F* h_DeltaR_ljOR_MM;
    TH1F* h_DeltaR_ljOR_EM;
    
    TH2F* h_N_MuonToBeChecked_afterORWJet_MM;
    TH2F* h_N_MuonToBeChecked_afterORWOFLepton_MM;
    TH2F* h_N_MuonToBeChecked_afterORWSFLepton_MM;
    TH2F* h_N_MuonToBeChecked_afterMllCut_MM;
    
    TH2F* h_N_MuonToBeChecked_afterORWJet_EM;
    TH2F* h_N_MuonToBeChecked_afterORWOFLepton_EM;
    TH2F* h_N_MuonToBeChecked_afterORWSFLepton_EM; 
    TH2F* h_N_MuonToBeChecked_afterMllCut_EM;
    TH2F* h_N_ElectronToBeChecked_afterORWJet_EM;
    TH2F* h_N_ElectronToBeChecked_afterORWOFLepton_EM;
    TH2F* h_N_ElectronToBeChecked_afterMllCut_EM;
    
    TH2F* h_etcone30l1llost_EM_SRSS1;
    TH2F* h_etcone30l1lsoft_EM_SRSS1;
    TH2F* h_etcone30l1loverlap_EM_SRSS1;
    TH2F* h_etcone30l1loverlapWJet_EM_SRSS1;
    TH2F* h_etcone30l1loverlapWOFLepton_EM_SRSS1;
    TH2F* h_etcone30l1loverlapWSFLepton_EM_SRSS1;
    TH2F* h_etcone30l1lZcand_EM_SRSS1;
    
    
    TH2F* h_Nleptons_lost_EE_SRSS1;
    TH2F* h_Nleptons_lost_MM_SRSS1;
    TH2F* h_Nleptons_lost_EM_SRSS1;

    
    TH2F* h_ml0llost_EE_SRSS1;
    TH2F* h_ml0llost_MM_SRSS1;
    TH2F* h_ml0llost_EM_SRSS1;
    
    TH2F* h_mTl0llost_EE_SRSS1;
    TH2F* h_mTl0llost_MM_SRSS1;
    TH2F* h_mTl0llost_EM_SRSS1;
    
    TH2F* h_ICl0llost_EE_SRSS1;
    TH2F* h_ICl0llost_MM_SRSS1;
    TH2F* h_ICl0llost_EM_SRSS1;    
    
    TH2F* h_pTl0llost_EE_SRSS1;
    TH2F* h_pTl0llost_MM_SRSS1;
    TH2F* h_pTl0llost_EM_SRSS1;
    
    TH2F* h_etal0llost_EE_SRSS1;
    TH2F* h_etal0llost_MM_SRSS1;
    TH2F* h_etal0llost_EM_SRSS1;
    
    TH2F* h_ptcone30l0llost_EE_SRSS1;
    TH2F* h_ptcone30l0llost_MM_SRSS1;
    TH2F* h_ptcone30l0llost_EM_SRSS1;

    
    TH2F* h_d0Sigl0llost_EE_SRSS1;
    TH2F* h_d0Sigl0llost_MM_SRSS1;
    TH2F* h_d0Sigl0llost_EM_SRSS1;
    
    TH2F* h_z0SinThetal0llost_EE_SRSS1;
    TH2F* h_z0SinThetal0llost_MM_SRSS1;
    TH2F* h_z0SinThetal0llost_EM_SRSS1;
    
    TH2F* h_ml1llost_EE_SRSS1;
    TH2F* h_ml1llost_MM_SRSS1;
    TH2F* h_ml1llost_EM_SRSS1;
    
    TH2F* h_mTl1llost_EE_SRSS1;
    TH2F* h_mTl1llost_MM_SRSS1;
    TH2F* h_mTl1llost_EM_SRSS1;   
    
    TH2F* h_ICl1llost_EE_SRSS1;
    TH2F* h_ICl1llost_MM_SRSS1;
    TH2F* h_ICl1llost_EM_SRSS1;
    
    TH2F* h_pTl1llost_EE_SRSS1;
    TH2F* h_pTl1llost_MM_SRSS1;
    TH2F* h_pTl1llost_EM_SRSS1;
    
    TH2F* h_etal1llost_EE_SRSS1;
    TH2F* h_etal1llost_MM_SRSS1;
    TH2F* h_etal1llost_EM_SRSS1;
    
    TH2F* h_ptcone30l1llost_EE_SRSS1;
    TH2F* h_ptcone30l1llost_MM_SRSS1;
    TH2F* h_ptcone30l1llost_EM_SRSS1;
    
    TH2F* h_d0Sigl1llost_EE_SRSS1;
    TH2F* h_d0Sigl1llost_MM_SRSS1;
    TH2F* h_d0Sigl1llost_EM_SRSS1;
    
    TH2F* h_z0SinThetal1llost_EE_SRSS1;
    TH2F* h_z0SinThetal1llost_MM_SRSS1;
    TH2F* h_z0SinThetal1llost_EM_SRSS1;
  
    TH2F* h_Nleptons_soft_EE_SRSS1;
    TH2F* h_Nleptons_soft_MM_SRSS1;
    TH2F* h_Nleptons_soft_EM_SRSS1;
    
    TH2F* h_ml0lsoft_EE_SRSS1;
    TH2F* h_ml0lsoft_MM_SRSS1;
    TH2F* h_ml0lsoft_EM_SRSS1;
    
    TH2F* h_mTl0lsoft_EE_SRSS1;
    TH2F* h_mTl0lsoft_MM_SRSS1;
    TH2F* h_mTl0lsoft_EM_SRSS1;    
    
    TH2F* h_ICl0lsoft_EE_SRSS1;
    TH2F* h_ICl0lsoft_MM_SRSS1;
    TH2F* h_ICl0lsoft_EM_SRSS1;    
    
    TH2F* h_pTl0lsoft_EE_SRSS1;
    TH2F* h_pTl0lsoft_MM_SRSS1;
    TH2F* h_pTl0lsoft_EM_SRSS1;
    
    TH2F* h_etal0lsoft_EE_SRSS1;
    TH2F* h_etal0lsoft_MM_SRSS1;
    TH2F* h_etal0lsoft_EM_SRSS1;
    
    TH2F* h_ptcone30l0lsoft_EE_SRSS1;
    TH2F* h_ptcone30l0lsoft_MM_SRSS1;
    TH2F* h_ptcone30l0lsoft_EM_SRSS1;
    
    TH2F* h_d0Sigl0lsoft_EE_SRSS1;
    TH2F* h_d0Sigl0lsoft_MM_SRSS1;
    TH2F* h_d0Sigl0lsoft_EM_SRSS1;
    
    TH2F* h_z0SinThetal0lsoft_EE_SRSS1;
    TH2F* h_z0SinThetal0lsoft_MM_SRSS1;
    TH2F* h_z0SinThetal0lsoft_EM_SRSS1;
    
    TH2F* h_ml1lsoft_EE_SRSS1;
    TH2F* h_ml1lsoft_MM_SRSS1;
    TH2F* h_ml1lsoft_EM_SRSS1;
    
    TH2F* h_mTl1lsoft_EE_SRSS1;
    TH2F* h_mTl1lsoft_MM_SRSS1;
    TH2F* h_mTl1lsoft_EM_SRSS1;
    
    TH2F* h_ICl1lsoft_EE_SRSS1;
    TH2F* h_ICl1lsoft_MM_SRSS1;
    TH2F* h_ICl1lsoft_EM_SRSS1;
    
    TH2F* h_pTl1lsoft_EE_SRSS1;
    TH2F* h_pTl1lsoft_MM_SRSS1;
    TH2F* h_pTl1lsoft_EM_SRSS1;
    
    TH2F* h_etal1lsoft_EE_SRSS1;
    TH2F* h_etal1lsoft_MM_SRSS1;
    TH2F* h_etal1lsoft_EM_SRSS1;
    
    TH2F* h_ptcone30l1lsoft_EE_SRSS1;
    TH2F* h_ptcone30l1lsoft_MM_SRSS1;
    TH2F* h_ptcone30l1lsoft_EM_SRSS1;
    
    TH2F* h_d0Sigl1lsoft_EE_SRSS1;
    TH2F* h_d0Sigl1lsoft_MM_SRSS1;
    TH2F* h_d0Sigl1lsoft_EM_SRSS1;
    
    TH2F* h_z0SinThetal1lsoft_EE_SRSS1;
    TH2F* h_z0SinThetal1lsoft_MM_SRSS1;
    TH2F* h_z0SinThetal1lsoft_EM_SRSS1;
    
    TH2F* h_Nleptons_overlap_EE_SRSS1;
    TH2F* h_Nleptons_overlap_MM_SRSS1;
    TH2F* h_Nleptons_overlap_EM_SRSS1;
    
    TH2F* h_ml0loverlap_EE_SRSS1;
    TH2F* h_ml0loverlap_MM_SRSS1;
    TH2F* h_ml0loverlap_EM_SRSS1;
    
    TH2F* h_mTl0loverlap_EE_SRSS1;
    TH2F* h_mTl0loverlap_MM_SRSS1;
    TH2F* h_mTl0loverlap_EM_SRSS1;
    
    TH2F* h_ICl0loverlap_EE_SRSS1;
    TH2F* h_ICl0loverlap_MM_SRSS1;
    TH2F* h_ICl0loverlap_EM_SRSS1;    
    
    TH2F* h_pTl0loverlap_EE_SRSS1;
    TH2F* h_pTl0loverlap_MM_SRSS1;
    TH2F* h_pTl0loverlap_EM_SRSS1;
    
    TH2F* h_etal0loverlap_EE_SRSS1;
    TH2F* h_etal0loverlap_MM_SRSS1;
    TH2F* h_etal0loverlap_EM_SRSS1;
    
    TH2F* h_ptcone30l0loverlap_EE_SRSS1;
    TH2F* h_ptcone30l0loverlap_MM_SRSS1;
    TH2F* h_ptcone30l0loverlap_EM_SRSS1;
    
    TH2F* h_d0Sigl0loverlap_EE_SRSS1;
    TH2F* h_d0Sigl0loverlap_MM_SRSS1;
    TH2F* h_d0Sigl0loverlap_EM_SRSS1;
    
    TH2F* h_z0SinThetal0loverlap_EE_SRSS1;
    TH2F* h_z0SinThetal0loverlap_MM_SRSS1;
    TH2F* h_z0SinThetal0loverlap_EM_SRSS1;
    
    TH2F* h_ml1loverlap_EE_SRSS1;
    TH2F* h_ml1loverlap_MM_SRSS1;
    TH2F* h_ml1loverlap_EM_SRSS1;
    
    TH2F* h_mTl1loverlap_EE_SRSS1;
    TH2F* h_mTl1loverlap_MM_SRSS1;
    TH2F* h_mTl1loverlap_EM_SRSS1;    
    
    TH2F* h_ICl1loverlap_EE_SRSS1;
    TH2F* h_ICl1loverlap_MM_SRSS1;
    TH2F* h_ICl1loverlap_EM_SRSS1;
    
    TH2F* h_pTl1loverlap_EE_SRSS1;
    TH2F* h_pTl1loverlap_MM_SRSS1;
    TH2F* h_pTl1loverlap_EM_SRSS1;
    
    TH2F* h_etal1loverlap_EE_SRSS1;
    TH2F* h_etal1loverlap_MM_SRSS1;
    TH2F* h_etal1loverlap_EM_SRSS1;
    
    TH2F* h_ptcone30l1loverlap_EE_SRSS1;
    TH2F* h_ptcone30l1loverlap_MM_SRSS1;
    TH2F* h_ptcone30l1loverlap_EM_SRSS1;
    
    TH2F* h_d0Sigl1loverlap_EE_SRSS1;
    TH2F* h_d0Sigl1loverlap_MM_SRSS1;
    TH2F* h_d0Sigl1loverlap_EM_SRSS1;
    
    TH2F* h_z0SinThetal1loverlap_EE_SRSS1;
    TH2F* h_z0SinThetal1loverlap_MM_SRSS1;
    TH2F* h_z0SinThetal1loverlap_EM_SRSS1;
    
    TH2F* h_Nleptons_overlapWJet_EE_SRSS1;
    TH2F* h_Nleptons_overlapWJet_MM_SRSS1;
    TH2F* h_Nleptons_overlapWJet_EM_SRSS1;
    
    TH2F* h_ml0loverlapWJet_EE_SRSS1;
    TH2F* h_ml0loverlapWJet_MM_SRSS1;
    TH2F* h_ml0loverlapWJet_EM_SRSS1;
    
    TH2F* h_mTl0loverlapWJet_EE_SRSS1;
    TH2F* h_mTl0loverlapWJet_MM_SRSS1;
    TH2F* h_mTl0loverlapWJet_EM_SRSS1;    
    
    TH2F* h_ICl0loverlapWJet_EE_SRSS1;
    TH2F* h_ICl0loverlapWJet_MM_SRSS1;
    TH2F* h_ICl0loverlapWJet_EM_SRSS1;    
    
    TH2F* h_pTl0loverlapWJet_EE_SRSS1;
    TH2F* h_pTl0loverlapWJet_MM_SRSS1;
    TH2F* h_pTl0loverlapWJet_EM_SRSS1;
    
    TH2F* h_etal0loverlapWJet_EE_SRSS1;
    TH2F* h_etal0loverlapWJet_MM_SRSS1;
    TH2F* h_etal0loverlapWJet_EM_SRSS1;
    
    TH2F* h_ptcone30l0loverlapWJet_EE_SRSS1;
    TH2F* h_ptcone30l0loverlapWJet_MM_SRSS1;
    TH2F* h_ptcone30l0loverlapWJet_EM_SRSS1;
    
    TH2F* h_d0Sigl0loverlapWJet_EE_SRSS1;
    TH2F* h_d0Sigl0loverlapWJet_MM_SRSS1;
    TH2F* h_d0Sigl0loverlapWJet_EM_SRSS1;
    
    TH2F* h_z0SinThetal0loverlapWJet_EE_SRSS1;
    TH2F* h_z0SinThetal0loverlapWJet_MM_SRSS1;
    TH2F* h_z0SinThetal0loverlapWJet_EM_SRSS1;
    
    TH2F* h_ml1loverlapWJet_EE_SRSS1;
    TH2F* h_ml1loverlapWJet_MM_SRSS1;
    TH2F* h_ml1loverlapWJet_EM_SRSS1;
    
    TH2F* h_mTl1loverlapWJet_EE_SRSS1;
    TH2F* h_mTl1loverlapWJet_MM_SRSS1;
    TH2F* h_mTl1loverlapWJet_EM_SRSS1;    
    
    TH2F* h_ICl1loverlapWJet_EE_SRSS1;
    TH2F* h_ICl1loverlapWJet_MM_SRSS1;
    TH2F* h_ICl1loverlapWJet_EM_SRSS1;
    
    TH2F* h_pTl1loverlapWJet_EE_SRSS1;
    TH2F* h_pTl1loverlapWJet_MM_SRSS1;
    TH2F* h_pTl1loverlapWJet_EM_SRSS1;
    
    TH2F* h_etal1loverlapWJet_EE_SRSS1;
    TH2F* h_etal1loverlapWJet_MM_SRSS1;
    TH2F* h_etal1loverlapWJet_EM_SRSS1;
    
    TH2F* h_ptcone30l1loverlapWJet_EE_SRSS1;
    TH2F* h_ptcone30l1loverlapWJet_MM_SRSS1;
    TH2F* h_ptcone30l1loverlapWJet_EM_SRSS1;
    
    TH2F* h_d0Sigl1loverlapWJet_EE_SRSS1;
    TH2F* h_d0Sigl1loverlapWJet_MM_SRSS1;
    TH2F* h_d0Sigl1loverlapWJet_EM_SRSS1;
    
    TH2F* h_z0SinThetal1loverlapWJet_EE_SRSS1;
    TH2F* h_z0SinThetal1loverlapWJet_MM_SRSS1;
    TH2F* h_z0SinThetal1loverlapWJet_EM_SRSS1;
    
    TH2F* h_Nleptons_overlapWOFLepton_EE_SRSS1;
    TH2F* h_Nleptons_overlapWOFLepton_MM_SRSS1;
    TH2F* h_Nleptons_overlapWOFLepton_EM_SRSS1;
    
    TH2F* h_ml0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ml0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ml0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_mTl0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_mTl0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_mTl0loverlapWOFLepton_EM_SRSS1;   
    
    TH2F* h_ICl0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ICl0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ICl0loverlapWOFLepton_EM_SRSS1;    
    
    TH2F* h_pTl0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_pTl0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_pTl0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_etal0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_etal0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_etal0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_ptcone30l0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ptcone30l0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ptcone30l0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_d0Sigl0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_d0Sigl0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_d0Sigl0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_z0SinThetal0loverlapWOFLepton_EE_SRSS1;
    TH2F* h_z0SinThetal0loverlapWOFLepton_MM_SRSS1;
    TH2F* h_z0SinThetal0loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_ml1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ml1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ml1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_mTl1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_mTl1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_mTl1loverlapWOFLepton_EM_SRSS1;    
    
    TH2F* h_ICl1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ICl1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ICl1loverlapWOFLepton_EM_SRSS1;    
    
    TH2F* h_pTl1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_pTl1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_pTl1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_etal1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_etal1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_etal1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_ptcone30l1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_ptcone30l1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_ptcone30l1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_d0Sigl1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_d0Sigl1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_d0Sigl1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_z0SinThetal1loverlapWOFLepton_EE_SRSS1;
    TH2F* h_z0SinThetal1loverlapWOFLepton_MM_SRSS1;
    TH2F* h_z0SinThetal1loverlapWOFLepton_EM_SRSS1;
    
    TH2F* h_Nleptons_overlapWSFLepton_EE_SRSS1;
    TH2F* h_Nleptons_overlapWSFLepton_MM_SRSS1;
    TH2F* h_Nleptons_overlapWSFLepton_EM_SRSS1;
    
    TH2F* h_ml0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ml0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ml0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_mTl0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_mTl0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_mTl0loverlapWSFLepton_EM_SRSS1;    
    
    TH2F* h_pTl0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_pTl0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_pTl0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_ICl0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ICl0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ICl0loverlapWSFLepton_EM_SRSS1;   
    
    TH2F* h_etal0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_etal0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_etal0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_ptcone30l0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ptcone30l0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ptcone30l0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_d0Sigl0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_d0Sigl0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_d0Sigl0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_z0SinThetal0loverlapWSFLepton_EE_SRSS1;
    TH2F* h_z0SinThetal0loverlapWSFLepton_MM_SRSS1;
    TH2F* h_z0SinThetal0loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_ml1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ml1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ml1loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_mTl1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_mTl1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_mTl1loverlapWSFLepton_EM_SRSS1;    
    
    TH2F* h_ICl1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ICl1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ICl1loverlapWSFLepton_EM_SRSS1;    
    
    TH2F* h_pTl1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_pTl1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_pTl1loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_etal1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_etal1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_etal1loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_ptcone30l1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_ptcone30l1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_ptcone30l1loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_d0Sigl1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_d0Sigl1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_d0Sigl1loverlapWSFLepton_EM_SRSS1;
    
    TH2F* h_z0SinThetal1loverlapWSFLepton_EE_SRSS1;
    TH2F* h_z0SinThetal1loverlapWSFLepton_MM_SRSS1;
    TH2F* h_z0SinThetal1loverlapWSFLepton_EM_SRSS1;
   
    TH2F* h_Nleptons_Zcand_EE_SRSS1;
    TH2F* h_Nleptons_Zcand_MM_SRSS1;
    TH2F* h_Nleptons_Zcand_EM_SRSS1;
    
    TH2F* h_ml0lZcand_EE_SRSS1;
    TH2F* h_ml0lZcand_MM_SRSS1;
    TH2F* h_ml0lZcand_EM_SRSS1;
    
    TH2F* h_mTl0lZcand_EE_SRSS1;
    TH2F* h_mTl0lZcand_MM_SRSS1;
    TH2F* h_mTl0lZcand_EM_SRSS1;    
    
    TH2F* h_pTl0lZcand_EE_SRSS1;
    TH2F* h_pTl0lZcand_MM_SRSS1;
    TH2F* h_pTl0lZcand_EM_SRSS1;
    
    TH2F* h_ICl0lZcand_EE_SRSS1;
    TH2F* h_ICl0lZcand_MM_SRSS1;
    TH2F* h_ICl0lZcand_EM_SRSS1;   
    
    TH2F* h_etal0lZcand_EE_SRSS1;
    TH2F* h_etal0lZcand_MM_SRSS1;
    TH2F* h_etal0lZcand_EM_SRSS1;
    
    TH2F* h_ptcone30l0lZcand_EE_SRSS1;
    TH2F* h_ptcone30l0lZcand_MM_SRSS1;
    TH2F* h_ptcone30l0lZcand_EM_SRSS1;
    
    TH2F* h_d0Sigl0lZcand_EE_SRSS1;
    TH2F* h_d0Sigl0lZcand_MM_SRSS1;
    TH2F* h_d0Sigl0lZcand_EM_SRSS1;
    
    TH2F* h_z0SinThetal0lZcand_EE_SRSS1;
    TH2F* h_z0SinThetal0lZcand_MM_SRSS1;
    TH2F* h_z0SinThetal0lZcand_EM_SRSS1;
    
    TH2F* h_ml1lZcand_EE_SRSS1;
    TH2F* h_ml1lZcand_MM_SRSS1;
    TH2F* h_ml1lZcand_EM_SRSS1;
    
    TH2F* h_mTl1lZcand_EE_SRSS1;
    TH2F* h_mTl1lZcand_MM_SRSS1;
    TH2F* h_mTl1lZcand_EM_SRSS1;    
    
    TH2F* h_ICl1lZcand_EE_SRSS1;
    TH2F* h_ICl1lZcand_MM_SRSS1;
    TH2F* h_ICl1lZcand_EM_SRSS1;    
    
    TH2F* h_pTl1lZcand_EE_SRSS1;
    TH2F* h_pTl1lZcand_MM_SRSS1;
    TH2F* h_pTl1lZcand_EM_SRSS1;
    
    TH2F* h_etal1lZcand_EE_SRSS1;
    TH2F* h_etal1lZcand_MM_SRSS1;
    TH2F* h_etal1lZcand_EM_SRSS1;
    
    TH2F* h_ptcone30l1lZcand_EE_SRSS1;
    TH2F* h_ptcone30l1lZcand_MM_SRSS1;
    TH2F* h_ptcone30l1lZcand_EM_SRSS1;
    
    TH2F* h_d0Sigl1lZcand_EE_SRSS1;
    TH2F* h_d0Sigl1lZcand_MM_SRSS1;
    TH2F* h_d0Sigl1lZcand_EM_SRSS1;
    
    TH2F* h_z0SinThetal1lZcand_EE_SRSS1;
    TH2F* h_z0SinThetal1lZcand_MM_SRSS1;
    TH2F* h_z0SinThetal1lZcand_EM_SRSS1;
    
    TH2F* h_Mljj_EE_SRSS1;
    TH2F* h_Mljj_MM_SRSS1;
    TH2F* h_Mljj_EM_SRSS1;
    
//     TH2F* h_DeltaRLeptons_EE_SRSS1;
//     TH2F* h_DeltaRLeptons_EE_SRSS2;
//     TH2F* h_DeltaRLeptons_MM_SRSS1;
//     TH2F* h_DeltaRLeptons_MM_SRSS2;
//     TH2F* h_DeltaRLeptons_MM_SRSS3;
//     TH2F* h_DeltaRLeptons_MM_SRSS4;
//     TH2F* h_DeltaRLeptons_EM_SRSS1;
//     TH2F* h_DeltaRLeptons_EM_SRSS2;
//     TH2F* h_DeltaRLeptons_EE_SROS1;
//     TH2F* h_DeltaRLeptons_MM_SROS1;
//     TH2F* h_DeltaRLeptons_EM_SROS1;
//     
//     TH2F* h_mZTT_coll_EE_SRSS1;
//     TH2F* h_mZTT_coll_EE_SRSS2;
//     TH2F* h_mZTT_coll_MM_SRSS1;
//     TH2F* h_mZTT_coll_MM_SRSS2;
//     TH2F* h_mZTT_coll_MM_SRSS3;
//     TH2F* h_mZTT_coll_MM_SRSS4;
//     TH2F* h_mZTT_coll_EM_SRSS1;
//     TH2F* h_mZTT_coll_EM_SRSS2;
//     TH2F* h_mZTT_coll_EE_SROS1;
//     TH2F* h_mZTT_coll_MM_SROS1;
//     TH2F* h_mZTT_coll_EM_SROS1;
//     
//     TH2F* h_mZTT_mmc_EE_SRSS1;
//     TH2F* h_mZTT_mmc_EE_SRSS2;
//     TH2F* h_mZTT_mmc_MM_SRSS1;
//     TH2F* h_mZTT_mmc_MM_SRSS2;
//     TH2F* h_mZTT_mmc_MM_SRSS3;
//     TH2F* h_mZTT_mmc_MM_SRSS4;
//     TH2F* h_mZTT_mmc_EM_SRSS1;
//     TH2F* h_mZTT_mmc_EM_SRSS2;
//     TH2F* h_mZTT_mmc_EE_SROS1;
//     TH2F* h_mZTT_mmc_MM_SROS1;
//     TH2F* h_mZTT_mmc_EM_SROS1;
//     
//     TH2F* h_pTl0_EE_SRSS1;
//     TH2F* h_pTl0_EE_SRSS2;
//     TH2F* h_pTl0_MM_SRSS1;
//     TH2F* h_pTl0_MM_SRSS2;
//     TH2F* h_pTl0_MM_SRSS3;
//     TH2F* h_pTl0_MM_SRSS4;
//     TH2F* h_pTl0_EM_SRSS1;
//     TH2F* h_pTl0_EM_SRSS2;
//     TH2F* h_pTl0_EE_SROS1;
//     TH2F* h_pTl0_MM_SROS1;
//     TH2F* h_pTl0_EM_SROS1;
//     
//     TH2F* h_pTl1_EE_SRSS1;
//     TH2F* h_pTl1_EE_SRSS2;
//     TH2F* h_pTl1_MM_SRSS1;  
//     TH2F* h_pTl1_MM_SRSS2;
//     TH2F* h_pTl1_MM_SRSS3;
//     TH2F* h_pTl1_MM_SRSS4;
//     TH2F* h_pTl1_EM_SRSS1;
//     TH2F* h_pTl1_EM_SRSS2;
//     TH2F* h_pTl1_EE_SROS1;
//     TH2F* h_pTl1_MM_SROS1;
//     TH2F* h_pTl1_EM_SROS1;
//     
//     TH2F* h_pTj0_EE_SRSS1;
//     TH2F* h_pTj0_EE_SRSS2;
//     TH2F* h_pTj0_MM_SRSS1;
//     TH2F* h_pTj0_MM_SRSS2;
//     TH2F* h_pTj0_MM_SRSS3;
//     TH2F* h_pTj0_MM_SRSS4;
//     TH2F* h_pTj0_EM_SRSS1;
//     TH2F* h_pTj0_EM_SRSS2;
//     TH2F* h_pTj0_EE_SROS1;
//     TH2F* h_pTj0_MM_SROS1;
//     TH2F* h_pTj0_EM_SROS1;
//     
//     
//     TH2F* h_pTj1_EE_SRSS1;
//     TH2F* h_pTj1_EE_SRSS2;
//     TH2F* h_pTj1_MM_SRSS1;  
//     TH2F* h_pTj1_MM_SRSS2;
//     TH2F* h_pTj1_MM_SRSS3;
//     TH2F* h_pTj1_MM_SRSS4;
//     TH2F* h_pTj1_EM_SRSS1;
//     TH2F* h_pTj1_EM_SRSS2;
//     TH2F* h_pTj1_EE_SROS1;
//     TH2F* h_pTj1_MM_SROS1;
//     TH2F* h_pTj1_EM_SROS1;
//     
//     TH2F* h_mll_EE_SRSS1;
//     TH2F* h_mll_EE_SRSS2;
//     TH2F* h_mll_MM_SRSS1; 
//     TH2F* h_mll_MM_SRSS2;
//     TH2F* h_mll_MM_SRSS3;
//     TH2F* h_mll_MM_SRSS4;
//     TH2F* h_mll_EM_SRSS1;
//     TH2F* h_mll_EM_SRSS2;
//     TH2F* h_mll_EE_SROS1;
//     TH2F* h_mll_MM_SROS1;
//     TH2F* h_mll_EM_SROS1;
//     
//     TH2F* h_METrel_EE_SRSS1;
//     TH2F* h_METrel_EE_SRSS2;
//     TH2F* h_METrel_MM_SRSS1;  
//     TH2F* h_METrel_MM_SRSS2;  
//     TH2F* h_METrel_MM_SRSS3;
//     TH2F* h_METrel_MM_SRSS4;
//     TH2F* h_METrel_EM_SRSS1;
//     TH2F* h_METrel_EM_SRSS2;
//     TH2F* h_METrel_EE_SROS1;
//     TH2F* h_METrel_MM_SROS1;
//     TH2F* h_METrel_EM_SROS1;
//     
//     TH2F* h_MET_EE_SRSS1;
//     TH2F* h_MET_EE_SRSS2;
//     TH2F* h_MET_MM_SRSS1;  
//     TH2F* h_MET_MM_SRSS2;  
//     TH2F* h_MET_MM_SRSS3;
//     TH2F* h_MET_MM_SRSS4;
//     TH2F* h_MET_EM_SRSS1;
//     TH2F* h_MET_EM_SRSS2;
//     TH2F* h_MET_EE_SROS1;
//     TH2F* h_MET_MM_SROS1;
//     TH2F* h_MET_EM_SROS1;
//     
//     TH2F* h_HT_EE_SRSS1;
//     TH2F* h_HT_EE_SRSS2;
//     TH2F* h_HT_MM_SRSS1;  
//     TH2F* h_HT_MM_SRSS2;
//     TH2F* h_HT_MM_SRSS3;
//     TH2F* h_HT_MM_SRSS4;
//     TH2F* h_HT_EM_SRSS1;
//     TH2F* h_HT_EM_SRSS2;
//     TH2F* h_HT_EE_SROS1;
//     TH2F* h_HT_MM_SROS1;
//     TH2F* h_HT_EM_SROS1;
//     
//     TH2F* h_mWWt_EE_SRSS1;
//     TH2F* h_mWWt_EE_SRSS2;
//     TH2F* h_mWWt_MM_SRSS1;  
//     TH2F* h_mWWt_MM_SRSS2;
//     TH2F* h_mWWt_MM_SRSS3;
//     TH2F* h_mWWt_MM_SRSS4;
//     TH2F* h_mWWt_EM_SRSS1;
//     TH2F* h_mWWt_EM_SRSS2;
//     TH2F* h_mWWt_EE_SROS1;
//     TH2F* h_mWWt_MM_SROS1;
//     TH2F* h_mWWt_EM_SROS1;
//     
//     TH2F* h_mTlmin_EE_SRSS1;
//     TH2F* h_mTlmin_EE_SRSS2;
//     TH2F* h_mTlmin_MM_SRSS1;  
//     TH2F* h_mTlmin_MM_SRSS2;
//     TH2F* h_mTlmin_MM_SRSS3;
//     TH2F* h_mTlmin_MM_SRSS4;
//     TH2F* h_mTlmin_EM_SRSS1;
//     TH2F* h_mTlmin_EM_SRSS2;
//     TH2F* h_mTlmin_EE_SROS1;
//     TH2F* h_mTlmin_MM_SROS1;
//     TH2F* h_mTlmin_EM_SROS1;
//     
//     TH2F* h_mTlmax_EE_SRSS1;
//     TH2F* h_mTlmax_EE_SRSS2;
//     TH2F* h_mTlmax_MM_SRSS1;  
//     TH2F* h_mTlmax_MM_SRSS2;
//     TH2F* h_mTlmax_MM_SRSS3;
//     TH2F* h_mTlmax_MM_SRSS4;
//     TH2F* h_mTlmax_EM_SRSS1;
//     TH2F* h_mTlmax_EM_SRSS2;
//     TH2F* h_mTlmax_EE_SROS1;
//     TH2F* h_mTlmax_MM_SROS1;
//     TH2F* h_mTlmax_EM_SROS1;
// 
//     TH2F* h_meff_EE_SRSS1;
//     TH2F* h_meff_EE_SRSS2;
//     TH2F* h_meff_MM_SRSS1;
//     TH2F* h_meff_MM_SRSS2;
//     TH2F* h_meff_MM_SRSS3;
//     TH2F* h_meff_MM_SRSS4;
//     TH2F* h_meff_EM_SRSS1;
//     TH2F* h_meff_EM_SRSS2;
//     TH2F* h_meff_EE_SROS1;
//     TH2F* h_meff_MM_SROS1;
//     TH2F* h_meff_EM_SROS1;
//     
//     
//     TH2F* h_mt2_EE_SRSS1;
//     TH2F* h_mt2_EE_SRSS2;
//     TH2F* h_mt2_MM_SRSS1;
//     TH2F* h_mt2_MM_SRSS2;  
//     TH2F* h_mt2_MM_SRSS3;
//     TH2F* h_mt2_MM_SRSS4;
//     TH2F* h_mt2_EM_SRSS1;
//     TH2F* h_mt2_EM_SRSS2;
//     TH2F* h_mt2_EE_SROS1;
//     TH2F* h_mt2_MM_SROS1;
//     TH2F* h_mt2_EM_SROS1;
//     
//     TH2F* h_mt2J_EE_SRSS1;
//     TH2F* h_mt2J_EE_SRSS2;
//     TH2F* h_mt2J_MM_SRSS1;
//     TH2F* h_mt2J_MM_SRSS2;  
//     TH2F* h_mt2J_MM_SRSS3;
//     TH2F* h_mt2J_MM_SRSS4;
//     TH2F* h_mt2J_EM_SRSS1;
//     TH2F* h_mt2J_EM_SRSS2;
//     TH2F* h_mt2J_EE_SROS1;
//     TH2F* h_mt2J_MM_SROS1;
//     TH2F* h_mt2J_EM_SROS1;    
//     
//     TH2F* h_mt2J0LepM_EE_SRSS1;
//     TH2F* h_mt2J0LepM_EE_SRSS2;
//     TH2F* h_mt2J0LepM_MM_SRSS1;
//     TH2F* h_mt2J0LepM_MM_SRSS2;  
//     TH2F* h_mt2J0LepM_MM_SRSS3;
//     TH2F* h_mt2J0LepM_MM_SRSS4;
//     TH2F* h_mt2J0LepM_EM_SRSS1;
//     TH2F* h_mt2J0LepM_EM_SRSS2;
//     TH2F* h_mt2J0LepM_EE_SROS1;
//     TH2F* h_mt2J0LepM_MM_SROS1;
//     TH2F* h_mt2J0LepM_EM_SROS1;        
// 
//     TH2F* h_mjj_EE_SRSS1;
//     TH2F* h_mjj_EE_SRSS2;
//     TH2F* h_mjj_MM_SRSS1;  
//     TH2F* h_mjj_MM_SRSS2;
//     TH2F* h_mjj_MM_SRSS3;
//     TH2F* h_mjj_MM_SRSS4;
//     TH2F* h_mjj_EM_SRSS1;
//     TH2F* h_mjj_EM_SRSS2;
//     TH2F* h_mjj_EE_SROS1;
//     TH2F* h_mjj_MM_SROS1;
//     TH2F* h_mjj_EM_SROS1;
//     
//     TH2F* h_DeltaPhiMETll_EE_SRSS1;
//     TH2F* h_DeltaPhiMETll_EE_SRSS2;
//     TH2F* h_DeltaPhiMETll_MM_SRSS1;  
//     TH2F* h_DeltaPhiMETll_MM_SRSS2;
//     TH2F* h_DeltaPhiMETll_MM_SRSS3;
//     TH2F* h_DeltaPhiMETll_MM_SRSS4;
//     TH2F* h_DeltaPhiMETll_EM_SRSS1;
//     TH2F* h_DeltaPhiMETll_EM_SRSS2;
//     TH2F* h_DeltaPhiMETll_EE_SROS1;
//     TH2F* h_DeltaPhiMETll_MM_SROS1;
//     TH2F* h_DeltaPhiMETll_EM_SROS1;
//     
//     TH2F* h_DeltaPhill_EE_SRSS1;
//     TH2F* h_DeltaPhill_EE_SRSS2;
//     TH2F* h_DeltaPhill_MM_SRSS1;  
//     TH2F* h_DeltaPhill_MM_SRSS2;
//     TH2F* h_DeltaPhill_MM_SRSS3;
//     TH2F* h_DeltaPhill_MM_SRSS4;
//     TH2F* h_DeltaPhill_EM_SRSS1;
//     TH2F* h_DeltaPhill_EM_SRSS2;
//     TH2F* h_DeltaPhill_EE_SROS1;
//     TH2F* h_DeltaPhill_MM_SROS1;
//     TH2F* h_DeltaPhill_EM_SROS1;
// 
//     TH2F* h_NBJets_EE_SRSS1;
//     TH2F* h_NBJets_EE_SRSS2;
//     TH2F* h_NBJets_MM_SRSS1;  
//     TH2F* h_NBJets_MM_SRSS2;
//     TH2F* h_NBJets_MM_SRSS3;
//     TH2F* h_NBJets_MM_SRSS4;
//     TH2F* h_NBJets_EM_SRSS1;
//     TH2F* h_NBJets_EM_SRSS2;
//     TH2F* h_NBJets_EE_SROS1;
//     TH2F* h_NBJets_MM_SROS1;
//     TH2F* h_NBJets_EM_SROS1;
// 
//     TH2F* h_NCJets_EE_SRSS1;
//     TH2F* h_NCJets_EE_SRSS2;
//     TH2F* h_NCJets_MM_SRSS1;  
//     TH2F* h_NCJets_MM_SRSS2;
//     TH2F* h_NCJets_MM_SRSS3;
//     TH2F* h_NCJets_MM_SRSS4;
//     TH2F* h_NCJets_EM_SRSS1;
//     TH2F* h_NCJets_EM_SRSS2;
//     TH2F* h_NCJets_EE_SROS1;
//     TH2F* h_NCJets_MM_SROS1;
//     TH2F* h_NCJets_EM_SROS1;
// 
//     TH2F* h_NFJets_EE_SRSS1;
//     TH2F* h_NFJets_EE_SRSS2;
//     TH2F* h_NFJets_MM_SRSS1;  
//     TH2F* h_NFJets_MM_SRSS2;
//     TH2F* h_NFJets_MM_SRSS3;
//     TH2F* h_NFJets_MM_SRSS4;
//     TH2F* h_NFJets_EM_SRSS1;
//     TH2F* h_NFJets_EM_SRSS2;
//     TH2F* h_NFJets_EE_SROS1;
//     TH2F* h_NFJets_MM_SROS1;
//     TH2F* h_NFJets_EM_SROS1;
//     
//       /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhijj_EE_SRSS1; 
//   TH2F* h_DeltaPhijj_EE_SRSS2; 
//   TH2F* h_DeltaPhijj_MM_SRSS1;   
//   TH2F* h_DeltaPhijj_MM_SRSS2; 
//   TH2F* h_DeltaPhijj_MM_SRSS3; 
//   TH2F* h_DeltaPhijj_MM_SRSS4; 
//   TH2F* h_DeltaPhijj_EM_SRSS1; 
//   TH2F* h_DeltaPhijj_EM_SRSS2; 
//   TH2F* h_DeltaPhijj_EE_SROS1; 
//   TH2F* h_DeltaPhijj_MM_SROS1; 
//   TH2F* h_DeltaPhijj_EM_SROS1; 
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_pTjj_EE_SRSS1; 
//   TH2F* h_pTjj_EE_SRSS2; 
//   TH2F* h_pTjj_MM_SRSS1; 
//   TH2F* h_pTjj_MM_SRSS2; 
//   TH2F* h_pTjj_MM_SRSS3; 
//   TH2F* h_pTjj_MM_SRSS4; 
//   TH2F* h_pTjj_EM_SRSS1; 
//   TH2F* h_pTjj_EM_SRSS2; 
//   TH2F* h_pTjj_EE_SROS1; 
//   TH2F* h_pTjj_MM_SROS1; 
//   TH2F* h_pTjj_EM_SROS1; 
// 
//   /*----------------------------------------------------------------------------*/ 
//   TH2F* h_ptll_EE_SRSS1; 
//   TH2F* h_ptll_EE_SRSS2; 
//   TH2F* h_ptll_MM_SRSS1;   
//   TH2F* h_ptll_MM_SRSS2; 
//   TH2F* h_ptll_MM_SRSS3; 
//   TH2F* h_ptll_MM_SRSS4; 
//   TH2F* h_ptll_EM_SRSS1; 
//   TH2F* h_ptll_EM_SRSS2; 
//   TH2F* h_ptll_EE_SROS1; 
//   TH2F* h_ptll_MM_SROS1; 
//   TH2F* h_ptll_EM_SROS1; 
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhiMETl0_EE_SRSS1; 
//   TH2F* h_DeltaPhiMETl0_EE_SRSS2; 
//   TH2F* h_DeltaPhiMETl0_MM_SRSS1;   
//   TH2F* h_DeltaPhiMETl0_MM_SRSS2; 
//   TH2F* h_DeltaPhiMETl0_MM_SRSS3; 
//   TH2F* h_DeltaPhiMETl0_MM_SRSS4; 
//   TH2F* h_DeltaPhiMETl0_EM_SRSS1; 
//   TH2F* h_DeltaPhiMETl0_EM_SRSS2; 
//   TH2F* h_DeltaPhiMETl0_EE_SROS1; 
//   TH2F* h_DeltaPhiMETl0_MM_SROS1; 
//   TH2F* h_DeltaPhiMETl0_EM_SROS1; 
// 
//   /*-------------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhiMETl1_EE_SRSS1; 
//   TH2F* h_DeltaPhiMETl1_EE_SRSS2; 
//   TH2F* h_DeltaPhiMETl1_MM_SRSS1;   
//   TH2F* h_DeltaPhiMETl1_MM_SRSS2; 
//   TH2F* h_DeltaPhiMETl1_MM_SRSS3; 
//   TH2F* h_DeltaPhiMETl1_MM_SRSS4; 
//   TH2F* h_DeltaPhiMETl1_EM_SRSS1; 
//   TH2F* h_DeltaPhiMETl1_EM_SRSS2; 
//   TH2F* h_DeltaPhiMETl1_EE_SROS1; 
//   TH2F* h_DeltaPhiMETl1_MM_SROS1; 
//   TH2F* h_DeltaPhiMETl1_EM_SROS1; 
//   
//     /*-----------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhiMETj0_EE_SRSS1; 
//   TH2F* h_DeltaPhiMETj0_EE_SRSS2; 
//   TH2F* h_DeltaPhiMETj0_MM_SRSS1;   
//   TH2F* h_DeltaPhiMETj0_MM_SRSS2; 
//   TH2F* h_DeltaPhiMETj0_MM_SRSS3; 
//   TH2F* h_DeltaPhiMETj0_MM_SRSS4; 
//   TH2F* h_DeltaPhiMETj0_EM_SRSS1; 
//   TH2F* h_DeltaPhiMETj0_EM_SRSS2; 
//   TH2F* h_DeltaPhiMETj0_EE_SROS1; 
//   TH2F* h_DeltaPhiMETj0_MM_SROS1; 
//   TH2F* h_DeltaPhiMETj0_EM_SROS1; 
//   /*-------------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhiMETj1_EE_SRSS1; 
//   TH2F* h_DeltaPhiMETj1_EE_SRSS2; 
//   TH2F* h_DeltaPhiMETj1_MM_SRSS1;   
//   TH2F* h_DeltaPhiMETj1_MM_SRSS2; 
//   TH2F* h_DeltaPhiMETj1_MM_SRSS3; 
//   TH2F* h_DeltaPhiMETj1_MM_SRSS4; 
//   TH2F* h_DeltaPhiMETj1_EM_SRSS1; 
//   TH2F* h_DeltaPhiMETj1_EM_SRSS2; 
//   TH2F* h_DeltaPhiMETj1_EE_SROS1; 
//   TH2F* h_DeltaPhiMETj1_MM_SROS1; 
//   TH2F* h_DeltaPhiMETj1_EM_SROS1; 
// 
//   /*-------------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhiMETjj_EE_SRSS1; 
//   TH2F* h_DeltaPhiMETjj_EE_SRSS2; 
//   TH2F* h_DeltaPhiMETjj_MM_SRSS1;   
//   TH2F* h_DeltaPhiMETjj_MM_SRSS2; 
//   TH2F* h_DeltaPhiMETjj_MM_SRSS3; 
//   TH2F* h_DeltaPhiMETjj_MM_SRSS4; 
//   TH2F* h_DeltaPhiMETjj_EM_SRSS1; 
//   TH2F* h_DeltaPhiMETjj_EM_SRSS2; 
//   TH2F* h_DeltaPhiMETjj_EE_SROS1; 
//   TH2F* h_DeltaPhiMETjj_MM_SROS1; 
//   TH2F* h_DeltaPhiMETjj_EM_SROS1; 
// 
//     /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaRjj_EE_SRSS1; 
//   TH2F* h_DeltaRjj_EE_SRSS2; 
//   TH2F* h_DeltaRjj_MM_SRSS1;   
//   TH2F* h_DeltaRjj_MM_SRSS2; 
//   TH2F* h_DeltaRjj_MM_SRSS3; 
//   TH2F* h_DeltaRjj_MM_SRSS4; 
//   TH2F* h_DeltaRjj_EM_SRSS1; 
//   TH2F* h_DeltaRjj_EM_SRSS2; 
//   TH2F* h_DeltaRjj_EE_SROS1; 
//   TH2F* h_DeltaRjj_MM_SROS1; 
//   TH2F* h_DeltaRjj_EM_SROS1; 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_etal0_EE_SRSS1; 
//   TH2F* h_etal0_EE_SRSS2; 
//   TH2F* h_etal0_MM_SRSS1;   
//   TH2F* h_etal0_MM_SRSS2; 
//   TH2F* h_etal0_MM_SRSS3; 
//   TH2F* h_etal0_MM_SRSS4; 
//   TH2F* h_etal0_EM_SRSS1; 
//   TH2F* h_etal0_EM_SRSS2; 
//   TH2F* h_etal0_EE_SROS1; 
//   TH2F* h_etal0_MM_SROS1; 
//   TH2F* h_etal0_EM_SROS1; 
//     /*---------------------------------------------------------------------------*/ 
//   TH2F* h_etal1_EE_SRSS1; 
//   TH2F* h_etal1_EE_SRSS2; 
//   TH2F* h_etal1_MM_SRSS1;   
//   TH2F* h_etal1_MM_SRSS2; 
//   TH2F* h_etal1_MM_SRSS3; 
//   TH2F* h_etal1_MM_SRSS4; 
//   TH2F* h_etal1_EM_SRSS1; 
//   TH2F* h_etal1_EM_SRSS2; 
//   TH2F* h_etal1_EE_SROS1; 
//   TH2F* h_etal1_MM_SROS1; 
//   TH2F* h_etal1_EM_SROS1; 
//     /*---------------------------------------------------------------------------*/ 
//   TH2F* h_etaj0_EE_SRSS1; 
//   TH2F* h_etaj0_EE_SRSS2; 
//   TH2F* h_etaj0_MM_SRSS1;   
//   TH2F* h_etaj0_MM_SRSS2; 
//   TH2F* h_etaj0_MM_SRSS3; 
//   TH2F* h_etaj0_MM_SRSS4; 
//   TH2F* h_etaj0_EM_SRSS1; 
//   TH2F* h_etaj0_EM_SRSS2; 
//   TH2F* h_etaj0_EE_SROS1; 
//   TH2F* h_etaj0_MM_SROS1; 
//   TH2F* h_etaj0_EM_SROS1; 
//     /*---------------------------------------------------------------------------*/ 
//   TH2F* h_etaj1_EE_SRSS1; 
//   TH2F* h_etaj1_EE_SRSS2; 
//   TH2F* h_etaj1_MM_SRSS1;   
//   TH2F* h_etaj1_MM_SRSS2; 
//   TH2F* h_etaj1_MM_SRSS3; 
//   TH2F* h_etaj1_MM_SRSS4; 
//   TH2F* h_etaj1_EM_SRSS1; 
//   TH2F* h_etaj1_EM_SRSS2; 
//   TH2F* h_etaj1_EE_SROS1; 
//   TH2F* h_etaj1_MM_SROS1; 
//   TH2F* h_etaj1_EM_SROS1; 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_mTl0MET_EE_SRSS1; 
//   TH2F* h_mTl0MET_EE_SRSS2; 
//   TH2F* h_mTl0MET_MM_SRSS1;   
//   TH2F* h_mTl0MET_MM_SRSS2; 
//   TH2F* h_mTl0MET_MM_SRSS3; 
//   TH2F* h_mTl0MET_MM_SRSS4; 
//   TH2F* h_mTl0MET_EM_SRSS1; 
//   TH2F* h_mTl0MET_EM_SRSS2; 
//   TH2F* h_mTl0MET_EE_SROS1; 
//   TH2F* h_mTl0MET_MM_SROS1; 
//   TH2F* h_mTl0MET_EM_SROS1; 
//   /*-------------------------------------------------------------------------------*/ 
//   TH2F* h_mTl1MET_EE_SRSS1; 
//   TH2F* h_mTl1MET_EE_SRSS2; 
//   TH2F* h_mTl1MET_MM_SRSS1;   
//   TH2F* h_mTl1MET_MM_SRSS2; 
//   TH2F* h_mTl1MET_MM_SRSS3; 
//   TH2F* h_mTl1MET_MM_SRSS4; 
//   TH2F* h_mTl1MET_EM_SRSS1; 
//   TH2F* h_mTl1MET_EM_SRSS2; 
//   TH2F* h_mTl1MET_EE_SROS1; 
//   TH2F* h_mTl1MET_MM_SROS1; 
//   TH2F* h_mTl1MET_EM_SROS1; 
// 
//       /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhilljj_EE_SRSS1; 
//   TH2F* h_DeltaPhilljj_EE_SRSS2; 
//   TH2F* h_DeltaPhilljj_MM_SRSS1;   
//   TH2F* h_DeltaPhilljj_MM_SRSS2; 
//   TH2F* h_DeltaPhilljj_MM_SRSS3; 
//   TH2F* h_DeltaPhilljj_MM_SRSS4; 
//   TH2F* h_DeltaPhilljj_EM_SRSS1; 
//   TH2F* h_DeltaPhilljj_EM_SRSS2; 
//   TH2F* h_DeltaPhilljj_EE_SROS1; 
//   TH2F* h_DeltaPhilljj_MM_SROS1; 
//   TH2F* h_DeltaPhilljj_EM_SROS1; 
//   /*------------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhil0jj_EE_SRSS1; 
//   TH2F* h_DeltaPhil0jj_EE_SRSS2; 
//   TH2F* h_DeltaPhil0jj_MM_SRSS1;   
//   TH2F* h_DeltaPhil0jj_MM_SRSS2; 
//   TH2F* h_DeltaPhil0jj_MM_SRSS3; 
//   TH2F* h_DeltaPhil0jj_MM_SRSS4; 
//   TH2F* h_DeltaPhil0jj_EM_SRSS1; 
//   TH2F* h_DeltaPhil0jj_EM_SRSS2; 
//   TH2F* h_DeltaPhil0jj_EE_SROS1; 
//   TH2F* h_DeltaPhil0jj_MM_SROS1; 
//   TH2F* h_DeltaPhil0jj_EM_SROS1; 
//   /*------------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaPhil1jj_EE_SRSS1; 
//   TH2F* h_DeltaPhil1jj_EE_SRSS2; 
//   TH2F* h_DeltaPhil1jj_MM_SRSS1;   
//   TH2F* h_DeltaPhil1jj_MM_SRSS2; 
//   TH2F* h_DeltaPhil1jj_MM_SRSS3; 
//   TH2F* h_DeltaPhil1jj_MM_SRSS4; 
//   TH2F* h_DeltaPhil1jj_EM_SRSS1; 
//   TH2F* h_DeltaPhil1jj_EM_SRSS2; 
//   TH2F* h_DeltaPhil1jj_EE_SROS1; 
//   TH2F* h_DeltaPhil1jj_MM_SROS1; 
//   TH2F* h_DeltaPhil1jj_EM_SROS1; 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaRlljj_EE_SRSS1; 
//   TH2F* h_DeltaRlljj_EE_SRSS2; 
//   TH2F* h_DeltaRlljj_MM_SRSS1;   
//   TH2F* h_DeltaRlljj_MM_SRSS2; 
//   TH2F* h_DeltaRlljj_MM_SRSS3; 
//   TH2F* h_DeltaRlljj_MM_SRSS4; 
//   TH2F* h_DeltaRlljj_EM_SRSS1; 
//   TH2F* h_DeltaRlljj_EM_SRSS2; 
//   TH2F* h_DeltaRlljj_EE_SROS1; 
//   TH2F* h_DeltaRlljj_MM_SROS1; 
//   TH2F* h_DeltaRlljj_EM_SROS1; 
// 
//     /*--------------------------------------------------------------------------------*/   
//   TH2F* h_DeltaEtajj_EE_SRSS1; 
//   TH2F* h_DeltaEtajj_EE_SRSS2; 
//   TH2F* h_DeltaEtajj_MM_SRSS1;   
//   TH2F* h_DeltaEtajj_MM_SRSS2; 
//   TH2F* h_DeltaEtajj_MM_SRSS3; 
//   TH2F* h_DeltaEtajj_MM_SRSS4; 
//   TH2F* h_DeltaEtajj_EM_SRSS1; 
//   TH2F* h_DeltaEtajj_EM_SRSS2; 
//   TH2F* h_DeltaEtajj_EE_SROS1; 
//   TH2F* h_DeltaEtajj_MM_SROS1; 
//   TH2F* h_DeltaEtajj_EM_SROS1;   
//   
//       /*--------------------------------------------------------------------------------*/   
//   TH2F* h_DeltaEtall_EE_SRSS1; 
//   TH2F* h_DeltaEtall_EE_SRSS2; 
//   TH2F* h_DeltaEtall_MM_SRSS1;   
//   TH2F* h_DeltaEtall_MM_SRSS2; 
//   TH2F* h_DeltaEtall_MM_SRSS3; 
//   TH2F* h_DeltaEtall_MM_SRSS4; 
//   TH2F* h_DeltaEtall_EM_SRSS1; 
//   TH2F* h_DeltaEtall_EM_SRSS2; 
//   TH2F* h_DeltaEtall_EE_SROS1; 
//   TH2F* h_DeltaEtall_MM_SROS1; 
//   TH2F* h_DeltaEtall_EM_SROS1;   
// 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_mTll_EE_SRSS1; 
//   TH2F* h_mTll_EE_SRSS2; 
//   TH2F* h_mTll_MM_SRSS1;   
//   TH2F* h_mTll_MM_SRSS2; 
//   TH2F* h_mTll_MM_SRSS3; 
//   TH2F* h_mTll_MM_SRSS4; 
//   TH2F* h_mTll_EM_SRSS1; 
//   TH2F* h_mTll_EM_SRSS2; 
//   TH2F* h_mTll_EE_SROS1; 
//   TH2F* h_mTll_MM_SROS1; 
//   TH2F* h_mTll_EM_SROS1; 
// 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_mMETll_EE_SRSS1; 
//   TH2F* h_mMETll_EE_SRSS2; 
//   TH2F* h_mMETll_MM_SRSS1;   
//   TH2F* h_mMETll_MM_SRSS2; 
//   TH2F* h_mMETll_MM_SRSS3; 
//   TH2F* h_mMETll_MM_SRSS4; 
//   TH2F* h_mMETll_EM_SRSS1; 
//   TH2F* h_mMETll_EM_SRSS2; 
//   TH2F* h_mMETll_EE_SROS1; 
//   TH2F* h_mMETll_MM_SROS1; 
//   TH2F* h_mMETll_EM_SROS1; 
// 
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_DeltaYjj_EE_SRSS1; 
//   TH2F* h_DeltaYjj_EE_SRSS2; 
//   TH2F* h_DeltaYjj_MM_SRSS1;  
//   TH2F* h_DeltaYjj_MM_SRSS2; 
//   TH2F* h_DeltaYjj_MM_SRSS3; 
//   TH2F* h_DeltaYjj_MM_SRSS4; 
//   TH2F* h_DeltaYjj_EM_SRSS1; 
//   TH2F* h_DeltaYjj_EM_SRSS2; 
//   TH2F* h_DeltaYjj_EE_SROS1; 
//   TH2F* h_DeltaYjj_MM_SROS1; 
//   TH2F* h_DeltaYjj_EM_SROS1; 
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_D0_branch_l0_EE_SRSS1;
//   TH2F* h_D0_branch_l0_EE_SRSS2;
//   TH2F* h_D0_branch_l0_MM_SRSS1;  
//   TH2F* h_D0_branch_l0_MM_SRSS2;
//   TH2F* h_D0_branch_l0_MM_SRSS3;
//   TH2F* h_D0_branch_l0_MM_SRSS4;
//   TH2F* h_D0_branch_l0_EM_SRSS1;
//   TH2F* h_D0_branch_l0_EM_SRSS2;
//   TH2F* h_D0_branch_l0_EE_SROS1;
//   TH2F* h_D0_branch_l0_MM_SROS1;
//   TH2F* h_D0_branch_l0_EM_SROS1;
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_D0_branch_l1_EE_SRSS1;
//   TH2F* h_D0_branch_l1_EE_SRSS2;
//   TH2F* h_D0_branch_l1_MM_SRSS1;  
//   TH2F* h_D0_branch_l1_MM_SRSS2;
//   TH2F* h_D0_branch_l1_MM_SRSS3;
//   TH2F* h_D0_branch_l1_MM_SRSS4;
//   TH2F* h_D0_branch_l1_EM_SRSS1;
//   TH2F* h_D0_branch_l1_EM_SRSS2;
//   TH2F* h_D0_branch_l1_EE_SROS1;
//   TH2F* h_D0_branch_l1_MM_SROS1;
//   TH2F* h_D0_branch_l1_EM_SROS1;
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_D0Signif_branch_l0_EE_SRSS1;
//   TH2F* h_D0Signif_branch_l0_EE_SRSS2;
//   TH2F* h_D0Signif_branch_l0_MM_SRSS1;  
//   TH2F* h_D0Signif_branch_l0_MM_SRSS2;
//   TH2F* h_D0Signif_branch_l0_MM_SRSS3;
//   TH2F* h_D0Signif_branch_l0_MM_SRSS4;
//   TH2F* h_D0Signif_branch_l0_EM_SRSS1;
//   TH2F* h_D0Signif_branch_l0_EM_SRSS2;
//   TH2F* h_D0Signif_branch_l0_EE_SROS1;
//   TH2F* h_D0Signif_branch_l0_MM_SROS1;
//   TH2F* h_D0Signif_branch_l0_EM_SROS1;
//   
//   /*--------------------------------------------------------------------------------*/ 
//   TH2F* h_D0Signif_branch_l1_EE_SRSS1;
//   TH2F* h_D0Signif_branch_l1_EE_SRSS2;
//   TH2F* h_D0Signif_branch_l1_MM_SRSS1;  
//   TH2F* h_D0Signif_branch_l1_MM_SRSS2;
//   TH2F* h_D0Signif_branch_l1_MM_SRSS3;
//   TH2F* h_D0Signif_branch_l1_MM_SRSS4;
//   TH2F* h_D0Signif_branch_l1_EM_SRSS1;
//   TH2F* h_D0Signif_branch_l1_EM_SRSS2;
//   TH2F* h_D0Signif_branch_l1_EE_SROS1;
//   TH2F* h_D0Signif_branch_l1_MM_SROS1;
//   TH2F* h_D0Signif_branch_l1_EM_SROS1;
  
    
    SUSYObjDef m_susyObj;      // SUSY object definitions
    
    TSelector_SusyNtuple();
    virtual ~TSelector_SusyNtuple(){};

    // Output Text File
    ofstream out;

    // Begin is called before looping on entries
    virtual void    Begin(TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
    // Terminate is called after looping is finished
    virtual void    Terminate();
    virtual void    SlaveTerminate();

    // Main event loop function
    virtual Bool_t  Process(Long64_t entry);
		     
    // Cut methods
    bool CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons);
    bool CheckChargeFlipElectrons(const ElectronVector& signal_electrons);
    float getBTagWeight(const Event* evt);
    float recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const JetVector& jets, bool useForward);
    float calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1);
    float calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1);
    float calcMT2J0LepM(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1);
    bool checkLeptonPt(const LeptonVector& leptons);
    float mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue);
    float calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, const JetVector &signalJets);
    float calcMeff(TLorentzVector met, const JetVector &signalJets);
    float calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met);
    float calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type);
    float calcMt(TLorentzVector _l, TLorentzVector _nu);
    float calcSumMv1(const JetVector &signalJets);
    
    bool defineHistos();
    bool writeHistos();
    bool addHistos();
    void fillHistos_EE(int cutnumber, float weight);
    void fillHistos_MM(int cutnumber, float weight);
    void fillHistos_EM(int cutnumber, float weight);
    
    void calcJet_variables(TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, TLorentzVector met_TLV);
    void calc_EE_variables(LeptonVector &leptons, Electron* el0, Electron* el1, TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EE);
    void calc_MM_variables(LeptonVector &leptons, Muon* mu0, Muon* mu1, TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_MM);
    void calc_EM_variables(LeptonVector &leptons, Electron* el, Muon* mu, TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EM);
    
    void fillHistos_EE_SRSS1(float cut_EE, int mcid, float weight_ALL_EE);    
    void fillHistos_MM_SRSS1(float cut_MM, int mcid, float weight_ALL_MM);    
    void fillHistos_EM_SRSS1(float cut_EM, int mcid, float weight_ALL_EM);
    
    float getFakeWeight(const LeptonVector &baseLeps, SusyMatrixMethod::FAKE_REGION region, float metRel, SusyMatrixMethod::SYSTEMATIC sys);
    
    float calc_D0(bool unbiased, const Lepton* lep);
    static bool compareElecMomentum (Electron* e0, Electron* e1);
    static bool compareMuonMomentum (Muon* mu0, Muon* mu1);
    ElectronVector getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys);
    ElectronVector getOverlapElectrons(SusyNtObject* susyNt, SusyNtSys sys);
    MuonVector getSoftMuons(SusyNtObject* susyNt, SusyNtSys sys);
    MuonVector getOverlapMuons(SusyNtObject* susyNt, SusyNtSys sys);
    bool isCMSJet(const Susy::Jet* jet);
    int numberOfCMSJets(const JetVector& jets);    
    vector<TLorentzVector> overlapRemoval(vector<TLorentzVector> objects_type1, vector<TLorentzVector> indices_2, double dr, bool sameType, bool removeSoft) ;
    bool doEventCleaning_andFillHistos(int flag, float weight_ALL_EE, float weight_ALL_MM, float weight_ALL_EM);

    // Selection region
    void setSelection(std::string s) { m_sel = s; }

    // debug check
    bool debugEvent();
    Analysis::AnalysisMuonConfigurableScaleFactors* m_muon_scaleFactor;

    int nSignalJets;
    float MET;
    float pTj0;
    float pTj1;
    float eta_j0;
    float eta_j1;
    float mjj;
    float DeltaPhijj;
    float pTjj;
    float DeltaPhiMETj0;
    float DeltaPhiMETj1;
    float DeltaRjj;
    float DeltaEtajj;
    float DeltaYjj;
    float DeltaPhiMETjj;
    int NBJets;
    int NCJets;
    int NFJets;
    float meff;
    
    float mZTT_coll;
    float mZTT_mmc; 
    
    //#####################################
    float ptel0;
    float ptel1;
    float eta_el0;
    float eta_el1;
    float DeltaRee;
    float pTee;
    float Mee;
    float METrelee;
    float METee;
    float HT_EE;
    float mTWW_EE;
    float mTee;
    float mTemin;
    float mTemax;
    float mTel0MET;
    float mTel1MET;
    float mMETee;
    float DeltaPhiEE;
    float DeltaPhiMETel0;
    float DeltaPhiMETel1;
    float DeltaPhiMETee;
    float mt2_ee;  
    float mt2J_ee;      
    float mt2J0LepM_ee;      
    float DeltaPhieejj;
    float DeltaPhiel0jj;
    float DeltaPhiel1jj;
    float DeltaReejj;
    float Mljj_EE;
    float DeltaEtaee;
    
    float D0_branch_el0;
    float D0_branch_el1;
    float D0err_branch_el0;
    float D0err_branch_el1;
    
    float sD0Signif_branch_el0;
    float sD0Signif_branch_el1;

    int Nleptons_lost_EE;
    float ml0llost_EE;      
    float mTl0llost_EE;
    int ICl0llost_EE;
    float pTl0llost_EE;
    float etal0llost_EE;
    float ptcone30l0llost_EE;
    float d0Sigl0llost_EE;
    float z0SinThetal0llost_EE;    
    float ml1llost_EE;
    float mTl1llost_EE;
    int ICl1llost_EE;
    float pTl1llost_EE;
    float etal1llost_EE;
    float ptcone30l1llost_EE;
    float d0Sigl1llost_EE;
    float z0SinThetal1llost_EE;

    int Nleptons_soft_EE;
    float ml0lsoft_EE;      
    float mTl0lsoft_EE;
    int ICl0lsoft_EE;
    float pTl0lsoft_EE;
    float etal0lsoft_EE;
    float ptcone30l0lsoft_EE;
    float d0Sigl0lsoft_EE;
    float z0SinThetal0lsoft_EE;    
    float ml1lsoft_EE;
    float mTl1lsoft_EE;
    int ICl1lsoft_EE;
    float pTl1lsoft_EE;
    float etal1lsoft_EE;
    float ptcone30l1lsoft_EE;
    float d0Sigl1lsoft_EE;
    float z0SinThetal1lsoft_EE;
    
    int Nleptons_overlap_EE;
    float ml0loverlap_EE;      
    float mTl0loverlap_EE;
    int ICl0loverlap_EE;
    float pTl0loverlap_EE;
    float etal0loverlap_EE;
    float ptcone30l0loverlap_EE;
    float d0Sigl0loverlap_EE;
    float z0SinThetal0loverlap_EE;    
    float ml1loverlap_EE;
    float mTl1loverlap_EE;
    int ICl1loverlap_EE;
    float pTl1loverlap_EE;
    float etal1loverlap_EE;
    float ptcone30l1loverlap_EE;
    float d0Sigl1loverlap_EE;
    float z0SinThetal1loverlap_EE;

    int Nleptons_overlapWJet_EE;
    float ml0loverlapWJet_EE;      
    float mTl0loverlapWJet_EE;
    int ICl0loverlapWJet_EE;
    float pTl0loverlapWJet_EE;
    float etal0loverlapWJet_EE;
    float ptcone30l0loverlapWJet_EE;
    float d0Sigl0loverlapWJet_EE;
    float z0SinThetal0loverlapWJet_EE;    
    float ml1loverlapWJet_EE;
    float mTl1loverlapWJet_EE;
    int ICl1loverlapWJet_EE;
    float pTl1loverlapWJet_EE;
    float etal1loverlapWJet_EE;
    float ptcone30l1loverlapWJet_EE;
    float d0Sigl1loverlapWJet_EE;
    float z0SinThetal1loverlapWJet_EE;
        
    int Nleptons_overlapWOFLepton_EE;
    float ml0loverlapWOFLepton_EE;      
    float mTl0loverlapWOFLepton_EE;
    int ICl0loverlapWOFLepton_EE;
    float pTl0loverlapWOFLepton_EE;
    float etal0loverlapWOFLepton_EE;
    float ptcone30l0loverlapWOFLepton_EE;
    float d0Sigl0loverlapWOFLepton_EE;
    float z0SinThetal0loverlapWOFLepton_EE;    
    float ml1loverlapWOFLepton_EE;
    float mTl1loverlapWOFLepton_EE;
    int ICl1loverlapWOFLepton_EE;
    float pTl1loverlapWOFLepton_EE;
    float etal1loverlapWOFLepton_EE;
    float ptcone30l1loverlapWOFLepton_EE;
    float d0Sigl1loverlapWOFLepton_EE;
    float z0SinThetal1loverlapWOFLepton_EE;
        
    int Nleptons_overlapWSFLepton_EE;
    float ml0loverlapWSFLepton_EE;      
    float mTl0loverlapWSFLepton_EE;
    int ICl0loverlapWSFLepton_EE;
    float pTl0loverlapWSFLepton_EE;
    float etal0loverlapWSFLepton_EE;
    float ptcone30l0loverlapWSFLepton_EE;
    float d0Sigl0loverlapWSFLepton_EE;
    float z0SinThetal0loverlapWSFLepton_EE;    
    float ml1loverlapWSFLepton_EE;
    float mTl1loverlapWSFLepton_EE;
    int ICl1loverlapWSFLepton_EE;
    float pTl1loverlapWSFLepton_EE;
    float etal1loverlapWSFLepton_EE;
    float ptcone30l1loverlapWSFLepton_EE;
    float d0Sigl1loverlapWSFLepton_EE;
    float z0SinThetal1loverlapWSFLepton_EE;
    
    int Nleptons_Zcand_EE;
    float ml0lZcand_EE;      
    float mTl0lZcand_EE;
    int ICl0lZcand_EE;
    float pTl0lZcand_EE;
    float etal0lZcand_EE;
    float ptcone30l0lZcand_EE;
    float d0Sigl0lZcand_EE;
    float z0SinThetal0lZcand_EE;    
    float ml1lZcand_EE;
    float mTl1lZcand_EE;
    int ICl1lZcand_EE;
    float pTl1lZcand_EE;
    float etal1lZcand_EE;
    float ptcone30l1lZcand_EE;
    float d0Sigl1lZcand_EE;
    float z0SinThetal1lZcand_EE;
    
    
    //#####################################
    
    float ptmu0;
    float ptmu1;
    float eta_mu0;
    float eta_mu1;
    float DeltaRmm;
    float pTmm;
    float Mmm;
    float mTmm;
    float METrelmm;
    float METmm;
    float HT_MM;
    float mTWW_MM;
    float mTmmin;
    float mTmmax;
    float mTmu0MET;
    float mTmu1MET;
    float mMETmm;
    float DeltaPhiMM;
    float DeltaPhiMETmu0;
    float DeltaPhiMETmu1;
    float DeltaPhiMETmm;
    float mt2_mm;
    float mt2J_mm;    
    float mt2J0LepM_mm;    
    
    float DeltaPhimmjj;
    float DeltaPhimu0jj;
    float DeltaPhimu1jj;
    float DeltaRmmjj;
    float Mljj_MM;
    float DeltaEtamm;

    float D0_branch_mu0;
    float D0_branch_mu1;
    float D0err_branch_mu0;
    float D0err_branch_mu1;
    
    float sD0Signif_branch_mu0;
    float sD0Signif_branch_mu1;

    int N_MuonToBeChecked_afterORWJet_MM;
    int N_MuonToBeChecked_afterORWOFLepton_MM;
    int N_MuonToBeChecked_afterORWSFLepton_MM;
    int N_MuonToBeChecked_afterMllCut_MM;
    int Nleptons_lost_MM;
    float ml0llost_MM;      
    float mTl0llost_MM;
    int ICl0llost_MM;
    float pTl0llost_MM;
    float etal0llost_MM;
    float ptcone30l0llost_MM;
    float d0Sigl0llost_MM;
    float z0SinThetal0llost_MM;    
    float ml1llost_MM;
    float mTl1llost_MM;
    int ICl1llost_MM;
    float pTl1llost_MM;
    float etal1llost_MM;
    float ptcone30l1llost_MM;
    float d0Sigl1llost_MM;
    float z0SinThetal1llost_MM;

    int Nleptons_soft_MM;
    float ml0lsoft_MM;      
    float mTl0lsoft_MM;
    int ICl0lsoft_MM;
    float pTl0lsoft_MM;
    float etal0lsoft_MM;
    float ptcone30l0lsoft_MM;
    float d0Sigl0lsoft_MM;
    float z0SinThetal0lsoft_MM;    
    float ml1lsoft_MM;
    float mTl1lsoft_MM;
    int ICl1lsoft_MM;
    float pTl1lsoft_MM;
    float etal1lsoft_MM;
    float ptcone30l1lsoft_MM;
    float d0Sigl1lsoft_MM;
    float z0SinThetal1lsoft_MM;
    
    int Nleptons_overlap_MM;
    float ml0loverlap_MM;      
    float mTl0loverlap_MM;
    int ICl0loverlap_MM;
    float pTl0loverlap_MM;
    float etal0loverlap_MM;
    float ptcone30l0loverlap_MM;
    float d0Sigl0loverlap_MM;
    float z0SinThetal0loverlap_MM;    
    float ml1loverlap_MM;
    float mTl1loverlap_MM;
    int ICl1loverlap_MM;
    float pTl1loverlap_MM;
    float etal1loverlap_MM;
    float ptcone30l1loverlap_MM;
    float d0Sigl1loverlap_MM;
    float z0SinThetal1loverlap_MM;

    int Nleptons_overlapWJet_MM;
    float ml0loverlapWJet_MM;      
    float mTl0loverlapWJet_MM;
    int ICl0loverlapWJet_MM;
    float pTl0loverlapWJet_MM;
    float etal0loverlapWJet_MM;
    float ptcone30l0loverlapWJet_MM;
    float d0Sigl0loverlapWJet_MM;
    float z0SinThetal0loverlapWJet_MM;    
    float ml1loverlapWJet_MM;
    float mTl1loverlapWJet_MM;
    int ICl1loverlapWJet_MM;
    float pTl1loverlapWJet_MM;
    float etal1loverlapWJet_MM;
    float ptcone30l1loverlapWJet_MM;
    float d0Sigl1loverlapWJet_MM;
    float z0SinThetal1loverlapWJet_MM;
        
    int Nleptons_overlapWOFLepton_MM;
    float ml0loverlapWOFLepton_MM;      
    float mTl0loverlapWOFLepton_MM;
    int ICl0loverlapWOFLepton_MM;
    float pTl0loverlapWOFLepton_MM;
    float etal0loverlapWOFLepton_MM;
    float ptcone30l0loverlapWOFLepton_MM;
    float d0Sigl0loverlapWOFLepton_MM;
    float z0SinThetal0loverlapWOFLepton_MM;    
    float ml1loverlapWOFLepton_MM;
    float mTl1loverlapWOFLepton_MM;
    int ICl1loverlapWOFLepton_MM;
    float pTl1loverlapWOFLepton_MM;
    float etal1loverlapWOFLepton_MM;
    float ptcone30l1loverlapWOFLepton_MM;
    float d0Sigl1loverlapWOFLepton_MM;
    float z0SinThetal1loverlapWOFLepton_MM;
        
    int Nleptons_overlapWSFLepton_MM;
    float ml0loverlapWSFLepton_MM;      
    float mTl0loverlapWSFLepton_MM;
    int ICl0loverlapWSFLepton_MM;
    float pTl0loverlapWSFLepton_MM;
    float etal0loverlapWSFLepton_MM;
    float ptcone30l0loverlapWSFLepton_MM;
    float d0Sigl0loverlapWSFLepton_MM;
    float z0SinThetal0loverlapWSFLepton_MM;    
    float ml1loverlapWSFLepton_MM;
    float mTl1loverlapWSFLepton_MM;
    int ICl1loverlapWSFLepton_MM;
    float pTl1loverlapWSFLepton_MM;
    float etal1loverlapWSFLepton_MM;
    float ptcone30l1loverlapWSFLepton_MM;
    float d0Sigl1loverlapWSFLepton_MM;
    float z0SinThetal1loverlapWSFLepton_MM;
    
    int Nleptons_Zcand_MM;
    float ml0lZcand_MM;      
    float mTl0lZcand_MM;
    int ICl0lZcand_MM;
    float pTl0lZcand_MM;
    float etal0lZcand_MM;
    float ptcone30l0lZcand_MM;
    float d0Sigl0lZcand_MM;
    float z0SinThetal0lZcand_MM;    
    float ml1lZcand_MM;
    float mTl1lZcand_MM;
    int ICl1lZcand_MM;
    float pTl1lZcand_MM;
    float etal1lZcand_MM;
    float ptcone30l1lZcand_MM;
    float d0Sigl1lZcand_MM;
    float z0SinThetal1lZcand_MM;
    
    //#####################################
    
    float ptl0;
    float ptl1;
    float eta_l0;
    float eta_l1;
    float DeltaRem;
    float pTem;
    float Mem;
    float mTem;
    float METrelem;
    float METem;
    float HT_EM;
    float mTWW_EM;
    float mTemmin;
    float mTemmax;
    float mTl0MET;
    float mTl1MET;
    float mMETem;
    float DeltaPhiEM;
    float DeltaPhiMETl0;
    float DeltaPhiMETl1;
    float DeltaPhiMETem;
    float mt2_em;
    float mt2J_em;    
    float mt2J0LepM_em;    
    
    float DeltaPhiEMjj;
    float DeltaPhil0jj;
    float DeltaPhil1jj;
    float DeltaRemjj;
    float Mljj_EM;
    float DeltaEtaem;

    float D0_branch_l0;
    float D0_branch_l1;
    float D0err_branch_l0;
    float D0err_branch_l1;   
    
    float sD0Signif_branch_l0;
    float sD0Signif_branch_l1;
    
    int N_MuonToBeChecked_afterORWJet_EM;
    int N_MuonToBeChecked_afterORWOFLepton_EM;
    int N_MuonToBeChecked_afterORWSFLepton_EM;    
    int N_MuonToBeChecked_afterMllCut_EM; 
    int N_ElecronToBeChecked_afterORWJet_EM;
    int N_ElectronToBeChecked_afterORWOFLepton_EM;
    int N_ElectronToBeChecked_afterMllCut_EM;

    int Nleptons_lost_EM;
    float ml0llost_EM;      
    float mTl0llost_EM;
    int ICl0llost_EM;
    float pTl0llost_EM;
    float etal0llost_EM;
    float ptcone30l0llost_EM;
    float d0Sigl0llost_EM;
    float z0SinThetal0llost_EM;    
    float ml1llost_EM;
    float mTl1llost_EM;
    int ICl1llost_EM;
    float pTl1llost_EM;
    float etal1llost_EM;
    float ptcone30l1llost_EM;
    float d0Sigl1llost_EM;
    float z0SinThetal1llost_EM;

    int Nleptons_soft_EM;
    float ml0lsoft_EM;      
    float mTl0lsoft_EM;
    int ICl0lsoft_EM;
    float pTl0lsoft_EM;
    float etal0lsoft_EM;
    float ptcone30l0lsoft_EM;
    float d0Sigl0lsoft_EM;
    float z0SinThetal0lsoft_EM;    
    float ml1lsoft_EM;
    float mTl1lsoft_EM;
    int ICl1lsoft_EM;
    float pTl1lsoft_EM;
    float etal1lsoft_EM;
    float ptcone30l1lsoft_EM;
    float d0Sigl1lsoft_EM;
    float z0SinThetal1lsoft_EM;
    
    int Nleptons_overlap_EM;
    float ml0loverlap_EM;      
    float mTl0loverlap_EM;
    int ICl0loverlap_EM;
    float pTl0loverlap_EM;
    float etal0loverlap_EM;
    float ptcone30l0loverlap_EM;
    float d0Sigl0loverlap_EM;
    float z0SinThetal0loverlap_EM;    
    float ml1loverlap_EM;
    float mTl1loverlap_EM;
    int ICl1loverlap_EM;
    float pTl1loverlap_EM;
    float etal1loverlap_EM;
    float ptcone30l1loverlap_EM;
    float d0Sigl1loverlap_EM;
    float z0SinThetal1loverlap_EM;

    int Nleptons_overlapWJet_EM;
    float ml0loverlapWJet_EM;      
    float mTl0loverlapWJet_EM;
    int ICl0loverlapWJet_EM;
    float pTl0loverlapWJet_EM;
    float etal0loverlapWJet_EM;
    float ptcone30l0loverlapWJet_EM;
    float d0Sigl0loverlapWJet_EM;
    float z0SinThetal0loverlapWJet_EM;    
    float ml1loverlapWJet_EM;
    float mTl1loverlapWJet_EM;
    int ICl1loverlapWJet_EM;
    float pTl1loverlapWJet_EM;
    float etal1loverlapWJet_EM;
    float ptcone30l1loverlapWJet_EM;
    float d0Sigl1loverlapWJet_EM;
    float z0SinThetal1loverlapWJet_EM;
        
    int Nleptons_overlapWOFLepton_EM;
    float ml0loverlapWOFLepton_EM;      
    float mTl0loverlapWOFLepton_EM;
    int ICl0loverlapWOFLepton_EM;
    float pTl0loverlapWOFLepton_EM;
    float etal0loverlapWOFLepton_EM;
    float ptcone30l0loverlapWOFLepton_EM;
    float d0Sigl0loverlapWOFLepton_EM;
    float z0SinThetal0loverlapWOFLepton_EM;    
    float ml1loverlapWOFLepton_EM;
    float mTl1loverlapWOFLepton_EM;
    int ICl1loverlapWOFLepton_EM;
    float pTl1loverlapWOFLepton_EM;
    float etal1loverlapWOFLepton_EM;
    float ptcone30l1loverlapWOFLepton_EM;
    float d0Sigl1loverlapWOFLepton_EM;
    float z0SinThetal1loverlapWOFLepton_EM;
        
    int Nleptons_overlapWSFLepton_EM;
    float ml0loverlapWSFLepton_EM;      
    float mTl0loverlapWSFLepton_EM;
    int ICl0loverlapWSFLepton_EM;
    float pTl0loverlapWSFLepton_EM;
    float etal0loverlapWSFLepton_EM;
    float ptcone30l0loverlapWSFLepton_EM;
    float d0Sigl0loverlapWSFLepton_EM;
    float z0SinThetal0loverlapWSFLepton_EM;    
    float ml1loverlapWSFLepton_EM;
    float mTl1loverlapWSFLepton_EM;
    int ICl1loverlapWSFLepton_EM;
    float pTl1loverlapWSFLepton_EM;
    float etal1loverlapWSFLepton_EM;
    float ptcone30l1loverlapWSFLepton_EM;
    float d0Sigl1loverlapWSFLepton_EM;
    float z0SinThetal1loverlapWSFLepton_EM;
    
    int Nleptons_Zcand_EM;
    float ml0lZcand_EM;      
    float mTl0lZcand_EM;
    int ICl0lZcand_EM;
    float pTl0lZcand_EM;
    float etal0lZcand_EM;
    float ptcone30l0lZcand_EM;
    float d0Sigl0lZcand_EM;
    float z0SinThetal0lZcand_EM;    
    float ml1lZcand_EM;
    float mTl1lZcand_EM;
    int ICl1lZcand_EM;
    float pTl1lZcand_EM;
    float etal1lZcand_EM;
    float ptcone30l1lZcand_EM;
    float d0Sigl1lZcand_EM;
    float z0SinThetal1lZcand_EM;

    float etcone30l0llost_EM;
    float etcone30l0lsoft_EM;
    float etcone30l0loverlap_EM;
    float etcone30l0loverlapWJet_EM;
    float etcone30l0loverlapWOFLepton;
    float etcone30l0loverlapWSFLepton;
    float etcone20l0lZcand_EM;
    float etcone30l1llost_EM;
    float etcone30l1lsoft_EM;
    float etcone30l1loverlap_EM;
    float etcone30l1loverlapWJet_EM;
    float etcone30l1loverlapWOFLepton_EM;
    float etcone30l1loverlapWSFLepton_EM;
    float etcone30l1lZcand_EM;
   
    
    //#####################################
    
    ClassDef(TSelector_SusyNtuple, 1);

  protected:
    int sample_identifier;
    std::string         m_sel;          // event selection string

    DilTrigLogic*      m_trigObjWithoutRU;      // My trigger logic class
    chargeFlip m_chargeFlip;
    SusyMatrixMethod::DiLeptonMatrixMethod* m_matrix;
    //initialize missing mass calculator MMC for identification of Z->tau tau events
    mmc MMC_sumet;
//     TGuiUtils* GuiUtils;

    // Cut variables
    
    bool                m_selectB;      // switch to select b-tagged jets
    bool                m_vetoB;        // switch to veto b-tagged jets
    bool                m_selectSFOS;   // switch to select SFOS pairs
    bool                m_vetoSFOS;     // switch to veto SFOS pairs

    bool                m_writeOut;     // switch to control output dump

    
    RecoTruthMatch                m_recoTruthMatch;       // Lepton truth matching tool
    
  int mcid_of_first_entry;
  float sumw_from_histo;
  
  bool m_kIsData;
  bool runWithPoD;
  bool calcFakeContribution; 
  
  enum LEP_TYPE{PR=0, CONV, HF, LF, TYPE_Undef};
  
};

#endif
