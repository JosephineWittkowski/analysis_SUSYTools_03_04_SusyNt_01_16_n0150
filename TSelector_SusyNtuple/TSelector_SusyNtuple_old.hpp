#ifndef SusyAna_TSelector_SusyNtuple_h
#define SusyAna_TSelector_SusyNtuple_h

//////////////////////////////////////////////////////////
// General script to implement basic selection with all //
// signal region cut methods.                           //
//////////////////////////////////////////////////////////

#define  runWithRoot
// #define runWithProof

#include "TTree.h"
#include <fstream>
#include "TH1.h"



#ifdef runWithRoot
#include "SusyNtuple/SusyNtuple/SusyNtAna.h"
#include "SusyNtuple/SusyNtuple/SusyNtTools.h"
#include "SusyNtuple/SusyNtuple/DilTrigLogic.h"
#include "SUSYTools/SUSYTools/SUSYObjDef.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"
#include "SusyNtuple/SusyNtuple/SusyDefs.h"
#include "SusyNtuple/WhTruthExtractor.h"
#include "ChargeFlip/ChargeFlip/chargeFlip.h"
#include "Mt2/Mt2/mt2_bisect.h" 
// #include "SusyMatrixMethod/DiLeptonMatrixMethod.h"
#include "mmc/mmc.cpp"
// #include "MissingMassCalculator/MissingMassCalculator/MissingMassCalculator.h"
#endif

#ifdef runWithProof
#include "SusyNtuple/SusyNtAna.h"
#include "SusyNtuple/SusyNtTools.h"
#include "SusyNtuple/DilTrigLogic.h"
#include "SUSYTools/SUSYObjDef.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"
#include "SusyNtuple/SusyDefs.h"
#include "SusyNtuple/WhTruthExtractor.h"
#include "Mt2/mt2_bisect.h" 
#include "mmc/mmc.hpp"
// #include "MissingMassCalculator/MissingMassCalculator.h"
#ifndef __CINT__
#include "ChargeFlip/chargeFlip.h"
#else
class chargeFlip ;
#endif
// #include "SusyMatrixMethod/DiLeptonMatrixMethod.h"

#endif

// #define hIsData
class TSelector_SusyNtuple : public SusyNtAna
{

  public:
    TH1F* h_storeSumwMcid;
    
    TH1F* h_N_events_EE;
    TH1F* h_N_events_MM;
    TH1F* h_N_events_EM;
    //---------------------------    
//     TH2F* h_N_events_SR6_EE;
//     TH2F* h_N_events_SR6_MM;
//     TH2F* h_N_events_SR7_EM;
//     TH2F* h_N_events_SR8_EE;
//     TH2F* h_N_events_SR8_MM;    
//     TH2F* h_N_events_SR9_EM; 
    //---------------------------    
    TH2F* h_METrel_SR6_EE;
    TH2F* h_METrel_SR6_MM;
    TH2F* h_METrel_SR7_EM;
    TH2F* h_METrel_SR8_EE;
    TH2F* h_METrel_SR8_MM;
    TH2F* h_METrel_SR9_EM;
    //---------------------------    
    TH2F* h_DeltaRLeptons_SR6_EE;
    TH2F* h_DeltaRLeptons_SR6_MM;
    TH2F* h_DeltaRLeptons_SR7_EM;
    TH2F* h_DeltaRLeptons_SR8_EE;
    TH2F* h_DeltaRLeptons_SR8_MM;
    TH2F* h_DeltaRLeptons_SR9_EM;
    //---------------------------    
    TH2F* h_mt2_SR6_EE;
    TH2F* h_mt2_SR6_MM;
    TH2F* h_mt2_SR7_EM;
    TH2F* h_mt2_SR8_EE;
    TH2F* h_mt2_SR8_MM;
    TH2F* h_mt2_SR9_EM;
    //---------------------------    
    TH2F* h_ptll_SR6_EE;
    TH2F* h_ptll_SR6_MM;
    TH2F* h_ptll_SR7_EM;
    TH2F* h_ptll_SR8_EE;
    TH2F* h_ptll_SR8_MM;   
    TH2F* h_ptll_SR9_EM;
    //---------------------------    
    TH2F* h_Mll_SR6_EE;
    TH2F* h_Mll_SR6_MM;
    TH2F* h_Mll_SR7_EM;
    TH2F* h_Mll_SR8_EE;
    TH2F* h_Mll_SR8_MM;
    TH2F* h_Mll_SR9_EM;
    //---------------------------    
    TH2F* h_mZTT_coll_SR6_EE;
    TH2F* h_mZTT_coll_SR6_MM;
    TH2F* h_mZTT_coll_SR7_EM;    
    TH2F* h_mZTT_coll_SR8_EE;
    TH2F* h_mZTT_coll_SR8_MM;
    TH2F* h_mZTT_coll_SR9_EM;
    //---------------------------    
    TH2F* h_mZTT_mmc_SR6_EE;
    TH2F* h_mZTT_mmc_SR6_MM;
    TH2F* h_mZTT_mmc_SR7_EM;    
    TH2F* h_mZTT_mmc_SR8_EE;
    TH2F* h_mZTT_mmc_SR8_MM;
    TH2F* h_mZTT_mmc_SR9_EM;
    //--------------------------- 
//     TH2F* h_mZTT_missMassCalc_SR6_EE;
//     TH2F* h_mZTT_missMassCalc_SR6_MM; 
//     TH2F* h_mZTT_missMassCalc_SR7_EM;
//     TH2F* h_mZTT_missMassCalc_SR8_EE;
//     TH2F* h_mZTT_missMassCalc_SR8_MM;
//     TH2F* h_mZTT_missMassCalc_SR9_EM;
    //---------------------------    
    TH2F* h_mTll_SR6_EE;
    TH2F* h_mTll_SR6_MM;
    TH2F* h_mTll_SR7_EM;
    TH2F* h_mTll_SR8_EE;
    TH2F* h_mTll_SR8_MM;
    TH2F* h_mTll_SR9_EM;
    //---------------------------    
    TH2F* h_mTlmin_SR6_EE;
    TH2F* h_mTlmin_SR6_MM;
    TH2F* h_mTlmin_SR7_EM;
    TH2F* h_mTlmin_SR8_EE;
    TH2F* h_mTlmin_SR8_MM;
    TH2F* h_mTlmin_SR9_EM;
    
