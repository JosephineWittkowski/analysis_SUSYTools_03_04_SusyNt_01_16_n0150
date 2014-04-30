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
#include "SusyNtuple/SusyNtTruthAna.h"
#include "SusyNtuple/SusyNtTools.h"
#include "SusyNtuple/SusyNtAna.h"
#include "SusyNtuple/DilTrigLogic.h"
#include "SUSYTools/SUSYObjDef.h"
#include "LeptonTruthTools/RecoTruthMatch.h"
#include "MuonEfficiencyCorrections/AnalysisMuonConfigurableScaleFactors.h"
#include "SusyNtuple/SusyDefs.h"
#include "SusyNtuple/WhTruthExtractor.h"
#include "Mt2/mt2_bisect.h" 
#include "SusyMatrixMethod/DiLeptonMatrixMethod.h"
// #include "SusyXSReader/XSReader.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
// #include "mmc/mmc.cpp"
// #include "MultiLep/CutflowTools.h"
// 
// #include "MultiLep/MuonD3PDObject.h"
// #include "MultiLep/ElectronD3PDObject.h"
// #include "MultiLep/VertexD3PDObject.h"
// #include "MultiLep/METD3PDObject.h"
// #include "MultiLep/JetD3PDObject.h"
// #include "MultiLep/TrackD3PDObject.h"
// #include "MultiLep/JetTools.h"
// #include "MultiLep/LeptonInfo.h"
// #include "TupleMaker.h"

#ifndef __CINT__
#include "ChargeFlip/chargeFlip.h"
#else
class chargeFlip ;
#endif

#include <fstream>


using Susy::Lepton;
  using Susy::Jet;
  using Susy::Met;
struct FourMom {
    double px, py, pz, E;
    bool isMu, isEl, isJet;
    int q;
    FourMom() : px(0), py(0), pz(0), E(0), q(0), isMu(false), isEl(false), isJet(false) {}
#ifndef __CINT__
// cint is not able to parse 'complex' code; see
// http://root.cern.ch/drupal/content/interacting-shared-libraries-rootcint
    FourMom& set4mom(const Lepton &l) { px=l.Px(); py=l.Py(); pz=l.Pz(); E=l.E(); q=l.q; return *this; }
    FourMom& set4mom(const Jet &j)    { px=j.Px(); py=j.Py(); pz=j.Pz(); E=j.E(); return *this; }
    FourMom& setMu(const Lepton &l) { isMu=true; isEl = isJet = false; return set4mom(l); }
    FourMom& setEl(const Lepton &l) { isEl=true; isMu = isJet = false; return set4mom(l); }
    FourMom& setJet(const Jet &j)   { isJet=true; isMu = isEl = false; return set4mom(j); }
    FourMom& setMet(const Met &m)   { isJet=isMu=isEl=false; px=m.lv().Px(); py=m.lv().Py(); E=m.lv().E(); return *this; }
#endif
};

struct EventParameters {
    double weight;
    unsigned int eventNumber;
    unsigned int runNumber;
    bool ismc;
    float metrel;
    EventParameters() : weight(0), eventNumber(0), runNumber(0), ismc(0), metrel(0) {}
#ifndef __CINT__
    EventParameters& setWeight(const double &w) { weight=w; return *this; }
    EventParameters& setEvent(const unsigned int &e) { eventNumber=e; return *this; }
    EventParameters& setRun(const unsigned int &r) { runNumber=r; return *this; }
    EventParameters& setIsmc(const bool &im) { ismc=im; return *this; }
    EventParameters& setMetrel(const float &metr) { metrel=metr; return *this; }
#endif
};

class TSelector_SusyNtuple : public SusyNtAna
{

  public:
    
//   Event* event_test;
//   EventParameters   pars; 
//   TBranch        *b_pars; 
  TBranch* m_eventParameters_b;
  EventParameters* m_eventParameters;
  
//   int truthParticles_pdgId;
//   TBranch *truthParticles_pdgId;
  
