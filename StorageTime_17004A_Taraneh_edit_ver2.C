//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17002.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17004A_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin553 = new TFile("outputTree_StorageTime_553.root","READ");
  TFile *fin554 = new TFile("outputTree_StorageTime_554.root","READ");
  TFile *fin555 = new TFile("outputTree_StorageTime_555.root","READ");
  TFile *fin556 = new TFile("outputTree_StorageTime_556.root","READ");
  TFile *fin557 = new TFile("outputTree_StorageTime_557.root","READ");
  TFile *fin558 = new TFile("outputTree_StorageTime_558.root","READ");
  TFile *fin559 = new TFile("outputTree_StorageTime_559.root","READ");
  TFile *fin560 = new TFile("outputTree_StorageTime_560.root","READ");


  
  TTree *outputTree553 = (TTree*) fin553 -> Get("cycle_info");
  TTree *outputTree554 = (TTree*) fin554 -> Get("cycle_info");
  TTree *outputTree555 = (TTree*) fin555 -> Get("cycle_info");
  TTree *outputTree556 = (TTree*) fin556 -> Get("cycle_info");
  TTree *outputTree557 = (TTree*) fin557 -> Get("cycle_info");
  TTree *outputTree558 = (TTree*) fin558 -> Get("cycle_info");
  TTree *outputTree559 = (TTree*) fin559 -> Get("cycle_info");
  TTree *outputTree560 = (TTree*) fin560 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime553;
  double cycleDelayTime554;
  double cycleDelayTime555;
  double cycleDelayTime556;
  double cycleDelayTime557;
  double cycleDelayTime558;
  double cycleDelayTime559;
  double cycleDelayTime560;



  outputTree553 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime553);
  outputTree554 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime554);
  outputTree555 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime555);
  outputTree556 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime556);
  outputTree557 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime557);
  outputTree558 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime558);
  outputTree559 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime559);
  outputTree560 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime560);



  // DELAY TIME (ARRAY)
  double delaytimeArray553 [100];
  double delaytimeArray554 [100];
  double delaytimeArray555 [100];
  double delaytimeArray556 [100];
  double delaytimeArray557 [100];
  double delaytimeArray558 [100];
  double delaytimeArray559 [100];
  double delaytimeArray560 [100];


  // CYCLE NUMBER
  int cycleNumber553;
  int cycleNumber554;
  int cycleNumber555;
  int cycleNumber556;
  int cycleNumber557;
  int cycleNumber558;
  int cycleNumber559;
  int cycleNumber560;


  outputTree553 -> SetBranchAddress ("cycleNumber" , &cycleNumber553);
  outputTree554 -> SetBranchAddress ("cycleNumber" , &cycleNumber554);
  outputTree555 -> SetBranchAddress ("cycleNumber" , &cycleNumber555);
  outputTree556 -> SetBranchAddress ("cycleNumber" , &cycleNumber556);
  outputTree557 -> SetBranchAddress ("cycleNumber" , &cycleNumber557);
  outputTree558 -> SetBranchAddress ("cycleNumber" , &cycleNumber558);
  outputTree559 -> SetBranchAddress ("cycleNumber" , &cycleNumber559);
  outputTree560 -> SetBranchAddress ("cycleNumber" , &cycleNumber560);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray553 [100];
  double cycleNumberArray554 [100];
  double cycleNumberArray555 [100];
  double cycleNumberArray556 [100];
  double cycleNumberArray557 [100];
  double cycleNumberArray558 [100];
  double cycleNumberArray559 [100];
  double cycleNumberArray560 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral553;
  double UCNIntegral554;
  double UCNIntegral555;
  double UCNIntegral556;
  double UCNIntegral557;
  double UCNIntegral558;
  double UCNIntegral559;
  double UCNIntegral560;



  outputTree553 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral553);
  outputTree554 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral554);
  outputTree555 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral555);
  outputTree556 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral556);
  outputTree557 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral557);
  outputTree558 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral558);
  outputTree559 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral559);
  outputTree560 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral560);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray553 [100];
  double UCNIntegralArray554 [100];
  double UCNIntegralArray555 [100];
  double UCNIntegralArray556 [100];
  double UCNIntegralArray557 [100];
  double UCNIntegralArray558 [100];
  double UCNIntegralArray559 [100];
  double UCNIntegralArray560 [100];


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr553;
  double UCNIntegralErr554;
  double UCNIntegralErr555;
  double UCNIntegralErr556;
  double UCNIntegralErr557;
  double UCNIntegralErr558;
  double UCNIntegralErr559;
  double UCNIntegralErr560;


  outputTree553 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr553);
  outputTree554 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr554);
  outputTree555 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr555);
  outputTree556 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr556);
  outputTree557 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr557);
  outputTree558 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr558);
  outputTree559 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr559);
  outputTree560 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr560);


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray553 [100];
  double UCNIntegralErrArray554 [100];
  double UCNIntegralErrArray555 [100];
  double UCNIntegralErrArray556 [100];
  double UCNIntegralErrArray557 [100];
  double UCNIntegralErrArray558 [100];
  double UCNIntegralErrArray559 [100];
  double UCNIntegralErrArray560 [100];


  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral553;
  double HistIntegral554;
  double HistIntegral555;
  double HistIntegral556;
  double HistIntegral557;
  double HistIntegral558;
  double HistIntegral559;
  double HistIntegral560;


  outputTree553 -> SetBranchAddress ("HistIntegral" , &HistIntegral553); 
  outputTree554 -> SetBranchAddress ("HistIntegral" , &HistIntegral554);
  outputTree555 -> SetBranchAddress ("HistIntegral" , &HistIntegral555);
  outputTree556 -> SetBranchAddress ("HistIntegral" , &HistIntegral556);
  outputTree557 -> SetBranchAddress ("HistIntegral" , &HistIntegral557);
  outputTree558 -> SetBranchAddress ("HistIntegral" , &HistIntegral558);
  outputTree559 -> SetBranchAddress ("HistIntegral" , &HistIntegral559);
  outputTree560 -> SetBranchAddress ("HistIntegral" , &HistIntegral560);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray553 [100];
  double HistIntegralArray554 [100];
  double HistIntegralArray555 [100];
  double HistIntegralArray556 [100];
  double HistIntegralArray557 [100];
  double HistIntegralArray558 [100];
  double HistIntegralArray559 [100];
  double HistIntegralArray560 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr553;
  double HistIntegralErr554;
  double HistIntegralErr555;
  double HistIntegralErr556;
  double HistIntegralErr557;
  double HistIntegralErr558;
  double HistIntegralErr559;
  double HistIntegralErr560;


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray553 [100];
  double HistIntegralErrArray554 [100];
  double HistIntegralErrArray555 [100];
  double HistIntegralErrArray556 [100];
  double HistIntegralErrArray557 [100];
  double HistIntegralErrArray558 [100];
  double HistIntegralErrArray559 [100];
  double HistIntegralErrArray560 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad553;
  double avets12Irrad554;
  double avets12Irrad555;
  double avets12Irrad556;
  double avets12Irrad557;
  double avets12Irrad558;
  double avets12Irrad559;
  double avets12Irrad560;

  outputTree553 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad553);
  outputTree554 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad554);
  outputTree555 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad555);
  outputTree556 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad556);
  outputTree557 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad557);
  outputTree558 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad558);
  outputTree559 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad559);
  outputTree560 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad560);



  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen553;
  double avets12ValveOpen554;
  double avets12ValveOpen555;
  double avets12ValveOpen556;
  double avets12ValveOpen557;
  double avets12ValveOpen558;
  double avets12ValveOpen559;
  double avets12ValveOpen560;


  outputTree553 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen553);
  outputTree554 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen554);
  outputTree555 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen555);
  outputTree556 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen556);
  outputTree557 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen557);
  outputTree558 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen558);
  outputTree559 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen559);
  outputTree560 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen560);


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray553 [100];
  double avets12IrradArray554 [100];
  double avets12IrradArray555 [100];
  double avets12IrradArray556 [100];
  double avets12IrradArray557 [100];
  double avets12IrradArray558 [100];
  double avets12IrradArray559 [100];
  double avets12IrradArray560 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray553 [100];
  double avets12ValveOpenArray554 [100];
  double avets12ValveOpenArray555 [100];
  double avets12ValveOpenArray556 [100];
  double avets12ValveOpenArray557 [100];
  double avets12ValveOpenArray558 [100];
  double avets12ValveOpenArray559 [100];
  double avets12ValveOpenArray560 [100];


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad553;
  double maxts12Irrad554;
  double maxts12Irrad555;
  double maxts12Irrad556;
  double maxts12Irrad557;
  double maxts12Irrad558;
  double maxts12Irrad559;
  double maxts12Irrad560;

  outputTree553 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad553);
  outputTree554 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad554);
  outputTree555 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad555);
  outputTree556 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad556);
  outputTree557 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad557);
  outputTree558 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad558);
  outputTree559 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad559);
  outputTree560 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad560);


 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen553;
  double maxts12ValveOpen554;
  double maxts12ValveOpen555;
  double maxts12ValveOpen556;
  double maxts12ValveOpen557;
  double maxts12ValveOpen558;
  double maxts12ValveOpen559;
  double maxts12ValveOpen560;


  outputTree553 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen553);
  outputTree554 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen554);
  outputTree555 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen555);
  outputTree556 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen556);
  outputTree557 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen557);
  outputTree558 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen558);
  outputTree559 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen559);
  outputTree560 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen560);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray553 [100];
  double maxts12IrradArray554 [100];
  double maxts12IrradArray555 [100];
  double maxts12IrradArray556 [100];
  double maxts12IrradArray557 [100];
  double maxts12IrradArray558 [100];
  double maxts12IrradArray559 [100];
  double maxts12IrradArray560 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray553 [100];
  double maxts12ValveOpenArray554 [100];
  double maxts12ValveOpenArray555 [100];
  double maxts12ValveOpenArray556 [100];
  double maxts12ValveOpenArray557 [100];
  double maxts12ValveOpenArray558 [100];
  double maxts12ValveOpenArray559 [100];
  double maxts12ValveOpenArray560 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad553;
  double mints12Irrad554;
  double mints12Irrad555;
  double mints12Irrad556;
  double mints12Irrad557;
  double mints12Irrad558;
  double mints12Irrad559;
  double mints12Irrad560;


  outputTree553 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad553);
  outputTree554 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad554);
  outputTree555 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad555);
  outputTree556 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad556);
  outputTree557 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad557);
  outputTree558 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad558);
  outputTree559 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad559);
  outputTree560 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad560);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen553;
  double mints12ValveOpen554;
  double mints12ValveOpen555;
  double mints12ValveOpen556;
  double mints12ValveOpen557;
  double mints12ValveOpen558;
  double mints12ValveOpen559;
  double mints12ValveOpen560;
  
  outputTree553 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen553);
  outputTree554 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen554);
  outputTree555 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen555);
  outputTree556 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen556);
  outputTree557 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen557);
  outputTree558 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen558);
  outputTree559 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen559);
  outputTree560 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen560);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray553 [100];
  double mints12IrradArray554 [100];
  double mints12IrradArray555 [100];
  double mints12IrradArray556 [100];
  double mints12IrradArray557 [100];
  double mints12IrradArray558 [100];
  double mints12IrradArray559 [100];
  double mints12IrradArray560 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray553 [100];
  double mints12ValveOpenArray554 [100];
  double mints12ValveOpenArray555 [100];
  double mints12ValveOpenArray556 [100];
  double mints12ValveOpenArray557 [100];
  double mints12ValveOpenArray558 [100];
  double mints12ValveOpenArray559 [100];
  double mints12ValveOpenArray560 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr553 [100];
  double ts12IrradErr554 [100];
  double ts12IrradErr555 [100];
  double ts12IrradErr556 [100];
  double ts12IrradErr557 [100];
  double ts12IrradErr558 [100];
  double ts12IrradErr559 [100];
  double ts12IrradErr560 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr553 [100];
  double ts12ValveOpenErr554 [100];
  double ts12ValveOpenErr555 [100];
  double ts12ValveOpenErr556 [100];
  double ts12ValveOpenErr557 [100];
  double ts12ValveOpenErr558 [100];
  double ts12ValveOpenErr559 [100];
  double ts12ValveOpenErr560 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur553;
  double avecur554;
  double avecur555;
  double avecur556;
  double avecur557;
  double avecur558;
  double avecur559;
  double avecur560;

  outputTree553 -> SetBranchAddress ("AVE_PRDCUR" , &avecur553);
  outputTree554 -> SetBranchAddress ("AVE_PRDCUR" , &avecur554);
  outputTree555 -> SetBranchAddress ("AVE_PRDCUR" , &avecur555);
  outputTree556 -> SetBranchAddress ("AVE_PRDCUR" , &avecur556);
  outputTree557 -> SetBranchAddress ("AVE_PRDCUR" , &avecur557);
  outputTree558 -> SetBranchAddress ("AVE_PRDCUR" , &avecur558);
  outputTree559 -> SetBranchAddress ("AVE_PRDCUR" , &avecur559);
  outputTree560 -> SetBranchAddress ("AVE_PRDCUR" , &avecur560);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray553 [100];
  double avecurArray554 [100];
  double avecurArray555 [100];
  double avecurArray556 [100];
  double avecurArray557 [100];
  double avecurArray558 [100];
  double avecurArray559 [100];
  double avecurArray560 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur553;
  double maxcur554;
  double maxcur555;
  double maxcur556;
  double maxcur557;
  double maxcur558;
  double maxcur559;
  double maxcur560;

  outputTree553 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur553);
  outputTree554 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur554);
  outputTree555 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur555);
  outputTree556 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur556);
  outputTree557 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur557);
  outputTree558 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur558);
  outputTree559 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur559);
  outputTree560 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur560);

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray553 [100];
  double maxcurArray554 [100];
  double maxcurArray555 [100];
  double maxcurArray556 [100];
  double maxcurArray557 [100];
  double maxcurArray558 [100];
  double maxcurArray559 [100];
  double maxcurArray560 [100];

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur553;
  double mincur554;
  double mincur555;
  double mincur556;
  double mincur557;
  double mincur558;
  double mincur559;
  double mincur560;

  outputTree553 -> SetBranchAddress ("MIN_PRDCUR" , &mincur553);
  outputTree554 -> SetBranchAddress ("MIN_PRDCUR" , &mincur554);
  outputTree555 -> SetBranchAddress ("MIN_PRDCUR" , &mincur555);
  outputTree556 -> SetBranchAddress ("MIN_PRDCUR" , &mincur556);
  outputTree557 -> SetBranchAddress ("MIN_PRDCUR" , &mincur557);
  outputTree558 -> SetBranchAddress ("MIN_PRDCUR" , &mincur558);
  outputTree559 -> SetBranchAddress ("MIN_PRDCUR" , &mincur559);
  outputTree560 -> SetBranchAddress ("MIN_PRDCUR" , &mincur560);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray553 [100];
  double mincurArray554 [100];
  double mincurArray555 [100];
  double mincurArray556 [100];
  double mincurArray557 [100];
  double mincurArray558 [100];
  double mincurArray559 [100];
  double mincurArray560 [100];

  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray553 [100];
  double ErrcurArray554 [100];
  double ErrcurArray555 [100];
  double ErrcurArray556 [100];
  double ErrcurArray557 [100];
  double ErrcurArray558 [100];
  double ErrcurArray559 [100];
  double ErrcurArray560 [100];

  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline553;
  double Baseline554;
  double Baseline555;
  double Baseline556;
  double Baseline557;
  double Baseline558;
  double Baseline559;
  double Baseline560;

  outputTree553 -> SetBranchAddress ("Baseline" , &Baseline553);
  outputTree554 -> SetBranchAddress ("Baseline" , &Baseline554);
  outputTree555 -> SetBranchAddress ("Baseline" , &Baseline555);
  outputTree556 -> SetBranchAddress ("Baseline" , &Baseline556);
  outputTree557 -> SetBranchAddress ("Baseline" , &Baseline557);
  outputTree558 -> SetBranchAddress ("Baseline" , &Baseline558);
  outputTree559 -> SetBranchAddress ("Baseline" , &Baseline559);
  outputTree560 -> SetBranchAddress ("Baseline" , &Baseline560);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray553 [100];
  double BaselineArray554 [100];
  double BaselineArray555 [100];
  double BaselineArray556 [100];
  double BaselineArray557 [100];
  double BaselineArray558 [100];
  double BaselineArray559 [100];
  double BaselineArray560 [100];

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr553;
  double BaselineErr554;
  double BaselineErr555;
  double BaselineErr556;
  double BaselineErr557;
  double BaselineErr558;
  double BaselineErr559;
  double BaselineErr560;
 
  outputTree553 -> SetBranchAddress ("BaselineErr" , &BaselineErr553);
  outputTree554 -> SetBranchAddress ("BaselineErr" , &BaselineErr554);
  outputTree555 -> SetBranchAddress ("BaselineErr" , &BaselineErr555);
  outputTree556 -> SetBranchAddress ("BaselineErr" , &BaselineErr556);
  outputTree557 -> SetBranchAddress ("BaselineErr" , &BaselineErr557);
  outputTree558 -> SetBranchAddress ("BaselineErr" , &BaselineErr558);
  outputTree559 -> SetBranchAddress ("BaselineErr" , &BaselineErr559);
  outputTree560 -> SetBranchAddress ("BaselineErr" , &BaselineErr560);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray553 [100];
  double BaselineErrArray554 [100];
  double BaselineErrArray555 [100];
  double BaselineErrArray556 [100];
  double BaselineErrArray557 [100];
  double BaselineErrArray558 [100];
  double BaselineErrArray559 [100];
  double BaselineErrArray560 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad553;
  double BaselineIrrad554;
  double BaselineIrrad555;
  double BaselineIrrad556;
  double BaselineIrrad557;
  double BaselineIrrad558;
  double BaselineIrrad559;
  double BaselineIrrad560;
 
  outputTree553 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad553);
  outputTree554 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad554);
  outputTree555 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad555);
  outputTree556 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad556);
  outputTree557 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad557);
  outputTree558 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad558);
  outputTree559 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad559);
  outputTree560 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad560);

  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray553 [100];
  double BaselineIrradArray554 [100];
  double BaselineIrradArray555 [100];
  double BaselineIrradArray556 [100];
  double BaselineIrradArray557 [100];
  double BaselineIrradArray558 [100];
  double BaselineIrradArray559 [100];
  double BaselineIrradArray560 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr553;
  double BaselineIrradErr554;
  double BaselineIrradErr555;
  double BaselineIrradErr556;
  double BaselineIrradErr557;
  double BaselineIrradErr558;
  double BaselineIrradErr559;
  double BaselineIrradErr560;

  outputTree553 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr553);
  outputTree554 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr554);
  outputTree555 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr555);
  outputTree556 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr556);
  outputTree557 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr557);
  outputTree558 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr558);
  outputTree559 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr559);
  outputTree560 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr560);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray553 [100];
  double BaselineIrradErrArray554 [100];
  double BaselineIrradErrArray555 [100];
  double BaselineIrradErrArray556 [100];
  double BaselineIrradErrArray557 [100];
  double BaselineIrradErrArray558 [100];
  double BaselineIrradErrArray559 [100];
  double BaselineIrradErrArray560 [100];

  // FALL TIME FROM THE UCN RATE FIT
  double FallTime553;
  double FallTime554;
  double FallTime555;
  double FallTime556;
  double FallTime557;
  double FallTime558;
  double FallTime559;
  double FallTime560;

  outputTree553 -> SetBranchAddress ("FallTime" , &FallTime553);
  outputTree554 -> SetBranchAddress ("FallTime" , &FallTime554);
  outputTree555 -> SetBranchAddress ("FallTime" , &FallTime555);
  outputTree556 -> SetBranchAddress ("FallTime" , &FallTime556);
  outputTree557 -> SetBranchAddress ("FallTime" , &FallTime557);
  outputTree558 -> SetBranchAddress ("FallTime" , &FallTime558);
  outputTree559 -> SetBranchAddress ("FallTime" , &FallTime559);
  outputTree560 -> SetBranchAddress ("FallTime" , &FallTime560);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray553 [100];
  double FallTimeArray554 [100];
  double FallTimeArray555 [100];
  double FallTimeArray556 [100];
  double FallTimeArray557 [100];
  double FallTimeArray558 [100];
  double FallTimeArray559 [100];
  double FallTimeArray560 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr553;
  double FallTimeErr554;
  double FallTimeErr555;
  double FallTimeErr556;
  double FallTimeErr557;
  double FallTimeErr558;
  double FallTimeErr559;
  double FallTimeErr560;

  outputTree553 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr553);
  outputTree554 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr554);
  outputTree555 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr555);
  outputTree556 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr556);
  outputTree557 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr557);
  outputTree558 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr558);
  outputTree559 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr559);
  outputTree560 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr560);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray553 [100];
  double FallTimeErrArray554 [100];
  double FallTimeErrArray555 [100];
  double FallTimeErrArray556 [100];
  double FallTimeErrArray557 [100];
  double FallTimeErrArray558 [100];
  double FallTimeErrArray559 [100];
  double FallTimeErrArray560 [100];
  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime553;
  double RiseTime554;
  double RiseTime555;
  double RiseTime556;
  double RiseTime557;
  double RiseTime558;
  double RiseTime559;
  double RiseTime560;

  outputTree553 -> SetBranchAddress ("RiseTime" , &RiseTime553);
  outputTree554 -> SetBranchAddress ("RiseTime" , &RiseTime554);
  outputTree555 -> SetBranchAddress ("RiseTime" , &RiseTime555);
  outputTree556 -> SetBranchAddress ("RiseTime" , &RiseTime556);
  outputTree557 -> SetBranchAddress ("RiseTime" , &RiseTime557);
  outputTree558 -> SetBranchAddress ("RiseTime" , &RiseTime558);
  outputTree559 -> SetBranchAddress ("RiseTime" , &RiseTime559);
  outputTree560 -> SetBranchAddress ("RiseTime" , &RiseTime560);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray553 [100];
  double RiseTimeArray554 [100];
  double RiseTimeArray555 [100];
  double RiseTimeArray556 [100];
  double RiseTimeArray557 [100];
  double RiseTimeArray558 [100];
  double RiseTimeArray559 [100];
  double RiseTimeArray560 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr553;
  double RiseTimeErr554;
  double RiseTimeErr555;
  double RiseTimeErr556;
  double RiseTimeErr557;
  double RiseTimeErr558;
  double RiseTimeErr559;
  double RiseTimeErr560;

  outputTree553 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr553);
  outputTree554 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr554);
  outputTree555 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr555);
  outputTree556 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr556);
  outputTree557 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr557);
  outputTree558 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr558);
  outputTree559 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr559);
  outputTree560 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr560);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray553 [100];
  double RiseTimeErrArray554 [100];
  double RiseTimeErrArray555 [100];
  double RiseTimeErrArray556 [100];
  double RiseTimeErrArray557 [100];
  double RiseTimeErrArray558 [100];
  double RiseTimeErrArray559 [100];
  double RiseTimeErrArray560 [100];


  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad553;
  double aveAllts12Irrad554;
  double aveAllts12Irrad555;
  double aveAllts12Irrad556;
  double aveAllts12Irrad557;
  double aveAllts12Irrad558;
  double aveAllts12Irrad559;
  double aveAllts12Irrad560;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad553;
  double aveAllErrts12Irrad554;
  double aveAllErrts12Irrad555;
  double aveAllErrts12Irrad556;
  double aveAllErrts12Irrad557;
  double aveAllErrts12Irrad558;
  double aveAllErrts12Irrad559;
  double aveAllErrts12Irrad560;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad553;
  double maxAllts12Irrad554;
  double maxAllts12Irrad555;
  double maxAllts12Irrad556;
  double maxAllts12Irrad557;
  double maxAllts12Irrad558;
  double maxAllts12Irrad559;
  double maxAllts12Irrad560;
  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad553;
  double minAllts12Irrad554;
  double minAllts12Irrad555;
  double minAllts12Irrad556;
  double minAllts12Irrad557;
  double minAllts12Irrad558;
  double minAllts12Irrad559;
  double minAllts12Irrad560;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage553;
  double storage554;
  double storage555;
  double storage556;
  double storage557;
  double storage558;
  double storage559;
  double storage560;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr553;
  double storageErr554;
  double storageErr555;
  double storageErr556;
  double storageErr557;
  double storageErr558;
  double storageErr559;
  double storageErr560;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_553 = 0;
  int counts_554 = 0;
  int counts_555 = 0;
  int counts_556 = 0;
  int counts_557 = 0;
  int counts_558 = 0;
  int counts_559 = 0;
  int counts_560 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events553;
  events553 = (Double_t)outputTree553 -> GetEntries();

  for (ULong64_t j = 0 ; j < events553 ; j++){
    outputTree553 -> GetEvent(j);
    if (j == 2)
      continue;
    UCNIntegralArray553[counts_553] = UCNIntegral553;
    UCNIntegralErrArray553[counts_553] = UCNIntegralErr553;
    HistIntegralArray553[counts_553] = HistIntegral553;
    HistIntegralErrArray553[counts_553] = sqrt (HistIntegral553);
    avets12IrradArray553[counts_553] = avets12Irrad553;
    avets12ValveOpenArray553[counts_553] = avets12ValveOpen553;
    maxts12IrradArray553[counts_553] = maxts12Irrad553;
    maxts12ValveOpenArray553[counts_553] = maxts12ValveOpen553;
    mints12IrradArray553[counts_553] = mints12Irrad553; 
    mints12ValveOpenArray553[counts_553] = mints12ValveOpen553;
    ts12IrradErr553[counts_553] = maxts12Irrad553 - mints12Irrad553;
    ts12ValveOpenErr553[counts_553] = maxts12ValveOpen553 - mints12ValveOpen553;
    avecurArray553[counts_553] = avecur553;
    maxcurArray553[counts_553] = maxcur553;
    mincurArray553[counts_553] = mincur553;
    ErrcurArray553[counts_553] = maxcur553 - mincur553;
    delaytimeArray553[counts_553] = cycleDelayTime553;
    cycleNumberArray553[counts_553] = cycleNumber553;
    BaselineArray553[counts_553] = Baseline553;
    BaselineIrradArray553[counts_553] = BaselineIrrad553;
    BaselineIrradErrArray553[counts_553] = BaselineIrradErr553;
    FallTimeArray553[counts_553] = FallTime553;
    FallTimeErrArray553[counts_553] = FallTimeErr553;
    RiseTimeArray553[counts_553] = RiseTime553;
    RiseTimeErrArray553[counts_553] = RiseTimeErr553;
    aveAllts12Irrad553 += avets12Irrad553;
    maxAllts12Irrad553 += maxts12Irrad553;
    minAllts12Irrad553 += mints12Irrad553;
    UCNIntegralArrayAll[counts_553] = UCNIntegral553;
    UCNIntegralErrArrayAll[counts_553] = UCNIntegralErr553;
    delayTimeAll[counts_553] = cycleDelayTime553;
    HistIntegralArrayAll[counts_553] = HistIntegral553;
    HistIntegralErrArrayAll[counts_553] = sqrt (HistIntegral553);
    counts_553++;
  }
  aveAllts12Irrad553 = aveAllts12Irrad553/counts_553;
  maxAllts12Irrad553 = maxAllts12Irrad553/counts_553;
  minAllts12Irrad553 = minAllts12Irrad553/counts_553;
  aveAllErrts12Irrad553 = maxAllts12Irrad553 - minAllts12Irrad553;

  ULong64_t events554;
  events554 = (Double_t)outputTree554 -> GetEntries();

  for (ULong64_t j = 0 ; j < events554 ; j++){
    outputTree554 -> GetEvent(j);
    UCNIntegralArray554[j] = UCNIntegral554;
    UCNIntegralErrArray554[j] = UCNIntegralErr554;
    HistIntegralArray554[j] = HistIntegral554;
    HistIntegralErrArray554[j] = sqrt (HistIntegral554);
    avets12IrradArray554[j] = avets12Irrad554;
    avets12ValveOpenArray554[j] = avets12ValveOpen554;
    maxts12IrradArray554[j] = maxts12Irrad554;
    maxts12ValveOpenArray554[j] = maxts12ValveOpen554;
    mints12IrradArray554[j] = mints12Irrad554; 
    mints12ValveOpenArray554[j] = mints12ValveOpen554;
    ts12IrradErr554[j] = maxts12Irrad554 - mints12Irrad554;
    ts12ValveOpenErr554[j] = maxts12ValveOpen554 - mints12ValveOpen554;
    avecurArray554[j] = avecur554;
    maxcurArray554[j] = maxcur554;
    mincurArray554[j] = mincur554;
    ErrcurArray554[j] = maxcur554 - mincur554;
    delaytimeArray554[j] = cycleDelayTime554;
    cycleNumberArray554[j] = cycleNumber554;
    BaselineArray554[j] = Baseline554;
    BaselineIrradArray554[j] = BaselineIrrad554;
    BaselineIrradErrArray554[j] = BaselineIrradErr554;
    FallTimeArray554[j] = FallTime554;
    FallTimeErrArray554[j] = FallTimeErr554;
    RiseTimeArray554[j] = RiseTime554;
    RiseTimeErrArray554[j] = RiseTimeErr554;
    aveAllts12Irrad554 += avets12Irrad554;
    maxAllts12Irrad554 += maxts12Irrad554;
    minAllts12Irrad554 += mints12Irrad554;
    cout << aveAllts12Irrad554 << endl;
    UCNIntegralArrayAll[counts_553+ counts_554] = UCNIntegral554;
    UCNIntegralErrArrayAll[counts_553+ counts_554] = UCNIntegralErr554;
    delayTimeAll[counts_553+ counts_554] = cycleDelayTime554;
    HistIntegralArrayAll[counts_553 + counts_554] = HistIntegral554;
    HistIntegralErrArrayAll[counts_553+counts_554] = sqrt (HistIntegral554);
    counts_554++;
  }
  aveAllts12Irrad554 = aveAllts12Irrad554/counts_554;
  maxAllts12Irrad554 = maxAllts12Irrad554/counts_554;
  minAllts12Irrad554 = minAllts12Irrad554/counts_554;
  aveAllErrts12Irrad554 = maxAllts12Irrad554 - minAllts12Irrad554;

  ULong64_t events555;
  events555 = (Double_t)outputTree555 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events555 ; j++){
    outputTree555 -> GetEvent(j);
    UCNIntegralArray555[counts_555] = UCNIntegral555;
    UCNIntegralErrArray555[counts_555] = UCNIntegralErr555;
    HistIntegralArray555[counts_555] = HistIntegral555;
    HistIntegralErrArray555[counts_555] = sqrt (HistIntegral555);
    avets12IrradArray555[counts_555] = avets12Irrad555;
    avets12ValveOpenArray555[counts_555] = avets12ValveOpen555;
    maxts12IrradArray555[counts_555] = maxts12Irrad555;
    maxts12ValveOpenArray555[counts_555] = maxts12ValveOpen555;
    mints12IrradArray555[counts_555] = mints12Irrad555; 
    mints12ValveOpenArray555[counts_555] = mints12ValveOpen555;
    ts12IrradErr555[counts_555] = maxts12Irrad555 - mints12Irrad555;
    ts12ValveOpenErr555[counts_555] = maxts12ValveOpen555 - mints12ValveOpen555;
    avecurArray555[counts_555] = avecur555;
    maxcurArray555[counts_555] = maxcur555;
    mincurArray555[counts_555] = mincur555;
    ErrcurArray555[counts_555] = maxcur555 - mincur555;
    delaytimeArray555[counts_555] = cycleDelayTime555;
    cycleNumberArray555[counts_555] = cycleNumber555;
    BaselineArray555[counts_555] = Baseline555;
    BaselineIrradArray555[counts_555] = BaselineIrrad555;
    BaselineIrradErrArray555[counts_555] = BaselineIrradErr555;
    FallTimeArray555[counts_555] = FallTime555;
    FallTimeErrArray555[counts_555] = FallTimeErr555;
    RiseTimeArray555[counts_555] = RiseTime555;
    RiseTimeErrArray555[counts_555] = RiseTimeErr555;
    aveAllts12Irrad555 += avets12Irrad555;
    maxAllts12Irrad555 += maxts12Irrad555;
    minAllts12Irrad555 += mints12Irrad555;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555] = UCNIntegral555;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555] = UCNIntegralErr555;
    delayTimeAll[counts_553+ counts_554+counts_555] = cycleDelayTime555;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555] = HistIntegral555;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555] = sqrt (HistIntegral555);
    counts_555++;
  }
  aveAllts12Irrad555 = aveAllts12Irrad555/counts_555;
  maxAllts12Irrad555 = maxAllts12Irrad555/counts_555;
  minAllts12Irrad555 = minAllts12Irrad555/counts_555;
  aveAllErrts12Irrad555 = maxAllts12Irrad555 - minAllts12Irrad555;
  
  ULong64_t events556;
  events556 = (Double_t)outputTree556 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events556 ; j++){
    outputTree556 -> GetEvent(j);
    UCNIntegralArray556[j] = UCNIntegral556;
    UCNIntegralErrArray556[j] = UCNIntegralErr556;
    HistIntegralArray556[j] = HistIntegral556;
    HistIntegralErrArray556[j] = sqrt (HistIntegral556);
    avets12IrradArray556[j] = avets12Irrad556;
    avets12ValveOpenArray556[j] = avets12ValveOpen556;
    maxts12IrradArray556[j] = maxts12Irrad556;
    maxts12ValveOpenArray556[j] = maxts12ValveOpen556;
    mints12IrradArray556[j] = mints12Irrad556; 
    mints12ValveOpenArray556[j] = mints12ValveOpen556;
    ts12IrradErr556[j] = maxts12Irrad556 - mints12Irrad556;
    ts12ValveOpenErr556[j] = maxts12ValveOpen556 - mints12ValveOpen556;
    avecurArray556[j] = avecur556;
    maxcurArray556[j] = maxcur556;
    mincurArray556[j] = mincur556;
    ErrcurArray556[j] = maxcur556 - mincur556;
    delaytimeArray556[j] = cycleDelayTime556;
    cycleNumberArray556[j] = cycleNumber556;
    BaselineArray556[j] = Baseline556;
    BaselineIrradArray556[j] = BaselineIrrad556;
    BaselineIrradErrArray556[j] = BaselineIrradErr556;
    FallTimeArray556[j] = FallTime556;
    FallTimeErrArray556[j] = FallTimeErr556;
    RiseTimeArray556[j] = RiseTime556;
    RiseTimeErrArray556[j] = RiseTimeErr556;
    aveAllts12Irrad556 += avets12Irrad556;
    maxAllts12Irrad556 += maxts12Irrad556;
    minAllts12Irrad556 += mints12Irrad556;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555+counts_556] = UCNIntegral556;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555+counts_556] = UCNIntegralErr556;
    delayTimeAll[counts_553+ counts_554+counts_555+counts_556] = cycleDelayTime556;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555+ counts_556] = HistIntegral556;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555+counts_556] = sqrt (HistIntegral556);
    counts_556++;
  }
  aveAllts12Irrad556 = aveAllts12Irrad556/counts_556;
  maxAllts12Irrad556 = maxAllts12Irrad556/counts_556;
  minAllts12Irrad556 = minAllts12Irrad556/counts_556;
  aveAllErrts12Irrad556 = maxAllts12Irrad556 - minAllts12Irrad556;
  
  ULong64_t events557;
  events557 = (Double_t)outputTree557 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events557 ; j++){
    outputTree557 -> GetEvent(j);
    if (j == 4)
      continue;
    UCNIntegralArray557[counts_557] = UCNIntegral557;
    UCNIntegralErrArray557[counts_557] = UCNIntegralErr557;
    HistIntegralArray557[counts_557] = HistIntegral557;
    HistIntegralErrArray557[counts_557] = sqrt (HistIntegral557);
    avets12IrradArray557[counts_557] = avets12Irrad557;
    avets12ValveOpenArray557[counts_557] = avets12ValveOpen557;
    maxts12IrradArray557[counts_557] = maxts12Irrad557;
    maxts12ValveOpenArray557[counts_557] = maxts12ValveOpen557;
    mints12IrradArray557[counts_557] = mints12Irrad557; 
    mints12ValveOpenArray557[counts_557] = mints12ValveOpen557;
    ts12IrradErr557[counts_557] = maxts12Irrad557 - mints12Irrad557;
    ts12ValveOpenErr557[counts_557] = maxts12ValveOpen557 - mints12ValveOpen557;
    avecurArray557[counts_557] = avecur557;
    maxcurArray557[counts_557] = maxcur557;
    mincurArray557[counts_557] = mincur557;
    ErrcurArray557[counts_557] = maxcur557 - mincur557;
    delaytimeArray557[counts_557] = cycleDelayTime557;
    cycleNumberArray557[counts_557] = cycleNumber557;
    BaselineArray557[counts_557] = Baseline557;
    BaselineIrradArray557[counts_557] = BaselineIrrad557;
    BaselineIrradErrArray557[counts_557] = BaselineIrradErr557;
    FallTimeArray557[counts_557] = FallTime557;
    FallTimeErrArray557[counts_557] = FallTimeErr557;
    RiseTimeArray557[counts_557] = RiseTime557;
    RiseTimeErrArray557[counts_557] = RiseTimeErr557;
    aveAllts12Irrad557 += avets12Irrad557;
    maxAllts12Irrad557 += maxts12Irrad557;
    minAllts12Irrad557 += mints12Irrad557;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557] = UCNIntegral557;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557] = UCNIntegralErr557;
    delayTimeAll[counts_553+ counts_554+counts_555+counts_556+ counts_557] = cycleDelayTime557;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555+ counts_556+counts_557] = HistIntegral557;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555+counts_556+counts_557] = sqrt (HistIntegral557);
    counts_557++;
  }
  aveAllts12Irrad557 = aveAllts12Irrad557/counts_557;
  maxAllts12Irrad557 = maxAllts12Irrad557/counts_557;
  minAllts12Irrad557 = minAllts12Irrad557/counts_557;
  aveAllErrts12Irrad557 = maxAllts12Irrad557 - minAllts12Irrad557;
  /*
  ULong64_t events558;
  events558 = (Double_t)outputTree558 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events558 ; j++){
    outputTree558 -> GetEvent(j);
    UCNIntegralArray558[counts_558] = UCNIntegral558;
    UCNIntegralErrArray558[counts_558] = UCNIntegralErr558;
    HistIntegralArray558[counts_558] = HistIntegral558;
    HistIntegralErrArray558[counts_558] = sqrt (HistIntegral558);
    avets12IrradArray558[counts_558] = avets12Irrad558;
    avets12ValveOpenArray558[counts_558] = avets12ValveOpen558;
    maxts12IrradArray558[counts_558] = maxts12Irrad558;
    maxts12ValveOpenArray558[counts_558] = maxts12ValveOpen558;
    mints12IrradArray558[counts_558] = mints12Irrad558; 
    mints12ValveOpenArray558[counts_558] = mints12ValveOpen558;
    ts12IrradErr558[counts_558] = maxts12Irrad558 - mints12Irrad558;
    ts12ValveOpenErr558[counts_558] = maxts12ValveOpen558 - mints12ValveOpen558;
    avecurArray558[counts_558] = avecur558;
    maxcurArray558[counts_558] = maxcur558;
    mincurArray558[counts_558] = mincur558;
    ErrcurArray558[counts_558] = maxcur558 - mincur558;
    delaytimeArray558[counts_558] = cycleDelayTime558;
    cycleNumberArray558[counts_558] = cycleNumber558;
    BaselineArray558[counts_558] = Baseline558;
    BaselineIrradArray558[counts_558] = BaselineIrrad558;
    BaselineIrradErrArray558[counts_558] = BaselineIrradErr558;
    FallTimeArray558[counts_558] = FallTime558;
    FallTimeErrArray558[counts_558] = FallTimeErr558;
    RiseTimeArray558[counts_558] = RiseTime558;
    RiseTimeErrArray558[counts_558] = RiseTimeErr558;
    aveAllts12Irrad558 += avets12Irrad558;
    maxAllts12Irrad558 += maxts12Irrad558;
    minAllts12Irrad558 += mints12Irrad558;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557 + counts_558] = UCNIntegral558;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557+counts_558] = UCNIntegralErr558;
    delayTimeAll[counts_553+ counts_554+counts_555+counts_556+ counts_557+counts_558] = cycleDelayTime558;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555+ counts_556+counts_557+counts_558] = HistIntegral558;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555+counts_556+counts_557+counts_558] = sqrt (HistIntegral558);
    counts_558++;
  }
  aveAllts12Irrad558 = aveAllts12Irrad558/counts_558;
  maxAllts12Irrad558 = maxAllts12Irrad558/counts_558;
  minAllts12Irrad558 = minAllts12Irrad558/counts_558;
  aveAllErrts12Irrad558 = maxAllts12Irrad558 - minAllts12Irrad558;
*/



  ULong64_t events559;
  events559 = (Double_t)outputTree559 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events559 ; j++){
    outputTree559 -> GetEvent(j);
    UCNIntegralArray559[counts_559] = UCNIntegral559;
    UCNIntegralErrArray559[counts_559] = UCNIntegralErr559;
    HistIntegralArray559[counts_559] = HistIntegral559;
    HistIntegralErrArray559[counts_559] = sqrt (HistIntegral559);
    avets12IrradArray559[counts_559] = avets12Irrad559;
    avets12ValveOpenArray559[counts_559] = avets12ValveOpen559;
    maxts12IrradArray559[counts_559] = maxts12Irrad559;
    maxts12ValveOpenArray559[counts_559] = maxts12ValveOpen559;
    mints12IrradArray559[counts_559] = mints12Irrad559; 
    mints12ValveOpenArray559[counts_559] = mints12ValveOpen559;
    ts12IrradErr559[counts_559] = maxts12Irrad559 - mints12Irrad559;
    ts12ValveOpenErr559[counts_559] = maxts12ValveOpen559 - mints12ValveOpen559;
    avecurArray559[counts_559] = avecur559;
    maxcurArray559[counts_559] = maxcur559;
    mincurArray559[counts_559] = mincur559;
    ErrcurArray559[counts_559] = maxcur559 - mincur559;
    delaytimeArray559[counts_559] = cycleDelayTime559;
    cycleNumberArray559[counts_559] = cycleNumber559;
    BaselineArray559[counts_559] = Baseline559;
    BaselineIrradArray559[counts_559] = BaselineIrrad559;
    BaselineIrradErrArray559[counts_559] = BaselineIrradErr559;
    FallTimeArray559[counts_559] = FallTime559;
    FallTimeErrArray559[counts_559] = FallTimeErr559;
    RiseTimeArray559[counts_559] = RiseTime559;
    RiseTimeErrArray559[counts_559] = RiseTimeErr559;
    aveAllts12Irrad559 += avets12Irrad559;
    maxAllts12Irrad559 += maxts12Irrad559;
    minAllts12Irrad559 += mints12Irrad559;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557 + counts_558+counts_559] = UCNIntegral559;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557+ counts_558+ counts_559] = UCNIntegralErr559;
    delayTimeAll[counts_553+ counts_554+counts_555+counts_556+ counts_557+ counts_558+ counts_559] = cycleDelayTime559;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555+ counts_556+counts_557+ counts_558+ counts_559] = HistIntegral559;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555+counts_556+counts_557+ counts_558+ counts_559] = sqrt (HistIntegral559);
    counts_559++;
  }
  aveAllts12Irrad559 = aveAllts12Irrad559/counts_559;
  maxAllts12Irrad559 = maxAllts12Irrad559/counts_559;
  minAllts12Irrad559 = minAllts12Irrad559/counts_559;
  aveAllErrts12Irrad559 = maxAllts12Irrad559 - minAllts12Irrad559;




  ULong64_t events560;
  events560 = (Double_t)outputTree560 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events560 ; j++){
    outputTree560 -> GetEvent(j);
    if (j==1)
      continue;
    UCNIntegralArray560[counts_560] = UCNIntegral560;
    UCNIntegralErrArray560[counts_560] = UCNIntegralErr560;
    HistIntegralArray560[counts_560] = HistIntegral560;
    HistIntegralErrArray560[counts_560] = sqrt (HistIntegral560);
    avets12IrradArray560[counts_560] = avets12Irrad560;
    avets12ValveOpenArray560[counts_560] = avets12ValveOpen560;
    maxts12IrradArray560[counts_560] = maxts12Irrad560;
    maxts12ValveOpenArray560[counts_560] = maxts12ValveOpen560;
    mints12IrradArray560[counts_560] = mints12Irrad560; 
    mints12ValveOpenArray560[counts_560] = mints12ValveOpen560;
    ts12IrradErr560[counts_560] = maxts12Irrad560 - mints12Irrad560;
    ts12ValveOpenErr560[counts_560] = maxts12ValveOpen560 - mints12ValveOpen560;
    avecurArray560[counts_560] = avecur560;
    maxcurArray560[counts_560] = maxcur560;
    mincurArray560[counts_560] = mincur560;
    ErrcurArray560[counts_560] = maxcur560 - mincur560;
    delaytimeArray560[counts_560] = cycleDelayTime560;
    cycleNumberArray560[counts_560] = cycleNumber560;
    BaselineArray560[counts_560] = Baseline560;
    BaselineIrradArray560[counts_560] = BaselineIrrad560;
    BaselineIrradErrArray560[counts_560] = BaselineIrradErr560;
    FallTimeArray560[counts_560] = FallTime560;
    FallTimeErrArray560[counts_560] = FallTimeErr560;
    RiseTimeArray560[counts_560] = RiseTime560;
    RiseTimeErrArray560[counts_560] = RiseTimeErr560;
    aveAllts12Irrad560 += avets12Irrad560;
    maxAllts12Irrad560 += maxts12Irrad560;
    minAllts12Irrad560 += mints12Irrad560;
    UCNIntegralArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557 + counts_558+counts_559+counts_560] = UCNIntegral560;
    UCNIntegralErrArrayAll[counts_553+ counts_554+counts_555+counts_556 + counts_557+counts_558+counts_559+counts_560] = UCNIntegralErr560;
    delayTimeAll[counts_553+ counts_554+counts_555+counts_556+ counts_557+counts_558+counts_559+counts_560] = cycleDelayTime560;
    HistIntegralArrayAll[counts_553 + counts_554+ counts_555+ counts_556+counts_557+counts_558+counts_559+counts_560] = HistIntegral560;
    HistIntegralErrArrayAll[counts_553+counts_554+counts_555+counts_556+counts_557+counts_558+counts_559+counts_560] = sqrt (HistIntegral560);
    counts_560++;
  }
  aveAllts12Irrad560 = aveAllts12Irrad560/counts_560;
  maxAllts12Irrad560 = maxAllts12Irrad560/counts_560;
  minAllts12Irrad560 = minAllts12Irrad560/counts_560;
  aveAllErrts12Irrad560 = maxAllts12Irrad560 - minAllts12Irrad560;


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
  //              553
  //*********************************
  //*********************************
  TCanvas *c553 = new TCanvas("c553" , "c553" , 1200, 800);
  c553 -> Divide(2,2);
  //c553 -> cd(1);
  TPad *p1 = c553->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr553_delaycounts = new TGraphErrors(counts_553, delaytimeArray553 , UCNIntegralArray553, 0, UCNIntegralErrArray553);

  gr553_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr553_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr553_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr553_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr553_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_delaycounts -> SetMarkerStyle(7);
  gr553_delaycounts -> Fit(fit);
  storage553 = fit -> GetParameter(1);
  storageErr553 = fit -> GetParError(1);
  
  TGraphErrors *gr553_delayhist = new TGraphErrors(counts_553, delaytimeArray553 , HistIntegralArray553, 0, HistIntegralErrArray553);

  gr553_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr553_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr553_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr553_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr553_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr553_delayhist -> SetMarkerColor(2);
  gr553_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr553_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr553_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr553_delaycounts -> Draw("Ap");
  gr553_delayhist -> Draw("p");
  leg2 -> Draw();

  //c553 -> cd(2);
  TPad *p2 = c553->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr553_tempIrradcounts = new TGraphErrors (counts_553 , avets12IrradArray553, UCNIntegralArray553 , ts12IrradErr553 , UCNIntegralErrArray553);
  gr553_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr553_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr553_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr553_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr553_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr553_tempValveOpencounts = new TGraphErrors (counts_553 , avets12ValveOpenArray553, UCNIntegralArray553 , ts12ValveOpenErr553 , UCNIntegralErrArray553);
  gr553_tempValveOpencounts -> SetMarkerStyle(7);
  gr553_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr553_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr553_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr553_tempIrradcounts -> Draw("Ap");
  gr553_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c553 -> cd(3);
  TGraphErrors *gr553_delaytempIrrad = new TGraphErrors (counts_553 , delaytimeArray553, avets12IrradArray553, 0 , ts12IrradErr553);

  gr553_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr553_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr553_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr553_delaytempIrrad -> SetMarkerStyle(7);
  gr553_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr553_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr553_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr553_delaytempValveOpen = new TGraphErrors (counts_553 , delaytimeArray553, avets12ValveOpenArray553, 0 , ts12ValveOpenErr553);

  gr553_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr553_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr553_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr553_delaytempValveOpen -> SetMarkerStyle(7);
  gr553_delaytempValveOpen -> SetMarkerColor(2);
  gr553_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr553_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr553_delaytempIrrad -> Draw("AP");
  gr553_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c553->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr553_curcounts = new TGraphErrors (counts_553 , avecurArray553, UCNIntegralArray553 , ErrcurArray553 , UCNIntegralErrArray553);
  gr553_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr553_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr553_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr553_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr553_curhist = new TGraphErrors (counts_553 , avecurArray553, UCNIntegralArray553 , ErrcurArray553 , UCNIntegralErrArray553);
  gr553_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr553_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr553_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr553_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr553_curhist -> SetMarkerColor(2);
  gr553_curhist -> SetMarkerStyle(7);

  gr553_curcounts -> Draw("Ap");
  gr553_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c553_cycleNum = new TCanvas("c553_cycleNum" , "c553_cycleNum" , 1200, 800);
  c553_cycleNum -> Divide(2,2);
  TPad *p5 = c553_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr553_cyclecounts = new TGraphErrors (counts_553 , cycleNumberArray553, UCNIntegralArray553, 0 , UCNIntegralErrArray553);
  gr553_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr553_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr553_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr553_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr553_cyclehist = new TGraphErrors(counts_553, cycleNumberArray553 , HistIntegralArray553, 0, HistIntegralErrArray553);

  gr553_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr553_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr553_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr553_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr553_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr553_cyclehist -> SetMarkerColor(2);
  gr553_cyclehist -> SetMarkerStyle(7);

  gr553_cyclecounts -> Draw("Ap");
  gr553_cyclehist -> Draw("p");

  leg2-> Draw();

  c553_cycleNum -> cd(2);
 TGraphErrors *gr553_cycledelay = new TGraphErrors (counts_553 , cycleNumberArray553, delaytimeArray553, 0 , 0);
  gr553_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr553_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr553_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr553_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cycledelay -> SetMarkerStyle(7);

  gr553_cycledelay -> Draw("Ap");


  c553_cycleNum -> cd(3);
  TGraphErrors *gr553_cycletempIrrad = new TGraphErrors (counts_553 , cycleNumberArray553, avets12IrradArray553, 0 , ts12IrradErr553);

  gr553_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr553_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr553_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr553_cycletempIrrad -> SetMarkerStyle(7);
  gr553_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr553_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr553_cycletempValveOpen = new TGraphErrors (counts_553 , cycleNumberArray553, avets12ValveOpenArray553, 0 , ts12ValveOpenErr553);

  gr553_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr553_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr553_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr553_cycletempValveOpen -> SetMarkerStyle(7);
  gr553_cycletempValveOpen -> SetMarkerColor(2);
  gr553_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr553_cycletempIrrad -> Draw("AP");
  gr553_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c553_cycleNum -> cd(4);
  TGraphErrors *gr553_cyclecur = new TGraphErrors (counts_553 , cycleNumberArray553 , avecurArray553, 0, ErrcurArray553 );
  gr553_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr553_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr553_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr553_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclecur -> SetMarkerStyle(7);
  gr553_cyclecur -> Draw("Ap");


  TCanvas *c553_cycleNumFit = new TCanvas("c553_cycleNumFit" , "c553_cycleNumFit" , 1200, 800);
  c553_cycleNumFit -> Divide(2,2);

  c553_cycleNumFit -> cd(1);
  TGraphErrors *gr553_cyclefall = new TGraphErrors (counts_553, cycleNumberArray553, FallTimeArray553 , 0, FallTimeErrArray553);

  gr553_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr553_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr553_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr553_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclefall -> SetMarkerStyle(7);
  gr553_cyclefall -> Draw("Ap");


  c553_cycleNumFit -> cd(2);
  TGraphErrors *gr553_cyclebaseline = new TGraphErrors (counts_553, cycleNumberArray553, BaselineArray553 , 0, BaselineErrArray553);

  gr553_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr553_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr553_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr553_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclebaseline -> SetMarkerStyle(7);
  gr553_cyclebaseline -> Draw("Ap");

  c553_cycleNumFit -> cd(3);
  TGraphErrors *gr553_cyclebaselineirrad = new TGraphErrors (counts_553, cycleNumberArray553, BaselineIrradArray553 , 0, BaselineIrradErrArray553);

  gr553_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr553_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr553_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr553_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclebaselineirrad -> SetMarkerStyle(7);
  gr553_cyclebaselineirrad -> Draw("Ap");

  c553_cycleNumFit -> cd(4);
  TGraphErrors *gr553_cyclerise = new TGraphErrors (counts_553, cycleNumberArray553, RiseTimeArray553 , 0, RiseTimeErrArray553);

  gr553_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr553_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr553_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr553_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr553_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr553_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr553_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr553_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr553_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr553_cyclerise -> SetMarkerStyle(7);
  gr553_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              554
  //*********************************
  //*********************************
  TCanvas *c554 = new TCanvas("c554" , "c554" , 1200, 800);
  c554 -> Divide(2,2);
  //c554 -> cd(1);
  TPad *p554_1 = c554->cd(1);
  p554_1->SetLogy(); 
  TGraphErrors *gr554_delaycounts = new TGraphErrors(counts_554, delaytimeArray554 , UCNIntegralArray554, 0, UCNIntegralErrArray554);

  gr554_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr554_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr554_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr554_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr554_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_delaycounts -> SetMarkerStyle(7);
  gr554_delaycounts -> Fit(fit);
  storage554 = fit -> GetParameter(1);
  storageErr554 = fit -> GetParError(1);
  
  TGraphErrors *gr554_delayhist = new TGraphErrors(counts_554, delaytimeArray554 , HistIntegralArray554, 0, HistIntegralErrArray554);

  gr554_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr554_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr554_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr554_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr554_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr554_delayhist -> SetMarkerColor(2);
  gr554_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr554_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr554_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr554_delaycounts -> Draw("Ap");
  gr554_delayhist -> Draw("p");
  leg2 -> Draw();

  //c554 -> cd(2);
  TPad *p554_2 = c554->cd(2);
  p554_2->SetLogy(); 
  TGraphErrors *gr554_tempIrradcounts = new TGraphErrors (counts_554 , avets12IrradArray554, UCNIntegralArray554 , ts12IrradErr554 , UCNIntegralErrArray554);
  gr554_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr554_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr554_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr554_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr554_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr554_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr554_tempValveOpencounts = new TGraphErrors (counts_554 , avets12ValveOpenArray554, UCNIntegralArray554 , ts12ValveOpenErr554 , UCNIntegralErrArray554);
  gr554_tempValveOpencounts -> SetMarkerStyle(7);
  gr554_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr554_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr554_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr554_tempIrradcounts -> Draw("Ap");
  gr554_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c554 -> cd(3);
  TGraphErrors *gr554_delaytempIrrad = new TGraphErrors (counts_554 , delaytimeArray554, avets12IrradArray554, 0 , ts12IrradErr554);

  gr554_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr554_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr554_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr554_delaytempIrrad -> SetMarkerStyle(7);
  gr554_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr554_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr554_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr554_delaytempValveOpen = new TGraphErrors (counts_554 , delaytimeArray554, avets12ValveOpenArray554, 0 , ts12ValveOpenErr554);

  gr554_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr554_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr554_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr554_delaytempValveOpen -> SetMarkerStyle(7);
  gr554_delaytempValveOpen -> SetMarkerColor(2);
  gr554_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr554_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr554_delaytempIrrad -> Draw("AP");
  gr554_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p554_3 = c554->cd(4);
  p554_3->SetLogy(); 
  TGraphErrors *gr554_curcounts = new TGraphErrors (counts_554 , avecurArray554, UCNIntegralArray554 , ErrcurArray554 , UCNIntegralErrArray554);
  gr554_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr554_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr554_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr554_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr554_curhist = new TGraphErrors (counts_554 , avecurArray554, UCNIntegralArray554 , ErrcurArray554 , UCNIntegralErrArray554);
  gr554_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr554_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr554_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr554_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr554_curhist -> SetMarkerColor(2);
  gr554_curhist -> SetMarkerStyle(7);

  gr554_curcounts -> Draw("Ap");
  gr554_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c554_cycleNum = new TCanvas("c554_cycleNum" , "c554_cycleNum" , 1200, 800);
  c554_cycleNum -> Divide(2,2);
  TPad *p554_4 = c554_cycleNum->cd(1);
  p554_4->SetLogy(); 
  TGraphErrors *gr554_cyclecounts = new TGraphErrors (counts_554 , cycleNumberArray554, UCNIntegralArray554, 0 , UCNIntegralErrArray554);
  gr554_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr554_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr554_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr554_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr554_cyclehist = new TGraphErrors(counts_554, cycleNumberArray554 , HistIntegralArray554, 0, HistIntegralErrArray554);

  gr554_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr554_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr554_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr554_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr554_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr554_cyclehist -> SetMarkerColor(2);
  gr554_cyclehist -> SetMarkerStyle(7);

  gr554_cyclecounts -> Draw("Ap");
  gr554_cyclehist -> Draw("p");

  leg2-> Draw();

  c554_cycleNum -> cd(2);
 TGraphErrors *gr554_cycledelay = new TGraphErrors (counts_554 , cycleNumberArray554, delaytimeArray554, 0 , 0);
  gr554_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr554_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr554_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr554_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cycledelay -> SetMarkerStyle(7);

  gr554_cycledelay -> Draw("Ap");


  c554_cycleNum -> cd(3);
  TGraphErrors *gr554_cycletempIrrad = new TGraphErrors (counts_554 , cycleNumberArray554, avets12IrradArray554, 0 , ts12IrradErr554);

  gr554_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr554_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr554_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr554_cycletempIrrad -> SetMarkerStyle(7);
  gr554_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr554_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr554_cycletempValveOpen = new TGraphErrors (counts_554 , cycleNumberArray554, avets12ValveOpenArray554, 0 , ts12ValveOpenErr554);

  gr554_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr554_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr554_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr554_cycletempValveOpen -> SetMarkerStyle(7);
  gr554_cycletempValveOpen -> SetMarkerColor(2);
  gr554_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr554_cycletempIrrad -> Draw("AP");
  gr554_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c554_cycleNum -> cd(4);
  TGraphErrors *gr554_cyclecur = new TGraphErrors (counts_554 , cycleNumberArray554 , avecurArray554, 0, ErrcurArray554 );
  gr554_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr554_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr554_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr554_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclecur -> SetMarkerStyle(7);
  gr554_cyclecur -> Draw("Ap");


  TCanvas *c554_cycleNumFit = new TCanvas("c554_cycleNumFit" , "c554_cycleNumFit" , 1200, 800);
  c554_cycleNumFit -> Divide(2,2);

  c554_cycleNumFit -> cd(1);
  TGraphErrors *gr554_cyclefall = new TGraphErrors (counts_554, cycleNumberArray554, FallTimeArray554 , 0, FallTimeErrArray554);

  gr554_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr554_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr554_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr554_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclefall -> SetMarkerStyle(7);
  gr554_cyclefall -> Draw("Ap");


  c554_cycleNumFit -> cd(2);
  TGraphErrors *gr554_cyclebaseline = new TGraphErrors (counts_554, cycleNumberArray554, BaselineArray554 , 0, BaselineErrArray554);

  gr554_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr554_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr554_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr554_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclebaseline -> SetMarkerStyle(7);
  gr554_cyclebaseline -> Draw("Ap");

  c554_cycleNumFit -> cd(3);
  TGraphErrors *gr554_cyclebaselineirrad = new TGraphErrors (counts_554, cycleNumberArray554, BaselineIrradArray554 , 0, BaselineIrradErrArray554);

  gr554_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr554_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr554_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr554_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclebaselineirrad -> SetMarkerStyle(7);
  gr554_cyclebaselineirrad -> Draw("Ap");

  c554_cycleNumFit -> cd(4);
  TGraphErrors *gr554_cyclerise = new TGraphErrors (counts_554, cycleNumberArray554, RiseTimeArray554 , 0, RiseTimeErrArray554);

  gr554_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr554_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr554_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr554_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr554_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr554_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr554_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr554_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr554_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr554_cyclerise -> SetMarkerStyle(7);
  gr554_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              555
  //*********************************
  //*********************************
  TCanvas *c555 = new TCanvas("c555" , "c555" , 1200, 800);
  c555 -> Divide(2,2);
  //c555 -> cd(1);
  TPad *p555_1 = c555->cd(1);
  p555_1->SetLogy(); 
  TGraphErrors *gr555_delaycounts = new TGraphErrors(counts_555, delaytimeArray555 , UCNIntegralArray555, 0, UCNIntegralErrArray555);

  gr555_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr555_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr555_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr555_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr555_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_delaycounts -> SetMarkerStyle(7);
  gr555_delaycounts -> Fit(fit);
  storage555 = fit -> GetParameter(1);
  storageErr555 = fit -> GetParError(1);
  
  TGraphErrors *gr555_delayhist = new TGraphErrors(counts_555, delaytimeArray555 , HistIntegralArray555, 0, HistIntegralErrArray555);

  gr555_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr555_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr555_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr555_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr555_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr555_delayhist -> SetMarkerColor(2);
  gr555_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr555_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr555_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr555_delaycounts -> Draw("Ap");
  gr555_delayhist -> Draw("p");
  leg2 -> Draw();

  //c555 -> cd(2);
  TPad *p555_2 = c555->cd(2);
  p555_2->SetLogy(); 
  TGraphErrors *gr555_tempIrradcounts = new TGraphErrors (counts_555 , avets12IrradArray555, UCNIntegralArray555 , ts12IrradErr555 , UCNIntegralErrArray555);
  gr555_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr555_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr555_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr555_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr555_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr555_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr555_tempValveOpencounts = new TGraphErrors (counts_555 , avets12ValveOpenArray555, UCNIntegralArray555 , ts12ValveOpenErr555 , UCNIntegralErrArray555);
  gr555_tempValveOpencounts -> SetMarkerStyle(7);
  gr555_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr555_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr555_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr555_tempIrradcounts -> Draw("Ap");
  gr555_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c555 -> cd(3);
  TGraphErrors *gr555_delaytempIrrad = new TGraphErrors (counts_555 , delaytimeArray555, avets12IrradArray555, 0 , ts12IrradErr555);

  gr555_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr555_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr555_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr555_delaytempIrrad -> SetMarkerStyle(7);
  gr555_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr555_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr555_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr555_delaytempValveOpen = new TGraphErrors (counts_555 , delaytimeArray555, avets12ValveOpenArray555, 0 , ts12ValveOpenErr555);

  gr555_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr555_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr555_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr555_delaytempValveOpen -> SetMarkerStyle(7);
  gr555_delaytempValveOpen -> SetMarkerColor(2);
  gr555_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr555_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr555_delaytempIrrad -> Draw("AP");
  gr555_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p555_3 = c555->cd(4);
  p555_3->SetLogy(); 
  TGraphErrors *gr555_curcounts = new TGraphErrors (counts_555 , avecurArray555, UCNIntegralArray555 , ErrcurArray555 , UCNIntegralErrArray555);
  gr555_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr555_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr555_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr555_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr555_curhist = new TGraphErrors (counts_555 , avecurArray555, UCNIntegralArray555 , ErrcurArray555 , UCNIntegralErrArray555);
  gr555_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr555_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr555_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr555_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr555_curhist -> SetMarkerColor(2);
  gr555_curhist -> SetMarkerStyle(7);

  gr555_curcounts -> Draw("Ap");
  gr555_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c555_cycleNum = new TCanvas("c555_cycleNum" , "c555_cycleNum" , 1200, 800);
  c555_cycleNum -> Divide(2,2);
  TPad *p555_4 = c555_cycleNum->cd(1);
  p555_4->SetLogy(); 
  TGraphErrors *gr555_cyclecounts = new TGraphErrors (counts_555 , cycleNumberArray555, UCNIntegralArray555, 0 , UCNIntegralErrArray555);
  gr555_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr555_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr555_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr555_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr555_cyclehist = new TGraphErrors(counts_555, cycleNumberArray555 , HistIntegralArray555, 0, HistIntegralErrArray555);

  gr555_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr555_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr555_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr555_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr555_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr555_cyclehist -> SetMarkerColor(2);
  gr555_cyclehist -> SetMarkerStyle(7);

  gr555_cyclecounts -> Draw("Ap");
  gr555_cyclehist -> Draw("p");

  leg2-> Draw();

  c555_cycleNum -> cd(2);
 TGraphErrors *gr555_cycledelay = new TGraphErrors (counts_555 , cycleNumberArray555, delaytimeArray555, 0 , 0);
  gr555_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr555_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr555_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr555_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cycledelay -> SetMarkerStyle(7);

  gr555_cycledelay -> Draw("Ap");


  c555_cycleNum -> cd(3);
  TGraphErrors *gr555_cycletempIrrad = new TGraphErrors (counts_555 , cycleNumberArray555, avets12IrradArray555, 0 , ts12IrradErr555);

  gr555_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr555_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr555_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr555_cycletempIrrad -> SetMarkerStyle(7);
  gr555_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr555_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr555_cycletempValveOpen = new TGraphErrors (counts_555 , cycleNumberArray555, avets12ValveOpenArray555, 0 , ts12ValveOpenErr555);

  gr555_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr555_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr555_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr555_cycletempValveOpen -> SetMarkerStyle(7);
  gr555_cycletempValveOpen -> SetMarkerColor(2);
  gr555_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr555_cycletempIrrad -> Draw("AP");
  gr555_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c555_cycleNum -> cd(4);
  TGraphErrors *gr555_cyclecur = new TGraphErrors (counts_555 , cycleNumberArray555 , avecurArray555, 0, ErrcurArray555 );
  gr555_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr555_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr555_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr555_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclecur -> SetMarkerStyle(7);
  gr555_cyclecur -> Draw("Ap");


  TCanvas *c555_cycleNumFit = new TCanvas("c555_cycleNumFit" , "c555_cycleNumFit" , 1200, 800);
  c555_cycleNumFit -> Divide(2,2);

  c555_cycleNumFit -> cd(1);
  TGraphErrors *gr555_cyclefall = new TGraphErrors (counts_555, cycleNumberArray555, FallTimeArray555 , 0, FallTimeErrArray555);

  gr555_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr555_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr555_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr555_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclefall -> SetMarkerStyle(7);
  gr555_cyclefall -> Draw("Ap");


  c555_cycleNumFit -> cd(2);
  TGraphErrors *gr555_cyclebaseline = new TGraphErrors (counts_555, cycleNumberArray555, BaselineArray555 , 0, BaselineErrArray555);

  gr555_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr555_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr555_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr555_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclebaseline -> SetMarkerStyle(7);
  gr555_cyclebaseline -> Draw("Ap");

  c555_cycleNumFit -> cd(3);
  TGraphErrors *gr555_cyclebaselineirrad = new TGraphErrors (counts_555, cycleNumberArray555, BaselineIrradArray555 , 0, BaselineIrradErrArray555);

  gr555_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr555_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr555_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr555_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclebaselineirrad -> SetMarkerStyle(7);
  gr555_cyclebaselineirrad -> Draw("Ap");

  c555_cycleNumFit -> cd(4);
  TGraphErrors *gr555_cyclerise = new TGraphErrors (counts_555, cycleNumberArray555, RiseTimeArray555 , 0, RiseTimeErrArray555);

  gr555_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr555_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr555_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr555_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr555_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr555_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr555_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr555_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr555_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr555_cyclerise -> SetMarkerStyle(7);
  gr555_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              556
  //*********************************
  //*********************************
  TCanvas *c556 = new TCanvas("c556" , "c556" , 1200, 800);
  c556 -> Divide(2,2);
  //c556 -> cd(1);
  TPad *p556_1 = c556->cd(1);
  p556_1->SetLogy(); 
  TGraphErrors *gr556_delaycounts = new TGraphErrors(counts_556, delaytimeArray556 , UCNIntegralArray556, 0, UCNIntegralErrArray556);

  gr556_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr556_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr556_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr556_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr556_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_delaycounts -> SetMarkerStyle(7);
  gr556_delaycounts -> Fit(fit);
  storage556 = fit -> GetParameter(1);
  storageErr556 = fit -> GetParError(1);
  
  TGraphErrors *gr556_delayhist = new TGraphErrors(counts_556, delaytimeArray556 , HistIntegralArray556, 0, HistIntegralErrArray556);

  gr556_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr556_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr556_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr556_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr556_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr556_delayhist -> SetMarkerColor(2);
  gr556_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr556_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr556_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr556_delaycounts -> Draw("Ap");
  gr556_delayhist -> Draw("p");
  leg2 -> Draw();

  //c556 -> cd(2);
  TPad *p556_2 = c556->cd(2);
  p556_2->SetLogy(); 
  TGraphErrors *gr556_tempIrradcounts = new TGraphErrors (counts_556 , avets12IrradArray556, UCNIntegralArray556 , ts12IrradErr556 , UCNIntegralErrArray556);
  gr556_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr556_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr556_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr556_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr556_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr556_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr556_tempValveOpencounts = new TGraphErrors (counts_556 , avets12ValveOpenArray556, UCNIntegralArray556 , ts12ValveOpenErr556 , UCNIntegralErrArray556);
  gr556_tempValveOpencounts -> SetMarkerStyle(7);
  gr556_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr556_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr556_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr556_tempIrradcounts -> Draw("Ap");
  gr556_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c556 -> cd(3);
  TGraphErrors *gr556_delaytempIrrad = new TGraphErrors (counts_556 , delaytimeArray556, avets12IrradArray556, 0 , ts12IrradErr556);

  gr556_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr556_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr556_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr556_delaytempIrrad -> SetMarkerStyle(7);
  gr556_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr556_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr556_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr556_delaytempValveOpen = new TGraphErrors (counts_556 , delaytimeArray556, avets12ValveOpenArray556, 0 , ts12ValveOpenErr556);

  gr556_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr556_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr556_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr556_delaytempValveOpen -> SetMarkerStyle(7);
  gr556_delaytempValveOpen -> SetMarkerColor(2);
  gr556_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr556_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr556_delaytempIrrad -> Draw("AP");
  gr556_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p556_3 = c556->cd(4);
  p556_3->SetLogy(); 
  TGraphErrors *gr556_curcounts = new TGraphErrors (counts_556 , avecurArray556, UCNIntegralArray556 , ErrcurArray556 , UCNIntegralErrArray556);
  gr556_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr556_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr556_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr556_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr556_curhist = new TGraphErrors (counts_556 , avecurArray556, UCNIntegralArray556 , ErrcurArray556 , UCNIntegralErrArray556);
  gr556_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr556_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr556_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr556_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr556_curhist -> SetMarkerColor(2);
  gr556_curhist -> SetMarkerStyle(7);

  gr556_curcounts -> Draw("Ap");
  gr556_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c556_cycleNum = new TCanvas("c556_cycleNum" , "c556_cycleNum" , 1200, 800);
  c556_cycleNum -> Divide(2,2);
  TPad *p556_4 = c556_cycleNum->cd(1);
  p556_4->SetLogy(); 
  TGraphErrors *gr556_cyclecounts = new TGraphErrors (counts_556 , cycleNumberArray556, UCNIntegralArray556, 0 , UCNIntegralErrArray556);
  gr556_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr556_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr556_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr556_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr556_cyclehist = new TGraphErrors(counts_556, cycleNumberArray556 , HistIntegralArray556, 0, HistIntegralErrArray556);

  gr556_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr556_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr556_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr556_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr556_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr556_cyclehist -> SetMarkerColor(2);
  gr556_cyclehist -> SetMarkerStyle(7);

  gr556_cyclecounts -> Draw("Ap");
  gr556_cyclehist -> Draw("p");

  leg2-> Draw();

  c556_cycleNum -> cd(2);
 TGraphErrors *gr556_cycledelay = new TGraphErrors (counts_556 , cycleNumberArray556, delaytimeArray556, 0 , 0);
  gr556_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr556_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr556_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr556_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cycledelay -> SetMarkerStyle(7);

  gr556_cycledelay -> Draw("Ap");


  c556_cycleNum -> cd(3);
  TGraphErrors *gr556_cycletempIrrad = new TGraphErrors (counts_556 , cycleNumberArray556, avets12IrradArray556, 0 , ts12IrradErr556);

  gr556_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr556_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr556_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr556_cycletempIrrad -> SetMarkerStyle(7);
  gr556_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr556_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr556_cycletempValveOpen = new TGraphErrors (counts_556 , cycleNumberArray556, avets12ValveOpenArray556, 0 , ts12ValveOpenErr556);

  gr556_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr556_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr556_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr556_cycletempValveOpen -> SetMarkerStyle(7);
  gr556_cycletempValveOpen -> SetMarkerColor(2);
  gr556_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr556_cycletempIrrad -> Draw("AP");
  gr556_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c556_cycleNum -> cd(4);
  TGraphErrors *gr556_cyclecur = new TGraphErrors (counts_556 , cycleNumberArray556 , avecurArray556, 0, ErrcurArray556 );
  gr556_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr556_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr556_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr556_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclecur -> SetMarkerStyle(7);
  gr556_cyclecur -> Draw("Ap");


  TCanvas *c556_cycleNumFit = new TCanvas("c556_cycleNumFit" , "c556_cycleNumFit" , 1200, 800);
  c556_cycleNumFit -> Divide(2,2);

  c556_cycleNumFit -> cd(1);
  TGraphErrors *gr556_cyclefall = new TGraphErrors (counts_556, cycleNumberArray556, FallTimeArray556 , 0, FallTimeErrArray556);

  gr556_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr556_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr556_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr556_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclefall -> SetMarkerStyle(7);
  gr556_cyclefall -> Draw("Ap");


  c556_cycleNumFit -> cd(2);
  TGraphErrors *gr556_cyclebaseline = new TGraphErrors (counts_556, cycleNumberArray556, BaselineArray556 , 0, BaselineErrArray556);

  gr556_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr556_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr556_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr556_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclebaseline -> SetMarkerStyle(7);
  gr556_cyclebaseline -> Draw("Ap");

  c556_cycleNumFit -> cd(3);
  TGraphErrors *gr556_cyclebaselineirrad = new TGraphErrors (counts_556, cycleNumberArray556, BaselineIrradArray556 , 0, BaselineIrradErrArray556);

  gr556_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr556_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr556_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr556_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclebaselineirrad -> SetMarkerStyle(7);
  gr556_cyclebaselineirrad -> Draw("Ap");

  c556_cycleNumFit -> cd(4);
  TGraphErrors *gr556_cyclerise = new TGraphErrors (counts_556, cycleNumberArray556, RiseTimeArray556 , 0, RiseTimeErrArray556);

  gr556_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr556_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr556_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr556_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr556_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr556_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr556_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr556_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr556_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr556_cyclerise -> SetMarkerStyle(7);
  gr556_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              557
  //*********************************
  //*********************************
  TCanvas *c557 = new TCanvas("c557" , "c557" , 1200, 800);
  c557 -> Divide(2,2);
  //c557 -> cd(1);
  TPad *p557_1 = c557->cd(1);
  p557_1->SetLogy(); 
  TGraphErrors *gr557_delaycounts = new TGraphErrors(counts_557, delaytimeArray557 , UCNIntegralArray557, 0, UCNIntegralErrArray557);

  gr557_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr557_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr557_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr557_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr557_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_delaycounts -> SetMarkerStyle(7);
  gr557_delaycounts -> Fit(fit);
  storage557 = fit -> GetParameter(1);
  storageErr557 = fit -> GetParError(1);
  
  TGraphErrors *gr557_delayhist = new TGraphErrors(counts_557, delaytimeArray557 , HistIntegralArray557, 0, HistIntegralErrArray557);

  gr557_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr557_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr557_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr557_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr557_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr557_delayhist -> SetMarkerColor(2);
  gr557_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr557_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr557_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr557_delaycounts -> Draw("Ap");
  gr557_delayhist -> Draw("p");
  leg2 -> Draw();

  //c557 -> cd(2);
  TPad *p557_2 = c557->cd(2);
  p557_2->SetLogy(); 
  TGraphErrors *gr557_tempIrradcounts = new TGraphErrors (counts_557 , avets12IrradArray557, UCNIntegralArray557 , ts12IrradErr557 , UCNIntegralErrArray557);
  gr557_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr557_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr557_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr557_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr557_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr557_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr557_tempValveOpencounts = new TGraphErrors (counts_557 , avets12ValveOpenArray557, UCNIntegralArray557 , ts12ValveOpenErr557 , UCNIntegralErrArray557);
  gr557_tempValveOpencounts -> SetMarkerStyle(7);
  gr557_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr557_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr557_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr557_tempIrradcounts -> Draw("Ap");
  gr557_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c557 -> cd(3);
  TGraphErrors *gr557_delaytempIrrad = new TGraphErrors (counts_557 , delaytimeArray557, avets12IrradArray557, 0 , ts12IrradErr557);

  gr557_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr557_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr557_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr557_delaytempIrrad -> SetMarkerStyle(7);
  gr557_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr557_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr557_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr557_delaytempValveOpen = new TGraphErrors (counts_557 , delaytimeArray557, avets12ValveOpenArray557, 0 , ts12ValveOpenErr557);

  gr557_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr557_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr557_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr557_delaytempValveOpen -> SetMarkerStyle(7);
  gr557_delaytempValveOpen -> SetMarkerColor(2);
  gr557_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr557_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr557_delaytempIrrad -> Draw("AP");
  gr557_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p557_3 = c557->cd(4);
  p557_3->SetLogy(); 
  TGraphErrors *gr557_curcounts = new TGraphErrors (counts_557 , avecurArray557, UCNIntegralArray557 , ErrcurArray557 , UCNIntegralErrArray557);
  gr557_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr557_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr557_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr557_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr557_curhist = new TGraphErrors (counts_557 , avecurArray557, UCNIntegralArray557 , ErrcurArray557 , UCNIntegralErrArray557);
  gr557_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr557_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr557_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr557_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr557_curhist -> SetMarkerColor(2);
  gr557_curhist -> SetMarkerStyle(7);

  gr557_curcounts -> Draw("Ap");
  gr557_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c557_cycleNum = new TCanvas("c557_cycleNum" , "c557_cycleNum" , 1200, 800);
  c557_cycleNum -> Divide(2,2);
  TPad *p557_4 = c557_cycleNum->cd(1);
  p557_4->SetLogy(); 
  TGraphErrors *gr557_cyclecounts = new TGraphErrors (counts_557 , cycleNumberArray557, UCNIntegralArray557, 0 , UCNIntegralErrArray557);
  gr557_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr557_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr557_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr557_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr557_cyclehist = new TGraphErrors(counts_557, cycleNumberArray557 , HistIntegralArray557, 0, HistIntegralErrArray557);

  gr557_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr557_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr557_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr557_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr557_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr557_cyclehist -> SetMarkerColor(2);
  gr557_cyclehist -> SetMarkerStyle(7);

  gr557_cyclecounts -> Draw("Ap");
  gr557_cyclehist -> Draw("p");

  leg2-> Draw();

  c557_cycleNum -> cd(2);
 TGraphErrors *gr557_cycledelay = new TGraphErrors (counts_557 , cycleNumberArray557, delaytimeArray557, 0 , 0);
  gr557_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr557_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr557_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr557_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cycledelay -> SetMarkerStyle(7);

  gr557_cycledelay -> Draw("Ap");


  c557_cycleNum -> cd(3);
  TGraphErrors *gr557_cycletempIrrad = new TGraphErrors (counts_557 , cycleNumberArray557, avets12IrradArray557, 0 , ts12IrradErr557);

  gr557_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr557_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr557_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr557_cycletempIrrad -> SetMarkerStyle(7);
  gr557_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr557_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr557_cycletempValveOpen = new TGraphErrors (counts_557 , cycleNumberArray557, avets12ValveOpenArray557, 0 , ts12ValveOpenErr557);

  gr557_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr557_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr557_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr557_cycletempValveOpen -> SetMarkerStyle(7);
  gr557_cycletempValveOpen -> SetMarkerColor(2);
  gr557_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr557_cycletempIrrad -> Draw("AP");
  gr557_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c557_cycleNum -> cd(4);
  TGraphErrors *gr557_cyclecur = new TGraphErrors (counts_557 , cycleNumberArray557 , avecurArray557, 0, ErrcurArray557 );
  gr557_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr557_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr557_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr557_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclecur -> SetMarkerStyle(7);
  gr557_cyclecur -> Draw("Ap");


  TCanvas *c557_cycleNumFit = new TCanvas("c557_cycleNumFit" , "c557_cycleNumFit" , 1200, 800);
  c557_cycleNumFit -> Divide(2,2);

  c557_cycleNumFit -> cd(1);
  TGraphErrors *gr557_cyclefall = new TGraphErrors (counts_557, cycleNumberArray557, FallTimeArray557 , 0, FallTimeErrArray557);

  gr557_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr557_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr557_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr557_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclefall -> SetMarkerStyle(7);
  gr557_cyclefall -> Draw("Ap");


  c557_cycleNumFit -> cd(2);
  TGraphErrors *gr557_cyclebaseline = new TGraphErrors (counts_557, cycleNumberArray557, BaselineArray557 , 0, BaselineErrArray557);

  gr557_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr557_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr557_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr557_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclebaseline -> SetMarkerStyle(7);
  gr557_cyclebaseline -> Draw("Ap");

  c557_cycleNumFit -> cd(3);
  TGraphErrors *gr557_cyclebaselineirrad = new TGraphErrors (counts_557, cycleNumberArray557, BaselineIrradArray557 , 0, BaselineIrradErrArray557);

  gr557_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr557_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr557_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr557_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclebaselineirrad -> SetMarkerStyle(7);
  gr557_cyclebaselineirrad -> Draw("Ap");

  c557_cycleNumFit -> cd(4);
  TGraphErrors *gr557_cyclerise = new TGraphErrors (counts_557, cycleNumberArray557, RiseTimeArray557 , 0, RiseTimeErrArray557);

  gr557_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr557_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr557_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr557_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr557_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr557_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr557_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr557_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr557_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr557_cyclerise -> SetMarkerStyle(7);
  gr557_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              558
  //*********************************
  //*********************************
  TCanvas *c558 = new TCanvas("c558" , "c558" , 1200, 800);
  c558 -> Divide(2,2);
  //c558 -> cd(1);
  TPad *p558_1 = c558->cd(1);
  p558_1->SetLogy(); 
  TGraphErrors *gr558_delaycounts = new TGraphErrors(counts_558, delaytimeArray558 , UCNIntegralArray558, 0, UCNIntegralErrArray558);

  gr558_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr558_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr558_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr558_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr558_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_delaycounts -> SetMarkerStyle(7);
  gr558_delaycounts -> Fit(fit);
  storage558 = fit -> GetParameter(1);
  storageErr558 = fit -> GetParError(1);
  
  TGraphErrors *gr558_delayhist = new TGraphErrors(counts_558, delaytimeArray558 , HistIntegralArray558, 0, HistIntegralErrArray558);

  gr558_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr558_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr558_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr558_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr558_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr558_delayhist -> SetMarkerColor(2);
  gr558_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr558_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr558_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr558_delaycounts -> Draw("Ap");
  gr558_delayhist -> Draw("p");
  leg2 -> Draw();

  //c558 -> cd(2);
  TPad *p558_2 = c558->cd(2);
  p558_2->SetLogy(); 
  TGraphErrors *gr558_tempIrradcounts = new TGraphErrors (counts_558 , avets12IrradArray558, UCNIntegralArray558 , ts12IrradErr558 , UCNIntegralErrArray558);
  gr558_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr558_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr558_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr558_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr558_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr558_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr558_tempValveOpencounts = new TGraphErrors (counts_558 , avets12ValveOpenArray558, UCNIntegralArray558 , ts12ValveOpenErr558 , UCNIntegralErrArray558);
  gr558_tempValveOpencounts -> SetMarkerStyle(7);
  gr558_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr558_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr558_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr558_tempIrradcounts -> Draw("Ap");
  gr558_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c558 -> cd(3);
  TGraphErrors *gr558_delaytempIrrad = new TGraphErrors (counts_558 , delaytimeArray558, avets12IrradArray558, 0 , ts12IrradErr558);

  gr558_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr558_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr558_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr558_delaytempIrrad -> SetMarkerStyle(7);
  gr558_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr558_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr558_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr558_delaytempValveOpen = new TGraphErrors (counts_558 , delaytimeArray558, avets12ValveOpenArray558, 0 , ts12ValveOpenErr558);

  gr558_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr558_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr558_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr558_delaytempValveOpen -> SetMarkerStyle(7);
  gr558_delaytempValveOpen -> SetMarkerColor(2);
  gr558_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr558_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr558_delaytempIrrad -> Draw("AP");
  gr558_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p558_3 = c558->cd(4);
  p558_3->SetLogy(); 
  TGraphErrors *gr558_curcounts = new TGraphErrors (counts_558 , avecurArray558, UCNIntegralArray558 , ErrcurArray558 , UCNIntegralErrArray558);
  gr558_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr558_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr558_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr558_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr558_curhist = new TGraphErrors (counts_558 , avecurArray558, UCNIntegralArray558 , ErrcurArray558 , UCNIntegralErrArray558);
  gr558_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr558_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr558_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr558_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr558_curhist -> SetMarkerColor(2);
  gr558_curhist -> SetMarkerStyle(7);

  gr558_curcounts -> Draw("Ap");
  gr558_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c558_cycleNum = new TCanvas("c558_cycleNum" , "c558_cycleNum" , 1200, 800);
  c558_cycleNum -> Divide(2,2);
  TPad *p558_4 = c558_cycleNum->cd(1);
  p558_4->SetLogy(); 
  TGraphErrors *gr558_cyclecounts = new TGraphErrors (counts_558 , cycleNumberArray558, UCNIntegralArray558, 0 , UCNIntegralErrArray558);
  gr558_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr558_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr558_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr558_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr558_cyclehist = new TGraphErrors(counts_558, cycleNumberArray558 , HistIntegralArray558, 0, HistIntegralErrArray558);

  gr558_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr558_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr558_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr558_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr558_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr558_cyclehist -> SetMarkerColor(2);
  gr558_cyclehist -> SetMarkerStyle(7);

  gr558_cyclecounts -> Draw("Ap");
  gr558_cyclehist -> Draw("p");

  leg2-> Draw();

  c558_cycleNum -> cd(2);
 TGraphErrors *gr558_cycledelay = new TGraphErrors (counts_558 , cycleNumberArray558, delaytimeArray558, 0 , 0);
  gr558_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr558_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr558_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr558_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cycledelay -> SetMarkerStyle(7);

  gr558_cycledelay -> Draw("Ap");


  c558_cycleNum -> cd(3);
  TGraphErrors *gr558_cycletempIrrad = new TGraphErrors (counts_558 , cycleNumberArray558, avets12IrradArray558, 0 , ts12IrradErr558);

  gr558_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr558_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr558_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr558_cycletempIrrad -> SetMarkerStyle(7);
  gr558_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr558_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr558_cycletempValveOpen = new TGraphErrors (counts_558 , cycleNumberArray558, avets12ValveOpenArray558, 0 , ts12ValveOpenErr558);

  gr558_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr558_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr558_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr558_cycletempValveOpen -> SetMarkerStyle(7);
  gr558_cycletempValveOpen -> SetMarkerColor(2);
  gr558_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr558_cycletempIrrad -> Draw("AP");
  gr558_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c558_cycleNum -> cd(4);
  TGraphErrors *gr558_cyclecur = new TGraphErrors (counts_558 , cycleNumberArray558 , avecurArray558, 0, ErrcurArray558 );
  gr558_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr558_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr558_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr558_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclecur -> SetMarkerStyle(7);
  gr558_cyclecur -> Draw("Ap");


  TCanvas *c558_cycleNumFit = new TCanvas("c558_cycleNumFit" , "c558_cycleNumFit" , 1200, 800);
  c558_cycleNumFit -> Divide(2,2);

  c558_cycleNumFit -> cd(1);
  TGraphErrors *gr558_cyclefall = new TGraphErrors (counts_558, cycleNumberArray558, FallTimeArray558 , 0, FallTimeErrArray558);

  gr558_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr558_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr558_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr558_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclefall -> SetMarkerStyle(7);
  gr558_cyclefall -> Draw("Ap");


  c558_cycleNumFit -> cd(2);
  TGraphErrors *gr558_cyclebaseline = new TGraphErrors (counts_558, cycleNumberArray558, BaselineArray558 , 0, BaselineErrArray558);

  gr558_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr558_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr558_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr558_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclebaseline -> SetMarkerStyle(7);
  gr558_cyclebaseline -> Draw("Ap");

  c558_cycleNumFit -> cd(3);
  TGraphErrors *gr558_cyclebaselineirrad = new TGraphErrors (counts_558, cycleNumberArray558, BaselineIrradArray558 , 0, BaselineIrradErrArray558);

  gr558_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr558_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr558_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr558_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclebaselineirrad -> SetMarkerStyle(7);
  gr558_cyclebaselineirrad -> Draw("Ap");

  c558_cycleNumFit -> cd(4);
  TGraphErrors *gr558_cyclerise = new TGraphErrors (counts_558, cycleNumberArray558, RiseTimeArray558 , 0, RiseTimeErrArray558);

  gr558_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr558_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr558_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr558_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr558_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr558_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr558_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr558_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr558_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr558_cyclerise -> SetMarkerStyle(7);
  gr558_cyclerise -> Draw("Ap");






  //*********************************
  //*********************************
  //              559
  //*********************************
  //*********************************
  TCanvas *c559 = new TCanvas("c559" , "c559" , 1200, 800);
  c559 -> Divide(2,2);
  //c559 -> cd(1);
  TPad *p559_1 = c559->cd(1);
  p559_1->SetLogy(); 
  TGraphErrors *gr559_delaycounts = new TGraphErrors(counts_559, delaytimeArray559 , UCNIntegralArray559, 0, UCNIntegralErrArray559);

  gr559_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr559_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr559_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr559_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr559_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_delaycounts -> SetMarkerStyle(7);
  gr559_delaycounts -> Fit(fit);
  storage559 = fit -> GetParameter(1);
  storageErr559 = fit -> GetParError(1);
  
  TGraphErrors *gr559_delayhist = new TGraphErrors(counts_559, delaytimeArray559 , HistIntegralArray559, 0, HistIntegralErrArray559);

  gr559_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr559_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr559_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr559_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr559_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr559_delayhist -> SetMarkerColor(2);
  gr559_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr559_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr559_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr559_delaycounts -> Draw("Ap");
  gr559_delayhist -> Draw("p");
  leg2 -> Draw();

  //c559 -> cd(2);
  TPad *p559_2 = c559->cd(2);
  p559_2->SetLogy(); 
  TGraphErrors *gr559_tempIrradcounts = new TGraphErrors (counts_559 , avets12IrradArray559, UCNIntegralArray559 , ts12IrradErr559 , UCNIntegralErrArray559);
  gr559_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr559_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr559_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr559_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr559_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr559_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr559_tempValveOpencounts = new TGraphErrors (counts_559 , avets12ValveOpenArray559, UCNIntegralArray559 , ts12ValveOpenErr559 , UCNIntegralErrArray559);
  gr559_tempValveOpencounts -> SetMarkerStyle(7);
  gr559_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr559_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr559_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr559_tempIrradcounts -> Draw("Ap");
  gr559_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c559 -> cd(3);
  TGraphErrors *gr559_delaytempIrrad = new TGraphErrors (counts_559 , delaytimeArray559, avets12IrradArray559, 0 , ts12IrradErr559);

  gr559_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr559_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr559_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr559_delaytempIrrad -> SetMarkerStyle(7);
  gr559_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr559_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr559_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr559_delaytempValveOpen = new TGraphErrors (counts_559 , delaytimeArray559, avets12ValveOpenArray559, 0 , ts12ValveOpenErr559);

  gr559_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr559_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr559_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr559_delaytempValveOpen -> SetMarkerStyle(7);
  gr559_delaytempValveOpen -> SetMarkerColor(2);
  gr559_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr559_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr559_delaytempIrrad -> Draw("AP");
  gr559_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p559_3 = c559->cd(4);
  p559_3->SetLogy(); 
  TGraphErrors *gr559_curcounts = new TGraphErrors (counts_559 , avecurArray559, UCNIntegralArray559 , ErrcurArray559 , UCNIntegralErrArray559);
  gr559_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr559_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr559_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr559_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr559_curhist = new TGraphErrors (counts_559 , avecurArray559, UCNIntegralArray559 , ErrcurArray559 , UCNIntegralErrArray559);
  gr559_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr559_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr559_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr559_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr559_curhist -> SetMarkerColor(2);
  gr559_curhist -> SetMarkerStyle(7);

  gr559_curcounts -> Draw("Ap");
  gr559_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c559_cycleNum = new TCanvas("c559_cycleNum" , "c559_cycleNum" , 1200, 800);
  c559_cycleNum -> Divide(2,2);
  TPad *p559_4 = c559_cycleNum->cd(1);
  p559_4->SetLogy(); 
  TGraphErrors *gr559_cyclecounts = new TGraphErrors (counts_559 , cycleNumberArray559, UCNIntegralArray559, 0 , UCNIntegralErrArray559);
  gr559_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr559_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr559_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr559_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr559_cyclehist = new TGraphErrors(counts_559, cycleNumberArray559 , HistIntegralArray559, 0, HistIntegralErrArray559);

  gr559_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr559_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr559_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr559_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr559_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr559_cyclehist -> SetMarkerColor(2);
  gr559_cyclehist -> SetMarkerStyle(7);

  gr559_cyclecounts -> Draw("Ap");
  gr559_cyclehist -> Draw("p");

  leg2-> Draw();

  c559_cycleNum -> cd(2);
 TGraphErrors *gr559_cycledelay = new TGraphErrors (counts_559 , cycleNumberArray559, delaytimeArray559, 0 , 0);
  gr559_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr559_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr559_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr559_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cycledelay -> SetMarkerStyle(7);

  gr559_cycledelay -> Draw("Ap");


  c559_cycleNum -> cd(3);
  TGraphErrors *gr559_cycletempIrrad = new TGraphErrors (counts_559 , cycleNumberArray559, avets12IrradArray559, 0 , ts12IrradErr559);

  gr559_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr559_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr559_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr559_cycletempIrrad -> SetMarkerStyle(7);
  gr559_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr559_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr559_cycletempValveOpen = new TGraphErrors (counts_559 , cycleNumberArray559, avets12ValveOpenArray559, 0 , ts12ValveOpenErr559);

  gr559_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr559_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr559_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr559_cycletempValveOpen -> SetMarkerStyle(7);
  gr559_cycletempValveOpen -> SetMarkerColor(2);
  gr559_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr559_cycletempIrrad -> Draw("AP");
  gr559_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c559_cycleNum -> cd(4);
  TGraphErrors *gr559_cyclecur = new TGraphErrors (counts_559 , cycleNumberArray559 , avecurArray559, 0, ErrcurArray559 );
  gr559_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr559_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr559_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr559_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclecur -> SetMarkerStyle(7);
  gr559_cyclecur -> Draw("Ap");


  TCanvas *c559_cycleNumFit = new TCanvas("c559_cycleNumFit" , "c559_cycleNumFit" , 1200, 800);
  c559_cycleNumFit -> Divide(2,2);

  c559_cycleNumFit -> cd(1);
  TGraphErrors *gr559_cyclefall = new TGraphErrors (counts_559, cycleNumberArray559, FallTimeArray559 , 0, FallTimeErrArray559);

  gr559_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr559_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr559_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr559_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclefall -> SetMarkerStyle(7);
  gr559_cyclefall -> Draw("Ap");


  c559_cycleNumFit -> cd(2);
  TGraphErrors *gr559_cyclebaseline = new TGraphErrors (counts_559, cycleNumberArray559, BaselineArray559 , 0, BaselineErrArray559);

  gr559_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr559_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr559_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr559_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclebaseline -> SetMarkerStyle(7);
  gr559_cyclebaseline -> Draw("Ap");

  c559_cycleNumFit -> cd(3);
  TGraphErrors *gr559_cyclebaselineirrad = new TGraphErrors (counts_559, cycleNumberArray559, BaselineIrradArray559 , 0, BaselineIrradErrArray559);

  gr559_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr559_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr559_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr559_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclebaselineirrad -> SetMarkerStyle(7);
  gr559_cyclebaselineirrad -> Draw("Ap");

  c559_cycleNumFit -> cd(4);
  TGraphErrors *gr559_cyclerise = new TGraphErrors (counts_559, cycleNumberArray559, RiseTimeArray559 , 0, RiseTimeErrArray559);

  gr559_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr559_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr559_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr559_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr559_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr559_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr559_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr559_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr559_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr559_cyclerise -> SetMarkerStyle(7);
  gr559_cyclerise -> Draw("Ap");







  //*********************************
  //*********************************
  //              560
  //*********************************
  //*********************************
  TCanvas *c560 = new TCanvas("c560" , "c560" , 1200, 800);
  c560 -> Divide(2,2);
  //c560 -> cd(1);
  TPad *p560_1 = c560->cd(1);
  p560_1->SetLogy(); 
  TGraphErrors *gr560_delaycounts = new TGraphErrors(counts_560, delaytimeArray560 , UCNIntegralArray560, 0, UCNIntegralErrArray560);

  gr560_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr560_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr560_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr560_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr560_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_delaycounts -> SetMarkerStyle(7);
  gr560_delaycounts -> Fit(fit);
  storage560 = fit -> GetParameter(1);
  storageErr560 = fit -> GetParError(1);
  
  TGraphErrors *gr560_delayhist = new TGraphErrors(counts_560, delaytimeArray560 , HistIntegralArray560, 0, HistIntegralErrArray560);

  gr560_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr560_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr560_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr560_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr560_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr560_delayhist -> SetMarkerColor(2);
  gr560_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr560_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr560_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr560_delaycounts -> Draw("Ap");
  gr560_delayhist -> Draw("p");
  leg2 -> Draw();

  //c560 -> cd(2);
  TPad *p560_2 = c560->cd(2);
  p560_2->SetLogy(); 
  TGraphErrors *gr560_tempIrradcounts = new TGraphErrors (counts_560 , avets12IrradArray560, UCNIntegralArray560 , ts12IrradErr560 , UCNIntegralErrArray560);
  gr560_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr560_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr560_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr560_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr560_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr560_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr560_tempValveOpencounts = new TGraphErrors (counts_560 , avets12ValveOpenArray560, UCNIntegralArray560 , ts12ValveOpenErr560 , UCNIntegralErrArray560);
  gr560_tempValveOpencounts -> SetMarkerStyle(7);
  gr560_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr560_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr560_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr560_tempIrradcounts -> Draw("Ap");
  gr560_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c560 -> cd(3);
  TGraphErrors *gr560_delaytempIrrad = new TGraphErrors (counts_560 , delaytimeArray560, avets12IrradArray560, 0 , ts12IrradErr560);

  gr560_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr560_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr560_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr560_delaytempIrrad -> SetMarkerStyle(7);
  gr560_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr560_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr560_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr560_delaytempValveOpen = new TGraphErrors (counts_560 , delaytimeArray560, avets12ValveOpenArray560, 0 , ts12ValveOpenErr560);

  gr560_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr560_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr560_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr560_delaytempValveOpen -> SetMarkerStyle(7);
  gr560_delaytempValveOpen -> SetMarkerColor(2);
  gr560_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr560_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr560_delaytempIrrad -> Draw("AP");
  gr560_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p560_3 = c560->cd(4);
  p560_3->SetLogy(); 
  TGraphErrors *gr560_curcounts = new TGraphErrors (counts_560 , avecurArray560, UCNIntegralArray560 , ErrcurArray560 , UCNIntegralErrArray560);
  gr560_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr560_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr560_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr560_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr560_curhist = new TGraphErrors (counts_560 , avecurArray560, UCNIntegralArray560 , ErrcurArray560 , UCNIntegralErrArray560);
  gr560_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr560_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr560_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr560_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr560_curhist -> SetMarkerColor(2);
  gr560_curhist -> SetMarkerStyle(7);

  gr560_curcounts -> Draw("Ap");
  gr560_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c560_cycleNum = new TCanvas("c560_cycleNum" , "c560_cycleNum" , 1200, 800);
  c560_cycleNum -> Divide(2,2);
  TPad *p560_4 = c560_cycleNum->cd(1);
  p560_4->SetLogy(); 
  TGraphErrors *gr560_cyclecounts = new TGraphErrors (counts_560 , cycleNumberArray560, UCNIntegralArray560, 0 , UCNIntegralErrArray560);
  gr560_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr560_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr560_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr560_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr560_cyclehist = new TGraphErrors(counts_560, cycleNumberArray560 , HistIntegralArray560, 0, HistIntegralErrArray560);

  gr560_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr560_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr560_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr560_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr560_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr560_cyclehist -> SetMarkerColor(2);
  gr560_cyclehist -> SetMarkerStyle(7);

  gr560_cyclecounts -> Draw("Ap");
  gr560_cyclehist -> Draw("p");

  leg2-> Draw();

  c560_cycleNum -> cd(2);
 TGraphErrors *gr560_cycledelay = new TGraphErrors (counts_560 , cycleNumberArray560, delaytimeArray560, 0 , 0);
  gr560_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr560_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr560_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr560_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cycledelay -> SetMarkerStyle(7);

  gr560_cycledelay -> Draw("Ap");


  c560_cycleNum -> cd(3);
  TGraphErrors *gr560_cycletempIrrad = new TGraphErrors (counts_560 , cycleNumberArray560, avets12IrradArray560, 0 , ts12IrradErr560);

  gr560_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr560_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr560_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr560_cycletempIrrad -> SetMarkerStyle(7);
  gr560_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr560_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr560_cycletempValveOpen = new TGraphErrors (counts_560 , cycleNumberArray560, avets12ValveOpenArray560, 0 , ts12ValveOpenErr560);

  gr560_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr560_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr560_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr560_cycletempValveOpen -> SetMarkerStyle(7);
  gr560_cycletempValveOpen -> SetMarkerColor(2);
  gr560_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr560_cycletempIrrad -> Draw("AP");
  gr560_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c560_cycleNum -> cd(4);
  TGraphErrors *gr560_cyclecur = new TGraphErrors (counts_560 , cycleNumberArray560 , avecurArray560, 0, ErrcurArray560 );
  gr560_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr560_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr560_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr560_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclecur -> SetMarkerStyle(7);
  gr560_cyclecur -> Draw("Ap");


  TCanvas *c560_cycleNumFit = new TCanvas("c560_cycleNumFit" , "c560_cycleNumFit" , 1200, 800);
  c560_cycleNumFit -> Divide(2,2);

  c560_cycleNumFit -> cd(1);
  TGraphErrors *gr560_cyclefall = new TGraphErrors (counts_560, cycleNumberArray560, FallTimeArray560 , 0, FallTimeErrArray560);

  gr560_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr560_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr560_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr560_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclefall -> SetMarkerStyle(7);
  gr560_cyclefall -> Draw("Ap");


  c560_cycleNumFit -> cd(2);
  TGraphErrors *gr560_cyclebaseline = new TGraphErrors (counts_560, cycleNumberArray560, BaselineArray560 , 0, BaselineErrArray560);

  gr560_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr560_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr560_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr560_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclebaseline -> SetMarkerStyle(7);
  gr560_cyclebaseline -> Draw("Ap");

  c560_cycleNumFit -> cd(3);
  TGraphErrors *gr560_cyclebaselineirrad = new TGraphErrors (counts_560, cycleNumberArray560, BaselineIrradArray560 , 0, BaselineIrradErrArray560);

  gr560_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr560_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr560_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr560_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclebaselineirrad -> SetMarkerStyle(7);
  gr560_cyclebaselineirrad -> Draw("Ap");

  c560_cycleNumFit -> cd(4);
  TGraphErrors *gr560_cyclerise = new TGraphErrors (counts_560, cycleNumberArray560, RiseTimeArray560 , 0, RiseTimeErrArray560);

  gr560_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr560_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr560_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr560_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr560_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr560_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr560_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr560_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr560_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr560_cyclerise -> SetMarkerStyle(7);
  gr560_cyclerise -> Draw("Ap");








  /*

  double StorageAll [100] = {storage553, storage554, storage556, storage557, storage558, storage540};
  double StorageErrAll[100] = {storageErr553, storageErr554, storageErr556, storageErr556, storageErr557, storageErr558, storageErr540};
  double runNum[100] = {553, 554, 556, 557, 558, 540};
  double tempIrradAll[100] = {aveAllts12Irrad553, aveAllts12Irrad554, aveAllts12Irrad556, aveAllts12Irrad557, aveAllts12Irrad558, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad553,  aveAllErrts12Irrad554,  aveAllErrts12Irrad555,  aveAllErrts12Irrad557,  aveAllErrts12Irrad558,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_553 +counts_554 +counts_555 +counts_556 +counts_557 +counts_558+counts_559+counts_560  , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_553 +counts_554 +counts_555 +counts_556 +counts_557 +counts_558  , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
  grAllHist -> SetMarkerStyle(7);
  grAllHist -> SetMarkerColor(2);

  
  grAll -> SetTitle("UCN Count vs cycle Delay Time ");
  grAll -> GetYaxis()-> SetTitle("UCN Count" );
  grAll -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  grAll -> GetXaxis()-> SetLimits(0 ,180);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> Fit(fit);

  grAll -> SetMarkerStyle(7);
  grAll -> Draw("Ap");
  grAllHist -> Draw("p");
  




}
