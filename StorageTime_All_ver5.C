// ************************************************************
// This script is to analyze all the standard storage lifetime
// measurements.
// Taraneh Andalib, June 15, 2018
// *************************************************************

#define max 200

void StorageTime_All_ver5(){
  gStyle->SetOptFit(0000);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");

  // OPENING ALL THE FILES
  TFile *fin002 = new TFile("./2ndpass/outputTree_17002.root","READ");
  TFile *fin003 = new TFile("./2ndpass/outputTree_17003.root","READ");
  TFile *fin006 = new TFile("./2ndpass/outputTree_17006.root","READ");
  TFile *fin006A = new TFile("./2ndpass/outputTree_17006A.root", "READ");
  TFile *fin012 = new TFile("./2ndpass/outputTree_17012.root","READ");
  TFile *fin013 = new TFile("./2ndpass/outputTree_17013.root","READ");
  TFile *fin016 = new TFile("./2ndpass/outputTree_17016.root","READ");
  TFile *fin021 = new TFile("./2ndpass/outputTree_17021.root","READ");
  TFile *fin023 = new TFile("./2ndpass/outputTree_17023.root","READ");
  TFile *fin025 = new TFile("./2ndpass/outputTree_17025.root","READ");
  TFile *fin026 = new TFile("./2ndpass/outputTree_17026.root","READ");
  TFile *fin029 = new TFile("./2ndpass/outputTree_17029.root","READ");
  TFile *fin029A = new TFile("./2ndpassoutputTree_17029A.root","READ");
  TFile *fin031 = new TFile("./2ndpass/outputTree_17031.root","READ");
  TFile *fin780 = new TFile("./2ndpass/outputTree_780.root","READ");



  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree002 = (TTree*) fin002->Get("cycle_info");
  TTree *outputTree003 = (TTree*) fin003->Get("cycle_info");
  TTree *outputTree006 = (TTree*) fin006->Get("cycle_info");
  TTree *outputTree006A = (TTree*) fin006A->Get("cycle_info");
  TTree *outputTree012 = (TTree*) fin012->Get("cycle_info");
  TTree *outputTree013 = (TTree*) fin013->Get("cycle_info");
  TTree *outputTree016 = (TTree*) fin016->Get("cycle_info");
  TTree *outputTree021 = (TTree*) fin021->Get("cycle_info");
  TTree *outputTree023 = (TTree*) fin023->Get("cycle_info");
  TTree *outputTree025 = (TTree*) fin025->Get("cycle_info");
  TTree *outputTree026 = (TTree*) fin026->Get("cycle_info");
  TTree *outputTree029 = (TTree*) fin029->Get("cycle_info");
  TTree *outputTree029A = (TTree*) fin029A->Get("cycle_info");
  TTree *outputTree031 = (TTree*) fin031->Get("cycle_info");
  TTree *outputTree780 = (TTree*) fin780->Get("cycle_info");


  // CYCLE DELAY TIME FOR EACH FILE
  double cycleDelayTime002;
  outputTree002 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime002);
  double cycleDelayTime003;
  outputTree003 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime003);
  double cycleDelayTime006;
  outputTree006 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime006);
  double cycleDelayTime006A;
  outputTree006A -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime006A);
  double cycleDelayTime012;
  outputTree012 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime012);
  double cycleDelayTime013;
  outputTree013 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime013);
  double cycleDelayTime016;
  outputTree016 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime016);
  double cycleDelayTime021;
  outputTree021 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime021);
  double cycleDelayTime023;
  outputTree023 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime023);
  double cycleDelayTime025;
  outputTree025 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime025);
  double cycleDelayTime026;
  outputTree026 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime026);
  double cycleDelayTime029;
  outputTree029 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime029);
  double cycleDelayTime029A;
  outputTree029A -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime029A);
  double cycleDelayTime031;
  outputTree031 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime031);
  double cycleDelayTime780;
  outputTree780 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime780);


  double cycleDelayTimeArray002[max];
  double cycleDelayTimeArray003[max];
  double cycleDelayTimeArray006[max];
  double cycleDelayTimeArray006A[max];
  double cycleDelayTimeArray012[max];
  double cycleDelayTimeArray013[max];
  double cycleDelayTimeArray016[max];
  double cycleDelayTimeArray021[max];
  double cycleDelayTimeArray023[max];
  double cycleDelayTimeArray025[max];
  double cycleDelayTimeArray026[max];
  double cycleDelayTimeArray029[max];
  double cycleDelayTimeArray029A[max];
  double cycleDelayTimeArray031[max];
  double cycleDelayTimeArray780[max];


  
  // TOTAL UCN COUNTS COMING FROM THE HISTOGRAM INTEGRAL
  double HistIntegral002;
  outputTree002 -> SetBranchAddress ("HistIntegral" , &HistIntegral002);
  double HistIntegral003;
  outputTree003 -> SetBranchAddress ("HistIntegral" , &HistIntegral003);
  double HistIntegral006;
  outputTree006 -> SetBranchAddress ("HistIntegral" , &HistIntegral006);
  double HistIntegral006A;
  outputTree006A -> SetBranchAddress ("HistIntegral" , &HistIntegral006A);
  double HistIntegral012;
  outputTree012 -> SetBranchAddress ("HistIntegral" , &HistIntegral012);
  double HistIntegral013;
  outputTree013 -> SetBranchAddress ("HistIntegral" , &HistIntegral013);
  double HistIntegral016;
  outputTree016 -> SetBranchAddress ("HistIntegral" , &HistIntegral016);
  double HistIntegral021;
  outputTree021 -> SetBranchAddress ("HistIntegral" , &HistIntegral021);
  double HistIntegral023;
  outputTree023 -> SetBranchAddress ("HistIntegral" , &HistIntegral023);
  double HistIntegral025;
  outputTree025 -> SetBranchAddress ("HistIntegral" , &HistIntegral025);
  double HistIntegral026;
  outputTree026 -> SetBranchAddress ("HistIntegral" , &HistIntegral026);
  double HistIntegral029;
  outputTree029 -> SetBranchAddress ("HistIntegral" , &HistIntegral029);
  double HistIntegral029A;
  outputTree029A -> SetBranchAddress ("HistIntegral" , &HistIntegral029A);
  double HistIntegral031;
  outputTree031 -> SetBranchAddress ("HistIntegral" , &HistIntegral031);
  double HistIntegral780;
  outputTree780 -> SetBranchAddress ("HistIntegral" , &HistIntegral780);

  double HistIntegralArray002[max];
  double HistIntegralArray003[max];
  double HistIntegralArray006[max];
  double HistIntegralArray006A[max];
  double HistIntegralArray012[max];
  double HistIntegralArray013[max];
  double HistIntegralArray016[max];
  double HistIntegralArray021[max];
  double HistIntegralArray023[max];
  double HistIntegralArray025[max];
  double HistIntegralArray026[max];
  double HistIntegralArray029[max];
  double HistIntegralArray029A[max];
  double HistIntegralArray031[max];
  double HistIntegralArray780[max];


  double HistIntegralErrArray002[max];
  double HistIntegralErrArray003[max];
  double HistIntegralErrArray006[max];
  double HistIntegralErrArray006A[max];
  double HistIntegralErrArray012[max];
  double HistIntegralErrArray013[max];
  double HistIntegralErrArray016[max];
  double HistIntegralErrArray021[max];
  double HistIntegralErrArray023[max];
  double HistIntegralErrArray025[max];
  double HistIntegralErrArray026[max];
  double HistIntegralErrArray029[max];
  double HistIntegralErrArray029A[max];
  double HistIntegralErrArray031[max];
  double HistIntegralErrArray780[max];


  // AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12VO002;
  outputTree002 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO002);
  double avets12VO003;
  outputTree003 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO003);
  double avets12VO006;
  outputTree006 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO006);
  double avets12VO006A;
  outputTree006A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO006A);
  double avets12VO012;
  outputTree012 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO012);
  double avets12VO013;
  outputTree013 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO013);
  double avets12VO016;
  outputTree016 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO016);
  double avets12VO021;
  outputTree021 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO021);
  double avets12VO023;
  outputTree023 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO023);
  double avets12VO025;
  outputTree025 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO025);
  double avets12VO026;
  outputTree026 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO026);
  double avets12VO029;
  outputTree029 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO029);
  double avets12VO029A;
  outputTree029A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO029A);
  double avets12VO031;
  outputTree031 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO031);
  double avets12VO780;
  outputTree780 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO780);


  double avets12VOArray002[max];
  double avets12VOArray003[max];
  double avets12VOArray006[max];
  double avets12VOArray006A[max];
  double avets12VOArray012[max];
  double avets12VOArray013[max];
  double avets12VOArray016[max];
  double avets12VOArray021[max];
  double avets12VOArray023[max];
  double avets12VOArray025[max];
  double avets12VOArray026[max];
  double avets12VOArray029[max];
  double avets12VOArray029A[max];
  double avets12VOArray031[max];
  double avets12VOArray780[max];


  double ts12VOErrArray002[max];
  double ts12VOErrArray003[max];
  double ts12VOErrArray006[max];
  double ts12VOErrArray006A[max];
  double ts12VOErrArray012[max];
  double ts12VOErrArray013[max];
  double ts12VOErrArray016[max];
  double ts12VOErrArray021[max];
  double ts12VOErrArray023[max];
  double ts12VOErrArray025[max];
  double ts12VOErrArray026[max];
  double ts12VOErrArray029[max];
  double ts12VOErrArray029A[max];
  double ts12VOErrArray031[max];
  double ts12VOErrArray780[max];


  
  //MAXIMUM ISOPURE HELIUM DURING VALVE OPEN
  double maxts12VO002;
  outputTree002 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO002);
  double maxts12VO003;
  outputTree003 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO003);
  double maxts12VO006;
  outputTree006 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO006);
  double maxts12VO006A;
  outputTree006A -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO006A);
  double maxts12VO012;
  outputTree012 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO012);
  double maxts12VO013;
  outputTree013 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO013);
  double maxts12VO016;
  outputTree016 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO016);
  double maxts12VO021;
  outputTree021 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO021);
  double maxts12VO023;
  outputTree023 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO023);
  double maxts12VO025;
  outputTree025 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO025);
  double maxts12VO026;
  outputTree026 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO026);
  double maxts12VO029;
  outputTree029 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO029);
  double maxts12VO029A;
  outputTree029A -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO029A);
  double maxts12VO031;
  outputTree031 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO031);
  double maxts12VO780;
  outputTree780 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO780);

  // MINIMUM ISOPURE HELIUM DURING VALVE OPEN
  double mints12VO002;
  outputTree002 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO002);
  double mints12VO003;
  outputTree003 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO003);
  double mints12VO006;
  outputTree006 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO006);
  double mints12VO006A;
  outputTree006A -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO006A);
  double mints12VO012;
  outputTree012 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO012);
  double mints12VO013;
  outputTree013 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO013);
  double mints12VO016;
  outputTree016 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO016);
  double mints12VO021;
  outputTree021 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO021);
  double mints12VO023;
  outputTree023 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO023);
  double mints12VO025;
  outputTree025 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO025);
  double mints12VO026;
  outputTree026 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO026);
  double mints12VO029;
  outputTree029 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO029);
  double mints12VO029A;
  outputTree029A -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO029A);
  double mints12VO031;
  outputTree031 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO031);
  double mints12VO780;
  outputTree780 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO780);

  // BASELINE BEFORE IRRADIATION
  double BASELINERATE002;
  outputTree002 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE002);
  double BASELINERATE003;
  outputTree003 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE003);
  double BASELINERATE006;
  outputTree006 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE006);
  double BASELINERATE006A;
  outputTree006A -> SetBranchAddress ("BASELINERATE" , &BASELINERATE006A);
  double BASELINERATE012;
  outputTree012 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE012);
  double BASELINERATE013;
  outputTree013 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE013);
  double BASELINERATE016;
  outputTree016 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE016);
  double BASELINERATE021;
  outputTree021 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE021);
  double BASELINERATE023;
  outputTree023 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE023);
  double BASELINERATE025;
  outputTree025 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE025);
  double BASELINERATE026;
  outputTree026 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE026);
  double BASELINERATE029;
  outputTree029 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE029);
  double BASELINERATE029A;
  outputTree029A -> SetBranchAddress ("BASELINERATE" , &BASELINERATE029A);
  double BASELINERATE031;
  outputTree031 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE031);
  double BASELINERATE780;
  outputTree780 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE780);
 

  // IRRADIATION START TIMES
  double irradStartTimes002;
  outputTree002 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes002);
  double irradStartTimes003;
  outputTree003 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes003);
  double irradStartTimes006;
  outputTree006 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes006);
  double irradStartTimes006A;
  outputTree006A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes006A);
  double irradStartTimes012;
  outputTree012 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes012);
  double irradStartTimes013;
  outputTree013 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes013);
  double irradStartTimes016;
  outputTree016 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes016);
  double irradStartTimes021;
  outputTree021 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes021);
  double irradStartTimes023;
  outputTree023 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes023);
  double irradStartTimes025;
  outputTree025 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes025);
  double irradStartTimes026;
  outputTree026 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes026);
  double irradStartTimes029;
  outputTree029 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes029);
  double irradStartTimes029A;
  outputTree029A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes029A);
  double irradStartTimes031;
  outputTree031 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes031);
  double irradStartTimes780;
  outputTree780 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes780);

  // CYCLE START TIMES
  double cycleStartTimes002;
  outputTree002 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes002);
  double cycleStartTimes003;
  outputTree003 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes003);
  double cycleStartTimes006;
  outputTree006 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes006);
  double cycleStartTimes006A;
  outputTree006A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes006A);
  double cycleStartTimes012;
  outputTree012 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes012);
  double cycleStartTimes013;
  outputTree013 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes013);
  double cycleStartTimes016;
  outputTree016 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes016);
  double cycleStartTimes021;
  outputTree021 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes021);
  double cycleStartTimes023;
  outputTree023 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes023);
  double cycleStartTimes025;
  outputTree025 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes025);
  double cycleStartTimes026;
  outputTree026 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes026);
  double cycleStartTimes029;
  outputTree029 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes029);
  double cycleStartTimes029A;
  outputTree029A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes029A);
  double cycleStartTimes031;
  outputTree031 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes031);
  double cycleStartTimes780;
  outputTree780 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes780);

  // AVERAGE PREDICTED BEAM CURRENT
  double avecur002;
  outputTree002 -> SetBranchAddress ("AVE_PRDCUR" , &avecur002);
  double avecur003;
  outputTree003 -> SetBranchAddress ("AVE_PRDCUR" , &avecur003);
  double avecur006;
  outputTree006 -> SetBranchAddress ("AVE_PRDCUR" , &avecur006);
  double avecur006A;
  outputTree006A -> SetBranchAddress ("AVE_PRDCUR" , &avecur006A);
  double avecur012;
  outputTree012 -> SetBranchAddress ("AVE_PRDCUR" , &avecur012);
  double avecur013;
  outputTree013 -> SetBranchAddress ("AVE_PRDCUR" , &avecur013);
  double avecur016;
  outputTree016 -> SetBranchAddress ("AVE_PRDCUR" , &avecur016);
  double avecur021;
  outputTree021 -> SetBranchAddress ("AVE_PRDCUR" , &avecur021);
  double avecur023;
  outputTree023 -> SetBranchAddress ("AVE_PRDCUR" , &avecur023);
  double avecur025;
  outputTree025 -> SetBranchAddress ("AVE_PRDCUR" , &avecur025);
  double avecur026;
  outputTree026 -> SetBranchAddress ("AVE_PRDCUR" , &avecur026);
  double avecur029;
  outputTree029 -> SetBranchAddress ("AVE_PRDCUR" , &avecur029);
  double avecur029A;
  outputTree029A -> SetBranchAddress ("AVE_PRDCUR" , &avecur029A);
  double avecur031;
  outputTree031 -> SetBranchAddress ("AVE_PRDCUR" , &avecur031);
  double avecur780;
  outputTree780 -> SetBranchAddress ("AVE_PRDCUR" , &avecur780);


  double avecurArray002[max];
  double avecurArray003[max];
  double avecurArray006[max];
  double avecurArray006A[max];
  double avecurArray012[max];
  double avecurArray013[max];
  double avecurArray016[max];
  double avecurArray021[max];
  double avecurArray023[max];
  double avecurArray025[max];
  double avecurArray026[max];
  double avecurArray029[max];
  double avecurArray029A[max];
  double avecurArray031[max];
  double avecurArray780[max];


  double avecurErrArray002[max];
  double avecurErrArray003[max];
  double avecurErrArray006[max];
  double avecurErrArray006A[max];
  double avecurErrArray012[max];
  double avecurErrArray013[max];
  double avecurErrArray016[max];
  double avecurErrArray021[max];
  double avecurErrArray023[max];
  double avecurErrArray025[max];
  double avecurErrArray026[max];
  double avecurErrArray029[max];
  double avecurErrArray029A[max];
  double avecurErrArray031[max];
  double avecurErrArray780[max];

  // Maximum predicted beam current
  double maxcur002;
  outputTree002 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur002);
  double maxcur003;
  outputTree003 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur003);
  double maxcur006;
  outputTree006 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur006);
  double maxcur006A;
  outputTree006A -> SetBranchAddress ("MAX_PRDCUR" , &maxcur006A);
  double maxcur012;
  outputTree012 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur012);
  double maxcur013;
  outputTree013 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur013);
  double maxcur016;
  outputTree016 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur016);
  double maxcur021;
  outputTree021 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur021);
  double maxcur023;
  outputTree023 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur023);
  double maxcur025;
  outputTree025 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur025);
  double maxcur026;
  outputTree026 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur026);
  double maxcur029;
  outputTree029 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur029);
  double maxcur029A;
  outputTree029A -> SetBranchAddress ("MAX_PRDCUR" , &maxcur029A);
  double maxcur031;
  outputTree031 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur031);
  double maxcur780;
  outputTree780 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur780);


  // Minimum predicted beam current
  double mincur002;
  outputTree002 -> SetBranchAddress ("MIN_PRDCUR" , &mincur002);
  double mincur003;
  outputTree003 -> SetBranchAddress ("MIN_PRDCUR" , &mincur003);
  double mincur006;
  outputTree006 -> SetBranchAddress ("MIN_PRDCUR" , &mincur006);
  double mincur006A;
  outputTree006A -> SetBranchAddress ("MIN_PRDCUR" , &mincur006A);
  double mincur012;
  outputTree012 -> SetBranchAddress ("MIN_PRDCUR" , &mincur012);
  double mincur013;
  outputTree013 -> SetBranchAddress ("MIN_PRDCUR" , &mincur013);
  double mincur016;
  outputTree016 -> SetBranchAddress ("MIN_PRDCUR" , &mincur016);
  double mincur021;
  outputTree021 -> SetBranchAddress ("MIN_PRDCUR" , &mincur021);
  double mincur023;
  outputTree023 -> SetBranchAddress ("MIN_PRDCUR" , &mincur023);
  double mincur025;
  outputTree025 -> SetBranchAddress ("MIN_PRDCUR" , &mincur025);
  double mincur026;
  outputTree026 -> SetBranchAddress ("MIN_PRDCUR" , &mincur026);
  double mincur029;
  outputTree029 -> SetBranchAddress ("MIN_PRDCUR" , &mincur029);
  double mincur029A;
  outputTree029A -> SetBranchAddress ("MIN_PRDCUR" , &mincur029A);
  double mincur031;
  outputTree031 -> SetBranchAddress ("MIN_PRDCUR" , &mincur031);
  double mincur780;
  outputTree780 -> SetBranchAddress ("MIN_PRDCUR" , &mincur780);
  
  
  
  // cycle Valve Open Time
  double cycleValveOpenTime002;
  outputTree002 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime002);
  double cycleValveOpenTime003;
  outputTree003 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime003);
  double cycleValveOpenTime006;
  outputTree006 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime006);
  double cycleValveOpenTime006A;
  outputTree006A -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime006A);
  double cycleValveOpenTime012;
  outputTree012 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime012);
  double cycleValveOpenTime013;
  outputTree013 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime013);
  double cycleValveOpenTime016;
  outputTree016 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime016);
  double cycleValveOpenTime021;
  outputTree021 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime021);
  double cycleValveOpenTime023;
  outputTree023 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime023);
  double cycleValveOpenTime025;
  outputTree025 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime025);
  double cycleValveOpenTime026;
  outputTree026 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime026);
  double cycleValveOpenTime029;
  outputTree029 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime029);
  double cycleValveOpenTime029A;
  outputTree029A -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime029A);
  double cycleValveOpenTime031;
  outputTree031 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime031);
  double cycleValveOpenTime780;
  outputTree780 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime780);

  // cycle Valve Close Time
  double cycleValveCloseTime002;
  outputTree002 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime002);
  double cycleValveCloseTime003;
  outputTree003 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime003);
  double cycleValveCloseTime006;
  outputTree006 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime006);
  double cycleValveCloseTime006A;
  outputTree006A -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime006A);
  double cycleValveCloseTime012;
  outputTree012 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime012);
  double cycleValveCloseTime013;
  outputTree013 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime013);
  double cycleValveCloseTime016;
  outputTree016 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime016);
  double cycleValveCloseTime021;
  outputTree021 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime021);
  double cycleValveCloseTime023;
  outputTree023 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime023);
  double cycleValveCloseTime025;
  outputTree025 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime025);
  double cycleValveCloseTime026;
  outputTree026 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime026);
  double cycleValveCloseTime029;
  outputTree029 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime029);
  double cycleValveCloseTime029A;
  outputTree029A -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime029A);
  double cycleValveCloseTime031;
  outputTree031 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime031);
  double cycleValveCloseTime780;
  outputTree780 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime780);


  
  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON


  double storagelifetime002;
  double storagelifetime003;
  double storagelifetime006;
  double storagelifetime006A;
  double storagelifetime012;
  double storagelifetime013;
  double storagelifetime016;
  double storagelifetime021;
  double storagelifetime023;
  double storagelifetime025;
  double storagelifetime026;
  double storagelifetime029;
  double storagelifetime029A;
  double storagelifetime031;
  double storagelifetime780;


  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION

  double fitErr002;
  double fitErr003;
  double fitErr006;
  double fitErr006A;
  double fitErr012;
  double fitErr013;
  double fitErr016;
  double fitErr021;
  double fitErr023;
  double fitErr025;
  double fitErr026;
  double fitErr029;
  double fitErr029A;
  double fitErr031;
  double fitErr780;
  

  // loop counters
  int counter002;
  int counter003;
  int counter006;
  int counter006A;
  int counter012;
  int counter013;
  int counter016;
  int counter021;
  int counter023;
  int counter025;
  int counter026;
  int counter029;
  int counter029A;
  int counter031;
  int counter780;


  // UCN counts without background
  double UCNCounts002[max];
  double UCNCounts003[max];
  double UCNCounts006[max];
  double UCNCounts006A[max];
  double UCNCounts012[max];
  double UCNCounts013[max];
  double UCNCounts016[max];
  double UCNCounts021[max];
  double UCNCounts023[max];
  double UCNCounts025[max];
  double UCNCounts026[max];
  double UCNCounts029[max];
  double UCNCounts029A[max];
  double UCNCounts031[max];
  double UCNCounts780[max];


  // Error in the UCN counts without background
  double UCNCountsErr002[max];
  double UCNCountsErr003[max];
  double UCNCountsErr006[max];
  double UCNCountsErr006A[max];
  double UCNCountsErr012[max];
  double UCNCountsErr013[max];
  double UCNCountsErr016[max];
  double UCNCountsErr021[max];
  double UCNCountsErr023[max];
  double UCNCountsErr025[max];
  double UCNCountsErr026[max];
  double UCNCountsErr029[max];
  double UCNCountsErr029A[max];
  double UCNCountsErr031[max];
  double UCNCountsErr780[max];
  

  
  // GET THE EVENTS FOR TCN17002
  ULong64_t event002;
  event002 = (Double_t) outputTree002->GetEntries();

  // GET THE EVENTS FOR TCN17003
  ULong64_t event003;
  event003 = (Double_t)outputTree003->GetEntries();

  // GET THE EVENTS FOR TCN17006
  ULong64_t event006;
  event006 = (Double_t)outputTree006->GetEntries();

  // GET THE EVENTS FOR TCN17006A
  ULong64_t event006A;
  event006A = (Double_t)outputTree006A->GetEntries();

  // GET THE EVENTS FOR TCN17012
  ULong64_t event012;
  event012 = (Double_t)outputTree012->GetEntries();

  // GET THE EVENTS FOR TCN17013
  ULong64_t event013;
  event013 = (Double_t)outputTree013->GetEntries();

  // GET THE EVENTS FOR TCN17016
  ULong64_t event016;
  event016 = (Double_t)outputTree016->GetEntries();

  // GET THE EVENTS FOR TCN17021
  ULong64_t event021;
  event021 = (Double_t)outputTree021->GetEntries();

  // GET THE EVENTS FOR TCN17023
  ULong64_t event023;
  event023 = (Double_t)outputTree023->GetEntries();

  // GET THE EVENTS FOR TCN17025
  ULong64_t event025;
  event025 = (Double_t)outputTree025->GetEntries();

  // GET THE EVENTS FOR TCN17026
  ULong64_t event026;
  event026 = (Double_t)outputTree026->GetEntries();

  // GET THE EVENTS FOR TCN17029
  ULong64_t event029;
  event029 = (Double_t)outputTree029->GetEntries();

  // GET THE EVENTS FOR TCN17029A
  ULong64_t event029A;
  event029A = (Double_t)outputTree029A->GetEntries();

  // GET THE EVENTS FOR TCN17031
  ULong64_t event031;
  event031 = (Double_t)outputTree031->GetEntries();

  // GET THE EVENTS FOR run 780
  ULong64_t event780;
  event780 = (Double_t)outputTree780->GetEntries();



  //cout.setf(ios::fixed);

  // FOR TCN17002
  for (ULong64_t j = 0 ; j < event002 ; j++){
    outputTree002-> GetEvent(j);
    HistIntegralArray002[counter002] = HistIntegral002;
    HistIntegralErrArray002[counter002] = sqrt (HistIntegreal002);
    UCNCounts002[counter002] = HistIntegral002 - BASELINERATE002*(cycleValveCloseTime002 - cycleValveOpenTime002);
    UCNCountsErr002[counter002] = sqrt (UCNCounts002[counter002]);
    avets12VOArray002[counter002] = avets12VO002;
    ts12VOErrArray002[counter002] = (maxts12VO002 - mints12VO002)/2;
    avecurArray002[counter002] = avecur002;
    avecurErrArray002[counter002] = (maxcur002 - mincur002)/2;
    cout << "Cycle irradiation time is " << irradStartTime002 << endl;
    counter002++;
  }


  // For TCN17003
  for (ULong64_t j = 0 ; j < event003 ; j++){
    outputTree003-> GetEvent(j);
    HistIntegralArray003[counter003] = HistIntegral003;
    HistIntegralErrArray003[counter003] = sqrt (HistIntegreal003);
    UCNCounts003[counter003] = HistIntegral003 - BASELINERATE003*(cycleValveCloseTime003 - cycleValveOpenTime003);
    UCNCountsErr003[counter003] = sqrt (UCNCounts003[counter003]);
    avets12VOArray003[counter003] = avets12VO003;
    ts12VOErrArray003[counter003] = (maxts12VO003 - mints12VO003)/2;
    avecurArray003[counter003] = avecur003;
    avecurErrArray003[counter003] = (maxcur003 - mincur003)/2;
    cout << "Cycle irradiation time is " << irradStartTime003 << endl;
    counter003++;
  }
  
  // For TCN17006
  for (ULong64_t j = 0 ; j < event006 ; j++){
    outputTree006-> GetEvent(j);
    HistIntegralArray006[counter006] = HistIntegral006;
    HistIntegralErrArray006[counter006] = sqrt (HistIntegreal006);
    UCNCounts006[counter006] = HistIntegral006 - BASELINERATE006*(cycleValveCloseTime006 - cycleValveOpenTime006);
    UCNCountsErr006[counter006] = sqrt (UCNCounts006[counter006]);
    avets12VOArray006[counter006] = avets12VO006;
    ts12VOErrArray006[counter006] = (maxts12VO006 - mints12VO006)/2;
    avecurArray006[counter006] = avecur006;
    avecurErrArray006[counter006] = (maxcur006 - mincur006)/2;
    cout << "Cycle irradiation time is " << irradStartTime006 << endl;
    counter006++;
  }

  // For TCN17006A
  for (ULong64_t j = 0 ; j < event006A ; j++){
    outputTree006A-> GetEvent(j);
    HistIntegralArray006A[counter006A] = HistIntegral006A;
    HistIntegralErrArray006A[counter006A] = sqrt (HistIntegreal006A);
    UCNCounts006A[counter006A] = HistIntegral006A - BASELINERATE006A*(cycleValveCloseTime006A - cycleValveOpenTime006A);
    UCNCountsErr006A[counter006A] = sqrt (UCNCounts006A[counter006A]);
    avets12VOArray006A[counter006A] = avets12VO006A;
    ts12VOErrArray006A[counter006A] = (maxts12VO006A - mints12VO006A)/2;
    avecurArray006A[counter006A] = avecur006A;
    avecurErrArray006A[counter006A] = (maxcur006A - mincur006A)/2;
    cout << "Cycle irradiation time is " << irradStartTime006A << endl;
    counter006A++;
  }

  // For TCN17012
  for (ULong64_t j = 0 ; j < event012 ; j++){
    outputTree012-> GetEvent(j);
    HistIntegralArray012[counter012] = HistIntegral012;
    HistIntegralErrArray012[counter012] = sqrt (HistIntegreal012);
    UCNCounts012[counter012] = HistIntegral012 - BASELINERATE012*(cycleValveCloseTime012 - cycleValveOpenTime012);
    UCNCountsErr012[counter012] = sqrt (UCNCounts012[counter012]);
    avets12VOArray012[counter012] = avets12VO012;
    ts12VOErrArray012[counter012] = (maxts12VO012 - mints12VO012)/2;
    avecurArray012[counter012] = avecur012;
    avecurErrArray012[counter012] = (maxcur012 - mincur012)/2;
    cout << "Cycle irradiation time is " << irradStartTime012 << endl;
    counter012++;
  }


  // For TCN17013
  for (ULong64_t j = 0 ; j < event013 ; j++){
    outputTree013-> GetEvent(j);
    HistIntegralArray013[counter013] = HistIntegral013;
    HistIntegralErrArray013[counter013] = sqrt (HistIntegreal013);
    UCNCounts013[counter013] = HistIntegral013 - BASELINERATE013*(cycleValveCloseTime013 - cycleValveOpenTime013);
    UCNCountsErr013[counter013] = sqrt (UCNCounts013[counter013]);
    avets12VOArray013[counter013] = avets12VO013;
    ts12VOErrArray013[counter013] = (maxts12VO013 - mints12VO013)/2;
    avecurArray013[counter013] = avecur013;
    avecurErrArray013[counter013] = (maxcur013 - mincur013)/2;
    cout << "Cycle irradiation time is " << irradStartTime013 << endl;
    counter013++;
  }

  // For TCN17016
  for (ULong64_t j = 0 ; j < event016 ; j++){
    outputTree016-> GetEvent(j);
    HistIntegralArray016[counter016] = HistIntegral016;
    HistIntegralErrArray016[counter016] = sqrt (HistIntegreal016);
    UCNCounts016[counter016] = HistIntegral016 - BASELINERATE016*(cycleValveCloseTime016 - cycleValveOpenTime016);
    UCNCountsErr016[counter016] = sqrt (UCNCounts016[counter016]);
    avets12VOArray016[counter016] = avets12VO016;
    ts12VOErrArray016[counter016] = (maxts12VO016 - mints12VO016)/2;
    avecurArray016[counter016] = avecur016;
    avecurErrArray016[counter016] = (maxcur016 - mincur016)/2;
    cout << "Cycle irradiation time is " << irradStartTime016 << endl;
    counter016++;
  }

  // For TCN17021
  for (ULong64_t j = 0 ; j < event021 ; j++){
    outputTree021-> GetEvent(j);
    HistIntegralArray021[counter021] = HistIntegral021;
    HistIntegralErrArray021[counter021] = sqrt (HistIntegreal021);
    UCNCounts021[counter021] = HistIntegral021 - BASELINERATE021*(cycleValveCloseTime021 - cycleValveOpenTime021);
    UCNCountsErr021[counter021] = sqrt (UCNCounts021[counter021]);
    avets12VOArray021[counter021] = avets12VO021;
    ts12VOErrArray021[counter021] = (maxts12VO021 - mints12VO021)/2;
    avecurArray021[counter021] = avecur021;
    avecurErrArray021[counter021] = (maxcur021 - mincur021)/2;
    cout << "Cycle irradiation time is " << irradStartTime021 << endl;
    counter021++;
  }

  // For TCN17023
  for (ULong64_t j = 0 ; j < event023 ; j++){
    outputTree023-> GetEvent(j);
    HistIntegralArray023[counter023] = HistIntegral023;
    HistIntegralErrArray023[counter023] = sqrt (HistIntegreal023);
    UCNCounts023[counter023] = HistIntegral023 - BASELINERATE023*(cycleValveCloseTime023 - cycleValveOpenTime023);
    UCNCountsErr023[counter023] = sqrt (UCNCounts023[counter023]);
    avets12VOArray023[counter023] = avets12VO023;
    ts12VOErrArray023[counter023] = (maxts12VO023 - mints12VO023)/2;
    avecurArray023[counter023] = avecur023;
    avecurErrArray023[counter023] = (maxcur023 - mincur023)/2;
    cout << "Cycle irradiation time is " << irradStartTime023 << endl;
    counter023++;
  }


  // For TCN17025
  for (ULong64_t j = 0 ; j < event025 ; j++){
    outputTree025-> GetEvent(j);
    HistIntegralArray025[counter025] = HistIntegral025;
    HistIntegralErrArray025[counter025] = sqrt (HistIntegreal025);
    UCNCounts025[counter025] = HistIntegral025 - BASELINERATE025*(cycleValveCloseTime025 - cycleValveOpenTime025);
    UCNCountsErr025[counter025] = sqrt (UCNCounts025[counter025]);
    avets12VOArray025[counter025] = avets12VO025;
    ts12VOErrArray025[counter025] = (maxts12VO025 - mints12VO025)/2;
    avecurArray025[counter025] = avecur025;
    avecurErrArray025[counter025] = (maxcur025 - mincur025)/2;
    cout << "Cycle irradiation time is " << irradStartTime025 << endl;
    counter025++;
  }

  // For TCN17026
  for (ULong64_t j = 0 ; j < event026 ; j++){
    outputTree026-> GetEvent(j);
    HistIntegralArray026[counter026] = HistIntegral026;
    HistIntegralErrArray026[counter026] = sqrt (HistIntegreal026);
    UCNCounts026[counter026] = HistIntegral026 - BASELINERATE026*(cycleValveCloseTime026 - cycleValveOpenTime026);
    UCNCountsErr026[counter026] = sqrt (UCNCounts026[counter026]);
    avets12VOArray026[counter026] = avets12VO026;
    ts12VOErrArray026[counter026] = (maxts12VO026 - mints12VO026)/2;
    avecurArray026[counter026] = avecur026;
    avecurErrArray026[counter026] = (maxcur026 - mincur026)/2;
    cout << "Cycle irradiation time is " << irradStartTime026 << endl;
    counter026++;
  }

  // For TCN17029
  for (ULong64_t j = 0 ; j < event029 ; j++){
    outputTree029-> GetEvent(j);
    HistIntegralArray029[counter029] = HistIntegral029;
    HistIntegralErrArray029[counter029] = sqrt (HistIntegreal029);
    UCNCounts029[counter029] = HistIntegral029 - BASELINERATE029*(cycleValveCloseTime029 - cycleValveOpenTime029);
    UCNCountsErr029[counter029] = sqrt (UCNCounts029[counter029]);
    avets12VOArray029[counter029] = avets12VO029;
    ts12VOErrArray029[counter029] = (maxts12VO029 - mints12VO029)/2;
    avecurArray029[counter029] = avecur029;
    avecurErrArray029[counter029] = (maxcur029 - mincur029)/2;
    cout << "Cycle irradiation time is " << irradStartTime029 << endl;
    counter029++;
  }
  

  // For TCN17029A
  for (ULong64_t j = 0 ; j < event029A ; j++){
    outputTree029A-> GetEvent(j);
    HistIntegralArray029A[counter029A] = HistIntegral029A;
    HistIntegralErrArray029A[counter029A] = sqrt (HistIntegreal029A);
    UCNCounts029A[counter029A] = HistIntegral029A - BASELINERATE029A*(cycleValveCloseTime029A - cycleValveOpenTime029A);
    UCNCountsErr029A[counter029A] = sqrt (UCNCounts029A[counter029A]);
    avets12VOArray029A[counter029A] = avets12VO029A;
    ts12VOErrArray029A[counter029A] = (maxts12VO029A - mints12VO029A)/2;
    avecurArray029A[counter029A] = avecur029A;
    avecurErrArray029A[counter029A] = (maxcur029A - mincur029A)/2;
    cout << "Cycle irradiation time is " << irradStartTime029A << endl;
    counter029A++;
  }

  // For TCN17031
  for (ULong64_t j = 0 ; j < event031 ; j++){
    outputTree031-> GetEvent(j);
    HistIntegralArray031[counter031] = HistIntegral031;
    HistIntegralErrArray031[counter031] = sqrt (HistIntegreal031);
    UCNCounts031[counter031] = HistIntegral031 - BASELINERATE031*(cycleValveCloseTime031 - cycleValveOpenTime031);
    UCNCountsErr031[counter031] = sqrt (UCNCounts031[counter031]);
    avets12VOArray031[counter031] = avets12VO031;
    ts12VOErrArray031[counter031] = (maxts12VO031 - mints12VO031)/2;
    avecurArray031[counter031] = avecur031;
    avecurErrArray031[counter031] = (maxcur031 - mincur031)/2;
    cout << "Cycle irradiation time is " << irradStartTime031 << endl;
    counter031++;
  }

  // For run 780
  for (ULong64_t j = 0 ; j < event780 ; j++){
    outputTree780-> GetEvent(j);
    HistIntegralArray780[counter780] = HistIntegral780;
    HistIntegralErrArray780[counter780] = sqrt (HistIntegreal780);
    UCNCounts780[counter780] = HistIntegral780 - BASELINERATE780*(cycleValveCloseTime780 - cycleValveOpenTime780);
    UCNCountsErr780[counter780] = sqrt (UCNCounts780[counter780]);
    avets12VOArray780[counter780] = avets12VO780;
    ts12VOErrArray780[counter780] = (maxts12VO780 - mints12VO780)/2;
    avecurArray780[counter780] = avecur780;
    avecurErrArray780[counter780] = (maxcur780 - mincur780)/2;
    cout << "Cycle irradiation time is " << irradStartTime780 << endl;
    counter780++;
  }



    
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 120);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(20000,30);
  fit1exp -> SetParLimits(0, 10000, 190000);
  fit1exp -> SetParLimits(1, 10, 45);
  

  // ******************************************************************
  // TCN17002
  // ******************************************************************
  TCanvas *c002 = new TCanvas("c002", "c002", 1200 ,900);
  c002 -> SetLogy();
  
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr002_1 = new TGraphErrors(counter002, cycleDelayTime002, UCNCounts002, 0 , UCNCountsErr002);

  gr002_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr002_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr002_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr002_1 -> SetMarkerStyle(20);
  // gr002_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr002_1 -> GetXaxis()-> SetLimits(0, 160);
  gr002_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr002_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr002_1 -> SetMarkerColor(1);

  // ---------------------
  // UP TO HERE
  // ------------------------
  
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
  storagefit002_1expfit =fit1exp->GetParameter(1);
  storageErrfit002_1expfit =fit1exp->GetParError(1);
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
