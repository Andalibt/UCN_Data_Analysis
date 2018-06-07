// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17007.
// UCN COUNTS VS IRRADIATION TIME
// 2nd pass of analysis
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17007_Taraneh_edit_ver3(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE
  int midasrun = 0; //run number
  char *filename[200]; // file name
  double irradStartTimes; // irradiation start time
  double cycleStartTimes; // cycle start time
  double cycleDelayTime; // cycle delay time (from the end of irradiation to valve open)
  double delaytimeArray[100]; // array of cycle delay time
  int cycleNumber; // cycle number of a particular run
  double cycleNumberArray [100]; // array of cycle numbers
  double UCNIntegral; // UCN integral or total counts that comes from integrating the fit function
  double UCNIntegralArray [100]; // array of total ucn counts that comes from integrating the fit function
  double UCNIntegralErr; // error of total ucn counts that comes from integrating the fit function
  double UCNIntegralErrArray [100]; // array of error in the total ucn counts from integrating the fit function
  double HistIntegral; // total ucn counts from integrating the histogram
  double HistIntegralArray [100]; // array of total ucn counts from integrating the histogram 
  double HistIntegralErrArray[100]; // array of errors in the total ucn counts coming from the
  double cycleValveOpenTime;
  double cycleValveCloseTime;

  double avets11Irrad; // average isopure temperature from TS11 during irradiation time
  double avets11IrradArray [100]; 
  double avets11ValveOpen;
  double avets11ValveOpenArray [100]; // array average TS11 temperature during valve open
  double maxts11Irrad;
  double maxts11IrradArray [100];
  double maxts11ValveOpen;
  double maxts11ValveOpenArray [100];
  double mints11Irrad;
  double mints11IrradArray [100];
  double mints11ValveOpen;
  double mints11ValveOpenArray [100];
  double ts11IrradErr [100];
  double ts11ValveOpenErr [100];
  
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


  double avets14Irrad;
  double avets14IrradArray [100];
  double avets14ValveOpen;
  double avets14ValveOpenArray [100];
  double maxts14Irrad;
  double maxts14IrradArray [100];
  double maxts14ValveOpen;
  double maxts14ValveOpenArray [100];
  double mints14Irrad;
  double mints14IrradArray [100];
  double mints14ValveOpen;
  double mints14ValveOpenArray [100];
  double ts14IrradErr [100];
  double ts14ValveOpenErr [100];


  double avets16Irrad;
  double avets16IrradArray [100];
  double avets16ValveOpen;
  double avets16ValveOpenArray [100];
  double maxts16Irrad;
  double maxts16IrradArray [100];
  double maxts16ValveOpen;
  double maxts16ValveOpenArray [100];
  double mints16Irrad;
  double mints16IrradArray [100];
  double mints16ValveOpen;
  double mints16ValveOpenArray [100];
  double ts16IrradErr [100];
  double ts16ValveOpenErr [100];
  
  double avecur; // average predicted current
  double avecurArray [100]; // array of average predicted current
  double maxcur; // maximum predicted current
  double maxcurArray [100];//array of maximum predicted current 
  double mincur; // minimum predicted current
  double mincurArray [100]; // array of minimum predicted current
  double ErrcurArray [100]; // error in the average predicted current which is max - min/2
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

  double BASELINERATE;
  double BASELINEIRRADRATE;

  
  double UCNIntegralManualArray [100];
  double UCNIntegralManualErrArray[100];
  int counts = 0;
  int oldcounts;

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
  // to 662
  for (midasrun = 614; midasrun < 662 ; midasrun++){
    cout << midasrun << endl;
    // cout << counts << " " << oldcounts << endl;
    if (midasrun == 637 || midasrun == 654 || midasrun == 659 )
      continue;
    sprintf (filename , "./2ndpass/outputTree_%d.root",midasrun);
    TFile* fin = new TFile(Form(filename),"READ");
    
    TTree *outputTree = (TTree*) fin -> Get("cycle_info");
    
    outputTree -> SetBranchAddress("irradStartTimes" , &irradStartTimes);
    outputTree -> SetBranchAddress("cycleStartTimes" , &cycleStartTimes);
    outputTree -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime);
    outputTree -> SetBranchAddress("cycleNumber", &cycleNumber);
    outputTree -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime);
    outputTree -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime);
    outputTree -> SetBranchAddress ("UCNIntegral" , &UCNIntegral);
    outputTree -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr);
    outputTree -> SetBranchAddress ("HistIntegral" , &HistIntegral);
    
    outputTree -> SetBranchAddress ("AVE_TS11_IRRAD" , &avets11Irrad);
    outputTree -> SetBranchAddress ("AVE_TS11_VALVEOPEN" , &avets11ValveOpen);
    outputTree -> SetBranchAddress ("MAX_TS11_IRRAD" , &maxts11Irrad);
    outputTree -> SetBranchAddress ("MAX_TS11_VALVEOPEN" , &maxts11ValveOpen);
    outputTree -> SetBranchAddress ("MIN_TS11_IRRAD" , &mints11Irrad);
    outputTree -> SetBranchAddress ("MIN_TS11_VALVEOPEN" , &mints11ValveOpen);
    
    outputTree -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad);
    outputTree -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen);
    outputTree -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad);
    outputTree -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen);
    outputTree -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad);
    outputTree -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen);

    outputTree -> SetBranchAddress ("AVE_TS14_IRRAD" , &avets14Irrad);
    outputTree -> SetBranchAddress ("AVE_TS14_VALVEOPEN" , &avets14ValveOpen);
    outputTree -> SetBranchAddress ("MAX_TS14_IRRAD" , &maxts14Irrad);
    outputTree -> SetBranchAddress ("MAX_TS14_VALVEOPEN" , &maxts14ValveOpen);
    outputTree -> SetBranchAddress ("MIN_TS14_IRRAD" , &mints14Irrad);
    outputTree -> SetBranchAddress ("MIN_TS14_VALVEOPEN" , &mints14ValveOpen);

    outputTree -> SetBranchAddress ("AVE_TS16_IRRAD" , &avets16Irrad);
    outputTree -> SetBranchAddress ("AVE_TS16_VALVEOPEN" , &avets16ValveOpen);
    outputTree -> SetBranchAddress ("MAX_TS16_IRRAD" , &maxts16Irrad);
    outputTree -> SetBranchAddress ("MAX_TS16_VALVEOPEN" , &maxts16ValveOpen);
    outputTree -> SetBranchAddress ("MIN_TS16_IRRAD" , &mints16Irrad);
    outputTree -> SetBranchAddress ("MIN_TS16_VALVEOPEN" , &mints16ValveOpen);
    
    outputTree -> SetBranchAddress ("AVE_PRDCUR" , &avecur);
    outputTree -> SetBranchAddress ("MAX_PRDCUR" , &maxcur);
    outputTree -> SetBranchAddress ("MIN_PRDCUR" , &mincur);
    outputTree -> SetBranchAddress ("Baseline" , &Baseline);
    outputTree -> SetBranchAddress ("BaselineErr" , &BaselineErr);
    outputTree -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad);
    outputTree -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr);
    outputTree -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral);
    outputTree -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral);
 
    outputTree -> SetBranchAddress ("BASELINERATE" , &BASELINERATE);
    outputTree -> SetBranchAddress ("BASELINEIRRADRATE" , &BASELINEIRRADRATE);


    // **************************
    // **************************
    
    //Temperature arrays for different beam currents

    // during irradiation 
    double avets11IrradArray_1muA[100];
    double avets12IrradArray_1muA[100];
    double avets14IrradArray_1muA[100];
    double avets16IrradArray_1muA[100];

    double avets11IrradErrArray_1muA[100];
    double avets12IrradErrArray_1muA[100];
    double avets14IrradErrArray_1muA[100];
    double avets16IrradErrArray_1muA[100];
     

    double avets11IrradArray_3muA[100];
    double avets12IrradArray_3muA[100];
    double avets14IrradArray_3muA[100];
    double avets16IrradArray_3muA[100];

    double avets11IrradErrArray_3muA[100];
    double avets12IrradErrArray_3muA[100];
    double avets14IrradErrArray_3muA[100];
    double avets16IrradErrArray_3muA[100];
    

    double avets11IrradArray_5muA[100];
    double avets12IrradArray_5muA[100];
    double avets14IrradArray_5muA[100];
    double avets16IrradArray_5muA[100];

    double avets11IrradErrArray_5muA[100];
    double avets12IrradErrArray_5muA[100];
    double avets14IrradErrArray_5muA[100];
    double avets16IrradErrArray_5muA[100];
    

    double avets11IrradArray_7muA[100];
    double avets12IrradArray_7muA[100];
    double avets14IrradArray_7muA[100];
    double avets16IrradArray_7muA[100];

    double avets11IrradErrArray_7muA[100];
    double avets12IrradErrArray_7muA[100];
    double avets14IrradErrArray_7muA[100];
    double avets16IrradErrArray_7muA[100];

    double avets11IrradArray_10muA[100];
    double avets12IrradArray_10muA[100];
    double avets14IrradArray_10muA[100];
    double avets16IrradArray_10muA[100];

    double avets11IrradErrArray_10muA[100];
    double avets12IrradErrArray_10muA[100];
    double avets14IrradErrArray_10muA[100];
    double avets16IrradErrArray_10muA[100];


    // during valve open 

    double avets11VOArray_1muA[100];
    double avets12VOArray_1muA[100];
    double avets14VOArray_1muA[100];
    double avets16VOArray_1muA[100];

    double avets11VOErrArray_1muA[100];
    double avets12VOErrArray_1muA[100];
    double avets14VOErrArray_1muA[100];
    double avets16VOErrArray_1muA[100];
     

    double avets11VOArray_3muA[100];
    double avets12VOArray_3muA[100];
    double avets14VOArray_3muA[100];
    double avets16VOArray_3muA[100];

    double avets11VOErrArray_3muA[100];
    double avets12VOErrArray_3muA[100];
    double avets14VOErrArray_3muA[100];
    double avets16VOErrArray_3muA[100];
    

    double avets11VOArray_5muA[100];
    double avets12VOArray_5muA[100];
    double avets14VOArray_5muA[100];
    double avets16VOArray_5muA[100];

    double avets11VOErrArray_5muA[100];
    double avets12VOErrArray_5muA[100];
    double avets14VOErrArray_5muA[100];
    double avets16VOErrArray_5muA[100];
    

    double avets11VOArray_7muA[100];
    double avets12VOArray_7muA[100];
    double avets14VOArray_7muA[100];
    double avets16VOArray_7muA[100];

    double avets11VOErrArray_7muA[100];
    double avets12VOErrArray_7muA[100];
    double avets14VOErrArray_7muA[100];
    double avets16VOErrArray_7muA[100];

    double avets11VOArray_10muA[100];
    double avets12VOArray_10muA[100];
    double avets14VOArray_10muA[100];
    double avets16VOArray_10muA[100];

    double avets11VOErrArray_10muA[100];
    double avets12VOErrArray_10muA[100];
    double avets14VOErrArray_10muA[100];
    double avets16VOErrArray_10muA[100];
    
    // write to file

    ofstream myfile;
    myfile.open("./2ndpass/TCN17007_Data.csv" , std::ios::app);
  
    ULong64_t events;
    events = (Double_t) outputTree -> GetEntries();
    
    for (ULong64_t j = 0 ; j < events ; j++){
      outputTree -> GetEvent(j);
      //cout << counts << endl;
      //if (UCNIntegral < 10)
      //continue;
      if (midasrun == 614 && j == 1 )
	continue;
      if (midasrun == 618 || midasrun == 623 || midasrun == 624)
	continue;
      if (midasrun == 626 && j ==0)
	continue;
      if (midasrun == 632 || midasrun == 635 || midasrun == 636)
	continue;
      if (midasrun == 637 || midasrun == 638 )
	continue;
      if (midasrun == 639 && j == 0)
	continue;
      if ( midasrun == 642 || midasrun == 643)
	continue;
      if (midasrun == 647 || midasrun == 648 )
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
      
      avets11ValveOpenArray[counts] = avets11ValveOpen;
      avets12ValveOpenArray[counts] = avets12ValveOpen;
      avets14ValveOpenArray[counts] = avets14ValveOpen;
      avets16ValveOpenArray[counts] = avets16ValveOpen;
      
      maxts12IrradArray[counts] = maxts12Irrad;
      maxts12ValveOpenArray[counts] = maxts12ValveOpen;
      mints12IrradArray[counts] = mints12Irrad; 
      mints12ValveOpenArray[counts] = mints12ValveOpen;
      ts12IrradErr[counts] = (maxts12Irrad - mints12Irrad)/2;
      
      ts11ValveOpenErr[counts] = (maxts11ValveOpen - mints11ValveOpen)/2;
      ts12ValveOpenErr[counts] = (maxts12ValveOpen - mints12ValveOpen)/2;
      ts14ValveOpenErr[counts] = (maxts14ValveOpen - mints14ValveOpen)/2;
      ts16ValveOpenErr[counts] = (maxts16ValveOpen - mints16ValveOpen)/2;
      
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
      UCNIntegralManualArray[counts] = HistIntegral - BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
      // cout << UCNIntegralManualArray[counts] << endl;
      UCNIntegralManualErrArray[counts] = sqrt(UCNIntegralManualArray[counts]);
      //cout << " The irradiation time for run " <<midasrun << " for cycle "<< counts << " is "<< cycleStartTimes - irradStartTimes << endl;


      
      
      // *******************
      // FOR THE FINAL GRAPH
      // ********************
      
      // 1.5 muA
      if (avecur > 1.4 && avecur < 1.6){
	UCNIntegralArray_1muA[counts_1muA] = UCNIntegral;
	UCNIntegralErrArray_1muA[counts_1muA] = UCNIntegralErr;
	HistIntegralArray_1muA[counts_1muA] = HistIntegral;
	HistIntegralErrArray_1muA[counts_1muA] = sqrt(HistIntegral);
	UCNIntegralManualArray_1muA[counts_1muA] =  HistIntegral -  BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	UCNIntegralManualErrArray_1muA[counts_1muA] = sqrt(UCNIntegralManualArray_1muA[counts]);
	irradtimeArray_1muA[counts_1muA] = cycleStartTimes - irradStartTimes;
	//temperatures
	avets11IrradArray_1muA[counts_1muA] = avets11Irrad;
	avets11IrradErrArray_1muA [counts_1muA] = (maxts11Irrad - mints11Irrad)/2;
	avets11VOArray_1muA[counts_1muA] = avets11ValveOpen;
	avets11VOErrArray_1muA[counts_1muA] = (maxts11ValveOpen - mints11ValveOpen)/2;

	avets12IrradArray_1muA[counts_1muA] = avets12Irrad;
	avets12IrradErrArray_1muA [counts_1muA] = (maxts12Irrad - mints12Irrad)/2;
	avets12VOArray_1muA[counts_1muA] = avets12ValveOpen;
	avets12VOErrArray_1muA[counts_1muA] = (maxts12ValveOpen - mints12ValveOpen)/2;

	avets14IrradArray_1muA[counts_1muA] = avets14Irrad;
	avets14IrradErrArray_1muA [counts_1muA] = (maxts14Irrad - mints14Irrad)/2;
	avets14VOArray_1muA[counts_1muA] = avets14ValveOpen;
	avets14VOErrArray_1muA[counts_1muA] = (maxts14ValveOpen - mints14ValveOpen)/2;

	avets16IrradArray_1muA[counts_1muA] = avets16Irrad;
	avets16IrradErrArray_1muA [counts_1muA] = (maxts16Irrad - mints16Irrad)/2;
	avets16VOArray_1muA[counts_1muA] = avets16ValveOpen;
	avets16VOErrArray_1muA[counts_1muA] = (maxts16ValveOpen - mints16ValveOpen)/2;
	//cout << "Current " << avecur << " Counts " << UCNIntegralManualArray_1muA[counts_1muA] << endl;

	counts_1muA++;
      }
      
      // 3 muA
      if (avecur > 2.8 && avecur < 3.2){
	UCNIntegralArray_3muA[counts_3muA] = UCNIntegral;
	UCNIntegralErrArray_3muA[counts_3muA] = UCNIntegralErr;
	HistIntegralArray_3muA[counts_3muA] = HistIntegral;
	HistIntegralErrArray_3muA[counts_3muA] = sqrt(HistIntegral);
	UCNIntegralManualArray_3muA[counts_3muA] =  HistIntegral -  BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	UCNIntegralManualErrArray_3muA[counts_3muA] = sqrt(UCNIntegralManualArray_3muA[counts]);
	irradtimeArray_3muA[counts_3muA] = cycleStartTimes - irradStartTimes;
	//temperatures
	avets11IrradArray_3muA[counts_3muA] = avets11Irrad;
	avets11IrradErrArray_3muA [counts_3muA] = (maxts11Irrad - mints11Irrad)/2;
	avets11VOArray_3muA[counts_3muA] = avets11ValveOpen;
	avets11VOErrArray_3muA[counts_3muA] = (maxts11ValveOpen - mints11ValveOpen)/2;

	avets12IrradArray_3muA[counts_3muA] = avets12Irrad;
	avets12IrradErrArray_3muA [counts_3muA] = (maxts12Irrad - mints12Irrad)/2;
	avets12VOArray_3muA[counts_3muA] = avets12ValveOpen;
	avets12VOErrArray_3muA[counts_3muA] = (maxts12ValveOpen - mints12ValveOpen)/2;

	avets14IrradArray_3muA[counts_3muA] = avets14Irrad;
	avets14IrradErrArray_3muA [counts_3muA] = (maxts14Irrad - mints14Irrad)/2;
	avets14VOArray_3muA[counts_3muA] = avets14ValveOpen;
	avets14VOErrArray_3muA[counts_3muA] = (maxts14ValveOpen - mints14ValveOpen)/2;

	avets16IrradArray_3muA[counts_3muA] = avets16Irrad;
	avets16IrradErrArray_3muA [counts_3muA] = (maxts16Irrad - mints16Irrad)/2;
	avets16VOArray_3muA[counts_3muA] = avets16ValveOpen;
	avets16VOErrArray_3muA[counts_3muA] = (maxts16ValveOpen - mints16ValveOpen)/2;
	counts_3muA++;
      }
      
      // 5 muA
      if (avecur > 4.8 && avecur < 5.2){
	UCNIntegralArray_5muA[counts_5muA] = UCNIntegral;
	UCNIntegralErrArray_5muA[counts_5muA] = UCNIntegralErr;
	HistIntegralArray_5muA[counts_5muA] = HistIntegral;
	HistIntegralErrArray_5muA[counts_5muA] = sqrt(HistIntegral);
	UCNIntegralManualArray_5muA[counts_5muA] =  HistIntegral -  BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	UCNIntegralManualErrArray_5muA[counts_5muA] = sqrt(UCNIntegralManualArray_5muA[counts]);
	irradtimeArray_5muA[counts_5muA] = cycleStartTimes - irradStartTimes;
	//temperatures
	avets11IrradArray_5muA[counts_5muA] = avets11Irrad;
	avets11IrradErrArray_5muA [counts_5muA] = (maxts11Irrad - mints11Irrad)/2;
	avets11VOArray_5muA[counts_5muA] = avets11ValveOpen;
	avets11VOErrArray_5muA[counts_5muA] = (maxts11ValveOpen - mints11ValveOpen)/2;

	avets12IrradArray_5muA[counts_5muA] = avets12Irrad;
	avets12IrradErrArray_5muA [counts_5muA] = (maxts12Irrad - mints12Irrad)/2;
	avets12VOArray_5muA[counts_5muA] = avets12ValveOpen;
	avets12VOErrArray_5muA[counts_5muA] = (maxts12ValveOpen - mints12ValveOpen)/2;

	avets14IrradArray_5muA[counts_5muA] = avets14Irrad;
	avets14IrradErrArray_5muA [counts_5muA] = (maxts14Irrad - mints14Irrad)/2;
	avets14VOArray_5muA[counts_5muA] = avets14ValveOpen;
	avets14VOErrArray_5muA[counts_5muA] = (maxts14ValveOpen - mints14ValveOpen)/2;

	avets16IrradArray_5muA[counts_5muA] = avets16Irrad;
	avets16IrradErrArray_5muA [counts_5muA] = (maxts16Irrad - mints16Irrad)/2;
	avets16VOArray_5muA[counts_5muA] = avets16ValveOpen;
	avets16VOErrArray_5muA[counts_5muA] = (maxts16ValveOpen - mints16ValveOpen)/2;
	
	//cout << "Current " << avecur << " Counts " << UCNIntegralManualArray_5muA[counts_5muA] <<" Irradiation duration " << cycleStartTimes - irradStartTimes  << endl;
	counts_5muA++;
      }
      
      // 7 muA
      if (avecur > 6.8 && avecur < 7.3){
	//if (midasrun == 639 && UCNIntegral < 1000)
	//continue;
	// cout << midasrun << " " << UCNIntegral << endl;
	UCNIntegralArray_7muA[counts_7muA] = UCNIntegral;
	UCNIntegralErrArray_7muA[counts_7muA] = UCNIntegralErr;
	HistIntegralArray_7muA[counts_7muA] = HistIntegral;
	HistIntegralErrArray_7muA[counts_7muA] = sqrt(HistIntegral);
	UCNIntegralManualArray_7muA[counts_7muA] =  HistIntegral -  BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	UCNIntegralManualErrArray_7muA[counts_7muA] = sqrt(UCNIntegralManualArray_7muA[counts]);
	irradtimeArray_7muA[counts_7muA] = cycleStartTimes - irradStartTimes;
	//temperature
	avets11IrradArray_7muA[counts_7muA] = avets11Irrad;
	avets11IrradErrArray_7muA [counts_7muA] = (maxts11Irrad - mints11Irrad)/2;
	avets11VOArray_7muA[counts_7muA] = avets11ValveOpen;
	avets11VOErrArray_7muA[counts_7muA] = (maxts11ValveOpen - mints11ValveOpen)/2;

	avets12IrradArray_7muA[counts_7muA] = avets12Irrad;
	avets12IrradErrArray_7muA [counts_7muA] = (maxts12Irrad - mints12Irrad)/2;
	avets12VOArray_7muA[counts_7muA] = avets12ValveOpen;
	avets12VOErrArray_7muA[counts_7muA] = (maxts12ValveOpen - mints12ValveOpen)/2;

	avets14IrradArray_7muA[counts_7muA] = avets14Irrad;
	avets14IrradErrArray_7muA [counts_7muA] = (maxts14Irrad - mints14Irrad)/2;
	avets14VOArray_7muA[counts_7muA] = avets14ValveOpen;
	avets14VOErrArray_7muA[counts_7muA] = (maxts14ValveOpen - mints14ValveOpen)/2;

	avets16IrradArray_7muA[counts_7muA] = avets16Irrad;
	avets16IrradErrArray_7muA [counts_7muA] = (maxts16Irrad - mints16Irrad)/2;
	avets16VOArray_7muA[counts_7muA] = avets16ValveOpen;
	avets16VOErrArray_7muA[counts_7muA] = (maxts16ValveOpen - mints16ValveOpen)/2;
	
	counts_7muA++;
      }
      
      // 10 muA
      if (avecur > 9.8 && avecur < 10.2){
	UCNIntegralArray_10muA[counts_10muA] = UCNIntegral;
	UCNIntegralErrArray_10muA[counts_10muA] = UCNIntegralErr;
	HistIntegralArray_10muA[counts_10muA] = HistIntegral;
	HistIntegralErrArray_10muA[counts_10muA] = sqrt(HistIntegral);
	UCNIntegralManualArray_10muA[counts_10muA] =  HistIntegral -  BASELINERATE*(cycleValveCloseTime - cycleValveOpenTime);
	UCNIntegralManualErrArray_10muA[counts_10muA] = sqrt(UCNIntegralManualArray_10muA[counts]);
	irradtimeArray_10muA[counts_10muA] = cycleStartTimes - irradStartTimes;

	//temperature
	avets11IrradArray_10muA[counts_10muA] = avets11Irrad;
	avets11IrradErrArray_10muA [counts_10muA] = (maxts11Irrad - mints11Irrad)/2;
	avets11VOArray_10muA[counts_10muA] = avets11ValveOpen;
	avets11VOErrArray_10muA[counts_10muA] = (maxts11ValveOpen - mints11ValveOpen)/2;

	avets12IrradArray_10muA[counts_10muA] = avets12Irrad;
	avets12IrradErrArray_10muA [counts_10muA] = (maxts12Irrad - mints12Irrad)/2;
	avets12VOArray_10muA[counts_10muA] = avets12ValveOpen;
	avets12VOErrArray_10muA[counts_10muA] = (maxts12ValveOpen - mints12ValveOpen)/2;

	avets14IrradArray_10muA[counts_10muA] = avets14Irrad;
	avets14IrradErrArray_10muA [counts_10muA] = (maxts14Irrad - mints14Irrad)/2;
	avets14VOArray_10muA[counts_10muA] = avets14ValveOpen;
	avets14VOErrArray_10muA[counts_10muA] = (maxts14ValveOpen - mints14ValveOpen)/2;

	avets16IrradArray_10muA[counts_10muA] = avets16Irrad;
	avets16IrradErrArray_10muA [counts_10muA] = (maxts16Irrad - mints16Irrad)/2;
	avets16VOArray_10muA[counts_10muA] = avets16ValveOpen;
	avets16VOErrArray_10muA[counts_10muA] = (maxts16ValveOpen - mints16ValveOpen)/2;
	counts_10muA++;
      }
      if (cycleStartTimes - irradStartTimes > 59. && cycleStartTimes - irradStartTimes < 61. ){
	myfile << HistIntegralArray[counts] << " "<< HistIntegralErrArray[counts] << " " << UCNIntegralManualArray[counts] << " " << UCNIntegralManualErrArray[counts] << " " << avecurArray[counts] << " " << ErrcurArray[counts] << " " << avets11ValveOpenArray[counts] << " " << ts11ValveOpenErr[counts] << " " << avets12ValveOpenArray[counts] << " " <<ts12ValveOpenErr[counts] << " " << avets14ValveOpenArray[counts] << " " << ts14ValveOpenErr[counts] << " " << avets16ValveOpenArray[counts] << " " << ts16ValveOpenErr[counts] << " " << maxts12ValveOpen << " " << mints12ValveOpen << endl;

      }
      counts++;
      //cout << counts << endl;
    }
    
    
    
    /*
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
    //leg2 -> AddEntry(gr_cyclecounts , "Counts with background subtracted (fit)" , "p") ;
    leg2 -> AddEntry(gr_cyclehist , "Counts with background" , "p") ;
    leg2 -> AddEntry(gr_cyclecountmanual, "Counts with background subtracted" , "p"); 
    leg2 -> SetTextSize(0.05);
    
    //gr_cyclecounts -> Draw("Ap");
    gr_cyclehist -> Draw("Ap");
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
    
    TGraphErrors *gr_countIrrad = new TGraphErrors (counts, avets12IrradArray, UCNIntegralManualArray, ts12IrradErr, UCNIntegralManualErrArray);
    gr_countIrrad -> SetTitle( "UCN Counts vs Average Isopure Temperature");
    gr_countIrrad -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
    gr_countIrrad -> GetYaxis()-> SetTitle("UCN Counts");
    gr_countIrrad -> SetMarkerStyle(20);
    gr_countIrrad -> GetYaxis() -> SetRangeUser(10,500000);
    gr_countIrrad -> GetXaxis()-> SetLimits(0.8, 0.98);
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
    
    
    
    TGraphErrors *gr_countValveOpen11 = new TGraphErrors (counts, avets11ValveOpenArray, UCNIntegralManualArray, ts11ValveOpenErr, UCNIntegralManualErrArray);
    gr_countValveOpen11 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
    gr_countValveOpen11 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
    gr_countValveOpen11 -> GetYaxis()-> SetTitle("UCN Counts");
    gr_countValveOpen11 -> SetMarkerStyle(20);
    gr_countValveOpen11 -> GetYaxis() -> SetRangeUser(100,500000);
    gr_countValveOpen11 -> GetXaxis()-> SetLimits(0.8, 1.3);
    gr_countValveOpen11 -> GetXaxis() -> SetTitleSize(0.05);
    gr_countValveOpen11 -> GetXaxis() -> SetTitleOffset(1.0);
    gr_countValveOpen11 -> GetYaxis() -> SetTitleSize(0.05); 
    gr_countValveOpen11 -> GetYaxis() -> SetTitleOffset(0.9);
    gr_countValveOpen11 -> SetMarkerColor(2);
    
    
    TGraphErrors *gr_countValveOpen = new TGraphErrors (counts, avets12ValveOpenArray, UCNIntegralManualArray, ts12ValveOpenErr, UCNIntegralManualErrArray);
    gr_countValveOpen -> SetTitle( "UCN Counts vs Average Isopure Temperature");
    gr_countValveOpen -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
    gr_countValveOpen -> GetYaxis()-> SetTitle("UCN Counts");
    gr_countValveOpen -> SetMarkerStyle(20);
    gr_countValveOpen -> GetXaxis()-> SetLimits(0.8, 0.9);
    gr_countValveOpen -> GetXaxis() -> SetTitleSize(0.05);
    gr_countValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
    gr_countValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
    gr_countValveOpen -> GetYaxis() -> SetTitleOffset(0.9);
    gr_countValveOpen -> SetMarkerColor(1);
    
    
    TGraphErrors *gr_countValveOpen14 = new TGraphErrors (counts, avets14ValveOpenArray, UCNIntegralManualArray, ts14ValveOpenErr, UCNIntegralManualErrArray);
    gr_countValveOpen14 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
    gr_countValveOpen14 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
    gr_countValveOpen14 -> GetYaxis()-> SetTitle("UCN Counts");
    gr_countValveOpen14 -> SetMarkerStyle(20);
    gr_countValveOpen14 -> GetXaxis()-> SetLimits(0.8, 0.9);
    gr_countValveOpen14 -> GetXaxis() -> SetTitleSize(0.05);
    gr_countValveOpen14 -> GetXaxis() -> SetTitleOffset(1.0);
    gr_countValveOpen14 -> GetYaxis() -> SetTitleSize(0.05); 
    gr_countValveOpen14 -> GetYaxis() -> SetTitleOffset(0.9);
    gr_countValveOpen14 -> SetMarkerColor(4);
    
    TGraphErrors *gr_countValveOpen16 = new TGraphErrors (counts, avets16ValveOpenArray, UCNIntegralManualArray, ts16ValveOpenErr, UCNIntegralManualErrArray);
    gr_countValveOpen16 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
    gr_countValveOpen16 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
    gr_countValveOpen16 -> GetYaxis()-> SetTitle("UCN Counts");
    gr_countValveOpen16 -> SetMarkerStyle(20);
    gr_countValveOpen16 -> GetXaxis()-> SetLimits(0.8, 0.9);
    gr_countValveOpen16 -> GetXaxis() -> SetTitleSize(0.05);
    gr_countValveOpen16 -> GetXaxis() -> SetTitleOffset(1.0);
    gr_countValveOpen16 -> GetYaxis() -> SetTitleSize(0.05); 
    gr_countValveOpen16 -> GetYaxis() -> SetTitleOffset(0.9);
    gr_countValveOpen16 -> SetMarkerColor(8);
    
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
    // leg3 -> AddEntry(gr_countIrrad , "Irradiation time + delay time, without background" , "p") ;
    leg3 -> AddEntry(gr_countValveOpen11 , "Valve open, He-II pot bottom" , "p") ;
    leg3 -> AddEntry(gr_countValveOpen , "Valve open, UCN double tube top" , "p") ;
    //leg3 -> AddEntry(gr_HistIrrad , "Irradiation time + delay time, with background" , "p") ;
    //leg3 -> AddEntry(gr_HistValveOpen , "Valve open, with background" , "p") ;
    leg3 -> AddEntry(gr_countValveOpen14 , "Valve open, He-II pot top" , "p") ;
    leg3 -> AddEntry(gr_countValveOpen16 , "Valve open, UCN double tube bottom" , "p") ;
    leg3 -> SetTextSize(0.04);
    
    //gr_countIrrad -> Draw("AP");
    gr_countValveOpen11 -> Draw("Ap");
    gr_countValveOpen -> Draw("p");
    gr_countValveOpen14 -> Draw("p");
    gr_countValveOpen16 -> Draw("p");  
    //gr_HistIrrad -> Draw("p");
    //gr_HistValveOpen -> Draw("p");
    leg3 -> Draw();
    */


    oldcounts = counts;

    fin -> Close();
    myfile.close();
  }
  
  /*
  TF1 *f1 = new TF1("f1" , "[0]*[1]*(1 - exp(-x/[1]))" , 0 , 150);
  f1 -> SetParName(0, "P");
  f1 -> SetParName(1, "#tau");
  f1 -> SetParameter(0, 10000);
  f1 -> SetParameter(1, 35);
  f1 -> SetParLimits(1, 17, 40);
  
  
  // ONLINE ANALYSIS
  
  double irrad_1muA[100] = {60, 60, 30, 30, 10, 10, 120, 120};
  double countsOnline1muA[100] = {60950, 60882, 44877, 44569, 20267, 20626, 68295, 65418};

  double irrad_3muA[100] = {60 , 60, 60, 60 , 60, 60, 30, 30, 30,10, 10, 10, 120};
  double countsOnline3muA[100] = {120781, 117583, 116194,117200, 115900, 116378, 87445, 87770, 86845, 40009, 40128, 39995, 121774 };

  double irrad_5muA[100] = {60, 60, 60, 60, 60, 60, 30, 30, 30, 10, 10, 10, 120, 120, 120 };
  double countsOnline5muA[100] = {187593, 183397, 181969, 180996, 181641, 180813,138896, 140355, 140646, 66017, 66688, 65900, 180860, 182208, 168731};

  double irrad_7muA[100] = {30, 30, 30, 60, 60, 60, 60,10, 10, 100};
  double countsOnline7muA[100] = {196483, 196345, 195076, 244108, 240295, 236461, 218805, 94786, 93734, 238781};

  double irrad_10muA[100] = {60, 30, 60, 60, 10, 10, 30, 30, 30};
  double countsOnline10muA[100] = {325380, 272176, 324800, 309519, 126541, 126998, 262278, 256605, 255361};
  #if 1
  TCanvas *c_1muA = new TCanvas ("c_1muA" , "c_1muA", 1200, 900);
  c_1muA-> SetLogy();

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
  grhist_1muA -> GetYaxis() -> SetRangeUser (100, 7000000);
  grhist_1muA -> SetMarkerStyle(25);
  grhist_1muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_1muA -> SetMarkerColor(2);

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


 TGraphErrors *gr1muAOnline = new TGraphErrors (8, irrad_1muA, countsOnline1muA, 0 , 0 );
  gr1muAOnline -> SetTitle( "UCN Counts vs Irradiation Time");
  gr1muAOnline -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr1muAOnline -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muAOnline -> SetMarkerStyle(3);
  gr1muAOnline -> GetXaxis()-> SetLimits(0, 150);
  gr1muAOnline -> GetXaxis() -> SetTitleSize(0.05);
  gr1muAOnline -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muAOnline -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muAOnline -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muAOnline -> SetMarkerColor(8);

  

  TLegend *leg1muA = new TLegend (0.7, 0.7, 0.9, 0.9);
  //leg1muA -> AddEntry(grcounts_1muA, "Counts without background (fit)" , "p");
  leg1muA -> AddEntry(grcountsM_1muA , "Counts without background" ,"p");
  leg1muA -> AddEntry(grhist_1muA, "Counts with background", "p");
  leg1muA -> AddEntry(gr1muAOnline , "Online Analysis" , "p");
  leg1muA -> SetTextSize(0.04);
  
  //grcounts_1muA -> Draw("Ap");
  grhist_1muA -> Draw("Ap");
  grcountsM_1muA -> Draw("p");
  grcountsM_1muA -> Fit("f1", "R+M");
  gr1muAOnline -> Draw("p");
  leg1muA -> Draw();

  TCanvas *c_3muA = new TCanvas ("c_3muA" , "c_3mA", 1200, 900);
  c_3muA -> SetLogy();
  TGraphErrors *grcounts_3muA = new TGraphErrors (counts_3muA, irradtimeArray_3muA, UCNIntegralArray_3muA, 0 , UCNIntegralErrArray_3muA);
  grcounts_3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_3muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_3muA -> GetYaxis() -> SetRangeUser (1, 1000000);
  grcounts_3muA -> SetMarkerStyle(20);
  grcounts_3muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_3muA -> SetMarkerColor(1);
    
  TGraphErrors *grhist_3muA = new TGraphErrors (counts_3muA, irradtimeArray_3muA, HistIntegralArray_3muA, 0 , HistIntegralErrArray_3muA);
  grhist_3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_3muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_3muA -> GetYaxis() -> SetRangeUser (100, 7000000);
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
  grcountsM_3muA -> SetMarkerColor(1);

  TGraphErrors *gr3muAOnline = new TGraphErrors (13, irrad_3muA, countsOnline3muA, 0 , 0 );
  gr3muAOnline -> SetTitle( "UCN Counts vs Irradiation Time");
  gr3muAOnline -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr3muAOnline -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muAOnline -> SetMarkerStyle(3);
  gr3muAOnline -> GetXaxis()-> SetLimits(0, 150);
  gr3muAOnline -> GetXaxis() -> SetTitleSize(0.05);
  gr3muAOnline -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muAOnline -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muAOnline -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muAOnline -> SetMarkerColor(8);

  //grcounts_3muA -> Draw("Ap");
  grhist_3muA -> Draw("Ap");
  grcountsM_3muA -> Draw("p");
  grcountsM_3muA -> Fit("f1" , "R+M");
  gr3muAOnline -> Draw("p");
  leg1muA -> Draw();

  TCanvas *c_5muA = new TCanvas ("c_5muA" , "c_5mA", 1200, 900);
  c_5muA -> SetLogy();
  TGraphErrors *grcounts_5muA = new TGraphErrors (counts_5muA, irradtimeArray_5muA, UCNIntegralArray_5muA, 0 , UCNIntegralErrArray_5muA);
  grcounts_5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_5muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_5muA -> GetYaxis() -> SetRangeUser (1, 1000000);
  grcounts_5muA -> SetMarkerStyle(20);
  grcounts_5muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_5muA -> SetMarkerColor(1);
    
  TGraphErrors *grhist_5muA = new TGraphErrors (counts_5muA, irradtimeArray_5muA, HistIntegralArray_5muA, 0 , HistIntegralErrArray_5muA);
  grhist_5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_5muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_5muA -> GetYaxis() -> SetRangeUser (100, 7000000);
  grhist_5muA -> SetMarkerStyle(25);
  grhist_5muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_5muA -> SetMarkerColor(2);

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
  grcountsM_5muA -> SetMarkerColor(1);

  TGraphErrors *gr5muAOnline = new TGraphErrors (15, irrad_5muA, countsOnline5muA, 0 , 0 );
  gr5muAOnline -> SetTitle( "UCN Counts vs Irradiation Time");
  gr5muAOnline -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr5muAOnline -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muAOnline -> SetMarkerStyle(3);
  gr5muAOnline -> GetXaxis()-> SetLimits(0, 150);
  gr5muAOnline -> GetXaxis() -> SetTitleSize(0.05);
  gr5muAOnline -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muAOnline -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muAOnline -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muAOnline -> SetMarkerColor(8);
  

  //grcounts_5muA -> Draw("Ap");
  grhist_5muA -> Draw("Ap");
  grcountsM_5muA -> Draw("p");
  grcountsM_5muA -> Fit("f1" , "R+M");
  gr5muAOnline -> Draw("p");
  leg1muA -> Draw();

  TCanvas *c_7muA = new TCanvas ("c_7muA" , "c_7mA", 1200, 900);
  c_7muA -> SetLogy();
  TGraphErrors *grcounts_7muA = new TGraphErrors (counts_7muA, irradtimeArray_7muA, UCNIntegralArray_7muA, 0 , UCNIntegralErrArray_7muA);
  grcounts_7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_7muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_7muA -> GetYaxis() -> SetRangeUser (1, 1000000);
  grcounts_7muA -> SetMarkerStyle(20);
  grcounts_7muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_7muA -> SetMarkerColor(1);
    
  TGraphErrors *grhist_7muA = new TGraphErrors (counts_7muA, irradtimeArray_7muA, HistIntegralArray_7muA, 0 , HistIntegralErrArray_7muA);
  grhist_7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_7muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_7muA -> GetYaxis() -> SetRangeUser (100, 7000000);
  grhist_7muA -> SetMarkerStyle(25);
  grhist_7muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_7muA -> SetMarkerColor(2);

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
  grcountsM_7muA -> SetMarkerColor(1);


  TGraphErrors *gr7muAOnline = new TGraphErrors (10, irrad_7muA, countsOnline7muA, 0 , 0 );
  gr7muAOnline -> SetTitle( "UCN Counts vs Irradiation Time");
  gr7muAOnline -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr7muAOnline -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muAOnline -> SetMarkerStyle(3);
  gr7muAOnline -> GetXaxis()-> SetLimits(0, 150);
  gr7muAOnline -> GetXaxis() -> SetTitleSize(0.05);
  gr7muAOnline -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muAOnline -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muAOnline -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muAOnline -> SetMarkerColor(8);

  //grcounts_7muA -> Draw("Ap");
  grhist_7muA -> Draw("Ap");
  grcountsM_7muA -> Draw("p");
  grcountsM_7muA -> Fit("f1" , "R+M");
  gr7muAOnline -> Draw("p");
  leg1muA -> Draw();

  
  TCanvas *c_10muA = new TCanvas ("c_10muA" , "c_10mA", 1200, 900);
  c_10muA -> SetLogy();
  TGraphErrors *grcounts_10muA = new TGraphErrors (counts_10muA, irradtimeArray_10muA, UCNIntegralArray_10muA, 0 , UCNIntegralErrArray_10muA);
  grcounts_10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grcounts_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grcounts_10muA -> GetYaxis()-> SetTitle("UCN Counts");
  grcounts_10muA -> GetYaxis() -> SetRangeUser (1, 1000000);
  grcounts_10muA -> SetMarkerStyle(20);
  grcounts_10muA -> GetXaxis()-> SetLimits(0, 150);
  grcounts_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grcounts_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grcounts_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grcounts_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grcounts_10muA -> SetMarkerColor(1);
    
  TGraphErrors *grhist_10muA = new TGraphErrors (counts_10muA, irradtimeArray_10muA, HistIntegralArray_10muA, 0 , HistIntegralErrArray_10muA);
  grhist_10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  grhist_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  grhist_10muA -> GetYaxis()-> SetTitle("UCN Counts");
  grhist_10muA -> GetYaxis() -> SetRangeUser (100, 7000000);
  grhist_10muA -> SetMarkerStyle(25);
  grhist_10muA -> GetXaxis()-> SetLimits(0, 150);
  grhist_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grhist_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grhist_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grhist_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grhist_10muA -> SetMarkerColor(2);

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
  grcountsM_10muA -> SetMarkerColor(1);


  TGraphErrors *gr10muAOnline = new TGraphErrors (9, irrad_10muA, countsOnline10muA, 0 , 0 );
  gr10muAOnline -> SetTitle( "UCN Counts vs Irradiation Time");
  gr10muAOnline -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr10muAOnline -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muAOnline -> SetMarkerStyle(3);
  gr10muAOnline -> GetXaxis() -> SetLimits(0, 150);
  gr10muAOnline -> GetXaxis() -> SetTitleSize(0.05);
  gr10muAOnline -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muAOnline -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muAOnline -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muAOnline -> SetMarkerColor(8);

  // grcounts_10muA -> Draw("Ap");
  grhist_10muA -> Draw("Ap");
  grcountsM_10muA -> Draw("p");
  grcountsM_10muA -> Fit("f1" , "R+EX0");
  gr10muAOnline -> Draw("p");
  leg1muA -> Draw();

#endif


#if 0
  TCanvas *cAll = new TCanvas ("cAll" , "cAll" , 1200, 900);
  cAll -> SetLogy();
  grhist_1muA -> GetYaxis() -> SetRangeUser (1000, 500000);
  grhist_1muA -> GetXaxis() -> SetLimits(0, 300);
  grcountsM_1muA -> GetYaxis() -> SetRangeUser (1000, 7000000);
  grcountsM_1muA -> GetXaxis() -> SetLimits(0, 300);

  grhist_1muA -> SetMarkerStyle(20);
  grhist_3muA -> SetMarkerStyle(20);
  grhist_5muA -> SetMarkerStyle(20);
  grhist_7muA -> SetMarkerStyle(20);
  grhist_10muA -> SetMarkerStyle(20);

  grcountsM_1muA -> SetMarkerStyle(20);
  grcountsM_3muA -> SetMarkerStyle(21);
  grcountsM_5muA -> SetMarkerStyle(24);
  grcountsM_7muA -> SetMarkerStyle(25);
  grcountsM_10muA -> SetMarkerStyle(3);
  
  grhist_1muA -> SetMarkerColor(1);
  grhist_3muA -> SetMarkerColor(2);
  grhist_5muA -> SetMarkerColor(8);
  grhist_7muA -> SetMarkerColor(4);
  grhist_10muA -> SetMarkerColor(6);

  grcountsM_1muA -> SetMarkerColor(1);
  grcountsM_3muA -> SetMarkerColor(1);
  grcountsM_5muA -> SetMarkerColor(1);
  grcountsM_7muA -> SetMarkerColor(1);
  grcountsM_10muA -> SetMarkerColor(1);
  
  TLegend *legAll = new TLegend(0.7, 0.7 , 0.9, 0.9);
  //legAll -> AddEntry (grhist_1muA, "Counts With Background , 1 #muA", "p");
  legAll -> AddEntry (grcountsM_1muA, "UCN Counts Without Background , 1.5 #muA" , "p");
  //legAll -> AddEntry (grhist_3muA, "Counts With Background , 3 #muA" , "p");
  legAll -> AddEntry (grcountsM_3muA, "UCN Counts Without Background , 3 #muA", "p");
  //legAll -> AddEntry (grhist_5muA , "Counts With Background , 5 #muA" , "p");
  legAll -> AddEntry (grcountsM_5muA, "UCN Counts Without Background , 5 #muA" , "p");
  //legAll -> AddEntry (grhist_7muA, "Counts With Background , 7 #muA" , "p");
  legAll -> AddEntry (grcountsM_7muA , "UCN Counts Without Background , 7.1 #muA" , "P");
  //legAll -> AddEntry (grhist_10muA , "Counts With Background , 10 #muA" , "p");
  legAll -> AddEntry (grcountsM_10muA , "UCN Counts Without Background , 10 #muA" , "p");
  legAll -> SetTextSize(0.03);
  
  //grhist_1muA -> Draw("Ap");
  grcountsM_1muA -> Draw("Ap");
  grcountsM_1muA -> Fit("f1");
  //grhist_3muA -> Draw("p");
  grcountsM_3muA -> Draw("p");
  //grhist_5muA -> Draw("p");
  grcountsM_5muA -> Draw("P");
  //grhist_7muA -> Draw("p");
  grcountsM_7muA -> Draw("p");
  //grhist_10muA -> Draw("p");
  grcountsM_10muA -> Draw("p");
  legAll -> Draw();
  #endif

  TCanvas *c1muA_temp = new TCanvas("c1muA_temp" , "c1muA_temp" , 1200, 900);
  //c1muA_temp -> SetLogy();
  c1muA_temp -> Divide(2,3);

  c1muA_temp -> cd(1);
  TPad *pad1 = c1muA_temp->cd(1);
  pad1->SetLogy(); 
  TGraphErrors *gr1muA_Irradtemp11 = new TGraphErrors(counts_1muA, avets11IrradArray_1muA,UCNIntegralManualArray_1muA, avets11IrradErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_Irradtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_Irradtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_Irradtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_Irradtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_Irradtemp11 -> SetMarkerStyle(20);
  gr1muA_Irradtemp11 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr1muA_Irradtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_Irradtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_Irradtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_Irradtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_Irradtemp11 -> SetMarkerColor(1);

  TGraphErrors *gr1muA_VOtemp11 = new TGraphErrors(counts_1muA, avets11VOArray_1muA,UCNIntegralManualArray_1muA, avets11VOErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_VOtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_VOtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_VOtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_VOtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_VOtemp11 -> SetMarkerStyle(24);
  gr1muA_VOtemp11 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr1muA_VOtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_VOtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_VOtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_VOtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_VOtemp11 -> SetMarkerColor(1);


  TGraphErrors *gr1muA_Irradtemp12 = new TGraphErrors(counts_1muA, avets12IrradArray_1muA,UCNIntegralManualArray_1muA, avets12IrradErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_Irradtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_Irradtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_Irradtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_Irradtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_Irradtemp12 -> SetMarkerStyle(20);
  gr1muA_Irradtemp12 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr1muA_Irradtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_Irradtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_Irradtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_Irradtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_Irradtemp12 -> SetMarkerColor(2);

  TGraphErrors *gr1muA_VOtemp12 = new TGraphErrors(counts_1muA, avets12VOArray_1muA,UCNIntegralManualArray_1muA, avets12VOErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_VOtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_VOtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_VOtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_VOtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_VOtemp12 -> SetMarkerStyle(24);
  gr1muA_VOtemp12 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr1muA_VOtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_VOtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_VOtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_VOtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_VOtemp12 -> SetMarkerColor(2);


  TGraphErrors *gr1muA_Irradtemp14 = new TGraphErrors(counts_1muA, avets14IrradArray_1muA,UCNIntegralManualArray_1muA, avets14IrradErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_Irradtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_Irradtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_Irradtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_Irradtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_Irradtemp14 -> SetMarkerStyle(20);
  gr1muA_Irradtemp14 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr1muA_Irradtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_Irradtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_Irradtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_Irradtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_Irradtemp14 -> SetMarkerColor(4);

  TGraphErrors *gr1muA_VOtemp14 = new TGraphErrors(counts_1muA, avets14VOArray_1muA,UCNIntegralManualArray_1muA, avets14VOErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_VOtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_VOtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_VOtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_VOtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_VOtemp14 -> SetMarkerStyle(24);
  gr1muA_VOtemp14 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr1muA_VOtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_VOtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_VOtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_VOtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_VOtemp14 -> SetMarkerColor(4);


  TGraphErrors *gr1muA_Irradtemp16 = new TGraphErrors(counts_1muA, avets16IrradArray_1muA,UCNIntegralManualArray_1muA, avets16IrradErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_Irradtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_Irradtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_Irradtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_Irradtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_Irradtemp16 -> SetMarkerStyle(20);
  gr1muA_Irradtemp16 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr1muA_Irradtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_Irradtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_Irradtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_Irradtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_Irradtemp16 -> SetMarkerColor(8);

  TGraphErrors *gr1muA_VOtemp16 = new TGraphErrors(counts_1muA, avets16VOArray_1muA,UCNIntegralManualArray_1muA, avets16VOErrArray_1muA,  UCNIntegralManualErrArray_1muA);
  gr1muA_VOtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr1muA_VOtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr1muA_VOtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA_VOtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr1muA_VOtemp16 -> SetMarkerStyle(24);
  gr1muA_VOtemp16 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr1muA_VOtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_VOtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_VOtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_VOtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_VOtemp16 -> SetMarkerColor(8);

  TLegend *legtemp_1muA = new TLegend (0.7, 0.6, 0.9, 0.9);
  legtemp_1muA -> AddEntry(gr1muA_Irradtemp11, "TS11, During Irradiation , 1.5 #muA", "P");
  legtemp_1muA -> AddEntry(gr1muA_VOtemp11 , "TS11, During Valve Open , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_Irradtemp12, "TS12, During Irradiation , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_VOtemp12, "TS12, During Valve Open , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_Irradtemp14, "TS14, During Irradiation , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_VOtemp14, "TS14, During Valve Open , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_Irradtemp16, "TS16, During Irradiation , 1.5 #muA" , "P");
  legtemp_1muA -> AddEntry(gr1muA_VOtemp16, "TS16, During Valve Open , 1.5 #muA" , "P");

  
   TText *t1 = new TText(.5,.5,"1.5 #muA ");
   t1->SetTextAlign(22);
   //t1->SetTextColor(kRed+2);
   t1->SetTextFont(43);
   t1->SetTextSize(40);
   //t1->SetTextAngle(45);
   t1->Draw();
  
  gr1muA_Irradtemp11 -> Draw("AP");
  gr1muA_VOtemp11 -> Draw("p");
  gr1muA_Irradtemp12 -> Draw("P");
  gr1muA_VOtemp12 -> Draw("P");
  gr1muA_Irradtemp14 -> Draw("P");
  gr1muA_VOtemp14 -> Draw("P");
  gr1muA_Irradtemp16 -> Draw("P");
  gr1muA_VOtemp16 -> Draw("P");
  legtemp_1muA -> Draw();


  // 3muA
  //TCanvas *c3muA_temp = new TCanvas("c3muA_temp" , "c3muA_temp" , 1200, 900);
  //c3muA_temp -> SetLogy();
  c1muA_temp -> cd(2);
  TPad *pad2 = c1muA_temp->cd(2);
  pad2->SetLogy(); 
  TGraphErrors *gr3muA_Irradtemp11 = new TGraphErrors(counts_3muA, avets11IrradArray_3muA,UCNIntegralManualArray_3muA, avets11IrradErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_Irradtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_Irradtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_Irradtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_Irradtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_Irradtemp11 -> SetMarkerStyle(20);
  gr3muA_Irradtemp11 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr3muA_Irradtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_Irradtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_Irradtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_Irradtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_Irradtemp11 -> SetMarkerColor(1);

  TGraphErrors *gr3muA_VOtemp11 = new TGraphErrors(counts_3muA, avets11VOArray_3muA,UCNIntegralManualArray_3muA, avets11VOErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_VOtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_VOtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_VOtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_VOtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_VOtemp11 -> SetMarkerStyle(24);
  gr3muA_VOtemp11 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr3muA_VOtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_VOtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_VOtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_VOtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_VOtemp11 -> SetMarkerColor(1);


  TGraphErrors *gr3muA_Irradtemp12 = new TGraphErrors(counts_3muA, avets12IrradArray_3muA,UCNIntegralManualArray_3muA, avets12IrradErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_Irradtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_Irradtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_Irradtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_Irradtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_Irradtemp12 -> SetMarkerStyle(20);
  gr3muA_Irradtemp12 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr3muA_Irradtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_Irradtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_Irradtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_Irradtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_Irradtemp12 -> SetMarkerColor(2);

  TGraphErrors *gr3muA_VOtemp12 = new TGraphErrors(counts_3muA, avets12VOArray_3muA,UCNIntegralManualArray_3muA, avets12VOErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_VOtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_VOtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_VOtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_VOtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_VOtemp12 -> SetMarkerStyle(24);
  gr3muA_VOtemp12 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr3muA_VOtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_VOtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_VOtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_VOtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_VOtemp12 -> SetMarkerColor(2);


  TGraphErrors *gr3muA_Irradtemp14 = new TGraphErrors(counts_3muA, avets14IrradArray_3muA,UCNIntegralManualArray_3muA, avets14IrradErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_Irradtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_Irradtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_Irradtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_Irradtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_Irradtemp14 -> SetMarkerStyle(20);
  gr3muA_Irradtemp14 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr3muA_Irradtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_Irradtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_Irradtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_Irradtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_Irradtemp14 -> SetMarkerColor(4);

  TGraphErrors *gr3muA_VOtemp14 = new TGraphErrors(counts_3muA, avets14VOArray_3muA,UCNIntegralManualArray_3muA, avets14VOErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_VOtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_VOtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_VOtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_VOtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_VOtemp14 -> SetMarkerStyle(24);
  gr3muA_VOtemp14 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr3muA_VOtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_VOtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_VOtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_VOtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_VOtemp14 -> SetMarkerColor(4);


  TGraphErrors *gr3muA_Irradtemp16 = new TGraphErrors(counts_3muA, avets16IrradArray_3muA,UCNIntegralManualArray_3muA, avets16IrradErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_Irradtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_Irradtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_Irradtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_Irradtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_Irradtemp16 -> SetMarkerStyle(20);
  gr3muA_Irradtemp16 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr3muA_Irradtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_Irradtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_Irradtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_Irradtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_Irradtemp16 -> SetMarkerColor(8);

  TGraphErrors *gr3muA_VOtemp16 = new TGraphErrors(counts_3muA, avets16VOArray_3muA,UCNIntegralManualArray_3muA, avets16VOErrArray_3muA,  UCNIntegralManualErrArray_3muA);
  gr3muA_VOtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr3muA_VOtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr3muA_VOtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA_VOtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr3muA_VOtemp16 -> SetMarkerStyle(24);
  gr3muA_VOtemp16 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr3muA_VOtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_VOtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_VOtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_VOtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_VOtemp16 -> SetMarkerColor(8);

  TLegend *legtemp_3muA = new TLegend (0.7, 0.6, 0.9, 0.9);
  legtemp_3muA -> AddEntry(gr3muA_Irradtemp11, "TS11, During Irradiation , 3 #muA", "P");
  legtemp_3muA -> AddEntry(gr3muA_VOtemp11 , "TS11, During Valve Open , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_Irradtemp12, "TS12, During Irradiation , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_VOtemp12, "TS12, During Valve Open , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_Irradtemp14, "TS14, During Irradiation , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_VOtemp14, "TS14, During Valve Open , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_Irradtemp16, "TS16, During Irradiation , 3 #muA" , "P");
  legtemp_3muA -> AddEntry(gr3muA_VOtemp16, "TS16, During Valve Open , 3 #muA" , "P");

  TText *t2 = new TText(.5,.5,"3 #muA ");
   t2->SetTextAlign(22);
   //t1->SetTextColor(kRed+2);
   t2->SetTextFont(43);
   t2->SetTextSize(40);
   //t1->SetTextAngle(45);
   t2->Draw();
  
  gr3muA_Irradtemp11 -> Draw("AP");
  gr3muA_VOtemp11 -> Draw("p");
  gr3muA_Irradtemp12 -> Draw("P");
  gr3muA_VOtemp12 -> Draw("P");
  gr3muA_Irradtemp14 -> Draw("P");
  gr3muA_VOtemp14 -> Draw("P");
  gr3muA_Irradtemp16 -> Draw("P");
  gr3muA_VOtemp16 -> Draw("P");
  legtemp_3muA -> Draw();


  // 5muA
  c1muA_temp -> cd(3);
  TPad *pad3 = c1muA_temp->cd(3);
  pad3->SetLogy(); 
  TGraphErrors *gr5muA_Irradtemp11 = new TGraphErrors(counts_5muA, avets11IrradArray_5muA,UCNIntegralManualArray_5muA, avets11IrradErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_Irradtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_Irradtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_Irradtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_Irradtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_Irradtemp11 -> SetMarkerStyle(20);
  gr5muA_Irradtemp11 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr5muA_Irradtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_Irradtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_Irradtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_Irradtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_Irradtemp11 -> SetMarkerColor(1);

  TGraphErrors *gr5muA_VOtemp11 = new TGraphErrors(counts_5muA, avets11VOArray_5muA,UCNIntegralManualArray_5muA, avets11VOErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_VOtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_VOtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_VOtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_VOtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_VOtemp11 -> SetMarkerStyle(24);
  gr5muA_VOtemp11 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr5muA_VOtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_VOtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_VOtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_VOtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_VOtemp11 -> SetMarkerColor(1);


  TGraphErrors *gr5muA_Irradtemp12 = new TGraphErrors(counts_5muA, avets12IrradArray_5muA,UCNIntegralManualArray_5muA, avets12IrradErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_Irradtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_Irradtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_Irradtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_Irradtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_Irradtemp12 -> SetMarkerStyle(20);
  gr5muA_Irradtemp12 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr5muA_Irradtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_Irradtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_Irradtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_Irradtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_Irradtemp12 -> SetMarkerColor(2);

  TGraphErrors *gr5muA_VOtemp12 = new TGraphErrors(counts_5muA, avets12VOArray_5muA,UCNIntegralManualArray_5muA, avets12VOErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_VOtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_VOtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_VOtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_VOtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_VOtemp12 -> SetMarkerStyle(24);
  gr5muA_VOtemp12 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr5muA_VOtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_VOtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_VOtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_VOtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_VOtemp12 -> SetMarkerColor(2);


  TGraphErrors *gr5muA_Irradtemp14 = new TGraphErrors(counts_5muA, avets14IrradArray_5muA,UCNIntegralManualArray_5muA, avets14IrradErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_Irradtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_Irradtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_Irradtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_Irradtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_Irradtemp14 -> SetMarkerStyle(20);
  gr5muA_Irradtemp14 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr5muA_Irradtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_Irradtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_Irradtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_Irradtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_Irradtemp14 -> SetMarkerColor(4);

  TGraphErrors *gr5muA_VOtemp14 = new TGraphErrors(counts_5muA, avets14VOArray_5muA,UCNIntegralManualArray_5muA, avets14VOErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_VOtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_VOtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_VOtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_VOtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_VOtemp14 -> SetMarkerStyle(24);
  gr5muA_VOtemp14 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr5muA_VOtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_VOtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_VOtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_VOtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_VOtemp14 -> SetMarkerColor(4);


  TGraphErrors *gr5muA_Irradtemp16 = new TGraphErrors(counts_5muA, avets16IrradArray_5muA,UCNIntegralManualArray_5muA, avets16IrradErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_Irradtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_Irradtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_Irradtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_Irradtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_Irradtemp16 -> SetMarkerStyle(20);
  gr5muA_Irradtemp16 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr5muA_Irradtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_Irradtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_Irradtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_Irradtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_Irradtemp16 -> SetMarkerColor(8);

  TGraphErrors *gr5muA_VOtemp16 = new TGraphErrors(counts_5muA, avets16VOArray_5muA,UCNIntegralManualArray_5muA, avets16VOErrArray_5muA,  UCNIntegralManualErrArray_5muA);
  gr5muA_VOtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr5muA_VOtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr5muA_VOtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA_VOtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr5muA_VOtemp16 -> SetMarkerStyle(24);
  gr5muA_VOtemp16 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr5muA_VOtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_VOtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_VOtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_VOtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_VOtemp16 -> SetMarkerColor(8);

  TLegend *legtemp_5muA = new TLegend (0.7, 0.6, 0.9, 0.9);
  legtemp_5muA -> AddEntry(gr5muA_Irradtemp11, "TS11, During Irradiation , 5 #muA", "P");
  legtemp_5muA -> AddEntry(gr5muA_VOtemp11 , "TS11, During Valve Open , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_Irradtemp12, "TS12, During Irradiation , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_VOtemp12, "TS12, During Valve Open , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_Irradtemp14, "TS14, During Irradiation , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_VOtemp14, "TS14, During Valve Open , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_Irradtemp16, "TS16, During Irradiation , 5 #muA" , "P");
  legtemp_5muA -> AddEntry(gr5muA_VOtemp16, "TS16, During Valve Open , 5 #muA" , "P");

  TText *t3 = new TText(.5,.5,"5 #muA ");
   t3->SetTextAlign(22);
   //t1->SetTextColor(kRed+2);
   t3->SetTextFont(43);
   t3->SetTextSize(40);
   //t1->SetTextAngle(45);
   t3->Draw();
  
  gr5muA_Irradtemp11 -> Draw("AP");
  gr5muA_VOtemp11 -> Draw("p");
  gr5muA_Irradtemp12 -> Draw("P");
  gr5muA_VOtemp12 -> Draw("P");
  gr5muA_Irradtemp14 -> Draw("P");
  gr5muA_VOtemp14 -> Draw("P");
  gr5muA_Irradtemp16 -> Draw("P");
  gr5muA_VOtemp16 -> Draw("P");
  legtemp_5muA -> Draw();

  //7muA
  c1muA_temp -> cd(4);
  TPad *pad4 = c1muA_temp->cd(4);
  pad4->SetLogy(); 
  TGraphErrors *gr7muA_Irradtemp11 = new TGraphErrors(counts_7muA, avets11IrradArray_7muA,UCNIntegralManualArray_7muA, avets11IrradErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_Irradtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_Irradtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_Irradtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_Irradtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_Irradtemp11 -> SetMarkerStyle(20);
  gr7muA_Irradtemp11 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr7muA_Irradtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_Irradtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_Irradtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_Irradtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_Irradtemp11 -> SetMarkerColor(1);

  TGraphErrors *gr7muA_VOtemp11 = new TGraphErrors(counts_7muA, avets11VOArray_7muA,UCNIntegralManualArray_7muA, avets11VOErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_VOtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_VOtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_VOtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_VOtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_VOtemp11 -> SetMarkerStyle(24);
  gr7muA_VOtemp11 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr7muA_VOtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_VOtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_VOtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_VOtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_VOtemp11 -> SetMarkerColor(1);


  TGraphErrors *gr7muA_Irradtemp12 = new TGraphErrors(counts_7muA, avets12IrradArray_7muA,UCNIntegralManualArray_7muA, avets12IrradErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_Irradtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_Irradtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_Irradtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_Irradtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_Irradtemp12 -> SetMarkerStyle(20);
  gr7muA_Irradtemp12 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr7muA_Irradtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_Irradtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_Irradtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_Irradtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_Irradtemp12 -> SetMarkerColor(2);

  TGraphErrors *gr7muA_VOtemp12 = new TGraphErrors(counts_7muA, avets12VOArray_7muA,UCNIntegralManualArray_7muA, avets12VOErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_VOtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_VOtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_VOtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_VOtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_VOtemp12 -> SetMarkerStyle(24);
  gr7muA_VOtemp12 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr7muA_VOtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_VOtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_VOtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_VOtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_VOtemp12 -> SetMarkerColor(2);


  TGraphErrors *gr7muA_Irradtemp14 = new TGraphErrors(counts_7muA, avets14IrradArray_7muA,UCNIntegralManualArray_7muA, avets14IrradErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_Irradtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_Irradtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_Irradtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_Irradtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_Irradtemp14 -> SetMarkerStyle(20);
  gr7muA_Irradtemp14 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr7muA_Irradtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_Irradtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_Irradtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_Irradtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_Irradtemp14 -> SetMarkerColor(4);

  TGraphErrors *gr7muA_VOtemp14 = new TGraphErrors(counts_7muA, avets14VOArray_7muA,UCNIntegralManualArray_7muA, avets14VOErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_VOtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_VOtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_VOtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_VOtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_VOtemp14 -> SetMarkerStyle(24);
  gr7muA_VOtemp14 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr7muA_VOtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_VOtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_VOtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_VOtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_VOtemp14 -> SetMarkerColor(4);


  TGraphErrors *gr7muA_Irradtemp16 = new TGraphErrors(counts_7muA, avets16IrradArray_7muA,UCNIntegralManualArray_7muA, avets16IrradErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_Irradtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_Irradtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_Irradtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_Irradtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_Irradtemp16 -> SetMarkerStyle(20);
  gr7muA_Irradtemp16 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr7muA_Irradtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_Irradtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_Irradtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_Irradtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_Irradtemp16 -> SetMarkerColor(8);

  TGraphErrors *gr7muA_VOtemp16 = new TGraphErrors(counts_7muA, avets16VOArray_7muA,UCNIntegralManualArray_7muA, avets16VOErrArray_7muA,  UCNIntegralManualErrArray_7muA);
  gr7muA_VOtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr7muA_VOtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr7muA_VOtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA_VOtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr7muA_VOtemp16 -> SetMarkerStyle(24);
  gr7muA_VOtemp16 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr7muA_VOtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_VOtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_VOtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_VOtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_VOtemp16 -> SetMarkerColor(8);

  TLegend *legtemp_7muA = new TLegend (0.7, 0.6, 0.9, 0.9);
  legtemp_7muA -> AddEntry(gr7muA_Irradtemp11, "TS11, During Irradiation , 7.1 #muA", "P");
  legtemp_7muA -> AddEntry(gr7muA_VOtemp11 , "TS11, During Valve Open , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_Irradtemp12, "TS12, During Irradiation , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_VOtemp12, "TS12, During Valve Open , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_Irradtemp14, "TS14, During Irradiation , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_VOtemp14, "TS14, During Valve Open , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_Irradtemp16, "TS16, During Irradiation , 7.1 #muA" , "P");
  legtemp_7muA -> AddEntry(gr7muA_VOtemp16, "TS16, During Valve Open , 7.1 #muA" , "P");

  TText *t4 = new TText(.5,.5,"7.1 #muA ");
  t4->SetTextAlign(22);
  //t1->SetTextColor(kRed+2);
  t4->SetTextFont(43);
  t4->SetTextSize(40);
  //t1->SetTextAngle(45);
  t4->Draw();
  
  gr7muA_Irradtemp11 -> Draw("AP");
  gr7muA_VOtemp11 -> Draw("p");
  gr7muA_Irradtemp12 -> Draw("P");
  gr7muA_VOtemp12 -> Draw("P");
  gr7muA_Irradtemp14 -> Draw("P");
  gr7muA_VOtemp14 -> Draw("P");
  gr7muA_Irradtemp16 -> Draw("P");
  gr7muA_VOtemp16 -> Draw("P");
  legtemp_7muA -> Draw();

  // 10muA
  c1muA_temp -> cd(5);
  TPad *pad5 = c1muA_temp->cd(5);
  pad5->SetLogy(); 
  TGraphErrors *gr10muA_Irradtemp11 = new TGraphErrors(counts_10muA, avets11IrradArray_10muA,UCNIntegralManualArray_10muA, avets11IrradErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_Irradtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_Irradtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_Irradtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_Irradtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_Irradtemp11 -> SetMarkerStyle(20);
  gr10muA_Irradtemp11 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr10muA_Irradtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_Irradtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_Irradtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_Irradtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_Irradtemp11 -> SetMarkerColor(1);

  TGraphErrors *gr10muA_VOtemp11 = new TGraphErrors(counts_10muA, avets11VOArray_10muA,UCNIntegralManualArray_10muA, avets11VOErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_VOtemp11 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_VOtemp11 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_VOtemp11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_VOtemp11 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_VOtemp11 -> SetMarkerStyle(24);
  gr10muA_VOtemp11 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr10muA_VOtemp11 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_VOtemp11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_VOtemp11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_VOtemp11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_VOtemp11 -> SetMarkerColor(1);


  TGraphErrors *gr10muA_Irradtemp12 = new TGraphErrors(counts_10muA, avets12IrradArray_10muA,UCNIntegralManualArray_10muA, avets12IrradErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_Irradtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_Irradtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_Irradtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_Irradtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_Irradtemp12 -> SetMarkerStyle(20);
  gr10muA_Irradtemp12 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr10muA_Irradtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_Irradtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_Irradtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_Irradtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_Irradtemp12 -> SetMarkerColor(2);

  TGraphErrors *gr10muA_VOtemp12 = new TGraphErrors(counts_10muA, avets12VOArray_10muA,UCNIntegralManualArray_10muA, avets12VOErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_VOtemp12 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_VOtemp12 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_VOtemp12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_VOtemp12 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_VOtemp12 -> SetMarkerStyle(24);
  gr10muA_VOtemp12 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr10muA_VOtemp12 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_VOtemp12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_VOtemp12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_VOtemp12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_VOtemp12 -> SetMarkerColor(2);


  TGraphErrors *gr10muA_Irradtemp14 = new TGraphErrors(counts_10muA, avets14IrradArray_10muA,UCNIntegralManualArray_10muA, avets14IrradErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_Irradtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_Irradtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_Irradtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_Irradtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_Irradtemp14 -> SetMarkerStyle(20);
  gr10muA_Irradtemp14 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr10muA_Irradtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_Irradtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_Irradtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_Irradtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_Irradtemp14 -> SetMarkerColor(4);

  TGraphErrors *gr10muA_VOtemp14 = new TGraphErrors(counts_10muA, avets14VOArray_10muA,UCNIntegralManualArray_10muA, avets14VOErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_VOtemp14 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_VOtemp14 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_VOtemp14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_VOtemp14 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_VOtemp14 -> SetMarkerStyle(24);
  gr10muA_VOtemp14 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr10muA_VOtemp14 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_VOtemp14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_VOtemp14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_VOtemp14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_VOtemp14 -> SetMarkerColor(4);


  TGraphErrors *gr10muA_Irradtemp16 = new TGraphErrors(counts_10muA, avets16IrradArray_10muA,UCNIntegralManualArray_10muA, avets16IrradErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_Irradtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_Irradtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_Irradtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_Irradtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_Irradtemp16 -> SetMarkerStyle(20);
  gr10muA_Irradtemp16 -> GetXaxis()-> SetLimits(0.8, 1.40);
  gr10muA_Irradtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_Irradtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_Irradtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_Irradtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_Irradtemp16 -> SetMarkerColor(8);

  TGraphErrors *gr10muA_VOtemp16 = new TGraphErrors(counts_10muA, avets16VOArray_10muA,UCNIntegralManualArray_10muA, avets16VOErrArray_10muA,  UCNIntegralManualErrArray_10muA);
  gr10muA_VOtemp16 -> SetTitle( "UCN Counts vs Isopure Helium Temperature");
  gr10muA_VOtemp16 -> GetXaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  gr10muA_VOtemp16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA_VOtemp16 -> GetYaxis() -> SetRangeUser (100, 7000000);
  gr10muA_VOtemp16 -> SetMarkerStyle(24);
  gr10muA_VOtemp16 -> GetXaxis()-> SetLimits(0.8, 1.4);
  gr10muA_VOtemp16 -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_VOtemp16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_VOtemp16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_VOtemp16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_VOtemp16 -> SetMarkerColor(8);

  TLegend *legtemp_10muA = new TLegend (0.7, 0.6, 0.9, 0.9);
  legtemp_10muA -> AddEntry(gr10muA_Irradtemp11, "TS11, During Irradiation , 10 #muA", "P");
  legtemp_10muA -> AddEntry(gr10muA_VOtemp11 , "TS11, During Valve Open , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_Irradtemp12, "TS12, During Irradiation , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_VOtemp12, "TS12, During Valve Open , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_Irradtemp14, "TS14, During Irradiation , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_VOtemp14, "TS14, During Valve Open , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_Irradtemp16, "TS16, During Irradiation , 10 #muA" , "P");
  legtemp_10muA -> AddEntry(gr10muA_VOtemp16, "TS16, During Valve Open , 10 #muA" , "P");

  TText *t5 = new TText(0.5,0.5,"10 #muA ");
  t5->SetTextAlign(22);
  //t1->SetTextColor(kRed+2);
  t5->SetTextFont(43);
  t5->SetTextSize(40);
  //t1->SetTextAngle(45);
  t5->Draw();
  
  gr10muA_Irradtemp11 -> Draw("AP");
  gr10muA_VOtemp11 -> Draw("p");
  gr10muA_Irradtemp12 -> Draw("P");
  gr10muA_VOtemp12 -> Draw("P");
  gr10muA_Irradtemp14 -> Draw("P");
  gr10muA_VOtemp14 -> Draw("P");
  gr10muA_Irradtemp16 -> Draw("P");
  gr10muA_VOtemp16 -> Draw("P");
  legtemp_10muA -> Draw();

  // temperature vs irradiation time at different beam current

  TCanvas *ctemp_irrad = new TCanvas("ctemp_irrad" , "ctemp_irrad", 1200, 900);
  ctemp_irrad -> Divide(2,3);

  
  //1.5 muA


  ctemp_irrad -> cd(1);
  TGraphErrors *grtemp11irrad_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets11IrradArray_1muA , 0 , avets11IrradErrArray_1muA);
  grtemp11irrad_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11irrad_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11irrad_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11irrad_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11irrad_1muA -> SetMarkerStyle(20);
  grtemp11irrad_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11irrad_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11irrad_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11irrad_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11irrad_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11irrad_1muA -> SetMarkerColor(1);


  TGraphErrors *grtemp11VO_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets11VOArray_1muA , 0 , avets11VOErrArray_1muA);
  grtemp11VO_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11VO_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11VO_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11VO_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11VO_1muA -> SetMarkerStyle(24);
  grtemp11VO_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11VO_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11VO_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11VO_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11VO_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11VO_1muA -> SetMarkerColor(1);



  TGraphErrors *grtemp12irrad_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets12IrradArray_1muA , 0 , avets12IrradErrArray_1muA);
  grtemp12irrad_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12irrad_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12irrad_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12irrad_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12irrad_1muA -> SetMarkerStyle(20);
  grtemp12irrad_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12irrad_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12irrad_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12irrad_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12irrad_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12irrad_1muA -> SetMarkerColor(2);


  TGraphErrors *grtemp12VO_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets12VOArray_1muA , 0 , avets12VOErrArray_1muA);
  grtemp12VO_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12VO_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12VO_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12VO_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12VO_1muA -> SetMarkerStyle(24);
  grtemp12VO_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12VO_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12VO_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12VO_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12VO_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12VO_1muA -> SetMarkerColor(2);



  TGraphErrors *grtemp14irrad_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets14IrradArray_1muA , 0 , avets14IrradErrArray_1muA);
  grtemp14irrad_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14irrad_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14irrad_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14irrad_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14irrad_1muA -> SetMarkerStyle(20);
  grtemp14irrad_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14irrad_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14irrad_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14irrad_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14irrad_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14irrad_1muA -> SetMarkerColor(4);


  TGraphErrors *grtemp14VO_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets14VOArray_1muA , 0 , avets14VOErrArray_1muA);
  grtemp14VO_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14VO_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14VO_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14VO_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14VO_1muA -> SetMarkerStyle(24);
  grtemp14VO_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14VO_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14VO_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14VO_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14VO_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14VO_1muA -> SetMarkerColor(4);


  TGraphErrors *grtemp16irrad_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets16IrradArray_1muA , 0 , avets16IrradErrArray_1muA);
  grtemp16irrad_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16irrad_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16irrad_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16irrad_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16irrad_1muA -> SetMarkerStyle(20);
  grtemp16irrad_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16irrad_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16irrad_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16irrad_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16irrad_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16irrad_1muA -> SetMarkerColor(8);


  TGraphErrors *grtemp16VO_1muA = new TGraphErrors(counts_1muA, irradtimeArray_1muA, avets16VOArray_1muA , 0 , avets16VOErrArray_1muA);
  grtemp16VO_1muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16VO_1muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16VO_1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16VO_1muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16VO_1muA -> SetMarkerStyle(24);
  grtemp16VO_1muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16VO_1muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16VO_1muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16VO_1muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16VO_1muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16VO_1muA -> SetMarkerColor(8);
  

  grtemp12irrad_1muA -> Draw("Ap");
  grtemp12VO_1muA -> Draw("P");
  //grtemp11irrad_1muA -> Draw("p");
  //grtemp11VO_1muA -> Draw("P");
  //grtemp14irrad_1muA -> Draw("p");
  //grtemp14VO_1muA -> Draw("P");
  //grtemp16irrad_1muA -> Draw("p");
  //grtemp16VO_1muA -> Draw("P");
  //legtemp_1muA -> Draw();

  // 3muA
  ctemp_irrad -> cd(2);
  TGraphErrors *grtemp11irrad_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets11IrradArray_3muA , 0 , avets11IrradErrArray_3muA);
  grtemp11irrad_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11irrad_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11irrad_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11irrad_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11irrad_3muA -> SetMarkerStyle(20);
  grtemp11irrad_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11irrad_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11irrad_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11irrad_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11irrad_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11irrad_3muA -> SetMarkerColor(1);


  TGraphErrors *grtemp11VO_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets11VOArray_3muA , 0 , avets11VOErrArray_3muA);
  grtemp11VO_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11VO_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11VO_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11VO_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11VO_3muA -> SetMarkerStyle(24);
  grtemp11VO_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11VO_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11VO_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11VO_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11VO_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11VO_3muA -> SetMarkerColor(1);



  TGraphErrors *grtemp12irrad_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets12IrradArray_3muA , 0 , avets12IrradErrArray_3muA);
  grtemp12irrad_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12irrad_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12irrad_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12irrad_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12irrad_3muA -> SetMarkerStyle(20);
  grtemp12irrad_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12irrad_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12irrad_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12irrad_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12irrad_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12irrad_3muA -> SetMarkerColor(2);


  TGraphErrors *grtemp12VO_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets12VOArray_3muA , 0 , avets12VOErrArray_3muA);
  grtemp12VO_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12VO_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12VO_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12VO_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12VO_3muA -> SetMarkerStyle(24);
  grtemp12VO_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12VO_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12VO_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12VO_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12VO_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12VO_3muA -> SetMarkerColor(2);



  TGraphErrors *grtemp14irrad_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets14IrradArray_3muA , 0 , avets14IrradErrArray_3muA);
  grtemp14irrad_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14irrad_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14irrad_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14irrad_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14irrad_3muA -> SetMarkerStyle(20);
  grtemp14irrad_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14irrad_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14irrad_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14irrad_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14irrad_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14irrad_3muA -> SetMarkerColor(4);


  TGraphErrors *grtemp14VO_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets14VOArray_3muA , 0 , avets14VOErrArray_3muA);
  grtemp14VO_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14VO_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14VO_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14VO_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14VO_3muA -> SetMarkerStyle(24);
  grtemp14VO_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14VO_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14VO_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14VO_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14VO_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14VO_3muA -> SetMarkerColor(4);


  TGraphErrors *grtemp16irrad_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets16IrradArray_3muA , 0 , avets16IrradErrArray_3muA);
  grtemp16irrad_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16irrad_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16irrad_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16irrad_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16irrad_3muA -> SetMarkerStyle(20);
  grtemp16irrad_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16irrad_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16irrad_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16irrad_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16irrad_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16irrad_3muA -> SetMarkerColor(8);


  TGraphErrors *grtemp16VO_3muA = new TGraphErrors(counts_3muA, irradtimeArray_3muA, avets16VOArray_3muA , 0 , avets16VOErrArray_3muA);
  grtemp16VO_3muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16VO_3muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16VO_3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16VO_3muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16VO_3muA -> SetMarkerStyle(24);
  grtemp16VO_3muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16VO_3muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16VO_3muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16VO_3muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16VO_3muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16VO_3muA -> SetMarkerColor(8);
  

  grtemp12irrad_3muA -> Draw("Ap");
  grtemp12VO_3muA -> Draw("P");
  //grtemp11irrad_3muA -> Draw("p");
  //grtemp11VO_3muA -> Draw("P");
  //grtemp14irrad_3muA -> Draw("p");
  //grtemp14VO_3muA -> Draw("P");
  //grtemp16irrad_3muA -> Draw("p");
  //grtemp16VO_3muA -> Draw("P");
  //legtemp_3muA -> Draw();

  // 5muA
  ctemp_irrad -> cd(3);
  TGraphErrors *grtemp11irrad_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets11IrradArray_5muA , 0 , avets11IrradErrArray_5muA);
  grtemp11irrad_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11irrad_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11irrad_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11irrad_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11irrad_5muA -> SetMarkerStyle(20);
  grtemp11irrad_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11irrad_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11irrad_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11irrad_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11irrad_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11irrad_5muA -> SetMarkerColor(1);


  TGraphErrors *grtemp11VO_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets11VOArray_5muA , 0 , avets11VOErrArray_5muA);
  grtemp11VO_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11VO_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11VO_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11VO_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11VO_5muA -> SetMarkerStyle(24);
  grtemp11VO_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11VO_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11VO_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11VO_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11VO_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11VO_5muA -> SetMarkerColor(1);



  TGraphErrors *grtemp12irrad_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets12IrradArray_5muA , 0 , avets12IrradErrArray_5muA);
  grtemp12irrad_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12irrad_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12irrad_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12irrad_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12irrad_5muA -> SetMarkerStyle(20);
  grtemp12irrad_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12irrad_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12irrad_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12irrad_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12irrad_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12irrad_5muA -> SetMarkerColor(2);


  TGraphErrors *grtemp12VO_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets12VOArray_5muA , 0 , avets12VOErrArray_5muA);
  grtemp12VO_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12VO_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12VO_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12VO_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12VO_5muA -> SetMarkerStyle(24);
  grtemp12VO_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12VO_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12VO_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12VO_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12VO_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12VO_5muA -> SetMarkerColor(2);



  TGraphErrors *grtemp14irrad_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets14IrradArray_5muA , 0 , avets14IrradErrArray_5muA);
  grtemp14irrad_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14irrad_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14irrad_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14irrad_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14irrad_5muA -> SetMarkerStyle(20);
  grtemp14irrad_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14irrad_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14irrad_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14irrad_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14irrad_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14irrad_5muA -> SetMarkerColor(4);


  TGraphErrors *grtemp14VO_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets14VOArray_5muA , 0 , avets14VOErrArray_5muA);
  grtemp14VO_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14VO_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14VO_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14VO_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14VO_5muA -> SetMarkerStyle(24);
  grtemp14VO_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14VO_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14VO_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14VO_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14VO_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14VO_5muA -> SetMarkerColor(4);


  TGraphErrors *grtemp16irrad_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets16IrradArray_5muA , 0 , avets16IrradErrArray_5muA);
  grtemp16irrad_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16irrad_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16irrad_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16irrad_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16irrad_5muA -> SetMarkerStyle(20);
  grtemp16irrad_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16irrad_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16irrad_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16irrad_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16irrad_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16irrad_5muA -> SetMarkerColor(8);


  TGraphErrors *grtemp16VO_5muA = new TGraphErrors(counts_5muA, irradtimeArray_5muA, avets16VOArray_5muA , 0 , avets16VOErrArray_5muA);
  grtemp16VO_5muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16VO_5muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16VO_5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16VO_5muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16VO_5muA -> SetMarkerStyle(24);
  grtemp16VO_5muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16VO_5muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16VO_5muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16VO_5muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16VO_5muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16VO_5muA -> SetMarkerColor(8);
  

  grtemp12irrad_5muA -> Draw("Ap");
  grtemp12VO_5muA -> Draw("P");
  //grtemp11irrad_5muA -> Draw("p");
  //grtemp11VO_5muA -> Draw("P");
  //grtemp14irrad_5muA -> Draw("p");
  //grtemp14VO_5muA -> Draw("P");
  //grtemp16irrad_5muA -> Draw("p");
  //grtemp16VO_5muA -> Draw("P");
  //legtemp_5muA -> Draw();

  //7.1 muA
  ctemp_irrad -> cd(4);
  TGraphErrors *grtemp11irrad_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets11IrradArray_7muA , 0 , avets11IrradErrArray_7muA);
  grtemp11irrad_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11irrad_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11irrad_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11irrad_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11irrad_7muA -> SetMarkerStyle(20);
  grtemp11irrad_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11irrad_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11irrad_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11irrad_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11irrad_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11irrad_7muA -> SetMarkerColor(1);


  TGraphErrors *grtemp11VO_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets11VOArray_7muA , 0 , avets11VOErrArray_7muA);
  grtemp11VO_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11VO_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11VO_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11VO_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11VO_7muA -> SetMarkerStyle(24);
  grtemp11VO_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11VO_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11VO_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11VO_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11VO_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11VO_7muA -> SetMarkerColor(1);



  TGraphErrors *grtemp12irrad_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets12IrradArray_7muA , 0 , avets12IrradErrArray_7muA);
  grtemp12irrad_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12irrad_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12irrad_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12irrad_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12irrad_7muA -> SetMarkerStyle(20);
  grtemp12irrad_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12irrad_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12irrad_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12irrad_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12irrad_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12irrad_7muA -> SetMarkerColor(2);


  TGraphErrors *grtemp12VO_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets12VOArray_7muA , 0 , avets12VOErrArray_7muA);
  grtemp12VO_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12VO_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12VO_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12VO_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12VO_7muA -> SetMarkerStyle(24);
  grtemp12VO_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12VO_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12VO_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12VO_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12VO_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12VO_7muA -> SetMarkerColor(2);



  TGraphErrors *grtemp14irrad_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets14IrradArray_7muA , 0 , avets14IrradErrArray_7muA);
  grtemp14irrad_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14irrad_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14irrad_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14irrad_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14irrad_7muA -> SetMarkerStyle(20);
  grtemp14irrad_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14irrad_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14irrad_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14irrad_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14irrad_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14irrad_7muA -> SetMarkerColor(4);


  TGraphErrors *grtemp14VO_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets14VOArray_7muA , 0 , avets14VOErrArray_7muA);
  grtemp14VO_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14VO_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14VO_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14VO_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14VO_7muA -> SetMarkerStyle(24);
  grtemp14VO_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14VO_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14VO_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14VO_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14VO_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14VO_7muA -> SetMarkerColor(4);


  TGraphErrors *grtemp16irrad_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets16IrradArray_7muA , 0 , avets16IrradErrArray_7muA);
  grtemp16irrad_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16irrad_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16irrad_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16irrad_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16irrad_7muA -> SetMarkerStyle(20);
  grtemp16irrad_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16irrad_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16irrad_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16irrad_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16irrad_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16irrad_7muA -> SetMarkerColor(8);


  TGraphErrors *grtemp16VO_7muA = new TGraphErrors(counts_7muA, irradtimeArray_7muA, avets16VOArray_7muA , 0 , avets16VOErrArray_7muA);
  grtemp16VO_7muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16VO_7muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16VO_7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16VO_7muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16VO_7muA -> SetMarkerStyle(24);
  grtemp16VO_7muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16VO_7muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16VO_7muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16VO_7muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16VO_7muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16VO_7muA -> SetMarkerColor(8);
  

  grtemp12irrad_7muA -> Draw("Ap");
  grtemp12VO_7muA -> Draw("P");
  //grtemp11irrad_7muA -> Draw("p");
  //grtemp11VO_7muA -> Draw("P");
  //grtemp14irrad_7muA -> Draw("p");
  //grtemp14VO_7muA -> Draw("P");
  //grtemp16irrad_7muA -> Draw("p");
  //grtemp16VO_7muA -> Draw("P");
  //legtemp_7muA -> Draw();

  //10 muA
  ctemp_irrad -> cd(5);
  TGraphErrors *grtemp11irrad_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets11IrradArray_10muA , 0 , avets11IrradErrArray_10muA);
  grtemp11irrad_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11irrad_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11irrad_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11irrad_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11irrad_10muA -> SetMarkerStyle(20);
  grtemp11irrad_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11irrad_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11irrad_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11irrad_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11irrad_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11irrad_10muA -> SetMarkerColor(1);


  TGraphErrors *grtemp11VO_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets11VOArray_10muA , 0 , avets11VOErrArray_10muA);
  grtemp11VO_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp11VO_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp11VO_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp11VO_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp11VO_10muA -> SetMarkerStyle(24);
  grtemp11VO_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp11VO_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp11VO_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp11VO_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp11VO_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp11VO_10muA -> SetMarkerColor(1);



  TGraphErrors *grtemp12irrad_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets12IrradArray_10muA , 0 , avets12IrradErrArray_10muA);
  grtemp12irrad_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12irrad_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12irrad_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12irrad_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12irrad_10muA -> SetMarkerStyle(20);
  grtemp12irrad_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12irrad_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12irrad_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12irrad_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12irrad_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12irrad_10muA -> SetMarkerColor(2);


  TGraphErrors *grtemp12VO_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets12VOArray_10muA , 0 , avets12VOErrArray_10muA);
  grtemp12VO_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp12VO_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp12VO_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp12VO_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp12VO_10muA -> SetMarkerStyle(24);
  grtemp12VO_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp12VO_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp12VO_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp12VO_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp12VO_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp12VO_10muA -> SetMarkerColor(2);



  TGraphErrors *grtemp14irrad_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets14IrradArray_10muA , 0 , avets14IrradErrArray_10muA);
  grtemp14irrad_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14irrad_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14irrad_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14irrad_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14irrad_10muA -> SetMarkerStyle(20);
  grtemp14irrad_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14irrad_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14irrad_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14irrad_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14irrad_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14irrad_10muA -> SetMarkerColor(4);


  TGraphErrors *grtemp14VO_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets14VOArray_10muA , 0 , avets14VOErrArray_10muA);
  grtemp14VO_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp14VO_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp14VO_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp14VO_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp14VO_10muA -> SetMarkerStyle(24);
  grtemp14VO_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp14VO_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp14VO_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp14VO_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp14VO_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp14VO_10muA -> SetMarkerColor(4);


  TGraphErrors *grtemp16irrad_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets16IrradArray_10muA , 0 , avets16IrradErrArray_10muA);
  grtemp16irrad_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16irrad_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16irrad_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16irrad_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16irrad_10muA -> SetMarkerStyle(20);
  grtemp16irrad_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16irrad_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16irrad_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16irrad_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16irrad_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16irrad_10muA -> SetMarkerColor(8);


  TGraphErrors *grtemp16VO_10muA = new TGraphErrors(counts_10muA, irradtimeArray_10muA, avets16VOArray_10muA , 0 , avets16VOErrArray_10muA);
  grtemp16VO_10muA -> SetTitle( "Average Isopure Temperature vs Irradiation Time");
  grtemp16VO_10muA -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp16VO_10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  grtemp16VO_10muA -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  grtemp16VO_10muA -> SetMarkerStyle(24);
  grtemp16VO_10muA -> GetXaxis()-> SetLimits(0, 150);
  grtemp16VO_10muA -> GetXaxis() -> SetTitleSize(0.05);
  grtemp16VO_10muA -> GetXaxis() -> SetTitleOffset(1.0);
  grtemp16VO_10muA -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp16VO_10muA -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp16VO_10muA -> SetMarkerColor(8);
  

  grtemp12irrad_10muA -> Draw("Ap");
  grtemp12VO_10muA -> Draw("P");
  //grtemp11irrad_10muA -> Draw("p");
  //grtemp11VO_10muA -> Draw("P");
  //grtemp14irrad_10muA -> Draw("p");
  //grtemp14VO_10muA -> Draw("P");
  //grtemp16irrad_10muA -> Draw("p");
  //grtemp16VO_10muA -> Draw("P");
  //legtemp_10muA -> Draw();
  */ 
}
