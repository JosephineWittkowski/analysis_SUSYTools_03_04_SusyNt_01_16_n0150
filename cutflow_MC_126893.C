{
   
  TFile hn("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/histos_ZN_177501_n0150_MZ20GeV0.root");
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
cout << "Fveto              :" << alpha_raw->GetBinContent(23) << "     " << gamma_raw->GetBinContent(23) << "     " << beta_raw->GetBinContent(23)  << endl; 
cout << "bVeto              :" << alpha_raw->GetBinContent(24) << "     " << gamma_raw->GetBinContent(24) << "     " << beta_raw->GetBinContent(24)  << endl; 
cout << "3rd lepton veto    :" << alpha_raw->GetBinContent(25) << "     " << gamma_raw->GetBinContent(25) << "     " << beta_raw->GetBinContent(25)  << endl; 
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












cout << "#############################################" << endl;
cout << "#############################################" << endl;
cout << "MC event Weights: all weights applied" << endl;

TH1F *alpha_mcEventWeight = (TH1F*)hn.Get("cutflow_EE_ALL");
TH1F *beta_mcEventWeight = (TH1F*)hn.Get("cutflow_EM_ALL");
TH1F *gamma_mcEventWeight = (TH1F*)hn.Get("cutflow_MM_ALL");
// 
cout << "events             :" << beta_mcEventWeight->GetBinContent( 1)  << endl;
                                                            
cout << "cut grl            :" << beta_mcEventWeight->GetBinContent( 2)  << endl; 
cout << "TileTripReader     :" << beta_mcEventWeight->GetBinContent( 3)  << endl; 
cout << "incomplete veto    :" << beta_mcEventWeight->GetBinContent( 4)  << endl; 
cout << "cut LArTileError   :" << beta_mcEventWeight->GetBinContent( 5)  << endl; 
cout << "cut TileCalHotSpot :" << beta_mcEventWeight->GetBinContent( 6)  << endl; 
cout << "cut BadJets        :" << beta_mcEventWeight->GetBinContent( 7)  << endl; 
cout << "cut CaloJets       :" << beta_mcEventWeight->GetBinContent( 8)  << endl; 
cout << "cut PrimaryVertex  :" << beta_mcEventWeight->GetBinContent( 9)  << endl; 
cout << "cut BadMuons       :" << beta_mcEventWeight->GetBinContent( 10)  << endl; 

cout << "Cosmic Muons       :" << beta_mcEventWeight->GetBinContent(11)  << endl; 
cout << "hfor veto          :" << beta_mcEventWeight->GetBinContent(12)  << endl; 

cout << ">= 2 lep           :" << beta_mcEventWeight->GetBinContent(13)  << endl; 
cout << "== 2 lept          :" << beta_mcEventWeight->GetBinContent(14)  << endl; 
cout << "mll cut            :" << beta_mcEventWeight->GetBinContent(15)  << endl; 

cout << "----------------  SS  --------------------------" << endl;
cout << "                      EE       MM     EM                " << endl;
cout << "----------------------------------------------" << endl;
cout << "pass category      :" << alpha_mcEventWeight->GetBinContent(16) << "     " << gamma_mcEventWeight->GetBinContent(16) << "     " << beta_mcEventWeight->GetBinContent(16)  << endl; 
cout << "flavor cut         :" << alpha_mcEventWeight->GetBinContent(17) << "     " << gamma_mcEventWeight->GetBinContent(17) << "     " << beta_mcEventWeight->GetBinContent(17)  << endl; 
cout << "tau veto           :" << alpha_mcEventWeight->GetBinContent(18) << "     " << gamma_mcEventWeight->GetBinContent(18) << "     " << beta_mcEventWeight->GetBinContent(18)  << endl; 
cout << "valid pT           :" << alpha_mcEventWeight->GetBinContent(19) << "     " << gamma_mcEventWeight->GetBinContent(19) << "     " << beta_mcEventWeight->GetBinContent(19)  << endl; 
cout << "Trigger            :" << alpha_mcEventWeight->GetBinContent(20) << "     " << gamma_mcEventWeight->GetBinContent(20) << "     " << beta_mcEventWeight->GetBinContent(20)  << endl; 
cout << "RealLeptonsCheck   :" << alpha_mcEventWeight->GetBinContent(21) << "     " << gamma_mcEventWeight->GetBinContent(21) << "     " << beta_mcEventWeight->GetBinContent(21)  << endl; 
cout << "SameSign           :" << alpha_mcEventWeight->GetBinContent(22) << "     " << gamma_mcEventWeight->GetBinContent(22) << "     " << beta_mcEventWeight->GetBinContent(22)  << endl; 
cout << "Fveto              :" << alpha_mcEventWeight->GetBinContent(23) << "     " << gamma_mcEventWeight->GetBinContent(23) << "     " << beta_mcEventWeight->GetBinContent(23)  << endl; 
cout << "bVeto              :" << alpha_mcEventWeight->GetBinContent(24) << "     " << gamma_mcEventWeight->GetBinContent(24) << "     " << beta_mcEventWeight->GetBinContent(24)  << endl; 
cout << "3rd lepton Veto    :" << alpha_mcEventWeight->GetBinContent(25) << "     " << gamma_mcEventWeight->GetBinContent(25) << "     " << beta_mcEventWeight->GetBinContent(25)  << endl; 
cout << "======================================================" << endl;
cout << "==1jet             :" << alpha_mcEventWeight->GetBinContent(26) << "     " << gamma_mcEventWeight->GetBinContent(26) << "     " << beta_mcEventWeight->GetBinContent(26)  << endl; 
cout << "lep pt             :" << alpha_mcEventWeight->GetBinContent(27) << "     " << gamma_mcEventWeight->GetBinContent(27) << "     " << beta_mcEventWeight->GetBinContent(27)  << endl; 
cout << "ZVeto              :" << alpha_mcEventWeight->GetBinContent(28) << "     " << gamma_mcEventWeight->GetBinContent(28) << "     " << beta_mcEventWeight->GetBinContent(28)  << endl; 
cout << "DeltaEtal0l1       :" << alpha_mcEventWeight->GetBinContent(29) << "     " << gamma_mcEventWeight->GetBinContent(29) << "     " << beta_mcEventWeight->GetBinContent(29)  << endl; 
cout << "max(mT)            :" << alpha_mcEventWeight->GetBinContent(30) << "     " << gamma_mcEventWeight->GetBinContent(30) << "     " << beta_mcEventWeight->GetBinContent(30)  << endl; 
cout << "mlj                :" << alpha_mcEventWeight->GetBinContent(31) << "     " << gamma_mcEventWeight->GetBinContent(31) << "     " << beta_mcEventWeight->GetBinContent(31)  << endl; 
cout << "HT                 :" << alpha_mcEventWeight->GetBinContent(32) << "     " << gamma_mcEventWeight->GetBinContent(32) << "     " << beta_mcEventWeight->GetBinContent(32)<< "     " << beta_mcEventWeight->GetBinError(32)  << endl; 
cout << "METrel             :" << alpha_mcEventWeight->GetBinContent(33) << "     " << gamma_mcEventWeight->GetBinContent(33) << "     " << beta_mcEventWeight->GetBinContent(33)  << endl; 
cout << "mT(WW)             :" << alpha_mcEventWeight->GetBinContent(34) << "     " << gamma_mcEventWeight->GetBinContent(34) << "     " << beta_mcEventWeight->GetBinContent(34)  << endl; 
cout << "======================================================" << endl;
cout << ">=2jets            :" << alpha_mcEventWeight->GetBinContent(35) << "     " << gamma_mcEventWeight->GetBinContent(35) << "     " << beta_mcEventWeight->GetBinContent(35)  << endl; 
cout << "lep pt             :" << alpha_mcEventWeight->GetBinContent(36) << "     " << gamma_mcEventWeight->GetBinContent(36) << "     " << beta_mcEventWeight->GetBinContent(36)  << endl; 
cout << "mll                :" << alpha_mcEventWeight->GetBinContent(37) << "     " << gamma_mcEventWeight->GetBinContent(337) << "     " << beta_mcEventWeight->GetBinContent(37)  << endl; 
cout << "DeltaEtal0l1       :" << alpha_mcEventWeight->GetBinContent(38) << "     " << gamma_mcEventWeight->GetBinContent(38) << "     " << beta_mcEventWeight->GetBinContent(38)  << endl; 
cout << "max(mT)            :" << alpha_mcEventWeight->GetBinContent(39) << "     " << gamma_mcEventWeight->GetBinContent(39) << "     " << beta_mcEventWeight->GetBinContent(39)  << endl; 
cout << "mljj               :" << alpha_mcEventWeight->GetBinContent(40) << "     " << gamma_mcEventWeight->GetBinContent(40) << "     " << beta_mcEventWeight->GetBinContent(40)  << endl; 
cout << "HT                 :" << alpha_mcEventWeight->GetBinContent(41) << "     " << gamma_mcEventWeight->GetBinContent(41) << "     " << beta_mcEventWeight->GetBinContent(41)  << endl; 
cout << "METrel             :" << alpha_mcEventWeight->GetBinContent(42) << "     " << gamma_mcEventWeight->GetBinContent(42) << "     " << beta_mcEventWeight->GetBinContent(42) << "     " << beta_mcEventWeight->GetBinError(42)  << endl; 
}