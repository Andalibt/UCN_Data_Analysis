//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17009 and TCN17009A.

// This script is for the second pass of analysis.
//
// Taraneh Andalib June 21, 2018
//****************************************************************
#include <string>
#include <fstream>

#define max 200

void StorageTime_17009_AND_17009A_ver1(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");

  TFile *fin1_60 = new TFile("./2ndpass/outputTree_17009_1muA_60sIrrad.root","READ");
  TFile *fin2_10 = new TFile("./2ndpass/outputTree_17009_2muA_10sIrrad.root","READ");
  TFile *fin2_30 = new TFile("./2ndpass/outputTree_17009_2muA_30sIrrad.root","READ");
  TFile *fin2_60 = new TFile("./2ndpass/outputTree_17009_2muA_60sIrrad.root","READ");
  TFile *fin2_120 = new TFile("./2ndpass/outputTree_17009_2muA_120sIrrad.root","READ");
  TFile *fin5_10 = new TFile("./2ndpass/outputTree_17009_5muA_10sIrrad.root","READ");
  TFile *fin5_30 = new TFile("./2ndpass/outputTree_17009_5muA_30sIrrad.root","READ");
  TFile *fin5_60 = new TFile("./2ndpass/outputTree_17009_5muA_60sIrrad.root","READ");
  TFile *fin5_120 = new TFile("./2ndpass/outputTree_17009_5muA_120sIrrad.root","READ");
  TFile *fin7_10 = new TFile("./2ndpass/outputTree_17009_7muA_10sIrrad.root","READ");
  TFile *fin7_30 = new TFile("./2ndpass/outputTree_17009_7muA_30sIrrad.root","READ");
  TFile *fin7_60 = new TFile("./2ndpass/outputTree_17009_7muA_60sIrrad.root","READ");
  TFile *fin10_10 = new TFile("./2ndpass/outputTree_17009_10muA_10sIrrad.root","READ");
  TFile *fin10_30 = new TFile("./2ndpass/outputTree_17009_10muA_30sIrrad.root","READ");


  TTree *outputTree1_60 = (TTree*) fin1_60 -> Get("cycle_info");
  TTree *outputTree2_10 = (TTree*) fin2_10 -> Get("cycle_info");
  TTree *outputTree2_30 = (TTree*) fin2_30 -> Get("cycle_info");
  TTree *outputTree2_60 = (TTree*) fin2_60 -> Get("cycle_info");
  TTree *outputTree2_120 = (TTree*) fin2_120 -> Get("cycle_info");
  TTree *outputTree5_10 = (TTree*) fin5_10 -> Get("cycle_info");
  TTree *outputTree5_30 = (TTree*) fin5_30 -> Get("cycle_info");
  TTree *outputTree5_60 = (TTree*) fin5_60 -> Get("cycle_info");
  TTree *outputTree5_120 = (TTree*) fin5_120 -> Get("cycle_info");
  TTree *outputTree7_10 = (TTree*) fin7_10 -> Get("cycle_info");
  TTree *outputTree7_30 = (TTree*) fin7_30 -> Get("cycle_info");
  TTree *outputTree7_60 = (TTree*) fin7_60 -> Get("cycle_info");
  TTree *outputTree10_10 = (TTree*) fin10_10 -> Get("cycle_info");
  TTree *outputTree10_30 = (TTree*) fin10_30 -> Get("cycle_info");


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime1_60;
  double cycleDelayTime2_10;
  double cycleDelayTime2_30;
  double cycleDelayTime2_60;
  double cycleDelayTime2_120;
  double cycleDelayTime5_10;
  double cycleDelayTime5_30;
  double cycleDelayTime5_60;
  double cycleDelayTime5_120;
  double cycleDelayTime7_10;
  double cycleDelayTime7_30;
  double cycleDelayTime7_60;
  double cycleDelayTime10_10;
  double cycleDelayTime10_30;
  

  outputTree1_60 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime1_60);
  outputTree2_10 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime2_10);
  outputTree2_30 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime2_30);
  outputTree2_60 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime2_60);
  outputTree2_120 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime2_120);
  outputTree5_10 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime5_10);
  outputTree5_30 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime5_30);
  outputTree5_60 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime5_60);
  outputTree5_120 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime5_120);
  outputTree7_10 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime7_10);
  outputTree7_30 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime7_30);
  outputTree7_60 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime7_60);
  outputTree10_10 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime10_10);
  outputTree10_30 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime10_30);

  // DELAY TIME (ARRAY)

  double delaytimeArray1_60 [max];
  double delaytimeArray2_10 [max];
  double delaytimeArray2_30 [max];
  double delaytimeArray2_60 [max];
  double delaytimeArray2_120 [max];
  double delaytimeArray5_10 [max];
  double delaytimeArray5_30 [max];
  double delaytimeArray5_60 [max];
  double delaytimeArray5_120 [max];
  double delaytimeArray7_10 [max];
  double delaytimeArray7_30 [max];
  double delaytimeArray7_60 [max];
  double delaytimeArray10_10 [max];
  double delaytimeArray10_30 [max];


  // cycle Valve Open Time
  double cycleValveOpenTime1_60;
  double cycleValveOpenTime2_10;
  double cycleValveOpenTime2_30;
  double cycleValveOpenTime2_60;
  double cycleValveOpenTime2_120;
  double cycleValveOpenTime5_10;
  double cycleValveOpenTime5_30;
  double cycleValveOpenTime5_60;
  double cycleValveOpenTime5_120;
  double cycleValveOpenTime7_10;
  double cycleValveOpenTime7_30;
  double cycleValveOpenTime7_60;
  double cycleValveOpenTime10_10;
  double cycleValveOpenTime10_30;

  outputTree1_60 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime1_60);
  outputTree2_10 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime2_10);
  outputTree2_30 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime2_30);
  outputTree2_60 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime2_60);
  outputTree2_120 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime2_120);
  outputTree5_10 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime5_10);
  outputTree5_30 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime5_30);
  outputTree5_60 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime5_60);
  outputTree5_120 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime5_120);
  outputTree7_10 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime7_10);
  outputTree7_30 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime7_30);
  outputTree7_60 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime7_60);
  outputTree10_10 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime10_10);
  outputTree10_30 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime10_30);

  

  // cycle Valve Close Time
  double cycleValveCloseTime1_60;
  double cycleValveCloseTime2_10;
  double cycleValveCloseTime2_30;
  double cycleValveCloseTime2_60;
  double cycleValveCloseTime2_120;
  double cycleValveCloseTime5_10;
  double cycleValveCloseTime5_30;
  double cycleValveCloseTime5_60;
  double cycleValveCloseTime5_120;
  double cycleValveCloseTime7_10;
  double cycleValveCloseTime7_30;
  double cycleValveCloseTime7_60;
  double cycleValveCloseTime10_10;
  double cycleValveCloseTime10_30;

  outputTree1_60 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime1_60);
  outputTree2_10 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime2_10);
  outputTree2_30 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime2_30);
  outputTree2_60 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime2_60);
  outputTree2_120 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime2_120);
  outputTree5_10 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime5_10);
  outputTree5_30 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime5_30);
  outputTree5_60 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime5_60);
  outputTree5_120 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime5_120);
  outputTree7_10 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime7_10);
  outputTree7_30 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime7_30);
  outputTree7_60 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime7_60);
  outputTree10_10 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime10_10);
  outputTree10_30 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime10_30);

  
  // CYCLE NUMBER
  int cycleNumberAll1_60;
  int cycleNumberAll2_10;
  int cycleNumberAll2_30;
  int cycleNumberAll2_60;
  int cycleNumberAll2_120;
  int cycleNumberAll5_10;
  int cycleNumberAll5_30;
  int cycleNumberAll5_60;
  int cycleNumberAll5_120;
  int cycleNumberAll7_10;
  int cycleNumberAll7_30;
  int cycleNumberAll7_60;
  int cycleNumberAll10_10;
  int cycleNumberAll10_30;

  outputTree1_60 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll1_60);
  outputTree2_10 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll2_10);
  outputTree2_30 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll2_30);
  outputTree2_60 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll2_60);
  outputTree2_120 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll2_120);
  outputTree5_10 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll5_10);
  outputTree5_30 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll5_30);
  outputTree5_60 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll5_60);
  outputTree5_120 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll5_120);
  outputTree7_10 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll7_10);
  outputTree7_30 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll7_30);
  outputTree7_60 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll7_60);
  outputTree10_10 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll10_10);
  outputTree10_30 -> SetBranchAddress ("cycleNumberAll" , &cycleNumberAll10_30);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberAllArray1_60[max];
  double cycleNumberAllArray2_10 [max];
  double cycleNumberAllArray2_30 [max];
  double cycleNumberAllArray2_60 [max];
  double cycleNumberAllArray2_120 [max];
  double cycleNumberAllArray5_10 [max];
  double cycleNumberAllArray5_30 [max];
  double cycleNumberAllArray5_60 [max];
  double cycleNumberAllArray5_120 [max];
  double cycleNumberAllArray7_10 [max];
  double cycleNumberAllArray7_30 [max];
  double cycleNumberAllArray7_60 [max];
  double cycleNumberAllArray10_10 [max];
  double cycleNumberAllArray10_30 [max];

  // Total UCN counts without background
  double UCNCountsArray1_60 [max];
  double UCNCountsArray2_10 [max];
  double UCNCountsArray2_30 [max];
  double UCNCountsArray2_60 [max];
  double UCNCountsArray2_120 [max];
  double UCNCountsArray5_10 [max];
  double UCNCountsArray5_30 [max];
  double UCNCountsArray5_60 [max];
  double UCNCountsArray5_120 [max];
  double UCNCountsArray7_10 [max];
  double UCNCountsArray7_30 [max];
  double UCNCountsArray7_60 [max];
  double UCNCountsArray10_10 [max];
  double UCNCountsArray10_30 [max];

  // Error in the total UCN counts without background
  double UCNCountsErrArray1_60 [max];
  double UCNCountsErrArray2_10 [max];
  double UCNCountsErrArray2_30 [max];
  double UCNCountsErrArray2_60 [max];
  double UCNCountsErrArray2_120[max];
  double UCNCountsErrArray5_10 [max];
  double UCNCountsErrArray5_30 [max];
  double UCNCountsErrArray5_60 [max];
  double UCNCountsErrArray5_120 [max];
  double UCNCountsErrArray7_10 [max];
  double UCNCountsErrArray7_30 [max];
  double UCNCountsErrArray7_60 [max];
  double UCNCountsErrArray10_10 [max];
  double UCNCountsErrArray10_30 [max];
  
  // THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegral1_60;
  double HistIntegral2_10;
  double HistIntegral2_30;
  double HistIntegral2_60;
  double HistIntegral2_120;
  double HistIntegral5_10;
  double HistIntegral5_30;
  double HistIntegral5_60;
  double HistIntegral5_120;
  double HistIntegral7_10;
  double HistIntegral7_30;
  double HistIntegral7_60;
  double HistIntegral10_10;
  double HistIntegral10_30;

  outputTree1_60 -> SetBranchAddress ("HistIntegral" , &HistIntegral1_60);
  outputTree2_10 -> SetBranchAddress ("HistIntegral" , &HistIntegral2_10);
  outputTree2_30 -> SetBranchAddress ("HistIntegral" , &HistIntegral2_30);
  outputTree2_60 -> SetBranchAddress ("HistIntegral" , &HistIntegral2_60);
  outputTree2_120 -> SetBranchAddress ("HistIntegral" , &HistIntegral2_120);
  outputTree5_10 -> SetBranchAddress ("HistIntegral" , &HistIntegral5_10); 
  outputTree5_30 -> SetBranchAddress ("HistIntegral" , &HistIntegral5_30);
  outputTree5_60 -> SetBranchAddress ("HistIntegral" , &HistIntegral5_60);
  outputTree5_120 -> SetBranchAddress ("HistIntegral" , &HistIntegral5_120);
  outputTree7_10 -> SetBranchAddress ("HistIntegral" , &HistIntegral7_10);
  outputTree7_30 -> SetBranchAddress ("HistIntegral" , &HistIntegral7_30);
  outputTree7_60 -> SetBranchAddress ("HistIntegral" , &HistIntegral7_60);
  outputTree10_10 -> SetBranchAddress ("HistIntegral" , &HistIntegral10_10);
  outputTree10_30 -> SetBranchAddress ("HistIntegral" , &HistIntegral10_30);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray1_60[max];
  double HistIntegralArray2_10 [max];
  double HistIntegralArray2_30 [max];
  double HistIntegralArray2_60 [max];
  double HistIntegralArray2_120 [max];
  double HistIntegralArray5_10 [max];
  double HistIntegralArray5_30 [max];
  double HistIntegralArray5_60 [max];
  double HistIntegralArray5_120 [max];
  double HistIntegralArray7_10 [max];
  double HistIntegralArray7_30 [max];
  double HistIntegralArray7_60 [max];
  double HistIntegralArray10_10 [max];
  double HistIntegralArray10_30 [max];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr1_60;
  double HistIntegralErr2_10;
  double HistIntegralErr2_30;
  double HistIntegralErr2_60;
  double HistIntegralErr2_120;
  double HistIntegralErr5_10;
  double HistIntegralErr5_30;
  double HistIntegralErr5_60;
  double HistIntegralErr5_120;
  double HistIntegralErr7_10;
  double HistIntegralErr7_30;
  double HistIntegralErr7_60;
  double HistIntegralErr10_10;
  double HistIntegralErr10_30;


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray1_60 [max];
  double HistIntegralErrArray2_10 [max];
  double HistIntegralErrArray2_30 [max];
  double HistIntegralErrArray2_60 [max];
  double HistIntegralErrArray2_120 [max];
  double HistIntegralErrArray5_10 [max];
  double HistIntegralErrArray5_30 [max];
  double HistIntegralErrArray5_60 [max];
  double HistIntegralErrArray5_120 [max];
  double HistIntegralErrArray7_10 [max];
  double HistIntegralErrArray7_30 [max];
  double HistIntegralErrArray7_60 [max];
  double HistIntegralErrArray10_10 [max];
  double HistIntegralErrArray10_30 [max];
  

  // AVERAGE TS11 DURING VALVE OPEN
  double avets11ValveOpen1_60;
  double avets11ValveOpen2_10;
  double avets11ValveOpen2_30;
  double avets11ValveOpen2_60;
  double avets11ValveOpen2_120;
  double avets11ValveOpen5_10;
  double avets11ValveOpen5_30;
  double avets11ValveOpen5_60;
  double avets11ValveOpen5_120;
  double avets11ValveOpen7_10;
  double avets11ValveOpen7_30;
  double avets11ValveOpen7_60;
  double avets11ValveOpen10_10;
  double avets11ValveOpen10_30;
  
  outputTree1_60 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen10_30);


  // AVERAGE TS11 DURING VALVE OPEN (ARRAY)
  double avets11ValveOpenArray1_60 [max];
  double avets11ValveOpenArray2_10 [max];
  double avets11ValveOpenArray2_30 [max];
  double avets11ValveOpenArray2_60 [max];
  double avets11ValveOpenArray2_120 [max];
  double avets11ValveOpenArray5_10 [max];
  double avets11ValveOpenArray5_30 [max];
  double avets11ValveOpenArray5_60 [max];
  double avets11ValveOpenArray5_120 [max];
  double avets11ValveOpenArray7_10 [max];
  double avets11ValveOpenArray7_30 [max];
  double avets11ValveOpenArray7_60 [max];
  double avets11ValveOpenArray10_10 [max];
  double avets11ValveOpenArray10_30 [max];

  
  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen1_60;
  double avets12ValveOpen2_10;
  double avets12ValveOpen2_30;
  double avets12ValveOpen2_60;
  double avets12ValveOpen2_120;
  double avets12ValveOpen5_10;
  double avets12ValveOpen5_30;
  double avets12ValveOpen5_60;
  double avets12ValveOpen5_120;
  double avets12ValveOpen7_10;
  double avets12ValveOpen7_30;
  double avets12ValveOpen7_60;
  double avets12ValveOpen10_10;
  double avets12ValveOpen10_30;
  
  outputTree1_60 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen10_30);


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray1_60 [max];
  double avets12ValveOpenArray2_10 [max];
  double avets12ValveOpenArray2_30 [max];
  double avets12ValveOpenArray2_60 [max];
  double avets12ValveOpenArray2_120 [max];
  double avets12ValveOpenArray5_10 [max];
  double avets12ValveOpenArray5_30 [max];
  double avets12ValveOpenArray5_60 [max];
  double avets12ValveOpenArray5_120 [max];
  double avets12ValveOpenArray7_10 [max];
  double avets12ValveOpenArray7_30 [max];
  double avets12ValveOpenArray7_60 [max];
  double avets12ValveOpenArray10_10 [max];
  double avets12ValveOpenArray10_30 [max];


  
  // AVERAGE TS14 DURING VALVE OPEN
  double avets14ValveOpen1_60;
  double avets14ValveOpen2_10;
  double avets14ValveOpen2_30;
  double avets14ValveOpen2_60;
  double avets14ValveOpen2_120;
  double avets14ValveOpen5_10;
  double avets14ValveOpen5_30;
  double avets14ValveOpen5_60;
  double avets14ValveOpen5_120;
  double avets14ValveOpen7_10;
  double avets14ValveOpen7_30;
  double avets14ValveOpen7_60;
  double avets14ValveOpen10_10;
  double avets14ValveOpen10_30;
  
  outputTree1_60 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen10_30);


  // AVERAGE TS14 DURING VALVE OPEN (ARRAY)
  double avets14ValveOpenArray1_60 [max];
  double avets14ValveOpenArray2_10 [max];
  double avets14ValveOpenArray2_30 [max];
  double avets14ValveOpenArray2_60 [max];
  double avets14ValveOpenArray2_120 [max];
  double avets14ValveOpenArray5_10 [max];
  double avets14ValveOpenArray5_30 [max];
  double avets14ValveOpenArray5_60 [max];
  double avets14ValveOpenArray5_120 [max];
  double avets14ValveOpenArray7_10 [max];
  double avets14ValveOpenArray7_30 [max];
  double avets14ValveOpenArray7_60 [max];
  double avets14ValveOpenArray10_10 [max];
  double avets14ValveOpenArray10_30 [max];

  
  // AVERAGE TS16 DURING VALVE OPEN
  double avets16ValveOpen1_60;
  double avets16ValveOpen2_10;
  double avets16ValveOpen2_30;
  double avets16ValveOpen2_60;
  double avets16ValveOpen2_120;
  double avets16ValveOpen5_10;
  double avets16ValveOpen5_30;
  double avets16ValveOpen5_60;
  double avets16ValveOpen5_120;
  double avets16ValveOpen7_10;
  double avets16ValveOpen7_30;
  double avets16ValveOpen7_60;
  double avets16ValveOpen10_10;
  double avets16ValveOpen10_30;
  
  outputTree1_60 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen10_30);


  // AVERAGE TS16 DURING VALVE OPEN (ARRAY)
  double avets16ValveOpenArray1_60 [max];
  double avets16ValveOpenArray2_10 [max];
  double avets16ValveOpenArray2_30 [max];
  double avets16ValveOpenArray2_60 [max];
  double avets16ValveOpenArray2_120 [max];
  double avets16ValveOpenArray5_10 [max];
  double avets16ValveOpenArray5_30 [max];
  double avets16ValveOpenArray5_60 [max];
  double avets16ValveOpenArray5_120 [max];
  double avets16ValveOpenArray7_10 [max];
  double avets16ValveOpenArray7_30 [max];
  double avets16ValveOpenArray7_60 [max];
  double avets16ValveOpenArray10_10 [max];
  double avets16ValveOpenArray10_30 [max];
  //********************************************
  
  // MAXIMUM TS11 DURING VALVE OPEN
  double maxts11ValveOpen1_60;
  double maxts11ValveOpen2_10;
  double maxts11ValveOpen2_30;
  double maxts11ValveOpen2_60;
  double maxts11ValveOpen2_120;
  double maxts11ValveOpen5_10;
  double maxts11ValveOpen5_30;
  double maxts11ValveOpen5_60;
  double maxts11ValveOpen5_120;
  double maxts11ValveOpen7_10;
  double maxts11ValveOpen7_30;
  double maxts11ValveOpen7_60;
  double maxts11ValveOpen10_10;
  double maxts11ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen10_30);
  
  
  // MINIMUM TS11 DURING VALVE OPEN
  double mints11ValveOpen1_60;
  double mints11ValveOpen2_10;
  double mints11ValveOpen2_30;
  double mints11ValveOpen2_60;
  double mints11ValveOpen2_120;
  double mints11ValveOpen5_10;
  double mints11ValveOpen5_30;
  double mints11ValveOpen5_60;
  double mints11ValveOpen5_120;
  double mints11ValveOpen7_10;
  double mints11ValveOpen7_30;
  double mints11ValveOpen7_60;
  double mints11ValveOpen10_10;
  double mints11ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen10_30);



  // TEMPERATURE ERROR BAR (ARRAY)

  double ts11ValveOpenErr1_60 [max];
  double ts11ValveOpenErr2_10 [max];
  double ts11ValveOpenErr2_10 [max];
  double ts11ValveOpenErr2_30 [max];
  double ts11ValveOpenErr2_60 [max];
  double ts11ValveOpenErr2_120 [max];
  double ts11ValveOpenErr5_10 [max];
  double ts11ValveOpenErr5_30 [max];
  double ts11ValveOpenErr5_60 [max];
  double ts11ValveOpenErr5_120 [max];
  double ts11ValveOpenErr7_10 [max];
  double ts11ValveOpenErr7_30 [max];
  double ts11ValveOpenErr7_60 [max];
  double ts11ValveOpenErr10_10 [max];
  double ts11ValveOpenErr10_30 [max];

  
  //*****************************************
 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen1_60;
  double maxts12ValveOpen2_10;
  double maxts12ValveOpen2_30;
  double maxts12ValveOpen2_60;
  double maxts12ValveOpen2_120;
  double maxts12ValveOpen5_10;
  double maxts12ValveOpen5_30;
  double maxts12ValveOpen5_60;
  double maxts12ValveOpen5_120;
  double maxts12ValveOpen7_10;
  double maxts12ValveOpen7_30;
  double maxts12ValveOpen7_60;
  double maxts12ValveOpen10_10;
  double maxts12ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen10_30);
  
  
  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen1_60;
  double mints12ValveOpen2_10;
  double mints12ValveOpen2_30;
  double mints12ValveOpen2_60;
  double mints12ValveOpen2_120;
  double mints12ValveOpen5_10;
  double mints12ValveOpen5_30;
  double mints12ValveOpen5_60;
  double mints12ValveOpen5_120;
  double mints12ValveOpen7_10;
  double mints12ValveOpen7_30;
  double mints12ValveOpen7_60;
  double mints12ValveOpen10_10;
  double mints12ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen10_30);



  // TEMPERATURE ERROR BAR (ARRAY)

  double ts12ValveOpenErr1_60 [max];
  double ts12ValveOpenErr2_10 [max];
  double ts12ValveOpenErr2_10 [max];
  double ts12ValveOpenErr2_30 [max];
  double ts12ValveOpenErr2_60 [max];
  double ts12ValveOpenErr2_120 [max];
  double ts12ValveOpenErr5_10 [max];
  double ts12ValveOpenErr5_30 [max];
  double ts12ValveOpenErr5_60 [max];
  double ts12ValveOpenErr5_120 [max];
  double ts12ValveOpenErr7_10 [max];
  double ts12ValveOpenErr7_30 [max];
  double ts12ValveOpenErr7_60 [max];
  double ts12ValveOpenErr10_10 [max];
  double ts12ValveOpenErr10_30 [max];

  //*******************************************************************

 // MAXIMUM TS14 DURING VALVE OPEN
  double maxts14ValveOpen1_60;
  double maxts14ValveOpen2_10;
  double maxts14ValveOpen2_30;
  double maxts14ValveOpen2_60;
  double maxts14ValveOpen2_120;
  double maxts14ValveOpen5_10;
  double maxts14ValveOpen5_30;
  double maxts14ValveOpen5_60;
  double maxts14ValveOpen5_120;
  double maxts14ValveOpen7_10;
  double maxts14ValveOpen7_30;
  double maxts14ValveOpen7_60;
  double maxts14ValveOpen10_10;
  double maxts14ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen10_30);
  
  
  // MINIMUM TS14 DURING VALVE OPEN
  double mints14ValveOpen1_60;
  double mints14ValveOpen2_10;
  double mints14ValveOpen2_30;
  double mints14ValveOpen2_60;
  double mints14ValveOpen2_120;
  double mints14ValveOpen5_10;
  double mints14ValveOpen5_30;
  double mints14ValveOpen5_60;
  double mints14ValveOpen5_120;
  double mints14ValveOpen7_10;
  double mints14ValveOpen7_30;
  double mints14ValveOpen7_60;
  double mints14ValveOpen10_10;
  double mints14ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen10_30);



  // TEMPERATURE ERROR BAR (ARRAY)

  double ts14ValveOpenErr1_60 [max];
  double ts14ValveOpenErr2_10 [max];
  double ts14ValveOpenErr2_10 [max];
  double ts14ValveOpenErr2_30 [max];
  double ts14ValveOpenErr2_60 [max];
  double ts14ValveOpenErr2_120 [max];
  double ts14ValveOpenErr5_10 [max];
  double ts14ValveOpenErr5_30 [max];
  double ts14ValveOpenErr5_60 [max];
  double ts14ValveOpenErr5_120 [max];
  double ts14ValveOpenErr7_10 [max];
  double ts14ValveOpenErr7_30 [max];
  double ts14ValveOpenErr7_60 [max];
  double ts14ValveOpenErr10_10 [max];
  double ts14ValveOpenErr10_30 [max];  



  //**********************************************************************************

  // MAXIMUM TS16 DURING VALVE OPEN
  double maxts16ValveOpen1_60;
  double maxts16ValveOpen2_10;
  double maxts16ValveOpen2_30;
  double maxts16ValveOpen2_60;
  double maxts16ValveOpen2_120;
  double maxts16ValveOpen5_10;
  double maxts16ValveOpen5_30;
  double maxts16ValveOpen5_60;
  double maxts16ValveOpen5_120;
  double maxts16ValveOpen7_10;
  double maxts16ValveOpen7_30;
  double maxts16ValveOpen7_60;
  double maxts16ValveOpen10_10;
  double maxts16ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen10_30);
  
  
  // MINIMUM TS16 DURING VALVE OPEN
  double mints16ValveOpen1_60;
  double mints16ValveOpen2_10;
  double mints16ValveOpen2_30;
  double mints16ValveOpen2_60;
  double mints16ValveOpen2_120;
  double mints16ValveOpen5_10;
  double mints16ValveOpen5_30;
  double mints16ValveOpen5_60;
  double mints16ValveOpen5_120;
  double mints16ValveOpen7_10;
  double mints16ValveOpen7_30;
  double mints16ValveOpen7_60;
  double mints16ValveOpen10_10;
  double mints16ValveOpen10_30;


  outputTree1_60 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen1_60);
  outputTree2_10 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen2_10);
  outputTree2_30 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen2_30);
  outputTree2_60 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen2_60);
  outputTree2_120 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen2_120);
  outputTree5_10 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen5_10);
  outputTree5_30 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen5_30);
  outputTree5_60 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen5_60);
  outputTree5_120 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen5_120);
  outputTree7_10 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen7_10);
  outputTree7_30 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen7_30);
  outputTree7_60 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen7_60);
  outputTree10_10 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen10_10);
  outputTree10_30 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen10_30);



  // TEMPERATURE ERROR BAR (ARRAY)

  double ts16ValveOpenErr1_60 [max];
  double ts16ValveOpenErr2_10 [max];
  double ts16ValveOpenErr2_10 [max];
  double ts16ValveOpenErr2_30 [max];
  double ts16ValveOpenErr2_60 [max];
  double ts16ValveOpenErr2_120 [max];
  double ts16ValveOpenErr5_10 [max];
  double ts16ValveOpenErr5_30 [max];
  double ts16ValveOpenErr5_60 [max];
  double ts16ValveOpenErr5_120 [max];
  double ts16ValveOpenErr7_10 [max];
  double ts16ValveOpenErr7_30 [max];
  double ts16ValveOpenErr7_60 [max];
  double ts16ValveOpenErr10_10 [max];
  double ts16ValveOpenErr10_30 [max];



  //***********************************************************************************

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur1_60;
  double avecur2_10;
  double avecur2_30;
  double avecur2_60;
  double avecur2_120;
  double avecur5_10;
  double avecur5_30;
  double avecur5_60;
  double avecur5_120;
  double avecur7_10;
  double avecur7_30;
  double avecur7_60;
  double avecur10_10;
  double avecur10_30;


  outputTree1_60 -> SetBranchAddress ("AVE_PRDCUR" , &avecur1_60);
  outputTree2_10 -> SetBranchAddress ("AVE_PRDCUR" , &avecur2_10);
  outputTree2_30 -> SetBranchAddress ("AVE_PRDCUR" , &avecur2_30);
  outputTree2_60 -> SetBranchAddress ("AVE_PRDCUR" , &avecur2_60);
  outputTree2_120 -> SetBranchAddress ("AVE_PRDCUR" , &avecur2_120);
  outputTree5_10 -> SetBranchAddress ("AVE_PRDCUR" , &avecur5_10);
  outputTree5_30 -> SetBranchAddress ("AVE_PRDCUR" , &avecur5_30);
  outputTree5_60 -> SetBranchAddress ("AVE_PRDCUR" , &avecur5_60);
  outputTree5_120 -> SetBranchAddress ("AVE_PRDCUR" , &avecur5_120);
  outputTree7_10 -> SetBranchAddress ("AVE_PRDCUR" , &avecur7_10);
  outputTree7_30 -> SetBranchAddress ("AVE_PRDCUR" , &avecur7_30);
  outputTree7_60 -> SetBranchAddress ("AVE_PRDCUR" , &avecur7_60); 
  outputTree10_10 -> SetBranchAddress ("AVE_PRDCUR" , &avecur10_10);
  outputTree10_30 -> SetBranchAddress ("AVE_PRDCUR" , &avecur10_30);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray1_60 [max];
  double avecurArray2_10 [max];
  double avecurArray2_30 [max];
  double avecurArray2_60 [max];
  double avecurArray2_120 [max];
  double avecurArray5_10 [max];
  double avecurArray5_30 [max];
  double avecurArray5_60 [max];
  double avecurArray5_120 [max];
  double avecurArray7_10 [max];
  double avecurArray7_30 [max];
  double avecurArray7_60 [max];
  double avecurArray10_10 [max];
  double avecurArray10_30 [max];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur1_60;
  double maxcur2_10;
  double maxcur2_30;
  double maxcur2_60;
  double maxcur2_120;
  double maxcur5_10;
  double maxcur5_30;
  double maxcur5_60;
  double maxcur5_120;
  double maxcur7_10;
  double maxcur7_30;
  double maxcur7_60;
  double maxcur10_10;
  double maxcur10_30;

  outputTree1_60 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur1_60);
  outputTree2_10 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur2_10);
  outputTree2_30 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur2_30);
  outputTree2_60 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur2_60);
  outputTree2_120 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur2_120);
  outputTree5_10 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur5_10);
  outputTree5_30 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur5_30);
  outputTree5_60 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur5_60);
  outputTree5_120 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur5_120);
  outputTree7_10 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur7_10);
  outputTree7_30 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur7_30);
  outputTree7_60 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur7_60);
  outputTree10_10 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur10_10);
  outputTree10_30 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur10_30);





  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur1_60;
  double mincur2_10;
  double mincur2_30;
  double mincur2_60;
  double mincur2_120;
  double mincur5_10;
  double mincur5_30;
  double mincur5_60;
  double mincur5_120;
  double mincur7_10;
  double mincur7_30;
  double mincur7_60;
  double mincur10_10;
  double mincur10_30;


  outputTree1_60 -> SetBranchAddress ("MIN_PRDCUR" , &mincur1_60);
  outputTree2_10 -> SetBranchAddress ("MIN_PRDCUR" , &mincur2_10);
  outputTree2_30 -> SetBranchAddress ("MIN_PRDCUR" , &mincur2_30);
  outputTree2_60 -> SetBranchAddress ("MIN_PRDCUR" , &mincur2_60);
  outputTree2_120 -> SetBranchAddress ("MIN_PRDCUR" , &mincur2_120);
  outputTree5_10 -> SetBranchAddress ("MIN_PRDCUR" , &mincur5_10);
  outputTree5_30 -> SetBranchAddress ("MIN_PRDCUR" , &mincur5_30);
  outputTree5_60 -> SetBranchAddress ("MIN_PRDCUR" , &mincur5_60);
  outputTree5_120 -> SetBranchAddress ("MIN_PRDCUR" , &mincur5_120);
  outputTree7_10 -> SetBranchAddress ("MIN_PRDCUR" , &mincur7_10);
  outputTree7_30 -> SetBranchAddress ("MIN_PRDCUR" , &mincur7_30);
  outputTree7_60 -> SetBranchAddress ("MIN_PRDCUR" , &mincur7_60);
  outputTree10_10 -> SetBranchAddress ("MIN_PRDCUR" , &mincur10_10);
  outputTree10_30 -> SetBranchAddress ("MIN_PRDCUR" , &mincur10_30);

  // ERROR (MAX - MIN)/2 OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray1_60 [max];
  double ErrcurArray2_10 [max];
  double ErrcurArray2_30 [max];
  double ErrcurArray2_60 [max];
  double ErrcurArray2_120 [max];
  double ErrcurArray5_10 [max];
  double ErrcurArray5_30 [max];
  double ErrcurArray5_60 [max];
  double ErrcurArray5_120 [max];
  double ErrcurArray7_10 [max];
  double ErrcurArray7_30 [max];
  double ErrcurArray7_60 [max];
  double ErrcurArray10_10 [max];
  double ErrcurArray10_30 [max];
 
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double BASELINERATE1_60;
  double BASELINERATE2_10;
  double BASELINERATE2_30;
  double BASELINERATE2_60;
  double BASELINERATE2_120;
  double BASELINERATE5_10;
  double BASELINERATE5_30;
  double BASELINERATE5_60;
  double BASELINERATE5_120;
  double BASELINERATE7_10;
  double BASELINERATE7_30;
  double BASELINERATE7_60;
  double BASELINERATE10_10;
  double BASELINERATE10_30;

  outputTree1_60 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE1_60);
  outputTree2_10 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE2_10);
  outputTree2_30 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE2_30);
  outputTree2_60 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE2_60);
  outputTree2_120 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE2_120);
  outputTree5_10 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE5_10);
  outputTree5_30 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE5_30);
  outputTree5_60 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE5_60);
  outputTree5_120 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE5_120);
  outputTree7_10 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE7_10);
  outputTree7_30 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE7_30);
  outputTree7_60 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE7_60);
  outputTree10_10 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE10_10);
  outputTree10_30 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE10_30);

  
  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage1_60;
  double storage2_10;
  double storage2_30;
  double storage2_60;
  double storage2_120;
  double storage5_10;
  double storage5_30;
  double storage5_60;
  double storage5_120;
  double storage7_10;
  double storage7_30;
  double storage7_60;
  double storage10_10;
  double storage10_30;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr1_60;
  double storageErr2_10;
  double storageErr2_30;
  double storageErr2_60;
  double storageErr2_120;
  double storageErr5_10;
  double storageErr5_30;
  double storageErr5_60;
  double storageErr5_120;
  double storageErr7_10;
  double storageErr7_30;
  double storageErr7_60;
  double storageErr10_10;
  double storageErr10_30;

  // NUMBER OF COUNTS IN EACH LOOP
  int counts_1_60 = 0;
  int counts_2_10 = 0;
  int counts_2_30 = 0;
  int counts_2_60 = 0;
  int counts_2_120 = 0;
  int counts_5_10 = 0;
  int counts_5_30 = 0;
  int counts_5_60 = 0;
  int counts_5_120 = 0;
  int counts_7_10 = 0;
  int counts_7_30 = 0;
  int counts_7_60 = 0;
  int counts_10_10 = 0;
  int counts_10_30 = 0;

  
  // BECAUSE THE ERROR BARS FOR TGRAPHERRORS ARE DOUBLED I HAVE TO DIVIDE THE ERRORS IN HALF


  // ****************************
  // 1 muA , 60 s irrad
  // ***************************
 ULong64_t events1_60;
  events1_60 = (Double_t)outputTree1_60 -> GetEntries();

  for (ULong64_t j = 0 ; j < events1_60 ; j++){
    outputTree1_60 -> GetEvent(j);
    
    UCNCountsArray1_60[counts_1_60] = HistIntegral1_60 - BASELINERATE1_60*(cycleValveCloseTime1_60 - cycleValveOpenTime1_60);
    UCNCountsErrArray1_60[counts_1_60] = sqrt(UCNCountsArray1_60[counts_1_60]);
    HistIntegralArray1_60[counts_1_60] = HistIntegral1_60;
    HistIntegralErrArray1_60[counts_1_60] = sqrt (HistIntegral1_60);
    
    avets11ValveOpenArray1_60[counts_1_60] = avets11ValveOpen1_60;
    avets12ValveOpenArray1_60[counts_1_60] = avets12ValveOpen1_60;
    avets14ValveOpenArray1_60[counts_1_60] = avets14ValveOpen1_60;
    avets16ValveOpenArray1_60[counts_1_60] = avets16ValveOpen1_60;
    ts11ValveOpenErr1_60[counts_1_60] = (maxts11ValveOpen1_60 - mints11ValveOpen1_60)/2;
    ts12ValveOpenErr1_60[counts_1_60] = (maxts12ValveOpen1_60 - mints12ValveOpen1_60)/2;
    ts14ValveOpenErr1_60[counts_1_60] = (maxts14ValveOpen1_60 - mints14ValveOpen1_60)/2;
    ts16ValveOpenErr1_60[counts_1_60] = (maxts16ValveOpen1_60 - mints16ValveOpen1_60)/2;
	    
    avecurArray1_60[counts_1_60] = avecur1_60;
    ErrcurArray1_60[counts_1_60] = (maxcur1_60 - mincur1_60)/2;
    
    delaytimeArray1_60[counts_1_60] = cycleDelayTime1_60;
    cycleNumberAllArray1_60[counts_1_60] = cycleNumberAll1_60;
    
    counts_1_60++;
  }

  // ****************************
  // 2.5 muA , 10 s irrad
  // ***************************
  ULong64_t events2_10;
  events2_10 = (Double_t)outputTree2_10 -> GetEntries();

  for (ULong64_t j = 0 ; j < events2_10 ; j++){
    outputTree2_10 -> GetEvent(j);
    
    UCNCountsArray2_10[counts_2_10] = HistIntegral2_10 - BASELINERATE2_10*(cycleValveCloseTime2_10 - cycleValveOpenTime2_10);
    UCNCountsErrArray2_10[counts_2_10] = sqrt(UCNCountsArray2_10[counts_2_10]);
    HistIntegralArray2_10[counts_2_10] = HistIntegral2_10;
    HistIntegralErrArray2_10[counts_2_10] = sqrt (HistIntegral2_10);
    
    avets11ValveOpenArray2_10[counts_2_10] = avets11ValveOpen2_10;
    avets12ValveOpenArray2_10[counts_2_10] = avets12ValveOpen2_10;
    avets14ValveOpenArray2_10[counts_2_10] = avets14ValveOpen2_10;
    avets16ValveOpenArray2_10[counts_2_10] = avets16ValveOpen2_10;
    ts11ValveOpenErr2_10[counts_2_10] = (maxts11ValveOpen2_10 - mints11ValveOpen2_10)/2;
    ts12ValveOpenErr2_10[counts_2_10] = (maxts12ValveOpen2_10 - mints12ValveOpen2_10)/2;
    ts14ValveOpenErr2_10[counts_2_10] = (maxts14ValveOpen2_10 - mints14ValveOpen2_10)/2;
    ts16ValveOpenErr2_10[counts_2_10] = (maxts16ValveOpen2_10 - mints16ValveOpen2_10)/2;
	    
    avecurArray2_10[counts_2_10] = avecur2_10;
    ErrcurArray2_10[counts_2_10] = (maxcur2_10 - mincur2_10)/2;
    
    delaytimeArray2_10[counts_2_10] = cycleDelayTime2_10;
    cycleNumberAllArray2_10[counts_2_10] = cycleNumberAll2_10;
    
    counts_2_10++;
  }

  // ****************************
  // 2.5 muA , 30 s irrad
  // ***************************
  ULong64_t events2_30;
  events2_30 = (Double_t)outputTree2_30 -> GetEntries();

  for (ULong64_t j = 0 ; j < events2_30 ; j++){
    outputTree2_30 -> GetEvent(j);
    
    UCNCountsArray2_30[counts_2_30] = HistIntegral2_30 - BASELINERATE2_30*(cycleValveCloseTime2_30 - cycleValveOpenTime2_30);
    UCNCountsErrArray2_30[counts_2_30] = sqrt(UCNCountsArray2_30[counts_2_30]);
    HistIntegralArray2_30[counts_2_30] = HistIntegral2_30;
    HistIntegralErrArray2_30[counts_2_30] = sqrt (HistIntegral2_30);
    
    avets11ValveOpenArray2_30[counts_2_30] = avets11ValveOpen2_30;
    avets12ValveOpenArray2_30[counts_2_30] = avets12ValveOpen2_30;
    avets14ValveOpenArray2_30[counts_2_30] = avets14ValveOpen2_30;
    avets16ValveOpenArray2_30[counts_2_30] = avets16ValveOpen2_30;
    ts11ValveOpenErr2_30[counts_2_30] = (maxts11ValveOpen2_30 - mints11ValveOpen2_30)/2;
    ts12ValveOpenErr2_30[counts_2_30] = (maxts12ValveOpen2_30 - mints12ValveOpen2_30)/2;
    ts14ValveOpenErr2_30[counts_2_30] = (maxts14ValveOpen2_30 - mints14ValveOpen2_30)/2;
    ts16ValveOpenErr2_30[counts_2_30] = (maxts16ValveOpen2_30 - mints16ValveOpen2_30)/2;
	    
    avecurArray2_30[counts_2_30] = avecur2_30;
    ErrcurArray2_30[counts_2_30] = (maxcur2_30 - mincur2_30)/2;
    
    delaytimeArray2_30[counts_2_30] = cycleDelayTime2_30;
    cycleNumberAllArray2_30[counts_2_30] = cycleNumberAll2_30;
    
    counts_2_30++;
  }

  // ****************************
  // 2.5 muA , 60 s irrad
  // ***************************
  ULong64_t events2_60;
  events2_60 = (Double_t)outputTree2_60 -> GetEntries();

  for (ULong64_t j = 0 ; j < events2_60 ; j++){
    outputTree2_60 -> GetEvent(j);
    if (j == 2 )
      continue;
    
    UCNCountsArray2_60[counts_2_60] = HistIntegral2_60 - BASELINERATE2_60*(cycleValveCloseTime2_60 - cycleValveOpenTime2_60);
    UCNCountsErrArray2_60[counts_2_60] = sqrt(UCNCountsArray2_60[counts_2_60]);
    HistIntegralArray2_60[counts_2_60] = HistIntegral2_60;
    HistIntegralErrArray2_60[counts_2_60] = sqrt (HistIntegral2_60);
    
    avets11ValveOpenArray2_60[counts_2_60] = avets11ValveOpen2_60;
    avets12ValveOpenArray2_60[counts_2_60] = avets12ValveOpen2_60;
    avets14ValveOpenArray2_60[counts_2_60] = avets14ValveOpen2_60;
    avets16ValveOpenArray2_60[counts_2_60] = avets16ValveOpen2_60;
    ts11ValveOpenErr2_60[counts_2_60] = (maxts11ValveOpen2_60 - mints11ValveOpen2_60)/2;
    ts12ValveOpenErr2_60[counts_2_60] = (maxts12ValveOpen2_60 - mints12ValveOpen2_60)/2;
    ts14ValveOpenErr2_60[counts_2_60] = (maxts14ValveOpen2_60 - mints14ValveOpen2_60)/2;
    ts16ValveOpenErr2_60[counts_2_60] = (maxts16ValveOpen2_60 - mints16ValveOpen2_60)/2;
	    
    avecurArray2_60[counts_2_60] = avecur2_60;
    ErrcurArray2_60[counts_2_60] = (maxcur2_60 - mincur2_60)/2;
    
    delaytimeArray2_60[counts_2_60] = cycleDelayTime2_60;
    cycleNumberAllArray2_60[counts_2_60] = cycleNumberAll2_60;
    
    counts_2_60++;
  }

  // ****************************
  // 2.5 muA , 120 s irrad
  // ***************************
  ULong64_t events2_120;
  events2_120 = (Double_t)outputTree2_120 -> GetEntries();

  for (ULong64_t j = 0 ; j < events2_120 ; j++){
    outputTree2_120 -> GetEvent(j);
    
    UCNCountsArray2_120[counts_2_120] = HistIntegral2_120 - BASELINERATE2_120*(cycleValveCloseTime2_120 - cycleValveOpenTime2_120);
    UCNCountsErrArray2_120[counts_2_120] = sqrt(UCNCountsArray2_120[counts_2_120]);
    HistIntegralArray2_120[counts_2_120] = HistIntegral2_120;
    HistIntegralErrArray2_120[counts_2_120] = sqrt (HistIntegral2_120);
    
    avets11ValveOpenArray2_120[counts_2_120] = avets11ValveOpen2_120;
    avets12ValveOpenArray2_120[counts_2_120] = avets12ValveOpen2_120;
    avets14ValveOpenArray2_120[counts_2_120] = avets14ValveOpen2_120;
    avets16ValveOpenArray2_120[counts_2_120] = avets16ValveOpen2_120;
    ts11ValveOpenErr2_120[counts_2_120] = (maxts11ValveOpen2_120 - mints11ValveOpen2_120)/2;
    ts12ValveOpenErr2_120[counts_2_120] = (maxts12ValveOpen2_120 - mints12ValveOpen2_120)/2;
    ts14ValveOpenErr2_120[counts_2_120] = (maxts14ValveOpen2_120 - mints14ValveOpen2_120)/2;
    ts16ValveOpenErr2_120[counts_2_120] = (maxts16ValveOpen2_120 - mints16ValveOpen2_120)/2;
	    
    avecurArray2_120[counts_2_120] = avecur2_120;
    ErrcurArray2_120[counts_2_120] = (maxcur2_120 - mincur2_120)/2;
    
    delaytimeArray2_120[counts_2_120] = cycleDelayTime2_120;
    cycleNumberAllArray2_120[counts_2_120] = cycleNumberAll2_120;
    
    counts_2_120++;
  }

  
  // ****************************
  // 5 muA , 10 s irrad
  // *************************
  ULong64_t events5_10;
  events5_10 = (Double_t)outputTree5_10 -> GetEntries();

  for (ULong64_t j = 0 ; j < events5_10 ; j++){
    outputTree5_10 -> GetEvent(j);
    if (j==7)
      continue;
    
    UCNCountsArray5_10[counts_5_10] = HistIntegral5_10 - BASELINERATE5_10*(cycleValveCloseTime5_10 - cycleValveOpenTime5_10);
    UCNCountsErrArray5_10[counts_5_10] = sqrt(UCNCountsArray5_10[counts_5_10]);
    HistIntegralArray5_10[counts_5_10] = HistIntegral5_10;
    HistIntegralErrArray5_10[counts_5_10] = sqrt (HistIntegral5_10);
    
    avets11ValveOpenArray5_10[counts_5_10] = avets11ValveOpen5_10;
    avets12ValveOpenArray5_10[counts_5_10] = avets12ValveOpen5_10;
    avets14ValveOpenArray5_10[counts_5_10] = avets14ValveOpen5_10;
    avets16ValveOpenArray5_10[counts_5_10] = avets16ValveOpen5_10;
    ts11ValveOpenErr5_10[counts_5_10] = (maxts11ValveOpen5_10 - mints11ValveOpen5_10)/2;
    ts12ValveOpenErr5_10[counts_5_10] = (maxts12ValveOpen5_10 - mints12ValveOpen5_10)/2;
    ts14ValveOpenErr5_10[counts_5_10] = (maxts14ValveOpen5_10 - mints14ValveOpen5_10)/2;
    ts16ValveOpenErr5_10[counts_5_10] = (maxts16ValveOpen5_10 - mints16ValveOpen5_10)/2;
	    
    avecurArray5_10[counts_5_10] = avecur5_10;
    ErrcurArray5_10[counts_5_10] = (maxcur5_10 - mincur5_10)/2;
    
    delaytimeArray5_10[counts_5_10] = cycleDelayTime5_10;
    cycleNumberAllArray5_10[counts_5_10] = cycleNumberAll5_10;
    
    counts_5_10++;
  }

  // ****************************
  // 5 muA , 30 s irrad
  // *************************
  ULong64_t events5_30;
  events5_30 = (Double_t)outputTree5_30 -> GetEntries();

  for (ULong64_t j = 0 ; j < events5_30 ; j++){
    outputTree5_30 -> GetEvent(j);
    if (j==1)
      continue;
    
    UCNCountsArray5_30[counts_5_30] = HistIntegral5_30 - BASELINERATE5_30*(cycleValveCloseTime5_30 - cycleValveOpenTime5_30);
    UCNCountsErrArray5_30[counts_5_30] = sqrt(UCNCountsArray5_30[counts_5_30]);
    HistIntegralArray5_30[counts_5_30] = HistIntegral5_30;
    HistIntegralErrArray5_30[counts_5_30] = sqrt (HistIntegral5_30);
    
    avets11ValveOpenArray5_30[counts_5_30] = avets11ValveOpen5_30;
    avets12ValveOpenArray5_30[counts_5_30] = avets12ValveOpen5_30;
    avets14ValveOpenArray5_30[counts_5_30] = avets14ValveOpen5_30;
    avets16ValveOpenArray5_30[counts_5_30] = avets16ValveOpen5_30;
    ts11ValveOpenErr5_30[counts_5_30] = (maxts11ValveOpen5_30 - mints11ValveOpen5_30)/2;
    ts12ValveOpenErr5_30[counts_5_30] = (maxts12ValveOpen5_30 - mints12ValveOpen5_30)/2;
    ts14ValveOpenErr5_30[counts_5_30] = (maxts14ValveOpen5_30 - mints14ValveOpen5_30)/2;
    ts16ValveOpenErr5_30[counts_5_30] = (maxts16ValveOpen5_30 - mints16ValveOpen5_30)/2;
	    
    avecurArray5_30[counts_5_30] = avecur5_30;
    ErrcurArray5_30[counts_5_30] = (maxcur5_30 - mincur5_30)/2;
    
    delaytimeArray5_30[counts_5_30] = cycleDelayTime5_30;
    cycleNumberAllArray5_30[counts_5_30] = cycleNumberAll5_30;
    
    counts_5_30++;
  }

  // ****************************
  // 5 muA , 60 s irrad
  // ***************************
  ULong64_t events5_60;
  events5_60 = (Double_t)outputTree5_60 -> GetEntries();

  for (ULong64_t j = 0 ; j < events5_60 ; j++){
    outputTree5_60 -> GetEvent(j);
    
    UCNCountsArray5_60[counts_5_60] = HistIntegral5_60 - BASELINERATE5_60*(cycleValveCloseTime5_60 - cycleValveOpenTime5_60);
    UCNCountsErrArray5_60[counts_5_60] = sqrt(UCNCountsArray5_60[counts_5_60]);
    HistIntegralArray5_60[counts_5_60] = HistIntegral5_60;
    HistIntegralErrArray5_60[counts_5_60] = sqrt (HistIntegral5_60);
    
    avets11ValveOpenArray5_60[counts_5_60] = avets11ValveOpen5_60;
    avets12ValveOpenArray5_60[counts_5_60] = avets12ValveOpen5_60;
    avets14ValveOpenArray5_60[counts_5_60] = avets14ValveOpen5_60;
    avets16ValveOpenArray5_60[counts_5_60] = avets16ValveOpen5_60;
    ts11ValveOpenErr5_60[counts_5_60] = (maxts11ValveOpen5_60 - mints11ValveOpen5_60)/2;
    ts12ValveOpenErr5_60[counts_5_60] = (maxts12ValveOpen5_60 - mints12ValveOpen5_60)/2;
    ts14ValveOpenErr5_60[counts_5_60] = (maxts14ValveOpen5_60 - mints14ValveOpen5_60)/2;
    ts16ValveOpenErr5_60[counts_5_60] = (maxts16ValveOpen5_60 - mints16ValveOpen5_60)/2;
	    
    avecurArray5_60[counts_5_60] = avecur5_60;
    ErrcurArray5_60[counts_5_60] = (maxcur5_60 - mincur5_60)/2;
    
    delaytimeArray5_60[counts_5_60] = cycleDelayTime5_60;
    cycleNumberAllArray5_60[counts_5_60] = cycleNumberAll5_60;
    
    counts_5_60++;
  }

  // ****************************
  // 5 muA , 120 s irrad
  // ***************************
 ULong64_t events5_120;
  events5_120 = (Double_t)outputTree5_120 -> GetEntries();

  for (ULong64_t j = 0 ; j < events5_120 ; j++){
    outputTree5_120 -> GetEvent(j);
    
    UCNCountsArray5_120[counts_5_120] = HistIntegral5_120 - BASELINERATE5_120*(cycleValveCloseTime5_120 - cycleValveOpenTime5_120);
    UCNCountsErrArray5_120[counts_5_120] = sqrt(UCNCountsArray5_120[counts_5_120]);
    HistIntegralArray5_120[counts_5_120] = HistIntegral5_120;
    HistIntegralErrArray5_120[counts_5_120] = sqrt (HistIntegral5_120);
    
    avets11ValveOpenArray5_120[counts_5_120] = avets11ValveOpen5_120;
    avets12ValveOpenArray5_120[counts_5_120] = avets12ValveOpen5_120;
    avets14ValveOpenArray5_120[counts_5_120] = avets14ValveOpen5_120;
    avets16ValveOpenArray5_120[counts_5_120] = avets16ValveOpen5_120;
    ts11ValveOpenErr5_120[counts_5_120] = (maxts11ValveOpen5_120 - mints11ValveOpen5_120)/2;
    ts12ValveOpenErr5_120[counts_5_120] = (maxts12ValveOpen5_120 - mints12ValveOpen5_120)/2;
    ts14ValveOpenErr5_120[counts_5_120] = (maxts14ValveOpen5_120 - mints14ValveOpen5_120)/2;
    ts16ValveOpenErr5_120[counts_5_120] = (maxts16ValveOpen5_120 - mints16ValveOpen5_120)/2;
	    
    avecurArray5_120[counts_5_120] = avecur5_120;
    ErrcurArray5_120[counts_5_120] = (maxcur5_120 - mincur5_120)/2;
    
    delaytimeArray5_120[counts_5_120] = cycleDelayTime5_120;
    cycleNumberAllArray5_120[counts_5_120] = cycleNumberAll5_120;
    
    counts_5_120++;
  }

  // ****************************
  // 7.1 muA , 10 s irrad
  // ***************************
 ULong64_t events7_10;
  events7_10 = (Double_t)outputTree7_10 -> GetEntries();

  for (ULong64_t j = 0 ; j < events7_10 ; j++){
    outputTree7_10 -> GetEvent(j);
    if (j == 3)
      continue;
    //cout << BASELINERATE7_10 << " " << cycleDelayTime7_10 << endl;
    UCNCountsArray7_10[counts_7_10] = HistIntegral7_10 - BASELINERATE7_10*(cycleValveCloseTime7_10 - cycleValveOpenTime7_10);
    UCNCountsErrArray7_10[counts_7_10] = sqrt(UCNCountsArray7_10[counts_7_10]);
    HistIntegralArray7_10[counts_7_10] = HistIntegral7_10;
    HistIntegralErrArray7_10[counts_7_10] = sqrt (HistIntegral7_10);
    
    avets11ValveOpenArray7_10[counts_7_10] = avets11ValveOpen7_10;
    avets12ValveOpenArray7_10[counts_7_10] = avets12ValveOpen7_10;
    avets14ValveOpenArray7_10[counts_7_10] = avets14ValveOpen7_10;
    avets16ValveOpenArray7_10[counts_7_10] = avets16ValveOpen7_10;
    ts11ValveOpenErr7_10[counts_7_10] = (maxts11ValveOpen7_10 - mints11ValveOpen7_10)/2;
    ts12ValveOpenErr7_10[counts_7_10] = (maxts12ValveOpen7_10 - mints12ValveOpen7_10)/2;
    ts14ValveOpenErr7_10[counts_7_10] = (maxts14ValveOpen7_10 - mints14ValveOpen7_10)/2;
    ts16ValveOpenErr7_10[counts_7_10] = (maxts16ValveOpen7_10 - mints16ValveOpen7_10)/2;
	    
    avecurArray7_10[counts_7_10] = avecur7_10;
    ErrcurArray7_10[counts_7_10] = (maxcur7_10 - mincur7_10)/2;
    
    delaytimeArray7_10[counts_7_10] = cycleDelayTime7_10;
    cycleNumberAllArray7_10[counts_7_10] = cycleNumberAll7_10;
    
    counts_7_10++;
  }
  //break;
  // ****************************
  // 7.1 muA , 30 s irrad
  // ***************************
 ULong64_t events7_30;
  events7_30 = (Double_t)outputTree7_30 -> GetEntries();

  for (ULong64_t j = 0 ; j < events7_30 ; j++){
    outputTree7_30 -> GetEvent(j);
    
    UCNCountsArray7_30[counts_7_30] = HistIntegral7_30 - BASELINERATE7_30*(cycleValveCloseTime7_30 - cycleValveOpenTime7_30);
    UCNCountsErrArray7_30[counts_7_30] = sqrt(UCNCountsArray7_30[counts_7_30]);
    HistIntegralArray7_30[counts_7_30] = HistIntegral7_30;
    HistIntegralErrArray7_30[counts_7_30] = sqrt (HistIntegral7_30);
    
    avets11ValveOpenArray7_30[counts_7_30] = avets11ValveOpen7_30;
    avets12ValveOpenArray7_30[counts_7_30] = avets12ValveOpen7_30;
    avets14ValveOpenArray7_30[counts_7_30] = avets14ValveOpen7_30;
    avets16ValveOpenArray7_30[counts_7_30] = avets16ValveOpen7_30;
    ts11ValveOpenErr7_30[counts_7_30] = (maxts11ValveOpen7_30 - mints11ValveOpen7_30)/2;
    ts12ValveOpenErr7_30[counts_7_30] = (maxts12ValveOpen7_30 - mints12ValveOpen7_30)/2;
    ts14ValveOpenErr7_30[counts_7_30] = (maxts14ValveOpen7_30 - mints14ValveOpen7_30)/2;
    ts16ValveOpenErr7_30[counts_7_30] = (maxts16ValveOpen7_30 - mints16ValveOpen7_30)/2;
	    
    avecurArray7_30[counts_7_30] = avecur7_30;
    ErrcurArray7_30[counts_7_30] = (maxcur7_30 - mincur7_30)/2;
    
    delaytimeArray7_30[counts_7_30] = cycleDelayTime7_30;
    cycleNumberAllArray7_30[counts_7_30] = cycleNumberAll7_30;
    
    counts_7_30++;
  }

  // ****************************
  // 7.1 muA , 60 s irrad
  // ***************************
 ULong64_t events7_60;
  events7_60 = (Double_t)outputTree7_60 -> GetEntries();

  for (ULong64_t j = 0 ; j < events7_60 ; j++){
    outputTree7_60 -> GetEvent(j);
    
    UCNCountsArray7_60[counts_7_60] = HistIntegral7_60 - BASELINERATE7_60*(cycleValveCloseTime7_60 - cycleValveOpenTime7_60);
    UCNCountsErrArray7_60[counts_7_60] = sqrt(UCNCountsArray7_60[counts_7_60]);
    HistIntegralArray7_60[counts_7_60] = HistIntegral7_60;
    HistIntegralErrArray7_60[counts_7_60] = sqrt (HistIntegral7_60);
    
    avets11ValveOpenArray7_60[counts_7_60] = avets11ValveOpen7_60;
    avets12ValveOpenArray7_60[counts_7_60] = avets12ValveOpen7_60;
    avets14ValveOpenArray7_60[counts_7_60] = avets14ValveOpen7_60;
    avets16ValveOpenArray7_60[counts_7_60] = avets16ValveOpen7_60;
    ts11ValveOpenErr7_60[counts_7_60] = (maxts11ValveOpen7_60 - mints11ValveOpen7_60)/2;
    ts12ValveOpenErr7_60[counts_7_60] = (maxts12ValveOpen7_60 - mints12ValveOpen7_60)/2;
    ts14ValveOpenErr7_60[counts_7_60] = (maxts14ValveOpen7_60 - mints14ValveOpen7_60)/2;
    ts16ValveOpenErr7_60[counts_7_60] = (maxts16ValveOpen7_60 - mints16ValveOpen7_60)/2;
	    
    avecurArray7_60[counts_7_60] = avecur7_60;
    ErrcurArray7_60[counts_7_60] = (maxcur7_60 - mincur7_60)/2;
    
    delaytimeArray7_60[counts_7_60] = cycleDelayTime7_60;
    cycleNumberAllArray7_60[counts_7_60] = cycleNumberAll7_60;
    
    counts_7_60++;
  }

  // ****************************
  // 10 muA , 10 s irrad
  // ***************************
 ULong64_t events10_10;
  events10_10 = (Double_t)outputTree10_10 -> GetEntries();

  for (ULong64_t j = 0 ; j < events10_10 ; j++){
    outputTree10_10 -> GetEvent(j);
    if (j==1 || j ==2|| j == 5)
      continue;
    
    UCNCountsArray10_10[counts_10_10] = HistIntegral10_10 - BASELINERATE10_10*(cycleValveCloseTime10_10 - cycleValveOpenTime10_10);
    UCNCountsErrArray10_10[counts_10_10] = sqrt(UCNCountsArray10_10[counts_10_10]);
    HistIntegralArray10_10[counts_10_10] = HistIntegral10_10;
    HistIntegralErrArray10_10[counts_10_10] = sqrt (HistIntegral10_10);
    
    avets11ValveOpenArray10_10[counts_10_10] = avets11ValveOpen10_10;
    avets12ValveOpenArray10_10[counts_10_10] = avets12ValveOpen10_10;
    avets14ValveOpenArray10_10[counts_10_10] = avets14ValveOpen10_10;
    avets16ValveOpenArray10_10[counts_10_10] = avets16ValveOpen10_10;
    ts11ValveOpenErr10_10[counts_10_10] = (maxts11ValveOpen10_10 - mints11ValveOpen10_10)/2;
    ts12ValveOpenErr10_10[counts_10_10] = (maxts12ValveOpen10_10 - mints12ValveOpen10_10)/2;
    ts14ValveOpenErr10_10[counts_10_10] = (maxts14ValveOpen10_10 - mints14ValveOpen10_10)/2;
    ts16ValveOpenErr10_10[counts_10_10] = (maxts16ValveOpen10_10 - mints16ValveOpen10_10)/2;
	    
    avecurArray10_10[counts_10_10] = avecur10_10;
    ErrcurArray10_10[counts_10_10] = (maxcur10_10 - mincur10_10)/2;
    
    delaytimeArray10_10[counts_10_10] = cycleDelayTime10_10;
    cycleNumberAllArray10_10[counts_10_10] = cycleNumberAll10_10;
    
    counts_10_10++;
  }

  // ****************************
  // 10 muA , 30 s irrad
  // ***************************
 ULong64_t events10_30;
  events10_30 = (Double_t)outputTree10_30 -> GetEntries();

  for (ULong64_t j = 0 ; j < events10_30 ; j++){
    outputTree10_30 -> GetEvent(j);
    
    UCNCountsArray10_30[counts_10_30] = HistIntegral10_30 - BASELINERATE10_30*(cycleValveCloseTime10_30 - cycleValveOpenTime10_30);
    UCNCountsErrArray10_30[counts_10_30] = sqrt(UCNCountsArray10_30[counts_10_30]);
    HistIntegralArray10_30[counts_10_30] = HistIntegral10_30;
    HistIntegralErrArray10_30[counts_10_30] = sqrt (HistIntegral10_30);
    
    avets11ValveOpenArray10_30[counts_10_30] = avets11ValveOpen10_30;
    avets12ValveOpenArray10_30[counts_10_30] = avets12ValveOpen10_30;
    avets14ValveOpenArray10_30[counts_10_30] = avets14ValveOpen10_30;
    avets16ValveOpenArray10_30[counts_10_30] = avets16ValveOpen10_30;
    ts11ValveOpenErr10_30[counts_10_30] = (maxts11ValveOpen10_30 - mints11ValveOpen10_30)/2;
    ts12ValveOpenErr10_30[counts_10_30] = (maxts12ValveOpen10_30 - mints12ValveOpen10_30)/2;
    ts14ValveOpenErr10_30[counts_10_30] = (maxts14ValveOpen10_30 - mints14ValveOpen10_30)/2;
    ts16ValveOpenErr10_30[counts_10_30] = (maxts16ValveOpen10_30 - mints16ValveOpen10_30)/2;
	    
    avecurArray10_30[counts_10_30] = avecur10_30;
    ErrcurArray10_30[counts_10_30] = (maxcur10_30 - mincur10_30)/2;
    
    delaytimeArray10_30[counts_10_30] = cycleDelayTime10_30;
    cycleNumberAllArray10_30[counts_10_30] = cycleNumberAll10_30;
    
    counts_10_30++;
  }


  

  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 170);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(10000,31);
  fit -> SetParLimits(0, 7000, 390000);
  fit -> SetParLimits(1, 15, 36);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************



  //*********************************
  //*********************************
  //              1_60
  //*********************************
  //*********************************
  TCanvas *c1_60 = new TCanvas("c1_60" , "c1_60" , 1200, 800);
  c1_60 ->SetLogy(); 
  TGraphErrors *gr1_60_delaycounts = new TGraphErrors(counts_1_60, delaytimeArray1_60 , UCNCountsArray1_60, 0, UCNCountsErrArray1_60);

  gr1_60_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr1_60_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr1_60_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1_60_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr1_60_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr1_60_delaycounts -> SetMarkerStyle(20);
  gr1_60_delaycounts -> Fit(fit);
  storage1_60 = fit -> GetParameter(1);
  storageErr1_60 = fit -> GetParError(1);




  gr1_60_delaycounts -> Draw("Ap");


  TCanvas *c1_60_cycleNum = new TCanvas("c1_60_cycleNum" , "c1_60_cycleNum" , 1200, 800);
  c1_60_cycleNum -> Divide(2,2);
  TPad *p1_60 = c1_60_cycleNum->cd(1);
  p1_60->SetLogy(); 
  TGraphErrors *gr1_60_cyclecounts = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, UCNCountsArray1_60, 0 , UCNCountsErrArray1_60);
  gr1_60_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr1_60_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr1_60_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1_60_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr1_60_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr1_60_cyclecounts -> SetMarkerColor(2);
  gr1_60_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr1_60_cyclehist = new TGraphErrors(counts_1_60, cycleNumberAllArray1_60 , HistIntegralArray1_60, 0, HistIntegralErrArray1_60);

  gr1_60_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr1_60_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr1_60_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1_60_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr1_60_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr1_60_cyclehist -> SetMarkerColor(1);
  gr1_60_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr1_60_cyclecounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr1_60_cyclehist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);

  
  gr1_60_cyclecounts -> Draw("Ap");
  gr1_60_cyclehist -> Draw("p");

  leg2-> Draw();

  c1_60_cycleNum -> cd(2);
 TGraphErrors *gr1_60_cycledelay = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, delaytimeArray1_60, 0 , 0);
  gr1_60_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr1_60_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr1_60_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr1_60_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr1_60_cycledelay -> SetMarkerStyle(20);

  gr1_60_cycledelay -> Draw("Ap");


  c1_60_cycleNum -> cd(3);

  TGraphErrors *gr1_60_cycletempValveOpen = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, avets12ValveOpenArray1_60, 0 , ts12ValveOpenErr1_60);

  gr1_60_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr1_60_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_60_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr1_60_cycletempValveOpen -> SetMarkerStyle(20);
  gr1_60_cycletempValveOpen -> SetMarkerColor(1);
  gr1_60_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr1_60_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr1_60_cycletempValveOpen11 = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, avets11ValveOpenArray1_60, 0 , ts11ValveOpenErr1_60);

  gr1_60_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr1_60_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_60_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr1_60_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr1_60_cycletempValveOpen11 -> SetMarkerColor(4);
  gr1_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr1_60_cycletempValveOpen14 = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, avets14ValveOpenArray1_60, 0 , ts14ValveOpenErr1_60);

  gr1_60_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr1_60_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_60_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr1_60_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr1_60_cycletempValveOpen14 -> SetMarkerColor(3);
  gr1_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr1_60_cycletempValveOpen16 = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60, avets16ValveOpenArray1_60, 0 , ts16ValveOpenErr1_60);

  gr1_60_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr1_60_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_60_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr1_60_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr1_60_cycletempValveOpen16 -> SetMarkerColor(2);
  gr1_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  TLegend *temps = new TLegend (0.7, 0.7, 0.9, 0.9);
  temps -> AddEntry( gr1_60_cycletempValveOpen11, "TS11" , "p");
  temps -> AddEntry( gr1_60_cycletempValveOpen, "TS12" , "p");
  temps -> AddEntry( gr1_60_cycletempValveOpen14, "TS14" , "p");
  temps -> AddEntry( gr1_60_cycletempValveOpen16, "TS16" , "p");
  

  
  gr1_60_cycletempValveOpen -> Draw("Ap");
  gr1_60_cycletempValveOpen11 -> Draw("p");
  gr1_60_cycletempValveOpen14 -> Draw("p");
  gr1_60_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c1_60_cycleNum -> cd(4);
  TGraphErrors *gr1_60_cyclecur = new TGraphErrors (counts_1_60 , cycleNumberAllArray1_60 , avecurArray1_60, 0, ErrcurArray1_60 );
  gr1_60_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr1_60_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr1_60_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr1_60_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr1_60_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr1_60_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr1_60_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr1_60_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr1_60_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr1_60_cyclecur -> SetMarkerStyle(20);
  gr1_60_cyclecur -> Draw("Ap");




  //*********************************
  //*********************************
  //              2_10
  //*********************************
  //*********************************
  TCanvas *c2_10 = new TCanvas("c2_10" , "c2_10" , 1200, 800);
  c2_10 ->SetLogy(); 
  TGraphErrors *gr2_10_delaycounts = new TGraphErrors(counts_2_10, delaytimeArray2_10 , UCNCountsArray2_10, 0, UCNCountsErrArray2_10);

  gr2_10_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_10_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_10_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_10_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_10_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_10_delaycounts -> SetMarkerStyle(20);
  gr2_10_delaycounts -> Fit(fit);
  storage2_10 = fit -> GetParameter(1);
  storageErr2_10 = fit -> GetParError(1);




  gr2_10_delaycounts -> Draw("Ap");


  TCanvas *c2_10_cycleNum = new TCanvas("c2_10_cycleNum" , "c2_10_cycleNum" , 1200, 800);
  c2_10_cycleNum -> Divide(2,2);
  TPad *p2_10 = c2_10_cycleNum->cd(1);
  p2_10->SetLogy(); 
  TGraphErrors *gr2_10_cyclecounts = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, UCNCountsArray2_10, 0 , UCNCountsErrArray2_10);
  gr2_10_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr2_10_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_10_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_10_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_10_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_10_cyclecounts -> SetMarkerColor(2);
  gr2_10_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr2_10_cyclehist = new TGraphErrors(counts_2_10, cycleNumberAllArray2_10 , HistIntegralArray2_10, 0, HistIntegralErrArray2_10);

  gr2_10_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_10_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_10_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_10_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_10_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_10_cyclehist -> SetMarkerColor(1);
  gr2_10_cyclehist -> SetMarkerStyle(25);

  
  gr2_10_cyclecounts -> Draw("Ap");
  gr2_10_cyclehist -> Draw("p");

  leg2-> Draw();

  c2_10_cycleNum -> cd(2);
 TGraphErrors *gr2_10_cycledelay = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, delaytimeArray2_10, 0 , 0);
  gr2_10_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr2_10_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_10_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr2_10_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_10_cycledelay -> SetMarkerStyle(20);

  gr2_10_cycledelay -> Draw("Ap");


  c2_10_cycleNum -> cd(3);

  TGraphErrors *gr2_10_cycletempValveOpen = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, avets12ValveOpenArray2_10, 0 , ts12ValveOpenErr2_10);

  gr2_10_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_10_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_10_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_10_cycletempValveOpen -> SetMarkerStyle(20);
  gr2_10_cycletempValveOpen -> SetMarkerColor(1);
  gr2_10_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr2_10_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr2_10_cycletempValveOpen11 = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, avets11ValveOpenArray2_10, 0 , ts11ValveOpenErr2_10);

  gr2_10_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_10_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_10_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_10_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr2_10_cycletempValveOpen11 -> SetMarkerColor(4);
  gr2_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr2_10_cycletempValveOpen14 = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, avets14ValveOpenArray2_10, 0 , ts14ValveOpenErr2_10);

  gr2_10_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_10_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_10_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_10_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr2_10_cycletempValveOpen14 -> SetMarkerColor(3);
  gr2_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr2_10_cycletempValveOpen16 = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10, avets16ValveOpenArray2_10, 0 , ts16ValveOpenErr2_10);

  gr2_10_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_10_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_10_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_10_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr2_10_cycletempValveOpen16 -> SetMarkerColor(2);
  gr2_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  

  
  gr2_10_cycletempValveOpen -> Draw("Ap");
  gr2_10_cycletempValveOpen11 -> Draw("p");
  gr2_10_cycletempValveOpen14 -> Draw("p");
  gr2_10_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c2_10_cycleNum -> cd(4);
  TGraphErrors *gr2_10_cyclecur = new TGraphErrors (counts_2_10 , cycleNumberAllArray2_10 , avecurArray2_10, 0, ErrcurArray2_10 );
  gr2_10_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr2_10_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr2_10_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr2_10_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr2_10_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr2_10_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr2_10_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_10_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_10_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_10_cyclecur -> SetMarkerStyle(20);
  gr2_10_cyclecur -> Draw("Ap");




  //*********************************
  //*********************************
  //              2_30
  //*********************************
  //*********************************
  TCanvas *c2_30 = new TCanvas("c2_30" , "c2_30" , 1200, 800);
  c2_30 ->SetLogy(); 
  TGraphErrors *gr2_30_delaycounts = new TGraphErrors(counts_2_30, delaytimeArray2_30 , UCNCountsArray2_30, 0, UCNCountsErrArray2_30);

  gr2_30_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_30_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_30_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_30_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_30_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_30_delaycounts -> SetMarkerStyle(20);
  gr2_30_delaycounts -> Fit(fit);
  storage2_30 = fit -> GetParameter(1);
  storageErr2_30 = fit -> GetParError(1);




  gr2_30_delaycounts -> Draw("Ap");


  TCanvas *c2_30_cycleNum = new TCanvas("c2_30_cycleNum" , "c2_30_cycleNum" , 1200, 800);
  c2_30_cycleNum -> Divide(2,2);
  TPad *p2_30 = c2_30_cycleNum->cd(1);
  p2_30->SetLogy(); 
  TGraphErrors *gr2_30_cyclecounts = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, UCNCountsArray2_30, 0 , UCNCountsErrArray2_30);
  gr2_30_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr2_30_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_30_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_30_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_30_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_30_cyclecounts -> SetMarkerColor(2);
  gr2_30_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr2_30_cyclehist = new TGraphErrors(counts_2_30, cycleNumberAllArray2_30 , HistIntegralArray2_30, 0, HistIntegralErrArray2_30);

  gr2_30_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_30_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_30_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_30_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_30_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_30_cyclehist -> SetMarkerColor(1);
  gr2_30_cyclehist -> SetMarkerStyle(25);

  
  gr2_30_cyclecounts -> Draw("Ap");
  gr2_30_cyclehist -> Draw("p");

  leg2-> Draw();

  c2_30_cycleNum -> cd(2);
 TGraphErrors *gr2_30_cycledelay = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, delaytimeArray2_30, 0 , 0);
  gr2_30_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr2_30_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_30_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr2_30_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_30_cycledelay -> SetMarkerStyle(20);

  gr2_30_cycledelay -> Draw("Ap");


  c2_30_cycleNum -> cd(3);

  TGraphErrors *gr2_30_cycletempValveOpen = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, avets12ValveOpenArray2_30, 0 , ts12ValveOpenErr2_30);

  gr2_30_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_30_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_30_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_30_cycletempValveOpen -> SetMarkerStyle(20);
  gr2_30_cycletempValveOpen -> SetMarkerColor(1);
  gr2_30_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr2_30_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr2_30_cycletempValveOpen11 = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, avets11ValveOpenArray2_30, 0 , ts11ValveOpenErr2_30);

  gr2_30_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_30_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_30_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_30_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr2_30_cycletempValveOpen11 -> SetMarkerColor(4);
  gr2_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr2_30_cycletempValveOpen14 = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, avets14ValveOpenArray2_30, 0 , ts14ValveOpenErr2_30);

  gr2_30_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_30_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_30_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_30_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr2_30_cycletempValveOpen14 -> SetMarkerColor(3);
  gr2_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr2_30_cycletempValveOpen16 = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30, avets16ValveOpenArray2_30, 0 , ts16ValveOpenErr2_30);

  gr2_30_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_30_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_30_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_30_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr2_30_cycletempValveOpen16 -> SetMarkerColor(2);
  gr2_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  

  
  gr2_30_cycletempValveOpen -> Draw("Ap");
  gr2_30_cycletempValveOpen11 -> Draw("p");
  gr2_30_cycletempValveOpen14 -> Draw("p");
  gr2_30_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c2_30_cycleNum -> cd(4);
  TGraphErrors *gr2_30_cyclecur = new TGraphErrors (counts_2_30 , cycleNumberAllArray2_30 , avecurArray2_30, 0, ErrcurArray2_30 );
  gr2_30_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr2_30_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr2_30_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr2_30_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr2_30_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr2_30_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr2_30_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_30_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_30_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_30_cyclecur -> SetMarkerStyle(20);
  gr2_30_cyclecur -> Draw("Ap");

  
  //*********************************
  //*********************************
  //              2_60
  //*********************************
  //*********************************
  TCanvas *c2_60 = new TCanvas("c2_60" , "c2_60" , 1200, 800);
  c2_60 ->SetLogy(); 
  TGraphErrors *gr2_60_delaycounts = new TGraphErrors(counts_2_60, delaytimeArray2_60 , UCNCountsArray2_60, 0, UCNCountsErrArray2_60);

  gr2_60_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_60_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_60_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_60_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_60_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_60_delaycounts -> SetMarkerStyle(20);
  gr2_60_delaycounts -> Fit(fit);
  storage2_60 = fit -> GetParameter(1);
  storageErr2_60 = fit -> GetParError(1);




  gr2_60_delaycounts -> Draw("Ap");


  TCanvas *c2_60_cycleNum = new TCanvas("c2_60_cycleNum" , "c2_60_cycleNum" , 1200, 800);
  c2_60_cycleNum -> Divide(2,2);
  TPad *p2_60 = c2_60_cycleNum->cd(1);
  p2_60->SetLogy(); 
  TGraphErrors *gr2_60_cyclecounts = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, UCNCountsArray2_60, 0 , UCNCountsErrArray2_60);
  gr2_60_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr2_60_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_60_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_60_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_60_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_60_cyclecounts -> SetMarkerColor(2);
  gr2_60_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr2_60_cyclehist = new TGraphErrors(counts_2_60, cycleNumberAllArray2_60 , HistIntegralArray2_60, 0, HistIntegralErrArray2_60);

  gr2_60_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_60_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_60_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_60_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_60_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_60_cyclehist -> SetMarkerColor(1);
  gr2_60_cyclehist -> SetMarkerStyle(25);

  
  gr2_60_cyclecounts -> Draw("Ap");
  gr2_60_cyclehist -> Draw("p");

  leg2-> Draw();

  c2_60_cycleNum -> cd(2);
 TGraphErrors *gr2_60_cycledelay = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, delaytimeArray2_60, 0 , 0);
  gr2_60_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr2_60_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_60_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr2_60_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_60_cycledelay -> SetMarkerStyle(20);

  gr2_60_cycledelay -> Draw("Ap");


  c2_60_cycleNum -> cd(3);

  TGraphErrors *gr2_60_cycletempValveOpen = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, avets12ValveOpenArray2_60, 0 , ts12ValveOpenErr2_60);

  gr2_60_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_60_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_60_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_60_cycletempValveOpen -> SetMarkerStyle(20);
  gr2_60_cycletempValveOpen -> SetMarkerColor(1);
  gr2_60_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr2_60_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr2_60_cycletempValveOpen11 = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, avets11ValveOpenArray2_60, 0 , ts11ValveOpenErr2_60);

  gr2_60_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_60_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_60_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_60_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr2_60_cycletempValveOpen11 -> SetMarkerColor(4);
  gr2_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr2_60_cycletempValveOpen14 = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, avets14ValveOpenArray2_60, 0 , ts14ValveOpenErr2_60);

  gr2_60_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_60_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_60_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_60_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr2_60_cycletempValveOpen14 -> SetMarkerColor(3);
  gr2_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr2_60_cycletempValveOpen16 = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60, avets16ValveOpenArray2_60, 0 , ts16ValveOpenErr2_60);

  gr2_60_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_60_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_60_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_60_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr2_60_cycletempValveOpen16 -> SetMarkerColor(2);
  gr2_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  

  
  gr2_60_cycletempValveOpen -> Draw("Ap");
  gr2_60_cycletempValveOpen11 -> Draw("p");
  gr2_60_cycletempValveOpen14 -> Draw("p");
  gr2_60_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c2_60_cycleNum -> cd(4);
  TGraphErrors *gr2_60_cyclecur = new TGraphErrors (counts_2_60 , cycleNumberAllArray2_60 , avecurArray2_60, 0, ErrcurArray2_60 );
  gr2_60_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr2_60_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr2_60_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr2_60_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr2_60_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr2_60_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr2_60_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_60_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_60_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_60_cyclecur -> SetMarkerStyle(20);
  gr2_60_cyclecur -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              2_120
  //*********************************
  //*********************************
  TCanvas *c2_120 = new TCanvas("c2_120" , "c2_120" , 1200, 800);
  c2_120 ->SetLogy(); 
  TGraphErrors *gr2_120_delaycounts = new TGraphErrors(counts_2_120, delaytimeArray2_120 , UCNCountsArray2_120, 0, UCNCountsErrArray2_120);

  gr2_120_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_120_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_120_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_120_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_120_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_120_delaycounts -> SetMarkerStyle(20);
  gr2_120_delaycounts -> Fit(fit);
  storage2_120 = fit -> GetParameter(1);
  storageErr2_120 = fit -> GetParError(1);




  gr2_120_delaycounts -> Draw("Ap");


  TCanvas *c2_120_cycleNum = new TCanvas("c2_120_cycleNum" , "c2_120_cycleNum" , 1200, 800);
  c2_120_cycleNum -> Divide(2,2);
  TPad *p2_120 = c2_120_cycleNum->cd(1);
  p2_120->SetLogy(); 
  TGraphErrors *gr2_120_cyclecounts = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, UCNCountsArray2_120, 0 , UCNCountsErrArray2_120);
  gr2_120_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr2_120_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_120_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_120_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_120_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_120_cyclecounts -> SetMarkerColor(2);
  gr2_120_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr2_120_cyclehist = new TGraphErrors(counts_2_120, cycleNumberAllArray2_120 , HistIntegralArray2_120, 0, HistIntegralErrArray2_120);

  gr2_120_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr2_120_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr2_120_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_120_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr2_120_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_120_cyclehist -> SetMarkerColor(1);
  gr2_120_cyclehist -> SetMarkerStyle(25);

  
  gr2_120_cyclecounts -> Draw("Ap");
  gr2_120_cyclehist -> Draw("p");

  leg2-> Draw();

  c2_120_cycleNum -> cd(2);
 TGraphErrors *gr2_120_cycledelay = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, delaytimeArray2_120, 0 , 0);
  gr2_120_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr2_120_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr2_120_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr2_120_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_120_cycledelay -> SetMarkerStyle(20);

  gr2_120_cycledelay -> Draw("Ap");


  c2_120_cycleNum -> cd(3);

  TGraphErrors *gr2_120_cycletempValveOpen = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, avets12ValveOpenArray2_120, 0 , ts12ValveOpenErr2_120);

  gr2_120_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_120_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_120_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_120_cycletempValveOpen -> SetMarkerStyle(20);
  gr2_120_cycletempValveOpen -> SetMarkerColor(1);
  gr2_120_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr2_120_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr2_120_cycletempValveOpen11 = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, avets11ValveOpenArray2_120, 0 , ts11ValveOpenErr2_120);

  gr2_120_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_120_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_120_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_120_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr2_120_cycletempValveOpen11 -> SetMarkerColor(4);
  gr2_120_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr2_120_cycletempValveOpen14 = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, avets14ValveOpenArray2_120, 0 , ts14ValveOpenErr2_120);

  gr2_120_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_120_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_120_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_120_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr2_120_cycletempValveOpen14 -> SetMarkerColor(3);
  gr2_120_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr2_120_cycletempValveOpen16 = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120, avets16ValveOpenArray2_120, 0 , ts16ValveOpenErr2_120);

  gr2_120_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr2_120_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_120_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr2_120_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr2_120_cycletempValveOpen16 -> SetMarkerColor(2);
  gr2_120_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr2_120_cycletempValveOpen -> Draw("Ap");
  gr2_120_cycletempValveOpen11 -> Draw("p");
  gr2_120_cycletempValveOpen14 -> Draw("p");
  gr2_120_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c2_120_cycleNum -> cd(4);
  TGraphErrors *gr2_120_cyclecur = new TGraphErrors (counts_2_120 , cycleNumberAllArray2_120 , avecurArray2_120, 0, ErrcurArray2_120 );
  gr2_120_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr2_120_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr2_120_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr2_120_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr2_120_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr2_120_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr2_120_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_120_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_120_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr2_120_cyclecur -> SetMarkerStyle(20);
  gr2_120_cyclecur -> Draw("Ap");



  

  //*********************************
  //*********************************
  //              5_10
  //*********************************
  //*********************************
  TCanvas *c5_10 = new TCanvas("c5_10" , "c5_10" , 1200, 800);
  c5_10 ->SetLogy(); 
  TGraphErrors *gr5_10_delaycounts = new TGraphErrors(counts_5_10, delaytimeArray5_10 , UCNCountsArray5_10, 0, UCNCountsErrArray5_10);

  gr5_10_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_10_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_10_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_10_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_10_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_10_delaycounts -> SetMarkerStyle(20);
  gr5_10_delaycounts -> Fit(fit);
  storage5_10 = fit -> GetParameter(1);
  storageErr5_10 = fit -> GetParError(1);




  gr5_10_delaycounts -> Draw("Ap");


  TCanvas *c5_10_cycleNum = new TCanvas("c5_10_cycleNum" , "c5_10_cycleNum" , 1200, 800);
  c5_10_cycleNum -> Divide(2,2);
  TPad *p5_10 = c5_10_cycleNum->cd(1);
  p5_10->SetLogy(); 
  TGraphErrors *gr5_10_cyclecounts = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, UCNCountsArray5_10, 0 , UCNCountsErrArray5_10);
  gr5_10_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr5_10_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_10_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_10_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_10_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_10_cyclecounts -> SetMarkerColor(2);
  gr5_10_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr5_10_cyclehist = new TGraphErrors(counts_5_10, cycleNumberAllArray5_10 , HistIntegralArray5_10, 0, HistIntegralErrArray5_10);

  gr5_10_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_10_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_10_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_10_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_10_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_10_cyclehist -> SetMarkerColor(1);
  gr5_10_cyclehist -> SetMarkerStyle(25);

  
  gr5_10_cyclecounts -> Draw("Ap");
  gr5_10_cyclehist -> Draw("p");

  leg2-> Draw();

  c5_10_cycleNum -> cd(2);
 TGraphErrors *gr5_10_cycledelay = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, delaytimeArray5_10, 0 , 0);
  gr5_10_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr5_10_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_10_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr5_10_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_10_cycledelay -> SetMarkerStyle(20);

  gr5_10_cycledelay -> Draw("Ap");


  c5_10_cycleNum -> cd(3);

  TGraphErrors *gr5_10_cycletempValveOpen = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, avets12ValveOpenArray5_10, 0 , ts12ValveOpenErr5_10);

  gr5_10_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_10_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_10_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_10_cycletempValveOpen -> SetMarkerStyle(20);
  gr5_10_cycletempValveOpen -> SetMarkerColor(1);
  gr5_10_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr5_10_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr5_10_cycletempValveOpen11 = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, avets11ValveOpenArray5_10, 0 , ts11ValveOpenErr5_10);

  gr5_10_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_10_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_10_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_10_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr5_10_cycletempValveOpen11 -> SetMarkerColor(4);
  gr5_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr5_10_cycletempValveOpen14 = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, avets14ValveOpenArray5_10, 0 , ts14ValveOpenErr5_10);

  gr5_10_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_10_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_10_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_10_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr5_10_cycletempValveOpen14 -> SetMarkerColor(3);
  gr5_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr5_10_cycletempValveOpen16 = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10, avets16ValveOpenArray5_10, 0 , ts16ValveOpenErr5_10);

  gr5_10_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_10_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_10_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_10_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr5_10_cycletempValveOpen16 -> SetMarkerColor(2);
  gr5_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  

  
  gr5_10_cycletempValveOpen -> Draw("Ap");
  gr5_10_cycletempValveOpen11 -> Draw("p");
  gr5_10_cycletempValveOpen14 -> Draw("p");
  gr5_10_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c5_10_cycleNum -> cd(4);
  TGraphErrors *gr5_10_cyclecur = new TGraphErrors (counts_5_10 , cycleNumberAllArray5_10 , avecurArray5_10, 0, ErrcurArray5_10 );
  gr5_10_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr5_10_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr5_10_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr5_10_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr5_10_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr5_10_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr5_10_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_10_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_10_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_10_cyclecur -> SetMarkerStyle(20);
  gr5_10_cyclecur -> Draw("Ap");




  
  //*********************************
  //*********************************
  //              5_30
  //*********************************
  //*********************************
  TCanvas *c5_30 = new TCanvas("c5_30" , "c5_30" , 1200, 800);
  c5_30 ->SetLogy(); 
  TGraphErrors *gr5_30_delaycounts = new TGraphErrors(counts_5_30, delaytimeArray5_30 , UCNCountsArray5_30, 0, UCNCountsErrArray5_30);

  gr5_30_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_30_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_30_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_30_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_30_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_30_delaycounts -> SetMarkerStyle(20);
  gr5_30_delaycounts -> Fit(fit);
  storage5_30 = fit -> GetParameter(1);
  storageErr5_30 = fit -> GetParError(1);

  gr5_30_delaycounts -> Draw("Ap");


  TCanvas *c5_30_cycleNum = new TCanvas("c5_30_cycleNum" , "c5_30_cycleNum" , 1200, 800);
  c5_30_cycleNum -> Divide(2,2);
  TPad *p5_30 = c5_30_cycleNum->cd(1);
  p5_30->SetLogy(); 
  TGraphErrors *gr5_30_cyclecounts = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, UCNCountsArray5_30, 0 , UCNCountsErrArray5_30);
  gr5_30_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr5_30_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_30_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_30_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_30_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_30_cyclecounts -> SetMarkerColor(2);
  gr5_30_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr5_30_cyclehist = new TGraphErrors(counts_5_30, cycleNumberAllArray5_30 , HistIntegralArray5_30, 0, HistIntegralErrArray5_30);

  gr5_30_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_30_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_30_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_30_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_30_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_30_cyclehist -> SetMarkerColor(1);
  gr5_30_cyclehist -> SetMarkerStyle(25);

  
  gr5_30_cyclecounts -> Draw("Ap");
  gr5_30_cyclehist -> Draw("p");

  leg2-> Draw();

  c5_30_cycleNum -> cd(2);
 TGraphErrors *gr5_30_cycledelay = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, delaytimeArray5_30, 0 , 0);
  gr5_30_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr5_30_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_30_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr5_30_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_30_cycledelay -> SetMarkerStyle(20);

  gr5_30_cycledelay -> Draw("Ap");


  c5_30_cycleNum -> cd(3);

  TGraphErrors *gr5_30_cycletempValveOpen = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, avets12ValveOpenArray5_30, 0 , ts12ValveOpenErr5_30);

  gr5_30_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_30_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_30_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_30_cycletempValveOpen -> SetMarkerStyle(20);
  gr5_30_cycletempValveOpen -> SetMarkerColor(1);
  gr5_30_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr5_30_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr5_30_cycletempValveOpen11 = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, avets11ValveOpenArray5_30, 0 , ts11ValveOpenErr5_30);

  gr5_30_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_30_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_30_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_30_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr5_30_cycletempValveOpen11 -> SetMarkerColor(4);
  gr5_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr5_30_cycletempValveOpen14 = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, avets14ValveOpenArray5_30, 0 , ts14ValveOpenErr5_30);

  gr5_30_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_30_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_30_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_30_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr5_30_cycletempValveOpen14 -> SetMarkerColor(3);
  gr5_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr5_30_cycletempValveOpen16 = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30, avets16ValveOpenArray5_30, 0 , ts16ValveOpenErr5_30);

  gr5_30_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_30_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_30_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_30_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr5_30_cycletempValveOpen16 -> SetMarkerColor(2);
  gr5_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr5_30_cycletempValveOpen -> Draw("Ap");
  gr5_30_cycletempValveOpen11 -> Draw("p");
  gr5_30_cycletempValveOpen14 -> Draw("p");
  gr5_30_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c5_30_cycleNum -> cd(4);
  TGraphErrors *gr5_30_cyclecur = new TGraphErrors (counts_5_30 , cycleNumberAllArray5_30 , avecurArray5_30, 0, ErrcurArray5_30 );
  gr5_30_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr5_30_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr5_30_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr5_30_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr5_30_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr5_30_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr5_30_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_30_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_30_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_30_cyclecur -> SetMarkerStyle(20);
  gr5_30_cyclecur -> Draw("Ap");

  //*********************************
  //*********************************
  //              5_60
  //*********************************
  //*********************************

  TCanvas *c5_60 = new TCanvas("c5_60" , "c5_60" , 1200, 800);
  c5_60 ->SetLogy(); 
  TGraphErrors *gr5_60_delaycounts = new TGraphErrors(counts_5_60, delaytimeArray5_60 , UCNCountsArray5_60, 0, UCNCountsErrArray5_60);

  gr5_60_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_60_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_60_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_60_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_60_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_60_delaycounts -> SetMarkerStyle(20);
  gr5_60_delaycounts -> Fit(fit);
  storage5_60 = fit -> GetParameter(1);
  storageErr5_60 = fit -> GetParError(1);




  gr5_60_delaycounts -> Draw("Ap");


  TCanvas *c5_60_cycleNum = new TCanvas("c5_60_cycleNum" , "c5_60_cycleNum" , 1200, 800);
  c5_60_cycleNum -> Divide(2,2);
  TPad *p5_60 = c5_60_cycleNum->cd(1);
  p5_60->SetLogy(); 
  TGraphErrors *gr5_60_cyclecounts = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, UCNCountsArray5_60, 0 , UCNCountsErrArray5_60);
  gr5_60_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr5_60_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_60_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_60_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_60_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_60_cyclecounts -> SetMarkerColor(2);
  gr5_60_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr5_60_cyclehist = new TGraphErrors(counts_5_60, cycleNumberAllArray5_60 , HistIntegralArray5_60, 0, HistIntegralErrArray5_60);

  gr5_60_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_60_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_60_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_60_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_60_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_60_cyclehist -> SetMarkerColor(1);
  gr5_60_cyclehist -> SetMarkerStyle(25);


  gr5_60_cyclecounts -> Draw("Ap");
  gr5_60_cyclehist -> Draw("p");

  leg2-> Draw();

  c5_60_cycleNum -> cd(2);
 TGraphErrors *gr5_60_cycledelay = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, delaytimeArray5_60, 0 , 0);
  gr5_60_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr5_60_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_60_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr5_60_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_60_cycledelay -> SetMarkerStyle(20);

  gr5_60_cycledelay -> Draw("Ap");


  c5_60_cycleNum -> cd(3);

  TGraphErrors *gr5_60_cycletempValveOpen = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, avets12ValveOpenArray5_60, 0 , ts12ValveOpenErr5_60);

  gr5_60_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_60_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_60_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_60_cycletempValveOpen -> SetMarkerStyle(20);
  gr5_60_cycletempValveOpen -> SetMarkerColor(1);
  gr5_60_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr5_60_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr5_60_cycletempValveOpen11 = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, avets11ValveOpenArray5_60, 0 , ts11ValveOpenErr5_60);

  gr5_60_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_60_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_60_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_60_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr5_60_cycletempValveOpen11 -> SetMarkerColor(4);
  gr5_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr5_60_cycletempValveOpen14 = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, avets14ValveOpenArray5_60, 0 , ts14ValveOpenErr5_60);

  gr5_60_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_60_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_60_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_60_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr5_60_cycletempValveOpen14 -> SetMarkerColor(3);
  gr5_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr5_60_cycletempValveOpen16 = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60, avets16ValveOpenArray5_60, 0 , ts16ValveOpenErr5_60);

  gr5_60_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_60_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_60_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_60_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr5_60_cycletempValveOpen16 -> SetMarkerColor(2);
  gr5_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr5_60_cycletempValveOpen -> Draw("Ap");
  gr5_60_cycletempValveOpen11 -> Draw("p");
  gr5_60_cycletempValveOpen14 -> Draw("p");
  gr5_60_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c5_60_cycleNum -> cd(4);
  TGraphErrors *gr5_60_cyclecur = new TGraphErrors (counts_5_60 , cycleNumberAllArray5_60 , avecurArray5_60, 0, ErrcurArray5_60 );
  gr5_60_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr5_60_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr5_60_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr5_60_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr5_60_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr5_60_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr5_60_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_60_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_60_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_60_cyclecur -> SetMarkerStyle(20);
  gr5_60_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              5_120
  //*********************************
  //*********************************
 
  TCanvas *c5_120 = new TCanvas("c5_120" , "c5_120" , 1200, 800);
  c5_120 ->SetLogy(); 
  TGraphErrors *gr5_120_delaycounts = new TGraphErrors(counts_5_120, delaytimeArray5_120 , UCNCountsArray5_120, 0, UCNCountsErrArray5_120);

  gr5_120_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_120_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_120_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_120_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_120_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_120_delaycounts -> SetMarkerStyle(20);
  gr5_120_delaycounts -> Fit(fit);
  storage5_120 = fit -> GetParameter(1);
  storageErr5_120 = fit -> GetParError(1);




  gr5_120_delaycounts -> Draw("Ap");


  TCanvas *c5_120_cycleNum = new TCanvas("c5_120_cycleNum" , "c5_120_cycleNum" , 1200, 800);
  c5_120_cycleNum -> Divide(2,2);
  TPad *p5_120 = c5_120_cycleNum->cd(1);
  p5_120->SetLogy(); 
  TGraphErrors *gr5_120_cyclecounts = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, UCNCountsArray5_120, 0 , UCNCountsErrArray5_120);
  gr5_120_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr5_120_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_120_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_120_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_120_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_120_cyclecounts -> SetMarkerColor(2);
  gr5_120_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr5_120_cyclehist = new TGraphErrors(counts_5_120, cycleNumberAllArray5_120 , HistIntegralArray5_120, 0, HistIntegralErrArray5_120);

  gr5_120_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr5_120_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr5_120_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_120_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr5_120_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr5_120_cyclehist -> SetMarkerColor(1);
  gr5_120_cyclehist -> SetMarkerStyle(25);

  
  gr5_120_cyclecounts -> Draw("Ap");
  gr5_120_cyclehist -> Draw("p");

  leg2-> Draw();

  c5_120_cycleNum -> cd(2);
 TGraphErrors *gr5_120_cycledelay = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, delaytimeArray5_120, 0 , 0);
  gr5_120_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr5_120_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr5_120_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr5_120_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_120_cycledelay -> SetMarkerStyle(20);

  gr5_120_cycledelay -> Draw("Ap");


  c5_120_cycleNum -> cd(3);

  TGraphErrors *gr5_120_cycletempValveOpen = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, avets12ValveOpenArray5_120, 0 , ts12ValveOpenErr5_120);

  gr5_120_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_120_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_120_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_120_cycletempValveOpen -> SetMarkerStyle(20);
  gr5_120_cycletempValveOpen -> SetMarkerColor(1);
  gr5_120_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr5_120_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr5_120_cycletempValveOpen11 = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, avets11ValveOpenArray5_120, 0 , ts11ValveOpenErr5_120);

  gr5_120_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_120_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_120_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_120_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr5_120_cycletempValveOpen11 -> SetMarkerColor(4);
  gr5_120_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr5_120_cycletempValveOpen14 = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, avets14ValveOpenArray5_120, 0 , ts14ValveOpenErr5_120);

  gr5_120_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_120_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_120_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_120_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr5_120_cycletempValveOpen14 -> SetMarkerColor(3);
  gr5_120_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr5_120_cycletempValveOpen16 = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120, avets16ValveOpenArray5_120, 0 , ts16ValveOpenErr5_120);

  gr5_120_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr5_120_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_120_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr5_120_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr5_120_cycletempValveOpen16 -> SetMarkerColor(2);
  gr5_120_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr5_120_cycletempValveOpen -> Draw("Ap");
  gr5_120_cycletempValveOpen11 -> Draw("p");
  gr5_120_cycletempValveOpen14 -> Draw("p");
  gr5_120_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c5_120_cycleNum -> cd(4);
  TGraphErrors *gr5_120_cyclecur = new TGraphErrors (counts_5_120 , cycleNumberAllArray5_120 , avecurArray5_120, 0, ErrcurArray5_120 );
  gr5_120_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr5_120_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr5_120_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr5_120_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr5_120_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr5_120_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr5_120_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr5_120_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr5_120_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr5_120_cyclecur -> SetMarkerStyle(20);
  gr5_120_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              7_10
  //*********************************
  //*********************************
 
  TCanvas *c7_10 = new TCanvas("c7_10" , "c7_10" , 1200, 800);
  c7_10 ->SetLogy(); 
  TGraphErrors *gr7_10_delaycounts = new TGraphErrors(counts_7_10, delaytimeArray7_10 , UCNCountsArray7_10, 0, UCNCountsErrArray7_10);

  gr7_10_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_10_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_10_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_10_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_10_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_10_delaycounts -> SetMarkerStyle(20);
  gr7_10_delaycounts -> Fit(fit);
  storage7_10 = fit -> GetParameter(1);
  storageErr7_10 = fit -> GetParError(1);




  gr7_10_delaycounts -> Draw("Ap");


  TCanvas *c7_10_cycleNum = new TCanvas("c7_10_cycleNum" , "c7_10_cycleNum" , 1200, 800);
  c7_10_cycleNum -> Divide(2,2);
  TPad *p7_10 = c7_10_cycleNum->cd(1);
  p7_10->SetLogy(); 
  TGraphErrors *gr7_10_cyclecounts = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, UCNCountsArray7_10, 0 , UCNCountsErrArray7_10);
  gr7_10_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr7_10_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_10_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_10_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_10_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_10_cyclecounts -> SetMarkerColor(2);
  gr7_10_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr7_10_cyclehist = new TGraphErrors(counts_7_10, cycleNumberAllArray7_10 , HistIntegralArray7_10, 0, HistIntegralErrArray7_10);

  gr7_10_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_10_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_10_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_10_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_10_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_10_cyclehist -> SetMarkerColor(1);
  gr7_10_cyclehist -> SetMarkerStyle(25);

  
  gr7_10_cyclecounts -> Draw("Ap");
  gr7_10_cyclehist -> Draw("p");

  leg2-> Draw();

  c7_10_cycleNum -> cd(2);
 TGraphErrors *gr7_10_cycledelay = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, delaytimeArray7_10, 0 , 0);
  gr7_10_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr7_10_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_10_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr7_10_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_10_cycledelay -> SetMarkerStyle(20);

  gr7_10_cycledelay -> Draw("Ap");


  c7_10_cycleNum -> cd(3);

  TGraphErrors *gr7_10_cycletempValveOpen = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, avets12ValveOpenArray7_10, 0 , ts12ValveOpenErr7_10);

  gr7_10_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_10_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_10_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_10_cycletempValveOpen -> SetMarkerStyle(20);
  gr7_10_cycletempValveOpen -> SetMarkerColor(1);
  gr7_10_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr7_10_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr7_10_cycletempValveOpen11 = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, avets11ValveOpenArray7_10, 0 , ts11ValveOpenErr7_10);

  gr7_10_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_10_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_10_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_10_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr7_10_cycletempValveOpen11 -> SetMarkerColor(4);
  gr7_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr7_10_cycletempValveOpen14 = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, avets14ValveOpenArray7_10, 0 , ts14ValveOpenErr7_10);

  gr7_10_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_10_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_10_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_10_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr7_10_cycletempValveOpen14 -> SetMarkerColor(3);
  gr7_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr7_10_cycletempValveOpen16 = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10, avets16ValveOpenArray7_10, 0 , ts16ValveOpenErr7_10);

  gr7_10_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_10_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_10_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_10_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr7_10_cycletempValveOpen16 -> SetMarkerColor(2);
  gr7_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr7_10_cycletempValveOpen -> Draw("Ap");
  gr7_10_cycletempValveOpen11 -> Draw("p");
  gr7_10_cycletempValveOpen14 -> Draw("p");
  gr7_10_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c7_10_cycleNum -> cd(4);
  TGraphErrors *gr7_10_cyclecur = new TGraphErrors (counts_7_10 , cycleNumberAllArray7_10 , avecurArray7_10, 0, ErrcurArray7_10 );
  gr7_10_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr7_10_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr7_10_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr7_10_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr7_10_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr7_10_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr7_10_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_10_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_10_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_10_cyclecur -> SetMarkerStyle(20);
  gr7_10_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              7_30
  //*********************************
  //*********************************
 
  TCanvas *c7_30 = new TCanvas("c7_30" , "c7_30" , 1200, 800);
  c7_30 ->SetLogy(); 
  TGraphErrors *gr7_30_delaycounts = new TGraphErrors(counts_7_30, delaytimeArray7_30 , UCNCountsArray7_30, 0, UCNCountsErrArray7_30);

  gr7_30_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_30_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_30_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_30_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_30_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_30_delaycounts -> SetMarkerStyle(20);
  gr7_30_delaycounts -> Fit(fit);
  storage7_30 = fit -> GetParameter(1);
  storageErr7_30 = fit -> GetParError(1);




  gr7_30_delaycounts -> Draw("Ap");


  TCanvas *c7_30_cycleNum = new TCanvas("c7_30_cycleNum" , "c7_30_cycleNum" , 1200, 800);
  c7_30_cycleNum -> Divide(2,2);
  TPad *p7_30 = c7_30_cycleNum->cd(1);
  p7_30->SetLogy(); 
  TGraphErrors *gr7_30_cyclecounts = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, UCNCountsArray7_30, 0 , UCNCountsErrArray7_30);
  gr7_30_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr7_30_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_30_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_30_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_30_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_30_cyclecounts -> SetMarkerColor(2);
  gr7_30_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr7_30_cyclehist = new TGraphErrors(counts_7_30, cycleNumberAllArray7_30 , HistIntegralArray7_30, 0, HistIntegralErrArray7_30);

  gr7_30_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_30_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_30_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_30_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_30_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_30_cyclehist -> SetMarkerColor(1);
  gr7_30_cyclehist -> SetMarkerStyle(25);

  
  gr7_30_cyclecounts -> Draw("Ap");
  gr7_30_cyclehist -> Draw("p");

  leg2-> Draw();

  c7_30_cycleNum -> cd(2);
 TGraphErrors *gr7_30_cycledelay = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, delaytimeArray7_30, 0 , 0);
  gr7_30_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr7_30_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_30_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr7_30_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_30_cycledelay -> SetMarkerStyle(20);

  gr7_30_cycledelay -> Draw("Ap");


  c7_30_cycleNum -> cd(3);

  TGraphErrors *gr7_30_cycletempValveOpen = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, avets12ValveOpenArray7_30, 0 , ts12ValveOpenErr7_30);

  gr7_30_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_30_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_30_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_30_cycletempValveOpen -> SetMarkerStyle(20);
  gr7_30_cycletempValveOpen -> SetMarkerColor(1);
  gr7_30_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr7_30_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr7_30_cycletempValveOpen11 = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, avets11ValveOpenArray7_30, 0 , ts11ValveOpenErr7_30);

  gr7_30_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_30_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_30_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_30_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr7_30_cycletempValveOpen11 -> SetMarkerColor(4);
  gr7_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr7_30_cycletempValveOpen14 = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, avets14ValveOpenArray7_30, 0 , ts14ValveOpenErr7_30);

  gr7_30_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_30_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_30_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_30_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr7_30_cycletempValveOpen14 -> SetMarkerColor(3);
  gr7_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr7_30_cycletempValveOpen16 = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30, avets16ValveOpenArray7_30, 0 , ts16ValveOpenErr7_30);

  gr7_30_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_30_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_30_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_30_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr7_30_cycletempValveOpen16 -> SetMarkerColor(2);
  gr7_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr7_30_cycletempValveOpen -> Draw("Ap");
  gr7_30_cycletempValveOpen11 -> Draw("p");
  gr7_30_cycletempValveOpen14 -> Draw("p");
  gr7_30_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c7_30_cycleNum -> cd(4);
  TGraphErrors *gr7_30_cyclecur = new TGraphErrors (counts_7_30 , cycleNumberAllArray7_30 , avecurArray7_30, 0, ErrcurArray7_30 );
  gr7_30_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr7_30_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr7_30_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr7_30_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr7_30_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr7_30_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr7_30_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_30_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_30_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_30_cyclecur -> SetMarkerStyle(20);
  gr7_30_cyclecur -> Draw("Ap");

  
  //*********************************
  //*********************************
  //              7_60
  //*********************************
  //*********************************
 
  TCanvas *c7_60 = new TCanvas("c7_60" , "c7_60" , 1200, 800);
  c7_60 ->SetLogy(); 
  TGraphErrors *gr7_60_delaycounts = new TGraphErrors(counts_7_60, delaytimeArray7_60 , UCNCountsArray7_60, 0, UCNCountsErrArray7_60);

  gr7_60_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_60_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_60_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_60_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_60_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_60_delaycounts -> SetMarkerStyle(20);
  gr7_60_delaycounts -> Fit(fit);
  storage7_60 = fit -> GetParameter(1);
  storageErr7_60 = fit -> GetParError(1);




  gr7_60_delaycounts -> Draw("Ap");


  TCanvas *c7_60_cycleNum = new TCanvas("c7_60_cycleNum" , "c7_60_cycleNum" , 1200, 800);
  c7_60_cycleNum -> Divide(2,2);
  TPad *p7_60 = c7_60_cycleNum->cd(1);
  p7_60->SetLogy(); 
  TGraphErrors *gr7_60_cyclecounts = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, UCNCountsArray7_60, 0 , UCNCountsErrArray7_60);
  gr7_60_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr7_60_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_60_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_60_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_60_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_60_cyclecounts -> SetMarkerColor(2);
  gr7_60_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr7_60_cyclehist = new TGraphErrors(counts_7_60, cycleNumberAllArray7_60 , HistIntegralArray7_60, 0, HistIntegralErrArray7_60);

  gr7_60_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr7_60_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7_60_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_60_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr7_60_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr7_60_cyclehist -> SetMarkerColor(1);
  gr7_60_cyclehist -> SetMarkerStyle(25);

  
  gr7_60_cyclecounts -> Draw("Ap");
  gr7_60_cyclehist -> Draw("p");

  leg2-> Draw();

  c7_60_cycleNum -> cd(2);
 TGraphErrors *gr7_60_cycledelay = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, delaytimeArray7_60, 0 , 0);
  gr7_60_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr7_60_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr7_60_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr7_60_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_60_cycledelay -> SetMarkerStyle(20);

  gr7_60_cycledelay -> Draw("Ap");


  c7_60_cycleNum -> cd(3);

  TGraphErrors *gr7_60_cycletempValveOpen = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, avets12ValveOpenArray7_60, 0 , ts12ValveOpenErr7_60);

  gr7_60_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_60_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_60_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_60_cycletempValveOpen -> SetMarkerStyle(20);
  gr7_60_cycletempValveOpen -> SetMarkerColor(1);
  gr7_60_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr7_60_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr7_60_cycletempValveOpen11 = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, avets11ValveOpenArray7_60, 0 , ts11ValveOpenErr7_60);

  gr7_60_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_60_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_60_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_60_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr7_60_cycletempValveOpen11 -> SetMarkerColor(4);
  gr7_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr7_60_cycletempValveOpen14 = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, avets14ValveOpenArray7_60, 0 , ts14ValveOpenErr7_60);

  gr7_60_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_60_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_60_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_60_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr7_60_cycletempValveOpen14 -> SetMarkerColor(3);
  gr7_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr7_60_cycletempValveOpen16 = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60, avets16ValveOpenArray7_60, 0 , ts16ValveOpenErr7_60);

  gr7_60_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr7_60_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_60_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr7_60_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr7_60_cycletempValveOpen16 -> SetMarkerColor(2);
  gr7_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr7_60_cycletempValveOpen -> Draw("Ap");
  gr7_60_cycletempValveOpen11 -> Draw("p");
  gr7_60_cycletempValveOpen14 -> Draw("p");
  gr7_60_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c7_60_cycleNum -> cd(4);
  TGraphErrors *gr7_60_cyclecur = new TGraphErrors (counts_7_60 , cycleNumberAllArray7_60 , avecurArray7_60, 0, ErrcurArray7_60 );
  gr7_60_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr7_60_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr7_60_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr7_60_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr7_60_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr7_60_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr7_60_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr7_60_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr7_60_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr7_60_cyclecur -> SetMarkerStyle(20);
  gr7_60_cyclecur -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              10_10
  //*********************************
  //*********************************
  TCanvas *c10_10 = new TCanvas("c10_10" , "c10_10" , 1200, 800);
  c10_10 ->SetLogy(); 
  TGraphErrors *gr10_10_delaycounts = new TGraphErrors(counts_10_10, delaytimeArray10_10 , UCNCountsArray10_10, 0, UCNCountsErrArray10_10);

  gr10_10_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr10_10_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr10_10_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_10_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_10_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_10_delaycounts -> SetMarkerStyle(20);
  gr10_10_delaycounts -> Fit(fit);
  storage10_10 = fit -> GetParameter(1);
  storageErr10_10 = fit -> GetParError(1);




  gr10_10_delaycounts -> Draw("Ap");


  TCanvas *c10_10_cycleNum = new TCanvas("c10_10_cycleNum" , "c10_10_cycleNum" , 1200, 800);
  c10_10_cycleNum -> Divide(2,2);
  TPad *p10_10 = c10_10_cycleNum->cd(1);
  p10_10->SetLogy(); 
  TGraphErrors *gr10_10_cyclecounts = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, UCNCountsArray10_10, 0 , UCNCountsErrArray10_10);
  gr10_10_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr10_10_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr10_10_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_10_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_10_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr10_10_cyclecounts -> SetMarkerColor(2);
  gr10_10_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr10_10_cyclehist = new TGraphErrors(counts_10_10, cycleNumberAllArray10_10 , HistIntegralArray10_10, 0, HistIntegralErrArray10_10);

  gr10_10_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr10_10_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr10_10_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_10_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_10_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr10_10_cyclehist -> SetMarkerColor(1);
  gr10_10_cyclehist -> SetMarkerStyle(25);

  
  gr10_10_cyclecounts -> Draw("Ap");
  gr10_10_cyclehist -> Draw("p");

  leg2-> Draw();

  c10_10_cycleNum -> cd(2);
 TGraphErrors *gr10_10_cycledelay = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, delaytimeArray10_10, 0 , 0);
  gr10_10_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr10_10_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr10_10_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr10_10_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_10_cycledelay -> SetMarkerStyle(20);

  gr10_10_cycledelay -> Draw("Ap");


  c10_10_cycleNum -> cd(3);

  TGraphErrors *gr10_10_cycletempValveOpen = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, avets12ValveOpenArray10_10, 0 , ts12ValveOpenErr10_10);

  gr10_10_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_10_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_10_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_10_cycletempValveOpen -> SetMarkerStyle(20);
  gr10_10_cycletempValveOpen -> SetMarkerColor(1);
  gr10_10_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr10_10_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr10_10_cycletempValveOpen11 = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, avets11ValveOpenArray10_10, 0 , ts11ValveOpenErr10_10);

  gr10_10_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_10_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_10_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_10_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr10_10_cycletempValveOpen11 -> SetMarkerColor(4);
  gr10_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr10_10_cycletempValveOpen14 = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, avets14ValveOpenArray10_10, 0 , ts14ValveOpenErr10_10);

  gr10_10_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_10_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_10_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_10_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr10_10_cycletempValveOpen14 -> SetMarkerColor(3);
  gr10_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr10_10_cycletempValveOpen16 = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10, avets16ValveOpenArray10_10, 0 , ts16ValveOpenErr10_10);

  gr10_10_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_10_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_10_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_10_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr10_10_cycletempValveOpen16 -> SetMarkerColor(2);
  gr10_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr10_10_cycletempValveOpen -> Draw("Ap");
  gr10_10_cycletempValveOpen11 -> Draw("p");
  gr10_10_cycletempValveOpen14 -> Draw("p");
  gr10_10_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c10_10_cycleNum -> cd(4);
  TGraphErrors *gr10_10_cyclecur = new TGraphErrors (counts_10_10 , cycleNumberAllArray10_10 , avecurArray10_10, 0, ErrcurArray10_10 );
  gr10_10_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr10_10_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr10_10_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr10_10_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr10_10_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr10_10_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr10_10_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_10_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_10_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_10_cyclecur -> SetMarkerStyle(20);
  gr10_10_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              10_30
  //*********************************
  //*********************************
  TCanvas *c10_30 = new TCanvas("c10_30" , "c10_30" , 1200, 800);
  c10_30 ->SetLogy(); 
  TGraphErrors *gr10_30_delaycounts = new TGraphErrors(counts_10_30, delaytimeArray10_30 , UCNCountsArray10_30, 0, UCNCountsErrArray10_30);

  gr10_30_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr10_30_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr10_30_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_30_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_30_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_30_delaycounts -> SetMarkerStyle(20);
  gr10_30_delaycounts -> Fit(fit);
  storage10_30 = fit -> GetParameter(1);
  storageErr10_30 = fit -> GetParError(1);




  gr10_30_delaycounts -> Draw("Ap");


  TCanvas *c10_30_cycleNum = new TCanvas("c10_30_cycleNum" , "c10_30_cycleNum" , 1200, 800);
  c10_30_cycleNum -> Divide(2,2);
  TPad *p10_30 = c10_30_cycleNum->cd(1);
  p10_30->SetLogy(); 
  TGraphErrors *gr10_30_cyclecounts = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, UCNCountsArray10_30, 0 , UCNCountsErrArray10_30);
  gr10_30_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr10_30_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr10_30_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_30_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_30_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr10_30_cyclecounts -> SetMarkerColor(2);
  gr10_30_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr10_30_cyclehist = new TGraphErrors(counts_10_30, cycleNumberAllArray10_30 , HistIntegralArray10_30, 0, HistIntegralErrArray10_30);

  gr10_30_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr10_30_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr10_30_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_30_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr10_30_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr10_30_cyclehist -> SetMarkerColor(1);
  gr10_30_cyclehist -> SetMarkerStyle(25);

  
  gr10_30_cyclecounts -> Draw("Ap");
  gr10_30_cyclehist -> Draw("p");

  leg2-> Draw();

  c10_30_cycleNum -> cd(2);
 TGraphErrors *gr10_30_cycledelay = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, delaytimeArray10_30, 0 , 0);
  gr10_30_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr10_30_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr10_30_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr10_30_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_30_cycledelay -> SetMarkerStyle(20);

  gr10_30_cycledelay -> Draw("Ap");


  c10_30_cycleNum -> cd(3);

  TGraphErrors *gr10_30_cycletempValveOpen = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, avets12ValveOpenArray10_30, 0 , ts12ValveOpenErr10_30);

  gr10_30_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_30_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_30_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_30_cycletempValveOpen -> SetMarkerStyle(20);
  gr10_30_cycletempValveOpen -> SetMarkerColor(1);
  gr10_30_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr10_30_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr10_30_cycletempValveOpen11 = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, avets11ValveOpenArray10_30, 0 , ts11ValveOpenErr10_30);

  gr10_30_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_30_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_30_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_30_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr10_30_cycletempValveOpen11 -> SetMarkerColor(4);
  gr10_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr10_30_cycletempValveOpen14 = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, avets14ValveOpenArray10_30, 0 , ts14ValveOpenErr10_30);

  gr10_30_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_30_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_30_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_30_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr10_30_cycletempValveOpen14 -> SetMarkerColor(3);
  gr10_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr10_30_cycletempValveOpen16 = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30, avets16ValveOpenArray10_30, 0 , ts16ValveOpenErr10_30);

  gr10_30_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr10_30_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_30_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr10_30_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr10_30_cycletempValveOpen16 -> SetMarkerColor(2);
  gr10_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr10_30_cycletempValveOpen -> Draw("Ap");
  gr10_30_cycletempValveOpen11 -> Draw("p");
  gr10_30_cycletempValveOpen14 -> Draw("p");
  gr10_30_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c10_30_cycleNum -> cd(4);
  TGraphErrors *gr10_30_cyclecur = new TGraphErrors (counts_10_30 , cycleNumberAllArray10_30 , avecurArray10_30, 0, ErrcurArray10_30 );
  gr10_30_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr10_30_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr10_30_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr10_30_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr10_30_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr10_30_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr10_30_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr10_30_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr10_30_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr10_30_cyclecur -> SetMarkerStyle(20);
  gr10_30_cyclecur -> Draw("Ap");

  // ****************************************
  // overall resutl
  // ****************************************

  double StorageArray_1muA[max] = {storage1_60};
  double StorageErrArray_1muA[max] = {storageErr1_60};
  double IrradArray_1muA[max] = {60};

  double StorageArray_2muA[max] = {storage2_10, storage2_30, storage2_60, storage2_120};
  double StorageErrArray_2muA[max] = {storageErr2_10, storageErr2_30, storageErr2_60, storageErr2_120};
  double IrradArray_2muA[max] = {10, 30, 60, 120};


  double StorageArray_5muA[max] = {storage5_10, storage5_30, storage5_60, storage5_120};
  double StorageErrArray_5muA[max] = { storageErr5_10, storageErr5_30, storageErr5_60, storageErr5_120};
  double IrradArray_5muA [max] = {10, 30, 60, 120};


  double StorageArray_7muA[max] = {storage7_10, storage7_30, storage7_60};
  double StorageErrArray_7muA[max] = {storageErr7_10, storageErr7_30, storageErr7_60};
  double IrradArray_7muA[max] = {10, 30 , 60};


  double StorageArray_10muA[max] = {storage10_10, storage10_30};
  double StorageErrArray_10muA[max] = {storageErr10_10, storageErr10_30};
  double IrradArray_10muA[max] = {10, 30};

  

  TCanvas *cAll = new TCanvas ("cAll" , "cAll", 1200, 900);

  TGraphErrors *Storage_1muA = new TGraphErrors (1, IrradArray_1muA, StorageArray_1muA, 0 , StorageErrArray_1muA);
  Storage_1muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  Storage_1muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  Storage_1muA -> GetYaxis()-> SetRangeUser(0, 40);
  Storage_1muA -> GetXaxis()-> SetLimits(0 ,150);
  Storage_1muA -> GetXaxis() -> SetTitleSize(0.05);
  Storage_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_1muA -> SetMarkerStyle(20);

  TGraphErrors *Storage_2muA = new TGraphErrors (4, IrradArray_2muA, StorageArray_2muA, 0 , StorageErrArray_2muA);
  Storage_2muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  Storage_2muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_2muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  //Storage_2muA -> GetYaxis()-> SetRangeUser(1, 500000);
  //  Storage_2muA -> GetXaxis()-> SetLimits(0.82 ,0.90);
  Storage_2muA -> GetXaxis() -> SetTitleSize(0.05);
  Storage_2muA -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_2muA -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_2muA -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_2muA -> SetMarkerStyle(21);


  TGraphErrors *Storage_5muA = new TGraphErrors (4, IrradArray_5muA, StorageArray_5muA, 0 , StorageErrArray_5muA);
  Storage_5muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  Storage_5muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  //Storage_5muA -> GetYaxis()-> SetRangeUser(1, 500000);
  //  Storage_5muA -> GetXaxis()-> SetLimits(0.82 ,0.90);
  Storage_5muA -> GetXaxis() -> SetTitleSize(0.05);
  Storage_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_5muA -> SetMarkerStyle(23);

  TGraphErrors *Storage_7muA = new TGraphErrors (3, IrradArray_7muA, StorageArray_7muA, 0 , StorageErrArray_7muA);
  Storage_7muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  Storage_7muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  //Storage_7muA -> GetYaxis()-> SetRangeUser(1, 500000);
  //  Storage_7muA -> GetXaxis()-> SetLimits(0.82 ,0.90);
  Storage_7muA -> GetXaxis() -> SetTitleSize(0.05);
  Storage_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_7muA -> SetMarkerStyle(24);
  
  TGraphErrors *Storage_10muA = new TGraphErrors (2, IrradArray_10muA, StorageArray_10muA, 0 , StorageErrArray_10muA);
  Storage_10muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  Storage_10muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  //Storage_10muA -> GetYaxis()-> SetRangeUser(1, 500000);
  //  Storage_10muA -> GetXaxis()-> SetLimits(0.82 ,0.90);
  Storage_10muA -> GetXaxis() -> SetTitleSize(0.05);
  Storage_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_10muA -> SetMarkerStyle(25);

  TLegend *currents = new TLegend (0.7 , 0.7, 0.9, 0.9);
  currents -> AddEntry(Storage_1muA , "1 #muA" , "p");
  currents -> AddEntry(Storage_2muA , "2.5 #muA" , "p");
  currents -> AddEntry(Storage_5muA , "5 #muA" , "p");
  currents -> AddEntry(Storage_7muA , "7.1 #muA" , "p");
  currents -> AddEntry(Storage_10muA , "10 #muA" , "p");
  
  Storage_1muA -> Draw("Ap");
  Storage_2muA -> Draw("p");
  Storage_5muA -> Draw("p");
  Storage_7muA -> Draw("p");
  Storage_10muA -> Draw("p");
  currents -> Draw();

  //*************************************************
  // Storage lifetime vs beam current
  //*************************************************
  
  double StorageArray_10s [max] = {storage2_10, storage5_10, storage7_10, storage10_10};
  double StorageErrArray_10s[max] = {storageErr2_10, storageErr5_10, storageErr7_10, storageErr10_10};
  double BeamArray_10s[max] = {2.5, 5., 7.1, 10.};


  double StorageArray_30s [max] = {storage2_30, storage5_30, storage7_30, storage10_30};
  double StorageErrArray_30s [max] = {storageErr2_30 , storageErr5_30, storageErr7_30, storageErr10_30};
  double BeamArray_30s[max] = {2.5, 5., 7.1, 10. };


  double StorageArray_60s [max]  = {storage1_60, storage2_60, storage5_60, storage7_60};
  double StorageErrArray_60s[max] = {storageErr1_60, storageErr2_60, storageErr5_60, storageErr5_60, storageErr7_60};
  double BeamArray_60s[max] = {1., 2.5 , 5., 7.1};

  double StorageArray_120s[max] = {storage2_120, storage5_120};
  double StorageErrArray_120s[max] = {storageErr2_120, storageErr5_120};
  double BeamArray_120s [max] = {2.5, 5. };

  TCanvas *cAll_2 = new TCanvas ("cAll_2" , "cAll_2" , 1200,  900);

  TGraphErrors *Storage_10s = new TGraphErrors (4, BeamArray_10s, StorageArray_10s, 0 , StorageErrArray_10s);
  Storage_10s -> SetTitle("Storage Lifetime vs Beam Current");
  Storage_10s -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_10s -> GetXaxis()-> SetTitle("Beam Current (#muA)");
  Storage_10s -> GetYaxis()-> SetRangeUser(0, 50);
  Storage_10s -> GetXaxis()-> SetLimits(0 ,11);
  Storage_10s -> GetXaxis() -> SetTitleSize(0.05);
  Storage_10s -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_10s -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_10s -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_10s -> SetMarkerStyle(20);
  Storage_10s -> SetMarkerSize(2);


  TGraphErrors *Storage_30s = new TGraphErrors (4, BeamArray_30s, StorageArray_30s, 0 , StorageErrArray_30s);
  Storage_30s -> SetTitle("Storage Lifetime vs Beam Current");
  Storage_30s -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_30s -> GetXaxis()-> SetTitle("Beam Current (#muA)");
  Storage_30s -> GetYaxis()-> SetRangeUser(0, 40);
  Storage_30s -> GetXaxis()-> SetLimits(0 ,150);
  Storage_30s -> GetXaxis() -> SetTitleSize(0.05);
  Storage_30s -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_30s -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_30s -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_30s -> SetMarkerStyle(21);
  Storage_30s -> SetMarkerSize(2);

  
  
  TGraphErrors *Storage_60s = new TGraphErrors (4, BeamArray_60s, StorageArray_60s, 0 , StorageErrArray_60s);
  Storage_60s -> SetTitle("Storage Lifetime vs Beam Current");
  Storage_60s -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_60s -> GetXaxis()-> SetTitle("Beam Current (#muA)");
  Storage_60s -> GetYaxis()-> SetRangeUser(0, 40);
  Storage_60s -> GetXaxis()-> SetLimits(0 ,150);
  Storage_60s -> GetXaxis() -> SetTitleSize(0.05);
  Storage_60s -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_60s -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_60s -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_60s -> SetMarkerStyle(23);
  Storage_60s -> SetMarkerSize(2);
    


  TGraphErrors *Storage_120s = new TGraphErrors (2, BeamArray_120s, StorageArray_120s, 0 , StorageErrArray_120s);
  Storage_120s -> SetTitle("Storage Lifetime vs Beam Current");
  Storage_120s -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  Storage_120s -> GetXaxis()-> SetTitle("Beam Current (#muA)");
  Storage_120s -> GetYaxis()-> SetRangeUser(0, 40);
  Storage_120s -> GetXaxis()-> SetLimits(0 ,150);
  Storage_120s -> GetXaxis() -> SetTitleSize(0.05);
  Storage_120s -> GetXaxis() -> SetTitleOffset(1.0);
  Storage_120s -> GetYaxis() -> SetTitleSize(0.05); 
  Storage_120s -> GetYaxis() -> SetTitleOffset(0.9);
  Storage_120s -> SetMarkerStyle(24);
  Storage_120s -> SetMarkerSize(2);


  TLegend *irrad = new TLegend (0.7, 0.7 , 0.9, 0.9);
  irrad -> AddEntry(Storage_10s , "10 s Irradiation time" , "p");
  irrad -> AddEntry(Storage_30s , "30 s Irradiation time" , "p");
  irrad -> AddEntry(Storage_60s , "60 s Irradiation time" , "p");
  irrad -> AddEntry(Storage_120s , "120 s Irradiation time" , "p");
	


  Storage_10s -> Draw("ap");
  Storage_30s -> Draw("p");
  Storage_60s -> Draw("p");
  Storage_120s -> Draw("p");
  irrad -> Draw();
}
