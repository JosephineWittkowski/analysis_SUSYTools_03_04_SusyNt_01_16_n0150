#include <iomanip>
#include "TCanvas.h"

#include "TSelector_SusyNtuple.hpp"
#include "histos_ZN_tauveto.C"

using namespace std;
using namespace Susy;

/*--------------------------------------------------------------------------------*/
// TSelector_SusyNtuple Constructor
/*--------------------------------------------------------------------------------*/
TSelector_SusyNtuple::TSelector_SusyNtuple() :
        m_selectB   (false),
        m_vetoB     (false),
        m_selectSFOS(false),
        m_vetoSFOS  (false),
        m_writeOut  (false)
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

   TString option = GetOption();

}
void TSelector_SusyNtuple::SlaveBegin(TTree* /*tree*/)
{
  
  defineHistos();


  m_susyObj.initialize(nt.evt()->isMC);

  SusyNtAna::Begin(0);


  setSelectTaus(true);


  m_trigObjWithoutRU = new DilTrigLogic("Moriond",false/*No Reweight Utils!*/); 
  
  cout << "initialize chargeFlip tool" << endl;
  
  m_chargeFlip.initialize("/data/etp/jwittkowski/analysis_SUSYTools_03_04/ChargeFlip/data/d0_chargeflip_map.root");  
  
  m_matrix = new SusyMatrixMethod::DiLeptonMatrixMethod();  
  m_matrix->configure("/data/etp/jwittkowski/analysis_SUSYTools_03_04/SusyMatrixMethod/data/forDavide_Sep11_2013.root", SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT);
  
}



Bool_t TSelector_SusyNtuple::Process(Long64_t entry)
{
  
  
  GetEntry(entry);
  clearObjects();

  
  m_chainEntry++;
  unsigned int mcid;
  if(nt.evt()->isMC){
    mcid = nt.evt()->mcChannel;
    calcFakeContribution = false;
  }
  else{
    mcid = 111111;
    calcFakeContribution = true;
  }
  m_kIsData = !nt.evt()->isMC;
  
  if(m_chainEntry==0){
    sample_identifier = mcid;
//     mcid_of_first_entry = mcid;
//     cout << "entry 0, mcid_of_first_entry= " << mcid_of_first_entry << endl;
    
    if(m_kIsData){
    cout << " DATA DATA DATA DATA DATA DATA" << endl;
  }
    else cout << "MC MC MC MC MC MC MC MC" << endl;
    cout << "sample_identifier= " << sample_identifier << endl;
    
    
  }
  if(m_dbg || m_chainEntry%50000==0)
  {
    
    unsigned int mcid = nt.evt()->mcChannel;
    float recalc_sumw = 0.;
    map<unsigned int, float>::const_iterator sumwMapIter = m_sumwMap.find(mcid);
    if(sumwMapIter != m_sumwMap.end()) recalc_sumw = sumwMapIter->second;
	
    cout << "**** Processing entry " << setw(6) << m_chainEntry << " run " << setw(6) << nt.evt()->run << " event " << setw(7) << nt.evt()->event << " sumw= " << nt.evt()->sumw << " recalc_sumw= " << recalc_sumw << " ****" << endl;
  }

  runWithPoD = false;
  
  if(runWithPoD && !m_kIsData && (m_chainEntry==0 || (mcid_of_first_entry != mcid))){
//       float recalc_sumw = 0.;
//       map<unsigned int, float>::const_iterator sumwMapIter = m_sumwMap.find(mcid);
//       if(sumwMapIter != m_sumwMap.end()) recalc_sumw = sumwMapIter->second;
//       h_storeSumwMcid->Fill(mcid, recalc_sumw);
      mcid_of_first_entry = mcid;
//       cout << "recalc_sumw= " << recalc_sumw << endl;
      
      TFile *pFileIn_sumw = new TFile("/data/etp/jwittkowski/analysis_SUSYTools_03_04/sumw_file_mcid126892.root");
      TH1F *h_storeSumwMcid_out = (TH1F*)pFileIn_sumw->Get("h_storeSumwMcid_merged");
      sumw_from_histo = h_storeSumwMcid_out->GetBinContent(mcid+1);
      cout << "sumw_from_histo= " << sumw_from_histo << " = " << h_storeSumwMcid_out->GetBinContent(mcid+1) << endl;
      pFileIn_sumw->Close();
    }
    
  
   
			      
// select signal objects
  selectObjects(NtSys_NOM, false, TauID_medium);

  int flag = nt.evt()->cutFlags[NtSys_NOM];
  //   charge flip background contribution in SS channels: for the e^pm e^pm and e^pm mu^pm channels, processes that are opposite-sign in truth but where one electron has undergone a “charge flip”. Contributions from WW, ttbar, Z/gamma* and single top are via charge-flip
  // In previous analysis, it has been observed that the charge flip rate in data is lower than that in the simulation by about 20%. Because of this disagreement, the electron charge flip rate is measured in data as a function of |eta| and combined with the smaller dependence on pT taken from simulation.
  float weight_ALL_EE =  (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) : 1.;
  float weight_ALL_MM =  (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) : 1.;
  float weight_ALL_EM =  (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) : 1.;
  
  float cutnumber = 0.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); // all events in the sample

  if( !(flag & ECut_GRL) ) return false; 
  cutnumber = 1.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //grl Cut

  if( !(ECut_TileTrip & flag) ) return false; 
  cutnumber = 2.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //TileTripReader

//   if ( !(flag & ECut_TTC)) return false;
  cutnumber = 3.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//IncompleteEvents Veto

  if(!(ECut_LarErr & flag) || !(ECut_TileErr & flag)) return false;
  cutnumber = 4.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //LAr/TileError

//   if( !(flag & ECut_HotSpot)) return false; //remove event where a jet points into hot TileCal module 
  cutnumber = 5.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //TileCalHotSpot

  // remove event with VeryLooseBad jets with pT>20 GeV. No eta cut. Only consider jets which are not overlapping with electrons or taus:  
  if(hasBadJet(m_baseJets))return kFALSE;
  cutnumber = 6.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadJets
    
  //on top of smart veto, veto event with >=1 jets before electron-jet overlap removal with pT>40 GeV, BCH_CORR_JET > 0.05, DeltaPhi(met,jet)<0.3 (Anyes)  
  JetVector prejets = getPreJets(&nt, NtSys_NOM);
  if(!passDeadRegions(prejets, m_met, nt.evt()->run, nt.evt()->isMC)/* || !(flag & ECut_SmartVeto)*/) return false; //   SusyNtTools: passDeadRegions(...)
  cutnumber = 7.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //CaloJets

  if( !(flag & ECut_GoodVtx)) return false;
  cutnumber = 8.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//PrimaryVertex

  MuonVector preMuons = getPreMuons(&nt, NtSys_NOM);
  if( hasBadMuon(preMuons)) return false;
  cutnumber = 9.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadMuons
    
  if(hasCosmicMuon(m_baseMuons)) return false; // !(flag & ECut_Cosmic)  - no longer guarantee the event flags that are stored :-(
  preMuons.clear();
  cutnumber = 10.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Cosmic Muons


  // Sherpa WW fix, remove radiative b-quark processes that overlap with single top: already done upstream in SusyCommon SusyNtMaker

  if(nt.evt()->hfor == 4) return false; //remove events where same heavy flavor final states arise in multiple samples when combining ALPGEN samples
  cutnumber = 11.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//hfor veto

  if(m_baseLeptons.size() < 2) return false;
  cutnumber = 12.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//at least 2 base leptons

  if( !(m_baseLeptons.size()==2) ) return false;
  cutnumber = 13.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//exactly 2 base leptons


//   if(!(m_baseElectrons.size()==2 || m_baseMuons.size()==2 || (m_baseElectrons.size()+m_baseMuons.size())==2)) return false; //only count leptons where no Mll < 20 GeV. Mll < 12 GeV veto ALREADY DONE FOR SELECTING BASELINE LEPTONS in performOverlapRemoval()


  // discard any SFOS baseline lepton pair with M_ll < 12 GeV unnecessary: already done when skimming/slimming ntuples
  // Any lepton pairs are required to have an invariant mass, m``, above 20 GeV such that to remove low-mass dilepton resonances
  if( Mll(m_baseLeptons[0], m_baseLeptons[1]) < 20 )return false;
  cutnumber = 14.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Mll
  
  Jet* jet0;
  Jet* jet1;
  TLorentzVector signalJet0_TLV, signalJet1_TLV;
  float mjj = 0.;
  
  if(numberOfCLJets(m_signalJets2Lep) >=1){
    jet0 = m_signalJets2Lep.at(0);    

    signalJet0_TLV.SetPtEtaPhiE(jet0->pt, jet0->eta, jet0->phi, jet0->pt*cosh(jet0->eta));
    if(numberOfCLJets(m_signalJets2Lep) >=2){	
      jet1 = m_signalJets2Lep.at(1);
      signalJet1_TLV.SetPtEtaPhiE(jet1->pt, jet1->eta, jet1->phi, jet1->pt*cosh(jet1->eta));
      
    }
  }
  bool useForwardJets = true;
  float METrel = getMetRel(m_met, m_signalLeptons, m_signalJets2Lep, useForwardJets);  
  
  calcJet_variables(signalJet0_TLV, signalJet1_TLV, m_met->lv());

  //............................................................................................................
  //Fill d0 histos for validation purpose:     
