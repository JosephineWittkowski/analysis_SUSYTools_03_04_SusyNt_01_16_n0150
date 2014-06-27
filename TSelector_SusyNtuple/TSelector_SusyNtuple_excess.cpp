#include <iomanip>
#include "TCanvas.h"
#include "TFile.h"
#include "TChainElement.h"

#include "TSelector_SusyNtuple_excess.hpp"
#include "histos_WH_analysis_excess.C"
#include <string>
#include <strstream>
using namespace std;
using namespace Susy;
// using FourMom;

/*--------------------------------------------------------------------------------*/
// TSelector_SusyNtuple_excess Constructor
/*--------------------------------------------------------------------------------*/
TSelector_SusyNtuple_excess::TSelector_SusyNtuple_excess() :
        m_selectB (false),
        m_vetoB (false),
        m_selectSFOS(false),
        m_vetoSFOS (false),
	file_(0),
	tree_(0),
        m_writeOut (false)
{
  setAnaType(Ana_2LepWH);
  

  if(m_writeOut) {
    out.open("event.dump");
  }
}

/*--------------------------------------------------------------------------------*/
// The Begin() function is called at the start of the query.
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_excess::Begin(TTree * /*tree*/)
{

  n0150BugFix = true;
  TString option = GetOption();
  SysSetting = NtSys_NOM;
  SysSettingBTag = BTag_NOM;
  qflipSysUncertType = 0;
  SFUncertType = 0;
  SysSettingFake = SusyMatrixMethod::SYS_NONE;
  SysSettingPileup = MCWeighter::Sys_NOM;
  isys = 0;
  if(option.Contains("NtSys_NOM"              ) ){SysSetting = NtSys_NOM;                                isys = 0 ; }
  else if(option.Contains("NtSys_EES_Z_UP"    ) ){SysSetting = NtSys_EES_Z_UP;                           isys = 1 ; }
  else if(option.Contains("NtSys_EES_Z_DN"    ) ){SysSetting = NtSys_EES_Z_DN;                           isys = 2 ; }
  else if(option.Contains("NtSys_EES_MAT_UP"  ) ){SysSetting = NtSys_EES_MAT_UP;                         isys = 3 ; }
  else if(option.Contains("NtSys_EES_MAT_DN"  ) ){SysSetting = NtSys_EES_MAT_DN;                         isys = 4 ; }
  else if(option.Contains("NtSys_EES_PS_UP"   ) ){SysSetting = NtSys_EES_PS_UP;                          isys = 5 ; }
  else if(option.Contains("NtSys_EES_PS_DN"   ) ){SysSetting = NtSys_EES_PS_DN;                          isys = 6 ; }
  else if(option.Contains("NtSys_EES_LOW_UP"  ) ){SysSetting = NtSys_EES_LOW_UP;                         isys = 7 ; }
  else if(option.Contains("NtSys_EES_LOW_DN"  ) ){SysSetting = NtSys_EES_LOW_DN;                         isys = 8 ; }
  else if(option.Contains("NtSys_EER_UP"      ) ){SysSetting = NtSys_EER_UP;                             isys = 9 ; }
  else if(option.Contains("NtSys_EER_DN"      ) ){SysSetting = NtSys_EER_DN;                             isys = 10; }
  else if(option.Contains("NtSys_MS_UP"       ) ){SysSetting = NtSys_MS_UP;                              isys = 11; }
  else if(option.Contains("NtSys_MS_DN"       ) ){SysSetting = NtSys_MS_DN;                              isys = 12; }
  else if(option.Contains("NtSys_ID_UP"       ) ){SysSetting = NtSys_ID_UP;                              isys = 13; }
  else if(option.Contains("NtSys_ID_DN"       ) ){SysSetting = NtSys_ID_DN;                              isys = 14; }
  else if(option.Contains("NtSys_JES_UP"      ) ){SysSetting = NtSys_JES_UP;                             isys = 15; }
  else if(option.Contains("NtSys_JES_DN"      ) ){SysSetting = NtSys_JES_DN;                             isys = 16; }
  else if(option.Contains("NtSys_JER"	      ) ){SysSetting = NtSys_JER;                                isys = 17; }
  else if(option.Contains("NtSys_SCALEST_UP"  ) ){SysSetting = NtSys_SCALEST_UP;                         isys = 18; }
  else if(option.Contains("NtSys_SCALEST_DN"  ) ){SysSetting = NtSys_SCALEST_DN;                         isys = 19; }
  else if(option.Contains("NtSys_RESOST"      ) ){SysSetting = NtSys_RESOST;                             isys = 20; }
  else if(option.Contains("NtSys_TRIGSF_EL_UP") ){SysSetting = NtSys_TRIGSF_EL_UP;                       isys = 21; }
  else if(option.Contains("NtSys_TRIGSF_EL_DN") ){SysSetting = NtSys_TRIGSF_EL_DN;                       isys = 22; }
  else if(option.Contains("NtSys_TRIGSF_MU_UP") ){SysSetting = NtSys_TRIGSF_MU_UP;                       isys = 23; }
  else if(option.Contains("NtSys_TRIGSF_MU_DN") ){SysSetting = NtSys_TRIGSF_MU_DN;                       isys = 24; }
  else if(option.Contains("NtSys_TES_UP"      ) ){SysSetting = NtSys_TES_UP;                             isys = 25; }
  else if(option.Contains("NtSys_TES_DN"      ) ){SysSetting = NtSys_TES_DN;                             isys = 26; }
  
  else if(option.Contains("BTag_BJet_DN"      ) ) {SysSettingBTag = BTag_BJet_DN;                        isys = 27; }
  else if(option.Contains("BTag_CJet_DN"      ) ) {SysSettingBTag = BTag_CJet_DN;                        isys = 28; }
  else if(option.Contains("BTag_LJet_DN"      ) ) {SysSettingBTag = BTag_LJet_DN;                        isys = 29; }
  else if(option.Contains("BTag_BJet_UP"      ) ) {SysSettingBTag = BTag_BJet_UP;                        isys = 30; }
  else if(option.Contains("BTag_CJet_UP"      ) ) {SysSettingBTag = BTag_CJet_UP;                        isys = 31; }
  else if(option.Contains("BTag_LJet_UP"      ) ) {SysSettingBTag = BTag_LJet_UP;                        isys = 32; }
  else if(option.Contains("BKGMETHOD_UP"      ) ) {qflipSysUncertType = 1;                               isys = 33; }
  else if(option.Contains("BKGMETHOD_DN"      ) ) {qflipSysUncertType = -1;                              isys = 34; }
  else if(option.Contains("SYS_EL_RE_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_RE_UP  ;    isys = 35; }
  else if(option.Contains("SYS_EL_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_RE_DOWN;    isys = 36; }
  else if(option.Contains("SYS_EL_FR_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_FR_UP  ;    isys = 37; }
  else if(option.Contains("SYS_EL_FR_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_FR_DOWN;    isys = 38; }
  else if(option.Contains("SYS_MU_RE_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_UP  ;    isys = 39; }
  else if(option.Contains("SYS_MU_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_DOWN;    isys = 40; }
  else if(option.Contains("SYS_MU_FR_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_FR_UP  ;    isys = 41; }
  else if(option.Contains("SYS_MU_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_DOWN;    isys = 42; }
  else if(option.Contains("el_eff_up"         ) ) {SFUncertType = 1;                                     isys = 43; }
  else if(option.Contains("el_eff_dn"         ) ) {SFUncertType = 2;                                     isys = 44; }
  else if(option.Contains("mu_eff_up"         ) ) {SFUncertType = 3;                                     isys = 45; }
  else if(option.Contains("mu_eff_dn"         ) ) {SFUncertType = 4;                                     isys = 46; }
  else if(option.Contains("Sys_PILEUP_UP"     ) ) {SysSettingPileup = MCWeighter::Sys_PILEUP_UP;         isys = 47; }
  else if(option.Contains("Sys_PILEUP_DN"     ) ) {SysSettingPileup = MCWeighter::Sys_PILEUP_DN;         isys = 48; }  
  
  
  cout << "SysSettingBTag= " << SysSettingBTag << " SysSetting= " << SysSetting << " isys= " << isys << endl;

}
void TSelector_SusyNtuple_excess::SlaveBegin(TTree* /*tree*/)
{
  
  calcSysUncert = false;
  makeNTuple = false;
//   defineHistos();
  defineHistos_Excess();
  if(calcSysUncert) defineHistos_sysUncert();


  SusyNtAna::Begin(0);
//   m_susyObj.initialize(nt.evt()->isMC);

  

  setSelectTaus(true);
  setDoIP(true);

  m_trigObjWithoutRU = new DilTrigLogic("Moriond",false/*No Reweight Utils!*/);
  
  cout << "initialize chargeFlip tool" << endl;
  
  m_chargeFlip.initialize("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/ChargeFlip/data/d0_new2d_chargeflip_map.root");
  
//   m_matrix = new SusyMatrixMethod::DiLeptonMatrixMethod();
//   m_matrix->configure("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SusyMatrixMethod/data/FinalFakeHist_Feb_02.root", SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT);
  if(makeNTuple) initTupleMaker("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SusySel_Egamma_6_NEW.root", "SusySel");
//   string xsecFileName  = gSystem->ExpandPathName("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SUSYTools/data/susy_crosssections_8TeV.txt");
  m_susyXsec = new SUSY::CrossSectionDB("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SUSYTools/data/mc12_8TeV/Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA.txt");
  
}



Bool_t TSelector_SusyNtuple_excess::Process(Long64_t entry)
{
  
  
  GetEntry(entry); //function from SusyNtAna.h
  
  clearObjects(); //function from SusyNtAna.cxx

  
  m_chainEntry++;
  

  unsigned int mcid;
//   cout << "nt.evt()->mcChannel= " << nt.evt()->mcChannel << endl;
  if(nt.evt()->isMC){
    mcid = nt.evt()->mcChannel;
//     cout << "mcid= " <<mcid << endl;
    calcFakeContribution = false;
  }
  else{
    mcid = 111111;
    calcFakeContribution = false;
  }
  m_kIsData = !nt.evt()->isMC;
  
  if(m_chainEntry==0){
    sample_identifier = mcid;

    if(m_kIsData){
    cout << " DATA DATA DATA DATA DATA DATA" << endl;
  }
    else cout << "MC MC MC MC MC MC MC MC" << endl;
    cout << "sample_identifier= " << sample_identifier << endl;
    cout << "nt.evt()->event= " << nt.evt()->event << endl;
    
    cout << "sample_identifier= " << sample_identifier << endl;
    
    
  }
  
  
  if(m_dbg || m_chainEntry%50000==0)
  {
    
    float recalc_sumw = 0.;
//     SumwMapKey genKey(mcid, 0);
//     map<unsigned int, float>::const_iterator sumwMapIter = m_sumwMap.find(genKey);
//     if(sumwMapIter != m_sumwMap.end()) recalc_sumw = sumwMapIter->second;

    cout << "**** Processing entry " << setw(6) << m_chainEntry << " run " << setw(6) << nt.evt()->run << " event " << setw(7) << nt.evt()->event << " sumw= " << nt.evt()->sumw << "   ****" << endl;
  }
  bool isExcessEvent = false;
  if(nt.evt()->event ==16911462 || nt.evt()->event == 9869172 || nt.evt()->event == 90209948 || nt.evt()->event == 44101707 || nt.evt()->event == 117557501 || nt.evt()->event == 1103610 || nt.evt()->event == 19507114 || nt.evt()->event == 16891699 || nt.evt()->event == 175112743 || nt.evt()->event == 17624087 || nt.evt()->event == 95409590 || nt.evt()->event == 43055624 || nt.evt()->event == 105712791 || nt.evt()->event == 17764246 || nt.evt()->event == 18079037 || nt.evt()->event == 46843774 || nt.evt()->event == 13140670 || nt.evt()->event == 88663093 || nt.evt()->event == 31715223 || nt.evt()->event == 140956299 || nt.evt()->event == 105514195 || nt.evt()->event == 23951846 || nt.evt()->event == 15237392 || nt.evt()->event == 27328480 || nt.evt()->event == 18676984 || nt.evt()->event == 101746521 || nt.evt()->event == 86630524 || nt.evt()->event == 5083691 || nt.evt()->event == 17417168 || nt.evt()->event == 53659423 || nt.evt()->event == 32677037 || nt.evt()->event == 22743905 || nt.evt()->event == 
68299036 || nt.evt()->event == 144333969 || nt.evt()->event == 78170346 || nt.evt()->event == 148644297 || nt.evt()->event == 65663218 || nt.evt()->event == 134754777 || nt.evt()->event == 115410729 || nt.evt()->event == 108569279 || nt.evt()->event == 125086405 || nt.evt()->event == 48263677 || nt.evt()->event == 143625474 || nt.evt()->event == 36625640 || nt.evt()->event == 20486044 || nt.evt()->event == 57334605 || nt.evt()->event == 73750293 || nt.evt()->event == 81502188 || nt.evt()->event == 116622329 || nt.evt()->event == 95528417 || nt.evt()->event == 22611790 || nt.evt()->event == 162105581 || nt.evt()->event == 216302484 || nt.evt()->event == 230250333 || nt.evt()->event == 107348561 || nt.evt()->event == 24557188 || nt.evt()->event == 89284315 || nt.evt()->event == 89921988 || nt.evt()->event == 75684998 || nt.evt()->event == 49790922 || nt.evt()->event == 181428723 || nt.evt()->event == 72456843 || nt.evt()->event == 57104481 || nt.evt()->event == 204010717 || nt.evt()->event == 211601840 || nt.
evt()->event == 138647084 || nt.evt()->event == 49832278 || nt.evt()->event == 128055658 || nt.evt()->event == 8638926){
    isExcessEvent = true;
  }



  // charge flip background contribution in SS channels: for the e^pm e^pm and e^pm mu^pm channels, processes that are opposite-sign in truth but where one electron has undergone a “charge flip”. Contributions from WW, ttbar, Z/gamma* and single top are via charge-flip
  // In previous analysis, it has been observed that the charge flip rate in data is lower than that in the simulation by about 20%. Because of this disagreement, the electron charge flip rate is measured in data as a function of |eta| and combined with the smaller dependence on pT taken from simulation.
    

  //select Leptons, Jets, ... automatically with SusyNt methods:
  clearObjects();
  selectObjects(SysSetting, false, TauID_medium, n0150BugFix);

  
  int flag = nt.evt()->cutFlags[SysSetting];  
  float weight_ALL = (nt.evt()->isMC) ? SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap, false, true, SysSettingPileup) : 1.;
  //   if(mcid>= 177501 && mcid <= 177527) 	weight_ALL = weight_ALL/nt.evt()->xsec * m_susyXsec->xsectTimesEff(mcid);
    
    float weight_ALL_EE = weight_ALL;
    float weight_ALL_MM = weight_ALL;
    float weight_ALL_EM = weight_ALL;
  
  //event cleaning doesn't need to be changed after agreement on cutflow:
  if (doEventCleaning_andFillHistos( flag, weight_ALL_EE, weight_ALL_MM, weight_ALL_EM, SysSetting, n0150BugFix)){
  
    //retrieve signal jets as base for many variables:
    Jet* jet0_buff;
    Jet* jet1_buff;
    TLorentzVector signalJet0_buff_TLV, signalJet1_buff_TLV;
    nSignalJets = numberOfCLJets(m_signalJets2Lep);
    if(nSignalJets >=1){
      jet0_buff = m_signalJets2Lep.at(0);

      signalJet0_buff_TLV.SetPtEtaPhiE(jet0_buff->Pt(), jet0_buff->eta, jet0_buff->phi, jet0_buff->Pt()*cosh(jet0_buff->eta));
      signalJet0_buff_TLV.SetPtEtaPhiM(jet0_buff->Pt(), jet0_buff->eta, jet0_buff->phi, jet0_buff->m);
      if(nSignalJets >=2){	
	jet1_buff = m_signalJets2Lep.at(1);
	signalJet1_buff_TLV.SetPtEtaPhiE(jet1_buff->Pt(), jet1_buff->eta, jet1_buff->phi, jet1_buff->Pt()*cosh(jet1_buff->eta));
	signalJet1_buff_TLV.SetPtEtaPhiM(jet1_buff->Pt(), jet1_buff->eta, jet1_buff->phi, jet1_buff->m);
	
      }
    }
    Jet* jet0;
    Jet* jet1;
    TLorentzVector signalJet0_TLV, signalJet1_TLV;
    jet0 = jet0_buff;
    signalJet0_TLV = signalJet0_buff_TLV;
    if(nSignalJets >=2){	
      jet0 = (jet0_buff->Pt() > jet1_buff->Pt()) ? jet0_buff : jet1_buff;
      jet1 = (jet0_buff->Pt() > jet1_buff->Pt()) ? jet1_buff : jet0_buff;
      signalJet1_TLV = (jet0_buff->Pt() > jet1_buff->Pt()) ? signalJet1_buff_TLV : signalJet0_buff_TLV;
      signalJet0_TLV = (jet0_buff->Pt() > jet1_buff->Pt()) ? signalJet0_buff_TLV : signalJet1_buff_TLV;
    }
    
  //   from MET, calculate METrel
  //   Met met = m_met;
    bool useForwardJets = true;
    float METrel = getMetRel(m_met, m_signalLeptons, m_signalJets2Lep, useForwardJets);

    float cutnumber;
  //   if(m_signalLeptons.size()>1){
  //     double weight= SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap);
  //     unsigned int run(nt.evt()->run), event(nt.evt()->event);
  //     LeptonVector anyLep(getAnyElOrMu(nt));
  //     LeptonVector lowPtLep(subtract_vector(anyLep, m_baseLeptons)); // caveat: spurious sigLep dupl.
  //     const Lepton *l0 = m_signalLeptons[0];
  //     const Lepton *l1 = m_signalLeptons[1];
  //     if(makeNTuple) fillTupleMaker(weight, run, event, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep);
  //   }
    TauVector preTaus = getPreTaus(&nt, SysSetting);
//     h_NpreTaus->Fill(preTaus.size(), 14, weight_ALL_EE);
  
    
    

    
  //////////////////////////// EM //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if((m_baseElectrons.size()==1 && m_baseMuons.size() ==1)){

    TLorentzVector el_TLV, mu_TLV;
    LeptonVector leptons;
    MuonVector muons;
    ElectronVector electrons;
      
    if(m_signalMuons.size()==1 && m_signalElectrons.size()==1 ){
      leptons = m_signalLeptons;
      muons = m_signalMuons;
      electrons = m_signalElectrons;
    }
    if(calcFakeContribution){
      leptons = m_baseLeptons;
      muons = m_baseMuons;
      electrons = m_baseElectrons;
    }
    if((m_signalMuons.size()==1 && m_signalElectrons.size()==1) || calcFakeContribution){
    Electron* el;
    Muon* mu;
    mu = muons.at(0);
    el = electrons.at(0);
    
    cutnumber = 15.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM); //pass category

      
    if(muons.size() == 1 && electrons.size() == 1 && fabs(mu->Eta())<=2.4){
      el_TLV.SetPtEtaPhiE(el->Pt(), el->eta ,el->phi, el->Pt()*cosh(el->eta));
      el_TLV.SetPtEtaPhiM(el->Pt(), el->eta ,el->phi, el->m);
      mu_TLV.SetPtEtaPhiE(mu->Pt(), mu->eta ,mu->phi, mu->Pt()*cosh(mu->eta));
      mu_TLV.SetPtEtaPhiM(mu->Pt(), mu->eta ,mu->phi, mu->m);
	
      // time to calc weights:
      //------------------------------------------------------------------------------------

      //calc lepton SF:
      float lep_SF_EM = 1.0;
//       if(nt.evt()->isMC) lep_SF_EM = mu->effSF * el->effSF;
      if(nt.evt()->isMC) lep_SF_EM = getLeptonSF(leptons, SFUncertType);
      //calc trigger weight:
      float trigW_EM = 1.;
      if(nt.evt()->isMC) trigW_EM = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->lv().Et(), nSignalJets, nt.evt()->nVtx, SysSetting);
      //product of all weights:
      weight_ALL_EM = (nt.evt()->isMC) ? weight_ALL_EM * lep_SF_EM * trigW_EM: 1;
      weight_ALL_EM *= getBTagWeight(nt.evt(), SysSettingBTag);


	//------------------------------------------------------------------------------------      
// 	h_NpreTaus->Fill(preTaus.size(), 17, weight_ALL_EM);
	cutnumber = 16.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM); //pass nlep
      
	if(m_signalTaus.size() == 0){
	  cutnumber = 17.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	  int cutnumber_Ex = -1.;
	  cutnumber_Ex = 7.; fillExcessHistos_1j(el, el_TLV, mu, mu_TLV, m_signalLeptons.at(0), m_signalLeptons.at(1), cutnumber_Ex);
	  cutnumber_Ex = 7.; fillExcessHistos_2j(el, el_TLV, mu, mu_TLV, m_signalLeptons.at(0), m_signalLeptons.at(1), cutnumber_Ex);
	  int cutnumber_Ex_j0 = -1;
	  cutnumber_Ex_j0 = 7.; fillExcessHistos_0j(el, el_TLV, mu, mu_TLV, m_signalLeptons.at(0), m_signalLeptons.at(1), cutnumber_Ex);
	  if(m_trigObjWithoutRU->passDilEvtTrig(leptons, m_met->Et, nt.evt())){ //valid pT region)
	    cutnumber = 18.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	    

	    if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){ //match to trigger
	      
	      cutnumber = 19.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	      
	      if(!nt.evt()->isMC || CheckRealLeptons(electrons, muons)){	      
		cutnumber = 20.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
		
		//calc charge flip weights:
		//Note that the charge flip is only applied in SS region (ee or em) and only for MC events that are true OS.
		//The charge flip changes both the lepton pt of the electron that charge flip and the change needs to be propagated to the met.
		float chargeFlipWeight = 1.0;	
		//make a copy of electrons and MET which will eventually be changed by ChargeFlip tool:
		Electron* el_SS;
		el_SS = electrons.at(0);
		ElectronVector electrons_SS;
		electrons_SS = electrons;
		TLorentzVector el_SS_TLV(*el_SS);
	    //     TLorentzVector el_SS_TLV;
	    //     el_SS_TLV.SetPtEtaPhiE(el_SS->Pt(), el_SS->eta ,el_SS->phi, el_SS->Pt()*cosh(el_SS->eta));
	    //     el_SS_TLV.SetPtEtaPhiM(el_SS->Pt(), el_SS->eta ,el_SS->phi, el_SS->m);

		TLorentzVector met_SS_TLV;
		TVector2 met_SS_TVector2;
		met_SS_TLV = m_met->lv();
		met_SS_TVector2.Set(met_SS_TLV.Px(), met_SS_TLV.Py());

		int pdg0 = 11 * (-1) * el->q; // Remember 11 = elec which has charge -1
		TLorentzVector empty_TLV;

		if(el->q*mu->q<0 && nt.evt()->isMC){
// 		  m_chargeFlip.setSeed(nt.evt()->event);
		  chargeFlip::eStatus map2use = chargeFlip::dataonly;
		  chargeFlipWeight = m_chargeFlip.OS2SS(pdg0, &el_SS_TLV, 13, &empty_TLV, qflipSysUncertType, map2use);
		  chargeFlipWeight*= m_chargeFlip.overlapFrac().first;
		  el_SS->pt = el_SS_TLV.Pt(); el_SS->resetTLV();
		  //get changed MET and fill in TLorentzVector:
		  met_SS_TLV.SetPx(met_SS_TVector2.Px());
		  met_SS_TLV.SetPy(met_SS_TVector2.Py());	
		  met_SS_TLV.SetE(sqrt(pow(met_SS_TVector2.Px(),2) + pow(met_SS_TVector2.Py(),2)));
		}
		float weight_ALL_SS_EM = weight_ALL_EM * chargeFlipWeight;
		float METrel_SS = recalcMetRel(met_SS_TLV, el_SS_TLV, mu_TLV, m_signalJets2Lep, useForwardJets);
		
		calc_EM_variables(leptons, el, mu, mu_TLV, el_SS_TLV, met_SS_TLV, signalJet0_TLV, signalJet1_TLV, useForwardJets, &nt, weight_ALL_SS_EM, SysSetting, n0150BugFix);
		calcJet_variables(met_SS_TLV);
		
		// only meaningful in SS SR:
		if(!nt.evt()->isMC && calcFakeContribution){
		  susy::fake::Region MatrixMethodRegion;
		  if(nSignalJets ==1) MatrixMethodRegion = susy::fake::CR_SRWH1j;
		  if(nSignalJets >=2 && nSignalJets <=3) MatrixMethodRegion = susy::fake::CR_SRWH2j;
		  weight_ALL_EM = getFakeWeight(m_baseLeptons, MatrixMethodRegion, METrel_SS, SysSettingFake);
		  weight_ALL_SS_EM = weight_ALL_EM;
		}



  //------------------------------------------------------------------------------------
  //----------------------------------SR-SS1-EM------------------------------------------
  //------------------------------------------------------------------------------------
		if(nt.evt()->isMC || (!nt.evt()->isMC && (el->q*mu->q)>0)){
		  const Lepton *l0 = m_signalLeptons[0];
		  const Lepton *l1 = m_signalLeptons[1];

  // 	      if(nt.evt()->event == 859255 || nt.evt()->event == 1181870){
  // 		cout << "EM " << nt.evt()->event <<
  // 		" total w= " << weight_ALL_SS_EM
  // 		<< " SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)= " << SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)
  // 		<< " lep_SF_EM= " << lep_SF_EM 
  // 		<< " trigW_EM= " << trigW_EM 
  // 		<< " btag= " << getBTagWeight(nt.evt(), SysSettingBTag)
  // 		<< " chargeFlipWeight= " << chargeFlipWeight << endl;
  // 	      }
		  cutnumber = 21.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM); //SS cut: applied only on weighted events
		  if((mllZcandImpact_mu_EM > MZ+20. || mllZcandImpact_mu_EM < MZ-20.) && (mllZcandImpact_el_EM > MZ+20. || mllZcandImpact_el_EM < MZ-20.)){
		    cutnumber = 22.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
// 		    int cutnumber_Ex = -1.;
		    cutnumber_Ex = 0.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
		    cutnumber_Ex = 0.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      cutnumber = 23.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
		      cutnumber_Ex = 1.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
		      cutnumber_Ex = 1.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);		      
		      
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 24.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			cutnumber_Ex = 2.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			cutnumber_Ex = 2.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			//------------------------------------------------------------------------------------
			if(nSignalJets ==0){
// 			  int cutnumber_Ex_j0 = -1;
			  cutnumber_Ex_j0 = 1.; fillExcessHistos_0j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			  if((mu_TLV.Pt() > el_SS_TLV.Pt() && mu_TLV.Pt() > 30 && el_SS_TLV.Pt() < 30) || (mu_TLV.Pt() < el_SS_TLV.Pt() && mu_TLV.Pt() < 30 && el_SS_TLV.Pt() > 30)) {
			    cutnumber_Ex_j0 = 2.; fillExcessHistos_0j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);

			    if(Mlj_1j_EM > 90.){
			      cutnumber_Ex_j0 = 3.; fillExcessHistos_0j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			  
			      
			      if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
				cout << "EM 1j is excess event by |eta(l0)| " << nt.evt()->event << endl;	
				
			      }
			      if(isExcessEvent) cout << "EM 1j excess event Davide " << nt.evt()->event << endl;
				
			    }
			  }
			}//end ==0jet
			//------------------------------------------------------------------------------------
			//------------------------------------------------------------------------------------
			if(nSignalJets >=1){
			cutnumber_Ex = 3.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			cutnumber_Ex = 3.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			  
			//------------------------------------------------------------------------------------
			if(nSignalJets ==1){
			  
			  cutnumber = 25.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			  cutnumber_Ex = 4.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			  if((mu_TLV.Pt() > el_SS_TLV.Pt() && mu_TLV.Pt() > 30 && el_SS_TLV.Pt() < 30) || (mu_TLV.Pt() < el_SS_TLV.Pt() && mu_TLV.Pt() < 30 && el_SS_TLV.Pt() > 30)) {
			    cutnumber = 42.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    cutnumber_Ex = 5.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);

			    if(Mlj_1j_EM > 90.){
			      cutnumber = 43.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			      cutnumber_Ex = 6.; fillExcessHistos_1j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			      
			      if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
				cout << "EM 1j is excess event by |eta(l0)| " << nt.evt()->event << endl;	
				
			      }
			      if(isExcessEvent) cout << "EM 1j excess event Davide " << nt.evt()->event << endl;
				
			    }
			  }
			}//end ==1jet
		  //------------------------------------------------------------------------------------
			if(nSignalJets >=2/* && nSignalJets <=3*/){
			  cutnumber = 34.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			  cutnumber_Ex = 4.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			  if((mu_TLV.Pt() > el_SS_TLV.Pt() && mu_TLV.Pt() > 30 && el_SS_TLV.Pt() < 30) || (mu_TLV.Pt() < el_SS_TLV.Pt() && mu_TLV.Pt() < 30 && el_SS_TLV.Pt() > 30)) {

			    cutnumber = 44.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    cutnumber_Ex = 5.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			    if(Mlj_2j_EM > 120.){
			      cutnumber = 45.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			      cutnumber_Ex = 6.; fillExcessHistos_2j(el_SS, el_SS_TLV, mu, mu_TLV, l0, l1, cutnumber_Ex);
			      if(isExcessEvent) cout << "EM 2j excess event Davide " << nt.evt()->event << endl;
				
			      //USE all |eta|>1.8 events
			      
			      if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
				cout << "EM 2j is excess event by |eta(l0)| " << nt.evt()->event << endl;	
				
			      }
			      

			      cout << "el pt " << el_SS_TLV.Pt() << " eta " << el_SS_TLV.Eta() << " phi " << el_SS_TLV.Phi() << endl;
			      cout << "mu pt " << mu_TLV.Pt() << " eta " << mu_TLV.Eta() << " phi " << mu_TLV.Phi() << endl;
			      cout << "j  pt " << m_signalJets2Lep.at(0)->Pt() << " eta " << m_signalJets2Lep.at(0)->Eta() << " phi " << m_signalJets2Lep.at(0)->Phi() << endl;				
			      if(!isExcessEvent){
				cout << "!isExcessEvent l0 pt " << l0->Pt() << " l1 pt " << l1->Pt() << endl;
				cout << "ele pt " << el_SS_TLV.Pt() << " eta " << el_SS_TLV.Eta() << " phi " << el_SS_TLV.Phi() << endl;
				cout << "mu pt " << mu_TLV.Pt() << " eta " << mu_TLV.Eta() << " phi " << mu_TLV.Phi() << endl;
			      }			      
				
			    }
				
			  }
			}//end >=2 jets
		  //------------------------------------------------------------------------------------
		      }//end >=1 jets
		    }
		  }
		}
		  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		    //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		}
	      }
	    }
	  }
	}
      }
    }
  }
}
// }
return kTRUE;

}



/*--------------------------------------------------------------------------------*/
// Analysis cuts
/*--------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------*/

bool TSelector_SusyNtuple_excess::CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons){

  for(uint i=0; i<signal_electrons.size(); i++){
    Electron* signal_electron = signal_electrons.at(i);
    if(signal_electron->isChargeFlip) return false;
    if(signal_electron->truthType != RecoTruthMatch::PROMPT) return false;
  }
  
    for(uint i=0; i<signal_muons.size(); i++){
      Muon* signal_muon = signal_muons.at(i);
      if(signal_muon->truthType != RecoTruthMatch::PROMPT) return false;
  }
  
  return true;
  
}

/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::CheckChargeFlipElectrons(const ElectronVector& signal_electrons){
  
  for(uint i=0; i<signal_electrons.size(); i++){
Electron* signal_electron = signal_electrons.at(i);
if(signal_electron->isChargeFlip) return false;
// check if signal electron has no charge flip
  }
  return true;
  
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::getBTagWeight(const Event* evt, BTagSys SysSettingBTag)
{
//   configureBTagTool("0_3511",MV1_80, false);
// if(nt.evt()->event == 859255 || nt.evt()->event == 1181870 || nt.evt()->event == 140871 || nt.evt()->event == 2697245) cout << "jets used for bTagSF(): " << endl;
//   JetVector tempJets;
//   for(uint ij=0; ij<m_baseJets.size(); ++ij){
//     Jet* jet = m_baseJets.at(ij);
//     if( jet->Pt() < JET_PT_L20_CUT        ) continue;
//     if( fabs(jet->detEta) > JET_ETA_CUT_2L ) continue;
//     tempJets.push_back(jet);
// //     if(nt.evt()->event == 859255 || nt.evt()->event == 1181870 || nt.evt()->event == 140871 || nt.evt()->event == 2697245) cout << "jet->Pt()= " << jet->Pt() << endl;
//   }
//   if(nt.evt()->event == 859255 || nt.evt()->event == 1181870 || nt.evt()->event == 140871 || nt.evt()->event == 2697245) cout << "# jets used for bTagSF(): " << tempJets.size() << endl;
  JetVector tempJets = getBTagSFJets2Lep(m_baseJets);
  return bTagSF(evt, tempJets, nt.evt()->mcChannel, SysSettingBTag);
  
  
//   if(valJets.size()==0) return 1;//safety.

// return 0.;
}

//   if(!nt->evt()->isMC) return 1;
//   if(!USE_BWEIGHT)     return 1;
// 
//   JetVector  valJets;
//   valJets.clear();
//   for(uint i=0; i<jets->size(); ++i){
//     Jet* jet = jets->at(i);
//     if( jet->Pt() < JET_PT_L20_CUT        ) continue;
//     if( fabs(jet->detEta) > JET_ETA_CUT_2L ) continue;
//     valJets.push_back(jet);
//   }
//   
//   if(valJets.size()==0) return 1;//safety.
// 
//   //Get sys naming convention
//   uint _sys = DGSys_NOM;
//   if(iSys==DGSys_BJet_DN) _sys=BTag_BJet_DN; 
//   if(iSys==DGSys_CJet_DN) _sys=BTag_CJet_DN; 
//   if(iSys==DGSys_LJet_DN) _sys=BTag_LJet_DN; 
//   if(iSys==DGSys_BJet_UP) _sys=BTag_BJet_UP; 
//   if(iSys==DGSys_CJet_UP) _sys=BTag_CJet_UP; 
//   if(iSys==DGSys_LJet_UP) _sys=BTag_LJet_UP; 
// 
//   return bTagSF(nt->evt(),valJets, nt->evt()->mcChannel, (BTagSys) _sys);
  
  


/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::checkLeptonPt(const LeptonVector& leptons)
{
// cout << "leptons[0]->Pt()= " << leptons[0]->Pt() << " leptons[1]->Pt()= " << leptons[1]->Pt() << endl;
  if(leptons[0]->Pt()>leptons[1]->Pt()){
if(leptons[0]->Pt()>35. && leptons[1]->Pt()>20.) return true;
else return false;
  }
  else{
if(leptons[1]->Pt()>35. && leptons[0]->Pt()>20.) return true;
else return false;
  }
  return true;
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue) // Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/PhysicsTools.cxx#L197
{
float dphi = acos(cos(_ll.Phi()-_nu.Phi()));
float mll = _ll.M();
float mvv=0;
if(!MvvTrue) mvv=mll;

float mT=0;
mT = sqrt( pow(mll,2) + pow(mvv,2)
+ 2*( sqrt(pow(_ll.Pt(),2) + pow(mll,2)) * sqrt(pow(_nu.Pt(),2) + pow(mvv,2))
- _ll.Pt()*_nu.Pt()*cos(dphi) ) );

return mT;

}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, const JetVector &signalJets){
  //Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/ToyNt.cxx#L404
  
  float HT = 0;
  HT += l1.Pt();
  HT += l2.Pt();
  
  for(uint i=0; i<signalJets.size(); i++){
    if(signalJets[i]->Pt() > 20) HT += signalJets[i]->Pt();
  }
  
  HT += met.E();
  return HT;

// ht = Meff(*leptons, *jets, met, JET_PT_CUT); //The function is defined in SusyNtTools.cxx & is the sum pT of leptons, jets and met
// where JET_PT_CUT = 20 (the default in the function uses pt=40)
  
// float SusyNtTools::Meff(const LeptonVector& leps, const JetVector& jets, const Met* met)
// {
// float meff = 0;
// for(uint i=0; i<leps.size(); i++) meff += leps[i]->Pt();
// for(uint i=0; i<jets.size(); i++){
// if(jets[i]->Pt() > 40) meff += jets[i]->Pt();
// }
// meff += met->Et;
// return meff;
// }
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcMeff(TLorentzVector met, const JetVector &signalJets){
  //Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/ToyNt.cxx#L404
  //mEff : same as HT but without the lepton
  float HT = 0;
// HT += l1.Pt();
// HT += l2.Pt();
  
  for(uint i=0; i<signalJets.size(); i++){
    if(signalJets[i]->Pt() > 40) HT += signalJets[i]->Pt();
  }
  
  HT += met.E();
  return HT;

}
/*--------------------------------------------------------------------------------*/

float TSelector_SusyNtuple_excess::calcMt(TLorentzVector _l, TLorentzVector _nu)
{
  float dphi = acos(cos(_l.Phi()-_nu.Phi()));
  return sqrt(2*_l.Pt()*_nu.Pt() * (1- cos(dphi)) );
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const JetVector& jets, bool useForward)
{
  //copied from SusyNtTools.cxx and modified to work with TLorenzVector
  float dPhi = TMath::Pi()/2.;
  
  if( fabs(metLV.DeltaPhi(l1)) < dPhi ) dPhi = fabs(metLV.DeltaPhi(l1));
  if( fabs(metLV.DeltaPhi(l2)) < dPhi ) dPhi = fabs(metLV.DeltaPhi(l2));
  
  for(uint ij=0; ij<jets.size(); ++ij){
    const Jet* jet = jets.at(ij);
    if( !useForward && isForwardJet(jet) ) continue; // Use only central jets
    if( fabs(metLV.DeltaPhi( *jet )) < dPhi ) dPhi = fabs(metLV.DeltaPhi( *jet ));
  }// end loop over jets
  
  return metLV.Et() * sin(dPhi);
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1)
{
  //copied from SusyNtTools.cxx and modified to work with TLorenzVector

  double pTMiss[3] = {0.0, metlv.Px(), metlv.Py()};
  double pA[3] = {0.0, l0.Px(), l0.Py()};
  double pB[3] = {0.0, l1.Px(), l1.Py()};
  
  // Create Mt2 object
  mt2_bisect::mt2 mt2_event;
  mt2_event.set_momenta(pA,pB,pTMiss);
  mt2_event.set_mn(0); // LSP mass = 0 is Generic
  
  return mt2_event.get_mt2();
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1)
{
//   l0 -> l0 + jet_i
//   l1 -> l1 + jet_j
//   minimize for jet

  //copied from SusyNtTools.cxx and modified to work with TLorentzVector
  
  TLorentzVector alpha_a, alpha_b;
  //case 1:
  alpha_a = l0 + j0;
  alpha_b = l1 + j1;

  double pTMiss1[3] = {0.0, metlv.Px(), metlv.Py()};
  double pA1[3] = {alpha_a.M(), alpha_a.Px(), alpha_a.Py()};
  double pB1[3] = {alpha_b.M(), alpha_b.Px(), alpha_b.Py()};
  
  // Create Mt2 object
  mt2_bisect::mt2 mt2_event1;
  mt2_event1.set_momenta(pA1,pB1,pTMiss1);
  mt2_event1.set_mn(0); // LSP mass = 0 is Generic
  
  //case 2:
  alpha_a = l0 + j1;
  alpha_b = l1 + j0;

  double pTMiss2[3] = {0.0, metlv.Px(), metlv.Py()};
  double pA2[3] = {alpha_a.M(), alpha_a.Px(), alpha_a.Py()};
  double pB2[3] = {alpha_b.M(), alpha_b.Px(), alpha_b.Py()};
  
  // Create Mt2 object
  mt2_bisect::mt2 mt2_event2;
  mt2_event2.set_momenta(pA2,pB2,pTMiss2);
  mt2_event2.set_mn(0); // LSP mass = 0 is Generic
  double min_mt2 = min(mt2_event1.get_mt2(), mt2_event2.get_mt2());
  double return_value = (min_mt2 > 0.) ? min_mt2 : -1.;
//   cout << nt.evt()->event << " mt2J= " << return_value << " mt2_event1.get_mt2()= " << mt2_event1.get_mt2() << " mt2_event2.get_mt2()= " << mt2_event2.get_mt2() << endl; 
//   cout << "m_signalLeptons.at(0)->m= " << m_signalLeptons.at(0)->m << " m_signalLeptons.at(1)->m= " << m_signalLeptons.at(1)->m << endl;
//   cout << "before ChargeFlip: m_met->lv().Px()= " << m_met->lv().Px() << " m_met->lv().Py()= " << m_met->lv().Py() << endl;
//   cout << "after ChargeFlip:  metlv.Px()= "<< metlv.Px() << " metlv.Py()= " << metlv.Py() << endl;
//   cout << "l0.Px()= " << l0.Px() << " l0.Py()= " << l0.Py() << " l0.M()= " << l0.M() << endl;
//   cout << "l1.Px()= " << l1.Px() << " l1.Py()= " << l1.Py() << " l1.M()= " << l1.M() << endl;
//   cout << "j0.Px()= " << j0.Px() << " j0.Py()= " << j0.Py() << " j0.M()= " << j0.M() << endl;
//   cout << "j1.Px()= " << j1.Px() << " j1.Py()= " << j1.Py() << " j1.M()= " << j1.M() << endl;
//   cout << "-------------------------------------------" << endl;
  return return_value;
  
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met)
{

  // IMPLEMENTATION OF COLLINEAR APPROXIMATION - validate code!
  
  float px0(signal_lep_0.Px()), py0(signal_lep_0.Py());
  float px1(signal_lep_1.Px()), py1(signal_lep_1.Py());
  float pxm(met.Px()), pym(met.Py());
  float num( px0*py1 - py0*px1 );
  float den1( py1*pxm - px1*pym + px0*py1 - py0*px1 );
  float den2( px0*pym - py0*pxm + px0*py1 - py0*px1 );
  float x1 = ( den1 != 0.0 ? (num/den1) : 0.0);
  float x2 = ( den2 != 0.0 ? (num/den2) : 0.0);
  // not guaranteed that this configuration is kinematically possible

  float returnvalue = x1*x2 > 0.0 ? (signal_lep_0+signal_lep_1).M() / std::sqrt(x1*x2) : -1.0;
  return returnvalue;
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type){
 //initialize missing mass calculator MMC for identification of Z->tau tau events https://svnweb.cern.ch/trac/atlasusr/browser/mflechl/code/htautau/mmc/tags/mmc-00-01-10/README
     
// float sum_et = 0.;
// sum_et += m_met->refEle_sumet;
// sum_et += m_met->refGamma_sumet;
// //taus?
// sum_et += m_met->refJet_sumet;
// sum_et += m_met->softTerm_sumet;
// sum_et += m_met->refMuo_sumet;
//
// TLorentzVector vec1, vec2;
// vec1 = lep1; //ELECTRON
// vec2 = lep2; // MUON
//
// float met_resolution = 0.;
// // cout << "nSignalJets= " << nSignalJets << endl;
// if(nt.evt()->isMC){
// if(nSignalJets==0){
// met_resolution = 4.447 + 0.505 * sqrt(sum_et);
// }
// if(nSignalJets==1){
// met_resolution = 5.000 + 0.500 * sqrt(sum_et);
// }
// if(nSignalJets==2){
// met_resolution = 4.635 + 0.514 * sqrt(sum_et);
// }
// if(nSignalJets>=3){
// met_resolution = 4.528 + 0.513 * sqrt(sum_et);
// }
// }
//
// if(!nt.evt()->isMC){
// if(nSignalJets==0){
// met_resolution = 4.314 + 0.498 * sqrt(sum_et);
// }
// if(nSignalJets==1){
// met_resolution = 4.700 + 0.509 * sqrt(sum_et);
// }
// if(nSignalJets==2){
// met_resolution = 4.539 + 0.519 * sqrt(sum_et);
// }
// if(nSignalJets>=3){
// met_resolution = 3.897 + 0.540 * sqrt(sum_et);
// }
// }
// // mode:
// // 11 - for ee final state
// // 13 - for emu final state
// // 31 - for mue final state
// // 33 - for mumu final state
//
// int mode = 0;
//
// if(tau0_decay_type == 0 && tau1_decay_type == 0) mode = 11; //EE channel
//
// if(tau0_decay_type == 0 && tau1_decay_type == 1){ //EM channel
// if(vec1.Pt() > vec2.Pt()) mode = 13; //EMU
// if(vec1.Pt() < vec2.Pt()) mode = 31; //MUE
// }
// if(tau0_decay_type == 1 && tau1_decay_type == 1) mode = 33; //MM channel
//
// MMC_sumet.Clear();
// // cout << "lep1.Pt()= " << lep1.Pt() << " lep2.Pt()= " << lep2.Pt() << " m_met->lv().Px()= " << m_met->lv().Px() << " m_met->lv().Py()= " << m_met->lv().Py() << " met_resolution= " << met_resolution << " mode= " << mode;
// MMC_sumet.Scan6dAnal(vec1, vec2, m_met->lv().Px(), m_met->lv().Py(), met_resolution, mode);
//
// // MMC_sumet.Set_Alpha(1.);
// // MMC_sumet.Scan6d(vec1, vec2, m_met->lv().Px(), m_met->lv().Py(), met_resolution, mode);
//
// float met_ex = MMC_sumet.GetCorrMEX();
// float met_ey = MMC_sumet.GetCorrMEY();
// // cout << " corrected met_ex= " << met_ex << " met_ey= " << met_ey << endl;
//
// // if (isnan(met_ex) || isnan(met_ey) ){
// // met_ex = m_met->lv().Px();
// // met_ey = m_met->lv().Py();
// // cout << "shift corrected met to old values because NAN" << endl;
// // }
// MMC_sumet.Scan4dAnal(vec1, vec2, met_ex, met_ey, mode);
// //validate: which method is best to get mass value?
// float mZTauTau_mmc = -1.;
// mZTauTau_mmc = MMC_sumet.GetMZ_peak();
// // cout << "MMC_sumet.GetMZ_mean()= " << MMC_sumet.GetMZ_mean() << " MMC_sumet.GetMZ_maxprob()= " << MMC_sumet.GetMZ_maxprob() << endl;
// // cout << "mZTauTau_mmc= " << mZTauTau_mmc << endl;
// return mZTauTau_mmc;
  return 111.;

}
void TSelector_SusyNtuple_excess::fillHistos_EE(int cutnumber, float weight){
//   cutflow_EE->Fill(cutnumber,1.0);
//   cutflow_EE_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_excess::fillHistos_MM(int cutnumber, float weight){
//   cutflow_MM->Fill(cutnumber,1.0);
//   cutflow_MM_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_excess::fillHistos_EM(int cutnumber, float weight){
//   cutflow_EM->Fill(cutnumber,1.0);
//   cutflow_EM_ALL->Fill(cutnumber, weight);
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calcSumMv1(const JetVector &signalJets){
  
  //with or without leptons?
  
  float sumMv1 = 0.;
  for(uint j=0; j<signalJets.size(); ++j){
Jet* jet = signalJets.at(j);
sumMv1 += jet->mv1;
  }
  return sumMv1;
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::getFakeWeight(const LeptonVector &baseLeps, susy::fake::Region region, float metRel, SusyMatrixMethod::SYSTEMATIC sys)
{

  if(baseLeps.size() != 2) return 0.0;

  uint nVtx = nt.evt()->nVtx;
  bool isMC = nt.evt()->isMC;
  
  float weight = m_matrix->getTotalFake( isSignalLepton(baseLeps[0],m_baseElectrons, m_baseMuons,nVtx,isMC),
                                         baseLeps[0]->isEle(),
                                         baseLeps[0]->Pt() * 1000.,
                                         baseLeps[0]->Eta(),
                                         isSignalLepton(baseLeps[1],m_baseElectrons, m_baseMuons,nVtx,isMC),
                                         baseLeps[1]->isEle(),
                                         baseLeps[1]->Pt() * 1000.,
                                         baseLeps[1]->Eta(),
                                         region,
                                         metRel * 1000.,
                                         sys);

  return weight;

}


/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_excess::calc_D0(bool unbiased, const Lepton* lep)
{
  float d0_branch;
  
  if(unbiased){
    d0_branch = lep->d0Unbiased;
  }
  else{
    d0_branch = lep->d0;
  }
  
  return d0_branch;
}
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::compareElecMomentum (Electron* e0, Electron* e1){ return (e0->Pt() > e1->Pt()); }

// /*--------------------------------------------------------------------------------*/
// ElectronVector TSelector_SusyNtuple_excess::getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys)
// {
//   
// //    electrons which are too soft: pT < 10 GeV [susyNt->eleco() but pT < 10 GeV]
//   ElectronVector soft_electrons;
//   for(uint ie=0; ie<susyNt->ele()->size(); ie++){
//     Electron* soft_elec = &susyNt->ele()->at(ie);
//     soft_elec->setState(sys);
//     if(soft_elec->Pt() < 10.) soft_electrons.push_back(soft_elec);
//   }
//   std::sort(soft_electrons.begin(), soft_electrons.end(), compareElecMomentum);
//  
//   return soft_electrons;
// }

/*--------------------------------------------------------------------------------*/
// ElectronVector TSelector_SusyNtuple_excess::getOverlapElectrons(SusyNtObject* susyNt, SusyNtSys sys)
// {
// //overlapElectrons: electrons which are removed in OR [getPreElectrons() but not m_baseElectrons (= no signal elec)]
//   ElectronVector overlap_electrons;
//   
//   ElectronVector PreElectrons = getPreElectrons(&nt, SysSetting);    
//   
//   for(uint ie=0; ie<PreElectrons.size(); ie++){
//     Electron* pre_el = PreElectrons.at(ie);
//     pre_el->setState(sys);
//     bool noBaseEl = true;
//     for(uint ie2=0; ie2<m_baseElectrons.size(); ie2++){
//       Electron* base_el = m_baseElectrons.at(ie2);
//       base_el->setState(sys);
//       if(base_el->DeltaR(*pre_el) < 0.0001) noBaseEl = false;
//     }
//     if(noBaseEl) overlap_electrons.push_back(pre_el);
//   }
//   std::sort(overlap_electrons.begin(), overlap_electrons.end(), compareElecMomentum);
//  
//   return overlap_electrons;
// }
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::compareMuonMomentum (Muon* mu0, Muon* mu1){ return (mu0->Pt() > mu1->Pt()); }
/*--------------------------------------------------------------------------------*/
// MuonVector TSelector_SusyNtuple_excess::getSoftMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
// {
// //    muons which are too soft: pT < 10 GeV [susyNt->muo() but pT < 10 GeV]
//   MuonVector soft_muons;
//   for(uint im=0; im<susyNt->muo()->size(); im++){
//     Muon* soft_mu = &susyNt->muo()->at(im);
//     soft_mu->setState(SysSetting);
//     if(soft_mu->Pt() < 10.) soft_muons.push_back(soft_mu);
//   }
//   std::sort(soft_muons.begin(), soft_muons.end(), compareMuonMomentum);
//  
//   return soft_muons;
// }

/*--------------------------------------------------------------------------------*/
// MuonVector TSelector_SusyNtuple_excess::getOverlapMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
// {
// //overlapMuons: muons which are removed in OR [getPreMuons() but not m_baseMuons (= no signal muon)]
//   MuonVector overlap_muons;
//   
//   MuonVector PreMuons = getPreMuons(&nt, SysSetting);    
//   
//   for(uint im=0; im<PreMuons.size(); im++){
//     Muon* pre_mu = PreMuons.at(im);
//     pre_mu->setState(SysSetting);
//     bool noBaseMu = true;
//     for(uint im2=0; im2<m_baseMuons.size(); im2++){
//       Muon* base_mu = m_baseMuons.at(im2);
//       base_mu->setState(SysSetting);
//       if(base_mu->DeltaR(*pre_mu) < 0.0001) noBaseMu = false;
//     }
//     if(noBaseMu) overlap_muons.push_back(pre_mu);
//   }
//   std::sort(overlap_muons.begin(), overlap_muons.end(), compareMuonMomentum);
//  
//   return overlap_muons;
// }

/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::isCMSJet(const Susy::Jet* jet)
{
  if(jet->Pt() < 30.) return false;
  //if(fabs(jet->Eta()) > JET_ETA_CUT_2L) return false;
  if(fabs(jet->detEta) > JET_ETA_CUT_2L) return false;
  if(jet->Pt() < JET_JVF_PT && 
     fabs(jet->jvf) - 1e-3 < JET_JVF_CUT_2L) return false;
  if(jet->mv1 > MV1_80) return false;

  return true;
}
/*--------------------------------------------------------------------------------*/
int TSelector_SusyNtuple_excess::numberOfCMSJets(const JetVector& jets)
{
  int ans = 0;

  for(uint ij=0; ij<jets.size(); ++ij){
    const Jet* j = jets.at(ij);
    if(isCMSJet(j)){
      ans++;
    }
  }

  return ans;
}


/*--------------------------------------------------------------------------------*/
vector<TLorentzVector> TSelector_SusyNtuple_excess::overlapRemoval(vector<TLorentzVector> objects_type1, vector<TLorentzVector> objects_type2, double dr, bool sameType, bool removeSoft) 
{
  //copied from MultiLep/CutflowTools.h and modified to work simply with vector<TLorentzVector>
//   cout << "overlapRemoval: dr " << dr << endl;
    vector<TLorentzVector> survivors;
    for(unsigned int i=0; i<objects_type1.size(); i++) {
        bool is_overlap = false;
        for(unsigned int j=0; j<objects_type2.size(); j++) {

            // Don't remove an object against itself (for electron-electron overlap) 
            if(sameType && i==j) continue;
	    
            if (removeSoft) {
	      //not needed at the moment
//                 if ( (object1.E()/cosh(object1.Eta())) > (object2.E()/cosh(object2.Eta()))) {
//                     continue;    // remove lowest Et
//                 }
//                 if(object1.DeltaR(object2) <= dr) {
//                     is_overlap = true;
//                 }
            } else {
// 		cout << "i " << i << " j " << j << " DeltaR= " << objects_type1.at(i).DeltaR(objects_type2.at(j)) << endl;				
                if(objects_type1.at(i).DeltaR(objects_type2.at(j)) <= dr) {
// 		    cout << "DeltaR= " << objects_type1.at(i).DeltaR(objects_type2.at(j))
                    is_overlap = true;
// 		    cout << "overlapRemoval: overlapping object" << endl;
                }
            }
        }
        if(is_overlap) {
            continue;
        }
        survivors.push_back(objects_type1.at(i));
    }
    return survivors;
}

/*--------------------------------------------------------------------------------*/

bool TSelector_SusyNtuple_excess::doEventCleaning_andFillHistos(int flag, float weight_ALL_EE, float weight_ALL_MM, float weight_ALL_EM, SusyNtSys SysSetting, bool n0150BugFix)
{
  float cutnumber = 0.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); // all events in the sample

  if( !(flag & ECut_GRL) ) return false;
  cutnumber = 1.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //grl Cut
  

  if( !(ECut_TileTrip & flag) ) return false;
  cutnumber = 2.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //TileTripReader
  

// if ( !(flag & ECut_TTC)) return false;
  cutnumber = 3.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//IncompleteEvents Veto
  

  if(!(ECut_LarErr & flag) || !(ECut_TileErr & flag)) return false;
  cutnumber = 4.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //LAr/TileError
  

// if( !(flag & ECut_HotSpot)) return false; //remove event where a jet points into hot TileCal module
  cutnumber = 5.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //TileCalHotSpot
  

  // remove event with VeryLooseBad jets with pT>20 GeV. No eta cut. Only consider jets which are not overlapping with electrons or taus:
  if(hasBadJet(m_baseJets))return kFALSE;
  cutnumber = 6.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadJets
  
    
  //on top of smart veto, veto event with >=1 jets before electron-jet overlap removal with pT>40 GeV, BCH_CORR_JET > 0.05, DeltaPhi(met,jet)<0.3 (Anyes)
  JetVector prejets = getPreJets(&nt, SysSetting);
  if(!passDeadRegions(prejets, m_met, nt.evt()->run, nt.evt()->isMC)/* || !(flag & ECut_SmartVeto)*/) return false; // SusyNtTools: passDeadRegions(...)
  cutnumber = 7.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //CaloJets
  

  if( !(flag & ECut_GoodVtx)) return false;
  cutnumber = 8.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//PrimaryVertex
  

  MuonVector preMuons = getPreMuons(&nt, SysSetting, n0150BugFix);
  if( hasBadMuon(preMuons)) return false;
  cutnumber = 9.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadMuons
  
    
  if(hasCosmicMuon(m_baseMuons)) return false; // !(flag & ECut_Cosmic) - no longer guarantee the event flags that are stored :-(
  preMuons.clear();
  cutnumber = 10.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Cosmic Muons
  


  // Sherpa WW fix, remove radiative b-quark processes that overlap with single top: already done upstream in SusyCommon SusyNtMaker

  if(nt.evt()->hfor == 4) return false; //remove events where same heavy flavor final states arise in multiple samples when combining ALPGEN samples
  cutnumber = 11.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//hfor veto
  if(nt.evt()->event == 17764246 || nt.evt()->event == 18676984 || nt.evt()->event == 19507114 || nt.evt()->event == 22743905 || nt.evt()->event == 89921988 || nt.evt()->event == 162105581 || nt.evt()->event == 204010717 || nt.evt()->event == 211601840 || nt.evt()->event == 17417168 || nt.evt()->event ==  31715223) cout << "event " << nt.evt()->event << " cutnumber = " << cutnumber << " m_baseLeptons.size()= " << m_baseLeptons.size() << endl;

  if(m_baseLeptons.size() < 2) return false;
  cutnumber = 12.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//at least 2 base leptons
  

  if( !(m_baseLeptons.size()==2) ) return false;
  cutnumber = 13.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//exactly 2 base leptons
  


// if(!(m_baseElectrons.size()==2 || m_baseMuons.size()==2 || (m_baseElectrons.size()+m_baseMuons.size())==2)) return false; //only count leptons where no Mll < 20 GeV. Mll < 12 GeV veto ALREADY DONE FOR SELECTING BASELINE LEPTONS in performOverlapRemoval()


  // discard any SFOS baseline lepton pair with M_ll < 12 GeV unnecessary: already done when skimming/slimming ntuples
  // Any lepton pairs are required to have an invariant mass, m``, above 20 GeV such that to remove low-mass dilepton resonances
  if( Mll(m_baseLeptons[0], m_baseLeptons[1]) < 20 )return false;
  cutnumber = 14.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Mll
  
  
  return true;
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_excess::initTupleMaker(const std::string &outFilename, const std::string &treename)
{
    /*if(file_ && file_->IsOpen() && tree_) {
        cout<<"TupleMaker::init: already initialized"<<endl;
        return false;
    }
    else */return (initFile(outFilename) && initTree(treename));
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_excess::initFile(const std::string &outFilename)
{
    file_ = TFile::Open(outFilename.c_str(), "recreate");
    if(!file_) cout<<"TupleMaker::initFile('"<<outFilename<<"') : failed to create file"<<endl;
    cout << "init " << outFilename << endl;
    return (file_ && file_->IsOpen());
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_excess::initTree(const std::string &treename)
{
    bool initialized(false);
    TDirectory *startingDir = gDirectory;
    if(file_) {
        file_->cd();
        string title("TupleMaker tree");
        tree_ = new TTree(treename.c_str(), title.c_str());
        tree_->SetDirectory(file_);
        initTreeBranches();
        initialized = true;
	cout << "init " << treename << endl;
    } else {
        cout<<"TupleMaker::initTree: invalid file, failed to create tree"<<endl;
    }
    if(startingDir) startingDir->cd(); // root is easily confused by pwd; cd back to where we were
    return initialized;
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_excess::initTreeBranches()
{
    bool initialized(false);
    if(tree_) {
        tree_->Branch("l0",    &l0_); //l0_, l1_, met_: FourMom() : px(0), py(0), pz(0), E(0), isMu(false), isEl(false), isJet(false) {}
        tree_->Branch("l1",    &l1_);
        tree_->Branch("met",   &met_);
        tree_->Branch("jets",  &jets_); //vector<FourMom> jets_, lowptLepts_
        tree_->Branch("lepts", &lowptLepts_);
        tree_->Branch("pars",  &eventPars_); //EventParameters() : weight(0), eventNumber(0), runNumber(0) {}
    } else {
        cout<<"TupleMaker::initTreeBranches : invalid tree, failed to init branches"<<endl;
    }
    return initialized;
}
//----------------------------------------------------------
FourMom lepton2FourMom (const Lepton *l)
{    
    return (  l && l->isMu()  ? FourMom().setMu(*l)
            : l && l->isEle() ? FourMom().setEl(*l)
            : FourMom());
}
//----------------------------------------------------------
FourMom jet2FourMom (const Jet *j) { return (j ? FourMom().setJet(*j) : FourMom()); }
//----------------------------------------------------------
bool TSelector_SusyNtuple_excess::fillTupleMaker(const double weight, const unsigned int run, const unsigned int event, const bool isMc,
                      const Susy::Lepton &l0, const Susy::Lepton &l1, const Susy::Met &met,
                      const LeptonVector &otherLeptons, const JetVector &jets)
{
    bool someBytesWritten(false);
    if(tree_) {
//       cout << "fillTupleMaker" << endl;
        eventPars_.setWeight(weight).setRun(run).setEvent(event).setIsmc(isMc);
        l0.isMu() ? l0_.setMu(l0) : l0_.setEl(l0);
        l1.isMu() ? l1_.setMu(l1) : l1_.setEl(l1);
        met_.setMet(met);
        jets_.clear();
        lowptLepts_.clear();
        const LeptonVector &olps = otherLeptons;
        std::transform(jets.begin(), jets.end(), std::back_inserter(jets_),       jet2FourMom);
        std::transform(olps.begin(), olps.end(), std::back_inserter(lowptLepts_), lepton2FourMom);
        someBytesWritten = (tree_->Fill()>0);
    }
    return someBytesWritten;
}
/*--------------------------------------------------------------------------------*/
LeptonVector TSelector_SusyNtuple_excess::getAnyElOrMu(SusyNtObject &susyNt, const Lepton *l0, const Lepton *l1)
{
    // DG 2013-12-02:
    // todo1 : re-implement with std algo
    // todo2 : re-implement with syst
    LeptonVector leptons;
    for(uint ie=0; ie<susyNt.ele()->size(); ++ie){
      if(Electron* e = & susyNt.ele()->at(ie)){ //e->setState(sys);
	if(fabs(e->d0Sig(true)) >= ELECTRON_D0SIG_CUT_WH) continue;
	if(fabs(e->z0SinTheta(true)) >= ELECTRON_Z0_SINTHETA_CUT) continue;
	if((e->q * l0->q)<0. || (e->q * l1->q)<0.){
	    leptons.push_back(static_cast<Lepton*>(e));
	}
      }
    }
    for(uint im=0; im<susyNt.muo()->size(); ++im){
        if(Muon* m = & susyNt.muo()->at(im)){ //m->setState(sys);
	  if(fabs(m->d0Sig(true)) >= MUON_D0SIG_CUT) continue;
	  if(fabs(m->z0SinTheta(true)) >= MUON_Z0_SINTHETA_CUT) continue;
	  if((m->q * l0->q)<0. || (m->q * l1->q)<0.){
            leptons.push_back(static_cast<Lepton*>(m));
	  }
        }
    }
    return leptons;
}
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::closeTupleMaker()
{
    bool closed(false);
    if(file_) {
        file_->cd();
        file_->Write();
        file_->Close();
        file_->Delete();
        file_ = 0;
        closed = true;
	cout << "closeTupleMaker" << endl;
    } else {
        cout<<"TupleMaker::close : file not there"<<endl;
    }
    return closed;
}

// /*--------------------------------------------------------------------------------*/
// SusyNtSys TSelector_SusyNtuple_excess::returnSysUncertType(int isys){
//   if(isys == 0 ) return NtSys_NOM;
//   if(isys == 1 ) return NtSys_EES_Z_UP;   
//   if(isys == 2 ) return NtSys_EES_Z_DN;   
//   if(isys == 3 ) return NtSys_EES_MAT_UP; 
//   if(isys == 4 ) return NtSys_EES_MAT_DN; 
//   if(isys == 5 ) return NtSys_EES_PS_UP;  
//   if(isys == 6 ) return NtSys_EES_PS_DN;  
//   if(isys == 7 ) return NtSys_EES_LOW_UP; 
//   if(isys == 8 ) return NtSys_EES_LOW_DN; 
//   if(isys == 9 ) return NtSys_EER_UP;     
//   if(isys == 10) return NtSys_EER_DN;     
//   if(isys == 11) return NtSys_MS_UP;      
//   if(isys == 12) return NtSys_MS_DN;      
//   if(isys == 13) return NtSys_ID_UP;      
//   if(isys == 14) return NtSys_ID_DN;      
//   if(isys == 15) return NtSys_JES_UP;     
//   if(isys == 16) return NtSys_JES_DN;     
//   if(isys == 17) return NtSys_JER;        
//   if(isys == 18) return NtSys_SCALEST_UP; 
//   if(isys == 19) return NtSys_SCALEST_DN;    
//   if(isys == 20) return NtSys_RESOST;   
//   if(isys == 21) return NtSys_TRIGSF_EL_UP; 
//   if(isys == 22) return NtSys_TRIGSF_EL_DN; 
//   if(isys == 23) return NtSys_TRIGSF_MU_UP; 
//   if(isys == 24) return NtSys_TRIGSF_MU_DN; 
//   if(isys == 25) return NtSys_TES_UP;     
//   if(isys == 26) return NtSys_TES_DN;     
//   
//   else {
//    cout << "NO VALID SYS UNCERTAINTY SET, WILL USE NOMINAL VALUE" << endl;
//    return   NtSys_NOM;
//   }
// }
//   
//   /*--------------------------------------------------------------------------------*/
// int TSelector_SusyNtuple_excess::returnSysUncertNumber(SusyNtSys UncertType){
//   if(UncertType == NtSys_NOM)            isys = 0 ;
//   if(UncertType == NtSys_EES_Z_UP)       isys = 1 ;
//   if(UncertType == NtSys_EES_Z_DN)       isys = 2 ;
//   if(UncertType == NtSys_EES_MAT_UP)     isys = 3 ; 
//   if(UncertType == NtSys_EES_MAT_DN)     isys = 4 ;
//   if(UncertType == NtSys_EES_PS_UP)      isys = 5 ;
//   if(UncertType == NtSys_EES_PS_DN)      isys = 6 ;
//   if(UncertType == NtSys_EES_LOW_UP)     isys = 7 ;
//   if(UncertType == NtSys_EES_LOW_DN)     isys = 8 ;
//   if(UncertType == NtSys_EER_UP)         isys = 9 ;
//   if(UncertType == NtSys_EER_DN)         isys = 10;
//   if(UncertType == NtSys_MS_UP)          isys = 11;
//   if(UncertType == NtSys_MS_DN)          isys = 12;
//   if(UncertType == NtSys_ID_UP)          isys = 13;
//   if(UncertType == NtSys_ID_DN)          isys = 14;
//   if(UncertType == NtSys_JES_UP)         isys = 15;
//   if(UncertType == NtSys_JES_DN)         isys = 16;
//   if(UncertType == NtSys_JER)            isys = 17;
//   if(UncertType == NtSys_SCALEST_UP)     isys = 18;
//   if(UncertType == NtSys_SCALEST_DN)     isys = 19;
//   if(UncertType == NtSys_RESOST)         isys = 20;
//   if(UncertType == NtSys_TRIGSF_EL_UP)   isys = 21;
//   if(UncertType == NtSys_TRIGSF_EL_DN)   isys = 22;
//   if(UncertType == NtSys_TRIGSF_MU_UP)   isys = 23;
//   if(UncertType == NtSys_TRIGSF_MU_DN)   isys = 24;
//   if(UncertType == NtSys_TES_UP)         isys = 25;
//   if(UncertType == NtSys_TES_DN)         isys = 26;
//                                                
//   else {
//    cout << "NO VALID SYS UNCERTAINTY SET, WILL USE NOMINAL VALUE" << endl;
//    return   0;
//   }
// }
// /*--------------------------------------------------------------------------------*/
// int TSelector_SusyNtuple_excess::returnSysUncertBTagNumber(BTagSys UncertType){
//  if(UncertType == BTag_BJet_DN)          isys = 27 ;
//  if(UncertType == BTag_CJet_DN)          isys = 28 ;
//  if(UncertType == BTag_LJet_DN)          isys = 29 ;
//  if(UncertType == BTag_BJet_UP)          isys = 30 ;
//  if(UncertType == BTag_CJet_UP)          isys = 31 ;
//  if(UncertType == BTag_LJet_UP)          isys = 32 ;
//     
// else {
//    cout << "NO VALID SYS UNCERTAINTY SET, WILL USE NOMINAL VALUE" << endl;
//    return   0;
//   }
// }
/*--------------------------------------------------------------------------------*/
char *TSelector_SusyNtuple_excess::GetID(Int_t type)
{
   return Form ("%d", type);
}

/*--------------------------------------------------------------------------------*/
// Debug event
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_excess::debugEvent()
{
  uint run = nt.evt()->run;
  uint evt = nt.evt()->event;
  //if(run==191139 && evt==140644832) return true;
  if(run==180164&&evt==24769) return true;

  return false;
}
/*--------------------------------------------------------------------------------*/


float TSelector_SusyNtuple_excess::getLeptonSF(const LeptonVector& leptons, int SFUncertType)
{
  float sf = 1.;
  for(uint i=0; i<leptons.size(); i++){
    const Lepton* lep = leptons[i];
    if(lep->isEle() && SFUncertType == 1)
      sf *= (lep->effSF + lep->errEffSF);

    else if(lep->isEle() && SFUncertType == 2)
      sf *= (lep->effSF - lep->errEffSF);

    else if(lep->isMu() && SFUncertType == 3)
      sf *= (lep->effSF + lep->errEffSF);

    else if(lep->isMu() && SFUncertType == 4)
      sf *= (lep->effSF - lep->errEffSF);

    else sf *= lep->effSF;
  }
  return sf;
}

void TSelector_SusyNtuple_excess::fillExcessHistos_0j(Electron* el_SS, TLorentzVector el_SS_TLV, Muon* mu, TLorentzVector mu_TLV, const Lepton *l0, const Lepton *l1, int cutnumber_Ex){

  //USE all |eta|>1.8 events
    //USE all |eta|>1.8 events
  bool isInEtaArea = false;
  if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
    isInEtaArea = true;
  }
  //----------------------------------------------------
  //      electron
  //----------------------------------------------------
  if(isInEtaArea) h_Ex_0j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  h_0j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  h_0j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  h_0j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_0j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  h_0j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  h_0j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);
  h_0j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_0j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_0j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_0j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_0j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  h_0j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  h_0j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_0j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  h_0j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_0j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.); 
  h_0j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  h_0j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_0j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  h_0j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  h_0j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_el = el_SS->Pt();
  if(isInEtaArea) h_Ex_0j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_0j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_0j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_0j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  }  
  
  if(isInEtaArea) h_Ex_0j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_0j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  //trigger matching alread done in SusyCommon, just check which trigger fired:
  DiLepEvtType evtType = getDiLepEvtType(m_signalLeptons);
  if( evtType == ET_em || evtType == ET_me ){
    DilTriggerRegion trigRegion = m_trigObjWithoutRU->getEMTrigRegion(el_SS->Pt(), mu->Pt());

    if( (trigRegion == DTR_EM_A)  && (nt.evt()->trigFlags & TRIG_e12Tvh_medium1_mu8)){
      if(isInEtaArea) h_Ex_0j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      h_0j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_0j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_0j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
    }
    if( (trigRegion == DTR_EM_B) && (nt.evt()->trigFlags & TRIG_mu18_tight_e7_medium1)){
      if(isInEtaArea) h_Ex_0j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      h_0j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_0j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_0j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      
    }  
  }  
  
  //----------------------------------------------------
  //      muon
  //----------------------------------------------------
  
  if(isInEtaArea) h_Ex_0j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  h_0j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  h_0j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  h_0j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  
  
  if(isInEtaArea) h_Ex_0j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  h_0j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_0j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_0j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  h_0j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_0j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 
  h_0j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_0j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);
  h_0j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_0j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  h_0j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  h_0j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_0j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  h_0j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_0j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 
  h_0j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_0j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  h_0j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  if(isInEtaArea) h_Ex_0j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.);     
  h_0j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_0j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.);     
  h_0j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_0j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 
  h_0j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_0j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  h_0j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  h_0j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  h_0j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  h_0j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_0j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  h_0j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  h_0j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_mu = mu->Pt();
  if(isInEtaArea) h_Ex_0j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_0j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_0j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_0j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_0j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_0j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  }
      
  //----------------------------------------------------
  //      Overlap Removal
  //----------------------------------------------------

  for(uint ie=0; ie<nt.ele()->size(); ++ie){
    Electron* e = & nt.ele()->at(ie);
    e->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<nt.ele()->size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = & nt.ele()->at(ie2);
      e2->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<nt.muo()->size(); ++im){
      Muon* mu = & nt.muo()->at(im);
      mu->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<nt.muo()->size(); ++im){
    Muon* mu = & nt.muo()->at(im);
    mu->setState(SysSetting, n0150BugFix);
    for(uint im2=0; im2<nt.muo()->size(); ++im2){
    if(im == im2) continue;
      Muon* mu2 = & nt.muo()->at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
    }				  
  }
  for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
    Tau* tau = & nt.tau()->at(iTau);
    tau->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_0j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }	
  
  for(uint ie=0; ie<m_signalElectrons.size(); ++ie){
    Electron* e = m_signalElectrons.at(ie);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<m_signalElectrons.size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = m_signalElectrons.at(ie2);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<m_signalMuons.size(); ++im){
      Muon* mu = m_signalMuons.at(im);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_0j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_0j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<m_signalMuons.size(); ++im){
    Muon* mu = m_signalMuons.at(im);
    for(uint im2=0; im2<m_signalMuons.size(); ++im2){
      if(im == im2) continue;
      Muon* mu2 = m_signalMuons.at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_0j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_0j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      
    }				  
  }
  for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
    Tau* tau = m_signalTaus.at(iTau);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_0j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_0j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }
  


}

