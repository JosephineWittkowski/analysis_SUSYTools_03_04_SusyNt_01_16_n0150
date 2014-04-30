{
   
  TFile hn("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/histos_ZN_177501_n0150_Truth_BJetDR04_.root");
  hn.Print();
TH1F *alpha_raw = (TH1F*)hn.Get("cutflow_EE");
TH1F *beta_raw = (TH1F*)hn.Get("cutflow_EM");
TH1F *gamma_raw = (TH1F*)hn.Get("cutflow_MM");

cout << "raw events:" << endl;
cout << fixed;

cout << "events             :" << beta_raw->GetBinContent( 1)  << endl;
                                                            
cout << "cut grl            :" << beta_raw->GetBinContent( 2)  << endl; 
cout << "TileTripReader     :" << beta_raw->GetBinContent( 3)  << endl; 
cout << "incomplete veto    :" << beta_raw->GetBinContent( 4)  << endl; 
cout << "cut LArTileError   :" << beta_raw->GetBinContent( 5)  << endl; 
cout << "cut TileCalHotSpot :" << beta_raw->GetBinContent( 6)  << endl; 
cout << "cut BadJets        :" << beta_raw->GetBinContent( 7)  << endl; 
cout << "cut CaloJets       :" << beta_raw->GetBinContent( 8)  << endl; 
cout << "cut PrimaryVertex  :" << beta_raw->GetBinContent( 9)  << endl; 
cout << "cut BadMuons       :" << beta_raw->GetBinContent( 10)  << endl; 

cout << "Cosmic Muons       :" << beta_raw->GetBinContent(11)  << endl; 
cout << "hfor veto          :" << beta_raw->GetBinContent(12)  << endl; 

cout << ">= 2 lep           :" << beta_raw->GetBinContent(13)  << endl; 
cout << "== 2 lept          :" << beta_raw->GetBinContent(14)  << endl; 
cout << "mll cut            :" << beta_raw->GetBinContent(15)  << endl; 

cout << "----------------  SS  --------------------------" << endl;
cout << "                      EE       MM     EM                " << endl;
cout << "----------------------------------------------" << endl;
cout << "pass category      :" << alpha_raw->GetBinContent(16) << "     " << gamma_raw->GetBinContent(16) << "     " << beta_raw->GetBinContent(16)  << endl; 
cout << "flavor cut         :" << alpha_raw->GetBinContent(17) << "     " << gamma_raw->GetBinContent(17) << "     " << beta_raw->GetBinContent(17)  << endl; 
cout << "tau veto           :" << alpha_raw->GetBinContent(18) << "     " << gamma_raw->GetBinContent(18) << "     " << beta_raw->GetBinContent(18)  << endl; 
cout << "valid pT           :" << alpha_raw->GetBinContent(19) << "     " << gamma_raw->GetBinContent(19) << "     " << beta_raw->GetBinContent(19)  << endl; 
cout << "Trigger            :" << alpha_raw->GetBinContent(20) << "     " << gamma_raw->GetBinContent(20) << "     " << beta_raw->GetBinContent(20)  << endl; 
cout << "RealLeptonsCheck   :" << alpha_raw->GetBinContent(21) << "     " << gamma_raw->GetBinContent(21) << "     " << beta_raw->GetBinContent(21)  << endl; 
cout << "SameSign           :" << alpha_raw->GetBinContent(22) << "     " << gamma_raw->GetBinContent(22) << "     " << beta_raw->GetBinContent(22)  << endl; 
cout << "3rd lep veto       :" << alpha_raw->GetBinContent(23) << "     " << gamma_raw->GetBinContent(23) << "     " << beta_raw->GetBinContent(23)  << endl; 
cout << "FVeto              :" << alpha_raw->GetBinContent(24) << "     " << gamma_raw->GetBinContent(24) << "     " << beta_raw->GetBinContent(24)  << endl; 
cout << "bVeto              :" << alpha_raw->GetBinContent(25) << "     " << gamma_raw->GetBinContent(25) << "     " << beta_raw->GetBinContent(25)  << endl; 
cout << "======================================================" << endl;
cout << "==1jet             :" << alpha_raw->GetBinContent(26) << "     " << gamma_raw->GetBinContent(26) << "     " << beta_raw->GetBinContent(26)  << endl; 
cout << "lep pt             :" << alpha_raw->GetBinContent(27) << "     " << gamma_raw->GetBinContent(27) << "     " << beta_raw->GetBinContent(27)  << endl; 
cout << "ZVeto              :" << alpha_raw->GetBinContent(28) << "     " << gamma_raw->GetBinContent(28) << "     " << beta_raw->GetBinContent(28)  << endl; 
cout << "DeltaEtal0l1       :" << alpha_raw->GetBinContent(29) << "     " << gamma_raw->GetBinContent(29) << "     " << beta_raw->GetBinContent(29)  << endl; 
cout << "max(mT)            :" << alpha_raw->GetBinContent(30) << "     " << gamma_raw->GetBinContent(30) << "     " << beta_raw->GetBinContent(30)  << endl; 
cout << "mlj                :" << alpha_raw->GetBinContent(31) << "     " << gamma_raw->GetBinContent(31) << "     " << beta_raw->GetBinContent(31)  << endl; 
cout << "HT                 :" << alpha_raw->GetBinContent(32) << "     " << gamma_raw->GetBinContent(32) << "     " << beta_raw->GetBinContent(32)  << endl; 
cout << "METrel             :" << alpha_raw->GetBinContent(33) << "     " << gamma_raw->GetBinContent(33) << "     " << beta_raw->GetBinContent(33)  << endl; 
cout << "mT(WW)             :" << alpha_raw->GetBinContent(34) << "     " << gamma_raw->GetBinContent(34) << "     " << beta_raw->GetBinContent(34)  << endl; 
cout << "======================================================" << endl;
cout << ">=2jets            :" << alpha_raw->GetBinContent(35) << "     " << gamma_raw->GetBinContent(35) << "     " << beta_raw->GetBinContent(35)  << endl; 
cout << "lep pt             :" << alpha_raw->GetBinContent(36) << "     " << gamma_raw->GetBinContent(36) << "     " << beta_raw->GetBinContent(36)  << endl; 
cout << "ZVeto              :" << alpha_raw->GetBinContent(37) << "     " << gamma_raw->GetBinContent(37) << "     " << beta_raw->GetBinContent(37)  << endl; 
cout << "DeltaEtal0l1       :" << alpha_raw->GetBinContent(38) << "     " << gamma_raw->GetBinContent(38) << "     " << beta_raw->GetBinContent(38)  << endl; 
cout << "max(mT)            :" << alpha_raw->GetBinContent(39) << "     " << gamma_raw->GetBinContent(39) << "     " << beta_raw->GetBinContent(39)  << endl; 
cout << "mljj               :" << alpha_raw->GetBinContent(40) << "     " << gamma_raw->GetBinContent(40) << "     " << beta_raw->GetBinContent(40)  << endl; 
cout << "HT                 :" << alpha_raw->GetBinContent(41) << "     " << gamma_raw->GetBinContent(41) << "     " << beta_raw->GetBinContent(41)  << endl; 
cout << "METrel             :" << alpha_raw->GetBinContent(42) << "     " << gamma_raw->GetBinContent(42) << "     " << beta_raw->GetBinContent(42)  << endl; 



}