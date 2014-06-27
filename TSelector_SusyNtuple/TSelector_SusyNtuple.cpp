#include <iomanip>
#include "TCanvas.h"
#include "TFile.h"
#include "TChainElement.h"

#include "TSelector_SusyNtuple.hpp"
#include "histos_WH_analysis.C"
#include <string>
#include <strstream>
using namespace std;
using namespace Susy;
// using FourMom;

/*--------------------------------------------------------------------------------*/
// TSelector_SusyNtuple Constructor
/*--------------------------------------------------------------------------------*/
TSelector_SusyNtuple::TSelector_SusyNtuple() :
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
void TSelector_SusyNtuple::Begin(TTree * /*tree*/)
{

  n0150BugFix = true;
  TString option = GetOption();
  SysSetting = NtSys_NOM;
  SysSettingBTag = BTag_NOM;
  qflipSysUncertType = 0;
  SFUncertType = 0;
  SysSettingFake = SusyMatrixMethod::SYS_NOM;
  SysSettingPileup = MCWeighter::Sys_NOM;
  isys = 0;
//   if(option.Contains("NtSys_NOM"              ) ){SysSetting = NtSys_NOM;                                isys = 0 ; }
//   else if(option.Contains("NtSys_EES_Z_UP"    ) ){SysSetting = NtSys_EES_Z_UP;                           isys = 1 ; }
//   else if(option.Contains("NtSys_EES_Z_DN"    ) ){SysSetting = NtSys_EES_Z_DN;                           isys = 2 ; }
//   else if(option.Contains("NtSys_EES_MAT_UP"  ) ){SysSetting = NtSys_EES_MAT_UP;                         isys = 3 ; }
//   else if(option.Contains("NtSys_EES_MAT_DN"  ) ){SysSetting = NtSys_EES_MAT_DN;                         isys = 4 ; }
//   else if(option.Contains("NtSys_EES_PS_UP"   ) ){SysSetting = NtSys_EES_PS_UP;                          isys = 5 ; }
//   else if(option.Contains("NtSys_EES_PS_DN"   ) ){SysSetting = NtSys_EES_PS_DN;                          isys = 6 ; }
//   else if(option.Contains("NtSys_EES_LOW_UP"  ) ){SysSetting = NtSys_EES_LOW_UP;                         isys = 7 ; }
//   else if(option.Contains("NtSys_EES_LOW_DN"  ) ){SysSetting = NtSys_EES_LOW_DN;                         isys = 8 ; }
//   else if(option.Contains("NtSys_EER_UP"      ) ){SysSetting = NtSys_EER_UP;                             isys = 9 ; }
//   else if(option.Contains("NtSys_EER_DN"      ) ){SysSetting = NtSys_EER_DN;                             isys = 10; }
//   else if(option.Contains("NtSys_MS_UP"       ) ){SysSetting = NtSys_MS_UP;                              isys = 11; }
//   else if(option.Contains("NtSys_MS_DN"       ) ){SysSetting = NtSys_MS_DN;                              isys = 12; }
//   else if(option.Contains("NtSys_ID_UP"       ) ){SysSetting = NtSys_ID_UP;                              isys = 13; }
//   else if(option.Contains("NtSys_ID_DN"       ) ){SysSetting = NtSys_ID_DN;                              isys = 14; }
//   else if(option.Contains("NtSys_JES_UP"      ) ){SysSetting = NtSys_JES_UP;                             isys = 15; }
//   else if(option.Contains("NtSys_JES_DN"      ) ){SysSetting = NtSys_JES_DN;                             isys = 16; }
//   else if(option.Contains("NtSys_JER"	      ) ){SysSetting = NtSys_JER;                                isys = 17; }
//   else if(option.Contains("NtSys_SCALEST_UP"  ) ){SysSetting = NtSys_SCALEST_UP;                         isys = 18; }
//   else if(option.Contains("NtSys_SCALEST_DN"  ) ){SysSetting = NtSys_SCALEST_DN;                         isys = 19; }
//   else if(option.Contains("NtSys_RESOST"      ) ){SysSetting = NtSys_RESOST;                             isys = 20; }
//   else if(option.Contains("NtSys_TRIGSF_EL_UP") ){SysSetting = NtSys_TRIGSF_EL_UP;                       isys = 21; }
//   else if(option.Contains("NtSys_TRIGSF_EL_DN") ){SysSetting = NtSys_TRIGSF_EL_DN;                       isys = 22; }
//   else if(option.Contains("NtSys_TRIGSF_MU_UP") ){SysSetting = NtSys_TRIGSF_MU_UP;                       isys = 23; }
//   else if(option.Contains("NtSys_TRIGSF_MU_DN") ){SysSetting = NtSys_TRIGSF_MU_DN;                       isys = 24; }
//   else if(option.Contains("NtSys_TES_UP"      ) ){SysSetting = NtSys_TES_UP;                             isys = 25; }
//   else if(option.Contains("NtSys_TES_DN"      ) ){SysSetting = NtSys_TES_DN;                             isys = 26; }
//   
//   else if(option.Contains("BTag_BJet_DN"      ) ) {SysSettingBTag = BTag_BJet_DN;                        isys = 27; }
//   else if(option.Contains("BTag_CJet_DN"      ) ) {SysSettingBTag = BTag_CJet_DN;                        isys = 28; }
//   else if(option.Contains("BTag_LJet_DN"      ) ) {SysSettingBTag = BTag_LJet_DN;                        isys = 29; }
//   else if(option.Contains("BTag_BJet_UP"      ) ) {SysSettingBTag = BTag_BJet_UP;                        isys = 30; }
//   else if(option.Contains("BTag_CJet_UP"      ) ) {SysSettingBTag = BTag_CJet_UP;                        isys = 31; }
//   else if(option.Contains("BTag_LJet_UP"      ) ) {SysSettingBTag = BTag_LJet_UP;                        isys = 32; }
//   else if(option.Contains("BKGMETHOD_UP"      ) ) {qflipSysUncertType = 1;                               isys = 33; }
//   else if(option.Contains("BKGMETHOD_DN"      ) ) {qflipSysUncertType = -1;                              isys = 34; }
//   else if(option.Contains("SYS_EL_RE_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_RE_UP  ;    isys = 35; }
//   else if(option.Contains("SYS_EL_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_RE_DOWN;    isys = 36; }
//   else if(option.Contains("SYS_EL_FR_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_FR_UP  ;    isys = 37; }
//   else if(option.Contains("SYS_EL_FR_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_EL_FR_DOWN;    isys = 38; }
//   else if(option.Contains("SYS_MU_RE_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_UP  ;    isys = 39; }
//   else if(option.Contains("SYS_MU_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_DOWN;    isys = 40; }
//   else if(option.Contains("SYS_MU_FR_UP"      ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_FR_UP  ;    isys = 41; }
//   else if(option.Contains("SYS_MU_RE_DOWN"    ) ) {SysSettingFake = SusyMatrixMethod::SYS_MU_RE_DOWN;    isys = 42; }
//   else if(option.Contains("el_eff_up"         ) ) {SFUncertType = 1;                                     isys = 43; }
//   else if(option.Contains("el_eff_dn"         ) ) {SFUncertType = 2;                                     isys = 44; }
//   else if(option.Contains("mu_eff_up"         ) ) {SFUncertType = 3;                                     isys = 45; }
//   else if(option.Contains("mu_eff_dn"         ) ) {SFUncertType = 4;                                     isys = 46; }
//   else if(option.Contains("Sys_PILEUP_UP"     ) ) {SysSettingPileup = MCWeighter::Sys_PILEUP_UP;         isys = 47; }
//   else if(option.Contains("Sys_PILEUP_DN"     ) ) {SysSettingPileup = MCWeighter::Sys_PILEUP_DN;         isys = 48; }  
  
  
  cout << "SysSettingBTag= " << SysSettingBTag << " SysSetting= " << SysSetting << " isys= " << isys << endl;

}
void TSelector_SusyNtuple::SlaveBegin(TTree* /*tree*/)
{
  
  calcSysUncert = true;
  makeNTuple = false;
  tuple_file = "/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/SusySel_177504_05_05_2014.root";
  defineHistos();
  if(calcSysUncert) defineHistos_sysUncert();

  SusyNtAna::Begin(0);
//   m_susyObj.initialize(nt.evt()->isMC);

  

  setSelectTaus(true);
  setDoIP(true);

  m_trigObjWithoutRU = new DilTrigLogic("Moriond",false/*No Reweight Utils!*/);
  
  cout << "initialize chargeFlip tool" << endl;
  
  m_chargeFlip.initialize("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/ChargeFlip/data/d0_new2d_chargeflip_map_scale_with_mc_last_ptbin.root");
  
  bool use2dparametrization = true;
  SusyMatrixMethod::RATE_PARAM pm = (use2dparametrization ? SusyMatrixMethod::PT_ETA : SusyMatrixMethod::PT);
  m_matrix = new SusyMatrixMethod::DiLeptonMatrixMethod();
  m_matrix->configure("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/SusyMatrixMethod/data/FinalFakeHist_Apr_10.root", pm, pm, pm, pm);
  
  if(makeNTuple) initTupleMaker(tuple_file, "SusySel");
//   string xsecFileName  = gSystem->ExpandPathName("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/SUSYTools/data/susy_crosssections_8TeV.txt");
  m_susyXsec = new SUSY::CrossSectionDB("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/SUSYTools/data/mc12_8TeV/Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA.txt");
  
}



