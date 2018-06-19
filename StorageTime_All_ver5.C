// ************************************************************
// This script is to analyze all the standard storage lifetime
// measurements.
// Taraneh Andalib, June 15, 2018
// *************************************************************

#define max 200

void StorageTime_All_ver5(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");

  // OPENING ALL THE FILES
  TFile *fin002 = new TFile("./2ndpass/outputTree_17002.root","READ");
  TFile *fin003 = new TFile("./2ndpass/outputTree_17003.root","READ");
  TFile *fin004A = new TFile("./2ndpass/outputTree_17004A.root","READ");
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
  TFile *fin029A = new TFile("./2ndpass/outputTree_17029A.root","READ");
  TFile *fin031 = new TFile("./2ndpass/outputTree_17031.root","READ");
  TFile *fin780 = new TFile("./2ndpass/outputTree_780.root","READ");



  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree002 = (TTree*) fin002->Get("cycle_info");
  TTree *outputTree003 = (TTree*) fin003->Get("cycle_info");
  TTree *outputTree004A = (TTree*) fin004A->Get("cycle_info");
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

  // cycle number

  int cycleNumber002;
  outputTree002 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber002);
  int cycleNumber003;
  outputTree003 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber003);
  int cycleNumber004A;
  outputTree004A -> SetBranchAddress ("cycleNumberAll" , &cycleNumber004A);
  int cycleNumber006;
  outputTree006 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber006);
  int cycleNumber006A;
  outputTree006A -> SetBranchAddress ("cycleNumberAll" , &cycleNumber006A);
  int cycleNumber012;
  outputTree012 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber012);
  int cycleNumber013;
  outputTree013 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber013);
  int cycleNumber016;
  outputTree016 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber016);
  int cycleNumber021;
  outputTree021 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber021);
  int cycleNumber023;
  outputTree023 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber023);
  int cycleNumber025;
  outputTree025 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber025);
  int cycleNumber026;
  outputTree026 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber026);
  int cycleNumber029;
  outputTree029 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber029);
  int cycleNumber029A;
  outputTree029A -> SetBranchAddress ("cycleNumberAll" , &cycleNumber029A);
  int cycleNumber031;
  outputTree031 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber031);
  int cycleNumber780;
  outputTree780 -> SetBranchAddress ("cycleNumberAll" , &cycleNumber780);
  
  double cycleNumberArray002[max];
  double cycleNumberArray003[max];
  double cycleNumberArray004A[max];
  double cycleNumberArray006[max];
  double cycleNumberArray006A[max];
  double cycleNumberArray012[max];
  double cycleNumberArray013[max];
  double cycleNumberArray016[max];
  double cycleNumberArray021[max];
  double cycleNumberArray023[max];
  double cycleNumberArray025[max];
  double cycleNumberArray026[max];
  double cycleNumberArray029[max];
  double cycleNumberArray029A[max];
  double cycleNumberArray031[max];
  double cycleNumberArray780[max];

  
  // CYCLE DELAY TIME FOR EACH FILE
  double cycleDelayTime002;
  outputTree002 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime002);
  double cycleDelayTime003;
  outputTree003 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime003);
  double cycleDelayTime004A;
  outputTree004A -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime004A);
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
  double cycleDelayTimeArray004A[max];
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
  double HistIntegral004A;
  outputTree004A -> SetBranchAddress ("HistIntegral" , &HistIntegral004A);
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
  double HistIntegralArray004A[max];
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
  double HistIntegralErrArray004A[max];
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
  double avets12VO004A;
  outputTree004A -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12VO004A);
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
  double avets12VOArray004A[max];
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
  double ts12VOErrArray004A[max];
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
  double maxts12VO004A;
  outputTree004A -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12VO004A);
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
  double mints12VO004A;
  outputTree004A -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12VO004A);
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
  double BASELINERATE004A;
  outputTree004A -> SetBranchAddress ("BASELINERATE" , &BASELINERATE004A);
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
  double irradStartTimes004A;
  outputTree004A -> SetBranchAddress ("irradStartTimes" , &irradStartTimes004A);
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
  double cycleStartTimes004A;
  outputTree004A -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes004A);
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
  double avecur004A;
  outputTree004A -> SetBranchAddress ("AVE_PRDCUR" , &avecur004A);
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
  double avecurArray004A[max];
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
  double avecurErrArray004A[max];
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
  double maxcur004A;
  outputTree004A -> SetBranchAddress ("MAX_PRDCUR" , &maxcur004A);
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
  double mincur004A;
  outputTree004A -> SetBranchAddress ("MIN_PRDCUR" , &mincur004A);
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
  double cycleValveOpenTime004A;
  outputTree004A -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime004A);
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
  double cycleValveCloseTime004A;
  outputTree004A -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime004A);
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
  double storagelifetime004A;
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
  double fitErr004A;
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
  int counter004A;
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
  double UCNCounts004A[max];
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
  double UCNCountsErr004A[max];
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

  // GET THE EVENTS FOR TCN17004A
  ULong64_t event004A;
  event004A = (Double_t)outputTree004A->GetEntries();
  
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
    if (j == 16 || j == 26)
      continue; // there are 0 current
    cycleNumberArray002[counter002] = cycleNumber002;
    cycleDelayTimeArray002[counter002] = cycleDelayTime002;
    HistIntegralArray002[counter002] = HistIntegral002;
    HistIntegralErrArray002[counter002] = sqrt (HistIntegral002);
    UCNCounts002[counter002] = HistIntegral002 - BASELINERATE002*(cycleValveCloseTime002 - cycleValveOpenTime002);
    UCNCountsErr002[counter002] = sqrt (UCNCounts002[counter002]);
    avets12VOArray002[counter002] = avets12VO002;
    ts12VOErrArray002[counter002] = (maxts12VO002 - mints12VO002)/2;
    avecurArray002[counter002] = avecur002;
    avecurErrArray002[counter002] = (maxcur002 - mincur002)/2;
    cout << "Cycle irradiation time is " << cycleStartTimes002 - irradStartTimes002 << endl;
    counter002++;
  }


  // For TCN17003
  for (ULong64_t j = 0 ; j < event003 ; j++){
    outputTree003-> GetEvent(j);
    if (j==2)
      continue;
    cycleNumberArray003[counter003] = cycleNumber003;
    cycleDelayTimeArray003[counter003] = cycleDelayTime003;
    HistIntegralArray003[counter003] = HistIntegral003;
    HistIntegralErrArray003[counter003] = sqrt (HistIntegral003);
    UCNCounts003[counter003] = HistIntegral003 - BASELINERATE003*(cycleValveCloseTime003 - cycleValveOpenTime003);
    UCNCountsErr003[counter003] = sqrt (UCNCounts003[counter003]);
    avets12VOArray003[counter003] = avets12VO003;
    ts12VOErrArray003[counter003] = (maxts12VO003 - mints12VO003)/2;
    avecurArray003[counter003] = avecur003;
    avecurErrArray003[counter003] = (maxcur003 - mincur003)/2;
    cout << "Cycle irradiation time is " << irradStartTimes003 << endl;
    counter003++;
  }

  // For TCN17004A
  for (ULong64_t j = 0 ; j < event004A ; j++){
    outputTree004A-> GetEvent(j);
    if (j == 8)
      continue;
    cycleNumberArray004A[counter004A] = cycleNumber004A;
    cycleDelayTimeArray004A[counter004A] = cycleDelayTime004A;
    HistIntegralArray004A[counter004A] = HistIntegral004A;
    HistIntegralErrArray004A[counter004A] = sqrt (HistIntegral004A);
    UCNCounts004A[counter004A] = HistIntegral004A - BASELINERATE004A*(cycleValveCloseTime004A - cycleValveOpenTime004A);
    UCNCountsErr004A[counter004A] = sqrt (UCNCounts004A[counter004A]);
    avets12VOArray004A[counter004A] = avets12VO004A;
    ts12VOErrArray004A[counter004A] = (maxts12VO004A - mints12VO004A)/2;
    avecurArray004A[counter004A] = avecur004A;
    avecurErrArray004A[counter004A] = (maxcur004A - mincur004A)/2;
    cout << "Cycle irradiation time is " << irradStartTimes004A << endl;
    counter004A++;
  }

  
  
  // For TCN17006
  for (ULong64_t j = 0 ; j < event006 ; j++){
    outputTree006-> GetEvent(j);
    if (j == 3 || j ==4 || j ==5 || j == 6 || j==7 || j == 18)
      continue;
    cycleNumberArray006[counter006] = cycleNumber006;
    cycleDelayTimeArray006[counter006] = cycleDelayTime006;
    HistIntegralArray006[counter006] = HistIntegral006;
    HistIntegralErrArray006[counter006] = sqrt (HistIntegral006);
    UCNCounts006[counter006] = HistIntegral006 - BASELINERATE006*(cycleValveCloseTime006 - cycleValveOpenTime006);
    UCNCountsErr006[counter006] = sqrt (UCNCounts006[counter006]);
    avets12VOArray006[counter006] = avets12VO006;
    ts12VOErrArray006[counter006] = (maxts12VO006 - mints12VO006)/2;
    avecurArray006[counter006] = avecur006;
    avecurErrArray006[counter006] = (maxcur006 - mincur006)/2;
    cout << "Cycle irradiation time is " << irradStartTimes006 << endl;
    counter006++;
  }

  // For TCN17006A
  for (ULong64_t j = 0 ; j < event006A ; j++){
    outputTree006A-> GetEvent(j);
    cycleNumberArray006A [counter006A] = cycleNumber006A;
    cycleDelayTimeArray006A[counter006A] = cycleDelayTime006A;
    HistIntegralArray006A[counter006A] = HistIntegral006A;
    HistIntegralErrArray006A[counter006A] = sqrt (HistIntegral006A);
    UCNCounts006A[counter006A] = HistIntegral006A - BASELINERATE006A*(cycleValveCloseTime006A - cycleValveOpenTime006A);
    UCNCountsErr006A[counter006A] = sqrt (UCNCounts006A[counter006A]);
    avets12VOArray006A[counter006A] = avets12VO006A;
    ts12VOErrArray006A[counter006A] = (maxts12VO006A - mints12VO006A)/2;
    avecurArray006A[counter006A] = avecur006A;
    avecurErrArray006A[counter006A] = (maxcur006A - mincur006A)/2;
    cout << "Cycle irradiation time is " << irradStartTimes006A << endl;
    counter006A++;
  }

  // For TCN17012
  for (ULong64_t j = 0 ; j < event012 ; j++){
    outputTree012-> GetEvent(j);
    if (j==9)
      continue;
    cycleNumberArray012[counter012] = cycleNumber012;
    cycleDelayTimeArray012[counter012] = cycleDelayTime012;
    HistIntegralArray012[counter012] = HistIntegral012;
    HistIntegralErrArray012[counter012] = sqrt (HistIntegral012);
    UCNCounts012[counter012] = HistIntegral012 - BASELINERATE012*(cycleValveCloseTime012 - cycleValveOpenTime012);
    UCNCountsErr012[counter012] = sqrt (UCNCounts012[counter012]);
    avets12VOArray012[counter012] = avets12VO012;
    ts12VOErrArray012[counter012] = (maxts12VO012 - mints12VO012)/2;
    avecurArray012[counter012] = avecur012;
    avecurErrArray012[counter012] = (maxcur012 - mincur012)/2;
    cout << "Cycle irradiation time is " << irradStartTimes012 << endl;
    counter012++;
  }


  // For TCN17013
  for (ULong64_t j = 0 ; j < event013 ; j++){
    outputTree013-> GetEvent(j);
    cycleNumberArray013[counter013] = cycleNumber013;
    cycleDelayTimeArray013[counter013] = cycleDelayTime013;
    HistIntegralArray013[counter013] = HistIntegral013;
    HistIntegralErrArray013[counter013] = sqrt (HistIntegral013);
    UCNCounts013[counter013] = HistIntegral013 - BASELINERATE013*(cycleValveCloseTime013 - cycleValveOpenTime013);
    UCNCountsErr013[counter013] = sqrt (UCNCounts013[counter013]);
    avets12VOArray013[counter013] = avets12VO013;
    ts12VOErrArray013[counter013] = (maxts12VO013 - mints12VO013)/2;
    avecurArray013[counter013] = avecur013;
    avecurErrArray013[counter013] = (maxcur013 - mincur013)/2;
    cout << "Cycle irradiation time is " << irradStartTimes013 << endl;
    counter013++;
  }

  // For TCN17016
  for (ULong64_t j = 0 ; j < event016 ; j++){
    outputTree016-> GetEvent(j);
    if ( j==1 || j ==2 || j == 9 || j==10 || j ==11)
      continue;
    cycleNumberArray016[counter016] = cycleNumber016;
    cycleDelayTimeArray016[counter016] = cycleDelayTime016;
    HistIntegralArray016[counter016] = HistIntegral016;
    HistIntegralErrArray016[counter016] = sqrt (HistIntegral016);
    UCNCounts016[counter016] = HistIntegral016 - BASELINERATE016*(cycleValveCloseTime016 - cycleValveOpenTime016);
    UCNCountsErr016[counter016] = sqrt (UCNCounts016[counter016]);
    avets12VOArray016[counter016] = avets12VO016;
    ts12VOErrArray016[counter016] = (maxts12VO016 - mints12VO016)/2;
    avecurArray016[counter016] = avecur016;
    avecurErrArray016[counter016] = (maxcur016 - mincur016)/2;
    cout << "Cycle irradiation time is " << irradStartTimes016 << endl;
    counter016++;
  }

  // For TCN17021
  for (ULong64_t j = 0 ; j < event021 ; j++){
    outputTree021-> GetEvent(j);
    cycleNumberArray021[counter021] = cycleNumber021;
    cycleDelayTimeArray021[counter021] = cycleDelayTime021;
    HistIntegralArray021[counter021] = HistIntegral021;
    HistIntegralErrArray021[counter021] = sqrt (HistIntegral021);
    UCNCounts021[counter021] = HistIntegral021 - BASELINERATE021*(cycleValveCloseTime021 - cycleValveOpenTime021);
    UCNCountsErr021[counter021] = sqrt (UCNCounts021[counter021]);
    avets12VOArray021[counter021] = avets12VO021;
    ts12VOErrArray021[counter021] = (maxts12VO021 - mints12VO021)/2;
    avecurArray021[counter021] = avecur021;
    avecurErrArray021[counter021] = (maxcur021 - mincur021)/2;
    cout << "Cycle irradiation time is " << irradStartTimes021 << endl;
    counter021++;
  }

  // For TCN17023
  for (ULong64_t j = 0 ; j < event023 ; j++){
    outputTree023-> GetEvent(j);
    if (j==8)
      continue;
    cycleNumberArray023[counter023] = cycleNumber023;
    cycleDelayTimeArray023[counter023] = cycleDelayTime023;
    HistIntegralArray023[counter023] = HistIntegral023;
    HistIntegralErrArray023[counter023] = sqrt (HistIntegral023);
    UCNCounts023[counter023] = HistIntegral023 - BASELINERATE023*(cycleValveCloseTime023 - cycleValveOpenTime023);
    UCNCountsErr023[counter023] = sqrt (UCNCounts023[counter023]);
    avets12VOArray023[counter023] = avets12VO023;
    ts12VOErrArray023[counter023] = (maxts12VO023 - mints12VO023)/2;
    avecurArray023[counter023] = avecur023;
    avecurErrArray023[counter023] = (maxcur023 - mincur023)/2;
    cout << "Cycle irradiation time is " << irradStartTimes023 << endl;
    counter023++;
  }


  // For TCN17025
  for (ULong64_t j = 0 ; j < event025 ; j++){
    outputTree025-> GetEvent(j);
    cycleNumberArray025[counter025] = cycleNumber025;
    cycleDelayTimeArray025[counter025] = cycleDelayTime025;
    HistIntegralArray025[counter025] = HistIntegral025;
    HistIntegralErrArray025[counter025] = sqrt (HistIntegral025);
    UCNCounts025[counter025] = HistIntegral025 - BASELINERATE025*(cycleValveCloseTime025 - cycleValveOpenTime025);
    UCNCountsErr025[counter025] = sqrt (UCNCounts025[counter025]);
    avets12VOArray025[counter025] = avets12VO025;
    ts12VOErrArray025[counter025] = (maxts12VO025 - mints12VO025)/2;
    avecurArray025[counter025] = avecur025;
    avecurErrArray025[counter025] = (maxcur025 - mincur025)/2;
    cout << "Cycle irradiation time is " << irradStartTimes025 << endl;
    counter025++;
  }

  // For TCN17026
  for (ULong64_t j = 0 ; j < event026 ; j++){
    outputTree026-> GetEvent(j);
    cycleNumberArray026[counter026] = cycleNumber026;
    cycleDelayTimeArray026[counter026] = cycleDelayTime026;
    HistIntegralArray026[counter026] = HistIntegral026;
    HistIntegralErrArray026[counter026] = sqrt (HistIntegral026);
    UCNCounts026[counter026] = HistIntegral026 - BASELINERATE026*(cycleValveCloseTime026 - cycleValveOpenTime026);
    UCNCountsErr026[counter026] = sqrt (UCNCounts026[counter026]);
    avets12VOArray026[counter026] = avets12VO026;
    ts12VOErrArray026[counter026] = (maxts12VO026 - mints12VO026)/2;
    avecurArray026[counter026] = avecur026;
    avecurErrArray026[counter026] = (maxcur026 - mincur026)/2;
    cout << "Cycle irradiation time is " << irradStartTimes026 << endl;
    counter026++;
  }

  // For TCN17029
  for (ULong64_t j = 0 ; j < event029 ; j++){
    outputTree029-> GetEvent(j);
    cycleNumberArray029[counter029] = cycleNumber029;
    cycleDelayTimeArray029[counter029] = cycleDelayTime029;
    HistIntegralArray029[counter029] = HistIntegral029;
    HistIntegralErrArray029[counter029] = sqrt (HistIntegral029);
    UCNCounts029[counter029] = HistIntegral029 - BASELINERATE029*(cycleValveCloseTime029 - cycleValveOpenTime029);
    UCNCountsErr029[counter029] = sqrt (UCNCounts029[counter029]);
    avets12VOArray029[counter029] = avets12VO029;
    ts12VOErrArray029[counter029] = (maxts12VO029 - mints12VO029)/2;
    avecurArray029[counter029] = avecur029;
    avecurErrArray029[counter029] = (maxcur029 - mincur029)/2;
    cout << "Cycle irradiation time is " << irradStartTimes029 << endl;
    counter029++;
  }
  

  // For TCN17029A
  for (ULong64_t j = 0 ; j < event029A ; j++){
    outputTree029A-> GetEvent(j);
    if (j==8)
      continue;
    cycleNumberArray029A[counter029A] = cycleNumber029A;
    cycleDelayTimeArray029A[counter029A] = cycleDelayTime029A;
    HistIntegralArray029A[counter029A] = HistIntegral029A;
    HistIntegralErrArray029A[counter029A] = sqrt (HistIntegral029A);
    UCNCounts029A[counter029A] = HistIntegral029A - BASELINERATE029A*(cycleValveCloseTime029A - cycleValveOpenTime029A);
    UCNCountsErr029A[counter029A] = sqrt (UCNCounts029A[counter029A]);
    avets12VOArray029A[counter029A] = avets12VO029A;
    ts12VOErrArray029A[counter029A] = (maxts12VO029A - mints12VO029A)/2;
    avecurArray029A[counter029A] = avecur029A;
    avecurErrArray029A[counter029A] = (maxcur029A - mincur029A)/2;
    cout << "Cycle irradiation time is " << irradStartTimes029A << endl;
    counter029A++;
  }

  // For TCN17031
  for (ULong64_t j = 0 ; j < event031 ; j++){
    outputTree031-> GetEvent(j);
    if (j==8)
      continue;
    cycleNumberArray031[counter031] = cycleNumber031;
    cycleDelayTimeArray031[counter031] = cycleDelayTime031;
    HistIntegralArray031[counter031] = HistIntegral031;
    HistIntegralErrArray031[counter031] = sqrt (HistIntegral031);
    UCNCounts031[counter031] = HistIntegral031 - BASELINERATE031*(cycleValveCloseTime031 - cycleValveOpenTime031);
    UCNCountsErr031[counter031] = sqrt (UCNCounts031[counter031]);
    avets12VOArray031[counter031] = avets12VO031;
    ts12VOErrArray031[counter031] = (maxts12VO031 - mints12VO031)/2;
    avecurArray031[counter031] = avecur031;
    avecurErrArray031[counter031] = (maxcur031 - mincur031)/2;
    cout << "Cycle irradiation time is " << irradStartTimes031 << endl;
    counter031++;
  }

  // For run 780
  for (ULong64_t j = 0 ; j < event780 ; j++){
    outputTree780-> GetEvent(j);
    if (j==3 || j ==4 || j == 9)
      continue;
    cycleNumberArray780[counter780] = cycleNumber780;
    cycleDelayTimeArray780[counter780] = cycleDelayTime780;
    HistIntegralArray780[counter780] = HistIntegral780;
    HistIntegralErrArray780[counter780] = sqrt (HistIntegral780);
    UCNCounts780[counter780] = HistIntegral780 - BASELINERATE780*(cycleValveCloseTime780 - cycleValveOpenTime780);
    UCNCountsErr780[counter780] = sqrt (UCNCounts780[counter780]);
    avets12VOArray780[counter780] = avets12VO780;
    ts12VOErrArray780[counter780] = (maxts12VO780 - mints12VO780)/2;
    avecurArray780[counter780] = avecur780;
    avecurErrArray780[counter780] = (maxcur780 - mincur780)/2;
    cout << "Cycle irradiation time is " << cycleStartTimes780 - irradStartTimes780 << endl;
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
  

  TGraphErrors *gr002_1 = new TGraphErrors(counter002, cycleDelayTimeArray002, UCNCounts002, 0 , UCNCountsErr002);

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

  gr002_1 -> Draw("ap");
  gr002_1 -> Fit(fit1exp);
  storagelifetime002 = fit1exp -> GetParameter(1);
  fitErr002 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c002_cycleNum = new TCanvas("c002_cycleNum" , "c002_cycleNum" , 1200, 800);
  c002_cycleNum -> Divide(2,2);
  TPad *p002 = c002_cycleNum->cd(1);
  p002->SetLogy();
  TGraphErrors *gr002_cyclecounts = new TGraphErrors (counter002 , cycleNumberArray002, UCNCounts002, 0 , UCNCountsErr002);
  gr002_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr002_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr002_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr002_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr002_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr002_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr002_cyclecounts -> SetMarkerStyle(20);
  gr002_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr002_cyclehist = new TGraphErrors(counter002, cycleNumberArray002 , HistIntegralArray002, 0, HistIntegralErrArray002);

  gr002_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr002_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr002_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr002_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr002_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr002_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr002_cyclehist -> SetMarkerColor(1);
  gr002_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr002_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr002_cyclehist, "UCN counts with background" , "P");
  
  gr002_cyclecounts -> Draw("Ap");
  gr002_cyclehist -> Draw("p");
  leg2-> Draw();

  c002_cycleNum -> cd(2);
  TGraphErrors *gr002_cycledelay = new TGraphErrors (counter002 , cycleNumberArray002, cycleDelayTimeArray002, 0 , 0);
  gr002_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr002_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr002_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr002_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr002_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr002_cycledelay -> SetMarkerStyle(20);
  gr002_cycledelay -> Draw("Ap");


  c002_cycleNum -> cd(3);
  TGraphErrors *gr002_cycletempVO = new TGraphErrors (counter002 , cycleNumberArray002, avets12VOArray002, 0 , ts12VOErrArray002);

  gr002_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr002_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr002_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr002_cycletempVO -> SetMarkerStyle(20);
  // gr002_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr002_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr002_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr002_cycletempVO -> Draw("AP");


  c002_cycleNum -> cd(4);
  TGraphErrors *gr002_cyclecur = new TGraphErrors (counter002 , cycleNumberArray002 , avecurArray002, 0, avecurErrArray002 );
  gr002_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr002_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr002_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr002_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr002_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr002_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr002_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr002_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr002_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr002_cyclecur -> SetMarkerStyle(20);
  gr002_cyclecur -> Draw("Ap");



  //*************************************************************************************************
  // *****************************************
  // TCN17003
  // ****************************************
  TCanvas *c003 = new TCanvas("c003", "c003", 1200 ,900);
  c003 -> SetLogy();
  

  TGraphErrors *gr003_1 = new TGraphErrors(counter003, cycleDelayTimeArray003, UCNCounts003, 0 , UCNCountsErr003);

  gr003_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr003_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr003_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr003_1 -> SetMarkerStyle(20);
  // gr003_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr003_1 -> GetXaxis()-> SetLimits(0, 160);
  gr003_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr003_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr003_1 -> SetMarkerColor(1);

  gr003_1 -> Draw("ap");
  gr003_1 -> Fit(fit1exp);
  storagelifetime003 = fit1exp -> GetParameter(1);
  fitErr003 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c003_cycleNum = new TCanvas("c003_cycleNum" , "c003_cycleNum" , 1200, 800);
  c003_cycleNum -> Divide(2,2);
  TPad *p003 = c003_cycleNum->cd(1);
  p003->SetLogy();
  TGraphErrors *gr003_cyclecounts = new TGraphErrors (counter003 , cycleNumberArray003, UCNCounts003, 0 , UCNCountsErr003);
  gr003_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr003_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr003_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr003_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr003_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr003_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr003_cyclecounts -> SetMarkerStyle(20);
  gr003_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr003_cyclehist = new TGraphErrors(counter003, cycleNumberArray003 , HistIntegralArray003, 0, HistIntegralErrArray003);

  gr003_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr003_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr003_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr003_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr003_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr003_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr003_cyclehist -> SetMarkerColor(1);
  gr003_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr003_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr003_cyclehist, "UCN counts with background" , "P");
  
  gr003_cyclecounts -> Draw("Ap");
  gr003_cyclehist -> Draw("p");
  leg2-> Draw();

  c003_cycleNum -> cd(2);
  TGraphErrors *gr003_cycledelay = new TGraphErrors (counter003 , cycleNumberArray003, cycleDelayTimeArray003, 0 , 0);
  gr003_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr003_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr003_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr003_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr003_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr003_cycledelay -> SetMarkerStyle(20);
  gr003_cycledelay -> Draw("Ap");


  c003_cycleNum -> cd(3);
  TGraphErrors *gr003_cycletempVO = new TGraphErrors (counter003 , cycleNumberArray003, avets12VOArray003, 0 , ts12VOErrArray003);

  gr003_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr003_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr003_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr003_cycletempVO -> SetMarkerStyle(20);
  // gr003_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr003_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr003_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr003_cycletempVO -> Draw("AP");


  c003_cycleNum -> cd(4);
  TGraphErrors *gr003_cyclecur = new TGraphErrors (counter003 , cycleNumberArray003 , avecurArray003, 0, avecurErrArray003 );
  gr003_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr003_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr003_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr003_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr003_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr003_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr003_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr003_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr003_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr003_cyclecur -> SetMarkerStyle(20);
  gr003_cyclecur -> Draw("Ap");


  //*************************************************************************************************
  // *****************************************
  // TCN17004A
  // ****************************************
  TCanvas *c004A = new TCanvas("c004A", "c004A", 1200 ,900);
  c004A -> SetLogy();
  

  TGraphErrors *gr004A_1 = new TGraphErrors(counter004A, cycleDelayTimeArray004A, UCNCounts004A, 0 , UCNCountsErr004A);

  gr004A_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr004A_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr004A_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr004A_1 -> SetMarkerStyle(20);
  // gr004A_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr004A_1 -> GetXaxis()-> SetLimits(0, 160);
  gr004A_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr004A_1 -> SetMarkerColor(1);

  gr004A_1 -> Draw("ap");
  gr004A_1 -> Fit(fit1exp);
  storagelifetime004A = fit1exp -> GetParameter(1);
  fitErr004A = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c004A_cycleNum = new TCanvas("c004A_cycleNum" , "c004A_cycleNum" , 1200, 800);
  c004A_cycleNum -> Divide(2,2);
  TPad *p004A = c004A_cycleNum->cd(1);
  p004A->SetLogy();
  TGraphErrors *gr004A_cyclecounts = new TGraphErrors (counter004A , cycleNumberArray004A, UCNCounts004A, 0 , UCNCountsErr004A);
  gr004A_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr004A_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr004A_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr004A_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr004A_cyclecounts -> SetMarkerStyle(20);
  gr004A_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr004A_cyclehist = new TGraphErrors(counter004A, cycleNumberArray004A , HistIntegralArray004A, 0, HistIntegralErrArray004A);

  gr004A_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr004A_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr004A_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr004A_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr004A_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr004A_cyclehist -> SetMarkerColor(1);
  gr004A_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr004A_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr004A_cyclehist, "UCN counts with background" , "P");
  
  gr004A_cyclecounts -> Draw("Ap");
  gr004A_cyclehist -> Draw("p");
  leg2-> Draw();

  c004A_cycleNum -> cd(2);
  TGraphErrors *gr004A_cycledelay = new TGraphErrors (counter004A , cycleNumberArray004A, cycleDelayTimeArray004A, 0 , 0);
  gr004A_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr004A_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr004A_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr004A_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr004A_cycledelay -> SetMarkerStyle(20);
  gr004A_cycledelay -> Draw("Ap");


  c004A_cycleNum -> cd(3);
  TGraphErrors *gr004A_cycletempVO = new TGraphErrors (counter004A , cycleNumberArray004A, avets12VOArray004A, 0 , ts12VOErrArray004A);

  gr004A_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr004A_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr004A_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr004A_cycletempVO -> SetMarkerStyle(20);
  // gr004A_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr004A_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr004A_cycletempVO -> Draw("AP");


  c004A_cycleNum -> cd(4);
  TGraphErrors *gr004A_cyclecur = new TGraphErrors (counter004A , cycleNumberArray004A , avecurArray004A, 0, avecurErrArray004A );
  gr004A_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr004A_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr004A_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr004A_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr004A_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr004A_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr004A_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr004A_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr004A_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr004A_cyclecur -> SetMarkerStyle(20);
  gr004A_cyclecur -> Draw("Ap");


  
 
  // ******************************************************************
  // TCN17006
  // ******************************************************************

  TCanvas *c006 = new TCanvas("c006", "c006", 1200 ,900);
  c006 -> SetLogy();
  

  TGraphErrors *gr006_1 = new TGraphErrors(counter006, cycleDelayTimeArray006, UCNCounts006, 0 , UCNCountsErr006);

  gr006_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr006_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr006_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr006_1 -> SetMarkerStyle(20);
  // gr006_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr006_1 -> GetXaxis()-> SetLimits(0, 160);
  gr006_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr006_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr006_1 -> SetMarkerColor(1);

  gr006_1 -> Draw("ap");
  gr006_1 -> Fit(fit1exp);
  storagelifetime006 = fit1exp -> GetParameter(1);
  fitErr006 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c006_cycleNum = new TCanvas("c006_cycleNum" , "c006_cycleNum" , 1200, 800);
  c006_cycleNum -> Divide(2,2);
  TPad *p006 = c006_cycleNum->cd(1);
  p006->SetLogy();
  TGraphErrors *gr006_cyclecounts = new TGraphErrors (counter006 , cycleNumberArray006, UCNCounts006, 0 , UCNCountsErr006);
  gr006_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr006_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr006_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr006_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr006_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr006_cyclecounts -> SetMarkerStyle(20);
  gr006_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr006_cyclehist = new TGraphErrors(counter006, cycleNumberArray006 , HistIntegralArray006, 0, HistIntegralErrArray006);

  gr006_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr006_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr006_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr006_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr006_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr006_cyclehist -> SetMarkerColor(1);
  gr006_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr006_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr006_cyclehist, "UCN counts with background" , "P");
  
  gr006_cyclecounts -> Draw("Ap");
  gr006_cyclehist -> Draw("p");
  leg2-> Draw();

  c006_cycleNum -> cd(2);
  TGraphErrors *gr006_cycledelay = new TGraphErrors (counter006 , cycleNumberArray006, cycleDelayTimeArray006, 0 , 0);
  gr006_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr006_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr006_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr006_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr006_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr006_cycledelay -> SetMarkerStyle(20);
  gr006_cycledelay -> Draw("Ap");


  c006_cycleNum -> cd(3);
  TGraphErrors *gr006_cycletempVO = new TGraphErrors (counter006 , cycleNumberArray006, avets12VOArray006, 0 , ts12VOErrArray006);

  gr006_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr006_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr006_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr006_cycletempVO -> SetMarkerStyle(20);
  // gr006_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr006_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr006_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr006_cycletempVO -> Draw("AP");


  c006_cycleNum -> cd(4);
  TGraphErrors *gr006_cyclecur = new TGraphErrors (counter006 , cycleNumberArray006 , avecurArray006, 0, avecurErrArray006 );
  gr006_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr006_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr006_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr006_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr006_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr006_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr006_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr006_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr006_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr006_cyclecur -> SetMarkerStyle(20);
  gr006_cyclecur -> Draw("Ap");


  // ******************************************************************
  // TCN17006A
  // ******************************************************************
  TCanvas *c006A = new TCanvas("c006A", "c006A", 1200 ,900);
  c006A -> SetLogy();
  

  TGraphErrors *gr006A_1 = new TGraphErrors(counter006A, cycleDelayTimeArray006A, UCNCounts006A, 0 , UCNCountsErr006A);

  gr006A_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr006A_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr006A_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr006A_1 -> SetMarkerStyle(20);
  // gr006A_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr006A_1 -> GetXaxis()-> SetLimits(0, 160);
  gr006A_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr006A_1 -> SetMarkerColor(1);

  gr006A_1 -> Draw("ap");
  gr006A_1 -> Fit(fit1exp);
  storagelifetime006A = fit1exp -> GetParameter(1);
  fitErr006A = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c006A_cycleNum = new TCanvas("c006A_cycleNum" , "c006A_cycleNum" , 1200, 800);
  c006A_cycleNum -> Divide(2,2);
  TPad *p006A = c006A_cycleNum->cd(1);
  p006A->SetLogy();
  TGraphErrors *gr006A_cyclecounts = new TGraphErrors (counter006A , cycleNumberArray006A, UCNCounts006A, 0 , UCNCountsErr006A);
  gr006A_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr006A_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr006A_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006A_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr006A_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr006A_cyclecounts -> SetMarkerStyle(20);
  gr006A_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr006A_cyclehist = new TGraphErrors(counter006A, cycleNumberArray006A , HistIntegralArray006A, 0, HistIntegralErrArray006A);

  gr006A_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr006A_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr006A_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr006A_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr006A_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr006A_cyclehist -> SetMarkerColor(1);
  gr006A_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr006A_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr006A_cyclehist, "UCN counts with background" , "P");
  
  gr006A_cyclecounts -> Draw("Ap");
  gr006A_cyclehist -> Draw("p");
  leg2-> Draw();

  c006A_cycleNum -> cd(2);
  TGraphErrors *gr006A_cycledelay = new TGraphErrors (counter006A , cycleNumberArray006A, cycleDelayTimeArray006A, 0 , 0);
  gr006A_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr006A_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr006A_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr006A_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr006A_cycledelay -> SetMarkerStyle(20);
  gr006A_cycledelay -> Draw("Ap");


  c006A_cycleNum -> cd(3);
  TGraphErrors *gr006A_cycletempVO = new TGraphErrors (counter006A , cycleNumberArray006A, avets12VOArray006A, 0 , ts12VOErrArray006A);

  gr006A_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr006A_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr006A_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr006A_cycletempVO -> SetMarkerStyle(20);
  // gr006A_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr006A_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr006A_cycletempVO -> Draw("AP");


  c006A_cycleNum -> cd(4);
  TGraphErrors *gr006A_cyclecur = new TGraphErrors (counter006A , cycleNumberArray006A , avecurArray006A, 0, avecurErrArray006A );
  gr006A_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr006A_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr006A_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr006A_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr006A_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr006A_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr006A_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr006A_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr006A_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr006A_cyclecur -> SetMarkerStyle(20);
  gr006A_cyclecur -> Draw("Ap");

  

  // ******************************************************************
  // TCN17012
  // ******************************************************************
  TCanvas *c012 = new TCanvas("c012", "c012", 1200 ,900);
  c012 -> SetLogy();
  

  TGraphErrors *gr012_1 = new TGraphErrors(counter012, cycleDelayTimeArray012, UCNCounts012, 0 , UCNCountsErr012);

  gr012_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr012_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr012_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr012_1 -> SetMarkerStyle(20);
  // gr012_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr012_1 -> GetXaxis()-> SetLimits(0, 160);
  gr012_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr012_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr012_1 -> SetMarkerColor(1);

  gr012_1 -> Draw("ap");
  gr012_1 -> Fit(fit1exp);
  storagelifetime012 = fit1exp -> GetParameter(1);
  fitErr012 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c012_cycleNum = new TCanvas("c012_cycleNum" , "c012_cycleNum" , 1200, 800);
  c012_cycleNum -> Divide(2,2);
  TPad *p012 = c012_cycleNum->cd(1);
  p012->SetLogy();
  TGraphErrors *gr012_cyclecounts = new TGraphErrors (counter012 , cycleNumberArray012, UCNCounts012, 0 , UCNCountsErr012);
  gr012_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr012_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr012_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr012_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr012_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr012_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr012_cyclecounts -> SetMarkerStyle(20);
  gr012_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr012_cyclehist = new TGraphErrors(counter012, cycleNumberArray012 , HistIntegralArray012, 0, HistIntegralErrArray012);

  gr012_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr012_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr012_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr012_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr012_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr012_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr012_cyclehist -> SetMarkerColor(1);
  gr012_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr012_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr012_cyclehist, "UCN counts with background" , "P");
  
  gr012_cyclecounts -> Draw("Ap");
  gr012_cyclehist -> Draw("p");
  leg2-> Draw();

  c012_cycleNum -> cd(2);
  TGraphErrors *gr012_cycledelay = new TGraphErrors (counter012 , cycleNumberArray012, cycleDelayTimeArray012, 0 , 0);
  gr012_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr012_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr012_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr012_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr012_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr012_cycledelay -> SetMarkerStyle(20);
  gr012_cycledelay -> Draw("Ap");


  c012_cycleNum -> cd(3);
  TGraphErrors *gr012_cycletempVO = new TGraphErrors (counter012 , cycleNumberArray012, avets12VOArray012, 0 , ts12VOErrArray012);

  gr012_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr012_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr012_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr012_cycletempVO -> SetMarkerStyle(20);
  // gr012_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr012_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr012_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr012_cycletempVO -> Draw("AP");


  c012_cycleNum -> cd(4);
  TGraphErrors *gr012_cyclecur = new TGraphErrors (counter012 , cycleNumberArray012 , avecurArray012, 0, avecurErrArray012 );
  gr012_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr012_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr012_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr012_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr012_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr012_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr012_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr012_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr012_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr012_cyclecur -> SetMarkerStyle(20);
  gr012_cyclecur -> Draw("Ap");



  // ******************************************************************
  // TCN17013
  // ******************************************************************
  TCanvas *c013 = new TCanvas("c013", "c013", 1200 ,900);
  c013 -> SetLogy();
  

  TGraphErrors *gr013_1 = new TGraphErrors(counter013, cycleDelayTimeArray013, UCNCounts013, 0 , UCNCountsErr013);

  gr013_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr013_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr013_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr013_1 -> SetMarkerStyle(20);
  // gr013_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr013_1 -> GetXaxis()-> SetLimits(0, 160);
  gr013_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr013_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr013_1 -> SetMarkerColor(1);

  gr013_1 -> Draw("ap");
  gr013_1 -> Fit(fit1exp);
  storagelifetime013 = fit1exp -> GetParameter(1);
  fitErr013 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c013_cycleNum = new TCanvas("c013_cycleNum" , "c013_cycleNum" , 1200, 800);
  c013_cycleNum -> Divide(2,2);
  TPad *p013 = c013_cycleNum->cd(1);
  p013->SetLogy();
  TGraphErrors *gr013_cyclecounts = new TGraphErrors (counter013 , cycleNumberArray013, UCNCounts013, 0 , UCNCountsErr013);
  gr013_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr013_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr013_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr013_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr013_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr013_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr013_cyclecounts -> SetMarkerStyle(20);
  gr013_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr013_cyclehist = new TGraphErrors(counter013, cycleNumberArray013 , HistIntegralArray013, 0, HistIntegralErrArray013);

  gr013_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr013_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr013_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr013_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr013_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr013_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr013_cyclehist -> SetMarkerColor(1);
  gr013_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr013_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr013_cyclehist, "UCN counts with background" , "P");
  
  gr013_cyclecounts -> Draw("Ap");
  gr013_cyclehist -> Draw("p");
  leg2-> Draw();

  c013_cycleNum -> cd(2);
  TGraphErrors *gr013_cycledelay = new TGraphErrors (counter013 , cycleNumberArray013, cycleDelayTimeArray013, 0 , 0);
  gr013_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr013_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr013_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr013_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr013_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr013_cycledelay -> SetMarkerStyle(20);
  gr013_cycledelay -> Draw("Ap");


  c013_cycleNum -> cd(3);
  TGraphErrors *gr013_cycletempVO = new TGraphErrors (counter013 , cycleNumberArray013, avets12VOArray013, 0 , ts12VOErrArray013);

  gr013_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr013_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr013_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr013_cycletempVO -> SetMarkerStyle(20);
  // gr013_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr013_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr013_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr013_cycletempVO -> Draw("AP");


  c013_cycleNum -> cd(4);
  TGraphErrors *gr013_cyclecur = new TGraphErrors (counter013 , cycleNumberArray013 , avecurArray013, 0, avecurErrArray013 );
  gr013_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr013_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr013_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr013_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr013_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr013_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr013_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr013_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr013_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr013_cyclecur -> SetMarkerStyle(20);
  gr013_cyclecur -> Draw("Ap");


  // ******************************************************************
  // TCN17016
  // ******************************************************************
  TCanvas *c016 = new TCanvas("c016", "c016", 1200 ,900);
  c016 -> SetLogy();
  

  TGraphErrors *gr016_1 = new TGraphErrors(counter016, cycleDelayTimeArray016, UCNCounts016, 0 , UCNCountsErr016);

  gr016_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr016_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr016_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr016_1 -> SetMarkerStyle(20);
  // gr016_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr016_1 -> GetXaxis()-> SetLimits(0, 180);
  gr016_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr016_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr016_1 -> SetMarkerColor(1);

  gr016_1 -> Draw("ap");
  gr016_1 -> Fit(fit1exp);
  storagelifetime016 = fit1exp -> GetParameter(1);
  fitErr016 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c016_cycleNum = new TCanvas("c016_cycleNum" , "c016_cycleNum" , 1200, 800);
  c016_cycleNum -> Divide(2,2);
  TPad *p016 = c016_cycleNum->cd(1);
  p016->SetLogy();
  TGraphErrors *gr016_cyclecounts = new TGraphErrors (counter016 , cycleNumberArray016, UCNCounts016, 0 , UCNCountsErr016);
  gr016_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr016_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr016_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr016_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr016_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr016_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr016_cyclecounts -> SetMarkerStyle(20);
  gr016_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr016_cyclehist = new TGraphErrors(counter016, cycleNumberArray016 , HistIntegralArray016, 0, HistIntegralErrArray016);

  gr016_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr016_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr016_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr016_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr016_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr016_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr016_cyclehist -> SetMarkerColor(1);
  gr016_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr016_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr016_cyclehist, "UCN counts with background" , "P");
  
  gr016_cyclecounts -> Draw("Ap");
  gr016_cyclehist -> Draw("p");
  leg2-> Draw();

  c016_cycleNum -> cd(2);
  TGraphErrors *gr016_cycledelay = new TGraphErrors (counter016 , cycleNumberArray016, cycleDelayTimeArray016, 0 , 0);
  gr016_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr016_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr016_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr016_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr016_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr016_cycledelay -> SetMarkerStyle(20);
  gr016_cycledelay -> Draw("Ap");


  c016_cycleNum -> cd(3);
  TGraphErrors *gr016_cycletempVO = new TGraphErrors (counter016 , cycleNumberArray016, avets12VOArray016, 0 , ts12VOErrArray016);

  gr016_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr016_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr016_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr016_cycletempVO -> SetMarkerStyle(20);
  // gr016_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr016_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr016_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr016_cycletempVO -> Draw("AP");


  c016_cycleNum -> cd(4);
  TGraphErrors *gr016_cyclecur = new TGraphErrors (counter016 , cycleNumberArray016 , avecurArray016, 0, avecurErrArray016 );
  gr016_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr016_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr016_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr016_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr016_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr016_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr016_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr016_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr016_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr016_cyclecur -> SetMarkerStyle(20);
  gr016_cyclecur -> Draw("Ap");
  

  // ******************************************************************
  // TCN17021
  // ******************************************************************
  TCanvas *c021 = new TCanvas("c021", "c021", 1200 ,900);
  c021 -> SetLogy();
  

  TGraphErrors *gr021_1 = new TGraphErrors(counter021, cycleDelayTimeArray021, UCNCounts021, 0 , UCNCountsErr021);

  gr021_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr021_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr021_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr021_1 -> SetMarkerStyle(20);
  // gr021_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr021_1 -> GetXaxis()-> SetLimits(0, 180);
  gr021_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr021_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr021_1 -> SetMarkerColor(1);

  gr021_1 -> Draw("ap");
  gr021_1 -> Fit(fit1exp);
  storagelifetime021 = fit1exp -> GetParameter(1);
  fitErr021 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c021_cycleNum = new TCanvas("c021_cycleNum" , "c021_cycleNum" , 1200, 800);
  c021_cycleNum -> Divide(2,2);
  TPad *p021 = c021_cycleNum->cd(1);
  p021->SetLogy();
  TGraphErrors *gr021_cyclecounts = new TGraphErrors (counter021 , cycleNumberArray021, UCNCounts021, 0 , UCNCountsErr021);
  gr021_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr021_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr021_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr021_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr021_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr021_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr021_cyclecounts -> SetMarkerStyle(20);
  gr021_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr021_cyclehist = new TGraphErrors(counter021, cycleNumberArray021 , HistIntegralArray021, 0, HistIntegralErrArray021);

  gr021_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr021_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr021_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr021_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr021_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr021_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr021_cyclehist -> SetMarkerColor(1);
  gr021_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr021_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr021_cyclehist, "UCN counts with background" , "P");
  
  gr021_cyclecounts -> Draw("Ap");
  gr021_cyclehist -> Draw("p");
  leg2-> Draw();

  c021_cycleNum -> cd(2);
  TGraphErrors *gr021_cycledelay = new TGraphErrors (counter021 , cycleNumberArray021, cycleDelayTimeArray021, 0 , 0);
  gr021_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr021_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr021_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr021_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr021_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr021_cycledelay -> SetMarkerStyle(20);
  gr021_cycledelay -> Draw("Ap");


  c021_cycleNum -> cd(3);
  TGraphErrors *gr021_cycletempVO = new TGraphErrors (counter021 , cycleNumberArray021, avets12VOArray021, 0 , ts12VOErrArray021);

  gr021_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr021_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr021_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr021_cycletempVO -> SetMarkerStyle(20);
  // gr021_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr021_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr021_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr021_cycletempVO -> Draw("AP");


  c021_cycleNum -> cd(4);
  TGraphErrors *gr021_cyclecur = new TGraphErrors (counter021 , cycleNumberArray021 , avecurArray021, 0, avecurErrArray021 );
  gr021_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr021_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr021_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr021_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr021_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr021_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr021_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr021_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr021_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr021_cyclecur -> SetMarkerStyle(20);
  gr021_cyclecur -> Draw("Ap");


  // ******************************************************************
  // TCN17023
  // ******************************************************************
  TCanvas *c023 = new TCanvas("c023", "c023", 1200 ,900);
  c023 -> SetLogy();
  

  TGraphErrors *gr023_1 = new TGraphErrors(counter023, cycleDelayTimeArray023, UCNCounts023, 0 , UCNCountsErr023);

  gr023_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr023_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr023_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr023_1 -> SetMarkerStyle(20);
  // gr023_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr023_1 -> GetXaxis()-> SetLimits(0, 180);
  gr023_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr023_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr023_1 -> SetMarkerColor(1);

  gr023_1 -> Draw("ap");
  gr023_1 -> Fit(fit1exp);
  storagelifetime023 = fit1exp -> GetParameter(1);
  fitErr023 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c023_cycleNum = new TCanvas("c023_cycleNum" , "c023_cycleNum" , 1200, 800);
  c023_cycleNum -> Divide(2,2);
  TPad *p023 = c023_cycleNum->cd(1);
  p023->SetLogy();
  TGraphErrors *gr023_cyclecounts = new TGraphErrors (counter023 , cycleNumberArray023, UCNCounts023, 0 , UCNCountsErr023);
  gr023_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr023_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr023_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr023_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr023_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr023_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr023_cyclecounts -> SetMarkerStyle(20);
  gr023_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr023_cyclehist = new TGraphErrors(counter023, cycleNumberArray023 , HistIntegralArray023, 0, HistIntegralErrArray023);

  gr023_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr023_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr023_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr023_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr023_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr023_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr023_cyclehist -> SetMarkerColor(1);
  gr023_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr023_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr023_cyclehist, "UCN counts with background" , "P");
  
  gr023_cyclecounts -> Draw("Ap");
  gr023_cyclehist -> Draw("p");
  leg2-> Draw();

  c023_cycleNum -> cd(2);
  TGraphErrors *gr023_cycledelay = new TGraphErrors (counter023 , cycleNumberArray023, cycleDelayTimeArray023, 0 , 0);
  gr023_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr023_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr023_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr023_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr023_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr023_cycledelay -> SetMarkerStyle(20);
  gr023_cycledelay -> Draw("Ap");


  c023_cycleNum -> cd(3);
  TGraphErrors *gr023_cycletempVO = new TGraphErrors (counter023 , cycleNumberArray023, avets12VOArray023, 0 , ts12VOErrArray023);

  gr023_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr023_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr023_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr023_cycletempVO -> SetMarkerStyle(20);
  // gr023_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr023_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr023_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr023_cycletempVO -> Draw("AP");


  c023_cycleNum -> cd(4);
  TGraphErrors *gr023_cyclecur = new TGraphErrors (counter023 , cycleNumberArray023 , avecurArray023, 0, avecurErrArray023 );
  gr023_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr023_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr023_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr023_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr023_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr023_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr023_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr023_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr023_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr023_cyclecur -> SetMarkerStyle(20);
  gr023_cyclecur -> Draw("Ap");
  

  // ******************************************************************
  // TCN17025
  // ******************************************************************
  TCanvas *c025 = new TCanvas("c025", "c025", 1200 ,900);
  c025 -> SetLogy();
  

  TGraphErrors *gr025_1 = new TGraphErrors(counter025, cycleDelayTimeArray025, UCNCounts025, 0 , UCNCountsErr025);

  gr025_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr025_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr025_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr025_1 -> SetMarkerStyle(20);
  // gr025_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr025_1 -> GetXaxis()-> SetLimits(0, 180);
  gr025_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr025_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr025_1 -> SetMarkerColor(1);

  gr025_1 -> Draw("ap");
  gr025_1 -> Fit(fit1exp);
  storagelifetime025 = fit1exp -> GetParameter(1);
  fitErr025 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c025_cycleNum = new TCanvas("c025_cycleNum" , "c025_cycleNum" , 1200, 800);
  c025_cycleNum -> Divide(2,2);
  TPad *p025 = c025_cycleNum->cd(1);
  p025->SetLogy();
  TGraphErrors *gr025_cyclecounts = new TGraphErrors (counter025 , cycleNumberArray025, UCNCounts025, 0 , UCNCountsErr025);
  gr025_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr025_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr025_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr025_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr025_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr025_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr025_cyclecounts -> SetMarkerStyle(20);
  gr025_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr025_cyclehist = new TGraphErrors(counter025, cycleNumberArray025 , HistIntegralArray025, 0, HistIntegralErrArray025);

  gr025_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr025_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr025_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr025_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr025_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr025_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr025_cyclehist -> SetMarkerColor(1);
  gr025_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr025_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr025_cyclehist, "UCN counts with background" , "P");
  
  gr025_cyclecounts -> Draw("Ap");
  gr025_cyclehist -> Draw("p");
  leg2-> Draw();

  c025_cycleNum -> cd(2);
  TGraphErrors *gr025_cycledelay = new TGraphErrors (counter025 , cycleNumberArray025, cycleDelayTimeArray025, 0 , 0);
  gr025_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr025_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr025_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr025_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr025_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr025_cycledelay -> SetMarkerStyle(20);
  gr025_cycledelay -> Draw("Ap");


  c025_cycleNum -> cd(3);
  TGraphErrors *gr025_cycletempVO = new TGraphErrors (counter025 , cycleNumberArray025, avets12VOArray025, 0 , ts12VOErrArray025);

  gr025_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr025_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr025_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr025_cycletempVO -> SetMarkerStyle(20);
  // gr025_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr025_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr025_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr025_cycletempVO -> Draw("AP");


  c025_cycleNum -> cd(4);
  TGraphErrors *gr025_cyclecur = new TGraphErrors (counter025 , cycleNumberArray025 , avecurArray025, 0, avecurErrArray025 );
  gr025_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr025_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr025_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr025_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr025_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr025_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr025_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr025_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr025_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr025_cyclecur -> SetMarkerStyle(20);
  gr025_cyclecur -> Draw("Ap");

  // ******************************************************************
  // TCN17026
  // ******************************************************************

  TCanvas *c026 = new TCanvas("c026", "c026", 1200 ,900);
  c026 -> SetLogy();
  

  TGraphErrors *gr026_1 = new TGraphErrors(counter026, cycleDelayTimeArray026, UCNCounts026, 0 , UCNCountsErr026);

  gr026_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr026_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr026_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr026_1 -> SetMarkerStyle(20);
  // gr026_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr026_1 -> GetXaxis()-> SetLimits(0, 180);
  gr026_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr026_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr026_1 -> SetMarkerColor(1);

  gr026_1 -> Draw("ap");
  gr026_1 -> Fit(fit1exp);
  storagelifetime026 = fit1exp -> GetParameter(1);
  fitErr026 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c026_cycleNum = new TCanvas("c026_cycleNum" , "c026_cycleNum" , 1200, 800);
  c026_cycleNum -> Divide(2,2);
  TPad *p026 = c026_cycleNum->cd(1);
  p026->SetLogy();
  TGraphErrors *gr026_cyclecounts = new TGraphErrors (counter026 , cycleNumberArray026, UCNCounts026, 0 , UCNCountsErr026);
  gr026_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr026_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr026_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr026_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr026_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr026_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr026_cyclecounts -> SetMarkerStyle(20);
  gr026_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr026_cyclehist = new TGraphErrors(counter026, cycleNumberArray026 , HistIntegralArray026, 0, HistIntegralErrArray026);

  gr026_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr026_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr026_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr026_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr026_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr026_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr026_cyclehist -> SetMarkerColor(1);
  gr026_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr026_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr026_cyclehist, "UCN counts with background" , "P");
  
  gr026_cyclecounts -> Draw("Ap");
  gr026_cyclehist -> Draw("p");
  leg2-> Draw();

  c026_cycleNum -> cd(2);
  TGraphErrors *gr026_cycledelay = new TGraphErrors (counter026 , cycleNumberArray026, cycleDelayTimeArray026, 0 , 0);
  gr026_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr026_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr026_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr026_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr026_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr026_cycledelay -> SetMarkerStyle(20);
  gr026_cycledelay -> Draw("Ap");


  c026_cycleNum -> cd(3);
  TGraphErrors *gr026_cycletempVO = new TGraphErrors (counter026 , cycleNumberArray026, avets12VOArray026, 0 , ts12VOErrArray026);

  gr026_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr026_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr026_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr026_cycletempVO -> SetMarkerStyle(20);
  // gr026_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr026_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr026_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr026_cycletempVO -> Draw("AP");


  c026_cycleNum -> cd(4);
  TGraphErrors *gr026_cyclecur = new TGraphErrors (counter026 , cycleNumberArray026 , avecurArray026, 0, avecurErrArray026 );
  gr026_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr026_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr026_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr026_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr026_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr026_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr026_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr026_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr026_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr026_cyclecur -> SetMarkerStyle(20);
  gr026_cyclecur -> Draw("Ap");




  // ******************************************************************
  // TCN17029
  // ******************************************************************

  TCanvas *c029 = new TCanvas("c029", "c029", 1200 ,900);
  c029 -> SetLogy();
  

  TGraphErrors *gr029_1 = new TGraphErrors(counter029, cycleDelayTimeArray029, UCNCounts029, 0 , UCNCountsErr029);

  gr029_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr029_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr029_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr029_1 -> SetMarkerStyle(20);
  // gr029_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr029_1 -> GetXaxis()-> SetLimits(0, 180);
  gr029_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr029_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr029_1 -> SetMarkerColor(1);

  gr029_1 -> Draw("ap");
  gr029_1 -> Fit(fit1exp);
  storagelifetime029 = fit1exp -> GetParameter(1);
  fitErr029 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c029_cycleNum = new TCanvas("c029_cycleNum" , "c029_cycleNum" , 1200, 800);
  c029_cycleNum -> Divide(2,2);
  TPad *p029 = c029_cycleNum->cd(1);
  p029->SetLogy();
  TGraphErrors *gr029_cyclecounts = new TGraphErrors (counter029 , cycleNumberArray029, UCNCounts029, 0 , UCNCountsErr029);
  gr029_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr029_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr029_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr029_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr029_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr029_cyclecounts -> SetMarkerStyle(20);
  gr029_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr029_cyclehist = new TGraphErrors(counter029, cycleNumberArray029 , HistIntegralArray029, 0, HistIntegralErrArray029);

  gr029_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr029_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr029_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr029_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr029_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr029_cyclehist -> SetMarkerColor(1);
  gr029_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr029_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr029_cyclehist, "UCN counts with background" , "P");
  
  gr029_cyclecounts -> Draw("Ap");
  gr029_cyclehist -> Draw("p");
  leg2-> Draw();

  c029_cycleNum -> cd(2);
  TGraphErrors *gr029_cycledelay = new TGraphErrors (counter029 , cycleNumberArray029, cycleDelayTimeArray029, 0 , 0);
  gr029_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr029_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr029_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr029_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr029_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr029_cycledelay -> SetMarkerStyle(20);
  gr029_cycledelay -> Draw("Ap");


  c029_cycleNum -> cd(3);
  TGraphErrors *gr029_cycletempVO = new TGraphErrors (counter029 , cycleNumberArray029, avets12VOArray029, 0 , ts12VOErrArray029);

  gr029_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr029_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr029_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr029_cycletempVO -> SetMarkerStyle(20);
  // gr029_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr029_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr029_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr029_cycletempVO -> Draw("AP");


  c029_cycleNum -> cd(4);
  TGraphErrors *gr029_cyclecur = new TGraphErrors (counter029 , cycleNumberArray029 , avecurArray029, 0, avecurErrArray029 );
  gr029_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr029_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr029_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr029_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr029_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr029_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr029_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr029_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr029_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr029_cyclecur -> SetMarkerStyle(20);
  gr029_cyclecur -> Draw("Ap");




  // ******************************************************************
  // TCN17029A
  // ******************************************************************

  TCanvas *c029A = new TCanvas("c029A", "c029A", 1200 ,900);
  c029A -> SetLogy();
  

  TGraphErrors *gr029A_1 = new TGraphErrors(counter029A, cycleDelayTimeArray029A, UCNCounts029A, 0 , UCNCountsErr029A);

  gr029A_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr029A_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr029A_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr029A_1 -> SetMarkerStyle(20);
  // gr029A_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr029A_1 -> GetXaxis()-> SetLimits(0, 180);
  gr029A_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr029A_1 -> SetMarkerColor(1);

  gr029A_1 -> Draw("ap");
  gr029A_1 -> Fit(fit1exp);
  storagelifetime029A = fit1exp -> GetParameter(1);
  fitErr029A = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c029A_cycleNum = new TCanvas("c029A_cycleNum" , "c029A_cycleNum" , 1200, 800);
  c029A_cycleNum -> Divide(2,2);
  TPad *p029A = c029A_cycleNum->cd(1);
  p029A->SetLogy();
  TGraphErrors *gr029A_cyclecounts = new TGraphErrors (counter029A , cycleNumberArray029A, UCNCounts029A, 0 , UCNCountsErr029A);
  gr029A_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr029A_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr029A_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029A_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr029A_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr029A_cyclecounts -> SetMarkerStyle(20);
  gr029A_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr029A_cyclehist = new TGraphErrors(counter029A, cycleNumberArray029A , HistIntegralArray029A, 0, HistIntegralErrArray029A);

  gr029A_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr029A_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr029A_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr029A_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr029A_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr029A_cyclehist -> SetMarkerColor(1);
  gr029A_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr029A_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr029A_cyclehist, "UCN counts with background" , "P");
  
  gr029A_cyclecounts -> Draw("Ap");
  gr029A_cyclehist -> Draw("p");
  leg2-> Draw();

  c029A_cycleNum -> cd(2);
  TGraphErrors *gr029A_cycledelay = new TGraphErrors (counter029A , cycleNumberArray029A, cycleDelayTimeArray029A, 0 , 0);
  gr029A_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr029A_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr029A_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr029A_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr029A_cycledelay -> SetMarkerStyle(20);
  gr029A_cycledelay -> Draw("Ap");


  c029A_cycleNum -> cd(3);
  TGraphErrors *gr029A_cycletempVO = new TGraphErrors (counter029A , cycleNumberArray029A, avets12VOArray029A, 0 , ts12VOErrArray029A);

  gr029A_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr029A_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr029A_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr029A_cycletempVO -> SetMarkerStyle(20);
  // gr029A_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr029A_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr029A_cycletempVO -> Draw("AP");


  c029A_cycleNum -> cd(4);
  TGraphErrors *gr029A_cyclecur = new TGraphErrors (counter029A , cycleNumberArray029A , avecurArray029A, 0, avecurErrArray029A );
  gr029A_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr029A_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr029A_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr029A_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr029A_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr029A_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr029A_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr029A_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr029A_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr029A_cyclecur -> SetMarkerStyle(20);
  gr029A_cyclecur -> Draw("Ap");





  
  // ******************************************************************
  // TCN17031
  // ******************************************************************

  TCanvas *c031 = new TCanvas("c031", "c031", 1200 ,900);
  c031 -> SetLogy();
  

  TGraphErrors *gr031_1 = new TGraphErrors(counter031, cycleDelayTimeArray031, UCNCounts031, 0 , UCNCountsErr031);

  gr031_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr031_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr031_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr031_1 -> SetMarkerStyle(20);
  // gr031_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr031_1 -> GetXaxis()-> SetLimits(0, 180);
  gr031_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr031_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr031_1 -> SetMarkerColor(1);

  gr031_1 -> Draw("ap");
  gr031_1 -> Fit(fit1exp);
  storagelifetime031 = fit1exp -> GetParameter(1);
  fitErr031 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c031_cycleNum = new TCanvas("c031_cycleNum" , "c031_cycleNum" , 1200, 800);
  c031_cycleNum -> Divide(2,2);
  TPad *p031 = c031_cycleNum->cd(1);
  p031->SetLogy();
  TGraphErrors *gr031_cyclecounts = new TGraphErrors (counter031 , cycleNumberArray031, UCNCounts031, 0 , UCNCountsErr031);
  gr031_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr031_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr031_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr031_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr031_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr031_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr031_cyclecounts -> SetMarkerStyle(20);
  gr031_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr031_cyclehist = new TGraphErrors(counter031, cycleNumberArray031 , HistIntegralArray031, 0, HistIntegralErrArray031);

  gr031_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr031_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr031_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr031_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr031_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr031_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr031_cyclehist -> SetMarkerColor(1);
  gr031_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr031_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr031_cyclehist, "UCN counts with background" , "P");
  
  gr031_cyclecounts -> Draw("Ap");
  gr031_cyclehist -> Draw("p");
  leg2-> Draw();

  c031_cycleNum -> cd(2);
  TGraphErrors *gr031_cycledelay = new TGraphErrors (counter031 , cycleNumberArray031, cycleDelayTimeArray031, 0 , 0);
  gr031_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr031_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr031_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr031_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr031_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr031_cycledelay -> SetMarkerStyle(20);
  gr031_cycledelay -> Draw("Ap");


  c031_cycleNum -> cd(3);
  TGraphErrors *gr031_cycletempVO = new TGraphErrors (counter031 , cycleNumberArray031, avets12VOArray031, 0 , ts12VOErrArray031);

  gr031_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr031_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr031_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr031_cycletempVO -> SetMarkerStyle(20);
  // gr031_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr031_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr031_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr031_cycletempVO -> Draw("AP");


  c031_cycleNum -> cd(4);
  TGraphErrors *gr031_cyclecur = new TGraphErrors (counter031 , cycleNumberArray031 , avecurArray031, 0, avecurErrArray031 );
  gr031_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr031_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr031_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr031_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr031_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr031_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr031_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr031_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr031_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr031_cyclecur -> SetMarkerStyle(20);
  gr031_cyclecur -> Draw("Ap");



    
  // ******************************************************************
  // TCN17780
  // ******************************************************************

  TCanvas *c780 = new TCanvas("c780", "c780", 1200 ,900);
  c780 -> SetLogy();
  

  TGraphErrors *gr780_1 = new TGraphErrors(counter780, cycleDelayTimeArray780, UCNCounts780, 0 , UCNCountsErr780);

  gr780_1 -> SetTitle( "UCN Counts vs Cycle Delay Time ");
  gr780_1 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr780_1 -> SetMarkerStyle(20);
  // gr780_1 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr780_1 -> GetXaxis()-> SetLimits(0, 180);
  gr780_1 -> GetXaxis() -> SetTitleSize(0.05);
  gr780_1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_1 -> SetMarkerColor(1);

  gr780_1 -> Draw("ap");
  gr780_1 -> Fit(fit1exp);
  storagelifetime780 = fit1exp -> GetParameter(1);
  fitErr780 = fit1exp->GetParError(1);
  //-----------------------------------------------------------------
  TCanvas *c780_cycleNum = new TCanvas("c780_cycleNum" , "c780_cycleNum" , 1200, 800);
  c780_cycleNum -> Divide(2,2);
  TPad *p780 = c780_cycleNum->cd(1);
  p780->SetLogy();
  TGraphErrors *gr780_cyclecounts = new TGraphErrors (counter780 , cycleNumberArray780, UCNCounts780, 0 , UCNCountsErr780);
  gr780_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr780_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr780_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr780_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cyclecounts -> SetMarkerStyle(20);
  gr780_cyclecounts -> SetMarkerColor(2);

  TGraphErrors *gr780_cyclehist = new TGraphErrors(counter780, cycleNumberArray780 , HistIntegralArray780, 0, HistIntegralErrArray780);

  gr780_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr780_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr780_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr780_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr780_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr780_cyclehist -> SetMarkerColor(1);
  gr780_cyclehist -> SetMarkerStyle(25);

  TLegend *leg2 = new TLegend (0.7 , 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr780_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr780_cyclehist, "UCN counts with background" , "P");
  
  gr780_cyclecounts -> Draw("Ap");
  gr780_cyclehist -> Draw("p");
  leg2-> Draw();

  c780_cycleNum -> cd(2);
  TGraphErrors *gr780_cycledelay = new TGraphErrors (counter780 , cycleNumberArray780, cycleDelayTimeArray780, 0 , 0);
  gr780_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr780_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr780_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr780_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr780_cycledelay -> SetMarkerStyle(20);
  gr780_cycledelay -> Draw("Ap");


  c780_cycleNum -> cd(3);
  TGraphErrors *gr780_cycletempVO = new TGraphErrors (counter780 , cycleNumberArray780, avets12VOArray780, 0 , ts12VOErrArray780);

  gr780_cycletempVO -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr780_cycletempVO -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr780_cycletempVO -> GetXaxis()-> SetTitle("Cycle Number");
  gr780_cycletempVO -> SetMarkerStyle(20);
  // gr780_cycletempVO -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr780_cycletempVO -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cycletempVO -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cycletempVO -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cycletempVO -> GetYaxis() -> SetTitleOffset(1.2);

  gr780_cycletempVO -> Draw("AP");


  c780_cycleNum -> cd(4);
  TGraphErrors *gr780_cyclecur = new TGraphErrors (counter780 , cycleNumberArray780 , avecurArray780, 0, avecurErrArray780 );
  gr780_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr780_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr780_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr780_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr780_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr780_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr780_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr780_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr780_cyclecur -> GetYaxis() -> SetTitleOffset(1.2);

  gr780_cyclecur -> SetMarkerStyle(20);
  gr780_cyclecur -> Draw("Ap");

  // Now all the storage lifetimes vs date
  
  TDatime da002 (2017,11,13,12,00,00);
  TDatime da003 (2017,11,14,12,00,00);
  TDatime da004A (2017,11,15,12,00,00);
  TDatime da006 (2017,11,16,12,00,00);
  TDatime da006A (2017,11,17,12,00,00);
  TDatime da012 (2017,11,20,12,00,00);
  TDatime da013 (2017,11,21,12,00,00);
  TDatime da016 (2017,11,24,12,00,00);
  TDatime da021 (2017,11,26,12,00,00);
  TDatime da023 (2017,11,27,12,00,00);
  TDatime da025 (2017,11,28,12,00,00);
  TDatime da026 (2017,11,29,12,00,00);
  TDatime da029 (2017,12,01,12,00,00);
  TDatime da029A (2017,12,01,12,00,00);
  TDatime da031 (2017,12,01,12,00,00);
  TDatime da780 (2017,11,22,12,00,00);

  double StorageLifetimeArray[100] = { storagelifetime002, storagelifetime003, storagelifetime004A, storagelifetime006, storagelifetime006A, storagelifetime012, storagelifetime013,  storagelifetime016, storagelifetime021, storagelifetime023, storagelifetime025, storagelifetime026, storagelifetime029, storagelifetime029A, storagelifetime031, storagelifetime780};

  double StorageLifetimeErrArray[100] = {fitErr002, fitErr003, fitErr004A, fitErr006, fitErr006A, fitErr012, fitErr013, fitErr016, fitErr021, fitErr023, fitErr025, fitErr026, fitErr029, fitErr029A, fitErr031, fitErr780};

  double dateArray[100] = {da002.Convert(), da003.Convert(), da004A.Convert(), da006.Convert(), da006A.Convert(), da012.Convert(), da013.Convert(), da016.Convert(), da021.Convert(), da023.Convert(), da025.Convert(), da026.Convert(), da029.Convert(), da029A.Convert(), da031.Convert(), da780.Convert()};

  TCanvas *cOverall = new TCanvas ("cOverall" , "cOverall", 1200, 900);

  TGraphErrors *StorageOverall = new TGraphErrors (16, dateArray, StorageLifetimeArray, 0 , StorageLifetimeErrArray);
  StorageOverall-> SetMarkerStyle(20);
  StorageOverall -> SetTitle("Storage Lifetime vs Date");
  StorageOverall -> GetYaxis() -> SetTitle("Storage Lifetime (s)");
  StorageOverall -> GetYaxis() -> SetRangeUser(0, 40);
  StorageOverall -> GetXaxis()->SetTimeDisplay(1);
  StorageOverall -> GetXaxis()->SetNdivisions(503);
  StorageOverall -> GetXaxis()->SetTimeFormat(" #splitline{%b}{ %d}");
  StorageOverall -> GetXaxis()->SetTimeOffset(0,"pst");
  StorageOverall -> GetXaxis() -> SetTitleSize(0.05);
  StorageOverall -> GetYaxis() -> SetTitleSize(0.05);
  StorageOverall -> GetXaxis() -> SetLabelOffset(0.03);
  StorageOverall-> Draw("Ap");
}
