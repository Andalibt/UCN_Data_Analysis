// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17003B WHICH IS THE
// UCN COUNT VS THE ISOPURE TEMPERATURE.
// DURING THE DATA ACQUISITON, THE ISOPURE HELIUM
// TEMPERATURE CHANGED.
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17003B_Taraneh_edit_ver1(){

  TFile *fin549 = new TFile ("outputTree_549.root", "READ");
  TFile *fin550 = new TFile ("outputTree_550.root", "READ");
  TFile *fin551 = new TFile ("outputTree_551.root", "READ");
  TFile *fin552 = new TFile ("outputTree_552.root", "READ");
  
  TTree *outputTree549 = (TTree*) fin549 -> Get("cycle_info");
  TTree *outputTree550 = (TTree*) fin550 -> Get("cycle_info");
  TTree *outputTree551 = (TTree*) fin551 -> Get("cycle_info");
  TTree *outputTree552 = (TTree*) fin552 -> Get("cycle_info");

  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double irradStartTimes549;
  double irradStartTimes550;
  double irradStartTimes551;
  double irradStartTimes552;

  outputTree549 -> SetBranchAddress("irradStartTimes" , &irradStartTimes549);
  outputTree550 -> SetBranchAddress("irradStartTimes" , &irradStartTimes550);
  outputTree551 -> SetBranchAddress("irradStartTimes" , &irradStartTimes551);
  outputTree552 -> SetBranchAddress("irradStartTimes" , &irradStartTimes552);

  double cycleStartTimes549;
  double cycleStartTimes550;
  double cycleStartTimes551;
  double cycleStartTimes552;

  outputTree549 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes549);
  outputTree550 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes550);
  outputTree551 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes551);
  outputTree552 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes552);
  



  
  double cycleDelayTime549;
  double cycleDelayTime550;
  double cycleDelayTime551;
  double cycleDelayTime552;
  outputTree549 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime549);
  outputTree550 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime550);
  outputTree551 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime551);
  outputTree552 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime552);
  double delaytimeArray549[100];
  double delaytimeArray550[100];
  double delaytimeArray551[100];
  double delaytimeArray552[100];

  int cycleNumber549;
  int cycleNumber550;
  int cycleNumber551;
  int cycleNumber552;
  outputTree549 -> SetBranchAddress("cycleNumber", &cycleNumber549);
  outputTree550 -> SetBranchAddress("cycleNumber", &cycleNumber550);
  outputTree551 -> SetBranchAddress("cycleNumber", &cycleNumber551);
  outputTree552 -> SetBranchAddress("cycleNumber", &cycleNumber552);
  double cycleNumberArray549 [100];
  double cycleNumberArray550 [100];
  double cycleNumberArray551 [100];
  double cycleNumberArray552 [100];  
  
  double UCNIntegral549;
  double UCNIntegral550;
  double UCNIntegral551;
  double UCNIntegral552;
  outputTree549 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral549);
  outputTree550 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral550);
  outputTree551 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral551);
  outputTree552 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral552);
  double UCNIntegralArray549 [100];
  double UCNIntegralArray550 [100];
  double UCNIntegralArray551 [100];
  double UCNIntegralArray552 [100];

  double UCNIntegralErr549;
  double UCNIntegralErr550;
  double UCNIntegralErr551;
  double UCNIntegralErr552;
  outputTree549 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr549);
  outputTree550 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr550);
  outputTree551 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr551);
  outputTree552 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr552);
  double UCNIntegralErrArray549 [100];
  double UCNIntegralErrArray550 [100];
  double UCNIntegralErrArray551 [100];
  double UCNIntegralErrArray552 [100];

  double HistIntegral549;
  double HistIntegral550;
  double HistIntegral551;
  double HistIntegral552;
  outputTree549 -> SetBranchAddress ("HistIntegral" , &HistIntegral549);
  outputTree550 -> SetBranchAddress ("HistIntegral" , &HistIntegral550);
  outputTree551 -> SetBranchAddress ("HistIntegral" , &HistIntegral551);
  outputTree552 -> SetBranchAddress ("HistIntegral" , &HistIntegral552); 
  double HistIntegralArray549 [100];
  double HistIntegralArray550 [100];
  double HistIntegralArray551 [100];
  double HistIntegralArray552 [100];
  double HistIntegralErrArray549[100];
  double HistIntegralErrArray550[100];
  double HistIntegralErrArray551[100];
  double HistIntegralErrArray552[100];

  double avets12Irrad549;
  double avets12Irrad550;
  double avets12Irrad551;
  double avets12Irrad552;
  outputTree549 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad549);
  outputTree550 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad550);
  outputTree551 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad551);
  outputTree552 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad552);
  double avets12IrradArray549 [100];
  double avets12IrradArray550 [100];
  double avets12IrradArray551 [100];
  double avets12IrradArray552 [100];
  
  double avets12ValveOpen549;
  double avets12ValveOpen550;
  double avets12ValveOpen551;
  double avets12ValveOpen552;
  outputTree549 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen549);
  outputTree550 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen550);
  outputTree551 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen551);
  outputTree552 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen552);
  double avets12ValveOpenArray549 [100];
  double avets12ValveOpenArray550 [100];
  double avets12ValveOpenArray551 [100];
  double avets12ValveOpenArray552 [100];
  
  double maxts12Irrad549;
  double maxts12Irrad550;
  double maxts12Irrad551;
  double maxts12Irrad552;
  outputTree549 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad549);
  outputTree550 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad550);
  outputTree551 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad551);
  outputTree552 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad552);
  double maxts12IrradArray549 [100];
  double maxts12IrradArray550 [100];
  double maxts12IrradArray551 [100];
  double maxts12IrradArray552 [100];
  
  double maxts12ValveOpen549;
  double maxts12ValveOpen550;
  double maxts12ValveOpen551;
  double maxts12ValveOpen552;
  outputTree549 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen549);
  outputTree550 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen550);
  outputTree551 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen551);
  outputTree552 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen552);
  double maxts12ValveOpenArray549 [100];
  double maxts12ValveOpenArray550 [100];
  double maxts12ValveOpenArray551 [100];
  double maxts12ValveOpenArray552 [100];

  double mints12Irrad549;
  double mints12Irrad550;
  double mints12Irrad551;
  double mints12Irrad552;
  outputTree549 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad549);
  outputTree550 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad550);
  outputTree551 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad551);
  outputTree552 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad552);
  double mints12IrradArray549 [100];
  double mints12IrradArray550 [100];
  double mints12IrradArray551 [100];
  double mints12IrradArray552 [100];
  
  double mints12ValveOpen549;
  double mints12ValveOpen550;
  double mints12ValveOpen551;
  double mints12ValveOpen552;
  outputTree549 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen549);
  outputTree550 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen550);
  outputTree551 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen551);
  outputTree552 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen552);
  double mints12ValveOpenArray549 [100];
  double mints12ValveOpenArray550 [100];
  double mints12ValveOpenArray551 [100];
  double mints12ValveOpenArray552 [100];
    

  double ts12IrradErr549 [100];
  double ts12IrradErr550 [100];
  double ts12IrradErr551 [100];
  double ts12IrradErr552 [100];
  double ts12ValveOpenErr549 [100];
  double ts12ValveOpenErr550 [100];
  double ts12ValveOpenErr551 [100];
  double ts12ValveOpenErr552 [100];

  double avecur549;
  double avecur550;
  double avecur551;
  double avecur552;
  outputTree549 -> SetBranchAddress ("AVE_PRDCUR" , &avecur549);
  outputTree550 -> SetBranchAddress ("AVE_PRDCUR" , &avecur550);
  outputTree551 -> SetBranchAddress ("AVE_PRDCUR" , &avecur551);
  outputTree552 -> SetBranchAddress ("AVE_PRDCUR" , &avecur552);
  double avecurArray549 [100];
  double avecurArray550 [100];
  double avecurArray551 [100];
  double avecurArray552 [100];

  double maxcur549;
  double maxcur550;
  double maxcur551;
  double maxcur552;
  outputTree549 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur549);
  outputTree550 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur550);
  outputTree551 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur551);
  outputTree552 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur552);
  double maxcurArray549 [100];
  double maxcurArray550 [100];
  double maxcurArray551 [100];
  double maxcurArray552 [100];

  double mincur549;
  double mincur550;
  double mincur551;
  double mincur552;
  outputTree549 -> SetBranchAddress ("MIN_PRDCUR" , &mincur549);
  outputTree550 -> SetBranchAddress ("MIN_PRDCUR" , &mincur550);
  outputTree551 -> SetBranchAddress ("MIN_PRDCUR" , &mincur551);
  outputTree552 -> SetBranchAddress ("MIN_PRDCUR" , &mincur552);
  double mincurArray549 [100];
  double mincurArray550 [100];
  double mincurArray551 [100];
  double mincurArray552 [100];

  double ErrcurArray549 [100];
  double ErrcurArray550 [100];
  double ErrcurArray551 [100];
  double ErrcurArray552 [100];

  double Baseline549;
  double Baseline550;
  double Baseline551;
  double Baseline552;
  outputTree549 -> SetBranchAddress ("Baseline" , &Baseline549);
  outputTree550 -> SetBranchAddress ("Baseline" , &Baseline550);
  outputTree551 -> SetBranchAddress ("Baseline" , &Baseline551);
  outputTree552 -> SetBranchAddress ("Baseline" , &Baseline552);
  double BaselineArray549 [100];
  double BaselineArray550 [100];
  double BaselineArray551 [100];
  double BaselineArray552 [100];

  double BaselineErr549;
  double BaselineErr550;
  double BaselineErr551;
  double BaselineErr552;
  outputTree549 -> SetBranchAddress ("BaselineErr" , &BaselineErr549);
  outputTree550 -> SetBranchAddress ("BaselineErr" , &BaselineErr550);
  outputTree551 -> SetBranchAddress ("BaselineErr" , &BaselineErr551);
  outputTree552 -> SetBranchAddress ("BaselineErr" , &BaselineErr552);
  double BaselineErrArray549 [100];
  double BaselineErrArray550 [100];
  double BaselineErrArray551 [100];
  double BaselineErrArray552 [100];
  
  double BaselineIrrad549;
  double BaselineIrrad550;
  double BaselineIrrad551;
  double BaselineIrrad552;
  outputTree549 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad549);
  outputTree550 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad550);
  outputTree551 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad551);
  outputTree552 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad552);
  double BaselineIrradArray549 [100];
  double BaselineIrradArray550 [100];
  double BaselineIrradArray551 [100];
  double BaselineIrradArray552 [100];
  
  double BaselineIrradErr549;
  double BaselineIrradErr550;
  double BaselineIrradErr551;
  double BaselineIrradErr552;
  outputTree549 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr549);
  outputTree550 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr550);
  outputTree551 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr551);
  outputTree552 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr552);
  double BaselineIrradErrArray549 [100];
  double BaselineIrradErrArray550 [100];
  double BaselineIrradErrArray551 [100];
  double BaselineIrradErrArray552 [100];

  double BaselineIntegral549;
  double BaselineIntegral550;
  double BaselineIntegral551;
  double BaselineIntegral552;
  outputTree549 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral549);
  outputTree550 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral550);
  outputTree551 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral551);
  outputTree552 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral552);
  double BaselineIntegralArray549[100];
  double BaselineIntegralArray550[100];
  double BaselineIntegralArray551[100];
  double BaselineIntegralArray552[100];

  double BaselineIrradIntegral549;
  double BaselineIrradIntegral550;
  double BaselineIrradIntegral551;
  double BaselineIrradIntegral552;
  outputTree549 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral549);
  outputTree550 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral550);
  outputTree551 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral551);
  outputTree552 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral552);
  double BaselineIrradIntegralArray549[100];
  double BaselineIrradIntegralArray550[100];
  double BaselineIrradIntegralArray551[100];
  double BaselineIrradIntegralArray552[100];

  double UCNIntegralManualArray549 [100];
  double UCNIntegralManualArray550 [100];
  double UCNIntegralManualArray551 [100];
  double UCNIntegralManualArray552 [100];
  double UCNIntegralManualErrArray549[100];
  double UCNIntegralManualErrArray550[100];
  double UCNIntegralManualErrArray551[100];
  double UCNIntegralManualErrArray552[100];


  int counts_549 = 0;
  int counts_550 = 0;
  int counts_551 = 0;
  int counts_552 = 0;

  // *****
  // 549
  // *****
  
  
  ULong64_t events549;
  events549 = (Double_t) outputTree549 -> GetEntries();

  for (ULong64_t j = 0 ; j < events549 ; j++){
    outputTree549 -> GetEvent(j);
    if (j==0 || j==2)
      continue;
    UCNIntegralArray549[counts_549] = UCNIntegral549;
    UCNIntegralErrArray549[counts_549] = UCNIntegralErr549;
    HistIntegralArray549[counts_549] = HistIntegral549;
    HistIntegralErrArray549[counts_549] = sqrt (HistIntegral549);
    avets12IrradArray549[counts_549] = avets12Irrad549;
    avets12ValveOpenArray549[counts_549] = avets12ValveOpen549;
    maxts12IrradArray549[counts_549] = maxts12Irrad549;
    maxts12ValveOpenArray549[counts_549] = maxts12ValveOpen549;
    mints12IrradArray549[counts_549] = mints12Irrad549; 
    mints12ValveOpenArray549[counts_549] = mints12ValveOpen549;
    ts12IrradErr549[counts_549] = (maxts12Irrad549 - mints12Irrad549)/2;
    ts12ValveOpenErr549[counts_549] = (maxts12ValveOpen549 - mints12ValveOpen549)/2;
    avecurArray549[counts_549] = avecur549;
    maxcurArray549[counts_549] = maxcur549;
    mincurArray549[counts_549] = mincur549;
    ErrcurArray549[counts_549] = (maxcur549 - mincur549)/2;
    delaytimeArray549[counts_549] = cycleDelayTime549;
    cycleNumberArray549[counts_549] = cycleNumber549;
    BaselineArray549[counts_549] = Baseline549;
    BaselineIrradArray549[counts_549] = BaselineIrrad549;
    BaselineIrradErrArray549[counts_549] = BaselineIrradErr549;
    BaselineIntegralArray549[counts_549] = BaselineIntegral549;
    BaselineIrradIntegralArray549[counts_549] = BaselineIrradIntegral549;
    UCNIntegralManualArray549[counts_549] = HistIntegral549 - BaselineIntegral549;
    // cout << UCNIntegralManualArray549[counts_549] << endl;
    UCNIntegralManualErrArray549[counts_549] = sqrt(HistIntegral549 - BaselineIntegral549);
    cout << " The irradiation time for run 549 for cycle "<< counts_549 << " is "<< cycleStartTimes549 - irradStartTimes549 << endl; 
    counts_549++;
  }


  // *****
  // 550
  // *****
  
  
  ULong64_t events550;
  events550 = (Double_t) outputTree550 -> GetEntries();

  for (ULong64_t j = 0 ; j < events550 ; j++){
    outputTree550 -> GetEvent(j);
    UCNIntegralArray550[counts_550] = UCNIntegral550;
    UCNIntegralErrArray550[counts_550] = UCNIntegralErr550;
    HistIntegralArray550[counts_550] = HistIntegral550;
    HistIntegralErrArray550[counts_550] = sqrt (HistIntegral550);
    avets12IrradArray550[counts_550] = avets12Irrad550;
    avets12ValveOpenArray550[counts_550] = avets12ValveOpen550;
    maxts12IrradArray550[counts_550] = maxts12Irrad550;
    maxts12ValveOpenArray550[counts_550] = maxts12ValveOpen550;
    mints12IrradArray550[counts_550] = mints12Irrad550; 
    mints12ValveOpenArray550[counts_550] = mints12ValveOpen550;
    ts12IrradErr550[counts_550] = (maxts12Irrad550 - mints12Irrad550)/2;
    ts12ValveOpenErr550[counts_550] = (maxts12ValveOpen550 - mints12ValveOpen550)/2;
    avecurArray550[counts_550] = avecur550;
    maxcurArray550[counts_550] = maxcur550;
    mincurArray550[counts_550] = mincur550;
    ErrcurArray550[counts_550] = (maxcur550 - mincur550)/2;
    delaytimeArray550[counts_550] = cycleDelayTime550;
    cycleNumberArray550[counts_550] = cycleNumber550;
    BaselineArray550[counts_550] = Baseline550;
    BaselineIrradArray550[counts_550] = BaselineIrrad550;
    BaselineIrradErrArray550[counts_550] = BaselineIrradErr550;
    BaselineIntegralArray550[counts_550] = BaselineIntegral550;
    BaselineIrradIntegralArray550[counts_550] = BaselineIrradIntegral550;
    UCNIntegralManualArray550[counts_550] = HistIntegral550 - BaselineIntegral550;
    // cout << UCNIntegralManualArray550[counts_550] << endl;
    UCNIntegralManualErrArray550[counts_550] = sqrt(HistIntegral550 - BaselineIntegral550);
    cout << " The irradiation time for run 550  for cycle "<< counts_550 << " is "<< cycleStartTimes550 - irradStartTimes550 << endl; 
    counts_550++;
  }


  // *****
  // 551
  // *****
  
  
  ULong64_t events551;
  events551 = (Double_t) outputTree551 -> GetEntries();

  for (ULong64_t j = 0 ; j < events551 ; j++){
    outputTree551 -> GetEvent(j);
    UCNIntegralArray551[counts_551] = UCNIntegral551;
    UCNIntegralErrArray551[counts_551] = UCNIntegralErr551;
    HistIntegralArray551[counts_551] = HistIntegral551;
    HistIntegralErrArray551[counts_551] = sqrt (HistIntegral551);
    avets12IrradArray551[counts_551] = avets12Irrad551;
    avets12ValveOpenArray551[counts_551] = avets12ValveOpen551;
    maxts12IrradArray551[counts_551] = maxts12Irrad551;
    maxts12ValveOpenArray551[counts_551] = maxts12ValveOpen551;
    mints12IrradArray551[counts_551] = mints12Irrad551; 
    mints12ValveOpenArray551[counts_551] = mints12ValveOpen551;
    ts12IrradErr551[counts_551] = (maxts12Irrad551 - mints12Irrad551)/2;
    ts12ValveOpenErr551[counts_551] = (maxts12ValveOpen551 - mints12ValveOpen551)/2;
    avecurArray551[counts_551] = avecur551;
    maxcurArray551[counts_551] = maxcur551;
    mincurArray551[counts_551] = mincur551;
    ErrcurArray551[counts_551] = (maxcur551 - mincur551)/2;
    delaytimeArray551[counts_551] = cycleDelayTime551;
    cycleNumberArray551[counts_551] = cycleNumber551;
    BaselineArray551[counts_551] = Baseline551;
    BaselineIrradArray551[counts_551] = BaselineIrrad551;
    BaselineIrradErrArray551[counts_551] = BaselineIrradErr551;
    BaselineIntegralArray551[counts_551] = BaselineIntegral551;
    BaselineIrradIntegralArray551[counts_551] = BaselineIrradIntegral551;
    UCNIntegralManualArray551[counts_551] = HistIntegral551 - BaselineIntegral551;
    // cout << UCNIntegralManualArray551[counts_551] << endl;
    UCNIntegralManualErrArray551[counts_551] = sqrt(HistIntegral551 - BaselineIntegral551);
    cout << " The irradiation time for run 551 for cycle " << counts_551 << " is "<< cycleStartTimes551 - irradStartTimes551 << endl; 
    counts_551++;
  }



  // *****
  // 552
  // *****
  
  
  ULong64_t events552;
  events552 = (Double_t) outputTree552 -> GetEntries();

  for (ULong64_t j = 0 ; j < events552 ; j++){
    outputTree552 -> GetEvent(j);
    if ( j==3)
      continue;
    UCNIntegralArray552[counts_552] = UCNIntegral552;
    UCNIntegralErrArray552[counts_552] = UCNIntegralErr552;
    HistIntegralArray552[counts_552] = HistIntegral552;
    HistIntegralErrArray552[counts_552] = sqrt (HistIntegral552);
    avets12IrradArray552[counts_552] = avets12Irrad552;
    avets12ValveOpenArray552[counts_552] = avets12ValveOpen552;
    maxts12IrradArray552[counts_552] = maxts12Irrad552;
    maxts12ValveOpenArray552[counts_552] = maxts12ValveOpen552;
    mints12IrradArray552[counts_552] = mints12Irrad552; 
    mints12ValveOpenArray552[counts_552] = mints12ValveOpen552;
    ts12IrradErr552[counts_552] = (maxts12Irrad552 - mints12Irrad552)/2;
    ts12ValveOpenErr552[counts_552] = (maxts12ValveOpen552 - mints12ValveOpen552)/2;
    avecurArray552[counts_552] = avecur552;
    maxcurArray552[counts_552] = maxcur552;
    mincurArray552[counts_552] = mincur552;
    ErrcurArray552[counts_552] = (maxcur552 - mincur552)/2;
    delaytimeArray552[counts_552] = cycleDelayTime552;
    cycleNumberArray552[counts_552] = cycleNumber552;
    BaselineArray552[counts_552] = Baseline552;
    BaselineIrradArray552[counts_552] = BaselineIrrad552;
    BaselineIrradErrArray552[counts_552] = BaselineIrradErr552;
    BaselineIntegralArray552[counts_552] = BaselineIntegral552;
    BaselineIrradIntegralArray552[counts_552] = BaselineIrradIntegral552;
    UCNIntegralManualArray552[counts_552] = HistIntegral552 - BaselineIntegral552;
    // cout << UCNIntegralManualArray552[counts_552] << endl;
    UCNIntegralManualErrArray552[counts_552] = sqrt(HistIntegral552 - BaselineIntegral552);
    cout << " The irradiation time for run 552 for cycle "<< counts_552<< " is "<< cycleStartTimes552 - irradStartTimes552 << endl; 
    counts_552++;
  }


  
 
  
  // *******************
  //     GRAPHS
  // ******************

  // ******
  //  549
  // ******
  

  TCanvas *c549_cylceNum =  new TCanvas("c549_cycleNum" , "c549_cycleNum " , 1200, 900);
  c549_cycleNum-> Divide(2,2);

  TPad *p549_1 = c549_cycleNum->cd(1);
  p549_1->SetLogy(); 
  TGraphErrors *gr549_cyclecounts = new TGraphErrors (counts_549 , cycleNumberArray549, UCNIntegralArray549, 0 , UCNIntegralErrArray549);
  gr549_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr549_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr549_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr549_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr549_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr549_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr549_cyclehist = new TGraphErrors(counts_549, cycleNumberArray549 , HistIntegralArray549, 0, HistIntegralErrArray549);
  
  gr549_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr549_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr549_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr549_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr549_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr549_cyclehist -> SetMarkerColor(2);
  gr549_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr549_cyclecountmanual = new TGraphErrors(counts_549, cycleNumberArray549 , UCNIntegralManualArray549, 0, UCNIntegralManualErrArray549);
  
  gr549_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr549_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr549_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr549_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr549_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr549_cyclecountmanual -> SetMarkerColor(1);
  gr549_cyclecountmanual -> SetMarkerStyle(25);
  

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr549_cyclecounts , "Without Background (fit)" , "p") ;
  leg2 -> AddEntry(gr549_cyclehist , "With Background" , "p") ;
  //leg2 -> AddEntry(gr549_cyclecountmanual, "Without Background" , "p"); 
  leg2 -> SetTextSize(0.05);
  
  gr549_cyclecounts -> Draw("Ap");
  gr549_cyclehist -> Draw("p");
  //gr549_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c549_cycleNum -> cd(2);
  TGraphErrors *gr549_cycledelay = new TGraphErrors (counts_549 , cycleNumberArray549, delaytimeArray549, 0 , 0);
  gr549_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr549_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr549_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr549_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr549_cycledelay -> SetMarkerStyle(20);
  
  gr549_cycledelay -> Draw("Ap");
  
  
  c549_cycleNum -> cd(3);
  TGraphErrors *gr549_cycletempIrrad = new TGraphErrors (counts_549 , cycleNumberArray549, avets12IrradArray549, 0 , ts12IrradErr549);
  
  gr549_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr549_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr549_cycletempIrrad -> SetMarkerStyle(20);
  gr549_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr549_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr549_cycletempValveOpen = new TGraphErrors (counts_549 , cycleNumberArray549, avets12ValveOpenArray549, 0 , ts12ValveOpenErr549);
  
  gr549_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr549_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr549_cycletempValveOpen -> SetMarkerStyle(20);
  gr549_cycletempValveOpen -> SetMarkerColor(2);
  gr549_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr549_cycletempIrrad , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr549_cycletempValveOpen , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  
  gr549_cycletempIrrad -> Draw("AP");
  gr549_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c549_cycleNum -> cd(4);
  TGraphErrors *gr549_cyclecur = new TGraphErrors (counts_549 , cycleNumberArray549 , avecurArray549, 0, ErrcurArray549 );
  gr549_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr549_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr549_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr549_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr549_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr549_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr549_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr549_cyclecur -> SetMarkerStyle(20);
  gr549_cyclecur -> Draw("Ap");
  c549_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c549_counttemp = new TCanvas ("c549_counttemp" , "c549_counttemp " , 1200, 900);
  c549_counttemp -> SetLogy();

  TGraphErrors *gr549_countIrrad = new TGraphErrors (counts_549, avets12IrradArray549, UCNIntegralArray549, ts12IrradErr549, UCNIntegralErrArray549);
  gr549_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr549_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr549_countIrrad -> SetMarkerStyle(20);
  gr549_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr549_countIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr549_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr549_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr549_HistIrrad = new TGraphErrors (counts_549, avets12IrradArray549, HistIntegralArray549, ts12IrradErr549, HistIntegralErrArray549);
  gr549_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr549_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr549_HistIrrad -> SetMarkerStyle(25);
  gr549_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr549_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr549_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr549_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr549_countValveOpen = new TGraphErrors (counts_549, avets12ValveOpenArray549, UCNIntegralArray549, ts12ValveOpenErr549, UCNIntegralErrArray549);
  gr549_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr549_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr549_countValveOpen -> SetMarkerStyle(20);
  gr549_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr549_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr549_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr549_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr549_HistValveOpen = new TGraphErrors (counts_549, avets12ValveOpenArray549, HistIntegralArray549, ts12ValveOpenErr549, HistIntegralErrArray549);
  gr549_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr549_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr549_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr549_HistValveOpen -> SetMarkerStyle(25);
  gr549_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr549_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr549_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr549_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr549_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr549_HistValveOpen -> SetMarkerColor(2);

  TLegend *leg3 = new TLegend(0.25,0.7, 0.9, 0.9);
  leg3 -> AddEntry(gr549_countIrrad , "Irradiation time + delay time, without background" , "p") ;
  //leg3 -> AddEntry(gr549_countValveOpen , "Valve open, without background" , "p") ;
  leg3 -> AddEntry(gr549_HistIrrad , "Irradiation time + delay time, with background" , "p") ;
  //leg3 -> AddEntry(gr549_HistValveOpen , "Valve open, with background" , "p") ;
  leg3 -> SetTextSize(0.04);

  gr549_countIrrad -> Draw("AP");
  //gr549_countValveOpen -> Draw("p");
   gr549_HistIrrad -> Draw("p");
  //gr549_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  // ************************************************
  
  // ******
  //  550
  // ******
  

  TCanvas *c550_cylceNum =  new TCanvas("c550_cycleNum" , "c550_cycleNum " , 1200, 900);
  c550_cycleNum-> Divide(2,2);

  TPad *p550_1 = c550_cycleNum->cd(1);
  p550_1->SetLogy(); 
  TGraphErrors *gr550_cyclecounts = new TGraphErrors (counts_550 , cycleNumberArray550, UCNIntegralArray550, 0 , UCNIntegralErrArray550);
  gr550_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr550_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr550_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr550_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr550_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr550_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr550_cyclehist = new TGraphErrors(counts_550, cycleNumberArray550 , HistIntegralArray550, 0, HistIntegralErrArray550);
  
  gr550_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr550_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr550_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr550_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr550_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr550_cyclehist -> SetMarkerColor(2);
  gr550_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr550_cyclecountmanual = new TGraphErrors(counts_550, cycleNumberArray550 , UCNIntegralManualArray550, 0, UCNIntegralManualErrArray550);
  
  gr550_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr550_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr550_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr550_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr550_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr550_cyclecountmanual -> SetMarkerColor(1);
  gr550_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr550_cyclecounts -> Draw("Ap");
  gr550_cyclehist -> Draw("p");
  //gr550_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c550_cycleNum -> cd(2);
  TGraphErrors *gr550_cycledelay = new TGraphErrors (counts_550 , cycleNumberArray550, delaytimeArray550, 0 , 0);
  gr550_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr550_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr550_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr550_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr550_cycledelay -> SetMarkerStyle(20);
  
  gr550_cycledelay -> Draw("Ap");
  
  
  c550_cycleNum -> cd(3);
  TGraphErrors *gr550_cycletempIrrad = new TGraphErrors (counts_550 , cycleNumberArray550, avets12IrradArray550, 0 , ts12IrradErr550);
  
  gr550_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr550_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr550_cycletempIrrad -> SetMarkerStyle(20);
  gr550_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr550_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr550_cycletempValveOpen = new TGraphErrors (counts_550 , cycleNumberArray550, avets12ValveOpenArray550, 0 , ts12ValveOpenErr550);
  
  gr550_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr550_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr550_cycletempValveOpen -> SetMarkerStyle(20);
  gr550_cycletempValveOpen -> SetMarkerColor(2);
  gr550_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr550_cycletempIrrad -> Draw("AP");
  gr550_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c550_cycleNum -> cd(4);
  TGraphErrors *gr550_cyclecur = new TGraphErrors (counts_550 , cycleNumberArray550 , avecurArray550, 0, ErrcurArray550 );
  gr550_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr550_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr550_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr550_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr550_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr550_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr550_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr550_cyclecur -> SetMarkerStyle(20);
  gr550_cyclecur -> Draw("Ap");
  c550_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c550_counttemp = new TCanvas ("c550_counttemp" , "c550_counttemp " , 1200, 900);
  c550_counttemp -> SetLogy();

  TGraphErrors *gr550_countIrrad = new TGraphErrors (counts_550, avets12IrradArray550, UCNIntegralArray550, ts12IrradErr550, UCNIntegralErrArray550);
  gr550_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr550_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr550_countIrrad -> SetMarkerStyle(20);
  gr550_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr550_countIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr550_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr550_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr550_HistIrrad = new TGraphErrors (counts_550, avets12IrradArray550, HistIntegralArray550, ts12IrradErr550, HistIntegralErrArray550);
  gr550_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr550_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr550_HistIrrad -> SetMarkerStyle(25);
  gr550_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr550_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr550_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr550_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr550_countValveOpen = new TGraphErrors (counts_550, avets12ValveOpenArray550, UCNIntegralArray550, ts12ValveOpenErr550, UCNIntegralErrArray550);
  gr550_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr550_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr550_countValveOpen -> SetMarkerStyle(20);
  gr550_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr550_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr550_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr550_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr550_HistValveOpen = new TGraphErrors (counts_550, avets12ValveOpenArray550, HistIntegralArray550, ts12ValveOpenErr550, HistIntegralErrArray550);
  gr550_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr550_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr550_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr550_HistValveOpen -> SetMarkerStyle(25);
  gr550_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr550_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr550_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr550_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr550_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr550_HistValveOpen -> SetMarkerColor(2);



  gr550_countIrrad -> Draw("AP");
  //gr550_countValveOpen -> Draw("p");
   gr550_HistIrrad -> Draw("p");
  //gr550_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  //*******************************************
  // ******
  //  551
  // ******
  

  TCanvas *c551_cylceNum =  new TCanvas("c551_cycleNum" , "c551_cycleNum " , 1200, 900);
  c551_cycleNum-> Divide(2,2);

  TPad *p551_1 = c551_cycleNum->cd(1);
  p551_1->SetLogy(); 
  TGraphErrors *gr551_cyclecounts = new TGraphErrors (counts_551 , cycleNumberArray551, UCNIntegralArray551, 0 , UCNIntegralErrArray551);
  gr551_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr551_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr551_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr551_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr551_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr551_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr551_cyclehist = new TGraphErrors(counts_551, cycleNumberArray551 , HistIntegralArray551, 0, HistIntegralErrArray551);
  
  gr551_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr551_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr551_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr551_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr551_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr551_cyclehist -> SetMarkerColor(2);
  gr551_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr551_cyclecountmanual = new TGraphErrors(counts_551, cycleNumberArray551 , UCNIntegralManualArray551, 0, UCNIntegralManualErrArray551);
  
  gr551_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr551_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr551_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr551_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr551_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr551_cyclecountmanual -> SetMarkerColor(1);
  gr551_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr551_cyclecounts -> Draw("Ap");
  gr551_cyclehist -> Draw("p");
  // gr551_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c551_cycleNum -> cd(2);
  TGraphErrors *gr551_cycledelay = new TGraphErrors (counts_551 , cycleNumberArray551, delaytimeArray551, 0 , 0);
  gr551_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr551_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr551_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr551_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr551_cycledelay -> SetMarkerStyle(20);
  gr551_cycledelay -> Draw("Ap");
  
  
  c551_cycleNum -> cd(3);
  TGraphErrors *gr551_cycletempIrrad = new TGraphErrors (counts_551 , cycleNumberArray551, avets12IrradArray551, 0 , ts12IrradErr551);
  
  gr551_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr551_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr551_cycletempIrrad -> SetMarkerStyle(20);
  gr551_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr551_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr551_cycletempValveOpen = new TGraphErrors (counts_551 , cycleNumberArray551, avets12ValveOpenArray551, 0 , ts12ValveOpenErr551);
  
  gr551_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr551_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr551_cycletempValveOpen -> SetMarkerStyle(20);
  gr551_cycletempValveOpen -> SetMarkerColor(2);
  gr551_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr551_cycletempIrrad -> Draw("AP");
  gr551_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c551_cycleNum -> cd(4);
  TGraphErrors *gr551_cyclecur = new TGraphErrors (counts_551 , cycleNumberArray551 , avecurArray551, 0, ErrcurArray551 );
  gr551_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr551_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr551_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr551_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr551_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr551_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr551_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr551_cyclecur -> SetMarkerStyle(20);
  gr551_cyclecur -> Draw("Ap");
  c551_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c551_counttemp = new TCanvas ("c551_counttemp" , "c551_counttemp " , 1200, 900);
  c551_counttemp -> SetLogy();

  TGraphErrors *gr551_countIrrad = new TGraphErrors (counts_551, avets12IrradArray551, UCNIntegralArray551, ts12IrradErr551, UCNIntegralErrArray551);
  gr551_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr551_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr551_countIrrad -> SetMarkerStyle(20);
  gr551_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr551_countIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr551_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr551_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr551_HistIrrad = new TGraphErrors (counts_551, avets12IrradArray551, HistIntegralArray551, ts12IrradErr551, HistIntegralErrArray551);
  gr551_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr551_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr551_HistIrrad -> SetMarkerStyle(25);
  gr551_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr551_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr551_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr551_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr551_countValveOpen = new TGraphErrors (counts_551, avets12ValveOpenArray551, UCNIntegralArray551, ts12ValveOpenErr551, UCNIntegralErrArray551);
  gr551_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr551_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr551_countValveOpen -> SetMarkerStyle(20);
  gr551_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr551_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr551_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr551_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr551_HistValveOpen = new TGraphErrors (counts_551, avets12ValveOpenArray551, HistIntegralArray551, ts12ValveOpenErr551, HistIntegralErrArray551);
  gr551_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr551_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr551_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr551_HistValveOpen -> SetMarkerStyle(25);
  gr551_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr551_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr551_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr551_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr551_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr551_HistValveOpen -> SetMarkerColor(2);



  gr551_countIrrad -> Draw("AP");
  //gr551_countValveOpen -> Draw("p");
   gr551_HistIrrad -> Draw("p");
  //gr551_HistValveOpen -> Draw("p");
  leg3 -> Draw();



  //********************************************
  // ******
  //  552
  // ******
  

  TCanvas *c552_cylceNum =  new TCanvas("c552_cycleNum" , "c552_cycleNum " , 1200, 900);
  c552_cycleNum-> Divide(2,2);

  TPad *p552_1 = c552_cycleNum->cd(1);
  p552_1->SetLogy(); 
  TGraphErrors *gr552_cyclecounts = new TGraphErrors (counts_552 , cycleNumberArray552, UCNIntegralArray552, 0 , UCNIntegralErrArray552);
  gr552_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr552_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr552_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr552_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr552_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr552_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr552_cyclehist = new TGraphErrors(counts_552, cycleNumberArray552 , HistIntegralArray552, 0, HistIntegralErrArray552);
  
  gr552_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr552_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr552_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr552_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr552_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr552_cyclehist -> SetMarkerColor(2);
  gr552_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr552_cyclecountmanual = new TGraphErrors(counts_552, cycleNumberArray552 , UCNIntegralManualArray552, 0, UCNIntegralManualErrArray552);
  
  gr552_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr552_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr552_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr552_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr552_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr552_cyclecountmanual -> SetMarkerColor(1);
  gr552_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr552_cyclecounts -> Draw("Ap");
  gr552_cyclehist -> Draw("p");
  //gr552_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c552_cycleNum -> cd(2);
  TGraphErrors *gr552_cycledelay = new TGraphErrors (counts_552 , cycleNumberArray552, delaytimeArray552, 0 , 0);
  gr552_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr552_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr552_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr552_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr552_cycledelay -> SetMarkerStyle(20);
  
  gr552_cycledelay -> Draw("Ap");
  
  
  c552_cycleNum -> cd(3);
  TGraphErrors *gr552_cycletempIrrad = new TGraphErrors (counts_552 , cycleNumberArray552, avets12IrradArray552, 0 , ts12IrradErr552);
  
  gr552_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr552_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr552_cycletempIrrad -> SetMarkerStyle(20);
  gr552_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr552_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr552_cycletempValveOpen = new TGraphErrors (counts_552 , cycleNumberArray552, avets12ValveOpenArray552, 0 , ts12ValveOpenErr552);
  
  gr552_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr552_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr552_cycletempValveOpen -> SetMarkerStyle(20);
  gr552_cycletempValveOpen -> SetMarkerColor(2);
  gr552_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr552_cycletempIrrad -> Draw("AP");
  gr552_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c552_cycleNum -> cd(4);
  TGraphErrors *gr552_cyclecur = new TGraphErrors (counts_552 , cycleNumberArray552 , avecurArray552, 0, ErrcurArray552 );
  gr552_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr552_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr552_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr552_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr552_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr552_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr552_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr552_cyclecur -> SetMarkerStyle(20);
  gr552_cyclecur -> Draw("Ap");
  c552_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c552_counttemp = new TCanvas ("c552_counttemp" , "c552_counttemp " , 1200, 900);
  c552_counttemp -> SetLogy();

  TGraphErrors *gr552_countIrrad = new TGraphErrors (counts_552, avets12IrradArray552, UCNIntegralArray552, ts12IrradErr552, UCNIntegralErrArray552);
  gr552_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr552_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr552_countIrrad -> SetMarkerStyle(20);
  gr552_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr552_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr552_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr552_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr552_HistIrrad = new TGraphErrors (counts_552, avets12IrradArray552, HistIntegralArray552, ts12IrradErr552, HistIntegralErrArray552);
  gr552_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr552_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr552_HistIrrad -> SetMarkerStyle(25);
  gr552_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr552_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr552_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr552_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr552_countValveOpen = new TGraphErrors (counts_552, avets12ValveOpenArray552, UCNIntegralArray552, ts12ValveOpenErr552, UCNIntegralErrArray552);
  gr552_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr552_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr552_countValveOpen -> SetMarkerStyle(20);
  gr552_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr552_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr552_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr552_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr552_HistValveOpen = new TGraphErrors (counts_552, avets12ValveOpenArray552, HistIntegralArray552, ts12ValveOpenErr552, HistIntegralErrArray552);
  gr552_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr552_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr552_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr552_HistValveOpen -> SetMarkerStyle(25);
  gr552_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr552_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr552_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr552_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr552_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr552_HistValveOpen -> SetMarkerColor(2);



  gr552_countIrrad -> Draw("AP");
  //gr552_countValveOpen -> Draw("p");
   gr552_HistIrrad -> Draw("p");
  //gr552_HistValveOpen -> Draw("p");
  leg3 -> Draw();

  // *******************************************
  // OVERALL
  // ******************************************

  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);
  cAll -> SetLogy();

  gr549_countIrrad -> GetYaxis()-> SetRangeUser(1, 1200000);
  gr549_countIrrad -> GetXaxis() -> SetLimits(0.8, 1.8);
  gr549_countIrrad -> SetMarkerStyle(20);
  gr549_HistIrrad -> SetMarkerStyle(25);
  gr550_countIrrad -> SetMarkerColor(2);
  gr550_HistIrrad -> SetMarkerColor(2);
  gr551_countIrrad -> SetMarkerColor(9);
  gr551_HistIrrad -> SetMarkerColor(9);

  TLegend *legAll = new TLegend (0.2, 0.7, 0.9, 0.9);
  legAll -> SetTextSize(0.02);
  legAll -> AddEntry(gr549_countIrrad , "Temp during rradiation time + delay time, counts without backgroun (fit) , 0 s delay time", "p");
  legAll -> AddEntry(gr549_HistIrrad , "Temp during rradiation time + delay time, counts with backgroun , 0 s delay time", "p");
  legAll -> AddEntry(gr550_countIrrad , "Temp during rradiation time + delay time, counts without backgroun (fit) , 20 s delay time", "p");
  legAll -> AddEntry(gr550_HistIrrad , "Temp during rradiation time + delay time, counts with backgroun , 20 s delay time", "p");
  legAll -> AddEntry(gr551_countIrrad , "Temp during rradiation time + delay time, counts without backgroun (fit) , 50 s delay time", "p");
  legAll -> AddEntry(gr551_HistIrrad , "Temp during rradiation time + delay time, counts with backgroun , 50 s delay time", "p");

  

  gr549_countIrrad -> Draw("ap");
  gr549_HistIrrad -> Draw("p");
  gr550_countIrrad -> Draw("p");
  gr550_HistIrrad -> Draw("p");
  gr551_countIrrad -> Draw("p");
   gr551_HistIrrad -> Draw("p");
  gr552_countIrrad -> Draw("p");
  gr552_HistIrrad -> Draw("p");
  legAll -> Draw();














  
}