    //--------------------------- 
    TH2F* h_mJJ_SR6_EE;
    TH2F* h_mJJ_SR6_MM;
    TH2F* h_mJJ_SR7_EM;
    TH2F* h_mJJ_SR8_EE;
    TH2F* h_mJJ_SR8_MM;
    TH2F* h_mJJ_SR9_EM;
    //--------------
    TH2F* h_mMETLL_SR6_EE; 
    TH2F* h_mMETLL_SR6_MM; 
    TH2F* h_mMETLL_SR7_EM; 
    TH2F* h_mMETLL_SR8_EE; 
    TH2F* h_mMETLL_SR8_MM; 
    TH2F* h_mMETLL_SR9_EM; 

    //---------------
    TH2F* h_mCT_SR6_EE;
    TH2F* h_mCT_SR6_MM;
    TH2F* h_mCT_SR7_EM;
    TH2F* h_mCT_SR8_EE;
    TH2F* h_mCT_SR8_MM;
    TH2F* h_mCT_SR9_EM;
    
    //---------------
    TH2F* h_pTj1_SR6_EE;
    TH2F* h_pTj1_SR6_MM;
    TH2F* h_pTj1_SR7_EM;
    TH2F* h_pTj1_SR8_EE;
    TH2F* h_pTj1_SR8_MM;
    TH2F* h_pTj1_SR9_EM;
    
    //-----------
    TH2F* h_pTj2_SR6_EE;
    TH2F* h_pTj2_SR6_MM;
    TH2F* h_pTj2_SR7_EM;
    TH2F* h_pTj2_SR8_EE;
    TH2F* h_pTj2_SR8_MM;
    TH2F* h_pTj2_SR9_EM;
    
    //-----------
    TH2F* h_pTl1_SR6_EE;
    TH2F* h_pTl1_SR6_MM;
    TH2F* h_pTl1_SR7_EM;
    TH2F* h_pTl1_SR8_EE;
    TH2F* h_pTl1_SR8_MM;
    TH2F* h_pTl1_SR9_EM;
    
    //-----------
    TH2F* h_pTl2_SR6_EE;
    TH2F* h_pTl2_SR6_MM;
    TH2F* h_pTl2_SR7_EM;
    TH2F* h_pTl2_SR8_EE;
    TH2F* h_pTl2_SR8_MM;
    TH2F* h_pTl2_SR9_EM;
    
