//**************************************
// THIS SCRIPT IS FOR ANALYSIS OF THE
// Ni FOIL MEASUREMENT TCN17017
// Taraneh Andalib April 26, 2018
//**************************************


void Background_TCN17017_Taraneh_edit_ver1(){
  
  // LOADING THE DATA IN ...
  TFile *fin794 = new TFile ("./outputTree_794.root", "READ");

  // GETTING THE CYCLE INFORMATION TREE ..
  TTree *cycle_info794 = (TTree*) fin794 -> Get("cycle_info");

  // IRRADIATION TIME
  double irradStartTime794; // irradiation start time for run 794
  double irradStartTimeArray794[100]; // irradiation start time array for run 794
  cycle_info794 -> SetBranchAddress("irradStartTimes", &irradStartTime794);

  // CYCLE START TIME
  double cycleStartTime794; // cycle start time for run 794
  double cycleStartTimeArray794[100]; // cycle start time array for run 794
  cycle_info794 -> SetBranchAddress("cycleStartTimes" , &cycleStartTime794);


  // INTEGRAL OF THE UCN RATE
  double HistIntegral794; // histogram integral for run 794
  double HistIntegralArray794[100]; // histogram integral array for run 794
  double HistIntegralErrArray794[100]; // histogram integral error array for run 794
  cycle_info794 -> SetBranchAddress("HistIntegral" , &HistIntegral794);
  
  // ISOPURE TEMPERATURE AVERAGE DURING IRRADIAITON
  double avets12Irrad794; // average ts12 temparature during irradiation for run 794
  double avetempIrradArray794[100]; // average ts12 temperature array during irradiation for run 794
  cycle_info794 -> SetBranchAddress("AVE_TS12_IRRAD" , &avets12Irrad794);
  
  // MAX ISOPURE TEMPERATURE DURING IRRADIATION
  double maxts12Irrad794; // max ts12 temperature during irradiation for run 794
  double maxtempIrradArray794[100]; // max ts12 temperature array during irradiation for run 794
  cycle_info794 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad794);
  
  // MINIMUM ISOPURE TEMPERATURE DURING IRRADIATION
  double mints12Irrad794; // min ts12 temperature during irradiation for run 794
  double mintempIrradArray794[100]; // min ts12 temperature array during irradiation for run 794
  cycle_info794 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad794);
  
  // AVERAGE ISOPURE TEMPERATURE DURING VALVE OPEN
  double avets12ValveOpen794; // average ts12 temperature during valve open for run 794
  double avetempVOArray794[100]; // average ts12 temperature array during valve open for run 794
  cycle_info794 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen794);

  // MAXIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double maxts12ValveOpen794; // max ts12 temperature during valve open for run 794
    double maxtempVOArray794[100]; // max ts12 temperature array during valve open for run 794
  cycle_info794 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen794);
 
  // MINIMUM ISOPURE TEMPERATURE DURING VALVE OPEN
  double mints12ValveOpen794; // min ts12 temperature during valve open for run 794
   double mintempVOArray794[100]; // min ts12 temperature array during valve open for run 794
   cycle_info794 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen794);

  // CYCLE NUMBER
  int cyclenum794; // cycle number for run 794
  double cycleNumArray794[100]; // cycle number arrat for run 794
  cycle_info794 -> SetBranchAddress ("cycleNumber" , &cyclenum794);

  // CYCLE DELAY TIME
  double cycleDelayTime794;
  double cycleDelayTimeArray794[100];
  cycle_info794 -> SetBranchAddress ("cycleDelayTime" , cycleDelayTime794);

  // BASELINE INTEGRAL BEFORE IRRADIATION
  double baselinerate794;
  cycle_info794 -> SetBranchAddress ("BASELINERATE" , &baselinerate794);


  // AVERAGE PREDICTED CURRENT
  double avecur794;
  double avecurArray794[100];
  cycle_info794 -> SetBranchAddress ("AVE_PRDCUR" , &avecur794);


  // MAXIMUM PREDICTED CURRENT
  double maxcur794;
  double maxcurArray794[100];
  cycle_info794 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur794);

  // MINIMUM PREDICTED CURRENT
  double mincur794;
  double mincurArray794[100];
  cycle_info794 -> SetBranchAddress ("MIN_PRDCUR" , &mincur794);


  // CYCLE VALVE OPEN TIME
  double cycleValveOpen794;
  cycle_info794 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpen794);
  double cycleValveOpenArray794[100];

  // CYCLE VALVE CLOSE TIME
  double cycleValveClose794;
  cycle_info794 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveClose794);
  double baselinecountsArray794[100];

  
  // READING FROM THE TREE , FILLING THE ARRAYS
  // *************
  // 794
  //**************
 
  
  int counter794 = 0;
  double UCNCounts794 [100];
  double UCNCountsErr794[100];
  double tempIrradErrArray794[100];
  double tempVOErrArray794[100];
  double curErrArray794[100];
  ULong64_t events794;

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
  
  events794 = (Double_t) cycle_info794 -> GetEntries();

  for (ULong64_t j = 0 ; j < events794 ; j++ ){
    cycle_info794 -> GetEvent(j);
    if (j == 11 || j == 19 || j > 24)
      continue;
    irradStartTimeArray794[counter794] = irradStartTime794;
    cycleStartTimeArray794[counter794] = cycleStartTime794;
    HistIntegralArray794[counter794] = HistIntegral794;
    HistIntegralErrArray794[counter794] = sqrt(HistIntegral794);
    avetempIrradArray794[counter794] = avets12Irrad794;
    maxtempIrradArray794[counter794] = maxts12Irrad794;
    mintempIrradArray794[counter794] = mints12Irrad794;
    tempIrradErrArray794[counter794] = (maxts12Irrad794 - mints12Irrad794)/2;
    avetempVOArray794[counter794] = avets12ValveOpen794;
    maxtempVOArray794[counter794] = maxts12ValveOpen794;
    mintempVOArray794[counter794] = mints12ValveOpen794;
    tempVOErrArray794[counter794] = (maxts12ValveOpen794 - mints12ValveOpen794)/2;
    cycleNumArray794[counter794] = cyclenum794;
    cycleDelayTimeArray794[counter794] = cycleDelayTime794;
    baselinecountsArray794[counter794] = baselinerate794*(cycleValveClose794 - cycleValveOpen794);
    UCNCounts794[counter794] = HistIntegralArray794[counter794] - baselinecountsArray794[counter794];
    UCNCountsErr794[counter794] = sqrt(UCNCounts794[counter794]);
    avecurArray794[counter794] = avecur794;
    curErrArray794[counter794] = (maxcur794 - mincur794)/2;
    // %%%%%%%%%%%%%%%%%%%%%%%
    HistIntegralAll[counter794] = HistIntegral794;
    HistIntegralErrAll[counter794] =  sqrt(HistIntegral794);
    UCNCountsAll[counter794] = HistIntegralArray794[counter794] - baselinecountsArray794[counter794];
    UCNCountsErrAll[counter794] = sqrt(UCNCounts794[counter794]);
    curAll[counter794] = avecur794;
    curErrAll[counter794] = (maxcur794 - mincur794)/2;
    tempIrradAll[counter794] = avets12Irrad794;
    tempIrradErrAll[counter794] = (maxts12Irrad794 - mints12Irrad794)/2;
    tempVOAll[counter794] = avets12ValveOpen794;
    tempVOErrAll[counter794] = (maxts12ValveOpen794 - mints12ValveOpen794)/2;
    cycleNumArrayAll[counter794] = cyclenum794;
    cycleDelayTimeArrayAll[counter794] = cycleDelayTime794;
    cycleStartTimeAll[counter794] = cycleStartTime794;
    cout << std::fixed <<cycleStartTimeAll[counter794] << endl;
    counterAll= counter794;
    counter794++;
  }

  // ***************************
  // GRAPHS
  // **************************

  TCanvas *c794_cylceNum =  new TCanvas("c794_cycleNum" , "c794_cycleNum " , 1200, 900);
  c794_cycleNum-> Divide(2,2);

  TPad *p794_1 = c794_cycleNum->cd(1);
  //p794_1->SetLogy(); 
  
  TGraphErrors *gr794_cyclehist = new TGraphErrors(counter794, cycleNumArray794 , HistIntegralArray794, 0, HistIntegralErrArray794);
  
  gr794_cyclehist -> SetTitle("UCN Counts vs Cycle Number");
  gr794_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr794_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr794_cyclehist -> GetYaxis()-> SetRangeUser(10, 100000);
  gr794_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr794_cyclehist -> SetMarkerColor(2);
  gr794_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr794_cyclecountmanual = new TGraphErrors(counter794, cycleNumArray794 , UCNCounts794, 0, UCNCountsErr794);
  
  gr794_cyclecountmanual -> SetTitle("UCN Counts vs Number");
  gr794_cyclecountmanual -> GetXaxis()-> SetTitle("Cycle Number" );
  gr794_cyclecountmanual -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr794_cyclecountmanual -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr794_cyclecountmanual -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cyclecountmanual -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cyclecountmanual -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cyclecountmanual -> GetYaxis() -> SetTitleOffset(0.9);
  gr794_cyclecountmanual -> SetMarkerColor(1);
  gr794_cyclecountmanual -> SetMarkerStyle(25);
  
  TLegend *leg2 = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr794_cyclehist, "With Background" , "p");
  leg2 -> AddEntry(gr794_cyclecountmanual, "Without Background" , "p");
  
  gr794_cyclehist -> Draw("Ap");
  gr794_cyclecountmanual -> Draw("p");
  leg2-> Draw();
  
  c794_cycleNum -> cd(2);
  TGraphErrors *gr794_cycledelay = new TGraphErrors (counter794 , cycleNumArray794, cycleDelayTimeArray794, 0 , 0);
  gr794_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr794_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr794_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr794_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr794_cycledelay -> SetMarkerStyle(20);
  gr794_cycledelay -> Draw("Ap");
  
  
  c794_cycleNum -> cd(3);
  TGraphErrors *gr794_cycletempIrrad = new TGraphErrors (counter794 , cycleNumArray794, avetempIrradArray794, 0 , tempIrradErrArray794);
  
  gr794_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr794_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr794_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr794_cycletempIrrad -> SetMarkerStyle(20);
  gr794_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  gr794_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr794_cycletempValveOpen = new TGraphErrors (counter794 , cycleNumArray794, avetempVOArray794, 0 , tempVOErrArray794);
  
  gr794_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr794_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr794_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr794_cycletempValveOpen -> SetMarkerStyle(20);
  gr794_cycletempValveOpen -> SetMarkerColor(2);
  gr794_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  TLegend *leg = new TLegend (0.7 , 0.7 , 0.9, 0.9);
  leg -> AddEntry(gr794_cycletempIrrad, "During Irradiation" , "p");
  leg -> AddEntry(gr794_cycletempValveOpen, "During Valve Open" , "p");
  
  gr794_cycletempIrrad -> Draw("AP");
  gr794_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c794_cycleNum -> cd(4);
  TGraphErrors *gr794_cyclecur = new TGraphErrors (counter794 , cycleNumArray794 , avecurArray794, 0, curErrArray794 );
  gr794_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr794_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr794_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr794_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr794_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr794_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr794_cyclecur -> SetMarkerStyle(20);
  gr794_cyclecur -> Draw("Ap");
  c794_cycleNum -> Update();


  

}