void TSelector_SusyNtuple_excess::fillExcessHistos_1j(Electron* el_SS, TLorentzVector el_SS_TLV, Muon* mu, TLorentzVector mu_TLV, const Lepton *l0, const Lepton *l1, int cutnumber_Ex){

  //USE all |eta|>1.8 events
  bool isInEtaArea = false;
  if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
    isInEtaArea = true;
  }
  //----------------------------------------------------
  //      electron
  //----------------------------------------------------
  if(isInEtaArea) h_Ex_1j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  h_1j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  h_1j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  h_1j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_1j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  h_1j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  h_1j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);
  h_1j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_1j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_1j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_1j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_1j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  h_1j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  h_1j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_1j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  h_1j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_1j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.); 
  h_1j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  h_1j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_1j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  h_1j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  h_1j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_el = el_SS->Pt();
  if(isInEtaArea) h_Ex_1j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_1j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_1j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_1j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  } 

  if(isInEtaArea) h_Ex_1j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_1j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  //trigger matching alread done in SusyCommon, just check which trigger fired:
  DiLepEvtType evtType = getDiLepEvtType(m_signalLeptons);
  if( evtType == ET_em || evtType == ET_me ){
    DilTriggerRegion trigRegion = m_trigObjWithoutRU->getEMTrigRegion(el_SS->Pt(), mu->Pt());

    if( (trigRegion == DTR_EM_A)  && (nt.evt()->trigFlags & TRIG_e12Tvh_medium1_mu8)){
      if(isInEtaArea) h_Ex_1j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      h_1j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_1j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_1j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
    }
    if( (trigRegion == DTR_EM_B) && (nt.evt()->trigFlags & TRIG_mu18_tight_e7_medium1)){
      if(isInEtaArea) h_Ex_1j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      h_1j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_1j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_1j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      
    }  
  }
  
  
  //----------------------------------------------------
  //      muon
  //----------------------------------------------------
  
  if(isInEtaArea) h_Ex_1j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  h_1j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  h_1j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  h_1j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  
  
  if(isInEtaArea) h_Ex_1j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  h_1j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_1j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_1j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  h_1j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_1j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 
  h_1j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_1j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);
  h_1j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_1j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  h_1j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  h_1j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_1j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  h_1j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_1j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 
  h_1j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_1j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  h_1j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  if(isInEtaArea) h_Ex_1j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.);     
  h_1j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_1j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.);     
  h_1j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_1j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 
  h_1j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_1j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  h_1j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  h_1j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  h_1j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  h_1j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_1j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  h_1j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  h_1j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_mu = mu->Pt();
  if(isInEtaArea) h_Ex_1j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_1j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_1j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_1j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_1j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  }
      
  //----------------------------------------------------
  //      Overlap Removal
  //----------------------------------------------------

  for(uint ie=0; ie<nt.ele()->size(); ++ie){
    Electron* e = & nt.ele()->at(ie);
    e->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<nt.ele()->size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = & nt.ele()->at(ie2);
      e2->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<nt.muo()->size(); ++im){
      Muon* mu = & nt.muo()->at(im);
      mu->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<nt.muo()->size(); ++im){
    Muon* mu = & nt.muo()->at(im);
    mu->setState(SysSetting, n0150BugFix);
    for(uint im2=0; im2<nt.muo()->size(); ++im2){
    if(im == im2) continue;
      Muon* mu2 = & nt.muo()->at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
    }				  
  }
  for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
    Tau* tau = & nt.tau()->at(iTau);
    tau->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_1j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }	
  
  for(uint ie=0; ie<m_signalElectrons.size(); ++ie){
    Electron* e = m_signalElectrons.at(ie);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<m_signalElectrons.size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = m_signalElectrons.at(ie2);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<m_signalMuons.size(); ++im){
      Muon* mu = m_signalMuons.at(im);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_1j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_1j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<m_signalMuons.size(); ++im){
    Muon* mu = m_signalMuons.at(im);
    for(uint im2=0; im2<m_signalMuons.size(); ++im2){
      if(im == im2) continue;
      Muon* mu2 = m_signalMuons.at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_1j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_1j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      
    }				  
  }
  for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
    Tau* tau = m_signalTaus.at(iTau);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_1j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_1j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }
  
  //----------------------------------------------------
  //      jets
  //----------------------------------------------------
  if(m_signalJets2Lep.size()>0){      
    if(isInEtaArea) h_Ex_1j_j0_pt ->Fill(m_signalJets2Lep.at(0)->Pt(), cutnumber_Ex, 1.);
    h_1j_j0_pt ->Fill(m_signalJets2Lep.at(0)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_eta->Fill(m_signalJets2Lep.at(0)->Eta(), cutnumber_Ex, 1.);
    h_1j_j0_eta->Fill(m_signalJets2Lep.at(0)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_phi->Fill( m_signalJets2Lep.at(0)->Phi(), cutnumber_Ex, 1.);
    h_1j_j0_phi->Fill( m_signalJets2Lep.at(0)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_1j_j0_jvf->Fill(m_signalJets2Lep.at(0)->jvf, cutnumber_Ex, 1.); 
    h_1j_j0_jvf->Fill(m_signalJets2Lep.at(0)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_1j_j0_detEta->Fill(m_signalJets2Lep.at(0)->detEta, cutnumber_Ex, 1.);
    h_1j_j0_detEta->Fill(m_signalJets2Lep.at(0)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_emfrac->Fill(m_signalJets2Lep.at(0)->emfrac, cutnumber_Ex, 1.);
    h_1j_j0_emfrac->Fill(m_signalJets2Lep.at(0)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_1j_j0_sv0->Fill(m_signalJets2Lep.at(0)->sv0, cutnumber_Ex, 1.);
    h_1j_j0_sv0->Fill(m_signalJets2Lep.at(0)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_combNN->Fill(m_signalJets2Lep.at(0)->combNN, cutnumber_Ex, 1.);
    h_1j_j0_combNN->Fill(m_signalJets2Lep.at(0)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_mv1->Fill(m_signalJets2Lep.at(0)->mv1, cutnumber_Ex, 1.);
    h_1j_j0_mv1->Fill(m_signalJets2Lep.at(0)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_jfit_mass->Fill(m_signalJets2Lep.at(0)->jfit_mass, cutnumber_Ex, 1.);
    h_1j_j0_jfit_mass->Fill(m_signalJets2Lep.at(0)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j0_bch_corr_jet->Fill(m_signalJets2Lep.at(0)->bch_corr_jet, cutnumber_Ex, 1.);
    h_1j_j0_bch_corr_jet->Fill(m_signalJets2Lep.at(0)->bch_corr_jet, cutnumber_Ex, 1.);
  }
  
if (nSignalJets >=2){
    if(isInEtaArea) h_Ex_1j_j1_pt ->Fill(m_signalJets2Lep.at(1)->Pt(), cutnumber_Ex, 1.);
    h_1j_j1_pt ->Fill(m_signalJets2Lep.at(1)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_eta->Fill(m_signalJets2Lep.at(1)->Eta(), cutnumber_Ex, 1.);
    h_1j_j1_eta->Fill(m_signalJets2Lep.at(1)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_phi->Fill( m_signalJets2Lep.at(1)->Phi(), cutnumber_Ex, 1.);
    h_1j_j1_phi->Fill( m_signalJets2Lep.at(1)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_1j_j1_jvf->Fill(m_signalJets2Lep.at(1)->jvf, cutnumber_Ex, 1.); 
    h_1j_j1_jvf->Fill(m_signalJets2Lep.at(1)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_1j_j1_detEta->Fill(m_signalJets2Lep.at(1)->detEta, cutnumber_Ex, 1.);
    h_1j_j1_detEta->Fill(m_signalJets2Lep.at(1)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_emfrac->Fill(m_signalJets2Lep.at(1)->emfrac, cutnumber_Ex, 1.);
    h_1j_j1_emfrac->Fill(m_signalJets2Lep.at(1)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_1j_j1_sv0->Fill(m_signalJets2Lep.at(1)->sv0, cutnumber_Ex, 1.);
    h_1j_j1_sv0->Fill(m_signalJets2Lep.at(1)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_combNN->Fill(m_signalJets2Lep.at(1)->combNN, cutnumber_Ex, 1.);
    h_1j_j1_combNN->Fill(m_signalJets2Lep.at(1)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_mv1->Fill(m_signalJets2Lep.at(1)->mv1, cutnumber_Ex, 1.);
    h_1j_j1_mv1->Fill(m_signalJets2Lep.at(1)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_jfit_mass->Fill(m_signalJets2Lep.at(1)->jfit_mass, cutnumber_Ex, 1.);
    h_1j_j1_jfit_mass->Fill(m_signalJets2Lep.at(1)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j1_bch_corr_jet->Fill(m_signalJets2Lep.at(1)->bch_corr_jet, cutnumber_Ex, 1.);
    h_1j_j1_bch_corr_jet->Fill(m_signalJets2Lep.at(1)->bch_corr_jet, cutnumber_Ex, 1.);
  }
  if (nSignalJets >=3){
    if(isInEtaArea) h_Ex_1j_j2_pt ->Fill(m_signalJets2Lep.at(2)->Pt(), cutnumber_Ex, 1.);
    h_1j_j2_pt ->Fill(m_signalJets2Lep.at(2)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_eta->Fill(m_signalJets2Lep.at(2)->Eta(), cutnumber_Ex, 1.);
    h_1j_j2_eta->Fill(m_signalJets2Lep.at(2)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_phi->Fill( m_signalJets2Lep.at(2)->Phi(), cutnumber_Ex, 1.);
    h_1j_j2_phi->Fill( m_signalJets2Lep.at(2)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_1j_j2_jvf->Fill(m_signalJets2Lep.at(2)->jvf, cutnumber_Ex, 1.); 
    h_1j_j2_jvf->Fill(m_signalJets2Lep.at(2)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_1j_j2_detEta->Fill(m_signalJets2Lep.at(2)->detEta, cutnumber_Ex, 1.);
    h_1j_j2_detEta->Fill(m_signalJets2Lep.at(2)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_emfrac->Fill(m_signalJets2Lep.at(2)->emfrac, cutnumber_Ex, 1.);
    h_1j_j2_emfrac->Fill(m_signalJets2Lep.at(2)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_1j_j2_sv0->Fill(m_signalJets2Lep.at(2)->sv0, cutnumber_Ex, 1.);
    h_1j_j2_sv0->Fill(m_signalJets2Lep.at(2)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_combNN->Fill(m_signalJets2Lep.at(2)->combNN, cutnumber_Ex, 1.);
    h_1j_j2_combNN->Fill(m_signalJets2Lep.at(2)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_mv1->Fill(m_signalJets2Lep.at(2)->mv1, cutnumber_Ex, 1.);
    h_1j_j2_mv1->Fill(m_signalJets2Lep.at(2)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_jfit_mass->Fill(m_signalJets2Lep.at(2)->jfit_mass, cutnumber_Ex, 1.);
    h_1j_j2_jfit_mass->Fill(m_signalJets2Lep.at(2)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_1j_j2_bch_corr_jet->Fill(m_signalJets2Lep.at(2)->bch_corr_jet, cutnumber_Ex, 1.);
    h_1j_j2_bch_corr_jet->Fill(m_signalJets2Lep.at(2)->bch_corr_jet, cutnumber_Ex, 1.);			    
  }
    
  if(isInEtaArea) h_Ex_1j_mlj->Fill(Mlj_1j_EM, cutnumber_Ex, 1.);
  h_1j_mlj->Fill(Mlj_1j_EM, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mlj_el->Fill(Mlj_1j_EM_el, cutnumber_Ex, 1.);
  h_1j_mlj_el->Fill(Mlj_1j_EM_el, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_mlj_mu->Fill(Mlj_1j_EM_mu, cutnumber_Ex, 1.);
  h_1j_mlj_mu->Fill(Mlj_1j_EM_mu, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_1j_Nj->Fill(m_signalJets2Lep.size(), cutnumber_Ex, 1.);
  h_1j_Nj->Fill(m_signalJets2Lep.size(), cutnumber_Ex, 1.);  




}

void TSelector_SusyNtuple_excess::fillExcessHistos_2j(Electron* el_SS, TLorentzVector el_SS_TLV, Muon* mu, TLorentzVector mu_TLV, const Lepton *l0, const Lepton *l1, int cutnumber_Ex){

  //USE all |eta|>1.8 events
  bool isInEtaArea = false;
  if(fabs(el_SS->Eta()) > 1.8 && fabs(el_SS->Eta()) < 2.2){
    isInEtaArea = true;
  }
  //----------------------------------------------------
  //      electron
  //----------------------------------------------------
  if(isInEtaArea) h_Ex_2j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  h_2j_el_pt ->Fill(el_SS_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  h_2j_el_eta->Fill(el_SS_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  h_2j_el_phi->Fill(el_SS_TLV.Phi(), cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_2j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  h_2j_el_etcone20->Fill(el_SS->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  h_2j_el_ptcone20->Fill(el_SS->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);
  h_2j_el_ptcone30->Fill(el_SS->ptcone30, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_2j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_2j_el_Ptcone30Corr->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);
  h_2j_el_topoEtcone30Corr->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC), cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_2j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  h_2j_el_d0->Fill(el_SS->d0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  h_2j_el_z0->Fill(el_SS->z0, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_2j_el_clusE->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  h_2j_el_clusEta->Fill(el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_2j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.); 
  h_2j_el_clusPhi->Fill(el_SS->clusPhi, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  h_2j_el_trackPt->Fill(el_SS->trackPt, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_2j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  h_2j_el_d0Sig->Fill(el_SS->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  h_2j_el_z0SinTheta->Fill(el_SS->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_el = el_SS->Pt();
  if(isInEtaArea) h_Ex_2j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_2j_el_ptconeOverPt->Fill(elPtConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_2j_el_etconeOverPt->Fill(elEtTopoConeCorr(el_SS, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_el,ELECTRON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_el_DeltaR_jets->Fill(el_SS->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_2j_el_DeltaR_jets_JVF->Fill(el_SS->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  }
  
  if(isInEtaArea) h_Ex_2j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  h_2j_el_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
  //trigger matching alread done in SusyCommon, just check which trigger fired:
  DiLepEvtType evtType = getDiLepEvtType(m_signalLeptons);
  if( evtType == ET_em || evtType == ET_me ){
    DilTriggerRegion trigRegion = m_trigObjWithoutRU->getEMTrigRegion(el_SS->Pt(), mu->Pt());

    if( (trigRegion == DTR_EM_A)  && (nt.evt()->trigFlags & TRIG_e12Tvh_medium1_mu8)){
      if(isInEtaArea) h_Ex_2j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      h_2j_el_trigger->Fill(1., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_2j_el_trigger_clusEt->Fill(1., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_2j_el_e12mu8_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
    }
    if( (trigRegion == DTR_EM_B) && (nt.evt()->trigFlags & TRIG_mu18_tight_e7_medium1)){
      if(isInEtaArea) h_Ex_2j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      h_2j_el_trigger->Fill(2., cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_2j_el_trigger_clusEt->Fill(2., el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      h_2j_el_mu18e7_eta_clusEt->Fill(el_SS->Eta(), el_SS->clusE/cosh(el_SS->clusEta), cutnumber_Ex, 1.);
      
    }  
  }
  
  //----------------------------------------------------
  //      muon
  //----------------------------------------------------
  
  if(isInEtaArea) h_Ex_2j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  h_2j_mu_pt ->Fill(mu_TLV.Pt(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  h_2j_mu_eta->Fill(mu_TLV.Eta(), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  h_2j_mu_phi->Fill(mu_TLV.Phi(), cutnumber_Ex, 1.);
  
  
  if(isInEtaArea) h_Ex_2j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  h_2j_mu_etcone20->Fill(mu->etcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_2j_mu_ptcone20->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  h_2j_mu_ptcone30->Fill(mu->ptcone20, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  h_2j_mu_d0->Fill(mu->d0, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_2j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 
  h_2j_mu_z0->Fill(mu->z0, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_2j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);
  h_2j_mu_isCombined->Fill(mu->isCombined, cutnumber_Ex, 1.);

  if(isInEtaArea) h_Ex_2j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  h_2j_mu_idTrackPt->Fill(mu->idTrackPt, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  h_2j_mu_idTrackEta->Fill(mu->idTrackEta, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_2j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  h_2j_mu_idTrackPhi->Fill(mu->idTrackPhi, cutnumber_Ex, 1.);  
  if(isInEtaArea) h_Ex_2j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 
  h_2j_mu_idTrackQ->Fill(mu->idTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_2j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  h_2j_mu_msTrackPt->Fill(mu->msTrackPt, cutnumber_Ex, 1.);   
  if(isInEtaArea) h_Ex_2j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.);     
  h_2j_mu_msTrackEta->Fill(mu->msTrackEta, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_2j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.);     
  h_2j_mu_msTrackPhi->Fill(mu->msTrackPhi, cutnumber_Ex, 1.); 
  if(isInEtaArea) h_Ex_2j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 
  h_2j_mu_msTrackQ->Fill(mu->msTrackQ, cutnumber_Ex, 1.); 

  if(isInEtaArea) h_Ex_2j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  h_2j_mu_thetaPV->Fill(mu->thetaPV, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  h_2j_mu_etcone30->Fill(mu->etcone30, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  h_2j_mu_etcone30Corr->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  h_2j_mu_ptcone30ElStyle->Fill(mu->ptcone30ElStyle, cutnumber_Ex, 1.);
  
  if(isInEtaArea) h_Ex_2j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  h_2j_mu_d0Sig->Fill(mu->d0Sig(true), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  h_2j_mu_z0SinTheta->Fill(mu->z0SinTheta(true), cutnumber_Ex, 1.);
  float pt_mu = mu->Pt();
  if(isInEtaArea) h_Ex_2j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_2j_mu_ptconeOverPt->Fill(mu->ptcone30ElStyle/std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  h_2j_mu_etconeOverPt->Fill(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/ std::min(pt_mu,MUON_ISO_PT_THRS), cutnumber_Ex, 1.);
  
  for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_mu_DeltaR_jets->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      if(isInEtaArea) h_Ex_2j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
      h_2j_mu_DeltaR_jets_JVF->Fill(mu->DeltaR(*j), j->jvf, cutnumber_Ex, 1.);
  }
      
  //----------------------------------------------------
  //      Overlap Removal
  //----------------------------------------------------

  for(uint ie=0; ie<nt.ele()->size(); ++ie){
    Electron* e = & nt.ele()->at(ie);
    e->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_jet_BeforeOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<nt.ele()->size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = & nt.ele()->at(ie2);
      e2->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_el_BeforeOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<nt.muo()->size(); ++im){
      Muon* mu = & nt.muo()->at(im);
      mu->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_mu_BeforeOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_tau_BeforeOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<nt.muo()->size(); ++im){
    Muon* mu = & nt.muo()->at(im);
    mu->setState(SysSetting, n0150BugFix);
    for(uint im2=0; im2<nt.muo()->size(); ++im2){
    if(im == im2) continue;
      Muon* mu2 = & nt.muo()->at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_mu_BeforeOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_jet_BeforeOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
      Tau* tau = & nt.tau()->at(iTau);
      tau->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_tau_BeforeOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
    }				  
  }
  for(uint iTau=0; iTau < nt.tau()->size(); iTau++){
    Tau* tau = & nt.tau()->at(iTau);
    tau->setState(SysSetting);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* j = & nt.jet()->at(ij);
      j->setState(SysSetting);
      if(isInEtaArea) h_Ex_2j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_tau_jet_BeforeOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }	
  
  for(uint ie=0; ie<m_signalElectrons.size(); ++ie){
    Electron* e = m_signalElectrons.at(ie);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_jet_AfterOR->Fill(e->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint ie2=0; ie2<m_signalElectrons.size(); ++ie2){
      if(ie == ie2) continue;
      Electron* e2 = m_signalElectrons.at(ie2);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_el_AfterOR->Fill(e->DeltaR(*e2), cutnumber_Ex, 1.);
    }
    for(uint im=0; im<m_signalMuons.size(); ++im){
      Muon* mu = m_signalMuons.at(im);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_mu_AfterOR->Fill(e->DeltaR(*mu), cutnumber_Ex, 1.);

    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_2j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
      h_2j_DeltaR_el_tau_AfterOR->Fill(e->DeltaR(*tau), cutnumber_Ex, 1.);
    }
  }

  for(uint im=0; im<m_signalMuons.size(); ++im){
    Muon* mu = m_signalMuons.at(im);
    for(uint im2=0; im2<m_signalMuons.size(); ++im2){
      if(im == im2) continue;
      Muon* mu2 = m_signalMuons.at(im2);
      mu2->setState(SysSetting, n0150BugFix);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_mu_AfterOR->Fill(mu->DeltaR(*mu2), cutnumber_Ex, 1.);
    }
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_jet_AfterOR->Fill(mu->DeltaR(*j), cutnumber_Ex, 1.);
    }
    for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
      Tau* tau = m_signalTaus.at(iTau);
      if(isInEtaArea) h_Ex_2j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      h_2j_DeltaR_mu_tau_AfterOR->Fill(mu->DeltaR(*tau), cutnumber_Ex, 1.);
      
    }				  
  }
  for(uint iTau=0; iTau < m_signalTaus.size(); iTau++){
    Tau* tau = m_signalTaus.at(iTau);
    for(uint ij=0; ij<m_signalJets2Lep.size(); ++ij){
      Jet* j = m_signalJets2Lep.at(ij);
      if(isInEtaArea) h_Ex_2j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
      h_2j_DeltaR_tau_jet_AfterOR->Fill(tau->DeltaR(*j), cutnumber_Ex, 1.);
    }
  }
  
  //----------------------------------------------------
  //      jets
  //----------------------------------------------------
  if(m_signalJets2Lep.size()>0){      
    if(isInEtaArea) h_Ex_2j_j0_pt ->Fill(m_signalJets2Lep.at(0)->Pt(), cutnumber_Ex, 1.);
    h_2j_j0_pt ->Fill(m_signalJets2Lep.at(0)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_eta->Fill(m_signalJets2Lep.at(0)->Eta(), cutnumber_Ex, 1.);
    h_2j_j0_eta->Fill(m_signalJets2Lep.at(0)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_phi->Fill( m_signalJets2Lep.at(0)->Phi(), cutnumber_Ex, 1.);
    h_2j_j0_phi->Fill( m_signalJets2Lep.at(0)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_2j_j0_jvf->Fill(m_signalJets2Lep.at(0)->jvf, cutnumber_Ex, 1.); 
    h_2j_j0_jvf->Fill(m_signalJets2Lep.at(0)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_2j_j0_detEta->Fill(m_signalJets2Lep.at(0)->detEta, cutnumber_Ex, 1.);
    h_2j_j0_detEta->Fill(m_signalJets2Lep.at(0)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_emfrac->Fill(m_signalJets2Lep.at(0)->emfrac, cutnumber_Ex, 1.);
    h_2j_j0_emfrac->Fill(m_signalJets2Lep.at(0)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_2j_j0_sv0->Fill(m_signalJets2Lep.at(0)->sv0, cutnumber_Ex, 1.);
    h_2j_j0_sv0->Fill(m_signalJets2Lep.at(0)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_combNN->Fill(m_signalJets2Lep.at(0)->combNN, cutnumber_Ex, 1.);
    h_2j_j0_combNN->Fill(m_signalJets2Lep.at(0)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_mv1->Fill(m_signalJets2Lep.at(0)->mv1, cutnumber_Ex, 1.);
    h_2j_j0_mv1->Fill(m_signalJets2Lep.at(0)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_jfit_mass->Fill(m_signalJets2Lep.at(0)->jfit_mass, cutnumber_Ex, 1.);
    h_2j_j0_jfit_mass->Fill(m_signalJets2Lep.at(0)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j0_bch_corr_jet->Fill(m_signalJets2Lep.at(0)->bch_corr_jet, cutnumber_Ex, 1.);
    h_2j_j0_bch_corr_jet->Fill(m_signalJets2Lep.at(0)->bch_corr_jet, cutnumber_Ex, 1.);
  }
  
if (nSignalJets >=2){
    if(isInEtaArea) h_Ex_2j_j1_pt ->Fill(m_signalJets2Lep.at(1)->Pt(), cutnumber_Ex, 1.);
    h_2j_j1_pt ->Fill(m_signalJets2Lep.at(1)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_eta->Fill(m_signalJets2Lep.at(1)->Eta(), cutnumber_Ex, 1.);
    h_2j_j1_eta->Fill(m_signalJets2Lep.at(1)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_phi->Fill( m_signalJets2Lep.at(1)->Phi(), cutnumber_Ex, 1.);
    h_2j_j1_phi->Fill( m_signalJets2Lep.at(1)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_2j_j1_jvf->Fill(m_signalJets2Lep.at(1)->jvf, cutnumber_Ex, 1.); 
    h_2j_j1_jvf->Fill(m_signalJets2Lep.at(1)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_2j_j1_detEta->Fill(m_signalJets2Lep.at(1)->detEta, cutnumber_Ex, 1.);
    h_2j_j1_detEta->Fill(m_signalJets2Lep.at(1)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_emfrac->Fill(m_signalJets2Lep.at(1)->emfrac, cutnumber_Ex, 1.);
    h_2j_j1_emfrac->Fill(m_signalJets2Lep.at(1)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_2j_j1_sv0->Fill(m_signalJets2Lep.at(1)->sv0, cutnumber_Ex, 1.);
    h_2j_j1_sv0->Fill(m_signalJets2Lep.at(1)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_combNN->Fill(m_signalJets2Lep.at(1)->combNN, cutnumber_Ex, 1.);
    h_2j_j1_combNN->Fill(m_signalJets2Lep.at(1)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_mv1->Fill(m_signalJets2Lep.at(1)->mv1, cutnumber_Ex, 1.);
    h_2j_j1_mv1->Fill(m_signalJets2Lep.at(1)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_jfit_mass->Fill(m_signalJets2Lep.at(1)->jfit_mass, cutnumber_Ex, 1.);
    h_2j_j1_jfit_mass->Fill(m_signalJets2Lep.at(1)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j1_bch_corr_jet->Fill(m_signalJets2Lep.at(1)->bch_corr_jet, cutnumber_Ex, 1.);
    h_2j_j1_bch_corr_jet->Fill(m_signalJets2Lep.at(1)->bch_corr_jet, cutnumber_Ex, 1.);
  }
  if (nSignalJets >=3){
    if(isInEtaArea) h_Ex_2j_j2_pt ->Fill(m_signalJets2Lep.at(2)->Pt(), cutnumber_Ex, 1.);
    h_2j_j2_pt ->Fill(m_signalJets2Lep.at(2)->Pt(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_eta->Fill(m_signalJets2Lep.at(2)->Eta(), cutnumber_Ex, 1.);
    h_2j_j2_eta->Fill(m_signalJets2Lep.at(2)->Eta(), cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_phi->Fill( m_signalJets2Lep.at(2)->Phi(), cutnumber_Ex, 1.);
    h_2j_j2_phi->Fill( m_signalJets2Lep.at(2)->Phi(), cutnumber_Ex, 1.);
    
    if(isInEtaArea) h_Ex_2j_j2_jvf->Fill(m_signalJets2Lep.at(2)->jvf, cutnumber_Ex, 1.); 
    h_2j_j2_jvf->Fill(m_signalJets2Lep.at(2)->jvf, cutnumber_Ex, 1.); 
    if(isInEtaArea) h_Ex_2j_j2_detEta->Fill(m_signalJets2Lep.at(2)->detEta, cutnumber_Ex, 1.);
    h_2j_j2_detEta->Fill(m_signalJets2Lep.at(2)->detEta, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_emfrac->Fill(m_signalJets2Lep.at(2)->emfrac, cutnumber_Ex, 1.);
    h_2j_j2_emfrac->Fill(m_signalJets2Lep.at(2)->emfrac, cutnumber_Ex, 1.);

    if(isInEtaArea) h_Ex_2j_j2_sv0->Fill(m_signalJets2Lep.at(2)->sv0, cutnumber_Ex, 1.);
    h_2j_j2_sv0->Fill(m_signalJets2Lep.at(2)->sv0, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_combNN->Fill(m_signalJets2Lep.at(2)->combNN, cutnumber_Ex, 1.);
    h_2j_j2_combNN->Fill(m_signalJets2Lep.at(2)->combNN, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_mv1->Fill(m_signalJets2Lep.at(2)->mv1, cutnumber_Ex, 1.);
    h_2j_j2_mv1->Fill(m_signalJets2Lep.at(2)->mv1, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_jfit_mass->Fill(m_signalJets2Lep.at(2)->jfit_mass, cutnumber_Ex, 1.);
    h_2j_j2_jfit_mass->Fill(m_signalJets2Lep.at(2)->jfit_mass, cutnumber_Ex, 1.);
    if(isInEtaArea) h_Ex_2j_j2_bch_corr_jet->Fill(m_signalJets2Lep.at(2)->bch_corr_jet, cutnumber_Ex, 1.);
    h_2j_j2_bch_corr_jet->Fill(m_signalJets2Lep.at(2)->bch_corr_jet, cutnumber_Ex, 1.);			    
  }
    
  if(isInEtaArea) h_Ex_2j_mlj->Fill(Mlj_2j_EM, cutnumber_Ex, 1.);
  h_2j_mlj->Fill(Mlj_2j_EM, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mlj_el->Fill(Mlj_2j_EM_el, cutnumber_Ex, 1.);
  h_2j_mlj_el->Fill(Mlj_2j_EM_el, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_mlj_mu->Fill(Mlj_2j_EM_mu, cutnumber_Ex, 1.);
  h_2j_mlj_mu->Fill(Mlj_2j_EM_mu, cutnumber_Ex, 1.);
  if(isInEtaArea) h_Ex_2j_Nj->Fill(m_signalJets2Lep.size(), cutnumber_Ex, 1.);
  h_2j_Nj->Fill(m_signalJets2Lep.size(), cutnumber_Ex, 1.);  



}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_excess::SlaveTerminate()
{
  
  // SusyNtAna::Terminate();
  if(makeNTuple) closeTupleMaker();
  if(m_dbg) cout << "TSelector_SusyNtuple_excess::Terminate" << endl;
  cout << "sample_identifier= " << sample_identifier << endl;

  if(m_writeOut) {
    out.close();
  }
    

 
  
    TString outputfile;

    if(sample_identifier == 169471)outputfile="histos_ZN_WW_n0150_excessStudy_";
    if(sample_identifier == 126988)outputfile="histos_ZN_WWPlusJets_n0150_excessStudy_";
    if(sample_identifier == 129477)outputfile="histos_ZN_ZV_n0150_excessStudy_";
    
    if(sample_identifier == 116600)outputfile="histos_ZN_ZZ_n0150_excessStudy_";
    if(sample_identifier == 108346)outputfile="histos_ZN_ttbarWtop_n0150_excessStudy_";
    
//     if(sample_identifier == 110805) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split1_excessStudy_";
//     if(sample_identifier == 117671) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split2_excessStudy_";    
//     if(sample_identifier == 173041)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split3_excessStudy_";           
//     if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split4_excessStudy_"; 
    
    if(sample_identifier == 147105)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split1_excessStudy_";    
    if(sample_identifier == 147123)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split2_excessStudy_";    
    if(sample_identifier == 147771)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split3_excessStudy_";    
    if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split4_excessStudy_";    
    
    
    
    if(sample_identifier == 160155)outputfile="histos_ZN_Higgs_n0150_excessStudy_";
    
    if(sample_identifier == 157816)outputfile="histos_ZN_VVtotautauqq_n0150_excessStudy_";
    
    if(sample_identifier == 126893)outputfile="histos_cutflow_126893_TSelector_n0150_excessStudy_";
    if(sample_identifier == 176576)outputfile="histos_cutflow_176576_TSelector_n0150_excessStudy_";
    if(sample_identifier == 177501)outputfile="histos_ZN_177501_n0150_excessStudy_";
    if(sample_identifier == 177502)outputfile="histos_ZN_177502_n0150_excessStudy_";
    if(sample_identifier == 177503)outputfile="histos_ZN_177503_n0150_excessStudy_";
    if(sample_identifier == 177504)outputfile="histos_ZN_177504_n0150_excessStudy_";
    if(sample_identifier == 177505)outputfile="histos_ZN_177505_n0150_excessStudy_";
    if(sample_identifier == 177506)outputfile="histos_ZN_177506_n0150_excessStudy_";
    if(sample_identifier == 177507)outputfile="histos_ZN_177507_n0150_excessStudy_";
    if(sample_identifier == 177508)outputfile="histos_ZN_177508_n0150_excessStudy_";
    if(sample_identifier == 177509)outputfile="histos_ZN_177509_n0150_excessStudy_";
    if(sample_identifier == 177510)outputfile="histos_ZN_177510_n0150_excessStudy_";
    if(sample_identifier == 177511)outputfile="histos_ZN_177511_n0150_excessStudy_";
    if(sample_identifier == 177512)outputfile="histos_ZN_177512_n0150_excessStudy_";
    if(sample_identifier == 177513)outputfile="histos_ZN_177513_n0150_excessStudy_";
    if(sample_identifier == 177514)outputfile="histos_ZN_177514_n0150_excessStudy_";
    if(sample_identifier == 177515)outputfile="histos_ZN_177515_n0150_excessStudy_";
    if(sample_identifier == 177516)outputfile="histos_ZN_177516_n0150_excessStudy_";
    if(sample_identifier == 177517)outputfile="histos_ZN_177517_n0150_excessStudy_";
    if(sample_identifier == 177518)outputfile="histos_ZN_177518_n0150_excessStudy_";
    if(sample_identifier == 177519)outputfile="histos_ZN_177519_n0150_excessStudy_";
    if(sample_identifier == 177520)outputfile="histos_ZN_177520_n0150_excessStudy_";
    if(sample_identifier == 177521)outputfile="histos_ZN_177521_n0150_excessStudy_";
    if(sample_identifier == 177522)outputfile="histos_ZN_177522_n0150_excessStudy_";
    if(sample_identifier == 177523)outputfile="histos_ZN_177523_n0150_excessStudy_";
    if(sample_identifier == 177524)outputfile="histos_ZN_177524_n0150_excessStudy_";
    if(sample_identifier == 177525)outputfile="histos_ZN_177525_n0150_excessStudy_";
    if(sample_identifier == 177526)outputfile="histos_ZN_177526_n0150_excessStudy_";
    if(sample_identifier == 177527)outputfile="histos_ZN_177527_n0150_excessStudy_";

    
    outputfile="histos_excess_EM_fake_MyEvents_Muons_E_x_";
    

    char buffer[10];
    sprintf(buffer, "%d", isys);
    printf("%s\n", buffer);
//     system("pause");
string str;
// string str1 = "histos_ZN_tauveto_signal_";
str.append(outputfile);
str.append(buffer);
string str2 = ".root";
str.append(str2);
cout <<"str= " << str << endl;

   TString outputfilename = str;
   TFile* output_file = new TFile(outputfilename, "recreate") ;//update or recreate?
   cout << "TFile created" << endl;
   output_file->cd();

//    writeHistos();
   writeHistos_Excess();
   if(calcSysUncert) writeHistos_sysUncert();
//     cout << "histos written" << endl;
   output_file->Write() ;
   cout << "outputfile written" << endl;
   output_file->Close();
   cout << "closed" << endl;
    
// }
}
/*--------------------------------------------------------------------------------*/
// The Terminate() function is the last function to be called
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_excess::Terminate()
{
//   closeTupleMaker();
 
}