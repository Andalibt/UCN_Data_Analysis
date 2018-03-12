//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17006A.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17012_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin775 = new TFile("outputTree_StorageTime_775.root","READ");



  
  TTree *outputTree775 = (TTree*) fin775 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime775;





  outputTree775 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime775);


  // DELAY TIME (ARRAY)
  double delaytimeArray775 [100];



  // CYCLE NUMBER
  int cycleNumber775;



  outputTree775 -> SetBranchAddress ("cycleNumber" , &cycleNumber775);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray775 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral775;

  outputTree775 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral775);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray775 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr775;

  double UCNIntegralErr613;


  outputTree775 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr775);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray775 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral775;



  outputTree775 -> SetBranchAddress ("HistIntegral" , &HistIntegral775); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray775 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr775;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray775 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad775;


  outputTree775 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad775);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen775;

  outputTree775 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen775);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray775 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray775 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad775;


  outputTree775 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad775);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen775;



  outputTree775 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen775);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray775 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray775 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad775;



  outputTree775 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad775);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen775;

  
  outputTree775 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen775);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray775 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray775 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr775 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr775 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur775;


  outputTree775 -> SetBranchAddress ("AVE_PRDCUR" , &avecur775);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray775 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur775;
 

  outputTree775 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur775);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray775 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur775;


  outputTree775 -> SetBranchAddress ("MIN_PRDCUR" , &mincur775);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray775 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray775 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline775;


  outputTree775 -> SetBranchAddress ("Baseline" , &Baseline775);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray775 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr775;

 
  outputTree775 -> SetBranchAddress ("BaselineErr" , &BaselineErr775);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray775 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad775;

 
  outputTree775 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad775);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray775 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr775;


  outputTree775 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr775);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray775 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime775;


  outputTree775 -> SetBranchAddress ("FallTime" , &FallTime775);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray775 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr775;


  outputTree775 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr775);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray775 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime775;


  outputTree775 -> SetBranchAddress ("RiseTime" , &RiseTime775);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray775 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr775;


  outputTree775 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr775);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray775 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad775;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad775;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad775;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad775;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage775;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr775;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_775 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events775;
  events775 = (Double_t)outputTree775 -> GetEntries();

  for (ULong64_t j = 0 ; j < events775 ; j++){
    outputTree775 -> GetEvent(j);
    if (j == 9)
      continue;
    UCNIntegralArray775[counts_775] = UCNIntegral775;
    UCNIntegralErrArray775[counts_775] = UCNIntegralErr775/2;
    HistIntegralArray775[counts_775] = HistIntegral775;
    HistIntegralErrArray775[counts_775] = sqrt (HistIntegral775)/2;
    avets12IrradArray775[counts_775] = avets12Irrad775;
    avets12ValveOpenArray775[counts_775] = avets12ValveOpen775;
    maxts12IrradArray775[counts_775] = maxts12Irrad775;
    maxts12ValveOpenArray775[counts_775] = maxts12ValveOpen775;
    mints12IrradArray775[counts_775] = mints12Irrad775; 
    mints12ValveOpenArray775[counts_775] = mints12ValveOpen775;
    ts12IrradErr775[counts_775] = (maxts12Irrad775 - mints12Irrad775)/2;
    ts12ValveOpenErr775[counts_775] = (maxts12ValveOpen775 - mints12ValveOpen775)/2;
    avecurArray775[counts_775] = avecur775;
    maxcurArray775[counts_775] = maxcur775;
    mincurArray775[counts_775] = mincur775;
    ErrcurArray775[counts_775] = (maxcur775 - mincur775)/2;
    delaytimeArray775[counts_775] = cycleDelayTime775;
    cycleNumberArray775[counts_775] = cycleNumber775;
    BaselineArray775[counts_775] = Baseline775;
    BaselineIrradArray775[counts_775] = BaselineIrrad775;
    BaselineIrradErrArray775[counts_775] = BaselineIrradErr775/2;
    FallTimeArray775[counts_775] = FallTime775;
    FallTimeErrArray775[counts_775] = FallTimeErr775/2;
    RiseTimeArray775[counts_775] = RiseTime775;
    RiseTimeErrArray775[counts_775] = RiseTimeErr775/2;
    aveAllts12Irrad775 += avets12Irrad775;
    maxAllts12Irrad775 += maxts12Irrad775;
    minAllts12Irrad775 += mints12Irrad775;
    UCNIntegralArrayAll[counts_775] = UCNIntegral775;
    UCNIntegralErrArrayAll[counts_775] = UCNIntegralErr775/2;
    delayTimeAll[counts_775] = cycleDelayTime775;
    HistIntegralArrayAll[counts_775] = HistIntegral775;
    HistIntegralErrArrayAll[counts_775] = sqrt (HistIntegral775)/2;
    counts_775++;
  }
  aveAllts12Irrad775 = aveAllts12Irrad775/counts_775;
  maxAllts12Irrad775 = maxAllts12Irrad775/counts_775;
  minAllts12Irrad775 = minAllts12Irrad775/counts_775;
  aveAllErrts12Irrad775 = (maxAllts12Irrad775 - minAllts12Irrad775)/2;




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
  //              775
  //*********************************
  //*********************************
  TCanvas *c775 = new TCanvas("c775" , "c775" , 1200, 800);
  c775 -> Divide(2,2);
  //c775 -> cd(1);
  TPad *p1 = c775->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr775_delaycounts = new TGraphErrors(counts_775, delaytimeArray775 , UCNIntegralArray775, 0, UCNIntegralErrArray775);

  gr775_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr775_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr775_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr775_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr775_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_delaycounts -> SetMarkerStyle(7);
  gr775_delaycounts -> Fit(fit);
  storage775 = fit -> GetParameter(1);
  storageErr775 = fit -> GetParError(1);
  
  TGraphErrors *gr775_delayhist = new TGraphErrors(counts_775, delaytimeArray775 , HistIntegralArray775, 0, HistIntegralErrArray775);

  gr775_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr775_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr775_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr775_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr775_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr775_delayhist -> SetMarkerColor(2);
  gr775_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr775_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr775_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr775_delaycounts -> Draw("Ap");
  gr775_delayhist -> Draw("p");
  leg2 -> Draw();

  //c775 -> cd(2);
  TPad *p2 = c775->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr775_tempIrradcounts = new TGraphErrors (counts_775 , avets12IrradArray775, UCNIntegralArray775 , ts12IrradErr775 , UCNIntegralErrArray775);
  gr775_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr775_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr775_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr775_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr775_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr775_tempValveOpencounts = new TGraphErrors (counts_775 , avets12ValveOpenArray775, UCNIntegralArray775 , ts12ValveOpenErr775 , UCNIntegralErrArray775);
  gr775_tempValveOpencounts -> SetMarkerStyle(7);
  gr775_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr775_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr775_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr775_tempIrradcounts -> Draw("Ap");
  gr775_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c775 -> cd(3);
  TGraphErrors *gr775_delaytempIrrad = new TGraphErrors (counts_775 , delaytimeArray775, avets12IrradArray775, 0 , ts12IrradErr775);

  gr775_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr775_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr775_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr775_delaytempIrrad -> SetMarkerStyle(7);
  gr775_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr775_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr775_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr775_delaytempValveOpen = new TGraphErrors (counts_775 , delaytimeArray775, avets12ValveOpenArray775, 0 , ts12ValveOpenErr775);

  gr775_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr775_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr775_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr775_delaytempValveOpen -> SetMarkerStyle(7);
  gr775_delaytempValveOpen -> SetMarkerColor(2);
  gr775_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr775_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr775_delaytempIrrad -> Draw("AP");
  gr775_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c775->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr775_curcounts = new TGraphErrors (counts_775 , avecurArray775, UCNIntegralArray775 , ErrcurArray775 , UCNIntegralErrArray775);
  gr775_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr775_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr775_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr775_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr775_curhist = new TGraphErrors (counts_775 , avecurArray775, UCNIntegralArray775 , ErrcurArray775 , UCNIntegralErrArray775);
  gr775_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr775_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr775_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr775_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr775_curhist -> SetMarkerColor(2);
  gr775_curhist -> SetMarkerStyle(7);

  gr775_curcounts -> Draw("Ap");
  gr775_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c775_cycleNum = new TCanvas("c775_cycleNum" , "c775_cycleNum" , 1200, 800);
  c775_cycleNum -> Divide(2,2);
  TPad *p5 = c775_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr775_cyclecounts = new TGraphErrors (counts_775 , cycleNumberArray775, UCNIntegralArray775, 0 , UCNIntegralErrArray775);
  gr775_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr775_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr775_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr775_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr775_cyclehist = new TGraphErrors(counts_775, cycleNumberArray775 , HistIntegralArray775, 0, HistIntegralErrArray775);

  gr775_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr775_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr775_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr775_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr775_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr775_cyclehist -> SetMarkerColor(2);
  gr775_cyclehist -> SetMarkerStyle(7);

  gr775_cyclecounts -> Draw("Ap");
  gr775_cyclehist -> Draw("p");

  leg2-> Draw();

  c775_cycleNum -> cd(2);
 TGraphErrors *gr775_cycledelay = new TGraphErrors (counts_775 , cycleNumberArray775, delaytimeArray775, 0 , 0);
  gr775_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr775_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr775_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr775_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cycledelay -> SetMarkerStyle(7);

  gr775_cycledelay -> Draw("Ap");


  c775_cycleNum -> cd(3);
  TGraphErrors *gr775_cycletempIrrad = new TGraphErrors (counts_775 , cycleNumberArray775, avets12IrradArray775, 0 , ts12IrradErr775);

  gr775_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr775_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr775_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr775_cycletempIrrad -> SetMarkerStyle(7);
  gr775_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr775_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr775_cycletempValveOpen = new TGraphErrors (counts_775 , cycleNumberArray775, avets12ValveOpenArray775, 0 , ts12ValveOpenErr775);

  gr775_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr775_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr775_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr775_cycletempValveOpen -> SetMarkerStyle(7);
  gr775_cycletempValveOpen -> SetMarkerColor(2);
  gr775_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr775_cycletempIrrad -> Draw("AP");
  gr775_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c775_cycleNum -> cd(4);
  TGraphErrors *gr775_cyclecur = new TGraphErrors (counts_775 , cycleNumberArray775 , avecurArray775, 0, ErrcurArray775 );
  gr775_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr775_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr775_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr775_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclecur -> SetMarkerStyle(7);
  gr775_cyclecur -> Draw("Ap");


  TCanvas *c775_cycleNumFit = new TCanvas("c775_cycleNumFit" , "c775_cycleNumFit" , 1200, 800);
  c775_cycleNumFit -> Divide(2,2);

  c775_cycleNumFit -> cd(1);
  TGraphErrors *gr775_cyclefall = new TGraphErrors (counts_775, cycleNumberArray775, FallTimeArray775 , 0, FallTimeErrArray775);

  gr775_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr775_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr775_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr775_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclefall -> SetMarkerStyle(7);
  gr775_cyclefall -> Draw("Ap");


  c775_cycleNumFit -> cd(2);
  TGraphErrors *gr775_cyclebaseline = new TGraphErrors (counts_775, cycleNumberArray775, BaselineArray775 , 0, BaselineErrArray775);

  gr775_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr775_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr775_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr775_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclebaseline -> SetMarkerStyle(7);
  gr775_cyclebaseline -> Draw("Ap");

  c775_cycleNumFit -> cd(3);
  TGraphErrors *gr775_cyclebaselineirrad = new TGraphErrors (counts_775, cycleNumberArray775, BaselineIrradArray775 , 0, BaselineIrradErrArray775);

  gr775_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr775_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr775_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr775_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclebaselineirrad -> SetMarkerStyle(7);
  gr775_cyclebaselineirrad -> Draw("Ap");

  c775_cycleNumFit -> cd(4);
  TGraphErrors *gr775_cyclerise = new TGraphErrors (counts_775, cycleNumberArray775, RiseTimeArray775 , 0, RiseTimeErrArray775);

  gr775_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr775_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr775_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr775_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr775_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr775_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr775_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr775_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr775_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr775_cyclerise -> SetMarkerStyle(7);
  gr775_cyclerise -> Draw("Ap");








  /*

  double StorageAll [100] = {storage775, storage606, storage608, storage609, storage610, storage540};
  double StorageErrAll[100] = {storageErr775, storageErr606, storageErr608, storageErr608, storageErr609, storageErr610, storageErr540};
  double runNum[100] = {775, 606, 608, 609, 610, 540};
  double tempIrradAll[100] = {aveAllts12Irrad775, aveAllts12Irrad606, aveAllts12Irrad608, aveAllts12Irrad609, aveAllts12Irrad610, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad775,  aveAllErrts12Irrad606,  aveAllErrts12Irrad607,  aveAllErrts12Irrad609,  aveAllErrts12Irrad610,  aveAllErrts12Irrad538};
  
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_775 +counts_606 +counts_607 +counts_608 +counts_609 +counts_610 + counts_612 +counts_611 + counts_613 , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_775 +counts_606 +counts_607 +counts_608 +counts_609 +counts_610 +counts_611 +counts_612+ counts_613  , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
  grAllHist -> SetMarkerStyle(7);
  grAllHist -> SetMarkerColor(2);

  
  grAll -> SetTitle("UCN Count vs cycle Delay Time ");
  grAll -> GetYaxis()-> SetTitle("UCN Count" );
  grAll -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  grAll -> GetXaxis()-> SetLimits(0 ,180);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> Fit(fit);

  grAll -> SetMarkerStyle(7);
  grAll -> Draw("Ap");
  grAllHist -> Draw("p");*/
  




}