    //--------------------------- 
    TH2F* h_DeltaPhiLL_SR6_EE;
    TH2F* h_DeltaPhiLL_SR6_MM;
    TH2F* h_DeltaPhiLL_SR7_EM;
    TH2F* h_DeltaPhiLL_SR8_EE;
    TH2F* h_DeltaPhiLL_SR8_MM;
    TH2F* h_DeltaPhiLL_SR9_EM;
    
    //-----------------
    TH2F* h_DeltaPhiJJ_SR6_EE;
    TH2F* h_DeltaPhiJJ_SR6_MM;
    TH2F* h_DeltaPhiJJ_SR7_EM;
    TH2F* h_DeltaPhiJJ_SR8_EE;
    TH2F* h_DeltaPhiJJ_SR8_MM;
    TH2F* h_DeltaPhiJJ_SR9_EM;
    
    //-----------------
    TH2F* h_pTJJ_SR6_EE;
    TH2F* h_pTJJ_SR6_MM;
    TH2F* h_pTJJ_SR7_EM;
    TH2F* h_pTJJ_SR8_EE;
    TH2F* h_pTJJ_SR8_MM;
    TH2F* h_pTJJ_SR9_EM;
    //--------------------------- 
    TH2F* h_DeltaPhiMETL1_SR6_EE;
    TH2F* h_DeltaPhiMETL1_SR6_MM;
    TH2F* h_DeltaPhiMETL1_SR7_EM;
    TH2F* h_DeltaPhiMETL1_SR8_EE;
    TH2F* h_DeltaPhiMETL1_SR8_MM;
    TH2F* h_DeltaPhiMETL1_SR9_EM;
    //--------------------
    TH2F* h_DeltaPhiMETL2_SR6_EE;
    TH2F* h_DeltaPhiMETL2_SR6_MM;
    TH2F* h_DeltaPhiMETL2_SR7_EM;
    TH2F* h_DeltaPhiMETL2_SR8_EE;
    TH2F* h_DeltaPhiMETL2_SR8_MM;
    TH2F* h_DeltaPhiMETL2_SR9_EM;
    //--------------------
    TH2F* h_DeltaPhiMETJ1_SR6_EE;
    TH2F* h_DeltaPhiMETJ1_SR6_MM;
    TH2F* h_DeltaPhiMETJ1_SR7_EM;
    TH2F* h_DeltaPhiMETJ1_SR8_EE;
    TH2F* h_DeltaPhiMETJ1_SR8_MM;
    TH2F* h_DeltaPhiMETJ1_SR9_EM;
    //--------------------
    TH2F* h_DeltaPhiMETJ2_SR6_EE;
    TH2F* h_DeltaPhiMETJ2_SR6_MM;
    TH2F* h_DeltaPhiMETJ2_SR7_EM;
    TH2F* h_DeltaPhiMETJ2_SR8_EE;
    TH2F* h_DeltaPhiMETJ2_SR8_MM;
    TH2F* h_DeltaPhiMETJ2_SR9_EM;
    //--------------------
    TH2F* h_DeltaPhiMETLL_SR6_EE;
    TH2F* h_DeltaPhiMETLL_SR6_MM;
    TH2F* h_DeltaPhiMETLL_SR7_EM;
    TH2F* h_DeltaPhiMETLL_SR8_EE;
    TH2F* h_DeltaPhiMETLL_SR8_MM;
    TH2F* h_DeltaPhiMETLL_SR9_EM;
    //--------------------
    TH2F* h_DeltaPhiMETJJ_SR6_EE;
    TH2F* h_DeltaPhiMETJJ_SR6_MM;
    TH2F* h_DeltaPhiMETJJ_SR7_EM;
    TH2F* h_DeltaPhiMETJJ_SR8_EE;
    TH2F* h_DeltaPhiMETJJ_SR8_MM;
    TH2F* h_DeltaPhiMETJJ_SR9_EM;
      //--------------------------- 
    TH2F* h_DeltaRJJ_SR6_EE;
    TH2F* h_DeltaRJJ_SR6_MM;
    TH2F* h_DeltaRJJ_SR7_EM;
    TH2F* h_DeltaRJJ_SR8_EE;
    TH2F* h_DeltaRJJ_SR8_MM;
    TH2F* h_DeltaRJJ_SR9_EM;
      //-------------
    TH2F* h_etaL1_SR6_EE;
    TH2F* h_etaL1_SR6_MM;
    TH2F* h_etaL1_SR7_EM;
    TH2F* h_etaL1_SR8_EE;
    TH2F* h_etaL1_SR8_MM;
    TH2F* h_etaL1_SR9_EM;
      //----------
    TH2F* h_etaL2_SR6_EE;
    TH2F* h_etaL2_SR6_MM;
    TH2F* h_etaL2_SR7_EM;
    TH2F* h_etaL2_SR8_EE;
    TH2F* h_etaL2_SR8_MM;
    TH2F* h_etaL2_SR9_EM;
      //----------
    TH2F* h_etaJ1_SR6_EE;
    TH2F* h_etaJ1_SR6_MM;
    TH2F* h_etaJ1_SR7_EM;
    TH2F* h_etaJ1_SR8_EE;
    TH2F* h_etaJ1_SR8_MM;
    TH2F* h_etaJ1_SR9_EM;
      //----------
    TH2F* h_etaJ2_SR6_EE;
    TH2F* h_etaJ2_SR6_MM;
    TH2F* h_etaJ2_SR7_EM;
    TH2F* h_etaJ2_SR8_EE;
    TH2F* h_etaJ2_SR8_MM;
    TH2F* h_etaJ2_SR9_EM;
      //----------
    TH2F* h_DeltaEtaJJ_SR6_EE;
    TH2F* h_DeltaEtaJJ_SR6_MM;
    TH2F* h_DeltaEtaJJ_SR7_EM;
    TH2F* h_DeltaEtaJJ_SR8_EE;
    TH2F* h_DeltaEtaJJ_SR8_MM;
    TH2F* h_DeltaEtaJJ_SR9_EM;
      //----------
    TH2F* h_DeltaYJJ_SR6_EE;
    TH2F* h_DeltaYJJ_SR6_MM;
    TH2F* h_DeltaYJJ_SR7_EM;
    TH2F* h_DeltaYJJ_SR8_EE;
    TH2F* h_DeltaYJJ_SR8_MM;
    TH2F* h_DeltaYJJ_SR9_EM;
    //---------------
    TH2F* h_mTL1MET_SR6_EE; 
    TH2F* h_mTL1MET_SR6_MM; 
    TH2F* h_mTL1MET_SR7_EM; 
    TH2F* h_mTL1MET_SR8_EE; 
    TH2F* h_mTL1MET_SR8_MM; 
    TH2F* h_mTL1MET_SR9_EM; 
    //---------------
    TH2F* h_mTL2MET_SR6_EE; 
    TH2F* h_mTL2MET_SR6_MM; 
    TH2F* h_mTL2MET_SR7_EM; 
    TH2F* h_mTL2MET_SR8_EE; 
    TH2F* h_mTL2MET_SR8_MM; 
    TH2F* h_mTL2MET_SR9_EM; 
    //-------------
    TH2F* h_NJets_SR6_EE;
    TH2F* h_NJets_SR6_MM;
    TH2F* h_NJets_SR7_EM;
    TH2F* h_NJets_SR8_EE;
    TH2F* h_NJets_SR8_MM;
    TH2F* h_NJets_SR9_EM;
    
