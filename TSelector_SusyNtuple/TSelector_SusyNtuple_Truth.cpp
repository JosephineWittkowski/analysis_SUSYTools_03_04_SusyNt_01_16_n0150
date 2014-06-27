#include <iomanip>
#include "TCanvas.h"
#include "TFile.h"
#include "TChainElement.h"

#include "TSelector_SusyNtuple_Truth.hpp"
#include "histos_WH_analysis_Truth.C"
#include <string>
#include <strstream>
using namespace std;
using namespace Susy;
// using FourMom;

/*--------------------------------------------------------------------------------*/
// TSelector_SusyNtuple_Truth Constructor
/*--------------------------------------------------------------------------------*/
TSelector_SusyNtuple_Truth::TSelector_SusyNtuple_Truth() :
        m_selectB (false),
        m_vetoB (false),
        m_selectSFOS(false),
        m_vetoSFOS (false),
	file_(0),
	tree_(0),
        m_writeOut (false)
{
//   setAnaType(Ana_2LepWH);
  setDebug(false);

  if(m_writeOut) {
    out.open("event.dump");
  }
}

/*--------------------------------------------------------------------------------*/
// The Begin() function is called at the start of the query.
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::Begin(TTree * /*tree*/)
{

  n0150BugFix = true;
  TString option = GetOption();
  SysSetting = NtSys_NOM;


}
void TSelector_SusyNtuple_Truth::SlaveBegin(TTree* /*tree*/)
{
  
  calcSysUncert = true;
  makeNTuple = false;
  defineHistos();
  if(calcSysUncert) defineHistos_sysUncert();


  SusyNtTruthAna::Begin(0);


  m_trigObjWithoutRU = new DilTrigLogic("Moriond",false/*No Reweight Utils!*/);
  
  cout << "initialize chargeFlip tool" << endl;
  
//   m_chargeFlip.initialize("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/ChargeFlip/data/d0_new2d_chargeflip_map.root");
  
//   m_matrix = new SusyMatrixMethod::DiLeptonMatrixMethod();
//   m_matrix->configure("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SusyMatrixMethod/data/FinalFakeHist_Feb_02.root", SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT, SusyMatrixMethod::PT);
  if(makeNTuple) initTupleMaker("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SusySel_Egamma_6_NEW.root", "SusySel");
//   string xsecFileName  = gSystem->ExpandPathName("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SUSYTools/data/susy_crosssections_8TeV.txt");
//   m_susyXsec = new SUSY::CrossSectionDB("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/SUSYTools/data/mc12_8TeV/Herwigpp_UEEE3_CTEQ6L1_simplifiedModel_wA.txt");
  
}



