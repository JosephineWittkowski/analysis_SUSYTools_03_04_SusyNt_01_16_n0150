void TSelector_SusyNtuple::defineHistos(){

  h_storeSumwMcid = new TH1F("h_storeSumwMcid", "h_storeSumwMcid", 200000, 0, 200000.);  h_storeSumwMcid->Sumw2();
  
  cutflow_EE = new TH1F("cutflow_EE", "cutflow_EE" ,130, 0, 129); cutflow_EE->Sumw2();
  cutflow_EE_ALL = new TH1F("cutflow_EE_ALL", "cutflow_EE_ALL" ,130, 0, 129); cutflow_EE_ALL->Sumw2();

  cutflow_MM = new TH1F("cutflow_MM", "cutflow_MM" ,130, 0, 129); cutflow_EE_ALL->Sumw2();
  cutflow_MM_ALL = new TH1F("cutflow_MM_ALL", "cutflow_MM_ALL" ,130, 0, 129); cutflow_MM_ALL->Sumw2();

  cutflow_EM = new TH1F("cutflow_EM", "cutflow_EM" ,130, 0, 129); cutflow_EM->Sumw2();
  cutflow_EM_ALL = new TH1F("cutflow_EM_ALL", "cutflow_EM_ALL" ,130, 0, 129);  ; cutflow_EM_ALL->Sumw2();
  
  h_NpreTaus = new TH2F("h_NpreTaus", "h_NpreTaus", 11, -0.5, 10.5, 130, 0, 129); h_NpreTaus->Sumw2();
  
  h_DeltaR_JVF_ljOR_EE = new TH2F("h_DeltaR_JVF_ljOR_EE", "h_DeltaR_JVF_ljOR_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_JVF_ljOR_EE->Sumw2();
  h_DeltaR_JVF_ljOR_MM = new TH2F("h_DeltaR_JVF_ljOR_MM", "h_DeltaR_JVF_ljOR_MM", 70, 0, 7, 100, 0, 1); h_DeltaR_JVF_ljOR_MM->Sumw2();
  h_DeltaR_JVF_ljOR_mu_EM = new TH2F("h_DeltaR_JVF_ljOR_mu_EM", "h_DeltaR_JVF_ljOR_mu_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_JVF_ljOR_mu_EM->Sumw2();
  h_DeltaR_JVF_ljOR_el_EM = new TH2F("h_DeltaR_JVF_ljOR_el_EM", "h_DeltaR_JVF_ljOR_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_JVF_ljOR_el_EM->Sumw2();

  h_DeltaR_mll_ljOR_EE = new TH2F("h_DeltaR_mll_ljOR_EE", "h_DeltaR_mll_ljOR_EE", 70, 0, 7, 100, 0, 500); h_DeltaR_mll_ljOR_EE->Sumw2();
  h_DeltaR_mll_ljOR_MM = new TH2F("h_DeltaR_mll_ljOR_MM", "h_DeltaR_mll_ljOR_MM", 70, 0, 7, 100, 0, 500); h_DeltaR_mll_ljOR_MM->Sumw2();
  h_DeltaR_mll_ljOR_mu_EM = new TH2F("h_DeltaR_mll_ljOR_mu_EM", "h_DeltaR_mll_ljOR_mu_EM", 70, 0, 7, 100, 0, 500); h_DeltaR_mll_ljOR_mu_EM->Sumw2();
  h_DeltaR_mll_ljOR_el_EM = new TH2F("h_DeltaR_mll_ljOR_el_EM", "h_DeltaR_mll_ljOR_el_EM", 70, 0, 7, 100, 0, 500); h_DeltaR_mll_ljOR_el_EM->Sumw2();
  
  h_DeltaR_leptonType_ljOR_EE = new TH2F("h_DeltaR_leptonType_ljOR_EE", "h_DeltaR_leptonType_ljOR_EE", 70, 0, 7, 5, -0.5, 4.5); h_DeltaR_leptonType_ljOR_EE->Sumw2();
  h_DeltaR_leptonType_ljOR_MM = new TH2F("h_DeltaR_leptonType_ljOR_MM", "h_DeltaR_leptonType_ljOR_MM", 70, 0, 7, 5, -0.5, 4.5); h_DeltaR_leptonType_ljOR_MM->Sumw2();
  h_DeltaR_leptonType_ljOR_mu_EM = new TH2F("h_DeltaR_leptonType_ljOR_mu_EM", "h_DeltaR_leptonType_ljOR_mu_EM", 70, 0, 7, 5, -0.5, 4.5); h_DeltaR_leptonType_ljOR_mu_EM->Sumw2();
  h_DeltaR_leptonType_ljOR_el_EM = new TH2F("h_DeltaR_leptonType_ljOR_el_EM", "h_DeltaR_leptonType_ljOR_el_EM", 70, 0, 7, 5, -0.5, 4.5); h_DeltaR_leptonType_ljOR_el_EM->Sumw2();  
  
  h_3rdleptonType_EE = new TH1F("h_3rdleptonType_EE", "h_3rdleptonType_EE", 5, -0.5, 4.5); h_3rdleptonType_EE->Sumw2();
  h_3rdleptonType_MM = new TH1F("h_3rdleptonType_MM", "h_3rdleptonType_MM", 5, -0.5, 4.5); h_3rdleptonType_MM->Sumw2();
  h_3rdleptonType_mu_EM = new TH1F("h_3rdleptonType_mu_EM", "h_3rdleptonType_mu_EM", 5, -0.5, 4.5); h_3rdleptonType_mu_EM->Sumw2();
  h_3rdleptonType_el_EM = new TH1F("h_3rdleptonType_el_EM", "h_3rdleptonType_el_EM", 5, -0.5, 4.5); h_3rdleptonType_el_EM->Sumw2(); 
  
  h_DeltaR_ptcone_ljOR_PR_EE = new TH2F("h_DeltaR_ptcone_ljOR_PR_EE", "h_DeltaR_ptcone_ljOR_PR_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_PR_EE->Sumw2();
  h_DeltaR_etcone_ljOR_PR_EE = new TH2F("h_DeltaR_etcone_ljOR_PR_EE", "h_DeltaR_etcone_ljOR_PR_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_etcone_ljOR_PR_EE->Sumw2();
  h_DeltaR_ptcone_ljOR_PR_MM = new TH2F("h_DeltaR_ptcone_ljOR_PR_MM", "h_DeltaR_ptcone_ljOR_PR_MM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_PR_MM->Sumw2();
  h_DeltaR_ptcone_ljOR_PR_mu_EM = new TH2F("h_DeltaR_ptcone_ljOR_PR_mu_EM", "h_DeltaR_ptcone_ljOR_PR_mu_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_PR_mu_EM->Sumw2();
  h_DeltaR_ptcone_ljOR_PR_el_EM = new TH2F("h_DeltaR_ptcone_ljOR_PR_el_EM", "h_DeltaR_ptcone_ljOR_PR_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_PR_el_EM->Sumw2();
  h_DeltaR_etcone_ljOR_PR_el_EM = new TH2F("h_DeltaR_etcone_ljOR_PR_el_EM", "h_DeltaR_etcone_ljOR_PR_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_etcone_ljOR_PR_el_EM->Sumw2();
  
  h_Ntpr_ljOR_HF_EE = new TH1F("h_Ntpr_ljOR_HF_EE", "h_Ntpr_ljOR_HF_EE", 10, -0.5, 9.5); h_Ntpr_ljOR_HF_EE->Sumw2();
  h_Ntpr_ljOR_LF_EE = new TH1F("h_Ntpr_ljOR_LF_EE", "h_Ntpr_ljOR_LF_EE", 10, -0.5, 9.5); h_Ntpr_ljOR_LF_EE->Sumw2();
  h_Ntpr_ljOR_HF_MM = new TH1F("h_Ntpr_ljOR_HF_MM", "h_Ntpr_ljOR_HF_MM", 10, -0.5, 9.5); h_Ntpr_ljOR_HF_MM->Sumw2();
  h_Ntpr_ljOR_LF_MM = new TH1F("h_Ntpr_ljOR_LF_MM", "h_Ntpr_ljOR_LF_MM", 10, -0.5, 9.5); h_Ntpr_ljOR_LF_MM->Sumw2();  
  h_Ntpr_ljOR_HF_mu_EM = new TH1F("h_Ntpr_ljOR_HF_mu_EM", "h_Ntpr_ljOR_HF_mu_EM", 10, -0.5, 9.5); h_Ntpr_ljOR_HF_mu_EM->Sumw2();
  h_Ntpr_ljOR_LF_mu_EM = new TH1F("h_Ntpr_ljOR_LF_mu_EM", "h_Ntpr_ljOR_LF_mu_EM", 10, -0.5, 9.5); h_Ntpr_ljOR_LF_mu_EM->Sumw2();
  h_Ntpr_ljOR_HF_el_EM = new TH1F("h_Ntpr_ljOR_HF_el_EM", "h_Ntpr_ljOR_HF_el_EM", 10, -0.5, 9.5); h_Ntpr_ljOR_HF_el_EM->Sumw2();
  h_Ntpr_ljOR_LF_el_EM = new TH1F("h_Ntpr_ljOR_LF_el_EM", "h_Ntpr_ljOR_LF_el_EM", 10, -0.5, 9.5); h_Ntpr_ljOR_LF_el_EM->Sumw2();



  
  h_DeltaR_min_lostLepton_truthParticle_HF_EE = new TH1F("h_DeltaR_min_lostLepton_truthParticle_HF_EE", "h_DeltaR_min_lostLepton_truthParticle_HF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_HF_EE->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_LF_EE = new TH1F("h_DeltaR_min_lostLepton_truthParticle_LF_EE", "h_DeltaR_min_lostLepton_truthParticle_LF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_LF_EE->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_HF_MM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_HF_MM", "h_DeltaR_min_lostLepton_truthParticle_HF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_HF_MM->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_LF_MM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_LF_MM", "h_DeltaR_min_lostLepton_truthParticle_LF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_LF_MM->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM", "h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM", "h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_HF_el_EM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_HF_el_EM", "h_DeltaR_min_lostLepton_truthParticle_HF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_HF_el_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthParticle_LF_el_EM = new TH1F("h_DeltaR_min_lostLepton_truthParticle_LF_el_EM", "h_DeltaR_min_lostLepton_truthParticle_LF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthParticle_LF_el_EM->Sumw2();
  
  h_DeltaR_min_lostLepton_truthJet_HF_EE = new TH1F("h_DeltaR_min_lostLepton_truthJet_HF_EE", "h_DeltaR_min_lostLepton_truthJet_HF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_HF_EE->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_LF_EE = new TH1F("h_DeltaR_min_lostLepton_truthJet_LF_EE", "h_DeltaR_min_lostLepton_truthJet_LF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_LF_EE->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_HF_MM = new TH1F("h_DeltaR_min_lostLepton_truthJet_HF_MM", "h_DeltaR_min_lostLepton_truthJet_HF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_HF_MM->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_LF_MM = new TH1F("h_DeltaR_min_lostLepton_truthJet_LF_MM", "h_DeltaR_min_lostLepton_truthJet_LF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_LF_MM->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_HF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_truthJet_HF_mu_EM", "h_DeltaR_min_lostLepton_truthJet_HF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_HF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_LF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_truthJet_LF_mu_EM", "h_DeltaR_min_lostLepton_truthJet_LF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_LF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_HF_el_EM = new TH1F("h_DeltaR_min_lostLepton_truthJet_HF_el_EM", "h_DeltaR_min_lostLepton_truthJet_HF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_HF_el_EM->Sumw2();
  h_DeltaR_min_lostLepton_truthJet_LF_el_EM = new TH1F("h_DeltaR_min_lostLepton_truthJet_LF_el_EM", "h_DeltaR_min_lostLepton_truthJet_LF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_truthJet_LF_el_EM->Sumw2();
  
  h_DeltaR_min_lostLepton_preJet_HF_EE = new TH1F("h_DeltaR_min_lostLepton_preJet_HF_EE", "h_DeltaR_min_lostLepton_preJet_HF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_HF_EE->Sumw2();
  h_DeltaR_min_lostLepton_preJet_LF_EE = new TH1F("h_DeltaR_min_lostLepton_preJet_LF_EE", "h_DeltaR_min_lostLepton_preJet_LF_EE", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_LF_EE->Sumw2();
  h_DeltaR_min_lostLepton_preJet_HF_MM = new TH1F("h_DeltaR_min_lostLepton_preJet_HF_MM", "h_DeltaR_min_lostLepton_preJet_HF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_HF_MM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_LF_MM = new TH1F("h_DeltaR_min_lostLepton_preJet_LF_MM", "h_DeltaR_min_lostLepton_preJet_LF_MM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_LF_MM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_HF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_preJet_HF_mu_EM", "h_DeltaR_min_lostLepton_preJet_HF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_HF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_LF_mu_EM = new TH1F("h_DeltaR_min_lostLepton_preJet_LF_mu_EM", "h_DeltaR_min_lostLepton_preJet_LF_mu_EM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_LF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_HF_el_EM = new TH1F("h_DeltaR_min_lostLepton_preJet_HF_el_EM", "h_DeltaR_min_lostLepton_preJet_HF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_HF_el_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_LF_el_EM = new TH1F("h_DeltaR_min_lostLepton_preJet_LF_el_EM", "h_DeltaR_min_lostLepton_preJet_LF_el_EM", 70, 0, 7); h_DeltaR_min_lostLepton_preJet_LF_el_EM->Sumw2();
  
  h_DeltaR_min_lostLepton_preJet_JVF_HF_EE = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_HF_EE", "h_DeltaR_min_lostLepton_preJet_JVF_HF_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_HF_EE->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_EE = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_LF_EE", "h_DeltaR_min_lostLepton_preJet_JVF_LF_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_LF_EE->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_MM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_HF_MM", "h_DeltaR_min_lostLepton_preJet_JVF_HF_MM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_HF_MM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_MM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_LF_MM", "h_DeltaR_min_lostLepton_preJet_JVF_LF_MM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_LF_MM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM", "h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM", "h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM", "h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM->Sumw2();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM = new TH2F("h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM", "h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM->Sumw2();

  
  
  h_DeltaR_ptcone_ljOR_HF_EE = new TH2F("h_DeltaR_ptcone_ljOR_HF_EE", "h_DeltaR_ptcone_ljOR_HF_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_HF_EE->Sumw2();
  h_DeltaR_etcone_ljOR_HF_EE = new TH2F("h_DeltaR_etcone_ljOR_HF_EE", "h_DeltaR_etcone_ljOR_HF_EE", 70, 0, 7, 100, 0, 1); h_DeltaR_etcone_ljOR_HF_EE->Sumw2();
  h_DeltaR_ptcone_ljOR_HF_MM = new TH2F("h_DeltaR_ptcone_ljOR_HF_MM", "h_DeltaR_ptcone_ljOR_HF_MM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_HF_MM->Sumw2();
  h_DeltaR_ptcone_ljOR_HF_mu_EM = new TH2F("h_DeltaR_ptcone_ljOR_HF_mu_EM", "h_DeltaR_ptcone_ljOR_HF_mu_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_HF_mu_EM->Sumw2();
  h_DeltaR_ptcone_ljOR_HF_el_EM = new TH2F("h_DeltaR_ptcone_ljOR_HF_el_EM", "h_DeltaR_ptcone_ljOR_HF_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_ptcone_ljOR_HF_el_EM->Sumw2();
  h_DeltaR_etcone_ljOR_HF_el_EM = new TH2F("h_DeltaR_etcone_ljOR_HF_el_EM", "h_DeltaR_etcone_ljOR_HF_el_EM", 70, 0, 7, 100, 0, 1); h_DeltaR_etcone_ljOR_HF_el_EM->Sumw2();
    
  h_DeltaR_em_EM = new TH1F("h_DeltaR_em_EM", "h_DeltaR_em_EM", 70, 0, 7); h_DeltaR_em_EM->Sumw2();

  h_failedSignalCriteria_EE = new TH2F("h_failedSignalCriteria_EE", "h_failedSignalCriteria_EE", 15, -0.5, 14.5, 130, 0, 129); h_failedSignalCriteria_EE->Sumw2();
  
  h_failedSignalCriteria_MM = new TH2F("h_failedSignalCriteria_MM", "h_failedSignalCriteria_MM", 15, -0.5, 14.5, 130, 0, 129); h_failedSignalCriteria_MM->Sumw2();
  
  h_failedSignalCriteria_mu_EM = new TH2F("h_failedSignalCriteria_mu_EM", "h_failedSignalCriteria_mu_EM", 15, -0.5, 14.5, 130, 0, 129); h_failedSignalCriteria_mu_EM->Sumw2();
  h_failedSignalCriteria_el_EM = new TH2F("h_failedSignalCriteria_el_EM", "h_failedSignalCriteria_el_EM", 15, -0.5, 14.5, 130, 0, 129); h_failedSignalCriteria_el_EM->Sumw2();

  h_etcone30lZcandImpact_EE_SRSS1 = new TH2F("h_etcone30lZcandImpact_EE_SRSS1", "h_etcone30lZcandImpact_EE_SRSS1", 100, 0, 1 ,130, 0, 129); h_etcone30lZcandImpact_EE_SRSS1->Sumw2();
  h_etcone30lZcandImpact_MM_SRSS1 = new TH2F("h_etcone30lZcandImpact_MM_SRSS1", "h_etcone30lZcandImpact_MM_SRSS1", 100, 0, 1 ,130, 0, 129); h_etcone30lZcandImpact_MM_SRSS1->Sumw2();
  h_etcone30lZcandImpact_mu_EM_SRSS1 = new TH2F("h_etcone30lZcandImpact_mu_EM_SRSS1", "h_etcone30lZcandImpact_mu_EM_SRSS1", 100, 0, 1 ,130, 0, 129); h_etcone30lZcandImpact_mu_EM_SRSS1->Sumw2();
  h_etcone30lZcandImpact_el_EM_SRSS1 = new TH2F("h_etcone30lZcandImpact_el_EM_SRSS1", "h_etcone30lZcandImpact_el_EM_SRSS1", 100, 0, 1 ,130, 0, 129); h_etcone30lZcandImpact_el_EM_SRSS1->Sumw2();
    
   //ZcandidateImpactParamter
  h_Nleptons_ZcandImpact_EE_SRSS1 = new TH2F("h_Nleptons_ZcandImpact_EE_SRSS1", "h_Nleptons_ZcandImpact_EE_SRSS1", 11, -0.5, 10.5, 130, 0, 129); h_Nleptons_ZcandImpact_EE_SRSS1->Sumw2();
  h_Nleptons_ZcandImpact_MM_SRSS1 = new TH2F("h_Nleptons_ZcandImpact_MM_SRSS1", "h_Nleptons_ZcandImpact_MM_SRSS1", 11, -0.5, 10.5, 130, 0, 129); h_Nleptons_ZcandImpact_MM_SRSS1->Sumw2();
  h_Nleptons_ZcandImpact_mu_EM_SRSS1 = new TH2F("h_Nleptons_ZcandImpact_mu_EM_SRSS1", "h_Nleptons_ZcandImpact_mu_EM_SRSS1", 11, -0.5, 10.5, 130, 0, 129); h_Nleptons_ZcandImpact_mu_EM_SRSS1->Sumw2();
  h_Nleptons_ZcandImpact_el_EM_SRSS1 = new TH2F("h_Nleptons_ZcandImpact_el_EM_SRSS1", "h_Nleptons_ZcandImpact_el_EM_SRSS1", 11, -0.5, 10.5, 130, 0, 129); h_Nleptons_ZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_mllZcandImpact_EE_SRSS1 = new TH2F("h_mllZcandImpact_EE_SRSS1", "h_mllZcandImpact_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mllZcandImpact_EE_SRSS1->Sumw2();
  h_mllZcandImpact_MM_SRSS1 = new TH2F("h_mllZcandImpact_MM_SRSS1", "h_mllZcandImpact_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mllZcandImpact_MM_SRSS1->Sumw2();
  h_mllZcandImpact_mu_EM_SRSS1 = new TH2F("h_mllZcandImpact_mu_EM_SRSS1", "h_mllZcandImpact_mu_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mllZcandImpact_mu_EM_SRSS1->Sumw2();
  h_mllZcandImpact_el_EM_SRSS1 = new TH2F("h_mllZcandImpact_el_EM_SRSS1", "h_mllZcandImpact_el_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mllZcandImpact_el_EM_SRSS1->Sumw2();
  
   
  h_mTllZcandImpact_EE_SRSS1 = new TH2F("h_mTllZcandImpact_EE_SRSS1", "h_mTllZcandImpact_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTllZcandImpact_EE_SRSS1->Sumw2();
  h_mTllZcandImpact_MM_SRSS1 = new TH2F("h_mTllZcandImpact_MM_SRSS1", "h_mTllZcandImpact_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTllZcandImpact_MM_SRSS1->Sumw2();
  h_mTllZcandImpact_mu_EM_SRSS1 = new TH2F("h_mTllZcandImpact_mu_EM_SRSS1", "h_mTllZcandImpact_mu_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTllZcandImpact_mu_EM_SRSS1->Sumw2();
  h_mTllZcandImpact_el_EM_SRSS1 = new TH2F("h_mTllZcandImpact_el_EM_SRSS1", "h_mTllZcandImpact_el_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTllZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_IClZcandImpact_EE_SRSS1 = new TH2F("h_IClZcandImpact_EE_SRSS1", "h_IClZcandImpact_EE_SRSS1", 2, -0.5, 1.5 ,130, 0, 129);  h_IClZcandImpact_EE_SRSS1->Sumw2();
  h_IClZcandImpact_MM_SRSS1 = new TH2F("h_IClZcandImpact_MM_SRSS1", "h_IClZcandImpact_MM_SRSS1", 2, -0.5, 1.5 ,130, 0, 129);  h_IClZcandImpact_MM_SRSS1->Sumw2();
  h_IClZcandImpact_mu_EM_SRSS1 = new TH2F("h_IClZcandImpact_mu_EM_SRSS1", "h_IClZcandImpact_mu_EM_SRSS1", 2, -0.5, 1.5 ,130, 0, 129);  h_IClZcandImpact_mu_EM_SRSS1->Sumw2();
  h_IClZcandImpact_el_EM_SRSS1 = new TH2F("h_IClZcandImpact_el_EM_SRSS1", "h_IClZcandImpact_el_EM_SRSS1", 2, -0.5, 1.5 ,130, 0, 129);  h_IClZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_pTlZcandImpact_EE_SRSS1 = new TH2F("h_pTlZcandImpact_EE_SRSS1", "h_pTlZcandImpact_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTlZcandImpact_EE_SRSS1->Sumw2();
  h_pTlZcandImpact_MM_SRSS1 = new TH2F("h_pTlZcandImpact_MM_SRSS1", "h_pTlZcandImpact_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTlZcandImpact_MM_SRSS1->Sumw2();
  h_pTlZcandImpact_mu_EM_SRSS1 = new TH2F("h_pTlZcandImpact_mu_EM_SRSS1", "h_pTlZcandImpact_mu_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTlZcandImpact_mu_EM_SRSS1->Sumw2();
  h_pTlZcandImpact_el_EM_SRSS1 = new TH2F("h_pTlZcandImpact_el_EM_SRSS1", "h_pTlZcandImpact_el_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTlZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_etalZcandImpact_EE_SRSS1 = new TH2F("h_etalZcandImpact_EE_SRSS1", "h_etalZcandImpact_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etalZcandImpact_EE_SRSS1->Sumw2();
  h_etalZcandImpact_MM_SRSS1 = new TH2F("h_etalZcandImpact_MM_SRSS1", "h_etalZcandImpact_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etalZcandImpact_MM_SRSS1->Sumw2();
  h_etalZcandImpact_mu_EM_SRSS1 = new TH2F("h_etalZcandImpact_mu_EM_SRSS1", "h_etalZcandImpact_mu_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etalZcandImpact_mu_EM_SRSS1->Sumw2();
  h_etalZcandImpact_el_EM_SRSS1 = new TH2F("h_etalZcandImpact_el_EM_SRSS1", "h_etalZcandImpact_el_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etalZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_ptcone30lZcandImpact_EE_SRSS1 = new TH2F("h_ptcone30lZcandImpact_EE_SRSS1", "h_ptcone30lZcandImpact_EE_SRSS1", 100, 0, 1 ,130, 0, 129);  h_ptcone30lZcandImpact_EE_SRSS1->Sumw2();
  h_ptcone30lZcandImpact_MM_SRSS1 = new TH2F("h_ptcone30lZcandImpact_MM_SRSS1", "h_ptcone30lZcandImpact_MM_SRSS1", 100, 0, 1 ,130, 0, 129);  h_ptcone30lZcandImpact_MM_SRSS1->Sumw2();
  h_ptcone30lZcandImpact_mu_EM_SRSS1 = new TH2F("h_ptcone30lZcandImpact_mu_EM_SRSS1", "h_ptcone30lZcandImpact_mu_EM_SRSS1", 100, 0, 1 ,130, 0, 129);  h_ptcone30lZcandImpact_mu_EM_SRSS1->Sumw2();
  h_ptcone30lZcandImpact_el_EM_SRSS1 = new TH2F("h_ptcone30lZcandImpact_el_EM_SRSS1", "h_ptcone30lZcandImpact_el_EM_SRSS1", 100, 0, 1 ,130, 0, 129);  h_ptcone30lZcandImpact_el_EM_SRSS1->Sumw2();
  
  h_d0SiglZcandImpact_EE_SRSS1 = new TH2F("h_d0SiglZcandImpact_EE_SRSS1", "h_d0SiglZcandImpact_EE_SRSS1", 100, 0, 10 ,130, 0, 129);  h_d0SiglZcandImpact_EE_SRSS1->Sumw2();
  h_d0SiglZcandImpact_MM_SRSS1 = new TH2F("h_d0SiglZcandImpact_MM_SRSS1", "h_d0SiglZcandImpact_MM_SRSS1", 100, 0, 10 ,130, 0, 129);  h_d0SiglZcandImpact_MM_SRSS1->Sumw2();
  h_d0SiglZcandImpact_mu_EM_SRSS1 = new TH2F("h_d0SiglZcandImpact_mu_EM_SRSS1", "h_d0SiglZcandImpact_mu_EM_SRSS1", 100, 0, 10 ,130, 0, 129);  h_d0SiglZcandImpact_mu_EM_SRSS1->Sumw2();
  h_d0SiglZcandImpact_el_EM_SRSS1 = new TH2F("h_d0SiglZcandImpact_el_EM_SRSS1", "h_d0SiglZcandImpact_el_EM_SRSS1", 100, 0, 10 ,130, 0, 129);  h_d0SiglZcandImpact_el_EM_SRSS1->Sumw2();
  
  
  h_z0SinThetalZcandImpact_EE_SRSS1 = new TH2F("h_z0SinThetalZcandImpact_EE_SRSS1", "h_z0SinThetalZcandImpact_EE_SRSS1", 100, 0, 5 ,130, 0, 129);  h_z0SinThetalZcandImpact_EE_SRSS1->Sumw2();
  h_z0SinThetalZcandImpact_MM_SRSS1 = new TH2F("h_z0SinThetalZcandImpact_MM_SRSS1", "h_z0SinThetalZcandImpact_MM_SRSS1", 100, 0, 5 ,130, 0, 129);  h_z0SinThetalZcandImpact_MM_SRSS1->Sumw2();
  h_z0SinThetalZcandImpact_mu_EM_SRSS1 = new TH2F("h_z0SinThetalZcandImpact_mu_EM_SRSS1", "h_z0SinThetalZcandImpact_mu_EM_SRSS1", 100, 0, 5 ,130, 0, 129);  h_z0SinThetalZcandImpact_mu_EM_SRSS1->Sumw2();
  h_z0SinThetalZcandImpact_el_EM_SRSS1 = new TH2F("h_z0SinThetalZcandImpact_el_EM_SRSS1", "h_z0SinThetalZcandImpact_el_EM_SRSS1", 100, 0, 5 ,130, 0, 129);  h_z0SinThetalZcandImpact_el_EM_SRSS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_Mljj_EE_SRSS1 = new TH2F("h_Mljj_EE_SRSS1", "h_Mljj_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mljj_EE_SRSS1->Sumw2();
  h_Mljj_MM_SRSS1 = new TH2F("h_Mljj_MM_SRSS1", "h_Mljj_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mljj_MM_SRSS1->Sumw2();
  h_Mljj_EM_SRSS1 = new TH2F("h_Mljj_EM_SRSS1", "h_Mljj_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mljj_EM_SRSS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_Mlj_EE_SRSS1 = new TH2F("h_Mlj_EE_SRSS1", "h_Mlj_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mlj_EE_SRSS1->Sumw2();
  h_Mlj_MM_SRSS1 = new TH2F("h_Mlj_MM_SRSS1", "h_Mlj_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mlj_MM_SRSS1->Sumw2();
  h_Mlj_EM_SRSS1 = new TH2F("h_Mlj_EM_SRSS1", "h_Mlj_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_Mlj_EM_SRSS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaRLeptons_EE_SRSS1 = new TH2F("h_DeltaRLeptons_EE_SRSS1", "h_DeltaRLeptons_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EE_SRSS1->Sumw2();
  h_DeltaRLeptons_EE_SRSS2 = new TH2F("h_DeltaRLeptons_EE_SRSS2", "h_DeltaRLeptons_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EE_SRSS2->Sumw2();
  h_DeltaRLeptons_MM_SRSS1 = new TH2F("h_DeltaRLeptons_MM_SRSS1", "h_DeltaRLeptons_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_MM_SRSS1->Sumw2();
  h_DeltaRLeptons_MM_SRSS2 = new TH2F("h_DeltaRLeptons_MM_SRSS2", "h_DeltaRLeptons_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_MM_SRSS2->Sumw2();
  h_DeltaRLeptons_MM_SRSS3 = new TH2F("h_DeltaRLeptons_MM_SRSS3", "h_DeltaRLeptons_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_MM_SRSS3->Sumw2();
  h_DeltaRLeptons_MM_SRSS4 = new TH2F("h_DeltaRLeptons_MM_SRSS4", "h_DeltaRLeptons_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_MM_SRSS4->Sumw2();
  h_DeltaRLeptons_EM_SRSS1 = new TH2F("h_DeltaRLeptons_EM_SRSS1", "h_DeltaRLeptons_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EM_SRSS1->Sumw2();  
  h_DeltaRLeptons_EM_SRSS2 = new TH2F("h_DeltaRLeptons_EM_SRSS2", "h_DeltaRLeptons_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EM_SRSS2->Sumw2();    
  h_DeltaRLeptons_EE_SROS1 = new TH2F("h_DeltaRLeptons_EE_SROS1", "h_DeltaRLeptons_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EE_SROS1->Sumw2();
  h_DeltaRLeptons_MM_SROS1 = new TH2F("h_DeltaRLeptons_MM_SROS1", "h_DeltaRLeptons_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_MM_SROS1->Sumw2();
  h_DeltaRLeptons_EM_SROS1 = new TH2F("h_DeltaRLeptons_EM_SROS1", "h_DeltaRLeptons_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRLeptons_EM_SROS1->Sumw2();
  
  
  /*--------------------------------------------------------------------------------*/ 
  h_pTl0_EE_SRSS1 = new TH2F("h_pTl0_EE_SRSS1", "h_pTl0_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_EE_SRSS1->Sumw2();
  h_pTl0_EE_SRSS2 = new TH2F("h_pTl0_EE_SRSS2", "h_pTl0_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl0_EE_SRSS2->Sumw2();
  h_pTl0_MM_SRSS1 = new TH2F("h_pTl0_MM_SRSS1", "h_pTl0_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_MM_SRSS1->Sumw2();
  h_pTl0_MM_SRSS2 = new TH2F("h_pTl0_MM_SRSS2", "h_pTl0_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl0_MM_SRSS2->Sumw2();
  h_pTl0_MM_SRSS3 = new TH2F("h_pTl0_MM_SRSS3", "h_pTl0_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTl0_MM_SRSS3->Sumw2();
  h_pTl0_MM_SRSS4 = new TH2F("h_pTl0_MM_SRSS4", "h_pTl0_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTl0_MM_SRSS4->Sumw2();
  h_pTl0_EM_SRSS1 = new TH2F("h_pTl0_EM_SRSS1", "h_pTl0_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_EM_SRSS1->Sumw2();
  h_pTl0_EM_SRSS2 = new TH2F("h_pTl0_EM_SRSS2", "h_pTl0_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl0_EM_SRSS2->Sumw2();
  h_pTl0_EE_SROS1 = new TH2F("h_pTl0_EE_SROS1", "h_pTl0_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_EE_SROS1->Sumw2();
  h_pTl0_MM_SROS1 = new TH2F("h_pTl0_MM_SROS1", "h_pTl0_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_MM_SROS1->Sumw2();
  h_pTl0_EM_SROS1 = new TH2F("h_pTl0_EM_SROS1", "h_pTl0_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_EM_SROS1->Sumw2();
  
  h_pTl0_raw_EE_SRSS1 = new TH2F("h_pTl0_raw_EE_SRSS1", "h_pTl0_raw_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_raw_EE_SRSS1->Sumw2();
  h_pTl0_raw_MM_SRSS1 = new TH2F("h_pTl0_raw_MM_SRSS1", "h_pTl0_raw_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_raw_MM_SRSS1->Sumw2();
  h_pTl0_raw_EM_SRSS1 = new TH2F("h_pTl0_raw_EM_SRSS1", "h_pTl0_raw_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl0_raw_EM_SRSS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_pTl1_EE_SRSS1 = new TH2F("h_pTl1_EE_SRSS1", "h_pTl1_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_EE_SRSS1->Sumw2();
  h_pTl1_EE_SRSS2 = new TH2F("h_pTl1_EE_SRSS2", "h_pTl1_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl1_EE_SRSS2->Sumw2();
  h_pTl1_MM_SRSS1 = new TH2F("h_pTl1_MM_SRSS1", "h_pTl1_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_MM_SRSS1->Sumw2();  
  h_pTl1_MM_SRSS2 = new TH2F("h_pTl1_MM_SRSS2", "h_pTl1_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl1_MM_SRSS2->Sumw2();
  h_pTl1_MM_SRSS3 = new TH2F("h_pTl1_MM_SRSS3", "h_pTl1_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTl1_MM_SRSS3->Sumw2();
  h_pTl1_MM_SRSS4 = new TH2F("h_pTl1_MM_SRSS4", "h_pTl1_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTl1_MM_SRSS4->Sumw2();
  h_pTl1_EM_SRSS1 = new TH2F("h_pTl1_EM_SRSS1", "h_pTl1_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_EM_SRSS1->Sumw2();
  h_pTl1_EM_SRSS2 = new TH2F("h_pTl1_EM_SRSS2", "h_pTl1_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTl1_EM_SRSS2->Sumw2();
  h_pTl1_EE_SROS1 = new TH2F("h_pTl1_EE_SROS1", "h_pTl1_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_EE_SROS1->Sumw2();
  h_pTl1_MM_SROS1 = new TH2F("h_pTl1_MM_SROS1", "h_pTl1_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_MM_SROS1->Sumw2();
  h_pTl1_EM_SROS1 = new TH2F("h_pTl1_EM_SROS1", "h_pTl1_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTl1_EM_SROS1->Sumw2();
  
    /*--------------------------------------------------------------------------------*/ 
  h_pTj0_EE_SRSS1 = new TH2F("h_pTj0_EE_SRSS1", "h_pTj0_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_EE_SRSS1->Sumw2();
  h_pTj0_EE_SRSS2 = new TH2F("h_pTj0_EE_SRSS2", "h_pTj0_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj0_EE_SRSS2->Sumw2();
  h_pTj0_MM_SRSS1 = new TH2F("h_pTj0_MM_SRSS1", "h_pTj0_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_MM_SRSS1->Sumw2();
  h_pTj0_MM_SRSS2 = new TH2F("h_pTj0_MM_SRSS2", "h_pTj0_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj0_MM_SRSS2->Sumw2();
  h_pTj0_MM_SRSS3 = new TH2F("h_pTj0_MM_SRSS3", "h_pTj0_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTj0_MM_SRSS3->Sumw2();
  h_pTj0_MM_SRSS4 = new TH2F("h_pTj0_MM_SRSS4", "h_pTj0_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTj0_MM_SRSS4->Sumw2();
  h_pTj0_EM_SRSS1 = new TH2F("h_pTj0_EM_SRSS1", "h_pTj0_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_EM_SRSS1->Sumw2();
  h_pTj0_EM_SRSS2 = new TH2F("h_pTj0_EM_SRSS2", "h_pTj0_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj0_EM_SRSS2->Sumw2();
  h_pTj0_EE_SROS1 = new TH2F("h_pTj0_EE_SROS1", "h_pTj0_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_EE_SROS1->Sumw2();
  h_pTj0_MM_SROS1 = new TH2F("h_pTj0_MM_SROS1", "h_pTj0_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_MM_SROS1->Sumw2();
  h_pTj0_EM_SROS1 = new TH2F("h_pTj0_EM_SROS1", "h_pTj0_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj0_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_pTj1_EE_SRSS1 = new TH2F("h_pTj1_EE_SRSS1", "h_pTj1_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_EE_SRSS1->Sumw2();
  h_pTj1_EE_SRSS2 = new TH2F("h_pTj1_EE_SRSS2", "h_pTj1_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj1_EE_SRSS2->Sumw2();
  h_pTj1_MM_SRSS1 = new TH2F("h_pTj1_MM_SRSS1", "h_pTj1_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_MM_SRSS1->Sumw2();  
  h_pTj1_MM_SRSS2 = new TH2F("h_pTj1_MM_SRSS2", "h_pTj1_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj1_MM_SRSS2->Sumw2();
  h_pTj1_MM_SRSS3 = new TH2F("h_pTj1_MM_SRSS3", "h_pTj1_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTj1_MM_SRSS3->Sumw2();
  h_pTj1_MM_SRSS4 = new TH2F("h_pTj1_MM_SRSS4", "h_pTj1_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTj1_MM_SRSS4->Sumw2();
  h_pTj1_EM_SRSS1 = new TH2F("h_pTj1_EM_SRSS1", "h_pTj1_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_EM_SRSS1->Sumw2();
  h_pTj1_EM_SRSS2 = new TH2F("h_pTj1_EM_SRSS2", "h_pTj1_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTj1_EM_SRSS2->Sumw2();
  h_pTj1_EE_SROS1 = new TH2F("h_pTj1_EE_SROS1", "h_pTj1_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_EE_SROS1->Sumw2();
  h_pTj1_MM_SROS1 = new TH2F("h_pTj1_MM_SROS1", "h_pTj1_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_MM_SROS1->Sumw2();
  h_pTj1_EM_SROS1 = new TH2F("h_pTj1_EM_SROS1", "h_pTj1_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTj1_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mll_EE_SRSS1 = new TH2F("h_mll_EE_SRSS1", "h_mll_EE_SRSS1", 100, 0, 500 ,130, 0, 129); h_mll_EE_SRSS1->Sumw2();
  h_mll_EE_SRSS2 = new TH2F("h_mll_EE_SRSS2", "h_mll_EE_SRSS2", 100, 0, 500 ,130, 0, 129); h_mll_EE_SRSS2->Sumw2();
  h_mll_MM_SRSS1 = new TH2F("h_mll_MM_SRSS1", "h_mll_MM_SRSS1", 100, 0, 500 ,130, 0, 129); h_mll_MM_SRSS1->Sumw2();  
  h_mll_MM_SRSS2 = new TH2F("h_mll_MM_SRSS2", "h_mll_MM_SRSS2", 100, 0, 500 ,130, 0, 129); h_mll_MM_SRSS2->Sumw2();
  h_mll_MM_SRSS3 = new TH2F("h_mll_MM_SRSS3", "h_mll_MM_SRSS3", 100, 0, 500 ,130, 0, 129); h_mll_MM_SRSS3->Sumw2();
  h_mll_MM_SRSS4 = new TH2F("h_mll_MM_SRSS4", "h_mll_MM_SRSS4", 100, 0, 500 ,130, 0, 129); h_mll_MM_SRSS4->Sumw2();
  h_mll_EM_SRSS1 = new TH2F("h_mll_EM_SRSS1", "h_mll_EM_SRSS1", 100, 0, 500 ,130, 0, 129); h_mll_EM_SRSS1->Sumw2();
  h_mll_EM_SRSS2 = new TH2F("h_mll_EM_SRSS2", "h_mll_EM_SRSS2", 100, 0, 500 ,130, 0, 129); h_mll_EM_SRSS2->Sumw2();
  h_mll_EE_SROS1 = new TH2F("h_mll_EE_SROS1", "h_mll_EE_SROS1", 100, 0, 500 ,130, 0, 129); h_mll_EE_SROS1->Sumw2();
  h_mll_MM_SROS1 = new TH2F("h_mll_MM_SROS1", "h_mll_MM_SROS1", 100, 0, 500 ,130, 0, 129); h_mll_MM_SROS1->Sumw2();
  h_mll_EM_SROS1 = new TH2F("h_mll_EM_SROS1", "h_mll_EM_SROS1", 100, 0, 500 ,130, 0, 129); h_mll_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_METrel_EE_SRSS1 = new TH2F("h_METrel_EE_SRSS1", "h_METrel_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_METrel_EE_SRSS1->Sumw2();
  h_METrel_EE_SRSS2 = new TH2F("h_METrel_EE_SRSS2", "h_METrel_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_METrel_EE_SRSS2->Sumw2();
  h_METrel_MM_SRSS1 = new TH2F("h_METrel_MM_SRSS1", "h_METrel_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_METrel_MM_SRSS1->Sumw2();  
  h_METrel_MM_SRSS2 = new TH2F("h_METrel_MM_SRSS2", "h_METrel_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_METrel_MM_SRSS2->Sumw2();  
  h_METrel_MM_SRSS3 = new TH2F("h_METrel_MM_SRSS3", "h_METrel_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_METrel_MM_SRSS3->Sumw2();
  h_METrel_MM_SRSS4 = new TH2F("h_METrel_MM_SRSS4", "h_METrel_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_METrel_MM_SRSS4->Sumw2();
  h_METrel_EM_SRSS1 = new TH2F("h_METrel_EM_SRSS1", "h_METrel_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_METrel_EM_SRSS1->Sumw2();
  h_METrel_EM_SRSS2 = new TH2F("h_METrel_EM_SRSS2", "h_METrel_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_METrel_EM_SRSS2->Sumw2();
  h_METrel_EE_SROS1 = new TH2F("h_METrel_EE_SROS1", "h_METrel_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_METrel_EE_SROS1->Sumw2();
  h_METrel_MM_SROS1 = new TH2F("h_METrel_MM_SROS1", "h_METrel_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_METrel_MM_SROS1->Sumw2();
  h_METrel_EM_SROS1 = new TH2F("h_METrel_EM_SROS1", "h_METrel_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_METrel_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_MET_EE_SRSS1 = new TH2F("h_MET_EE_SRSS1", "h_MET_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_MET_EE_SRSS1->Sumw2();
  h_MET_EE_SRSS2 = new TH2F("h_MET_EE_SRSS2", "h_MET_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_MET_EE_SRSS2->Sumw2();
  h_MET_MM_SRSS1 = new TH2F("h_MET_MM_SRSS1", "h_MET_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_MET_MM_SRSS1->Sumw2();  
  h_MET_MM_SRSS2 = new TH2F("h_MET_MM_SRSS2", "h_MET_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_MET_MM_SRSS2->Sumw2();  
  h_MET_MM_SRSS3 = new TH2F("h_MET_MM_SRSS3", "h_MET_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_MET_MM_SRSS3->Sumw2();
  h_MET_MM_SRSS4 = new TH2F("h_MET_MM_SRSS4", "h_MET_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_MET_MM_SRSS4->Sumw2();
  h_MET_EM_SRSS1 = new TH2F("h_MET_EM_SRSS1", "h_MET_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_MET_EM_SRSS1->Sumw2();
  h_MET_EM_SRSS2 = new TH2F("h_MET_EM_SRSS2", "h_MET_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_MET_EM_SRSS2->Sumw2();
  h_MET_EE_SROS1 = new TH2F("h_MET_EE_SROS1", "h_MET_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_MET_EE_SROS1->Sumw2();
  h_MET_MM_SROS1 = new TH2F("h_MET_MM_SROS1", "h_MET_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_MET_MM_SROS1->Sumw2();
  h_MET_EM_SROS1 = new TH2F("h_MET_EM_SROS1", "h_MET_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_MET_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_HT_EE_SRSS1 = new TH2F("h_HT_EE_SRSS1", "h_HT_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_HT_EE_SRSS1->Sumw2();
  h_HT_EE_SRSS2 = new TH2F("h_HT_EE_SRSS2", "h_HT_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_HT_EE_SRSS2->Sumw2();
  h_HT_MM_SRSS1 = new TH2F("h_HT_MM_SRSS1", "h_HT_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_HT_MM_SRSS1->Sumw2();  
  h_HT_MM_SRSS2 = new TH2F("h_HT_MM_SRSS2", "h_HT_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_HT_MM_SRSS2->Sumw2();
  h_HT_MM_SRSS3 = new TH2F("h_HT_MM_SRSS3", "h_HT_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_HT_MM_SRSS3->Sumw2();
  h_HT_MM_SRSS4 = new TH2F("h_HT_MM_SRSS4", "h_HT_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_HT_MM_SRSS4->Sumw2();
  h_HT_EM_SRSS1 = new TH2F("h_HT_EM_SRSS1", "h_HT_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_HT_EM_SRSS1->Sumw2();
  h_HT_EM_SRSS2 = new TH2F("h_HT_EM_SRSS2", "h_HT_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_HT_EM_SRSS2->Sumw2();
  h_HT_EE_SROS1 = new TH2F("h_HT_EE_SROS1", "h_HT_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_HT_EE_SROS1->Sumw2();
  h_HT_MM_SROS1 = new TH2F("h_HT_MM_SROS1", "h_HT_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_HT_MM_SROS1->Sumw2();
  h_HT_EM_SROS1 = new TH2F("h_HT_EM_SROS1", "h_HT_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_HT_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mWWt_EE_SRSS1 = new TH2F("h_mWWt_EE_SRSS1", "h_mWWt_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_EE_SRSS1->Sumw2();
  h_mWWt_EE_SRSS2 = new TH2F("h_mWWt_EE_SRSS2", "h_mWWt_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mWWt_EE_SRSS2->Sumw2();
  h_mWWt_MM_SRSS1 = new TH2F("h_mWWt_MM_SRSS1", "h_mWWt_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_MM_SRSS1->Sumw2();  
  h_mWWt_MM_SRSS2 = new TH2F("h_mWWt_MM_SRSS2", "h_mWWt_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mWWt_MM_SRSS2->Sumw2();
  h_mWWt_MM_SRSS3 = new TH2F("h_mWWt_MM_SRSS3", "h_mWWt_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mWWt_MM_SRSS3->Sumw2();
  h_mWWt_MM_SRSS4 = new TH2F("h_mWWt_MM_SRSS4", "h_mWWt_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mWWt_MM_SRSS4->Sumw2();
  h_mWWt_EM_SRSS1 = new TH2F("h_mWWt_EM_SRSS1", "h_mWWt_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_EM_SRSS1->Sumw2();
  h_mWWt_EM_SRSS2 = new TH2F("h_mWWt_EM_SRSS2", "h_mWWt_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mWWt_EM_SRSS2->Sumw2();
  h_mWWt_EE_SROS1 = new TH2F("h_mWWt_EE_SROS1", "h_mWWt_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_EE_SROS1->Sumw2();
  h_mWWt_MM_SROS1 = new TH2F("h_mWWt_MM_SROS1", "h_mWWt_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_MM_SROS1->Sumw2();
  h_mWWt_EM_SROS1 = new TH2F("h_mWWt_EM_SROS1", "h_mWWt_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mWWt_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mTlmin_EE_SRSS1 = new TH2F("h_mTlmin_EE_SRSS1", "h_mTlmin_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EE_SRSS1->Sumw2();
  h_mTlmin_EE_SRSS2 = new TH2F("h_mTlmin_EE_SRSS2", "h_mTlmin_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EE_SRSS2->Sumw2();
  h_mTlmin_MM_SRSS1 = new TH2F("h_mTlmin_MM_SRSS1", "h_mTlmin_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_MM_SRSS1->Sumw2();  
  h_mTlmin_MM_SRSS2 = new TH2F("h_mTlmin_MM_SRSS2", "h_mTlmin_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmin_MM_SRSS2->Sumw2();
  h_mTlmin_MM_SRSS3 = new TH2F("h_mTlmin_MM_SRSS3", "h_mTlmin_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mTlmin_MM_SRSS3->Sumw2();
  h_mTlmin_MM_SRSS4 = new TH2F("h_mTlmin_MM_SRSS4", "h_mTlmin_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mTlmin_MM_SRSS4->Sumw2();
  h_mTlmin_EM_SRSS1 = new TH2F("h_mTlmin_EM_SRSS1", "h_mTlmin_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EM_SRSS1->Sumw2();
  h_mTlmin_EM_SRSS2 = new TH2F("h_mTlmin_EM_SRSS2", "h_mTlmin_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EM_SRSS2->Sumw2();
  h_mTlmin_EE_SROS1 = new TH2F("h_mTlmin_EE_SROS1", "h_mTlmin_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EE_SROS1->Sumw2();
  h_mTlmin_MM_SROS1 = new TH2F("h_mTlmin_MM_SROS1", "h_mTlmin_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_MM_SROS1->Sumw2();
  h_mTlmin_EM_SROS1 = new TH2F("h_mTlmin_EM_SROS1", "h_mTlmin_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmin_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mTlmax_EE_SRSS1 = new TH2F("h_mTlmax_EE_SRSS1", "h_mTlmax_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EE_SRSS1->Sumw2();
  h_mTlmax_EE_SRSS2 = new TH2F("h_mTlmax_EE_SRSS2", "h_mTlmax_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EE_SRSS2->Sumw2();
  h_mTlmax_MM_SRSS1 = new TH2F("h_mTlmax_MM_SRSS1", "h_mTlmax_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_MM_SRSS1->Sumw2();  
  h_mTlmax_MM_SRSS2 = new TH2F("h_mTlmax_MM_SRSS2", "h_mTlmax_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmax_MM_SRSS2->Sumw2();
  h_mTlmax_MM_SRSS3 = new TH2F("h_mTlmax_MM_SRSS3", "h_mTlmax_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mTlmax_MM_SRSS3->Sumw2();
  h_mTlmax_MM_SRSS4 = new TH2F("h_mTlmax_MM_SRSS4", "h_mTlmax_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mTlmax_MM_SRSS4->Sumw2();
  h_mTlmax_EM_SRSS1 = new TH2F("h_mTlmax_EM_SRSS1", "h_mTlmax_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EM_SRSS1->Sumw2();
  h_mTlmax_EM_SRSS2 = new TH2F("h_mTlmax_EM_SRSS2", "h_mTlmax_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EM_SRSS2->Sumw2();
  h_mTlmax_EE_SROS1 = new TH2F("h_mTlmax_EE_SROS1", "h_mTlmax_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EE_SROS1->Sumw2();
  h_mTlmax_MM_SROS1 = new TH2F("h_mTlmax_MM_SROS1", "h_mTlmax_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_MM_SROS1->Sumw2();
  h_mTlmax_EM_SROS1 = new TH2F("h_mTlmax_EM_SROS1", "h_mTlmax_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTlmax_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_meff_EE_SRSS1 = new TH2F("h_meff_EE_SRSS1", "h_meff_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_meff_EE_SRSS1->Sumw2();
  h_meff_EE_SRSS2 = new TH2F("h_meff_EE_SRSS2", "h_meff_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_meff_EE_SRSS2->Sumw2();
  h_meff_MM_SRSS1 = new TH2F("h_meff_MM_SRSS1", "h_meff_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_meff_MM_SRSS1->Sumw2();
  h_meff_MM_SRSS2 = new TH2F("h_meff_MM_SRSS2", "h_meff_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_meff_MM_SRSS2->Sumw2();
  h_meff_MM_SRSS3 = new TH2F("h_meff_MM_SRSS3", "h_meff_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_meff_MM_SRSS3->Sumw2();
  h_meff_MM_SRSS4 = new TH2F("h_meff_MM_SRSS4", "h_meff_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_meff_MM_SRSS4->Sumw2();
  h_meff_EM_SRSS1 = new TH2F("h_meff_EM_SRSS1", "h_meff_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_meff_EM_SRSS1->Sumw2();
  h_meff_EM_SRSS2 = new TH2F("h_meff_EM_SRSS2", "h_meff_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_meff_EM_SRSS2->Sumw2();
  h_meff_EE_SROS1 = new TH2F("h_meff_EE_SROS1", "h_meff_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_meff_EE_SROS1->Sumw2();
  h_meff_MM_SROS1 = new TH2F("h_meff_MM_SROS1", "h_meff_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_meff_MM_SROS1->Sumw2();
  h_meff_EM_SROS1 = new TH2F("h_meff_EM_SROS1", "h_meff_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_meff_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mT2_EE_SRSS1 = new TH2F("h_mT2_EE_SRSS1", "h_mT2_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2_EE_SRSS1->Sumw2();
  h_mT2_EE_SRSS2 = new TH2F("h_mT2_EE_SRSS2", "h_mT2_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2_EE_SRSS2->Sumw2();
  h_mT2_MM_SRSS1 = new TH2F("h_mT2_MM_SRSS1", "h_mT2_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2_MM_SRSS1->Sumw2();
  h_mT2_MM_SRSS2 = new TH2F("h_mT2_MM_SRSS2", "h_mT2_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2_MM_SRSS2->Sumw2();  
  h_mT2_MM_SRSS3 = new TH2F("h_mT2_MM_SRSS3", "h_mT2_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mT2_MM_SRSS3->Sumw2();
  h_mT2_MM_SRSS4 = new TH2F("h_mT2_MM_SRSS4", "h_mT2_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mT2_MM_SRSS4->Sumw2();
  h_mT2_EM_SRSS1 = new TH2F("h_mT2_EM_SRSS1", "h_mT2_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2_EM_SRSS1->Sumw2();
  h_mT2_EM_SRSS2 = new TH2F("h_mT2_EM_SRSS2", "h_mT2_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2_EM_SRSS2->Sumw2();
  h_mT2_EE_SROS1 = new TH2F("h_mT2_EE_SROS1", "h_mT2_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2_EE_SROS1->Sumw2();
  h_mT2_MM_SROS1 = new TH2F("h_mT2_MM_SROS1", "h_mT2_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2_MM_SROS1->Sumw2();
  h_mT2_EM_SROS1 = new TH2F("h_mT2_EM_SROS1", "h_mT2_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2_EM_SROS1->Sumw2();
/*--------------------------------------------------------------------------------*/ 
  h_mT2J_EE_SRSS1 = new TH2F("h_mT2J_EE_SRSS1", "h_mT2J_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_EE_SRSS1->Sumw2();
  h_mT2J_EE_SRSS2 = new TH2F("h_mT2J_EE_SRSS2", "h_mT2J_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2J_EE_SRSS2->Sumw2();
  h_mT2J_MM_SRSS1 = new TH2F("h_mT2J_MM_SRSS1", "h_mT2J_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_MM_SRSS1->Sumw2();
  h_mT2J_MM_SRSS2 = new TH2F("h_mT2J_MM_SRSS2", "h_mT2J_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2J_MM_SRSS2->Sumw2();  
  h_mT2J_MM_SRSS3 = new TH2F("h_mT2J_MM_SRSS3", "h_mT2J_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mT2J_MM_SRSS3->Sumw2();
  h_mT2J_MM_SRSS4 = new TH2F("h_mT2J_MM_SRSS4", "h_mT2J_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mT2J_MM_SRSS4->Sumw2();
  h_mT2J_EM_SRSS1 = new TH2F("h_mT2J_EM_SRSS1", "h_mT2J_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_EM_SRSS1->Sumw2();
  h_mT2J_EM_SRSS2 = new TH2F("h_mT2J_EM_SRSS2", "h_mT2J_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mT2J_EM_SRSS2->Sumw2();
  h_mT2J_EE_SROS1 = new TH2F("h_mT2J_EE_SROS1", "h_mT2J_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_EE_SROS1->Sumw2();
  h_mT2J_MM_SROS1 = new TH2F("h_mT2J_MM_SROS1", "h_mT2J_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_MM_SROS1->Sumw2();
  h_mT2J_EM_SROS1 = new TH2F("h_mT2J_EM_SROS1", "h_mT2J_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mT2J_EM_SROS1->Sumw2();  
  /*--------------------------------------------------------------------------------*/ 
  h_mjj_EE_SRSS1 = new TH2F("h_mjj_EE_SRSS1", "h_mjj_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mjj_EE_SRSS1->Sumw2();
  h_mjj_EE_SRSS2 = new TH2F("h_mjj_EE_SRSS2", "h_mjj_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mjj_EE_SRSS2->Sumw2();
  h_mjj_MM_SRSS1 = new TH2F("h_mjj_MM_SRSS1", "h_mjj_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mjj_MM_SRSS1->Sumw2();  
  h_mjj_MM_SRSS2 = new TH2F("h_mjj_MM_SRSS2", "h_mjj_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mjj_MM_SRSS2->Sumw2();
  h_mjj_MM_SRSS3 = new TH2F("h_mjj_MM_SRSS3", "h_mjj_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mjj_MM_SRSS3->Sumw2();
  h_mjj_MM_SRSS4 = new TH2F("h_mjj_MM_SRSS4", "h_mjj_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mjj_MM_SRSS4->Sumw2();
  h_mjj_EM_SRSS1 = new TH2F("h_mjj_EM_SRSS1", "h_mjj_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mjj_EM_SRSS1->Sumw2();
  h_mjj_EM_SRSS2 = new TH2F("h_mjj_EM_SRSS2", "h_mjj_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mjj_EM_SRSS2->Sumw2();
  h_mjj_EE_SROS1 = new TH2F("h_mjj_EE_SROS1", "h_mjj_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mjj_EE_SROS1->Sumw2();
  h_mjj_MM_SROS1 = new TH2F("h_mjj_MM_SROS1", "h_mjj_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mjj_MM_SROS1->Sumw2();
  h_mjj_EM_SROS1 = new TH2F("h_mjj_EM_SROS1", "h_mjj_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mjj_EM_SROS1->Sumw2();
  
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETll_EE_SRSS1 = new TH2F("h_DeltaPhiMETll_EE_SRSS1", "h_DeltaPhiMETll_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EE_SRSS1->Sumw2();
  h_DeltaPhiMETll_EE_SRSS2 = new TH2F("h_DeltaPhiMETll_EE_SRSS2", "h_DeltaPhiMETll_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EE_SRSS2->Sumw2();
  h_DeltaPhiMETll_MM_SRSS1 = new TH2F("h_DeltaPhiMETll_MM_SRSS1", "h_DeltaPhiMETll_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETll_MM_SRSS2 = new TH2F("h_DeltaPhiMETll_MM_SRSS2", "h_DeltaPhiMETll_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_MM_SRSS2->Sumw2();
  h_DeltaPhiMETll_MM_SRSS3 = new TH2F("h_DeltaPhiMETll_MM_SRSS3", "h_DeltaPhiMETll_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_MM_SRSS3->Sumw2();
  h_DeltaPhiMETll_MM_SRSS4 = new TH2F("h_DeltaPhiMETll_MM_SRSS4", "h_DeltaPhiMETll_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_MM_SRSS4->Sumw2();
  h_DeltaPhiMETll_EM_SRSS1 = new TH2F("h_DeltaPhiMETll_EM_SRSS1", "h_DeltaPhiMETll_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EM_SRSS1->Sumw2();
  h_DeltaPhiMETll_EM_SRSS2 = new TH2F("h_DeltaPhiMETll_EM_SRSS2", "h_DeltaPhiMETll_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EM_SRSS2->Sumw2();
  h_DeltaPhiMETll_EE_SROS1 = new TH2F("h_DeltaPhiMETll_EE_SROS1", "h_DeltaPhiMETll_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EE_SROS1->Sumw2();
  h_DeltaPhiMETll_MM_SROS1 = new TH2F("h_DeltaPhiMETll_MM_SROS1", "h_DeltaPhiMETll_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_MM_SROS1->Sumw2();
  h_DeltaPhiMETll_EM_SROS1 = new TH2F("h_DeltaPhiMETll_EM_SROS1", "h_DeltaPhiMETll_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETll_EM_SROS1->Sumw2();
  
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhill_EE_SRSS1 = new TH2F("h_DeltaPhill_EE_SRSS1", "h_DeltaPhill_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EE_SRSS1->Sumw2();
  h_DeltaPhill_EE_SRSS2 = new TH2F("h_DeltaPhill_EE_SRSS2", "h_DeltaPhill_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EE_SRSS2->Sumw2();
  h_DeltaPhill_MM_SRSS1 = new TH2F("h_DeltaPhill_MM_SRSS1", "h_DeltaPhill_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_MM_SRSS1->Sumw2();  
  h_DeltaPhill_MM_SRSS2 = new TH2F("h_DeltaPhill_MM_SRSS2", "h_DeltaPhill_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_MM_SRSS2->Sumw2();
  h_DeltaPhill_MM_SRSS3 = new TH2F("h_DeltaPhill_MM_SRSS3", "h_DeltaPhill_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_MM_SRSS3->Sumw2();
  h_DeltaPhill_MM_SRSS4 = new TH2F("h_DeltaPhill_MM_SRSS4", "h_DeltaPhill_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_MM_SRSS4->Sumw2();
  h_DeltaPhill_EM_SRSS1 = new TH2F("h_DeltaPhill_EM_SRSS1", "h_DeltaPhill_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EM_SRSS1->Sumw2();
  h_DeltaPhill_EM_SRSS2 = new TH2F("h_DeltaPhill_EM_SRSS2", "h_DeltaPhill_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EM_SRSS2->Sumw2();
  h_DeltaPhill_EE_SROS1 = new TH2F("h_DeltaPhill_EE_SROS1", "h_DeltaPhill_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EE_SROS1->Sumw2();
  h_DeltaPhill_MM_SROS1 = new TH2F("h_DeltaPhill_MM_SROS1", "h_DeltaPhill_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_MM_SROS1->Sumw2();
  h_DeltaPhill_EM_SROS1 = new TH2F("h_DeltaPhill_EM_SROS1", "h_DeltaPhill_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhill_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_NBJets_EE_SRSS1 = new TH2F("h_NBJets_EE_SRSS1", "h_NBJets_EE_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EE_SRSS1->Sumw2();
  h_NBJets_EE_SRSS2 = new TH2F("h_NBJets_EE_SRSS2", "h_NBJets_EE_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EE_SRSS2->Sumw2();
  h_NBJets_MM_SRSS1 = new TH2F("h_NBJets_MM_SRSS1", "h_NBJets_MM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_MM_SRSS1->Sumw2();  
  h_NBJets_MM_SRSS2 = new TH2F("h_NBJets_MM_SRSS2", "h_NBJets_MM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_MM_SRSS2->Sumw2();
  h_NBJets_MM_SRSS3 = new TH2F("h_NBJets_MM_SRSS3", "h_NBJets_MM_SRSS3", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_MM_SRSS3->Sumw2();
  h_NBJets_MM_SRSS4 = new TH2F("h_NBJets_MM_SRSS4", "h_NBJets_MM_SRSS4", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_MM_SRSS4->Sumw2();
  h_NBJets_EM_SRSS1 = new TH2F("h_NBJets_EM_SRSS1", "h_NBJets_EM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EM_SRSS1->Sumw2();
  h_NBJets_EM_SRSS2 = new TH2F("h_NBJets_EM_SRSS2", "h_NBJets_EM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EM_SRSS2->Sumw2();
  h_NBJets_EE_SROS1 = new TH2F("h_NBJets_EE_SROS1", "h_NBJets_EE_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EE_SROS1->Sumw2();
  h_NBJets_MM_SROS1 = new TH2F("h_NBJets_MM_SROS1", "h_NBJets_MM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_MM_SROS1->Sumw2();
  h_NBJets_EM_SROS1 = new TH2F("h_NBJets_EM_SROS1", "h_NBJets_EM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NBJets_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_NCJets_EE_SRSS1 = new TH2F("h_NCJets_EE_SRSS1", "h_NCJets_EE_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EE_SRSS1->Sumw2();
  h_NCJets_EE_SRSS2 = new TH2F("h_NCJets_EE_SRSS2", "h_NCJets_EE_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EE_SRSS2->Sumw2();
  h_NCJets_MM_SRSS1 = new TH2F("h_NCJets_MM_SRSS1", "h_NCJets_MM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_MM_SRSS1->Sumw2();  
  h_NCJets_MM_SRSS2 = new TH2F("h_NCJets_MM_SRSS2", "h_NCJets_MM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_MM_SRSS2->Sumw2();
  h_NCJets_MM_SRSS3 = new TH2F("h_NCJets_MM_SRSS3", "h_NCJets_MM_SRSS3", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_MM_SRSS3->Sumw2();
  h_NCJets_MM_SRSS4 = new TH2F("h_NCJets_MM_SRSS4", "h_NCJets_MM_SRSS4", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_MM_SRSS4->Sumw2();
  h_NCJets_EM_SRSS1 = new TH2F("h_NCJets_EM_SRSS1", "h_NCJets_EM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EM_SRSS1->Sumw2();
  h_NCJets_EM_SRSS2 = new TH2F("h_NCJets_EM_SRSS2", "h_NCJets_EM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EM_SRSS2->Sumw2();
  h_NCJets_EE_SROS1 = new TH2F("h_NCJets_EE_SROS1", "h_NCJets_EE_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EE_SROS1->Sumw2();
  h_NCJets_MM_SROS1 = new TH2F("h_NCJets_MM_SROS1", "h_NCJets_MM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_MM_SROS1->Sumw2();
  h_NCJets_EM_SROS1 = new TH2F("h_NCJets_EM_SROS1", "h_NCJets_EM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NCJets_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_NFJets_EE_SRSS1 = new TH2F("h_NFJets_EE_SRSS1", "h_NFJets_EE_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EE_SRSS1->Sumw2();
  h_NFJets_EE_SRSS2 = new TH2F("h_NFJets_EE_SRSS2", "h_NFJets_EE_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EE_SRSS2->Sumw2();
  h_NFJets_MM_SRSS1 = new TH2F("h_NFJets_MM_SRSS1", "h_NFJets_MM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_MM_SRSS1->Sumw2();  
  h_NFJets_MM_SRSS2 = new TH2F("h_NFJets_MM_SRSS2", "h_NFJets_MM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_MM_SRSS2->Sumw2();
  h_NFJets_MM_SRSS3 = new TH2F("h_NFJets_MM_SRSS3", "h_NFJets_MM_SRSS3", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_MM_SRSS3->Sumw2();
  h_NFJets_MM_SRSS4 = new TH2F("h_NFJets_MM_SRSS4", "h_NFJets_MM_SRSS4", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_MM_SRSS4->Sumw2();
  h_NFJets_EM_SRSS1 = new TH2F("h_NFJets_EM_SRSS1", "h_NFJets_EM_SRSS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EM_SRSS1->Sumw2();
  h_NFJets_EM_SRSS2 = new TH2F("h_NFJets_EM_SRSS2", "h_NFJets_EM_SRSS2", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EM_SRSS2->Sumw2();
  h_NFJets_EE_SROS1 = new TH2F("h_NFJets_EE_SROS1", "h_NFJets_EE_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EE_SROS1->Sumw2();
  h_NFJets_MM_SROS1 = new TH2F("h_NFJets_MM_SROS1", "h_NFJets_MM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_MM_SROS1->Sumw2();
  h_NFJets_EM_SROS1 = new TH2F("h_NFJets_EM_SROS1", "h_NFJets_EM_SROS1", 11, -0.5, 10.5 ,130, 0, 129);  h_NFJets_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_mZTT_coll_EE_SRSS1 = new TH2F("h_mZTT_coll_EE_SRSS1", "h_mZTT_coll_EE_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EE_SRSS1->Sumw2();
  h_mZTT_coll_EE_SRSS2 = new TH2F("h_mZTT_coll_EE_SRSS2", "h_mZTT_coll_EE_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EE_SRSS2->Sumw2();
  h_mZTT_coll_MM_SRSS1 = new TH2F("h_mZTT_coll_MM_SRSS1", "h_mZTT_coll_MM_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_MM_SRSS1->Sumw2();  
  h_mZTT_coll_MM_SRSS2 = new TH2F("h_mZTT_coll_MM_SRSS2", "h_mZTT_coll_MM_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_MM_SRSS2->Sumw2();
  h_mZTT_coll_MM_SRSS3 = new TH2F("h_mZTT_coll_MM_SRSS3", "h_mZTT_coll_MM_SRSS3", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_MM_SRSS3->Sumw2();
  h_mZTT_coll_MM_SRSS4 = new TH2F("h_mZTT_coll_MM_SRSS4", "h_mZTT_coll_MM_SRSS4", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_MM_SRSS4->Sumw2();
  h_mZTT_coll_EM_SRSS1 = new TH2F("h_mZTT_coll_EM_SRSS1", "h_mZTT_coll_EM_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EM_SRSS1->Sumw2();
  h_mZTT_coll_EM_SRSS2 = new TH2F("h_mZTT_coll_EM_SRSS2", "h_mZTT_coll_EM_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EM_SRSS2->Sumw2();
  h_mZTT_coll_EE_SROS1 = new TH2F("h_mZTT_coll_EE_SROS1", "h_mZTT_coll_EE_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EE_SROS1->Sumw2();
  h_mZTT_coll_MM_SROS1 = new TH2F("h_mZTT_coll_MM_SROS1", "h_mZTT_coll_MM_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_MM_SROS1->Sumw2();
  h_mZTT_coll_EM_SROS1 = new TH2F("h_mZTT_coll_EM_SROS1", "h_mZTT_coll_EM_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_coll_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mZTT_mmc_EE_SRSS1 = new TH2F("h_mZTT_mmc_EE_SRSS1", "h_mZTT_mmc_EE_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EE_SRSS1->Sumw2();
  h_mZTT_mmc_EE_SRSS2 = new TH2F("h_mZTT_mmc_EE_SRSS2", "h_mZTT_mmc_EE_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EE_SRSS2->Sumw2();
  h_mZTT_mmc_MM_SRSS1 = new TH2F("h_mZTT_mmc_MM_SRSS1", "h_mZTT_mmc_MM_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_MM_SRSS1->Sumw2();  
  h_mZTT_mmc_MM_SRSS2 = new TH2F("h_mZTT_mmc_MM_SRSS2", "h_mZTT_mmc_MM_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_MM_SRSS2->Sumw2();
  h_mZTT_mmc_MM_SRSS3 = new TH2F("h_mZTT_mmc_MM_SRSS3", "h_mZTT_mmc_MM_SRSS3", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_MM_SRSS3->Sumw2();
  h_mZTT_mmc_MM_SRSS4 = new TH2F("h_mZTT_mmc_MM_SRSS4", "h_mZTT_mmc_MM_SRSS4", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_MM_SRSS4->Sumw2();
  h_mZTT_mmc_EM_SRSS1 = new TH2F("h_mZTT_mmc_EM_SRSS1", "h_mZTT_mmc_EM_SRSS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EM_SRSS1->Sumw2();
  h_mZTT_mmc_EM_SRSS2 = new TH2F("h_mZTT_mmc_EM_SRSS2", "h_mZTT_mmc_EM_SRSS2", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EM_SRSS2->Sumw2();
  h_mZTT_mmc_EE_SROS1 = new TH2F("h_mZTT_mmc_EE_SROS1", "h_mZTT_mmc_EE_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EE_SROS1->Sumw2();
  h_mZTT_mmc_MM_SROS1 = new TH2F("h_mZTT_mmc_MM_SROS1", "h_mZTT_mmc_MM_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_MM_SROS1->Sumw2();
  h_mZTT_mmc_EM_SROS1 = new TH2F("h_mZTT_mmc_EM_SROS1", "h_mZTT_mmc_EM_SROS1", 500, -2, 498 ,130, 0, 129);  h_mZTT_mmc_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhijj_EE_SRSS1 = new TH2F("h_DeltaPhijj_EE_SRSS1", "h_DeltaPhijj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EE_SRSS1->Sumw2();
  h_DeltaPhijj_EE_SRSS2 = new TH2F("h_DeltaPhijj_EE_SRSS2", "h_DeltaPhijj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EE_SRSS2->Sumw2();
  h_DeltaPhijj_MM_SRSS1 = new TH2F("h_DeltaPhijj_MM_SRSS1", "h_DeltaPhijj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_MM_SRSS1->Sumw2();  
  h_DeltaPhijj_MM_SRSS2 = new TH2F("h_DeltaPhijj_MM_SRSS2", "h_DeltaPhijj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_MM_SRSS2->Sumw2();
  h_DeltaPhijj_MM_SRSS3 = new TH2F("h_DeltaPhijj_MM_SRSS3", "h_DeltaPhijj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_MM_SRSS3->Sumw2();
  h_DeltaPhijj_MM_SRSS4 = new TH2F("h_DeltaPhijj_MM_SRSS4", "h_DeltaPhijj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_MM_SRSS4->Sumw2();
  h_DeltaPhijj_EM_SRSS1 = new TH2F("h_DeltaPhijj_EM_SRSS1", "h_DeltaPhijj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EM_SRSS1->Sumw2();
  h_DeltaPhijj_EM_SRSS2 = new TH2F("h_DeltaPhijj_EM_SRSS2", "h_DeltaPhijj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EM_SRSS2->Sumw2();
  h_DeltaPhijj_EE_SROS1 = new TH2F("h_DeltaPhijj_EE_SROS1", "h_DeltaPhijj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EE_SROS1->Sumw2();
  h_DeltaPhijj_MM_SROS1 = new TH2F("h_DeltaPhijj_MM_SROS1", "h_DeltaPhijj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_MM_SROS1->Sumw2();
  h_DeltaPhijj_EM_SROS1 = new TH2F("h_DeltaPhijj_EM_SROS1", "h_DeltaPhijj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhijj_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_pTjj_EE_SRSS1 = new TH2F("h_pTjj_EE_SRSS1", "h_pTjj_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_EE_SRSS1->Sumw2();
  h_pTjj_EE_SRSS2 = new TH2F("h_pTjj_EE_SRSS2", "h_pTjj_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTjj_EE_SRSS2->Sumw2();
  h_pTjj_MM_SRSS1 = new TH2F("h_pTjj_MM_SRSS1", "h_pTjj_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_MM_SRSS1->Sumw2();
  h_pTjj_MM_SRSS2 = new TH2F("h_pTjj_MM_SRSS2", "h_pTjj_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTjj_MM_SRSS2->Sumw2();
  h_pTjj_MM_SRSS3 = new TH2F("h_pTjj_MM_SRSS3", "h_pTjj_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTjj_MM_SRSS3->Sumw2();
  h_pTjj_MM_SRSS4 = new TH2F("h_pTjj_MM_SRSS4", "h_pTjj_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTjj_MM_SRSS4->Sumw2();
  h_pTjj_EM_SRSS1 = new TH2F("h_pTjj_EM_SRSS1", "h_pTjj_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_EM_SRSS1->Sumw2();
  h_pTjj_EM_SRSS2 = new TH2F("h_pTjj_EM_SRSS2", "h_pTjj_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTjj_EM_SRSS2->Sumw2();
  h_pTjj_EE_SROS1 = new TH2F("h_pTjj_EE_SROS1", "h_pTjj_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_EE_SROS1->Sumw2();
  h_pTjj_MM_SROS1 = new TH2F("h_pTjj_MM_SROS1", "h_pTjj_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_MM_SROS1->Sumw2();
  h_pTjj_EM_SROS1 = new TH2F("h_pTjj_EM_SROS1", "h_pTjj_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTjj_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_pTll_EE_SRSS1 = new TH2F("h_pTll_EE_SRSS1", "h_pTll_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTll_EE_SRSS1->Sumw2();
  h_pTll_EE_SRSS2 = new TH2F("h_pTll_EE_SRSS2", "h_pTll_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTll_EE_SRSS2->Sumw2();
  h_pTll_MM_SRSS1 = new TH2F("h_pTll_MM_SRSS1", "h_pTll_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTll_MM_SRSS1->Sumw2();  
  h_pTll_MM_SRSS2 = new TH2F("h_pTll_MM_SRSS2", "h_pTll_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTll_MM_SRSS2->Sumw2();
  h_pTll_MM_SRSS3 = new TH2F("h_pTll_MM_SRSS3", "h_pTll_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_pTll_MM_SRSS3->Sumw2();
  h_pTll_MM_SRSS4 = new TH2F("h_pTll_MM_SRSS4", "h_pTll_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_pTll_MM_SRSS4->Sumw2();
  h_pTll_EM_SRSS1 = new TH2F("h_pTll_EM_SRSS1", "h_pTll_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_pTll_EM_SRSS1->Sumw2();
  h_pTll_EM_SRSS2 = new TH2F("h_pTll_EM_SRSS2", "h_pTll_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_pTll_EM_SRSS2->Sumw2();
  h_pTll_EE_SROS1 = new TH2F("h_pTll_EE_SROS1", "h_pTll_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTll_EE_SROS1->Sumw2();
  h_pTll_MM_SROS1 = new TH2F("h_pTll_MM_SROS1", "h_pTll_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTll_MM_SROS1->Sumw2();
  h_pTll_EM_SROS1 = new TH2F("h_pTll_EM_SROS1", "h_pTll_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_pTll_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl0_EE_SRSS1 = new TH2F("h_DeltaPhiMETl0_EE_SRSS1", "h_DeltaPhiMETl0_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EE_SRSS1->Sumw2();
  h_DeltaPhiMETl0_EE_SRSS2 = new TH2F("h_DeltaPhiMETl0_EE_SRSS2", "h_DeltaPhiMETl0_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EE_SRSS2->Sumw2();
  h_DeltaPhiMETl0_MM_SRSS1 = new TH2F("h_DeltaPhiMETl0_MM_SRSS1", "h_DeltaPhiMETl0_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETl0_MM_SRSS2 = new TH2F("h_DeltaPhiMETl0_MM_SRSS2", "h_DeltaPhiMETl0_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_MM_SRSS2->Sumw2();
  h_DeltaPhiMETl0_MM_SRSS3 = new TH2F("h_DeltaPhiMETl0_MM_SRSS3", "h_DeltaPhiMETl0_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_MM_SRSS3->Sumw2();
  h_DeltaPhiMETl0_MM_SRSS4 = new TH2F("h_DeltaPhiMETl0_MM_SRSS4", "h_DeltaPhiMETl0_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_MM_SRSS4->Sumw2();
  h_DeltaPhiMETl0_EM_SRSS1 = new TH2F("h_DeltaPhiMETl0_EM_SRSS1", "h_DeltaPhiMETl0_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EM_SRSS1->Sumw2();
  h_DeltaPhiMETl0_EM_SRSS2 = new TH2F("h_DeltaPhiMETl0_EM_SRSS2", "h_DeltaPhiMETl0_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EM_SRSS2->Sumw2();
  h_DeltaPhiMETl0_EE_SROS1 = new TH2F("h_DeltaPhiMETl0_EE_SROS1", "h_DeltaPhiMETl0_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EE_SROS1->Sumw2();
  h_DeltaPhiMETl0_MM_SROS1 = new TH2F("h_DeltaPhiMETl0_MM_SROS1", "h_DeltaPhiMETl0_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_MM_SROS1->Sumw2();
  h_DeltaPhiMETl0_EM_SROS1 = new TH2F("h_DeltaPhiMETl0_EM_SROS1", "h_DeltaPhiMETl0_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl0_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETl1_EE_SRSS1 = new TH2F("h_DeltaPhiMETl1_EE_SRSS1", "h_DeltaPhiMETl1_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EE_SRSS1->Sumw2();
  h_DeltaPhiMETl1_EE_SRSS2 = new TH2F("h_DeltaPhiMETl1_EE_SRSS2", "h_DeltaPhiMETl1_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EE_SRSS2->Sumw2();
  h_DeltaPhiMETl1_MM_SRSS1 = new TH2F("h_DeltaPhiMETl1_MM_SRSS1", "h_DeltaPhiMETl1_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETl1_MM_SRSS2 = new TH2F("h_DeltaPhiMETl1_MM_SRSS2", "h_DeltaPhiMETl1_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_MM_SRSS2->Sumw2();
  h_DeltaPhiMETl1_MM_SRSS3 = new TH2F("h_DeltaPhiMETl1_MM_SRSS3", "h_DeltaPhiMETl1_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_MM_SRSS3->Sumw2();
  h_DeltaPhiMETl1_MM_SRSS4 = new TH2F("h_DeltaPhiMETl1_MM_SRSS4", "h_DeltaPhiMETl1_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_MM_SRSS4->Sumw2();
  h_DeltaPhiMETl1_EM_SRSS1 = new TH2F("h_DeltaPhiMETl1_EM_SRSS1", "h_DeltaPhiMETl1_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EM_SRSS1->Sumw2();
  h_DeltaPhiMETl1_EM_SRSS2 = new TH2F("h_DeltaPhiMETl1_EM_SRSS2", "h_DeltaPhiMETl1_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EM_SRSS2->Sumw2();
  h_DeltaPhiMETl1_EE_SROS1 = new TH2F("h_DeltaPhiMETl1_EE_SROS1", "h_DeltaPhiMETl1_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EE_SROS1->Sumw2();
  h_DeltaPhiMETl1_MM_SROS1 = new TH2F("h_DeltaPhiMETl1_MM_SROS1", "h_DeltaPhiMETl1_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_MM_SROS1->Sumw2();
  h_DeltaPhiMETl1_EM_SROS1 = new TH2F("h_DeltaPhiMETl1_EM_SROS1", "h_DeltaPhiMETl1_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETl1_EM_SROS1->Sumw2();
  
    /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj0_EE_SRSS1 = new TH2F("h_DeltaPhiMETj0_EE_SRSS1", "h_DeltaPhiMETj0_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EE_SRSS1->Sumw2();
  h_DeltaPhiMETj0_EE_SRSS2 = new TH2F("h_DeltaPhiMETj0_EE_SRSS2", "h_DeltaPhiMETj0_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EE_SRSS2->Sumw2();
  h_DeltaPhiMETj0_MM_SRSS1 = new TH2F("h_DeltaPhiMETj0_MM_SRSS1", "h_DeltaPhiMETj0_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETj0_MM_SRSS2 = new TH2F("h_DeltaPhiMETj0_MM_SRSS2", "h_DeltaPhiMETj0_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_MM_SRSS2->Sumw2();
  h_DeltaPhiMETj0_MM_SRSS3 = new TH2F("h_DeltaPhiMETj0_MM_SRSS3", "h_DeltaPhiMETj0_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_MM_SRSS3->Sumw2();
  h_DeltaPhiMETj0_MM_SRSS4 = new TH2F("h_DeltaPhiMETj0_MM_SRSS4", "h_DeltaPhiMETj0_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_MM_SRSS4->Sumw2();
  h_DeltaPhiMETj0_EM_SRSS1 = new TH2F("h_DeltaPhiMETj0_EM_SRSS1", "h_DeltaPhiMETj0_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EM_SRSS1->Sumw2();
  h_DeltaPhiMETj0_EM_SRSS2 = new TH2F("h_DeltaPhiMETj0_EM_SRSS2", "h_DeltaPhiMETj0_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EM_SRSS2->Sumw2();
  h_DeltaPhiMETj0_EE_SROS1 = new TH2F("h_DeltaPhiMETj0_EE_SROS1", "h_DeltaPhiMETj0_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EE_SROS1->Sumw2();
  h_DeltaPhiMETj0_MM_SROS1 = new TH2F("h_DeltaPhiMETj0_MM_SROS1", "h_DeltaPhiMETj0_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_MM_SROS1->Sumw2();
  h_DeltaPhiMETj0_EM_SROS1 = new TH2F("h_DeltaPhiMETj0_EM_SROS1", "h_DeltaPhiMETj0_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj0_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETj1_EE_SRSS1 = new TH2F("h_DeltaPhiMETj1_EE_SRSS1", "h_DeltaPhiMETj1_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EE_SRSS1->Sumw2();
  h_DeltaPhiMETj1_EE_SRSS2 = new TH2F("h_DeltaPhiMETj1_EE_SRSS2", "h_DeltaPhiMETj1_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EE_SRSS2->Sumw2();
  h_DeltaPhiMETj1_MM_SRSS1 = new TH2F("h_DeltaPhiMETj1_MM_SRSS1", "h_DeltaPhiMETj1_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETj1_MM_SRSS2 = new TH2F("h_DeltaPhiMETj1_MM_SRSS2", "h_DeltaPhiMETj1_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_MM_SRSS2->Sumw2();
  h_DeltaPhiMETj1_MM_SRSS3 = new TH2F("h_DeltaPhiMETj1_MM_SRSS3", "h_DeltaPhiMETj1_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_MM_SRSS3->Sumw2();
  h_DeltaPhiMETj1_MM_SRSS4 = new TH2F("h_DeltaPhiMETj1_MM_SRSS4", "h_DeltaPhiMETj1_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_MM_SRSS4->Sumw2();
  h_DeltaPhiMETj1_EM_SRSS1 = new TH2F("h_DeltaPhiMETj1_EM_SRSS1", "h_DeltaPhiMETj1_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EM_SRSS1->Sumw2();
  h_DeltaPhiMETj1_EM_SRSS2 = new TH2F("h_DeltaPhiMETj1_EM_SRSS2", "h_DeltaPhiMETj1_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EM_SRSS2->Sumw2();
  h_DeltaPhiMETj1_EE_SROS1 = new TH2F("h_DeltaPhiMETj1_EE_SROS1", "h_DeltaPhiMETj1_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EE_SROS1->Sumw2();
  h_DeltaPhiMETj1_MM_SROS1 = new TH2F("h_DeltaPhiMETj1_MM_SROS1", "h_DeltaPhiMETj1_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_MM_SROS1->Sumw2();
  h_DeltaPhiMETj1_EM_SROS1 = new TH2F("h_DeltaPhiMETj1_EM_SROS1", "h_DeltaPhiMETj1_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETj1_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhiMETjj_EE_SRSS1 = new TH2F("h_DeltaPhiMETjj_EE_SRSS1", "h_DeltaPhiMETjj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EE_SRSS1->Sumw2();
  h_DeltaPhiMETjj_EE_SRSS2 = new TH2F("h_DeltaPhiMETjj_EE_SRSS2", "h_DeltaPhiMETjj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EE_SRSS2->Sumw2();
  h_DeltaPhiMETjj_MM_SRSS1 = new TH2F("h_DeltaPhiMETjj_MM_SRSS1", "h_DeltaPhiMETjj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_MM_SRSS1->Sumw2();  
  h_DeltaPhiMETjj_MM_SRSS2 = new TH2F("h_DeltaPhiMETjj_MM_SRSS2", "h_DeltaPhiMETjj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_MM_SRSS2->Sumw2();
  h_DeltaPhiMETjj_MM_SRSS3 = new TH2F("h_DeltaPhiMETjj_MM_SRSS3", "h_DeltaPhiMETjj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_MM_SRSS3->Sumw2();
  h_DeltaPhiMETjj_MM_SRSS4 = new TH2F("h_DeltaPhiMETjj_MM_SRSS4", "h_DeltaPhiMETjj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_MM_SRSS4->Sumw2();
  h_DeltaPhiMETjj_EM_SRSS1 = new TH2F("h_DeltaPhiMETjj_EM_SRSS1", "h_DeltaPhiMETjj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EM_SRSS1->Sumw2();
  h_DeltaPhiMETjj_EM_SRSS2 = new TH2F("h_DeltaPhiMETjj_EM_SRSS2", "h_DeltaPhiMETjj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EM_SRSS2->Sumw2();
  h_DeltaPhiMETjj_EE_SROS1 = new TH2F("h_DeltaPhiMETjj_EE_SROS1", "h_DeltaPhiMETjj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EE_SROS1->Sumw2();
  h_DeltaPhiMETjj_MM_SROS1 = new TH2F("h_DeltaPhiMETjj_MM_SROS1", "h_DeltaPhiMETjj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_MM_SROS1->Sumw2();
  h_DeltaPhiMETjj_EM_SROS1 = new TH2F("h_DeltaPhiMETjj_EM_SROS1", "h_DeltaPhiMETjj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhiMETjj_EM_SROS1->Sumw2();

    /*--------------------------------------------------------------------------------*/ 
  h_DeltaRjj_EE_SRSS1 = new TH2F("h_DeltaRjj_EE_SRSS1", "h_DeltaRjj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EE_SRSS1->Sumw2();
  h_DeltaRjj_EE_SRSS2 = new TH2F("h_DeltaRjj_EE_SRSS2", "h_DeltaRjj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EE_SRSS2->Sumw2();
  h_DeltaRjj_MM_SRSS1 = new TH2F("h_DeltaRjj_MM_SRSS1", "h_DeltaRjj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_MM_SRSS1->Sumw2();  
  h_DeltaRjj_MM_SRSS2 = new TH2F("h_DeltaRjj_MM_SRSS2", "h_DeltaRjj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_MM_SRSS2->Sumw2();
  h_DeltaRjj_MM_SRSS3 = new TH2F("h_DeltaRjj_MM_SRSS3", "h_DeltaRjj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_MM_SRSS3->Sumw2();
  h_DeltaRjj_MM_SRSS4 = new TH2F("h_DeltaRjj_MM_SRSS4", "h_DeltaRjj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_MM_SRSS4->Sumw2();
  h_DeltaRjj_EM_SRSS1 = new TH2F("h_DeltaRjj_EM_SRSS1", "h_DeltaRjj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EM_SRSS1->Sumw2();
  h_DeltaRjj_EM_SRSS2 = new TH2F("h_DeltaRjj_EM_SRSS2", "h_DeltaRjj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EM_SRSS2->Sumw2();
  h_DeltaRjj_EE_SROS1 = new TH2F("h_DeltaRjj_EE_SROS1", "h_DeltaRjj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EE_SROS1->Sumw2();
  h_DeltaRjj_MM_SROS1 = new TH2F("h_DeltaRjj_MM_SROS1", "h_DeltaRjj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_MM_SROS1->Sumw2();
  h_DeltaRjj_EM_SROS1 = new TH2F("h_DeltaRjj_EM_SROS1", "h_DeltaRjj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRjj_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_etal0_EE_SRSS1 = new TH2F("h_etal0_EE_SRSS1", "h_etal0_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal0_EE_SRSS1->Sumw2();
  h_etal0_EE_SRSS2 = new TH2F("h_etal0_EE_SRSS2", "h_etal0_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal0_EE_SRSS2->Sumw2();
  h_etal0_MM_SRSS1 = new TH2F("h_etal0_MM_SRSS1", "h_etal0_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal0_MM_SRSS1->Sumw2();  
  h_etal0_MM_SRSS2 = new TH2F("h_etal0_MM_SRSS2", "h_etal0_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal0_MM_SRSS2->Sumw2();
  h_etal0_MM_SRSS3 = new TH2F("h_etal0_MM_SRSS3", "h_etal0_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_etal0_MM_SRSS3->Sumw2();
  h_etal0_MM_SRSS4 = new TH2F("h_etal0_MM_SRSS4", "h_etal0_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_etal0_MM_SRSS4->Sumw2();
  h_etal0_EM_SRSS1 = new TH2F("h_etal0_EM_SRSS1", "h_etal0_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal0_EM_SRSS1->Sumw2();
  h_etal0_EM_SRSS2 = new TH2F("h_etal0_EM_SRSS2", "h_etal0_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal0_EM_SRSS2->Sumw2();
  h_etal0_EE_SROS1 = new TH2F("h_etal0_EE_SROS1", "h_etal0_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal0_EE_SROS1->Sumw2();
  h_etal0_MM_SROS1 = new TH2F("h_etal0_MM_SROS1", "h_etal0_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal0_MM_SROS1->Sumw2();
  h_etal0_EM_SROS1 = new TH2F("h_etal0_EM_SROS1", "h_etal0_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal0_EM_SROS1->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etal1_EE_SRSS1 = new TH2F("h_etal1_EE_SRSS1", "h_etal1_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal1_EE_SRSS1->Sumw2();
  h_etal1_EE_SRSS2 = new TH2F("h_etal1_EE_SRSS2", "h_etal1_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal1_EE_SRSS2->Sumw2();
  h_etal1_MM_SRSS1 = new TH2F("h_etal1_MM_SRSS1", "h_etal1_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal1_MM_SRSS1->Sumw2();  
  h_etal1_MM_SRSS2 = new TH2F("h_etal1_MM_SRSS2", "h_etal1_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal1_MM_SRSS2->Sumw2();
  h_etal1_MM_SRSS3 = new TH2F("h_etal1_MM_SRSS3", "h_etal1_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_etal1_MM_SRSS3->Sumw2();
  h_etal1_MM_SRSS4 = new TH2F("h_etal1_MM_SRSS4", "h_etal1_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_etal1_MM_SRSS4->Sumw2();
  h_etal1_EM_SRSS1 = new TH2F("h_etal1_EM_SRSS1", "h_etal1_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etal1_EM_SRSS1->Sumw2();
  h_etal1_EM_SRSS2 = new TH2F("h_etal1_EM_SRSS2", "h_etal1_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etal1_EM_SRSS2->Sumw2();
  h_etal1_EE_SROS1 = new TH2F("h_etal1_EE_SROS1", "h_etal1_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal1_EE_SROS1->Sumw2();
  h_etal1_MM_SROS1 = new TH2F("h_etal1_MM_SROS1", "h_etal1_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal1_MM_SROS1->Sumw2();
  h_etal1_EM_SROS1 = new TH2F("h_etal1_EM_SROS1", "h_etal1_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etal1_EM_SROS1->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etaj0_EE_SRSS1 = new TH2F("h_etaj0_EE_SRSS1", "h_etaj0_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_EE_SRSS1->Sumw2();
  h_etaj0_EE_SRSS2 = new TH2F("h_etaj0_EE_SRSS2", "h_etaj0_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj0_EE_SRSS2->Sumw2();
  h_etaj0_MM_SRSS1 = new TH2F("h_etaj0_MM_SRSS1", "h_etaj0_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_MM_SRSS1->Sumw2();  
  h_etaj0_MM_SRSS2 = new TH2F("h_etaj0_MM_SRSS2", "h_etaj0_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj0_MM_SRSS2->Sumw2();
  h_etaj0_MM_SRSS3 = new TH2F("h_etaj0_MM_SRSS3", "h_etaj0_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_etaj0_MM_SRSS3->Sumw2();
  h_etaj0_MM_SRSS4 = new TH2F("h_etaj0_MM_SRSS4", "h_etaj0_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_etaj0_MM_SRSS4->Sumw2();
  h_etaj0_EM_SRSS1 = new TH2F("h_etaj0_EM_SRSS1", "h_etaj0_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_EM_SRSS1->Sumw2();
  h_etaj0_EM_SRSS2 = new TH2F("h_etaj0_EM_SRSS2", "h_etaj0_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj0_EM_SRSS2->Sumw2();
  h_etaj0_EE_SROS1 = new TH2F("h_etaj0_EE_SROS1", "h_etaj0_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_EE_SROS1->Sumw2();
  h_etaj0_MM_SROS1 = new TH2F("h_etaj0_MM_SROS1", "h_etaj0_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_MM_SROS1->Sumw2();
  h_etaj0_EM_SROS1 = new TH2F("h_etaj0_EM_SROS1", "h_etaj0_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj0_EM_SROS1->Sumw2();
    /*--------------------------------------------------------------------------------*/ 
  h_etaj1_EE_SRSS1 = new TH2F("h_etaj1_EE_SRSS1", "h_etaj1_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_EE_SRSS1->Sumw2();
  h_etaj1_EE_SRSS2 = new TH2F("h_etaj1_EE_SRSS2", "h_etaj1_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj1_EE_SRSS2->Sumw2();
  h_etaj1_MM_SRSS1 = new TH2F("h_etaj1_MM_SRSS1", "h_etaj1_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_MM_SRSS1->Sumw2();  
  h_etaj1_MM_SRSS2 = new TH2F("h_etaj1_MM_SRSS2", "h_etaj1_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj1_MM_SRSS2->Sumw2();
  h_etaj1_MM_SRSS3 = new TH2F("h_etaj1_MM_SRSS3", "h_etaj1_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_etaj1_MM_SRSS3->Sumw2();
  h_etaj1_MM_SRSS4 = new TH2F("h_etaj1_MM_SRSS4", "h_etaj1_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_etaj1_MM_SRSS4->Sumw2();
  h_etaj1_EM_SRSS1 = new TH2F("h_etaj1_EM_SRSS1", "h_etaj1_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_EM_SRSS1->Sumw2();
  h_etaj1_EM_SRSS2 = new TH2F("h_etaj1_EM_SRSS2", "h_etaj1_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_etaj1_EM_SRSS2->Sumw2();
  h_etaj1_EE_SROS1 = new TH2F("h_etaj1_EE_SROS1", "h_etaj1_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_EE_SROS1->Sumw2();
  h_etaj1_MM_SROS1 = new TH2F("h_etaj1_MM_SROS1", "h_etaj1_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_MM_SROS1->Sumw2();
  h_etaj1_EM_SROS1 = new TH2F("h_etaj1_EM_SROS1", "h_etaj1_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_etaj1_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_mTl0MET_EE_SRSS1 = new TH2F("h_mTl0MET_EE_SRSS1", "h_mTl0MET_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EE_SRSS1->Sumw2();
  h_mTl0MET_EE_SRSS2 = new TH2F("h_mTl0MET_EE_SRSS2", "h_mTl0MET_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EE_SRSS2->Sumw2();
  h_mTl0MET_MM_SRSS1 = new TH2F("h_mTl0MET_MM_SRSS1", "h_mTl0MET_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_MM_SRSS1->Sumw2();  
  h_mTl0MET_MM_SRSS2 = new TH2F("h_mTl0MET_MM_SRSS2", "h_mTl0MET_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_MM_SRSS2->Sumw2();
  h_mTl0MET_MM_SRSS3 = new TH2F("h_mTl0MET_MM_SRSS3", "h_mTl0MET_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_MM_SRSS3->Sumw2();
  h_mTl0MET_MM_SRSS4 = new TH2F("h_mTl0MET_MM_SRSS4", "h_mTl0MET_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_MM_SRSS4->Sumw2();
  h_mTl0MET_EM_SRSS1 = new TH2F("h_mTl0MET_EM_SRSS1", "h_mTl0MET_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EM_SRSS1->Sumw2();
  h_mTl0MET_EM_SRSS2 = new TH2F("h_mTl0MET_EM_SRSS2", "h_mTl0MET_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EM_SRSS2->Sumw2();
  h_mTl0MET_EE_SROS1 = new TH2F("h_mTl0MET_EE_SROS1", "h_mTl0MET_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EE_SROS1->Sumw2();
  h_mTl0MET_MM_SROS1 = new TH2F("h_mTl0MET_MM_SROS1", "h_mTl0MET_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_MM_SROS1->Sumw2();
  h_mTl0MET_EM_SROS1 = new TH2F("h_mTl0MET_EM_SROS1", "h_mTl0MET_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl0MET_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_mTl1MET_EE_SRSS1 = new TH2F("h_mTl1MET_EE_SRSS1", "h_mTl1MET_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EE_SRSS1->Sumw2();
  h_mTl1MET_EE_SRSS2 = new TH2F("h_mTl1MET_EE_SRSS2", "h_mTl1MET_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EE_SRSS2->Sumw2();
  h_mTl1MET_MM_SRSS1 = new TH2F("h_mTl1MET_MM_SRSS1", "h_mTl1MET_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_MM_SRSS1->Sumw2();  
  h_mTl1MET_MM_SRSS2 = new TH2F("h_mTl1MET_MM_SRSS2", "h_mTl1MET_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_MM_SRSS2->Sumw2();
  h_mTl1MET_MM_SRSS3 = new TH2F("h_mTl1MET_MM_SRSS3", "h_mTl1MET_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_MM_SRSS3->Sumw2();
  h_mTl1MET_MM_SRSS4 = new TH2F("h_mTl1MET_MM_SRSS4", "h_mTl1MET_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_MM_SRSS4->Sumw2();
  h_mTl1MET_EM_SRSS1 = new TH2F("h_mTl1MET_EM_SRSS1", "h_mTl1MET_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EM_SRSS1->Sumw2();
  h_mTl1MET_EM_SRSS2 = new TH2F("h_mTl1MET_EM_SRSS2", "h_mTl1MET_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EM_SRSS2->Sumw2();
  h_mTl1MET_EE_SROS1 = new TH2F("h_mTl1MET_EE_SROS1", "h_mTl1MET_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EE_SROS1->Sumw2();
  h_mTl1MET_MM_SROS1 = new TH2F("h_mTl1MET_MM_SROS1", "h_mTl1MET_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_MM_SROS1->Sumw2();
  h_mTl1MET_EM_SROS1 = new TH2F("h_mTl1MET_EM_SROS1", "h_mTl1MET_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mTl1MET_EM_SROS1->Sumw2();

      /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhilljj_EE_SRSS1 = new TH2F("h_DeltaPhilljj_EE_SRSS1", "h_DeltaPhilljj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EE_SRSS1->Sumw2();
  h_DeltaPhilljj_EE_SRSS2 = new TH2F("h_DeltaPhilljj_EE_SRSS2", "h_DeltaPhilljj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EE_SRSS2->Sumw2();
  h_DeltaPhilljj_MM_SRSS1 = new TH2F("h_DeltaPhilljj_MM_SRSS1", "h_DeltaPhilljj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_MM_SRSS1->Sumw2();  
  h_DeltaPhilljj_MM_SRSS2 = new TH2F("h_DeltaPhilljj_MM_SRSS2", "h_DeltaPhilljj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_MM_SRSS2->Sumw2();
  h_DeltaPhilljj_MM_SRSS3 = new TH2F("h_DeltaPhilljj_MM_SRSS3", "h_DeltaPhilljj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_MM_SRSS3->Sumw2();
  h_DeltaPhilljj_MM_SRSS4 = new TH2F("h_DeltaPhilljj_MM_SRSS4", "h_DeltaPhilljj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_MM_SRSS4->Sumw2();
  h_DeltaPhilljj_EM_SRSS1 = new TH2F("h_DeltaPhilljj_EM_SRSS1", "h_DeltaPhilljj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EM_SRSS1->Sumw2();
  h_DeltaPhilljj_EM_SRSS2 = new TH2F("h_DeltaPhilljj_EM_SRSS2", "h_DeltaPhilljj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EM_SRSS2->Sumw2();
  h_DeltaPhilljj_EE_SROS1 = new TH2F("h_DeltaPhilljj_EE_SROS1", "h_DeltaPhilljj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EE_SROS1->Sumw2();
  h_DeltaPhilljj_MM_SROS1 = new TH2F("h_DeltaPhilljj_MM_SROS1", "h_DeltaPhilljj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_MM_SROS1->Sumw2();
  h_DeltaPhilljj_EM_SROS1 = new TH2F("h_DeltaPhilljj_EM_SROS1", "h_DeltaPhilljj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhilljj_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil0jj_EE_SRSS1 = new TH2F("h_DeltaPhil0jj_EE_SRSS1", "h_DeltaPhil0jj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EE_SRSS1->Sumw2();
  h_DeltaPhil0jj_EE_SRSS2 = new TH2F("h_DeltaPhil0jj_EE_SRSS2", "h_DeltaPhil0jj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EE_SRSS2->Sumw2();
  h_DeltaPhil0jj_MM_SRSS1 = new TH2F("h_DeltaPhil0jj_MM_SRSS1", "h_DeltaPhil0jj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_MM_SRSS1->Sumw2();  
  h_DeltaPhil0jj_MM_SRSS2 = new TH2F("h_DeltaPhil0jj_MM_SRSS2", "h_DeltaPhil0jj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_MM_SRSS2->Sumw2();
  h_DeltaPhil0jj_MM_SRSS3 = new TH2F("h_DeltaPhil0jj_MM_SRSS3", "h_DeltaPhil0jj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_MM_SRSS3->Sumw2();
  h_DeltaPhil0jj_MM_SRSS4 = new TH2F("h_DeltaPhil0jj_MM_SRSS4", "h_DeltaPhil0jj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_MM_SRSS4->Sumw2();
  h_DeltaPhil0jj_EM_SRSS1 = new TH2F("h_DeltaPhil0jj_EM_SRSS1", "h_DeltaPhil0jj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EM_SRSS1->Sumw2();
  h_DeltaPhil0jj_EM_SRSS2 = new TH2F("h_DeltaPhil0jj_EM_SRSS2", "h_DeltaPhil0jj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EM_SRSS2->Sumw2();
  h_DeltaPhil0jj_EE_SROS1 = new TH2F("h_DeltaPhil0jj_EE_SROS1", "h_DeltaPhil0jj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EE_SROS1->Sumw2();
  h_DeltaPhil0jj_MM_SROS1 = new TH2F("h_DeltaPhil0jj_MM_SROS1", "h_DeltaPhil0jj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_MM_SROS1->Sumw2();
  h_DeltaPhil0jj_EM_SROS1 = new TH2F("h_DeltaPhil0jj_EM_SROS1", "h_DeltaPhil0jj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil0jj_EM_SROS1->Sumw2();
  /*--------------------------------------------------------------------------------*/ 
  h_DeltaPhil1jj_EE_SRSS1 = new TH2F("h_DeltaPhil1jj_EE_SRSS1", "h_DeltaPhil1jj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EE_SRSS1->Sumw2();
  h_DeltaPhil1jj_EE_SRSS2 = new TH2F("h_DeltaPhil1jj_EE_SRSS2", "h_DeltaPhil1jj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EE_SRSS2->Sumw2();
  h_DeltaPhil1jj_MM_SRSS1 = new TH2F("h_DeltaPhil1jj_MM_SRSS1", "h_DeltaPhil1jj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_MM_SRSS1->Sumw2();  
  h_DeltaPhil1jj_MM_SRSS2 = new TH2F("h_DeltaPhil1jj_MM_SRSS2", "h_DeltaPhil1jj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_MM_SRSS2->Sumw2();
  h_DeltaPhil1jj_MM_SRSS3 = new TH2F("h_DeltaPhil1jj_MM_SRSS3", "h_DeltaPhil1jj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_MM_SRSS3->Sumw2();
  h_DeltaPhil1jj_MM_SRSS4 = new TH2F("h_DeltaPhil1jj_MM_SRSS4", "h_DeltaPhil1jj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_MM_SRSS4->Sumw2();
  h_DeltaPhil1jj_EM_SRSS1 = new TH2F("h_DeltaPhil1jj_EM_SRSS1", "h_DeltaPhil1jj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EM_SRSS1->Sumw2();
  h_DeltaPhil1jj_EM_SRSS2 = new TH2F("h_DeltaPhil1jj_EM_SRSS2", "h_DeltaPhil1jj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EM_SRSS2->Sumw2();
  h_DeltaPhil1jj_EE_SROS1 = new TH2F("h_DeltaPhil1jj_EE_SROS1", "h_DeltaPhil1jj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EE_SROS1->Sumw2();
  h_DeltaPhil1jj_MM_SROS1 = new TH2F("h_DeltaPhil1jj_MM_SROS1", "h_DeltaPhil1jj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_MM_SROS1->Sumw2();
  h_DeltaPhil1jj_EM_SROS1 = new TH2F("h_DeltaPhil1jj_EM_SROS1", "h_DeltaPhil1jj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaPhil1jj_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_DeltaRlljj_EE_SRSS1 = new TH2F("h_DeltaRlljj_EE_SRSS1", "h_DeltaRlljj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EE_SRSS1->Sumw2();
  h_DeltaRlljj_EE_SRSS2 = new TH2F("h_DeltaRlljj_EE_SRSS2", "h_DeltaRlljj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EE_SRSS2->Sumw2();
  h_DeltaRlljj_MM_SRSS1 = new TH2F("h_DeltaRlljj_MM_SRSS1", "h_DeltaRlljj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_MM_SRSS1->Sumw2();  
  h_DeltaRlljj_MM_SRSS2 = new TH2F("h_DeltaRlljj_MM_SRSS2", "h_DeltaRlljj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_MM_SRSS2->Sumw2();
  h_DeltaRlljj_MM_SRSS3 = new TH2F("h_DeltaRlljj_MM_SRSS3", "h_DeltaRlljj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_MM_SRSS3->Sumw2();
  h_DeltaRlljj_MM_SRSS4 = new TH2F("h_DeltaRlljj_MM_SRSS4", "h_DeltaRlljj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_MM_SRSS4->Sumw2();
  h_DeltaRlljj_EM_SRSS1 = new TH2F("h_DeltaRlljj_EM_SRSS1", "h_DeltaRlljj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EM_SRSS1->Sumw2();
  h_DeltaRlljj_EM_SRSS2 = new TH2F("h_DeltaRlljj_EM_SRSS2", "h_DeltaRlljj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EM_SRSS2->Sumw2();
  h_DeltaRlljj_EE_SROS1 = new TH2F("h_DeltaRlljj_EE_SROS1", "h_DeltaRlljj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EE_SROS1->Sumw2();
  h_DeltaRlljj_MM_SROS1 = new TH2F("h_DeltaRlljj_MM_SROS1", "h_DeltaRlljj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_MM_SROS1->Sumw2();
  h_DeltaRlljj_EM_SROS1 = new TH2F("h_DeltaRlljj_EM_SROS1", "h_DeltaRlljj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaRlljj_EM_SROS1->Sumw2();

    /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtajj_EE_SRSS1 = new TH2F("h_DeltaEtajj_EE_SRSS1", "h_DeltaEtajj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EE_SRSS1->Sumw2();
  h_DeltaEtajj_EE_SRSS2 = new TH2F("h_DeltaEtajj_EE_SRSS2", "h_DeltaEtajj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EE_SRSS2->Sumw2();
  h_DeltaEtajj_MM_SRSS1 = new TH2F("h_DeltaEtajj_MM_SRSS1", "h_DeltaEtajj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_MM_SRSS1->Sumw2();  
  h_DeltaEtajj_MM_SRSS2 = new TH2F("h_DeltaEtajj_MM_SRSS2", "h_DeltaEtajj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_MM_SRSS2->Sumw2();
  h_DeltaEtajj_MM_SRSS3 = new TH2F("h_DeltaEtajj_MM_SRSS3", "h_DeltaEtajj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_MM_SRSS3->Sumw2();
  h_DeltaEtajj_MM_SRSS4 = new TH2F("h_DeltaEtajj_MM_SRSS4", "h_DeltaEtajj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_MM_SRSS4->Sumw2();
  h_DeltaEtajj_EM_SRSS1 = new TH2F("h_DeltaEtajj_EM_SRSS1", "h_DeltaEtajj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EM_SRSS1->Sumw2();
  h_DeltaEtajj_EM_SRSS2 = new TH2F("h_DeltaEtajj_EM_SRSS2", "h_DeltaEtajj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EM_SRSS2->Sumw2();
  h_DeltaEtajj_EE_SROS1 = new TH2F("h_DeltaEtajj_EE_SROS1", "h_DeltaEtajj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EE_SROS1->Sumw2();
  h_DeltaEtajj_MM_SROS1 = new TH2F("h_DeltaEtajj_MM_SROS1", "h_DeltaEtajj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_MM_SROS1->Sumw2();
  h_DeltaEtajj_EM_SROS1 = new TH2F("h_DeltaEtajj_EM_SROS1", "h_DeltaEtajj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtajj_EM_SROS1->Sumw2();  
  
      /*--------------------------------------------------------------------------------*/ 
  h_DeltaEtall_EE_SRSS1 = new TH2F("h_DeltaEtall_EE_SRSS1", "h_DeltaEtall_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EE_SRSS1->Sumw2();
  h_DeltaEtall_EE_SRSS2 = new TH2F("h_DeltaEtall_EE_SRSS2", "h_DeltaEtall_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EE_SRSS2->Sumw2();
  h_DeltaEtall_MM_SRSS1 = new TH2F("h_DeltaEtall_MM_SRSS1", "h_DeltaEtall_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_MM_SRSS1->Sumw2();  
  h_DeltaEtall_MM_SRSS2 = new TH2F("h_DeltaEtall_MM_SRSS2", "h_DeltaEtall_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_MM_SRSS2->Sumw2();
  h_DeltaEtall_MM_SRSS3 = new TH2F("h_DeltaEtall_MM_SRSS3", "h_DeltaEtall_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_MM_SRSS3->Sumw2();
  h_DeltaEtall_MM_SRSS4 = new TH2F("h_DeltaEtall_MM_SRSS4", "h_DeltaEtall_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_MM_SRSS4->Sumw2();
  h_DeltaEtall_EM_SRSS1 = new TH2F("h_DeltaEtall_EM_SRSS1", "h_DeltaEtall_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EM_SRSS1->Sumw2();
  h_DeltaEtall_EM_SRSS2 = new TH2F("h_DeltaEtall_EM_SRSS2", "h_DeltaEtall_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EM_SRSS2->Sumw2();
  h_DeltaEtall_EE_SROS1 = new TH2F("h_DeltaEtall_EE_SROS1", "h_DeltaEtall_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EE_SROS1->Sumw2();
  h_DeltaEtall_MM_SROS1 = new TH2F("h_DeltaEtall_MM_SROS1", "h_DeltaEtall_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_MM_SROS1->Sumw2();
  h_DeltaEtall_EM_SROS1 = new TH2F("h_DeltaEtall_EM_SROS1", "h_DeltaEtall_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaEtall_EM_SROS1->Sumw2();  


  /*--------------------------------------------------------------------------------*/ 
  h_mTll_EE_SRSS1 = new TH2F("h_mTll_EE_SRSS1", "h_mTll_EE_SRSS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_EE_SRSS1->Sumw2();
  h_mTll_EE_SRSS2 = new TH2F("h_mTll_EE_SRSS2", "h_mTll_EE_SRSS2", 1000, 0, 1000 ,130, 0, 129); h_mTll_EE_SRSS2->Sumw2();
  h_mTll_MM_SRSS1 = new TH2F("h_mTll_MM_SRSS1", "h_mTll_MM_SRSS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_MM_SRSS1->Sumw2();  
  h_mTll_MM_SRSS2 = new TH2F("h_mTll_MM_SRSS2", "h_mTll_MM_SRSS2", 1000, 0, 1000 ,130, 0, 129); h_mTll_MM_SRSS2->Sumw2();
  h_mTll_MM_SRSS3 = new TH2F("h_mTll_MM_SRSS3", "h_mTll_MM_SRSS3", 1000, 0, 1000 ,130, 0, 129); h_mTll_MM_SRSS3->Sumw2();
  h_mTll_MM_SRSS4 = new TH2F("h_mTll_MM_SRSS4", "h_mTll_MM_SRSS4", 1000, 0, 1000 ,130, 0, 129); h_mTll_MM_SRSS4->Sumw2();
  h_mTll_EM_SRSS1 = new TH2F("h_mTll_EM_SRSS1", "h_mTll_EM_SRSS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_EM_SRSS1->Sumw2();
  h_mTll_EM_SRSS2 = new TH2F("h_mTll_EM_SRSS2", "h_mTll_EM_SRSS2", 1000, 0, 1000 ,130, 0, 129); h_mTll_EM_SRSS2->Sumw2();
  h_mTll_EE_SROS1 = new TH2F("h_mTll_EE_SROS1", "h_mTll_EE_SROS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_EE_SROS1->Sumw2();
  h_mTll_MM_SROS1 = new TH2F("h_mTll_MM_SROS1", "h_mTll_MM_SROS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_MM_SROS1->Sumw2();
  h_mTll_EM_SROS1 = new TH2F("h_mTll_EM_SROS1", "h_mTll_EM_SROS1", 1000, 0, 1000 ,130, 0, 129); h_mTll_EM_SROS1->Sumw2();


  /*--------------------------------------------------------------------------------*/ 
  h_mMETll_EE_SRSS1 = new TH2F("h_mMETll_EE_SRSS1", "h_mMETll_EE_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_EE_SRSS1->Sumw2();
  h_mMETll_EE_SRSS2 = new TH2F("h_mMETll_EE_SRSS2", "h_mMETll_EE_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mMETll_EE_SRSS2->Sumw2();
  h_mMETll_MM_SRSS1 = new TH2F("h_mMETll_MM_SRSS1", "h_mMETll_MM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_MM_SRSS1->Sumw2();  
  h_mMETll_MM_SRSS2 = new TH2F("h_mMETll_MM_SRSS2", "h_mMETll_MM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mMETll_MM_SRSS2->Sumw2();
  h_mMETll_MM_SRSS3 = new TH2F("h_mMETll_MM_SRSS3", "h_mMETll_MM_SRSS3", 100, 0, 500 ,130, 0, 129);  h_mMETll_MM_SRSS3->Sumw2();
  h_mMETll_MM_SRSS4 = new TH2F("h_mMETll_MM_SRSS4", "h_mMETll_MM_SRSS4", 100, 0, 500 ,130, 0, 129);  h_mMETll_MM_SRSS4->Sumw2();
  h_mMETll_EM_SRSS1 = new TH2F("h_mMETll_EM_SRSS1", "h_mMETll_EM_SRSS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_EM_SRSS1->Sumw2();
  h_mMETll_EM_SRSS2 = new TH2F("h_mMETll_EM_SRSS2", "h_mMETll_EM_SRSS2", 100, 0, 500 ,130, 0, 129);  h_mMETll_EM_SRSS2->Sumw2();
  h_mMETll_EE_SROS1 = new TH2F("h_mMETll_EE_SROS1", "h_mMETll_EE_SROS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_EE_SROS1->Sumw2();
  h_mMETll_MM_SROS1 = new TH2F("h_mMETll_MM_SROS1", "h_mMETll_MM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_MM_SROS1->Sumw2();
  h_mMETll_EM_SROS1 = new TH2F("h_mMETll_EM_SROS1", "h_mMETll_EM_SROS1", 100, 0, 500 ,130, 0, 129);  h_mMETll_EM_SROS1->Sumw2();

  /*--------------------------------------------------------------------------------*/ 
  h_DeltaYjj_EE_SRSS1 = new TH2F("h_DeltaYjj_EE_SRSS1", "h_DeltaYjj_EE_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EE_SRSS1->Sumw2();
  h_DeltaYjj_EE_SRSS2 = new TH2F("h_DeltaYjj_EE_SRSS2", "h_DeltaYjj_EE_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EE_SRSS2->Sumw2();
  h_DeltaYjj_MM_SRSS1 = new TH2F("h_DeltaYjj_MM_SRSS1", "h_DeltaYjj_MM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_MM_SRSS1->Sumw2();  
  h_DeltaYjj_MM_SRSS2 = new TH2F("h_DeltaYjj_MM_SRSS2", "h_DeltaYjj_MM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_MM_SRSS2->Sumw2();
  h_DeltaYjj_MM_SRSS3 = new TH2F("h_DeltaYjj_MM_SRSS3", "h_DeltaYjj_MM_SRSS3", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_MM_SRSS3->Sumw2();
  h_DeltaYjj_MM_SRSS4 = new TH2F("h_DeltaYjj_MM_SRSS4", "h_DeltaYjj_MM_SRSS4", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_MM_SRSS4->Sumw2();
  h_DeltaYjj_EM_SRSS1 = new TH2F("h_DeltaYjj_EM_SRSS1", "h_DeltaYjj_EM_SRSS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EM_SRSS1->Sumw2();
  h_DeltaYjj_EM_SRSS2 = new TH2F("h_DeltaYjj_EM_SRSS2", "h_DeltaYjj_EM_SRSS2", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EM_SRSS2->Sumw2();
  h_DeltaYjj_EE_SROS1 = new TH2F("h_DeltaYjj_EE_SROS1", "h_DeltaYjj_EE_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EE_SROS1->Sumw2();
  h_DeltaYjj_MM_SROS1 = new TH2F("h_DeltaYjj_MM_SROS1", "h_DeltaYjj_MM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_MM_SROS1->Sumw2();
  h_DeltaYjj_EM_SROS1 = new TH2F("h_DeltaYjj_EM_SROS1", "h_DeltaYjj_EM_SROS1", 70, 0, 7 ,130, 0, 129);  h_DeltaYjj_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_D0_branch_l0_EE_SRSS1 = new TH2F("h_D0_branch_l0_EE_SRSS1", "h_D0_branch_l0_EE_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EE_SRSS1->Sumw2();
  h_D0_branch_l0_EE_SRSS2 = new TH2F("h_D0_branch_l0_EE_SRSS2", "h_D0_branch_l0_EE_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EE_SRSS2->Sumw2();
  h_D0_branch_l0_MM_SRSS1 = new TH2F("h_D0_branch_l0_MM_SRSS1", "h_D0_branch_l0_MM_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_MM_SRSS1->Sumw2();  
  h_D0_branch_l0_MM_SRSS2 = new TH2F("h_D0_branch_l0_MM_SRSS2", "h_D0_branch_l0_MM_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_MM_SRSS2->Sumw2();
  h_D0_branch_l0_MM_SRSS3 = new TH2F("h_D0_branch_l0_MM_SRSS3", "h_D0_branch_l0_MM_SRSS3", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_MM_SRSS3->Sumw2();
  h_D0_branch_l0_MM_SRSS4 = new TH2F("h_D0_branch_l0_MM_SRSS4", "h_D0_branch_l0_MM_SRSS4", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_MM_SRSS4->Sumw2();
  h_D0_branch_l0_EM_SRSS1 = new TH2F("h_D0_branch_l0_EM_SRSS1", "h_D0_branch_l0_EM_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EM_SRSS1->Sumw2();
  h_D0_branch_l0_EM_SRSS2 = new TH2F("h_D0_branch_l0_EM_SRSS2", "h_D0_branch_l0_EM_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EM_SRSS2->Sumw2();
  h_D0_branch_l0_EE_SROS1 = new TH2F("h_D0_branch_l0_EE_SROS1", "h_D0_branch_l0_EE_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EE_SROS1->Sumw2();
  h_D0_branch_l0_MM_SROS1 = new TH2F("h_D0_branch_l0_MM_SROS1", "h_D0_branch_l0_MM_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_MM_SROS1->Sumw2();
  h_D0_branch_l0_EM_SROS1 = new TH2F("h_D0_branch_l0_EM_SROS1", "h_D0_branch_l0_EM_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l0_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_D0_branch_l1_EE_SRSS1 = new TH2F("h_D0_branch_l1_EE_SRSS1", "h_D0_branch_l1_EE_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EE_SRSS1->Sumw2();
  h_D0_branch_l1_EE_SRSS2 = new TH2F("h_D0_branch_l1_EE_SRSS2", "h_D0_branch_l1_EE_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EE_SRSS2->Sumw2();
  h_D0_branch_l1_MM_SRSS1 = new TH2F("h_D0_branch_l1_MM_SRSS1", "h_D0_branch_l1_MM_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_MM_SRSS1->Sumw2();  
  h_D0_branch_l1_MM_SRSS2 = new TH2F("h_D0_branch_l1_MM_SRSS2", "h_D0_branch_l1_MM_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_MM_SRSS2->Sumw2();
  h_D0_branch_l1_MM_SRSS3 = new TH2F("h_D0_branch_l1_MM_SRSS3", "h_D0_branch_l1_MM_SRSS3", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_MM_SRSS3->Sumw2();
  h_D0_branch_l1_MM_SRSS4 = new TH2F("h_D0_branch_l1_MM_SRSS4", "h_D0_branch_l1_MM_SRSS4", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_MM_SRSS4->Sumw2();
  h_D0_branch_l1_EM_SRSS1 = new TH2F("h_D0_branch_l1_EM_SRSS1", "h_D0_branch_l1_EM_SRSS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EM_SRSS1->Sumw2();
  h_D0_branch_l1_EM_SRSS2 = new TH2F("h_D0_branch_l1_EM_SRSS2", "h_D0_branch_l1_EM_SRSS2", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EM_SRSS2->Sumw2();
  h_D0_branch_l1_EE_SROS1 = new TH2F("h_D0_branch_l1_EE_SROS1", "h_D0_branch_l1_EE_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EE_SROS1->Sumw2();
  h_D0_branch_l1_MM_SROS1 = new TH2F("h_D0_branch_l1_MM_SROS1", "h_D0_branch_l1_MM_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_MM_SROS1->Sumw2();
  h_D0_branch_l1_EM_SROS1 = new TH2F("h_D0_branch_l1_EM_SROS1", "h_D0_branch_l1_EM_SROS1", 1200, -1.5, 1.5 ,130, 0, 129);  h_D0_branch_l1_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_D0Signif_branch_l0_EE_SRSS1 = new TH2F("h_D0Signif_branch_l0_EE_SRSS1", "h_D0Signif_branch_l0_EE_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EE_SRSS1->Sumw2();
  h_D0Signif_branch_l0_EE_SRSS2 = new TH2F("h_D0Signif_branch_l0_EE_SRSS2", "h_D0Signif_branch_l0_EE_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EE_SRSS2->Sumw2();
  h_D0Signif_branch_l0_MM_SRSS1 = new TH2F("h_D0Signif_branch_l0_MM_SRSS1", "h_D0Signif_branch_l0_MM_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_MM_SRSS1->Sumw2();  
  h_D0Signif_branch_l0_MM_SRSS2 = new TH2F("h_D0Signif_branch_l0_MM_SRSS2", "h_D0Signif_branch_l0_MM_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_MM_SRSS2->Sumw2();
  h_D0Signif_branch_l0_MM_SRSS3 = new TH2F("h_D0Signif_branch_l0_MM_SRSS3", "h_D0Signif_branch_l0_MM_SRSS3", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_MM_SRSS3->Sumw2();
  h_D0Signif_branch_l0_MM_SRSS4 = new TH2F("h_D0Signif_branch_l0_MM_SRSS4", "h_D0Signif_branch_l0_MM_SRSS4", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_MM_SRSS4->Sumw2();
  h_D0Signif_branch_l0_EM_SRSS1 = new TH2F("h_D0Signif_branch_l0_EM_SRSS1", "h_D0Signif_branch_l0_EM_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EM_SRSS1->Sumw2();
  h_D0Signif_branch_l0_EM_SRSS2 = new TH2F("h_D0Signif_branch_l0_EM_SRSS2", "h_D0Signif_branch_l0_EM_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EM_SRSS2->Sumw2();
  h_D0Signif_branch_l0_EE_SROS1 = new TH2F("h_D0Signif_branch_l0_EE_SROS1", "h_D0Signif_branch_l0_EE_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EE_SROS1->Sumw2();
  h_D0Signif_branch_l0_MM_SROS1 = new TH2F("h_D0Signif_branch_l0_MM_SROS1", "h_D0Signif_branch_l0_MM_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_MM_SROS1->Sumw2();
  h_D0Signif_branch_l0_EM_SROS1 = new TH2F("h_D0Signif_branch_l0_EM_SROS1", "h_D0Signif_branch_l0_EM_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l0_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
  h_D0Signif_branch_l1_EE_SRSS1 = new TH2F("h_D0Signif_branch_l1_EE_SRSS1", "h_D0Signif_branch_l1_EE_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EE_SRSS1->Sumw2();
  h_D0Signif_branch_l1_EE_SRSS2 = new TH2F("h_D0Signif_branch_l1_EE_SRSS2", "h_D0Signif_branch_l1_EE_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EE_SRSS2->Sumw2();
  h_D0Signif_branch_l1_MM_SRSS1 = new TH2F("h_D0Signif_branch_l1_MM_SRSS1", "h_D0Signif_branch_l1_MM_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_MM_SRSS1->Sumw2();  
  h_D0Signif_branch_l1_MM_SRSS2 = new TH2F("h_D0Signif_branch_l1_MM_SRSS2", "h_D0Signif_branch_l1_MM_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_MM_SRSS2->Sumw2();
  h_D0Signif_branch_l1_MM_SRSS3 = new TH2F("h_D0Signif_branch_l1_MM_SRSS3", "h_D0Signif_branch_l1_MM_SRSS3", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_MM_SRSS3->Sumw2();
  h_D0Signif_branch_l1_MM_SRSS4 = new TH2F("h_D0Signif_branch_l1_MM_SRSS4", "h_D0Signif_branch_l1_MM_SRSS4", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_MM_SRSS4->Sumw2();
  h_D0Signif_branch_l1_EM_SRSS1 = new TH2F("h_D0Signif_branch_l1_EM_SRSS1", "h_D0Signif_branch_l1_EM_SRSS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EM_SRSS1->Sumw2();
  h_D0Signif_branch_l1_EM_SRSS2 = new TH2F("h_D0Signif_branch_l1_EM_SRSS2", "h_D0Signif_branch_l1_EM_SRSS2", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EM_SRSS2->Sumw2();
  h_D0Signif_branch_l1_EE_SROS1 = new TH2F("h_D0Signif_branch_l1_EE_SROS1", "h_D0Signif_branch_l1_EE_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EE_SROS1->Sumw2();
  h_D0Signif_branch_l1_MM_SROS1 = new TH2F("h_D0Signif_branch_l1_MM_SROS1", "h_D0Signif_branch_l1_MM_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_MM_SROS1->Sumw2();
  h_D0Signif_branch_l1_EM_SROS1 = new TH2F("h_D0Signif_branch_l1_EM_SROS1", "h_D0Signif_branch_l1_EM_SROS1", 200, -10, 10 ,130, 0, 129);  h_D0Signif_branch_l1_EM_SROS1->Sumw2();
  
  /*--------------------------------------------------------------------------------*/ 
}
 void TSelector_SusyNtuple::defineHistos_sysUncert(){ 
  cutflow_EE_sysUncert = new TH2F("cutflow_EE_sysUncert", "cutflow_EE_sysUncert" ,130, 0, 129, 60, 0, 59); cutflow_EE_sysUncert->Sumw2();
  cutflow_MM_sysUncert = new TH2F("cutflow_MM_sysUncert", "cutflow_MM_sysUncert" ,130, 0, 129, 60, 0, 59); cutflow_MM_sysUncert->Sumw2();
  cutflow_EM_sysUncert = new TH2F("cutflow_EM_sysUncert", "cutflow_EM_sysUncert" ,130, 0, 129, 60, 0, 59); cutflow_EM_sysUncert->Sumw2();
  
  

}


void TSelector_SusyNtuple::writeHistos(){

  bool EE_SRSS1 = true;
  bool EE_SRSS2 = false;
  bool MM_SRSS1 = true;
  bool MM_SRSS2 = false;
  bool MM_SRSS3 = false;
  bool MM_SRSS4 = false;
  bool EM_SRSS1 = true;
  bool EM_SRSS2 = false;
  bool EE_SROS1 = false;
  bool MM_SROS1 = false;
  bool EM_SROS1 = false;
  
    h_storeSumwMcid->Write();
    
    if(EE_SRSS1) h_DeltaRLeptons_EE_SRSS1->Write();
    if(EE_SRSS2) h_DeltaRLeptons_EE_SRSS2->Write();
    if(MM_SRSS1) h_DeltaRLeptons_MM_SRSS1->Write();
    if(MM_SRSS2) h_DeltaRLeptons_MM_SRSS2->Write();
    if(MM_SRSS3) h_DeltaRLeptons_MM_SRSS3->Write();
    if(MM_SRSS4) h_DeltaRLeptons_MM_SRSS4->Write();
    if(EM_SRSS1) h_DeltaRLeptons_EM_SRSS1->Write();
    if(EM_SRSS2) h_DeltaRLeptons_EM_SRSS2->Write();
    if(EE_SROS1) h_DeltaRLeptons_EE_SROS1->Write();
    if(MM_SROS1) h_DeltaRLeptons_MM_SROS1->Write();
    if(EM_SROS1) h_DeltaRLeptons_EM_SROS1->Write();
    
    if(EE_SRSS1) h_pTl0_EE_SRSS1->Write();
    if(EE_SRSS2) h_pTl0_EE_SRSS2->Write();
    if(MM_SRSS1) h_pTl0_MM_SRSS1->Write();
    if(MM_SRSS2) h_pTl0_MM_SRSS2->Write();
    if(MM_SRSS3) h_pTl0_MM_SRSS3->Write();
    if(MM_SRSS4) h_pTl0_MM_SRSS4->Write();
    if(EM_SRSS1) h_pTl0_EM_SRSS1->Write();
    if(EM_SRSS2) h_pTl0_EM_SRSS2->Write();
    if(EE_SROS1) h_pTl0_EE_SROS1->Write();
    if(MM_SROS1) h_pTl0_MM_SROS1->Write();
    if(EM_SROS1) h_pTl0_EM_SROS1->Write();
    
    if(EE_SRSS1) h_pTl0_raw_EE_SRSS1->Write();
    if(MM_SRSS1) h_pTl0_raw_MM_SRSS1->Write();
    if(EM_SRSS1) h_pTl0_raw_EM_SRSS1->Write(); 
    
    /*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_pTl1_EE_SRSS1->Write();
    if(EE_SRSS2) h_pTl1_EE_SRSS2->Write();
    if(MM_SRSS1) h_pTl1_MM_SRSS1->Write();
    if(MM_SRSS2) h_pTl1_MM_SRSS2->Write();
    if(MM_SRSS3) h_pTl1_MM_SRSS3->Write();
    if(MM_SRSS4) h_pTl1_MM_SRSS4->Write();
    if(EM_SRSS1) h_pTl1_EM_SRSS1->Write();
    if(EM_SRSS2) h_pTl1_EM_SRSS2->Write();
    if(EE_SROS1) h_pTl1_EE_SROS1->Write();
    if(MM_SROS1) h_pTl1_MM_SROS1->Write();
    if(EM_SROS1) h_pTl1_EM_SROS1->Write();
    
      /*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_pTj0_EE_SRSS1->Write();
    if(EE_SRSS2) h_pTj0_EE_SRSS2->Write();
    if(MM_SRSS1) h_pTj0_MM_SRSS1->Write();
    if(MM_SRSS2) h_pTj0_MM_SRSS2->Write();
    if(MM_SRSS3) h_pTj0_MM_SRSS3->Write();
    if(MM_SRSS4) h_pTj0_MM_SRSS4->Write();
    if(EM_SRSS1) h_pTj0_EM_SRSS1->Write();
    if(EM_SRSS2) h_pTj0_EM_SRSS2->Write();
    if(EE_SROS1) h_pTj0_EE_SROS1->Write();
    if(MM_SROS1) h_pTj0_MM_SROS1->Write();
    if(EM_SROS1) h_pTj0_EM_SROS1->Write();
    
    /*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_pTj1_EE_SRSS1->Write();
    if(EE_SRSS2) h_pTj1_EE_SRSS2->Write();
    if(MM_SRSS1) h_pTj1_MM_SRSS1->Write();  
    if(MM_SRSS2) h_pTj1_MM_SRSS2->Write();
    if(MM_SRSS3) h_pTj1_MM_SRSS3->Write();
    if(MM_SRSS4) h_pTj1_MM_SRSS4->Write();
    if(EM_SRSS1) h_pTj1_EM_SRSS1->Write();
    if(EM_SRSS2) h_pTj1_EM_SRSS2->Write();
    if(EE_SROS1) h_pTj1_EE_SROS1->Write();
    if(MM_SROS1) h_pTj1_MM_SROS1->Write();
    if(EM_SROS1) h_pTj1_EM_SROS1->Write();
    
    /*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_mll_EE_SRSS1->Write();
    if(EE_SRSS2) h_mll_EE_SRSS2->Write();
    if(MM_SRSS1) h_mll_MM_SRSS1->Write(); 
    if(MM_SRSS2) h_mll_MM_SRSS2->Write();
    if(MM_SRSS3) h_mll_MM_SRSS3->Write();
    if(MM_SRSS4) h_mll_MM_SRSS4->Write();
    if(EM_SRSS1) h_mll_EM_SRSS1->Write();
    if(EM_SRSS2) h_mll_EM_SRSS2->Write();
    if(EE_SROS1) h_mll_EE_SROS1->Write();
    if(MM_SROS1) h_mll_MM_SROS1->Write();
    if(EM_SROS1) h_mll_EM_SROS1->Write();
    /*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_METrel_EE_SRSS1->Write();
    if(EE_SRSS2) h_METrel_EE_SRSS2->Write();
    if(MM_SRSS1) h_METrel_MM_SRSS1->Write();  
    if(MM_SRSS2) h_METrel_MM_SRSS2->Write();  
    if(MM_SRSS3) h_METrel_MM_SRSS3->Write();
    if(MM_SRSS4) h_METrel_MM_SRSS4->Write();
    if(EM_SRSS1) h_METrel_EM_SRSS1->Write();
    if(EM_SRSS2) h_METrel_EM_SRSS2->Write();
    if(EE_SROS1) h_METrel_EE_SROS1->Write();
    if(MM_SROS1) h_METrel_MM_SROS1->Write();
    if(EM_SROS1) h_METrel_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_MET_EE_SRSS1->Write();
    if(EE_SRSS2) h_MET_EE_SRSS2->Write();
    if(MM_SRSS1) h_MET_MM_SRSS1->Write();  
    if(MM_SRSS2) h_MET_MM_SRSS2->Write();  
    if(MM_SRSS3) h_MET_MM_SRSS3->Write();
    if(MM_SRSS4) h_MET_MM_SRSS4->Write();
    if(EM_SRSS1) h_MET_EM_SRSS1->Write();
    if(EM_SRSS2) h_MET_EM_SRSS2->Write();
    if(EE_SROS1) h_MET_EE_SROS1->Write();
    if(MM_SROS1) h_MET_MM_SROS1->Write();
    if(EM_SROS1) h_MET_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_HT_EE_SRSS1->Write();
    if(EE_SRSS2) h_HT_EE_SRSS2->Write();
    if(MM_SRSS1) h_HT_MM_SRSS1->Write();  
    if(MM_SRSS2) h_HT_MM_SRSS2->Write();
    if(MM_SRSS3) h_HT_MM_SRSS3->Write();
    if(MM_SRSS4) h_HT_MM_SRSS4->Write();
    if(EM_SRSS1) h_HT_EM_SRSS1->Write();
    if(EM_SRSS2) h_HT_EM_SRSS2->Write();
    if(EE_SROS1) h_HT_EE_SROS1->Write();
    if(MM_SROS1) h_HT_MM_SROS1->Write();
    if(EM_SROS1) h_HT_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_mWWt_EE_SRSS1->Write();
    if(EE_SRSS2) h_mWWt_EE_SRSS2->Write();
    if(MM_SRSS1) h_mWWt_MM_SRSS1->Write();  
    if(MM_SRSS2) h_mWWt_MM_SRSS2->Write();
    if(MM_SRSS3) h_mWWt_MM_SRSS3->Write();
    if(MM_SRSS4) h_mWWt_MM_SRSS4->Write();
    if(EM_SRSS1) h_mWWt_EM_SRSS1->Write();
    if(EM_SRSS2) h_mWWt_EM_SRSS2->Write();
    if(EE_SROS1) h_mWWt_EE_SROS1->Write();
    if(MM_SROS1) h_mWWt_MM_SROS1->Write();
    if(EM_SROS1) h_mWWt_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_mTlmin_EE_SRSS1->Write();
    if(EE_SRSS2) h_mTlmin_EE_SRSS2->Write();
    if(MM_SRSS1) h_mTlmin_MM_SRSS1->Write();  
    if(MM_SRSS2) h_mTlmin_MM_SRSS2->Write();
    if(MM_SRSS3) h_mTlmin_MM_SRSS3->Write();
    if(MM_SRSS4) h_mTlmin_MM_SRSS4->Write();
    if(EM_SRSS1) h_mTlmin_EM_SRSS1->Write();
    if(EM_SRSS2) h_mTlmin_EM_SRSS2->Write();
    if(EE_SROS1) h_mTlmin_EE_SROS1->Write();
    if(MM_SROS1) h_mTlmin_MM_SROS1->Write();
    if(EM_SROS1) h_mTlmin_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_mTlmax_EE_SRSS1->Write();
    if(EE_SRSS2) h_mTlmax_EE_SRSS2->Write();
    if(MM_SRSS1) h_mTlmax_MM_SRSS1->Write();  
    if(MM_SRSS2) h_mTlmax_MM_SRSS2->Write();
    if(MM_SRSS3) h_mTlmax_MM_SRSS3->Write();
    if(MM_SRSS4) h_mTlmax_MM_SRSS4->Write();
    if(EM_SRSS1) h_mTlmax_EM_SRSS1->Write();
    if(EM_SRSS2) h_mTlmax_EM_SRSS2->Write();
    if(EE_SROS1) h_mTlmax_EE_SROS1->Write();
    if(MM_SROS1) h_mTlmax_MM_SROS1->Write();
    if(EM_SROS1) h_mTlmax_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_meff_EE_SRSS1->Write();
    if(EE_SRSS2) h_meff_EE_SRSS2->Write();
    if(MM_SRSS1) h_meff_MM_SRSS1->Write();
    if(MM_SRSS2) h_meff_MM_SRSS2->Write();
    if(MM_SRSS3) h_meff_MM_SRSS3->Write();
    if(MM_SRSS4) h_meff_MM_SRSS4->Write();
    if(EM_SRSS1) h_meff_EM_SRSS1->Write();
    if(EM_SRSS2) h_meff_EM_SRSS2->Write();
    if(EE_SROS1) h_meff_EE_SROS1->Write();
    if(MM_SROS1) h_meff_MM_SROS1->Write();
    if(EM_SROS1) h_meff_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    
    if(EE_SRSS1) h_mT2_EE_SRSS1->Write();
    if(EE_SRSS2) h_mT2_EE_SRSS2->Write();
    if(MM_SRSS1) h_mT2_MM_SRSS1->Write();
    if(MM_SRSS2) h_mT2_MM_SRSS2->Write();  
    if(MM_SRSS3) h_mT2_MM_SRSS3->Write();
    if(MM_SRSS4) h_mT2_MM_SRSS4->Write();
    if(EM_SRSS1) h_mT2_EM_SRSS1->Write();
    if(EM_SRSS2) h_mT2_EM_SRSS2->Write();
    if(EE_SROS1) h_mT2_EE_SROS1->Write();
    if(MM_SROS1) h_mT2_MM_SROS1->Write();
    if(EM_SROS1) h_mT2_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    
    if(EE_SRSS1) h_mT2J_EE_SRSS1->Write();
    if(EE_SRSS2) h_mT2J_EE_SRSS2->Write();
    if(MM_SRSS1) h_mT2J_MM_SRSS1->Write();
    if(MM_SRSS2) h_mT2J_MM_SRSS2->Write();  
    if(MM_SRSS3) h_mT2J_MM_SRSS3->Write();
    if(MM_SRSS4) h_mT2J_MM_SRSS4->Write();
    if(EM_SRSS1) h_mT2J_EM_SRSS1->Write();
    if(EM_SRSS2) h_mT2J_EM_SRSS2->Write();
    if(EE_SROS1) h_mT2J_EE_SROS1->Write();
    if(MM_SROS1) h_mT2J_MM_SROS1->Write();
    if(EM_SROS1) h_mT2J_EM_SROS1->Write();          
/*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_mjj_EE_SRSS1->Write();
    if(EE_SRSS2) h_mjj_EE_SRSS2->Write();
    if(MM_SRSS1) h_mjj_MM_SRSS1->Write();  
    if(MM_SRSS2) h_mjj_MM_SRSS2->Write();
    if(MM_SRSS3) h_mjj_MM_SRSS3->Write();
    if(MM_SRSS4) h_mjj_MM_SRSS4->Write();
    if(EM_SRSS1) h_mjj_EM_SRSS1->Write();
    if(EM_SRSS2) h_mjj_EM_SRSS2->Write();
    if(EE_SROS1) h_mjj_EE_SROS1->Write();
    if(MM_SROS1) h_mjj_MM_SROS1->Write();
    if(EM_SROS1) h_mjj_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_DeltaPhiMETll_EE_SRSS1->Write();
    if(EE_SRSS2) h_DeltaPhiMETll_EE_SRSS2->Write();
    if(MM_SRSS1) h_DeltaPhiMETll_MM_SRSS1->Write();  
    if(MM_SRSS2) h_DeltaPhiMETll_MM_SRSS2->Write();
    if(MM_SRSS3) h_DeltaPhiMETll_MM_SRSS3->Write();
    if(MM_SRSS4) h_DeltaPhiMETll_MM_SRSS4->Write();
    if(EM_SRSS1) h_DeltaPhiMETll_EM_SRSS1->Write();
    if(EM_SRSS2) h_DeltaPhiMETll_EM_SRSS2->Write();
    if(EE_SROS1) h_DeltaPhiMETll_EE_SROS1->Write();
    if(MM_SROS1) h_DeltaPhiMETll_MM_SROS1->Write();
    if(EM_SROS1) h_DeltaPhiMETll_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
    if(EE_SRSS1) h_DeltaPhill_EE_SRSS1->Write();
    if(EE_SRSS2) h_DeltaPhill_EE_SRSS2->Write();
    if(MM_SRSS1) h_DeltaPhill_MM_SRSS1->Write();  
    if(MM_SRSS2) h_DeltaPhill_MM_SRSS2->Write();
    if(MM_SRSS3) h_DeltaPhill_MM_SRSS3->Write();
    if(MM_SRSS4) h_DeltaPhill_MM_SRSS4->Write();
    if(EM_SRSS1) h_DeltaPhill_EM_SRSS1->Write();
    if(EM_SRSS2) h_DeltaPhill_EM_SRSS2->Write();
    if(EE_SROS1) h_DeltaPhill_EE_SROS1->Write();
    if(MM_SROS1) h_DeltaPhill_MM_SROS1->Write();
    if(EM_SROS1) h_DeltaPhill_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_NBJets_EE_SRSS1->Write();
    if(EE_SRSS2) h_NBJets_EE_SRSS2->Write();
    if(MM_SRSS1) h_NBJets_MM_SRSS1->Write();  
    if(MM_SRSS2) h_NBJets_MM_SRSS2->Write();
    if(MM_SRSS3) h_NBJets_MM_SRSS3->Write();
    if(MM_SRSS4) h_NBJets_MM_SRSS4->Write();
    if(EM_SRSS1) h_NBJets_EM_SRSS1->Write();
    if(EM_SRSS2) h_NBJets_EM_SRSS2->Write();
    if(EE_SROS1) h_NBJets_EE_SROS1->Write();
    if(MM_SROS1) h_NBJets_MM_SROS1->Write();
    if(EM_SROS1) h_NBJets_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_NCJets_EE_SRSS1->Write();
    if(EE_SRSS2) h_NCJets_EE_SRSS2->Write();
    if(MM_SRSS1) h_NCJets_MM_SRSS1->Write();  
    if(MM_SRSS2) h_NCJets_MM_SRSS2->Write();
    if(MM_SRSS3) h_NCJets_MM_SRSS3->Write();
    if(MM_SRSS4) h_NCJets_MM_SRSS4->Write();
    if(EM_SRSS1) h_NCJets_EM_SRSS1->Write();
    if(EM_SRSS2) h_NCJets_EM_SRSS2->Write();
    if(EE_SROS1) h_NCJets_EE_SROS1->Write();
    if(MM_SROS1) h_NCJets_MM_SROS1->Write();
    if(EM_SROS1) h_NCJets_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/ 
    if(EE_SRSS1) h_NFJets_EE_SRSS1->Write();
    if(EE_SRSS2) h_NFJets_EE_SRSS2->Write();
    if(MM_SRSS1) h_NFJets_MM_SRSS1->Write();  
    if(MM_SRSS2) h_NFJets_MM_SRSS2->Write();
    if(MM_SRSS3) h_NFJets_MM_SRSS3->Write();
    if(MM_SRSS4) h_NFJets_MM_SRSS4->Write();
    if(EM_SRSS1) h_NFJets_EM_SRSS1->Write();
    if(EM_SRSS2) h_NFJets_EM_SRSS2->Write();
    if(EE_SROS1) h_NFJets_EE_SROS1->Write();
    if(MM_SROS1) h_NFJets_MM_SROS1->Write();
    if(EM_SROS1) h_NFJets_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/     
 
    if(EE_SRSS1) h_mZTT_mmc_EE_SRSS1->Write();
    if(EE_SRSS2) h_mZTT_mmc_EE_SRSS2->Write();
    if(MM_SRSS1) h_mZTT_mmc_MM_SRSS1->Write();
    if(MM_SRSS2) h_mZTT_mmc_MM_SRSS2->Write();
    if(MM_SRSS3) h_mZTT_mmc_MM_SRSS3->Write();
    if(MM_SRSS4) h_mZTT_mmc_MM_SRSS4->Write();
    if(EM_SRSS1) h_mZTT_mmc_EM_SRSS1->Write();
    if(EM_SRSS2) h_mZTT_mmc_EM_SRSS2->Write();
    if(EE_SROS1) h_mZTT_mmc_EE_SROS1->Write();
    if(MM_SROS1) h_mZTT_mmc_MM_SROS1->Write();
    if(EM_SROS1) h_mZTT_mmc_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/  
    if(EE_SRSS1) h_mZTT_coll_EE_SRSS1->Write();
    if(EE_SRSS2) h_mZTT_coll_EE_SRSS2->Write();
    if(MM_SRSS1) h_mZTT_coll_MM_SRSS1->Write();
    if(MM_SRSS2) h_mZTT_coll_MM_SRSS2->Write();
    if(MM_SRSS3) h_mZTT_coll_MM_SRSS3->Write();
    if(MM_SRSS4) h_mZTT_coll_MM_SRSS4->Write();    
    if(EM_SRSS1) h_mZTT_coll_EM_SRSS1->Write();   
    if(EM_SRSS2) h_mZTT_coll_EM_SRSS2->Write();   
    if(EE_SROS1) h_mZTT_coll_EE_SROS1->Write();   
    if(MM_SROS1) h_mZTT_coll_MM_SROS1->Write();   
    if(EM_SROS1) h_mZTT_coll_EM_SROS1->Write();   
//     ---------------------------  
    
    
  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhijj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhijj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhijj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhijj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhijj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhijj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhijj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhijj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhijj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhijj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhijj_EM_SROS1->Write(); 
  
  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_pTjj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_pTjj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_pTjj_MM_SRSS1->Write(); 
  if(MM_SRSS2) h_pTjj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_pTjj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_pTjj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_pTjj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_pTjj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_pTjj_EE_SROS1->Write(); 
  if(MM_SROS1) h_pTjj_MM_SROS1->Write(); 
  if(EM_SROS1) h_pTjj_EM_SROS1->Write(); 

  /*----------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_pTll_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_pTll_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_pTll_MM_SRSS1->Write();   
  if(MM_SRSS2) h_pTll_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_pTll_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_pTll_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_pTll_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_pTll_EM_SRSS2->Write(); 
  if(EE_SROS1) h_pTll_EE_SROS1->Write(); 
  if(MM_SROS1) h_pTll_MM_SROS1->Write(); 
  if(EM_SROS1) h_pTll_EM_SROS1->Write(); 
  
  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhiMETl0_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhiMETl0_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhiMETl0_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhiMETl0_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhiMETl0_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhiMETl0_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhiMETl0_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhiMETl0_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhiMETl0_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhiMETl0_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhiMETl0_EM_SROS1->Write(); 

  /*-------------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhiMETl1_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhiMETl1_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhiMETl1_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhiMETl1_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhiMETl1_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhiMETl1_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhiMETl1_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhiMETl1_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhiMETl1_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhiMETl1_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhiMETl1_EM_SROS1->Write(); 
  
    /*-----------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhiMETj0_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhiMETj0_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhiMETj0_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhiMETj0_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhiMETj0_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhiMETj0_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhiMETj0_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhiMETj0_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhiMETj0_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhiMETj0_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhiMETj0_EM_SROS1->Write(); 
  /*-------------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhiMETj1_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhiMETj1_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhiMETj1_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhiMETj1_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhiMETj1_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhiMETj1_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhiMETj1_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhiMETj1_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhiMETj1_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhiMETj1_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhiMETj1_EM_SROS1->Write(); 

  /*-------------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhiMETjj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhiMETjj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhiMETjj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhiMETjj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhiMETjj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhiMETjj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhiMETjj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhiMETjj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhiMETjj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhiMETjj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhiMETjj_EM_SROS1->Write(); 

    /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaRjj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaRjj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaRjj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaRjj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaRjj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaRjj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaRjj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaRjj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaRjj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaRjj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaRjj_EM_SROS1->Write(); 

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_etal0_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_etal0_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_etal0_MM_SRSS1->Write();   
  if(MM_SRSS2) h_etal0_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_etal0_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_etal0_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_etal0_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_etal0_EM_SRSS2->Write(); 
  if(EE_SROS1) h_etal0_EE_SROS1->Write(); 
  if(MM_SROS1) h_etal0_MM_SROS1->Write(); 
  if(EM_SROS1) h_etal0_EM_SROS1->Write(); 
    /*---------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_etal1_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_etal1_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_etal1_MM_SRSS1->Write();   
  if(MM_SRSS2) h_etal1_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_etal1_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_etal1_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_etal1_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_etal1_EM_SRSS2->Write(); 
  if(EE_SROS1) h_etal1_EE_SROS1->Write(); 
  if(MM_SROS1) h_etal1_MM_SROS1->Write(); 
  if(EM_SROS1) h_etal1_EM_SROS1->Write(); 
    /*---------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_etaj0_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_etaj0_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_etaj0_MM_SRSS1->Write();   
  if(MM_SRSS2) h_etaj0_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_etaj0_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_etaj0_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_etaj0_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_etaj0_EM_SRSS2->Write(); 
  if(EE_SROS1) h_etaj0_EE_SROS1->Write(); 
  if(MM_SROS1) h_etaj0_MM_SROS1->Write(); 
  if(EM_SROS1) h_etaj0_EM_SROS1->Write(); 
    /*---------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_etaj1_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_etaj1_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_etaj1_MM_SRSS1->Write();   
  if(MM_SRSS2) h_etaj1_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_etaj1_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_etaj1_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_etaj1_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_etaj1_EM_SRSS2->Write(); 
  if(EE_SROS1) h_etaj1_EE_SROS1->Write(); 
  if(MM_SROS1) h_etaj1_MM_SROS1->Write(); 
  if(EM_SROS1) h_etaj1_EM_SROS1->Write(); 

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_mTl0MET_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_mTl0MET_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_mTl0MET_MM_SRSS1->Write();   
  if(MM_SRSS2) h_mTl0MET_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_mTl0MET_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_mTl0MET_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_mTl0MET_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_mTl0MET_EM_SRSS2->Write(); 
  if(EE_SROS1) h_mTl0MET_EE_SROS1->Write(); 
  if(MM_SROS1) h_mTl0MET_MM_SROS1->Write(); 
  if(EM_SROS1) h_mTl0MET_EM_SROS1->Write(); 
  /*-------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_mTl1MET_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_mTl1MET_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_mTl1MET_MM_SRSS1->Write();   
  if(MM_SRSS2) h_mTl1MET_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_mTl1MET_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_mTl1MET_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_mTl1MET_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_mTl1MET_EM_SRSS2->Write(); 
  if(EE_SROS1) h_mTl1MET_EE_SROS1->Write(); 
  if(MM_SROS1) h_mTl1MET_MM_SROS1->Write(); 
  if(EM_SROS1) h_mTl1MET_EM_SROS1->Write(); 

      /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhilljj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhilljj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhilljj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhilljj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhilljj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhilljj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhilljj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhilljj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhilljj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhilljj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhilljj_EM_SROS1->Write(); 
  /*------------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhil0jj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhil0jj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhil0jj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhil0jj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhil0jj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhil0jj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhil0jj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhil0jj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhil0jj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhil0jj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhil0jj_EM_SROS1->Write(); 
  /*------------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaPhil1jj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaPhil1jj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaPhil1jj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaPhil1jj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaPhil1jj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaPhil1jj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaPhil1jj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaPhil1jj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaPhil1jj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaPhil1jj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaPhil1jj_EM_SROS1->Write(); 

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaRlljj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaRlljj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaRlljj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaRlljj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaRlljj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaRlljj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaRlljj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaRlljj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaRlljj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaRlljj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaRlljj_EM_SROS1->Write(); 

    /*--------------------------------------------------------------------------------*/   
  if(EE_SRSS1) h_DeltaEtajj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaEtajj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaEtajj_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaEtajj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaEtajj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaEtajj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaEtajj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaEtajj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaEtajj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaEtajj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaEtajj_EM_SROS1->Write();   
  
      /*--------------------------------------------------------------------------------*/   
  if(EE_SRSS1) h_DeltaEtall_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaEtall_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaEtall_MM_SRSS1->Write();   
  if(MM_SRSS2) h_DeltaEtall_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaEtall_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaEtall_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaEtall_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaEtall_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaEtall_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaEtall_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaEtall_EM_SROS1->Write();  


  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_mTll_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_mTll_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_mTll_MM_SRSS1->Write();   
  if(MM_SRSS2) h_mTll_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_mTll_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_mTll_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_mTll_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_mTll_EM_SRSS2->Write(); 
  if(EE_SROS1) h_mTll_EE_SROS1->Write(); 
  if(MM_SROS1) h_mTll_MM_SROS1->Write(); 
  if(EM_SROS1) h_mTll_EM_SROS1->Write(); 


  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_mMETll_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_mMETll_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_mMETll_MM_SRSS1->Write();   
  if(MM_SRSS2) h_mMETll_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_mMETll_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_mMETll_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_mMETll_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_mMETll_EM_SRSS2->Write(); 
  if(EE_SROS1) h_mMETll_EE_SROS1->Write(); 
  if(MM_SROS1) h_mMETll_MM_SROS1->Write(); 
  if(EM_SROS1) h_mMETll_EM_SROS1->Write(); 

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_DeltaYjj_EE_SRSS1->Write(); 
  if(EE_SRSS2) h_DeltaYjj_EE_SRSS2->Write(); 
  if(MM_SRSS1) h_DeltaYjj_MM_SRSS1->Write();  
  if(MM_SRSS2) h_DeltaYjj_MM_SRSS2->Write(); 
  if(MM_SRSS3) h_DeltaYjj_MM_SRSS3->Write(); 
  if(MM_SRSS4) h_DeltaYjj_MM_SRSS4->Write(); 
  if(EM_SRSS1) h_DeltaYjj_EM_SRSS1->Write(); 
  if(EM_SRSS2) h_DeltaYjj_EM_SRSS2->Write(); 
  if(EE_SROS1) h_DeltaYjj_EE_SROS1->Write(); 
  if(MM_SROS1) h_DeltaYjj_MM_SROS1->Write(); 
  if(EM_SROS1) h_DeltaYjj_EM_SROS1->Write(); 

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_D0_branch_l0_EE_SRSS1->Write();
  if(EE_SRSS2) h_D0_branch_l0_EE_SRSS2->Write();
  if(MM_SRSS1) h_D0_branch_l0_MM_SRSS1->Write();  
  if(MM_SRSS2) h_D0_branch_l0_MM_SRSS2->Write();
  if(MM_SRSS3) h_D0_branch_l0_MM_SRSS3->Write();
  if(MM_SRSS4) h_D0_branch_l0_MM_SRSS4->Write();
  if(EM_SRSS1) h_D0_branch_l0_EM_SRSS1->Write();
  if(EM_SRSS2) h_D0_branch_l0_EM_SRSS2->Write();
  if(EE_SROS1) h_D0_branch_l0_EE_SROS1->Write();
  if(MM_SROS1) h_D0_branch_l0_MM_SROS1->Write();
  if(EM_SROS1) h_D0_branch_l0_EM_SROS1->Write();

    /*--------------------------------------------------------------------------------*/ 
  h_D0_branch_l1_EE_SRSS1->Write();
  h_D0_branch_l1_EE_SRSS2->Write();
  h_D0_branch_l1_MM_SRSS1->Write();  
  h_D0_branch_l1_MM_SRSS2->Write();
  h_D0_branch_l1_MM_SRSS3->Write();
  h_D0_branch_l1_MM_SRSS4->Write();
  h_D0_branch_l1_EM_SRSS1->Write();
  h_D0_branch_l1_EM_SRSS2->Write();
  h_D0_branch_l1_EE_SROS1->Write();
  h_D0_branch_l1_MM_SROS1->Write();
  h_D0_branch_l1_EM_SROS1->Write();

  /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_D0Signif_branch_l0_EE_SRSS1->Write();
  if(EE_SRSS2) h_D0Signif_branch_l0_EE_SRSS2->Write();
  if(MM_SRSS1) h_D0Signif_branch_l0_MM_SRSS1->Write();  
  if(MM_SRSS2) h_D0Signif_branch_l0_MM_SRSS2->Write();
  if(MM_SRSS3) h_D0Signif_branch_l0_MM_SRSS3->Write();
  if(MM_SRSS4) h_D0Signif_branch_l0_MM_SRSS4->Write();
  if(EM_SRSS1) h_D0Signif_branch_l0_EM_SRSS1->Write();
  if(EM_SRSS2) h_D0Signif_branch_l0_EM_SRSS2->Write();
  if(EE_SROS1) h_D0Signif_branch_l0_EE_SROS1->Write();
  if(MM_SROS1) h_D0Signif_branch_l0_MM_SROS1->Write();
  if(EM_SROS1) h_D0Signif_branch_l0_EM_SROS1->Write();

    /*--------------------------------------------------------------------------------*/ 
  if(EE_SRSS1) h_D0Signif_branch_l1_EE_SRSS1->Write();
  if(EE_SRSS2) h_D0Signif_branch_l1_EE_SRSS2->Write();
  if(MM_SRSS1) h_D0Signif_branch_l1_MM_SRSS1->Write();  
  if(MM_SRSS2) h_D0Signif_branch_l1_MM_SRSS2->Write();
  if(MM_SRSS3) h_D0Signif_branch_l1_MM_SRSS3->Write();
  if(MM_SRSS4) h_D0Signif_branch_l1_MM_SRSS4->Write();
  if(EM_SRSS1) h_D0Signif_branch_l1_EM_SRSS1->Write();
  if(EM_SRSS2) h_D0Signif_branch_l1_EM_SRSS2->Write();
  if(EE_SROS1) h_D0Signif_branch_l1_EE_SROS1->Write();
  if(MM_SROS1) h_D0Signif_branch_l1_MM_SROS1->Write();
  if(EM_SROS1) h_D0Signif_branch_l1_EM_SROS1->Write();
/*--------------------------------------------------------------------------------*/    
  cutflow_EE->Write();
  cutflow_EE_ALL->Write();  
  cutflow_MM->Write();
  cutflow_MM_ALL->Write();  
  cutflow_EM->Write();
  cutflow_EM_ALL->Write();
  
  h_NpreTaus->Write();
  
  h_DeltaR_JVF_ljOR_EE->Write(); 
  h_DeltaR_JVF_ljOR_MM->Write(); 
  h_DeltaR_JVF_ljOR_el_EM->Write();
  h_DeltaR_JVF_ljOR_mu_EM->Write();
  
  h_DeltaR_mll_ljOR_EE->Write(); 
  h_DeltaR_mll_ljOR_MM->Write(); 
  h_DeltaR_mll_ljOR_el_EM->Write();
  h_DeltaR_mll_ljOR_mu_EM->Write();
  
  h_DeltaR_leptonType_ljOR_EE->Write();
  h_DeltaR_leptonType_ljOR_MM->Write();
  h_DeltaR_leptonType_ljOR_mu_EM->Write();
  h_DeltaR_leptonType_ljOR_el_EM->Write();
  
  h_3rdleptonType_EE->Write();
  h_3rdleptonType_MM->Write();
  h_3rdleptonType_mu_EM->Write();
  h_3rdleptonType_el_EM->Write(); 
  
  h_DeltaR_ptcone_ljOR_PR_EE->Write(); 
  h_DeltaR_etcone_ljOR_PR_EE->Write();
  h_DeltaR_ptcone_ljOR_PR_MM->Write();
  h_DeltaR_ptcone_ljOR_PR_mu_EM->Write();
  h_DeltaR_ptcone_ljOR_PR_el_EM->Write();
  h_DeltaR_etcone_ljOR_PR_el_EM->Write();
  
  h_Ntpr_ljOR_HF_EE->Write();
  h_Ntpr_ljOR_LF_EE->Write();
  h_Ntpr_ljOR_HF_MM->Write();
  h_Ntpr_ljOR_LF_MM->Write();
  h_Ntpr_ljOR_HF_mu_EM->Write();
  h_Ntpr_ljOR_LF_mu_EM->Write();
  h_Ntpr_ljOR_HF_el_EM->Write();
  h_Ntpr_ljOR_LF_el_EM->Write();  

  h_DeltaR_min_lostLepton_truthParticle_HF_EE->Write();
  h_DeltaR_min_lostLepton_truthParticle_LF_EE->Write();
  h_DeltaR_min_lostLepton_truthParticle_HF_MM->Write();
  h_DeltaR_min_lostLepton_truthParticle_LF_MM->Write();
  h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM->Write();
  h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM->Write();
  h_DeltaR_min_lostLepton_truthParticle_HF_el_EM->Write();
  h_DeltaR_min_lostLepton_truthParticle_LF_el_EM->Write();  
  
  h_DeltaR_min_lostLepton_truthJet_HF_EE->Write();
  h_DeltaR_min_lostLepton_truthJet_LF_EE->Write();
  h_DeltaR_min_lostLepton_truthJet_HF_MM->Write();
  h_DeltaR_min_lostLepton_truthJet_LF_MM->Write();
  h_DeltaR_min_lostLepton_truthJet_HF_mu_EM->Write();
  h_DeltaR_min_lostLepton_truthJet_LF_mu_EM->Write();
  h_DeltaR_min_lostLepton_truthJet_HF_el_EM->Write();
  h_DeltaR_min_lostLepton_truthJet_LF_el_EM->Write();  
  
  h_DeltaR_min_lostLepton_preJet_HF_EE->Write();
  h_DeltaR_min_lostLepton_preJet_LF_EE->Write();
  h_DeltaR_min_lostLepton_preJet_HF_MM->Write();
  h_DeltaR_min_lostLepton_preJet_LF_MM->Write();
  h_DeltaR_min_lostLepton_preJet_HF_mu_EM->Write();
  h_DeltaR_min_lostLepton_preJet_LF_mu_EM->Write();
  h_DeltaR_min_lostLepton_preJet_HF_el_EM->Write();
  h_DeltaR_min_lostLepton_preJet_LF_el_EM->Write();  
  
  h_DeltaR_min_lostLepton_preJet_JVF_HF_EE->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_EE->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_MM->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_MM->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_mu_EM->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_mu_EM->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_HF_el_EM->Write();
  h_DeltaR_min_lostLepton_preJet_JVF_LF_el_EM->Write();  
    
  h_DeltaR_ptcone_ljOR_HF_EE->Write(); 
  h_DeltaR_etcone_ljOR_HF_EE->Write();
  h_DeltaR_ptcone_ljOR_HF_MM->Write();
  h_DeltaR_ptcone_ljOR_HF_mu_EM->Write();
  h_DeltaR_ptcone_ljOR_HF_el_EM->Write();
  h_DeltaR_etcone_ljOR_HF_el_EM->Write();
    
  h_DeltaR_em_EM->Write();
  
  h_failedSignalCriteria_EE->Write();  
  h_failedSignalCriteria_MM->Write();  
  h_failedSignalCriteria_mu_EM->Write();
  h_failedSignalCriteria_el_EM->Write();

  h_etcone30lZcandImpact_EE_SRSS1->Write();  
  h_etcone30lZcandImpact_MM_SRSS1->Write();      
  h_etcone30lZcandImpact_mu_EM_SRSS1->Write();
  h_etcone30lZcandImpact_el_EM_SRSS1->Write();
    
  h_Nleptons_ZcandImpact_EE_SRSS1->Write();
  h_Nleptons_ZcandImpact_MM_SRSS1->Write();
  h_Nleptons_ZcandImpact_mu_EM_SRSS1->Write();
  h_Nleptons_ZcandImpact_el_EM_SRSS1->Write();
  
  h_mllZcandImpact_EE_SRSS1->Write();
  h_mllZcandImpact_MM_SRSS1->Write();
  h_mllZcandImpact_mu_EM_SRSS1->Write();
  h_mllZcandImpact_el_EM_SRSS1->Write();
  
  h_mTllZcandImpact_EE_SRSS1->Write();
  h_mTllZcandImpact_MM_SRSS1->Write();
  h_mTllZcandImpact_mu_EM_SRSS1->Write();    
  h_mTllZcandImpact_el_EM_SRSS1->Write();    
  
  h_pTlZcandImpact_EE_SRSS1->Write();
  h_pTlZcandImpact_MM_SRSS1->Write();
  h_pTlZcandImpact_mu_EM_SRSS1->Write();
  h_pTlZcandImpact_el_EM_SRSS1->Write();
  
  h_IClZcandImpact_EE_SRSS1->Write();
  h_IClZcandImpact_MM_SRSS1->Write();
  h_IClZcandImpact_mu_EM_SRSS1->Write();   
  h_IClZcandImpact_el_EM_SRSS1->Write();
  
  h_etalZcandImpact_EE_SRSS1->Write();
  h_etalZcandImpact_MM_SRSS1->Write();
  h_etalZcandImpact_mu_EM_SRSS1->Write();
  h_etalZcandImpact_el_EM_SRSS1->Write();
  
  h_ptcone30lZcandImpact_EE_SRSS1->Write();
  h_ptcone30lZcandImpact_MM_SRSS1->Write();
  h_ptcone30lZcandImpact_mu_EM_SRSS1->Write();
  h_ptcone30lZcandImpact_el_EM_SRSS1->Write();
  
  h_d0SiglZcandImpact_EE_SRSS1->Write();
  h_d0SiglZcandImpact_MM_SRSS1->Write();
  h_d0SiglZcandImpact_mu_EM_SRSS1->Write();
  h_d0SiglZcandImpact_el_EM_SRSS1->Write();
  
  h_z0SinThetalZcandImpact_EE_SRSS1->Write();
  h_z0SinThetalZcandImpact_MM_SRSS1->Write();
  h_z0SinThetalZcandImpact_mu_EM_SRSS1->Write();
  h_z0SinThetalZcandImpact_el_EM_SRSS1->Write();
  
  

//   h_Nleptons_tauZcand_EE_SRSS1->Write();
//   h_Nleptons_tauZcand_MM_SRSS1->Write();
//   h_Nleptons_tauZcand_EM_SRSS1->Write();
//   
//   h_Nleptons_preTau_EE_SRSS1->Write();
//   h_Nleptons_preTau_MM_SRSS1->Write();
//   h_Nleptons_preTau_EM_SRSS1->Write();
//   
//   h_ml0ltauZcand_EE_SRSS1->Write();
//   h_ml0ltauZcand_MM_SRSS1->Write();
//   h_ml0ltauZcand_EM_SRSS1->Write();
//   
//   h_mTl0ltauZcand_EE_SRSS1->Write();
//   h_mTl0ltauZcand_MM_SRSS1->Write();
//   h_mTl0ltauZcand_EM_SRSS1->Write();    
//   
//   h_pTl0ltauZcand_EE_SRSS1->Write();
//   h_pTl0ltauZcand_MM_SRSS1->Write();
//   h_pTl0ltauZcand_EM_SRSS1->Write();
// 
//   h_etal0ltauZcand_EE_SRSS1->Write();
//   h_etal0ltauZcand_MM_SRSS1->Write();
//   h_etal0ltauZcand_EM_SRSS1->Write();
//   
//   h_jetBDTl0ltauZcand_EE_SRSS1->Write();
//   h_jetBDTl0ltauZcand_MM_SRSS1->Write();
//   h_jetBDTl0ltauZcand_EM_SRSS1->Write();
//   
//   h_mltauZcand_EE_SRSS1->Write();
//   h_mltauZcand_MM_SRSS1->Write();
//   h_mltauZcand_EM_SRSS1->Write();
//   
//   h_mTltauZcand_EE_SRSS1->Write();
//   h_mTltauZcand_MM_SRSS1->Write();
//   h_mTltauZcand_EM_SRSS1->Write();    
//   
//   h_pTltauZcand_EE_SRSS1->Write();
//   h_pTltauZcand_MM_SRSS1->Write();
//   h_pTltauZcand_EM_SRSS1->Write();
//   
//   h_etaltauZcand_EE_SRSS1->Write();
//   h_etaltauZcand_MM_SRSS1->Write();
//   h_etaltauZcand_EM_SRSS1->Write();
//   
//   h_jetBDTltauZcand_EE_SRSS1->Write();
//   h_jetBDTltauZcand_MM_SRSS1->Write();
//   h_jetBDTltauZcand_EM_SRSS1->Write();  
  
  h_Mljj_EE_SRSS1->Write();
  h_Mljj_MM_SRSS1->Write();
  h_Mljj_EM_SRSS1->Write();
  h_Mlj_EE_SRSS1->Write();
  h_Mlj_MM_SRSS1->Write();
  h_Mlj_EM_SRSS1->Write();
  
}

void TSelector_SusyNtuple::writeHistos_sysUncert(){
  
  cutflow_EE_sysUncert->Write();  
  cutflow_MM_sysUncert->Write();  
  cutflow_EM_sysUncert->Write();
}

// void TSelector_SusyNtuple::addHistos(){
// 
//   //nEEded when running with Proof On Demand
// 
// //     fOutput->Add( h_storeSumwMcid);
// 
// //   return true;
//     
// }
void TSelector_SusyNtuple::calcJet_variables(TLorentzVector met_TLV){
  
  TLorentzVector signalJet0_TLV;
  TLorentzVector signalJet1_TLV;
  nSignalJets = numberOfCLJets(m_signalJets2Lep);
  if(nSignalJets>0){
    signalJet0_TLV.SetPtEtaPhiE(m_signalJets2Lep.at(0)->Pt(), m_signalJets2Lep.at(0)->eta ,m_signalJets2Lep.at(0)->phi, m_signalJets2Lep.at(0)
    ->Pt()*cosh(m_signalJets2Lep.at(0)->eta));
    signalJet0_TLV.SetPtEtaPhiM(m_signalJets2Lep.at(0)->Pt(), m_signalJets2Lep.at(0)->eta ,m_signalJets2Lep.at(0)->phi, m_signalJets2Lep.at(0)
    ->m);
  }
  if(nSignalJets>1){
    signalJet1_TLV.SetPtEtaPhiE(m_signalJets2Lep.at(1)->Pt(), m_signalJets2Lep.at(1)->eta ,m_signalJets2Lep.at(1)->phi, m_signalJets2Lep.at(1)->Pt()*cosh(m_signalJets2Lep.at(1)->eta));
    signalJet1_TLV.SetPtEtaPhiM(m_signalJets2Lep.at(1)->Pt(), m_signalJets2Lep.at(1)->eta ,m_signalJets2Lep.at(1)->phi, m_signalJets2Lep.at(1)->m);
  }
  
  
  
  if(nSignalJets>0){
    pTj0 = signalJet0_TLV.Pt();
    pTj1 = (nSignalJets>1) ? signalJet1_TLV.Pt() : 0.;
    eta_j0 = signalJet0_TLV.Eta();
    eta_j1 = (nSignalJets>1) ? signalJet1_TLV.Eta() : 0.;
    mjj = (nSignalJets>1) ? (signalJet0_TLV + signalJet1_TLV).M() : signalJet0_TLV.M();
    DeltaPhijj = (nSignalJets>1) ? fabs(signalJet0_TLV.DeltaPhi(signalJet1_TLV)) : 0.;
    pTjj = (nSignalJets>1) ? (signalJet0_TLV + signalJet1_TLV).Pt() : signalJet0_TLV.Pt();
    DeltaPhiMETj0 = fabs(signalJet0_TLV.DeltaPhi(met_TLV));
    DeltaPhiMETj1 = (nSignalJets>1) ? fabs(signalJet1_TLV.DeltaPhi(met_TLV)) : 0.;
    DeltaRjj = (nSignalJets>1) ?  fabs(signalJet0_TLV.DeltaR(signalJet1_TLV)) : 0.;
    DeltaEtajj = (nSignalJets>1) ? fabs(signalJet0_TLV.Eta() - signalJet1_TLV.Eta()) : 0.;
    DeltaYjj = (nSignalJets>1) ? fabs(signalJet0_TLV.Rapidity() - signalJet1_TLV.Rapidity()) : 0.;
    DeltaPhiMETjj = (nSignalJets>1) ? fabs((signalJet0_TLV+ signalJet1_TLV).DeltaPhi(met_TLV)) : fabs(signalJet0_TLV.DeltaPhi(met_TLV));
    NBJets = numberOfCBJets(m_signalJets2Lep);
    NCJets = numberOfCLJets(m_signalJets2Lep);
    NFJets = numberOfFJets(m_signalJets2Lep);
    meff = calcMeff(met_TLV, m_signalJets2Lep);
  }
    
}
void TSelector_SusyNtuple::calc_EE_variables(LeptonVector &leptons, Electron* el0, Electron* el1, TLorentzVector el0_TLV, TLorentzVector el1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EE, SusyNtSys SysSetting, bool n0150BugFix){
  
  pTl0_EE = el0_TLV.Pt();
  pTl1_EE = el1_TLV.Pt();
  etal0_EE = el0_TLV.Eta();
  etal1_EE = el1_TLV.Eta();
  DeltaR_EE = fabs(el0_TLV.DeltaR(el1_TLV));
  pTll_EE = (el0_TLV + el1_TLV).Pt();
  Mll_EE = Mll(el0, el1);
  METrel_EE = recalcMetRel(met_TLV, el0_TLV, el1_TLV, m_signalJets2Lep, useForwardJets);
  MET_EE = met_TLV.Pt();
  HT_EE = calcHT(el0_TLV, el1_TLV, met_TLV, m_signalJets2Lep);
  mTWW_EE = calcMt((el0_TLV + el1_TLV), met_TLV);
  mT_EE = calcMt((el0_TLV+el1_TLV), met_TLV);
  mTmin_EE = (calcMt(el0_TLV, met_TLV) > calcMt(el1_TLV, met_TLV)) ? calcMt(el1_TLV, met_TLV) : calcMt(el0_TLV, met_TLV);
  mTmax_EE = (calcMt(el0_TLV, met_TLV) < calcMt(el1_TLV, met_TLV)) ? calcMt(el1_TLV, met_TLV) : calcMt(el0_TLV, met_TLV);
  mTl0MET_EE = calcMt(el0_TLV, met_TLV);
  mTl1MET_EE = calcMt(el1_TLV, met_TLV);
  mMET_EE = (el0_TLV + el1_TLV + met_TLV).M();
  DeltaPhi_EE = fabs(el0_TLV.DeltaPhi(el1_TLV));
  DeltaPhiMETl0_EE = fabs(el0_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETl1_EE = fabs(el1_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETll_EE = fabs((el0_TLV + el1_TLV).DeltaPhi(met_TLV));
  
  if(nSignalJets>0){
     DeltaPhilljj_EE = (nSignalJets>1) ? fabs((el0_TLV + el1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : fabs((el0_TLV + el1_TLV).DeltaPhi(signalJet0_TLV));    
    DeltaPhil0jj_EE = (nSignalJets>1) ? ((el0_TLV.Pt()> el1_TLV.Pt()) ? (el0_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (el1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((el0_TLV.Pt()> el1_TLV.Pt()) ? (el0_TLV).DeltaPhi(signalJet0_TLV) : (el1_TLV).DeltaPhi(signalJet0_TLV));
    DeltaPhil1jj_EE= (nSignalJets>1) ?  ((el0_TLV.Pt()< el1_TLV.Pt()) ? (el1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (el0_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((el0_TLV.Pt()< el1_TLV.Pt()) ? (el1_TLV).DeltaPhi(signalJet0_TLV) : (el0_TLV).DeltaPhi(signalJet0_TLV));
    DeltaRlljj_EE = (nSignalJets>1) ? (el0_TLV + el1_TLV).DeltaR(signalJet0_TLV + signalJet1_TLV) : (el0_TLV + el1_TLV).DeltaR(signalJet0_TLV);
  }
  
  //Mljj: invariant mass of the lepton-dijet system formed by the two highest pT jets and the lepton closest to the dijet axis.
  Mljj_EE = -1.;
  Mlj_EE = -1.;
  if(nSignalJets>1){
    //find dijet axis:
    double DeltaRDijetEl0 = el0_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el0_TLV.Phi()),2));
    double DeltaRDijetE = el1_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el1_TLV.Phi()),2));
    TLorentzVector closestElecDijetAxis_TLV = (DeltaRDijetEl0 > DeltaRDijetE) ? el1_TLV : el0_TLV;
    Mljj_EE = (signalJet0_TLV + signalJet1_TLV + closestElecDijetAxis_TLV).M();
  }
  if(nSignalJets>0){
    //find dijet axis:
    double DeltaRDijetEl0 = el0_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - el0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el0_TLV.Phi()),2));
    double DeltaRDijetE = el1_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - el1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el1_TLV.Phi()),2));
    TLorentzVector closestElecDijetAxis_TLV = (DeltaRDijetEl0 > DeltaRDijetE) ? el1_TLV : el0_TLV;
    Mlj_EE = (signalJet0_TLV + closestElecDijetAxis_TLV).M();
  }
  
  mT2_EE = calcMT2(met_TLV, el0_TLV, el1_TLV);
  if(nSignalJets>1) mT2J_EE = calcMT2J(met_TLV, el0_TLV, el1_TLV, signalJet0_TLV, signalJet1_TLV);
  

  DeltaEtall_EE = fabs(el0_TLV.Eta() - el1_TLV.Eta());
    
  bool unbiased = true;
  if(unbiased){
    D0_branch_l0_EE = el0->d0Unbiased;
    D0_branch_l1_EE = el1->d0Unbiased;
    D0err_branch_l0_EE = el0->errD0Unbiased;
    D0err_branch_l1_EE = el1->errD0Unbiased;
  }
  else{
    D0_branch_l0_EE = el0->d0;
    D0_branch_l1_EE = el1->d0;
    D0err_branch_l0_EE = el0->errD0;
    D0err_branch_l1_EE = el1->errD0;
  }
  
  
  sD0Signif_branch_l0_EE = calc_D0(unbiased, leptons.at(0)) / D0err_branch_l0_EE;
  sD0Signif_branch_l1_EE = calc_D0(unbiased, leptons.at(1)) / D0err_branch_l1_EE;
  
  //get all electrons in SusyNtuple which have pT > 6 GeV
  ElectronVector Electrons_all_vec;
  for(uint ie=0; ie<susyNt->ele()->size(); ++ie){
    Electron* e = & susyNt->ele()->at(ie);
    e->setState(SysSetting);
    if(e->Pt() < 6.) continue;

    Electrons_all_vec.push_back(e);
  }
    JetVector prejets = getPreJets(&nt, SysSetting); 
//   perform overlap removal to check which electrons *would* have been removed
  ElectronVector elecs = Electrons_all_vec;
  MuonVector muons = getPreMuons(susyNt, SysSetting, n0150BugFix);
  JetVector jets  = getPreJets(susyNt, SysSetting);
  TauVector taus = getPreTaus(susyNt, SysSetting);

  // Now perform the overlap removals
  performOverlap(elecs, muons, taus, jets);

  // Do SFOS removal for Mll < 12 
  removeSFOSPair(elecs, MLL_MIN);
//   removeSFOSPair(muons, MLL_MIN);
  

  mllZcandImpact_EE = -1.;      
  mTllZcandImpact_EE = -1.;
  IClZcandImpact_EE = -5;
  pTlZcandImpact_EE = -1.;
  etalZcandImpact_EE = -1.;
  ptcone30lZcandImpact_EE = -1.;
  etcone30lZcandImpact_EE = -1.;
  d0SiglZcandImpact_EE = -1.;
  z0SinThetalZcandImpact_EE = -1.;
  
  ZcandLep_exists_EE = false;
  ZcandLep_passesPT_EE = true;
  ZcandLep_passesEta_EE = true;
  ZcandLep_passesPTcone_EE = true;
  ZcandLep_passesETcone_EE = true;
  ZcandLep_passesD0_EE = true; 
  ZcandLep_passesZ0_EE = true; 
  ZcandLep_PassesMedium_EE = true;
  ZcandLep_PassesTight_EE = true; 
  ZcandLep_PassesORAndMllCut_EE = false;
  ZcandLep_PassesPR_EE = true;
  
  
  double DeltaMZ_lZcandImpact = 99999.;

  ElectronVector Electron_ZcandImpact_vec;
  Electron* el_ZcandImpact_lost;
 
  
  
    Electron* closest_signal_el;
    TLorentzVector closest_signal_el_TLV;
    bool foundCandidate = false;
    for(uint ie=0; ie<Electrons_all_vec.size(); ie++){
      
    
      Electron* el_ZcandImpact = Electrons_all_vec.at(ie);
      el_ZcandImpact->setState(SysSetting);

      if((el_ZcandImpact->DeltaR(*el0) < 0.05) || (el_ZcandImpact->DeltaR(*el1) < 0.05)) continue; //no overlap w/ signal lepton
      
      if(fabs(el_ZcandImpact->d0Sig(true)) >= ELECTRON_D0SIG_CUT_WH) continue;
      if(fabs(el_ZcandImpact->z0SinTheta(true)) >= ELECTRON_Z0_SINTHETA_CUT) continue;

      TLorentzVector ZcandImpactElec_TLV;
      ZcandImpactElec_TLV.SetPtEtaPhiE(el_ZcandImpact->Pt(), el_ZcandImpact->eta ,el_ZcandImpact->phi, el_ZcandImpact->Pt()*cosh(el_ZcandImpact->eta));
      ZcandImpactElec_TLV.SetPtEtaPhiM(el_ZcandImpact->Pt(), el_ZcandImpact->eta ,el_ZcandImpact->phi, el_ZcandImpact->m);

//       SFOS pair with leading or subleading signal electron closer to Zmass?
      float DeltaMZ_l0_ZcandImpact = 999.;
      if((fabs(MZ - Mll(el0, el_ZcandImpact)) < DeltaMZ_lZcandImpact) && ((el_ZcandImpact->q * el0->q)<0.)){
	DeltaMZ_l0_ZcandImpact = fabs(MZ - Mll(el0, el_ZcandImpact));
	foundCandidate = true;
      }
      float DeltaMZ_l1_ZcandImpact = 999.;
      if((fabs(MZ - Mll(el1, el_ZcandImpact)) < DeltaMZ_lZcandImpact) && ((el_ZcandImpact->q * el1->q)<0.)){
	DeltaMZ_l1_ZcandImpact = fabs(MZ - Mll(el1, el_ZcandImpact));
	foundCandidate = true;
      }
      
      if(foundCandidate && ( (fabs(MZ - Mll(el1, el_ZcandImpact)) < DeltaMZ_lZcandImpact) || (fabs(MZ - Mll(el0, el_ZcandImpact)) < DeltaMZ_lZcandImpact) )){

	el_ZcandImpact_lost = el_ZcandImpact;
	if(DeltaMZ_l0_ZcandImpact < DeltaMZ_l1_ZcandImpact){
	  closest_signal_el = el0;
	  closest_signal_el_TLV = el0_TLV;
	}
	else{
	  closest_signal_el = el1;
	  closest_signal_el_TLV = el1_TLV;
	}
	
	mllZcandImpact_EE = Mll(closest_signal_el, el_ZcandImpact);      
	mTllZcandImpact_EE = calcMt(closest_signal_el_TLV, ZcandImpactElec_TLV);  
	pTlZcandImpact_EE = el_ZcandImpact->Pt();
	etalZcandImpact_EE = fabs(el_ZcandImpact->eta);
	float ptcone30 = elPtConeCorr(el_ZcandImpact, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	ptcone30lZcandImpact_EE = ptcone30/std::min(el_ZcandImpact->pt,ELECTRON_ISO_PT_THRS);

	
	float etcone = elEtTopoConeCorr(el_ZcandImpact, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	etcone30lZcandImpact_EE = etcone/std::min(el_ZcandImpact->pt,ELECTRON_ISO_PT_THRS);	
	d0SiglZcandImpact_EE = fabs(el_ZcandImpact->d0Sig(true));
	z0SinThetalZcandImpact_EE = fabs(el_ZcandImpact->z0SinTheta(true));	
	DeltaMZ_lZcandImpact = fabs(MZ - Mll(closest_signal_el, el_ZcandImpact));
	
	Electron_ZcandImpact_vec.push_back(el_ZcandImpact);
      }
      
    }


  Nleptons_ZcandImpact_EE = Electron_ZcandImpact_vec.size();
  
  if(Nleptons_ZcandImpact_EE>0) {

    ZcandLep_exists_EE = true;
//     if(fabs(mllZcandImpact_EE - MZ) < 20.){
      if(pTlZcandImpact_EE < 10.) ZcandLep_passesPT_EE = false;
      if(ptcone30lZcandImpact_EE >= ELECTRON_PTCONE30_PT_WH_CUT) ZcandLep_passesPTcone_EE = false;
      if(etcone30lZcandImpact_EE >= ELECTRON_TOPOCONE30_PT_WH_CUT) ZcandLep_passesETcone_EE = false;
      if(d0SiglZcandImpact_EE >= ELECTRON_D0SIG_CUT_WH) ZcandLep_passesD0_EE = false;
      if(z0SinThetalZcandImpact_EE >= ELECTRON_Z0_SINTHETA_CUT) ZcandLep_passesZ0_EE = false;
      ZcandLep_PassesMedium_EE = el_ZcandImpact_lost->mediumPP;
      ZcandLep_PassesTight_EE = el_ZcandImpact_lost->tightPP;
      if(el_ZcandImpact_lost->truthType != RecoTruthMatch::PROMPT) ZcandLep_PassesPR_EE =  false;
      for(unsigned int ie = 0; ie< elecs.size(); ie ++){
	 if(elecs.at(ie)->DeltaR(*el_ZcandImpact_lost) < 0.0001) ZcandLep_PassesORAndMllCut_EE = true;
      }
//     }
    
    int lepton_type = -1;
    if(el_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT) lepton_type = 1;	
    else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF) lepton_type = 2;	
    else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
    else lepton_type = 0;      
    
    if(fabs(mllZcandImpact_EE - MZ) < 20.){
      
      h_3rdleptonType_EE->Fill(lepton_type, 1.);
      TLorentzVector el_ZcandImpact_lost_TLV;
      el_ZcandImpact_lost_TLV.SetPtEtaPhiE(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->Pt()*cosh(el_ZcandImpact_lost->eta));
      el_ZcandImpact_lost_TLV.SetPtEtaPhiM(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->m);
      
//       study HF lost electrons:
      if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	  
// 	  h_Ntpr_ljOR_HF_EE->Fill(nt.tpr()->size(),  1.);
	  
// 	  TruthParticleVector candidates_3rd_truth_lepton;
// 	  TruthParticle* third_truth_particle;
// 	  TLorentzVector third_truth_particle_TLV;
	  
	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	  float DeltaR_min_lostLepton_truthParticle = 999.;
// 	  for(uint index=0; index<nt.tpr()->size(); ++index){
// 	    TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	    TLorentzVector truthparticle_TLV;
// 	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    
// 	    if(el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 
// 	       
// 	    if((truthparticle_TLV.DeltaR(el0_TLV) < 0.003) || (truthparticle_TLV.DeltaR(el1_TLV) < 0.003)) continue; //no overlap w/ signal lepton
// 	    third_truth_particle = truthparticle;
// 
// 	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	    candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	    
// 	    
// 	  }
// 	  h_DeltaR_min_lostLepton_truthParticle_HF_EE->Fill(DeltaR_min_lostLepton_truthParticle, 1.);

	  //loop over 3rd truth lepton (should only be one):
	  
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// // 	      cout << "truthjet->eta= " << truthjet->eta << " truthjet->phi= " << truthjet->phi << " truthjet DeltaR= " << el_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV) << endl;
// 	      if(truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV);
// 	    }
// 	    
// 	    h_DeltaR_min_lostLepton_truthJet_HF_EE->Fill(DeltaR_min_lostLepton_truthJet,  1.);
// 	    
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	      Jet* prejet = prejets.at(ij);
	      
	      TLorentzVector prejet_TLV;
	      prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	      prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	      
	      if(prejet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_preJet){
		DeltaR_min_lostLepton_preJet = el_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);
		prejet_minDeltaR = prejet;
	      }
	      
	      
	    }
	    h_DeltaR_min_lostLepton_preJet_HF_EE->Fill(DeltaR_min_lostLepton_preJet,  1.);
	    
	  
      }
      
      //study LF lost electrons:
      if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF){
	  
// 	  h_Ntpr_ljOR_LF_EE->Fill(nt.tpr()->size(),  1.);
	  
// 	  TruthParticleVector candidates_3rd_truth_lepton;
// 	  TruthParticle* third_truth_particle;
// 	  TLorentzVector third_truth_particle_TLV;
	  
	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	  float DeltaR_min_lostLepton_truthParticle = 999.;
// 	  for(uint index=0; index<nt.tpr()->size(); ++index){
// 	    TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	    TLorentzVector truthparticle_TLV;
// 	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    
// 	    if(el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 
// 	       
// 	    if((truthparticle_TLV.DeltaR(el0_TLV) < 0.003) || (truthparticle_TLV.DeltaR(el1_TLV) < 0.003)) continue; //no overlap w/ signal lepton
// 	    third_truth_particle = truthparticle;
// 
// 	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	    candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	    
// 	    
// 	  }
// 	  h_DeltaR_min_lostLepton_truthParticle_LF_EE->Fill(DeltaR_min_lostLepton_truthParticle, 1.);

	  //loop over 3rd truth lepton (should only be one):
	  
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 	      if(truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV);
// 	    }
// 	    
// 	    h_DeltaR_min_lostLepton_truthJet_LF_EE->Fill(DeltaR_min_lostLepton_truthJet,  1.);
// 	    
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	      Jet* prejet = prejets.at(ij);
	      
	      TLorentzVector prejet_TLV;
	      prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	      prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	      if(el_ZcandImpact_lost_TLV.DeltaR(prejet_TLV) < DeltaR_min_lostLepton_preJet){
		DeltaR_min_lostLepton_preJet = el_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);
		prejet_minDeltaR = prejet;
	      }
	      
	      
	    }
	    h_DeltaR_min_lostLepton_preJet_LF_EE->Fill(DeltaR_min_lostLepton_preJet,  1.);
	    
	  
      }
    }
      
      for(uint ij=0; ij<prejets.size(); ij++){ 
	Jet* prejet = prejets.at(ij);
	float ptcone30 = elPtConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	float etcone = elEtTopoConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	    
	h_DeltaR_JVF_ljOR_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), prejets.at(ij)->jvf, 1.);      
	h_DeltaR_mll_ljOR_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mllZcandImpact_EE, 1.);      

	if(el_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT){
	  lepton_type = 1;
	  h_DeltaR_etcone_ljOR_PR_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), etcone/el_ZcandImpact_lost->Pt(), 1.);
	  h_DeltaR_ptcone_ljOR_PR_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), ptcone30/el_ZcandImpact_lost->Pt(), 1.);

	}
	else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF){

	  lepton_type = 2;
	  h_DeltaR_etcone_ljOR_HF_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), etcone/el_ZcandImpact_lost->Pt(),  1.);
	  h_DeltaR_ptcone_ljOR_HF_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), ptcone30/el_ZcandImpact_lost->Pt(), 1.);
	}
	else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
	else lepton_type = 0;
	if(fabs(mllZcandImpact_EE - MZ) < 20.) h_DeltaR_leptonType_ljOR_EE->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), lepton_type, 1.);
      }
    }
 

  		  
   mZTT_coll = calcMZTauTau_coll(el0_TLV, el1_TLV, met_TLV); 
}

void TSelector_SusyNtuple::calc_MM_variables(LeptonVector &leptons, Muon* mu0, Muon* mu1, TLorentzVector mu0_TLV, TLorentzVector mu1_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_MM, SusyNtSys SysSetting, bool n0150BugFix){

  TLorentzVector mu0_TLV_n, mu1_TLV_n;
  mu0_TLV_n.SetPtEtaPhiE(mu0->Pt(), mu0->eta ,mu0->phi, mu0->Pt()*cosh(mu0->eta));
  mu0_TLV_n.SetPtEtaPhiM(mu0->Pt(), mu0->eta ,mu0->phi, mu0->m);
  mu0_TLV_n.SetPtEtaPhiE(mu1->Pt(), mu1->eta ,mu1->phi, mu1->Pt()*cosh(mu1->eta));
  mu0_TLV_n.SetPtEtaPhiM(mu1->Pt(), mu1->eta ,mu1->phi, mu1->m);
  
  DeltaR_MM = mu0_TLV.DeltaR(mu1_TLV);
  pTl0_MM = mu0_TLV.Pt() > mu1_TLV.Pt() ? mu0_TLV.Pt() : mu1_TLV.Pt();
  pTl1_MM = mu0_TLV.Pt() > mu1_TLV.Pt() ? mu1_TLV.Pt() : mu0_TLV.Pt();
  etal0_MM = mu0_TLV.Eta();
  etal1_MM = mu1_TLV.Eta();
  pTll_MM = (mu0_TLV_n + mu1_TLV_n).Pt();
  Mll_MM = Mll(mu0, mu1);
  METrel_MM = recalcMetRel(met_TLV, mu0_TLV, mu1_TLV, m_signalJets2Lep, useForwardJets);
  MET_MM = met_TLV.Pt();
  HT_MM = calcHT(mu0_TLV, mu1_TLV, met_TLV, m_signalJets2Lep);
  mTWW_MM = calcMt((mu0_TLV + mu1_TLV), met_TLV);

  mT_MM = calcMt((mu0_TLV+mu1_TLV), met_TLV);
  mTmin_MM = (calcMt(mu0_TLV, met_TLV) > calcMt(mu1_TLV, met_TLV)) ? calcMt(mu1_TLV, met_TLV) : calcMt(mu0_TLV, met_TLV);
  mTmax_MM = (calcMt(mu0_TLV, met_TLV) < calcMt(mu1_TLV, met_TLV)) ? calcMt(mu1_TLV, met_TLV) : calcMt(mu0_TLV, met_TLV);
  mTl0MET_MM = calcMt(mu0_TLV, met_TLV);
  mTl1MET_MM = calcMt(mu1_TLV, met_TLV);
  mMET_MM = (mu0_TLV + mu1_TLV + met_TLV).M();
  DeltaPhi_MM = fabs(mu0_TLV.DeltaPhi(mu1_TLV));
  DeltaPhiMETl0_MM = fabs(mu0_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETl1_MM = fabs(mu1_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETll_MM = fabs((mu0_TLV + mu1_TLV).DeltaPhi(met_TLV));
  if(nSignalJets>0){
    DeltaPhilljj_MM = (nSignalJets>1) ? fabs((mu0_TLV + mu1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : fabs((mu0_TLV + mu1_TLV).DeltaPhi(signalJet0_TLV));
    DeltaPhil0jj_MM = (nSignalJets>1) ?  ((mu0_TLV.Pt()> mu1_TLV.Pt()) ? (mu0_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (mu1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((mu0_TLV.Pt()> mu1_TLV.Pt()) ? (mu0_TLV).DeltaPhi(signalJet0_TLV) : (mu1_TLV).DeltaPhi(signalJet0_TLV));
    DeltaPhil1jj_MM= (nSignalJets>1) ?  ((mu0_TLV.Pt()< mu1_TLV.Pt()) ? (mu1_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (mu0_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((mu0_TLV.Pt()< mu1_TLV.Pt()) ? (mu1_TLV).DeltaPhi(signalJet0_TLV) : (mu0_TLV).DeltaPhi(signalJet0_TLV));
    DeltaRlljj_MM = (nSignalJets>1) ?  (mu0_TLV + mu1_TLV).DeltaR(signalJet0_TLV + signalJet1_TLV) : (mu0_TLV + mu1_TLV).DeltaR(signalJet0_TLV);
  }
  
  //Mljj: invariant mass of the lepton-dijet system formed by the two highest pT jets and the lepton closest to the dijet axis.
  Mljj_MM = -1.;
  Mlj_MM = -1.;
  if(nSignalJets>1){
    double DeltaRDijetMu0 = mu0_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetMu1 = mu1_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestMuonDijetAxis_TLV = (DeltaRDijetMu0 > DeltaRDijetMu1) ? mu1_TLV : mu0_TLV;
    Mljj_MM = (signalJet0_TLV + signalJet1_TLV + closestMuonDijetAxis_TLV).M();
  }
  if(nSignalJets>0){
    double DeltaRDijetMu0 = mu0_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu0_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu0_TLV.Phi()),2));
    double DeltaRDijetMu1 = mu1_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu1_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu1_TLV.Phi()),2));
    TLorentzVector closestMuonDijetAxis_TLV = (DeltaRDijetMu0 > DeltaRDijetMu1) ? mu1_TLV : mu0_TLV;
    Mlj_MM = (signalJet0_TLV + closestMuonDijetAxis_TLV).M();
  }  
  
  mT2_MM = calcMT2(met_TLV, mu0_TLV, mu1_TLV);
  if(nSignalJets>1){
    mT2J_MM = calcMT2J(met_TLV, mu0_TLV, mu1_TLV, signalJet0_TLV, signalJet1_TLV);
  }
  
  DeltaEtall_MM = fabs(mu0_TLV.Eta() - mu1_TLV.Eta());
  
bool unbiased = true;
  if(unbiased){
    D0_branch_l0_MM = mu0->d0Unbiased;
    D0_branch_l1_MM = mu1->d0Unbiased;
    D0err_branch_l0_MM = mu0->errD0Unbiased;
    D0err_branch_l1_MM = mu1->errD0Unbiased;
  }
  else{
    D0_branch_l0_MM = mu0->d0;
    D0_branch_l1_MM = mu1->d0;
    D0err_branch_l0_MM = mu0->errD0;
    D0err_branch_l1_MM = mu1->errD0;
  }
  
  sD0Signif_branch_l0_MM = calc_D0(unbiased, leptons.at(0)) / D0err_branch_l0_MM;
  sD0Signif_branch_l1_MM = calc_D0(unbiased, leptons.at(1)) / D0err_branch_l1_MM;
  
  
  MuonVector Muons_all_vec;
  for(uint im=0; im<susyNt->muo()->size(); ++im){
    Muon* mu = & susyNt->muo()->at(im);
    mu->setState(SysSetting, n0150BugFix);    
    if(mu->Pt() < 6.) continue;
    Muons_all_vec.push_back(mu);
  }
  
  JetVector prejets = getPreJets(&nt, SysSetting); 
  ElectronVector elecs = getPreElectrons(susyNt, SysSetting);
  MuonVector muons = Muons_all_vec;
  JetVector jets  = getPreJets(susyNt, SysSetting);
  TauVector taus = getPreTaus(susyNt, SysSetting);

  //cout<<"Select Taus: "<<selectTaus<<" size: "<<taus.size()<<endl;

  // Now perform the overlap removals
  performOverlap(elecs, muons, taus, jets);

  // Do SFOS removal for Mll < 12 
//   removeSFOSPair(elecs, MLL_MIN);
  removeSFOSPair(muons, MLL_MIN);
  
  //ZcandImpact muons: all muons, only check for distance to signal muons
  mllZcandImpact_MM = -1.;      
  mTllZcandImpact_MM = -1.;
  IClZcandImpact_MM = -5;
  pTlZcandImpact_MM = -1.;
  etalZcandImpact_MM = -1.;
  ptcone30lZcandImpact_MM = -1.;
  etcone30lZcandImpact_MM = -1.;
  d0SiglZcandImpact_MM = -1.;
  z0SinThetalZcandImpact_MM = -1.;
  
  ZcandLep_exists_MM = false;
  ZcandLep_passesPT_MM = true;
  ZcandLep_passesEta_MM = true;
  ZcandLep_passesPTcone_MM = true;
  ZcandLep_passesETcone_MM = true;
  ZcandLep_passesD0_MM = true; 
  ZcandLep_passesZ0_MM = true; 
  ZcandLep_PassesMedium_MM = true;
  ZcandLep_PassesTight_MM = true; 
  ZcandLep_PassesORAndMllCut_MM = false; 
  ZcandLep_PassesPR_MM = true; 
  
  
  
  double DeltaMZ_lZcandImpact = 99999.;  
  MuonVector Muon_ZcandImpact_vec;
  Muon* mu_ZcandImpact_lost;  
  Muon* closest_signal_mu;
  TLorentzVector closest_signal_mu_TLV;
  bool foundCandidate = false;
  for(uint im=0; im<Muons_all_vec.size(); im++){

    Muon* mu_ZcandImpact = Muons_all_vec.at(im);
    mu_ZcandImpact->setState(SysSetting, n0150BugFix);
    
    if((mu_ZcandImpact->DeltaR(*mu0) < 0.05) || (mu_ZcandImpact->DeltaR(*mu1) < 0.05)) continue; //only check for separation of signal leptons

    if(fabs(mu_ZcandImpact->d0Sig(true)) >= MUON_D0SIG_CUT) continue;
    if(fabs(mu_ZcandImpact->z0SinTheta(true)) >= MUON_Z0_SINTHETA_CUT) continue;

    TLorentzVector ZcandImpact_TLV;
    ZcandImpact_TLV.SetPtEtaPhiE(mu_ZcandImpact->Pt(), mu_ZcandImpact->eta ,mu_ZcandImpact->phi, mu_ZcandImpact->Pt()*cosh(mu_ZcandImpact->eta));
    ZcandImpact_TLV.SetPtEtaPhiM(mu_ZcandImpact->Pt(), mu_ZcandImpact->eta ,mu_ZcandImpact->phi, mu_ZcandImpact->m);
    
    float DeltaMZ_l0_ZcandImpact = 999.;
    if(((fabs(MZ - Mll(mu0, mu_ZcandImpact)) < DeltaMZ_lZcandImpact) && ((mu_ZcandImpact->q * mu0->q)<0.))){
      DeltaMZ_l0_ZcandImpact = fabs(MZ - Mll(mu0, mu_ZcandImpact));
      foundCandidate = true;
    }
    float DeltaMZ_l1_ZcandImpact = 999.;
    if(((fabs(MZ - Mll(mu1, mu_ZcandImpact)) < DeltaMZ_lZcandImpact) && ((mu_ZcandImpact->q * mu1->q)<0.))){
      DeltaMZ_l1_ZcandImpact = fabs(MZ - Mll(mu1, mu_ZcandImpact));
      foundCandidate = true;
    }
    
    if(foundCandidate && ((fabs(MZ - Mll(mu1, mu_ZcandImpact)) < DeltaMZ_lZcandImpact) || (fabs(MZ - Mll(mu0, mu_ZcandImpact)) < DeltaMZ_lZcandImpact))){

      mu_ZcandImpact_lost = mu_ZcandImpact;
      if(DeltaMZ_l0_ZcandImpact < DeltaMZ_l1_ZcandImpact){
	closest_signal_mu = mu0;
	closest_signal_mu_TLV = mu0_TLV;
      }
      else{
	closest_signal_mu = mu1;
	closest_signal_mu_TLV = mu1_TLV;
      }
      mllZcandImpact_MM = Mll(closest_signal_mu, mu_ZcandImpact);      
      mTllZcandImpact_MM = calcMt(closest_signal_mu_TLV, ZcandImpact_TLV);  
      IClZcandImpact_MM = mu_ZcandImpact->isCombined;
      pTlZcandImpact_MM = mu_ZcandImpact->Pt();
      etalZcandImpact_MM = fabs(mu_ZcandImpact->eta);
      ptcone30lZcandImpact_MM = mu_ZcandImpact->ptcone30ElStyle/std::min(mu_ZcandImpact->pt,MUON_ISO_PT_THRS);
      float etcone30 = muEtConeCorr(mu_ZcandImpact, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false);
      etcone30lZcandImpact_MM = etcone30/std::min(mu_ZcandImpact->pt,MUON_ISO_PT_THRS);	   
      d0SiglZcandImpact_MM = fabs(mu_ZcandImpact->d0Sig(true));
      z0SinThetalZcandImpact_MM = fabs(mu_ZcandImpact->z0SinTheta(true));	
      DeltaMZ_lZcandImpact = fabs(MZ - Mll(closest_signal_mu, mu_ZcandImpact));
      
      Muon_ZcandImpact_vec.push_back(mu_ZcandImpact);
    }
      
  }

    
  Nleptons_ZcandImpact_MM = Muon_ZcandImpact_vec.size(); 
 
  if(Nleptons_ZcandImpact_MM>0){    
    ZcandLep_exists_MM = true;
//     if(fabs(mllZcandImpact_MM - MZ) < 20.){
      if(pTlZcandImpact_MM < 10.) ZcandLep_passesPT_MM = false;
      if(etalZcandImpact_MM >= 2.4) ZcandLep_passesEta_MM = false;
      if(ptcone30lZcandImpact_MM >= MUON_PTCONE30ELSTYLE_PT_WH_CUT) ZcandLep_passesPTcone_MM = false;
      if(etcone30lZcandImpact_MM >= MUON_ETCONE30_PT_WH_CUT) ZcandLep_passesETcone_MM = false;
      if(d0SiglZcandImpact_MM >= MUON_D0SIG_CUT) ZcandLep_passesD0_MM = false;
      if(z0SinThetalZcandImpact_MM >= MUON_Z0_SINTHETA_CUT) ZcandLep_passesZ0_MM = false;
      if(mu_ZcandImpact_lost->truthType != RecoTruthMatch::PROMPT) ZcandLep_PassesPR_MM = false;
      for(unsigned int im = 0; im< muons.size(); im ++){
	if(muons.at(im)->DeltaR(*mu_ZcandImpact_lost) < 0.0001) ZcandLep_PassesORAndMllCut_MM = true;
      }
//     }
    
    if(fabs(mllZcandImpact_MM - MZ) < 20.){
      int lepton_type = -1;
      if(mu_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT) lepton_type = 1;	
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF) lepton_type = 2;	
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
      else lepton_type = 0;      
      h_3rdleptonType_MM->Fill(lepton_type, 1.);
      
      TLorentzVector mu_ZcandImpact_lost_TLV;
      mu_ZcandImpact_lost_TLV.SetPtEtaPhiE(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->Pt()*cosh(mu_ZcandImpact_lost->eta));
      mu_ZcandImpact_lost_TLV.SetPtEtaPhiM(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->m);
      
      
      //study HF lost muons:
      if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
// 	  h_Ntpr_ljOR_HF_MM->Fill(nt.tpr()->size(),  1.);
// 	  
// 	  TruthParticleVector candidates_3rd_truth_lepton;
// 	  TruthParticle* third_truth_particle;
// 	  TLorentzVector third_truth_particle_TLV;
// 	  float DeltaR_min_lostLepton_truthParticle = 999.;
// 	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	  for(uint index=0; index<nt.tpr()->size(); ++index){
// 	    TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	    TLorentzVector truthparticle_TLV;
// 	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    if(mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 	    
// 
// 	    if((truthparticle_TLV.DeltaR(mu0_TLV) < 0.003) || (truthparticle_TLV.DeltaR(mu1_TLV) < 0.003)) continue; //no overlap w/ signal lepton
// 	    third_truth_particle = truthparticle;
// 
// 	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	    candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	  }

// 	  h_DeltaR_min_lostLepton_truthParticle_HF_MM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);


	  //loop over 3rd truth lepton (should only be one):
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 
// 	      if(mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV);	    
// 
// 	    }
// 
// 	    h_DeltaR_min_lostLepton_truthJet_HF_MM->Fill(DeltaR_min_lostLepton_truthJet, 1.);
// 
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	    Jet* prejet = prejets.at(ij);
	    
	    TLorentzVector prejet_TLV;
	    prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	    prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	    if(mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV) < DeltaR_min_lostLepton_preJet){
	      prejet_minDeltaR = prejet;
	      DeltaR_min_lostLepton_preJet = mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);	    
	    }
	    
	    
	  }
	  h_DeltaR_min_lostLepton_preJet_HF_MM->Fill(DeltaR_min_lostLepton_preJet, 1.);
	  
      }
      
          //study LF lost muons:
      if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF){

// 	h_Ntpr_ljOR_LF_MM->Fill(nt.tpr()->size(),  1.);
	  
/*	  
	  TruthParticleVector candidates_3rd_truth_lepton;
	  TruthParticle* third_truth_particle;
	  TLorentzVector third_truth_particle_TLV;
	  float DeltaR_min_lostLepton_truthParticle = 999.;
	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
	  for(uint index=0; index<nt.tpr()->size(); ++index){
	    TruthParticle* truthparticle = & nt.tpr()->at(index);
	    TLorentzVector truthparticle_TLV;
	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    cout << "truthparticle->eta= " << truthparticle->eta << " truthparticle->phi= " << truthparticle->phi <<" truthparticle DeltaR= " << mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) << endl;
	    if(mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
	    

	    if((truthparticle_TLV.DeltaR(mu0_TLV) < 0.003) || (truthparticle_TLV.DeltaR(mu1_TLV) < 0.003)) continue; //no overlap w/ signal lepton
	    third_truth_particle = truthparticle;

	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
	    candidates_3rd_truth_lepton.push_back(third_truth_particle);


	  }

	  h_DeltaR_min_lostLepton_truthParticle_LF_MM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);*/


	  //loop over 3rd truth lepton (should only be one):
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 
// 	      if(mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV);	    
// 
// 	    }
// 
// 	    h_DeltaR_min_lostLepton_truthJet_LF_MM->Fill(DeltaR_min_lostLepton_truthJet, 1.);
// 	  }
	float DeltaR_min_lostLepton_preJet = 999.;
	Jet* prejet_minDeltaR;
	for(uint ij=0; ij<prejets.size(); ij++){ 
	  Jet* prejet = prejets.at(ij);
	  
	  TLorentzVector prejet_TLV;
	  prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	  prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	  if(mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV) < DeltaR_min_lostLepton_preJet){
	    prejet_minDeltaR = prejet;
	    DeltaR_min_lostLepton_preJet = mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);	    
	  }
	  
	  
	}
	h_DeltaR_min_lostLepton_preJet_LF_MM->Fill(DeltaR_min_lostLepton_preJet, 1.);
	  
      }
    }

      
      for(uint ij=0; ij<prejets.size(); ij++){ 
	
	h_DeltaR_JVF_ljOR_MM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), prejets.at(ij)->jvf, 1.);
	h_DeltaR_mll_ljOR_MM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mllZcandImpact_MM, 1.);
	int lepton_type = -1;
	if(mu_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT){
	  lepton_type = 1;
	  h_DeltaR_ptcone_ljOR_PR_MM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mu_ZcandImpact_lost->ptcone30ElStyle/mu_ZcandImpact_lost->Pt(), 1.);
	}
	else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	  lepton_type = 2;
	  h_DeltaR_ptcone_ljOR_HF_MM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mu_ZcandImpact_lost->ptcone30ElStyle/mu_ZcandImpact_lost->Pt(), 1.);
	}
	else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
	else lepton_type = 0;
	
	if(fabs(mllZcandImpact_MM - MZ) < 20.) h_DeltaR_leptonType_ljOR_MM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), lepton_type, 1.);
      }

    }

  mZTT_coll = calcMZTauTau_coll(mu0_TLV, mu1_TLV, met_TLV); 
}

void TSelector_SusyNtuple::calc_EM_variables(LeptonVector &leptons, Electron* el, Muon* mu, TLorentzVector mu_TLV, TLorentzVector el_TLV, TLorentzVector met_TLV, TLorentzVector signalJet0_TLV, TLorentzVector signalJet1_TLV, bool useForwardJets, SusyNtObject* susyNt, float weight_EM, SusyNtSys SysSetting, bool n0150BugFix){
  
  pTl0_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? el_TLV.Pt() : mu_TLV.Pt();
  pTl1_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? mu_TLV.Pt() : el_TLV.Pt();
  etal0_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? el_TLV.Eta() : mu_TLV.Eta();
  etal1_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? mu_TLV.Eta() : el_TLV.Eta();
  DeltaR_EM = fabs(mu_TLV.DeltaR(el_TLV));
  pTll_EM = (mu_TLV + el_TLV).Pt();
  Mll_EM= Mll(mu, el);
  METrel_EM = recalcMetRel(met_TLV, mu_TLV, el_TLV, m_signalJets2Lep, useForwardJets);
  MET_EM = met_TLV.Pt();
  HT_EM = calcHT(mu_TLV, el_TLV, met_TLV, m_signalJets2Lep);
  mTWW_EM = calcMt((mu_TLV + el_TLV), met_TLV);
  mT_EM= calcMt((mu_TLV+el_TLV), met_TLV);
  mTmin_EM = (calcMt(mu_TLV, met_TLV) > calcMt(el_TLV, met_TLV)) ? calcMt(el_TLV, met_TLV) : calcMt(mu_TLV, met_TLV);
  mTmax_EM = (calcMt(mu_TLV, met_TLV) < calcMt(el_TLV, met_TLV)) ? calcMt(el_TLV, met_TLV) : calcMt(mu_TLV, met_TLV);
  mTl0MET_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? calcMt(el_TLV, met_TLV) : calcMt(mu_TLV, met_TLV);
  mTl1MET_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? calcMt(mu_TLV, met_TLV) : calcMt(el_TLV, met_TLV);
  mMET_EM = (mu_TLV + el_TLV + met_TLV).M();
  DeltaPhi_EM = fabs(mu_TLV.DeltaPhi(el_TLV));
  DeltaPhiMETl0_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? fabs(el_TLV.DeltaPhi(met_TLV)) : fabs(mu_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETl1_EM = (el_TLV.Pt() > mu_TLV.Pt()) ? fabs(mu_TLV.DeltaPhi(met_TLV)) : fabs(el_TLV.DeltaPhi(met_TLV));
  DeltaPhiMETll_EM = fabs((mu_TLV + el_TLV).DeltaPhi(met_TLV));
  if(nSignalJets>0){
    DeltaPhilljj_EM = (nSignalJets>1) ? fabs((el_TLV + mu_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : fabs((el_TLV + mu_TLV).DeltaPhi(signalJet0_TLV));
    DeltaPhil0jj_EM = (nSignalJets>1) ? ((mu_TLV.Pt()> el_TLV.Pt()) ? (mu_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (el_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((mu_TLV.Pt()> el_TLV.Pt()) ? (mu_TLV).DeltaPhi(signalJet0_TLV) : (el_TLV).DeltaPhi(signalJet0_TLV));
    DeltaPhil1jj_EM = (nSignalJets>1) ? ((mu_TLV.Pt()< el_TLV.Pt()) ? (el_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV) : (mu_TLV).DeltaPhi(signalJet0_TLV + signalJet1_TLV)) : ((mu_TLV.Pt()< el_TLV.Pt()) ? (el_TLV).DeltaPhi(signalJet0_TLV) : (mu_TLV).DeltaPhi(signalJet0_TLV));
    DeltaRlljj_EM = (nSignalJets>1) ? (mu_TLV + el_TLV).DeltaR(signalJet0_TLV + signalJet1_TLV) : (mu_TLV + el_TLV).DeltaR(signalJet0_TLV);
  }
  
  //Mljj: invariant mass of the lepton-dijet system formed by the two highest pT jets and the lepton closest to the dijet axis.
  Mljj_EM = -1.;
  Mlj_EM = -1.;
  if(nSignalJets>1){
    //find dijet axis:
    double DeltaRDijetMu = mu_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - mu_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu_TLV.Phi()),2));
    double DeltaRDijetEl = el_TLV.DeltaR(signalJet0_TLV + signalJet1_TLV); //sqrt(pow(fabs(etaDijetAxis - el_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el_TLV.Phi()),2));
    TLorentzVector closestLepDijetAxis_TLV = (DeltaRDijetMu > DeltaRDijetEl) ? el_TLV : mu_TLV;

    Mljj_EM = (signalJet0_TLV + signalJet1_TLV + closestLepDijetAxis_TLV).M();

  }
  if(nSignalJets>0){
    //find dijet axis:
    double DeltaRDijetMu = mu_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - mu_TLV.Eta()),2) + pow(fabs(phiDijetAxis - mu_TLV.Phi()),2));
    double DeltaRDijetEl = el_TLV.DeltaR(signalJet0_TLV); //sqrt(pow(fabs(etaDijetAxis - el_TLV.Eta()),2) + pow(fabs(phiDijetAxis - el_TLV.Phi()),2));
    TLorentzVector closestLepDijetAxis_TLV = (DeltaRDijetMu > DeltaRDijetEl) ? el_TLV : mu_TLV;

    Mlj_EM = (signalJet0_TLV + closestLepDijetAxis_TLV).M();

  }
  
  mT2_EM = calcMT2(met_TLV, el_TLV, mu_TLV);
  if(nSignalJets>1) mT2J_EM = calcMT2J(met_TLV, el_TLV, mu_TLV, signalJet0_TLV, signalJet1_TLV);
  
  DeltaEtall_EM = fabs(mu_TLV.Eta() - el_TLV.Eta());  
  
bool unbiased = true;
  if(unbiased){
    D0_branch_l0_EM = leptons.at(0)->d0Unbiased;
    D0_branch_l1_EM = leptons.at(1)->d0Unbiased;
    D0err_branch_l0_EM = leptons.at(0)->errD0Unbiased;
    D0err_branch_l1_EM = leptons.at(1)->errD0Unbiased;
  }
  else{
    D0_branch_l0_EM = leptons.at(0)->d0;
    D0_branch_l1_EM = leptons.at(1)->d0;
    D0err_branch_l0_EM = leptons.at(0)->errD0;
    D0err_branch_l1_EM = leptons.at(1)->errD0;
  }
  
  sD0Signif_branch_l0_EM = calc_D0(unbiased, leptons.at(0)) / D0err_branch_l0_EM;
  sD0Signif_branch_l1_EM = calc_D0(unbiased, leptons.at(1)) / D0err_branch_l1_EM;
      
  MuonVector Muons_all_vec;
  for(uint im=0; im<susyNt->muo()->size(); ++im){
    Muon* mu = & susyNt->muo()->at(im);
    mu->setState(SysSetting, n0150BugFix); 
    if(mu->Pt() < 6.) continue;
    Muons_all_vec.push_back(mu);
  }
  
  ElectronVector Electrons_all_vec;
  for(uint ie=0; ie<susyNt->ele()->size(); ++ie){
    Electron* e = & susyNt->ele()->at(ie);
    e->setState(SysSetting);
    if(e->Pt() < 6.) continue;
    Electrons_all_vec.push_back(e);
  }
  JetVector prejets = getPreJets(&nt, SysSetting); 
  ElectronVector elecs_mu = getPreElectrons(susyNt, SysSetting);
  MuonVector muons_mu = Muons_all_vec;
  JetVector jets_mu  = getPreJets(susyNt, SysSetting);
  TauVector taus_mu = getPreTaus(susyNt, SysSetting);

  // Now perform the overlap removals
  performOverlap(elecs_mu, muons_mu, taus_mu, jets_mu);

  // Do SFOS removal for Mll < 12 
//   removeSFOSPair(elecs_mu, MLL_MIN);
  removeSFOSPair(muons_mu, MLL_MIN);
  
  ElectronVector elecs_el = Electrons_all_vec;
  MuonVector muons_el = getPreMuons(susyNt, SysSetting, n0150BugFix);
  JetVector jets_el  = getPreJets(susyNt, SysSetting);
  TauVector taus_el = getPreTaus(susyNt, SysSetting);

  // Now perform the overlap removals
  performOverlap(elecs_el, muons_el, taus_el, jets_el);

  // Do SFOS removal for Mll < 12 
  removeSFOSPair(elecs_el, MLL_MIN);
//   removeSFOSPair(muons_el, MLL_MIN);
  
  //ZcandImpact muons: all muons, only check for distance to signal muons
  
  mllZcandImpact_mu_EM = -1.;      
  mTllZcandImpact_mu_EM = -1.;
  IClZcandImpact_mu_EM = -5;
  pTlZcandImpact_mu_EM = -1.;
  etalZcandImpact_mu_EM = -1.;
  ptcone30lZcandImpact_mu_EM = -1.;
  etcone30lZcandImpact_mu_EM = -1.;
  d0SiglZcandImpact_mu_EM = -1.;
  z0SinThetalZcandImpact_mu_EM = -1.;
  
  mllZcandImpact_el_EM = -1.;      
  mTllZcandImpact_el_EM = -1.;
  IClZcandImpact_el_EM = -5;
  pTlZcandImpact_el_EM = -1.;
  etalZcandImpact_el_EM = -1.;
  ptcone30lZcandImpact_el_EM = -1.;
  etcone30lZcandImpact_el_EM = -1.;
  d0SiglZcandImpact_el_EM = -1.;
  z0SinThetalZcandImpact_el_EM = -1.;
  
  ZcandLep_exists_mu_EM = false; 
  ZcandLep_passesPT_mu_EM = true;
  ZcandLep_passesEta_mu_EM = true;
  ZcandLep_passesPTcone_mu_EM = true;
  ZcandLep_passesETcone_mu_EM = true;
  ZcandLep_passesD0_mu_EM = true; 
  ZcandLep_passesZ0_mu_EM = true; 
  ZcandLep_PassesMedium_mu_EM = true;
  ZcandLep_PassesTight_mu_EM = true; 
  ZcandLep_PassesORAndMllCut_mu_EM = false;
  ZcandLep_PassesPR_mu_EM = true;
  
  ZcandLep_exists_el_EM = false;
  ZcandLep_passesPT_el_EM = true;
  ZcandLep_passesEta_el_EM = true;
  ZcandLep_passesPTcone_el_EM = true;
  ZcandLep_passesETcone_el_EM = true;
  ZcandLep_passesD0_el_EM = true; 
  ZcandLep_passesZ0_el_EM = true; 
  ZcandLep_PassesMedium_el_EM = true;
  ZcandLep_PassesTight_el_EM = true;
  ZcandLep_PassesORAndMllCut_el_EM = false;
  ZcandLep_PassesPR_el_EM = true;
  
  
  
  double DeltaMZ_lZcandImpact_mu = 99999.;  
  double DeltaMZ_lZcandImpact_el = 99999.;  
  MuonVector Muon_ZcandImpact_vec;
  ElectronVector Electron_ZcandImpact_vec;
  Muon* mu_ZcandImpact_lost; 
  Electron* el_ZcandImpact_lost; 

  bool isMu = false;
  bool isEl = false;
  
  Muon* mu_ZcandImpact;
  //loop over all muons and electrons, check for separation from signal leptons (in the meaning of DeltaR). If one SFOS pair is closer to Zmass, use this third lepton. Mark if it is electron or muon with 'isEl' and 'isMu'
  for(uint im=0; im<Muons_all_vec.size(); im++){
    mu_ZcandImpact = Muons_all_vec.at(im);
    mu_ZcandImpact->setState(SysSetting, n0150BugFix);
    
    
    if((mu_ZcandImpact->DeltaR(*mu) < 0.05) || mu_ZcandImpact->DeltaR(*el) < 0.05) continue;  //only check for separation of signal leptons

    if(fabs(mu_ZcandImpact->d0Sig(true)) >= MUON_D0SIG_CUT) continue;
    if(fabs(mu_ZcandImpact->z0SinTheta(true)) >= MUON_Z0_SINTHETA_CUT) continue;
    
    if((mu_ZcandImpact->q * mu->q)<0.){
	if((fabs(MZ - Mll(mu, mu_ZcandImpact)) < DeltaMZ_lZcandImpact_mu)){
	  DeltaMZ_lZcandImpact_mu = fabs(MZ - Mll(mu, mu_ZcandImpact));
	  mu_ZcandImpact_lost = mu_ZcandImpact;
	  Muon_ZcandImpact_vec.push_back(mu_ZcandImpact);
	}
    }
    
  }

  Electron* el_ZcandImpact;
  for(uint ie=0; ie<Electrons_all_vec.size(); ie++){
    el_ZcandImpact = Electrons_all_vec.at(ie);
    el_ZcandImpact->setState(SysSetting);

    if((el_ZcandImpact->DeltaR(*mu) < 0.05) || (el_ZcandImpact->DeltaR(*el) < 0.05)) continue; //only check for separation of signal leptons

    if(fabs(el_ZcandImpact->d0Sig(true)) >= ELECTRON_D0SIG_CUT_WH) continue;
    if(fabs(el_ZcandImpact->z0SinTheta(true)) >= ELECTRON_Z0_SINTHETA_CUT) continue;
    
    
    
    if((el_ZcandImpact->q * el->q)<0.){
      if(fabs(MZ - Mll(el, el_ZcandImpact)) < DeltaMZ_lZcandImpact_el){
	DeltaMZ_lZcandImpact_el = fabs(MZ - Mll(el, el_ZcandImpact));
	el_ZcandImpact_lost = el_ZcandImpact;
	Electron_ZcandImpact_vec.push_back(el_ZcandImpact);
      }
    }
  }
  
 
  if(DeltaMZ_lZcandImpact_mu < DeltaMZ_lZcandImpact_el) isMu = true;
 
  else if (DeltaMZ_lZcandImpact_mu > DeltaMZ_lZcandImpact_el) isEl = true;
    
  
  if(isMu){
    
    TLorentzVector ZcandImpactMuon_TLV;
    ZcandImpactMuon_TLV.SetPtEtaPhiE(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->Pt()*cosh(mu_ZcandImpact_lost->eta));
    ZcandImpactMuon_TLV.SetPtEtaPhiM(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->m);
      
    mllZcandImpact_mu_EM = Mll(mu, mu_ZcandImpact_lost);  
    mTllZcandImpact_mu_EM = calcMt(mu_TLV, ZcandImpactMuon_TLV);  
    IClZcandImpact_mu_EM = mu_ZcandImpact_lost->isCombined;
    pTlZcandImpact_mu_EM = mu_ZcandImpact_lost->Pt();
    etalZcandImpact_mu_EM = fabs(mu_ZcandImpact_lost->eta);
    ptcone30lZcandImpact_mu_EM = mu_ZcandImpact_lost->ptcone30ElStyle/std::min(mu_ZcandImpact_lost->pt,MUON_ISO_PT_THRS);
    float etcone30 = muEtConeCorr(mu_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC, false);
    etcone30lZcandImpact_mu_EM = etcone30/std::min(mu_ZcandImpact_lost->pt,MUON_ISO_PT_THRS);  
    d0SiglZcandImpact_mu_EM = fabs(mu_ZcandImpact_lost->d0Sig(true));
    z0SinThetalZcandImpact_mu_EM = fabs(mu_ZcandImpact_lost->z0SinTheta(true));	
 
  }
  
  if( isEl){    
    TLorentzVector ZcandImpactElec_TLV;
    ZcandImpactElec_TLV.SetPtEtaPhiE(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->Pt()*cosh(el_ZcandImpact_lost->eta));
    ZcandImpactElec_TLV.SetPtEtaPhiM(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->m);
      
    mllZcandImpact_el_EM = Mll(el, el_ZcandImpact_lost);      
    mTllZcandImpact_el_EM = calcMt(el_TLV, ZcandImpactElec_TLV);  
    pTlZcandImpact_el_EM = el_ZcandImpact_lost->Pt();
    etalZcandImpact_el_EM = fabs(el_ZcandImpact_lost->eta);
    float ptcone30 = elPtConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
    ptcone30lZcandImpact_el_EM = ptcone30/std::min(el_ZcandImpact_lost->pt,ELECTRON_ISO_PT_THRS);
    
    float etcone = elEtTopoConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
    etcone30lZcandImpact_el_EM = etcone/std::min(el_ZcandImpact_lost->pt,ELECTRON_ISO_PT_THRS);		    	  	    
    d0SiglZcandImpact_el_EM = fabs(el_ZcandImpact_lost->d0Sig(true));
    z0SinThetalZcandImpact_el_EM = fabs(el_ZcandImpact_lost->z0SinTheta(true));	

  }
  
  


  Nleptons_ZcandImpact_mu_EM = Muon_ZcandImpact_vec.size();
  Nleptons_ZcandImpact_el_EM = Electron_ZcandImpact_vec.size();
  
  
  if(isMu){    
    ZcandLep_exists_mu_EM = true;
//     if(fabs(mllZcandImpact_mu_EM - MZ) < 20.){
      if(pTlZcandImpact_mu_EM < 10.) ZcandLep_passesPT_mu_EM = false;
      if(fabs(etalZcandImpact_mu_EM) >= 2.4) ZcandLep_passesEta_mu_EM = false;
      if(ptcone30lZcandImpact_mu_EM >= MUON_PTCONE30ELSTYLE_PT_WH_CUT) ZcandLep_passesPTcone_mu_EM = false;
      if(etcone30lZcandImpact_mu_EM >= MUON_ETCONE30_PT_WH_CUT) ZcandLep_passesETcone_mu_EM = false;
      if(d0SiglZcandImpact_mu_EM >= MUON_D0SIG_CUT) ZcandLep_passesD0_mu_EM = false;
      if(z0SinThetalZcandImpact_mu_EM >= MUON_Z0_SINTHETA_CUT) ZcandLep_passesZ0_mu_EM = false;
      if(mu_ZcandImpact_lost->truthType != RecoTruthMatch::PROMPT) ZcandLep_PassesPR_mu_EM = false;
      for(unsigned int im = 0; im< muons_mu.size(); im ++){
	if(muons_mu.at(im)->DeltaR(*mu_ZcandImpact_lost) < 0.0001) ZcandLep_PassesORAndMllCut_mu_EM = true;
      }
//     }
    if(fabs(mllZcandImpact_mu_EM - MZ) < 20.){
      int lepton_type = -1;
      if(mu_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT) lepton_type = 1;	
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF) lepton_type = 2;	
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
      else lepton_type = 0;      
      h_3rdleptonType_mu_EM->Fill(lepton_type, 1.);
    
    
      TLorentzVector mu_ZcandImpact_lost_TLV;
      mu_ZcandImpact_lost_TLV.SetPtEtaPhiE(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->Pt()*cosh(mu_ZcandImpact_lost->eta));
      mu_ZcandImpact_lost_TLV.SetPtEtaPhiM(mu_ZcandImpact_lost->Pt(), mu_ZcandImpact_lost->eta ,mu_ZcandImpact_lost->phi, mu_ZcandImpact_lost->m);
    //study HF lost muons:	
      if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	
// 	  h_Ntpr_ljOR_HF_mu_EM->Fill(nt.tpr()->size(),  1.);
	  
// 	  TruthParticleVector candidates_3rd_truth_lepton;
// 	  TruthParticle* third_truth_particle;
// 	  TLorentzVector third_truth_particle_TLV;
// 	  float DeltaR_min_lostLepton_truthParticle = 999.;
// 	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	  for(uint index=0; index<nt.tpr()->size(); ++index){
// 	    TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	    TLorentzVector truthparticle_TLV;
// 	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    if(mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 	    
// 
// 	    if(truthparticle_TLV.DeltaR(mu_TLV) < 0.003) continue; //no overlap w/ signal lepton
// 	    third_truth_particle = truthparticle;
// 
// 	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	    candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	  }
// 
// 	  h_DeltaR_min_lostLepton_truthParticle_HF_mu_EM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);


	  //loop over 3rd truth lepton (should only be one):
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 	      if(mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV);	    
// 
// 	    }
// 
// 	    h_DeltaR_min_lostLepton_truthJet_HF_mu_EM->Fill(DeltaR_min_lostLepton_truthJet, 1.);
// 
// 	  }
	  
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	    Jet* prejet = prejets.at(ij);
	    
	    TLorentzVector prejet_TLV;
	    prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	    prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	    if(mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV) < DeltaR_min_lostLepton_preJet){
	      prejet_minDeltaR = prejet;
	      DeltaR_min_lostLepton_preJet = mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);	    
	    }
	    
	    
	  }
	  h_DeltaR_min_lostLepton_preJet_HF_mu_EM->Fill(DeltaR_min_lostLepton_preJet, 1.);
	  
      }
      
          //study LF lost muons:
      if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF){

// 	h_Ntpr_ljOR_LF_mu_EM->Fill(nt.tpr()->size(),  1.);
// 	  
// 	  
// 	  TruthParticleVector candidates_3rd_truth_lepton;
// 	  TruthParticle* third_truth_particle;
// 	  TLorentzVector third_truth_particle_TLV;
// 	  float DeltaR_min_lostLepton_truthParticle = 999.;
// 	  //loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	  for(uint index=0; index<nt.tpr()->size(); ++index){
// 	    TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	    TLorentzVector truthparticle_TLV;
// 	    truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	    truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	    if(mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = mu_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 	    
// 
// 	    if(truthparticle_TLV.DeltaR(mu_TLV) < 0.003) continue; //no overlap w/ signal lepton
// 	    third_truth_particle = truthparticle;
// 
// 	    third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	    third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	    candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	  }
// 
// 	  h_DeltaR_min_lostLepton_truthParticle_LF_mu_EM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);


	  //loop over 3rd truth lepton (should only be one):
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 	      if(mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = mu_ZcandImpact_lost_TLV.DeltaR(truthjet_TLV);	    
// 
// 	    }
// 
// 	    h_DeltaR_min_lostLepton_truthJet_LF_mu_EM->Fill(DeltaR_min_lostLepton_truthJet, 1.);
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	    Jet* prejet = prejets.at(ij);
	    
	    TLorentzVector prejet_TLV;
	    prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	    prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	    if(mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV) < DeltaR_min_lostLepton_preJet){
	      prejet_minDeltaR = prejet;
	      DeltaR_min_lostLepton_preJet = mu_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);	    
	    }
	    
	    
	  }
	  h_DeltaR_min_lostLepton_preJet_LF_mu_EM->Fill(DeltaR_min_lostLepton_preJet, 1.);	  
	  
      }
    }
      
//     if(fabs(mllZcandImpact_mu_EM - MZ) < 20.){
      
    for(uint ij=0; ij<prejets.size(); ij++){ 
      h_DeltaR_JVF_ljOR_mu_EM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), prejets.at(ij)->jvf, 1.);
      h_DeltaR_mll_ljOR_mu_EM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mllZcandImpact_mu_EM, 1.);
      int lepton_type = -1;
      if(mu_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT){
	lepton_type = 1;
	h_DeltaR_ptcone_ljOR_PR_mu_EM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)),mu_ZcandImpact_lost->ptcone30ElStyle/mu_ZcandImpact_lost->Pt(), 1.);
      }
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	lepton_type = 2;
	h_DeltaR_ptcone_ljOR_HF_mu_EM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)),mu_ZcandImpact_lost->ptcone30ElStyle/mu_ZcandImpact_lost->Pt(), 1.);
      }
      else if (mu_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
      else lepton_type = 0;
      if(fabs(mllZcandImpact_mu_EM - MZ) < 20.)h_DeltaR_leptonType_ljOR_mu_EM->Fill(mu_ZcandImpact_lost->DeltaR(*prejets.at(ij)),lepton_type, 1.);
    }
//     }
  }
  
  if(isEl){
    ZcandLep_exists_el_EM = true;
//     if(fabs(mllZcandImpact_el_EM - MZ) < 20.){
      if(pTlZcandImpact_el_EM < 10.) ZcandLep_passesPT_el_EM = false;
      if(ptcone30lZcandImpact_el_EM >= ELECTRON_PTCONE30_PT_WH_CUT) ZcandLep_passesPTcone_el_EM = false;
      if(etcone30lZcandImpact_el_EM >= ELECTRON_TOPOCONE30_PT_WH_CUT) ZcandLep_passesETcone_el_EM = false;
      if(d0SiglZcandImpact_el_EM >= ELECTRON_D0SIG_CUT_WH) ZcandLep_passesD0_el_EM = false;
      if(z0SinThetalZcandImpact_el_EM >= ELECTRON_Z0_SINTHETA_CUT) ZcandLep_passesZ0_el_EM = false;
      ZcandLep_PassesMedium_el_EM = el_ZcandImpact_lost->mediumPP;
      ZcandLep_PassesTight_el_EM = el_ZcandImpact_lost->tightPP;
      if(el_ZcandImpact_lost->truthType != RecoTruthMatch::PROMPT) ZcandLep_PassesPR_el_EM = false;
      for(unsigned int ie = 0; ie< elecs_el.size(); ie ++){
	if(elecs_el.at(ie)->DeltaR(*el_ZcandImpact_lost) < 0.0001) ZcandLep_PassesORAndMllCut_el_EM = true;
      }
//     }
    if(fabs(mllZcandImpact_el_EM - MZ) < 20.){    
      int lepton_type = -1;
      if(el_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT) lepton_type = 1;	
      else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF) lepton_type = 2;	
      else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
      else lepton_type = 0;      

      h_3rdleptonType_el_EM->Fill(lepton_type, 1.);
    
      TLorentzVector el_ZcandImpact_lost_TLV;
      el_ZcandImpact_lost_TLV.SetPtEtaPhiE(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->Pt()*cosh(el_ZcandImpact_lost->eta));
      el_ZcandImpact_lost_TLV.SetPtEtaPhiM(el_ZcandImpact_lost->Pt(), el_ZcandImpact_lost->eta ,el_ZcandImpact_lost->phi, el_ZcandImpact_lost->m);
//      study HF lost electrons:
      if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	  
// 	h_Ntpr_ljOR_HF_el_EM->Fill(nt.tpr()->size(),  1.);
// 	  
// 	TruthParticleVector candidates_3rd_truth_lepton;
// 	TruthParticle* third_truth_particle;
// 	TLorentzVector third_truth_particle_TLV;
// 	
	//loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	float DeltaR_min_lostLepton_truthParticle = 999.;
// 	for(uint index=0; index<nt.tpr()->size(); ++index){
// 	  TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	  TLorentzVector truthparticle_TLV;
// 	  truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	  truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);
// 	  
// 	  if(el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 
// 	      
// 	  if(truthparticle_TLV.DeltaR(el_TLV) < 0.003) continue; //no overlap w/ signal lepton
// 	  third_truth_particle = truthparticle;
// 
// 	  third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	  third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	  candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	    
// 	    
// 	  }
// 	  h_DeltaR_min_lostLepton_truthParticle_HF_el_EM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);

	  //loop over 3rd truth lepton (should only be one):
	  
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 	      if(truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV);
// 	    }
// 	    
// 	    h_DeltaR_min_lostLepton_truthJet_HF_el_EM->Fill(DeltaR_min_lostLepton_truthJet,  1.);
// 	    
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	      Jet* prejet = prejets.at(ij);
	      
	      TLorentzVector prejet_TLV;
	      prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	      prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	      if(prejet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_preJet){
		DeltaR_min_lostLepton_preJet = el_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);
		prejet_minDeltaR = prejet;
	      }
	      
	      
	    }
	    h_DeltaR_min_lostLepton_preJet_HF_el_EM->Fill(DeltaR_min_lostLepton_preJet,  1.);	    
	  
      }
      
      //study LF lost electrons:
      if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF){
	  
// 	h_Ntpr_ljOR_LF_el_EM->Fill(nt.tpr()->size(),  1.);
// 	
// 	TruthParticleVector candidates_3rd_truth_lepton;
// 	TruthParticle* third_truth_particle;
// 	TLorentzVector third_truth_particle_TLV;
// 	
// 	//loop over truth particles: which can be matched to signal leptons, which one is the 3rd one?
// 	float DeltaR_min_lostLepton_truthParticle = 999.;
// 	for(uint index=0; index<nt.tpr()->size(); ++index){
// 	  TruthParticle* truthparticle = & nt.tpr()->at(index);
// 	  TLorentzVector truthparticle_TLV;
// 	  truthparticle_TLV.SetPtEtaPhiE(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->Pt()*cosh(truthparticle->eta));
// 	  truthparticle_TLV.SetPtEtaPhiM(truthparticle->Pt(), truthparticle->eta ,truthparticle->phi, truthparticle->m);	  
// 	  if(el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV) < DeltaR_min_lostLepton_truthParticle) DeltaR_min_lostLepton_truthParticle = el_ZcandImpact_lost_TLV.DeltaR(truthparticle_TLV);	    
// 
// 	      
// 	  if(truthparticle_TLV.DeltaR(el_TLV) < 0.003) continue; //no overlap w/ signal lepton
// 	  third_truth_particle = truthparticle;
// 
// 	  third_truth_particle_TLV.SetPtEtaPhiE(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->Pt()*cosh(third_truth_particle->eta));
// 	  third_truth_particle_TLV.SetPtEtaPhiM(third_truth_particle->Pt(), third_truth_particle->eta ,third_truth_particle->phi, third_truth_particle->m);
// 	  candidates_3rd_truth_lepton.push_back(third_truth_particle);
// 
// 
// 	    
// 	    
// 	  }
// 	  h_DeltaR_min_lostLepton_truthParticle_LF_el_EM->Fill(DeltaR_min_lostLepton_truthParticle, 1.);

	  //loop over 3rd truth lepton (should only be one):
	  
// 	  for(uint i = 0; i < candidates_3rd_truth_lepton.size(); i++){
// 
// 	    float DeltaR_min_lostLepton_truthJet = 999.;
// 	    //can this be matched to one of the truth jets?
// 	    for(uint index=0; index<nt.tjt()->size(); ++index){
// 	      TruthJet* truthjet = & nt.tjt()->at(index);
// 	      TLorentzVector truthjet_TLV;
// 	      truthjet_TLV.SetPtEtaPhiE(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->Pt()*cosh(truthjet->eta));
// 	      truthjet_TLV.SetPtEtaPhiM(truthjet->Pt(), truthjet->eta ,truthjet->phi, truthjet->m);
// 	      if(truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_truthJet) DeltaR_min_lostLepton_truthJet = truthjet_TLV.DeltaR(el_ZcandImpact_lost_TLV);
// 	    }
// 	    
// 	    h_DeltaR_min_lostLepton_truthJet_LF_el_EM->Fill(DeltaR_min_lostLepton_truthJet,  1.);
// 	    
// 	  }
	  float DeltaR_min_lostLepton_preJet = 999.;
	  Jet* prejet_minDeltaR;
	  for(uint ij=0; ij<prejets.size(); ij++){ 
	      Jet* prejet = prejets.at(ij);
	      
	      TLorentzVector prejet_TLV;
	      prejet_TLV.SetPtEtaPhiE(prejet->Pt(), prejet->eta ,prejet->phi, prejet->Pt()*cosh(prejet->eta));
	      prejet_TLV.SetPtEtaPhiM(prejet->Pt(), prejet->eta ,prejet->phi, prejet->m);
	      if(prejet_TLV.DeltaR(el_ZcandImpact_lost_TLV) < DeltaR_min_lostLepton_preJet){
		DeltaR_min_lostLepton_preJet = el_ZcandImpact_lost_TLV.DeltaR(prejet_TLV);
		prejet_minDeltaR = prejet;
	      }
	      
	      
	    }
	    h_DeltaR_min_lostLepton_preJet_LF_el_EM->Fill(DeltaR_min_lostLepton_preJet,  1.);    
	  
      }
    }
      for(uint ij=0; ij<prejets.size(); ij++){ 
	float etcone = elEtTopoConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	float ptcone30 = elPtConeCorr(el_ZcandImpact_lost, m_baseElectrons, m_baseMuons, nt.evt()->nVtx, nt.evt()->isMC);
	h_DeltaR_JVF_ljOR_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), prejets.at(ij)->jvf, 1.);
	h_DeltaR_mll_ljOR_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)), mllZcandImpact_el_EM, 1.);
	int lepton_type = -1;
	if(el_ZcandImpact_lost->truthType == RecoTruthMatch::PROMPT){
	  lepton_type = 1;
	  h_DeltaR_ptcone_ljOR_PR_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)),ptcone30/el_ZcandImpact_lost->Pt(),  1.);
	  h_DeltaR_etcone_ljOR_PR_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)),etcone/el_ZcandImpact_lost->Pt(), 1.);
	}
	else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::HF){
	  lepton_type = 2;
	  h_DeltaR_ptcone_ljOR_HF_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)),ptcone30/el_ZcandImpact_lost->Pt(), 1.);
	  h_DeltaR_etcone_ljOR_HF_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)),etcone/el_ZcandImpact_lost->Pt(), 1.);
	}
	else if (el_ZcandImpact_lost->truthType == RecoTruthMatch::LF) lepton_type = 3;
	else lepton_type = 0;
	if(fabs(mllZcandImpact_el_EM - MZ) < 20.)h_DeltaR_leptonType_ljOR_el_EM->Fill(el_ZcandImpact_lost->DeltaR(*prejets.at(ij)),lepton_type, 1.);
      }
    }


  
  
  mZTT_coll = calcMZTauTau_coll(el_TLV, mu_TLV, met_TLV); 
}

  

void TSelector_SusyNtuple::fillHistos_EE_SRSS1(float cut_EE, float weight_ALL_EE){
  fillHistos_EE(cut_EE, weight_ALL_EE);
  h_DeltaRLeptons_EE_SRSS1->Fill(DeltaR_EE, cut_EE, weight_ALL_EE); 
  h_pTl0_EE_SRSS1->Fill(pTl0_EE, cut_EE, weight_ALL_EE); 
  h_pTl0_raw_EE_SRSS1->Fill(pTl0_EE, cut_EE, 1.); 
  h_pTl1_EE_SRSS1->Fill(pTl1_EE, cut_EE, weight_ALL_EE); 
  h_pTj0_EE_SRSS1->Fill(pTj0, cut_EE, weight_ALL_EE); 
  h_pTj1_EE_SRSS1->Fill(pTj1, cut_EE, weight_ALL_EE); 
  h_mll_EE_SRSS1->Fill(Mll_EE, cut_EE, weight_ALL_EE); 
  h_METrel_EE_SRSS1->Fill(METrel_EE, cut_EE, weight_ALL_EE); 
  h_MET_EE_SRSS1->Fill(MET_EE, cut_EE, weight_ALL_EE); 
  h_HT_EE_SRSS1->Fill(HT_EE, cut_EE, weight_ALL_EE); 
  h_mWWt_EE_SRSS1->Fill(mTWW_EE, cut_EE, weight_ALL_EE); 
  h_mTlmin_EE_SRSS1->Fill(mTmin_EE, cut_EE, weight_ALL_EE); 
  h_mTlmax_EE_SRSS1->Fill(mTmax_EE, cut_EE, weight_ALL_EE); 
  h_meff_EE_SRSS1->Fill(meff, cut_EE, weight_ALL_EE); 
  h_mT2_EE_SRSS1->Fill(mT2_EE, cut_EE, weight_ALL_EE); 
  h_mT2J_EE_SRSS1->Fill(mT2J_EE, cut_EE, weight_ALL_EE); 
  h_mjj_EE_SRSS1->Fill(mjj, cut_EE, weight_ALL_EE); 
  h_DeltaPhiMETll_EE_SRSS1->Fill(DeltaPhiMETll_EE, cut_EE, weight_ALL_EE); 
  h_DeltaPhill_EE_SRSS1->Fill(DeltaPhi_EE, cut_EE, weight_ALL_EE); 
  h_NBJets_EE_SRSS1->Fill(NBJets, cut_EE, weight_ALL_EE); 
  h_NCJets_EE_SRSS1->Fill(NCJets, cut_EE, weight_ALL_EE); 
  h_NFJets_EE_SRSS1->Fill(NFJets, cut_EE, weight_ALL_EE); 
  h_mZTT_coll_EE_SRSS1->Fill(mZTT_coll, cut_EE, weight_ALL_EE); 
  h_mZTT_mmc_EE_SRSS1->Fill(mZTT_mmc, cut_EE, weight_ALL_EE); 
  
  h_DeltaPhijj_EE_SRSS1->Fill(DeltaPhijj, cut_EE, weight_ALL_EE);  
  h_pTjj_EE_SRSS1->Fill(pTjj, cut_EE, weight_ALL_EE);  
  h_pTll_EE_SRSS1->Fill(pTll_EE, cut_EE, weight_ALL_EE);  
  h_DeltaPhiMETl0_EE_SRSS1->Fill(DeltaPhiMETl0_EE, cut_EE, weight_ALL_EE);  
  h_DeltaPhiMETl1_EE_SRSS1->Fill(DeltaPhiMETl1_EE, cut_EE, weight_ALL_EE);    
  h_DeltaPhiMETj0_EE_SRSS1->Fill(DeltaPhiMETj0, cut_EE, weight_ALL_EE);  
  h_DeltaPhiMETj1_EE_SRSS1->Fill(DeltaPhiMETj1, cut_EE, weight_ALL_EE);  
  h_DeltaPhiMETjj_EE_SRSS1->Fill(DeltaPhiMETjj, cut_EE, weight_ALL_EE);  
  h_DeltaRjj_EE_SRSS1->Fill(DeltaRjj, cut_EE, weight_ALL_EE);  

  h_etal0_EE_SRSS1->Fill(fabs(etal0_EE), cut_EE, weight_ALL_EE);  
  h_etal1_EE_SRSS1->Fill(fabs(etal1_EE), cut_EE, weight_ALL_EE);  
  h_etaj0_EE_SRSS1->Fill(fabs(eta_j0), cut_EE, weight_ALL_EE);  
  h_etaj1_EE_SRSS1->Fill(fabs(eta_j1), cut_EE, weight_ALL_EE);  
  h_mTl0MET_EE_SRSS1->Fill(mTl0MET_EE, cut_EE, weight_ALL_EE);  
  h_mTl1MET_EE_SRSS1->Fill(mTl1MET_EE, cut_EE, weight_ALL_EE);  
  h_DeltaPhilljj_EE_SRSS1->Fill(DeltaPhilljj_EE, cut_EE, weight_ALL_EE);  
  h_DeltaPhil0jj_EE_SRSS1->Fill(DeltaPhil0jj_EE, cut_EE, weight_ALL_EE);  
  h_DeltaPhil1jj_EE_SRSS1->Fill(DeltaPhil1jj_EE, cut_EE, weight_ALL_EE);  
  h_DeltaRlljj_EE_SRSS1->Fill(DeltaRlljj_EE, cut_EE, weight_ALL_EE);  
  h_DeltaEtajj_EE_SRSS1->Fill(DeltaEtajj, cut_EE, weight_ALL_EE);  
  h_DeltaEtall_EE_SRSS1->Fill(DeltaEtall_EE, cut_EE, weight_ALL_EE);  
  h_mTll_EE_SRSS1->Fill(mT_EE, cut_EE, weight_ALL_EE);  
  h_mMETll_EE_SRSS1->Fill(mMET_EE, cut_EE, weight_ALL_EE);  
  h_DeltaYjj_EE_SRSS1->Fill(DeltaYjj, cut_EE, weight_ALL_EE);  
  
  h_D0_branch_l0_EE_SRSS1->Fill(D0_branch_l0_EE, cut_EE, weight_ALL_EE);  
  h_D0_branch_l1_EE_SRSS1->Fill(D0_branch_l1_EE, cut_EE, weight_ALL_EE);  
  h_D0Signif_branch_l0_EE_SRSS1->Fill(sD0Signif_branch_l0_EE, cut_EE, weight_ALL_EE);  
  h_D0Signif_branch_l1_EE_SRSS1->Fill(sD0Signif_branch_l1_EE, cut_EE, weight_ALL_EE);  

  h_Mljj_EE_SRSS1->Fill(Mljj_EE, cut_EE, weight_ALL_EE);  
  h_Mlj_EE_SRSS1->Fill(Mlj_EE, cut_EE, weight_ALL_EE);  

  
  
  h_Nleptons_ZcandImpact_EE_SRSS1->Fill(Nleptons_ZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_mllZcandImpact_EE_SRSS1->Fill(mllZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_mTllZcandImpact_EE_SRSS1->Fill(mTllZcandImpact_EE, cut_EE, weight_ALL_EE);  
//   h_IClZcandImpact_EE_SRSS1->Fill(IClZcandImpact_EE, cut_EE, weight_ALL_EE);
  h_pTlZcandImpact_EE_SRSS1->Fill(pTlZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_etalZcandImpact_EE_SRSS1->Fill(etalZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_ptcone30lZcandImpact_EE_SRSS1->Fill(ptcone30lZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_etcone30lZcandImpact_EE_SRSS1->Fill(etcone30lZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_d0SiglZcandImpact_EE_SRSS1->Fill(d0SiglZcandImpact_EE, cut_EE, weight_ALL_EE);  
  h_z0SinThetalZcandImpact_EE_SRSS1->Fill(z0SinThetalZcandImpact_EE, cut_EE, weight_ALL_EE);  
  

  if(ZcandLep_exists_EE){
    h_failedSignalCriteria_EE->Fill(1., cut_EE, weight_ALL_EE);
    if(!ZcandLep_passesPT_EE) h_failedSignalCriteria_EE->Fill(2., cut_EE, weight_ALL_EE);
  //   if(!ZcandLep_passesEta_EE) h_failedSignalCriteria_EE->Fill(3., cut_EE, weight_ALL_EE);
    if(!ZcandLep_passesPTcone_EE) h_failedSignalCriteria_EE->Fill(4., cut_EE, weight_ALL_EE);
    if(!ZcandLep_passesETcone_EE) h_failedSignalCriteria_EE->Fill(5., cut_EE, weight_ALL_EE);
    if(!ZcandLep_passesD0_EE) h_failedSignalCriteria_EE->Fill(6., cut_EE, weight_ALL_EE);
    if(!ZcandLep_passesZ0_EE) h_failedSignalCriteria_EE->Fill(7., cut_EE, weight_ALL_EE);
    if(!ZcandLep_PassesMedium_EE) h_failedSignalCriteria_EE->Fill(8., cut_EE, weight_ALL_EE);
    if(!ZcandLep_PassesTight_EE) h_failedSignalCriteria_EE->Fill(9., cut_EE, weight_ALL_EE);
    if(!ZcandLep_PassesORAndMllCut_EE) h_failedSignalCriteria_EE->Fill(10., cut_EE, weight_ALL_EE);  
    if(!ZcandLep_PassesPR_EE) h_failedSignalCriteria_EE->Fill(11., cut_EE, weight_ALL_EE);  
  }
}


void TSelector_SusyNtuple::fillHistos_MM_SRSS1(float cut_MM, float weight_ALL_MM){
  
  fillHistos_MM(cut_MM, weight_ALL_MM);

  h_DeltaRLeptons_MM_SRSS1->Fill(DeltaR_MM, cut_MM, weight_ALL_MM); 
  h_pTl0_MM_SRSS1->Fill(pTl0_MM, cut_MM, weight_ALL_MM); 
  h_pTl0_raw_MM_SRSS1->Fill(pTl0_MM, cut_MM, 1.); 
  h_pTl1_MM_SRSS1->Fill(pTl1_MM, cut_MM, weight_ALL_MM); 
  h_pTj0_MM_SRSS1->Fill(pTj0, cut_MM, weight_ALL_MM); 
  h_pTj1_MM_SRSS1->Fill(pTj1, cut_MM, weight_ALL_MM); 
  h_mll_MM_SRSS1->Fill(Mll_MM, cut_MM, weight_ALL_MM); 
  h_METrel_MM_SRSS1->Fill(METrel_MM, cut_MM, weight_ALL_MM); 
  h_MET_MM_SRSS1->Fill(MET_MM, cut_MM, weight_ALL_MM); 
  h_HT_MM_SRSS1->Fill(HT_MM, cut_MM, weight_ALL_MM); 
  h_mWWt_MM_SRSS1->Fill(mTWW_MM, cut_MM, weight_ALL_MM); 
  h_mTlmin_MM_SRSS1->Fill(mTmin_MM, cut_MM, weight_ALL_MM); 
  h_mTlmax_MM_SRSS1->Fill(mTmax_MM, cut_MM, weight_ALL_MM); 
  h_meff_MM_SRSS1->Fill(meff, cut_MM, weight_ALL_MM); 
  h_mT2_MM_SRSS1->Fill(mT2_MM, cut_MM, weight_ALL_MM); 
  h_mT2J_MM_SRSS1->Fill(mT2J_MM, cut_MM, weight_ALL_MM); 
  h_mjj_MM_SRSS1->Fill(mjj, cut_MM, weight_ALL_MM); 
  h_DeltaPhiMETll_MM_SRSS1->Fill(DeltaPhiMETll_MM, cut_MM, weight_ALL_MM); 
  h_DeltaPhill_MM_SRSS1->Fill(DeltaPhi_MM, cut_MM, weight_ALL_MM); 
  h_NBJets_MM_SRSS1->Fill(NBJets, cut_MM, weight_ALL_MM); 
  h_NCJets_MM_SRSS1->Fill(NCJets, cut_MM, weight_ALL_MM); 
  h_NFJets_MM_SRSS1->Fill(NFJets, cut_MM, weight_ALL_MM); 
  h_mZTT_coll_MM_SRSS1->Fill(mZTT_coll, cut_MM, weight_ALL_MM); 
  h_mZTT_mmc_MM_SRSS1->Fill(mZTT_mmc, cut_MM, weight_ALL_MM); 
  
  h_DeltaPhijj_MM_SRSS1->Fill(DeltaPhijj, cut_MM, weight_ALL_MM);  
  h_pTjj_MM_SRSS1->Fill(pTjj, cut_MM, weight_ALL_MM);  
  h_pTll_MM_SRSS1->Fill(pTll_MM, cut_MM, weight_ALL_MM);  
  h_DeltaPhiMETl0_MM_SRSS1->Fill(DeltaPhiMETl0_MM, cut_MM, weight_ALL_MM);  
  h_DeltaPhiMETl1_MM_SRSS1->Fill(DeltaPhiMETl1_MM, cut_MM, weight_ALL_MM);    
  h_DeltaPhiMETj0_MM_SRSS1->Fill(DeltaPhiMETj0, cut_MM, weight_ALL_MM);  
  h_DeltaPhiMETj1_MM_SRSS1->Fill(DeltaPhiMETj1, cut_MM, weight_ALL_MM);  
  h_DeltaPhiMETjj_MM_SRSS1->Fill(DeltaPhiMETjj, cut_MM, weight_ALL_MM);  
  h_DeltaRjj_MM_SRSS1->Fill(DeltaRjj, cut_MM, weight_ALL_MM);  

  h_etal0_MM_SRSS1->Fill(fabs(etal0_MM), cut_MM, weight_ALL_MM);  
  h_etal1_MM_SRSS1->Fill(fabs(etal1_MM), cut_MM, weight_ALL_MM);  
  h_etaj0_MM_SRSS1->Fill(fabs(eta_j0), cut_MM, weight_ALL_MM);  
  h_etaj1_MM_SRSS1->Fill(fabs(eta_j1), cut_MM, weight_ALL_MM);  
  h_mTl0MET_MM_SRSS1->Fill(mTl0MET_MM, cut_MM, weight_ALL_MM);  
  h_mTl1MET_MM_SRSS1->Fill(mTl1MET_MM, cut_MM, weight_ALL_MM);  
  h_DeltaPhilljj_MM_SRSS1->Fill(DeltaPhilljj_MM, cut_MM, weight_ALL_MM);  
  h_DeltaPhil0jj_MM_SRSS1->Fill(DeltaPhil0jj_MM, cut_MM, weight_ALL_MM);  
  h_DeltaPhil1jj_MM_SRSS1->Fill(DeltaPhil1jj_MM, cut_MM, weight_ALL_MM);  
  h_DeltaRlljj_MM_SRSS1->Fill(DeltaRlljj_MM, cut_MM, weight_ALL_MM);  
  h_DeltaEtajj_MM_SRSS1->Fill(DeltaEtajj, cut_MM, weight_ALL_MM);  
  h_DeltaEtall_MM_SRSS1->Fill(DeltaEtall_MM, cut_MM, weight_ALL_MM);  
  h_mTll_MM_SRSS1->Fill(mT_MM, cut_MM, weight_ALL_MM);  
  h_mMETll_MM_SRSS1->Fill(mMET_MM, cut_MM, weight_ALL_MM);  
  h_DeltaYjj_MM_SRSS1->Fill(DeltaYjj, cut_MM, weight_ALL_MM);  
  
  h_D0_branch_l0_MM_SRSS1->Fill(D0_branch_l0_MM, cut_MM, weight_ALL_MM);  
  h_D0_branch_l1_MM_SRSS1->Fill(D0_branch_l1_MM, cut_MM, weight_ALL_MM);  
  h_D0Signif_branch_l0_MM_SRSS1->Fill(sD0Signif_branch_l0_MM, cut_MM, weight_ALL_MM);  
  h_D0Signif_branch_l1_MM_SRSS1->Fill(sD0Signif_branch_l1_MM, cut_MM, weight_ALL_MM);  
  
  h_Mljj_MM_SRSS1->Fill(Mljj_MM, cut_MM, weight_ALL_MM);
  h_Mlj_MM_SRSS1->Fill(Mlj_MM, cut_MM, weight_ALL_MM);
    
  h_Nleptons_ZcandImpact_MM_SRSS1->Fill(Nleptons_ZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_mllZcandImpact_MM_SRSS1->Fill(mllZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_mTllZcandImpact_MM_SRSS1->Fill(mTllZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_IClZcandImpact_MM_SRSS1->Fill(IClZcandImpact_MM, cut_MM, weight_ALL_MM);
  h_pTlZcandImpact_MM_SRSS1->Fill(pTlZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_etalZcandImpact_MM_SRSS1->Fill(etalZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_ptcone30lZcandImpact_MM_SRSS1->Fill(ptcone30lZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_d0SiglZcandImpact_MM_SRSS1->Fill(d0SiglZcandImpact_MM, cut_MM, weight_ALL_MM);  
  h_z0SinThetalZcandImpact_MM_SRSS1->Fill(z0SinThetalZcandImpact_MM, cut_MM, weight_ALL_MM);  
  
  if(ZcandLep_exists_MM){
    h_failedSignalCriteria_MM->Fill(1., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesPT_MM) h_failedSignalCriteria_MM->Fill(2., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesEta_MM) h_failedSignalCriteria_MM->Fill(3., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesPTcone_MM) h_failedSignalCriteria_MM->Fill(4., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesETcone_MM) h_failedSignalCriteria_MM->Fill(5., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesD0_MM) h_failedSignalCriteria_MM->Fill(6., cut_MM, weight_ALL_MM);
    if(!ZcandLep_passesZ0_MM) h_failedSignalCriteria_MM->Fill(7., cut_MM, weight_ALL_MM);
    if(!ZcandLep_PassesORAndMllCut_MM) h_failedSignalCriteria_MM->Fill(10., cut_MM, weight_ALL_MM);  
    if(!ZcandLep_PassesORAndMllCut_MM) h_failedSignalCriteria_MM->Fill(11., cut_MM, weight_ALL_MM);  
  }
}

void TSelector_SusyNtuple::fillHistos_EM_SRSS1(float cut_EM, float weight_ALL_EM){

  fillHistos_EM(cut_EM, weight_ALL_EM);
  h_DeltaRLeptons_EM_SRSS1->Fill(DeltaR_EM, cut_EM, weight_ALL_EM); 
  h_pTl0_EM_SRSS1->Fill(pTl0_EM, cut_EM, weight_ALL_EM); 
  h_pTl0_raw_EM_SRSS1->Fill(pTl0_EM, cut_EM, 1.); 
  h_pTl1_EM_SRSS1->Fill(pTl1_EM, cut_EM, weight_ALL_EM); 
  h_pTj0_EM_SRSS1->Fill(pTj0, cut_EM, weight_ALL_EM); 
  h_pTj1_EM_SRSS1->Fill(pTj1, cut_EM, weight_ALL_EM); 
  h_mll_EM_SRSS1->Fill(Mll_EM, cut_EM, weight_ALL_EM); 
  h_METrel_EM_SRSS1->Fill(METrel_EM, cut_EM, weight_ALL_EM); 
  h_MET_EM_SRSS1->Fill(MET_EM, cut_EM, weight_ALL_EM); 
  h_HT_EM_SRSS1->Fill(HT_EM, cut_EM, weight_ALL_EM); 
  h_mWWt_EM_SRSS1->Fill(mTWW_EM, cut_EM, weight_ALL_EM); 
  h_mTlmin_EM_SRSS1->Fill(mTmin_EM, cut_EM, weight_ALL_EM); 
  h_mTlmax_EM_SRSS1->Fill(mTmax_EM, cut_EM, weight_ALL_EM); 
  h_meff_EM_SRSS1->Fill(meff, cut_EM, weight_ALL_EM); 
  h_mT2_EM_SRSS1->Fill(mT2_EM, cut_EM, weight_ALL_EM); 
  h_mT2J_EM_SRSS1->Fill(mT2J_EM, cut_EM, weight_ALL_EM); 
  h_mjj_EM_SRSS1->Fill(mjj, cut_EM, weight_ALL_EM); 
  h_DeltaPhiMETll_EM_SRSS1->Fill(DeltaPhiMETll_EM, cut_EM, weight_ALL_EM); 
  h_DeltaPhill_EM_SRSS1->Fill(DeltaPhi_EM, cut_EM, weight_ALL_EM); 
  h_NBJets_EM_SRSS1->Fill(NBJets, cut_EM, weight_ALL_EM); 
  h_NCJets_EM_SRSS1->Fill(NCJets, cut_EM, weight_ALL_EM); 
  h_NFJets_EM_SRSS1->Fill(NFJets, cut_EM, weight_ALL_EM); 
  h_mZTT_coll_EM_SRSS1->Fill(mZTT_coll, cut_EM, weight_ALL_EM); 
  h_mZTT_mmc_EM_SRSS1->Fill(mZTT_mmc, cut_EM, weight_ALL_EM); 
  
  h_DeltaPhijj_EM_SRSS1->Fill(DeltaPhijj, cut_EM, weight_ALL_EM);  
  h_pTjj_EM_SRSS1->Fill(pTjj, cut_EM, weight_ALL_EM);  
  h_pTll_EM_SRSS1->Fill(pTll_EM, cut_EM, weight_ALL_EM);  
  h_DeltaPhiMETl0_EM_SRSS1->Fill(DeltaPhiMETl0_EM, cut_EM, weight_ALL_EM);  
  h_DeltaPhiMETl1_EM_SRSS1->Fill(DeltaPhiMETl1_EM, cut_EM, weight_ALL_EM);    
  h_DeltaPhiMETj0_EM_SRSS1->Fill(DeltaPhiMETj0, cut_EM, weight_ALL_EM);  
  h_DeltaPhiMETj1_EM_SRSS1->Fill(DeltaPhiMETj1, cut_EM, weight_ALL_EM);  
  h_DeltaPhiMETjj_EM_SRSS1->Fill(DeltaPhiMETjj, cut_EM, weight_ALL_EM);  
  h_DeltaRjj_EM_SRSS1->Fill(DeltaRjj, cut_EM, weight_ALL_EM);  

  h_etal0_EM_SRSS1->Fill(fabs(etal0_EM), cut_EM, weight_ALL_EM);  
  h_etal1_EM_SRSS1->Fill(fabs(etal1_EM), cut_EM, weight_ALL_EM);  
  h_etaj0_EM_SRSS1->Fill(fabs(eta_j0), cut_EM, weight_ALL_EM);  
  h_etaj1_EM_SRSS1->Fill(fabs(eta_j1), cut_EM, weight_ALL_EM);  
  h_mTl0MET_EM_SRSS1->Fill(mTl0MET_EM, cut_EM, weight_ALL_EM);  
  h_mTl1MET_EM_SRSS1->Fill(mTl1MET_EM, cut_EM, weight_ALL_EM);  
  h_DeltaPhilljj_EM_SRSS1->Fill(DeltaPhilljj_EM, cut_EM, weight_ALL_EM);  
  h_DeltaPhil0jj_EM_SRSS1->Fill(DeltaPhil0jj_EM, cut_EM, weight_ALL_EM);  
  h_DeltaPhil1jj_EM_SRSS1->Fill(DeltaPhil1jj_EM, cut_EM, weight_ALL_EM);  
  h_DeltaRlljj_EM_SRSS1->Fill(DeltaRlljj_EM, cut_EM, weight_ALL_EM);  
  h_DeltaEtajj_EM_SRSS1->Fill(DeltaEtajj, cut_EM, weight_ALL_EM);  
  h_DeltaEtall_EM_SRSS1->Fill(DeltaEtall_EM, cut_EM, weight_ALL_EM);  
  h_mTll_EM_SRSS1->Fill(mT_EM, cut_EM, weight_ALL_EM);  
  h_mMETll_EM_SRSS1->Fill(mMET_EM, cut_EM, weight_ALL_EM);  
  h_DeltaYjj_EM_SRSS1->Fill(DeltaYjj, cut_EM, weight_ALL_EM);  
  
  h_D0_branch_l0_EM_SRSS1->Fill(D0_branch_l0_EM, cut_EM, weight_ALL_EM);  
  h_D0_branch_l1_EM_SRSS1->Fill(D0_branch_l1_EM, cut_EM, weight_ALL_EM);  
  h_D0Signif_branch_l0_EM_SRSS1->Fill(sD0Signif_branch_l0_EM, cut_EM, weight_ALL_EM);  
  h_D0Signif_branch_l1_EM_SRSS1->Fill(sD0Signif_branch_l1_EM, cut_EM, weight_ALL_EM);  

  h_Mljj_EM_SRSS1->Fill(Mljj_EM, cut_EM, weight_ALL_EM);  
  h_Mlj_EM_SRSS1->Fill(Mlj_EM, cut_EM, weight_ALL_EM);  

  h_Nleptons_ZcandImpact_mu_EM_SRSS1->Fill(Nleptons_ZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_mllZcandImpact_mu_EM_SRSS1->Fill(mllZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_mTllZcandImpact_mu_EM_SRSS1->Fill(mTllZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_IClZcandImpact_mu_EM_SRSS1->Fill(IClZcandImpact_mu_EM, cut_EM, weight_ALL_EM);
  h_pTlZcandImpact_mu_EM_SRSS1->Fill(pTlZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_etalZcandImpact_mu_EM_SRSS1->Fill(etalZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_ptcone30lZcandImpact_mu_EM_SRSS1->Fill(ptcone30lZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_etcone30lZcandImpact_mu_EM_SRSS1->Fill(etcone30lZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_d0SiglZcandImpact_mu_EM_SRSS1->Fill(d0SiglZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  h_z0SinThetalZcandImpact_mu_EM_SRSS1->Fill(z0SinThetalZcandImpact_mu_EM, cut_EM, weight_ALL_EM);  
  
  h_Nleptons_ZcandImpact_el_EM_SRSS1->Fill(Nleptons_ZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_mllZcandImpact_el_EM_SRSS1->Fill(mllZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_mTllZcandImpact_el_EM_SRSS1->Fill(mTllZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
//   h_IClZcandImpact_el_EM_SRSS1->Fill(IClZcandImpact_el_EM, cut_EM, weight_ALL_EM);
  h_pTlZcandImpact_el_EM_SRSS1->Fill(pTlZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_etalZcandImpact_el_EM_SRSS1->Fill(etalZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_ptcone30lZcandImpact_el_EM_SRSS1->Fill(ptcone30lZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_etcone30lZcandImpact_el_EM_SRSS1->Fill(etcone30lZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_d0SiglZcandImpact_el_EM_SRSS1->Fill(d0SiglZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
  h_z0SinThetalZcandImpact_el_EM_SRSS1->Fill(z0SinThetalZcandImpact_el_EM, cut_EM, weight_ALL_EM);  
      
    
  if(ZcandLep_exists_mu_EM){
    h_failedSignalCriteria_mu_EM->Fill(1., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesPT_mu_EM) h_failedSignalCriteria_mu_EM->Fill(2., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesEta_mu_EM) h_failedSignalCriteria_mu_EM->Fill(3., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesPTcone_mu_EM) h_failedSignalCriteria_mu_EM->Fill(4., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesETcone_mu_EM) h_failedSignalCriteria_mu_EM->Fill(5., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesD0_mu_EM) h_failedSignalCriteria_mu_EM->Fill(6., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesZ0_mu_EM) h_failedSignalCriteria_mu_EM->Fill(7., cut_EM, weight_ALL_EM);
  //   if(!ZcandLepPassesMedium_mu_EM) h_failedSignalCriteria_mu_EM->Fill(8., cut_EM, weight_ALL_EM);
  //   if(!ZcandLepPassesTight_mu_EM) h_failedSignalCriteria_mu_EM->Fill(9., cut_EM, weight_ALL_EM);
    if(!ZcandLep_PassesORAndMllCut_mu_EM) h_failedSignalCriteria_mu_EM->Fill(10., cut_EM, weight_ALL_EM);  
    if(!ZcandLep_PassesPR_mu_EM) h_failedSignalCriteria_mu_EM->Fill(11., cut_EM, weight_ALL_EM);  
  }
  
  if(ZcandLep_exists_el_EM){
    h_failedSignalCriteria_el_EM->Fill(1., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesPT_el_EM) h_failedSignalCriteria_el_EM->Fill(2., cut_EM, weight_ALL_EM);
  //   if(!ZcandLep_passesEta_EM) h_failedSignalCriteria_l0_EM->Fill(3., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesPTcone_el_EM) h_failedSignalCriteria_el_EM->Fill(4., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesETcone_el_EM) h_failedSignalCriteria_el_EM->Fill(5., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesD0_el_EM) h_failedSignalCriteria_el_EM->Fill(6., cut_EM, weight_ALL_EM);
    if(!ZcandLep_passesZ0_el_EM) h_failedSignalCriteria_el_EM->Fill(7., cut_EM, weight_ALL_EM);
    if(!ZcandLep_PassesMedium_el_EM) h_failedSignalCriteria_el_EM->Fill(8., cut_EM, weight_ALL_EM);
    if(!ZcandLep_PassesTight_el_EM) h_failedSignalCriteria_el_EM->Fill(9., cut_EM, weight_ALL_EM);
    if(!ZcandLep_PassesORAndMllCut_el_EM) h_failedSignalCriteria_el_EM->Fill(10., cut_EM, weight_ALL_EM);  
    if(!ZcandLep_PassesPR_el_EM) h_failedSignalCriteria_el_EM->Fill(11., cut_EM, weight_ALL_EM);  
  }
  
    
    
}