      TH2F* h_DeltaPhiLLJJ_SR6_EE;
    TH2F* h_DeltaPhiLLJJ_SR6_MM;
    TH2F* h_DeltaPhiLLJJ_SR7_EM;
    TH2F* h_DeltaPhiLLJJ_SR8_EE;
    TH2F* h_DeltaPhiLLJJ_SR8_MM;
    TH2F* h_DeltaPhiLLJJ_SR9_EM;
    //---------------
    TH2F* h_DeltaPhiL1JJ_SR6_EE;
    TH2F* h_DeltaPhiL1JJ_SR6_MM;
    TH2F* h_DeltaPhiL1JJ_SR7_EM;
    TH2F* h_DeltaPhiL1JJ_SR8_EE;
    TH2F* h_DeltaPhiL1JJ_SR8_MM;
    TH2F* h_DeltaPhiL1JJ_SR9_EM;
    //---------------
    TH2F* h_DeltaPhiL2JJ_SR6_EE;
    TH2F* h_DeltaPhiL2JJ_SR6_MM;
    TH2F* h_DeltaPhiL2JJ_SR7_EM;
    TH2F* h_DeltaPhiL2JJ_SR8_EE;
    TH2F* h_DeltaPhiL2JJ_SR8_MM;
    TH2F* h_DeltaPhiL2JJ_SR9_EM;
    //---------------
    TH2F* h_DeltaRLLJJ_SR6_EE;
    TH2F* h_DeltaRLLJJ_SR6_MM;
    TH2F* h_DeltaRLLJJ_SR7_EM;
    TH2F* h_DeltaRLLJJ_SR8_EE;
    TH2F* h_DeltaRLLJJ_SR8_MM;
    TH2F* h_DeltaRLLJJ_SR9_EM;
    //---------------
    TH2F* h_NBJets_SR6_EE;
    TH2F* h_NBJets_SR6_MM;
    TH2F* h_NBJets_SR7_EM;
    TH2F* h_NBJets_SR8_EE;
    TH2F* h_NBJets_SR8_MM;
    TH2F* h_NBJets_SR9_EM;
    //---------------
    TH2F* h_NCJets_SR6_EE;
    TH2F* h_NCJets_SR6_MM;
    TH2F* h_NCJets_SR7_EM;
    TH2F* h_NCJets_SR8_EE;
    TH2F* h_NCJets_SR8_MM;
    TH2F* h_NCJets_SR9_EM;
    //---------------
    TH2F* h_MET_SR6_EE;
    TH2F* h_MET_SR6_MM;
    TH2F* h_MET_SR7_EM;
    TH2F* h_MET_SR8_EE;
    TH2F* h_MET_SR8_MM;
    TH2F* h_MET_SR9_EM;
    //---------------
    TH2F* h_HT_SR6_EE;
    TH2F* h_HT_SR6_MM;
    TH2F* h_HT_SR7_EM;
    TH2F* h_HT_SR8_EE;
    TH2F* h_HT_SR8_MM;
    TH2F* h_HT_SR9_EM;
    //---------------
    TH2F* h_mWWt_SR6_EE;
    TH2F* h_mWWt_SR6_MM;
    TH2F* h_mWWt_SR7_EM;
    TH2F* h_mWWt_SR8_EE;
    TH2F* h_mWWt_SR8_MM;
    TH2F* h_mWWt_SR9_EM;
    

    
    TH1F* cutflow_EE;
    TH1F* cutflow_EE_MCWeight;
    TH1F* cutflow_EE_LSF;
    TH1F* cutflow_EE_bTagWeight;
    TH1F* cutflow_EE_chargeFlipWeight;
    TH1F* cutflow_EE_triggerWeight;
    TH1F* cutflow_EE_ALL;
    