// Don't cut on d0sig to plot these (I'm assuming you do looking at these plots)
// You can also drop the iso and the dR cuts (overlap w./ jets) for the purpose of validating the var)


  if(nt.evt()->isMC && numberOfCLJets(m_signalJets2Lep) > 0){
    

  for (int ilep = 0; ilep < m_baseLeptons.size(); ilep ++){
    

    if(m_baseLeptons.at(ilep)->isEle()){
      int iel = 0;
      for(iel = 0; iel < m_baseElectrons.size(); iel ++){
	if(m_baseLeptons.at(ilep)->Pt() == m_baseElectrons.at(iel)->Pt()){
	  break;
	}
      }
      if(!m_baseElectrons.at(iel)->tightPP) continue;
      if(m_baseLeptons.at(ilep)->Pt() <= 10.) continue;
//       float ptcone30 = elPtConeCorr(m_baseElectrons.at(iel), m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false);
//       if(ptcone30/m_baseLeptons.at(ilep)->Pt() >= ELECTRON_PTCONE30_PT_CUT) continue;
//       float etcone = elEtTopoConeCorr(m_baseElectrons.at(iel), m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false);
//       if(etcone/m_baseLeptons.at(ilep)->Pt() >= ELECTRON_TOPOCONE30_PT_CUT) continue;
    }
    else{
      int imu = 0;
      for(imu = 0; imu < m_baseMuons.size(); imu ++){
	if(m_baseLeptons.at(ilep)->Pt() == m_baseMuons.at(imu)->Pt()){
	  break;
	}
      }
      if(m_baseLeptons.at(ilep)->Pt() <= 10.) continue;
      if(fabs(m_baseLeptons.at(ilep)->Eta()) >= 2.4) continue;
//       float ptcone30 = m_baseMuons.at(imu)->ptcone30ElStyle; // no corrections at the moment
//       if(ptcone30/m_baseMuons.at(imu)->Pt() >= MUON_PTCONE30ELSTYLE_PT_CUT) continue;
    }

      
    bool unbiased = true;
    float D0_branch = 0.;
    float D0err_branch = 0.;
    float D0_recalc = 0.;
     //read d0 and errd0 from ntuple (d0Sig = d0 / errD0)
    if(unbiased){
      D0_branch = m_baseLeptons.at(ilep)->d0Unbiased;
      D0err_branch = m_baseLeptons.at(ilep)->errD0Unbiased;
    }
    else{
      D0_branch = m_baseLeptons.at(ilep)->d0;
      D0err_branch = m_baseLeptons.at(ilep)->errD0;
    }
  
    //calc closest jet for lepton
    const Jet* closestJet = getClosestJet(m_baseLeptons.at(ilep));	
    //recalc sign of d0 wrt closest jet
    D0_recalc = recalc_D0(unbiased, m_baseLeptons.at(ilep), closestJet);

    float sD0Signif_recalc = D0_recalc / D0err_branch;

    if(m_baseLeptons.at(ilep)->truthType == PR){ 
      if(m_baseLeptons.at(ilep)->isEle()){ 
	h_D0Signif_recalc_PR_elec->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
	h_D0_recalc_PR_elec->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
      }
      else{
	h_D0Signif_recalc_PR_muon->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
	h_D0_recalc_PR_muon->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
      }
    }
    
    if(m_baseLeptons.at(ilep)->truthType == HF){ 
      if(m_baseLeptons.at(ilep)->isEle()){ 
	h_D0Signif_recalc_HF_elec->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
	h_D0_recalc_HF_elec->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
      }
      else{
	h_D0Signif_recalc_HF_muon->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
	h_D0_recalc_HF_muon->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
      }
    }
    
    if(m_baseLeptons.at(ilep)->truthType == LF){ 
      if(m_baseLeptons.at(ilep)->isEle()){ 
	h_D0Signif_recalc_LF_elec->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
	h_D0_recalc_LF_elec->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
      }
      else{
	h_D0Signif_recalc_LF_muon->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
	h_D0_recalc_LF_muon->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
      }
    }

//       bool isConv = m_baseLeptons.at(ilep)->truthType == CONV;
//       bool isqFlip = false;
// 
//       if(isConv){      
// 	if(m_baseLeptons.at(ilep)->isEle()){
// 	  for(int iel = 0; iel < m_baseElectrons.size(); iel ++){
// 	    if(m_baseLeptons.at(ilep)->Pt() == m_baseElectrons.at(iel)->Pt()){
// 	      isqFlip = m_baseElectrons.at(iel)->isChargeFlip;
// 	      break;
// 	    }
// 	  }
// 	}
//       }
//       if(isConv && !isqFlip){
// 	if(m_baseLeptons.at(ilep)->isEle()){
// 	  h_D0Signif_recalc_l0_elec->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
// 	  h_D0_recalc_l0_elec->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_EE);
// 	}
// 	else{
// 	  h_D0Signif_recalc_l0_muon->Fill(sD0Signif_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
// 	  h_D0_recalc_l0_muon->Fill(D0_recalc, m_baseLeptons.at(ilep)->truthType, weight_ALL_MM);
// 	}
//       }
    }
  }
  //............................................................................................................

 ////////////////////////////        EE            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //calculate normal contribution with signal leptons:
  if(m_baseElectrons.size()==2){
    cutnumber = 15.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE); //pass category
    bool passEE = false;
    Electron* el0;
    Electron* el1;
    LeptonVector leptons;
    ElectronVector electrons;
    TLorentzVector el0_TLV, el1_TLV;
//     cout << "m_signalElectrons.size()= " << m_signalElectrons.size() << " m_baseElectrons.size()= " << m_baseElectrons.size() << endl;
    if(m_signalElectrons.size()==2){
      passEE = true;
      cutnumber = 16.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE); //pass nlep
     
      el0 = (m_signalElectrons.at(0)->pt > m_signalElectrons.at(1)->pt) ? m_signalElectrons.at(0) : m_signalElectrons.at(1);
      el1 = (m_signalElectrons.at(0)->pt > m_signalElectrons.at(1)->pt) ? m_signalElectrons.at(1) : m_signalElectrons.at(0);
      
      leptons = m_signalLeptons;
      electrons = m_signalElectrons;
      
      el0_TLV.SetPtEtaPhiE(el0->pt, el0->eta ,el0->phi, el0->pt*cosh(el0->eta));
      el1_TLV.SetPtEtaPhiE(el1->pt, el1->eta ,el1->phi, el1->pt*cosh(el1->eta));
    }
      
//       make sure you take the baseline leptons:
      if (calcFakeContribution && m_baseElectrons.size()==2 ){
	passEE = true;
	leptons = m_baseLeptons;
	electrons = m_baseElectrons;
	el0 = (electrons.at(0)->pt > electrons.at(1)->pt) ? electrons.at(0) : electrons.at(1);
	el1 = (electrons.at(0)->pt > electrons.at(1)->pt) ? electrons.at(1) : electrons.at(0);
	
	el0_TLV.SetPtEtaPhiE(el0->pt, el0->eta ,el0->phi, el0->pt*cosh(el0->eta));
	el1_TLV.SetPtEtaPhiE(el1->pt, el1->eta ,el1->phi, el1->pt*cosh(el1->eta));
      }
	
      if(passEE && m_signalTaus.size() == 0){
	
	  cutnumber = 17.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE);
	  if(m_trigObjWithoutRU->passDilEvtTrig(leptons, m_met->Et, nt.evt())){ //valid pT region
	    cutnumber = 18.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE);
	
	    if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){  //match to trigger (in MC not needed bc weighted)
	      cutnumber = 19.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE);
	      if(!nt.evt()->isMC || CheckRealLeptons(electrons, m_signalMuons)){
		cutnumber = 20.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_EE);
		
		//time to calc weights:
		//------------------------------------------------------------------------------------
		//calc lepton SF:
		float lep_SF_EE = 1.0;
		if(nt.evt()->isMC) lep_SF_EE = el0->effSF * el1->effSF;		
		
		//calc trigger weight:
		float trigW_EE = 1.;
		if(nt.evt()->isMC) trigW_EE = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM);
		//product of all weights, for SS and OS MC events:
		weight_ALL_EE = (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) * lep_SF_EE * trigW_EE : 1; //consider pileup, xsec, lumi (as argument), MC eventWeight.
		
		//calc charge flip weights: 
		//Note that the charge flip is only applied in SS region (ee or em) and only for MC events that are true OS.
		//The charge flip changes both the lepton pt of the electron that charge flip and the change needs to be propagated to the met.
		float chargeFlipWeight = 1.0;

		//make a copy of electrons and MET which will eventually be changed by ChargeFlip tool:
		ElectronVector electrons_SS;
		electrons_SS = electrons;
		Electron* el0_SS;
		Electron* el1_SS;
		el0_SS = (electrons.at(0)->pt > electrons.at(1)->pt) ? electrons.at(0) : electrons.at(1);
		el1_SS = (electrons.at(0)->pt > electrons.at(1)->pt) ? electrons.at(1) : electrons.at(0);
		TLorentzVector el0_SS_TLV, el1_SS_TLV;
		el0_SS_TLV.SetPtEtaPhiE(el0_SS->pt, el0_SS->eta ,el0_SS->phi, el0_SS->pt*cosh(el0_SS->eta));
		el1_SS_TLV.SetPtEtaPhiE(el1_SS->pt, el1_SS->eta ,el1_SS->phi, el1_SS->pt*cosh(el1_SS->eta));
		
		TLorentzVector met_SS_TLV;
		TVector2 met_SS_TVector2;
		met_SS_TLV = m_met->lv();
		met_SS_TVector2.Set(met_SS_TLV.Px(), met_SS_TLV.Py());
		
