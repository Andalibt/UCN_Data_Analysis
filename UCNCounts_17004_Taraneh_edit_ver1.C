// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17004.
// UCN COUNTS VS IRRADIATION TIME
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17004_Taraneh_edit_ver1(){

  TFile *fin562 = new TFile ("outputTree_562.root", "READ");
  TFile *fin563 = new TFile ("outputTree_563.root", "READ");
  TFile *fin564 = new TFile ("outputTree_564.root", "READ");
  TFile *fin565 = new TFile ("outputTree_565.root", "READ");
  TFile *fin566 = new TFile ("outputTree_566.root", "READ");
  TFile *fin567 = new TFile ("outputTree_567.root", "READ");
  TFile *fin568 = new TFile ("outputTree_568.root", "READ");
  TFile *fin569 = new TFile ("outputTree_569.root", "READ");
  TFile *fin570 = new TFile ("outputTree_570.root", "READ");
  TFile *fin571 = new TFile ("outputTree_571.root", "READ");
  TFile *fin572 = new TFile ("outputTree_572.root", "READ");
  
  TTree *outputTree562 = (TTree*) fin562 -> Get("cycle_info");
  TTree *outputTree563 = (TTree*) fin563 -> Get("cycle_info");
  TTree *outputTree564 = (TTree*) fin564 -> Get("cycle_info");
  TTree *outputTree565 = (TTree*) fin565 -> Get("cycle_info");
  TTree *outputTree566 = (TTree*) fin566 -> Get("cycle_info");
  TTree *outputTree567 = (TTree*) fin567 -> Get("cycle_info");
  TTree *outputTree568 = (TTree*) fin568 -> Get("cycle_info");
  TTree *outputTree569 = (TTree*) fin569 -> Get("cycle_info");
  TTree *outputTree570 = (TTree*) fin570 -> Get("cycle_info");
  TTree *outputTree571 = (TTree*) fin571 -> Get("cycle_info");
  TTree *outputTree572 = (TTree*) fin572 -> Get("cycle_info");

  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double irradStartTimes562;
  double irradStartTimes563;
  double irradStartTimes564;
  double irradStartTimes565;
  double irradStartTimes566;
  double irradStartTimes567;
  double irradStartTimes568;
  double irradStartTimes569;
  double irradStartTimes570;
  double irradStartTimes571;
  double irradStartTimes572;

  outputTree562 -> SetBranchAddress("irradStartTimes" , &irradStartTimes562);
  outputTree563 -> SetBranchAddress("irradStartTimes" , &irradStartTimes563);
  outputTree564 -> SetBranchAddress("irradStartTimes" , &irradStartTimes564);
  outputTree565 -> SetBranchAddress("irradStartTimes" , &irradStartTimes565);
  outputTree566 -> SetBranchAddress("irradStartTimes" , &irradStartTimes566);
  outputTree567 -> SetBranchAddress("irradStartTimes" , &irradStartTimes567);
  outputTree568 -> SetBranchAddress("irradStartTimes" , &irradStartTimes568);
  outputTree569 -> SetBranchAddress("irradStartTimes" , &irradStartTimes569);
  outputTree570 -> SetBranchAddress("irradStartTimes" , &irradStartTimes570);
  outputTree571 -> SetBranchAddress("irradStartTimes" , &irradStartTimes571);
  outputTree572 -> SetBranchAddress("irradStartTimes" , &irradStartTimes572);

  double cycleStartTimes562;
  double cycleStartTimes563;
  double cycleStartTimes564;
  double cycleStartTimes565;
  double cycleStartTimes566;
  double cycleStartTimes567;
  double cycleStartTimes568;
  double cycleStartTimes569;
  double cycleStartTimes570;
  double cycleStartTimes571;
  double cycleStartTimes572;

  outputTree562 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes562);
  outputTree563 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes563);
  outputTree564 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes564);
  outputTree565 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes565);
  outputTree566 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes566);
  outputTree567 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes567);
  outputTree568 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes568);
  outputTree569 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes569);
  outputTree570 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes570);
  outputTree571 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes571);
  outputTree572 -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes572);


  
  double cycleDelayTime562;
  double cycleDelayTime563;
  double cycleDelayTime564;
  double cycleDelayTime565;
  double cycleDelayTime566;
  double cycleDelayTime567;
  double cycleDelayTime568;
  double cycleDelayTime569;
  double cycleDelayTime570;
  double cycleDelayTime571;
  double cycleDelayTime572;
  outputTree562 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime562);
  outputTree563 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime563);
  outputTree564 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime564);
  outputTree565 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime565);
  outputTree566 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime566);
  outputTree567 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime567);
  outputTree568 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime568);
  outputTree569 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime569);
  outputTree570 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime570);
  outputTree571 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime571);
  outputTree572 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime572);
  double delaytimeArray562[100];
  double delaytimeArray563[100];
  double delaytimeArray564[100];
  double delaytimeArray565[100];
  double delaytimeArray566[100];
  double delaytimeArray567[100];
  double delaytimeArray568[100];
  double delaytimeArray569[100];
  double delaytimeArray570[100];
  double delaytimeArray571[100];
  double delaytimeArray572[100];

  int cycleNumber562;
  int cycleNumber563;
  int cycleNumber564;
  int cycleNumber565;
  int cycleNumber566;
  int cycleNumber567;
  int cycleNumber568;
  int cycleNumber569;
  int cycleNumber570;
  int cycleNumber571;
  int cycleNumber572;
  outputTree562 -> SetBranchAddress("cycleNumber", &cycleNumber562);
  outputTree563 -> SetBranchAddress("cycleNumber", &cycleNumber563);
  outputTree564 -> SetBranchAddress("cycleNumber", &cycleNumber564);
  outputTree565 -> SetBranchAddress("cycleNumber", &cycleNumber565);
  outputTree566 -> SetBranchAddress("cycleNumber", &cycleNumber566);
  outputTree567 -> SetBranchAddress("cycleNumber", &cycleNumber567);
  outputTree568 -> SetBranchAddress("cycleNumber", &cycleNumber568);
  outputTree569 -> SetBranchAddress("cycleNumber", &cycleNumber569);
  outputTree570 -> SetBranchAddress("cycleNumber", &cycleNumber570);
  outputTree571 -> SetBranchAddress("cycleNumber", &cycleNumber571);
  outputTree572 -> SetBranchAddress("cycleNumber", &cycleNumber572);
  double cycleNumberArray562 [100];
  double cycleNumberArray563 [100];
  double cycleNumberArray564 [100];
  double cycleNumberArray565 [100];
  double cycleNumberArray566 [100];
  double cycleNumberArray567 [100];
  double cycleNumberArray568 [100];
  double cycleNumberArray569 [100];
  double cycleNumberArray570 [100];
  double cycleNumberArray571 [100];
  double cycleNumberArray572 [100];  
  
  double UCNIntegral562;
  double UCNIntegral563;
  double UCNIntegral564;
  double UCNIntegral565;
  double UCNIntegral566;
  double UCNIntegral567;
  double UCNIntegral568;
  double UCNIntegral569;
  double UCNIntegral570;
  double UCNIntegral571;
  double UCNIntegral572;
  outputTree562 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral562);
  outputTree563 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral563);
  outputTree564 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral564);
  outputTree565 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral565);
  outputTree566 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral566);
  outputTree567 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral567);
  outputTree568 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral568);
  outputTree569 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral569);
  outputTree570 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral570);
  outputTree571 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral571);
  outputTree572 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral572);
  double UCNIntegralArray562 [100];
  double UCNIntegralArray563 [100];
  double UCNIntegralArray564 [100];
  double UCNIntegralArray565 [100];
  double UCNIntegralArray566 [100];
  double UCNIntegralArray567 [100];
  double UCNIntegralArray568 [100];
  double UCNIntegralArray569 [100];
  double UCNIntegralArray570 [100];
  double UCNIntegralArray571 [100];
  double UCNIntegralArray572 [100];

  double UCNIntegralErr562;
  double UCNIntegralErr563;
  double UCNIntegralErr564;
  double UCNIntegralErr565;
  double UCNIntegralErr566;
  double UCNIntegralErr567;
  double UCNIntegralErr568;
  double UCNIntegralErr569;
  double UCNIntegralErr570;
  double UCNIntegralErr571;
  double UCNIntegralErr572;
  outputTree562 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr562);
  outputTree563 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr563);
  outputTree564 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr564);
  outputTree565 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr565);
  outputTree566 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr566);
  outputTree567 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr567);
  outputTree568 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr568);
  outputTree569 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr569);
  outputTree570 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr570);
  outputTree571 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr571);
  outputTree572 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr572);
  double UCNIntegralErrArray562 [100];
  double UCNIntegralErrArray563 [100];
  double UCNIntegralErrArray564 [100];
  double UCNIntegralErrArray565 [100];
  double UCNIntegralErrArray566 [100];
  double UCNIntegralErrArray567 [100];
  double UCNIntegralErrArray568 [100];
  double UCNIntegralErrArray569 [100];
  double UCNIntegralErrArray570 [100];
  double UCNIntegralErrArray571 [100];
  double UCNIntegralErrArray572 [100];

  double HistIntegral562;
  double HistIntegral563;
  double HistIntegral564;
  double HistIntegral565;
  double HistIntegral566;
  double HistIntegral567;
  double HistIntegral568;
  double HistIntegral569;
  double HistIntegral570;
  double HistIntegral571;
  double HistIntegral572;
  outputTree562 -> SetBranchAddress ("HistIntegral" , &HistIntegral562);
  outputTree563 -> SetBranchAddress ("HistIntegral" , &HistIntegral563);
  outputTree564 -> SetBranchAddress ("HistIntegral" , &HistIntegral564);
  outputTree565 -> SetBranchAddress ("HistIntegral" , &HistIntegral565);
  outputTree566 -> SetBranchAddress ("HistIntegral" , &HistIntegral566);
  outputTree567 -> SetBranchAddress ("HistIntegral" , &HistIntegral567);
  outputTree568 -> SetBranchAddress ("HistIntegral" , &HistIntegral568);
  outputTree569 -> SetBranchAddress ("HistIntegral" , &HistIntegral569);
  outputTree570 -> SetBranchAddress ("HistIntegral" , &HistIntegral570);
  outputTree571 -> SetBranchAddress ("HistIntegral" , &HistIntegral571);
  outputTree572 -> SetBranchAddress ("HistIntegral" , &HistIntegral572); 
  double HistIntegralArray562 [100];
  double HistIntegralArray563 [100];
  double HistIntegralArray564 [100];
  double HistIntegralArray565 [100];
  double HistIntegralArray566 [100];
  double HistIntegralArray567 [100];
  double HistIntegralArray568 [100];
  double HistIntegralArray569 [100];
  double HistIntegralArray570 [100];
  double HistIntegralArray571 [100];
  double HistIntegralArray572 [100];
  double HistIntegralErrArray562[100];
  double HistIntegralErrArray563[100];
  double HistIntegralErrArray564[100];
  double HistIntegralErrArray565[100];
  double HistIntegralErrArray566[100];
  double HistIntegralErrArray567[100];
  double HistIntegralErrArray568[100];
  double HistIntegralErrArray569[100];
  double HistIntegralErrArray570[100];
  double HistIntegralErrArray571[100];
  double HistIntegralErrArray572[100];

  double avets12Irrad562;
  double avets12Irrad563;
  double avets12Irrad564;
  double avets12Irrad565;
  double avets12Irrad566;
  double avets12Irrad567;
  double avets12Irrad568;
  double avets12Irrad569;
  double avets12Irrad570;
  double avets12Irrad571;
  double avets12Irrad572;
  outputTree562 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad562);
  outputTree563 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad563);
  outputTree564 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad564);
  outputTree565 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad565);
  outputTree566 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad566);
  outputTree567 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad567);
  outputTree568 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad568);
  outputTree569 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad569);
  outputTree570 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad570);
  outputTree571 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad571);
  outputTree572 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad572);
  double avets12IrradArray562 [100];
  double avets12IrradArray563 [100];
  double avets12IrradArray564 [100];
  double avets12IrradArray565 [100];
  double avets12IrradArray566 [100];
  double avets12IrradArray567 [100];
  double avets12IrradArray568 [100];
  double avets12IrradArray569 [100];
  double avets12IrradArray570 [100];
  double avets12IrradArray571 [100];
  double avets12IrradArray572 [100];
  
  double avets12ValveOpen562;
  double avets12ValveOpen563;
  double avets12ValveOpen564;
  double avets12ValveOpen565;
  double avets12ValveOpen566;
  double avets12ValveOpen567;
  double avets12ValveOpen568;
  double avets12ValveOpen569;
  double avets12ValveOpen570;
  double avets12ValveOpen571;
  double avets12ValveOpen572;
  outputTree562 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen562);
  outputTree563 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen563);
  outputTree564 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen564);
  outputTree565 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen565);
  outputTree566 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen566);
  outputTree567 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen567);
  outputTree568 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen568);
  outputTree569 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen569);
  outputTree570 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen570);
  outputTree571 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen571);
  outputTree572 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen572);
  double avets12ValveOpenArray562 [100];
  double avets12ValveOpenArray563 [100];
  double avets12ValveOpenArray564 [100];
  double avets12ValveOpenArray565 [100];
  double avets12ValveOpenArray566 [100];
  double avets12ValveOpenArray567 [100];
  double avets12ValveOpenArray568 [100];
  double avets12ValveOpenArray569 [100];
  double avets12ValveOpenArray570 [100];
  double avets12ValveOpenArray571 [100];
  double avets12ValveOpenArray572 [100];
  
  double maxts12Irrad562;
  double maxts12Irrad563;
  double maxts12Irrad564;
  double maxts12Irrad565;
  double maxts12Irrad566;
  double maxts12Irrad567;
  double maxts12Irrad568;
  double maxts12Irrad569;
  double maxts12Irrad570;
  double maxts12Irrad571;
  double maxts12Irrad572;
  outputTree562 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad562);
  outputTree563 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad563);
  outputTree564 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad564);
  outputTree565 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad565);
  outputTree566 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad566);
  outputTree567 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad567);
  outputTree568 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad568);
  outputTree569 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad569);
  outputTree570 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad570);
  outputTree571 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad571);
  outputTree572 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad572);
  double maxts12IrradArray562 [100];
  double maxts12IrradArray563 [100];
  double maxts12IrradArray564 [100];
  double maxts12IrradArray565 [100];
  double maxts12IrradArray566 [100];
  double maxts12IrradArray567 [100];
  double maxts12IrradArray568 [100];
  double maxts12IrradArray569 [100];
  double maxts12IrradArray570 [100];
  double maxts12IrradArray571 [100];
  double maxts12IrradArray572 [100];
  
  double maxts12ValveOpen562;
  double maxts12ValveOpen563;
  double maxts12ValveOpen564;
  double maxts12ValveOpen565;
  double maxts12ValveOpen566;
  double maxts12ValveOpen567;
  double maxts12ValveOpen568;
  double maxts12ValveOpen569;
  double maxts12ValveOpen570;
  double maxts12ValveOpen571;
  double maxts12ValveOpen572;
  outputTree562 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen562);
  outputTree563 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen563);
  outputTree564 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen564);
  outputTree565 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen565);
  outputTree566 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen566);
  outputTree567 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen567);
  outputTree568 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen568);
  outputTree569 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen569);
  outputTree570 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen570);
  outputTree571 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen571);
  outputTree572 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen572);
  double maxts12ValveOpenArray562 [100];
  double maxts12ValveOpenArray563 [100];
  double maxts12ValveOpenArray564 [100];
  double maxts12ValveOpenArray565 [100];
  double maxts12ValveOpenArray566 [100];
  double maxts12ValveOpenArray567 [100];
  double maxts12ValveOpenArray568 [100];
  double maxts12ValveOpenArray569 [100];
  double maxts12ValveOpenArray570 [100];
  double maxts12ValveOpenArray571 [100];
  double maxts12ValveOpenArray572 [100];

  double mints12Irrad562;
  double mints12Irrad563;
  double mints12Irrad564;
  double mints12Irrad565;
  double mints12Irrad566;
  double mints12Irrad567;
  double mints12Irrad568;
  double mints12Irrad569;
  double mints12Irrad570;
  double mints12Irrad571;
  double mints12Irrad572;
  outputTree562 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad562);
  outputTree563 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad563);
  outputTree564 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad564);
  outputTree565 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad565);
  outputTree566 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad566);
  outputTree567 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad567);
  outputTree568 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad568);
  outputTree569 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad569);
  outputTree570 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad570);
  outputTree571 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad571);
  outputTree572 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad572);
  double mints12IrradArray562 [100];
  double mints12IrradArray563 [100];
  double mints12IrradArray564 [100];
  double mints12IrradArray565 [100];
  double mints12IrradArray566 [100];
  double mints12IrradArray567 [100];
  double mints12IrradArray568 [100];
  double mints12IrradArray569 [100];
  double mints12IrradArray570 [100];
  double mints12IrradArray571 [100];
  double mints12IrradArray572 [100];
  
  double mints12ValveOpen562;
  double mints12ValveOpen563;
  double mints12ValveOpen564;
  double mints12ValveOpen565;
  double mints12ValveOpen566;
  double mints12ValveOpen567;
  double mints12ValveOpen568;
  double mints12ValveOpen569;
  double mints12ValveOpen570;
  double mints12ValveOpen571;
  double mints12ValveOpen572;
  outputTree562 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen562);
  outputTree563 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen563);
  outputTree564 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen564);
  outputTree565 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen565);
  outputTree566 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen566);
  outputTree567 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen567);
  outputTree568 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen568);
  outputTree569 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen569);
  outputTree570 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen570);
  outputTree571 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen571);
  outputTree572 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen572);
  double mints12ValveOpenArray562 [100];
  double mints12ValveOpenArray563 [100];
  double mints12ValveOpenArray564 [100];
  double mints12ValveOpenArray565 [100];
  double mints12ValveOpenArray566 [100];
  double mints12ValveOpenArray567 [100];
  double mints12ValveOpenArray568 [100];
  double mints12ValveOpenArray569 [100];
  double mints12ValveOpenArray570 [100];
  double mints12ValveOpenArray571 [100];
  double mints12ValveOpenArray572 [100];
    

  double ts12IrradErr562 [100];
  double ts12IrradErr563 [100];
  double ts12IrradErr564 [100];
  double ts12IrradErr565 [100];
  double ts12IrradErr566 [100];
  double ts12IrradErr567 [100];
  double ts12IrradErr568 [100];
  double ts12IrradErr569 [100];
  double ts12IrradErr570 [100];
  double ts12IrradErr571 [100];
  double ts12IrradErr572 [100];
  double ts12ValveOpenErr562 [100];
  double ts12ValveOpenErr563 [100];
  double ts12ValveOpenErr564 [100];
  double ts12ValveOpenErr565 [100];
  double ts12ValveOpenErr566 [100];
  double ts12ValveOpenErr567 [100];
  double ts12ValveOpenErr568 [100];
  double ts12ValveOpenErr569 [100];
  double ts12ValveOpenErr570 [100];
  double ts12ValveOpenErr571 [100];
  double ts12ValveOpenErr572 [100];

  double avecur562;
  double avecur563;
  double avecur564;
  double avecur565;
  double avecur566;
  double avecur567;
  double avecur568;
  double avecur569;
  double avecur570;
  double avecur571;
  double avecur572;
  outputTree562 -> SetBranchAddress ("AVE_PRDCUR" , &avecur562);
  outputTree563 -> SetBranchAddress ("AVE_PRDCUR" , &avecur563);
  outputTree564 -> SetBranchAddress ("AVE_PRDCUR" , &avecur564);
  outputTree565 -> SetBranchAddress ("AVE_PRDCUR" , &avecur565);
  outputTree566 -> SetBranchAddress ("AVE_PRDCUR" , &avecur566);
  outputTree567 -> SetBranchAddress ("AVE_PRDCUR" , &avecur567);
  outputTree568 -> SetBranchAddress ("AVE_PRDCUR" , &avecur568);
  outputTree569 -> SetBranchAddress ("AVE_PRDCUR" , &avecur569);
  outputTree570 -> SetBranchAddress ("AVE_PRDCUR" , &avecur570);
  outputTree571 -> SetBranchAddress ("AVE_PRDCUR" , &avecur571);
  outputTree572 -> SetBranchAddress ("AVE_PRDCUR" , &avecur572);
  double avecurArray562 [100];
  double avecurArray563 [100];
  double avecurArray564 [100];
  double avecurArray565 [100];
  double avecurArray566 [100];
  double avecurArray567 [100];
  double avecurArray568 [100];
  double avecurArray569 [100];
  double avecurArray570 [100];
  double avecurArray571 [100];
  double avecurArray572 [100];

  double maxcur562;
  double maxcur563;
  double maxcur564;
  double maxcur565;
  double maxcur566;
  double maxcur567;
  double maxcur568;
  double maxcur569;
  double maxcur570;
  double maxcur571;
  double maxcur572;
  outputTree562 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur562);
  outputTree563 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur563);
  outputTree564 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur564);
  outputTree565 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur565);
  outputTree566 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur566);
  outputTree567 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur567);
  outputTree568 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur568);
  outputTree569 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur569);
  outputTree570 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur570);
  outputTree571 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur571);
  outputTree572 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur572);
  double maxcurArray562 [100];
  double maxcurArray563 [100];
  double maxcurArray564 [100];
  double maxcurArray565 [100];
  double maxcurArray566 [100];
  double maxcurArray567 [100];
  double maxcurArray568 [100];
  double maxcurArray569 [100];
  double maxcurArray570 [100];
  double maxcurArray571 [100];
  double maxcurArray572 [100];

  double mincur562;
  double mincur563;
  double mincur564;
  double mincur565;
  double mincur566;
  double mincur567;
  double mincur568;
  double mincur569;
  double mincur570;
  double mincur571;
  double mincur572;
  outputTree562 -> SetBranchAddress ("MIN_PRDCUR" , &mincur562);
  outputTree563 -> SetBranchAddress ("MIN_PRDCUR" , &mincur563);
  outputTree564 -> SetBranchAddress ("MIN_PRDCUR" , &mincur564);
  outputTree565 -> SetBranchAddress ("MIN_PRDCUR" , &mincur565);
  outputTree566 -> SetBranchAddress ("MIN_PRDCUR" , &mincur566);
  outputTree567 -> SetBranchAddress ("MIN_PRDCUR" , &mincur567);
  outputTree568 -> SetBranchAddress ("MIN_PRDCUR" , &mincur568);
  outputTree569 -> SetBranchAddress ("MIN_PRDCUR" , &mincur569);
  outputTree570 -> SetBranchAddress ("MIN_PRDCUR" , &mincur570);
  outputTree571 -> SetBranchAddress ("MIN_PRDCUR" , &mincur571);
  outputTree572 -> SetBranchAddress ("MIN_PRDCUR" , &mincur572);
  double mincurArray562 [100];
  double mincurArray563 [100];
  double mincurArray564 [100];
  double mincurArray565 [100];
  double mincurArray566 [100];
  double mincurArray567 [100];
  double mincurArray568 [100];
  double mincurArray569 [100];
  double mincurArray570 [100];
  double mincurArray571 [100];
  double mincurArray572 [100];

  double ErrcurArray562 [100];
  double ErrcurArray563 [100];
  double ErrcurArray564 [100];
  double ErrcurArray565 [100];
  double ErrcurArray566 [100];
  double ErrcurArray567 [100];
  double ErrcurArray568 [100];
  double ErrcurArray569 [100];
  double ErrcurArray570 [100];
  double ErrcurArray571 [100];
  double ErrcurArray572 [100];

  double Baseline562;
  double Baseline563;
  double Baseline564;
  double Baseline565;
  double Baseline566;
  double Baseline567;
  double Baseline568;
  double Baseline569;
  double Baseline570;
  double Baseline571;
  double Baseline572;
  outputTree562 -> SetBranchAddress ("Baseline" , &Baseline562);
  outputTree563 -> SetBranchAddress ("Baseline" , &Baseline563);
  outputTree564 -> SetBranchAddress ("Baseline" , &Baseline564);
  outputTree565 -> SetBranchAddress ("Baseline" , &Baseline565);
  outputTree566 -> SetBranchAddress ("Baseline" , &Baseline566);
  outputTree567 -> SetBranchAddress ("Baseline" , &Baseline567);
  outputTree568 -> SetBranchAddress ("Baseline" , &Baseline568);
  outputTree569 -> SetBranchAddress ("Baseline" , &Baseline569);
  outputTree570 -> SetBranchAddress ("Baseline" , &Baseline570);
  outputTree571 -> SetBranchAddress ("Baseline" , &Baseline571);
  outputTree572 -> SetBranchAddress ("Baseline" , &Baseline572);
  double BaselineArray562 [100];
  double BaselineArray563 [100];
  double BaselineArray564 [100];
  double BaselineArray565 [100];
  double BaselineArray566 [100];
  double BaselineArray567 [100];
  double BaselineArray568 [100];
  double BaselineArray569 [100];
  double BaselineArray570 [100];
  double BaselineArray571 [100];
  double BaselineArray572 [100];
  
  double BaselineErr562;
  double BaselineErr563;
  double BaselineErr564;
  double BaselineErr565;
  double BaselineErr566;
  double BaselineErr567;
  double BaselineErr568;
  double BaselineErr569;
  double BaselineErr570;
  double BaselineErr571;
  double BaselineErr572;
  outputTree562 -> SetBranchAddress ("BaselineErr" , &BaselineErr562);
  outputTree563 -> SetBranchAddress ("BaselineErr" , &BaselineErr563);
  outputTree564 -> SetBranchAddress ("BaselineErr" , &BaselineErr564);
  outputTree565 -> SetBranchAddress ("BaselineErr" , &BaselineErr565);
  outputTree566 -> SetBranchAddress ("BaselineErr" , &BaselineErr566);
  outputTree567 -> SetBranchAddress ("BaselineErr" , &BaselineErr567);
  outputTree568 -> SetBranchAddress ("BaselineErr" , &BaselineErr568);
  outputTree569 -> SetBranchAddress ("BaselineErr" , &BaselineErr569);
  outputTree570 -> SetBranchAddress ("BaselineErr" , &BaselineErr570);
  outputTree571 -> SetBranchAddress ("BaselineErr" , &BaselineErr571);
  outputTree572 -> SetBranchAddress ("BaselineErr" , &BaselineErr572);
  
  double BaselineErrArray562 [100];
  double BaselineErrArray563 [100];
  double BaselineErrArray564 [100];
  double BaselineErrArray565 [100];
  double BaselineErrArray566 [100];
  double BaselineErrArray567 [100];
  double BaselineErrArray568 [100];
  double BaselineErrArray569 [100];
  double BaselineErrArray570 [100];
  double BaselineErrArray571 [100];
  double BaselineErrArray572 [100];
  
  double BaselineIrrad562;
  double BaselineIrrad563;
  double BaselineIrrad564;
  double BaselineIrrad565;
  double BaselineIrrad566;
  double BaselineIrrad567;
  double BaselineIrrad568;
  double BaselineIrrad569;
  double BaselineIrrad570;
  double BaselineIrrad571;
  double BaselineIrrad572;
  outputTree562 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad562);
  outputTree563 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad563);
  outputTree564 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad564);
  outputTree565 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad565);
  outputTree566 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad566);
  outputTree567 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad567);
  outputTree568 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad568);
  outputTree569 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad569);
  outputTree570 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad570);
  outputTree571 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad571);
  outputTree572 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad572);
  double BaselineIrradArray562 [100];
  double BaselineIrradArray563 [100];
  double BaselineIrradArray564 [100];
  double BaselineIrradArray565 [100];
  double BaselineIrradArray566 [100];
  double BaselineIrradArray567 [100];
  double BaselineIrradArray568 [100];
  double BaselineIrradArray569 [100];
  double BaselineIrradArray570 [100];
  double BaselineIrradArray571 [100];
  double BaselineIrradArray572 [100];
  
  double BaselineIrradErr562;
  double BaselineIrradErr563;
  double BaselineIrradErr564;
  double BaselineIrradErr565;
  double BaselineIrradErr566;
  double BaselineIrradErr567;
  double BaselineIrradErr568;
  double BaselineIrradErr569;
  double BaselineIrradErr570;
  double BaselineIrradErr571;
  double BaselineIrradErr572;
  outputTree562 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr562);
  outputTree563 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr563);
  outputTree564 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr564);
  outputTree565 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr565);
  outputTree566 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr566);
  outputTree567 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr567);
  outputTree568 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr568);
  outputTree569 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr569);
  outputTree570 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr570);
  outputTree571 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr571);
  outputTree572 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr572);
  double BaselineIrradErrArray562 [100];
  double BaselineIrradErrArray563 [100];
  double BaselineIrradErrArray564 [100];
  double BaselineIrradErrArray565 [100];
  double BaselineIrradErrArray566 [100];
  double BaselineIrradErrArray567 [100];
  double BaselineIrradErrArray568 [100];
  double BaselineIrradErrArray569 [100];
  double BaselineIrradErrArray570 [100];
  double BaselineIrradErrArray571 [100];
  double BaselineIrradErrArray572 [100];

  double BaselineIntegral562;
  double BaselineIntegral563;
  double BaselineIntegral564;
  double BaselineIntegral565;
  double BaselineIntegral566;
  double BaselineIntegral567;
  double BaselineIntegral568;
  double BaselineIntegral569;
  double BaselineIntegral570;
  double BaselineIntegral571;
  double BaselineIntegral572;
  outputTree562 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral562);
  outputTree563 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral563);
  outputTree564 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral564);
  outputTree565 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral565);
  outputTree566 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral566);
  outputTree567 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral567);
  outputTree568 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral568);
  outputTree569 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral569);
  outputTree570 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral570);
  outputTree571 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral571);
  outputTree572 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral572);
  double BaselineIntegralArray562[100];
  double BaselineIntegralArray563[100];
  double BaselineIntegralArray564[100];
  double BaselineIntegralArray565[100];
  double BaselineIntegralArray566[100];
  double BaselineIntegralArray567[100];
  double BaselineIntegralArray568[100];
  double BaselineIntegralArray569[100];
  double BaselineIntegralArray570[100];
  double BaselineIntegralArray571[100];
  double BaselineIntegralArray572[100]; 

  double BaselineIrradIntegral562;
  double BaselineIrradIntegral563;
  double BaselineIrradIntegral564;
  double BaselineIrradIntegral565;
  double BaselineIrradIntegral566;
  double BaselineIrradIntegral567;
  double BaselineIrradIntegral568;
  double BaselineIrradIntegral569;
  double BaselineIrradIntegral570;
  double BaselineIrradIntegral571;
  double BaselineIrradIntegral572;
  outputTree562 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral562);
  outputTree563 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral563);
  outputTree564 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral564);
  outputTree565 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral565);
  outputTree566 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral566);
  outputTree567 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral567);
  outputTree568 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral568);
  outputTree569 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral569);
  outputTree570 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral570);
  outputTree571 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral571);
  outputTree572 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral572);
  double BaselineIrradIntegralArray562[100];
  double BaselineIrradIntegralArray563[100];
  double BaselineIrradIntegralArray564[100];
  double BaselineIrradIntegralArray565[100];
  double BaselineIrradIntegralArray566[100];
  double BaselineIrradIntegralArray567[100];
  double BaselineIrradIntegralArray568[100];
  double BaselineIrradIntegralArray569[100];
  double BaselineIrradIntegralArray570[100];
  double BaselineIrradIntegralArray571[100];
  double BaselineIrradIntegralArray572[100];

  double UCNIntegralManualArray562 [100];
  double UCNIntegralManualArray563 [100];
  double UCNIntegralManualArray564 [100];
  double UCNIntegralManualArray565 [100];
  double UCNIntegralManualArray566 [100];
  double UCNIntegralManualArray567 [100];
  double UCNIntegralManualArray568 [100];
  double UCNIntegralManualArray569 [100];
  double UCNIntegralManualArray570 [100];
  double UCNIntegralManualArray571 [100];
  double UCNIntegralManualArray572 [100];
  double UCNIntegralManualErrArray562[100];
  double UCNIntegralManualErrArray563[100];
  double UCNIntegralManualErrArray564[100];
  double UCNIntegralManualErrArray565[100];
  double UCNIntegralManualErrArray566[100];
  double UCNIntegralManualErrArray567[100];
  double UCNIntegralManualErrArray568[100];
  double UCNIntegralManualErrArray569[100];
  double UCNIntegralManualErrArray570[100];
  double UCNIntegralManualErrArray571[100];
  double UCNIntegralManualErrArray572[100];

  int counts_562 = 0;
  int counts_563 = 0;
  int counts_564 = 0;
  int counts_565 = 0;
  int counts_566 = 0;
  int counts_567 = 0;
  int counts_568 = 0;
  int counts_569 = 0;
  int counts_570 = 0;
  int counts_571 = 0;
  int counts_572 = 0;

  double UCNIntegralAll[100];
  double UCNIntegralErrAll[100];
  double HistIntegralAll[100];
  double HistIntegralErrAll[100];
  double UCNIntegralManualAll[100];
  double UCNIntegralManualErrAll[100];
  double irradArray[100];

  // *****
  // 562
  // *****
  
  
  ULong64_t events562;
  events562 = (Double_t) outputTree562 -> GetEntries();

  for (ULong64_t j = 0 ; j < events562 ; j++){
    outputTree562 -> GetEvent(j);
    UCNIntegralArray562[counts_562] = UCNIntegral562;
    UCNIntegralErrArray562[counts_562] = UCNIntegralErr562;
    HistIntegralArray562[counts_562] = HistIntegral562;
    HistIntegralErrArray562[counts_562] = sqrt (HistIntegral562);
    avets12IrradArray562[counts_562] = avets12Irrad562;
    avets12ValveOpenArray562[counts_562] = avets12ValveOpen562;
    maxts12IrradArray562[counts_562] = maxts12Irrad562;
    maxts12ValveOpenArray562[counts_562] = maxts12ValveOpen562;
    mints12IrradArray562[counts_562] = mints12Irrad562; 
    mints12ValveOpenArray562[counts_562] = mints12ValveOpen562;
    ts12IrradErr562[counts_562] = (maxts12Irrad562 - mints12Irrad562)/2;
    ts12ValveOpenErr562[counts_562] = (maxts12ValveOpen562 - mints12ValveOpen562)/2;
    avecurArray562[counts_562] = avecur562;
    maxcurArray562[counts_562] = maxcur562;
    mincurArray562[counts_562] = mincur562;
    ErrcurArray562[counts_562] = (maxcur562 - mincur562)/2;
    delaytimeArray562[counts_562] = cycleDelayTime562;
    cycleNumberArray562[counts_562] = cycleNumber562;
    BaselineArray562[counts_562] = Baseline562;
    BaselineIrradArray562[counts_562] = BaselineIrrad562;
    BaselineIrradErrArray562[counts_562] = BaselineIrradErr562;
    BaselineIntegralArray562[counts_562] = BaselineIntegral562;
    BaselineIrradIntegralArray562[counts_562] = BaselineIrradIntegral562;
    UCNIntegralManualArray562[counts_562] = HistIntegral562 - BaselineIntegral562;
    // cout << UCNIntegralManualArray562[counts_562] << endl;
    UCNIntegralManualErrArray562[counts_562] = sqrt(HistIntegral562 - BaselineIntegral562);
    cout << " The irradiation time for run 562 for cycle "<< counts_562 << " is "<< cycleStartTimes562 - irradStartTimes562 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562] = UCNIntegral562;
    UCNIntegralErrAll[counts_562] = UCNIntegralErr562;
    HistIntegralAll[counts_562] = HistIntegral562;
    HistIntegralErrAll[counts_562] = sqrt (HistIntegral562);
    UCNIntegralManualAll[counts_562] = HistIntegral562 - BaselineIntegral562;
    UCNIntegralManualErrAll[counts_562] = sqrt(HistIntegral562 - BaselineIntegral562);
    irradArray[counts_562] = cycleStartTimes562 - irradStartTimes562;
    counts_562++;
  }


  // *****
  // 563
  // *****
  
  
  ULong64_t events563;
  events563 = (Double_t) outputTree563 -> GetEntries();

  for (ULong64_t j = 0 ; j < events563 ; j++){
    outputTree563 -> GetEvent(j);
    UCNIntegralArray563[counts_563] = UCNIntegral563;
    UCNIntegralErrArray563[counts_563] = UCNIntegralErr563;
    HistIntegralArray563[counts_563] = HistIntegral563;
    HistIntegralErrArray563[counts_563] = sqrt (HistIntegral563);
    avets12IrradArray563[counts_563] = avets12Irrad563;
    avets12ValveOpenArray563[counts_563] = avets12ValveOpen563;
    maxts12IrradArray563[counts_563] = maxts12Irrad563;
    maxts12ValveOpenArray563[counts_563] = maxts12ValveOpen563;
    mints12IrradArray563[counts_563] = mints12Irrad563; 
    mints12ValveOpenArray563[counts_563] = mints12ValveOpen563;
    ts12IrradErr563[counts_563] = (maxts12Irrad563 - mints12Irrad563)/2;
    ts12ValveOpenErr563[counts_563] = (maxts12ValveOpen563 - mints12ValveOpen563)/2;
    avecurArray563[counts_563] = avecur563;
    maxcurArray563[counts_563] = maxcur563;
    mincurArray563[counts_563] = mincur563;
    ErrcurArray563[counts_563] = (maxcur563 - mincur563)/2;
    delaytimeArray563[counts_563] = cycleDelayTime563;
    cycleNumberArray563[counts_563] = cycleNumber563;
    BaselineArray563[counts_563] = Baseline563;
    BaselineIrradArray563[counts_563] = BaselineIrrad563;
    BaselineIrradErrArray563[counts_563] = BaselineIrradErr563;
    BaselineIntegralArray563[counts_563] = BaselineIntegral563;
    BaselineIrradIntegralArray563[counts_563] = BaselineIrradIntegral563;
    UCNIntegralManualArray563[counts_563] = HistIntegral563 - BaselineIntegral563;
    // cout << UCNIntegralManualArray563[counts_563] << endl;
    UCNIntegralManualErrArray563[counts_563] = sqrt(HistIntegral563 - BaselineIntegral563);
    cout << " The irradiation time for run 563  for cycle "<< counts_563 << " is "<< cycleStartTimes563 - irradStartTimes563 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563] = UCNIntegral563;
    irradArray[counts_562+counts_563]  = cycleStartTimes563 - irradStartTimes563;
    UCNIntegralErrAll[counts_562+counts_563] = UCNIntegralErr563;
    HistIntegralAll[counts_562+counts_563] = HistIntegral563;
    HistIntegralErrAll[counts_562+counts_563] = sqrt (HistIntegral563);
    UCNIntegralManualAll[counts_562+counts_563] = HistIntegral563 - BaselineIntegral563;
    UCNIntegralManualErrAll[counts_562+counts_563] = sqrt(HistIntegral563 - BaselineIntegral563);
    counts_563++;
  }


  // *****
  // 564
  // *****
  
  
  ULong64_t events564;
  events564 = (Double_t) outputTree564 -> GetEntries();

  for (ULong64_t j = 0 ; j < events564 ; j++){
    outputTree564 -> GetEvent(j);
    UCNIntegralArray564[counts_564] = UCNIntegral564;
    UCNIntegralErrArray564[counts_564] = UCNIntegralErr564;
    HistIntegralArray564[counts_564] = HistIntegral564;
    HistIntegralErrArray564[counts_564] = sqrt (HistIntegral564);
    avets12IrradArray564[counts_564] = avets12Irrad564;
    avets12ValveOpenArray564[counts_564] = avets12ValveOpen564;
    maxts12IrradArray564[counts_564] = maxts12Irrad564;
    maxts12ValveOpenArray564[counts_564] = maxts12ValveOpen564;
    mints12IrradArray564[counts_564] = mints12Irrad564; 
    mints12ValveOpenArray564[counts_564] = mints12ValveOpen564;
    ts12IrradErr564[counts_564] = (maxts12Irrad564 - mints12Irrad564)/2;
    ts12ValveOpenErr564[counts_564] = (maxts12ValveOpen564 - mints12ValveOpen564)/2;
    avecurArray564[counts_564] = avecur564;
    maxcurArray564[counts_564] = maxcur564;
    mincurArray564[counts_564] = mincur564;
    ErrcurArray564[counts_564] = (maxcur564 - mincur564)/2;
    delaytimeArray564[counts_564] = cycleDelayTime564;
    cycleNumberArray564[counts_564] = cycleNumber564;
    BaselineArray564[counts_564] = Baseline564;
    BaselineIrradArray564[counts_564] = BaselineIrrad564;
    BaselineIrradErrArray564[counts_564] = BaselineIrradErr564;
    BaselineIntegralArray564[counts_564] = BaselineIntegral564;
    BaselineIrradIntegralArray564[counts_564] = BaselineIrradIntegral564;
    UCNIntegralManualArray564[counts_564] = HistIntegral564 - BaselineIntegral564;
    // cout << UCNIntegralManualArray564[counts_564] << endl;
    UCNIntegralManualErrArray564[counts_564] = sqrt(HistIntegral564 - BaselineIntegral564);
    cout << " The irradiation time for run 564 for cycle " << counts_564 << " is "<< cycleStartTimes564 - irradStartTimes564 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564] = UCNIntegral564;
    irradArray[counts_562+counts_563+counts_564] = cycleStartTimes564 - irradStartTimes564;
    UCNIntegralErrAll[counts_562+counts_563+counts_564] = UCNIntegralErr564;
    HistIntegralAll[counts_562+counts_563+counts_564] = HistIntegral564;
    HistIntegralErrAll[counts_562+counts_563+counts_564] = sqrt (HistIntegral564);
    UCNIntegralManualAll[counts_562+counts_563+counts_564] = HistIntegral564 - BaselineIntegral564;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564] = sqrt(HistIntegral564 - BaselineIntegral564);
    counts_564++;
  }



  // *****
  // 565
  // *****
  
  
  ULong64_t events565;
  events565 = (Double_t) outputTree565 -> GetEntries();

  for (ULong64_t j = 0 ; j < events565 ; j++){
    outputTree565 -> GetEvent(j);
    UCNIntegralArray565[counts_565] = UCNIntegral565;
    UCNIntegralErrArray565[counts_565] = UCNIntegralErr565;
    HistIntegralArray565[counts_565] = HistIntegral565;
    HistIntegralErrArray565[counts_565] = sqrt (HistIntegral565);
    avets12IrradArray565[counts_565] = avets12Irrad565;
    avets12ValveOpenArray565[counts_565] = avets12ValveOpen565;
    maxts12IrradArray565[counts_565] = maxts12Irrad565;
    maxts12ValveOpenArray565[counts_565] = maxts12ValveOpen565;
    mints12IrradArray565[counts_565] = mints12Irrad565; 
    mints12ValveOpenArray565[counts_565] = mints12ValveOpen565;
    ts12IrradErr565[counts_565] = (maxts12Irrad565 - mints12Irrad565)/2;
    ts12ValveOpenErr565[counts_565] = (maxts12ValveOpen565 - mints12ValveOpen565)/2;
    avecurArray565[counts_565] = avecur565;
    maxcurArray565[counts_565] = maxcur565;
    mincurArray565[counts_565] = mincur565;
    ErrcurArray565[counts_565] = (maxcur565 - mincur565)/2;
    delaytimeArray565[counts_565] = cycleDelayTime565;
    cycleNumberArray565[counts_565] = cycleNumber565;
    BaselineArray565[counts_565] = Baseline565;
    BaselineIrradArray565[counts_565] = BaselineIrrad565;
    BaselineIrradErrArray565[counts_565] = BaselineIrradErr565;
    BaselineIntegralArray565[counts_565] = BaselineIntegral565;
    BaselineIrradIntegralArray565[counts_565] = BaselineIrradIntegral565;
    UCNIntegralManualArray565[counts_565] = HistIntegral565 - BaselineIntegral565;
    // cout << UCNIntegralManualArray565[counts_565] << endl;
    UCNIntegralManualErrArray565[counts_565] = sqrt(HistIntegral565 - BaselineIntegral565);
    cout << " The irradiation time for run 565 for cycle "<< counts_565<< " is "<< cycleStartTimes565 - irradStartTimes565 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565] = UCNIntegral565;
    irradArray[counts_562+counts_563+counts_564+counts_565] = cycleStartTimes565 - irradStartTimes565;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565] = UCNIntegralErr565;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565] = HistIntegral565;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565] = sqrt (HistIntegral565);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565] = HistIntegral565 - BaselineIntegral565;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565] = sqrt(HistIntegral565 - BaselineIntegral565);
    counts_565++;
  }


  // *****
  // 566
  // *****
  
  
  ULong64_t events566;
  events566 = (Double_t) outputTree566 -> GetEntries();

  for (ULong64_t j = 0 ; j < events566 ; j++){
    outputTree566 -> GetEvent(j);
    if (j ==1 )
      continue;
    UCNIntegralArray566[counts_566] = UCNIntegral566;
    UCNIntegralErrArray566[counts_566] = UCNIntegralErr566;
    HistIntegralArray566[counts_566] = HistIntegral566;
    HistIntegralErrArray566[counts_566] = sqrt (HistIntegral566);
    avets12IrradArray566[counts_566] = avets12Irrad566;
    avets12ValveOpenArray566[counts_566] = avets12ValveOpen566;
    maxts12IrradArray566[counts_566] = maxts12Irrad566;
    maxts12ValveOpenArray566[counts_566] = maxts12ValveOpen566;
    mints12IrradArray566[counts_566] = mints12Irrad566; 
    mints12ValveOpenArray566[counts_566] = mints12ValveOpen566;
    ts12IrradErr566[counts_566] = (maxts12Irrad566 - mints12Irrad566)/2;
    ts12ValveOpenErr566[counts_566] = (maxts12ValveOpen566 - mints12ValveOpen566)/2;
    avecurArray566[counts_566] = avecur566;
    maxcurArray566[counts_566] = maxcur566;
    mincurArray566[counts_566] = mincur566;
    ErrcurArray566[counts_566] = (maxcur566 - mincur566)/2;
    delaytimeArray566[counts_566] = cycleDelayTime566;
    cycleNumberArray566[counts_566] = cycleNumber566;
    BaselineArray566[counts_566] = Baseline566;
    BaselineIrradArray566[counts_566] = BaselineIrrad566;
    BaselineIrradErrArray566[counts_566] = BaselineIrradErr566;
    BaselineIntegralArray566[counts_566] = BaselineIntegral566;
    BaselineIrradIntegralArray566[counts_566] = BaselineIrradIntegral566;
    UCNIntegralManualArray566[counts_566] = HistIntegral566 - BaselineIntegral566;
    // cout << UCNIntegralManualArray566[counts_566] << endl;
    UCNIntegralManualErrArray566[counts_566] = sqrt(HistIntegral566 - BaselineIntegral566);
    cout << " The irradiation time for run 566 for cycle "<< counts_566<< " is "<< cycleStartTimes566 - irradStartTimes566 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566] = UCNIntegral566;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566] = cycleStartTimes566 - irradStartTimes566;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566] = UCNIntegralErr566;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566] = HistIntegral566;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566] = sqrt (HistIntegral566);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566] = HistIntegral566 - BaselineIntegral566;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566] = sqrt(HistIntegral566 - BaselineIntegral566);
    counts_566++;
  }


  // *****
  // 567
  // *****
  
  
  ULong64_t events567;
  events567 = (Double_t) outputTree567 -> GetEntries();

  for (ULong64_t j = 0 ; j < events567 ; j++){
    outputTree567 -> GetEvent(j);
    UCNIntegralArray567[counts_567] = UCNIntegral567;
    UCNIntegralErrArray567[counts_567] = UCNIntegralErr567;
    HistIntegralArray567[counts_567] = HistIntegral567;
    HistIntegralErrArray567[counts_567] = sqrt (HistIntegral567);
    avets12IrradArray567[counts_567] = avets12Irrad567;
    avets12ValveOpenArray567[counts_567] = avets12ValveOpen567;
    maxts12IrradArray567[counts_567] = maxts12Irrad567;
    maxts12ValveOpenArray567[counts_567] = maxts12ValveOpen567;
    mints12IrradArray567[counts_567] = mints12Irrad567; 
    mints12ValveOpenArray567[counts_567] = mints12ValveOpen567;
    ts12IrradErr567[counts_567] = (maxts12Irrad567 - mints12Irrad567)/2;
    ts12ValveOpenErr567[counts_567] = (maxts12ValveOpen567 - mints12ValveOpen567)/2;
    avecurArray567[counts_567] = avecur567;
    maxcurArray567[counts_567] = maxcur567;
    mincurArray567[counts_567] = mincur567;
    ErrcurArray567[counts_567] = (maxcur567 - mincur567)/2;
    delaytimeArray567[counts_567] = cycleDelayTime567;
    cycleNumberArray567[counts_567] = cycleNumber567;
    BaselineArray567[counts_567] = Baseline567;
    BaselineIrradArray567[counts_567] = BaselineIrrad567;
    BaselineIrradErrArray567[counts_567] = BaselineIrradErr567;
    BaselineIntegralArray567[counts_567] = BaselineIntegral567;
    BaselineIrradIntegralArray567[counts_567] = BaselineIrradIntegral567;
    UCNIntegralManualArray567[counts_567] = HistIntegral567 - BaselineIntegral567;
    // cout << UCNIntegralManualArray567[counts_567] << endl;
    UCNIntegralManualErrArray567[counts_567] = sqrt(HistIntegral567 - BaselineIntegral567);
    cout << " The irradiation time for run 567 for cycle "<< counts_567<< " is "<< cycleStartTimes567 - irradStartTimes567 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = UCNIntegral567;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = cycleStartTimes567 - irradStartTimes567;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = UCNIntegralErr567;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = HistIntegral567;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = sqrt (HistIntegral567);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = HistIntegral567 - BaselineIntegral567;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567] = sqrt(HistIntegral567 - BaselineIntegral567);
    counts_567++;
  }

  // *****
  // 568
  // *****
  
  
  ULong64_t events568;
  events568 = (Double_t) outputTree568 -> GetEntries();

  for (ULong64_t j = 0 ; j < events568 ; j++){
    outputTree568 -> GetEvent(j);
    UCNIntegralArray568[counts_568] = UCNIntegral568;
    UCNIntegralErrArray568[counts_568] = UCNIntegralErr568;
    HistIntegralArray568[counts_568] = HistIntegral568;
    HistIntegralErrArray568[counts_568] = sqrt (HistIntegral568);
    avets12IrradArray568[counts_568] = avets12Irrad568;
    avets12ValveOpenArray568[counts_568] = avets12ValveOpen568;
    maxts12IrradArray568[counts_568] = maxts12Irrad568;
    maxts12ValveOpenArray568[counts_568] = maxts12ValveOpen568;
    mints12IrradArray568[counts_568] = mints12Irrad568; 
    mints12ValveOpenArray568[counts_568] = mints12ValveOpen568;
    ts12IrradErr568[counts_568] = (maxts12Irrad568 - mints12Irrad568)/2;
    ts12ValveOpenErr568[counts_568] = (maxts12ValveOpen568 - mints12ValveOpen568)/2;
    avecurArray568[counts_568] = avecur568;
    maxcurArray568[counts_568] = maxcur568;
    mincurArray568[counts_568] = mincur568;
    ErrcurArray568[counts_568] = (maxcur568 - mincur568)/2;
    delaytimeArray568[counts_568] = cycleDelayTime568;
    cycleNumberArray568[counts_568] = cycleNumber568;
    BaselineArray568[counts_568] = Baseline568;
    BaselineIrradArray568[counts_568] = BaselineIrrad568;
    BaselineIrradErrArray568[counts_568] = BaselineIrradErr568;
    BaselineIntegralArray568[counts_568] = BaselineIntegral568;
    BaselineIrradIntegralArray568[counts_568] = BaselineIrradIntegral568;
    UCNIntegralManualArray568[counts_568] = HistIntegral568 - BaselineIntegral568;
    // cout << UCNIntegralManualArray568[counts_568] << endl;
    UCNIntegralManualErrArray568[counts_568] = sqrt(HistIntegral568 - BaselineIntegral568);
    cout << " The irradiation time for run 568 for cycle "<< counts_568<< " is "<< cycleStartTimes568 - irradStartTimes568 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = UCNIntegral568;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = cycleStartTimes568 - irradStartTimes568;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = UCNIntegralErr568;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = HistIntegral568;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = sqrt (HistIntegral568);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = HistIntegral568 - BaselineIntegral568;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568] = sqrt(HistIntegral568 - BaselineIntegral568);
    counts_568++;
  }

  // *****
  // 569
  // *****
  
  
  ULong64_t events569;
  events569 = (Double_t) outputTree569 -> GetEntries();

  for (ULong64_t j = 0 ; j < events569 ; j++){
    outputTree569 -> GetEvent(j);
    UCNIntegralArray569[counts_569] = UCNIntegral569;
    UCNIntegralErrArray569[counts_569] = UCNIntegralErr569;
    HistIntegralArray569[counts_569] = HistIntegral569;
    HistIntegralErrArray569[counts_569] = sqrt (HistIntegral569);
    avets12IrradArray569[counts_569] = avets12Irrad569;
    avets12ValveOpenArray569[counts_569] = avets12ValveOpen569;
    maxts12IrradArray569[counts_569] = maxts12Irrad569;
    maxts12ValveOpenArray569[counts_569] = maxts12ValveOpen569;
    mints12IrradArray569[counts_569] = mints12Irrad569; 
    mints12ValveOpenArray569[counts_569] = mints12ValveOpen569;
    ts12IrradErr569[counts_569] = (maxts12Irrad569 - mints12Irrad569)/2;
    ts12ValveOpenErr569[counts_569] = (maxts12ValveOpen569 - mints12ValveOpen569)/2;
    avecurArray569[counts_569] = avecur569;
    maxcurArray569[counts_569] = maxcur569;
    mincurArray569[counts_569] = mincur569;
    ErrcurArray569[counts_569] = (maxcur569 - mincur569)/2;
    delaytimeArray569[counts_569] = cycleDelayTime569;
    cycleNumberArray569[counts_569] = cycleNumber569;
    BaselineArray569[counts_569] = Baseline569;
    BaselineIrradArray569[counts_569] = BaselineIrrad569;
    BaselineIrradErrArray569[counts_569] = BaselineIrradErr569;
    BaselineIntegralArray569[counts_569] = BaselineIntegral569;
    BaselineIrradIntegralArray569[counts_569] = BaselineIrradIntegral569;
    UCNIntegralManualArray569[counts_569] = HistIntegral569 - BaselineIntegral569;
    // cout << UCNIntegralManualArray569[counts_569] << endl;
    UCNIntegralManualErrArray569[counts_569] = sqrt(HistIntegral569 - BaselineIntegral569);
    cout << " The irradiation time for run 569 for cycle "<< counts_569<< " is "<< cycleStartTimes569 - irradStartTimes569 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = UCNIntegral569;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = cycleStartTimes569 - irradStartTimes569;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = UCNIntegralErr569;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = HistIntegral569;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = sqrt (HistIntegral569);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = HistIntegral569 - BaselineIntegral569;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569] = sqrt(HistIntegral569 - BaselineIntegral569);
    counts_569++;
  }


  
  // *****
  // 570
  // *****
  
  
  ULong64_t events570;
  events570 = (Double_t) outputTree570 -> GetEntries();

  for (ULong64_t j = 0 ; j < events570 ; j++){
    outputTree570 -> GetEvent(j);
    UCNIntegralArray570[counts_570] = UCNIntegral570;
    UCNIntegralErrArray570[counts_570] = UCNIntegralErr570;
    HistIntegralArray570[counts_570] = HistIntegral570;
    HistIntegralErrArray570[counts_570] = sqrt (HistIntegral570);
    avets12IrradArray570[counts_570] = avets12Irrad570;
    avets12ValveOpenArray570[counts_570] = avets12ValveOpen570;
    maxts12IrradArray570[counts_570] = maxts12Irrad570;
    maxts12ValveOpenArray570[counts_570] = maxts12ValveOpen570;
    mints12IrradArray570[counts_570] = mints12Irrad570; 
    mints12ValveOpenArray570[counts_570] = mints12ValveOpen570;
    ts12IrradErr570[counts_570] = (maxts12Irrad570 - mints12Irrad570)/2;
    ts12ValveOpenErr570[counts_570] = (maxts12ValveOpen570 - mints12ValveOpen570)/2;
    avecurArray570[counts_570] = avecur570;
    maxcurArray570[counts_570] = maxcur570;
    mincurArray570[counts_570] = mincur570;
    ErrcurArray570[counts_570] = (maxcur570 - mincur570)/2;
    delaytimeArray570[counts_570] = cycleDelayTime570;
    cycleNumberArray570[counts_570] = cycleNumber570;
    BaselineArray570[counts_570] = Baseline570;
    BaselineIrradArray570[counts_570] = BaselineIrrad570;
    BaselineIrradErrArray570[counts_570] = BaselineIrradErr570;
    BaselineIntegralArray570[counts_570] = BaselineIntegral570;
    BaselineIrradIntegralArray570[counts_570] = BaselineIrradIntegral570;
    UCNIntegralManualArray570[counts_570] = HistIntegral570 - BaselineIntegral570;
    // cout << UCNIntegralManualArray570[counts_570] << endl;
    UCNIntegralManualErrArray570[counts_570] = sqrt(HistIntegral570 - BaselineIntegral570);
    cout << " The irradiation time for run 570 for cycle "<< counts_570<< " is "<< cycleStartTimes570 - irradStartTimes570 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = UCNIntegral570;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = cycleStartTimes570 - irradStartTimes570;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = UCNIntegralErr570;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = HistIntegral570;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = sqrt (HistIntegral570);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = HistIntegral570 - BaselineIntegral570;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570] = sqrt(HistIntegral570 - BaselineIntegral570);
    counts_570++;
  }


  // *****
  // 571
  // *****
  
  
  ULong64_t events571;
  events571 = (Double_t) outputTree571 -> GetEntries();

  for (ULong64_t j = 0 ; j < events571 ; j++){
    outputTree571 -> GetEvent(j);
    UCNIntegralArray571[counts_571] = UCNIntegral571;
    UCNIntegralErrArray571[counts_571] = UCNIntegralErr571;
    HistIntegralArray571[counts_571] = HistIntegral571;
    HistIntegralErrArray571[counts_571] = sqrt (HistIntegral571);
    avets12IrradArray571[counts_571] = avets12Irrad571;
    avets12ValveOpenArray571[counts_571] = avets12ValveOpen571;
    maxts12IrradArray571[counts_571] = maxts12Irrad571;
    maxts12ValveOpenArray571[counts_571] = maxts12ValveOpen571;
    mints12IrradArray571[counts_571] = mints12Irrad571; 
    mints12ValveOpenArray571[counts_571] = mints12ValveOpen571;
    ts12IrradErr571[counts_571] = (maxts12Irrad571 - mints12Irrad571)/2;
    ts12ValveOpenErr571[counts_571] = (maxts12ValveOpen571 - mints12ValveOpen571)/2;
    avecurArray571[counts_571] = avecur571;
    maxcurArray571[counts_571] = maxcur571;
    mincurArray571[counts_571] = mincur571;
    ErrcurArray571[counts_571] = (maxcur571 - mincur571)/2;
    delaytimeArray571[counts_571] = cycleDelayTime571;
    cycleNumberArray571[counts_571] = cycleNumber571;
    BaselineArray571[counts_571] = Baseline571;
    BaselineIrradArray571[counts_571] = BaselineIrrad571;
    BaselineIrradErrArray571[counts_571] = BaselineIrradErr571;
    BaselineIntegralArray571[counts_571] = BaselineIntegral571;
    BaselineIrradIntegralArray571[counts_571] = BaselineIrradIntegral571;
    UCNIntegralManualArray571[counts_571] = HistIntegral571 - BaselineIntegral571;
    // cout << UCNIntegralManualArray571[counts_571] << endl;
    UCNIntegralManualErrArray571[counts_571] = sqrt(HistIntegral571 - BaselineIntegral571);
    cout << " The irradiation time for run 571 for cycle "<< counts_571<< " is "<< cycleStartTimes571 - irradStartTimes571 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = UCNIntegral571;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = cycleStartTimes571 - irradStartTimes571;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = UCNIntegralErr571;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = HistIntegral571;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = sqrt (HistIntegral571);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = HistIntegral571 - BaselineIntegral571;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571] = sqrt(HistIntegral571 - BaselineIntegral571);
    counts_571++;
  }


  // *****
  // 572
  // *****
  
  
  ULong64_t events572;
  events572 = (Double_t) outputTree572 -> GetEntries();

  for (ULong64_t j = 0 ; j < events572 ; j++){
    outputTree572 -> GetEvent(j);
    UCNIntegralArray572[counts_572] = UCNIntegral572;
    UCNIntegralErrArray572[counts_572] = UCNIntegralErr572;
    HistIntegralArray572[counts_572] = HistIntegral572;
    HistIntegralErrArray572[counts_572] = sqrt (HistIntegral572);
    avets12IrradArray572[counts_572] = avets12Irrad572;
    avets12ValveOpenArray572[counts_572] = avets12ValveOpen572;
    maxts12IrradArray572[counts_572] = maxts12Irrad572;
    maxts12ValveOpenArray572[counts_572] = maxts12ValveOpen572;
    mints12IrradArray572[counts_572] = mints12Irrad572; 
    mints12ValveOpenArray572[counts_572] = mints12ValveOpen572;
    ts12IrradErr572[counts_572] = (maxts12Irrad572 - mints12Irrad572)/2;
    ts12ValveOpenErr572[counts_572] = (maxts12ValveOpen572 - mints12ValveOpen572)/2;
    avecurArray572[counts_572] = avecur572;
    maxcurArray572[counts_572] = maxcur572;
    mincurArray572[counts_572] = mincur572;
    ErrcurArray572[counts_572] = (maxcur572 - mincur572)/2;
    delaytimeArray572[counts_572] = cycleDelayTime572;
    cycleNumberArray572[counts_572] = cycleNumber572;
    BaselineArray572[counts_572] = Baseline572;
    BaselineIrradArray572[counts_572] = BaselineIrrad572;
    BaselineIrradErrArray572[counts_572] = BaselineIrradErr572;
    BaselineIntegralArray572[counts_572] = BaselineIntegral572;
    BaselineIrradIntegralArray572[counts_572] = BaselineIrradIntegral572;
    UCNIntegralManualArray572[counts_572] = HistIntegral572 - BaselineIntegral572;
    // cout << UCNIntegralManualArray572[counts_572] << endl;
    UCNIntegralManualErrArray572[counts_572] = sqrt(HistIntegral572 - BaselineIntegral572);
    cout << " The irradiation time for run 572 for cycle "<< counts_572<< " is "<< cycleStartTimes572 - irradStartTimes572 << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = UCNIntegral572;
    irradArray[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = cycleStartTimes572 - irradStartTimes572;
    UCNIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = UCNIntegralErr572;
    HistIntegralAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = HistIntegral572;
    HistIntegralErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = sqrt (HistIntegral572);
    UCNIntegralManualAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = HistIntegral572 - BaselineIntegral572;
    UCNIntegralManualErrAll[counts_562+counts_563+counts_564+counts_565+counts_566+counts_567+counts_568+counts_569+counts_570+counts_571+counts_572] = sqrt(HistIntegral572 - BaselineIntegral572);
    counts_572++;
  }

  
  // *******************
  //     GRAPHS
  // ******************

  // ******
  //  562
  // ******
  

  TCanvas *c562_cylceNum =  new TCanvas("c562_cycleNum" , "c562_cycleNum " , 1200, 900);
  c562_cycleNum-> Divide(2,2);

  TPad *p562_1 = c562_cycleNum->cd(1);
  p562_1->SetLogy(); 
  TGraphErrors *gr562_cyclecounts = new TGraphErrors (counts_562 , cycleNumberArray562, UCNIntegralArray562, 0 , UCNIntegralErrArray562);
  gr562_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr562_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr562_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr562_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr562_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr562_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr562_cyclehist = new TGraphErrors(counts_562, cycleNumberArray562 , HistIntegralArray562, 0, HistIntegralErrArray562);
  
  gr562_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr562_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr562_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr562_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr562_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr562_cyclehist -> SetMarkerColor(2);
  gr562_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr562_cyclecountmanual = new TGraphErrors(counts_562, cycleNumberArray562 , UCNIntegralManualArray562, 0, UCNIntegralManualErrArray562);
  
  gr562_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr562_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr562_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr562_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr562_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr562_cyclecountmanual -> SetMarkerColor(1);
  gr562_cyclecountmanual -> SetMarkerStyle(25);
  

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr562_cyclecounts , "Without Background (fit)" , "p") ;
  leg2 -> AddEntry(gr562_cyclehist , "With Background" , "p") ;
  leg2 -> AddEntry(gr562_cyclecountmanual, "Without Background" , "p"); 
  leg2 -> SetTextSize(0.05);
  
  gr562_cyclecounts -> Draw("Ap");
  gr562_cyclehist -> Draw("p");
  gr562_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c562_cycleNum -> cd(2);
  TGraphErrors *gr562_cycledelay = new TGraphErrors (counts_562 , cycleNumberArray562, delaytimeArray562, 0 , 0);
  gr562_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr562_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr562_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr562_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr562_cycledelay -> SetMarkerStyle(20);
  
  gr562_cycledelay -> Draw("Ap");
  
  
  c562_cycleNum -> cd(3);
  TGraphErrors *gr562_cycletempIrrad = new TGraphErrors (counts_562 , cycleNumberArray562, avets12IrradArray562, 0 , ts12IrradErr562);
  
  gr562_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr562_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr562_cycletempIrrad -> SetMarkerStyle(20);
  gr562_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 1.3);
  gr562_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr562_cycletempValveOpen = new TGraphErrors (counts_562 , cycleNumberArray562, avets12ValveOpenArray562, 0 , ts12ValveOpenErr562);
  
  gr562_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr562_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr562_cycletempValveOpen -> SetMarkerStyle(20);
  gr562_cycletempValveOpen -> SetMarkerColor(2);
  gr562_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr562_cycletempIrrad , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr562_cycletempValveOpen , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  
  gr562_cycletempIrrad -> Draw("AP");
  gr562_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c562_cycleNum -> cd(4);
  TGraphErrors *gr562_cyclecur = new TGraphErrors (counts_562 , cycleNumberArray562 , avecurArray562, 0, ErrcurArray562 );
  gr562_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr562_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr562_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr562_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr562_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr562_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr562_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr562_cyclecur -> SetMarkerStyle(20);
  gr562_cyclecur -> Draw("Ap");
  c562_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c_counttemp = new TCanvas ("c_counttemp" , "c_counttemp " , 1200, 900);
  c_counttemp -> SetLogy();

  TGraphErrors *gr562_countIrrad = new TGraphErrors (counts_562, avets12IrradArray562, UCNIntegralArray562, ts12IrradErr562, UCNIntegralErrArray562);
  gr562_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr562_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr562_countIrrad -> SetMarkerStyle(20);
  gr562_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr562_countIrrad -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr562_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr562_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr562_HistIrrad = new TGraphErrors (counts_562, avets12IrradArray562, HistIntegralArray562, ts12IrradErr562, HistIntegralErrArray562);
  gr562_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr562_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr562_HistIrrad -> SetMarkerStyle(25);
  gr562_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr562_HistIrrad -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr562_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr562_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

  TGraphErrors *gr562_countValveOpen = new TGraphErrors (counts_562, avets12ValveOpenArray562, UCNIntegralArray562, ts12ValveOpenErr562, UCNIntegralErrArray562);
  gr562_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr562_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr562_countValveOpen -> SetMarkerStyle(20);
  gr562_countValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr562_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr562_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr562_countValveOpen -> SetMarkerColor(2);


  TGraphErrors *gr562_HistValveOpen = new TGraphErrors (counts_562, avets12ValveOpenArray562, HistIntegralArray562, ts12ValveOpenErr562, HistIntegralErrArray562);
  gr562_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr562_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr562_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr562_HistValveOpen -> SetMarkerStyle(25);
  gr562_HistValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr562_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr562_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr562_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr562_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr562_HistValveOpen -> SetMarkerColor(2);

  TLegend *leg3 = new TLegend(0.25,0.7, 0.9, 0.9);
  leg3 -> AddEntry(gr562_countIrrad , "Irradiation time + delay time, without background" , "p") ;
  //leg3 -> AddEntry(gr562_countValveOpen , "Valve open, without background" , "p") ;
  leg3 -> AddEntry(gr562_HistIrrad , "Irradiation time + delay time, with background" , "p") ;
  //leg3 -> AddEntry(gr562_HistValveOpen , "Valve open, with background" , "p") ;
  leg3 -> SetTextSize(0.04);

  gr562_countIrrad -> Draw("AP");
  //gr_countValveOpen -> Draw("p");
   gr562_HistIrrad -> Draw("p");
  //gr_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  // ************************************************
  
  // ******
  //  563
  // ******
  

  TCanvas *c563_cylceNum =  new TCanvas("c563_cycleNum" , "c563_cycleNum " , 1200, 900);
  c563_cycleNum-> Divide(2,2);

  TPad *p563_1 = c563_cycleNum->cd(1);
  p563_1->SetLogy(); 
  TGraphErrors *gr563_cyclecounts = new TGraphErrors (counts_563 , cycleNumberArray563, UCNIntegralArray563, 0 , UCNIntegralErrArray563);
  gr563_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr563_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr563_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr563_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr563_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr563_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr563_cyclehist = new TGraphErrors(counts_563, cycleNumberArray563 , HistIntegralArray563, 0, HistIntegralErrArray563);
  
  gr563_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr563_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr563_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr563_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr563_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr563_cyclehist -> SetMarkerColor(2);
  gr563_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr563_cyclecountmanual = new TGraphErrors(counts_563, cycleNumberArray563 , UCNIntegralManualArray563, 0, UCNIntegralManualErrArray563);
  
  gr563_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr563_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr563_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr563_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr563_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr563_cyclecountmanual -> SetMarkerColor(1);
  gr563_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr563_cyclecounts -> Draw("Ap");
  gr563_cyclehist -> Draw("p");
  gr563_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c563_cycleNum -> cd(2);
  TGraphErrors *gr563_cycledelay = new TGraphErrors (counts_563 , cycleNumberArray563, delaytimeArray563, 0 , 0);
  gr563_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr563_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr563_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr563_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr563_cycledelay -> SetMarkerStyle(20);
  
  gr563_cycledelay -> Draw("Ap");
  
  
  c563_cycleNum -> cd(3);
  TGraphErrors *gr563_cycletempIrrad = new TGraphErrors (counts_563 , cycleNumberArray563, avets12IrradArray563, 0 , ts12IrradErr563);
  
  gr563_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr563_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr563_cycletempIrrad -> SetMarkerStyle(20);
  gr563_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr563_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr563_cycletempValveOpen = new TGraphErrors (counts_563 , cycleNumberArray563, avets12ValveOpenArray563, 0 , ts12ValveOpenErr563);
  
  gr563_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr563_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr563_cycletempValveOpen -> SetMarkerStyle(20);
  gr563_cycletempValveOpen -> SetMarkerColor(2);
  gr563_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr563_cycletempIrrad -> Draw("AP");
  gr563_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c563_cycleNum -> cd(4);
  TGraphErrors *gr563_cyclecur = new TGraphErrors (counts_563 , cycleNumberArray563 , avecurArray563, 0, ErrcurArray563 );
  gr563_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr563_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr563_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr563_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr563_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr563_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr563_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr563_cyclecur -> SetMarkerStyle(20);
  gr563_cyclecur -> Draw("Ap");
  c563_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c563_counttemp = new TCanvas ("c563_counttemp" , "c563_counttemp " , 1200, 900);
  c563_counttemp -> SetLogy();

  TGraphErrors *gr563_countIrrad = new TGraphErrors (counts_563, avets12IrradArray563, UCNIntegralArray563, ts12IrradErr563, UCNIntegralErrArray563);
  gr563_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr563_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr563_countIrrad -> SetMarkerStyle(20);
  gr563_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr563_countIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr563_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr563_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr563_HistIrrad = new TGraphErrors (counts_563, avets12IrradArray563, HistIntegralArray563, ts12IrradErr563, HistIntegralErrArray563);
  gr563_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr563_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr563_HistIrrad -> SetMarkerStyle(25);
  gr563_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr563_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr563_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr563_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr563_countValveOpen = new TGraphErrors (counts_563, avets12ValveOpenArray563, UCNIntegralArray563, ts12ValveOpenErr563, UCNIntegralErrArray563);
  gr563_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr563_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr563_countValveOpen -> SetMarkerStyle(20);
  gr563_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr563_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr563_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr563_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr563_HistValveOpen = new TGraphErrors (counts_563, avets12ValveOpenArray563, HistIntegralArray563, ts12ValveOpenErr563, HistIntegralErrArray563);
  gr563_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr563_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr563_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr563_HistValveOpen -> SetMarkerStyle(25);
  gr563_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr563_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr563_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr563_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr563_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr563_HistValveOpen -> SetMarkerColor(2);



  gr563_countIrrad -> Draw("AP");
  //gr563_countValveOpen -> Draw("p");
   gr563_HistIrrad -> Draw("p");
  //gr563_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  //*******************************************
  // ******
  //  564
  // ******
  

  TCanvas *c564_cylceNum =  new TCanvas("c564_cycleNum" , "c564_cycleNum " , 1200, 900);
  c564_cycleNum-> Divide(2,2);

  TPad *p564_1 = c564_cycleNum->cd(1);
  p564_1->SetLogy(); 
  TGraphErrors *gr564_cyclecounts = new TGraphErrors (counts_564 , cycleNumberArray564, UCNIntegralArray564, 0 , UCNIntegralErrArray564);
  gr564_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr564_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr564_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr564_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr564_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr564_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr564_cyclehist = new TGraphErrors(counts_564, cycleNumberArray564 , HistIntegralArray564, 0, HistIntegralErrArray564);
  
  gr564_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr564_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr564_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr564_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr564_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr564_cyclehist -> SetMarkerColor(2);
  gr564_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr564_cyclecountmanual = new TGraphErrors(counts_564, cycleNumberArray564 , UCNIntegralManualArray564, 0, UCNIntegralManualErrArray564);
  
  gr564_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr564_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr564_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr564_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr564_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr564_cyclecountmanual -> SetMarkerColor(1);
  gr564_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr564_cyclecounts -> Draw("Ap");
  gr564_cyclehist -> Draw("p");
  gr564_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c564_cycleNum -> cd(2);
  TGraphErrors *gr564_cycledelay = new TGraphErrors (counts_564 , cycleNumberArray564, delaytimeArray564, 0 , 0);
  gr564_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr564_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr564_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr564_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr564_cycledelay -> SetMarkerStyle(20);
  gr564_cycledelay -> Draw("Ap");
  
  
  c564_cycleNum -> cd(3);
  TGraphErrors *gr564_cycletempIrrad = new TGraphErrors (counts_564 , cycleNumberArray564, avets12IrradArray564, 0 , ts12IrradErr564);
  
  gr564_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr564_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr564_cycletempIrrad -> SetMarkerStyle(20);
  gr564_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr564_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr564_cycletempValveOpen = new TGraphErrors (counts_564 , cycleNumberArray564, avets12ValveOpenArray564, 0 , ts12ValveOpenErr564);
  
  gr564_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr564_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr564_cycletempValveOpen -> SetMarkerStyle(20);
  gr564_cycletempValveOpen -> SetMarkerColor(2);
  gr564_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr564_cycletempIrrad -> Draw("AP");
  gr564_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c564_cycleNum -> cd(4);
  TGraphErrors *gr564_cyclecur = new TGraphErrors (counts_564 , cycleNumberArray564 , avecurArray564, 0, ErrcurArray564 );
  gr564_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr564_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr564_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr564_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr564_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr564_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr564_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr564_cyclecur -> SetMarkerStyle(20);
  gr564_cyclecur -> Draw("Ap");
  c564_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c564_counttemp = new TCanvas ("c564_counttemp" , "c564_counttemp " , 1200, 900);
  c564_counttemp -> SetLogy();

  TGraphErrors *gr564_countIrrad = new TGraphErrors (counts_564, avets12IrradArray564, UCNIntegralArray564, ts12IrradErr564, UCNIntegralErrArray564);
  gr564_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr564_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr564_countIrrad -> SetMarkerStyle(20);
  gr564_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr564_countIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr564_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr564_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr564_HistIrrad = new TGraphErrors (counts_564, avets12IrradArray564, HistIntegralArray564, ts12IrradErr564, HistIntegralErrArray564);
  gr564_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr564_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr564_HistIrrad -> SetMarkerStyle(25);
  gr564_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr564_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr564_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr564_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr564_countValveOpen = new TGraphErrors (counts_564, avets12ValveOpenArray564, UCNIntegralArray564, ts12ValveOpenErr564, UCNIntegralErrArray564);
  gr564_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr564_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr564_countValveOpen -> SetMarkerStyle(20);
  gr564_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr564_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr564_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr564_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr564_HistValveOpen = new TGraphErrors (counts_564, avets12ValveOpenArray564, HistIntegralArray564, ts12ValveOpenErr564, HistIntegralErrArray564);
  gr564_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr564_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr564_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr564_HistValveOpen -> SetMarkerStyle(25);
  gr564_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr564_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr564_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr564_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr564_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr564_HistValveOpen -> SetMarkerColor(2);



  gr564_countIrrad -> Draw("AP");
  //gr564_countValveOpen -> Draw("p");
   gr564_HistIrrad -> Draw("p");
  //gr564_HistValveOpen -> Draw("p");
  leg3 -> Draw();



  //********************************************
  // ******
  //  565
  // ******
  

  TCanvas *c565_cylceNum =  new TCanvas("c565_cycleNum" , "c565_cycleNum " , 1200, 900);
  c565_cycleNum-> Divide(2,2);

  TPad *p565_1 = c565_cycleNum->cd(1);
  p565_1->SetLogy(); 
  TGraphErrors *gr565_cyclecounts = new TGraphErrors (counts_565 , cycleNumberArray565, UCNIntegralArray565, 0 , UCNIntegralErrArray565);
  gr565_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr565_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr565_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr565_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr565_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr565_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr565_cyclehist = new TGraphErrors(counts_565, cycleNumberArray565 , HistIntegralArray565, 0, HistIntegralErrArray565);
  
  gr565_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr565_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr565_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr565_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr565_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr565_cyclehist -> SetMarkerColor(2);
  gr565_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr565_cyclecountmanual = new TGraphErrors(counts_565, cycleNumberArray565 , UCNIntegralManualArray565, 0, UCNIntegralManualErrArray565);
  
  gr565_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr565_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr565_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr565_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr565_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr565_cyclecountmanual -> SetMarkerColor(1);
  gr565_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr565_cyclecounts -> Draw("Ap");
  gr565_cyclehist -> Draw("p");
  gr565_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c565_cycleNum -> cd(2);
  TGraphErrors *gr565_cycledelay = new TGraphErrors (counts_565 , cycleNumberArray565, delaytimeArray565, 0 , 0);
  gr565_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr565_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr565_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr565_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr565_cycledelay -> SetMarkerStyle(20);
  
  gr565_cycledelay -> Draw("Ap");
  
  
  c565_cycleNum -> cd(3);
  TGraphErrors *gr565_cycletempIrrad = new TGraphErrors (counts_565 , cycleNumberArray565, avets12IrradArray565, 0 , ts12IrradErr565);
  
  gr565_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr565_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr565_cycletempIrrad -> SetMarkerStyle(20);
  gr565_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr565_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr565_cycletempValveOpen = new TGraphErrors (counts_565 , cycleNumberArray565, avets12ValveOpenArray565, 0 , ts12ValveOpenErr565);
  
  gr565_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr565_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr565_cycletempValveOpen -> SetMarkerStyle(20);
  gr565_cycletempValveOpen -> SetMarkerColor(2);
  gr565_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr565_cycletempIrrad -> Draw("AP");
  gr565_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c565_cycleNum -> cd(4);
  TGraphErrors *gr565_cyclecur = new TGraphErrors (counts_565 , cycleNumberArray565 , avecurArray565, 0, ErrcurArray565 );
  gr565_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr565_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr565_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr565_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr565_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr565_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr565_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr565_cyclecur -> SetMarkerStyle(20);
  gr565_cyclecur -> Draw("Ap");
  c565_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c565_counttemp = new TCanvas ("c565_counttemp" , "c565_counttemp " , 1200, 900);
  c565_counttemp -> SetLogy();

  TGraphErrors *gr565_countIrrad = new TGraphErrors (counts_565, avets12IrradArray565, UCNIntegralArray565, ts12IrradErr565, UCNIntegralErrArray565);
  gr565_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr565_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr565_countIrrad -> SetMarkerStyle(20);
  gr565_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr565_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr565_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr565_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr565_HistIrrad = new TGraphErrors (counts_565, avets12IrradArray565, HistIntegralArray565, ts12IrradErr565, HistIntegralErrArray565);
  gr565_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr565_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr565_HistIrrad -> SetMarkerStyle(25);
  gr565_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr565_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr565_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr565_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr565_countValveOpen = new TGraphErrors (counts_565, avets12ValveOpenArray565, UCNIntegralArray565, ts12ValveOpenErr565, UCNIntegralErrArray565);
  gr565_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr565_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr565_countValveOpen -> SetMarkerStyle(20);
  gr565_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr565_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr565_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr565_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr565_HistValveOpen = new TGraphErrors (counts_565, avets12ValveOpenArray565, HistIntegralArray565, ts12ValveOpenErr565, HistIntegralErrArray565);
  gr565_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr565_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr565_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr565_HistValveOpen -> SetMarkerStyle(25);
  gr565_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr565_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr565_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr565_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr565_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr565_HistValveOpen -> SetMarkerColor(2);



  gr565_countIrrad -> Draw("AP");
  //gr565_countValveOpen -> Draw("p");
   gr565_HistIrrad -> Draw("p");
  //gr565_HistValveOpen -> Draw("p");
  leg3 -> Draw();






  //********************************************
  // ******
  //  566
  // ******
  

  TCanvas *c566_cylceNum =  new TCanvas("c566_cycleNum" , "c566_cycleNum " , 1200, 900);
  c566_cycleNum-> Divide(2,2);

  TPad *p566_1 = c566_cycleNum->cd(1);
  p566_1->SetLogy(); 
  TGraphErrors *gr566_cyclecounts = new TGraphErrors (counts_566 , cycleNumberArray566, UCNIntegralArray566, 0 , UCNIntegralErrArray566);
  gr566_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr566_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr566_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr566_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr566_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr566_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr566_cyclehist = new TGraphErrors(counts_566, cycleNumberArray566 , HistIntegralArray566, 0, HistIntegralErrArray566);
  
  gr566_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr566_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr566_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr566_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr566_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr566_cyclehist -> SetMarkerColor(2);
  gr566_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr566_cyclecountmanual = new TGraphErrors(counts_566, cycleNumberArray566 , UCNIntegralManualArray566, 0, UCNIntegralManualErrArray566);
  
  gr566_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr566_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr566_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr566_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr566_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr566_cyclecountmanual -> SetMarkerColor(1);
  gr566_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr566_cyclecounts -> Draw("Ap");
  gr566_cyclehist -> Draw("p");
  gr566_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c566_cycleNum -> cd(2);
  TGraphErrors *gr566_cycledelay = new TGraphErrors (counts_566 , cycleNumberArray566, delaytimeArray566, 0 , 0);
  gr566_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr566_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr566_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr566_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr566_cycledelay -> SetMarkerStyle(20);
  
  gr566_cycledelay -> Draw("Ap");
  
  
  c566_cycleNum -> cd(3);
  TGraphErrors *gr566_cycletempIrrad = new TGraphErrors (counts_566 , cycleNumberArray566, avets12IrradArray566, 0 , ts12IrradErr566);
  
  gr566_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr566_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr566_cycletempIrrad -> SetMarkerStyle(20);
  gr566_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr566_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr566_cycletempValveOpen = new TGraphErrors (counts_566 , cycleNumberArray566, avets12ValveOpenArray566, 0 , ts12ValveOpenErr566);
  
  gr566_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr566_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr566_cycletempValveOpen -> SetMarkerStyle(20);
  gr566_cycletempValveOpen -> SetMarkerColor(2);
  gr566_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr566_cycletempIrrad -> Draw("AP");
  gr566_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c566_cycleNum -> cd(4);
  TGraphErrors *gr566_cyclecur = new TGraphErrors (counts_566 , cycleNumberArray566 , avecurArray566, 0, ErrcurArray566 );
  gr566_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr566_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr566_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr566_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr566_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr566_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr566_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr566_cyclecur -> SetMarkerStyle(20);
  gr566_cyclecur -> Draw("Ap");
  c566_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c566_counttemp = new TCanvas ("c566_counttemp" , "c566_counttemp " , 1200, 900);
  c566_counttemp -> SetLogy();

  TGraphErrors *gr566_countIrrad = new TGraphErrors (counts_566, avets12IrradArray566, UCNIntegralArray566, ts12IrradErr566, UCNIntegralErrArray566);
  gr566_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr566_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr566_countIrrad -> SetMarkerStyle(20);
  gr566_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr566_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr566_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr566_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr566_HistIrrad = new TGraphErrors (counts_566, avets12IrradArray566, HistIntegralArray566, ts12IrradErr566, HistIntegralErrArray566);
  gr566_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr566_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr566_HistIrrad -> SetMarkerStyle(25);
  gr566_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr566_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr566_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr566_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr566_countValveOpen = new TGraphErrors (counts_566, avets12ValveOpenArray566, UCNIntegralArray566, ts12ValveOpenErr566, UCNIntegralErrArray566);
  gr566_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr566_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr566_countValveOpen -> SetMarkerStyle(20);
  gr566_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr566_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr566_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr566_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr566_HistValveOpen = new TGraphErrors (counts_566, avets12ValveOpenArray566, HistIntegralArray566, ts12ValveOpenErr566, HistIntegralErrArray566);
  gr566_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr566_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr566_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr566_HistValveOpen -> SetMarkerStyle(25);
  gr566_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr566_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr566_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr566_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr566_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr566_HistValveOpen -> SetMarkerColor(2);



  gr566_countIrrad -> Draw("AP");
  //gr566_countValveOpen -> Draw("p");
   gr566_HistIrrad -> Draw("p");
  //gr566_HistValveOpen -> Draw("p");
  leg3 -> Draw();
  


  //********************************************
  // ******
  //  567
  // ******
  

  TCanvas *c567_cylceNum =  new TCanvas("c567_cycleNum" , "c567_cycleNum " , 1200, 900);
  c567_cycleNum-> Divide(2,2);

  TPad *p567_1 = c567_cycleNum->cd(1);
  p567_1->SetLogy(); 
  TGraphErrors *gr567_cyclecounts = new TGraphErrors (counts_567 , cycleNumberArray567, UCNIntegralArray567, 0 , UCNIntegralErrArray567);
  gr567_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr567_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr567_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr567_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr567_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr567_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr567_cyclehist = new TGraphErrors(counts_567, cycleNumberArray567 , HistIntegralArray567, 0, HistIntegralErrArray567);
  
  gr567_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr567_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr567_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr567_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr567_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr567_cyclehist -> SetMarkerColor(2);
  gr567_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr567_cyclecountmanual = new TGraphErrors(counts_567, cycleNumberArray567 , UCNIntegralManualArray567, 0, UCNIntegralManualErrArray567);
  
  gr567_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr567_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr567_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr567_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr567_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr567_cyclecountmanual -> SetMarkerColor(1);
  gr567_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr567_cyclecounts -> Draw("Ap");
  gr567_cyclehist -> Draw("p");
  gr567_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c567_cycleNum -> cd(2);
  TGraphErrors *gr567_cycledelay = new TGraphErrors (counts_567 , cycleNumberArray567, delaytimeArray567, 0 , 0);
  gr567_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr567_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr567_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr567_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr567_cycledelay -> SetMarkerStyle(20);
  
  gr567_cycledelay -> Draw("Ap");
  
  
  c567_cycleNum -> cd(3);
  TGraphErrors *gr567_cycletempIrrad = new TGraphErrors (counts_567 , cycleNumberArray567, avets12IrradArray567, 0 , ts12IrradErr567);
  
  gr567_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr567_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr567_cycletempIrrad -> SetMarkerStyle(20);
  gr567_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr567_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr567_cycletempValveOpen = new TGraphErrors (counts_567 , cycleNumberArray567, avets12ValveOpenArray567, 0 , ts12ValveOpenErr567);
  
  gr567_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr567_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr567_cycletempValveOpen -> SetMarkerStyle(20);
  gr567_cycletempValveOpen -> SetMarkerColor(2);
  gr567_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr567_cycletempIrrad -> Draw("AP");
  gr567_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c567_cycleNum -> cd(4);
  TGraphErrors *gr567_cyclecur = new TGraphErrors (counts_567 , cycleNumberArray567 , avecurArray567, 0, ErrcurArray567 );
  gr567_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr567_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr567_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr567_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr567_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr567_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr567_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr567_cyclecur -> SetMarkerStyle(20);
  gr567_cyclecur -> Draw("Ap");
  c567_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c567_counttemp = new TCanvas ("c567_counttemp" , "c567_counttemp " , 1200, 900);
  c567_counttemp -> SetLogy();

  TGraphErrors *gr567_countIrrad = new TGraphErrors (counts_567, avets12IrradArray567, UCNIntegralArray567, ts12IrradErr567, UCNIntegralErrArray567);
  gr567_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr567_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr567_countIrrad -> SetMarkerStyle(20);
  gr567_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr567_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr567_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr567_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr567_HistIrrad = new TGraphErrors (counts_567, avets12IrradArray567, HistIntegralArray567, ts12IrradErr567, HistIntegralErrArray567);
  gr567_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr567_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr567_HistIrrad -> SetMarkerStyle(25);
  gr567_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr567_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr567_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr567_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr567_countValveOpen = new TGraphErrors (counts_567, avets12ValveOpenArray567, UCNIntegralArray567, ts12ValveOpenErr567, UCNIntegralErrArray567);
  gr567_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr567_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr567_countValveOpen -> SetMarkerStyle(20);
  gr567_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr567_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr567_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr567_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr567_HistValveOpen = new TGraphErrors (counts_567, avets12ValveOpenArray567, HistIntegralArray567, ts12ValveOpenErr567, HistIntegralErrArray567);
  gr567_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr567_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr567_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr567_HistValveOpen -> SetMarkerStyle(25);
  gr567_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr567_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr567_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr567_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr567_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr567_HistValveOpen -> SetMarkerColor(2);



  gr567_countIrrad -> Draw("AP");
  //gr567_countValveOpen -> Draw("p");
   gr567_HistIrrad -> Draw("p");
  //gr567_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  
  //********************************************
  // ******
  //  568
  // ******
  

  TCanvas *c568_cylceNum =  new TCanvas("c568_cycleNum" , "c568_cycleNum " , 1200, 900);
  c568_cycleNum-> Divide(2,2);

  TPad *p568_1 = c568_cycleNum->cd(1);
  p568_1->SetLogy(); 
  TGraphErrors *gr568_cyclecounts = new TGraphErrors (counts_568 , cycleNumberArray568, UCNIntegralArray568, 0 , UCNIntegralErrArray568);
  gr568_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr568_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr568_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr568_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr568_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr568_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr568_cyclehist = new TGraphErrors(counts_568, cycleNumberArray568 , HistIntegralArray568, 0, HistIntegralErrArray568);
  
  gr568_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr568_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr568_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr568_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr568_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr568_cyclehist -> SetMarkerColor(2);
  gr568_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr568_cyclecountmanual = new TGraphErrors(counts_568, cycleNumberArray568 , UCNIntegralManualArray568, 0, UCNIntegralManualErrArray568);
  
  gr568_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr568_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr568_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr568_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr568_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr568_cyclecountmanual -> SetMarkerColor(1);
  gr568_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr568_cyclecounts -> Draw("Ap");
  gr568_cyclehist -> Draw("p");
  gr568_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c568_cycleNum -> cd(2);
  TGraphErrors *gr568_cycledelay = new TGraphErrors (counts_568 , cycleNumberArray568, delaytimeArray568, 0 , 0);
  gr568_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr568_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr568_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr568_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr568_cycledelay -> SetMarkerStyle(20);
  
  gr568_cycledelay -> Draw("Ap");
  
  
  c568_cycleNum -> cd(3);
  TGraphErrors *gr568_cycletempIrrad = new TGraphErrors (counts_568 , cycleNumberArray568, avets12IrradArray568, 0 , ts12IrradErr568);
  
  gr568_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr568_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr568_cycletempIrrad -> SetMarkerStyle(20);
  gr568_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr568_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr568_cycletempValveOpen = new TGraphErrors (counts_568 , cycleNumberArray568, avets12ValveOpenArray568, 0 , ts12ValveOpenErr568);
  
  gr568_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr568_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr568_cycletempValveOpen -> SetMarkerStyle(20);
  gr568_cycletempValveOpen -> SetMarkerColor(2);
  gr568_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr568_cycletempIrrad -> Draw("AP");
  gr568_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c568_cycleNum -> cd(4);
  TGraphErrors *gr568_cyclecur = new TGraphErrors (counts_568 , cycleNumberArray568 , avecurArray568, 0, ErrcurArray568 );
  gr568_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr568_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr568_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr568_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr568_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr568_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr568_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr568_cyclecur -> SetMarkerStyle(20);
  gr568_cyclecur -> Draw("Ap");
  c568_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c568_counttemp = new TCanvas ("c568_counttemp" , "c568_counttemp " , 1200, 900);
  c568_counttemp -> SetLogy();

  TGraphErrors *gr568_countIrrad = new TGraphErrors (counts_568, avets12IrradArray568, UCNIntegralArray568, ts12IrradErr568, UCNIntegralErrArray568);
  gr568_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr568_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr568_countIrrad -> SetMarkerStyle(20);
  gr568_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr568_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr568_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr568_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr568_HistIrrad = new TGraphErrors (counts_568, avets12IrradArray568, HistIntegralArray568, ts12IrradErr568, HistIntegralErrArray568);
  gr568_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr568_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr568_HistIrrad -> SetMarkerStyle(25);
  gr568_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr568_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr568_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr568_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr568_countValveOpen = new TGraphErrors (counts_568, avets12ValveOpenArray568, UCNIntegralArray568, ts12ValveOpenErr568, UCNIntegralErrArray568);
  gr568_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr568_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr568_countValveOpen -> SetMarkerStyle(20);
  gr568_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr568_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr568_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr568_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr568_HistValveOpen = new TGraphErrors (counts_568, avets12ValveOpenArray568, HistIntegralArray568, ts12ValveOpenErr568, HistIntegralErrArray568);
  gr568_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr568_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr568_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr568_HistValveOpen -> SetMarkerStyle(25);
  gr568_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr568_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr568_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr568_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr568_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr568_HistValveOpen -> SetMarkerColor(2);



  gr568_countIrrad -> Draw("AP");
  //gr568_countValveOpen -> Draw("p");
   gr568_HistIrrad -> Draw("p");
  //gr568_HistValveOpen -> Draw("p");
  leg3 -> Draw();




  
  //********************************************
  // ******
  //  569
  // ******
  

  TCanvas *c569_cylceNum =  new TCanvas("c569_cycleNum" , "c569_cycleNum " , 1200, 900);
  c569_cycleNum-> Divide(2,2);

  TPad *p569_1 = c569_cycleNum->cd(1);
  p569_1->SetLogy(); 
  TGraphErrors *gr569_cyclecounts = new TGraphErrors (counts_569 , cycleNumberArray569, UCNIntegralArray569, 0 , UCNIntegralErrArray569);
  gr569_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr569_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr569_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr569_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr569_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr569_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr569_cyclehist = new TGraphErrors(counts_569, cycleNumberArray569 , HistIntegralArray569, 0, HistIntegralErrArray569);
  
  gr569_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr569_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr569_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr569_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr569_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr569_cyclehist -> SetMarkerColor(2);
  gr569_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr569_cyclecountmanual = new TGraphErrors(counts_569, cycleNumberArray569 , UCNIntegralManualArray569, 0, UCNIntegralManualErrArray569);
  
  gr569_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr569_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr569_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr569_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr569_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr569_cyclecountmanual -> SetMarkerColor(1);
  gr569_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr569_cyclecounts -> Draw("Ap");
  gr569_cyclehist -> Draw("p");
  gr569_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c569_cycleNum -> cd(2);
  TGraphErrors *gr569_cycledelay = new TGraphErrors (counts_569 , cycleNumberArray569, delaytimeArray569, 0 , 0);
  gr569_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr569_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr569_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr569_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr569_cycledelay -> SetMarkerStyle(20);
  
  gr569_cycledelay -> Draw("Ap");
  
  
  c569_cycleNum -> cd(3);
  TGraphErrors *gr569_cycletempIrrad = new TGraphErrors (counts_569 , cycleNumberArray569, avets12IrradArray569, 0 , ts12IrradErr569);
  
  gr569_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr569_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr569_cycletempIrrad -> SetMarkerStyle(20);
  gr569_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr569_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr569_cycletempValveOpen = new TGraphErrors (counts_569 , cycleNumberArray569, avets12ValveOpenArray569, 0 , ts12ValveOpenErr569);
  
  gr569_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr569_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr569_cycletempValveOpen -> SetMarkerStyle(20);
  gr569_cycletempValveOpen -> SetMarkerColor(2);
  gr569_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr569_cycletempIrrad -> Draw("AP");
  gr569_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c569_cycleNum -> cd(4);
  TGraphErrors *gr569_cyclecur = new TGraphErrors (counts_569 , cycleNumberArray569 , avecurArray569, 0, ErrcurArray569 );
  gr569_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr569_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr569_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr569_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr569_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr569_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr569_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr569_cyclecur -> SetMarkerStyle(20);
  gr569_cyclecur -> Draw("Ap");
  c569_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c569_counttemp = new TCanvas ("c569_counttemp" , "c569_counttemp " , 1200, 900);
  c569_counttemp -> SetLogy();

  TGraphErrors *gr569_countIrrad = new TGraphErrors (counts_569, avets12IrradArray569, UCNIntegralArray569, ts12IrradErr569, UCNIntegralErrArray569);
  gr569_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr569_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr569_countIrrad -> SetMarkerStyle(20);
  gr569_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr569_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr569_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr569_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr569_HistIrrad = new TGraphErrors (counts_569, avets12IrradArray569, HistIntegralArray569, ts12IrradErr569, HistIntegralErrArray569);
  gr569_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr569_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr569_HistIrrad -> SetMarkerStyle(25);
  gr569_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr569_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr569_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr569_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr569_countValveOpen = new TGraphErrors (counts_569, avets12ValveOpenArray569, UCNIntegralArray569, ts12ValveOpenErr569, UCNIntegralErrArray569);
  gr569_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr569_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr569_countValveOpen -> SetMarkerStyle(20);
  gr569_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr569_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr569_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr569_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr569_HistValveOpen = new TGraphErrors (counts_569, avets12ValveOpenArray569, HistIntegralArray569, ts12ValveOpenErr569, HistIntegralErrArray569);
  gr569_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr569_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr569_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr569_HistValveOpen -> SetMarkerStyle(25);
  gr569_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr569_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr569_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr569_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr569_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr569_HistValveOpen -> SetMarkerColor(2);



  gr569_countIrrad -> Draw("AP");
  //gr569_countValveOpen -> Draw("p");
   gr569_HistIrrad -> Draw("p");
  //gr569_HistValveOpen -> Draw("p");
  leg3 -> Draw();



  
  //********************************************
  // ******
  //  570
  // ******
  

  TCanvas *c570_cylceNum =  new TCanvas("c570_cycleNum" , "c570_cycleNum " , 1200, 900);
  c570_cycleNum-> Divide(2,2);

  TPad *p570_1 = c570_cycleNum->cd(1);
  p570_1->SetLogy(); 
  TGraphErrors *gr570_cyclecounts = new TGraphErrors (counts_570 , cycleNumberArray570, UCNIntegralArray570, 0 , UCNIntegralErrArray570);
  gr570_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr570_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr570_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr570_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr570_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr570_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr570_cyclehist = new TGraphErrors(counts_570, cycleNumberArray570 , HistIntegralArray570, 0, HistIntegralErrArray570);
  
  gr570_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr570_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr570_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr570_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr570_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr570_cyclehist -> SetMarkerColor(2);
  gr570_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr570_cyclecountmanual = new TGraphErrors(counts_570, cycleNumberArray570 , UCNIntegralManualArray570, 0, UCNIntegralManualErrArray570);
  
  gr570_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr570_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr570_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr570_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr570_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr570_cyclecountmanual -> SetMarkerColor(1);
  gr570_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr570_cyclecounts -> Draw("Ap");
  gr570_cyclehist -> Draw("p");
  gr570_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c570_cycleNum -> cd(2);
  TGraphErrors *gr570_cycledelay = new TGraphErrors (counts_570 , cycleNumberArray570, delaytimeArray570, 0 , 0);
  gr570_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr570_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr570_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr570_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr570_cycledelay -> SetMarkerStyle(20);
  
  gr570_cycledelay -> Draw("Ap");
  
  
  c570_cycleNum -> cd(3);
  TGraphErrors *gr570_cycletempIrrad = new TGraphErrors (counts_570 , cycleNumberArray570, avets12IrradArray570, 0 , ts12IrradErr570);
  
  gr570_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr570_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr570_cycletempIrrad -> SetMarkerStyle(20);
  gr570_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr570_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr570_cycletempValveOpen = new TGraphErrors (counts_570 , cycleNumberArray570, avets12ValveOpenArray570, 0 , ts12ValveOpenErr570);
  
  gr570_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr570_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr570_cycletempValveOpen -> SetMarkerStyle(20);
  gr570_cycletempValveOpen -> SetMarkerColor(2);
  gr570_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr570_cycletempIrrad -> Draw("AP");
  gr570_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c570_cycleNum -> cd(4);
  TGraphErrors *gr570_cyclecur = new TGraphErrors (counts_570 , cycleNumberArray570 , avecurArray570, 0, ErrcurArray570 );
  gr570_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr570_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr570_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr570_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr570_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr570_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr570_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr570_cyclecur -> SetMarkerStyle(20);
  gr570_cyclecur -> Draw("Ap");
  c570_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c570_counttemp = new TCanvas ("c570_counttemp" , "c570_counttemp " , 1200, 900);
  c570_counttemp -> SetLogy();

  TGraphErrors *gr570_countIrrad = new TGraphErrors (counts_570, avets12IrradArray570, UCNIntegralArray570, ts12IrradErr570, UCNIntegralErrArray570);
  gr570_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr570_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr570_countIrrad -> SetMarkerStyle(20);
  gr570_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr570_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr570_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr570_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr570_HistIrrad = new TGraphErrors (counts_570, avets12IrradArray570, HistIntegralArray570, ts12IrradErr570, HistIntegralErrArray570);
  gr570_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr570_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr570_HistIrrad -> SetMarkerStyle(25);
  gr570_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr570_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr570_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr570_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr570_countValveOpen = new TGraphErrors (counts_570, avets12ValveOpenArray570, UCNIntegralArray570, ts12ValveOpenErr570, UCNIntegralErrArray570);
  gr570_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr570_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr570_countValveOpen -> SetMarkerStyle(20);
  gr570_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr570_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr570_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr570_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr570_HistValveOpen = new TGraphErrors (counts_570, avets12ValveOpenArray570, HistIntegralArray570, ts12ValveOpenErr570, HistIntegralErrArray570);
  gr570_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr570_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr570_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr570_HistValveOpen -> SetMarkerStyle(25);
  gr570_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr570_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr570_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr570_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr570_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr570_HistValveOpen -> SetMarkerColor(2);



  gr570_countIrrad -> Draw("AP");
  //gr570_countValveOpen -> Draw("p");
   gr570_HistIrrad -> Draw("p");
  //gr570_HistValveOpen -> Draw("p");
  leg3 -> Draw();

    
  //********************************************
  // ******
  //  571
  // ******
  

  TCanvas *c571_cylceNum =  new TCanvas("c571_cycleNum" , "c571_cycleNum " , 1200, 900);
  c571_cycleNum-> Divide(2,2);

  TPad *p571_1 = c571_cycleNum->cd(1);
  p571_1->SetLogy(); 
  TGraphErrors *gr571_cyclecounts = new TGraphErrors (counts_571 , cycleNumberArray571, UCNIntegralArray571, 0 , UCNIntegralErrArray571);
  gr571_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr571_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr571_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr571_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr571_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr571_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr571_cyclehist = new TGraphErrors(counts_571, cycleNumberArray571 , HistIntegralArray571, 0, HistIntegralErrArray571);
  
  gr571_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr571_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr571_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr571_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr571_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr571_cyclehist -> SetMarkerColor(2);
  gr571_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr571_cyclecountmanual = new TGraphErrors(counts_571, cycleNumberArray571 , UCNIntegralManualArray571, 0, UCNIntegralManualErrArray571);
  
  gr571_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr571_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr571_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr571_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr571_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr571_cyclecountmanual -> SetMarkerColor(1);
  gr571_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr571_cyclecounts -> Draw("Ap");
  gr571_cyclehist -> Draw("p");
  gr571_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c571_cycleNum -> cd(2);
  TGraphErrors *gr571_cycledelay = new TGraphErrors (counts_571 , cycleNumberArray571, delaytimeArray571, 0 , 0);
  gr571_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr571_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr571_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr571_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr571_cycledelay -> SetMarkerStyle(20);
  
  gr571_cycledelay -> Draw("Ap");
  
  
  c571_cycleNum -> cd(3);
  TGraphErrors *gr571_cycletempIrrad = new TGraphErrors (counts_571 , cycleNumberArray571, avets12IrradArray571, 0 , ts12IrradErr571);
  
  gr571_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr571_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr571_cycletempIrrad -> SetMarkerStyle(20);
  gr571_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr571_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr571_cycletempValveOpen = new TGraphErrors (counts_571 , cycleNumberArray571, avets12ValveOpenArray571, 0 , ts12ValveOpenErr571);
  
  gr571_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr571_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr571_cycletempValveOpen -> SetMarkerStyle(20);
  gr571_cycletempValveOpen -> SetMarkerColor(2);
  gr571_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr571_cycletempIrrad -> Draw("AP");
  gr571_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c571_cycleNum -> cd(4);
  TGraphErrors *gr571_cyclecur = new TGraphErrors (counts_571 , cycleNumberArray571 , avecurArray571, 0, ErrcurArray571 );
  gr571_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr571_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr571_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr571_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr571_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr571_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr571_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr571_cyclecur -> SetMarkerStyle(20);
  gr571_cyclecur -> Draw("Ap");
  c571_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c571_counttemp = new TCanvas ("c571_counttemp" , "c571_counttemp " , 1200, 900);
  c571_counttemp -> SetLogy();

  TGraphErrors *gr571_countIrrad = new TGraphErrors (counts_571, avets12IrradArray571, UCNIntegralArray571, ts12IrradErr571, UCNIntegralErrArray571);
  gr571_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr571_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr571_countIrrad -> SetMarkerStyle(20);
  gr571_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr571_countIrrad -> GetXaxis()-> SetLimits(0.85, 1.1);
  gr571_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr571_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr571_HistIrrad = new TGraphErrors (counts_571, avets12IrradArray571, HistIntegralArray571, ts12IrradErr571, HistIntegralErrArray571);
  gr571_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr571_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr571_HistIrrad -> SetMarkerStyle(25);
  gr571_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr571_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr571_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr571_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr571_countValveOpen = new TGraphErrors (counts_571, avets12ValveOpenArray571, UCNIntegralArray571, ts12ValveOpenErr571, UCNIntegralErrArray571);
  gr571_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr571_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr571_countValveOpen -> SetMarkerStyle(20);
  gr571_countValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr571_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr571_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr571_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr571_HistValveOpen = new TGraphErrors (counts_571, avets12ValveOpenArray571, HistIntegralArray571, ts12ValveOpenErr571, HistIntegralErrArray571);
  gr571_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr571_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr571_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr571_HistValveOpen -> SetMarkerStyle(25);
  gr571_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr571_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr571_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr571_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr571_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr571_HistValveOpen -> SetMarkerColor(2);



  gr571_countIrrad -> Draw("AP");
  //gr571_countValveOpen -> Draw("p");
   gr571_HistIrrad -> Draw("p");
  //gr571_HistValveOpen -> Draw("p");
  leg3 -> Draw();

  
  //********************************************
  // ******
  //  572
  // ******
  

  TCanvas *c572_cylceNum =  new TCanvas("c572_cycleNum" , "c572_cycleNum " , 1200, 900);
  c572_cycleNum-> Divide(2,2);

  TPad *p572_1 = c572_cycleNum->cd(1);
  p572_1->SetLogy(); 
  TGraphErrors *gr572_cyclecounts = new TGraphErrors (counts_572 , cycleNumberArray572, UCNIntegralArray572, 0 , UCNIntegralErrArray572);
  gr572_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr572_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr572_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr572_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr572_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr572_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr572_cyclehist = new TGraphErrors(counts_572, cycleNumberArray572 , HistIntegralArray572, 0, HistIntegralErrArray572);
  
  gr572_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr572_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr572_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr572_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr572_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr572_cyclehist -> SetMarkerColor(2);
  gr572_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr572_cyclecountmanual = new TGraphErrors(counts_572, cycleNumberArray572 , UCNIntegralManualArray572, 0, UCNIntegralManualErrArray572);
  
  gr572_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr572_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr572_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr572_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr572_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr572_cyclecountmanual -> SetMarkerColor(1);
  gr572_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr572_cyclecounts -> Draw("Ap");
  gr572_cyclehist -> Draw("p");
  gr572_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c572_cycleNum -> cd(2);
  TGraphErrors *gr572_cycledelay = new TGraphErrors (counts_572 , cycleNumberArray572, delaytimeArray572, 0 , 0);
  gr572_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr572_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr572_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr572_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr572_cycledelay -> SetMarkerStyle(20);
  
  gr572_cycledelay -> Draw("Ap");
  
  
  c572_cycleNum -> cd(3);
  TGraphErrors *gr572_cycletempIrrad = new TGraphErrors (counts_572 , cycleNumberArray572, avets12IrradArray572, 0 , ts12IrradErr572);
  
  gr572_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr572_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr572_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr572_cycletempIrrad -> SetMarkerStyle(20);
  gr572_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr572_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr572_cycletempValveOpen = new TGraphErrors (counts_572 , cycleNumberArray572, avets12ValveOpenArray572, 0 , ts12ValveOpenErr572);
  
  gr572_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr572_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr572_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr572_cycletempValveOpen -> SetMarkerStyle(20);
  gr572_cycletempValveOpen -> SetMarkerColor(2);
  gr572_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr572_cycletempIrrad -> Draw("AP");
  gr572_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c572_cycleNum -> cd(4);
  TGraphErrors *gr572_cyclecur = new TGraphErrors (counts_572 , cycleNumberArray572 , avecurArray572, 0, ErrcurArray572 );
  gr572_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr572_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr572_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr572_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr572_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr572_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr572_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr572_cyclecur -> SetMarkerStyle(20);
  gr572_cyclecur -> Draw("Ap");
  c572_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c572_counttemp = new TCanvas ("c572_counttemp" , "c572_counttemp " , 1200, 900);
  c572_counttemp -> SetLogy();

  TGraphErrors *gr572_countIrrad = new TGraphErrors (counts_572, avets12IrradArray572, UCNIntegralArray572, ts12IrradErr572, UCNIntegralErrArray572);
  gr572_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr572_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr572_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr572_countIrrad -> SetMarkerStyle(20);
  gr572_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr572_countIrrad -> GetXaxis() -> SetLimits(0.85, 1.1);
  gr572_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr572_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr572_HistIrrad = new TGraphErrors (counts_572, avets12IrradArray572, HistIntegralArray572, ts12IrradErr572, HistIntegralErrArray572);
  gr572_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr572_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr572_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr572_HistIrrad -> SetMarkerStyle(25);
  gr572_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr572_HistIrrad -> GetXaxis() -> SetLimits(1, 1.4);
  gr572_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr572_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

 TGraphErrors *gr572_countValveOpen = new TGraphErrors (counts_572, avets12ValveOpenArray572, UCNIntegralArray572, ts12ValveOpenErr572, UCNIntegralErrArray572);
  gr572_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr572_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr572_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr572_countValveOpen -> SetMarkerStyle(20);
  gr572_countValveOpen -> GetXaxis() -> SetLimits(0.84, 2.3);
  gr572_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr572_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr572_countValveOpen -> SetMarkerColor(2);


   TGraphErrors *gr572_HistValveOpen = new TGraphErrors (counts_572, avets12ValveOpenArray572, HistIntegralArray572, ts12ValveOpenErr572, HistIntegralErrArray572);
  gr572_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr572_HistValveOpen -> GetXaxis() -> SetTitle("Average Isopure Temperature (K)" );
  gr572_HistValveOpen -> GetYaxis() -> SetTitle("UCN Counts");
  gr572_HistValveOpen -> SetMarkerStyle(25);
  gr572_HistValveOpen -> GetXaxis() -> SetLimits(0.84, 2.3);
  gr572_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr572_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr572_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr572_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr572_HistValveOpen -> SetMarkerColor(2);



  gr572_countIrrad -> Draw("AP");
  //gr572_countValveOpen -> Draw("p");
   gr572_HistIrrad -> Draw("p");
  //gr572_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  
  
  // *******************************************
  // OVERALL
  // ******************************************

  // online analysis

  double irradOnline[100] = {10, 10, 10, 20, 20, 20, 30, 30, 30, 40, 40, 40, 50, 50, 50, 60, 60, 60, 80, 80, 80, 100, 100, 100, 120, 120, 120, 150, 150, 150 };

  double countsOnline[100] = {14015, 13658, 13764, 23507, 23682, 23026, 30489, 29814, 30518, 35465, 34632, 35041, 38704, 39412, 38999, 41790, 42082, 41584, 45070, 44639, 44133, 47569, 47205, 46749, 48915, 48302, 47670, 48426, 48872, 48231 };

  // double irradAll[40] = {10, 20, 30, 40 , 50, 100 , 60, 120 , 80, 150};

  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);
  //cAll -> SetLogy();

  TGraphErrors *gr_counts = new TGraphErrors (29, irradArray, UCNIntegralAll, 0 , UCNIntegralErrAll);
  gr_counts -> SetTitle( "UCN Counts vs irradiation time");
  gr_counts -> GetXaxis() -> SetTitle("Irradiation Time (s)" );
  gr_counts -> GetYaxis() -> SetTitle("UCN Counts");
  gr_counts -> GetYaxis() -> SetRangeUser (10, 500000);
  gr_counts -> SetMarkerStyle(20);
  gr_counts -> GetXaxis() -> SetLimits(0, 170);
  gr_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr_counts -> GetXaxis() -> SetTitleOffset(1.0);
  gr_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr_counts -> GetYaxis() -> SetTitleOffset(0.9);
  gr_counts -> SetMarkerColor(1);
  
  TGraphErrors *gr_countsmanual = new TGraphErrors (29, irradArray, UCNIntegralManualAll, 0 , UCNIntegralManualErrAll);
  gr_countsmanual -> SetTitle( "UCN Counts vs irradiation time");
  gr_countsmanual -> GetXaxis() -> SetTitle("Irradiation Time (s)" );
  gr_countsmanual -> GetYaxis() -> SetTitle("UCN Counts");
  gr_countsmanual -> SetMarkerStyle(20);
  gr_countsmanual -> GetXaxis() -> SetLimits(0, 170);
  gr_countsmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr_countsmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr_countsmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr_countsmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr_countsmanual -> SetMarkerColor(2);


  TGraphErrors *gr_hist = new TGraphErrors (29, irradArray, HistIntegralAll, 0 , HistIntegralErrAll);
  gr_hist -> SetTitle( "UCN Counts vs irradiation time");
  gr_hist -> GetXaxis() -> SetTitle("Irradiation Time (s)" );
  gr_hist -> GetYaxis() -> SetTitle("UCN Counts");
  gr_hist -> SetMarkerStyle(25);
  gr_hist -> GetXaxis() -> SetLimits(0, 170);
  gr_hist -> GetXaxis() -> SetTitleSize(0.05);
  gr_hist -> GetXaxis() -> SetTitleOffset(1.0);
  gr_hist -> GetYaxis() -> SetTitleSize(0.05); 
  gr_hist -> GetYaxis() -> SetTitleOffset(0.9);
  gr_hist -> SetMarkerColor(1);

  TGraphErrors *gr_online = new TGraphErrors (30, irradOnline, countsOnline, 0 , 0);
  gr_online -> SetTitle( "UCN Counts vs irradiation time");
  gr_online -> GetXaxis() -> SetTitle("Irradiation Time (s)" );
  gr_online -> GetYaxis() -> SetTitle("UCN Counts");
  gr_online -> SetMarkerStyle(3);
  gr_online -> GetXaxis() -> SetLimits(0, 170);
  gr_online -> GetXaxis() -> SetTitleSize(0.05);
  gr_online -> GetXaxis() -> SetTitleOffset(1.0);
  gr_online -> GetYaxis() -> SetTitleSize(0.05); 
  gr_online -> GetYaxis() -> SetTitleOffset(0.9);
  gr_online -> SetMarkerColor(8);

  TLegend *legAll = new TLegend(0.7, 0.7, 0.9, 0.9);
  legAll -> AddEntry(gr_counts, "Counts without background (fit)" , "p");
  legAll -> AddEntry(gr_countsmanual, "Counts without background" , "p");
  legAll -> AddEntry(gr_hist , "Counts with background" , "p");
  legAll -> AddEntry(gr_online, "Online Analysis" , "P");

  gr_counts -> Draw("ap");
  gr_countsmanual -> Draw("p");
  gr_hist -> Draw("p");
  gr_online -> Draw("p");
  legAll -> Draw();
  
}
