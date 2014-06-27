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

#ifndef __CINT__
#include "ChargeFlip/ChargeFlip.h"
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
    
    TH1F* h_D0Signif_recalc_PR_elec;
    TH1F* h_D0Signif_recalc_HF_elec;
    TH1F* h_D0Signif_recalc_LF_elec;
    TH1F* h_D0Signif_recalc_elec;
    
    TH1F* h_D0Signif_recalc_PR_muon;
    TH1F* h_D0Signif_recalc_HF_muon;
    TH1F* h_D0Signif_recalc_LF_muon;  
    TH1F* h_D0Signif_recalc_muon;  
    
    TH1F* h_D0_recalc_PR_elec;
    TH1F* h_D0_recalc_HF_elec;
    TH1F* h_D0_recalc_LF_elec;
    TH1F* h_D0_recalc_elec;
    
    TH1F* h_D0_recalc_PR_muon;
    TH1F* h_D0_recalc_HF_muon;
    TH1F* h_D0_recalc_LF_muon;
    TH1F* h_D0_recalc_muon;
    
    TH1F* h_jetTruthInfo_elec;
    TH1F* h_jetTruthInfo_muon;
    
    TH2F* h_DeltaRLeptons_EE_SRSS1;
    TH2F* h_DeltaRLeptons_EE_SRSS2;
    TH2F* h_DeltaRLeptons_MM_SRSS1;
    TH2F* h_DeltaRLeptons_MM_SRSS2;
    TH2F* h_DeltaRLeptons_MM_SRSS3;
    TH2F* h_DeltaRLeptons_MM_SRSS4;
    TH2F* h_DeltaRLeptons_EM_SRSS1;
    TH2F* h_DeltaRLeptons_EM_SRSS2;
    TH2F* h_DeltaRLeptons_EE_SROS1;
    TH2F* h_DeltaRLeptons_MM_SROS1;
    TH2F* h_DeltaRLeptons_EM_SROS1;
    
    TH2F* h_mZTT_coll_EE_SRSS1;
    TH2F* h_mZTT_coll_EE_SRSS2;
    TH2F* h_mZTT_coll_MM_SRSS1;
    TH2F* h_mZTT_coll_MM_SRSS2;
    TH2F* h_mZTT_coll_MM_SRSS3;
    TH2F* h_mZTT_coll_MM_SRSS4;
    TH2F* h_mZTT_coll_EM_SRSS1;
    TH2F* h_mZTT_coll_EM_SRSS2;
    TH2F* h_mZTT_coll_EE_SROS1;
    TH2F* h_mZTT_coll_MM_SROS1;
    TH2F* h_mZTT_coll_EM_SROS1;
    
    TH2F* h_mZTT_mmc_EE_SRSS1;
    TH2F* h_mZTT_mmc_EE_SRSS2;
    TH2F* h_mZTT_mmc_MM_SRSS1;
    TH2F* h_mZTT_mmc_MM_SRSS2;
    TH2F* h_mZTT_mmc_MM_SRSS3;
    TH2F* h_mZTT_mmc_MM_SRSS4;
    TH2F* h_mZTT_mmc_EM_SRSS1;
    TH2F* h_mZTT_mmc_EM_SRSS2;
    TH2F* h_mZTT_mmc_EE_SROS1;
    TH2F* h_mZTT_mmc_MM_SROS1;
    TH2F* h_mZTT_mmc_EM_SROS1;
    
    TH2F* h_pTl0_EE_SRSS1;
    TH2F* h_pTl0_EE_SRSS2;
    TH2F* h_pTl0_MM_SRSS1;
    TH2F* h_pTl0_MM_SRSS2;
    TH2F* h_pTl0_MM_SRSS3;
    TH2F* h_pTl0_MM_SRSS4;
    TH2F* h_pTl0_EM_SRSS1;
    TH2F* h_pTl0_EM_SRSS2;
    TH2F* h_pTl0_EE_SROS1;
    TH2F* h_pTl0_MM_SROS1;
    TH2F* h_pTl0_EM_SROS1;
    
    TH2F* h_pTl1_EE_SRSS1;
    TH2F* h_pTl1_EE_SRSS2;
    TH2F* h_pTl1_MM_SRSS1;  
    TH2F* h_pTl1_MM_SRSS2;
    TH2F* h_pTl1_MM_SRSS3;
    TH2F* h_pTl1_MM_SRSS4;
    TH2F* h_pTl1_EM_SRSS1;
    TH2F* h_pTl1_EM_SRSS2;
    TH2F* h_pTl1_EE_SROS1;
    TH2F* h_pTl1_MM_SROS1;
    TH2F* h_pTl1_EM_SROS1;
    
    TH2F* h_pTj0_EE_SRSS1;
    TH2F* h_pTj0_EE_SRSS2;
    TH2F* h_pTj0_MM_SRSS1;
    TH2F* h_pTj0_MM_SRSS2;
    TH2F* h_pTj0_MM_SRSS3;
    TH2F* h_pTj0_MM_SRSS4;
    TH2F* h_pTj0_EM_SRSS1;
    TH2F* h_pTj0_EM_SRSS2;
    TH2F* h_pTj0_EE_SROS1;
    TH2F* h_pTj0_MM_SROS1;
    TH2F* h_pTj0_EM_SROS1;
    
    
    TH2F* h_pTj1_EE_SRSS1;
    TH2F* h_pTj1_EE_SRSS2;
    TH2F* h_pTj1_MM_SRSS1;  
    TH2F* h_pTj1_MM_SRSS2;
    TH2F* h_pTj1_MM_SRSS3;
    TH2F* h_pTj1_MM_SRSS4;
    TH2F* h_pTj1_EM_SRSS1;
    TH2F* h_pTj1_EM_SRSS2;
    TH2F* h_pTj1_EE_SROS1;
    TH2F* h_pTj1_MM_SROS1;
    TH2F* h_pTj1_EM_SROS1;
    
    TH2F* h_mll_EE_SRSS1;
    TH2F* h_mll_EE_SRSS2;
    TH2F* h_mll_MM_SRSS1; 
    TH2F* h_mll_MM_SRSS2;
    TH2F* h_mll_MM_SRSS3;
    TH2F* h_mll_MM_SRSS4;
    TH2F* h_mll_EM_SRSS1;
    TH2F* h_mll_EM_SRSS2;
    TH2F* h_mll_EE_SROS1;
    TH2F* h_mll_MM_SROS1;
    TH2F* h_mll_EM_SROS1;
    
    TH2F* h_METrel_EE_SRSS1;
    TH2F* h_METrel_EE_SRSS2;
    TH2F* h_METrel_MM_SRSS1;  
    TH2F* h_METrel_MM_SRSS2;  
    TH2F* h_METrel_MM_SRSS3;
    TH2F* h_METrel_MM_SRSS4;
    TH2F* h_METrel_EM_SRSS1;
    TH2F* h_METrel_EM_SRSS2;
    TH2F* h_METrel_EE_SROS1;
    TH2F* h_METrel_MM_SROS1;
    TH2F* h_METrel_EM_SROS1;
    
    TH2F* h_MET_EE_SRSS1;
    TH2F* h_MET_EE_SRSS2;
    TH2F* h_MET_MM_SRSS1;  
    TH2F* h_MET_MM_SRSS2;  
    TH2F* h_MET_MM_SRSS3;
    TH2F* h_MET_MM_SRSS4;
    TH2F* h_MET_EM_SRSS1;
    TH2F* h_MET_EM_SRSS2;
    TH2F* h_MET_EE_SROS1;
    TH2F* h_MET_MM_SROS1;
    TH2F* h_MET_EM_SROS1;
    
    TH2F* h_HT_EE_SRSS1;
    TH2F* h_HT_EE_SRSS2;
    TH2F* h_HT_MM_SRSS1;  
    TH2F* h_HT_MM_SRSS2;
    TH2F* h_HT_MM_SRSS3;
    TH2F* h_HT_MM_SRSS4;
    TH2F* h_HT_EM_SRSS1;
    TH2F* h_HT_EM_SRSS2;
    TH2F* h_HT_EE_SROS1;
    TH2F* h_HT_MM_SROS1;
    TH2F* h_HT_EM_SROS1;
    
    TH2F* h_mWWt_EE_SRSS1;
    TH2F* h_mWWt_EE_SRSS2;
    TH2F* h_mWWt_MM_SRSS1;  
    TH2F* h_mWWt_MM_SRSS2;
    TH2F* h_mWWt_MM_SRSS3;
    TH2F* h_mWWt_MM_SRSS4;
    TH2F* h_mWWt_EM_SRSS1;
    TH2F* h_mWWt_EM_SRSS2;
    TH2F* h_mWWt_EE_SROS1;
    TH2F* h_mWWt_MM_SROS1;
    TH2F* h_mWWt_EM_SROS1;
    
    TH2F* h_mTlmin_EE_SRSS1;
    TH2F* h_mTlmin_EE_SRSS2;
    TH2F* h_mTlmin_MM_SRSS1;  
    TH2F* h_mTlmin_MM_SRSS2;
    TH2F* h_mTlmin_MM_SRSS3;
    TH2F* h_mTlmin_MM_SRSS4;
    TH2F* h_mTlmin_EM_SRSS1;
    TH2F* h_mTlmin_EM_SRSS2;
    TH2F* h_mTlmin_EE_SROS1;
    TH2F* h_mTlmin_MM_SROS1;
    TH2F* h_mTlmin_EM_SROS1;

    TH2F* h_meff_EE_SRSS1;
    TH2F* h_meff_EE_SRSS2;
    TH2F* h_meff_MM_SRSS1;
    TH2F* h_meff_MM_SRSS2;
    TH2F* h_meff_MM_SRSS3;
    TH2F* h_meff_MM_SRSS4;
    TH2F* h_meff_EM_SRSS1;
    TH2F* h_meff_EM_SRSS2;
    TH2F* h_meff_EE_SROS1;
    TH2F* h_meff_MM_SROS1;
    TH2F* h_meff_EM_SROS1;
    
    
    TH2F* h_mt2_EE_SRSS1;
    TH2F* h_mt2_EE_SRSS2;
    TH2F* h_mt2_MM_SRSS1;
    TH2F* h_mt2_MM_SRSS2;  
    TH2F* h_mt2_MM_SRSS3;
    TH2F* h_mt2_MM_SRSS4;
    TH2F* h_mt2_EM_SRSS1;
    TH2F* h_mt2_EM_SRSS2;
    TH2F* h_mt2_EE_SROS1;
    TH2F* h_mt2_MM_SROS1;
    TH2F* h_mt2_EM_SROS1;

    TH2F* h_mjj_EE_SRSS1;
    TH2F* h_mjj_EE_SRSS2;
    TH2F* h_mjj_MM_SRSS1;  
    TH2F* h_mjj_MM_SRSS2;
    TH2F* h_mjj_MM_SRSS3;
    TH2F* h_mjj_MM_SRSS4;
    TH2F* h_mjj_EM_SRSS1;
    TH2F* h_mjj_EM_SRSS2;
    TH2F* h_mjj_EE_SROS1;
    TH2F* h_mjj_MM_SROS1;
    TH2F* h_mjj_EM_SROS1;
    
    TH2F* h_DeltaPhiMETll_EE_SRSS1;
    TH2F* h_DeltaPhiMETll_EE_SRSS2;
    TH2F* h_DeltaPhiMETll_MM_SRSS1;  
    TH2F* h_DeltaPhiMETll_MM_SRSS2;
    TH2F* h_DeltaPhiMETll_MM_SRSS3;
    TH2F* h_DeltaPhiMETll_MM_SRSS4;
    TH2F* h_DeltaPhiMETll_EM_SRSS1;
    TH2F* h_DeltaPhiMETll_EM_SRSS2;
    TH2F* h_DeltaPhiMETll_EE_SROS1;
    TH2F* h_DeltaPhiMETll_MM_SROS1;
    TH2F* h_DeltaPhiMETll_EM_SROS1;
    
    TH2F* h_DeltaPhill_EE_SRSS1;
    TH2F* h_DeltaPhill_EE_SRSS2;
    TH2F* h_DeltaPhill_MM_SRSS1;  
    TH2F* h_DeltaPhill_MM_SRSS2;
    TH2F* h_DeltaPhill_MM_SRSS3;
    TH2F* h_DeltaPhill_MM_SRSS4;
    TH2F* h_DeltaPhill_EM_SRSS1;
    TH2F* h_DeltaPhill_EM_SRSS2;
    TH2F* h_DeltaPhill_EE_SROS1;
    TH2F* h_DeltaPhill_MM_SROS1;
    TH2F* h_DeltaPhill_EM_SROS1;

    TH2F* h_NBJets_EE_SRSS1;
    TH2F* h_NBJets_EE_SRSS2;
    TH2F* h_NBJets_MM_SRSS1;  
    TH2F* h_NBJets_MM_SRSS2;
    TH2F* h_NBJets_MM_SRSS3;
    TH2F* h_NBJets_MM_SRSS4;
    TH2F* h_NBJets_EM_SRSS1;
    TH2F* h_NBJets_EM_SRSS2;
    TH2F* h_NBJets_EE_SROS1;
    TH2F* h_NBJets_MM_SROS1;
    TH2F* h_NBJets_EM_SROS1;

    TH2F* h_NCJets_EE_SRSS1;
    TH2F* h_NCJets_EE_SRSS2;
    TH2F* h_NCJets_MM_SRSS1;  
    TH2F* h_NCJets_MM_SRSS2;
    TH2F* h_NCJets_MM_SRSS3;
    TH2F* h_NCJets_MM_SRSS4;
    TH2F* h_NCJets_EM_SRSS1;
    TH2F* h_NCJets_EM_SRSS2;
    TH2F* h_NCJets_EE_SROS1;
    TH2F* h_NCJets_MM_SROS1;
    TH2F* h_NCJets_EM_SROS1;

    TH2F* h_NFJets_EE_SRSS1;
    TH2F* h_NFJets_EE_SRSS2;
    TH2F* h_NFJets_MM_SRSS1;  
    TH2F* h_NFJets_MM_SRSS2;
    TH2F* h_NFJets_MM_SRSS3;
    TH2F* h_NFJets_MM_SRSS4;
    TH2F* h_NFJets_EM_SRSS1;
    TH2F* h_NFJets_EM_SRSS2;
    TH2F* h_NFJets_EE_SROS1;
    TH2F* h_NFJets_MM_SROS1;
    TH2F* h_NFJets_EM_SROS1;
    
      /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhijj_EE_SRSS1; 
  TH2F* h_DeltaPhijj_EE_SRSS2; 
  TH2F* h_DeltaPhijj_MM_SRSS1;   
  TH2F* h_DeltaPhijj_MM_SRSS2; 
  TH2F* h_DeltaPhijj_MM_SRSS3; 
  TH2F* h_DeltaPhijj_MM_SRSS4; 
  TH2F* h_DeltaPhijj_EM_SRSS1; 
  TH2F* h_DeltaPhijj_EM_SRSS2; 
  TH2F* h_DeltaPhijj_EE_SROS1; 
  TH2F* h_DeltaPhijj_MM_SROS1; 
  TH2F* h_DeltaPhijj_EM_SROS1; 
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_pTjj_EE_SRSS1; 
  TH2F* h_pTjj_EE_SRSS2; 
  TH2F* h_pTjj_MM_SRSS1; 
  TH2F* h_pTjj_MM_SRSS2; 
  TH2F* h_pTjj_MM_SRSS3; 
  TH2F* h_pTjj_MM_SRSS4; 
  TH2F* h_pTjj_EM_SRSS1; 
  TH2F* h_pTjj_EM_SRSS2; 
  TH2F* h_pTjj_EE_SROS1; 
  TH2F* h_pTjj_MM_SROS1; 
  TH2F* h_pTjj_EM_SROS1; 

  /*----------------------------------------------------------------------------*/ 
  TH2F* h_ptll_EE_SRSS1; 
  TH2F* h_ptll_EE_SRSS2; 
  TH2F* h_ptll_MM_SRSS1;   
  TH2F* h_ptll_MM_SRSS2; 
  TH2F* h_ptll_MM_SRSS3; 
  TH2F* h_ptll_MM_SRSS4; 
  TH2F* h_ptll_EM_SRSS1; 
  TH2F* h_ptll_EM_SRSS2; 
  TH2F* h_ptll_EE_SROS1; 
  TH2F* h_ptll_MM_SROS1; 
  TH2F* h_ptll_EM_SROS1; 
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhiMETl0_EE_SRSS1; 
  TH2F* h_DeltaPhiMETl0_EE_SRSS2; 
  TH2F* h_DeltaPhiMETl0_MM_SRSS1;   
  TH2F* h_DeltaPhiMETl0_MM_SRSS2; 
  TH2F* h_DeltaPhiMETl0_MM_SRSS3; 
  TH2F* h_DeltaPhiMETl0_MM_SRSS4; 
  TH2F* h_DeltaPhiMETl0_EM_SRSS1; 
  TH2F* h_DeltaPhiMETl0_EM_SRSS2; 
  TH2F* h_DeltaPhiMETl0_EE_SROS1; 
  TH2F* h_DeltaPhiMETl0_MM_SROS1; 
  TH2F* h_DeltaPhiMETl0_EM_SROS1; 

  /*-------------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhiMETl1_EE_SRSS1; 
  TH2F* h_DeltaPhiMETl1_EE_SRSS2; 
  TH2F* h_DeltaPhiMETl1_MM_SRSS1;   
  TH2F* h_DeltaPhiMETl1_MM_SRSS2; 
  TH2F* h_DeltaPhiMETl1_MM_SRSS3; 
  TH2F* h_DeltaPhiMETl1_MM_SRSS4; 
  TH2F* h_DeltaPhiMETl1_EM_SRSS1; 
  TH2F* h_DeltaPhiMETl1_EM_SRSS2; 
  TH2F* h_DeltaPhiMETl1_EE_SROS1; 
  TH2F* h_DeltaPhiMETl1_MM_SROS1; 
  TH2F* h_DeltaPhiMETl1_EM_SROS1; 
  
    /*-----------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhiMETj0_EE_SRSS1; 
  TH2F* h_DeltaPhiMETj0_EE_SRSS2; 
  TH2F* h_DeltaPhiMETj0_MM_SRSS1;   
  TH2F* h_DeltaPhiMETj0_MM_SRSS2; 
  TH2F* h_DeltaPhiMETj0_MM_SRSS3; 
  TH2F* h_DeltaPhiMETj0_MM_SRSS4; 
  TH2F* h_DeltaPhiMETj0_EM_SRSS1; 
  TH2F* h_DeltaPhiMETj0_EM_SRSS2; 
  TH2F* h_DeltaPhiMETj0_EE_SROS1; 
  TH2F* h_DeltaPhiMETj0_MM_SROS1; 
  TH2F* h_DeltaPhiMETj0_EM_SROS1; 
  /*-------------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhiMETj1_EE_SRSS1; 
  TH2F* h_DeltaPhiMETj1_EE_SRSS2; 
  TH2F* h_DeltaPhiMETj1_MM_SRSS1;   
  TH2F* h_DeltaPhiMETj1_MM_SRSS2; 
  TH2F* h_DeltaPhiMETj1_MM_SRSS3; 
  TH2F* h_DeltaPhiMETj1_MM_SRSS4; 
  TH2F* h_DeltaPhiMETj1_EM_SRSS1; 
  TH2F* h_DeltaPhiMETj1_EM_SRSS2; 
  TH2F* h_DeltaPhiMETj1_EE_SROS1; 
  TH2F* h_DeltaPhiMETj1_MM_SROS1; 
  TH2F* h_DeltaPhiMETj1_EM_SROS1; 

  /*-------------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhiMETjj_EE_SRSS1; 
  TH2F* h_DeltaPhiMETjj_EE_SRSS2; 
  TH2F* h_DeltaPhiMETjj_MM_SRSS1;   
  TH2F* h_DeltaPhiMETjj_MM_SRSS2; 
  TH2F* h_DeltaPhiMETjj_MM_SRSS3; 
  TH2F* h_DeltaPhiMETjj_MM_SRSS4; 
  TH2F* h_DeltaPhiMETjj_EM_SRSS1; 
  TH2F* h_DeltaPhiMETjj_EM_SRSS2; 
  TH2F* h_DeltaPhiMETjj_EE_SROS1; 
  TH2F* h_DeltaPhiMETjj_MM_SROS1; 
  TH2F* h_DeltaPhiMETjj_EM_SROS1; 

    /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaRjj_EE_SRSS1; 
  TH2F* h_DeltaRjj_EE_SRSS2; 
  TH2F* h_DeltaRjj_MM_SRSS1;   
  TH2F* h_DeltaRjj_MM_SRSS2; 
  TH2F* h_DeltaRjj_MM_SRSS3; 
  TH2F* h_DeltaRjj_MM_SRSS4; 
  TH2F* h_DeltaRjj_EM_SRSS1; 
  TH2F* h_DeltaRjj_EM_SRSS2; 
  TH2F* h_DeltaRjj_EE_SROS1; 
  TH2F* h_DeltaRjj_MM_SROS1; 
  TH2F* h_DeltaRjj_EM_SROS1; 

  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_etal0_EE_SRSS1; 
  TH2F* h_etal0_EE_SRSS2; 
  TH2F* h_etal0_MM_SRSS1;   
  TH2F* h_etal0_MM_SRSS2; 
  TH2F* h_etal0_MM_SRSS3; 
  TH2F* h_etal0_MM_SRSS4; 
  TH2F* h_etal0_EM_SRSS1; 
  TH2F* h_etal0_EM_SRSS2; 
  TH2F* h_etal0_EE_SROS1; 
  TH2F* h_etal0_MM_SROS1; 
  TH2F* h_etal0_EM_SROS1; 
    /*---------------------------------------------------------------------------*/ 
  TH2F* h_etal1_EE_SRSS1; 
  TH2F* h_etal1_EE_SRSS2; 
  TH2F* h_etal1_MM_SRSS1;   
  TH2F* h_etal1_MM_SRSS2; 
  TH2F* h_etal1_MM_SRSS3; 
  TH2F* h_etal1_MM_SRSS4; 
  TH2F* h_etal1_EM_SRSS1; 
  TH2F* h_etal1_EM_SRSS2; 
  TH2F* h_etal1_EE_SROS1; 
  TH2F* h_etal1_MM_SROS1; 
  TH2F* h_etal1_EM_SROS1; 
    /*---------------------------------------------------------------------------*/ 
  TH2F* h_etaj0_EE_SRSS1; 
  TH2F* h_etaj0_EE_SRSS2; 
  TH2F* h_etaj0_MM_SRSS1;   
  TH2F* h_etaj0_MM_SRSS2; 
  TH2F* h_etaj0_MM_SRSS3; 
  TH2F* h_etaj0_MM_SRSS4; 
  TH2F* h_etaj0_EM_SRSS1; 
  TH2F* h_etaj0_EM_SRSS2; 
  TH2F* h_etaj0_EE_SROS1; 
  TH2F* h_etaj0_MM_SROS1; 
  TH2F* h_etaj0_EM_SROS1; 
    /*---------------------------------------------------------------------------*/ 
  TH2F* h_etaj1_EE_SRSS1; 
  TH2F* h_etaj1_EE_SRSS2; 
  TH2F* h_etaj1_MM_SRSS1;   
  TH2F* h_etaj1_MM_SRSS2; 
  TH2F* h_etaj1_MM_SRSS3; 
  TH2F* h_etaj1_MM_SRSS4; 
  TH2F* h_etaj1_EM_SRSS1; 
  TH2F* h_etaj1_EM_SRSS2; 
  TH2F* h_etaj1_EE_SROS1; 
  TH2F* h_etaj1_MM_SROS1; 
  TH2F* h_etaj1_EM_SROS1; 

  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_mTl0MET_EE_SRSS1; 
  TH2F* h_mTl0MET_EE_SRSS2; 
  TH2F* h_mTl0MET_MM_SRSS1;   
  TH2F* h_mTl0MET_MM_SRSS2; 
  TH2F* h_mTl0MET_MM_SRSS3; 
  TH2F* h_mTl0MET_MM_SRSS4; 
  TH2F* h_mTl0MET_EM_SRSS1; 
  TH2F* h_mTl0MET_EM_SRSS2; 
  TH2F* h_mTl0MET_EE_SROS1; 
  TH2F* h_mTl0MET_MM_SROS1; 
  TH2F* h_mTl0MET_EM_SROS1; 
  /*-------------------------------------------------------------------------------*/ 
  TH2F* h_mTl1MET_EE_SRSS1; 
  TH2F* h_mTl1MET_EE_SRSS2; 
  TH2F* h_mTl1MET_MM_SRSS1;   
  TH2F* h_mTl1MET_MM_SRSS2; 
  TH2F* h_mTl1MET_MM_SRSS3; 
  TH2F* h_mTl1MET_MM_SRSS4; 
  TH2F* h_mTl1MET_EM_SRSS1; 
  TH2F* h_mTl1MET_EM_SRSS2; 
  TH2F* h_mTl1MET_EE_SROS1; 
  TH2F* h_mTl1MET_MM_SROS1; 
  TH2F* h_mTl1MET_EM_SROS1; 

      /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhilljj_EE_SRSS1; 
  TH2F* h_DeltaPhilljj_EE_SRSS2; 
  TH2F* h_DeltaPhilljj_MM_SRSS1;   
  TH2F* h_DeltaPhilljj_MM_SRSS2; 
  TH2F* h_DeltaPhilljj_MM_SRSS3; 
  TH2F* h_DeltaPhilljj_MM_SRSS4; 
  TH2F* h_DeltaPhilljj_EM_SRSS1; 
  TH2F* h_DeltaPhilljj_EM_SRSS2; 
  TH2F* h_DeltaPhilljj_EE_SROS1; 
  TH2F* h_DeltaPhilljj_MM_SROS1; 
  TH2F* h_DeltaPhilljj_EM_SROS1; 
  /*------------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhil0jj_EE_SRSS1; 
  TH2F* h_DeltaPhil0jj_EE_SRSS2; 
  TH2F* h_DeltaPhil0jj_MM_SRSS1;   
  TH2F* h_DeltaPhil0jj_MM_SRSS2; 
  TH2F* h_DeltaPhil0jj_MM_SRSS3; 
  TH2F* h_DeltaPhil0jj_MM_SRSS4; 
  TH2F* h_DeltaPhil0jj_EM_SRSS1; 
  TH2F* h_DeltaPhil0jj_EM_SRSS2; 
  TH2F* h_DeltaPhil0jj_EE_SROS1; 
  TH2F* h_DeltaPhil0jj_MM_SROS1; 
  TH2F* h_DeltaPhil0jj_EM_SROS1; 
  /*------------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaPhil1jj_EE_SRSS1; 
  TH2F* h_DeltaPhil1jj_EE_SRSS2; 
  TH2F* h_DeltaPhil1jj_MM_SRSS1;   
  TH2F* h_DeltaPhil1jj_MM_SRSS2; 
  TH2F* h_DeltaPhil1jj_MM_SRSS3; 
  TH2F* h_DeltaPhil1jj_MM_SRSS4; 
  TH2F* h_DeltaPhil1jj_EM_SRSS1; 
  TH2F* h_DeltaPhil1jj_EM_SRSS2; 
  TH2F* h_DeltaPhil1jj_EE_SROS1; 
  TH2F* h_DeltaPhil1jj_MM_SROS1; 
  TH2F* h_DeltaPhil1jj_EM_SROS1; 

  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaRlljj_EE_SRSS1; 
  TH2F* h_DeltaRlljj_EE_SRSS2; 
  TH2F* h_DeltaRlljj_MM_SRSS1;   
  TH2F* h_DeltaRlljj_MM_SRSS2; 
  TH2F* h_DeltaRlljj_MM_SRSS3; 
  TH2F* h_DeltaRlljj_MM_SRSS4; 
  TH2F* h_DeltaRlljj_EM_SRSS1; 
  TH2F* h_DeltaRlljj_EM_SRSS2; 
  TH2F* h_DeltaRlljj_EE_SROS1; 
  TH2F* h_DeltaRlljj_MM_SROS1; 
  TH2F* h_DeltaRlljj_EM_SROS1; 

    /*--------------------------------------------------------------------------------*/   
  TH2F* h_DeltaEtajj_EE_SRSS1; 
  TH2F* h_DeltaEtajj_EE_SRSS2; 
  TH2F* h_DeltaEtajj_MM_SRSS1;   
  TH2F* h_DeltaEtajj_MM_SRSS2; 
  TH2F* h_DeltaEtajj_MM_SRSS3; 
  TH2F* h_DeltaEtajj_MM_SRSS4; 
  TH2F* h_DeltaEtajj_EM_SRSS1; 
  TH2F* h_DeltaEtajj_EM_SRSS2; 
  TH2F* h_DeltaEtajj_EE_SROS1; 
  TH2F* h_DeltaEtajj_MM_SROS1; 
  TH2F* h_DeltaEtajj_EM_SROS1;   
  
      /*--------------------------------------------------------------------------------*/   
  TH2F* h_DeltaEtall_EE_SRSS1; 
  TH2F* h_DeltaEtall_EE_SRSS2; 
  TH2F* h_DeltaEtall_MM_SRSS1;   
  TH2F* h_DeltaEtall_MM_SRSS2; 
  TH2F* h_DeltaEtall_MM_SRSS3; 
  TH2F* h_DeltaEtall_MM_SRSS4; 
  TH2F* h_DeltaEtall_EM_SRSS1; 
  TH2F* h_DeltaEtall_EM_SRSS2; 
  TH2F* h_DeltaEtall_EE_SROS1; 
  TH2F* h_DeltaEtall_MM_SROS1; 
  TH2F* h_DeltaEtall_EM_SROS1;   


  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_mTll_EE_SRSS1; 
  TH2F* h_mTll_EE_SRSS2; 
  TH2F* h_mTll_MM_SRSS1;   
  TH2F* h_mTll_MM_SRSS2; 
  TH2F* h_mTll_MM_SRSS3; 
  TH2F* h_mTll_MM_SRSS4; 
  TH2F* h_mTll_EM_SRSS1; 
  TH2F* h_mTll_EM_SRSS2; 
  TH2F* h_mTll_EE_SROS1; 
  TH2F* h_mTll_MM_SROS1; 
  TH2F* h_mTll_EM_SROS1; 


  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_mMETll_EE_SRSS1; 
  TH2F* h_mMETll_EE_SRSS2; 
  TH2F* h_mMETll_MM_SRSS1;   
  TH2F* h_mMETll_MM_SRSS2; 
  TH2F* h_mMETll_MM_SRSS3; 
  TH2F* h_mMETll_MM_SRSS4; 
  TH2F* h_mMETll_EM_SRSS1; 
  TH2F* h_mMETll_EM_SRSS2; 
  TH2F* h_mMETll_EE_SROS1; 
  TH2F* h_mMETll_MM_SROS1; 
  TH2F* h_mMETll_EM_SROS1; 

  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_DeltaYjj_EE_SRSS1; 
  TH2F* h_DeltaYjj_EE_SRSS2; 
  TH2F* h_DeltaYjj_MM_SRSS1;  
  TH2F* h_DeltaYjj_MM_SRSS2; 
  TH2F* h_DeltaYjj_MM_SRSS3; 
  TH2F* h_DeltaYjj_MM_SRSS4; 
  TH2F* h_DeltaYjj_EM_SRSS1; 
  TH2F* h_DeltaYjj_EM_SRSS2; 
  TH2F* h_DeltaYjj_EE_SROS1; 
  TH2F* h_DeltaYjj_MM_SROS1; 
  TH2F* h_DeltaYjj_EM_SROS1; 
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0_branch_l0_EE_SRSS1;
  TH2F* h_D0_branch_l0_EE_SRSS2;
  TH2F* h_D0_branch_l0_MM_SRSS1;  
  TH2F* h_D0_branch_l0_MM_SRSS2;
  TH2F* h_D0_branch_l0_MM_SRSS3;
  TH2F* h_D0_branch_l0_MM_SRSS4;
  TH2F* h_D0_branch_l0_EM_SRSS1;
  TH2F* h_D0_branch_l0_EM_SRSS2;
  TH2F* h_D0_branch_l0_EE_SROS1;
  TH2F* h_D0_branch_l0_MM_SROS1;
  TH2F* h_D0_branch_l0_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0_branch_l1_EE_SRSS1;
  TH2F* h_D0_branch_l1_EE_SRSS2;
  TH2F* h_D0_branch_l1_MM_SRSS1;  
  TH2F* h_D0_branch_l1_MM_SRSS2;
  TH2F* h_D0_branch_l1_MM_SRSS3;
  TH2F* h_D0_branch_l1_MM_SRSS4;
  TH2F* h_D0_branch_l1_EM_SRSS1;
  TH2F* h_D0_branch_l1_EM_SRSS2;
  TH2F* h_D0_branch_l1_EE_SROS1;
  TH2F* h_D0_branch_l1_MM_SROS1;
  TH2F* h_D0_branch_l1_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0_recalc_l0_EE_SRSS1;
  TH2F* h_D0_recalc_l0_EE_SRSS2;
  TH2F* h_D0_recalc_l0_MM_SRSS1;  
  TH2F* h_D0_recalc_l0_MM_SRSS2;
  TH2F* h_D0_recalc_l0_MM_SRSS3;
  TH2F* h_D0_recalc_l0_MM_SRSS4;
  TH2F* h_D0_recalc_l0_EM_SRSS1;
  TH2F* h_D0_recalc_l0_EM_SRSS2;
  TH2F* h_D0_recalc_l0_EE_SROS1;
  TH2F* h_D0_recalc_l0_MM_SROS1;
  TH2F* h_D0_recalc_l0_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0_recalc_l1_EE_SRSS1;
  TH2F* h_D0_recalc_l1_EE_SRSS2;
  TH2F* h_D0_recalc_l1_MM_SRSS1;  
  TH2F* h_D0_recalc_l1_MM_SRSS2;
  TH2F* h_D0_recalc_l1_MM_SRSS3;
  TH2F* h_D0_recalc_l1_MM_SRSS4;
  TH2F* h_D0_recalc_l1_EM_SRSS1;
  TH2F* h_D0_recalc_l1_EM_SRSS2;
  TH2F* h_D0_recalc_l1_EE_SROS1;
  TH2F* h_D0_recalc_l1_MM_SROS1;
  TH2F* h_D0_recalc_l1_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0Signif_branch_l0_EE_SRSS1;
  TH2F* h_D0Signif_branch_l0_EE_SRSS2;
  TH2F* h_D0Signif_branch_l0_MM_SRSS1;  
  TH2F* h_D0Signif_branch_l0_MM_SRSS2;
  TH2F* h_D0Signif_branch_l0_MM_SRSS3;
  TH2F* h_D0Signif_branch_l0_MM_SRSS4;
  TH2F* h_D0Signif_branch_l0_EM_SRSS1;
  TH2F* h_D0Signif_branch_l0_EM_SRSS2;
  TH2F* h_D0Signif_branch_l0_EE_SROS1;
  TH2F* h_D0Signif_branch_l0_MM_SROS1;
  TH2F* h_D0Signif_branch_l0_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0Signif_branch_l1_EE_SRSS1;
  TH2F* h_D0Signif_branch_l1_EE_SRSS2;
  TH2F* h_D0Signif_branch_l1_MM_SRSS1;  
  TH2F* h_D0Signif_branch_l1_MM_SRSS2;
  TH2F* h_D0Signif_branch_l1_MM_SRSS3;
  TH2F* h_D0Signif_branch_l1_MM_SRSS4;
  TH2F* h_D0Signif_branch_l1_EM_SRSS1;
  TH2F* h_D0Signif_branch_l1_EM_SRSS2;
  TH2F* h_D0Signif_branch_l1_EE_SROS1;
  TH2F* h_D0Signif_branch_l1_MM_SROS1;
  TH2F* h_D0Signif_branch_l1_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0Signif_recalc_l0_EE_SRSS1;
  TH2F* h_D0Signif_recalc_l0_EE_SRSS2;
  TH2F* h_D0Signif_recalc_l0_MM_SRSS1;  
  TH2F* h_D0Signif_recalc_l0_MM_SRSS2;
  TH2F* h_D0Signif_recalc_l0_MM_SRSS3;
  TH2F* h_D0Signif_recalc_l0_MM_SRSS4;
  TH2F* h_D0Signif_recalc_l0_EM_SRSS1;
  TH2F* h_D0Signif_recalc_l0_EM_SRSS2;
  TH2F* h_D0Signif_recalc_l0_EE_SROS1;
  TH2F* h_D0Signif_recalc_l0_MM_SROS1;
  TH2F* h_D0Signif_recalc_l0_EM_SROS1;
  
  /*--------------------------------------------------------------------------------*/ 
  TH2F* h_D0Signif_recalc_l1_EE_SRSS1;
  TH2F* h_D0Signif_recalc_l1_EE_SRSS2;
  TH2F* h_D0Signif_recalc_l1_MM_SRSS1;  
  TH2F* h_D0Signif_recalc_l1_MM_SRSS2;
  TH2F* h_D0Signif_recalc_l1_MM_SRSS3;
  TH2F* h_D0Signif_recalc_l1_MM_SRSS4;
  TH2F* h_D0Signif_recalc_l1_EM_SRSS1;
  TH2F* h_D0Signif_recalc_l1_EM_SRSS2;
  TH2F* h_D0Signif_recalc_l1_EE_SROS1;
  TH2F* h_D0Signif_recalc_l1_MM_SROS1;
  TH2F* h_D0Signif_recalc_l1_EM_SROS1;
  

    
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
    void calc_EE_variables(LeptonVector &leptons, Electron* el0, Electron* el1, TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets );
    void calc_MM_variables(LeptonVector &leptons, Muon* mu0, Muon* mu1, TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets);
    void calc_EM_variables(LeptonVector &leptons, Electron* el, Muon* mu, TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets);
    
    void fillHistos_EE_SRSS1(float cut_EE, int mcid, float weight_ALL_EE);
    void fillHistos_EE_SRSS2(float cut_EE, int mcid, float weight_ALL_EE);
    void fillHistos_EE_SROS1(float cut_EE, int mcid, float weight_ALL_EE);
    
    void fillHistos_MM_SRSS1(float cut_MM, int mcid, float weight_ALL_MM);
    void fillHistos_MM_SRSS2(float cut_MM, int mcid, float weight_ALL_MM);
    void fillHistos_MM_SRSS3(float cut_MM, int mcid, float weight_ALL_MM);
    void fillHistos_MM_SRSS4(float cut_MM, int mcid, float weight_ALL_MM);
    void fillHistos_MM_SROS1(float cut_MM, int mcid, float weight_ALL_MM);
    
    void fillHistos_EM_SRSS1(float cut_EM, int mcid, float weight_ALL_EM);
    void fillHistos_EM_SRSS2(float cut_EM, int mcid, float weight_ALL_EM);
    void fillHistos_EM_SROS1(float cut_EM, int mcid, float weight_ALL_EM);
    
    float getFakeWeight(const LeptonVector &baseLeps, SusyMatrixMethod::FAKE_REGION region, float metRel, SusyMatrixMethod::SYSTEMATIC sys);
    
    const Jet* getClosestJet(const Lepton* lep, const JetVector &jets);
    float recalc_D0(bool unbiased, const Lepton* lep, const Jet* closestJet_lep);
    float calc_D0(bool unbiased, const Lepton* lep);
    
    ElectronVector getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys);
    MuonVector getSoftMuons(SusyNtObject* susyNt, SusyNtSys sys);

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
    float mTel0MET;
    float mTel1MET;
    float mMETee;
    float DeltaPhiEE;
    float DeltaPhiMETel0;
    float DeltaPhiMETel1;
    float DeltaPhiMETee;
    float mt2_ee;  
    float DeltaPhieejj;
    float DeltaPhiel0jj;
    float DeltaPhiel1jj;
    float DeltaReejj;
    float DeltaEtaee;
    
    float D0_branch_el0;
    float D0_branch_el1;
    float D0err_branch_el0;
    float D0err_branch_el1;
    
    float D0_recalc_el0;
    float D0_recalc_el1;
    
    float sD0Signif_branch_el0;
    float sD0Signif_branch_el1;
    float sD0Signif_recalc_el0;
    float sD0Signif_recalc_el1;
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
    float mTmu0MET;
    float mTmu1MET;
    float mMETmm;
    float DeltaPhiMM;
    float DeltaPhiMETmu0;
    float DeltaPhiMETmu1;
    float DeltaPhiMETmm;
    float mt2_mm;
    
    float DeltaPhimmjj;
    float DeltaPhimu0jj;
    float DeltaPhimu1jj;
    float DeltaRmmjj;
    float DeltaEtamm;

    float D0_branch_mu0;
    float D0_branch_mu1;
    float D0err_branch_mu0;
    float D0err_branch_mu1;
    
    float D0_recalc_mu0;
    float D0_recalc_mu1;
    
    float sD0Signif_branch_mu0;
    float sD0Signif_branch_mu1;
    float sD0Signif_recalc_mu0;
    float sD0Signif_recalc_mu1;
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
    float mTl0MET;
    float mTl1MET;
    float mMETem;
    float DeltaPhiem;
    float DeltaPhiMETl0;
    float DeltaPhiMETl1;
    float DeltaPhiMETem;
    float mt2_em;
    
    float DeltaPhiemjj;
    float DeltaPhil0jj;
    float DeltaPhil1jj;
    float DeltaRemjj;
    float DeltaEtaem;

    float D0_branch_l0;
    float D0_branch_l1;
    float D0err_branch_l0;
    float D0err_branch_l1;
    
    float D0_recalc_l0;
    float D0_recalc_l1;
    
    float sD0Signif_branch_l0;
    float sD0Signif_branch_l1;
    float sD0Signif_recalc_l0;
    float sD0Signif_recalc_l1;
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
