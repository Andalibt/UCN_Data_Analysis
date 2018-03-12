//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17025.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17025_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin819 = new TFile("outputTree_StorageTime_819.root","READ");



  
  TTree *outputTree819 = (TTree*) fin819 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime819;





  outputTree819 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime819);


  // DELAY TIME (ARRAY)
  double delaytimeArray819 [100];



  // CYCLE NUMBER
  int cycleNumber819;



  outputTree819 -> SetBranchAddress ("cycleNumber" , &cycleNumber819);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray819 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral819;

  outputTree819 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral819);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray819 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr819;

  double UCNIntegralErr613;


  outputTree819 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr819);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray819 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral819;



  outputTree819 -> SetBranchAddress ("HistIntegral" , &HistIntegral819); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray819 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr819;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray819 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad819;


  outputTree819 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad819);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen819;

  outputTree819 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen819);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray819 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray819 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad819;


  outputTree819 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad819);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen819;



  outputTree819 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen819);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray819 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray819 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad819;



  outputTree819 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad819);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen819;

  
  outputTree819 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen819);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray819 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray819 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr819 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr819 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur819;


  outputTree819 -> SetBranchAddress ("AVE_PRDCUR" , &avecur819);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray819 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur819;
 

  outputTree819 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur819);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray819 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur819;


  outputTree819 -> SetBranchAddress ("MIN_PRDCUR" , &mincur819);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray819 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray819 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline819;


  outputTree819 -> SetBranchAddress ("Baseline" , &Baseline819);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray819 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr819;

 
  outputTree819 -> SetBranchAddress ("BaselineErr" , &BaselineErr819);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray819 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad819;

 
  outputTree819 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad819);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray819 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr819;


  outputTree819 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr819);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray819 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime819;


  outputTree819 -> SetBranchAddress ("FallTime" , &FallTime819);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray819 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr819;


  outputTree819 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr819);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray819 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime819;


  outputTree819 -> SetBranchAddress ("RiseTime" , &RiseTime819);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray819 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr819;


  outputTree819 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr819);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray819 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad819;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad819;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad819;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad819;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage819;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr819;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_819 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events819;
  events819 = (Double_t)outputTree819 -> GetEntries();

  for (ULong64_t j = 0 ; j < events819 ; j++){
    outputTree819 -> GetEvent(j);
    UCNIntegralArray819[counts_819] = UCNIntegral819;
    UCNIntegralErrArray819[counts_819] = UCNIntegralErr819/2;
    HistIntegralArray819[counts_819] = HistIntegral819;
    HistIntegralErrArray819[counts_819] = sqrt (HistIntegral819)/2;
    avets12IrradArray819[counts_819] = avets12Irrad819;
    avets12ValveOpenArray819[counts_819] = avets12ValveOpen819;
    maxts12IrradArray819[counts_819] = maxts12Irrad819;
    maxts12ValveOpenArray819[counts_819] = maxts12ValveOpen819;
    mints12IrradArray819[counts_819] = mints12Irrad819; 
    mints12ValveOpenArray819[counts_819] = mints12ValveOpen819;
    ts12IrradErr819[counts_819] = (maxts12Irrad819 - mints12Irrad819)/2;
    ts12ValveOpenErr819[counts_819] = (maxts12ValveOpen819 - mints12ValveOpen819)/2;
    avecurArray819[counts_819] = avecur819;
    maxcurArray819[counts_819] = maxcur819;
    mincurArray819[counts_819] = mincur819;
    ErrcurArray819[counts_819] = (maxcur819 - mincur819)/2;
    delaytimeArray819[counts_819] = cycleDelayTime819;
    cycleNumberArray819[counts_819] = cycleNumber819;
    BaselineArray819[counts_819] = Baseline819;
    BaselineIrradArray819[counts_819] = BaselineIrrad819;
    BaselineIrradErrArray819[counts_819] = BaselineIrradErr819/2;
    FallTimeArray819[counts_819] = FallTime819;
    FallTimeErrArray819[counts_819] = FallTimeErr819/2;
    RiseTimeArray819[counts_819] = RiseTime819;
    RiseTimeErrArray819[counts_819] = RiseTimeErr819/2;
    aveAllts12Irrad819 += avets12Irrad819;
    maxAllts12Irrad819 += maxts12Irrad819;
    minAllts12Irrad819 += mints12Irrad819;
    UCNIntegralArrayAll[counts_819] = UCNIntegral819;
    UCNIntegralErrArrayAll[counts_819] = UCNIntegralErr819/2;
    delayTimeAll[counts_819] = cycleDelayTime819;
    HistIntegralArrayAll[counts_819] = HistIntegral819;
    HistIntegralErrArrayAll[counts_819] = sqrt (HistIntegral819)/2;
    counts_819++;
  }
  aveAllts12Irrad819 = aveAllts12Irrad819/counts_819;
  maxAllts12Irrad819 = maxAllts12Irrad819/counts_819;
  minAllts12Irrad819 = minAllts12Irrad819/counts_819;
  aveAllErrts12Irrad819 = (maxAllts12Irrad819 - minAllts12Irrad819)/2;




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
  //              819
  //*********************************
  //*********************************
  TCanvas *c819 = new TCanvas("c819" , "c819" , 1200, 800);
  c819 -> Divide(2,2);
  //c819 -> cd(1);
  TPad *p1 = c819->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr819_delaycounts = new TGraphErrors(counts_819, delaytimeArray819 , UCNIntegralArray819, 0, UCNIntegralErrArray819);

  gr819_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr819_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr819_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr819_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr819_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_delaycounts -> SetMarkerStyle(7);
  gr819_delaycounts -> Fit(fit);
  storage819 = fit -> GetParameter(1);
  storageErr819 = fit -> GetParError(1);
  
  TGraphErrors *gr819_delayhist = new TGraphErrors(counts_819, delaytimeArray819 , HistIntegralArray819, 0, HistIntegralErrArray819);

  gr819_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr819_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr819_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr819_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr819_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr819_delayhist -> SetMarkerColor(2);
  gr819_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr819_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr819_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr819_delaycounts -> Draw("Ap");
  gr819_delayhist -> Draw("p");
  leg2 -> Draw();

  //c819 -> cd(2);
  TPad *p2 = c819->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr819_tempIrradcounts = new TGraphErrors (counts_819 , avets12IrradArray819, UCNIntegralArray819 , ts12IrradErr819 , UCNIntegralErrArray819);
  gr819_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr819_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr819_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr819_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr819_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr819_tempValveOpencounts = new TGraphErrors (counts_819 , avets12ValveOpenArray819, UCNIntegralArray819 , ts12ValveOpenErr819 , UCNIntegralErrArray819);
  gr819_tempValveOpencounts -> SetMarkerStyle(7);
  gr819_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr819_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr819_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr819_tempIrradcounts -> Draw("Ap");
  gr819_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c819 -> cd(3);
  TGraphErrors *gr819_delaytempIrrad = new TGraphErrors (counts_819 , delaytimeArray819, avets12IrradArray819, 0 , ts12IrradErr819);

  gr819_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr819_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr819_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr819_delaytempIrrad -> SetMarkerStyle(7);
  gr819_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr819_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr819_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr819_delaytempValveOpen = new TGraphErrors (counts_819 , delaytimeArray819, avets12ValveOpenArray819, 0 , ts12ValveOpenErr819);

  gr819_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr819_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr819_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr819_delaytempValveOpen -> SetMarkerStyle(7);
  gr819_delaytempValveOpen -> SetMarkerColor(2);
  gr819_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr819_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr819_delaytempIrrad -> Draw("AP");
  gr819_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c819->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr819_curcounts = new TGraphErrors (counts_819 , avecurArray819, UCNIntegralArray819 , ErrcurArray819 , UCNIntegralErrArray819);
  gr819_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr819_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr819_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr819_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr819_curhist = new TGraphErrors (counts_819 , avecurArray819, UCNIntegralArray819 , ErrcurArray819 , UCNIntegralErrArray819);
  gr819_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr819_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr819_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr819_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr819_curhist -> SetMarkerColor(2);
  gr819_curhist -> SetMarkerStyle(7);

  gr819_curcounts -> Draw("Ap");
  gr819_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c819_cycleNum = new TCanvas("c819_cycleNum" , "c819_cycleNum" , 1200, 800);
  c819_cycleNum -> Divide(2,2);
  TPad *p5 = c819_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr819_cyclecounts = new TGraphErrors (counts_819 , cycleNumberArray819, UCNIntegralArray819, 0 , UCNIntegralErrArray819);
  gr819_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr819_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr819_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr819_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr819_cyclehist = new TGraphErrors(counts_819, cycleNumberArray819 , HistIntegralArray819, 0, HistIntegralErrArray819);

  gr819_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr819_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr819_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr819_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr819_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr819_cyclehist -> SetMarkerColor(2);
  gr819_cyclehist -> SetMarkerStyle(7);

  gr819_cyclecounts -> Draw("Ap");
  gr819_cyclehist -> Draw("p");

  leg2-> Draw();

  c819_cycleNum -> cd(2);
 TGraphErrors *gr819_cycledelay = new TGraphErrors (counts_819 , cycleNumberArray819, delaytimeArray819, 0 , 0);
  gr819_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr819_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr819_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr819_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cycledelay -> SetMarkerStyle(7);

  gr819_cycledelay -> Draw("Ap");


  c819_cycleNum -> cd(3);
  TGraphErrors *gr819_cycletempIrrad = new TGraphErrors (counts_819 , cycleNumberArray819, avets12IrradArray819, 0 , ts12IrradErr819);

  gr819_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr819_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr819_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr819_cycletempIrrad -> SetMarkerStyle(7);
  gr819_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr819_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr819_cycletempValveOpen = new TGraphErrors (counts_819 , cycleNumberArray819, avets12ValveOpenArray819, 0 , ts12ValveOpenErr819);

  gr819_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr819_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr819_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr819_cycletempValveOpen -> SetMarkerStyle(7);
  gr819_cycletempValveOpen -> SetMarkerColor(2);
  gr819_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr819_cycletempIrrad -> Draw("AP");
  gr819_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c819_cycleNum -> cd(4);
  TGraphErrors *gr819_cyclecur = new TGraphErrors (counts_819 , cycleNumberArray819 , avecurArray819, 0, ErrcurArray819 );
  gr819_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr819_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr819_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr819_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclecur -> SetMarkerStyle(7);
  gr819_cyclecur -> Draw("Ap");


  TCanvas *c819_cycleNumFit = new TCanvas("c819_cycleNumFit" , "c819_cycleNumFit" , 1200, 800);
  c819_cycleNumFit -> Divide(2,2);

  c819_cycleNumFit -> cd(1);
  TGraphErrors *gr819_cyclefall = new TGraphErrors (counts_819, cycleNumberArray819, FallTimeArray819 , 0, FallTimeErrArray819);

  gr819_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr819_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr819_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr819_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclefall -> SetMarkerStyle(7);
  gr819_cyclefall -> Draw("Ap");


  c819_cycleNumFit -> cd(2);
  TGraphErrors *gr819_cyclebaseline = new TGraphErrors (counts_819, cycleNumberArray819, BaselineArray819 , 0, BaselineErrArray819);

  gr819_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr819_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr819_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr819_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclebaseline -> SetMarkerStyle(7);
  gr819_cyclebaseline -> Draw("Ap");

  c819_cycleNumFit -> cd(3);
  TGraphErrors *gr819_cyclebaselineirrad = new TGraphErrors (counts_819, cycleNumberArray819, BaselineIrradArray819 , 0, BaselineIrradErrArray819);

  gr819_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr819_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr819_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr819_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclebaselineirrad -> SetMarkerStyle(7);
  gr819_cyclebaselineirrad -> Draw("Ap");

  c819_cycleNumFit -> cd(4);
  TGraphErrors *gr819_cyclerise = new TGraphErrors (counts_819, cycleNumberArray819, RiseTimeArray819 , 0, RiseTimeErrArray819);

  gr819_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr819_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr819_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr819_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr819_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr819_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr819_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr819_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr819_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr819_cyclerise -> SetMarkerStyle(7);
  gr819_cyclerise -> Draw("Ap");








  




}
