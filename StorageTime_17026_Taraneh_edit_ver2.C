//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17026.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17026_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin821 = new TFile("outputTree_StorageTime_821.root","READ");



  
  TTree *outputTree821 = (TTree*) fin821 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime821;





  outputTree821 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime821);


  // DELAY TIME (ARRAY)
  double delaytimeArray821 [100];



  // CYCLE NUMBER
  int cycleNumber821;



  outputTree821 -> SetBranchAddress ("cycleNumber" , &cycleNumber821);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray821 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral821;

  outputTree821 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral821);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray821 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr821;

  double UCNIntegralErr613;


  outputTree821 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr821);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray821 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral821;



  outputTree821 -> SetBranchAddress ("HistIntegral" , &HistIntegral821); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray821 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr821;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray821 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad821;


  outputTree821 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad821);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen821;

  outputTree821 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen821);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray821 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray821 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad821;


  outputTree821 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad821);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen821;



  outputTree821 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen821);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray821 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray821 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad821;



  outputTree821 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad821);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen821;

  
  outputTree821 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen821);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray821 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray821 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr821 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr821 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur821;


  outputTree821 -> SetBranchAddress ("AVE_PRDCUR" , &avecur821);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray821 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur821;
 

  outputTree821 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur821);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray821 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur821;


  outputTree821 -> SetBranchAddress ("MIN_PRDCUR" , &mincur821);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray821 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray821 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline821;


  outputTree821 -> SetBranchAddress ("Baseline" , &Baseline821);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray821 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr821;

 
  outputTree821 -> SetBranchAddress ("BaselineErr" , &BaselineErr821);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray821 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad821;

 
  outputTree821 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad821);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray821 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr821;


  outputTree821 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr821);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray821 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime821;


  outputTree821 -> SetBranchAddress ("FallTime" , &FallTime821);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray821 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr821;


  outputTree821 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr821);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray821 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime821;


  outputTree821 -> SetBranchAddress ("RiseTime" , &RiseTime821);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray821 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr821;


  outputTree821 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr821);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray821 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad821;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad821;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad821;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad821;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage821;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr821;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_821 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events821;
  events821 = (Double_t)outputTree821 -> GetEntries();

  for (ULong64_t j = 0 ; j < events821 ; j++){
    outputTree821 -> GetEvent(j);
    UCNIntegralArray821[counts_821] = UCNIntegral821;
    UCNIntegralErrArray821[counts_821] = UCNIntegralErr821/2;
    HistIntegralArray821[counts_821] = HistIntegral821;
    HistIntegralErrArray821[counts_821] = sqrt (HistIntegral821)/2;
    avets12IrradArray821[counts_821] = avets12Irrad821;
    avets12ValveOpenArray821[counts_821] = avets12ValveOpen821;
    maxts12IrradArray821[counts_821] = maxts12Irrad821;
    maxts12ValveOpenArray821[counts_821] = maxts12ValveOpen821;
    mints12IrradArray821[counts_821] = mints12Irrad821; 
    mints12ValveOpenArray821[counts_821] = mints12ValveOpen821;
    ts12IrradErr821[counts_821] = (maxts12Irrad821 - mints12Irrad821)/2;
    ts12ValveOpenErr821[counts_821] = (maxts12ValveOpen821 - mints12ValveOpen821)/2;
    avecurArray821[counts_821] = avecur821;
    maxcurArray821[counts_821] = maxcur821;
    mincurArray821[counts_821] = mincur821;
    ErrcurArray821[counts_821] = (maxcur821 - mincur821)/2;
    delaytimeArray821[counts_821] = cycleDelayTime821;
    cycleNumberArray821[counts_821] = cycleNumber821;
    BaselineArray821[counts_821] = Baseline821;
    BaselineIrradArray821[counts_821] = BaselineIrrad821;
    BaselineIrradErrArray821[counts_821] = BaselineIrradErr821/2;
    FallTimeArray821[counts_821] = FallTime821;
    FallTimeErrArray821[counts_821] = FallTimeErr821/2;
    RiseTimeArray821[counts_821] = RiseTime821;
    RiseTimeErrArray821[counts_821] = RiseTimeErr821/2;
    aveAllts12Irrad821 += avets12Irrad821;
    maxAllts12Irrad821 += maxts12Irrad821;
    minAllts12Irrad821 += mints12Irrad821;
    UCNIntegralArrayAll[counts_821] = UCNIntegral821;
    UCNIntegralErrArrayAll[counts_821] = UCNIntegralErr821/2;
    delayTimeAll[counts_821] = cycleDelayTime821;
    HistIntegralArrayAll[counts_821] = HistIntegral821;
    HistIntegralErrArrayAll[counts_821] = sqrt (HistIntegral821)/2;
    counts_821++;
  }
  aveAllts12Irrad821 = aveAllts12Irrad821/counts_821;
  maxAllts12Irrad821 = maxAllts12Irrad821/counts_821;
  minAllts12Irrad821 = minAllts12Irrad821/counts_821;
  aveAllErrts12Irrad821 = (maxAllts12Irrad821 - minAllts12Irrad821)/2;




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
  //              821
  //*********************************
  //*********************************
  TCanvas *c821 = new TCanvas("c821" , "c821" , 1200, 800);
  c821 -> Divide(2,2);
  //c821 -> cd(1);
  TPad *p1 = c821->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr821_delaycounts = new TGraphErrors(counts_821, delaytimeArray821 , UCNIntegralArray821, 0, UCNIntegralErrArray821);

  gr821_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr821_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr821_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr821_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr821_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_delaycounts -> SetMarkerStyle(7);
  gr821_delaycounts -> Fit(fit);
  storage821 = fit -> GetParameter(1);
  storageErr821 = fit -> GetParError(1);
  
  TGraphErrors *gr821_delayhist = new TGraphErrors(counts_821, delaytimeArray821 , HistIntegralArray821, 0, HistIntegralErrArray821);

  gr821_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr821_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr821_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr821_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr821_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr821_delayhist -> SetMarkerColor(2);
  gr821_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr821_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr821_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr821_delaycounts -> Draw("Ap");
  gr821_delayhist -> Draw("p");
  leg2 -> Draw();

  //c821 -> cd(2);
  TPad *p2 = c821->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr821_tempIrradcounts = new TGraphErrors (counts_821 , avets12IrradArray821, UCNIntegralArray821 , ts12IrradErr821 , UCNIntegralErrArray821);
  gr821_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr821_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr821_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr821_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr821_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr821_tempValveOpencounts = new TGraphErrors (counts_821 , avets12ValveOpenArray821, UCNIntegralArray821 , ts12ValveOpenErr821 , UCNIntegralErrArray821);
  gr821_tempValveOpencounts -> SetMarkerStyle(7);
  gr821_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr821_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr821_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr821_tempIrradcounts -> Draw("Ap");
  gr821_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c821 -> cd(3);
  TGraphErrors *gr821_delaytempIrrad = new TGraphErrors (counts_821 , delaytimeArray821, avets12IrradArray821, 0 , ts12IrradErr821);

  gr821_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr821_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr821_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr821_delaytempIrrad -> SetMarkerStyle(7);
  gr821_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr821_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr821_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr821_delaytempValveOpen = new TGraphErrors (counts_821 , delaytimeArray821, avets12ValveOpenArray821, 0 , ts12ValveOpenErr821);

  gr821_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr821_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr821_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr821_delaytempValveOpen -> SetMarkerStyle(7);
  gr821_delaytempValveOpen -> SetMarkerColor(2);
  gr821_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr821_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr821_delaytempIrrad -> Draw("AP");
  gr821_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c821->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr821_curcounts = new TGraphErrors (counts_821 , avecurArray821, UCNIntegralArray821 , ErrcurArray821 , UCNIntegralErrArray821);
  gr821_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr821_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr821_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr821_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr821_curhist = new TGraphErrors (counts_821 , avecurArray821, UCNIntegralArray821 , ErrcurArray821 , UCNIntegralErrArray821);
  gr821_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr821_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr821_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr821_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr821_curhist -> SetMarkerColor(2);
  gr821_curhist -> SetMarkerStyle(7);

  gr821_curcounts -> Draw("Ap");
  gr821_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c821_cycleNum = new TCanvas("c821_cycleNum" , "c821_cycleNum" , 1200, 800);
  c821_cycleNum -> Divide(2,2);
  TPad *p5 = c821_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr821_cyclecounts = new TGraphErrors (counts_821 , cycleNumberArray821, UCNIntegralArray821, 0 , UCNIntegralErrArray821);
  gr821_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr821_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr821_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr821_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr821_cyclehist = new TGraphErrors(counts_821, cycleNumberArray821 , HistIntegralArray821, 0, HistIntegralErrArray821);

  gr821_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr821_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr821_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr821_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr821_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr821_cyclehist -> SetMarkerColor(2);
  gr821_cyclehist -> SetMarkerStyle(7);

  gr821_cyclecounts -> Draw("Ap");
  gr821_cyclehist -> Draw("p");

  leg2-> Draw();

  c821_cycleNum -> cd(2);
 TGraphErrors *gr821_cycledelay = new TGraphErrors (counts_821 , cycleNumberArray821, delaytimeArray821, 0 , 0);
  gr821_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr821_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr821_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr821_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cycledelay -> SetMarkerStyle(7);

  gr821_cycledelay -> Draw("Ap");


  c821_cycleNum -> cd(3);
  TGraphErrors *gr821_cycletempIrrad = new TGraphErrors (counts_821 , cycleNumberArray821, avets12IrradArray821, 0 , ts12IrradErr821);

  gr821_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr821_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr821_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr821_cycletempIrrad -> SetMarkerStyle(7);
  gr821_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr821_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr821_cycletempValveOpen = new TGraphErrors (counts_821 , cycleNumberArray821, avets12ValveOpenArray821, 0 , ts12ValveOpenErr821);

  gr821_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr821_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr821_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr821_cycletempValveOpen -> SetMarkerStyle(7);
  gr821_cycletempValveOpen -> SetMarkerColor(2);
  gr821_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr821_cycletempIrrad -> Draw("AP");
  gr821_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c821_cycleNum -> cd(4);
  TGraphErrors *gr821_cyclecur = new TGraphErrors (counts_821 , cycleNumberArray821 , avecurArray821, 0, ErrcurArray821 );
  gr821_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr821_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr821_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr821_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclecur -> SetMarkerStyle(7);
  gr821_cyclecur -> Draw("Ap");


  TCanvas *c821_cycleNumFit = new TCanvas("c821_cycleNumFit" , "c821_cycleNumFit" , 1200, 800);
  c821_cycleNumFit -> Divide(2,2);

  c821_cycleNumFit -> cd(1);
  TGraphErrors *gr821_cyclefall = new TGraphErrors (counts_821, cycleNumberArray821, FallTimeArray821 , 0, FallTimeErrArray821);

  gr821_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr821_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr821_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr821_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclefall -> SetMarkerStyle(7);
  gr821_cyclefall -> Draw("Ap");


  c821_cycleNumFit -> cd(2);
  TGraphErrors *gr821_cyclebaseline = new TGraphErrors (counts_821, cycleNumberArray821, BaselineArray821 , 0, BaselineErrArray821);

  gr821_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr821_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr821_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr821_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclebaseline -> SetMarkerStyle(7);
  gr821_cyclebaseline -> Draw("Ap");

  c821_cycleNumFit -> cd(3);
  TGraphErrors *gr821_cyclebaselineirrad = new TGraphErrors (counts_821, cycleNumberArray821, BaselineIrradArray821 , 0, BaselineIrradErrArray821);

  gr821_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr821_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr821_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr821_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclebaselineirrad -> SetMarkerStyle(7);
  gr821_cyclebaselineirrad -> Draw("Ap");

  c821_cycleNumFit -> cd(4);
  TGraphErrors *gr821_cyclerise = new TGraphErrors (counts_821, cycleNumberArray821, RiseTimeArray821 , 0, RiseTimeErrArray821);

  gr821_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr821_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr821_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr821_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr821_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr821_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr821_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr821_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr821_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr821_cyclerise -> SetMarkerStyle(7);
  gr821_cyclerise -> Draw("Ap");








  




}
