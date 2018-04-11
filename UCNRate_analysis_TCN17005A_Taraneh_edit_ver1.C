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
  

  int timestamp_bl587;
  int timestamp_bl588;
  int timestamp_bl589;
  int timestamp_bl590;
  int timestamp_bl591;
  int timestamp_bl592;
  int timestamp_bl593;

  double TSArray587 [1000000];
  double TSArray588 [1000000];
  double TSArray589 [1000000];
  double TSArray590 [1000000];
  double TSArray591 [1000000];
  double TSArray592 [1000000];
  double TSArray593 [1000000];
  

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

  curAve587 = curAve587 / boCounts587;
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

  curAve588 = curAve588 / boCounts588;
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

  curAve589 = curAve589 / boCounts589;
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

  curAve590 = curAve590 / boCounts590 ;
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

  curAve591 = curAve591 / boCounts591;
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

  curAve592 = curAve592 / boCounts592;
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

  curAve593 = curAve593/ boCounts593;
  NBins593 = max593 - min593;

  TH1* UCNrate_li6593 = new TH1F ("UCNrate_li6593" , "UCN_rate Histogram" , NBins593, min593, max593);
  
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



  // *********************
  // THE OVERALL RESULT
  //**********************

  double curAll[19] = {0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.5, 0.5, 0.5, 0.7, 0.7, 0.7, 0.9,  0.9, 1, 1, 1};
  double rateAll[19] = {141.7, 146.3, 156.9, 155.7, 461.1, 461.0, 460.7, 761.3, 765.0, 710.2, 1065.4, 1058.7, 1069.8, 1347.3, 1354.5, 1500.7, 1435.0, 1489.8}; 
    
  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);

  TGraph *grAll = new TGraph (19, curAll, rateAll);
  grAll -> SetTitle("UCN Rate vs Predicted Beam Current");
  grAll -> GetXaxis() -> SetTitle("Predicted Beam Current (#muA) " );
  grAll -> GetYaxis() -> SetTitle("UCN Counts/s");
  grAll -> SetMarkerStyle(20);
  
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> SetMarkerColor(1);
  grAll -> Draw("ap");
  //grAll -> Fit("pol1");
  
}
