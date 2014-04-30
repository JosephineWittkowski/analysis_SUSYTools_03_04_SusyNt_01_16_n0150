{
   
  TFile hn("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16/output_WH_177501_SusySel_test.root");
  hn.Print();
TH1F *alpha_raw = (TH1F*)hn.Get("cutflow_EE");
TH1F *beta_raw = (TH1F*)hn.Get("cutflow_EM");
TH1F *gamma_raw = (TH1F*)hn.Get("cutflow_MM");

cout << "raw events:" << endl;
cout << fixed;

/*cout << "events             :" << beta_raw->GetBinContent( 1)  << endl;
                                                            
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
cout << "SameSign           :" << alpha_raw->GetBinContent(23) << "     " << gamma_raw->GetBinContent(23) << "     " << beta_raw->GetBinContent(23)  << endl; 
cout << "Iso                :" << alpha_raw->GetBinContent(24) << "     " << gamma_raw->GetBinContent(24) << "     " << beta_raw->GetBinContent(24)  << endl; 
cout << "dOS                :" << alpha_raw->GetBinContent() << "     " << gamma_raw->GetBinContent() << "     " << beta_raw->GetBinContent()  << endl; 
cout << "FVeto              :" << alpha_raw->GetBinContent(26) << "     " << gamma_raw->GetBinContent(26) << "     " << beta_raw->GetBinContent(26)  << endl; 
cout << "bVeto              :" << alpha_raw->GetBinContent(27) << "     " << gamma_raw->GetBinContent(27) << "     " << beta_raw->GetBinContent(27)  << endl; */
cout << ">=1jet             :" << alpha_raw->GetBinContent(2) << "     " << gamma_raw->GetBinContent(2) << "     " << beta_raw->GetBinContent(2)  << endl; 
cout << "======================================================" << endl;
cout << "==1jet             :" << alpha_raw->GetBinContent(3) << "     " << gamma_raw->GetBinContent(3) << "     " << beta_raw->GetBinContent(3)  << endl; 
cout << "lep pt             :" << alpha_raw->GetBinContent(4) << "     " << gamma_raw->GetBinContent(4) << "     " << beta_raw->GetBinContent(4)  << endl; 
cout << "mll                :" << alpha_raw->GetBinContent(5) << "     " << gamma_raw->GetBinContent(5) << "     " << beta_raw->GetBinContent(5)  << endl; 
cout << "mWWT               :" << alpha_raw->GetBinContent(6) << "     " << gamma_raw->GetBinContent(6) << "     " << beta_raw->GetBinContent(6)  << endl; 
cout << "HT                 :" << alpha_raw->GetBinContent(7) << "     " << gamma_raw->GetBinContent(7) << "     " << beta_raw->GetBinContent(7)  << endl; 
cout << "metREL             :" << alpha_raw->GetBinContent(8) << "     " << gamma_raw->GetBinContent(8) << "     " << beta_raw->GetBinContent(8)  << endl; 
cout << "3rd lepton veto    :" << alpha_raw->GetBinContent(9) << "     " << gamma_raw->GetBinContent(9) << "     " << beta_raw->GetBinContent(9)  << endl; 
cout << "======================================================" << endl;
cout << ">=2jets            :" << alpha_raw->GetBinContent(23) << "     " << gamma_raw->GetBinContent(23) << "     " << beta_raw->GetBinContent(23)  << endl; 
cout << "lep pt             :" << alpha_raw->GetBinContent(24) << "     " << gamma_raw->GetBinContent(24) << "     " << beta_raw->GetBinContent(24)  << endl; 
cout << "mll                :" << alpha_raw->GetBinContent(25) << "     " << gamma_raw->GetBinContent(25) << "     " << beta_raw->GetBinContent(25)  << endl; 
cout << "mWWT               :" << alpha_raw->GetBinContent(26) << "     " << gamma_raw->GetBinContent(26) << "     " << beta_raw->GetBinContent(26)  << endl; 
cout << "HT                 :" << alpha_raw->GetBinContent(27) << "     " << gamma_raw->GetBinContent(27) << "     " << beta_raw->GetBinContent(27)  << endl; 
cout << "metREL             :" << alpha_raw->GetBinContent(28) << "     " << gamma_raw->GetBinContent(28) << "     " << beta_raw->GetBinContent(28)  << endl; 
cout << "3rd lepton veto    :" << alpha_raw->GetBinContent(29) << "     " << gamma_raw->GetBinContent(29) << "     " << beta_raw->GetBinContent(29)  << endl; 












cout << "#############################################" << endl;
cout << "#############################################" << endl;
cout << "MC event Weights: all weights applied" << endl;

TH1F *alpha_mcEventWeight = (TH1F*)hn.Get("cutflow_EE_ALL");
TH1F *beta_mcEventWeight = (TH1F*)hn.Get("cutflow_EM_ALL");
TH1F *gamma_mcEventWeight = (TH1F*)hn.Get("cutflow_MM_ALL");
// 
/*cout << "events             :" << beta_mcEventWeight->GetBinContent( 1)  << endl;
                                                            
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
cout << "SameSign           :" << alpha_mcEventWeight->GetBinContent(23) << "     " << gamma_mcEventWeight->GetBinContent(23) << "     " << beta_mcEventWeight->GetBinContent(23)  << endl; 
cout << "Iso                :" << alpha_mcEventWeight->GetBinContent(24) << "     " << gamma_mcEventWeight->GetBinContent(24) << "     " << beta_mcEventWeight->GetBinContent(24)  << endl; 
cout << "dOS                :" << alpha_mcEventWeight->GetBinContent() << "     " << gamma_mcEventWeight->GetBinContent() << "     " << beta_mcEventWeight->GetBinContent()  << endl; 
cout << "FVeto              :" << alpha_mcEventWeight->GetBinContent(26) << "     " << gamma_mcEventWeight->GetBinContent(26) << "     " << beta_mcEventWeight->GetBinContent(26)  << endl; 
cout << "bVeto              :" << alpha_mcEventWeight->GetBinContent(27) << "     " << gamma_mcEventWeight->GetBinContent(27) << "     " << beta_mcEventWeight->GetBinContent(27)  << endl;*/ 
cout << ">=1jet             :" << alpha_mcEventWeight->GetBinContent(2) << "     " << gamma_mcEventWeight->GetBinContent(2) << "     " << beta_mcEventWeight->GetBinContent(2)  << endl; 
cout << "======================================================" << endl;
cout << "==1jet             :" << alpha_mcEventWeight->GetBinContent(3) << "     " << gamma_mcEventWeight->GetBinContent(3) << "     " << beta_mcEventWeight->GetBinContent(3)  << endl; 
cout << "lep pt             :" << alpha_mcEventWeight->GetBinContent(4) << "     " << gamma_mcEventWeight->GetBinContent(4) << "     " << beta_mcEventWeight->GetBinContent(4)  << endl; 
cout << "mll                :" << alpha_mcEventWeight->GetBinContent(5) << "     " << gamma_mcEventWeight->GetBinContent(5) << "     " << beta_mcEventWeight->GetBinContent(5)  << endl; 
cout << "mWWT               :" << alpha_mcEventWeight->GetBinContent(6) << "     " << gamma_mcEventWeight->GetBinContent(6) << "     " << beta_mcEventWeight->GetBinContent(6)  << endl; 
cout << "HT                 :" << alpha_mcEventWeight->GetBinContent(7) << "     " << gamma_mcEventWeight->GetBinContent(7) << "     " << beta_mcEventWeight->GetBinContent(7)  << endl; 
cout << "metREL             :" << alpha_mcEventWeight->GetBinContent(8) << "     " << gamma_mcEventWeight->GetBinContent(8) << "     " << beta_mcEventWeight->GetBinContent(8)  << endl; 
cout << "3rd lepton veto    :" << alpha_mcEventWeight->GetBinContent(9) << "     " << gamma_mcEventWeight->GetBinContent(9) << "     " << beta_mcEventWeight->GetBinContent(9)  << endl; 
// cout << "======================================================" << endl;
cout << ">=2jets            :" << alpha_mcEventWeight->GetBinContent(23) << "     " << gamma_mcEventWeight->GetBinContent(23) << "     " << beta_mcEventWeight->GetBinContent(23)  << endl; 
cout << "lep pt             :" << alpha_mcEventWeight->GetBinContent(24) << "     " << gamma_mcEventWeight->GetBinContent(24) << "     " << beta_mcEventWeight->GetBinContent(24)  << endl; 
cout << "mll                :" << alpha_mcEventWeight->GetBinContent(25) << "     " << gamma_mcEventWeight->GetBinContent(25) << "     " << beta_mcEventWeight->GetBinContent(25)  << endl; 
cout << "mWWT               :" << alpha_mcEventWeight->GetBinContent(26) << "     " << gamma_mcEventWeight->GetBinContent(26) << "     " << beta_mcEventWeight->GetBinContent(26)  << endl; 
cout << "HT                 :" << alpha_mcEventWeight->GetBinContent(27) << "     " << gamma_mcEventWeight->GetBinContent(27) << "     " << beta_mcEventWeight->GetBinContent(27)  << endl; 
cout << "metREL             :" << alpha_mcEventWeight->GetBinContent(28) << "     " << gamma_mcEventWeight->GetBinContent(28) << "     " << beta_mcEventWeight->GetBinContent(28)  << endl; 
cout << "3rd lepton veto    :" << alpha_mcEventWeight->GetBinContent(29) << "     " << gamma_mcEventWeight->GetBinContent(29) << "     " << beta_mcEventWeight->GetBinContent(29)  << endl; 
}