  unsigned int eventNumber;
  TBranch *b_pars_eventNumber;

    
    TH1F* h_storeSumwMcid;
    
    TH1F* cutflow_EE;
    TH1F* cutflow_EE_ALL;
    
    TH1F* cutflow_MM;
    TH1F* cutflow_MM_ALL;
    
    TH1F* cutflow_EM;
    TH1F* cutflow_EM_ALL;
    
    TH1F* cutflow_ME;
    TH1F* cutflow_ME_ALL;
    
    TH2F* h_NpreTaus;
      
    TH2F* h_DeltaR_JVF_ljOR_EE; 
    TH2F* h_DeltaR_JVF_ljOR_MM; 
    TH2F* h_DeltaR_JVF_ljOR_mu_EM;
    TH2F* h_DeltaR_JVF_ljOR_el_EM;
    
    TH2F* h_DeltaR_mll_ljOR_EE; 
    TH2F* h_DeltaR_mll_ljOR_MM; 
    TH2F* h_DeltaR_mll_ljOR_mu_EM;
    TH2F* h_DeltaR_mll_ljOR_el_EM;    
    
    TH2F* h_DeltaR_leptonType_ljOR_EE;
    TH2F* h_DeltaR_leptonType_ljOR_MM;
    TH2F* h_DeltaR_leptonType_ljOR_mu_EM;
    TH2F* h_DeltaR_leptonType_ljOR_el_EM;
    
    TH1F* h_3rdleptonType_EE;
    TH1F* h_3rdleptonType_MM;
    TH1F* h_3rdleptonType_mu_EM;
    TH1F* h_3rdleptonType_el_EM; 
    
    TH2F* h_DeltaR_ptcone_ljOR_PR_EE; 
    TH2F* h_DeltaR_etcone_ljOR_PR_EE;
    TH2F* h_DeltaR_ptcone_ljOR_PR_MM;
    TH2F* h_DeltaR_ptcone_ljOR_PR_mu_EM;
    TH2F* h_DeltaR_ptcone_ljOR_PR_el_EM;
    TH2F* h_DeltaR_etcone_ljOR_PR_el_EM;
    
    TH1F* h_Ntpr_ljOR_HF_EE;
    TH1F* h_Ntpr_ljOR_LF_EE;
    TH1F* h_Ntpr_ljOR_HF_MM;
    TH1F* h_Ntpr_ljOR_LF_MM;
    TH1F* h_Ntpr_ljOR_HF_mu_EM;
    TH1F* h_Ntpr_ljOR_LF_mu_EM;
    TH1F* h_Ntpr_ljOR_HF_el_EM;
    TH1F* h_Ntpr_ljOR_LF_el_EM;    
    
    TH1F* h_DeltaR_min_lostLepton_truthParticle_HF_EE;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_LF_EE;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_HF_MM;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_LF_MM;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_HF_el_EM;
    TH1F* h_DeltaR_min_lostLepton_truthParticle_LF_el_EM;    
    
    TH1F* h_DeltaR_min_lostLepton_truthJet_HF_EE;
    TH1F* h_DeltaR_min_lostLepton_truthJet_LF_EE;
    TH1F* h_DeltaR_min_lostLepton_truthJet_HF_MM;
    TH1F* h_DeltaR_min_lostLepton_truthJet_LF_MM;
    TH1F* h_DeltaR_min_lostLepton_truthJet_HF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_truthJet_LF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_truthJet_HF_el_EM;
    TH1F* h_DeltaR_min_lostLepton_truthJet_LF_el_EM;    
    
    TH1F* h_DeltaR_min_lostLepton_preJet_HF_EE;
    TH1F* h_DeltaR_min_lostLepton_preJet_LF_EE;
    TH1F* h_DeltaR_min_lostLepton_preJet_HF_MM;
    TH1F* h_DeltaR_min_lostLepton_preJet_LF_MM;
    TH1F* h_DeltaR_min_lostLepton_preJet_HF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_preJet_LF_mu_EM;
    TH1F* h_DeltaR_min_lostLepton_preJet_HF_el_EM;
    TH1F* h_DeltaR_min_lostLepton_preJet_LF_el_EM;    
    
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_HF_EE;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_LF_EE;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_HF_MM;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_LF_MM;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM;
    TH2F* h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM;    
    
