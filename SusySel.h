//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 7 15:37:45 2014 by ROOT version 5.34/11
// from TTree SusySel/TupleMaker tree
// found on file: file.root
//////////////////////////////////////////////////////////

#ifndef SusySel_h
#define SusySel_h

// Root Packages
#include "TTree.h"
// #include "TProofOutputFile.h"
// #include "TSystem.h"
// Susy Common
#include "SusyNtuple/SusyNtTruthAna.h"
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
// #include <vector>

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
    float mllZcandidate_mu;
    float mllZcandidate_el;
    EventParameters() : weight(0), eventNumber(0), runNumber(0), ismc(0), metrel(0), mllZcandidate_mu(0), mllZcandidate_el(0) {}
#ifndef __CINT__
    EventParameters& setWeight(const double &w) { weight=w; return *this; }
    EventParameters& setEvent(const unsigned int &e) { eventNumber=e; return *this; }
    EventParameters& setRun(const unsigned int &r) { runNumber=r; return *this; }
    EventParameters& setIsmc(const bool &im) { ismc=im; return *this; }
    EventParameters& setMetrel(const float &metr) { metrel=metr; return *this; }
    EventParameters& setMllZcand_mu(const float &mllZcand_mu) {mllZcandidate_mu = mllZcand_mu; return *this;}
    EventParameters& setMllZcand_el(const float &mllZcand_el) {mllZcandidate_el = mllZcand_el; return *this;}
#endif
};

class SusySel : public TSelector {
public :
  
  
    TH1F* cutflow_EE;
    TH1F* cutflow_EE_ALL;
    
    TH1F* cutflow_MM;
    TH1F* cutflow_MM_ALL;
    
    TH1F* cutflow_EM;
    TH1F* cutflow_EM_ALL;
    
    TH1F* cutflow_ME;
    TH1F* cutflow_ME_ALL;
    
    
      TH2F* h_pTl0_1j_EE;
    TH2F* h_pTl0_2j_EE;

    TH2F* h_pTl1_1j_EE;
    TH2F* h_pTl1_2j_EE;

    TH2F* h_DeltaRLeptons_1j_EE;
    TH2F* h_DeltaRLeptons_2j_EE;
      
    TH2F* h_pTj0_1j_EE;
    TH2F* h_pTj0_2j_EE;
      

    TH2F* h_pTj1_1j_EE;
    TH2F* h_pTj1_2j_EE;
      

    TH2F* h_mll_1j_EE;
    TH2F* h_mll_2j_EE;


    TH2F* h_METrel_1j_EE;
    TH2F* h_METrel_2j_EE;
      
    TH2F* h_MET_1j_EE;
    TH2F* h_MET_2j_EE;
      
    TH2F* h_HT_1j_EE;
    TH2F* h_HT_2j_EE;
      
    TH2F* h_mWWt_1j_EE;
    TH2F* h_mWWt_2j_EE;

    TH2F* h_mTlmin_1j_EE;
    TH2F* h_mTlmin_2j_EE;
      
    TH2F* h_mTlmax_1j_EE;
    TH2F* h_mTlmax_2j_EE;
      
    TH2F* h_meff_1j_EE;
    TH2F* h_meff_2j_EE;
      
    TH2F* h_mT2_1j_EE;
    TH2F* h_mT2_2j_EE;
      

    TH2F* h_mT2J_1j_EE;
    TH2F* h_mT2J_2j_EE;
      

    TH2F* h_mjj_1j_EE;
    TH2F* h_mjj_2j_EE;
	
    TH2F* h_DeltaPhiMETll_1j_EE;
    TH2F* h_DeltaPhiMETll_2j_EE;
	
    TH2F* h_DeltaPhill_1j_EE;
    TH2F* h_DeltaPhill_2j_EE;
      
    TH2F* h_NBJets_1j_EE;
    TH2F* h_NBJets_2j_EE;
      
    TH2F* h_NCJets_1j_EE;
    TH2F* h_NCJets_2j_EE;
      
    TH2F* h_NFJets_1j_EE;
    TH2F* h_NFJets_2j_EE;
      
