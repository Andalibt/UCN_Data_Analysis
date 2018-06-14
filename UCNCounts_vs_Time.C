// ************************************************
// This script is to look at the total UCN counts
// under the same conditions over time and see if
// anything has changed or not.
// Taraneh Andalib, June 14, 2018
// ************************************************

#define max 500

void UCNCounts_vs_Time(){
  
  TFile *fin = new TFile("./2ndpass/outputTree_StorageLifetime_All.root","READ");
  TTree *outputTree = (TTree*) fin -> Get("cycle_info");
  
  
  double irradiationStartTime;
  outputTree -> SetBranchAddress ( "irradStartTimes" , &irradiationStartTime);
  double irradTimeArray[max];
  
  double cycleStartTime;
  outputTree -> SetBranchAddress ("cycleStartTimes" , &cycleStartTime);
  double cycleStartTimeArray[max];
  
  double cycleValveOpenTime;
  outputTree -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime);
  
  double cycleValveCloseTime;
  outputTree -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime);

  double cycleDelayTime;
  outputTree -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime);
  
  double HistIntegral;
  outputTree -> SetBranchAddress ("HistIntegral" , &HistIntegral);
  double HistIntegralArray[max];
  
  double BASELINERATE;
  outputTree -> SetBranchAddress ("BASELINERATE" , &BASELINERATE);
  
  double avets12VO;
  outputTree -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO);
  double avets12VOArray[max];
  
  double maxts12VO;
  outputTree -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO);
  
  double mints12VO;
  outputTree -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO);
  
  double avecur;
  outputTree -> SetBranchAddress ("AVE_PRDCUR" , &avecur);
  double avecurArray[max];
  
  double maxcur;
  outputTree -> SetBranchAddress ("MAX_PRDCUR" , &maxcur);
  
  double mincur;
  outputTree -> SetBranchAddress ("MIN_PRDCUR" , &mincur);
  
  double HistIntegralErrArray[max];
  double UCNCounts[max];
  double UCNCountsErr[max];
  double avecurErrArray[max];
  double avets12VOErrArray[max];
  double NormUCNCounts[max];
  
  Int_t counts = 0;
  
  ULong64_t event;
  event = (Double_t) outputTree->GetEntries();
  
  for (ULong64_t j = 0 ; j < event ; j++){
    outputTree-> GetEvent(j);
    if ( BASELINERATE < 0 || HistIntegral < 100)
      continue;
    if (cycleStartTime - irradiationStartTime > 59. && cycleStartTime - irradiationStartTime < 61){
      if (cycleDelayTime <1.){
	HistIntegralArray[counts] = HistIntegral;
	HistIntegralErrArray[counts] = sqrt(HistIntegral);
	UCNCounts[counts] = HistIntegral - BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	cout << counts << " " << HistIntegralArray[counts]  << endl;
	UCNCountsErr[counts] = sqrt(UCNCounts[counts]);
	avecurArray[counts] = avecur;
	avecurErrArray[counts] = (maxcur - mincur)/2;
	avets12VOArray[counts] = avets12VO;
	avets12VOErrArray[counts] = (maxts12VO - mints12VO)/2;
	cycleStartTimeArray[counts] = cycleStartTime;
	NormUCNCounts[counts] = UCNCounts[counts]/avecurArray[counts];
	counts++;
	//cout << UCNCounts[counts] << " " << cycleStartTimeArray[counts] << " " << counts << " " << UCNCountsErr[counts] << endl;
      }
    }
  }
  
  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200 , 900);

  TGraphErrors *gr1 = new TGraphErrors (counts, cycleStartTimeArray, NormUCNCounts, 0 , UCNCountsErr);
  
  gr1 -> SetTitle("Normalized UCN Counts vs Date");
  gr1 -> GetYaxis() -> SetTitle("UCN Counts Normalized to Beam Current");
  gr1 -> GetYaxis() -> SetRangeUser(0,50000);
  gr1-> SetMarkerStyle(20);
  gr1 -> GetXaxis()->SetNdivisions(503);
  gr1 -> GetXaxis() -> SetTimeDisplay(1);
  gr1 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr1 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr1 -> GetXaxis() -> SetTitleSize(0.05);
  gr1 -> GetXaxis() -> SetLabelOffset(.03);
  gr1 -> GetXaxis() -> SetTitleOffset(0.2);
  gr1 -> GetYaxis() -> SetTitleOffset(1.3);
  gr1 -> GetXaxis() -> SetLabelSize(.04);
  gr1-> Draw("Ap");
  
  
  TCanvas *c2 = new TCanvas ("c2" , "c2" , 1200 , 900);

  TGraphErrors *gr2 = new TGraphErrors (counts, avets12VOArray, UCNCounts, avets12VOErrArray , UCNCountsErr);
  
  gr2 -> SetTitle("UCN Counts vs Average Isopure Helium Temperature");
  gr2 -> GetYaxis() -> SetTitle("UCN Counts");
  gr2 -> GetXaxis() -> SetTitle ("Average Isopure Helium Temperature (K)");
  gr2-> SetMarkerStyle(20);
  gr2 -> GetXaxis() -> SetTitleSize(0.05);
  gr2 -> GetXaxis() -> SetLabelOffset(.03);
  gr2 -> GetYaxis() -> SetTitleOffset(1.3);
  gr2 -> GetXaxis() -> SetTitleOffset(1.3);
  gr2 -> GetXaxis() -> SetLabelSize(.04);
  gr2-> Draw("Ap");
  
  TCanvas *c3 = new TCanvas ("c3" , "c3" , 1200 , 900);

  TGraphErrors *gr3 = new TGraphErrors (counts, avecurArray, UCNCounts, avecurErrArray , UCNCountsErr);
  
  gr3 -> SetTitle("UCN Counts vs Average Beam Current");
  gr3 -> GetYaxis() -> SetTitle("UCN Counts");
  gr3 -> GetXaxis() -> SetTitle ("Average Beam Current (#muA)");
  gr3-> SetMarkerStyle(20);
  gr3 -> GetXaxis() -> SetTitleSize(0.05);
  gr3 -> GetXaxis() -> SetLabelOffset(.03);
  gr3 -> GetYaxis() -> SetTitleOffset(1.3);
  gr3 -> GetXaxis() -> SetTitleOffset(1.3);
  gr3 -> GetXaxis() -> SetLabelSize(.04);
  gr3-> Draw("Ap");
}