    TH2F* h_DeltaR_ptcone_ljOR_HF_EE; 
    TH2F* h_DeltaR_etcone_ljOR_HF_EE;
    TH2F* h_DeltaR_ptcone_ljOR_HF_MM;
    TH2F* h_DeltaR_ptcone_ljOR_HF_mu_EM;
    TH2F* h_DeltaR_ptcone_ljOR_HF_el_EM;
    TH2F* h_DeltaR_etcone_ljOR_HF_el_EM; 
        
    TH1F* h_DeltaR_em_EM;
    
    TH2F* h_failedSignalCriteria_EE;
    TH2F* h_failedSignalCriteria_MM;
    TH2F* h_failedSignalCriteria_mu_EM;
    TH2F* h_failedSignalCriteria_el_EM;
        
    TH2F* h_etcone30lZcandImpact_EE_SRSS1;   
    TH2F* h_etcone30lZcandImpact_MM_SRSS1;        
    TH2F* h_etcone30lZcandImpact_mu_EM_SRSS1;  
    TH2F* h_etcone30lZcandImpact_el_EM_SRSS1;  
   
    TH2F* h_Nleptons_ZcandImpact_EE_SRSS1;
    TH2F* h_Nleptons_ZcandImpact_MM_SRSS1;
    TH2F* h_Nleptons_ZcandImpact_mu_EM_SRSS1;
    TH2F* h_Nleptons_ZcandImpact_el_EM_SRSS1;
    
    TH2F* h_mllZcandImpact_EE_SRSS1;
    TH2F* h_mllZcandImpact_MM_SRSS1;
    TH2F* h_mllZcandImpact_mu_EM_SRSS1;
    TH2F* h_mllZcandImpact_el_EM_SRSS1;
    
    TH2F* h_mTllZcandImpact_EE_SRSS1;
    TH2F* h_mTllZcandImpact_MM_SRSS1;
    TH2F* h_mTllZcandImpact_mu_EM_SRSS1;   
    TH2F* h_mTllZcandImpact_el_EM_SRSS1;   
    
    TH2F* h_pTlZcandImpact_EE_SRSS1;
    TH2F* h_pTlZcandImpact_MM_SRSS1;
    TH2F* h_pTlZcandImpact_mu_EM_SRSS1;
    TH2F* h_pTlZcandImpact_el_EM_SRSS1;
    
    TH2F* h_IClZcandImpact_EE_SRSS1;
    TH2F* h_IClZcandImpact_MM_SRSS1;
    TH2F* h_IClZcandImpact_mu_EM_SRSS1;
    TH2F* h_IClZcandImpact_el_EM_SRSS1;
    
    TH2F* h_etalZcandImpact_EE_SRSS1;
    TH2F* h_etalZcandImpact_MM_SRSS1;
    TH2F* h_etalZcandImpact_mu_EM_SRSS1;
    TH2F* h_etalZcandImpact_el_EM_SRSS1;
    
    TH2F* h_ptcone30lZcandImpact_EE_SRSS1;
    TH2F* h_ptcone30lZcandImpact_MM_SRSS1;
    TH2F* h_ptcone30lZcandImpact_mu_EM_SRSS1;
    TH2F* h_ptcone30lZcandImpact_el_EM_SRSS1;
    
    TH2F* h_d0SiglZcandImpact_EE_SRSS1;
    TH2F* h_d0SiglZcandImpact_MM_SRSS1;
    TH2F* h_d0SiglZcandImpact_mu_EM_SRSS1;
    TH2F* h_d0SiglZcandImpact_el_EM_SRSS1;
    