    TH2F* h_DeltaPhijj_1j_EE;
    TH2F* h_DeltaPhijj_2j_EE;
      
    TH2F* h_pTjj_1j_EE;
    TH2F* h_pTjj_2j_EE;
      
    TH2F* h_pTll_1j_EE;
    TH2F* h_pTll_2j_EE;
      
    TH2F* h_DeltaPhiMETl0_1j_EE;
    TH2F* h_DeltaPhiMETl0_2j_EE;
      
    TH2F* h_DeltaPhiMETl1_1j_EE;
    TH2F* h_DeltaPhiMETl1_2j_EE;
	
    TH2F* h_DeltaPhiMETj0_1j_EE;
    TH2F* h_DeltaPhiMETj0_2j_EE;
      
    TH2F* h_DeltaPhiMETj1_1j_EE;
    TH2F* h_DeltaPhiMETj1_2j_EE;
      
    TH2F* h_DeltaPhiMETjj_1j_EE;
    TH2F* h_DeltaPhiMETjj_2j_EE;
	
    TH2F* h_DeltaRjj_1j_EE;
    TH2F* h_DeltaRjj_2j_EE;
      
    TH2F* h_etal0_1j_EE;
    TH2F* h_etal0_2j_EE;
	
    TH2F* h_etal1_1j_EE;
    TH2F* h_etal1_2j_EE;
	
    TH2F* h_etaj0_1j_EE;
    TH2F* h_etaj0_2j_EE;
	
    TH2F* h_etaj1_1j_EE;
    TH2F* h_etaj1_2j_EE;
      
    TH2F* h_mTl0MET_1j_EE;
    TH2F* h_mTl0MET_2j_EE;
      
    TH2F* h_mTl1MET_1j_EE;
    TH2F* h_mTl1MET_2j_EE;
	  
    TH2F* h_DeltaPhilljj_1j_EE;
    TH2F* h_DeltaPhilljj_2j_EE;
	
    TH2F* h_DeltaPhil0jj_1j_EE;
    TH2F* h_DeltaPhil0jj_2j_EE;
      
    TH2F* h_DeltaPhil1jj_1j_EE;
    TH2F* h_DeltaPhil1jj_2j_EE;
      
    TH2F* h_DeltaRlljj_1j_EE;
    TH2F* h_DeltaRlljj_2j_EE;
	
    TH2F* h_DeltaEtajj_1j_EE;
    TH2F* h_DeltaEtajj_2j_EE;
      
    TH2F* h_DeltaEtall_1j_EE;
    TH2F* h_DeltaEtall_2j_EE;
      
    TH2F* h_mTll_1j_EE;
    TH2F* h_mTll_2j_EE;
      
    TH2F* h_mMETll_1j_EE;
    TH2F* h_mMETll_2j_EE;
      
    TH2F* h_DeltaYjj_1j_EE;
    TH2F* h_DeltaYjj_2j_EE;
    
    TH2F* h_mljj_1j_EE;
    TH2F* h_mljj_2j_EE;
    
    TH2F* h_mlj_1j_EE;
    TH2F* h_mlj_2j_EE;
//=======================================================
    
    
      TH2F* h_pTl0_1j_MM;
    TH2F* h_pTl0_2j_MM;

    TH2F* h_pTl1_1j_MM;
    TH2F* h_pTl1_2j_MM;

    TH2F* h_DeltaRLeptons_1j_MM;
    TH2F* h_DeltaRLeptons_2j_MM;
      
    TH2F* h_pTj0_1j_MM;
    TH2F* h_pTj0_2j_MM;
      

    TH2F* h_pTj1_1j_MM;
    TH2F* h_pTj1_2j_MM;
      

    TH2F* h_mll_1j_MM;
    TH2F* h_mll_2j_MM;


    TH2F* h_METrel_1j_MM;
    TH2F* h_METrel_2j_MM;
      
    TH2F* h_MET_1j_MM;
    TH2F* h_MET_2j_MM;
      
    TH2F* h_HT_1j_MM;
    TH2F* h_HT_2j_MM;
      
    TH2F* h_mWWt_1j_MM;
    TH2F* h_mWWt_2j_MM;

