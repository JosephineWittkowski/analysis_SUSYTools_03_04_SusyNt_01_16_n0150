// Don't forget to load AtlasStyle
#include <math.h>

#include "TROOT.h"
#include "TH1.h"
#include "TCanvas.h"
#include "THStack.h"
#include "TLine.h"
#include "TLegend.h"
#include "TGraphAsymmErrors.h"

//#include "ATLASStyle/AtlasStyle.h"
//#include "ATLASStyle/AtlasUtils.h"
//#include "ATLASStyle/AtlasLabels.h"

// Forward Declear
void PlotUnifier(
                  TH1F* histos[9],                   // Array of pointers to histograms
                  TGraphAsymmErrors* smErrorBand,    // Error band for the top pad
                  TGraphAsymmErrors* ratioErrorBand  // Error band for the bottom pad
                );

////////////////////////////////////////////////////////////////////////////////////////
// Example main app 
////////////////////////////////////////////////////////////////////////////////////////
void PlotExample_v3()
{
  // !!!!!!!!!!!!!!!!!!!!
  // Load Macros and SetStyle
  gROOT->LoadMacro("ATLASStyle/AtlasUtils.C"); 
  gROOT->LoadMacro("ATLASStyle/AtlasStyle.C"); 
  gROOT->LoadMacro("ATLASStyle/AtlasLabels.C"); 
  SetAtlasStyle();

  // !!!!!!!!!!!!!!!!!!!!
  // Create Dummy nominal histograms and fill them
  TH1F* histoData    = new TH1F("histoData"   ,"histoData"   ,1,0,1);   histoData ->SetBinContent(1, 30.0);  histoData ->SetBinError(1, sqrt(30.)); 
  TH1F* histoWW      = new TH1F("histoWW"     ,"histoWW"     ,1,0,1);   histoWW   ->SetBinContent(1, 15.0);  histoWW   ->SetBinError(1,      2.0); 
  TH1F* histoTop     = new TH1F("histoTop"    ,"histoTop"    ,1,0,1);   histoTop  ->SetBinContent(1,  6.0);  histoTop  ->SetBinError(1,      2.0);
  TH1F* histoZV      = new TH1F("histoZV"     ,"histoZV"     ,1,0,1);   histoZV   ->SetBinContent(1,  4.0);  histoZV   ->SetBinError(1,      1.2);
  TH1F* histoZjets   = new TH1F("histoZjets"  ,"histoZjets"  ,1,0,1);   histoZjets->SetBinContent(1,  1.0);  histoZjets->SetBinError(1,      1.0);
  TH1F* histoFakes   = new TH1F("histoFakes"  ,"histoFakes"  ,1,0,1);   histoFakes->SetBinContent(1,  0.5);  histoFakes->SetBinError(1,      0.5);
  TH1F* histoHiggs   = new TH1F("histoHiggs"  ,"histoHiggs"  ,1,0,1);   histoHiggs->SetBinContent(1,  2.5);  histoHiggs->SetBinError(1,      1.0);
  TH1F* histoSignal1 = new TH1F("histoSignal1","histoSignal1",1,0,1); histoSignal1->SetBinContent(1,  1.0);  histoSignal1->SetBinError(1,    0.2);
  TH1F* histoSignal2 = new TH1F("histoSignal2","histoSignal2",1,0,1); histoSignal2->SetBinContent(1,  0.2);  histoSignal2->SetBinError(1,    0.0);

  // !!!!!!!!!!!!!!!!!!!!
  // RESPECT THE ORDER!!!
  TH1F* inputHistograms[9] = { histoData   ,
                               histoZjets  ,
                               histoWW     ,
                               histoTop    ,
                               histoZV     ,
                               histoFakes  ,
                               histoHiggs  , 
                               histoSignal1, 
                               histoSignal2 };

  // Here build you error bands that's internal to your code
  // Now we're using dummy ones ==> Doesn't seem to show correctly needs to debugged
  Double_t x[1] = {0.5}, y[1] = {29.0}, exl[1] = {0.5}, exh[1] = {0.5}, eyl[1] = {4.0}, eyh[1] = {5.0};
  TGraphAsymmErrors* upperPadError = new TGraphAsymmErrors(1,x,y,exl,exh,eyl,eyh); 
  Double_t xx[1] = {0.5}, yy[1] = { 1.0}, exxl[1] = {0.5}, exxh[1] = {0.5}, eyyl[1] = {0.3}, eyyh[1] = {0.4};
  TGraphAsymmErrors* lowerPadError = new TGraphAsymmErrors(1,xx,yy,exxl,exxh,eyyl,eyyh); 

  // Call the plotter  
  PlotUnifier( inputHistograms, upperPadError, lowerPadError );
}