Bool_t TSelector_SusyNtuple::Process(Long64_t entry)
{
  
  double Zwindow = 20.;
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
    calcFakeContribution = true;
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
    if(nt.evt()->event == 1033189) sample_identifier = 10001; //Egamma 1
    if(nt.evt()->event == 1362322) sample_identifier = 10002; //Egamma 2
    if(nt.evt()->event == 9837079) sample_identifier = 10003; //Egamma 3
    if(nt.evt()->event == 38897454) sample_identifier = 10004; //Egamma 4
    if(nt.evt()->event == 55212803) sample_identifier = 10005; //Egamma 5
    if(nt.evt()->event == 228985598) sample_identifier = 10006; //Egamma 6

    if(nt.evt()->event == 1708601) sample_identifier = 20001; //Muons 1
    if(nt.evt()->event == 887022) sample_identifier = 20002; //Muons 2
    if(nt.evt()->event == 787758) sample_identifier = 20003; //Muons 3
    if(nt.evt()->event == 19724863) sample_identifier = 20004; //Muons 4
    if(nt.evt()->event == 48008265) sample_identifier = 20005; //Muons 5
    if(nt.evt()->event == 11336195) sample_identifier = 20006; //Muons 6
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
//     if(m_signalLeptons.size()>1){
//       double weight= SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap);
//       unsigned int run(nt.evt()->run), event(nt.evt()->event);
//       LeptonVector anyLep(getAnyElOrMu(nt));
//       LeptonVector lowPtLep(subtract_vector(anyLep, m_baseLeptons)); // caveat: spurious sigLep dupl.
//       const Lepton *l0 = m_signalLeptons[0];
//       const Lepton *l1 = m_signalLeptons[1];
//       if(makeNTuple) fillTupleMaker(weight, run, event, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep);
//     }
    TauVector preTaus = getPreTaus(&nt, SysSetting);
    h_NpreTaus->Fill(preTaus.size(), 14, weight_ALL_EE);
  //////////////////////////// EE //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //calculate normal contribution with signal leptons:
    if(m_baseElectrons.size()==2){
      cutnumber = 15.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE); //pass category
      
      bool passEE = false;
      Electron* el0;
      Electron* el1;
      LeptonVector leptons;
      ElectronVector electrons;
      TLorentzVector el0_TLV, el1_TLV;

      if(m_signalElectrons.size()==2){
	passEE = true;
      
	el0 = (m_signalElectrons.at(0)->Pt() > m_signalElectrons.at(1)->Pt()) ? m_signalElectrons.at(0) : m_signalElectrons.at(1);
	el1 = (m_signalElectrons.at(0)->Pt() > m_signalElectrons.at(1)->Pt()) ? m_signalElectrons.at(1) : m_signalElectrons.at(0);
	
	leptons = m_signalLeptons;
	electrons = m_signalElectrons;
	
	el0_TLV.SetPtEtaPhiE(el0->Pt(), el0->eta ,el0->phi, el0->Pt()*cosh(el0->eta));
	el0_TLV.SetPtEtaPhiM(el0->Pt(), el0->eta ,el0->phi, el0->m);
	el1_TLV.SetPtEtaPhiE(el1->Pt(), el1->eta ,el1->phi, el1->Pt()*cosh(el1->eta));
	el1_TLV.SetPtEtaPhiM(el1->Pt(), el1->eta ,el1->phi, el1->m);
      }
	
  // make sure you take the baseline leptons:
	if (calcFakeContribution && m_baseElectrons.size()==2 ){
	  passEE = true;
	  leptons = m_baseLeptons;
	  electrons = m_baseElectrons;
	  el0 = (electrons.at(0)->Pt() > electrons.at(1)->Pt()) ? electrons.at(0) : electrons.at(1);
	  el1 = (electrons.at(0)->Pt() > electrons.at(1)->Pt()) ? electrons.at(1) : electrons.at(0);

	  el0_TLV.SetPtEtaPhiE(el0->Pt(), el0->eta ,el0->phi, el0->Pt()*cosh(el0->eta));
	  el0_TLV.SetPtEtaPhiM(el0->Pt(), el0->eta ,el0->phi, el0->m);
	  el1_TLV.SetPtEtaPhiE(el1->Pt(), el1->eta ,el1->phi, el1->Pt()*cosh(el1->eta));
	  el1_TLV.SetPtEtaPhiM(el1->Pt(), el1->eta ,el1->phi, el1->m);
	}

	if(passEE && m_signalTaus.size() == 0 && (el0->q * el1->q)<0){
	  
	  //time to calc weights:
	  //------------------------------------------------------------------------------------
	  //calc lepton SF:
	  float lep_SF_EE = 1.0;
// 	  if(nt.evt()->isMC) lep_SF_EE = el0->effSF * el1->effSF;	
	  if(nt.evt()->isMC) lep_SF_EE = getLeptonSF(leptons, SFUncertType);

	  //calc trigger weight:
	  float trigW_EE = 1.;
	  if(nt.evt()->isMC) trigW_EE = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, SysSetting);
	  //product of all weights, for SS and OS MC events:
	  weight_ALL_EE = (nt.evt()->isMC) ? weight_ALL_EE * lep_SF_EE * trigW_EE : 1; //consider pileup, xsec, lumi (as argument), MC eventWeight.
	  weight_ALL_EE *= getBTagWeight(nt.evt(), SysSettingBTag);
	  
	  h_NpreTaus->Fill(preTaus.size(), 15, weight_ALL_EE);
	  cutnumber = 16.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE); //pass nlep
	  
	  cutnumber = 17.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	  if(m_trigObjWithoutRU->passDilEvtTrig(leptons, m_met->Et, nt.evt())){ //valid pT region
	    cutnumber = 18.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);

	    if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){ //match to trigger (in MC not needed bc weighted)
	      cutnumber = 19.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	      if(!nt.evt()->isMC || CheckRealLeptons(electrons, m_signalMuons)){
		cutnumber = 20.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	  


		  
		  //calc charge flip weights:
		  //Note that the charge flip is only applied in SS region (ee or em) and only for MC events that are true OS.
		  //The charge flip changes both the lepton pt of the electron that charge flip and the change needs to be propagated to the met.
		  float chargeFlipWeight = 1.0;

		  //make a copy of electrons and MET which will eventually be changed by ChargeFlip tool:
		  ElectronVector electrons_SS;
		  Electron* el0_SS;
		  Electron* el1_SS;
		  el0_SS = (electrons.at(0)->Pt() > electrons.at(1)->Pt()) ? electrons.at(0) : electrons.at(1);
		  el1_SS = (electrons.at(0)->Pt() > electrons.at(1)->Pt()) ? electrons.at(1) : electrons.at(0);
		  TLorentzVector el0_SS_TLV(*el0_SS);
		  TLorentzVector el1_SS_TLV(*el1_SS);

		  TLorentzVector met_SS_TLV;
		  TVector2 met_SS_TVector2;
		  met_SS_TLV = m_met->lv();
		  met_SS_TVector2.Set(met_SS_TLV.Px(), met_SS_TLV.Py());

		  //if SS event, get ChargeFlipWeight and modify electron and met TLV:
		  int pdg0 = 11 * (-1) * el0->q; // Remember 11 = elec which has charge -1
		  int pdg1 = 11 * (-1) * el1->q;
		  if((el0->q * el1->q)<0 && nt.evt()->isMC){	
// 		    m_chargeFlip.setSeed(nt.evt()->event);
		    chargeFlip::eStatus map2use = chargeFlip::dataonly;
		    chargeFlipWeight = m_chargeFlip.OS2SS(pdg0, &el0_SS_TLV, pdg1, &el1_SS_TLV, 0, (!nt.evt()->isMC), map2use);
		    chargeFlipWeight*= m_chargeFlip.overlapFrac().first;	
		    el0_SS->pt = el0_SS_TLV.Pt(); el0_SS->resetTLV();
		    el1_SS->pt = el1_SS_TLV.Pt(); el1_SS->resetTLV();

		    if(el1_SS_TLV.Pt() > el0_SS_TLV.Pt()){
		      TLorentzVector el0_SS_buffer_TLV, el1_SS_buffer_TLV;
		      el0_SS_buffer_TLV = el1_SS_TLV;
		      el1_SS_buffer_TLV = el0_SS_TLV;
		      
		      el0_SS_TLV = el0_SS_buffer_TLV;
		      el1_SS_TLV = el1_SS_buffer_TLV;
		    }
		    //get changed MET and fill in TLorentzVector:
		    met_SS_TLV.SetPx(met_SS_TVector2.Px());
		    met_SS_TLV.SetPy(met_SS_TVector2.Py());	
		    met_SS_TLV.SetE(sqrt(pow(met_SS_TVector2.Px(),2) + pow(met_SS_TVector2.Py(),2)));

		  }
		  float weight_ALL_SS_EE = 1.0;
		  
		  weight_ALL_SS_EE = weight_ALL_EE * chargeFlipWeight; //multiply only SS weight by chargeFlipWeight
		  float METrel_SS = recalcMetRel(met_SS_TLV, el0_SS_TLV, el1_SS_TLV, m_signalJets2Lep, useForwardJets);
		  //if running on data for fake bg, instead of weights (pileup, xsec, eventweight, trigger, SF, btag, ...) use fakeWeight from SusyMatrixMethod
		  // only meaningful in SS SR
		  if(!nt.evt()->isMC && calcFakeContribution){
		      
		    weight_ALL_EE = getFakeWeight(m_baseLeptons, METrel_SS);
		    weight_ALL_SS_EE = weight_ALL_EE;
		  }
		  
		  calc_EE_variables(leptons, el0, el1, el0_SS_TLV, el1_SS_TLV, met_SS_TLV, signalJet0_TLV, signalJet1_TLV, useForwardJets, &nt, weight_ALL_EE, SysSetting, n0150BugFix);
		  calcJet_variables(met_SS_TLV);

		  //------------------------------------------------------------------------------------
		  //----------------------------------SR-SS-EE------------------------------------------
		  //------------------------------------------------------------------------------------
		  if(nt.evt()->isMC || (!nt.evt()->isMC && (el0->q * el1->q)>0)){ //MC: also take into account OS events by charge flip weight!
		  //------------------------------------------------------------------------------------
		    cutnumber = 21.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE); //SS cut: applied only on weighted events
// 		    cout << "run " << nt.evt()->run << " event " << nt.evt()->event << " ee pt0= " << el0->Pt() << " pt1= " << el1->Pt() << " weight= " << weight_ALL_SS_EE << endl;
  // 		  if(nt.evt()->event == 140871 || nt.evt()->event == 2697245){
  // 		    cout << "EE " << nt.evt()->event <<
  // 		    " total w= " << weight_ALL_EE << endl;
  // 		    << " SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)= " << SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)
  // 		    << " lep_SF_EE= " << lep_SF_EE 
  // 		    << " trigW_EE= " << trigW_EE 
  // 		    << " btag= " << getBTagWeight(nt.evt(), SysSettingBTag)
  // 		    << " chargeFlipWeight= " << chargeFlipWeight << endl;
  // 		  }
	
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      cutnumber = 22.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 23.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			
			//fill NTUPLE
			if(makeNTuple){
			  LeptonVector anyLep(getAnyElOrMu(nt, el0_SS, el1_SS));
			  LeptonVector lowPtLep(subtract_vector(anyLep, m_baseLeptons)); // caveat: spurious sigLep dupl.
			  if(nt.evt()->isMC){
			    const Lepton *l0 = m_signalLeptons[0];
			    const Lepton *l1 = m_signalLeptons[1];
    // 				cout << "nt.evt()->event= " << nt.evt()->event << endl;
			    const JetVector signalJets = m_signalJets2Lep;
			    fillTupleMaker(weight_ALL_SS_EE, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep, METrel_SS, 0., mllZcandImpact_EE);
			  }
			  if(calcFakeContribution){
			    const Lepton *l0 = m_baseLeptons[0];
			    const Lepton *l1 = m_baseLeptons[1];
			    fillTupleMaker(weight_ALL_SS_EE, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep, METrel_SS, 0., mllZcandImpact_EE);
			  }
			}			
			if((mllZcandImpact_EE > MZ+Zwindow || mllZcandImpact_EE < MZ-Zwindow)){
			cutnumber = 24.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
		      

			  if(nSignalJets >=1){
			    
			  //============================================
			  if(nSignalJets ==1){
			    cutnumber = 25.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			    if(el0_SS_TLV.Pt()>=20. && el1_SS_TLV.Pt()>=20. && ((el0_SS_TLV.Pt()>el1_SS_TLV.Pt() && el0_SS_TLV.Pt() >= 30.) || (el0_SS_TLV.Pt()<el1_SS_TLV.Pt() && el1_SS_TLV.Pt() >= 30.))){
			      

			      cutnumber = 26.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			      if((el0_SS_TLV + el1_SS_TLV).M() > MZ + 10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ - 10.){
				cutnumber = 27.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE); //ZVeto
				cutnumber = 28.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				cutnumber = 29.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				if(Mlj_EE < 90.){
				  cutnumber = 30.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				  if(HT_EE > 200.){			    
				    cutnumber = 31.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);		  
				    if(METrel_SS > 55.){
				      cutnumber = 32.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);		  
				      cutnumber = 33.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				      if(calcSysUncert) cutflow_EE_sysUncert->Fill(cutnumber, isys, weight_ALL_SS_EE);
				      
// 				      cout << nt.evt()->event << " isys= " << isys << " weight_ALL = " << weight_ALL << " lep_SF_EE = " << lep_SF_EE << " trigW_EE= " << trigW_EE <<  endl;
// 				      cout << "nominal trigger weight= " << m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM) << endl;
// 		weight_ALL_EE *= getBTagWeight(nt.evt(), SysSettingBTag);			cout << "isys= " << isys << "chargeFlipWeight= " << chargeFlipWeight << endl;
// 					cout << "isys= " << isys << "getBTagWeight(nt.evt(), SysSettingBTag)= " << getBTagWeight(nt.evt(), SysSettingBTag) << endl;
// 					cout << "isys= " << isys << "weight_ALL_SS_EE= " << weight_ALL_SS_EE << endl;
				    }
				  }
				}
			      }
			    }
			  }//end ==1 jets
	      //==================
			  if(nSignalJets >=2 && nSignalJets <=3){
			  cutnumber = 34.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);	

			  if(el0_SS_TLV.Pt()>=20. && el1_SS_TLV.Pt()>=20. && ((el0_SS_TLV.Pt()>el1_SS_TLV.Pt() && el0_SS_TLV.Pt() >= 30.) || (el0_SS_TLV.Pt()<el1_SS_TLV.Pt() && el1_SS_TLV.Pt() >= 30.))){

			    cutnumber = 35.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			    if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
			      cutnumber = 36.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE); //ZVeto
			      cutnumber = 37.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			      
			      if(mTmax_EE > 110.){
				cutnumber = 38.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				if(Mljj_EE < 120.){
				  cutnumber = 39.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				  cutnumber = 40.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				  if(METrel_EE>=30.){			    
				    cutnumber = 41.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				    if(calcSysUncert) cutflow_EE_sysUncert->Fill(cutnumber, isys, weight_ALL_SS_EE);
				    
// 				    cout << nt.evt()->event << " isys= " << isys << " weight_ALL = " << weight_ALL << " lep_SF_EE = " << lep_SF_EE << " trigW_EE= " << trigW_EE <<  endl;
// 				      cout << "nominal trigger weight= " << m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM) << endl;
// 		weight_ALL_EE *= getBTagWeight(nt.evt(), SysSettingBTag);			cout << "isys= " << isys << "chargeFlipWeight= " << chargeFlipWeight << endl;
// 					cout << "isys= " << isys << "getBTagWeight(nt.evt(), SysSettingBTag)= " << getBTagWeight(nt.evt(), SysSettingBTag) << endl;
// 					cout << "isys= " << isys << "weight_ALL_SS_EE= " << weight_ALL_SS_EE << endl;
				  }
				}
			      }
			    }
			  }
			}//end >=2 jets
		      } //end >=1 jets
		    //=========================================
		      }
		    }
		  }
		  
		  
		  
		  
		  
		  
		  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		  
		  
		      
		      if(numberOfFJets(m_signalJets2Lep) == 0){
			if(numberOfCBJets(m_signalJets2Lep) == 0){
			  if(nSignalJets >=1){
			  //============================================
			  if(nSignalJets ==1){
			    if(el0_SS_TLV.Pt()>=20. && el1_SS_TLV.Pt()>=20. && ((el0_SS_TLV.Pt()>el1_SS_TLV.Pt() && el0_SS_TLV.Pt() >= 30.) || (el0_SS_TLV.Pt()<el1_SS_TLV.Pt() && el1_SS_TLV.Pt() >= 30.))){
			      cutnumber = 60.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			      if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
				if(Mlj_EE < 90.){
				  if(HT_EE > 200.){			    
				    if(METrel_SS > 55.){
				      cutnumber = 50.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				      if((mllZcandImpact_EE > MZ+Zwindow || mllZcandImpact_EE < MZ-Zwindow)){
					cutnumber = 51.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				      }
				      if((mllZcandImpact_EE > MZ+25. || mllZcandImpact_EE < MZ-25.)){
					cutnumber = 52.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				      }
				      
				    }
				  }
				}
			      }
			    }
			  }//end ==1 jets
	      //==================
			  if(nSignalJets >=2 && nSignalJets <=3){
			  if(el0_SS_TLV.Pt()>=20. && el1_SS_TLV.Pt()>=20. && ((el0_SS_TLV.Pt()>el1_SS_TLV.Pt() && el0_SS_TLV.Pt() >= 30.) || (el0_SS_TLV.Pt()<el1_SS_TLV.Pt() && el1_SS_TLV.Pt() >= 30.))){
			    cutnumber = 61.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
			    if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){			    
			      if(mTmax_EE > 110.){
				if(Mljj_EE < 120.){
				  if(METrel_EE>30.){			    
				    cutnumber = 53.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				    if((mllZcandImpact_EE > MZ+Zwindow || mllZcandImpact_EE < MZ-Zwindow)){
				      cutnumber = 54.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				    }
				    if((mllZcandImpact_EE > MZ+25. || mllZcandImpact_EE < MZ-25.)){
				      cutnumber = 55.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_SS_EE);
				    }
				  }
				}
			      }
			    }
			  }
			}//end >=2 jets
		      } //end >=1 jets
		    //=========================================
		      }
		    }
		  
		  //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		}//end SS
	      }
	    }
	  }
	}
      }
    

    
    //////////////////////////// MM //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(m_baseMuons.size()==2){
      cutnumber = 15.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //pass category
      Muon* mu0;
      Muon* mu1;
      LeptonVector leptons;
      MuonVector muons;
      TLorentzVector mu0_TLV, mu1_TLV;
      bool passMM = false;
      
      if(m_signalMuons.size()==2 ){
	
	passMM = true;
	mu0 = (m_signalMuons.at(0)->Pt() > m_signalMuons.at(1)->Pt()) ? m_signalMuons.at(0) : m_signalMuons.at(1);
	mu1 = (m_signalMuons.at(0)->Pt() > m_signalMuons.at(1)->Pt()) ? m_signalMuons.at(1) : m_signalMuons.at(0);
//         cout << "mu0->Pt()= " << mu0->Pt() << endl;
	leptons = m_signalLeptons;
	muons = m_signalMuons;
	
	mu0_TLV.SetPtEtaPhiE(mu0->Pt(), mu0->eta ,mu0->phi, mu0->Pt()*cosh(mu0->eta));
	mu0_TLV.SetPtEtaPhiM(mu0->Pt(), mu0->eta ,mu0->phi, mu0->m);
	mu1_TLV.SetPtEtaPhiE(mu1->Pt(), mu1->eta ,mu1->phi, mu1->Pt()*cosh(mu1->eta));
	mu1_TLV.SetPtEtaPhiM(mu1->Pt(), mu1->eta ,mu1->phi, mu1->m);
      }
	
  // calculate fake bg contribution with m_baseMuons, don't use info about m_signalMuons
      if(calcFakeContribution && m_baseMuons.size()==2 ){
	
	passMM = true;
	mu0 = (m_baseMuons.at(0)->Pt() > m_baseMuons.at(1)->Pt()) ? m_baseMuons.at(0) : m_baseMuons.at(1);
	mu1 = (m_baseMuons.at(0)->Pt() > m_baseMuons.at(1)->Pt()) ? m_baseMuons.at(1) : m_baseMuons.at(0);
	mu0_TLV.SetPtEtaPhiE(mu0->Pt(), mu0->eta ,mu0->phi, mu0->Pt()*cosh(mu0->eta));
	mu0_TLV.SetPtEtaPhiM(mu0->Pt(), mu0->eta ,mu0->phi, mu0->m);
	mu1_TLV.SetPtEtaPhiE(mu1->Pt(), mu1->eta ,mu1->phi, mu1->Pt()*cosh(mu1->eta));
	mu1_TLV.SetPtEtaPhiM(mu1->Pt(), mu1->eta ,mu1->phi, mu1->m);
	
	leptons = m_baseLeptons;
	muons = m_baseMuons;
      }
      if(passMM && fabs(mu0->Eta())<=2.4 && fabs(mu1->Eta())<=2.4  && (mu0->q * mu1->q)<0){
	//time to calc weights:
	//------------------------------------------------------------------------------------
	//calc lepton SF:
	float lep_SF_MM = 1.0;
// 	if(nt.evt()->isMC) lep_SF_MM = mu0->effSF * mu1->effSF;	
	if(nt.evt()->isMC) lep_SF_MM = getLeptonSF(leptons, SFUncertType);
	//calc trigger weight:
	float trigW_MM = 1.;
	if(nt.evt()->isMC) trigW_MM = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, SysSetting);
	//product of all weights:
	weight_ALL_MM = (nt.evt()->isMC) ? weight_ALL_MM * lep_SF_MM * trigW_MM: 1; //consider pileup, xsec, lumi (as argument), MC eventWeight.
	weight_ALL_MM *= getBTagWeight(nt.evt(), SysSettingBTag);
	//------------------------------------------------------------------------------------
	calc_MM_variables(leptons, mu0, mu1, mu0_TLV, mu1_TLV, m_met->lv(), signalJet0_TLV, signalJet1_TLV, useForwardJets, &nt, weight_ALL_MM, SysSetting, n0150BugFix);
	calcJet_variables(m_met->lv());
	h_NpreTaus->Fill(preTaus.size(), 16, weight_ALL_MM);
	cutnumber = 16.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //pass nlep