    TH2F* h_mTlmin_1j_MM;
    TH2F* h_mTlmin_2j_MM;
      
    TH2F* h_mTlmax_1j_MM;
    TH2F* h_mTlmax_2j_MM;
      
    TH2F* h_meff_1j_MM;
    TH2F* h_meff_2j_MM;
      
    TH2F* h_mT2_1j_MM;
    TH2F* h_mT2_2j_MM;
      

    TH2F* h_mT2J_1j_MM;
    TH2F* h_mT2J_2j_MM;
      

    TH2F* h_mjj_1j_MM;
    TH2F* h_mjj_2j_MM;
	
    TH2F* h_DeltaPhiMETll_1j_MM;
    TH2F* h_DeltaPhiMETll_2j_MM;
	
    TH2F* h_DeltaPhill_1j_MM;
    TH2F* h_DeltaPhill_2j_MM;
      
    TH2F* h_NBJets_1j_MM;
    TH2F* h_NBJets_2j_MM;
      
    TH2F* h_NCJets_1j_MM;
    TH2F* h_NCJets_2j_MM;
      
    TH2F* h_NFJets_1j_MM;
    TH2F* h_NFJets_2j_MM;
      
    TH2F* h_DeltaPhijj_1j_MM;
    TH2F* h_DeltaPhijj_2j_MM;
      
    TH2F* h_pTjj_1j_MM;
    TH2F* h_pTjj_2j_MM;
      
    TH2F* h_pTll_1j_MM;
    TH2F* h_pTll_2j_MM;
      
    TH2F* h_DeltaPhiMETl0_1j_MM;
    TH2F* h_DeltaPhiMETl0_2j_MM;
      
    TH2F* h_DeltaPhiMETl1_1j_MM;
    TH2F* h_DeltaPhiMETl1_2j_MM;
	
    TH2F* h_DeltaPhiMETj0_1j_MM;
    TH2F* h_DeltaPhiMETj0_2j_MM;
      
    TH2F* h_DeltaPhiMETj1_1j_MM;
    TH2F* h_DeltaPhiMETj1_2j_MM;
      
    TH2F* h_DeltaPhiMETjj_1j_MM;
    TH2F* h_DeltaPhiMETjj_2j_MM;
	
    TH2F* h_DeltaRjj_1j_MM;
    TH2F* h_DeltaRjj_2j_MM;
      
    TH2F* h_etal0_1j_MM;
    TH2F* h_etal0_2j_MM;
	
    TH2F* h_etal1_1j_MM;
    TH2F* h_etal1_2j_MM;
	
    TH2F* h_etaj0_1j_MM;
    TH2F* h_etaj0_2j_MM;
	
    TH2F* h_etaj1_1j_MM;
    TH2F* h_etaj1_2j_MM;
      
    TH2F* h_mTl0MET_1j_MM;
    TH2F* h_mTl0MET_2j_MM;
      
    TH2F* h_mTl1MET_1j_MM;
    TH2F* h_mTl1MET_2j_MM;
	  
    TH2F* h_DeltaPhilljj_1j_MM;
    TH2F* h_DeltaPhilljj_2j_MM;
	
    TH2F* h_DeltaPhil0jj_1j_MM;
    TH2F* h_DeltaPhil0jj_2j_MM;
      
    TH2F* h_DeltaPhil1jj_1j_MM;
    TH2F* h_DeltaPhil1jj_2j_MM;
      
    TH2F* h_DeltaRlljj_1j_MM;
    TH2F* h_DeltaRlljj_2j_MM;
	
    TH2F* h_DeltaEtajj_1j_MM;
    TH2F* h_DeltaEtajj_2j_MM;
      
    TH2F* h_DeltaEtall_1j_MM;
    TH2F* h_DeltaEtall_2j_MM;
      
    TH2F* h_mTll_1j_MM;
    TH2F* h_mTll_2j_MM;
      
    TH2F* h_mMETll_1j_MM;
    TH2F* h_mMETll_2j_MM;
      
    TH2F* h_DeltaYjj_1j_MM;
    TH2F* h_DeltaYjj_2j_MM;
    