    TH2F* h_z0SinThetalZcandImpact_EE_SRSS1;
    TH2F* h_z0SinThetalZcandImpact_MM_SRSS1;
    TH2F* h_z0SinThetalZcandImpact_mu_EM_SRSS1;
    TH2F* h_z0SinThetalZcandImpact_el_EM_SRSS1;
       
 
    
    TH2F* h_Mljj_EE_SRSS1;
    TH2F* h_Mljj_MM_SRSS1;
    TH2F* h_Mljj_EM_SRSS1;
    
    TH2F* h_Mlj_EE_SRSS1;
    TH2F* h_Mlj_MM_SRSS1;
    TH2F* h_Mlj_EM_SRSS1;    
    
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
    
    TH2F* h_pTl0_raw_EE_SRSS1;
    TH2F* h_pTl0_raw_MM_SRSS1;
    TH2F* h_pTl0_raw_EM_SRSS1;
    
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
    
    TH2F* h_mTlmax_EE_SRSS1;
    TH2F* h_mTlmax_EE_SRSS2;
    TH2F* h_mTlmax_MM_SRSS1;  
    TH2F* h_mTlmax_MM_SRSS2;
    TH2F* h_mTlmax_MM_SRSS3;
    TH2F* h_mTlmax_MM_SRSS4;
    TH2F* h_mTlmax_EM_SRSS1;
    TH2F* h_mTlmax_EM_SRSS2;
    TH2F* h_mTlmax_EE_SROS1;
    TH2F* h_mTlmax_MM_SROS1;
    TH2F* h_mTlmax_EM_SROS1;

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
    
    
    TH2F* h_mT2_EE_SRSS1;
    TH2F* h_mT2_EE_SRSS2;
    TH2F* h_mT2_MM_SRSS1;
    TH2F* h_mT2_MM_SRSS2;  
    TH2F* h_mT2_MM_SRSS3;
    TH2F* h_mT2_MM_SRSS4;
    TH2F* h_mT2_EM_SRSS1;
    TH2F* h_mT2_EM_SRSS2;
    TH2F* h_mT2_EE_SROS1;
    TH2F* h_mT2_MM_SROS1;
    TH2F* h_mT2_EM_SROS1;
    
    TH2F* h_mT2J_EE_SRSS1;
    TH2F* h_mT2J_EE_SRSS2;
    TH2F* h_mT2J_MM_SRSS1;
    TH2F* h_mT2J_MM_SRSS2;  
    TH2F* h_mT2J_MM_SRSS3;
    TH2F* h_mT2J_MM_SRSS4;
    TH2F* h_mT2J_EM_SRSS1;
    TH2F* h_mT2J_EM_SRSS2;
    TH2F* h_mT2J_EE_SROS1;
    TH2F* h_mT2J_MM_SROS1;
    TH2F* h_mT2J_EM_SROS1;    
    
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
  TH2F* h_pTll_EE_SRSS1; 
  TH2F* h_pTll_EE_SRSS2; 
  TH2F* h_pTll_MM_SRSS1;   
  TH2F* h_pTll_MM_SRSS2; 
  TH2F* h_pTll_MM_SRSS3; 
  TH2F* h_pTll_MM_SRSS4; 
  TH2F* h_pTll_EM_SRSS1; 
  TH2F* h_pTll_EM_SRSS2; 
  TH2F* h_pTll_EE_SROS1; 
  TH2F* h_pTll_MM_SROS1; 
  TH2F* h_pTll_EM_SROS1; 
  
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
  
  TH2F* cutflow_EE_sysUncert;  
  TH2F* cutflow_MM_sysUncert; 
  TH2F* cutflow_EM_sysUncert;
  
    
    SUSYObjDef m_susyObj;      // SUSY object definitions
    
    TSelector_SusyNtuple();
    virtual ~TSelector_SusyNtuple(){};

    // Output Text File
    ofstream out;

