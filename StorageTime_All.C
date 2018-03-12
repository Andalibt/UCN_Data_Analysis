// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS WITH
// 60s IRRADIATION TIME.
// ********************************************************************


void StorageTime_All(){
  gStyle->SetOptFit(0000);

  // OPENING ALL THE FILES
  TFile *fin003 = new TFile("outputTree_StorageTime_17003.root","READ");
  TFile *fin013 = new TFile("outputTree_StorageTime_17013.root","READ");
  TFile *fin023 = new TFile("outputTree_StorageTime_17023.root","READ");
  TFile *fin025 = new TFile("outputTree_StorageTime_17025.root","READ");
  TFile *fin026 = new TFile("outputTree_StorageTime_17026.root","READ");
  TFile *fin029A = new TFile("outputTree_StorageTime_17029A.root","READ");
  TFile *fin031 = new TFile("outputTree_StorageTime_17031.root","READ");
  TFile *fin002 = new TFile("outputTree_StorageTime_17002.root","READ");
  TFile *fin006 = new TFile("outputTree_StorageTime_17006.root","READ");
  TFile *fin021 = new TFile("outputTree_StorageTime_17021.root","READ");
  TFile *fin004A = new TFile("outputTree_StorageTime_17004A.root","READ");
  TFile *fin004B = new TFile("outputTree_StorageTime_17004B.root","READ");
  TFile *fin009 = new TFile("outputTree_StorageTime_17009.root","READ");
  TFile *fin009A = new TFile("outputTree_StorageTime_17009A.root","READ");
  TFile *fin014 = new TFile("outputTree_StorageTime_17014.root","READ");
  TFile *fin029 = new TFile("outputTree_StorageTime_17029.root","READ");
 


  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree003 = (TTree*) fin003->Get("cycle_info");
  TTree *outputTree013 = (TTree*) fin013->Get("cycle_info");
  TTree *outputTree023 = (TTree*) fin023->Get("cycle_info");
  TTree *outputTree025 = (TTree*) fin025->Get("cycle_info");
  TTree *outputTree026 = (TTree*) fin026->Get("cycle_info");
  TTree *outputTree029A = (TTree*) fin029A->Get("cycle_info");
  TTree *outputTree031 = (TTree*) fin031->Get("cycle_info");
  TTree *outputTree002 = (TTree*) fin002->Get("cycle_info");
  TTree *outputTree006 = (TTree*) fin006->Get("cycle_info");
  TTree *outputTree021 = (TTree*) fin021->Get("cycle_info");
  TTree *outputTree004A = (TTree*) fin004A->Get("cycle_info");
  TTree *outputTree004B = (TTree*) fin004B->Get("cycle_info");
  TTree *outputTree009 = (TTree*) fin009->Get("cycle_info");
  TTree *outputTree009A = (TTree*) fin009A->Get("cycle_info");
  TTree *outputTree014 = (TTree*) fin014->Get("cycle_info");
  TTree *outputTree029 = (TTree*) fin029->Get("cycle_info");
 

  // UPTO HERE


  // RUN NUMBER FOR EACH FILE
  Int_t runNumber1;
  Int_t runNumber2;
  Int_t runNumber3;
  Int_t runNumber4;
  Int_t runNumber5;
  Int_t runNumber6;
  Int_t runNumber7;
  Int_t runNumber8;
  Int_t runNumber9;
  Int_t runNumber10;
  Int_t runNumber11;
  Int_t runNumber12;
  Int_t runNumber13;
  Int_t runNumber14;
  Int_t runNumber15;
  Int_t runNumber16;




  // CYCLE DELAY TIME FOR EACH FILE
  double delayTime1;
  double delayTime2;
  double delayTime3;
  double delayTime4;
  double delayTime5;
  double delayTime6;
  double delayTime7;
  double delayTime8;
  double delayTime9;
  double delayTime10;
  double delayTime11;
  double delayTime12;
  double delayTime13;
  double delayTime14;
  double delayTime15;
  double delayTime16;

  // INTEGRAL OF THE UCN COUNTS FROM VALVE CLOSE 
  // TO OPEN FROM THE FIT FUNCTION
  double UCNIntegral1;
  double UCNIntegral2;
  double UCNIntegral3;
  double UCNIntegral4;
  double UCNIntegral5;
  double UCNIntegral6;
  double UCNIntegral7;
  double UCNIntegral8;
  double UCNIntegral9;
  double UCNIntegral10;
  double UCNIntegral11;
  double UCNIntegral12;
  double UCNIntegral13;
  double UCNIntegral14;
  double UCNIntegral15;
  double UCNIntegral16;
  
  // THE ERROR ASSOCIATED WITH THE INTEGRAL FROM
  // THE FIT FUNCTION
  double UCNIntegralErr1;
  double UCNIntegralErr2;
  double UCNIntegralErr3;
  double UCNIntegralErr4;
  double UCNIntegralErr5;
  double UCNIntegralErr6;
  double UCNIntegralErr7;
  double UCNIntegralErr8;
  double UCNIntegralErr9;
  double UCNIntegralErr10;
  double UCNIntegralErr11;
  double UCNIntegralErr12;
  double UCNIntegralErr13;
  double UCNIntegralErr14;
  double UCNIntegralErr15;
  double UCNIntegralErr16;

  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON
  double storagefit003_1expfit = 0;
  double storagefit013_1expfit = 0;
  double storagefit023_1expfit = 0;
  double storagefit025_1expfit = 0; 
  double storagefit026_1expfit = 0;
  double storagefit029A_1expfit = 0;
  double storagefit031_1expfit = 0;
  double storagefit002_1expfit = 0;
  double storagefit006_1expfit = 0;
  double storagefit021_1expfit = 0;

  double storagefit004A_10_1expfit = 0;
  double storagefit004A_20_1expfit = 0;
  double storagefit004A_30_1expfit = 0;
  double storagefit004A_40_1expfit = 0;
  double storagefit004A_50_1expfit = 0;
  double storagefit004A_60_1expfit = 0;
  double storagefit004A_80_1expfit = 0;
  double storagefit004A_100_1expfit = 0;
  double storagefit004A_120_1expfit = 0;
  double storagefit004A_150_1expfit = 0;


  double storagefit004B_1expfit = 0;

  double storagefit009_10_1expfit = 0;
  double storagefit009_30_1expfit = 0;
  double storagefit009_60_1expfit = 0;

  double storagefit009A_10_1expfit = 0;
  double storagefit009A_30_1expfit = 0;
  double storagefit009A_60_1expfit = 0;
  double storagefit009A_120_1expfit = 0;

  double storagefit014_1expfit = 0;
  double storagefit029_1expfit = 0;

  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION
  double storageErrfit003_1expfit = 0;
  double storageErrfit013_1expfit = 0;
  double storageErrfit023_1expfit = 0;
  double storageErrfit025_1expfit = 0;
  double storageErrfit026_1expfit = 0;
  double storageErrfit029A_1expfit = 0;
  double storageErrfit031_1expfit = 0;
  double storageErrfit002_1expfit = 0;
  double storageErrfit006_1expfit = 0;
  double storageErrfit021_1expfit = 0;

  double storageErrfit004A_10_1expfit = 0;
  double storageErrfit004A_20_1expfit = 0;
  double storageErrfit004A_30_1expfit = 0;
  double storageErrfit004A_40_1expfit = 0;
  double storageErrfit004A_50_1expfit = 0;
  double storageErrfit004A_60_1expfit = 0;
  double storageErrfit004A_80_1expfit = 0;
  double storageErrfit004A_100_1expfit = 0;
  double storageErrfit004A_120_1expfit = 0;
  double storageErrfit004A_150_1expfit = 0;
 
  double storageErrfit004B_1expfit = 0;

  double storageErrfit009_10_1expfit = 0;
  double storageErrfit009_30_1expfit = 0;
  double storageErrfit009_60_1expfit = 0;

  double storageErrfit009A_10_1expfit = 0;
  double storageErrfit009A_30_1expfit = 0;
  double storageErrfit009A_60_1expfit = 0;
  double storageErrfit009A_120_1expfit = 0;

  double storageErrfit014_1expfit = 0;
  double storageErrfit029_1expfit = 0;


  // TOTAL UCN COUNTS COMING FROM THE HISTOGRAM INTEGRAL
  int HistIntegral1;
  int HistIntegral2;
  int HistIntegral3;
  int HistIntegral4;
  int HistIntegral5;
  int HistIntegral6;
  int HistIntegral7;
  int HistIntegral8;
  int HistIntegral9;
  int HistIntegral10;
  int HistIntegral11;
  double HistIntegral12;
  int HistIntegral13;
  int HistIntegral14;
  int HistIntegral15;
  int HistIntegral16;
  
  // AVERAGE ISOPURE TEMPERATURE DURING IRRADIAITON
  double avets12Irrad_003;
  double avets12Irrad_013;
  double avets12Irrad_023;
  double avets12Irrad_025;
  double avets12Irrad_026;
  double avets12Irrad_029A;
  double avets12Irrad_031;
  double avets12Irrad_002;
  double avets12Irrad_006;
  double avets12Irrad_021;
  double avets12Irrad_004A;
  double avets12Irrad_004B;
  double avets12Irrad_009;
  double avets12Irrad_009A;
  double avets12Irrad_014;
  double avets12Irrad_029;

  //MAXIMUM ISOPURE HELIUM DURING IRRADIAITON
  double maxts12Irrad_003;
  double maxts12Irrad_013;
  double maxts12Irrad_023;
  double maxts12Irrad_025;
  double maxts12Irrad_026;
  double maxts12Irrad_029A;
  double maxts12Irrad_031;
  double maxts12Irrad_002;
  double maxts12Irrad_006;
  double maxts12Irrad_021;
  double maxts12Irrad_004A;
  double maxts12Irrad_004B;
  double maxts12Irrad_009;
  double maxts12Irrad_009A;
  double maxts12Irrad_014;
  double maxts12Irrad_029;

  // MINIMUM ISOPURE HELIUM DURING IRRADIAITON

  double mints12Irrad_003;
  double mints12Irrad_013;
  double mints12Irrad_023;
  double mints12Irrad_025;
  double mints12Irrad_026;
  double mints12Irrad_029A;
  double mints12Irrad_031;
  double mints12Irrad_002;
  double mints12Irrad_006;
  double mints12Irrad_021;
  double mints12Irrad_004A;
  double mints12Irrad_004B;
  double mints12Irrad_009;
  double mints12Irrad_009A;
  double mints12Irrad_014;
  double mints12Irrad_029;


// AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen_003;
  double avets12ValveOpen_013;
  double avets12ValveOpen_023;
  double avets12ValveOpen_025;
  double avets12ValveOpen_026;
  double avets12ValveOpen_029A;
  double avets12ValveOpen_031;
  double avets12ValveOpen_002;
  double avets12ValveOpen_006;
  double avets12ValveOpen_021;
  double avets12ValveOpen_004A;
  double avets12ValveOpen_004B;
  double avets12ValveOpen_009;
  double avets12ValveOpen_009A;
  double avets12ValveOpen_014;
  double avets12ValveOpen_029;

  //MAXIMUM ISOPURE HELIUM DURING VALVE OPEN
  double maxts12ValveOpen_003;
  double maxts12ValveOpen_013;
  double maxts12ValveOpen_023;
  double maxts12ValveOpen_025;
  double maxts12ValveOpen_026;
  double maxts12ValveOpen_029A;
  double maxts12ValveOpen_031;
  double maxts12ValveOpen_002;
  double maxts12ValveOpen_006;
  double maxts12ValveOpen_021;
  double maxts12ValveOpen_004A;
  double maxts12ValveOpen_004B;
  double maxts12ValveOpen_009;
  double maxts12ValveOpen_009A;
  double maxts12ValveOpen_014;
  double maxts12ValveOpen_029;

  // MINIMUM ISOPURE HELIUM DURING VALVE OPEN

  double mints12ValveOpen_003;
  double mints12ValveOpen_013;
  double mints12ValveOpen_023;
  double mints12ValveOpen_025;
  double mints12ValveOpen_026;
  double mints12ValveOpen_029A;
  double mints12ValveOpen_031;
  double mints12ValveOpen_002;
  double mints12ValveOpen_006;
  double mints12ValveOpen_021;
  double mints12ValveOpen_004A;
  double mints12ValveOpen_004B;
  double mints12ValveOpen_009;
  double mints12ValveOpen_009A;
  double mints12ValveOpen_014;
  double mints12ValveOpen_029;


  // BASELINE BEFORE IRRADIATION
  double baseline_003;
  double baseline_013;
  double baseline_023;
  double baseline_025;
  double baseline_026;
  double baseline_029A;
  double baseline_031;
  double baseline_002;
  double baseline_006;
  double baseline_021;
  double baseline_004A;
  double baseline_004B;
  double baseline_009;
  double baseline_009A;
  double baseline_014;
  double baseline_029;

  // BASELINE ERROR (BEFORE IRRADIATION)
  
  double baselineErr_003;
  double baselineErr_013;
  double baselineErr_023;
  double baselineErr_025;
  double baselineErr_026;
  double baselineErr_029A;
  double baselineErr_031;
  double baselineErr_002;
  double baselineErr_006;
  double baselineErr_021;
  double baselineErr_004A;
  double baselineErr_004B;
  double baselineErr_009;
  double baselineErr_009A;
  double baselineErr_014;
  double baselineErr_029;

  // BASELINE DURING IRRADIAITON

  double baselineIrrad_003;
  double baselineIrrad_013;
  double baselineIrrad_023;
  double baselineIrrad_025;
  double baselineIrrad_026;
  double baselineIrrad_029A;
  double baselineIrrad_031;
  double baselineIrrad_002;
  double baselineIrrad_006;
  double baselineIrrad_021;
  double baselineIrrad_004A;
  double baselineIrrad_004B;
  double baselineIrrad_009;
  double baselineIrrad_009A;
  double baselineIrrad_014;
  double baselineIrrad_029;
 

  // IRRADIATION START TIMES
  double irradStartTimes1;
  double irradStartTimes2;
  double irradStartTimes3;
  double irradStartTimes4;
  double irradStartTimes5;
  double irradStartTimes6;
  double irradStartTimes7;
  double irradStartTimes8;
  double irradStartTimes9;
  double irradStartTimes10;
  double irradStartTimes11;
  double irradStartTimes12;
  double irradStartTimes13;
  double irradStartTimes14;
  double irradStartTimes15;
  double irradStartTimes16;


  // CYCLE START TIMES
  double cycleStartTimes1;
  double cycleStartTimes2;
  double cycleStartTimes3;
  double cycleStartTimes4;
  double cycleStartTimes5;
  double cycleStartTimes6;
  double cycleStartTimes7;
  double cycleStartTimes8;
  double cycleStartTimes9;
  double cycleStartTimes10;
  double cycleStartTimes11;
  double cycleStartTimes12;
  double cycleStartTimes13;
  double cycleStartTimes14;
  double cycleStartTimes15;
  double cycleStartTimes16;


  // SET THE BRANCH TO GET THE RUN NUMBER FROM THE TREE
  outputTree003 -> SetBranchAddress ("runNumber" , &runNumber1);
  outputTree013 -> SetBranchAddress ("runNumber" , &runNumber2);
  outputTree023 -> SetBranchAddress ("runNumber" , &runNumber3);
  outputTree025 -> SetBranchAddress ("runNumber" , &runNumber4);
  outputTree026 -> SetBranchAddress ("runNumber" , &runNumber5);
  outputTree029A -> SetBranchAddress ("runNumber" , &runNumber6);
  outputTree031 -> SetBranchAddress ("runNumber" , &runNumber7);
  outputTree002 -> SetBranchAddress ("runNumber" , &runNumber8);
  outputTree006 -> SetBranchAddress ("runNumber" , &runNumber9);
  outputTree021 -> SetBranchAddress ("runNumber" , &runNumber10);
  outputTree004A -> SetBranchAddress ("runNumber" , &runNumber11);
  outputTree004B -> SetBranchAddress ("runNumber" , &runNumber12);
  outputTree009 -> SetBranchAddress ("runNumber" , &runNumber13);
  outputTree009A -> SetBranchAddress ("runNumber" , &runNumber14);
  outputTree014 -> SetBranchAddress ("runNumber" , &runNumber15);
  outputTree029 -> SetBranchAddress ("runNumber" , &runNumber16);

  // SET THE BRANCH TO GET THE CYCLE DELAY TIME FROM THE TREE
  outputTree003 -> SetBranchAddress ("cycleDelayTime", &delayTime1);
  outputTree013 -> SetBranchAddress ("cycleDelayTime", &delayTime2);
  outputTree023 -> SetBranchAddress ("cycleDelayTime", &delayTime3);
  outputTree025 -> SetBranchAddress ("cycleDelayTime", &delayTime4);
  outputTree026 -> SetBranchAddress ("cycleDelayTime", &delayTime5);
  outputTree029A -> SetBranchAddress ("cycleDelayTime", &delayTime6);
  outputTree031 -> SetBranchAddress ("cycleDelayTime", &delayTime7);
  outputTree002 -> SetBranchAddress ("cycleDelayTime", &delayTime8);
  outputTree006 -> SetBranchAddress ("cycleDelayTime", &delayTime9);
  outputTree021 -> SetBranchAddress ("cycleDelayTime", &delayTime10);
  outputTree004A -> SetBranchAddress ("cycleDelayTime", &delayTime11);
  outputTree004B -> SetBranchAddress ("cycleDelayTime", &delayTime12);
  outputTree009 -> SetBranchAddress ("cycleDelayTime", &delayTime13);
  outputTree009A -> SetBranchAddress ("cycleDelayTime", &delayTime14);
  outputTree014 -> SetBranchAddress ("cycleDelayTime", &delayTime15);
  outputTree029 -> SetBranchAddress ("cycleDelayTime", &delayTime16);
   
  // SET THE BRANCH ADDRESS TO GET THE UCNINTEGRAL (FROM THE FIT
  // FUNCTION) FROM THE TREE
  outputTree003 -> SetBranchAddress ("UCNIntegral", &UCNIntegral1);
  outputTree013 -> SetBranchAddress ("UCNIntegral", &UCNIntegral2);
  outputTree023 -> SetBranchAddress ("UCNIntegral", &UCNIntegral3);
  outputTree025 -> SetBranchAddress ("UCNIntegral", &UCNIntegral4);
  outputTree026 -> SetBranchAddress ("UCNIntegral", &UCNIntegral5);
  outputTree029A -> SetBranchAddress ("UCNIntegral", &UCNIntegral6);
  outputTree031 -> SetBranchAddress ("UCNIntegral", &UCNIntegral7);
  outputTree002 -> SetBranchAddress ("UCNIntegral", &UCNIntegral8);
  outputTree006 -> SetBranchAddress ("UCNIntegral", &UCNIntegral9);
  outputTree021 -> SetBranchAddress ("UCNIntegral", &UCNIntegral10);
  outputTree004A -> SetBranchAddress ("UCNIntegral", &UCNIntegral11);
  outputTree004B -> SetBranchAddress ("UCNIntegral", &UCNIntegral12);
  outputTree009 -> SetBranchAddress ("UCNIntegral", &UCNIntegral13);
  outputTree009A -> SetBranchAddress ("UCNIntegral", &UCNIntegral14);
  outputTree014 -> SetBranchAddress ("UCNIntegral", &UCNIntegral15);
  outputTree029 -> SetBranchAddress ("UCNIntegral", &UCNIntegral16);

  // SET THE BRANCH ADDRESS TO GET THE ERROR ASSOCIATED WITH THE
  // INTEGRAL FROM THE FIT FUNCTION
  outputTree003 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr1);
  outputTree013 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr2);
  outputTree023 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr3);
  outputTree025 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr4);
  outputTree026 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr5);
  outputTree029A -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr6);
  outputTree031 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr7);
  outputTree002 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr8);
  outputTree006 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr9);
  outputTree021 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr10);
  outputTree004A -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr11);
  outputTree004B -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr12);
  outputTree009 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr13);
  outputTree009A -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr14);
  outputTree014 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr15);
  outputTree029 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr16);

  // SET THE BRANCH ADDRESS TO GET THE HISTOGRAM INTEGRAL FROM THE TREE
  outputTree003 -> SetBranchAddress ("HistIntegral" , &HistIntegral1);
  outputTree013 -> SetBranchAddress ("HistIntegral" , &HistIntegral2);
  outputTree023 -> SetBranchAddress ("HistIntegral" , &HistIntegral3);
  outputTree025 -> SetBranchAddress ("HistIntegral" , &HistIntegral4);
  outputTree026 -> SetBranchAddress ("HistIntegral" , &HistIntegral5);
  outputTree029A -> SetBranchAddress ("HistIntegral" , &HistIntegral6);
  outputTree031 -> SetBranchAddress ("HistIntegral" , &HistIntegral7);
  outputTree002 -> SetBranchAddress ("HistIntegral" , &HistIntegral8);
  outputTree006 -> SetBranchAddress ("HistIntegral" , &HistIntegral9);
  outputTree021 -> SetBranchAddress ("HistIntegral" , &HistIntegral10);
  outputTree004A -> SetBranchAddress ("HistIntegral" , &HistIntegral11);
  outputTree004B -> SetBranchAddress ("HistIntegral" , &HistIntegral12);
  outputTree009 -> SetBranchAddress ("HistIntegral" , &HistIntegral13);
  outputTree009A -> SetBranchAddress ("HistIntegral" , &HistIntegral14);
  outputTree014 -> SetBranchAddress ("HistIntegral" , &HistIntegral15);
  outputTree029 -> SetBranchAddress ("HistIntegral" , &HistIntegral16);

  // SET THE BRANCH ADDRESS TO GET THE AVERAGE ISOPURE HELIUM TEMPERATURE DURING VALVE OPEN
  outputTree003-> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_003);
  outputTree013-> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_013);
  outputTree023-> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_023);
  outputTree025 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_025);
  outputTree026 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_026);
  outputTree029A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_029A);
  outputTree031 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_031);
  outputTree002 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_002);
  outputTree006 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_006);
  outputTree021 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_021);
  outputTree004A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_004A);
  outputTree004B -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_004B);
  outputTree009 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_009);
  outputTree009A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_009A);
  outputTree014 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_014);
  outputTree029 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_029);


  // SET THE BRANCH ADDRESS TO GET THE IRRADIATION START TIMES
  outputTree003-> SetBranchAddress ("irradStartTimes" , &irradStartTimes1);
  outputTree013-> SetBranchAddress ("irradStartTimes" , &irradStartTimes2);
  outputTree023-> SetBranchAddress ("irradStartTimes" , &irradStartTimes3);
  outputTree025 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes4);
  outputTree026 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes5);
  outputTree029A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes6);
  outputTree031 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes7);
  outputTree002 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes8);
  outputTree006 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes9);
  outputTree021 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes10);
  outputTree004A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes11);
  outputTree004B -> SetBranchAddress ("irradStartTimes" , &irradStartTimes12);
  outputTree009 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes13);
  outputTree009A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes14);
  outputTree014 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes15);
  outputTree029 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes16);


  // SET THE BRANCH ADDRESS TO GET THE CYCLE START TIMES
  outputTree003-> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes1);
  outputTree013-> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes2);
  outputTree023-> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes3);
  outputTree025 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes4);
  outputTree026 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes5);
  outputTree029A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes6);
  outputTree031 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes7);
  outputTree002 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes8);
  outputTree006 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes9);
  outputTree021 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes10);
  outputTree004A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes11);
  outputTree004B -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes12);
  outputTree009 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes13);
  outputTree009A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes14);
  outputTree014 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes15);
  outputTree029 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes16);


  // DEFINE ALL THE DELAY TIME ARRAYS
  Double_t delayTimeArray1[100] = 0;
  Double_t delayTimeArray2[100] = 0;
  Double_t delayTimeArray3[100] = 0;
  Double_t delayTimeArray4[100] = 0;
  Double_t delayTimeArray5[100] = 0;
  Double_t delayTimeArray6[100] = 0;
  Double_t delayTimeArray7[100] = 0;
  Double_t delayTimeArray8[100] = 0;
  Double_t delayTimeArray9[100] = 0;
  Double_t delayTimeArray10[100] = 0;

  Double_t delayTimeArray11[100] = 0;
  Double_t delayTimeArray11_150[100] = 0;
  Double_t delayTimeArray11_10[100] = 0;
  Double_t delayTimeArray11_20[100] = 0;
  Double_t delayTimeArray11_30[100] = 0;
  Double_t delayTimeArray11_40[100] = 0;
  Double_t delayTimeArray11_50[100] = 0;
  Double_t delayTimeArray11_60[100] = 0;
  Double_t delayTimeArray11_80[100] = 0;
  Double_t delayTimeArray11_100[100] = 0;
  Double_t delayTimeArray11_120[100] = 0;

  Double_t delayTimeArray12[100] = 0;

  Double_t delayTimeArray13[100] = 0;
  Double_t delayTimeArray13_10[100] = 0;
  Double_t delayTimeArray13_30[100] = 0;
  Double_t delayTimeArray13_60[100] = 0;

  Double_t delayTimeArray14[100] = 0;
  Double_t delayTimeArray14_10[100] = 0;
  Double_t delayTimeArray14_30[100] = 0;
  Double_t delayTimeArray14_60[100] = 0;
  Double_t delayTimeArray14_120[100] = 0;

  Double_t delayTimeArray15[100] = 0;
  Double_t delayTimeArray16[100] = 0;

  // DEFINE ARRAYS OF UCN INTEGRAL WHICH IS THE INTEGRAL
  // CALCUALTED FROM THE FIT FUNCTION 
  Double_t UCNIntegralArray1[100] = 0;
  Double_t UCNIntegralArray2[100] = 0;
  Double_t UCNIntegralArray3[100] = 0;
  Double_t UCNIntegralArray4[100] = 0;
  Double_t UCNIntegralArray5[100] = 0;
  Double_t UCNIntegralArray6[100] = 0;
  Double_t UCNIntegralArray7[100] = 0;
  Double_t UCNIntegralArray8[100] = 0;
  Double_t UCNIntegralArray9[100] = 0;
  Double_t UCNIntegralArray10[100] = 0;

  Double_t UCNIntegralArray11[100] = 0;
  Double_t UCNIntegralArray11_150[100] = 0;
  Double_t UCNIntegralArray11_10[100] = 0;
  Double_t UCNIntegralArray11_20[100] = 0;
  Double_t UCNIntegralArray11_30[100] = 0;
  Double_t UCNIntegralArray11_40[100] = 0;
  Double_t UCNIntegralArray11_50[100] = 0;
  Double_t UCNIntegralArray11_60[100] = 0;
  Double_t UCNIntegralArray11_80[100] = 0;
  Double_t UCNIntegralArray11_100[100] = 0;
  Double_t UCNIntegralArray11_120[100] = 0;
  Double_t UCNIntegralArray11_150[100] = 0;

  Double_t UCNIntegralArray12[100] = 0;
  Double_t UCNIntegralArray13[100] = 0;

  Double_t UCNIntegralArray13_10[100] = 0;
  Double_t UCNIntegralArray13_30[100] = 0;
  Double_t UCNIntegralArray13_60[100] = 0;

  Double_t UCNIntegralArray14[100] = 0;
  Double_t UCNIntegralArray14_10[100] = 0;
  Double_t UCNIntegralArray14_30[100] = 0;
  Double_t UCNIntegralArray14_60[100] = 0;
  Double_t UCNIntegralArray14_120[100] = 0;

  Double_t UCNIntegralArray15[100] = 0;
  Double_t UCNIntegralArray16[100] = 0;

  // DEFINE ARRAYS OF INTEGRAL ERRORS CALCLULATED FROM
  // THE FIT FUNCTION
  Double_t UCNIntegralErrArray1[100] = 0;
  Double_t UCNIntegralErrArray2[100] = 0;
  Double_t UCNIntegralErrArray3[100] = 0;
  Double_t UCNIntegralErrArray4[100] = 0;
  Double_t UCNIntegralErrArray5[100] = 0;
  Double_t UCNIntegralErrArray6[100] = 0;
  Double_t UCNIntegralErrArray7[100] = 0;
  Double_t UCNIntegralErrArray8[100] = 0;
  Double_t UCNIntegralErrArray9[100] = 0;
  Double_t UCNIntegralErrArray10[100] = 0;

  Double_t UCNIntegralErrArray11[100] = 0;
  Double_t UCNIntegralErrArray11_150[100] = 0;
  Double_t UCNIntegralErrArray11_10[100] = 0;
  Double_t UCNIntegralErrArray11_20[100] = 0;
  Double_t UCNIntegralErrArray11_30[100] = 0;
  Double_t UCNIntegralErrArray11_40[100] = 0;
  Double_t UCNIntegralErrArray11_50[100] = 0;
  Double_t UCNIntegralErrArray11_60[100] = 0;
  Double_t UCNIntegralErrArray11_80[100] = 0;
  Double_t UCNIntegralErrArray11_100[100] = 0;
  Double_t UCNIntegralErrArray11_120[100] = 0;

  Double_t UCNIntegralErrArray12[100] = 0;

  Double_t UCNIntegralErrArray13[100] = 0;
  Double_t UCNIntegralErrArray13_10[100] = 0;
  Double_t UCNIntegralErrArray13_30[100] = 0;
  Double_t UCNIntegralErrArray13_60[100] = 0;

  Double_t UCNIntegralErrArray14[100] = 0;
  Double_t UCNIntegralErrArray14_10[100] = 0;
  Double_t UCNIntegralErrArray14_30[100] = 0;
  Double_t UCNIntegralErrArray14_60[100] = 0;
  Double_t UCNIntegralErrArray14_120[100] = 0;

  Double_t UCNIntegralErrArray15[100] = 0;
  Double_t UCNIntegralErrArray16[100] = 0;

  // DEFINE ARRAYS OF HISTOGRAM INTEGRALS
  Double_t HistIntegralArray1[100] = 0;
  Double_t HistIntegralArray2[100] = 0;
  Double_t HistIntegralArray3[100] = 0;
  Double_t HistIntegralArray4[100] = 0;
  Double_t HistIntegralArray5[100] = 0;
  Double_t HistIntegralArray6[100] = 0;
  Double_t HistIntegralArray7[100] = 0;
  Double_t HistIntegralArray8[100] = 0;
  Double_t HistIntegralArray9[100] = 0;
  Double_t HistIntegralArray10[100] = 0;

  Double_t HistIntegralArray11[100] = 0;
  Double_t HistIntegralArray11_150[100] = 0;
  Double_t HistIntegralArray11_10[100] = 0;
  Double_t HistIntegralArray11_20[100] = 0;
  Double_t HistIntegralArray11_30[100] = 0;
  Double_t HistIntegralArray11_40[100] = 0;
  Double_t HistIntegralArray11_50[100] = 0;
  Double_t HistIntegralArray11_60[100] = 0;
  Double_t HistIntegralArray11_80[100] = 0;
  Double_t HistIntegralArray11_100[100] = 0;
  Double_t HistIntegralArray11_120[100] = 0;

  Double_t HistIntegralArray12[100] = 0;

  Double_t HistIntegralArray13[100] = 0;
  Double_t HistIntegralArray13_10[100] = 0;
  Double_t HistIntegralArray13_30[100] = 0;
  Double_t HistIntegralArray13_60[100] = 0;

  Double_t HistIntegralArray14[100] = 0;
  Double_t HistIntegralArray14_10[100] = 0;
  Double_t HistIntegralArray14_30[100] = 0;
  Double_t HistIntegralArray14_60[100] = 0;
  Double_t HistIntegralArray14_120[100] = 0;

  Double_t HistIntegralArray15[100] = 0;
  Double_t HistIntegralArray16[100] = 0;
  

  Double_t irradTimeArray1[100] = 0;
  Double_t irradTimeArray2[100] = 0;
  Double_t irradTimeArray3[100] = 0;
  Double_t irradTimeArray4[100] = 0;
  Double_t irradTimeArray5[100] = 0;
  Double_t irradTimeArray6[100] = 0;
  Double_t irradTimeArray7[100] = 0;
  Double_t irradTimeArray8[100] = 0;
  Double_t irradTimeArray9[100] = 0;
  Double_t irradTimeArray10[100] = 0;
  Double_t irradTimeArray11[100] = 0;
  Double_t irradTimeArray12[100] = 0;
  Double_t irradTimeArray13[100] = 0;
  Double_t irradTimeArray14[100] = 0;
  Double_t irradTimeArray15[100] = 0;
  Double_t irradTimeArray16[100] = 0;


  // GET THE EVENTS FOR TCN17003
  ULong64_t event1;
  event1 = (Double_t) outputTree003->GetEntries();

  // GET THE EVENTS FOR TCN17013
  ULong64_t event2;
  event2 = (Double_t)outputTree013->GetEntries();

  // GET THE EVENTS FOR TCN17023
  ULong64_t event3;
  event3 = (Double_t)outputTree023->GetEntries();

  // GET THE EVENTS FOR TCN17025
  ULong64_t event4;
  event4 = (Double_t)outputTree025->GetEntries();

  // GET THE EVENTS FOR TCN17026
  ULong64_t event5;
  event5 = (Double_t)outputTree026->GetEntries();

  // GET THE EVENTS FOR TCN17029A
  ULong64_t event6;
  event6 = (Double_t)outputTree029A->GetEntries();

  // GET THE EVENTS FOR TCN17031
  ULong64_t event7;
  event7 = (Double_t)outputTree031->GetEntries();

  // GET THE EVENTS FOR TCN17002
  ULong64_t event8;
  event8 = (Double_t)outputTree002->GetEntries();

  // GET THE EVENTS FOR TCN17006
  ULong64_t event9;
  event9 = (Double_t)outputTree006->GetEntries();

  // GET THE EVENTS FOR TCN17021
  ULong64_t event10;
  event10 = (Double_t)outputTree021->GetEntries();

  // GET THE EVENTS FOR TCN17004A
  ULong64_t event11;
  event11 = (Double_t)outputTree004A->GetEntries();

  // GET THE EVENTS FOR TCN17004B
  ULong64_t event12;
  event12 = (Double_t)outputTree004B->GetEntries();

  // GET THE EVENTS FOR TCN17009
  ULong64_t event13;
  event13 = (Double_t)outputTree009->GetEntries();

  // GET THE EVENTS FOR TCN17009A
  ULong64_t event14;
  event14 = (Double_t)outputTree009A->GetEntries();

  // GET THE EVENTS FOR TCN17014
  ULong64_t event15;
  event15 = (Double_t)outputTree014->GetEntries();

  // GET THE EVENTS FOR TCN17029
  ULong64_t event16;
  event16 = (Double_t)outputTree029->GetEntries();



  Int_t counts1 = 0;
  Int_t counts2 = 0;
  Int_t counts3 = 0;
  Int_t counts4 = 0;
  Int_t counts5 = 0;
  Int_t counts6 = 0;
  Int_t counts7 = 0;
  Int_t counts8 = 0;
  Int_t counts9 = 0;
  Int_t counts10 = 0;

  Int_t counts11 = 0;
  Int_t counts11_150 = 0;
  Int_t counts11_10 = 0;
  Int_t counts11_20 = 0;
  Int_t counts11_30 = 0;
  Int_t counts11_40 = 0;
  Int_t counts11_50 = 0;
  Int_t counts11_60 = 0;
  Int_t counts11_80 = 0;
  Int_t counts11_100 = 0;
  Int_t counts11_120 = 0;

  Int_t counts12 = 0;

  Int_t counts13 = 0;
  Int_t counts13_10 = 0;
  Int_t counts13_30 = 0;
  Int_t counts13_60 = 0;

  Int_t counts14 = 0;
  Int_t counts14_10 = 0;
  Int_t counts14_30 = 0;
  Int_t counts14_60 = 0;
  Int_t counts14_120 = 0;

  Int_t counts15 = 0;
  Int_t counts16 = 0;


 cout.setf(ios::fixed);

 // FOR TCN17003
  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree003-> GetEvent(j);
    if ( HistIntegral1 < 2000)
      continue;
    // cout << UCNIntegral1 << endl;
    UCNIntegralArray1[j] = UCNIntegral1;
    UCNIntegralErrArray1[j] = UCNIntegralErr1;
    delayTimeArray1[j] = delayTime1;
    HistIntegralArray1[j] = HistIntegral1;
    irradTimeArray1[j] = cycleStartTimes1 - irradStartTimes1;
    counts1++;
  }

  // FOR TCN17013
  for (ULong64_t j = 0 ; j < event2 ; j++){
    outputTree013-> GetEvent(j);
    UCNIntegralArray2[j] = UCNIntegral2;
    UCNIntegralErrArray2[j] = UCNIntegralErr2;
    delayTimeArray2[j] = delayTime2;
    HistIntegralArray2[j] = HistIntegral2;
    irradTimeArray2[j] = cycleStartTimes2 - irradStartTimes2;
    counts2++;
  }

  // FOR TCN17023
  for (ULong64_t j = 0 ; j < event3 ; j++){
    outputTree023 -> GetEvent(j);
    //if ( UCNIntegralErr3 > 2000)
    // continue;
    UCNIntegralArray3[j] = UCNIntegral3;
    UCNIntegralErrArray3[j] = UCNIntegralErr3;
    delayTimeArray3[j] = delayTime3;
    HistIntegralArray3[j] = HistIntegral3;
    irradTimeArray3[j] = cycleStartTimes3 - irradStartTimes3;
    counts3++;
  }

  // FOR TCN17025
  for (ULong64_t j = 0 ; j < event4 ; j++){
    outputTree025 -> GetEvent(j);
    UCNIntegralArray4[j] = UCNIntegral4;
    UCNIntegralErrArray4[j] = UCNIntegralErr4;
    delayTimeArray4[j] = delayTime4;
    HistIntegralArray4[j] = HistIntegral4;
    irradTimeArray4[j] = cycleStartTimes4 - irradStartTimes4;
    counts4++;
  }

  // FOR TCN17026
  for (ULong64_t j = 0 ; j < event5 ; j++){
    outputTree026 -> GetEvent(j);
    UCNIntegralArray5[j] = UCNIntegral5;
    UCNIntegralErrArray5[j] = UCNIntegralErr5;
    delayTimeArray5[j] = delayTime5;
    HistIntegralArray5[j] = HistIntegral5;
    irradTimeArray5[j] = cycleStartTimes5 - irradStartTimes5;
    counts5++;
  }

  // FOR TCN17029A
  for (ULong64_t j = 0 ; j < event6 ; j++){
    outputTree029A -> GetEvent(j);
    //   if (HistIntegral6 < 1000)
    //    continue;
    UCNIntegralArray6[j] = UCNIntegral6;
    UCNIntegralErrArray6[j] = UCNIntegralErr6;
    delayTimeArray6[j] = delayTime6;
    HistIntegralArray6[j] = HistIntegral6;
    irradTimeArray6[j] = cycleStartTimes6 - irradStartTimes6;
    counts6++;
  }

  // FOR TCN17031
  for (ULong64_t j = 0 ; j < event7 ; j++){
    outputTree031 -> GetEvent(j);
    UCNIntegralArray7[j] = UCNIntegral7;
    UCNIntegralErrArray7[j] = UCNIntegralErr7;
    delayTimeArray7[j] = delayTime7;
    HistIntegralArray7[j] = HistIntegral7;
    irradTimeArray7[j] = cycleStartTimes7 - irradStartTimes7;
    counts7++;
  }

  // FOR TCN17002
  for (ULong64_t j = 0 ; j < event8 ; j++){
    outputTree002 -> GetEvent(j);
    //  if (UCNIntegralErr8 > 2000 || HistIntegral8 < 400 )
    //    continue;
    //cout << HistIntegral8 << endl;
    UCNIntegralArray8[j] = UCNIntegral8;
    UCNIntegralErrArray8[j] = UCNIntegralErr8;
    delayTimeArray8[j] = delayTime8;
    HistIntegralArray8[j] = HistIntegral8;
    irradTimeArray8[j] = cycleStartTimes8 - irradStartTimes8;
    counts8++;
  }

  // FOR TCN17006
  for (ULong64_t j = 0 ; j < event9 ; j++){
    outputTree006 -> GetEvent(j);
    if ( UCNIntegral9 < 10000 && delayTime9 <10 )
      continue;
    if (UCNIntegral9 < 100)
      continue;
    UCNIntegralArray9[j] = UCNIntegral9;
    UCNIntegralErrArray9[j] = UCNIntegralErr9;
    delayTimeArray9[j] = delayTime9;
    HistIntegralArray9[j] = HistIntegral9;
    irradTimeArray9[j] = cycleStartTimes9 - irradStartTimes9;
    counts9++;
  }
  
  // FOR TCN17021
  for (ULong64_t j = 0 ; j < event10 ; j++){
    outputTree021 -> GetEvent(j);
    //  if ( UCNIntegralErr10 > 2000 || HistIntegral10 < 10)
    // continue;
    //cout << UCNIntegralErr10 << endl;
    UCNIntegralArray10[j] = UCNIntegral10;
    UCNIntegralErrArray10[j] = UCNIntegralErr10;
    delayTimeArray10[j] = delayTime10;
    HistIntegralArray10[j] = HistIntegral10;
    irradTimeArray10[j] = cycleStartTimes10 - irradStartTimes10;
    counts10++;
  }

  // FOR TCN17004A
  for (ULong64_t j = 0 ; j < event11 ; j++){
    outputTree004A -> GetEvent(j);
    irradTimeArray11[j] = cycleStartTimes11 - irradStartTimes11;
    // for 150 irrad time
    if (irradTimeArray11[j] >= 149. && irradTimeArray11[j]< 151. ){
      UCNIntegralArray11_150[j] = UCNIntegral11;
      UCNIntegralErrArray11_150[j] = UCNIntegralErr11; 
      HistIntegralArray11_150[j] = HistIntegral11;
      delayTimeArray11_150[j] = delayTime11;
      cout << delayTime11<< " " << delayTimeArray11_150[j] << endl;
      counts11_150++;
    }
    // for 10s irradiation time
    if (irradTimeArray11[j]>9.  && irradTimeArray11[j]< 11.  ){
      UCNIntegralArray11_10[j] = UCNIntegral11;
      UCNIntegralErrArray11_10[j] = UCNIntegralErr11; 
      HistIntegralArray11_10[j] = HistIntegral11;
      delayTimeArray11_10[j] = delayTime11;
      counts11_10++;
    }

    // for 20s irradiation time
    if (irradTimeArray11[j]>19.  && irradTimeArray11[j]< 21. ){
      UCNIntegralArray11_20[j] = UCNIntegral11;
      UCNIntegralErrArray11_20[j] = UCNIntegralErr11; 
      HistIntegralArray11_20[j] = HistIntegral11;
      delayTimeArray11_20[j] = delayTime11;
      counts11_20++;
    }
    // for 30s irradiation time
    if (irradTimeArray11[j]>29.  && irradTimeArray11[j]< 31. ){
      UCNIntegralArray11_30[j] = UCNIntegral11;
      UCNIntegralErrArray11_30[j] = UCNIntegralErr11; 
      HistIntegralArray11_30[j] = HistIntegral11;
      delayTimeArray11_30[j] = delayTime11;
      counts11_30++;
    }
    // for 40s irradiation time
    if (irradTimeArray11[j]>39.  && irradTimeArray11[j]< 41.){
      UCNIntegralArray11_40[j] = UCNIntegral11;
      UCNIntegralErrArray11_40[j] = UCNIntegralErr11; 
      HistIntegralArray11_40[j] = HistIntegral11;
      delayTimeArray11_40[j] = delayTime11;
      counts11_40++;
    }
    // for 50s irradiation time
    if (irradTimeArray11[j]>49.  && irradTimeArray11[j]< 51. ){
      UCNIntegralArray11_50[j] = UCNIntegral11;
      UCNIntegralErrArray11_50[j] = UCNIntegralErr11; 
      HistIntegralArray11_50[j] = HistIntegral11;
      delayTimeArray11_50[j] = delayTime11;
      counts11_50++;
    }
    // for 60s irradiation time
    if (irradTimeArray11[j]>59.  && irradTimeArray11[j]< 61. ){
      UCNIntegralArray11_60[j] = UCNIntegral11;
      UCNIntegralErrArray11_60[j] = UCNIntegralErr11; 
      HistIntegralArray11_60[j] = HistIntegral11;
      delayTimeArray11_60[j] = delayTime11;
      counts11_60++;
    }
    // for 80s irradiation time
    if (irradTimeArray11[j]>79.  && irradTimeArray11[j]< 81. ){
      UCNIntegralArray11_80[j] = UCNIntegral11;
      UCNIntegralErrArray11_80[j] = UCNIntegralErr11; 
      HistIntegralArray11_80[j] = HistIntegral11;
      delayTimeArray11_80[j] = delayTime11;
      counts11_80++;
    }
    // for 100s irradiation time
    if (irradTimeArray11[j]>99.  && irradTimeArray11[j]< 101. ){
      UCNIntegralArray11_100[j] = UCNIntegral11;
      UCNIntegralErrArray11_100[j] = UCNIntegralErr11; 
      HistIntegralArray11_100[j] = HistIntegral11;
      delayTimeArray11_100[j] = delayTime11;
      counts11_100++;
    }
    // for 120s irradiation time
    if (irradTimeArray11[j]>119.  && irradTimeArray11[j]< 121. ){
      UCNIntegralArray11_120[j] = UCNIntegral11;
      UCNIntegralErrArray11_120[j] = UCNIntegralErr11; 
      HistIntegralArray11_120[j] = HistIntegral11;
      delayTimeArray11_120[j] = delayTime11;
      counts11_120++;
    }

    UCNIntegralArray11[j] = UCNIntegral11;
    UCNIntegralErrArray11[j] = UCNIntegralErr11;
    delayTimeArray11[j] = delayTime11;
    HistIntegralArray11[j] = HistIntegral11;

    counts11++;
  }

  // FOR TCN17004B
  for (ULong64_t j = 0 ; j < event12 ; j++){
    outputTree004B -> GetEvent(j);
    UCNIntegralArray12[j] = UCNIntegral12;
    UCNIntegralErrArray12[j] = UCNIntegralErr12;
    delayTimeArray12[j] = delayTime12;
    HistIntegralArray12[j] = HistIntegral12;
    irradTimeArray12[j] = cycleStartTimes12 - irradStartTimes12;
    counts12++;
  }

  // FOR TCN17009
  for (ULong64_t j = 0 ; j < event13 ; j++){
    outputTree009 -> GetEvent(j);
    irradTimeArray13[j] = cycleStartTimes13 - irradStartTimes13;

    // for 10s irradiation time
    if (irradTimeArray13[j]==10. ){
      UCNIntegralArray13_10[j] = UCNIntegral13;
      UCNIntegralErrArray13_10[j] = UCNIntegralErr13; 
      HistIntegralArray13_10[j] = HistIntegral13;
      delayTimeArray13_10[j] = delayTime13;
      counts13_10++;
    }

    // for 30s irradiation time
    if (irradTimeArray13[j] == 30. ){
      UCNIntegralArray13_30[j] = UCNIntegral13;
      UCNIntegralErrArray13_30[j] = UCNIntegralErr13; 
      HistIntegralArray13_30[j] = HistIntegral13;
      delayTimeArray13_30[j] = delayTime13;
      counts13_30++;
    }
    // for 60s irradiation time
    if (irradTimeArray13[j] == 60. ){
      UCNIntegralArray13_60[j] = UCNIntegral13;
      UCNIntegralErrArray13_60[j] = UCNIntegralErr13; 
      HistIntegralArray13_60[j] = HistIntegral13;
      delayTimeArray13_60[j] = delayTime13;
      counts13_60++;
    }


    UCNIntegralArray13[j] = UCNIntegral13;
    UCNIntegralErrArray13[j] = UCNIntegralErr13;
    delayTimeArray13[j] = delayTime13;
    HistIntegralArray13[j] = HistIntegral13;

    counts13++;
  }

  // FOR TCN17009A
  for (ULong64_t j = 0 ; j < event14 ; j++){
    outputTree009A -> GetEvent(j);
    irradTimeArray14[j] = cycleStartTimes14 - irradStartTimes14;

    // for 10s irradiation time
    if (irradTimeArray14[j] == 10. ){
      UCNIntegralArray14_10[j] = UCNIntegral14;
      UCNIntegralErrArray14_10[j] = UCNIntegralErr14; 
      HistIntegralArray14_10[j] = HistIntegral14;
      delayTimeArray14_10[j] = delayTime14;
      counts14_10++;
    }
    // for 30s irradiation time
    if (irradTimeArray14[j] == 30. ){
      UCNIntegralArray14_30[j] = UCNIntegral14;
      UCNIntegralErrArray14_30[j] = UCNIntegralErr14; 
      HistIntegralArray14_30[j] = HistIntegral14;
      delayTimeArray14_30[j] = delayTime14;
      counts14_30++;
    }

    // for 600s irradiation time
    if (irradTimeArray14[j] == 60. ){
      UCNIntegralArray14_60[j] = UCNIntegral14;
      UCNIntegralErrArray14_60[j] = UCNIntegralErr14; 
      HistIntegralArray14_60[j] = HistIntegral14;
      delayTimeArray14_60[j] = delayTime14;
      counts14_60++;
    }
    // for 120s irradiation time
    if (irradTimeArray14[j] == 120. ){
      UCNIntegralArray14_120[j] = UCNIntegral14;
      UCNIntegralErrArray14_120[j] = UCNIntegralErr14; 
      HistIntegralArray14_120[j] = HistIntegral14;
      delayTimeArray14_120[j] = delayTime14;
      counts14_120++;
    }

    UCNIntegralArray14[j] = UCNIntegral14;
    UCNIntegralErrArray14[j] = UCNIntegralErr14;
    delayTimeArray14[j] = delayTime14;
    HistIntegralArray14[j] = HistIntegral14;

    counts14++;
  }

  // FOR TCN17014
  for (ULong64_t j = 0 ; j < event15 ; j++){
    outputTree014 -> GetEvent(j);
    //  if ( UCNIntegralErr10 > 2000 || HistIntegral10 < 10)
    // continue;
    //cout << UCNIntegralErr10 << endl;
    UCNIntegralArray15[j] = UCNIntegral15;
    UCNIntegralErrArray15[j] = UCNIntegralErr15;
    delayTimeArray15[j] = delayTime15;
    HistIntegralArray15[j] = HistIntegral15;
    irradTimeArray15[j] = cycleStartTimes15 - irradStartTimes15;
    counts15++;
  }

  // FOR TCN17029
  for (ULong64_t j = 0 ; j < event16 ; j++){
    outputTree029 -> GetEvent(j);
    //  if ( UCNIntegralErr10 > 2000 || HistIntegral10 < 10)
    // continue;
    //cout << UCNIntegralErr10 << endl;
    UCNIntegralArray16[j] = UCNIntegral16;
    UCNIntegralErrArray16[j] = UCNIntegralErr16;
    delayTimeArray16[j] = delayTime16;
    HistIntegralArray16[j] = HistIntegral16;
    irradTimeArray16[j] = cycleStartTimes16 - irradStartTimes16;
    counts16++;
  }




  // ONE EXPONENTIAL FIT
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 120);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(25000,30);
  fit1exp -> SetParLimits(0, 10000, 60000);
  //fit1exp -> SetParLimits(1, 20, 45);
  

  break;
  // ******************************************************************
  // TCN17003
  // ******************************************************************
  TCanvas *c1 = new TCanvas("c1", "c1",900,500);
  c1 -> SetLogy();

  // INTEGRAL FROM THE FIT
  TGraphErrors *gr1 = new TGraphErrors(counts1, delayTimeArray1, UCNIntegralArray1, 0 , UCNIntegralErrArray1);

  gr1 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr1 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr1 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1 -> GetXaxis()-> SetRangeUser(0, 120);
  // gr1 -> GetYaxis()-> SetRangeUser(10, 60000);
  gr1 -> SetMarkerStyle(7);

  gr1 -> Fit(fit1exp, "+R");
  fit1exp -> SetLineColor(1);
  storagefit003_1expfit =fit1exp->GetParameter(1);
  storageErrfit003_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr11 = new TGraph(counts1, delayTimeArray1, HistIntegralArray1);
  gr11 -> SetMarkerStyle(7);
  gr11 -> SetMarkerColor(2);
  gr11 -> GetXaxis()-> SetRangeUser(0, 120);
  //gr11 -> GetYaxis()-> SetRangeUser(1000, 60000);

  gr1 -> Draw("ap");
  gr11 -> Draw("p");
  // ******************************************************************
  // TCN17013
  // ******************************************************************
  // INTEGRAL FROM THE FIT
 
  TCanvas *c2 = new TCanvas("c2", "c2",900,500);
  c2 -> SetLogy();
  
  TGraphErrors *gr2 = new TGraphErrors(counts2, delayTimeArray2, UCNIntegralArray2, 0 , UCNIntegralErrArray2);
  gr2 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr2 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr2 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2 -> GetYaxis()-> SetRangeUser(1, 60000);
  gr2 -> SetMarkerStyle(2); 
  //gr2 -> SetMarkerColor(9);
  
  gr2 -> Fit(fit1exp,"+R");
  storagefit013_1expfit =fit1exp->GetParameter(1);
  storageErrfit013_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr22 = new TGraph(counts2, delayTimeArray2, HistIntegralArray2);
  gr22 -> SetMarkerStyle(2);
  gr22 -> SetMarkerColor(2);

   gr2 -> Draw("ap");
   gr22 -> Draw("p");


  // ******************************************************************
  // TCN17023
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c3 = new TCanvas("c3", "c3",900,500);
  c3 -> SetLogy();
  
  TGraphErrors *gr3 = new TGraphErrors(counts3, delayTimeArray3, UCNIntegralArray3, 0 , UCNIntegralErrArray3);
  
  gr3 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr3 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr3 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //gr3 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr3 -> SetMarkerStyle(3);

  gr3 -> Fit(fit1exp,"+R");
  storagefit023_1expfit =fit1exp->GetParameter(1);
  storageErrfit023_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr33 = new TGraph(counts3, delayTimeArray3, HistIntegralArray3);
  gr33 -> SetMarkerStyle(3);
  gr33 -> SetMarkerColor(2);

  gr3 -> Draw("ap");
  gr33 -> Draw("p");
  
  // ******************************************************************
  // TCN17025
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c4 = new TCanvas("c4", "c4",900,500);
  c4 -> SetLogy();
  
  TGraphErrors *gr4 = new TGraphErrors(counts4, delayTimeArray4, UCNIntegralArray4, 0 , UCNIntegralErrArray4);
  gr4 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr4 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr4 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //gr4 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr4 -> SetMarkerStyle(4);

  gr4 -> Fit(fit1exp,"+R");
  storagefit025_1expfit =fit1exp->GetParameter(1);
  storageErrfit025_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr44 = new TGraph(counts4, delayTimeArray4, HistIntegralArray4);
  gr44 -> SetMarkerStyle(4);
  gr44 -> SetMarkerColor(2);

  gr4 -> Draw("ap");
  gr44 -> Draw("p");
  
  // ******************************************************************
  // TCN17026
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c5 = new TCanvas("c5", "c5",900,500);
  c5 -> SetLogy();
  
  TGraphErrors *gr5 = new TGraphErrors(counts5, delayTimeArray5, UCNIntegralArray5, 0 , UCNIntegralErrArray5);

  
  gr5 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr5 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr5 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //  gr5 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr5 -> SetMarkerStyle(5);

  gr5 -> Fit(fit1exp,"+R");
  storagefit026_1expfit =fit1exp->GetParameter(1);
  storageErrfit026_1expfit =fit1exp->GetParError(1);

  
  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr55 = new TGraph(counts5, delayTimeArray5, HistIntegralArray5);
  gr55 -> SetMarkerStyle(5);
  gr55 -> SetMarkerColor(2);

  gr5 -> Draw("ap");
  gr55 -> Draw("p");
  
  // ******************************************************************
  // TCN17029A
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c6 = new TCanvas("c6", "c6",900,500);
  c6 -> SetLogy();

  TGraphErrors *gr6 = new TGraphErrors(counts6, delayTimeArray6, UCNIntegralArray6, 0 , UCNIntegralErrArray6);

  gr6 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr6 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr6 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //  gr6 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr6 -> SetMarkerStyle(26);

  gr6 -> Fit(fit1exp,"+R");
  storagefit029A_1expfit =fit1exp->GetParameter(1);
  storageErrfit029A_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr66 = new TGraph(counts6, delayTimeArray6, HistIntegralArray6);
  gr66 -> SetMarkerStyle(26);
  gr66 -> SetMarkerColor(2);


  gr6 -> Draw("ap");
  gr66 -> Draw("p");
  
  // ******************************************************************
  // TCN17031
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TCanvas *c7 = new TCanvas("c7", "c7",900,500);
  c7 -> SetLogy();

  TGraphErrors *gr7 = new TGraphErrors(counts7, delayTimeArray7, UCNIntegralArray7, 0 , UCNIntegralErrArray7);

  gr7 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr7 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //  gr7 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr7 -> SetMarkerStyle(25);

  gr7 -> Fit(fit1exp,"+R");
  storagefit031_1expfit =fit1exp->GetParameter(1);
  storageErrfit031_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr77 = new TGraph(counts7, delayTimeArray7, HistIntegralArray7); 
  gr77 -> SetMarkerStyle(25);
  gr77 -> SetMarkerColor(2);

  gr7 -> Draw("ap");
  gr77 -> Draw("p");
  // ******************************************************************
  // TCN17002
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c8 = new TCanvas("c8", "c8",900,500);
  c8 -> SetLogy();

  TGraphErrors *gr8 = new TGraphErrors(counts8, delayTimeArray8, UCNIntegralArray8, 0 , UCNIntegralErrArray8);

  
  gr8 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr8 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr8 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr8 -> GetYaxis()-> SetRangeUser(1, 60000);
  gr8 -> SetMarkerStyle(33); 

  gr8 -> Fit(fit1exp,"+R");
  storagefit002_1expfit =fit1exp->GetParameter(1);
  storageErrfit002_1expfit =fit1exp->GetParError(1);
  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr88 = new TGraph(counts8, delayTimeArray8, HistIntegralArray8);
  gr88 -> SetMarkerStyle(33);
  gr88 -> SetMarkerColor(2);

  gr8 -> Draw("ap");
  gr88 -> Draw("p");
  
  // ******************************************************************
  // TCN17006
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c9 = new TCanvas("c9", "c9",900,500);
  c9 -> SetLogy();


  TGraphErrors *gr9 = new TGraphErrors(counts9, delayTimeArray9, UCNIntegralArray9, 0 , UCNIntegralErrArray9);
  
  gr9 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr9 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr9 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  // gr9 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr9 -> SetMarkerStyle(21); 

  gr9 -> Fit(fit1exp,"+R");
  storagefit006_1expfit =fit1exp->GetParameter(1);
  storageErrfit006_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr99 = new TGraph(counts9, delayTimeArray9, HistIntegralArray9);
  gr99 -> SetMarkerStyle(21);
  gr99 -> SetMarkerColor(2);
  
   gr9 -> Draw("ap");
   gr99 -> Draw("p");
  
  // ******************************************************************
  // TCN17021
  // ******************************************************************

  // INTEGRAL FROM THE FIT
  
  TCanvas *c10 = new TCanvas("c10", "c10",900,500);
  c10 -> SetLogy();


  TGraphErrors *gr10 = new TGraphErrors(counts10, delayTimeArray10, UCNIntegralArray10, 0 , UCNIntegralErrArray10);

  
  gr10 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr10 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //  gr10 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr10 -> SetMarkerStyle(22); 

  gr10 -> Fit(fit1exp,"+R");
  storagefit021_1expfit =fit1exp->GetParameter(1);
  storageErrfit021_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr1010 = new TGraph(counts10, delayTimeArray10, HistIntegralArray10);
  gr1010 -> SetMarkerStyle(22);
  gr1010 -> SetMarkerColor(2);

  gr10 -> Draw("ap");
  gr1010 -> Draw("p");
  
  // ******************************************************************
  // TCN17004A
  // ******************************************************************
  TCanvas *c004A = new TCanvas("c004A" , "c004A" , 900, 500);
  c004A -> SetLogy();
  c004A -> Divide(3,4);
  
  c004A -> cd(1);
 TGraphErrors *gr004A_10 = new TGraphErrors(counts11_10, delayTimeArray11_10, UCNIntegralArray11_10, 0 , UCNIntegralErrArray11_10);
  gr004A_10 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_10 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_10 -> SetMarkerStyle(22); 

  gr004A_10 -> Fit(fit1exp,"+R");
  storagefit004A_10_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_10_1expfit =fit1exp->GetParError(1);


  TGraph *gr004A_10_hist = new TGraph(counts11_10, delayTimeArray11_10, HistIntegralArray11_10);
  gr004A_10_hist -> SetMarkerStyle(22);
  gr004A_10_hist -> SetMarkerColor(2);

  gr004A_10 -> Draw("ap");
  gr004A_10_hist -> Draw("p");


  c004A -> cd(2);
 TGraphErrors *gr004A_20 = new TGraphErrors(counts11_20, delayTimeArray11_20, UCNIntegralArray11_20, 0 , UCNIntegralErrArray11_20);
  gr004A_20 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_20 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_20 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_20 -> SetMarkerStyle(22); 

  gr004A_20 -> Fit(fit1exp,"+R");
  storagefit004A_20_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_20_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_20_hist = new TGraph(counts11_20, delayTimeArray11_20, HistIntegralArray11_10);
  gr004A_20_hist -> SetMarkerStyle(22);
  gr004A_20_hist -> SetMarkerColor(2);

  gr004A_20 -> Draw("ap");
  gr004A_20_hist -> Draw("p");


  c004A -> cd(3);
 TGraphErrors *gr004A_30 = new TGraphErrors(counts11_30, delayTimeArray11_30, UCNIntegralArray11_30, 0 , UCNIntegralErrArray11_30);
  gr004A_30 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_30 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_30 -> SetMarkerStyle(22); 

  gr004A_30 -> Fit(fit1exp,"+R");
  storagefit004A_30_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_30_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_30_hist = new TGraph(counts11_30, delayTimeArray11_30, HistIntegralArray11_10);
  gr004A_30_hist -> SetMarkerStyle(22);
  gr004A_30_hist -> SetMarkerColor(2);

  gr004A_30 -> Draw("ap");
  gr004A_30_hist -> Draw("p");


  c004A -> cd(4);
 TGraphErrors *gr004A_40 = new TGraphErrors(counts11_40, delayTimeArray11_40, UCNIntegralArray11_40, 0 , UCNIntegralErrArray11_40);
  gr004A_40 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_40 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_40 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_40 -> SetMarkerStyle(22); 

  gr004A_40 -> Fit(fit1exp,"+R");
  storagefit004A_40_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_40_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_40_hist = new TGraph(counts11_40, delayTimeArray11_40, HistIntegralArray11_10);
  gr004A_40_hist -> SetMarkerStyle(22);
  gr004A_40_hist -> SetMarkerColor(2);

  gr004A_40 -> Draw("ap");
  gr004A_40_hist -> Draw("p");


  c004A -> cd(5);
 TGraphErrors *gr004A_50 = new TGraphErrors(counts11_50, delayTimeArray11_50, UCNIntegralArray11_50, 0 , UCNIntegralErrArray11_50);
  gr004A_50 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_50 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_50 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_50 -> SetMarkerStyle(22); 

  gr004A_50 -> Fit(fit1exp,"+R");
  storagefit004A_50_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_50_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_50_hist = new TGraph(counts11_50, delayTimeArray11_50, HistIntegralArray11_10);
  gr004A_50_hist -> SetMarkerStyle(22);
  gr004A_50_hist -> SetMarkerColor(2);

  gr004A_50 -> Draw("ap");
  gr004A_50_hist -> Draw("p");

  c004A -> cd(6);
 TGraphErrors *gr004A_60 = new TGraphErrors(counts11_60, delayTimeArray11_60, UCNIntegralArray11_60, 0 , UCNIntegralErrArray11_60);
  gr004A_60 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_60 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_60 -> SetMarkerStyle(22); 

  gr004A_60 -> Fit(fit1exp,"+R");
  storagefit004A_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_60_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_60_hist = new TGraph(counts11_60, delayTimeArray11_60, HistIntegralArray11_10);
  gr004A_60_hist -> SetMarkerStyle(22);
  gr004A_60_hist -> SetMarkerColor(2);

  gr004A_60 -> Draw("ap");
  gr004A_60_hist -> Draw("p");

  c004A -> cd(7);
 TGraphErrors *gr004A_80 = new TGraphErrors(counts11_80, delayTimeArray11_80, UCNIntegralArray11_80, 0 , UCNIntegralErrArray11_80);
  gr004A_80 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_80 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_80 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_80 -> SetMarkerStyle(22); 

  gr004A_80 -> Fit(fit1exp,"+R");
  storagefit004A_80_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_80_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_80_hist = new TGraph(counts11_80, delayTimeArray11_80, HistIntegralArray11_10);
  gr004A_80_hist -> SetMarkerStyle(22);
  gr004A_80_hist -> SetMarkerColor(2);

  gr004A_80 -> Draw("ap");
  gr004A_80_hist -> Draw("p");



  c004A -> cd(8);
 TGraphErrors *gr004A_100 = new TGraphErrors(counts11_100, delayTimeArray11_100, UCNIntegralArray11_100, 0 , UCNIntegralErrArray11_100);
  gr004A_100 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_100 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_100 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_100 -> SetMarkerStyle(22); 

  gr004A_100 -> Fit(fit1exp,"+R");
  storagefit004A_100_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_100_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_100_hist = new TGraph(counts11_100, delayTimeArray11_100, HistIntegralArray11_10);
  gr004A_100_hist -> SetMarkerStyle(22);
  gr004A_100_hist -> SetMarkerColor(2);

  gr004A_100 -> Draw("ap");
  gr004A_100_hist -> Draw("p");


  c004A -> cd(9);
 TGraphErrors *gr004A_120 = new TGraphErrors(counts11_120, delayTimeArray11_120, UCNIntegralArray11_120, 0 , UCNIntegralErrArray11_120);
  gr004A_120 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_120 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_120 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_120 -> SetMarkerStyle(22); 

  gr004A_120 -> Fit(fit1exp,"+R");
  storagefit004A_120_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_120_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_120_hist = new TGraph(counts11_120, delayTimeArray11_120, HistIntegralArray11_10);
  gr004A_120_hist -> SetMarkerStyle(22);
  gr004A_120_hist -> SetMarkerColor(2);

  gr004A_120 -> Draw("ap");
  gr004A_120_hist -> Draw("p");
  
  c004A -> cd(10);
