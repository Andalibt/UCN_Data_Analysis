// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS WITH
// 60s IRRADIATION TIME.
// ********************************************************************

void FitGraph(TGraph* gr, TF1* func, std::string opt){
  gr->Fit(func, opt+"+");
}

void StorageTime_60sIrrad_separateGraphs_ver2(){
  gStyle->SetOptFit(0000);

  // OPENING ALL THE FILES
  TFile *fin1 = new TFile("outputTree_StorageTime_17003.root","READ");
  TFile *fin2 = new TFile("outputTree_StorageTime_17013.root","READ");
  TFile *fin3 = new TFile("outputTree_StorageTime_17023.root","READ");
  TFile *fin4 = new TFile("outputTree_StorageTime_17025.root","READ");
  TFile *fin5 = new TFile("outputTree_StorageTime_17026.root","READ");
  TFile *fin6 = new TFile("outputTree_StorageTime_17029A.root","READ");
  TFile *fin7 = new TFile("outputTree_StorageTime_17031.root","READ");
  TFile *fin8 = new TFile("outputTree_StorageTime_17002.root","READ");
  TFile *fin9 = new TFile("outputTree_StorageTime_17006.root","READ");
  TFile *fin10 = new TFile("outputTree_StorageTime_17021.root","READ");

  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree1 = (TTree*) fin1->Get("cycle_info");
  TTree *outputTree2 = (TTree*) fin2->Get("cycle_info");
  TTree *outputTree3 = (TTree*) fin3->Get("cycle_info");
  TTree *outputTree4 = (TTree*) fin4->Get("cycle_info");
  TTree *outputTree5 = (TTree*) fin5->Get("cycle_info");
  TTree *outputTree6 = (TTree*) fin6->Get("cycle_info");
  TTree *outputTree7 = (TTree*) fin7->Get("cycle_info");
  TTree *outputTree8 = (TTree*) fin8->Get("cycle_info");
  TTree *outputTree9 = (TTree*) fin9->Get("cycle_info");
  TTree *outputTree10 = (TTree*) fin10->Get("cycle_info");
 
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

  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT
  // WITH CONSIDERING UCN COUNTS FROM THE HISTOGRAM
  // INTEGRAL
  double storagehist003_1expfit = 0;
  double storagehist013_1expfit = 0;
  double storagehist023_1expfit = 0;
  double storagehist025_1expfit = 0;
  double storagehist026_1expfit = 0;
  double storagehist029A_1expfit = 0;
  double storagehist031_1expfit = 0;
  double storagehist002_1expfit = 0;
  double storagehist006_1expfit = 0;
  double storagehist021_1expfit = 0;

  // ERROR ASSOCIATED WITH THE STORAGE TIME
  // FROM THE ONE EXPONENTIAL FIT CONSIDERING
  // THE UCN COUNTS FROM THE HISTOGRAM INTEGRAL
  double storageErrhist003_1expfit = 0;
  double storageErrhist013_1expfit = 0;
  double storageErrhist023_1expfit = 0;
  double storageErrhist025_1expfit = 0;
  double storageErrhist026_1expfit = 0;
  double storageErrhist029A_1expfit = 0;
  double storageErrhist031_1expfit = 0;
  double storageErrhist002_1expfit = 0;
  double storageErrhist006_1expfit = 0;
  double storageErrhist021_1expfit = 0;



  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON
  double fit003tau1 = 0;
  double fit013tau1 = 0;
  double fit023tau1 = 0;
  double fit025tau1 = 0;
  double fit026tau1 = 0;
  double fit029Atau1 = 0;
  double fit031tau1 = 0;
  double fit002tau1 = 0;
  double fit006tau1 = 0;
  double fit021tau1 = 0;


  double fit003tau2 = 0;
  double fit013tau2 = 0;
  double fit023tau2 = 0;
  double fit025tau2 = 0;
  double fit026tau2 = 0;
  double fit029Atau2 = 0;
  double fit031tau2 = 0;
  double fit002tau2 = 0;
  double fit006tau2 = 0;
  double fit021tau2 = 0;

  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION

  double fit003tau1Err = 0;
  double fit013tau1Err = 0;
  double fit023tau1Err = 0;
  double fit025tau1Err = 0;
  double fit026tau1Err = 0;
  double fit029Atau1Err = 0;
  double fit031tau1Err = 0;
  double fit002tau1Err = 0;
  double fit006tau1Err = 0;
  double fit021tau1Err = 0;


  double fit003tau2Err = 0;
  double fit013tau2Err = 0;
  double fit023tau2Err = 0;
  double fit025tau2Err = 0;
  double fit026tau2Err = 0;
  double fit029Atau2Err = 0;
  double fit031tau2Err = 0;
  double fit002tau2Err = 0;
  double fit006tau2Err = 0;
  double fit021tau2Err = 0;


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
 


  // SET THE BRANCH TO GET THE RUN NUMBER FROM THE TREE
  outputTree1 -> SetBranchAddress ("runNumber" , &runNumber1);
  outputTree2 -> SetBranchAddress ("runNumber" , &runNumber2);
  outputTree3 -> SetBranchAddress ("runNumber" , &runNumber3);
  outputTree4 -> SetBranchAddress ("runNumber" , &runNumber4);
  outputTree5 -> SetBranchAddress ("runNumber" , &runNumber5);
  outputTree6 -> SetBranchAddress ("runNumber" , &runNumber6);
  outputTree7 -> SetBranchAddress ("runNumber" , &runNumber7);
  outputTree8 -> SetBranchAddress ("runNumber" , &runNumber8);
  outputTree9 -> SetBranchAddress ("runNumber" , &runNumber9);
  outputTree10 -> SetBranchAddress ("runNumber" , &runNumber10);

  // SET THE BRANCH TO GET THE CYCLE DELAY TIME FROM THE TREE
  outputTree1 -> SetBranchAddress ("cycleDelayTime", &delayTime1);
  outputTree2 -> SetBranchAddress ("cycleDelayTime", &delayTime2);
  outputTree3 -> SetBranchAddress ("cycleDelayTime", &delayTime3);
  outputTree4 -> SetBranchAddress ("cycleDelayTime", &delayTime4);
  outputTree5 -> SetBranchAddress ("cycleDelayTime", &delayTime5);
  outputTree6 -> SetBranchAddress ("cycleDelayTime", &delayTime6);
  outputTree7 -> SetBranchAddress ("cycleDelayTime", &delayTime7);
  outputTree8 -> SetBranchAddress ("cycleDelayTime", &delayTime8);
  outputTree9 -> SetBranchAddress ("cycleDelayTime", &delayTime9);
  outputTree10 -> SetBranchAddress ("cycleDelayTime", &delayTime10);
   
  // SET THE BRANCH ADDRESS TO GET THE UCNINTEGRAL (FROM THE FIT
  // FUNCTION) FROM THE TREE
  outputTree1 -> SetBranchAddress ("UCNIntegral", &UCNIntegral1);
  outputTree2 -> SetBranchAddress ("UCNIntegral", &UCNIntegral2);
  outputTree3 -> SetBranchAddress ("UCNIntegral", &UCNIntegral3);
  outputTree4 -> SetBranchAddress ("UCNIntegral", &UCNIntegral4);
  outputTree5 -> SetBranchAddress ("UCNIntegral", &UCNIntegral5);
  outputTree6 -> SetBranchAddress ("UCNIntegral", &UCNIntegral6);
  outputTree7 -> SetBranchAddress ("UCNIntegral", &UCNIntegral7);
  outputTree8 -> SetBranchAddress ("UCNIntegral", &UCNIntegral8);
  outputTree9 -> SetBranchAddress ("UCNIntegral", &UCNIntegral9);
  outputTree10 -> SetBranchAddress ("UCNIntegral", &UCNIntegral10);

  // SET THE BRANCH ADDRESS TO GET THE ERROR ASSOCIATED WITH THE
  // INTEGRAL FROM THE FIT FUNCTION
  outputTree1 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr1);
  outputTree2 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr2);
  outputTree3 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr3);
  outputTree4 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr4);
  outputTree5 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr5);
  outputTree6 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr6);
  outputTree7 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr7);
  outputTree8 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr8);
  outputTree9 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr9);
  outputTree10 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr10);

  // SET THE BRANCH ADDRESS TO GET THE HISTOGRAM INTEGRAL FROM THE TREE
  outputTree1 -> SetBranchAddress ("HistIntegral" , &HistIntegral1);
  outputTree2 -> SetBranchAddress ("HistIntegral" , &HistIntegral2);
  outputTree3 -> SetBranchAddress ("HistIntegral" , &HistIntegral3);
  outputTree4 -> SetBranchAddress ("HistIntegral" , &HistIntegral4);
  outputTree5 -> SetBranchAddress ("HistIntegral" , &HistIntegral5);
  outputTree6 -> SetBranchAddress ("HistIntegral" , &HistIntegral6);
  outputTree7 -> SetBranchAddress ("HistIntegral" , &HistIntegral7);
  outputTree8 -> SetBranchAddress ("HistIntegral" , &HistIntegral8);
  outputTree9 -> SetBranchAddress ("HistIntegral" , &HistIntegral9);
  outputTree10 -> SetBranchAddress ("HistIntegral" , &HistIntegral10);
  /*
  // SET THE BRANCH ADDRESS TO GET THE AVERAGE ISOPURE HELIUM TEMPERATURE DURING VALVE OPEN
  ouputTree1 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_003);
  ouputTree2 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_013);
  ouputTree3 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_023);
  ouputTree4 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_025);
  ouputTree5 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_026);
  ouputTree6 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_031);
  ouputTree7 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_002);
  ouputTree8 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_006);
  // ouputTree9 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_003);
  //ouputTree10 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_003);*/


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
  

  // GET THE EVENTS FOR TCN17003
  ULong64_t event1;
  event1 = (Double_t)outputTree1->GetEntries();

  // GET THE EVENTS FOR TCN17013
  ULong64_t event2;
  event2 = (Double_t)outputTree2->GetEntries();

  // GET THE EVENTS FOR TCN17023
  ULong64_t event3;
  event3 = (Double_t)outputTree3->GetEntries();

  // GET THE EVENTS FOR TCN17025
  ULong64_t event4;
  event4 = (Double_t)outputTree4->GetEntries();

  // GET THE EVENTS FOR TCN17026
  ULong64_t event5;
  event5 = (Double_t)outputTree5->GetEntries();

  // GET THE EVENTS FOR TCN17029A
  ULong64_t event6;
  event6 = (Double_t)outputTree6->GetEntries();

  // GET THE EVENTS FOR TCN17031
  ULong64_t event7;
  event7 = (Double_t)outputTree7->GetEntries();

  // GET THE EVENTS FOR TCN17002
  ULong64_t event8;
  event8 = (Double_t)outputTree8->GetEntries();

  // GET THE EVENTS FOR TCN17006
  ULong64_t event9;
  event9 = (Double_t)outputTree9->GetEntries();

  // GET THE EVENTS FOR TCN17021
  ULong64_t event10;
  event10 = (Double_t)outputTree10->GetEntries();



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


 cout.setf(ios::fixed);

 // FOR TCN17003
  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree1 -> GetEvent(j);
    if ( HistIntegral1 < 2000)
      continue;
    // cout << UCNIntegral1 << endl;
    UCNIntegralArray1[j] = UCNIntegral1;
    UCNIntegralErrArray1[j] = UCNIntegralErr1;
    delayTimeArray1[j] = delayTime1;
    HistIntegralArray1[j] = HistIntegral1;
    //cout << HistIntegral1 << " " << UCNIntegralArray1[j]<< " " << UCNIntegral1/HistIntegral1 << endl;
    counts1++;
  }

  // FOR TCN17013
  for (ULong64_t j = 0 ; j < event2 ; j++){
    outputTree2 -> GetEvent(j);
    UCNIntegralArray2[j] = UCNIntegral2;
    UCNIntegralErrArray2[j] = UCNIntegralErr2;
    delayTimeArray2[j] = delayTime2;
    HistIntegralArray2[j] = HistIntegral2;
    //cout << HistIntegral2 << " " << UCNIntegralArray2[j]<< " " << UCNIntegral2/HistIntegral2 << endl;
    counts2++;
  }

  // FOR TCN17023
  for (ULong64_t j = 0 ; j < event3 ; j++){
    outputTree3 -> GetEvent(j);
    //if ( UCNIntegralErr3 > 2000)
    // continue;
    UCNIntegralArray3[j] = UCNIntegral3;
    UCNIntegralErrArray3[j] = UCNIntegralErr3;
    delayTimeArray3[j] = delayTime3;
    HistIntegralArray3[j] = HistIntegral3;
    counts3++;
  }

  // FOR TCN17025
  for (ULong64_t j = 0 ; j < event4 ; j++){
    outputTree4 -> GetEvent(j);
    UCNIntegralArray4[j] = UCNIntegral4;
    UCNIntegralErrArray4[j] = UCNIntegralErr4;
    delayTimeArray4[j] = delayTime4;
    HistIntegralArray4[j] = HistIntegral4;
    counts4++;
  }

  // FOR TCN17026
  for (ULong64_t j = 0 ; j < event5 ; j++){
    outputTree5 -> GetEvent(j);
    cout << "Without Bkgrnd    " << UCNIntegral5 << " With Bkgrnd    " << HistIntegral5 <<  " Delay    " << delayTime5 <<endl;
    UCNIntegralArray5[j] = UCNIntegral5;
    UCNIntegralErrArray5[j] = UCNIntegralErr5;
    delayTimeArray5[j] = delayTime5;
    HistIntegralArray5[j] = HistIntegral5;
    counts5++;
  }

  // FOR TCN17029A
  for (ULong64_t j = 0 ; j < event6 ; j++){
    outputTree6 -> GetEvent(j);
    //   if (HistIntegral6 < 1000)
    //    continue;
    UCNIntegralArray6[j] = UCNIntegral6;
    UCNIntegralErrArray6[j] = UCNIntegralErr6;
    delayTimeArray6[j] = delayTime6;
    HistIntegralArray6[j] = HistIntegral6;
    //cout << HistIntegral6 << " " << UCNIntegralArray6[j]<< endl;
    counts6++;
  }

  // FOR TCN17031
  for (ULong64_t j = 0 ; j < event7 ; j++){
    outputTree7 -> GetEvent(j);
    UCNIntegralArray7[j] = UCNIntegral7;
    UCNIntegralErrArray7[j] = UCNIntegralErr7;
    delayTimeArray7[j] = delayTime7;
    HistIntegralArray7[j] = HistIntegral7;
    counts7++;
  }

  // FOR TCN17002
  for (ULong64_t j = 0 ; j < event8 ; j++){
    outputTree8 -> GetEvent(j);
    //  if (UCNIntegralErr8 > 2000 || HistIntegral8 < 400 )
    //    continue;
    //cout << HistIntegral8 << endl;
    UCNIntegralArray8[j] = UCNIntegral8;
    UCNIntegralErrArray8[j] = UCNIntegralErr8;
    delayTimeArray8[j] = delayTime8;
    HistIntegralArray8[j] = HistIntegral8;
    counts8++;
  }

  // FOR TCN17006
  for (ULong64_t j = 0 ; j < event9 ; j++){
    outputTree9 -> GetEvent(j);
    if ( UCNIntegral9 < 10000 && delayTime9 <10 )
      continue;
    if (UCNIntegral9 < 100)
      continue;
    //cout << HistIntegral9 << " " << UCNIntegral9 << endl;
    UCNIntegralArray9[j] = UCNIntegral9;
    UCNIntegralErrArray9[j] = UCNIntegralErr9;
    delayTimeArray9[j] = delayTime9;
    HistIntegralArray9[j] = HistIntegral9;
    counts9++;
  }
  
  // FOR TCN17021
  for (ULong64_t j = 0 ; j < event10 ; j++){
    outputTree10 -> GetEvent(j);
    //  if ( UCNIntegralErr10 > 2000 || HistIntegral10 < 10)
    // continue;
    //cout << UCNIntegralErr10 << endl;
    UCNIntegralArray10[j] = UCNIntegral10;
    UCNIntegralErrArray10[j] = UCNIntegralErr10;
    delayTimeArray10[j] = delayTime10;
    HistIntegralArray10[j] = HistIntegral10;
    counts10++;
  }


  // ONE EXPONENTIAL FIT
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 120);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(25000,30);
  fit1exp -> SetParLimits(0, 10000, 60000);
  //fit1exp -> SetParLimits(1, 20, 45);
  

  // TWO EXPONENTIAL FIT

  
  TF1 *fit2exp = new TF1 ("fit2exp" , "[0]*exp(-x/[1])+exp(-x/[2])*[3]", 0, 170);
  fit2exp -> SetParNames("Amplitude1", "Tau1", "Tau2","Amplitude2");
  fit2exp -> SetParameters(1000, 100 ,30, 35000.  );
  fit2exp -> SetParLimits(3,0 , 100000);
  fit2exp -> SetParLimits(1, 10, 200);
  fit2exp -> SetParLimits(2, 10, 100);
  fit2exp -> SetParLimits(0,0, 100000);


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


   gr1 -> Fit(fit2exp,"+WW");
  fit2exp -> SetLineColor(3);
  fit003tau1 = fit2exp -> GetParameter(1);
  fit003tau2 = fit2exp -> GetParameter(2);
  fit003tau1Err = fit2exp -> GetParError(1);
  fit003tau2Err = fit2exp -> GetParError(2);


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
  

  gr2 -> Fit(fit2exp, "+WW");
  fit013tau1 = fit2exp -> GetParameter(1);
  fit013tau2 = fit2exp -> GetParameter(2);
  fit013tau1Err = fit2exp -> GetParError(1);
  fit013tau2Err = fit2exp -> GetParError(2);


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

  gr3 -> Fit(fit2exp, "+WW");
  fit023tau1 = fit2exp -> GetParameter(1);
  fit023tau2 = fit2exp -> GetParameter(2);
  fit023tau1Err = fit2exp -> GetParError(1);
  fit023tau2Err = fit2exp -> GetParError(2);


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

  gr4 -> Fit(fit2exp, "+WW");
  fit025tau1 = fit2exp -> GetParameter(1);
  fit025tau2 = fit2exp -> GetParameter(2);
  fit025tau1Err = fit2exp -> GetParError(1);
  fit025tau2Err = fit2exp -> GetParError(2);

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


  gr5 -> Fit(fit2exp, "+WW");
  fit026tau1 = fit2exp -> GetParameter(1);
  fit026tau2 = fit2exp -> GetParameter(2);
  fit026tau1Err = fit2exp -> GetParError(1);
  fit026tau2Err = fit2exp -> GetParError(2);
 
  
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

  gr6 -> Fit(fit2exp, "+WW" );
  fit029Atau1 = fit2exp -> GetParameter(1);
  fit029Atau2 = fit2exp -> GetParameter(2);
  fit029Atau1Err = fit2exp -> GetParError(1);
  fit029Atau2Err = fit2exp -> GetParError(2);

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

  gr7 -> Fit(fit2exp, "+WW");
  fit031tau1 = fit2exp -> GetParameter(1);
  fit031tau2 = fit2exp -> GetParameter(2);
  fit031tau1Err = fit2exp -> GetParError(1);
  fit031tau2Err = fit2exp -> GetParError(2);

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

  gr8 -> Fit(fit2exp, "+WW");
  fit002tau1 = fit2exp -> GetParameter(1);
  fit002tau2 = fit2exp -> GetParameter(2);
  fit002tau1Err = fit2exp -> GetParError(1);
  fit002tau2Err = fit2exp -> GetParError(2);

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

  gr9 -> Fit(fit2exp, "+WW");
  fit006tau1 = fit2exp -> GetParameter(1);
  fit006tau2 = fit2exp -> GetParameter(2);
  fit006tau1Err = fit2exp -> GetParError(1);
  fit006tau2Err = fit2exp -> GetParError(2);


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

  gr10 -> Fit(fit2exp, "+WW");
  fit021tau1 = fit2exp -> GetParameter(1);
  fit021tau2 = fit2exp -> GetParameter(2);
  fit021tau1Err = fit2exp -> GetParError(1);
  fit021tau2Err = fit2exp -> GetParError(2);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr1010 = new TGraph(counts10, delayTimeArray10, HistIntegralArray10);
  gr1010 -> SetMarkerStyle(22);
  gr1010 -> SetMarkerColor(2);

  gr10 -> Draw("ap");
  gr1010 -> Draw("p");
  
  
  /* TLegend *leg = new TLegend (0.65,0.55, 0.84, 0.87);
  leg -> SetHeader("UCN Experiment Number");
  leg -> AddEntry(gr8, "TCN002", "p"); 
  leg -> AddEntry(gr1, "TCN003", "p");
  //leg -> AddEntry(gr9, "TCN006", "p"); 
  leg -> AddEntry(gr2, "TCN013", "p");
  leg -> AddEntry(gr10, "TCN021", "p"); 
  leg -> AddEntry(gr3, "TCN023", "p");
  leg -> AddEntry(gr4, "TCN025", "p");
  leg -> AddEntry(gr5, "TCN026", "p");
  leg -> AddEntry(gr6, "TCN029A", "p");
  leg -> AddEntry(gr7, "TCN031", "p"); 
  */
  
 
 

  //leg -> Draw();
 

  
  
  TText *text2 = new TText();
  text2-> SetNDC();
  text2 -> SetTextFont(1);
  text2 -> SetTextColor(2);
  text2 -> SetTextSize(0.03);
  text2 -> SetTextAlign(22);
  text2 -> SetTextAngle(0);
  // text2 -> DrawText(0.6, 0.4, "Counts From Histogram Integral");
  

  //***********************************************************
  // COMMENTS:
  // - AFTER FURTHER INVESTIGATION, I HAVE TO EXCLUDE TCN17002
  //   AND IT IS BECASE THERE ARE MULTIPLE VALUES AT ONE DELAY
  //   TIME
  // - TCN17003 IS EXCLUDED BECAUSE THERE ARE NOT ENOUGH DATA
  //   POINTS TO MAKE THE FIT FUNCTION WORK. ONLY TWO EXPONENTIAL
  //   WITHOUT BACKGROUND WORKS.
  //**********************************************************

  // THE EXPERIMENT NUMBER
  double experiment[10] = {17003, 17013, 17023, 17025, 17026, 17029, 17031,  17006, 17021};
  
  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT FUNCTION
  double storagefit_1expfit[10] = { storagefit003_1expfit, storagefit013_1expfit, storagefit023_1expfit, storagefit025_1expfit, storagefit026_1expfit, storagefit029A_1expfit, storagefit031_1expfit,storagefit006_1expfit,storagefit021_1expfit };
  
  // ERROR ASSOCIATED WITH THE STORAGE TIME FROM ONE FIT FUNCTION
  double storageErrfit_1expfit[10] = {  storageErrfit003_1expfit,storageErrfit013_1expfit, storageErrfit023_1expfit, storageErrfit025_1expfit, storageErrfit026_1expfit, storageErrfit029A_1expfit, storageErrfit031_1expfit , storageErrfit006_1expfit , storageErrfit021_1expfit};
  
  
  // TAU1 FROM THE TWO EXPONENTIAL FIT FUNCTION
  double tau1fit[10] = { fit003tau1,  fit013tau1, fit023tau1, fit025tau1, fit026tau1, fit029Atau1, fit031tau1, fit006tau1, fit021tau1};
  
  // ERROR ASSOCIATED WITH TAU1
   double tau1Errfit[10] = {fit003tau1Err, fit013tau1Err, fit023tau1Err, fit025tau1Err, fit026tau1Err, fit029Atau1Err, fit031tau1Err,  fit006tau1Err, fit021tau1Err};

  // TAU2 FROM THE TWO EXPONENTIAL FIT FUNCTION
  double tau2fit[10] = {fit003tau2, fit013tau2, fit023tau2, fit025tau2, fit026tau2, fit029Atau2,  fit031tau2, fit006tau2, fit021tau2};
  
  // ERROR ASSOCIATED WITH TAU2 
   double tau2Errfit[10] = {fit003tau2Err, fit013tau2Err, fit023tau2Err, fit025tau2Err, fit026tau2Err, fit029Atau2Err,  fit031tau2Err, fit006tau2Err, fit021tau2Err};

 
  TCanvas *c11 = new TCanvas("c11", "c11",900,500);
  TGraphErrors *grfit1exp = new TGraphErrors(9, experiment, storagefit_1expfit, 0 , storageErrfit_1expfit);
  grfit1exp -> SetTitle("Storage Time vs The Experiment Number, One Exponential Fit");
  grfit1exp -> GetXaxis()-> SetTitle("Experiment number" );
  grfit1exp -> GetYaxis()-> SetTitle("Storage Time (s)");
  grfit1exp -> SetMarkerStyle(25); 

  
  grfit1exp -> Draw("ap");
  
  TText *text1 = new TText();
  text1-> SetNDC();
  text1 -> SetTextFont(1);
  text1 -> SetTextColor(1);
  text1 -> SetTextSize(0.03);
  text1 -> SetTextAlign(22);
  text1 -> SetTextAngle(0);
  text1 -> DrawText(0.4, 0.3, "60s Irradiaiton Time");

  TCanvas *c12 = new TCanvas("c12", "c12",900,500);
  TGraphErrors *grtau1fit = new TGraphErrors(9, experiment, tau1fit, 0 , tau1Errfit);
  grtau1fit -> SetTitle("Tau1 vs The Experiment Number, Two Exponential Fit ");
  grtau1fit -> GetXaxis()-> SetTitle("Experiment number" );
  grtau1fit -> GetYaxis()-> SetTitle("Tau1 (s)");
  grtau1fit -> SetMarkerStyle(7); 


  grtau1fit-> Draw("ap");

  TCanvas *c13 = new TCanvas("c13", "c13",900,500);
  TGraphErrors *grtau2fit = new TGraphErrors(9, experiment, tau2fit, 0 , tau2Errfit);
  grtau2fit -> SetTitle("Tau2 vs The Experiment Number , Two Exponential Fit ");
  grtau2fit -> GetXaxis()-> SetTitle("Experiment number" );
  grtau2fit -> GetYaxis()-> SetTitle("Tau2 (s)");
  grtau2fit -> SetMarkerStyle(7); 


  grtau2fit -> Draw("ap");


  TCanvas *c14 = new TCanvas("c14", "c14",900,500);
  grfit1exp-> SetMarkerStyle(24);
  grtau2fit-> SetMarkerStyle(26);

 
  TLegend *leg5 = new TLegend (0.7,0.7, 0.9, 0.9);
  leg5 -> SetHeader("");
  leg5 -> AddEntry(grtau2fit, "Without Background, tau2", "p"); 
  leg5 -> AddEntry(grfit1exp, "Without Background, 1expfit", "p"); 

  grfit1exp -> Draw("ap");
  grtau2fit -> Draw("p");
 
  leg5-> Draw();

}
