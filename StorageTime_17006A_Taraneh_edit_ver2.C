//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17006A.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17006A_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin605 = new TFile("outputTree_StorageTime_605.root","READ");
  TFile *fin606 = new TFile("outputTree_StorageTime_606.root","READ");
  TFile *fin607 = new TFile("outputTree_StorageTime_607.root","READ");
  TFile *fin608 = new TFile("outputTree_StorageTime_608.root","READ");
  TFile *fin609 = new TFile("outputTree_StorageTime_609.root","READ");
  TFile *fin610 = new TFile("outputTree_StorageTime_610.root","READ");
  TFile *fin611 = new TFile("outputTree_StorageTime_611.root","READ");
  TFile *fin612 = new TFile("outputTree_StorageTime_612.root","READ");
  TFile *fin613 = new TFile("outputTree_StorageTime_613.root","READ");


  
  TTree *outputTree605 = (TTree*) fin605 -> Get("cycle_info");
  TTree *outputTree606 = (TTree*) fin606 -> Get("cycle_info");
  TTree *outputTree607 = (TTree*) fin607 -> Get("cycle_info");
  TTree *outputTree608 = (TTree*) fin608 -> Get("cycle_info");
  TTree *outputTree609 = (TTree*) fin609 -> Get("cycle_info");
  TTree *outputTree610 = (TTree*) fin610 -> Get("cycle_info");
  TTree *outputTree611 = (TTree*) fin611 -> Get("cycle_info");
  TTree *outputTree612 = (TTree*) fin612 -> Get("cycle_info");
  TTree *outputTree613 = (TTree*) fin613 -> Get("cycle_info");
  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime605;
  double cycleDelayTime606;
  double cycleDelayTime607;
  double cycleDelayTime608;
  double cycleDelayTime609;
  double cycleDelayTime610;
  double cycleDelayTime611;
  double cycleDelayTime612;
  double cycleDelayTime613;




  outputTree605 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime605);
  outputTree606 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime606);
  outputTree607 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime607);
  outputTree608 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime608);
  outputTree609 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime609);
  outputTree610 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime610);
  outputTree611 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime611);
  outputTree612 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime612);
  outputTree613 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime613);



  // DELAY TIME (ARRAY)
  double delaytimeArray605 [100];
  double delaytimeArray606 [100];
  double delaytimeArray607 [100];
  double delaytimeArray608 [100];
  double delaytimeArray609 [100];
  double delaytimeArray610 [100];
  double delaytimeArray611 [100];
  double delaytimeArray612 [100];
  double delaytimeArray613 [100];


  // CYCLE NUMBER
  int cycleNumber605;
  int cycleNumber606;
  int cycleNumber607;
  int cycleNumber608;
  int cycleNumber609;
  int cycleNumber610;
  int cycleNumber611;
  int cycleNumber612;
  int cycleNumber613;


  outputTree605 -> SetBranchAddress ("cycleNumber" , &cycleNumber605);
  outputTree606 -> SetBranchAddress ("cycleNumber" , &cycleNumber606);
  outputTree607 -> SetBranchAddress ("cycleNumber" , &cycleNumber607);
  outputTree608 -> SetBranchAddress ("cycleNumber" , &cycleNumber608);
  outputTree609 -> SetBranchAddress ("cycleNumber" , &cycleNumber609);
  outputTree610 -> SetBranchAddress ("cycleNumber" , &cycleNumber610);
  outputTree611 -> SetBranchAddress ("cycleNumber" , &cycleNumber611);
  outputTree612 -> SetBranchAddress ("cycleNumber" , &cycleNumber612);
  outputTree613 -> SetBranchAddress ("cycleNumber" , &cycleNumber613);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray605 [100];
  double cycleNumberArray606 [100];
  double cycleNumberArray607 [100];
  double cycleNumberArray608 [100];
  double cycleNumberArray609 [100];
  double cycleNumberArray610 [100];
  double cycleNumberArray611 [100];
  double cycleNumberArray612 [100];
  double cycleNumberArray613 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral605;
  double UCNIntegral606;
  double UCNIntegral607;
  double UCNIntegral608;
  double UCNIntegral609;
  double UCNIntegral610;
  double UCNIntegral611;
  double UCNIntegral612;
  double UCNIntegral613;



  outputTree605 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral605);
  outputTree606 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral606);
  outputTree607 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral607);
  outputTree608 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral608);
  outputTree609 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral609);
  outputTree610 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral610);
  outputTree611 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral611);
  outputTree612 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral612);
  outputTree613 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral613);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray605 [100];
  double UCNIntegralArray606 [100];
  double UCNIntegralArray607 [100];
  double UCNIntegralArray608 [100];
  double UCNIntegralArray609 [100];
  double UCNIntegralArray610 [100];
  double UCNIntegralArray611 [100];
  double UCNIntegralArray612 [100];
  double UCNIntegralArray613 [100];


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr605;
  double UCNIntegralErr606;
  double UCNIntegralErr607;
  double UCNIntegralErr608;
  double UCNIntegralErr609;
  double UCNIntegralErr610;
  double UCNIntegralErr611;
  double UCNIntegralErr612;
  double UCNIntegralErr613;


  outputTree605 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr605);
  outputTree606 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr606);
  outputTree607 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr607);
  outputTree608 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr608);
  outputTree609 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr609);
  outputTree610 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr610);
  outputTree611 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr611);
  outputTree612 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr612);
  outputTree613 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr613);


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray605 [100];
  double UCNIntegralErrArray606 [100];
  double UCNIntegralErrArray607 [100];
  double UCNIntegralErrArray608 [100];
  double UCNIntegralErrArray609 [100];
  double UCNIntegralErrArray610 [100];
  double UCNIntegralErrArray611 [100];
  double UCNIntegralErrArray612 [100];
  double UCNIntegralErrArray613 [100];


  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral605;
  double HistIntegral606;
  double HistIntegral607;
  double HistIntegral608;
  double HistIntegral609;
  double HistIntegral610;
  double HistIntegral611;
  double HistIntegral612;
  double HistIntegral613;


  outputTree605 -> SetBranchAddress ("HistIntegral" , &HistIntegral605); 
  outputTree606 -> SetBranchAddress ("HistIntegral" , &HistIntegral606);
  outputTree607 -> SetBranchAddress ("HistIntegral" , &HistIntegral607);
  outputTree608 -> SetBranchAddress ("HistIntegral" , &HistIntegral608);
  outputTree609 -> SetBranchAddress ("HistIntegral" , &HistIntegral609);
  outputTree610 -> SetBranchAddress ("HistIntegral" , &HistIntegral610);
  outputTree611 -> SetBranchAddress ("HistIntegral" , &HistIntegral611);
  outputTree612 -> SetBranchAddress ("HistIntegral" , &HistIntegral612);
  outputTree613 -> SetBranchAddress ("HistIntegral" , &HistIntegral613);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray605 [100];
  double HistIntegralArray606 [100];
  double HistIntegralArray607 [100];
  double HistIntegralArray608 [100];
  double HistIntegralArray609 [100];
  double HistIntegralArray610 [100];
  double HistIntegralArray611 [100];
  double HistIntegralArray612 [100];
  double HistIntegralArray613 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr605;
  double HistIntegralErr606;
  double HistIntegralErr607;
  double HistIntegralErr608;
  double HistIntegralErr609;
  double HistIntegralErr610;
  double HistIntegralErr611;
  double HistIntegralErr612;
  double HistIntegralErr613;


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray605 [100];
  double HistIntegralErrArray606 [100];
  double HistIntegralErrArray607 [100];
  double HistIntegralErrArray608 [100];
  double HistIntegralErrArray609 [100];
  double HistIntegralErrArray610 [100];
  double HistIntegralErrArray611 [100];
  double HistIntegralErrArray612 [100];
  double HistIntegralErrArray613 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad605;
  double avets12Irrad606;
  double avets12Irrad607;
  double avets12Irrad608;
  double avets12Irrad609;
  double avets12Irrad610;
  double avets12Irrad611;
  double avets12Irrad612;
  double avets12Irrad613;

  outputTree605 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad605);
  outputTree606 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad606);
  outputTree607 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad607);
  outputTree608 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad608);
  outputTree609 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad609);
  outputTree610 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad610);
  outputTree611 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad611);
  outputTree612 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad612);
  outputTree613 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad613);



  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen605;
  double avets12ValveOpen606;
  double avets12ValveOpen607;
  double avets12ValveOpen608;
  double avets12ValveOpen609;
  double avets12ValveOpen610;
  double avets12ValveOpen611;
  double avets12ValveOpen612;
  double avets12ValveOpen613;


  outputTree605 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen605);
  outputTree606 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen606);
  outputTree607 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen607);
  outputTree608 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen608);
  outputTree609 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen609);
  outputTree610 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen610);
  outputTree611 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen611);
  outputTree612 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen612);
  outputTree613 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen613);


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray605 [100];
  double avets12IrradArray606 [100];
  double avets12IrradArray607 [100];
  double avets12IrradArray608 [100];
  double avets12IrradArray609 [100];
  double avets12IrradArray610 [100];
  double avets12IrradArray611 [100];
  double avets12IrradArray612 [100];
  double avets12IrradArray613 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray605 [100];
  double avets12ValveOpenArray606 [100];
  double avets12ValveOpenArray607 [100];
  double avets12ValveOpenArray608 [100];
  double avets12ValveOpenArray609 [100];
  double avets12ValveOpenArray610 [100];
  double avets12ValveOpenArray611 [100];
  double avets12ValveOpenArray612 [100];
  double avets12ValveOpenArray613 [100];


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad605;
  double maxts12Irrad606;
  double maxts12Irrad607;
  double maxts12Irrad608;
  double maxts12Irrad609;
  double maxts12Irrad610;
  double maxts12Irrad611;
  double maxts12Irrad612;
  double maxts12Irrad613;

  outputTree605 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad605);
  outputTree606 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad606);
  outputTree607 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad607);
  outputTree608 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad608);
  outputTree609 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad609);
  outputTree610 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad610);
  outputTree611 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad611);
  outputTree612 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad612);
  outputTree613 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad613);


 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen605;
  double maxts12ValveOpen606;
  double maxts12ValveOpen607;
  double maxts12ValveOpen608;
  double maxts12ValveOpen609;
  double maxts12ValveOpen610;
  double maxts12ValveOpen611;
  double maxts12ValveOpen612;
  double maxts12ValveOpen613;


  outputTree605 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen605);
  outputTree606 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen606);
  outputTree607 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen607);
  outputTree608 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen608);
  outputTree609 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen609);
  outputTree610 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen610);
  outputTree611 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen611);
  outputTree612 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen612);
  outputTree613 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen613);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray605 [100];
  double maxts12IrradArray606 [100];
  double maxts12IrradArray607 [100];
  double maxts12IrradArray608 [100];
  double maxts12IrradArray609 [100];
  double maxts12IrradArray610 [100];
  double maxts12IrradArray611 [100];
  double maxts12IrradArray612 [100];
  double maxts12IrradArray613 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray605 [100];
  double maxts12ValveOpenArray606 [100];
  double maxts12ValveOpenArray607 [100];
  double maxts12ValveOpenArray608 [100];
  double maxts12ValveOpenArray609 [100];
  double maxts12ValveOpenArray610 [100];
  double maxts12ValveOpenArray611 [100];
  double maxts12ValveOpenArray612 [100];
  double maxts12ValveOpenArray613 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad605;
  double mints12Irrad606;
  double mints12Irrad607;
  double mints12Irrad608;
  double mints12Irrad609;
  double mints12Irrad610;
  double mints12Irrad611;
  double mints12Irrad612;
  double mints12Irrad613;


  outputTree605 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad605);
  outputTree606 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad606);
  outputTree607 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad607);
  outputTree608 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad608);
  outputTree609 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad609);
  outputTree610 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad610);
  outputTree611 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad611);
  outputTree612 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad612);
  outputTree613 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad613);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen605;
  double mints12ValveOpen606;
  double mints12ValveOpen607;
  double mints12ValveOpen608;
  double mints12ValveOpen609;
  double mints12ValveOpen610;
  double mints12ValveOpen611;
  double mints12ValveOpen612;
  double mints12ValveOpen613;
  
  outputTree605 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen605);
  outputTree606 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen606);
  outputTree607 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen607);
  outputTree608 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen608);
  outputTree609 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen609);
  outputTree610 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen610);
  outputTree611 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen611);
  outputTree612 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen612);
  outputTree613 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen613);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray605 [100];
  double mints12IrradArray606 [100];
  double mints12IrradArray607 [100];
  double mints12IrradArray608 [100];
  double mints12IrradArray609 [100];
  double mints12IrradArray610 [100];
  double mints12IrradArray611 [100];
  double mints12IrradArray612 [100];
  double mints12IrradArray613 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray605 [100];
  double mints12ValveOpenArray606 [100];
  double mints12ValveOpenArray607 [100];
  double mints12ValveOpenArray608 [100];
  double mints12ValveOpenArray609 [100];
  double mints12ValveOpenArray610 [100];
  double mints12ValveOpenArray611 [100];
  double mints12ValveOpenArray612 [100];
  double mints12ValveOpenArray613 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr605 [100];
  double ts12IrradErr606 [100];
  double ts12IrradErr607 [100];
  double ts12IrradErr608 [100];
  double ts12IrradErr609 [100];
  double ts12IrradErr610 [100];
  double ts12IrradErr611 [100];
  double ts12IrradErr612 [100];
  double ts12IrradErr613 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr605 [100];
  double ts12ValveOpenErr606 [100];
  double ts12ValveOpenErr607 [100];
  double ts12ValveOpenErr608 [100];
  double ts12ValveOpenErr609 [100];
  double ts12ValveOpenErr610 [100];
  double ts12ValveOpenErr611 [100];
  double ts12ValveOpenErr612 [100];
  double ts12ValveOpenErr613 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur605;
  double avecur606;
  double avecur607;
  double avecur608;
  double avecur609;
  double avecur610;
  double avecur611;
  double avecur612;
  double avecur613;

  outputTree605 -> SetBranchAddress ("AVE_PRDCUR" , &avecur605);
  outputTree606 -> SetBranchAddress ("AVE_PRDCUR" , &avecur606);
  outputTree607 -> SetBranchAddress ("AVE_PRDCUR" , &avecur607);
  outputTree608 -> SetBranchAddress ("AVE_PRDCUR" , &avecur608);
  outputTree609 -> SetBranchAddress ("AVE_PRDCUR" , &avecur609);
  outputTree610 -> SetBranchAddress ("AVE_PRDCUR" , &avecur610);
  outputTree611 -> SetBranchAddress ("AVE_PRDCUR" , &avecur611);
  outputTree612 -> SetBranchAddress ("AVE_PRDCUR" , &avecur612);
  outputTree613 -> SetBranchAddress ("AVE_PRDCUR" , &avecur613);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray605 [100];
  double avecurArray606 [100];
  double avecurArray607 [100];
  double avecurArray608 [100];
  double avecurArray609 [100];
  double avecurArray610 [100];
  double avecurArray611 [100];
  double avecurArray612 [100];
  double avecurArray613 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur605;
  double maxcur606;
  double maxcur607;
  double maxcur608;
  double maxcur609;
  double maxcur610;
  double maxcur611;
  double maxcur612;
  double maxcur613;

  outputTree605 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur605);
  outputTree606 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur606);
  outputTree607 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur607);
  outputTree608 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur608);
  outputTree609 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur609);
  outputTree610 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur610);
  outputTree611 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur611);
  outputTree612 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur612);
  outputTree613 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur613);

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray605 [100];
  double maxcurArray606 [100];
  double maxcurArray607 [100];
  double maxcurArray608 [100];
  double maxcurArray609 [100];
  double maxcurArray610 [100];
  double maxcurArray611 [100];
  double maxcurArray612 [100];
  double maxcurArray613 [100];

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur605;
  double mincur606;
  double mincur607;
  double mincur608;
  double mincur609;
  double mincur610;
  double mincur611;
  double mincur612;
  double mincur613;

  outputTree605 -> SetBranchAddress ("MIN_PRDCUR" , &mincur605);
  outputTree606 -> SetBranchAddress ("MIN_PRDCUR" , &mincur606);
  outputTree607 -> SetBranchAddress ("MIN_PRDCUR" , &mincur607);
  outputTree608 -> SetBranchAddress ("MIN_PRDCUR" , &mincur608);
  outputTree609 -> SetBranchAddress ("MIN_PRDCUR" , &mincur609);
  outputTree610 -> SetBranchAddress ("MIN_PRDCUR" , &mincur610);
  outputTree611 -> SetBranchAddress ("MIN_PRDCUR" , &mincur611);
  outputTree612 -> SetBranchAddress ("MIN_PRDCUR" , &mincur612);
  outputTree613 -> SetBranchAddress ("MIN_PRDCUR" , &mincur613);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray605 [100];
  double mincurArray606 [100];
  double mincurArray607 [100];
  double mincurArray608 [100];
  double mincurArray609 [100];
  double mincurArray610 [100];
  double mincurArray611 [100];
  double mincurArray612 [100];
  double mincurArray613 [100];

  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray605 [100];
  double ErrcurArray606 [100];
  double ErrcurArray607 [100];
  double ErrcurArray608 [100];
  double ErrcurArray609 [100];
  double ErrcurArray610 [100];
  double ErrcurArray611 [100];
  double ErrcurArray612 [100];
  double ErrcurArray613 [100];

  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline605;
  double Baseline606;
  double Baseline607;
  double Baseline608;
  double Baseline609;
  double Baseline610;
  double Baseline611;
  double Baseline612;
  double Baseline613;

  outputTree605 -> SetBranchAddress ("Baseline" , &Baseline605);
  outputTree606 -> SetBranchAddress ("Baseline" , &Baseline606);
  outputTree607 -> SetBranchAddress ("Baseline" , &Baseline607);
  outputTree608 -> SetBranchAddress ("Baseline" , &Baseline608);
  outputTree609 -> SetBranchAddress ("Baseline" , &Baseline609);
  outputTree610 -> SetBranchAddress ("Baseline" , &Baseline610);
  outputTree611 -> SetBranchAddress ("Baseline" , &Baseline611);
  outputTree612 -> SetBranchAddress ("Baseline" , &Baseline612);
  outputTree613 -> SetBranchAddress ("Baseline" , &Baseline613);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray605 [100];
  double BaselineArray606 [100];
  double BaselineArray607 [100];
  double BaselineArray608 [100];
  double BaselineArray609 [100];
  double BaselineArray610 [100];
  double BaselineArray611 [100];
  double BaselineArray612 [100];
  double BaselineArray613 [100];

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr605;
  double BaselineErr606;
  double BaselineErr607;
  double BaselineErr608;
  double BaselineErr609;
  double BaselineErr610;
  double BaselineErr611;
  double BaselineErr612;
  double BaselineErr613;
 
  outputTree605 -> SetBranchAddress ("BaselineErr" , &BaselineErr605);
  outputTree606 -> SetBranchAddress ("BaselineErr" , &BaselineErr606);
  outputTree607 -> SetBranchAddress ("BaselineErr" , &BaselineErr607);
  outputTree608 -> SetBranchAddress ("BaselineErr" , &BaselineErr608);
  outputTree609 -> SetBranchAddress ("BaselineErr" , &BaselineErr609);
  outputTree610 -> SetBranchAddress ("BaselineErr" , &BaselineErr610);
  outputTree611 -> SetBranchAddress ("BaselineErr" , &BaselineErr611);
  outputTree612 -> SetBranchAddress ("BaselineErr" , &BaselineErr612);
  outputTree613 -> SetBranchAddress ("BaselineErr" , &BaselineErr613);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray605 [100];
  double BaselineErrArray606 [100];
  double BaselineErrArray607 [100];
  double BaselineErrArray608 [100];
  double BaselineErrArray609 [100];
  double BaselineErrArray610 [100];
  double BaselineErrArray611 [100];
  double BaselineErrArray612 [100];
  double BaselineErrArray613 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad605;
  double BaselineIrrad606;
  double BaselineIrrad607;
  double BaselineIrrad608;
  double BaselineIrrad609;
  double BaselineIrrad610;
  double BaselineIrrad611;
  double BaselineIrrad612;
  double BaselineIrrad613;
 
  outputTree605 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad605);
  outputTree606 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad606);
  outputTree607 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad607);
  outputTree608 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad608);
  outputTree609 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad609);
  outputTree610 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad610);
  outputTree611 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad611);
  outputTree612 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad612);
  outputTree613 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad613);

  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray605 [100];
  double BaselineIrradArray606 [100];
  double BaselineIrradArray607 [100];
  double BaselineIrradArray608 [100];
  double BaselineIrradArray609 [100];
  double BaselineIrradArray610 [100];
  double BaselineIrradArray611 [100];
  double BaselineIrradArray612 [100];
  double BaselineIrradArray613 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr605;
  double BaselineIrradErr606;
  double BaselineIrradErr607;
  double BaselineIrradErr608;
  double BaselineIrradErr609;
  double BaselineIrradErr610;
  double BaselineIrradErr611;
  double BaselineIrradErr612;
  double BaselineIrradErr613;

  outputTree605 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr605);
  outputTree606 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr606);
  outputTree607 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr607);
  outputTree608 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr608);
  outputTree609 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr609);
  outputTree610 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr610);
  outputTree611 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr611);
  outputTree612 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr612);
  outputTree613 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr613);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray605 [100];
  double BaselineIrradErrArray606 [100];
  double BaselineIrradErrArray607 [100];
  double BaselineIrradErrArray608 [100];
  double BaselineIrradErrArray609 [100];
  double BaselineIrradErrArray610 [100];
  double BaselineIrradErrArray611 [100];
  double BaselineIrradErrArray612 [100];
  double BaselineIrradErrArray613 [100];

  // FALL TIME FROM THE UCN RATE FIT
  double FallTime605;
  double FallTime606;
  double FallTime607;
  double FallTime608;
  double FallTime609;
  double FallTime610;
  double FallTime611;
  double FallTime612;
  double FallTime613;

  outputTree605 -> SetBranchAddress ("FallTime" , &FallTime605);
  outputTree606 -> SetBranchAddress ("FallTime" , &FallTime606);
  outputTree607 -> SetBranchAddress ("FallTime" , &FallTime607);
  outputTree608 -> SetBranchAddress ("FallTime" , &FallTime608);
  outputTree609 -> SetBranchAddress ("FallTime" , &FallTime609);
  outputTree610 -> SetBranchAddress ("FallTime" , &FallTime610);
  outputTree611 -> SetBranchAddress ("FallTime" , &FallTime611);
  outputTree612 -> SetBranchAddress ("FallTime" , &FallTime612);
  outputTree613 -> SetBranchAddress ("FallTime" , &FallTime613);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray605 [100];
  double FallTimeArray606 [100];
  double FallTimeArray607 [100];
  double FallTimeArray608 [100];
  double FallTimeArray609 [100];
  double FallTimeArray610 [100];
  double FallTimeArray611 [100];
  double FallTimeArray612 [100];
  double FallTimeArray613 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr605;
  double FallTimeErr606;
  double FallTimeErr607;
  double FallTimeErr608;
  double FallTimeErr609;
  double FallTimeErr610;
  double FallTimeErr611;
  double FallTimeErr612;
  double FallTimeErr613;

  outputTree605 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr605);
  outputTree606 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr606);
  outputTree607 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr607);
  outputTree608 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr608);
  outputTree609 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr609);
  outputTree610 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr610);
  outputTree611 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr611);
  outputTree612 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr612);
  outputTree613 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr613);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray605 [100];
  double FallTimeErrArray606 [100];
  double FallTimeErrArray607 [100];
  double FallTimeErrArray608 [100];
  double FallTimeErrArray609 [100];
  double FallTimeErrArray610 [100];
  double FallTimeErrArray611 [100];
  double FallTimeErrArray612 [100];
  double FallTimeErrArray613 [100];
  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime605;
  double RiseTime606;
  double RiseTime607;
  double RiseTime608;
  double RiseTime609;
  double RiseTime610;
  double RiseTime611;
  double RiseTime612;
  double RiseTime613;

  outputTree605 -> SetBranchAddress ("RiseTime" , &RiseTime605);
  outputTree606 -> SetBranchAddress ("RiseTime" , &RiseTime606);
  outputTree607 -> SetBranchAddress ("RiseTime" , &RiseTime607);
  outputTree608 -> SetBranchAddress ("RiseTime" , &RiseTime608);
  outputTree609 -> SetBranchAddress ("RiseTime" , &RiseTime609);
  outputTree610 -> SetBranchAddress ("RiseTime" , &RiseTime610);
  outputTree611 -> SetBranchAddress ("RiseTime" , &RiseTime611);
  outputTree612 -> SetBranchAddress ("RiseTime" , &RiseTime612);
  outputTree613 -> SetBranchAddress ("RiseTime" , &RiseTime613);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray605 [100];
  double RiseTimeArray606 [100];
  double RiseTimeArray607 [100];
  double RiseTimeArray608 [100];
  double RiseTimeArray609 [100];
  double RiseTimeArray610 [100];
  double RiseTimeArray611 [100];
  double RiseTimeArray612 [100];
  double RiseTimeArray613 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr605;
  double RiseTimeErr606;
  double RiseTimeErr607;
  double RiseTimeErr608;
  double RiseTimeErr609;
  double RiseTimeErr610;
  double RiseTimeErr611;
  double RiseTimeErr612;
  double RiseTimeErr613;

  outputTree605 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr605);
  outputTree606 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr606);
  outputTree607 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr607);
  outputTree608 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr608);
  outputTree609 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr609);
  outputTree610 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr610);
  outputTree611 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr611);
  outputTree612 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr612);
  outputTree613 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr613);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray605 [100];
  double RiseTimeErrArray606 [100];
  double RiseTimeErrArray607 [100];
  double RiseTimeErrArray608 [100];
  double RiseTimeErrArray609 [100];
  double RiseTimeErrArray610 [100];
  double RiseTimeErrArray611 [100];
  double RiseTimeErrArray612 [100];
  double RiseTimeErrArray613 [100];


  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad605;
  double aveAllts12Irrad606;
  double aveAllts12Irrad607;
  double aveAllts12Irrad608;
  double aveAllts12Irrad609;
  double aveAllts12Irrad610;
  double aveAllts12Irrad611;
  double aveAllts12Irrad612;
  double aveAllts12Irrad613;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad605;
  double aveAllErrts12Irrad606;
  double aveAllErrts12Irrad607;
  double aveAllErrts12Irrad608;
  double aveAllErrts12Irrad609;
  double aveAllErrts12Irrad610;
  double aveAllErrts12Irrad611;
  double aveAllErrts12Irrad612;
  double aveAllErrts12Irrad613;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad605;
  double maxAllts12Irrad606;
  double maxAllts12Irrad607;
  double maxAllts12Irrad608;
  double maxAllts12Irrad609;
  double maxAllts12Irrad610;
  double maxAllts12Irrad611;
  double maxAllts12Irrad612;
  double maxAllts12Irrad613;
  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad605;
  double minAllts12Irrad606;
  double minAllts12Irrad607;
  double minAllts12Irrad608;
  double minAllts12Irrad609;
  double minAllts12Irrad610;
  double minAllts12Irrad611;
  double minAllts12Irrad612;
  double minAllts12Irrad613;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage605;
  double storage606;
  double storage607;
  double storage608;
  double storage609;
  double storage610;
  double storage611;
  double storage612;
  double storage613;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr605;
  double storageErr606;
  double storageErr607;
  double storageErr608;
  double storageErr609;
  double storageErr610;
  double storageErr611;
  double storageErr612;
  double storageErr613;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_605 = 0;
  int counts_606 = 0;
  int counts_607 = 0;
  int counts_608 = 0;
  int counts_609 = 0;
  int counts_610 = 0;
  int counts_611 = 0;
  int counts_612 = 0;
  int counts_613 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events605;
  events605 = (Double_t)outputTree605 -> GetEntries();

  for (ULong64_t j = 0 ; j < events605 ; j++){
    outputTree605 -> GetEvent(j);
    if (j == 2)
      continue;
    UCNIntegralArray605[counts_605] = UCNIntegral605;
    UCNIntegralErrArray605[counts_605] = UCNIntegralErr605/2;
    HistIntegralArray605[counts_605] = HistIntegral605;
    HistIntegralErrArray605[counts_605] = sqrt (HistIntegral605)/2;
    avets12IrradArray605[counts_605] = avets12Irrad605;
    avets12ValveOpenArray605[counts_605] = avets12ValveOpen605;
    maxts12IrradArray605[counts_605] = maxts12Irrad605;
    maxts12ValveOpenArray605[counts_605] = maxts12ValveOpen605;
    mints12IrradArray605[counts_605] = mints12Irrad605; 
    mints12ValveOpenArray605[counts_605] = mints12ValveOpen605;
    ts12IrradErr605[counts_605] = (maxts12Irrad605 - mints12Irrad605)/2;
    ts12ValveOpenErr605[counts_605] = (maxts12ValveOpen605 - mints12ValveOpen605)/2;
    avecurArray605[counts_605] = avecur605;
    maxcurArray605[counts_605] = maxcur605;
    mincurArray605[counts_605] = mincur605;
    ErrcurArray605[counts_605] = (maxcur605 - mincur605)/2;
    delaytimeArray605[counts_605] = cycleDelayTime605;
    cycleNumberArray605[counts_605] = cycleNumber605;
    BaselineArray605[counts_605] = Baseline605;
    BaselineIrradArray605[counts_605] = BaselineIrrad605;
    BaselineIrradErrArray605[counts_605] = BaselineIrradErr605/2;
    FallTimeArray605[counts_605] = FallTime605;
    FallTimeErrArray605[counts_605] = FallTimeErr605/2;
    RiseTimeArray605[counts_605] = RiseTime605;
    RiseTimeErrArray605[counts_605] = RiseTimeErr605/2;
    aveAllts12Irrad605 += avets12Irrad605;
    maxAllts12Irrad605 += maxts12Irrad605;
    minAllts12Irrad605 += mints12Irrad605;
    UCNIntegralArrayAll[counts_605] = UCNIntegral605;
    UCNIntegralErrArrayAll[counts_605] = UCNIntegralErr605/2;
    delayTimeAll[counts_605] = cycleDelayTime605;
    HistIntegralArrayAll[counts_605] = HistIntegral605;
    HistIntegralErrArrayAll[counts_605] = sqrt (HistIntegral605)/2;
    counts_605++;
  }
  aveAllts12Irrad605 = aveAllts12Irrad605/counts_605;
  maxAllts12Irrad605 = maxAllts12Irrad605/counts_605;
  minAllts12Irrad605 = minAllts12Irrad605/counts_605;
  aveAllErrts12Irrad605 = (maxAllts12Irrad605 - minAllts12Irrad605)/2;

  ULong64_t events606;
  events606 = (Double_t)outputTree606 -> GetEntries();

  for (ULong64_t j = 0 ; j < events606 ; j++){
    outputTree606 -> GetEvent(j);
    UCNIntegralArray606[j] = UCNIntegral606;
    UCNIntegralErrArray606[j] = UCNIntegralErr606/2;
    HistIntegralArray606[j] = HistIntegral606;
    HistIntegralErrArray606[j] = sqrt (HistIntegral606)/2;
    avets12IrradArray606[j] = avets12Irrad606;
    avets12ValveOpenArray606[j] = avets12ValveOpen606;
    maxts12IrradArray606[j] = maxts12Irrad606;
    maxts12ValveOpenArray606[j] = maxts12ValveOpen606;
    mints12IrradArray606[j] = mints12Irrad606; 
    mints12ValveOpenArray606[j] = mints12ValveOpen606;
    ts12IrradErr606[j] = (maxts12Irrad606 - mints12Irrad606)/2;
    ts12ValveOpenErr606[j] = (maxts12ValveOpen606 - mints12ValveOpen606)/2;
    avecurArray606[j] = avecur606;
    maxcurArray606[j] = maxcur606;
    mincurArray606[j] = mincur606;
    ErrcurArray606[j] = (maxcur606 - mincur606)/2;
    delaytimeArray606[j] = cycleDelayTime606;
    cycleNumberArray606[j] = cycleNumber606;
    BaselineArray606[j] = Baseline606;
    BaselineIrradArray606[j] = BaselineIrrad606;
    BaselineIrradErrArray606[j] = BaselineIrradErr606/2;
    FallTimeArray606[j] = FallTime606;
    FallTimeErrArray606[j] = FallTimeErr606/2;
    RiseTimeArray606[j] = RiseTime606;
    RiseTimeErrArray606[j] = RiseTimeErr606/2;
    aveAllts12Irrad606 += avets12Irrad606;
    maxAllts12Irrad606 += maxts12Irrad606;
    minAllts12Irrad606 += mints12Irrad606;
    //cout << aveAllts12Irrad606 << endl;
    UCNIntegralArrayAll[counts_605+ counts_606] = UCNIntegral606;
    UCNIntegralErrArrayAll[counts_605+ counts_606] = UCNIntegralErr606/2;
    delayTimeAll[counts_605+ counts_606] = cycleDelayTime606;
    HistIntegralArrayAll[counts_605 + counts_606] = HistIntegral606;
    HistIntegralErrArrayAll[counts_605+counts_606] = sqrt (HistIntegral606)/2;
    counts_606++;
  }
  aveAllts12Irrad606 = aveAllts12Irrad606/counts_606;
  maxAllts12Irrad606 = maxAllts12Irrad606/counts_606;
  minAllts12Irrad606 = minAllts12Irrad606/counts_606;
  aveAllErrts12Irrad606 = (maxAllts12Irrad606 - minAllts12Irrad606)/2;

  ULong64_t events607;
  events607 = (Double_t)outputTree607 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events607 ; j++){
    outputTree607 -> GetEvent(j);
    UCNIntegralArray607[counts_607] = UCNIntegral607;
    UCNIntegralErrArray607[counts_607] = UCNIntegralErr607/2;
    HistIntegralArray607[counts_607] = HistIntegral607;
    HistIntegralErrArray607[counts_607] = sqrt (HistIntegral607)/2;
    avets12IrradArray607[counts_607] = avets12Irrad607;
    avets12ValveOpenArray607[counts_607] = avets12ValveOpen607;
    maxts12IrradArray607[counts_607] = maxts12Irrad607;
    maxts12ValveOpenArray607[counts_607] = maxts12ValveOpen607;
    mints12IrradArray607[counts_607] = mints12Irrad607; 
    mints12ValveOpenArray607[counts_607] = mints12ValveOpen607;
    ts12IrradErr607[counts_607] = (maxts12Irrad607 - mints12Irrad607)/2;
    ts12ValveOpenErr607[counts_607] =( maxts12ValveOpen607 - mints12ValveOpen607)/2;
    avecurArray607[counts_607] = avecur607;
    maxcurArray607[counts_607] = maxcur607;
    mincurArray607[counts_607] = mincur607;
    ErrcurArray607[counts_607] = (maxcur607 - mincur607)/2;
    delaytimeArray607[counts_607] = cycleDelayTime607;
    cycleNumberArray607[counts_607] = cycleNumber607;
    BaselineArray607[counts_607] = Baseline607;
    BaselineIrradArray607[counts_607] = BaselineIrrad607;
    BaselineIrradErrArray607[counts_607] = BaselineIrradErr607/2;
    FallTimeArray607[counts_607] = FallTime607;
    FallTimeErrArray607[counts_607] = FallTimeErr607/2;
    RiseTimeArray607[counts_607] = RiseTime607;
    RiseTimeErrArray607[counts_607] = RiseTimeErr607/2;
    aveAllts12Irrad607 += avets12Irrad607;
    maxAllts12Irrad607 += maxts12Irrad607;
    minAllts12Irrad607 += mints12Irrad607;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607] = UCNIntegral607;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607] = UCNIntegralErr607/2;
    delayTimeAll[counts_605+ counts_606+counts_607] = cycleDelayTime607;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607] = HistIntegral607;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607] = sqrt (HistIntegral607)/2;
    counts_607++;
  }
  aveAllts12Irrad607 = aveAllts12Irrad607/counts_607;
  maxAllts12Irrad607 = maxAllts12Irrad607/counts_607;
  minAllts12Irrad607 = minAllts12Irrad607/counts_607;
  aveAllErrts12Irrad607 = (maxAllts12Irrad607 - minAllts12Irrad607)/2;
  
  ULong64_t events608;
  events608 = (Double_t)outputTree608 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events608 ; j++){
    outputTree608 -> GetEvent(j);
    UCNIntegralArray608[j] = UCNIntegral608;
    UCNIntegralErrArray608[j] = UCNIntegralErr608/2;
    HistIntegralArray608[j] = HistIntegral608;
    HistIntegralErrArray608[j] = sqrt (HistIntegral608)/2;
    avets12IrradArray608[j] = avets12Irrad608;
    avets12ValveOpenArray608[j] = avets12ValveOpen608;
    maxts12IrradArray608[j] = maxts12Irrad608;
    maxts12ValveOpenArray608[j] = maxts12ValveOpen608;
    mints12IrradArray608[j] = mints12Irrad608; 
    mints12ValveOpenArray608[j] = mints12ValveOpen608;
    ts12IrradErr608[j] = (maxts12Irrad608 - mints12Irrad608)/2;
    ts12ValveOpenErr608[j] = (maxts12ValveOpen608 - mints12ValveOpen608)/2;
    avecurArray608[j] = avecur608;
    maxcurArray608[j] = maxcur608;
    mincurArray608[j] = mincur608;
    ErrcurArray608[j] = (maxcur608 - mincur608)/2;
    delaytimeArray608[j] = cycleDelayTime608;
    cycleNumberArray608[j] = cycleNumber608;
    BaselineArray608[j] = Baseline608;
    BaselineIrradArray608[j] = BaselineIrrad608;
    BaselineIrradErrArray608[j] = BaselineIrradErr608/2;
    FallTimeArray608[j] = FallTime608;
    FallTimeErrArray608[j] = FallTimeErr608/2;
    RiseTimeArray608[j] = RiseTime608;
    RiseTimeErrArray608[j] = RiseTimeErr608/2;
    aveAllts12Irrad608 += avets12Irrad608;
    maxAllts12Irrad608 += maxts12Irrad608;
    minAllts12Irrad608 += mints12Irrad608;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608] = UCNIntegral608;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608] = UCNIntegralErr608/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608] = cycleDelayTime608;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608] = HistIntegral608;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608] = sqrt (HistIntegral608)/2;
    counts_608++;
  }
  aveAllts12Irrad608 = aveAllts12Irrad608/counts_608;
  maxAllts12Irrad608 = maxAllts12Irrad608/counts_608;
  minAllts12Irrad608 = minAllts12Irrad608/counts_608;
  aveAllErrts12Irrad608 = (maxAllts12Irrad608 - minAllts12Irrad608)/2;
  
  ULong64_t events609;
  events609 = (Double_t)outputTree609 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events609 ; j++){
    outputTree609 -> GetEvent(j);
    UCNIntegralArray609[counts_609] = UCNIntegral609;
    UCNIntegralErrArray609[counts_609] = UCNIntegralErr609/2;
    HistIntegralArray609[counts_609] = HistIntegral609;
    HistIntegralErrArray609[counts_609] = sqrt (HistIntegral609)/2;
    avets12IrradArray609[counts_609] = avets12Irrad609;
    avets12ValveOpenArray609[counts_609] = avets12ValveOpen609;
    maxts12IrradArray609[counts_609] = maxts12Irrad609;
    maxts12ValveOpenArray609[counts_609] = maxts12ValveOpen609;
    mints12IrradArray609[counts_609] = mints12Irrad609; 
    mints12ValveOpenArray609[counts_609] = mints12ValveOpen609;
    ts12IrradErr609[counts_609] = (maxts12Irrad609 - mints12Irrad609)/2;
    ts12ValveOpenErr609[counts_609] =( maxts12ValveOpen609 - mints12ValveOpen609)/2;
    avecurArray609[counts_609] = avecur609;
    maxcurArray609[counts_609] = maxcur609;
    mincurArray609[counts_609] = mincur609;
    ErrcurArray609[counts_609] = (maxcur609 - mincur609)/2;
    delaytimeArray609[counts_609] = cycleDelayTime609;
    cycleNumberArray609[counts_609] = cycleNumber609;
    BaselineArray609[counts_609] = Baseline609;
    BaselineIrradArray609[counts_609] = BaselineIrrad609;
    BaselineIrradErrArray609[counts_609] = BaselineIrradErr609/2;
    FallTimeArray609[counts_609] = FallTime609;
    FallTimeErrArray609[counts_609] = FallTimeErr609/2;
    RiseTimeArray609[counts_609] = RiseTime609;
    RiseTimeErrArray609[counts_609] = RiseTimeErr609/2;
    aveAllts12Irrad609 += avets12Irrad609;
    maxAllts12Irrad609 += maxts12Irrad609;
    minAllts12Irrad609 += mints12Irrad609;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609] = UCNIntegral609;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609] = UCNIntegralErr609/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608+ counts_609] = cycleDelayTime609;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608+counts_609] = HistIntegral609;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608+counts_609] = sqrt (HistIntegral609)/2;
    counts_609++;
  }
  aveAllts12Irrad609 = aveAllts12Irrad609/counts_609;
  maxAllts12Irrad609 = maxAllts12Irrad609/counts_609;
  minAllts12Irrad609 = minAllts12Irrad609/counts_609;
  aveAllErrts12Irrad609 = (maxAllts12Irrad609 - minAllts12Irrad609)/2;
  
  ULong64_t events610;
  events610 = (Double_t)outputTree610 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events610 ; j++){
    outputTree610 -> GetEvent(j);
    if (j == 0)
      continue;
    UCNIntegralArray610[counts_610] = UCNIntegral610;
    UCNIntegralErrArray610[counts_610] = UCNIntegralErr610/2;
    HistIntegralArray610[counts_610] = HistIntegral610;
    HistIntegralErrArray610[counts_610] = sqrt (HistIntegral610)/2;
    avets12IrradArray610[counts_610] = avets12Irrad610;
    avets12ValveOpenArray610[counts_610] = avets12ValveOpen610;
    maxts12IrradArray610[counts_610] = maxts12Irrad610;
    maxts12ValveOpenArray610[counts_610] = maxts12ValveOpen610;
    mints12IrradArray610[counts_610] = mints12Irrad610; 
    mints12ValveOpenArray610[counts_610] = mints12ValveOpen610;
    ts12IrradErr610[counts_610] = (maxts12Irrad610 - mints12Irrad610)/2;
    ts12ValveOpenErr610[counts_610] = (maxts12ValveOpen610 - mints12ValveOpen610)/2;
    avecurArray610[counts_610] = avecur610;
    maxcurArray610[counts_610] = maxcur610;
    mincurArray610[counts_610] = mincur610;
    ErrcurArray610[counts_610] = (maxcur610 - mincur610)/2;
    delaytimeArray610[counts_610] = cycleDelayTime610;
    cycleNumberArray610[counts_610] = cycleNumber610;
    BaselineArray610[counts_610] = Baseline610;
    BaselineIrradArray610[counts_610] = BaselineIrrad610;
    BaselineIrradErrArray610[counts_610] = BaselineIrradErr610/2;
    FallTimeArray610[counts_610] = FallTime610;
    FallTimeErrArray610[counts_610] = FallTimeErr610/2;
    RiseTimeArray610[counts_610] = RiseTime610;
    RiseTimeErrArray610[counts_610] = RiseTimeErr610/2;
    aveAllts12Irrad610 += avets12Irrad610;
    maxAllts12Irrad610 += maxts12Irrad610;
    minAllts12Irrad610 += mints12Irrad610;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609 + counts_610] = UCNIntegral610;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609+counts_610] = UCNIntegralErr610/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608+ counts_609+counts_610] = cycleDelayTime610;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608+counts_609+counts_610] = HistIntegral610;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608+counts_609+counts_610] = sqrt (HistIntegral610)/2;
    counts_610++;
  }
  aveAllts12Irrad610 = aveAllts12Irrad610/counts_610;
  maxAllts12Irrad610 = maxAllts12Irrad610/counts_610;
  minAllts12Irrad610 = minAllts12Irrad610/counts_610;
  aveAllErrts12Irrad610 = (maxAllts12Irrad610 - minAllts12Irrad610)/2;




  ULong64_t events611;
  events611 = (Double_t)outputTree611 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events611 ; j++){
    outputTree611 -> GetEvent(j);
    UCNIntegralArray611[counts_611] = UCNIntegral611;
    UCNIntegralErrArray611[counts_611] = UCNIntegralErr611/2;
    HistIntegralArray611[counts_611] = HistIntegral611;
    HistIntegralErrArray611[counts_611] = sqrt (HistIntegral611)/2;
    avets12IrradArray611[counts_611] = avets12Irrad611;
    avets12ValveOpenArray611[counts_611] = avets12ValveOpen611;
    maxts12IrradArray611[counts_611] = maxts12Irrad611;
    maxts12ValveOpenArray611[counts_611] = maxts12ValveOpen611;
    mints12IrradArray611[counts_611] = mints12Irrad611; 
    mints12ValveOpenArray611[counts_611] = mints12ValveOpen611;
    ts12IrradErr611[counts_611] = (maxts12Irrad611 - mints12Irrad611)/2;
    ts12ValveOpenErr611[counts_611] =( maxts12ValveOpen611 - mints12ValveOpen611)/2;
    avecurArray611[counts_611] = avecur611;
    maxcurArray611[counts_611] = maxcur611;
    mincurArray611[counts_611] = mincur611;
    ErrcurArray611[counts_611] = (maxcur611 - mincur611)/2;
    delaytimeArray611[counts_611] = cycleDelayTime611;
    cycleNumberArray611[counts_611] = cycleNumber611;
    BaselineArray611[counts_611] = Baseline611;
    BaselineIrradArray611[counts_611] = BaselineIrrad611;
    BaselineIrradErrArray611[counts_611] = BaselineIrradErr611/2;
    FallTimeArray611[counts_611] = FallTime611;
    FallTimeErrArray611[counts_611] = FallTimeErr611/2;
    RiseTimeArray611[counts_611] = RiseTime611;
    RiseTimeErrArray611[counts_611] = RiseTimeErr611/2;
    aveAllts12Irrad611 += avets12Irrad611;
    maxAllts12Irrad611 += maxts12Irrad611;
    minAllts12Irrad611 += mints12Irrad611;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609 + counts_610+counts_611] = UCNIntegral611;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609+ counts_610+ counts_611] = UCNIntegralErr611/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608+ counts_609+ counts_610+ counts_611] = cycleDelayTime611;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608+counts_609+ counts_610+ counts_611] = HistIntegral611;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608+counts_609+ counts_610+ counts_611] = sqrt (HistIntegral611)/2;
    counts_611++;
  }
  aveAllts12Irrad611 = aveAllts12Irrad611/counts_611;
  maxAllts12Irrad611 = maxAllts12Irrad611/counts_611;
  minAllts12Irrad611 = minAllts12Irrad611/counts_611;
  aveAllErrts12Irrad611 = (maxAllts12Irrad611 - minAllts12Irrad611)/2;




  ULong64_t events612;
  events612 = (Double_t)outputTree612 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events612 ; j++){
    outputTree612 -> GetEvent(j);
    UCNIntegralArray612[counts_612] = UCNIntegral612;
    UCNIntegralErrArray612[counts_612] = UCNIntegralErr612/2;
    HistIntegralArray612[counts_612] = HistIntegral612;
    HistIntegralErrArray612[counts_612] = sqrt (HistIntegral612)/2;
    avets12IrradArray612[counts_612] = avets12Irrad612;
    avets12ValveOpenArray612[counts_612] = avets12ValveOpen612;
    maxts12IrradArray612[counts_612] = maxts12Irrad612;
    maxts12ValveOpenArray612[counts_612] = maxts12ValveOpen612;
    mints12IrradArray612[counts_612] = mints12Irrad612; 
    mints12ValveOpenArray612[counts_612] = mints12ValveOpen612;
    ts12IrradErr612[counts_612] = (maxts12Irrad612 - mints12Irrad612)/2;
    ts12ValveOpenErr612[counts_612] = (maxts12ValveOpen612 - mints12ValveOpen612)/2;
    avecurArray612[counts_612] = avecur612;
    maxcurArray612[counts_612] = maxcur612;
    mincurArray612[counts_612] = mincur612;
    ErrcurArray612[counts_612] = (maxcur612 - mincur612)/2;
    delaytimeArray612[counts_612] = cycleDelayTime612;
    cycleNumberArray612[counts_612] = cycleNumber612;
    BaselineArray612[counts_612] = Baseline612;
    BaselineIrradArray612[counts_612] = BaselineIrrad612;
    BaselineIrradErrArray612[counts_612] = BaselineIrradErr612/2;
    FallTimeArray612[counts_612] = FallTime612;
    FallTimeErrArray612[counts_612] = FallTimeErr612/2;
    RiseTimeArray612[counts_612] = RiseTime612;
    RiseTimeErrArray612[counts_612] = RiseTimeErr612/2;
    aveAllts12Irrad612 += avets12Irrad612;
    maxAllts12Irrad612 += maxts12Irrad612;
    minAllts12Irrad612 += mints12Irrad612;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609 + counts_610+counts_611+counts_612] = UCNIntegral612;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609+counts_610+counts_611+counts_612] = UCNIntegralErr612/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608+ counts_609+counts_610+counts_611+counts_612] = cycleDelayTime612;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608+counts_609+counts_610+counts_611+counts_612] = HistIntegral612;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608+counts_609+counts_610+counts_611+counts_612] = sqrt (HistIntegral612)/2;
    counts_612++;
  }
  aveAllts12Irrad612 = aveAllts12Irrad612/counts_612;
  maxAllts12Irrad612 = maxAllts12Irrad612/counts_612;
  minAllts12Irrad612 = minAllts12Irrad612/counts_612;
  aveAllErrts12Irrad612 = (maxAllts12Irrad612 - minAllts12Irrad612)/2;



  ULong64_t events613;
  events613 = (Double_t)outputTree613 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events613 ; j++){
    outputTree613 -> GetEvent(j);
    UCNIntegralArray613[counts_613] = UCNIntegral613;
    UCNIntegralErrArray613[counts_613] = UCNIntegralErr613/2;
    HistIntegralArray613[counts_613] = HistIntegral613;
    HistIntegralErrArray613[counts_613] = sqrt (HistIntegral613)/2;
    avets12IrradArray613[counts_613] = avets12Irrad613;
    avets12ValveOpenArray613[counts_613] = avets12ValveOpen613;
    maxts12IrradArray613[counts_613] = maxts12Irrad613;
    maxts12ValveOpenArray613[counts_613] = maxts12ValveOpen613;
    mints12IrradArray613[counts_613] = mints12Irrad613; 
    mints12ValveOpenArray613[counts_613] = mints12ValveOpen613;
    ts12IrradErr613[counts_613] = (maxts12Irrad613 - mints12Irrad613)/2;
    ts12ValveOpenErr613[counts_613] = (maxts12ValveOpen613 - mints12ValveOpen613)/2;
    avecurArray613[counts_613] = avecur613;
    maxcurArray613[counts_613] = maxcur613;
    mincurArray613[counts_613] = mincur613;
    ErrcurArray613[counts_613] = (maxcur613 - mincur613)/2;
    delaytimeArray613[counts_613] = cycleDelayTime613;
    cycleNumberArray613[counts_613] = cycleNumber613;
    BaselineArray613[counts_613] = Baseline613;
    BaselineIrradArray613[counts_613] = BaselineIrrad613;
    BaselineIrradErrArray613[counts_613] = BaselineIrradErr613/2;
    FallTimeArray613[counts_613] = FallTime613;
    FallTimeErrArray613[counts_613] = FallTimeErr613/2;
    RiseTimeArray613[counts_613] = RiseTime613;
    RiseTimeErrArray613[counts_613] = RiseTimeErr613/2;
    aveAllts12Irrad613 += avets12Irrad613;
    maxAllts12Irrad613 += maxts12Irrad613;
    minAllts12Irrad613 += mints12Irrad613;
    UCNIntegralArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609 + counts_610+counts_611+counts_612+counts_613] = UCNIntegral613;
    UCNIntegralErrArrayAll[counts_605+ counts_606+counts_607+counts_608 + counts_609+ counts_610+ counts_611+counts_612+counts_613] = UCNIntegralErr613/2;
    delayTimeAll[counts_605+ counts_606+counts_607+counts_608+ counts_609+ counts_610+counts_611+counts_612+ counts_613] = cycleDelayTime613;
    HistIntegralArrayAll[counts_605 + counts_606+ counts_607+ counts_608+counts_609+ counts_610+counts_611+counts_612+ counts_613] = HistIntegral613;
    HistIntegralErrArrayAll[counts_605+counts_606+counts_607+counts_608+counts_609+ counts_610+counts_611+counts_612+ counts_613] = sqrt (HistIntegral613)/2;
    counts_613++;
  }
  aveAllts12Irrad613 = aveAllts12Irrad613/counts_613;
  maxAllts12Irrad613 = maxAllts12Irrad613/counts_613;
  minAllts12Irrad613 = minAllts12Irrad613/counts_613;
  aveAllErrts12Irrad613 = (maxAllts12Irrad613 - minAllts12Irrad613)/2;



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
  //              605
  //*********************************
  //*********************************
  TCanvas *c605 = new TCanvas("c605" , "c605" , 1200, 800);
  c605 -> Divide(2,2);
  //c605 -> cd(1);
  TPad *p1 = c605->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr605_delaycounts = new TGraphErrors(counts_605, delaytimeArray605 , UCNIntegralArray605, 0, UCNIntegralErrArray605);

  gr605_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr605_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr605_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr605_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr605_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_delaycounts -> SetMarkerStyle(7);
  gr605_delaycounts -> Fit(fit);
  storage605 = fit -> GetParameter(1);
  storageErr605 = fit -> GetParError(1);
  
  TGraphErrors *gr605_delayhist = new TGraphErrors(counts_605, delaytimeArray605 , HistIntegralArray605, 0, HistIntegralErrArray605);

  gr605_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr605_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr605_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr605_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr605_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr605_delayhist -> SetMarkerColor(2);
  gr605_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr605_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr605_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr605_delaycounts -> Draw("Ap");
  gr605_delayhist -> Draw("p");
  leg2 -> Draw();

  //c605 -> cd(2);
  TPad *p2 = c605->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr605_tempIrradcounts = new TGraphErrors (counts_605 , avets12IrradArray605, UCNIntegralArray605 , ts12IrradErr605 , UCNIntegralErrArray605);
  gr605_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr605_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr605_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr605_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr605_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr605_tempValveOpencounts = new TGraphErrors (counts_605 , avets12ValveOpenArray605, UCNIntegralArray605 , ts12ValveOpenErr605 , UCNIntegralErrArray605);
  gr605_tempValveOpencounts -> SetMarkerStyle(7);
  gr605_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr605_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr605_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr605_tempIrradcounts -> Draw("Ap");
  gr605_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c605 -> cd(3);
  TGraphErrors *gr605_delaytempIrrad = new TGraphErrors (counts_605 , delaytimeArray605, avets12IrradArray605, 0 , ts12IrradErr605);

  gr605_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr605_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr605_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr605_delaytempIrrad -> SetMarkerStyle(7);
  gr605_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr605_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr605_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr605_delaytempValveOpen = new TGraphErrors (counts_605 , delaytimeArray605, avets12ValveOpenArray605, 0 , ts12ValveOpenErr605);

  gr605_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr605_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr605_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr605_delaytempValveOpen -> SetMarkerStyle(7);
  gr605_delaytempValveOpen -> SetMarkerColor(2);
  gr605_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr605_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr605_delaytempIrrad -> Draw("AP");
  gr605_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c605->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr605_curcounts = new TGraphErrors (counts_605 , avecurArray605, UCNIntegralArray605 , ErrcurArray605 , UCNIntegralErrArray605);
  gr605_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr605_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr605_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr605_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr605_curhist = new TGraphErrors (counts_605 , avecurArray605, UCNIntegralArray605 , ErrcurArray605 , UCNIntegralErrArray605);
  gr605_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr605_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr605_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr605_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr605_curhist -> SetMarkerColor(2);
  gr605_curhist -> SetMarkerStyle(7);

  gr605_curcounts -> Draw("Ap");
  gr605_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c605_cycleNum = new TCanvas("c605_cycleNum" , "c605_cycleNum" , 1200, 800);
  c605_cycleNum -> Divide(2,2);
  TPad *p5 = c605_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr605_cyclecounts = new TGraphErrors (counts_605 , cycleNumberArray605, UCNIntegralArray605, 0 , UCNIntegralErrArray605);
  gr605_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr605_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr605_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr605_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr605_cyclehist = new TGraphErrors(counts_605, cycleNumberArray605 , HistIntegralArray605, 0, HistIntegralErrArray605);

  gr605_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr605_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr605_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr605_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr605_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr605_cyclehist -> SetMarkerColor(2);
  gr605_cyclehist -> SetMarkerStyle(7);

  gr605_cyclecounts -> Draw("Ap");
  gr605_cyclehist -> Draw("p");

  leg2-> Draw();

  c605_cycleNum -> cd(2);
 TGraphErrors *gr605_cycledelay = new TGraphErrors (counts_605 , cycleNumberArray605, delaytimeArray605, 0 , 0);
  gr605_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr605_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr605_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr605_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cycledelay -> SetMarkerStyle(7);

  gr605_cycledelay -> Draw("Ap");


  c605_cycleNum -> cd(3);
  TGraphErrors *gr605_cycletempIrrad = new TGraphErrors (counts_605 , cycleNumberArray605, avets12IrradArray605, 0 , ts12IrradErr605);

  gr605_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr605_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr605_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr605_cycletempIrrad -> SetMarkerStyle(7);
  gr605_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr605_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr605_cycletempValveOpen = new TGraphErrors (counts_605 , cycleNumberArray605, avets12ValveOpenArray605, 0 , ts12ValveOpenErr605);

  gr605_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr605_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr605_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr605_cycletempValveOpen -> SetMarkerStyle(7);
  gr605_cycletempValveOpen -> SetMarkerColor(2);
  gr605_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr605_cycletempIrrad -> Draw("AP");
  gr605_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c605_cycleNum -> cd(4);
  TGraphErrors *gr605_cyclecur = new TGraphErrors (counts_605 , cycleNumberArray605 , avecurArray605, 0, ErrcurArray605 );
  gr605_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr605_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr605_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr605_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclecur -> SetMarkerStyle(7);
  gr605_cyclecur -> Draw("Ap");


  TCanvas *c605_cycleNumFit = new TCanvas("c605_cycleNumFit" , "c605_cycleNumFit" , 1200, 800);
  c605_cycleNumFit -> Divide(2,2);

  c605_cycleNumFit -> cd(1);
  TGraphErrors *gr605_cyclefall = new TGraphErrors (counts_605, cycleNumberArray605, FallTimeArray605 , 0, FallTimeErrArray605);

  gr605_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr605_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr605_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr605_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclefall -> SetMarkerStyle(7);
  gr605_cyclefall -> Draw("Ap");


  c605_cycleNumFit -> cd(2);
  TGraphErrors *gr605_cyclebaseline = new TGraphErrors (counts_605, cycleNumberArray605, BaselineArray605 , 0, BaselineErrArray605);

  gr605_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr605_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr605_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr605_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclebaseline -> SetMarkerStyle(7);
  gr605_cyclebaseline -> Draw("Ap");

  c605_cycleNumFit -> cd(3);
  TGraphErrors *gr605_cyclebaselineirrad = new TGraphErrors (counts_605, cycleNumberArray605, BaselineIrradArray605 , 0, BaselineIrradErrArray605);

  gr605_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr605_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr605_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr605_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclebaselineirrad -> SetMarkerStyle(7);
  gr605_cyclebaselineirrad -> Draw("Ap");

  c605_cycleNumFit -> cd(4);
  TGraphErrors *gr605_cyclerise = new TGraphErrors (counts_605, cycleNumberArray605, RiseTimeArray605 , 0, RiseTimeErrArray605);

  gr605_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr605_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr605_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr605_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr605_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr605_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr605_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr605_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr605_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr605_cyclerise -> SetMarkerStyle(7);
  gr605_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              606
  //*********************************
  //*********************************
  TCanvas *c606 = new TCanvas("c606" , "c606" , 1200, 800);
  c606 -> Divide(2,2);
  //c606 -> cd(1);
  TPad *p606_1 = c606->cd(1);
  p606_1->SetLogy(); 
  TGraphErrors *gr606_delaycounts = new TGraphErrors(counts_606, delaytimeArray606 , UCNIntegralArray606, 0, UCNIntegralErrArray606);

  gr606_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr606_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr606_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr606_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr606_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_delaycounts -> SetMarkerStyle(7);
  gr606_delaycounts -> Fit(fit);
  storage606 = fit -> GetParameter(1);
  storageErr606 = fit -> GetParError(1);
  
  TGraphErrors *gr606_delayhist = new TGraphErrors(counts_606, delaytimeArray606 , HistIntegralArray606, 0, HistIntegralErrArray606);

  gr606_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr606_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr606_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr606_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr606_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr606_delayhist -> SetMarkerColor(2);
  gr606_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr606_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr606_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr606_delaycounts -> Draw("Ap");
  gr606_delayhist -> Draw("p");
  leg2 -> Draw();

  //c606 -> cd(2);
  TPad *p606_2 = c606->cd(2);
  p606_2->SetLogy(); 
  TGraphErrors *gr606_tempIrradcounts = new TGraphErrors (counts_606 , avets12IrradArray606, UCNIntegralArray606 , ts12IrradErr606 , UCNIntegralErrArray606);
  gr606_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr606_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr606_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr606_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr606_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr606_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr606_tempValveOpencounts = new TGraphErrors (counts_606 , avets12ValveOpenArray606, UCNIntegralArray606 , ts12ValveOpenErr606 , UCNIntegralErrArray606);
  gr606_tempValveOpencounts -> SetMarkerStyle(7);
  gr606_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr606_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr606_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr606_tempIrradcounts -> Draw("Ap");
  gr606_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c606 -> cd(3);
  TGraphErrors *gr606_delaytempIrrad = new TGraphErrors (counts_606 , delaytimeArray606, avets12IrradArray606, 0 , ts12IrradErr606);

  gr606_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr606_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr606_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr606_delaytempIrrad -> SetMarkerStyle(7);
  gr606_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr606_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr606_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr606_delaytempValveOpen = new TGraphErrors (counts_606 , delaytimeArray606, avets12ValveOpenArray606, 0 , ts12ValveOpenErr606);

  gr606_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr606_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr606_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr606_delaytempValveOpen -> SetMarkerStyle(7);
  gr606_delaytempValveOpen -> SetMarkerColor(2);
  gr606_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr606_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr606_delaytempIrrad -> Draw("AP");
  gr606_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p606_3 = c606->cd(4);
  p606_3->SetLogy(); 
  TGraphErrors *gr606_curcounts = new TGraphErrors (counts_606 , avecurArray606, UCNIntegralArray606 , ErrcurArray606 , UCNIntegralErrArray606);
  gr606_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr606_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr606_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr606_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr606_curhist = new TGraphErrors (counts_606 , avecurArray606, UCNIntegralArray606 , ErrcurArray606 , UCNIntegralErrArray606);
  gr606_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr606_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr606_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr606_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr606_curhist -> SetMarkerColor(2);
  gr606_curhist -> SetMarkerStyle(7);

  gr606_curcounts -> Draw("Ap");
  gr606_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c606_cycleNum = new TCanvas("c606_cycleNum" , "c606_cycleNum" , 1200, 800);
  c606_cycleNum -> Divide(2,2);
  TPad *p606_4 = c606_cycleNum->cd(1);
  p606_4->SetLogy(); 
  TGraphErrors *gr606_cyclecounts = new TGraphErrors (counts_606 , cycleNumberArray606, UCNIntegralArray606, 0 , UCNIntegralErrArray606);
  gr606_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr606_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr606_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr606_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr606_cyclehist = new TGraphErrors(counts_606, cycleNumberArray606 , HistIntegralArray606, 0, HistIntegralErrArray606);

  gr606_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr606_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr606_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr606_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr606_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr606_cyclehist -> SetMarkerColor(2);
  gr606_cyclehist -> SetMarkerStyle(7);

  gr606_cyclecounts -> Draw("Ap");
  gr606_cyclehist -> Draw("p");

  leg2-> Draw();

  c606_cycleNum -> cd(2);
 TGraphErrors *gr606_cycledelay = new TGraphErrors (counts_606 , cycleNumberArray606, delaytimeArray606, 0 , 0);
  gr606_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr606_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr606_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr606_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cycledelay -> SetMarkerStyle(7);

  gr606_cycledelay -> Draw("Ap");


  c606_cycleNum -> cd(3);
  TGraphErrors *gr606_cycletempIrrad = new TGraphErrors (counts_606 , cycleNumberArray606, avets12IrradArray606, 0 , ts12IrradErr606);

  gr606_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr606_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr606_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr606_cycletempIrrad -> SetMarkerStyle(7);
  gr606_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.85, 0.9);
  gr606_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr606_cycletempValveOpen = new TGraphErrors (counts_606 , cycleNumberArray606, avets12ValveOpenArray606, 0 , ts12ValveOpenErr606);

  gr606_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr606_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr606_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr606_cycletempValveOpen -> SetMarkerStyle(7);
  gr606_cycletempValveOpen -> SetMarkerColor(2);
  gr606_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr606_cycletempIrrad -> Draw("AP");
  gr606_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c606_cycleNum -> cd(4);
  TGraphErrors *gr606_cyclecur = new TGraphErrors (counts_606 , cycleNumberArray606 , avecurArray606, 0, ErrcurArray606 );
  gr606_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr606_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr606_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr606_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclecur -> SetMarkerStyle(7);
  gr606_cyclecur -> Draw("Ap");


  TCanvas *c606_cycleNumFit = new TCanvas("c606_cycleNumFit" , "c606_cycleNumFit" , 1200, 800);
  c606_cycleNumFit -> Divide(2,2);

  c606_cycleNumFit -> cd(1);
  TGraphErrors *gr606_cyclefall = new TGraphErrors (counts_606, cycleNumberArray606, FallTimeArray606 , 0, FallTimeErrArray606);

  gr606_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr606_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr606_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr606_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclefall -> SetMarkerStyle(7);
  gr606_cyclefall -> Draw("Ap");


  c606_cycleNumFit -> cd(2);
  TGraphErrors *gr606_cyclebaseline = new TGraphErrors (counts_606, cycleNumberArray606, BaselineArray606 , 0, BaselineErrArray606);

  gr606_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr606_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr606_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr606_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclebaseline -> SetMarkerStyle(7);
  gr606_cyclebaseline -> Draw("Ap");

  c606_cycleNumFit -> cd(3);
  TGraphErrors *gr606_cyclebaselineirrad = new TGraphErrors (counts_606, cycleNumberArray606, BaselineIrradArray606 , 0, BaselineIrradErrArray606);

  gr606_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr606_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr606_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr606_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclebaselineirrad -> SetMarkerStyle(7);
  gr606_cyclebaselineirrad -> Draw("Ap");

  c606_cycleNumFit -> cd(4);
  TGraphErrors *gr606_cyclerise = new TGraphErrors (counts_606, cycleNumberArray606, RiseTimeArray606 , 0, RiseTimeErrArray606);

  gr606_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr606_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr606_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr606_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr606_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr606_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr606_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr606_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr606_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr606_cyclerise -> SetMarkerStyle(7);
  gr606_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              607
  //*********************************
  //*********************************
  TCanvas *c607 = new TCanvas("c607" , "c607" , 1200, 800);
  c607 -> Divide(2,2);
  //c607 -> cd(1);
  TPad *p607_1 = c607->cd(1);
  p607_1->SetLogy(); 
  TGraphErrors *gr607_delaycounts = new TGraphErrors(counts_607, delaytimeArray607 , UCNIntegralArray607, 0, UCNIntegralErrArray607);

  gr607_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr607_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr607_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr607_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr607_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_delaycounts -> SetMarkerStyle(7);
  gr607_delaycounts -> Fit(fit);
  storage607 = fit -> GetParameter(1);
  storageErr607 = fit -> GetParError(1);
  
  TGraphErrors *gr607_delayhist = new TGraphErrors(counts_607, delaytimeArray607 , HistIntegralArray607, 0, HistIntegralErrArray607);

  gr607_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr607_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr607_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr607_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr607_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr607_delayhist -> SetMarkerColor(2);
  gr607_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr607_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr607_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr607_delaycounts -> Draw("Ap");
  gr607_delayhist -> Draw("p");
  leg2 -> Draw();

  //c607 -> cd(2);
  TPad *p607_2 = c607->cd(2);
  p607_2->SetLogy(); 
  TGraphErrors *gr607_tempIrradcounts = new TGraphErrors (counts_607 , avets12IrradArray607, UCNIntegralArray607 , ts12IrradErr607 , UCNIntegralErrArray607);
  gr607_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr607_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr607_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr607_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr607_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr607_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr607_tempValveOpencounts = new TGraphErrors (counts_607 , avets12ValveOpenArray607, UCNIntegralArray607 , ts12ValveOpenErr607 , UCNIntegralErrArray607);
  gr607_tempValveOpencounts -> SetMarkerStyle(7);
  gr607_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr607_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr607_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr607_tempIrradcounts -> Draw("Ap");
  gr607_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c607 -> cd(3);
  TGraphErrors *gr607_delaytempIrrad = new TGraphErrors (counts_607 , delaytimeArray607, avets12IrradArray607, 0 , ts12IrradErr607);

  gr607_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr607_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr607_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr607_delaytempIrrad -> SetMarkerStyle(7);
  gr607_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr607_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr607_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr607_delaytempValveOpen = new TGraphErrors (counts_607 , delaytimeArray607, avets12ValveOpenArray607, 0 , ts12ValveOpenErr607);

  gr607_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr607_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr607_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr607_delaytempValveOpen -> SetMarkerStyle(7);
  gr607_delaytempValveOpen -> SetMarkerColor(2);
  gr607_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr607_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr607_delaytempIrrad -> Draw("AP");
  gr607_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p607_3 = c607->cd(4);
  p607_3->SetLogy(); 
  TGraphErrors *gr607_curcounts = new TGraphErrors (counts_607 , avecurArray607, UCNIntegralArray607 , ErrcurArray607 , UCNIntegralErrArray607);
  gr607_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr607_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr607_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr607_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr607_curhist = new TGraphErrors (counts_607 , avecurArray607, UCNIntegralArray607 , ErrcurArray607 , UCNIntegralErrArray607);
  gr607_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr607_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr607_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr607_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr607_curhist -> SetMarkerColor(2);
  gr607_curhist -> SetMarkerStyle(7);

  gr607_curcounts -> Draw("Ap");
  gr607_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c607_cycleNum = new TCanvas("c607_cycleNum" , "c607_cycleNum" , 1200, 800);
  c607_cycleNum -> Divide(2,2);
  TPad *p607_4 = c607_cycleNum->cd(1);
  p607_4->SetLogy(); 
  TGraphErrors *gr607_cyclecounts = new TGraphErrors (counts_607 , cycleNumberArray607, UCNIntegralArray607, 0 , UCNIntegralErrArray607);
  gr607_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr607_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr607_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr607_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr607_cyclehist = new TGraphErrors(counts_607, cycleNumberArray607 , HistIntegralArray607, 0, HistIntegralErrArray607);

  gr607_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr607_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr607_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr607_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr607_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr607_cyclehist -> SetMarkerColor(2);
  gr607_cyclehist -> SetMarkerStyle(7);

  gr607_cyclecounts -> Draw("Ap");
  gr607_cyclehist -> Draw("p");

  leg2-> Draw();

  c607_cycleNum -> cd(2);
 TGraphErrors *gr607_cycledelay = new TGraphErrors (counts_607 , cycleNumberArray607, delaytimeArray607, 0 , 0);
  gr607_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr607_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr607_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr607_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cycledelay -> SetMarkerStyle(7);

  gr607_cycledelay -> Draw("Ap");


  c607_cycleNum -> cd(3);
  TGraphErrors *gr607_cycletempIrrad = new TGraphErrors (counts_607 , cycleNumberArray607, avets12IrradArray607, 0 , ts12IrradErr607);

  gr607_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr607_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr607_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr607_cycletempIrrad -> SetMarkerStyle(7);
  gr607_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr607_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr607_cycletempValveOpen = new TGraphErrors (counts_607 , cycleNumberArray607, avets12ValveOpenArray607, 0 , ts12ValveOpenErr607);

  gr607_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr607_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr607_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr607_cycletempValveOpen -> SetMarkerStyle(7);
  gr607_cycletempValveOpen -> SetMarkerColor(2);
  gr607_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr607_cycletempIrrad -> Draw("AP");
  gr607_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c607_cycleNum -> cd(4);
  TGraphErrors *gr607_cyclecur = new TGraphErrors (counts_607 , cycleNumberArray607 , avecurArray607, 0, ErrcurArray607 );
  gr607_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr607_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr607_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr607_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclecur -> SetMarkerStyle(7);
  gr607_cyclecur -> Draw("Ap");


  TCanvas *c607_cycleNumFit = new TCanvas("c607_cycleNumFit" , "c607_cycleNumFit" , 1200, 800);
  c607_cycleNumFit -> Divide(2,2);

  c607_cycleNumFit -> cd(1);
  TGraphErrors *gr607_cyclefall = new TGraphErrors (counts_607, cycleNumberArray607, FallTimeArray607 , 0, FallTimeErrArray607);

  gr607_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr607_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr607_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr607_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclefall -> SetMarkerStyle(7);
  gr607_cyclefall -> Draw("Ap");


  c607_cycleNumFit -> cd(2);
  TGraphErrors *gr607_cyclebaseline = new TGraphErrors (counts_607, cycleNumberArray607, BaselineArray607 , 0, BaselineErrArray607);

  gr607_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr607_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr607_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr607_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclebaseline -> SetMarkerStyle(7);
  gr607_cyclebaseline -> Draw("Ap");

  c607_cycleNumFit -> cd(3);
  TGraphErrors *gr607_cyclebaselineirrad = new TGraphErrors (counts_607, cycleNumberArray607, BaselineIrradArray607 , 0, BaselineIrradErrArray607);

  gr607_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr607_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr607_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr607_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclebaselineirrad -> SetMarkerStyle(7);
  gr607_cyclebaselineirrad -> Draw("Ap");

  c607_cycleNumFit -> cd(4);
  TGraphErrors *gr607_cyclerise = new TGraphErrors (counts_607, cycleNumberArray607, RiseTimeArray607 , 0, RiseTimeErrArray607);

  gr607_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr607_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr607_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr607_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr607_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr607_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr607_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr607_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr607_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr607_cyclerise -> SetMarkerStyle(7);
  gr607_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              608
  //*********************************
  //*********************************
  TCanvas *c608 = new TCanvas("c608" , "c608" , 1200, 800);
  c608 -> Divide(2,2);
  //c608 -> cd(1);
  TPad *p608_1 = c608->cd(1);
  p608_1->SetLogy(); 
  TGraphErrors *gr608_delaycounts = new TGraphErrors(counts_608, delaytimeArray608 , UCNIntegralArray608, 0, UCNIntegralErrArray608);

  gr608_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr608_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr608_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr608_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr608_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_delaycounts -> SetMarkerStyle(7);
  gr608_delaycounts -> Fit(fit);
  storage608 = fit -> GetParameter(1);
  storageErr608 = fit -> GetParError(1);
  
  TGraphErrors *gr608_delayhist = new TGraphErrors(counts_608, delaytimeArray608 , HistIntegralArray608, 0, HistIntegralErrArray608);

  gr608_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr608_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr608_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr608_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr608_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr608_delayhist -> SetMarkerColor(2);
  gr608_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr608_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr608_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr608_delaycounts -> Draw("Ap");
  gr608_delayhist -> Draw("p");
  leg2 -> Draw();

  //c608 -> cd(2);
  TPad *p608_2 = c608->cd(2);
  p608_2->SetLogy(); 
  TGraphErrors *gr608_tempIrradcounts = new TGraphErrors (counts_608 , avets12IrradArray608, UCNIntegralArray608 , ts12IrradErr608 , UCNIntegralErrArray608);
  gr608_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr608_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr608_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr608_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr608_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr608_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr608_tempValveOpencounts = new TGraphErrors (counts_608 , avets12ValveOpenArray608, UCNIntegralArray608 , ts12ValveOpenErr608 , UCNIntegralErrArray608);
  gr608_tempValveOpencounts -> SetMarkerStyle(7);
  gr608_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr608_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr608_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr608_tempIrradcounts -> Draw("Ap");
  gr608_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c608 -> cd(3);
  TGraphErrors *gr608_delaytempIrrad = new TGraphErrors (counts_608 , delaytimeArray608, avets12IrradArray608, 0 , ts12IrradErr608);

  gr608_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr608_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr608_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr608_delaytempIrrad -> SetMarkerStyle(7);
  gr608_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr608_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr608_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr608_delaytempValveOpen = new TGraphErrors (counts_608 , delaytimeArray608, avets12ValveOpenArray608, 0 , ts12ValveOpenErr608);

  gr608_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr608_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr608_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr608_delaytempValveOpen -> SetMarkerStyle(7);
  gr608_delaytempValveOpen -> SetMarkerColor(2);
  gr608_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr608_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr608_delaytempIrrad -> Draw("AP");
  gr608_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p608_3 = c608->cd(4);
  p608_3->SetLogy(); 
  TGraphErrors *gr608_curcounts = new TGraphErrors (counts_608 , avecurArray608, UCNIntegralArray608 , ErrcurArray608 , UCNIntegralErrArray608);
  gr608_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr608_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr608_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr608_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr608_curhist = new TGraphErrors (counts_608 , avecurArray608, UCNIntegralArray608 , ErrcurArray608 , UCNIntegralErrArray608);
  gr608_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr608_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr608_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr608_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr608_curhist -> SetMarkerColor(2);
  gr608_curhist -> SetMarkerStyle(7);

  gr608_curcounts -> Draw("Ap");
  gr608_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c608_cycleNum = new TCanvas("c608_cycleNum" , "c608_cycleNum" , 1200, 800);
  c608_cycleNum -> Divide(2,2);
  TPad *p608_4 = c608_cycleNum->cd(1);
  p608_4->SetLogy(); 
  TGraphErrors *gr608_cyclecounts = new TGraphErrors (counts_608 , cycleNumberArray608, UCNIntegralArray608, 0 , UCNIntegralErrArray608);
  gr608_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr608_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr608_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr608_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr608_cyclehist = new TGraphErrors(counts_608, cycleNumberArray608 , HistIntegralArray608, 0, HistIntegralErrArray608);

  gr608_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr608_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr608_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr608_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr608_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr608_cyclehist -> SetMarkerColor(2);
  gr608_cyclehist -> SetMarkerStyle(7);

  gr608_cyclecounts -> Draw("Ap");
  gr608_cyclehist -> Draw("p");

  leg2-> Draw();

  c608_cycleNum -> cd(2);
 TGraphErrors *gr608_cycledelay = new TGraphErrors (counts_608 , cycleNumberArray608, delaytimeArray608, 0 , 0);
  gr608_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr608_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr608_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr608_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cycledelay -> SetMarkerStyle(7);

  gr608_cycledelay -> Draw("Ap");


  c608_cycleNum -> cd(3);
  TGraphErrors *gr608_cycletempIrrad = new TGraphErrors (counts_608 , cycleNumberArray608, avets12IrradArray608, 0 , ts12IrradErr608);

  gr608_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr608_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr608_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr608_cycletempIrrad -> SetMarkerStyle(7);
  gr608_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr608_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr608_cycletempValveOpen = new TGraphErrors (counts_608 , cycleNumberArray608, avets12ValveOpenArray608, 0 , ts12ValveOpenErr608);

  gr608_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr608_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr608_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr608_cycletempValveOpen -> SetMarkerStyle(7);
  gr608_cycletempValveOpen -> SetMarkerColor(2);
  gr608_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr608_cycletempIrrad -> Draw("AP");
  gr608_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c608_cycleNum -> cd(4);
  TGraphErrors *gr608_cyclecur = new TGraphErrors (counts_608 , cycleNumberArray608 , avecurArray608, 0, ErrcurArray608 );
  gr608_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr608_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr608_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr608_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclecur -> SetMarkerStyle(7);
  gr608_cyclecur -> Draw("Ap");


  TCanvas *c608_cycleNumFit = new TCanvas("c608_cycleNumFit" , "c608_cycleNumFit" , 1200, 800);
  c608_cycleNumFit -> Divide(2,2);

  c608_cycleNumFit -> cd(1);
  TGraphErrors *gr608_cyclefall = new TGraphErrors (counts_608, cycleNumberArray608, FallTimeArray608 , 0, FallTimeErrArray608);

  gr608_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr608_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr608_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr608_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclefall -> SetMarkerStyle(7);
  gr608_cyclefall -> Draw("Ap");


  c608_cycleNumFit -> cd(2);
  TGraphErrors *gr608_cyclebaseline = new TGraphErrors (counts_608, cycleNumberArray608, BaselineArray608 , 0, BaselineErrArray608);

  gr608_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr608_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr608_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr608_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclebaseline -> SetMarkerStyle(7);
  gr608_cyclebaseline -> Draw("Ap");

  c608_cycleNumFit -> cd(3);
  TGraphErrors *gr608_cyclebaselineirrad = new TGraphErrors (counts_608, cycleNumberArray608, BaselineIrradArray608 , 0, BaselineIrradErrArray608);

  gr608_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr608_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr608_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr608_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclebaselineirrad -> SetMarkerStyle(7);
  gr608_cyclebaselineirrad -> Draw("Ap");

  c608_cycleNumFit -> cd(4);
  TGraphErrors *gr608_cyclerise = new TGraphErrors (counts_608, cycleNumberArray608, RiseTimeArray608 , 0, RiseTimeErrArray608);

  gr608_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr608_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr608_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr608_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr608_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr608_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr608_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr608_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr608_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr608_cyclerise -> SetMarkerStyle(7);
  gr608_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              609
  //*********************************
  //*********************************
  TCanvas *c609 = new TCanvas("c609" , "c609" , 1200, 800);
  c609 -> Divide(2,2);
  //c609 -> cd(1);
  TPad *p609_1 = c609->cd(1);
  p609_1->SetLogy(); 
  TGraphErrors *gr609_delaycounts = new TGraphErrors(counts_609, delaytimeArray609 , UCNIntegralArray609, 0, UCNIntegralErrArray609);

  gr609_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr609_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr609_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr609_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr609_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_delaycounts -> SetMarkerStyle(7);
  gr609_delaycounts -> Fit(fit);
  storage609 = fit -> GetParameter(1);
  storageErr609 = fit -> GetParError(1);
  
  TGraphErrors *gr609_delayhist = new TGraphErrors(counts_609, delaytimeArray609 , HistIntegralArray609, 0, HistIntegralErrArray609);

  gr609_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr609_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr609_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr609_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr609_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr609_delayhist -> SetMarkerColor(2);
  gr609_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr609_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr609_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr609_delaycounts -> Draw("Ap");
  gr609_delayhist -> Draw("p");
  leg2 -> Draw();

  //c609 -> cd(2);
  TPad *p609_2 = c609->cd(2);
  p609_2->SetLogy(); 
  TGraphErrors *gr609_tempIrradcounts = new TGraphErrors (counts_609 , avets12IrradArray609, UCNIntegralArray609 , ts12IrradErr609 , UCNIntegralErrArray609);
  gr609_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr609_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr609_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr609_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr609_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr609_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr609_tempValveOpencounts = new TGraphErrors (counts_609 , avets12ValveOpenArray609, UCNIntegralArray609 , ts12ValveOpenErr609 , UCNIntegralErrArray609);
  gr609_tempValveOpencounts -> SetMarkerStyle(7);
  gr609_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr609_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr609_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr609_tempIrradcounts -> Draw("Ap");
  gr609_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c609 -> cd(3);
  TGraphErrors *gr609_delaytempIrrad = new TGraphErrors (counts_609 , delaytimeArray609, avets12IrradArray609, 0 , ts12IrradErr609);

  gr609_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr609_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr609_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr609_delaytempIrrad -> SetMarkerStyle(7);
  gr609_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr609_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr609_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr609_delaytempValveOpen = new TGraphErrors (counts_609 , delaytimeArray609, avets12ValveOpenArray609, 0 , ts12ValveOpenErr609);

  gr609_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr609_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr609_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr609_delaytempValveOpen -> SetMarkerStyle(7);
  gr609_delaytempValveOpen -> SetMarkerColor(2);
  gr609_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr609_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr609_delaytempIrrad -> Draw("AP");
  gr609_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p609_3 = c609->cd(4);
  p609_3->SetLogy(); 
  TGraphErrors *gr609_curcounts = new TGraphErrors (counts_609 , avecurArray609, UCNIntegralArray609 , ErrcurArray609 , UCNIntegralErrArray609);
  gr609_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr609_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr609_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr609_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr609_curhist = new TGraphErrors (counts_609 , avecurArray609, UCNIntegralArray609 , ErrcurArray609 , UCNIntegralErrArray609);
  gr609_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr609_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr609_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr609_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr609_curhist -> SetMarkerColor(2);
  gr609_curhist -> SetMarkerStyle(7);

  gr609_curcounts -> Draw("Ap");
  gr609_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c609_cycleNum = new TCanvas("c609_cycleNum" , "c609_cycleNum" , 1200, 800);
  c609_cycleNum -> Divide(2,2);
  TPad *p609_4 = c609_cycleNum->cd(1);
  p609_4->SetLogy(); 
  TGraphErrors *gr609_cyclecounts = new TGraphErrors (counts_609 , cycleNumberArray609, UCNIntegralArray609, 0 , UCNIntegralErrArray609);
  gr609_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr609_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr609_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr609_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr609_cyclehist = new TGraphErrors(counts_609, cycleNumberArray609 , HistIntegralArray609, 0, HistIntegralErrArray609);

  gr609_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr609_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr609_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr609_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr609_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr609_cyclehist -> SetMarkerColor(2);
  gr609_cyclehist -> SetMarkerStyle(7);

  gr609_cyclecounts -> Draw("Ap");
  gr609_cyclehist -> Draw("p");

  leg2-> Draw();

  c609_cycleNum -> cd(2);
 TGraphErrors *gr609_cycledelay = new TGraphErrors (counts_609 , cycleNumberArray609, delaytimeArray609, 0 , 0);
  gr609_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr609_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr609_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr609_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cycledelay -> SetMarkerStyle(7);

  gr609_cycledelay -> Draw("Ap");


  c609_cycleNum -> cd(3);
  TGraphErrors *gr609_cycletempIrrad = new TGraphErrors (counts_609 , cycleNumberArray609, avets12IrradArray609, 0 , ts12IrradErr609);

  gr609_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr609_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr609_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr609_cycletempIrrad -> SetMarkerStyle(7);
  gr609_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr609_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr609_cycletempValveOpen = new TGraphErrors (counts_609 , cycleNumberArray609, avets12ValveOpenArray609, 0 , ts12ValveOpenErr609);

  gr609_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr609_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr609_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr609_cycletempValveOpen -> SetMarkerStyle(7);
  gr609_cycletempValveOpen -> SetMarkerColor(2);
  gr609_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr609_cycletempIrrad -> Draw("AP");
  gr609_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c609_cycleNum -> cd(4);
  TGraphErrors *gr609_cyclecur = new TGraphErrors (counts_609 , cycleNumberArray609 , avecurArray609, 0, ErrcurArray609 );
  gr609_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr609_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr609_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr609_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclecur -> SetMarkerStyle(7);
  gr609_cyclecur -> Draw("Ap");


  TCanvas *c609_cycleNumFit = new TCanvas("c609_cycleNumFit" , "c609_cycleNumFit" , 1200, 800);
  c609_cycleNumFit -> Divide(2,2);

  c609_cycleNumFit -> cd(1);
  TGraphErrors *gr609_cyclefall = new TGraphErrors (counts_609, cycleNumberArray609, FallTimeArray609 , 0, FallTimeErrArray609);

  gr609_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr609_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr609_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr609_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclefall -> SetMarkerStyle(7);
  gr609_cyclefall -> Draw("Ap");


  c609_cycleNumFit -> cd(2);
  TGraphErrors *gr609_cyclebaseline = new TGraphErrors (counts_609, cycleNumberArray609, BaselineArray609 , 0, BaselineErrArray609);

  gr609_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr609_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr609_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr609_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclebaseline -> SetMarkerStyle(7);
  gr609_cyclebaseline -> Draw("Ap");

  c609_cycleNumFit -> cd(3);
  TGraphErrors *gr609_cyclebaselineirrad = new TGraphErrors (counts_609, cycleNumberArray609, BaselineIrradArray609 , 0, BaselineIrradErrArray609);

  gr609_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr609_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr609_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr609_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclebaselineirrad -> SetMarkerStyle(7);
  gr609_cyclebaselineirrad -> Draw("Ap");

  c609_cycleNumFit -> cd(4);
  TGraphErrors *gr609_cyclerise = new TGraphErrors (counts_609, cycleNumberArray609, RiseTimeArray609 , 0, RiseTimeErrArray609);

  gr609_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr609_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr609_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr609_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr609_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr609_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr609_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr609_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr609_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr609_cyclerise -> SetMarkerStyle(7);
  gr609_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              610
  //*********************************
  //*********************************
  TCanvas *c610 = new TCanvas("c610" , "c610" , 1200, 800);
  c610 -> Divide(2,2);
  //c610 -> cd(1);
  TPad *p610_1 = c610->cd(1);
  p610_1->SetLogy(); 
  TGraphErrors *gr610_delaycounts = new TGraphErrors(counts_610, delaytimeArray610 , UCNIntegralArray610, 0, UCNIntegralErrArray610);

  gr610_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr610_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr610_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr610_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr610_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_delaycounts -> SetMarkerStyle(7);
  gr610_delaycounts -> Fit(fit);
  storage610 = fit -> GetParameter(1);
  storageErr610 = fit -> GetParError(1);
  
  TGraphErrors *gr610_delayhist = new TGraphErrors(counts_610, delaytimeArray610 , HistIntegralArray610, 0, HistIntegralErrArray610);

  gr610_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr610_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr610_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr610_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr610_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr610_delayhist -> SetMarkerColor(2);
  gr610_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr610_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr610_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr610_delaycounts -> Draw("Ap");
  gr610_delayhist -> Draw("p");
  leg2 -> Draw();

  //c610 -> cd(2);
  TPad *p610_2 = c610->cd(2);
  p610_2->SetLogy(); 
  TGraphErrors *gr610_tempIrradcounts = new TGraphErrors (counts_610 , avets12IrradArray610, UCNIntegralArray610 , ts12IrradErr610 , UCNIntegralErrArray610);
  gr610_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr610_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr610_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr610_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr610_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr610_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr610_tempValveOpencounts = new TGraphErrors (counts_610 , avets12ValveOpenArray610, UCNIntegralArray610 , ts12ValveOpenErr610 , UCNIntegralErrArray610);
  gr610_tempValveOpencounts -> SetMarkerStyle(7);
  gr610_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr610_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr610_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr610_tempIrradcounts -> Draw("Ap");
  gr610_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c610 -> cd(3);
  TGraphErrors *gr610_delaytempIrrad = new TGraphErrors (counts_610 , delaytimeArray610, avets12IrradArray610, 0 , ts12IrradErr610);

  gr610_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr610_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr610_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr610_delaytempIrrad -> SetMarkerStyle(7);
  gr610_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr610_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr610_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr610_delaytempValveOpen = new TGraphErrors (counts_610 , delaytimeArray610, avets12ValveOpenArray610, 0 , ts12ValveOpenErr610);

  gr610_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr610_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr610_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr610_delaytempValveOpen -> SetMarkerStyle(7);
  gr610_delaytempValveOpen -> SetMarkerColor(2);
  gr610_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr610_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr610_delaytempIrrad -> Draw("AP");
  gr610_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p610_3 = c610->cd(4);
  p610_3->SetLogy(); 
  TGraphErrors *gr610_curcounts = new TGraphErrors (counts_610 , avecurArray610, UCNIntegralArray610 , ErrcurArray610 , UCNIntegralErrArray610);
  gr610_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr610_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr610_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr610_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr610_curhist = new TGraphErrors (counts_610 , avecurArray610, UCNIntegralArray610 , ErrcurArray610 , UCNIntegralErrArray610);
  gr610_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr610_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr610_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr610_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr610_curhist -> SetMarkerColor(2);
  gr610_curhist -> SetMarkerStyle(7);

  gr610_curcounts -> Draw("Ap");
  gr610_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c610_cycleNum = new TCanvas("c610_cycleNum" , "c610_cycleNum" , 1200, 800);
  c610_cycleNum -> Divide(2,2);
  TPad *p610_4 = c610_cycleNum->cd(1);
  p610_4->SetLogy(); 
  TGraphErrors *gr610_cyclecounts = new TGraphErrors (counts_610 , cycleNumberArray610, UCNIntegralArray610, 0 , UCNIntegralErrArray610);
  gr610_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr610_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr610_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr610_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr610_cyclehist = new TGraphErrors(counts_610, cycleNumberArray610 , HistIntegralArray610, 0, HistIntegralErrArray610);

  gr610_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr610_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr610_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr610_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr610_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr610_cyclehist -> SetMarkerColor(2);
  gr610_cyclehist -> SetMarkerStyle(7);

  gr610_cyclecounts -> Draw("Ap");
  gr610_cyclehist -> Draw("p");

  leg2-> Draw();

  c610_cycleNum -> cd(2);
 TGraphErrors *gr610_cycledelay = new TGraphErrors (counts_610 , cycleNumberArray610, delaytimeArray610, 0 , 0);
  gr610_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr610_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr610_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr610_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cycledelay -> SetMarkerStyle(7);

  gr610_cycledelay -> Draw("Ap");


  c610_cycleNum -> cd(3);
  TGraphErrors *gr610_cycletempIrrad = new TGraphErrors (counts_610 , cycleNumberArray610, avets12IrradArray610, 0 , ts12IrradErr610);

  gr610_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr610_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr610_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr610_cycletempIrrad -> SetMarkerStyle(7);
  gr610_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr610_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr610_cycletempValveOpen = new TGraphErrors (counts_610 , cycleNumberArray610, avets12ValveOpenArray610, 0 , ts12ValveOpenErr610);

  gr610_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr610_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr610_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr610_cycletempValveOpen -> SetMarkerStyle(7);
  gr610_cycletempValveOpen -> SetMarkerColor(2);
  gr610_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr610_cycletempIrrad -> Draw("AP");
  gr610_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c610_cycleNum -> cd(4);
  TGraphErrors *gr610_cyclecur = new TGraphErrors (counts_610 , cycleNumberArray610 , avecurArray610, 0, ErrcurArray610 );
  gr610_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr610_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr610_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr610_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclecur -> SetMarkerStyle(7);
  gr610_cyclecur -> Draw("Ap");


  TCanvas *c610_cycleNumFit = new TCanvas("c610_cycleNumFit" , "c610_cycleNumFit" , 1200, 800);
  c610_cycleNumFit -> Divide(2,2);

  c610_cycleNumFit -> cd(1);
  TGraphErrors *gr610_cyclefall = new TGraphErrors (counts_610, cycleNumberArray610, FallTimeArray610 , 0, FallTimeErrArray610);

  gr610_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr610_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr610_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr610_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclefall -> SetMarkerStyle(7);
  gr610_cyclefall -> Draw("Ap");


  c610_cycleNumFit -> cd(2);
  TGraphErrors *gr610_cyclebaseline = new TGraphErrors (counts_610, cycleNumberArray610, BaselineArray610 , 0, BaselineErrArray610);

  gr610_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr610_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr610_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr610_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclebaseline -> SetMarkerStyle(7);
  gr610_cyclebaseline -> Draw("Ap");

  c610_cycleNumFit -> cd(3);
  TGraphErrors *gr610_cyclebaselineirrad = new TGraphErrors (counts_610, cycleNumberArray610, BaselineIrradArray610 , 0, BaselineIrradErrArray610);

  gr610_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr610_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr610_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr610_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclebaselineirrad -> SetMarkerStyle(7);
  gr610_cyclebaselineirrad -> Draw("Ap");

  c610_cycleNumFit -> cd(4);
  TGraphErrors *gr610_cyclerise = new TGraphErrors (counts_610, cycleNumberArray610, RiseTimeArray610 , 0, RiseTimeErrArray610);

  gr610_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr610_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr610_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr610_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr610_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr610_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr610_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr610_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr610_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr610_cyclerise -> SetMarkerStyle(7);
  gr610_cyclerise -> Draw("Ap");






  //*********************************
  //*********************************
  //              611
  //*********************************
  //*********************************
  TCanvas *c611 = new TCanvas("c611" , "c611" , 1200, 800);
  c611 -> Divide(2,2);
  //c611 -> cd(1);
  TPad *p611_1 = c611->cd(1);
  p611_1->SetLogy(); 
  TGraphErrors *gr611_delaycounts = new TGraphErrors(counts_611, delaytimeArray611 , UCNIntegralArray611, 0, UCNIntegralErrArray611);

  gr611_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr611_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr611_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr611_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr611_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_delaycounts -> SetMarkerStyle(7);
  gr611_delaycounts -> Fit(fit);
  storage611 = fit -> GetParameter(1);
  storageErr611 = fit -> GetParError(1);
  
  TGraphErrors *gr611_delayhist = new TGraphErrors(counts_611, delaytimeArray611 , HistIntegralArray611, 0, HistIntegralErrArray611);

  gr611_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr611_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr611_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr611_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr611_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr611_delayhist -> SetMarkerColor(2);
  gr611_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr611_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr611_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr611_delaycounts -> Draw("Ap");
  gr611_delayhist -> Draw("p");
  leg2 -> Draw();

  //c611 -> cd(2);
  TPad *p611_2 = c611->cd(2);
  p611_2->SetLogy(); 
  TGraphErrors *gr611_tempIrradcounts = new TGraphErrors (counts_611 , avets12IrradArray611, UCNIntegralArray611 , ts12IrradErr611 , UCNIntegralErrArray611);
  gr611_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr611_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr611_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr611_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr611_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr611_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr611_tempValveOpencounts = new TGraphErrors (counts_611 , avets12ValveOpenArray611, UCNIntegralArray611 , ts12ValveOpenErr611 , UCNIntegralErrArray611);
  gr611_tempValveOpencounts -> SetMarkerStyle(7);
  gr611_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr611_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr611_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr611_tempIrradcounts -> Draw("Ap");
  gr611_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c611 -> cd(3);
  TGraphErrors *gr611_delaytempIrrad = new TGraphErrors (counts_611 , delaytimeArray611, avets12IrradArray611, 0 , ts12IrradErr611);

  gr611_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr611_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr611_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr611_delaytempIrrad -> SetMarkerStyle(7);
  gr611_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr611_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr611_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr611_delaytempValveOpen = new TGraphErrors (counts_611 , delaytimeArray611, avets12ValveOpenArray611, 0 , ts12ValveOpenErr611);

  gr611_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr611_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr611_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr611_delaytempValveOpen -> SetMarkerStyle(7);
  gr611_delaytempValveOpen -> SetMarkerColor(2);
  gr611_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr611_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr611_delaytempIrrad -> Draw("AP");
  gr611_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p611_3 = c611->cd(4);
  p611_3->SetLogy(); 
  TGraphErrors *gr611_curcounts = new TGraphErrors (counts_611 , avecurArray611, UCNIntegralArray611 , ErrcurArray611 , UCNIntegralErrArray611);
  gr611_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr611_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr611_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr611_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr611_curhist = new TGraphErrors (counts_611 , avecurArray611, UCNIntegralArray611 , ErrcurArray611 , UCNIntegralErrArray611);
  gr611_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr611_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr611_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr611_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr611_curhist -> SetMarkerColor(2);
  gr611_curhist -> SetMarkerStyle(7);

  gr611_curcounts -> Draw("Ap");
  gr611_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c611_cycleNum = new TCanvas("c611_cycleNum" , "c611_cycleNum" , 1200, 800);
  c611_cycleNum -> Divide(2,2);
  TPad *p611_4 = c611_cycleNum->cd(1);
  p611_4->SetLogy(); 
  TGraphErrors *gr611_cyclecounts = new TGraphErrors (counts_611 , cycleNumberArray611, UCNIntegralArray611, 0 , UCNIntegralErrArray611);
  gr611_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr611_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr611_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr611_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr611_cyclehist = new TGraphErrors(counts_611, cycleNumberArray611 , HistIntegralArray611, 0, HistIntegralErrArray611);

  gr611_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr611_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr611_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr611_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr611_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr611_cyclehist -> SetMarkerColor(2);
  gr611_cyclehist -> SetMarkerStyle(7);

  gr611_cyclecounts -> Draw("Ap");
  gr611_cyclehist -> Draw("p");

  leg2-> Draw();

  c611_cycleNum -> cd(2);
 TGraphErrors *gr611_cycledelay = new TGraphErrors (counts_611 , cycleNumberArray611, delaytimeArray611, 0 , 0);
  gr611_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr611_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr611_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr611_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cycledelay -> SetMarkerStyle(7);

  gr611_cycledelay -> Draw("Ap");


  c611_cycleNum -> cd(3);
  TGraphErrors *gr611_cycletempIrrad = new TGraphErrors (counts_611 , cycleNumberArray611, avets12IrradArray611, 0 , ts12IrradErr611);

  gr611_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr611_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr611_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr611_cycletempIrrad -> SetMarkerStyle(7);
  gr611_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr611_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr611_cycletempValveOpen = new TGraphErrors (counts_611 , cycleNumberArray611, avets12ValveOpenArray611, 0 , ts12ValveOpenErr611);

  gr611_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr611_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr611_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr611_cycletempValveOpen -> SetMarkerStyle(7);
  gr611_cycletempValveOpen -> SetMarkerColor(2);
  gr611_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr611_cycletempIrrad -> Draw("AP");
  gr611_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c611_cycleNum -> cd(4);
  TGraphErrors *gr611_cyclecur = new TGraphErrors (counts_611 , cycleNumberArray611 , avecurArray611, 0, ErrcurArray611 );
  gr611_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr611_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr611_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr611_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclecur -> SetMarkerStyle(7);
  gr611_cyclecur -> Draw("Ap");


  TCanvas *c611_cycleNumFit = new TCanvas("c611_cycleNumFit" , "c611_cycleNumFit" , 1200, 800);
  c611_cycleNumFit -> Divide(2,2);

  c611_cycleNumFit -> cd(1);
  TGraphErrors *gr611_cyclefall = new TGraphErrors (counts_611, cycleNumberArray611, FallTimeArray611 , 0, FallTimeErrArray611);

  gr611_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr611_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr611_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr611_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclefall -> SetMarkerStyle(7);
  gr611_cyclefall -> Draw("Ap");


  c611_cycleNumFit -> cd(2);
  TGraphErrors *gr611_cyclebaseline = new TGraphErrors (counts_611, cycleNumberArray611, BaselineArray611 , 0, BaselineErrArray611);

  gr611_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr611_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr611_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr611_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclebaseline -> SetMarkerStyle(7);
  gr611_cyclebaseline -> Draw("Ap");

  c611_cycleNumFit -> cd(3);
  TGraphErrors *gr611_cyclebaselineirrad = new TGraphErrors (counts_611, cycleNumberArray611, BaselineIrradArray611 , 0, BaselineIrradErrArray611);

  gr611_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr611_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr611_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr611_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclebaselineirrad -> SetMarkerStyle(7);
  gr611_cyclebaselineirrad -> Draw("Ap");

  c611_cycleNumFit -> cd(4);
  TGraphErrors *gr611_cyclerise = new TGraphErrors (counts_611, cycleNumberArray611, RiseTimeArray611 , 0, RiseTimeErrArray611);

  gr611_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr611_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr611_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr611_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr611_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr611_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr611_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr611_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr611_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr611_cyclerise -> SetMarkerStyle(7);
  gr611_cyclerise -> Draw("Ap");







  //*********************************
  //*********************************
  //              612
  //*********************************
  //*********************************
  TCanvas *c612 = new TCanvas("c612" , "c612" , 1200, 800);
  c612 -> Divide(2,2);
  //c612 -> cd(1);
  TPad *p612_1 = c612->cd(1);
  p612_1->SetLogy(); 
  TGraphErrors *gr612_delaycounts = new TGraphErrors(counts_612, delaytimeArray612 , UCNIntegralArray612, 0, UCNIntegralErrArray612);

  gr612_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr612_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr612_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr612_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr612_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_delaycounts -> SetMarkerStyle(7);
  gr612_delaycounts -> Fit(fit);
  storage612 = fit -> GetParameter(1);
  storageErr612 = fit -> GetParError(1);
  
  TGraphErrors *gr612_delayhist = new TGraphErrors(counts_612, delaytimeArray612 , HistIntegralArray612, 0, HistIntegralErrArray612);

  gr612_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr612_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr612_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr612_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr612_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr612_delayhist -> SetMarkerColor(2);
  gr612_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr612_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr612_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr612_delaycounts -> Draw("Ap");
  gr612_delayhist -> Draw("p");
  leg2 -> Draw();

  //c612 -> cd(2);
  TPad *p612_2 = c612->cd(2);
  p612_2->SetLogy(); 
  TGraphErrors *gr612_tempIrradcounts = new TGraphErrors (counts_612 , avets12IrradArray612, UCNIntegralArray612 , ts12IrradErr612 , UCNIntegralErrArray612);
  gr612_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr612_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr612_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr612_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr612_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr612_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr612_tempValveOpencounts = new TGraphErrors (counts_612 , avets12ValveOpenArray612, UCNIntegralArray612 , ts12ValveOpenErr612 , UCNIntegralErrArray612);
  gr612_tempValveOpencounts -> SetMarkerStyle(7);
  gr612_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr612_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr612_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr612_tempIrradcounts -> Draw("Ap");
  gr612_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c612 -> cd(3);
  TGraphErrors *gr612_delaytempIrrad = new TGraphErrors (counts_612 , delaytimeArray612, avets12IrradArray612, 0 , ts12IrradErr612);

  gr612_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr612_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr612_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr612_delaytempIrrad -> SetMarkerStyle(7);
  gr612_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr612_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr612_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr612_delaytempValveOpen = new TGraphErrors (counts_612 , delaytimeArray612, avets12ValveOpenArray612, 0 , ts12ValveOpenErr612);

  gr612_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr612_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr612_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr612_delaytempValveOpen -> SetMarkerStyle(7);
  gr612_delaytempValveOpen -> SetMarkerColor(2);
  gr612_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr612_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr612_delaytempIrrad -> Draw("AP");
  gr612_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p612_3 = c612->cd(4);
  p612_3->SetLogy(); 
  TGraphErrors *gr612_curcounts = new TGraphErrors (counts_612 , avecurArray612, UCNIntegralArray612 , ErrcurArray612 , UCNIntegralErrArray612);
  gr612_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr612_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr612_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr612_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr612_curhist = new TGraphErrors (counts_612 , avecurArray612, UCNIntegralArray612 , ErrcurArray612 , UCNIntegralErrArray612);
  gr612_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr612_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr612_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr612_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr612_curhist -> SetMarkerColor(2);
  gr612_curhist -> SetMarkerStyle(7);

  gr612_curcounts -> Draw("Ap");
  gr612_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c612_cycleNum = new TCanvas("c612_cycleNum" , "c612_cycleNum" , 1200, 800);
  c612_cycleNum -> Divide(2,2);
  TPad *p612_4 = c612_cycleNum->cd(1);
  p612_4->SetLogy(); 
  TGraphErrors *gr612_cyclecounts = new TGraphErrors (counts_612 , cycleNumberArray612, UCNIntegralArray612, 0 , UCNIntegralErrArray612);
  gr612_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr612_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr612_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr612_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr612_cyclehist = new TGraphErrors(counts_612, cycleNumberArray612 , HistIntegralArray612, 0, HistIntegralErrArray612);

  gr612_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr612_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr612_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr612_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr612_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr612_cyclehist -> SetMarkerColor(2);
  gr612_cyclehist -> SetMarkerStyle(7);

  gr612_cyclecounts -> Draw("Ap");
  gr612_cyclehist -> Draw("p");

  leg2-> Draw();

  c612_cycleNum -> cd(2);
 TGraphErrors *gr612_cycledelay = new TGraphErrors (counts_612 , cycleNumberArray612, delaytimeArray612, 0 , 0);
  gr612_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr612_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr612_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr612_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cycledelay -> SetMarkerStyle(7);

  gr612_cycledelay -> Draw("Ap");


  c612_cycleNum -> cd(3);
  TGraphErrors *gr612_cycletempIrrad = new TGraphErrors (counts_612 , cycleNumberArray612, avets12IrradArray612, 0 , ts12IrradErr612);

  gr612_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr612_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr612_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr612_cycletempIrrad -> SetMarkerStyle(7);
  gr612_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr612_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr612_cycletempValveOpen = new TGraphErrors (counts_612 , cycleNumberArray612, avets12ValveOpenArray612, 0 , ts12ValveOpenErr612);

  gr612_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr612_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr612_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr612_cycletempValveOpen -> SetMarkerStyle(7);
  gr612_cycletempValveOpen -> SetMarkerColor(2);
  gr612_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr612_cycletempIrrad -> Draw("AP");
  gr612_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c612_cycleNum -> cd(4);
  TGraphErrors *gr612_cyclecur = new TGraphErrors (counts_612 , cycleNumberArray612 , avecurArray612, 0, ErrcurArray612 );
  gr612_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr612_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr612_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr612_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclecur -> SetMarkerStyle(7);
  gr612_cyclecur -> Draw("Ap");


  TCanvas *c612_cycleNumFit = new TCanvas("c612_cycleNumFit" , "c612_cycleNumFit" , 1200, 800);
  c612_cycleNumFit -> Divide(2,2);

  c612_cycleNumFit -> cd(1);
  TGraphErrors *gr612_cyclefall = new TGraphErrors (counts_612, cycleNumberArray612, FallTimeArray612 , 0, FallTimeErrArray612);

  gr612_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr612_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr612_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr612_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclefall -> SetMarkerStyle(7);
  gr612_cyclefall -> Draw("Ap");


  c612_cycleNumFit -> cd(2);
  TGraphErrors *gr612_cyclebaseline = new TGraphErrors (counts_612, cycleNumberArray612, BaselineArray612 , 0, BaselineErrArray612);

  gr612_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr612_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr612_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr612_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclebaseline -> SetMarkerStyle(7);
  gr612_cyclebaseline -> Draw("Ap");

  c612_cycleNumFit -> cd(3);
  TGraphErrors *gr612_cyclebaselineirrad = new TGraphErrors (counts_612, cycleNumberArray612, BaselineIrradArray612 , 0, BaselineIrradErrArray612);

  gr612_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr612_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr612_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr612_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclebaselineirrad -> SetMarkerStyle(7);
  gr612_cyclebaselineirrad -> Draw("Ap");

  c612_cycleNumFit -> cd(4);
  TGraphErrors *gr612_cyclerise = new TGraphErrors (counts_612, cycleNumberArray612, RiseTimeArray612 , 0, RiseTimeErrArray612);

  gr612_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr612_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr612_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr612_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr612_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr612_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr612_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr612_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr612_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr612_cyclerise -> SetMarkerStyle(7);
  gr612_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              613
  //*********************************
  //*********************************
  TCanvas *c613 = new TCanvas("c613" , "c613" , 1200, 800);
  c613 -> Divide(2,2);
  //c613 -> cd(1);
  TPad *p613_1 = c613->cd(1);
  p613_1->SetLogy(); 
  TGraphErrors *gr613_delaycounts = new TGraphErrors(counts_613, delaytimeArray613 , UCNIntegralArray613, 0, UCNIntegralErrArray613);

  gr613_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr613_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr613_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr613_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr613_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_delaycounts -> SetMarkerStyle(7);
  gr613_delaycounts -> Fit(fit);
  storage613 = fit -> GetParameter(1);
  storageErr613 = fit -> GetParError(1);
  
  TGraphErrors *gr613_delayhist = new TGraphErrors(counts_613, delaytimeArray613 , HistIntegralArray613, 0, HistIntegralErrArray613);

  gr613_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr613_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr613_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr613_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr613_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr613_delayhist -> SetMarkerColor(2);
  gr613_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr613_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr613_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr613_delaycounts -> Draw("Ap");
  gr613_delayhist -> Draw("p");
  leg2 -> Draw();

  //c613 -> cd(2);
  TPad *p613_2 = c613->cd(2);
  p613_2->SetLogy(); 
  TGraphErrors *gr613_tempIrradcounts = new TGraphErrors (counts_613 , avets12IrradArray613, UCNIntegralArray613 , ts12IrradErr613 , UCNIntegralErrArray613);
  gr613_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr613_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr613_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr613_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr613_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr613_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr613_tempValveOpencounts = new TGraphErrors (counts_613 , avets12ValveOpenArray613, UCNIntegralArray613 , ts12ValveOpenErr613 , UCNIntegralErrArray613);
  gr613_tempValveOpencounts -> SetMarkerStyle(7);
  gr613_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr613_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr613_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr613_tempIrradcounts -> Draw("Ap");
  gr613_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c613 -> cd(3);
  TGraphErrors *gr613_delaytempIrrad = new TGraphErrors (counts_613 , delaytimeArray613, avets12IrradArray613, 0 , ts12IrradErr613);

  gr613_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr613_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr613_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr613_delaytempIrrad -> SetMarkerStyle(7);
  gr613_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr613_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr613_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr613_delaytempValveOpen = new TGraphErrors (counts_613 , delaytimeArray613, avets12ValveOpenArray613, 0 , ts12ValveOpenErr613);

  gr613_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr613_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr613_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr613_delaytempValveOpen -> SetMarkerStyle(7);
  gr613_delaytempValveOpen -> SetMarkerColor(2);
  gr613_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr613_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr613_delaytempIrrad -> Draw("AP");
  gr613_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p613_3 = c613->cd(4);
  p613_3->SetLogy(); 
  TGraphErrors *gr613_curcounts = new TGraphErrors (counts_613 , avecurArray613, UCNIntegralArray613 , ErrcurArray613 , UCNIntegralErrArray613);
  gr613_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr613_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr613_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr613_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr613_curhist = new TGraphErrors (counts_613 , avecurArray613, UCNIntegralArray613 , ErrcurArray613 , UCNIntegralErrArray613);
  gr613_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr613_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr613_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr613_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr613_curhist -> SetMarkerColor(2);
  gr613_curhist -> SetMarkerStyle(7);

  gr613_curcounts -> Draw("Ap");
  gr613_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c613_cycleNum = new TCanvas("c613_cycleNum" , "c613_cycleNum" , 1200, 800);
  c613_cycleNum -> Divide(2,2);
  TPad *p613_4 = c613_cycleNum->cd(1);
  p613_4->SetLogy(); 
  TGraphErrors *gr613_cyclecounts = new TGraphErrors (counts_613 , cycleNumberArray613, UCNIntegralArray613, 0 , UCNIntegralErrArray613);
  gr613_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr613_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr613_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr613_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr613_cyclehist = new TGraphErrors(counts_613, cycleNumberArray613 , HistIntegralArray613, 0, HistIntegralErrArray613);

  gr613_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr613_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr613_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr613_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr613_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr613_cyclehist -> SetMarkerColor(2);
  gr613_cyclehist -> SetMarkerStyle(7);

  gr613_cyclecounts -> Draw("Ap");
  gr613_cyclehist -> Draw("p");

  leg2-> Draw();

  c613_cycleNum -> cd(2);
 TGraphErrors *gr613_cycledelay = new TGraphErrors (counts_613 , cycleNumberArray613, delaytimeArray613, 0 , 0);
  gr613_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr613_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr613_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr613_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cycledelay -> SetMarkerStyle(7);

  gr613_cycledelay -> Draw("Ap");


  c613_cycleNum -> cd(3);
  TGraphErrors *gr613_cycletempIrrad = new TGraphErrors (counts_613 , cycleNumberArray613, avets12IrradArray613, 0 , ts12IrradErr613);

  gr613_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr613_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr613_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr613_cycletempIrrad -> SetMarkerStyle(7);
  gr613_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr613_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr613_cycletempValveOpen = new TGraphErrors (counts_613 , cycleNumberArray613, avets12ValveOpenArray613, 0 , ts12ValveOpenErr613);

  gr613_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr613_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr613_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr613_cycletempValveOpen -> SetMarkerStyle(7);
  gr613_cycletempValveOpen -> SetMarkerColor(2);
  gr613_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr613_cycletempIrrad -> Draw("AP");
  gr613_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c613_cycleNum -> cd(4);
  TGraphErrors *gr613_cyclecur = new TGraphErrors (counts_613 , cycleNumberArray613 , avecurArray613, 0, ErrcurArray613 );
  gr613_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr613_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr613_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr613_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclecur -> SetMarkerStyle(7);
  gr613_cyclecur -> Draw("Ap");


  TCanvas *c613_cycleNumFit = new TCanvas("c613_cycleNumFit" , "c613_cycleNumFit" , 1200, 800);
  c613_cycleNumFit -> Divide(2,2);

  c613_cycleNumFit -> cd(1);
  TGraphErrors *gr613_cyclefall = new TGraphErrors (counts_613, cycleNumberArray613, FallTimeArray613 , 0, FallTimeErrArray613);

  gr613_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr613_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr613_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr613_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclefall -> SetMarkerStyle(7);
  gr613_cyclefall -> Draw("Ap");


  c613_cycleNumFit -> cd(2);
  TGraphErrors *gr613_cyclebaseline = new TGraphErrors (counts_613, cycleNumberArray613, BaselineArray613 , 0, BaselineErrArray613);

  gr613_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr613_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr613_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr613_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclebaseline -> SetMarkerStyle(7);
  gr613_cyclebaseline -> Draw("Ap");

  c613_cycleNumFit -> cd(3);
  TGraphErrors *gr613_cyclebaselineirrad = new TGraphErrors (counts_613, cycleNumberArray613, BaselineIrradArray613 , 0, BaselineIrradErrArray613);

  gr613_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr613_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr613_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr613_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclebaselineirrad -> SetMarkerStyle(7);
  gr613_cyclebaselineirrad -> Draw("Ap");

  c613_cycleNumFit -> cd(4);
  TGraphErrors *gr613_cyclerise = new TGraphErrors (counts_613, cycleNumberArray613, RiseTimeArray613 , 0, RiseTimeErrArray613);

  gr613_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr613_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr613_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr613_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr613_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr613_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr613_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr613_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr613_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr613_cyclerise -> SetMarkerStyle(7);
  gr613_cyclerise -> Draw("Ap");





  /*

  double StorageAll [100] = {storage605, storage606, storage608, storage609, storage610, storage540};
  double StorageErrAll[100] = {storageErr605, storageErr606, storageErr608, storageErr608, storageErr609, storageErr610, storageErr540};
  double runNum[100] = {605, 606, 608, 609, 610, 540};
  double tempIrradAll[100] = {aveAllts12Irrad605, aveAllts12Irrad606, aveAllts12Irrad608, aveAllts12Irrad609, aveAllts12Irrad610, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad605,  aveAllErrts12Irrad606,  aveAllErrts12Irrad607,  aveAllErrts12Irrad609,  aveAllErrts12Irrad610,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_605 +counts_606 +counts_607 +counts_608 +counts_609 +counts_610 + counts_612 +counts_611 + counts_613 , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_605+counts_606 +counts_607 +counts_608 +counts_609 +counts_610 +counts_611 +counts_612+ counts_613  , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
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
