//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17029A.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17029A_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin832 = new TFile("outputTree_StorageTime_832.root","READ");



  
  TTree *outputTree832 = (TTree*) fin832 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime832;





  outputTree832 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime832);


  // DELAY TIME (ARRAY)
  double delaytimeArray832 [100];



  // CYCLE NUMBER
  int cycleNumber832;



  outputTree832 -> SetBranchAddress ("cycleNumber" , &cycleNumber832);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray832 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral832;

  outputTree832 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral832);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray832 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr832;

  double UCNIntegralErr613;


  outputTree832 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr832);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray832 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral832;



  outputTree832 -> SetBranchAddress ("HistIntegral" , &HistIntegral832); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray832 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr832;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray832 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad832;


  outputTree832 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad832);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen832;

  outputTree832 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen832);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray832 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray832 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad832;


  outputTree832 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad832);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen832;



  outputTree832 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen832);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray832 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray832 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad832;



  outputTree832 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad832);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen832;

  
  outputTree832 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen832);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray832 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray832 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr832 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr832 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur832;


  outputTree832 -> SetBranchAddress ("AVE_PRDCUR" , &avecur832);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray832 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur832;
 

  outputTree832 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur832);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray832 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur832;


  outputTree832 -> SetBranchAddress ("MIN_PRDCUR" , &mincur832);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray832 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray832 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline832;


  outputTree832 -> SetBranchAddress ("Baseline" , &Baseline832);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray832 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr832;

 
  outputTree832 -> SetBranchAddress ("BaselineErr" , &BaselineErr832);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray832 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad832;

 
  outputTree832 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad832);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray832 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr832;


  outputTree832 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr832);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray832 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime832;


  outputTree832 -> SetBranchAddress ("FallTime" , &FallTime832);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray832 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr832;


  outputTree832 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr832);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray832 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime832;


  outputTree832 -> SetBranchAddress ("RiseTime" , &RiseTime832);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray832 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr832;


  outputTree832 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr832);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray832 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad832;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad832;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad832;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad832;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage832;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr832;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_832 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events832;
  events832 = (Double_t)outputTree832 -> GetEntries();

  for (ULong64_t j = 0 ; j < events832 ; j++){
    outputTree832 -> GetEvent(j);
    //if (j==8)
    //  continue;
    UCNIntegralArray832[counts_832] = UCNIntegral832;
    UCNIntegralErrArray832[counts_832] = UCNIntegralErr832/2;
    HistIntegralArray832[counts_832] = HistIntegral832;
    HistIntegralErrArray832[counts_832] = sqrt (HistIntegral832)/2;
    avets12IrradArray832[counts_832] = avets12Irrad832;
    avets12ValveOpenArray832[counts_832] = avets12ValveOpen832;
    maxts12IrradArray832[counts_832] = maxts12Irrad832;
    maxts12ValveOpenArray832[counts_832] = maxts12ValveOpen832;
    mints12IrradArray832[counts_832] = mints12Irrad832; 
    mints12ValveOpenArray832[counts_832] = mints12ValveOpen832;
    ts12IrradErr832[counts_832] = (maxts12Irrad832 - mints12Irrad832)/2;
    ts12ValveOpenErr832[counts_832] = (maxts12ValveOpen832 - mints12ValveOpen832)/2;
    avecurArray832[counts_832] = avecur832;
    maxcurArray832[counts_832] = maxcur832;
    mincurArray832[counts_832] = mincur832;
    ErrcurArray832[counts_832] = (maxcur832 - mincur832)/2;
    delaytimeArray832[counts_832] = cycleDelayTime832;
    cycleNumberArray832[counts_832] = cycleNumber832;
    BaselineArray832[counts_832] = Baseline832;
    BaselineIrradArray832[counts_832] = BaselineIrrad832;
    BaselineIrradErrArray832[counts_832] = BaselineIrradErr832/2;
    FallTimeArray832[counts_832] = FallTime832;
    FallTimeErrArray832[counts_832] = FallTimeErr832/2;
    RiseTimeArray832[counts_832] = RiseTime832;
    RiseTimeErrArray832[counts_832] = RiseTimeErr832/2;
    aveAllts12Irrad832 += avets12Irrad832;
    maxAllts12Irrad832 += maxts12Irrad832;
    minAllts12Irrad832 += mints12Irrad832;
    UCNIntegralArrayAll[counts_832] = UCNIntegral832;
    UCNIntegralErrArrayAll[counts_832] = UCNIntegralErr832/2;
    delayTimeAll[counts_832] = cycleDelayTime832;
    HistIntegralArrayAll[counts_832] = HistIntegral832;
    HistIntegralErrArrayAll[counts_832] = sqrt (HistIntegral832)/2;
    counts_832++;
  }
  aveAllts12Irrad832 = aveAllts12Irrad832/counts_832;
  maxAllts12Irrad832 = maxAllts12Irrad832/counts_832;
  minAllts12Irrad832 = minAllts12Irrad832/counts_832;
  aveAllErrts12Irrad832 = (maxAllts12Irrad832 - minAllts12Irrad832)/2;




  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(100000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 5, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************


  //*********************************
  //*********************************
  //              832
  //*********************************
  //*********************************
  TCanvas *c832 = new TCanvas("c832" , "c832" , 1200, 800);
  c832 -> Divide(2,2);
  //c832 -> cd(1);
  TPad *p1 = c832->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr832_delaycounts = new TGraphErrors(counts_832, delaytimeArray832 , UCNIntegralArray832, 0, UCNIntegralErrArray832);

  gr832_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr832_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr832_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr832_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr832_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_delaycounts -> SetMarkerStyle(7);
  gr832_delaycounts -> Fit(fit);
  storage832 = fit -> GetParameter(1);
  storageErr832 = fit -> GetParError(1);
  
  TGraphErrors *gr832_delayhist = new TGraphErrors(counts_832, delaytimeArray832 , HistIntegralArray832, 0, HistIntegralErrArray832);

  gr832_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr832_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr832_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr832_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr832_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr832_delayhist -> SetMarkerColor(2);
  gr832_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr832_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr832_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr832_delaycounts -> Draw("Ap");
  gr832_delayhist -> Draw("p");
  leg2 -> Draw();

  //c832 -> cd(2);
  TPad *p2 = c832->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr832_tempIrradcounts = new TGraphErrors (counts_832 , avets12IrradArray832, UCNIntegralArray832 , ts12IrradErr832 , UCNIntegralErrArray832);
  gr832_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr832_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr832_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr832_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr832_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr832_tempValveOpencounts = new TGraphErrors (counts_832 , avets12ValveOpenArray832, UCNIntegralArray832 , ts12ValveOpenErr832 , UCNIntegralErrArray832);
  gr832_tempValveOpencounts -> SetMarkerStyle(7);
  gr832_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr832_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr832_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr832_tempIrradcounts -> Draw("Ap");
  gr832_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c832 -> cd(3);
  TGraphErrors *gr832_delaytempIrrad = new TGraphErrors (counts_832 , delaytimeArray832, avets12IrradArray832, 0 , ts12IrradErr832);

  gr832_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr832_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr832_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr832_delaytempIrrad -> SetMarkerStyle(7);
  gr832_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr832_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr832_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr832_delaytempValveOpen = new TGraphErrors (counts_832 , delaytimeArray832, avets12ValveOpenArray832, 0 , ts12ValveOpenErr832);

  gr832_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr832_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr832_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr832_delaytempValveOpen -> SetMarkerStyle(7);
  gr832_delaytempValveOpen -> SetMarkerColor(2);
  gr832_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr832_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr832_delaytempIrrad -> Draw("AP");
  gr832_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c832->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr832_curcounts = new TGraphErrors (counts_832 , avecurArray832, UCNIntegralArray832 , ErrcurArray832 , UCNIntegralErrArray832);
  gr832_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr832_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr832_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr832_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr832_curhist = new TGraphErrors (counts_832 , avecurArray832, UCNIntegralArray832 , ErrcurArray832 , UCNIntegralErrArray832);
  gr832_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr832_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr832_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr832_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr832_curhist -> SetMarkerColor(2);
  gr832_curhist -> SetMarkerStyle(7);

  gr832_curcounts -> Draw("Ap");
  gr832_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c832_cycleNum = new TCanvas("c832_cycleNum" , "c832_cycleNum" , 1200, 800);
  c832_cycleNum -> Divide(2,2);
  TPad *p5 = c832_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr832_cyclecounts = new TGraphErrors (counts_832 , cycleNumberArray832, UCNIntegralArray832, 0 , UCNIntegralErrArray832);
  gr832_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr832_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr832_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr832_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr832_cyclehist = new TGraphErrors(counts_832, cycleNumberArray832 , HistIntegralArray832, 0, HistIntegralErrArray832);

  gr832_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr832_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr832_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr832_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr832_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr832_cyclehist -> SetMarkerColor(2);
  gr832_cyclehist -> SetMarkerStyle(7);

  gr832_cyclecounts -> Draw("Ap");
  gr832_cyclehist -> Draw("p");

  leg2-> Draw();

  c832_cycleNum -> cd(2);
 TGraphErrors *gr832_cycledelay = new TGraphErrors (counts_832 , cycleNumberArray832, delaytimeArray832, 0 , 0);
  gr832_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr832_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr832_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr832_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cycledelay -> SetMarkerStyle(7);

  gr832_cycledelay -> Draw("Ap");


  c832_cycleNum -> cd(3);
  TGraphErrors *gr832_cycletempIrrad = new TGraphErrors (counts_832 , cycleNumberArray832, avets12IrradArray832, 0 , ts12IrradErr832);

  gr832_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr832_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr832_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr832_cycletempIrrad -> SetMarkerStyle(7);
  gr832_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr832_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr832_cycletempValveOpen = new TGraphErrors (counts_832 , cycleNumberArray832, avets12ValveOpenArray832, 0 , ts12ValveOpenErr832);

  gr832_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr832_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr832_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr832_cycletempValveOpen -> SetMarkerStyle(7);
  gr832_cycletempValveOpen -> SetMarkerColor(2);
  gr832_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr832_cycletempIrrad -> Draw("AP");
  gr832_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c832_cycleNum -> cd(4);
  TGraphErrors *gr832_cyclecur = new TGraphErrors (counts_832 , cycleNumberArray832 , avecurArray832, 0, ErrcurArray832 );
  gr832_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr832_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr832_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr832_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclecur -> SetMarkerStyle(7);
  gr832_cyclecur -> Draw("Ap");


  TCanvas *c832_cycleNumFit = new TCanvas("c832_cycleNumFit" , "c832_cycleNumFit" , 1200, 800);
  c832_cycleNumFit -> Divide(2,2);

  c832_cycleNumFit -> cd(1);
  TGraphErrors *gr832_cyclefall = new TGraphErrors (counts_832, cycleNumberArray832, FallTimeArray832 , 0, FallTimeErrArray832);

  gr832_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr832_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr832_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr832_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclefall -> SetMarkerStyle(7);
  gr832_cyclefall -> Draw("Ap");


  c832_cycleNumFit -> cd(2);
  TGraphErrors *gr832_cyclebaseline = new TGraphErrors (counts_832, cycleNumberArray832, BaselineArray832 , 0, BaselineErrArray832);

  gr832_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr832_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr832_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr832_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclebaseline -> SetMarkerStyle(7);
  gr832_cyclebaseline -> Draw("Ap");

  c832_cycleNumFit -> cd(3);
  TGraphErrors *gr832_cyclebaselineirrad = new TGraphErrors (counts_832, cycleNumberArray832, BaselineIrradArray832 , 0, BaselineIrradErrArray832);

  gr832_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr832_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr832_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr832_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclebaselineirrad -> SetMarkerStyle(7);
  gr832_cyclebaselineirrad -> Draw("Ap");

  c832_cycleNumFit -> cd(4);
  TGraphErrors *gr832_cyclerise = new TGraphErrors (counts_832, cycleNumberArray832, RiseTimeArray832 , 0, RiseTimeErrArray832);

  gr832_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr832_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr832_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr832_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr832_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr832_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr832_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr832_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr832_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr832_cyclerise -> SetMarkerStyle(7);
  gr832_cyclerise -> Draw("Ap");








  




}
