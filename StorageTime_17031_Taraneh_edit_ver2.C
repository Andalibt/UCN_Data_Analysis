//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17031.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17031_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin834 = new TFile("outputTree_StorageTime_834.root","READ");



  
  TTree *outputTree834 = (TTree*) fin834 -> Get("cycle_info");

  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime834;





  outputTree834 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime834);


  // DELAY TIME (ARRAY)
  double delaytimeArray834 [100];



  // CYCLE NUMBER
  int cycleNumber834;



  outputTree834 -> SetBranchAddress ("cycleNumber" , &cycleNumber834);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray834 [100];


  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral834;

  outputTree834 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral834);

  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray834 [100];

  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr834;

  double UCNIntegralErr613;


  outputTree834 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr834);




  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray834 [100];



  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral834;



  outputTree834 -> SetBranchAddress ("HistIntegral" , &HistIntegral834); 



  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray834 [100];



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr834;



  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray834 [100];



  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad834;


  outputTree834 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad834);


  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen834;

  outputTree834 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen834);

  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray834 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray834 [100];

  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad834;


  outputTree834 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad834);



 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen834;



  outputTree834 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen834);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray834 [100];


  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray834 [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad834;



  outputTree834 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad834);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen834;

  
  outputTree834 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen834);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray834 [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray834 [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr834 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr834 [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur834;


  outputTree834 -> SetBranchAddress ("AVE_PRDCUR" , &avecur834);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray834 [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur834;
 

  outputTree834 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur834);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray834 [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur834;


  outputTree834 -> SetBranchAddress ("MIN_PRDCUR" , &mincur834);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray834 [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray834 [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline834;


  outputTree834 -> SetBranchAddress ("Baseline" , &Baseline834);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray834 [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr834;

 
  outputTree834 -> SetBranchAddress ("BaselineErr" , &BaselineErr834);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray834 [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad834;

 
  outputTree834 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad834);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray834 [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr834;


  outputTree834 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr834);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray834 [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTime834;


  outputTree834 -> SetBranchAddress ("FallTime" , &FallTime834);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray834 [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr834;


  outputTree834 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr834);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray834 [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime834;


  outputTree834 -> SetBranchAddress ("RiseTime" , &RiseTime834);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray834 [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr834;


  outputTree834 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr834);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray834 [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad834;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad834;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad834;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad834;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage834;


  // STORAGE TIME ERR FROM THE FIT
  double storageErr834;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_834 = 0;

  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events834;
  events834 = (Double_t)outputTree834 -> GetEntries();

  for (ULong64_t j = 0 ; j < events834 ; j++){
    outputTree834 -> GetEvent(j);
    //if (j==8)
    //  continue;
    UCNIntegralArray834[counts_834] = UCNIntegral834;
    UCNIntegralErrArray834[counts_834] = UCNIntegralErr834/2;
    HistIntegralArray834[counts_834] = HistIntegral834;
    HistIntegralErrArray834[counts_834] = sqrt (HistIntegral834)/2;
    avets12IrradArray834[counts_834] = avets12Irrad834;
    avets12ValveOpenArray834[counts_834] = avets12ValveOpen834;
    maxts12IrradArray834[counts_834] = maxts12Irrad834;
    maxts12ValveOpenArray834[counts_834] = maxts12ValveOpen834;
    mints12IrradArray834[counts_834] = mints12Irrad834; 
    mints12ValveOpenArray834[counts_834] = mints12ValveOpen834;
    ts12IrradErr834[counts_834] = (maxts12Irrad834 - mints12Irrad834)/2;
    ts12ValveOpenErr834[counts_834] = (maxts12ValveOpen834 - mints12ValveOpen834)/2;
    avecurArray834[counts_834] = avecur834;
    maxcurArray834[counts_834] = maxcur834;
    mincurArray834[counts_834] = mincur834;
    ErrcurArray834[counts_834] = (maxcur834 - mincur834)/2;
    delaytimeArray834[counts_834] = cycleDelayTime834;
    cycleNumberArray834[counts_834] = cycleNumber834;
    BaselineArray834[counts_834] = Baseline834;
    BaselineIrradArray834[counts_834] = BaselineIrrad834;
    BaselineIrradErrArray834[counts_834] = BaselineIrradErr834/2;
    FallTimeArray834[counts_834] = FallTime834;
    FallTimeErrArray834[counts_834] = FallTimeErr834/2;
    RiseTimeArray834[counts_834] = RiseTime834;
    RiseTimeErrArray834[counts_834] = RiseTimeErr834/2;
    aveAllts12Irrad834 += avets12Irrad834;
    maxAllts12Irrad834 += maxts12Irrad834;
    minAllts12Irrad834 += mints12Irrad834;
    UCNIntegralArrayAll[counts_834] = UCNIntegral834;
    UCNIntegralErrArrayAll[counts_834] = UCNIntegralErr834/2;
    delayTimeAll[counts_834] = cycleDelayTime834;
    HistIntegralArrayAll[counts_834] = HistIntegral834;
    HistIntegralErrArrayAll[counts_834] = sqrt (HistIntegral834)/2;
    counts_834++;
  }
  aveAllts12Irrad834 = aveAllts12Irrad834/counts_834;
  maxAllts12Irrad834 = maxAllts12Irrad834/counts_834;
  minAllts12Irrad834 = minAllts12Irrad834/counts_834;
  aveAllErrts12Irrad834 = (maxAllts12Irrad834 - minAllts12Irrad834)/2;




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
  //              834
  //*********************************
  //*********************************
  TCanvas *c834 = new TCanvas("c834" , "c834" , 1200, 800);
  c834 -> Divide(2,2);
  //c834 -> cd(1);
  TPad *p1 = c834->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr834_delaycounts = new TGraphErrors(counts_834, delaytimeArray834 , UCNIntegralArray834, 0, UCNIntegralErrArray834);

  gr834_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr834_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr834_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr834_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr834_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_delaycounts -> SetMarkerStyle(7);
  gr834_delaycounts -> Fit(fit);
  storage834 = fit -> GetParameter(1);
  storageErr834 = fit -> GetParError(1);
  
  TGraphErrors *gr834_delayhist = new TGraphErrors(counts_834, delaytimeArray834 , HistIntegralArray834, 0, HistIntegralErrArray834);

  gr834_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr834_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr834_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr834_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr834_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr834_delayhist -> SetMarkerColor(2);
  gr834_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr834_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr834_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr834_delaycounts -> Draw("Ap");
  gr834_delayhist -> Draw("p");
  leg2 -> Draw();

  //c834 -> cd(2);
  TPad *p2 = c834->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr834_tempIrradcounts = new TGraphErrors (counts_834 , avets12IrradArray834, UCNIntegralArray834 , ts12IrradErr834 , UCNIntegralErrArray834);
  gr834_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr834_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr834_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr834_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr834_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr834_tempValveOpencounts = new TGraphErrors (counts_834 , avets12ValveOpenArray834, UCNIntegralArray834 , ts12ValveOpenErr834 , UCNIntegralErrArray834);
  gr834_tempValveOpencounts -> SetMarkerStyle(7);
  gr834_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr834_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr834_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr834_tempIrradcounts -> Draw("Ap");
  gr834_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c834 -> cd(3);
  TGraphErrors *gr834_delaytempIrrad = new TGraphErrors (counts_834 , delaytimeArray834, avets12IrradArray834, 0 , ts12IrradErr834);

  gr834_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr834_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr834_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr834_delaytempIrrad -> SetMarkerStyle(7);
  gr834_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr834_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr834_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr834_delaytempValveOpen = new TGraphErrors (counts_834 , delaytimeArray834, avets12ValveOpenArray834, 0 , ts12ValveOpenErr834);

  gr834_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr834_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr834_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr834_delaytempValveOpen -> SetMarkerStyle(7);
  gr834_delaytempValveOpen -> SetMarkerColor(2);
  gr834_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr834_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr834_delaytempIrrad -> Draw("AP");
  gr834_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c834->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr834_curcounts = new TGraphErrors (counts_834 , avecurArray834, UCNIntegralArray834 , ErrcurArray834 , UCNIntegralErrArray834);
  gr834_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr834_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr834_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr834_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr834_curhist = new TGraphErrors (counts_834 , avecurArray834, UCNIntegralArray834 , ErrcurArray834 , UCNIntegralErrArray834);
  gr834_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr834_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr834_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr834_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr834_curhist -> SetMarkerColor(2);
  gr834_curhist -> SetMarkerStyle(7);

  gr834_curcounts -> Draw("Ap");
  gr834_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c834_cycleNum = new TCanvas("c834_cycleNum" , "c834_cycleNum" , 1200, 800);
  c834_cycleNum -> Divide(2,2);
  TPad *p5 = c834_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr834_cyclecounts = new TGraphErrors (counts_834 , cycleNumberArray834, UCNIntegralArray834, 0 , UCNIntegralErrArray834);
  gr834_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr834_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr834_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr834_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr834_cyclehist = new TGraphErrors(counts_834, cycleNumberArray834 , HistIntegralArray834, 0, HistIntegralErrArray834);

  gr834_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr834_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr834_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr834_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr834_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr834_cyclehist -> SetMarkerColor(2);
  gr834_cyclehist -> SetMarkerStyle(7);

  gr834_cyclecounts -> Draw("Ap");
  gr834_cyclehist -> Draw("p");

  leg2-> Draw();

  c834_cycleNum -> cd(2);
 TGraphErrors *gr834_cycledelay = new TGraphErrors (counts_834 , cycleNumberArray834, delaytimeArray834, 0 , 0);
  gr834_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr834_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr834_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr834_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cycledelay -> SetMarkerStyle(7);

  gr834_cycledelay -> Draw("Ap");


  c834_cycleNum -> cd(3);
  TGraphErrors *gr834_cycletempIrrad = new TGraphErrors (counts_834 , cycleNumberArray834, avets12IrradArray834, 0 , ts12IrradErr834);

  gr834_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr834_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr834_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr834_cycletempIrrad -> SetMarkerStyle(7);
  gr834_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr834_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr834_cycletempValveOpen = new TGraphErrors (counts_834 , cycleNumberArray834, avets12ValveOpenArray834, 0 , ts12ValveOpenErr834);

  gr834_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr834_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr834_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr834_cycletempValveOpen -> SetMarkerStyle(7);
  gr834_cycletempValveOpen -> SetMarkerColor(2);
  gr834_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr834_cycletempIrrad -> Draw("AP");
  gr834_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c834_cycleNum -> cd(4);
  TGraphErrors *gr834_cyclecur = new TGraphErrors (counts_834 , cycleNumberArray834 , avecurArray834, 0, ErrcurArray834 );
  gr834_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr834_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr834_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr834_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclecur -> SetMarkerStyle(7);
  gr834_cyclecur -> Draw("Ap");


  TCanvas *c834_cycleNumFit = new TCanvas("c834_cycleNumFit" , "c834_cycleNumFit" , 1200, 800);
  c834_cycleNumFit -> Divide(2,2);

  c834_cycleNumFit -> cd(1);
  TGraphErrors *gr834_cyclefall = new TGraphErrors (counts_834, cycleNumberArray834, FallTimeArray834 , 0, FallTimeErrArray834);

  gr834_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr834_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr834_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr834_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclefall -> SetMarkerStyle(7);
  gr834_cyclefall -> Draw("Ap");


  c834_cycleNumFit -> cd(2);
  TGraphErrors *gr834_cyclebaseline = new TGraphErrors (counts_834, cycleNumberArray834, BaselineArray834 , 0, BaselineErrArray834);

  gr834_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr834_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr834_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr834_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclebaseline -> SetMarkerStyle(7);
  gr834_cyclebaseline -> Draw("Ap");

  c834_cycleNumFit -> cd(3);
  TGraphErrors *gr834_cyclebaselineirrad = new TGraphErrors (counts_834, cycleNumberArray834, BaselineIrradArray834 , 0, BaselineIrradErrArray834);

  gr834_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr834_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr834_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr834_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclebaselineirrad -> SetMarkerStyle(7);
  gr834_cyclebaselineirrad -> Draw("Ap");

  c834_cycleNumFit -> cd(4);
  TGraphErrors *gr834_cyclerise = new TGraphErrors (counts_834, cycleNumberArray834, RiseTimeArray834 , 0, RiseTimeErrArray834);

  gr834_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr834_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr834_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr834_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr834_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr834_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr834_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr834_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr834_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr834_cyclerise -> SetMarkerStyle(7);
  gr834_cyclerise -> Draw("Ap");








  




}