////////////////////////////////////////////////////////////////////////////////////////
// Draw and save the canvas
// This bit shouldn't need to be updated except the region and channel labels
// As of Jan 10,2013 - the known issues are:
// ++ Error bands don't show correctly
// ++ Data histogram needs to be converted to TGraphAsymmErrors and 
//    plotted w/ poisson errors
// ++ Ratio plot needs to divide the Data TGraphAsymmErrors and
//    TGraphAsymmErrors for the total SM (by turning off the errors since they are
//    shown explicitly)
////////////////////////////////////////////////////////////////////////////////////////
void PlotUnifier(
                  TH1F* histos[9],                   // Array of pointers to histograms
                  TGraphAsymmErrors* smErrorBand,    // Error band for the top pad
                  TGraphAsymmErrors* ratioErrorBand  // Error band for the bottom pad
                )
{
  ////////////////////////////////////////////////////////////////////////////////////////
  // Set Histogram Properties, build the stack and make the ratio plot
  histos[0]->SetMarkerStyle(20)     ; histos[0]->SetMarkerSize(1.2); 
  histos[1]->SetFillColor(kOrange-2); histos[4]->SetLineWidth (2);
  histos[2]->SetFillColor(kAzure-9 ); histos[1]->SetLineWidth (2);
  histos[3]->SetFillColor(kSpring+1); histos[2]->SetLineWidth (2);
  histos[4]->SetFillColor(kAzure+4 ); histos[3]->SetLineWidth (2);
  histos[5]->SetFillColor(kGray    ); histos[5]->SetLineWidth (2);
  histos[6]->SetFillColor(kYellow-9); histos[6]->SetLineWidth (2);
  histos[7]->SetLineColor(kMagenta ); histos[7]->SetLineWidth (3); histos[7]->SetLineStyle(2);
  histos[8]->SetLineColor(kGreen+1 ); histos[8]->SetLineWidth (3); histos[8]->SetLineStyle(2);
  
  ////////////////////////////////////////////////////////////////////////////////////////
  // Here comes the stack 
  THStack* sm = new THStack("sm","sm");
  sm->Add(histos[6]);
  sm->Add(histos[5]);
  sm->Add(histos[4]);
  sm->Add(histos[3]);
  sm->Add(histos[2]);
  sm->Add(histos[1]);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Define the legend and fill in the stack order
  TLegend* legendA        = new TLegend(0.49,0.65,0.74,0.85);
  TLegend* legendB        = new TLegend(0.62,0.65,0.87,0.85);
  legendA->SetTextFont(42);    
  legendB->SetTextFont(42);    
  legendA->SetTextSize(0.03);
  legendB->SetTextSize(0.03);
  legendA->SetBorderSize(0);
  legendB->SetBorderSize(0);
  legendA->SetFillColor(0);
  legendB->SetFillColor(0);
  legendA->AddEntry(histos[0],"Data"               ,"p");
  legendA->AddEntry(histos[1],"Z+jets"             ,"f");
  legendA->AddEntry(histos[2],"WW"                 ,"f");
  legendA->AddEntry(histos[3],"t#bar{t}+Wt"        ,"f");
  legendA->AddEntry(histos[4],"ZV"                 ,"f");
  legendB->AddEntry(histos[5],"Non-prompt leptons" ,"f");
  legendB->AddEntry(histos[6],"Higgs"              ,"f");
  TH1F* histoError = new TH1F("histoError"         ,"histoError",1,0,1);
  histoError->SetFillStyle(3004);
  histoError->SetFillColor(kBlack);
  legendB->AddEntry(histoError,"Bkg. Uncert."      ,"f");
  legendB->AddEntry(histos[7],"Signal 1"           ,"l");
  legendB->AddEntry(histos[8],"Signal 2"           ,"l");

  ////////////////////////////////////////////////////////////////////////////////////////
  // Ratio plot 
  TH1F* ratio      = (TH1F*) histos[0]->Clone(); ratio->Reset(); 
  TH1F* stackHisto = (TH1F*) sm->GetStack()->Last();
  ratio->Divide(histos[0],stackHisto);
  ratio->SetMarkerSize(1.2);
  ratio->SetMarkerStyle(20);
  ratio->SetLineColor(kBlack);
  ratio->SetLineWidth(2);

  ratio->GetXaxis()->SetTitle("Observable");
  ratio->GetYaxis()->SetTitle("Data/SM");
  ratio->GetXaxis()->SetLabelSize(0.13);
  ratio->GetXaxis()->SetLabelOffset(0.02);
  ratio->GetXaxis()->SetTitleSize(0.14);
  ratio->GetXaxis()->SetTitleOffset(1.2);

  ratio->GetYaxis()->SetRangeUser(0,2);
  ratio->GetYaxis()->SetLabelSize(0.13);
  ratio->GetYaxis()->SetLabelOffset(0.0125);
  ratio->GetYaxis()->SetTitleSize(0.14);
  ratio->GetYaxis()->SetTitleOffset(0.5);
  ratio->GetYaxis()->SetNdivisions(5);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Error bands
  smErrorBand->SetMarkerSize(0); 
  smErrorBand->SetFillStyle(3004);
  smErrorBand->SetFillColor(kBlack);
  ratioErrorBand->SetMarkerSize(0); 
  ratioErrorBand->SetFillStyle(3004);
  ratioErrorBand->SetFillColor(kBlack);
 
  ////////////////////////////////////////////////////////////////////////////////////////
  // Draw and save the canvas
  TCanvas* canvas = new TCanvas("canvas","canvas",500,500);
  TPad*    topPad = new TPad("pTop","pTop",0,0.2,1,1);
  TPad*    botPad = new TPad("pBot","pBot",0,0.0,1,0.3);
  topPad->Draw();
  botPad->Draw();

  ////////////////////////////////////////////////////////////////////////////////////////
  // Data is special since I use it to draw the axis labels etc.
  histos[0]->GetXaxis()->SetTitle("Observable"); 
  histos[0]->GetYaxis()->SetTitle("Events / Bin"); 
  histos[0]->GetXaxis()->SetLabelOffset(1.2); 
  histos[0]->GetXaxis()->SetLabelSize(0.03);
  histos[0]->GetYaxis()->SetRangeUser(1.e-2,1.e5);
  histos[0]->GetYaxis()->SetTitleSize(0.055);
  histos[0]->GetYaxis()->SetTitleOffset(1.28);
  histos[0]->GetYaxis()->SetLabelSize(0.05);
  histos[0]->GetYaxis()->SetLabelOffset(0.01);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Top Pad
  topPad      ->cd();
  topPad      ->SetBottomMargin(0.15);
  histos[0]   ->Draw("p && e && x0");
  sm          ->Draw("same && hists");
  smErrorBand ->Draw("same && E2");
  histos[0]   ->Draw("same && p && e && x0");
  histos[7]   ->Draw("same && hist");
  histos[8]   ->Draw("same && hist");
  legendA     ->Draw();
  legendB     ->Draw();
  gPad        ->RedrawAxis();
  gPad        ->SetLogy(1);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Decoration
  char annoyingLabel1[100] = "#bf{#it{ATLAS}}, #sqrt{s} = 8 TeV, 20.3 fb^{-1}";
  char annoyingLabel2[100] = "SF/DF channel"; 
  char annoyingLabel3[100] = "- Top CR for SR-#scale[0.9]{m_{T2}} and SR-WWb/c";
  myText(0.53,0.880,kBlack,annoyingLabel1);
  myText(0.17,0.965,kBlack,annoyingLabel2);
  myText(0.37,0.965,kBlack,annoyingLabel3);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Bottom Pad
  botPad ->cd();
  botPad ->SetBottomMargin(0.4);
  
  ////////////////////////////////////////////////////////////////////////////////////////
  // 1 Line
  TLine* line = new TLine(histos[0]->GetXaxis()->GetXmin(),1,histos[0]->GetXaxis()->GetXmax(),1);
  line   ->SetLineColor(kRed);
  line   ->SetLineStyle(7);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Draw
  ratio          ->Draw("p && e && x0");
  ratioErrorBand ->Draw("same && E2");
  line           ->Draw("same");
  ratio          ->Draw("same && p && e && x0");
  gPad           ->SetGridy(1);

  ////////////////////////////////////////////////////////////////////////////////////////
  // Save
  canvas ->SaveAs("Test_v3.eps");

} 
