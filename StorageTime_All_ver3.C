// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS.
// I ALSO ADD THE BEAM CURRENT.
// ********************************************************************


void StorageTime_All_ver3(){
  gStyle->SetOptFit(0000);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");

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
  TFile *fin006A = new TFile("outputTree_StorageTime_17006A.root", "READ");


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
  TTree *outputTree006A = (TTree*) fin006A->Get("cycle_info");

 

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
  Int_t runNumber17;




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
  double delayTime17;

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
  double UCNIntegral17;
  
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
  double UCNIntegralErr17;

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
  double storagefit009_10_5muA;
  double storagefit009_10_10muA;
  double storagefit009_30_1expfit = 0;
  double storagefit009_60_1expfit = 0;

  double storagefit009A_10_1expfit = 0;
  double storagefit009A_10_low;
  double storagefit009A_10_high;
  double storagefit009A_30_1expfit = 0;
  double storagefit009A_30_3muA;
  double storagefit009A_30_9muA;
  double storagefit009A_30_12muA;
  double storagefit009A_60_1expfit = 0;
  double storagefit009A_60_1muA;
  double storagefit009A_60_3muA;
  double storagefit009A_60_8muA;
  double storagefit009A_120_1expfit = 0;

  double storagefit014_1expfit = 0;
  double storagefit029_1expfit = 0;

  double storagefit006A_1expfit = 0;


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
  double storageErrfit009_10_5muA;
  double storageErrfit009_10_10muA;
  double storageErrfit009_30_1expfit = 0;
  double storageErrfit009_60_1expfit = 0;

  double storageErrfit009A_10_1expfit = 0;
  double storageErrfit009A_10_low;
  double storageErrfit009A_10_high;
  double storageErrfit009A_30_1expfit = 0;
  double storageErrfit009A_30_3muA;
  double storageErrfit009A_30_9muA;
  double storageErrfit009A_30_12muA;
  double storageErrfit009A_60_1expfit = 0;
  double storageErrfit009A_60_1muA;
  double storageErrfit009A_60_3muA;
  double storageErrfit009A_60_8muA;
  double storageErrfit009A_120_1expfit = 0;

  double storageErrfit014_1expfit = 0;
  double storageErrfit029_1expfit = 0;
  double storageErrfit006A_1expfit = 0;

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
  int HistIntegral17;


  
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
  double avets12Irrad_006A;

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
  double maxts12Irrad_006A;

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
  double mints12Irrad_006A;


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
  double avets12ValveOpen_006A;

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
  double maxts12ValveOpen_006A;

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
  double mints12ValveOpen_006A;


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
  double baseline_006A;

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
  double baselineErr_006A;

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
  double baselineIrrad_006A;
 

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
  double irradStartTimes17;


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
  double cycleStartTimes17;


  // AVERAGE PREDICTED BEAM CURRENT
  double avecur_003;
  double avecur_013;
  double avecur_023;
  double avecur_025;
  double avecur_026;
  double avecur_029A;
  double avecur_031;
  double avecur_002;
  double avecur_006;
  double avecur_021;
  double avecur_004A;
  double avecur_004B;
  double avecur_009;
  double avecur_009A;
  double avecur_014;
  double avecur_029;
  double avecur_006A;


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
  outputTree006A -> SetBranchAddress ("runNumber" , &runNumber17);

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
  outputTree006A -> SetBranchAddress ("cycleDelayTime", &delayTime17);
   
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
  outputTree006A -> SetBranchAddress ("UCNIntegral", &UCNIntegral17);

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
  outputTree006A -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr17);

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
  outputTree006A -> SetBranchAddress ("HistIntegral" , &HistIntegral17);

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
  outputTree006A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_006A);


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
  outputTree006A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes17);


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
  outputTree006A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes17);


  // SET THE BRANCH ADDRESS TO GET THE AVERAGE PREDICTED CURRENT
  outputTree003 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_003);
  outputTree013 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_013);
  outputTree023 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_023);
  outputTree025 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_025);
  outputTree026 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_026);
  outputTree029A -> SetBranchAddress ("AVE_PRDCUR" , &avecur_029A);
  outputTree031 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_031);
  outputTree002 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_002);
  outputTree006 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_006);
  outputTree021 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_021);
  outputTree004A -> SetBranchAddress ("AVE_PRDCUR" , &avecur_004A);
  outputTree004B -> SetBranchAddress ("AVE_PRDCUR" , &avecur_004B);
  outputTree009 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_009);
  outputTree009A -> SetBranchAddress ("AVE_PRDCUR" , &avecur_009A);
  outputTree014 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_014);
  outputTree029 -> SetBranchAddress ("AVE_PRDCUR" , &avecur_029);
  outputTree006A -> SetBranchAddress ("AVE_PRDCUR" , &avecur_006A);

  // AVERAGE ISOPURE TEMPERATURE DURING IRRADIATION AND DELAY
  // (STORAGE TIME)
  outputTree003-> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_003);
  outputTree013-> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_013);
  outputTree023-> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_023);
  outputTree025 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_025);
  outputTree026 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_026);
  outputTree029A -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_029A);
  outputTree031 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_031);
  outputTree002 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_002);
  outputTree006 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_006);
  outputTree021 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_021);
  outputTree004A -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_004A);
  outputTree004B -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_004B);
  outputTree009 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_009);
  outputTree009A -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_009A);
  outputTree014 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_014);
  outputTree029 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_029);
  outputTree006A -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad_006A);



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
  Double_t delayTimeArray13_10_5muA[100] = 0;
  Double_t delayTimeArray13_10_10muA[100] = 0;
  Double_t delayTimeArray13_30[100] = 0;
  Double_t delayTimeArray13_60[100] = 0;

  Double_t delayTimeArray14[100] = 0;
  Double_t delayTimeArray14_10[100] = 0;
  Double_t delayTimeArray14_10_low[100] = 0;
  Double_t delayTimeArray14_10_high[100] = 0;
  Double_t delayTimeArray14_30[100] = 0;
  Double_t delayTimeArray14_30_3muA[100] = 0;
  Double_t delayTimeArray14_30_9muA[100] = 0;
  Double_t delayTimeArray14_30_12muA[100] = 0;
  Double_t delayTimeArray14_60[100] = 0;
  Double_t delayTimeArray14_60_1muA[100] = 0;
  Double_t delayTimeArray14_60_3muA[100] = 0;
  Double_t delayTimeArray14_60_8muA[100] = 0;
  Double_t delayTimeArray14_120[100] = 0;


  Double_t delayTimeArray15[100] = 0;
  Double_t delayTimeArray16[100] = 0;
  Double_t delayTimeArray17[100] = 0;

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
  Double_t UCNIntegralArray13_10_5muA[100] = 0;
  Double_t UCNIntegralArray13_10_10muA[100] = 0;
  Double_t UCNIntegralArray13_30[100] = 0;
  Double_t UCNIntegralArray13_60[100] = 0;

  Double_t UCNIntegralArray14[100] = 0;
  Double_t UCNIntegralArray14_10[100] = 0;
  Double_t UCNIntegralArray14_10_low[100] = 0;
  Double_t UCNIntegralArray14_10_high[100] = 0;
  Double_t UCNIntegralArray14_30[100] = 0;
  Double_t UCNIntegralArray14_30_3muA[100] = 0;
  Double_t UCNIntegralArray14_30_9muA[100] = 0;
  Double_t UCNIntegralArray14_30_12muA[100] = 0;
  Double_t UCNIntegralArray14_60[100] = 0;
  Double_t UCNIntegralArray14_60_1muA[100] = 0;
  Double_t UCNIntegralArray14_60_3muA[100] = 0;
  Double_t UCNIntegralArray14_60_8muA[100] = 0;
  Double_t UCNIntegralArray14_120[100] = 0;

  Double_t UCNIntegralArray15[100] = 0;
  Double_t UCNIntegralArray16[100] = 0;
  Double_t UCNIntegralArray17[100] = 0;

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
  Double_t UCNIntegralErrArray13_10_5muA[100] = 0;
  Double_t UCNIntegralErrArray13_10_10muA[100] = 0;
  Double_t UCNIntegralErrArray13_30[100] = 0;
  Double_t UCNIntegralErrArray13_60[100] = 0;

  Double_t UCNIntegralErrArray14[100] = 0;
  Double_t UCNIntegralErrArray14_10[100] = 0;
  Double_t UCNIntegralErrArray14_10_low[100] = 0;
  Double_t UCNIntegralErrArray14_10_high[100] = 0;
  Double_t UCNIntegralErrArray14_30[100] = 0;
  Double_t UCNIntegralErrArray14_30_3muA[100] = 0;
  Double_t UCNIntegralErrArray14_30_9muA[100] = 0;
  Double_t UCNIntegralErrArray14_30_12muA[100] = 0;
  Double_t UCNIntegralErrArray14_60[100] = 0;
  Double_t UCNIntegralErrArray14_60_1muA[100] = 0;
  Double_t UCNIntegralErrArray14_60_3muA[100] = 0;
  Double_t UCNIntegralErrArray14_60_8muA[100] = 0;
  Double_t UCNIntegralErrArray14_120[100] = 0;

  Double_t UCNIntegralErrArray15[100] = 0;
  Double_t UCNIntegralErrArray16[100] = 0;
  Double_t UCNIntegralErrArray17[100] = 0;

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
  Double_t HistIntegralArray13_10_5muA[100] = 0;
  Double_t HistIntegralArray13_10_10muA[100] = 0;
  Double_t HistIntegralArray13_30[100] = 0;
  Double_t HistIntegralArray13_60[100] = 0;

  Double_t HistIntegralArray14[100] = 0;
  Double_t HistIntegralArray14_10[100] = 0;
  Double_t HistIntegralArray14_10_low[100] = 0;
  Double_t HistIntegralArray14_10_high[100] = 0;
  Double_t HistIntegralArray14_30[100] = 0;
  Double_t HistIntegralArray14_30_3muA[100] = 0;
  Double_t HistIntegralArray14_30_9muA[100] = 0;
  Double_t HistIntegralArray14_30_12muA[100] = 0;
  Double_t HistIntegralArray14_60[100] = 0;
  Double_t HistIntegralArray14_60_1muA[100] = 0;
  Double_t HistIntegralArray14_60_3muA[100] = 0;
  Double_t HistIntegralArray14_60_8muA[100] = 0;
  Double_t HistIntegralArray14_120[100] = 0;

  Double_t HistIntegralArray15[100] = 0;
  Double_t HistIntegralArray16[100] = 0;
  Double_t HistIntegralArray17[100] = 0;

  // ERROR ASSOCIATED WITH THE HISTOGRAM INTEGRALS
  Double_t HistIntegralErrArray1[100] = 0;
  Double_t HistIntegralErrArray2[100] = 0;
  Double_t HistIntegralErrArray3[100] = 0;
  Double_t HistIntegralErrArray4[100] = 0;
  Double_t HistIntegralErrArray5[100] = 0;
  Double_t HistIntegralErrArray6[100] = 0;
  Double_t HistIntegralErrArray7[100] = 0;
  Double_t HistIntegralErrArray8[100] = 0;
  Double_t HistIntegralErrArray9[100] = 0;
  Double_t HistIntegralErrArray10[100] = 0;

  Double_t HistIntegralErrArray11[100] = 0;
  Double_t HistIntegralErrArray11_150[100] = 0;
  Double_t HistIntegralErrArray11_10[100] = 0;
  Double_t HistIntegralErrArray11_20[100] = 0;
  Double_t HistIntegralErrArray11_30[100] = 0;
  Double_t HistIntegralErrArray11_40[100] = 0;
  Double_t HistIntegralErrArray11_50[100] = 0;
  Double_t HistIntegralErrArray11_60[100] = 0;
  Double_t HistIntegralErrArray11_80[100] = 0;
  Double_t HistIntegralErrArray11_100[100] = 0;
  Double_t HistIntegralErrArray11_120[100] = 0;

  Double_t HistIntegralErrArray12[100] = 0;

  Double_t HistIntegralErrArray13[100] = 0;
  Double_t HistIntegralErrArray13_10[100] = 0;
  Double_t HistIntegralErrArray13_10_5muA[100] = 0;
  Double_t HistIntegralErrArray13_10_10muA[100] = 0;
  Double_t HistIntegralErrArray13_30[100] = 0;
  Double_t HistIntegralErrArray13_60[100] = 0;

  Double_t HistIntegralErrArray14[100] = 0;
  Double_t HistIntegralErrArray14_10[100] = 0;
  Double_t HistIntegralErrArray14_10_low[100] = 0;
  Double_t HistIntegralErrArray14_10_high[100] = 0;
  Double_t HistIntegralErrArray14_30[100] = 0;
  Double_t HistIntegralErrArray14_30_3muA[100] = 0;
  Double_t HistIntegralErrArray14_30_9muA[100] = 0;
  Double_t HistIntegralErrArray14_30_12muA[100] = 0;
  Double_t HistIntegralErrArray14_60[100] = 0;
  Double_t HistIntegralErrArray14_60_1muA[100] = 0;
  Double_t HistIntegralErrArray14_60_3muA[100] = 0;
  Double_t HistIntegralErrArray14_60_8muA[100] = 0;
  Double_t HistIntegralErrArray14_120[100] = 0;

  Double_t HistIntegralErrArray15[100] = 0;
  Double_t HistIntegralErrArray16[100] = 0;
  Double_t HistIntegralErrArray17[100] = 0;

  
  //IRRADIAITON START TIME
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
  Double_t irradTimeArray17[100] = 0;

  // AVERAGE PREDICTED CURRENT ARRAY
  Double_t curArray003[100] = 0;
  Double_t curArray013[100] = 0;
  Double_t curArray023[100] = 0;
  Double_t curArray025[100] = 0;
  Double_t curArray026[100] = 0;
  Double_t curArray029A[100] = 0;
  Double_t curArray031[100] = 0;
  Double_t curArray002[100] = 0;
  Double_t curArray006[100] = 0;
  Double_t curArray021[100] = 0;
  Double_t curArray004A[100] = 0;
  Double_t curArray004B[100] = 0;

  Double_t curArray009_10[100] = 0;
  Double_t curArray009_10_5muA[100] = 0;
  Double_t curArray009_10_10muA[100] = 0;
  Double_t curArray009_30[100] = 0;
  Double_t curArray009_60[100] = 0;

  Double_t curArray009A_10[100] = 0;
  Double_t curArray009A_10_low[100] = 0;
  Double_t curArray009A_10_high[100] = 0;
  Double_t curArray009A_30[100] = 0;
  Double_t curArray009A_30_3muA[100] = 0;
  Double_t curArray009A_30_9muA[100] = 0;
  Double_t curArray009A_30_12muA[100] = 0;
  Double_t curArray009A_60[100] = 0;
  Double_t curArray009A_60_1muA[100] = 0;
  Double_t curArray009A_60_3muA[100] = 0;
  Double_t curArray009A_60_8muA[100] = 0;
  Double_t curArray009A_120[100] = 0;

  Double_t curArray014[100] = 0;
  Double_t curArray029[100] = 0;
  Double_t curArray006A[100] = 0;


 // AVERAGE OF AVERAGES OF TEMPERATURE
  double aveT003_valveopen;
  double aveT013_valveopen;
  double aveT023_valveopen;
  double aveT025_valveopen;
  double aveT026_valveopen;
  double aveT029A_valveopen;
  double aveT031_valveopen;
  double aveT002_valveopen;
  double aveT006_valveopen;
  double aveT021_valveopen;

  double aveT004B_valveopen;

  double aveT009_10_valveopen;
  double aveT009_30_valveopen;
  double aveT009_60_valveopen;

  double aveT009A_10_valveopen;
  double aveT009A_30_valveopen;
  double aveT009A_60_valveopen;
  double aveT009A_120_valveopen;

  double aveT014_valveopen;
  double aveT029_valveopen;
  double aveT006A_valveopen;

 // STANDARD DEVIATION FROM THE AVERAGE OF AVERAGES OF TEMPERATURE
  double sdT003_valveopen;
  double sdT013_valveopen;
  double sdT023_valveopen;
  double sdT025_valveopen;
  double sdT026_valveopen;
  double sdT029A_valveopen;
  double sdT031_valveopen;
  double sdT002_valveopen;
  double sdT006_valveopen;
  double sdT021_valveopen;

  double sdT004B_valveopen;

  double sdT009_10_valveopen;
  double sdT009_30_valveopen;
  double sdT009_60_valveopen;

  double sdT009A_10_valveopen;
  double sdT009A_30_valveopen;
  double sdT009A_60_valveopen;
  double sdT009A_120_valveopen;

  double sdT014_valveopen;
  double sdT029_valveopen;
  double sdT006A_valveopen;

  // AVERAGE OF AVERAGES OF TEMPERATURE DURING IRRADIATION TIME

  double aveT003_irrad;
  double aveT013_irrad;
  double aveT023_irrad;
  double aveT025_irrad;
  double aveT026_irrad;
  double aveT029A_irrad;
  double aveT031_irrad;
  double aveT002_irrad;
  double aveT006_irrad;
  double aveT021_irrad;

  double aveT004B_irrad;

  double aveT009_10_irrad;
  double aveT009_30_irrad;
  double aveT009_60_irrad;

  double aveT009A_10_irrad;
  double aveT009A_30_irrad;
  double aveT009A_60_irrad;
  double aveT009A_120_irrad;

  double aveT014_irrad;
  double aveT029_irrad;
  double aveT006A_irrad;
  
  // TEMP ARRAYS DURING IRRADIATION
  double tempArrayIrrad_003 [100] = 0;
  double tempArrayIrrad_013 [100] = 0;
  double tempArrayIrrad_023 [100] = 0;
  double tempArrayIrrad_025 [100] = 0;
  double tempArrayIrrad_026 [100] = 0;
  double tempArrayIrrad_029A [100] = 0;
  double tempArrayIrrad_031 [100] = 0;
  double tempArrayIrrad_002 [100] = 0;
  double tempArrayIrrad_006 [100] = 0;
  double tempArrayIrrad_021 [100] = 0;

  double tempArrayIrrad_004B [100] = 0;

  double tempArrayIrrad_009_10 [100] = 0;
  double tempArrayIrrad_009_10_5muA[100] = 0;
  double tempArrayIrrad_009_10_10muA[100] = 0;
  double tempArrayIrrad_009_30 [100] = 0;
  double tempArrayIrrad_009_60 [100] = 0;

  double tempArrayIrrad_009A_10 [100] = 0;
  double tempArrayIrrad_009A_10_low[100] = 0;
  double tempArrayIrrad_009A_10_high[100] = 0;
  double tempArrayIrrad_009A_30 [100] = 0;
  double tempArrayIrrad_009A_30_3muA[100] = 0;
  double tempArrayIrrad_009A_30_9muA[100] = 0;
  double tempArrayIrrad_009A_30_12muA[100] = 0;
  double tempArrayIrrad_009A_60 [100] = 0;
  double tempArrayIrrad_009A_60_1muA[100] = 0;
  double tempArrayIrrad_009A_60_3muA[100] = 0;
  double tempArrayIrrad_009A_60_8muA[100] = 0;
  double tempArrayIrrad_009A_120 [100] = 0;

  double tempArrayIrrad_014 [100] = 0;
  double tempArrayIrrad_029 [100] = 0;
  double tempArrayIrrad_006A [100] = 0;

  // STANDARD DEVIATION FROM THE AVERAGE OF AVERAGES OF TEMPERATURE
  // DURING THE IRRADIAITON

  double sdT003_irrad;
  double sdT013_irrad;
  double sdT023_irrad;
  double sdT025_irrad;
  double sdT026_irrad;
  double sdT029A_irrad;
  double sdT031_irrad;
  double sdT002_irrad;
  double sdT006_irrad;
  double sdT021_irrad;

  double sdT004B_irrad;

  double sdT009_10_irrad;
  double sdT009_30_irrad;
  double sdT009_60_irrad;

  double sdT009A_10_irrad;
  double sdT009A_30_irrad;
  double sdT009A_60_irrad;
  double sdT009A_120_irrad;

  double sdT014_irrad;
  double sdT029_irrad;
  double sdT006A_irrad;


  // FOR INTEGRATED BEAM CURRENT WHICH IS CURRENT * IRRADIATION TIME
  double integCur003[100] = 0;
  double integCur013[100] = 0;
  double integCur023[100] = 0;
  double integCur025[100] = 0;
  double integCur026[100] = 0;
  double integCur029a[100] = 0;
  double integCur031[100] = 0;
  double integCur002[100] = 0;
  double integCur006[100] = 0;
  double integCur021[100] = 0;
  double integCur004b[100] = 0;
  double integCur009[100] = 0;
  double integCur009a[100] = 0;
  double integCur014[100] = 0;
  double integCur029[100] = 0;
  double integCur006a[100] = 0;


  // AVERAGE OF AVERAGE PREDICTED CURRENT
  double  aveavecur003;
  double  aveavecur013;
  double  aveavecur023;
  double  aveavecur025;
  double  aveavecur026;
  double  aveavecur029A;
  double  aveavecur031;
  double  aveavecur002;
  double  aveavecur006;
  double  aveavecur021;
  
  double  aveavecur004B;

  double  aveavecur009_10;
  double  aveavecur009_30;
  double  aveavecur009_60;
  
  double  aveavecur009A_10;
  double  aveavecur009A_30;
  double  aveavecur009A_60;
  double  aveavecur009A_120;

  double  aveavecur014;
  double  aveavecur029;
  double  aveavecur006A;


  // STANDARD DEVIATION OF AVERAGE PREDICTED CURRENT

  double  sdcur003;
  double  sdcur013;
  double  sdcur023;
  double  sdcur025;
  double  sdcur026;
  double  sdcur029A;
  double  sdcur031;
  double  sdcur002;
  double  sdcur006;
  double  sdcur021;
  
  double  sdcur004B;

  double  sdcur009_10;
  double  sdcur009_30;
  double  sdcur009_60;
  
  double  sdcur009A_10;
  double  sdcur009A_30;
  double  sdcur009A_60;
  double  sdcur009A_120;

  double  sdcur014;
  double  sdcur029;
  double  sdcur006A;


  // COUNTS FOR THE READING LOOPS
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
  Int_t counts13_10_5muA = 0;
  Int_t counts13_10_10muA = 0;
  Int_t counts13_30 = 0;
  Int_t counts13_60 = 0;

  Int_t counts14 = 0;
  Int_t counts14_10 = 0;
  Int_t counts14_10_low = 0;
  Int_t counts14_10_high = 0;
  Int_t counts14_30 = 0;
  Int_t counts14_30_3muA = 0;
  Int_t counts14_30_9muA = 0;
  Int_t counts14_30_12muA = 0;
  Int_t counts14_60 = 0;
  Int_t counts14_60_1muA = 0;
  Int_t counts14_60_3muA = 0;
  Int_t counts14_60_8muA = 0;
  Int_t counts14_120 = 0;

  Int_t counts15 = 0;
  Int_t counts16 = 0;
  Int_t counts17 = 0;


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

  // GET THE EVENTS FOR TCN17006A
  ULong64_t event17;
  event17 = (Double_t)outputTree006A->GetEntries();



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
    HistIntegralErrArray1[j] = sqrt(HistIntegral1);
    irradTimeArray1[j] = cycleStartTimes1 - irradStartTimes1;
    aveT003_valveopen+=avets12ValveOpen_003;
    aveT003_irrad+=avets12Irrad_003;
    aveavecur003+=avecur_003;
    curArray003[j] = avecur_003;
    tempArrayIrrad_003[j] = avets12Irrad_003;
    //cout << tempArrayIrrad_003[j] << endl;
    integCur003[j] = avecur_003*irradTimeArray1[j];
    counts1++;
  }

  aveT003_valveopen = aveT003_valveopen/counts1;
  aveT003_irrad = aveT003_irrad/counts1;
  aveavecur003 = aveavecur003/counts1;

  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree003-> GetEvent(j);
    if ( HistIntegral1 < 2000)
      continue;
    sdT003_valveopen += (avets12ValveOpen_003 - aveT003_valveopen)* (avets12ValveOpen_003 - aveT003_valveopen);
    sdT003_irrad += (avets12Irrad_003 - aveT003_irrad)* (avets12Irrad_003 - aveT003_irrad);
    sdcur003 += (avecur_003 - aveavecur003)*(avecur_003 - aveavecur003);
  }
  sdT003_valveopen = sqrt (sdT003_valveopen/counts1);
  sdT003_irrad = sqrt (sdT003_irrad/counts1);
  sdcur003 = sqrt(sdcur003/counts1);
  //cout << aveT003_valveopen << "    " << sdT003_valveopen << endl;
  //cout << aveavecur003 << " " << sdcur003 << endl;

  // FOR TCN17013
  for (ULong64_t j = 0 ; j < event2 ; j++){
    outputTree013-> GetEvent(j);
    UCNIntegralArray2[j] = UCNIntegral2;
    UCNIntegralErrArray2[j] = UCNIntegralErr2;
    delayTimeArray2[j] = delayTime2;
    HistIntegralArray2[j] = HistIntegral2;
    HistIntegralErrArray2[j] = sqrt(HistIntegral2);
    irradTimeArray2[j] = cycleStartTimes2 - irradStartTimes2;
    aveT013_valveopen+=avets12ValveOpen_013;
    aveT013_irrad += avets12Irrad_013;
    curArray013[j] = avecur_013;
    aveavecur013 += avecur_013;
    tempArrayIrrad_013[j] = avets12Irrad_013;
    integCur013[j] = avecur_013*irradTimeArray2[j];
    counts2++;
  }

  aveT013_valveopen = aveT013_valveopen/counts2;
  aveT013_irrad = aveT013_irrad/counts2;
  aveavecur013 = aveavecur013/counts2;

  for (ULong64_t j = 0 ; j < event2 ; j++){
    outputTree013-> GetEvent(j);
    sdT013_valveopen += (avets12ValveOpen_013 - aveT013_valveopen)* (avets12ValveOpen_013 - aveT013_valveopen);
    sdT013_irrad += (avets12Irrad_013 - aveT013_irrad)* (avets12Irrad_013 - aveT013_irrad);
    sdcur013 += (avecur_013 - aveavecur013)*(avecur_013 - aveavecur013);
  }
  sdT013_valveopen = sqrt (sdT013_valveopen/counts2);
  sdT013_irrad = sqrt (sdT013_irrad/counts2);
  sdcur013 = sqrt ( sdcur013/counts2);
  //  cout << aveT013_valveopen << "    " << sdT013_valveopen << endl;
  //cout << aveT013_irrad << " " << sdT013_irrad << endl;
  //cout << aveavecur013 << " " << sdcur013 << endl;

  // FOR TCN17023
  for (ULong64_t j = 0 ; j < event3 ; j++){
    outputTree023 -> GetEvent(j);
    //if ( UCNIntegralErr3 > 2000)
    // continue;
    UCNIntegralArray3[j] = UCNIntegral3;
    UCNIntegralErrArray3[j] = UCNIntegralErr3;
    delayTimeArray3[j] = delayTime3;
    HistIntegralArray3[j] = HistIntegral3;
    HistIntegralErrArray3[j] = sqrt(HistIntegral3);
    irradTimeArray3[j] = cycleStartTimes3 - irradStartTimes3;
    aveT023_valveopen+=avets12ValveOpen_023;
    aveT023_irrad+= avets12Irrad_023;
    curArray023[j] = avecur_023;
    aveavecur023 += avecur_023;
    tempArrayIrrad_023[j] = avets12Irrad_023;
    integCur023[j] = avecur_023*irradTimeArray3[j];
    counts3++;
  }
  aveT023_valveopen = aveT023_valveopen/counts3;
  aveT023_irrad = aveT023_irrad/counts3;
  aveavecur023 = aveavecur023/counts3;
  for (ULong64_t j = 0 ; j < event3 ; j++){
    outputTree023 -> GetEvent(j);
    sdT023_valveopen += (avets12ValveOpen_023 - aveT023_valveopen)* (avets12ValveOpen_023 - aveT023_valveopen);
    sdT023_irrad += (avets12Irrad_023 - aveT023_irrad)* (avets12Irrad_023 - aveT023_irrad);
    sdcur023 += (avecur_023 - aveavecur023)*(avecur_023 - aveavecur023);
  }
  sdT023_valveopen = sqrt (sdT023_valveopen/counts3);
  sdT023_irrad = sqrt (sdT023_irrad/counts3);
  sdcur023 = sqrt (sdcur023/counts3);
  //   cout << aveT023_valveopen << "    " << sdT023_valveopen << endl;
  //cout << aveavecur023 << " " << sdcur023 << endl;

  // FOR TCN17025
  for (ULong64_t j = 0 ; j < event4 ; j++){
    outputTree025 -> GetEvent(j);
    UCNIntegralArray4[j] = UCNIntegral4;
    UCNIntegralErrArray4[j] = UCNIntegralErr4;
    delayTimeArray4[j] = delayTime4;
    HistIntegralArray4[j] = HistIntegral4;
    HistIntegralErrArray4[j] = sqrt(HistIntegral4);
    irradTimeArray4[j] = cycleStartTimes4 - irradStartTimes4;
    aveT025_valveopen+=avets12ValveOpen_025;
    aveT025_irrad+=avets12Irrad_025;
    curArray025[j] = avecur_025;
    aveavecur025 += avecur_025;
    tempArrayIrrad_025[j] = avets12Irrad_025;
    integCur025[j] = avecur_025*irradTimeArray4[j];
    counts4++;
  }
  aveT025_valveopen = aveT025_valveopen/counts4;
  aveT025_irrad = aveT025_irrad/counts4;
  aveavecur025 = aveavecur025/counts4;

  for (ULong64_t j = 0 ; j < event4 ; j++){
    outputTree025 -> GetEvent(j);
    sdT025_valveopen += (avets12ValveOpen_025 - aveT025_valveopen)* (avets12ValveOpen_025 - aveT025_valveopen);
    sdT025_irrad += (avets12Irrad_025 - aveT025_irrad)* (avets12Irrad_025 - aveT025_irrad);
    sdcur025 += (avecur_025 - aveavecur025)*(avecur_025 - aveavecur025);
  }
  sdT025_valveopen = sqrt (sdT025_valveopen/counts4);
  sdT025_irrad = sqrt (sdT025_irrad/counts4);
  sdcur025 = sqrt (sdcur025/counts4);
  //cout << aveT025_valveopen << "    " << sdT025_valveopen << endl;
  //cout << aveavecur025 << " " << sdcur025 << endl;

  // FOR TCN17026
  for (ULong64_t j = 0 ; j < event5 ; j++){
    outputTree026 -> GetEvent(j);
    UCNIntegralArray5[j] = UCNIntegral5;
    UCNIntegralErrArray5[j] = UCNIntegralErr5;
    delayTimeArray5[j] = delayTime5;
    HistIntegralArray5[j] = HistIntegral5;
    irradTimeArray5[j] = cycleStartTimes5 - irradStartTimes5;
    HistIntegralErrArray5[j] = sqrt(HistIntegral5);
    curArray026[j] = avecur_026;
    aveavecur026 += avecur_026;
    tempArrayIrrad_026[j] = avets12Irrad_026;
    if (j <event5-1){
      aveT026_valveopen +=avets12ValveOpen_026;
      aveT026_irrad +=avets12Irrad_026;
    }
    integCur026[j] = avecur_026*irradTimeArray5[j];
    counts5++;
  }
  aveT026_valveopen = aveT026_valveopen/(counts5-1);
  aveT026_irrad = aveT026_irrad/(counts5-1);
  aveavecur026 = aveavecur026/ counts5;

  for (ULong64_t j = 0 ; j < event5-1 ; j++){
    outputTree026 -> GetEvent(j);
    sdT026_valveopen += (avets12ValveOpen_026 - aveT026_valveopen)* (avets12ValveOpen_026 - aveT026_valveopen);
    sdT026_irrad += (avets12Irrad_026 - aveT026_irrad)* (avets12Irrad_026 - aveT026_irrad);
    sdcur026 += (avecur_026 - aveavecur026)*(avecur_026 - aveavecur026);
    //    cout << sdT026_valveopen << endl;
  }

  sdT026_valveopen = sqrt (sdT026_valveopen/(counts5-1));
  sdT026_irrad = sqrt (sdT026_irrad/(counts5-1));
  sdcur026 = sqrt (sdcur026/counts5);
  //cout << aveT026_valveopen << "    " << sdT026_valveopen << endl;
  //cout << aveavecur026 << " " << sdcur026 << endl;

  // FOR TCN17029A
  for (ULong64_t j = 0 ; j < event6 ; j++){
    outputTree029A -> GetEvent(j);
    UCNIntegralArray6[j] = UCNIntegral6;
    UCNIntegralErrArray6[j] = UCNIntegralErr6;
    delayTimeArray6[j] = delayTime6;
    HistIntegralArray6[j] = HistIntegral6;
    HistIntegralErrArray6[j] = sqrt(HistIntegral6);
    irradTimeArray6[j] = cycleStartTimes6 - irradStartTimes6;
    // cout << avets12Irrad_029A << endl;
    aveT029A_valveopen+=avets12ValveOpen_029A;
    aveT029A_irrad+=avets12Irrad_029A;
    curArray029A[j] = avecur_029A;
    aveavecur029A += avecur_029A;
    tempArrayIrrad_029A[j] = avets12Irrad_029A;
    integCur029a[j] = avecur_029A*irradTimeArray6[j];
    counts6++;
  }
  aveT029A_valveopen = aveT029A_valveopen/counts6;
  aveT029A_irrad = aveT029A_irrad/counts6;
  aveavecur029A = aveavecur029A/counts6;

  for (ULong64_t j = 0 ; j < event6 ; j++){
    outputTree029A -> GetEvent(j);
    sdT029A_valveopen += (avets12ValveOpen_029A - aveT029A_valveopen)* (avets12ValveOpen_029A - aveT029A_valveopen);
    sdT029A_irrad += (avets12Irrad_029A - aveT029A_irrad)* (avets12Irrad_029A - aveT029A_irrad);
    sdcur029A += (avecur_029A - aveavecur029A)*(avecur_029A - aveavecur029A);
  }
  sdT029A_valveopen = sqrt (sdT029A_valveopen/counts6);
  sdT029A_irrad = sqrt (sdT029A_irrad/counts6);
  sdcur029A = sqrt (sdcur029A/counts6);
  //    cout << aveT029A_valveopen << "    " << sdT029A_valveopen << endl;
  //cout << aveT029A_irrad << " " << sdT029A_irrad << endl;
  //cout << aveavecur029A << " " << sdcur029A << endl;

  // FOR TCN17031
  for (ULong64_t j = 0 ; j < event7 ; j++){
    outputTree031 -> GetEvent(j);
    UCNIntegralArray7[j] = UCNIntegral7;
    UCNIntegralErrArray7[j] = UCNIntegralErr7;
    delayTimeArray7[j] = delayTime7;
    HistIntegralArray7[j] = HistIntegral7;
    HistIntegralErrArray7[j] = sqrt(HistIntegral7);
    irradTimeArray7[j] = cycleStartTimes7 - irradStartTimes7;
    aveT031_valveopen+=avets12ValveOpen_031;
    aveT031_irrad+=avets12Irrad_031;
    curArray031[j] = avecur_031;
    aveavecur031 += avecur_031;
    tempArrayIrrad_031[j] = avets12Irrad_031;
    integCur031[j] = avecur_031*irradTimeArray7[j];
    //cout << avecur_031 << endl;
    counts7++;
  }
  aveT031_valveopen = aveT031_valveopen/counts7;
  aveT031_irrad = aveT031_irrad/counts7;
  aveavecur031 = aveavecur031/counts7;

  for (ULong64_t j = 0 ; j < event7 ; j++){
    outputTree031 -> GetEvent(j);
    sdT031_valveopen += (avets12ValveOpen_031 - aveT031_valveopen)* (avets12ValveOpen_031 - aveT031_valveopen);
    sdT031_irrad += (avets12Irrad_031 - aveT031_irrad)* (avets12Irrad_031 - aveT031_irrad);
    sdcur031 += (avecur_031 - aveavecur031)*(avecur_031 - aveavecur031);
  }
  sdT031_valveopen = sqrt (sdT031_valveopen/counts7);
  sdT031_irrad = sqrt (sdT031_irrad/counts7);
  sdcur031 = sqrt (sdcur031/counts7);
  // cout << aveT031_valveopen << "    " << sdT031_valveopen << endl;
  //cout << aveavecur031 << " " << sdcur031 << endl;


  // FOR TCN17002
  for (ULong64_t j = 0 ; j < event8 ; j++){
    outputTree002 -> GetEvent(j);
    if (UCNIntegral8 < 1000){
      continue;
    }
    UCNIntegralArray8[j] = UCNIntegral8;
    UCNIntegralErrArray8[j] = UCNIntegralErr8;
    delayTimeArray8[j] = delayTime8;
    HistIntegralArray8[j] = HistIntegral8;
    HistIntegralErrArray8[j] = sqrt(HistIntegral8);
    irradTimeArray8[j] = cycleStartTimes8 - irradStartTimes8;
    aveT002_valveopen+=avets12ValveOpen_002;
    aveT002_irrad+=avets12Irrad_002;
    curArray002[j] = avecur_002;
    aveavecur002 += avecur_002;
    tempArrayIrrad_002[j] = avets12Irrad_002;
    integCur002[j] = avecur_002*irradTimeArray8[j];
    //cout << avecur_002 << endl;
    counts8++;
  }

  aveT002_valveopen = aveT002_valveopen/counts8;
  aveT002_irrad = aveT002_irrad/counts8;
  aveavecur002 = aveavecur002/counts8;
  
  for (ULong64_t j = 0 ; j < event8 ; j++){
    outputTree002 -> GetEvent(j);
    sdT002_valveopen += (avets12ValveOpen_002 - aveT002_valveopen)* (avets12ValveOpen_002 - aveT002_valveopen);
    sdT002_irrad += (avets12Irrad_002 - aveT002_irrad)* (avets12Irrad_002 - aveT002_irrad);
    sdcur002 += (avecur_002 - aveavecur002)*(avecur_002 - aveavecur002);
  }
  sdT002_valveopen = sqrt (sdT002_valveopen/counts8);
  sdT002_irrad = sqrt (sdT002_irrad/counts8);
  sdcur002 = sqrt (sdcur002/counts8);
  //cout << aveT002_valveopen << "    " << sdT002_valveopen << endl;
  cout << aveavecur002 << " " << sdcur002 << endl;


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
    HistIntegralErrArray9[j] = sqrt(HistIntegral9);
    irradTimeArray9[j] = cycleStartTimes9 - irradStartTimes9;
    aveT006_valveopen+=avets12ValveOpen_006;
    aveT006_irrad+=avets12Irrad_006;
    curArray006[j] = avecur_006;
    aveavecur006 += avecur_006;
    tempArrayIrrad_006[j] = avets12Irrad_006;
    integCur006[j] = avecur_006*irradTimeArray9[j];
    counts9++;
  }
  aveT006_valveopen = aveT006_valveopen/counts9;
  aveT006_irrad = aveT006_irrad/counts9;
  aveavecur006 = aveavecur006/counts9;

  for (ULong64_t j = 0 ; j < event9 ; j++){
    outputTree002 -> GetEvent(j);
    if ( UCNIntegral9 < 10000 && delayTime9 <10 )
      continue;
    if (UCNIntegral9 < 100)
      continue;
    sdT006_valveopen += (avets12ValveOpen_006 - aveT006_valveopen)* (avets12ValveOpen_006 - aveT006_valveopen);
    sdT006_irrad += (avets12Irrad_006 - aveT006_irrad)* (avets12Irrad_006 - aveT006_irrad);
    sdcur006 += (avecur_006 - aveavecur006)*(avecur_006 - aveavecur006);
  }
  sdT006_valveopen = sqrt (sdT006_valveopen/counts9);
  sdT006_irrad = sqrt (sdT006_irrad/counts9);
  sdcur006 = sqrt (sdcur006/counts9);
  //cout << aveT006_valveopen << "    " << sdT006_valveopen << endl;
  //cout << aveavecur006 << " " << sdcur006 << endl;

  // FOR TCN17021
  for (ULong64_t j = 0 ; j < event10 ; j++){
    outputTree021 -> GetEvent(j);
    UCNIntegralArray10[j] = UCNIntegral10;
    UCNIntegralErrArray10[j] = UCNIntegralErr10;
    delayTimeArray10[j] = delayTime10;
    HistIntegralArray10[j] = HistIntegral10;
    HistIntegralErrArray10[j] = sqrt(HistIntegral10);
    irradTimeArray10[j] = cycleStartTimes10 - irradStartTimes10;
    aveT021_valveopen+=avets12ValveOpen_021;
    aveT021_irrad+=avets12Irrad_021;
    curArray021[j] = avecur_021;
    aveavecur021 += avecur_021;
    tempArrayIrrad_021[j] = avets12Irrad_021;
    //cout << tempArrayIrrad_021[j] << endl;
    integCur021[j] = avecur_021*irradTimeArray10[j];
    counts10++;
  }

  aveT021_valveopen = aveT021_valveopen/counts10;
  aveT021_irrad = aveT021_irrad/counts10;
  aveavecur021 = aveavecur021/counts10;

  for (ULong64_t j = 0 ; j < event10 ; j++){
    outputTree021 -> GetEvent(j);
    sdT021_valveopen += (avets12ValveOpen_021 - aveT021_valveopen)* (avets12ValveOpen_021 - aveT021_valveopen);
    sdT021_irrad += (avets12Irrad_021 - aveT021_irrad)* (avets12Irrad_021 - aveT021_irrad);
    sdcur021 += (avecur_021 - aveavecur021)*(avecur_021 - aveavecur021);
  }
  sdT021_valveopen = sqrt (sdT021_valveopen/counts10);
  sdT021_irrad = sqrt (sdT021_irrad/counts10);
  sdcur021 = sqrt (sdcur021/counts10);
  //cout << aveT021_valveopen << "    " << sdT021_valveopen << endl;
  //cout << aveavecur021 << " " << sdcur021 << endl;

  // FOR TCN17004A
  for (ULong64_t j = 0 ; j < event11 ; j++){
    outputTree004A -> GetEvent(j);
    irradTimeArray11[j] = cycleStartTimes11 - irradStartTimes11;
    // for 150 irrad time
    if (irradTimeArray11[j] >= 149. && irradTimeArray11[j]< 151. ){
      UCNIntegralArray11_150[j] = UCNIntegral11;
      UCNIntegralErrArray11_150[j] = UCNIntegralErr11; 
      HistIntegralArray11_150[j] = HistIntegral11;
      HistIntegralErrArray11_150[j] = sqrt(HistIntegral11);
      delayTimeArray11_150[j] = delayTime11;
      //      cout << delayTime11<< " " << delayTimeArray11_150[j] << endl;
      counts11_150++;
    }
    // for 10s irradiation time
    if (irradTimeArray11[j]>9.  && irradTimeArray11[j]< 11.  ){
      UCNIntegralArray11_10[j] = UCNIntegral11;
      UCNIntegralErrArray11_10[j] = UCNIntegralErr11; 
      HistIntegralArray11_10[j] = HistIntegral11;
      HistIntegralErrArray11_10[j] = sqrt(HistIntegral11);
      delayTimeArray11_10[j] = delayTime11;
      counts11_10++;
    }

    // for 20s irradiation time
    if (irradTimeArray11[j]>19.  && irradTimeArray11[j]< 21. ){
      UCNIntegralArray11_20[j] = UCNIntegral11;
      UCNIntegralErrArray11_20[j] = UCNIntegralErr11; 
      HistIntegralArray11_20[j] = HistIntegral11;
      HistIntegralErrArray11_20[j] = sqrt(HistIntegral11);
      delayTimeArray11_20[j] = delayTime11;
      counts11_20++;
    }
    // for 30s irradiation time
    if (irradTimeArray11[j]>29.  && irradTimeArray11[j]< 31. ){
      UCNIntegralArray11_30[j] = UCNIntegral11;
      UCNIntegralErrArray11_30[j] = UCNIntegralErr11; 
      HistIntegralArray11_30[j] = HistIntegral11;
      HistIntegralErrArray11_30[j] = sqrt(HistIntegral11);
      delayTimeArray11_30[j] = delayTime11;
      counts11_30++;
    }
    // for 40s irradiation time
    if (irradTimeArray11[j]>39.  && irradTimeArray11[j]< 41.){
      UCNIntegralArray11_40[j] = UCNIntegral11;
      UCNIntegralErrArray11_40[j] = UCNIntegralErr11; 
      HistIntegralArray11_40[j] = HistIntegral11;
      HistIntegralErrArray11_40[j] = sqrt(HistIntegral11);
      delayTimeArray11_40[j] = delayTime11;
      counts11_40++;
    }
    // for 50s irradiation time
    if (irradTimeArray11[j]>49.  && irradTimeArray11[j]< 51. ){
      UCNIntegralArray11_50[j] = UCNIntegral11;
      UCNIntegralErrArray11_50[j] = UCNIntegralErr11; 
      HistIntegralArray11_50[j] = HistIntegral11;
      HistIntegralErrArray11_50[j] = sqrt(HistIntegral11);
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
      HistIntegralErrArray11_80[j] = sqrt(HistIntegral11);
      delayTimeArray11_80[j] = delayTime11;
      counts11_80++;
    }
    // for 100s irradiation time
    if (irradTimeArray11[j]>99.  && irradTimeArray11[j]< 101. ){
      UCNIntegralArray11_100[j] = UCNIntegral11;
      UCNIntegralErrArray11_100[j] = UCNIntegralErr11; 
      HistIntegralArray11_100[j] = HistIntegral11;
      HistIntegralErrArray11_100[j] = sqrt(HistIntegral11);
      delayTimeArray11_100[j] = delayTime11;
      counts11_100++;
    }
    // for 120s irradiation time
    if (irradTimeArray11[j]>119.  && irradTimeArray11[j]< 121. ){
      UCNIntegralArray11_120[j] = UCNIntegral11;
      UCNIntegralErrArray11_120[j] = UCNIntegralErr11; 
      HistIntegralArray11_120[j] = HistIntegral11;
      HistIntegralErrArray11_120[j] = sqrt(HistIntegral11);
      delayTimeArray11_120[j] = delayTime11;
      counts11_120++;
    }

    UCNIntegralArray11[j] = UCNIntegral11;
    UCNIntegralErrArray11[j] = UCNIntegralErr11;
    delayTimeArray11[j] = delayTime11;
    HistIntegralArray11[j] = HistIntegral11;
    curArray004A[j] = avecur_004A;
    counts11++;
  }

  // FOR TCN17004B
  for (ULong64_t j = 0 ; j < event12 ; j++){
    outputTree004B -> GetEvent(j);
    UCNIntegralArray12[j] = UCNIntegral12;
    UCNIntegralErrArray12[j] = UCNIntegralErr12;
    delayTimeArray12[j] = delayTime12;
    HistIntegralArray12[j] = HistIntegral12;
      HistIntegralErrArray12[j] = sqrt(HistIntegral12);
    irradTimeArray12[j] = cycleStartTimes12 - irradStartTimes12;
    aveT004B_valveopen+=avets12ValveOpen_004B;
    aveT004B_irrad+=avets12Irrad_004B;
    curArray004B[j] = avecur_004B;
    aveavecur004B +=avecur_004B;
    tempArrayIrrad_004B[j] = avets12Irrad_004B;
    integCur004b[j] = avecur_004B*irradTimeArray12[j];
    counts12++;
  }
  aveT004B_valveopen = aveT004B_valveopen/counts12;
  aveT004B_irrad = aveT004B_irrad/counts12;
  aveavecur004B = aveavecur004B/counts12;

  for (ULong64_t j = 0 ; j < event12; j++){
    outputTree004B -> GetEvent(j);
    sdT004B_valveopen += (avets12ValveOpen_004B - aveT004B_valveopen)* (avets12ValveOpen_004B - aveT004B_valveopen);
    sdT004B_irrad += (avets12Irrad_004B - aveT004B_irrad)* (avets12Irrad_004B - aveT004B_irrad);
    sdcur004B += (avecur_004B - aveavecur004B)*(avecur_004B - aveavecur004B);
  }
  sdT004B_valveopen = sqrt (sdT004B_valveopen/counts12);
  sdT004B_irrad = sqrt (sdT004B_irrad/counts12);
  sdcur004B = sqrt ( sdcur004B/counts12);
  //cout << aveT004B_valveopen << "    " << sdT004B_valveopen << endl;
  //cout << aveavecur004B << " " << sdcur004B << endl;

  // FOR TCN17009
  for (ULong64_t j = 0 ; j < event13 ; j++){
    outputTree009 -> GetEvent(j);
    irradTimeArray13[j] = cycleStartTimes13 - irradStartTimes13;

    // for 10s irradiation time
    if (irradTimeArray13[j] > 9. && irradTimeArray13[j]< 11.  ){
      UCNIntegralArray13_10[counts13_10] = UCNIntegral13;
      UCNIntegralErrArray13_10[counts13_10] = UCNIntegralErr13; 
      HistIntegralArray13_10[counts13_10] = HistIntegral13;
      HistIntegralErrArray13_10[j] = sqrt(HistIntegral13);
      delayTimeArray13_10[counts13_10] = delayTime13;
      aveT009_10_valveopen+= avets12ValveOpen_009;
      aveT009_10_irrad+= avets12Irrad_009;
      curArray009_10[counts13_10] = avecur_009;
      aveavecur009_10+=avecur_009;
      tempArrayIrrad_009_10[counts13_10] = avets12Irrad_009;
      
      if (avecur_009 > 4.5 && avecur_009 < 5.5){
	UCNIntegralArray13_10_5muA[counts13_10_5muA] = UCNIntegral13;
	UCNIntegralErrArray13_10_5muA[counts13_10_5muA] = UCNIntegralErr13; 
	HistIntegralArray13_10_5muA[counts13_10_5muA] = HistIntegral13;
	HistIntegralErrArray13_10_5muA[counts13_10_5muA] = sqrt(HistIntegral13);
	delayTimeArray13_10_5muA[counts13_10_5muA] = delayTime13;
	curArray009_10_5muA[counts13_10_5muA] = avecur_009;
	tempArrayIrrad_009_10_5muA[counts13_10_5muA] = avets12Irrad_009;
	counts13_10_5muA++;
      }

      if (avecur_009 > 9.5 && avecur_009 < 10.5){
	if (delayTime13 > 100 &&  UCNIntegral13 > 30000)
	  continue;
	UCNIntegralArray13_10_10muA[counts13_10_10muA] = UCNIntegral13;
	UCNIntegralErrArray13_10_10muA[counts13_10_10muA] = UCNIntegralErr13; 
	HistIntegralArray13_10_10muA[counts13_10_10muA] = HistIntegral13;
	HistIntegralErrArray13_10_10muA[counts13_10_10muA] = sqrt(HistIntegral13);
	delayTimeArray13_10_10muA[counts13_10_10muA] = delayTime13;
	curArray009_10_10muA[counts13_10_10muA] = avecur_009;
	tempArrayIrrad_009_10_10muA[counts13_10_10muA] = avets12Irrad_009;
	counts13_10_10muA++;
      }
      counts13_10++;
    }
     // for 30s irradiation time
    if (irradTimeArray13[j] > 29.  && irradTimeArray13[j]< 31){
      UCNIntegralArray13_30[counts13_30] = UCNIntegral13;
      UCNIntegralErrArray13_30[counts13_30] = UCNIntegralErr13; 
      HistIntegralArray13_30[counts13_30] = HistIntegral13;
      HistIntegralErrArray13_30[j] = sqrt(HistIntegral13);
      delayTimeArray13_30[counts13_30] = delayTime13;
      //     cout <<  delayTimeArray13_30[counts13_30] <<endl;
      aveT009_30_valveopen+= avets12ValveOpen_009;
      aveT009_30_irrad+= avets12Irrad_009;
      curArray009_30[counts13_30] = avecur_009;
      aveavecur009_30+=avecur_009;
      //cout << "30s " << avecur_009 << endl;
      tempArrayIrrad_009_30[counts13_30] = avets12Irrad_009;
      counts13_30++;
    }
    // for 60s irradiation time
    if (irradTimeArray13[j] > 59. && irradTimeArray13[j] < 61. ){
      UCNIntegralArray13_60[ counts13_60] = UCNIntegral13;
      UCNIntegralErrArray13_60[ counts13_60] = UCNIntegralErr13; 
      HistIntegralArray13_60[ counts13_60] = HistIntegral13;
      HistIntegralErrArray13_60[j] = sqrt(HistIntegral13);
      delayTimeArray13_60[ counts13_60] = delayTime13;
      //cout << UCNIntegralArray13_60[j] << " " <<UCNIntegralErrArray13_60[j] << " " << delayTimeArray13_60[j] << " " << counts13_60 << " " << HistIntegralArray13_60[j] <<endl;
      curArray009_60[counts13_60] = avecur_009;
      aveT009_60_valveopen+= avets12ValveOpen_009;
      aveT009_60_irrad+= avets12Irrad_009;
      aveavecur009_60+=avecur_009;
      tempArrayIrrad_009_60[counts13_60] = avets12Irrad_009;
      counts13_60++;
    }
     UCNIntegralArray13[j] = UCNIntegral13;
     UCNIntegralErrArray13[j] = UCNIntegralErr13;
     delayTimeArray13[j] = delayTime13;
     HistIntegralArray13[j] = HistIntegral13;
    integCur009[j] = avecur_009*irradTimeArray13[j];
    counts13++;
  }

  aveT009_10_valveopen = aveT009_10_valveopen/counts13_10;
  aveT009_30_valveopen = aveT009_30_valveopen/counts13_30;
  aveT009_60_valveopen = aveT009_60_valveopen/counts13_60;

  aveavecur009_10 = aveavecur009_10/counts13_10;
  aveavecur009_30 = aveavecur009_30/counts13_30;
  aveavecur009_60 = aveavecur009_60/counts13_60;

  aveT009_10_irrad = aveT009_10_irrad/counts13_10;
  aveT009_30_irrad = aveT009_30_irrad/counts13_30;
  aveT009_60_irrad = aveT009_60_irrad/counts13_60;

  for (ULong64_t j = 0 ; j < event13 ; j++){
    outputTree009 -> GetEvent(j);
    // for 10s irradiation time
    if (irradTimeArray13[j] > 9. && irradTimeArray13[j]< 11.  ){
      sdT009_10_valveopen += (avets12ValveOpen_009 - aveT009_10_valveopen)* (avets12ValveOpen_009 - aveT009_10_valveopen);
      sdT009_10_irrad += (avets12Irrad_009 - aveT009_10_irrad)* (avets12Irrad_009 - aveT009_10_irrad);
      sdcur009_10 += (avecur_009 - aveavecur009_10)*(avecur_009 - aveavecur009_10);
    }

     // for 30s irradiation time
    if (irradTimeArray13[j] > 29.  && irradTimeArray13[j]< 31){
      sdT009_30_valveopen += (avets12ValveOpen_009 - aveT009_30_valveopen)* (avets12ValveOpen_009 - aveT009_30_valveopen);
      sdT009_30_irrad += (avets12Irrad_009 - aveT009_30_irrad)* (avets12Irrad_009 - aveT009_30_irrad);
      sdcur009_30 += (avecur_009 - aveavecur009_30)*(avecur_009 - aveavecur009_30);
    }
    
    // for 60s irradiation time
    if (irradTimeArray13[j] > 59. && irradTimeArray13[j] < 61. ){
      sdT009_60_valveopen += (avets12ValveOpen_009 - aveT009_60_valveopen)* (avets12ValveOpen_009 - aveT009_60_valveopen);
      sdT009_60_irrad += (avets12Irrad_009 - aveT009_60_irrad)* (avets12Irrad_009 - aveT009_60_irrad);
      sdcur009_60 += (avecur_009 - aveavecur009_60)*(avecur_009 - aveavecur009_60);
    }

  }

  sdT009_10_valveopen = sqrt (sdT009_10_valveopen/counts13_10);
  sdT009_30_valveopen = sqrt (sdT009_30_valveopen/counts13_30);
  sdT009_60_valveopen = sqrt (sdT009_60_valveopen/counts13_60);

  sdcur009_10 = sqrt ( sdcur009_10 / counts13_10);
  sdcur009_30 = sqrt ( sdcur009_10 / counts13_30);
  sdcur009_60 = sqrt ( sdcur009_10 / counts13_60);


  sdT009_10_irrad = sqrt (sdT009_10_irrad/counts13_10);
  sdT009_30_irrad = sqrt (sdT009_30_irrad/counts13_30);
  sdT009_60_irrad = sqrt (sdT009_60_irrad/counts13_60);
  //cout << aveT009_10_valveopen << "    " << sdT009_10_valveopen << endl;
  //cout << aveT009_30_valveopen << "    " << sdT009_30_valveopen << endl;
  //cout << aveT009_60_valveopen << "    " << sdT009_60_valveopen << endl;
  //cout << aveavecur009_10 << " " << sdcur009_10 << endl;
  //cout << aveavecur009_30 << " " << sdcur009_30 << endl;
  //cout << aveavecur009_60 << " " << sdcur009_60 << endl;


  // FOR TCN17009A
  for (ULong64_t j = 0 ; j < event14 ; j++){
    outputTree009A -> GetEvent(j);
    irradTimeArray14[j] = cycleStartTimes14 - irradStartTimes14;
    cout << irradTimeArray14[j] << " " << avecur_009A << endl;
    // for 10s irradiation time
    if (irradTimeArray14[j] > 9. && irradTimeArray14[j]<11.  ){
      UCNIntegralArray14_10[ counts14_10] = UCNIntegral14;
      UCNIntegralErrArray14_10[ counts14_10] = UCNIntegralErr14; 
      HistIntegralArray14_10[ counts14_10] = HistIntegral14;
      HistIntegralErrArray14_10[j] = sqrt(HistIntegral14);
      delayTimeArray14_10[ counts14_10] = delayTime14;
      curArray009A_10[counts14_10] = avecur_009A;
      //cout << irradTimeArray14[j] << " " <<curArray009A_10[counts14_10] << endl;
      aveT009A_10_valveopen+= avets12ValveOpen_009A;
      aveT009A_10_irrad+= avets12Irrad_009A;
      aveavecur009A_10+=avecur_009A;
      tempArrayIrrad_009A_10[counts14_10] = avets12Irrad_009A;

      if (avecur_009A > 2.0 && avecur_009A < 5.5){
	UCNIntegralArray14_10_low[counts14_10_low] = UCNIntegral14;
	UCNIntegralErrArray14_10_low[counts14_10_low] = UCNIntegralErr14; 
	HistIntegralArray14_10_low[counts14_10_low] = HistIntegral14;
	HistIntegralErrArray14_10_low[counts14_10_low] = sqrt(HistIntegral14);
	delayTimeArray14_10_low[counts14_10_low] = delayTime14;
	curArray009A_10_low[counts14_10_low] = avecur_009A;
	tempArrayIrrad_009A_10_low[counts14_10_low] = avets12Irrad_009A;
	//cout<< UCNIntegral14 << endl;
	counts14_10_low++;
      }

      if (avecur_009A > 7.5 && avecur_009A < 15){
	if (UCNIntegral14 <1000)
	  continue;
	UCNIntegralArray14_10_high[counts14_10_high] = UCNIntegral14;
	UCNIntegralErrArray14_10_high[counts14_10_high] = UCNIntegralErr14; 
	HistIntegralArray14_10_high[counts14_10_high] = HistIntegral14;
	HistIntegralErrArray14_10_high[counts14_10_high] = sqrt(HistIntegral14);
	delayTimeArray14_10_high[counts14_10_high] = delayTime14;
	curArray009A_10_high[counts14_10_high] = avecur_009A;
	tempArrayIrrad_009A_10_high[counts14_10_high] = avets12Irrad_009A;
	counts14_10_high++;
      }

      counts14_10++;
    }
    // for 30s irradiation time
    if (irradTimeArray14[j]>  29. && irradTimeArray14[j] < 31. ){
      UCNIntegralArray14_30[ counts14_30] = UCNIntegral14;
      UCNIntegralErrArray14_30[ counts14_30] = UCNIntegralErr14; 
      HistIntegralArray14_30[ counts14_30] = HistIntegral14;
      HistIntegralErrArray14_30[j] = sqrt(HistIntegral14);
      delayTimeArray14_30[ counts14_30] = delayTime14;
      curArray009A_30[counts14_30] = avecur_009A;
      aveT009A_30_valveopen+= avets12ValveOpen_009A;
      aveT009A_30_irrad+= avets12Irrad_009A;
      aveavecur009A_30+=avecur_009A;
      tempArrayIrrad_009A_30[counts14_30] = avets12Irrad_009A;

      if (avecur_009A > 2.5 && avecur_009A < 3.5){
	UCNIntegralArray14_30_3muA[counts14_30_3muA] = UCNIntegral14;
	UCNIntegralErrArray14_30_3muA[counts14_30_3muA] = UCNIntegralErr14; 
	HistIntegralArray14_30_3muA[counts14_30_3muA] = HistIntegral14;
	HistIntegralErrArray14_30_3muA[counts14_30_3muA] = sqrt(HistIntegral14);
	delayTimeArray14_30_3muA[counts14_30_3muA] = delayTime14;
	curArray009A_30_3muA[counts14_30_3muA] = avecur_009A;
	tempArrayIrrad_009A_30_3muA[counts14_30_3muA] = avets12Irrad_009A;
	counts14_30_3muA++;
      }

      if (avecur_009A > 8.5 && avecur_009A < 9.5){
	UCNIntegralArray14_30_9muA[counts14_30_9muA] = UCNIntegral14;
	UCNIntegralErrArray14_30_9muA[counts14_30_9muA] = UCNIntegralErr14; 
	HistIntegralArray14_30_9muA[counts14_30_9muA] = HistIntegral14;
	HistIntegralErrArray14_30_9muA[counts14_30_9muA] = sqrt(HistIntegral14);
	delayTimeArray14_30_9muA[counts14_30_9muA] = delayTime14;
	curArray009A_30_9muA[counts14_30_9muA] = avecur_009A;
	tempArrayIrrad_009A_30_9muA[counts14_30_9muA] = avets12Irrad_009A;
	counts14_30_9muA++;
      }

      if (avecur_009A > 10.5 && avecur_009A < 12.5){
	UCNIntegralArray14_30_12muA[counts14_30_12muA] = UCNIntegral14;
	UCNIntegralErrArray14_30_12muA[counts14_30_12muA] = UCNIntegralErr14; 
	HistIntegralArray14_30_12muA[counts14_30_12muA] = HistIntegral14;
	HistIntegralErrArray14_30_12muA[counts14_30_12muA] = sqrt(HistIntegral14);
	delayTimeArray14_30_12muA[counts14_30_12muA] = delayTime14;
	curArray009A_30_12muA[counts14_30_12muA] = avecur_009A;
	tempArrayIrrad_009A_30_12muA[counts14_30_12muA] = avets12Irrad_009A;
	counts14_30_12muA++;
      }
      counts14_30++;
    }
    
    // for 60s irradiation time
    if (irradTimeArray14[j] > 59. && irradTimeArray14[j] < 61. ){
      UCNIntegralArray14_60[counts14_60] = UCNIntegral14;
      UCNIntegralErrArray14_60[counts14_60] = UCNIntegralErr14; 
      HistIntegralArray14_60[counts14_60] = HistIntegral14;
      HistIntegralErrArray14_60[counts14_60] = sqrt(HistIntegral14);
      delayTimeArray14_60[counts14_60] = delayTime14;
      aveT009A_60_valveopen+= avets12ValveOpen_009A;
      aveT009A_60_irrad+= avets12Irrad_009A;
      aveavecur009A_60+=avecur_009A;
      curArray009A_60[counts14_60] = avecur_009A;
      tempArrayIrrad_009A_60[counts14_60] = avets12Irrad_009A;

      if (avecur_009A > 0 && avecur_009A < 1.5){
	UCNIntegralArray14_60_1muA[counts14_60_1muA] = UCNIntegral14;
	UCNIntegralErrArray14_60_1muA[counts14_60_1muA] = UCNIntegralErr14; 
	HistIntegralArray14_60_1muA[counts14_60_1muA] = HistIntegral14;
	HistIntegralErrArray14_60_1muA[counts14_60_1muA] = sqrt(HistIntegral14);
	delayTimeArray14_60_1muA[counts14_60_1muA] = delayTime14;
	curArray009A_60_1muA[counts14_60_1muA] = avecur_009A;
	tempArrayIrrad_009A_60_1muA[counts14_60_1muA] = avets12Irrad_009A;
	counts14_60_1muA++;
      }

      if (avecur_009A > 2.5 && avecur_009A < 3.5){
	UCNIntegralArray14_60_3muA[counts14_60_3muA] = UCNIntegral14;
	UCNIntegralErrArray14_60_3muA[counts14_60_3muA] = UCNIntegralErr14; 
	HistIntegralArray14_60_3muA[counts14_60_3muA] = HistIntegral14;
	HistIntegralErrArray14_60_3muA[counts14_60_3muA] = sqrt(HistIntegral14);
	delayTimeArray14_60_3muA[counts14_60_3muA] = delayTime14;
	curArray009A_60_3muA[counts14_60_3muA] = avecur_009A;
	tempArrayIrrad_009A_60_3muA[counts14_60_3muA] = avets12Irrad_009A;
	counts14_60_3muA++;
      }
      if (avecur_009A > 7.5 && avecur_009A < 8.5){
	UCNIntegralArray14_60_8muA[counts14_60_8muA] = UCNIntegral14;
	UCNIntegralErrArray14_60_8muA[counts14_60_8muA] = UCNIntegralErr14; 
	HistIntegralArray14_60_8muA[counts14_60_8muA] = HistIntegral14;
	HistIntegralErrArray14_60_8muA[counts14_60_8muA] = sqrt(HistIntegral14);
	delayTimeArray14_60_8muA[counts14_60_8muA] = delayTime14;
	curArray009A_60_8muA[counts14_60_8muA] = avecur_009A;
	tempArrayIrrad_009A_60_8muA[counts14_60_8muA] = avets12Irrad_009A;
	counts14_60_8muA++;
      }

      counts14_60++;
    }
    // for 120s irradiation time
    //cout << "********************"<<endl;
    //cout << "120s" << endl;
    if (irradTimeArray14[j] >  119. && irradTimeArray14[j] <121.){
      UCNIntegralArray14_120[ counts14_120] = UCNIntegral14;
      UCNIntegralErrArray14_120[ counts14_120] = UCNIntegralErr14; 
      HistIntegralArray14_120[ counts14_120] = HistIntegral14;
      HistIntegralErrArray14_120[j] = sqrt(HistIntegral14);
      delayTimeArray14_120[ counts14_120] = delayTime14;
      //cout << UCNIntegralArray14_120[j] << " " << delayTimeArray14_120[j]<<endl;
      aveT009A_120_valveopen+= avets12ValveOpen_009A;
      aveT009A_120_irrad+= avets12Irrad_009A;
      aveavecur009A_120+=avecur_009A;

      curArray009A_120[counts14_120] = avecur_009A;
      tempArrayIrrad_009A_120[counts14_120] = avets12Irrad_009A;
      integCur009a[j] = avecur_009A*irradTimeArray14[j];
      counts14_120++;
    }    
    UCNIntegralArray14[j] = UCNIntegral14;
    UCNIntegralErrArray14[j] = UCNIntegralErr14;
    delayTimeArray14[j] = delayTime14;
    HistIntegralArray14[j] = HistIntegral14;
    counts14++;
  }

  aveT009A_10_valveopen = aveT009A_10_valveopen/counts14_10;
  aveT009A_30_valveopen = aveT009A_30_valveopen/counts14_30;
  aveT009A_60_valveopen = aveT009A_60_valveopen/counts14_60;
  aveT009A_120_valveopen = aveT009A_120_valveopen/counts14_120;

  aveT009A_10_irrad = aveT009A_10_irrad/counts14_10;
  aveT009A_30_irrad = aveT009A_30_irrad/counts14_30;
  aveT009A_60_irrad = aveT009A_60_irrad/counts14_60;
  aveT009A_120_irrad = aveT009A_120_irrad/counts14_120;

  aveavecur009A_10 = aveavecur009A_10/counts14_10;
  aveavecur009A_30 = aveavecur009A_30/counts14_30;
  aveavecur009A_60 = aveavecur009A_60/counts14_60;
  aveavecur009A_120 = aveavecur009A_120/counts14_120;

  for (ULong64_t j = 0 ; j < event14 ; j++){
    outputTree009A -> GetEvent(j);
    // for 10s irradiation time
    if (irradTimeArray14[j] > 9. && irradTimeArray14[j]< 11.  ){
      sdT009A_10_valveopen += (avets12ValveOpen_009A - aveT009A_10_valveopen)* (avets12ValveOpen_009A - aveT009A_10_valveopen);
      sdT009A_10_irrad += (avets12Irrad_009A - aveT009A_10_irrad)* (avets12Irrad_009A - aveT009A_10_irrad);
      sdcur009A_10 += (avecur_009A - aveavecur009A_10)*(avecur_009A - aveavecur009A_10);
    }

     // for 30s irradiation time
    if (irradTimeArray14[j] > 29.  && irradTimeArray14[j]< 31){
      sdT009A_30_valveopen += (avets12ValveOpen_009A - aveT009A_30_valveopen)* (avets12ValveOpen_009A - aveT009A_30_valveopen);      
      sdT009A_30_irrad += (avets12Irrad_009A - aveT009A_30_irrad)* (avets12Irrad_009A - aveT009A_30_irrad);
      sdcur009A_30 += (avecur_009A - aveavecur009A_30)*(avecur_009A - aveavecur009A_30);
    }
    
    // for 60s irradiation time
    if (irradTimeArray14[j] > 59. && irradTimeArray14[j] < 61. ){
      sdT009A_60_valveopen += (avets12ValveOpen_009A - aveT009A_60_valveopen)* (avets12ValveOpen_009A - aveT009A_60_valveopen);
      sdT009A_60_irrad += (avets12Irrad_009A - aveT009A_60_irrad)* (avets12Irrad_009A - aveT009A_60_irrad);
      sdcur009A_60 += (avecur_009A - aveavecur009A_60)*(avecur_009A - aveavecur009A_60);
    }
    // for 120s irradiation time
    if (irradTimeArray14[j] >  119. && irradTimeArray14[j] <121.){
      sdT009A_120_valveopen += (avets12ValveOpen_009A - aveT009A_120_valveopen)* (avets12ValveOpen_009A - aveT009A_120_valveopen);
      sdT009A_120_irrad += (avets12Irrad_009A - aveT009A_120_irrad)* (avets12Irrad_009A - aveT009A_120_irrad);
      sdcur009A_120 += (avecur_009A - aveavecur009A_120)*(avecur_009A - aveavecur009A_120);
    }
  }
  sdT009A_10_valveopen = sqrt (sdT009A_10_valveopen/counts14_10);
  sdT009A_30_valveopen = sqrt (sdT009A_30_valveopen/counts14_30);
  sdT009A_60_valveopen = sqrt (sdT009A_60_valveopen/counts14_60);
  sdT009A_120_valveopen = sqrt (sdT009A_120_valveopen/counts14_120);

  sdT009A_10_irrad = sqrt (sdT009A_10_irrad/counts14_10);
  sdT009A_30_irrad = sqrt (sdT009A_30_irrad/counts14_30);
  sdT009A_60_irrad = sqrt (sdT009A_60_irrad/counts14_60);
  sdT009A_120_irrad = sqrt (sdT009A_120_irrad/counts14_120);

  sdcur009A_10 = sqrt ( sdcur009A_10 / counts14_10);
  sdcur009A_30 = sqrt ( sdcur009A_30 / counts14_30);
  sdcur009A_60 = sqrt ( sdcur009A_60 / counts14_60);
  sdcur009A_120 = sqrt ( sdcur009A_120 / counts14_120);

  //cout << aveT009A_10_valveopen << "    " << sdT009A_10_valveopen << endl;
  //cout << aveT009A_30_valveopen << "    " << sdT009A_30_valveopen << endl;
  //cout << aveT009A_60_valveopen << "    " << sdT009A_60_valveopen << endl;
  //cout << aveT009A_120_valveopen << "    " << sdT009A_120_valveopen << endl;
  //cout << aveavecur009A_10 << " " << sdcur009A_10 << endl;
  //cout << aveavecur009A_30 << " " << sdcur009A_30 << endl;
  //cout << aveavecur009A_60 << " " << sdcur009A_60 << endl;
  //cout << aveavecur009A_120 << " " << sdcur009A_120 << endl;

  // FOR TCN17014
  for (ULong64_t j = 0 ; j < event15 ; j++){
    outputTree014 -> GetEvent(j);
    UCNIntegralArray15[j] = UCNIntegral15;
    UCNIntegralErrArray15[j] = UCNIntegralErr15;
    delayTimeArray15[j] = delayTime15;
    HistIntegralArray15[j] = HistIntegral15;
    HistIntegralErrArray15[j] = sqrt(HistIntegral15);
    irradTimeArray15[j] = cycleStartTimes15 - irradStartTimes15;
    aveT014_valveopen+=avets12ValveOpen_014;
    aveT014_irrad+=avets12Irrad_014;
    //cout << aveT014_valveopen << endl;
    curArray014[j] = avecur_014;
    aveavecur014+= avecur_014;
    tempArrayIrrad_014[j] = avets12Irrad_014;
    integCur014[j] = avecur_014*irradTimeArray15[j];
    counts15++;
  }
  aveT014_valveopen = aveT014_valveopen/counts15;
  aveavecur014 = aveavecur014/counts15;

  for (ULong64_t j = 0 ; j < event15; j++){
    outputTree014 -> GetEvent(j);
    sdT014_valveopen += (avets12ValveOpen_014 - aveT014_valveopen)* (avets12ValveOpen_014 - aveT014_valveopen);
    sdT014_irrad += (avets12Irrad_014 - aveT014_irrad)* (avets12Irrad_014 - aveT014_irrad);
    sdcur014 += (avecur_014 - aveavecur014)*(avecur_014 - aveavecur014);
  }
  sdT014_valveopen = sqrt (sdT014_valveopen/counts15);
  sdT014_irrad = sqrt (sdT014_irrad/counts15);
  sdcur014 = sqrt ( sdcur014/counts15);
  //cout << aveT014_valveopen << "    " << sdT014_valveopen << endl;
  //cout << aveavecur014 << " " << sdcur014 << endl;

  // FOR TCN17029
  for (ULong64_t j = 0 ; j < event16 ; j++){
    outputTree029 -> GetEvent(j);
    UCNIntegralArray16[j] = UCNIntegral16;
    UCNIntegralErrArray16[j] = UCNIntegralErr16;
    delayTimeArray16[j] = delayTime16;
    HistIntegralArray16[j] = HistIntegral16;
    HistIntegralErrArray16[j] = sqrt(HistIntegral16);
    irradTimeArray16[j] = cycleStartTimes16 - irradStartTimes16;
    aveT029_valveopen+=avets12ValveOpen_029;
    aveT029_irrad+=avets12Irrad_029;
    curArray029[j] = avecur_029;
    aveavecur029 += avecur_029;
    tempArrayIrrad_029[j] = avets12Irrad_029;
    integCur029[j] = avecur_029*irradTimeArray16[j];
    counts16++;
  }
  aveT029_valveopen = aveT029_valveopen/counts16;
  aveT029_irrad = aveT029_irrad/counts16;
  aveavecur029 = aveavecur029/counts16;

  for (ULong64_t j = 0 ; j < event16; j++){
    outputTree029 -> GetEvent(j);
    sdT029_valveopen += (avets12ValveOpen_029 - aveT029_valveopen)* (avets12ValveOpen_029 - aveT029_valveopen);
    sdT029_irrad += (avets12Irrad_029 - aveT029_irrad)* (avets12Irrad_029 - aveT029_irrad);
    sdcur029 += (avecur_029 - aveavecur029)*(avecur_029 - aveavecur029);
  }
  sdT029_valveopen = sqrt (sdT029_valveopen/counts16);
  sdT029_irrad = sqrt (sdT029_irrad/counts16);
  sdcur029 = sqrt ( sdcur029/counts16);
  //cout << aveT029_valveopen << "    " << sdT029_valveopen << endl;
  //cout << aveavecur029 << " " << sdcur029 << endl;

  // FOR TCN17006A
  for (ULong64_t j = 0 ; j < event17 ; j++){
    outputTree006A -> GetEvent(j);
    UCNIntegralArray17[j] = UCNIntegral17;
    UCNIntegralErrArray17[j] = UCNIntegralErr17;
    delayTimeArray17[j] = delayTime17;
    HistIntegralArray17[j] = HistIntegral17;
    HistIntegralErrArray17[j] = sqrt(HistIntegral17);
    irradTimeArray17[j] = cycleStartTimes17 - irradStartTimes17;
    aveT006A_valveopen+=avets12ValveOpen_006A;
    aveT006A_irrad+=avets12Irrad_006A;
    curArray006A[j] = avecur_006A;
    aveavecur006A+= avecur_006A;
    tempArrayIrrad_006A[j] = avets12Irrad_006A;
    integCur006a[j] = avecur_006A*irradTimeArray17[j];
    counts17++;
  }
   aveT006A_valveopen = aveT006A_valveopen/counts17;
   aveT006A_irrad = aveT006A_irrad/counts17;
   aveavecur006A = aveavecur006A / counts17;

  for (ULong64_t j = 0 ; j < event17; j++){
    outputTree006A -> GetEvent(j);
    sdT006A_valveopen += (avets12ValveOpen_006A - aveT006A_valveopen)* (avets12ValveOpen_006A - aveT006A_valveopen);
    sdT006A_irrad += (avets12Irrad_006A - aveT006A_irrad)* (avets12Irrad_006A - aveT006A_irrad);
    sdcur006A += (avecur_006A - aveavecur006A)*(avecur_006A - aveavecur006A);
  }
  sdT006A_valveopen = sqrt (sdT006A_valveopen/counts17);
  sdT006A_irrad = sqrt (sdT006A_irrad/counts17);
  sdcur006A = sqrt ( sdcur006A/counts17);
  //cout << aveT006A_valveopen << "    " << sdT006A_valveopen << endl;
  //cout << aveavecur006A << " " << sdcur006A << endl;

  
  // ONE EXPONENTIAL FIT
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 120);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(20000,30);
  fit1exp -> SetParLimits(0, 10000, 190000);
  fit1exp -> SetParLimits(1, 10, 45);
  

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
  TGraphErrors *gr11 = new TGraphErrors(counts1, delayTimeArray1, HistIntegralArray1, 0 , HistIntegralErrArray1);
  gr11 -> SetMarkerStyle(7);
  gr11 -> SetMarkerColor(2);
  gr11 -> GetXaxis()-> SetRangeUser(0, 120);
  //gr11 -> GetYaxis()-> SetRangeUser(1000, 60000);
  
  gr1 -> Draw("ap");
  gr11 -> Draw("p");

  TCanvas *c1_cur = new TCanvas("c1_cur" , "c1_cur" , 900, 500);
  c1_cur -> SetLogy();
  TGraphErrors *gr1_cur = new TGraphErrors(counts1, curArray003, UCNIntegralArray1, 0, UCNIntegralErrArray1);
  gr1_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr1_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr1_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1_cur -> SetMarkerStyle(7);

  TGraphErrors *gr11_cur = new TGraphErrors (counts1 , curArray003, HistIntegralArray1, 0 , HistIntegralErrArray1);
  gr11_cur -> SetMarkerStyle(7);
  gr11_cur -> SetMarkerColor(2);

  gr1_cur -> Draw("ap");
  gr11_cur -> Draw("p");


  TCanvas *c1_temp = new TCanvas ("c1_temp" , "c1_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c1_temp -> Divide(1,2);

  c1_temp -> cd(1);
  TGraphErrors *gr1_temp = new TGraphErrors (counts1, tempArrayIrrad_003, UCNIntegralArray1, 0, UCNIntegralErrArray1);
  gr1_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr1_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr1_temp -> SetMarkerStyle(7);
  gr1_temp -> Draw("Ap");

  c1_temp -> cd(2);
  TGraphErrors *gr1_tempcur = new TGraphErrors (counts1, tempArrayIrrad_003, curArray003, 0, 0);
  gr1_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr1_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr1_tempcur -> SetMarkerStyle(7);
  gr1_tempcur -> Draw("Ap");


  // INTEGRATED BEAM CURRENT VS ISOPURE TEMPERATURE
  TCanvas *c1_totcurtemp = new TCanvas ("c1_totcurtemp" , "c1_totcurtemp" , 900, 500);
  
  TGraphErrors *gr1_totcurtemp = new TGraphErrors(counts1, tempArrayIrrad_003, integCur003, 0 , 0);
  gr1_totcurtemp -> SetTitle("Integrated Beam Current vs Average Isopure Temperature");
  gr1_totcurtemp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1_totcurtemp -> GetYaxis()-> SetTitle("Integrated Beam Current (#muA s)");
  gr1_totcurtemp -> SetMarkerStyle(7);
  gr1_totcurtemp -> Draw("Ap");

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
  TGraphErrors *gr22 = new TGraphErrors(counts2, delayTimeArray2, HistIntegralArray2, 0 , HistIntegralErrArray2);
  gr22 -> SetMarkerStyle(2);
  gr22 -> SetMarkerColor(2);
  
  gr2 -> Draw("AP");
  gr22 -> Draw("P");
  
  TCanvas *c2_cur = new TCanvas("c2_cur" , "c2_cur" , 900, 500);
  c2_cur -> SetLogy();
  TGraphErrors *gr2_cur = new TGraphErrors(counts2, curArray013, UCNIntegralArray2, 0, UCNIntegralErrArray2);
  gr2_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr2_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr2_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr2_cur -> SetMarkerStyle(7);

  TGraphErrors *gr22_cur = new TGraphErrors (counts2 , curArray013, HistIntegralArray2,0 , HistIntegralErrArray2);
  gr22_cur -> SetMarkerStyle(7);
  gr22_cur -> SetMarkerColor(2);

  gr2_cur -> Draw("AP");
  gr22_cur -> Draw("P");


  TCanvas *c2_temp = new TCanvas ("c2_temp" , "c2_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c2_temp -> Divide(1,2);

  c2_temp -> cd(1);
  TGraphErrors *gr2_temp = new TGraphErrors (counts2, tempArrayIrrad_013, UCNIntegralArray2, 0, UCNIntegralErrArray2);
  gr2_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr2_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2_temp -> SetMarkerStyle(7);
  gr2_temp -> Draw("Ap");

  c2_temp -> cd(2);
  TGraphErrors *gr2_tempcur = new TGraphErrors (counts2, tempArrayIrrad_013, curArray013, 0, 0);
  gr2_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr2_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr2_tempcur -> SetMarkerStyle(7);
  gr2_tempcur -> Draw("Ap");


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
  TGraphErrors *gr33 = new TGraphErrors (counts3, delayTimeArray3, HistIntegralArray3, 0, HistIntegralErrArray3);
  gr33 -> SetMarkerStyle(3);
  gr33 -> SetMarkerColor(2);
  
  gr3 -> Draw("ap");
  gr33 -> Draw("p");

  TCanvas *c3_cur = new TCanvas("c3_cur" , "c3_cur" , 900, 500);
  c3_cur -> SetLogy();
  TGraphErrors *gr3_cur = new TGraphErrors(counts3, curArray023, UCNIntegralArray3, 0, UCNIntegralErrArray3);
  gr3_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr3_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr3_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr3_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr3_cur -> SetMarkerStyle(7);

  TGraphErrors *gr33_cur = new TGraphErrors (counts3 , curArray023, HistIntegralArray3, 0, HistIntegralErrArray3);
  gr33_cur -> SetMarkerStyle(7);
  gr33_cur -> SetMarkerColor(2);

  gr3_cur -> Draw("ap");
  gr33_cur -> Draw("p");

  TCanvas *c3_temp = new TCanvas ("c3_temp" , "c3_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c3_temp -> Divide(1,2);

  c3_temp -> cd(1);
  TGraphErrors *gr3_temp = new TGraphErrors (counts3, tempArrayIrrad_023, UCNIntegralArray3, 0, UCNIntegralErrArray3);
  gr3_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr3_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr3_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr3_temp -> SetMarkerStyle(7);
  gr3_temp -> Draw("Ap");

  c3_temp -> cd(2);
  TGraphErrors *gr3_tempcur = new TGraphErrors (counts3, tempArrayIrrad_023, curArray023, 0, 0);
  gr3_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr3_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr3_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr3_tempcur -> SetMarkerStyle(7);
  gr3_tempcur -> Draw("Ap");

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
  TGraphErrors *gr44 = new TGraphErrors(counts4, delayTimeArray4, HistIntegralArray4, 0 , HistIntegralErrArray4);
  gr44 -> SetMarkerStyle(4);
  gr44 -> SetMarkerColor(2);
  
  gr4 -> Draw("ap");
  gr44 -> Draw("p");
  
  TCanvas *c4_cur = new TCanvas("c4_cur" , "c4_cur" , 900, 500);
  c4_cur -> SetLogy();
  TGraphErrors *gr4_cur = new TGraphErrors(counts4, curArray025, UCNIntegralArray4, 0, UCNIntegralErrArray4);
  gr4_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr4_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr4_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr4_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr4_cur -> SetMarkerStyle(7);

  TGraphErrors *gr44_cur = new TGraphErrors (counts4 , curArray025, HistIntegralArray4, 0 , HistIntegralErrArray4);
  gr44_cur -> SetMarkerStyle(7);
  gr44_cur -> SetMarkerColor(2);

  gr4_cur -> Draw("ap");
  gr44_cur -> Draw("p");

  TCanvas *c4_temp = new TCanvas ("c4_temp" , "c4_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c4_temp -> Divide(1,2);

  c4_temp -> cd(1);
  TGraphErrors *gr4_temp = new TGraphErrors (counts4, tempArrayIrrad_025, UCNIntegralArray4, 0, UCNIntegralErrArray4);
  gr4_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr4_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr4_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr4_temp -> SetMarkerStyle(7);
  gr4_temp -> Draw("Ap");

  c4_temp -> cd(2);
  TGraphErrors *gr4_tempcur = new TGraphErrors (counts4, tempArrayIrrad_025, curArray025, 0, 0);
  gr4_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr4_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr4_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr4_tempcur -> SetMarkerStyle(7);
  gr4_tempcur -> Draw("Ap");


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
  TGraphErrors *gr55 = new TGraphErrors (counts5, delayTimeArray5, HistIntegralArray5 , 0 , HistIntegralErrArray5);
  gr55 -> SetMarkerStyle(5);
  gr55 -> SetMarkerColor(2);
  
  gr5 -> Draw("ap");
  gr55 -> Draw("p");
  
  TCanvas *c5_cur = new TCanvas("c5_cur" , "c5_cur" , 900, 500);
  c5_cur -> SetLogy();
  TGraphErrors *gr5_cur = new TGraphErrors(counts5, curArray026, UCNIntegralArray5, 0, UCNIntegralErrArray5);
  gr5_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr5_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr5_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr5_cur -> SetMarkerStyle(7);

  TGraphErrors *gr55_cur = new TGraphErrors (counts5 , curArray026, HistIntegralArray5, 0 ,HistIntegralErrArray5);
  gr55_cur -> SetMarkerStyle(7);
  gr55_cur -> SetMarkerColor(2);

  gr5_cur -> Draw("ap");
  gr55_cur -> Draw("p");

  TCanvas *c5_temp = new TCanvas ("c5_temp" , "c5_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c5_temp -> Divide(1,2);

  c5_temp -> cd(1);
  TGraphErrors *gr5_temp = new TGraphErrors (counts5, tempArrayIrrad_026, UCNIntegralArray5, 0, UCNIntegralErrArray5);
  gr5_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr5_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5_temp -> SetMarkerStyle(7);
  gr5_temp -> Draw("Ap");

  c5_temp -> cd(2);
  TGraphErrors *gr5_tempcur = new TGraphErrors (counts5, tempArrayIrrad_026, curArray026, 0, 0);
  gr5_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr5_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr5_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr5_tempcur -> SetMarkerStyle(7);
  gr5_tempcur -> Draw("Ap");


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
  TGraphErrors *gr66 = new TGraphErrors (counts6, delayTimeArray6, HistIntegralArray6, 0 , HistIntegralErrArray6);
  gr66 -> SetMarkerStyle(26);
  gr66 -> SetMarkerColor(2);
  
  
  gr6 -> Draw("ap");
  gr66 -> Draw("p");

  TCanvas *c6_cur = new TCanvas("c6_cur" , "c6_cur" , 900, 500);
  c6_cur -> SetLogy();
  TGraphErrors *gr6_cur = new TGraphErrors(counts6, curArray029A, UCNIntegralArray6, 0, UCNIntegralErrArray6);
  gr6_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr6_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr6_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr6_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr6_cur -> SetMarkerStyle(7);

  TGraphErrors *gr66_cur = new TGraphErrors (counts6 , curArray029A, HistIntegralArray6, 0 , HistIntegralErrArray6);
  gr66_cur -> SetMarkerStyle(7);
  gr66_cur -> SetMarkerColor(2);

  gr6_cur -> Draw("ap");
  gr66_cur -> Draw("p");

  TCanvas *c6_temp = new TCanvas ("c6_temp" , "c6_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c6_temp -> Divide(1,2);

  c6_temp -> cd(1);
  TGraphErrors *gr6_temp = new TGraphErrors (counts6, tempArrayIrrad_029A, UCNIntegralArray6, 0, UCNIntegralErrArray6);
  gr6_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr6_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr6_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr6_temp -> SetMarkerStyle(7);
  gr6_temp -> Draw("Ap");

  c6_temp -> cd(2);
  TGraphErrors *gr6_tempcur = new TGraphErrors (counts6, tempArrayIrrad_029A, curArray029A, 0, 0);
  gr6_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr6_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr6_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr6_tempcur -> SetMarkerStyle(7);
  gr6_tempcur -> Draw("Ap");


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
  TGraphErrors *gr77 = new TGraphErrors (counts7, delayTimeArray7, HistIntegralArray7, 0, HistIntegralErrArray7); 
  gr77 -> SetMarkerStyle(25);
  gr77 -> SetMarkerColor(2);
  
  gr7 -> Draw("ap");
  gr77 -> Draw("p");

  TCanvas *c7_cur = new TCanvas("c7_cur" , "c7_cur" , 900, 500);
  c7_cur -> SetLogy();
  TGraphErrors *gr7_cur = new TGraphErrors(counts7, curArray031, UCNIntegralArray7, 0, UCNIntegralErrArray7);
  gr7_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr7_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr7_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr7_cur -> SetMarkerStyle(7);

  TGraphErrors *gr77_cur = new TGraphErrors (counts7 , curArray031, HistIntegralArray7, 0 , HistIntegralErrArray7);
  gr77_cur -> SetMarkerStyle(7);
  gr77_cur -> SetMarkerColor(2);

  gr7_cur -> Draw("ap");
  gr77_cur -> Draw("p");

  TCanvas *c7_temp = new TCanvas ("c7_temp" , "c7_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c7_temp -> Divide(1,2);

  c7_temp -> cd(1);
  TGraphErrors *gr7_temp = new TGraphErrors (counts7, tempArrayIrrad_031, UCNIntegralArray7, 0, UCNIntegralErrArray7);
  gr7_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr7_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7_temp -> SetMarkerStyle(7);
  gr7_temp -> Draw("Ap");

  c7_temp -> cd(2);
  TGraphErrors *gr7_tempcur = new TGraphErrors (counts7, tempArrayIrrad_031, curArray031, 0, 0);
  gr7_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr7_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr7_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr7_tempcur -> SetMarkerStyle(7);
  gr7_tempcur -> Draw("Ap");

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
  TGraphErrors *gr88 = new TGraphErrors (counts8, delayTimeArray8, HistIntegralArray8, 0 , HistIntegralErrArray8);
  gr88 -> SetMarkerStyle(33);
  gr88 -> SetMarkerColor(2);

  gr8 -> Draw("ap");
  gr88 -> Draw("p");
  
  TCanvas *c8_cur = new TCanvas("c8_cur" , "c8_cur" , 900, 500);
  c8_cur -> SetLogy();
  TGraphErrors *gr8_cur = new TGraphErrors(counts8, curArray002, UCNIntegralArray8, 0, UCNIntegralErrArray8);
  gr8_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr8_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr8_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr8_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr8_cur -> SetMarkerStyle(7);

  TGraphErrors *gr88_cur = new TGraphErrors (counts8 , curArray002, HistIntegralArray8, 0 , HistIntegralErrArray8);
  gr88_cur -> SetMarkerStyle(7);
  gr88_cur -> SetMarkerColor(2);

  gr8_cur -> Draw("ap");
  gr88_cur -> Draw("p");

  TCanvas *c8_temp = new TCanvas ("c8_temp" , "c8_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c8_temp -> Divide(1,2);

  c8_temp -> cd(1);
  TGraphErrors *gr8_temp = new TGraphErrors (counts8, tempArrayIrrad_002, UCNIntegralArray8, 0, UCNIntegralErrArray8);
  gr8_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr8_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr8_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr8_temp -> SetMarkerStyle(7);
  gr8_temp -> Draw("Ap");

  c8_temp -> cd(2);
  TGraphErrors *gr8_tempcur = new TGraphErrors (counts8, tempArrayIrrad_002, curArray002, 0, 0);
  gr8_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr8_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr8_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr8_tempcur -> SetMarkerStyle(7);
  gr8_tempcur -> Draw("Ap");





 TCanvas *c002 = new TCanvas ("c002" , "c002" , 900, 500);
  c002 -> Divide(2,2);

  c002-> cd(1);
  TGraphErrors *gr002_counts = new TGraphErrors(counts12, delayTimeArray12, UCNIntegralArray12, 0 , UCNIntegralErrArray12);
  gr002_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr002_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr002_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr002_counts -> GetYaxis()-> SetRangeUser(1, 80000);
  gr002_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr002_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr002_counts -> SetMarkerStyle(2);  

  gr002_counts -> Fit(fit1exp,"+R");
  storagefit002 =fit1exp->GetParameter(1);
  storageErrfit002 =fit1exp->GetParError(1);
  gr002_counts -> Draw("ap");

  c002 -> cd(2); 
  gr8_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr8_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr8_temp -> Draw("ap");

  c002 -> cd(3);
  gr8_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr8_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr8_cur -> Draw("ap");


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
  TGraphErrors *gr99 = new TGraphErrors (counts9, delayTimeArray9, HistIntegralArray9, 0 , HistIntegralErrArray9);
  gr99 -> SetMarkerStyle(21);
  gr99 -> SetMarkerColor(2);
  
   gr9 -> Draw("ap");
   gr99 -> Draw("p");
  
   TCanvas *c9_cur = new TCanvas("c9_cur" , "c9_cur" , 900, 500);
  c9_cur -> SetLogy();
  TGraphErrors *gr9_cur = new TGraphErrors(counts9, curArray006, UCNIntegralArray9, 0, UCNIntegralErrArray9);
  gr9_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr9_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr9_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr9_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr9_cur -> SetMarkerStyle(7);

  TGraphErrors *gr99_cur = new TGraphErrors (counts9 , curArray006, HistIntegralArray9, 0 , HistIntegralErrArray9);
  gr99_cur -> SetMarkerStyle(7);
  gr99_cur -> SetMarkerColor(2);

  gr9_cur -> Draw("ap");
  gr99_cur -> Draw("p");

  TCanvas *c9_temp = new TCanvas ("c9_temp" , "c9_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c9_temp -> Divide(1,2);

  c9_temp -> cd(1);
  TGraphErrors *gr9_temp = new TGraphErrors (counts9, tempArrayIrrad_006, UCNIntegralArray9, 0, UCNIntegralErrArray9);
  gr9_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr9_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr9_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr9_temp -> SetMarkerStyle(7);
  gr9_temp -> Draw("Ap");

  c9_temp -> cd(2);
  TGraphErrors *gr9_tempcur = new TGraphErrors (counts9, tempArrayIrrad_006, curArray006, 0, 0);
  gr9_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr9_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr9_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr9_tempcur -> SetMarkerStyle(7);
  gr9_tempcur -> Draw("Ap");


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
  TGraphErrors *gr1010 = new TGraphErrors (counts10, delayTimeArray10, HistIntegralArray10, 0 , HistIntegralErrArray10);
  gr1010 -> SetMarkerStyle(22);
  gr1010 -> SetMarkerColor(2);

  gr10 -> Draw("ap");
  gr1010 -> Draw("p");
  
  TCanvas *c10_cur = new TCanvas("c10_cur" , "c10_cur" , 900, 500);
  c10_cur -> SetLogy();
  TGraphErrors *gr10_cur = new TGraphErrors(counts10, curArray021, UCNIntegralArray10, 0, UCNIntegralErrArray10);
  gr10_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr10_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr10_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr10_cur -> SetMarkerStyle(7);

  TGraphErrors *gr1010_cur = new TGraphErrors (counts10 , curArray021, HistIntegralArray10, 0 , HistIntegralErrArray10);
  gr1010_cur -> SetMarkerStyle(7);
  gr1010_cur -> SetMarkerColor(2);

  gr10_cur -> Draw("ap");
  gr1010_cur -> Draw("p");

  TCanvas *c10_temp = new TCanvas ("c10_temp" , "c10_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c10_temp -> Divide(1,2);

  c10_temp -> cd(1);
  TGraphErrors *gr10_temp = new TGraphErrors (counts10, tempArrayIrrad_021, UCNIntegralArray10, 0, UCNIntegralErrArray10);
  gr10_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr10_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10_temp -> SetMarkerStyle(7);
  gr10_temp -> Draw("Ap");

  c10_temp -> cd(2);
  TGraphErrors *gr10_tempcur = new TGraphErrors (counts10, tempArrayIrrad_021, curArray021, 0, 0);
  gr10_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr10_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr10_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr10_tempcur -> SetMarkerStyle(7);
  gr10_tempcur -> Draw("Ap");


  // ******************************************************************
  // TCN17004A
  // ******************************************************************
  /*  TCanvas *c004A = new TCanvas("c004A" , "c004A" , 900, 500);
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
  
  */

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
  TGraphErrors *gr004B_hist = new TGraphErrors (counts12, delayTimeArray12, HistIntegralArray12, 0 , HistIntegralErrArray12);
  gr004B_hist -> SetMarkerStyle(2);
  gr004B_hist -> SetMarkerColor(2);
  
  gr004B -> Draw("ap");
  gr004B_hist -> Draw("p");

  TCanvas *c004B_cur = new TCanvas("c004B_cur" , "c004B_cur" , 900, 500);
  c004B_cur -> SetLogy();
  TGraphErrors *gr004B_cur = new TGraphErrors(counts12, curArray004B, UCNIntegralArray12, 0, UCNIntegralErrArray12);
  gr004B_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr004B_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr004B_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004B_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr004B_cur -> SetMarkerStyle(7);

  TGraphErrors *gr004B_hist_cur = new TGraphErrors (counts12 , curArray004B, HistIntegralArray12 , 0 , HistIntegralErrArray12);
  gr004B_hist_cur -> SetMarkerStyle(7);
  gr004B_hist_cur -> SetMarkerColor(2);

  gr004B_cur -> Draw("ap");
  gr004B_hist_cur -> Draw("p");

  TCanvas *c004B_temp = new TCanvas ("c004B_temp" , "c004B_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c004B_temp -> Divide(1,2);

  c004B_temp -> cd(1);
  TGraphErrors *gr004B_temp = new TGraphErrors (counts12, tempArrayIrrad_004B, UCNIntegralArray12, 0, UCNIntegralErrArray12);
  gr004B_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr004B_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr004B_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004B_temp -> SetMarkerStyle(7);
  gr004B_temp -> Draw("Ap");

  c004B_temp -> cd(2);
  TGraphErrors *gr004B_tempcur = new TGraphErrors (counts12, tempArrayIrrad_004B, curArray004B, 0, 0);
  gr004B_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr004B_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr004B_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr004B_tempcur -> SetMarkerStyle(7);
  gr004B_tempcur -> Draw("Ap");  



 TCanvas *c004B = new TCanvas ("c004B" , "c004B" , 900, 500);
  c004B -> Divide(2,2);

  c004B-> cd(1);
  TGraphErrors *gr004B_counts = new TGraphErrors(counts12, delayTimeArray12, UCNIntegralArray12, 0 , UCNIntegralErrArray12);
  gr004B_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr004B_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr004B_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004B_counts -> GetYaxis()-> SetRangeUser(1, 80000);
  gr004B_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr004B_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr004B_counts -> SetMarkerStyle(2);  

  gr004B_counts -> Fit(fit1exp,"+R");
  storagefit004B =fit1exp->GetParameter(1);
  storageErrfit004B =fit1exp->GetParError(1);
  gr004B_counts -> Draw("ap");

  c004B -> cd(2); 
  gr004B_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr004B_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr004B_temp -> Draw("ap");

  c004B -> cd(3);
  gr004B_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr004B_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr004B_cur -> Draw("ap");


  // ******************************************************************
  // TCN17009
  // ******************************************************************
  
  TCanvas *c009 = new TCanvas("c009", "c009",900,500);
  // c009_10 -> SetLogy();
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
  TGraphErrors *gr009_10_hist = new TGraphErrors (counts13_10, delayTimeArray13_10, HistIntegralArray13_10, 0 , HistIntegralErrArray10);
  gr009_10_hist -> SetMarkerStyle(2);
  gr009_10_hist -> SetMarkerColor(2);
  
  gr009_10 -> Draw("ap");
  gr009_10_hist -> Draw("p");
  
  TText *text1 = new TText();
  text1 -> SetNDC();
  text1 -> SetTextFont(1);
  text1 -> SetTextColor(2);
  text1 -> SetTextSize(0.03);
  text1 -> SetTextAlign(22);
  text1 -> SetTextAngle(0);
  text1 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");

  c009-> cd(2);
  TGraphErrors *gr009_30 = new TGraphErrors(counts13_30, delayTimeArray13_30, UCNIntegralArray13_30, 0 , UCNIntegralErrArray13_30);

  
  gr009_30 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_30 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  // gr009_30 -> GetYaxis()-> SetRangeUser(1, 300000);
  //gr009_30 -> GetXaxis()-> SetLimits(0,120);
  gr009_30 -> SetMarkerStyle(2); 
  
  //gr009_30 -> Fit(fit1exp,"+R");
  //storagefit009_30_1expfit =fit1exp->GetParameter(1);
  //storageErrfit009_30_1expfit =fit1exp->GetParError(1);
  
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009_30_hist = new TGraphErrors (counts13_30, delayTimeArray13_30, HistIntegralArray13_30 , 0 , HistIntegralErrArray13_30);
  gr009_30_hist -> SetMarkerStyle(2);
  gr009_30_hist -> SetMarkerColor(2);


  gr009_30 -> Draw("ap");
  gr009_30_hist -> Draw("p");


  TText *text6 = new TText();
  text6-> SetNDC();
  text6 -> SetTextFont(1);
  text6 -> SetTextColor(2);
  text6 -> SetTextSize(0.03);
  text6 -> SetTextAlign(22);
  text6 -> SetTextAngle(0);
  text6 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009 -> cd(3);
  TGraphErrors *gr009_60 = new TGraphErrors(counts13_60, delayTimeArray13_60, UCNIntegralArray13_60, 0 , UCNIntegralErrArray13_60);
  gr009_60 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_60 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_60 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_60 -> GetXaxis() -> SetLimits(0,170);
  gr009_60 -> SetMarkerStyle(2); 
  
  gr009_60 -> Fit(fit1exp,"+R");
  storagefit009_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_60_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009_60_hist = new TGraphErrors (counts13_60, delayTimeArray13_60, HistIntegralArray13_60 , 0 , HistIntegralErrArray13_60);
  gr009_60_hist -> SetMarkerStyle(2);
  gr009_60_hist -> SetMarkerColor(2);

  gr009_60 -> Draw("ap");
  gr009_60_hist -> Draw("p");
  
  TText *text7 = new TText();
  text7 -> SetNDC();
  text7 -> SetTextFont(1);
  text7 -> SetTextColor(2);
  text7 -> SetTextSize(0.03);
  text7 -> SetTextAlign(22);
  text7 -> SetTextAngle(0);
  text7 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");
  
  
  // NOW FOR THE DEPENDENCY TO THE BEAM CURRENT
  
  TCanvas *c009_cur = new TCanvas("c009_cur", "c009_cur",900,500);
  // c009_10 -> SetLogy();
  c009_cur -> Divide(3,1);
  
  c009_cur -> cd(1);
  TGraphErrors *gr009_cur_10 = new TGraphErrors(counts13_10, curArray009_10, UCNIntegralArray13_10, 0 , UCNIntegralErrArray13_10);
  gr009_cur_10 -> SetTitle("UCN Counts vs Beam Current");
  gr009_cur_10 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009_cur_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_cur_10 -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_cur_10 -> SetMarkerStyle(2); 
  
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009_cur_10_hist = new TGraphErrors (counts13_10, curArray009_10, HistIntegralArray13_10, 0 , HistIntegralErrArray13_10);
  gr009_cur_10_hist -> SetMarkerStyle(2);
  gr009_cur_10_hist -> SetMarkerColor(2);
  
  gr009_cur_10 -> Draw("ap");
  gr009_cur_10_hist -> Draw("p");
  text1 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");
  
  c009_cur-> cd(2);
  TGraphErrors *gr009_cur_30 = new TGraphErrors(counts13_30, curArray009_30, UCNIntegralArray13_30, 0 , UCNIntegralErrArray13_30);
  
  
  gr009_cur_30 -> SetTitle("UCN Counts vs Beam Current");
  gr009_cur_30 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009_cur_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  // gr009_30 -> GetYaxis()-> SetRangeUser(1, 300000);
  //gr009_30 -> GetXaxis()-> SetLimits(0,120);
  gr009_cur_30 -> SetMarkerStyle(2); 
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009_cur_30_hist = new TGraphErrors (counts13_30, curArray009_30, HistIntegralArray13_30 , 0 , HistIntegralErrArray13_30);
  gr009_cur_30_hist -> SetMarkerStyle(2);
  gr009_cur_30_hist -> SetMarkerColor(2);
  
  
  gr009_cur_30 -> Draw("ap");
  gr009_cur_30_hist -> Draw("p");
  text6 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");
  
  c009_cur -> cd(3);
  TGraphErrors *gr009_cur_60 = new TGraphErrors(counts13_60, curArray009_60, UCNIntegralArray13_60, 0 , UCNIntegralErrArray13_60);
  gr009_cur_60-> SetTitle("UCN Counts vs Beam Current");
  gr009_cur_60 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009_cur_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_cur_60 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_cur_60 -> SetMarkerStyle(2); 
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009_cur_60_hist = new TGraphErrors (counts13_60,curArray009_60, HistIntegralArray13_60 , 0 , HistIntegralErrArray13_60);
  gr009_cur_60_hist -> SetMarkerStyle(2);
  gr009_cur_60_hist -> SetMarkerColor(2);
  
  gr009_cur_60 -> Draw("ap");
  gr009_cur_60_hist -> Draw("p");
  text7 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");
  

  // ISOPURE TEMPERATURE AND UCN COUNT
  TCanvas *c009_temp = new TCanvas ("c009_temp" , "c009_temp" , 900, 500);
  c009_temp -> Divide(3,1);

  c009_temp -> cd(1);
  TGraphErrors *gr009_temp_10 = new TGraphErrors (counts13_10, tempArrayIrrad_009_10, UCNIntegralArray13_10, 0, UCNIntegralErrArray13_10);
  gr009_temp_10 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_temp_10 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_temp_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_temp_10 -> SetMarkerStyle(7);
  gr009_temp_10 -> Draw("Ap");
 text1 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");

  c009_temp -> cd(2);
  TGraphErrors *gr009_temp_30 = new TGraphErrors (counts13_30, tempArrayIrrad_009_30, UCNIntegralArray13_30, 0, UCNIntegralErrArray13_30);
  gr009_temp_30 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_temp_30 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_temp_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_temp_30 -> SetMarkerStyle(7);
  gr009_temp_30 -> Draw("Ap");
  text6 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009_temp -> cd(3);
  TGraphErrors *gr009_temp_60 = new TGraphErrors (counts13_60, tempArrayIrrad_009_60, UCNIntegralArray13_60, 0, UCNIntegralErrArray13_60);
  gr009_temp_60 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_temp_60 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_temp_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_temp_60 -> SetMarkerStyle(7);
  gr009_temp_60 -> Draw("Ap");
  text7 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");

  //AVERAGE ISOPURE TEMPERATURE AND BEAM CURRENT
  TCanvas *c009_tempcur = new TCanvas ("c009_tempcur" , "c009_tempcur" , 900, 500);
  c009_tempcur -> Divide(3,1);

  c009_tempcur -> cd(1);
  TGraphErrors *gr009_tempcur_10 = new TGraphErrors (counts13_10, tempArrayIrrad_009_10,curArray009_10, 0, 0);
  gr009_tempcur_10 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009_tempcur_10 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_tempcur_10 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009_tempcur_10 -> SetMarkerStyle(7);
  gr009_tempcur_10 -> Draw("Ap");
  text1 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");

  c009_tempcur -> cd(2);
  TGraphErrors *gr009_tempcur_30 = new TGraphErrors (counts13_30, tempArrayIrrad_009_30,curArray009_30, 0, 0);
  gr009_tempcur_30 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009_tempcur_30 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_tempcur_30 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009_tempcur_30 -> SetMarkerStyle(7);
  gr009_tempcur_30 -> Draw("Ap");
  text6 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009_tempcur -> cd(3);
  TGraphErrors *gr009_tempcur_60 = new TGraphErrors (counts13_60, tempArrayIrrad_009_60, curArray009_10, 0, 0);
  gr009_tempcur_60 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009_tempcur_60 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_tempcur_60 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009_tempcur_60 -> SetMarkerStyle(7);
  gr009_tempcur_60 -> Draw("Ap");
  text7 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");
  


  // FOR DIFFERENT BEAM CURRENTS
  
  TCanvas *c009_10_5muA = new TCanvas ("c009_10_5muA" , "c009_10_5muA" , 900, 500);
  c009_10_5muA -> Divide(2,2);

  c009_10_5muA -> cd(1);
  TGraphErrors *gr009_10_5muA_counts = new TGraphErrors(counts13_10_5muA, delayTimeArray13_10_5muA, UCNIntegralArray13_10_5muA, 0 , UCNIntegralErrArray13_10_5muA);
  gr009_10_5muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_10_5muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_10_5muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_5muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_counts -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_10_5muA_counts -> SetMarkerStyle(2);  

  gr009_10_5muA_counts -> Fit(fit1exp,"+R");
  storagefit009_10_5muA =fit1exp->GetParameter(1);
  storageErrfit009_10_5muA =fit1exp->GetParError(1);
  gr009_10_5muA_counts -> Draw("ap");

  c009_10_5muA -> cd(2);
  TGraphErrors *gr009_10_5muA_temp = new TGraphErrors(counts13_10_5muA, tempArrayIrrad_009_10_5muA, UCNIntegralArray13_10_5muA, 0,  UCNIntegralErrArray13_10_5muA);
  gr009_10_5muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_10_5muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_10_5muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_5muA_temp -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_10_5muA_temp -> SetMarkerStyle(2);  
  gr009_10_5muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_temp -> Draw("ap");

  c009_10_5muA -> cd(3);
  TGraphErrors *gr009_10_5muA_cur = new TGraphErrors(counts13_10_5muA, curArray009_10_5muA, UCNIntegralArray13_10_5muA, 0,  UCNIntegralErrArray13_10_5muA);
  gr009_10_5muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009_10_5muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009_10_5muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_5muA_cur -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009_10_5muA_cur -> SetMarkerStyle(2);  
  gr009_10_5muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_5muA_cur -> Draw("ap");



  TCanvas *c009_10_10muA = new TCanvas ("c009_10_10muA" , "c009_10_10muA" , 900, 500);
  c009_10_10muA -> Divide(2,2);

  c009_10_10muA -> cd(1);
  TGraphErrors *gr009_10_10muA_counts = new TGraphErrors(counts13_10_10muA, delayTimeArray13_10_10muA, UCNIntegralArray13_10_10muA, 0 , UCNIntegralErrArray13_10_10muA);
  gr009_10_10muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_10_10muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_10_10muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_10muA_counts -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_10_10muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_counts -> SetMarkerStyle(2);  

  gr009_10_10muA_counts -> Fit(fit1exp,"+R");
  storagefit009_10_10muA =fit1exp->GetParameter(1);
  storageErrfit009_10_10muA =fit1exp->GetParError(1);
  gr009_10_10muA_counts -> Draw("ap");

  c009_10_10muA -> cd(2);
  TGraphErrors *gr009_10_10muA_temp = new TGraphErrors(counts13_10_10muA, tempArrayIrrad_009_10_10muA, UCNIntegralArray13_10_10muA, 0,  UCNIntegralErrArray13_10_10muA);
  gr009_10_10muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_10_10muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_10_10muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_10muA_temp -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_10_10muA_temp -> SetMarkerStyle(2);  
  gr009_10_10muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_temp -> Draw("ap");

  c009_10_10muA -> cd(3);
  TGraphErrors *gr009_10_10muA_cur = new TGraphErrors(counts13_10_10muA, curArray009_10_10muA, UCNIntegralArray13_10_10muA, 0,  UCNIntegralErrArray13_10_10muA);
  gr009_10_10muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009_10_10muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009_10_10muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_10_10muA_cur -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_10_10muA_cur -> SetMarkerStyle(2);  
  gr009_10_10muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009_10_10muA_cur -> Draw("ap");





  TCanvas *c009_30_5muA = new TCanvas ("c009_30_5muA" , "c009_30_5muA" , 900, 500);
  c009_30_5muA -> Divide(2,2);

  c009_30_5muA -> cd(1);
  TGraphErrors *gr009_30_5muA_counts = new TGraphErrors(counts13_30, delayTimeArray13_30, UCNIntegralArray13_30, 0 , UCNIntegralErrArray13_30);
  gr009_30_5muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_30_5muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_30_5muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_30_5muA_counts -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_30_5muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_counts -> SetMarkerStyle(2);  

  gr009_30_5muA_counts -> Fit(fit1exp,"+R");
  storagefit009_30_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_30_1expfit =fit1exp->GetParError(1);
  gr009_30_5muA_counts -> Draw("ap");

  c009_30_5muA -> cd(2);
  TGraphErrors *gr009_30_5muA_temp = new TGraphErrors(counts13_30, tempArrayIrrad_009_30, UCNIntegralArray13_30, 0,  UCNIntegralErrArray13_30);
  gr009_30_5muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_30_5muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_30_5muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_30_5muA_temp -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_30_5muA_temp -> SetMarkerStyle(2);  
  gr009_30_5muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_temp -> Draw("ap");

  c009_30_5muA -> cd(3);
  TGraphErrors *gr009_30_5muA_cur = new TGraphErrors(counts13_30, curArray009_30, UCNIntegralArray13_30, 0,  UCNIntegralErrArray13_30);
  gr009_30_5muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009_30_5muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009_30_5muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_30_5muA_cur -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_30_5muA_cur -> SetMarkerStyle(2);  
  gr009_30_5muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009_30_5muA_cur -> Draw("ap");


  TCanvas *c009_60_5muA = new TCanvas ("c009_60_5muA" , "c009_60_5muA" , 900, 500);
  c009_60_5muA -> Divide(2,2);

  c009_60_5muA -> cd(1);
  TGraphErrors *gr009_60_5muA_counts = new TGraphErrors(counts13_60, delayTimeArray13_60, UCNIntegralArray13_60, 0 , UCNIntegralErrArray13_60);
  gr009_60_5muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009_60_5muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009_60_5muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_60_5muA_counts -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_60_5muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_counts -> SetMarkerStyle(2);  

  gr009_60_5muA_counts -> Fit(fit1exp,"+R");
  storagefit009_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_60_1expfit =fit1exp->GetParError(1);
  gr009_60_5muA_counts -> Draw("ap");

  c009_60_5muA -> cd(2);
  TGraphErrors *gr009_60_5muA_temp = new TGraphErrors(counts13_60, tempArrayIrrad_009_60, UCNIntegralArray13_60, 0,  UCNIntegralErrArray13_60);
  gr009_60_5muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009_60_5muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009_60_5muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_60_5muA_temp -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_60_5muA_temp -> SetMarkerStyle(2);  
  gr009_60_5muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_temp -> Draw("ap");

  c009_60_5muA -> cd(3);
  TGraphErrors *gr009_60_5muA_cur = new TGraphErrors(counts13_60, curArray009_60, UCNIntegralArray13_60, 0,  UCNIntegralErrArray13_60);
  gr009_60_5muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009_60_5muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009_60_5muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009_60_5muA_cur -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009_60_5muA_cur -> SetMarkerStyle(2);  
  gr009_60_5muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009_60_5muA_cur -> Draw("ap");

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
  gr009A_10 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_10 -> SetMarkerStyle(2); 
  
  gr009A_10 -> Fit(fit1exp,"+R");
  storagefit009A_10_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_10_1expfit =fit1exp->GetParError(1);
  
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_10_hist = new TGraphErrors (counts14_10, delayTimeArray14_10, HistIntegralArray14_10, 0 , HistIntegralErrArray14_10);
  gr009A_10_hist -> SetMarkerStyle(2);
  gr009A_10_hist -> SetMarkerColor(2);
  
  gr009A_10 -> Draw("ap");
  gr009A_10_hist -> Draw("p");
  
  TText *text2 = new TText();
  text2-> SetNDC();
  text2 -> SetTextFont(1);
  text2 -> SetTextColor(2);
  text2 -> SetTextSize(0.03);
  text2 -> SetTextAlign(22);
  text2 -> SetTextAngle(0);
  text2 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");
  
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
  TGraphErrors *gr009A_30_hist = new TGraphErrors (counts14_30, delayTimeArray14_30, HistIntegralArray14_30 , 0 , HistIntegralErrArray14_30);
  gr009A_30_hist -> SetMarkerStyle(2);
  gr009A_30_hist -> SetMarkerColor(2);
  
  gr009A_30 -> Draw("ap");
  gr009A_30_hist -> Draw("p");
  

  TText *text3 = new TText();
  text3 -> SetNDC();
  text3 -> SetTextFont(1);
  text3 -> SetTextColor(2);
  text3 -> SetTextSize(0.03);
  text3 -> SetTextAlign(22);
  text3 -> SetTextAngle(0);
  text3 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009A -> cd(3);
  TGraphErrors *gr009A_60 = new TGraphErrors(counts14_60, delayTimeArray14_60, UCNIntegralArray14_60, 0 , UCNIntegralErrArray14_60);
  gr009A_60 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_60 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  // gr009A_60 -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_60 -> SetMarkerStyle(2); 
  
  gr009A_60 -> Fit(fit1exp,"+R");
  storagefit009A_60_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_60_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_60_hist = new TGraphErrors (counts14_60, delayTimeArray14_60, HistIntegralArray14_60 , 0 , HistIntegralErrArray14_60);
  gr009A_60_hist -> SetMarkerStyle(2);
  gr009A_60_hist -> SetMarkerColor(2);

  gr009A_60 -> Draw("ap");
  gr009A_60_hist -> Draw("p");

  TText *text4 = new TText();
  text4-> SetNDC();
  text4 -> SetTextFont(1);
  text4 -> SetTextColor(2);
  text4 -> SetTextSize(0.03);
  text4 -> SetTextAlign(22);
  text4 -> SetTextAngle(0);
  text4 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");

  c009A -> cd(4);
  TGraphErrors *gr009A_120 = new TGraphErrors(counts14_120, delayTimeArray14_120, UCNIntegralArray14_120, 0 , UCNIntegralErrArray14_120);
  gr009A_120 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_120 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_120 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_120 -> GetYaxis()-> SetRangeUser(1, 500000);
  gr009A_120 -> SetMarkerStyle(2); 
  
  gr009A_120 -> Fit(fit1exp,"+R");
  storagefit009A_120_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_120_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_120_hist = new TGraphErrors (counts14_120, delayTimeArray14_120, HistIntegralArray14_120 , 0 , HistIntegralErrArray14_120);
  gr009A_120_hist -> SetMarkerStyle(2);
  gr009A_120_hist -> SetMarkerColor(2);

  gr009A_120 -> Draw("ap");
  gr009A_120_hist -> Draw("p");

  TText *text5 = new TText();
  text5 -> SetNDC();
  text5 -> SetTextFont(1);
  text5 -> SetTextColor(2);
  text5 -> SetTextSize(0.03);
  text5 -> SetTextAlign(22);
  text5 -> SetTextAngle(0);
  text5 -> DrawText(0.6, 0.4, "120 s Irradiaiton Time");

  // ISOPURE TEMPERATURE AND UCN COUNT
  TCanvas *c009A_temp = new TCanvas ("c009A_temp" , "c009A_temp" , 900, 500);
  c009A_temp -> Divide(2,2);

  c009A_temp -> cd(1);
  TGraphErrors *gr009A_temp_10 = new TGraphErrors (counts14_10, tempArrayIrrad_009A_10, UCNIntegralArray14_10, 0, UCNIntegralErrArray14_10);
  gr009A_temp_10 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_temp_10 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_temp_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_temp_10 -> SetMarkerStyle(7);
  gr009A_temp_10 -> Draw("Ap");
  text2 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");

  c009A_temp -> cd(2);
  TGraphErrors *gr009A_temp_30 = new TGraphErrors (counts14_30, tempArrayIrrad_009A_30, UCNIntegralArray14_30, 0, UCNIntegralErrArray14_30);
  gr009A_temp_30 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_temp_30 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_temp_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_temp_30 -> SetMarkerStyle(7);
  gr009A_temp_30 -> Draw("Ap");
  text3 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009A_temp -> cd(3);
  TGraphErrors *gr009A_temp_60 = new TGraphErrors (counts14_60, tempArrayIrrad_009A_60, UCNIntegralArray14_60, 0, UCNIntegralErrArray14_60);
  gr009A_temp_60 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_temp_60 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_temp_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_temp_60 -> SetMarkerStyle(7);
  gr009A_temp_60 -> Draw("Ap");
  text4 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");

  c009A_temp -> cd(4);
  TGraphErrors *gr009A_temp_120 = new TGraphErrors (counts14_120, tempArrayIrrad_009A_120, UCNIntegralArray14_120, 0, UCNIntegralErrArray14_120);
  gr009A_temp_120 -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_temp_120 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_temp_120 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_temp_120 -> SetMarkerStyle(7);
  gr009A_temp_120 -> Draw("Ap");
  text5 -> DrawText(0.6, 0.4, "120 s Irradiaiton Time");

  //AVERAGE ISOPURE TEMPERATURE AND BEAM CURRENT
  TCanvas *c009A_tempcur = new TCanvas ("c009A_tempcur" , "c009A_tempcur" , 900, 500);
  c009A_tempcur -> Divide(2,2);

  c009A_tempcur -> cd(1);
  TGraphErrors *gr009A_tempcur_10 = new TGraphErrors (counts14_10, tempArrayIrrad_009A_10,curArray009A_10, 0, 0);
  gr009A_tempcur_10 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009A_tempcur_10 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_tempcur_10 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009A_tempcur_10 -> SetMarkerStyle(7);
  gr009A_tempcur_10 -> Draw("Ap");
  text2 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");

  c009A_tempcur -> cd(2);
  TGraphErrors *gr009A_tempcur_30 = new TGraphErrors (counts14_30, tempArrayIrrad_009A_30,curArray009A_30, 0, 0);
  gr009A_tempcur_30 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009A_tempcur_30 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_tempcur_30 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009A_tempcur_30 -> SetMarkerStyle(7);
  gr009A_tempcur_30 -> Draw("Ap");
  text3 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");

  c009A_tempcur -> cd(3);
  TGraphErrors *gr009A_tempcur_60 = new TGraphErrors (counts14_60, tempArrayIrrad_009A_60, curArray009A_10, 0, 0);
  gr009A_tempcur_60 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009A_tempcur_60 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_tempcur_60 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009A_tempcur_60 -> SetMarkerStyle(7);
  gr009A_tempcur_60 -> Draw("Ap");
  text4 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");

  c009A_tempcur -> cd(4);
  TGraphErrors *gr009A_tempcur_120 = new TGraphErrors (counts14_120, tempArrayIrrad_009A_120, curArray009A_120, 0, 0);
  gr009A_tempcur_120 -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr009A_tempcur_120 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_tempcur_120 -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr009A_tempcur_120 -> SetMarkerStyle(7);
  gr009A_tempcur_120 -> Draw("Ap");
  text5 -> DrawText(0.6, 0.4, "120 s Irradiaiton Time");

  // COUNTS AND CURRENT
  TCanvas *c009A_cur = new TCanvas("c009A_cur", "c009A_cur",900,500);
  // c009_10 -> SetLogy();
  c009A_cur -> Divide(2,2);
  
  c009A_cur -> cd(1);
  TGraphErrors *gr009A_cur_10 = new TGraphErrors(counts14_10, curArray009A_10, UCNIntegralArray14_10, 0 , UCNIntegralErrArray14_10);
  gr009A_cur_10 -> SetTitle("UCN Counts vs Beam Current");
  gr009A_cur_10 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009A_cur_10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_cur_10 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_cur_10 -> GetXaxis()-> SetRangeUser(0, 14);
  gr009A_cur_10 -> SetMarkerStyle(2); 
  
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_cur_10_hist = new TGraphErrors (counts14_10, curArray009A_10, HistIntegralArray14_10, 0 , HistIntegralErrArray14_10);
  gr009A_cur_10_hist -> SetMarkerStyle(2);
  gr009A_cur_10_hist -> SetMarkerColor(2);
  
  gr009A_cur_10 -> Draw("ap");
  gr009A_cur_10_hist -> Draw("p");
  text1 -> DrawText(0.6, 0.4, "10 s Irradiaiton Time");
  
  c009A_cur-> cd(2);
  TGraphErrors *gr009A_cur_30 = new TGraphErrors(counts14_30, curArray009A_30, UCNIntegralArray14_30, 0 , UCNIntegralErrArray14_30);
  
  
  gr009A_cur_30 -> SetTitle("UCN Counts vs Beam Current");
  gr009A_cur_30 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009A_cur_30 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  // gr009_30 -> GetYaxis()-> SetRangeUser(1, 300000);
  //gr009_30 -> GetXaxis()-> SetLimits(0,120);
  gr009A_cur_30 -> SetMarkerStyle(2); 
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_cur_30_hist = new TGraphErrors (counts14_30, curArray009A_30, HistIntegralArray14_30 , 0 , HistIntegralErrArray14_30);
  gr009A_cur_30_hist -> SetMarkerStyle(2);
  gr009A_cur_30_hist -> SetMarkerColor(2);
  
  
  gr009A_cur_30 -> Draw("ap");
  gr009A_cur_30_hist -> Draw("p");
  text6 -> DrawText(0.6, 0.4, "30 s Irradiaiton Time");
  
  c009A_cur -> cd(3);
  TGraphErrors *gr009A_cur_60 = new TGraphErrors(counts14_60, curArray009A_60, UCNIntegralArray14_60, 0 , UCNIntegralErrArray14_60);
  gr009A_cur_60-> SetTitle("UCN Counts vs Beam Current");
  gr009A_cur_60 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009A_cur_60 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_cur_60 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_cur_60 -> SetMarkerStyle(2); 
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_cur_60_hist = new TGraphErrors (counts14_60, curArray009A_60, HistIntegralArray14_60 , 0 , HistIntegralErrArray14_60);
  gr009A_cur_60_hist -> SetMarkerStyle(2);
  gr009A_cur_60_hist -> SetMarkerColor(2);
  
  gr009A_cur_60 -> Draw("ap");
  //gr009A_cur_60_hist -> Draw("ap");
  text7 -> DrawText(0.6, 0.4, "60 s Irradiaiton Time");

  c009A_cur -> cd(4);
  TGraphErrors *gr009A_cur_120 = new TGraphErrors(counts14_120, curArray009A_120, UCNIntegralArray14_120, 0 , UCNIntegralErrArray14_120);
  gr009A_cur_120-> SetTitle("UCN Counts vs Beam Current");
  gr009A_cur_120 -> GetXaxis()-> SetTitle("Beam Current (#muA)" );
  gr009A_cur_120 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_cur_120 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_cur_120 -> SetMarkerStyle(2); 
  
  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr009A_cur_120_hist = new TGraphErrors (counts14_120,curArray009A_120, HistIntegralArray14_120 , 0 , HistIntegralErrArray14_120);
  gr009A_cur_120_hist -> SetMarkerStyle(2);
  gr009A_cur_120_hist -> SetMarkerColor(2);
  
  gr009A_cur_120 -> Draw("ap");
  gr009A_cur_120_hist -> Draw("p");
  text7 -> DrawText(0.6, 0.4, "120 s Irradiaiton Time");
  
  

  // NOW FOR DIFFERENT BEAM CURRENTS
  TCanvas *c009A_10_low = new TCanvas ("c009A_10_low" , "c009A_10_low" , 900, 500);
  c009A_10_low -> Divide(2,2);

  c009A_10_low -> cd(1);
  TGraphErrors *gr009A_10_low_counts = new TGraphErrors(counts14_10_low, delayTimeArray14_10_low, UCNIntegralArray14_10_low, 0 , UCNIntegralErrArray14_10_low);
  gr009A_10_low_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_10_low_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_10_low_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_low_counts -> GetYaxis()-> SetRangeUser(1, 70000);
  gr009A_10_low_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_low_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_10_low_counts -> SetMarkerStyle(2);  

  gr009A_10_low_counts -> Fit(fit1exp,"+R");
  storagefit009A_10_low =fit1exp->GetParameter(1);
  storageErrfit009A_10_low =fit1exp->GetParError(1);
  gr009A_10_low_counts -> Draw("ap");

  c009A_10_low -> cd(2);
  TGraphErrors *gr009A_10_low_temp = new TGraphErrors(counts14_10_low, tempArrayIrrad_009A_10_low, UCNIntegralArray14_10_low, 0,  UCNIntegralErrArray14_10_low);
  gr009A_10_low_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_10_low_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_10_low_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_low_temp -> GetYaxis()-> SetRangeUser(1, 70000);
  gr009A_10_low_temp -> SetMarkerStyle(2);  
  gr009A_10_low_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_low_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_10_low_temp -> Draw("ap");

  c009A_10_low -> cd(3);
  TGraphErrors *gr009A_10_low_cur = new TGraphErrors(counts14_10_low, curArray009A_10_low, UCNIntegralArray14_10_low, 0,  UCNIntegralErrArray14_10_low);
  gr009A_10_low_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_10_low_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_10_low_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_low_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr009A_10_low_cur -> SetMarkerStyle(2);  
  gr009A_10_low_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_low_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_10_low_cur -> Draw("ap");


  TCanvas *c009A_10_high = new TCanvas ("c009A_10_high" , "c009A_10_high" , 900, 500);
  c009A_10_high -> Divide(2,2);

  c009A_10_high -> cd(1);
  TGraphErrors *gr009A_10_high_counts = new TGraphErrors(counts14_10_high, delayTimeArray14_10_high, UCNIntegralArray14_10_high, 0 , UCNIntegralErrArray14_10_high);
  gr009A_10_high_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_10_high_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_10_high_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_high_counts -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_10_high_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_high_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_10_high_counts -> SetMarkerStyle(2);  

  gr009A_10_high_counts -> Fit(fit1exp,"+R");
  storagefit009A_10_high =fit1exp->GetParameter(1);
  storageErrfit009A_10_high =fit1exp->GetParError(1);
  gr009A_10_high_counts -> Draw("ap");

  c009A_10_high -> cd(2);
  TGraphErrors *gr009A_10_high_temp = new TGraphErrors(counts14_10_high, tempArrayIrrad_009A_10_high, UCNIntegralArray14_10_high, 0,  UCNIntegralErrArray14_10_high);
  gr009A_10_high_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_10_high_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_10_high_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_high_temp -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_10_high_temp -> SetMarkerStyle(2);  
  gr009A_10_high_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_high_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_10_high_temp -> Draw("ap");

  c009A_10_high -> cd(3);
  TGraphErrors *gr009A_10_high_cur = new TGraphErrors(counts14_10_high, curArray009A_10_high, UCNIntegralArray14_10_high, 0,  UCNIntegralErrArray14_10_high);
  gr009A_10_high_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_10_high_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_10_high_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_10_high_cur -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_10_high_cur -> SetMarkerStyle(2); 
  gr009A_10_high_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_10_high_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_10_high_cur -> Draw("ap");


  TCanvas *c009A_30_3muA = new TCanvas ("c009A_30_3muA" , "c009A_30_3muA" , 900, 500);
  c009A_30_3muA -> Divide(2,2);

  c009A_30_3muA -> cd(1);
  TGraphErrors *gr009A_30_3muA_counts = new TGraphErrors(counts14_30_3muA, delayTimeArray14_30_3muA, UCNIntegralArray14_30_3muA, 0 , UCNIntegralErrArray14_30_3muA);
  gr009A_30_3muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_30_3muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_30_3muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_3muA_counts -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_30_3muA_counts -> SetMarkerStyle(2);  
  gr009A_30_3muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_3muA_counts -> GetYaxis() -> SetTitleSize(0.05); 

  gr009A_30_3muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_30_3muA =fit1exp->GetParameter(1);
  storageErrfit009A_30_3muA =fit1exp->GetParError(1);
  gr009A_30_3muA_counts -> Draw("ap");

  c009A_30_3muA -> cd(2);
  TGraphErrors *gr009A_30_3muA_temp = new TGraphErrors(counts14_30_3muA, tempArrayIrrad_009A_30_3muA, UCNIntegralArray14_30_3muA, 0,  UCNIntegralErrArray14_30_3muA);
  gr009A_30_3muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_30_3muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_30_3muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_3muA_temp -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_3muA_temp -> SetMarkerStyle(2);  
  gr009A_30_3muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_3muA_temp -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_3muA_temp -> Draw("ap");

  c009A_30_3muA -> cd(3);
  TGraphErrors *gr009A_30_3muA_cur = new TGraphErrors(counts14_30_3muA, curArray009A_30_3muA, UCNIntegralArray14_30_3muA, 0,  UCNIntegralErrArray14_30_3muA);
  gr009A_30_3muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_30_3muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_30_3muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_3muA_cur -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_30_3muA_cur -> SetMarkerStyle(2);  
  gr009A_30_3muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_3muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_3muA_cur -> Draw("ap");


  TCanvas *c009A_30_9muA = new TCanvas ("c009A_30_9muA" , "c009A_30_9muA" , 900, 500);
  c009A_30_9muA -> Divide(2,2);

  c009A_30_9muA -> cd(1);
  TGraphErrors *gr009A_30_9muA_counts = new TGraphErrors(counts14_30_9muA, delayTimeArray14_30_9muA, UCNIntegralArray14_30_9muA, 0 , UCNIntegralErrArray14_30_9muA);
  gr009A_30_9muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_30_9muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_30_9muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_9muA_counts -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_9muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_9muA_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_9muA_counts -> SetMarkerStyle(2);  

  gr009A_30_9muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_30_9muA =fit1exp->GetParameter(1);
  storageErrfit009A_30_9muA =fit1exp->GetParError(1);
  gr009A_30_9muA_counts -> Draw("ap");

  c009A_30_9muA -> cd(2);
  TGraphErrors *gr009A_30_9muA_temp = new TGraphErrors(counts14_30_9muA, tempArrayIrrad_009A_30_9muA, UCNIntegralArray14_30_9muA, 0,  UCNIntegralErrArray14_30_9muA);
  gr009A_30_9muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_30_9muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_30_9muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_9muA_temp -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_9muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_9muA_temp -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_9muA_temp -> SetMarkerStyle(2);  
  gr009A_30_9muA_temp -> Draw("ap");

  c009A_30_9muA -> cd(3);
  TGraphErrors *gr009A_30_9muA_cur = new TGraphErrors(counts14_30_9muA, curArray009A_30_9muA, UCNIntegralArray14_30_9muA, 0,  UCNIntegralErrArray14_30_9muA);
  gr009A_30_9muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_30_9muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_30_9muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_9muA_cur -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_9muA_cur -> SetMarkerStyle(2);  
  gr009A_30_9muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_9muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_9muA_cur -> Draw("ap");



  TCanvas *c009A_30_12muA = new TCanvas ("c009A_30_12muA" , "c009A_30_12muA" , 900, 500);
  c009A_30_12muA -> Divide(2,2);

  c009A_30_12muA -> cd(1);
  TGraphErrors *gr009A_30_12muA_counts = new TGraphErrors(counts14_30_12muA, delayTimeArray14_30_12muA, UCNIntegralArray14_30_12muA, 0 , UCNIntegralErrArray14_30_12muA);
  gr009A_30_12muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_30_12muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_30_12muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_12muA_counts -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_12muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_12muA_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_12muA_counts -> SetMarkerStyle(2);  

  gr009A_30_12muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_30_12muA =fit1exp->GetParameter(1);
  storageErrfit009A_30_12muA =fit1exp->GetParError(1);
  gr009A_30_12muA_counts -> Draw("ap");

  c009A_30_12muA -> cd(2);
  TGraphErrors *gr009A_30_12muA_temp = new TGraphErrors(counts14_30_12muA, tempArrayIrrad_009A_30_12muA, UCNIntegralArray14_30_12muA, 0,  UCNIntegralErrArray14_30_12muA);
  gr009A_30_12muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_30_12muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_30_12muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_12muA_temp -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_12muA_temp -> SetMarkerStyle(2);  
  gr009A_30_12muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_12muA_temp -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_12muA_temp -> Draw("ap");

  c009A_30_12muA -> cd(3);
  TGraphErrors *gr009A_30_12muA_cur = new TGraphErrors(counts14_30_12muA, curArray009A_30_12muA, UCNIntegralArray14_30_12muA, 0,  UCNIntegralErrArray14_30_12muA);
  gr009A_30_12muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_30_12muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_30_12muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_30_12muA_cur -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_30_12muA_cur -> SetMarkerStyle(2);  
  gr009A_30_12muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_30_12muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_30_12muA_cur -> Draw("ap");



  TCanvas *c009A_60_1muA = new TCanvas ("c009A_60_1muA" , "c009A_60_1muA" , 900, 500);
  c009A_60_1muA -> Divide(2,2);

  c009A_60_1muA -> cd(1);
  TGraphErrors *gr009A_60_1muA_counts = new TGraphErrors(counts14_60_1muA, delayTimeArray14_60_1muA, UCNIntegralArray14_60_1muA, 0 , UCNIntegralErrArray14_60_1muA);
  gr009A_60_1muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_60_1muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_60_1muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_1muA_counts -> GetYaxis()-> SetRangeUser(1, 60000);
  gr009A_60_1muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_1muA_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_1muA_counts -> SetMarkerStyle(2);  

  gr009A_60_1muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_60_1muA =fit1exp->GetParameter(1);
  storageErrfit009A_60_1muA =fit1exp->GetParError(1);
  gr009A_60_1muA_counts -> Draw("ap");

  c009A_60_1muA -> cd(2);
  TGraphErrors *gr009A_60_1muA_temp = new TGraphErrors(counts14_60_1muA, tempArrayIrrad_009A_60_1muA, UCNIntegralArray14_60_1muA, 0,  UCNIntegralErrArray14_60_1muA);
  gr009A_60_1muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_60_1muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_60_1muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_1muA_temp -> GetYaxis()-> SetRangeUser(1, 60000);
  gr009A_60_1muA_temp -> SetMarkerStyle(2);  
  gr009A_60_1muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_1muA_temp -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_1muA_temp -> Draw("ap");

  c009A_60_1muA -> cd(3);
  TGraphErrors *gr009A_60_1muA_cur = new TGraphErrors(counts14_60_1muA, curArray009A_60_1muA, UCNIntegralArray14_60_1muA, 0,  UCNIntegralErrArray14_60_1muA);
  gr009A_60_1muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_60_1muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_60_1muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_1muA_cur -> GetYaxis()-> SetRangeUser(1, 60000);
  gr009A_60_1muA_cur -> SetMarkerStyle(2);  
  gr009A_60_1muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_1muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_1muA_cur -> Draw("ap");

  TCanvas *c009A_60_3muA = new TCanvas ("c009A_60_3muA" , "c009A_60_3muA" , 900, 500);
  c009A_60_3muA -> Divide(2,2);

  c009A_60_3muA -> cd(1);
  TGraphErrors *gr009A_60_3muA_counts = new TGraphErrors(counts14_60_3muA, delayTimeArray14_60_3muA, UCNIntegralArray14_60_3muA, 0 , UCNIntegralErrArray14_60_3muA);
  gr009A_60_3muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_60_3muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_60_3muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_3muA_counts -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_60_3muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_3muA_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_3muA_counts -> SetMarkerStyle(2);  

  gr009A_60_3muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_60_3muA =fit1exp->GetParameter(1);
  storageErrfit009A_60_3muA =fit1exp->GetParError(1);
  gr009A_60_3muA_counts -> Draw("ap");

  c009A_60_3muA -> cd(2);
  TGraphErrors *gr009A_60_3muA_temp = new TGraphErrors(counts14_60_3muA, tempArrayIrrad_009A_60_3muA, UCNIntegralArray14_60_3muA, 0,  UCNIntegralErrArray14_60_3muA);
  gr009A_60_3muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_60_3muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_60_3muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_3muA_temp -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_60_3muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_3muA_temp -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_3muA_temp -> SetMarkerStyle(2);  
  gr009A_60_3muA_temp -> Draw("ap");

  c009A_60_3muA -> cd(3);
  TGraphErrors *gr009A_60_3muA_cur = new TGraphErrors(counts14_60_3muA, curArray009A_60_3muA, UCNIntegralArray14_60_3muA, 0,  UCNIntegralErrArray14_60_3muA);
  gr009A_60_3muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_60_3muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_60_3muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_3muA_cur -> GetYaxis()-> SetRangeUser(1, 100000);
  gr009A_60_3muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_3muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_3muA_cur -> SetMarkerStyle(2);  
  gr009A_60_3muA_cur -> Draw("ap");



  TCanvas *c009A_60_8muA = new TCanvas ("c009A_60_8muA" , "c009A_60_8muA" , 900, 500);
  c009A_60_8muA -> Divide(2,2);

  c009A_60_8muA -> cd(1);
  TGraphErrors *gr009A_60_8muA_counts = new TGraphErrors(counts14_60_8muA, delayTimeArray14_60_8muA, UCNIntegralArray14_60_8muA, 0 , UCNIntegralErrArray14_60_8muA);
  gr009A_60_8muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_60_8muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_60_8muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_8muA_counts -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_60_8muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_8muA_counts -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_8muA_counts -> SetMarkerStyle(2);  

  gr009A_60_8muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_60_8muA =fit1exp->GetParameter(1);
  storageErrfit009A_60_8muA =fit1exp->GetParError(1);
  gr009A_60_8muA_counts -> Draw("ap");

  c009A_60_8muA -> cd(2);
  TGraphErrors *gr009A_60_8muA_temp = new TGraphErrors(counts14_60_8muA, tempArrayIrrad_009A_60_8muA, UCNIntegralArray14_60_8muA, 0,  UCNIntegralErrArray14_60_8muA);
  gr009A_60_8muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_60_8muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_60_8muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_8muA_temp -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_60_8muA_temp -> SetMarkerStyle(2); 
  gr009A_60_8muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_8muA_temp -> GetYaxis() -> SetTitleSize(0.05);  
  gr009A_60_8muA_temp -> Draw("ap");

  c009A_60_8muA -> cd(3);
  TGraphErrors *gr009A_60_8muA_cur = new TGraphErrors(counts14_60_8muA, curArray009A_60_8muA, UCNIntegralArray14_60_8muA, 0,  UCNIntegralErrArray14_60_8muA);
  gr009A_60_8muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_60_8muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_60_8muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_60_8muA_cur -> GetYaxis()-> SetRangeUser(1, 300000);
  gr009A_60_8muA_cur -> SetMarkerStyle(2);  
  gr009A_60_8muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_60_8muA_cur -> GetYaxis() -> SetTitleSize(0.05); 
  gr009A_60_8muA_cur -> Draw("ap");



  TCanvas *c009A_120_3muA = new TCanvas ("c009A_120_3muA" , "c009A_120_3muA" , 900, 500);
  c009A_120_3muA -> Divide(2,2);

  c009A_120_3muA -> cd(1);
  TGraphErrors *gr009A_120_3muA_counts = new TGraphErrors(counts14_120, delayTimeArray14_120, UCNIntegralArray14_120, 0 , UCNIntegralErrArray14_120);
  gr009A_120_3muA_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr009A_120_3muA_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr009A_120_3muA_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_120_3muA_counts -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_120_3muA_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_counts -> SetMarkerStyle(2);  

  gr009A_120_3muA_counts -> Fit(fit1exp,"+R");
  storagefit009A_120_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_120_1expfit =fit1exp->GetParError(1);
  gr009A_120_3muA_counts -> Draw("ap");

  c009A_120_3muA -> cd(2);
  TGraphErrors *gr009A_120_3muA_temp = new TGraphErrors(counts14_120, tempArrayIrrad_009A_120, UCNIntegralArray14_120, 0,  UCNIntegralErrArray14_120);
  gr009A_120_3muA_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr009A_120_3muA_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr009A_120_3muA_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_120_3muA_temp -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_120_3muA_temp -> SetMarkerStyle(2);  
  gr009A_120_3muA_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_temp -> Draw("ap");

  c009A_120_3muA -> cd(3);
  TGraphErrors *gr009A_120_3muA_cur = new TGraphErrors(counts14_120, curArray009A_120, UCNIntegralArray14_120, 0,  UCNIntegralErrArray14_120);
  gr009A_120_3muA_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr009A_120_3muA_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr009A_120_3muA_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr009A_120_3muA_cur -> GetYaxis()-> SetRangeUser(1, 200000);
  gr009A_120_3muA_cur -> SetMarkerStyle(2);  
  gr009A_120_3muA_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr009A_120_3muA_cur -> Draw("ap");

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
  TGraphErrors *gr014_hist = new TGraphErrors (counts15, delayTimeArray15, HistIntegralArray15 , 0 , HistIntegralErrArray15);
  gr014_hist -> SetMarkerStyle(7);
  gr014_hist -> SetMarkerColor(2);
  gr014_hist -> GetXaxis()-> SetRangeUser(0, 120);


  gr014 -> Draw("ap");
  gr014_hist -> Draw("p");

  TCanvas *c014_cur = new TCanvas("c014_cur" , "c014_cur" , 900, 500);
  c014_cur -> SetLogy();
  TGraphErrors *gr014_cur = new TGraphErrors(counts15, curArray014, UCNIntegralArray15, 0, UCNIntegralErrArray15);
  gr014_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr014_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr014_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr014_cur -> GetYaxis()-> SetRangeUser(1, 30000);
  gr014_cur -> SetMarkerStyle(7);

  TGraphErrors *gr014_hist_cur = new TGraphErrors (counts15 , curArray014, HistIntegralArray15 , 0 , HistIntegralErrArray15);
  gr014_hist_cur -> SetMarkerStyle(7);
  gr014_hist_cur -> SetMarkerColor(2);

  gr014_cur -> Draw("ap");
  gr014_hist_cur -> Draw("p");

  TCanvas *c014_temp = new TCanvas ("c014_temp" , "c014_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c014_temp -> Divide(1,2);

  c014_temp -> cd(1);
  TGraphErrors *gr014_temp = new TGraphErrors (counts15, tempArrayIrrad_014, UCNIntegralArray15, 0, UCNIntegralErrArray15);
  gr014_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr014_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr014_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr014_temp -> SetMarkerStyle(7);
  gr014_temp -> Draw("Ap");

  c014_temp -> cd(2);
  TGraphErrors *gr014_tempcur = new TGraphErrors (counts15, tempArrayIrrad_014, curArray014, 0, 0);
  gr014_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr014_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr014_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr014_tempcur -> SetMarkerStyle(7);
  gr014_tempcur -> Draw("Ap");  




  /*

  TCanvas *c014 = new TCanvas ("c014" , "c014" , 900, 500);
  c014 -> Divide(2,2);

  c014-> cd(1);
  TGraphErrors *gr014_counts = new TGraphErrors(counts15, delayTimeArray15, UCNIntegralArray15, 0 , UCNIntegralErrArray15);
  gr014_counts -> SetTitle("UCN Counts vs Valve Delay Time");
  gr014_counts -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr014_counts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr014_counts -> GetYaxis()-> SetRangeUser(1, 30000);
  gr014_counts -> GetXaxis() -> SetTitleSize(0.05);
  gr014_counts -> GetYaxis() -> SetTitleSize(0.05);
  gr014_counts -> SetMarkerStyle(2);  

  gr014_counts -> Fit(fit1exp,"+R");
  storagefit014 =fit1exp->GetParameter(1);
  storageErrfit014 =fit1exp->GetParError(1);
  gr014_counts -> Draw("ap");

  c014 -> cd(2); 
  gr014_temp -> GetXaxis() -> SetTitleSize(0.05);
  gr014_temp -> GetYaxis() -> SetTitleSize(0.05);
  gr014_temp -> Draw("ap");

  c014 -> cd(3);
  gr014_cur -> GetXaxis() -> SetTitleSize(0.05);
  gr014_cur -> GetYaxis() -> SetTitleSize(0.05);
  gr014_cur -> Draw("ap");*/

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
  gr029 -> GetYaxis()-> SetRangeUser(1, 500000);
  gr029 -> SetMarkerStyle(7);

  gr029 -> Fit(fit1exp, "+R");
  fit1exp -> SetLineColor(1);
  storagefit029_1expfit =fit1exp->GetParameter(1);
  storageErrfit029_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr029_hist = new TGraphErrors (counts16, delayTimeArray16, HistIntegralArray16);
  gr029_hist -> SetMarkerStyle(7);
  gr029_hist -> SetMarkerColor(2);
  gr029_hist -> GetXaxis()-> SetRangeUser(0, 120);


  gr029 -> Draw("ap");
  gr029_hist -> Draw("p");

  TCanvas *c029_cur = new TCanvas("c029_cur" , "c029_cur" , 900, 500);
  c029_cur -> SetLogy();
  TGraphErrors *gr029_cur = new TGraphErrors(counts16, curArray029, UCNIntegralArray16, 0, UCNIntegralErrArray16);
  gr029_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr029_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr029_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr029_cur -> SetMarkerStyle(7);

  TGraphErrors *gr029_hist_cur = new TGraphErrors (counts16 , curArray029, HistIntegralArray16 , 0 , HistIntegralErrArray16);
  gr029_hist_cur -> SetMarkerStyle(7);
  gr029_hist_cur -> SetMarkerColor(2);

  gr029_cur -> Draw("ap");
  gr029_hist_cur -> Draw("p");

  TCanvas *c029_temp = new TCanvas ("c029_temp" , "c029_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c029_temp -> Divide(1,2);

  c029_temp -> cd(1);
  TGraphErrors *gr029_temp = new TGraphErrors (counts16, tempArrayIrrad_029, UCNIntegralArray16, 0, UCNIntegralErrArray16);
  gr029_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr029_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr029_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029_temp -> SetMarkerStyle(7);
  gr029_temp -> Draw("Ap");

  c029_temp -> cd(2);
  TGraphErrors *gr029_tempcur = new TGraphErrors (counts16, tempArrayIrrad_029, curArray029, 0, 0);
  gr029_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr029_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr029_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr029_tempcur -> SetMarkerStyle(7);
  gr029_tempcur -> Draw("Ap"); 
 

  // ******************************************************************
  // TCN17006A
  // ******************************************************************

   TCanvas *c006A = new TCanvas("c006A", "c006A",900,500);
   c006A -> SetLogy();

  // INTEGRAL FROM THE FIT
  TGraphErrors *gr006A = new TGraphErrors(counts17, delayTimeArray17, UCNIntegralArray17, 0 , UCNIntegralErrArray17);

  gr006A -> SetTitle("UCN Counts vs Valve Delay Time");
  gr006A -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr006A -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006A -> GetXaxis()-> SetRangeUser(0, 120);
  gr006A -> SetMarkerStyle(7);

  gr006A -> Fit(fit1exp, "+R");
  fit1exp -> SetLineColor(1);
  storagefit006A_1expfit =fit1exp->GetParameter(1);
  storageErrfit006A_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraphErrors *gr006A_hist = new TGraphErrors (counts17, delayTimeArray17, HistIntegralArray17 , 0 , HistIntegralErrArray17);
  gr006A_hist -> SetMarkerStyle(7);
  gr006A_hist -> SetMarkerColor(2);
  gr006A_hist -> GetXaxis()-> SetRangeUser(0, 120);


  gr006A -> Draw("ap");
  gr006A_hist -> Draw("p");

  TCanvas *c006A_cur = new TCanvas("c006A_cur" , "c006A_cur" , 900, 500);
  c006A_cur -> SetLogy();
  TGraphErrors *gr006A_cur = new TGraphErrors(counts17, curArray006A, UCNIntegralArray17, 0, UCNIntegralErrArray17);
  gr006A_cur -> SetTitle("UCN Counts vs Average Beam Current");
  gr006A_cur -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr006A_cur -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006A_cur -> GetYaxis()-> SetRangeUser(1, 70000);
  gr006A_cur -> SetMarkerStyle(7);

  TGraphErrors *gr006A_hist_cur = new TGraphErrors (counts17 , curArray006A, HistIntegralArray17 , 0 , HistIntegralErrArray17);
  gr006A_hist_cur -> SetMarkerStyle(7);
  gr006A_hist_cur -> SetMarkerColor(2);

  gr006A_cur -> Draw("ap");
  gr006A_hist_cur -> Draw("p");

  TCanvas *c006A_temp = new TCanvas ("c006A_temp" , "c006A_temp" , 900, 900);
  //c1_temp -> SetLogy();
  c006A_temp -> Divide(1,2);

  c006A_temp -> cd(1);
  TGraphErrors *gr006A_temp = new TGraphErrors (counts17, tempArrayIrrad_006A, UCNIntegralArray17, 0, UCNIntegralErrArray17);
  gr006A_temp -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr006A_temp -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr006A_temp -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006A_temp -> SetMarkerStyle(7);
  gr006A_temp -> Draw("Ap");

  c006A_temp -> cd(2);
  TGraphErrors *gr006A_tempcur = new TGraphErrors (counts17, tempArrayIrrad_006A, curArray006A, 0, 0);
  gr006A_tempcur -> SetTitle("Average Beam Current vs Average Isopure Temperature");
  gr006A_tempcur -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr006A_tempcur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)");
  gr006A_tempcur -> SetMarkerStyle(7);
  gr006A_tempcur -> Draw("Ap"); 


  // **********************************************************************
  // STORAGE TIME
  // *********************************************************************

  // THE EXPERIMENT NUMBER
  double experiment[16] = {17003, 17013, 17023, 17025, 17026, 17029.5, 17031,  17006, 17021, 17004.5, 17004.75, 17009, 17009.5, 17014, 17029 , 17006.5};
  
  // FOR 10 S IRRADIATION TIME
  //double storage_10[3] = { storagefit004A_10_1expfit,   storagefit009_10_1expfit,   storagefit009A_10_1expfit};
  //double storage_10Err [3] = {  storageErrfit004A_10_1expfit  , storageErrfit009_10_1expfit ,storageErrfit009A_10_1expfit};
  //double storage_10_expNum[3] ={17004.5, 17009, 17009.5};
  double storage_10[2] = {    storagefit009_10_1expfit,   storagefit009A_10_1expfit};
  double storage_10Err [2] = {    storageErrfit009_10_1expfit ,storageErrfit009A_10_1expfit};
  double storage_10_expNum[2] ={ 17009, 17009.5};
  double temp_10[2] = {aveT009_10_valveopen, aveT009A_10_valveopen};
  double tempErr_10[2]={sdT009_10_valveopen, sdT009A_10_valveopen};

  // FOR 20S IRRADITION TIME
  //double  storage_20 [1] = {  storagefit004A_20_1expfit};
  //double storage_20Err[1] = {  storageErrfit004A_20_1expfit};
  //double storage_20_expNum[1] = {17004.5};

  // FOR 30S IRRADIATION TIME
  //double storage_30[5] = {  storagefit004A_30_1expfit,  storagefit009_30_1expfit,  storagefit009A_30_1expfit,  storagefit014_1expfit,  storagefit029_1expfit };
  //double storage_30Err[5] = { storageErrfit004A_30_1expfit,  storageErrfit009_30_1expfit,  storageErrfit009A_30_1expfit,   storageErrfit014_1expfit,  storageErrfit029_1expfit};
  //double storage_30_expNum[5]= {17004.5, 17009, 17009.5, 17014, 17029};
  double storage_30[4] = {   storagefit009_30_1expfit,  storagefit009A_30_1expfit,  storagefit014_1expfit,  storagefit029_1expfit };
  double storage_30Err[4] = {   storageErrfit009_30_1expfit,  storageErrfit009A_30_1expfit,   storageErrfit014_1expfit,  storageErrfit029_1expfit};
  double storage_30_expNum[4]= { 17009, 17009.5, 17014, 17029};
  double temp_30[4] = {aveT009_30_valveopen, aveT009A_30_valveopen, aveT014_valveopen, aveT029_valveopen};
  double tempErr_30[4] ={sdT009_30_valveopen, sdT009A_30_valveopen, sdT014_valveopen, sdT029_valveopen};

  // FOR 40S IRRATIATION TIME
  //double storage_40[1] = {  storagefit004A_40_1expfit};
  //double storage_40Err[1] = {  storageErrfit004A_40_1expfit};
  //double storage_40_expNum[1]={17004.5};

  //FOR 50S IRRADIATION TIME
  //double storage_50[1] = {  storagefit004A_50_1expfit};
  //double storage_50Err[1] = {  storageErrfit004A_50_1expfit};
  //double storage_50_expNum[1]={17004.5};

  //FOR 60S IRRADIATION TIME
  //double storage_60 [13] = {  storagefit002_1expfit,  storagefit003_1expfit,  storagefit004A_60_1expfit,  storagefit006_1expfit,   storagefit009_60_1expfit,  storagefit009A_60_1expfit,  storagefit013_1expfit,  storagefit021_1expfit,  storagefit023_1expfit ,   storagefit025_1expfit,  storagefit026_1expfit,  storagefit029A_1expfit,   storagefit031_1expfit}; 
  //double storage_60Err[13] = {  storageErrfit002_1expfit,  storageErrfit003_1expfit,  storageErrfit004A_60_1expfit,   storageErrfit006_1expfit,   storageErrfit009_60_1expfit,  storageErrfit009A_60_1expfit,  storageErrfit013_1expfit,  storageErrfit021_1expfit,  storageErrfit023_1expfit,  storageErrfit025_1expfit,  storageErrfit026_1expfit,  storageErrfit029A_1expfit,   storageErrfit031_1expfit };
  //double storage_60_expNum[13] = {17002, 17003, 17004.5, 17006,17009, 17009.5,17013, 17021,17023, 17025, 17026, 17029.5 , 17031 };
  double storage_60 [13] = {  storagefit002_1expfit,  storagefit003_1expfit,   storagefit006_1expfit,   storagefit009_60_1expfit,  storagefit009A_60_1expfit,  storagefit013_1expfit,  storagefit021_1expfit,  storagefit023_1expfit ,   storagefit025_1expfit,  storagefit026_1expfit,  storagefit029A_1expfit,   storagefit031_1expfit, storagefit006A_1expfit}; 
  double storage_60Err[13] = {  storageErrfit002_1expfit,  storageErrfit003_1expfit,  storageErrfit006_1expfit,   storageErrfit009_60_1expfit,  storageErrfit009A_60_1expfit,  storageErrfit013_1expfit,  storageErrfit021_1expfit,  storageErrfit023_1expfit,  storageErrfit025_1expfit,  storageErrfit026_1expfit,  storageErrfit029A_1expfit,   storageErrfit031_1expfit,  storageErrfit006A_1expfit };
  double storage_60_expNum[13] = {17002, 17003, 17006,17009, 17009.5,17013, 17021,17023, 17025, 17026, 17029.5 , 17031, 17006.5 };
  double temp_60[13]={aveT002_valveopen, aveT003_valveopen, aveT006_valveopen, aveT009_60_valveopen, aveT009A_60_valveopen, aveT013_valveopen, aveT021_valveopen, aveT023_valveopen, aveT025_valveopen, aveT026_valveopen, aveT029A_valveopen, aveT031_valveopen, aveT006A_valveopen};
  double tempErr_60[13]={sdT002_valveopen, sdT003_valveopen, sdT006_valveopen, sdT009_60_valveopen, sdT009A_60_valveopen, sdT025_valveopen, sdT026_valveopen, sdT029A_valveopen, sdT031_valveopen, sdT006A_valveopen};

  // FOR 80S IRRADIATION TIME
  //double storage_80[1] = {  storagefit004A_80_1expfit};
  //double storage_80Err[1] = {  storageErrfit004A_80_1expfit};
  //double storage_80_expNum[1]={17004.5};

  // FOR 100S IRRADIATION TIME
  //double storage_100[2] = {  storagefit004A_100_1expfit,  storagefit004B_1expfit };
  //double storage_100Err[2] = {  storageErrfit004A_100_1expfit,  storageErrfit004B_1expfit };
  //double storage_100_expNum[2] = {17004.5 , 17004.75};
  double storage_100[1] = {  storagefit004B_1expfit };
  double storage_100Err[1] = {   storageErrfit004B_1expfit };
  double storage_100_expNum[1] = { 17004.75};
  double temp_100[1] = {aveT004B_valveopen};
  double tempErr_100[1] = {sdT004B_valveopen};

  // FOR 120S IRRADIATION TIME
  //double storage_120[2] = {  storagefit004A_120_1expfit,   storagefit009A_120_1expfit} ;
  //double storage_120Err[2] = {  storageErrfit004A_120_1expfit,  storageErrfit009A_120_1expfit };
  //double storage_120_expNum[2] = {17004.5, 17009.5 };
  double storage_120[1] = { storagefit009A_120_1expfit} ;
  double storage_120Err[1] = {storageErrfit009A_120_1expfit };
  double storage_120_expNum[1] = { 17009.5 };
  double temp_120[1] = {aveT009A_120_valveopen};
  double tempErr_120[1] = {sdT009A_120_valveopen};

  // FOR 150S IRRADIATION TIME
  //double storage_150[1] = {  storagefit004A_150_1expfit};
  //double storage_150Err[1] = {  storageErrfit004A_150_1expfit};
  //double storage_150_expNum[1]={17004.5};
  
  
  TCanvas *cstorage = new TCanvas ("cstorage" , "cstorage", 900, 500);
  //TGraphErrors *grStorage10 = new TGraphErrors(3, storage_10_expNum , storage_10 , 0 , storage_10Err);
  //grStorage10 -> SetMarkerStyle(2);

  //TGraphErrors *grStorage20 = new TGraphErrors(1, storage_20_expNum , storage_20 , 0 , storage_20Err);
  //grStorage20 -> SetMarkerStyle(3);

  TGraphErrors *grStorage30 = new TGraphErrors(4, storage_30_expNum , storage_30 , 0 , storage_30Err);
  grStorage30 -> SetMarkerStyle(4);
  grStorage30 -> GetXaxis()->SetLimits(17001, 17035);
  grStorage30 -> SetTitle("Storage Time (s) vs Experiment Number");
  grStorage30 -> GetXaxis()-> SetTitle("Experiment Number");
  grStorage30 -> GetYaxis() -> SetTitle("Storage Time (s) ");

  //TGraphErrors *grStorage40 = new TGraphErrors(1, storage_40_expNum , storage_40 , 0 , storage_40Err);
  //grStorage40 -> SetMarkerStyle(5);

  //TGraphErrors *grStorage50 = new TGraphErrors(1, storage_50_expNum , storage_50 , 0 , storage_50Err);
  //grStorage50 -> SetMarkerStyle(6);

  TGraphErrors *grStorage60 = new TGraphErrors(12, storage_60_expNum , storage_60 , 0 , storage_60Err);
  grStorage60 -> SetMarkerStyle(7);

  //TGraphErrors *grStorage80 = new TGraphErrors(1, storage_80_expNum , storage_80 , 0 , storage_80Err);
  //grStorage80 -> SetMarkerStyle(8);

  TGraphErrors *grStorage100 = new TGraphErrors(1, storage_100_expNum , storage_100 , 0 , storage_100Err);
  grStorage100 -> SetMarkerStyle(25);

  TGraphErrors *grStorage120 = new TGraphErrors(1, storage_120_expNum , storage_120 , 0 , storage_120Err);
  grStorage120 -> SetMarkerStyle(26);

  //TGraphErrors *grStorage150 = new TGraphErrors(1, storage_150_expNum , storage_150 , 0 , storage_150Err);
  //grStorage150 -> SetMarkerStyle(11);


  TLegend *leg = new TLegend(0.7,0.7, 0.9, 0.9);
  //  leg -> AddEntry(grStorage10 , "10s Irradiation time" , "p") ;
  //  leg -> AddEntry(grStorage20 , "20s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage30 , "30s Irradiation time" , "p") ;
  //  leg -> AddEntry(grStorage40 , "40s Irradiation time" , "p") ;
  //  leg -> AddEntry(grStorage50 , "50s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage60 , "60s Irradiation time" , "p") ;
  //  leg -> AddEntry(grStorage80 , "80s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage100 , "100s Irradiation time" , "p") ;
  leg -> AddEntry(grStorage120 , "120s Irradiation time" , "p") ;
  //  leg -> AddEntry(grStorage150 , "150s Irradiation time" , "p") ;

  //grStorage10 -> Draw("ap");
  //grStorage20 -> Draw("p");
  grStorage30 -> Draw("ap");
  //grStorage40 -> Draw("p");
  //grStorage50 -> Draw("p");
  grStorage60 -> Draw("p");
  //grStorage80 -> Draw("p");
  grStorage100 -> Draw("p");
  grStorage120 -> Draw("p");
  //grStorage150 -> Draw("p");

  leg -> Draw(); 


  TCanvas *ctemp = new TCanvas ("ctemp" , "ctemp", 900, 500);
  TGraphErrors *grtemp30 = new TGraphErrors(4, temp_30 , storage_30 , tempErr_30 , storage_30Err);
  grtemp30 -> SetMarkerStyle(4);
  grtemp30 -> GetXaxis()->SetLimits(0.85, 1.2);
  grtemp30 -> SetTitle("Storage Time (s) vs Isopure Temperature");
  grtemp30 -> GetXaxis()-> SetTitle("Isopure Temperature (K)");
  grtemp30 -> GetYaxis() -> SetTitle("Storage Time (s) ");
  TGraphErrors *grtemp60 = new TGraphErrors(12, temp_60 , storage_60 , tempErr_60 , storage_60Err);
  grtemp60 -> SetMarkerStyle(7);
  TGraphErrors *grtemp100 = new TGraphErrors(1, temp_100 , storage_100 , tempErr_100 , storage_100Err);
  grtemp100 -> SetMarkerStyle(25);
  TGraphErrors *grtemp120 = new TGraphErrors(1, temp_120 , storage_120 , tempErr_120 , storage_120Err);
  grtemp120 -> SetMarkerStyle(26);

  TLegend *leg2 = new TLegend(0.7,0.7, 0.9, 0.9);
  leg2 -> AddEntry(grtemp30 , "30s Irradiation time" , "p") ;
  leg2 -> AddEntry(grtemp60 , "60s Irradiation time" , "p") ;
  leg2 -> AddEntry(grtemp100 , "100s Irradiation time" , "p") ;
  leg2 -> AddEntry(grtemp120 , "120s Irradiation time" , "p") ;

  grtemp30 -> Draw("ap");
  grtemp60 -> Draw("p");
  grtemp100 -> Draw("p");
  grtemp120 -> Draw("p");
  leg2 -> Draw();

  // DRAW LABELS ON X AXIS
  TText *t = new TText();
  t-> SetNDC();
  t->SetTextAlign(32);
  t->SetTextSize(0.035);
  t->SetTextFont(72);
  char *labels_30[4] = {"17009","17009A","17014","17029"};
  for (Int_t i = 0 ; i < 4 ; i++){
  t->DrawText(-0.42,storage_30[i],labels_30[i]);
  }


  // ORGANIZING ALL OF THE STORAGE TIME MEASUREMENTS
  // THESE ARE THE GROUPS THAT I CAME UP WITH BASED ON SIMILAR RANGE FOR THESE
  // PARAMETERS: BEAM CURRENT, IRRADIATION TIME AND ISOPURE TEMPERATURE

  // GROUP ONE  : FOR 60 SECONDS IRRADIATION TIME, ISOPURE TEMPERATURE IN 0.84 - 1.04 K
  //              AND AROUND 1 MICRO AMP BEAM CURRENT
  // GROUP TWO  : FOR 100 SECONDS IRRADIATION TIME, ISOPURE TEMPERATURE 0.86-1. K
  //              AND AROUND 1 MICRO AMP BEAM CURRENT
  // GROUP TREE : FOR 10 SECONDS IRRADIATION TIME, ISOPURE TEMPERATURE OF 0.83-1.8 K
  //              AND 2-10 MICRO AMP BEAM CURRENT
  // GROUP FOUR : FOR 60 SECONDS IRRADIAITON TIME, ISOPURE TEMPERATURE OF 0.95-1.2 K
  //              AND THE BEAM CURRET OF 2-12 ISH MICRO AMP
  // GROUP FIVE : FOR 30 SECONDS IRRADIATION TIME, ISOPURE TEMPERATURE FROM 0.85-1.85 K
  //              AND BEAM CURRENT OF 0.5 - 12 MICRO AMP
  // GROUP SIX  : FOR 120 S IRRADIATION TIME, ISOPURE TEMPERATURE OF 0.97-1.06 K
  //              AND BEAM CURRENT OF ABOUT 2.6 MICRO AMP


  // SET THE DATE FOR ALL THE EXPERIMENTS
  TDatime da002 (2017,11,13,12,00,00);
  TDatime da003 (2017,11,14,12,00,00);
  TDatime da004B (2017,11,15,12,00,00);
  TDatime da006 (2017,11,16,12,00,00);
  TDatime da006a (2017,11,17,12,00,00);
  TDatime da006a (2017,11,17,12,00,00);
  TDatime da009 (2017,11,18,12,00,00);
  TDatime da009a (2017,11,19,12,00,00);
  TDatime da013 (2017,11,21,12,00,00);
  TDatime da014 (2017,11,22,12,00,00);
  TDatime da021 (2017,11,26,12,00,00);
  TDatime da023 (2017,11,27,12,00,00);
  TDatime da025 (2017,11,28,12,00,00);
  TDatime da026 (2017,11,29,12,00,00);
  TDatime da029 (2017,12,01,12,00,00);
  TDatime da029a (2017,12,01,12,00,00);
  TDatime da031 (2017,12,01,12,00,00);
  
  double g1_date [11] = {da002.Convert(), da003.Convert(), da006.Convert(), da013.Convert(), da021.Convert(), da023.Convert(), da025.Convert(), da026.Convert(), da029a.Convert(), da031.Convert(), da006a.Convert()};
  
  double g2_date[1]={ da004B.Convert()};
  
  double g3_date[2] = {da009.Convert(), da009a.Convert()};
  
  double g4_date[2]= {da009.Convert(), da009a.Convert()};
  
  double g5_date[4] = {da009.Convert(), da009a.Convert(), da014.Convert(), da029.Convert()};
  
  double g5_date[1] = {da009a.Convert()};
  
  
  double storage_g1 [12] = { storagefit002_1expfit,  storagefit003_1expfit,   storagefit006_1expfit,  storagefit013_1expfit,  storagefit021_1expfit,  storagefit023_1expfit ,   storagefit025_1expfit,  storagefit026_1expfit,  storagefit029A_1expfit,   storagefit031_1expfit, storagefit006A_1expfit};
  double storageErr_g1 [12] = {storageErrfit002_1expfit, storageErrfit003_1expfit,  storageErrfit006_1expfit,storageErrfit013_1expfit,  storageErrfit021_1expfit,  storageErrfit023_1expfit,  storageErrfit025_1expfit,  storageErrfit026_1expfit,  storageErrfit029A_1expfit,  storageErrfit031_1expfit,  storageErrfit006A_1expfit};
  double g1_temp[12] = {aveT002_irrad, aveT003_irrad, aveT006_irrad, aveT013_irrad, aveT021_irrad, aveT023_irrad, aveT025_irrad, aveT026_irrad, aveT029A_irrad, aveT031_irrad, aveT006A_irrad};
  double g1_tempErr[11] = {sdT002_irrad, sdT003_irrad, sdT006_irrad, sdT013_irrad, sdT021_irrad, sdT023_irrad, sdT025_irrad, sdT026_irrad, sdT029A_irrad, sdT031_irrad, sdT006A_irrad};
  double g1_cur [11] = {aveavecur002, aveavecur003, aveavecur006, aveavecur013, aveavecur021, aveavecur023, aveavecur025, aveavecur026, aveavecur029A, aveavecur031, aveavecur006A};
  double g1_curErr[11] = {sdcur002, sdcur003, sdcur006, sdcur013, sdcur021, sdcur023, sdcur025, sdcur026, sdcur029A, sdcur031, sdcur006A};
  double g1_expnum[11]= {17002, 17003,17006, 17013, 17021, 17023, 17025, 17026, 17029.5,17031, 17006.5};
  
  double storage_g2 [1] = { storagefit004B_1expfit};
  double storageErr_g2[1] = { storageErrfit004B_1expfit };
  double g2_temp[1] = {aveT004B_irrad};
  double g2_tempErr[1] = {sdT004B_irrad};
  double g2_cur[1] = {aveavecur004B};
  double g2_curErr[1] = {sdcur004B};
  
  double storage_g3[3]= { storagefit009_10_1expfit,   storagefit009A_10_1expfit};
  double storageErr_g3[3] = {storageErrfit009_10_1expfit ,storageErrfit009A_10_1expfit};
  double g3_temp[2] = {aveT009_10_irrad, aveT009A_10_irrad};
  double g3_tempErr[2] = {sdT009_10_irrad, sdT009A_10_irrad};
  double g3_cur[2] = {aveavecur009_10, aveavecur009A_10};
  double g3_curErr[2] = {sdcur009_10 , sdcur009A_10};
  
  double storage_g4[2] = {storagefit009_60_1expfit,   storagefit009A_60_1expfit};
  double storageErr_g4[2] = {storageErrfit009_60_1expfit ,storageErrfit009A_60_1expfit};
  double g4_temp[2] = {aveT009_60_irrad, aveT009A_60_irrad};  
  double g4_tempErr[2] = {sdT009_60_irrad,  sdT009A_60_irrad};
  double g4_cur[2] = {aveavecur009_60 , aveavecur009A_60};
  double g4_curErr[2] = {sdcur009_60 , sdcur009A_60};

  double storage_g5[4] = {storagefit009_30_1expfit,  storagefit009A_30_1expfit,  storagefit014_1expfit,  storagefit029_1expfit };
  double storageErr_g5[4] = {storageErrfit009_30_1expfit,  storageErrfit009A_30_1expfit,   storageErrfit014_1expfit,  storageErrfit029_1expfit};
  double g5_temp[4] = {aveT009_30_irrad, aveT009A_30_irrad, aveT014_irrad, aveT029_irrad};
  double g5_tempErr[4] = {sdT009_30_irrad, sdT009A_30_irrad, sdT014_irrad, sdT029_irrad};
  double g5_cur[4] = {aveavecur009_30, aveavecur009A_30, aveavecur014, aveavecur029};
  double g5_cur[4] = {sdcur009_30, sdcur009A_30 , aveavecur014, aveavecur029};

  double storage_g6[1] = { storagefit009A_120_1expfit};
  double storageErr_g6[1] = {storageErrfit009A_120_1expfit};
  double g6_temp[1] = {aveT009A_120_irrad};
  double g6_tempErr[1] = {sdT009A_120_irrad};
  double g6_cur[1]= {aveavecur009A_120};
  double g6_curErr[1] = {sdcur009A_120};
  

  // FOR GROUP ONE
  TCanvas *c1_g1 = new TCanvas("c1_g1" , "c1_g1" , 900, 500); 
  c1_g1 -> Divide(2,2);
  
  c1_g1 -> cd(1);
  
  TGraphErrors *g1_1 = new TGraphErrors (11, g1_date, storage_g1, 0, storageErr_g1); 
  
  g1_1-> SetMarkerStyle(7);
  g1_1 -> SetTitle("storage Time vs Date");
  g1_1 -> GetYaxis() -> SetTitle("Storage time (s)");
  g1_1 -> GetXaxis()->SetTimeDisplay(1);
  g1_1 -> GetXaxis()->SetNdivisions(513);
  g1_1 -> GetXaxis()->SetTimeFormat("%Y-%m-%d");
  g1_1 -> GetXaxis()->SetTimeOffset(0,"pst");
  g1_1 -> GetXaxis() -> SetTitleSize(0.05);
  g1_1 -> GetYaxis() -> SetTitleSize(0.05);
  g1_1-> Draw("Ap");
  

  c1_g1-> cd(2);
  TGraphErrors *g1_2 = new TGraphErrors (11, g1_temp, storage_g1, g1_tempErr, storageErr_g1);
  g1_2 -> SetTitle("Storage Time vs Isopure Temperature");
  g1_2 -> SetMarkerStyle(7);
  g1_2 -> GetYaxis() -> SetTitle("Storage time (s)");
  g1_2 -> GetXaxis() -> SetTitle("Isopure Temperature (K)");
  g1_2 -> GetXaxis() -> SetTitleSize(0.05);
  g1_2 -> GetYaxis() -> SetTitleSize(0.05);
  g1_2 -> Draw("ap");

  c1_g1-> cd(3);
  TGraphErrors *g1_3 = new TGraphErrors (11, g1_expnum, storage_g1, 0, storageErr_g1);
  g1_3 -> SetTitle("Storage Time vs Experiment Number");
  g1_3 -> SetMarkerStyle(7);
  g1_3 -> GetYaxis() -> SetTitle("Storage time (s)");
  g1_3 -> GetXaxis() -> SetTitle("Experiment Number");
  g1_3 -> GetXaxis() -> SetTitleSize(0.05);
  g1_3 -> GetYaxis() -> SetTitleSize(0.05);
  g1_3 -> Draw("ap");

  c1_g1 -> cd(4);
 TGraphErrors *g1_4 = new TGraphErrors (11, g1_cur, storage_g1, g1_curErr, storageErr_g1);
  g1_4 -> SetTitle("Storage Time vs Average Beam Current");
  g1_4 -> SetMarkerStyle(7);
  g1_4 -> GetYaxis() -> SetTitle("Storage time (s)");
  g1_4 -> GetXaxis() -> SetTitle("Average Beam Current (#muA)");
  g1_4 -> GetXaxis() -> SetTitleSize(0.05);
  g1_4 -> GetYaxis() -> SetTitleSize(0.05);
  g1_4 -> Draw("ap");

  // FOR GROUP TWO
  TCanvas *c2_g2 = new TCanvas("c2_g2" , "c2_g2" , 900, 500);
  c2_g2 -> Divide(2,2);
  
  c2_g2 -> cd(1);
  
  TGraphErrors *g2_1 = new TGraphErrors (1, g2_date, storage_g2, 0, storageErr_g2); 
  
  g2_1-> SetMarkerStyle(7);
  g2_1 -> SetTitle("storage Time vs Date");
  g2_1 -> GetYaxis() -> SetTitle("Storage time (s)");
  g2_1 -> GetXaxis()->SetTimeDisplay(1);
  g2_1 -> GetXaxis()->SetNdivisions(503);
  g2_1 -> GetXaxis()->SetTimeFormat("%Y-%m-%d");
  g2_1 -> GetXaxis()->SetTimeOffset(0,"pst");
  g2_1-> Draw("Ap");
  
  c2_g2-> cd(2);
  TGraphErrors *g2_2 = new TGraphErrors (1, g2_temp, storage_g2, g2_tempErr, storageErr_g2);
  g2_2 -> SetTitle("Storage Time vs Isopure Temperature");
  g2_2 -> SetMarkerStyle(7);
  g2_2 -> GetYaxis() -> SetTitle("Storage time (s)");
  g2_2 -> GetXaxis() -> SetTitle("Isopure Temperature (K)");
  g2_2 -> Draw("ap");

  c2_g2 -> cd(4);
 TGraphErrors *g2_4 = new TGraphErrors (1, g2_cur, storage_g2, g2_curErr, storageErr_g2);
  g2_4 -> SetTitle("Storage Time vs Average Beam Current");
  g2_4 -> SetMarkerStyle(7);
  g2_4 -> GetYaxis() -> SetTitle("Storage time (s)");
  g2_4 -> GetXaxis() -> SetTitle("Average Beam Current (#muA)");
  g2_4 -> Draw("ap");

  //FOR GROUP THREE 
  TCanvas *c3_g3 = new TCanvas("c3_g3" , "c3_g3" , 900, 500);
  c3_g3 -> Divide(2,2);
  
  c3_g3 -> cd(1);
  
  TGraphErrors *g3_1 = new TGraphErrors (2, g3_date, storage_g3, 0, storageErr_g3); 
  
  g3_1-> SetMarkerStyle(7);
  g3_1 -> SetTitle("storage Time vs Date");
  g3_1 -> GetYaxis() -> SetTitle("Storage time (s)");
  g3_1 -> GetXaxis()->SetTimeDisplay(1);
  g3_1 -> GetXaxis()->SetNdivisions(503);
  g3_1 -> GetXaxis()->SetTimeFormat("%Y-%m-%d");
  g3_1 -> GetXaxis()->SetTimeOffset(0,"pst");
  g3_1-> Draw("Ap");
  
  c3_g3-> cd(2);
  TGraphErrors *g3_2 = new TGraphErrors (2, g3_temp, storage_g3, g3_tempErr, storageErr_g3);
  g3_2 -> SetTitle("Storage Time vs Isopure Temperature");
  g3_2 -> SetMarkerStyle(7);
  g3_2 -> GetYaxis() -> SetTitle("Storage time (s)");
  g3_2 -> GetXaxis() -> SetTitle("Isopure Temperature (K)");
  g3_2 -> Draw("ap");

  c3_g3 -> cd(4);
 TGraphErrors *g3_4 = new TGraphErrors (2, g3_cur, storage_g3, g3_curErr, storageErr_g3);
  g3_4 -> SetTitle("Storage Time vs Average Beam Current");
  g3_4 -> SetMarkerStyle(7);
  g3_4 -> GetYaxis() -> SetTitle("Storage time (s)");
  g3_4 -> GetXaxis() -> SetTitle("Average Beam Current (#muA)");
  g3_4 -> Draw("ap");


  cout << storagefit009_60_1expfit << " " <<storageErrfit009_60_1expfit<< endl;

}
