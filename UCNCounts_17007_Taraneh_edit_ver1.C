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

  double UCNIntegralArray_1muA[100];
  double UCNIntegralErrArray_1muA[100];
  double HistIntegralArray_1muA[100];
  double HistIntegralErrArray_1muA[100];
  double UCNIntegralManualArray_1muA[100];
  double UCNIntegralManualErrArray_1muA[100];
  double irradtimeArray_1muA[100];
  int counts_1muA = 0;

  double UCNIntegralArray_3muA[100];
  double UCNIntegralErrArray_3muA[100];
  double HistIntegralArray_3muA[100];
  double HistIntegralErrArray_3muA[100];
  double UCNIntegralManualArray_3muA[100];
  double UCNIntegralManualErrArray_3muA[100];
  double irradtimeArray_3muA[100];
  int counts_3muA = 0;

  double UCNIntegralArray_5muA[100];
  double UCNIntegralErrArray_5muA[100];
  double HistIntegralArray_5muA[100];
  double HistIntegralErrArray_5muA[100];
  double UCNIntegralManualArray_5muA[100];
  double UCNIntegralManualErrArray_5muA[100];
  double irradtimeArray_5muA[100];
  int counts_5muA = 0;

  double UCNIntegralArray_7muA[100];
  double UCNIntegralErrArray_7muA[100];
  double HistIntegralArray_7muA[100];
  double HistIntegralErrArray_7muA[100];
  double UCNIntegralManualArray_7muA[100];
  double UCNIntegralManualErrArray_7muA[100];
  double irradtimeArray_7muA[100];
  int counts_7muA = 0;

  double UCNIntegralArray_10muA[100];
  double UCNIntegralErrArray_10muA[100];
  double HistIntegralArray_10muA[100];
  double HistIntegralErrArray_10muA[100];
  double UCNIntegralManualArray_10muA[100];
  double UCNIntegralManualErrArray_10muA[100];
  double irradtimeArray_10muA[100];
  int counts_10muA = 0;
  
  for (midasrun = 614; midasrun < 662 ; midasrun++){

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
    if (midasrun == 618 || midasrun == 623 || midasrun == 624)
      continue;
    if (midasrun == 632 || midasrun == 635 || midasrun == 636)
      continue;
    if (midasrun == 637 || midasrun == 638 )
      continue;
    //if (midasrun == 639 && counts == 0)
    // continue;
    if (midasrun == 640 || midasrun == 642 || midasrun == 643)
      continue;
    if (midasrun == 647 || midasrun == 648 || midasrun == 649)
      continue;
    if (midasrun == 651 || midasrun == 652 || midasrun == 653)
      continue;
    if (midasrun == 654 || midasrun == 655 || midasrun == 656)
      continue;
    if (midasrun == 657 || midasrun == 658 || midasrun == 659)
      continue;
    
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
    cout << " The irradiation time for run " <<midasrun << " for cycle "<< counts << " is "<< cycleStartTimes - irradStartTimes << endl;

    // *******************
    // FOR THE FINAL GRAPH
    // ********************
    
    // 1.5 muA
    if (avecur > 1.4 && avecur < 1.6){
      UCNIntegralArray_1muA[counts_1muA] = UCNIntegral;
      UCNIntegralErrArray_1muA[counts_1muA] = UCNIntegralErr;
      HistIntegralArray_1muA[counts_1muA] = HistIntegral;
      HistIntegralErrArray_1muA[counts_1muA] = sqrt(HistIntegral);
      UCNIntegralManualArray_1muA[counts_1muA] =  HistIntegral - BaselineIntegral;
      UCNIntegralManualErrArray_1muA[counts_1muA] = sqrt(HistIntegral - BaselineIntegral);
      irradtimeArray_1muA[counts_1muA] = cycleStartTimes - irradStartTimes;
      counts_1muA++;
    }

    // 3 muA
    if (avecur > 2.8 && avecur < 3.2){
      UCNIntegralArray_3muA[counts_3muA] = UCNIntegral;
      UCNIntegralErrArray_3muA[counts_3muA] = UCNIntegralErr;
      HistIntegralArray_3muA[counts_3muA] = HistIntegral;
      HistIntegralErrArray_3muA[counts_3muA] = sqrt(HistIntegral);
      UCNIntegralManualArray_3muA[counts_3muA] =  HistIntegral - BaselineIntegral;
      UCNIntegralManualErrArray_3muA[counts_3muA] = sqrt(HistIntegral - BaselineIntegral);
      irradtimeArray_3muA[counts_3muA] = cycleStartTimes - irradStartTimes;
      counts_3muA++;
    }

    // 5 muA
    if (avecur > 4.8 && avecur < 5.2){
      UCNIntegralArray_5muA[counts_5muA] = UCNIntegral;
      UCNIntegralErrArray_5muA[counts_5muA] = UCNIntegralErr;
      HistIntegralArray_5muA[counts_5muA] = HistIntegral;
      HistIntegralErrArray_5muA[counts_5muA] = sqrt(HistIntegral);
      UCNIntegralManualArray_5muA[counts_5muA] =  HistIntegral - BaselineIntegral;
      UCNIntegralManualErrArray_5muA[counts_5muA] = sqrt(HistIntegral - BaselineIntegral);
      irradtimeArray_5muA[counts_5muA] = cycleStartTimes - irradStartTimes;
      counts_5muA++;
    }

    // 7 muA
    if (avecur > 6.8 && avecur < 7.3){
      if (midasrun == 639 && UCNIntegral < 1000)
        continue;
      // cout << midasrun << " " << UCNIntegral << endl;
      UCNIntegralArray_7muA[counts_7muA] = UCNIntegral;
      UCNIntegralErrArray_7muA[counts_7muA] = UCNIntegralErr;
      HistIntegralArray_7muA[counts_7muA] = HistIntegral;
      HistIntegralErrArray_7muA[counts_7muA] = sqrt(HistIntegral);
      UCNIntegralManualArray_7muA[counts_7muA] =  HistIntegral - BaselineIntegral;
      UCNIntegralManualErrArray_7muA[counts_7muA] = sqrt(HistIntegral - BaselineIntegral);
      irradtimeArray_7muA[counts_7muA] = cycleStartTimes - irradStartTimes;
      counts_7muA++;
    }

    // 10 muA
    if (avecur > 9.8 && avecur < 10.2){
      UCNIntegralArray_10muA[counts_10muA] = UCNIntegral;
      UCNIntegralErrArray_10muA[counts_10muA] = UCNIntegralErr;
      HistIntegralArray_10muA[counts_10muA] = HistIntegral;
      HistIntegralErrArray_10muA[counts_10muA] = sqrt(HistIntegral);
      UCNIntegralManualArray_10muA[counts_10muA] =  HistIntegral - BaselineIntegral;
      UCNIntegralManualErrArray_10muA[counts_10muA] = sqrt(HistIntegral - BaselineIntegral);
      irradtimeArray_10muA[counts_10muA] = cycleStartTimes - irradStartTimes;
      counts_10muA++;
      }
    counts++;
    //cout << counts << endl;
  }



  
  
  // *******************
  //     GRAPHS
  // ******************

  #if 0

  TCanvas *c_cylceNum =  new TCanvas("c_cycleNum" , "c_cycleNum " , 1200, 900);
  c_cycleNum-> Divide(2,2);

  TPad *p_1 = c_cycleNum->cd(1);
  p_1->SetLogy(); 
  TGraphErrors *gr_cyclecounts = new TGraphErrors (counts , cycleNumberArray, UCNIntegralArray, 0 , UCNIntegralErrArray);
  gr_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr_cyclecounts -> GetYaxis()-> SetRangeUser(100, 1000000);
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

