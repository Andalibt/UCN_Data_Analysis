//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17023.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17023_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin813 = new TFile("outputTree_StorageTime_813.root","READ");



  
  TTree *outputTree813 = (TTree*) fin813 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime813;





  outputTree813 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime813);


  // DELAY TIME (ARRAY)
  double delaytimeArray813 [100];



  // CYCLE NUMBER
  int cycleNumber813;



  outputTree813 -> SetBranchAddress ("cycleNumber" , &cycleNumber813);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray813 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral813;

  outputTree813 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral813);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray813 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr813;

  double UCNIntegralErr613;


  outputTree813 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr813);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray813 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral813;



  outputTree813 -> SetBranchAddress ("HistIntegral" , &HistIntegral813); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray813 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr813;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray813 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad813;


  outputTree813 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad813);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen813;

  outputTree813 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen813);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray813 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray813 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad813;


  outputTree813 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad813);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen813;



  outputTree813 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen813);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray813 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray813 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad813;



  outputTree813 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad813);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen813;

  
  outputTree813 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen813);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray813 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray813 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr813 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr813 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur813;


  outputTree813 -> SetBranchAddress ("AVE_PRDCUR" , &avecur813);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray813 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur813;
 

  outputTree813 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur813);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray813 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur813;


  outputTree813 -> SetBranchAddress ("MIN_PRDCUR" , &mincur813);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray813 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray813 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline813;


  outputTree813 -> SetBranchAddress ("Baseline" , &Baseline813);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray813 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr813;

 
  outputTree813 -> SetBranchAddress ("BaselineErr" , &BaselineErr813);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray813 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad813;

 
  outputTree813 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad813);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray813 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr813;


  outputTree813 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr813);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray813 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime813;


  outputTree813 -> SetBranchAddress ("FallTime" , &FallTime813);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray813 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr813;


  outputTree813 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr813);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray813 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime813;


  outputTree813 -> SetBranchAddress ("RiseTime" , &RiseTime813);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray813 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr813;


  outputTree813 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr813);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray813 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad813;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad813;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad813;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad813;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage813;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr813;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_813 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events813;
  events813 = (Double_t)outputTree813 -> GetEntries();

  for (ULong64_t j = 0 ; j < events813 ; j++){
    outputTree813 -> GetEvent(j);
    UCNIntegralArray813[counts_813] = UCNIntegral813;
    UCNIntegralErrArray813[counts_813] = UCNIntegralErr813/2;
    HistIntegralArray813[counts_813] = HistIntegral813;
    HistIntegralErrArray813[counts_813] = sqrt (HistIntegral813)/2;
    avets12IrradArray813[counts_813] = avets12Irrad813;
    avets12ValveOpenArray813[counts_813] = avets12ValveOpen813;
    maxts12IrradArray813[counts_813] = maxts12Irrad813;
    maxts12ValveOpenArray813[counts_813] = maxts12ValveOpen813;
    mints12IrradArray813[counts_813] = mints12Irrad813; 
    mints12ValveOpenArray813[counts_813] = mints12ValveOpen813;
    ts12IrradErr813[counts_813] = (maxts12Irrad813 - mints12Irrad813)/2;
    ts12ValveOpenErr813[counts_813] = (maxts12ValveOpen813 - mints12ValveOpen813)/2;
    avecurArray813[counts_813] = avecur813;
    maxcurArray813[counts_813] = maxcur813;
    mincurArray813[counts_813] = mincur813;
    ErrcurArray813[counts_813] = (maxcur813 - mincur813)/2;
    delaytimeArray813[counts_813] = cycleDelayTime813;
    cycleNumberArray813[counts_813] = cycleNumber813;
    BaselineArray813[counts_813] = Baseline813;
    BaselineIrradArray813[counts_813] = BaselineIrrad813;
    BaselineIrradErrArray813[counts_813] = BaselineIrradErr813/2;
    FallTimeArray813[counts_813] = FallTime813;
    FallTimeErrArray813[counts_813] = FallTimeErr813/2;
    RiseTimeArray813[counts_813] = RiseTime813;
    RiseTimeErrArray813[counts_813] = RiseTimeErr813/2;
    aveAllts12Irrad813 += avets12Irrad813;
    maxAllts12Irrad813 += maxts12Irrad813;
    minAllts12Irrad813 += mints12Irrad813;
    UCNIntegralArrayAll[counts_813] = UCNIntegral813;
    UCNIntegralErrArrayAll[counts_813] = UCNIntegralErr813/2;
    delayTimeAll[counts_813] = cycleDelayTime813;
    HistIntegralArrayAll[counts_813] = HistIntegral813;
    HistIntegralErrArrayAll[counts_813] = sqrt (HistIntegral813)/2;
    counts_813++;
  }
  aveAllts12Irrad813 = aveAllts12Irrad813/counts_813;
  maxAllts12Irrad813 = maxAllts12Irrad813/counts_813;
  minAllts12Irrad813 = minAllts12Irrad813/counts_813;
  aveAllErrts12Irrad813 = (maxAllts12Irrad813 - minAllts12Irrad813)/2;




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
  //              813
  //*********************************
  //*********************************
  TCanvas *c813 = new TCanvas("c813" , "c813" , 1200, 800);
  c813 -> Divide(2,2);
  //c813 -> cd(1);
  TPad *p1 = c813->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr813_delaycounts = new TGraphErrors(counts_813, delaytimeArray813 , UCNIntegralArray813, 0, UCNIntegralErrArray813);

  gr813_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr813_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr813_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr813_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr813_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_delaycounts -> SetMarkerStyle(7);
  gr813_delaycounts -> Fit(fit);
  storage813 = fit -> GetParameter(1);
  storageErr813 = fit -> GetParError(1);
  
  TGraphErrors *gr813_delayhist = new TGraphErrors(counts_813, delaytimeArray813 , HistIntegralArray813, 0, HistIntegralErrArray813);

  gr813_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr813_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr813_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr813_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr813_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr813_delayhist -> SetMarkerColor(2);
  gr813_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr813_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr813_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr813_delaycounts -> Draw("Ap");
  gr813_delayhist -> Draw("p");
  leg2 -> Draw();

  //c813 -> cd(2);
  TPad *p2 = c813->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr813_tempIrradcounts = new TGraphErrors (counts_813 , avets12IrradArray813, UCNIntegralArray813 , ts12IrradErr813 , UCNIntegralErrArray813);
  gr813_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr813_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr813_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr813_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr813_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr813_tempValveOpencounts = new TGraphErrors (counts_813 , avets12ValveOpenArray813, UCNIntegralArray813 , ts12ValveOpenErr813 , UCNIntegralErrArray813);
  gr813_tempValveOpencounts -> SetMarkerStyle(7);
  gr813_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr813_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr813_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr813_tempIrradcounts -> Draw("Ap");
  gr813_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c813 -> cd(3);
  TGraphErrors *gr813_delaytempIrrad = new TGraphErrors (counts_813 , delaytimeArray813, avets12IrradArray813, 0 , ts12IrradErr813);

  gr813_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr813_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr813_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr813_delaytempIrrad -> SetMarkerStyle(7);
  gr813_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr813_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr813_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr813_delaytempValveOpen = new TGraphErrors (counts_813 , delaytimeArray813, avets12ValveOpenArray813, 0 , ts12ValveOpenErr813);

  gr813_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr813_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr813_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr813_delaytempValveOpen -> SetMarkerStyle(7);
  gr813_delaytempValveOpen -> SetMarkerColor(2);
  gr813_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr813_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr813_delaytempIrrad -> Draw("AP");
  gr813_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c813->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr813_curcounts = new TGraphErrors (counts_813 , avecurArray813, UCNIntegralArray813 , ErrcurArray813 , UCNIntegralErrArray813);
  gr813_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr813_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr813_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr813_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr813_curhist = new TGraphErrors (counts_813 , avecurArray813, UCNIntegralArray813 , ErrcurArray813 , UCNIntegralErrArray813);
  gr813_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr813_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr813_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr813_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr813_curhist -> SetMarkerColor(2);
  gr813_curhist -> SetMarkerStyle(7);

  gr813_curcounts -> Draw("Ap");
  gr813_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c813_cycleNum = new TCanvas("c813_cycleNum" , "c813_cycleNum" , 1200, 800);
  c813_cycleNum -> Divide(2,2);
  TPad *p5 = c813_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr813_cyclecounts = new TGraphErrors (counts_813 , cycleNumberArray813, UCNIntegralArray813, 0 , UCNIntegralErrArray813);
  gr813_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr813_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr813_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr813_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr813_cyclehist = new TGraphErrors(counts_813, cycleNumberArray813 , HistIntegralArray813, 0, HistIntegralErrArray813);

  gr813_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr813_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr813_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr813_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr813_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr813_cyclehist -> SetMarkerColor(2);
  gr813_cyclehist -> SetMarkerStyle(7);

  gr813_cyclecounts -> Draw("Ap");
  gr813_cyclehist -> Draw("p");

  leg2-> Draw();

  c813_cycleNum -> cd(2);
 TGraphErrors *gr813_cycledelay = new TGraphErrors (counts_813 , cycleNumberArray813, delaytimeArray813, 0 , 0);
  gr813_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr813_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr813_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr813_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cycledelay -> SetMarkerStyle(7);

  gr813_cycledelay -> Draw("Ap");


  c813_cycleNum -> cd(3);
  TGraphErrors *gr813_cycletempIrrad = new TGraphErrors (counts_813 , cycleNumberArray813, avets12IrradArray813, 0 , ts12IrradErr813);

  gr813_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr813_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr813_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr813_cycletempIrrad -> SetMarkerStyle(7);
  gr813_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr813_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr813_cycletempValveOpen = new TGraphErrors (counts_813 , cycleNumberArray813, avets12ValveOpenArray813, 0 , ts12ValveOpenErr813);

  gr813_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr813_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr813_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr813_cycletempValveOpen -> SetMarkerStyle(7);
  gr813_cycletempValveOpen -> SetMarkerColor(2);
  gr813_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr813_cycletempIrrad -> Draw("AP");
  gr813_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c813_cycleNum -> cd(4);
  TGraphErrors *gr813_cyclecur = new TGraphErrors (counts_813 , cycleNumberArray813 , avecurArray813, 0, ErrcurArray813 );
  gr813_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr813_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr813_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr813_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclecur -> SetMarkerStyle(7);
  gr813_cyclecur -> Draw("Ap");


  TCanvas *c813_cycleNumFit = new TCanvas("c813_cycleNumFit" , "c813_cycleNumFit" , 1200, 800);
  c813_cycleNumFit -> Divide(2,2);

  c813_cycleNumFit -> cd(1);
  TGraphErrors *gr813_cyclefall = new TGraphErrors (counts_813, cycleNumberArray813, FallTimeArray813 , 0, FallTimeErrArray813);

  gr813_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr813_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr813_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr813_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclefall -> SetMarkerStyle(7);
  gr813_cyclefall -> Draw("Ap");


  c813_cycleNumFit -> cd(2);
  TGraphErrors *gr813_cyclebaseline = new TGraphErrors (counts_813, cycleNumberArray813, BaselineArray813 , 0, BaselineErrArray813);

  gr813_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr813_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr813_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr813_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclebaseline -> SetMarkerStyle(7);
  gr813_cyclebaseline -> Draw("Ap");

  c813_cycleNumFit -> cd(3);
  TGraphErrors *gr813_cyclebaselineirrad = new TGraphErrors (counts_813, cycleNumberArray813, BaselineIrradArray813 , 0, BaselineIrradErrArray813);

  gr813_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr813_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr813_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr813_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclebaselineirrad -> SetMarkerStyle(7);
  gr813_cyclebaselineirrad -> Draw("Ap");

  c813_cycleNumFit -> cd(4);
  TGraphErrors *gr813_cyclerise = new TGraphErrors (counts_813, cycleNumberArray813, RiseTimeArray813 , 0, RiseTimeErrArray813);

  gr813_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr813_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr813_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr813_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr813_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr813_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr813_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr813_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr813_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr813_cyclerise -> SetMarkerStyle(7);
  gr813_cyclerise -> Draw("Ap");








  




}
