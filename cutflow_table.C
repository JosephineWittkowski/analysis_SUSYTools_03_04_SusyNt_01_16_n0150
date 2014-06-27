{
   
  TFile hn("/data/etp3/jwittkow/analysis_SUSYTools_03_04_SusyNt_01_16_n0150/histos_ZN_177501_n0150_21_05_14.root");
  hn.Print();
TH1F *alpha_raw = (TH1F*)hn.Get("cutflow_EE");
TH1F *beta_raw = (TH1F*)hn.Get("cutflow_EM");
TH1F *gamma_raw = (TH1F*)hn.Get("cutflow_MM");


TH1F *alpha_mcEventWeight = (TH1F*)hn.Get("cutflow_EE_ALL");
TH1F *beta_mcEventWeight = (TH1F*)hn.Get("cutflow_EM_ALL");
TH1F *gamma_mcEventWeight = (TH1F*)hn.Get("cutflow_MM_ALL");
// 
cout << fixed;
cout << "\\begin{tabular}{l|c|c|c}" << endl;

cout << "Cuts & \\multicolumn{3}{c}{Number of events} \\\\" << endl;
cout << "\\hline" << endl;
cout << "No Cuts & \\multicolumn{3}{c}{" << std::setprecision(0) <<beta_raw->GetBinContent( 1)  << "} \\\\" << endl;
cout << "GRL & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent( 2)  << "} \\\\"  << endl; 
cout << "LAR/Tile Error & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent( 5)  << "} \\\\"  << endl; 
cout << "TileCal Hot Spot & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent( 6)  << "} \\\\"  << endl; 
cout << "BadJet & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent( 7)  << "} \\\\"  << endl;
cout << "Primary Vertex & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent( 9)  << "} \\\\"  << endl; 
cout << "Bad Muon & \\multicolumn{3}{c}{ " << std::setprecision(0) << beta_raw->GetBinContent( 10)  << "} \\\\"  << endl; 
cout << "Cosmic Veto & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent(11)  << "} \\\\"  << endl; 
cout << "$>$=2 leptons & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent(13)  << "} \\\\"  << endl; 
cout << "==2 leptons, mll $>$ 20 & \\multicolumn{3}{c}{" << std::setprecision(0) << beta_raw->GetBinContent(15)  << "} \\\\"  << endl;

cout << "\\hline" << endl;
cout << "& $ee$ channel & $\\mu\\mu$ channel & $e\\mu$ channel \\\\" << endl;
cout << "\\hline" << endl;
                                                            

cout << "flavour signal leptons & " << std::setprecision(0) << alpha_raw->GetBinContent(17) << " & " << std::setprecision(0) << gamma_raw->GetBinContent(17) << " & " << std::setprecision(0) << beta_raw->GetBinContent(17) << "\\\\"  << endl; 
cout << "Tau Veto & " << std::setprecision(0) << alpha_raw->GetBinContent(18) << " & " << std::setprecision(0) << gamma_raw->GetBinContent(18) << " & " << std::setprecision(0) << beta_raw->GetBinContent(18) << "\\\\"  << endl; 

cout << "Triggermatch & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(20) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(20) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(20) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(20) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(20) << " (" << std::setprecision(0) << beta_raw->GetBinContent(20) << ")" << "\\\\"  << endl; 
cout << "SameSign & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(22) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(22) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(22) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(22) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(22) << " (" << std::setprecision(0) << beta_raw->GetBinContent(22) << ")" << "\\\\"  << endl; 
cout << "3rd lep veto & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(23) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(23) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(23) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(23) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(23) << " (" << std::setprecision(0) << beta_raw->GetBinContent(23) << ")" << "\\\\"  << endl; 
cout << "FVeto/BVeto & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(25) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(25) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(25) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(25) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(25) << " (" << std::setprecision(0) << beta_raw->GetBinContent(25) << ")" << "\\\\"  << endl; 
cout << "\\hline" << endl;
cout << "==1jet & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(26) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(26) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(26) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(26) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(26) << " (" << std::setprecision(0) << beta_raw->GetBinContent(26) << ")" << "\\\\"  << endl; 
cout << "SR$_{1~jet}$ & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(34) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(34) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(32) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(32) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(32) << " (" << std::setprecision(0) << beta_raw->GetBinContent(32) << ")" << "\\\\"  << endl; 
cout << "\\hline" << endl;
cout << "$>$=2jets & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(35) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(35) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(35) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(35) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(35) << " (" << std::setprecision(0) << beta_raw->GetBinContent(35) << ")" << "\\\\"  << endl;
cout << "SR$_{2,3~jet}$ & " << std::setprecision(2) << alpha_mcEventWeight->GetBinContent(42) << " (" << std::setprecision(0) << alpha_raw->GetBinContent(42) << ")" << " & " << std::setprecision(2) << gamma_mcEventWeight->GetBinContent(41) << " (" << std::setprecision(0) << gamma_raw->GetBinContent(41) << ")" << " & " << std::setprecision(2) << beta_mcEventWeight->GetBinContent(41) << " (" << std::setprecision(0) << beta_raw->GetBinContent(41) << ")" << "\\\\"  << endl; 
cout << "\\hline \\hline" << endl;
cout << "\\end{tabular}" << endl;
}