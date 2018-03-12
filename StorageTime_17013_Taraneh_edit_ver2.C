//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17013.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17013_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin777 = new TFile("outputTree_StorageTime_777.root","READ");



  
  TTree *outputTree777 = (TTree*) fin777 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime777;





  outputTree777 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime777);


  // DELAY TIME (ARRAY)
  double delaytimeArray777 [100];



  // CYCLE NUMBER
  int cycleNumber777;



  outputTree777 -> SetBranchAddress ("cycleNumber" , &cycleNumber777);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray777 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral777;

  outputTree777 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral777);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray777 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr777;

  double UCNIntegralErr613;


  outputTree777 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr777);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray777 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral777;



  outputTree777 -> SetBranchAddress ("HistIntegral" , &HistIntegral777); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray777 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr777;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray777 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad777;


  outputTree777 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad777);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen777;

  outputTree777 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen777);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray777 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray777 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad777;


  outputTree777 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad777);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen777;



  outputTree777 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen777);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray777 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray777 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad777;



  outputTree777 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad777);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen777;

  
  outputTree777 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen777);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray777 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray777 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr777 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr777 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur777;


  outputTree777 -> SetBranchAddress ("AVE_PRDCUR" , &avecur777);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray777 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur777;
 

  outputTree777 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur777);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray777 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur777;


  outputTree777 -> SetBranchAddress ("MIN_PRDCUR" , &mincur777);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray777 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray777 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline777;


  outputTree777 -> SetBranchAddress ("Baseline" , &Baseline777);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray777 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr777;

 
  outputTree777 -> SetBranchAddress ("BaselineErr" , &BaselineErr777);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray777 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad777;

 
  outputTree777 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad777);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray777 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr777;


  outputTree777 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr777);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray777 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime777;


  outputTree777 -> SetBranchAddress ("FallTime" , &FallTime777);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray777 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr777;


  outputTree777 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr777);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray777 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime777;


  outputTree777 -> SetBranchAddress ("RiseTime" , &RiseTime777);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray777 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr777;


  outputTree777 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr777);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray777 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad777;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad777;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad777;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad777;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage777;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr777;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_777 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events777;
  events777 = (Double_t)outputTree777 -> GetEntries();

  for (ULong64_t j = 0 ; j < events777 ; j++){
    outputTree777 -> GetEvent(j);
    if (j==8)
      continue;
    UCNIntegralArray777[counts_777] = UCNIntegral777;
    UCNIntegralErrArray777[counts_777] = UCNIntegralErr777/2;
    HistIntegralArray777[counts_777] = HistIntegral777;
    HistIntegralErrArray777[counts_777] = sqrt (HistIntegral777)/2;
    avets12IrradArray777[counts_777] = avets12Irrad777;
    avets12ValveOpenArray777[counts_777] = avets12ValveOpen777;
    maxts12IrradArray777[counts_777] = maxts12Irrad777;
    maxts12ValveOpenArray777[counts_777] = maxts12ValveOpen777;
    mints12IrradArray777[counts_777] = mints12Irrad777; 
    mints12ValveOpenArray777[counts_777] = mints12ValveOpen777;
    ts12IrradErr777[counts_777] = (maxts12Irrad777 - mints12Irrad777)/2;
    ts12ValveOpenErr777[counts_777] = (maxts12ValveOpen777 - mints12ValveOpen777)/2;
    avecurArray777[counts_777] = avecur777;
    maxcurArray777[counts_777] = maxcur777;
    mincurArray777[counts_777] = mincur777;
    ErrcurArray777[counts_777] = (maxcur777 - mincur777)/2;
    delaytimeArray777[counts_777] = cycleDelayTime777;
    cycleNumberArray777[counts_777] = cycleNumber777;
    BaselineArray777[counts_777] = Baseline777;
    BaselineIrradArray777[counts_777] = BaselineIrrad777;
    BaselineIrradErrArray777[counts_777] = BaselineIrradErr777/2;
    FallTimeArray777[counts_777] = FallTime777;
    FallTimeErrArray777[counts_777] = FallTimeErr777/2;
    RiseTimeArray777[counts_777] = RiseTime777;
    RiseTimeErrArray777[counts_777] = RiseTimeErr777/2;
    aveAllts12Irrad777 += avets12Irrad777;
    maxAllts12Irrad777 += maxts12Irrad777;
    minAllts12Irrad777 += mints12Irrad777;
    UCNIntegralArrayAll[counts_777] = UCNIntegral777;
    UCNIntegralErrArrayAll[counts_777] = UCNIntegralErr777/2;
    delayTimeAll[counts_777] = cycleDelayTime777;
    HistIntegralArrayAll[counts_777] = HistIntegral777;
    HistIntegralErrArrayAll[counts_777] = sqrt (HistIntegral777)/2;
    counts_777++;
  }
  aveAllts12Irrad777 = aveAllts12Irrad777/counts_777;
  maxAllts12Irrad777 = maxAllts12Irrad777/counts_777;
  minAllts12Irrad777 = minAllts12Irrad777/counts_777;
  aveAllErrts12Irrad777 = (maxAllts12Irrad777 - minAllts12Irrad777)/2;




  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(100000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 10, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************


  //*********************************
  //*********************************
  //              777
  //*********************************
  //*********************************
  TCanvas *c777 = new TCanvas("c777" , "c777" , 1200, 800);
  c777 -> Divide(2,2);
  //c777 -> cd(1);
  TPad *p1 = c777->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr777_delaycounts = new TGraphErrors(counts_777, delaytimeArray777 , UCNIntegralArray777, 0, UCNIntegralErrArray777);

  gr777_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr777_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr777_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr777_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr777_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_delaycounts -> SetMarkerStyle(7);
  gr777_delaycounts -> Fit(fit);
  storage777 = fit -> GetParameter(1);
  storageErr777 = fit -> GetParError(1);
  
  TGraphErrors *gr777_delayhist = new TGraphErrors(counts_777, delaytimeArray777 , HistIntegralArray777, 0, HistIntegralErrArray777);

  gr777_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr777_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr777_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr777_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr777_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr777_delayhist -> SetMarkerColor(2);
  gr777_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr777_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr777_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr777_delaycounts -> Draw("Ap");
  gr777_delayhist -> Draw("p");
  leg2 -> Draw();

  //c777 -> cd(2);
  TPad *p2 = c777->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr777_tempIrradcounts = new TGraphErrors (counts_777 , avets12IrradArray777, UCNIntegralArray777 , ts12IrradErr777 , UCNIntegralErrArray777);
  gr777_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr777_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr777_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr777_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr777_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr777_tempValveOpencounts = new TGraphErrors (counts_777 , avets12ValveOpenArray777, UCNIntegralArray777 , ts12ValveOpenErr777 , UCNIntegralErrArray777);
  gr777_tempValveOpencounts -> SetMarkerStyle(7);
  gr777_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr777_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr777_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr777_tempIrradcounts -> Draw("Ap");
  gr777_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c777 -> cd(3);
  TGraphErrors *gr777_delaytempIrrad = new TGraphErrors (counts_777 , delaytimeArray777, avets12IrradArray777, 0 , ts12IrradErr777);

  gr777_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr777_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr777_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr777_delaytempIrrad -> SetMarkerStyle(7);
  gr777_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr777_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr777_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr777_delaytempValveOpen = new TGraphErrors (counts_777 , delaytimeArray777, avets12ValveOpenArray777, 0 , ts12ValveOpenErr777);

  gr777_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr777_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr777_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr777_delaytempValveOpen -> SetMarkerStyle(7);
  gr777_delaytempValveOpen -> SetMarkerColor(2);
  gr777_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr777_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr777_delaytempIrrad -> Draw("AP");
  gr777_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c777->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr777_curcounts = new TGraphErrors (counts_777 , avecurArray777, UCNIntegralArray777 , ErrcurArray777 , UCNIntegralErrArray777);
  gr777_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr777_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr777_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr777_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr777_curhist = new TGraphErrors (counts_777 , avecurArray777, UCNIntegralArray777 , ErrcurArray777 , UCNIntegralErrArray777);
  gr777_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr777_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr777_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr777_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr777_curhist -> SetMarkerColor(2);
  gr777_curhist -> SetMarkerStyle(7);

  gr777_curcounts -> Draw("Ap");
  gr777_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c777_cycleNum = new TCanvas("c777_cycleNum" , "c777_cycleNum" , 1200, 800);
  c777_cycleNum -> Divide(2,2);
  TPad *p5 = c777_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr777_cyclecounts = new TGraphErrors (counts_777 , cycleNumberArray777, UCNIntegralArray777, 0 , UCNIntegralErrArray777);
  gr777_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr777_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr777_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr777_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr777_cyclehist = new TGraphErrors(counts_777, cycleNumberArray777 , HistIntegralArray777, 0, HistIntegralErrArray777);

  gr777_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr777_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr777_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr777_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr777_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr777_cyclehist -> SetMarkerColor(2);
  gr777_cyclehist -> SetMarkerStyle(7);

  gr777_cyclecounts -> Draw("Ap");
  gr777_cyclehist -> Draw("p");

  leg2-> Draw();

  c777_cycleNum -> cd(2);
 TGraphErrors *gr777_cycledelay = new TGraphErrors (counts_777 , cycleNumberArray777, delaytimeArray777, 0 , 0);
  gr777_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr777_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr777_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr777_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cycledelay -> SetMarkerStyle(7);

  gr777_cycledelay -> Draw("Ap");


  c777_cycleNum -> cd(3);
  TGraphErrors *gr777_cycletempIrrad = new TGraphErrors (counts_777 , cycleNumberArray777, avets12IrradArray777, 0 , ts12IrradErr777);

  gr777_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr777_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr777_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr777_cycletempIrrad -> SetMarkerStyle(7);
  gr777_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr777_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr777_cycletempValveOpen = new TGraphErrors (counts_777 , cycleNumberArray777, avets12ValveOpenArray777, 0 , ts12ValveOpenErr777);

  gr777_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr777_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr777_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr777_cycletempValveOpen -> SetMarkerStyle(7);
  gr777_cycletempValveOpen -> SetMarkerColor(2);
  gr777_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr777_cycletempIrrad -> Draw("AP");
  gr777_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c777_cycleNum -> cd(4);
  TGraphErrors *gr777_cyclecur = new TGraphErrors (counts_777 , cycleNumberArray777 , avecurArray777, 0, ErrcurArray777 );
  gr777_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr777_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr777_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr777_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclecur -> SetMarkerStyle(7);
  gr777_cyclecur -> Draw("Ap");


  TCanvas *c777_cycleNumFit = new TCanvas("c777_cycleNumFit" , "c777_cycleNumFit" , 1200, 800);
  c777_cycleNumFit -> Divide(2,2);

  c777_cycleNumFit -> cd(1);
  TGraphErrors *gr777_cyclefall = new TGraphErrors (counts_777, cycleNumberArray777, FallTimeArray777 , 0, FallTimeErrArray777);

  gr777_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr777_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr777_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr777_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclefall -> SetMarkerStyle(7);
  gr777_cyclefall -> Draw("Ap");


  c777_cycleNumFit -> cd(2);
  TGraphErrors *gr777_cyclebaseline = new TGraphErrors (counts_777, cycleNumberArray777, BaselineArray777 , 0, BaselineErrArray777);

  gr777_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr777_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr777_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr777_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclebaseline -> SetMarkerStyle(7);
  gr777_cyclebaseline -> Draw("Ap");

  c777_cycleNumFit -> cd(3);
  TGraphErrors *gr777_cyclebaselineirrad = new TGraphErrors (counts_777, cycleNumberArray777, BaselineIrradArray777 , 0, BaselineIrradErrArray777);

  gr777_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr777_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr777_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr777_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclebaselineirrad -> SetMarkerStyle(7);
  gr777_cyclebaselineirrad -> Draw("Ap");

  c777_cycleNumFit -> cd(4);
  TGraphErrors *gr777_cyclerise = new TGraphErrors (counts_777, cycleNumberArray777, RiseTimeArray777 , 0, RiseTimeErrArray777);

  gr777_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr777_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr777_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr777_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr777_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr777_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr777_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr777_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr777_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr777_cyclerise -> SetMarkerStyle(7);
  gr777_cyclerise -> Draw("Ap");








  




}
