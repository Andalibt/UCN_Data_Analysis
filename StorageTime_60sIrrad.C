// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS WITH
// 60s IRRADIATION TIME.
// ********************************************************************

void StorageTime_60sIrrad(){
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
  double storage1_1expfit = 0;
  double storage2_1expfit = 0;
  double storage3_1expfit = 0;
  double storage4_1expfit = 0;
  double storage5_1expfit = 0;
  double storage6_1expfit = 0;
  double storage7_1expfit = 0;
  double storage8_1expfit = 0;
  double storage9_1expfit = 0;
  double storage10_1expfit = 0;

  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION
  double storageErr1_1expfit = 0;
  double storageErr2_1expfit = 0;
  double storageErr3_1expfit = 0;
  double storageErr4_1expfit = 0;
  double storageErr5_1expfit = 0;
  double storageErr6_1expfit = 0;
  double storageErr7_1expfit = 0;
  double storageErr8_1expfit = 0;
  double storageErr9_1expfit = 0;
  double storageErr10_1expfit = 0;

  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT
  // WITH CONSIDERING UCN COUNTS FROM THE HISTOGRAM
  // INTEGRAL
  double storage11_1expfit = 0;
  double storage22_1expfit = 0;
  double storage33_1expfit = 0;
  double storage44_1expfit = 0;
  double storage55_1expfit = 0;
  double storage66_1expfit = 0;
  double storage77_1expfit = 0;
  double storage88_1expfit = 0;
  double storage99_1expfit = 0;
  double storage1010_1expfit = 0;

  // ERROR ASSOCIATED WITH THE STORAGE TIME
  // FROM THE ONE EXPONENTIAL FIT CONSIDERING
  // THE UCN COUNTS FROM THE HISTOGRAM INTEGRAL
  double storageErr11_1expfit = 0;
  double storageErr22_1expfit = 0;
  double storageErr33_1expfit = 0;
  double storageErr44_1expfit = 0;
  double storageErr55_1expfit = 0;
  double storageErr66_1expfit = 0;
  double storageErr77_1expfit = 0;
  double storageErr88_1expfit = 0;
  double storageErr99_1expfit = 0;
  double storageErr1010_1expfit = 0;



  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON
  double storage1_2expfit = 0;
  double storage2_2expfit = 0;
  double storage3_2expfit = 0;
  double storage4_2expfit = 0;
  double storage5_2expfit = 0;
  double storage6_2expfit = 0;
  double storage7_2expfit = 0;
  double storage8_2expfit = 0;
  double storage9_2expfit = 0;
  double storage10_2expfit = 0;

  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION
  double storageErr1_2expfit = 0;
  double storageErr2_2expfit = 0;
  double storageErr3_2expfit = 0;
  double storageErr4_2expfit = 0;
  double storageErr5_2expfit = 0;
  double storageErr6_2expfit = 0;
  double storageErr7_2expfit = 0;
  double storageErr8_2expfit = 0;
  double storageErr9_2expfit = 0;
  double storageErr10_2expfit = 0;

  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT
  // WITH CONSIDERING UCN COUNTS FROM THE HISTOGRAM
  // INTEGRAL
  double storage11_2expfit = 0;
  double storage22_2expfit = 0;
  double storage33_2expfit = 0;
  double storage44_2expfit = 0;
  double storage55_2expfit = 0;
  double storage66_2expfit = 0;
  double storage77_2expfit = 0;
  double storage88_2expfit = 0;
  double storage99_2expfit = 0;
  double storage1010_2expfit = 0;

  // ERROR ASSOCIATED WITH THE STORAGE TIME
  // FROM THE ONE EXPONENTIAL FIT CONSIDERING
  // THE UCN COUNTS FROM THE HISTOGRAM INTEGRAL
  double storageErr11_2expfit = 0;
  double storageErr22_2expfit = 0;
  double storageErr33_2expfit = 0;
  double storageErr44_2expfit = 0;
  double storageErr55_2expfit = 0;
  double storageErr66_2expfit = 0;
  double storageErr77_2expfit = 0;
  double storageErr88_2expfit = 0;
  double storageErr99_2expfit = 0;
  double storageErr1010_2expfit = 0;




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



  Int_t counts1 = 1;
  Int_t counts2 = 1;
  Int_t counts3 = 1;
  Int_t counts4 = 1;
  Int_t counts5 = 1;
  Int_t counts6 = 1;
  Int_t counts7 = 1;
  Int_t counts8 = 1;
  Int_t counts9 = 1;
  Int_t counts10 = 1;


 cout.setf(ios::fixed);

 // FOR TCN17003
  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree1 -> GetEvent(j);
    // if ( HistIntegral1 < 50)
    //   continue;
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
  /*for (ULong64_t j = 0 ; j < event9 ; j++){
    outputTree9 -> GetEvent(j);
    if ( UCNIntegral9 < 1800  )
      continue;
    //cout << HistIntegral9 << " " << UCNIntegral9 << endl;
    UCNIntegralArray9[j] = UCNIntegral9;
    UCNIntegralErrArray9[j] = UCNIntegralErr9;
    delayTimeArray9[j] = delayTime9;
    HistIntegralArray9[j] = HistIntegral9;
    counts9++;
  }
  */
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
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 170);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(20000,30);
  //fit1exp -> SetParLimits(0, 10000, 60000);
  //fit1exp -> SetParLimits(1, 0, 40);
  

  // TWO EXPONENTIAL FIT

  double tau1, tau2;
  double tau1Err, tau2Err;
  double tauSum = tau1+tau2;
 
  TF1 *fit2exp = new TF1 ("fit2exp" , "[0]*exp(-x/[1])*exp(-x/[2])", 0, 180);
  fit2exp -> SetParNames("Amplitude" , "Tau1", "Tau2");
  fit2exp -> SetParameters(20000, 20. , 20. );
  //  fit2exp -> SetParLimits(0, 20000, 60000);
  //fit2exp -> SetParLimits(1, 0, 10);
  //fit2exp -> SetParLimits(2, 0, 10);

  //tau1 = fit2exp -> GetParameter(1);
  //tau2 = fit2exp -> GetParameter(2);
  // tau1Err = fit2exp -> GetParError(1);
   //tau2Err = fit2exp -> GetParError(2);
  //tauSum = tau1+tau2;

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
  gr1 -> GetXaxis()-> SetRangeUser(0, 180);
  gr1 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr1 -> SetMarkerStyle(7);
  //gr1 -> SetMarkerColor(1);
  gr1 -> Fit(fit1exp, "0");
  gr1 -> Fit(fit2exp, "0");

  storage1_1expfit =fit1exp->GetParameter(1);
  storageErr1_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;
  
  storage1_2expfit = tau1*tau2/(tau1+tau2);
  //storageErr1_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  //storageErr1_2expfit = tauSum * sqrt ( (tau1Err/tau1)* (tau1Err/tau1)+  (tau2Err/tau2)*(tau2Err/tau2)+ (tau1Err*tau1Err + tau2Err*tau2Err)/(tauSum*tauSum));

  // cout << storage1_2expfit << " " << storageErr1_2expfit << endl;
  //  cout << storage1_1expfit << " " << storageErr1_1expfit << endl;
  // cout << tau1 << " " << tau2 << endl;
  //cout << tau1Err << "  " << tau2Err << endl;

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr11 = new TGraph(counts1, delayTimeArray1, HistIntegralArray1);
  gr11 -> SetMarkerStyle(7);
  gr11 -> SetMarkerColor(2);
  gr11 -> GetXaxis()-> SetRangeUser(0, 180);
  gr11 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr11 -> Fit(fit1exp, "0");
  gr11 -> Fit(fit2exp, "0");

  storage11_1expfit =fit1exp->GetParameter(1);
  storageErr11_1expfit =fit2exp->GetParError(1);
  fit1exp->SetLineColor(1);

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;

  storage11_2expfit = (tau1*tau2)/(tau1+tau2);
  //  storageErr11_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  cout << storage11_2expfit << " " << storageErr11_2expfit << endl;
  cout << storage11_1expfit << " " << storageErr11_1expfit << endl;

  
  // ******************************************************************
  // TCN17013
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr2 = new TGraphErrors(counts2, delayTimeArray2, UCNIntegralArray2, 0 , UCNIntegralErrArray2);
  gr2 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr2 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr2 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr2 -> SetMarkerStyle(2); 
  //gr2 -> SetMarkerColor(9);
  gr2 -> Fit(fit1exp,"1");
  //gr2 -> Fit(fit2exp, "0");
  storage2_1expfit =fit1exp->GetParameter(1);
  storageErr2_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage2_2expfit = tau1*tau2/(tau1+tau2);
  storageErr2_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr22 = new TGraph(counts2, delayTimeArray2, HistIntegralArray2);
  gr22 -> SetMarkerStyle(2);
  gr22 -> SetMarkerColor(2);
  gr22 -> Fit(fit1exp,"0");
  gr22 -> Fit(fit2exp, "0");
  storage22_1expfit =fit1exp->GetParameter(1);
  storageErr22_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage22_2expfit = tau1*tau2/(tau1+tau2);
  storageErr22_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  

  // ******************************************************************
  // TCN17023
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr3 = new TGraphErrors(counts3, delayTimeArray3, UCNIntegralArray3, 0 , UCNIntegralErrArray3);
  
  gr3 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr3 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr3 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr3 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr3 -> SetMarkerStyle(3);
  //gr3 -> SetMarkerColor(3);
  gr3 -> Fit(fit1exp,"0");
  gr3 -> Fit(fit2exp, "0");
  storage3_1expfit =fit1exp->GetParameter(1);
  storageErr3_1expfit =fit1exp->GetParError(1);
  //fit1exp ->SetLineColor(1);



  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage3_2expfit = tau1*tau2/(tau1+tau2);
  storageErr3_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr33 = new TGraph(counts3, delayTimeArray3, HistIntegralArray3);
  gr33 -> SetMarkerStyle(3);
  gr33 -> SetMarkerColor(2);
  gr33 -> Fit(fit1exp,"0");
  gr33 -> Fit(fit2exp, "0");
  storage33_1expfit =fit1exp->GetParameter(1);
  storageErr33_1expfit =fit1exp->GetParError(1);
  fit1exp ->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage33_2expfit = tau1*tau2/(tau1+tau2);
  storageErr33_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  

  
  // ******************************************************************
  // TCN17025
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr4 = new TGraphErrors(counts4, delayTimeArray4, UCNIntegralArray4, 0 , UCNIntegralErrArray4);
  gr4 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr4 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr4 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr4 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr4 -> SetMarkerStyle(4);
  //gr4 -> SetMarkerColor(4);
  gr4 -> Fit(fit1exp,"0");
  gr4 -> Fit(fit2exp, "0");
  storage4_1expfit =fit1exp->GetParameter(1);
  storageErr4_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage4_2expfit = tau1*tau2/(tau1+tau2);
  storageErr4_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr44 = new TGraph(counts4, delayTimeArray4, HistIntegralArray4);
  gr44 -> SetMarkerStyle(4);
  gr44 -> SetMarkerColor(2);
  gr44 -> Fit(fit1exp,"0");
  gr44 -> Fit(fit2exp, "0");
  storage44_1expfit =fit1exp->GetParameter(1);
  storageErr44_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage44_2expfit = tau1*tau2/(tau1+tau2);
  storageErr44_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  
  
  // ******************************************************************
  // TCN17026
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr5 = new TGraphErrors(counts5, delayTimeArray5, UCNIntegralArray5, 0 , UCNIntegralErrArray5);

  
  gr5 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr5 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr5 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr5 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr5 -> SetMarkerStyle(5);
  //gr5 -> SetMarkerColor(5);
  gr5 -> Fit(fit1exp,"0");
  gr5 -> Fit(fit2exp, "0");
  storage5_1expfit=fit1exp->GetParameter(1);
  storageErr5_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage5_2expfit = tau1*tau2/(tau1+tau2);
  storageErr5_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr55 = new TGraph(counts5, delayTimeArray5, HistIntegralArray5);
  gr55 -> SetMarkerStyle(5);
  gr55 -> SetMarkerColor(2);
  gr55 -> Fit(fit1exp,"0");
  gr55 -> Fit(fit2exp, "0");
  storage55_1expfit = fit1exp->GetParameter(1);
  storageErr55_1expfit = fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage55_2expfit = tau1*tau2/(tau1+tau2);
  storageErr55_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  
  // ******************************************************************
  // TCN17029A
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr6 = new TGraphErrors(counts6, delayTimeArray6, UCNIntegralArray6, 0 , UCNIntegralErrArray6);

  gr6 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr6 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr6 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr6 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr6 -> SetMarkerStyle(26);
  //gr6 -> SetMarkerColor(6);
  gr6 -> Fit(fit1exp,"0");
  gr6 -> Fit(fit2exp, "0" );
  storage6_1expfit =fit1exp->GetParameter(1);
  storageErr6_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage6_2expfit = tau1*tau2/(tau1+tau2);
  storageErr6_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr66 = new TGraph(counts6, delayTimeArray6, HistIntegralArray6);
  gr66 -> SetMarkerStyle(26);
  gr66 -> SetMarkerColor(2);
  gr66 -> Fit(fit1exp,"1");
  gr66 -> Fit(fit2exp, "0" );
  storage66_1expfit =fit1exp->GetParameter(1);
  storageErr66_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage66_2expfit = tau1*tau2/(tau1+tau2);
  storageErr66_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  


  // ******************************************************************
  // TCN17031
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr7 = new TGraphErrors(counts7, delayTimeArray7, UCNIntegralArray7, 0 , UCNIntegralErrArray7);

  gr7 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr7 -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr7 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr7 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr7 -> SetMarkerStyle(25);
  //gr7 -> SetMarkerColor(7);
  gr7 -> Fit(fit1exp,"0");
  gr7 -> Fit(fit2exp, "0");
  storage7_1expfit =fit1exp->GetParameter(1);
  storageErr7_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  gr7 -> GetXaxis()-> SetRangeUser(1, 180);
  gr7 -> GetYaxis()-> SetRangeUser(1000, 70000);


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage7_2expfit = tau1*tau2/(tau1+tau2);
  storageErr7_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr77 = new TGraph(counts7, delayTimeArray7, HistIntegralArray7); 
  gr77 -> SetMarkerStyle(25);
  gr77 -> SetMarkerColor(2);
  gr77 -> Fit(fit1exp,"0");
  gr77 -> Fit(fit2exp , "0");
  storage77_1expfit =fit1exp->GetParameter(1);
  storageErr77_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage77_2expfit = tau1*tau2/(tau1+tau2);
  storageErr77_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  
  // ******************************************************************
  // TCN17002
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  TGraphErrors *gr8 = new TGraphErrors(counts8, delayTimeArray8, UCNIntegralArray8, 0 , UCNIntegralErrArray8);

  
  gr8 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr8 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr8 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr8 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr8 -> SetMarkerStyle(33); 
  //gr8 -> SetMarkerColor(9);
  gr8 -> Fit(fit1exp,"0");
  gr8 -> Fit(fit2exp, "0");
  storage8_1expfit =fit1exp->GetParameter(1);
  storageErr8_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage8_2expfit = tau1*tau2/(tau1+tau2);
  storageErr8_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr88 = new TGraph(counts8, delayTimeArray8, HistIntegralArray8);
  gr88 -> SetMarkerStyle(33);
  gr88 -> SetMarkerColor(2);
  gr88 -> Fit(fit1exp,"0");
  gr88 -> Fit(fit2exp, "0");
  storage88_1expfit =fit1exp->GetParameter(1);
  storageErr88_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage88_2expfit = tau1*tau2/(tau1+tau2);
  storageErr88_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  

  // ******************************************************************
  // TCN17006
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  /*
  TGraphErrors *gr9 = new TGraphErrors(counts9, delayTimeArray9, UCNIntegralArray9, 0 , UCNIntegralErrArray9);
  
  gr9 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr9 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr9 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr9 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr9 -> SetMarkerStyle(21); 
  //gr9 -> SetMarkerColor(9);
  gr9 -> Fit(fit1exp,"0");
  gr9 -> Fit(fit2exp, "0");
  storage9_1expfit =fit1exp->GetParameter(1);
  storageErr9_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage9_2expfit = tau1*tau2/(tau1+tau2);
  storageErr9_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr99 = new TGraph(counts9, delayTimeArray9, HistIntegralArray9);
  gr99 -> SetMarkerStyle(21);
  gr99 -> SetMarkerColor(2);
  gr99 -> Fit(fit1exp,"0");
  gr99 -> Fit(fit2exp, "0");
  storage99_1expfit =fit1exp->GetParameter(1);
  storageErr99_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;


  storage99_2expfit = tau1*tau2/(tau1+tau2);
  storageErr99_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  */
  // ******************************************************************
  // TCN17021
  // ******************************************************************

  // INTEGRAL FROM THE FIT
  TGraphErrors *gr10 = new TGraphErrors(counts10, delayTimeArray10, UCNIntegralArray10, 0 , UCNIntegralErrArray10);

  
  gr10 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr10 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr10 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr10 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr10 -> SetMarkerStyle(22); 
  //gr10 -> SetMarkerColor(9);
  gr10 -> Fit(fit1exp,"0");
  gr10 -> Fit(fit2exp, "0");
  storage10_1expfit =fit1exp->GetParameter(1);
  storageErr10_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);


  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage10_2expfit = tau1*tau2/(tau1+tau2);
  storageErr10_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);  

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr1010 = new TGraph(counts10, delayTimeArray10, HistIntegralArray10);
  gr1010 -> SetMarkerStyle(22);
  gr1010 -> SetMarkerColor(2);
  gr1010 -> Fit(fit1exp,"0");
  gr1010 -> Fit(fit2exp, "0");
  storage1010_1expfit =fit1exp->GetParameter(1);
  storageErr1010_1expfit =fit1exp->GetParError(1);
  fit1exp->SetLineColor(1);
  

  tau1 = fit2exp -> GetParameter(1);
  tau2 = fit2exp -> GetParameter(2);
  tau1Err = fit2exp -> GetParError(1);
  tau2Err = fit2exp -> GetParError(2);
  tauSum = tau1+tau2;



  storage1010_2expfit = tau1*tau2/(tau1+tau2);
  storageErr1010_2expfit = sqrt ((tau2*tau2/(tauSum*tauSum))*tau1Err + (tau1*tau1/(tauSum*tauSum))*tau2Err);
  
  TLegend *leg = new TLegend (0.65,0.55, 0.84, 0.87);
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

  
 
 
  gr1 -> Draw("ap");
  gr2 -> Draw("p");
  gr3 -> Draw("p");
  gr4 -> Draw("p");
  gr5 -> Draw("p");
  gr6 -> Draw("p");
   gr7 -> Draw("p");
  gr8 -> Draw("p");
  // gr9 -> Draw("p");
  gr10 -> Draw("p");
  gr11 -> Draw("p");
  gr22 -> Draw("p");
  gr33 -> Draw("p");
  gr44 -> Draw("p");
  gr55 -> Draw("p");
  gr66 -> Draw("p");
  gr77 -> Draw("p");
  gr88 -> Draw("p");
  // gr99 -> Draw("p");
  gr1010 -> Draw("p");
  leg -> Draw();
 
  
  TText *text1 = new TText();
  text1-> SetNDC();
  text1 -> SetTextFont(1);
  text1 -> SetTextColor(1);
  text1 -> SetTextSize(0.03);
  text1 -> SetTextAlign(22);
  text1 -> SetTextAngle(0);
  // text1 -> DrawText(0.6, 0.3, "60s Irradiaiton Time");
  
  
  TText *text2 = new TText();
  text2-> SetNDC();
  text2 -> SetTextFont(1);
  text2 -> SetTextColor(2);
  text2 -> SetTextSize(0.03);
  text2 -> SetTextAlign(22);
  text2 -> SetTextAngle(0);
  // text2 -> DrawText(0.6, 0.4, "Counts From Histogram Integral");
  

  /*

  // THE EXPERIMENT NUMBER
  double experiment[10] = {17003, 17013, 17023, 17025, 17026, 17029, 17031, 17002, 17006, 17021};
  
  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT FUNCTION
  double storage_1expfit[10] = { storage1_1expfit, storage2_1expfit, storage3_1expfit, storage4_1expfit, storage5_1expfit, storage6_1expfit, storage7_1expfit,storage9_1expfit,storage8_1expfit,storage10_1expfit };
  
  // ERROR ASSOCIATED WITH THE STORAGE TIME FROM ONE FIT FUNCTION
  double storageErr_1expfit[10] = { storageErr1_1expfit, storageErr2_1expfit, storageErr3_1expfit, storageErr4_1expfit, storageErr5_1expfit, storageErr6_1expfit, storageErr7_1expfit , storageErr8_1expfit , storageErr9_1expfit , storageErr10_1expfit};
  
  // STORAGE TIME FROM ONE EXPONENTIAL FIT FROM THE COUNTS OF HISTOGRAM
  double storageHist_1expfit[10] = { storage11_1expfit, storage22_1expfit, storage33_1expfit, storage44_1expfit, storage55_1expfit, storage66_1expfit, storage77_1expfit ,  storage88_1expfit ,  storage99_1expfit ,  storage1010_1expfit};
  
  // ERROR ASSOCIATED WITH THE STRAGE TIME FROM ONE EXPONENTIAL FIT FROM THE HISTOGRAM COUNTS
  double storageErrHist_1expfit[10] = { storageErr11_1expfit, storageErr22_1expfit, storageErr33_1expfit, storageErr44_1expfit, storageErr55_1expfit, storageErr66_1expfit, storageErr77_1expfit ,  storageErr88_1expfit ,  storageErr99_1expfit,  storageErr1010_1expfit};
  
  // STORAGE TIME FROM THE TWO EXPONENTIAL FIT FUNCTION
  double storage_2expfit[10] = { storage1_2expfit, storage2_2expfit, storage3_2expfit, storage4_2expfit, storage5_2expfit, storage6_2expfit, storage7_2expfit,storage9_2expfit,storage8_2expfit,storage10_2expfit };
  
  // ERROR ASSOCIATED WITH THE STORAGE TIME FROM TWO FIT FUNCTION
  double storageErr_2expfit[10] = { storageErr1_2expfit, storageErr2_2expfit, storageErr3_2expfit, storageErr4_2expfit, storageErr5_2expfit, storageErr6_2expfit, storageErr7_2expfit , storageErr8_2expfit , storageErr9_2expfit , storageErr10_2expfit};
  
  // STORAGE TIME FROM TWO EXPONENTIAL FIT FROM THE COUNTS OF HISTOGRAM
  double storageHist_2expfit[10] = { storage11_2expfit, storage22_2expfit, storage33_2expfit, storage44_2expfit, storage55_2expfit, storage66_2expfit, storage77_2expfit ,  storage88_2expfit ,  storage99_2expfit ,  storage1010_2expfit};
  
  // ERROR ASSOCIATED WITH THE STRAGE TIME FROM TWO EXPONENTIAL FIT FROM THE HISTOGRAM COUNTS
  double storageErrHist_2expfit[10] = { storageErr11_2expfit, storageErr22_2expfit, storageErr33_2expfit, storageErr44_2expfit, storageErr55_2expfit, storageErr66_2expfit, storageErr77_2expfit ,  storageErr88_2expfit ,  storageErr99_2expfit,  storageErr1010_2expfit};
  
  TCanvas *c2 = new TCanvas("c2", "c2",900,500);
  
  TGraphErrors *gr100 = new TGraphErrors(10, experiment, storage_1expfit, 0 , storageErr_1expfit);
  gr100 -> SetTitle("Storage Time vs The Experiment Number");
  gr100 -> GetXaxis()-> SetTitle("Experiment number" );
  gr100 -> GetYaxis()-> SetTitle("Storage Time (s)");
  gr100 -> SetMarkerStyle(7); 
  
  TGraphErrors *gr200 = new TGraphErrors(10, experiment, storageHist_1expfit, 0 ,storageErrHist_1expfit);
  gr200 -> SetTitle("Storage Time vs The Experiment Number");
  gr200 -> GetXaxis()-> SetTitle("Experiment number" );
  gr200 -> GetYaxis()-> SetTitle("Storage Time (s)");
  gr200 -> SetMarkerStyle(25);
  gr200 -> SetMarkerColor(1); 
  
  TGraphErrors *gr100_2exp = new TGraphErrors(10, experiment, storage_2expfit, 0 , storageErr_2expfit);
  gr100_2exp -> SetTitle("Storage Time vs The Experiment Number");
  gr100_2exp -> GetXaxis()-> SetTitle("Experiment number" );
  gr100_2exp -> GetYaxis()-> SetTitle("Storage Time (s)");
  gr100_2exp -> SetMarkerStyle(7); 
  gr100_2exp -> SetMarkerStyle(22);
  TGraphErrors *gr200_2exp = new TGraphErrors(10, experiment, storageHist_2expfit, 0 ,storageErrHist_2expfit);
  gr200_2exp -> SetTitle("Storage Time vs The Experiment Number");
  gr200_2exp -> GetXaxis()-> SetTitle("Experiment number" );
  gr200_2exp -> GetYaxis()-> SetTitle("Storage Time (s)");
  gr200_2exp -> SetMarkerStyle(21);
  gr200_2exp -> SetMarkerColor(1); 

  TLegend *leg2 = new TLegend (0.7,0.7, 0.9, 0.9);
  leg2 -> SetHeader("");
  leg2 -> AddEntry(gr100, "One Exp, Fit Function", "p"); 
  leg2 -> AddEntry(gr200, "One Exp, Hist Counts", "p");
  leg2 -> AddEntry(gr100_2exp, "Two Exp, Fit Function", "p"); 
  leg2 -> AddEntry(gr200_2exp, "Two Exp, Hist Counts", "p"); 

  //gr200->Draw("ap");
  //gr100 -> Draw("p");
  gr100_2exp -> Draw("ap");
  gr200_2exp -> Draw("p");
  leg2 -> Draw();*/
  
  /*  cout << "*****************************************" << endl;
  cout << "# OF POINTS: " << counts3 << endl;
  cout << "FOR ONE EXPONENTIAL FIT" << endl;
  cout << storage3_1expfit << " " << storage33_1expfit << endl;
  cout  << storageErr3_1expfit << " "<< storageErr33_1expfit << endl;

  cout << "FOR TWO EXPONENTIAL FIT" << endl;
  cout << storage3_2expfit << " " << storage33_2expfit << endl;
  cout  << storageErr3_1expfit << " "<< storageErr33_2expfit << endl;*/
 
  cout << "FOR TCN17003" << endl;
  cout << storage1_1expfit << " " << storage1_2expfit << endl;
  cout << storage11_1expfit << " " << storage11_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17013" << endl;
  cout <<  storage2_1expfit << " " << storage2_2expfit << endl;
  cout << storage22_1expfit << " " << storage22_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17023" << endl;
  cout <<  storage3_1expfit << " " << storage3_2expfit << endl;
  cout << storage33_1expfit << " " << storage33_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17025" << endl;
  cout <<  storage4_1expfit << " " << storage4_2expfit << endl;
  cout << storage44_1expfit << " " << storage44_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17026" << endl;
  cout <<  storage5_1expfit << " " << storage5_2expfit << endl;
  cout << storage55_1expfit << " " << storage55_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17029A" << endl;
  cout <<  storage6_1expfit << " " << storage6_2expfit << endl;
  cout << storage66_1expfit << " " << storage66_2expfit << endl;



  cout << "********************************" << endl;
  cout << "FOR TCN17031" << endl;
  cout <<  storage7_1expfit << " " << storage7_2expfit << endl;
  cout << storage77_1expfit << " " << storage77_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17002" << endl;
  cout <<  storage8_1expfit << " " << storage8_2expfit << endl;
  cout << storage88_1expfit << " " << storage88_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17006" << endl;
  cout <<  storage9_1expfit << " " << storage9_2expfit << endl;
  cout << storage99_1expfit << " " << storage99_2expfit << endl;


  cout << "********************************" << endl;
  cout << "FOR TCN17021" << endl;
  cout <<  storage10_1expfit << " " << storage10_2expfit << endl;
  cout << storage1010_1expfit << " " << storage1010_2expfit << endl;

}