// 		cout << "before chargeflip: lv0 px: "<<el0_SS_TLV.Px()<<" py: "<<el0_SS_TLV.Py()<<" pz: "<<el0_SS_TLV.Pz() << " pT= " << el0_SS_TLV.Pt() << " phi= " << el0_SS_TLV.Phi()
// 		<<" lv1 px: "<<el1_SS_TLV.Px()<<" py: "<<el1_SS_TLV.Py()<<" pz: "<<el1_SS_TLV.Pz() << " pT= " << el1_SS_TLV.Pt() << " phi= " << el1_SS_TLV.Phi()
// 		<<" met px: "<<met_SS_TLV.Px()<<" py: "<<met_SS_TLV.Py()<<" pT: "<<met_SS_TLV.Pt()<<" phi: "<<met_SS_TLV.Phi()
// 		<<endl;
		//if SS event, get ChargeFlipWeight and modify electron and met TLV:
		int pdg0 = 11 * (-1) * el0->q; // Remember 11 = elec which has charge -1
		int pdg1 = 11 * (-1) * el1->q;
		if((el0->q * el1->q)<0 && nt.evt()->isMC){		  
		  m_chargeFlip.setSeed(nt.evt()->event);
		  chargeFlipWeight = m_chargeFlip.OS2SS(pdg0, &el0_SS_TLV, pdg1, &el1_SS_TLV, &met_SS_TVector2, 0);
		  chargeFlipWeight*=  m_chargeFlip.overlapFrac().first;		  

		  //get changed MET and fill in TLorentzVector:
		  met_SS_TLV.SetPx(met_SS_TVector2.Px());
		  met_SS_TLV.SetPy(met_SS_TVector2.Py());		  
		  met_SS_TLV.SetE(sqrt(pow(met_SS_TVector2.Px(),2) + pow(met_SS_TVector2.Py(),2)));

		}
		float weight_ALL_SS_EE = 1.0;
		weight_ALL_SS_EE = weight_ALL_EE * chargeFlipWeight; //multiply only SS weight by chargeFlipWeight
// 		cout << "weight_ALL_SS_EE= " << weight_ALL_SS_EE;
		//------------------------------------------------------------------------------------
		calc_EE_variables(leptons, el0, el1, el0_SS_TLV, el1_SS_TLV, met_SS_TLV, signalJet0_TLV, signalJet1_TLV, useForwardJets);
		//if running on data for fake bg, instead of weights (pileup, xsec, eventweight, trigger, SF, btag, ...) use fakeWeight from SusyMatrixMethod		
		float METrel_SS = recalcMetRel(met_SS_TLV, el0_SS_TLV, el1_SS_TLV, m_signalJets2Lep, useForwardJets);
		if(!nt.evt()->isMC && calcFakeContribution){
		  weight_ALL_EE = getFakeWeight(m_baseLeptons, SusyMatrixMethod::FR_SRDavide, METrel, SusyMatrixMethod::SYS_NONE);
		  weight_ALL_SS_EE = weight_ALL_EE;
		}
// 		cout << " " << weight_ALL_SS_EE << endl;
		
		//------------------------------------------------------------------------------------
		//----------------------------------SR-SS-EE------------------------------------------
		//------------------------------------------------------------------------------------
		

		
		
		
		if(nt.evt()->isMC || (!nt.evt()->isMC && (el0->q * el1->q)>0)){
		  cutnumber = 21.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE); //SS cut: applied only on weighted events
		  cutnumber = 22.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE); //iso cut (muons)
		  
// truthMatchType == PR
// truthMatchType == HF
// truthMatchType == LF
// 
// For conversion it's s little more complicated
// 
// bool isConv       = el0->truthType == CONV;
// bool isqFlip =  isEle ? isChargeFlip : false;
// return isConv && !isqFlip;
// if(nt.evt()->isMC){
//     for (int iel = 0; iel < m_signalElectrons.size(); iel ++){
// //       cout << "m_baseElectrons.at(iel)->truthType = " << m_baseElectrons.at(iel)->truthType << endl;
// // 		    if(el0->truthType == PR) cout << "is PR" << endl;
//     if(m_signalElectrons.at(iel)->truthType == HF) cout << "is HF" << endl; 
//     if(m_signalElectrons.at(iel)->truthType == LF) cout << "is LF" << endl;
//     }
//   }

