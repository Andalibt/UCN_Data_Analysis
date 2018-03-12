//********************************************************
//             UCN 2017 analysis
//********************************************************
// THE UPDATE IN THIS VERSION IS THAT I GET RID OF THE
// VECTORS AND I FILL OUT THE TREE ELEMENT BY ELEMENT.
//*******************************************************

#include <string>
#include <iostream>
using namespace std;
#define max 100

// For fitting error to avoid the program to crash
//__________________________________________________

#include <iostream>
#include <cmath>

double safe_exp(double x) {
#if 0 /* 0 or 1 */
  if (x < -745) x = -745; else if (x > 709) x = 709; else if (std::isnan(x)) x = 0;
#endif /* 0 or 1 */
  double v = std::exp(x);
  if ((!std::isfinite(x)) || (!std::isfinite(v)))
    std::cout << "Warning : exp( " << x << " ) = " << v << std::endl;
  return v;
}

//_____________________________________________________


//******************************************************
// Fit Function
//******************************************************
Double_t Li6FitFunc (Double_t *x, Double_t *par){
  Double_t Li6_Fit;
  
  Li6_Fit = par[3] + (x[0] > par[0] && x[0] < par[2]) * par[1]*par[4] + (x[0] > par[2] + par[9]+ par[11]) * par[6]*(1 - exp(-(x[0] - par[2] - par[11]- par[9])/par[7]))*exp(-(x[0] - par[2] - par[11] - par[9])/par[8]);
 

  // par[0] : irradiation start time
  // par[1] : BaselineIrrad
  // par[2] : cycle start time
  // par[3] : Baseline after irradiation
  // par[4] : average predicted current during the cycle
  // par[5] : cycle valve open time
  // par[6] : amplitude
  // par[7] : rise time
  // par[8] : fall time
  // par[9] : delay
  // par[10]: cycle valve close time
  // par[11]: delay time after cycle start
  
  return Li6_Fit;
}