    // Begin is called before looping on entries
    virtual void    Begin(TTree *tree);
    virtual void    SlaveBegin(TTree *tree);
//     virtual void    Init(TTree *tree);
    // Main event loop function
    virtual Bool_t  Process(Long64_t entry);
    // Terminate is called after looping is finished
    
    virtual void    Terminate();
    virtual void    SlaveTerminate();
    
  


    
		     
    // Cut methods
    bool CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons);
    bool CheckChargeFlipElectrons(const ElectronVector& signal_electrons);
    float getBTagWeight(const Event* evt, BTagSys SysSettingBTag);
    float recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const JetVector& jets, bool useForward);
    float calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1);
    float calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1);
    bool checkLeptonPt(const LeptonVector& leptons);
    float mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue);
    float calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, const JetVector &signalJets);
    float calcMeff(TLorentzVector met, const JetVector &signalJets);
    float calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met);
    float calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type);
    float calcMt(TLorentzVector _l, TLorentzVector _nu);
    float calcSumMv1(const JetVector &signalJets);
    
    void defineHistos();
    void defineHistos_sysUncert();
    void writeHistos();
    void writeHistos_sysUncert();
//     void addHistos();
    void fillHistos_EE(int cutnumber, float weight);
    void fillHistos_MM(int cutnumber, float weight);
    void fillHistos_EM(int cutnumber, float weight);
    
    void calcJet_variables(TLorentzVector met_TLV);
    void calc_EE_variables(LeptonVector &leptons, Electron* el0, Electron* el1, TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EE, SusyNtSys SysSetting, bool n0150BugFix);
    void calc_MM_variables(LeptonVector &leptons, Muon* mu0, Muon* mu1, TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_MM, SusyNtSys SysSetting, bool n0150BugFix);
    void calc_EM_variables(LeptonVector &leptons, Electron* el, Muon* mu, TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EM, SusyNtSys SysSetting, bool n0150BugFix);
    
    void fillHistos_EE_SRSS1(float cut_EE, float weight_ALL_EE);    
    void fillHistos_MM_SRSS1(float cut_MM, float weight_ALL_MM);    
    void fillHistos_EM_SRSS1(float cut_EM, float weight_ALL_EM);
    
    float getFakeWeight(const LeptonVector &baseLeps, susy::fake::Region region, float metRel, SusyMatrixMethod::SYSTEMATIC sys);
    
    float calc_D0(bool unbiased, const Lepton* lep);
    static bool compareElecMomentum (Electron* e0, Electron* e1);
    static bool compareMuonMomentum (Muon* mu0, Muon* mu1);
//     ElectronVector getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys);
//     ElectronVector getOverlapElectrons(SusyNtObject* susyNt, SusyNtSys sys);
//     MuonVector getSoftMuons(SusyNtObject* susyNt, SusyNtSys sys);
//     MuonVector getOverlapMuons(SusyNtObject* susyNt, SusyNtSys sys);
    bool isCMSJet(const Susy::Jet* jet);
    int numberOfCMSJets(const JetVector& jets);    
    vector<TLorentzVector> overlapRemoval(vector<TLorentzVector> objects_type1, vector<TLorentzVector> indices_2, double dr, bool sameType, bool removeSoft) ;
    bool doEventCleaning_andFillHistos(int flag, float weight_ALL_EE, float weight_ALL_MM, float weight_ALL_EM, SusyNtSys SysSetting, bool n0150BugFix);
    bool initTupleMaker(const std::string &outFilename, const std::string &treename);
    bool initFile(const std::string &outFilename);
    bool initTree(const std::string &treename);
    bool initTreeBranches();
    bool fillTupleMaker(const double weight, const unsigned int run, const unsigned int event, const bool isMc, const Susy::Lepton &l0, const Susy::Lepton &l1, const Susy::Met &met, const LeptonVector &otherLeptons, const JetVector &jets, float METrel);
    LeptonVector getAnyElOrMu(SusyNtObject &susyNt, const Lepton *l0, const Lepton *l1);
    bool closeTupleMaker();
