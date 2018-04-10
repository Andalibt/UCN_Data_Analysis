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
  double bOnTS587[1000000];
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
	//bOnTS587[boCounts587] = timestamp_bl587;
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

  cout << "*******************************************" << endl;

  
  TCanvas *c1587 = new TCanvas ("c1587", "c1587", 1200, 900);
  UCNrate_li6587 -> Draw();



  TCanvas *c2587 = new TCanvas ("c2587" , "c2587", 1200, 900);

  TGraphErrors *gr_b587 = new TGraphErrors (counts587 , TSArray587 , curArray587, 0 , 0);

  gr_b587 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b587 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b587 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)");
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
  double bOnTS588[1000000];
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
	//bOnTS588[boCounts588] = timestamp_bl588;
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

  cout << "*******************************************" << endl;

  
  TCanvas *c1588 = new TCanvas ("c1588", "c1588", 1200, 900);
  UCNrate_li6588 -> Draw();



  TCanvas *c2588 = new TCanvas ("c2588" , "c2588", 1200, 900);

  TGraphErrors *gr_b588 = new TGraphErrors (counts588 , TSArray588 , curArray588, 0 , 0);

  gr_b588 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b588 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b588 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)");
  gr_b588 -> SetMarkerStyle(20);
  
  gr_b588 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b588 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b588 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b588 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b588 -> SetMarkerColor(1);

  

  gr_b588 -> Draw("Ap");
  UCNrate_li6588 -> Draw("same");
  

  

}
