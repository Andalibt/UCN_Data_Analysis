//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17002.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17003_Taraneh_edit_ver1(){
  gStyle->SetOptFit(1111);
  // READ THE TREE
  
  TFile *fin = new TFile("outputTree_StorageTime_17003.root","READ");
  if ( fin->IsOpen() ){
    printf("File opened successfully\n");
  }
  if (fin->IsZombie()) {
    cout << "Error opening file" << endl;
    exit(-1);
  }
  
  TTree *outputTree = (TTree*) fin->Get("cycle_info");
  
  ULong64_t events;
  events = (Double_t)outputTree->GetEntries();
  const Int_t counts = 30;
  
  double irradStartTimes;
  double cycleStartTimes;
  double delayTime;
  Int_t runNumber;
  double UCNIntegral;
  double UCNIntegralErr;
  double AVE_TS12_VALVEOPEN;
  double irradTime;
  double Amplitude;
  double FallTime;
  double RiseTime;
  double AmplitudeErr;
  double FallTimeErr;
  double RiseTimeErr;
  double AVE_B1CUR;
  int HistIntegral;
  
  Double_t delayTimeArray[counts];
  Double_t UCNIntegralArray[counts];
  Double_t UCNIntegralErrArray[counts];
  Double_t HistIntegralArray[counts];

  outputTree -> SetBranchAddress ("runNumber" , &runNumber);
  outputTree -> SetBranchAddress ("irradStartTimes", &irradStartTimes); 
  outputTree -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes);
  outputTree -> SetBranchAddress ("cycleDelayTime", &delayTime);
  outputTree -> SetBranchAddress ("UCNIntegral", &UCNIntegral);
  outputTree -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr);
  outputTree -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &AVE_TS12_VALVEOPEN);
  outputTree -> SetBranchAddress ("Amplitude" , &Amplitude);
  outputTree -> SetBranchAddress ("FallTime" , &FallTime);
  outputTree -> SetBranchAddress ("RiseTime" , &RiseTime);
  outputTree -> SetBranchAddress ("AmplitudeErr" , &AmplitudeErr);
  outputTree -> SetBranchAddress ("FallTimeErr" , &FallTimeErr);
  outputTree -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr);
  outputTree -> SetBranchAddress ("AVE_B1CUR" , &AVE_B1CUR);
  outputTree -> SetBranchAddress ("HistIntegral" , &HistIntegral);

  // HISTOGRAM TO SHOW TOTOAL UCN (ONLY) COUNTS VS THE VALVE DELAY TIME
  TH2* StorageTime = new TH2F("StorageTime", "Counts vs Delay Time", 1000, 0., 180. , 1000,  0., 200000);
  // HISTOGRAM TO SHOW THE TOTAL UCN (ONLY) COUNTS VS THE ISOPURE TEMPERATURE
  TH2* StorageTemp = new TH2F("StorageTemp", "Counts vs Temperture", 1000, 0.83, 0.95 , 1000,  0., 200000);
  // HISTOGRA TO SHOW THE TOTAL UCN (ONLY) COUNTS VS THE RUN NUMBER
  TH2* UCN = new TH2F("UCN", "UCN vs run#", 1000, 540, 550 , 1000,  0., 200000);
  // HISTOGRAM TO SHOW THE AVERAGE ISOPURE TEMPERATURE VS THE RUN NUMBER
  TH2* runTemp = new TH2F("UCN", "Temperature vs run#", 1000, 540, 550,1000, 0.83, 0.95);
  // HISTOGRAM TO SHOW THE TOTAL IRRADIATION TIME VS THE AVERAGE ISOPURE TEMPERATURE
  TH2* IrradTemp = new TH2F("UCN", "Irradiation Time vs Temperature", 1000, 30, 200 , 1000, 0.83, 0.95);
  // HISTOGRAM TO SHOW THE AVERAGE ISOPURE TEMPERATURE VS BEAM CURRENT
  TH2* TempBeam = new TH2F("UCN", "Temperature vs Beam Current", 1000, 0.83, 0.95 , 1000, 99, 109);
  // HISTOGRAM TO SHOW THE THE TOTAL UCN (ONLY) COUNTS VS AVERAGE BEAM CURRENT
  TH2* UCNBeam = new TH2F("UCN", "UCN Counts vs Beam Current" , 1000, 99, 109 , 1000 , 0 , 200000 );

  TF1 *Func1 = new TF1("Func1", "[0]*(1-exp(-x/[1]))*exp(-x/[2])", 0, 180);
  double integralArray[26];
  double integralErrArray[26];
  
  cout.setf(ios::fixed);
  for (ULong64_t j = 0 ; j < events ; j++){
    outputTree -> GetEvent(j);
    if (HistIntegral < 1000)
      continue;
    Func1 -> SetParameters(Amplitude, RiseTime, FallTime);
    Func1 -> SetParError(0, AmplitudeErr);
    Func1 -> SetParError(1, RiseTimeErr);
    Func1 -> SetParError(2, FallTimeErr);
    integralArray[j] = Func1-> Integral(0,170);
    // integralErrArray[j] = Func1 -> IntegralError(0,170);
    // cout << integralArray[j] << " " << UCNIntegral << " " << UCNIntegral/integralArray[j] << endl;
    irradTime = cycleStartTimes - irradStartTimes;
    // cout << (double) irradTime << endl;
    // cout << UCNIntegral << " " << UCNIntegralErr << endl;
    //StorageTime -> SetCellError(j, j, 0, UCNIntegralErr);
    //cout << AVE_TS12_VALVEOPEN << endl;
    StorageTime -> SetBinError(0, UCNIntegralErr);
    StorageTime -> Fill(delayTime , UCNIntegral);
    StorageTemp -> Fill(AVE_TS12_VALVEOPEN, UCNIntegral);
    UCN -> Fill(runNumber, UCNIntegral);
    runTemp -> Fill(runNumber , AVE_TS12_VALVEOPEN); 
    IrradTemp -> Fill (irradTime , AVE_TS12_VALVEOPEN);
    TempBeam -> Fill( AVE_TS12_VALVEOPEN, AVE_B1CUR);
    UCNBeam -> Fill (AVE_B1CUR , UCNIntegral);
    delayTimeArray[j] = delayTime;
    UCNIntegralArray[j] = UCNIntegral;
    UCNIntegralErrArray[j] = UCNIntegralErr;
  }


  Func1 -> Draw();
  

  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1])+ [2]", 0, 180);
  fit -> SetParameters(140000,40,0);
  fit -> SetParNames("Amplitude" , "Storage Lifetime", "intercept");



  cout << j << endl;
  TCanvas *c1 = new TCanvas("c1", "c1",900,500);
  //c1 ->Divide(2,1);
  //c1 -> cd(1);
  StorageTime-> GetXaxis()-> SetTitle("Cycle Delay Time" );
  StorageTime-> GetYaxis()-> SetTitle("Cycle UCN Counts");
  StorageTime-> SetMarkerStyle(7);
  StorageTime-> Fit(fit,"R");
  StorageTime-> Draw();

  TText *text = new TText();
  text-> SetNDC();
  text -> SetTextFont(1);
  text -> SetTextColor(1);
  text -> SetTextSize(0.03);
  text -> SetTextAlign(22);
  text -> SetTextAngle(0);
  text -> DrawText(0.4, 0.8, "Exp #: TCN17003");

  
  title = new TPaveLabel(0.1, 0.94, 0.9, 0.98, "Be Isotopes");
  title -> SetFillColor(16);
  title -> Draw();
  
  TCanvas *c2 = new TCanvas("c2", "c2",900,500);
  // c1 -> cd(2);
  StorageTemp-> GetXaxis()-> SetTitle("Cycle Delay Time" );
  StorageTemp-> GetYaxis()-> SetTitle("Cycle UCN Counts");
  StorageTemp-> SetMarkerStyle(7);
  StorageTemp-> Draw();
  



  TCanvas *c3 = new TCanvas("c3", "c3",900,500);
  //c2  -> Divide(1,3);
  // c2  -> cd(1);
  UCN -> GetXaxis()-> SetTitle("Run Number" );
  UCN -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  UCN -> SetMarkerStyle(7);
  UCN -> Draw();

  TText *text = new TText();
  text-> SetNDC();
  text -> SetTextFont(1);
  text -> SetTextColor(1);
  text -> SetTextSize(0.03);
  text -> SetTextAlign(22);
  text -> SetTextAngle(0);
  text -> DrawText(0.4, 0.8, "Exp #: TCN17003");

  TCanvas *c4 = new TCanvas("c4", "c4",900,500);
  //c2 -> cd(2);
  runTemp -> GetXaxis()-> SetTitle("Run Number" );
  runTemp -> GetYaxis()-> SetTitle("Temparature");
  runTemp -> SetMarkerStyle(7);
  runTemp -> Draw();

  TCanvas *c5 = new TCanvas("c5", "c5",900,500);
  //c2 -> cd(3);
  IrradTemp -> GetXaxis()-> SetTitle("Irradiation Time" );
  IrradTemp -> GetYaxis()-> SetTitle("Temparature");
  IrradTemp -> SetMarkerStyle(7);
  IrradTemp -> Draw();


  TCanvas *c6 = new TCanvas("c6", "c6",900,500);
  c6 -> SetLogy();
  TGraphErrors *gr = new TGraphErrors(12, delayTimeArray, UCNIntegralArray, 0 , UCNIntegralErrArray);
  gr -> SetTitle("UCN Counts vs Valve Delay Time");
  gr -> GetXaxis()-> SetTitle("Cycle Delay Time" );
  gr -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr -> GetYaxis()-> SetRangeUser (1, 500000);
  gr -> SetMarkerStyle(7);
  gr -> Fit(fit);
  gr -> Draw("ap");
  
  c6->Update();
  
  // TF1 *tempbeamfit = new TF1 ("tempbeamfit" , "[0]*exp(x/[1])", 0.83, 0.93);
  //tempbeamfit -> SetParameters(80,20);
  TCanvas *c7 = new TCanvas("c7", "c7",900,500);
  TempBeam -> GetXaxis()-> SetTitle("Average Isopure Temperature" );
  TempBeam -> GetYaxis()-> SetTitle("Average Beam Current");
  TempBeam -> SetMarkerStyle(7);
  TempBeam -> Draw();
  TempBeam -> Fit("pol1");
  
  TCanvas *c8 = new TCanvas("c8", "c8",900,500);
  UCNBeam -> GetYaxis()-> SetTitle("UCN Count");
  UCNBeam -> GetXaxis()-> SetTitle("Average Beam Current");
  UCNBeam -> SetMarkerStyle(7);
  UCNBeam -> Draw();
  
}
