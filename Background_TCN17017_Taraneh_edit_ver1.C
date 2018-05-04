//**************************************
// THIS SCRIPT IS FOR ANALYSIS OF THE
// Ni FOIL MEASUREMENT TCN17017
// Taraneh Andalib April 26, 2018
//**************************************

#define max 1000
void Background_TCN17017_Taraneh_edit_ver1(){
  gStyle -> SetOptStat(0);

  // *************************************************************************************
  // This is how I did this analysis: I started by only looking at the run794 which is the 
  // background measurement and I realized that I have to also compare the result with all
  // the other runs that are at 1muA beam current and 60 s irradiation time with 0 s cycle
  // delay time. So here first I load the data file for run 794 and later on I add the root
  // file that I created for all the other runs. At the end I graph all of the backgrounds
  // and this measurement together.
  // *************************************************************************************


  // THESE ARE ALL FOR THE RUN 794
  //********************************
  
  // LOADING THE DATA IN ...
  TFile *fin794 = new TFile ("./outputTree_794.root", "READ");

  // GETTING THE CYCLE INFORMATION TREE ...
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


  // INTEGRAL OF THE UCN RATE FROM HE3 DETECTOR
  double HistIntegralHe3794;
  double HistIntegralHe3Array794[100];
  double HistIntegralHe3ErrArray794[100];
  cycle_info794 -> SetBranchAddress ("HistIntegralHe3" , &HistIntegralHe3794);
  
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

  // BASELINE DURING IRRADIATION
  double baselineIrradrate794;
  cycle_info794 -> SetBranchAddress ("BASELINEIRRADRATE" , &baselineIrradrate794);
  double baselineIrradrateArray794[100];
  double baselineIrradrateErrArray794[100];
  
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
  double cycleValveCloseArray794[100];
  double baselinecountsArray794[100];
  double baselineArrayErr794[100];
  
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

  double HistIntegralAll[max]; // histogram integral for all runs
  double HistIntegralErrAll[max]; // histogram integral error for all runs
  double UCNCountsAll[max]; // UCN counts (without background) for all runs
  double UCNCountsErrAll[max]; // UCN counts error ( without background) for all runs
  double curAll[max]; // current for all runs 
  double curErrAll[max]; // current error for all runs
  double tempIrradAll[max]; // temparature during irradiation for all runs
  double tempIrradErrAll[max]; // temperature during irradiaiton error for all runs
  double tempVOAll[max]; // temperature during valve open for all runs
  double tempVOErrAll[max]; // temperature error during valve open for all runs
  double cycleNumArrayAll[max]; // the cycle number for all the runs
  double cycleDelayTimeArrayAll[max]; // cycle delay time for all the runs
  double cycleStartTimeAll[max];
  double baselineRateArrayAll[max];
  double baselineRateErrArrayAll[max];
  double baselineIrradRateArrayAll[max];
  double baselineIrradRateErrArrayAll[max];
  double Li6BgAll[max];
  double Li6BgErrAll[max];
  int counterAll;
  
  events794 = (Double_t) cycle_info794 -> GetEntries();

  for (ULong64_t j = 0 ; j < events794 ; j++ ){
    cycle_info794 -> GetEvent(j);
    if (j == 11 || j == 19 || j > 24)
      continue;
    irradStartTimeArray794[counter794] = irradStartTime794;
    cycleStartTimeArray794[counter794] = cycleStartTime794;
    cycleValveOpenArray794[counter794] = cycleValveOpen794;
    cycleValveCloseArray794[counter794] = cycleValveClose794;
    HistIntegralArray794[counter794] = HistIntegral794;
    HistIntegralHe3Array794[counter794] = HistIntegralHe3794;
    HistIntegralErrArray794[counter794] = sqrt(HistIntegral794);
    HistIntegralHe3ErrArray794[counter794] = sqrt(HistIntegralHe3794);
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
    baselineArrayErr794[counter794] = sqrt(baselinecountsArray794[counter794]);
    UCNCounts794[counter794] = HistIntegralArray794[counter794] - baselinecountsArray794[counter794];
    UCNCountsErr794[counter794] = sqrt(UCNCounts794[counter794]);
    avecurArray794[counter794] = avecur794;
    curErrArray794[counter794] = (maxcur794 - mincur794)/2;
    // %%%%%%%%%%%%%%%%%%%%%%%
    HistIntegralAll[counter794] = HistIntegral794;
    HistIntegralErrAll[counter794] =  sqrt(HistIntegral794);
    //UCNCountsAll[counter794] = HistIntegralArray794[counter794] - baselinecountsArray794[counter794];
    //UCNCountsErrAll[counter794] = sqrt(UCNCounts794[counter794]);
    curAll[counter794] = avecur794;
    curErrAll[counter794] = (maxcur794 - mincur794)/2;
    tempIrradAll[counter794] = avets12Irrad794;
    tempIrradErrAll[counter794] = (maxts12Irrad794 - mints12Irrad794)/2;
    tempVOAll[counter794] = avets12ValveOpen794;
    tempVOErrAll[counter794] = (maxts12ValveOpen794 - mints12ValveOpen794)/2;
    cycleNumArrayAll[counter794] = cyclenum794;
    cycleDelayTimeArrayAll[counter794] = cycleDelayTime794;
    cycleStartTimeAll[counter794] = cycleStartTime794;
    Li6BgAll[counter794] = HistIntegral794;
    Li6BgErrAll[counter794] = sqrt(HistIntegral794);
    baselineRateArrayAll[counter794] = baselinerate794;
    baselineRateErrArrayAll[counter794] = sqrt(baselinerate794);
    baselineIrradRateArrayAll[counter794] = baselineIrradrate794;
    baselineIrradRateErrArrayAll[counter794] = sqrt (baselineIrradrate794);
    // cout << std::fixed <<cycleStartTimeAll[counter794] << endl;
    counterAll= counter794;
    counter794++;
  }

  // ********************************************************************************
  // I WANT TO COMPARE THE RESULT OF WHAT I GET WITH THE BACKGROUND IN OTHER SIMILAR
  // MEASUREMENTS. SO THE FOLLOWING RUN ARE ALSO AT 1 MUA BEAM CURRENT, 60 S IRRADIATION
  // TIME AND 0 S CYCLE DELAY TIME: 532, 541, 553, 573, 595, 605
  // I CAN LOOK AT THE BACKGROUND DURING THOSE RUNS AND COMPARE IT WITH THIS MEASUREMENT
  // *********************************************************************************
  
  // I WILL USE THE OVERALL FILE THAT I CREATED AND THEN IF THERE WAS A PROBLEM I WILL LOOK AT INDIVIDUAL FILES
  TFile *finAll = new TFile ("./outputTree_1muA_60sIrrad.root", "READ");

  TTree *cycle_infoAll = (TTree*) finAll -> Get("cycle_info");

  double cycleStartTime;
  cycle_infoAll -> SetBranchAddress ("cycleStartTimes" , &cycleStartTime);
  double cycleStartTimeArray[max];
  double HistIntegral;
  cycle_infoAll -> SetBranchAddress ("HistIntegral" , &HistIntegral);
  double HistIntegralArray[max];
  double HistIntegralErrArray[max];
  double HistIntegralHe3;
  cycle_infoAll -> SetBranchAddress ("HistIntegralHe3" , &HistIntegralHe3);
  double HistIntegralHe3Array[max];
  double HistIntegralHe3ErrArray[max];
  double avets12Irrad;
  cycle_infoAll -> SetBranchAddress ("AVE_TS12_IRRAD", &avets12Irrad);
  double avetempIrradArray[max];
  double maxts12Irrad;
  cycle_infoAll -> SetBranchAddress ("MAX_TS12_IRRAD", &maxts12Irrad);
  double maxtempIrradArray[max];
  double mints12Irrad;
  cycle_infoAll -> SetBranchAddress ("MIN_TS12_IRRAD", &mints12Irrad);
  double mintempIrradArray[max];
  double avets12ValveOpen;
  cycle_infoAll -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen);
  double avetempVOArray[max];
  double maxts12ValveOpen;
  cycle_infoAll -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen);
  double maxtempVOArray[max];
  double mints12ValveOpen;
  cycle_infoAll -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen);
  double mintempVOArray[max];
  int cyclenum;
  cycle_infoAll -> SetBranchAddress ("cycleNumberAll" , &cyclenum);
  double cycleNumArray[max];
  double cycleDelayTime;
  cycle_infoAll -> SetBranchAddress ("cycleDelayTime", &cycleDelayTime);
  double cycleDelayTimeArray[max];
  double baselinerate;
  cycle_infoAll -> SetBranchAddress ("BASELINERATE" , &baselinerate);
  double baselineArray[max];
  double baselineErrArray[max];
  double baselineIrradrate;
  cycle_infoAll -> SetBranchAddress ("BASELINEIRRADRATE" , &baselineIrradrate);
  double avecur;
  cycle_infoAll -> SetBranchAddress ("AVE_PRDCUR" , &avecur);
  double avecurArray[max];
  double maxcur;
  cycle_infoAll -> SetBranchAddress ("MAX_PRDCUR" , &maxcur);
  double mincur;
  cycle_infoAll -> SetBranchAddress ("MIN_PRDCUR" , &mincur);
  double curErrArray[max];
  double cycleValveOpen;
  cycle_infoAll -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpen);
  double cycleValveOpenArray[max];
  double cycleValveClose;
  cycle_infoAll -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveClose);
  double cycleValveCloseArray[max];

	  
  int counter = 0;
  double UCNCounts [max];
  double UCNCountsErr[max];
  double tempIrradErrArray[max];
  double tempVOErrArray[max];
  double curErrArray[max];
  ULong64_t events;

  events = (Double_t) cycle_infoAll -> GetEntries();

  for (ULong64_t j = 0 ; j < events ; j++ ){
    cycle_infoAll -> GetEvent(j);
    if (cycleDelayTime > 0)
      continue; // because I only care about cycle delay time of 0
    cycleDelayTimeArray[counter] = cycleDelayTime;
    cycleStartTimeArray[counter] = cycleStartTime;
    HistIntegralArray[counter] = HistIntegral;
    HistIntegralHe3Array[counter] = HistIntegralHe3;
    HistIntegralErrArray[counter] = sqrt(HistIntegral);
    HistIntegralHe3ErrArray[counter] = sqrt(HistIntegralHe3);
    avetempIrradArray[counter] = avets12Irrad;
    maxtempIrradArray[counter] = maxts12Irrad;
    mintempIrradArray[counter] = mints12Irrad;
    tempIrradErrArray[counter] = (maxts12Irrad - mints12Irrad)/2;
    avetempVOArray[counter] = avets12ValveOpen;
    maxtempVOArray[counter] = maxts12ValveOpen;
    mintempVOArray[counter] = mints12ValveOpen;
    tempVOErrArray[counter] = (maxts12ValveOpen - mints12ValveOpen)/2;
    cycleNumArray[counter] = cyclenum;
    baselineArray[counter] = baselinerate*(cycleValveClose - cycleValveOpen);
    baselineErrArray[counter] = sqrt(baselineArray[counter]);
    UCNCounts[counter] = HistIntegralArray[counter] - baselineArray[counter];
    //cout << UCNCounts[counter] << endl;
    UCNCountsErr[counter] = sqrt(UCNCounts[counter]);
    avecurArray[counter] = avecur;
    curErrArray[counter] = (maxcur - mincur)/2;
    // %%%%%%%%%%%%%%%%%%%%%%%
    HistIntegralAll[counter+counter794] = HistIntegral;
    HistIntegralErrAll[counter+counter794] =  sqrt(HistIntegral);
    //UCNCountsAll[counter] = HistIntegralArray[counter] - baselinecountsArray[counter];
    //UCNCountsErrAll[counter] = sqrt(UCNCounts[counter]);
    curAll[counter+counter794] = avecur;
    curErrAll[counter+counter794] = (maxcur - mincur)/2;
    tempIrradAll[counter+counter794] = avets12Irrad;
    tempIrradErrAll[counter+counter794] = (maxts12Irrad - mints12Irrad)/2;
    tempVOAll[counter+counter794] = avets12ValveOpen;
    tempVOErrAll[counter+counter794] = (maxts12ValveOpen - mints12ValveOpen)/2;
    cycleNumArrayAll[counter+counter794] = cyclenum;
    cycleDelayTimeArrayAll[counter+counter794] = cycleDelayTime;
    cycleStartTimeAll[counter+counter794] = cycleStartTime;
    Li6BgAll[counter+counter794] = baselineArray[counter];
    Li6BgErrAll[counter+counter794] = sqrt(baselineArray[counter]);
    baselineRateArrayAll[counter + counter794] = baselinerate;
    baselineRateErrArrayAll[counter + counter794] = sqrt(baselinerate);
    baselineIrradRateArrayAll[counter + counter794] = baselineIrradrate;
    baselineIrradRateErrArrayAll[counter + counter794] = sqrt (baselineIrradrate);
    // cout << std::fixed <<cycleStartTimeAll[counter] << endl;
    counterAll= counter;
    counter++;
  }		



  

  // ***************************
  // GRAPHS
  // **************************

  //***********
  // 794
  //**********
  
  TCanvas *c794_cylceNum =  new TCanvas("c794_cycleNum" , "c794_cycleNum " , 1200, 900);
  c794_cycleNum-> Divide(2,2);

  TPad *p794_1 = c794_cycleNum->cd(1);
  //p794_1->SetLogy(); 
  
  TGraphErrors *gr794_cyclehist = new TGraphErrors(counter794, cycleNumArray794 , HistIntegralArray794, 0, HistIntegralErrArray794);
  
  gr794_cyclehist -> SetTitle("UCN Counts vs Cycle Number");
  gr794_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr794_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr794_cyclehist -> GetYaxis()-> SetRangeUser(10, 700);
  gr794_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr794_cyclehist -> SetMarkerColor(2);
  gr794_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr794_cyclecountBB = new TGraphErrors(counter794, cycleNumArray794 , HistIntegralHe3Array794, 0, HistIntegralHe3ErrArray794);
  
  gr794_cyclecountBB -> SetTitle("UCN Counts vs Number");
  gr794_cyclecountBB -> GetXaxis()-> SetTitle("Cycle Number" );
  gr794_cyclecountBB -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr794_cyclecountBB -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr794_cyclecountBB -> GetXaxis() -> SetTitleSize(0.05);
  gr794_cyclecountBB -> GetXaxis() -> SetTitleOffset(1.0);
  gr794_cyclecountBB -> GetYaxis() -> SetTitleSize(0.05); 
  gr794_cyclecountBB -> GetYaxis() -> SetTitleOffset(0.9);
  gr794_cyclecountBB -> SetMarkerColor(1);
  gr794_cyclecountBB -> SetMarkerStyle(25);
  
  TLegend *leg2 = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr794_cyclehist, "Li6 Counts" , "p");
  leg2 -> AddEntry(gr794_cyclecountBB, "He3 Counts" , "p");
  
  gr794_cyclehist -> Draw("Ap");
  gr794_cyclecountBB -> Draw("p");
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

  // ****************************************************
  // FOR ALL THE OTHER 1MUA , 60 S IRRADIAITON TIME RUNS
  // ****************************************************

   TCanvas *c_cylceNum =  new TCanvas("c_cycleNum" , "c_cycleNum " , 1200, 900);
  c_cycleNum-> Divide(2,2);

  TPad *p_1 = c_cycleNum->cd(1);
  //p_1->SetLogy(); 
  
  TGraphErrors *gr_cyclehist = new TGraphErrors(counter, cycleNumArray , baselineArray, 0, baselineErrArray);
  
  gr_cyclehist -> SetTitle("Background vs Cycle Number");
  gr_cyclehist -> GetXaxis()-> SetTitle("Cycle Number" );
  gr_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  //gr_cyclehist -> GetYaxis()-> SetRangeUser(10, 700);
  gr_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr_cyclehist -> SetMarkerColor(2);
  gr_cyclehist -> SetMarkerStyle(20);

  TGraphErrors *gr_cyclecountBB = new TGraphErrors(counter, cycleNumArray , HistIntegralHe3Array, 0, HistIntegralHe3ErrArray);
  
  gr_cyclecountBB -> SetTitle("UCN Counts vs Number");
  gr_cyclecountBB -> GetXaxis()-> SetTitle("Cycle Number" );
  gr_cyclecountBB -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr_cyclecountBB -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr_cyclecountBB -> GetXaxis() -> SetTitleSize(0.05);
  gr_cyclecountBB -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cyclecountBB -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cyclecountBB -> GetYaxis() -> SetTitleOffset(0.9);
  gr_cyclecountBB -> SetMarkerColor(1);
  gr_cyclecountBB -> SetMarkerStyle(25);
  
  TLegend *leg2 = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr_cyclehist, "Li6 Counts" , "p");
  leg2 -> AddEntry(gr_cyclecountBB, "He3 Counts" , "p");
  
  gr_cyclehist -> Draw("Ap");
  // gr_cyclecountBB -> Draw("p");
  //leg2-> Draw();
  
  c_cycleNum -> cd(2);
  TGraphErrors *gr_cycledelay = new TGraphErrors (counter , cycleNumArray, cycleDelayTimeArray, 0 , 0);
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
  TGraphErrors *gr_cycletempIrrad = new TGraphErrors (counter , cycleNumArray, avetempIrradArray, 0 , tempIrradErrArray);
  
  gr_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr_cycletempIrrad -> SetMarkerStyle(20);
  gr_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  gr_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  
  TGraphErrors *gr_cycletempValveOpen = new TGraphErrors (counter , cycleNumArray, avetempVOArray, 0 , tempVOErrArray);
  
  gr_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr_cycletempValveOpen -> SetMarkerStyle(20);
  gr_cycletempValveOpen -> SetMarkerColor(2);
  gr_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  TLegend *leg = new TLegend (0.7 , 0.7 , 0.9, 0.9);
  leg -> AddEntry(gr_cycletempIrrad, "During Irradiation" , "p");
  leg -> AddEntry(gr_cycletempValveOpen, "During Valve Open" , "p");
  
  gr_cycletempIrrad -> Draw("AP");
  gr_cycletempValveOpen -> Draw("p");
  leg -> Draw();
  
  c_cycleNum -> cd(4);
  TGraphErrors *gr_cyclecur = new TGraphErrors (counter , cycleNumArray , avecurArray, 0, curErrArray );
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


  // ************************************************************
  // overall result in time
  // ************************************************************


  TCanvas *cAll_cylceNum =  new TCanvas("cAll_cycleNum" , "cAll_cycleNum " , 1200, 900);
  cAll_cycleNum-> Divide(2,2);

  TPad *pAll_1 = cAll_cycleNum->cd(1);
  //pAll_1->SetLogy(); 


  TGraphErrors *grAll_baselineIrrad = new TGraphErrors(counterAll, cycleStartTimeAll , baselineIrradRateArrayAll, 0, baselineIrradRateErrArrayAll);
  
  grAll_baselineIrrad -> SetTitle("Li6 Background Rate vs Cycle Start Time");
  //grAll_baselineIrrad -> GetXaxis()-> SetTitle("Cycle Start Time " );
  grAll_baselineIrrad -> GetYaxis()-> SetTitle("Cycle UCN Counts/s");
  //grAll_baselineIrrad -> GetYaxis()-> SetRangeUser(10, 500000);
  grAll_baselineIrrad -> GetXaxis() -> SetTimeDisplay(1);
  // grAll_baselineIrrad -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_baselineIrrad -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_baselineIrrad -> GetXaxis() -> SetNdivisions(20);
  grAll_baselineIrrad -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_baselineIrrad -> GetXaxis() -> SetTitleSize(0.05);
  grAll_baselineIrrad -> GetXaxis() -> SetLabelOffset(.03);
  grAll_baselineIrrad -> GetXaxis() -> SetLabelSize(.04);
  grAll_baselineIrrad -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_baselineIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_baselineIrrad -> GetYaxis() -> SetTitleOffset(1.3);
  grAll_baselineIrrad -> SetMarkerColor(1);
  grAll_baselineIrrad -> SetMarkerStyle(20);
  



  
  TGraphErrors *grAll_cyclehist = new TGraphErrors(counterAll, cycleStartTimeAll , baselineRateArrayAll, 0, baselineRateErrArrayAll);
  
  grAll_cyclehist -> SetTitle("Li6 Background Rate vs Cycle Start Time");
  //grAll_cyclehist -> GetXaxis()-> SetTitle("Cycle Start Time " );
  grAll_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts/s");
  //grAll_cyclehist -> GetYaxis()-> SetRangeUser(10, 500000);
  grAll_cyclehist -> GetXaxis() -> SetTimeDisplay(1);
  // grAll_cyclehist -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cyclehist -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_cyclehist -> GetXaxis() -> SetNdivisions(20);
  grAll_cyclehist -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cyclehist -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cyclehist -> GetXaxis() -> SetLabelSize(.04);
  grAll_cyclehist -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cyclehist -> GetYaxis() -> SetTitleOffset(1.3);
  grAll_cyclehist -> SetMarkerColor(2);
  grAll_cyclehist -> SetMarkerStyle(20);

  TLegend *leg_BR = new TLegend (0.7 , 0.7, 0.9, 0.9);
  leg_BR -> AddEntry(grAll_baselineIrrad, "Backround RateDuring Irradiation" , "p");
  leg_BR -> AddEntry(grAll_cyclehist, "Background Rate Before Irradiation" , "P");

  grAll_baselineIrrad -> Draw("Ap");
  grAll_cyclehist -> Draw("p");
  leg_BR -> Draw();

  
  cAll_cycleNum -> cd(2);
  TGraphErrors *grAll_cycledelay = new TGraphErrors (counterAll , cycleStartTimeAll, cycleDelayTimeArrayAll, 0 , 0);
  grAll_cycledelay -> SetTitle("Delay Time vs Cycle Start Time");
  //grAll_cycledelay -> GetXaxis()-> SetTitle("Cycle Start Time" );
  grAll_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll_cycledelay -> GetXaxis() -> SetTimeDisplay(1);
  //grAll_cycledelay -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycledelay -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_cycledelay -> GetXaxis() -> SetNdivisions(20);
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
  //grAll_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Start Time");
  grAll_cycletempIrrad -> SetMarkerStyle(20);
  grAll_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 0.9);
  grAll_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeDisplay(1);
  //grAll_cycletempIrrad -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_cycletempIrrad -> GetXaxis() -> SetNdivisions(20);
  grAll_cycletempIrrad -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cycletempIrrad -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cycletempIrrad -> GetXaxis() -> SetLabelSize(.04);
  
  TGraphErrors *grAll_cycletempValveOpen = new TGraphErrors (counterAll , cycleStartTimeAll, tempVOAll, 0 , tempVOErrAll);
  
  grAll_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Start Time");
  grAll_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  //grAll_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Start Time");
  grAll_cycletempValveOpen -> SetMarkerStyle(20);
  grAll_cycletempValveOpen -> SetMarkerColor(2);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cycletempValveOpen -> GetXaxis() -> SetTimeDisplay(1);
  //grAll_cycletempValveOpen -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cycletempValveOpen -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_cycletempValveOpen -> GetXaxis() -> SetNdivisions(20);
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
  //grAll_cyclecur -> GetXaxis()-> SetTitle("Cycle Start Time");
  //grAll_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  grAll_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  grAll_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  grAll_cyclecur -> GetXaxis() -> SetTitleOffset(1.3);
  grAll_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  grAll_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);
  grAll_cyclecur -> GetXaxis() -> SetTimeDisplay(1);
  //grAll_cyclecur -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grAll_cyclecur -> GetXaxis() -> SetTimeFormat(" #splitline{%d}{%b}");
  grAll_cyclecur -> GetXaxis() -> SetNdivisions(20);
  grAll_cyclecur -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grAll_cyclecur -> GetXaxis() -> SetLabelOffset(.03);
  grAll_cyclecur -> GetXaxis() -> SetLabelSize(.04);
  
  grAll_cyclecur -> SetMarkerStyle(20);
  grAll_cyclecur -> Draw("Ap");
  cAll_cycleNum -> Update();

  // ***********************************************************
  // Now I like to look at the UCN rate from the raw data file
  // and add when the valve opened and closed and irradiation
  // happened

  TFile *finraw794 = new TFile("~/raw_Data/ucn_tree_00000794.root");
  TTree *uinLi6 = (TTree*) finraw794 -> Get("UCNHits_Li-6");
  TTree *uinHe3 = (TTree*) finraw794 -> Get("UCNHits_He3");
  TTree *runtransLi6 = (TTree*) finraw794 -> Get("RunTransitions_Li6");
  TTree *runtransHe3 = (TTree*) finraw794 -> Get("RunTransitions_He3");
  TTree *BL = (TTree*) finraw794 -> Get("BeamlineEpicsTree");

  Double_t maxXrange = 0, minXrange=1540000000.;
  Int_t BinWidth=1;
  Int_t NBins = 1;
   
  double tUnixTimePrecise_Li6, tUnixTime_Li6;
  double tUnixTimePrecise_He3, tUnixTime_He3;
  UShort_t tIsUCN_Li6;
  UShort_t tIsUCN_He3;
  int timestamp_beamline;

  uinLi6 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise_Li6);
  uinLi6 -> SetBranchAddress ("tUnixTime" , &tUnixTime_Li6);
  uinLi6 -> SetBranchAddress ("tIsUCN" , &tIsUCN_Li6);
  uinHe3 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise_He3);
  uinHe3 -> SetBranchAddress ("tUnixTime",&tUnixTime_He3);
  uinHe3 -> SetBranchAddress ("tIsUCN" , &tIsUCN_He3);
  BL -> SetBranchAddress("timestamp" , &timestamp_beamline);
  

  TH1* UCNRate_Li6= new TH1F("UCN_rate_Li6", "UCN Rate Histogram Li6",NBins , minXrange, maxXrange);
  UCNRate_Li6 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate_Li6 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate_Li6 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate_Li6 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate_Li6 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate_Li6 -> GetXaxis() -> SetLabelSize(.04);
  TH1* UCNRate_He3= new TH1F("UCN_rate_He3", "UCN Rate Histogram He3", NBins , minXrange, maxXrange);
  UCNRate_He3 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate_He3 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate_He3 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate_He3 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate_He3 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate_He3 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate_He3 -> GetXaxis() -> SetLabelSize(.04);
  
  ULong64_t beamlineEvent = (Double_t) BL -> GetEntries();

  for(ULong64_t j=0 ; j < beamlineEvent ;j++) {
    BeamlineEpicsTree -> GetEvent(j);
    //cout << timestamp_beamline << endl;
    if (timestamp_beamline < minXrange ){
      minXrange = timestamp_beamline;
    }
    if (timestamp_beamline > maxXrange)
      {
	maxXrange = timestamp_beamline;
      }
  }
  
  NBins = (maxXrange - minXrange)/BinWidth ; 
  UCNRate_Li6 -> SetBins(NBins, minXrange , maxXrange);
  UCNRate_He3 -> SetBins(NBins, minXrange , maxXrange);
    
  ULong64_t eventsLi6 = (Double_t) uinLi6 -> GetEntries();
  ULong64_t eventsHe3 = (Double_t) uinHe3 -> GetEntries();

  for (ULong64_t j = 0 ; j < eventsLi6 ; j++){
    uinLi6 -> GetEvent(j);
    //cout << tUnixTime_Li6 << endl;
    if (tIsUCN_Li6 >0 && tUnixTimePrecise_Li6 >20e6){
      UCNRate_Li6-> Fill (tUnixTimePrecise_Li6);
    }
  }
  
  for (ULong64_t j = 0 ; j < eventsHe3; j++){
    uinHe3 -> GetEvent(j);
    if (tIsUCN_He3 >0 && tUnixTime_He3 >20e6){
      UCNRate_He3-> Fill (tUnixTime_He3);
    }
  }

  
  Float_t He3MaxRate = UCNRate_He3 -> GetMaximum();
  Float_t Li6MaxRate = UCNRate_Li6 -> GetMaximum();
  

  
  TCanvas *He3rate = new TCanvas("He3rate" , "He3rate" , 1200, 900);
  UCNRate_He3 -> Draw();
  
  TLine *lineHe3;
  TLine *line2He3;


  TLegend *legline = new TLegend (0.7, 0.7, 0.9, 0.9);
  legline -> AddEntry (lineHe3 , "Valve Open Time" , "l");
  legline -> AddEntry (line2He3 , "Irradiation Start Time" , "l");
  
  
  for (int k = 0 ; k < counter794; k++){
    lineHe3 = new TLine(cycleValveOpenArray794[k],0, cycleValveOpenArray794[k] , He3MaxRate);
    
    lineHe3->SetLineColor(kRed);
    lineHe3 -> SetLineWidth(3);
    line2He3 = new TLine(irradStartTimeArray794[k],0, irradStartTimeArray794[k] , He3MaxRate);
    
    line2He3->SetLineColor(8);
    line2He3 -> SetLineWidth(3);
    lineHe3->Draw();
    line2He3 -> Draw();
  }
  //legline -> Draw();
  TCanvas *Li6rate = new TCanvas("Li6rate" , "Li6rate" , 1200 , 900);
  UCNRate_Li6 -> Draw();
  
  TLine *lineLi6;
  TLine *line2Li6;
  for (int k = 0 ; k < counter794; k++){
    lineLi6 = new TLine(cycleValveOpenArray794[k],0, cycleValveOpenArray794[k] , Li6MaxRate);
    lineLi6->SetLineColor(kRed);
    lineLi6 -> SetLineWidth(3);
    line2Li6 = new TLine(irradStartTimeArray794[k],0, irradStartTimeArray794[k] , Li6MaxRate);
    
    line2Li6->SetLineColor(8);
    line2Li6 -> SetLineWidth(3);
    lineLi6 -> Draw();
    line2Li6 -> Draw();
  }
  //legline -> Draw();


  
}
