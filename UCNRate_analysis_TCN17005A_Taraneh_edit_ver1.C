// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17005A.
// UCN RATE AT DIFFERENT BEAM CURRENTS
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNRate_analysis_TCN17005A_Taraneh_edit_ver1(){

  TFile *fin587 = new TFile ("~/raw_Data/ucn_tree_00000587.root", "READ");
  TFile *fin588 = new TFile ("~/raw_Data/ucn_tree_00000588.root", "READ");
  TFile *fin589 = new TFile ("~/raw_Data/ucn_tree_00000589.root", "READ");
  TFile *fin590 = new TFile ("~/raw_Data/ucn_tree_00000590.root", "READ");
  TFile *fin591 = new TFile ("~/raw_Data/ucn_tree_00000591.root", "READ");
  TFile *fin592 = new TFile ("~/raw_Data/ucn_tree_00000592.root", "READ");
  TFile *fin593 = new TFile ("~/raw_Data/ucn_tree_00000593.root", "READ");


  TTree *uinli6587 = (TTree*) fin587 -> Get("UCNHits_Li-6");
  TTree *uinli6588 = (TTree*) fin588 -> Get("UCNHits_Li-6");
  TTree *uinli6589 = (TTree*) fin589 -> Get("UCNHits_Li-6");
  TTree *uinli6590 = (TTree*) fin590 -> Get("UCNHits_Li-6");
  TTree *uinli6591 = (TTree*) fin591 -> Get("UCNHits_Li-6");
  TTree *uinli6592 = (TTree*) fin592 -> Get("UCNHits_Li-6");
  TTree *uinli6593 = (TTree*) fin593 -> Get("UCNHits_Li-6");


  TTree *bl587 = (TTree*) fin587 -> Get("BeamlineEpicsTree");
  TTree *bl588 = (TTree*) fin588 -> Get("BeamlineEpicsTree");
  TTree *bl589 = (TTree*) fin589 -> Get("BeamlineEpicsTree");
  TTree *bl590 = (TTree*) fin590 -> Get("BeamlineEpicsTree");
  TTree *bl591 = (TTree*) fin591 -> Get("BeamlineEpicsTree");
  TTree *bl592 = (TTree*) fin592 -> Get("BeamlineEpicsTree");
  TTree *bl593 = (TTree*) fin593 -> Get("BeamlineEpicsTree");

  TTree *sourceEpics587 = (TTree*) fin587 -> Get("SourceEpicsTree");
  TTree *sourceEpics588 = (TTree*) fin588 -> Get("SourceEpicsTree");
  TTree *sourceEpics589 = (TTree*) fin589 -> Get("SourceEpicsTree");
  TTree *sourceEpics590 = (TTree*) fin590 -> Get("SourceEpicsTree");
  TTree *sourceEpics591 = (TTree*) fin591 -> Get("SourceEpicsTree");
  TTree *sourceEpics592 = (TTree*) fin592 -> Get("SourceEpicsTree");
  TTree *sourceEpics593 = (TTree*) fin593 -> Get("SourceEpicsTree");
  
  

  double tUnixTimePrecise587;
  double tUnixTimePrecise588;
  double tUnixTimePrecise589;
  double tUnixTimePrecise590;
  double tUnixTimePrecise591;
  double tUnixTimePrecise592;
  double tUnixTimePrecise593;

  double tUnixTime587;
  double tUnixTime588;
  double tUnixTime589;
  double tUnixTime590;
  double tUnixTime591;
  double tUnixTime592;
  double tUnixTime593;
  

  UShort_t tIsUCN587;
  UShort_t tIsUCN588;
  UShort_t tIsUCN589;
  UShort_t tIsUCN590;
  UShort_t tIsUCN591;
  UShort_t tIsUCN592;
  UShort_t tIsUCN593;
  
  double cur587;
  double cur588;
  double cur589;
  double cur590;
  double cur591;
  double cur592;
  double cur593;

  double ts12587;
  double ts12588;
  double ts12589;
  double ts12590;
  double ts12591;
  double ts12592;
  double ts12593;
  

  double curArray587 [1000000];
  double curArray588 [1000000];
  double curArray589 [1000000];
  double curArray590 [1000000];
  double curArray591 [1000000];
  double curArray592 [1000000];
  double curArray593 [1000000];
  
  double curAve587;
  double curAve588;
  double curAve589;
  double curAve590;
  double curAve591;
  double curAve592;
  double curAve593;

  double ts12Ave587;
  double ts12Ave588;
  double ts12Ave589;
  double ts12Ave590;
  double ts12Ave591;
  double ts12Ave592;
  double ts12Ave593;
  
  

  int timestamp_bl587;
  int timestamp_bl588;
  int timestamp_bl589;
  int timestamp_bl590;
  int timestamp_bl591;
  int timestamp_bl592;
  int timestamp_bl593;


  int timestamp_se587;
  int timestamp_se588;
  int timestamp_se589;
  int timestamp_se590;
  int timestamp_se591;
  int timestamp_se592;
  int timestamp_se593;
  

  double TSArray587 [1000000];
  double TSArray588 [1000000];
  double TSArray589 [1000000];
  double TSArray590 [1000000];
  double TSArray591 [1000000];
  double TSArray592 [1000000];
  double TSArray593 [1000000];

  double TSArrayse587 [1000000];
  double TSArrayse588 [1000000];
  double TSArrayse589 [1000000];
  double TSArrayse590 [1000000];
  double TSArrayse591 [1000000];
  double TSArrayse592 [1000000];
  double TSArrayse593 [1000000];

  double tempArray587 [1000000];
  double tempArray588 [1000000];
  double tempArray589 [1000000];
  double tempArray590 [1000000];
  double tempArray591 [1000000];
  double tempArray592 [1000000];
  double tempArray593 [1000000];
  
  
  Double_t min587 = 15400000000;
  Double_t min588 = 15400000000;
  Double_t min589 = 15400000000;
  Double_t min590 = 15400000000;
  Double_t min591 = 15400000000;
  Double_t min592 = 15400000000;
  Double_t min593 = 15400000000;


  Double_t max587 = 0.;
  Double_t max588 = 0.;
  Double_t max589 = 0.;
  Double_t max590 = 0.;
  Double_t max591 = 0.;
  Double_t max592 = 0.;
  Double_t max593 = 0.;

  Int_t NBins587;
  Int_t NBins588;
  Int_t NBins589;
  Int_t NBins590;
  Int_t NBins591;
  Int_t NBins592;
  Int_t NBins593;
   
  uinli6587 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise587);
  uinli6588 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise588);
  uinli6589 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise589);
  uinli6590 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise590);
  uinli6591 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise591);
  uinli6592 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise592);
  uinli6593 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise593);

  uinli6587 -> SetBranchAddress ("tUnixTime", &tUnixTime587);
  uinli6588 -> SetBranchAddress ("tUnixTime", &tUnixTime588);
  uinli6589 -> SetBranchAddress ("tUnixTime", &tUnixTime589);
  uinli6590 -> SetBranchAddress ("tUnixTime", &tUnixTime590);
  uinli6591 -> SetBranchAddress ("tUnixTime", &tUnixTime591);
  uinli6592 -> SetBranchAddress ("tUnixTime", &tUnixTime592);
  uinli6593 -> SetBranchAddress ("tUnixTime", &tUnixTime593);
  

  uinli6587 -> SetBranchAddress ("tIsUCN" , &tIsUCN587);
  uinli6588 -> SetBranchAddress ("tIsUCN" , &tIsUCN588);
  uinli6589 -> SetBranchAddress ("tIsUCN" , &tIsUCN589);
  uinli6590 -> SetBranchAddress ("tIsUCN" , &tIsUCN590);
  uinli6591 -> SetBranchAddress ("tIsUCN" , &tIsUCN591);
  uinli6592 -> SetBranchAddress ("tIsUCN" , &tIsUCN592);
  uinli6593 -> SetBranchAddress ("tIsUCN" , &tIsUCN593);


  bl587 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur587);
  bl588 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur588);
  bl589 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur589);
  bl590 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur590);
  bl591 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur591);
  bl592 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur592);
  bl593 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur593);

  
  bl587 -> SetBranchAddress ("timestamp", &timestamp_bl587);
  bl588 -> SetBranchAddress ("timestamp", &timestamp_bl588);
  bl589 -> SetBranchAddress ("timestamp", &timestamp_bl589);
  bl590 -> SetBranchAddress ("timestamp", &timestamp_bl590);
  bl591 -> SetBranchAddress ("timestamp", &timestamp_bl591);
  bl592 -> SetBranchAddress ("timestamp", &timestamp_bl592);
  bl593 -> SetBranchAddress ("timestamp", &timestamp_bl593);


  sourceEpics587 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12587);
  sourceEpics588 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12588);
  sourceEpics589 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12589);
  sourceEpics590 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12590);
  sourceEpics591 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12591);
  sourceEpics592 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12592);
  sourceEpics593 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12593);


  sourceEpics587 -> SetBranchAddress ("timestamp", &timestamp_se587);
  sourceEpics588 -> SetBranchAddress ("timestamp", &timestamp_se588);
  sourceEpics589 -> SetBranchAddress ("timestamp", &timestamp_se589);
  sourceEpics590 -> SetBranchAddress ("timestamp", &timestamp_se590);
  sourceEpics591 -> SetBranchAddress ("timestamp", &timestamp_se591);
  sourceEpics592 -> SetBranchAddress ("timestamp", &timestamp_se592);
  sourceEpics593 -> SetBranchAddress ("timestamp", &timestamp_se593);
  
  


  // *************
  // FOR RUN 587
  // ************

  int counts587 = 0;
  int boCounts587;
  
  
  double beamlineEvent587 = (Double_t) bl587-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 587 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent587 ;j++) {
    bl587 -> GetEvent(j);
    TSArray587[counts587] = timestamp_bl587;
    curArray587[counts587] = cur587*2000;

    if (counts587 > 1){
      if (curArray587[counts587 - 1] < 0.08 && curArray587[counts587] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl587 << endl;
	curAve587 += cur587;
	boCounts587++;
      }
      if (curArray587[counts587-1] > 0.08 && curArray587[counts587] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl587 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl587 < min587 ){
      min587 = timestamp_bl587;
    }
    // MAX TIME STAMP
    if (timestamp_bl587 > max587){
      max587 = timestamp_bl587;
    }

    counts587++;
  }

  int SEcounts587;
  double sourceEpicsEvents587 = (double) sourceEpics587 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents587 ; j++){
    sourceEpics587 -> GetEvent(j);
    TSArrayse587[j] = timestamp_se587;
    tempArray587[j] = ts12587;
    ts12Ave587 += ts12587;
    SEcounts587++;
  }

  
  curAve587 = curAve587 / boCounts587;
  ts12Ave587 = ts12Ave587/SEcounts587;
  NBins587 = max587 - min587;

  TH1* UCNrate_li6587 = new TH1F ("UCNrate_li6587" , "UCN_rate Histogram" , NBins587, min587, max587);
  
  int points587;
  int rate1587;
  int rate2587;
  int rate3587;
  int rate4587;

  double interval1587;
  double interval2587;
  double interval3587;
  double interval4587;
 

  ULong64_t eventTot587 = (Double_t) uinli6587 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot587 ; j++) {
    uinli6587 -> GetEvent(j);
      
    if (tIsUCN587 > 0 && tUnixTime587 > 20e6){
      UCNrate_li6587 -> Fill(tUnixTimePrecise587);
      if (tUnixTimePrecise587 > 1510853491 + 20 && tUnixTimePrecise587 < 1510853592 - 20)
	rate1587++;
      if (tUnixTimePrecise587 > 1510853794 + 20 && tUnixTimePrecise587 < 1510854087 - 20)
	rate2587++;
      if (tUnixTimePrecise587 > 1510854390 + 20 && tUnixTimePrecise587 < 1510854990 - 20)
	rate3587++;
      if (tUnixTimePrecise587 > 1510855287 + 20 && tUnixTimePrecise587 <1510855887 - 20)
	rate4587++;
    }
    points587++;
    
  }

  interval1587 = -( 1510853491 + 20) + (1510853592 - 20);
  interval2587 = -(1510853794 + 20) +( 1510854087 - 20);
  interval3587 = -(1510854390 + 20) + (1510854990 - 20);
  interval4587 = -(1510855287 + 20) + (1510855887 - 20);

  cout << rate1587/interval1587 << " "<< rate2587/interval2587 << " " << rate3587/interval3587 << " " << rate4587/interval4587 << endl;
  cout << "The average current for this run was " << curAve587 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave587 << endl;
  cout << "For this run, the first pulse generated by being irradiated by " << 1510853592 - 1510853491 << " s" << endl;
  cout << "The second pulse was generated by irradiating for about " << 1510854087 - 1510853794 << " s" << endl;
  cout << "The third pulse was generated by irradiating for about " << 1510854990 - 1510854390 << " s"<< endl;
  cout << "And the fourth pulse was generated by irradiaiting the beam for about " << 1510855887 - 1510855287 << endl;

  
  double tave1587;
  double tave2587;
  double tave3587;
  double tave4587;

  int cts1587 = 0;
  int cts2587 = 0;
  int cts3587 = 0;
  int cts4587 = 0;

  double timestampArray_se587[1000000];
  int countsse587;
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents587 ; j++){
    sourceEpics587 -> GetEvent(j);
    timestampArray_se587[j] = timestamp_se587;
    if (timestamp_se587 > 1510853491  && timestamp_se587 < 1510853592 ){
      tave1587 += ts12587;
      cts1587++;
    }
    if (timestamp_se587 > 1510853794  && timestamp_se587 < 1510854087 ){
      tave2587 += ts12587;
      cts2587++;
    }
    if (timestamp_se587 > 1510854390  && timestamp_se587 < 1510854990 ){
      tave3587 += ts12587;
      cts3587++;
    }
    if (timestamp_se587 > 1510855287 && timestamp_se587 <1510855887 ){
      tave4587 += ts12587;
      cts4587++;
    }
    countsse587++;
  }

  tave1587 = tave1587/ cts1587;
  tave2587 = tave2587/ cts2587;
  tave3587 = tave3587/ cts3587;
  tave4587 = tave4587/ cts4587;

  cout << tave1587 << " " << tave2587 << " " << tave3587 << " " << tave4587 << endl;

  cout << "*******************************************" << endl;

  
  TCanvas *c1587 = new TCanvas ("c1587", "c1587", 1200, 900);
  UCNrate_li6587 -> Draw();



  TCanvas *c2587 = new TCanvas ("c2587" , "c2587", 1200, 900);

  TGraphErrors *gr_b587 = new TGraphErrors (counts587 , TSArray587 , curArray587, 0 , 0);

  gr_b587 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b587 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b587 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b587 -> SetMarkerStyle(20);
  
  gr_b587 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b587 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b587 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b587 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b587 -> SetMarkerColor(1);

  

  gr_b587 -> Draw("Ap");
   UCNrate_li6587 -> Draw("same");

  TF1 *f587 = new TF1("f587","10", min587 ,max587 );
  TCanvas *c3587 = new TCanvas ("c3587" , "c3587" , 1200, 900);

  TGraph *gr_s587 = new TGraph (SEcounts587 , TSArrayse587, tempArray587);
  gr_s587 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s587 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s587 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s587 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s587 -> SetMarkerStyle(20);
  
  gr_s587 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s587 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s587 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s587 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s587 -> SetMarkerColor(1);

  gr_s587 -> Draw("ap");
  UCNrate_li6587 -> Divide(f587);
  //UCNrate_li6587 -> Draw("same");


 
  // *************
  // FOR RUN 588
  // ************

  int counts588 = 0;
  int boCounts588;
  
  double beamlineEvent588 = (Double_t) bl588-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 588 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent588 ;j++) {
    bl588 -> GetEvent(j);
    TSArray588[counts588] = timestamp_bl588;
    curArray588[counts588] = cur588*2000;
    
    if (counts588 > 1){
      if (curArray588[counts588 - 1] < 0.08 && curArray588[counts588] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl588 << endl;
	curAve588 += cur588;
	boCounts588++;
      }
      if (curArray588[counts588-1] > 0.08 && curArray588[counts588] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl588 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl588 < min588 ){
      min588 = timestamp_bl588;
    }
    // MAX TIME STAMP
    if (timestamp_bl588 > max588){
      max588 = timestamp_bl588;
    }

    counts588++;
  }


  int SEcounts588;
  double sourceEpicsEvents588 = (double) sourceEpics588 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents588 ; j++){
    sourceEpics588 -> GetEvent(j);
    TSArrayse588[j] = timestamp_se588;
    tempArray588[j] = ts12588;
    ts12Ave588 += ts12588;
    SEcounts588++;
  }


  curAve588 = curAve588 / boCounts588;
  ts12Ave588 = ts12Ave588/ SEcounts588;
  NBins588 = max588 - min588;

  TH1* UCNrate_li6588 = new TH1F ("UCNrate_li6588" , "UCN_rate Histogram" , NBins588, min588, max588);
  
  int points588;
  int rate1588;
  int rate2588;
  int rate3588;

  double interval1588;
  double interval2588;
  double interval3588;
 

  ULong64_t eventTot588 = (Double_t) uinli6588 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot588 ; j++) {
    uinli6588 -> GetEvent(j);
      
    if (tIsUCN588 > 0 && tUnixTime588 > 20e6){
      UCNrate_li6588 -> Fill(tUnixTimePrecise588);
      if (tUnixTimePrecise588 > 1510856459 + 20 && tUnixTimePrecise588 < 1510857059 - 20)
	rate1588++;
      if (tUnixTimePrecise588 > 1510857361 + 20 && tUnixTimePrecise588 < 1510857960 - 20)
	rate2588++;
      if (tUnixTimePrecise588 > 1510858262 + 20 && tUnixTimePrecise588 < 1510858861 - 20)
	rate3588++;

      points588++;
    }
  }
  
  interval1588 = -( 1510856459 + 20) + (1510857059 - 20);
  interval2588 = -(1510857361 + 20) + (1510857960 - 20);
  interval3588 = -(1510858262 + 20) + (1510858861 - 20);

  cout << rate1588/interval1588 << " "<< rate2588/interval2588 << " " << rate3588/interval3588  << endl;
  cout << "The average current for this run was " << curAve588 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave588 << endl;
  cout << "The first pulse was being generated by irradiating for about " << 1510857059 - 1510856459 << " s" << endl;
  cout << "The second pulse was being generated by irradiating for about " << 1510857960 - 1510857361 << " s" << endl;
  cout << "The third pulse was being generated by irradiating for about " << 1510858861 - 1510858262 << " s" << endl;
  

  double tave1588;
  double tave2588;
  double tave3588;

  int cts1588 = 0;
  int cts2588 = 0;
  int cts3588 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents588 ; j++){
    sourceEpics588 -> GetEvent(j);
    if (timestamp_se588 > 1510856459  && timestamp_se588 < 1510857059 ){
      tave1588 += ts12588;
      cts1588++;
    }
    if (timestamp_se588 > 1510857361  && timestamp_se588 < 1510857960  ){
      tave2588 += ts12588;
      cts2588++;
    }
    if (timestamp_se588 > 1510858262  && timestamp_se588 < 1510858861 ){
      tave3588 += ts12588;
      cts3588++;
    }
  }

  tave1588 = tave1588/ cts1588;
  tave2588 = tave2588/ cts2588;
  tave3588 = tave3588/ cts3588;

  cout << tave1588 << " " << tave2588 << " " << tave3588 <<  endl;

  
  cout << "*******************************************" << endl;

  
  TCanvas *c1588 = new TCanvas ("c1588", "c1588", 1200, 900);
  UCNrate_li6588 -> Draw();



  TCanvas *c2588 = new TCanvas ("c2588" , "c2588", 1200, 900);

  TGraphErrors *gr_b588 = new TGraphErrors (counts588 , TSArray588 , curArray588, 0 , 0);

  gr_b588 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b588 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b588 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b588 -> SetMarkerStyle(20);
  
  gr_b588 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b588 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b588 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b588 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b588 -> SetMarkerColor(1);

  

  gr_b588 -> Draw("Ap");
  UCNrate_li6588 -> Draw("same");
  
  TF1 *f588 = new TF1("f588","160", min588 ,max588 );
  TCanvas *c3588 = new TCanvas ("c3588" , "c3588" , 1200, 900);

  TGraph *gr_s588 = new TGraph (SEcounts588 , TSArrayse588, tempArray588);
  gr_s588 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s588 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s588 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s588 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s588 -> SetMarkerStyle(20);
  
  gr_s588 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s588 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s588 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s588 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s588 -> SetMarkerColor(1);

  gr_s588 -> Draw("ap");
  //UCNrate_li6588 -> Divide(f588);
  //UCNrate_li6588 -> Draw("same");

  // *************
  // FOR RUN 589
  // ************

  int counts589 = 0;
  int boCounts589;
  
  double beamlineEvent589 = (Double_t) bl589-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 589 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent589 ;j++) {
    bl589 -> GetEvent(j);
    TSArray589[counts589] = timestamp_bl589;
    curArray589[counts589] = cur589*2000;
    ts12Ave589 += ts12589;
    if (counts589 > 1){
      if (curArray589[counts589 - 1] < 0.08 && curArray589[counts589] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl589 << endl;
	curAve589 += cur589;
	boCounts589++;
      }
      if (curArray589[counts589-1] > 0.08 && curArray589[counts589] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl589 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl589 < min589 ){
      min589 = timestamp_bl589;
    }
    // MAX TIME STAMP
    if (timestamp_bl589 > max589){
      max589 = timestamp_bl589;
    }

    counts589++;
  }

  int SEcounts589;
  double sourceEpicsEvents589 = (double) sourceEpics589 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents589 ; j++){
    sourceEpics589 -> GetEvent(j);
    TSArrayse589[j] = timestamp_se589;
    tempArray589[j] = ts12589;
    ts12Ave589 += ts12589;
    SEcounts589++;
  }

  
  curAve589 = curAve589 / boCounts589;
  ts12Ave589 = ts12Ave589/SEcounts589;
  NBins589 = max589 - min589;

  TH1* UCNrate_li6589 = new TH1F ("UCNrate_li6589" , "UCN_rate Histogram" , NBins589, min589, max589);
  
  int points589;
  int rate1589;
  int rate2589;
  int rate3589;


  double interval1589;
  double interval2589;
  double interval3589;

 

  ULong64_t eventTot589 = (Double_t) uinli6589 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot589 ; j++) {
    uinli6589 -> GetEvent(j);
      
    if (tIsUCN589 > 0 && tUnixTime589 > 20e6){
      UCNrate_li6589 -> Fill(tUnixTimePrecise589);
      if (tUnixTimePrecise589 > 1510859274 + 20 && tUnixTimePrecise589 < 1510859873 - 20)
	rate1589++;
      if (tUnixTimePrecise589 > 1510860176 + 20 && tUnixTimePrecise589 < 1510860775 - 20)
	rate2589++;
      if (tUnixTimePrecise589 > 1510861077 + 60 && tUnixTimePrecise589 < 1510861698 - 20)
	rate3589++;
    }
    points589++;
    
  }

  interval1589 = -( 1510859274 + 20) + (1510859873 - 20);
  interval2589 = -(1510860176 + 20) +( 1510860775 - 20);
  interval3589 = -(1510861077 + 60) + (1510861698 - 20);

  cout << rate1589/interval1589 << " "<< rate2589/interval2589 << " " << rate3589/interval3589 << endl;
  cout << "The average current for this run was " << curAve589 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave589 << endl;
  cout << "The first pulse was generated by irradiationg for about " << 1510859873 - 1510859274 << " s" << endl;
  cout << "The second pulse was generated by irradiaiting for about " << 1510860775 - 1510860176 << " s" << endl;
  cout << "The third pulse was generated by irrdiaiton  for about " << 1510861698 - 1510861077 << " s " << endl;

  double tave1589;
  double tave2589;
  double tave3589;

  int cts1589 = 0;
  int cts2589 = 0;
  int cts3589 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents589 ; j++){
    sourceEpics589 -> GetEvent(j);
    if (timestamp_se589 > 1510859274  && timestamp_se589 < 1510859873 ){
      tave1589 += ts12589;
      cts1589++;
    }
    if (timestamp_se589 > 1510860176  && timestamp_se589 < 1510860775  ){
      tave2589 += ts12589;
      cts2589++;
    }
    if (timestamp_se589 > 1510861077  && timestamp_se589 < 1510861698 ){
      tave3589 += ts12589;
      cts3589++;
    }
  }

  tave1589 = tave1589/ cts1589;
  tave2589 = tave2589/ cts2589;
  tave3589 = tave3589/ cts3589;

  cout << tave1589 << " " << tave2589 << " " << tave3589 <<  endl;

  
  cout << "*******************************************" << endl;

  
  TCanvas *c1589 = new TCanvas ("c1589", "c1589", 1200, 900);
  UCNrate_li6589 -> Draw();



  TCanvas *c2589 = new TCanvas ("c2589" , "c2589", 1200, 900);

  TGraphErrors *gr_b589 = new TGraphErrors (counts589 , TSArray589 , curArray589, 0 , 0);

  gr_b589 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b589 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b589 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b589 -> SetMarkerStyle(20);
  
  gr_b589 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b589 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b589 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b589 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b589 -> SetMarkerColor(1);

  

  gr_b589 -> Draw("Ap");
  UCNrate_li6589 -> Draw("same");
  
  TF1 *f589 = new TF1("f589","160", min589 ,max589 );
  TCanvas *c3589 = new TCanvas ("c3589" , "c3589" , 1200, 900);

  TGraph *gr_s589 = new TGraph (SEcounts589 , TSArrayse589, tempArray589);
  gr_s589 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s589 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s589 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s589 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s589 -> SetMarkerStyle(20);
  
  gr_s589 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s589 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s589 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s589 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s589 -> SetMarkerColor(1);

  gr_s589 -> Draw("ap");
  //UCNrate_li6589 -> Divide(f589);
  //UCNrate_li6589 -> Draw("same");

  // *************
  // FOR RUN 590
  // ************

  int counts590 = 0;
  int boCounts590;
  
  double beamlineEvent590 = (Double_t) bl590-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 590 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent590 ;j++) {
    bl590 -> GetEvent(j);
    TSArray590[counts590] = timestamp_bl590;
    curArray590[counts590] = cur590*2000;
    ts12Ave590 += ts12590;
    if (counts590 > 1){
      if (curArray590[counts590 - 1] < 0.08 && curArray590[counts590] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl590 << endl;
	curAve590 += cur590;
	boCounts590++;
      }
      if (curArray590[counts590-1] > 0.08 && curArray590[counts590] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl590 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl590 < min590 ){
      min590 = timestamp_bl590;
    }
    // MAX TIME STAMP
    if (timestamp_bl590 > max590){
      max590 = timestamp_bl590;
    }

    counts590++;
  }


  int SEcounts590;
  double sourceEpicsEvents590 = (double) sourceEpics590 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents590 ; j++){
    sourceEpics590 -> GetEvent(j);
    TSArrayse590[j] = timestamp_se590;
    tempArray590[j] = ts12590;
    ts12Ave590 += ts12590;
    SEcounts590++;
  }

  
  curAve590 = curAve590 / boCounts590 ;
  ts12Ave590 = ts12Ave590 / SEcounts590;
  NBins590 = max590 - min590;

  TH1* UCNrate_li6590 = new TH1F ("UCNrate_li6590" , "UCN_rate Histogram" , NBins590, min590, max590);
  
  int points590;
  int rate1590;
  int rate2590;
  int rate3590;


  double interval1590;
  double interval2590;
  double interval3590;

 

  ULong64_t eventTot590 = (Double_t) uinli6590 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot590 ; j++) {
    uinli6590 -> GetEvent(j);
      
    if (tIsUCN590 > 0 && tUnixTime590 > 20e6){
      UCNrate_li6590 -> Fill(tUnixTimePrecise590);
      if (tUnixTimePrecise590 > 1510862192 + 20 && tUnixTimePrecise590 < 1510862791 - 20)
	rate1590++;
      if (tUnixTimePrecise590 > 1510863088 + 20 && tUnixTimePrecise590 < 1510863692 - 20)
	rate2590++;
      if (tUnixTimePrecise590 > 1510863990 + 60 && tUnixTimePrecise590 < 1510864589 - 20)
	rate3590++;
    }
    points590++;
    
  }

  interval1590 = -( 1510862192 + 20) + (1510862791 - 20);
  interval2590 = -(1510863088 + 20) +( 1510863692 - 20);
  interval3590 = -(1510863990 + 60) + (1510864589 - 20);

  cout << rate1590/interval1590 << " "<< rate2590/interval2590 << " " << rate3590/interval3590 << endl;
  cout << "The average current for this run was " << curAve590 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave590 << endl;
  cout << "The first pulse was generated by irradiating for about " << 1510862791 - 1510862192 << " s " << endl;
  cout << "The second pulse was generated by irradiaiting for about " << 1510863692 - 1510863088 << " s " << endl;
  cout << "The third pulse was generated by irradiating for about " << 1510864589 - 1510863990 << " s  " << endl;


  double tave1590;
  double tave2590;
  double tave3590;

  int cts1590 = 0;
  int cts2590 = 0;
  int cts3590 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents590 ; j++){
    sourceEpics590 -> GetEvent(j);
    if (timestamp_se590 > 1510862192  && timestamp_se590 < 1510862791 ){
      tave1590 += ts12590;
      cts1590++;
    }
    if (timestamp_se590 > 1510863088  && timestamp_se590 < 1510863692  ){
      tave2590 += ts12590;
      cts2590++;
    }
    if (timestamp_se590 > 1510863990  && timestamp_se590 < 1510864589 ){
      tave3590 += ts12590;
      cts3590++;
    }
  }

  tave1590 = tave1590/ cts1590;
  tave2590 = tave2590/ cts2590;
  tave3590 = tave3590/ cts3590;

  cout << tave1590 << " " << tave2590 << " " << tave3590 <<  endl;
  
  cout << "*******************************************" << endl;

  
  TCanvas *c1590 = new TCanvas ("c1590", "c1590", 1200, 900);
  UCNrate_li6590 -> Draw();



  TCanvas *c2590 = new TCanvas ("c2590" , "c2590", 1200, 900);

  TGraphErrors *gr_b590 = new TGraphErrors (counts590 , TSArray590 , curArray590, 0 , 0);

  gr_b590 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b590 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b590 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b590 -> SetMarkerStyle(20);
  
  gr_b590 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b590 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b590 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b590 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b590 -> SetMarkerColor(1);

  

  gr_b590 -> Draw("Ap");
  UCNrate_li6590 -> Draw("same");


  TF1 *f590 = new TF1("f590","160", min590 ,max590 );
  TCanvas *c3590 = new TCanvas ("c3590" , "c3590" , 1200, 900);

  TGraph *gr_s590 = new TGraph (SEcounts590 , TSArrayse590, tempArray590);
  gr_s590 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s590 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s590 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s590 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s590 -> SetMarkerStyle(20);
  
  gr_s590 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s590 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s590 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s590 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s590 -> SetMarkerColor(1);

  gr_s590 -> Draw("ap");
  //UCNrate_li6590 -> Divide(f590);
  //UCNrate_li6590 -> Draw("same");

  
  
  // *************
  // FOR RUN 591
  // ************

  int counts591 = 0;
  int boCounts591;
  
  double beamlineEvent591 = (Double_t) bl591-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 591 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent591 ;j++) {
    bl591 -> GetEvent(j);
    TSArray591[counts591] = timestamp_bl591;
    curArray591[counts591] = cur591*2000;
    ts12Ave591 += ts12591;
    if (counts591 > 1){
      if (curArray591[counts591 - 1] < 0.08 && curArray591[counts591] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl591 << endl;
	curAve591 += cur591;
	boCounts591++;
      }
      if (curArray591[counts591-1] > 0.08 && curArray591[counts591] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl591 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl591 < min591 ){
      min591 = timestamp_bl591;
    }
    // MAX TIME STAMP
    if (timestamp_bl591 > max591){
      max591 = timestamp_bl591;
    }

    counts591++;
  }

  int SEcounts591;
  double sourceEpicsEvents591 = (double) sourceEpics591 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents591 ; j++){
    sourceEpics591 -> GetEvent(j);
    TSArrayse591[j] = timestamp_se591;
    tempArray591[j] = ts12591;
    ts12Ave591 += ts12591;
    SEcounts591++;
  }

  curAve591 = curAve591 / boCounts591;
  ts12Ave591 = ts12Ave591 / SEcounts591;
  NBins591 = max591 - min591;

  TH1* UCNrate_li6591 = new TH1F ("UCNrate_li6591" , "UCN_rate Histogram" , NBins591, min591, max591);
  
  int points591;
  int rate1591;
  int rate2591;
  int rate3591;


  double interval1591;
  double interval2591;
  double interval3591;

 

  ULong64_t eventTot591 = (Double_t) uinli6591 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot591 ; j++) {
    uinli6591 -> GetEvent(j);
      
    if (tIsUCN591 > 0 && tUnixTime591 > 20e6){
      UCNrate_li6591 -> Fill(tUnixTimePrecise591);
      if (tUnixTimePrecise591 > 1510864992 + 20 && tUnixTimePrecise591 < 1510865595 - 20)
	rate1591++;
      if (tUnixTimePrecise591 > 1510865893 + 20 && tUnixTimePrecise591 < 1510866498 - 20)
	rate2591++;
      if (tUnixTimePrecise591 > 1510866796 + 60 && tUnixTimePrecise591 < 1510867394 - 20)
	rate3591++;
    }
    points591++;
    
  }

  interval1591 = -( 1510864992 + 20) + (1510865595 - 20);
  interval2591 = -(1510865893 + 20) +( 1510866498 - 20);
  interval3591 = -(1510866796 + 60) + (1510867394 - 20);

  cout << rate1591/interval1591 << " "<< rate2591/interval2591 << " " << rate3591/interval3591 << endl;
  cout << "The average current for this run was " << curAve591 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave591 << endl;
  cout << "The first pulse was generated by irradiating for about " << 1510865595 - 1510864992 << " s " << endl;
  cout << "The second pulse was generated by irradiaiting for about " << 1510866498 - 1510865893  << " s " << endl;
  cout << "The third pulse was generated by irradiating for about " << 1510867394 - 1510866796 << " s  " << endl;

  double tave1591;
  double tave2591;
  double tave3591;

  int cts1591 = 0;
  int cts2591 = 0;
  int cts3591 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents591 ; j++){
    sourceEpics591 -> GetEvent(j);
    if (timestamp_se591 > 1510864992  && timestamp_se591 < 1510865595 ){
      tave1591 += ts12591;
      cts1591++;
    }
    if (timestamp_se591 > 1510865893  && timestamp_se591 < 1510866498  ){
      tave2591 += ts12591;
      cts2591++;
    }
    if (timestamp_se591 > 1510866796  && timestamp_se591 < 1510867394 ){
      tave3591 += ts12591;
      cts3591++;
    }
  }

  tave1591 = tave1591/ cts1591;
  tave2591 = tave2591/ cts2591;
  tave3591 = tave3591/ cts3591;

  cout << tave1591 << " " << tave2591 << " " << tave3591 <<  endl;
  
  cout << "*******************************************" << endl;

  
  TCanvas *c1591 = new TCanvas ("c1591", "c1591", 1200, 900);
  UCNrate_li6591 -> Draw();



  TCanvas *c2591 = new TCanvas ("c2591" , "c2591", 1200, 900);

  TGraphErrors *gr_b591 = new TGraphErrors (counts591 , TSArray591 , curArray591, 0 , 0);

  gr_b591 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b591 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b591 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b591 -> SetMarkerStyle(20);
  
  gr_b591 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b591 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b591 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b591 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b591 -> SetMarkerColor(1);

  

  gr_b591 -> Draw("Ap");
  UCNrate_li6591 -> Draw("same");


  TF1 *f591 = new TF1("f591","160", min591 ,max591 );
  TCanvas *c3591 = new TCanvas ("c3591" , "c3591" , 1200, 900);

  TGraph *gr_s591 = new TGraph (SEcounts591 , TSArrayse591, tempArray591);
  gr_s591 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s591 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s591 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s591 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s591 -> SetMarkerStyle(20);
  
  gr_s591 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s591 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s591 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s591 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s591 -> SetMarkerColor(1);

  gr_s591 -> Draw("ap");
  //UCNrate_li6591 -> Divide(f591);
  //UCNrate_li6591 -> Draw("same");

  
  // *************
  // FOR RUN 592
  // ************

  int counts592 = 0;
  int boCounts592;
  
  double beamlineEvent592 = (Double_t) bl592-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 592 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent592 ;j++) {
    bl592 -> GetEvent(j);
    TSArray592[counts592] = timestamp_bl592;
    curArray592[counts592] = cur592*2000;
    ts12Ave592 += ts12592;
    if (counts592 > 1){
      if (curArray592[counts592 - 1] < 0.08 && curArray592[counts592] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl592 << endl;
	curAve592 += cur592;
	boCounts592++;
      }
      if (curArray592[counts592-1] > 0.08 && curArray592[counts592] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl592 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl592 < min592 ){
      min592 = timestamp_bl592;
    }
    // MAX TIME STAMP
    if (timestamp_bl592 > max592){
      max592 = timestamp_bl592;
    }

    counts592++;
  }

  int SEcounts592;
  double sourceEpicsEvents592 = (double) sourceEpics592 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents592 ; j++){
    sourceEpics592 -> GetEvent(j);
    TSArrayse592[j] = timestamp_se592;
    tempArray592[j] = ts12592;
    ts12Ave592 += ts12592;
    SEcounts592++;
  }

  
  curAve592 = curAve592 / boCounts592;
  ts12Ave592 = ts12Ave592 / SEcounts592;
  NBins592 = max592 - min592;

  TH1* UCNrate_li6592 = new TH1F ("UCNrate_li6592" , "UCN_rate Histogram" , NBins592, min592, max592);
  
  int points592;
  int rate1592;
  int rate2592;


  double interval1592;
  double interval2592;


  ULong64_t eventTot592 = (Double_t) uinli6592 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot592 ; j++) {
    uinli6592 -> GetEvent(j);
      
    if (tIsUCN592 > 0 && tUnixTime592 > 20e6){
      UCNrate_li6592 -> Fill(tUnixTimePrecise592);
      if (tUnixTimePrecise592 > 1510867930 + 20 && tUnixTimePrecise592 < 1510868518 - 20)
	rate1592++;
      if (tUnixTimePrecise592 > 1510868828 + 20 && tUnixTimePrecise592 < 1510869447 - 20)
	rate2592++;

    }
    points592++;
    
  }

  interval1592 = -( 1510867930 + 20) + (1510868518 - 20);
  interval2592 = -(1510868828 + 20) +( 1510869447 - 20);

  cout << rate1592/interval1592 << " "<< rate2592/interval2592  << endl;
  cout << "The average current for this run was " << curAve592 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave592 << endl;
  cout << "The first pulse was generated by irradiating for about " << 1510868518 - 1510867930  << " s " << endl;
  cout << "The second pulse was generated by irradiaiting for about " << 1510869447 - 1510868828  << " s " << endl;

  
  double tave1592;
  double tave2592;

  int cts1592 = 0;
  int cts2592 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents592 ; j++){
    sourceEpics592 -> GetEvent(j);
    if (timestamp_se592 > 1510867930  && timestamp_se592 < 1510868518 ){
      tave1592 += ts12592;
      cts1592++;
    }
    if (timestamp_se592 > 1510868828  && timestamp_se592 < 1510869447  ){
      tave2592 += ts12592;
      cts2592++;
    }
  }

  tave1592 = tave1592/ cts1592;
  tave2592 = tave2592/ cts2592;

  cout << tave1592 << " " << tave2592 <<  endl;
  
  cout << "*******************************************" << endl;

  
  TCanvas *c1592 = new TCanvas ("c1592", "c1592", 1200, 900);
  UCNrate_li6592 -> Draw();



  TCanvas *c2592 = new TCanvas ("c2592" , "c2592", 1200, 900);

  TGraphErrors *gr_b592 = new TGraphErrors (counts592 , TSArray592 , curArray592, 0 , 0);

  gr_b592 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b592 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b592 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b592 -> SetMarkerStyle(20);
  
  gr_b592 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b592 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b592 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b592 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b592 -> SetMarkerColor(1);

  

  gr_b592 -> Draw("Ap");
  UCNrate_li6592 -> Draw("same");

  TF1 *f592 = new TF1("f592","160", min592 ,max592 );
  TCanvas *c3592 = new TCanvas ("c3592" , "c3592" , 1200, 900);

  TGraph *gr_s592 = new TGraph (SEcounts592 , TSArrayse592, tempArray592);
  gr_s592 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s592 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s592 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s592 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s592 -> SetMarkerStyle(20);
  
  gr_s592 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s592 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s592 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s592 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s592 -> SetMarkerColor(1);

  gr_s592 -> Draw("ap");
  //UCNrate_li6592 -> Divide(f592);
  //UCNrate_li6592 -> Draw("same");


  
  // *************
  // FOR RUN 593
  // ************

  int counts593 = 0;
  double bOnTS593[1000000];
  int boCounts593;
  
  double beamlineEvent593 = (Double_t) bl593-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 593 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent593 ;j++) {
    bl593 -> GetEvent(j);
    TSArray593[counts593] = timestamp_bl593;
    curArray593[counts593] = cur593*2000;
    ts12Ave593 += ts12593 ;
    if (counts593 > 1){
      if (curArray593[counts593 - 1] < 0.08 && curArray593[counts593] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl593 << endl;
	curAve593 += cur593;
	boCounts593++;
      }
      if (curArray593[counts593-1] > 0.08 && curArray593[counts593] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl593 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl593 < min593 ){
      min593 = timestamp_bl593;
    }
    // MAX TIME STAMP
    if (timestamp_bl593 > max593){
      max593 = timestamp_bl593;
    }

    counts593++;
  }


  int SEcounts593;
  double sourceEpicsEvents593 = (double) sourceEpics593 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents593 ; j++){
    sourceEpics593 -> GetEvent(j);
    TSArrayse593[j] = timestamp_se593;
    tempArray593[j] = ts12593;
    ts12Ave593 += ts12593;
    SEcounts593++;
  }

  
  curAve593 = curAve593/ boCounts593;
  ts12Ave593 = ts12Ave593 /SEcounts593;
  NBins593 = max593 - min593;

  TH1* UCNrate_li6593 = new TH1F ("UCNrate_li6593" , "UCN_rate Histogram" , NBins593, min593, max593);
  UCNrate_li6593 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNrate_li6593 -> GetXaxis() -> SetTimeDisplay(1);
  UCNrate_li6593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNrate_li6593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNrate_li6593 -> GetXaxis() -> SetTitleSize(0.05);
  UCNrate_li6593 -> GetXaxis() -> SetLabelOffset(.03);
  UCNrate_li6593 -> GetXaxis() -> SetLabelSize(.04);
  int points593;
  int rate1593;

  double interval1593;


  ULong64_t eventTot593 = (Double_t) uinli6593 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot593 ; j++) {
    uinli6593 -> GetEvent(j);
      
    if (tIsUCN593 > 0 && tUnixTime593 > 20e6){
      UCNrate_li6593 -> Fill(tUnixTimePrecise593);
      if (tUnixTimePrecise593 > 1510869732 + 20 && tUnixTimePrecise593 < 1510870324 - 20)
	rate1593++;


    }
    points593++;
    
  }
  cout << rate1593 << endl;
  interval1593 = -( 1510869732 + 20) + (1510870324 - 20);

  cout << rate1593/interval1593  << endl;
  cout << "The average current for this run was " << curAve593 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave593 << endl;
  cout << "The first pulse was generated by irradiating for about " << 1510870324 - 1510869732 << " s " << endl;

  double tave1593;

  int cts1593 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents593 ; j++){
    sourceEpics593 -> GetEvent(j);
    if (timestamp_se593 > 1510869732 && timestamp_se593 < 1510870324 ){
      tave1593 += ts12593;
      cts1593++;
    }
  }

  tave1593 = tave1593/ cts1593;

  cout << tave1593 <<  endl;
  
  cout << "*******************************************" << endl;

  
  TCanvas *c1593 = new TCanvas ("c1593", "c1593", 1200, 900);
  UCNrate_li6593 -> Draw();



  TCanvas *c2593 = new TCanvas ("c2593" , "c2593", 1200, 900);

  TGraphErrors *gr_b593 = new TGraphErrors (counts593 , TSArray593 , curArray593, 0 , 0);

  gr_b593 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b593 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b593 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b593 -> SetMarkerStyle(20);
  
  gr_b593 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b593 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b593 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b593 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b593 -> SetMarkerColor(1);

  

  gr_b593 -> Draw("Ap");
  UCNrate_li6593 -> Draw("same");


  TF1 *f593 = new TF1("f593","160", min593 ,max593 );
  TCanvas *c3593 = new TCanvas ("c3593" , "c3593" , 1200, 900);

  TGraph *gr_s593 = new TGraph (SEcounts593 , TSArrayse593, tempArray593);
  gr_s593 -> SetTitle(" Isopure Temperature vs Time ");
  //gr_s593 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s593 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  gr_s593 -> GetXaxis() -> SetTimeDisplay(1);
  gr_s593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr_s593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr_s593 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s593 -> GetXaxis() -> SetLabelOffset(.03);
  gr_s593 -> GetXaxis() -> SetLabelSize(.04);
  //gr_s593 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s593 -> SetMarkerStyle(20);
  
  gr_s593 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s593 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s593 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s593 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s593 -> SetMarkerColor(1);

  gr_s593 -> Draw("ap");
  //UCNrate_li6593 -> Divide(f593);
  //UCNrate_li6593 -> Draw("same");
  

  // *********************
  // THE OVERALL RESULT
  //**********************

  double curAll[19] = { 0.1, 0.1, 0.3, 0.3, 0.3, 0.5, 0.5, 0.7, 0.7, 0.7, 0.9,  0.9, 1, 1};
  double tempAll[19] = { 0.88, 0.88, 0.9, 0.91, 0.92, 0.93, 0.91, 0.91, 0.92, 0.92, 0.93, 0.94, 0.94, 0.95};
  double rateAll[19] = { 156.9, 155.7, 461.1, 461.0, 460.7, 761.3, 765.0,  1065.4, 1058.7, 1069.8, 1347.3, 1354.5, 1500.7,  1489.8};
  double ratecurAll[19] ;

  for (int k = 0 ; k < 14 ; k++){
    ratecurAll[k] = rateAll[k]/curAll[k];
  }

  
  
  // ONLINE ANALYSIS
  double curOnline[19] = {0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7, 0.9, 0.9, 0.9, 1, 1, 1};
  double rateOnline[19] = {155, 155, 155, 460, 460, 460, 770, 770, 770, 1080, 1070, 1070, 1350, 1350, 1350, 1500, 1500, 1500};
  double tempOnline[19] = {0.87, 0.88, 0.88, 0.92, 0.92, 0.92, 0.93, 0.91, 0.91, 0.92, 0.92, 0.92, 0.93, 0.94, 0.94, 0.95, 0.95, 0.95};
  double ratecurOnline[18];

  for (int k = 0 ; k < 18 ; k++){
    ratecurOnline [k] = rateOnline[k] / curOnline[k] ;
  } 
  
  TCanvas *c1All = new TCanvas ("c1All" , "c1All" , 1200, 900);
  c1All -> Divide(2,1);

  c1All -> cd(1);
  TGraph *gr1All = new TGraph (14, curAll, rateAll);

  gr1All -> SetTitle("UCN Rate vs Predicted Beam Current");
  gr1All -> GetXaxis() -> SetTitle("Predicted Beam Current (#muA) " );
  gr1All -> GetYaxis() -> SetTitle("UCN Counts/s");
  gr1All -> SetMarkerStyle(20);
  
  gr1All -> GetXaxis() -> SetTitleSize(0.05);
  gr1All -> GetXaxis() -> SetTitleOffset(1.0);
  gr1All -> GetYaxis() -> SetTitleSize(0.05); 
  gr1All -> GetYaxis() -> SetTitleOffset(1.4);
  gr1All -> SetMarkerColor(1);
  
  TGraph *gr1Online = new TGraph (18, curOnline, rateOnline);
  gr1Online -> SetMarkerStyle(3);
  gr1Online -> SetMarkerColor(8);

  TLegend *leg1 = new TLegend (0.5226449, 0.854893, 0.9598662, 0.9419833);
  leg1 -> AddEntry(gr1All, "Taraneh's Analysis", "p");
  leg1 -> AddEntry(gr1Online, "Online Analysis" , "p");
  
  gr1All -> Draw("ap");
  gr1Online -> Draw("p");
  leg1 -> Draw();


  c1All -> cd(2);
  TGraph *gr2All = new TGraph (14, tempAll, rateAll);
  gr2All -> SetTitle("UCN Rate vs Average Isopure Helium Temperature");
  gr2All -> GetXaxis() -> SetTitle("Average Isopure Helium Temperature (K) " );
  gr2All -> GetYaxis() -> SetTitle("UCN Counts/s");
  gr2All -> SetMarkerStyle(20);
  
  gr2All -> GetXaxis() -> SetTitleSize(0.05);
  gr2All -> GetXaxis() -> SetTitleOffset(1.0);
  gr2All -> GetYaxis() -> SetTitleSize(0.05); 
  gr2All -> GetYaxis() -> SetTitleOffset(1.4);
  gr2All -> SetMarkerColor(1);

  TGraph *gr2Online = new TGraph (18, tempOnline, rateOnline);
  gr2Online -> SetMarkerStyle(3);
  gr2Online -> SetMarkerColor(8);

  
  gr2All -> Draw("ap");  
  gr2Online -> Draw("p");
  leg1 -> Draw();

  TCanvas *c2All = new TCanvas ("c2All" , "c2All" , 1200, 900);

  TGraph *gr1Overall = new TGraph (14, tempAll, ratecurAll);

  gr1Overall -> SetTitle("UCN Rate/Beam Current vs Average Isopure Helium Temperature");
  gr1Overall -> GetXaxis() -> SetTitle("Average Isopure Helium Temperature (K) " );
  gr1Overall -> GetYaxis() -> SetTitle("UCN Counts/(s*#muA)");
  gr1Overall -> SetMarkerStyle(20);
  
  gr1Overall -> GetXaxis() -> SetTitleSize(0.05);
  gr1Overall -> GetXaxis() -> SetTitleOffset(1.0);
  gr1Overall -> GetYaxis() -> SetTitleSize(0.05); 
  gr1Overall -> GetYaxis() -> SetTitleOffset(0.9);
  gr1Overall -> SetMarkerColor(1);


  TGraph *gr2Overall = new TGraph (18, tempOnline, ratecurOnline);

  gr2Overall -> SetMarkerStyle(3);
  gr2Overall -> SetMarkerColor(8);

  gr1Overall -> Draw("AP");
  gr2Overall -> Draw("p");
  leg1 -> Draw();



  TCanvas *c3All = new TCanvas ("c3All" , "c3All", 1200, 900);

  TGraph *grcurtempAll = new TGraph (14, tempAll, curAll);
  grcurtempAll -> SetTitle("Beam Current vs Average Isopure Helium Temperature");
  grcurtempAll -> GetXaxis() -> SetTitle("Average Isopure Helium Temperature (K) " );
  grcurtempAll -> GetYaxis() -> SetTitle("Beam Current(#muA)");
  grcurtempAll -> SetMarkerStyle(20);
  
  grcurtempAll -> GetXaxis() -> SetTitleSize(0.05);
  grcurtempAll -> GetXaxis() -> SetTitleOffset(1.0);
  grcurtempAll -> GetYaxis() -> SetTitleSize(0.05); 
  grcurtempAll -> GetYaxis() -> SetTitleOffset(0.9);
  grcurtempAll -> SetMarkerColor(1);

  TGraph *grcurtempOnline = new TGraph (18, tempOnline, curOnline);
  grcurtempOnline -> SetMarkerStyle (3);
  grcurtempOnline -> SetMarkerColor (8);

  grcurtempAll -> Draw("Ap");
  grcurtempOnline -> Draw("P");
  leg1 -> Draw();

    
}