    TH1F* cutflow_MM;
    TH1F* cutflow_MM_MCWeight;
    TH1F* cutflow_MM_LSF;
    TH1F* cutflow_MM_bTagWeight;
//     TH1F* cutflow_MM_chargeFlipWeight;
    TH1F* cutflow_MM_triggerWeight;
    TH1F* cutflow_MM_ALL;
    
    TH1F* cutflow_EM;
    TH1F* cutflow_EM_MCWeight;
    TH1F* cutflow_EM_LSF;
    TH1F* cutflow_EM_bTagWeight;
    TH1F* cutflow_EM_chargeFlipWeight;
    TH1F* cutflow_EM_triggerWeight;
    TH1F* cutflow_EM_ALL;
    
    TH1F* cutflow_ME;
    TH1F* cutflow_ME_MCWeight;
    TH1F* cutflow_ME_LSF;
    TH1F* cutflow_ME_bTagWeight;
    TH1F* cutflow_ME_chargeFlipWeight;
    TH1F* cutflow_ME_triggerWeight;
    TH1F* cutflow_ME_ALL;

    
    
    SUSYObjDef m_susyObj;      // SUSY object definitions
    
    TSelector_SusyNtuple();
    virtual ~TSelector_SusyNtuple(){};

    // Output Text File
    ofstream out;

    // Begin is called before looping on entries
    virtual void    SlaveBegin(TTree *tree);
    virtual void    Begin(TTree *tree);
    // Terminate is called after looping is finished
    virtual void    SlaveTerminate();
    virtual void    Terminate();

    // Main event loop function
    virtual Bool_t  Process(Long64_t entry);
		      
    bool defineHistos();
    bool writeHistos();
    bool addHistos();
    
    
    void fillHistos_SR6_EE(int mcid, float cut_EE, float weight_ALL_EE, float METrel, float HT, float mWWt, float mCT, TLorentzVector el1_TLV, TLorentzVector el2_TLV, const Met* susymet, Electron* el1, Electron* el2, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);
    