    TH2F* h_mljj_1j_MM;
    TH2F* h_mljj_2j_MM;
    
    TH2F* h_mlj_1j_MM;
    TH2F* h_mlj_2j_MM;
    //=======================================================
    
    
   TH2F* h_pTl0_1j_EM;
    TH2F* h_pTl0_2j_EM;

    TH2F* h_pTl1_1j_EM;
    TH2F* h_pTl1_2j_EM;

    TH2F* h_DeltaRLeptons_1j_EM;
    TH2F* h_DeltaRLeptons_2j_EM;
      
    TH2F* h_pTj0_1j_EM;
    TH2F* h_pTj0_2j_EM;
      

    TH2F* h_pTj1_1j_EM;
    TH2F* h_pTj1_2j_EM;
      

    TH2F* h_mll_1j_EM;
    TH2F* h_mll_2j_EM;


    TH2F* h_METrel_1j_EM;
    TH2F* h_METrel_2j_EM;
      
    TH2F* h_MET_1j_EM;
    TH2F* h_MET_2j_EM;
      
    TH2F* h_HT_1j_EM;
    TH2F* h_HT_2j_EM;
      
    TH2F* h_mWWt_1j_EM;
    TH2F* h_mWWt_2j_EM;

    TH2F* h_mTlmin_1j_EM;
    TH2F* h_mTlmin_2j_EM;
      
    TH2F* h_mTlmax_1j_EM;
    TH2F* h_mTlmax_2j_EM;
      
    TH2F* h_meff_1j_EM;
    TH2F* h_meff_2j_EM;
      
    TH2F* h_mT2_1j_EM;
    TH2F* h_mT2_2j_EM;
      

    TH2F* h_mT2J_1j_EM;
    TH2F* h_mT2J_2j_EM;
      

    TH2F* h_mjj_1j_EM;
    TH2F* h_mjj_2j_EM;
	
    TH2F* h_DeltaPhiMETll_1j_EM;
    TH2F* h_DeltaPhiMETll_2j_EM;
	
    TH2F* h_DeltaPhill_1j_EM;
    TH2F* h_DeltaPhill_2j_EM;
      
    TH2F* h_NBJets_1j_EM;
    TH2F* h_NBJets_2j_EM;
      
    TH2F* h_NCJets_1j_EM;
    TH2F* h_NCJets_2j_EM;
      
    TH2F* h_NFJets_1j_EM;
    TH2F* h_NFJets_2j_EM;
      
    TH2F* h_DeltaPhijj_1j_EM;
    TH2F* h_DeltaPhijj_2j_EM;
      
    TH2F* h_pTjj_1j_EM;
    TH2F* h_pTjj_2j_EM;
      
    TH2F* h_pTll_1j_EM;
    TH2F* h_pTll_2j_EM;
      
    TH2F* h_DeltaPhiMETl0_1j_EM;
    TH2F* h_DeltaPhiMETl0_2j_EM;
      
    TH2F* h_DeltaPhiMETl1_1j_EM;
    TH2F* h_DeltaPhiMETl1_2j_EM;
	
    TH2F* h_DeltaPhiMETj0_1j_EM;
    TH2F* h_DeltaPhiMETj0_2j_EM;
      
    TH2F* h_DeltaPhiMETj1_1j_EM;
    TH2F* h_DeltaPhiMETj1_2j_EM;
      
    TH2F* h_DeltaPhiMETjj_1j_EM;
    TH2F* h_DeltaPhiMETjj_2j_EM;
	
    TH2F* h_DeltaRjj_1j_EM;
    TH2F* h_DeltaRjj_2j_EM;
      
    TH2F* h_etal0_1j_EM;
    TH2F* h_etal0_2j_EM;
	
    TH2F* h_etal1_1j_EM;
    TH2F* h_etal1_2j_EM;
	
    TH2F* h_etaj0_1j_EM;
    TH2F* h_etaj0_2j_EM;
	
    TH2F* h_etaj1_1j_EM;
    TH2F* h_etaj1_2j_EM;
      
    TH2F* h_mTl0MET_1j_EM;
    TH2F* h_mTl0MET_2j_EM;
      
