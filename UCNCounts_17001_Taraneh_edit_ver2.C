// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17001.
// FOR THE SECOND PASS OF ANALYSIS
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17001_Taraneh_edit_ver2(){
  
  // Read the files in ...
  TFile *fin524 = new TFile ("./2ndpass/outputTree_524.root", "READ");
  TFile *fin525 = new TFile ("./2ndpass/outputTree_525.root", "READ");
  TFile *fin526 = new TFile ("./2ndpass/outputTree_526.root", "READ");
  TFile *fin527 = new TFile ("./2ndpass/outputTree_527.root", "READ");
  TFile *fin528 = new TFile ("./2ndpass/outputTree_528.root", "READ");
  TFile *fin529 = new TFile ("./2ndpass/outputTree_529.root", "READ");
  TFile *fin530 = new TFile ("./2ndpass/outputTree_530.root", "READ");

  // Get the cycle_info tree
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


  double cycleValveOpenTime524;
  double cycleValveOpenTime525;
  double cycleValveOpenTime526;
  double cycleValveOpenTime527;
  double cycleValveOpenTime528;
  double cycleValveOpenTime529;
  double cycleValveOpenTime530;
  outputTree524 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime524);
  outputTree525 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime525);
  outputTree526 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime526);
  outputTree527 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime527);
  outputTree528 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime528);
  outputTree529 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime529);
  outputTree530 -> SetBranchAddress("cycleValveOpenTime" , &cycleValveOpenTime530);


  double cycleValveCloseTime524;
  double cycleValveCloseTime525;
  double cycleValveCloseTime526;
  double cycleValveCloseTime527;
  double cycleValveCloseTime528;
  double cycleValveCloseTime529;
  double cycleValveCloseTime530;
  outputTree524 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime524);
  outputTree525 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime525);
  outputTree526 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime526);
  outputTree527 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime527);
  outputTree528 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime528);
  outputTree529 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime529);
  outputTree530 -> SetBranchAddress("cycleValveCloseTime" , &cycleValveCloseTime530);

  
  
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

  // Average temperature during irradiation time
  double avets11Irrad524;
  double avets11Irrad525;
  double avets11Irrad526;
  double avets11Irrad527;
  double avets11Irrad528;
  double avets11Irrad529;
  double avets11Irrad530;
  outputTree524 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad524);
  outputTree525 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad525);
  outputTree526 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad526);
  outputTree527 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad527);
  outputTree528 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad528);
  outputTree529 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad529);
  outputTree530 -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad530);
  double avets11IrradArray524 [100];
  double avets11IrradArray525 [100];
  double avets11IrradArray526 [100];
  double avets11IrradArray527 [100];
  double avets11IrradArray528 [100];
  double avets11IrradArray529 [100];
  double avets11IrradArray530 [100];

  
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

  double avets14Irrad524;
  double avets14Irrad525;
  double avets14Irrad526;
  double avets14Irrad527;
  double avets14Irrad528;
  double avets14Irrad529;
  double avets14Irrad530;
  outputTree524 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad524);
  outputTree525 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad525);
  outputTree526 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad526);
  outputTree527 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad527);
  outputTree528 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad528);
  outputTree529 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad529);
  outputTree530 -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad530);
  double avets14IrradArray524 [100];
  double avets14IrradArray525 [100];
  double avets14IrradArray526 [100];
  double avets14IrradArray527 [100];
  double avets14IrradArray528 [100];
  double avets14IrradArray529 [100];
  double avets14IrradArray530 [100];

  double avets16Irrad524;
  double avets16Irrad525;
  double avets16Irrad526;
  double avets16Irrad527;
  double avets16Irrad528;
  double avets16Irrad529;
  double avets16Irrad530;
  outputTree524 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad524);
  outputTree525 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad525);
  outputTree526 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad526);
  outputTree527 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad527);
  outputTree528 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad528);
  outputTree529 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad529);
  outputTree530 -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad530);
  double avets16IrradArray524 [100];
  double avets16IrradArray525 [100];
  double avets16IrradArray526 [100];
  double avets16IrradArray527 [100];
  double avets16IrradArray528 [100];
  double avets16IrradArray529 [100];
  double avets16IrradArray530 [100];
  
  // Average temperature during valve open time
  double avets11ValveOpen524;
  double avets11ValveOpen525;
  double avets11ValveOpen526;
  double avets11ValveOpen527;
  double avets11ValveOpen528;
  double avets11ValveOpen529;
  double avets11ValveOpen530;
  outputTree524 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen524);
  outputTree525 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen525);
  outputTree526 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen526);
  outputTree527 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen527);
  outputTree528 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen528);
  outputTree529 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen529);
  outputTree530 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen530);
  double avets11ValveOpenArray524 [100];
  double avets11ValveOpenArray525 [100];
  double avets11ValveOpenArray526 [100];
  double avets11ValveOpenArray527 [100];
  double avets11ValveOpenArray528 [100];
  double avets11ValveOpenArray529 [100];
  double avets11ValveOpenArray530 [100];


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


  double avets14ValveOpen524;
  double avets14ValveOpen525;
  double avets14ValveOpen526;
  double avets14ValveOpen527;
  double avets14ValveOpen528;
  double avets14ValveOpen529;
  double avets14ValveOpen530;
  outputTree524 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen524);
  outputTree525 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen525);
  outputTree526 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen526);
  outputTree527 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen527);
  outputTree528 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen528);
  outputTree529 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen529);
  outputTree530 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen530);
  double avets14ValveOpenArray524 [100];
  double avets14ValveOpenArray525 [100];
  double avets14ValveOpenArray526 [100];
  double avets14ValveOpenArray527 [100];
  double avets14ValveOpenArray528 [100];
  double avets14ValveOpenArray529 [100];
  double avets14ValveOpenArray530 [100];


  double avets16ValveOpen524;
  double avets16ValveOpen525;
  double avets16ValveOpen526;
  double avets16ValveOpen527;
  double avets16ValveOpen528;
  double avets16ValveOpen529;
  double avets16ValveOpen530;
  outputTree524 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen524);
  outputTree525 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen525);
  outputTree526 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen526);
  outputTree527 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen527);
  outputTree528 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen528);
  outputTree529 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen529);
  outputTree530 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen530);
  double avets16ValveOpenArray524 [100];
  double avets16ValveOpenArray525 [100];
  double avets16ValveOpenArray526 [100];
  double avets16ValveOpenArray527 [100];
  double avets16ValveOpenArray528 [100];
  double avets16ValveOpenArray529 [100];
  double avets16ValveOpenArray530 [100];
  


  // Maximum temperture during irradiation time
  double maxts11Irrad524;
  double maxts11Irrad525;
  double maxts11Irrad526;
  double maxts11Irrad527;
  double maxts11Irrad528;
  double maxts11Irrad529;
  double maxts11Irrad530;
  outputTree524 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad524);
  outputTree525 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad525);
  outputTree526 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad526);
  outputTree527 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad527);
  outputTree528 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad528);
  outputTree529 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad529);
  outputTree530 -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad530);

  
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

  double maxts14Irrad524;
  double maxts14Irrad525;
  double maxts14Irrad526;
  double maxts14Irrad527;
  double maxts14Irrad528;
  double maxts14Irrad529;
  double maxts14Irrad530;
  outputTree524 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad524);
  outputTree525 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad525);
  outputTree526 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad526);
  outputTree527 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad527);
  outputTree528 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad528);
  outputTree529 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad529);
  outputTree530 -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad530);


  double maxts16Irrad524;
  double maxts16Irrad525;
  double maxts16Irrad526;
  double maxts16Irrad527;
  double maxts16Irrad528;
  double maxts16Irrad529;
  double maxts16Irrad530;
  outputTree524 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad524);
  outputTree525 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad525);
  outputTree526 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad526);
  outputTree527 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad527);
  outputTree528 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad528);
  outputTree529 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad529);
  outputTree530 -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad530);

  // Maximum temperature during valve open time  
  double maxts11ValveOpen524;
  double maxts11ValveOpen525;
  double maxts11ValveOpen526;
  double maxts11ValveOpen527;
  double maxts11ValveOpen528;
  double maxts11ValveOpen529;
  double maxts11ValveOpen530;
  outputTree524 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen524);
  outputTree525 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen525);
  outputTree526 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen526);
  outputTree527 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen527);
  outputTree528 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen528);
  outputTree529 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen529);
  outputTree530 -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen530);


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


  double maxts14ValveOpen524;
  double maxts14ValveOpen525;
  double maxts14ValveOpen526;
  double maxts14ValveOpen527;
  double maxts14ValveOpen528;
  double maxts14ValveOpen529;
  double maxts14ValveOpen530;
  outputTree524 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen524);
  outputTree525 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen525);
  outputTree526 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen526);
  outputTree527 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen527);
  outputTree528 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen528);
  outputTree529 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen529);
  outputTree530 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen530);


  double maxts16ValveOpen524;
  double maxts16ValveOpen525;
  double maxts16ValveOpen526;
  double maxts16ValveOpen527;
  double maxts16ValveOpen528;
  double maxts16ValveOpen529;
  double maxts16ValveOpen530;
  outputTree524 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen524);
  outputTree525 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen525);
  outputTree526 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen526);
  outputTree527 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen527);
  outputTree528 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen528);
  outputTree529 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen529);
  outputTree530 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen530);

  
  // Minimum temperature during irradiation time
  double mints11Irrad524;
  double mints11Irrad525;
  double mints11Irrad526;
  double mints11Irrad527;
  double mints11Irrad528;
  double mints11Irrad529;
  double mints11Irrad530;
  outputTree524 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad524);
  outputTree525 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad525);
  outputTree526 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad526);
  outputTree527 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad527);
  outputTree528 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad528);
  outputTree529 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad529);
  outputTree530 -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad530);


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


  double mints14Irrad524;
  double mints14Irrad525;
  double mints14Irrad526;
  double mints14Irrad527;
  double mints14Irrad528;
  double mints14Irrad529;
  double mints14Irrad530;
  outputTree524 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad524);
  outputTree525 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad525);
  outputTree526 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad526);
  outputTree527 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad527);
  outputTree528 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad528);
  outputTree529 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad529);
  outputTree530 -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad530);


  double mints16Irrad524;
  double mints16Irrad525;
  double mints16Irrad526;
  double mints16Irrad527;
  double mints16Irrad528;
  double mints16Irrad529;
  double mints16Irrad530;
  outputTree524 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad524);
  outputTree525 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad525);
  outputTree526 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad526);
  outputTree527 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad527);
  outputTree528 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad528);
  outputTree529 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad529);
  outputTree530 -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad530);
    
  // Minimum temperature during valve open time
  double mints11ValveOpen524;
  double mints11ValveOpen525;
  double mints11ValveOpen526;
  double mints11ValveOpen527;
  double mints11ValveOpen528;
  double mints11ValveOpen529;
  double mints11ValveOpen530;
  outputTree524 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen524);
  outputTree525 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen525);
  outputTree526 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen526);
  outputTree527 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen527);
  outputTree528 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen528);
  outputTree529 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen529);
  outputTree530 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen530);


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


  double mints14ValveOpen524;
  double mints14ValveOpen525;
  double mints14ValveOpen526;
  double mints14ValveOpen527;
  double mints14ValveOpen528;
  double mints14ValveOpen529;
  double mints14ValveOpen530;
  outputTree524 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen524);
  outputTree525 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen525);
  outputTree526 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen526);
  outputTree527 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen527);
  outputTree528 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen528);
  outputTree529 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen529);
  outputTree530 -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen530);


  double mints16ValveOpen524;
  double mints16ValveOpen525;
  double mints16ValveOpen526;
  double mints16ValveOpen527;
  double mints16ValveOpen528;
  double mints16ValveOpen529;
  double mints16ValveOpen530;
  outputTree524 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen524);
  outputTree525 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen525);
  outputTree526 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen526);
  outputTree527 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen527);
  outputTree528 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen528);
  outputTree529 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen529);
  outputTree530 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen530);
  
  // Error in the temperature during irradiation

  double ts11IrradErr524 [100];
  double ts11IrradErr525 [100];
  double ts11IrradErr526 [100];
  double ts11IrradErr527 [100];
  double ts11IrradErr528 [100];
  double ts11IrradErr529 [100];
  double ts11IrradErr530 [100];
  
  double ts12IrradErr524 [100];
  double ts12IrradErr525 [100];
  double ts12IrradErr526 [100];
  double ts12IrradErr527 [100];
  double ts12IrradErr528 [100];
  double ts12IrradErr529 [100];
  double ts12IrradErr530 [100];

  double ts14IrradErr524 [100];
  double ts14IrradErr525 [100];
  double ts14IrradErr526 [100];
  double ts14IrradErr527 [100];
  double ts14IrradErr528 [100];
  double ts14IrradErr529 [100];
  double ts14IrradErr530 [100];

  double ts16IrradErr524 [100];
  double ts16IrradErr525 [100];
  double ts16IrradErr526 [100];
  double ts16IrradErr527 [100];
  double ts16IrradErr528 [100];
  double ts16IrradErr529 [100];
  double ts16IrradErr530 [100];

  // Error in temperature during the valve open time
  double ts11ValveOpenErr524 [100];
  double ts11ValveOpenErr525 [100];
  double ts11ValveOpenErr526 [100];
  double ts11ValveOpenErr527 [100];
  double ts11ValveOpenErr528 [100];
  double ts11ValveOpenErr529 [100];
  double ts11ValveOpenErr530 [100];

  
  double ts12ValveOpenErr524 [100];
  double ts12ValveOpenErr525 [100];
  double ts12ValveOpenErr526 [100];
  double ts12ValveOpenErr527 [100];
  double ts12ValveOpenErr528 [100];
  double ts12ValveOpenErr529 [100];
  double ts12ValveOpenErr530 [100];


  double ts14ValveOpenErr524 [100];
  double ts14ValveOpenErr525 [100];
  double ts14ValveOpenErr526 [100];
  double ts14ValveOpenErr527 [100];
  double ts14ValveOpenErr528 [100];
  double ts14ValveOpenErr529 [100];
  double ts14ValveOpenErr530 [100];

  double ts16ValveOpenErr524 [100];
  double ts16ValveOpenErr525 [100];
  double ts16ValveOpenErr526 [100];
  double ts16ValveOpenErr527 [100];
  double ts16ValveOpenErr528 [100];
  double ts16ValveOpenErr529 [100];
  double ts16ValveOpenErr530 [100];



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


  double ErrcurArray524 [100];
  double ErrcurArray525 [100];
  double ErrcurArray526 [100];
  double ErrcurArray527 [100];
  double ErrcurArray528 [100];
  double ErrcurArray529 [100];
  double ErrcurArray530 [100];

  double BASELINERATE524;
  double BASELINERATE525;
  double BASELINERATE526;
  double BASELINERATE527;
  double BASELINERATE528;
  double BASELINERATE529;
  double BASELINERATE530;
  outputTree524 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE524);
  outputTree525 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE525);
  outputTree526 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE526);
  outputTree527 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE527);
  outputTree528 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE528);
  outputTree529 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE529);
  outputTree530 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE530);

  

  double UCNIntegralManualArray524 [100];
  double UCNIntegralManualArray525 [100];
  double UCNIntegralManualArray526 [100];
  double UCNIntegralManualArray527 [100];
  double UCNIntegralManualArray528 [100];
  double UCNIntegralManualArray529 [100];
  double UCNIntegralManualArray530 [100];

  
  double UCNIntegralManualErrArray524[100];
  double UCNIntegralManualErrArray525[100];
  double UCNIntegralManualErrArray526[100];
  double UCNIntegralManualErrArray527[100];
  double UCNIntegralManualErrArray528[100];
  double UCNIntegralManualErrArray529[100];
  double UCNIntegralManualErrArray530[100];


  int counts_524 = 0;
  int counts_525 = 0;
  int counts_526 = 0;
  int counts_527 = 0;
  int counts_528 = 0;
  int counts_529 = 0;
  int counts_530 = 0;


  // Write to a file

  ofstream myfile;
  myfile.open ("./2ndpass/TCN17001_Data.csv");
  


  // ********************************************************
  // *****
  // 524
  // *****
  
  
  ULong64_t events524;
  events524 = (Double_t) outputTree524 -> GetEntries();

  for (ULong64_t j = 0 ; j < events524 ; j++){
    outputTree524 -> GetEvent(j);
    HistIntegralArray524[counts_524] = HistIntegral524;
    HistIntegralErrArray524[counts_524] = sqrt (HistIntegral524);
    UCNIntegralManualArray524[counts_524] = HistIntegral524 - BASELINERATE524 * (cycleValveCloseTime524 - cycleValveOpenTime524);
    UCNIntegralManualErrArray524[counts_524] = sqrt(UCNIntegralManualArray524[counts_524]);
    
    avets11IrradArray524[counts_524] = avets11Irrad524;
    avets12IrradArray524[counts_524] = avets12Irrad524;
    avets14IrradArray524[counts_524] = avets14Irrad524;
    avets16IrradArray524[counts_524] = avets16Irrad524;

    avets11ValveOpenArray524[counts_524] = avets11ValveOpen524;
    avets12ValveOpenArray524[counts_524] = avets12ValveOpen524;
    avets14ValveOpenArray524[counts_524] = avets14ValveOpen524;
    avets16ValveOpenArray524[counts_524] = avets16ValveOpen524;
    
    ts11IrradErr524[counts_524] = (maxts11Irrad524 - mints11Irrad524)/2;
    ts12IrradErr524[counts_524] = (maxts12Irrad524 - mints12Irrad524)/2;
    ts14IrradErr524[counts_524] = (maxts14Irrad524 - mints14Irrad524)/2;
    ts16IrradErr524[counts_524] = (maxts16Irrad524 - mints16Irrad524)/2;
    
    ts11ValveOpenErr524[counts_524] = (maxts11ValveOpen524 - mints11ValveOpen524)/2;
    ts12ValveOpenErr524[counts_524] = (maxts12ValveOpen524 - mints12ValveOpen524)/2;
    ts14ValveOpenErr524[counts_524] = (maxts14ValveOpen524 - mints14ValveOpen524)/2;
    ts16ValveOpenErr524[counts_524] = (maxts16ValveOpen524 - mints16ValveOpen524)/2;

    
    avecurArray524[counts_524] = avecur524;
    ErrcurArray524[counts_524] = (maxcur524 - mincur524)/2;
    
    delaytimeArray524[counts_524] = cycleDelayTime524;
    cycleNumberArray524[counts_524] = cycleNumber524;
    cout << " The irradiation time for run 524 for cycle "<< counts_524 << " is "<< cycleStartTimes524 - irradStartTimes524 << endl;
    
    myfile << HistIntegralArray524[counts_524] << " " << HistIntegralErrArray524[counts_524] << " " << UCNIntegralManualArray524[counts_524] << " " << UCNIntegralManualErrArray524[counts_524] << " " << avecurArray524[counts_524] << " " <<  ErrcurArray524[counts_524] << " " <<  avets11IrradArray524[counts_524] << " " << ts11IrradErr524[counts_524] << " " << avets12IrradArray524[counts_524] << " " << ts12IrradErr524[counts_524] << " " << avets14IrradArray524[counts_524] << " " << ts14IrradErr524[counts_524] << " " << avets16IrradArray524[counts_524] << " " << ts16IrradErr524[counts_524] << " " << avets11ValveOpenArray524[counts_524] << " " <<  ts11ValveOpenErr524[counts_524] << " " << avets12ValveOpenArray524[counts_524] << " " << ts12ValveOpenErr524[counts_524] << " " << avets14ValveOpenArray524[counts_524] << " " << ts14ValveOpenErr524[counts_524] << " " << avets16ValveOpenArray524[counts_524] << " " << ts16ValveOpenErr524[counts_524] << endl;
    counts_524++;
  }


  // *****
  // 525
  // *****
  
  
  ULong64_t events525;
  events525 = (Double_t) outputTree525 -> GetEntries();

  for (ULong64_t j = 0 ; j < events525 ; j++){
    outputTree525 -> GetEvent(j);
    HistIntegralArray525[counts_525] = HistIntegral525;
    HistIntegralErrArray525[counts_525] = sqrt (HistIntegral525);
    UCNIntegralManualArray525[counts_525] = HistIntegral525 - BASELINERATE525 * (cycleValveCloseTime525 - cycleValveOpenTime525);
    UCNIntegralManualErrArray525[counts_525] = sqrt(UCNIntegralManualArray525[counts_525]);
    
    avets11IrradArray525[counts_525] = avets11Irrad525;
    avets12IrradArray525[counts_525] = avets12Irrad525;
    avets14IrradArray525[counts_525] = avets14Irrad525;
    avets16IrradArray525[counts_525] = avets16Irrad525;

    avets11ValveOpenArray525[counts_525] = avets11ValveOpen525;
    avets12ValveOpenArray525[counts_525] = avets12ValveOpen525;
    avets14ValveOpenArray525[counts_525] = avets14ValveOpen525;
    avets16ValveOpenArray525[counts_525] = avets16ValveOpen525;
    
    ts11IrradErr525[counts_525] = (maxts11Irrad525 - mints11Irrad525)/2;
    ts12IrradErr525[counts_525] = (maxts12Irrad525 - mints12Irrad525)/2;
    ts14IrradErr525[counts_525] = (maxts14Irrad525 - mints14Irrad525)/2;
    ts16IrradErr525[counts_525] = (maxts16Irrad525 - mints16Irrad525)/2;
    
    ts11ValveOpenErr525[counts_525] = (maxts11ValveOpen525 - mints11ValveOpen525)/2;
    ts12ValveOpenErr525[counts_525] = (maxts12ValveOpen525 - mints12ValveOpen525)/2;
    ts14ValveOpenErr525[counts_525] = (maxts14ValveOpen525 - mints14ValveOpen525)/2;
    ts16ValveOpenErr525[counts_525] = (maxts16ValveOpen525 - mints16ValveOpen525)/2;

    
    avecurArray525[counts_525] = avecur525;
    ErrcurArray525[counts_525] = (maxcur525 - mincur525)/2;
    
    delaytimeArray525[counts_525] = cycleDelayTime525;
    cycleNumberArray525[counts_525] = cycleNumber525;
    cout << " The irradiation time for run 525 for cycle "<< counts_525 << " is "<< cycleStartTimes525 - irradStartTimes525 << endl;

    myfile << HistIntegralArray525[counts_525] << " " << HistIntegralErrArray525[counts_525] << " " << UCNIntegralManualArray525[counts_525] << " " << UCNIntegralManualErrArray525[counts_525] << " " << avecurArray525[counts_525] << " " <<  ErrcurArray525[counts_525] << " " <<  avets11IrradArray525[counts_525] << " " << ts11IrradErr525[counts_525] << " " << avets12IrradArray525[counts_525] << " " << ts12IrradErr525[counts_525] << " " << avets14IrradArray525[counts_525] << " " << ts14IrradErr525[counts_525] << " " << avets16IrradArray525[counts_525] << " " << ts16IrradErr525[counts_525] << " " << avets11ValveOpenArray525[counts_525] << " " <<  ts11ValveOpenErr525[counts_525] << " " << avets12ValveOpenArray525[counts_525] << " " << ts12ValveOpenErr525[counts_525] << " " << avets14ValveOpenArray525[counts_525] << " " << ts14ValveOpenErr525[counts_525] << " " << avets16ValveOpenArray525[counts_525] << " " << ts16ValveOpenErr525[counts_525] << endl;
    
    counts_525++;
  }


  // *****
  // 526
  // *****
  
    
  ULong64_t events526;
  events526 = (Double_t) outputTree526 -> GetEntries();

  for (ULong64_t j = 0 ; j < events526 ; j++){
    outputTree526 -> GetEvent(j);
    HistIntegralArray526[counts_526] = HistIntegral526;
    HistIntegralErrArray526[counts_526] = sqrt (HistIntegral526);
    UCNIntegralManualArray526[counts_526] = HistIntegral526 - BASELINERATE526 * (cycleValveCloseTime526 - cycleValveOpenTime526);
    UCNIntegralManualErrArray526[counts_526] = sqrt(UCNIntegralManualArray526[counts_526]);
    
    avets11IrradArray526[counts_526] = avets11Irrad526;
    avets12IrradArray526[counts_526] = avets12Irrad526;
    avets14IrradArray526[counts_526] = avets14Irrad526;
    avets16IrradArray526[counts_526] = avets16Irrad526;

    avets11ValveOpenArray526[counts_526] = avets11ValveOpen526;
    avets12ValveOpenArray526[counts_526] = avets12ValveOpen526;
    avets14ValveOpenArray526[counts_526] = avets14ValveOpen526;
    avets16ValveOpenArray526[counts_526] = avets16ValveOpen526;
    
    ts11IrradErr526[counts_526] = (maxts11Irrad526 - mints11Irrad526)/2;
    ts12IrradErr526[counts_526] = (maxts12Irrad526 - mints12Irrad526)/2;
    ts14IrradErr526[counts_526] = (maxts14Irrad526 - mints14Irrad526)/2;
    ts16IrradErr526[counts_526] = (maxts16Irrad526 - mints16Irrad526)/2;
    
    ts11ValveOpenErr526[counts_526] = (maxts11ValveOpen526 - mints11ValveOpen526)/2;
    ts12ValveOpenErr526[counts_526] = (maxts12ValveOpen526 - mints12ValveOpen526)/2;
    ts14ValveOpenErr526[counts_526] = (maxts14ValveOpen526 - mints14ValveOpen526)/2;
    ts16ValveOpenErr526[counts_526] = (maxts16ValveOpen526 - mints16ValveOpen526)/2;

    
    avecurArray526[counts_526] = avecur526;
    ErrcurArray526[counts_526] = (maxcur526 - mincur526)/2;
    
    delaytimeArray526[counts_526] = cycleDelayTime526;
    cycleNumberArray526[counts_526] = cycleNumber526;
    cout << " The irradiation time for run 526 for cycle "<< counts_526 << " is "<< cycleStartTimes526 - irradStartTimes526 << endl;

    myfile << HistIntegralArray526[counts_526] << " " << HistIntegralErrArray526[counts_526] << " " << UCNIntegralManualArray526[counts_526] << " " << UCNIntegralManualErrArray526[counts_526] << " " << avecurArray526[counts_526] << " " <<  ErrcurArray526[counts_526] << " " <<  avets11IrradArray526[counts_526] << " " << ts11IrradErr526[counts_526] << " " << avets12IrradArray526[counts_526] << " " << ts12IrradErr526[counts_526] << " " << avets14IrradArray526[counts_526] << " " << ts14IrradErr526[counts_526] << " " << avets16IrradArray526[counts_526] << " " << ts16IrradErr526[counts_526] << " " << avets11ValveOpenArray526[counts_526] << " " <<  ts11ValveOpenErr526[counts_526] << " " << avets12ValveOpenArray526[counts_526] << " " << ts12ValveOpenErr526[counts_526] << " " << avets14ValveOpenArray526[counts_526] << " " << ts14ValveOpenErr526[counts_526] << " " << avets16ValveOpenArray526[counts_526] << " " << ts16ValveOpenErr526[counts_526] << endl;
    
    counts_526++;
  }



  // *****
  // 527
  // *****
  
      
  ULong64_t events527;
  events527 = (Double_t) outputTree527 -> GetEntries();

  for (ULong64_t j = 0 ; j < events527 ; j++){
    outputTree527 -> GetEvent(j);
    HistIntegralArray527[counts_527] = HistIntegral527;
    HistIntegralErrArray527[counts_527] = sqrt (HistIntegral527);
    UCNIntegralManualArray527[counts_527] = HistIntegral527 - BASELINERATE527 * (cycleValveCloseTime527 - cycleValveOpenTime527);
    UCNIntegralManualErrArray527[counts_527] = sqrt(UCNIntegralManualArray527[counts_527]);
    
    avets11IrradArray527[counts_527] = avets11Irrad527;
    avets12IrradArray527[counts_527] = avets12Irrad527;
    avets14IrradArray527[counts_527] = avets14Irrad527;
    avets16IrradArray527[counts_527] = avets16Irrad527;

    avets11ValveOpenArray527[counts_527] = avets11ValveOpen527;
    avets12ValveOpenArray527[counts_527] = avets12ValveOpen527;
    avets14ValveOpenArray527[counts_527] = avets14ValveOpen527;
    avets16ValveOpenArray527[counts_527] = avets16ValveOpen527;
    
    ts11IrradErr527[counts_527] = (maxts11Irrad527 - mints11Irrad527)/2;
    ts12IrradErr527[counts_527] = (maxts12Irrad527 - mints12Irrad527)/2;
    ts14IrradErr527[counts_527] = (maxts14Irrad527 - mints14Irrad527)/2;
    ts16IrradErr527[counts_527] = (maxts16Irrad527 - mints16Irrad527)/2;
    
    ts11ValveOpenErr527[counts_527] = (maxts11ValveOpen527 - mints11ValveOpen527)/2;
    ts12ValveOpenErr527[counts_527] = (maxts12ValveOpen527 - mints12ValveOpen527)/2;
    ts14ValveOpenErr527[counts_527] = (maxts14ValveOpen527 - mints14ValveOpen527)/2;
    ts16ValveOpenErr527[counts_527] = (maxts16ValveOpen527 - mints16ValveOpen527)/2;

    
    avecurArray527[counts_527] = avecur527;
    ErrcurArray527[counts_527] = (maxcur527 - mincur527)/2;
    
    delaytimeArray527[counts_527] = cycleDelayTime527;
    cycleNumberArray527[counts_527] = cycleNumber527;
    cout << " The irradiation time for run 527 for cycle "<< counts_527 << " is "<< cycleStartTimes527 - irradStartTimes527 << endl;

    myfile << HistIntegralArray527[counts_527] << " " << HistIntegralErrArray527[counts_527] << " " << UCNIntegralManualArray527[counts_527] << " " << UCNIntegralManualErrArray527[counts_527] << " " << avecurArray527[counts_527] << " " <<  ErrcurArray527[counts_527] << " " <<  avets11IrradArray527[counts_527] << " " << ts11IrradErr527[counts_527] << " " << avets12IrradArray527[counts_527] << " " << ts12IrradErr527[counts_527] << " " << avets14IrradArray527[counts_527] << " " << ts14IrradErr527[counts_527] << " " << avets16IrradArray527[counts_527] << " " << ts16IrradErr527[counts_527] << " " << avets11ValveOpenArray527[counts_527] << " " <<  ts11ValveOpenErr527[counts_527] << " " << avets12ValveOpenArray527[counts_527] << " " << ts12ValveOpenErr527[counts_527] << " " << avets14ValveOpenArray527[counts_527] << " " << ts14ValveOpenErr527[counts_527] << " " << avets16ValveOpenArray527[counts_527] << " " << ts16ValveOpenErr527[counts_527] << endl;
    
    counts_527++;
  }


 


  // *****
  // 528
  // *****
  
        
  ULong64_t events528;
  events528 = (Double_t) outputTree528 -> GetEntries();

  for (ULong64_t j = 0 ; j < events528 ; j++){
    outputTree528 -> GetEvent(j);
    HistIntegralArray528[counts_528] = HistIntegral528;
    HistIntegralErrArray528[counts_528] = sqrt (HistIntegral528);
    UCNIntegralManualArray528[counts_528] = HistIntegral528 - BASELINERATE528 * (cycleValveCloseTime528 - cycleValveOpenTime528);
    UCNIntegralManualErrArray528[counts_528] = sqrt(UCNIntegralManualArray528[counts_528]);
    
    avets11IrradArray528[counts_528] = avets11Irrad528;
    avets12IrradArray528[counts_528] = avets12Irrad528;
    avets14IrradArray528[counts_528] = avets14Irrad528;
    avets16IrradArray528[counts_528] = avets16Irrad528;

    avets11ValveOpenArray528[counts_528] = avets11ValveOpen528;
    avets12ValveOpenArray528[counts_528] = avets12ValveOpen528;
    avets14ValveOpenArray528[counts_528] = avets14ValveOpen528;
    avets16ValveOpenArray528[counts_528] = avets16ValveOpen528;
    
    ts11IrradErr528[counts_528] = (maxts11Irrad528 - mints11Irrad528)/2;
    ts12IrradErr528[counts_528] = (maxts12Irrad528 - mints12Irrad528)/2;
    ts14IrradErr528[counts_528] = (maxts14Irrad528 - mints14Irrad528)/2;
    ts16IrradErr528[counts_528] = (maxts16Irrad528 - mints16Irrad528)/2;
    
    ts11ValveOpenErr528[counts_528] = (maxts11ValveOpen528 - mints11ValveOpen528)/2;
    ts12ValveOpenErr528[counts_528] = (maxts12ValveOpen528 - mints12ValveOpen528)/2;
    ts14ValveOpenErr528[counts_528] = (maxts14ValveOpen528 - mints14ValveOpen528)/2;
    ts16ValveOpenErr528[counts_528] = (maxts16ValveOpen528 - mints16ValveOpen528)/2;

    
    avecurArray528[counts_528] = avecur528;
    ErrcurArray528[counts_528] = (maxcur528 - mincur528)/2;
    
    delaytimeArray528[counts_528] = cycleDelayTime528;
    cycleNumberArray528[counts_528] = cycleNumber528;
    cout << " The irradiation time for run 528 for cycle "<< counts_528 << " is "<< cycleStartTimes528 - irradStartTimes528 << endl;

    myfile << HistIntegralArray528[counts_528] << " " << HistIntegralErrArray528[counts_528] << " " << UCNIntegralManualArray528[counts_528] << " " << UCNIntegralManualErrArray528[counts_528] << " " << avecurArray528[counts_528] << " " <<  ErrcurArray528[counts_528] << " " <<  avets11IrradArray528[counts_528] << " " << ts11IrradErr528[counts_528] << " " << avets12IrradArray528[counts_528] << " " << ts12IrradErr528[counts_528] << " " << avets14IrradArray528[counts_528] << " " << ts14IrradErr528[counts_528] << " " << avets16IrradArray528[counts_528] << " " << ts16IrradErr528[counts_528] << " " << avets11ValveOpenArray528[counts_528] << " " <<  ts11ValveOpenErr528[counts_528] << " " << avets12ValveOpenArray528[counts_528] << " " << ts12ValveOpenErr528[counts_528] << " " << avets14ValveOpenArray528[counts_528] << " " << ts14ValveOpenErr528[counts_528] << " " << avets16ValveOpenArray528[counts_528] << " " << ts16ValveOpenErr528[counts_528] << endl;
    
    counts_528++;
  }


  // *****
  // 529
  // *****
  
  ULong64_t events529;
  events529 = (Double_t) outputTree529 -> GetEntries();

  for (ULong64_t j = 0 ; j < events529 ; j++){
    outputTree529 -> GetEvent(j);
    HistIntegralArray529[counts_529] = HistIntegral529;
    HistIntegralErrArray529[counts_529] = sqrt (HistIntegral529);
    UCNIntegralManualArray529[counts_529] = HistIntegral529 - BASELINERATE529 * (cycleValveCloseTime529 - cycleValveOpenTime529);
    UCNIntegralManualErrArray529[counts_529] = sqrt(UCNIntegralManualArray529[counts_529]);
    
    avets11IrradArray529[counts_529] = avets11Irrad529;
    avets12IrradArray529[counts_529] = avets12Irrad529;
    avets14IrradArray529[counts_529] = avets14Irrad529;
    avets16IrradArray529[counts_529] = avets16Irrad529;

    avets11ValveOpenArray529[counts_529] = avets11ValveOpen529;
    avets12ValveOpenArray529[counts_529] = avets12ValveOpen529;
    avets14ValveOpenArray529[counts_529] = avets14ValveOpen529;
    avets16ValveOpenArray529[counts_529] = avets16ValveOpen529;
    
    ts11IrradErr529[counts_529] = (maxts11Irrad529 - mints11Irrad529)/2;
    ts12IrradErr529[counts_529] = (maxts12Irrad529 - mints12Irrad529)/2;
    ts14IrradErr529[counts_529] = (maxts14Irrad529 - mints14Irrad529)/2;
    ts16IrradErr529[counts_529] = (maxts16Irrad529 - mints16Irrad529)/2;
    
    ts11ValveOpenErr529[counts_529] = (maxts11ValveOpen529 - mints11ValveOpen529)/2;
    ts12ValveOpenErr529[counts_529] = (maxts12ValveOpen529 - mints12ValveOpen529)/2;
    ts14ValveOpenErr529[counts_529] = (maxts14ValveOpen529 - mints14ValveOpen529)/2;
    ts16ValveOpenErr529[counts_529] = (maxts16ValveOpen529 - mints16ValveOpen529)/2;

    
    avecurArray529[counts_529] = avecur529;
    ErrcurArray529[counts_529] = (maxcur529 - mincur529)/2;
    
    delaytimeArray529[counts_529] = cycleDelayTime529;
    cycleNumberArray529[counts_529] = cycleNumber529;
    cout << " The irradiation time for run 529 for cycle "<< counts_529 << " is "<< cycleStartTimes529 - irradStartTimes529 << endl;

    myfile << HistIntegralArray529[counts_529] << " " << HistIntegralErrArray529[counts_529] << " " << UCNIntegralManualArray529[counts_529] << " " << UCNIntegralManualErrArray529[counts_529] << " " << avecurArray529[counts_529] << " " <<  ErrcurArray529[counts_529] << " " <<  avets11IrradArray529[counts_529] << " " << ts11IrradErr529[counts_529] << " " << avets12IrradArray529[counts_529] << " " << ts12IrradErr529[counts_529] << " " << avets14IrradArray529[counts_529] << " " << ts14IrradErr529[counts_529] << " " << avets16IrradArray529[counts_529] << " " << ts16IrradErr529[counts_529] << " " << avets11ValveOpenArray529[counts_529] << " " <<  ts11ValveOpenErr529[counts_529] << " " << avets12ValveOpenArray529[counts_529] << " " << ts12ValveOpenErr529[counts_529] << " " << avets14ValveOpenArray529[counts_529] << " " << ts14ValveOpenErr529[counts_529] << " " << avets16ValveOpenArray529[counts_529] << " " << ts16ValveOpenErr529[counts_529] << endl;
    
    counts_529++;
  }

  // *****
  // 530
  // *****
  
  
  ULong64_t events530;
  events530 = (Double_t) outputTree530 -> GetEntries();

  for (ULong64_t j = 0 ; j < events530 ; j++){
    outputTree530 -> GetEvent(j);
    HistIntegralArray530[counts_530] = HistIntegral530;
    HistIntegralErrArray530[counts_530] = sqrt (HistIntegral530);
    UCNIntegralManualArray530[counts_530] = HistIntegral530 - BASELINERATE530 * (cycleValveCloseTime530 - cycleValveOpenTime530);
    UCNIntegralManualErrArray530[counts_530] = sqrt(UCNIntegralManualArray530[counts_530]);
    
    avets11IrradArray530[counts_530] = avets11Irrad530;
    avets12IrradArray530[counts_530] = avets12Irrad530;
    avets14IrradArray530[counts_530] = avets14Irrad530;
    avets16IrradArray530[counts_530] = avets16Irrad530;

    avets11ValveOpenArray530[counts_530] = avets11ValveOpen530;
    avets12ValveOpenArray530[counts_530] = avets12ValveOpen530;
    avets14ValveOpenArray530[counts_530] = avets14ValveOpen530;
    avets16ValveOpenArray530[counts_530] = avets16ValveOpen530;
    
    ts11IrradErr530[counts_530] = (maxts11Irrad530 - mints11Irrad530)/2;
    ts12IrradErr530[counts_530] = (maxts12Irrad530 - mints12Irrad530)/2;
    ts14IrradErr530[counts_530] = (maxts14Irrad530 - mints14Irrad530)/2;
    ts16IrradErr530[counts_530] = (maxts16Irrad530 - mints16Irrad530)/2;
    
    ts11ValveOpenErr530[counts_530] = (maxts11ValveOpen530 - mints11ValveOpen530)/2;
    ts12ValveOpenErr530[counts_530] = (maxts12ValveOpen530 - mints12ValveOpen530)/2;
    ts14ValveOpenErr530[counts_530] = (maxts14ValveOpen530 - mints14ValveOpen530)/2;
    ts16ValveOpenErr530[counts_530] = (maxts16ValveOpen530 - mints16ValveOpen530)/2;

    
    avecurArray530[counts_530] = avecur530;
    ErrcurArray530[counts_530] = (maxcur530 - mincur530)/2;
    
    delaytimeArray530[counts_530] = cycleDelayTime530;
    cycleNumberArray530[counts_530] = cycleNumber530;
    cout << " The irradiation time for run 530 for cycle "<< counts_530 << " is "<< cycleStartTimes530 - irradStartTimes530 << endl; 
    counts_530++;
  }

 
  
  // *******************
  //     GRAPHS
  // ******************

  // ******
  //  524
  // ******
  

  TCanvas *c524_cylceNum =  new TCanvas("c524_cycleNum" , "c524_cycleNum " , 1200, 900);
  c524_cycleNum-> Divide(2,2);

  TPad *p524_1 = c524_cycleNum->cd(1);
  p524_1->SetLogy(); 
  TGraphErrors *gr524_cyclehist = new TGraphErrors(counts_524, cycleNumberArray524 , HistIntegralArray524, 0, HistIntegralErrArray524);
  
  gr524_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr524_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr524_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr524_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr524_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_cyclehist -> SetMarkerColor(2);
  gr524_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr524_cyclecountmanual = new TGraphErrors(counts_524, cycleNumberArray524 , UCNIntegralManualArray524, 0, UCNIntegralManualErrArray524);
  
  gr524_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr524_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr524_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr524_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr524_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_cyclecountmanual -> SetMarkerColor(1);
  gr524_cyclecountmanual -> SetMarkerStyle(25);
  

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr524_cyclehist , "With Background" , "p") ;
  leg2 -> AddEntry(gr524_cyclecountmanual, "Without Background" , "p"); 
  leg2 -> SetTextSize(0.05);
  

  gr524_cyclehist -> Draw("Ap");
  gr524_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c524_cycleNum -> cd(2);
  TGraphErrors *gr524_cycledelay = new TGraphErrors (counts_524 , cycleNumberArray524, delaytimeArray524, 0 , 0);
  gr524_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr524_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr524_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr524_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr524_cycledelay -> SetMarkerStyle(20);
  
  gr524_cycledelay -> Draw("Ap");
  
  
  c524_cycleNum -> cd(3);
  TGraphErrors *gr524_cycletempIrrad = new TGraphErrors (counts_524 , cycleNumberArray524, avets12IrradArray524, 0 , ts12IrradErr524);
  
  gr524_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr524_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr524_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr524_cycletempIrrad -> SetMarkerStyle(20);
  gr524_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 1.3);
  gr524_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr524_cycletempValveOpen = new TGraphErrors (counts_524 , cycleNumberArray524, avets12ValveOpenArray524, 0 , ts12ValveOpenErr524);
  
  gr524_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr524_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr524_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr524_cycletempValveOpen -> SetMarkerStyle(20);
  gr524_cycletempValveOpen -> SetMarkerColor(2);
  gr524_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr524_cycletempIrrad , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr524_cycletempValveOpen , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  
  gr524_cycletempIrrad -> Draw("AP");
  gr524_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c524_cycleNum -> cd(4);
  TGraphErrors *gr524_cyclecur = new TGraphErrors (counts_524 , cycleNumberArray524 , avecurArray524, 0, ErrcurArray524 );
  gr524_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr524_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr524_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr524_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr524_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr524_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr524_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr524_cyclecur -> SetMarkerStyle(20);
  gr524_cyclecur -> Draw("Ap");
  c524_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c524_counttemp = new TCanvas ("c524_counttemp" , "c524_counttemp " , 1200, 900);
  c524_counttemp -> SetLogy();

  TGraphErrors *gr524_HistIrrad = new TGraphErrors (counts_524, avets12IrradArray524, HistIntegralArray524, ts12IrradErr524, HistIntegralErrArray524);
  gr524_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr524_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr524_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_HistIrrad -> SetMarkerStyle(25);
  gr524_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr524_HistIrrad -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr524_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr524_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);



  TGraphErrors *gr524_HistValveOpen = new TGraphErrors (counts_524, avets12ValveOpenArray524, HistIntegralArray524, ts12ValveOpenErr524, HistIntegralErrArray524);
  gr524_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr524_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr524_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_HistValveOpen -> SetMarkerStyle(25);
  gr524_HistValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr524_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr524_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_HistValveOpen -> SetMarkerColor(2);

  TLegend *leg3 = new TLegend(0.25,0.7, 0.9, 0.9);
  leg3 -> AddEntry(gr524_HistIrrad , "Irradiation time + delay time, with background" , "p") ;
  leg3 -> AddEntry(gr524_HistValveOpen , "Valve open, with background" , "p") ;
  leg3 -> SetTextSize(0.04);

  gr524_HistIrrad -> Draw("Ap");
  gr524_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  // ************************************************
  
  // ******
  //  525
  // ******
  

  TCanvas *c525_cylceNum =  new TCanvas("c525_cycleNum" , "c525_cycleNum " , 1200, 900);
  c525_cycleNum-> Divide(2,2);

  TPad *p525_1 = c525_cycleNum->cd(1);
  p525_1->SetLogy(); 
  
  TGraphErrors *gr525_cyclehist = new TGraphErrors(counts_525, cycleNumberArray525 , HistIntegralArray525, 0, HistIntegralErrArray525);
  
  gr525_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr525_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr525_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr525_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr525_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_cyclehist -> SetMarkerColor(2);
  gr525_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr525_cyclecountmanual = new TGraphErrors(counts_525, cycleNumberArray525 , UCNIntegralManualArray525, 0, UCNIntegralManualErrArray525);
  
  gr525_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr525_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr525_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr525_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr525_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_cyclecountmanual -> SetMarkerColor(1);
  gr525_cyclecountmanual -> SetMarkerStyle(25);
  
  

  gr525_cyclehist -> Draw("Ap");
  gr525_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c525_cycleNum -> cd(2);
  TGraphErrors *gr525_cycledelay = new TGraphErrors (counts_525 , cycleNumberArray525, delaytimeArray525, 0 , 0);
  gr525_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr525_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr525_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr525_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr525_cycledelay -> SetMarkerStyle(20);
  
  gr525_cycledelay -> Draw("Ap");
  
  
  c525_cycleNum -> cd(3);
  TGraphErrors *gr525_cycletempIrrad = new TGraphErrors (counts_525 , cycleNumberArray525, avets12IrradArray525, 0 , ts12IrradErr525);
  
  gr525_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr525_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr525_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr525_cycletempIrrad -> SetMarkerStyle(20);
  gr525_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr525_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr525_cycletempValveOpen = new TGraphErrors (counts_525 , cycleNumberArray525, avets12ValveOpenArray525, 0 , ts12ValveOpenErr525);
  
  gr525_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr525_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr525_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr525_cycletempValveOpen -> SetMarkerStyle(20);
  gr525_cycletempValveOpen -> SetMarkerColor(2);
  gr525_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr525_cycletempIrrad -> Draw("AP");
  gr525_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c525_cycleNum -> cd(4);
  TGraphErrors *gr525_cyclecur = new TGraphErrors (counts_525 , cycleNumberArray525 , avecurArray525, 0, ErrcurArray525 );
  gr525_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr525_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr525_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr525_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr525_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr525_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr525_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr525_cyclecur -> SetMarkerStyle(20);
  gr525_cyclecur -> Draw("Ap");
  c525_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c525_counttemp = new TCanvas ("c525_counttemp" , "c525_counttemp " , 1200, 900);
  c525_counttemp -> SetLogy();

  TGraphErrors *gr525_HistIrrad = new TGraphErrors (counts_525, avets12IrradArray525, HistIntegralArray525, ts12IrradErr525, HistIntegralErrArray525);
  gr525_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr525_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr525_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_HistIrrad -> SetMarkerStyle(25);
  gr525_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr525_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr525_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr525_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  
  TGraphErrors *gr525_HistValveOpen = new TGraphErrors (counts_525, avets12ValveOpenArray525, HistIntegralArray525, ts12ValveOpenErr525, HistIntegralErrArray525);
  gr525_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr525_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr525_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_HistValveOpen -> SetMarkerStyle(25);
  gr525_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr525_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr525_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_HistValveOpen -> SetMarkerColor(2);


  gr525_HistIrrad -> Draw("Ap");
  gr525_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  //*******************************************
  // ******
  //  526
  // ******
  

  TCanvas *c526_cylceNum =  new TCanvas("c526_cycleNum" , "c526_cycleNum " , 1200, 900);
  c526_cycleNum-> Divide(2,2);

  TPad *p526_1 = c526_cycleNum->cd(1);
  p526_1->SetLogy(); 
  TGraphErrors *gr526_cyclehist = new TGraphErrors(counts_526, cycleNumberArray526 , HistIntegralArray526, 0, HistIntegralErrArray526);
  
  gr526_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr526_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr526_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr526_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr526_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_cyclehist -> SetMarkerColor(2);
  gr526_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr526_cyclecountmanual = new TGraphErrors(counts_526, cycleNumberArray526 , UCNIntegralManualArray526, 0, UCNIntegralManualErrArray526);
  
  gr526_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr526_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr526_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr526_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr526_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_cyclecountmanual -> SetMarkerColor(1);
  gr526_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr526_cyclehist -> Draw("Ap");
  gr526_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c526_cycleNum -> cd(2);
  TGraphErrors *gr526_cycledelay = new TGraphErrors (counts_526 , cycleNumberArray526, delaytimeArray526, 0 , 0);
  gr526_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr526_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr526_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr526_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr526_cycledelay -> SetMarkerStyle(20);
  gr526_cycledelay -> Draw("Ap");
  
  
  c526_cycleNum -> cd(3);
  TGraphErrors *gr526_cycletempIrrad = new TGraphErrors (counts_526 , cycleNumberArray526, avets12IrradArray526, 0 , ts12IrradErr526);
  
  gr526_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr526_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr526_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr526_cycletempIrrad -> SetMarkerStyle(20);
  gr526_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr526_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr526_cycletempValveOpen = new TGraphErrors (counts_526 , cycleNumberArray526, avets12ValveOpenArray526, 0 , ts12ValveOpenErr526);
  
  gr526_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr526_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr526_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr526_cycletempValveOpen -> SetMarkerStyle(20);
  gr526_cycletempValveOpen -> SetMarkerColor(2);
  gr526_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr526_cycletempIrrad -> Draw("AP");
  gr526_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c526_cycleNum -> cd(4);
  TGraphErrors *gr526_cyclecur = new TGraphErrors (counts_526 , cycleNumberArray526 , avecurArray526, 0, ErrcurArray526 );
  gr526_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr526_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr526_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr526_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr526_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr526_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr526_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr526_cyclecur -> SetMarkerStyle(20);
  gr526_cyclecur -> Draw("Ap");
  c526_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c526_counttemp = new TCanvas ("c526_counttemp" , "c526_counttemp " , 1200, 900);
  c526_counttemp -> SetLogy();



  TGraphErrors *gr526_HistIrrad = new TGraphErrors (counts_526, avets12IrradArray526, HistIntegralArray526, ts12IrradErr526, HistIntegralErrArray526);
  gr526_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr526_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr526_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_HistIrrad -> SetMarkerStyle(25);
  gr526_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr526_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr526_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr526_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);



  TGraphErrors *gr526_HistValveOpen = new TGraphErrors (counts_526, avets12ValveOpenArray526, HistIntegralArray526, ts12ValveOpenErr526, HistIntegralErrArray526);
  gr526_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr526_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr526_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_HistValveOpen -> SetMarkerStyle(25);
  gr526_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr526_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr526_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_HistValveOpen -> SetMarkerColor(2);


  gr526_HistIrrad -> Draw("Ap");
  gr526_HistValveOpen -> Draw("p");
  leg3 -> Draw();



  //********************************************
  // ******
  //  527
  // ******
  

  TCanvas *c527_cylceNum =  new TCanvas("c527_cycleNum" , "c527_cycleNum " , 1200, 900);
  c527_cycleNum-> Divide(2,2);

  TPad *p527_1 = c527_cycleNum->cd(1);
  p527_1->SetLogy(); 
  TGraphErrors *gr527_cyclehist = new TGraphErrors(counts_527, cycleNumberArray527 , HistIntegralArray527, 0, HistIntegralErrArray527);
  
  gr527_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr527_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr527_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr527_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr527_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_cyclehist -> SetMarkerColor(2);
  gr527_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr527_cyclecountmanual = new TGraphErrors(counts_527, cycleNumberArray527 , UCNIntegralManualArray527, 0, UCNIntegralManualErrArray527);
  
  gr527_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr527_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr527_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr527_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr527_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_cyclecountmanual -> SetMarkerColor(1);
  gr527_cyclecountmanual -> SetMarkerStyle(25);
  
  
  gr527_cyclehist -> Draw("Ap");
  gr527_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c527_cycleNum -> cd(2);
  TGraphErrors *gr527_cycledelay = new TGraphErrors (counts_527 , cycleNumberArray527, delaytimeArray527, 0 , 0);
  gr527_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr527_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr527_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr527_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr527_cycledelay -> SetMarkerStyle(20);
  
  gr527_cycledelay -> Draw("Ap");
  
  
  c527_cycleNum -> cd(3);
  TGraphErrors *gr527_cycletempIrrad = new TGraphErrors (counts_527 , cycleNumberArray527, avets12IrradArray527, 0 , ts12IrradErr527);
  
  gr527_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr527_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr527_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr527_cycletempIrrad -> SetMarkerStyle(20);
  gr527_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr527_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr527_cycletempValveOpen = new TGraphErrors (counts_527 , cycleNumberArray527, avets12ValveOpenArray527, 0 , ts12ValveOpenErr527);
  
  gr527_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr527_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr527_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr527_cycletempValveOpen -> SetMarkerStyle(20);
  gr527_cycletempValveOpen -> SetMarkerColor(2);
  gr527_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr527_cycletempIrrad -> Draw("AP");
  gr527_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c527_cycleNum -> cd(4);
  TGraphErrors *gr527_cyclecur = new TGraphErrors (counts_527 , cycleNumberArray527 , avecurArray527, 0, ErrcurArray527 );
  gr527_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr527_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr527_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr527_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr527_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr527_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr527_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr527_cyclecur -> SetMarkerStyle(20);
  gr527_cyclecur -> Draw("Ap");
  c527_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c527_counttemp = new TCanvas ("c527_counttemp" , "c527_counttemp " , 1200, 900);
  c527_counttemp -> SetLogy();



  TGraphErrors *gr527_HistIrrad = new TGraphErrors (counts_527, avets12IrradArray527, HistIntegralArray527, ts12IrradErr527, HistIntegralErrArray527);
  gr527_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr527_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr527_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_HistIrrad -> SetMarkerStyle(25);
  gr527_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr527_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr527_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr527_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  
  TGraphErrors *gr527_HistValveOpen = new TGraphErrors (counts_527, avets12ValveOpenArray527, HistIntegralArray527, ts12ValveOpenErr527, HistIntegralErrArray527);
  gr527_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr527_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr527_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_HistValveOpen -> SetMarkerStyle(25);
  gr527_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr527_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr527_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_HistValveOpen -> SetMarkerColor(2);


   gr527_HistIrrad -> Draw("Ap");
  gr527_HistValveOpen -> Draw("p");
  leg3 -> Draw();






  //********************************************
  // ******
  //  528
  // ******
  

  TCanvas *c528_cylceNum =  new TCanvas("c528_cycleNum" , "c528_cycleNum " , 1200, 900);
  c528_cycleNum-> Divide(2,2);

  TPad *p528_1 = c528_cycleNum->cd(1);
  p528_1->SetLogy(); 
  TGraphErrors *gr528_cyclehist = new TGraphErrors(counts_528, cycleNumberArray528 , HistIntegralArray528, 0, HistIntegralErrArray528);
  
  gr528_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr528_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr528_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr528_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr528_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_cyclehist -> SetMarkerColor(2);
  gr528_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr528_cyclecountmanual = new TGraphErrors(counts_528, cycleNumberArray528 , UCNIntegralManualArray528, 0, UCNIntegralManualErrArray528);
  
  gr528_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr528_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr528_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr528_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr528_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_cyclecountmanual -> SetMarkerColor(1);
  gr528_cyclecountmanual -> SetMarkerStyle(25);
  
  

  gr528_cyclehist -> Draw("Ap");
  gr528_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c528_cycleNum -> cd(2);
  TGraphErrors *gr528_cycledelay = new TGraphErrors (counts_528 , cycleNumberArray528, delaytimeArray528, 0 , 0);
  gr528_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr528_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr528_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr528_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr528_cycledelay -> SetMarkerStyle(20);
  
  gr528_cycledelay -> Draw("Ap");
  
  
  c528_cycleNum -> cd(3);
  TGraphErrors *gr528_cycletempIrrad = new TGraphErrors (counts_528 , cycleNumberArray528, avets12IrradArray528, 0 , ts12IrradErr528);
  
  gr528_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr528_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr528_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr528_cycletempIrrad -> SetMarkerStyle(20);
  gr528_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr528_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr528_cycletempValveOpen = new TGraphErrors (counts_528 , cycleNumberArray528, avets12ValveOpenArray528, 0 , ts12ValveOpenErr528);
  
  gr528_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr528_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr528_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr528_cycletempValveOpen -> SetMarkerStyle(20);
  gr528_cycletempValveOpen -> SetMarkerColor(2);
  gr528_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr528_cycletempIrrad -> Draw("AP");
  gr528_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c528_cycleNum -> cd(4);
  TGraphErrors *gr528_cyclecur = new TGraphErrors (counts_528 , cycleNumberArray528 , avecurArray528, 0, ErrcurArray528 );
  gr528_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr528_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr528_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr528_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr528_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr528_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr528_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr528_cyclecur -> SetMarkerStyle(20);
  gr528_cyclecur -> Draw("Ap");
  c528_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c528_counttemp = new TCanvas ("c528_counttemp" , "c528_counttemp " , 1200, 900);
  c528_counttemp -> SetLogy();

  TGraphErrors *gr528_HistIrrad = new TGraphErrors (counts_528, avets12IrradArray528, HistIntegralArray528, ts12IrradErr528, HistIntegralErrArray528);
  gr528_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr528_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr528_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_HistIrrad -> SetMarkerStyle(25);
  gr528_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr528_HistIrrad -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr528_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr528_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);



  TGraphErrors *gr528_HistValveOpen = new TGraphErrors (counts_528, avets12ValveOpenArray528, HistIntegralArray528, ts12ValveOpenErr528, HistIntegralErrArray528);
  gr528_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr528_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr528_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_HistValveOpen -> SetMarkerStyle(25);
  gr528_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr528_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr528_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_HistValveOpen -> SetMarkerColor(2);


   gr528_HistIrrad -> Draw("Ap");
  gr528_HistValveOpen -> Draw("p");
  leg3 -> Draw();
  


  //********************************************
  // ******
  //  529
  // ******
  

  TCanvas *c529_cylceNum =  new TCanvas("c529_cycleNum" , "c529_cycleNum " , 1200, 900);
  c529_cycleNum-> Divide(2,2);

  TPad *p529_1 = c529_cycleNum->cd(1);
  p529_1->SetLogy(); 
  TGraphErrors *gr529_cyclehist = new TGraphErrors(counts_529, cycleNumberArray529 , HistIntegralArray529, 0, HistIntegralErrArray529);
  
  gr529_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr529_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr529_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr529_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr529_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_cyclehist -> SetMarkerColor(2);
  gr529_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr529_cyclecountmanual = new TGraphErrors(counts_529, cycleNumberArray529 , UCNIntegralManualArray529, 0, UCNIntegralManualErrArray529);
  
  gr529_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr529_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr529_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr529_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr529_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_cyclecountmanual -> SetMarkerColor(1);
  gr529_cyclecountmanual -> SetMarkerStyle(25);
  
  

  gr529_cyclehist -> Draw("Ap");
  gr529_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c529_cycleNum -> cd(2);
  TGraphErrors *gr529_cycledelay = new TGraphErrors (counts_529 , cycleNumberArray529, delaytimeArray529, 0 , 0);
  gr529_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr529_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr529_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr529_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr529_cycledelay -> SetMarkerStyle(20);
  
  gr529_cycledelay -> Draw("Ap");
  
  
  c529_cycleNum -> cd(3);
  TGraphErrors *gr529_cycletempIrrad = new TGraphErrors (counts_529 , cycleNumberArray529, avets12IrradArray529, 0 , ts12IrradErr529);
  
  gr529_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr529_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr529_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr529_cycletempIrrad -> SetMarkerStyle(20);
  gr529_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr529_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr529_cycletempValveOpen = new TGraphErrors (counts_529 , cycleNumberArray529, avets12ValveOpenArray529, 0 , ts12ValveOpenErr529);
  
  gr529_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr529_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr529_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr529_cycletempValveOpen -> SetMarkerStyle(20);
  gr529_cycletempValveOpen -> SetMarkerColor(2);
  gr529_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr529_cycletempIrrad -> Draw("AP");
  gr529_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c529_cycleNum -> cd(4);
  TGraphErrors *gr529_cyclecur = new TGraphErrors (counts_529 , cycleNumberArray529 , avecurArray529, 0, ErrcurArray529 );
  gr529_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr529_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr529_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr529_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr529_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr529_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr529_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr529_cyclecur -> SetMarkerStyle(20);
  gr529_cyclecur -> Draw("Ap");
  c529_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c529_counttemp = new TCanvas ("c529_counttemp" , "c529_counttemp " , 1200, 900);
  c529_counttemp -> SetLogy();



  TGraphErrors *gr529_HistIrrad = new TGraphErrors (counts_529, avets12IrradArray529, HistIntegralArray529, ts12IrradErr529, HistIntegralErrArray529);
  gr529_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr529_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr529_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_HistIrrad -> SetMarkerStyle(25);
  gr529_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr529_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr529_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr529_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr529_HistValveOpen = new TGraphErrors (counts_529, avets12ValveOpenArray529, HistIntegralArray529, ts12ValveOpenErr529, HistIntegralErrArray529);
  gr529_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr529_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr529_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_HistValveOpen -> SetMarkerStyle(25);
  gr529_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr529_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr529_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_HistValveOpen -> SetMarkerColor(2);

  gr529_HistIrrad -> Draw("Ap");
  gr529_HistValveOpen -> Draw("p");
  leg3 -> Draw();


  
  //********************************************
  // ******
  //  530
  // ******
  

  TCanvas *c530_cylceNum =  new TCanvas("c530_cycleNum" , "c530_cycleNum " , 1200, 900);
  c530_cycleNum-> Divide(2,2);

  TPad *p530_1 = c530_cycleNum->cd(1);
  p530_1->SetLogy(); 
  TGraphErrors *gr530_cyclehist = new TGraphErrors(counts_530, cycleNumberArray530 , HistIntegralArray530, 0, HistIntegralErrArray530);
  
  gr530_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr530_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr530_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr530_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr530_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr530_cyclehist -> SetMarkerColor(2);
  gr530_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr530_cyclecountmanual = new TGraphErrors(counts_530, cycleNumberArray530 , UCNIntegralManualArray530, 0, UCNIntegralManualErrArray530);
  
  gr530_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr530_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr530_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr530_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr530_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr530_cyclecountmanual -> SetMarkerColor(1);
  gr530_cyclecountmanual -> SetMarkerStyle(25);
  

  gr530_cyclehist -> Draw("Ap");
  gr530_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c530_cycleNum -> cd(2);
  TGraphErrors *gr530_cycledelay = new TGraphErrors (counts_530 , cycleNumberArray530, delaytimeArray530, 0 , 0);
  gr530_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr530_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr530_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr530_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr530_cycledelay -> SetMarkerStyle(20);
  
  gr530_cycledelay -> Draw("Ap");
  
  
  c530_cycleNum -> cd(3);
  TGraphErrors *gr530_cycletempIrrad = new TGraphErrors (counts_530 , cycleNumberArray530, avets12IrradArray530, 0 , ts12IrradErr530);
  
  gr530_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr530_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr530_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr530_cycletempIrrad -> SetMarkerStyle(20);
  gr530_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.2);
  gr530_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr530_cycletempValveOpen = new TGraphErrors (counts_530 , cycleNumberArray530, avets12ValveOpenArray530, 0 , ts12ValveOpenErr530);
  
  gr530_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr530_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr530_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr530_cycletempValveOpen -> SetMarkerStyle(20);
  gr530_cycletempValveOpen -> SetMarkerColor(2);
  gr530_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  
  gr530_cycletempIrrad -> Draw("AP");
  gr530_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c530_cycleNum -> cd(4);
  TGraphErrors *gr530_cyclecur = new TGraphErrors (counts_530 , cycleNumberArray530 , avecurArray530, 0, ErrcurArray530 );
  gr530_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr530_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr530_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr530_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr530_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr530_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr530_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr530_cyclecur -> SetMarkerStyle(20);
  gr530_cyclecur -> Draw("Ap");
  c530_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c530_counttemp = new TCanvas ("c530_counttemp" , "c530_counttemp " , 1200, 900);
  c530_counttemp -> SetLogy();

  TGraphErrors *gr530_HistIrrad = new TGraphErrors (counts_530, avets12IrradArray530, HistIntegralArray530, ts12IrradErr530, HistIntegralErrArray530);
  gr530_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr530_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr530_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr530_HistIrrad -> SetMarkerStyle(25);
  gr530_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr530_HistIrrad -> GetXaxis()-> SetLimits(1, 1.4);
  gr530_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr530_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr530_HistValveOpen = new TGraphErrors (counts_530, avets12ValveOpenArray530, HistIntegralArray530, ts12ValveOpenErr530, HistIntegralErrArray530);
  gr530_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr530_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr530_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr530_HistValveOpen -> SetMarkerStyle(25);
  gr530_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 1.2);
  gr530_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr530_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr530_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr530_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr530_HistValveOpen -> SetMarkerColor(2);



  gr530_HistIrrad -> Draw("Ap");
  gr530_HistValveOpen -> Draw("p");
  leg3 -> Draw();

  
  // *******************************************
  // OVERALL
  // ******************************************

  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);
  cAll -> SetLogy();

  // gr524_countIrrad -> SetTitle("UCN Count vs Average Isopure Temperature and Beam Current");
  //gr524_countIrrad -> GetYaxis()-> SetRangeUser(100, 1600000);
  //gr524_countIrrad -> GetXaxis() -> SetLimits(0.8, 0.92);
  // gr524_countIrrad -> SetMarkerStyle(20);
  gr524_HistIrrad -> SetMarkerStyle(25);
  //gr525_countIrrad -> SetMarkerColor(2);
  gr525_HistIrrad -> SetMarkerColor(2);
  //gr527_countIrrad -> SetMarkerColor(9);
  gr527_HistIrrad -> SetMarkerColor(9);
  //gr528_countIrrad -> SetMarkerColor(8);
  gr528_HistIrrad -> SetMarkerColor(8);
  //gr529_countIrrad -> SetMarkerColor(6);
  gr529_HistIrrad -> SetMarkerColor(6);

  TLegend *legAll = new TLegend (0.2, 0.7, 0.9, 0.9);
  legAll -> SetTextSize(0.02);
  //legAll -> AddEntry(gr524_countIrrad , "Counts without backgroun (fit) , 0.05 #muA", "p");
  legAll -> AddEntry(gr524_HistIrrad , "Counts with backgroun ,  0.05 #muA", "p");
  //legAll -> AddEntry(gr525_countIrrad , "Counts without backgroun (fit) ,0.5 #muA", "p");
  legAll -> AddEntry(gr525_HistIrrad , "Counts with backgroun , 0.5 #muA", "p");
  //legAll -> AddEntry(gr527_countIrrad , "Counts without backgroun (fit) , 0.25 #muA", "p");
  legAll -> AddEntry(gr527_HistIrrad , "Counts with backgroun , 0.25 #muA", "p");
  //legAll -> AddEntry(gr528_countIrrad , "Counts without backgroun (fit) , 0.75 #muA", "p");
  legAll -> AddEntry(gr528_HistIrrad , "Counts with backgroun , 0.75 #muA", "p");
  //legAll -> AddEntry(gr529_countIrrad , "Counts without backgroun (fit) , 1 #muA", "p");
  legAll -> AddEntry(gr529_HistIrrad , "Counts with backgroun , 1 #muA", "p");
  

  //gr524_countIrrad -> Draw("ap");
  gr524_HistIrrad -> Draw("Ap");
  //gr525_countIrrad -> Draw("p");
  gr525_HistIrrad -> Draw("p");
  //gr527_countIrrad -> Draw("p");
  gr527_HistIrrad -> Draw("p");
  //gr528_countIrrad -> Draw("p");
  gr528_HistIrrad -> Draw("p");
  //gr529_countIrrad -> Draw("p");
  gr529_HistIrrad -> Draw("p");
  legAll -> Draw();



  // UCN COUNT VS BEAM CURRENT

  // ONLINE ANALYSIS
  double curOnline[100] = {0.05, 0.05, 0.05, 0.05, 0.5, 0.5 , 0.5 ,0.5 , 0.5, 1 ,1 ,1, 1, 1, 0.25, 0.25, 0.25, 0.25, 0.25, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 1, 1, 1, 1, 1 };

  double countsOnline[100] = {2600, 2300, 2245, 2300, 20100, 20200, 20000, 20150, 20150, 40000,39300, 39900, 39500, 39500, 10300, 10100, 10100, 10100, 10100, 30200, 30100, 30300, 30000, 30300, 30200, 40200, 39600, 39200, 39800, 40200} ;

  TCanvas *c_countcur = new TCanvas("c_countcur" , "c_countcur" , 1200, 900);
  // c_countcur -> SetLogy();

  TGraphErrors *gr524_countcur = new TGraphErrors (counts_524, avecurArray524, UCNIntegralManualArray524, 0,   UCNIntegralManualErrArray524);
  gr524_countcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr524_countcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr524_countcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_countcur -> SetMarkerStyle(20);
  gr524_countcur -> GetYaxis() -> SetRangeUser(10,70000);
  gr524_countcur -> GetXaxis()-> SetLimits(0., 2.5);
  gr524_countcur -> GetXaxis() -> SetTitleSize(0.05);
  gr524_countcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_countcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_countcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_countcur -> SetMarkerColor(1);



  TGraphErrors *gr524_histcur = new  TGraphErrors (counts_524,  avecurArray524, HistIntegralArray524, 0, HistIntegralErrArray524);
  gr524_histcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr524_histcur -> GetXaxis() -> SetTitle("Average Predicted Beam Current" );
  gr524_histcur -> GetYaxis() -> SetTitle("UCN Counts");
  gr524_histcur -> SetMarkerStyle(25);
  gr524_histcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr524_histcur -> GetXaxis() -> SetLimits(0., 1.2);
  gr524_histcur -> GetXaxis() -> SetTitleSize(0.05);
  gr524_histcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_histcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_histcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_histcur -> SetMarkerColor(1);

  TGraphErrors *gr525_countcur = new TGraphErrors (counts_525,  avecurArray525, UCNIntegralManualArray525,0 ,  UCNIntegralManualErrArray525);
  gr525_countcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr525_countcur -> GetXaxis() -> SetTitle("Average Predicted Beam Current" );
  gr525_countcur -> GetYaxis() -> SetTitle("UCN Counts");
  gr525_countcur -> SetMarkerStyle(20);
  gr525_countcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr525_countcur -> GetXaxis() -> SetLimits(0., 1.2);
  gr525_countcur -> GetXaxis() -> SetTitleSize(0.05);
  gr525_countcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_countcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_countcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_countcur -> SetMarkerColor(2);

  TGraphErrors *gr525_histcur = new TGraphErrors (counts_525,  avecurArray525, HistIntegralArray525, 0, HistIntegralErrArray525);
  gr525_histcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr525_histcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr525_histcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_histcur -> SetMarkerStyle(25);
  gr525_histcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr525_histcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr525_histcur -> GetXaxis() -> SetTitleSize(0.05);
  gr525_histcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_histcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_histcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_histcur -> SetMarkerColor(2);

  TGraphErrors *gr527_countcur = new TGraphErrors (counts_527, avecurArray527,  UCNIntegralManualArray527, 0 ,  UCNIntegralManualErrArray527);
  gr527_countcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr527_countcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr527_countcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_countcur -> SetMarkerStyle(20);
  gr527_countcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr527_countcur -> GetXaxis()-> SetLimits(0., 1.3);
  gr527_countcur -> GetXaxis() -> SetTitleSize(0.05);
  gr527_countcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_countcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_countcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_countcur -> SetMarkerColor(4);

  TGraphErrors *gr527_histcur = new TGraphErrors (counts_527 ,avecurArray527, HistIntegralArray527, 0, HistIntegralErrArray527);
  gr527_histcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr527_histcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr527_histcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_histcur -> SetMarkerStyle(25);
  gr527_histcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr527_histcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr527_histcur -> GetXaxis() -> SetTitleSize(0.05);
  gr527_histcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_histcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_histcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_histcur -> SetMarkerColor(4);
  
  TGraphErrors *gr528_countcur = new TGraphErrors (counts_528,  avecurArray528, UCNIntegralManualArray528,0 , UCNIntegralManualErrArray528);
  gr528_countcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr528_countcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr528_countcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_countcur -> SetMarkerStyle(20);
  gr528_countcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr528_countcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_countcur -> GetXaxis() -> SetTitleSize(0.05);
  gr528_countcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_countcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_countcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_countcur -> SetMarkerColor(8);

  TGraphErrors *gr528_histcur = new TGraphErrors (counts_528, avecurArray528, HistIntegralArray528 ,0,  HistIntegralErrArray528);
  gr528_histcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr528_histcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr528_histcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_histcur -> SetMarkerStyle(25);
  gr528_histcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr528_histcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_histcur -> GetXaxis() -> SetTitleSize(0.05);
  gr528_histcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_histcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_histcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_histcur -> SetMarkerColor(8);

  TGraphErrors *gr529_countcur = new TGraphErrors (counts_529 , avecurArray529 , UCNIntegralManualArray529, 0,  UCNIntegralManualErrArray529);
  gr529_countcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr529_countcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr529_countcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_countcur -> SetMarkerStyle(20);
  gr529_countcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr529_countcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_countcur -> GetXaxis() -> SetTitleSize(0.05);
  gr529_countcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_countcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_countcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_countcur -> SetMarkerColor(6);


  TGraphErrors *gr529_histcur = new TGraphErrors (counts_529, avecurArray529,  HistIntegralArray529, 0, HistIntegralErrArray529);
  gr529_histcur -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr529_histcur -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr529_histcur -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_histcur -> SetMarkerStyle(25);
  gr529_histcur -> GetYaxis() -> SetRangeUser(10,500000);
  gr529_histcur -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_histcur -> GetXaxis() -> SetTitleSize(0.05);
  gr529_histcur -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_histcur -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_histcur -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_histcur -> SetMarkerColor(6);


  TGraphErrors *gr_online = new TGraphErrors (30, curOnline,  countsOnline, 0, 0);
  gr_online -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr_online -> GetXaxis()-> SetTitle("Average Predicted Beam Current" );
  gr_online -> GetYaxis()-> SetTitle("UCN Counts");
  gr_online -> SetMarkerStyle(3);
  gr_online -> GetYaxis() -> SetRangeUser(10,500000);
  gr_online -> GetXaxis()-> SetLimits(0., 1.2);
  gr_online -> GetXaxis() -> SetTitleSize(0.05);
  gr_online -> GetXaxis() -> SetTitleOffset(1.0);
  gr_online -> GetYaxis() -> SetTitleSize(0.05); 
  gr_online -> GetYaxis() -> SetTitleOffset(0.9);
  gr_online -> SetMarkerColor(1);

  TLegend *legcur = new TLegend (0.7, 0.5, 0.9, 0.9);

  legcur -> AddEntry (gr524_countcur , "Without background , 0.05 #muA", "p");
  legcur -> AddEntry (gr524_histcur , "With background , 0.05 #muA" , "p");
  legcur -> AddEntry (gr525_countcur , "Without background , 0.5 #muA", "p");
  legcur -> AddEntry (gr525_histcur , "With background , 0.5 #muA" , "p");
  legcur -> AddEntry (gr527_countcur , "Without background , 0.25 #muA", "p");
  legcur -> AddEntry (gr527_histcur , "With background , 0.25 #muA" , "p");
  legcur -> AddEntry (gr528_countcur , "Without background , 0.75 #muA", "p");
  legcur -> AddEntry (gr528_histcur , "With background , 0.75 #muA" , "p");
  legcur -> AddEntry (gr529_countcur , "Without background, 1 #muA", "p");
  legcur -> AddEntry (gr529_histcur , "With background , 1 #muA" , "p");
  legcur -> AddEntry (gr_online , "Online Analysis" , "p");
  

  gr524_countcur -> Draw("ap");
  gr524_histcur -> Draw("p");
  gr525_countcur -> Draw("p");
  gr525_histcur -> Draw("p");
  gr527_countcur -> Draw("p");
  gr527_histcur -> Draw("p");
  gr528_countcur -> Draw("p");
  gr528_histcur -> Draw("p");
  gr529_countcur -> Draw("p");
  gr529_histcur -> Draw("p");
  gr_online -> Draw("p");
  legcur -> Draw();

  // Average predicted current vs different temperatures

  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200, 900);

  TGraphErrors *gr524_ts11 = new TGraphErrors( counts_524, avecurArray524 ,  avets11IrradArray524  , ErrcurArray524 , ts11IrradErr524);
  gr524_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr524_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr524_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_ts11 -> SetMarkerStyle(20);
  gr524_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr524_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr524_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr524_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr524_ts12 = new TGraphErrors( counts_524, avecurArray524 ,  avets12IrradArray524  , ErrcurArray524 , ts12IrradErr524);
  gr524_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr524_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr524_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_ts12 -> SetMarkerStyle(21);
  gr524_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr524_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr524_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr524_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr524_ts14 = new TGraphErrors( counts_524, avecurArray524 ,  avets14IrradArray524  , ErrcurArray524 , ts14IrradErr524);
  gr524_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr524_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr524_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_ts14 -> SetMarkerStyle(24);
  gr524_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr524_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr524_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr524_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr524_ts16 = new TGraphErrors( counts_524, avecurArray524 ,  avets16IrradArray524  , ErrcurArray524 , ts16IrradErr524);
  gr524_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr524_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr524_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr524_ts16 -> SetMarkerStyle(25);
  gr524_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr524_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr524_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr524_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr524_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr524_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr524_ts16 -> SetMarkerColor(1);

  TLegend *legtemp = new TLegend (0.7, 0.7, 0.9, 0.9);
  legtemp -> AddEntry (gr524_ts11 , "TS11" , "p");
  legtemp -> AddEntry (gr524_ts12 , "TS12" , "p");
  legtemp -> AddEntry (gr524_ts14 , "TS14" , "p");
  legtemp -> AddEntry (gr524_ts16 , "TS16" , "p");

  // 525
  TGraphErrors *gr525_ts11 = new TGraphErrors( counts_525, avecurArray525 ,  avets11IrradArray525  , ErrcurArray525 , ts11IrradErr525);
  gr525_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr525_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr525_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_ts11 -> SetMarkerStyle(20);
  gr525_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr525_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr525_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr525_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr525_ts12 = new TGraphErrors( counts_525, avecurArray525 ,  avets12IrradArray525  , ErrcurArray525 , ts12IrradErr525);
  gr525_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr525_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr525_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_ts12 -> SetMarkerStyle(21);
  gr525_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr525_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr525_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr525_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr525_ts14 = new TGraphErrors( counts_525, avecurArray525 ,  avets14IrradArray525  , ErrcurArray525 , ts14IrradErr525);
  gr525_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr525_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr525_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_ts14 -> SetMarkerStyle(24);
  gr525_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr525_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr525_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr525_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr525_ts16 = new TGraphErrors( counts_525, avecurArray525 ,  avets16IrradArray525  , ErrcurArray525 , ts16IrradErr525);
  gr525_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr525_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr525_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr525_ts16 -> SetMarkerStyle(25);
  gr525_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr525_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr525_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr525_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr525_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr525_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr525_ts16 -> SetMarkerColor(1);

  //526
  TGraphErrors *gr526_ts11 = new TGraphErrors( counts_526, avecurArray526 ,  avets11IrradArray526  , ErrcurArray526 , ts11IrradErr526);
  gr526_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr526_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr526_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_ts11 -> SetMarkerStyle(20);
  gr526_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr526_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr526_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr526_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr526_ts12 = new TGraphErrors( counts_526, avecurArray526 ,  avets12IrradArray526  , ErrcurArray526 , ts12IrradErr526);
  gr526_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr526_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr526_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_ts12 -> SetMarkerStyle(21);
  gr526_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr526_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr526_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr526_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr526_ts14 = new TGraphErrors( counts_526, avecurArray526 ,  avets14IrradArray526  , ErrcurArray526 , ts14IrradErr526);
  gr526_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr526_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr526_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_ts14 -> SetMarkerStyle(24);
  gr526_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr526_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr526_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr526_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr526_ts16 = new TGraphErrors( counts_526, avecurArray526 ,  avets16IrradArray526  , ErrcurArray526 , ts16IrradErr526);
  gr526_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr526_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr526_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr526_ts16 -> SetMarkerStyle(25);
  gr526_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr526_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr526_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr526_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr526_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr526_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr526_ts16 -> SetMarkerColor(1);

  //527
  TGraphErrors *gr527_ts11 = new TGraphErrors( counts_527, avecurArray527 ,  avets11IrradArray527  , ErrcurArray527 , ts11IrradErr527);
  gr527_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr527_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr527_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_ts11 -> SetMarkerStyle(20);
  gr527_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr527_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr527_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr527_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr527_ts12 = new TGraphErrors( counts_527, avecurArray527 ,  avets12IrradArray527  , ErrcurArray527 , ts12IrradErr527);
  gr527_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr527_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr527_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_ts12 -> SetMarkerStyle(21);
  gr527_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr527_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr527_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr527_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr527_ts14 = new TGraphErrors( counts_527, avecurArray527 ,  avets14IrradArray527  , ErrcurArray527 , ts14IrradErr527);
  gr527_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr527_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr527_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_ts14 -> SetMarkerStyle(24);
  gr527_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr527_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr527_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr527_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr527_ts16 = new TGraphErrors( counts_527, avecurArray527 ,  avets16IrradArray527  , ErrcurArray527 , ts16IrradErr527);
  gr527_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr527_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr527_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr527_ts16 -> SetMarkerStyle(25);
  gr527_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr527_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr527_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr527_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr527_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr527_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr527_ts16 -> SetMarkerColor(1);

  //528
  TGraphErrors *gr528_ts11 = new TGraphErrors( counts_528, avecurArray528 ,  avets11IrradArray528  , ErrcurArray528 , ts11IrradErr528);
  gr528_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr528_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr528_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_ts11 -> SetMarkerStyle(20);
  gr528_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr528_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr528_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr528_ts12 = new TGraphErrors( counts_528, avecurArray528 ,  avets12IrradArray528  , ErrcurArray528 , ts12IrradErr528);
  gr528_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr528_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr528_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_ts12 -> SetMarkerStyle(21);
  gr528_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr528_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr528_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr528_ts14 = new TGraphErrors( counts_528, avecurArray528 ,  avets14IrradArray528  , ErrcurArray528 , ts14IrradErr528);
  gr528_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr528_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr528_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_ts14 -> SetMarkerStyle(24);
  gr528_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr528_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr528_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr528_ts16 = new TGraphErrors( counts_528, avecurArray528 ,  avets16IrradArray528  , ErrcurArray528 , ts16IrradErr528);
  gr528_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr528_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr528_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr528_ts16 -> SetMarkerStyle(25);
  gr528_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr528_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr528_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr528_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr528_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr528_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr528_ts16 -> SetMarkerColor(1);


  //529
  TGraphErrors *gr529_ts11 = new TGraphErrors( counts_529, avecurArray529 ,  avets11IrradArray529  , ErrcurArray529 , ts11IrradErr529);
  gr529_ts11 -> SetTitle( "Average TS11 Temperature vs Average Predicted Beam Current");
  gr529_ts11 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr529_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_ts11 -> SetMarkerStyle(20);
  gr529_ts11 -> GetYaxis() -> SetRangeUser(0.8 , 1.2);
  gr529_ts11 -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr529_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_ts11 -> SetMarkerColor(1);

  TGraphErrors *gr529_ts12 = new TGraphErrors( counts_529, avecurArray529 ,  avets12IrradArray529  , ErrcurArray529 , ts12IrradErr529);
  gr529_ts12 -> SetTitle( "Average TS12 Temperature vs Average Predicted Beam Current");
  gr529_ts12 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr529_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_ts12 -> SetMarkerStyle(21);
  gr529_ts12 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr529_ts12 -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr529_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_ts12 -> SetMarkerColor(1);

  TGraphErrors *gr529_ts14 = new TGraphErrors( counts_529, avecurArray529 ,  avets14IrradArray529  , ErrcurArray529 , ts14IrradErr529);
  gr529_ts14 -> SetTitle( "Average TS14 Temperature vs Average Predicted Beam Current");
  gr529_ts14 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr529_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_ts14 -> SetMarkerStyle(24);
  gr529_ts14 -> GetYaxis() -> SetRangeUser(0.8 , 2.3);
  gr529_ts14 -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr529_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_ts14 -> SetMarkerColor(1);


  TGraphErrors *gr529_ts16 = new TGraphErrors( counts_529, avecurArray529 ,  avets16IrradArray529  , ErrcurArray529 , ts16IrradErr529);
  gr529_ts16 -> SetTitle( "Average TS16 Temperature vs Average Predicted Beam Current");
  gr529_ts16 -> GetXaxis()-> SetTitle("Average Predicted Beam Current (#muA)" );
  gr529_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr529_ts16 -> SetMarkerStyle(25);
  gr529_ts16 -> GetYaxis() -> SetRangeUser(0.8, 2.3);
  gr529_ts16 -> GetXaxis()-> SetLimits(0., 1.2);
  gr529_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr529_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr529_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr529_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr529_ts16 -> SetMarkerColor(1);
  

  gr524_ts11 -> Draw("AP");
  gr524_ts12 -> Draw("p");
  gr524_ts14 -> Draw("p");
  gr524_ts16 -> Draw("p");
  gr525_ts11 -> Draw("P");
  gr525_ts12 -> Draw("p");
  gr525_ts14 -> Draw("p");
  gr525_ts16 -> Draw("p");
  //gr526_ts11 -> Draw("P");
  //gr526_ts12 -> Draw("p");
  //gr526_ts14 -> Draw("p");
  //gr526_ts16 -> Draw("p");
  gr527_ts11 -> Draw("P");
  gr527_ts12 -> Draw("p");
  gr527_ts14 -> Draw("p");
  gr527_ts16 -> Draw("p");
  gr528_ts11 -> Draw("P");
  gr528_ts12 -> Draw("p");
  gr528_ts14 -> Draw("p");
  gr528_ts16 -> Draw("p");
  gr529_ts11 -> Draw("P");
  gr529_ts12 -> Draw("p");
  gr529_ts14 -> Draw("p");
  gr529_ts16 -> Draw("p");
  legtemp -> Draw();

  myfile.close();
}