    void fillHistos_SR8_EE(int mcid, float cut_EE, float weight_ALL_EE, float METrel, float HT, float mWWt, float mCT, TLorentzVector el1_TLV, TLorentzVector el2_TLV, const Met* susymet, Electron* el1, Electron* el2, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);    
    
    void fillHistos_SR6_MM(int mcid, float cut_MM, float weight_ALL_MM, float METrel, float HT, float mWWt, float mCT, TLorentzVector mu1_TLV, TLorentzVector mu2_TLV, const Met* susymet, Muon* mu1, Muon* mu2, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);
    
    void fillHistos_SR8_MM(int mcid, float cut_MM, float weight_ALL_MM, float METrel, float HT, float mWWt, float mCT, TLorentzVector mu1_TLV, TLorentzVector mu2_TLV, const Met* susymet, Muon* mu1, Muon* mu2, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);
    
    void fillHistos_SR7_EM(int mcid, float cut_EM, float weight_ALL_EM, float METrel, float HT, float mWWt, float mCT, TLorentzVector mu_TLV, TLorentzVector el_TLV, const Met* susymet, Muon* mu, Electron* el, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);
    
    void fillHistos_SR9_EM(int mcid, float cut_EM, float weight_ALL_EM, float METrel, float HT, float mWWt, float mCT, TLorentzVector mu_TLV, TLorentzVector el_TLV, const Met* susymet, Muon* mu, Electron* el, LeptonVector leptons, TLorentzVector signalJet1_TLV, TLorentzVector signalJet2_TLV, int nSignalJets, float mZTT_coll, float mZTT_mmc);
    
    // Cut methods
    bool CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons);
    bool CheckChargeFlipElectrons(const ElectronVector& signal_electrons);
    float getBTagWeight(const Event* evt);
    bool isNoZBoson(const LeptonVector& leptons);
    JetVector selectC20AndB20Jets(JetVector& m_baseJets);
    bool checkLeptonPt(const LeptonVector& leptons);
    float calcMt(const TLorentzVector &lep, const TLorentzVector &met);
//     float getFakeWeight(const LeptonVector &baseLeps, SusyMatrixMethod::FAKE_REGION region, float metRel, SusyMatrixMethod::SYSTEMATIC sys);
    float mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue = true);
    float calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, const JetVector &signalJets);
    float recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const JetVector& jets, bool useForward);
    float calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1);
    float calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met);
    float calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type);
//     float calcMZTauTau_MissMassCalc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type);
    float calcSumMv1(const JetVector &signalJets);
    float mT(TLorentzVector _l, TLorentzVector _nu);
    void fill_histos_EE(int cutnumber, float weight);
    void fill_histos_MM(int cutnumber, float weight);
    void fill_histos_EM(int cutnumber, float weight);
    

    // Selection region
    void setSelection(std::string s) { m_sel = s; }

    // debug check
//     bool debugEvent();
    Analysis::AnalysisMuonConfigurableScaleFactors* m_muon_scaleFactor;


    ClassDef(TSelector_SusyNtuple, 1);

  protected:
    int sample_identifier;
    int mcid_of_first_entry;
    float sumw_from_histo;
    std::string         m_sel;          // event selection string
    bool m_kIsData;
    bool runWithPoD;
    bool rejectTaus;

    DilTrigLogic*      m_trigObjWithoutRU;      // My trigger logic class
    chargeFlip m_chargeFlip;
//     SusyMatrixMethod::DiLeptonMatrixMethod* m_matrix;
    
    //initialize missing mass calculator MMC for identification of Z->tau tau events
    mmc MMC_sumet;
//     mmc Mmmc;
//     MMC_sumet = new mmc();
//     mmc MMC_sumet();
//     MissingMassCalculator missMassCalc;

    // Cut variables
    
    bool                m_selectB;      // switch to select b-tagged jets
    bool                m_vetoB;        // switch to veto b-tagged jets
    bool                m_selectSFOS;   // switch to select SFOS pairs
    bool                m_vetoSFOS;     // switch to veto SFOS pairs

    bool                m_writeOut;     // switch to control output dump

    
    RecoTruthMatch                m_recoTruthMatch;       // Lepton truth matching tool
    
  bool calcFakeContribution; 
};

#endif