Bool_t TSelector_SusyNtuple_Truth::Process(Long64_t entry)
{
  
  
  GetEntry(entry); //function from SusyNtAna.h
  
  clearTruthObjects(); //function from SusyNtAna.cxx

  
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
    if(nt.evt()->event == 1273710) sample_identifier = 10002; //Egamma 2
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
  clearTruthObjects();
//   selectTruthObjects();
  const Susy::TruthMet* truthMet = getTruthMet(&nt);
  TLorentzVector truthMet_TLV = truthMet->lv();
  TruthParticleVector truthElectrons = getPreTruthLeptons(&nt,11); //10 GeV, |eta|<2.47
  TruthParticleVector truthMuons     = getPreTruthLeptons(&nt,13);// 10 GeV, |eta|<2.4
  TruthParticleVector truthTaus      = getPreTruthLeptons(&nt,15);// 20 GeV, |eta|<2.5
  TruthJetVector truthJets      = getPreTruthJets   (&nt   ); // 20 GeV, |eta|<4.5

//   cout << "event " << nt.evt()->event << endl;
  
//   for(uint index=0; index<nt.tpr()->size(); ++index){
//     TruthParticle* particle = & nt.tpr()->at(index);
//     if(fabs(particle->pdgId) == 11) {
//       cout << "truth particle pt " << particle->Pt() << ", eta " << particle->Eta() << endl;
//     }
//   }
//   for (int i=0; i<truthTaus.size(); i++){
//     const TruthParticle* t = truthTaus.at(i);
//     cout << "t->Pt()= " << t->Pt() << endl;
//   }

//   for(uint index=0; index<nt.tjt()->size(); ++index){
//     TruthJet* jet = & nt.tjt()->at(index);
//     cout << "jet pt " << jet->Pt() << " eta " << jet->Eta() << endl;
//   }
//   for (int i=0; i<truthJets.size(); i++){
//     const TruthJet* j = truthJets.at(i);
//     cout << "j->Pt()= " << j->Pt() << endl;
//   }
//   for (int i=0; i<truthMuons.size(); i++){
//     const TruthParticle* m = truthMuons.at(i);
//     cout << "m->Pt()= " << m->Pt() << endl;
//     for (int k=0; k<truthMuons.size(); k++){
//       if (i==k) continue;
//       const TruthParticle* m1 = truthMuons.at(k);
//       cout << "m1->Pt()= " << m1->Pt() << endl;
//       cout << "m1->DeltaR(*m) " << m1->DeltaR(*m) << " q*q " << m->charge*m1->charge << " mll " << SusyNtAna::Mll(m,m1) <<  endl;
//     }
//   }
  overlapProcedure(truthElectrons, truthMuons, truthTaus, truthJets);
//   cout << "after overlapProcedure(): " << endl;
//   for (int i=0; i<truthElectrons.size(); i++){
//     const TruthParticle* e = truthElectrons.at(i);
//     cout << "e->Pt()= " << e->Pt() << endl;
//     for (int k=0; k<truthJets.size(); k++){
//       const TruthJet* j = truthJets.at(k);
//       cout << "j->Pt()= " << j->Pt() << endl;
//       cout << "j->DeltaR(*e) " << j->DeltaR(*e) << endl;
//     }
//   }
  
//   cout << "truth jets: " << endl;
//   for (int i=0; i<truthJets.size(); i++){
//     const TruthJet* j = truthJets.at(i);
//     cout << "pt " << j->Pt() << " eta " << j->Eta() << endl;
//   }
  
  // Do we really need overlap removal at the truth level
  // I'm not 100% sold on this, so I skip at the moment

  // Do SFOS removal for Mll < 20 GeV
  removeSFOSPair(truthElectrons);
  removeSFOSPair(truthMuons    );
//   for (int i=0; i<truthMuons.size(); i++){
//     const TruthParticle* m = truthMuons.at(i);
//     cout << "m->Pt()= " << m->Pt() << endl;
//     for (int k=0; k<truthMuons.size(); k++){
//       if (i==k) continue;
//       const TruthParticle* m1 = truthMuons.at(k);
//       cout << "m1->Pt()= " << m1->Pt() << endl;
//       cout << "m1->DeltaR(*m) " << m1->DeltaR(*m) << " q*q " << m->charge*m1->charge << " mll " << SusyNtAna::Mll(m,m1) <<  endl;
//     }
//   }
//   removeSFOSPair(truthTaus     ); 
  
  TruthParticleVector signal_truthElectrons = truthElectrons; //leptons: same as baseline selection.
  TruthParticleVector signal_truthMuons = truthMuons;
  TruthParticleVector signal_truthTaus = truthTaus;
  TruthJetVector signal_L20truthJets = getTruthJetsL20(truthJets); //jets: pt>20 GeV, |eta|<=2.4, not matched to b quark
  TruthJetVector signal_F30truthJets = getTruthJetsF30(truthJets); //jets: pt>30 GeV, |eta|>2.4
  TruthJetVector signal_B20truthJets = getTruthJetsB20(truthJets); //jets: pt>20 GeV, |eta|<=2.4, matched to b quark
  TruthJetVector signal_truthJets = getTruthJetsSignal(truthJets); //jets: pt>20 GeV, |eta|<=2.4 or pt > 30 GeV and |eta| > 2.4
  
  calcJet_variables(truthMet_TLV, signal_truthJets);
  
//   cout << "signal_L20truthJets: " << endl;
//   for (int i=0; i<signal_L20truthJets.size(); i++){
//     const TruthJet* j = signal_L20truthJets.at(i);
//     cout << "pt " << j->Pt() << " eta " << j->Eta() << endl;
//   }
//   
//   cout << "signal_F30truthJets: " << endl;
//   for (int i=0; i<signal_F30truthJets.size(); i++){
//     const TruthJet* j = signal_F30truthJets.at(i);
//     cout << "pt " << j->Pt() << " eta " << j->Eta() << endl;
//   }
//   
//   cout << "signal_B20truthJets: " << endl;
//   for (int i=0; i<signal_B20truthJets.size(); i++){
//     const TruthJet* j = signal_B20truthJets.at(i);
//     cout << "pt " << j->Pt() << " eta " << j->Eta() << endl;
//   }
//   
//   cout << "signal_truthJets: " << endl;
//   for (int i=0; i<signal_truthJets.size(); i++){
//     const TruthJet* j = signal_truthJets.at(i);
//     cout << "pt " << j->Pt() << " eta " << j->Eta() << endl;
//   }
  
  


  
  int flag = nt.evt()->cutFlags[SysSetting];  
  float weight_ALL = 1.;//(nt.evt()->isMC) ? SusyNtTools::getEventWeight(nt.evt(), LUMI_A_L, true, &m_sumwMap, false, true, SysSettingPileup) : 1.;
//   //   if(mcid>= 177501 && mcid <= 177527) 	weight_ALL = weight_ALL/nt.evt()->xsec * m_susyXsec->xsectTimesEff(mcid);
//     
    float weight_ALL_EE = weight_ALL;
    float weight_ALL_MM = weight_ALL;
    float weight_ALL_EM = weight_ALL;
//   
//     Anders: I'm skipping many of the event cleaning cuts. Some of them are simply not applicable to MC truth - There are no cosmic muons, and there are no mismeasured or misidentified objects. The goodPrimaryVertex cut, for example, is based on the number of tracks leading to a given vertex. The corresponding number does not exist in truth. All you have is the (x, y, z) position of each vertex. It's possible that you could simulate the vx_nTracks variable if you looked up the official definition of how tracks are assigned to vertices, but not without significant extra work.
//   //event cleaning doesn't need to be changed after agreement on cutflow:
  if(doEventCleaning_andFillHistos(truthJets, truthMet, truthMuons, truthElectrons, flag, weight_ALL_EE, weight_ALL_MM, weight_ALL_EM, SysSetting, n0150BugFix)){
  
    //Set TLorentzVector for jets:
    TruthJet* jet0_buff;
    TruthJet* jet1_buff;
    TLorentzVector signalJet0_buff_TLV, signalJet1_buff_TLV;
//     nSignalJets = signal_truthJets.size();
    if(nSignalJets >=1){
      jet0_buff = signal_truthJets.at(0);

      signalJet0_buff_TLV.SetPtEtaPhiE(jet0_buff->Pt(), jet0_buff->eta, jet0_buff->phi, jet0_buff->Pt()*cosh(jet0_buff->eta));
      signalJet0_buff_TLV.SetPtEtaPhiM(jet0_buff->Pt(), jet0_buff->eta, jet0_buff->phi, jet0_buff->m);
      if(nSignalJets >=2){	
	jet1_buff = signal_truthJets.at(1);
	signalJet1_buff_TLV.SetPtEtaPhiE(jet1_buff->Pt(), jet1_buff->eta, jet1_buff->phi, jet1_buff->Pt()*cosh(jet1_buff->eta));
	signalJet1_buff_TLV.SetPtEtaPhiM(jet1_buff->Pt(), jet1_buff->eta, jet1_buff->phi, jet1_buff->m);
	
      }
    }
    //now use buffer to fill jets variables (otherwise code crashes):
    TruthJet* jet0;
    TruthJet* jet1;
    TLorentzVector signalJet0_TLV, signalJet1_TLV;
    jet0 = jet0_buff;
    signalJet0_TLV = signalJet0_buff_TLV;
    if(nSignalJets >=2){	
      jet0 = (jet0_buff->Pt() > jet1_buff->Pt()) ? jet0_buff : jet1_buff;
      jet1 = (jet0_buff->Pt() > jet1_buff->Pt()) ? jet1_buff : jet0_buff;
      signalJet1_TLV = (jet0_buff->Pt() > jet1_buff->Pt()) ? signalJet1_buff_TLV : signalJet0_buff_TLV;
      signalJet0_TLV = (jet0_buff->Pt() > jet1_buff->Pt()) ? signalJet0_buff_TLV : signalJet1_buff_TLV;
    }

    bool useForwardJets = true;
    //make a copy of electrons and MET which will eventually be changed by ChargeFlip tool:
    
    float cutnumber;
    
    //////////////// EE //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(truthElectrons.size() == 2){
      cutnumber = 15.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
      if(signal_truthElectrons.size() == 2){
	cutnumber = 16.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	if(signal_truthTaus.size()==0){
	  cutnumber = 17.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	  if(( 14 < signal_truthElectrons.at(0)->Pt() && 14 < signal_truthElectrons.at(1)->Pt() ) ||   (25 < signal_truthElectrons.at(0)->Pt() && 10 < signal_truthElectrons.at(1)->Pt() && signal_truthElectrons.at(1)->Pt() <= 14 )){
	    cutnumber = 18.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	    cutnumber = 19.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	    cutnumber = 20.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
	    if(signal_truthElectrons.at(0)->charge * signal_truthElectrons.at(1)->charge > 0.){ // genuine SS events
	      cutnumber = 21.; fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
// 	      TruthParticleVector electrons_SS;
	      TruthParticle* el0_SS;
	      TruthParticle* el1_SS;
	      el0_SS = (signal_truthElectrons.at(0)->Pt() > signal_truthElectrons.at(1)->Pt()) ? signal_truthElectrons.at(0) : signal_truthElectrons.at(1);
	      el1_SS = (signal_truthElectrons.at(0)->Pt() > signal_truthElectrons.at(1)->Pt()) ? signal_truthElectrons.at(1) : signal_truthElectrons.at(0);
	      TLorentzVector el0_SS_TLV(*el0_SS);
	      TLorentzVector el1_SS_TLV(*el1_SS);
	      
	      
	      calc_EE_variables(el0_SS, el1_SS, el0_SS_TLV, el1_SS_TLV, signal_truthJets, signalJet0_TLV, signalJet1_TLV, truthMet_TLV);
	      
	      if((mllZcandImpact_EE > MZ+20. || mllZcandImpact_EE < MZ-20.)){
		cutnumber = 22.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
		if(signal_F30truthJets.size()==0){
		  cutnumber = 23.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
		  if(signal_B20truthJets.size()==0){
		    cutnumber = 24.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
		    ///////////////////////////////////////////////////////////////////
		    //                1jet                //////////////
		    ///////////////////////////////////////////////////////////////////
		    if(signal_truthJets.size()==1){
		      cutnumber = 25.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
		      if(el0_SS->Pt() > 30. && el1_SS->Pt() > 20.){
			cutnumber = 26.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE); 
			
			if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
			  cutnumber = 27.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE); //ZVeto
			  cutnumber = 28.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			  cutnumber = 29.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			  if(Mlj_EE < 90.){
			    cutnumber = 30.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			    if(HT_EE > 200.){			    
			      cutnumber = 31.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);		  
    // 			  from MET, calculate METrel
			      
			      float METrel_EE = recalcMetRel(truthMet_TLV, el0_SS_TLV, el1_SS_TLV, signal_truthJets, useForwardJets);
			      if(METrel_EE > 55.){
				cutnumber = 32.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);		  
				cutnumber = 33.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			      }
			    }
			  }
			}
		      }
		    }
		    ///////////////////////////////////////////////////////////////////
		    //                2,3jet                //////////////
		    ///////////////////////////////////////////////////////////////////
		    
		    if(signal_truthJets.size() >=2 && signal_truthJets.size() <=3){
		      cutnumber = 34.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);	

		      if(el0_SS->Pt() > 30. && el1_SS->Pt() > 20.){

			cutnumber = 35.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			if((el0_SS_TLV + el1_SS_TLV).M() > MZ+10. || (el0_SS_TLV + el1_SS_TLV).M() < MZ-10.){
			  cutnumber = 36.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE); //ZVeto
			  cutnumber = 37.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			  
			  if(mTmax_EE > 110.){
			    cutnumber = 38.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			    if(Mljj_EE < 120.){
			      cutnumber = 39.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			      cutnumber = 40.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			      float METrel_EE = recalcMetRel(truthMet_TLV, el0_SS_TLV, el1_SS_TLV, signal_truthJets, useForwardJets);
			      if(METrel_EE>=30.){			    
				cutnumber = 41.;  fillHistos_EE_SRSS1(cutnumber, weight_ALL_EE);
			      }
			    }
			  }
			}
		      }
		    }//end >=2 jets_
		  }
		}
	      }
	    }
	  }
	}
