//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17006.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17006_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin595 = new TFile("outputTree_StorageTime_595.root","READ");
  TFile *fin596 = new TFile("outputTree_StorageTime_596.root","READ");
  TFile *fin597 = new TFile("outputTree_StorageTime_597.root","READ");
  TFile *fin598 = new TFile("outputTree_StorageTime_598.root","READ");
  TFile *fin599 = new TFile("outputTree_StorageTime_599.root","READ");
  TFile *fin600 = new TFile("outputTree_StorageTime_600.root","READ");
  TFile *fin601 = new TFile("outputTree_StorageTime_601.root","READ");
  TFile *fin602 = new TFile("outputTree_StorageTime_602.root","READ");


  
  TTree *outputTree595 = (TTree*) fin595 -> Get("cycle_info");
  TTree *outputTree596 = (TTree*) fin596 -> Get("cycle_info");
  TTree *outputTree597 = (TTree*) fin597 -> Get("cycle_info");
  TTree *outputTree598 = (TTree*) fin598 -> Get("cycle_info");
  TTree *outputTree599 = (TTree*) fin599 -> Get("cycle_info");
  TTree *outputTree600 = (TTree*) fin600 -> Get("cycle_info");
  TTree *outputTree601 = (TTree*) fin601 -> Get("cycle_info");
  TTree *outputTree602 = (TTree*) fin602 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime595;
  double cycleDelayTime596;
  double cycleDelayTime597;
  double cycleDelayTime598;
  double cycleDelayTime599;
  double cycleDelayTime600;
  double cycleDelayTime601;
  double cycleDelayTime602;



  outputTree595 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime595);
  outputTree596 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime596);
  outputTree597 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime597);
  outputTree598 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime598);
  outputTree599 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime599);
  outputTree600 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime600);
  outputTree601 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime601);
  outputTree602 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime602);



  // DELAY TIME (ARRAY)
  double delaytimeArray595 [100];
  double delaytimeArray596 [100];
  double delaytimeArray597 [100];
  double delaytimeArray598 [100];
  double delaytimeArray599 [100];
  double delaytimeArray600 [100];
  double delaytimeArray601 [100];
  double delaytimeArray602 [100];


  // CYCLE NUMBER
  int cycleNumber595;
  int cycleNumber596;
  int cycleNumber597;
  int cycleNumber598;
  int cycleNumber599;
  int cycleNumber600;
  int cycleNumber601;
  int cycleNumber602;


  outputTree595 -> SetBranchAddress ("cycleNumber" , &cycleNumber595);
  outputTree596 -> SetBranchAddress ("cycleNumber" , &cycleNumber596);
  outputTree597 -> SetBranchAddress ("cycleNumber" , &cycleNumber597);
  outputTree598 -> SetBranchAddress ("cycleNumber" , &cycleNumber598);
  outputTree599 -> SetBranchAddress ("cycleNumber" , &cycleNumber599);
  outputTree600 -> SetBranchAddress ("cycleNumber" , &cycleNumber600);
  outputTree601 -> SetBranchAddress ("cycleNumber" , &cycleNumber601);
  outputTree602 -> SetBranchAddress ("cycleNumber" , &cycleNumber602);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray595 [100];
  double cycleNumberArray596 [100];
  double cycleNumberArray597 [100];
  double cycleNumberArray598 [100];
  double cycleNumberArray599 [100];
  double cycleNumberArray600 [100];
  double cycleNumberArray601 [100];
  double cycleNumberArray602 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral595;
  double UCNIntegral596;
  double UCNIntegral597;
  double UCNIntegral598;
  double UCNIntegral599;
  double UCNIntegral600;
  double UCNIntegral601;
  double UCNIntegral602;



  outputTree595 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral595);
  outputTree596 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral596);
  outputTree597 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral597);
  outputTree598 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral598);
  outputTree599 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral599);
  outputTree600 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral600);
  outputTree601 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral601);
  outputTree602 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral602);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray595 [100];
  double UCNIntegralArray596 [100];
  double UCNIntegralArray597 [100];
  double UCNIntegralArray598 [100];
  double UCNIntegralArray599 [100];
  double UCNIntegralArray600 [100];
  double UCNIntegralArray601 [100];
  double UCNIntegralArray602 [100];


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr595;
  double UCNIntegralErr596;
  double UCNIntegralErr597;
  double UCNIntegralErr598;
  double UCNIntegralErr599;
  double UCNIntegralErr600;
  double UCNIntegralErr601;
  double UCNIntegralErr602;


  outputTree595 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr595);
  outputTree596 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr596);
  outputTree597 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr597);
  outputTree598 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr598);
  outputTree599 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr599);
  outputTree600 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr600);
  outputTree601 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr601);
  outputTree602 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr602);


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray595 [100];
  double UCNIntegralErrArray596 [100];
  double UCNIntegralErrArray597 [100];
  double UCNIntegralErrArray598 [100];
  double UCNIntegralErrArray599 [100];
  double UCNIntegralErrArray600 [100];
  double UCNIntegralErrArray601 [100];
  double UCNIntegralErrArray602 [100];


  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral595;
  double HistIntegral596;
  double HistIntegral597;
  double HistIntegral598;
  double HistIntegral599;
  double HistIntegral600;
  double HistIntegral601;
  double HistIntegral602;


  outputTree595 -> SetBranchAddress ("HistIntegral" , &HistIntegral595); 
  outputTree596 -> SetBranchAddress ("HistIntegral" , &HistIntegral596);
  outputTree597 -> SetBranchAddress ("HistIntegral" , &HistIntegral597);
  outputTree598 -> SetBranchAddress ("HistIntegral" , &HistIntegral598);
  outputTree599 -> SetBranchAddress ("HistIntegral" , &HistIntegral599);
  outputTree600 -> SetBranchAddress ("HistIntegral" , &HistIntegral600);
  outputTree601 -> SetBranchAddress ("HistIntegral" , &HistIntegral601);
  outputTree602 -> SetBranchAddress ("HistIntegral" , &HistIntegral602);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray595 [100];
  double HistIntegralArray596 [100];
  double HistIntegralArray597 [100];
  double HistIntegralArray598 [100];
  double HistIntegralArray599 [100];
  double HistIntegralArray600 [100];
  double HistIntegralArray601 [100];
  double HistIntegralArray602 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr595;
  double HistIntegralErr596;
  double HistIntegralErr597;
  double HistIntegralErr598;
  double HistIntegralErr599;
  double HistIntegralErr600;
  double HistIntegralErr601;
  double HistIntegralErr602;


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray595 [100];
  double HistIntegralErrArray596 [100];
  double HistIntegralErrArray597 [100];
  double HistIntegralErrArray598 [100];
  double HistIntegralErrArray599 [100];
  double HistIntegralErrArray600 [100];
  double HistIntegralErrArray601 [100];
  double HistIntegralErrArray602 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad595;
  double avets12Irrad596;
  double avets12Irrad597;
  double avets12Irrad598;
  double avets12Irrad599;
  double avets12Irrad600;
  double avets12Irrad601;
  double avets12Irrad602;

  outputTree595 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad595);
  outputTree596 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad596);
  outputTree597 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad597);
  outputTree598 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad598);
  outputTree599 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad599);
  outputTree600 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad600);
  outputTree601 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad601);
  outputTree602 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad602);



  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen595;
  double avets12ValveOpen596;
  double avets12ValveOpen597;
  double avets12ValveOpen598;
  double avets12ValveOpen599;
  double avets12ValveOpen600;
  double avets12ValveOpen601;
  double avets12ValveOpen602;


  outputTree595 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen595);
  outputTree596 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen596);
  outputTree597 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen597);
  outputTree598 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen598);
  outputTree599 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen599);
  outputTree600 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen600);
  outputTree601 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen601);
  outputTree602 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen602);


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray595 [100];
  double avets12IrradArray596 [100];
  double avets12IrradArray597 [100];
  double avets12IrradArray598 [100];
  double avets12IrradArray599 [100];
  double avets12IrradArray600 [100];
  double avets12IrradArray601 [100];
  double avets12IrradArray602 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray595 [100];
  double avets12ValveOpenArray596 [100];
  double avets12ValveOpenArray597 [100];
  double avets12ValveOpenArray598 [100];
  double avets12ValveOpenArray599 [100];
  double avets12ValveOpenArray600 [100];
  double avets12ValveOpenArray601 [100];
  double avets12ValveOpenArray602 [100];


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad595;
  double maxts12Irrad596;
  double maxts12Irrad597;
  double maxts12Irrad598;
  double maxts12Irrad599;
  double maxts12Irrad600;
  double maxts12Irrad601;
  double maxts12Irrad602;

  outputTree595 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad595);
  outputTree596 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad596);
  outputTree597 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad597);
  outputTree598 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad598);
  outputTree599 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad599);
  outputTree600 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad600);
  outputTree601 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad601);
  outputTree602 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad602);


 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen595;
  double maxts12ValveOpen596;
  double maxts12ValveOpen597;
  double maxts12ValveOpen598;
  double maxts12ValveOpen599;
  double maxts12ValveOpen600;
  double maxts12ValveOpen601;
  double maxts12ValveOpen602;


  outputTree595 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen595);
  outputTree596 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen596);
  outputTree597 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen597);
  outputTree598 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen598);
  outputTree599 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen599);
  outputTree600 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen600);
  outputTree601 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen601);
  outputTree602 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen602);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray595 [100];
  double maxts12IrradArray596 [100];
  double maxts12IrradArray597 [100];
  double maxts12IrradArray598 [100];
  double maxts12IrradArray599 [100];
  double maxts12IrradArray600 [100];
  double maxts12IrradArray601 [100];
  double maxts12IrradArray602 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray595 [100];
  double maxts12ValveOpenArray596 [100];
  double maxts12ValveOpenArray597 [100];
  double maxts12ValveOpenArray598 [100];
  double maxts12ValveOpenArray599 [100];
  double maxts12ValveOpenArray600 [100];
  double maxts12ValveOpenArray601 [100];
  double maxts12ValveOpenArray602 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad595;
  double mints12Irrad596;
  double mints12Irrad597;
  double mints12Irrad598;
  double mints12Irrad599;
  double mints12Irrad600;
  double mints12Irrad601;
  double mints12Irrad602;


  outputTree595 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad595);
  outputTree596 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad596);
  outputTree597 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad597);
  outputTree598 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad598);
  outputTree599 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad599);
  outputTree600 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad600);
  outputTree601 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad601);
  outputTree602 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad602);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen595;
  double mints12ValveOpen596;
  double mints12ValveOpen597;
  double mints12ValveOpen598;
  double mints12ValveOpen599;
  double mints12ValveOpen600;
  double mints12ValveOpen601;
  double mints12ValveOpen602;
  
  outputTree595 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen595);
  outputTree596 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen596);
  outputTree597 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen597);
  outputTree598 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen598);
  outputTree599 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen599);
  outputTree600 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen600);
  outputTree601 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen601);
  outputTree602 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen602);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray595 [100];
  double mints12IrradArray596 [100];
  double mints12IrradArray597 [100];
  double mints12IrradArray598 [100];
  double mints12IrradArray599 [100];
  double mints12IrradArray600 [100];
  double mints12IrradArray601 [100];
  double mints12IrradArray602 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray595 [100];
  double mints12ValveOpenArray596 [100];
  double mints12ValveOpenArray597 [100];
  double mints12ValveOpenArray598 [100];
  double mints12ValveOpenArray599 [100];
  double mints12ValveOpenArray600 [100];
  double mints12ValveOpenArray601 [100];
  double mints12ValveOpenArray602 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr595 [100];
  double ts12IrradErr596 [100];
  double ts12IrradErr597 [100];
  double ts12IrradErr598 [100];
  double ts12IrradErr599 [100];
  double ts12IrradErr600 [100];
  double ts12IrradErr601 [100];
  double ts12IrradErr602 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr595 [100];
  double ts12ValveOpenErr596 [100];
  double ts12ValveOpenErr597 [100];
  double ts12ValveOpenErr598 [100];
  double ts12ValveOpenErr599 [100];
  double ts12ValveOpenErr600 [100];
  double ts12ValveOpenErr601 [100];
  double ts12ValveOpenErr602 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur595;
  double avecur596;
  double avecur597;
  double avecur598;
  double avecur599;
  double avecur600;
  double avecur601;
  double avecur602;

  outputTree595 -> SetBranchAddress ("AVE_PRDCUR" , &avecur595);
  outputTree596 -> SetBranchAddress ("AVE_PRDCUR" , &avecur596);
  outputTree597 -> SetBranchAddress ("AVE_PRDCUR" , &avecur597);
  outputTree598 -> SetBranchAddress ("AVE_PRDCUR" , &avecur598);
  outputTree599 -> SetBranchAddress ("AVE_PRDCUR" , &avecur599);
  outputTree600 -> SetBranchAddress ("AVE_PRDCUR" , &avecur600);
  outputTree601 -> SetBranchAddress ("AVE_PRDCUR" , &avecur601);
  outputTree602 -> SetBranchAddress ("AVE_PRDCUR" , &avecur602);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray595 [100];
  double avecurArray596 [100];
  double avecurArray597 [100];
  double avecurArray598 [100];
  double avecurArray599 [100];
  double avecurArray600 [100];
  double avecurArray601 [100];
  double avecurArray602 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur595;
  double maxcur596;
  double maxcur597;
  double maxcur598;
  double maxcur599;
  double maxcur600;
  double maxcur601;
  double maxcur602;

  outputTree595 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur595);
  outputTree596 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur596);
  outputTree597 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur597);
  outputTree598 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur598);
  outputTree599 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur599);
  outputTree600 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur600);
  outputTree601 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur601);
  outputTree602 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur602);

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray595 [100];
  double maxcurArray596 [100];
  double maxcurArray597 [100];
  double maxcurArray598 [100];
  double maxcurArray599 [100];
  double maxcurArray600 [100];
  double maxcurArray601 [100];
  double maxcurArray602 [100];

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur595;
  double mincur596;
  double mincur597;
  double mincur598;
  double mincur599;
  double mincur600;
  double mincur601;
  double mincur602;

  outputTree595 -> SetBranchAddress ("MIN_PRDCUR" , &mincur595);
  outputTree596 -> SetBranchAddress ("MIN_PRDCUR" , &mincur596);
  outputTree597 -> SetBranchAddress ("MIN_PRDCUR" , &mincur597);
  outputTree598 -> SetBranchAddress ("MIN_PRDCUR" , &mincur598);
  outputTree599 -> SetBranchAddress ("MIN_PRDCUR" , &mincur599);
  outputTree600 -> SetBranchAddress ("MIN_PRDCUR" , &mincur600);
  outputTree601 -> SetBranchAddress ("MIN_PRDCUR" , &mincur601);
  outputTree602 -> SetBranchAddress ("MIN_PRDCUR" , &mincur602);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray595 [100];
  double mincurArray596 [100];
  double mincurArray597 [100];
  double mincurArray598 [100];
  double mincurArray599 [100];
  double mincurArray600 [100];
  double mincurArray601 [100];
  double mincurArray602 [100];

  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray595 [100];
  double ErrcurArray596 [100];
  double ErrcurArray597 [100];
  double ErrcurArray598 [100];
  double ErrcurArray599 [100];
  double ErrcurArray600 [100];
  double ErrcurArray601 [100];
  double ErrcurArray602 [100];

  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline595;
  double Baseline596;
  double Baseline597;
  double Baseline598;
  double Baseline599;
  double Baseline600;
  double Baseline601;
  double Baseline602;

  outputTree595 -> SetBranchAddress ("Baseline" , &Baseline595);
  outputTree596 -> SetBranchAddress ("Baseline" , &Baseline596);
  outputTree597 -> SetBranchAddress ("Baseline" , &Baseline597);
  outputTree598 -> SetBranchAddress ("Baseline" , &Baseline598);
  outputTree599 -> SetBranchAddress ("Baseline" , &Baseline599);
  outputTree600 -> SetBranchAddress ("Baseline" , &Baseline600);
  outputTree601 -> SetBranchAddress ("Baseline" , &Baseline601);
  outputTree602 -> SetBranchAddress ("Baseline" , &Baseline602);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray595 [100];
  double BaselineArray596 [100];
  double BaselineArray597 [100];
  double BaselineArray598 [100];
  double BaselineArray599 [100];
  double BaselineArray600 [100];
  double BaselineArray601 [100];
  double BaselineArray602 [100];

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr595;
  double BaselineErr596;
  double BaselineErr597;
  double BaselineErr598;
  double BaselineErr599;
  double BaselineErr600;
  double BaselineErr601;
  double BaselineErr602;
 
  outputTree595 -> SetBranchAddress ("BaselineErr" , &BaselineErr595);
  outputTree596 -> SetBranchAddress ("BaselineErr" , &BaselineErr596);
  outputTree597 -> SetBranchAddress ("BaselineErr" , &BaselineErr597);
  outputTree598 -> SetBranchAddress ("BaselineErr" , &BaselineErr598);
  outputTree599 -> SetBranchAddress ("BaselineErr" , &BaselineErr599);
  outputTree600 -> SetBranchAddress ("BaselineErr" , &BaselineErr600);
  outputTree601 -> SetBranchAddress ("BaselineErr" , &BaselineErr601);
  outputTree602 -> SetBranchAddress ("BaselineErr" , &BaselineErr602);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray595 [100];
  double BaselineErrArray596 [100];
  double BaselineErrArray597 [100];
  double BaselineErrArray598 [100];
  double BaselineErrArray599 [100];
  double BaselineErrArray600 [100];
  double BaselineErrArray601 [100];
  double BaselineErrArray602 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad595;
  double BaselineIrrad596;
  double BaselineIrrad597;
  double BaselineIrrad598;
  double BaselineIrrad599;
  double BaselineIrrad600;
  double BaselineIrrad601;
  double BaselineIrrad602;
 
  outputTree595 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad595);
  outputTree596 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad596);
  outputTree597 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad597);
  outputTree598 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad598);
  outputTree599 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad599);
  outputTree600 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad600);
  outputTree601 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad601);
  outputTree602 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad602);

  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray595 [100];
  double BaselineIrradArray596 [100];
  double BaselineIrradArray597 [100];
  double BaselineIrradArray598 [100];
  double BaselineIrradArray599 [100];
  double BaselineIrradArray600 [100];
  double BaselineIrradArray601 [100];
  double BaselineIrradArray602 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr595;
  double BaselineIrradErr596;
  double BaselineIrradErr597;
  double BaselineIrradErr598;
  double BaselineIrradErr599;
  double BaselineIrradErr600;
  double BaselineIrradErr601;
  double BaselineIrradErr602;

  outputTree595 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr595);
  outputTree596 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr596);
  outputTree597 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr597);
  outputTree598 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr598);
  outputTree599 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr599);
  outputTree600 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr600);
  outputTree601 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr601);
  outputTree602 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr602);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray595 [100];
  double BaselineIrradErrArray596 [100];
  double BaselineIrradErrArray597 [100];
  double BaselineIrradErrArray598 [100];
  double BaselineIrradErrArray599 [100];
  double BaselineIrradErrArray600 [100];
  double BaselineIrradErrArray601 [100];
  double BaselineIrradErrArray602 [100];

  // FALL TIME FROM THE UCN RATE FIT
  double FallTime595;
  double FallTime596;
  double FallTime597;
  double FallTime598;
  double FallTime599;
  double FallTime600;
  double FallTime601;
  double FallTime602;

  outputTree595 -> SetBranchAddress ("FallTime" , &FallTime595);
  outputTree596 -> SetBranchAddress ("FallTime" , &FallTime596);
  outputTree597 -> SetBranchAddress ("FallTime" , &FallTime597);
  outputTree598 -> SetBranchAddress ("FallTime" , &FallTime598);
  outputTree599 -> SetBranchAddress ("FallTime" , &FallTime599);
  outputTree600 -> SetBranchAddress ("FallTime" , &FallTime600);
  outputTree601 -> SetBranchAddress ("FallTime" , &FallTime601);
  outputTree602 -> SetBranchAddress ("FallTime" , &FallTime602);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray595 [100];
  double FallTimeArray596 [100];
  double FallTimeArray597 [100];
  double FallTimeArray598 [100];
  double FallTimeArray599 [100];
  double FallTimeArray600 [100];
  double FallTimeArray601 [100];
  double FallTimeArray602 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr595;
  double FallTimeErr596;
  double FallTimeErr597;
  double FallTimeErr598;
  double FallTimeErr599;
  double FallTimeErr600;
  double FallTimeErr601;
  double FallTimeErr602;

  outputTree595 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr595);
  outputTree596 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr596);
  outputTree597 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr597);
  outputTree598 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr598);
  outputTree599 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr599);
  outputTree600 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr600);
  outputTree601 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr601);
  outputTree602 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr602);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray595 [100];
  double FallTimeErrArray596 [100];
  double FallTimeErrArray597 [100];
  double FallTimeErrArray598 [100];
  double FallTimeErrArray599 [100];
  double FallTimeErrArray600 [100];
  double FallTimeErrArray601 [100];
  double FallTimeErrArray602 [100];
  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime595;
  double RiseTime596;
  double RiseTime597;
  double RiseTime598;
  double RiseTime599;
  double RiseTime600;
  double RiseTime601;
  double RiseTime602;

  outputTree595 -> SetBranchAddress ("RiseTime" , &RiseTime595);
  outputTree596 -> SetBranchAddress ("RiseTime" , &RiseTime596);
  outputTree597 -> SetBranchAddress ("RiseTime" , &RiseTime597);
  outputTree598 -> SetBranchAddress ("RiseTime" , &RiseTime598);
  outputTree599 -> SetBranchAddress ("RiseTime" , &RiseTime599);
  outputTree600 -> SetBranchAddress ("RiseTime" , &RiseTime600);
  outputTree601 -> SetBranchAddress ("RiseTime" , &RiseTime601);
  outputTree602 -> SetBranchAddress ("RiseTime" , &RiseTime602);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray595 [100];
  double RiseTimeArray596 [100];
  double RiseTimeArray597 [100];
  double RiseTimeArray598 [100];
  double RiseTimeArray599 [100];
  double RiseTimeArray600 [100];
  double RiseTimeArray601 [100];
  double RiseTimeArray602 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr595;
  double RiseTimeErr596;
  double RiseTimeErr597;
  double RiseTimeErr598;
  double RiseTimeErr599;
  double RiseTimeErr600;
  double RiseTimeErr601;
  double RiseTimeErr602;

  outputTree595 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr595);
  outputTree596 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr596);
  outputTree597 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr597);
  outputTree598 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr598);
  outputTree599 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr599);
  outputTree600 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr600);
  outputTree601 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr601);
  outputTree602 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr602);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray595 [100];
  double RiseTimeErrArray596 [100];
  double RiseTimeErrArray597 [100];
  double RiseTimeErrArray598 [100];
  double RiseTimeErrArray599 [100];
  double RiseTimeErrArray600 [100];
  double RiseTimeErrArray601 [100];
  double RiseTimeErrArray602 [100];


  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad595;
  double aveAllts12Irrad596;
  double aveAllts12Irrad597;
  double aveAllts12Irrad598;
  double aveAllts12Irrad599;
  double aveAllts12Irrad600;
  double aveAllts12Irrad601;
  double aveAllts12Irrad602;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad595;
  double aveAllErrts12Irrad596;
  double aveAllErrts12Irrad597;
  double aveAllErrts12Irrad598;
  double aveAllErrts12Irrad599;
  double aveAllErrts12Irrad600;
  double aveAllErrts12Irrad601;
  double aveAllErrts12Irrad602;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad595;
  double maxAllts12Irrad596;
  double maxAllts12Irrad597;
  double maxAllts12Irrad598;
  double maxAllts12Irrad599;
  double maxAllts12Irrad600;
  double maxAllts12Irrad601;
  double maxAllts12Irrad602;
  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad595;
  double minAllts12Irrad596;
  double minAllts12Irrad597;
  double minAllts12Irrad598;
  double minAllts12Irrad599;
  double minAllts12Irrad600;
  double minAllts12Irrad601;
  double minAllts12Irrad602;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage595;
  double storage596;
  double storage597;
  double storage598;
  double storage599;
  double storage600;
  double storage601;
  double storage602;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr595;
  double storageErr596;
  double storageErr597;
  double storageErr598;
  double storageErr599;
  double storageErr600;
  double storageErr601;
  double storageErr602;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_595 = 0;
  int counts_596 = 0;
  int counts_597 = 0;
  int counts_598 = 0;
  int counts_599 = 0;
  int counts_600 = 0;
  int counts_601 = 0;
  int counts_602 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events595;
  events595 = (Double_t)outputTree595 -> GetEntries();

  for (ULong64_t j = 0 ; j < events595 ; j++){
    outputTree595 -> GetEvent(j);
    UCNIntegralArray595[counts_595] = UCNIntegral595;
    UCNIntegralErrArray595[counts_595] = UCNIntegralErr595;
    HistIntegralArray595[counts_595] = HistIntegral595;
    HistIntegralErrArray595[counts_595] = sqrt (HistIntegral595);
    avets12IrradArray595[counts_595] = avets12Irrad595;
    avets12ValveOpenArray595[counts_595] = avets12ValveOpen595;
    maxts12IrradArray595[counts_595] = maxts12Irrad595;
    maxts12ValveOpenArray595[counts_595] = maxts12ValveOpen595;
    mints12IrradArray595[counts_595] = mints12Irrad595; 
    mints12ValveOpenArray595[counts_595] = mints12ValveOpen595;
    ts12IrradErr595[counts_595] = maxts12Irrad595 - mints12Irrad595;
    ts12ValveOpenErr595[counts_595] = maxts12ValveOpen595 - mints12ValveOpen595;
    avecurArray595[counts_595] = avecur595;
    maxcurArray595[counts_595] = maxcur595;
    mincurArray595[counts_595] = mincur595;
    ErrcurArray595[counts_595] = maxcur595 - mincur595;
    delaytimeArray595[counts_595] = cycleDelayTime595;
    cycleNumberArray595[counts_595] = cycleNumber595;
    BaselineArray595[counts_595] = Baseline595;
    BaselineIrradArray595[counts_595] = BaselineIrrad595;
    BaselineIrradErrArray595[counts_595] = BaselineIrradErr595;
    FallTimeArray595[counts_595] = FallTime595;
    FallTimeErrArray595[counts_595] = FallTimeErr595;
    RiseTimeArray595[counts_595] = RiseTime595;
    RiseTimeErrArray595[counts_595] = RiseTimeErr595;
    aveAllts12Irrad595 += avets12Irrad595;
    maxAllts12Irrad595 += maxts12Irrad595;
    minAllts12Irrad595 += mints12Irrad595;
    UCNIntegralArrayAll[counts_595] = UCNIntegral595;
    UCNIntegralErrArrayAll[counts_595] = UCNIntegralErr595;
    delayTimeAll[counts_595] = cycleDelayTime595;
    HistIntegralArrayAll[counts_595] = HistIntegral595;
    HistIntegralErrArrayAll[counts_595] = sqrt (HistIntegral595);
    counts_595++;
  }
  aveAllts12Irrad595 = aveAllts12Irrad595/counts_595;
  maxAllts12Irrad595 = maxAllts12Irrad595/counts_595;
  minAllts12Irrad595 = minAllts12Irrad595/counts_595;
  aveAllErrts12Irrad595 = maxAllts12Irrad595 - minAllts12Irrad595;

  ULong64_t events596;
  events596 = (Double_t)outputTree596 -> GetEntries();

  for (ULong64_t j = 0 ; j < events596 ; j++){
    outputTree596 -> GetEvent(j);
    if (j ==1 || j==2 || j==3)
      continue;
    UCNIntegralArray596[j] = UCNIntegral596;
    UCNIntegralErrArray596[j] = UCNIntegralErr596;
    HistIntegralArray596[j] = HistIntegral596;
    HistIntegralErrArray596[j] = sqrt (HistIntegral596);
    avets12IrradArray596[j] = avets12Irrad596;
    avets12ValveOpenArray596[j] = avets12ValveOpen596;
    maxts12IrradArray596[j] = maxts12Irrad596;
    maxts12ValveOpenArray596[j] = maxts12ValveOpen596;
    mints12IrradArray596[j] = mints12Irrad596; 
    mints12ValveOpenArray596[j] = mints12ValveOpen596;
    ts12IrradErr596[j] = maxts12Irrad596 - mints12Irrad596;
    ts12ValveOpenErr596[j] = maxts12ValveOpen596 - mints12ValveOpen596;
    avecurArray596[j] = avecur596;
    maxcurArray596[j] = maxcur596;
    mincurArray596[j] = mincur596;
    ErrcurArray596[j] = maxcur596 - mincur596;
    delaytimeArray596[j] = cycleDelayTime596;
    cycleNumberArray596[j] = cycleNumber596;
    BaselineArray596[j] = Baseline596;
    BaselineIrradArray596[j] = BaselineIrrad596;
    BaselineIrradErrArray596[j] = BaselineIrradErr596;
    FallTimeArray596[j] = FallTime596;
    FallTimeErrArray596[j] = FallTimeErr596;
    RiseTimeArray596[j] = RiseTime596;
    RiseTimeErrArray596[j] = RiseTimeErr596;
    aveAllts12Irrad596 += avets12Irrad596;
    maxAllts12Irrad596 += maxts12Irrad596;
    minAllts12Irrad596 += mints12Irrad596;
    cout << aveAllts12Irrad596 << endl;
    UCNIntegralArrayAll[counts_595+ counts_596] = UCNIntegral596;
    UCNIntegralErrArrayAll[counts_595+ counts_596] = UCNIntegralErr596;
    delayTimeAll[counts_595+ counts_596] = cycleDelayTime596;
    HistIntegralArrayAll[counts_595 + counts_596] = HistIntegral596;
    HistIntegralErrArrayAll[counts_595+counts_596] = sqrt (HistIntegral596);
    counts_596++;
  }
  aveAllts12Irrad596 = aveAllts12Irrad596/counts_596;
  maxAllts12Irrad596 = maxAllts12Irrad596/counts_596;
  minAllts12Irrad596 = minAllts12Irrad596/counts_596;
  aveAllErrts12Irrad596 = maxAllts12Irrad596 - minAllts12Irrad596;

  ULong64_t events597;
  events597 = (Double_t)outputTree597 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events597 ; j++){
    outputTree597 -> GetEvent(j);
    if (j==0 || j==1)
      continue;
    UCNIntegralArray597[counts_597] = UCNIntegral597;
    UCNIntegralErrArray597[counts_597] = UCNIntegralErr597;
    HistIntegralArray597[counts_597] = HistIntegral597;
    HistIntegralErrArray597[counts_597] = sqrt (HistIntegral597);
    avets12IrradArray597[counts_597] = avets12Irrad597;
    avets12ValveOpenArray597[counts_597] = avets12ValveOpen597;
    maxts12IrradArray597[counts_597] = maxts12Irrad597;
    maxts12ValveOpenArray597[counts_597] = maxts12ValveOpen597;
    mints12IrradArray597[counts_597] = mints12Irrad597; 
    mints12ValveOpenArray597[counts_597] = mints12ValveOpen597;
    ts12IrradErr597[counts_597] = maxts12Irrad597 - mints12Irrad597;
    ts12ValveOpenErr597[counts_597] = maxts12ValveOpen597 - mints12ValveOpen597;
    avecurArray597[counts_597] = avecur597;
    maxcurArray597[counts_597] = maxcur597;
    mincurArray597[counts_597] = mincur597;
    ErrcurArray597[counts_597] = maxcur597 - mincur597;
    delaytimeArray597[counts_597] = cycleDelayTime597;
    cycleNumberArray597[counts_597] = cycleNumber597;
    BaselineArray597[counts_597] = Baseline597;
    BaselineIrradArray597[counts_597] = BaselineIrrad597;
    BaselineIrradErrArray597[counts_597] = BaselineIrradErr597;
    FallTimeArray597[counts_597] = FallTime597;
    FallTimeErrArray597[counts_597] = FallTimeErr597;
    RiseTimeArray597[counts_597] = RiseTime597;
    RiseTimeErrArray597[counts_597] = RiseTimeErr597;
    aveAllts12Irrad597 += avets12Irrad597;
    maxAllts12Irrad597 += maxts12Irrad597;
    minAllts12Irrad597 += mints12Irrad597;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597] = UCNIntegral597;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597] = UCNIntegralErr597;
    delayTimeAll[counts_595+ counts_596+counts_597] = cycleDelayTime597;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597] = HistIntegral597;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597] = sqrt (HistIntegral597);
    counts_597++;
  }
  aveAllts12Irrad597 = aveAllts12Irrad597/counts_597;
  maxAllts12Irrad597 = maxAllts12Irrad597/counts_597;
  minAllts12Irrad597 = minAllts12Irrad597/counts_597;
  aveAllErrts12Irrad597 = maxAllts12Irrad597 - minAllts12Irrad597;
  
  ULong64_t events598;
  events598 = (Double_t)outputTree598 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events598 ; j++){
    outputTree598 -> GetEvent(j);
    UCNIntegralArray598[j] = UCNIntegral598;
    UCNIntegralErrArray598[j] = UCNIntegralErr598;
    HistIntegralArray598[j] = HistIntegral598;
    HistIntegralErrArray598[j] = sqrt (HistIntegral598);
    avets12IrradArray598[j] = avets12Irrad598;
    avets12ValveOpenArray598[j] = avets12ValveOpen598;
    maxts12IrradArray598[j] = maxts12Irrad598;
    maxts12ValveOpenArray598[j] = maxts12ValveOpen598;
    mints12IrradArray598[j] = mints12Irrad598; 
    mints12ValveOpenArray598[j] = mints12ValveOpen598;
    ts12IrradErr598[j] = maxts12Irrad598 - mints12Irrad598;
    ts12ValveOpenErr598[j] = maxts12ValveOpen598 - mints12ValveOpen598;
    avecurArray598[j] = avecur598;
    maxcurArray598[j] = maxcur598;
    mincurArray598[j] = mincur598;
    ErrcurArray598[j] = maxcur598 - mincur598;
    delaytimeArray598[j] = cycleDelayTime598;
    cycleNumberArray598[j] = cycleNumber598;
    BaselineArray598[j] = Baseline598;
    BaselineIrradArray598[j] = BaselineIrrad598;
    BaselineIrradErrArray598[j] = BaselineIrradErr598;
    FallTimeArray598[j] = FallTime598;
    FallTimeErrArray598[j] = FallTimeErr598;
    RiseTimeArray598[j] = RiseTime598;
    RiseTimeErrArray598[j] = RiseTimeErr598;
    aveAllts12Irrad598 += avets12Irrad598;
    maxAllts12Irrad598 += maxts12Irrad598;
    minAllts12Irrad598 += mints12Irrad598;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597+counts_598] = UCNIntegral598;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597+counts_598] = UCNIntegralErr598;
    delayTimeAll[counts_595+ counts_596+counts_597+counts_598] = cycleDelayTime598;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597+ counts_598] = HistIntegral598;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597+counts_598] = sqrt (HistIntegral598);
    counts_598++;
  }
  aveAllts12Irrad598 = aveAllts12Irrad598/counts_598;
  maxAllts12Irrad598 = maxAllts12Irrad598/counts_598;
  minAllts12Irrad598 = minAllts12Irrad598/counts_598;
  aveAllErrts12Irrad598 = maxAllts12Irrad598 - minAllts12Irrad598;
  
  ULong64_t events599;
  events599 = (Double_t)outputTree599 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events599 ; j++){
    outputTree599 -> GetEvent(j);
    UCNIntegralArray599[counts_599] = UCNIntegral599;
    UCNIntegralErrArray599[counts_599] = UCNIntegralErr599;
    HistIntegralArray599[counts_599] = HistIntegral599;
    HistIntegralErrArray599[counts_599] = sqrt (HistIntegral599);
    avets12IrradArray599[counts_599] = avets12Irrad599;
    avets12ValveOpenArray599[counts_599] = avets12ValveOpen599;
    maxts12IrradArray599[counts_599] = maxts12Irrad599;
    maxts12ValveOpenArray599[counts_599] = maxts12ValveOpen599;
    mints12IrradArray599[counts_599] = mints12Irrad599; 
    mints12ValveOpenArray599[counts_599] = mints12ValveOpen599;
    ts12IrradErr599[counts_599] = maxts12Irrad599 - mints12Irrad599;
    ts12ValveOpenErr599[counts_599] = maxts12ValveOpen599 - mints12ValveOpen599;
    avecurArray599[counts_599] = avecur599;
    maxcurArray599[counts_599] = maxcur599;
    mincurArray599[counts_599] = mincur599;
    ErrcurArray599[counts_599] = maxcur599 - mincur599;
    delaytimeArray599[counts_599] = cycleDelayTime599;
    cycleNumberArray599[counts_599] = cycleNumber599;
    BaselineArray599[counts_599] = Baseline599;
    BaselineIrradArray599[counts_599] = BaselineIrrad599;
    BaselineIrradErrArray599[counts_599] = BaselineIrradErr599;
    FallTimeArray599[counts_599] = FallTime599;
    FallTimeErrArray599[counts_599] = FallTimeErr599;
    RiseTimeArray599[counts_599] = RiseTime599;
    RiseTimeErrArray599[counts_599] = RiseTimeErr599;
    aveAllts12Irrad599 += avets12Irrad599;
    maxAllts12Irrad599 += maxts12Irrad599;
    minAllts12Irrad599 += mints12Irrad599;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599] = UCNIntegral599;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599] = UCNIntegralErr599;
    delayTimeAll[counts_595+ counts_596+counts_597+counts_598+ counts_599] = cycleDelayTime599;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597+ counts_598+counts_599] = HistIntegral599;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597+counts_598+counts_599] = sqrt (HistIntegral599);
    counts_599++;
  }
  aveAllts12Irrad599 = aveAllts12Irrad599/counts_599;
  maxAllts12Irrad599 = maxAllts12Irrad599/counts_599;
  minAllts12Irrad599 = minAllts12Irrad599/counts_599;
  aveAllErrts12Irrad599 = maxAllts12Irrad599 - minAllts12Irrad599;
  
  ULong64_t events600;
  events600 = (Double_t)outputTree600 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events600 ; j++){
    outputTree600 -> GetEvent(j);
    UCNIntegralArray600[counts_600] = UCNIntegral600;
    UCNIntegralErrArray600[counts_600] = UCNIntegralErr600;
    HistIntegralArray600[counts_600] = HistIntegral600;
    HistIntegralErrArray600[counts_600] = sqrt (HistIntegral600);
    avets12IrradArray600[counts_600] = avets12Irrad600;
    avets12ValveOpenArray600[counts_600] = avets12ValveOpen600;
    maxts12IrradArray600[counts_600] = maxts12Irrad600;
    maxts12ValveOpenArray600[counts_600] = maxts12ValveOpen600;
    mints12IrradArray600[counts_600] = mints12Irrad600; 
    mints12ValveOpenArray600[counts_600] = mints12ValveOpen600;
    ts12IrradErr600[counts_600] = maxts12Irrad600 - mints12Irrad600;
    ts12ValveOpenErr600[counts_600] = maxts12ValveOpen600 - mints12ValveOpen600;
    avecurArray600[counts_600] = avecur600;
    maxcurArray600[counts_600] = maxcur600;
    mincurArray600[counts_600] = mincur600;
    ErrcurArray600[counts_600] = maxcur600 - mincur600;
    delaytimeArray600[counts_600] = cycleDelayTime600;
    cycleNumberArray600[counts_600] = cycleNumber600;
    BaselineArray600[counts_600] = Baseline600;
    BaselineIrradArray600[counts_600] = BaselineIrrad600;
    BaselineIrradErrArray600[counts_600] = BaselineIrradErr600;
    FallTimeArray600[counts_600] = FallTime600;
    FallTimeErrArray600[counts_600] = FallTimeErr600;
    RiseTimeArray600[counts_600] = RiseTime600;
    RiseTimeErrArray600[counts_600] = RiseTimeErr600;
    aveAllts12Irrad600 += avets12Irrad600;
    maxAllts12Irrad600 += maxts12Irrad600;
    minAllts12Irrad600 += mints12Irrad600;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599 + counts_600] = UCNIntegral600;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599+counts_600] = UCNIntegralErr600;
    delayTimeAll[counts_595+ counts_596+counts_597+counts_598+ counts_599+counts_600] = cycleDelayTime600;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597+ counts_598+counts_599+counts_600] = HistIntegral600;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597+counts_598+counts_599+counts_600] = sqrt (HistIntegral600);
    counts_600++;
  }
  aveAllts12Irrad600 = aveAllts12Irrad600/counts_600;
  maxAllts12Irrad600 = maxAllts12Irrad600/counts_600;
  minAllts12Irrad600 = minAllts12Irrad600/counts_600;
  aveAllErrts12Irrad600 = maxAllts12Irrad600 - minAllts12Irrad600;




  ULong64_t events601;
  events601 = (Double_t)outputTree601 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events601 ; j++){
    outputTree601 -> GetEvent(j);
    UCNIntegralArray601[counts_601] = UCNIntegral601;
    UCNIntegralErrArray601[counts_601] = UCNIntegralErr601;
    HistIntegralArray601[counts_601] = HistIntegral601;
    HistIntegralErrArray601[counts_601] = sqrt (HistIntegral601);
    avets12IrradArray601[counts_601] = avets12Irrad601;
    avets12ValveOpenArray601[counts_601] = avets12ValveOpen601;
    maxts12IrradArray601[counts_601] = maxts12Irrad601;
    maxts12ValveOpenArray601[counts_601] = maxts12ValveOpen601;
    mints12IrradArray601[counts_601] = mints12Irrad601; 
    mints12ValveOpenArray601[counts_601] = mints12ValveOpen601;
    ts12IrradErr601[counts_601] = maxts12Irrad601 - mints12Irrad601;
    ts12ValveOpenErr601[counts_601] = maxts12ValveOpen601 - mints12ValveOpen601;
    avecurArray601[counts_601] = avecur601;
    maxcurArray601[counts_601] = maxcur601;
    mincurArray601[counts_601] = mincur601;
    ErrcurArray601[counts_601] = maxcur601 - mincur601;
    delaytimeArray601[counts_601] = cycleDelayTime601;
    cycleNumberArray601[counts_601] = cycleNumber601;
    BaselineArray601[counts_601] = Baseline601;
    BaselineIrradArray601[counts_601] = BaselineIrrad601;
    BaselineIrradErrArray601[counts_601] = BaselineIrradErr601;
    FallTimeArray601[counts_601] = FallTime601;
    FallTimeErrArray601[counts_601] = FallTimeErr601;
    RiseTimeArray601[counts_601] = RiseTime601;
    RiseTimeErrArray601[counts_601] = RiseTimeErr601;
    aveAllts12Irrad601 += avets12Irrad601;
    maxAllts12Irrad601 += maxts12Irrad601;
    minAllts12Irrad601 += mints12Irrad601;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599 + counts_600+counts_601] = UCNIntegral601;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599+ counts_600+ counts_601] = UCNIntegralErr601;
    delayTimeAll[counts_595+ counts_596+counts_597+counts_598+ counts_599+ counts_600+ counts_601] = cycleDelayTime601;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597+ counts_598+counts_599+ counts_600+ counts_601] = HistIntegral601;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597+counts_598+counts_599+ counts_600+ counts_601] = sqrt (HistIntegral601);
    counts_601++;
  }
  aveAllts12Irrad601 = aveAllts12Irrad601/counts_601;
  maxAllts12Irrad601 = maxAllts12Irrad601/counts_601;
  minAllts12Irrad601 = minAllts12Irrad601/counts_601;
  aveAllErrts12Irrad601 = maxAllts12Irrad601 - minAllts12Irrad601;




  ULong64_t events602;
  events602 = (Double_t)outputTree602 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events602 ; j++){
    outputTree602 -> GetEvent(j);
    UCNIntegralArray602[counts_602] = UCNIntegral602;
    UCNIntegralErrArray602[counts_602] = UCNIntegralErr602;
    HistIntegralArray602[counts_602] = HistIntegral602;
    HistIntegralErrArray602[counts_602] = sqrt (HistIntegral602);
    avets12IrradArray602[counts_602] = avets12Irrad602;
    avets12ValveOpenArray602[counts_602] = avets12ValveOpen602;
    maxts12IrradArray602[counts_602] = maxts12Irrad602;
    maxts12ValveOpenArray602[counts_602] = maxts12ValveOpen602;
    mints12IrradArray602[counts_602] = mints12Irrad602; 
    mints12ValveOpenArray602[counts_602] = mints12ValveOpen602;
    ts12IrradErr602[counts_602] = maxts12Irrad602 - mints12Irrad602;
    ts12ValveOpenErr602[counts_602] = maxts12ValveOpen602 - mints12ValveOpen602;
    avecurArray602[counts_602] = avecur602;
    maxcurArray602[counts_602] = maxcur602;
    mincurArray602[counts_602] = mincur602;
    ErrcurArray602[counts_602] = maxcur602 - mincur602;
    delaytimeArray602[counts_602] = cycleDelayTime602;
    cycleNumberArray602[counts_602] = cycleNumber602;
    BaselineArray602[counts_602] = Baseline602;
    BaselineIrradArray602[counts_602] = BaselineIrrad602;
    BaselineIrradErrArray602[counts_602] = BaselineIrradErr602;
    FallTimeArray602[counts_602] = FallTime602;
    FallTimeErrArray602[counts_602] = FallTimeErr602;
    RiseTimeArray602[counts_602] = RiseTime602;
    RiseTimeErrArray602[counts_602] = RiseTimeErr602;
    aveAllts12Irrad602 += avets12Irrad602;
    maxAllts12Irrad602 += maxts12Irrad602;
    minAllts12Irrad602 += mints12Irrad602;
    UCNIntegralArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599 + counts_600+counts_601+counts_602] = UCNIntegral602;
    UCNIntegralErrArrayAll[counts_595+ counts_596+counts_597+counts_598 + counts_599+counts_600+counts_601+counts_602] = UCNIntegralErr602;
    delayTimeAll[counts_595+ counts_596+counts_597+counts_598+ counts_599+counts_600+counts_601+counts_602] = cycleDelayTime602;
    HistIntegralArrayAll[counts_595 + counts_596+ counts_597+ counts_598+counts_599+counts_600+counts_601+counts_602] = HistIntegral602;
    HistIntegralErrArrayAll[counts_595+counts_596+counts_597+counts_598+counts_599+counts_600+counts_601+counts_602] = sqrt (HistIntegral602);
    counts_602++;
  }
  aveAllts12Irrad602 = aveAllts12Irrad602/counts_602;
  maxAllts12Irrad602 = maxAllts12Irrad602/counts_602;
  minAllts12Irrad602 = minAllts12Irrad602/counts_602;
  aveAllErrts12Irrad602 = maxAllts12Irrad602 - minAllts12Irrad602;


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
  //              595
  //*********************************
  //*********************************
  TCanvas *c595 = new TCanvas("c595" , "c595" , 1200, 800);
  c595 -> Divide(2,2);
  //c595 -> cd(1);
  TPad *p1 = c595->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr595_delaycounts = new TGraphErrors(counts_595, delaytimeArray595 , UCNIntegralArray595, 0, UCNIntegralErrArray595);

  gr595_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr595_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr595_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr595_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr595_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_delaycounts -> SetMarkerStyle(7);
  gr595_delaycounts -> Fit(fit);
  storage595 = fit -> GetParameter(1);
  storageErr595 = fit -> GetParError(1);
  
  TGraphErrors *gr595_delayhist = new TGraphErrors(counts_595, delaytimeArray595 , HistIntegralArray595, 0, HistIntegralErrArray595);

  gr595_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr595_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr595_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr595_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr595_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr595_delayhist -> SetMarkerColor(2);
  gr595_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr595_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr595_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr595_delaycounts -> Draw("Ap");
  gr595_delayhist -> Draw("p");
  leg2 -> Draw();

  //c595 -> cd(2);
  TPad *p2 = c595->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr595_tempIrradcounts = new TGraphErrors (counts_595 , avets12IrradArray595, UCNIntegralArray595 , ts12IrradErr595 , UCNIntegralErrArray595);
  gr595_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr595_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr595_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr595_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr595_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr595_tempValveOpencounts = new TGraphErrors (counts_595 , avets12ValveOpenArray595, UCNIntegralArray595 , ts12ValveOpenErr595 , UCNIntegralErrArray595);
  gr595_tempValveOpencounts -> SetMarkerStyle(7);
  gr595_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr595_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr595_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr595_tempIrradcounts -> Draw("Ap");
  gr595_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c595 -> cd(3);
  TGraphErrors *gr595_delaytempIrrad = new TGraphErrors (counts_595 , delaytimeArray595, avets12IrradArray595, 0 , ts12IrradErr595);

  gr595_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr595_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr595_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr595_delaytempIrrad -> SetMarkerStyle(7);
  gr595_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr595_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr595_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr595_delaytempValveOpen = new TGraphErrors (counts_595 , delaytimeArray595, avets12ValveOpenArray595, 0 , ts12ValveOpenErr595);

  gr595_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr595_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr595_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr595_delaytempValveOpen -> SetMarkerStyle(7);
  gr595_delaytempValveOpen -> SetMarkerColor(2);
  gr595_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr595_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr595_delaytempIrrad -> Draw("AP");
  gr595_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c595->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr595_curcounts = new TGraphErrors (counts_595 , avecurArray595, UCNIntegralArray595 , ErrcurArray595 , UCNIntegralErrArray595);
  gr595_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr595_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr595_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr595_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr595_curhist = new TGraphErrors (counts_595 , avecurArray595, UCNIntegralArray595 , ErrcurArray595 , UCNIntegralErrArray595);
  gr595_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr595_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr595_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr595_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr595_curhist -> SetMarkerColor(2);
  gr595_curhist -> SetMarkerStyle(7);

  gr595_curcounts -> Draw("Ap");
  gr595_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c595_cycleNum = new TCanvas("c595_cycleNum" , "c595_cycleNum" , 1200, 800);
  c595_cycleNum -> Divide(2,2);
  TPad *p5 = c595_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr595_cyclecounts = new TGraphErrors (counts_595 , cycleNumberArray595, UCNIntegralArray595, 0 , UCNIntegralErrArray595);
  gr595_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr595_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr595_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr595_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr595_cyclehist = new TGraphErrors(counts_595, cycleNumberArray595 , HistIntegralArray595, 0, HistIntegralErrArray595);

  gr595_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr595_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr595_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr595_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr595_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr595_cyclehist -> SetMarkerColor(2);
  gr595_cyclehist -> SetMarkerStyle(7);

  gr595_cyclecounts -> Draw("Ap");
  gr595_cyclehist -> Draw("p");

  leg2-> Draw();

  c595_cycleNum -> cd(2);
 TGraphErrors *gr595_cycledelay = new TGraphErrors (counts_595 , cycleNumberArray595, delaytimeArray595, 0 , 0);
  gr595_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr595_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr595_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr595_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cycledelay -> SetMarkerStyle(7);

  gr595_cycledelay -> Draw("Ap");


  c595_cycleNum -> cd(3);
  TGraphErrors *gr595_cycletempIrrad = new TGraphErrors (counts_595 , cycleNumberArray595, avets12IrradArray595, 0 , ts12IrradErr595);

  gr595_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr595_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr595_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr595_cycletempIrrad -> SetMarkerStyle(7);
  gr595_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr595_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr595_cycletempValveOpen = new TGraphErrors (counts_595 , cycleNumberArray595, avets12ValveOpenArray595, 0 , ts12ValveOpenErr595);

  gr595_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr595_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr595_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr595_cycletempValveOpen -> SetMarkerStyle(7);
  gr595_cycletempValveOpen -> SetMarkerColor(2);
  gr595_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr595_cycletempIrrad -> Draw("AP");
  gr595_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c595_cycleNum -> cd(4);
  TGraphErrors *gr595_cyclecur = new TGraphErrors (counts_595 , cycleNumberArray595 , avecurArray595, 0, ErrcurArray595 );
  gr595_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr595_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr595_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr595_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclecur -> SetMarkerStyle(7);
  gr595_cyclecur -> Draw("Ap");


  TCanvas *c595_cycleNumFit = new TCanvas("c595_cycleNumFit" , "c595_cycleNumFit" , 1200, 800);
  c595_cycleNumFit -> Divide(2,2);

  c595_cycleNumFit -> cd(1);
  TGraphErrors *gr595_cyclefall = new TGraphErrors (counts_595, cycleNumberArray595, FallTimeArray595 , 0, FallTimeErrArray595);

  gr595_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr595_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr595_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr595_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclefall -> SetMarkerStyle(7);
  gr595_cyclefall -> Draw("Ap");


  c595_cycleNumFit -> cd(2);
  TGraphErrors *gr595_cyclebaseline = new TGraphErrors (counts_595, cycleNumberArray595, BaselineArray595 , 0, BaselineErrArray595);

  gr595_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr595_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr595_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr595_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclebaseline -> SetMarkerStyle(7);
  gr595_cyclebaseline -> Draw("Ap");

  c595_cycleNumFit -> cd(3);
  TGraphErrors *gr595_cyclebaselineirrad = new TGraphErrors (counts_595, cycleNumberArray595, BaselineIrradArray595 , 0, BaselineIrradErrArray595);

  gr595_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr595_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr595_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr595_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclebaselineirrad -> SetMarkerStyle(7);
  gr595_cyclebaselineirrad -> Draw("Ap");

  c595_cycleNumFit -> cd(4);
  TGraphErrors *gr595_cyclerise = new TGraphErrors (counts_595, cycleNumberArray595, RiseTimeArray595 , 0, RiseTimeErrArray595);

  gr595_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr595_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr595_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr595_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr595_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr595_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr595_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr595_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr595_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr595_cyclerise -> SetMarkerStyle(7);
  gr595_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              596
  //*********************************
  //*********************************
  TCanvas *c596 = new TCanvas("c596" , "c596" , 1200, 800);
  c596 -> Divide(2,2);
  //c596 -> cd(1);
  TPad *p596_1 = c596->cd(1);
  p596_1->SetLogy(); 
  TGraphErrors *gr596_delaycounts = new TGraphErrors(counts_596, delaytimeArray596 , UCNIntegralArray596, 0, UCNIntegralErrArray596);

  gr596_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr596_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr596_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr596_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr596_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_delaycounts -> SetMarkerStyle(7);
  gr596_delaycounts -> Fit(fit);
  storage596 = fit -> GetParameter(1);
  storageErr596 = fit -> GetParError(1);
  
  TGraphErrors *gr596_delayhist = new TGraphErrors(counts_596, delaytimeArray596 , HistIntegralArray596, 0, HistIntegralErrArray596);

  gr596_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr596_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr596_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr596_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr596_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr596_delayhist -> SetMarkerColor(2);
  gr596_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr596_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr596_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr596_delaycounts -> Draw("Ap");
  gr596_delayhist -> Draw("p");
  leg2 -> Draw();

  //c596 -> cd(2);
  TPad *p596_2 = c596->cd(2);
  p596_2->SetLogy(); 
  TGraphErrors *gr596_tempIrradcounts = new TGraphErrors (counts_596 , avets12IrradArray596, UCNIntegralArray596 , ts12IrradErr596 , UCNIntegralErrArray596);
  gr596_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr596_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr596_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr596_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr596_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr596_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr596_tempValveOpencounts = new TGraphErrors (counts_596 , avets12ValveOpenArray596, UCNIntegralArray596 , ts12ValveOpenErr596 , UCNIntegralErrArray596);
  gr596_tempValveOpencounts -> SetMarkerStyle(7);
  gr596_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr596_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr596_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr596_tempIrradcounts -> Draw("Ap");
  gr596_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c596 -> cd(3);
  TGraphErrors *gr596_delaytempIrrad = new TGraphErrors (counts_596 , delaytimeArray596, avets12IrradArray596, 0 , ts12IrradErr596);

  gr596_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr596_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr596_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr596_delaytempIrrad -> SetMarkerStyle(7);
  gr596_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr596_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr596_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr596_delaytempValveOpen = new TGraphErrors (counts_596 , delaytimeArray596, avets12ValveOpenArray596, 0 , ts12ValveOpenErr596);

  gr596_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr596_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr596_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr596_delaytempValveOpen -> SetMarkerStyle(7);
  gr596_delaytempValveOpen -> SetMarkerColor(2);
  gr596_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr596_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr596_delaytempIrrad -> Draw("AP");
  gr596_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p596_3 = c596->cd(4);
  p596_3->SetLogy(); 
  TGraphErrors *gr596_curcounts = new TGraphErrors (counts_596 , avecurArray596, UCNIntegralArray596 , ErrcurArray596 , UCNIntegralErrArray596);
  gr596_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr596_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr596_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr596_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr596_curhist = new TGraphErrors (counts_596 , avecurArray596, UCNIntegralArray596 , ErrcurArray596 , UCNIntegralErrArray596);
  gr596_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr596_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr596_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr596_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr596_curhist -> SetMarkerColor(2);
  gr596_curhist -> SetMarkerStyle(7);

  gr596_curcounts -> Draw("Ap");
  gr596_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c596_cycleNum = new TCanvas("c596_cycleNum" , "c596_cycleNum" , 1200, 800);
  c596_cycleNum -> Divide(2,2);
  TPad *p596_4 = c596_cycleNum->cd(1);
  p596_4->SetLogy(); 
  TGraphErrors *gr596_cyclecounts = new TGraphErrors (counts_596 , cycleNumberArray596, UCNIntegralArray596, 0 , UCNIntegralErrArray596);
  gr596_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr596_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr596_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr596_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr596_cyclehist = new TGraphErrors(counts_596, cycleNumberArray596 , HistIntegralArray596, 0, HistIntegralErrArray596);

  gr596_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr596_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr596_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr596_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr596_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr596_cyclehist -> SetMarkerColor(2);
  gr596_cyclehist -> SetMarkerStyle(7);

  gr596_cyclecounts -> Draw("Ap");
  gr596_cyclehist -> Draw("p");

  leg2-> Draw();

  c596_cycleNum -> cd(2);
 TGraphErrors *gr596_cycledelay = new TGraphErrors (counts_596 , cycleNumberArray596, delaytimeArray596, 0 , 0);
  gr596_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr596_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr596_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr596_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cycledelay -> SetMarkerStyle(7);

  gr596_cycledelay -> Draw("Ap");


  c596_cycleNum -> cd(3);
  TGraphErrors *gr596_cycletempIrrad = new TGraphErrors (counts_596 , cycleNumberArray596, avets12IrradArray596, 0 , ts12IrradErr596);

  gr596_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr596_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr596_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr596_cycletempIrrad -> SetMarkerStyle(7);
  gr596_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr596_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr596_cycletempValveOpen = new TGraphErrors (counts_596 , cycleNumberArray596, avets12ValveOpenArray596, 0 , ts12ValveOpenErr596);

  gr596_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr596_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr596_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr596_cycletempValveOpen -> SetMarkerStyle(7);
  gr596_cycletempValveOpen -> SetMarkerColor(2);
  gr596_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr596_cycletempIrrad -> Draw("AP");
  gr596_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c596_cycleNum -> cd(4);
  TGraphErrors *gr596_cyclecur = new TGraphErrors (counts_596 , cycleNumberArray596 , avecurArray596, 0, ErrcurArray596 );
  gr596_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr596_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr596_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr596_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclecur -> SetMarkerStyle(7);
  gr596_cyclecur -> Draw("Ap");


  TCanvas *c596_cycleNumFit = new TCanvas("c596_cycleNumFit" , "c596_cycleNumFit" , 1200, 800);
  c596_cycleNumFit -> Divide(2,2);

  c596_cycleNumFit -> cd(1);
  TGraphErrors *gr596_cyclefall = new TGraphErrors (counts_596, cycleNumberArray596, FallTimeArray596 , 0, FallTimeErrArray596);

  gr596_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr596_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr596_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr596_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclefall -> SetMarkerStyle(7);
  gr596_cyclefall -> Draw("Ap");


  c596_cycleNumFit -> cd(2);
  TGraphErrors *gr596_cyclebaseline = new TGraphErrors (counts_596, cycleNumberArray596, BaselineArray596 , 0, BaselineErrArray596);

  gr596_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr596_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr596_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr596_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclebaseline -> SetMarkerStyle(7);
  gr596_cyclebaseline -> Draw("Ap");

  c596_cycleNumFit -> cd(3);
  TGraphErrors *gr596_cyclebaselineirrad = new TGraphErrors (counts_596, cycleNumberArray596, BaselineIrradArray596 , 0, BaselineIrradErrArray596);

  gr596_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr596_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr596_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr596_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclebaselineirrad -> SetMarkerStyle(7);
  gr596_cyclebaselineirrad -> Draw("Ap");

  c596_cycleNumFit -> cd(4);
  TGraphErrors *gr596_cyclerise = new TGraphErrors (counts_596, cycleNumberArray596, RiseTimeArray596 , 0, RiseTimeErrArray596);

  gr596_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr596_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr596_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr596_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr596_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr596_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr596_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr596_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr596_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr596_cyclerise -> SetMarkerStyle(7);
  gr596_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              597
  //*********************************
  //*********************************
  TCanvas *c597 = new TCanvas("c597" , "c597" , 1200, 800);
  c597 -> Divide(2,2);
  //c597 -> cd(1);
  TPad *p597_1 = c597->cd(1);
  p597_1->SetLogy(); 
  TGraphErrors *gr597_delaycounts = new TGraphErrors(counts_597, delaytimeArray597 , UCNIntegralArray597, 0, UCNIntegralErrArray597);

  gr597_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr597_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr597_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr597_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr597_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_delaycounts -> SetMarkerStyle(7);
  gr597_delaycounts -> Fit(fit);
  storage597 = fit -> GetParameter(1);
  storageErr597 = fit -> GetParError(1);
  
  TGraphErrors *gr597_delayhist = new TGraphErrors(counts_597, delaytimeArray597 , HistIntegralArray597, 0, HistIntegralErrArray597);

  gr597_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr597_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr597_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr597_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr597_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr597_delayhist -> SetMarkerColor(2);
  gr597_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr597_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr597_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr597_delaycounts -> Draw("Ap");
  gr597_delayhist -> Draw("p");
  leg2 -> Draw();

  //c597 -> cd(2);
  TPad *p597_2 = c597->cd(2);
  p597_2->SetLogy(); 
  TGraphErrors *gr597_tempIrradcounts = new TGraphErrors (counts_597 , avets12IrradArray597, UCNIntegralArray597 , ts12IrradErr597 , UCNIntegralErrArray597);
  gr597_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr597_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr597_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr597_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr597_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr597_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr597_tempValveOpencounts = new TGraphErrors (counts_597 , avets12ValveOpenArray597, UCNIntegralArray597 , ts12ValveOpenErr597 , UCNIntegralErrArray597);
  gr597_tempValveOpencounts -> SetMarkerStyle(7);
  gr597_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr597_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr597_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr597_tempIrradcounts -> Draw("Ap");
  gr597_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c597 -> cd(3);
  TGraphErrors *gr597_delaytempIrrad = new TGraphErrors (counts_597 , delaytimeArray597, avets12IrradArray597, 0 , ts12IrradErr597);

  gr597_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr597_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr597_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr597_delaytempIrrad -> SetMarkerStyle(7);
  gr597_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr597_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr597_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr597_delaytempValveOpen = new TGraphErrors (counts_597 , delaytimeArray597, avets12ValveOpenArray597, 0 , ts12ValveOpenErr597);

  gr597_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr597_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr597_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr597_delaytempValveOpen -> SetMarkerStyle(7);
  gr597_delaytempValveOpen -> SetMarkerColor(2);
  gr597_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr597_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr597_delaytempIrrad -> Draw("AP");
  gr597_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p597_3 = c597->cd(4);
  p597_3->SetLogy(); 
  TGraphErrors *gr597_curcounts = new TGraphErrors (counts_597 , avecurArray597, UCNIntegralArray597 , ErrcurArray597 , UCNIntegralErrArray597);
  gr597_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr597_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr597_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr597_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr597_curhist = new TGraphErrors (counts_597 , avecurArray597, UCNIntegralArray597 , ErrcurArray597 , UCNIntegralErrArray597);
  gr597_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr597_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr597_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr597_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr597_curhist -> SetMarkerColor(2);
  gr597_curhist -> SetMarkerStyle(7);

  gr597_curcounts -> Draw("Ap");
  gr597_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c597_cycleNum = new TCanvas("c597_cycleNum" , "c597_cycleNum" , 1200, 800);
  c597_cycleNum -> Divide(2,2);
  TPad *p597_4 = c597_cycleNum->cd(1);
  p597_4->SetLogy(); 
  TGraphErrors *gr597_cyclecounts = new TGraphErrors (counts_597 , cycleNumberArray597, UCNIntegralArray597, 0 , UCNIntegralErrArray597);
  gr597_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr597_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr597_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr597_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr597_cyclehist = new TGraphErrors(counts_597, cycleNumberArray597 , HistIntegralArray597, 0, HistIntegralErrArray597);

  gr597_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr597_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr597_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr597_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr597_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr597_cyclehist -> SetMarkerColor(2);
  gr597_cyclehist -> SetMarkerStyle(7);

  gr597_cyclecounts -> Draw("Ap");
  gr597_cyclehist -> Draw("p");

  leg2-> Draw();

  c597_cycleNum -> cd(2);
 TGraphErrors *gr597_cycledelay = new TGraphErrors (counts_597 , cycleNumberArray597, delaytimeArray597, 0 , 0);
  gr597_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr597_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr597_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr597_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cycledelay -> SetMarkerStyle(7);

  gr597_cycledelay -> Draw("Ap");


  c597_cycleNum -> cd(3);
  TGraphErrors *gr597_cycletempIrrad = new TGraphErrors (counts_597 , cycleNumberArray597, avets12IrradArray597, 0 , ts12IrradErr597);

  gr597_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr597_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr597_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr597_cycletempIrrad -> SetMarkerStyle(7);
  gr597_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr597_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr597_cycletempValveOpen = new TGraphErrors (counts_597 , cycleNumberArray597, avets12ValveOpenArray597, 0 , ts12ValveOpenErr597);

  gr597_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr597_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr597_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr597_cycletempValveOpen -> SetMarkerStyle(7);
  gr597_cycletempValveOpen -> SetMarkerColor(2);
  gr597_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr597_cycletempIrrad -> Draw("AP");
  gr597_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c597_cycleNum -> cd(4);
  TGraphErrors *gr597_cyclecur = new TGraphErrors (counts_597 , cycleNumberArray597 , avecurArray597, 0, ErrcurArray597 );
  gr597_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr597_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr597_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr597_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclecur -> SetMarkerStyle(7);
  gr597_cyclecur -> Draw("Ap");


  TCanvas *c597_cycleNumFit = new TCanvas("c597_cycleNumFit" , "c597_cycleNumFit" , 1200, 800);
  c597_cycleNumFit -> Divide(2,2);

  c597_cycleNumFit -> cd(1);
  TGraphErrors *gr597_cyclefall = new TGraphErrors (counts_597, cycleNumberArray597, FallTimeArray597 , 0, FallTimeErrArray597);

  gr597_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr597_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr597_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr597_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclefall -> SetMarkerStyle(7);
  gr597_cyclefall -> Draw("Ap");


  c597_cycleNumFit -> cd(2);
  TGraphErrors *gr597_cyclebaseline = new TGraphErrors (counts_597, cycleNumberArray597, BaselineArray597 , 0, BaselineErrArray597);

  gr597_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr597_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr597_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr597_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclebaseline -> SetMarkerStyle(7);
  gr597_cyclebaseline -> Draw("Ap");

  c597_cycleNumFit -> cd(3);
  TGraphErrors *gr597_cyclebaselineirrad = new TGraphErrors (counts_597, cycleNumberArray597, BaselineIrradArray597 , 0, BaselineIrradErrArray597);

  gr597_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr597_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr597_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr597_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclebaselineirrad -> SetMarkerStyle(7);
  gr597_cyclebaselineirrad -> Draw("Ap");

  c597_cycleNumFit -> cd(4);
  TGraphErrors *gr597_cyclerise = new TGraphErrors (counts_597, cycleNumberArray597, RiseTimeArray597 , 0, RiseTimeErrArray597);

  gr597_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr597_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr597_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr597_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr597_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr597_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr597_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr597_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr597_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr597_cyclerise -> SetMarkerStyle(7);
  gr597_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              598
  //*********************************
  //*********************************
  TCanvas *c598 = new TCanvas("c598" , "c598" , 1200, 800);
  c598 -> Divide(2,2);
  //c598 -> cd(1);
  TPad *p598_1 = c598->cd(1);
  p598_1->SetLogy(); 
  TGraphErrors *gr598_delaycounts = new TGraphErrors(counts_598, delaytimeArray598 , UCNIntegralArray598, 0, UCNIntegralErrArray598);

  gr598_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr598_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr598_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr598_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr598_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_delaycounts -> SetMarkerStyle(7);
  gr598_delaycounts -> Fit(fit);
  storage598 = fit -> GetParameter(1);
  storageErr598 = fit -> GetParError(1);
  
  TGraphErrors *gr598_delayhist = new TGraphErrors(counts_598, delaytimeArray598 , HistIntegralArray598, 0, HistIntegralErrArray598);

  gr598_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr598_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr598_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr598_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr598_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr598_delayhist -> SetMarkerColor(2);
  gr598_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr598_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr598_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr598_delaycounts -> Draw("Ap");
  gr598_delayhist -> Draw("p");
  leg2 -> Draw();

  //c598 -> cd(2);
  TPad *p598_2 = c598->cd(2);
  p598_2->SetLogy(); 
  TGraphErrors *gr598_tempIrradcounts = new TGraphErrors (counts_598 , avets12IrradArray598, UCNIntegralArray598 , ts12IrradErr598 , UCNIntegralErrArray598);
  gr598_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr598_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr598_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr598_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr598_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr598_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr598_tempValveOpencounts = new TGraphErrors (counts_598 , avets12ValveOpenArray598, UCNIntegralArray598 , ts12ValveOpenErr598 , UCNIntegralErrArray598);
  gr598_tempValveOpencounts -> SetMarkerStyle(7);
  gr598_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr598_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr598_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr598_tempIrradcounts -> Draw("Ap");
  gr598_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c598 -> cd(3);
  TGraphErrors *gr598_delaytempIrrad = new TGraphErrors (counts_598 , delaytimeArray598, avets12IrradArray598, 0 , ts12IrradErr598);

  gr598_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr598_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr598_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr598_delaytempIrrad -> SetMarkerStyle(7);
  gr598_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr598_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr598_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr598_delaytempValveOpen = new TGraphErrors (counts_598 , delaytimeArray598, avets12ValveOpenArray598, 0 , ts12ValveOpenErr598);

  gr598_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr598_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr598_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr598_delaytempValveOpen -> SetMarkerStyle(7);
  gr598_delaytempValveOpen -> SetMarkerColor(2);
  gr598_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr598_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr598_delaytempIrrad -> Draw("AP");
  gr598_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p598_3 = c598->cd(4);
  p598_3->SetLogy(); 
  TGraphErrors *gr598_curcounts = new TGraphErrors (counts_598 , avecurArray598, UCNIntegralArray598 , ErrcurArray598 , UCNIntegralErrArray598);
  gr598_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr598_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr598_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr598_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr598_curhist = new TGraphErrors (counts_598 , avecurArray598, UCNIntegralArray598 , ErrcurArray598 , UCNIntegralErrArray598);
  gr598_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr598_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr598_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr598_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr598_curhist -> SetMarkerColor(2);
  gr598_curhist -> SetMarkerStyle(7);

  gr598_curcounts -> Draw("Ap");
  gr598_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c598_cycleNum = new TCanvas("c598_cycleNum" , "c598_cycleNum" , 1200, 800);
  c598_cycleNum -> Divide(2,2);
  TPad *p598_4 = c598_cycleNum->cd(1);
  p598_4->SetLogy(); 
  TGraphErrors *gr598_cyclecounts = new TGraphErrors (counts_598 , cycleNumberArray598, UCNIntegralArray598, 0 , UCNIntegralErrArray598);
  gr598_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr598_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr598_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr598_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr598_cyclehist = new TGraphErrors(counts_598, cycleNumberArray598 , HistIntegralArray598, 0, HistIntegralErrArray598);

  gr598_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr598_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr598_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr598_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr598_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr598_cyclehist -> SetMarkerColor(2);
  gr598_cyclehist -> SetMarkerStyle(7);

  gr598_cyclecounts -> Draw("Ap");
  gr598_cyclehist -> Draw("p");

  leg2-> Draw();

  c598_cycleNum -> cd(2);
 TGraphErrors *gr598_cycledelay = new TGraphErrors (counts_598 , cycleNumberArray598, delaytimeArray598, 0 , 0);
  gr598_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr598_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr598_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr598_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cycledelay -> SetMarkerStyle(7);

  gr598_cycledelay -> Draw("Ap");


  c598_cycleNum -> cd(3);
  TGraphErrors *gr598_cycletempIrrad = new TGraphErrors (counts_598 , cycleNumberArray598, avets12IrradArray598, 0 , ts12IrradErr598);

  gr598_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr598_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr598_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr598_cycletempIrrad -> SetMarkerStyle(7);
  gr598_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr598_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr598_cycletempValveOpen = new TGraphErrors (counts_598 , cycleNumberArray598, avets12ValveOpenArray598, 0 , ts12ValveOpenErr598);

  gr598_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr598_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr598_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr598_cycletempValveOpen -> SetMarkerStyle(7);
  gr598_cycletempValveOpen -> SetMarkerColor(2);
  gr598_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr598_cycletempIrrad -> Draw("AP");
  gr598_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c598_cycleNum -> cd(4);
  TGraphErrors *gr598_cyclecur = new TGraphErrors (counts_598 , cycleNumberArray598 , avecurArray598, 0, ErrcurArray598 );
  gr598_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr598_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr598_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr598_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclecur -> SetMarkerStyle(7);
  gr598_cyclecur -> Draw("Ap");


  TCanvas *c598_cycleNumFit = new TCanvas("c598_cycleNumFit" , "c598_cycleNumFit" , 1200, 800);
  c598_cycleNumFit -> Divide(2,2);

  c598_cycleNumFit -> cd(1);
  TGraphErrors *gr598_cyclefall = new TGraphErrors (counts_598, cycleNumberArray598, FallTimeArray598 , 0, FallTimeErrArray598);

  gr598_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr598_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr598_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr598_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclefall -> SetMarkerStyle(7);
  gr598_cyclefall -> Draw("Ap");


  c598_cycleNumFit -> cd(2);
  TGraphErrors *gr598_cyclebaseline = new TGraphErrors (counts_598, cycleNumberArray598, BaselineArray598 , 0, BaselineErrArray598);

  gr598_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr598_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr598_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr598_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclebaseline -> SetMarkerStyle(7);
  gr598_cyclebaseline -> Draw("Ap");

  c598_cycleNumFit -> cd(3);
  TGraphErrors *gr598_cyclebaselineirrad = new TGraphErrors (counts_598, cycleNumberArray598, BaselineIrradArray598 , 0, BaselineIrradErrArray598);

  gr598_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr598_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr598_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr598_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclebaselineirrad -> SetMarkerStyle(7);
  gr598_cyclebaselineirrad -> Draw("Ap");

  c598_cycleNumFit -> cd(4);
  TGraphErrors *gr598_cyclerise = new TGraphErrors (counts_598, cycleNumberArray598, RiseTimeArray598 , 0, RiseTimeErrArray598);

  gr598_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr598_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr598_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr598_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr598_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr598_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr598_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr598_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr598_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr598_cyclerise -> SetMarkerStyle(7);
  gr598_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              599
  //*********************************
  //*********************************
  TCanvas *c599 = new TCanvas("c599" , "c599" , 1200, 800);
  c599 -> Divide(2,2);
  //c599 -> cd(1);
  TPad *p599_1 = c599->cd(1);
  p599_1->SetLogy(); 
  TGraphErrors *gr599_delaycounts = new TGraphErrors(counts_599, delaytimeArray599 , UCNIntegralArray599, 0, UCNIntegralErrArray599);

  gr599_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr599_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr599_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr599_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr599_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_delaycounts -> SetMarkerStyle(7);
  gr599_delaycounts -> Fit(fit);
  storage599 = fit -> GetParameter(1);
  storageErr599 = fit -> GetParError(1);
  
  TGraphErrors *gr599_delayhist = new TGraphErrors(counts_599, delaytimeArray599 , HistIntegralArray599, 0, HistIntegralErrArray599);

  gr599_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr599_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr599_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr599_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr599_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr599_delayhist -> SetMarkerColor(2);
  gr599_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr599_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr599_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr599_delaycounts -> Draw("Ap");
  gr599_delayhist -> Draw("p");
  leg2 -> Draw();

  //c599 -> cd(2);
  TPad *p599_2 = c599->cd(2);
  p599_2->SetLogy(); 
  TGraphErrors *gr599_tempIrradcounts = new TGraphErrors (counts_599 , avets12IrradArray599, UCNIntegralArray599 , ts12IrradErr599 , UCNIntegralErrArray599);
  gr599_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr599_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr599_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr599_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr599_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr599_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr599_tempValveOpencounts = new TGraphErrors (counts_599 , avets12ValveOpenArray599, UCNIntegralArray599 , ts12ValveOpenErr599 , UCNIntegralErrArray599);
  gr599_tempValveOpencounts -> SetMarkerStyle(7);
  gr599_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr599_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr599_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr599_tempIrradcounts -> Draw("Ap");
  gr599_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c599 -> cd(3);
  TGraphErrors *gr599_delaytempIrrad = new TGraphErrors (counts_599 , delaytimeArray599, avets12IrradArray599, 0 , ts12IrradErr599);

  gr599_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr599_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr599_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr599_delaytempIrrad -> SetMarkerStyle(7);
  gr599_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr599_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr599_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr599_delaytempValveOpen = new TGraphErrors (counts_599 , delaytimeArray599, avets12ValveOpenArray599, 0 , ts12ValveOpenErr599);

  gr599_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr599_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr599_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr599_delaytempValveOpen -> SetMarkerStyle(7);
  gr599_delaytempValveOpen -> SetMarkerColor(2);
  gr599_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr599_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr599_delaytempIrrad -> Draw("AP");
  gr599_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p599_3 = c599->cd(4);
  p599_3->SetLogy(); 
  TGraphErrors *gr599_curcounts = new TGraphErrors (counts_599 , avecurArray599, UCNIntegralArray599 , ErrcurArray599 , UCNIntegralErrArray599);
  gr599_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr599_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr599_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr599_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr599_curhist = new TGraphErrors (counts_599 , avecurArray599, UCNIntegralArray599 , ErrcurArray599 , UCNIntegralErrArray599);
  gr599_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr599_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr599_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr599_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr599_curhist -> SetMarkerColor(2);
  gr599_curhist -> SetMarkerStyle(7);

  gr599_curcounts -> Draw("Ap");
  gr599_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c599_cycleNum = new TCanvas("c599_cycleNum" , "c599_cycleNum" , 1200, 800);
  c599_cycleNum -> Divide(2,2);
  TPad *p599_4 = c599_cycleNum->cd(1);
  p599_4->SetLogy(); 
  TGraphErrors *gr599_cyclecounts = new TGraphErrors (counts_599 , cycleNumberArray599, UCNIntegralArray599, 0 , UCNIntegralErrArray599);
  gr599_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr599_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr599_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr599_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr599_cyclehist = new TGraphErrors(counts_599, cycleNumberArray599 , HistIntegralArray599, 0, HistIntegralErrArray599);

  gr599_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr599_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr599_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr599_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr599_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr599_cyclehist -> SetMarkerColor(2);
  gr599_cyclehist -> SetMarkerStyle(7);

  gr599_cyclecounts -> Draw("Ap");
  gr599_cyclehist -> Draw("p");

  leg2-> Draw();

  c599_cycleNum -> cd(2);
 TGraphErrors *gr599_cycledelay = new TGraphErrors (counts_599 , cycleNumberArray599, delaytimeArray599, 0 , 0);
  gr599_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr599_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr599_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr599_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cycledelay -> SetMarkerStyle(7);

  gr599_cycledelay -> Draw("Ap");


  c599_cycleNum -> cd(3);
  TGraphErrors *gr599_cycletempIrrad = new TGraphErrors (counts_599 , cycleNumberArray599, avets12IrradArray599, 0 , ts12IrradErr599);

  gr599_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr599_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr599_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr599_cycletempIrrad -> SetMarkerStyle(7);
  gr599_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr599_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr599_cycletempValveOpen = new TGraphErrors (counts_599 , cycleNumberArray599, avets12ValveOpenArray599, 0 , ts12ValveOpenErr599);

  gr599_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr599_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr599_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr599_cycletempValveOpen -> SetMarkerStyle(7);
  gr599_cycletempValveOpen -> SetMarkerColor(2);
  gr599_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr599_cycletempIrrad -> Draw("AP");
  gr599_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c599_cycleNum -> cd(4);
  TGraphErrors *gr599_cyclecur = new TGraphErrors (counts_599 , cycleNumberArray599 , avecurArray599, 0, ErrcurArray599 );
  gr599_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr599_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr599_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr599_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclecur -> SetMarkerStyle(7);
  gr599_cyclecur -> Draw("Ap");


  TCanvas *c599_cycleNumFit = new TCanvas("c599_cycleNumFit" , "c599_cycleNumFit" , 1200, 800);
  c599_cycleNumFit -> Divide(2,2);

  c599_cycleNumFit -> cd(1);
  TGraphErrors *gr599_cyclefall = new TGraphErrors (counts_599, cycleNumberArray599, FallTimeArray599 , 0, FallTimeErrArray599);

  gr599_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr599_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr599_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr599_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclefall -> SetMarkerStyle(7);
  gr599_cyclefall -> Draw("Ap");


  c599_cycleNumFit -> cd(2);
  TGraphErrors *gr599_cyclebaseline = new TGraphErrors (counts_599, cycleNumberArray599, BaselineArray599 , 0, BaselineErrArray599);

  gr599_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr599_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr599_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr599_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclebaseline -> SetMarkerStyle(7);
  gr599_cyclebaseline -> Draw("Ap");

  c599_cycleNumFit -> cd(3);
  TGraphErrors *gr599_cyclebaselineirrad = new TGraphErrors (counts_599, cycleNumberArray599, BaselineIrradArray599 , 0, BaselineIrradErrArray599);

  gr599_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr599_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr599_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr599_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclebaselineirrad -> SetMarkerStyle(7);
  gr599_cyclebaselineirrad -> Draw("Ap");

  c599_cycleNumFit -> cd(4);
  TGraphErrors *gr599_cyclerise = new TGraphErrors (counts_599, cycleNumberArray599, RiseTimeArray599 , 0, RiseTimeErrArray599);

  gr599_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr599_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr599_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr599_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr599_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr599_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr599_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr599_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr599_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr599_cyclerise -> SetMarkerStyle(7);
  gr599_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              600
  //*********************************
  //*********************************
  TCanvas *c600 = new TCanvas("c600" , "c600" , 1200, 800);
  c600 -> Divide(2,2);
  //c600 -> cd(1);
  TPad *p600_1 = c600->cd(1);
  p600_1->SetLogy(); 
  TGraphErrors *gr600_delaycounts = new TGraphErrors(counts_600, delaytimeArray600 , UCNIntegralArray600, 0, UCNIntegralErrArray600);

  gr600_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr600_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr600_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr600_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr600_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_delaycounts -> SetMarkerStyle(7);
  gr600_delaycounts -> Fit(fit);
  storage600 = fit -> GetParameter(1);
  storageErr600 = fit -> GetParError(1);
  
  TGraphErrors *gr600_delayhist = new TGraphErrors(counts_600, delaytimeArray600 , HistIntegralArray600, 0, HistIntegralErrArray600);

  gr600_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr600_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr600_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr600_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr600_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr600_delayhist -> SetMarkerColor(2);
  gr600_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr600_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr600_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr600_delaycounts -> Draw("Ap");
  gr600_delayhist -> Draw("p");
  leg2 -> Draw();

  //c600 -> cd(2);
  TPad *p600_2 = c600->cd(2);
  p600_2->SetLogy(); 
  TGraphErrors *gr600_tempIrradcounts = new TGraphErrors (counts_600 , avets12IrradArray600, UCNIntegralArray600 , ts12IrradErr600 , UCNIntegralErrArray600);
  gr600_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr600_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr600_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr600_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr600_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr600_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr600_tempValveOpencounts = new TGraphErrors (counts_600 , avets12ValveOpenArray600, UCNIntegralArray600 , ts12ValveOpenErr600 , UCNIntegralErrArray600);
  gr600_tempValveOpencounts -> SetMarkerStyle(7);
  gr600_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr600_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr600_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr600_tempIrradcounts -> Draw("Ap");
  gr600_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c600 -> cd(3);
  TGraphErrors *gr600_delaytempIrrad = new TGraphErrors (counts_600 , delaytimeArray600, avets12IrradArray600, 0 , ts12IrradErr600);

  gr600_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr600_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr600_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr600_delaytempIrrad -> SetMarkerStyle(7);
  gr600_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr600_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr600_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr600_delaytempValveOpen = new TGraphErrors (counts_600 , delaytimeArray600, avets12ValveOpenArray600, 0 , ts12ValveOpenErr600);

  gr600_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr600_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr600_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr600_delaytempValveOpen -> SetMarkerStyle(7);
  gr600_delaytempValveOpen -> SetMarkerColor(2);
  gr600_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr600_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr600_delaytempIrrad -> Draw("AP");
  gr600_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p600_3 = c600->cd(4);
  p600_3->SetLogy(); 
  TGraphErrors *gr600_curcounts = new TGraphErrors (counts_600 , avecurArray600, UCNIntegralArray600 , ErrcurArray600 , UCNIntegralErrArray600);
  gr600_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr600_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr600_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr600_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr600_curhist = new TGraphErrors (counts_600 , avecurArray600, UCNIntegralArray600 , ErrcurArray600 , UCNIntegralErrArray600);
  gr600_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr600_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr600_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr600_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr600_curhist -> SetMarkerColor(2);
  gr600_curhist -> SetMarkerStyle(7);

  gr600_curcounts -> Draw("Ap");
  gr600_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c600_cycleNum = new TCanvas("c600_cycleNum" , "c600_cycleNum" , 1200, 800);
  c600_cycleNum -> Divide(2,2);
  TPad *p600_4 = c600_cycleNum->cd(1);
  p600_4->SetLogy(); 
  TGraphErrors *gr600_cyclecounts = new TGraphErrors (counts_600 , cycleNumberArray600, UCNIntegralArray600, 0 , UCNIntegralErrArray600);
  gr600_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr600_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr600_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr600_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr600_cyclehist = new TGraphErrors(counts_600, cycleNumberArray600 , HistIntegralArray600, 0, HistIntegralErrArray600);

  gr600_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr600_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr600_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr600_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr600_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr600_cyclehist -> SetMarkerColor(2);
  gr600_cyclehist -> SetMarkerStyle(7);

  gr600_cyclecounts -> Draw("Ap");
  gr600_cyclehist -> Draw("p");

  leg2-> Draw();

  c600_cycleNum -> cd(2);
 TGraphErrors *gr600_cycledelay = new TGraphErrors (counts_600 , cycleNumberArray600, delaytimeArray600, 0 , 0);
  gr600_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr600_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr600_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr600_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cycledelay -> SetMarkerStyle(7);

  gr600_cycledelay -> Draw("Ap");


  c600_cycleNum -> cd(3);
  TGraphErrors *gr600_cycletempIrrad = new TGraphErrors (counts_600 , cycleNumberArray600, avets12IrradArray600, 0 , ts12IrradErr600);

  gr600_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr600_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr600_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr600_cycletempIrrad -> SetMarkerStyle(7);
  gr600_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr600_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr600_cycletempValveOpen = new TGraphErrors (counts_600 , cycleNumberArray600, avets12ValveOpenArray600, 0 , ts12ValveOpenErr600);

  gr600_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr600_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr600_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr600_cycletempValveOpen -> SetMarkerStyle(7);
  gr600_cycletempValveOpen -> SetMarkerColor(2);
  gr600_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr600_cycletempIrrad -> Draw("AP");
  gr600_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c600_cycleNum -> cd(4);
  TGraphErrors *gr600_cyclecur = new TGraphErrors (counts_600 , cycleNumberArray600 , avecurArray600, 0, ErrcurArray600 );
  gr600_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr600_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr600_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr600_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclecur -> SetMarkerStyle(7);
  gr600_cyclecur -> Draw("Ap");


  TCanvas *c600_cycleNumFit = new TCanvas("c600_cycleNumFit" , "c600_cycleNumFit" , 1200, 800);
  c600_cycleNumFit -> Divide(2,2);

  c600_cycleNumFit -> cd(1);
  TGraphErrors *gr600_cyclefall = new TGraphErrors (counts_600, cycleNumberArray600, FallTimeArray600 , 0, FallTimeErrArray600);

  gr600_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr600_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr600_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr600_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclefall -> SetMarkerStyle(7);
  gr600_cyclefall -> Draw("Ap");


  c600_cycleNumFit -> cd(2);
  TGraphErrors *gr600_cyclebaseline = new TGraphErrors (counts_600, cycleNumberArray600, BaselineArray600 , 0, BaselineErrArray600);

  gr600_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr600_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr600_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr600_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclebaseline -> SetMarkerStyle(7);
  gr600_cyclebaseline -> Draw("Ap");

  c600_cycleNumFit -> cd(3);
  TGraphErrors *gr600_cyclebaselineirrad = new TGraphErrors (counts_600, cycleNumberArray600, BaselineIrradArray600 , 0, BaselineIrradErrArray600);

  gr600_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr600_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr600_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr600_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclebaselineirrad -> SetMarkerStyle(7);
  gr600_cyclebaselineirrad -> Draw("Ap");

  c600_cycleNumFit -> cd(4);
  TGraphErrors *gr600_cyclerise = new TGraphErrors (counts_600, cycleNumberArray600, RiseTimeArray600 , 0, RiseTimeErrArray600);

  gr600_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr600_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr600_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr600_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr600_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr600_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr600_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr600_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr600_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr600_cyclerise -> SetMarkerStyle(7);
  gr600_cyclerise -> Draw("Ap");






  //*********************************
  //*********************************
  //              601
  //*********************************
  //*********************************
  TCanvas *c601 = new TCanvas("c601" , "c601" , 1200, 800);
  c601 -> Divide(2,2);
  //c601 -> cd(1);
  TPad *p601_1 = c601->cd(1);
  p601_1->SetLogy(); 
  TGraphErrors *gr601_delaycounts = new TGraphErrors(counts_601, delaytimeArray601 , UCNIntegralArray601, 0, UCNIntegralErrArray601);

  gr601_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr601_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr601_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr601_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr601_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_delaycounts -> SetMarkerStyle(7);
  gr601_delaycounts -> Fit(fit);
  storage601 = fit -> GetParameter(1);
  storageErr601 = fit -> GetParError(1);
  
  TGraphErrors *gr601_delayhist = new TGraphErrors(counts_601, delaytimeArray601 , HistIntegralArray601, 0, HistIntegralErrArray601);

  gr601_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr601_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr601_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr601_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr601_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr601_delayhist -> SetMarkerColor(2);
  gr601_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr601_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr601_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr601_delaycounts -> Draw("Ap");
  gr601_delayhist -> Draw("p");
  leg2 -> Draw();

  //c601 -> cd(2);
  TPad *p601_2 = c601->cd(2);
  p601_2->SetLogy(); 
  TGraphErrors *gr601_tempIrradcounts = new TGraphErrors (counts_601 , avets12IrradArray601, UCNIntegralArray601 , ts12IrradErr601 , UCNIntegralErrArray601);
  gr601_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr601_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr601_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr601_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr601_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr601_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr601_tempValveOpencounts = new TGraphErrors (counts_601 , avets12ValveOpenArray601, UCNIntegralArray601 , ts12ValveOpenErr601 , UCNIntegralErrArray601);
  gr601_tempValveOpencounts -> SetMarkerStyle(7);
  gr601_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr601_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr601_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr601_tempIrradcounts -> Draw("Ap");
  gr601_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c601 -> cd(3);
  TGraphErrors *gr601_delaytempIrrad = new TGraphErrors (counts_601 , delaytimeArray601, avets12IrradArray601, 0 , ts12IrradErr601);

  gr601_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr601_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr601_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr601_delaytempIrrad -> SetMarkerStyle(7);
  gr601_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr601_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr601_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr601_delaytempValveOpen = new TGraphErrors (counts_601 , delaytimeArray601, avets12ValveOpenArray601, 0 , ts12ValveOpenErr601);

  gr601_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr601_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr601_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr601_delaytempValveOpen -> SetMarkerStyle(7);
  gr601_delaytempValveOpen -> SetMarkerColor(2);
  gr601_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr601_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr601_delaytempIrrad -> Draw("AP");
  gr601_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p601_3 = c601->cd(4);
  p601_3->SetLogy(); 
  TGraphErrors *gr601_curcounts = new TGraphErrors (counts_601 , avecurArray601, UCNIntegralArray601 , ErrcurArray601 , UCNIntegralErrArray601);
  gr601_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr601_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr601_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr601_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr601_curhist = new TGraphErrors (counts_601 , avecurArray601, UCNIntegralArray601 , ErrcurArray601 , UCNIntegralErrArray601);
  gr601_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr601_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr601_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr601_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr601_curhist -> SetMarkerColor(2);
  gr601_curhist -> SetMarkerStyle(7);

  gr601_curcounts -> Draw("Ap");
  gr601_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c601_cycleNum = new TCanvas("c601_cycleNum" , "c601_cycleNum" , 1200, 800);
  c601_cycleNum -> Divide(2,2);
  TPad *p601_4 = c601_cycleNum->cd(1);
  p601_4->SetLogy(); 
  TGraphErrors *gr601_cyclecounts = new TGraphErrors (counts_601 , cycleNumberArray601, UCNIntegralArray601, 0 , UCNIntegralErrArray601);
  gr601_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr601_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr601_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr601_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr601_cyclehist = new TGraphErrors(counts_601, cycleNumberArray601 , HistIntegralArray601, 0, HistIntegralErrArray601);

  gr601_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr601_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr601_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr601_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr601_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr601_cyclehist -> SetMarkerColor(2);
  gr601_cyclehist -> SetMarkerStyle(7);

  gr601_cyclecounts -> Draw("Ap");
  gr601_cyclehist -> Draw("p");

  leg2-> Draw();

  c601_cycleNum -> cd(2);
 TGraphErrors *gr601_cycledelay = new TGraphErrors (counts_601 , cycleNumberArray601, delaytimeArray601, 0 , 0);
  gr601_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr601_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr601_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr601_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cycledelay -> SetMarkerStyle(7);

  gr601_cycledelay -> Draw("Ap");


  c601_cycleNum -> cd(3);
  TGraphErrors *gr601_cycletempIrrad = new TGraphErrors (counts_601 , cycleNumberArray601, avets12IrradArray601, 0 , ts12IrradErr601);

  gr601_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr601_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr601_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr601_cycletempIrrad -> SetMarkerStyle(7);
  gr601_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr601_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr601_cycletempValveOpen = new TGraphErrors (counts_601 , cycleNumberArray601, avets12ValveOpenArray601, 0 , ts12ValveOpenErr601);

  gr601_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr601_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr601_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr601_cycletempValveOpen -> SetMarkerStyle(7);
  gr601_cycletempValveOpen -> SetMarkerColor(2);
  gr601_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr601_cycletempIrrad -> Draw("AP");
  gr601_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c601_cycleNum -> cd(4);
  TGraphErrors *gr601_cyclecur = new TGraphErrors (counts_601 , cycleNumberArray601 , avecurArray601, 0, ErrcurArray601 );
  gr601_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr601_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr601_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr601_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclecur -> SetMarkerStyle(7);
  gr601_cyclecur -> Draw("Ap");


  TCanvas *c601_cycleNumFit = new TCanvas("c601_cycleNumFit" , "c601_cycleNumFit" , 1200, 800);
  c601_cycleNumFit -> Divide(2,2);

  c601_cycleNumFit -> cd(1);
  TGraphErrors *gr601_cyclefall = new TGraphErrors (counts_601, cycleNumberArray601, FallTimeArray601 , 0, FallTimeErrArray601);

  gr601_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr601_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr601_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr601_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclefall -> SetMarkerStyle(7);
  gr601_cyclefall -> Draw("Ap");


  c601_cycleNumFit -> cd(2);
  TGraphErrors *gr601_cyclebaseline = new TGraphErrors (counts_601, cycleNumberArray601, BaselineArray601 , 0, BaselineErrArray601);

  gr601_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr601_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr601_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr601_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclebaseline -> SetMarkerStyle(7);
  gr601_cyclebaseline -> Draw("Ap");

  c601_cycleNumFit -> cd(3);
  TGraphErrors *gr601_cyclebaselineirrad = new TGraphErrors (counts_601, cycleNumberArray601, BaselineIrradArray601 , 0, BaselineIrradErrArray601);

  gr601_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr601_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr601_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr601_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclebaselineirrad -> SetMarkerStyle(7);
  gr601_cyclebaselineirrad -> Draw("Ap");

  c601_cycleNumFit -> cd(4);
  TGraphErrors *gr601_cyclerise = new TGraphErrors (counts_601, cycleNumberArray601, RiseTimeArray601 , 0, RiseTimeErrArray601);

  gr601_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr601_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr601_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr601_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr601_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr601_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr601_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr601_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr601_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr601_cyclerise -> SetMarkerStyle(7);
  gr601_cyclerise -> Draw("Ap");







  //*********************************
  //*********************************
  //              602
  //*********************************
  //*********************************
  TCanvas *c602 = new TCanvas("c602" , "c602" , 1200, 800);
  c602 -> Divide(2,2);
  //c602 -> cd(1);
  TPad *p602_1 = c602->cd(1);
  p602_1->SetLogy(); 
  TGraphErrors *gr602_delaycounts = new TGraphErrors(counts_602, delaytimeArray602 , UCNIntegralArray602, 0, UCNIntegralErrArray602);

  gr602_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr602_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr602_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr602_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr602_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_delaycounts -> SetMarkerStyle(7);
  gr602_delaycounts -> Fit(fit);
  storage602 = fit -> GetParameter(1);
  storageErr602 = fit -> GetParError(1);
  
  TGraphErrors *gr602_delayhist = new TGraphErrors(counts_602, delaytimeArray602 , HistIntegralArray602, 0, HistIntegralErrArray602);

  gr602_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr602_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr602_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr602_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr602_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr602_delayhist -> SetMarkerColor(2);
  gr602_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr602_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr602_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr602_delaycounts -> Draw("Ap");
  gr602_delayhist -> Draw("p");
  leg2 -> Draw();

  //c602 -> cd(2);
  TPad *p602_2 = c602->cd(2);
  p602_2->SetLogy(); 
  TGraphErrors *gr602_tempIrradcounts = new TGraphErrors (counts_602 , avets12IrradArray602, UCNIntegralArray602 , ts12IrradErr602 , UCNIntegralErrArray602);
  gr602_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr602_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr602_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr602_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr602_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr602_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr602_tempValveOpencounts = new TGraphErrors (counts_602 , avets12ValveOpenArray602, UCNIntegralArray602 , ts12ValveOpenErr602 , UCNIntegralErrArray602);
  gr602_tempValveOpencounts -> SetMarkerStyle(7);
  gr602_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr602_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr602_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr602_tempIrradcounts -> Draw("Ap");
  gr602_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c602 -> cd(3);
  TGraphErrors *gr602_delaytempIrrad = new TGraphErrors (counts_602 , delaytimeArray602, avets12IrradArray602, 0 , ts12IrradErr602);

  gr602_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr602_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr602_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr602_delaytempIrrad -> SetMarkerStyle(7);
  gr602_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr602_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr602_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr602_delaytempValveOpen = new TGraphErrors (counts_602 , delaytimeArray602, avets12ValveOpenArray602, 0 , ts12ValveOpenErr602);

  gr602_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr602_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr602_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr602_delaytempValveOpen -> SetMarkerStyle(7);
  gr602_delaytempValveOpen -> SetMarkerColor(2);
  gr602_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr602_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr602_delaytempIrrad -> Draw("AP");
  gr602_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p602_3 = c602->cd(4);
  p602_3->SetLogy(); 
  TGraphErrors *gr602_curcounts = new TGraphErrors (counts_602 , avecurArray602, UCNIntegralArray602 , ErrcurArray602 , UCNIntegralErrArray602);
  gr602_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr602_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr602_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr602_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr602_curhist = new TGraphErrors (counts_602 , avecurArray602, UCNIntegralArray602 , ErrcurArray602 , UCNIntegralErrArray602);
  gr602_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr602_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr602_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr602_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr602_curhist -> SetMarkerColor(2);
  gr602_curhist -> SetMarkerStyle(7);

  gr602_curcounts -> Draw("Ap");
  gr602_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c602_cycleNum = new TCanvas("c602_cycleNum" , "c602_cycleNum" , 1200, 800);
  c602_cycleNum -> Divide(2,2);
  TPad *p602_4 = c602_cycleNum->cd(1);
  p602_4->SetLogy(); 
  TGraphErrors *gr602_cyclecounts = new TGraphErrors (counts_602 , cycleNumberArray602, UCNIntegralArray602, 0 , UCNIntegralErrArray602);
  gr602_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr602_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr602_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr602_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr602_cyclehist = new TGraphErrors(counts_602, cycleNumberArray602 , HistIntegralArray602, 0, HistIntegralErrArray602);

  gr602_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr602_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr602_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr602_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr602_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr602_cyclehist -> SetMarkerColor(2);
  gr602_cyclehist -> SetMarkerStyle(7);

  gr602_cyclecounts -> Draw("Ap");
  gr602_cyclehist -> Draw("p");

  leg2-> Draw();

  c602_cycleNum -> cd(2);
 TGraphErrors *gr602_cycledelay = new TGraphErrors (counts_602 , cycleNumberArray602, delaytimeArray602, 0 , 0);
  gr602_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr602_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr602_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr602_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cycledelay -> SetMarkerStyle(7);

  gr602_cycledelay -> Draw("Ap");


  c602_cycleNum -> cd(3);
  TGraphErrors *gr602_cycletempIrrad = new TGraphErrors (counts_602 , cycleNumberArray602, avets12IrradArray602, 0 , ts12IrradErr602);

  gr602_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr602_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr602_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr602_cycletempIrrad -> SetMarkerStyle(7);
  gr602_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr602_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr602_cycletempValveOpen = new TGraphErrors (counts_602 , cycleNumberArray602, avets12ValveOpenArray602, 0 , ts12ValveOpenErr602);

  gr602_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr602_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr602_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr602_cycletempValveOpen -> SetMarkerStyle(7);
  gr602_cycletempValveOpen -> SetMarkerColor(2);
  gr602_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr602_cycletempIrrad -> Draw("AP");
  gr602_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c602_cycleNum -> cd(4);
  TGraphErrors *gr602_cyclecur = new TGraphErrors (counts_602 , cycleNumberArray602 , avecurArray602, 0, ErrcurArray602 );
  gr602_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr602_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr602_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr602_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclecur -> SetMarkerStyle(7);
  gr602_cyclecur -> Draw("Ap");


  TCanvas *c602_cycleNumFit = new TCanvas("c602_cycleNumFit" , "c602_cycleNumFit" , 1200, 800);
  c602_cycleNumFit -> Divide(2,2);

  c602_cycleNumFit -> cd(1);
  TGraphErrors *gr602_cyclefall = new TGraphErrors (counts_602, cycleNumberArray602, FallTimeArray602 , 0, FallTimeErrArray602);

  gr602_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr602_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr602_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr602_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclefall -> SetMarkerStyle(7);
  gr602_cyclefall -> Draw("Ap");


  c602_cycleNumFit -> cd(2);
  TGraphErrors *gr602_cyclebaseline = new TGraphErrors (counts_602, cycleNumberArray602, BaselineArray602 , 0, BaselineErrArray602);

  gr602_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr602_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr602_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr602_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclebaseline -> SetMarkerStyle(7);
  gr602_cyclebaseline -> Draw("Ap");

  c602_cycleNumFit -> cd(3);
  TGraphErrors *gr602_cyclebaselineirrad = new TGraphErrors (counts_602, cycleNumberArray602, BaselineIrradArray602 , 0, BaselineIrradErrArray602);

  gr602_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr602_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr602_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr602_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclebaselineirrad -> SetMarkerStyle(7);
  gr602_cyclebaselineirrad -> Draw("Ap");

  c602_cycleNumFit -> cd(4);
  TGraphErrors *gr602_cyclerise = new TGraphErrors (counts_602, cycleNumberArray602, RiseTimeArray602 , 0, RiseTimeErrArray602);

  gr602_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr602_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr602_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr602_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr602_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr602_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr602_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr602_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr602_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr602_cyclerise -> SetMarkerStyle(7);
  gr602_cyclerise -> Draw("Ap");








  /*

  double StorageAll [100] = {storage595, storage596, storage598, storage599, storage600, storage540};
  double StorageErrAll[100] = {storageErr595, storageErr596, storageErr598, storageErr598, storageErr599, storageErr600, storageErr540};
  double runNum[100] = {595, 596, 598, 599, 600, 540};
  double tempIrradAll[100] = {aveAllts12Irrad595, aveAllts12Irrad596, aveAllts12Irrad598, aveAllts12Irrad599, aveAllts12Irrad600, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad595,  aveAllErrts12Irrad596,  aveAllErrts12Irrad597,  aveAllErrts12Irrad599,  aveAllErrts12Irrad600,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_595 +counts_596 +counts_597 +counts_598 +counts_599 +counts_600+counts_601 +counts_602  , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_595 +counts_596 +counts_597 +counts_598 +counts_599 +counts_600+counts_601+counts_602  , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
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
