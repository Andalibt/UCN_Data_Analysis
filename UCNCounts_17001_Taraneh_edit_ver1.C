// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17001.
// WHAT ELSE??
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17001_Taraneh_edit_ver1(){

  TFile *fin524 = new TFile ("outputTree_524.root", "READ");
  TFile *fin525 = new TFile ("outputTree_525.root", "READ");
  TFile *fin526 = new TFile ("outputTree_526.root", "READ");
  TFile *fin527 = new TFile ("outputTree_527.root", "READ");
  TFile *fin528 = new TFile ("outputTree_528.root", "READ");
  TFile *fin529 = new TFile ("outputTree_529.root", "READ");
  TFile *fin530 = new TFile ("outputTree_530.root", "READ");
  
  TTree *outputTree524 = (TTree*) fin524 -> Get("cycle_info");
  TTree *outputTree525 = (TTree*) fin525 -> Get("cycle_info");
  TTree *outputTree526 = (TTree*) fin526 -> Get("cycle_info");
  TTree *outputTree527 = (TTree*) fin527 -> Get("cycle_info");
  TTree *outputTree528 = (TTree*) fin528 -> Get("cycle_info");
  TTree *outputTree529 = (TTree*) fin529 -> Get("cycle_info");
  TTree *outputTree530 = (TTree*) fin530 -> Get("cycle_info");

  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double irradStartTimes524;
  double irradStartTimes525;
  double irradStartTimes526;
  double irradStartTimes527;
  double irradStartTimes528;
  double irradStartTimes529;
  double irradStartTimes530;

  outputTree524 -> SetBranchAddress("irradStartTimes" , &irradStartTimes524);
  outputTree525 -> SetBranchAddress("irradStartTimes" , &irradStartTimes525);
  outputTree526 -> SetBranchAddress("irradStartTimes" , &irradStartTimes526);
  outputTree527 -> SetBranchAddress("irradStartTimes" , &irradStartTimes527);
  outputTree528 -> SetBranchAddress("irradStartTimes" , &irradStartTimes528);
  outputTree529 -> SetBranchAddress("irradStartTimes" , &irradStartTimes529);
  outputTree530 -> SetBranchAddress("irradStartTimes" , &irradStartTimes530);

  double cycleStartTimes524;
  double cycleStartTimes525;
  double cycleStartTimes526;
  double cycleStartTimes527;
  double cycleStartTimes528;
  double cycleStartTimes529;
  double cycleStartTimes530;

  outputTree524 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes524);
  outputTree525 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes525);
  outputTree526 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes526);
  outputTree527 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes527);
  outputTree528 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes528);
  outputTree529 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes529);
  outputTree530 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes530);



  
  double cycleDelayTime524;
  double cycleDelayTime525;
  double cycleDelayTime526;
  double cycleDelayTime527;
  double cycleDelayTime528;
  double cycleDelayTime529;
  double cycleDelayTime530;
  outputTree524 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime524);
  outputTree525 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime525);
  outputTree526 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime526);
  outputTree527 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime527);
  outputTree528 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime528);
  outputTree529 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime529);
  outputTree530 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime530);
  double delaytimeArray524[100];
  double delaytimeArray525[100];
  double delaytimeArray526[100];
  double delaytimeArray527[100];
  double delaytimeArray528[100];
  double delaytimeArray529[100];
  double delaytimeArray530[100];

  int cycleNumber524;
  int cycleNumber525;
  int cycleNumber526;
  int cycleNumber527;
  int cycleNumber528;
  int cycleNumber529;
  int cycleNumber530;
  outputTree524 -> SetBranchAddress("cycleNumber", &cycleNumber524);
  outputTree525 -> SetBranchAddress("cycleNumber", &cycleNumber525);
  outputTree526 -> SetBranchAddress("cycleNumber", &cycleNumber526);
  outputTree527 -> SetBranchAddress("cycleNumber", &cycleNumber527);
  outputTree528 -> SetBranchAddress("cycleNumber", &cycleNumber528);
  outputTree529 -> SetBranchAddress("cycleNumber", &cycleNumber529);
  outputTree530 -> SetBranchAddress("cycleNumber", &cycleNumber530);
  double cycleNumberArray524 [100];
  double cycleNumberArray525 [100];
  double cycleNumberArray526 [100];
  double cycleNumberArray527 [100];
  double cycleNumberArray528 [100];
  double cycleNumberArray529 [100];
  double cycleNumberArray530 [100];  
  
  double UCNIntegral524;
  double UCNIntegral525;
  double UCNIntegral526;
  double UCNIntegral527;
  double UCNIntegral528;
  double UCNIntegral529;
  double UCNIntegral530;
  outputTree524 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral524);
  outputTree525 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral525);
  outputTree526 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral526);
  outputTree527 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral527);
  outputTree528 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral528);
  outputTree529 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral529);
  outputTree530 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral530);
  double UCNIntegralArray524 [100];
  double UCNIntegralArray525 [100];
  double UCNIntegralArray526 [100];
  double UCNIntegralArray527 [100];
  double UCNIntegralArray528 [100];
  double UCNIntegralArray529 [100];
  double UCNIntegralArray530 [100];

  double UCNIntegralErr524;
  double UCNIntegralErr525;
  double UCNIntegralErr526;
  double UCNIntegralErr527;
  double UCNIntegralErr528;
  double UCNIntegralErr529;
  double UCNIntegralErr530;
  outputTree524 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr524);
  outputTree525 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr525);
  outputTree526 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr526);
  outputTree527 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr527);
  outputTree528 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr528);
  outputTree529 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr529);
  outputTree530 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr530);
  double UCNIntegralErrArray524 [100];
  double UCNIntegralErrArray525 [100];
  double UCNIntegralErrArray526 [100];
  double UCNIntegralErrArray527 [100];
  double UCNIntegralErrArray528 [100];
  double UCNIntegralErrArray529 [100];
  double UCNIntegralErrArray530 [100];

  double HistIntegral524;
  double HistIntegral525;
  double HistIntegral526;
  double HistIntegral527;
  double HistIntegral528;
  double HistIntegral529;
  double HistIntegral530;
  outputTree524 -> SetBranchAddress ("HistIntegral" , &HistIntegral524);
  outputTree525 -> SetBranchAddress ("HistIntegral" , &HistIntegral525);
  outputTree526 -> SetBranchAddress ("HistIntegral" , &HistIntegral526);
  outputTree527 -> SetBranchAddress ("HistIntegral" , &HistIntegral527);
  outputTree528 -> SetBranchAddress ("HistIntegral" , &HistIntegral528);
  outputTree529 -> SetBranchAddress ("HistIntegral" , &HistIntegral529);
  outputTree530 -> SetBranchAddress ("HistIntegral" , &HistIntegral530); 
  double HistIntegralArray524 [100];
  double HistIntegralArray525 [100];
  double HistIntegralArray526 [100];
  double HistIntegralArray527 [100];
  double HistIntegralArray528 [100];
  double HistIntegralArray529 [100];
  double HistIntegralArray530 [100];
  double HistIntegralErrArray524[100];
  double HistIntegralErrArray525[100];
  double HistIntegralErrArray526[100];
  double HistIntegralErrArray527[100];
  double HistIntegralErrArray528[100];
  double HistIntegralErrArray529[100];
  double HistIntegralErrArray530[100];

  double avets12Irrad524;
  double avets12Irrad525;
  double avets12Irrad526;
  double avets12Irrad527;
  double avets12Irrad528;
  double avets12Irrad529;
  double avets12Irrad530;
  outputTree524 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad524);
  outputTree525 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad525);
  outputTree526 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad526);
  outputTree527 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad527);
  outputTree528 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad528);
  outputTree529 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad529);
  outputTree530 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad530);
  double avets12IrradArray524 [100];
  double avets12IrradArray525 [100];
  double avets12IrradArray526 [100];
  double avets12IrradArray527 [100];
  double avets12IrradArray528 [100];
  double avets12IrradArray529 [100];
  double avets12IrradArray530 [100];
  
  double avets12ValveOpen524;
  double avets12ValveOpen525;
  double avets12ValveOpen526;
  double avets12ValveOpen527;
  double avets12ValveOpen528;
  double avets12ValveOpen529;
  double avets12ValveOpen530;
  outputTree524 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen524);
  outputTree525 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen525);
  outputTree526 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen526);
  outputTree527 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen527);
  outputTree528 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen528);
  outputTree529 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen529);
  outputTree530 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen530);
  double avets12ValveOpenArray524 [100];
  double avets12ValveOpenArray525 [100];
  double avets12ValveOpenArray526 [100];
  double avets12ValveOpenArray527 [100];
  double avets12ValveOpenArray528 [100];
  double avets12ValveOpenArray529 [100];
  double avets12ValveOpenArray530 [100];
  
  double maxts12Irrad524;
  double maxts12Irrad525;
  double maxts12Irrad526;
  double maxts12Irrad527;
  double maxts12Irrad528;
  double maxts12Irrad529;
  double maxts12Irrad530;
  outputTree524 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad524);
  outputTree525 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad525);
  outputTree526 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad526);
  outputTree527 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad527);
  outputTree528 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad528);
  outputTree529 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad529);
  outputTree530 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad530);
  double maxts12IrradArray524 [100];
  double maxts12IrradArray525 [100];
  double maxts12IrradArray526 [100];
  double maxts12IrradArray527 [100];
  double maxts12IrradArray528 [100];
  double maxts12IrradArray529 [100];
  double maxts12IrradArray530 [100];
  
  double maxts12ValveOpen524;
  double maxts12ValveOpen525;
  double maxts12ValveOpen526;
  double maxts12ValveOpen527;
  double maxts12ValveOpen528;
  double maxts12ValveOpen529;
  double maxts12ValveOpen530;
  outputTree524 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen524);
  outputTree525 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen525);
  outputTree526 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen526);
  outputTree527 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen527);
  outputTree528 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen528);
  outputTree529 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen529);
  outputTree530 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen530);
  double maxts12ValveOpenArray524 [100];
  double maxts12ValveOpenArray525 [100];
  double maxts12ValveOpenArray526 [100];
  double maxts12ValveOpenArray527 [100];
  double maxts12ValveOpenArray528 [100];
  double maxts12ValveOpenArray529 [100];
  double maxts12ValveOpenArray530 [100];

  double mints12Irrad524;
  double mints12Irrad525;
  double mints12Irrad526;
  double mints12Irrad527;
  double mints12Irrad528;
  double mints12Irrad529;
  double mints12Irrad530;
  outputTree524 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad524);
  outputTree525 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad525);
  outputTree526 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad526);
  outputTree527 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad527);
  outputTree528 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad528);
  outputTree529 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad529);
  outputTree530 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad530);
  double mints12IrradArray524 [100];
  double mints12IrradArray525 [100];
  double mints12IrradArray526 [100];
  double mints12IrradArray527 [100];
  double mints12IrradArray528 [100];
  double mints12IrradArray529 [100];
  double mints12IrradArray530 [100];
  
  double mints12ValveOpen524;
  double mints12ValveOpen525;
  double mints12ValveOpen526;
  double mints12ValveOpen527;
  double mints12ValveOpen528;
  double mints12ValveOpen529;
  double mints12ValveOpen530;
  outputTree524 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen524);
  outputTree525 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen525);
  outputTree526 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen526);
  outputTree527 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen527);
  outputTree528 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen528);
  outputTree529 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen529);
  outputTree530 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen530);
  double mints12ValveOpenArray524 [100];
  double mints12ValveOpenArray525 [100];
  double mints12ValveOpenArray526 [100];
  double mints12ValveOpenArray527 [100];
  double mints12ValveOpenArray528 [100];
  double mints12ValveOpenArray529 [100];
  double mints12ValveOpenArray530 [100];
    

  double ts12IrradErr524 [100];
  double ts12IrradErr525 [100];
  double ts12IrradErr526 [100];
  double ts12IrradErr527 [100];
  double ts12IrradErr528 [100];
  double ts12IrradErr529 [100];
  double ts12IrradErr530 [100];
  double ts12ValveOpenErr524 [100];
  double ts12ValveOpenErr525 [100];
  double ts12ValveOpenErr526 [100];
  double ts12ValveOpenErr527 [100];
  double ts12ValveOpenErr528 [100];
  double ts12ValveOpenErr529 [100];
  double ts12ValveOpenErr530 [100];

  double avecur524;
  double avecur525;
  double avecur526;
  double avecur527;
  double avecur528;
  double avecur529;
  double avecur530;
  outputTree524 -> SetBranchAddress ("AVE_PRDCUR" , &avecur524);
  outputTree525 -> SetBranchAddress ("AVE_PRDCUR" , &avecur525);
  outputTree526 -> SetBranchAddress ("AVE_PRDCUR" , &avecur526);
  outputTree527 -> SetBranchAddress ("AVE_PRDCUR" , &avecur527);
  outputTree528 -> SetBranchAddress ("AVE_PRDCUR" , &avecur528);
  outputTree529 -> SetBranchAddress ("AVE_PRDCUR" , &avecur529);
  outputTree530 -> SetBranchAddress ("AVE_PRDCUR" , &avecur530);
  double avecurArray524 [100];
  double avecurArray525 [100];
  double avecurArray526 [100];
  double avecurArray527 [100];
  double avecurArray528 [100];
  double avecurArray529 [100];
  double avecurArray530 [100];

  double maxcur524;
  double maxcur525;
  double maxcur526;
  double maxcur527;
  double maxcur528;
  double maxcur529;
  double maxcur530;
  outputTree524 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur524);
  outputTree525 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur525);
  outputTree526 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur526);
  outputTree527 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur527);
  outputTree528 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur528);
  outputTree529 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur529);
  outputTree530 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur530);
  double maxcurArray524 [100];
  double maxcurArray525 [100];
  double maxcurArray526 [100];
  double maxcurArray527 [100];
  double maxcurArray528 [100];
  double maxcurArray529 [100];
  double maxcurArray530 [100];

  double mincur524;
  double mincur525;
  double mincur526;
  double mincur527;
  double mincur528;
  double mincur529;
  double mincur530;
  outputTree524 -> SetBranchAddress ("MIN_PRDCUR" , &mincur524);
  outputTree525 -> SetBranchAddress ("MIN_PRDCUR" , &mincur525);
  outputTree526 -> SetBranchAddress ("MIN_PRDCUR" , &mincur526);
  outputTree527 -> SetBranchAddress ("MIN_PRDCUR" , &mincur527);
  outputTree528 -> SetBranchAddress ("MIN_PRDCUR" , &mincur528);
  outputTree529 -> SetBranchAddress ("MIN_PRDCUR" , &mincur529);
  outputTree530 -> SetBranchAddress ("MIN_PRDCUR" , &mincur530);
  double mincurArray524 [100];
  double mincurArray525 [100];
  double mincurArray526 [100];
  double mincurArray527 [100];
  double mincurArray528 [100];
  double mincurArray529 [100];
  double mincurArray530 [100];

  double ErrcurArray524 [100];
  double ErrcurArray525 [100];
  double ErrcurArray526 [100];
  double ErrcurArray527 [100];
  double ErrcurArray528 [100];
  double ErrcurArray529 [100];
  double ErrcurArray530 [100];

  double Baseline524;
  double Baseline525;
  double Baseline526;
  double Baseline527;
  double Baseline528;
  double Baseline529;
  double Baseline530;
  outputTree524 -> SetBranchAddress ("Baseline" , &Baseline524);
  outputTree525 -> SetBranchAddress ("Baseline" , &Baseline525);
  outputTree526 -> SetBranchAddress ("Baseline" , &Baseline526);
  outputTree527 -> SetBranchAddress ("Baseline" , &Baseline527);
  outputTree528 -> SetBranchAddress ("Baseline" , &Baseline528);
  outputTree529 -> SetBranchAddress ("Baseline" , &Baseline529);
  outputTree530 -> SetBranchAddress ("Baseline" , &Baseline530);
  double BaselineArray524 [100];
  double BaselineArray525 [100];
  double BaselineArray526 [100];
  double BaselineArray527 [100];
  double BaselineArray528 [100];
  double BaselineArray529 [100];
  double BaselineArray530 [100];

  double BaselineErr524;
  double BaselineErr525;
  double BaselineErr526;
  double BaselineErr527;
  double BaselineErr528;
  double BaselineErr529;
  double BaselineErr530;
  outputTree524 -> SetBranchAddress ("BaselineErr" , &BaselineErr524);
  outputTree525 -> SetBranchAddress ("BaselineErr" , &BaselineErr525);
  outputTree526 -> SetBranchAddress ("BaselineErr" , &BaselineErr526);
  outputTree527 -> SetBranchAddress ("BaselineErr" , &BaselineErr527);
  outputTree528 -> SetBranchAddress ("BaselineErr" , &BaselineErr528);
  outputTree529 -> SetBranchAddress ("BaselineErr" , &BaselineErr529);
  outputTree530 -> SetBranchAddress ("BaselineErr" , &BaselineErr530);
  double BaselineErrArray524 [100];
  double BaselineErrArray525 [100];
  double BaselineErrArray526 [100];
  double BaselineErrArray527 [100];
  double BaselineErrArray528 [100];
  double BaselineErrArray529 [100];
  double BaselineErrArray530 [100];
  
  double BaselineIrrad524;
  double BaselineIrrad525;
  double BaselineIrrad526;
  double BaselineIrrad527;
  double BaselineIrrad528;
  double BaselineIrrad529;
  double BaselineIrrad530;
  outputTree524 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad524);
  outputTree525 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad525);
  outputTree526 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad526);
  outputTree527 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad527);
  outputTree528 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad528);
  outputTree529 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad529);
  outputTree530 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad530);
  double BaselineIrradArray524 [100];
  double BaselineIrradArray525 [100];
  double BaselineIrradArray526 [100];
  double BaselineIrradArray527 [100];
  double BaselineIrradArray528 [100];
  double BaselineIrradArray529 [100];
  double BaselineIrradArray530 [100];
  
  double BaselineIrradErr524;
  double BaselineIrradErr525;
  double BaselineIrradErr526;
  double BaselineIrradErr527;
  double BaselineIrradErr528;
  double BaselineIrradErr529;
  double BaselineIrradErr530;
  outputTree524 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr524);
  outputTree525 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr525);
  outputTree526 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr526);
  outputTree527 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr527);
  outputTree528 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr528);
  outputTree529 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr529);
  outputTree530 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr530);
  double BaselineIrradErrArray524 [100];
  double BaselineIrradErrArray525 [100];
  double BaselineIrradErrArray526 [100];
  double BaselineIrradErrArray527 [100];
  double BaselineIrradErrArray528 [100];
  double BaselineIrradErrArray529 [100];
  double BaselineIrradErrArray530 [100];

  double BaselineIntegral524;
  double BaselineIntegral525;
  double BaselineIntegral526;
  double BaselineIntegral527;
  double BaselineIntegral528;
  double BaselineIntegral529;
  double BaselineIntegral530;
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
