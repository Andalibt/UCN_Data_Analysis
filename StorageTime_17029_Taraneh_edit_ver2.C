//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17029.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17029_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin827 = new TFile("outputTree_StorageTime_827.root","READ");



  
  TTree *outputTree827 = (TTree*) fin827 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime827;





  outputTree827 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime827);


  // DELAY TIME (ARRAY)
  double delaytimeArray827 [100];



  // CYCLE NUMBER
  int cycleNumber827;



  outputTree827 -> SetBranchAddress ("cycleNumber" , &cycleNumber827);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray827 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral827;

  outputTree827 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral827);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray827 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr827;

  double UCNIntegralErr613;


  outputTree827 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr827);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray827 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral827;



  outputTree827 -> SetBranchAddress ("HistIntegral" , &HistIntegral827); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray827 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr827;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray827 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad827;


  outputTree827 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad827);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen827;

  outputTree827 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen827);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray827 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray827 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad827;


  outputTree827 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad827);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen827;



  outputTree827 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen827);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray827 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray827 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad827;



  outputTree827 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad827);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen827;

  
  outputTree827 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen827);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray827 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray827 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr827 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr827 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur827;


  outputTree827 -> SetBranchAddress ("AVE_PRDCUR" , &avecur827);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray827 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur827;
 

  outputTree827 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur827);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray827 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur827;


  outputTree827 -> SetBranchAddress ("MIN_PRDCUR" , &mincur827);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray827 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray827 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline827;


  outputTree827 -> SetBranchAddress ("Baseline" , &Baseline827);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray827 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr827;

 
  outputTree827 -> SetBranchAddress ("BaselineErr" , &BaselineErr827);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray827 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad827;

 
  outputTree827 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad827);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray827 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr827;


  outputTree827 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr827);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray827 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime827;


  outputTree827 -> SetBranchAddress ("FallTime" , &FallTime827);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray827 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr827;


  outputTree827 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr827);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray827 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime827;


  outputTree827 -> SetBranchAddress ("RiseTime" , &RiseTime827);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray827 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr827;


  outputTree827 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr827);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray827 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad827;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad827;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad827;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad827;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage827;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr827;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_827 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events827;
  events827 = (Double_t)outputTree827 -> GetEntries();

  for (ULong64_t j = 0 ; j < events827 ; j++){
    outputTree827 -> GetEvent(j);
    //if (j==8)
    //  continue;
    UCNIntegralArray827[counts_827] = UCNIntegral827;
    UCNIntegralErrArray827[counts_827] = UCNIntegralErr827/2;
    HistIntegralArray827[counts_827] = HistIntegral827;
    HistIntegralErrArray827[counts_827] = sqrt (HistIntegral827)/2;
    avets12IrradArray827[counts_827] = avets12Irrad827;
    avets12ValveOpenArray827[counts_827] = avets12ValveOpen827;
    maxts12IrradArray827[counts_827] = maxts12Irrad827;
    maxts12ValveOpenArray827[counts_827] = maxts12ValveOpen827;
    mints12IrradArray827[counts_827] = mints12Irrad827; 
    mints12ValveOpenArray827[counts_827] = mints12ValveOpen827;
    ts12IrradErr827[counts_827] = (maxts12Irrad827 - mints12Irrad827)/2;
    ts12ValveOpenErr827[counts_827] = (maxts12ValveOpen827 - mints12ValveOpen827)/2;
    avecurArray827[counts_827] = avecur827;
    maxcurArray827[counts_827] = maxcur827;
    mincurArray827[counts_827] = mincur827;
    ErrcurArray827[counts_827] = (maxcur827 - mincur827)/2;
    delaytimeArray827[counts_827] = cycleDelayTime827;
    cycleNumberArray827[counts_827] = cycleNumber827;
    BaselineArray827[counts_827] = Baseline827;
    BaselineIrradArray827[counts_827] = BaselineIrrad827;
    BaselineIrradErrArray827[counts_827] = BaselineIrradErr827/2;
    FallTimeArray827[counts_827] = FallTime827;
    FallTimeErrArray827[counts_827] = FallTimeErr827/2;
    RiseTimeArray827[counts_827] = RiseTime827;
    RiseTimeErrArray827[counts_827] = RiseTimeErr827/2;
    aveAllts12Irrad827 += avets12Irrad827;
    maxAllts12Irrad827 += maxts12Irrad827;
    minAllts12Irrad827 += mints12Irrad827;
    UCNIntegralArrayAll[counts_827] = UCNIntegral827;
    UCNIntegralErrArrayAll[counts_827] = UCNIntegralErr827/2;
    delayTimeAll[counts_827] = cycleDelayTime827;
    HistIntegralArrayAll[counts_827] = HistIntegral827;
    HistIntegralErrArrayAll[counts_827] = sqrt (HistIntegral827)/2;
    counts_827++;
  }
  aveAllts12Irrad827 = aveAllts12Irrad827/counts_827;
  maxAllts12Irrad827 = maxAllts12Irrad827/counts_827;
  minAllts12Irrad827 = minAllts12Irrad827/counts_827;
  aveAllErrts12Irrad827 = (maxAllts12Irrad827 - minAllts12Irrad827)/2;




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
  //              827
  //*********************************
  //*********************************
  TCanvas *c827 = new TCanvas("c827" , "c827" , 1200, 800);
  c827 -> Divide(2,2);
  //c827 -> cd(1);
  TPad *p1 = c827->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr827_delaycounts = new TGraphErrors(counts_827, delaytimeArray827 , UCNIntegralArray827, 0, UCNIntegralErrArray827);

  gr827_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr827_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr827_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr827_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr827_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_delaycounts -> SetMarkerStyle(7);
  gr827_delaycounts -> Fit(fit);
  storage827 = fit -> GetParameter(1);
  storageErr827 = fit -> GetParError(1);
  
  TGraphErrors *gr827_delayhist = new TGraphErrors(counts_827, delaytimeArray827 , HistIntegralArray827, 0, HistIntegralErrArray827);

  gr827_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr827_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr827_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr827_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr827_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr827_delayhist -> SetMarkerColor(2);
  gr827_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr827_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr827_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr827_delaycounts -> Draw("Ap");
  gr827_delayhist -> Draw("p");
  leg2 -> Draw();

  //c827 -> cd(2);
  TPad *p2 = c827->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr827_tempIrradcounts = new TGraphErrors (counts_827 , avets12IrradArray827, UCNIntegralArray827 , ts12IrradErr827 , UCNIntegralErrArray827);
  gr827_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr827_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr827_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr827_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr827_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr827_tempValveOpencounts = new TGraphErrors (counts_827 , avets12ValveOpenArray827, UCNIntegralArray827 , ts12ValveOpenErr827 , UCNIntegralErrArray827);
  gr827_tempValveOpencounts -> SetMarkerStyle(7);
  gr827_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr827_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr827_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr827_tempIrradcounts -> Draw("Ap");
  gr827_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c827 -> cd(3);
  TGraphErrors *gr827_delaytempIrrad = new TGraphErrors (counts_827 , delaytimeArray827, avets12IrradArray827, 0 , ts12IrradErr827);

  gr827_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr827_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr827_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr827_delaytempIrrad -> SetMarkerStyle(7);
  gr827_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr827_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr827_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr827_delaytempValveOpen = new TGraphErrors (counts_827 , delaytimeArray827, avets12ValveOpenArray827, 0 , ts12ValveOpenErr827);

  gr827_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr827_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr827_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr827_delaytempValveOpen -> SetMarkerStyle(7);
  gr827_delaytempValveOpen -> SetMarkerColor(2);
  gr827_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr827_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr827_delaytempIrrad -> Draw("AP");
  gr827_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c827->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr827_curcounts = new TGraphErrors (counts_827 , avecurArray827, UCNIntegralArray827 , ErrcurArray827 , UCNIntegralErrArray827);
  gr827_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr827_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr827_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr827_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr827_curhist = new TGraphErrors (counts_827 , avecurArray827, UCNIntegralArray827 , ErrcurArray827 , UCNIntegralErrArray827);
  gr827_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr827_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr827_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr827_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr827_curhist -> SetMarkerColor(2);
  gr827_curhist -> SetMarkerStyle(7);

  gr827_curcounts -> Draw("Ap");
  gr827_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c827_cycleNum = new TCanvas("c827_cycleNum" , "c827_cycleNum" , 1200, 800);
  c827_cycleNum -> Divide(2,2);
  TPad *p5 = c827_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr827_cyclecounts = new TGraphErrors (counts_827 , cycleNumberArray827, UCNIntegralArray827, 0 , UCNIntegralErrArray827);
  gr827_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr827_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr827_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr827_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr827_cyclehist = new TGraphErrors(counts_827, cycleNumberArray827 , HistIntegralArray827, 0, HistIntegralErrArray827);

  gr827_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr827_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr827_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr827_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr827_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr827_cyclehist -> SetMarkerColor(2);
  gr827_cyclehist -> SetMarkerStyle(7);

  gr827_cyclecounts -> Draw("Ap");
  gr827_cyclehist -> Draw("p");

  leg2-> Draw();

  c827_cycleNum -> cd(2);
 TGraphErrors *gr827_cycledelay = new TGraphErrors (counts_827 , cycleNumberArray827, delaytimeArray827, 0 , 0);
  gr827_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr827_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr827_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr827_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cycledelay -> SetMarkerStyle(7);

  gr827_cycledelay -> Draw("Ap");


  c827_cycleNum -> cd(3);
  TGraphErrors *gr827_cycletempIrrad = new TGraphErrors (counts_827 , cycleNumberArray827, avets12IrradArray827, 0 , ts12IrradErr827);

  gr827_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr827_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr827_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr827_cycletempIrrad -> SetMarkerStyle(7);
  gr827_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr827_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr827_cycletempValveOpen = new TGraphErrors (counts_827 , cycleNumberArray827, avets12ValveOpenArray827, 0 , ts12ValveOpenErr827);

  gr827_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr827_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr827_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr827_cycletempValveOpen -> SetMarkerStyle(7);
  gr827_cycletempValveOpen -> SetMarkerColor(2);
  gr827_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr827_cycletempIrrad -> Draw("AP");
  gr827_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c827_cycleNum -> cd(4);
  TGraphErrors *gr827_cyclecur = new TGraphErrors (counts_827 , cycleNumberArray827 , avecurArray827, 0, ErrcurArray827 );
  gr827_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr827_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr827_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr827_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclecur -> SetMarkerStyle(7);
  gr827_cyclecur -> Draw("Ap");


  TCanvas *c827_cycleNumFit = new TCanvas("c827_cycleNumFit" , "c827_cycleNumFit" , 1200, 800);
  c827_cycleNumFit -> Divide(2,2);

  c827_cycleNumFit -> cd(1);
  TGraphErrors *gr827_cyclefall = new TGraphErrors (counts_827, cycleNumberArray827, FallTimeArray827 , 0, FallTimeErrArray827);

  gr827_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr827_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr827_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr827_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclefall -> SetMarkerStyle(7);
  gr827_cyclefall -> Draw("Ap");


  c827_cycleNumFit -> cd(2);
  TGraphErrors *gr827_cyclebaseline = new TGraphErrors (counts_827, cycleNumberArray827, BaselineArray827 , 0, BaselineErrArray827);

  gr827_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr827_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr827_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr827_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclebaseline -> SetMarkerStyle(7);
  gr827_cyclebaseline -> Draw("Ap");

  c827_cycleNumFit -> cd(3);
  TGraphErrors *gr827_cyclebaselineirrad = new TGraphErrors (counts_827, cycleNumberArray827, BaselineIrradArray827 , 0, BaselineIrradErrArray827);

  gr827_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr827_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr827_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr827_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclebaselineirrad -> SetMarkerStyle(7);
  gr827_cyclebaselineirrad -> Draw("Ap");

  c827_cycleNumFit -> cd(4);
  TGraphErrors *gr827_cyclerise = new TGraphErrors (counts_827, cycleNumberArray827, RiseTimeArray827 , 0, RiseTimeErrArray827);

  gr827_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr827_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr827_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr827_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr827_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr827_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr827_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr827_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr827_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr827_cyclerise -> SetMarkerStyle(7);
  gr827_cyclerise -> Draw("Ap");








  




}
