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


  int timestamp_bl587;
  int timestamp_bl588;
  int timestamp_bl589;
  int timestamp_bl590;
  int timestamp_bl591;
  int timestamp_bl592;
  int timestamp_bl593;

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

  
  double beamlineEvent587 = (Double_t) bl587-> GetEntries();
  
  for(ULong64_t j=0 ; j < beamlineEvent587 ;j++) {
    bl587 -> GetEvent(j);
    //cout << timestamp_bl587 << endl;
    if (timestamp_bl587 < min587 ){
      min587 = timestamp_bl587;
    }
    if (timestamp_bl587 > max587){
      max587 = timestamp_bl587;
    }
  }


  NBins587 = max587 - min587;

  TH1* UCNrate_li6587 = new TH1F ("UCNrate_li6587" , "UCN_rate Histogram" , NBins587, min587, max587);
  
  //TH1* UCNrate_li6587= new TH1F("UCNrate_li6587", "UCN-rate Histogram",NBins587 , min587, max587);
  
  int points;
  ULong64_t eventTot587 = (Double_t) uinli6587 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot587 ; j++) {
    uinli6587 -> GetEvent(j);    
    if (tIsUCN587 > 0 && tUnixTime587 > 20e6){
      UCNrate_li6587 -> Fill(tUnixTimePrecise587);
      points++;
    }
  }

  TCanvas *c1 = new TCanvas ("c1", "c1", 1200, 900);
  UCNrate_li6587 -> Draw();
  cout << points<< endl;




  

  

}