// HERE THE MAIN FUNCTION STARTS
// TO RUN THIS CODE YOU JUST OPEN ROOT AND TYPE .X plot_ucn_per_cycle_Taraneh_edit_ver8.C
void plot_ucn_per_cycle_Taraneh_edit_ver13(){  
  // Get the file
  char *filename[200];
  ofstream badruns_file("badruns_list.txt"); //List of all the bad runs.
  ofstream nofile("NotExist.txt"); //List of all the files that do not exist.
  Int_t midasrun=0;
  Int_t norun;
  Int_t badrun;
  Int_t runs=0; 
      
  //************************************************************************
  // Create a root tree
  
  //TFile hfile ("outputTree_StorageTime_17014.root", "RECREATE");
  TFile hfile ("outputTree_StorageTime_673.root", "RECREATE");
  TTree *outputTree = new TTree ("cycle_info", "output tree");


  std::string *expNumber = new std::string(); 
  std::string *shifter = new std::string(); 
  std::string *comment = new std::string(); 

  int runNumber;
  double StartofCycle;
  //const Int_t maxdata = StartofCycle.size();

  double cycleValveOpenTimes;
  double cycleValveCloseTimes;
  double cycleValveOpenDuration;
  double cycleDelayTimes;  
  int cycleNumber;
  double AVE_PRDCUR;
  double AVE_TNIM;
  double AVE_B1CUR;
  double AVE_TARGETTEMP1;
  double AVE_TARGETTEMP2;
  double AVE_WTEMP1;
  double AVE_WTEMP2;
  double AVE_COL2UP;
  double AVE_COL2LEFT;
  double AVE_COL2RIGHT;
  double AVE_COL2DOWN;
  double MAX_B1CUR;
  double MIN_B1CUR;
  double MAX_PRDCUR;
  double MIN_PRDCUR;
  double MAX_TNIM;
  double MIN_TNIM;
  double MAX_TARGETTEMP1;
  double MIN_TARGETTEMP1;
  double MAX_TARGETTEMP2;
  double MIN_TARGETTEMP2;
  double MAX_WTEMP1;
  double MIN_WTEMP1;
  double MAX_WTEMP2;
  double MIN_WTEMP2;
  double MAX_COL2UP;
  double MIN_COL2UP;
  double MAX_COL2RIGHT;
  double MIN_COL2RIGHT;
  double MAX_COL2LEFT;
  double MIN_COL2LEFT;
  double MAX_COL2DOWN;
  double MIN_COL2DOWN;
  double irradStartTimes;
  double AVE_TS12_IRRAD;
  double AVE_TS12_VALVEOPEN;
  double AVE_FM1;
  double MAX_TS12_IRRAD;
  double MIN_TS12_IRRAD;
  double MAX_TS12_VALVEOPEN;
  double MIN_TS12_VALVEOPEN;
  double AVE_TS12_DELAY;
  double MAX_TS12_DELAY;
  double MIN_TS12_DELAY;
  double MAX_FM1;
  double MIN_FM1;
  double AVE_FM4;
  double AVE_FM5;
  double AVE_LND;
  double MAX_LND;
  double MIN_LND;
  double Li6CountsValveOpen;
  double Li6CountsCycleStart;
  Double_t maxXrange = 0, minXrange=1540000000.;
  Int_t BinWidth=3;
  Int_t NBins = 1;
      
  TH2F *psd_vs_ql[16];
  for(int i = 0; i < 16; i++){
    char name[100],title[100];
    sprintf(name,"psd_vs_ql_%i",i);
    sprintf(title,"PSD vs QL ch %i",i); 
    psd_vs_ql[i] = new TH2F(name,title,200,0,15000,200,-1,1);
  }

 TH2F *psd_vs_ql_withcuts[16];
  for(int i = 0; i < 16; i++){
    char name[100],title[100];
    sprintf(name,"psd_vs_ql_withcuts_%i",i);
    sprintf(title,"PSD vs QL ch %i",i); 
    psd_vs_ql_withcuts[i] = new TH2F(name,title,200,0,15000,200,-1,1);
  }
  
  TH2* UCN_per_cycle_Li6_All = new TH2F("UCN_per_cycle_Li6_Whole_Sequence", "UCN per cycle", 100, minXrange, maxXrange , 100, 0.0, 10000);
  TH2* UCN_per_cycle_Li6_valveOpen = new TH2F("UCN_per_cycle_Li6_valveOpen", "UCN per cycle", 100, minXrange, maxXrange ,100, 0.0, 10000);
  TH1* UCN_rate_li6= new TH1F("UCN_rate_Li6", "UCN-rate Histogram",NBins , minXrange, maxXrange);
  TH2* UCN_per_cycle_He3_Whole_Sequence= new TH2F("UCN_per_cycle_He3_Whole_Sequence", "UCN per cycle",1000 , minXrange, maxXrange, 100, 0.0, 10000);
  TH2* UCN_per_cycle_He3_valveOpen= new TH2F("UCN_per_cycle_He3_valveOpen", "UCN per cycle", 100, minXrange, maxXrange, 100, 0.0, 10000);
  TH1* UCN_rate_He3= new TH1F("UCN_rate_He3", "UCN-rate Histogram", NBins , minXrange, maxXrange);
  THStack *UCN_rate_Li6_all = new THStack("UCN_rate_Li6_all" , " ");


  double Baseline;
  double BaselineDuringIrrad;
  double Amplitude;
  double RiseTime;
  double FallTime;
  double DELAY;
  double BaselineErr;

  double BaselineDuringIrradErr;
  double AmplitudeErr;
  double RiseTimeErr;
  double FallTimeErr;
  double DELAYErr;
  
  double UCNIntegral;
  double UCNIntegralErr;

  double HistIntegral;

  // Create branches. 
  outputTree -> Branch ("runNumber" , &runNumber);
  outputTree -> Branch ("expNumber" , &expNumber );
  outputTree -> Branch ("shifter", &shifter);
  outputTree -> Branch ("comment", &comment);
  outputTree -> Branch ("irradStartTimes",&irradStartTimes);
  outputTree -> Branch ("cycleStartTimes" , &StartofCycle);
  outputTree -> Branch ("cycleValveOpenTime", &cycleValveOpenTimes);
  outputTree -> Branch ("cycleValveCloseTime", &cycleValveCloseTimes);
  outputTree -> Branch ("cycleDelayTime", &cycleDelayTimes);
  outputTree -> Branch ("cycleValveOpenDuration", &cycleValveOpenDuration);
  outputTree -> Branch ("cycleNumber" , &cycleNumber);
  outputTree -> Branch ("AVE_PRDCUR",&AVE_PRDCUR);
  outputTree -> Branch ("MAX_PRDCUR",&MAX_PRDCUR);
  outputTree -> Branch ("MIN_PRDCUR",&MIN_PRDCUR);
  outputTree -> Branch ("AVE_TNIM",&AVE_TNIM);
  outputTree -> Branch ("MAX_TNIM",&MAX_TNIM);
  outputTree -> Branch ("MIN_TNIM",&MIN_TNIM);
  outputTree -> Branch ("AVE_B1CUR",&AVE_B1CUR);
  outputTree -> Branch ("MAX_B1CUR",&MAX_B1CUR);
  outputTree -> Branch ("MIN_B1CUR",&MIN_B1CUR);
  outputTree -> Branch ("AVE_TARGETTEMP1",&AVE_TARGETTEMP1);
  outputTree -> Branch ("MAX_TARGETTEMP1",&MAX_TARGETTEMP1);  
  outputTree -> Branch ("MIN_TARGETTEMP1",&MIN_TARGETTEMP1);
  outputTree -> Branch ("AVE_TARGETTEMP2",&AVE_TARGETTEMP2);
  outputTree -> Branch ("MAX_TARGETTEMP2",&MAX_TARGETTEMP2);
  outputTree -> Branch ("MIN_TARGETTEMP2",&MIN_TARGETTEMP2);
  outputTree -> Branch ("AVE_WTEMP1",&AVE_WTEMP1);
  outputTree -> Branch ("MAX_WTEMP1",&MAX_WTEMP1);
  outputTree -> Branch ("MIN_WTEMP1",&MIN_WTEMP1);
  outputTree -> Branch ("AVE_WTEMP2",&AVE_WTEMP2);
  outputTree -> Branch ("MAX_WTEMP2",&MAX_WTEMP2);
  outputTree -> Branch ("MIN_WTEMP2",&MIN_WTEMP2);
  outputTree -> Branch ("AVE_COL2UP",&AVE_COL2UP);
  outputTree -> Branch ("MAX_COL2UP",&MAX_COL2UP);
  outputTree -> Branch ("MIN_COL2UP",&MIN_COL2UP);
  outputTree -> Branch ("AVE_COL2DOWN",&AVE_COL2DOWN);
  outputTree -> Branch ("MAX_COL2DOWN",&MAX_COL2DOWN);
  outputTree -> Branch ("MIN_COL2DOWN",&MIN_COL2DOWN);
  outputTree -> Branch ("AVE_COL2RIGHT",&AVE_COL2RIGHT);
  outputTree -> Branch ("MAX_COL2RIGHT",&MAX_COL2RIGHT);
  outputTree -> Branch ("MIN_COL2RIGHT",&MIN_COL2RIGHT);
  outputTree -> Branch ("AVE_COL2LEFT",&AVE_COL2LEFT);
  outputTree -> Branch ("MAX_COL2LEFT",&MAX_COL2LEFT);
  outputTree -> Branch ("MIN_COL2LEFT",&MIN_COL2LEFT);
  outputTree -> Branch ("AVE_TS12_IRRAD",&AVE_TS12_IRRAD);
  outputTree -> Branch ("MAX_TS12_IRRAD",&MAX_TS12_IRRAD);
  outputTree -> Branch ("MIN_TS12_IRRAD",&MIN_TS12_IRRAD);
  outputTree -> Branch ("AVE_TS12_VALVEOPEN",&AVE_TS12_VALVEOPEN);
  outputTree -> Branch ("MAX_TS12_VALVEOPEN",&MAX_TS12_VALVEOPEN);
  outputTree -> Branch ("MIN_TS12_VALVEOPEN",&MIN_TS12_VALVEOPEN);
  outputTree -> Branch ("AVE_TS12_DELAY",&AVE_TS12_DELAY);
  outputTree -> Branch ("MAX_TS12_DELAY",&MAX_TS12_DELAY);
  outputTree -> Branch ("MIN_TS12_DELAY",&MIN_TS12_DELAY);
  outputTree -> Branch ("AVE_FM1",&AVE_FM1);
  outputTree -> Branch ("MAX_FM1",&MAX_FM1);
  outputTree -> Branch ("MIN_FM1",&MIN_FM1);
  outputTree -> Branch ("AVE_FM4", &AVE_FM4);
  outputTree -> Branch ("AVE_FM5", &AVE_FM5);
  outputTree -> Branch ("AVE_LNDr", &AVE_LND);
  outputTree -> Branch ("MAX_LNDr", &MAX_LND);
  outputTree -> Branch ("MIN_LNDr", &MIN_LND);
  outputTree -> Branch ("Li6CountsCycleStart", &Li6CountsCycleStart);
  outputTree -> Branch ("Li6CountsValveOpen" , &Li6CountsValveOpen);
  outputTree -> Branch ("Baseline" , &Baseline);
  outputTree -> Branch ("BaselineDuringIrrad" , &BaselineDuringIrrad);
  outputTree -> Branch ("Amplitude" , &Amplitude);
  outputTree -> Branch ("RiseTime" , &RiseTime);
  outputTree -> Branch ("FallTime", &FallTime);
  outputTree -> Branch ("DELAY", &DELAY);
  outputTree -> Branch ("BaselineErr" , &BaselineErr);
  outputTree -> Branch ("BaselineDuringIrradErr" , &BaselineDuringIrradErr);
  outputTree -> Branch ("AmplitudeErr" , &AmplitudeErr);
  outputTree -> Branch ("RiseTimeErr" , &RiseTimeErr);
  outputTree -> Branch ("FallTimeErr", &FallTimeErr);
  outputTree -> Branch ("DELAYErr", &DELAYErr);
  outputTree -> Branch ("UCNIntegral" , &UCNIntegral);
  outputTree -> Branch ("UCNIntegralErr" , &UCNIntegralErr);
  outputTree -> Branch ("HistIntegral" , &HistIntegral);
  
  // *************************************************************
  // STARTING THE LOOP OVER THE FILES.
  // *************************************************************
  
  // Int_t StorageTimeFiles[173] = {780, 781, 782, 783, 784, 785, 786};
  Int_t StorageTimeFiles[10] ={673};

  Int_t total_counter = 0 ;
  Int_t fit_counter = 0;
  Int_t total_cycle = 0;
  Int_t numcycle = 0; 
  Int_t failfit_cycle = 0;
  Int_t StorageTimeFileCounter =0; 
  for ( midasrun =524; midasrun <838; midasrun++){
    total_counter ++;
    runNumber = midasrun;
    runs++;
    cout << midasrun << endl;
    sprintf (filename , "/data/ucn/root_files/ucn_tree_00000%d.root",midasrun);
 
    if (StorageTimeFiles[StorageTimeFileCounter] != midasrun)
      continue;
    
    /*    if (midasrun == 539)
      continue;
 
    if (midasrun == 549)
      continue;
    if (midasrun == 560)
      continue;
    if (midasrun == 595) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 596) // IT SAYS THERE ARE 4 CYCLES BUT THE UCN RATE SHOWS ONLY ONE!
      continue;
    if (midasrun == 615) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 616) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 617) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 618) // I HAVE NO IDEA WHAT THIS RUN IS
      continue;
    if (midasrun == 619) // ROOT CRASHES
      continue;
    if (midasrun == 636) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 638) // THERE ARE 0 CYCLES IN THIS FILE. IT IS CRAP.
      continue;
    if (midasrun == 639) //AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 640) // ROOT CRASHES.
      continue;
    if (midasrun == 641) // AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 642) // ROOT CRASHES
      continue;
    if (midasrun == 674)
      continue;
    if (midasrun == 691)
      continue;
    if (midasrun == 694)
      continue;
    if (midasrun == 775)
      continue;
    if (midasrun == 787) 
      continue;
    if (midasrun == 792){ // THE UCN RATE HISTOGRAM LOOKS STRANGE A LITTLE.
                          // THE LAST CYCLE LOOKS STRANGE. OTHER THAN THAT, I THINK THE REASON THAT
                          // THE FIT FAILS IS BECAUSE THE RATES HAVE DIFFERENT INTENSITIES AND IT
                          // IS NOT CONSISTENT WITH THE INITIAL VALUES THAT I PROVIDE.
      continue;}
    if (midasrun == 793)
      continue;
    if (midasrun == 794)  // THE RATE HISTOGRAM IS STRANGE, VERY LOW INTENSITY AND THE FIT FAILS.  
      continue;
    if (midasrun == 795)  // GIVES AN ERROR
      continue;
    if (midasrun == 796)  // AFTER ADDING FIT FAILS
      continue;
    if (midasrun == 797)
      continue;
    if (midasrun == 810)
      continue;
    if (midasrun == 831)
      continue;*/

    TFile* fin = new TFile(Form(filename),"READ");
    
    // Here I should put if the file does not exist.
    if (fin == NULL) {
      std::cout<<"could not open file : "<< filename <<std::endl;
      return;
    } 
    if ( fin->IsOpen() == false ) {
      //std::cout<<"file not open : "<<filename<<std::endl;
      norun[runs]=midasrun;
      nofile << norun[runs] << endl;
      continue;
      return;
    }
    
    


      //**************************************************************************
      //TCNxxxxx number that the cycle belongs to
      //  This information is in the "headerTree;1" in the "experimetNumber" branch.
      //  The other run information such as the shifter and the run comments are 
      //  also added here.
      
      
      TTree* headerTree = (TTree*) fin->Get("headerTree");
      
      headerTree->SetBranchAddress("experimentNumber",&expNumber);
      headerTree->SetBranchAddress("shifter",&shifter);
      headerTree->SetBranchAddress("comment",&comment);
      headerTree->GetEntry(0);

      // cout<<"**********************************************************"<<endl;
      //std::cout << "The Experiment Number is:" << *expNumber << std::endl;
      //std::cout << "The shifter was: "<< *shifter<<std::endl;
      //std::cout << "Run comment: "<< *comment << std::endl;
      cout<<"**********************************************************"<<endl;
      

      //************************************************************************
      // IV1 open and close time.
      // These information must be in RunTransitions_Li-6 tree.
      
      
      TTree* truntime = (TTree*) fin -> Get("RunTransitions_Li-6");
      
      
      std::vector<int> numberEventsPerCycle;
      std::vector<int> numberEventsPerCycleValveOpen;
      ULong64_t eventTot;
      //numcycle = 0;
      

      double cycleStart;
      double valveOpenTime;
      double valveCloseTime;
      double delayTime;
      double delayTimeArray[max];
      double valveOpenDuration;
      std::vector <double> cycleStartTimes;
      for(int i = 0; i < cycleStartTimes.size(); i++) cycleStartTimes.push_back(0);
 
      double cycleStartTime[max];
      double cyclevalveopen[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) cyclevalveopen[i]=0;
      double cyclevalveclose[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) cyclevalveclose[i]=0;
      int cycleNumberArray[max] ;
      

      truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
      truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime);// time that valve opened
      truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); //time that valve closed
      truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
      truntime->SetBranchAddress("cycleOpenInterval",&valveOpenDuration); // valve open time
      
      eventTot = (Double_t)truntime->GetEntries();
      
      for(ULong64_t j=0; j< eventTot;j++) {
	truntime->GetEvent(j);
	cycleStartTimes.push_back(cycleStart);
	cycleStartTime[j] = cycleStart;
	//cycleValveOpenTimes.push_back(valveOpenTime);
	cyclevalveopen[j]=valveOpenTime;
	//	cycleValveCloseTimes.push_back(valveCloseTime);
	cyclevalveclose[j]=valveCloseTime;
	cycleValveOpenDuration[j] = valveOpenDuration;
	delayTimeArray[j]=delayTime;
	cycleDelayTimes[j] = delayTime;
	numberEventsPerCycle.push_back(0);
	numberEventsPerCycleValveOpen.push_back(0);
	numcycle=j+1;
	cycleNumberArray[j] = numcycle;
      }
      total_cycle = total_cycle + numcycle;
      cout << "Total number of cycles in this run is " << numcycle << endl;
      cout<<"**********************************************************"<<endl;

      //**************************************************************************
      //**************************************************************************
      
      TTree* BeamlineEpicsTree = (TTree*) fin-> Get ("BeamlineEpicsTree");
      TTree* sourceTree = (TTree*) fin->Get("SourceEpicsTree");
      TTree* LNDDetectorTree = (TTree*) fin-> Get("LNDDetectorTree");

      std::vector<double> beamlineReadTimes;
      for(int i = 0; i < 100000; i++) beamlineReadTimes.push_back(0);
      std::vector<int> beamlineFoundEntry;
      for(int i = 0; i < cycleStartTimes.size(); i++) beamlineFoundEntry.push_back(0);
      
      std::vector<double> cycleIrradiationTime;
      // for(int i = 0; i < cycleStartTimes.size(); i++) cycleIrradiationTime.push_back(0);
      std::vector<double> cycleB1U_BeamCurrent;
      std::vector<double> cycleB1_BeamCurrent;
      std::vector<double> cycleB1V_Fraction;
      std::vector<double> cycleTNIM_raw;
      
      
      double B1V_KSM_RDBEAMON_VAL1, B1V_KSM_PREDCUR, B1_FOIL_ADJCUR, B1V_KSM_PREDCUR_last = 0;
      double B1V_KSM_RDFRCTN_VAL1, B1U_TNIM2_RAW;
      double B1U_TGTTEMP1_RDTEMP, B1U_TGTTEMP2_RDTEMP; //Target Temperature
      double B1U_WTEMP1_RDTEMP, B1U_WTEMP2_RDTEMP;
      double B1U_COL2RIGHT_RDTEMP, B1U_COL2DOWN_RDTEMP, B1U_COL2UP_RDTEMP,B1U_COL2LEFT_RDTEMP;
      double UCN_ISO_TS12_RDTEMP;
      double UCN_HE3_FM1_RDFLOW;
      double UCN_HE4_FM4_RDFLOW;
      double UCN_HE4_FM5_RDFLOW;
     
      int timestamp_beamline=0;
     

      int timestamp;
      std::vector<double> sourceReadTimes;
      
      Int_t timestamp_LND;
      double LND_Reading;      

      BeamlineEpicsTree -> SetBranchAddress("timestamp",&timestamp_beamline);
      BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_RDBEAMON_VAL1",&B1V_KSM_RDBEAMON_VAL1);
      BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_PREDCUR",&B1V_KSM_PREDCUR);
      BeamlineEpicsTree -> SetBranchAddress("B1_FOIL_ADJCUR",&B1_FOIL_ADJCUR);
      BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_RDFRCTN_VAL1",&B1V_KSM_RDFRCTN_VAL1);
      BeamlineEpicsTree -> SetBranchAddress("B1U_TNIM2_RAW",&B1U_TNIM2_RAW);
      BeamlineEpicsTree -> SetBranchAddress("B1U_TGTTEMP1_RDTEMP",&B1U_TGTTEMP1_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_TGTTEMP2_RDTEMP",&B1U_TGTTEMP2_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_WTEMP1_RDTEMP",&B1U_WTEMP1_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_WTEMP2_RDTEMP",&B1U_WTEMP2_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_COL2RIGHT_RDTEMP",&B1U_COL2RIGHT_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_COL2LEFT_RDTEMP",&B1U_COL2LEFT_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_COL2DOWN_RDTEMP",&B1U_COL2DOWN_RDTEMP);
      BeamlineEpicsTree -> SetBranchAddress("B1U_COL2UP_RDTEMP",&B1U_COL2UP_RDTEMP);
        
      sourceTree -> SetBranchAddress("UCN_ISO_TS12_RDTEMP",&UCN_ISO_TS12_RDTEMP);
      sourceTree -> SetBranchAddress("UCN_HE3_FM1_RDFLOW",&UCN_HE3_FM1_RDFLOW);
      sourceTree -> SetBranchAddress("UCN_HE4_FM4_RDFLOW", &UCN_HE4_FM4_RDFLOW);
      sourceTree -> SetBranchAddress("UCN_HE4_FM5_RDFLOW", &UCN_HE4_FM5_RDFLOW);
      sourceTree->SetBranchAddress("timestamp",&timestamp);

      LNDDetectorTree->SetBranchAddress("timestamp",&timestamp_LND);
      LNDDetectorTree-> SetBranchAddress("LND_Reading",&LND_Reading);


      double prdcur_ave[max];
      for ( int k = 0 ; k < max; k++)
	prdcur_ave[k] = 100;
      double tnim_ave[max] = 0;
      double b1_ave[max] = 0;
      double targettemp1_ave[max] = 0 ;
      double targettemp2_ave[max] = 0;  
      double wtemp1_ave[max] = 0;
      double wtemp2_ave[max] = 0;
      double col2up_ave[max] = 0;
      double col2left_ave[max] = 0;
      double col2right_ave[max] = 0;
      double col2down_ave[max] = 0;
      double irradiationStartTime[max] = 0;
      double b1_max[max] = 0;
      double b1_min[max] ;
      for ( int k = 0 ; k < max; k++)
	b1_min[k] = 100;
      double prdcur_max[max];
     for ( int k = 0 ; k < max; k++)
	prdcur_max[k] = 0;
      double prdcur_min[max];
      for (int k = 0 ; k< max ; k++ )
	prdcur_min[k] = 100;
      double tnim_max[max] = 0;
      double tnim_min[max] = 1000;
      for (int k = 0 ; k< max ; k++ )
	tnim_min[k] = 1000;
      double targettemp1_max[max] = 0;
      double targettemp1_min[max];
      for (int k = 0 ; k< max ; k++ )
	targettemp1_min[k] = 100;
      double targettemp2_max[max] = 0;
      double targettemp2_min[max];
      for (int k = 0 ; k< max ; k++ )
	targettemp2_min[k] = 100;
      double wtemp1_max[max] = 0;
      double wtemp1_min[max] ;
      for (int k = 0 ; k< max ; k++ )
	wtemp1_min[k] = 1000;
      double wtemp2_max[max] = 0;
      double wtemp2_min[max] ;
      for (int k = 0 ; k< max ; k++ )
	wtemp2_min[k] = 1000;
      double col2up_max[max] = 0;
      double col2up_min[max];
      for (int k = 0 ; k< max ; k++ )
	col2up_min[k] = 100;
      double col2down_max[max] = 0;
      double col2down_min[max] ;
      for (int k = 0 ; k< max ; k++ )
	col2down_min[k] = 100;
      double col2right_max[max] = 0;
      double col2right_min[max] ;
      for (int k = 0 ; k< max ; k++ )
	col2right_min[k] = 100;
      double col2left_max[max] = 0;
      double col2left_min[max] ;
      for (int k = 0 ; k< max ; k++ )
	col2left_min[k] = 100;
      int counter_3=1 , counter_2=1, counter_1 = 1, counter_4 = 1;

      double avets12_temperature_irrad[max];
     for (int k = 0 ; k < max ; k++)
	avets12_temperature_irrad[k] = 0;
      double avets12_temperature_valveOpen[max];
      for (int k = 0 ; k < max ; k++)
	avets12_temperature_valveOpen[k] = 0;
      double avets12_delay[max] = 0;
      for (int k = 0 ; k < max ; k++)
	avets12_delay[k] = 0;
      double fm1_ave[max] = 0;
      double maxts12_temperature_irrad[max] ;
     for (int k = 0 ; k < max ; k++)
	maxts12_temperature_irrad[k] = 0;
      double mints12_temperature_irrad[max];
      for (int k = 0 ; k < max ; k++)
	mints12_temperature_irrad[k] = 100;
      double maxts12_temperature_valveOpen[max] = 0 ;
      for (int k = 0 ; k < max ; k++)
	maxts12_temperature_valveOpen[k] = 0;
      double mints12_temperature_valveOpen[max];
      for (int k = 0 ; k< max ; k++ )
	mints12_temperature_valveOpen[k] = 100;
      double maxts12_delay[max] = 0;
      double mints12_delay[max] = 100;
      for (int k = 0 ; k< max ; k++ )
	mints12_delay[k] = 100;
      double fm1_max[max];
      for (int k = 0 ; k< max ; k++ )
	fm1_max[k] = 0;
      double fm1_min[max];
      for (int k = 0 ; k< max ; k++ )
	fm1_min[k] = 100;
      double fm4_ave[max] = 0;
      double fm5_ave[max] = 0;
      double LND_ave[max] = 0;
      double LND_max[max] = 0;
      double LND_min[max] = 0;
 
      cout.setf(ios::fixed);
      Double_t beamlineEvent = (Double_t) BeamlineEpicsTree-> GetEntries();
      Double_t sourceEpicsEvent = (Double_t) sourceTree-> GetEntries();
      Double_t LNDEvent = (Double_t) LNDDetectorTree -> GetEntries();


      for(ULong64_t j = 0 ; j < beamlineEvent ;j++) {
	BeamlineEpicsTree -> GetEvent(j);
	beamlineReadTimes.push_back(timestamp_beamline);
	for(int i = 0; i < cycleStartTimes.size(); i++){
	  if(beamlineFoundEntry[i] == 1) continue;
	  if(timestamp_beamline > cycleStartTimes[i]){
	    cycleIrradiationTime.push_back(B1V_KSM_RDBEAMON_VAL1 *0.0008881);
	    cycleB1U_BeamCurrent.push_back(B1V_KSM_PREDCUR_last);
	    cycleB1_BeamCurrent.push_back(B1_FOIL_ADJCUR);	
	    //cycleB1V_Fraction.push_back(B1V_KSM_RDFRCTN_VAL1);
	    //cycleTNIM_raw.push_back(B1U_TNIM2_RAW);
	    beamlineFoundEntry[i] = 1;
	  }
	  B1V_KSM_PREDCUR_last = B1V_KSM_PREDCUR;
	}
      }

      int counter_cur = 0;
      int counter_delay = 0;

      // LOOP TO CALCULATE MAX, MIN AND AVERAGE
      for ( int i = 0 ; i < cycleStartTimes.size(); i++){
	irradiationStartTime[i] = cycleStartTimes[i] - cycleIrradiationTime[i];
	counter_1=0;	
	counter_2=0;
	counter_3=0;
	counter_4=0;
	counter_cur = 0;
	counter_delay = 0;
	prdcur_ave[i] = 0;
	for(ULong64_t j=0; j < beamlineEvent ;j++) {
	  BeamlineEpicsTree -> GetEvent(j);
	  beamlineReadTimes.push_back(timestamp_beamline);
	  if (timestamp_beamline > irradiationStartTime[i] && timestamp_beamline < cycleStartTimes[i]) {
	    b1_ave[i]+=B1_FOIL_ADJCUR;
	    if (B1V_KSM_PREDCUR >0 ){
	      prdcur_ave[i]+=B1V_KSM_PREDCUR;
	      counter_cur++;
	    }
	    tnim_ave[i]+=B1U_TNIM2_RAW;
	    targettemp1_ave[i]+=B1U_TGTTEMP1_RDTEMP;
	    targettemp2_ave[i]+=B1U_TGTTEMP2_RDTEMP;
	    wtemp1_ave[i]+=B1U_WTEMP1_RDTEMP;
	    wtemp2_ave[i]+=B1U_WTEMP2_RDTEMP;
	    col2up_ave[i]+=B1U_COL2UP_RDTEMP;
	    col2down_ave[i]+=B1U_COL2DOWN_RDTEMP;
	    col2right_ave[i]+=B1U_COL2RIGHT_RDTEMP;
	    col2left_ave[i]+=B1U_COL2LEFT_RDTEMP;
	    
	    counter_3++;
	   
	    if(B1_FOIL_ADJCUR >= b1_max[i]){
	      b1_max[i]=B1_FOIL_ADJCUR;  
	    }
	    if( b1_min[i] >= B1_FOIL_ADJCUR){
	      b1_min[i] = B1_FOIL_ADJCUR;
	    }
	    if(B1V_KSM_PREDCUR >= prdcur_max[i]){
	      prdcur_max[i]=B1V_KSM_PREDCUR;
	    }
	    if (B1V_KSM_PREDCUR <= prdcur_min[i]){
	      prdcur_min[i]=B1V_KSM_PREDCUR;
	    }
	    if (B1U_TNIM2_RAW >= tnim_max[i]){
	      tnim_max[i]= B1U_TNIM2_RAW;
	    }
	    if (B1U_TNIM2_RAW <= tnim_min[i]){
	      tnim_min[i]=B1U_TNIM2_RAW;
	    }
	    if (B1U_TGTTEMP1_RDTEMP >= targettemp1_max[i]){
	      targettemp1_max[i]=B1U_TGTTEMP1_RDTEMP ;
	    }
	    if (B1U_TGTTEMP1_RDTEMP <= targettemp1_min[i]){
	      targettemp1_min[i]=B1U_TGTTEMP1_RDTEMP;
	    }
	    if (B1U_TGTTEMP2_RDTEMP >= targettemp2_max[i]){
	      targettemp2_max[i]=B1U_TGTTEMP2_RDTEMP ;
	    }
	    if (B1U_TGTTEMP2_RDTEMP <= targettemp2_min[i]){
	      targettemp2_min[i]=B1U_TGTTEMP2_RDTEMP;
	    }
	    if (B1U_WTEMP1_RDTEMP >= wtemp1_max[i]){
	      wtemp1_max[i]=B1U_WTEMP1_RDTEMP ;
	    }
	    if (B1U_WTEMP1_RDTEMP <= wtemp1_min[i]){
	      wtemp1_min[i]=B1U_WTEMP1_RDTEMP;
	    }
	    if (B1U_WTEMP2_RDTEMP >= wtemp2_max[i]){
	      wtemp2_max[i]=B1U_WTEMP2_RDTEMP ;
	    }
	    if (B1U_WTEMP2_RDTEMP <= wtemp2_min[i]){
	      wtemp2_min[i]=B1U_WTEMP2_RDTEMP;
	    }
	    if (B1U_COL2UP_RDTEMP >= col2up_max[i] ){
	      col2up_max[i]=B1U_COL2UP_RDTEMP;
	    }
	    if (B1U_COL2UP_RDTEMP <= col2up_min[i] ){
	      col2up_min[i]=B1U_COL2UP_RDTEMP;
	    }
	    if (B1U_COL2DOWN_RDTEMP >= col2down_max[i] ){
	      col2down_max[i]=B1U_COL2DOWN_RDTEMP;
	    }
	    if (B1U_COL2DOWN_RDTEMP <= col2down_min[i] ){
	      col2down_min[i]=B1U_COL2DOWN_RDTEMP;
	    }
	    if (B1U_COL2RIGHT_RDTEMP >= col2right_max[i] ){
	      col2right_max[i]=B1U_COL2RIGHT_RDTEMP;
	    }
	    if (B1U_COL2RIGHT_RDTEMP <= col2right_min[i] ){
	      col2right_min[i]=B1U_COL2RIGHT_RDTEMP;
	    }
	    if (B1U_COL2LEFT_RDTEMP >= col2left_max[i] ){
	      col2left_max[i]=B1U_COL2LEFT_RDTEMP;
	    }
	    if (B1U_COL2LEFT_RDTEMP <= col2left_min[i] ){
	      col2left_min[i]=B1U_COL2LEFT_RDTEMP;
	      //cout << col2left_min[i] << endl;
	    }	
	  }
	}
	for(ULong64_t j=0 ; j < sourceEpicsEvent ;j++) {
	  sourceTree -> GetEvent(j);
	  if(timestamp > irradiationStartTime[i] && timestamp < cyclevalveopen[i]){
	    avets12_temperature_irrad[i]+=UCN_ISO_TS12_RDTEMP;
	    fm1_ave[i]+=UCN_HE3_FM1_RDFLOW;
	    fm4_ave[i] += UCN_HE4_FM4_RDFLOW;
	    fm5_ave[i] += UCN_HE4_FM5_RDFLOW;
	    if (timestamp > cycleStartTimes[i] && timestamp < cyclevalveopen[i]){
	      avets12_delay[i] += UCN_ISO_TS12_RDTEMP;
	      if (UCN_ISO_TS12_RDTEMP >= maxts12_delay[i]){
		maxts12_delay[i] = UCN_ISO_TS12_RDTEMP;
	      }
	      if (UCN_ISO_TS12_RDTEMP <= mints12_delay[i] ){
		mints12_delay[i]  = UCN_ISO_TS12_RDTEMP;
	      }
	      counter_delay++;
	    }
	    counter_2++;
	    
	    if(UCN_ISO_TS12_RDTEMP >= maxts12_temperature_irrad[i]){
	      maxts12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
	    }
	    //cout <<"outside the loop " << UCN_ISO_TS12_RDTEMP << endl;  
	    if( UCN_ISO_TS12_RDTEMP < mints12_temperature_irrad[i]){
	      mints12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
	      //cout << "inside the loop " <<UCN_ISO_TS12_RDTEMP << endl;  
	    }
	    if(UCN_HE3_FM1_RDFLOW <= fm1_min[i]){
	      fm1_min[i] = UCN_HE3_FM1_RDFLOW;
	    }
	    if(UCN_HE3_FM1_RDFLOW >= fm1_max[i]){
	      fm1_max[i]=UCN_HE3_FM1_RDFLOW;
	    }

	  }
	  if (timestamp > cyclevalveopen[i] && timestamp < cyclevalveclose[i]){
	    avets12_temperature_valveOpen[i]+=UCN_ISO_TS12_RDTEMP;
	    counter_1++;
	    if(UCN_ISO_TS12_RDTEMP > maxts12_temperature_valveOpen[i]){
	      maxts12_temperature_valveOpen[i] = UCN_ISO_TS12_RDTEMP;
	    } 
	    if(UCN_ISO_TS12_RDTEMP < mints12_temperature_valveOpen[i]){
	      mints12_temperature_valveOpen[i] = UCN_ISO_TS12_RDTEMP; 
	    }
	  }
	}
	for(ULong64_t j=0; j < LNDEvent ;j++) {
	  LNDDetectorTree -> GetEvent(j);
	  if ( timestamp_LND > irradiationStartTime[i] && timestamp_LND < cyclevalveopen[i]){
	    LND_ave[i]+=LND_Reading;
	    counter_4++;
	    if (LND_max[i] < LND_Reading){
	      LND_max[i]=LND_Reading;
	    }
	    if(LND_min[i] > LND_Reading){
	      LND_min[i]=LND_Reading;
	    }
	  }
	}
	//cout << counter_1 << " " << counter_2 << " " << counter_3 << " " << counter_4 << endl;
	b1_ave[i]=b1_ave[i]/(counter_3);
	if (prdcur_ave[i] >  0.001){
	  prdcur_ave[i]=prdcur_ave[i]/(counter_cur);
	}
	cout << "delay counter " << counter_delay << endl;
	//cout << counter_1 << " "<< counter_2<< " "<< counter_3<< " " << counter_4 << endl;
	//cout << avets12_temperature_valveOpen[i] << endl;
	tnim_ave[i]=tnim_ave[i]/(counter_3);
	targettemp1_ave[i]=targettemp1_ave[i]/(counter_3);
	targettemp2_ave[i]=targettemp2_ave[i]/(counter_3);
	wtemp1_ave[i]=wtemp1_ave[i]/(counter_3);
	wtemp2_ave[i]=wtemp2_ave[i]/(counter_3);
	col2up_ave[i]=col2up_ave[i]/(counter_3);
	col2down_ave[i]=col2down_ave[i]/(counter_3);
	col2right_ave[i]=col2right_ave[i]/(counter_3);
	col2left_ave[i]=col2left_ave[i]/(counter_3);
	avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter_2);
	fm1_ave[i] = fm1_ave[i]/(counter_2);
	fm4_ave[i] = fm4_ave[i]/(counter_2);
	fm5_ave[i] = fm5_ave[i]/(counter_2);
	if (avets12_temperature_valveOpen[i] < 0.001){
	  counter_1 = 1;
	}
	avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_1);
	LND_ave[i]=LND_ave[i]/counter_4;
	if (counter_delay == 0)
	  counter_delay = 1;
	avets12_delay[i] = avets12_delay[i]/counter_delay;
      }
 
      maxXrange=0;
      minXrange=1540000000.;

      for(ULong64_t j=0 ; j < beamlineEvent ;j++) {
	BeamlineEpicsTree -> GetEvent(j);
	if (timestamp_beamline < minXrange ){
	  minXrange = timestamp_beamline;
	  //cout << minXrange << " " <<  endl;
	}
	if (timestamp_beamline > maxXrange)
	  {
	    maxXrange = timestamp_beamline;
	    //  cout << maxXrange << endl;
	  }
      }

      NBins = (maxXrange - minXrange)/BinWidth ; 
      cout  << "NBins: " << NBins << " ,BinWidth: "  << BinWidth<< endl;
      //*****************************************************************************
      // UCN hits
      //*****************************************************************************
      
      TTree* uinli6 = (TTree*) fin->Get("UCNHits_Li-6");
      

      double tUnixTimePrecise_li6, tUnixTime_li6;
      Float_t tPSD_li6;  
      UShort_t tChargeL_li6;
      UShort_t tIsUCN_li6, tChannel_li6;

      uinli6->SetBranchAddress("tUnixTimePrecise",&tUnixTimePrecise_li6);
      uinli6->SetBranchAddress("tUnixTime",&tUnixTime_li6);
      uinli6->SetBranchAddress("tIsUCN",&tIsUCN_li6);
      uinli6->SetBranchAddress("tChannel",&tChannel_li6);
      uinli6->SetBranchAddress("tPSD",&tPSD_li6);
      uinli6->SetBranchAddress("tChargeL",&tChargeL_li6);

      
      UCN_rate_li6 -> Reset();
      UCN_rate_li6 -> SetBins(NBins, minXrange , maxXrange);
      
	
      // pointer for closeSourceEPics reads;
      int source_index = 0;
   

      // This is for during the whole sequence.
      eventTot = (Double_t)uinli6->GetEntries();
      for(ULong64_t j=0;j<eventTot;j++) {
	uinli6->GetEvent(j);
	
	// To get the ucn rate
	if (tIsUCN_li6 >0 && tUnixTime_li6 >20e6){
	  UCN_rate_li6-> Fill (tUnixTimePrecise_li6);
	}
	//Check if this is a UCN hit.
	if(tIsUCN_li6 > 0  && cycleStartTimes.size() > 0){ 
	  // check which cycle this is in...
	  for(int i = 0; i < cycleStartTimes.size()-1; i++){
	    if(tUnixTimePrecise_li6 >= cycleStartTimes[i] && tUnixTimePrecise_li6 <= cycleStartTimes[i+1]){
	      numberEventsPerCycle[i]++;
	      //break;
	    }
	    if (tUnixTimePrecise_li6 >= cyclevalveopen[i] && tUnixTimePrecise_li6 < cyclevalveclose[i]){
	      numberEventsPerCycleValveOpen[i]++;
	    }
	    // cout << numberEventsPerCycle[i]<< " " << numberEventsPerCycleValveOpen[i] <<endl;
	  }
	  
	}
      
	psd_vs_ql[tChannel_li6]->Fill(tChargeL_li6,tPSD_li6);
      }

      // Normalizing the UCN_rate_li6 Histogram
      
      // Method one
      //Double_t scale;
      //scale = UCN_rate_li6->GetXaxis() -> GetBinWidth(1)/ (UCN_rate_li6 -> GetIntegral());
      //UCN_rate_li6 -> Scale(scale);

      // Method two
      //Double_t norm = UCN_rate_li6 -> GetEntries();
      //UCN_rate_li6 -> Scale(1/norm);


      // Method three
      Double_t norm = 1.;
      Int_t Li6_integral[100000];
      Double_t scale[100000];
      Int_t Li6Max[100000];
      Double_t mu_li6[100000];
      Int_t Bin_low[100000];
      Int_t Bin_high[100000];
      Double_t min_range[100000];
      Double_t max_range[100000];
   

      // Here I find for each cycle, which bin is the start of the cycle and which is the end.
      // This is important because when I want to do the fit, I have to provide a range of values.
      
      for(ULong64_t j=0;j<eventTot;j++) {
	uinli6->GetEvent(j);
	for ( int i = 0; i < cycleStartTimes.size(); i++){
	  min_range[i] = irradiationStartTime[i];
	  max_range[i] = cyclevalveclose[i];
	  Bin_low[i] = UCN_rate_li6 -> GetXaxis() -> FindBin(irradiationStartTime[i]);
	  Bin_high[i] = UCN_rate_li6 ->  GetXaxis() -> FindBin(cyclevalveclose[i]);
	}
      }
      
      for ( int i = 0; i < cycleStartTimes.size(); i++){
	UCN_rate_li6 -> GetXaxis()-> SetRange(min_range[i] , max_range[i]);

	Li6Max[i] = UCN_rate_li6 -> GetMaximum();
	mu_li6[i] = UCN_rate_li6 -> GetMean();
	Li6_integral[i] = UCN_rate_li6 -> Integral(Bin_low[i] , Bin_high[i]);
      }
      
      // Fix the range to see all the cycles
      UCN_rate_li6 -> GetXaxis()-> SetRange(minXrange , maxXrange);
      //Plot the UCN counts per cycle for Li6 detector
      if(cycleStartTimes.size() > 0){
      	for( int i = 0; i < cycleStartTimes.size()-1; i++){
      	  UCN_per_cycle_Li6_All->Fill(cycleStartTimes[i],numberEventsPerCycle[i]);
	  UCN_per_cycle_Li6_valveOpen->Fill(cyclevalveopen[i],numberEventsPerCycleValveOpen[i]);
      	}
	UCN_per_cycle_Li6_All->SetMarkerStyle(20);
	UCN_per_cycle_Li6_valveOpen->SetMarkerStyle(20);
      }
     
      //-----------------------------
      // He3 detector stuff

      if (midasrun >786){
	TTree* uinhe3 = (TTree*) fin->Get("UCNHits_He3");
	TTree* runtransitionhe3= (TTree*) fin->Get("RunTransitions_He3");
	
	double tUnixTimePrecise_he3, tUnixTime_he3;
	Float_t tPSD_he3;  
	UShort_t tChargeL_he3;
	UShort_t tIsUCN_he3, tChannel_he3;
	
	
	std::vector <int> numberEventsPerCyclehe3;
	std::vector <int> numberEventsPerCyclehe3valveOpen;
	ULong64_t runtransitionhe3Event;
	ULong64_t He3Event;
	double cycleStart_he3;
	std::vector <double> cycleStartTimehe3;
	
	
	uinhe3->SetBranchAddress("tUnixTimePrecise",&tUnixTimePrecise_he3);
	uinhe3->SetBranchAddress("tUnixTime",&tUnixTime_he3);
	uinhe3->SetBranchAddress("tIsUCN",&tIsUCN_he3);
	uinhe3->SetBranchAddress("tChannel",&tChannel_he3);
	uinhe3->SetBranchAddress("tPSD",&tPSD_he3);
	uinhe3->SetBranchAddress("tChargeL",&tChargeL_he3);
	
	runtransitionhe3 -> SetBranchAddress("cycleStartTime", &cycleStart_he3);
	
	
	
	runtransitionhe3Event= (Double_t)runtransitionhe3->GetEntries();
	for(ULong64_t j=0; j < runtransitionhe3Event ; j++) {
	  runtransitionhe3-> GetEvent(j);
	  cycleStartTimehe3.push_back(cycleStart_he3);
	}
	
	He3Event = (Double_t) uinhe3 -> GetEntries();
	for(ULong64_t j=0; j < He3Event ; j++) {
	  uinhe3->GetEvent(j);
	  numberEventsPerCyclehe3.push_back(0);
	  numberEventsPerCyclehe3valveOpen.push_back(0);
	}
	
	// THE HE3 DETECTOR WAS USED FROM RUN 787 AND FURTHER
	
	//TH1* UCN_rate_he3= new TH1F("UCN_rate_He3", "UCN-rate Histogram", 1000, 1500000000, 153000000);
	// This is for during the whole sequence.
	
	for(ULong64_t j=0; j < He3Event ; j++) {
	  uinhe3->GetEvent(j);
	  // To get the ucn rate
	  
	  if (tIsUCN_he3 >0 && tUnixTime_he3 >20e6){
	    UCN_rate_He3-> Fill (tUnixTimePrecise_he3);
	  }
	  if(tIsUCN_he3 >0 && cycleStartTimehe3.size() > 0){
	    // check which cycle this is in...
	    for(int i = 0; i < cycleStartTimehe3.size()-1; i++){
	      if(tUnixTimePrecise_he3 >= cycleStartTimehe3[i] && tUnixTimePrecise_he3 <= cycleStartTimehe3[i+1]){
		numberEventsPerCyclehe3[i]++;
		//	break;
	      }
	      if (tUnixTimePrecise_he3 >= cyclevalveopen[i] && tUnixTimePrecise_he3 < cyclevalveclose[i]){
		numberEventsPerCyclehe3valveOpen[i]++;
	      }
	    }
	  }
	}
	
	TH2* UCN_per_cycle_he3 = new TH2F("UCN_per_cycle_He3", "UCN per cycle", 100, 0.0, NBins, 100, 1500000000, 153000000);
	if(cycleStartTimehe3.size() > 0){
	  for( int i = 0; i < cycleStartTimehe3.size()-1; i++){
	    //  cout << cycleStartTimehe3[i] << " " << numberEventsPerCyclehe3[i] << endl;
	    UCN_per_cycle_He3_Whole_Sequence->Fill(cycleStartTimehe3[i],numberEventsPerCyclehe3[i]);
	    UCN_per_cycle_He3_valveOpen->Fill(cyclevalveopen[i],numberEventsPerCyclehe3valveOpen[i]);
	  }
	  UCN_per_cycle_He3_Whole_Sequence->SetMarkerStyle(20);
	  UCN_per_cycle_He3_valveOpen->SetMarkerStyle(20);
	}
      }
      
      //**********************************************************************
      // FIT THE UCN_RATE HISTOGRAM
      //**********************************************************************
      Double_t baseline[max] , baselineErr[max];
      Double_t baseline_during_irrad[max] , baseline_during_irrad_Err[max];
      Double_t amp[max] , ampErr[max];
      Double_t tauRise[max] , tauRiseErr[max];
      Double_t tauFall[max] , tauFallErr[max];
      Double_t delay[max] , delayErr[max];
      Double_t Integral[max] , IntegralErr[max];


      gStyle -> SetOptFit(0000);
      for (int i=0 ; i < cycleStartTimes.size(); i++){

	//UCN_rate_li6 -> Scale(scale[i]);
	//cout << "min_range: " << min_range[i] << endl;
	//cout << "max_range: " << max_range[i] << endl;
	//cout << "irradStart: " << irradiationStartTime[i]<< endl;
	//cout << "cycleStartTimes: " << cycleStartTimes[i] << endl;
	//cout << "valveOpenTime: " << cyclevalveopen[i] << endl;
	//cout << "delay duration: "<< delayTimeArray[i] << endl;
	//cout << "Li6Max: " << Li6Max[i] << endl; 
	//cout << "Li6_integral: " << Li6_integral[i] << endl;
	TF1 *Li6_Fit_Func = new TF1("Li6FitFunc", Li6FitFunc ,min_range[i] , max_range[i] , 12);

	// par[0] : irradiation start time
	// par[1] : BackgroundIrrad
	// par[2] : cycle start time
	// par[3] : Background after irradiation
	// par[4] : average predicted current during the cycle
	// par[5] : cycle valve open time
	// par[6] : amplitude
	// par[7] : rise time
	// par[8] : fall time
	// par[9]: delay
	// par[10]: cycle valve close time

	Li6_Fit_Func -> SetParName(0, "Irradiation Start Time");
	Li6_Fit_Func -> SetParName(1, "Baseline during irradiation");
	Li6_Fit_Func -> SetParName(2, "cycle start time");
	Li6_Fit_Func -> SetParName(3, "Baseline");
	Li6_Fit_Func -> SetParName(4, "Average predicted current");
	Li6_Fit_Func -> SetParName(5, "Cycle valve open time");
	Li6_Fit_Func -> SetParName(6, "Amplitude");
	Li6_Fit_Func -> SetParName(7, "Rise time");
	Li6_Fit_Func -> SetParName(8, "Fall time");
	Li6_Fit_Func -> SetParName(9, "delay");
	Li6_Fit_Func -> SetParName(10, "cycle valve close time");
	Li6_Fit_Func -> SetParName(11, "valve open delay duration");
	//Li6_Fit_Func -> SetParameter(0, 0);
	Li6_Fit_Func -> FixParameter(0, irradiationStartTime[i]);
	Li6_Fit_Func -> SetParameter(1, 2);
	Li6_Fit_Func -> SetParLimits(1, 0, 150);
	Li6_Fit_Func -> FixParameter(2, cycleStartTimes[i]);
	Li6_Fit_Func -> SetParameter(3, 4);
	Li6_Fit_Func -> SetParLimits(3, 0, 100);
	Li6_Fit_Func -> FixParameter(4, prdcur_ave[i]);
	Li6_Fit_Func -> FixParameter(5, cyclevalveopen[i]);
	Li6_Fit_Func -> SetParameter(6, (int)Li6Max[i]/2);
	Li6_Fit_Func -> SetParLimits(6, 0, 70000);
	Li6_Fit_Func -> SetParameter(7, 2);
	Li6_Fit_Func -> SetParLimits(7, 1e-3, 10);
	Li6_Fit_Func -> SetParameter(8, 20);
	Li6_Fit_Func -> SetParLimits(8, 1e-3, 30);
	Li6_Fit_Func -> SetParameter(9, 3);
	Li6_Fit_Func -> SetParLimits(9, 0, 10);
	Li6_Fit_Func -> FixParameter(10, cyclevalveclose[i]);
	Li6_Fit_Func -> FixParameter(11,delayTimeArray[i]);
	Li6_Fit_Func -> SetNpx(10000);
	TFitResultPtr status = UCN_rate_li6->Fit(Li6_Fit_Func,"R+MQ");
	cout << "***********************************************************" << endl;
	Int_t fitStatus = status;
	cout << fitStatus << endl;
	if (fitStatus == 4) {
	  failfit_cycle++;
	  continue;
	}
	baseline[i] = Li6_Fit_Func -> GetParameter(3);
	baseline_during_irrad[i] = Li6_Fit_Func -> GetParameter(1);
	amp[i] = Li6_Fit_Func -> GetParameter(6);
	tauRise[i] = Li6_Fit_Func -> GetParameter(7);
	tauFall[i] = Li6_Fit_Func -> GetParameter(8);
	delay[i] = Li6_Fit_Func -> GetParameter(9);
	baselineErr[i] = Li6_Fit_Func -> GetParError(3);
	baseline_during_irrad_Err[i] = Li6_Fit_Func -> GetParError(1);
	ampErr[i] = Li6_Fit_Func -> GetParError(6);
	tauRiseErr[i] = Li6_Fit_Func -> GetParError(7);
	tauFallErr[i] = Li6_Fit_Func -> GetParError(8);
	delayErr[i] = Li6_Fit_Func -> GetParError(9);
	Integral[i] = Li6_Fit_Func -> Integral(cyclevalveopen[i] , cyclevalveclose[i])/BinWidth;
	IntegralErr[i] = Li6_Fit_Func -> IntegralError(cyclevalveopen[i] , cyclevalveclose[i]);
	//Li6_Fit_Func-> Draw("");
	hfile.cd();
      }
      
      fit_counter++;

      
      std::ostringstream runname;
      //char *runname[200];
      //sprintf(runname, "UCN_rate_Li6_run%d",midasrun);
      runname << "UCN_rate_Li6_run"<< midasrun;
      // for (auto del = cycleDelayTimes.begin(); del != cycleDelayTimes.end(); ++del)
      //	runname << " " << *del;
      //  cycleDelayTimes.clear();
      UCN_rate_li6->Write(runname.str().c_str());
      
      UCN_rate_li6 -> SetBins(NBins, minXrange , maxXrange);
      UCN_rate_Li6_all -> Add (UCN_rate_li6);

      //**********************************************************************
      // CHECK THE DETECTOR CUTS FOR Li6 DETECTOR
      //**********************************************************************

      Double_t PSDThreshold = 0.3; // value found in TLi6Detector.cxx file
      Double_t QLongThreshold = 2000.;  // value found in TLi6Detector.cxx file
      UShort_t tChargeS_li6;
      
      uinli6 -> SetBranchAddress("tChargeS" , &tChargeS_li6);

      eventTot = (Double_t)uinli6->GetEntries();
      for(ULong64_t j=0;j<eventTot;j++) {
	uinli6->GetEvent(j);
	// apply the cuts
	if (tPSD_li6 > PSDThreshold && tChargeL_li6 > QLongThreshold){
	  psd_vs_ql_withcuts[tChannel_li6]->Fill(tChargeL_li6,tPSD_li6);
	}
      }



      //***********************************************************************
      // FILLING THE TREE     
      //***********************************************************************
      
      for ( int i = 0 ; i < cycleStartTimes.size(); i++ ){
	irradStartTimes = irradiationStartTime[i];
	StartofCycle = cycleStartTime[i] ;
	cycleValveOpenTimes = cyclevalveopen[i];
	cycleValveCloseTimes = cyclevalveclose[i];
	cycleDelayTimes[i] = -cycleStartTime[i] + cyclevalveopen[i];
	AVE_B1CUR = b1_ave[i];
	AVE_PRDCUR = prdcur_ave[i];
	AVE_TNIM = tnim_ave[i];
	AVE_TARGETTEMP1 = targettemp1_ave[i];
	AVE_TARGETTEMP2 = targettemp2_ave[i];	   
	AVE_WTEMP1 = wtemp1_ave[i];
	AVE_WTEMP2 = wtemp2_ave[i];
	AVE_COL2UP = col2up_ave[i];
	AVE_COL2DOWN = col2down_ave[i];
	AVE_COL2RIGHT = col2right_ave[i];
	AVE_COL2LEFT = col2left_ave[i];
	AVE_TS12_IRRAD = avets12_temperature_irrad[i];
	AVE_TS12_VALVEOPEN = avets12_temperature_valveOpen[i];
	AVE_TS12_DELAY = avets12_delay[i];
	AVE_FM1 = fm1_ave[i];
	AVE_FM4 = fm4_ave[i];
	AVE_FM5 = fm5_ave[i];
	MAX_B1CUR =  b1_max[i] ;
	MIN_B1CUR =  b1_min[i] ;
	MAX_PRDCUR =  prdcur_max[i] ;
	MIN_PRDCUR =  prdcur_min[i] ;
	MAX_TNIM =  tnim_max[i] ;
	MIN_TNIM =  tnim_min[i] ;
	MAX_TARGETTEMP1 =  targettemp1_max[i] ;
	MIN_TARGETTEMP1 =  targettemp1_min[i] ;
	MAX_TARGETTEMP2 =  targettemp2_max[i] ;
	MIN_TARGETTEMP2 =  targettemp2_min[i] ;
	MAX_WTEMP1 =  wtemp1_max[i] ;
	MIN_WTEMP1 =  wtemp1_min[i] ;
	MAX_WTEMP2 =  wtemp2_max[i] ;
	MIN_WTEMP2 =  wtemp2_min[i] ;
	MAX_COL2UP =  col2up_max[i] ;
	MIN_COL2UP =  col2up_min[i] ;
	MAX_COL2DOWN =  col2down_max[i] ;
	MIN_COL2DOWN =  col2down_min[i] ;
	MAX_COL2RIGHT = col2right_max[i] ;
	MIN_COL2RIGHT = col2right_min[i] ;
	MAX_COL2LEFT =  col2left_max[i] ;
	MIN_COL2LEFT =  col2left_min[i] ;
	MAX_TS12_IRRAD =  maxts12_temperature_irrad[i] ;
	MIN_TS12_IRRAD =  mints12_temperature_irrad[i] ;
       	MAX_TS12_VALVEOPEN =  maxts12_temperature_valveOpen[i];
       	MIN_TS12_VALVEOPEN =  mints12_temperature_valveOpen[i];
	MAX_TS12_DELAY = maxts12_delay[i] ;
	MIN_TS12_DELAY = mints12_delay[i] ;
	MAX_FM1 = fm1_max[i];
	MIN_FM1 = fm1_min[i];
	AVE_LND = LND_ave[i];
	MAX_LND = LND_max[i];
	MIN_LND = LND_min[i];
	Li6CountsCycleStart = numberEventsPerCycle[i];
	Li6CountsValveOpen = numberEventsPerCycleValveOpen[i];
	BaselineDuringIrrad = baseline_during_irrad[i]*BinWidth*prdcur_ave[i];
	Baseline = baseline[i]*BinWidth;
	Amplitude = amp[i];
	RiseTime = tauRise[i];
	FallTime = tauFall[i];
	DELAY = delay[i];
	BaselineDuringIrradErr = baseline_during_irrad_Err[i]*BinWidth*prdcur_ave[i];
	BaselineErr = baselineErr[i]*BinWidth;
	AmplitudeErr = ampErr[i];
	RiseTimeErr = tauRiseErr[i];
	FallTimeErr = tauFallErr[i];
	DELAYErr = delayErr[i];
	UCNIntegral = Integral[i];
	UCNIntegralErr = IntegralErr[i];
	HistIntegral = Li6_integral[i];
	cycleNumber = cycleNumberArray[i] ;
	outputTree->Fill();
      }
      
  

      //***************************************************************
      // Writing the tree
      
      StorageTimeFileCounter++;
      fin->Close();
      delete fin;
      
  }
  cout << "TOTAL NUMBER OF FILES: " << total_counter << endl;
  cout << "TOTAL NUMBER OF FILES ANALYZED: " << fit_counter << endl;
  cout << "TOTAL NUMBER OF CYCLES: " << total_cycle << endl;
  cout << "TOTAL NUMBER OF FITTED CYCLES: " << total_cycle - failfit_cycle << endl;
  cout << (double)fit_counter*100/total_counter << " OF FILES ARE ANALYZED." << endl;

  //outputTree -> Fill();
  //outputTree -> Print();
  
  hfile.Write();
  hfile.Close("R");
  
  
}

