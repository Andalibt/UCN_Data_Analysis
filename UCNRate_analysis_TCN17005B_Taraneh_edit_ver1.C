// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17005B.
// CONTINUE IRRADIATION AFTER OPENNING VALVE
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNRate_analysis_TCN17005B_Taraneh_edit_ver1(){

  TFile *fin594 = new TFile ("~/raw_Data/ucn_tree_00000594.root", "READ");

  
  TTree *uinli6594 = (TTree*) fin594 -> Get("UCNHits_Li-6");
  TTree *bl594 = (TTree*) fin594 -> Get("BeamlineEpicsTree");
  TTree *sourceEpics594 = (TTree*) fin594 -> Get("SourceEpicsTree");
  
  

  double tUnixTimePrecise594;
  double tUnixTime594;
  UShort_t tIsUCN594;
  double cur594;
  double ts12594;
  double curArray594 [1000000];
  double curAve594;
  double ts12Ave594;
  int timestamp_bl594;
  int timestamp_se594;
  double TSArray594 [1000000];
  double TSArrayse594 [1000000];
  double tempArray594 [1000000];
  Double_t min594 = 15400000000;
  Double_t max594 = 0.;
  Int_t NBins594;

  uinli6594 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise594);
  uinli6594 -> SetBranchAddress ("tUnixTime", &tUnixTime594);
  uinli6594 -> SetBranchAddress ("tIsUCN" , &tIsUCN594);
  bl594 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur594);
  bl594 -> SetBranchAddress ("timestamp", &timestamp_bl594);
  sourceEpics594 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12594);
  sourceEpics594 -> SetBranchAddress ("timestamp", &timestamp_se594);


  // *************
  // FOR RUN 594
  // ************

  int counts594 = 0;
  int boCounts594;
  

  double beamlineEvent594 = (Double_t) bl594-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 594 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent594 ;j++) {
    bl594 -> GetEvent(j);
    TSArray594[counts594] = timestamp_bl594;
    curArray594[counts594] = cur594*2000;

    if (counts594 > 1){
      if (curArray594[counts594 - 1] < 0.08 && curArray594[counts594] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl594 << endl;
	curAve594 += cur594;
	boCounts594++;
      }
      if (curArray594[counts594-1] > 0.08 && curArray594[counts594] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl594 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl594 < min594 ){
      min594 = timestamp_bl594;
    }
    // MAX TIME STAMP
    if (timestamp_bl594 > max594){
      max594 = timestamp_bl594;
    }

    counts594++;
    }

  int SEcounts594;
  double sourceEpicsEvents594 = (double) sourceEpics594 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents594 ; j++){
    sourceEpics594 -> GetEvent(j);
    TSArrayse594[j] = timestamp_se594;
    tempArray594[j] = ts12594;
    ts12Ave594 += ts12594;
    SEcounts594++;
  }

  
  curAve594 = curAve594 / boCounts594;
  ts12Ave594 = ts12Ave594/SEcounts594;
  NBins594 = max594 - min594;

  TH1* UCNrate_li6594 = new TH1F ("UCNrate_li6594" , "UCN_rate Histogram" , NBins594, min594, max594);
  
  int points594;
  int maxrate1594 = 0;
  int maxrate2594 = 0;
  int maxrate3594 = 0;
 

  ULong64_t eventTot594 = (Double_t) uinli6594 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot594 ; j++) {
    uinli6594 -> GetEvent(j);
      
    if (tIsUCN594 > 0 && tUnixTime594 > 20e6){
      UCNrate_li6594 -> Fill(tUnixTimePrecise594);
      if (tUnixTimePrecise594 > 1510870622 + 20 && tUnixTimePrecise594 < 1510871222 - 20){
	if (maxrate1594 < = UCNrate_li6594 -> GetMaximum())
	  maxrate1594 = UCNrate_li6594 -> GetMaximum();
      }
      if (tUnixTimePrecise594 > 1510871520 + 20 && tUnixTimePrecise594 < 1510872118 - 20){
	if (maxrate2594 < = UCNrate_li6594 -> GetMaximum())
	  maxrate2594 = UCNrate_li6594 -> GetMaximum();
      }
      if (tUnixTimePrecise594 > 1510872427  + 20 && tUnixTimePrecise594 < 1510873023 - 20){
	if (maxrate3594 < = UCNrate_li6594 -> GetMaximum())
	  maxrate3594 = UCNrate_li6594 -> GetMaximum();
      }
    }
    points594++;
    
  }


  cout << maxrate1594 << " "<< maxrate2594 << " " << maxrate3594  << endl;
  cout << "The average current for this run was " << curAve594 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave594 << endl;


  double tave1594;
  double tave2594;
  double tave3594;

  int cts1594 = 0;
  int cts2594 = 0;
  int cts3594 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents594 ; j++){
    sourceEpics594 -> GetEvent(j);
    if (timestamp_se594 > 1510870622  && timestamp_se594 < 1510871222 ){
      tave1594 += ts12594;
      cts1594++;
    }
    if (timestamp_se594 > 1510871520  && timestamp_se594 < 1510872118 ){
      tave2594 += ts12594;
      cts2594++;
    }
    if (timestamp_se594 > 1510872427  && timestamp_se594 < 1510873023 ){
      tave3594 += ts12594;
      cts3594++;
    }
  }

  tave1594 = tave1594/ cts1594;
  tave2594 = tave2594/ cts2594;
  tave3594 = tave3594/ cts3594;

  cout << tave1594 << " " << tave2594 << " " << tave3594  << endl;

  cout << "*******************************************" << endl;

  
  TCanvas *c1594 = new TCanvas ("c1594", "c1594", 1200, 900);
  UCNrate_li6594 -> Draw();



  TCanvas *c2594 = new TCanvas ("c2594" , "c2594", 1200, 900);

  TGraphErrors *gr_b594 = new TGraphErrors (counts594 , TSArray594 , curArray594, 0 , 0);

  gr_b594 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b594 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b594 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b594 -> SetMarkerStyle(20);
  
  gr_b594 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b594 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b594 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b594 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b594 -> SetMarkerColor(1);

  

  gr_b594 -> Draw("Ap");
  UCNrate_li6594 -> Draw("same");

  TF1 *f594 = new TF1("f594","140", min594 ,max594 );
  TCanvas *c3594 = new TCanvas ("c3594" , "c3594" , 1200, 900);

  TGraph *gr_s594 = new TGraph (SEcounts594 , TSArrayse594, tempArray594);
  gr_s594 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s594 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s594 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s594 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s594 -> SetMarkerStyle(20);
  
  gr_s594 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s594 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s594 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s594 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s594 -> SetMarkerColor(1);

  gr_s594 -> Draw("ap");
  //  UCNrate_li6594 -> Divide(f594);
  //UCNrate_li6594 -> Draw("same");



  
}