    TH2F* h_mTl1MET_1j_EM;
    TH2F* h_mTl1MET_2j_EM;
	  
    TH2F* h_DeltaPhilljj_1j_EM;
    TH2F* h_DeltaPhilljj_2j_EM;
	
    TH2F* h_DeltaPhil0jj_1j_EM;
    TH2F* h_DeltaPhil0jj_2j_EM;
      
    TH2F* h_DeltaPhil1jj_1j_EM;
    TH2F* h_DeltaPhil1jj_2j_EM;
      
    TH2F* h_DeltaRlljj_1j_EM;
    TH2F* h_DeltaRlljj_2j_EM;
	
    TH2F* h_DeltaEtajj_1j_EM;
    TH2F* h_DeltaEtajj_2j_EM;
      
    TH2F* h_DeltaEtall_1j_EM;
    TH2F* h_DeltaEtall_2j_EM;
      
    TH2F* h_mTll_1j_EM;
    TH2F* h_mTll_2j_EM;
      
    TH2F* h_mMETll_1j_EM;
    TH2F* h_mMETll_2j_EM;
      
    TH2F* h_DeltaYjj_1j_EM;
    TH2F* h_DeltaYjj_2j_EM;
    
    TH2F* h_mljj_1j_EM;
    TH2F* h_mljj_2j_EM;
    
    TH2F* h_mlj_1j_EM;
    TH2F* h_mlj_2j_EM;    
    
   TTree *fChain; //!pointer to the analyzed TTree or TChain
   
    EventParameters* m_eventParameters;
    FourMom *m_l0, *m_l1, *m_met;
    vector<FourMom> *m_jets;
    vector<FourMom> *m_lepts;
    TBranch* m_eventParameters_b;
    TBranch *m_l0_b, *m_l1_b, *m_met_b, *m_jets_b, *m_lepts_b;
    


   SusySel(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~SusySel() { }
   virtual Int_t Version() const { return 2; }
   virtual void Begin(TTree *tree);
   virtual void SlaveBegin(TTree *tree);
   virtual void Init(TTree *tree);
   virtual Bool_t Notify();
   virtual Bool_t Process(Long64_t entry);
// virtual Int_t GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void SetOption(const char *option) { fOption = option; }
   virtual void SetObject(TObject *obj) { fObject = obj; }
   virtual void SetInputList(TList *input) { fInput = input; }
   virtual TList *GetOutputList() const { return fOutput; }
   virtual void SlaveTerminate();
   virtual void Terminate();
   
   string fourMom2str(const FourMom* fm);
   bool defineHistos();
   
   void fillHistos_1j_EE(int cutnumber, float weight);
   void fillHistos_2j_EE(int cutnumber, float weight);
   void fillHistos_1j_MM(int cutnumber, float weight);
   void fillHistos_2j_MM(int cutnumber, float weight);
   void fillHistos_1j_EM(int cutnumber, float weight);
   void fillHistos_2j_EM(int cutnumber, float weight);
   
   bool writeHistos();
   
   void calc_MM_variables(TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, vector<FourMom> signalJets, vector<FourMom> m_leptons);
   void calc_EE_variables(TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, vector<FourMom> signalJets, vector<FourMom> m_leptons);
   void calc_EM_variables(TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, vector<FourMom> signalJets, vector<FourMom> m_leptons);
   
   float calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, vector<FourMom> signalJets);
   float recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, vector<FourMom> signalJets);
   float calcMt(TLorentzVector _l, TLorentzVector _nu);
   float calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, vector<FourMom> signalJets);
   float calc_Ml_3rdl(TLorentzVector l0_TLV, TLorentzVector l1_TLV, vector<FourMom> m_leptons);
   float calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1);
   

   ClassDef(SusySel,0);
   
   int sample_identifier;
   
   //#####################################
   bool l0IsMu;
   bool l1IsMu;
    
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
    float mass_3rdlepZ_MM;
    
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
    float mass_3rdlepZ_EE;
    
    
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
    float mass_3rdlepZ_EM;
protected:
  chargeFlip m_chargeFlip;
};

#endif

Bool_t SusySel::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}
