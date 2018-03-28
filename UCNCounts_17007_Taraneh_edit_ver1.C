// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17007.
// UCN COUNTS VS IRRADIATION TIME
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17007_Taraneh_edit_ver1(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE
  int midasrun = 0;
  char *filename[200];
  double irradStartTimes;
  double cycleStartTimes;
  double cycleDelayTime;
  double delaytimeArray[100];
  int cycleNumber;
  double cycleNumberArray [100];
  double UCNIntegral;
  double UCNIntegralArray [100];
  double UCNIntegralErr;
  double UCNIntegralErrArray [100];
  double HistIntegral;
  double HistIntegralArray [100];
  double HistIntegralErrArray[100];
  double avets12Irrad;
  double avets12IrradArray [100];
  double avets12ValveOpen;
  double avets12ValveOpenArray [100];
  double maxts12Irrad;
  double maxts12IrradArray [100];
  double maxts12ValveOpen;
  double maxts12ValveOpenArray [100];
  double mints12Irrad;
  double mints12IrradArray [100];
  double mints12ValveOpen;
  double mints12ValveOpenArray [100];
  double ts12IrradErr [100];
  double ts12ValveOpenErr [100];
  double avecur;
  double avecurArray [100];
  double maxcur;
  double maxcurArray [100];
  double mincur;
  double mincurArray [100];
  double ErrcurArray [100];
  double Baseline;
  double BaselineArray [100];
  double BaselineErr;
  double BaselineErrArray [100];
  double BaselineIrrad;
  double BaselineIrradArray [100];
  double BaselineIrradErr;
  double BaselineIrradErrArray [100];
  double BaselineIntegral;
  double BaselineIntegralArray[100];
  double BaselineIrradIntegral;
  double BaselineIrradIntegralArray[100];
  double UCNIntegralManualArray [100];
  double UCNIntegralManualErrArray[100];
  int counts = 0;
  double UCNIntegralAll[100];
  double UCNIntegralErrAll[100];
  double HistIntegralAll[100];
  double HistIntegralErrAll[100];
  double UCNIntegralManualAll[100];
  double UCNIntegralManualErrAll[100];

  // root files are created up to 645
  for (midasrun = 620; midasrun < 621 ; midasrun++){

    sprintf (filename , "./outputTree_%d.root",midasrun);
    TFile* fin = new TFile(Form(filename),"READ");
    
    TTree *outputTree = (TTree*) fin -> Get("cycle_info");
    
    outputTree -> SetBranchAddress("irradStartTimes" , &irradStartTimes);
    outputTree -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes);
    outputTree -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime);
    outputTree -> SetBranchAddress("cycleNumber", &cycleNumber);
    outputTree -> SetBranchAddress ("UCNIntegral" , &UCNIntegral);
    outputTree -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr);
    outputTree -> SetBranchAddress ("HistIntegral" , &HistIntegral);
    outputTree -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad);
    outputTree -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen);
    outputTree -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad);
    outputTree -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen);
    outputTree -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad);
    outputTree -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen);
    outputTree -> SetBranchAddress ("AVE_PRDCUR" , &avecur);
    outputTree -> SetBranchAddress ("MAX_PRDCUR" , &maxcur);
    outputTree -> SetBranchAddress ("MIN_PRDCUR" , &mincur);
    outputTree -> SetBranchAddress ("Baseline" , &Baseline);
    outputTree -> SetBranchAddress ("BaselineErr" , &BaselineErr);
    outputTree -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad);
    outputTree -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr);
    outputTree -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral);
    outputTree -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral);
 



  // **************************
  // **************************
  
  
  ULong64_t events;
  events = (Double_t) outputTree -> GetEntries();

  for (ULong64_t j = 0 ; j < events ; j++){
    outputTree -> GetEvent(j);
    UCNIntegralArray[counts] = UCNIntegral;
    UCNIntegralErrArray[counts] = UCNIntegralErr;
    HistIntegralArray[counts] = HistIntegral;
    HistIntegralErrArray[counts] = sqrt (HistIntegral);
    avets12IrradArray[counts] = avets12Irrad;
    avets12ValveOpenArray[counts] = avets12ValveOpen;
    maxts12IrradArray[counts] = maxts12Irrad;
    maxts12ValveOpenArray[counts] = maxts12ValveOpen;
    mints12IrradArray[counts] = mints12Irrad; 
    mints12ValveOpenArray[counts] = mints12ValveOpen;
    ts12IrradErr[counts] = (maxts12Irrad - mints12Irrad)/2;
    ts12ValveOpenErr[counts] = (maxts12ValveOpen - mints12ValveOpen)/2;
    avecurArray[counts] = avecur;
    maxcurArray[counts] = maxcur;
    mincurArray[counts] = mincur;
    ErrcurArray[counts] = (maxcur - mincur)/2;
    delaytimeArray[counts] = cycleDelayTime;
    cycleNumberArray[counts] = cycleNumber;
    BaselineArray[counts] = Baseline;
    BaselineIrradArray[counts] = BaselineIrrad;
    BaselineIrradErrArray[counts] = BaselineIrradErr;
    BaselineIntegralArray[counts] = BaselineIntegral;
    BaselineIrradIntegralArray[counts] = BaselineIrradIntegral;
    UCNIntegralManualArray[counts] = HistIntegral - BaselineIntegral;
    // cout << UCNIntegralManualArray[counts] << endl;
    UCNIntegralManualErrArray[counts] = sqrt(HistIntegral - BaselineIntegral);
    cout << " The irradiation time for run  for cycle "<< counts << " is "<< cycleStartTimes - irradStartTimes << endl;
    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    UCNIntegralAll[counts] = UCNIntegral;
    UCNIntegralErrAll[counts] = UCNIntegralErr;
    HistIntegralAll[counts] = HistIntegral;
    HistIntegralErrAll[counts] = sqrt (HistIntegral);
    UCNIntegralManualAll[counts] = HistIntegral - BaselineIntegral;
    UCNIntegralManualErrAll[counts] = sqrt(HistIntegral - BaselineIntegral);
    counts++;
  }



  
  
  // *******************
  //     GRAPHS
  // ******************

  

  TCanvas *c_cylceNum =  new TCanvas("c_cycleNum" , "c_cycleNum " , 1200, 900);
  c_cycleNum-> Divide(2,2);

  TPad *p_1 = c_cycleNum->cd(1);
  p_1->SetLogy(); 
  TGraphErrors *gr_cyclecounts = new TGraphErrors (counts , cycleNumberArray, UCNIntegralArray, 0 , UCNIntegralErrArray);
  gr_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr_cyclecounts -> GetYaxis()-> SetRangeUser(100, 500000);
  gr_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr_cyclecounts -> SetMarkerStyle(20);
  
  
  TGraphErrors *gr_cyclehist = new TGraphErrors(counts, cycleNumberArray , HistIntegralArray, 0, HistIntegralErrArray);
  
  gr_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr_cyclehist -> SetMarkerColor(2);
  gr_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr_cyclecountmanual = new TGraphErrors(counts, cycleNumberArray , UCNIntegralManualArray, 0, UCNIntegralManualErrArray);
  
  gr_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr_cyclecountmanual -> SetMarkerColor(1);
  gr_cyclecountmanual -> SetMarkerStyle(25);
  

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr_cyclecounts , "Without Background (fit)" , "p") ;
  leg2 -> AddEntry(gr_cyclehist , "With Background" , "p") ;
  leg2 -> AddEntry(gr_cyclecountmanual, "Without Background" , "p"); 
  leg2 -> SetTextSize(0.05);
  
  gr_cyclecounts -> Draw("Ap");
  gr_cyclehist -> Draw("p");
  gr_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c_cycleNum -> cd(2);
  TGraphErrors *gr_cycledelay = new TGraphErrors (counts , cycleNumberArray, delaytimeArray, 0 , 0);
  gr_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr_cycledelay -> SetMarkerStyle(20);
  
  gr_cycledelay -> Draw("Ap");
  
  
  c_cycleNum -> cd(3);
  TGraphErrors *gr_cycletempIrrad = new TGraphErrors (counts , cycleNumberArray, avets12IrradArray, 0 , ts12IrradErr);
  
  gr_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr_cycletempIrrad -> SetMarkerStyle(20);
  gr_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 1.3);
  gr_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr_cycletempValveOpen = new TGraphErrors (counts , cycleNumberArray, avets12ValveOpenArray, 0 , ts12ValveOpenErr);
  
  gr_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr_cycletempValveOpen -> SetMarkerStyle(20);
  gr_cycletempValveOpen -> SetMarkerColor(2);
  gr_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr_cycletempIrrad , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr_cycletempValveOpen , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  
  gr_cycletempIrrad -> Draw("AP");
  gr_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c_cycleNum -> cd(4);
  TGraphErrors *gr_cyclecur = new TGraphErrors (counts , cycleNumberArray , avecurArray, 0, ErrcurArray );
  gr_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr_cyclecur -> SetMarkerStyle(20);
  gr_cyclecur -> Draw("Ap");
  c_cycleNum -> Update();



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************

  TCanvas *c_counttemp = new TCanvas ("c_counttemp" , "c_counttemp " , 1200, 900);
  c_counttemp -> SetLogy();

  TGraphErrors *gr_countIrrad = new TGraphErrors (counts, avets12IrradArray, UCNIntegralArray, ts12IrradErr, UCNIntegralErrArray);
  gr_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr_countIrrad -> SetMarkerStyle(20);
  gr_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr_countIrrad -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr_countIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr_countIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr_countIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr_countIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr_HistIrrad = new TGraphErrors (counts, avets12IrradArray, HistIntegralArray, ts12IrradErr, HistIntegralErrArray);
  gr_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr_HistIrrad -> SetMarkerStyle(25);
  gr_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr_HistIrrad -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  

  TGraphErrors *gr_countValveOpen = new TGraphErrors (counts, avets12ValveOpenArray, UCNIntegralArray, ts12ValveOpenErr, UCNIntegralErrArray);
  gr_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr_countValveOpen -> SetMarkerStyle(20);
  gr_countValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr_countValveOpen -> SetMarkerColor(2);


  TGraphErrors *gr_HistValveOpen = new TGraphErrors (counts, avets12ValveOpenArray, HistIntegralArray, ts12ValveOpenErr, HistIntegralErrArray);
  gr_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr_HistValveOpen -> SetMarkerStyle(25);
  gr_HistValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
  gr_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr_HistValveOpen -> SetMarkerColor(2);

  TLegend *leg3 = new TLegend(0.25,0.7, 0.9, 0.9);
  leg3 -> AddEntry(gr_countIrrad , "Irradiation time + delay time, without background" , "p") ;
  //leg3 -> AddEntry(gr_countValveOpen , "Valve open, without background" , "p") ;
  leg3 -> AddEntry(gr_HistIrrad , "Irradiation time + delay time, with background" , "p") ;
  //leg3 -> AddEntry(gr_HistValveOpen , "Valve open, with background" , "p") ;
  leg3 -> SetTextSize(0.04);

  gr_countIrrad -> Draw("AP");
  //gr_countValveOpen -> Draw("p");
   gr_HistIrrad -> Draw("p");
  //gr_HistValveOpen -> Draw("p");
  leg3 -> Draw();


 
  }
  
}
