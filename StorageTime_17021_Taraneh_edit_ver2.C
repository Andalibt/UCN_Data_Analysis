//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17021.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17021_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin803 = new TFile("outputTree_StorageTime_803.root","READ");



  
  TTree *outputTree803 = (TTree*) fin803 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime803;





  outputTree803 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime803);


  // DELAY TIME (ARRAY)
  double delaytimeArray803 [100];



  // CYCLE NUMBER
  int cycleNumber803;



  outputTree803 -> SetBranchAddress ("cycleNumber" , &cycleNumber803);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray803 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral803;

  outputTree803 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral803);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray803 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr803;

  double UCNIntegralErr613;


  outputTree803 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr803);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray803 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral803;



  outputTree803 -> SetBranchAddress ("HistIntegral" , &HistIntegral803); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray803 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr803;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray803 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad803;


  outputTree803 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad803);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen803;

  outputTree803 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen803);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray803 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray803 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad803;


  outputTree803 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad803);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen803;



  outputTree803 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen803);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray803 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray803 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad803;



  outputTree803 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad803);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen803;

  
  outputTree803 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen803);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray803 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray803 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr803 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr803 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur803;


  outputTree803 -> SetBranchAddress ("AVE_PRDCUR" , &avecur803);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray803 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur803;
 

  outputTree803 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur803);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray803 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur803;


  outputTree803 -> SetBranchAddress ("MIN_PRDCUR" , &mincur803);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray803 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray803 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline803;


  outputTree803 -> SetBranchAddress ("Baseline" , &Baseline803);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray803 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr803;

 
  outputTree803 -> SetBranchAddress ("BaselineErr" , &BaselineErr803);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray803 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad803;

 
  outputTree803 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad803);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray803 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr803;


  outputTree803 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr803);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray803 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime803;


  outputTree803 -> SetBranchAddress ("FallTime" , &FallTime803);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray803 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr803;


  outputTree803 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr803);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray803 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime803;


  outputTree803 -> SetBranchAddress ("RiseTime" , &RiseTime803);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray803 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr803;


  outputTree803 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr803);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray803 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad803;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad803;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad803;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad803;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage803;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr803;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_803 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events803;
  events803 = (Double_t)outputTree803 -> GetEntries();

  for (ULong64_t j = 0 ; j < events803 ; j++){
    outputTree803 -> GetEvent(j);
    if (j==8)
      continue;
    UCNIntegralArray803[counts_803] = UCNIntegral803;
    UCNIntegralErrArray803[counts_803] = UCNIntegralErr803/2;
    HistIntegralArray803[counts_803] = HistIntegral803;
    HistIntegralErrArray803[counts_803] = sqrt (HistIntegral803)/2;
    avets12IrradArray803[counts_803] = avets12Irrad803;
    avets12ValveOpenArray803[counts_803] = avets12ValveOpen803;
    maxts12IrradArray803[counts_803] = maxts12Irrad803;
    maxts12ValveOpenArray803[counts_803] = maxts12ValveOpen803;
    mints12IrradArray803[counts_803] = mints12Irrad803; 
    mints12ValveOpenArray803[counts_803] = mints12ValveOpen803;
    ts12IrradErr803[counts_803] = (maxts12Irrad803 - mints12Irrad803)/2;
    ts12ValveOpenErr803[counts_803] = (maxts12ValveOpen803 - mints12ValveOpen803)/2;
    avecurArray803[counts_803] = avecur803;
    maxcurArray803[counts_803] = maxcur803;
    mincurArray803[counts_803] = mincur803;
    ErrcurArray803[counts_803] = (maxcur803 - mincur803)/2;
    delaytimeArray803[counts_803] = cycleDelayTime803;
    cycleNumberArray803[counts_803] = cycleNumber803;
    BaselineArray803[counts_803] = Baseline803;
    BaselineIrradArray803[counts_803] = BaselineIrrad803;
    BaselineIrradErrArray803[counts_803] = BaselineIrradErr803/2;
    FallTimeArray803[counts_803] = FallTime803;
    FallTimeErrArray803[counts_803] = FallTimeErr803/2;
    RiseTimeArray803[counts_803] = RiseTime803;
    RiseTimeErrArray803[counts_803] = RiseTimeErr803/2;
    aveAllts12Irrad803 += avets12Irrad803;
    maxAllts12Irrad803 += maxts12Irrad803;
    minAllts12Irrad803 += mints12Irrad803;
    UCNIntegralArrayAll[counts_803] = UCNIntegral803;
    UCNIntegralErrArrayAll[counts_803] = UCNIntegralErr803/2;
    delayTimeAll[counts_803] = cycleDelayTime803;
    HistIntegralArrayAll[counts_803] = HistIntegral803;
    HistIntegralErrArrayAll[counts_803] = sqrt (HistIntegral803)/2;
    counts_803++;
  }
  aveAllts12Irrad803 = aveAllts12Irrad803/counts_803;
  maxAllts12Irrad803 = maxAllts12Irrad803/counts_803;
  minAllts12Irrad803 = minAllts12Irrad803/counts_803;
  aveAllErrts12Irrad803 = (maxAllts12Irrad803 - minAllts12Irrad803)/2;




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
  //              803
  //*********************************
  //*********************************
  TCanvas *c803 = new TCanvas("c803" , "c803" , 1200, 800);
  c803 -> Divide(2,2);
  //c803 -> cd(1);
  TPad *p1 = c803->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr803_delaycounts = new TGraphErrors(counts_803, delaytimeArray803 , UCNIntegralArray803, 0, UCNIntegralErrArray803);

  gr803_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr803_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr803_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr803_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr803_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_delaycounts -> SetMarkerStyle(7);
  gr803_delaycounts -> Fit(fit);
  storage803 = fit -> GetParameter(1);
  storageErr803 = fit -> GetParError(1);
  
  TGraphErrors *gr803_delayhist = new TGraphErrors(counts_803, delaytimeArray803 , HistIntegralArray803, 0, HistIntegralErrArray803);

  gr803_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr803_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr803_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr803_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr803_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr803_delayhist -> SetMarkerColor(2);
  gr803_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr803_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr803_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr803_delaycounts -> Draw("Ap");
  gr803_delayhist -> Draw("p");
  leg2 -> Draw();

  //c803 -> cd(2);
  TPad *p2 = c803->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr803_tempIrradcounts = new TGraphErrors (counts_803 , avets12IrradArray803, UCNIntegralArray803 , ts12IrradErr803 , UCNIntegralErrArray803);
  gr803_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr803_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr803_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr803_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr803_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr803_tempValveOpencounts = new TGraphErrors (counts_803 , avets12ValveOpenArray803, UCNIntegralArray803 , ts12ValveOpenErr803 , UCNIntegralErrArray803);
  gr803_tempValveOpencounts -> SetMarkerStyle(7);
  gr803_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr803_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr803_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr803_tempIrradcounts -> Draw("Ap");
  gr803_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c803 -> cd(3);
  TGraphErrors *gr803_delaytempIrrad = new TGraphErrors (counts_803 , delaytimeArray803, avets12IrradArray803, 0 , ts12IrradErr803);

  gr803_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr803_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr803_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr803_delaytempIrrad -> SetMarkerStyle(7);
  gr803_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr803_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr803_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr803_delaytempValveOpen = new TGraphErrors (counts_803 , delaytimeArray803, avets12ValveOpenArray803, 0 , ts12ValveOpenErr803);

  gr803_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr803_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr803_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr803_delaytempValveOpen -> SetMarkerStyle(7);
  gr803_delaytempValveOpen -> SetMarkerColor(2);
  gr803_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr803_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr803_delaytempIrrad -> Draw("AP");
  gr803_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c803->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr803_curcounts = new TGraphErrors (counts_803 , avecurArray803, UCNIntegralArray803 , ErrcurArray803 , UCNIntegralErrArray803);
  gr803_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr803_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr803_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr803_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr803_curhist = new TGraphErrors (counts_803 , avecurArray803, UCNIntegralArray803 , ErrcurArray803 , UCNIntegralErrArray803);
  gr803_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr803_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr803_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr803_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr803_curhist -> SetMarkerColor(2);
  gr803_curhist -> SetMarkerStyle(7);

  gr803_curcounts -> Draw("Ap");
  gr803_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c803_cycleNum = new TCanvas("c803_cycleNum" , "c803_cycleNum" , 1200, 800);
  c803_cycleNum -> Divide(2,2);
  TPad *p5 = c803_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr803_cyclecounts = new TGraphErrors (counts_803 , cycleNumberArray803, UCNIntegralArray803, 0 , UCNIntegralErrArray803);
  gr803_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr803_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr803_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr803_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr803_cyclehist = new TGraphErrors(counts_803, cycleNumberArray803 , HistIntegralArray803, 0, HistIntegralErrArray803);

  gr803_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr803_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr803_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr803_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr803_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr803_cyclehist -> SetMarkerColor(2);
  gr803_cyclehist -> SetMarkerStyle(7);

  gr803_cyclecounts -> Draw("Ap");
  gr803_cyclehist -> Draw("p");

  leg2-> Draw();

  c803_cycleNum -> cd(2);
 TGraphErrors *gr803_cycledelay = new TGraphErrors (counts_803 , cycleNumberArray803, delaytimeArray803, 0 , 0);
  gr803_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr803_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr803_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr803_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cycledelay -> SetMarkerStyle(7);

  gr803_cycledelay -> Draw("Ap");


  c803_cycleNum -> cd(3);
  TGraphErrors *gr803_cycletempIrrad = new TGraphErrors (counts_803 , cycleNumberArray803, avets12IrradArray803, 0 , ts12IrradErr803);

  gr803_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr803_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr803_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr803_cycletempIrrad -> SetMarkerStyle(7);
  gr803_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr803_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr803_cycletempValveOpen = new TGraphErrors (counts_803 , cycleNumberArray803, avets12ValveOpenArray803, 0 , ts12ValveOpenErr803);

  gr803_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr803_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr803_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr803_cycletempValveOpen -> SetMarkerStyle(7);
  gr803_cycletempValveOpen -> SetMarkerColor(2);
  gr803_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr803_cycletempIrrad -> Draw("AP");
  gr803_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c803_cycleNum -> cd(4);
  TGraphErrors *gr803_cyclecur = new TGraphErrors (counts_803 , cycleNumberArray803 , avecurArray803, 0, ErrcurArray803 );
  gr803_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr803_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr803_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr803_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclecur -> SetMarkerStyle(7);
  gr803_cyclecur -> Draw("Ap");


  TCanvas *c803_cycleNumFit = new TCanvas("c803_cycleNumFit" , "c803_cycleNumFit" , 1200, 800);
  c803_cycleNumFit -> Divide(2,2);

  c803_cycleNumFit -> cd(1);
  TGraphErrors *gr803_cyclefall = new TGraphErrors (counts_803, cycleNumberArray803, FallTimeArray803 , 0, FallTimeErrArray803);

  gr803_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr803_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr803_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr803_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclefall -> SetMarkerStyle(7);
  gr803_cyclefall -> Draw("Ap");


  c803_cycleNumFit -> cd(2);
  TGraphErrors *gr803_cyclebaseline = new TGraphErrors (counts_803, cycleNumberArray803, BaselineArray803 , 0, BaselineErrArray803);

  gr803_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr803_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr803_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr803_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclebaseline -> SetMarkerStyle(7);
  gr803_cyclebaseline -> Draw("Ap");

  c803_cycleNumFit -> cd(3);
  TGraphErrors *gr803_cyclebaselineirrad = new TGraphErrors (counts_803, cycleNumberArray803, BaselineIrradArray803 , 0, BaselineIrradErrArray803);

  gr803_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr803_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr803_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr803_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclebaselineirrad -> SetMarkerStyle(7);
  gr803_cyclebaselineirrad -> Draw("Ap");

  c803_cycleNumFit -> cd(4);
  TGraphErrors *gr803_cyclerise = new TGraphErrors (counts_803, cycleNumberArray803, RiseTimeArray803 , 0, RiseTimeErrArray803);

  gr803_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr803_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr803_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr803_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr803_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr803_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr803_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr803_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr803_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr803_cyclerise -> SetMarkerStyle(7);
  gr803_cyclerise -> Draw("Ap");








  




}
