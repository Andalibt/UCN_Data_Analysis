//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17016.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17016_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin791 = new TFile("outputTree_StorageTime_791.root","READ");



  
  TTree *outputTree791 = (TTree*) fin791 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime791;





  outputTree791 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime791);


  // DELAY TIME (ARRAY)
  double delaytimeArray791 [100];



  // CYCLE NUMBER
  int cycleNumber791;



  outputTree791 -> SetBranchAddress ("cycleNumber" , &cycleNumber791);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray791 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral791;

  outputTree791 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral791);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray791 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr791;

  double UCNIntegralErr613;


  outputTree791 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr791);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray791 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral791;



  outputTree791 -> SetBranchAddress ("HistIntegral" , &HistIntegral791); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray791 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr791;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray791 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad791;


  outputTree791 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad791);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen791;

  outputTree791 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen791);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray791 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray791 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad791;


  outputTree791 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad791);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen791;



  outputTree791 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen791);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray791 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray791 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad791;



  outputTree791 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad791);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen791;

  
  outputTree791 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen791);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray791 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray791 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr791 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr791 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur791;


  outputTree791 -> SetBranchAddress ("AVE_PRDCUR" , &avecur791);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray791 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur791;
 

  outputTree791 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur791);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray791 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur791;


  outputTree791 -> SetBranchAddress ("MIN_PRDCUR" , &mincur791);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray791 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray791 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline791;


  outputTree791 -> SetBranchAddress ("Baseline" , &Baseline791);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray791 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr791;

 
  outputTree791 -> SetBranchAddress ("BaselineErr" , &BaselineErr791);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray791 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad791;

 
  outputTree791 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad791);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray791 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr791;


  outputTree791 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr791);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray791 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime791;


  outputTree791 -> SetBranchAddress ("FallTime" , &FallTime791);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray791 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr791;


  outputTree791 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr791);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray791 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime791;


  outputTree791 -> SetBranchAddress ("RiseTime" , &RiseTime791);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray791 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr791;


  outputTree791 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr791);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray791 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad791;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad791;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad791;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad791;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage791;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr791;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_791 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events791;
  events791 = (Double_t)outputTree791 -> GetEntries();

  for (ULong64_t j = 0 ; j < events791 ; j++){
    outputTree791 -> GetEvent(j);
    if (j == 8 || j == 9 || j == 10|| j==11)
      continue;
    UCNIntegralArray791[counts_791] = UCNIntegral791;
    UCNIntegralErrArray791[counts_791] = UCNIntegralErr791/2;
    HistIntegralArray791[counts_791] = HistIntegral791;
    HistIntegralErrArray791[counts_791] = sqrt (HistIntegral791)/2;
    avets12IrradArray791[counts_791] = avets12Irrad791;
    avets12ValveOpenArray791[counts_791] = avets12ValveOpen791;
    maxts12IrradArray791[counts_791] = maxts12Irrad791;
    maxts12ValveOpenArray791[counts_791] = maxts12ValveOpen791;
    mints12IrradArray791[counts_791] = mints12Irrad791; 
    mints12ValveOpenArray791[counts_791] = mints12ValveOpen791;
    ts12IrradErr791[counts_791] = (maxts12Irrad791 - mints12Irrad791)/2;
    ts12ValveOpenErr791[counts_791] = (maxts12ValveOpen791 - mints12ValveOpen791)/2;
    avecurArray791[counts_791] = avecur791;
    maxcurArray791[counts_791] = maxcur791;
    mincurArray791[counts_791] = mincur791;
    ErrcurArray791[counts_791] = (maxcur791 - mincur791)/2;
    delaytimeArray791[counts_791] = cycleDelayTime791;
    cycleNumberArray791[counts_791] = cycleNumber791;
    BaselineArray791[counts_791] = Baseline791;
    BaselineIrradArray791[counts_791] = BaselineIrrad791;
    BaselineIrradErrArray791[counts_791] = BaselineIrradErr791/2;
    FallTimeArray791[counts_791] = FallTime791;
    FallTimeErrArray791[counts_791] = FallTimeErr791/2;
    RiseTimeArray791[counts_791] = RiseTime791;
    RiseTimeErrArray791[counts_791] = RiseTimeErr791/2;
    aveAllts12Irrad791 += avets12Irrad791;
    maxAllts12Irrad791 += maxts12Irrad791;
    minAllts12Irrad791 += mints12Irrad791;
    UCNIntegralArrayAll[counts_791] = UCNIntegral791;
    UCNIntegralErrArrayAll[counts_791] = UCNIntegralErr791/2;
    delayTimeAll[counts_791] = cycleDelayTime791;
    HistIntegralArrayAll[counts_791] = HistIntegral791;
    HistIntegralErrArrayAll[counts_791] = sqrt (HistIntegral791)/2;
    counts_791++;
  }
  aveAllts12Irrad791 = aveAllts12Irrad791/counts_791;
  maxAllts12Irrad791 = maxAllts12Irrad791/counts_791;
  minAllts12Irrad791 = minAllts12Irrad791/counts_791;
  aveAllErrts12Irrad791 = (maxAllts12Irrad791 - minAllts12Irrad791)/2;




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
  //              791
  //*********************************
  //*********************************
  TCanvas *c791 = new TCanvas("c791" , "c791" , 1200, 800);
  c791 -> Divide(2,2);
  //c791 -> cd(1);
  TPad *p1 = c791->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr791_delaycounts = new TGraphErrors(counts_791, delaytimeArray791 , UCNIntegralArray791, 0, UCNIntegralErrArray791);

  gr791_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr791_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr791_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr791_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr791_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_delaycounts -> SetMarkerStyle(7);
  gr791_delaycounts -> Fit(fit);
  storage791 = fit -> GetParameter(1);
  storageErr791 = fit -> GetParError(1);
  
  TGraphErrors *gr791_delayhist = new TGraphErrors(counts_791, delaytimeArray791 , HistIntegralArray791, 0, HistIntegralErrArray791);

  gr791_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr791_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr791_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr791_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr791_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr791_delayhist -> SetMarkerColor(2);
  gr791_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr791_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr791_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr791_delaycounts -> Draw("Ap");
  gr791_delayhist -> Draw("p");
  leg2 -> Draw();

  //c791 -> cd(2);
  TPad *p2 = c791->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr791_tempIrradcounts = new TGraphErrors (counts_791 , avets12IrradArray791, UCNIntegralArray791 , ts12IrradErr791 , UCNIntegralErrArray791);
  gr791_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr791_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr791_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr791_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr791_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr791_tempValveOpencounts = new TGraphErrors (counts_791 , avets12ValveOpenArray791, UCNIntegralArray791 , ts12ValveOpenErr791 , UCNIntegralErrArray791);
  gr791_tempValveOpencounts -> SetMarkerStyle(7);
  gr791_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr791_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr791_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr791_tempIrradcounts -> Draw("Ap");
  gr791_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c791 -> cd(3);
  TGraphErrors *gr791_delaytempIrrad = new TGraphErrors (counts_791 , delaytimeArray791, avets12IrradArray791, 0 , ts12IrradErr791);

  gr791_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr791_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr791_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr791_delaytempIrrad -> SetMarkerStyle(7);
  gr791_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr791_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr791_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr791_delaytempValveOpen = new TGraphErrors (counts_791 , delaytimeArray791, avets12ValveOpenArray791, 0 , ts12ValveOpenErr791);

  gr791_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr791_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr791_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr791_delaytempValveOpen -> SetMarkerStyle(7);
  gr791_delaytempValveOpen -> SetMarkerColor(2);
  gr791_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr791_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr791_delaytempIrrad -> Draw("AP");
  gr791_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c791->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr791_curcounts = new TGraphErrors (counts_791 , avecurArray791, UCNIntegralArray791 , ErrcurArray791 , UCNIntegralErrArray791);
  gr791_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr791_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr791_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr791_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr791_curhist = new TGraphErrors (counts_791 , avecurArray791, UCNIntegralArray791 , ErrcurArray791 , UCNIntegralErrArray791);
  gr791_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr791_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr791_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr791_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr791_curhist -> SetMarkerColor(2);
  gr791_curhist -> SetMarkerStyle(7);

  gr791_curcounts -> Draw("Ap");
  gr791_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c791_cycleNum = new TCanvas("c791_cycleNum" , "c791_cycleNum" , 1200, 800);
  c791_cycleNum -> Divide(2,2);
  TPad *p5 = c791_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr791_cyclecounts = new TGraphErrors (counts_791 , cycleNumberArray791, UCNIntegralArray791, 0 , UCNIntegralErrArray791);
  gr791_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr791_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr791_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr791_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr791_cyclehist = new TGraphErrors(counts_791, cycleNumberArray791 , HistIntegralArray791, 0, HistIntegralErrArray791);

  gr791_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr791_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr791_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr791_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr791_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr791_cyclehist -> SetMarkerColor(2);
  gr791_cyclehist -> SetMarkerStyle(7);

  gr791_cyclecounts -> Draw("Ap");
  gr791_cyclehist -> Draw("p");

  leg2-> Draw();

  c791_cycleNum -> cd(2);
 TGraphErrors *gr791_cycledelay = new TGraphErrors (counts_791 , cycleNumberArray791, delaytimeArray791, 0 , 0);
  gr791_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr791_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr791_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr791_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cycledelay -> SetMarkerStyle(7);

  gr791_cycledelay -> Draw("Ap");


  c791_cycleNum -> cd(3);
  TGraphErrors *gr791_cycletempIrrad = new TGraphErrors (counts_791 , cycleNumberArray791, avets12IrradArray791, 0 , ts12IrradErr791);

  gr791_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr791_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr791_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr791_cycletempIrrad -> SetMarkerStyle(7);
  gr791_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr791_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr791_cycletempValveOpen = new TGraphErrors (counts_791 , cycleNumberArray791, avets12ValveOpenArray791, 0 , ts12ValveOpenErr791);

  gr791_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr791_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr791_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr791_cycletempValveOpen -> SetMarkerStyle(7);
  gr791_cycletempValveOpen -> SetMarkerColor(2);
  gr791_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr791_cycletempIrrad -> Draw("AP");
  gr791_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c791_cycleNum -> cd(4);
  TGraphErrors *gr791_cyclecur = new TGraphErrors (counts_791 , cycleNumberArray791 , avecurArray791, 0, ErrcurArray791 );
  gr791_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr791_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr791_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr791_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclecur -> SetMarkerStyle(7);
  gr791_cyclecur -> Draw("Ap");


  TCanvas *c791_cycleNumFit = new TCanvas("c791_cycleNumFit" , "c791_cycleNumFit" , 1200, 800);
  c791_cycleNumFit -> Divide(2,2);

  c791_cycleNumFit -> cd(1);
  TGraphErrors *gr791_cyclefall = new TGraphErrors (counts_791, cycleNumberArray791, FallTimeArray791 , 0, FallTimeErrArray791);

  gr791_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr791_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr791_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr791_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclefall -> SetMarkerStyle(7);
  gr791_cyclefall -> Draw("Ap");


  c791_cycleNumFit -> cd(2);
  TGraphErrors *gr791_cyclebaseline = new TGraphErrors (counts_791, cycleNumberArray791, BaselineArray791 , 0, BaselineErrArray791);

  gr791_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr791_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr791_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr791_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclebaseline -> SetMarkerStyle(7);
  gr791_cyclebaseline -> Draw("Ap");

  c791_cycleNumFit -> cd(3);
  TGraphErrors *gr791_cyclebaselineirrad = new TGraphErrors (counts_791, cycleNumberArray791, BaselineIrradArray791 , 0, BaselineIrradErrArray791);

  gr791_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr791_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr791_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr791_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclebaselineirrad -> SetMarkerStyle(7);
  gr791_cyclebaselineirrad -> Draw("Ap");

  c791_cycleNumFit -> cd(4);
  TGraphErrors *gr791_cyclerise = new TGraphErrors (counts_791, cycleNumberArray791, RiseTimeArray791 , 0, RiseTimeErrArray791);

  gr791_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr791_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr791_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr791_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr791_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr791_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr791_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr791_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr791_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr791_cyclerise -> SetMarkerStyle(7);
  gr791_cyclerise -> Draw("Ap");








}
