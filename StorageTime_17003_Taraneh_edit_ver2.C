//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17002.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17003_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin541 = new TFile("outputTree_StorageTime_541.root","READ");
  TFile *fin542 = new TFile("outputTree_StorageTime_542.root","READ");
  TFile *fin543 = new TFile("outputTree_StorageTime_543.root","READ");
  TFile *fin544 = new TFile("outputTree_StorageTime_544.root","READ");
  TFile *fin545 = new TFile("outputTree_StorageTime_545.root","READ");
  TFile *fin546 = new TFile("outputTree_StorageTime_546.root","READ");


  
  TTree *outputTree541 = (TTree*) fin541 -> Get("cycle_info");
  TTree *outputTree542 = (TTree*) fin542 -> Get("cycle_info");
  TTree *outputTree543 = (TTree*) fin543 -> Get("cycle_info");
  TTree *outputTree544 = (TTree*) fin544 -> Get("cycle_info");
  TTree *outputTree545 = (TTree*) fin545 -> Get("cycle_info");
  TTree *outputTree546 = (TTree*) fin546 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime541;
  double cycleDelayTime542;
  double cycleDelayTime543;
  double cycleDelayTime544;
  double cycleDelayTime545;
  double cycleDelayTime546;



  outputTree541 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime541);
  outputTree542 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime542);
  outputTree543 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime543);
  outputTree544 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime544);
  outputTree545 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime545);
  outputTree546 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime546);



  // DELAY TIME (ARRAY)
  double delaytimeArray541 [100];
  double delaytimeArray542 [100];
  double delaytimeArray543 [100];
  double delaytimeArray544 [100];
  double delaytimeArray545 [100];
  double delaytimeArray546 [100];


  // CYCLE NUMBER
  int cycleNumber541;
  int cycleNumber542;
  int cycleNumber543;
  int cycleNumber544;
  int cycleNumber545;
  int cycleNumber546;
  int cycleNumber538;
  int cycleNumber539;
  int cycleNumber540;

  outputTree541 -> SetBranchAddress ("cycleNumber" , &cycleNumber541);
  outputTree542 -> SetBranchAddress ("cycleNumber" , &cycleNumber542);
  outputTree543 -> SetBranchAddress ("cycleNumber" , &cycleNumber543);
  outputTree544 -> SetBranchAddress ("cycleNumber" , &cycleNumber544);
  outputTree545 -> SetBranchAddress ("cycleNumber" , &cycleNumber545);
  outputTree546 -> SetBranchAddress ("cycleNumber" , &cycleNumber546);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray541 [100];
  double cycleNumberArray542 [100];
  double cycleNumberArray543 [100];
  double cycleNumberArray544 [100];
  double cycleNumberArray545 [100];
  double cycleNumberArray546 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral541;
  double UCNIntegral542;
  double UCNIntegral543;
  double UCNIntegral544;
  double UCNIntegral545;
  double UCNIntegral546;



  outputTree541 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral541);
  outputTree542 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral542);
  outputTree543 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral543);
  outputTree544 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral544);
  outputTree545 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral545);
  outputTree546 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral546);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray541 [100];
  double UCNIntegralArray542 [100];
  double UCNIntegralArray543 [100];
  double UCNIntegralArray544 [100];
  double UCNIntegralArray545 [100];
  double UCNIntegralArray546 [100];


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr541;
  double UCNIntegralErr542;
  double UCNIntegralErr543;
  double UCNIntegralErr544;
  double UCNIntegralErr545;
  double UCNIntegralErr546;


  outputTree541 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr541);
  outputTree542 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr542);
  outputTree543 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr543);
  outputTree544 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr544);
  outputTree545 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr545);
  outputTree546 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr546);


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray541 [100];
  double UCNIntegralErrArray542 [100];
  double UCNIntegralErrArray543 [100];
  double UCNIntegralErrArray544 [100];
  double UCNIntegralErrArray545 [100];
  double UCNIntegralErrArray546 [100];

  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral541;
  double HistIntegral542;
  double HistIntegral543;
  double HistIntegral544;
  double HistIntegral545;
  double HistIntegral546;

  outputTree541 -> SetBranchAddress ("HistIntegral" , &HistIntegral541); 
  outputTree542 -> SetBranchAddress ("HistIntegral" , &HistIntegral542);
  outputTree543 -> SetBranchAddress ("HistIntegral" , &HistIntegral543);
  outputTree544 -> SetBranchAddress ("HistIntegral" , &HistIntegral544);
  outputTree545 -> SetBranchAddress ("HistIntegral" , &HistIntegral545);
  outputTree546 -> SetBranchAddress ("HistIntegral" , &HistIntegral546);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray541 [100];
  double HistIntegralArray542 [100];
  double HistIntegralArray543 [100];
  double HistIntegralArray544 [100];
  double HistIntegralArray545 [100];
  double HistIntegralArray546 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr541;
  double HistIntegralErr542;
  double HistIntegralErr543;
  double HistIntegralErr544;
  double HistIntegralErr545;
  double HistIntegralErr546;

  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray541 [100];
  double HistIntegralErrArray542 [100];
  double HistIntegralErrArray543 [100];
  double HistIntegralErrArray544 [100];
  double HistIntegralErrArray545 [100];
  double HistIntegralErrArray546 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad541;
  double avets12Irrad542;
  double avets12Irrad543;
  double avets12Irrad544;
  double avets12Irrad545;
  double avets12Irrad546;

  outputTree541 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad541);
  outputTree542 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad542);
  outputTree543 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad543);
  outputTree544 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad544);
  outputTree545 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad545);
  outputTree546 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad546);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen541;
  double avets12ValveOpen542;
  double avets12ValveOpen543;
  double avets12ValveOpen544;
  double avets12ValveOpen545;
  double avets12ValveOpen546;

  outputTree541 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen541);
  outputTree542 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen542);
  outputTree543 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen543);
  outputTree544 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen544);
  outputTree545 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen545);
  outputTree546 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen546);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray541 [100];
  double avets12IrradArray542 [100];
  double avets12IrradArray543 [100];
  double avets12IrradArray544 [100];
  double avets12IrradArray545 [100];
  double avets12IrradArray546 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray541 [100];
  double avets12ValveOpenArray542 [100];
  double avets12ValveOpenArray543 [100];
  double avets12ValveOpenArray544 [100];
  double avets12ValveOpenArray545 [100];
  double avets12ValveOpenArray546 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad541;
  double maxts12Irrad542;
  double maxts12Irrad543;
  double maxts12Irrad544;
  double maxts12Irrad545;
  double maxts12Irrad546;

  outputTree541 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad541);
  outputTree542 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad542);
  outputTree543 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad543);
  outputTree544 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad544);
  outputTree545 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad545);
  outputTree546 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad546);
 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen541;
  double maxts12ValveOpen542;
  double maxts12ValveOpen543;
  double maxts12ValveOpen544;
  double maxts12ValveOpen545;
  double maxts12ValveOpen546;

  outputTree541 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen541);
  outputTree542 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen542);
  outputTree543 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen543);
  outputTree544 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen544);
  outputTree545 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen545);
  outputTree546 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen546);

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray541 [100];
  double maxts12IrradArray542 [100];
  double maxts12IrradArray543 [100];
  double maxts12IrradArray544 [100];
  double maxts12IrradArray545 [100];
  double maxts12IrradArray546 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray541 [100];
  double maxts12ValveOpenArray542 [100];
  double maxts12ValveOpenArray543 [100];
  double maxts12ValveOpenArray544 [100];
  double maxts12ValveOpenArray545 [100];
  double maxts12ValveOpenArray546 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad541;
  double mints12Irrad542;
  double mints12Irrad543;
  double mints12Irrad544;
  double mints12Irrad545;
  double mints12Irrad546;


  outputTree541 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad541);
  outputTree542 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad542);
  outputTree543 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad543);
  outputTree544 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad544);
  outputTree545 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad545);
  outputTree546 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad546);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen541;
  double mints12ValveOpen542;
  double mints12ValveOpen543;
  double mints12ValveOpen544;
  double mints12ValveOpen545;
  double mints12ValveOpen546;
  
  outputTree541 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen541);
  outputTree542 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen542);
  outputTree543 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen543);
  outputTree544 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen544);
  outputTree545 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen545);
  outputTree546 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen546);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray541 [100];
  double mints12IrradArray542 [100];
  double mints12IrradArray543 [100];
  double mints12IrradArray544 [100];
  double mints12IrradArray545 [100];
  double mints12IrradArray546 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray541 [100];
  double mints12ValveOpenArray542 [100];
  double mints12ValveOpenArray543 [100];
  double mints12ValveOpenArray544 [100];
  double mints12ValveOpenArray545 [100];
  double mints12ValveOpenArray546 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr541 [100];
  double ts12IrradErr542 [100];
  double ts12IrradErr543 [100];
  double ts12IrradErr544 [100];
  double ts12IrradErr545 [100];
  double ts12IrradErr546 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr541 [100];
  double ts12ValveOpenErr542 [100];
  double ts12ValveOpenErr543 [100];
  double ts12ValveOpenErr544 [100];
  double ts12ValveOpenErr545 [100];
  double ts12ValveOpenErr546 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur541;
  double avecur542;
  double avecur543;
  double avecur544;
  double avecur545;
  double avecur546;

  outputTree541 -> SetBranchAddress ("AVE_PRDCUR" , &avecur541);
  outputTree542 -> SetBranchAddress ("AVE_PRDCUR" , &avecur542);
  outputTree543 -> SetBranchAddress ("AVE_PRDCUR" , &avecur543);
  outputTree544 -> SetBranchAddress ("AVE_PRDCUR" , &avecur544);
  outputTree545 -> SetBranchAddress ("AVE_PRDCUR" , &avecur545);
  outputTree546 -> SetBranchAddress ("AVE_PRDCUR" , &avecur546);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray541 [100];
  double avecurArray542 [100];
  double avecurArray543 [100];
  double avecurArray544 [100];
  double avecurArray545 [100];
  double avecurArray546 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur541;
  double maxcur542;
  double maxcur543;
  double maxcur544;
  double maxcur545;
  double maxcur546;

  outputTree541 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur541);
  outputTree542 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur542);
  outputTree543 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur543);
  outputTree544 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur544);
  outputTree545 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur545);
  outputTree546 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur546);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray541 [100];
  double maxcurArray542 [100];
  double maxcurArray543 [100];
  double maxcurArray544 [100];
  double maxcurArray545 [100];
  double maxcurArray546 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur541;
  double mincur542;
  double mincur543;
  double mincur544;
  double mincur545;
  double mincur546;

  outputTree541 -> SetBranchAddress ("MIN_PRDCUR" , &mincur541);
  outputTree542 -> SetBranchAddress ("MIN_PRDCUR" , &mincur542);
  outputTree543 -> SetBranchAddress ("MIN_PRDCUR" , &mincur543);
  outputTree544 -> SetBranchAddress ("MIN_PRDCUR" , &mincur544);
  outputTree545 -> SetBranchAddress ("MIN_PRDCUR" , &mincur545);
  outputTree546 -> SetBranchAddress ("MIN_PRDCUR" , &mincur546);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray541 [100];
  double mincurArray542 [100];
  double mincurArray543 [100];
  double mincurArray544 [100];
  double mincurArray545 [100];
  double mincurArray546 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray541 [100];
  double ErrcurArray542 [100];
  double ErrcurArray543 [100];
  double ErrcurArray544 [100];
  double ErrcurArray545 [100];
  double ErrcurArray546 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline541;
  double Baseline542;
  double Baseline543;
  double Baseline544;
  double Baseline545;
  double Baseline546;

  outputTree541 -> SetBranchAddress ("Baseline" , &Baseline541);
  outputTree542 -> SetBranchAddress ("Baseline" , &Baseline542);
  outputTree543 -> SetBranchAddress ("Baseline" , &Baseline543);
  outputTree544 -> SetBranchAddress ("Baseline" , &Baseline544);
  outputTree545 -> SetBranchAddress ("Baseline" , &Baseline545);
  outputTree546 -> SetBranchAddress ("Baseline" , &Baseline546);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray541 [100];
  double BaselineArray542 [100];
  double BaselineArray543 [100];
  double BaselineArray544 [100];
  double BaselineArray545 [100];
  double BaselineArray546 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr541;
  double BaselineErr542;
  double BaselineErr543;
  double BaselineErr544;
  double BaselineErr545;
  double BaselineErr546;
 
  outputTree541 -> SetBranchAddress ("BaselineErr" , &BaselineErr541);
  outputTree542 -> SetBranchAddress ("BaselineErr" , &BaselineErr542);
  outputTree543 -> SetBranchAddress ("BaselineErr" , &BaselineErr543);
  outputTree544 -> SetBranchAddress ("BaselineErr" , &BaselineErr544);
  outputTree545 -> SetBranchAddress ("BaselineErr" , &BaselineErr545);
  outputTree546 -> SetBranchAddress ("BaselineErr" , &BaselineErr546);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray541 [100];
  double BaselineErrArray542 [100];
  double BaselineErrArray543 [100];
  double BaselineErrArray544 [100];
  double BaselineErrArray545 [100];
  double BaselineErrArray546 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad541;
  double BaselineIrrad542;
  double BaselineIrrad543;
  double BaselineIrrad544;
  double BaselineIrrad545;
  double BaselineIrrad546;
 
  outputTree541 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad541);
  outputTree542 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad542);
  outputTree543 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad543);
  outputTree544 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad544);
  outputTree545 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad545);
  outputTree546 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad546);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray541 [100];
  double BaselineIrradArray542 [100];
  double BaselineIrradArray543 [100];
  double BaselineIrradArray544 [100];
  double BaselineIrradArray545 [100];
  double BaselineIrradArray546 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr541;
  double BaselineIrradErr542;
  double BaselineIrradErr543;
  double BaselineIrradErr544;
  double BaselineIrradErr545;
  double BaselineIrradErr546;

  outputTree541 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr541);
  outputTree542 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr542);
  outputTree543 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr543);
  outputTree544 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr544);
  outputTree545 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr545);
  outputTree546 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr546);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray541 [100];
  double BaselineIrradErrArray542 [100];
  double BaselineIrradErrArray543 [100];
  double BaselineIrradErrArray544 [100];
  double BaselineIrradErrArray545 [100];
  double BaselineIrradErrArray546 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime541;
  double FallTime542;
  double FallTime543;
  double FallTime544;
  double FallTime545;
  double FallTime546;

  outputTree541 -> SetBranchAddress ("FallTime" , &FallTime541);
  outputTree542 -> SetBranchAddress ("FallTime" , &FallTime542);
  outputTree543 -> SetBranchAddress ("FallTime" , &FallTime543);
  outputTree544 -> SetBranchAddress ("FallTime" , &FallTime544);
  outputTree545 -> SetBranchAddress ("FallTime" , &FallTime545);
  outputTree546 -> SetBranchAddress ("FallTime" , &FallTime546);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray541 [100];
  double FallTimeArray542 [100];
  double FallTimeArray543 [100];
  double FallTimeArray544 [100];
  double FallTimeArray545 [100];
  double FallTimeArray546 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr541;
  double FallTimeErr542;
  double FallTimeErr543;
  double FallTimeErr544;
  double FallTimeErr545;
  double FallTimeErr546;

  outputTree541 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr541);
  outputTree542 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr542);
  outputTree543 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr543);
  outputTree544 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr544);
  outputTree545 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr545);
  outputTree546 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr546);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray541 [100];
  double FallTimeErrArray542 [100];
  double FallTimeErrArray543 [100];
  double FallTimeErrArray544 [100];
  double FallTimeErrArray545 [100];
  double FallTimeErrArray546 [100];

  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime541;
  double RiseTime542;
  double RiseTime543;
  double RiseTime544;
  double RiseTime545;
  double RiseTime546;

  outputTree541 -> SetBranchAddress ("RiseTime" , &RiseTime541);
  outputTree542 -> SetBranchAddress ("RiseTime" , &RiseTime542);
  outputTree543 -> SetBranchAddress ("RiseTime" , &RiseTime543);
  outputTree544 -> SetBranchAddress ("RiseTime" , &RiseTime544);
  outputTree545 -> SetBranchAddress ("RiseTime" , &RiseTime545);
  outputTree546 -> SetBranchAddress ("RiseTime" , &RiseTime546);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray541 [100];
  double RiseTimeArray542 [100];
  double RiseTimeArray543 [100];
  double RiseTimeArray544 [100];
  double RiseTimeArray545 [100];
  double RiseTimeArray546 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr541;
  double RiseTimeErr542;
  double RiseTimeErr543;
  double RiseTimeErr544;
  double RiseTimeErr545;
  double RiseTimeErr546;

  outputTree541 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr541);
  outputTree542 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr542);
  outputTree543 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr543);
  outputTree544 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr544);
  outputTree545 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr545);
  outputTree546 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr546);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray541 [100];
  double RiseTimeErrArray542 [100];
  double RiseTimeErrArray543 [100];
  double RiseTimeErrArray544 [100];
  double RiseTimeErrArray545 [100];
  double RiseTimeErrArray546 [100];


  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad541;
  double aveAllts12Irrad542;
  double aveAllts12Irrad543;
  double aveAllts12Irrad544;
  double aveAllts12Irrad545;
  double aveAllts12Irrad546;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad541;
  double aveAllErrts12Irrad542;
  double aveAllErrts12Irrad543;
  double aveAllErrts12Irrad544;
  double aveAllErrts12Irrad545;
  double aveAllErrts12Irrad546;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad541;
  double maxAllts12Irrad542;
  double maxAllts12Irrad543;
  double maxAllts12Irrad544;
  double maxAllts12Irrad545;
  double maxAllts12Irrad546;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad541;
  double minAllts12Irrad542;
  double minAllts12Irrad543;
  double minAllts12Irrad544;
  double minAllts12Irrad545;
  double minAllts12Irrad546;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage541;
  double storage542;
  double storage543;
  double storage544;
  double storage545;
  double storage546;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr541;
  double storageErr542;
  double storageErr543;
  double storageErr544;
  double storageErr545;
  double storageErr546;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_541 = 0;
  int counts_542 = 0;
  int counts_543 = 0;
  int counts_544 = 0;
  int counts_545 = 0;
  int counts_546 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events541;
  events541 = (Double_t)outputTree541 -> GetEntries();

  for (ULong64_t j = 0 ; j < events541 ; j++){
    outputTree541 -> GetEvent(j);
    if (j == 2)
      continue;
    UCNIntegralArray541[counts_541] = UCNIntegral541;
    UCNIntegralErrArray541[counts_541] = UCNIntegralErr541;
    HistIntegralArray541[counts_541] = HistIntegral541;
    HistIntegralErrArray541[counts_541] = sqrt (HistIntegral541);
    avets12IrradArray541[counts_541] = avets12Irrad541;
    avets12ValveOpenArray541[counts_541] = avets12ValveOpen541;
    maxts12IrradArray541[counts_541] = maxts12Irrad541;
    maxts12ValveOpenArray541[counts_541] = maxts12ValveOpen541;
    mints12IrradArray541[counts_541] = mints12Irrad541; 
    mints12ValveOpenArray541[counts_541] = mints12ValveOpen541;
    ts12IrradErr541[counts_541] = maxts12Irrad541 - mints12Irrad541;
    ts12ValveOpenErr541[counts_541] = maxts12ValveOpen541 - mints12ValveOpen541;
    avecurArray541[counts_541] = avecur541;
    maxcurArray541[counts_541] = maxcur541;
    mincurArray541[counts_541] = mincur541;
    ErrcurArray541[counts_541] = maxcur541 - mincur541;
    delaytimeArray541[counts_541] = cycleDelayTime541;
    cycleNumberArray541[counts_541] = cycleNumber541;
    BaselineArray541[counts_541] = Baseline541;
    BaselineIrradArray541[counts_541] = BaselineIrrad541;
    BaselineIrradErrArray541[counts_541] = BaselineIrradErr541;
    FallTimeArray541[counts_541] = FallTime541;
    FallTimeErrArray541[counts_541] = FallTimeErr541;
    RiseTimeArray541[counts_541] = RiseTime541;
    RiseTimeErrArray541[counts_541] = RiseTimeErr541;
    aveAllts12Irrad541 += avets12Irrad541;
    maxAllts12Irrad541 += maxts12Irrad541;
    minAllts12Irrad541 += mints12Irrad541;
    UCNIntegralArrayAll[counts_541] = UCNIntegral541;
    UCNIntegralErrArrayAll[counts_541] = UCNIntegralErr541;
    delayTimeAll[counts_541] = cycleDelayTime541;
    HistIntegralArrayAll[counts_541] = HistIntegral541;
    HistIntegralErrArrayAll[counts_541] = sqrt (HistIntegral541);
    counts_541++;
  }
  aveAllts12Irrad541 = aveAllts12Irrad541/counts_541;
  maxAllts12Irrad541 = maxAllts12Irrad541/counts_541;
  minAllts12Irrad541 = minAllts12Irrad541/counts_541;
  aveAllErrts12Irrad541 = maxAllts12Irrad541 - minAllts12Irrad541;

  ULong64_t events542;
  events542 = (Double_t)outputTree542 -> GetEntries();

  for (ULong64_t j = 0 ; j < events542 ; j++){
    outputTree542 -> GetEvent(j);
    UCNIntegralArray542[j] = UCNIntegral542;
    UCNIntegralErrArray542[j] = UCNIntegralErr542;
    HistIntegralArray542[j] = HistIntegral542;
    HistIntegralErrArray542[j] = sqrt (HistIntegral542);
    avets12IrradArray542[j] = avets12Irrad542;
    avets12ValveOpenArray542[j] = avets12ValveOpen542;
    maxts12IrradArray542[j] = maxts12Irrad542;
    maxts12ValveOpenArray542[j] = maxts12ValveOpen542;
    mints12IrradArray542[j] = mints12Irrad542; 
    mints12ValveOpenArray542[j] = mints12ValveOpen542;
    ts12IrradErr542[j] = maxts12Irrad542 - mints12Irrad542;
    ts12ValveOpenErr542[j] = maxts12ValveOpen542 - mints12ValveOpen542;
    avecurArray542[j] = avecur542;
    maxcurArray542[j] = maxcur542;
    mincurArray542[j] = mincur542;
    ErrcurArray542[j] = maxcur542 - mincur542;
    delaytimeArray542[j] = cycleDelayTime542;
    cycleNumberArray542[j] = cycleNumber542;
    BaselineArray542[j] = Baseline542;
    BaselineIrradArray542[j] = BaselineIrrad542;
    BaselineIrradErrArray542[j] = BaselineIrradErr542;
    FallTimeArray542[j] = FallTime542;
    FallTimeErrArray542[j] = FallTimeErr542;
    RiseTimeArray542[j] = RiseTime542;
    RiseTimeErrArray542[j] = RiseTimeErr542;
    aveAllts12Irrad542 += avets12Irrad542;
    maxAllts12Irrad542 += maxts12Irrad542;
    minAllts12Irrad542 += mints12Irrad542;
    cout << aveAllts12Irrad542 << endl;
    UCNIntegralArrayAll[counts_541+ counts_542] = UCNIntegral542;
    UCNIntegralErrArrayAll[counts_541+ counts_542] = UCNIntegralErr542;
    delayTimeAll[counts_541+ counts_542] = cycleDelayTime542;
    HistIntegralArrayAll[counts_541 + counts_542] = HistIntegral542;
    HistIntegralErrArrayAll[counts_541+counts_542] = sqrt (HistIntegral542);
    counts_542++;
  }
  aveAllts12Irrad542 = aveAllts12Irrad542/counts_542;
  maxAllts12Irrad542 = maxAllts12Irrad542/counts_542;
  minAllts12Irrad542 = minAllts12Irrad542/counts_542;
  aveAllErrts12Irrad542 = maxAllts12Irrad542 - minAllts12Irrad542;

  ULong64_t events543;
  events543 = (Double_t)outputTree543 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events543 ; j++){
    outputTree543 -> GetEvent(j);
    UCNIntegralArray543[counts_543] = UCNIntegral543;
    UCNIntegralErrArray543[counts_543] = UCNIntegralErr543;
    HistIntegralArray543[counts_543] = HistIntegral543;
    HistIntegralErrArray543[counts_543] = sqrt (HistIntegral543);
    avets12IrradArray543[counts_543] = avets12Irrad543;
    avets12ValveOpenArray543[counts_543] = avets12ValveOpen543;
    maxts12IrradArray543[counts_543] = maxts12Irrad543;
    maxts12ValveOpenArray543[counts_543] = maxts12ValveOpen543;
    mints12IrradArray543[counts_543] = mints12Irrad543; 
    mints12ValveOpenArray543[counts_543] = mints12ValveOpen543;
    ts12IrradErr543[counts_543] = maxts12Irrad543 - mints12Irrad543;
    ts12ValveOpenErr543[counts_543] = maxts12ValveOpen543 - mints12ValveOpen543;
    avecurArray543[counts_543] = avecur543;
    maxcurArray543[counts_543] = maxcur543;
    mincurArray543[counts_543] = mincur543;
    ErrcurArray543[counts_543] = maxcur543 - mincur543;
    delaytimeArray543[counts_543] = cycleDelayTime543;
    cycleNumberArray543[counts_543] = cycleNumber543;
    BaselineArray543[counts_543] = Baseline543;
    BaselineIrradArray543[counts_543] = BaselineIrrad543;
    BaselineIrradErrArray543[counts_543] = BaselineIrradErr543;
    FallTimeArray543[counts_543] = FallTime543;
    FallTimeErrArray543[counts_543] = FallTimeErr543;
    RiseTimeArray543[counts_543] = RiseTime543;
    RiseTimeErrArray543[counts_543] = RiseTimeErr543;
    aveAllts12Irrad543 += avets12Irrad543;
    maxAllts12Irrad543 += maxts12Irrad543;
    minAllts12Irrad543 += mints12Irrad543;
    UCNIntegralArrayAll[counts_541+ counts_542+counts_543] = UCNIntegral543;
    UCNIntegralErrArrayAll[counts_541+ counts_542+counts_543] = UCNIntegralErr543;
    delayTimeAll[counts_541+ counts_542+counts_543] = cycleDelayTime543;
    HistIntegralArrayAll[counts_541 + counts_542+ counts_543] = HistIntegral543;
    HistIntegralErrArrayAll[counts_541+counts_542+counts_543] = sqrt (HistIntegral543);
    counts_543++;
  }
  aveAllts12Irrad543 = aveAllts12Irrad543/counts_543;
  maxAllts12Irrad543 = maxAllts12Irrad543/counts_543;
  minAllts12Irrad543 = minAllts12Irrad543/counts_543;
  aveAllErrts12Irrad543 = maxAllts12Irrad543 - minAllts12Irrad543;
  
  ULong64_t events544;
  events544 = (Double_t)outputTree544 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events544 ; j++){
    outputTree544 -> GetEvent(j);
    UCNIntegralArray544[j] = UCNIntegral544;
    UCNIntegralErrArray544[j] = UCNIntegralErr544;
    HistIntegralArray544[j] = HistIntegral544;
    HistIntegralErrArray544[j] = sqrt (HistIntegral544);
    avets12IrradArray544[j] = avets12Irrad544;
    avets12ValveOpenArray544[j] = avets12ValveOpen544;
    maxts12IrradArray544[j] = maxts12Irrad544;
    maxts12ValveOpenArray544[j] = maxts12ValveOpen544;
    mints12IrradArray544[j] = mints12Irrad544; 
    mints12ValveOpenArray544[j] = mints12ValveOpen544;
    ts12IrradErr544[j] = maxts12Irrad544 - mints12Irrad544;
    ts12ValveOpenErr544[j] = maxts12ValveOpen544 - mints12ValveOpen544;
    avecurArray544[j] = avecur544;
    maxcurArray544[j] = maxcur544;
    mincurArray544[j] = mincur544;
    ErrcurArray544[j] = maxcur544 - mincur544;
    delaytimeArray544[j] = cycleDelayTime544;
    cycleNumberArray544[j] = cycleNumber544;
    BaselineArray544[j] = Baseline544;
    BaselineIrradArray544[j] = BaselineIrrad544;
    BaselineIrradErrArray544[j] = BaselineIrradErr544;
    FallTimeArray544[j] = FallTime544;
    FallTimeErrArray544[j] = FallTimeErr544;
    RiseTimeArray544[j] = RiseTime544;
    RiseTimeErrArray544[j] = RiseTimeErr544;
    aveAllts12Irrad544 += avets12Irrad544;
    maxAllts12Irrad544 += maxts12Irrad544;
    minAllts12Irrad544 += mints12Irrad544;
    UCNIntegralArrayAll[counts_541+ counts_542+counts_543+counts_544] = UCNIntegral544;
    UCNIntegralErrArrayAll[counts_541+ counts_542+counts_543+counts_544] = UCNIntegralErr544;
    delayTimeAll[counts_541+ counts_542+counts_543+counts_544] = cycleDelayTime544;
    HistIntegralArrayAll[counts_541 + counts_542+ counts_543+ counts_544] = HistIntegral544;
    HistIntegralErrArrayAll[counts_541+counts_542+counts_543+counts_544] = sqrt (HistIntegral544);
    counts_544++;
  }
  aveAllts12Irrad544 = aveAllts12Irrad544/counts_544;
  maxAllts12Irrad544 = maxAllts12Irrad544/counts_544;
  minAllts12Irrad544 = minAllts12Irrad544/counts_544;
  aveAllErrts12Irrad544 = maxAllts12Irrad544 - minAllts12Irrad544;
  
  ULong64_t events545;
  events545 = (Double_t)outputTree545 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events545 ; j++){
    outputTree545 -> GetEvent(j);
    if (j == 4)
      continue;
    UCNIntegralArray545[counts_545] = UCNIntegral545;
    UCNIntegralErrArray545[counts_545] = UCNIntegralErr545;
    HistIntegralArray545[counts_545] = HistIntegral545;
    HistIntegralErrArray545[counts_545] = sqrt (HistIntegral545);
    avets12IrradArray545[counts_545] = avets12Irrad545;
    avets12ValveOpenArray545[counts_545] = avets12ValveOpen545;
    maxts12IrradArray545[counts_545] = maxts12Irrad545;
    maxts12ValveOpenArray545[counts_545] = maxts12ValveOpen545;
    mints12IrradArray545[counts_545] = mints12Irrad545; 
    mints12ValveOpenArray545[counts_545] = mints12ValveOpen545;
    ts12IrradErr545[counts_545] = maxts12Irrad545 - mints12Irrad545;
    ts12ValveOpenErr545[counts_545] = maxts12ValveOpen545 - mints12ValveOpen545;
    avecurArray545[counts_545] = avecur545;
    maxcurArray545[counts_545] = maxcur545;
    mincurArray545[counts_545] = mincur545;
    ErrcurArray545[counts_545] = maxcur545 - mincur545;
    delaytimeArray545[counts_545] = cycleDelayTime545;
    cycleNumberArray545[counts_545] = cycleNumber545;
    BaselineArray545[counts_545] = Baseline545;
    BaselineIrradArray545[counts_545] = BaselineIrrad545;
    BaselineIrradErrArray545[counts_545] = BaselineIrradErr545;
    FallTimeArray545[counts_545] = FallTime545;
    FallTimeErrArray545[counts_545] = FallTimeErr545;
    RiseTimeArray545[counts_545] = RiseTime545;
    RiseTimeErrArray545[counts_545] = RiseTimeErr545;
    aveAllts12Irrad545 += avets12Irrad545;
    maxAllts12Irrad545 += maxts12Irrad545;
    minAllts12Irrad545 += mints12Irrad545;
    UCNIntegralArrayAll[counts_541+ counts_542+counts_543+counts_544 + counts_545] = UCNIntegral545;
    UCNIntegralErrArrayAll[counts_541+ counts_542+counts_543+counts_544 + counts_545] = UCNIntegralErr545;
    delayTimeAll[counts_541+ counts_542+counts_543+counts_544+ counts_545] = cycleDelayTime545;
    HistIntegralArrayAll[counts_541 + counts_542+ counts_543+ counts_544+counts_545] = HistIntegral545;
    HistIntegralErrArrayAll[counts_541+counts_542+counts_543+counts_544+counts_545] = sqrt (HistIntegral545);
    counts_545++;
  }
  aveAllts12Irrad545 = aveAllts12Irrad545/counts_545;
  maxAllts12Irrad545 = maxAllts12Irrad545/counts_545;
  minAllts12Irrad545 = minAllts12Irrad545/counts_545;
  aveAllErrts12Irrad545 = maxAllts12Irrad545 - minAllts12Irrad545;

  ULong64_t events546;
  events546 = (Double_t)outputTree546 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events546 ; j++){
    outputTree546 -> GetEvent(j);
    UCNIntegralArray546[counts_546] = UCNIntegral546;
    UCNIntegralErrArray546[counts_546] = UCNIntegralErr546;
    HistIntegralArray546[counts_546] = HistIntegral546;
    HistIntegralErrArray546[counts_546] = sqrt (HistIntegral546);
    avets12IrradArray546[counts_546] = avets12Irrad546;
    avets12ValveOpenArray546[counts_546] = avets12ValveOpen546;
    maxts12IrradArray546[counts_546] = maxts12Irrad546;
    maxts12ValveOpenArray546[counts_546] = maxts12ValveOpen546;
    mints12IrradArray546[counts_546] = mints12Irrad546; 
    mints12ValveOpenArray546[counts_546] = mints12ValveOpen546;
    ts12IrradErr546[counts_546] = maxts12Irrad546 - mints12Irrad546;
    ts12ValveOpenErr546[counts_546] = maxts12ValveOpen546 - mints12ValveOpen546;
    avecurArray546[counts_546] = avecur546;
    maxcurArray546[counts_546] = maxcur546;
    mincurArray546[counts_546] = mincur546;
    ErrcurArray546[counts_546] = maxcur546 - mincur546;
    delaytimeArray546[counts_546] = cycleDelayTime546;
    cycleNumberArray546[counts_546] = cycleNumber546;
    BaselineArray546[counts_546] = Baseline546;
    BaselineIrradArray546[counts_546] = BaselineIrrad546;
    BaselineIrradErrArray546[counts_546] = BaselineIrradErr546;
    FallTimeArray546[counts_546] = FallTime546;
    FallTimeErrArray546[counts_546] = FallTimeErr546;
    RiseTimeArray546[counts_546] = RiseTime546;
    RiseTimeErrArray546[counts_546] = RiseTimeErr546;
    aveAllts12Irrad546 += avets12Irrad546;
    maxAllts12Irrad546 += maxts12Irrad546;
    minAllts12Irrad546 += mints12Irrad546;
    UCNIntegralArrayAll[counts_541+ counts_542+counts_543+counts_544 + counts_545 + counts_546] = UCNIntegral546;
    UCNIntegralErrArrayAll[counts_541+ counts_542+counts_543+counts_544 + counts_545+counts_546] = UCNIntegralErr546;
    delayTimeAll[counts_541+ counts_542+counts_543+counts_544+ counts_545+counts_546] = cycleDelayTime546;
    HistIntegralArrayAll[counts_541 + counts_542+ counts_543+ counts_544+counts_545+counts_546] = HistIntegral546;
    HistIntegralErrArrayAll[counts_541+counts_542+counts_543+counts_544+counts_545+counts_546] = sqrt (HistIntegral546);
    counts_546++;
  }
  aveAllts12Irrad546 = aveAllts12Irrad546/counts_546;
  maxAllts12Irrad546 = maxAllts12Irrad546/counts_546;
  minAllts12Irrad546 = minAllts12Irrad546/counts_546;
  aveAllErrts12Irrad546 = maxAllts12Irrad546 - minAllts12Irrad546;




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
  //              541
  //*********************************
  //*********************************
  TCanvas *c541 = new TCanvas("c541" , "c541" , 1200, 800);
  c541 -> Divide(2,2);
  //c541 -> cd(1);
  TPad *p1 = c541->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr541_delaycounts = new TGraphErrors(counts_541, delaytimeArray541 , UCNIntegralArray541, 0, UCNIntegralErrArray541);

  gr541_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr541_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr541_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr541_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr541_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_delaycounts -> SetMarkerStyle(7);
  gr541_delaycounts -> Fit(fit);
  storage541 = fit -> GetParameter(1);
  storageErr541 = fit -> GetParError(1);
  
  TGraphErrors *gr541_delayhist = new TGraphErrors(counts_541, delaytimeArray541 , HistIntegralArray541, 0, HistIntegralErrArray541);

  gr541_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr541_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr541_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr541_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr541_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr541_delayhist -> SetMarkerColor(2);
  gr541_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr541_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr541_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr541_delaycounts -> Draw("Ap");
  gr541_delayhist -> Draw("p");
  leg2 -> Draw();

  //c541 -> cd(2);
  TPad *p2 = c541->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr541_tempIrradcounts = new TGraphErrors (counts_541 , avets12IrradArray541, UCNIntegralArray541 , ts12IrradErr541 , UCNIntegralErrArray541);
  gr541_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr541_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr541_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr541_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr541_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr541_tempValveOpencounts = new TGraphErrors (counts_541 , avets12ValveOpenArray541, UCNIntegralArray541 , ts12ValveOpenErr541 , UCNIntegralErrArray541);
  gr541_tempValveOpencounts -> SetMarkerStyle(7);
  gr541_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr541_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr541_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr541_tempIrradcounts -> Draw("Ap");
  gr541_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c541 -> cd(3);
  TGraphErrors *gr541_delaytempIrrad = new TGraphErrors (counts_541 , delaytimeArray541, avets12IrradArray541, 0 , ts12IrradErr541);

  gr541_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr541_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr541_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr541_delaytempIrrad -> SetMarkerStyle(7);
  gr541_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr541_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr541_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr541_delaytempValveOpen = new TGraphErrors (counts_541 , delaytimeArray541, avets12ValveOpenArray541, 0 , ts12ValveOpenErr541);

  gr541_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr541_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr541_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr541_delaytempValveOpen -> SetMarkerStyle(7);
  gr541_delaytempValveOpen -> SetMarkerColor(2);
  gr541_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr541_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr541_delaytempIrrad -> Draw("AP");
  gr541_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c541->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr541_curcounts = new TGraphErrors (counts_541 , avecurArray541, UCNIntegralArray541 , ErrcurArray541 , UCNIntegralErrArray541);
  gr541_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr541_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr541_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr541_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr541_curhist = new TGraphErrors (counts_541 , avecurArray541, UCNIntegralArray541 , ErrcurArray541 , UCNIntegralErrArray541);
  gr541_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr541_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr541_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr541_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr541_curhist -> SetMarkerColor(2);
  gr541_curhist -> SetMarkerStyle(7);

  gr541_curcounts -> Draw("Ap");
  gr541_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c541_cycleNum = new TCanvas("c541_cycleNum" , "c541_cycleNum" , 1200, 800);
  c541_cycleNum -> Divide(2,2);
  TPad *p5 = c541_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr541_cyclecounts = new TGraphErrors (counts_541 , cycleNumberArray541, UCNIntegralArray541, 0 , UCNIntegralErrArray541);
  gr541_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr541_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr541_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr541_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr541_cyclehist = new TGraphErrors(counts_541, cycleNumberArray541 , HistIntegralArray541, 0, HistIntegralErrArray541);

  gr541_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr541_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr541_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr541_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr541_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr541_cyclehist -> SetMarkerColor(2);
  gr541_cyclehist -> SetMarkerStyle(7);

  gr541_cyclecounts -> Draw("Ap");
  gr541_cyclehist -> Draw("p");

  leg2-> Draw();

  c541_cycleNum -> cd(2);
 TGraphErrors *gr541_cycledelay = new TGraphErrors (counts_541 , cycleNumberArray541, delaytimeArray541, 0 , 0);
  gr541_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr541_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr541_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr541_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cycledelay -> SetMarkerStyle(7);

  gr541_cycledelay -> Draw("Ap");


  c541_cycleNum -> cd(3);
  TGraphErrors *gr541_cycletempIrrad = new TGraphErrors (counts_541 , cycleNumberArray541, avets12IrradArray541, 0 , ts12IrradErr541);

  gr541_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr541_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr541_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr541_cycletempIrrad -> SetMarkerStyle(7);
  gr541_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr541_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr541_cycletempValveOpen = new TGraphErrors (counts_541 , cycleNumberArray541, avets12ValveOpenArray541, 0 , ts12ValveOpenErr541);

  gr541_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr541_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr541_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr541_cycletempValveOpen -> SetMarkerStyle(7);
  gr541_cycletempValveOpen -> SetMarkerColor(2);
  gr541_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr541_cycletempIrrad -> Draw("AP");
  gr541_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c541_cycleNum -> cd(4);
  TGraphErrors *gr541_cyclecur = new TGraphErrors (counts_541 , cycleNumberArray541 , avecurArray541, 0, ErrcurArray541 );
  gr541_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr541_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr541_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr541_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclecur -> SetMarkerStyle(7);
  gr541_cyclecur -> Draw("Ap");


  TCanvas *c541_cycleNumFit = new TCanvas("c541_cycleNumFit" , "c541_cycleNumFit" , 1200, 800);
  c541_cycleNumFit -> Divide(2,2);

  c541_cycleNumFit -> cd(1);
  TGraphErrors *gr541_cyclefall = new TGraphErrors (counts_541, cycleNumberArray541, FallTimeArray541 , 0, FallTimeErrArray541);

  gr541_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr541_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr541_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr541_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclefall -> SetMarkerStyle(7);
  gr541_cyclefall -> Draw("Ap");


  c541_cycleNumFit -> cd(2);
  TGraphErrors *gr541_cyclebaseline = new TGraphErrors (counts_541, cycleNumberArray541, BaselineArray541 , 0, BaselineErrArray541);

  gr541_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr541_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr541_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr541_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclebaseline -> SetMarkerStyle(7);
  gr541_cyclebaseline -> Draw("Ap");

  c541_cycleNumFit -> cd(3);
  TGraphErrors *gr541_cyclebaselineirrad = new TGraphErrors (counts_541, cycleNumberArray541, BaselineIrradArray541 , 0, BaselineIrradErrArray541);

  gr541_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr541_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr541_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr541_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclebaselineirrad -> SetMarkerStyle(7);
  gr541_cyclebaselineirrad -> Draw("Ap");

  c541_cycleNumFit -> cd(4);
  TGraphErrors *gr541_cyclerise = new TGraphErrors (counts_541, cycleNumberArray541, RiseTimeArray541 , 0, RiseTimeErrArray541);

  gr541_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr541_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr541_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr541_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr541_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr541_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr541_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr541_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr541_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr541_cyclerise -> SetMarkerStyle(7);
  gr541_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              542
  //*********************************
  //*********************************
  TCanvas *c542 = new TCanvas("c542" , "c542" , 1200, 800);
  c542 -> Divide(2,2);
  //c542 -> cd(1);
  TPad *p542_1 = c542->cd(1);
  p542_1->SetLogy(); 
  TGraphErrors *gr542_delaycounts = new TGraphErrors(counts_542, delaytimeArray542 , UCNIntegralArray542, 0, UCNIntegralErrArray542);

  gr542_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr542_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr542_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr542_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr542_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_delaycounts -> SetMarkerStyle(7);
  gr542_delaycounts -> Fit(fit);
  storage542 = fit -> GetParameter(1);
  storageErr542 = fit -> GetParError(1);
  
  TGraphErrors *gr542_delayhist = new TGraphErrors(counts_542, delaytimeArray542 , HistIntegralArray542, 0, HistIntegralErrArray542);

  gr542_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr542_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr542_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr542_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr542_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr542_delayhist -> SetMarkerColor(2);
  gr542_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr542_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr542_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr542_delaycounts -> Draw("Ap");
  gr542_delayhist -> Draw("p");
  leg2 -> Draw();

  //c542 -> cd(2);
  TPad *p542_2 = c542->cd(2);
  p542_2->SetLogy(); 
  TGraphErrors *gr542_tempIrradcounts = new TGraphErrors (counts_542 , avets12IrradArray542, UCNIntegralArray542 , ts12IrradErr542 , UCNIntegralErrArray542);
  gr542_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr542_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr542_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr542_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr542_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr542_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr542_tempValveOpencounts = new TGraphErrors (counts_542 , avets12ValveOpenArray542, UCNIntegralArray542 , ts12ValveOpenErr542 , UCNIntegralErrArray542);
  gr542_tempValveOpencounts -> SetMarkerStyle(7);
  gr542_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr542_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr542_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr542_tempIrradcounts -> Draw("Ap");
  gr542_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c542 -> cd(3);
  TGraphErrors *gr542_delaytempIrrad = new TGraphErrors (counts_542 , delaytimeArray542, avets12IrradArray542, 0 , ts12IrradErr542);

  gr542_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr542_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr542_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr542_delaytempIrrad -> SetMarkerStyle(7);
  gr542_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr542_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr542_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr542_delaytempValveOpen = new TGraphErrors (counts_542 , delaytimeArray542, avets12ValveOpenArray542, 0 , ts12ValveOpenErr542);

  gr542_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr542_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr542_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr542_delaytempValveOpen -> SetMarkerStyle(7);
  gr542_delaytempValveOpen -> SetMarkerColor(2);
  gr542_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr542_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr542_delaytempIrrad -> Draw("AP");
  gr542_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p542_3 = c542->cd(4);
  p542_3->SetLogy(); 
  TGraphErrors *gr542_curcounts = new TGraphErrors (counts_542 , avecurArray542, UCNIntegralArray542 , ErrcurArray542 , UCNIntegralErrArray542);
  gr542_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr542_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr542_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr542_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr542_curhist = new TGraphErrors (counts_542 , avecurArray542, UCNIntegralArray542 , ErrcurArray542 , UCNIntegralErrArray542);
  gr542_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr542_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr542_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr542_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr542_curhist -> SetMarkerColor(2);
  gr542_curhist -> SetMarkerStyle(7);

  gr542_curcounts -> Draw("Ap");
  gr542_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c542_cycleNum = new TCanvas("c542_cycleNum" , "c542_cycleNum" , 1200, 800);
  c542_cycleNum -> Divide(2,2);
  TPad *p542_4 = c542_cycleNum->cd(1);
  p542_4->SetLogy(); 
  TGraphErrors *gr542_cyclecounts = new TGraphErrors (counts_542 , cycleNumberArray542, UCNIntegralArray542, 0 , UCNIntegralErrArray542);
  gr542_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr542_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr542_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr542_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr542_cyclehist = new TGraphErrors(counts_542, cycleNumberArray542 , HistIntegralArray542, 0, HistIntegralErrArray542);

  gr542_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr542_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr542_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr542_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr542_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr542_cyclehist -> SetMarkerColor(2);
  gr542_cyclehist -> SetMarkerStyle(7);

  gr542_cyclecounts -> Draw("Ap");
  gr542_cyclehist -> Draw("p");

  leg2-> Draw();

  c542_cycleNum -> cd(2);
 TGraphErrors *gr542_cycledelay = new TGraphErrors (counts_542 , cycleNumberArray542, delaytimeArray542, 0 , 0);
  gr542_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr542_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr542_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr542_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cycledelay -> SetMarkerStyle(7);

  gr542_cycledelay -> Draw("Ap");


  c542_cycleNum -> cd(3);
  TGraphErrors *gr542_cycletempIrrad = new TGraphErrors (counts_542 , cycleNumberArray542, avets12IrradArray542, 0 , ts12IrradErr542);

  gr542_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr542_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr542_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr542_cycletempIrrad -> SetMarkerStyle(7);
  gr542_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr542_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr542_cycletempValveOpen = new TGraphErrors (counts_542 , cycleNumberArray542, avets12ValveOpenArray542, 0 , ts12ValveOpenErr542);

  gr542_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr542_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr542_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr542_cycletempValveOpen -> SetMarkerStyle(7);
  gr542_cycletempValveOpen -> SetMarkerColor(2);
  gr542_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr542_cycletempIrrad -> Draw("AP");
  gr542_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c542_cycleNum -> cd(4);
  TGraphErrors *gr542_cyclecur = new TGraphErrors (counts_542 , cycleNumberArray542 , avecurArray542, 0, ErrcurArray542 );
  gr542_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr542_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr542_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr542_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclecur -> SetMarkerStyle(7);
  gr542_cyclecur -> Draw("Ap");


  TCanvas *c542_cycleNumFit = new TCanvas("c542_cycleNumFit" , "c542_cycleNumFit" , 1200, 800);
  c542_cycleNumFit -> Divide(2,2);

  c542_cycleNumFit -> cd(1);
  TGraphErrors *gr542_cyclefall = new TGraphErrors (counts_542, cycleNumberArray542, FallTimeArray542 , 0, FallTimeErrArray542);

  gr542_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr542_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr542_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr542_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclefall -> SetMarkerStyle(7);
  gr542_cyclefall -> Draw("Ap");


  c542_cycleNumFit -> cd(2);
  TGraphErrors *gr542_cyclebaseline = new TGraphErrors (counts_542, cycleNumberArray542, BaselineArray542 , 0, BaselineErrArray542);

  gr542_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr542_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr542_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr542_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclebaseline -> SetMarkerStyle(7);
  gr542_cyclebaseline -> Draw("Ap");

  c542_cycleNumFit -> cd(3);
  TGraphErrors *gr542_cyclebaselineirrad = new TGraphErrors (counts_542, cycleNumberArray542, BaselineIrradArray542 , 0, BaselineIrradErrArray542);

  gr542_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr542_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr542_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr542_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclebaselineirrad -> SetMarkerStyle(7);
  gr542_cyclebaselineirrad -> Draw("Ap");

  c542_cycleNumFit -> cd(4);
  TGraphErrors *gr542_cyclerise = new TGraphErrors (counts_542, cycleNumberArray542, RiseTimeArray542 , 0, RiseTimeErrArray542);

  gr542_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr542_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr542_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr542_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr542_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr542_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr542_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr542_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr542_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr542_cyclerise -> SetMarkerStyle(7);
  gr542_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              543
  //*********************************
  //*********************************
  TCanvas *c543 = new TCanvas("c543" , "c543" , 1200, 800);
  c543 -> Divide(2,2);
  //c543 -> cd(1);
  TPad *p543_1 = c543->cd(1);
  p543_1->SetLogy(); 
  TGraphErrors *gr543_delaycounts = new TGraphErrors(counts_543, delaytimeArray543 , UCNIntegralArray543, 0, UCNIntegralErrArray543);

  gr543_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr543_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr543_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr543_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr543_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_delaycounts -> SetMarkerStyle(7);
  gr543_delaycounts -> Fit(fit);
  storage543 = fit -> GetParameter(1);
  storageErr543 = fit -> GetParError(1);
  
  TGraphErrors *gr543_delayhist = new TGraphErrors(counts_543, delaytimeArray543 , HistIntegralArray543, 0, HistIntegralErrArray543);

  gr543_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr543_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr543_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr543_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr543_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr543_delayhist -> SetMarkerColor(2);
  gr543_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr543_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr543_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr543_delaycounts -> Draw("Ap");
  gr543_delayhist -> Draw("p");
  leg2 -> Draw();

  //c543 -> cd(2);
  TPad *p543_2 = c543->cd(2);
  p543_2->SetLogy(); 
  TGraphErrors *gr543_tempIrradcounts = new TGraphErrors (counts_543 , avets12IrradArray543, UCNIntegralArray543 , ts12IrradErr543 , UCNIntegralErrArray543);
  gr543_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr543_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr543_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr543_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr543_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr543_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr543_tempValveOpencounts = new TGraphErrors (counts_543 , avets12ValveOpenArray543, UCNIntegralArray543 , ts12ValveOpenErr543 , UCNIntegralErrArray543);
  gr543_tempValveOpencounts -> SetMarkerStyle(7);
  gr543_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr543_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr543_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr543_tempIrradcounts -> Draw("Ap");
  gr543_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c543 -> cd(3);
  TGraphErrors *gr543_delaytempIrrad = new TGraphErrors (counts_543 , delaytimeArray543, avets12IrradArray543, 0 , ts12IrradErr543);

  gr543_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr543_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr543_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr543_delaytempIrrad -> SetMarkerStyle(7);
  gr543_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr543_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr543_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr543_delaytempValveOpen = new TGraphErrors (counts_543 , delaytimeArray543, avets12ValveOpenArray543, 0 , ts12ValveOpenErr543);

  gr543_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr543_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr543_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr543_delaytempValveOpen -> SetMarkerStyle(7);
  gr543_delaytempValveOpen -> SetMarkerColor(2);
  gr543_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr543_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr543_delaytempIrrad -> Draw("AP");
  gr543_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p543_3 = c543->cd(4);
  p543_3->SetLogy(); 
  TGraphErrors *gr543_curcounts = new TGraphErrors (counts_543 , avecurArray543, UCNIntegralArray543 , ErrcurArray543 , UCNIntegralErrArray543);
  gr543_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr543_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr543_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr543_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr543_curhist = new TGraphErrors (counts_543 , avecurArray543, UCNIntegralArray543 , ErrcurArray543 , UCNIntegralErrArray543);
  gr543_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr543_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr543_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr543_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr543_curhist -> SetMarkerColor(2);
  gr543_curhist -> SetMarkerStyle(7);

  gr543_curcounts -> Draw("Ap");
  gr543_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c543_cycleNum = new TCanvas("c543_cycleNum" , "c543_cycleNum" , 1200, 800);
  c543_cycleNum -> Divide(2,2);
  TPad *p543_4 = c543_cycleNum->cd(1);
  p543_4->SetLogy(); 
  TGraphErrors *gr543_cyclecounts = new TGraphErrors (counts_543 , cycleNumberArray543, UCNIntegralArray543, 0 , UCNIntegralErrArray543);
  gr543_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr543_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr543_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr543_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr543_cyclehist = new TGraphErrors(counts_543, cycleNumberArray543 , HistIntegralArray543, 0, HistIntegralErrArray543);

  gr543_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr543_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr543_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr543_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr543_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr543_cyclehist -> SetMarkerColor(2);
  gr543_cyclehist -> SetMarkerStyle(7);

  gr543_cyclecounts -> Draw("Ap");
  gr543_cyclehist -> Draw("p");

  leg2-> Draw();

  c543_cycleNum -> cd(2);
 TGraphErrors *gr543_cycledelay = new TGraphErrors (counts_543 , cycleNumberArray543, delaytimeArray543, 0 , 0);
  gr543_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr543_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr543_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr543_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cycledelay -> SetMarkerStyle(7);

  gr543_cycledelay -> Draw("Ap");


  c543_cycleNum -> cd(3);
  TGraphErrors *gr543_cycletempIrrad = new TGraphErrors (counts_543 , cycleNumberArray543, avets12IrradArray543, 0 , ts12IrradErr543);

  gr543_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr543_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr543_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr543_cycletempIrrad -> SetMarkerStyle(7);
  gr543_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr543_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr543_cycletempValveOpen = new TGraphErrors (counts_543 , cycleNumberArray543, avets12ValveOpenArray543, 0 , ts12ValveOpenErr543);

  gr543_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr543_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr543_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr543_cycletempValveOpen -> SetMarkerStyle(7);
  gr543_cycletempValveOpen -> SetMarkerColor(2);
  gr543_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr543_cycletempIrrad -> Draw("AP");
  gr543_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c543_cycleNum -> cd(4);
  TGraphErrors *gr543_cyclecur = new TGraphErrors (counts_543 , cycleNumberArray543 , avecurArray543, 0, ErrcurArray543 );
  gr543_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr543_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr543_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr543_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclecur -> SetMarkerStyle(7);
  gr543_cyclecur -> Draw("Ap");


  TCanvas *c543_cycleNumFit = new TCanvas("c543_cycleNumFit" , "c543_cycleNumFit" , 1200, 800);
  c543_cycleNumFit -> Divide(2,2);

  c543_cycleNumFit -> cd(1);
  TGraphErrors *gr543_cyclefall = new TGraphErrors (counts_543, cycleNumberArray543, FallTimeArray543 , 0, FallTimeErrArray543);

  gr543_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr543_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr543_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr543_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclefall -> SetMarkerStyle(7);
  gr543_cyclefall -> Draw("Ap");


  c543_cycleNumFit -> cd(2);
  TGraphErrors *gr543_cyclebaseline = new TGraphErrors (counts_543, cycleNumberArray543, BaselineArray543 , 0, BaselineErrArray543);

  gr543_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr543_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr543_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr543_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclebaseline -> SetMarkerStyle(7);
  gr543_cyclebaseline -> Draw("Ap");

  c543_cycleNumFit -> cd(3);
  TGraphErrors *gr543_cyclebaselineirrad = new TGraphErrors (counts_543, cycleNumberArray543, BaselineIrradArray543 , 0, BaselineIrradErrArray543);

  gr543_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr543_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr543_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr543_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclebaselineirrad -> SetMarkerStyle(7);
  gr543_cyclebaselineirrad -> Draw("Ap");

  c543_cycleNumFit -> cd(4);
  TGraphErrors *gr543_cyclerise = new TGraphErrors (counts_543, cycleNumberArray543, RiseTimeArray543 , 0, RiseTimeErrArray543);

  gr543_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr543_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr543_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr543_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr543_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr543_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr543_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr543_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr543_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr543_cyclerise -> SetMarkerStyle(7);
  gr543_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              544
  //*********************************
  //*********************************
  TCanvas *c544 = new TCanvas("c544" , "c544" , 1200, 800);
  c544 -> Divide(2,2);
  //c544 -> cd(1);
  TPad *p544_1 = c544->cd(1);
  p544_1->SetLogy(); 
  TGraphErrors *gr544_delaycounts = new TGraphErrors(counts_544, delaytimeArray544 , UCNIntegralArray544, 0, UCNIntegralErrArray544);

  gr544_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr544_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr544_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr544_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr544_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_delaycounts -> SetMarkerStyle(7);
  gr544_delaycounts -> Fit(fit);
  storage544 = fit -> GetParameter(1);
  storageErr544 = fit -> GetParError(1);
  
  TGraphErrors *gr544_delayhist = new TGraphErrors(counts_544, delaytimeArray544 , HistIntegralArray544, 0, HistIntegralErrArray544);

  gr544_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr544_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr544_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr544_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr544_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr544_delayhist -> SetMarkerColor(2);
  gr544_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr544_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr544_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr544_delaycounts -> Draw("Ap");
  gr544_delayhist -> Draw("p");
  leg2 -> Draw();

  //c544 -> cd(2);
  TPad *p544_2 = c544->cd(2);
  p544_2->SetLogy(); 
  TGraphErrors *gr544_tempIrradcounts = new TGraphErrors (counts_544 , avets12IrradArray544, UCNIntegralArray544 , ts12IrradErr544 , UCNIntegralErrArray544);
  gr544_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr544_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr544_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr544_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr544_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr544_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr544_tempValveOpencounts = new TGraphErrors (counts_544 , avets12ValveOpenArray544, UCNIntegralArray544 , ts12ValveOpenErr544 , UCNIntegralErrArray544);
  gr544_tempValveOpencounts -> SetMarkerStyle(7);
  gr544_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr544_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr544_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr544_tempIrradcounts -> Draw("Ap");
  gr544_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c544 -> cd(3);
  TGraphErrors *gr544_delaytempIrrad = new TGraphErrors (counts_544 , delaytimeArray544, avets12IrradArray544, 0 , ts12IrradErr544);

  gr544_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr544_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr544_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr544_delaytempIrrad -> SetMarkerStyle(7);
  gr544_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr544_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr544_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr544_delaytempValveOpen = new TGraphErrors (counts_544 , delaytimeArray544, avets12ValveOpenArray544, 0 , ts12ValveOpenErr544);

  gr544_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr544_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr544_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr544_delaytempValveOpen -> SetMarkerStyle(7);
  gr544_delaytempValveOpen -> SetMarkerColor(2);
  gr544_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr544_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr544_delaytempIrrad -> Draw("AP");
  gr544_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p544_3 = c544->cd(4);
  p544_3->SetLogy(); 
  TGraphErrors *gr544_curcounts = new TGraphErrors (counts_544 , avecurArray544, UCNIntegralArray544 , ErrcurArray544 , UCNIntegralErrArray544);
  gr544_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr544_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr544_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr544_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr544_curhist = new TGraphErrors (counts_544 , avecurArray544, UCNIntegralArray544 , ErrcurArray544 , UCNIntegralErrArray544);
  gr544_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr544_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr544_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr544_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr544_curhist -> SetMarkerColor(2);
  gr544_curhist -> SetMarkerStyle(7);

  gr544_curcounts -> Draw("Ap");
  gr544_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c544_cycleNum = new TCanvas("c544_cycleNum" , "c544_cycleNum" , 1200, 800);
  c544_cycleNum -> Divide(2,2);
  TPad *p544_4 = c544_cycleNum->cd(1);
  p544_4->SetLogy(); 
  TGraphErrors *gr544_cyclecounts = new TGraphErrors (counts_544 , cycleNumberArray544, UCNIntegralArray544, 0 , UCNIntegralErrArray544);
  gr544_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr544_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr544_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr544_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr544_cyclehist = new TGraphErrors(counts_544, cycleNumberArray544 , HistIntegralArray544, 0, HistIntegralErrArray544);

  gr544_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr544_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr544_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr544_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr544_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr544_cyclehist -> SetMarkerColor(2);
  gr544_cyclehist -> SetMarkerStyle(7);

  gr544_cyclecounts -> Draw("Ap");
  gr544_cyclehist -> Draw("p");

  leg2-> Draw();

  c544_cycleNum -> cd(2);
 TGraphErrors *gr544_cycledelay = new TGraphErrors (counts_544 , cycleNumberArray544, delaytimeArray544, 0 , 0);
  gr544_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr544_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr544_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr544_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cycledelay -> SetMarkerStyle(7);

  gr544_cycledelay -> Draw("Ap");


  c544_cycleNum -> cd(3);
  TGraphErrors *gr544_cycletempIrrad = new TGraphErrors (counts_544 , cycleNumberArray544, avets12IrradArray544, 0 , ts12IrradErr544);

  gr544_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr544_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr544_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr544_cycletempIrrad -> SetMarkerStyle(7);
  gr544_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr544_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr544_cycletempValveOpen = new TGraphErrors (counts_544 , cycleNumberArray544, avets12ValveOpenArray544, 0 , ts12ValveOpenErr544);

  gr544_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr544_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr544_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr544_cycletempValveOpen -> SetMarkerStyle(7);
  gr544_cycletempValveOpen -> SetMarkerColor(2);
  gr544_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr544_cycletempIrrad -> Draw("AP");
  gr544_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c544_cycleNum -> cd(4);
  TGraphErrors *gr544_cyclecur = new TGraphErrors (counts_544 , cycleNumberArray544 , avecurArray544, 0, ErrcurArray544 );
  gr544_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr544_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr544_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr544_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclecur -> SetMarkerStyle(7);
  gr544_cyclecur -> Draw("Ap");


  TCanvas *c544_cycleNumFit = new TCanvas("c544_cycleNumFit" , "c544_cycleNumFit" , 1200, 800);
  c544_cycleNumFit -> Divide(2,2);

  c544_cycleNumFit -> cd(1);
  TGraphErrors *gr544_cyclefall = new TGraphErrors (counts_544, cycleNumberArray544, FallTimeArray544 , 0, FallTimeErrArray544);

  gr544_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr544_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr544_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr544_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclefall -> SetMarkerStyle(7);
  gr544_cyclefall -> Draw("Ap");


  c544_cycleNumFit -> cd(2);
  TGraphErrors *gr544_cyclebaseline = new TGraphErrors (counts_544, cycleNumberArray544, BaselineArray544 , 0, BaselineErrArray544);

  gr544_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr544_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr544_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr544_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclebaseline -> SetMarkerStyle(7);
  gr544_cyclebaseline -> Draw("Ap");

  c544_cycleNumFit -> cd(3);
  TGraphErrors *gr544_cyclebaselineirrad = new TGraphErrors (counts_544, cycleNumberArray544, BaselineIrradArray544 , 0, BaselineIrradErrArray544);

  gr544_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr544_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr544_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr544_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclebaselineirrad -> SetMarkerStyle(7);
  gr544_cyclebaselineirrad -> Draw("Ap");

  c544_cycleNumFit -> cd(4);
  TGraphErrors *gr544_cyclerise = new TGraphErrors (counts_544, cycleNumberArray544, RiseTimeArray544 , 0, RiseTimeErrArray544);

  gr544_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr544_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr544_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr544_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr544_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr544_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr544_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr544_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr544_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr544_cyclerise -> SetMarkerStyle(7);
  gr544_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              545
  //*********************************
  //*********************************
  TCanvas *c545 = new TCanvas("c545" , "c545" , 1200, 800);
  c545 -> Divide(2,2);
  //c545 -> cd(1);
  TPad *p545_1 = c545->cd(1);
  p545_1->SetLogy(); 
  TGraphErrors *gr545_delaycounts = new TGraphErrors(counts_545, delaytimeArray545 , UCNIntegralArray545, 0, UCNIntegralErrArray545);

  gr545_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr545_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr545_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr545_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr545_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_delaycounts -> SetMarkerStyle(7);
  gr545_delaycounts -> Fit(fit);
  storage545 = fit -> GetParameter(1);
  storageErr545 = fit -> GetParError(1);
  
  TGraphErrors *gr545_delayhist = new TGraphErrors(counts_545, delaytimeArray545 , HistIntegralArray545, 0, HistIntegralErrArray545);

  gr545_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr545_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr545_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr545_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr545_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr545_delayhist -> SetMarkerColor(2);
  gr545_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr545_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr545_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr545_delaycounts -> Draw("Ap");
  gr545_delayhist -> Draw("p");
  leg2 -> Draw();

  //c545 -> cd(2);
  TPad *p545_2 = c545->cd(2);
  p545_2->SetLogy(); 
  TGraphErrors *gr545_tempIrradcounts = new TGraphErrors (counts_545 , avets12IrradArray545, UCNIntegralArray545 , ts12IrradErr545 , UCNIntegralErrArray545);
  gr545_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr545_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr545_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr545_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr545_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr545_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr545_tempValveOpencounts = new TGraphErrors (counts_545 , avets12ValveOpenArray545, UCNIntegralArray545 , ts12ValveOpenErr545 , UCNIntegralErrArray545);
  gr545_tempValveOpencounts -> SetMarkerStyle(7);
  gr545_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr545_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr545_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr545_tempIrradcounts -> Draw("Ap");
  gr545_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c545 -> cd(3);
  TGraphErrors *gr545_delaytempIrrad = new TGraphErrors (counts_545 , delaytimeArray545, avets12IrradArray545, 0 , ts12IrradErr545);

  gr545_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr545_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr545_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr545_delaytempIrrad -> SetMarkerStyle(7);
  gr545_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr545_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr545_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr545_delaytempValveOpen = new TGraphErrors (counts_545 , delaytimeArray545, avets12ValveOpenArray545, 0 , ts12ValveOpenErr545);

  gr545_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr545_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr545_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr545_delaytempValveOpen -> SetMarkerStyle(7);
  gr545_delaytempValveOpen -> SetMarkerColor(2);
  gr545_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr545_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr545_delaytempIrrad -> Draw("AP");
  gr545_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p545_3 = c545->cd(4);
  p545_3->SetLogy(); 
  TGraphErrors *gr545_curcounts = new TGraphErrors (counts_545 , avecurArray545, UCNIntegralArray545 , ErrcurArray545 , UCNIntegralErrArray545);
  gr545_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr545_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr545_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr545_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr545_curhist = new TGraphErrors (counts_545 , avecurArray545, UCNIntegralArray545 , ErrcurArray545 , UCNIntegralErrArray545);
  gr545_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr545_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr545_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr545_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr545_curhist -> SetMarkerColor(2);
  gr545_curhist -> SetMarkerStyle(7);

  gr545_curcounts -> Draw("Ap");
  gr545_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c545_cycleNum = new TCanvas("c545_cycleNum" , "c545_cycleNum" , 1200, 800);
  c545_cycleNum -> Divide(2,2);
  TPad *p545_4 = c545_cycleNum->cd(1);
  p545_4->SetLogy(); 
  TGraphErrors *gr545_cyclecounts = new TGraphErrors (counts_545 , cycleNumberArray545, UCNIntegralArray545, 0 , UCNIntegralErrArray545);
  gr545_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr545_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr545_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr545_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr545_cyclehist = new TGraphErrors(counts_545, cycleNumberArray545 , HistIntegralArray545, 0, HistIntegralErrArray545);

  gr545_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr545_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr545_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr545_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr545_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr545_cyclehist -> SetMarkerColor(2);
  gr545_cyclehist -> SetMarkerStyle(7);

  gr545_cyclecounts -> Draw("Ap");
  gr545_cyclehist -> Draw("p");

  leg2-> Draw();

  c545_cycleNum -> cd(2);
 TGraphErrors *gr545_cycledelay = new TGraphErrors (counts_545 , cycleNumberArray545, delaytimeArray545, 0 , 0);
  gr545_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr545_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr545_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr545_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cycledelay -> SetMarkerStyle(7);

  gr545_cycledelay -> Draw("Ap");


  c545_cycleNum -> cd(3);
  TGraphErrors *gr545_cycletempIrrad = new TGraphErrors (counts_545 , cycleNumberArray545, avets12IrradArray545, 0 , ts12IrradErr545);

  gr545_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr545_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr545_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr545_cycletempIrrad -> SetMarkerStyle(7);
  gr545_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr545_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr545_cycletempValveOpen = new TGraphErrors (counts_545 , cycleNumberArray545, avets12ValveOpenArray545, 0 , ts12ValveOpenErr545);

  gr545_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr545_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr545_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr545_cycletempValveOpen -> SetMarkerStyle(7);
  gr545_cycletempValveOpen -> SetMarkerColor(2);
  gr545_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr545_cycletempIrrad -> Draw("AP");
  gr545_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c545_cycleNum -> cd(4);
  TGraphErrors *gr545_cyclecur = new TGraphErrors (counts_545 , cycleNumberArray545 , avecurArray545, 0, ErrcurArray545 );
  gr545_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr545_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr545_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr545_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclecur -> SetMarkerStyle(7);
  gr545_cyclecur -> Draw("Ap");


  TCanvas *c545_cycleNumFit = new TCanvas("c545_cycleNumFit" , "c545_cycleNumFit" , 1200, 800);
  c545_cycleNumFit -> Divide(2,2);

  c545_cycleNumFit -> cd(1);
  TGraphErrors *gr545_cyclefall = new TGraphErrors (counts_545, cycleNumberArray545, FallTimeArray545 , 0, FallTimeErrArray545);

  gr545_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr545_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr545_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr545_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclefall -> SetMarkerStyle(7);
  gr545_cyclefall -> Draw("Ap");


  c545_cycleNumFit -> cd(2);
  TGraphErrors *gr545_cyclebaseline = new TGraphErrors (counts_545, cycleNumberArray545, BaselineArray545 , 0, BaselineErrArray545);

  gr545_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr545_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr545_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr545_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclebaseline -> SetMarkerStyle(7);
  gr545_cyclebaseline -> Draw("Ap");

  c545_cycleNumFit -> cd(3);
  TGraphErrors *gr545_cyclebaselineirrad = new TGraphErrors (counts_545, cycleNumberArray545, BaselineIrradArray545 , 0, BaselineIrradErrArray545);

  gr545_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr545_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr545_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr545_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclebaselineirrad -> SetMarkerStyle(7);
  gr545_cyclebaselineirrad -> Draw("Ap");

  c545_cycleNumFit -> cd(4);
  TGraphErrors *gr545_cyclerise = new TGraphErrors (counts_545, cycleNumberArray545, RiseTimeArray545 , 0, RiseTimeErrArray545);

  gr545_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr545_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr545_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr545_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr545_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr545_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr545_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr545_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr545_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr545_cyclerise -> SetMarkerStyle(7);
  gr545_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              546
  //*********************************
  //*********************************
  TCanvas *c546 = new TCanvas("c546" , "c546" , 1200, 800);
  c546 -> Divide(2,2);
  //c546 -> cd(1);
  TPad *p546_1 = c546->cd(1);
  p546_1->SetLogy(); 
  TGraphErrors *gr546_delaycounts = new TGraphErrors(counts_546, delaytimeArray546 , UCNIntegralArray546, 0, UCNIntegralErrArray546);

  gr546_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr546_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr546_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr546_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr546_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_delaycounts -> SetMarkerStyle(7);
  gr546_delaycounts -> Fit(fit);
  storage546 = fit -> GetParameter(1);
  storageErr546 = fit -> GetParError(1);
  
  TGraphErrors *gr546_delayhist = new TGraphErrors(counts_546, delaytimeArray546 , HistIntegralArray546, 0, HistIntegralErrArray546);

  gr546_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr546_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr546_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr546_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr546_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr546_delayhist -> SetMarkerColor(2);
  gr546_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr546_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr546_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr546_delaycounts -> Draw("Ap");
  gr546_delayhist -> Draw("p");
  leg2 -> Draw();

  //c546 -> cd(2);
  TPad *p546_2 = c546->cd(2);
  p546_2->SetLogy(); 
  TGraphErrors *gr546_tempIrradcounts = new TGraphErrors (counts_546 , avets12IrradArray546, UCNIntegralArray546 , ts12IrradErr546 , UCNIntegralErrArray546);
  gr546_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr546_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr546_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr546_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr546_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr546_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr546_tempValveOpencounts = new TGraphErrors (counts_546 , avets12ValveOpenArray546, UCNIntegralArray546 , ts12ValveOpenErr546 , UCNIntegralErrArray546);
  gr546_tempValveOpencounts -> SetMarkerStyle(7);
  gr546_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr546_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr546_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr546_tempIrradcounts -> Draw("Ap");
  gr546_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c546 -> cd(3);
  TGraphErrors *gr546_delaytempIrrad = new TGraphErrors (counts_546 , delaytimeArray546, avets12IrradArray546, 0 , ts12IrradErr546);

  gr546_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr546_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr546_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr546_delaytempIrrad -> SetMarkerStyle(7);
  gr546_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr546_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr546_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr546_delaytempValveOpen = new TGraphErrors (counts_546 , delaytimeArray546, avets12ValveOpenArray546, 0 , ts12ValveOpenErr546);

  gr546_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr546_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr546_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr546_delaytempValveOpen -> SetMarkerStyle(7);
  gr546_delaytempValveOpen -> SetMarkerColor(2);
  gr546_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr546_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr546_delaytempIrrad -> Draw("AP");
  gr546_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p546_3 = c546->cd(4);
  p546_3->SetLogy(); 
  TGraphErrors *gr546_curcounts = new TGraphErrors (counts_546 , avecurArray546, UCNIntegralArray546 , ErrcurArray546 , UCNIntegralErrArray546);
  gr546_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr546_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr546_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr546_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr546_curhist = new TGraphErrors (counts_546 , avecurArray546, UCNIntegralArray546 , ErrcurArray546 , UCNIntegralErrArray546);
  gr546_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr546_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr546_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr546_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr546_curhist -> SetMarkerColor(2);
  gr546_curhist -> SetMarkerStyle(7);

  gr546_curcounts -> Draw("Ap");
  gr546_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c546_cycleNum = new TCanvas("c546_cycleNum" , "c546_cycleNum" , 1200, 800);
  c546_cycleNum -> Divide(2,2);
  TPad *p546_4 = c546_cycleNum->cd(1);
  p546_4->SetLogy(); 
  TGraphErrors *gr546_cyclecounts = new TGraphErrors (counts_546 , cycleNumberArray546, UCNIntegralArray546, 0 , UCNIntegralErrArray546);
  gr546_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr546_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr546_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr546_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr546_cyclehist = new TGraphErrors(counts_546, cycleNumberArray546 , HistIntegralArray546, 0, HistIntegralErrArray546);

  gr546_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr546_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr546_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr546_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr546_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr546_cyclehist -> SetMarkerColor(2);
  gr546_cyclehist -> SetMarkerStyle(7);

  gr546_cyclecounts -> Draw("Ap");
  gr546_cyclehist -> Draw("p");

  leg2-> Draw();

  c546_cycleNum -> cd(2);
 TGraphErrors *gr546_cycledelay = new TGraphErrors (counts_546 , cycleNumberArray546, delaytimeArray546, 0 , 0);
  gr546_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr546_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr546_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr546_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cycledelay -> SetMarkerStyle(7);

  gr546_cycledelay -> Draw("Ap");


  c546_cycleNum -> cd(3);
  TGraphErrors *gr546_cycletempIrrad = new TGraphErrors (counts_546 , cycleNumberArray546, avets12IrradArray546, 0 , ts12IrradErr546);

  gr546_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr546_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr546_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr546_cycletempIrrad -> SetMarkerStyle(7);
  gr546_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr546_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr546_cycletempValveOpen = new TGraphErrors (counts_546 , cycleNumberArray546, avets12ValveOpenArray546, 0 , ts12ValveOpenErr546);

  gr546_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr546_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr546_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr546_cycletempValveOpen -> SetMarkerStyle(7);
  gr546_cycletempValveOpen -> SetMarkerColor(2);
  gr546_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr546_cycletempIrrad -> Draw("AP");
  gr546_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c546_cycleNum -> cd(4);
  TGraphErrors *gr546_cyclecur = new TGraphErrors (counts_546 , cycleNumberArray546 , avecurArray546, 0, ErrcurArray546 );
  gr546_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr546_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr546_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr546_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclecur -> SetMarkerStyle(7);
  gr546_cyclecur -> Draw("Ap");


  TCanvas *c546_cycleNumFit = new TCanvas("c546_cycleNumFit" , "c546_cycleNumFit" , 1200, 800);
  c546_cycleNumFit -> Divide(2,2);

  c546_cycleNumFit -> cd(1);
  TGraphErrors *gr546_cyclefall = new TGraphErrors (counts_546, cycleNumberArray546, FallTimeArray546 , 0, FallTimeErrArray546);

  gr546_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr546_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr546_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr546_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclefall -> SetMarkerStyle(7);
  gr546_cyclefall -> Draw("Ap");


  c546_cycleNumFit -> cd(2);
  TGraphErrors *gr546_cyclebaseline = new TGraphErrors (counts_546, cycleNumberArray546, BaselineArray546 , 0, BaselineErrArray546);

  gr546_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr546_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr546_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr546_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclebaseline -> SetMarkerStyle(7);
  gr546_cyclebaseline -> Draw("Ap");

  c546_cycleNumFit -> cd(3);
  TGraphErrors *gr546_cyclebaselineirrad = new TGraphErrors (counts_546, cycleNumberArray546, BaselineIrradArray546 , 0, BaselineIrradErrArray546);

  gr546_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr546_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr546_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr546_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclebaselineirrad -> SetMarkerStyle(7);
  gr546_cyclebaselineirrad -> Draw("Ap");

  c546_cycleNumFit -> cd(4);
  TGraphErrors *gr546_cyclerise = new TGraphErrors (counts_546, cycleNumberArray546, RiseTimeArray546 , 0, RiseTimeErrArray546);

  gr546_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr546_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr546_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr546_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr546_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr546_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr546_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr546_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr546_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr546_cyclerise -> SetMarkerStyle(7);
  gr546_cyclerise -> Draw("Ap");






  /*

  double StorageAll [100] = {storage541, storage542, storage544, storage545, storage546, storage540};
  double StorageErrAll[100] = {storageErr541, storageErr542, storageErr544, storageErr544, storageErr545, storageErr546, storageErr540};
  double runNum[100] = {541, 542, 544, 545, 546, 540};
  double tempIrradAll[100] = {aveAllts12Irrad541, aveAllts12Irrad542, aveAllts12Irrad544, aveAllts12Irrad545, aveAllts12Irrad546, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad541,  aveAllErrts12Irrad542,  aveAllErrts12Irrad543,  aveAllErrts12Irrad545,  aveAllErrts12Irrad546,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_541 +counts_542 +counts_543 +counts_544 +counts_545 +counts_546  , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_541 +counts_542 +counts_543 +counts_544 +counts_545 +counts_546  , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
  grAllHist -> SetMarkerStyle(7);
  grAllHist -> SetMarkerColor(2);

  
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
  grAllHist -> Draw("p");
  




}