#endif
 
  } 
  
  TCanvas *cAll = new TCanvas ("cAll" , "cAll", 1200, 900);
  cAll -> SetLogy();

  TGraphErrors *grcounts_1muA = new TGraphErrors (counts_1muA, irradtimeArray_1muA, UCNIntegralArray_1muA, 0 , UCNIntegralErrArray_1muA);
  grcounts_1muA -> GetYaxis() -> SetRangeUser (1, 1000000);
  grcounts_1muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_1muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_1muA -> SetMarkerStyle(20);
  grcounts_1muA -> GetXaxis()-> SetLimits(0, 200);
  grcounts_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_1muA -> SetMarkerColor(1);
    
  TGraphErrors *grhist_1muA = new TGraphErrors (counts_1muA, irradtimeArray_1muA, HistIntegralArray_1muA, 0 , HistIntegralErrArray_1muA);
  grhist_1muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_1muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_1muA -> SetMarkerStyle(25);
  grhist_1muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_1muA -> SetMarkerColor(1);

  TGraphErrors *grcountsM_1muA = new TGraphErrors (counts_1muA, irradtimeArray_1muA, UCNIntegralManualArray_1muA, 0 , UCNIntegralManualErrArray_1muA);
  grcountsM_1muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcountsM_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcountsM_1muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcountsM_1muA -> SetMarkerStyle(24);
  grcountsM_1muA -> GetXaxis()-> SetLimits(0, 150);
  grcountsM_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grcountsM_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcountsM_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcountsM_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcountsM_1muA -> SetMarkerColor(1);

  TGraphErrors *grcounts_3muA = new TGraphErrors (counts_3muA, irradtimeArray_3muA, UCNIntegralArray_3muA, 0 , UCNIntegralErrArray_3muA);
  grcounts_3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_3muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_3muA -> SetMarkerStyle(20);
  grcounts_3muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_3muA -> SetMarkerColor(2);
    
  TGraphErrors *grhist_3muA = new TGraphErrors (counts_3muA, irradtimeArray_3muA, HistIntegralArray_3muA, 0 , HistIntegralErrArray_3muA);
  grhist_3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_3muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_3muA -> SetMarkerStyle(25);
  grhist_3muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_3muA -> SetMarkerColor(2);

  TGraphErrors *grcountsM_3muA = new TGraphErrors (counts_3muA, irradtimeArray_3muA, UCNIntegralManualArray_3muA, 0 , UCNIntegralManualErrArray_3muA);
  grcountsM_3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcountsM_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcountsM_3muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcountsM_3muA -> SetMarkerStyle(24);
  grcountsM_3muA -> GetXaxis()-> SetLimits(0, 150);
  grcountsM_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grcountsM_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcountsM_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcountsM_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcountsM_3muA -> SetMarkerColor(2);


  TGraphErrors *grcounts_5muA = new TGraphErrors (counts_5muA, irradtimeArray_5muA, UCNIntegralArray_5muA, 0 , UCNIntegralErrArray_5muA);
  grcounts_5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_5muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_5muA -> SetMarkerStyle(20);
  grcounts_5muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_5muA -> SetMarkerColor(4);
    
  TGraphErrors *grhist_5muA = new TGraphErrors (counts_5muA, irradtimeArray_5muA, HistIntegralArray_5muA, 0 , HistIntegralErrArray_5muA);
  grhist_5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_5muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_5muA -> SetMarkerStyle(25);
  grhist_5muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_5muA -> SetMarkerColor(4);

  TGraphErrors *grcountsM_5muA = new TGraphErrors (counts_5muA, irradtimeArray_5muA, UCNIntegralManualArray_5muA, 0 , UCNIntegralManualErrArray_5muA);
  grcountsM_5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcountsM_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcountsM_5muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcountsM_5muA -> SetMarkerStyle(24);
  grcountsM_5muA -> GetXaxis()-> SetLimits(0, 150);
  grcountsM_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grcountsM_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcountsM_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcountsM_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcountsM_5muA -> SetMarkerColor(4);

  TGraphErrors *grcounts_7muA = new TGraphErrors (counts_7muA, irradtimeArray_7muA, UCNIntegralArray_7muA, 0 , UCNIntegralErrArray_7muA);
  grcounts_7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_7muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_7muA -> SetMarkerStyle(20);
  grcounts_7muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_7muA -> SetMarkerColor(8);
    
  TGraphErrors *grhist_7muA = new TGraphErrors (counts_7muA, irradtimeArray_7muA, HistIntegralArray_7muA, 0 , HistIntegralErrArray_7muA);
  grhist_7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_7muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_7muA -> SetMarkerStyle(25);
  grhist_7muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_7muA -> SetMarkerColor(8);

  TGraphErrors *grcountsM_7muA = new TGraphErrors (counts_7muA, irradtimeArray_7muA, UCNIntegralManualArray_7muA, 0 , UCNIntegralManualErrArray_7muA);
  grcountsM_7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcountsM_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcountsM_7muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcountsM_7muA -> SetMarkerStyle(24);
  grcountsM_7muA -> GetXaxis()-> SetLimits(0, 150);
  grcountsM_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grcountsM_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcountsM_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcountsM_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcountsM_7muA -> SetMarkerColor(8);


  TGraphErrors *grcounts_10muA = new TGraphErrors (counts_10muA, irradtimeArray_10muA, UCNIntegralArray_10muA, 0 , UCNIntegralErrArray_10muA);
  grcounts_10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_10muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_10muA -> SetMarkerStyle(20);
  grcounts_10muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_10muA -> SetMarkerColor(6);
    
  TGraphErrors *grhist_10muA = new TGraphErrors (counts_10muA, irradtimeArray_10muA, HistIntegralArray_10muA, 0 , HistIntegralErrArray_10muA);
  grhist_10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_10muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_10muA -> SetMarkerStyle(25);
  grhist_10muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_10muA -> SetMarkerColor(6);

  TGraphErrors *grcountsM_10muA = new TGraphErrors (counts_10muA, irradtimeArray_10muA, UCNIntegralManualArray_10muA, 0 , UCNIntegralManualErrArray_10muA);
  grcountsM_10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcountsM_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcountsM_10muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcountsM_10muA -> SetMarkerStyle(24);
  grcountsM_10muA -> GetXaxis()-> SetLimits(0, 150);
  grcountsM_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grcountsM_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcountsM_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcountsM_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcountsM_10muA -> SetMarkerColor(6);

  TLegend *legAll = new TLegend (0.6, 0.3 , 0.9 , 0.9);
  legAll -> AddEntry(grcounts_1muA, " Counts without background (fit) at 1 #muA" , "p");
  legAll -> AddEntry(grhist_1muA, "Counts with background at 1 #muA" , "p");
  legAll -> AddEntry(grcountsM_1muA, "Counts without background at 1 #muA ", "p");
  legAll -> AddEntry(grcounts_3muA, " Counts without background (fit) at 3 #muA" , "p");
  legAll -> AddEntry(grhist_3muA, "Counts with background at 3 #muA" , "p");
  legAll -> AddEntry(grcountsM_3muA, "Counts without background at 3 #muA ", "p");
  legAll -> AddEntry(grcounts_5muA, " Counts without background (fit) at 5 #muA" , "p");
  legAll -> AddEntry(grhist_5muA, "Counts with background at 5 #muA" , "p");
  legAll -> AddEntry(grcountsM_5muA, "Counts without background at 5 #muA ", "p");
  legAll -> AddEntry(grcounts_7muA, " Counts without background (fit) at 7 #muA" , "p");
  legAll -> AddEntry(grhist_7muA, "Counts with background at 7 #muA" , "p");
  legAll -> AddEntry(grcountsM_7muA, "Counts without background at 7 #muA ", "p");
  legAll -> AddEntry(grcounts_10muA, " Counts without background (fit) at 10 #muA" , "p");
  legAll -> AddEntry(grhist_10muA, "Counts with background at 10 #muA" , "p");
  legAll -> AddEntry(grcountsM_10muA, "Counts without background at 10 #muA ", "p");
  legAll -> SetTextSize(0.02);
  
  grcounts_1muA -> Draw("ap");
  grhist_1muA -> Draw("p");
  grcountsM_1muA -> Draw("p");
  grcounts_3muA -> Draw("p");
  grhist_3muA -> Draw("p");
  grcountsM_3muA -> Draw("p");
  grcounts_5muA -> Draw("p");
  grhist_5muA -> Draw("p");
  grcountsM_5muA -> Draw("p");
  grcounts_7muA -> Draw("p");
  grhist_7muA -> Draw("p");
  grcountsM_7muA -> Draw("p");
  grcounts_10muA -> Draw("p");
  grhist_10muA -> Draw("p");
  grcountsM_10muA -> Draw("p");
  legAll -> Draw();
  
}
