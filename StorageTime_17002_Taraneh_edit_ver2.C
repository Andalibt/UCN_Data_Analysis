//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17002.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17002_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin532 = new TFile("outputTree_StorageTime_532.root","READ");
  TFile *fin533 = new TFile("outputTree_StorageTime_533.root","READ");
  TFile *fin534 = new TFile("outputTree_StorageTime_534.root","READ");
  TFile *fin535 = new TFile("outputTree_StorageTime_535.root","READ");
  TFile *fin536 = new TFile("outputTree_StorageTime_536.root","READ");
  TFile *fin537 = new TFile("outputTree_StorageTime_537.root","READ");
  TFile *fin538 = new TFile("outputTree_StorageTime_538.root","READ");
  TFile *fin539 = new TFile("outputTree_StorageTime_539.root","READ");
  TFile *fin540 = new TFile("outputTree_StorageTime_540.root","READ");

  
  TTree *outputTree532 = (TTree*) fin532 -> Get("cycle_info");
  TTree *outputTree533 = (TTree*) fin533 -> Get("cycle_info");
  TTree *outputTree534 = (TTree*) fin534 -> Get("cycle_info");
  TTree *outputTree535 = (TTree*) fin535 -> Get("cycle_info");
  TTree *outputTree536 = (TTree*) fin536 -> Get("cycle_info");
  TTree *outputTree537 = (TTree*) fin537 -> Get("cycle_info");
  TTree *outputTree538 = (TTree*) fin538 -> Get("cycle_info");
  TTree *outputTree539 = (TTree*) fin539 -> Get("cycle_info");
  TTree *outputTree540 = (TTree*) fin540 -> Get("cycle_info");
  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime532;
  double cycleDelayTime533;
  double cycleDelayTime534;
  double cycleDelayTime535;
  double cycleDelayTime536;
  double cycleDelayTime537;
  double cycleDelayTime538;
  double cycleDelayTime539;
  double cycleDelayTime540;


  outputTree532 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime532);
  outputTree533 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime533);
  outputTree534 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime534);
  outputTree535 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime535);
  outputTree536 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime536);
  outputTree537 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime537);
  outputTree538 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime538);
  outputTree539 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime539);
  outputTree540 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime540);


  // DELAY TIME (ARRAY)
  double delaytimeArray532 [100];
  double delaytimeArray533 [100];
  double delaytimeArray534 [100];
  double delaytimeArray535 [100];
  double delaytimeArray536 [100];
  double delaytimeArray537 [100];
  double delaytimeArray538 [100];
  double delaytimeArray539 [100];
  double delaytimeArray540 [100];

  // CYCLE NUMBER
  int cycleNumber532;
  int cycleNumber533;
  int cycleNumber534;
  int cycleNumber535;
  int cycleNumber536;
  int cycleNumber537;
  int cycleNumber538;
  int cycleNumber539;
  int cycleNumber540;

  outputTree532 -> SetBranchAddress ("cycleNumber" , &cycleNumber532);
  outputTree533 -> SetBranchAddress ("cycleNumber" , &cycleNumber533);
  outputTree534 -> SetBranchAddress ("cycleNumber" , &cycleNumber534);
  outputTree535 -> SetBranchAddress ("cycleNumber" , &cycleNumber535);
  outputTree536 -> SetBranchAddress ("cycleNumber" , &cycleNumber536);
  outputTree537 -> SetBranchAddress ("cycleNumber" , &cycleNumber537);
  outputTree538 -> SetBranchAddress ("cycleNumber" , &cycleNumber538);
  outputTree539 -> SetBranchAddress ("cycleNumber" , &cycleNumber539);
  outputTree540 -> SetBranchAddress ("cycleNumber" , &cycleNumber540);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray532 [100];
  double cycleNumberArray533 [100];
  double cycleNumberArray534 [100];
  double cycleNumberArray535 [100];
  double cycleNumberArray536 [100];
  double cycleNumberArray537 [100];
  double cycleNumberArray538 [100];
  double cycleNumberArray539 [100];
  double cycleNumberArray540 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral532;
  double UCNIntegral533;
  double UCNIntegral534;
  double UCNIntegral535;
  double UCNIntegral536;
  double UCNIntegral537;
  double UCNIntegral538;
  double UCNIntegral539;
  double UCNIntegral540;


  outputTree532 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral532);
  outputTree533 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral533);
  outputTree534 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral534);
  outputTree535 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral535);
  outputTree536 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral536);
  outputTree537 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral537);
  outputTree538 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral538);
  outputTree539 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral539);
  outputTree540 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral540);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray532 [100];
  double UCNIntegralArray533 [100];
  double UCNIntegralArray534 [100];
  double UCNIntegralArray535 [100];
  double UCNIntegralArray536 [100];
  double UCNIntegralArray537 [100];
  double UCNIntegralArray538 [100];
  double UCNIntegralArray539 [100];
  double UCNIntegralArray540 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr532;
  double UCNIntegralErr533;
  double UCNIntegralErr534;
  double UCNIntegralErr535;
  double UCNIntegralErr536;
  double UCNIntegralErr537;
  double UCNIntegralErr538;
  double UCNIntegralErr539;
  double UCNIntegralErr540;

  outputTree532 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr532);
  outputTree533 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr533);
  outputTree534 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr534);
  outputTree535 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr535);
  outputTree536 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr536);
  outputTree537 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr537);
  outputTree538 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr538);
  outputTree539 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr539);
  outputTree540 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr540);



  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray532 [100];
  double UCNIntegralErrArray533 [100];
  double UCNIntegralErrArray534 [100];
  double UCNIntegralErrArray535 [100];
  double UCNIntegralErrArray536 [100];
  double UCNIntegralErrArray537 [100];
  double UCNIntegralErrArray538 [100];
  double UCNIntegralErrArray539 [100];
  double UCNIntegralErrArray540 [100];

  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral532;
  double HistIntegral533;
  double HistIntegral534;
  double HistIntegral535;
  double HistIntegral536;
  double HistIntegral537;
  double HistIntegral538;
  double HistIntegral539;
  double HistIntegral540;

  outputTree532 -> SetBranchAddress ("HistIntegral" , &HistIntegral532); 
  outputTree533 -> SetBranchAddress ("HistIntegral" , &HistIntegral533);
  outputTree534 -> SetBranchAddress ("HistIntegral" , &HistIntegral534);
  outputTree535 -> SetBranchAddress ("HistIntegral" , &HistIntegral535);
  outputTree536 -> SetBranchAddress ("HistIntegral" , &HistIntegral536);
  outputTree537 -> SetBranchAddress ("HistIntegral" , &HistIntegral537);
  outputTree538 -> SetBranchAddress ("HistIntegral" , &HistIntegral538);
  outputTree539 -> SetBranchAddress ("HistIntegral" , &HistIntegral539);
  outputTree540 -> SetBranchAddress ("HistIntegral" , &HistIntegral540);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray532 [100];
  double HistIntegralArray533 [100];
  double HistIntegralArray534 [100];
  double HistIntegralArray535 [100];
  double HistIntegralArray536 [100];
  double HistIntegralArray537 [100];
  double HistIntegralArray538 [100];
  double HistIntegralArray539 [100];
  double HistIntegralArray540 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr532;
  double HistIntegralErr533;
  double HistIntegralErr534;
  double HistIntegralErr535;
  double HistIntegralErr536;
  double HistIntegralErr537;
  double HistIntegralErr538;
  double HistIntegralErr539;
  double HistIntegralErr540;

  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray532 [100];
  double HistIntegralErrArray533 [100];
  double HistIntegralErrArray534 [100];
  double HistIntegralErrArray535 [100];
  double HistIntegralErrArray536 [100];
  double HistIntegralErrArray537 [100];
  double HistIntegralErrArray538 [100];
  double HistIntegralErrArray539 [100];
  double HistIntegralErrArray540 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad532;
  double avets12Irrad533;
  double avets12Irrad534;
  double avets12Irrad535;
  double avets12Irrad536;
  double avets12Irrad537;
  double avets12Irrad538;
  double avets12Irrad539;
  double avets12Irrad540;

  outputTree532 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad532);
  outputTree533 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad533);
  outputTree534 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad534);
  outputTree535 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad535);
  outputTree536 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad536);
  outputTree537 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad537);
  outputTree538 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad538);
  outputTree539 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad539);
  outputTree540 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad540);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen532;
  double avets12ValveOpen533;
  double avets12ValveOpen534;
  double avets12ValveOpen535;
  double avets12ValveOpen536;
  double avets12ValveOpen537;
  double avets12ValveOpen538;
  double avets12ValveOpen539;
  double avets12ValveOpen540;

  outputTree532 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen532);
  outputTree533 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen533);
  outputTree534 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen534);
  outputTree535 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen535);
  outputTree536 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen536);
  outputTree537 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen537);
  outputTree538 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen538);
  outputTree539 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen539);
  outputTree540 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen540);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray532 [100];
  double avets12IrradArray533 [100];
  double avets12IrradArray534 [100];
  double avets12IrradArray535 [100];
  double avets12IrradArray536 [100];
  double avets12IrradArray537 [100];
  double avets12IrradArray538 [100];
  double avets12IrradArray539 [100];
  double avets12IrradArray540 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray532 [100];
  double avets12ValveOpenArray533 [100];
  double avets12ValveOpenArray534 [100];
  double avets12ValveOpenArray535 [100];
  double avets12ValveOpenArray536 [100];
  double avets12ValveOpenArray537 [100];
  double avets12ValveOpenArray538 [100];
  double avets12ValveOpenArray539 [100];
  double avets12ValveOpenArray540 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad532;
  double maxts12Irrad533;
  double maxts12Irrad534;
  double maxts12Irrad535;
  double maxts12Irrad536;
  double maxts12Irrad537;
  double maxts12Irrad538;
  double maxts12Irrad539;
  double maxts12Irrad540;

  outputTree532 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad532);
  outputTree533 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad533);
  outputTree534 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad534);
  outputTree535 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad535);
  outputTree536 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad536);
  outputTree537 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad537);
  outputTree538 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad538);
  outputTree539 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad539);
  outputTree540 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad540);

 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen532;
  double maxts12ValveOpen533;
  double maxts12ValveOpen534;
  double maxts12ValveOpen535;
  double maxts12ValveOpen536;
  double maxts12ValveOpen537;
  double maxts12ValveOpen538;
  double maxts12ValveOpen539;
  double maxts12ValveOpen540;

  outputTree532 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen532);
  outputTree533 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen533);
  outputTree534 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen534);
  outputTree535 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen535);
  outputTree536 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen536);
  outputTree537 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen537);
  outputTree538 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen538);
  outputTree539 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen539);
  outputTree540 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen540);

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray532 [100];
  double maxts12IrradArray533 [100];
  double maxts12IrradArray534 [100];
  double maxts12IrradArray535 [100];
  double maxts12IrradArray536 [100];
  double maxts12IrradArray537 [100];
  double maxts12IrradArray538 [100];
  double maxts12IrradArray539 [100];
  double maxts12IrradArray540 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray532 [100];
  double maxts12ValveOpenArray533 [100];
  double maxts12ValveOpenArray534 [100];
  double maxts12ValveOpenArray535 [100];
  double maxts12ValveOpenArray536 [100];
  double maxts12ValveOpenArray537 [100];
  double maxts12ValveOpenArray538 [100];
  double maxts12ValveOpenArray539 [100];
  double maxts12ValveOpenArray540 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad532;
  double mints12Irrad533;
  double mints12Irrad534;
  double mints12Irrad535;
  double mints12Irrad536;
  double mints12Irrad537;
  double mints12Irrad538;
  double mints12Irrad539;
  double mints12Irrad540;
  
  outputTree532 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad532);
  outputTree533 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad533);
  outputTree534 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad534);
  outputTree535 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad535);
  outputTree536 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad536);
  outputTree537 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad537);
  outputTree538 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad538);
  outputTree539 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad539);
  outputTree540 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad540);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen532;
  double mints12ValveOpen533;
  double mints12ValveOpen534;
  double mints12ValveOpen535;
  double mints12ValveOpen536;
  double mints12ValveOpen537;
  double mints12ValveOpen538;
  double mints12ValveOpen539;
  double mints12ValveOpen540;
  
  outputTree532 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen532);
  outputTree533 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen533);
  outputTree534 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen534);
  outputTree535 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen535);
  outputTree536 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen536);
  outputTree537 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen537);
  outputTree538 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen538);
  outputTree539 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen539);
  outputTree540 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen540);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray532 [100];
  double mints12IrradArray533 [100];
  double mints12IrradArray534 [100];
  double mints12IrradArray535 [100];
  double mints12IrradArray536 [100];
  double mints12IrradArray537 [100];
  double mints12IrradArray538 [100];
  double mints12IrradArray539 [100];
  double mints12IrradArray540 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray532 [100];
  double mints12ValveOpenArray533 [100];
  double mints12ValveOpenArray534 [100];
  double mints12ValveOpenArray535 [100];
  double mints12ValveOpenArray536 [100];
  double mints12ValveOpenArray537 [100];
  double mints12ValveOpenArray538 [100];
  double mints12ValveOpenArray539 [100];
  double mints12ValveOpenArray540 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr532 [100];
  double ts12IrradErr533 [100];
  double ts12IrradErr534 [100];
  double ts12IrradErr535 [100];
  double ts12IrradErr536 [100];
  double ts12IrradErr537 [100];
  double ts12IrradErr538 [100];
  double ts12IrradErr539 [100];
  double ts12IrradErr540 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr532 [100];
  double ts12ValveOpenErr533 [100];
  double ts12ValveOpenErr534 [100];
  double ts12ValveOpenErr535 [100];
  double ts12ValveOpenErr536 [100];
  double ts12ValveOpenErr537 [100];
  double ts12ValveOpenErr538 [100];
  double ts12ValveOpenErr539 [100];
  double ts12ValveOpenErr540 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur532;
  double avecur533;
  double avecur534;
  double avecur535;
  double avecur536;
  double avecur537;
  double avecur538;
  double avecur539;
  double avecur540;

  outputTree532 -> SetBranchAddress ("AVE_PRDCUR" , &avecur532);
  outputTree533 -> SetBranchAddress ("AVE_PRDCUR" , &avecur533);
  outputTree534 -> SetBranchAddress ("AVE_PRDCUR" , &avecur534);
  outputTree535 -> SetBranchAddress ("AVE_PRDCUR" , &avecur535);
  outputTree536 -> SetBranchAddress ("AVE_PRDCUR" , &avecur536);
  outputTree537 -> SetBranchAddress ("AVE_PRDCUR" , &avecur537);
  outputTree538 -> SetBranchAddress ("AVE_PRDCUR" , &avecur538);
  outputTree539 -> SetBranchAddress ("AVE_PRDCUR" , &avecur539);
  outputTree540 -> SetBranchAddress ("AVE_PRDCUR" , &avecur540);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray532 [100];
  double avecurArray533 [100];
  double avecurArray534 [100];
  double avecurArray535 [100];
  double avecurArray536 [100];
  double avecurArray537 [100];
  double avecurArray538 [100];
  double avecurArray539 [100];
  double avecurArray540 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur532;
  double maxcur533;
  double maxcur534;
  double maxcur535;
  double maxcur536;
  double maxcur537;
  double maxcur538;
  double maxcur539;
  double maxcur540;

  outputTree532 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur532);
  outputTree533 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur533);
  outputTree534 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur534);
  outputTree535 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur535);
  outputTree536 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur536);
  outputTree537 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur537);
  outputTree538 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur538);
  outputTree539 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur539);
  outputTree540 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur540);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray532 [100];
  double maxcurArray533 [100];
  double maxcurArray534 [100];
  double maxcurArray535 [100];
  double maxcurArray536 [100];
  double maxcurArray537 [100];
  double maxcurArray538 [100];
  double maxcurArray539 [100];
  double maxcurArray540 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur532;
  double mincur533;
  double mincur534;
  double mincur535;
  double mincur536;
  double mincur537;
  double mincur538;
  double mincur539;
  double mincur540;

  outputTree532 -> SetBranchAddress ("MIN_PRDCUR" , &mincur532);
  outputTree533 -> SetBranchAddress ("MIN_PRDCUR" , &mincur533);
  outputTree534 -> SetBranchAddress ("MIN_PRDCUR" , &mincur534);
  outputTree535 -> SetBranchAddress ("MIN_PRDCUR" , &mincur535);
  outputTree536 -> SetBranchAddress ("MIN_PRDCUR" , &mincur536);
  outputTree537 -> SetBranchAddress ("MIN_PRDCUR" , &mincur537);
  outputTree538 -> SetBranchAddress ("MIN_PRDCUR" , &mincur538);
  outputTree539 -> SetBranchAddress ("MIN_PRDCUR" , &mincur539);
  outputTree540 -> SetBranchAddress ("MIN_PRDCUR" , &mincur540);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray532 [100];
  double mincurArray533 [100];
  double mincurArray534 [100];
  double mincurArray535 [100];
  double mincurArray536 [100];
  double mincurArray537 [100];
  double mincurArray538 [100];
  double mincurArray539 [100];
  double mincurArray540 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray532 [100];
  double ErrcurArray533 [100];
  double ErrcurArray534 [100];
  double ErrcurArray535 [100];
  double ErrcurArray536 [100];
  double ErrcurArray537 [100];
  double ErrcurArray538 [100];
  double ErrcurArray539 [100];
  double ErrcurArray540 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline532;
  double Baseline533;
  double Baseline534;
  double Baseline535;
  double Baseline536;
  double Baseline537;
  double Baseline538;
  double Baseline539;
  double Baseline540;

  outputTree532 -> SetBranchAddress ("Baseline" , &Baseline532);
  outputTree533 -> SetBranchAddress ("Baseline" , &Baseline533);
  outputTree534 -> SetBranchAddress ("Baseline" , &Baseline534);
  outputTree535 -> SetBranchAddress ("Baseline" , &Baseline535);
  outputTree536 -> SetBranchAddress ("Baseline" , &Baseline536);
  outputTree537 -> SetBranchAddress ("Baseline" , &Baseline537);
  outputTree538 -> SetBranchAddress ("Baseline" , &Baseline538);
  outputTree539 -> SetBranchAddress ("Baseline" , &Baseline539);
  outputTree540 -> SetBranchAddress ("Baseline" , &Baseline540);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray532 [100];
  double BaselineArray533 [100];
  double BaselineArray534 [100];
  double BaselineArray535 [100];
  double BaselineArray536 [100];
  double BaselineArray537 [100];
  double BaselineArray538 [100];
  double BaselineArray539 [100];
  double BaselineArray540 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr532;
  double BaselineErr533;
  double BaselineErr534;
  double BaselineErr535;
  double BaselineErr536;
  double BaselineErr537;
  double BaselineErr538;
  double BaselineErr539;
  double BaselineErr540;
 
  outputTree532 -> SetBranchAddress ("BaselineErr" , &BaselineErr532);
  outputTree533 -> SetBranchAddress ("BaselineErr" , &BaselineErr533);
  outputTree534 -> SetBranchAddress ("BaselineErr" , &BaselineErr534);
  outputTree535 -> SetBranchAddress ("BaselineErr" , &BaselineErr535);
  outputTree536 -> SetBranchAddress ("BaselineErr" , &BaselineErr536);
  outputTree537 -> SetBranchAddress ("BaselineErr" , &BaselineErr537);
  outputTree538 -> SetBranchAddress ("BaselineErr" , &BaselineErr538);
  outputTree539 -> SetBranchAddress ("BaselineErr" , &BaselineErr539);
  outputTree540 -> SetBranchAddress ("BaselineErr" , &BaselineErr540);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray532 [100];
  double BaselineErrArray533 [100];
  double BaselineErrArray534 [100];
  double BaselineErrArray535 [100];
  double BaselineErrArray536 [100];
  double BaselineErrArray537 [100];
  double BaselineErrArray538 [100];
  double BaselineErrArray539 [100];
  double BaselineErrArray540 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad532;
  double BaselineIrrad533;
  double BaselineIrrad534;
  double BaselineIrrad535;
  double BaselineIrrad536;
  double BaselineIrrad537;
  double BaselineIrrad538;
  double BaselineIrrad539;
  double BaselineIrrad540;
 
  outputTree532 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad532);
  outputTree533 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad533);
  outputTree534 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad534);
  outputTree535 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad535);
  outputTree536 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad536);
  outputTree537 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad537);
  outputTree538 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad538);
  outputTree539 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad539);
  outputTree540 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad540);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray532 [100];
  double BaselineIrradArray533 [100];
  double BaselineIrradArray534 [100];
  double BaselineIrradArray535 [100];
  double BaselineIrradArray536 [100];
  double BaselineIrradArray537 [100];
  double BaselineIrradArray538 [100];
  double BaselineIrradArray539 [100];
  double BaselineIrradArray540 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr532;
  double BaselineIrradErr533;
  double BaselineIrradErr534;
  double BaselineIrradErr535;
  double BaselineIrradErr536;
  double BaselineIrradErr537;
  double BaselineIrradErr538;
  double BaselineIrradErr539;
  double BaselineIrradErr540;

  outputTree532 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr532);
  outputTree533 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr533);
  outputTree534 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr534);
  outputTree535 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr535);
  outputTree536 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr536);
  outputTree537 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr537);
  outputTree538 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr538);
  outputTree539 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr539);
  outputTree540 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr540);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray532 [100];
  double BaselineIrradErrArray533 [100];
  double BaselineIrradErrArray534 [100];
  double BaselineIrradErrArray535 [100];
  double BaselineIrradErrArray536 [100];
  double BaselineIrradErrArray537 [100];
  double BaselineIrradErrArray538 [100];
  double BaselineIrradErrArray539 [100];
  double BaselineIrradErrArray540 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime532;
  double FallTime533;
  double FallTime534;
  double FallTime535;
  double FallTime536;
  double FallTime537;
  double FallTime538;
  double FallTime539;
  double FallTime540;

  outputTree532 -> SetBranchAddress ("FallTime" , &FallTime532);
  outputTree533 -> SetBranchAddress ("FallTime" , &FallTime533);
  outputTree534 -> SetBranchAddress ("FallTime" , &FallTime534);
  outputTree535 -> SetBranchAddress ("FallTime" , &FallTime535);
  outputTree536 -> SetBranchAddress ("FallTime" , &FallTime536);
  outputTree537 -> SetBranchAddress ("FallTime" , &FallTime537);
  outputTree538 -> SetBranchAddress ("FallTime" , &FallTime538);
  outputTree539 -> SetBranchAddress ("FallTime" , &FallTime539);
  outputTree540 -> SetBranchAddress ("FallTime" , &FallTime540);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray532 [100];
  double FallTimeArray533 [100];
  double FallTimeArray534 [100];
  double FallTimeArray535 [100];
  double FallTimeArray536 [100];
  double FallTimeArray537 [100];
  double FallTimeArray538 [100];
  double FallTimeArray539 [100];
  double FallTimeArray540 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr532;
  double FallTimeErr533;
  double FallTimeErr534;
  double FallTimeErr535;
  double FallTimeErr536;
  double FallTimeErr537;
  double FallTimeErr538;
  double FallTimeErr539;
  double FallTimeErr540;

  outputTree532 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr532);
  outputTree533 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr533);
  outputTree534 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr534);
  outputTree535 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr535);
  outputTree536 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr536);
  outputTree537 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr537);
  outputTree538 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr538);
  outputTree539 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr539);
  outputTree540 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr540);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray532 [100];
  double FallTimeErrArray533 [100];
  double FallTimeErrArray534 [100];
  double FallTimeErrArray535 [100];
  double FallTimeErrArray536 [100];
  double FallTimeErrArray537 [100];
  double FallTimeErrArray538 [100];
  double FallTimeErrArray539 [100];
  double FallTimeErrArray540 [100];

  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime532;
  double RiseTime533;
  double RiseTime534;
  double RiseTime535;
  double RiseTime536;
  double RiseTime537;
  double RiseTime538;
  double RiseTime539;
  double RiseTime540;

  outputTree532 -> SetBranchAddress ("RiseTime" , &RiseTime532);
  outputTree533 -> SetBranchAddress ("RiseTime" , &RiseTime533);
  outputTree534 -> SetBranchAddress ("RiseTime" , &RiseTime534);
  outputTree535 -> SetBranchAddress ("RiseTime" , &RiseTime535);
  outputTree536 -> SetBranchAddress ("RiseTime" , &RiseTime536);
  outputTree537 -> SetBranchAddress ("RiseTime" , &RiseTime537);
  outputTree538 -> SetBranchAddress ("RiseTime" , &RiseTime538);
  outputTree539 -> SetBranchAddress ("RiseTime" , &RiseTime539);
  outputTree540 -> SetBranchAddress ("RiseTime" , &RiseTime540);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray532 [100];
  double RiseTimeArray533 [100];
  double RiseTimeArray534 [100];
  double RiseTimeArray535 [100];
  double RiseTimeArray536 [100];
  double RiseTimeArray537 [100];
  double RiseTimeArray538 [100];
  double RiseTimeArray539 [100];
  double RiseTimeArray540 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr532;
  double RiseTimeErr533;
  double RiseTimeErr534;
  double RiseTimeErr535;
  double RiseTimeErr536;
  double RiseTimeErr537;
  double RiseTimeErr538;
  double RiseTimeErr539;
  double RiseTimeErr540;

  outputTree532 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr532);
  outputTree533 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr533);
  outputTree534 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr534);
  outputTree535 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr535);
  outputTree536 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr536);
  outputTree537 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr537);
  outputTree538 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr538);
  outputTree539 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr539);
  outputTree540 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr540);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray532 [100];
  double RiseTimeErrArray533 [100];
  double RiseTimeErrArray534 [100];
  double RiseTimeErrArray535 [100];
  double RiseTimeErrArray536 [100];
  double RiseTimeErrArray537 [100];
  double RiseTimeErrArray538 [100];
  double RiseTimeErrArray539 [100];
  double RiseTimeErrArray540 [100];

  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad532;
  double aveAllts12Irrad533;
  double aveAllts12Irrad534;
  double aveAllts12Irrad535;
  double aveAllts12Irrad536;
  double aveAllts12Irrad537;
  double aveAllts12Irrad538;
  double aveAllts12Irrad539;
  double aveAllts12Irrad540;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad532;
  double aveAllErrts12Irrad533;
  double aveAllErrts12Irrad534;
  double aveAllErrts12Irrad535;
  double aveAllErrts12Irrad536;
  double aveAllErrts12Irrad537;
  double aveAllErrts12Irrad538;
  double aveAllErrts12Irrad539;
  double aveAllErrts12Irrad540;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad532;
  double maxAllts12Irrad533;
  double maxAllts12Irrad534;
  double maxAllts12Irrad535;
  double maxAllts12Irrad536;
  double maxAllts12Irrad537;
  double maxAllts12Irrad538;
  double maxAllts12Irrad539;
  double maxAllts12Irrad540;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad532;
  double minAllts12Irrad533;
  double minAllts12Irrad534;
  double minAllts12Irrad535;
  double minAllts12Irrad536;
  double minAllts12Irrad537;
  double minAllts12Irrad538;
  double minAllts12Irrad539;
  double minAllts12Irrad540;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage532;
  double storage533;
  double storage534;
  double storage535;
  double storage536;
  double storage537;
  double storage538;
  double storage539;
  double storage540;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr532;
  double storageErr533;
  double storageErr534;
  double storageErr535;
  double storageErr536;
  double storageErr537;
  double storageErr538;
  double storageErr539;
  double storageErr540;


  // BASELINE INTEGRAL NOT FROM THE FIT
  double BaselineIntegral532;
  double BaselineIntegral533;
  double BaselineIntegral534;
  double BaselineIntegral535;
  double BaselineIntegral536;
  double BaselineIntegral537;
  double BaselineIntegral538;
  double BaselineIntegral539;
  double BaselineIntegral540;

  outputTree532 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral532);
  outputTree533 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral533);
  outputTree534 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral534);
  outputTree535 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral535);
  outputTree536 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral536);
  outputTree537 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral537);
  outputTree538 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral538);
  outputTree539 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral539);
  outputTree540 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral540);


  // BASELINE INTEGRAL DURING IRRADIATION TIME NOT FROM THE FIT
  double BaselineIrradIntegral532;
  double BaselineIrradIntegral533;
  double BaselineIrradIntegral534;
  double BaselineIrradIntegral535;
  double BaselineIrradIntegral536;
  double BaselineIrradIntegral537;
  double BaselineIrradIntegral538;
  double BaselineIrradIntegral539;
  double BaselineIrradIntegral540;

  outputTree532 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral532);
  outputTree533 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral533);
  outputTree534 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral534);
  outputTree535 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral535);
  outputTree536 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral536);
  outputTree537 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral537);
  outputTree538 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral538);
  outputTree539 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral539);
  outputTree540 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral540);

  // NUMBER OF COUNTS IN EACH LOOP
  int counts_532 = 0;
  int counts_533 = 0;
  int counts_534 = 0;
  int counts_535 = 0;
  int counts_536 = 0;
  int counts_537 = 0;
  int counts_538 = 0;
  int counts_539 = 0;
  int counts_540 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  
  ULong64_t events532;
  events532 = (Double_t)outputTree532 -> GetEntries();

  for (ULong64_t j = 0 ; j < events532 ; j++){
    outputTree532 -> GetEvent(j);
    UCNIntegralArray532[counts_532] = UCNIntegral532;
    UCNIntegralErrArray532[counts_532] = UCNIntegralErr532;
    HistIntegralArray532[counts_532] = HistIntegral532;
    HistIntegralErrArray532[counts_532] = sqrt (HistIntegral532);
    avets12IrradArray532[counts_532] = avets12Irrad532;
    avets12ValveOpenArray532[counts_532] = avets12ValveOpen532;
    maxts12IrradArray532[counts_532] = maxts12Irrad532;
    maxts12ValveOpenArray532[counts_532] = maxts12ValveOpen532;
    mints12IrradArray532[counts_532] = mints12Irrad532; 
    mints12ValveOpenArray532[counts_532] = mints12ValveOpen532;
    ts12IrradErr532[counts_532] = (maxts12Irrad532 - mints12Irrad532)/2;
    ts12ValveOpenErr532[counts_532] = (maxts12ValveOpen532 - mints12ValveOpen532)/2;
    avecurArray532[counts_532] = avecur532;
    maxcurArray532[counts_532] = maxcur532;
    mincurArray532[counts_532] = mincur532;
    ErrcurArray532[counts_532] = (maxcur532 - mincur532)/2;
    delaytimeArray532[counts_532] = cycleDelayTime532;
    cycleNumberArray532[counts_532] = cycleNumber532;
    BaselineArray532[counts_532] = Baseline532;
    BaselineIrradArray532[counts_532] = BaselineIrrad532;
    BaselineIrradErrArray532[counts_532] = BaselineIrradErr532;
    FallTimeArray532[counts_532] = FallTime532;
    FallTimeErrArray532[counts_532] = FallTimeErr532;
    RiseTimeArray532[counts_532] = RiseTime532;
    RiseTimeErrArray532[counts_532] = RiseTimeErr532;
    aveAllts12Irrad532 += avets12Irrad532;
    maxAllts12Irrad532 += maxts12Irrad532;
    minAllts12Irrad532 += mints12Irrad532;
    UCNIntegralArrayAll[counts_532] = UCNIntegral532;
    UCNIntegralErrArrayAll[counts_532] = UCNIntegralErr532;
    delayTimeAll[counts_532] = cycleDelayTime532;
    counts_532++;
  }
  aveAllts12Irrad532 = aveAllts12Irrad532/counts_532;
  maxAllts12Irrad532 = maxAllts12Irrad532/counts_532;
  minAllts12Irrad532 = minAllts12Irrad532/counts_532;
  aveAllErrts12Irrad532 = (maxAllts12Irrad532 - minAllts12Irrad532)/2;

  ULong64_t events533;
  events533 = (Double_t)outputTree533 -> GetEntries();

  for (ULong64_t j = 0 ; j < events533 ; j++){
    outputTree533 -> GetEvent(j);
    UCNIntegralArray533[j] = UCNIntegral533;
    UCNIntegralErrArray533[j] = UCNIntegralErr533;
    HistIntegralArray533[j] = HistIntegral533;
    HistIntegralErrArray533[j] = sqrt (HistIntegral533);
    avets12IrradArray533[j] = avets12Irrad533;
    avets12ValveOpenArray533[j] = avets12ValveOpen533;
    maxts12IrradArray533[j] = maxts12Irrad533;
    maxts12ValveOpenArray533[j] = maxts12ValveOpen533;
    mints12IrradArray533[j] = mints12Irrad533; 
    mints12ValveOpenArray533[j] = mints12ValveOpen533;
    ts12IrradErr533[j] = (maxts12Irrad533 - mints12Irrad533)/2;
    ts12ValveOpenErr533[j] = (maxts12ValveOpen533 - mints12ValveOpen533)/2;
    avecurArray533[j] = avecur533;
    maxcurArray533[j] = maxcur533;
    mincurArray533[j] = mincur533;
    ErrcurArray533[j] = (maxcur533 - mincur533)/2;
    delaytimeArray533[j] = cycleDelayTime533;
    cycleNumberArray533[j] = cycleNumber533;
    BaselineArray533[j] = Baseline533;
    BaselineIrradArray533[j] = BaselineIrrad533;
    BaselineIrradErrArray533[j] = BaselineIrradErr533;
    FallTimeArray533[j] = FallTime533;
    FallTimeErrArray533[j] = FallTimeErr533;
    RiseTimeArray533[j] = RiseTime533;
    RiseTimeErrArray533[j] = RiseTimeErr533;
    aveAllts12Irrad533 += avets12Irrad533;
    maxAllts12Irrad533 += maxts12Irrad533;
    minAllts12Irrad533 += mints12Irrad533;
    cout << aveAllts12Irrad533 << endl;
    UCNIntegralArrayAll[counts_532+ counts_533] = UCNIntegral533;
    UCNIntegralErrArrayAll[counts_532+ counts_533] = UCNIntegralErr533;
    delayTimeAll[counts_532+ counts_533] = cycleDelayTime533;
    counts_533++;
  }
  aveAllts12Irrad533 = aveAllts12Irrad533/counts_533;
  maxAllts12Irrad533 = maxAllts12Irrad533/counts_533;
  minAllts12Irrad533 = minAllts12Irrad533/counts_533;
  aveAllErrts12Irrad533 = (maxAllts12Irrad533 - minAllts12Irrad533)/2;

  ULong64_t events534;
  events534 = (Double_t)outputTree534 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events534 ; j++){
    outputTree534 -> GetEvent(j);
    UCNIntegralArray534[counts_534] = UCNIntegral534;
    UCNIntegralErrArray534[counts_534] = UCNIntegralErr534;
    HistIntegralArray534[counts_534] = HistIntegral534;
    HistIntegralErrArray534[counts_534] = sqrt (HistIntegral534);
    avets12IrradArray534[counts_534] = avets12Irrad534;
    avets12ValveOpenArray534[counts_534] = avets12ValveOpen534;
    maxts12IrradArray534[counts_534] = maxts12Irrad534;
    maxts12ValveOpenArray534[counts_534] = maxts12ValveOpen534;
    mints12IrradArray534[counts_534] = mints12Irrad534; 
    mints12ValveOpenArray534[counts_534] = mints12ValveOpen534;
    ts12IrradErr534[counts_534] = (maxts12Irrad534 - mints12Irrad534)/2;
    ts12ValveOpenErr534[counts_534] = (maxts12ValveOpen534 - mints12ValveOpen534)/2;
    avecurArray534[counts_534] = avecur534;
    maxcurArray534[counts_534] = maxcur534;
    mincurArray534[counts_534] = mincur534;
    ErrcurArray534[counts_534] = (maxcur534 - mincur534)/2;
    delaytimeArray534[counts_534] = cycleDelayTime534;
    cycleNumberArray534[counts_534] = cycleNumber534;
    BaselineArray534[counts_534] = Baseline534;
    BaselineIrradArray534[counts_534] = BaselineIrrad534;
    BaselineIrradErrArray534[counts_534] = BaselineIrradErr534;
    FallTimeArray534[counts_534] = FallTime534;
    FallTimeErrArray534[counts_534] = FallTimeErr534;
    RiseTimeArray534[counts_534] = RiseTime534;
    RiseTimeErrArray534[counts_534] = RiseTimeErr534;
    aveAllts12Irrad534 += avets12Irrad534;
    maxAllts12Irrad534 += maxts12Irrad534;
    minAllts12Irrad534 += mints12Irrad534;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534] = UCNIntegral534;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534] = UCNIntegralErr534;
    delayTimeAll[counts_532+ counts_533+counts_534] = cycleDelayTime534;
    counts_534++;
  }
  aveAllts12Irrad534 = aveAllts12Irrad534/counts_534;
  maxAllts12Irrad534 = maxAllts12Irrad534/counts_534;
  minAllts12Irrad534 = minAllts12Irrad534/counts_534;
  aveAllErrts12Irrad534 = (maxAllts12Irrad534 - minAllts12Irrad534)/2;
  
  ULong64_t events535;
  events535 = (Double_t)outputTree535 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events535 ; j++){
    outputTree535 -> GetEvent(j);
    UCNIntegralArray535[j] = UCNIntegral535;
    UCNIntegralErrArray535[j] = UCNIntegralErr535;
    HistIntegralArray535[j] = HistIntegral535;
    HistIntegralErrArray535[j] = sqrt (HistIntegral535);
    avets12IrradArray535[j] = avets12Irrad535;
    avets12ValveOpenArray535[j] = avets12ValveOpen535;
    maxts12IrradArray535[j] = maxts12Irrad535;
    maxts12ValveOpenArray535[j] = maxts12ValveOpen535;
    mints12IrradArray535[j] = mints12Irrad535; 
    mints12ValveOpenArray535[j] = mints12ValveOpen535;
    ts12IrradErr535[j] = (maxts12Irrad535 - mints12Irrad535)/2;
    ts12ValveOpenErr535[j] = (maxts12ValveOpen535 - mints12ValveOpen535)/2;
    avecurArray535[j] = avecur535;
    maxcurArray535[j] = maxcur535;
    mincurArray535[j] = mincur535;
    ErrcurArray535[j] = (maxcur535 - mincur535)/2;
    delaytimeArray535[j] = cycleDelayTime535;
    cycleNumberArray535[j] = cycleNumber535;
    BaselineArray535[j] = Baseline535;
    BaselineIrradArray535[j] = BaselineIrrad535;
    BaselineIrradErrArray535[j] = BaselineIrradErr535;
    FallTimeArray535[j] = FallTime535;
    FallTimeErrArray535[j] = FallTimeErr535;
    RiseTimeArray535[j] = RiseTime535;
    RiseTimeErrArray535[j] = RiseTimeErr535;
    aveAllts12Irrad535 += avets12Irrad535;
    maxAllts12Irrad535 += maxts12Irrad535;
    minAllts12Irrad535 += mints12Irrad535;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535] = UCNIntegral535;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535] = UCNIntegralErr535;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535] = cycleDelayTime535;
    counts_535++;
  }
  aveAllts12Irrad535 = aveAllts12Irrad535/counts_535;
  maxAllts12Irrad535 = maxAllts12Irrad535/counts_535;
  minAllts12Irrad535 = minAllts12Irrad535/counts_535;
  aveAllErrts12Irrad535 = (maxAllts12Irrad535 - minAllts12Irrad535)/2;
  
  ULong64_t events536;
  events536 = (Double_t)outputTree536 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events536 ; j++){
    outputTree536 -> GetEvent(j);
    if (j == 4)
      continue;
    UCNIntegralArray536[counts_536] = UCNIntegral536;
    UCNIntegralErrArray536[counts_536] = UCNIntegralErr536;
    HistIntegralArray536[counts_536] = HistIntegral536;
    HistIntegralErrArray536[counts_536] = sqrt (HistIntegral536);
    avets12IrradArray536[counts_536] = avets12Irrad536;
    avets12ValveOpenArray536[counts_536] = avets12ValveOpen536;
    maxts12IrradArray536[counts_536] = maxts12Irrad536;
    maxts12ValveOpenArray536[counts_536] = maxts12ValveOpen536;
    mints12IrradArray536[counts_536] = mints12Irrad536; 
    mints12ValveOpenArray536[counts_536] = mints12ValveOpen536;
    ts12IrradErr536[counts_536] = (maxts12Irrad536 - mints12Irrad536)/2;
    ts12ValveOpenErr536[counts_536] = (maxts12ValveOpen536 - mints12ValveOpen536)/2;
    avecurArray536[counts_536] = avecur536;
    maxcurArray536[counts_536] = maxcur536;
    mincurArray536[counts_536] = mincur536;
    ErrcurArray536[counts_536] = (maxcur536 - mincur536)/2;
    delaytimeArray536[counts_536] = cycleDelayTime536;
    cycleNumberArray536[counts_536] = cycleNumber536;
    BaselineArray536[counts_536] = Baseline536;
    BaselineIrradArray536[counts_536] = BaselineIrrad536;
    BaselineIrradErrArray536[counts_536] = BaselineIrradErr536;
    FallTimeArray536[counts_536] = FallTime536;
    FallTimeErrArray536[counts_536] = FallTimeErr536;
    RiseTimeArray536[counts_536] = RiseTime536;
    RiseTimeErrArray536[counts_536] = RiseTimeErr536;
    aveAllts12Irrad536 += avets12Irrad536;
    maxAllts12Irrad536 += maxts12Irrad536;
    minAllts12Irrad536 += mints12Irrad536;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536] = UCNIntegral536;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536] = UCNIntegralErr536;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535+ counts_536] = cycleDelayTime536;
    counts_536++;
  }
  aveAllts12Irrad536 = aveAllts12Irrad536/counts_536;
  maxAllts12Irrad536 = maxAllts12Irrad536/counts_536;
  minAllts12Irrad536 = minAllts12Irrad536/counts_536;
  aveAllErrts12Irrad536 = (maxAllts12Irrad536 - minAllts12Irrad536)/2;

  ULong64_t events537;
  events537 = (Double_t)outputTree537 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events537 ; j++){
    outputTree537 -> GetEvent(j);
    UCNIntegralArray537[counts_537] = UCNIntegral537;
    UCNIntegralErrArray537[counts_537] = UCNIntegralErr537;
    HistIntegralArray537[counts_537] = HistIntegral537;
    HistIntegralErrArray537[counts_537] = sqrt (HistIntegral537);
    avets12IrradArray537[counts_537] = avets12Irrad537;
    avets12ValveOpenArray537[counts_537] = avets12ValveOpen537;
    maxts12IrradArray537[counts_537] = maxts12Irrad537;
    maxts12ValveOpenArray537[counts_537] = maxts12ValveOpen537;
    mints12IrradArray537[counts_537] = mints12Irrad537; 
    mints12ValveOpenArray537[counts_537] = mints12ValveOpen537;
    ts12IrradErr537[counts_537] = (maxts12Irrad537 - mints12Irrad537)/2;
    ts12ValveOpenErr537[counts_537] = (maxts12ValveOpen537 - mints12ValveOpen537)/2;
    avecurArray537[counts_537] = avecur537;
    maxcurArray537[counts_537] = maxcur537;
    mincurArray537[counts_537] = mincur537;
    ErrcurArray537[counts_537] = (maxcur537 - mincur5370)/2;
    delaytimeArray537[counts_537] = cycleDelayTime537;
    cycleNumberArray537[counts_537] = cycleNumber537;
    BaselineArray537[counts_537] = Baseline537;
    BaselineIrradArray537[counts_537] = BaselineIrrad537;
    BaselineIrradErrArray537[counts_537] = BaselineIrradErr537;
    FallTimeArray537[counts_537] = FallTime537;
    FallTimeErrArray537[counts_537] = FallTimeErr537;
    RiseTimeArray537[counts_537] = RiseTime537;
    RiseTimeErrArray537[counts_537] = RiseTimeErr537;
    aveAllts12Irrad537 += avets12Irrad537;
    maxAllts12Irrad537 += maxts12Irrad537;
    minAllts12Irrad537 += mints12Irrad537;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536 + counts_537] = UCNIntegral537;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536+counts_537] = UCNIntegralErr537;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535+ counts_536+counts_537] = cycleDelayTime537;
    counts_537++;
  }
  aveAllts12Irrad537 = aveAllts12Irrad537/counts_537;
  maxAllts12Irrad537 = maxAllts12Irrad537/counts_537;
  minAllts12Irrad537 = minAllts12Irrad537/counts_537;
  aveAllErrts12Irrad537 = (maxAllts12Irrad537 - minAllts12Irrad537)/2;

  ULong64_t events538;
  events538 = (Double_t)outputTree538 -> GetEntries();


  for (ULong64_t j = 0 ; j < events538 ; j++){
    outputTree538 -> GetEvent(j);
    UCNIntegralArray538[j] = UCNIntegral538;
    UCNIntegralErrArray538[j] = UCNIntegralErr538;
    HistIntegralArray538[j] = HistIntegral538;
    HistIntegralErrArray538[j] = sqrt (HistIntegral538);
    avets12IrradArray538[j] = avets12Irrad538;
    avets12ValveOpenArray538[j] = avets12ValveOpen538;
    maxts12IrradArray538[j] = maxts12Irrad538;
    maxts12ValveOpenArray538[j] = maxts12ValveOpen538;
    mints12IrradArray538[j] = mints12Irrad538; 
    mints12ValveOpenArray538[j] = mints12ValveOpen538;
    ts12IrradErr538[j] = (maxts12Irrad538 - mints12Irrad538)/2;
    ts12ValveOpenErr538[j] = (maxts12ValveOpen538 - mints12ValveOpen538)/2;
    avecurArray538[j] = avecur538;
    maxcurArray538[j] = maxcur538;
    mincurArray538[j] = mincur538;
    ErrcurArray538[j] = (maxcur538 - mincur538)/2;
    delaytimeArray538[j] = cycleDelayTime538;
    cycleNumberArray538[j] = cycleNumber538;
    BaselineArray538[j] = Baseline538;
    BaselineIrradArray538[j] = BaselineIrrad538;
    BaselineIrradErrArray538[j] = BaselineIrradErr538;
    FallTimeArray538[j] = FallTime538;
    FallTimeErrArray538[j] = FallTimeErr538;
    RiseTimeArray538[j] = RiseTime538;
    RiseTimeErrArray538[j] = RiseTimeErr538;
    aveAllts12Irrad538 += avets12Irrad538;
    maxAllts12Irrad538 += maxts12Irrad538;
    minAllts12Irrad538 += mints12Irrad538;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536 + counts_537+counts_538] = UCNIntegral538;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536+counts_537+counts_538] = UCNIntegralErr538;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535+ counts_536+counts_537+counts_538] = cycleDelayTime538;
    counts_538++;
  }
  aveAllts12Irrad538 = aveAllts12Irrad538/counts_538;
  maxAllts12Irrad538 = maxAllts12Irrad538/counts_538;
  minAllts12Irrad538 = minAllts12Irrad538/counts_538;
  aveAllErrts12Irrad538 = (maxAllts12Irrad538 - minAllts12Irrad538)/2;

  ULong64_t events539;
  events539 = (Double_t)outputTree539 -> GetEntries();

  for (ULong64_t j = 0 ; j < events539 ; j++){
    outputTree539 -> GetEvent(j);
    if (j==3)
      continue;
    UCNIntegralArray539[counts_539] = UCNIntegral539;
    UCNIntegralErrArray539[counts_539] = UCNIntegralErr539;
    HistIntegralArray539[counts_539] = HistIntegral539;
    HistIntegralErrArray539[counts_539] = sqrt (HistIntegral539);
    avets12IrradArray539[counts_539] = avets12Irrad539;
    avets12ValveOpenArray539[counts_539] = avets12ValveOpen539;
    maxts12IrradArray539[counts_539] = maxts12Irrad539;
    maxts12ValveOpenArray539[counts_539] = maxts12ValveOpen539;
    mints12IrradArray539[counts_539] = mints12Irrad539; 
    mints12ValveOpenArray539[counts_539] = mints12ValveOpen539;
    ts12IrradErr539[counts_539] = (maxts12Irrad539 - mints12Irrad539)/2;
    ts12ValveOpenErr539[counts_539] = (maxts12ValveOpen539 - mints12ValveOpen539)/2;
    avecurArray539[counts_539] = avecur539;
    maxcurArray539[counts_539] = maxcur539;
    mincurArray539[counts_539] = mincur539;
    ErrcurArray539[counts_539] = (maxcur539 - mincur539)/2;
    delaytimeArray539[counts_539] = cycleDelayTime539;
    cycleNumberArray539[counts_539] = cycleNumber539;
    BaselineArray539[counts_539] = Baseline539;
    BaselineIrradArray539[counts_539] = BaselineIrrad539;
    BaselineIrradErrArray539[counts_539] = BaselineIrradErr539;
    FallTimeArray539[counts_539] = FallTime539;
    FallTimeErrArray539[counts_539] = FallTimeErr539;
    RiseTimeArray539[counts_539] = RiseTime539;
    RiseTimeErrArray539[counts_539] = RiseTimeErr539;
    aveAllts12Irrad539 += avets12Irrad539;
    maxAllts12Irrad539 += maxts12Irrad539;
    minAllts12Irrad539 += mints12Irrad539;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536 + counts_537+counts_538+counts_539] = UCNIntegral539;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536+counts_537+counts_538+counts_539] = UCNIntegralErr539;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535+ counts_536+counts_537+counts_538+counts_539] = cycleDelayTime539;
    cout << cycleDelayTime539<< endl;
    counts_539++;
  }
  aveAllts12Irrad539 = aveAllts12Irrad539/counts_539;
  maxAllts12Irrad539 = maxAllts12Irrad539/counts_539;
  minAllts12Irrad539 = minAllts12Irrad539/counts_539;
  aveAllErrts12Irrad539 = (maxAllts12Irrad539 - minAllts12Irrad539)/2;

  ULong64_t events540;
  events540 = (Double_t)outputTree540 -> GetEntries();


  for (ULong64_t j = 0 ; j < events540 ; j++){
    outputTree540 -> GetEvent(j);
    //if (FallTime540 < 0.001)
    // continue;
    UCNIntegralArray540[counts_540] = UCNIntegral540;
    UCNIntegralErrArray540[counts_540] = UCNIntegralErr540;
    HistIntegralArray540[counts_540] = HistIntegral540;
    HistIntegralErrArray540[counts_540] = sqrt (HistIntegral540);
    avets12IrradArray540[counts_540] = avets12Irrad540;
    avets12ValveOpenArray540[counts_540] = avets12ValveOpen540;
    maxts12IrradArray540[counts_540] = maxts12Irrad540;
    maxts12ValveOpenArray540[counts_540] = maxts12ValveOpen540;
    mints12IrradArray540[counts_540] = mints12Irrad540; 
    mints12ValveOpenArray540[counts_540] = mints12ValveOpen540;
    ts12IrradErr540[counts_540] = (maxts12Irrad540 - mints12Irrad540)/2;
    ts12ValveOpenErr540[counts_540] = (maxts12ValveOpen540 - mints12ValveOpen540)/2;
    avecurArray540[counts_540] = avecur540;
    maxcurArray540[counts_540] = maxcur540;
    mincurArray540[counts_540] = mincur540;
    ErrcurArray540[counts_540] = (maxcur540 - mincur540)/2;
    delaytimeArray540[counts_540] = cycleDelayTime540;
    cycleNumberArray540[counts_540] = cycleNumber540;
    BaselineArray540[counts_540] = Baseline540;
    BaselineIrradArray540[counts_540] = BaselineIrrad540;
    BaselineIrradErrArray540[counts_540] = BaselineIrradErr540;
    FallTimeArray540[counts_540] = FallTime540;
    FallTimeErrArray540[counts_540] = FallTimeErr540;
    RiseTimeArray540[counts_540] = RiseTime540;
    RiseTimeErrArray540[counts_540] = RiseTimeErr540;
    aveAllts12Irrad540 += avets12Irrad540;
    maxAllts12Irrad540 += maxts12Irrad540;
    minAllts12Irrad540 += mints12Irrad540;
    UCNIntegralArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536 + counts_537+counts_538+counts_539+counts_540] = UCNIntegral540;
    UCNIntegralErrArrayAll[counts_532+ counts_533+counts_534+counts_535 + counts_536+counts_537+counts_538+counts_539+counts_540] = UCNIntegralErr540;
    delayTimeAll[counts_532+ counts_533+counts_534+counts_535+ counts_536+counts_537+counts_538+counts_539+counts_540] = cycleDelayTime540;
    counts_540++;
  }
  aveAllts12Irrad540 = aveAllts12Irrad540/counts_540;
  maxAllts12Irrad540 = maxAllts12Irrad540/counts_540;
  minAllts12Irrad540 = minAllts12Irrad540/counts_540;
  aveAllErrts12Irrad540 = (maxAllts12Irrad540 - minAllts12Irrad540)/2;


  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(100000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 10, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************


  //*********************************
  //*********************************
  //              532
  //*********************************
  //*********************************
  TCanvas *c532 = new TCanvas("c532" , "c532" , 1200, 800);
  c532 -> Divide(2,2);
  //c532 -> cd(1);
  TPad *p1 = c532->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr532_delaycounts = new TGraphErrors(counts_532, delaytimeArray532 , UCNIntegralArray532, 0, UCNIntegralErrArray532);

  gr532_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr532_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr532_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr532_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_delaycounts -> SetMarkerStyle(7);
  gr532_delaycounts -> Fit(fit);
  storage532 = fit -> GetParameter(1);
  storageErr532 = fit -> GetParError(1);
  
  TGraphErrors *gr532_delayhist = new TGraphErrors(counts_532, delaytimeArray532 , HistIntegralArray532, 0, HistIntegralErrArray532);

  gr532_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr532_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr532_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr532_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr532_delayhist -> SetMarkerColor(2);
  gr532_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr532_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr532_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr532_delaycounts -> Draw("Ap");
  gr532_delayhist -> Draw("p");
  leg2 -> Draw();

  //c532 -> cd(2);
  TPad *p2 = c532->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr532_tempIrradcounts = new TGraphErrors (counts_532 , avets12IrradArray532, UCNIntegralArray532 , ts12IrradErr532 , UCNIntegralErrArray532);
  gr532_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr532_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr532_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr532_tempValveOpencounts = new TGraphErrors (counts_532 , avets12ValveOpenArray532, UCNIntegralArray532 , ts12ValveOpenErr532 , UCNIntegralErrArray532);
  gr532_tempValveOpencounts -> SetMarkerStyle(7);
  gr532_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr532_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr532_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr532_tempIrradcounts -> Draw("Ap");
  gr532_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c532 -> cd(3);
  TGraphErrors *gr532_delaytempIrrad = new TGraphErrors (counts_532 , delaytimeArray532, avets12IrradArray532, 0 , ts12IrradErr532);

  gr532_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr532_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr532_delaytempIrrad -> SetMarkerStyle(7);
  gr532_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr532_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr532_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr532_delaytempValveOpen = new TGraphErrors (counts_532 , delaytimeArray532, avets12ValveOpenArray532, 0 , ts12ValveOpenErr532);

  gr532_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr532_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr532_delaytempValveOpen -> SetMarkerStyle(7);
  gr532_delaytempValveOpen -> SetMarkerColor(2);
  gr532_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr532_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr532_delaytempIrrad -> Draw("AP");
  gr532_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c532->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr532_curcounts = new TGraphErrors (counts_532 , avecurArray532, UCNIntegralArray532 , ErrcurArray532 , UCNIntegralErrArray532);
  gr532_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr532_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr532_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr532_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr532_curhist = new TGraphErrors (counts_532 , avecurArray532, UCNIntegralArray532 , ErrcurArray532 , UCNIntegralErrArray532);
  gr532_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr532_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr532_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr532_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr532_curhist -> SetMarkerColor(2);
  gr532_curhist -> SetMarkerStyle(7);

  gr532_curcounts -> Draw("Ap");
  gr532_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c532_cycleNum = new TCanvas("c532_cycleNum" , "c532_cycleNum" , 1200, 800);
  c532_cycleNum -> Divide(2,2);
  TPad *p5 = c532_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr532_cyclecounts = new TGraphErrors (counts_532 , cycleNumberArray532, UCNIntegralArray532, 0 , UCNIntegralErrArray532);
  gr532_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr532_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr532_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr532_cyclehist = new TGraphErrors(counts_532, cycleNumberArray532 , HistIntegralArray532, 0, HistIntegralErrArray532);

  gr532_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr532_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr532_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr532_cyclehist -> SetMarkerColor(2);
  gr532_cyclehist -> SetMarkerStyle(7);

  gr532_cyclecounts -> Draw("Ap");
  gr532_cyclehist -> Draw("p");

  leg2-> Draw();

  c532_cycleNum -> cd(2);
 TGraphErrors *gr532_cycledelay = new TGraphErrors (counts_532 , cycleNumberArray532, delaytimeArray532, 0 , 0);
  gr532_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr532_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr532_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr532_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cycledelay -> SetMarkerStyle(7);

  gr532_cycledelay -> Draw("Ap");


  c532_cycleNum -> cd(3);
  TGraphErrors *gr532_cycletempIrrad = new TGraphErrors (counts_532 , cycleNumberArray532, avets12IrradArray532, 0 , ts12IrradErr532);

  gr532_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr532_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr532_cycletempIrrad -> SetMarkerStyle(7);
  gr532_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr532_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr532_cycletempValveOpen = new TGraphErrors (counts_532 , cycleNumberArray532, avets12ValveOpenArray532, 0 , ts12ValveOpenErr532);

  gr532_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr532_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr532_cycletempValveOpen -> SetMarkerStyle(7);
  gr532_cycletempValveOpen -> SetMarkerColor(2);
  gr532_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr532_cycletempIrrad -> Draw("AP");
  gr532_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c532_cycleNum -> cd(4);
  TGraphErrors *gr532_cyclecur = new TGraphErrors (counts_532 , cycleNumberArray532 , avecurArray532, 0, ErrcurArray532 );
  gr532_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr532_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr532_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclecur -> SetMarkerStyle(7);
  gr532_cyclecur -> Draw("Ap");


  TCanvas *c532_cycleNumFit = new TCanvas("c532_cycleNumFit" , "c532_cycleNumFit" , 1200, 800);
  c532_cycleNumFit -> Divide(2,2);

  c532_cycleNumFit -> cd(1);
  TGraphErrors *gr532_cyclefall = new TGraphErrors (counts_532, cycleNumberArray532, FallTimeArray532 , 0, FallTimeErrArray532);

  gr532_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr532_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr532_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclefall -> SetMarkerStyle(7);
  gr532_cyclefall -> Draw("Ap");


  c532_cycleNumFit -> cd(2);
  TGraphErrors *gr532_cyclebaseline = new TGraphErrors (counts_532, cycleNumberArray532, BaselineArray532 , 0, BaselineErrArray532);

  gr532_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr532_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr532_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclebaseline -> SetMarkerStyle(7);
  gr532_cyclebaseline -> Draw("Ap");

  c532_cycleNumFit -> cd(3);
  TGraphErrors *gr532_cyclebaselineirrad = new TGraphErrors (counts_532, cycleNumberArray532, BaselineIrradArray532 , 0, BaselineIrradErrArray532);

  gr532_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr532_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr532_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclebaselineirrad -> SetMarkerStyle(7);
  gr532_cyclebaselineirrad -> Draw("Ap");

  c532_cycleNumFit -> cd(4);
  TGraphErrors *gr532_cyclerise = new TGraphErrors (counts_532, cycleNumberArray532, RiseTimeArray532 , 0, RiseTimeErrArray532);

  gr532_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr532_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr532_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclerise -> SetMarkerStyle(7);
  gr532_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              533
  //*********************************
  //*********************************
  TCanvas *c533 = new TCanvas("c533" , "c533" , 1200, 800);
  c533 -> Divide(2,2);
  //c533 -> cd(1);
  TPad *p533_1 = c533->cd(1);
  p533_1->SetLogy(); 
  TGraphErrors *gr533_delaycounts = new TGraphErrors(counts_533, delaytimeArray533 , UCNIntegralArray533, 0, UCNIntegralErrArray533);

  gr533_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr533_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr533_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr533_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr533_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_delaycounts -> SetMarkerStyle(7);
  gr533_delaycounts -> Fit(fit);
  storage533 = fit -> GetParameter(1);
  storageErr533 = fit -> GetParError(1);
  
  TGraphErrors *gr533_delayhist = new TGraphErrors(counts_533, delaytimeArray533 , HistIntegralArray533, 0, HistIntegralErrArray533);

  gr533_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr533_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr533_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr533_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr533_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr533_delayhist -> SetMarkerColor(2);
  gr533_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr533_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr533_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr533_delaycounts -> Draw("Ap");
  gr533_delayhist -> Draw("p");
  leg2 -> Draw();

  //c533 -> cd(2);
  TPad *p533_2 = c533->cd(2);
  p533_2->SetLogy(); 
  TGraphErrors *gr533_tempIrradcounts = new TGraphErrors (counts_533 , avets12IrradArray533, UCNIntegralArray533 , ts12IrradErr533 , UCNIntegralErrArray533);
  gr533_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr533_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr533_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr533_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr533_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr533_tempValveOpencounts = new TGraphErrors (counts_533 , avets12ValveOpenArray533, UCNIntegralArray533 , ts12ValveOpenErr533 , UCNIntegralErrArray533);
  gr533_tempValveOpencounts -> SetMarkerStyle(7);
  gr533_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr533_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr533_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr533_tempIrradcounts -> Draw("Ap");
  gr533_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c533 -> cd(3);
  TGraphErrors *gr533_delaytempIrrad = new TGraphErrors (counts_533 , delaytimeArray533, avets12IrradArray533, 0 , ts12IrradErr533);

  gr533_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr533_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr533_delaytempIrrad -> SetMarkerStyle(7);
  gr533_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr533_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr533_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr533_delaytempValveOpen = new TGraphErrors (counts_533 , delaytimeArray533, avets12ValveOpenArray533, 0 , ts12ValveOpenErr533);

  gr533_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr533_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr533_delaytempValveOpen -> SetMarkerStyle(7);
  gr533_delaytempValveOpen -> SetMarkerColor(2);
  gr533_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr533_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr533_delaytempIrrad -> Draw("AP");
  gr533_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p533_3 = c533->cd(4);
  p533_3->SetLogy(); 
  TGraphErrors *gr533_curcounts = new TGraphErrors (counts_533 , avecurArray533, UCNIntegralArray533 , ErrcurArray533 , UCNIntegralErrArray533);
  gr533_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr533_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr533_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr533_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr533_curhist = new TGraphErrors (counts_533 , avecurArray533, UCNIntegralArray533 , ErrcurArray533 , UCNIntegralErrArray533);
  gr533_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr533_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr533_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr533_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr533_curhist -> SetMarkerColor(2);
  gr533_curhist -> SetMarkerStyle(7);

  gr533_curcounts -> Draw("Ap");
  gr533_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c533_cycleNum = new TCanvas("c533_cycleNum" , "c533_cycleNum" , 1200, 800);
  c533_cycleNum -> Divide(2,2);
  TPad *p533_4 = c533_cycleNum->cd(1);
  p533_4->SetLogy(); 
  TGraphErrors *gr533_cyclecounts = new TGraphErrors (counts_533 , cycleNumberArray533, UCNIntegralArray533, 0 , UCNIntegralErrArray533);
  gr533_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr533_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr533_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr533_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr533_cyclehist = new TGraphErrors(counts_533, cycleNumberArray533 , HistIntegralArray533, 0, HistIntegralErrArray533);

  gr533_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr533_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr533_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr533_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr533_cyclehist -> SetMarkerColor(2);
  gr533_cyclehist -> SetMarkerStyle(7);

  gr533_cyclecounts -> Draw("Ap");
  gr533_cyclehist -> Draw("p");

  leg2-> Draw();

  c533_cycleNum -> cd(2);
 TGraphErrors *gr533_cycledelay = new TGraphErrors (counts_533 , cycleNumberArray533, delaytimeArray533, 0 , 0);
  gr533_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr533_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr533_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr533_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cycledelay -> SetMarkerStyle(7);

  gr533_cycledelay -> Draw("Ap");


  c533_cycleNum -> cd(3);
  TGraphErrors *gr533_cycletempIrrad = new TGraphErrors (counts_533 , cycleNumberArray533, avets12IrradArray533, 0 , ts12IrradErr533);

  gr533_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr533_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr533_cycletempIrrad -> SetMarkerStyle(7);
  gr533_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr533_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr533_cycletempValveOpen = new TGraphErrors (counts_533 , cycleNumberArray533, avets12ValveOpenArray533, 0 , ts12ValveOpenErr533);

  gr533_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr533_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr533_cycletempValveOpen -> SetMarkerStyle(7);
  gr533_cycletempValveOpen -> SetMarkerColor(2);
  gr533_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr533_cycletempIrrad -> Draw("AP");
  gr533_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c533_cycleNum -> cd(4);
  TGraphErrors *gr533_cyclecur = new TGraphErrors (counts_533 , cycleNumberArray533 , avecurArray533, 0, ErrcurArray533 );
  gr533_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr533_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr533_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclecur -> SetMarkerStyle(7);
  gr533_cyclecur -> Draw("Ap");


  TCanvas *c533_cycleNumFit = new TCanvas("c533_cycleNumFit" , "c533_cycleNumFit" , 1200, 800);
  c533_cycleNumFit -> Divide(2,2);

  c533_cycleNumFit -> cd(1);
  TGraphErrors *gr533_cyclefall = new TGraphErrors (counts_533, cycleNumberArray533, FallTimeArray533 , 0, FallTimeErrArray533);

  gr533_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr533_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr533_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclefall -> SetMarkerStyle(7);
  gr533_cyclefall -> Draw("Ap");


  c533_cycleNumFit -> cd(2);
  TGraphErrors *gr533_cyclebaseline = new TGraphErrors (counts_533, cycleNumberArray533, BaselineArray533 , 0, BaselineErrArray533);

  gr533_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr533_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr533_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclebaseline -> SetMarkerStyle(7);
  gr533_cyclebaseline -> Draw("Ap");

  c533_cycleNumFit -> cd(3);
  TGraphErrors *gr533_cyclebaselineirrad = new TGraphErrors (counts_533, cycleNumberArray533, BaselineIrradArray533 , 0, BaselineIrradErrArray533);

  gr533_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr533_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr533_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclebaselineirrad -> SetMarkerStyle(7);
  gr533_cyclebaselineirrad -> Draw("Ap");

  c533_cycleNumFit -> cd(4);
  TGraphErrors *gr533_cyclerise = new TGraphErrors (counts_533, cycleNumberArray533, RiseTimeArray533 , 0, RiseTimeErrArray533);

  gr533_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr533_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr533_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclerise -> SetMarkerStyle(7);
  gr533_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              534
  //*********************************
  //*********************************
  TCanvas *c534 = new TCanvas("c534" , "c534" , 1200, 800);
  c534 -> Divide(2,2);
  //c534 -> cd(1);
  TPad *p534_1 = c534->cd(1);
  p534_1->SetLogy(); 
  TGraphErrors *gr534_delaycounts = new TGraphErrors(counts_534, delaytimeArray534 , UCNIntegralArray534, 0, UCNIntegralErrArray534);

  gr534_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr534_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr534_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr534_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr534_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_delaycounts -> SetMarkerStyle(7);
  gr534_delaycounts -> Fit(fit);
  storage534 = fit -> GetParameter(1);
  storageErr534 = fit -> GetParError(1);
  
  TGraphErrors *gr534_delayhist = new TGraphErrors(counts_534, delaytimeArray534 , HistIntegralArray534, 0, HistIntegralErrArray534);

  gr534_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr534_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr534_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr534_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr534_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr534_delayhist -> SetMarkerColor(2);
  gr534_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr534_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr534_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr534_delaycounts -> Draw("Ap");
  gr534_delayhist -> Draw("p");
  leg2 -> Draw();

  //c534 -> cd(2);
  TPad *p534_2 = c534->cd(2);
  p534_2->SetLogy(); 
  TGraphErrors *gr534_tempIrradcounts = new TGraphErrors (counts_534 , avets12IrradArray534, UCNIntegralArray534 , ts12IrradErr534 , UCNIntegralErrArray534);
  gr534_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr534_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr534_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr534_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr534_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr534_tempValveOpencounts = new TGraphErrors (counts_534 , avets12ValveOpenArray534, UCNIntegralArray534 , ts12ValveOpenErr534 , UCNIntegralErrArray534);
  gr534_tempValveOpencounts -> SetMarkerStyle(7);
  gr534_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr534_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr534_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr534_tempIrradcounts -> Draw("Ap");
  gr534_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c534 -> cd(3);
  TGraphErrors *gr534_delaytempIrrad = new TGraphErrors (counts_534 , delaytimeArray534, avets12IrradArray534, 0 , ts12IrradErr534);

  gr534_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr534_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr534_delaytempIrrad -> SetMarkerStyle(7);
  gr534_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr534_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr534_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr534_delaytempValveOpen = new TGraphErrors (counts_534 , delaytimeArray534, avets12ValveOpenArray534, 0 , ts12ValveOpenErr534);

  gr534_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr534_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr534_delaytempValveOpen -> SetMarkerStyle(7);
  gr534_delaytempValveOpen -> SetMarkerColor(2);
  gr534_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr534_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr534_delaytempIrrad -> Draw("AP");
  gr534_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p534_3 = c534->cd(4);
  p534_3->SetLogy(); 
  TGraphErrors *gr534_curcounts = new TGraphErrors (counts_534 , avecurArray534, UCNIntegralArray534 , ErrcurArray534 , UCNIntegralErrArray534);
  gr534_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr534_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr534_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr534_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr534_curhist = new TGraphErrors (counts_534 , avecurArray534, UCNIntegralArray534 , ErrcurArray534 , UCNIntegralErrArray534);
  gr534_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr534_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr534_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr534_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr534_curhist -> SetMarkerColor(2);
  gr534_curhist -> SetMarkerStyle(7);

  gr534_curcounts -> Draw("Ap");
  gr534_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c534_cycleNum = new TCanvas("c534_cycleNum" , "c534_cycleNum" , 1200, 800);
  c534_cycleNum -> Divide(2,2);
  TPad *p534_4 = c534_cycleNum->cd(1);
  p534_4->SetLogy(); 
  TGraphErrors *gr534_cyclecounts = new TGraphErrors (counts_534 , cycleNumberArray534, UCNIntegralArray534, 0 , UCNIntegralErrArray534);
  gr534_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr534_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr534_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr534_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr534_cyclehist = new TGraphErrors(counts_534, cycleNumberArray534 , HistIntegralArray534, 0, HistIntegralErrArray534);

  gr534_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr534_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr534_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr534_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr534_cyclehist -> SetMarkerColor(2);
  gr534_cyclehist -> SetMarkerStyle(7);

  gr534_cyclecounts -> Draw("Ap");
  gr534_cyclehist -> Draw("p");

  leg2-> Draw();

  c534_cycleNum -> cd(2);
 TGraphErrors *gr534_cycledelay = new TGraphErrors (counts_534 , cycleNumberArray534, delaytimeArray534, 0 , 0);
  gr534_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr534_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr534_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr534_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cycledelay -> SetMarkerStyle(7);

  gr534_cycledelay -> Draw("Ap");


  c534_cycleNum -> cd(3);
  TGraphErrors *gr534_cycletempIrrad = new TGraphErrors (counts_534 , cycleNumberArray534, avets12IrradArray534, 0 , ts12IrradErr534);

  gr534_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr534_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr534_cycletempIrrad -> SetMarkerStyle(7);
  gr534_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr534_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr534_cycletempValveOpen = new TGraphErrors (counts_534 , cycleNumberArray534, avets12ValveOpenArray534, 0 , ts12ValveOpenErr534);

  gr534_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr534_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr534_cycletempValveOpen -> SetMarkerStyle(7);
  gr534_cycletempValveOpen -> SetMarkerColor(2);
  gr534_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr534_cycletempIrrad -> Draw("AP");
  gr534_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c534_cycleNum -> cd(4);
  TGraphErrors *gr534_cyclecur = new TGraphErrors (counts_534 , cycleNumberArray534 , avecurArray534, 0, ErrcurArray534 );
  gr534_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr534_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr534_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclecur -> SetMarkerStyle(7);
  gr534_cyclecur -> Draw("Ap");


  TCanvas *c534_cycleNumFit = new TCanvas("c534_cycleNumFit" , "c534_cycleNumFit" , 1200, 800);
  c534_cycleNumFit -> Divide(2,2);

  c534_cycleNumFit -> cd(1);
  TGraphErrors *gr534_cyclefall = new TGraphErrors (counts_534, cycleNumberArray534, FallTimeArray534 , 0, FallTimeErrArray534);

  gr534_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr534_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr534_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclefall -> SetMarkerStyle(7);
  gr534_cyclefall -> Draw("Ap");


  c534_cycleNumFit -> cd(2);
  TGraphErrors *gr534_cyclebaseline = new TGraphErrors (counts_534, cycleNumberArray534, BaselineArray534 , 0, BaselineErrArray534);

  gr534_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr534_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr534_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclebaseline -> SetMarkerStyle(7);
  gr534_cyclebaseline -> Draw("Ap");

  c534_cycleNumFit -> cd(3);
  TGraphErrors *gr534_cyclebaselineirrad = new TGraphErrors (counts_534, cycleNumberArray534, BaselineIrradArray534 , 0, BaselineIrradErrArray534);

  gr534_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr534_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr534_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclebaselineirrad -> SetMarkerStyle(7);
  gr534_cyclebaselineirrad -> Draw("Ap");

  c534_cycleNumFit -> cd(4);
  TGraphErrors *gr534_cyclerise = new TGraphErrors (counts_534, cycleNumberArray534, RiseTimeArray534 , 0, RiseTimeErrArray534);

  gr534_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr534_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr534_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclerise -> SetMarkerStyle(7);
  gr534_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              535
  //*********************************
  //*********************************
  TCanvas *c535 = new TCanvas("c535" , "c535" , 1200, 800);
  c535 -> Divide(2,2);
  //c535 -> cd(1);
  TPad *p535_1 = c535->cd(1);
  p535_1->SetLogy(); 
  TGraphErrors *gr535_delaycounts = new TGraphErrors(counts_535, delaytimeArray535 , UCNIntegralArray535, 0, UCNIntegralErrArray535);

  gr535_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr535_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr535_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr535_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr535_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_delaycounts -> SetMarkerStyle(7);
  gr535_delaycounts -> Fit(fit);
  storage535 = fit -> GetParameter(1);
  storageErr535 = fit -> GetParError(1);
  
  TGraphErrors *gr535_delayhist = new TGraphErrors(counts_535, delaytimeArray535 , HistIntegralArray535, 0, HistIntegralErrArray535);

  gr535_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr535_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr535_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr535_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr535_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr535_delayhist -> SetMarkerColor(2);
  gr535_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr535_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr535_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr535_delaycounts -> Draw("Ap");
  gr535_delayhist -> Draw("p");
  leg2 -> Draw();

  //c535 -> cd(2);
  TPad *p535_2 = c535->cd(2);
  p535_2->SetLogy(); 
  TGraphErrors *gr535_tempIrradcounts = new TGraphErrors (counts_535 , avets12IrradArray535, UCNIntegralArray535 , ts12IrradErr535 , UCNIntegralErrArray535);
  gr535_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr535_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr535_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr535_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr535_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr535_tempValveOpencounts = new TGraphErrors (counts_535 , avets12ValveOpenArray535, UCNIntegralArray535 , ts12ValveOpenErr535 , UCNIntegralErrArray535);
  gr535_tempValveOpencounts -> SetMarkerStyle(7);
  gr535_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr535_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr535_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr535_tempIrradcounts -> Draw("Ap");
  gr535_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c535 -> cd(3);
  TGraphErrors *gr535_delaytempIrrad = new TGraphErrors (counts_535 , delaytimeArray535, avets12IrradArray535, 0 , ts12IrradErr535);

  gr535_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr535_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr535_delaytempIrrad -> SetMarkerStyle(7);
  gr535_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr535_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr535_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr535_delaytempValveOpen = new TGraphErrors (counts_535 , delaytimeArray535, avets12ValveOpenArray535, 0 , ts12ValveOpenErr535);

  gr535_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr535_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr535_delaytempValveOpen -> SetMarkerStyle(7);
  gr535_delaytempValveOpen -> SetMarkerColor(2);
  gr535_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr535_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr535_delaytempIrrad -> Draw("AP");
  gr535_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p535_3 = c535->cd(4);
  p535_3->SetLogy(); 
  TGraphErrors *gr535_curcounts = new TGraphErrors (counts_535 , avecurArray535, UCNIntegralArray535 , ErrcurArray535 , UCNIntegralErrArray535);
  gr535_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr535_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr535_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr535_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr535_curhist = new TGraphErrors (counts_535 , avecurArray535, UCNIntegralArray535 , ErrcurArray535 , UCNIntegralErrArray535);
  gr535_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr535_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr535_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr535_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr535_curhist -> SetMarkerColor(2);
  gr535_curhist -> SetMarkerStyle(7);

  gr535_curcounts -> Draw("Ap");
  gr535_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c535_cycleNum = new TCanvas("c535_cycleNum" , "c535_cycleNum" , 1200, 800);
  c535_cycleNum -> Divide(2,2);
  TPad *p535_4 = c535_cycleNum->cd(1);
  p535_4->SetLogy(); 
  TGraphErrors *gr535_cyclecounts = new TGraphErrors (counts_535 , cycleNumberArray535, UCNIntegralArray535, 0 , UCNIntegralErrArray535);
  gr535_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr535_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr535_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr535_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr535_cyclehist = new TGraphErrors(counts_535, cycleNumberArray535 , HistIntegralArray535, 0, HistIntegralErrArray535);

  gr535_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr535_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr535_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr535_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr535_cyclehist -> SetMarkerColor(2);
  gr535_cyclehist -> SetMarkerStyle(7);

  gr535_cyclecounts -> Draw("Ap");
  gr535_cyclehist -> Draw("p");

  leg2-> Draw();

  c535_cycleNum -> cd(2);
 TGraphErrors *gr535_cycledelay = new TGraphErrors (counts_535 , cycleNumberArray535, delaytimeArray535, 0 , 0);
  gr535_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr535_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr535_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr535_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cycledelay -> SetMarkerStyle(7);

  gr535_cycledelay -> Draw("Ap");


  c535_cycleNum -> cd(3);
  TGraphErrors *gr535_cycletempIrrad = new TGraphErrors (counts_535 , cycleNumberArray535, avets12IrradArray535, 0 , ts12IrradErr535);

  gr535_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr535_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr535_cycletempIrrad -> SetMarkerStyle(7);
  gr535_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr535_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr535_cycletempValveOpen = new TGraphErrors (counts_535 , cycleNumberArray535, avets12ValveOpenArray535, 0 , ts12ValveOpenErr535);

  gr535_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr535_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr535_cycletempValveOpen -> SetMarkerStyle(7);
  gr535_cycletempValveOpen -> SetMarkerColor(2);
  gr535_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr535_cycletempIrrad -> Draw("AP");
  gr535_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c535_cycleNum -> cd(4);
  TGraphErrors *gr535_cyclecur = new TGraphErrors (counts_535 , cycleNumberArray535 , avecurArray535, 0, ErrcurArray535 );
  gr535_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr535_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr535_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclecur -> SetMarkerStyle(7);
  gr535_cyclecur -> Draw("Ap");


  TCanvas *c535_cycleNumFit = new TCanvas("c535_cycleNumFit" , "c535_cycleNumFit" , 1200, 800);
  c535_cycleNumFit -> Divide(2,2);

  c535_cycleNumFit -> cd(1);
  TGraphErrors *gr535_cyclefall = new TGraphErrors (counts_535, cycleNumberArray535, FallTimeArray535 , 0, FallTimeErrArray535);

  gr535_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr535_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr535_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclefall -> SetMarkerStyle(7);
  gr535_cyclefall -> Draw("Ap");


  c535_cycleNumFit -> cd(2);
  TGraphErrors *gr535_cyclebaseline = new TGraphErrors (counts_535, cycleNumberArray535, BaselineArray535 , 0, BaselineErrArray535);

  gr535_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr535_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr535_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclebaseline -> SetMarkerStyle(7);
  gr535_cyclebaseline -> Draw("Ap");

  c535_cycleNumFit -> cd(3);
  TGraphErrors *gr535_cyclebaselineirrad = new TGraphErrors (counts_535, cycleNumberArray535, BaselineIrradArray535 , 0, BaselineIrradErrArray535);

  gr535_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr535_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr535_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclebaselineirrad -> SetMarkerStyle(7);
  gr535_cyclebaselineirrad -> Draw("Ap");

  c535_cycleNumFit -> cd(4);
  TGraphErrors *gr535_cyclerise = new TGraphErrors (counts_535, cycleNumberArray535, RiseTimeArray535 , 0, RiseTimeErrArray535);

  gr535_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr535_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr535_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclerise -> SetMarkerStyle(7);
  gr535_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              536
  //*********************************
  //*********************************
  TCanvas *c536 = new TCanvas("c536" , "c536" , 1200, 800);
  c536 -> Divide(2,2);
  //c536 -> cd(1);
  TPad *p536_1 = c536->cd(1);
  p536_1->SetLogy(); 
  TGraphErrors *gr536_delaycounts = new TGraphErrors(counts_536, delaytimeArray536 , UCNIntegralArray536, 0, UCNIntegralErrArray536);

  gr536_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr536_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr536_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr536_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_delaycounts -> SetMarkerStyle(7);
  gr536_delaycounts -> Fit(fit);
  storage536 = fit -> GetParameter(1);
  storageErr536 = fit -> GetParError(1);
  
  TGraphErrors *gr536_delayhist = new TGraphErrors(counts_536, delaytimeArray536 , HistIntegralArray536, 0, HistIntegralErrArray536);

  gr536_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr536_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr536_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr536_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr536_delayhist -> SetMarkerColor(2);
  gr536_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr536_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr536_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr536_delaycounts -> Draw("Ap");
  gr536_delayhist -> Draw("p");
  leg2 -> Draw();

  //c536 -> cd(2);
  TPad *p536_2 = c536->cd(2);
  p536_2->SetLogy(); 
  TGraphErrors *gr536_tempIrradcounts = new TGraphErrors (counts_536 , avets12IrradArray536, UCNIntegralArray536 , ts12IrradErr536 , UCNIntegralErrArray536);
  gr536_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr536_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr536_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr536_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr536_tempValveOpencounts = new TGraphErrors (counts_536 , avets12ValveOpenArray536, UCNIntegralArray536 , ts12ValveOpenErr536 , UCNIntegralErrArray536);
  gr536_tempValveOpencounts -> SetMarkerStyle(7);
  gr536_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr536_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr536_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr536_tempIrradcounts -> Draw("Ap");
  gr536_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c536 -> cd(3);
  TGraphErrors *gr536_delaytempIrrad = new TGraphErrors (counts_536 , delaytimeArray536, avets12IrradArray536, 0 , ts12IrradErr536);

  gr536_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr536_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr536_delaytempIrrad -> SetMarkerStyle(7);
  gr536_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr536_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr536_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr536_delaytempValveOpen = new TGraphErrors (counts_536 , delaytimeArray536, avets12ValveOpenArray536, 0 , ts12ValveOpenErr536);

  gr536_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr536_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr536_delaytempValveOpen -> SetMarkerStyle(7);
  gr536_delaytempValveOpen -> SetMarkerColor(2);
  gr536_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr536_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr536_delaytempIrrad -> Draw("AP");
  gr536_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p536_3 = c536->cd(4);
  p536_3->SetLogy(); 
  TGraphErrors *gr536_curcounts = new TGraphErrors (counts_536 , avecurArray536, UCNIntegralArray536 , ErrcurArray536 , UCNIntegralErrArray536);
  gr536_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr536_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr536_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr536_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr536_curhist = new TGraphErrors (counts_536 , avecurArray536, UCNIntegralArray536 , ErrcurArray536 , UCNIntegralErrArray536);
  gr536_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr536_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr536_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr536_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr536_curhist -> SetMarkerColor(2);
  gr536_curhist -> SetMarkerStyle(7);

  gr536_curcounts -> Draw("Ap");
  gr536_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c536_cycleNum = new TCanvas("c536_cycleNum" , "c536_cycleNum" , 1200, 800);
  c536_cycleNum -> Divide(2,2);
  TPad *p536_4 = c536_cycleNum->cd(1);
  p536_4->SetLogy(); 
  TGraphErrors *gr536_cyclecounts = new TGraphErrors (counts_536 , cycleNumberArray536, UCNIntegralArray536, 0 , UCNIntegralErrArray536);
  gr536_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr536_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr536_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr536_cyclehist = new TGraphErrors(counts_536, cycleNumberArray536 , HistIntegralArray536, 0, HistIntegralErrArray536);

  gr536_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr536_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr536_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr536_cyclehist -> SetMarkerColor(2);
  gr536_cyclehist -> SetMarkerStyle(7);

  gr536_cyclecounts -> Draw("Ap");
  gr536_cyclehist -> Draw("p");

  leg2-> Draw();

  c536_cycleNum -> cd(2);
 TGraphErrors *gr536_cycledelay = new TGraphErrors (counts_536 , cycleNumberArray536, delaytimeArray536, 0 , 0);
  gr536_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr536_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr536_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr536_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cycledelay -> SetMarkerStyle(7);

  gr536_cycledelay -> Draw("Ap");


  c536_cycleNum -> cd(3);
  TGraphErrors *gr536_cycletempIrrad = new TGraphErrors (counts_536 , cycleNumberArray536, avets12IrradArray536, 0 , ts12IrradErr536);

  gr536_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr536_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr536_cycletempIrrad -> SetMarkerStyle(7);
  gr536_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr536_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr536_cycletempValveOpen = new TGraphErrors (counts_536 , cycleNumberArray536, avets12ValveOpenArray536, 0 , ts12ValveOpenErr536);

  gr536_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr536_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr536_cycletempValveOpen -> SetMarkerStyle(7);
  gr536_cycletempValveOpen -> SetMarkerColor(2);
  gr536_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr536_cycletempIrrad -> Draw("AP");
  gr536_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c536_cycleNum -> cd(4);
  TGraphErrors *gr536_cyclecur = new TGraphErrors (counts_536 , cycleNumberArray536 , avecurArray536, 0, ErrcurArray536 );
  gr536_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr536_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr536_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclecur -> SetMarkerStyle(7);
  gr536_cyclecur -> Draw("Ap");


  TCanvas *c536_cycleNumFit = new TCanvas("c536_cycleNumFit" , "c536_cycleNumFit" , 1200, 800);
  c536_cycleNumFit -> Divide(2,2);

  c536_cycleNumFit -> cd(1);
  TGraphErrors *gr536_cyclefall = new TGraphErrors (counts_536, cycleNumberArray536, FallTimeArray536 , 0, FallTimeErrArray536);

  gr536_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr536_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr536_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclefall -> SetMarkerStyle(7);
  gr536_cyclefall -> Draw("Ap");


  c536_cycleNumFit -> cd(2);
  TGraphErrors *gr536_cyclebaseline = new TGraphErrors (counts_536, cycleNumberArray536, BaselineArray536 , 0, BaselineErrArray536);

  gr536_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr536_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr536_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclebaseline -> SetMarkerStyle(7);
  gr536_cyclebaseline -> Draw("Ap");

  c536_cycleNumFit -> cd(3);
  TGraphErrors *gr536_cyclebaselineirrad = new TGraphErrors (counts_536, cycleNumberArray536, BaselineIrradArray536 , 0, BaselineIrradErrArray536);

  gr536_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr536_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr536_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclebaselineirrad -> SetMarkerStyle(7);
  gr536_cyclebaselineirrad -> Draw("Ap");

  c536_cycleNumFit -> cd(4);
  TGraphErrors *gr536_cyclerise = new TGraphErrors (counts_536, cycleNumberArray536, RiseTimeArray536 , 0, RiseTimeErrArray536);

  gr536_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr536_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr536_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclerise -> SetMarkerStyle(7);
  gr536_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              537
  //*********************************
  //*********************************
  TCanvas *c537 = new TCanvas("c537" , "c537" , 1200, 800);
  c537 -> Divide(2,2);
  //c537 -> cd(1);
  TPad *p537_1 = c537->cd(1);
  p537_1->SetLogy(); 
  TGraphErrors *gr537_delaycounts = new TGraphErrors(counts_537, delaytimeArray537 , UCNIntegralArray537, 0, UCNIntegralErrArray537);

  gr537_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr537_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr537_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr537_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_delaycounts -> SetMarkerStyle(7);
  gr537_delaycounts -> Fit(fit);
  storage537 = fit -> GetParameter(1);
  storageErr537 = fit -> GetParError(1);
  
  TGraphErrors *gr537_delayhist = new TGraphErrors(counts_537, delaytimeArray537 , HistIntegralArray537, 0, HistIntegralErrArray537);

  gr537_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr537_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr537_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr537_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr537_delayhist -> SetMarkerColor(2);
  gr537_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr537_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr537_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr537_delaycounts -> Draw("Ap");
  gr537_delayhist -> Draw("p");
  leg2 -> Draw();

  //c537 -> cd(2);
  TPad *p537_2 = c537->cd(2);
  p537_2->SetLogy(); 
  TGraphErrors *gr537_tempIrradcounts = new TGraphErrors (counts_537 , avets12IrradArray537, UCNIntegralArray537 , ts12IrradErr537 , UCNIntegralErrArray537);
  gr537_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr537_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr537_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr537_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr537_tempValveOpencounts = new TGraphErrors (counts_537 , avets12ValveOpenArray537, UCNIntegralArray537 , ts12ValveOpenErr537 , UCNIntegralErrArray537);
  gr537_tempValveOpencounts -> SetMarkerStyle(7);
  gr537_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr537_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr537_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr537_tempIrradcounts -> Draw("Ap");
  gr537_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c537 -> cd(3);
  TGraphErrors *gr537_delaytempIrrad = new TGraphErrors (counts_537 , delaytimeArray537, avets12IrradArray537, 0 , ts12IrradErr537);

  gr537_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr537_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr537_delaytempIrrad -> SetMarkerStyle(7);
  gr537_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr537_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr537_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr537_delaytempValveOpen = new TGraphErrors (counts_537 , delaytimeArray537, avets12ValveOpenArray537, 0 , ts12ValveOpenErr537);

  gr537_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr537_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr537_delaytempValveOpen -> SetMarkerStyle(7);
  gr537_delaytempValveOpen -> SetMarkerColor(2);
  gr537_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr537_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr537_delaytempIrrad -> Draw("AP");
  gr537_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p537_3 = c537->cd(4);
  p537_3->SetLogy(); 
  TGraphErrors *gr537_curcounts = new TGraphErrors (counts_537 , avecurArray537, UCNIntegralArray537 , ErrcurArray537 , UCNIntegralErrArray537);
  gr537_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr537_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr537_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr537_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr537_curhist = new TGraphErrors (counts_537 , avecurArray537, UCNIntegralArray537 , ErrcurArray537 , UCNIntegralErrArray537);
  gr537_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr537_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr537_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr537_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr537_curhist -> SetMarkerColor(2);
  gr537_curhist -> SetMarkerStyle(7);

  gr537_curcounts -> Draw("Ap");
  gr537_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c537_cycleNum = new TCanvas("c537_cycleNum" , "c537_cycleNum" , 1200, 800);
  c537_cycleNum -> Divide(2,2);
  TPad *p537_4 = c537_cycleNum->cd(1);
  p537_4->SetLogy(); 
  TGraphErrors *gr537_cyclecounts = new TGraphErrors (counts_537 , cycleNumberArray537, UCNIntegralArray537, 0 , UCNIntegralErrArray537);
  gr537_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr537_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr537_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr537_cyclehist = new TGraphErrors(counts_537, cycleNumberArray537 , HistIntegralArray537, 0, HistIntegralErrArray537);

  gr537_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr537_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr537_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr537_cyclehist -> SetMarkerColor(2);
  gr537_cyclehist -> SetMarkerStyle(7);

  gr537_cyclecounts -> Draw("Ap");
  gr537_cyclehist -> Draw("p");

  leg2-> Draw();

  c537_cycleNum -> cd(2);
 TGraphErrors *gr537_cycledelay = new TGraphErrors (counts_537 , cycleNumberArray537, delaytimeArray537, 0 , 0);
  gr537_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr537_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr537_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr537_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cycledelay -> SetMarkerStyle(7);

  gr537_cycledelay -> Draw("Ap");


  c537_cycleNum -> cd(3);
  TGraphErrors *gr537_cycletempIrrad = new TGraphErrors (counts_537 , cycleNumberArray537, avets12IrradArray537, 0 , ts12IrradErr537);

  gr537_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr537_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr537_cycletempIrrad -> SetMarkerStyle(7);
  gr537_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr537_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr537_cycletempValveOpen = new TGraphErrors (counts_537 , cycleNumberArray537, avets12ValveOpenArray537, 0 , ts12ValveOpenErr537);

  gr537_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr537_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr537_cycletempValveOpen -> SetMarkerStyle(7);
  gr537_cycletempValveOpen -> SetMarkerColor(2);
  gr537_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr537_cycletempIrrad -> Draw("AP");
  gr537_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c537_cycleNum -> cd(4);
  TGraphErrors *gr537_cyclecur = new TGraphErrors (counts_537 , cycleNumberArray537 , avecurArray537, 0, ErrcurArray537 );
  gr537_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr537_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr537_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclecur -> SetMarkerStyle(7);
  gr537_cyclecur -> Draw("Ap");


  TCanvas *c537_cycleNumFit = new TCanvas("c537_cycleNumFit" , "c537_cycleNumFit" , 1200, 800);
  c537_cycleNumFit -> Divide(2,2);

  c537_cycleNumFit -> cd(1);
  TGraphErrors *gr537_cyclefall = new TGraphErrors (counts_537, cycleNumberArray537, FallTimeArray537 , 0, FallTimeErrArray537);

  gr537_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr537_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr537_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclefall -> SetMarkerStyle(7);
  gr537_cyclefall -> Draw("Ap");


  c537_cycleNumFit -> cd(2);
  TGraphErrors *gr537_cyclebaseline = new TGraphErrors (counts_537, cycleNumberArray537, BaselineArray537 , 0, BaselineErrArray537);

  gr537_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr537_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr537_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclebaseline -> SetMarkerStyle(7);
  gr537_cyclebaseline -> Draw("Ap");

  c537_cycleNumFit -> cd(3);
  TGraphErrors *gr537_cyclebaselineirrad = new TGraphErrors (counts_537, cycleNumberArray537, BaselineIrradArray537 , 0, BaselineIrradErrArray537);

  gr537_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr537_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr537_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclebaselineirrad -> SetMarkerStyle(7);
  gr537_cyclebaselineirrad -> Draw("Ap");

  c537_cycleNumFit -> cd(4);
  TGraphErrors *gr537_cyclerise = new TGraphErrors (counts_537, cycleNumberArray537, RiseTimeArray537 , 0, RiseTimeErrArray537);

  gr537_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr537_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr537_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclerise -> SetMarkerStyle(7);
  gr537_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              538
  //*********************************
  //*********************************
  TCanvas *c538 = new TCanvas("c538" , "c538" , 1200, 800);
  c538 -> Divide(2,2);
  //c538 -> cd(1);
  TPad *p538_1 = c538->cd(1);
  p538_1->SetLogy(); 
  TGraphErrors *gr538_delaycounts = new TGraphErrors(counts_538, delaytimeArray538 , UCNIntegralArray538, 0, UCNIntegralErrArray538);

  gr538_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr538_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr538_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr538_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_delaycounts -> SetMarkerStyle(7);
  gr538_delaycounts -> Fit(fit);
  storage538 = fit -> GetParameter(1);
  storageErr538 = fit -> GetParError(1);
  
  TGraphErrors *gr538_delayhist = new TGraphErrors(counts_538, delaytimeArray538 , HistIntegralArray538, 0, HistIntegralErrArray538);

  gr538_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr538_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr538_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr538_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr538_delayhist -> SetMarkerColor(2);
  gr538_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr538_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr538_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr538_delaycounts -> Draw("Ap");
  gr538_delayhist -> Draw("p");
  leg2 -> Draw();

  //c538 -> cd(2);
  TPad *p538_2 = c538->cd(2);
  p538_2->SetLogy(); 
  TGraphErrors *gr538_tempIrradcounts = new TGraphErrors (counts_538 , avets12IrradArray538, UCNIntegralArray538 , ts12IrradErr538 , UCNIntegralErrArray538);
  gr538_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr538_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.4);
  gr538_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr538_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr538_tempValveOpencounts = new TGraphErrors (counts_538 , avets12ValveOpenArray538, UCNIntegralArray538 , ts12ValveOpenErr538 , UCNIntegralErrArray538);
  gr538_tempValveOpencounts -> SetMarkerStyle(7);
  gr538_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr538_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr538_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr538_tempIrradcounts -> Draw("Ap");
  gr538_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c538 -> cd(3);
  TGraphErrors *gr538_delaytempIrrad = new TGraphErrors (counts_538 , delaytimeArray538, avets12IrradArray538, 0 , ts12IrradErr538);

  gr538_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr538_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr538_delaytempIrrad -> SetMarkerStyle(7);
  gr538_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.4);
  gr538_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr538_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr538_delaytempValveOpen = new TGraphErrors (counts_538 , delaytimeArray538, avets12ValveOpenArray538, 0 , ts12ValveOpenErr538);

  gr538_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr538_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr538_delaytempValveOpen -> SetMarkerStyle(7);
  gr538_delaytempValveOpen -> SetMarkerColor(2);
  gr538_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr538_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr538_delaytempIrrad -> Draw("AP");
  gr538_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p538_3 = c538->cd(4);
  p538_3->SetLogy(); 
  TGraphErrors *gr538_curcounts = new TGraphErrors (counts_538 , avecurArray538, UCNIntegralArray538 , ErrcurArray538 , UCNIntegralErrArray538);
  gr538_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr538_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr538_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr538_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr538_curhist = new TGraphErrors (counts_538 , avecurArray538, UCNIntegralArray538 , ErrcurArray538 , UCNIntegralErrArray538);
  gr538_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr538_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr538_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr538_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr538_curhist -> SetMarkerColor(2);
  gr538_curhist -> SetMarkerStyle(7);

  gr538_curcounts -> Draw("Ap");
  gr538_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c538_cycleNum = new TCanvas("c538_cycleNum" , "c538_cycleNum" , 1200, 800);
  c538_cycleNum -> Divide(2,2);
  TPad *p538_4 = c538_cycleNum->cd(1);
  p538_4->SetLogy(); 
  TGraphErrors *gr538_cyclecounts = new TGraphErrors (counts_538 , cycleNumberArray538, UCNIntegralArray538, 0 , UCNIntegralErrArray538);
  gr538_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr538_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr538_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr538_cyclehist = new TGraphErrors(counts_538, cycleNumberArray538 , HistIntegralArray538, 0, HistIntegralErrArray538);

  gr538_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr538_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr538_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr538_cyclehist -> SetMarkerColor(2);
  gr538_cyclehist -> SetMarkerStyle(7);

  gr538_cyclecounts -> Draw("Ap");
  gr538_cyclehist -> Draw("p");

  leg2-> Draw();

  c538_cycleNum -> cd(2);
 TGraphErrors *gr538_cycledelay = new TGraphErrors (counts_538 , cycleNumberArray538, delaytimeArray538, 0 , 0);
  gr538_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr538_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr538_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr538_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cycledelay -> SetMarkerStyle(7);

  gr538_cycledelay -> Draw("Ap");


  c538_cycleNum -> cd(3);
  TGraphErrors *gr538_cycletempIrrad = new TGraphErrors (counts_538 , cycleNumberArray538, avets12IrradArray538, 0 , ts12IrradErr538);

  gr538_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr538_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr538_cycletempIrrad -> SetMarkerStyle(7);
  gr538_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr538_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr538_cycletempValveOpen = new TGraphErrors (counts_538 , cycleNumberArray538, avets12ValveOpenArray538, 0 , ts12ValveOpenErr538);

  gr538_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr538_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr538_cycletempValveOpen -> SetMarkerStyle(7);
  gr538_cycletempValveOpen -> SetMarkerColor(2);
  gr538_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr538_cycletempIrrad -> Draw("AP");
  gr538_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c538_cycleNum -> cd(4);
  TGraphErrors *gr538_cyclecur = new TGraphErrors (counts_538 , cycleNumberArray538 , avecurArray538, 0, ErrcurArray538 );
  gr538_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr538_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr538_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclecur -> SetMarkerStyle(7);
  gr538_cyclecur -> Draw("Ap");


  TCanvas *c538_cycleNumFit = new TCanvas("c538_cycleNumFit" , "c538_cycleNumFit" , 1200, 800);
  c538_cycleNumFit -> Divide(2,2);

  c538_cycleNumFit -> cd(1);
  TGraphErrors *gr538_cyclefall = new TGraphErrors (counts_538, cycleNumberArray538, FallTimeArray538 , 0, FallTimeErrArray538);

  gr538_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr538_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr538_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclefall -> SetMarkerStyle(7);
  gr538_cyclefall -> Draw("Ap");


  c538_cycleNumFit -> cd(2);
  TGraphErrors *gr538_cyclebaseline = new TGraphErrors (counts_538, cycleNumberArray538, BaselineArray538 , 0, BaselineErrArray538);

  gr538_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr538_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr538_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclebaseline -> SetMarkerStyle(7);
  gr538_cyclebaseline -> Draw("Ap");

  c538_cycleNumFit -> cd(3);
  TGraphErrors *gr538_cyclebaselineirrad = new TGraphErrors (counts_538, cycleNumberArray538, BaselineIrradArray538 , 0, BaselineIrradErrArray538);

  gr538_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr538_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr538_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclebaselineirrad -> SetMarkerStyle(7);
  gr538_cyclebaselineirrad -> Draw("Ap");

  c538_cycleNumFit -> cd(4);
  TGraphErrors *gr538_cyclerise = new TGraphErrors (counts_538, cycleNumberArray538, RiseTimeArray538 , 0, RiseTimeErrArray538);

  gr538_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr538_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr538_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclerise -> SetMarkerStyle(7);
  gr538_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              539
  //*********************************
  //*********************************
  TCanvas *c539 = new TCanvas("c539" , "c539" , 1200, 800);
  c539 -> Divide(2,2);
  //c539 -> cd(1);
  TPad *p539_1 = c539->cd(1);
  p539_1->SetLogy(); 
  TGraphErrors *gr539_delaycounts = new TGraphErrors(counts_539, delaytimeArray539 , UCNIntegralArray539, 0, UCNIntegralErrArray539);

  gr539_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr539_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr539_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr539_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_delaycounts -> SetMarkerStyle(7);
  gr539_delaycounts -> Fit(fit);
  storage539 = fit -> GetParameter(1);
  storageErr539 = fit -> GetParError(1);
  
  TGraphErrors *gr539_delayhist = new TGraphErrors(counts_539, delaytimeArray539 , HistIntegralArray539, 0, HistIntegralErrArray539);

  gr539_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr539_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr539_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr539_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr539_delayhist -> SetMarkerColor(2);
  gr539_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr539_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr539_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr539_delaycounts -> Draw("Ap");
  gr539_delayhist -> Draw("p");
  leg2 -> Draw();

  //c539 -> cd(2);
  TPad *p539_2 = c539->cd(2);
  p539_2->SetLogy(); 
  TGraphErrors *gr539_tempIrradcounts = new TGraphErrors (counts_539 , avets12IrradArray539, UCNIntegralArray539 , ts12IrradErr539 , UCNIntegralErrArray539);
  gr539_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr539_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.4);
  gr539_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr539_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr539_tempValveOpencounts = new TGraphErrors (counts_539 , avets12ValveOpenArray539, UCNIntegralArray539 , ts12ValveOpenErr539 , UCNIntegralErrArray539);
  gr539_tempValveOpencounts -> SetMarkerStyle(7);
  gr539_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr539_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr539_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr539_tempIrradcounts -> Draw("Ap");
  gr539_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c539 -> cd(3);
  TGraphErrors *gr539_delaytempIrrad = new TGraphErrors (counts_539 , delaytimeArray539, avets12IrradArray539, 0 , ts12IrradErr539);

  gr539_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr539_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr539_delaytempIrrad -> SetMarkerStyle(7);
  gr539_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.4);
  gr539_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr539_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr539_delaytempValveOpen = new TGraphErrors (counts_539 , delaytimeArray539, avets12ValveOpenArray539, 0 , ts12ValveOpenErr539);

  gr539_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr539_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr539_delaytempValveOpen -> SetMarkerStyle(7);
  gr539_delaytempValveOpen -> SetMarkerColor(2);
  gr539_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr539_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr539_delaytempIrrad -> Draw("AP");
  gr539_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p539_3 = c539->cd(4);
  p539_3->SetLogy(); 
  TGraphErrors *gr539_curcounts = new TGraphErrors (counts_539 , avecurArray539, UCNIntegralArray539 , ErrcurArray539 , UCNIntegralErrArray539);
  gr539_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr539_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr539_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr539_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr539_curhist = new TGraphErrors (counts_539 , avecurArray539, UCNIntegralArray539 , ErrcurArray539 , UCNIntegralErrArray539);
  gr539_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr539_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr539_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr539_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr539_curhist -> SetMarkerColor(2);
  gr539_curhist -> SetMarkerStyle(7);

  gr539_curcounts -> Draw("Ap");
  gr539_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c539_cycleNum = new TCanvas("c539_cycleNum" , "c539_cycleNum" , 1200, 800);
  c539_cycleNum -> Divide(2,2);
  TPad *p539_4 = c539_cycleNum->cd(1);
  p539_4->SetLogy(); 
  TGraphErrors *gr539_cyclecounts = new TGraphErrors (counts_539 , cycleNumberArray539, UCNIntegralArray539, 0 , UCNIntegralErrArray539);
  gr539_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr539_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr539_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr539_cyclehist = new TGraphErrors(counts_539, cycleNumberArray539 , HistIntegralArray539, 0, HistIntegralErrArray539);

  gr539_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr539_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr539_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr539_cyclehist -> SetMarkerColor(2);
  gr539_cyclehist -> SetMarkerStyle(7);

  gr539_cyclecounts -> Draw("Ap");
  gr539_cyclehist -> Draw("p");

  leg2-> Draw();

  c539_cycleNum -> cd(2);
 TGraphErrors *gr539_cycledelay = new TGraphErrors (counts_539 , cycleNumberArray539, delaytimeArray539, 0 , 0);
  gr539_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr539_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr539_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr539_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cycledelay -> SetMarkerStyle(7);

  gr539_cycledelay -> Draw("Ap");


  c539_cycleNum -> cd(3);
  TGraphErrors *gr539_cycletempIrrad = new TGraphErrors (counts_539 , cycleNumberArray539, avets12IrradArray539, 0 , ts12IrradErr539);

  gr539_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr539_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr539_cycletempIrrad -> SetMarkerStyle(7);
  gr539_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr539_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr539_cycletempValveOpen = new TGraphErrors (counts_539 , cycleNumberArray539, avets12ValveOpenArray539, 0 , ts12ValveOpenErr539);

  gr539_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr539_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr539_cycletempValveOpen -> SetMarkerStyle(7);
  gr539_cycletempValveOpen -> SetMarkerColor(2);
  gr539_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr539_cycletempIrrad -> Draw("AP");
  gr539_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c539_cycleNum -> cd(4);
  TGraphErrors *gr539_cyclecur = new TGraphErrors (counts_539 , cycleNumberArray539 , avecurArray539, 0, ErrcurArray539 );
  gr539_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr539_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr539_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclecur -> SetMarkerStyle(7);
  gr539_cyclecur -> Draw("Ap");


  TCanvas *c539_cycleNumFit = new TCanvas("c539_cycleNumFit" , "c539_cycleNumFit" , 1200, 800);
  c539_cycleNumFit -> Divide(2,2);

  c539_cycleNumFit -> cd(1);
  TGraphErrors *gr539_cyclefall = new TGraphErrors (counts_539, cycleNumberArray539, FallTimeArray539 , 0, FallTimeErrArray539);

  gr539_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr539_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr539_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclefall -> SetMarkerStyle(7);
  gr539_cyclefall -> Draw("Ap");


  c539_cycleNumFit -> cd(2);
  TGraphErrors *gr539_cyclebaseline = new TGraphErrors (counts_539, cycleNumberArray539, BaselineArray539 , 0, BaselineErrArray539);

  gr539_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr539_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr539_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclebaseline -> SetMarkerStyle(7);
  gr539_cyclebaseline -> Draw("Ap");

  c539_cycleNumFit -> cd(3);
  TGraphErrors *gr539_cyclebaselineirrad = new TGraphErrors (counts_539, cycleNumberArray539, BaselineIrradArray539 , 0, BaselineIrradErrArray539);

  gr539_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr539_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr539_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclebaselineirrad -> SetMarkerStyle(7);
  gr539_cyclebaselineirrad -> Draw("Ap");

  c539_cycleNumFit -> cd(4);
  TGraphErrors *gr539_cyclerise = new TGraphErrors (counts_539, cycleNumberArray539, RiseTimeArray539 , 0, RiseTimeErrArray539);

  gr539_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr539_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr539_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclerise -> SetMarkerStyle(7);
  gr539_cyclerise -> Draw("Ap");


 
  //*********************************
  //*********************************
  //              540
  //*********************************
  //*********************************
  TCanvas *c540 = new TCanvas("c540" , "c540" , 1200, 800);
  c540 -> Divide(2,2);
  //c540 -> cd(1);
  TPad *p540_1 = c540->cd(1);
  p540_1->SetLogy(); 
  TGraphErrors *gr540_delaycounts = new TGraphErrors(counts_540, delaytimeArray540 , UCNIntegralArray540, 0, UCNIntegralErrArray540);

  gr540_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr540_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr540_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr540_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_delaycounts -> SetMarkerStyle(7);
  gr540_delaycounts -> Fit(fit);
  storage540 = fit -> GetParameter(1);
  storageErr540 = fit -> GetParError(1);
  
  TGraphErrors *gr540_delayhist = new TGraphErrors(counts_540, delaytimeArray540 , HistIntegralArray540, 0, HistIntegralErrArray540);

  gr540_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr540_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr540_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr540_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr540_delayhist -> SetMarkerColor(2);
  gr540_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr540_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr540_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr540_delaycounts -> Draw("Ap");
  gr540_delayhist -> Draw("p");
  leg2 -> Draw();

  //c540 -> cd(2);
  TPad *p540_2 = c540->cd(2);
  p540_2->SetLogy(); 
  TGraphErrors *gr540_tempIrradcounts = new TGraphErrors (counts_540 , avets12IrradArray540, UCNIntegralArray540 , ts12IrradErr540 , UCNIntegralErrArray540);
  gr540_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr540_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.4);
  gr540_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr540_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr540_tempValveOpencounts = new TGraphErrors (counts_540 , avets12ValveOpenArray540, UCNIntegralArray540 , ts12ValveOpenErr540 , UCNIntegralErrArray540);
  gr540_tempValveOpencounts -> SetMarkerStyle(7);
  gr540_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr540_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr540_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr540_tempIrradcounts -> Draw("Ap");
  gr540_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c540 -> cd(3);
  TGraphErrors *gr540_delaytempIrrad = new TGraphErrors (counts_540 , delaytimeArray540, avets12IrradArray540, 0 , ts12IrradErr540);

  gr540_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr540_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr540_delaytempIrrad -> SetMarkerStyle(7);
  gr540_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.4);
  gr540_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr540_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr540_delaytempValveOpen = new TGraphErrors (counts_540 , delaytimeArray540, avets12ValveOpenArray540, 0 , ts12ValveOpenErr540);

  gr540_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr540_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr540_delaytempValveOpen -> SetMarkerStyle(7);
  gr540_delaytempValveOpen -> SetMarkerColor(2);
  gr540_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr540_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr540_delaytempIrrad -> Draw("AP");
  gr540_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p540_3 = c540->cd(4);
  p540_3->SetLogy(); 
  TGraphErrors *gr540_curcounts = new TGraphErrors (counts_540 , avecurArray540, UCNIntegralArray540 , ErrcurArray540 , UCNIntegralErrArray540);
  gr540_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr540_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr540_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr540_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr540_curhist = new TGraphErrors (counts_540 , avecurArray540, UCNIntegralArray540 , ErrcurArray540 , UCNIntegralErrArray540);
  gr540_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr540_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr540_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr540_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr540_curhist -> SetMarkerColor(2);
  gr540_curhist -> SetMarkerStyle(7);

  gr540_curcounts -> Draw("Ap");
  gr540_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c540_cycleNum = new TCanvas("c540_cycleNum" , "c540_cycleNum" , 1200, 800);
  c540_cycleNum -> Divide(2,2);
  TPad *p540_4 = c540_cycleNum->cd(1);
  p540_4->SetLogy(); 
  TGraphErrors *gr540_cyclecounts = new TGraphErrors (counts_540 , cycleNumberArray540, UCNIntegralArray540, 0 , UCNIntegralErrArray540);
  gr540_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr540_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr540_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr540_cyclehist = new TGraphErrors(counts_540, cycleNumberArray540 , HistIntegralArray540, 0, HistIntegralErrArray540);

  gr540_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr540_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr540_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr540_cyclehist -> SetMarkerColor(2);
  gr540_cyclehist -> SetMarkerStyle(7);

  gr540_cyclecounts -> Draw("Ap");
  gr540_cyclehist -> Draw("p");

  leg2-> Draw();

  c540_cycleNum -> cd(2);
 TGraphErrors *gr540_cycledelay = new TGraphErrors (counts_540 , cycleNumberArray540, delaytimeArray540, 0 , 0);
  gr540_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr540_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr540_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr540_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cycledelay -> SetMarkerStyle(7);

  gr540_cycledelay -> Draw("Ap");


  c540_cycleNum -> cd(3);
  TGraphErrors *gr540_cycletempIrrad = new TGraphErrors (counts_540 , cycleNumberArray540, avets12IrradArray540, 0 , ts12IrradErr540);

  gr540_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr540_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr540_cycletempIrrad -> SetMarkerStyle(7);
  gr540_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr540_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr540_cycletempValveOpen = new TGraphErrors (counts_540 , cycleNumberArray540, avets12ValveOpenArray540, 0 , ts12ValveOpenErr540);

  gr540_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr540_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr540_cycletempValveOpen -> SetMarkerStyle(7);
  gr540_cycletempValveOpen -> SetMarkerColor(2);
  gr540_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr540_cycletempIrrad -> Draw("AP");
  gr540_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c540_cycleNum -> cd(4);
  TGraphErrors *gr540_cyclecur = new TGraphErrors (counts_540 , cycleNumberArray540 , avecurArray540, 0, ErrcurArray540 );
  gr540_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr540_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr540_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclecur -> SetMarkerStyle(7);
  gr540_cyclecur -> Draw("Ap");


  TCanvas *c540_cycleNumFit = new TCanvas("c540_cycleNumFit" , "c540_cycleNumFit" , 1200, 800);
  c540_cycleNumFit -> Divide(2,2);

  c540_cycleNumFit -> cd(1);
  TGraphErrors *gr540_cyclefall = new TGraphErrors (counts_540, cycleNumberArray540, FallTimeArray540 , 0, FallTimeErrArray540);

  gr540_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr540_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr540_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclefall -> SetMarkerStyle(7);
  gr540_cyclefall -> Draw("Ap");


  c540_cycleNumFit -> cd(2);
  TGraphErrors *gr540_cyclebaseline = new TGraphErrors (counts_540, cycleNumberArray540, BaselineArray540 , 0, BaselineErrArray540);

  gr540_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr540_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr540_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclebaseline -> SetMarkerStyle(7);
  gr540_cyclebaseline -> Draw("Ap");

  c540_cycleNumFit -> cd(3);
  TGraphErrors *gr540_cyclebaselineirrad = new TGraphErrors (counts_540, cycleNumberArray540, BaselineIrradArray540 , 0, BaselineIrradErrArray540);

  gr540_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr540_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr540_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclebaselineirrad -> SetMarkerStyle(7);
  gr540_cyclebaselineirrad -> Draw("Ap");

  c540_cycleNumFit -> cd(4);
  TGraphErrors *gr540_cyclerise = new TGraphErrors (counts_540, cycleNumberArray540, RiseTimeArray540 , 0, RiseTimeErrArray540);

  gr540_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr540_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr540_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclerise -> SetMarkerStyle(7);
  gr540_cyclerise -> Draw("Ap");



  /*

  double StorageAll [100] = {storage532, storage533, storage535, storage536, storage537, storage540};
  double StorageErrAll[100] = {storageErr532, storageErr533, storageErr535, storageErr535, storageErr536, storageErr537, storageErr540};
  double runNum[100] = {532, 533, 535, 536, 537, 540};
  double tempIrradAll[100] = {aveAllts12Irrad532, aveAllts12Irrad533, aveAllts12Irrad535, aveAllts12Irrad536, aveAllts12Irrad537, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad532,  aveAllErrts12Irrad533,  aveAllErrts12Irrad534,  aveAllErrts12Irrad536,  aveAllErrts12Irrad537,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_532 +counts_533 +counts_534 +counts_535 +counts_536 +counts_537 +counts_538 +counts_539 +counts_540 , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  
  grAll -> SetTitle("UCN Count vs cycle Delay Time ");
  grAll -> GetYaxis()-> SetTitle("UCN Count" );
  grAll -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  //grAll -> GetXaxis()-> SetLimits(0.8 ,1.3);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> Fit(fit);

  grAll -> SetMarkerStyle(7);
  grAll -> Draw("Ap");
  




}
