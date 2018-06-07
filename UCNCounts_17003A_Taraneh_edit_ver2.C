// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17003A WHICH IS THE
// UCN COUNT VS THE ISOPURE TEMPERATURE.
// DURING THE DATA ACQUISITON, THE ISOPURE HELIUM
// TEMPERATURE INCREASED.
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17003A_Taraneh_edit_ver2(){

  TFile *fin548 = new TFile ("./2ndpass/outputTree_548.root", "READ");
  
  TTree *outputTree548 = (TTree*) fin548 -> Get("cycle_info");


  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double cycleDelayTime548;
  outputTree548 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime548);
  double delaytimeArray548[100];

  int cycleNumber548;
  outputTree548 -> SetBranchAddress("cycleNumber", &cycleNumber548);
  double cycleNumberArray548 [100];

  double HistIntegral548;
  outputTree548 -> SetBranchAddress ("HistIntegral" , &HistIntegral548); 
  double HistIntegralArray548 [100];
  double HistIntegralErrArray548[100];

  double BASELINERATE548;
  outputTree548 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE548);
  double BASELINERATEArray548[100];

  double cycleValveOpen548;
  outputTree548 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpen548);

  double cycleValveClose548;
  outputTree548 -> SetBranchAddress ("cycleValveCloseTime", &cycleValveClose548);

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

  double UCNIntegralManualArray548 [100];
  double UCNIntegralManualErrArray548[100];



  double avets11VO;
  outputTree548 -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11VO);
  double avets14VO;
  outputTree548 -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14VO);
  double avets16VO;
  outputTree548 -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16VO);

  double mints11VO;
  outputTree548 -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11VO);
  double maxts11VO;
  outputTree548 -> SetBranchAddress ("MAX_TS11_VALVEOPEN", &maxts11VO);
  double mints14VO;
  outputTree548 -> SetBranchAddress ("MIN_TS14_VALVEOPEN", &mints14VO);
  double maxts14VO;
  outputTree548 -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14VO);
  double mints16VO;
  outputTree548 -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16VO);
  double maxts16VO;
  outputTree548 -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16VO);

  double ts11Err;
  double ts14Err;
  double ts16Err;


  ofstream myfile;

  myfile.open("./2ndpass/TCN17003A_Data.csv",std::ios_base::app);

  int counts_548 = 0;
  
  ULong64_t events548;
  events548 = (Double_t) outputTree548 -> GetEntries();

  for (ULong64_t j = 0 ; j < events548 ; j++){
    outputTree548 -> GetEvent(j);

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
    UCNIntegralManualArray548[counts_548] = HistIntegral548 - BASELINERATE548*(cycleValveClose548 - cycleValveOpen548);
    cout << UCNIntegralManualArray548[counts_548] << endl;
    ts11Err = (maxts11VO - mints11VO)/2;
    ts14Err = (maxts14VO - mints14VO)/2;
    ts16Err = (maxts16VO - mints16VO)/2;
    UCNIntegralManualErrArray548[counts_548] = sqrt(UCNIntegralManualArray548[counts_548]);
    myfile << HistIntegralArray548[counts_548] << " " << HistIntegralErrArray548[counts_548] << " " << UCNIntegralManualArray548[counts_548] << " " << UCNIntegralManualErrArray548[counts_548] << " " << avecurArray548[counts_548] << " " << ErrcurArray548[counts_548] << " " <<avets11VO << " " << ts11Err << " " << avets12ValveOpenArray548[counts_548] << " " << ts12ValveOpenErr548[counts_548] << avets14VO << " " << ts14Err << " " << avets16VO << " " << ts16Err << endl;
    counts_548++;
  }


  
  // *******************
  //     GRAPHS
  // ******************

  TCanvas *canvas_cylceNum =  new TCanvas("canvas_cycleNum" , " " , 1200, 900);
  canvas_cycleNum-> Divide(2,2);

  TPad *p5 = canvas_cycleNum->cd(1);
  p5->SetLogy(); 
  
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

  TGraphErrors *gr548_cyclecountmanual = new TGraphErrors(counts_548, cycleNumberArray548 , UCNIntegralManualArray548, 0, UCNIntegralManualErrArray548);
  
  gr548_cyclecountmanual -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr548_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr548_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr548_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr548_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr548_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr548_cyclecountmanual -> SetMarkerColor(1);
  gr548_cyclecountmanual -> SetMarkerStyle(25);
  

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr548_cyclehist , "With Background" , "p") ;
  leg2 -> AddEntry(gr548_cyclecountmanual, "Without Background" , "p"); 
  leg2 -> SetTextSize(0.05);
  
  gr548_cyclehist -> Draw("Ap");
  gr548_cyclecountmanual -> Draw("p");
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



  // ************************
  // TEMPERATURE AND COUNTS
  // ************************
 
  // ONLINE DATA FROM THE FOLLOWING LINK
  //https://docs.google.com/document/d/1IG8Yiy4DBPqcEO57lyALb7G1jq1tUQIsCV0pJxl_5CA/edit?usp=sharing

  double countsOnline[100] = {4100, 2400, 1860, 1500, 1250, 1000, 38950};
  double tempOnline[100] = {1.54, 1.63, 1.66, 1.69, 1.73, 1.76, 0.86};
  
  
  TCanvas *c_counttemp = new TCanvas ("c_counttemp" , " " , 1200, 900);
  c_counttemp -> SetLogy();


  TGraphErrors *gr548_HistIrrad = new TGraphErrors (counts_548, avets12IrradArray548, HistIntegralArray548, ts12IrradErr548, HistIntegralErrArray548);
  gr548_HistIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr548_HistIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr548_HistIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr548_HistIrrad -> SetMarkerStyle(25);
  gr548_HistIrrad -> GetYaxis() -> SetRangeUser(100,500000);
  gr548_HistIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr548_HistIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr548_HistIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_HistIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_HistIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr548_countmanualIrrad = new TGraphErrors (counts_548, avets12IrradArray548,UCNIntegralManualArray548, ts12IrradErr548, UCNIntegralManualErrArray548);
  gr548_countmanualIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr548_countmanualIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr548_countmanualIrrad -> GetYaxis()-> SetTitle("UCN Counts");
  gr548_countmanualIrrad -> SetMarkerStyle(24);
  gr548_countmanualIrrad -> GetYaxis() -> SetRangeUser(10,500000);
  gr548_countmanualIrrad -> GetXaxis()-> SetLimits(1.4, 1.8);
  gr548_countmanualIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr548_countmanualIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_countmanualIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_countmanualIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr548_countmanualIrrad -> SetMarkerColor(1);



   TGraphErrors *gr548_HistValveOpen = new TGraphErrors (counts_548, avets12ValveOpenArray548, HistIntegralArray548, ts12ValveOpenErr548, HistIntegralErrArray548);
  gr548_HistValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr548_HistValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr548_HistValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
  gr548_HistValveOpen -> SetMarkerStyle(25);
  gr548_HistValveOpen -> GetXaxis()-> SetLimits(0.84, 2.3);
  gr548_HistValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr548_HistValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr548_HistValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr548_HistValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  gr548_HistValveOpen -> SetMarkerColor(2);


  TGraphErrors *gr_online = new TGraphErrors (7, tempOnline, countsOnline, 0, 0);
  gr_online -> SetMarkerStyle(3);
  gr_online -> SetMarkerColor(8);

  TLegend *leg3 = new TLegend(0.25,0.7, 0.9, 0.9);

    leg3 -> AddEntry(gr548_countmanualIrrad , "Counts without background" , "p") ;
  //leg3 -> AddEntry(gr548_countValveOpen , "Valve open, without background" , "p") ;
  leg3 -> AddEntry(gr548_HistIrrad , "Counts with background" , "p") ;
  //leg3 -> AddEntry(gr548_HistValveOpen , "Valve open, with background" , "p") ;
  leg3 -> AddEntry(gr_online, "Online Analysis" , "p");
  leg3 -> SetTextSize(0.04);


  //gr548_countValveOpen -> Draw("p");
   gr548_HistIrrad -> Draw("Ap");
  //gr548_HistValveOpen -> Draw("p");
  gr_online -> Draw("p");
  gr548_countmanualIrrad -> Draw("p");
  leg3 -> Draw();
  
}