TGraphErrors *gr004A_150 = new TGraphErrors(counts11_150, delayTimeArray11_150, UCNIntegralArray11_150, 0 , UCNIntegralErrArray11_150);
  gr004A_150 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004A_150 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004A_150 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_150 -> SetMarkerStyle(22); 

  gr004A_150 -> Fit(fit1exp,"+R");
  storagefit004A_150_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_150_1expfit =fit1exp->GetParError(1);

  TGraph *gr004A_150_hist = new TGraph(counts11_150, delayTimeArray11_150, HistIntegralArray11_10);
  gr004A_150_hist -> SetMarkerStyle(22);
  gr004A_150_hist -> SetMarkerColor(2);

  gr004A_150 -> Draw("ap");
  gr004A_150_hist -> Draw("p");
  
  break;
  // ******************************************************************
  // TCN17004B
  // ******************************************************************
  
   TCanvas *c004B = new TCanvas("c004B", "c004B",900,500);
   c004B -> SetLogy();
  
  TGraphErrors *gr004B = new TGraphErrors(counts12, delayTimeArray12, UCNIntegralArray12, 0 , UCNIntegralErrArray12);
  gr004B -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004B -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004B -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004B -> GetYaxis()-> SetRangeUser(1, 60000);
  gr004B -> SetMarkerStyle(2); 
  //gr004B -> SetMarkerColor(9);
  
  gr004B -> Fit(fit1exp,"+R");
  storagefit004B_1expfit =fit1exp->GetParameter(1);
  storageErrfit004B_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr004B_hist = new TGraph(counts12, delayTimeArray12, HistIntegralArray12);
  gr004B_hist -> SetMarkerStyle(2);
  gr004B_hist -> SetMarkerColor(2);

   gr004B -> Draw("ap");
   gr004B_hist -> Draw("p");
  // ******************************************************************
  // TCN17009
  // ******************************************************************
  
   TCanvas *c009 = new TCanvas("c009", "c009",900,500);
   c009 -> SetLogy();
   c009 -> Divide(3,1);

   c009 -> cd(1);
  TGraphErrors *gr009_10 = new TGraphErrors(counts13_10, delayTimeArray13_10, UCNIntegralArray13_10, 0 , UCNIntegralErrArray13_10);
  gr009_10 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_10 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_10 -> SetMarkerStyle(2); 
  
  gr009_10 -> Fit(fit1exp,"+R");
  storagefit009_10_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_10_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009_10_hist = new TGraph(counts13_10, delayTimeArray13_10, HistIntegralArray13_10);
  gr009_10_hist -> SetMarkerStyle(2);
  gr009_10_hist -> SetMarkerColor(2);

   gr009_10 -> Draw("ap");
   gr009_10_hist -> Draw("p");


   c009 -> cd(2);
  TGraphErrors *gr009_30 = new TGraphErrors(counts13_30, delayTimeArray13_30, UCNIntegralArray13_30, 0 , UCNIntegralErrArray13_30);
  gr009_30 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_30 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_30 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_30 -> SetMarkerStyle(2); 
  
  gr009_30 -> Fit(fit1exp,"+R");
  storagefit009_30_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_30_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009_30_hist = new TGraph(counts13_30, delayTimeArray13_30, HistIntegralArray13_30);
  gr009_30_hist -> SetMarkerStyle(2);
  gr009_30_hist -> SetMarkerColor(2);

   gr009_30 -> Draw("ap");
   gr009_30_hist -> Draw("p");

   c009 -> cd(3);
  TGraphErrors *gr009_60 = new TGraphErrors(counts13_60, delayTimeArray13_60, UCNIntegralArray13_60, 0 , UCNIntegralErrArray13_60);
  gr009_60 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_60 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_60 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_60 -> SetMarkerStyle(2); 
  
  gr009_60 -> Fit(fit1exp,"+R");
  storagefit009_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_60_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009_60_hist = new TGraph(counts13_60, delayTimeArray13_60, HistIntegralArray13_60);
  gr009_60_hist -> SetMarkerStyle(2);
  gr009_60_hist -> SetMarkerColor(2);

   gr009_60 -> Draw("ap");
   gr009_60_hist -> Draw("p");

  // ******************************************************************
  // TCN17009A
  // ******************************************************************
  
   TCanvas *c009A = new TCanvas("c009A", "c009A",900,500);
   c009A -> SetLogy();
   c009A -> Divide(2,2);

   c009A -> cd(1);
  TGraphErrors *gr009A_10 = new TGraphErrors(counts14_10, delayTimeArray14_10, UCNIntegralArray14_10, 0 , UCNIntegralErrArray14_10);
  gr009A_10 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_10 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_10 -> SetMarkerStyle(2); 
  
  gr009A_10 -> Fit(fit1exp,"+R");
  storagefit009A_10_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_10_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009A_10_hist = new TGraph(counts14_10, delayTimeArray14_10, HistIntegralArray14_10);
  gr009A_10_hist -> SetMarkerStyle(2);
  gr009A_10_hist -> SetMarkerColor(2);

   gr009A_10 -> Draw("ap");
   gr009A_10_hist -> Draw("p");

   c009A -> cd(2);
  TGraphErrors *gr009A_30 = new TGraphErrors(counts14_30, delayTimeArray14_30, UCNIntegralArray14_30, 0 , UCNIntegralErrArray14_30);
  gr009A_30 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_30 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_30 -> SetMarkerStyle(2); 
  
  gr009A_30 -> Fit(fit1exp,"+R");
  storagefit009A_30_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_30_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009A_30_hist = new TGraph(counts14_30, delayTimeArray14_30, HistIntegralArray14_30);
  gr009A_30_hist -> SetMarkerStyle(2);
  gr009A_30_hist -> SetMarkerColor(2);

   gr009A_30 -> Draw("ap");
   gr009A_30_hist -> Draw("p");

   c009A -> cd(3);
  TGraphErrors *gr009A_60 = new TGraphErrors(counts14_60, delayTimeArray14_60, UCNIntegralArray14_60, 0 , UCNIntegralErrArray14_60);
  gr009A_60 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_60 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_60 -> SetMarkerStyle(2); 
  
  gr009A_60 -> Fit(fit1exp,"+R");
  storagefit009A_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_60_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009A_60_hist = new TGraph(counts14_60, delayTimeArray14_60, HistIntegralArray14_60);
  gr009A_60_hist -> SetMarkerStyle(2);
  gr009A_60_hist -> SetMarkerColor(2);

   gr009A_60 -> Draw("ap");
   gr009A_60_hist -> Draw("p");

   c009A -> cd(4);
  TGraphErrors *gr009A_120 = new TGraphErrors(counts14_120, delayTimeArray14_120, UCNIntegralArray14_120, 0 , UCNIntegralErrArray14_120);
  gr009A_120 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_120 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_120 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_120 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_120 -> SetMarkerStyle(2); 
  
  gr009A_120 -> Fit(fit1exp,"+R");
  storagefit009A_120_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_120_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr009A_120_hist = new TGraph(counts14_120, delayTimeArray14_120, HistIntegralArray14_120);
  gr009A_120_hist -> SetMarkerStyle(2);
  gr009A_120_hist -> SetMarkerColor(2);

   gr009A_120 -> Draw("ap");
   gr009A_120_hist -> Draw("p");


  // ******************************************************************
  // TCN17014
  // ******************************************************************
  
   TCanvas *c014 = new TCanvas("c014", "c014",900,500);
   c014 -> SetLogy();

  // INTEGRAL FROM THE FIT
  TGraphErrors *gr014 = new TGraphErrors(counts15, delayTimeArray15, UCNIntegralArray15, 0 , UCNIntegralErrArray15);

  gr014 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr014 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr014 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr014 -> GetXaxis()-> SetRangeUser(0, 120);
  gr014 -> SetMarkerStyle(7);

  gr014 -> Fit(fit1exp, "+R");
  fit1exp -> SetLineColor(1);
  storagefit014_1expfit =fit1exp->GetParameter(1);
  storageErrfit014_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr014_hist = new TGraph(counts15, delayTimeArray15, HistIntegralArray15);
  gr014_hist -> SetMarkerStyle(7);
  gr014_hist -> SetMarkerColor(2);
  gr014_hist -> GetXaxis()-> SetRangeUser(0, 120);


  gr014 -> Draw("ap");
  gr014_hist -> Draw("p");


  // ******************************************************************
  // TCN17029
  // ******************************************************************

   TCanvas *c029 = new TCanvas("c029", "c029",900,500);
   c029 -> SetLogy();

  // INTEGRAL FROM THE FIT
  TGraphErrors *gr029 = new TGraphErrors(counts16, delayTimeArray16, UCNIntegralArray16, 0 , UCNIntegralErrArray16);

  gr029 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr029 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr029 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029 -> GetXaxis()-> SetRangeUser(0, 120);
  gr029 -> SetMarkerStyle(7);

  gr029 -> Fit(fit1exp, "+R");
  fit1exp -> SetLineColor(1);
  storagefit029_1expfit =fit1exp->GetParameter(1);
  storageErrfit029_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr029_hist = new TGraph(counts16, delayTimeArray16, HistIntegralArray16);
  gr029_hist -> SetMarkerStyle(7);
  gr029_hist -> SetMarkerColor(2);
  gr029_hist -> GetXaxis()-> SetRangeUser(0, 120);


  gr029 -> Draw("ap");
  gr029_hist -> Draw("p");


  // **********************************************************************
  // STORAGE TIME
  // *********************************************************************


  // THE EXPERIMENT NUMBER
  double experiment[15] = {17003, 17013, 17023, 17025, 17026, 17029.5, 17031,  17006, 17021, 17004.5, 17004.75, 17009, 17009.5, 17014, 17029 };
  
  // FOR 10 S IRRADIATION TIME
  double storage_10[3] = { storagefit004A_10_1expfit,   storagefit009_10_1expfit,   storagefit009A_10_1expfit};
  double storage_10Err [3] = {  storageErrfit004A_10_1expfit  , storageErrfit009_10_1expfit ,storageErrfit009A_10_1expfit};
  double storage_10_expNum[3] ={17004.5, 17009, 17009.5};

  // FOR 20S IRRADITION TIME
  double  storage_20 [1] = {  storagefit004A_20_1expfit};
  double storage_20Err[1] = {  storageErrfit004A_20_1expfit};
  double storage_20_expNum[1] = {17004.5};

  // FOR 30S IRRADIATION TIME
  double storage_30[5] = {  storagefit004A_30_1expfit,  storagefit009_30_1expfit,  storagefit009A_30_1expfit,  storagefit014_1expfit,  storagefit029_1expfit };
  double storage_30Err[5] = { storageErrfit004A_30_1expfit,  storageErrfit009_30_1expfit,  storageErrfit009A_30_1expfit,   storageErrfit014_1expfit,  storageErrfit029_1expfit};
  double storage_30_expNum[5]= {17004.5, 17009, 17009.5, 17014, 17029};

  // FOR 40S IRRATIATION TIME
  double storage_40[1] = {  storagefit004A_40_1expfit};
  double storage_40Err[1] = {  storageErrfit004A_40_1expfit};
  double storage_40_expNum[1]={17004.5};

  //FOR 50S IRRADIATION TIME
  double storage_50[1] = {  storagefit004A_50_1expfit};
  double storage_50Err[1] = {  storageErrfit004A_50_1expfit};
  double storage_50_expNum[1]={17004.5};

  //FOR 60S IRRADIATION TIME
  double storage_60 [13] = {  storagefit002_1expfit,  storagefit003_1expfit,  storagefit004A_60_1expfit,  storagefit006_1expfit,   storagefit009_60_1expfit,  storagefit009A_60_1expfit,  storagefit013_1expfit,  storagefit021_1expfit,  storagefit023_1expfit ,   storagefit025_1expfit,  storagefit026_1expfit,  storagefit029A_1expfit,   storagefit031_1expfit}; 
  double storage_60Err[13] = {  storageErrfit002_1expfit,  storageErrfit003_1expfit,  storageErrfit004A_60_1expfit,   storageErrfit006_1expfit,   storageErrfit009_60_1expfit,  storageErrfit009A_60_1expfit,  storageErrfit013_1expfit,  storageErrfit021_1expfit,  storageErrfit023_1expfit,  storageErrfit025_1expfit,  storageErrfit026_1expfit,  storageErrfit029A_1expfit,   storageErrfit031_1expfit };
  double storage_60_expNum[13] = {17002, 17003, 17004.5, 17006,17009, 17009.5,17013, 17021,17023, 17025, 17026, 17029.5 , 17031 };

  // FOR 80S IRRADIATION TIME
  double storage_80[1] = {  storagefit004A_80_1expfit};
  double storage_80Err[1] = {  storageErrfit004A_80_1expfit};
  double storage_80_expNum[1]={17004.5};

  // FOR 100S IRRADIATION TIME
  double  storage_100[2] = {  storagefit004A_100_1expfit,  storagefit004B_1expfit };
  double storage_100Err[2] = {  storageErrfit004A_100_1expfit,  storageErrfit004B_1expfit };
  double storage_100_expNum[2] = {17004.5 , 17004.75};

  // FOR 120S IRRADIATION TIME
  double storage_120[2] = {  storagefit004A_120_1expfit,   storagefit009A_120_1expfit} ;
  double storage_120Err[2] = {  storageErrfit004A_120_1expfit,  storageErrfit009A_120_1expfit };
  double storage_120_expNum[2] = {17004.5, 17009.5 };
  // FOR 150S IRRADIATION TIME
  double storage_150[1] = {  storagefit004A_150_1expfit};
  double storage_150Err[1] = {  storageErrfit004A_150_1expfit};
  double storage_150_expNum[1]={17004.5};

  TCanvas *cstorage = new TCanvas ("cstorage" , "cstorage", 900, 500);
  TGraphErrors *grStorage10 = new TGraphErrors(3, storage_10_expNum , storage_10 , 0 , storage_10Err);
  grStorage10 -> SetMarkerStyle(2);

  TGraphErrors *grStorage20 = new TGraphErrors(1, storage_20_expNum , storage_20 , 0 , storage_20Err);
  grStorage20 -> SetMarkerStyle(3);

  TGraphErrors *grStorage30 = new TGraphErrors(5, storage_30_expNum , storage_30 , 0 , storage_30Err);
  grStorage30 -> SetMarkerStyle(4);

  TGraphErrors *grStorage40 = new TGraphErrors(1, storage_40_expNum , storage_40 , 0 , storage_40Err);
  grStorage40 -> SetMarkerStyle(5);

  TGraphErrors *grStorage50 = new TGraphErrors(1, storage_50_expNum , storage_50 , 0 , storage_50Err);
  grStorage50 -> SetMarkerStyle(6);

  TGraphErrors *grStorage60 = new TGraphErrors(13, storage_60_expNum , storage_60 , 0 , storage_60Err);
  grStorage60 -> SetMarkerStyle(7);

  TGraphErrors *grStorage80 = new TGraphErrors(1, storage_80_expNum , storage_80 , 0 , storage_80Err);
  grStorage80 -> SetMarkerStyle(8);

  TGraphErrors *grStorage100 = new TGraphErrors(2, storage_100_expNum , storage_100 , 0 , storage_100Err);
  grStorage100 -> SetMarkerStyle(9);

  TGraphErrors *grStorage120 = new TGraphErrors(2, storage_120_expNum , storage_120 , 0 , storage_120Err);
  grStorage120 -> SetMarkerStyle(10);

  TGraphErrors *grStorage150 = new TGraphErrors(1, storage_150_expNum , storage_150 , 0 , storage_150Err);
  grStorage150 -> SetMarkerStyle(11);


  TLegend *leg = new TLegend(0.7,0.7, 0.9, 0.9);
  leg -> AddEntry(grStorage10 , "10s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage20 , "20s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage30 , "30s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage40 , "40s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage50 , "50s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage60 , "60s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage80 , "80s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage100 , "100s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage120 , "120s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage150 , "150s Irradiation time" , "p") ;

  grStorage10 -> Draw("ap");
  grStorage20 -> Draw("p");
  grStorage30 -> Draw("p");
  grStorage40 -> Draw("p");
  grStorage50 -> Draw("p");
  grStorage60 -> Draw("p");
  grStorage80 -> Draw("p");
  grStorage100 -> Draw("p");
  grStorage120 -> Draw("p");
  grStorage150 -> Draw("p");

  leg -> Draw();
}