// 	cout << "cutnumber= " <<  cutnumber << endl;
	if(m_signalTaus.size() == 0){
	  cutnumber = 17.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	  
	  if(m_trigObjWithoutRU->passDilEvtTrig(m_baseLeptons, m_met->Et, nt.evt())){ //valid pT region
	    cutnumber = 18.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	    if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){ //match to trigger
	      cutnumber = 19.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
//               cout << "cutnumber= " <<  cutnumber << endl;
	      if(!nt.evt()->isMC || CheckRealLeptons(m_signalElectrons, muons)){
		cutnumber = 20.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 		cout << "cutnumber= " <<  cutnumber << endl;
		// only meaningful in SS SR
		if(!nt.evt()->isMC && calcFakeContribution){
		  susy::fake::Region MatrixMethodRegion;
		  if(nSignalJets ==1) MatrixMethodRegion = susy::fake::CR_SSInc1j;
		  if(nSignalJets >=2 && nSignalJets <=3) MatrixMethodRegion = susy::fake::CR_SSInc1j;
		  weight_ALL_MM = getFakeWeight(m_baseLeptons, METrel);
		}

	


  //------------------------------------------------------------------------------------
  //----------------------------------SR-SS-MM------------------------------------------
  //------------------------------------------------------------------------------------
		  if(mu0->q*mu1->q>0){
		    cutnumber = 21.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //SS cut: for MM applied only on SS events.
  // 		  cout << "MM " << nt.evt()->event
  // 		  << " total w= " << weight_ALL_MM
  // 		  << " SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)= " << SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap)
  // 		  << " lep_SF_MM= " << lep_SF_MM 
  // 		  << " trigW_MM= " << trigW_MM 
  // 		  << " btag= " << getBTagWeight(nt.evt(), SysSettingBTag) << endl;
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      cutnumber = 22.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 23.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			if(makeNTuple){
			  LeptonVector anyLep(getAnyElOrMu(nt, mu0, mu1));
			  LeptonVector lowPtLep(subtract_vector(anyLep, m_baseLeptons)); // caveat: spurious sigLep dupl.
			  if(nt.evt()->isMC){
			    const Lepton *l0 = m_signalLeptons[0];
			    const Lepton *l1 = m_signalLeptons[1];
			    if(makeNTuple) fillTupleMaker(weight_ALL_MM, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep, METrel_MM, mllZcandImpact_MM, 0.);
			  }
			  if(calcFakeContribution){
			    const Lepton *l0 = m_baseLeptons[0];
			    const Lepton *l1 = m_baseLeptons[1];
			    if(makeNTuple) fillTupleMaker(weight_ALL_MM, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep, METrel_MM, mllZcandImpact_MM, 0.);
			  }
			}			
			if((mllZcandImpact_MM > MZ+Zwindow || mllZcandImpact_MM < MZ-Zwindow)){
			cutnumber = 24.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			  
			  if(nSignalJets >=1){
			    //===============================================================================================================================		  
			    if(nSignalJets ==1){
			      cutnumber = 25.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 			      if(nt.evt()->event == 96686) cout << nt.evt()->event << " weight_ALL_MM= " << weight_ALL_MM << " trigW_MM= " <<  trigW_MM << " mu0_TLV.Pt()= " << mu0_TLV.Pt() << " mu1_TLV.Pt()= " << mu1_TLV.Pt() << endl;
			      
			      if(mu0_TLV.Pt()>=20. && mu1_TLV.Pt()>=20. && ((mu0_TLV.Pt()>mu1_TLV.Pt() && mu0_TLV.Pt() >= 30.) || (mu0_TLV.Pt()<mu1_TLV.Pt() && mu1_TLV.Pt() >= 30.))){
				cutnumber = 26.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				cutnumber = 27.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //ZVeto
// 				if(nt.evt()->event == 96686) cout << cutnumber << endl;
				if(DeltaEtall_MM < 1.5){
				  cutnumber = 28.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 				  if(nt.evt()->event == 96686) cout << cutnumber << " mTmax_MM= " << mTmax_MM << endl;
				   
				  if(mTmax_MM > 110.){
				    cutnumber = 29.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 				    if(nt.evt()->event == 96686) cout << cutnumber << endl;
				    if(Mlj_MM < 90.){
				      cutnumber = 30.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 				      if(nt.evt()->event == 96686) cout << cutnumber << endl;
				  
				      if(HT_MM > 200.){
					cutnumber = 31.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
// 					if(nt.evt()->event == 96686) cout << cutnumber << endl;
					if(calcSysUncert) cutflow_MM_sysUncert->Fill(cutnumber, isys, weight_ALL_MM);
// 					if(nt.evt()->event == 96686) cout << nt.evt()->event << " weight_ALL_MM= " << weight_ALL_MM << " trigW_MM= " <<  trigW_MM << " mu0_TLV.Pt()= " << mu0_TLV.Pt() << " mu1_TLV.Pt()= " << mu1_TLV.Pt() << endl;
					
				      }
				    }
				  }
				}
			      }
			    }//end ==1 jets
			    //===============================================================================================================================		  
			    if(nSignalJets >=2 && nSignalJets <=3){
			      if(nt.evt()->event == 451609){
				cout << "event 451609 mcid " << nt.evt()->mcChannel << 
				" mll = " << (mu0_TLV + mu1_TLV).M() << 
				" mu0->q= " << mu0->q << 
				" mu0_TLV.Pt()= " << mu0_TLV.Pt() << 
				" mu0_TLV.Eta()= " << mu0_TLV.Eta() <<
				" mu0_TLV.Phi()= " << mu0_TLV.Phi() << 
				
				" mu1->q= " << mu1->q << 
				" mu1_TLV.Pt()= " << mu1_TLV.Pt() << 
				" mu1_TLV.Eta()= " << mu1_TLV.Eta() <<
				" mu1_TLV.Phi()= " << mu1_TLV.Phi() << endl;
			      }
			      cutnumber = 34.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			      if(mu0_TLV.Pt()>=30. && mu1_TLV.Pt()>=30. && ((mu0_TLV.Pt()>mu1_TLV.Pt() && mu0_TLV.Pt() >= 30.) || (mu0_TLV.Pt()<mu1_TLV.Pt() && mu1_TLV.Pt() >= 30.))){
				cutnumber = 35.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				
				cutnumber = 36.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //ZVeto
				if(DeltaEtall_MM<1.5){
				  cutnumber = 37.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				  cutnumber = 38.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				  
				  if(Mljj_MM < 120.){
				    cutnumber = 39.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				    if(HT_MM >= 200.){
				      cutnumber = 40.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);	
				      if(calcSysUncert) cutflow_MM_sysUncert->Fill(cutnumber, isys, weight_ALL_MM);
				    }
				  }
				}
			      }
			    }//end >=2 jets      
			    }//end >=1 jets
			  }
			}
		      }
		      
		      //&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		      if(numberOfFJets(m_signalJets2Lep) == 0){
			if(numberOfCBJets(m_signalJets2Lep) == 0){
			  if(nSignalJets >=1){
			    //===============================================================================================================================		  
			    if(nSignalJets ==1){
			      if(mu0_TLV.Pt()>=20. && mu1_TLV.Pt()>=20. && ((mu0_TLV.Pt()>mu1_TLV.Pt() && mu0_TLV.Pt() >= 30.) || (mu0_TLV.Pt()<mu1_TLV.Pt() && mu1_TLV.Pt() >= 30.))){
				cutnumber = 60.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
				if(DeltaEtall_MM < 1.5){
				  if(mTmax_MM > 110.){
				    if(Mlj_MM < 90.){
				      if(HT_MM > 200.){
					cutnumber = 50.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
					if((mllZcandImpact_MM > MZ+Zwindow || mllZcandImpact_MM < MZ-Zwindow)){
					  cutnumber = 51.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
					}
					if((mllZcandImpact_MM > MZ+25 || mllZcandImpact_MM < MZ-25)){
					  cutnumber = 52.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
					}					
				      }
				    }
				  }
				}
			      }
			    }//end ==1 jets
			    //===============================================================================================================================		  
			    if(nSignalJets >=2 && nSignalJets <=3){
			      if(mu0_TLV.Pt()>=30. && mu1_TLV.Pt()>=30. && ((mu0_TLV.Pt()>mu1_TLV.Pt() && mu0_TLV.Pt() >= 30.) || (mu0_TLV.Pt()<mu1_TLV.Pt() && mu1_TLV.Pt() >= 30.))){
			      cutnumber = 61.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
			      if(DeltaEtall_MM<1.5){
				if(Mljj_MM < 120.){
				  if(HT_MM >= 200.){
				    cutnumber = 53.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
				    if((mllZcandImpact_MM > MZ+Zwindow || mllZcandImpact_MM < MZ-Zwindow)){
				      cutnumber = 53.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
				    }
				    if((mllZcandImpact_MM > MZ+25. || mllZcandImpact_MM < MZ-25.)){
				      cutnumber = 54.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);				
				    }				    
				  }
				}
			      }
			    }
			  }//end >=2 jets      
			}//end >=1 jets
		      }
		    }
			//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		    } //end SS
		  }
		}
	      }
	    }
	  }
	}

    
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

    
      
    if(muons.size() == 1 && electrons.size() == 1 && fabs(mu->Eta())<=2.4  && el->q*mu->q<0 ){
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
	h_NpreTaus->Fill(preTaus.size(), 17, weight_ALL_EM);
	cutnumber = 16.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM); //pass nlep

      
	if(m_signalTaus.size() == 0){
	  cutnumber = 17.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
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
		  chargeFlipWeight = m_chargeFlip.OS2SS(pdg0, &el_SS_TLV, 13, &empty_TLV, 0, (!nt.evt()->isMC), map2use);
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
		  if(nSignalJets ==1) MatrixMethodRegion = susy::fake::CR_SSInc1j;
		  if(nSignalJets >=2 && nSignalJets <=3) MatrixMethodRegion = susy::fake::CR_SSInc1j;
		  weight_ALL_EM = getFakeWeight(m_baseLeptons, METrel_SS);
		  weight_ALL_SS_EM = weight_ALL_EM;
		}



  //------------------------------------------------------------------------------------
  //----------------------------------SR-SS1-EM------------------------------------------
  //------------------------------------------------------------------------------------
		if(nt.evt()->isMC || (!nt.evt()->isMC && (el->q*mu->q)>0)){
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
		  		  
		  if(numberOfFJets(m_signalJets2Lep) == 0){
		    cutnumber = 22.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
		    
		    if(numberOfCBJets(m_signalJets2Lep) == 0){
		      cutnumber = 23.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);		  
		      if(makeNTuple){
			LeptonVector anyLep(getAnyElOrMu(nt, el, mu));
			LeptonVector lowPtLep(subtract_vector(anyLep, m_baseLeptons)); // caveat: spurious sigLep dupl.
			if(nt.evt()->isMC){
			  const Lepton *l0 = m_signalLeptons[0];
			  const Lepton *l1 = m_signalLeptons[1];
			  fillTupleMaker(weight_ALL_SS_EM, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep,METrel_SS, mllZcandImpact_mu_EM, mllZcandImpact_el_EM);
			}
			if(calcFakeContribution){
			  const Lepton *l0 = m_baseLeptons[0];
			  const Lepton *l1 = m_baseLeptons[1];
			  fillTupleMaker(weight_ALL_SS_EM, nt.evt()->run, nt.evt()->event, nt.evt()->isMC, *l0, *l1, *m_met, lowPtLep, m_signalJets2Lep, METrel_SS, mllZcandImpact_mu_EM, mllZcandImpact_el_EM);
			}
		      }
// 		      cout << "mllZcandImpact_mu_EM= " << mllZcandImpact_mu_EM << " mllZcandImpact_el_EM= " << mllZcandImpact_el_EM << endl;
		      if((mllZcandImpact_mu_EM > MZ+Zwindow || mllZcandImpact_mu_EM < MZ-Zwindow) && (mllZcandImpact_el_EM > MZ+Zwindow || mllZcandImpact_el_EM < MZ-Zwindow)){
			cutnumber = 24.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
		    

			if(nSignalJets >=1){
			//------------------------------------------------------------------------------------
			if(nSignalJets ==1){
			  cutnumber = 25.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			  if(el_SS_TLV.Pt()>=30. && mu_TLV.Pt()>=30. && ((el_SS_TLV.Pt()>mu_TLV.Pt() && el_SS_TLV.Pt() >= 30.) || (el_SS_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
			    cutnumber = 26.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    cutnumber = 27.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM); //ZVeto
			    
			    if(DeltaEtall_EM < 1.5){
			      cutnumber = 28.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);				
			      if(mTmax_EM > 110){
				cutnumber = 29.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				if(Mlj_EM < 90.){
				  cutnumber = 30.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				  if(HT_EM > 200.){
				    cutnumber = 31.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    if(calcSysUncert) cutflow_EM_sysUncert->Fill(cutnumber, isys, weight_ALL_SS_EM);
				  }				 
				}
			      }
			    }
			  }
			}//end ==1jet
		  //------------------------------------------------------------------------------------
			if(nSignalJets >=2 && nSignalJets <=3){
			  cutnumber = 34.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			  if(el_SS_TLV.Pt()>=30. && mu_TLV.Pt()>=30. && ((el_SS_TLV.Pt()>mu_TLV.Pt() && el_SS_TLV.Pt() >= 30.) || (el_SS_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
			    cutnumber = 35.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    cutnumber = 36.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM); //ZVeto
			    if(DeltaEtall_EM < 1.5){
			      cutnumber = 37.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			      cutnumber = 38.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);				
			      
			      if(mTmax_EM >= 110.){
				cutnumber = 39.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				if(Mljj_EM < 120.){
				  cutnumber = 40.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				  if(HT_EM > 200.){	
				  cutnumber = 41.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				  if(calcSysUncert)cutflow_EM_sysUncert->Fill(cutnumber, isys, weight_ALL_SS_EM);
				  }
				}
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
		  
		    if(numberOfFJets(m_signalJets2Lep) == 0){		    
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			if(nSignalJets >=1){
			//------------------------------------------------------------------------------------
			if(nSignalJets ==1){
			  if(el_SS_TLV.Pt()>=30. && mu_TLV.Pt()>=30. && ((el_SS_TLV.Pt()>mu_TLV.Pt() && el_SS_TLV.Pt() >= 30.) || (el_SS_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
			    cutnumber = 60.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    if(DeltaEtall_EM < 1.5){
			      if(mTmax_EM > 110){
				if(Mlj_EM < 90.){
				  if(HT_EM > 200.){
				    cutnumber = 50.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    if((mllZcandImpact_mu_EM > MZ+Zwindow || mllZcandImpact_mu_EM < MZ-Zwindow) && (mllZcandImpact_el_EM > MZ+Zwindow || mllZcandImpact_el_EM < MZ-Zwindow)){
				      cutnumber = 51.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    }	
				    if((mllZcandImpact_mu_EM > MZ+25 || mllZcandImpact_mu_EM < MZ-25) && (mllZcandImpact_el_EM > MZ+25 || mllZcandImpact_el_EM < MZ-25)){
				      cutnumber = 52.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    }				    
				  }
				}
			      }
			    }
			  }
			}//end ==1jet
		  //------------------------------------------------------------------------------------
			if(nSignalJets >=2 && nSignalJets <=3){
			  if(el_SS_TLV.Pt()>=30. && mu_TLV.Pt()>=30. && ((el_SS_TLV.Pt()>mu_TLV.Pt() && el_SS_TLV.Pt() >= 30.) || (el_SS_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
			    cutnumber = 61.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
			    if(DeltaEtall_EM < 1.5){			    
			    if(Mljj_EM < 120.){
				if(HT_EM > 200.){
				  if(mTmax_EM > 110.){
				    cutnumber = 53.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    if((mllZcandImpact_mu_EM > MZ+Zwindow || mllZcandImpact_mu_EM < MZ-Zwindow) && (mllZcandImpact_el_EM > MZ+Zwindow || mllZcandImpact_el_EM < MZ-Zwindow)){
				      cutnumber = 54.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    }
				    if((mllZcandImpact_mu_EM > MZ+25 || mllZcandImpact_mu_EM < MZ-25) && (mllZcandImpact_el_EM > MZ+25 || mllZcandImpact_el_EM < MZ-25)){
				      cutnumber = 55.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_SS_EM);
				    }				    
				  }
				}
			      }
			    }
			  }
			}//end >=2 jets
		  //------------------------------------------------------------------------------------
		      }//end >=1 jets
		      }
		    }
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

bool TSelector_SusyNtuple::CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons){

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
bool TSelector_SusyNtuple::CheckChargeFlipElectrons(const ElectronVector& signal_electrons){
  
  for(uint i=0; i<signal_electrons.size(); i++){
Electron* signal_electron = signal_electrons.at(i);
if(signal_electron->isChargeFlip) return false;
// check if signal electron has no charge flip
  }
  return true;
  
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::getBTagWeight(const Event* evt, BTagSys SysSettingBTag)
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
bool TSelector_SusyNtuple::checkLeptonPt(const LeptonVector& leptons)
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
float TSelector_SusyNtuple::mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue) // Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/PhysicsTools.cxx#L197
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
float TSelector_SusyNtuple::calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, const JetVector &signalJets){
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
float TSelector_SusyNtuple::calcMeff(TLorentzVector met, const JetVector &signalJets){
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

float TSelector_SusyNtuple::calcMt(TLorentzVector _l, TLorentzVector _nu)
{
  float dphi = acos(cos(_l.Phi()-_nu.Phi()));
  return sqrt(2*_l.Pt()*_nu.Pt() * (1- cos(dphi)) );
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const JetVector& jets, bool useForward)
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
float TSelector_SusyNtuple::calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1)
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
float TSelector_SusyNtuple::calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1)
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
float TSelector_SusyNtuple::calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met)
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
float TSelector_SusyNtuple::calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type){
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
void TSelector_SusyNtuple::fillHistos_EE(int cutnumber, float weight){
  cutflow_EE->Fill(cutnumber,1.0);
  cutflow_EE_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple::fillHistos_MM(int cutnumber, float weight){
  cutflow_MM->Fill(cutnumber,1.0);
  cutflow_MM_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple::fillHistos_EM(int cutnumber, float weight){
  cutflow_EM->Fill(cutnumber,1.0);
  cutflow_EM_ALL->Fill(cutnumber, weight);
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::calcSumMv1(const JetVector &signalJets){
  
  //with or without leptons?
  
  float sumMv1 = 0.;
  for(uint j=0; j<signalJets.size(); ++j){
Jet* jet = signalJets.at(j);
sumMv1 += jet->mv1;
  }
  return sumMv1;
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::getFakeWeight(const LeptonVector &baseLeps, float metRel)
{

  if(baseLeps.size() != 2) return 0.0;

  uint nVtx = nt.evt()->nVtx;
  bool isMC = nt.evt()->isMC;
  
  susy::fake::Region region = susy::fake::CR_SSInc1j;
  SusyMatrixMethod::SYSTEMATIC sys = SusyMatrixMethod::SYS_NOM;
  
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
float TSelector_SusyNtuple::calc_D0(bool unbiased, const Lepton* lep)
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
bool TSelector_SusyNtuple::compareElecMomentum (Electron* e0, Electron* e1){ return (e0->Pt() > e1->Pt()); }

// /*--------------------------------------------------------------------------------*/
// ElectronVector TSelector_SusyNtuple::getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys)
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
// ElectronVector TSelector_SusyNtuple::getOverlapElectrons(SusyNtObject* susyNt, SusyNtSys sys)
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
bool TSelector_SusyNtuple::compareMuonMomentum (Muon* mu0, Muon* mu1){ return (mu0->Pt() > mu1->Pt()); }
/*--------------------------------------------------------------------------------*/
// MuonVector TSelector_SusyNtuple::getSoftMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
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
// MuonVector TSelector_SusyNtuple::getOverlapMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
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
bool TSelector_SusyNtuple::isCMSJet(const Susy::Jet* jet)
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
int TSelector_SusyNtuple::numberOfCMSJets(const JetVector& jets)
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
vector<TLorentzVector> TSelector_SusyNtuple::overlapRemoval(vector<TLorentzVector> objects_type1, vector<TLorentzVector> objects_type2, double dr, bool sameType, bool removeSoft) 
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

bool TSelector_SusyNtuple::doEventCleaning_andFillHistos(int flag, float weight_ALL_EE, float weight_ALL_MM, float weight_ALL_EM, SusyNtSys SysSetting, bool n0150BugFix)
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
bool TSelector_SusyNtuple::initTupleMaker(const std::string &outFilename, const std::string &treename)
{
    /*if(file_ && file_->IsOpen() && tree_) {
        cout<<"TupleMaker::init: already initialized"<<endl;
        return false;
    }
    else */return (initFile(outFilename) && initTree(treename));
}
//----------------------------------------------------------
bool TSelector_SusyNtuple::initFile(const std::string &outFilename)
{
    file_ = TFile::Open(outFilename.c_str(), "recreate");
    if(!file_) cout<<"TupleMaker::initFile('"<<outFilename<<"') : failed to create file"<<endl;
    cout << "init " << outFilename << endl;
    return (file_ && file_->IsOpen());
}
//----------------------------------------------------------
bool TSelector_SusyNtuple::initTree(const std::string &treename)
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
bool TSelector_SusyNtuple::initTreeBranches()
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
FourMom lepton2FourMom (Lepton *l)
{    
    return (  l && l->isMu()  ? FourMom().setMu(*l)
            : l && l->isEle() ? FourMom().setEl(*l)
            : FourMom());
}
//----------------------------------------------------------
FourMom jet2FourMom (Jet *j) { return (j ? FourMom().setJet(*j) : FourMom()); }
//----------------------------------------------------------
float half(int n) {
  return n / 2.;
}
Jet* JetTransformer(Jet *j) { return j;}
//----------------------------------------------------------
bool TSelector_SusyNtuple::fillTupleMaker(const double weight, const unsigned int run, const unsigned int event, const bool isMc,
                      const Susy::Lepton &l0, const Susy::Lepton &l1, const Susy::Met &met,
                      const LeptonVector &otherLeptons, const JetVector &jets, float METrel, float mllZcandImpact_mu, float mllZcandImpact_el)
// &jets: address of 'jets'
// Durch einen Zeiger auf die Konstante kann ihr Inhalt verändert werden. 
{
    bool someBytesWritten(false);
    if(tree_) {
// 	cout << "event= " << event;
        eventPars_.setWeight(weight).setRun(run).setEvent(event).setIsmc(isMc).setMetrel(METrel).setMllZcand_mu(mllZcandImpact_mu).setMllZcand_el(mllZcandImpact_el);
        l0.isMu() ? l0_.setMu(l0) : l0_.setEl(l0);
        l1.isMu() ? l1_.setMu(l1) : l1_.setEl(l1);
        met_.setMet(met);
        jets_.clear();
        lowptLepts_.clear();
        const LeptonVector &olps = otherLeptons;
// 	cout << "before transform jet2FourMom" << endl;
// 	std::vector<int> v1;
// 	std::vector<float> v2;
	
// 	std::transform(v1.begin(), v1.end(), std::back_inserter(v2), half);


	JetVector jets_buffer;
        std::transform(jets.begin(), jets.end(), std::back_inserter(jets_),       jet2FourMom);
// 	cout << "jets.size()= " << jets.size() << endl;
// 	std::vector<int> foo;
// 	std::vector<int> bar;
// 	const JetVector &jets_in;
// 	jets_in = jets;
// 	JetVector jets_out;
// 	std::transform(jets.begin(), jets.end(), std::back_inserter(jets_),       jet2FourMom);

// 	for(int i = 0; i < jets.size(); i++){
// 	  jets_.at(i) =  FourMom().setJet(*jets.at(i));
// 	}
// 	cout << " jets_.size()= " << jets_.size();
// 	if(jets_.size()>0) cout << "jet 0 " << jets_.at(0).px << endl;
// 	if(jets_.size()>1) cout << "jet 1 " << jets_.at(1).px << endl;
// 	if(jets_.size()>2) cout << "jet 2 " << jets_.at(2).px << endl;
// 	jets_ = jets_buffer;
// 	for(int i = 0; i < otherLeptons.size(); i++){
// 	  lowptLepts_.push_back(lepton2FourMom(otherLeptons.at(i)));
// 	}
// 	cout << "before transform lepton2FourMom" << endl;
        std::transform(olps.begin(), olps.end(), std::back_inserter(lowptLepts_), lepton2FourMom);
// 	cout << " lowptLepts_.size()= " << lowptLepts_.size() << endl;
// 	cout << "before someBytesWritten " << endl;
        someBytesWritten = (tree_->Fill()>0);
// 	cout << "tree_->Fill" << endl;
// 	jets_.clear();
    }
    return someBytesWritten;
}

/*--------------------------------------------------------------------------------*/
LeptonVector TSelector_SusyNtuple::getAnyElOrMu(SusyNtObject &susyNt, const Lepton *l0, const Lepton *l1)
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
bool TSelector_SusyNtuple::closeTupleMaker()
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
// SusyNtSys TSelector_SusyNtuple::returnSysUncertType(int isys){
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
// int TSelector_SusyNtuple::returnSysUncertNumber(SusyNtSys UncertType){
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
// int TSelector_SusyNtuple::returnSysUncertBTagNumber(BTagSys UncertType){
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
char *TSelector_SusyNtuple::GetID(Int_t type)
{
   return Form ("%d", type);
}

/*--------------------------------------------------------------------------------*/
// Debug event
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple::debugEvent()
{
  uint run = nt.evt()->run;
  uint evt = nt.evt()->event;
  //if(run==191139 && evt==140644832) return true;
  if(run==180164&&evt==24769) return true;

  return false;
}
/*--------------------------------------------------------------------------------*/


float TSelector_SusyNtuple::getLeptonSF(const LeptonVector& leptons, int SFUncertType)
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
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple::SlaveTerminate()
{
  
  // SusyNtAna::Terminate();

  if(m_dbg) cout << "TSelector_SusyNtuple::Terminate" << endl;
  cout << "sample_identifier= " << sample_identifier << endl;

  if(m_writeOut) {
    out.close();
  }
    

 
  
    TString outputfile;

    if(sample_identifier == 169471)outputfile="histos_ZN_WW_n0150_02_06_14";
    if(sample_identifier == 126988)outputfile="histos_ZN_WWPlusJets_n0150_02_06_14";
    if(sample_identifier == 179974)outputfile="histos_ZN_WZ_n0150_MZ20GeV";
    
    if(sample_identifier == 116600)outputfile="histos_ZN_ZZ_n0150_02_06_14";
    if(sample_identifier == 108346)outputfile="histos_ZN_ttbarWtop_n0150_02_06_14";
    
//     if(sample_identifier == 110805) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split1_02_06_14";
//     if(sample_identifier == 117671) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split2_02_06_14";    
//     if(sample_identifier == 173041)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split3_02_06_14";           
//     if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split4_02_06_14"; 
    
    if(sample_identifier == 147105)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split1_02_06_14";    
    if(sample_identifier == 147123)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split2_02_06_14";    
    if(sample_identifier == 147771)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split3_02_06_14";    
    if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split4_02_06_14";    
    
    
    
    if(sample_identifier == 160155)outputfile="histos_ZN_Higgs_n0150_02_06_14";
    
    if(sample_identifier == 157816)outputfile="histos_ZN_VVtotautauqq_n0150_02_06_14";
    
    if(sample_identifier == 126893)outputfile="histos_cutflow_126893_TSelector_n0150_02_06_14";
    if(sample_identifier == 176576)outputfile="histos_cutflow_176576_TSelector_n0150_02_06_14";
    if(sample_identifier == 177501)outputfile="histos_ZN_177501_n0150_02_06_14_OS";
    if(sample_identifier == 177502)outputfile="histos_ZN_177502_n0150_02_06_14";
    if(sample_identifier == 177503)outputfile="histos_ZN_177503_n0150_02_06_14";
    if(sample_identifier == 177504)outputfile="histos_ZN_177504_n0150_02_06_14";
    if(sample_identifier == 177505)outputfile="histos_ZN_177505_n0150_02_06_14";
    if(sample_identifier == 177506)outputfile="histos_ZN_177506_n0150_02_06_14";
    if(sample_identifier == 177507)outputfile="histos_ZN_177507_n0150_02_06_14";
    if(sample_identifier == 177508)outputfile="histos_ZN_177508_n0150_02_06_14";
    if(sample_identifier == 177509)outputfile="histos_ZN_177509_n0150_02_06_14";
    if(sample_identifier == 177510)outputfile="histos_ZN_177510_n0150_02_06_14";
    if(sample_identifier == 177511)outputfile="histos_ZN_177511_n0150_02_06_14";
    if(sample_identifier == 177512)outputfile="histos_ZN_177512_n0150_02_06_14";
    if(sample_identifier == 177513)outputfile="histos_ZN_177513_n0150_02_06_14";
    if(sample_identifier == 177514)outputfile="histos_ZN_177514_n0150_02_06_14";
    if(sample_identifier == 177515)outputfile="histos_ZN_177515_n0150_02_06_14";
    if(sample_identifier == 177516)outputfile="histos_ZN_177516_n0150_02_06_14";
    if(sample_identifier == 177517)outputfile="histos_ZN_177517_n0150_02_06_14";
    if(sample_identifier == 177518)outputfile="histos_ZN_177518_n0150_02_06_14";
    if(sample_identifier == 177519)outputfile="histos_ZN_177519_n0150_02_06_14";
    if(sample_identifier == 177520)outputfile="histos_ZN_177520_n0150_02_06_14";
    if(sample_identifier == 177521)outputfile="histos_ZN_177521_n0150_02_06_14";
    if(sample_identifier == 177522)outputfile="histos_ZN_177522_n0150_02_06_14";
    if(sample_identifier == 177523)outputfile="histos_ZN_177523_n0150_02_06_14";
    if(sample_identifier == 177524)outputfile="histos_ZN_177524_n0150_02_06_14";
    if(sample_identifier == 177525)outputfile="histos_ZN_177525_n0150_02_06_14";
    if(sample_identifier == 177526)outputfile="histos_ZN_177526_n0150_02_06_14";
    if(sample_identifier == 177527)outputfile="histos_ZN_177527_n0150_02_06_14";
    
    if(sample_identifier == 10001) outputfile="histos_fake_Egamma_n0150_1_02_06_14";
    if(sample_identifier == 10002) outputfile="histos_fake_Egamma_n0150_2_02_06_14";
    if(sample_identifier == 10003) outputfile="histos_fake_Egamma_n0150_3_02_06_14";
    if(sample_identifier == 10004) outputfile="histos_fake_Egamma_n0150_4_02_06_14";
    if(sample_identifier == 10005) outputfile="histos_fake_Egamma_n0150_5_02_06_14";
    if(sample_identifier == 10006) outputfile="histos_fake_Egamma_n0150_6_02_06_14";
    
    if(sample_identifier == 20001) outputfile="histos_fake_Muons_n0150_1_02_06_14";
    if(sample_identifier == 20002) outputfile="histos_fake_Muons_n0150_2_02_06_14";
    if(sample_identifier == 20003) outputfile="histos_fake_Muons_n0150_3_02_06_14";
    if(sample_identifier == 20004) outputfile="histos_fake_Muons_n0150_4_02_06_14";
    if(sample_identifier == 20005) outputfile="histos_fake_Muons_n0150_5_02_06_14";
    if(sample_identifier == 20006) outputfile="histos_fake_Muons_n0150_6_02_06_14";
//     outputfile="histos_Egamma_A";
    
// if(sample_identifier>=176574 && sample_identifier <= 176640){
// char buffer[10];
// ostrstream Str(buffer, isys);
// Str << sample_identifier << ends;
// double d = 3.14;
    char buffer[10];
    sprintf(buffer, "%d", isys);
    printf("%s\n", buffer);
//     system("pause");
string str;
// string str1 = "histos_ZN_tauveto_signal_";
str.append(outputfile);
// str.append(buffer);
string str2 = ".root";
str.append(str2);
cout <<"str= " << str << endl;

//     cout << "outputfile_composed= " << outputfile_composed << endl;
// //     cout << "ouputfile: " << outputfile << endl;
//     cout << " " << endl;
   TString outputfilename = str;
   TFile* output_file = new TFile(outputfilename, "recreate") ;//update or recreate?
   cout << "TFile created" << endl;
   output_file->cd();

   /*if(!calcSysUncert) */writeHistos();
   if(calcSysUncert) writeHistos_sysUncert();
    cout << "histos written" << endl;
   output_file->Write() ;
   cout << "outputfile written" << endl;
   output_file->Close();
   cout << "closed" << endl;
  if(makeNTuple){
    closeTupleMaker();
    cout << "created " << tuple_file << endl;
  }
    
// }
}
/*--------------------------------------------------------------------------------*/
// The Terminate() function is the last function to be called
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple::Terminate()
{
//   closeTupleMaker();
 
}