// 		  cout << "run " << nt.evt()->run
// 		  << " evt " << nt.evt()->event 
// 		  << " ee l0: pt=" << el0_SS_TLV.Pt() <<  " eta=" << el0_SS_TLV.Eta() 
// 		  << " l1: pt=" << el1_SS_TLV.Pt() << " eta=" << el1_SS_TLV.Eta() 
// 		  << " weight=" << weight_ALL_SS_EE << endl;
		
		  if(fabs(el0->d0Sig(true))<=3.0 && fabs(el1->d0Sig(true))<=3.0){//|d0/sd0|<3   (for electron) (update to latest QFlip)
		    cutnumber = 23.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      weight_ALL_SS_EE *= getBTagWeight(nt.evt());
// 		      cout << "EE event  " << nt.evt()->event << " gen " << nt.evt()->w  << " pileup " <<  nt.evt()->wPileup << " norm " << nt.evt()->xsec * LUMI_A_L / nt.evt()->sumw  << " lepSf " << lep_SF_EE  << " btag " << getBTagWeight(nt.evt()) << " trigger " << m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM) << " chargeFlipWeight " << chargeFlipWeight << " all " << weight_ALL_SS_EE
// 		      << endl;
	  
// 		      cout <<" pdg0 "<<pdg0
// 		      <<" lv0 px: "<<el0_SS_TLV.Px()<<" py: "<<el0_SS_TLV.Py()<<" pz: "<<el0_SS_TLV.Pz() << " pT= " << el0_SS_TLV.Pt() << " phi= " << el0_SS_TLV.Phi()
// 		      <<" pdg1 "<<pdg1
// 		      <<" lv1 px: "<<el1_SS_TLV.Px()<<" py: "<<el1_SS_TLV.Py()<<" pz: "<<el1_SS_TLV.Pz() << " pT= " << el1_SS_TLV.Pt() << " phi= " << el1_SS_TLV.Phi()
// 		      <<" met px: "<<met_SS_TLV.Px()<<" py: "<<met_SS_TLV.Py()<<" pT: "<<met_SS_TLV.Pt()<<" phi: "<<met_SS_TLV.Phi()
// 		      <<endl;
		      cutnumber = 24.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 25.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			if(numberOfCLJets(m_signalJets2Lep) >=1){
			  cutnumber = 26.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
		  
// 			  if(el0_SS_TLV.Pt()>=20. && el1_SS_TLV.Pt()>=20. && ((el0_SS_TLV.Pt()>el1_SS_TLV.Pt() && el0_SS_TLV.Pt() >= 30.) || (el0_SS_TLV.Pt()<el1_SS_TLV.Pt() && el1_SS_TLV.Pt() >= 30.))){
			    
// 			    cutnumber = 27.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
// 			    if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
// 			      cutnumber = 28.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE); //ZVeto
// 			      float mTWW_EE = calcMt((el0_SS_TLV + el1_SS_TLV), met_SS_TLV);
			      
			      
			      // 1 or 2 jets?
// 
// try different cuts on lepton pT later in cutflow
// 
// same for mll: later
// 
// try mTWW with 130, 140, 150, 160, 170, 180 GeV (150 already very good value)
// 
// HT: not meaningful. Remove!
// 
// METrel >= 50 GeV important. Try higher values: 60, 70, 80 GeV
// 
// min(mT(l0), mT(l1)) >= 60 GeV important cut. Try higher: 70, 80, 90
// 
// meff >= 50 GeV is good. Try 60, 70 GeV (80 is too high)
// 
// forget mjj, pTjj
//   
// try DeltaPhi(MET, ll) <= 5.0
// try DeltaPhi(ll, jj) <= 3.0, 2.8
// try DeltaPhi(l0, jj) <= 3.0, 2.8
// try DeltaPhi(l1, jj) <= 3.0, 2.8
// 
// 
// 
// pTll >= 50 GeV is good. Try 60, 70 GeV
// 
// DeltaPhi(MET, jj) <= 2.8 is good. Try also 3.0, 2.9. 2.7 ?
// 
// fabs(etal0), fabs(etal1) <= 2.0 is good. Try also 1.7, 1.8, 1.9, 2.1, 2.2
// 
// 
// mT(l0, MET) >= 90 GeV is good. Try 80, 100, 110, 120 GeV.
// 
// mT(l1, MET) >= 60 GeV is good. Try 70, 80, 90, 100 GeV.
// 
// mT(ll, MET) >= 90 GeV is good. Try 80, 100, 110, 120 GeV
// 
// m(MET, ll) >= 190 GeV is good. Try 200, 210, 220, 230 GeV
// 
// mT2 >= 70 GeV is good. Try 40, 50 GeV.
			      
			      //play with cuts:
			      // try mTWW with 130, 140, 150, 160, 170, 180 GeV (150 already very good value)
			      if(mTWW_EE >= 130.){
				cutnumber = 30.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			      }
			      if(mTWW_EE >= 140.){
				cutnumber = 31.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			      }
			      if(mTWW_EE >= 160.){
				cutnumber = 32.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			      }
			      if(mTWW_EE >= 170.){
				cutnumber = 33.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			      }
			      if(mTWW_EE >= 180.){
				cutnumber = 34.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
			      }			      
			      if(mTWW_EE >= 150.){	
				cutnumber = 35.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				
			      
			      if(mTWW_EE >= 150.){	
				cutnumber = 36.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				// METrel >= 50 GeV important. Try higher values: 60, 70, 80 GeV
				if(METrelee >= 60.){
				  cutnumber = 37.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				}
				if(METrelee >= 70.){
				  cutnumber = 38.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				}
				if(METrelee >= 80.){
				  cutnumber = 39.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				}
				if(METrelee >= 50.){				
				  cutnumber = 40.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				  
				  // try different cuts on lepton pT later in cutflow
				  if(ptel1>=20. && ptel1 >= 30.){
				    cutnumber = 41.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				    // same for mll: later
				    if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
				      cutnumber = 42.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				      // min(mT(l0), mT(l1)) >= 60 GeV important cut. Try higher: 70, 80, 90
				      if(mTemin>= 70.){
					cutnumber = 43.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTemin>= 80.){
					cutnumber = 44.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTemin>= 90.){
					cutnumber = 45.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTemin>= 60.){			
					cutnumber = 46.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					// meff >= 50 GeV is good. Try 60, 70 GeV (80 is too high)
					if(meff >= 60.){
					  cutnumber = 47.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(meff >= 70.){
					  cutnumber = 48.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(meff >= 50.){
					  cutnumber = 49.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  // try DeltaPhi(MET, ll) <= 5.0
					  if(DeltaPhiMETee<= 3.0){
					    cutnumber = 50.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(DeltaPhiMETee<= 2.8){
					    cutnumber = 51.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  // try DeltaPhi(l0, jj) <= 3.0, 2.8
					  if(DeltaPhiel0jj <= 3.0){
					    cutnumber = 52.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(DeltaPhiel0jj <= 2.8){
					    cutnumber = 53.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }					  
					  // try DeltaPhi(l1, jj) <= 3.0, 2.8
					  if(DeltaPhiel1jj <= 3.0){
					    cutnumber = 54.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(DeltaPhiel1jj <= 2.8){
					    cutnumber = 55.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }		
// 					  pTll >= 50 GeV is good. Try 60, 70 GeV
					  if(pTee>= 60.){
					    cutnumber = 56.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(pTee>= 70.){
					    cutnumber = 57.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					  }					  
					  if(pTee>= 50.){	
					    cutnumber = 58.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					    // DeltaPhi(MET, jj) <= 2.8 is good. Try also 3.0, 2.9. 2.7 ?
					    if(DeltaPhiMETjj <= 3.0){
					      cutnumber = 59.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					    }
					    if(DeltaPhiMETjj <= 2.9){
					      cutnumber = 60.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					    }
					    if(DeltaPhiMETjj <= 2.7){
					      cutnumber = 61.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					    }
					    if(DeltaPhiMETjj <= 2.8){
					      cutnumber = 62.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      
					      // fabs(etal0), fabs(etal1) <= 2.0 is good. Try also 1.7, 1.8, 1.9, 2.1, 2.2					      
					      if(fabs(eta_el0) <= 2.2 && fabs(eta_el1) <= 2.2){
						cutnumber = 63.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }
					      if(fabs(eta_el0) <= 2.1 && fabs(eta_el1) <= 2.1){
						cutnumber = 64.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }
					      if(fabs(eta_el0) <= 1.9 && fabs(eta_el1) <= 1.9){
						cutnumber = 65.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }
					      if(fabs(eta_el0) <= 1.8 && fabs(eta_el1) <= 1.8){
						cutnumber = 66.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }
					      if(fabs(eta_el0) <= 1.7 && fabs(eta_el1) <= 1.7){
						cutnumber = 67.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }					      
					      if(fabs(eta_el0) <= 2.0 && fabs(eta_el1) <= 2.0){
						cutnumber = 68.; fillHistos_EE_SRSS1(cutnumber, mcid, weight_ALL_SS_EE);
					      }
					    }
					  }
					}
				      }
				      
				      // mT(l0, MET) >= 90 GeV is good. Try 80, 100, 110, 120 GeV.
				      if(mTel0MET >= 80.){
					cutnumber = 30.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTel0MET >= 100.){
					cutnumber = 31.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTel0MET >= 110.){
					cutnumber = 32.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTel0MET >= 120.){
					cutnumber = 33.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
				      }
				      if(mTel0MET >= 90.){		      
					cutnumber = 34.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					// mT(l1, MET) >= 60 GeV is good. Try 70, 80, 90, 100 GeV.
					if(mTel0MET >= 70.){	
					  cutnumber = 35.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(mTel0MET >= 80.){	
					  cutnumber = 36.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(mTel0MET >= 90.){	
					  cutnumber = 37.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(mTel0MET >= 100.){	
					  cutnumber = 38.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					}
					if(mTel0MET >= 60.){	
					  cutnumber = 39.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					  // mT(ll, MET) >= 90 GeV is good. Try 80, 100, 110, 120 GeV
					  if(mTee>= 80.){
					    cutnumber = 40.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(mTee>= 100.){
					    cutnumber = 41.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(mTee>= 110.){
					    cutnumber = 42.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(mTee>= 120.){
					    cutnumber = 43.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					  }
					  if(mTee>= 90.){
					    cutnumber = 44.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					     // m(MET, ll) >= 190 GeV is good. Try 200, 210, 220, 230 GeV
					     if(mMETee>= 200.){
					       cutnumber = 45.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					     }
					     if(mMETee>= 210.){
					       cutnumber = 46.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					     }
					     if(mMETee>= 220.){
					       cutnumber = 47.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					     }
					     if(mMETee>= 230.){
					       cutnumber = 48.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					     }
					     if(mMETee>= 190.){
					       cutnumber = 49.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					       // mT2 >= 70 GeV is good. Try 40, 50 GeV.
					       if(mt2_ee>= 40.){
						 cutnumber = 50.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					       }
					       if(mt2_ee>= 50.){
						 cutnumber = 51.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					       }
					       if(mt2_ee>= 70.){
						 cutnumber = 52.; fillHistos_EE_SRSS2(cutnumber, mcid, weight_ALL_SS_EE);
					       }
					     }
					  }
					}
				      }
				    }
				  }
				}
			      }
			      }
			}
		      }
		    }
		  }
		}
					     
					     
				
	      //------------------------------------------------------------------------------------
	      //----------------------------------SR-OS-EE------------------------------------------
	      //------------------------------------------------------------------------------------
	      if((el0->q * el1->q)<0){
		cutnumber = 50.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
		cutnumber = 51.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
		if(numberOfFJets(m_signalJets2Lep) == 0){
		  weight_ALL_EE *= getBTagWeight(nt.evt());
		  cutnumber = 52.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
		  if(numberOfCBJets(m_signalJets2Lep) == 0){
		    cutnumber = 53.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
		    if(numberOfCLJets(m_signalJets2Lep) >=2){
		      cutnumber = 54.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
		      TLorentzVector signalJet0_TLV, signalJet1_TLV;
		      signalJet0_TLV.SetPtEtaPhiE(jet0->pt, jet0->eta, jet0->phi, jet0->pt*cosh(jet0->eta));
		      signalJet1_TLV.SetPtEtaPhiE(jet1->pt, jet1->eta, jet1->phi, jet1->pt*cosh(jet1->eta));
		      mjj = Mll(m_signalJets2Lep.at(0), m_signalJets2Lep.at(1));
		      if(mjj >= 50. && mjj <= 100.){
			cutnumber = 55.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
			if(el0_TLV.Pt() >= 30 && el1_TLV.Pt() >= 30){
			  cutnumber = 56.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
			  float DeltaRee = fabs(el0_TLV.DeltaR(el1_TLV));
			  if(DeltaRee<=1.5){
			    cutnumber = 57.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
			    float mTemin = (Mt(el0, m_met) > Mt(el1, m_met)) ? Mt(el1, m_met) : Mt(el0, m_met);
			    if(mTemin >= 60.){
			      cutnumber = 58.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
			      float DeltaPhiMETee = fabs((el0_TLV + el1_TLV).DeltaPhi(m_met->lv()));
			      if(DeltaPhiMETee>=1.5){
				cutnumber = 59.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
				if(m_met->lv().Pt() >= 80.){
				  mZTT_coll = calcMZTauTau_coll(el0_SS_TLV, el1_SS_TLV, met_SS_TLV);
				  mZTT_mmc = calcMZTauTau_mmc(el0_SS_TLV, el1_SS_TLV, 0, 0);
				  cutnumber = 60.; fillHistos_EE_SROS1(cutnumber, mcid, weight_ALL_EE);
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  
 
  
   ////////////////////////////        MM            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  if(m_baseMuons.size()==2){
    cutnumber = 15.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM); //pass category
    Muon* mu0;
    Muon* mu1;
    LeptonVector leptons;
    MuonVector muons;
    TLorentzVector mu0_TLV, mu1_TLV;
    bool passMM = false;
    
    if(m_signalMuons.size()==2 ){
      
      passMM = true;
      mu0 = (m_signalMuons.at(0)->pt > m_signalMuons.at(1)->pt) ? m_signalMuons.at(0) : m_signalMuons.at(1);
      mu1 = (m_signalMuons.at(0)->pt > m_signalMuons.at(1)->pt) ? m_signalMuons.at(1) : m_signalMuons.at(0);

      leptons = m_signalLeptons;
      muons = m_signalMuons;
      
      mu0_TLV.SetPtEtaPhiE(mu0->pt, mu0->eta ,mu0->phi, mu0->pt*cosh(mu0->eta));
      mu1_TLV.SetPtEtaPhiE(mu1->pt, mu1->eta ,mu1->phi, mu1->pt*cosh(mu1->eta));
      }
      
//     calculate fake bg contribution with m_baseMuons, don't use info about m_signalElectrons
    if(calcFakeContribution && m_baseMuons.size()==2 ){   
      
      passMM = true;
      mu0 = (m_baseMuons.at(0)->pt > m_baseMuons.at(1)->pt) ? m_baseMuons.at(0) : m_baseMuons.at(1);
      mu1 = (m_baseMuons.at(0)->pt > m_baseMuons.at(1)->pt) ? m_baseMuons.at(1) : m_baseMuons.at(0);
      mu0_TLV.SetPtEtaPhiE(mu0->pt, mu0->eta ,mu0->phi, mu0->pt*cosh(mu0->eta));
      mu1_TLV.SetPtEtaPhiE(mu1->pt, mu1->eta ,mu1->phi, mu1->pt*cosh(mu1->eta));
      
      leptons = m_baseLeptons;
      muons = m_baseMuons;
    }
      if(passMM && fabs(mu0->Eta())<=2.4 && fabs(mu1->Eta())<=2.4){
	cutnumber = 16.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM); //pass nlep
	if(m_signalTaus.size() == 0){
	  cutnumber = 17.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
	  if(m_trigObjWithoutRU->passDilEvtTrig(leptons, m_met->Et, nt.evt())){ //valid pT region
	    cutnumber = 18.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
	    if(m_signalTaus.size() == 0){
	      
	      if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){ //match to trigger
		cutnumber = 19.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);

		if(!nt.evt()->isMC || CheckRealLeptons(m_signalElectrons, muons)){
		  cutnumber = 20.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
		  //time to calc weights:
		  //------------------------------------------------------------------------------------
		  //calc lepton SF:		  
		  float lep_SF_MM = 1.0;
		  if(nt.evt()->isMC) lep_SF_MM = mu0->effSF * mu1->effSF;	
		  //calc trigger weight:
		  float trigW_MM = 1.;
		  if(nt.evt()->isMC) trigW_MM = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM);
		  //product of all weights:
		  weight_ALL_MM = (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) * lep_SF_MM * trigW_MM: 1; //consider pileup, xsec, lumi (as argument), MC eventWeight.
		  		  //------------------------------------------------------------------------------------
		  calc_MM_variables(leptons, mu0, mu1, mu0_TLV, mu1_TLV, m_met->lv(), signalJet0_TLV, signalJet1_TLV, useForwardJets);
		  if(!nt.evt()->isMC && calcFakeContribution) weight_ALL_MM = getFakeWeight(m_baseLeptons, SusyMatrixMethod::FR_SRDavide, METrel, SusyMatrixMethod::SYS_NONE);
		  

		  //------------------------------------------------------------------------------------
		  //----------------------------------SR-SS-MM------------------------------------------
		  //------------------------------------------------------------------------------------
		  if(mu0->q*mu1->q>0){
		    cutnumber = 21.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM); //SS cut: for MM applied only on SS events.
// 		
		    if(muEtConeCorr(mu0, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu0->pt < 0.1 && muEtConeCorr(mu1, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu1->pt < 0.1){
		      cutnumber = 22.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
		      cutnumber = 23.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
		      if(numberOfFJets(m_signalJets2Lep) == 0){
			weight_ALL_MM *= getBTagWeight(nt.evt());
// 			cout << "MM event  " << nt.evt()->event << " gen " << nt.evt()->w << " pileup " <<  nt.evt()->wPileup << " norm " << nt.evt()->xsec * LUMI_A_L / nt.evt()->sumw  << " lepSf " << lep_SF_MM  << " btag " << getBTagWeight(nt.evt()) << " trigger " << m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->Et, m_signalJets2Lep.size(), nt.evt()->nVtx, NtSys_NOM) << " all " << weight_ALL_MM << endl;
			cutnumber = 24.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 25.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);
			if(numberOfCLJets(m_signalJets2Lep) >=1){
			  cutnumber = 26.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		    
		  
			  
			  
			  // 1 or 2 jets?  
//highest sensitiviy for points in the middle area (and elsewhere): 
// mTWW >= 140, METrel >= 50, HT >= 200, |etal0|, |etal1| <= 2.2, mT(l0,MET) >= 120, DeltaR(jj) <= 2.6, DeltaR(ll,jj) <= 2.0, DeltaEta(l,l) <= 1.9
			  if(mTWW_MM >= 140.){
			    cutnumber = 30.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
			    if(METrelmm >= 50.){
			      cutnumber = 31.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
				if(HT_MM >= 200.){
				  cutnumber = 32.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
				  if(fabs(eta_mu0)<= 2.2 && fabs(eta_mu1) <= 2.2){
				    cutnumber = 33.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
				    if(mTl0MET >= 120.){
				      cutnumber = 34.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
				      if(DeltaRjj <= 2.6){
					cutnumber = 35.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
					if(DeltaRmmjj <= 2.0){
					  cutnumber = 36.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
					  if(DeltaEtamm <= 1.9){
					    cutnumber = 37.; fillHistos_MM_SRSS1(cutnumber, mcid, weight_ALL_MM);		
					  }
					}
				      }
				    }
				  }
				}
			    }
			  }


			}
		      }
		    }
		  }
		}
		
		//------------------------------------------------------------------------------------
		//----------------------------------SR-OS-MM------------------------------------------
		//------------------------------------------------------------------------------------
		if((mu0->q * mu1->q)<0){
		  cutnumber = 50.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
		  if(muEtConeCorr(mu0, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu0->pt < 0.1 && muEtConeCorr(mu1, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu1->pt < 0.1){
		    cutnumber = 51.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      weight_ALL_MM *= getBTagWeight(nt.evt());
		      cutnumber = 52.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 53.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
			if(numberOfCLJets(m_signalJets2Lep) >=2){  
			  cutnumber = 54.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
			  TLorentzVector signalJet0_TLV, signalJet1_TLV;
			  signalJet0_TLV.SetPtEtaPhiE(jet0->pt, jet0->eta, jet0->phi, jet0->pt*cosh(jet0->eta));
			  signalJet1_TLV.SetPtEtaPhiE(jet1->pt, jet1->eta, jet1->phi, jet1->pt*cosh(jet1->eta));
			  mjj = Mll(m_signalJets2Lep.at(0), m_signalJets2Lep.at(1));
			  if(mjj >= 50. && mjj <= 100.){
			    cutnumber = 55.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
			    if(mu0_TLV.Pt() >= 30 && mu1_TLV.Pt() >= 30){
			      cutnumber = 56.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
			      float DeltaRmm = fabs(mu0_TLV.DeltaR(mu1_TLV));
			      if(DeltaRmm<1.5){
				cutnumber = 57.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
				float mTmmin = (Mt(mu0, m_met) > Mt(mu1, m_met)) ? Mt(mu1, m_met) : Mt(mu0, m_met);
				if(mTmmin >= 60.){			  
				  cutnumber = 58.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
				  float DeltaPhiMETmm = fabs((mu0_TLV + mu1_TLV).DeltaPhi(m_met->lv()));
				  if(DeltaPhiMETmm>=1.5){
				    cutnumber = 59.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
				    if(m_met->lv().Pt() >= 80.){
				      mZTT_coll = calcMZTauTau_coll(mu0_TLV, mu1_TLV, m_met->lv());
				      mZTT_mmc = calcMZTauTau_mmc(mu0_TLV, mu1_TLV, 1, 1);
				      cutnumber = 60.; fillHistos_MM_SROS1(cutnumber, mcid, weight_ALL_MM);
				    }
				  }
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
	 
  
 ////////////////////////////        EM            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  

//   cout << "m_signalMuons.size()= " << m_signalMuons.size() << " m_signalElectrons.size()= " << m_signalElectrons.size() << " ... m_baseElectrons.size()= " << m_baseElectrons.size() << " m_baseMuons.size()= " <<  m_baseMuons.size() << endl;

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
  Lepton* lep0;
  Lepton* lep1;
  lep0 = (leptons.at(0)->pt > leptons.at(1)->pt) ? leptons.at(0) :leptons.at(1);
  lep1 = (leptons.at(0)->pt > leptons.at(1)->pt) ? leptons.at(1) :leptons.at(0);
  
  cutnumber = 15.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM); //pass category

   
    
    if(muons.size() == 1 && electrons.size() == 1 && fabs(mu->Eta())<=2.4){
      cutnumber = 16.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM); //pass nlep	
	

	el_TLV.SetPtEtaPhiE(el->pt, el->eta ,el->phi, el->pt*cosh(el->eta));
	mu_TLV.SetPtEtaPhiE(mu->pt, mu->eta ,mu->phi, mu->pt*cosh(mu->eta));
	float pt1 = (mu->pt > el->pt) ? mu->pt : el->pt;
	float pt2 = (mu->pt > el->pt) ? el->pt : mu->pt;
	if(m_signalTaus.size() == 0){
	  cutnumber = 17.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
	  if(m_trigObjWithoutRU->passDilEvtTrig(leptons, m_met->Et, nt.evt())){ //valid pT region)   
	    cutnumber = 18.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);

	    if(nt.evt()->isMC || (!nt.evt()->isMC && m_trigObjWithoutRU->passDilTrigMatch(leptons, m_met->Et, nt.evt()))){ //match to trigger
	      cutnumber = 19.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
	      if(!nt.evt()->isMC || CheckRealLeptons(electrons, muons)){
		cutnumber = 20.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
		
// 		time to calc weights:
		//------------------------------------------------------------------------------------
	
		//calc lepton SF:
		float lep_SF_EM = 1.0;
		if(nt.evt()->isMC) lep_SF_EM = mu->effSF * el->effSF;
		//calc trigger weight:
		float trigW_EM = 1.;
		if(nt.evt()->isMC) trigW_EM = m_trigObjWithoutRU->getTriggerWeight(leptons, nt.evt()->isMC, m_met->lv().Et(), numberOfCLJets(m_signalJets2Lep), nt.evt()->nVtx, NtSys_NOM);
		//product of all weights:
		weight_ALL_EM = (nt.evt()->isMC) ? getEventWeight(LUMI_A_L, true) * lep_SF_EM * trigW_EM: 1;
		

		//calc charge flip weights: 
		//Note that the charge flip is only applied in SS region (ee or em) and only for MC events that are true OS.
		//The charge flip changes both the lepton pt of the electron that charge flip and the change needs to be propagated to the met.
		float chargeFlipWeight = 1.0;		
		//make a copy of electrons and MET which will eventually be changed by ChargeFlip tool:
		Electron* el_SS;
		el_SS = electrons.at(0);
		ElectronVector electrons_SS;
		electrons_SS = electrons;
		TLorentzVector el_SS_TLV;
		el_SS_TLV.SetPtEtaPhiE(el_SS->pt, el_SS->eta ,el_SS->phi, el_SS->pt*cosh(el_SS->eta));
		
		TLorentzVector met_SS_TLV;
		TVector2 met_SS_TVector2;
		met_SS_TLV = m_met->lv();
		met_SS_TVector2.Set(met_SS_TLV.Px(), met_SS_TLV.Py());

		int pdg0 = 11 * (-1) * el->q; // Remember 11 = elec which has charge -1
		TLorentzVector empty_TLV;
		  
		  if(el->q*mu->q<0 && nt.evt()->isMC){  
		    m_chargeFlip.setSeed(nt.evt()->event);
		    chargeFlipWeight = m_chargeFlip.OS2SS(pdg0, &el_SS_TLV, 13, &empty_TLV, &met_SS_TVector2, 0);
		    chargeFlipWeight*=  m_chargeFlip.overlapFrac().first;
		    //get changed MET and fill in TLorentzVector:
		    met_SS_TLV.SetPx(met_SS_TVector2.Px());
		    met_SS_TLV.SetPy(met_SS_TVector2.Py());		  
		    met_SS_TLV.SetE(sqrt(pow(met_SS_TVector2.Px(),2) + pow(met_SS_TVector2.Py(),2)));
		}
		float weight_ALL_SS_EM = weight_ALL_EM * chargeFlipWeight;
// 		cout << "weight_ALL_EM= " << weight_ALL_EM;
		//------------------------------------------------------------------------------------
		float METrel_SS = recalcMetRel(met_SS_TLV, el_SS_TLV, mu_TLV, m_signalJets2Lep, useForwardJets);
		calc_EM_variables(leptons, el, mu, mu_TLV, el_SS_TLV, met_SS_TLV, signalJet0_TLV, signalJet1_TLV, useForwardJets);
		if(!nt.evt()->isMC && calcFakeContribution){ 
		  weight_ALL_EM = getFakeWeight(m_baseLeptons, SusyMatrixMethod::FR_SRDavide, METrel, SusyMatrixMethod::SYS_NONE);
		  weight_ALL_SS_EM = getFakeWeight(m_baseLeptons, SusyMatrixMethod::FR_SRDavide, METrel, SusyMatrixMethod::SYS_NONE);
// 		  cout << "  " << weight_ALL_EM << endl;
		}
		
		//------------------------------------------------------------------------------------
		//----------------------------------SR-SS1-EM------------------------------------------
		//------------------------------------------------------------------------------------
		if(nt.evt()->isMC || (!nt.evt()->isMC && (el->q*mu->q)>0)){
		  cutnumber = 21.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM); //SS cut: applied only on weighted events

		  if(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu->pt < 0.1){
		    cutnumber = 22.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
		    if(fabs(el->d0Sig(true))<=3.0){//|d0/sd0|<3   (for electron)
		      cutnumber = 23.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
		      if(numberOfFJets(m_signalJets2Lep) == 0){
			weight_ALL_SS_EM *= getBTagWeight(nt.evt());

			cutnumber = 24.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
			if(numberOfCBJets(m_signalJets2Lep) == 0){
			  cutnumber = 25.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
			  if(numberOfCLJets(m_signalJets2Lep) >=1){
			    cutnumber = 26.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);   		    
			    float METrel_SS = recalcMetRel(met_SS_TLV, el_SS_TLV, mu_TLV, m_signalJets2Lep, useForwardJets);
// 			    if(el_SS_TLV.Pt()>=20. && mu_TLV.Pt()>=20. && ((el_SS_TLV.Pt()>mu_TLV.Pt() && el_SS_TLV.Pt() >= 30.) || (el_SS_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
  
			  //start playing around with cuts:
			    
			    
// minmTl0l1>= 90 GeV (try smaller value),  mT2 >= 80 GeV, DeltaRlljj <= 2.9 or 2.8, (DeltaEtall <= 2.8 ?),  check mTl0>= 130, ..., 200 GeV, mTl1 >= 130 GeV, keep other checks
			    
//forget DeltaPhiMETll, 
			    
			    
			      
			      if(mt2_em>= 80.){
				cutnumber = 30.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				if(METrel_SS>=80.){
				  cutnumber = 31.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				  
				  
				  if(mTWW_EM >= 160.){
				    if(ptl0>=30. && ptl1 >= 20.){
				      cutnumber = 32.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=30. && ptl1 >= 10.){
				      cutnumber = 33.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 10.){
				      cutnumber = 34.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 30.){
				      cutnumber = 35.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=30. && ptl1 >= 30.){
				      cutnumber = 36.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=20. && ptl1 >= 20.){
				      cutnumber = 37.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 20.){
				      cutnumber = 38.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(fabs(eta_l0) <= 1.8 && fabs(eta_l1) <= 1.8){
				      cutnumber = 39.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.2 && fabs(eta_l1) <= 2.2){
				      cutnumber = 40.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.4 && fabs(eta_l1) <= 2.4){
				      cutnumber = 41.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.0 && fabs(eta_l1) <= 2.0){
				      cutnumber = 42.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    if(mTemmin >= 120.){
				      cutnumber = 43.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 110.){
				      cutnumber = 44.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 100.){
				      cutnumber = 45.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 90.){
				      cutnumber = 46.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 80.){
				      cutnumber = 47.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 70.){
				      cutnumber = 48.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 120.){
				      cutnumber = 49.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 130.){
				      cutnumber = 50.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 140.){
				      cutnumber = 51.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 150.){
				      cutnumber = 52.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 160.){
				      cutnumber = 53.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 170.){
				      cutnumber = 54.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 180.){
				      cutnumber = 55.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 190.){
				      cutnumber = 56.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 200.){
				      cutnumber = 57.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 80.){
				      cutnumber = 58.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 90.){
				      cutnumber = 59.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 100.){
				      cutnumber = 60.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 110.){
				      cutnumber = 61.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 120.){
				      cutnumber = 62.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 130.){
				      cutnumber = 63.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=70.){
				      cutnumber = 64.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=80.){
				      cutnumber = 65.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=90.){
				      cutnumber = 66.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=100.){
				      cutnumber = 67.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    // try DeltaPhi(MET,ll) <= 3, 2.9, 2.8, 2.7?
				    if(DeltaPhiMETem <= 3.){
				      cutnumber = 68.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.9){
				      cutnumber = 69.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.8){
				      cutnumber = 71.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.7){
				      cutnumber = 72.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }				      

				    //DeltaR(ll, jj) <= 3 is nice. Try 3.2, 3.1, 2.9, 2.8, 
				    if(DeltaRemjj <= 3.2){
				      cutnumber = 73.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 3.1){
				      cutnumber = 74.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 2.9){
				      cutnumber = 75.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 2.8){
				      cutnumber = 76.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 3.0){
				      cutnumber = 77.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }

				    //Try DeltaEta(l,l) <= 3.0, 2.9, 2.8, 2.7, 2.6
				    if(DeltaEtaem <= 3.0){
				      cutnumber = 78.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.9){
				      cutnumber = 79.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.8){
				      cutnumber = 80.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.7){
				      cutnumber = 81.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.6){
				      cutnumber = 82.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				    }				  
				  }
				  
				  
				}
				if(mTWW_EM >= 170.){
				  
				    if(ptl0>=30. && ptl1 >= 20.){
				      cutnumber = 32.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=30. && ptl1 >= 10.){
				      cutnumber = 33.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 10.){
				      cutnumber = 34.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 30.){
				      cutnumber = 35.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=30. && ptl1 >= 30.){
				      cutnumber = 36.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=20. && ptl1 >= 20.){
				      cutnumber = 37.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(ptl0>=40. && ptl1 >= 20.){
				      cutnumber = 38.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_EM);
				    }
				    if(fabs(eta_l0) <= 1.8 && fabs(eta_l1) <= 1.8){
				      cutnumber = 39.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.2 && fabs(eta_l1) <= 2.2){
				      cutnumber = 40.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.4 && fabs(eta_l1) <= 2.4){
				      cutnumber = 41.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(fabs(eta_l0) <= 2.0 && fabs(eta_l1) <= 2.0){
				      cutnumber = 42.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    if(mTemmin >= 120.){
				      cutnumber = 43.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 110.){
				      cutnumber = 44.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 100.){
				      cutnumber = 45.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 90.){
				      cutnumber = 46.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 80.){
				      cutnumber = 47.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTemmin >= 70.){
				      cutnumber = 48.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 120.){
				      cutnumber = 49.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 130.){
				      cutnumber = 50.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 140.){
				      cutnumber = 51.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 150.){
				      cutnumber = 52.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 160.){
				      cutnumber = 53.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 170.){
				      cutnumber = 54.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 180.){
				      cutnumber = 55.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 190.){
				      cutnumber = 56.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl0MET >= 200.){
				      cutnumber = 57.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 80.){
				      cutnumber = 58.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 90.){
				      cutnumber = 59.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 100.){
				      cutnumber = 60.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 110.){
				      cutnumber = 61.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 120.){
				      cutnumber = 62.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mTl1MET >= 130.){
				      cutnumber = 63.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=70.){
				      cutnumber = 64.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=80.){
				      cutnumber = 65.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=90.){
				      cutnumber = 66.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(mt2_em>=100.){
				      cutnumber = 67.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    // try DeltaPhi(MET,ll) <= 3, 2.9, 2.8, 2.7?
				    if(DeltaPhiMETem <= 3.){
				      cutnumber = 68.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.9){
				      cutnumber = 69.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.8){
				      cutnumber = 71.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaPhiMETem <= 2.7){
				      cutnumber = 72.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }				      

				    //DeltaR(ll, jj) <= 3 is nice. Try 3.2, 3.1, 2.9, 2.8, 
				    if(DeltaRemjj <= 3.2){
				      cutnumber = 73.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 3.1){
				      cutnumber = 74.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 2.9){
				      cutnumber = 75.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 2.8){
				      cutnumber = 76.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaRemjj <= 3.0){
				      cutnumber = 77.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }

				    //Try DeltaEta(l,l) <= 3.0, 2.9, 2.8, 2.7, 2.6
				    if(DeltaEtaem <= 3.0){
				      cutnumber = 78.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.9){
				      cutnumber = 79.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.8){
				      cutnumber = 80.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.7){
				      cutnumber = 81.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }
				    if(DeltaEtaem <= 2.6){
				      cutnumber = 82.; fillHistos_EM_SRSS2(cutnumber, mcid, weight_ALL_SS_EM);
				    }				  
				  }
				}
				if(mTWW_EM>= 150.){
				  cutnumber = 83.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				}
				if(mTWW_EM>= 180.){
				  cutnumber = 84.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				}
				if(mTWW_EM>= 190.){
				  cutnumber = 85.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				}
				if(mTWW_EM>= 200.){
				  cutnumber = 86.; fillHistos_EM_SRSS1(cutnumber, mcid, weight_ALL_SS_EM);
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
			    
			 

		//------------------------------------------------------------------------------------
		//----------------------------------SR-OS1-EM------------------------------------------
		//------------------------------------------------------------------------------------
		mZTT_mmc = calcMZTauTau_mmc(el_SS_TLV, mu_TLV, 0, 1);
		if((el->q * mu->q)<0){
		  cutnumber = 50.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
		  if(muEtConeCorr(mu, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC)/mu->pt < 0.1/* && fabs(el->d0Sig(true))<=3.0*/){//|d0/sd0|<3   (for electron)
		    cutnumber = 51.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
		    if(numberOfFJets(m_signalJets2Lep) == 0){
		      weight_ALL_EM *= getBTagWeight(nt.evt());
		      cutnumber = 52.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
		      if(numberOfCBJets(m_signalJets2Lep) == 0){
			cutnumber = 53.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
			if(numberOfCLJets(m_signalJets2Lep) >=2){
			  cutnumber = 54.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
			  mjj = Mll(m_signalJets2Lep.at(0), m_signalJets2Lep.at(1));
			  if(mjj >= 50. && mjj <= 100.){
			    cutnumber = 55.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
			    if(el_TLV.Pt()>=30. && mu_TLV.Pt()>=30. && ((el_TLV.Pt()>mu_TLV.Pt() && el_TLV.Pt() >= 30.) || (el_TLV.Pt()<mu_TLV.Pt() && mu_TLV.Pt() >= 30.))){
			      cutnumber = 56.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
			      float DeltaRem = fabs(el_TLV.DeltaR(mu_TLV));
			      if(DeltaRem<=1.5){
				cutnumber = 57.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
				float mTemmin = (Mt(el, m_met) > Mt(mu, m_met)) ? Mt(mu, m_met) : Mt(el, m_met);
				if(mTemmin >= 60.){
				cutnumber = 58.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
				float DeltaPhiMETem = fabs((el_TLV + mu_TLV).DeltaPhi(m_met->lv()));
				if(DeltaPhiMETem>=1.5){
				  cutnumber = 59.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);
				  if(m_met->lv().Pt() >= 80.){
				    mZTT_coll = calcMZTauTau_coll(el_SS_TLV, mu_TLV, met_SS_TLV);
// 				    mZTT_mmc = calcMZTauTau_mmc(el_SS_TLV, mu_TLV, 0, 1);
				    cutnumber = 60.; fillHistos_EM_SROS1(cutnumber, mcid, weight_ALL_EM);	      
				    }
				  }
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }

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
float TSelector_SusyNtuple::getBTagWeight(const Event* evt)
{
  JetVector tempJets;
  for(uint ij=0; ij<m_baseJets.size(); ++ij){
    Jet* jet = m_baseJets.at(ij);
    if( !(jet->Pt() > 20 && fabs(jet->detEta) < 2.4) ) continue;
    tempJets.push_back(jet);
  }

  return bTagSF(evt, tempJets, nt.evt()->mcChannel, BTag_NOM);
// return 0.;
}


/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple::checkLeptonPt(const LeptonVector& leptons)
{
//   cout << "leptons[0]->pt= " << leptons[0]->pt << " leptons[1]->pt= " << leptons[1]->pt << endl;
  if(leptons[0]->pt>leptons[1]->pt){
	  if(leptons[0]->pt>35. && leptons[1]->pt>20.) return true;
	  else return false;
  }
  else{
	  if(leptons[1]->pt>35. && leptons[0]->pt>20.) return true;
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

//   ht = Meff(*leptons, *jets, met, JET_PT_CUT);  //The function is defined in SusyNtTools.cxx  & is  the sum  pT of leptons, jets and met
// where JET_PT_CUT = 20 (the default in the function uses pt=40)
  
//   float SusyNtTools::Meff(const LeptonVector& leps, const JetVector& jets, const Met* met)
// {
//   float meff = 0;
//   for(uint i=0; i<leps.size(); i++) meff += leps[i]->Pt();
//   for(uint i=0; i<jets.size(); i++){
//     if(jets[i]->Pt() > 40) meff += jets[i]->Pt();
//   }
//   meff += met->Et;
//   return meff;
// }
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::calcMeff(TLorentzVector met, const JetVector &signalJets){
  //Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/ToyNt.cxx#L404
  //mEff : same as HT but without the lepton
  float HT = 0;
//   HT += l1.Pt();
//   HT += l2.Pt();
  
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
  double pA[3]     = {0.0, l0.Px(), l0.Py()};
  double pB[3]     = {0.0, l1.Px(), l1.Py()};
  
  // Create Mt2 object
  mt2_bisect::mt2 mt2_event;
  mt2_event.set_momenta(pA,pB,pTMiss);
  mt2_event.set_mn(0); // LSP mass = 0 is Generic
  
  return mt2_event.get_mt2();
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
     
//   float sum_et = 0.;
//   sum_et += m_met->refEle_sumet;
//   sum_et += m_met->refGamma_sumet;
//   //taus?
//   sum_et += m_met->refJet_sumet;
//   sum_et += m_met->softTerm_sumet;
//   sum_et += m_met->refMuo_sumet;  
// 
//   TLorentzVector vec1, vec2;
//   vec1 = lep1; //ELECTRON
//   vec2 = lep2; // MUON
// 
//   float met_resolution = 0.;
// //   cout << "nSignalJets= " << nSignalJets << endl;
//   if(nt.evt()->isMC){
//     if(nSignalJets==0){
//       met_resolution = 4.447 + 0.505 * sqrt(sum_et);
//     }
//     if(nSignalJets==1){
//       met_resolution = 5.000 + 0.500 * sqrt(sum_et);
//     }
//     if(nSignalJets==2){
//       met_resolution = 4.635 + 0.514 * sqrt(sum_et);
//     }
//     if(nSignalJets>=3){
//       met_resolution = 4.528 + 0.513 * sqrt(sum_et);
//     }
//   }
// 
//   if(!nt.evt()->isMC){
//     if(nSignalJets==0){
//       met_resolution = 4.314 + 0.498 * sqrt(sum_et);
//     }
//     if(nSignalJets==1){
//       met_resolution = 4.700 + 0.509 * sqrt(sum_et);
//     }
//     if(nSignalJets==2){
//       met_resolution = 4.539 + 0.519 * sqrt(sum_et);
//     }
//     if(nSignalJets>=3){
//       met_resolution = 3.897 + 0.540 * sqrt(sum_et);
//     }
//   }
// //   mode:
// //   11 - for ee final state
// //   13 - for emu final state
// //   31 - for mue final state
// //   33 - for mumu final state
// 
//   int mode = 0;
//   
//   if(tau0_decay_type == 0 && tau1_decay_type == 0) mode = 11; //EE channel
// 
//   if(tau0_decay_type == 0 && tau1_decay_type == 1){ //EM channel
//     if(vec1.Pt() > vec2.Pt()) mode = 13; //EMU
//     if(vec1.Pt() < vec2.Pt()) mode = 31; //MUE
//   }
//   if(tau0_decay_type == 1 && tau1_decay_type == 1) mode = 33; //MM channel
//   
//   MMC_sumet.Clear();
// //   cout << "lep1.Pt()= " << lep1.Pt() << " lep2.Pt()= " << lep2.Pt() << " m_met->lv().Px()= " << m_met->lv().Px() << " m_met->lv().Py()= " << m_met->lv().Py() << " met_resolution= " << met_resolution << " mode= " << mode;
//   MMC_sumet.Scan6dAnal(vec1, vec2, m_met->lv().Px(), m_met->lv().Py(), met_resolution, mode); 
//   
// //   MMC_sumet.Set_Alpha(1.);
// //   MMC_sumet.Scan6d(vec1, vec2, m_met->lv().Px(), m_met->lv().Py(), met_resolution, mode); 
//   
//   float met_ex = MMC_sumet.GetCorrMEX();
//   float met_ey = MMC_sumet.GetCorrMEY();
// //   cout << " corrected met_ex= " << met_ex << " met_ey= " << met_ey << endl;
//   
// //   if (isnan(met_ex) || isnan(met_ey) ){
// //     met_ex = m_met->lv().Px();
// //     met_ey = m_met->lv().Py();
// //     cout << "shift corrected met to old values because NAN" << endl;
// //   }
//   MMC_sumet.Scan4dAnal(vec1, vec2, met_ex, met_ey, mode);
//     //validate: which method is best to get mass value? 
//   float mZTauTau_mmc = -1.;
//   mZTauTau_mmc = MMC_sumet.GetMZ_peak(); 
// //   cout << "MMC_sumet.GetMZ_mean()= " << MMC_sumet.GetMZ_mean() << " MMC_sumet.GetMZ_maxprob()= " << MMC_sumet.GetMZ_maxprob() << endl;
// //   cout << "mZTauTau_mmc= " << mZTauTau_mmc << endl;
//   return mZTauTau_mmc;
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
float TSelector_SusyNtuple::getFakeWeight(const LeptonVector &baseLeps, 
                                      SusyMatrixMethod::FAKE_REGION region, 
                                      float metRel,
                                      SusyMatrixMethod::SYSTEMATIC sys)
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
const Jet* TSelector_SusyNtuple::getClosestJet(const Lepton* lep)
{
  const Jet* closestJet;
  float mindR=0.6;
  
  for(uint j=0; j<m_baseJets.size(); j++){
    const Jet* cj = m_baseJets.at(j);
    
    if(lep->DeltaR(*cj)>mindR) continue;
    mindR = lep->DeltaR(*cj);
    closestJet = cj;
  }
  return closestJet;
}		

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple::recalc_D0(bool unbiased, const Lepton* lep, const Jet* closestJet)
{
  // recalculate sign of d0. 
  // For significance, still needs to be divided by err!!!

  float d0_branch;
  
  if(unbiased){
    d0_branch = lep->d0Unbiased;
  }
  else{
    d0_branch = lep->d0;
  }
//calc sign of d0 from ntuple ('branch'):		  
  float qd0 =d0_branch/fabs(d0_branch);
  
// calc angle "Phi" between jet and direction to the track (= lepton) closest point from the PMV, based on (closestJet->phi - lep->phi)
  float phi_lepd0 = lep->phi + qd0 * TMath::Pi()/2.;
  float Phi = phi_lepd0- closestJet->phi;
  
// recalc sign = sign of cos(Phi):   
  float signIP_lep =  fabs(cos(Phi))/(cos(Phi)+1e-32) * fabs(d0_branch); 
  return signIP_lep;

  
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

void TSelector_SusyNtuple::SlaveTerminate()
{
  //   SusyNtAna::Terminate();
  if(m_dbg) cout << "TSelector_SusyNtuple::Terminate" << endl;

  if(m_writeOut) {
    out.close();
  }
    

  if(!runWithPoD){
 
  
    TString outputfile="";

    if(sample_identifier == 126988)outputfile="histos_ZN_WW_version7.root";
    if(sample_identifier == 108346)outputfile="histos_ZN_ttbarWtop_version7_DeltaRClosestJet06.root";
    if(sample_identifier == 110805)outputfile="histos_ZN_ZPlusJets_version7.root";
    if(sample_identifier == 157814)outputfile="histos_ZN_ZV_version7.root";
    if(sample_identifier == 160155)outputfile="histos_ZN_Higgs_version7.root";
    if(sample_identifier == 126893)outputfile="histos_cutflow_126893_TSelector.root";
    if(sample_identifier == 176576)outputfile="histos_cutflow_176576_TSelector.root";
    if(sample_identifier == 177502)outputfile="histos_ZN_177502_version7.root";
    if(sample_identifier == 177503)outputfile="histos_ZN_177503_version7.root";
    if(sample_identifier == 177504)outputfile="histos_ZN_177504_version7.root";
    if(sample_identifier == 177506)outputfile="histos_ZN_177506_version7.root";
    if(sample_identifier == 177508)outputfile="histos_ZN_177508_version7.root";
    if(sample_identifier == 177509)outputfile="histos_ZN_177509_version7.root";
    if(sample_identifier == 177510)outputfile="histos_ZN_177510_version7.root";
    if(sample_identifier == 177512)outputfile="histos_ZN_177512_version7.root";
    if(sample_identifier == 177513)outputfile="histos_ZN_177513_version7.root";
    if(sample_identifier == 177514)outputfile="histos_ZN_177514_version7.root";
    if(sample_identifier == 177517)outputfile="histos_ZN_177517_version7.root";
    if(sample_identifier == 177521)outputfile="histos_ZN_177521_version7.root";
    if(sample_identifier == 177522)outputfile="histos_ZN_177522_version7.root";
    if(sample_identifier == 177523)outputfile="histos_ZN_177523_version7.root";
    if(sample_identifier == 177524)outputfile="histos_ZN_177524_version7.root";
    if(sample_identifier == 177525)outputfile="histos_ZN_177525_version7.root";
    if(sample_identifier == 177526)outputfile="histos_ZN_177526_version7.root";
    if(sample_identifier == 177527)outputfile="histos_ZN_177527_version7.root";
    
    if(sample_identifier == 111111) outputfile="histos_fake_Egamma_version7_2.root";


/*  
    
//     if(sample_identifier>=176574 && sample_identifier <= 176640){
//     char buffer[10];
//     ostrstream Str(buffer, 10);
//     Str << sample_identifier << ends;
//     string ZahlAlsString(Str.str());
//     string str;
//     string str1 = "histos_ZN_tauveto_signal_";
//     str.append(str1); 
//     str.append(ZahlAlsString); 
//     string str2 = ".root";
//     str.append(str2);
//     outputfile = str;
//     }*/
    cout << " " << endl;
    cout << "ouputfile: " << outputfile << endl;
    cout << " " << endl;
   TFile* output_file = new TFile(outputfile, "recreate") ;//update or recreate?

   output_file->cd();
	  
   writeHistos();  

   output_file->Write() ;
   output_file->Close();
    
  }
}
/*--------------------------------------------------------------------------------*/
// The Terminate() function is the last function to be called
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple::Terminate()
{
 
}