//     FourMom jet2FourMom (const Jet *j);
//     FourMom lepton2FourMom (const Lepton *l);
//     SusyNtSys returnSysUncertType(int isys);
//     int returnSysUncertNumber(SusyNtSys UncertType);
//     int returnSysUncertBTagNumber(BTagSys UncertType);
    char *GetID(Int_t type);
    float getLeptonSF(const LeptonVector& leptons, int SFUncertType);

    // Selection region
    void setSelection(std::string s) { m_sel = s; }

    // debug check
    bool debugEvent();
    Analysis::AnalysisMuonConfigurableScaleFactors* m_muon_scaleFactor;
    bool makeNTuple;
    bool run_on_SusyNtuple;
    bool calcSysUncert;

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
    float pTl0_EE;
    float pTl1_EE;
    float etal0_EE;
    float etal1_EE;
    float DeltaR_EE;
    float pTll_EE;
    float Mll_EE;
    float METrel_EE;
    float MET_EE;
    float HT_EE;
    float mTWW_EE;
    float mT_EE;
    float mTmin_EE;
    float mTmax_EE;
    float mTl0MET_EE;
    float mTl1MET_EE;
    float mMET_EE;
    float DeltaPhi_EE;
    float DeltaPhiMETl0_EE;
    float DeltaPhiMETl1_EE;
    float DeltaPhiMETll_EE;
    float mT2_EE;  
    float mT2J_EE;       
    float DeltaPhilljj_EE;
    float DeltaPhil0jj_EE;
    float DeltaPhil1jj_EE;
    float DeltaRlljj_EE;
    float Mljj_EE;
    float Mlj_EE;
    float DeltaEtall_EE;
    
    float D0_branch_l0_EE;
    float D0_branch_l1_EE;
    float D0err_branch_l0_EE;
    float D0err_branch_l1_EE;
    
    float sD0Signif_branch_l0_EE;
    float sD0Signif_branch_l1_EE;
  
    int Nleptons_ZcandImpact_EE;
    float etcone30lZcandImpact_EE;
    
    float mllZcandImpact_EE;      
    float mTllZcandImpact_EE;
    float pTlZcandImpact_EE;
    float etalZcandImpact_EE;
    int IClZcandImpact_EE;
    float ptcone30lZcandImpact_EE;
    float d0SiglZcandImpact_EE;
    float z0SinThetalZcandImpact_EE;
    
    bool ZcandLep_exists_EE;
    bool ZcandLep_passesPT_EE;
    bool ZcandLep_passesEta_EE;
    bool ZcandLep_passesPTcone_EE;
    bool ZcandLep_passesETcone_EE;
    bool ZcandLep_passesD0_EE; 
    bool ZcandLep_passesZ0_EE; 
    bool ZcandLep_PassesMedium_EE;
    bool ZcandLep_PassesTight_EE; 
    bool ZcandLep_PassesORAndMllCut_EE;
    bool ZcandLep_PassesPR_EE;
    
    //#####################################
    
    float pTl0_MM;
    float pTl1_MM;
    float etal0_MM;
    float etal1_MM;
    float DeltaR_MM;
    float pTll_MM;
    float Mll_MM;
    float METrel_MM;
    float MET_MM;
    float HT_MM;
    float mTWW_MM;
    float mT_MM;
    float mTmin_MM;
    float mTmax_MM;
    float mTl0MET_MM;
    float mTl1MET_MM;
    float mMET_MM;
    float DeltaPhi_MM;
    float DeltaPhiMETl0_MM;
    float DeltaPhiMETl1_MM;
    float DeltaPhiMETll_MM;
    float mT2_MM;  
    float mT2J_MM;       
    float DeltaPhilljj_MM;
    float DeltaPhil0jj_MM;
    float DeltaPhil1jj_MM;
    float DeltaRlljj_MM;
    float Mljj_MM;
    float Mlj_MM;
    float DeltaEtall_MM;
    
    float D0_branch_l0_MM;
    float D0_branch_l1_MM;
    float D0err_branch_l0_MM;
    float D0err_branch_l1_MM;
    
    float sD0Signif_branch_l0_MM;
    float sD0Signif_branch_l1_MM;
    
    int Nleptons_ZcandImpact_MM;
    float mllZcandImpact_MM;      
    float mTllZcandImpact_MM;
    float pTlZcandImpact_MM;
    float etalZcandImpact_MM;
    int IClZcandImpact_MM;
    float ptcone30lZcandImpact_MM;
    float etcone30lZcandImpact_MM;
    float d0SiglZcandImpact_MM;
    float z0SinThetalZcandImpact_MM;
    
    bool ZcandLep_exists_MM;
    bool ZcandLep_passesPT_MM;
    bool ZcandLep_passesEta_MM;
    bool ZcandLep_passesPTcone_MM;
    bool ZcandLep_passesETcone_MM;
    bool ZcandLep_passesD0_MM; 
    bool ZcandLep_passesZ0_MM; 
    bool ZcandLep_PassesMedium_MM;
    bool ZcandLep_PassesTight_MM; 
    bool ZcandLep_PassesORAndMllCut_MM;
    bool ZcandLep_PassesPR_MM;
    //#####################################
    
    float pTl0_EM;
    float pTl1_EM;
    float etal0_EM;
    float etal1_EM;
    float DeltaR_EM;
    float pTll_EM;
    float Mll_EM;
    float METrel_EM;
    float MET_EM;
    float HT_EM;
    float mTWW_EM;
    float mT_EM;
    float mTmin_EM;
    float mTmax_EM;
    float mTl0MET_EM;
    float mTl1MET_EM;
    float mMET_EM;
    float DeltaPhi_EM;
    float DeltaPhiMETl0_EM;
    float DeltaPhiMETl1_EM;
    float DeltaPhiMETll_EM;
    float mT2_EM;  
    float mT2J_EM;       
    float DeltaPhilljj_EM;
    float DeltaPhil0jj_EM;
    float DeltaPhil1jj_EM;
    float DeltaRlljj_EM;
    float Mljj_EM;
    float Mlj_EM;
    float DeltaEtall_EM;
    
    float D0_branch_l0_EM;
    float D0_branch_l1_EM;
    float D0err_branch_l0_EM;
    float D0err_branch_l1_EM;
    
    float sD0Signif_branch_l0_EM;
    float sD0Signif_branch_l1_EM;
    
 
    int Nleptons_ZcandImpact_mu_EM;
    int Nleptons_ZcandImpact_el_EM;
    
    float mllZcandImpact_mu_EM;      
    float mTllZcandImpact_mu_EM;
    float pTlZcandImpact_mu_EM;
    float etalZcandImpact_mu_EM;
    int IClZcandImpact_mu_EM;
    float ptcone30lZcandImpact_mu_EM;
    float etcone30lZcandImpact_mu_EM;
    float d0SiglZcandImpact_mu_EM;
    float z0SinThetalZcandImpact_mu_EM;    
    
    float mllZcandImpact_el_EM;      
    float mTllZcandImpact_el_EM;
    float pTlZcandImpact_el_EM;
    float etalZcandImpact_el_EM;
    int IClZcandImpact_el_EM;
    float ptcone30lZcandImpact_el_EM;
    float etcone30lZcandImpact_el_EM;   
    float d0SiglZcandImpact_el_EM;
    float z0SinThetalZcandImpact_el_EM;
    
    bool ZcandLep_exists_mu_EM;
    bool ZcandLep_passesPT_mu_EM;
    bool ZcandLep_passesEta_mu_EM;
    bool ZcandLep_passesPTcone_mu_EM;
    bool ZcandLep_passesETcone_mu_EM;
    bool ZcandLep_passesD0_mu_EM; 
    bool ZcandLep_passesZ0_mu_EM; 
    bool ZcandLep_PassesMedium_mu_EM;
    bool ZcandLep_PassesTight_mu_EM; 
    bool ZcandLep_PassesORAndMllCut_mu_EM;
    bool ZcandLep_PassesPR_mu_EM;
    
    bool ZcandLep_exists_el_EM;
    bool ZcandLep_passesPT_el_EM;
    bool ZcandLep_passesEta_el_EM;
    bool ZcandLep_passesPTcone_el_EM;
    bool ZcandLep_passesETcone_el_EM;
    bool ZcandLep_passesD0_el_EM; 
    bool ZcandLep_passesZ0_el_EM; 
    bool ZcandLep_PassesMedium_el_EM;
    bool ZcandLep_PassesTight_el_EM; 
    bool ZcandLep_PassesORAndMllCut_el_EM;
    bool ZcandLep_PassesPR_el_EM;
    
    //#####################################
    
    ClassDef(TSelector_SusyNtuple, 1);

  protected:
    int sample_identifier;
    std::string         m_sel;          // event selection string

    DilTrigLogic*      m_trigObjWithoutRU;      // My trigger logic class
    chargeFlip m_chargeFlip;
    SusyMatrixMethod::DiLeptonMatrixMethod* m_matrix;
    SUSY::CrossSectionDB*                       m_susyXsec;     // SUSY cross section database
