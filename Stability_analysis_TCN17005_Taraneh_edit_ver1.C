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
  // TDatime dh(2017,11,16,3,28,42);

  
  //LOADING THE DATA IN ...
  TFile *fin582 = new TFile ("./outputTree_582.root", "READ");
  TFile *fin583 = new TFile ("./outputTree_583.root", "READ");

  // GETTING THE CYCLE INFORMATION TREE ..
  TTree *cycle_info582 = (TTree*) fin582 -> Get("cycle_info");
  TTree *cycle_info583 = (TTree*) fin583 -> Get("cycle_info");

  // IRRADIATION TIME
  double irradStartTime582; // irradiation start time for run 582
  double irradStartTime583; // irradiation start time for run 583

  double irradStartTimeArray582[100]; // irradiation start time array for run 582
  double irradStartTimeArray583[100]; // irradiation start time array for run 583

    
  cycle_info582 -> SetBranchAddress("irradStartTimes", &irradStartTime582);
  cycle_info583 -> SetBranchAddress("irradStartTimes", &irradStartTime583);

  // CYCLE START TIME
  double cycleStartTime582; // cycle start time for run 582
  double cycleStartTime583; // cycle start time for run 583

  double cycleStartTimeArray582[100]; // cycle start time array for run 582
  double cycleStartTimeArray583[100]; // cycle start time array for run 583

  cycle_info582 -> SetBranchAddress("cycleStartTimes" , &cycleStartTime582);
  cycle_info583 -> SetBranchAddress("cycleStartTimes" , &cycleStartTime583);

  // INTEGRAL OF THE UCN RATE
  double HistIntegral582; // histogram integral for run 582
  double HistIntegral583; // histogram integral for ru 583

  double HistIntegralArray582[100]; // histogram integral array for run 582
  double HistIntegralArray583[100]; // histogram integral array for run 583

  double HistIntegralErrArray582[100]; // histogral integral error array for run 582
  double HistIntegralErrArray583[100]; // histogram integral error array for run 583

  cycle_info582 -> SetBranchAddress("HistIntegral", &HistIntegral582);
  cycle_info583 -> SetBranchAddress("HistIntegral" , &HistIntegral583);

  // ISOPURE TEMPERATURE AVERAGE DURING IRRADIAITON
  double avets12Irrad582; // average ts12 temparature during irradiation for run 582
  double avets12Irrad583; // average ts12 temperature during irradiation for run 583

  double avetempIrradArray582[100]; // average ts12 temperature array during irradiation for run 582
  double avetempIrradArray583[100]; // average ts12 temperature array during irradiation for run 583
  
  cycle_info582 -> SetBranchAddress("AVE_TS12_IRRAD" , &avets12Irrad582);
  cycle_info583 -> SetBranchAddress("AVE_TS12_IRRAD" , &avets12Irrad583);

  // MAX ISOPURE TEMPERATURE DURING IRRADIATION
  double maxts12Irrad582; // max ts12 temperature during irradiation for run 582
  double maxts12Irrad583; // max ts12 temperature during irradiation for run 583

  double maxtempIrradArray582[100]; // max ts12 temperature array during irradiation for run 582
  double maxtempIrradArray583[100]; // max ts12 temperature array during irradiation for run 583
 
  cycle_info582 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad582);
  cycle_info583 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad583);


  // MINIMUM ISOPURE TEMPERATURE DURING IRRADIATION
  double mints12Irrad582; // min ts12 temperature during irradiation for run 582
  double mints12Irrad583; // min ts12 temperature during irradiation for run 583

  double mintempIrradArray582[100]; // min ts12 temperature array during irradiation for run 582 
  double mintempIrradArray583[100]; // min ts12 temperature array during irradiation for run 583
  
  cycle_info582 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad582);
  cycle_info583 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad583);

  // AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen582; // average ts12 temperature during valve open for run 582
  double avets12ValveOpen583; // average ts12 temperature during valve open for run 583

  double avetempVOArray582[100]; // average ts12 temperature array during valve open for run 582
  double avetempVOArray583[100]; // average ts12 temperature array during valve open for run 583
			     
  cycle_info582 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen583);

  // MAXIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double maxts12ValveOpen582; // max ts12 temperature during valve open for run 582
  double maxts12ValveOpen583; // max ts12 temperature during valve open for run 583

  double maxtempVOArray582[100]; // max ts12 temperature array during valve open for run 582
  double maxtempVOArray583[100]; // max ts12 temperature array during valve open for run 583

  cycle_info582 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen583);

  // MINIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double mints12ValveOpen582; // min ts12 temperature during valve open for run 582
  double mints12ValveOpen583; // min ts12 temperature during valve open for run 583

  double mintempVOArray582[100]; // min ts12 temperature array during valve open for run 582
  double mintempVOArray583[100]; // min ts12 temperature array during valve open for run 583

  cycle_info582 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen582);
  cycle_info583 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen583);

  // CYCLE NUMBER
  int cyclenum582; // cycle number for run 582
  int cyclenum583; // cycle number for run 583

  double cycleNumArray582[100]; // cycle number array for run 582
  double cycleNumArray583[100]; // cycle number arrat for run 583

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

  double baselinerate582;
  double baselinerate583;



  cycle_info582 -> SetBranchAddress ("BASELINERATE" , &baselinerate582);
  cycle_info583 -> SetBranchAddress ("BASELINERATE" , &baselinerate583);


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


  // CYCLE VALVE OPEN TIME

  double cycleValveOpen582;
  double cycleValveOpen583;

  cycle_info582 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpen582);
  cycle_info583 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpen583);

  double cycleValveOpenArray582[100];
  double cycleValveOpenArray583[100];

  // CYCLE VALVE CLOSE TIME

  double cycleValveClose582;
  double cycleValveClose583;

  cycle_info582 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveClose582);
  cycle_info583 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveClose583);

  double baselinecountsArray582[100];
  double baselinecountsArray583[100];

  
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

  // %%%%%%%%%%%%%%%%%%%
  // OVERALL PARAMETERS
  // %%%%%%%%%%%%%%%%%%%

  double HistIntegralAll[100]; // histogram integral for all runs
  double HistIntegralErrAll[100]; // histogram integral error for all runs
  double UCNCountsAll[100]; // UCN counts (without background) for all runs
  double UCNCountsErrAll[100]; // UCN counts error ( without background) for all runs
  double curAll[100]; // current for all runs 
  double curErrAll[100]; // current error for all runs
  double tempIrradAll[100]; // temparature during irradiation for all runs
  double tempIrradErrAll[100]; // temperature during irradiaiton error for all runs
  double tempVOAll[100]; // temperature during valve open for all runs
  double tempVOErrAll[100]; // temperature error during valve open for all runs
  double cycleNumArrayAll[100]; // the cycle number for all the runs
  double cycleDelayTimeArrayAll[100]; // cycle delay time for all the runs
  double cycleStartTimeAll[100];
  int counterAll;
  
  events582 = (Double_t) cycle_info582 -> GetEntries();

  for (ULong64_t j = 0 ; j < events582 ; j++ ){
    cycle_info582 -> GetEvent(j);
    if (j == 11 || j == 19 || j > 24)
      continue;
    irradStartTimeArray582[counter582] = irradStartTime582;
    cycleStartTimeArray582[counter582] = cycleStartTime582;
    HistIntegralArray582[counter582] = HistIntegral582;
    HistIntegralErrArray582[counter582] = sqrt(HistIntegral582);
    avetempIrradArray582[counter582] = avets12Irrad582;
    maxtempIrradArray582[counter582] = maxts12Irrad582;
    mintempIrradArray582[counter582] = mints12Irrad582;
    tempIrradErrArray582[counter582] = (maxts12Irrad582 - mints12Irrad582)/2;
    avetempVOArray582[counter582] = avets12ValveOpen582;
    maxtempVOArray582[counter582] = maxts12ValveOpen582;
    mintempVOArray582[counter582] = mints12ValveOpen582;
    tempVOErrArray582[counter582] = (maxts12ValveOpen582 - mints12ValveOpen582)/2;
    cycleNumArray582[counter582] = cyclenum582;
    cycleDelayTimeArray582[counter582] = cycleDelayTime582;
    baselinecountsArray582[counter582] = baselinerate582*(cycleValveClose582 - cycleValveOpen582);
    UCNCounts582[counter582] = HistIntegralArray582[counter582] - baselinecountsArray582[counter582];
    UCNCountsErr582[counter582] = sqrt(UCNCounts582[counter582]);
    avecurArray582[counter582] = avecur582;
    curErrArray582[counter582] = (maxcur582 - mincur582)/2;
    // %%%%%%%%%%%%%%%%%%%%%%%
    HistIntegralAll[counter582] = HistIntegral582;
    HistIntegralErrAll[counter582] =  sqrt(HistIntegral582);
    UCNCountsAll[counter582] = HistIntegralArray582[counter582] - baselinecountsArray582[counter582];
    UCNCountsErrAll[counter582] = sqrt(UCNCounts582[counter582]);
    curAll[counter582] = avecur582;
    curErrAll[counter582] = (maxcur582 - mincur582)/2;
    tempIrradAll[counter582] = avets12Irrad582;
    tempIrradErrAll[counter582] = (maxts12Irrad582 - mints12Irrad582)/2;
    tempVOAll[counter582] = avets12ValveOpen582;
    tempVOErrAll[counter582] = (maxts12ValveOpen582 - mints12ValveOpen582)/2;
    cycleNumArrayAll[counter582] = cyclenum582;
    cycleDelayTimeArrayAll[counter582] = cycleDelayTime582;
    cycleStartTimeAll[counter582] = cycleStartTime582;
    cout << std::fixed <<cycleStartTimeAll[counter582] << endl;
    counterAll= counter582;
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

    irradStartTimeArray583[counter583] = irradStartTime583;
    cycleStartTimeArray583[counter583] = cycleStartTime583;
    HistIntegralArray583[counter583] = HistIntegral583;
    HistIntegralErrArray583[counter583] = sqrt(HistIntegral583);
    avetempIrradArray583[counter583] = avets12Irrad583;
    maxtempIrradArray583[counter583] = maxts12Irrad583;
    mintempIrradArray583[counter583] = mints12Irrad583;
    tempIrradErrArray582[counter583] = (maxts12Irrad583 - mints12Irrad583)/2;
    avetempVOArray583[counter583] = avets12ValveOpen583;
    maxtempVOArray583[counter583] = maxts12ValveOpen583;
    mintempVOArray583[counter583] = mints12ValveOpen583;
    tempVOErrArray583[counter583] = (maxts12ValveOpen583 - mints12ValveOpen583)/2;
    cycleNumArray583[counter583] = cyclenum583;
    cycleDelayTimeArray583[counter583] = cycleDelayTime583;
    baselinecountsArray583[counter583] = baselinerate583*(cycleValveClose583 - cycleValveOpen583);
    UCNCounts583[counter583] = HistIntegralArray583[counter583] - baselinecountsArray583[counter583];
    UCNCountsErr583[counter583] = sqrt(UCNCounts583[counter583]);
    avecurArray583[counter583] = avecur583;
    curErrArray583[counter583] = (maxcur583 - mincur583)/2;
    // %%%%%%%%%%%%%%%%%%%%%%%
    HistIntegralAll[counter582 + counter583] = HistIntegral583;
    HistIntegralErrAll[counter582 + counter583] =  sqrt(HistIntegral583);
    UCNCountsAll[counter582 + counter583] =HistIntegralArray583[counter583] - baselinecountsArray583[counter583] ;
    UCNCountsErrAll[counter582 + counter583] = sqrt(UCNCounts583[counter583]);
    curAll[counter582 + counter583] = avecur583;
    curErrAll[counter582 + counter583] = (maxcur583 - mincur583)/2;
    tempIrradAll[counter582 + counter583] = avets12Irrad583;
    tempIrradErrAll[counter582 + counter583] = (maxts12Irrad583 - mints12Irrad583)/2;
    tempVOAll[counter582 + counter583] = avets12ValveOpen583;
    tempVOErrAll[counter582 + counter583] = (maxts12ValveOpen583 - mints12ValveOpen583)/2;
    cycleNumArrayAll[counter582 + counter583] = cyclenum583;
    cycleDelayTimeArrayAll[counter582 + counter583] = cycleDelayTime583;
    cycleStartTimeAll[counter582 + counter583] = cycleStartTime583;
    counterAll = counter582 + counter583;
    counter583++;
  }



  // ***************************
  // GRAPHS
  // **************************

  TCanvas *c582_cylceNum =  new TCanvas("c582_cycleNum" , "c582_cycleNum " , 1200, 900);
  c582_cycleNum-> Divide(2,2);

  TPad *p582_1 = c582_cycleNum->cd(1);
  //p582_1->SetLogy(); 
  
  TGraphErrors *gr582_cyclehist = new TGraphErrors(counter582, cycleNumArray582 , HistIntegralArray582, 0, HistIntegralErrArray582);
  
  gr582_cyclehist -> SetTitle("UCN Counts vs Cycle Number");
  gr582_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr582_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr582_cyclehist -> GetYaxis()-> SetRangeUser(10, 100000);
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
  //p583_1->SetLogy(); 
  
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


  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // OVERALL GRAPH

  TCanvas *cAll_cylceNum =  new TCanvas("cAll_cycleNum" , "cAll_cycleNum " , 1200, 900);
  cAll_cycleNum-> Divide(2,2);

  TPad *pAll_1 = cAll_cycleNum->cd(1);
  //pAll_1->SetLogy(); 
  
  TGraphErrors *grAll_cyclehist = new TGraphErrors(counterAll, cycleStartTimeAll , HistIntegralAll, 0, HistIntegralErrAll);
  
  grAll_cyclehist -> SetTitle("UCN Counts vs Cycle Start Time");
  grAll_cyclehist -> GetXaxis()-> SetTitle("Cycle Start Time " );
  grAll_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //grAll_cyclehist -> GetYaxis()-> SetRangeUser(10, 500000);
  grAll_cyclehist -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cyclehist -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cyclehist -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cyclehist -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cyclehist -> GetXaxis() -> SetLabelSize(.04);
  grAll_cyclehist -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cyclehist -> GetYaxis() -> SetTitleOffset(1.3);
  grAll_cyclehist -> SetMarkerColor(2);
  grAll_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *grAll_cyclecountmanual = new TGraphErrors(counterAll, cycleStartTimeAll , UCNCountsAll, 0, UCNCountsErrAll);
  
  grAll_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Start Time");
  grAll_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Start Time" );
  grAll_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  grAll_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  grAll_cyclecountmanual -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cyclecountmanual -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cyclecountmanual -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cyclecountmanual -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cyclecountmanual -> GetXaxis() -> SetLabelSize(.04);
  grAll_cyclecountmanual -> SetMarkerColor(1);
  grAll_cyclecountmanual -> SetMarkerStyle(25);
  
  grAll_cyclehist -> Draw("Ap");
  grAll_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  cAll_cycleNum -> cd(2);
  TGraphErrors *grAll_cycledelay = new TGraphErrors (counterAll , cycleStartTimeAll, cycleDelayTimeArrayAll, 0 , 0);
  grAll_cycledelay -> SetTitle("Delay Time vs Cycle Start Time");
  grAll_cycledelay -> GetXaxis()-> SetTitle("Cycle Start Time" );
  grAll_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll_cycledelay -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cycledelay -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycledelay -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cycledelay -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cycledelay -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cycledelay -> GetXaxis() -> SetLabelSize(.04);
  
  grAll_cycledelay -> SetMarkerStyle(20);
  grAll_cycledelay -> Draw("Ap");
  
  
  cAll_cycleNum -> cd(3);
  TGraphErrors *grAll_cycletempIrrad = new TGraphErrors (counterAll , cycleStartTimeAll, tempIrradAll, 0 , tempIrradErrAll);
  
  grAll_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  grAll_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grAll_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Start Time");
  grAll_cycletempIrrad -> SetMarkerStyle(20);
  grAll_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  grAll_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cycletempIrrad -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cycletempIrrad -> GetXaxis() -> SetLabelSize(.04);
  
  TGraphErrors *grAll_cycletempValveOpen = new TGraphErrors (counterAll , cycleStartTimeAll, tempVOAll, 0 , tempVOErrAll);
  
  grAll_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Start Time");
  grAll_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  grAll_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Start Time");
  grAll_cycletempValveOpen -> SetMarkerStyle(20);
  grAll_cycletempValveOpen -> SetMarkerColor(2);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycletempValveOpen -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cycletempValveOpen -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cycletempValveOpen -> GetXaxis() -> SetLabelSize(.04);
  
  grAll_cycletempIrrad -> Draw("AP");
  grAll_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  cAll_cycleNum -> cd(4);
  TGraphErrors *grAll_cyclecur = new TGraphErrors (counterAll , cycleStartTimeAll , curAll, 0, curErrAll );
  grAll_cyclecur -> SetTitle(" Average Beam Current vs Cycle Start Time");
  grAll_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  grAll_cyclecur -> GetXaxis()-> SetTitle("Cycle Start Time");
  //grAll_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grAll_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grAll_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cyclecur -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cyclecur -> GetXaxis() -> SetTimeDisplay(1);
  grAll_cyclecur -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cyclecur -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cyclecur -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cyclecur -> GetXaxis() -> SetLabelSize(.04);
  
  grAll_cyclecur -> SetMarkerStyle(20);
  grAll_cyclecur -> Draw("Ap");
  cAll_cycleNum -> Update();


}
