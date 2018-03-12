// *********************************************************************
// THIS SCRIPT ANALYZES ALL THE STORAGE LIFETIME MEASUREMENTS WITH
// 30s IRRADIATION TIME.
// ********************************************************************


void StorageTime_30sIrrad(){
  gStyle->SetOptFit(0000);

  // OPENING ALL THE FILES
  TFile *fin1 = new TFile("outputTree_StorageTime_17014.root","READ");

  // CREATE THE CYCLE INFORMATION FROM THE TREE
  TTree *outputTree1 = (TTree*) fin1->Get("cycle_info");

 
  // RUN NUMBER FOR EACH FILE
  Int_t runNumber1;

  // CYCLE DELAY TIME FOR EACH FILE
  double delayTime1;


  // INTEGRAL OF THE UCN COUNTS FROM VALVE CLOSE 
  // TO OPEN FROM THE FIT FUNCTION
  double UCNIntegral1;

  
  // THE ERROR ASSOCIATED WITH THE INTEGRAL FROM
  // THE FIT FUNCTION
  double UCNIntegralErr1;


  // STORAGE TIME FROM ONE EXPONENTIAL FIT
  // WITH THE UCN COUNTS FROM THE INTEGRAL
  // OF THE FIT FUNCITON
  double storagefit014_1expfit = 0;


  // ERROR FROM THE STORAGE TIME WITH ONE
  // EXPONENTIAL FIT WITH THE UCN COUNTS
  // FROM THE INTEGRAL OF THE FIT FUNCTION
  double storageErrfit014_1expfit = 0;


  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT
  // WITH CONSIDERING UCN COUNTS FROM THE HISTOGRAM
  // INTEGRAL
  double storagehist014_1expfit = 0;


  // ERROR ASSOCIATED WITH THE STORAGE TIME
  // FROM THE ONE EXPONENTIAL FIT CONSIDERING
  // THE UCN COUNTS FROM THE HISTOGRAM INTEGRAL
  double storageErrhist003_1expfit = 0;


  // TOTAL UCN COUNTS COMING FROM THE HISTOGRAM INTEGRAL
  int HistIntegral1;

  
  // AVERAGE ISOPURE TEMPERATURE DURING IRRADIAITON
  double avets12Irrad_014;


  //MAXIMUM ISOPURE HELIUM DURING IRRADIAITON
  double maxts12Irrad_014;


  // MINIMUM ISOPURE HELIUM DURING IRRADIAITON
  double mints12Irrad_014;

  // AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen_014;
  double avets12ValveOpenArray[100];

  //MAXIMUM ISOPURE HELIUM DURING VALVE OPEN
  double maxts12ValveOpen_014;


  // MINIMUM ISOPURE HELIUM DURING VALVE OPEN
  double mints12ValveOpen_014;

  // TS12 CHANGES DURING VALVE OPEN
  double ts12barValveOpenArray[100];

  // BASELINE BEFORE IRRADIATION
  double baseline_014;

  // BASELINE ERROR (BEFORE IRRADIATION)
  double baselineErr_014;

  // BASELINE DURING IRRADIAITON
  double baselineIrrad_014;
 

  // SET THE BRANCH TO GET THE RUN NUMBER FROM THE TREE
  outputTree1 -> SetBranchAddress ("runNumber" , &runNumber1);

  // SET THE BRANCH TO GET THE CYCLE DELAY TIME FROM THE TREE
  outputTree1 -> SetBranchAddress ("cycleDelayTime", &delayTime1);
   
  // SET THE BRANCH ADDRESS TO GET THE UCNINTEGRAL (FROM THE FIT
  // FUNCTION) FROM THE TREE
  outputTree1 -> SetBranchAddress ("UCNIntegral", &UCNIntegral1);

  // SET THE BRANCH ADDRESS TO GET THE ERROR ASSOCIATED WITH THE
  // INTEGRAL FROM THE FIT FUNCTION
  outputTree1 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr1);

  // SET THE BRANCH ADDRESS TO GET THE HISTOGRAM INTEGRAL FROM THE TREE
  outputTree1 -> SetBranchAddress ("HistIntegral" , &HistIntegral1);
  
  // SET THE BRANCH ADDRESS TO GET THE AVERAGE ISOPURE HELIUM TEMPERATURE DURING VALVE OPEN
  outputTree1 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen_014);

  // DEFINE ALL THE DELAY TIME ARRAYS
  Double_t delayTimeArray1[100] = 0;

  // DEFINE ARRAYS OF UCN INTEGRAL WHICH IS THE INTEGRAL
  // CALCUALTED FROM THE FIT FUNCTION 
  Double_t UCNIntegralArray1[100] = 0;

  // DEFINE ARRAYS OF INTEGRAL ERRORS CALCLULATED FROM
  // THE FIT FUNCTION
  Double_t UCNIntegralErrArray1[100] = 0;

  // DEFINE ARRAYS OF HISTOGRAM INTEGRALS
  Double_t HistIntegralArray1[100] = 0;

  // GET THE EVENTS FOR TCN17003
  ULong64_t event1;
  event1 = (Double_t)outputTree1->GetEntries();

  Int_t counts1 = 0;


 cout.setf(ios::fixed);
 
 // FOR TCN17014
  for (ULong64_t j = 0 ; j < event1 ; j++){
    outputTree1 -> GetEvent(j);
    //if ( HistIntegral1 < 2000)
    //continue;
    // cout << UCNIntegral1 << endl;
    UCNIntegralArray1[j] = UCNIntegral1;
    UCNIntegralErrArray1[j] = UCNIntegralErr1;
    delayTimeArray1[j] = delayTime1;
    HistIntegralArray1[j] = HistIntegral1;
    //cout << HistIntegral1 << " " << UCNIntegralArray1[j]<< " " << UCNIntegral1/HistIntegral1 << endl;
    ts12barValveOpenArray[j] = maxts12ValveOpen_014 - mints12ValveOpen_014;
    avets12ValveOpenArray[j] = avets12ValveOpen_014;
    counts1++;
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
  // TCN17014
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
  storagefit014_1expfit =fit1exp->GetParameter(1);
  storageErrfit014_1expfit =fit1exp->GetParError(1);

  // INTEGRAL FROM THE HISTOGRM
  TGraph *gr11 = new TGraph(counts1, delayTimeArray1, HistIntegralArray1);
  gr11 -> SetMarkerStyle(25);
  gr11 -> SetMarkerColor(2);
  gr11 -> GetXaxis()-> SetRangeUser(0, 120);
  //gr11 -> GetYaxis()-> SetRangeUser(1000, 60000);

  gr1 -> Draw("ap");
  gr11 -> Draw("p");
  

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
  double experiment[10] = {17014};
  
  // STORAGE TIME FROM THE ONE EXPONENTIAL FIT FUNCTION
  double storagefit_1expfit[10] = { storagefit014_1expfit};
  
  // ERROR ASSOCIATED WITH THE STORAGE TIME FROM ONE FIT FUNCTION
  double storageErrfit_1expfit[10] = {  storageErrfit014_1expfit};
  
 
  TCanvas *c11 = new TCanvas("c11", "c11",900,500);
  TGraphErrors *grfit1exp = new TGraphErrors(1, experiment, storagefit_1expfit, 0 , storageErrfit_1expfit);
  grfit1exp -> SetTitle("Storage Time vs The Experiment Number, One Exponential Fit");
  grfit1exp -> GetXaxis()-> SetTitle("Experiment number" );
  grfit1exp -> GetYaxis()-> SetTitle("Storage Time (s)");
  grfit1exp -> SetMarkerStyle(25); 

  
  grfit1exp -> Draw("ap");

  TCanvas *c12 = new TCanvas("c12", "c12",900,500);
  c12 -> SetLogy();
  TGraphErrors *gr2 = new TGraphErrors(counts1 ,avets12ValveOpenArray ,UCNIntegralArray1 , ts12barValveOpenArray , UCNIntegralErrArray1);
  gr2 -> SetTitle("UCN Counts vs Temperature");
  gr2 -> GetXaxis()-> SetTitle("Temperature (C)" );
  gr2 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2 -> SetMarkerStyle(25); 

  
  gr2 -> Draw("ap");
  
  TText *text1 = new TText();
  text1-> SetNDC();
  text1 -> SetTextFont(1);
  text1 -> SetTextColor(1);
  text1 -> SetTextSize(0.03);
  text1 -> SetTextAlign(22);
  text1 -> SetTextAngle(0);
  // text1 -> DrawText(0.4, 0.3, "30s Irradiaiton Time");

}
