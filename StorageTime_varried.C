// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS WITH
// VARRIED IRRADIATION TIME.
// IT IS STILL UNDER DEVELOPMENT.
// ********************************************************************

void StorageTime_varried(){
  gStyle->SetOptFit(0000);

  // OPENING ALL THE FILES
  TFile *fin1 = new TFile("outputTree_StorageTime_17004A.root","READ");
  TFile *fin2 = new TFile("outputTree_StorageTime_17009.root","READ");
  TFile *fin3 = new TFile("outputTree_StorageTime_17009A.root","READ");


  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree1 = (TTree*) fin1->Get("cycle_info");
  TTree *outputTree2 = (TTree*) fin2->Get("cycle_info");
  TTree *outputTree3 = (TTree*) fin3->Get("cycle_info");

 
  // RUN NUMBER FOR EACH FILE
  Int_t runNumber1;
  Int_t runNumber2;
  Int_t runNumber3;

  // CYCLE DELAY TIME FOR EACH FILE
  double delayTime1;
  double delayTime2;
  double delayTime3;

  // INTEGRAL OF THE UCN COUNTS FROM VALVE CLOSE 
  // TO OPEN FROM THE FIT FUNCTION
  double UCNIntegral1;
  double UCNIntegral2;
  double UCNIntegral3;
  
  // THE ERROR ASSOCIATED WITH THE INTEGRAL FROM
  // THE FIT FUNCTION
  double UCNIntegralErr1;
  double UCNIntegralErr2;
  double UCNIntegralErr3;

  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON
  double storagefit004A_1expfit = 0;
  double storagefit009_1expfit = 0;
  double storagefit009A_1expfit = 0;

  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION
  double storageErrfit004A_1expfit = 0;
  double storageErrfit009_1expfit = 0;
  double storageErrfit009A_1expfit = 0;


  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT
  // WITH CONSIDERING UCN COUNTS FROM THE HISTOGRAM
  // INTEGRAL
  double storagehist003_1expfit = 0;
  double storagehist009_1expfit = 0;
  double storagehist009A_1expfit = 0;


  // ERROR ASSOCIATED WITH THE STORAGE TIME
  // FROM THE ONE EXPONENTIAL FIT CONSIDERING
  // THE UCN COUNTS FROM THE HISTOGRAM INTEGRAL
  double storageErrhist004A_1expfit = 0;
  double storageErrhist009_1expfit = 0;
  double storageErrhist009A_1expfit = 0;



  // TOTAL UCN COUNTS COMING FROM THE HISTOGRAM INTEGRAL
  int HistIntegral1;
  int HistIntegral2;
  int HistIntegral3;

  
  // AVERAGE ISOPURE TEMPERATURE DURING IRRADIAITON
  double avets12Irrad_004A;
  double avets12Irrad_009;
  double avets12Irrad_009A;

  //MAXIMUM ISOPURE HELIUM DURING IRRADIAITON
  double maxts12Irrad_004A;
  double maxts12Irrad_009;
  double maxts12Irrad_009A;

  // MINIMUM ISOPURE HELIUM DURING IRRADIAITON

  double mints12Irrad_004A;
  double mints12Irrad_009;
  double mints12Irrad_009A;


// AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen_004A;
  double avets12ValveOpen_009;
  double avets12ValveOpen_009A;

  //MAXIMUM ISOPURE HELIUM DURING VALVE OPEN
  double maxts12ValveOpen_004A;
  double maxts12ValveOpen_009;
  double maxts12ValveOpen_009A;

  // MINIMUM ISOPURE HELIUM DURING VALVE OPEN

  double mints12ValveOpen_004A;
  double mints12ValveOpen_009;
  double mints12ValveOpen_009A;


  // BASELINE BEFORE IRRADIATION
  double baseline_004A;
  double baseline_009;
  double baseline_009A;

  // BASELINE ERROR (BEFORE IRRADIATION)
  
  double baselineErr_004A;
  double baselineErr_009;
  double baselineErr_009A;

  // BASELINE DURING IRRADIAITON

  double baselineIrrad_004A;
  double baselineIrrad_009;
  double baselineIrrad_009A;

  // IRRADIATION START TIME
  double irradStartTimes1;
  double irradStartTimes2;
  double irradStartTimes3;

  // CYCLE START TIMES
  double cycleStartTimes1;
  double cycleStartTimes2;
  double cycleStartTimes3;


  // SET THE BRANCH TO GET THE RUN NUMBER FROM THE TREE
  outputTree1 -> SetBranchAddress ("runNumber" , &runNumber1);
  outputTree2 -> SetBranchAddress ("runNumber" , &runNumber2);
  outputTree3 -> SetBranchAddress ("runNumber" , &runNumber3);

  // SET THE BRANCH TO GET THE CYCLE DELAY TIME FROM THE TREE
  outputTree1 -> SetBranchAddress ("cycleDelayTime", &delayTime1);
  outputTree2 -> SetBranchAddress ("cycleDelayTime", &delayTime2);
  outputTree3 -> SetBranchAddress ("cycleDelayTime", &delayTime3);
   
  // SET THE BRANCH ADDRESS TO GET THE UCNINTEGRAL (FROM THE FIT
  // FUNCTION) FROM THE TREE
  outputTree1 -> SetBranchAddress ("UCNIntegral", &UCNIntegral1);
  outputTree2 -> SetBranchAddress ("UCNIntegral", &UCNIntegral2);
  outputTree3 -> SetBranchAddress ("UCNIntegral", &UCNIntegral3);

  // SET THE BRANCH ADDRESS TO GET THE ERROR ASSOCIATED WITH THE
  // INTEGRAL FROM THE FIT FUNCTION
  outputTree1 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr1);
  outputTree2 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr2);
  outputTree3 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr3);

  // SET THE BRANCH ADDRESS TO GET THE HISTOGRAM INTEGRAL FROM THE TREE
  outputTree1 -> SetBranchAddress ("HistIntegral" , &HistIntegral1);
  outputTree2 -> SetBranchAddress ("HistIntegral" , &HistIntegral2);
  outputTree3 -> SetBranchAddress ("HistIntegral" , &HistIntegral3);
  // SET THE BRANCH ADDRESS TO GET THE AVERAGE ISOPURE HELIUM TEMPERATURE DURING VALVE OPEN
  outputTree1 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_004A);
  outputTree2 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_009);
  outputTree3 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_009A);

  // SET THE BRANCH TO GET THE IRRADIATION START TIMES
  outputTree1 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes1);
  outputTree2 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes2);
  outputTree3 -> SetBranchAddress ("irradStartTimes" , &irradStartTimes3);


  // SET THE BRANCH TO GET THE CYCLE START TIMES
  outputTree1 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes1);
  outputTree2 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes2);
  outputTree3 -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes3);


  // DEFINE ALL THE DELAY TIME ARRAYS
  Double_t delayTimeArray1[100] = 0;
  Double_t delayTimeArray2[100] = 0;
  Double_t delayTimeArray3[100] = 0;

  // DEFINE ARRAYS OF UCN INTEGRAL WHICH IS THE INTEGRAL
  // CALCUALTED FROM THE FIT FUNCTION 
  Double_t UCNIntegralArray1[100] = 0;
  Double_t UCNIntegralArray2[100] = 0;
  Double_t UCNIntegralArray3[100] = 0;

  // DEFINE ARRAYS OF INTEGRAL ERRORS CALCLULATED FROM
  // THE FIT FUNCTION
  Double_t UCNIntegralErrArray1[100] = 0;
  Double_t UCNIntegralErrArray2[100] = 0;
  Double_t UCNIntegralErrArray3[100] = 0;

  // DEFINE ARRAYS OF HISTOGRAM INTEGRALS
  Double_t HistIntegralArray1[100] = 0;
  Double_t HistIntegralArray2[100] = 0;
  Double_t HistIntegralArray3[100] = 0;
  

  // GET THE EVENTS FOR TCN17004A
  ULong64_t event1;
  event1 = (Double_t)outputTree1->GetEntries();

  // GET THE EVENTS FOR TCN17009
  ULong64_t event2;
  event2 = (Double_t)outputTree2->GetEntries();

  // GET THE EVENTS FOR TCN17009A
  ULong64_t event3;
  event3 = (Double_t)outputTree3->GetEntries();

  double irradTimeArray1[100];
  double irradTimeArray2[100];
  double irradTimeArray3[100];

  Int_t counts1 = 0;
  Int_t counts2 = 0;
  Int_t counts3 = 0;


 cout.setf(ios::fixed);

 // FOR TCN17004A
  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree1 -> GetEvent(j);
    if ( HistIntegral1 < 2000)
      continue;
    // cout << UCNIntegral1 << endl;
    UCNIntegralArray1[j] = UCNIntegral1;
    UCNIntegralErrArray1[j] = UCNIntegralErr1;
    delayTimeArray1[j] = delayTime1;
    HistIntegralArray1[j] = HistIntegral1;
    irradTimeArray1[j] = cycleStartTimes1 - irradStartTimes1;
    cout << irradTimeArray1[j] <<endl;
    counts1++;
  }

  // FOR TCN17009
  for (ULong64_t j = 0 ; j < event2 ; j++){
    outputTree2 -> GetEvent(j);
    UCNIntegralArray2[j] = UCNIntegral2;
    UCNIntegralErrArray2[j] = UCNIntegralErr2;
    delayTimeArray2[j] = delayTime2;
    HistIntegralArray2[j] = HistIntegral2;
    cout << HistIntegral2 << " " <<  endl;
    irradTimeArray2[j] = cycleStartTimes2 - irradStartTimes2;
    counts2++;
  }

  // FOR TCN17009A
  for (ULong64_t j = 0 ; j < event3 ; j++){
    outputTree3 -> GetEvent(j);
    //if ( UCNIntegralErr3 > 2000)
    // continue;
    UCNIntegralArray3[j] = UCNIntegral3;
    UCNIntegralErrArray3[j] = UCNIntegralErr3;
    delayTimeArray3[j] = delayTime3;
    HistIntegralArray3[j] = HistIntegral3;
    irradTimeArray3[j] = cycleStartTimes3 - irradStartTimes3;
    counts3++;
  }

 
  // ONE EXPONENTIAL FIT
  TF1 *fit1exp = new TF1 ("fit1exp" , "[0]*exp(-x/[1]) ", 0, 160);
  fit1exp -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit1exp -> SetParameters(100000,30);
  //fit1exp -> SetParLimits(0, 100000, 20000);
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
  // TCN17004A
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
  storagefit004A_1expfit =fit1exp->GetParameter(1);
  storageErrfit004A_1expfit =fit1exp->GetParError(1);


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr11 = new TGraph(counts1, delayTimeArray1, HistIntegralArray1);
  gr11 -> SetMarkerStyle(7);
  gr11 -> SetMarkerColor(2);
  gr11 -> GetXaxis()-> SetRangeUser(0, 120);
  //gr11 -> GetYaxis()-> SetRangeUser(1000, 60000);

  //gr1 -> Draw("ap");
  // gr11 -> Draw("p");
  // ******************************************************************
  // TCN17009
  // ******************************************************************
  // INTEGRAL FROM THE FIT
 
  TCanvas *c2 = new TCanvas("c2", "c2",900,500);
  //c2 -> SetLogy();
  
  TGraphErrors *gr2 = new TGraphErrors(counts2, delayTimeArray2, UCNIntegralArray2, 0 , UCNIntegralErrArray2);
  gr2 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr2 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr2 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr2 -> GetYaxis()-> SetRangeUser(1, 200000);
  gr2 -> SetMarkerStyle(2); 
  //gr2 -> SetMarkerColor(9);
  
  gr2 -> Fit(fit1exp,"+R");
  storagefit009_1expfit =fit1exp->GetParameter(1);
  storageErrfit009_1expfit =fit1exp->GetParError(1);
  


  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr22 = new TGraph(counts2, delayTimeArray2, HistIntegralArray2);
  gr22 -> SetMarkerStyle(2);
  gr22 -> SetMarkerColor(2);

   gr2 -> Draw("ap");
   //gr22 -> Draw("p");


  // ******************************************************************
  // TCN17009A
  // ******************************************************************
  // INTEGRAL FROM THE FIT
  
  TCanvas *c3 = new TCanvas("c3", "c3",900,500);
  //c3 -> SetLogy();
  
  TGraphErrors *gr3 = new TGraphErrors(counts3, delayTimeArray3, UCNIntegralArray3, 0 , UCNIntegralErrArray3);
  
  gr3 -> SetTitle("UCN Counts vs Valve Delay Time");
  gr3 -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr3 -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //gr3 -> GetYaxis()-> SetRangeUser(1000, 60000);
  gr3 -> SetMarkerStyle(4);

  gr3 -> Fit(fit1exp,"+R");
  storagefit009A_1expfit =fit1exp->GetParameter(1);
  storageErrfit009A_1expfit =fit1exp->GetParError(1);



  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr33 = new TGraph(counts3, delayTimeArray3, HistIntegralArray3);
  gr33 -> SetMarkerStyle(4);
  gr33 -> SetMarkerColor(2);

    gr3 -> Draw("ap");
    //gr33 -> Draw("p");
  
 
  //***********************************************************
  // COMMENTS:
  // - AFTER FURTHER INVESTIGATION, I HAVE TO EXCLUDE TCN17002
  //   AND IT IS BECASE THERE ARE MULTIPLE VALUES AT ONE DELAY
  //   TIME
  // - TCN17004A IS EXCLUDED BECAUSE THERE ARE NOT ENOUGH DATA
  //   POINTS TO MAKE THE FIT FUNCTION WORK. ONLY TWO EXPONENTIAL
  //   WITHOUT BACKGROUND WORKS.
  //**********************************************************

  // THE EXPERIMENT NUMBER
  double experiment[3] = { 17009, 17009A};
  
  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT FUNCTION
  double storagefit_1expfit[3] = { storagefit009_1expfit, storagefit009A_1expfit };
  
  // ERROR ASSOCIATED WITH THE STORAGE TIME FROM ONE FIT FUNCTION
  double storageErrfit_1expfit[3] = {  storageErrfit009_1expfit, storageErrfit009A_1expfit};
  
 
  TCanvas *c11 = new TCanvas("c11", "c11",900,500);
  TGraphErrors *grfit1exp = new TGraphErrors(2, experiment, storagefit_1expfit, 0 , storageErrfit_1expfit);
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
  // text1 -> DrawText(0.4, 0.3, "60s Irradiaiton Time");


}