//       }
      
    
      
    }
    }
    
  //////////////////// MM //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(truthMuons.size() == 2){
      cutnumber = 15.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
      if(signal_truthMuons.size()==2){
	cutnumber = 16.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	
	if(signal_truthTaus.size()==0){
	  cutnumber = 17.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	  
	    if(( 18 < signal_truthMuons.at(0)->Pt() && 18 < signal_truthMuons.at(1)->Pt() ) || (18 < signal_truthMuons.at(0)->Pt() && 14 < signal_truthMuons.at(1)->Pt() && signal_truthMuons.at(1)->Pt() <= 18) || ( 18 < signal_truthMuons.at(0)->Pt() && 8 < signal_truthMuons.at(1)->Pt() && signal_truthMuons.at(1)->Pt() <= 14 ) || ( 14 < signal_truthMuons.at(0)->Pt() && signal_truthMuons.at(0)->Pt() <= 18 && 14 < signal_truthMuons.at(1)->Pt() ) ){
	      
	      cutnumber = 18.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	      cutnumber = 19.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	      cutnumber = 20.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
	      
	      if(signal_truthMuons.at(0)->charge * signal_truthMuons.at(1)->charge > 0.){
		cutnumber = 21.; fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
		
		TruthParticle* mu0;
		TruthParticle* mu1;

		mu0 = (signal_truthMuons.at(0)->Pt() > signal_truthMuons.at(1)->Pt()) ? signal_truthMuons.at(0) : signal_truthMuons.at(1);
		mu1 = (signal_truthMuons.at(0)->Pt() > signal_truthMuons.at(1)->Pt()) ? signal_truthMuons.at(1) : signal_truthMuons.at(0);
		TLorentzVector mu0_TLV(*mu0);
		TLorentzVector mu1_TLV(*mu1);
		
		calc_MM_variables(mu0, mu1, mu0_TLV, mu1_TLV, signal_truthJets, signalJet0_TLV, signalJet1_TLV, truthMet_TLV);
		
		if((mllZcandImpact_MM > MZ+20. || mllZcandImpact_MM < MZ-20.)){
		  cutnumber = 22.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
		  if(signal_F30truthJets.size()==0){
		    cutnumber = 23.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
		    if(signal_B20truthJets.size()==0){
		      cutnumber = 24.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
		      
		      ///////////////////////////////////////////////////////////////
		      ///////////       1 jet /////////////////////////////
		      ///////////////////////////////////////////////////////////////
		      
		      if(signal_truthJets.size() ==1){
			cutnumber = 25.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);		    
			if(mu0->Pt() > 30 && mu1->Pt() > 20){
			  cutnumber = 26.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			  cutnumber = 27.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //ZVeto
			  if(DeltaEtall_MM < 1.5){
			    cutnumber = 28.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			      
			    if(mTmax_MM > 110.){
			      cutnumber = 29.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			      if(Mlj_MM < 90.){
				cutnumber = 30.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			    
				if(HT_MM > 200.){
				  cutnumber = 31.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
				}
			      }
			    }
			  }
			}
		      }//end ==1 jets

		      ///////////////////////////////////////////////////////////////
		      ///////////       2,3 jets /////////////////////////////
		      ///////////////////////////////////////////////////////////////		      
		      if(signal_truthJets.size() >=2 && signal_truthJets.size() <=3){
			cutnumber = 34.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			if(mu0->Pt() > 30 && mu1->Pt() > 30){
			  cutnumber = 35.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			  
			  cutnumber = 36.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM); //ZVeto
			  if(DeltaEtall_MM<1.5){
			    cutnumber = 37.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			    cutnumber = 38.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			    
			    if(Mljj_MM < 120.){
			      cutnumber = 39.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);
			      if(HT_MM >= 200.){
				cutnumber = 40.;  fillHistos_MM_SRSS1(cutnumber, weight_ALL_MM);	
			      }
			    }
			  }
			}
		      }//end >=2 jets      
		    }
		  }
		}
	      }
	    }
	  
	  
	  
	}
      }
      
    }
    
  //////////////////////////// EM //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(truthElectrons.size() == 1 && truthMuons.size() == 1){
      cutnumber = 15.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
      
      if(signal_truthElectrons.size()==1 && signal_truthMuons.size()==1){
	cutnumber = 16.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	
	if(signal_truthTaus.size()==0){
	  cutnumber = 17.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	    if( ( 14 < signal_truthElectrons.at(0)->Pt() && 8 < signal_truthMuons.at(0)->Pt()) || ( 10 < signal_truthElectrons.at(0)->Pt() && signal_truthElectrons.at(0)->Pt() <= 14 && 18 < signal_truthMuons.at(0)->Pt()) ){
	      cutnumber = 18.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	      cutnumber = 19.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	      cutnumber = 20.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
	      
	      if(signal_truthElectrons.at(0)->charge * signal_truthMuons.at(0)->charge > 0.){
		cutnumber = 21.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
		TruthParticle* mu;
		TruthParticle* el;

		mu = signal_truthMuons.at(0);
		el = signal_truthElectrons.at(0);
		TLorentzVector mu_TLV(*mu);
		TLorentzVector el_TLV(*el);
		
		calc_EM_variables(mu, el, mu_TLV, el_TLV, signal_truthJets, signalJet0_TLV, signalJet1_TLV, truthMet_TLV);
		
		if((mllZcandImpact_mu_EM > MZ+20. || mllZcandImpact_mu_EM < MZ-20.) && (mllZcandImpact_el_EM > MZ+20. || mllZcandImpact_el_EM < MZ-20.)){
		  cutnumber = 22.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
		  if(signal_F30truthJets.size()==0){
		    cutnumber = 23.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
		    if(signal_B20truthJets.size()==0){
		      cutnumber = 24.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
		      /////////////////////////////////////////////////////////////////
		      //             1 jet ///////////////////////////////////
		      /////////////////////////////////////////////////////////////////
		      if(nSignalJets ==1){
			cutnumber = 25.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			if(el->Pt() > 30. && mu->Pt() > 30.){
			  cutnumber = 26.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			  cutnumber = 27.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM); //ZVeto
			  
			  if(DeltaEtall_EM < 1.5){
			    cutnumber = 28.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);				
			    if(mTmax_EM > 110){
			      cutnumber = 29.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			      if(Mlj_EM < 90.){
				cutnumber = 30.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
// 				cout << "HT_EM= " << HT_EM << endl;
				if(HT_EM > 200.){
				  cutnumber = 31.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
				  cutnumber = 32.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
				  cutnumber = 33.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);				  
				}				 
			      }
			    }
			  }
			}
		      }//end ==1jet
		      
		      /////////////////////////////////////////////////////////////////
		      //             2,3 jets ///////////////////////////////////
		      /////////////////////////////////////////////////////////////////		
		      if(nSignalJets >=2 && nSignalJets <=3){
			cutnumber = 34.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			if(el->Pt() > 30. && mu->Pt() > 30.){
			  cutnumber = 35.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			  cutnumber = 36.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM); //ZVeto
			  if(DeltaEtall_EM < 1.5){
			    cutnumber = 37.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
			    if(mTmax_EM > 110){
			      cutnumber = 38.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);				
			      
			      if(Mljj_EM < 120.){
				cutnumber = 39.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
				if(HT_EM > 200.){
				  cutnumber = 41.; fillHistos_EM_SRSS1(cutnumber, weight_ALL_EM);
				}
			      }
			    }
			  }
			}
		      }//end >=2 jets
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

bool TSelector_SusyNtuple_Truth::CheckRealLeptons(const ElectronVector& signal_electrons, MuonVector& signal_muons){

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
bool TSelector_SusyNtuple_Truth::CheckChargeFlipElectrons(const ElectronVector& signal_electrons){
  
  for(uint i=0; i<signal_electrons.size(); i++){
Electron* signal_electron = signal_electrons.at(i);
if(signal_electron->isChargeFlip) return false;
// check if signal electron has no charge flip
  }
  return true;
  
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::getBTagWeight(const Event* evt, BTagSys SysSettingBTag)
{

//   JetVector tempJets = getBTagSFJets2Lep(m_baseJets);
//   return bTagSF(evt, tempJets, nt.evt()->mcChannel, SysSettingBTag);
return 0.;

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
bool TSelector_SusyNtuple_Truth::checkLeptonPt(const LeptonVector& leptons)
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
float TSelector_SusyNtuple_Truth::mTWW(TLorentzVector _ll, TLorentzVector _nu, bool MvvTrue) // Anyes: https://svnweb.cern.ch/trac/atlasinst/browser/Institutes/UCIrvine/ataffard/SusyWeakProdAna/trunk/Root/PhysicsTools.cxx#L197
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
float TSelector_SusyNtuple_Truth::calcHT(TLorentzVector l1, TLorentzVector l2, TLorentzVector met, TruthJetVector &signalJets){
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
float TSelector_SusyNtuple_Truth::calcMeff(TLorentzVector met, const JetVector &signalJets){
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

float TSelector_SusyNtuple_Truth::calcMt(TLorentzVector _l, TLorentzVector _nu)
{
  float dphi = acos(cos(_l.Phi()-_nu.Phi()));
  return sqrt(2*_l.Pt()*_nu.Pt() * (1- cos(dphi)) );
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::recalcMetRel(TLorentzVector metLV, TLorentzVector l1, TLorentzVector l2, const TruthJetVector jets, bool useForward)
{
  //copied from SusyNtTools.cxx and modified to work with TLorenzVector
  float dPhi = TMath::Pi()/2.;
  
  if( fabs(metLV.DeltaPhi(l1)) < dPhi ) dPhi = fabs(metLV.DeltaPhi(l1));
  if( fabs(metLV.DeltaPhi(l2)) < dPhi ) dPhi = fabs(metLV.DeltaPhi(l2));
  
  for(uint ij=0; ij<jets.size(); ++ij){
    const TruthJet* jet = jets.at(ij);
//     if( !useForward && SusyNtAna::isForwardJet(jet) ) continue; // Use only central jets
    if( fabs(metLV.DeltaPhi( *jet )) < dPhi ) dPhi = fabs(metLV.DeltaPhi( *jet ));
  }// end loop over jets
  
  return metLV.Et() * sin(dPhi);
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::calcMT2(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1)
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
float TSelector_SusyNtuple_Truth::calcMT2J(TLorentzVector metlv, TLorentzVector l0, TLorentzVector l1, TLorentzVector j0, TLorentzVector j1)
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
float TSelector_SusyNtuple_Truth::calcMZTauTau_coll(const TLorentzVector &signal_lep_0, const TLorentzVector &signal_lep_1, const TLorentzVector &met)
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
float TSelector_SusyNtuple_Truth::calcMZTauTau_mmc(TLorentzVector lep1, TLorentzVector lep2, int tau0_decay_type, int tau1_decay_type){
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
void TSelector_SusyNtuple_Truth::fillHistos_EE(int cutnumber, float weight){
  cutflow_EE->Fill(cutnumber,1.0);
  cutflow_EE_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::fillHistos_MM(int cutnumber, float weight){
  cutflow_MM->Fill(cutnumber,1.0);
  cutflow_MM_ALL->Fill(cutnumber, weight);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::fillHistos_EM(int cutnumber, float weight){
  cutflow_EM->Fill(cutnumber,1.0);
  cutflow_EM_ALL->Fill(cutnumber, weight);
}

/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::calcSumMv1(const JetVector &signalJets){
  
  //with or without leptons?
  
  float sumMv1 = 0.;
  for(uint j=0; j<signalJets.size(); ++j){
Jet* jet = signalJets.at(j);
sumMv1 += jet->mv1;
  }
  return sumMv1;
}
/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::getFakeWeight(const LeptonVector &baseLeps, susy::fake::Region region, float metRel, SusyMatrixMethod::SYSTEMATIC sys)
{

//   if(baseLeps.size() != 2) return 0.0;
// 
//   uint nVtx = nt.evt()->nVtx;
//   bool isMC = nt.evt()->isMC;
//   
//   float weight = m_matrix->getTotalFake( isSignalLepton(baseLeps[0],m_baseElectrons, m_baseMuons,nVtx,isMC),
//                                          baseLeps[0]->isEle(),
//                                          baseLeps[0]->Pt() * 1000.,
//                                          baseLeps[0]->Eta(),
//                                          isSignalLepton(baseLeps[1],m_baseElectrons, m_baseMuons,nVtx,isMC),
//                                          baseLeps[1]->isEle(),
//                                          baseLeps[1]->Pt() * 1000.,
//                                          baseLeps[1]->Eta(),
//                                          region,
//                                          metRel * 1000.,
//                                          sys);
// 
//   return weight;
return 0.;

}


/*--------------------------------------------------------------------------------*/
float TSelector_SusyNtuple_Truth::calc_D0(bool unbiased, const Lepton* lep)
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
bool TSelector_SusyNtuple_Truth::compareElecMomentum (Electron* e0, Electron* e1){ return (e0->Pt() > e1->Pt()); }

// /*--------------------------------------------------------------------------------*/
// ElectronVector TSelector_SusyNtuple_Truth::getSoftElectrons(SusyNtObject* susyNt, SusyNtSys sys)
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
// ElectronVector TSelector_SusyNtuple_Truth::getOverlapElectrons(SusyNtObject* susyNt, SusyNtSys sys)
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
bool TSelector_SusyNtuple_Truth::compareMuonMomentum (Muon* mu0, Muon* mu1){ return (mu0->Pt() > mu1->Pt()); }
/*--------------------------------------------------------------------------------*/
// MuonVector TSelector_SusyNtuple_Truth::getSoftMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
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
// MuonVector TSelector_SusyNtuple_Truth::getOverlapMuons(SusyNtObject* susyNt, SusyNtSys SysSetting)
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
bool TSelector_SusyNtuple_Truth::isCMSJet(const Susy::Jet* jet)
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
int TSelector_SusyNtuple_Truth::numberOfCMSJets(const JetVector& jets)
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
vector<TLorentzVector> TSelector_SusyNtuple_Truth::overlapRemoval(vector<TLorentzVector> objects_type1, vector<TLorentzVector> objects_type2, double dr, bool sameType, bool removeSoft) 
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

bool TSelector_SusyNtuple_Truth::doEventCleaning_andFillHistos(TruthJetVector baseJets, const TruthMet* met, TruthParticleVector baseMuons, TruthParticleVector baseElectrons, int flag, float weight_ALL_EE, float weight_ALL_MM, float weight_ALL_EM, SusyNtSys SysSetting, bool n0150BugFix)
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
//   if(SusyNtAna::hasBadJet(baseJets))return kFALSE;
  cutnumber = 6.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadJets
    
  //on top of smart veto, veto event with >=1 jets before electron-jet overlap removal with pT>40 GeV, BCH_CORR_JET > 0.05, DeltaPhi(met,jet)<0.3 (Anyes)
//   TruthJetVector prejets = getPreTruthJets(&nt);
//   if(!passDeadRegions(prejets, met, nt.evt()->run, nt.evt()->isMC)/* || !(flag & ECut_SmartVeto)*/) return false; // SusyNtTools: passDeadRegions(...)
  cutnumber = 7.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM); //CaloJets

//   if( !(flag & ECut_GoodVtx)) return false;
  cutnumber = 8.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//PrimaryVertex

//   MuonVector preMuons = SusyNtAna::getPreMuons(&nt, SysSetting, n0150BugFix);
//   if( SusyNtAna::hasBadMuon(preMuons)) return false;
  cutnumber = 9.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//BadMuons
    
//   if(hasCosmicMuon(baseMuons)) return false; // !(flag & ECut_Cosmic) - no longer guarantee the event flags that are stored :-(
//   preMuons.clear();
  cutnumber = 10.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Cosmic Muons


  // Sherpa WW fix, remove radiative b-quark processes that overlap with single top: already done upstream in SusyCommon SusyNtMaker

  if(nt.evt()->hfor == 4) return false; //remove events where same heavy flavor final states arise in multiple samples when combining ALPGEN samples
  cutnumber = 11.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//hfor veto

  if(!(baseMuons.size() >= 2 || baseElectrons.size() >= 2 || (baseElectrons.size()+baseMuons.size()) >= 2)) return false;
  cutnumber = 12.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//at least 2 base leptons

  if(!(baseMuons.size() == 2 || baseElectrons.size() == 2 || (baseElectrons.size()+baseMuons.size()) == 2)) return false;
  cutnumber = 13.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//exactly 2 base leptons


// if(!(m_baseElectrons.size()==2 || baseMuons.size()==2 || (m_baseElectrons.size()+baseMuons.size())==2)) return false; //only count leptons where no Mll < 20 GeV. Mll < 12 GeV veto ALREADY DONE FOR SELECTING BASELINE LEPTONS in performOverlapRemoval()


  // discard any SFOS baseline lepton pair with M_ll < 12 GeV unnecessary: already done when skimming/slimming ntuples
  // Any lepton pairs are required to have an invariant mass, m``, above 20 GeV such that to remove low-mass dilepton resonances
  if(baseMuons.size() == 2 && SusyNtAna::Mll(baseMuons[0], baseMuons[1]) < 20 )return false;
  if(baseElectrons.size() == 2 && SusyNtAna::Mll(baseElectrons[0], baseElectrons[1]) < 20 )return false;
  if((baseElectrons.size() ==1 && baseMuons.size() == 1) && SusyNtAna::Mll(baseElectrons[0], baseMuons[0]) < 20 )return false;
  cutnumber = 14.; fillHistos_EE(cutnumber, weight_ALL_EE); fillHistos_MM(cutnumber, weight_ALL_MM); fillHistos_EM(cutnumber, weight_ALL_EM);//Mll
  
  return true;
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_Truth::initTupleMaker(const std::string &outFilename, const std::string &treename)
{
    /*if(file_ && file_->IsOpen() && tree_) {
        cout<<"TupleMaker::init: already initialized"<<endl;
        return false;
    }
    else */return (initFile(outFilename) && initTree(treename));
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_Truth::initFile(const std::string &outFilename)
{
    file_ = TFile::Open(outFilename.c_str(), "recreate");
    if(!file_) cout<<"TupleMaker::initFile('"<<outFilename<<"') : failed to create file"<<endl;
    cout << "init " << outFilename << endl;
    return (file_ && file_->IsOpen());
}
//----------------------------------------------------------
bool TSelector_SusyNtuple_Truth::initTree(const std::string &treename)
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
bool TSelector_SusyNtuple_Truth::initTreeBranches()
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
bool TSelector_SusyNtuple_Truth::fillTupleMaker(const double weight, const unsigned int run, const unsigned int event, const bool isMc,
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
LeptonVector TSelector_SusyNtuple_Truth::getAnyElOrMu(SusyNtObject &susyNt, const Lepton *l0, const Lepton *l1)
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
bool TSelector_SusyNtuple_Truth::closeTupleMaker()
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


/*--------------------------------------------------------------------------------*/
char *TSelector_SusyNtuple_Truth::GetID(Int_t type)
{
   return Form ("%d", type);
}

/*--------------------------------------------------------------------------------*/
// Debug event
/*--------------------------------------------------------------------------------*/
bool TSelector_SusyNtuple_Truth::debugEvent()
{
  uint run = nt.evt()->run;
  uint evt = nt.evt()->event;
  //if(run==191139 && evt==140644832) return true;
  if(run==180164&&evt==24769) return true;

  return false;
}
/*--------------------------------------------------------------------------------*/


float TSelector_SusyNtuple_Truth::getLeptonSF(const LeptonVector& leptons, int SFUncertType)
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
void TSelector_SusyNtuple_Truth::overlapProcedure(TruthParticleVector& elecs, TruthParticleVector& muons, TruthParticleVector& taus, TruthJetVector& jets)
{
  // Remove electrons from electrons
  e_e_overlap(elecs, E_E_DR);
  // Remove jets from electrons
  e_j_overlap(elecs, jets, J_E_DR, true);
  // Remove taus from electrons
  t_e_overlap(taus, elecs, T_E_DR);
  // Remove taus from muons
  t_m_overlap(taus, muons, T_M_DR);
  // Remove electrons from jets
  e_j_overlap(elecs, jets, E_J_DR, false);
  // Remove muons from jets
  m_j_overlap(muons, jets, M_J_DR);
  // Remove electrons and muons that overlap
  e_m_overlap(elecs, muons, E_M_DR);
  // Remove muons from muons
  m_m_overlap(muons, M_M_DR);
  // Remove jets from taus
  t_j_overlap(taus, jets, J_T_DR, true);
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::e_e_overlap(TruthParticleVector& elecs, float minDr)
{
  uint nEl = elecs.size();
  if(nEl < 2) return;

  // Find all possible pairings
  static std::set<const TruthParticle*> removeElecs;
  removeElecs.clear();
  for(uint iEl=0; iEl<nEl; iEl++){
    const TruthParticle* e1 = elecs[iEl];
    for(uint jEl=iEl+1; jEl<nEl; jEl++){
      const TruthParticle* e2 = elecs[jEl];
      if(e1->DeltaR(*e2) < minDr){
        if(e1->Pt() < e2->Pt()){
          removeElecs.insert(e1);
          break;
        }
        else{
          removeElecs.insert(e2);
        }
      } // dR
    } // e2 loop
  } // e1 loop

  // Remove electrons that overlap
  for(int iEl=nEl-1; iEl>=0; iEl--){
    if(removeElecs.find(elecs[iEl]) != removeElecs.end()){
      elecs.erase( elecs.begin() + iEl );
    }
  }
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::e_j_overlap(TruthParticleVector& elecs, TruthJetVector& jets, float minDr, bool removeJets)
{
//   cout << nt.evt()->event << "  removeJets= " << removeJets << " minDr= " << minDr << endl;
  if(elecs.size()==0 || jets.size()==0) return;

  for(int ie=elecs.size()-1; ie>=0; ie--){
    const TruthParticle* e = elecs.at(ie);
    for(int ij=jets.size()-1; ij>=0; ij--){
      const TruthJet* j = jets.at(ij);
//       cout << "e->DeltaR(*j)= " << e->DeltaR(*j) << " e->Pt()= " << e->Pt() << " j->Pt()= " << j->Pt() << endl;
      if(e->DeltaR(*j) > minDr) continue;
      
      if(removeJets){
	jets.erase( jets.begin() + ij );
      }
      else{
	elecs.erase( elecs.begin() + ie );
	break;
      }
    }// end loop over jets
  }// end loop over electrons	  
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::m_j_overlap(TruthParticleVector& muons, TruthJetVector jets, float minDr)
{
  if(muons.size()==0 || jets.size()==0) return;

  for(int im=muons.size()-1; im>=0; im--){
    const TruthParticle* mu = muons.at(im);
    for(int ij=jets.size()-1; ij>=0; ij--){
      const TruthJet* j = jets.at(ij);
      if(mu->DeltaR(*j) > minDr) continue;

      muons.erase( muons.begin() + im );
      break;

    }// end loop over jets
  }// end loop over muons
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::e_m_overlap(TruthParticleVector& elecs, TruthParticleVector& muons, float minDr)
{
  uint nEl = elecs.size();
  uint nMu = muons.size();
  if(nEl==0 || nMu==0) return;

  // Electron muon overlap should be pretty rare,
  // so we can take advantage of that and optimize
  static std::set<const TruthParticle*> removeElecs;
  static std::set<const TruthParticle*> removeMuons;
  removeElecs.clear();
  removeMuons.clear();

  // In this case we will want to remove both the electron and the muon
  for(uint iEl=0; iEl<nEl; iEl++){
    const TruthParticle* e = elecs[iEl];
    for(uint iMu=0; iMu<nMu; iMu++){
      const TruthParticle* mu = muons[iMu];
      if(e->DeltaR(*mu) < minDr){
        removeElecs.insert(e);
        removeMuons.insert(mu);
      }
    }
  }

  // Remove those electrons flagged for removal
  if(removeElecs.size()){
    for(int iEl=nEl-1; iEl>=0; iEl--){
      if(removeElecs.find(elecs[iEl])!=removeElecs.end()){
        elecs.erase( elecs.begin() + iEl );
      }
    }
  }
  // Remove those muons flagged for removal
  if(removeMuons.size()){
    for(int iMu=nMu-1; iMu>=0; iMu--){
      if(removeMuons.find(muons[iMu])!=removeMuons.end()){
        muons.erase( muons.begin() + iMu );
      }
    }
  }
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::m_m_overlap(TruthParticleVector& muons, float minDr)
{
  uint nMu = muons.size();
  if(nMu < 2) return;

  // If 2 muons overlap, toss them both!
  static std::set<const TruthParticle*> removeMuons;
  removeMuons.clear();
  for(uint iMu=0; iMu<nMu; iMu++){
    const TruthParticle* mu1 = muons[iMu];
    for(uint jMu=iMu+1; jMu<nMu; jMu++){
      const TruthParticle* mu2 = muons[jMu];
      if(mu1->DeltaR(*mu2) < minDr){
        removeMuons.insert(mu1);
        removeMuons.insert(mu2);
      }
    }
  }
  for(int iMu=nMu-1; iMu>=0; iMu--){
    const TruthParticle* mu = muons[iMu];
    if(removeMuons.find(mu) != removeMuons.end()){
      muons.erase( muons.begin() + iMu );
    }
  }
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::t_e_overlap(TruthParticleVector& taus, TruthParticleVector& elecs, float minDr)
{
  uint nTau = taus.size();
  uint nEle = elecs.size();
  if(nTau==0 || nEle==0) return;

  for(int iTau=nTau-1; iTau>=0; iTau--){
    const TruthParticle* tau = taus[iTau];
    for(int iEl=nEle-1; iEl>=0; iEl--){
      const TruthParticle* e = elecs[iEl];

      if(tau->DeltaR(*e) < minDr){
        taus.erase( taus.begin() + iTau );
        break;
      }

    }
  }
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::t_m_overlap(TruthParticleVector& taus, TruthParticleVector& muons, float minDr)
{
  uint nTau = taus.size();
  uint nMuo = muons.size();
  if(nTau==0 || nMuo==0) return;

  for(int iTau=nTau-1; iTau>=0; iTau--){
    const TruthParticle* tau = taus[iTau];
    for(int iMu=nMuo-1; iMu>=0; iMu--){
      const TruthParticle* mu = muons[iMu];

      if(tau->DeltaR(*mu) < minDr){
        taus.erase( taus.begin() + iTau );
        break;
      }

    }
  }
}
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::t_j_overlap(TruthParticleVector& taus, TruthJetVector& jets, float minDr, bool removeJets)
{
  uint nTau = taus.size();
  uint nJet = jets.size();
  if(nTau==0 || nJet==0) return;

  for(int iTau=nTau-1; iTau>=0; iTau--){
    const TruthParticle* tau = taus.at(iTau);
    for(int iJet=jets.size()-1; iJet>=0; iJet--){
      const TruthJet* jet = jets.at(iJet);

      if(tau->DeltaR(*jet) < minDr){
        if(removeJets)
	  jets.erase( jets.begin() + iJet );
        else{
	  taus.erase( taus.begin() + iTau );
	  break;
        }
      }

    } // end loop over jets
  } // end loop over electrons	  
}
/*--------------------------------------------------------------------------------*/
TruthJetVector TSelector_SusyNtuple_Truth::getTruthJetsL20   (TruthJetVector& truthBaseJets)
{

  TruthJetVector truthSignalJets;
  for(uint index=0; index<truthBaseJets.size(); ++index){
    TruthJet* jet = truthBaseJets.at(index);
    bool bmatch = false;
    TruthJet* truthjet = truthBaseJets.at(index);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* recoj = & nt.jet()->at(ij);
      if(recoj->truthLabel==5){
	if(recoj->DeltaR(*truthjet) < 0.4) bmatch = true;
      }
    }
    if(!bmatch &&  jet->Pt() >= 20. && fabs(jet->Eta()) <= 2.4 ) truthSignalJets.push_back(jet);
  }

  return truthSignalJets;
}

/*--------------------------------------------------------------------------------*/
TruthJetVector TSelector_SusyNtuple_Truth::getTruthJetsF30   (TruthJetVector& truthBaseJets)
{

  TruthJetVector truthSignalJets;
  for(uint index=0; index<truthBaseJets.size(); ++index){
    TruthJet* jet = truthBaseJets.at(index);

    if(jet->Pt() >= 30. && fabs(jet->Eta()) > 2.4 ) truthSignalJets.push_back(jet);
    
    
  }

  return truthSignalJets;
}

/*--------------------------------------------------------------------------------*/
TruthJetVector TSelector_SusyNtuple_Truth::getTruthJetsB20   (TruthJetVector& truthBaseJets)
{

  TruthJetVector truthSignalJets;
  for(uint index=0; index<truthBaseJets.size(); ++index){
    bool bmatch = false;
    TruthJet* truthjet = truthBaseJets.at(index);
    for(uint ij=0; ij<nt.jet()->size(); ++ij){
      Jet* recoj = & nt.jet()->at(ij);
      if(recoj->truthLabel==5){
// 	if(recoj->DeltaR(*truthjet) < 0.05) cout << "DeltaR truth, reco jet:  " << recoj->DeltaR(*truthjet) << " reco pt, eta, phi " << recoj->Pt()<< ", " << recoj->Eta() << ", " << recoj->Phi() << "; truthjet pt, eta, phi " << truthjet->Pt() << ", " << truthjet->Eta() << ", " << truthjet->Phi() << endl;
	
// 	h_diffptrecoTruthJets_DeltaR->Fill(fabs(recoj->Pt() - truthjet->Pt()), recoj->DeltaR(*truthjet), 1);
	if(recoj->DeltaR(*truthjet) < 0.4) bmatch = true;
      }
    }
    if( bmatch && truthjet->Pt() >= 20. && fabs(truthjet->Eta()) <= 2.4 ) truthSignalJets.push_back(truthjet);
  }

  return truthSignalJets;
}
/*--------------------------------------------------------------------------------*/
TruthJetVector TSelector_SusyNtuple_Truth::getTruthJetsSignal   (TruthJetVector& truthBaseJets)
{

  TruthJetVector truthSignalJets;
  for(uint index=0; index<truthBaseJets.size(); ++index){
    TruthJet* jet = truthBaseJets.at(index);
    
//     bool bmatch = false;
//     TruthJet* truthjet = truthBaseJets.at(index);
//     for(uint ij=0; ij<nt.jet()->size(); ++ij){
//       Jet* recoj = & nt.jet()->at(ij);
//       if(recoj->truthLabel==5){
// 	if(recoj->DeltaR(*truthjet) < 0.2) bmatch = true;
//       }
//     }
    if(jet->Pt() >= 20. && fabs(jet->Eta()) <= 2.4 ) truthSignalJets.push_back(jet);
    if(jet->Pt() >= 30. && fabs(jet->Eta()) > 2.4 ) truthSignalJets.push_back(jet);
//     if(truthjet->Pt() >= 20. && fabs(truthjet->Eta()) <= 2.4 ) truthSignalJets.push_back(truthjet)
//     truthSignalJets.push_back(jet);
  }

  return truthSignalJets;
}

/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::SlaveTerminate()
{
  
  // SusyNtAna::Terminate();
  if(makeNTuple) closeTupleMaker();
  if(m_dbg) cout << "TSelector_SusyNtuple_Truth::Terminate" << endl;
  cout << "sample_identifier= " << sample_identifier << endl;

  if(m_writeOut) {
    out.close();
  }
    

 
  
    TString outputfile;

    if(sample_identifier == 169471)outputfile="histos_ZN_WW_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 126988)outputfile="histos_ZN_WWPlusJets_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 129477)outputfile="histos_ZN_ZV_n0150_Truth_BJetDR04_02_06_14";
    
    if(sample_identifier == 116600)outputfile="histos_ZN_ZZ_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 108346)outputfile="histos_ZN_ttbarWtop_n0150_Truth_BJetDR04_02_06_14";
    
//     if(sample_identifier == 110805) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split1_Truth_BJetDR04_02_06_14";
//     if(sample_identifier == 117671) outputfile="histos_ZN_ZPlusJetsOLD_n0150_split2_Truth_BJetDR04_02_06_14";    
//     if(sample_identifier == 173041)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split3_Truth_BJetDR04_02_06_14";           
//     if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsOLD_n0150_split4_Truth_BJetDR04_02_06_14"; 
    
    if(sample_identifier == 147105)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split1_Truth_BJetDR04_02_06_14";    
    if(sample_identifier == 147123)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split2_Truth_BJetDR04_02_06_14";    
    if(sample_identifier == 147771)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split3_Truth_BJetDR04_02_06_14";    
    if(sample_identifier == 173045)outputfile="histos_ZN_ZPlusJetsNEW_n0150_split4_Truth_BJetDR04_02_06_14";    
    
    
    
    if(sample_identifier == 160155)outputfile="histos_ZN_Higgs_n0150_Truth_BJetDR04_02_06_14";
    
    if(sample_identifier == 157816)outputfile="histos_ZN_VVtotautauqq_n0150_Truth_BJetDR04_02_06_14";
    
    if(sample_identifier == 126893)outputfile="histos_cutflow_126893_TSelector_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 176576)outputfile="histos_cutflow_176576_TSelector_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177501)outputfile="histos_ZN_177501_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177502)outputfile="histos_ZN_177502_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177503)outputfile="histos_ZN_177503_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177504)outputfile="histos_ZN_177504_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177505)outputfile="histos_ZN_177505_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177506)outputfile="histos_ZN_177506_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177507)outputfile="histos_ZN_177507_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177508)outputfile="histos_ZN_177508_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177509)outputfile="histos_ZN_177509_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177510)outputfile="histos_ZN_177510_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177511)outputfile="histos_ZN_177511_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177512)outputfile="histos_ZN_177512_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177513)outputfile="histos_ZN_177513_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177514)outputfile="histos_ZN_177514_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177515)outputfile="histos_ZN_177515_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177516)outputfile="histos_ZN_177516_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177517)outputfile="histos_ZN_177517_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177518)outputfile="histos_ZN_177518_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177519)outputfile="histos_ZN_177519_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177520)outputfile="histos_ZN_177520_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177521)outputfile="histos_ZN_177521_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177522)outputfile="histos_ZN_177522_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177523)outputfile="histos_ZN_177523_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177524)outputfile="histos_ZN_177524_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177525)outputfile="histos_ZN_177525_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177526)outputfile="histos_ZN_177526_n0150_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 177527)outputfile="histos_ZN_177527_n0150_Truth_BJetDR04_02_06_14";
    
    if(sample_identifier == 10001) outputfile="histos_fake_Egamma_n0150_1_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 10002) outputfile="histos_fake_Egamma_n0150_2_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 10003) outputfile="histos_fake_Egamma_n0150_3_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 10004) outputfile="histos_fake_Egamma_n0150_4_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 10005) outputfile="histos_fake_Egamma_n0150_5_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 10006) outputfile="histos_fake_Egamma_n0150_6_Truth_BJetDR04_02_06_14";
    
    if(sample_identifier == 20001) outputfile="histos_fake_Muons_n0150_1_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 20002) outputfile="histos_fake_Muons_n0150_2_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 20003) outputfile="histos_fake_Muons_n0150_3_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 20004) outputfile="histos_fake_Muons_n0150_4_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 20005) outputfile="histos_fake_Muons_n0150_5_Truth_BJetDR04_02_06_14";
    if(sample_identifier == 20006) outputfile="histos_fake_Muons_n0150_6_Truth_BJetDR04_02_06_14";
//     outputfile="histos_cutflow_fake_Egamma_periodA_Truth_BJetDR04_02_06_14";
    
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
    
// }
}
/*--------------------------------------------------------------------------------*/
// The Terminate() function is the last function to be called
/*--------------------------------------------------------------------------------*/
void TSelector_SusyNtuple_Truth::Terminate()
{
//   closeTupleMaker();
 
}