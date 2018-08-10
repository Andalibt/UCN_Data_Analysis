//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17014.

// This is for the second pass of analysis.
// Taraneh Andalib, June 19 2018
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17014_Taraneh_edit_ver3(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin780 = new TFile("./2ndpass/outputTree_780.root","READ");
  TFile *fin781 = new TFile("./2ndpass/outputTree_781.root","READ");
  TFile *fin782 = new TFile("./2ndpass/outputTree_782.root","READ");
  TFile *fin783 = new TFile("./2ndpass/outputTree_783.root","READ");
  TFile *fin784 = new TFile("./2ndpass/outputTree_784.root","READ");
  TFile *fin785 = new TFile("./2ndpass/outputTree_785.root","READ");
  TFile *fin786 = new TFile("./2ndpass/outputTree_786.root","READ");

  
  TTree *outputTree780 = (TTree*) fin780 -> Get("cycle_info");
  TTree *outputTree781 = (TTree*) fin781 -> Get("cycle_info");
  TTree *outputTree782 = (TTree*) fin782 -> Get("cycle_info");
  TTree *outputTree783 = (TTree*) fin783 -> Get("cycle_info");
  TTree *outputTree784 = (TTree*) fin784 -> Get("cycle_info");
  TTree *outputTree785 = (TTree*) fin785 -> Get("cycle_info");
  TTree *outputTree786 = (TTree*) fin786 -> Get("cycle_info");
  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime780;
  double cycleDelayTime781;
  double cycleDelayTime782;
  double cycleDelayTime783;
  double cycleDelayTime784;
  double cycleDelayTime785;
  double cycleDelayTime786;


  outputTree780 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime780);
  outputTree781 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime781);
  outputTree782 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime782);
  outputTree783 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime783);
  outputTree784 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime784);
  outputTree785 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime785);
  outputTree786 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime786);


  // DELAY TIME (ARRAY)
  double delaytimeArray780 [100];
  double delaytimeArray781 [100];
  double delaytimeArray782 [100];
  double delaytimeArray783 [100];
  double delaytimeArray784 [100];
  double delaytimeArray785 [100];
  double delaytimeArray786 [100];


  // cycle Valve Open Time
  double cycleValveOpenTime780;
  double cycleValveOpenTime781;
  double cycleValveOpenTime782;
  double cycleValveOpenTime783;
  double cycleValveOpenTime784;
  double cycleValveOpenTime785;
  double cycleValveOpenTime786;

  outputTree780 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime780);
  outputTree781 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime781);
  outputTree782 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime782);
  outputTree783 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime783);
  outputTree784 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime784);
  outputTree785 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime785);
  outputTree786 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime786);
  

  // cycle Valve Close Time
  double cycleValveCloseTime780;
  double cycleValveCloseTime781;
  double cycleValveCloseTime782;
  double cycleValveCloseTime783;
  double cycleValveCloseTime784;
  double cycleValveCloseTime785;
  double cycleValveCloseTime786;

  outputTree780 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime780);
  outputTree781 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime781);
  outputTree782 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime782);
  outputTree783 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime783);
  outputTree784 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime784);
  outputTree785 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime785);
  outputTree786 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime786);

  
  // CYCLE NUMBER
  int cycleNumber780;
  int cycleNumber781;
  int cycleNumber782;
  int cycleNumber783;
  int cycleNumber784;
  int cycleNumber785;
  int cycleNumber786;

  outputTree780 -> SetBranchAddress ("cycleNumber" , &cycleNumber780);
  outputTree781 -> SetBranchAddress ("cycleNumber" , &cycleNumber781);
  outputTree782 -> SetBranchAddress ("cycleNumber" , &cycleNumber782);
  outputTree783 -> SetBranchAddress ("cycleNumber" , &cycleNumber783);
  outputTree784 -> SetBranchAddress ("cycleNumber" , &cycleNumber784);
  outputTree785 -> SetBranchAddress ("cycleNumber" , &cycleNumber785);
  outputTree786 -> SetBranchAddress ("cycleNumber" , &cycleNumber786);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray780 [100];
  double cycleNumberArray781 [100];
  double cycleNumberArray782 [100];
  double cycleNumberArray783 [100];
  double cycleNumberArray784 [100];
  double cycleNumberArray785 [100];
  double cycleNumberArray786 [100];

  // Total UCN counts without background

  double UCNCountsArray780 [100];
  double UCNCountsArray781 [100];
  double UCNCountsArray782 [100];
  double UCNCountsArray783 [100];
  double UCNCountsArray784 [100];
  double UCNCountsArray785 [100];
  double UCNCountsArray786 [100];


  // Error in the total UCN counts without background

  double UCNCountsErrArray780 [100];
  double UCNCountsErrArray781 [100];
  double UCNCountsErrArray782 [100];
  double UCNCountsErrArray783 [100];
  double UCNCountsErrArray784 [100];
  double UCNCountsErrArray785 [100];
  double UCNCountsErrArray786 [100];

  
  
  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral780;
  double HistIntegral781;
  double HistIntegral782;
  double HistIntegral783;
  double HistIntegral784;
  double HistIntegral785;
  double HistIntegral786;

  outputTree780 -> SetBranchAddress ("HistIntegral" , &HistIntegral780); 
  outputTree781 -> SetBranchAddress ("HistIntegral" , &HistIntegral781);
  outputTree782 -> SetBranchAddress ("HistIntegral" , &HistIntegral782);
  outputTree783 -> SetBranchAddress ("HistIntegral" , &HistIntegral783);
  outputTree784 -> SetBranchAddress ("HistIntegral" , &HistIntegral784);
  outputTree785 -> SetBranchAddress ("HistIntegral" , &HistIntegral785);
  outputTree786 -> SetBranchAddress ("HistIntegral" , &HistIntegral786);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray780 [100];
  double HistIntegralArray781 [100];
  double HistIntegralArray782 [100];
  double HistIntegralArray783 [100];
  double HistIntegralArray784 [100];
  double HistIntegralArray785 [100];
  double HistIntegralArray786 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr780;
  double HistIntegralErr781;
  double HistIntegralErr782;
  double HistIntegralErr783;
  double HistIntegralErr784;
  double HistIntegralErr785;
  double HistIntegralErr786;

  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray780 [100];
  double HistIntegralErrArray781 [100];
  double HistIntegralErrArray782 [100];
  double HistIntegralErrArray783 [100];
  double HistIntegralErrArray784 [100];
  double HistIntegralErrArray785 [100];
  double HistIntegralErrArray786 [100];

  // AVERAGE TS11 DURING VALVE OPEN
  double avets11ValveOpen780;
  double avets11ValveOpen781;
  double avets11ValveOpen782;
  double avets11ValveOpen783;
  double avets11ValveOpen784;
  double avets11ValveOpen785;
  double avets11ValveOpen786;

  outputTree780 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen780);
  outputTree781 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen781);
  outputTree782 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen782);
  outputTree783 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen783);
  outputTree784 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen784);
  outputTree785 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen785);
  outputTree786 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen786);

  // AVERAGE TS11 DURING VALVE OPEN (ARRAY)
  double avets11ValveOpenArray780 [100];
  double avets11ValveOpenArray781 [100];
  double avets11ValveOpenArray782 [100];
  double avets11ValveOpenArray783 [100];
  double avets11ValveOpenArray784 [100];
  double avets11ValveOpenArray785 [100];
  double avets11ValveOpenArray786 [100];


  
  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen780;
  double avets12ValveOpen781;
  double avets12ValveOpen782;
  double avets12ValveOpen783;
  double avets12ValveOpen784;
  double avets12ValveOpen785;
  double avets12ValveOpen786;

  outputTree780 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen780);
  outputTree781 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen781);
  outputTree782 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen782);
  outputTree783 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen783);
  outputTree784 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen784);
  outputTree785 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen785);
  outputTree786 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen786);



  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray780 [100];
  double avets12ValveOpenArray781 [100];
  double avets12ValveOpenArray782 [100];
  double avets12ValveOpenArray783 [100];
  double avets12ValveOpenArray784 [100];
  double avets12ValveOpenArray785 [100];
  double avets12ValveOpenArray786 [100];



  
  // AVERAGE TS14 DURING VALVE OPEN
  double avets14ValveOpen780;
  double avets14ValveOpen781;
  double avets14ValveOpen782;
  double avets14ValveOpen783;
  double avets14ValveOpen784;
  double avets14ValveOpen785;
  double avets14ValveOpen786;

  outputTree780 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen780);
  outputTree781 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen781);
  outputTree782 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen782);
  outputTree783 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen783);
  outputTree784 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen784);
  outputTree785 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen785);
  outputTree786 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen786);



  // AVERAGE TS14 DURING VALVE OPEN (ARRAY)
  double avets14ValveOpenArray780 [100];
  double avets14ValveOpenArray781 [100];
  double avets14ValveOpenArray782 [100];
  double avets14ValveOpenArray783 [100];
  double avets14ValveOpenArray784 [100];
  double avets14ValveOpenArray785 [100];
  double avets14ValveOpenArray786 [100];



  
  // AVERAGE TS16 DURING VALVE OPEN
  double avets16ValveOpen780;
  double avets16ValveOpen781;
  double avets16ValveOpen782;
  double avets16ValveOpen783;
  double avets16ValveOpen784;
  double avets16ValveOpen785;
  double avets16ValveOpen786;

  outputTree780 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen780);
  outputTree781 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen781);
  outputTree782 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen782);
  outputTree783 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen783);
  outputTree784 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen784);
  outputTree785 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen785);
  outputTree786 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen786);



  // AVERAGE TS16 DURING VALVE OPEN (ARRAY)
  double avets16ValveOpenArray780 [100];
  double avets16ValveOpenArray781 [100];
  double avets16ValveOpenArray782 [100];
  double avets16ValveOpenArray783 [100];
  double avets16ValveOpenArray784 [100];
  double avets16ValveOpenArray785 [100];
  double avets16ValveOpenArray786 [100];
  
  //********************************************
  
  // MAXIMUM TS11 DURING VALVE OPEN
  double maxts11ValveOpen780;
  double maxts11ValveOpen781;
  double maxts11ValveOpen782;
  double maxts11ValveOpen783;
  double maxts11ValveOpen784;
  double maxts11ValveOpen785;
  double maxts11ValveOpen786;

  outputTree780 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen780);
  outputTree781 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen781);
  outputTree782 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen782);
  outputTree783 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen783);
  outputTree784 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen784);
  outputTree785 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen785);
  outputTree786 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen786);



  // MINIMUM TS11 DURING VALVE OPEN
  double mints11ValveOpen780;
  double mints11ValveOpen781;
  double mints11ValveOpen782;
  double mints11ValveOpen783;
  double mints11ValveOpen784;
  double mints11ValveOpen785;
  double mints11ValveOpen786;
  
  outputTree780 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen780);
  outputTree781 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen781);
  outputTree782 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen782);
  outputTree783 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen783);
  outputTree784 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen784);
  outputTree785 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen785);
  outputTree786 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen786);


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts11ValveOpenErr780 [100];
  double ts11ValveOpenErr781 [100];
  double ts11ValveOpenErr782 [100];
  double ts11ValveOpenErr783 [100];
  double ts11ValveOpenErr784 [100];
  double ts11ValveOpenErr785 [100];
  double ts11ValveOpenErr786 [100];


  
  //*****************************************
 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen780;
  double maxts12ValveOpen781;
  double maxts12ValveOpen782;
  double maxts12ValveOpen783;
  double maxts12ValveOpen784;
  double maxts12ValveOpen785;
  double maxts12ValveOpen786;

  outputTree780 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen780);
  outputTree781 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen781);
  outputTree782 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen782);
  outputTree783 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen783);
  outputTree784 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen784);
  outputTree785 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen785);
  outputTree786 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen786);



  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen780;
  double mints12ValveOpen781;
  double mints12ValveOpen782;
  double mints12ValveOpen783;
  double mints12ValveOpen784;
  double mints12ValveOpen785;
  double mints12ValveOpen786;
  
  outputTree780 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen780);
  outputTree781 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen781);
  outputTree782 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen782);
  outputTree783 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen783);
  outputTree784 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen784);
  outputTree785 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen785);
  outputTree786 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen786);


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr780 [100];
  double ts12ValveOpenErr781 [100];
  double ts12ValveOpenErr782 [100];
  double ts12ValveOpenErr783 [100];
  double ts12ValveOpenErr784 [100];
  double ts12ValveOpenErr785 [100];
  double ts12ValveOpenErr786 [100];


  //*******************************************************************

  
 // MAXIMUM TS14 DURING VALVE OPEN
  double maxts14ValveOpen780;
  double maxts14ValveOpen781;
  double maxts14ValveOpen782;
  double maxts14ValveOpen783;
  double maxts14ValveOpen784;
  double maxts14ValveOpen785;
  double maxts14ValveOpen786;

  outputTree780 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen780);
  outputTree781 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen781);
  outputTree782 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen782);
  outputTree783 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen783);
  outputTree784 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen784);
  outputTree785 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen785);
  outputTree786 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen786);



  // MINIMUM TS14 DURING VALVE OPEN
  double mints14ValveOpen780;
  double mints14ValveOpen781;
  double mints14ValveOpen782;
  double mints14ValveOpen783;
  double mints14ValveOpen784;
  double mints14ValveOpen785;
  double mints14ValveOpen786;
  
  outputTree780 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen780);
  outputTree781 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen781);
  outputTree782 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen782);
  outputTree783 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen783);
  outputTree784 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen784);
  outputTree785 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen785);
  outputTree786 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen786);


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts14ValveOpenErr780 [100];
  double ts14ValveOpenErr781 [100];
  double ts14ValveOpenErr782 [100];
  double ts14ValveOpenErr783 [100];
  double ts14ValveOpenErr784 [100];
  double ts14ValveOpenErr785 [100];
  double ts14ValveOpenErr786 [100];


  //**********************************************************************************

 // MAXIMUM TS16 DURING VALVE OPEN
  double maxts16ValveOpen780;
  double maxts16ValveOpen781;
  double maxts16ValveOpen782;
  double maxts16ValveOpen783;
  double maxts16ValveOpen784;
  double maxts16ValveOpen785;
  double maxts16ValveOpen786;

  outputTree780 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen780);
  outputTree781 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen781);
  outputTree782 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen782);
  outputTree783 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen783);
  outputTree784 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen784);
  outputTree785 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen785);
  outputTree786 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen786);



  // MINIMUM TS16 DURING VALVE OPEN
  double mints16ValveOpen780;
  double mints16ValveOpen781;
  double mints16ValveOpen782;
  double mints16ValveOpen783;
  double mints16ValveOpen784;
  double mints16ValveOpen785;
  double mints16ValveOpen786;
  
  outputTree780 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen780);
  outputTree781 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen781);
  outputTree782 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen782);
  outputTree783 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen783);
  outputTree784 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen784);
  outputTree785 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen785);
  outputTree786 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen786);


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts16ValveOpenErr780 [100];
  double ts16ValveOpenErr781 [100];
  double ts16ValveOpenErr782 [100];
  double ts16ValveOpenErr783 [100];
  double ts16ValveOpenErr784 [100];
  double ts16ValveOpenErr785 [100];
  double ts16ValveOpenErr786 [100];



  //***********************************************************************************

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur780;
  double avecur781;
  double avecur782;
  double avecur783;
  double avecur784;
  double avecur785;
  double avecur786;

  outputTree780 -> SetBranchAddress ("AVE_PRDCUR" , &avecur780);
  outputTree781 -> SetBranchAddress ("AVE_PRDCUR" , &avecur781);
  outputTree782 -> SetBranchAddress ("AVE_PRDCUR" , &avecur782);
  outputTree783 -> SetBranchAddress ("AVE_PRDCUR" , &avecur783);
  outputTree784 -> SetBranchAddress ("AVE_PRDCUR" , &avecur784);
  outputTree785 -> SetBranchAddress ("AVE_PRDCUR" , &avecur785);
  outputTree786 -> SetBranchAddress ("AVE_PRDCUR" , &avecur786);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray780 [100];
  double avecurArray781 [100];
  double avecurArray782 [100];
  double avecurArray783 [100];
  double avecurArray784 [100];
  double avecurArray785 [100];
  double avecurArray786 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur780;
  double maxcur781;
  double maxcur782;
  double maxcur783;
  double maxcur784;
  double maxcur785;
  double maxcur786;

  outputTree780 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur780);
  outputTree781 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur781);
  outputTree782 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur782);
  outputTree783 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur783);
  outputTree784 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur784);
  outputTree785 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur785);
  outputTree786 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur786);




  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur780;
  double mincur781;
  double mincur782;
  double mincur783;
  double mincur784;
  double mincur785;
  double mincur786;

  outputTree780 -> SetBranchAddress ("MIN_PRDCUR" , &mincur780);
  outputTree781 -> SetBranchAddress ("MIN_PRDCUR" , &mincur781);
  outputTree782 -> SetBranchAddress ("MIN_PRDCUR" , &mincur782);
  outputTree783 -> SetBranchAddress ("MIN_PRDCUR" , &mincur783);
  outputTree784 -> SetBranchAddress ("MIN_PRDCUR" , &mincur784);
  outputTree785 -> SetBranchAddress ("MIN_PRDCUR" , &mincur785);
  outputTree786 -> SetBranchAddress ("MIN_PRDCUR" , &mincur786);


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray780 [100];
  double ErrcurArray781 [100];
  double ErrcurArray782 [100];
  double ErrcurArray783 [100];
  double ErrcurArray784 [100];
  double ErrcurArray785 [100];
  double ErrcurArray786 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double BASELINERATE780;
  double BASELINERATE781;
  double BASELINERATE782;
  double BASELINERATE783;
  double BASELINERATE784;
  double BASELINERATE785;
  double BASELINERATE786;

  outputTree780 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE780);
  outputTree781 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE781);
  outputTree782 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE782);
  outputTree783 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE783);
  outputTree784 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE784);
  outputTree785 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE785);
  outputTree786 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE786);


  
  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage780;
  double storage781;
  double storage782;
  double storage783;
  double storage784;
  double storage785;
  double storage786;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr780;
  double storageErr781;
  double storageErr782;
  double storageErr783;
  double storageErr784;
  double storageErr785;
  double storageErr786;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_780 = 0;
  int counts_781 = 0;
  int counts_782 = 0;
  int counts_783 = 0;
  int counts_784 = 0;
  int counts_785 = 0;
  int counts_786 = 0;


  double avets11All780;
  double maxts11All780 = 0;
  double mints11All780 = 20;
  double avets12All780;
  double maxts12All780 = 0;
  double mints12All780 = 20;
  double avets14All780;
  double maxts14All780 = 0;
  double mints14All780 = 20;
  double avets16All780;
  double maxts16All780 = 0;
  double mints16All780 = 20;
  double ts11ErrAll780;
  double ts12ErrAll780;
  double ts14ErrAll780;
  double ts16ErrAll780;

  double avets11All781;
  double maxts11All781 = 0;
  double mints11All781 = 20;
  double avets12All781;
  double maxts12All781 = 0;
  double mints12All781 = 20;
  double avets14All781;
  double maxts14All781 = 0;
  double mints14All781 = 20;
  double avets16All781;
  double maxts16All781 = 0;
  double mints16All781 = 20;
  double ts11ErrAll781;
  double ts12ErrAll781;
  double ts14ErrAll781;
  double ts16ErrAll781;


  double avets11All782;
  double maxts11All782 = 0;
  double mints11All782 = 20;
  double avets12All782;
  double maxts12All782 = 0;
  double mints12All782 = 20;
  double avets14All782;
  double maxts14All782 = 0;
  double mints14All782 = 20;
  double avets16All782;
  double maxts16All782 = 0;
  double mints16All782 = 20;
  double ts11ErrAll782;
  double ts12ErrAll782;
  double ts14ErrAll782;
  double ts16ErrAll782;


  double avets11All784;
  double maxts11All784 = 0;
  double mints11All784 = 20;
  double avets12All784;
  double maxts12All784 = 0;
  double mints12All784 = 20;
  double avets14All784;
  double maxts14All784 = 0;
  double mints14All784 = 20;
  double avets16All784;
  double maxts16All784 = 0;
  double mints16All784 = 20;
  double ts11ErrAll784;
  double ts12ErrAll784;
  double ts14ErrAll784;
  double ts16ErrAll784;


  double avets11All785;
  double maxts11All785 = 0;
  double mints11All785 = 20;
  double avets12All785;
  double maxts12All785 = 0;
  double mints12All785 = 20;
  double avets14All785;
  double maxts14All785 = 0;
  double mints14All785 = 20;
  double avets16All785;
  double maxts16All785 = 0;
  double mints16All785 = 20;
  double ts11ErrAll785;
  double ts12ErrAll785;
  double ts14ErrAll785;
  double ts16ErrAll785;
  

  double avets11All786;
  double maxts11All786 = 0;
  double mints11All786 = 20;
  double avets12All786;
  double maxts12All786 = 0;
  double mints12All786 = 20;
  double avets14All786;
  double maxts14All786 = 0;
  double mints14All786 = 20;
  double avets16All786;
  double maxts16All786 = 0;
  double mints16All786 = 20;
  double ts11ErrAll786;
  double ts12ErrAll786;
  double ts14ErrAll786;
  double ts16ErrAll786;


  
  // BECAUSE THE ERROR BARS FOR TGRAPHERRORS ARE DOUBLED I HAVE TO DIVIDE THE ERRORS IN HALF
  
  ULong64_t events780;
  events780 = (Double_t)outputTree780 -> GetEntries();

  for (ULong64_t j = 0 ; j < events780 ; j++){
    outputTree780 -> GetEvent(j);
    if (j==3 || j == 4|| j==9)
      continue;
    
    UCNCountsArray780[counts_780] = HistIntegral780 - BASELINERATE780*(cycleValveCloseTime780 - cycleValveOpenTime780);
    UCNCountsErrArray780[counts_780] = sqrt(UCNCountsArray780[counts_780]);
    HistIntegralArray780[counts_780] = HistIntegral780;
    HistIntegralErrArray780[counts_780] = sqrt (HistIntegral780);
    
    avets11ValveOpenArray780[counts_780] = avets11ValveOpen780;
    avets12ValveOpenArray780[counts_780] = avets12ValveOpen780;
    avets14ValveOpenArray780[counts_780] = avets14ValveOpen780;
    avets16ValveOpenArray780[counts_780] = avets16ValveOpen780;
    ts11ValveOpenErr780[counts_780] = (maxts11ValveOpen780 - mints11ValveOpen780)/2;
    ts12ValveOpenErr780[counts_780] = (maxts12ValveOpen780 - mints12ValveOpen780)/2;
    ts14ValveOpenErr780[counts_780] = (maxts14ValveOpen780 - mints14ValveOpen780)/2;
    ts16ValveOpenErr780[counts_780] = (maxts16ValveOpen780 - mints16ValveOpen780)/2;
	    
    avecurArray780[counts_780] = avecur780;
    ErrcurArray780[counts_780] = (maxcur780 - mincur780)/2;
    
    delaytimeArray780[counts_780] = cycleDelayTime780;
    cycleNumberArray780[counts_780] = cycleNumber780;

    avets11All780 += avets11ValveOpen780;
    if (maxts11All780 < maxts11ValveOpen780)
      maxts11All780 = maxts11ValveOpen780;
    if (mints11All780 > mints11ValveOpen780)
      mints11All780 = mints11ValveOpen780;
    avets12All780 += avets12ValveOpen780;
    if (maxts12All780 < maxts12ValveOpen780)
      maxts12All780 = maxts12ValveOpen780;
    if (mints12All780 > mints12ValveOpen780)
      mints12All780 = mints12ValveOpen780;
    avets14All780 += avets14ValveOpen780;
    if (maxts14All780 < maxts14ValveOpen780)
      maxts14All780 = maxts14ValveOpen780;
    if (mints14All780 > mints14ValveOpen780)
      mints14All780 = mints14ValveOpen780;
    avets16All780 += avets16ValveOpen780;
    if (maxts16All780 < maxts16ValveOpen780)
      maxts16All780 = maxts16ValveOpen780;
    if (mints16All780 > mints16ValveOpen780)
      mints16All780 = mints16ValveOpen780;
    
    counts_780++;
  }

  avets11All780 = avets11All780/counts_780;
  avets12All780 = avets12All780/counts_780;
  avets14All780 = avets14All780/counts_780;
  avets16All780 = avets16All780/counts_780;
  ts11ErrAll780 = (maxts11All780 - mints11All780)/2;
  ts12ErrAll780 = (maxts12All780 - mints12All780)/2;
  ts14ErrAll780 = (maxts14All780 - mints14All780)/2;
  ts16ErrAll780 = (maxts16All780 - mints16All780)/2;

  ULong64_t events781;
  events781 = (Double_t)outputTree781 -> GetEntries();


  for (ULong64_t j = 0 ; j < events781 ; j++){
    outputTree781 -> GetEvent(j);

    UCNCountsArray781[counts_781] = HistIntegral781 - BASELINERATE781*(cycleValveCloseTime781 - cycleValveOpenTime781);
    UCNCountsErrArray781[counts_781] = sqrt(UCNCountsArray781[counts_781]);
    HistIntegralArray781[counts_781] = HistIntegral781;
    HistIntegralErrArray781[counts_781] = sqrt (HistIntegral781);
    
    avets11ValveOpenArray781[counts_781] = avets11ValveOpen781;
    avets12ValveOpenArray781[counts_781] = avets12ValveOpen781;
    avets14ValveOpenArray781[counts_781] = avets14ValveOpen781;
    avets16ValveOpenArray781[counts_781] = avets16ValveOpen781;
    ts11ValveOpenErr781[counts_781] = (maxts11ValveOpen781 - mints11ValveOpen781)/2;
    ts12ValveOpenErr781[counts_781] = (maxts12ValveOpen781 - mints12ValveOpen781)/2;
    ts14ValveOpenErr781[counts_781] = (maxts14ValveOpen781 - mints14ValveOpen781)/2;
    ts16ValveOpenErr781[counts_781] = (maxts16ValveOpen781 - mints16ValveOpen781)/2;
	    
    avecurArray781[counts_781] = avecur781;
    ErrcurArray781[counts_781] = (maxcur781 - mincur781)/2;
    
    delaytimeArray781[counts_781] = cycleDelayTime781;
    cycleNumberArray781[counts_781] = cycleNumber781;

    avets11All781 += avets11ValveOpen781;
    if (maxts11All781 < maxts11ValveOpen781)
      maxts11All781 = maxts11ValveOpen781;
    if (mints11All781 > mints11ValveOpen781)
      mints11All781 = mints11ValveOpen781;
    avets12All781 += avets12ValveOpen781;
    if (maxts12All781 < maxts12ValveOpen781)
      maxts12All781 = maxts12ValveOpen781;
    if (mints12All781 > mints12ValveOpen781)
      mints12All781 = mints12ValveOpen781;
    avets14All781 += avets14ValveOpen781;
    if (maxts14All781 < maxts14ValveOpen781)
      maxts14All781 = maxts14ValveOpen781;
    if (mints14All781 > mints14ValveOpen781)
      mints14All781 = mints14ValveOpen781;
    avets16All781 += avets16ValveOpen781;
    if (maxts16All781 < maxts16ValveOpen781)
      maxts16All781 = maxts16ValveOpen781;
    if (mints16All781 > mints16ValveOpen781)
      mints16All781 = mints16ValveOpen781;
    
    counts_781++;
  }

  avets11All781 = avets11All781/counts_781;
  avets12All781 = avets12All781/counts_781;
  avets14All781 = avets14All781/counts_781;
  avets16All781 = avets16All781/counts_781;
  ts11ErrAll781 = (maxts11All781 - mints11All781)/2;
  ts12ErrAll781 = (maxts12All781 - mints12All781)/2;
  ts14ErrAll781 = (maxts14All781 - mints14All781)/2;
  ts16ErrAll781 = (maxts16All781 - mints16All781)/2;


  ULong64_t events782;
  events782 = (Double_t)outputTree782 -> GetEntries();

  for (ULong64_t j = 0 ; j < events782 ; j++){
    outputTree782 -> GetEvent(j);
    if (j==4)
      continue;

    UCNCountsArray782[counts_782] = HistIntegral782 - BASELINERATE782*(cycleValveCloseTime782 - cycleValveOpenTime782);
    UCNCountsErrArray782[counts_782] = sqrt(UCNCountsArray782[counts_782]);
    HistIntegralArray782[counts_782] = HistIntegral782;
    HistIntegralErrArray782[counts_782] = sqrt (HistIntegral782);
    
    avets11ValveOpenArray782[counts_782] = avets11ValveOpen782;
    avets12ValveOpenArray782[counts_782] = avets12ValveOpen782;
    avets14ValveOpenArray782[counts_782] = avets14ValveOpen782;
    avets16ValveOpenArray782[counts_782] = avets16ValveOpen782;    
    ts11ValveOpenErr782[counts_782] = (maxts11ValveOpen782 - mints11ValveOpen782)/2;
    ts12ValveOpenErr782[counts_782] = (maxts12ValveOpen782 - mints12ValveOpen782)/2;
    ts14ValveOpenErr782[counts_782] = (maxts14ValveOpen782 - mints14ValveOpen782)/2;
    ts16ValveOpenErr782[counts_782] = (maxts16ValveOpen782 - mints16ValveOpen782)/2;
	    
    avecurArray782[counts_782] = avecur782;
    ErrcurArray782[counts_782] = (maxcur782 - mincur782)/2;
    
    delaytimeArray782[counts_782] = cycleDelayTime782;
    cycleNumberArray782[counts_782] = cycleNumber782;

    avets11All782 += avets11ValveOpen782;
    if (maxts11All782 < maxts11ValveOpen782)
      maxts11All782 = maxts11ValveOpen782;
    if (mints11All782 > mints11ValveOpen782)
      mints11All782 = mints11ValveOpen782;
    avets12All782 += avets12ValveOpen782;
    if (maxts12All782 < maxts12ValveOpen782)
      maxts12All782 = maxts12ValveOpen782;
    if (mints12All782 > mints12ValveOpen782)
      mints12All782 = mints12ValveOpen782;
    avets14All782 += avets14ValveOpen782;
    if (maxts14All782 < maxts14ValveOpen782)
      maxts14All782 = maxts14ValveOpen782;
    if (mints14All782 > mints14ValveOpen782)
      mints14All782 = mints14ValveOpen782;
    avets16All782 += avets16ValveOpen782;
    if (maxts16All782 < maxts16ValveOpen782)
      maxts16All782 = maxts16ValveOpen782;
    if (mints16All782 > mints16ValveOpen782)
      mints16All782 = mints16ValveOpen782;
    
    counts_782++;
  }

  avets11All782 = avets11All782/counts_782;
  avets12All782 = avets12All782/counts_782;
  avets14All782 = avets14All782/counts_782;
  avets16All782 = avets16All782/counts_782;
  ts11ErrAll782 = (maxts11All782 - mints11All782)/2;
  ts12ErrAll782 = (maxts12All782 - mints12All782)/2;
  ts14ErrAll782 = (maxts14All782 - mints14All782)/2;
  ts16ErrAll782 = (maxts16All782 - mints16All782)/2;


  
  ULong64_t events783;
  events783 = (Double_t)outputTree783 -> GetEntries();

  for (ULong64_t j = 0 ; j < events783 ; j++){
    outputTree783 -> GetEvent(j);

    UCNCountsArray783[counts_783] = HistIntegral783 - BASELINERATE783*(cycleValveCloseTime783 - cycleValveOpenTime783);
    UCNCountsErrArray783[counts_783] = sqrt(UCNCountsArray783[counts_783]);
    HistIntegralArray783[counts_783] = HistIntegral783;
    HistIntegralErrArray783[counts_783] = sqrt (HistIntegral783);
    
    avets11ValveOpenArray783[counts_783] = avets11ValveOpen783;
    avets12ValveOpenArray783[counts_783] = avets12ValveOpen783;
    avets14ValveOpenArray783[counts_783] = avets14ValveOpen783;
    avets16ValveOpenArray783[counts_783] = avets16ValveOpen783;
    ts11ValveOpenErr783[counts_783] = (maxts11ValveOpen783 - mints11ValveOpen783)/2;
    ts12ValveOpenErr783[counts_783] = (maxts12ValveOpen783 - mints12ValveOpen783)/2;
    ts14ValveOpenErr783[counts_783] = (maxts14ValveOpen783 - mints14ValveOpen783)/2;
    ts16ValveOpenErr783[counts_783] = (maxts16ValveOpen783 - mints16ValveOpen783)/2;
	    
    avecurArray783[counts_783] = avecur783;
    ErrcurArray783[counts_783] = (maxcur783 - mincur783)/2;
    
    delaytimeArray783[counts_783] = cycleDelayTime783;
    cycleNumberArray783[counts_783] = cycleNumber783;
    counts_783++;
  }


  ULong64_t events784;
  events784 = (Double_t)outputTree784 -> GetEntries();


  for (ULong64_t j = 0 ; j < events784 ; j++){
    outputTree784 -> GetEvent(j);
    if (j==1)
      continue;
    
    UCNCountsArray784[counts_784] = HistIntegral784 - BASELINERATE784*(cycleValveCloseTime784 - cycleValveOpenTime784);
    UCNCountsErrArray784[counts_784] = sqrt(UCNCountsArray784[counts_784]);
    HistIntegralArray784[counts_784] = HistIntegral784;
    HistIntegralErrArray784[counts_784] = sqrt (HistIntegral784);
    
    avets11ValveOpenArray784[counts_784] = avets11ValveOpen784;
    avets12ValveOpenArray784[counts_784] = avets12ValveOpen784;
    avets14ValveOpenArray784[counts_784] = avets14ValveOpen784;
    avets16ValveOpenArray784[counts_784] = avets16ValveOpen784;
    ts11ValveOpenErr784[counts_784] = (maxts11ValveOpen784 - mints11ValveOpen784)/2;
    ts12ValveOpenErr784[counts_784] = (maxts12ValveOpen784 - mints12ValveOpen784)/2;
    ts14ValveOpenErr784[counts_784] = (maxts14ValveOpen784 - mints14ValveOpen784)/2;
    ts16ValveOpenErr784[counts_784] = (maxts16ValveOpen784 - mints16ValveOpen784)/2;
	    
    avecurArray784[counts_784] = avecur784;
    ErrcurArray784[counts_784] = (maxcur784 - mincur784)/2;
    
    delaytimeArray784[counts_784] = cycleDelayTime784;
    cycleNumberArray784[counts_784] = cycleNumber784;

    avets11All784 += avets11ValveOpen784;
    if (maxts11All784 < maxts11ValveOpen784)
      maxts11All784 = maxts11ValveOpen784;
    if (mints11All784 > mints11ValveOpen784)
      mints11All784 = mints11ValveOpen784;
    avets12All784 += avets12ValveOpen784;
    if (maxts12All784 < maxts12ValveOpen784)
      maxts12All784 = maxts12ValveOpen784;
    if (mints12All784 > mints12ValveOpen784)
      mints12All784 = mints12ValveOpen784;
    avets14All784 += avets14ValveOpen784;
    if (maxts14All784 < maxts14ValveOpen784)
      maxts14All784 = maxts14ValveOpen784;
    if (mints14All784 > mints14ValveOpen784)
      mints14All784 = mints14ValveOpen784;
    avets16All784 += avets16ValveOpen784;
    if (maxts16All784 < maxts16ValveOpen784)
      maxts16All784 = maxts16ValveOpen784;
    if (mints16All784 > mints16ValveOpen784)
      mints16All784 = mints16ValveOpen784;
    
    counts_784++;
  }

  avets11All784 = avets11All784/counts_784;
  avets12All784 = avets12All784/counts_784;
  avets14All784 = avets14All784/counts_784;
  avets16All784 = avets16All784/counts_784;
  ts11ErrAll784 = (maxts11All784 - mints11All784)/2;
  ts12ErrAll784 = (maxts12All784 - mints12All784)/2;
  ts14ErrAll784 = (maxts14All784 - mints14All784)/2;
  ts16ErrAll784 = (maxts16All784 - mints16All784)/2;

  
  ULong64_t events785;
  events785 = (Double_t)outputTree785 -> GetEntries();


  for (ULong64_t j = 0 ; j < events785 ; j++){
    outputTree785 -> GetEvent(j);

    UCNCountsArray785[counts_785] = HistIntegral785 - BASELINERATE785*(cycleValveCloseTime785 - cycleValveOpenTime785);
    UCNCountsErrArray785[counts_785] = sqrt(UCNCountsArray785[counts_785]);
    HistIntegralArray785[counts_785] = HistIntegral785;
    HistIntegralErrArray785[counts_785] = sqrt (HistIntegral785);
    
    avets11ValveOpenArray785[counts_785] = avets11ValveOpen785;
    avets12ValveOpenArray785[counts_785] = avets12ValveOpen785;
    avets14ValveOpenArray785[counts_785] = avets14ValveOpen785;
    avets16ValveOpenArray785[counts_785] = avets16ValveOpen785;
    ts11ValveOpenErr785[counts_785] = (maxts11ValveOpen785 - mints11ValveOpen785)/2;
    ts12ValveOpenErr785[counts_785] = (maxts12ValveOpen785 - mints12ValveOpen785)/2;
    ts14ValveOpenErr785[counts_785] = (maxts14ValveOpen785 - mints14ValveOpen785)/2;
    ts16ValveOpenErr785[counts_785] = (maxts16ValveOpen785 - mints16ValveOpen785)/2;
	    
    avecurArray785[counts_785] = avecur785;
    ErrcurArray785[counts_785] = (maxcur785 - mincur785)/2;
    
    delaytimeArray785[counts_785] = cycleDelayTime785;
    cycleNumberArray785[counts_785] = cycleNumber785;

    avets11All785 += avets11ValveOpen785;
    if (maxts11All785 < maxts11ValveOpen785)
      maxts11All785 = maxts11ValveOpen785;
    if (mints11All785 > mints11ValveOpen785)
      mints11All785 = mints11ValveOpen785;
    avets12All785 += avets12ValveOpen785;
    if (maxts12All785 < maxts12ValveOpen785)
      maxts12All785 = maxts12ValveOpen785;
    if (mints12All785 > mints12ValveOpen785)
      mints12All785 = mints12ValveOpen785;
    avets14All785 += avets14ValveOpen785;
    if (maxts14All785 < maxts14ValveOpen785)
      maxts14All785 = maxts14ValveOpen785;
    if (mints14All785 > mints14ValveOpen785)
      mints14All785 = mints14ValveOpen785;
    avets16All785 += avets16ValveOpen785;
    if (maxts16All785 < maxts16ValveOpen785)
      maxts16All785 = maxts16ValveOpen785;
    if (mints16All785 > mints16ValveOpen785)
      mints16All785 = mints16ValveOpen785;
    
    counts_785++;
  }

  avets11All785 = avets11All785/counts_785;
  avets12All785 = avets12All785/counts_785;
  avets14All785 = avets14All785/counts_785;
  avets16All785 = avets16All785/counts_785;
  ts11ErrAll785 = (maxts11All785 - mints11All785)/2;
  ts12ErrAll785 = (maxts12All785 - mints12All785)/2;
  ts14ErrAll785 = (maxts14All785 - mints14All785)/2;
  ts16ErrAll785 = (maxts16All785 - mints16All785)/2;
  

  ULong64_t events786;
  events786 = (Double_t)outputTree786 -> GetEntries();

  for (ULong64_t j = 0 ; j < events786 ; j++){
    outputTree786 -> GetEvent(j);
 

    UCNCountsArray786[counts_786] = HistIntegral786 - BASELINERATE786*(cycleValveCloseTime786 - cycleValveOpenTime786);
    UCNCountsErrArray786[counts_786] = sqrt(UCNCountsArray786[counts_786]);
    HistIntegralArray786[counts_786] = HistIntegral786;
    HistIntegralErrArray786[counts_786] = sqrt (HistIntegral786);
    
    avets11ValveOpenArray786[counts_786] = avets11ValveOpen786;
    avets12ValveOpenArray786[counts_786] = avets12ValveOpen786;
    avets14ValveOpenArray786[counts_786] = avets14ValveOpen786;
    avets16ValveOpenArray786[counts_786] = avets16ValveOpen786;
    ts11ValveOpenErr786[counts_786] = (maxts11ValveOpen786 - mints11ValveOpen786)/2;
    ts12ValveOpenErr786[counts_786] = (maxts12ValveOpen786 - mints12ValveOpen786)/2;
    ts14ValveOpenErr786[counts_786] = (maxts14ValveOpen786 - mints14ValveOpen786)/2;
    ts16ValveOpenErr786[counts_786] = (maxts16ValveOpen786 - mints16ValveOpen786)/2;
	    
    avecurArray786[counts_786] = avecur786;
    ErrcurArray786[counts_786] = (maxcur786 - mincur786)/2;
    
    delaytimeArray786[counts_786] = cycleDelayTime786;
    cycleNumberArray786[counts_786] = cycleNumber786;

    avets11All786 += avets11ValveOpen786;
    if (maxts11All786 < maxts11ValveOpen786)
      maxts11All786 = maxts11ValveOpen786;
    if (mints11All786 > mints11ValveOpen786)
      mints11All786 = mints11ValveOpen786;
    avets12All786 += avets12ValveOpen786;
    if (maxts12All786 < maxts12ValveOpen786)
      maxts12All786 = maxts12ValveOpen786;
    if (mints12All786 > mints12ValveOpen786)
      mints12All786 = mints12ValveOpen786;
    avets14All786 += avets14ValveOpen786;
    if (maxts14All786 < maxts14ValveOpen786)
      maxts14All786 = maxts14ValveOpen786;
    if (mints14All786 > mints14ValveOpen786)
      mints14All786 = mints14ValveOpen786;
    avets16All786 += avets16ValveOpen786;
    if (maxts16All786 < maxts16ValveOpen786)
      maxts16All786 = maxts16ValveOpen786;
    if (mints16All786 > mints16ValveOpen786)
      mints16All786 = mints16ValveOpen786;
    
    counts_786++;
  }

  avets11All786 = avets11All786/counts_786;
  avets12All786 = avets12All786/counts_786;
  avets14All786 = avets14All786/counts_786;
  avets16All786 = avets16All786/counts_786;
  ts11ErrAll786 = (maxts11All786 - mints11All786)/2;
  ts12ErrAll786 = (maxts12All786 - mints12All786)/2;
  ts14ErrAll786 = (maxts14All786 - mints14All786)/2;
  ts16ErrAll786 = (maxts16All786 - mints16All786)/2;
  

  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(10000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 10, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************


  //*********************************
  //*********************************
  //              780
  //*********************************
  //*********************************
  TCanvas *c780 = new TCanvas("c780" , "c780" , 1200, 800);
  c780 ->SetLogy(); 
  TGraphErrors *gr780_delaycounts = new TGraphErrors(counts_780, delaytimeArray780 , UCNCountsArray780, 0, UCNCountsErrArray780);

  gr780_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_delaycounts -> SetMarkerStyle(20);
  gr780_delaycounts -> Fit(fit);
  storage780 = fit -> GetParameter(1);
  storageErr780 = fit -> GetParError(1);




  gr780_delaycounts -> Draw("Ap");


  TCanvas *c780_cycleNum = new TCanvas("c780_cycleNum" , "c780_cycleNum" , 1200, 800);
  c780_cycleNum -> Divide(2,2);
  TPad *p780 = c780_cycleNum->cd(1);
  p780->SetLogy(); 
  TGraphErrors *gr780_cyclecounts = new TGraphErrors (counts_780 , cycleNumberArray780, UCNCountsArray780, 0 , UCNCountsErrArray780);
  gr780_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr780_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr780_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_cyclecounts -> SetMarkerColor(2);
  gr780_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr780_cyclehist = new TGraphErrors(counts_780, cycleNumberArray780 , HistIntegralArray780, 0, HistIntegralErrArray780);

  gr780_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_cyclehist -> SetMarkerColor(1);
  gr780_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr780_cyclecounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr780_cyclehist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);

  
  gr780_cyclecounts -> Draw("Ap");
  gr780_cyclehist -> Draw("p");

  leg2-> Draw();

  c780_cycleNum -> cd(2);
 TGraphErrors *gr780_cycledelay = new TGraphErrors (counts_780 , cycleNumberArray780, delaytimeArray780, 0 , 0);
  gr780_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr780_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr780_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr780_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cycledelay -> SetMarkerStyle(20);

  gr780_cycledelay -> Draw("Ap");


  c780_cycleNum -> cd(3);

  TGraphErrors *gr780_cycletempValveOpen = new TGraphErrors (counts_780 , cycleNumberArray780, avets12ValveOpenArray780, 0 , ts12ValveOpenErr780);

  gr780_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempValveOpen -> SetMarkerStyle(20);
  gr780_cycletempValveOpen -> SetMarkerColor(1);
  gr780_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr780_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr780_cycletempValveOpen11 = new TGraphErrors (counts_780 , cycleNumberArray780, avets11ValveOpenArray780, 0 , ts11ValveOpenErr780);

  gr780_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr780_cycletempValveOpen11 -> SetMarkerColor(4);
  gr780_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr780_cycletempValveOpen14 = new TGraphErrors (counts_780 , cycleNumberArray780, avets14ValveOpenArray780, 0 , ts14ValveOpenErr780);

  gr780_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr780_cycletempValveOpen14 -> SetMarkerColor(3);
  gr780_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr780_cycletempValveOpen16 = new TGraphErrors (counts_780 , cycleNumberArray780, avets16ValveOpenArray780, 0 , ts16ValveOpenErr780);

  gr780_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr780_cycletempValveOpen16 -> SetMarkerColor(2);
  gr780_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  TLegend *temps = new TLegend (0.7, 0.7, 0.9, 0.9);
  temps -> AddEntry( gr780_cycletempValveOpen11, "TS11" , "p");
  temps -> AddEntry( gr780_cycletempValveOpen, "TS12" , "p");
  temps -> AddEntry( gr780_cycletempValveOpen14, "TS14" , "p");
  temps -> AddEntry( gr780_cycletempValveOpen16, "TS16" , "p");
  

  
  gr780_cycletempValveOpen -> Draw("Ap");
  gr780_cycletempValveOpen11 -> Draw("p");
  gr780_cycletempValveOpen14 -> Draw("p");
  gr780_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c780_cycleNum -> cd(4);
  TGraphErrors *gr780_cyclecur = new TGraphErrors (counts_780 , cycleNumberArray780 , avecurArray780, 0, ErrcurArray780 );
  gr780_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr780_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr780_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclecur -> SetMarkerStyle(20);
  gr780_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              781
  //*********************************
  //*********************************
 
  TCanvas *c781 = new TCanvas("c781" , "c781" , 1200, 800);
  c781 ->SetLogy(); 
  TGraphErrors *gr781_delaycounts = new TGraphErrors(counts_781, delaytimeArray781 , UCNCountsArray781, 0, UCNCountsErrArray781);

  gr781_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr781_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr781_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_delaycounts -> SetMarkerStyle(20);
  gr781_delaycounts -> Fit(fit);
  storage781 = fit -> GetParameter(1);
  storageErr781 = fit -> GetParError(1);




  gr781_delaycounts -> Draw("Ap");


  TCanvas *c781_cycleNum = new TCanvas("c781_cycleNum" , "c781_cycleNum" , 1200, 800);
  c781_cycleNum -> Divide(2,2);
  TPad *p781 = c781_cycleNum->cd(1);
  p781->SetLogy(); 
  TGraphErrors *gr781_cyclecounts = new TGraphErrors (counts_781 , cycleNumberArray781, UCNCountsArray781, 0 , UCNCountsErrArray781);
  gr781_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr781_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr781_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr781_cyclecounts -> SetMarkerColor(2);
  gr781_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr781_cyclehist = new TGraphErrors(counts_781, cycleNumberArray781 , HistIntegralArray781, 0, HistIntegralErrArray781);

  gr781_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr781_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr781_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr781_cyclehist -> SetMarkerColor(1);
  gr781_cyclehist -> SetMarkerStyle(25);

  
  gr781_cyclecounts -> Draw("Ap");
  gr781_cyclehist -> Draw("p");

  leg2-> Draw();

  c781_cycleNum -> cd(2);
 TGraphErrors *gr781_cycledelay = new TGraphErrors (counts_781 , cycleNumberArray781, delaytimeArray781, 0 , 0);
  gr781_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr781_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr781_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr781_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cycledelay -> SetMarkerStyle(20);

  gr781_cycledelay -> Draw("Ap");


  c781_cycleNum -> cd(3);

  TGraphErrors *gr781_cycletempValveOpen = new TGraphErrors (counts_781 , cycleNumberArray781, avets12ValveOpenArray781, 0 , ts12ValveOpenErr781);

  gr781_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempValveOpen -> SetMarkerStyle(20);
  gr781_cycletempValveOpen -> SetMarkerColor(1);
  gr781_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr781_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr781_cycletempValveOpen11 = new TGraphErrors (counts_781 , cycleNumberArray781, avets11ValveOpenArray781, 0 , ts11ValveOpenErr781);

  gr781_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr781_cycletempValveOpen11 -> SetMarkerColor(4);
  gr781_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr781_cycletempValveOpen14 = new TGraphErrors (counts_781 , cycleNumberArray781, avets14ValveOpenArray781, 0 , ts14ValveOpenErr781);

  gr781_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr781_cycletempValveOpen14 -> SetMarkerColor(3);
  gr781_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr781_cycletempValveOpen16 = new TGraphErrors (counts_781 , cycleNumberArray781, avets16ValveOpenArray781, 0 , ts16ValveOpenErr781);

  gr781_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr781_cycletempValveOpen16 -> SetMarkerColor(2);
  gr781_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr781_cycletempValveOpen -> Draw("Ap");
  gr781_cycletempValveOpen11 -> Draw("p");
  gr781_cycletempValveOpen14 -> Draw("p");
  gr781_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c781_cycleNum -> cd(4);
  TGraphErrors *gr781_cyclecur = new TGraphErrors (counts_781 , cycleNumberArray781 , avecurArray781, 0, ErrcurArray781 );
  gr781_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr781_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr781_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr781_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclecur -> SetMarkerStyle(20);
  gr781_cyclecur -> Draw("Ap");


 
  
  //*********************************
  //*********************************
  //              782
  //*********************************
  //*********************************
  TCanvas *c782 = new TCanvas("c782" , "c782" , 1200, 800);
  c782 ->SetLogy(); 
  TGraphErrors *gr782_delaycounts = new TGraphErrors(counts_782, delaytimeArray782 , UCNCountsArray782, 0, UCNCountsErrArray782);

  gr782_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr782_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr782_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_delaycounts -> SetMarkerStyle(20);
  gr782_delaycounts -> Fit(fit);
  storage782 = fit -> GetParameter(1);
  storageErr782 = fit -> GetParError(1);




  gr782_delaycounts -> Draw("Ap");


  TCanvas *c782_cycleNum = new TCanvas("c782_cycleNum" , "c782_cycleNum" , 1200, 800);
  c782_cycleNum -> Divide(2,2);
  TPad *p782 = c782_cycleNum->cd(1);
  p782->SetLogy(); 
  TGraphErrors *gr782_cyclecounts = new TGraphErrors (counts_782 , cycleNumberArray782, UCNCountsArray782, 0 , UCNCountsErrArray782);
  gr782_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr782_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr782_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr782_cyclecounts -> SetMarkerColor(2);
  gr782_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr782_cyclehist = new TGraphErrors(counts_782, cycleNumberArray782 , HistIntegralArray782, 0, HistIntegralErrArray782);

  gr782_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr782_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr782_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr782_cyclehist -> SetMarkerColor(1);
  gr782_cyclehist -> SetMarkerStyle(25);

  
  gr782_cyclecounts -> Draw("Ap");
  gr782_cyclehist -> Draw("p");

  leg2-> Draw();

  c782_cycleNum -> cd(2);
 TGraphErrors *gr782_cycledelay = new TGraphErrors (counts_782 , cycleNumberArray782, delaytimeArray782, 0 , 0);
  gr782_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr782_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr782_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr782_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cycledelay -> SetMarkerStyle(20);

  gr782_cycledelay -> Draw("Ap");


  c782_cycleNum -> cd(3);

  TGraphErrors *gr782_cycletempValveOpen = new TGraphErrors (counts_782 , cycleNumberArray782, avets12ValveOpenArray782, 0 , ts12ValveOpenErr782);

  gr782_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempValveOpen -> SetMarkerStyle(20);
  gr782_cycletempValveOpen -> SetMarkerColor(1);
  gr782_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr782_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr782_cycletempValveOpen11 = new TGraphErrors (counts_782 , cycleNumberArray782, avets11ValveOpenArray782, 0 , ts11ValveOpenErr782);

  gr782_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr782_cycletempValveOpen11 -> SetMarkerColor(4);
  gr782_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr782_cycletempValveOpen14 = new TGraphErrors (counts_782 , cycleNumberArray782, avets14ValveOpenArray782, 0 , ts14ValveOpenErr782);

  gr782_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr782_cycletempValveOpen14 -> SetMarkerColor(3);
  gr782_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr782_cycletempValveOpen16 = new TGraphErrors (counts_782 , cycleNumberArray782, avets16ValveOpenArray782, 0 , ts16ValveOpenErr782);

  gr782_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr782_cycletempValveOpen16 -> SetMarkerColor(2);
  gr782_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr782_cycletempValveOpen -> Draw("Ap");
  gr782_cycletempValveOpen11 -> Draw("p");
  gr782_cycletempValveOpen14 -> Draw("p");
  gr782_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c782_cycleNum -> cd(4);
  TGraphErrors *gr782_cyclecur = new TGraphErrors (counts_782 , cycleNumberArray782 , avecurArray782, 0, ErrcurArray782 );
  gr782_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr782_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr782_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr782_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclecur -> SetMarkerStyle(20);
  gr782_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              784
  //*********************************
  //*********************************
  TCanvas *c784 = new TCanvas("c784" , "c784" , 1200, 800);
  c784 ->SetLogy(); 
  TGraphErrors *gr784_delaycounts = new TGraphErrors(counts_784, delaytimeArray784 , UCNCountsArray784, 0, UCNCountsErrArray784);

  gr784_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr784_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr784_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_delaycounts -> SetMarkerStyle(20);
  gr784_delaycounts -> Fit(fit);
  storage784 = fit -> GetParameter(1);
  storageErr784 = fit -> GetParError(1);




  gr784_delaycounts -> Draw("Ap");


  TCanvas *c784_cycleNum = new TCanvas("c784_cycleNum" , "c784_cycleNum" , 1200, 800);
  c784_cycleNum -> Divide(2,2);
  TPad *p784 = c784_cycleNum->cd(1);
  p784->SetLogy(); 
  TGraphErrors *gr784_cyclecounts = new TGraphErrors (counts_784 , cycleNumberArray784, UCNCountsArray784, 0 , UCNCountsErrArray784);
  gr784_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr784_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr784_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr784_cyclecounts -> SetMarkerColor(2);
  gr784_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr784_cyclehist = new TGraphErrors(counts_784, cycleNumberArray784 , HistIntegralArray784, 0, HistIntegralErrArray784);

  gr784_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr784_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr784_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr784_cyclehist -> SetMarkerColor(1);
  gr784_cyclehist -> SetMarkerStyle(25);

  
  gr784_cyclecounts -> Draw("Ap");
  gr784_cyclehist -> Draw("p");

  leg2-> Draw();

  c784_cycleNum -> cd(2);
 TGraphErrors *gr784_cycledelay = new TGraphErrors (counts_784 , cycleNumberArray784, delaytimeArray784, 0 , 0);
  gr784_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr784_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr784_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr784_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cycledelay -> SetMarkerStyle(20);

  gr784_cycledelay -> Draw("Ap");


  c784_cycleNum -> cd(3);

  TGraphErrors *gr784_cycletempValveOpen = new TGraphErrors (counts_784 , cycleNumberArray784, avets12ValveOpenArray784, 0 , ts12ValveOpenErr784);

  gr784_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempValveOpen -> SetMarkerStyle(20);
  gr784_cycletempValveOpen -> SetMarkerColor(1);
  gr784_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr784_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr784_cycletempValveOpen11 = new TGraphErrors (counts_784 , cycleNumberArray784, avets11ValveOpenArray784, 0 , ts11ValveOpenErr784);

  gr784_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr784_cycletempValveOpen11 -> SetMarkerColor(4);
  gr784_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr784_cycletempValveOpen14 = new TGraphErrors (counts_784 , cycleNumberArray784, avets14ValveOpenArray784, 0 , ts14ValveOpenErr784);

  gr784_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr784_cycletempValveOpen14 -> SetMarkerColor(3);
  gr784_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr784_cycletempValveOpen16 = new TGraphErrors (counts_784 , cycleNumberArray784, avets16ValveOpenArray784, 0 , ts16ValveOpenErr784);

  gr784_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr784_cycletempValveOpen16 -> SetMarkerColor(2);
  gr784_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr784_cycletempValveOpen -> Draw("Ap");
  gr784_cycletempValveOpen11 -> Draw("p");
  gr784_cycletempValveOpen14 -> Draw("p");
  gr784_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c784_cycleNum -> cd(4);
  TGraphErrors *gr784_cyclecur = new TGraphErrors (counts_784 , cycleNumberArray784 , avecurArray784, 0, ErrcurArray784 );
  gr784_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr784_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr784_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr784_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclecur -> SetMarkerStyle(20);
  gr784_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              785
  //*********************************
  //*********************************
  TCanvas *c785 = new TCanvas("c785" , "c785" , 1200, 800);
  c785 ->SetLogy(); 
  TGraphErrors *gr785_delaycounts = new TGraphErrors(counts_785, delaytimeArray785 , UCNCountsArray785, 0, UCNCountsErrArray785);

  gr785_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr785_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr785_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_delaycounts -> SetMarkerStyle(20);
  gr785_delaycounts -> Fit(fit);
  storage785 = fit -> GetParameter(1);
  storageErr785 = fit -> GetParError(1);




  gr785_delaycounts -> Draw("Ap");


  TCanvas *c785_cycleNum = new TCanvas("c785_cycleNum" , "c785_cycleNum" , 1200, 800);
  c785_cycleNum -> Divide(2,2);
  TPad *p785 = c785_cycleNum->cd(1);
  p785->SetLogy(); 
  TGraphErrors *gr785_cyclecounts = new TGraphErrors (counts_785 , cycleNumberArray785, UCNCountsArray785, 0 , UCNCountsErrArray785);
  gr785_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr785_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr785_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr785_cyclecounts -> SetMarkerColor(2);
  gr785_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr785_cyclehist = new TGraphErrors(counts_785, cycleNumberArray785 , HistIntegralArray785, 0, HistIntegralErrArray785);

  gr785_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr785_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr785_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr785_cyclehist -> SetMarkerColor(1);
  gr785_cyclehist -> SetMarkerStyle(25);

  
  gr785_cyclecounts -> Draw("Ap");
  gr785_cyclehist -> Draw("p");

  leg2-> Draw();

  c785_cycleNum -> cd(2);
 TGraphErrors *gr785_cycledelay = new TGraphErrors (counts_785 , cycleNumberArray785, delaytimeArray785, 0 , 0);
  gr785_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr785_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr785_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr785_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cycledelay -> SetMarkerStyle(20);

  gr785_cycledelay -> Draw("Ap");


  c785_cycleNum -> cd(3);

  TGraphErrors *gr785_cycletempValveOpen = new TGraphErrors (counts_785 , cycleNumberArray785, avets12ValveOpenArray785, 0 , ts12ValveOpenErr785);

  gr785_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempValveOpen -> SetMarkerStyle(20);
  gr785_cycletempValveOpen -> SetMarkerColor(1);
  gr785_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr785_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr785_cycletempValveOpen11 = new TGraphErrors (counts_785 , cycleNumberArray785, avets11ValveOpenArray785, 0 , ts11ValveOpenErr785);

  gr785_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr785_cycletempValveOpen11 -> SetMarkerColor(4);
  gr785_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr785_cycletempValveOpen14 = new TGraphErrors (counts_785 , cycleNumberArray785, avets14ValveOpenArray785, 0 , ts14ValveOpenErr785);

  gr785_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr785_cycletempValveOpen14 -> SetMarkerColor(3);
  gr785_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr785_cycletempValveOpen16 = new TGraphErrors (counts_785 , cycleNumberArray785, avets16ValveOpenArray785, 0 , ts16ValveOpenErr785);

  gr785_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr785_cycletempValveOpen16 -> SetMarkerColor(2);
  gr785_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr785_cycletempValveOpen -> Draw("Ap");
  gr785_cycletempValveOpen11 -> Draw("p");
  gr785_cycletempValveOpen14 -> Draw("p");
  gr785_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c785_cycleNum -> cd(4);
  TGraphErrors *gr785_cyclecur = new TGraphErrors (counts_785 , cycleNumberArray785 , avecurArray785, 0, ErrcurArray785 );
  gr785_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr785_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr785_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr785_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclecur -> SetMarkerStyle(20);
  gr785_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              786
  //*********************************
  //*********************************
  TCanvas *c786 = new TCanvas("c786" , "c786" , 1200, 800);
  c786 ->SetLogy(); 
  TGraphErrors *gr786_delaycounts = new TGraphErrors(counts_786, delaytimeArray786 , UCNCountsArray786, 0, UCNCountsErrArray786);

  gr786_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr786_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr786_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_delaycounts -> SetMarkerStyle(20);
  gr786_delaycounts -> Fit(fit);
  storage786 = fit -> GetParameter(1);
  storageErr786 = fit -> GetParError(1);




  gr786_delaycounts -> Draw("Ap");


  TCanvas *c786_cycleNum = new TCanvas("c786_cycleNum" , "c786_cycleNum" , 1200, 800);
  c786_cycleNum -> Divide(2,2);
  TPad *p786 = c786_cycleNum->cd(1);
  p786->SetLogy(); 
  TGraphErrors *gr786_cyclecounts = new TGraphErrors (counts_786 , cycleNumberArray786, UCNCountsArray786, 0 , UCNCountsErrArray786);
  gr786_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr786_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr786_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  gr786_cyclecounts -> SetMarkerColor(2);
  gr786_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr786_cyclehist = new TGraphErrors(counts_786, cycleNumberArray786 , HistIntegralArray786, 0, HistIntegralErrArray786);

  gr786_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr786_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr786_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr786_cyclehist -> SetMarkerColor(1);
  gr786_cyclehist -> SetMarkerStyle(25);

  
  gr786_cyclecounts -> Draw("Ap");
  gr786_cyclehist -> Draw("p");

  leg2-> Draw();

  c786_cycleNum -> cd(2);
 TGraphErrors *gr786_cycledelay = new TGraphErrors (counts_786 , cycleNumberArray786, delaytimeArray786, 0 , 0);
  gr786_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr786_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr786_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr786_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cycledelay -> SetMarkerStyle(20);

  gr786_cycledelay -> Draw("Ap");


  c786_cycleNum -> cd(3);

  TGraphErrors *gr786_cycletempValveOpen = new TGraphErrors (counts_786 , cycleNumberArray786, avets12ValveOpenArray786, 0 , ts12ValveOpenErr786);

  gr786_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempValveOpen -> SetMarkerStyle(20);
  gr786_cycletempValveOpen -> SetMarkerColor(1);
  gr786_cycletempValveOpen -> GetYaxis() -> SetRangeUser(0.8 , 1.5);
  gr786_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr786_cycletempValveOpen11 = new TGraphErrors (counts_786 , cycleNumberArray786, avets11ValveOpenArray786, 0 , ts11ValveOpenErr786);

  gr786_cycletempValveOpen11 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempValveOpen11 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempValveOpen11 -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempValveOpen11 -> SetMarkerStyle(20);
  gr786_cycletempValveOpen11 -> SetMarkerColor(4);
  gr786_cycletempValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
  

  TGraphErrors *gr786_cycletempValveOpen14 = new TGraphErrors (counts_786 , cycleNumberArray786, avets14ValveOpenArray786, 0 , ts14ValveOpenErr786);

  gr786_cycletempValveOpen14 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempValveOpen14 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempValveOpen14 -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempValveOpen14 -> SetMarkerStyle(20);
  gr786_cycletempValveOpen14 -> SetMarkerColor(3);
  gr786_cycletempValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr786_cycletempValveOpen16 = new TGraphErrors (counts_786 , cycleNumberArray786, avets16ValveOpenArray786, 0 , ts16ValveOpenErr786);

  gr786_cycletempValveOpen16 -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempValveOpen16 -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempValveOpen16 -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempValveOpen16 -> SetMarkerStyle(20);
  gr786_cycletempValveOpen16 -> SetMarkerColor(2);
  gr786_cycletempValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
  
  

  
  gr786_cycletempValveOpen -> Draw("Ap");
  gr786_cycletempValveOpen11 -> Draw("p");
  gr786_cycletempValveOpen14 -> Draw("p");
  gr786_cycletempValveOpen16 -> Draw("p");
  temps -> Draw();
  

  c786_cycleNum -> cd(4);
  TGraphErrors *gr786_cyclecur = new TGraphErrors (counts_786 , cycleNumberArray786 , avecurArray786, 0, ErrcurArray786 );
  gr786_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr786_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr786_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr786_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclecur -> SetMarkerStyle(20);
  gr786_cyclecur -> Draw("Ap");



  //*********************************************************
  // overall
  // ********************************************************
  
  double StorageAll [100] = {storage780, storage781, storage782, storage784, storage785, storage786};
  double StorageErrAll[100] = {storageErr780, storageErr781, storageErr782,  storageErr784, storageErr785, storageErr786};
  double TS11All[100] = {avets11All780 , avets11All781 , avets11All782 , avets11All784 , avets11All785 , avets11All786 };
  double TS11ErrAll [100] = {ts11ErrAll780 , ts11ErrAll781 , ts11ErrAll782 , ts11ErrAll784 , ts11ErrAll785 , ts11ErrAll786}; 
  double TS12All[100] = {avets12All780 , avets12All781 , avets12All782 , avets12All784 , avets12All785 , avets12All786 };
  double TS12ErrAll [100] = {ts12ErrAll780 , ts12ErrAll781 , ts12ErrAll782 , ts12ErrAll784 , ts12ErrAll785 , ts12ErrAll786}; 		     
  double TS14All[100] = {avets14All780 , avets14All781 , avets14All782 , avets14All784 , avets14All785 , avets14All786 };
  double TS14ErrAll [100] = {ts14ErrAll780 , ts14ErrAll781 , ts14ErrAll782 , ts14ErrAll784 , ts14ErrAll785 , ts14ErrAll786};
  double TS16All[100] = {avets16All780 , avets16All781 , avets16All782 , avets16All784 , avets16All785 , avets16All786 };
  double TS16ErrAll [100] = {ts16ErrAll780 , ts16ErrAll781 , ts16ErrAll782 , ts16ErrAll784 , ts16ErrAll785 , ts16ErrAll786}; 


  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);

  TGraphErrors *grTS11 = new TGraphErrors (6 , TS11All, StorageAll, TS11ErrAll, StorageErrAll);
  grTS11 -> SetTitle("Storage Lifetime vs Isopure He-II Temperature");
  grTS11 -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  grTS11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)");
  grTS11 -> GetYaxis()-> SetRangeUser(0, 40);
  grTS11 -> GetXaxis()-> SetLimits(0.8 ,1.5);
  grTS11 -> GetXaxis() -> SetTitleSize(0.05);
  grTS11 -> GetXaxis() -> SetTitleOffset(1.0);
  grTS11 -> GetYaxis() -> SetTitleSize(0.05); 
  grTS11 -> GetYaxis() -> SetTitleOffset(0.9);
  grTS11 -> SetMarkerStyle(20);

  TGraphErrors *grTS12 = new TGraphErrors (6 , TS12All, StorageAll, TS12ErrAll, StorageErrAll);
  grTS12 -> SetMarkerStyle(20);

  TGraphErrors *grTS14 = new TGraphErrors (6 , TS14All, StorageAll, TS14ErrAll, StorageErrAll);
  grTS14 -> SetMarkerStyle(20);

  TGraphErrors *grTS16 = new TGraphErrors (6 , TS16All, StorageAll, TS16ErrAll, StorageErrAll);
  grTS16 -> SetMarkerStyle(20);


  grTS11 -> Draw("Ap");
  grTS12 -> Draw("p");
  grTS14 -> Draw("p");
  grTS16 -> Draw("p");
  
}
