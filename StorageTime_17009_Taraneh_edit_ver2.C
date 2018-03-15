//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17009.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17009_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");

  int midasrun =0;
  char *filename[200];
  double UCNIntegralAll[200];
  double HistIntegralAll[200];
  double UCNIntegralErrAll[200];
  double HistIntegralErrAll[200];
  double delaytimeAll[200];
  int counts_old = 0;





  for (midasrun = 662 ; midasrun <669; midasrun++){


    
    sprintf (filename , "./outputTree_StorageTime_%d.root",midasrun);
    TFile* fin = new TFile(Form(filename),"READ");
    //TFile *finmidasrun = new TFile("outputTree_StorageTime_midasrun.root","READ");
    
    TTree *outputTreemidasrun = (TTree*) fin -> Get("cycle_info");
    
    // VARIABLES FOR THE TREE
    // DELAY TIME
    double cycleDelayTimemidasrun;
    
    outputTreemidasrun -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTimemidasrun);
    
    
    // DELAY TIME (ARRAY)
    double delaytimeArraymidasrun [100];
    
    // CYCLE NUMBER
    int cycleNumbermidasrun;
    outputTreemidasrun -> SetBranchAddress ("cycleNumber" , &cycleNumbermidasrun);
    
    
    //CYCLE NUMBER (ARRAY)
    double cycleNumberArraymidasrun [100];
    
    // UCN INTEGRAL FROM THE FIT FUNCTION
    double UCNIntegralmidasrun;
    
    outputTreemidasrun -> SetBranchAddress ("UCNIntegral" , &UCNIntegralmidasrun);
    
    // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
    double UCNIntegralArraymidasrun [100];
    
    // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
    double UCNIntegralErrmidasrun;
    
    double UCNIntegralErr613;
    
    
    outputTreemidasrun -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErrmidasrun);
    
    // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
    double UCNIntegralErrArraymidasrun [100];
    
    
    
    // THE UCN RATE HISTOGRAM INTEGRAL 
    double HistIntegralmidasrun;
    
    
    
    outputTreemidasrun -> SetBranchAddress ("HistIntegral" , &HistIntegralmidasrun); 
    
    
    
    // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
    double HistIntegralArraymidasrun [100];
    
    
    
    // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
    double HistIntegralErrmidasrun;
    
    
    
    // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
    double HistIntegralErrArraymidasrun [100];
    
    
    
    // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
    double avets12Irradmidasrun;
    
    
    outputTreemidasrun -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irradmidasrun);
    
    
    // AVERAGE TS12 DURING VALVE OPEN
    double avets12ValveOpenmidasrun;
    
    outputTreemidasrun -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpenmidasrun);
    
    // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
    double avets12IrradArraymidasrun [100];
    
    
    // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
    double avets12ValveOpenArraymidasrun [100];
    
    // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
    double maxts12Irradmidasrun;
    
    
    outputTreemidasrun -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irradmidasrun);
    
    
    
    // MAXIMUM TS12 DURING VALVE OPEN
    double maxts12ValveOpenmidasrun;
    
    
    
    outputTreemidasrun -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpenmidasrun);


    // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
    double maxts12IrradArraymidasrun [100];
    
    
  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArraymidasrun [100];


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irradmidasrun;



  outputTreemidasrun -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irradmidasrun);


  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpenmidasrun;

  
  outputTreemidasrun -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpenmidasrun);


  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArraymidasrun [100];


  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArraymidasrun [100];



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErrmidasrun [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErrmidasrun [100];



  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecurmidasrun;


  outputTreemidasrun -> SetBranchAddress ("AVE_PRDCUR" , &avecurmidasrun);


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArraymidasrun [100];


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcurmidasrun;
 

  outputTreemidasrun -> SetBranchAddress ("MAX_PRDCUR" , &maxcurmidasrun);


  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArraymidasrun [100];


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincurmidasrun;


  outputTreemidasrun -> SetBranchAddress ("MIN_PRDCUR" , &mincurmidasrun);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArraymidasrun [100];


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArraymidasrun [100];


  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baselinemidasrun;


  outputTreemidasrun -> SetBranchAddress ("Baseline" , &Baselinemidasrun);

  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArraymidasrun [100];


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErrmidasrun;

 
  outputTreemidasrun -> SetBranchAddress ("BaselineErr" , &BaselineErrmidasrun);


  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArraymidasrun [100];



  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrradmidasrun;

 
  outputTreemidasrun -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrradmidasrun);


  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArraymidasrun [100];

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErrmidasrun;


  outputTreemidasrun -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErrmidasrun);


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArraymidasrun [100];


  // FALL TIME FROM THE UCN RATE FIT
  double FallTimemidasrun;


  outputTreemidasrun -> SetBranchAddress ("FallTime" , &FallTimemidasrun);


  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArraymidasrun [100];


  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErrmidasrun;


  outputTreemidasrun -> SetBranchAddress ("FallTimeErr" , &FallTimeErrmidasrun);



  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArraymidasrun [100];

  

  // RISE TIME FROM THE UCN RATE FIT
  double RiseTimemidasrun;


  outputTreemidasrun -> SetBranchAddress ("RiseTime" , &RiseTimemidasrun);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArraymidasrun [100];


  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErrmidasrun;


  outputTreemidasrun -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErrmidasrun);



  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArraymidasrun [100];



  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irradmidasrun;


  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irradmidasrun;


  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irradmidasrun;

  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irradmidasrun;


  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storagemidasrun;


  // STORAGE TIME ERR FROM THE FIT
  double storageErrmidasrun;



  // NUMBER OF COUNTS IN EACH LOOP
  int counts_midasrun = 0;

  double irradiationStartTimes;
  double cycleStartTimes;
  double irradiationTime;

  outputTreemidasrun -> SetBranchAddress ("irradStartTimes" , &irradiationStartTimes);
  outputTreemidasrun -> SetBranchAddress ("cycleStartTimes" , &cycleStartTimes);
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];


  cout << "******************************" << endl;
  
  ULong64_t eventsmidasrun;
  eventsmidasrun = (Double_t)outputTreemidasrun -> GetEntries();

  for (ULong64_t j = 0 ; j < eventsmidasrun ; j++){
    outputTreemidasrun -> GetEvent(j);
    if (midasrun == 674 && j==1)
      continue;
    if (midasrun == 691 && j==1)
      continue;
    if (midasrun == 694 && j==1)
      continue;
    irradiationTime = cycleStartTimes - irradiationStartTimes;
    cout << "For midas run "  << midasrun  << " the irradiation time is " << irradiationTime << endl;
    UCNIntegralArraymidasrun[counts_midasrun] = UCNIntegralmidasrun;
    UCNIntegralErrArraymidasrun[counts_midasrun] = UCNIntegralErrmidasrun;
    HistIntegralArraymidasrun[counts_midasrun] = HistIntegralmidasrun;
    HistIntegralErrArraymidasrun[counts_midasrun] = sqrt (HistIntegralmidasrun);
    avets12IrradArraymidasrun[counts_midasrun] = avets12Irradmidasrun;
    avets12ValveOpenArraymidasrun[counts_midasrun] = avets12ValveOpenmidasrun;
    maxts12IrradArraymidasrun[counts_midasrun] = maxts12Irradmidasrun;
    maxts12ValveOpenArraymidasrun[counts_midasrun] = maxts12ValveOpenmidasrun;
    mints12IrradArraymidasrun[counts_midasrun] = mints12Irradmidasrun; 
    mints12ValveOpenArraymidasrun[counts_midasrun] = mints12ValveOpenmidasrun;
    ts12IrradErrmidasrun[counts_midasrun] = (maxts12Irradmidasrun - mints12Irradmidasrun)/2;
    ts12ValveOpenErrmidasrun[counts_midasrun] = (maxts12ValveOpenmidasrun - mints12ValveOpenmidasrun)/2;
    avecurArraymidasrun[counts_midasrun] = avecurmidasrun;
    maxcurArraymidasrun[counts_midasrun] = maxcurmidasrun;
    mincurArraymidasrun[counts_midasrun] = mincurmidasrun;
    ErrcurArraymidasrun[counts_midasrun] = (maxcurmidasrun - mincurmidasrun)/2;
    delaytimeArraymidasrun[counts_midasrun] = cycleDelayTimemidasrun;
    cycleNumberArraymidasrun[counts_midasrun] = cycleNumbermidasrun;
    BaselineArraymidasrun[counts_midasrun] = Baselinemidasrun;
    BaselineIrradArraymidasrun[counts_midasrun] = BaselineIrradmidasrun;
    BaselineIrradErrArraymidasrun[counts_midasrun] = BaselineIrradErrmidasrun;
    FallTimeArraymidasrun[counts_midasrun] = FallTimemidasrun;
    FallTimeErrArraymidasrun[counts_midasrun] = FallTimeErrmidasrun;
    RiseTimeArraymidasrun[counts_midasrun] = RiseTimemidasrun;
    RiseTimeErrArraymidasrun[counts_midasrun] = RiseTimeErrmidasrun;
    aveAllts12Irradmidasrun += avets12Irradmidasrun;
    maxAllts12Irradmidasrun += maxts12Irradmidasrun;
    minAllts12Irradmidasrun += mints12Irradmidasrun;
    UCNIntegralArrayAll[counts_midasrun] = UCNIntegralmidasrun;
    UCNIntegralErrArrayAll[counts_midasrun] = UCNIntegralErrmidasrun;
    //delayTimeAll[counts_midasrun] = cycleDelayTimemidasrun;
    //HistIntegralArrayAll[counts_midasrun] = HistIntegralmidasrun;
    //HistIntegralErrArrayAll[counts_midasrun] = sqrt (HistIntegralmidasrun)/2;
    delaytimeAll[counts_old + counts_midasrun] = cycleDelayTimemidasrun;
    UCNIntegralAll[counts_old + counts_midasrun] = UCNIntegralmidasrun;
    UCNIntegralErrAll[counts_old + counts_midasrun] = UCNIntegralErrmidasrun;
    HistIntegralAll[counts_old + counts_midasrun] = HistIntegralmidasrun;
HistIntegralErrAll[counts_old + counts_midasrun] = sqrt (HistIntegralmidasrun);
    cout <<counts_old+ counts_midasrun << " "<<delayTimeAll[counts_old+counts_midasrun] << endl;
    counts_midasrun++;
  }
  aveAllts12Irradmidasrun = aveAllts12Irradmidasrun/counts_midasrun;
  maxAllts12Irradmidasrun = maxAllts12Irradmidasrun/counts_midasrun;
  minAllts12Irradmidasrun = minAllts12Irradmidasrun/counts_midasrun;
  aveAllErrts12Irradmidasrun = (maxAllts12Irradmidasrun - minAllts12Irradmidasrun)/2;
  counts_old = counts_old + counts_midasrun;
  cout << "***************************************" << endl;


  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(100000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 5, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************

  /*
  //*********************************
  //*********************************
  //              midasrun
  //*********************************
  //********************************* 
  TCanvas *cmidasrun = new TCanvas("cmidasrun" , "cmidasrun" , 1200, 800);
  cmidasrun -> Divide(2,2);
  //cmidasrun -> cd(1);
  TPad *p1 = cmidasrun->cd(1);
  p1->SetLogy(); 

  TGraphErrors *grmidasrun_delaycounts = new TGraphErrors(counts_midasrun, delaytimeArraymidasrun , UCNIntegralArraymidasrun, 0, UCNIntegralErrArraymidasrun);

  grmidasrun_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  grmidasrun_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  grmidasrun_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_delaycounts -> GetYaxis()-> SetRangeUser(100, 500000);
  grmidasrun_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_delaycounts -> SetMarkerStyle(20);
  grmidasrun_delaycounts -> Fit(fit);
  storagemidasrun = fit -> GetParameter(1);
  storageErrmidasrun = fit -> GetParError(1);
  
  TGraphErrors *grmidasrun_delayhist = new TGraphErrors(counts_midasrun, delaytimeArraymidasrun , HistIntegralArraymidasrun, 0, HistIntegralErrArraymidasrun);

  grmidasrun_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  grmidasrun_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  grmidasrun_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  grmidasrun_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  grmidasrun_delayhist -> SetMarkerColor(2);
  grmidasrun_delayhist -> SetMarkerStyle(20);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(grmidasrun_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(grmidasrun_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  grmidasrun_delaycounts -> Draw("Ap");
  grmidasrun_delayhist -> Draw("p");
  leg2 -> Draw();

  //cmidasrun -> cd(2);

  TGraphErrors *grmidasrun_tempIrradcounts = new TGraphErrors (counts_midasrun , avets12IrradArraymidasrun, UCNIntegralArraymidasrun , ts12IrradErrmidasrun , UCNIntegralErrArraymidasrun);
  grmidasrun_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  grmidasrun_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grmidasrun_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  grmidasrun_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_tempIrradcounts -> SetMarkerStyle(20);

  TGraphErrors *grmidasrun_tempValveOpencounts = new TGraphErrors (counts_midasrun , avets12ValveOpenArraymidasrun, UCNIntegralArraymidasrun , ts12ValveOpenErrmidasrun , UCNIntegralErrArraymidasrun);
  grmidasrun_tempValveOpencounts -> SetMarkerStyle(20);
  grmidasrun_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(grmidasrun_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(grmidasrun_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  grmidasrun_tempIrradcounts -> Draw("Ap");
  grmidasrun_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  cmidasrun -> cd(3);
  TGraphErrors *grmidasrun_delaytempIrrad = new TGraphErrors (counts_midasrun , delaytimeArraymidasrun, avets12IrradArraymidasrun, 0 , ts12IrradErrmidasrun);

  grmidasrun_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  grmidasrun_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grmidasrun_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grmidasrun_delaytempIrrad -> SetMarkerStyle(20);
  grmidasrun_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  grmidasrun_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *grmidasrun_delaytempValveOpen = new TGraphErrors (counts_midasrun , delaytimeArraymidasrun, avets12ValveOpenArraymidasrun, 0 , ts12ValveOpenErrmidasrun);

  grmidasrun_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  grmidasrun_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grmidasrun_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grmidasrun_delaytempValveOpen -> SetMarkerStyle(20);
  grmidasrun_delaytempValveOpen -> SetMarkerColor(2);
  grmidasrun_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  grmidasrun_delaytempIrrad -> Draw("AP");
  grmidasrun_delaytempValveOpen -> Draw("p");
  leg -> Draw();

  TPad *p2 = cmidasrun->cd(2);
  p2->SetLogy(); 
  TGraphErrors *grmidasrun_curcounts = new TGraphErrors (counts_midasrun , avecurArraymidasrun, UCNIntegralArraymidasrun , ErrcurArraymidasrun , UCNIntegralErrArraymidasrun);
  grmidasrun_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  grmidasrun_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  grmidasrun_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_curcounts -> SetMarkerStyle(20);

  TGraphErrors *grmidasrun_curhist = new TGraphErrors (counts_midasrun , avecurArraymidasrun, UCNIntegralArraymidasrun , ErrcurArraymidasrun , UCNIntegralErrArraymidasrun);
  grmidasrun_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  grmidasrun_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  grmidasrun_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_curhist -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  grmidasrun_curhist -> SetMarkerColor(2);
  grmidasrun_curhist -> SetMarkerStyle(20);

  grmidasrun_curcounts -> Draw("Ap");
  grmidasrun_curhist -> Draw("p");
  leg2 -> Draw();
  cmidasrun -> Update();

  TCanvas *cmidasrun_cycleNum = new TCanvas("cmidasrun_cycleNum" , "cmidasrun_cycleNum" , 1200, 800);
  cmidasrun_cycleNum -> Divide(2,2);
  TPad *p5 = cmidasrun_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *grmidasrun_cyclecounts = new TGraphErrors (counts_midasrun , cycleNumberArraymidasrun, UCNIntegralArraymidasrun, 0 , UCNIntegralErrArraymidasrun);
  grmidasrun_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  grmidasrun_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  grmidasrun_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  grmidasrun_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *grmidasrun_cyclehist = new TGraphErrors(counts_midasrun, cycleNumberArraymidasrun , HistIntegralArraymidasrun, 0, HistIntegralErrArraymidasrun);

  grmidasrun_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  grmidasrun_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  grmidasrun_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grmidasrun_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  grmidasrun_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  grmidasrun_cyclehist -> SetMarkerColor(2);
  grmidasrun_cyclehist -> SetMarkerStyle(20);

  grmidasrun_cyclecounts -> Draw("Ap");
  grmidasrun_cyclehist -> Draw("p");

  leg2-> Draw();

  cmidasrun_cycleNum -> cd(2);
 TGraphErrors *grmidasrun_cycledelay = new TGraphErrors (counts_midasrun , cycleNumberArraymidasrun, delaytimeArraymidasrun, 0 , 0);
  grmidasrun_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  grmidasrun_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  grmidasrun_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  grmidasrun_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cycledelay -> SetMarkerStyle(20);

  grmidasrun_cycledelay -> Draw("Ap");


  cmidasrun_cycleNum -> cd(3);
  TGraphErrors *grmidasrun_cycletempIrrad = new TGraphErrors (counts_midasrun , cycleNumberArraymidasrun, avets12IrradArraymidasrun, 0 , ts12IrradErrmidasrun);

  grmidasrun_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  grmidasrun_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grmidasrun_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  grmidasrun_cycletempIrrad -> SetMarkerStyle(20);
  grmidasrun_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  grmidasrun_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *grmidasrun_cycletempValveOpen = new TGraphErrors (counts_midasrun , cycleNumberArraymidasrun, avets12ValveOpenArraymidasrun, 0 , ts12ValveOpenErrmidasrun);

  grmidasrun_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  grmidasrun_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grmidasrun_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  grmidasrun_cycletempValveOpen -> SetMarkerStyle(20);
  grmidasrun_cycletempValveOpen -> SetMarkerColor(2);
  grmidasrun_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  grmidasrun_cycletempIrrad -> Draw("AP");
  grmidasrun_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  cmidasrun_cycleNum -> cd(4);
  TGraphErrors *grmidasrun_cyclecur = new TGraphErrors (counts_midasrun , cycleNumberArraymidasrun , avecurArraymidasrun, 0, ErrcurArraymidasrun );
  grmidasrun_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  grmidasrun_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  grmidasrun_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //grmidasrun_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclecur -> SetMarkerStyle(20);
  grmidasrun_cyclecur -> Draw("Ap");
  cmidasrun_cycleNum -> Update();

  TCanvas *cmidasrun_cycleNumFit = new TCanvas("cmidasrun_cycleNumFit" , "cmidasrun_cycleNumFit" , 1200, 800);
  cmidasrun_cycleNumFit -> Divide(2,2);

  cmidasrun_cycleNumFit -> cd(1);
  TGraphErrors *grmidasrun_cyclefall = new TGraphErrors (counts_midasrun, cycleNumberArraymidasrun, FallTimeArraymidasrun , 0, FallTimeErrArraymidasrun);

  grmidasrun_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  grmidasrun_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  grmidasrun_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //grmidasrun_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclefall -> SetMarkerStyle(20);
  grmidasrun_cyclefall -> Draw("Ap");


  cmidasrun_cycleNumFit -> cd(2);
  TGraphErrors *grmidasrun_cyclebaseline = new TGraphErrors (counts_midasrun, cycleNumberArraymidasrun, BaselineArraymidasrun , 0, BaselineErrArraymidasrun);

  grmidasrun_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  grmidasrun_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  grmidasrun_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //grmidasrun_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclebaseline -> SetMarkerStyle(20);
  grmidasrun_cyclebaseline -> Draw("Ap");

  cmidasrun_cycleNumFit -> cd(3);
  TGraphErrors *grmidasrun_cyclebaselineirrad = new TGraphErrors (counts_midasrun, cycleNumberArraymidasrun, BaselineIrradArraymidasrun , 0, BaselineIrradErrArraymidasrun);

  grmidasrun_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  grmidasrun_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  grmidasrun_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //grmidasrun_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclebaselineirrad -> SetMarkerStyle(20);
  grmidasrun_cyclebaselineirrad -> Draw("Ap");

  cmidasrun_cycleNumFit -> cd(4);
  TGraphErrors *grmidasrun_cyclerise = new TGraphErrors (counts_midasrun, cycleNumberArraymidasrun, RiseTimeArraymidasrun , 0, RiseTimeErrArraymidasrun);

  grmidasrun_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  grmidasrun_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  grmidasrun_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //grmidasrun_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grmidasrun_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grmidasrun_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  grmidasrun_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  grmidasrun_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  grmidasrun_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  grmidasrun_cyclerise -> SetMarkerStyle(20);
  grmidasrun_cyclerise -> Draw("Ap");

  cmidasrun_cycleNumFit-> Update(); 
  
  */

  }
  for (int k = 0; k < counts_old ; k++){
    cout << UCNIntegralAll[k] << endl;
    }


  TCanvas *c = new TCanvas("c" , "c" , 1200, 800);
  c->SetLogy(); 

  TGraphErrors *gr = new TGraphErrors(counts_old, delaytimeAll , UCNIntegralAll, 0, UCNIntegralErrAll);

  gr -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr -> GetYaxis()-> SetRangeUser(100, 500000);
  gr -> GetXaxis() -> SetTitleSize(0.05);
  gr -> GetXaxis() -> SetTitleOffset(1.0);
  gr -> GetYaxis() -> SetTitleSize(0.05); 
  gr -> GetYaxis() -> SetTitleOffset(0.9);

  gr -> SetMarkerStyle(20);
  gr -> Fit(fit);
  storagemidasrun = fit -> GetParameter(1);
  storageErrmidasrun = fit -> GetParError(1);
  
  TGraphErrors *grhist = new TGraphErrors(counts_old, delaytimeAll , HistIntegralAll, 0, HistIntegralErrAll);

  grhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  grhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  grhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  grhist -> GetXaxis() -> SetTitleSize(0.05);
  grhist -> GetXaxis() -> SetTitleOffset(1.0);
  grhist -> GetYaxis() -> SetTitleSize(0.05); 
  grhist -> GetYaxis() -> SetTitleOffset(0.9);
  grhist -> SetMarkerColor(2);
  grhist -> SetMarkerStyle(20);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr , "Without Background" , "p") ;
  leg2 -> AddEntry(grhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr -> Draw("Ap");
  grhist -> Draw("p");
  leg2 -> Draw(); 

 
  



}
