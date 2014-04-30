bool SusySel::defineHistos(){

  
  cutflow_EE = new TH1F("cutflow_EE", "cutflow_EE" ,130, 0, 129); cutflow_EE->Sumw2();
  cutflow_EE_ALL = new TH1F("cutflow_EE_ALL", "cutflow_EE_ALL" ,130, 0, 129); cutflow_EE_ALL->Sumw2();

  cutflow_MM = new TH1F("cutflow_MM", "cutflow_MM" ,130, 0, 129); cutflow_EE_ALL->Sumw2();
  cutflow_MM_ALL = new TH1F("cutflow_MM_ALL", "cutflow_MM_ALL" ,130, 0, 129); cutflow_MM_ALL->Sumw2();

  cutflow_EM = new TH1F("cutflow_EM", "cutflow_EM" ,130, 0, 129); cutflow_EM->Sumw2();
  cutflow_EM_ALL = new TH1F("cutflow_EM_ALL", "cutflow_EM_ALL" ,130, 0, 129);  ; cutflow_EM_ALL->Sumw2();
//============================================================================================================
//============================================================================================================
    h_pTl0_1j_EE = new TH2F("h_pTl0_1j_EE", "h_pTl0_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTl0_1j_EE->Sumw2();
  h_pTl0_2j_EE = new TH2F("h_pTl0_2j_EE", "h_pTl0_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTl0_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTl1_1j_EE = new TH2F("h_pTl1_1j_EE", "h_pTl1_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTl1_1j_EE->Sumw2();
  h_pTl1_2j_EE = new TH2F("h_pTl1_2j_EE", "h_pTl1_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTl1_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaRLeptons_1j_EE = new TH2F("h_DeltaRLeptons_1j_EE", "h_DeltaRLeptons_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_1j_EE->Sumw2();
  h_DeltaRLeptons_2j_EE = new TH2F("h_DeltaRLeptons_2j_EE", "h_DeltaRLeptons_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTj0_1j_EE = new TH2F("h_pTj0_1j_EE", "h_pTj0_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTj0_1j_EE->Sumw2();
  h_pTj0_2j_EE = new TH2F("h_pTj0_2j_EE", "h_pTj0_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTj0_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTj1_1j_EE = new TH2F("h_pTj1_1j_EE", "h_pTj1_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTj1_1j_EE->Sumw2();
  h_pTj1_2j_EE = new TH2F("h_pTj1_2j_EE", "h_pTj1_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTj1_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mll_1j_EE = new TH2F("h_mll_1j_EE", "h_mll_1j_EE", 100, 0, 500 ,130, 0, 129); h_mll_1j_EE->Sumw2();
  h_mll_2j_EE = new TH2F("h_mll_2j_EE", "h_mll_2j_EE", 100, 0, 500 ,130, 0, 129); h_mll_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_METrel_1j_EE = new TH2F("h_METrel_1j_EE", "h_METrel_1j_EE", 100, 0, 500 ,130, 0, 129);  h_METrel_1j_EE->Sumw2();
  h_METrel_2j_EE = new TH2F("h_METrel_2j_EE", "h_METrel_2j_EE", 100, 0, 500 ,130, 0, 129);  h_METrel_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_MET_1j_EE = new TH2F("h_MET_1j_EE", "h_MET_1j_EE", 100, 0, 500 ,130, 0, 129);  h_MET_1j_EE->Sumw2();
  h_MET_2j_EE = new TH2F("h_MET_2j_EE", "h_MET_2j_EE", 100, 0, 500 ,130, 0, 129);  h_MET_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_HT_1j_EE = new TH2F("h_HT_1j_EE", "h_HT_1j_EE", 100, 0, 500 ,130, 0, 129);  h_HT_1j_EE->Sumw2();
  h_HT_2j_EE = new TH2F("h_HT_2j_EE", "h_HT_2j_EE", 100, 0, 500 ,130, 0, 129);  h_HT_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mWWt_1j_EE = new TH2F("h_mWWt_1j_EE", "h_mWWt_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mWWt_1j_EE->Sumw2();
  h_mWWt_2j_EE = new TH2F("h_mWWt_2j_EE", "h_mWWt_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mWWt_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mTlmin_1j_EE = new TH2F("h_mTlmin_1j_EE", "h_mTlmin_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mTlmin_1j_EE->Sumw2();
  h_mTlmin_2j_EE = new TH2F("h_mTlmin_2j_EE", "h_mTlmin_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mTlmin_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTlmax_1j_EE = new TH2F("h_mTlmax_1j_EE", "h_mTlmax_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mTlmax_1j_EE->Sumw2();
  h_mTlmax_2j_EE = new TH2F("h_mTlmax_2j_EE", "h_mTlmax_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mTlmax_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_meff_1j_EE = new TH2F("h_meff_1j_EE", "h_meff_1j_EE", 100, 0, 500 ,130, 0, 129);  h_meff_1j_EE->Sumw2();
  h_meff_2j_EE = new TH2F("h_meff_2j_EE", "h_meff_2j_EE", 100, 0, 500 ,130, 0, 129);  h_meff_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mT2_1j_EE = new TH2F("h_mT2_1j_EE", "h_mT2_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mT2_1j_EE->Sumw2();
  h_mT2_2j_EE = new TH2F("h_mT2_2j_EE", "h_mT2_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mT2_2j_EE->Sumw2();
/*--------------------------------------------------------------------------------*/ 
  h_mT2J_1j_EE = new TH2F("h_mT2J_1j_EE", "h_mT2J_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mT2J_1j_EE->Sumw2();
  h_mT2J_2j_EE = new TH2F("h_mT2J_2j_EE", "h_mT2J_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mT2J_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mjj_1j_EE = new TH2F("h_mjj_1j_EE", "h_mjj_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mjj_1j_EE->Sumw2();
  h_mjj_2j_EE = new TH2F("h_mjj_2j_EE", "h_mjj_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mjj_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETll_1j_EE = new TH2F("h_DeltaPhiMETll_1j_EE", "h_DeltaPhiMETll_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_1j_EE->Sumw2();
  h_DeltaPhiMETll_2j_EE = new TH2F("h_DeltaPhiMETll_2j_EE", "h_DeltaPhiMETll_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhill_1j_EE = new TH2F("h_DeltaPhill_1j_EE", "h_DeltaPhill_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_1j_EE->Sumw2();
  h_DeltaPhill_2j_EE = new TH2F("h_DeltaPhill_2j_EE", "h_DeltaPhill_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NBJets_1j_EE = new TH2F("h_NBJets_1j_EE", "h_NBJets_1j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_1j_EE->Sumw2();
  h_NBJets_2j_EE = new TH2F("h_NBJets_2j_EE", "h_NBJets_2j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NCJets_1j_EE = new TH2F("h_NCJets_1j_EE", "h_NCJets_1j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_1j_EE->Sumw2();
  h_NCJets_2j_EE = new TH2F("h_NCJets_2j_EE", "h_NCJets_2j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NFJets_1j_EE = new TH2F("h_NFJets_1j_EE", "h_NFJets_1j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_1j_EE->Sumw2();
  h_NFJets_2j_EE = new TH2F("h_NFJets_2j_EE", "h_NFJets_2j_EE", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhijj_1j_EE = new TH2F("h_DeltaPhijj_1j_EE", "h_DeltaPhijj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_1j_EE->Sumw2();
  h_DeltaPhijj_2j_EE = new TH2F("h_DeltaPhijj_2j_EE", "h_DeltaPhijj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTjj_1j_EE = new TH2F("h_pTjj_1j_EE", "h_pTjj_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTjj_1j_EE->Sumw2();
  h_pTjj_2j_EE = new TH2F("h_pTjj_2j_EE", "h_pTjj_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTjj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTll_1j_EE = new TH2F("h_pTll_1j_EE", "h_pTll_1j_EE", 100, 0, 500 ,130, 0, 129);  h_pTll_1j_EE->Sumw2();
  h_pTll_2j_EE = new TH2F("h_pTll_2j_EE", "h_pTll_2j_EE", 100, 0, 500 ,130, 0, 129);  h_pTll_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl0_1j_EE = new TH2F("h_DeltaPhiMETl0_1j_EE", "h_DeltaPhiMETl0_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_1j_EE->Sumw2();
  h_DeltaPhiMETl0_2j_EE = new TH2F("h_DeltaPhiMETl0_2j_EE", "h_DeltaPhiMETl0_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl1_1j_EE = new TH2F("h_DeltaPhiMETl1_1j_EE", "h_DeltaPhiMETl1_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_1j_EE->Sumw2();
  h_DeltaPhiMETl1_2j_EE = new TH2F("h_DeltaPhiMETl1_2j_EE", "h_DeltaPhiMETl1_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj0_1j_EE = new TH2F("h_DeltaPhiMETj0_1j_EE", "h_DeltaPhiMETj0_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_1j_EE->Sumw2();
  h_DeltaPhiMETj0_2j_EE = new TH2F("h_DeltaPhiMETj0_2j_EE", "h_DeltaPhiMETj0_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj1_1j_EE = new TH2F("h_DeltaPhiMETj1_1j_EE", "h_DeltaPhiMETj1_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_1j_EE->Sumw2();
  h_DeltaPhiMETj1_2j_EE = new TH2F("h_DeltaPhiMETj1_2j_EE", "h_DeltaPhiMETj1_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETjj_1j_EE = new TH2F("h_DeltaPhiMETjj_1j_EE", "h_DeltaPhiMETjj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_1j_EE->Sumw2();
  h_DeltaPhiMETjj_2j_EE = new TH2F("h_DeltaPhiMETjj_2j_EE", "h_DeltaPhiMETjj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaRjj_1j_EE = new TH2F("h_DeltaRjj_1j_EE", "h_DeltaRjj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_1j_EE->Sumw2();
  h_DeltaRjj_2j_EE = new TH2F("h_DeltaRjj_2j_EE", "h_DeltaRjj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etal0_1j_EE = new TH2F("h_etal0_1j_EE", "h_etal0_1j_EE", 70, 0, 7 ,130, 0, 129);  h_etal0_1j_EE->Sumw2();
  h_etal0_2j_EE = new TH2F("h_etal0_2j_EE", "h_etal0_2j_EE", 70, 0, 7 ,130, 0, 129);  h_etal0_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etal1_1j_EE = new TH2F("h_etal1_1j_EE", "h_etal1_1j_EE", 70, 0, 7 ,130, 0, 129);  h_etal1_1j_EE->Sumw2();
  h_etal1_2j_EE = new TH2F("h_etal1_2j_EE", "h_etal1_2j_EE", 70, 0, 7 ,130, 0, 129);  h_etal1_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj0_1j_EE = new TH2F("h_etaj0_1j_EE", "h_etaj0_1j_EE", 70, 0, 7 ,130, 0, 129);  h_etaj0_1j_EE->Sumw2();
  h_etaj0_2j_EE = new TH2F("h_etaj0_2j_EE", "h_etaj0_2j_EE", 70, 0, 7 ,130, 0, 129);  h_etaj0_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj1_1j_EE = new TH2F("h_etaj1_1j_EE", "h_etaj1_1j_EE", 70, 0, 7 ,130, 0, 129);  h_etaj1_1j_EE->Sumw2();
  h_etaj1_2j_EE = new TH2F("h_etaj1_2j_EE", "h_etaj1_2j_EE", 70, 0, 7 ,130, 0, 129);  h_etaj1_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl0MET_1j_EE = new TH2F("h_mTl0MET_1j_EE", "h_mTl0MET_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_1j_EE->Sumw2();
  h_mTl0MET_2j_EE = new TH2F("h_mTl0MET_2j_EE", "h_mTl0MET_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl1MET_1j_EE = new TH2F("h_mTl1MET_1j_EE", "h_mTl1MET_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_1j_EE->Sumw2();
  h_mTl1MET_2j_EE = new TH2F("h_mTl1MET_2j_EE", "h_mTl1MET_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_2j_EE->Sumw2();
        /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhilljj_1j_EE = new TH2F("h_DeltaPhilljj_1j_EE", "h_DeltaPhilljj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_1j_EE->Sumw2();
  h_DeltaPhilljj_2j_EE = new TH2F("h_DeltaPhilljj_2j_EE", "h_DeltaPhilljj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil0jj_1j_EE = new TH2F("h_DeltaPhil0jj_1j_EE", "h_DeltaPhil0jj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_1j_EE->Sumw2();
  h_DeltaPhil0jj_2j_EE = new TH2F("h_DeltaPhil0jj_2j_EE", "h_DeltaPhil0jj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil1jj_1j_EE = new TH2F("h_DeltaPhil1jj_1j_EE", "h_DeltaPhil1jj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_1j_EE->Sumw2();
  h_DeltaPhil1jj_2j_EE = new TH2F("h_DeltaPhil1jj_2j_EE", "h_DeltaPhil1jj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaRlljj_1j_EE = new TH2F("h_DeltaRlljj_1j_EE", "h_DeltaRlljj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_1j_EE->Sumw2();
  h_DeltaRlljj_2j_EE = new TH2F("h_DeltaRlljj_2j_EE", "h_DeltaRlljj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_2j_EE->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtajj_1j_EE = new TH2F("h_DeltaEtajj_1j_EE", "h_DeltaEtajj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_1j_EE->Sumw2();
  h_DeltaEtajj_2j_EE = new TH2F("h_DeltaEtajj_2j_EE", "h_DeltaEtajj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtall_1j_EE = new TH2F("h_DeltaEtall_1j_EE", "h_DeltaEtall_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_1j_EE->Sumw2();
  h_DeltaEtall_2j_EE = new TH2F("h_DeltaEtall_2j_EE", "h_DeltaEtall_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mMETll_1j_EE = new TH2F("h_mMETll_1j_EE", "h_mMETll_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mMETll_1j_EE->Sumw2();
  h_mMETll_2j_EE = new TH2F("h_mMETll_2j_EE", "h_mMETll_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mMETll_2j_EE->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaYjj_1j_EE = new TH2F("h_DeltaYjj_1j_EE", "h_DeltaYjj_1j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_1j_EE->Sumw2();
  h_DeltaYjj_2j_EE = new TH2F("h_DeltaYjj_2j_EE", "h_DeltaYjj_2j_EE", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mljj_1j_EE = new TH2F("h_mljj_1j_EE", "h_mljj_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mljj_1j_EE->Sumw2();
  h_mljj_2j_EE = new TH2F("h_mljj_2j_EE", "h_mljj_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mljj_2j_EE->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mlj_1j_EE = new TH2F("h_mlj_1j_EE", "h_mlj_1j_EE", 100, 0, 500 ,130, 0, 129);  h_mlj_1j_EE->Sumw2();
  h_mlj_2j_EE = new TH2F("h_mlj_2j_EE", "h_mlj_2j_EE", 100, 0, 500 ,130, 0, 129);  h_mlj_2j_EE->Sumw2();

//============================================================================================================
//============================================================================================================
  h_pTl0_1j_MM = new TH2F("h_pTl0_1j_MM", "h_pTl0_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTl0_1j_MM->Sumw2();
  h_pTl0_2j_MM = new TH2F("h_pTl0_2j_MM", "h_pTl0_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTl0_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTl1_1j_MM = new TH2F("h_pTl1_1j_MM", "h_pTl1_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTl1_1j_MM->Sumw2();
  h_pTl1_2j_MM = new TH2F("h_pTl1_2j_MM", "h_pTl1_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTl1_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaRLeptons_1j_MM = new TH2F("h_DeltaRLeptons_1j_MM", "h_DeltaRLeptons_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_1j_MM->Sumw2();
  h_DeltaRLeptons_2j_MM = new TH2F("h_DeltaRLeptons_2j_MM", "h_DeltaRLeptons_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTj0_1j_MM = new TH2F("h_pTj0_1j_MM", "h_pTj0_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTj0_1j_MM->Sumw2();
  h_pTj0_2j_MM = new TH2F("h_pTj0_2j_MM", "h_pTj0_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTj0_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTj1_1j_MM = new TH2F("h_pTj1_1j_MM", "h_pTj1_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTj1_1j_MM->Sumw2();
  h_pTj1_2j_MM = new TH2F("h_pTj1_2j_MM", "h_pTj1_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTj1_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mll_1j_MM = new TH2F("h_mll_1j_MM", "h_mll_1j_MM", 100, 0, 500 ,130, 0, 129); h_mll_1j_MM->Sumw2();
  h_mll_2j_MM = new TH2F("h_mll_2j_MM", "h_mll_2j_MM", 100, 0, 500 ,130, 0, 129); h_mll_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_METrel_1j_MM = new TH2F("h_METrel_1j_MM", "h_METrel_1j_MM", 100, 0, 500 ,130, 0, 129);  h_METrel_1j_MM->Sumw2();
  h_METrel_2j_MM = new TH2F("h_METrel_2j_MM", "h_METrel_2j_MM", 100, 0, 500 ,130, 0, 129);  h_METrel_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_MET_1j_MM = new TH2F("h_MET_1j_MM", "h_MET_1j_MM", 100, 0, 500 ,130, 0, 129);  h_MET_1j_MM->Sumw2();
  h_MET_2j_MM = new TH2F("h_MET_2j_MM", "h_MET_2j_MM", 100, 0, 500 ,130, 0, 129);  h_MET_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_HT_1j_MM = new TH2F("h_HT_1j_MM", "h_HT_1j_MM", 100, 0, 500 ,130, 0, 129);  h_HT_1j_MM->Sumw2();
  h_HT_2j_MM = new TH2F("h_HT_2j_MM", "h_HT_2j_MM", 100, 0, 500 ,130, 0, 129);  h_HT_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mWWt_1j_MM = new TH2F("h_mWWt_1j_MM", "h_mWWt_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mWWt_1j_MM->Sumw2();
  h_mWWt_2j_MM = new TH2F("h_mWWt_2j_MM", "h_mWWt_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mWWt_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mTlmin_1j_MM = new TH2F("h_mTlmin_1j_MM", "h_mTlmin_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mTlmin_1j_MM->Sumw2();
  h_mTlmin_2j_MM = new TH2F("h_mTlmin_2j_MM", "h_mTlmin_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mTlmin_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTlmax_1j_MM = new TH2F("h_mTlmax_1j_MM", "h_mTlmax_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mTlmax_1j_MM->Sumw2();
  h_mTlmax_2j_MM = new TH2F("h_mTlmax_2j_MM", "h_mTlmax_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mTlmax_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_meff_1j_MM = new TH2F("h_meff_1j_MM", "h_meff_1j_MM", 100, 0, 500 ,130, 0, 129);  h_meff_1j_MM->Sumw2();
  h_meff_2j_MM = new TH2F("h_meff_2j_MM", "h_meff_2j_MM", 100, 0, 500 ,130, 0, 129);  h_meff_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mT2_1j_MM = new TH2F("h_mT2_1j_MM", "h_mT2_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mT2_1j_MM->Sumw2();
  h_mT2_2j_MM = new TH2F("h_mT2_2j_MM", "h_mT2_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mT2_2j_MM->Sumw2();
/*--------------------------------------------------------------------------------*/ 
  h_mT2J_1j_MM = new TH2F("h_mT2J_1j_MM", "h_mT2J_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mT2J_1j_MM->Sumw2();
  h_mT2J_2j_MM = new TH2F("h_mT2J_2j_MM", "h_mT2J_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mT2J_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mjj_1j_MM = new TH2F("h_mjj_1j_MM", "h_mjj_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mjj_1j_MM->Sumw2();
  h_mjj_2j_MM = new TH2F("h_mjj_2j_MM", "h_mjj_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mjj_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETll_1j_MM = new TH2F("h_DeltaPhiMETll_1j_MM", "h_DeltaPhiMETll_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_1j_MM->Sumw2();
  h_DeltaPhiMETll_2j_MM = new TH2F("h_DeltaPhiMETll_2j_MM", "h_DeltaPhiMETll_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhill_1j_MM = new TH2F("h_DeltaPhill_1j_MM", "h_DeltaPhill_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_1j_MM->Sumw2();
  h_DeltaPhill_2j_MM = new TH2F("h_DeltaPhill_2j_MM", "h_DeltaPhill_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NBJets_1j_MM = new TH2F("h_NBJets_1j_MM", "h_NBJets_1j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_1j_MM->Sumw2();
  h_NBJets_2j_MM = new TH2F("h_NBJets_2j_MM", "h_NBJets_2j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NCJets_1j_MM = new TH2F("h_NCJets_1j_MM", "h_NCJets_1j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_1j_MM->Sumw2();
  h_NCJets_2j_MM = new TH2F("h_NCJets_2j_MM", "h_NCJets_2j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NFJets_1j_MM = new TH2F("h_NFJets_1j_MM", "h_NFJets_1j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_1j_MM->Sumw2();
  h_NFJets_2j_MM = new TH2F("h_NFJets_2j_MM", "h_NFJets_2j_MM", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhijj_1j_MM = new TH2F("h_DeltaPhijj_1j_MM", "h_DeltaPhijj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_1j_MM->Sumw2();
  h_DeltaPhijj_2j_MM = new TH2F("h_DeltaPhijj_2j_MM", "h_DeltaPhijj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTjj_1j_MM = new TH2F("h_pTjj_1j_MM", "h_pTjj_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTjj_1j_MM->Sumw2();
  h_pTjj_2j_MM = new TH2F("h_pTjj_2j_MM", "h_pTjj_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTjj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTll_1j_MM = new TH2F("h_pTll_1j_MM", "h_pTll_1j_MM", 100, 0, 500 ,130, 0, 129);  h_pTll_1j_MM->Sumw2();
  h_pTll_2j_MM = new TH2F("h_pTll_2j_MM", "h_pTll_2j_MM", 100, 0, 500 ,130, 0, 129);  h_pTll_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl0_1j_MM = new TH2F("h_DeltaPhiMETl0_1j_MM", "h_DeltaPhiMETl0_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_1j_MM->Sumw2();
  h_DeltaPhiMETl0_2j_MM = new TH2F("h_DeltaPhiMETl0_2j_MM", "h_DeltaPhiMETl0_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl1_1j_MM = new TH2F("h_DeltaPhiMETl1_1j_MM", "h_DeltaPhiMETl1_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_1j_MM->Sumw2();
  h_DeltaPhiMETl1_2j_MM = new TH2F("h_DeltaPhiMETl1_2j_MM", "h_DeltaPhiMETl1_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj0_1j_MM = new TH2F("h_DeltaPhiMETj0_1j_MM", "h_DeltaPhiMETj0_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_1j_MM->Sumw2();
  h_DeltaPhiMETj0_2j_MM = new TH2F("h_DeltaPhiMETj0_2j_MM", "h_DeltaPhiMETj0_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj1_1j_MM = new TH2F("h_DeltaPhiMETj1_1j_MM", "h_DeltaPhiMETj1_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_1j_MM->Sumw2();
  h_DeltaPhiMETj1_2j_MM = new TH2F("h_DeltaPhiMETj1_2j_MM", "h_DeltaPhiMETj1_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETjj_1j_MM = new TH2F("h_DeltaPhiMETjj_1j_MM", "h_DeltaPhiMETjj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_1j_MM->Sumw2();
  h_DeltaPhiMETjj_2j_MM = new TH2F("h_DeltaPhiMETjj_2j_MM", "h_DeltaPhiMETjj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaRjj_1j_MM = new TH2F("h_DeltaRjj_1j_MM", "h_DeltaRjj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_1j_MM->Sumw2();
  h_DeltaRjj_2j_MM = new TH2F("h_DeltaRjj_2j_MM", "h_DeltaRjj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etal0_1j_MM = new TH2F("h_etal0_1j_MM", "h_etal0_1j_MM", 70, 0, 7 ,130, 0, 129);  h_etal0_1j_MM->Sumw2();
  h_etal0_2j_MM = new TH2F("h_etal0_2j_MM", "h_etal0_2j_MM", 70, 0, 7 ,130, 0, 129);  h_etal0_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etal1_1j_MM = new TH2F("h_etal1_1j_MM", "h_etal1_1j_MM", 70, 0, 7 ,130, 0, 129);  h_etal1_1j_MM->Sumw2();
  h_etal1_2j_MM = new TH2F("h_etal1_2j_MM", "h_etal1_2j_MM", 70, 0, 7 ,130, 0, 129);  h_etal1_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj0_1j_MM = new TH2F("h_etaj0_1j_MM", "h_etaj0_1j_MM", 70, 0, 7 ,130, 0, 129);  h_etaj0_1j_MM->Sumw2();
  h_etaj0_2j_MM = new TH2F("h_etaj0_2j_MM", "h_etaj0_2j_MM", 70, 0, 7 ,130, 0, 129);  h_etaj0_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj1_1j_MM = new TH2F("h_etaj1_1j_MM", "h_etaj1_1j_MM", 70, 0, 7 ,130, 0, 129);  h_etaj1_1j_MM->Sumw2();
  h_etaj1_2j_MM = new TH2F("h_etaj1_2j_MM", "h_etaj1_2j_MM", 70, 0, 7 ,130, 0, 129);  h_etaj1_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl0MET_1j_MM = new TH2F("h_mTl0MET_1j_MM", "h_mTl0MET_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_1j_MM->Sumw2();
  h_mTl0MET_2j_MM = new TH2F("h_mTl0MET_2j_MM", "h_mTl0MET_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl1MET_1j_MM = new TH2F("h_mTl1MET_1j_MM", "h_mTl1MET_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_1j_MM->Sumw2();
  h_mTl1MET_2j_MM = new TH2F("h_mTl1MET_2j_MM", "h_mTl1MET_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_2j_MM->Sumw2();
        /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhilljj_1j_MM = new TH2F("h_DeltaPhilljj_1j_MM", "h_DeltaPhilljj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_1j_MM->Sumw2();
  h_DeltaPhilljj_2j_MM = new TH2F("h_DeltaPhilljj_2j_MM", "h_DeltaPhilljj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil0jj_1j_MM = new TH2F("h_DeltaPhil0jj_1j_MM", "h_DeltaPhil0jj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_1j_MM->Sumw2();
  h_DeltaPhil0jj_2j_MM = new TH2F("h_DeltaPhil0jj_2j_MM", "h_DeltaPhil0jj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil1jj_1j_MM = new TH2F("h_DeltaPhil1jj_1j_MM", "h_DeltaPhil1jj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_1j_MM->Sumw2();
  h_DeltaPhil1jj_2j_MM = new TH2F("h_DeltaPhil1jj_2j_MM", "h_DeltaPhil1jj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaRlljj_1j_MM = new TH2F("h_DeltaRlljj_1j_MM", "h_DeltaRlljj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_1j_MM->Sumw2();
  h_DeltaRlljj_2j_MM = new TH2F("h_DeltaRlljj_2j_MM", "h_DeltaRlljj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_2j_MM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtajj_1j_MM = new TH2F("h_DeltaEtajj_1j_MM", "h_DeltaEtajj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_1j_MM->Sumw2();
  h_DeltaEtajj_2j_MM = new TH2F("h_DeltaEtajj_2j_MM", "h_DeltaEtajj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtall_1j_MM = new TH2F("h_DeltaEtall_1j_MM", "h_DeltaEtall_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_1j_MM->Sumw2();
  h_DeltaEtall_2j_MM = new TH2F("h_DeltaEtall_2j_MM", "h_DeltaEtall_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mMETll_1j_MM = new TH2F("h_mMETll_1j_MM", "h_mMETll_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mMETll_1j_MM->Sumw2();
  h_mMETll_2j_MM = new TH2F("h_mMETll_2j_MM", "h_mMETll_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mMETll_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaYjj_1j_MM = new TH2F("h_DeltaYjj_1j_MM", "h_DeltaYjj_1j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_1j_MM->Sumw2();
  h_DeltaYjj_2j_MM = new TH2F("h_DeltaYjj_2j_MM", "h_DeltaYjj_2j_MM", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_2j_MM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mljj_1j_MM = new TH2F("h_mljj_1j_MM", "h_mljj_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mljj_1j_MM->Sumw2();
  h_mljj_2j_MM = new TH2F("h_mljj_2j_MM", "h_mljj_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mljj_2j_MM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mlj_1j_MM = new TH2F("h_mlj_1j_MM", "h_mlj_1j_MM", 100, 0, 500 ,130, 0, 129);  h_mlj_1j_MM->Sumw2();
  h_mlj_2j_MM = new TH2F("h_mlj_2j_MM", "h_mlj_2j_MM", 100, 0, 500 ,130, 0, 129);  h_mlj_2j_MM->Sumw2();

  //============================================================================================================
//============================================================================================================  
  
  h_pTl0_1j_EM = new TH2F("h_pTl0_1j_EM", "h_pTl0_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTl0_1j_EM->Sumw2();
  h_pTl0_2j_EM = new TH2F("h_pTl0_2j_EM", "h_pTl0_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTl0_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTl1_1j_EM = new TH2F("h_pTl1_1j_EM", "h_pTl1_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTl1_1j_EM->Sumw2();
  h_pTl1_2j_EM = new TH2F("h_pTl1_2j_EM", "h_pTl1_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTl1_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaRLeptons_1j_EM = new TH2F("h_DeltaRLeptons_1j_EM", "h_DeltaRLeptons_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_1j_EM->Sumw2();
  h_DeltaRLeptons_2j_EM = new TH2F("h_DeltaRLeptons_2j_EM", "h_DeltaRLeptons_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTj0_1j_EM = new TH2F("h_pTj0_1j_EM", "h_pTj0_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTj0_1j_EM->Sumw2();
  h_pTj0_2j_EM = new TH2F("h_pTj0_2j_EM", "h_pTj0_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTj0_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTj1_1j_EM = new TH2F("h_pTj1_1j_EM", "h_pTj1_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTj1_1j_EM->Sumw2();
  h_pTj1_2j_EM = new TH2F("h_pTj1_2j_EM", "h_pTj1_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTj1_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mll_1j_EM = new TH2F("h_mll_1j_EM", "h_mll_1j_EM", 100, 0, 500 ,130, 0, 129); h_mll_1j_EM->Sumw2();
  h_mll_2j_EM = new TH2F("h_mll_2j_EM", "h_mll_2j_EM", 100, 0, 500 ,130, 0, 129); h_mll_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_METrel_1j_EM = new TH2F("h_METrel_1j_EM", "h_METrel_1j_EM", 100, 0, 500 ,130, 0, 129);  h_METrel_1j_EM->Sumw2();
  h_METrel_2j_EM = new TH2F("h_METrel_2j_EM", "h_METrel_2j_EM", 100, 0, 500 ,130, 0, 129);  h_METrel_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_MET_1j_EM = new TH2F("h_MET_1j_EM", "h_MET_1j_EM", 100, 0, 500 ,130, 0, 129);  h_MET_1j_EM->Sumw2();
  h_MET_2j_EM = new TH2F("h_MET_2j_EM", "h_MET_2j_EM", 100, 0, 500 ,130, 0, 129);  h_MET_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_HT_1j_EM = new TH2F("h_HT_1j_EM", "h_HT_1j_EM", 100, 0, 500 ,130, 0, 129);  h_HT_1j_EM->Sumw2();
  h_HT_2j_EM = new TH2F("h_HT_2j_EM", "h_HT_2j_EM", 100, 0, 500 ,130, 0, 129);  h_HT_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mWWt_1j_EM = new TH2F("h_mWWt_1j_EM", "h_mWWt_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mWWt_1j_EM->Sumw2();
  h_mWWt_2j_EM = new TH2F("h_mWWt_2j_EM", "h_mWWt_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mWWt_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mTlmin_1j_EM = new TH2F("h_mTlmin_1j_EM", "h_mTlmin_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mTlmin_1j_EM->Sumw2();
  h_mTlmin_2j_EM = new TH2F("h_mTlmin_2j_EM", "h_mTlmin_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mTlmin_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTlmax_1j_EM = new TH2F("h_mTlmax_1j_EM", "h_mTlmax_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mTlmax_1j_EM->Sumw2();
  h_mTlmax_2j_EM = new TH2F("h_mTlmax_2j_EM", "h_mTlmax_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mTlmax_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_meff_1j_EM = new TH2F("h_meff_1j_EM", "h_meff_1j_EM", 100, 0, 500 ,130, 0, 129);  h_meff_1j_EM->Sumw2();
  h_meff_2j_EM = new TH2F("h_meff_2j_EM", "h_meff_2j_EM", 100, 0, 500 ,130, 0, 129);  h_meff_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mT2_1j_EM = new TH2F("h_mT2_1j_EM", "h_mT2_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mT2_1j_EM->Sumw2();
  h_mT2_2j_EM = new TH2F("h_mT2_2j_EM", "h_mT2_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mT2_2j_EM->Sumw2();
/*--------------------------------------------------------------------------------*/ 
  h_mT2J_1j_EM = new TH2F("h_mT2J_1j_EM", "h_mT2J_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mT2J_1j_EM->Sumw2();
  h_mT2J_2j_EM = new TH2F("h_mT2J_2j_EM", "h_mT2J_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mT2J_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mjj_1j_EM = new TH2F("h_mjj_1j_EM", "h_mjj_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mjj_1j_EM->Sumw2();
  h_mjj_2j_EM = new TH2F("h_mjj_2j_EM", "h_mjj_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mjj_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETll_1j_EM = new TH2F("h_DeltaPhiMETll_1j_EM", "h_DeltaPhiMETll_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_1j_EM->Sumw2();
  h_DeltaPhiMETll_2j_EM = new TH2F("h_DeltaPhiMETll_2j_EM", "h_DeltaPhiMETll_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhill_1j_EM = new TH2F("h_DeltaPhill_1j_EM", "h_DeltaPhill_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_1j_EM->Sumw2();
  h_DeltaPhill_2j_EM = new TH2F("h_DeltaPhill_2j_EM", "h_DeltaPhill_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NBJets_1j_EM = new TH2F("h_NBJets_1j_EM", "h_NBJets_1j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_1j_EM->Sumw2();
  h_NBJets_2j_EM = new TH2F("h_NBJets_2j_EM", "h_NBJets_2j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NCJets_1j_EM = new TH2F("h_NCJets_1j_EM", "h_NCJets_1j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_1j_EM->Sumw2();
  h_NCJets_2j_EM = new TH2F("h_NCJets_2j_EM", "h_NCJets_2j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_NFJets_1j_EM = new TH2F("h_NFJets_1j_EM", "h_NFJets_1j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_1j_EM->Sumw2();
  h_NFJets_2j_EM = new TH2F("h_NFJets_2j_EM", "h_NFJets_2j_EM", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhijj_1j_EM = new TH2F("h_DeltaPhijj_1j_EM", "h_DeltaPhijj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_1j_EM->Sumw2();
  h_DeltaPhijj_2j_EM = new TH2F("h_DeltaPhijj_2j_EM", "h_DeltaPhijj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTjj_1j_EM = new TH2F("h_pTjj_1j_EM", "h_pTjj_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTjj_1j_EM->Sumw2();
  h_pTjj_2j_EM = new TH2F("h_pTjj_2j_EM", "h_pTjj_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTjj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_pTll_1j_EM = new TH2F("h_pTll_1j_EM", "h_pTll_1j_EM", 100, 0, 500 ,130, 0, 129);  h_pTll_1j_EM->Sumw2();
  h_pTll_2j_EM = new TH2F("h_pTll_2j_EM", "h_pTll_2j_EM", 100, 0, 500 ,130, 0, 129);  h_pTll_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl0_1j_EM = new TH2F("h_DeltaPhiMETl0_1j_EM", "h_DeltaPhiMETl0_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_1j_EM->Sumw2();
  h_DeltaPhiMETl0_2j_EM = new TH2F("h_DeltaPhiMETl0_2j_EM", "h_DeltaPhiMETl0_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl1_1j_EM = new TH2F("h_DeltaPhiMETl1_1j_EM", "h_DeltaPhiMETl1_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_1j_EM->Sumw2();
  h_DeltaPhiMETl1_2j_EM = new TH2F("h_DeltaPhiMETl1_2j_EM", "h_DeltaPhiMETl1_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj0_1j_EM = new TH2F("h_DeltaPhiMETj0_1j_EM", "h_DeltaPhiMETj0_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_1j_EM->Sumw2();
  h_DeltaPhiMETj0_2j_EM = new TH2F("h_DeltaPhiMETj0_2j_EM", "h_DeltaPhiMETj0_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj1_1j_EM = new TH2F("h_DeltaPhiMETj1_1j_EM", "h_DeltaPhiMETj1_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_1j_EM->Sumw2();
  h_DeltaPhiMETj1_2j_EM = new TH2F("h_DeltaPhiMETj1_2j_EM", "h_DeltaPhiMETj1_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETjj_1j_EM = new TH2F("h_DeltaPhiMETjj_1j_EM", "h_DeltaPhiMETjj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_1j_EM->Sumw2();
  h_DeltaPhiMETjj_2j_EM = new TH2F("h_DeltaPhiMETjj_2j_EM", "h_DeltaPhiMETjj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaRjj_1j_EM = new TH2F("h_DeltaRjj_1j_EM", "h_DeltaRjj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_1j_EM->Sumw2();
  h_DeltaRjj_2j_EM = new TH2F("h_DeltaRjj_2j_EM", "h_DeltaRjj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etal0_1j_EM = new TH2F("h_etal0_1j_EM", "h_etal0_1j_EM", 70, 0, 7 ,130, 0, 129);  h_etal0_1j_EM->Sumw2();
  h_etal0_2j_EM = new TH2F("h_etal0_2j_EM", "h_etal0_2j_EM", 70, 0, 7 ,130, 0, 129);  h_etal0_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etal1_1j_EM = new TH2F("h_etal1_1j_EM", "h_etal1_1j_EM", 70, 0, 7 ,130, 0, 129);  h_etal1_1j_EM->Sumw2();
  h_etal1_2j_EM = new TH2F("h_etal1_2j_EM", "h_etal1_2j_EM", 70, 0, 7 ,130, 0, 129);  h_etal1_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj0_1j_EM = new TH2F("h_etaj0_1j_EM", "h_etaj0_1j_EM", 70, 0, 7 ,130, 0, 129);  h_etaj0_1j_EM->Sumw2();
  h_etaj0_2j_EM = new TH2F("h_etaj0_2j_EM", "h_etaj0_2j_EM", 70, 0, 7 ,130, 0, 129);  h_etaj0_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_etaj1_1j_EM = new TH2F("h_etaj1_1j_EM", "h_etaj1_1j_EM", 70, 0, 7 ,130, 0, 129);  h_etaj1_1j_EM->Sumw2();
  h_etaj1_2j_EM = new TH2F("h_etaj1_2j_EM", "h_etaj1_2j_EM", 70, 0, 7 ,130, 0, 129);  h_etaj1_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl0MET_1j_EM = new TH2F("h_mTl0MET_1j_EM", "h_mTl0MET_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_1j_EM->Sumw2();
  h_mTl0MET_2j_EM = new TH2F("h_mTl0MET_2j_EM", "h_mTl0MET_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mTl1MET_1j_EM = new TH2F("h_mTl1MET_1j_EM", "h_mTl1MET_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_1j_EM->Sumw2();
  h_mTl1MET_2j_EM = new TH2F("h_mTl1MET_2j_EM", "h_mTl1MET_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_2j_EM->Sumw2();
        /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhilljj_1j_EM = new TH2F("h_DeltaPhilljj_1j_EM", "h_DeltaPhilljj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_1j_EM->Sumw2();
  h_DeltaPhilljj_2j_EM = new TH2F("h_DeltaPhilljj_2j_EM", "h_DeltaPhilljj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil0jj_1j_EM = new TH2F("h_DeltaPhil0jj_1j_EM", "h_DeltaPhil0jj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_1j_EM->Sumw2();
  h_DeltaPhil0jj_2j_EM = new TH2F("h_DeltaPhil0jj_2j_EM", "h_DeltaPhil0jj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil1jj_1j_EM = new TH2F("h_DeltaPhil1jj_1j_EM", "h_DeltaPhil1jj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_1j_EM->Sumw2();
  h_DeltaPhil1jj_2j_EM = new TH2F("h_DeltaPhil1jj_2j_EM", "h_DeltaPhil1jj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaRlljj_1j_EM = new TH2F("h_DeltaRlljj_1j_EM", "h_DeltaRlljj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_1j_EM->Sumw2();
  h_DeltaRlljj_2j_EM = new TH2F("h_DeltaRlljj_2j_EM", "h_DeltaRlljj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_2j_EM->Sumw2();
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtajj_1j_EM = new TH2F("h_DeltaEtajj_1j_EM", "h_DeltaEtajj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_1j_EM->Sumw2();
  h_DeltaEtajj_2j_EM = new TH2F("h_DeltaEtajj_2j_EM", "h_DeltaEtajj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtall_1j_EM = new TH2F("h_DeltaEtall_1j_EM", "h_DeltaEtall_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_1j_EM->Sumw2();
  h_DeltaEtall_2j_EM = new TH2F("h_DeltaEtall_2j_EM", "h_DeltaEtall_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mMETll_1j_EM = new TH2F("h_mMETll_1j_EM", "h_mMETll_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mMETll_1j_EM->Sumw2();
  h_mMETll_2j_EM = new TH2F("h_mMETll_2j_EM", "h_mMETll_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mMETll_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaYjj_1j_EM = new TH2F("h_DeltaYjj_1j_EM", "h_DeltaYjj_1j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_1j_EM->Sumw2();
  h_DeltaYjj_2j_EM = new TH2F("h_DeltaYjj_2j_EM", "h_DeltaYjj_2j_EM", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_2j_EM->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mljj_1j_EM = new TH2F("h_mljj_1j_EM", "h_mljj_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mljj_1j_EM->Sumw2();
  h_mljj_2j_EM = new TH2F("h_mljj_2j_EM", "h_mljj_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mljj_2j_EM->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_mlj_1j_EM = new TH2F("h_mlj_1j_EM", "h_mlj_1j_EM", 100, 0, 500 ,130, 0, 129);  h_mlj_1j_EM->Sumw2();
  h_mlj_2j_EM = new TH2F("h_mlj_2j_EM", "h_mlj_2j_EM", 100, 0, 500 ,130, 0, 129);  h_mlj_2j_EM->Sumw2();

  return true;

}

void SusySel::calc_MM_variables(TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, vector<FourMom> *signalJets, vector<FourMom> *m_leptons){
  pTl0_MM = (mu0_TLV.Pt() > mu1_TLV.Pt()) ? mu0_TLV.Pt() : mu1_TLV.Pt();
  pTl1_MM = (mu0_TLV.Pt() > mu1_TLV.Pt()) ? mu1_TLV.Pt() : mu0_TLV.Pt();
  HT_MM = calcHT(mu0_TLV, mu1_TLV, met_TLV, m_jets);
  Mll_MM = (mu0_TLV + mu1_TLV).M();
  METrel_MM = recalcMetRel(met_TLV, mu0_TLV, mu1_TLV, signalJets);
  mTWW_MM = calcMt((mu0_TLV + mu1_TLV), met_TLV);
  mT2J_MM = calcMT2J(met_TLV, mu0_TLV, mu1_TLV, signalJets);
//   cout << "mT2J_MM= " << mT2J_MM << endl;
  Mljj_MM = -1.;
  if((*signalJets).size()/2>1){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    FourMom signalJet1 =     (*signalJets).at(1);
    TLorentzVector jet1_TLV;
    jet1_TLV.SetPxPyPzE(signalJet1.px, signalJet1.py, signalJet1.pz, signalJet1.E);
    //find dijet axis:
    double DeltaRDijetEl0 = mu0_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetE = mu1_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestElecDijetAxis_TLV = (DeltaRDijetEl0 > DeltaRDijetE) ? mu1_TLV : mu0_TLV;
    Mljj_MM = (jet0_TLV + jet1_TLV + closestElecDijetAxis_TLV).M();
  }
  

  Mlj_MM = -1.;
  if((*signalJets).size()/2>0){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    //find dijet axis:
    double DeltaRDijetl0 = mu0_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetl1 = mu1_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestLepton_TLV = (DeltaRDijetl0 > DeltaRDijetl1) ? mu1_TLV : mu0_TLV;
    Mlj_MM = (jet0_TLV + closestLepton_TLV).M();
  }
  
  mTmin_MM = (calcMt(mu0_TLV, met_TLV) > calcMt(mu1_TLV, met_TLV)) ? calcMt(mu1_TLV, met_TLV) : calcMt(mu0_TLV, met_TLV);
  mTmax_MM = (calcMt(mu0_TLV, met_TLV) < calcMt(mu1_TLV, met_TLV)) ? calcMt(mu1_TLV, met_TLV) : calcMt(mu0_TLV, met_TLV);
  DeltaEtall_MM = fabs(mu0_TLV.Eta() - mu1_TLV.Eta());
  mass_3rdlepZ_MM = calc_Ml_3rdl(mu0_TLV, mu1_TLV, m_lepts);
  
  mT2_MM = calcMT2(met_TLV, mu0_TLV, mu1_TLV);
  etal0_MM = fabs(mu0_TLV.Eta());
  etal1_MM = fabs(mu1_TLV.Eta());
  
}  

void SusySel::calc_EE_variables(TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, vector<FourMom> *signalJets, vector<FourMom> *m_leptons){
  pTl0_EE = (el0_TLV.Pt() > el1_TLV.Pt()) ? el0_TLV.Pt() : el1_TLV.Pt();
  pTl1_EE = (el0_TLV.Pt() > el1_TLV.Pt()) ? el1_TLV.Pt() : el0_TLV.Pt();
  HT_EE = calcHT(el0_TLV, el1_TLV, met_TLV, m_jets);
  Mll_EE = (el0_TLV + el1_TLV).M();
  METrel_EE = recalcMetRel(met_TLV, el0_TLV, el1_TLV, signalJets);
  mTWW_EE = calcMt((el0_TLV + el1_TLV), met_TLV);
  mT2J_EE = calcMT2J(met_TLV, el0_TLV, el1_TLV, signalJets);
  Mljj_EE = -1.;
  if((*signalJets).size()/2>1){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    FourMom signalJet1 =     (*signalJets).at(1);
    TLorentzVector jet1_TLV;
    jet1_TLV.SetPxPyPzE(signalJet1.px, signalJet1.py, signalJet1.pz, signalJet1.E);
    //find dijet axis:
    double DeltaRDijetEl0 = el0_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el0_TLV.Phi()),2));
    double DeltaRDijetE = el1_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el1_TLV.Phi()),2));
    TLorentzVector closestElecDijetAxis_TLV = (DeltaRDijetEl0 > DeltaRDijetE) ? el1_TLV : el0_TLV;
    Mljj_EE = (jet0_TLV + jet1_TLV + closestElecDijetAxis_TLV).M();
  }
  
  Mlj_EE = -1.;
  if((*signalJets).size()/2>0){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    //find dijet axis:
    double DeltaRDijetl0 = el0_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetl1 = el1_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestLepton_TLV = (DeltaRDijetl0 > DeltaRDijetl1) ? el1_TLV : el0_TLV;
    Mlj_EE = (jet0_TLV + closestLepton_TLV).M();
  }
  
  mTmin_EE = (calcMt(el0_TLV, met_TLV) > calcMt(el1_TLV, met_TLV)) ? calcMt(el1_TLV, met_TLV) : calcMt(el0_TLV, met_TLV);
  mTmax_EE = (calcMt(el0_TLV, met_TLV) < calcMt(el1_TLV, met_TLV)) ? calcMt(el1_TLV, met_TLV) : calcMt(el0_TLV, met_TLV);
  DeltaEtall_EE = fabs(el0_TLV.Eta() - el1_TLV.Eta());
  mass_3rdlepZ_EE = calc_Ml_3rdl(el0_TLV, el1_TLV, m_lepts);
  
  mT2_EE = calcMT2(met_TLV, el0_TLV, el1_TLV);
  etal0_EE = fabs(el0_TLV.Eta());
  etal1_EE = fabs(el1_TLV.Eta());

} 

void SusySel::calc_EM_variables(TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, vector<FourMom> *signalJets, vector<FourMom> *m_leptons){
  pTl0_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? el_TLV.Pt() : mu_TLV.Pt();
  pTl1_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? mu_TLV.Pt() : el_TLV.Pt();
  HT_EM = calcHT(el_TLV, mu_TLV, met_TLV, m_jets);
  Mll_EM = (el_TLV + mu_TLV).M();
  METrel_EM = recalcMetRel(met_TLV, el_TLV, mu_TLV, signalJets);
  mTWW_EM = calcMt((el_TLV + mu_TLV), met_TLV);
  mT2J_EM = calcMT2J(met_TLV, el_TLV, mu_TLV, signalJets);
  Mljj_EM = -1.;
  if((*signalJets).size()/2>1){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    FourMom signalJet1 =     (*signalJets).at(1);
    TLorentzVector jet1_TLV;
    jet1_TLV.SetPxPyPzE(signalJet1.px, signalJet1.py, signalJet1.pz, signalJet1.E);
    //find dijet axis:
    double DeltaRDijetEl0 = el_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el_TLV.Phi()),2));
    double DeltaRDijetE = mu_TLV.DeltaR(jet0_TLV + jet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu_TLV.Phi()),2));
    TLorentzVector closestElecDijetAxis_TLV = (DeltaRDijetEl0 > DeltaRDijetE) ? mu_TLV : el_TLV;
    Mljj_EM = (jet0_TLV + jet1_TLV + closestElecDijetAxis_TLV).M();
  }
  
  Mlj_EM = -1.;
  if((*signalJets).size()/2>0){
    FourMom signalJet0 =     (*signalJets).at(0);
    TLorentzVector jet0_TLV;
    jet0_TLV.SetPxPyPzE(signalJet0.px, signalJet0.py, signalJet0.pz, signalJet0.E);
    //find dijet axis:
    double DeltaRDijetl0 = mu_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetl1 = el_TLV.DeltaR(jet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestLepton_TLV = (DeltaRDijetl0 > DeltaRDijetl1) ? el_TLV : mu_TLV;
    Mlj_EM = (jet0_TLV + closestLepton_TLV).M();
  }
  
  mTmin_EM = (calcMt(el_TLV, met_TLV) > calcMt(mu_TLV, met_TLV)) ? calcMt(mu_TLV, met_TLV) : calcMt(el_TLV, met_TLV);
  mTmax_EM = (calcMt(el_TLV, met_TLV) < calcMt(mu_TLV, met_TLV)) ? calcMt(mu_TLV, met_TLV) : calcMt(el_TLV, met_TLV);
  DeltaEtall_EM = fabs(el_TLV.Eta() - mu_TLV.Eta());
  mass_3rdlepZ_EM = calc_Ml_3rdl(mu_TLV, el_TLV, m_lepts);
  
  mT2_EM = calcMT2(met_TLV, mu_TLV, el_TLV);
  etal0_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? fabs(el_TLV.Eta()) : fabs(mu_TLV.Eta());
  etal1_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? fabs(mu_TLV.Eta()) : fabs(el_TLV.Eta());
}


  
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_1j_EE(int cutnumber, float weight){
  cutflow_EE->Fill(cutnumber,1.0);
  cutflow_EE_ALL->Fill(cutnumber, weight);

  h_pTl0_1j_EE->Fill(pTl0_EE, cutnumber, weight);   
  h_pTl1_1j_EE->Fill(pTl1_EE, cutnumber, weight);
  h_HT_1j_EE->Fill(HT_EE, cutnumber, weight);
  h_mll_1j_EE->Fill(Mll_EE, cutnumber, weight);
  h_METrel_1j_EE->Fill(METrel_EE, cutnumber, weight);
  h_mWWt_1j_EE->Fill(mTWW_EE, cutnumber, weight);
  h_mT2J_1j_EE->Fill(mT2J_EE, cutnumber, weight);
  h_mljj_1j_EE->Fill(Mljj_EE, cutnumber, weight);
  h_mlj_1j_EE->Fill(Mlj_EE, cutnumber, weight);
  h_mTlmax_1j_EE->Fill(mTmax_EE, cutnumber, weight);
  h_mTlmin_1j_EE->Fill(mTmin_EE, cutnumber, weight);
  h_DeltaEtall_1j_EE->Fill(DeltaEtall_EE, cutnumber, weight);
  
  h_mT2_1j_EE->Fill(mT2_EE, cutnumber, weight);
  h_etal0_1j_EE->Fill(etal0_EE, cutnumber, weight);
  h_etal1_1j_EE->Fill(etal1_EE, cutnumber, weight);  
  
}
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_2j_EE(int cutnumber, float weight){
  cutflow_EE->Fill(cutnumber,1.0);
  cutflow_EE_ALL->Fill(cutnumber, weight);

  h_pTl0_2j_EE->Fill(pTl0_EE, cutnumber, weight);   
  h_pTl1_2j_EE->Fill(pTl1_EE, cutnumber, weight);
  h_HT_2j_EE->Fill(HT_EE, cutnumber, weight);
  h_mll_2j_EE->Fill(Mll_EE, cutnumber, weight);
  h_METrel_2j_EE->Fill(METrel_EE, cutnumber, weight);
  h_mWWt_2j_EE->Fill(mTWW_EE, cutnumber, weight);
  h_mT2J_2j_EE->Fill(mT2J_EE, cutnumber, weight);
  h_mljj_2j_EE->Fill(Mljj_EE, cutnumber, weight);
  h_mlj_2j_EE->Fill(Mlj_EE, cutnumber, weight);
  h_mTlmax_2j_EE->Fill(mTmax_EE, cutnumber, weight);
  h_mTlmin_2j_EE->Fill(mTmin_EE, cutnumber, weight);
  h_DeltaEtall_2j_EE->Fill(DeltaEtall_EE, cutnumber, weight);
  
  h_mT2_2j_EE->Fill(mT2_EE, cutnumber, weight);
  h_etal0_2j_EE->Fill(etal0_EE, cutnumber, weight);
  h_etal1_2j_EE->Fill(etal1_EE, cutnumber, weight);  
  
}
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_1j_MM(int cutnumber, float weight){
  cutflow_MM->Fill(cutnumber,1.0);
  cutflow_MM_ALL->Fill(cutnumber, weight);

  h_pTl0_1j_MM->Fill(pTl0_MM, cutnumber, weight);   
  h_pTl1_1j_MM->Fill(pTl1_MM, cutnumber, weight);
  h_HT_1j_MM->Fill(HT_MM, cutnumber, weight);
  h_mll_1j_MM->Fill(Mll_MM, cutnumber, weight);
  h_METrel_1j_MM->Fill(METrel_MM, cutnumber, weight);
  h_mWWt_1j_MM->Fill(mTWW_MM, cutnumber, weight);
  h_mT2J_1j_MM->Fill(mT2J_MM, cutnumber, weight);
  h_mljj_1j_MM->Fill(Mljj_MM, cutnumber, weight);
  h_mlj_1j_MM->Fill(Mlj_MM, cutnumber, weight);
  h_mTlmax_1j_MM->Fill(mTmax_MM, cutnumber, weight);
  h_mTlmin_1j_MM->Fill(mTmin_MM, cutnumber, weight);
  h_DeltaEtall_1j_MM->Fill(DeltaEtall_MM, cutnumber, weight);
  
  h_mT2_1j_MM->Fill(mT2_MM, cutnumber, weight);
  h_etal0_1j_MM->Fill(etal0_MM, cutnumber, weight);
  h_etal1_1j_MM->Fill(etal1_MM, cutnumber, weight);  
  
}
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_2j_MM(int cutnumber, float weight){
  cutflow_MM->Fill(cutnumber,1.0);
  cutflow_MM_ALL->Fill(cutnumber, weight);

  h_pTl0_2j_MM->Fill(pTl0_MM, cutnumber, weight);   
  h_pTl1_2j_MM->Fill(pTl1_MM, cutnumber, weight);
  h_HT_2j_MM->Fill(HT_MM, cutnumber, weight);
  h_mll_2j_MM->Fill(Mll_MM, cutnumber, weight);
  h_METrel_2j_MM->Fill(METrel_MM, cutnumber, weight);
  h_mWWt_2j_MM->Fill(mTWW_MM, cutnumber, weight);
  h_mT2J_2j_MM->Fill(mT2J_MM, cutnumber, weight);
  h_mljj_2j_MM->Fill(Mljj_MM, cutnumber, weight);
  h_mlj_2j_MM->Fill(Mlj_MM, cutnumber, weight);
  h_mTlmax_2j_MM->Fill(mTmax_MM, cutnumber, weight);
  h_mTlmin_2j_MM->Fill(mTmin_MM, cutnumber, weight);
  h_DeltaEtall_2j_MM->Fill(DeltaEtall_MM, cutnumber, weight);
  
  h_mT2_2j_MM->Fill(mT2_MM, cutnumber, weight);
  h_etal0_2j_MM->Fill(etal0_MM, cutnumber, weight);
  h_etal1_2j_MM->Fill(etal1_MM, cutnumber, weight);  
  
}
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_1j_EM(int cutnumber, float weight){
  cutflow_EM->Fill(cutnumber,1.0);
  cutflow_EM_ALL->Fill(cutnumber, weight);

  h_pTl0_1j_EM->Fill(pTl0_EM, cutnumber, weight);   
  h_pTl1_1j_EM->Fill(pTl1_EM, cutnumber, weight);
  h_HT_1j_EM->Fill(HT_EM, cutnumber, weight);
  h_mll_1j_EM->Fill(Mll_EM, cutnumber, weight);
  h_METrel_1j_EM->Fill(METrel_EM, cutnumber, weight);
  h_mWWt_1j_EM->Fill(mTWW_EM, cutnumber, weight);
  h_mT2J_1j_EM->Fill(mT2J_EM, cutnumber, weight);
  h_mljj_1j_EM->Fill(Mljj_EM, cutnumber, weight);
  h_mlj_1j_EM->Fill(Mlj_EM, cutnumber, weight);
  h_mTlmax_1j_EM->Fill(mTmax_EM, cutnumber, weight);
  h_mTlmin_1j_EM->Fill(mTmin_EM, cutnumber, weight);
  h_DeltaEtall_1j_EM->Fill(DeltaEtall_EM, cutnumber, weight);
  
  h_mT2_1j_EM->Fill(mT2_EM, cutnumber, weight);
  h_etal0_1j_EM->Fill(etal0_EM, cutnumber, weight);
  h_etal1_1j_EM->Fill(etal1_EM, cutnumber, weight);  
  
}
/*--------------------------------------------------------------------------------*/
void SusySel::fillHistos_2j_EM(int cutnumber, float weight){
  cutflow_EM->Fill(cutnumber,1.0);
  cutflow_EM_ALL->Fill(cutnumber, weight);

  h_pTl0_2j_EM->Fill(pTl0_EM, cutnumber, weight);   
  h_pTl1_2j_EM->Fill(pTl1_EM, cutnumber, weight);
  h_HT_2j_EM->Fill(HT_EM, cutnumber, weight);
  h_mll_2j_EM->Fill(Mll_EM, cutnumber, weight);
  h_METrel_2j_EM->Fill(METrel_EM, cutnumber, weight);
  h_mWWt_2j_EM->Fill(mTWW_EM, cutnumber, weight);
  h_mT2J_2j_EM->Fill(mT2J_EM, cutnumber, weight);
  h_mljj_2j_EM->Fill(Mljj_EM, cutnumber, weight);
  h_mlj_2j_EM->Fill(Mlj_EM, cutnumber, weight);
  h_mTlmax_2j_EM->Fill(mTmax_EM, cutnumber, weight);
  h_mTlmin_2j_EM->Fill(mTmin_EM, cutnumber, weight);
  h_DeltaEtall_2j_EM->Fill(DeltaEtall_EM, cutnumber, weight);
  
  h_mT2_2j_EM->Fill(mT2_EM, cutnumber, weight);
  h_etal0_2j_EM->Fill(etal0_EM, cutnumber, weight);
  h_etal1_2j_EM->Fill(etal1_EM, cutnumber, weight);  
  
}



bool SusySel::writeHistos(){

//   bool EE_SRSS1 = true;
//   bool EE_SRSS2 = false;
//   bool MM_SRSS1 = true;
//   bool MM_SRSS2 = false;
//   bool MM_SRSS3 = false;
//   bool MM_SRSS4 = false;
//   bool EM_SRSS1 = true;
//   bool EM_SRSS2 = false;
//   bool EE_SROS1 = false;
//   bool MM_SROS1 = false;
//   bool EM_SROS1 = false;
  

  cutflow_EE->Write();
  cutflow_EE_ALL->Write();  
  cutflow_MM->Write();
  cutflow_MM_ALL->Write();  
  cutflow_EM->Write();
  cutflow_EM_ALL->Write();
  
   h_pTl0_1j_EE->Write();
  h_pTl0_2j_EE->Write();

  h_pTl1_1j_EE->Write();
  h_pTl1_2j_EE->Write();

  h_DeltaRLeptons_1j_EE->Write();
  h_DeltaRLeptons_2j_EE->Write();
    
  h_pTj0_1j_EE->Write();
  h_pTj0_2j_EE->Write();
    

  h_pTj1_1j_EE->Write();
  h_pTj1_2j_EE->Write();
    

  h_mll_1j_EE->Write();
  h_mll_2j_EE->Write();


  h_METrel_1j_EE->Write();
  h_METrel_2j_EE->Write();
    
  h_MET_1j_EE->Write();
  h_MET_2j_EE->Write();
    
  h_HT_1j_EE->Write();
  h_HT_2j_EE->Write();
    
  h_mWWt_1j_EE->Write();
  h_mWWt_2j_EE->Write();

  h_mTlmin_1j_EE->Write();
  h_mTlmin_2j_EE->Write();
    
  h_mTlmax_1j_EE->Write();
  h_mTlmax_2j_EE->Write();
    
  h_meff_1j_EE->Write();
  h_meff_2j_EE->Write();
    
  h_mT2_1j_EE->Write();
  h_mT2_2j_EE->Write();
    

  h_mT2J_1j_EE->Write();
  h_mT2J_2j_EE->Write();
    

  h_mjj_1j_EE->Write();
  h_mjj_2j_EE->Write();
      
  h_DeltaPhiMETll_1j_EE->Write();
  h_DeltaPhiMETll_2j_EE->Write();
      
  h_DeltaPhill_1j_EE->Write();
  h_DeltaPhill_2j_EE->Write();
    
  h_NBJets_1j_EE->Write();
  h_NBJets_2j_EE->Write();
    
  h_NCJets_1j_EE->Write();
  h_NCJets_2j_EE->Write();
    
  h_NFJets_1j_EE->Write();
  h_NFJets_2j_EE->Write();
    
  h_DeltaPhijj_1j_EE->Write();
  h_DeltaPhijj_2j_EE->Write();
    
  h_pTjj_1j_EE->Write();
  h_pTjj_2j_EE->Write();
    
  h_pTll_1j_EE->Write();
  h_pTll_2j_EE->Write();
    
  h_DeltaPhiMETl0_1j_EE->Write();
  h_DeltaPhiMETl0_2j_EE->Write();
    
  h_DeltaPhiMETl1_1j_EE->Write();
  h_DeltaPhiMETl1_2j_EE->Write();
      
  h_DeltaPhiMETj0_1j_EE->Write();
  h_DeltaPhiMETj0_2j_EE->Write();
    
  h_DeltaPhiMETj1_1j_EE->Write();
  h_DeltaPhiMETj1_2j_EE->Write();
    
  h_DeltaPhiMETjj_1j_EE->Write();
  h_DeltaPhiMETjj_2j_EE->Write();
      
  h_DeltaRjj_1j_EE->Write();
  h_DeltaRjj_2j_EE->Write();
    
  h_etal0_1j_EE->Write();
  h_etal0_2j_EE->Write();
      
  h_etal1_1j_EE->Write();
  h_etal1_2j_EE->Write();
      
  h_etaj0_1j_EE->Write();
  h_etaj0_2j_EE->Write();
      
  h_etaj1_1j_EE->Write();
  h_etaj1_2j_EE->Write();
    
  h_mTl0MET_1j_EE->Write();
  h_mTl0MET_2j_EE->Write();
    
  h_mTl1MET_1j_EE->Write();
  h_mTl1MET_2j_EE->Write();
	
  h_DeltaPhilljj_1j_EE->Write();
  h_DeltaPhilljj_2j_EE->Write();
      
  h_DeltaPhil0jj_1j_EE->Write();
  h_DeltaPhil0jj_2j_EE->Write();
    
  h_DeltaPhil1jj_1j_EE->Write();
  h_DeltaPhil1jj_2j_EE->Write();
    
  h_DeltaRlljj_1j_EE->Write();
  h_DeltaRlljj_2j_EE->Write();
      
  h_DeltaEtajj_1j_EE->Write();
  h_DeltaEtajj_2j_EE->Write();
    
  h_DeltaEtall_1j_EE->Write();
  h_DeltaEtall_2j_EE->Write();
    
  h_mMETll_1j_EE->Write();
  h_mMETll_2j_EE->Write();
    
  h_DeltaYjj_1j_EE->Write();
  h_DeltaYjj_2j_EE->Write();
  
  h_mljj_1j_EE->Write();
  h_mljj_2j_EE->Write();
  
  h_mlj_1j_EE->Write();
  h_mlj_2j_EE->Write();
  
  h_mT2_1j_EE->Write();
  h_mT2_2j_EE->Write();
  
//==============================  
   h_pTl0_1j_MM->Write();
  h_pTl0_2j_MM->Write();

  h_pTl1_1j_MM->Write();
  h_pTl1_2j_MM->Write();

  h_DeltaRLeptons_1j_MM->Write();
  h_DeltaRLeptons_2j_MM->Write();
    
  h_pTj0_1j_MM->Write();
  h_pTj0_2j_MM->Write();
    

  h_pTj1_1j_MM->Write();
  h_pTj1_2j_MM->Write();
    

  h_mll_1j_MM->Write();
  h_mll_2j_MM->Write();


  h_METrel_1j_MM->Write();
  h_METrel_2j_MM->Write();
    
  h_MET_1j_MM->Write();
  h_MET_2j_MM->Write();
    
  h_HT_1j_MM->Write();
  h_HT_2j_MM->Write();
    
  h_mWWt_1j_MM->Write();
  h_mWWt_2j_MM->Write();

  h_mTlmin_1j_MM->Write();
  h_mTlmin_2j_MM->Write();
    
  h_mTlmax_1j_MM->Write();
  h_mTlmax_2j_MM->Write();
    
  h_meff_1j_MM->Write();
  h_meff_2j_MM->Write();
    
  h_mT2_1j_MM->Write();
  h_mT2_2j_MM->Write();
    

  h_mT2J_1j_MM->Write();
  h_mT2J_2j_MM->Write();
    

  h_mjj_1j_MM->Write();
  h_mjj_2j_MM->Write();
      
  h_DeltaPhiMETll_1j_MM->Write();
  h_DeltaPhiMETll_2j_MM->Write();
      
  h_DeltaPhill_1j_MM->Write();
  h_DeltaPhill_2j_MM->Write();
    
  h_NBJets_1j_MM->Write();
  h_NBJets_2j_MM->Write();
    
  h_NCJets_1j_MM->Write();
  h_NCJets_2j_MM->Write();
    
  h_NFJets_1j_MM->Write();
  h_NFJets_2j_MM->Write();
    
  h_DeltaPhijj_1j_MM->Write();
  h_DeltaPhijj_2j_MM->Write();
    
  h_pTjj_1j_MM->Write();
  h_pTjj_2j_MM->Write();
    
  h_pTll_1j_MM->Write();
  h_pTll_2j_MM->Write();
    
  h_DeltaPhiMETl0_1j_MM->Write();
  h_DeltaPhiMETl0_2j_MM->Write();
    
  h_DeltaPhiMETl1_1j_MM->Write();
  h_DeltaPhiMETl1_2j_MM->Write();
      
  h_DeltaPhiMETj0_1j_MM->Write();
  h_DeltaPhiMETj0_2j_MM->Write();
    
  h_DeltaPhiMETj1_1j_MM->Write();
  h_DeltaPhiMETj1_2j_MM->Write();
    
  h_DeltaPhiMETjj_1j_MM->Write();
  h_DeltaPhiMETjj_2j_MM->Write();
      
  h_DeltaRjj_1j_MM->Write();
  h_DeltaRjj_2j_MM->Write();
    
  h_etal0_1j_MM->Write();
  h_etal0_2j_MM->Write();
      
  h_etal1_1j_MM->Write();
  h_etal1_2j_MM->Write();
      
  h_etaj0_1j_MM->Write();
  h_etaj0_2j_MM->Write();
      
  h_etaj1_1j_MM->Write();
  h_etaj1_2j_MM->Write();
    
  h_mTl0MET_1j_MM->Write();
  h_mTl0MET_2j_MM->Write();
    
  h_mTl1MET_1j_MM->Write();
  h_mTl1MET_2j_MM->Write();
	
  h_DeltaPhilljj_1j_MM->Write();
  h_DeltaPhilljj_2j_MM->Write();
      
  h_DeltaPhil0jj_1j_MM->Write();
  h_DeltaPhil0jj_2j_MM->Write();
    
  h_DeltaPhil1jj_1j_MM->Write();
  h_DeltaPhil1jj_2j_MM->Write();
    
  h_DeltaRlljj_1j_MM->Write();
  h_DeltaRlljj_2j_MM->Write();
      
  h_DeltaEtajj_1j_MM->Write();
  h_DeltaEtajj_2j_MM->Write();
    
  h_DeltaEtall_1j_MM->Write();
  h_DeltaEtall_2j_MM->Write();
    
  h_mMETll_1j_MM->Write();
  h_mMETll_2j_MM->Write();
    
  h_DeltaYjj_1j_MM->Write();
  h_DeltaYjj_2j_MM->Write();
  
  h_mljj_1j_MM->Write();
  h_mljj_2j_MM->Write();
  
  h_mlj_1j_MM->Write();
  h_mlj_2j_MM->Write();
  
  //==============================  
   h_pTl0_1j_EM->Write();
  h_pTl0_2j_EM->Write();

  h_pTl1_1j_EM->Write();
  h_pTl1_2j_EM->Write();

  h_DeltaRLeptons_1j_EM->Write();
  h_DeltaRLeptons_2j_EM->Write();
    
  h_pTj0_1j_EM->Write();
  h_pTj0_2j_EM->Write();
    

  h_pTj1_1j_EM->Write();
  h_pTj1_2j_EM->Write();
    

  h_mll_1j_EM->Write();
  h_mll_2j_EM->Write();


  h_METrel_1j_EM->Write();
  h_METrel_2j_EM->Write();
    
  h_MET_1j_EM->Write();
  h_MET_2j_EM->Write();
    
  h_HT_1j_EM->Write();
  h_HT_2j_EM->Write();
    
  h_mWWt_1j_EM->Write();
  h_mWWt_2j_EM->Write();

  h_mTlmin_1j_EM->Write();
  h_mTlmin_2j_EM->Write();
    
  h_mTlmax_1j_EM->Write();
  h_mTlmax_2j_EM->Write();
    
  h_meff_1j_EM->Write();
  h_meff_2j_EM->Write();
    
  h_mT2_1j_EM->Write();
  h_mT2_2j_EM->Write();
    

  h_mT2J_1j_EM->Write();
  h_mT2J_2j_EM->Write();
    

  h_mjj_1j_EM->Write();
  h_mjj_2j_EM->Write();
      
  h_DeltaPhiMETll_1j_EM->Write();
  h_DeltaPhiMETll_2j_EM->Write();
      
  h_DeltaPhill_1j_EM->Write();
  h_DeltaPhill_2j_EM->Write();
    
  h_NBJets_1j_EM->Write();
  h_NBJets_2j_EM->Write();
    
  h_NCJets_1j_EM->Write();
  h_NCJets_2j_EM->Write();
    
  h_NFJets_1j_EM->Write();
  h_NFJets_2j_EM->Write();
    
  h_DeltaPhijj_1j_EM->Write();
  h_DeltaPhijj_2j_EM->Write();
    
  h_pTjj_1j_EM->Write();
  h_pTjj_2j_EM->Write();
    
  h_pTll_1j_EM->Write();
  h_pTll_2j_EM->Write();
    
  h_DeltaPhiMETl0_1j_EM->Write();
  h_DeltaPhiMETl0_2j_EM->Write();
    
  h_DeltaPhiMETl1_1j_EM->Write();
  h_DeltaPhiMETl1_2j_EM->Write();
      
  h_DeltaPhiMETj0_1j_EM->Write();
  h_DeltaPhiMETj0_2j_EM->Write();
    
  h_DeltaPhiMETj1_1j_EM->Write();
  h_DeltaPhiMETj1_2j_EM->Write();
    
  h_DeltaPhiMETjj_1j_EM->Write();
  h_DeltaPhiMETjj_2j_EM->Write();
      
  h_DeltaRjj_1j_EM->Write();
  h_DeltaRjj_2j_EM->Write();
    
  h_etal0_1j_EM->Write();
  h_etal0_2j_EM->Write();
      
  h_etal1_1j_EM->Write();
  h_etal1_2j_EM->Write();
      
  h_etaj0_1j_EM->Write();
  h_etaj0_2j_EM->Write();
      
  h_etaj1_1j_EM->Write();
  h_etaj1_2j_EM->Write();
    
  h_mTl0MET_1j_EM->Write();
  h_mTl0MET_2j_EM->Write();
    
  h_mTl1MET_1j_EM->Write();
  h_mTl1MET_2j_EM->Write();
	
  h_DeltaPhilljj_1j_EM->Write();
  h_DeltaPhilljj_2j_EM->Write();
      
  h_DeltaPhil0jj_1j_EM->Write();
  h_DeltaPhil0jj_2j_EM->Write();
    
  h_DeltaPhil1jj_1j_EM->Write();
  h_DeltaPhil1jj_2j_EM->Write();
    
  h_DeltaRlljj_1j_EM->Write();
  h_DeltaRlljj_2j_EM->Write();
      
  h_DeltaEtajj_1j_EM->Write();
  h_DeltaEtajj_2j_EM->Write();
    
  h_DeltaEtall_1j_EM->Write();
  h_DeltaEtall_2j_EM->Write();
    
  h_mMETll_1j_EM->Write();
  h_mMETll_2j_EM->Write();
    
  h_DeltaYjj_1j_EM->Write();
  h_DeltaYjj_2j_EM->Write();
  
  h_mljj_1j_EM->Write();
  h_mljj_2j_EM->Write();
  
  h_mlj_1j_EM->Write();
  h_mlj_2j_EM->Write();
      
  return true;
}


