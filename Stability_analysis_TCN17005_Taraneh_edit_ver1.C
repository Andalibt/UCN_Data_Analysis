// ****************************************
// THIS SCRIPT IS FOR TCN17005 ANALYSIS.
// THE EXPERIMENT WAS CONDUCTED ON NOV 15
// 2017 TO STUDY THE LONG TERM STABILITY
// OF THE VERTICAL UCN SOURCE.
// Taraneh Andalib April 19, 2018
// ***************************************

#include <string>
#include <fstream>

void Stability_analysis_TCN17005_Taraneh_edit_ver1(){

  //LOADING THE DATA IN ...
  TFile *fin582 = new TFile ("./outputTree_582.root", "READ");
  TFile *fin583 = new TFile ("./outputTree_583.root", "READ");

  // GETTING THE CYCLE INFORMATION TREE ..
  TTree *cycle_info582 = (TTree*) fin582 -> Get("cycle_info");
  TTree *cycle_info583 = (TTree*) fin583 -> Get("cycle_info");

  // IRRADIATION TIME
  double irradStartTime582;
  double irradStartTime583;

  double irradStartTimeArray582[100];
  double irradStartTimeArray583[100];

    
  cycle_info582 -> SetBranchAddress("irradStartTimes", &irradStartTime582);
  cycle_info583 -> SetBranchAddress("irradStartTimes", &irradStartTime583);

  // CYCLE START TIME
  double cycleStartTime582;
  double cycleStartTime583;

  double cycleStartTimeArray582[100];
  double cycleStartTimeArray583[100];

  cycle_info582 -> SetBranchAddress("cycleStartTimes" , &cycleStartTime582);
  cycle_info583 -> SetBranchAddress("cycleStartTimes" , &cycleStartTime583);

  // INTEGRAL OF THE UCN RATE
  double HistIntegral582;
  double HistIntegral583;

  double HistIntegralArray582[100];
  double HistIntegralArray583[100];

  double HistIntegralErrArray582[100];
  double HistIntegralErrArray583[100];

  cycle_info582 -> SetBranchAddress("HistIntegral", &HistIntegral582);
  cycle_info583 -> SetBranchAddress("HistIntegral" , &HistIntegral583);

  // ISOPURE TEMPERATURE AVERAGE DURING IRRADIAITON
  double avets12Irrad582;
  double avets12Irrad583;

  double avetempIrradArray582[100];
  double avetempIrradArray583[100];
  
  cycle_info582 -> SetBranchAddress("AVE_TS12_IRRAD" , &avets12Irrad582);
  cycle_info583 -> SetBranchAddress("AVE_TS12_IRRAD" , &avets12Irrad583);

  // MAX ISOPURE TEMPERATURE DURING IRRADIATION
  double maxts12Irrad582;
  double maxts12Irrad583;

  double maxtempIrradArray582[100];
  double maxtempIrradArray583[100];
 
  cycle_info582 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad582);
  cycle_info583 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad583);


  // MINIMUM ISOPURE TEMPERATURE DURING IRRADIATION
  double mints12Irrad582;
  double mints12Irrad583;

  double mintempIrradArray582[100];
  double mintempIrradArray583[100];
  
  cycle_info582 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad582);
  cycle_info583 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad583);

  // AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen582;
  double avets12ValveOpen583;

  double avetempVOArray582[100];
  double avetempVOArray583[100];
			     
  cycle_info582 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen583);

  // MAXIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double maxts12ValveOpen582;
  double maxts12ValveOpen583;

  double maxtempVOArray582[100];
  double maxtempVOArray583[100];

  cycle_info582 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen583);

  // MINIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double mints12ValveOpen582;
  double mints12ValveOpen583;

  double mintempVOArray582[100];
  double mintempVOArray583[100];

  cycle_info582 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen583);

  // CYCLE NUMBER
  int cyclenum582;
  int cyclenum583;

  double cycleNumArray582[100];
  double cycleNumArray583[100];

  cycle_info582 -> SetBranchAddress ("cycleNumber" , &cyclenum582);
  cycle_info583 -> SetBranchAddress ("cycleNumber" , &cyclenum583);

  // CYCLE DELAY TIME
  double cycleDelayTime582;
  double cycleDelayTime583;

  double cycleDelayTimeArray582[100];
  double cycleDelayTimeArray583[100];

  cycle_info582 -> SetBranchAddress ("cycleDelayTime" , cycleDelayTime582);
  cycle_info583 -> SetBranchAddress ("cycleDelayTime" , cycleDelayTime583);

  // BASELINE INTEGRAL BEFORE IRRADIATION

  double baselineIntegral582;
  double baselineIntegral583;

  double baselineIntegralArray582[100];
  double baselineIntegralArray583[100];

  cycle_info582 -> SetBranchAddress ("BaselineIntegral" , &baselineIntegral582);
  cycle_info583 -> SetBranchAddress ("BaselineIntegral" , &baselineIntegral583);


  // AVERAGE PREDICTED CURRENT

  double avecur582;
  double avecur583;

  double avecurArray582[100];
  double avecurArray583[100];

  cycle_info582 -> SetBranchAddress ("AVE_PRDCUR", &avecur582);
  cycle_info583 -> SetBranchAddress ("AVE_PRDCUR" , &avecur583);


  // MAXIMUM PREDICTED CURRENT
  double maxcur582;
  double maxcur583;

  double maxcurArray582[100];
  double maxcurArray583[100];

  cycle_info582 -> SetBranchAddress ("MAX_PRDCUR", &maxcur582);
  cycle_info583 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur583);

  // MINIMUM PREDICTED CURRENT
  double mincur582;
  double mincur583;

  double mincurArray582[100];
  double mincurArray583[100];

  cycle_info582 -> SetBranchAddress ("MIN_PRDCUR" , &mincur582);
  cycle_info583 -> SetBranchAddress ("MIN_PRDCUR" , &mincur583);

  





  
  // READING FROM THE TREE , FILLING THE ARRAYS
  // *************
  // 582
  //**************

  int counter582 = 0;
  double UCNCounts582 [100];
  double UCNCountsErr582[100];
  double tempIrradErrArray582[100];
  double tempVOErrArray582[100];
  double curErrArray582[100];
  ULong64_t events582;
  events582 = (Double_t) cycle_info582 -> GetEntries();

  for (ULong64_t j = 0 ; j < events582 ; j++ ){
    cycle_info582 -> GetEvent(j);

    irradStartTimeArray582[j] = irradStartTime582;
    cycleStartTimeArray582[j] = cycleStartTime582;
    HistIntegralArray582[j] = HistIntegral582;
    HistIntegralErrArray582[j] = sqrt(HistIntegral582);
    avetempIrradArray582[j] = avets12Irrad582;
    maxtempIrradArray582[j] = maxts12Irrad582;
    mintempIrradArray582[j] = mints12Irrad582;
    tempIrradErrArray582[j] = (maxts12Irrad582 - mints12Irrad582)/2;
    avetempVOArray582[j] = avets12ValveOpen582;
    maxtempVOArray582[j] = maxts12ValveOpen582;
    mintempVOArray582[j] = mints12ValveOpen582;
    tempVOErrArray582[j] = (maxts12ValveOpen582 - mints12ValveOpen582)/2;
    cycleNumArray582[j] = cyclenum582;
    cycleDelayTimeArray582[j] = cycleDelayTime582;
    baselineIntegralArray582[j] = baselineIntegral582;
    UCNCounts582[j] = HistIntegral582 - baselineIntegral582;
    UCNCountsErr582[j] = sqrt(HistIntegral582 - baselineIntegral582);
    avecurArray582[j] = avecur582;
    curErrArray582[j] = (maxcur582 - mincur582)/2;
    counter582++;
  }


  // *************
  // 583
  //**************

  int counter583 = 0;
  double UCNCounts583 [100];
  double UCNCountsErr583[100];
  double tempIrradErrArray583[100];
  double tempVOErrArray583[100];
  double curErrArray583[100];
  ULong64_t events583;
  events583 = (Double_t) cycle_info583 -> GetEntries();

  for (ULong64_t j = 0 ; j < events583 ; j++ ){
    cycle_info583 -> GetEvent(j);

    irradStartTimeArray583[j] = irradStartTime583;
    cycleStartTimeArray583[j] = cycleStartTime583;
    HistIntegralArray583[j] = HistIntegral583;
    HistIntegralErrArray583[j] = sqrt(HistIntegral583);
    avetempIrradArray583[j] = avets12Irrad583;
    maxtempIrradArray583[j] = maxts12Irrad583;
    mintempIrradArray583[j] = mints12Irrad583;
    tempIrradErrArray582[j] = (maxts12Irrad583 - mints12Irrad583)/2;
    avetempVOArray583[j] = avets12ValveOpen583;
    maxtempVOArray583[j] = maxts12ValveOpen583;
    mintempVOArray583[j] = mints12ValveOpen583;
    tempVOErrArray583[j] = (maxts12ValveOpen583 - mints12ValveOpen583)/2;
    cycleNumArray583[j] = cyclenum583;
    cycleDelayTimeArray583[j] = cycleDelayTime583;
    baselineIntegralArray582[j] = baselineIntegral583;
    UCNCounts583[j] = HistIntegral583 - baselineIntegral583;
    UCNCountsErr583[j] = sqrt(HistIntegral583 - baselineIntegral583);
    avecurArray583[j] = avecur583;
    curErrArray583[j] = (maxcur583 - mincur583)/2;
    counter583++;
  }

  // ***************************
  // GRAPHS
  // **************************

  TCanvas *c582_cylceNum =  new TCanvas("c582_cycleNum" , "c582_cycleNum " , 1200, 900);
  c582_cycleNum-> Divide(2,2);

  TPad *p582_1 = c582_cycleNum->cd(1);
  p582_1->SetLogy(); 
  
  TGraphErrors *gr582_cyclehist = new TGraphErrors(counter582, cycleNumArray582 , HistIntegralArray582, 0, HistIntegralErrArray582);
  
  gr582_cyclehist -> SetTitle("UCN Counts vs Cycle Number");
  gr582_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr582_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr582_cyclehist -> GetYaxis()-> SetRangeUser(10, 500000);
  gr582_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr582_cyclehist -> SetMarkerColor(2);
  gr582_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr582_cyclecountmanual = new TGraphErrors(counter582, cycleNumArray582 , UCNCounts582, 0, UCNCountsErr582);
  
  gr582_cyclecountmanual -> SetTitle("UCN Counts vs Number");
  gr582_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Number" );
  gr582_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr582_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr582_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr582_cyclecountmanual -> SetMarkerColor(1);
  gr582_cyclecountmanual -> SetMarkerStyle(25);
  
  TLegend *leg2 = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr582_cyclehist, "With Background" , "p");
  leg2 -> AddEntry(gr582_cyclecountmanual, "Without Background" , "p");
  
  gr582_cyclehist -> Draw("Ap");
  gr582_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c582_cycleNum -> cd(2);
  TGraphErrors *gr582_cycledelay = new TGraphErrors (counter582 , cycleNumArray582, cycleDelayTimeArray582, 0 , 0);
  gr582_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr582_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr582_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr582_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr582_cycledelay -> SetMarkerStyle(20);
  gr582_cycledelay -> Draw("Ap");
  
  
  c582_cycleNum -> cd(3);
  TGraphErrors *gr582_cycletempIrrad = new TGraphErrors (counter582 , cycleNumArray582, avetempIrradArray582, 0 , tempIrradErrArray582);
  
  gr582_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr582_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr582_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr582_cycletempIrrad -> SetMarkerStyle(20);
  gr582_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  gr582_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr582_cycletempValveOpen = new TGraphErrors (counter582 , cycleNumArray582, avetempVOArray582, 0 , tempVOErrArray582);
  
  gr582_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr582_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr582_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr582_cycletempValveOpen -> SetMarkerStyle(20);
  gr582_cycletempValveOpen -> SetMarkerColor(2);
  gr582_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  TLegend *leg = new TLegend (0.7 , 0.7 , 0.9, 0.9);
  leg -> AddEntry(gr582_cycletempIrrad, "During Irradiation" , "p");
  leg -> AddEntry(gr582_cycletempValveOpen, "During Valve Open" , "p");
  
  gr582_cycletempIrrad -> Draw("AP");
  gr582_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c582_cycleNum -> cd(4);
  TGraphErrors *gr582_cyclecur = new TGraphErrors (counter582 , cycleNumArray582 , avecurArray582, 0, curErrArray582 );
  gr582_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr582_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr582_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr582_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr582_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr582_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr582_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr582_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr582_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr582_cyclecur -> SetMarkerStyle(20);
  gr582_cyclecur -> Draw("Ap");
  c582_cycleNum -> Update();


  // ***********************
  // 583
  // ******************
  TCanvas *c582_cylceNum =  new TCanvas("c583_cycleNum" , "c583_cycleNum " , 1200, 900);
  c583_cycleNum-> Divide(2,2);

  TPad *p583_1 = c583_cycleNum->cd(1);
  p583_1->SetLogy(); 
  
  TGraphErrors *gr583_cyclehist = new TGraphErrors(counter583, cycleNumArray583 , HistIntegralArray583, 0, HistIntegralErrArray583);
  
  gr583_cyclehist -> SetTitle("UCN Counts vs Cycle Number");
  gr583_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr583_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr583_cyclehist -> GetYaxis()-> SetRangeUser(10, 500000);
  gr583_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr583_cyclehist -> SetMarkerColor(2);
  gr583_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr583_cyclecountmanual = new TGraphErrors(counter583, cycleNumArray583 , UCNCounts583, 0, UCNCountsErr583);
  
  gr583_cyclecountmanual -> SetTitle("UCN Counts vs Number");
  gr583_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Number" );
  gr583_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr583_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr583_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr583_cyclecountmanual -> SetMarkerColor(1);
  gr583_cyclecountmanual -> SetMarkerStyle(25);
  
  gr583_cyclehist -> Draw("Ap");
  gr583_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c583_cycleNum -> cd(2);
  TGraphErrors *gr583_cycledelay = new TGraphErrors (counter583 , cycleNumArray583, cycleDelayTimeArray583, 0 , 0);
  gr583_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr583_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr583_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr583_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr583_cycledelay -> SetMarkerStyle(20);
  gr583_cycledelay -> Draw("Ap");
  
  
  c583_cycleNum -> cd(3);
  TGraphErrors *gr583_cycletempIrrad = new TGraphErrors (counter583 , cycleNumArray583, avetempIrradArray583, 0 , tempIrradErrArray583);
  
  gr583_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr583_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr583_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr583_cycletempIrrad -> SetMarkerStyle(20);
  gr583_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  gr583_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr583_cycletempValveOpen = new TGraphErrors (counter583 , cycleNumArray583, avetempVOArray583, 0 , tempVOErrArray583);
  
  gr583_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr583_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr583_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr583_cycletempValveOpen -> SetMarkerStyle(20);
  gr583_cycletempValveOpen -> SetMarkerColor(2);
  gr583_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr583_cycletempIrrad -> Draw("AP");
  gr583_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c583_cycleNum -> cd(4);
  TGraphErrors *gr583_cyclecur = new TGraphErrors (counter583 , cycleNumArray583 , avecurArray583, 0, curErrArray583 );
  gr583_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr583_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr583_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr583_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr583_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr583_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr583_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr583_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr583_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr583_cyclecur -> SetMarkerStyle(20);
  gr583_cyclecur -> Draw("Ap");
  c583_cycleNum -> Update();




}
