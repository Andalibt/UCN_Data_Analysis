// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17003A WHICH IS THE
// UCN COUNT VS THE ISOPURE TEMPERATURE.
// DURING THE DATA ACQUISITON, THE ISOPURE HELIUM
// TEMPERATURE INCREASED.
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17003A_Taraneh_edit_ver1(){

  TFile *fin548 = new TFile ("outputTree_548.root", "READ");
  
  TTree *outputTree548 = (TTree*) fin548 -> Get("cycle_info");


  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double cycleDelayTime548;
  outputTree548 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime548);
  double delaytimeArray548[100];

  int cycleNumber548;
  outputTree548 -> SetBranchAddress("cycleNumber", &cycleNumber548);
  double cycleNumberArray548 [100];
  
  double UCNIntegral548;
  outputTree548 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral548);
  double UCNIntegralArray548 [100];

  double UCNIntegralErr548;
  outputTree548 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr548);
  double UCNIntegralErrArray548 [100];

  double HistIntegral548;
  outputTree548 -> SetBranchAddress ("HistIntegral" , &HistIntegral548); 
  double HistIntegralArray548 [100];
  double HistIntegralErrArray548[100];

  double avets12Irrad548;
  outputTree548 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad548);
  double avets12IrradArray548 [100];
  
  double avets12ValveOpen548;
  outputTree548 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen548);
  double avets12ValveOpenArray548 [100];

  double maxts12Irrad548;
  outputTree548 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad548);
  double maxts12IrradArray548 [100];
  
  double maxts12ValveOpen548;
  outputTree548 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen548);
  double maxts12ValveOpenArray548 [100];

  double mints12Irrad548;
  outputTree548 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad548);
  double mints12IrradArray548 [100];
  
  double mints12ValveOpen548;
  outputTree548 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen548);
  double mints12ValveOpenArray548 [100];

  double ts12IrradErr548 [100];
  double ts12ValveOpenErr548 [100];

  double avecur548;
  outputTree548 -> SetBranchAddress ("AVE_PRDCUR" , &avecur548);
  double avecurArray548 [100];

  double maxcur548;
  outputTree548 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur548);
  double maxcurArray548 [100];

  double mincur548;
  outputTree548 -> SetBranchAddress ("MIN_PRDCUR" , &mincur548);
  double mincurArray548 [100];

  double ErrcurArray548 [100];

  double Baseline548;
  outputTree548 -> SetBranchAddress ("Baseline" , &Baseline548);
  double BaselineArray548 [100];

  double BaselineErr548;
  outputTree548 -> SetBranchAddress ("BaselineErr" , &BaselineErr548);
  double BaselineErrArray548 [100];

  double BaselineIrrad548;
  outputTree548 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad548);
  double BaselineIrradArray548 [100];

  double BaselineIrradErr548;
  outputTree548 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr548);
  double BaselineIrradErrArray548 [100];

  double BaselineIntegral548;
  outputTree548 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral548);
  double BaselineIntegralArray548[100];

  double BaselineIrradIntegral548;
  outputTree548 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral548);
  double BaselineIrradIntegralArray548[100];

  double UCNIntegralManualArray548 [100];
  double UCNIntegralManualErrArray548[100];


  int counts_548 = 0;
  
  ULong64_t events548;
  events548 = (Double_t) outputTree548 -> GetEntries();

  for (ULong64_t j = 0 ; j < events548 ; j++){
    outputTree548 -> GetEvent(j);
    UCNIntegralArray548[counts_548] = UCNIntegral548;
    UCNIntegralErrArray548[counts_548] = UCNIntegralErr548;
    HistIntegralArray548[counts_548] = HistIntegral548;
    HistIntegralErrArray548[counts_548] = sqrt (HistIntegral548);
    avets12IrradArray548[counts_548] = avets12Irrad548;
    avets12ValveOpenArray548[counts_548] = avets12ValveOpen548;
    maxts12IrradArray548[counts_548] = maxts12Irrad548;
    maxts12ValveOpenArray548[counts_548] = maxts12ValveOpen548;
    mints12IrradArray548[counts_548] = mints12Irrad548; 
    mints12ValveOpenArray548[counts_548] = mints12ValveOpen548;
    ts12IrradErr548[counts_548] = (maxts12Irrad548 - mints12Irrad548)/2;
    ts12ValveOpenErr548[counts_548] = (maxts12ValveOpen548 - mints12ValveOpen548)/2;
    avecurArray548[counts_548] = avecur548;
    maxcurArray548[counts_548] = maxcur548;
    mincurArray548[counts_548] = mincur548;
    ErrcurArray548[counts_548] = (maxcur548 - mincur548)/2;
    delaytimeArray548[counts_548] = cycleDelayTime548;
    cycleNumberArray548[counts_548] = cycleNumber548;
    BaselineArray548[counts_548] = Baseline548;
    BaselineIrradArray548[counts_548] = BaselineIrrad548;
    BaselineIrradErrArray548[counts_548] = BaselineIrradErr548;
    BaselineIntegralArray548[counts_548] = BaselineIntegral548;
    BaselineIrradIntegralArray548[counts_548] = BaselineIrradIntegral548;
    UCNIntegralManualArray548[counts_548] = HistIntegral548 - BaselineIntegral548;
    UCNIntegralManualErrArray548[counts_548] = sqrt(HistIntegral548 - BaselineIntegral548);
    counts_548++;
  }

  // *******************
  //     GRAPHS
  // ******************

  TCanvas *canvas_cylceNum =  new TCanvas("canvas_cycleNum" , " " , 1200, 900);
  canvas_cycleNum-> Divide(2,2);

  TPad *p5 = canvas_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr548_cyclecounts = new TGraphErrors (counts_548 , cycleNumberArray548, UCNIntegralArray548, 0 , UCNIntegralErrArray548);
  gr548_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr548_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr548_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr548_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr548_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr548_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr548_cyclehist = new TGraphErrors(counts_548, cycleNumberArray548 , HistIntegralArray548, 0, HistIntegralErrArray548);
  
  gr548_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr548_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr548_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr548_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr548_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr548_cyclehist -> SetMarkerColor(2);
  gr548_cyclehist -> SetMarkerStyle(20);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr548_cyclecounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr548_cyclehist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);
  
  gr548_cyclecounts -> Draw("Ap");
  gr548_cyclehist -> Draw("p");
  
  leg2-> Draw();
  
  canvas_cycleNum -> cd(2);
  TGraphErrors *gr548_cycledelay = new TGraphErrors (counts_548 , cycleNumberArray548, delaytimeArray548, 0 , 0);
  gr548_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr548_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr548_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr548_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr548_cycledelay -> SetMarkerStyle(20);
  
  gr548_cycledelay -> Draw("Ap");
  
  
  canvas_cycleNum -> cd(3);
  TGraphErrors *gr548_cycletempIrrad = new TGraphErrors (counts_548 , cycleNumberArray548, avets12IrradArray548, 0 , ts12IrradErr548);
  
  gr548_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr548_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr548_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr548_cycletempIrrad -> SetMarkerStyle(20);
  gr548_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 2.3);
  gr548_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr548_cycletempValveOpen = new TGraphErrors (counts_548 , cycleNumberArray548, avets12ValveOpenArray548, 0 , ts12ValveOpenErr548);
  
  gr548_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr548_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr548_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr548_cycletempValveOpen -> SetMarkerStyle(20);
  gr548_cycletempValveOpen -> SetMarkerColor(2);
  gr548_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr548_cycletempIrrad , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr548_cycletempValveOpen , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  
  gr548_cycletempIrrad -> Draw("AP");
  gr548_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  canvas_cycleNum -> cd(4);
  TGraphErrors *gr548_cyclecur = new TGraphErrors (counts_548 , cycleNumberArray548 , avecurArray548, 0, ErrcurArray548 );
  gr548_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr548_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr548_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr548_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr548_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr548_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr548_cyclecur -> SetMarkerStyle(20);
  gr548_cyclecur -> Draw("Ap");
  canvas_cycleNum -> Update();

}