//     XSReader* susyXS;
//     SusyNtTruthAna* susyAnaTruth;
//     susy::wh::TupleMaker m_tupleMaker;
    //initialize missing mass calculator MMC for identification of Z->tau tau events
//     mmc MMC_sumet;
//     TGuiUtils* GuiUtils;

    // Cut variables
    
    bool                m_selectB;      // switch to select b-tagged jets
    bool                m_vetoB;        // switch to veto b-tagged jets
    bool                m_selectSFOS;   // switch to select SFOS pairs
    bool                m_vetoSFOS;     // switch to veto SFOS pairs

    bool                m_writeOut;     // switch to control output dump

    
    RecoTruthMatch                m_recoTruthMatch;       // Lepton truth matching tool
    
    unsigned int mcid_of_first_entry;
    float sumw_from_histo;
    
    bool m_kIsData;
    bool calcFakeContribution; 
    int isys;
    SusyNtSys SysSetting;
    BTagSys SysSettingBTag;
    int qflipSysUncertType;
    int SFUncertType;
    bool n0150BugFix;
    SusyMatrixMethod::SYSTEMATIC SysSettingFake;
    MCWeighter::WeightSys SysSettingPileup;
    
    enum LEP_TYPE{PR=0, CONV, HF, LF, TYPE_Undef};
    
    // Build a vector that is the difference between two vectors.
// Caveat1: computing the difference triggers copies of the vectors
// Caveat2: the result is not guaranteed to be sorted
// Caveat3: a-b != b-a
// Based on: http://stackoverflow.com/questions/14175858/c-subtract-vectors
  template <typename T>
  std::vector<T> subtract_vector(std::vector<T>& a, const std::vector<T>& b)
  {
    std::vector<T> difference;
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter( difference ));
    return difference;
  }
  
   TTree *tree_out;

  private:
    TFile *file_;
    TTree *tree_;
    FourMom l0_, l1_, met_;
    std::vector<FourMom> jets_, lowptLepts_;
    EventParameters eventPars_;
    
};

// #ifdef TSelector_SusyNtuple_cpp
//   void TSelector_SusyNtuple::Init(TTree *tree)
//   {
//     // The Init() function is called when the selector needs to initialize
//     // a new tree or chain. Typically here the branch addresses and branch
//     // pointers of the tree will be set.
//     // It is normally not necessary to make changes to the generated
//     // code, but the routine can be extended by the user if needed.
//     // Init() will be called many times when running on PROOF
//     // (once per file to be processed).
//     

//       
//   }
//   #endif // #ifdef TSelector_SusyNtuple_cpp

#endif