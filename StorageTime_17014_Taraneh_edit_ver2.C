//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17014.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17014_Taraneh_edit_ver2(){
  gStyle->SetOptFit(0000);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin780 = new TFile("outputTree_StorageTime_780.root","READ");
  TFile *fin781 = new TFile("outputTree_StorageTime_781.root","READ");
  TFile *fin782 = new TFile("outputTree_StorageTime_782.root","READ");
  TFile *fin783 = new TFile("outputTree_StorageTime_783.root","READ");
  TFile *fin784 = new TFile("outputTree_StorageTime_784.root","READ");
  TFile *fin785 = new TFile("outputTree_StorageTime_785.root","READ");
  TFile *fin786 = new TFile("outputTree_StorageTime_786.root","READ");

  
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




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral780;
  double UCNIntegral781;
  double UCNIntegral782;
  double UCNIntegral783;
  double UCNIntegral784;
  double UCNIntegral785;
  double UCNIntegral786;


  outputTree780 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral780);
  outputTree781 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral781);
  outputTree782 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral782);
  outputTree783 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral783);
  outputTree784 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral784);
  outputTree785 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral785);
  outputTree786 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral786);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray780 [100] = 0;
  double UCNIntegralArray781 [100];
  double UCNIntegralArray782 [100];
  double UCNIntegralArray783 [100];
  double UCNIntegralArray784 [100];
  double UCNIntegralArray785 [100];
  double UCNIntegralArray786 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr780;
  double UCNIntegralErr781;
  double UCNIntegralErr782;
  double UCNIntegralErr783;
  double UCNIntegralErr784;
  double UCNIntegralErr785;
  double UCNIntegralErr786;

  outputTree780 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr780);
  outputTree781 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr781);
  outputTree782 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr782);
  outputTree783 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr783);
  outputTree784 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr784);
  outputTree785 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr785);
  outputTree786 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr786);



  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray780 [100];
  double UCNIntegralErrArray781 [100];
  double UCNIntegralErrArray782 [100];
  double UCNIntegralErrArray783 [100];
  double UCNIntegralErrArray784 [100];
  double UCNIntegralErrArray785 [100];
  double UCNIntegralErrArray786 [100];

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


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad780;
  double avets12Irrad781;
  double avets12Irrad782;
  double avets12Irrad783;
  double avets12Irrad784;
  double avets12Irrad785;
  double avets12Irrad786;

  outputTree780 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad780);
  outputTree781 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad781);
  outputTree782 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad782);
  outputTree783 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad783);
  outputTree784 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad784);
  outputTree785 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad785);
  outputTree786 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad786);


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

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray780 [100];
  double avets12IrradArray781 [100];
  double avets12IrradArray782 [100];
  double avets12IrradArray783 [100];
  double avets12IrradArray784 [100];
  double avets12IrradArray785 [100];
  double avets12IrradArray786 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray780 [100];
  double avets12ValveOpenArray781 [100];
  double avets12ValveOpenArray782 [100];
  double avets12ValveOpenArray783 [100];
  double avets12ValveOpenArray784 [100];
  double avets12ValveOpenArray785 [100];
  double avets12ValveOpenArray786 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad780;
  double maxts12Irrad781;
  double maxts12Irrad782;
  double maxts12Irrad783;
  double maxts12Irrad784;
  double maxts12Irrad785;
  double maxts12Irrad786;

  outputTree780 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad780);
  outputTree781 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad781);
  outputTree782 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad782);
  outputTree783 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad783);
  outputTree784 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad784);
  outputTree785 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad785);
  outputTree786 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad786);

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

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray780 [100];
  double maxts12IrradArray781 [100];
  double maxts12IrradArray782 [100];
  double maxts12IrradArray783 [100];
  double maxts12IrradArray784 [100];
  double maxts12IrradArray785 [100];
  double maxts12IrradArray786 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray780 [100];
  double maxts12ValveOpenArray781 [100];
  double maxts12ValveOpenArray782 [100];
  double maxts12ValveOpenArray783 [100];
  double maxts12ValveOpenArray784 [100];
  double maxts12ValveOpenArray785 [100];
  double maxts12ValveOpenArray786 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad780;
  double mints12Irrad781;
  double mints12Irrad782;
  double mints12Irrad783;
  double mints12Irrad784;
  double mints12Irrad785;
  double mints12Irrad786;
  
  outputTree780 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad780);
  outputTree781 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad781);
  outputTree782 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad782);
  outputTree783 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad783);
  outputTree784 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad784);
  outputTree785 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad785);
  outputTree786 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad786);


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

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray780 [100];
  double mints12IrradArray781 [100];
  double mints12IrradArray782 [100];
  double mints12IrradArray783 [100];
  double mints12IrradArray784 [100];
  double mints12IrradArray785 [100];
  double mints12IrradArray786 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray780 [100];
  double mints12ValveOpenArray781 [100];
  double mints12ValveOpenArray782 [100];
  double mints12ValveOpenArray783 [100];
  double mints12ValveOpenArray784 [100];
  double mints12ValveOpenArray785 [100];
  double mints12ValveOpenArray786 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr780 [100];
  double ts12IrradErr781 [100];
  double ts12IrradErr782 [100];
  double ts12IrradErr783 [100];
  double ts12IrradErr784 [100];
  double ts12IrradErr785 [100];
  double ts12IrradErr786 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr780 [100];
  double ts12ValveOpenErr781 [100];
  double ts12ValveOpenErr782 [100];
  double ts12ValveOpenErr783 [100];
  double ts12ValveOpenErr784 [100];
  double ts12ValveOpenErr785 [100];
  double ts12ValveOpenErr786 [100];


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


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray780 [100];
  double maxcurArray781 [100];
  double maxcurArray782 [100];
  double maxcurArray783 [100];
  double maxcurArray784 [100];
  double maxcurArray785 [100];
  double maxcurArray786 [100];


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

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray780 [100];
  double mincurArray781 [100];
  double mincurArray782 [100];
  double mincurArray783 [100];
  double mincurArray784 [100];
  double mincurArray785 [100];
  double mincurArray786 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray780 [100];
  double ErrcurArray781 [100];
  double ErrcurArray782 [100];
  double ErrcurArray783 [100];
  double ErrcurArray784 [100];
  double ErrcurArray785 [100];
  double ErrcurArray786 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline780;
  double Baseline781;
  double Baseline782;
  double Baseline783;
  double Baseline784;
  double Baseline785;
  double Baseline786;

  outputTree780 -> SetBranchAddress ("Baseline" , &Baseline780);
  outputTree781 -> SetBranchAddress ("Baseline" , &Baseline781);
  outputTree782 -> SetBranchAddress ("Baseline" , &Baseline782);
  outputTree783 -> SetBranchAddress ("Baseline" , &Baseline783);
  outputTree784 -> SetBranchAddress ("Baseline" , &Baseline784);
  outputTree785 -> SetBranchAddress ("Baseline" , &Baseline785);
  outputTree786 -> SetBranchAddress ("Baseline" , &Baseline786);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray780 [100];
  double BaselineArray781 [100];
  double BaselineArray782 [100];
  double BaselineArray783 [100];
  double BaselineArray784 [100];
  double BaselineArray785 [100];
  double BaselineArray786 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr780;
  double BaselineErr781;
  double BaselineErr782;
  double BaselineErr783;
  double BaselineErr784;
  double BaselineErr785;
  double BaselineErr786;
 
  outputTree780 -> SetBranchAddress ("BaselineErr" , &BaselineErr780);
  outputTree781 -> SetBranchAddress ("BaselineErr" , &BaselineErr781);
  outputTree782 -> SetBranchAddress ("BaselineErr" , &BaselineErr782);
  outputTree783 -> SetBranchAddress ("BaselineErr" , &BaselineErr783);
  outputTree784 -> SetBranchAddress ("BaselineErr" , &BaselineErr784);
  outputTree785 -> SetBranchAddress ("BaselineErr" , &BaselineErr785);
  outputTree786 -> SetBranchAddress ("BaselineErr" , &BaselineErr786);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray780 [100];
  double BaselineErrArray781 [100];
  double BaselineErrArray782 [100];
  double BaselineErrArray783 [100];
  double BaselineErrArray784 [100];
  double BaselineErrArray785 [100];
  double BaselineErrArray786 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad780;
  double BaselineIrrad781;
  double BaselineIrrad782;
  double BaselineIrrad783;
  double BaselineIrrad784;
  double BaselineIrrad785;
  double BaselineIrrad786;
 
  outputTree780 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad780);
  outputTree781 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad781);
  outputTree782 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad782);
  outputTree783 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad783);
  outputTree784 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad784);
  outputTree785 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad785);
  outputTree786 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad786);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray780 [100];
  double BaselineIrradArray781 [100];
  double BaselineIrradArray782 [100];
  double BaselineIrradArray783 [100];
  double BaselineIrradArray784 [100];
  double BaselineIrradArray785 [100];
  double BaselineIrradArray786 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr780;
  double BaselineIrradErr781;
  double BaselineIrradErr782;
  double BaselineIrradErr783;
  double BaselineIrradErr784;
  double BaselineIrradErr785;
  double BaselineIrradErr786;

  outputTree780 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr780);
  outputTree781 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr781);
  outputTree782 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr782);
  outputTree783 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr783);
  outputTree784 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr784);
  outputTree785 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr785);
  outputTree786 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr786);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray780 [100];
  double BaselineIrradErrArray781 [100];
  double BaselineIrradErrArray782 [100];
  double BaselineIrradErrArray783 [100];
  double BaselineIrradErrArray784 [100];
  double BaselineIrradErrArray785 [100];
  double BaselineIrradErrArray786 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime780;
  double FallTime781;
  double FallTime782;
  double FallTime783;
  double FallTime784;
  double FallTime785;
  double FallTime786;

  outputTree780 -> SetBranchAddress ("FallTime" , &FallTime780);
  outputTree781 -> SetBranchAddress ("FallTime" , &FallTime781);
  outputTree782 -> SetBranchAddress ("FallTime" , &FallTime782);
  outputTree783 -> SetBranchAddress ("FallTime" , &FallTime783);
  outputTree784 -> SetBranchAddress ("FallTime" , &FallTime784);
  outputTree785 -> SetBranchAddress ("FallTime" , &FallTime785);
  outputTree786 -> SetBranchAddress ("FallTime" , &FallTime786);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray780 [100];
  double FallTimeArray781 [100];
  double FallTimeArray782 [100];
  double FallTimeArray783 [100];
  double FallTimeArray784 [100];
  double FallTimeArray785 [100];
  double FallTimeArray786 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr780;
  double FallTimeErr781;
  double FallTimeErr782;
  double FallTimeErr783;
  double FallTimeErr784;
  double FallTimeErr785;
  double FallTimeErr786;

  outputTree780 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr780);
  outputTree781 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr781);
  outputTree782 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr782);
  outputTree783 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr783);
  outputTree784 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr784);
  outputTree785 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr785);
  outputTree786 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr786);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray780 [100];
  double FallTimeErrArray781 [100];
  double FallTimeErrArray782 [100];
  double FallTimeErrArray783 [100];
  double FallTimeErrArray784 [100];
  double FallTimeErrArray785 [100];
  double FallTimeErrArray786 [100];

  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime780;
  double RiseTime781;
  double RiseTime782;
  double RiseTime783;
  double RiseTime784;
  double RiseTime785;
  double RiseTime786;

  outputTree780 -> SetBranchAddress ("RiseTime" , &RiseTime780);
  outputTree781 -> SetBranchAddress ("RiseTime" , &RiseTime781);
  outputTree782 -> SetBranchAddress ("RiseTime" , &RiseTime782);
  outputTree783 -> SetBranchAddress ("RiseTime" , &RiseTime783);
  outputTree784 -> SetBranchAddress ("RiseTime" , &RiseTime784);
  outputTree785 -> SetBranchAddress ("RiseTime" , &RiseTime785);
  outputTree786 -> SetBranchAddress ("RiseTime" , &RiseTime786);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray780 [100];
  double RiseTimeArray781 [100];
  double RiseTimeArray782 [100];
  double RiseTimeArray783 [100];
  double RiseTimeArray784 [100];
  double RiseTimeArray785 [100];
  double RiseTimeArray786 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr780;
  double RiseTimeErr781;
  double RiseTimeErr782;
  double RiseTimeErr783;
  double RiseTimeErr784;
  double RiseTimeErr785;
  double RiseTimeErr786;

  outputTree780 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr780);
  outputTree781 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr781);
  outputTree782 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr782);
  outputTree783 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr783);
  outputTree784 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr784);
  outputTree785 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr785);
  outputTree786 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr786);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray780 [100];
  double RiseTimeErrArray781 [100];
  double RiseTimeErrArray782 [100];
  double RiseTimeErrArray783 [100];
  double RiseTimeErrArray784 [100];
  double RiseTimeErrArray785 [100];
  double RiseTimeErrArray786 [100];

  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad780;
  double aveAllts12Irrad781;
  double aveAllts12Irrad782;
  double aveAllts12Irrad783;
  double aveAllts12Irrad784;
  double aveAllts12Irrad785;
  double aveAllts12Irrad786;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad780;
  double aveAllErrts12Irrad781;
  double aveAllErrts12Irrad782;
  double aveAllErrts12Irrad783;
  double aveAllErrts12Irrad784;
  double aveAllErrts12Irrad785;
  double aveAllErrts12Irrad786;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad780;
  double maxAllts12Irrad781;
  double maxAllts12Irrad782;
  double maxAllts12Irrad783;
  double maxAllts12Irrad784;
  double maxAllts12Irrad785;
  double maxAllts12Irrad786;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad780;
  double minAllts12Irrad781;
  double minAllts12Irrad782;
  double minAllts12Irrad783;
  double minAllts12Irrad784;
  double minAllts12Irrad785;
  double minAllts12Irrad786;

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
  
  // BECAUSE THE ERROR BARS FOR TGRAPHERRORS ARE DOUBLED I HAVE TO DIVIDE THE ERRORS IN HALF
  
  ULong64_t events780;
  events780 = (Double_t)outputTree780 -> GetEntries();

  for (ULong64_t j = 0 ; j < events780 ; j++){
    outputTree780 -> GetEvent(j);
    if ( j==3 || j==9)
      continue;
    UCNIntegralArray780[counts_780] = UCNIntegral780;
    UCNIntegralErrArray780[counts_780] = UCNIntegralErr780;
    HistIntegralArray780[counts_780] = HistIntegral780;
    HistIntegralErrArray780[counts_780] = sqrt (HistIntegral780);
    avets12IrradArray780[counts_780] = avets12Irrad780;
    avets12ValveOpenArray780[counts_780] = avets12ValveOpen780;
    maxts12IrradArray780[counts_780] = maxts12Irrad780;
    maxts12ValveOpenArray780[counts_780] = maxts12ValveOpen780;
    mints12IrradArray780[counts_780] = mints12Irrad780; 
    mints12ValveOpenArray780[counts_780] = mints12ValveOpen780;
    ts12IrradErr780[counts_780] = (maxts12Irrad780 - mints12Irrad780)/2;
    ts12ValveOpenErr780[counts_780] = (maxts12ValveOpen780 - mints12ValveOpen780)/2;
    avecurArray780[counts_780] = avecur780;
    maxcurArray780[counts_780] = maxcur780;
    mincurArray780[counts_780] = mincur780;
    ErrcurArray780[counts_780] = (maxcur780 - mincur780)/2;
    delaytimeArray780[counts_780] = cycleDelayTime780;
    cycleNumberArray780[counts_780] = cycleNumber780;
    BaselineArray780[counts_780] = Baseline780;
    BaselineIrradArray780[counts_780] = BaselineIrrad780;
    BaselineIrradErrArray780[counts_780] = BaselineIrradErr780;
    FallTimeArray780[counts_780] = FallTime780;
    FallTimeErrArray780[counts_780] = FallTimeErr780;
    RiseTimeArray780[counts_780] = RiseTime780;
    RiseTimeErrArray780[counts_780] = RiseTimeErr780;
    aveAllts12Irrad780 += avets12Irrad780;
    maxAllts12Irrad780 += maxts12Irrad780;
    minAllts12Irrad780 += mints12Irrad780;
    counts_780++;
  }
  aveAllts12Irrad780 = aveAllts12Irrad780/counts_780;
  maxAllts12Irrad780 = maxAllts12Irrad780/counts_780;
  minAllts12Irrad780 = minAllts12Irrad780/counts_780;
  aveAllErrts12Irrad780 = (maxAllts12Irrad780 - minAllts12Irrad780)/2;

  ULong64_t events781;
  events781 = (Double_t)outputTree781 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events781 ; j++){
    outputTree781 -> GetEvent(j);
    UCNIntegralArray781[j] = UCNIntegral781;
    UCNIntegralErrArray781[j] = UCNIntegralErr781;
    HistIntegralArray781[j] = HistIntegral781;
    HistIntegralErrArray781[j] = sqrt (HistIntegral781);
    avets12IrradArray781[j] = avets12Irrad781;
    avets12ValveOpenArray781[j] = avets12ValveOpen781;
    maxts12IrradArray781[j] = maxts12Irrad781;
    maxts12ValveOpenArray781[j] = maxts12ValveOpen781;
    mints12IrradArray781[j] = mints12Irrad781; 
    mints12ValveOpenArray781[j] = mints12ValveOpen781;
    ts12IrradErr781[j] = (maxts12Irrad781 - mints12Irrad781)/2;
    ts12ValveOpenErr781[j] = (maxts12ValveOpen781 - mints12ValveOpen781)/2;
    avecurArray781[j] = avecur781;
    maxcurArray781[j] = maxcur781;
    mincurArray781[j] = mincur781;
    ErrcurArray781[j] = (maxcur781 - mincur781)/2;
    delaytimeArray781[j] = cycleDelayTime781;
    cycleNumberArray781[j] = cycleNumber781;
    BaselineArray781[j] = Baseline781;
    BaselineIrradArray781[j] = BaselineIrrad781;
    BaselineIrradErrArray781[j] = BaselineIrradErr781;
    FallTimeArray781[j] = FallTime781;
    FallTimeErrArray781[j] = FallTimeErr781;
    RiseTimeArray781[j] = RiseTime781;
    RiseTimeErrArray781[j] = RiseTimeErr781;
    aveAllts12Irrad781 += avets12Irrad781;
    maxAllts12Irrad781 += maxts12Irrad781;
    minAllts12Irrad781 += mints12Irrad781;
    cout << aveAllts12Irrad781 << endl;
    counts_781++;
  }
  aveAllts12Irrad781 = aveAllts12Irrad781/counts_781;
  maxAllts12Irrad781 = maxAllts12Irrad781/counts_781;
  minAllts12Irrad781 = minAllts12Irrad781/counts_781;
  aveAllErrts12Irrad781 = (maxAllts12Irrad781 - minAllts12Irrad781)/2;

  ULong64_t events782;
  events782 = (Double_t)outputTree782 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events782 ; j++){
    outputTree782 -> GetEvent(j);
    if (j==4)
      continue;
    UCNIntegralArray782[counts_782] = UCNIntegral782;
    UCNIntegralErrArray782[counts_782] = UCNIntegralErr782;
    HistIntegralArray782[counts_782] = HistIntegral782;
    HistIntegralErrArray782[counts_782] = sqrt (HistIntegral782);
    avets12IrradArray782[counts_782] = avets12Irrad782;
    avets12ValveOpenArray782[counts_782] = avets12ValveOpen782;
    maxts12IrradArray782[counts_782] = maxts12Irrad782;
    maxts12ValveOpenArray782[counts_782] = maxts12ValveOpen782;
    mints12IrradArray782[counts_782] = mints12Irrad782; 
    mints12ValveOpenArray782[counts_782] = mints12ValveOpen782;
    ts12IrradErr782[counts_782] = (maxts12Irrad782 - mints12Irrad782)/2;
    ts12ValveOpenErr782[counts_782] = (maxts12ValveOpen782 - mints12ValveOpen782)/2;
    avecurArray782[counts_782] = avecur782;
    maxcurArray782[counts_782] = maxcur782;
    mincurArray782[counts_782] = mincur782;
    ErrcurArray782[counts_782] = (maxcur782 - mincur782)/2;
    delaytimeArray782[counts_782] = cycleDelayTime782;
    cycleNumberArray782[counts_782] = cycleNumber782;
    BaselineArray782[counts_782] = Baseline782;
    BaselineIrradArray782[counts_782] = BaselineIrrad782;
    BaselineIrradErrArray782[counts_782] = BaselineIrradErr782;
    FallTimeArray782[counts_782] = FallTime782;
    FallTimeErrArray782[counts_782] = FallTimeErr782;
    RiseTimeArray782[counts_782] = RiseTime782;
    RiseTimeErrArray782[counts_782] = RiseTimeErr782;
    aveAllts12Irrad782 += avets12Irrad782;
    maxAllts12Irrad782 += maxts12Irrad782;
    minAllts12Irrad782 += mints12Irrad782;
    counts_782++;
  }
  aveAllts12Irrad782 = aveAllts12Irrad782/counts_782;
  maxAllts12Irrad782 = maxAllts12Irrad782/counts_782;
  minAllts12Irrad782 = minAllts12Irrad782/counts_782;
  aveAllErrts12Irrad782 = (maxAllts12Irrad782 - minAllts12Irrad782)/2;
  
  ULong64_t events783;
  events783 = (Double_t)outputTree783 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events783 ; j++){
    outputTree783 -> GetEvent(j);
    UCNIntegralArray783[j] = UCNIntegral783;
    UCNIntegralErrArray783[j] = UCNIntegralErr783;
    HistIntegralArray783[j] = HistIntegral783;
    HistIntegralErrArray783[j] = sqrt (HistIntegral783);
    avets12IrradArray783[j] = avets12Irrad783;
    avets12ValveOpenArray783[j] = avets12ValveOpen783;
    maxts12IrradArray783[j] = maxts12Irrad783;
    maxts12ValveOpenArray783[j] = maxts12ValveOpen783;
    mints12IrradArray783[j] = mints12Irrad783; 
    mints12ValveOpenArray783[j] = mints12ValveOpen783;
    ts12IrradErr783[j] = (maxts12Irrad783 - mints12Irrad783)/2;
    ts12ValveOpenErr783[j] = (maxts12ValveOpen783 - mints12ValveOpen783)/2;
    avecurArray783[j] = avecur783;
    maxcurArray783[j] = maxcur783;
    mincurArray783[j] = mincur783;
    ErrcurArray783[j] = (maxcur783 - mincur783)/2;
    delaytimeArray783[j] = cycleDelayTime783;
    cycleNumberArray783[j] = cycleNumber783;
    BaselineArray783[j] = Baseline783;
    BaselineIrradArray783[j] = BaselineIrrad783;
    BaselineIrradErrArray783[j] = BaselineIrradErr783;
    FallTimeArray783[j] = FallTime783;
    FallTimeErrArray783[j] = FallTimeErr783;
    RiseTimeArray783[j] = RiseTime783;
    RiseTimeErrArray783[j] = RiseTimeErr783;
    aveAllts12Irrad783 += avets12Irrad783;
    maxAllts12Irrad783 += maxts12Irrad783;
    minAllts12Irrad783 += mints12Irrad783;
    counts_783++;
  }
  aveAllts12Irrad783 = aveAllts12Irrad783/counts_783;
  maxAllts12Irrad783 = maxAllts12Irrad783/counts_783;
  minAllts12Irrad783 = minAllts12Irrad783/counts_783;
  aveAllErrts12Irrad783 = (maxAllts12Irrad783 - minAllts12Irrad783)/2;
  
  ULong64_t events784;
  events784 = (Double_t)outputTree784 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events784 ; j++){
    outputTree784 -> GetEvent(j);
    UCNIntegralArray784[counts_784] = UCNIntegral784;
    UCNIntegralErrArray784[counts_784] = UCNIntegralErr784;
    HistIntegralArray784[counts_784] = HistIntegral784;
    HistIntegralErrArray784[counts_784] = sqrt (HistIntegral784);
    avets12IrradArray784[counts_784] = avets12Irrad784;
    avets12ValveOpenArray784[counts_784] = avets12ValveOpen784;
    maxts12IrradArray784[counts_784] = maxts12Irrad784;
    maxts12ValveOpenArray784[counts_784] = maxts12ValveOpen784;
    mints12IrradArray784[counts_784] = mints12Irrad784; 
    mints12ValveOpenArray784[counts_784] = mints12ValveOpen784;
    ts12IrradErr784[counts_784] = (maxts12Irrad784 - mints12Irrad784)/2;
    ts12ValveOpenErr784[counts_784] = (maxts12ValveOpen784 - mints12ValveOpen784)/2;
    avecurArray784[counts_784] = avecur784;
    maxcurArray784[counts_784] = maxcur784;
    mincurArray784[counts_784] = mincur784;
    ErrcurArray784[counts_784] = (maxcur784 - mincur784)/2;
    delaytimeArray784[counts_784] = cycleDelayTime784;
    cycleNumberArray784[counts_784] = cycleNumber784;
    BaselineArray784[counts_784] = Baseline784;
    BaselineIrradArray784[counts_784] = BaselineIrrad784;
    BaselineIrradErrArray784[counts_784] = BaselineIrradErr784;
    FallTimeArray784[counts_784] = FallTime784;
    FallTimeErrArray784[counts_784] = FallTimeErr784;
    RiseTimeArray784[counts_784] = RiseTime784;
    RiseTimeErrArray784[counts_784] = RiseTimeErr784;
    aveAllts12Irrad784 += avets12Irrad784;
    maxAllts12Irrad784 += maxts12Irrad784;
    minAllts12Irrad784 += mints12Irrad784;
    counts_784++;
  }
  aveAllts12Irrad784 = aveAllts12Irrad784/counts_784;
  maxAllts12Irrad784 = maxAllts12Irrad784/counts_784;
  minAllts12Irrad784 = minAllts12Irrad784/counts_784;
  aveAllErrts12Irrad784 = (maxAllts12Irrad784 - minAllts12Irrad784)/2;

  ULong64_t events785;
  events785 = (Double_t)outputTree785 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events785 ; j++){
    outputTree785 -> GetEvent(j);
    UCNIntegralArray785[counts_785] = UCNIntegral785;
    UCNIntegralErrArray785[counts_785] = UCNIntegralErr785;
    HistIntegralArray785[counts_785] = HistIntegral785;
    HistIntegralErrArray785[counts_785] = sqrt (HistIntegral785);
    avets12IrradArray785[counts_785] = avets12Irrad785;
    avets12ValveOpenArray785[counts_785] = avets12ValveOpen785;
    maxts12IrradArray785[counts_785] = maxts12Irrad785;
    maxts12ValveOpenArray785[counts_785] = maxts12ValveOpen785;
    mints12IrradArray785[counts_785] = mints12Irrad785; 
    mints12ValveOpenArray785[counts_785] = mints12ValveOpen785;
    ts12IrradErr785[counts_785] = (maxts12Irrad785 - mints12Irrad785)/2;
    ts12ValveOpenErr785[counts_785] = (maxts12ValveOpen785 - mints12ValveOpen785)/2;
    avecurArray785[counts_785] = avecur785;
    maxcurArray785[counts_785] = maxcur785;
    mincurArray785[counts_785] = mincur785;
    ErrcurArray785[counts_785] = (maxcur785 - mincur785)/2;
    delaytimeArray785[counts_785] = cycleDelayTime785;
    cycleNumberArray785[counts_785] = cycleNumber785;
    BaselineArray785[counts_785] = Baseline785;
    BaselineIrradArray785[counts_785] = BaselineIrrad785;
    BaselineIrradErrArray785[counts_785] = BaselineIrradErr785;
    FallTimeArray785[counts_785] = FallTime785;
    FallTimeErrArray785[counts_785] = FallTimeErr785;
    RiseTimeArray785[counts_785] = RiseTime785;
    RiseTimeErrArray785[counts_785] = RiseTimeErr785;
    aveAllts12Irrad785 += avets12Irrad785;
    maxAllts12Irrad785 += maxts12Irrad785;
    minAllts12Irrad785 += mints12Irrad785;
    counts_785++;
  }
  aveAllts12Irrad785 = aveAllts12Irrad785/counts_785;
  maxAllts12Irrad785 = maxAllts12Irrad785/counts_785;
  minAllts12Irrad785 = minAllts12Irrad785/counts_785;
  aveAllErrts12Irrad785 = (maxAllts12Irrad785 - minAllts12Irrad785)/2;

  ULong64_t events786;
  events786 = (Double_t)outputTree786 -> GetEntries();


  for (ULong64_t j = 0 ; j < events786 ; j++){
    outputTree786 -> GetEvent(j);
    UCNIntegralArray786[j] = UCNIntegral786;
    UCNIntegralErrArray786[j] = UCNIntegralErr786;
    HistIntegralArray786[j] = HistIntegral786;
    HistIntegralErrArray786[j] = sqrt (HistIntegral786);
    avets12IrradArray786[j] = avets12Irrad786;
    avets12ValveOpenArray786[j] = avets12ValveOpen786;
    maxts12IrradArray786[j] = maxts12Irrad786;
    maxts12ValveOpenArray786[j] = maxts12ValveOpen786;
    mints12IrradArray786[j] = mints12Irrad786; 
    mints12ValveOpenArray786[j] = mints12ValveOpen786;
    ts12IrradErr786[j] = (maxts12Irrad786 - mints12Irrad786)/2;
    ts12ValveOpenErr786[j] = (maxts12ValveOpen786 - mints12ValveOpen786)/2;
    avecurArray786[j] = avecur786;
    maxcurArray786[j] = maxcur786;
    mincurArray786[j] = mincur786;
    ErrcurArray786[j] = (maxcur786 - mincur786)/2;
    delaytimeArray786[j] = cycleDelayTime786;
    cycleNumberArray786[j] = cycleNumber786;
    BaselineArray786[j] = Baseline786;
    BaselineIrradArray786[j] = BaselineIrrad786;
    BaselineIrradErrArray786[j] = BaselineIrradErr786;
    FallTimeArray786[j] = FallTime786;
    FallTimeErrArray786[j] = FallTimeErr786;
    RiseTimeArray786[j] = RiseTime786;
    RiseTimeErrArray786[j] = RiseTimeErr786;
    aveAllts12Irrad786 += avets12Irrad786;
    maxAllts12Irrad786 += maxts12Irrad786;
    minAllts12Irrad786 += mints12Irrad786;
    counts_786++;
  }
  aveAllts12Irrad786 = aveAllts12Irrad786/counts_786;
  maxAllts12Irrad786 = maxAllts12Irrad786/counts_786;
  minAllts12Irrad786 = minAllts12Irrad786/counts_786;
  aveAllErrts12Irrad786 = (maxAllts12Irrad786 - minAllts12Irrad786)/2;

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
  c780 -> Divide(2,2);
  //c780 -> cd(1);
  TPad *p1 = c780->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr780_delaycounts = new TGraphErrors(counts_780, delaytimeArray780 , UCNIntegralArray780, 0, UCNIntegralErrArray780);

  gr780_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_delaycounts -> SetMarkerStyle(7);
  gr780_delaycounts -> Fit(fit);
  storage780 = fit -> GetParameter(1);
  storageErr780 = fit -> GetParError(1);
  
  TGraphErrors *gr780_delayhist = new TGraphErrors(counts_780, delaytimeArray780 , HistIntegralArray780, 0, HistIntegralErrArray780);

  gr780_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr780_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_delayhist -> SetMarkerColor(2);
  gr780_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr780_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr780_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr780_delaycounts -> Draw("Ap");
  gr780_delayhist -> Draw("p");
  leg2 -> Draw();

  //c780 -> cd(2);
  TPad *p2 = c780->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr780_tempIrradcounts = new TGraphErrors (counts_780 , avets12IrradArray780, UCNIntegralArray780 , ts12IrradErr780 , UCNIntegralErrArray780);
  gr780_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr780_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr780_tempValveOpencounts = new TGraphErrors (counts_780 , avets12ValveOpenArray780, UCNIntegralArray780 , ts12ValveOpenErr780 , UCNIntegralErrArray780);
  gr780_tempValveOpencounts -> SetMarkerStyle(7);
  gr780_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr780_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr780_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr780_tempIrradcounts -> Draw("Ap");
  gr780_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c780 -> cd(3);
  TGraphErrors *gr780_delaytempIrrad = new TGraphErrors (counts_780 , delaytimeArray780, avets12IrradArray780, 0 , ts12IrradErr780);

  gr780_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr780_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr780_delaytempIrrad -> SetMarkerStyle(7);
  gr780_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr780_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr780_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr780_delaytempValveOpen = new TGraphErrors (counts_780 , delaytimeArray780, avets12ValveOpenArray780, 0 , ts12ValveOpenErr780);

  gr780_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr780_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr780_delaytempValveOpen -> SetMarkerStyle(7);
  gr780_delaytempValveOpen -> SetMarkerColor(2);
  gr780_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr780_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr780_delaytempIrrad -> Draw("AP");
  gr780_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c780->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr780_curcounts = new TGraphErrors (counts_780 , avecurArray780, UCNIntegralArray780 , ErrcurArray780 , UCNIntegralErrArray780);
  gr780_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr780_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr780_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr780_curhist = new TGraphErrors (counts_780 , avecurArray780, UCNIntegralArray780 , ErrcurArray780 , UCNIntegralErrArray780);
  gr780_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr780_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr780_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr780_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_curhist -> SetMarkerColor(2);
  gr780_curhist -> SetMarkerStyle(7);

  gr780_curcounts -> Draw("Ap");
  gr780_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c780_cycleNum = new TCanvas("c780_cycleNum" , "c780_cycleNum" , 1200, 800);
  c780_cycleNum -> Divide(2,2);
  TPad *p5 = c780_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr780_cyclecounts = new TGraphErrors (counts_780 , cycleNumberArray780, UCNIntegralArray780, 0 , UCNIntegralErrArray780);
  gr780_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr780_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr780_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr780_cyclehist = new TGraphErrors(counts_780, cycleNumberArray780 , HistIntegralArray780, 0, HistIntegralErrArray780);

  gr780_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr780_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_cyclehist -> SetMarkerColor(2);
  gr780_cyclehist -> SetMarkerStyle(7);

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

  gr780_cycledelay -> SetMarkerStyle(7);

  gr780_cycledelay -> Draw("Ap");


  c780_cycleNum -> cd(3);
  TGraphErrors *gr780_cycletempIrrad = new TGraphErrors (counts_780 , cycleNumberArray780, avets12IrradArray780, 0 , ts12IrradErr780);

  gr780_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempIrrad -> SetMarkerStyle(7);
  gr780_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr780_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr780_cycletempValveOpen = new TGraphErrors (counts_780 , cycleNumberArray780, avets12ValveOpenArray780, 0 , ts12ValveOpenErr780);

  gr780_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempValveOpen -> SetMarkerStyle(7);
  gr780_cycletempValveOpen -> SetMarkerColor(2);
  gr780_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr780_cycletempIrrad -> Draw("AP");
  gr780_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr780_cyclecur -> SetMarkerStyle(7);
  gr780_cyclecur -> Draw("Ap");


  TCanvas *c780_cycleNumFit = new TCanvas("c780_cycleNumFit" , "c780_cycleNumFit" , 1200, 800);
  c780_cycleNumFit -> Divide(2,2);

  c780_cycleNumFit -> cd(1);
  TGraphErrors *gr780_cyclefall = new TGraphErrors (counts_780, cycleNumberArray780, FallTimeArray780 , 0, FallTimeErrArray780);

  gr780_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr780_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr780_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclefall -> SetMarkerStyle(7);
  gr780_cyclefall -> Draw("Ap");


  c780_cycleNumFit -> cd(2);
  TGraphErrors *gr780_cyclebaseline = new TGraphErrors (counts_780, cycleNumberArray780, BaselineArray780 , 0, BaselineErrArray780);

  gr780_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr780_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr780_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclebaseline -> SetMarkerStyle(7);
  gr780_cyclebaseline -> Draw("Ap");

  c780_cycleNumFit -> cd(3);
  TGraphErrors *gr780_cyclebaselineirrad = new TGraphErrors (counts_780, cycleNumberArray780, BaselineIrradArray780 , 0, BaselineIrradErrArray780);

  gr780_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr780_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr780_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclebaselineirrad -> SetMarkerStyle(7);
  gr780_cyclebaselineirrad -> Draw("Ap");

  c780_cycleNumFit -> cd(4);
  TGraphErrors *gr780_cyclerise = new TGraphErrors (counts_780, cycleNumberArray780, RiseTimeArray780 , 0, RiseTimeErrArray780);

  gr780_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr780_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr780_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclerise -> SetMarkerStyle(7);
  gr780_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              781
  //*********************************
  //*********************************
  TCanvas *c781 = new TCanvas("c781" , "c781" , 1200, 800);
  c781 -> Divide(2,2);
  //c781 -> cd(1);
  TPad *p781_1 = c781->cd(1);
  p781_1->SetLogy(); 
  TGraphErrors *gr781_delaycounts = new TGraphErrors(counts_781, delaytimeArray781 , UCNIntegralArray781, 0, UCNIntegralErrArray781);

  gr781_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr781_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr781_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_delaycounts -> SetMarkerStyle(7);
  gr781_delaycounts -> Fit(fit);
  storage781 = fit -> GetParameter(1);
  storageErr781 = fit -> GetParError(1);
  
  TGraphErrors *gr781_delayhist = new TGraphErrors(counts_781, delaytimeArray781 , HistIntegralArray781, 0, HistIntegralErrArray781);

  gr781_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr781_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr781_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr781_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr781_delayhist -> SetMarkerColor(2);
  gr781_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr781_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr781_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr781_delaycounts -> Draw("Ap");
  gr781_delayhist -> Draw("p");
  leg2 -> Draw();

  //c781 -> cd(2);
  TPad *p781_2 = c781->cd(2);
  p781_2->SetLogy(); 
  TGraphErrors *gr781_tempIrradcounts = new TGraphErrors (counts_781 , avets12IrradArray781, UCNIntegralArray781 , ts12IrradErr781 , UCNIntegralErrArray781);
  gr781_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr781_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.10);
  gr781_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr781_tempValveOpencounts = new TGraphErrors (counts_781 , avets12ValveOpenArray781, UCNIntegralArray781 , ts12ValveOpenErr781 , UCNIntegralErrArray781);
  gr781_tempValveOpencounts -> SetMarkerStyle(7);
  gr781_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr781_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr781_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr781_tempIrradcounts -> Draw("Ap");
  gr781_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c781 -> cd(3);
  TGraphErrors *gr781_delaytempIrrad = new TGraphErrors (counts_781 , delaytimeArray781, avets12IrradArray781, 0 , ts12IrradErr781);

  gr781_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr781_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr781_delaytempIrrad -> SetMarkerStyle(7);
  gr781_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.1);
  gr781_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr781_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr781_delaytempValveOpen = new TGraphErrors (counts_781 , delaytimeArray781, avets12ValveOpenArray781, 0 , ts12ValveOpenErr781);

  gr781_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr781_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr781_delaytempValveOpen -> SetMarkerStyle(7);
  gr781_delaytempValveOpen -> SetMarkerColor(2);
  gr781_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr781_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr781_delaytempIrrad -> Draw("AP");
  gr781_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p781_3 = c781->cd(4);
  p781_3->SetLogy(); 
  TGraphErrors *gr781_curcounts = new TGraphErrors (counts_781 , avecurArray781, UCNIntegralArray781 , ErrcurArray781 , UCNIntegralErrArray781);
  gr781_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr781_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr781_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr781_curhist = new TGraphErrors (counts_781 , avecurArray781, UCNIntegralArray781 , ErrcurArray781 , UCNIntegralErrArray781);
  gr781_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr781_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr781_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr781_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr781_curhist -> SetMarkerColor(2);
  gr781_curhist -> SetMarkerStyle(7);

  gr781_curcounts -> Draw("Ap");
  gr781_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c781_cycleNum = new TCanvas("c781_cycleNum" , "c781_cycleNum" , 1200, 800);
  c781_cycleNum -> Divide(2,2);
  TPad *p781_4 = c781_cycleNum->cd(1);
  p781_4->SetLogy(); 
  TGraphErrors *gr781_cyclecounts = new TGraphErrors (counts_781 , cycleNumberArray781, UCNIntegralArray781, 0 , UCNIntegralErrArray781);
  gr781_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr781_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr781_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr781_cyclehist = new TGraphErrors(counts_781, cycleNumberArray781 , HistIntegralArray781, 0, HistIntegralErrArray781);

  gr781_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr781_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr781_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr781_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr781_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr781_cyclehist -> SetMarkerColor(2);
  gr781_cyclehist -> SetMarkerStyle(7);

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

  gr781_cycledelay -> SetMarkerStyle(7);

  gr781_cycledelay -> Draw("Ap");


  c781_cycleNum -> cd(3);
  TGraphErrors *gr781_cycletempIrrad = new TGraphErrors (counts_781 , cycleNumberArray781, avets12IrradArray781, 0 , ts12IrradErr781);

  gr781_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempIrrad -> SetMarkerStyle(7);
  gr781_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.9, 1.1);
  gr781_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr781_cycletempValveOpen = new TGraphErrors (counts_781 , cycleNumberArray781, avets12ValveOpenArray781, 0 , ts12ValveOpenErr781);

  gr781_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr781_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr781_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr781_cycletempValveOpen -> SetMarkerStyle(7);
  gr781_cycletempValveOpen -> SetMarkerColor(2);
  gr781_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr781_cycletempIrrad -> Draw("AP");
  gr781_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr781_cyclecur -> SetMarkerStyle(7);
  gr781_cyclecur -> Draw("Ap");


  TCanvas *c781_cycleNumFit = new TCanvas("c781_cycleNumFit" , "c781_cycleNumFit" , 1200, 800);
  c781_cycleNumFit -> Divide(2,2);

  c781_cycleNumFit -> cd(1);
  TGraphErrors *gr781_cyclefall = new TGraphErrors (counts_781, cycleNumberArray781, FallTimeArray781 , 0, FallTimeErrArray781);

  gr781_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr781_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr781_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr781_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclefall -> SetMarkerStyle(7);
  gr781_cyclefall -> Draw("Ap");


  c781_cycleNumFit -> cd(2);
  TGraphErrors *gr781_cyclebaseline = new TGraphErrors (counts_781, cycleNumberArray781, BaselineArray781 , 0, BaselineErrArray781);

  gr781_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr781_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr781_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr781_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclebaseline -> SetMarkerStyle(7);
  gr781_cyclebaseline -> Draw("Ap");

  c781_cycleNumFit -> cd(3);
  TGraphErrors *gr781_cyclebaselineirrad = new TGraphErrors (counts_781, cycleNumberArray781, BaselineIrradArray781 , 0, BaselineIrradErrArray781);

  gr781_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr781_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr781_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr781_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclebaselineirrad -> SetMarkerStyle(7);
  gr781_cyclebaselineirrad -> Draw("Ap");

  c781_cycleNumFit -> cd(4);
  TGraphErrors *gr781_cyclerise = new TGraphErrors (counts_781, cycleNumberArray781, RiseTimeArray781 , 0, RiseTimeErrArray781);

  gr781_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr781_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr781_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr781_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr781_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr781_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr781_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr781_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr781_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr781_cyclerise -> SetMarkerStyle(7);
  gr781_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              782
  //*********************************
  //*********************************
  TCanvas *c782 = new TCanvas("c782" , "c782" , 1200, 800);
  c782 -> Divide(2,2);
  //c782 -> cd(1);
  TPad *p782_1 = c782->cd(1);
  p782_1->SetLogy(); 
  TGraphErrors *gr782_delaycounts = new TGraphErrors(counts_782, delaytimeArray782 , UCNIntegralArray782, 0, UCNIntegralErrArray782);

  gr782_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr782_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr782_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_delaycounts -> SetMarkerStyle(7);
  gr782_delaycounts -> Fit(fit);
  storage782 = fit -> GetParameter(1);
  storageErr782 = fit -> GetParError(1);
  
  TGraphErrors *gr782_delayhist = new TGraphErrors(counts_782, delaytimeArray782 , HistIntegralArray782, 0, HistIntegralErrArray782);

  gr782_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr782_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr782_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr782_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr782_delayhist -> SetMarkerColor(2);
  gr782_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr782_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr782_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr782_delaycounts -> Draw("Ap");
  gr782_delayhist -> Draw("p");
  leg2 -> Draw();

  //c782 -> cd(2);
  TPad *p782_2 = c782->cd(2);
  p782_2->SetLogy(); 
  TGraphErrors *gr782_tempIrradcounts = new TGraphErrors (counts_782 , avets12IrradArray782, UCNIntegralArray782 , ts12IrradErr782 , UCNIntegralErrArray782);
  gr782_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr782_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.10);
  gr782_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr782_tempValveOpencounts = new TGraphErrors (counts_782 , avets12ValveOpenArray782, UCNIntegralArray782 , ts12ValveOpenErr782 , UCNIntegralErrArray782);
  gr782_tempValveOpencounts -> SetMarkerStyle(7);
  gr782_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr782_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr782_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr782_tempIrradcounts -> Draw("Ap");
  gr782_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c782 -> cd(3);
  TGraphErrors *gr782_delaytempIrrad = new TGraphErrors (counts_782 , delaytimeArray782, avets12IrradArray782, 0 , ts12IrradErr782);

  gr782_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr782_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr782_delaytempIrrad -> SetMarkerStyle(7);
  gr782_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.1);
  gr782_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr782_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr782_delaytempValveOpen = new TGraphErrors (counts_782 , delaytimeArray782, avets12ValveOpenArray782, 0 , ts12ValveOpenErr782);

  gr782_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr782_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr782_delaytempValveOpen -> SetMarkerStyle(7);
  gr782_delaytempValveOpen -> SetMarkerColor(2);
  gr782_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr782_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr782_delaytempIrrad -> Draw("AP");
  gr782_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p782_3 = c782->cd(4);
  p782_3->SetLogy(); 
  TGraphErrors *gr782_curcounts = new TGraphErrors (counts_782 , avecurArray782, UCNIntegralArray782 , ErrcurArray782 , UCNIntegralErrArray782);
  gr782_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr782_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr782_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr782_curhist = new TGraphErrors (counts_782 , avecurArray782, UCNIntegralArray782 , ErrcurArray782 , UCNIntegralErrArray782);
  gr782_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr782_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr782_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr782_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr782_curhist -> SetMarkerColor(2);
  gr782_curhist -> SetMarkerStyle(7);

  gr782_curcounts -> Draw("Ap");
  gr782_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c782_cycleNum = new TCanvas("c782_cycleNum" , "c782_cycleNum" , 1200, 800);
  c782_cycleNum -> Divide(2,2);
  TPad *p782_4 = c782_cycleNum->cd(1);
  p782_4->SetLogy(); 
  TGraphErrors *gr782_cyclecounts = new TGraphErrors (counts_782 , cycleNumberArray782, UCNIntegralArray782, 0 , UCNIntegralErrArray782);
  gr782_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr782_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr782_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr782_cyclehist = new TGraphErrors(counts_782, cycleNumberArray782 , HistIntegralArray782, 0, HistIntegralErrArray782);

  gr782_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr782_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr782_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr782_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr782_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr782_cyclehist -> SetMarkerColor(2);
  gr782_cyclehist -> SetMarkerStyle(7);

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

  gr782_cycledelay -> SetMarkerStyle(7);

  gr782_cycledelay -> Draw("Ap");


  c782_cycleNum -> cd(3);
  TGraphErrors *gr782_cycletempIrrad = new TGraphErrors (counts_782 , cycleNumberArray782, avets12IrradArray782, 0 , ts12IrradErr782);

  gr782_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempIrrad -> SetMarkerStyle(7);
  gr782_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.9, 1.1);
  gr782_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr782_cycletempValveOpen = new TGraphErrors (counts_782 , cycleNumberArray782, avets12ValveOpenArray782, 0 , ts12ValveOpenErr782);

  gr782_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr782_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr782_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr782_cycletempValveOpen -> SetMarkerStyle(7);
  gr782_cycletempValveOpen -> SetMarkerColor(2);
  gr782_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr782_cycletempIrrad -> Draw("AP");
  gr782_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr782_cyclecur -> SetMarkerStyle(7);
  gr782_cyclecur -> Draw("Ap");


  TCanvas *c782_cycleNumFit = new TCanvas("c782_cycleNumFit" , "c782_cycleNumFit" , 1200, 800);
  c782_cycleNumFit -> Divide(2,2);

  c782_cycleNumFit -> cd(1);
  TGraphErrors *gr782_cyclefall = new TGraphErrors (counts_782, cycleNumberArray782, FallTimeArray782 , 0, FallTimeErrArray782);

  gr782_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr782_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr782_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr782_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclefall -> SetMarkerStyle(7);
  gr782_cyclefall -> Draw("Ap");


  c782_cycleNumFit -> cd(2);
  TGraphErrors *gr782_cyclebaseline = new TGraphErrors (counts_782, cycleNumberArray782, BaselineArray782 , 0, BaselineErrArray782);

  gr782_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr782_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr782_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr782_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclebaseline -> SetMarkerStyle(7);
  gr782_cyclebaseline -> Draw("Ap");

  c782_cycleNumFit -> cd(3);
  TGraphErrors *gr782_cyclebaselineirrad = new TGraphErrors (counts_782, cycleNumberArray782, BaselineIrradArray782 , 0, BaselineIrradErrArray782);

  gr782_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr782_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr782_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr782_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclebaselineirrad -> SetMarkerStyle(7);
  gr782_cyclebaselineirrad -> Draw("Ap");

  c782_cycleNumFit -> cd(4);
  TGraphErrors *gr782_cyclerise = new TGraphErrors (counts_782, cycleNumberArray782, RiseTimeArray782 , 0, RiseTimeErrArray782);

  gr782_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr782_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr782_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr782_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr782_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr782_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr782_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr782_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr782_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr782_cyclerise -> SetMarkerStyle(7);
  gr782_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              784
  //*********************************
  //*********************************
  TCanvas *c784 = new TCanvas("c784" , "c784" , 1200, 800);
  c784 -> Divide(2,2);
  //c784 -> cd(1);
  TPad *p784_1 = c784->cd(1);
  p784_1->SetLogy(); 
  TGraphErrors *gr784_delaycounts = new TGraphErrors(counts_784, delaytimeArray784 , UCNIntegralArray784, 0, UCNIntegralErrArray784);

  gr784_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr784_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr784_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_delaycounts -> SetMarkerStyle(7);
  gr784_delaycounts -> Fit(fit);
  storage784 = fit -> GetParameter(1);
  storageErr784 = fit -> GetParError(1);
  
  TGraphErrors *gr784_delayhist = new TGraphErrors(counts_784, delaytimeArray784 , HistIntegralArray784, 0, HistIntegralErrArray784);

  gr784_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr784_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr784_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr784_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr784_delayhist -> SetMarkerColor(2);
  gr784_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr784_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr784_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr784_delaycounts -> Draw("Ap");
  gr784_delayhist -> Draw("p");
  leg2 -> Draw();

  //c784 -> cd(2);
  TPad *p784_2 = c784->cd(2);
  p784_2->SetLogy(); 
  TGraphErrors *gr784_tempIrradcounts = new TGraphErrors (counts_784 , avets12IrradArray784, UCNIntegralArray784 , ts12IrradErr784 , UCNIntegralErrArray784);
  gr784_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr784_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr784_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr784_tempValveOpencounts = new TGraphErrors (counts_784 , avets12ValveOpenArray784, UCNIntegralArray784 , ts12ValveOpenErr784 , UCNIntegralErrArray784);
  gr784_tempValveOpencounts -> SetMarkerStyle(7);
  gr784_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr784_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr784_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr784_tempIrradcounts -> Draw("Ap");
  gr784_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c784 -> cd(3);
  TGraphErrors *gr784_delaytempIrrad = new TGraphErrors (counts_784 , delaytimeArray784, avets12IrradArray784, 0 , ts12IrradErr784);

  gr784_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr784_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr784_delaytempIrrad -> SetMarkerStyle(7);
  gr784_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr784_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr784_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr784_delaytempValveOpen = new TGraphErrors (counts_784 , delaytimeArray784, avets12ValveOpenArray784, 0 , ts12ValveOpenErr784);

  gr784_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr784_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr784_delaytempValveOpen -> SetMarkerStyle(7);
  gr784_delaytempValveOpen -> SetMarkerColor(2);
  gr784_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr784_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr784_delaytempIrrad -> Draw("AP");
  gr784_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p784_3 = c784->cd(4);
  p784_3->SetLogy(); 
  TGraphErrors *gr784_curcounts = new TGraphErrors (counts_784 , avecurArray784, UCNIntegralArray784 , ErrcurArray784 , UCNIntegralErrArray784);
  gr784_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr784_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr784_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr784_curhist = new TGraphErrors (counts_784 , avecurArray784, UCNIntegralArray784 , ErrcurArray784 , UCNIntegralErrArray784);
  gr784_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr784_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr784_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr784_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr784_curhist -> SetMarkerColor(2);
  gr784_curhist -> SetMarkerStyle(7);

  gr784_curcounts -> Draw("Ap");
  gr784_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c784_cycleNum = new TCanvas("c784_cycleNum" , "c784_cycleNum" , 1200, 800);
  c784_cycleNum -> Divide(2,2);
  TPad *p784_4 = c784_cycleNum->cd(1);
  p784_4->SetLogy(); 
  TGraphErrors *gr784_cyclecounts = new TGraphErrors (counts_784 , cycleNumberArray784, UCNIntegralArray784, 0 , UCNIntegralErrArray784);
  gr784_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr784_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr784_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr784_cyclehist = new TGraphErrors(counts_784, cycleNumberArray784 , HistIntegralArray784, 0, HistIntegralErrArray784);

  gr784_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr784_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr784_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr784_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr784_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr784_cyclehist -> SetMarkerColor(2);
  gr784_cyclehist -> SetMarkerStyle(7);

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

  gr784_cycledelay -> SetMarkerStyle(7);

  gr784_cycledelay -> Draw("Ap");


  c784_cycleNum -> cd(3);
  TGraphErrors *gr784_cycletempIrrad = new TGraphErrors (counts_784 , cycleNumberArray784, avets12IrradArray784, 0 , ts12IrradErr784);

  gr784_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempIrrad -> SetMarkerStyle(7);
  gr784_cycletempIrrad -> GetYaxis()-> SetRangeUser(1.1, 1.5);
  gr784_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr784_cycletempValveOpen = new TGraphErrors (counts_784 , cycleNumberArray784, avets12ValveOpenArray784, 0 , ts12ValveOpenErr784);

  gr784_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr784_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr784_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr784_cycletempValveOpen -> SetMarkerStyle(7);
  gr784_cycletempValveOpen -> SetMarkerColor(2);
  gr784_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr784_cycletempIrrad -> Draw("AP");
  gr784_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr784_cyclecur -> SetMarkerStyle(7);
  gr784_cyclecur -> Draw("Ap");


  TCanvas *c784_cycleNumFit = new TCanvas("c784_cycleNumFit" , "c784_cycleNumFit" , 1200, 800);
  c784_cycleNumFit -> Divide(2,2);

  c784_cycleNumFit -> cd(1);
  TGraphErrors *gr784_cyclefall = new TGraphErrors (counts_784, cycleNumberArray784, FallTimeArray784 , 0, FallTimeErrArray784);

  gr784_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr784_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr784_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr784_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclefall -> SetMarkerStyle(7);
  gr784_cyclefall -> Draw("Ap");


  c784_cycleNumFit -> cd(2);
  TGraphErrors *gr784_cyclebaseline = new TGraphErrors (counts_784, cycleNumberArray784, BaselineArray784 , 0, BaselineErrArray784);

  gr784_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr784_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr784_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr784_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclebaseline -> SetMarkerStyle(7);
  gr784_cyclebaseline -> Draw("Ap");

  c784_cycleNumFit -> cd(3);
  TGraphErrors *gr784_cyclebaselineirrad = new TGraphErrors (counts_784, cycleNumberArray784, BaselineIrradArray784 , 0, BaselineIrradErrArray784);

  gr784_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr784_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr784_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr784_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclebaselineirrad -> SetMarkerStyle(7);
  gr784_cyclebaselineirrad -> Draw("Ap");

  c784_cycleNumFit -> cd(4);
  TGraphErrors *gr784_cyclerise = new TGraphErrors (counts_784, cycleNumberArray784, RiseTimeArray784 , 0, RiseTimeErrArray784);

  gr784_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr784_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr784_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr784_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr784_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr784_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr784_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr784_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr784_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr784_cyclerise -> SetMarkerStyle(7);
  gr784_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              785
  //*********************************
  //*********************************
  TCanvas *c785 = new TCanvas("c785" , "c785" , 1200, 800);
  c785 -> Divide(2,2);
  //c785 -> cd(1);
  TPad *p785_1 = c785->cd(1);
  p785_1->SetLogy(); 
  TGraphErrors *gr785_delaycounts = new TGraphErrors(counts_785, delaytimeArray785 , UCNIntegralArray785, 0, UCNIntegralErrArray785);

  gr785_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr785_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr785_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_delaycounts -> SetMarkerStyle(7);
  gr785_delaycounts -> Fit(fit);
  storage785 = fit -> GetParameter(1);
  storageErr785 = fit -> GetParError(1);
  
  TGraphErrors *gr785_delayhist = new TGraphErrors(counts_785, delaytimeArray785 , HistIntegralArray785, 0, HistIntegralErrArray785);

  gr785_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr785_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr785_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr785_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr785_delayhist -> SetMarkerColor(2);
  gr785_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr785_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr785_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr785_delaycounts -> Draw("Ap");
  gr785_delayhist -> Draw("p");
  leg2 -> Draw();

  //c785 -> cd(2);
  TPad *p785_2 = c785->cd(2);
  p785_2->SetLogy(); 
  TGraphErrors *gr785_tempIrradcounts = new TGraphErrors (counts_785 , avets12IrradArray785, UCNIntegralArray785 , ts12IrradErr785 , UCNIntegralErrArray785);
  gr785_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr785_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr785_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr785_tempValveOpencounts = new TGraphErrors (counts_785 , avets12ValveOpenArray785, UCNIntegralArray785 , ts12ValveOpenErr785 , UCNIntegralErrArray785);
  gr785_tempValveOpencounts -> SetMarkerStyle(7);
  gr785_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr785_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr785_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr785_tempIrradcounts -> Draw("Ap");
  gr785_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c785 -> cd(3);
  TGraphErrors *gr785_delaytempIrrad = new TGraphErrors (counts_785 , delaytimeArray785, avets12IrradArray785, 0 , ts12IrradErr785);

  gr785_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr785_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr785_delaytempIrrad -> SetMarkerStyle(7);
  gr785_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr785_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr785_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr785_delaytempValveOpen = new TGraphErrors (counts_785 , delaytimeArray785, avets12ValveOpenArray785, 0 , ts12ValveOpenErr785);

  gr785_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr785_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr785_delaytempValveOpen -> SetMarkerStyle(7);
  gr785_delaytempValveOpen -> SetMarkerColor(2);
  gr785_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr785_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr785_delaytempIrrad -> Draw("AP");
  gr785_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p785_3 = c785->cd(4);
  p785_3->SetLogy(); 
  TGraphErrors *gr785_curcounts = new TGraphErrors (counts_785 , avecurArray785, UCNIntegralArray785 , ErrcurArray785 , UCNIntegralErrArray785);
  gr785_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr785_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr785_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr785_curhist = new TGraphErrors (counts_785 , avecurArray785, UCNIntegralArray785 , ErrcurArray785 , UCNIntegralErrArray785);
  gr785_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr785_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr785_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr785_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr785_curhist -> SetMarkerColor(2);
  gr785_curhist -> SetMarkerStyle(7);

  gr785_curcounts -> Draw("Ap");
  gr785_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c785_cycleNum = new TCanvas("c785_cycleNum" , "c785_cycleNum" , 1200, 800);
  c785_cycleNum -> Divide(2,2);
  TPad *p785_4 = c785_cycleNum->cd(1);
  p785_4->SetLogy(); 
  TGraphErrors *gr785_cyclecounts = new TGraphErrors (counts_785 , cycleNumberArray785, UCNIntegralArray785, 0 , UCNIntegralErrArray785);
  gr785_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr785_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr785_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr785_cyclehist = new TGraphErrors(counts_785, cycleNumberArray785 , HistIntegralArray785, 0, HistIntegralErrArray785);

  gr785_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr785_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr785_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr785_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr785_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr785_cyclehist -> SetMarkerColor(2);
  gr785_cyclehist -> SetMarkerStyle(7);

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

  gr785_cycledelay -> SetMarkerStyle(7);

  gr785_cycledelay -> Draw("Ap");


  c785_cycleNum -> cd(3);
  TGraphErrors *gr785_cycletempIrrad = new TGraphErrors (counts_785 , cycleNumberArray785, avets12IrradArray785, 0 , ts12IrradErr785);

  gr785_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempIrrad -> SetMarkerStyle(7);
  gr785_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.9, 1.3);
  gr785_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr785_cycletempValveOpen = new TGraphErrors (counts_785 , cycleNumberArray785, avets12ValveOpenArray785, 0 , ts12ValveOpenErr785);

  gr785_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr785_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr785_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr785_cycletempValveOpen -> SetMarkerStyle(7);
  gr785_cycletempValveOpen -> SetMarkerColor(2);
  gr785_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr785_cycletempIrrad -> Draw("AP");
  gr785_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr785_cyclecur -> SetMarkerStyle(7);
  gr785_cyclecur -> Draw("Ap");


  TCanvas *c785_cycleNumFit = new TCanvas("c785_cycleNumFit" , "c785_cycleNumFit" , 1200, 800);
  c785_cycleNumFit -> Divide(2,2);

  c785_cycleNumFit -> cd(1);
  TGraphErrors *gr785_cyclefall = new TGraphErrors (counts_785, cycleNumberArray785, FallTimeArray785 , 0, FallTimeErrArray785);

  gr785_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr785_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr785_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr785_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclefall -> SetMarkerStyle(7);
  gr785_cyclefall -> Draw("Ap");


  c785_cycleNumFit -> cd(2);
  TGraphErrors *gr785_cyclebaseline = new TGraphErrors (counts_785, cycleNumberArray785, BaselineArray785 , 0, BaselineErrArray785);

  gr785_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr785_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr785_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr785_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclebaseline -> SetMarkerStyle(7);
  gr785_cyclebaseline -> Draw("Ap");

  c785_cycleNumFit -> cd(3);
  TGraphErrors *gr785_cyclebaselineirrad = new TGraphErrors (counts_785, cycleNumberArray785, BaselineIrradArray785 , 0, BaselineIrradErrArray785);

  gr785_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr785_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr785_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr785_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclebaselineirrad -> SetMarkerStyle(7);
  gr785_cyclebaselineirrad -> Draw("Ap");

  c785_cycleNumFit -> cd(4);
  TGraphErrors *gr785_cyclerise = new TGraphErrors (counts_785, cycleNumberArray785, RiseTimeArray785 , 0, RiseTimeErrArray785);

  gr785_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr785_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr785_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr785_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr785_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr785_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr785_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr785_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr785_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr785_cyclerise -> SetMarkerStyle(7);
  gr785_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              786
  //*********************************
  //*********************************
  TCanvas *c786 = new TCanvas("c786" , "c786" , 1200, 800);
  c786 -> Divide(2,2);
  //c786 -> cd(1);
  TPad *p786_1 = c786->cd(1);
  p786_1->SetLogy(); 
  TGraphErrors *gr786_delaycounts = new TGraphErrors(counts_786, delaytimeArray786 , UCNIntegralArray786, 0, UCNIntegralErrArray786);

  gr786_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr786_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr786_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_delaycounts -> SetMarkerStyle(7);
  gr786_delaycounts -> Fit(fit);
  storage786 = fit -> GetParameter(1);
  storageErr786 = fit -> GetParError(1);
  
  TGraphErrors *gr786_delayhist = new TGraphErrors(counts_786, delaytimeArray786 , HistIntegralArray786, 0, HistIntegralErrArray786);

  gr786_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr786_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr786_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr786_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr786_delayhist -> SetMarkerColor(2);
  gr786_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr786_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr786_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr786_delaycounts -> Draw("Ap");
  gr786_delayhist -> Draw("p");
  leg2 -> Draw();

  //c786 -> cd(2);
  TPad *p786_2 = c786->cd(2);
  p786_2->SetLogy(); 
  TGraphErrors *gr786_tempIrradcounts = new TGraphErrors (counts_786 , avets12IrradArray786, UCNIntegralArray786 , ts12IrradErr786 , UCNIntegralErrArray786);
  gr786_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr786_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.4);
  gr786_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr786_tempValveOpencounts = new TGraphErrors (counts_786 , avets12ValveOpenArray786, UCNIntegralArray786 , ts12ValveOpenErr786 , UCNIntegralErrArray786);
  gr786_tempValveOpencounts -> SetMarkerStyle(7);
  gr786_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr786_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr786_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr786_tempIrradcounts -> Draw("Ap");
  gr786_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c786 -> cd(3);
  TGraphErrors *gr786_delaytempIrrad = new TGraphErrors (counts_786 , delaytimeArray786, avets12IrradArray786, 0 , ts12IrradErr786);

  gr786_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr786_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr786_delaytempIrrad -> SetMarkerStyle(7);
  gr786_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.4);
  gr786_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr786_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr786_delaytempValveOpen = new TGraphErrors (counts_786 , delaytimeArray786, avets12ValveOpenArray786, 0 , ts12ValveOpenErr786);

  gr786_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr786_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr786_delaytempValveOpen -> SetMarkerStyle(7);
  gr786_delaytempValveOpen -> SetMarkerColor(2);
  gr786_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr786_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr786_delaytempIrrad -> Draw("AP");
  gr786_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p786_3 = c786->cd(4);
  p786_3->SetLogy(); 
  TGraphErrors *gr786_curcounts = new TGraphErrors (counts_786 , avecurArray786, UCNIntegralArray786 , ErrcurArray786 , UCNIntegralErrArray786);
  gr786_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr786_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr786_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr786_curhist = new TGraphErrors (counts_786 , avecurArray786, UCNIntegralArray786 , ErrcurArray786 , UCNIntegralErrArray786);
  gr786_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr786_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr786_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr786_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr786_curhist -> SetMarkerColor(2);
  gr786_curhist -> SetMarkerStyle(7);

  gr786_curcounts -> Draw("Ap");
  gr786_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c786_cycleNum = new TCanvas("c786_cycleNum" , "c786_cycleNum" , 1200, 800);
  c786_cycleNum -> Divide(2,2);
  TPad *p786_4 = c786_cycleNum->cd(1);
  p786_4->SetLogy(); 
  TGraphErrors *gr786_cyclecounts = new TGraphErrors (counts_786 , cycleNumberArray786, UCNIntegralArray786, 0 , UCNIntegralErrArray786);
  gr786_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr786_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr786_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr786_cyclehist = new TGraphErrors(counts_786, cycleNumberArray786 , HistIntegralArray786, 0, HistIntegralErrArray786);

  gr786_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr786_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr786_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr786_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr786_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr786_cyclehist -> SetMarkerColor(2);
  gr786_cyclehist -> SetMarkerStyle(7);

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

  gr786_cycledelay -> SetMarkerStyle(7);

  gr786_cycledelay -> Draw("Ap");


  c786_cycleNum -> cd(3);
  TGraphErrors *gr786_cycletempIrrad = new TGraphErrors (counts_786 , cycleNumberArray786, avets12IrradArray786, 0 , ts12IrradErr786);

  gr786_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempIrrad -> SetMarkerStyle(7);
  gr786_cycletempIrrad -> GetYaxis()-> SetRangeUser(1.1, 1.4);
  gr786_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr786_cycletempValveOpen = new TGraphErrors (counts_786 , cycleNumberArray786, avets12ValveOpenArray786, 0 , ts12ValveOpenErr786);

  gr786_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr786_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr786_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr786_cycletempValveOpen -> SetMarkerStyle(7);
  gr786_cycletempValveOpen -> SetMarkerColor(2);
  gr786_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr786_cycletempIrrad -> Draw("AP");
  gr786_cycletempValveOpen -> Draw("p");
  leg -> Draw();

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

  gr786_cyclecur -> SetMarkerStyle(7);
  gr786_cyclecur -> Draw("Ap");


  TCanvas *c786_cycleNumFit = new TCanvas("c786_cycleNumFit" , "c786_cycleNumFit" , 1200, 800);
  c786_cycleNumFit -> Divide(2,2);

  c786_cycleNumFit -> cd(1);
  TGraphErrors *gr786_cyclefall = new TGraphErrors (counts_786, cycleNumberArray786, FallTimeArray786 , 0, FallTimeErrArray786);

  gr786_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr786_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr786_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr786_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclefall -> SetMarkerStyle(7);
  gr786_cyclefall -> Draw("Ap");


  c786_cycleNumFit -> cd(2);
  TGraphErrors *gr786_cyclebaseline = new TGraphErrors (counts_786, cycleNumberArray786, BaselineArray786 , 0, BaselineErrArray786);

  gr786_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr786_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr786_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr786_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclebaseline -> SetMarkerStyle(7);
  gr786_cyclebaseline -> Draw("Ap");

  c786_cycleNumFit -> cd(3);
  TGraphErrors *gr786_cyclebaselineirrad = new TGraphErrors (counts_786, cycleNumberArray786, BaselineIrradArray786 , 0, BaselineIrradErrArray786);

  gr786_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr786_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr786_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr786_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclebaselineirrad -> SetMarkerStyle(7);
  gr786_cyclebaselineirrad -> Draw("Ap");

  c786_cycleNumFit -> cd(4);
  TGraphErrors *gr786_cyclerise = new TGraphErrors (counts_786, cycleNumberArray786, RiseTimeArray786 , 0, RiseTimeErrArray786);

  gr786_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr786_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr786_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr786_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr786_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr786_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr786_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr786_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr786_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr786_cyclerise -> SetMarkerStyle(7);
  gr786_cyclerise -> Draw("Ap");

  double StorageAll [100] = {storage780, storage781, storage782, storage784, storage785, storage786};
  double StorageErrAll[100] = {storageErr780, storageErr781, storageErr782, storageErr783, storageErr784, storageErr785, storageErr786};
  double runNum[100] = {780, 781, 782, 784, 785, 786};
  double tempIrradAll[100] = {aveAllts12Irrad780, aveAllts12Irrad781, aveAllts12Irrad782, aveAllts12Irrad784, aveAllts12Irrad785, aveAllts12Irrad786};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad780,  aveAllErrts12Irrad781,  aveAllErrts12Irrad782,  aveAllErrts12Irrad784,  aveAllErrts12Irrad785,  aveAllErrts12Irrad786};

  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);

  TGraphErrors *grAll = new TGraphErrors (7, tempIrradAll, StorageAll , tempErrIrradAll, StorageErrAll);
  
  grAll -> SetTitle("Storage Lifetime vs Average Isopure Temperature ");
  grAll -> GetYaxis()-> SetTitle("Storage Time (s)" );
  grAll -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)");
  //grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  grAll -> GetXaxis()-> SetLimits(0.8 ,1.3);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);

  grAll -> SetMarkerStyle(7);
  grAll -> Draw("Ap");





}
