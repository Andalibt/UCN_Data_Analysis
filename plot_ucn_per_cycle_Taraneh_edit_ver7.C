//********************************************************
//             UCN 2017 analysis
//********************************************************
// IN THIS VERSION I LOOP OVER ALL THE EXISTING FILES.
// I ALSO USE THE FOLLOWING FIT FUNCTION TO FIT FOR EACH
// CYCLE.
// THE FIT FUNCTION IS DIFFERENT THAN IN VER6.
// HERE I ALSO ADDED FM5 AND FM5 AVERGE IN CYCLES AND
// THEY ARE IN THE OUTPUT TREE
//*******************************************************

#include <string>
#include <iostream>
using namespace std;
#define max 100


// For fitting error to avoid the program to crash
//__________________________________________________

#include <iostream>
#include <cmath>

//double safe_exp(double x) {
//#if 0 /* 0 or 1 */
//  if (x < -745) x = -745; else if (x > 709) x = 709; else if (std::isnan(x)) x = 0;
//#endif /* 0 or 1 */
//  double v = std::exp(x);
//  if ((!std::isfinite(x)) || (!std::isfinite(v)))
//    std::cout << "Warning : exp( " << x << " ) = " << v << std::endl;
// return v;
//}

//_____________________________________________________

// Fit Functions
Double_t Li6FitFunc (Double_t *x, Double_t *par){
  Double_t Li6_Fit;
  
  // Li6_Fit = ( x[0] < par[1] ) * par[0] + par[2]*( x[0] > par[1] && x[0] < par[3] ) + par[4] * par[5] * (x[0] > par[3] && x[0] < par[6]) + (  x[0] > par[6] )* ( par[7]) * /*( 2./par[10] ) **/ exp((par[8] + par[9]*par[9]/par[10]/2. - x[0] )/( par[10])) * TMath::Erfc ((par[8] + par[9]*par[9]/par[10] - x[0] )/TMath::Sqrt(2.)/par[9]);

  //  Li6_Fit = ( x[0] < par[1] ) * par[0] +( x[0] > par[1] && x[0] < par[3] )*par[2]*par[5] + (x[0] > par[3])*( par[4] + ( par[7]) /** ( 2./par[10] )*/ * exp((par[8] + par[9]*par[9]/par[10]/2. - x[0] )/( par[10])) * TMath::Erfc ((par[8] + par[9]*par[9]/par[10] - x[0] )/TMath::Sqrt(2.)/par[9]));
  
  Li6_Fit = ( x[0] > par[0] && x[0] < par[2] )*par[1]*par[4] + (x[0] > par[2] && x[0] < par[11])*( par[3] + ( par[6] /**( 2./par[9] )*/ * exp((par[7] + par[8]*par[8]/par[9]/2. - x[0]+par[10] )/( par[9])) * TMath::Erfc ((par[7] + par[8]*par[8]/par[9] - x[0]+par[10] )/TMath::Sqrt(2.)/par[8])))+ (x > par[11])*par[12] ;
  
//  // par[0] : Baseline
  // par[0] : irradiation start time
  // par[1] : BaselineIrrad
  // par[2] : cycle start time
  // par[3] : Baseline after irradiation
  // par[4] : average predicted current during the cycle
  // par[5] : cycle valve open time
  // par[6] : amplitude
  // par[7] : gaussian mu
  // par[8] : gaussian sig
  // par[9] : exponential decay constant
  // par[10]: delay
  // par[11]: cycle valve close time
  // par[12]: Baseline after the valve is close

  
  return Li6_Fit;
}

void plot_ucn_per_cycle_Taraneh_edit_ver7(){  
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
  
  TFile hfile ("outputTree_ver7.root", "RECREATE");
  TTree *outputTree = new TTree ("cycle_info", "output tree");
  

  std::string *expNumber = new std::string(); 
  std::string *shifter = new std::string(); 
  std::string *comment = new std::string(); 

  std::vector <int> runNumber;
  for(int i = 0; i < 1000; i++) runNumber.push_back(0.);

  std::vector <double> StartofCycle;
  std::vector <double> cycleValveOpenTimes;
  for(int i = 0; i < StartofCycle.size(); i++) cycleValveOpenTimes.push_back(0.);
  std::vector <double> cycleValveCloseTimes;
  for(int i = 0; i < StartofCycle.size(); i++) cycleValveCloseTimes.push_back(0.);
  std::vector <double> cycleValveOpenDuration;
  for(int i = 0; i < StartofCycle.size(); i++) cycleValveOpenDuration.push_back(0.);
  std::vector <double> cycleDelayTimes;  
  for(int i = 0; i < StartofCycle.size(); i++) cycleDelayTimes.push_back(0.);

  int numcycle;
  
  std::vector <double> AVE_PRDCUR;
  std::vector <double> AVE_TNIM;
  std::vector <double> AVE_B1CUR;
  std::vector <double> AVE_TARGETTEMP1;
  std::vector <double> AVE_TARGETTEMP2;
  std::vector <double> AVE_WTEMP1;
  std::vector <double> AVE_WTEMP2;
  std::vector <double> AVE_COL2UP;
  std::vector <double> AVE_COL2LEFT;
  std::vector <double> AVE_COL2RIGHT;
  std::vector <double> AVE_COL2DOWN;


  std::vector <double> MAX_B1CUR;
  std::vector <double> MIN_B1CUR;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_B1CUR.push_back(0.);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_B1CUR.push_back(300);
  
  std::vector <double> MAX_PRDCUR;
  std::vector <double> MIN_PRDCUR;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_PRDCUR.push_back(0.);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_PRDCUR.push_back(100);
  
  
  std::vector <double> MAX_TNIM;
  std::vector <double> MIN_TNIM;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_TNIM.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_TNIM.push_back(1000);
  
  std::vector <double> MAX_TARGETTEMP1;
  std::vector <double> MIN_TARGETTEMP1;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_TARGETTEMP1.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_TARGETTEMP1.push_back(1000);
  
  std::vector <double> MAX_TARGETTEMP2;
  std::vector <double> MIN_TARGETTEMP2;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_TARGETTEMP2.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_TARGETTEMP2.push_back(1000);
  
  std::vector <double> MAX_WTEMP1;
  std::vector <double> MIN_WTEMP1;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_WTEMP1.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_WTEMP1.push_back(1000);
  
  std::vector <double> MAX_WTEMP2;
  std::vector <double> MIN_WTEMP2;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_WTEMP2.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_WTEMP2.push_back(1000);
  
  
  std::vector <double> MAX_COL2UP;
  std::vector <double> MIN_COL2UP;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_COL2UP.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_COL2UP.push_back(100);
  
  std::vector <double> MAX_COL2RIGHT;
  std::vector <double> MIN_COL2RIGHT;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_COL2RIGHT.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_COL2RIGHT.push_back(100);

  std::vector <double> MAX_COL2LEFT;
  std::vector <double> MIN_COL2LEFT;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_COL2LEFT.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_COL2LEFT.push_back(100);
  
  std::vector <double> MAX_COL2DOWN;
  std::vector <double> MIN_COL2DOWN;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_COL2DOWN.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_COL2DOWN.push_back(100);


  std::vector <double> irradStartTimes;
  for(int i = 0; i < StartofCycle.size(); i++) irradStartTimes.push_back(0);
  std::vector <double> AVE_TS12_IRRAD;
  std::vector <double> AVE_TS12_VALVEOPEN;
  std::vector <double> AVE_FM1;

   
  std::vector <double> MAX_TS12_IRRAD;
  std::vector <double> MIN_TS12_IRRAD;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_TS12_IRRAD.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_TS12_IRRAD.push_back(100);
  
  std::vector <double> MAX_TS12_VALVEOPEN;
  std::vector <double> MIN_TS12_VALVEOPEN;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_TS12_VALVEOPEN.push_back(0);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_TS12_VALVEOPEN.push_back(100);
  
  std::vector <double> MAX_FM1;
  std::vector <double> MIN_FM1;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_FM1.push_back(0.);
  for(int i = 0; i < StartofCycle.size(); i++) MIN_FM1.push_back(100);

  std::vector <double> AVE_FM4;
  std::vector <double> AVE_FM5;
  for(int i = 0; i < StartofCycle.size(); i++) AVE_FM4.push_back(0.);
  for(int i = 0; i < StartofCycle.size(); i++) AVE_FM5.push_back(100);

  
  std::vector <double> AVE_LND;
  std::vector <double> MAX_LND;
  for(int i = 0; i < StartofCycle.size(); i++) MAX_LND.push_back(0.);
  std::vector <double> MIN_LND;
  for(int i = 0; i < StartofCycle.size(); i++) MIN_LND.push_back(1000.);

  Double_t maxXrange = 0, minXrange=1540000000.;
  Int_t BinWidth=5;
  Int_t NBins = 1;
      
  TH2F *psd_vs_ql[16];
  for(int i = 0; i < 16; i++){
    char name[100],title[100];
    sprintf(name,"psd_vs_ql_%i",i);
    sprintf(title,"PSD vs QL ch %i",i); 
    psd_vs_ql[i] = new TH2F(name,title,200,0,15000,200,-1,1);
  }
  
  TH2* UCN_per_cycle_Li6_All = new TH2F("UCN_per_cycle_Li6_Whole_Sequence", "UCN per cycle", 100, minXrange, maxXrange , 100, 0.0, 10000);
  TH2* UCN_per_cycle_Li6_valveOpen = new TH2F("UCN_per_cycle_Li6_valveOpen", "UCN per cycle", 100, minXrange, maxXrange ,100, 0.0, 10000);
  TH1* UCN_rate_li6= new TH1F("UCN_rate_Li6", "UCN-rate Histogram",NBins , minXrange, maxXrange);
  TH2* UCN_per_cycle_He3_Whole_Sequence= new TH2F("UCN_per_cycle_He3_Whole_Sequence", "UCN per cycle",1000 , minXrange, maxXrange, 100, 0.0, 10000);
  TH2* UCN_per_cycle_He3_valveOpen= new TH2F("UCN_per_cycle_He3_valveOpen", "UCN per cycle", 100, minXrange, maxXrange, 100, 0.0, 10000);
  TH1* UCN_rate_He3= new TH1F("UCN_rate_He3", "UCN-rate Histogram", NBins , minXrange, maxXrange);
  THStack *UCN_rate_Li6_all = new THStack("UCN_rate_Li6_all" , " ");


  std::vector <double> BaselineBeforeIrrad;
  for(int i = 0; i < StartofCycle.size(); i++) BaselineBeforeIrrad.push_back(0.);
  std::vector <double> BaselineDuringIrrad;
  for(int i = 0; i < StartofCycle.size(); i++) BaselineDuringIrrad.push_back(0.);
  std::vector <double> BaselineAfterIrrad;
  for(int i = 0; i < StartofCycle.size(); i++) BaselineAfterIrrad.push_back(0.);
  std::vector <double> Amplitude;
  for(int i = 0; i < StartofCycle.size(); i++) Amplitude.push_back(0.);
  std::vector <double> GaussianMean;
  for(int i = 0; i < StartofCycle.size(); i++) GaussianMean.push_back(0.);
  std::vector <double> GaussianSigma;
  for(int i = 0; i < StartofCycle.size(); i++) GaussianSigma.push_back(0.);
  std::vector <double> Tau;
  for(int i = 0; i < StartofCycle.size(); i++) Tau.push_back(0.);
  std::vector <double> BaselineValveClose;
  for(int i = 0; i < StartofCycle.size(); i++) BaselineValveClose.push_back(0.);
  
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
  outputTree -> Branch ("AVE_FM1",&AVE_FM1);
  outputTree -> Branch ("MAX_FM1",&MAX_FM1);
  outputTree -> Branch ("MIN_FM1",&MIN_FM1);
  outputTree -> Branch ("AVE_FM4", &AVE_FM4);
  outputTree -> Branch ("AVE_FM5", &AVE_FM5);
  outputTree -> Branch ("AVE_LNDr", &AVE_LND);
  outputTree -> Branch ("MAX_LNDr", &MAX_LND);
  outputTree -> Branch ("MIN_LNDr", &MIN_LND);
  //  outputTree -> Branch ("BaselineBeforeIrrad" , &BaselineBeforeIrrad);
  outputTree -> Branch ("BaselineDuringIrrad" , &BaselineDuringIrrad);
  outputTree -> Branch ("BaselineAfterIrrad" , &BaselineAfterIrrad);
  outputTree -> Branch ("Amplitude" , &Amplitude);
  outputTree -> Branch ("GaussianMean" , &GaussianMean);
  outputTree -> Branch ("GaussianSigma", &GaussianSigma);
  outputTree -> Branch ("Tau", &Tau);
  outputTree -> Branch ("BaselineValveClose", &BaselineValveClose);
  //outputTree -> Branch ("psd_vs_ql","TH2F",&psd_vs_ql[16]);
  // outputTree -> Branch ("UCN_PER_CYCLE_Li6", &UCN_per_cycle_Li6_All);
  //outputTree -> Branch ("UCN_RATE_Li6",&UCN_rate_li6);
  //outputTree -> Branch ("UCN_PER_CYCLE_He3", &UCN_per_cycle_he3);
  //outputTree -> Branch ("UCN_RATE_He3",&UCN_rate_he3);
  
  // *************************************************************
  // STARTING THE LOOP OVER THE FILES.
  // *************************************************************
  
  for ( midasrun =762 ; midasrun <763 ; midasrun++){
    runNumber.push_back(midasrun);
    runs++;
    cout << midasrun << endl;
    sprintf (filename , "/data/ucn/root_files/ucn_tree_00000%d.root",midasrun);
    // printf("%s\n",filename); 
    
    if (midasrun == 539)
	continue;
    if (midasrun == 549)
	continue;
    if (midasrun == 560)
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
    if (midasrun == 793)
      continue;
    if (midasrun == 797)
      continue;
    if (midasrun == 810)
      continue;
    if (midasrun == 831)
      continue;

    
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
      

   
 

      //I HAVE TO THINK ABOUT THIS STILL
      //------------------------------
      //charng testrun = "-1";
      
      // if (expNumber == testrun){
      //   badrun[runs]=midasrun;
      //   cout << testrun << endl;
      //   badruns_file << badrun[runs] << endl;
      //   continue;
      //   return;
      //  }
      //------------------------------------
  
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

      double cyclevalveopen[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) cyclevalveopen[i]=0;
      double cyclevalveclose[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) cyclevalveclose[i]=0;
      

      truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
      truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime);// time that valve opened
      truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); //time that valve closed
      truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
      truntime->SetBranchAddress("cycleOpenInterval",&valveOpenDuration); // valve open time
      
      eventTot = (Double_t)truntime->GetEntries();
      
      for(ULong64_t j=0;j<eventTot;j++) {
	truntime->GetEvent(j);
	cycleStartTimes.push_back(cycleStart);
	//cycleValveOpenTimes.push_back(valveOpenTime);
	cyclevalveopen[j]=valveOpenTime;
	//	cycleValveCloseTimes.push_back(valveCloseTime);
	cyclevalveclose[j]=valveCloseTime;
	cycleValveOpenDuration.push_back(valveOpenDuration);
	delayTimeArray[j]=delayTime;
	cycleDelayTimes.push_back(delayTime);
	numberEventsPerCycle.push_back(0);
	numberEventsPerCycleValveOpen.push_back(0);
	numcycle=j+1;
      }
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
      for(int i = 0; i < cycleStartTimes.size(); i++) prdcur_ave[i]=0;

      double tnim_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) tnim_ave[i]=0;

      double b1_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) b1_ave[i]=0;

      double targettemp1_ave[max] ;
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp1_ave[i]=0;

      double targettemp2_ave[max];  
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp2_ave[i]=0;

      double wtemp1_ave[max], wtemp2_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp1_ave[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp2_ave[i]=0;

      double col2up_ave[max], col2left_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2up_ave[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2left_ave[i]=0;

      double col2right_ave[max], col2down_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2right_ave[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2down_ave[i]=0;

      double irradiationStartTime[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) irradiationStartTime[i]=0;

      
      double b1_max[max] , b1_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) b1_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) b1_min[i]=1000;

      double prdcur_max[max] , prdcur_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) prdcur_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) prdcur_min[i]=100;

      double tnim_max[max], tnim_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) tnim_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) tnim_min[i]=1000;
      
      double targettemp1_max[max], targettemp1_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp1_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp1_min[i]=100;

      double targettemp2_max[max], targettemp2_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp2_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) targettemp2_min[i]=100;

      double wtemp1_max[max] , wtemp1_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp1_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp1_min[i]=1000;

      double wtemp2_max[max], wtemp2_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp2_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) wtemp2_min[i]=1000;

      double col2up_max[max] , col2up_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2up_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2up_min[i]=100;

      double col2down_max[max] , col2down_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2down_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2down_min[i]=100;

      double col2right_max[max] , col2right_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2right_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2right_min[i]=100;

      double col2left_max[max];
      double col2left_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) col2left_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) col2left_min[i]=100;

      int counter_3=1 , counter_2=1, counter_1 = 1, counter_4 = 1;
      
      double avets12_temperature_irrad[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) avets12_temperature_irrad[i]=0;

      double avets12_temperature_valveOpen[max]; 
      for(int i = 0; i < cycleStartTimes.size(); i++) avets12_temperature_valveOpen[i]=0;

      double fm1_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) fm1_ave[i]=0;
      
      double maxts12_temperature_irrad[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) maxts12_temperature_irrad[i]=0;

      double mints12_temperature_irrad[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) mints12_temperature_irrad[i]=100;

      double maxts12_temperature_valveOpen[max] ;
      for(int i = 0; i < cycleStartTimes.size(); i++) maxts12_temperature_valveOpen[i]=0;

      double mints12_temperature_valveOpen[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) mints12_temperature_valveOpen[i]=100;

      double fm1_max[max], fm1_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) fm1_max[i]=0;
      for(int i = 0; i < cycleStartTimes.size(); i++) fm1_min[i]=1000;

      double fm4_ave[max], fm5_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) fm4_ave[i]=0.;
      for(int i = 0; i < cycleStartTimes.size(); i++) fm5_ave[i]=0.;

      double LND_ave[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) LND_ave[i]=0;
      double LND_max[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) LND_max[i]=0;
      double LND_min[max];
      for(int i = 0; i < cycleStartTimes.size(); i++) LND_min[i]=0;

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

      // LOOP TO CALCULATE MAX, MIN AND AVERAGE
      for ( int i = 0 ; i < cycleStartTimes.size(); i++){
	irradiationStartTime[i] = cycleStartTimes[i] - cycleIrradiationTime[i];
	counter_1=1;	
	counter_2=1;
	counter_3=1;
	counter_4=1;
	for(ULong64_t j=0; j < beamlineEvent ;j++) {
	  BeamlineEpicsTree -> GetEvent(j);
	  beamlineReadTimes.push_back(timestamp_beamline);
	  if (timestamp_beamline > irradiationStartTime[i] && timestamp_beamline < cyclevalveopen[i]) {
	    b1_ave[i]+=B1_FOIL_ADJCUR;
	    prdcur_ave[i]+=B1V_KSM_PREDCUR;
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

	    counter_2++;
	    
	    if(UCN_ISO_TS12_RDTEMP >= maxts12_temperature_irrad[i]){
	      maxts12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
	    }
	    if(UCN_ISO_TS12_RDTEMP <= mints12_temperature_irrad[i]){
	      mints12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
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
	    // cout << counter_1 << endl;
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

	b1_ave[i]=b1_ave[i]/(counter_3-1);
	prdcur_ave[i]=prdcur_ave[i]/(counter_3-1);
	tnim_ave[i]=tnim_ave[i]/(counter_3-1);
	targettemp1_ave[i]=targettemp1_ave[i]/(counter_3-1);
	targettemp2_ave[i]=targettemp2_ave[i]/(counter_3-1);
	wtemp1_ave[i]=wtemp1_ave[i]/(counter_3-1);
	wtemp2_ave[i]=wtemp2_ave[i]/(counter_3-1);
	col2up_ave[i]=col2up_ave[i]/(counter_3-1);
	col2down_ave[i]=col2down_ave[i]/(counter_3-1);
	col2right_ave[i]=col2right_ave[i]/(counter_3-1);
	col2left_ave[i]=col2left_ave[i]/(counter_3-1);
	avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter_2-1);
	fm1_ave[i] = fm1_ave[i]/(counter_2-1);
	fm4_ave[i] = fm4_ave[i]/(counter_2-1);
	fm5_ave[i] = fm5_ave[i]/(counter_2-1);
	avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_1-1);
	LND_ave[i]=LND_ave[i]/counter_4;
		
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

      NBins = (maxXrange - minXrange)/BinWidth ; // I like to have 
      cout  << NBins << " "  << BinWidth<< endl;
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
      Int_t Bins_min[100000];
      Int_t Bins_max[100000];
      Double_t min_range[100000];
      Double_t max_range[100000];


      // Here I find for each cycle, which bin is the start of the cycle and which is the end.
      // This is important because when I want to do the fit, I have to provide a range of values.
      
      for(ULong64_t j=0;j<eventTot;j++) {
	uinli6->GetEvent(j);

	for ( int i = 0; i < cycleStartTimes.size(); i++){
	  min_range[i] = irradiationStartTime[i];
	  max_range[i] = irradiationStartTime[i+1];
	  if(tUnixTimePrecise_li6 >= cycleStartTimes[i] && tUnixTimePrecise_li6 <= cycleStartTimes[i+1]){
	    Bins_min[i] =  UCN_rate_li6 -> GetXaxis() -> FindBin(cycleStartTimes[i]);
	    Bins_max[i] =  UCN_rate_li6 -> GetXaxis() -> FindBin(cycleStartTimes[i+1]);
	  }
	}
      }
      
      // Here I find how many counts are in each cycle (I calculate the integral).
      // This is useful to find the scale of the histogram to put the right initial values.
      for ( int i = 0; i < cycleStartTimes.size(); i++){
	if ( i == cycleStartTimes.size()-1){
	  if (i >1){
	  Bins_min[i] = Bins_max[i-1];
	  Bins_max[i] = NBins;
	  }
	}
	if ( i == 0){
	  Bins_min[i] = 1;
	}
	if (i == cycleStartTimes.size()-1 ){
	  max_range[i] = maxXrange;
	}
	if (cycleStartTimes.size() == 1){
	  Bins_max[i] = NBins;
	}
	//cout << "Bin min " << Bins_min[i] << " Bin max" << Bins_max[i] << endl;
	UCN_rate_li6 -> GetXaxis()-> SetRange(Bins_min[i] , Bins_max[i]);
	Li6_integral[i] = UCN_rate_li6 -> Integral(Bins_min[i] , Bins_max[i]);
	scale[i] = norm/ (Li6_integral[i]);
	//UCN_rate_li6 -> Scale(scale[i]);
	Li6Max[i] = UCN_rate_li6 -> GetMaximum();
	mu_li6[i] = UCN_rate_li6 -> GetMean();
	//cout << "integral " << Li6_integral[i] << " ,Li6Max " << Li6Max[i] << " ,Mu " << mu_li6[i] << ",Scale" << scale[i] <<  endl;
	//cout << "min range " << min_range[i] << ",max range" << max_range[i] << endl;
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
      
      TH2* UCN_per_cycle_he3 = new TH2F("UCN_per_cycle_He3", "UCN per cycle", 100, 0.0, 10000, 100, 1500000000, 153000000);
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
      Double_t baseline_before_irrad[max];
      Double_t baseline_during_irrad[max];
      Double_t baseline_after_irrad[max];
      Double_t baseline_valveClose[max];
      Double_t amp[max];
      Double_t Gmu[max];
      Double_t Gsig[max];
      Double_t tau_li6[max];

      Double_t par1Err;
      Double_t par3Err;
      Double_t par6Err;
      Double_t par7Err;
      Double_t par8Err;
      Double_t par9Err;
      Double_t par10Err;
      Double_t par12Err;


      
      for (int i=0 ; i < cycleStartTimes.size(); i++){

	//UCN_rate_li6 -> Scale(scale[i]);
	cout << "min range " << min_range[i] << " max range " << max_range[i] << endl;
	TF1 *Li6_Fit_Func = new TF1("Li6FitFunc", Li6FitFunc ,min_range[i] , max_range[i] , 13);
	//	// par[0] : Background
	// par[0] : irradiation start time
	// par[1] : BackgroundIrrad
	// par[2] : cycle start time
	// par[3] : Background after irradiation
	// par[4] : average predicted current during the cycle
	// par[5] : cycle valve open time
	// par[6] : amplitude
	// par[7] : gaussian mu
	// par[8] : gaussian sig
	// par[9] : exponential decay constant
	// par[10]: delay
	// par[11]: cycle valve close time
	// par[12]: Baseline after the valve is close
	//Li6_Fit_Func -> SetParName(0, "Baseline before irradiation");
	Li6_Fit_Func -> SetParName(0, "Irradiation Start Time");
	Li6_Fit_Func -> SetParName(1, "Baseline during irradiation");
	Li6_Fit_Func -> SetParName(2, "cycle start time");
	Li6_Fit_Func -> SetParName(3, "Baseline after irradiaton");
	Li6_Fit_Func -> SetParName(4, "Average predicted current");
	Li6_Fit_Func -> SetParName(5, "Cycle valve open time");
	Li6_Fit_Func -> SetParName(6, "Amplitude");
	Li6_Fit_Func -> SetParName(7, "Gaussian mu");
	Li6_Fit_Func -> SetParName(8, "Gaussian sigma");
	Li6_Fit_Func -> SetParName(9, "exponential decay constant");
	Li6_Fit_Func -> SetParName(10, "delay");
	Li6_Fit_Func -> SetParName(11, "cycle valve close time");
	Li6_Fit_Func -> SetParName(12, "baseline after valve close");
	//Li6_Fit_Func -> SetParameter(0, 0);
	Li6_Fit_Func -> FixParameter(0, irradiationStartTime[i]);
	Li6_Fit_Func -> SetParameter(1, 15);
	Li6_Fit_Func -> SetParLimits(1,0,150);
	Li6_Fit_Func -> FixParameter(2, cycleStartTimes[i]);
	Li6_Fit_Func -> SetParameter(3, 0);
	Li6_Fit_Func -> SetParLimits(3,0,10);
	Li6_Fit_Func -> FixParameter(4, prdcur_ave[i]);
	Li6_Fit_Func -> FixParameter(5, cyclevalveopen[i]);
	Li6_Fit_Func -> SetParameter(6, (int)Li6Max[i]/2);
	Li6_Fit_Func -> SetParLimits(6, Li6Max[i]/2 , Li6Max[i]);
	Li6_Fit_Func -> SetParameter(7, mu_li6[i]);
	Li6_Fit_Func -> SetParLimits(7,  mu_li6[i]-20,  mu_li6[i] + 20);
	Li6_Fit_Func -> SetParameter(8, 0.2);
	Li6_Fit_Func -> SetParLimits(8, 0.1, 0.5);
	Li6_Fit_Func -> SetParameter(9, 40);
	Li6_Fit_Func -> SetParLimits(9, 20,50);
	Li6_Fit_Func -> GetParError(9);
	Li6_Fit_Func -> SetParameter(10, 10);
	Li6_Fit_Func -> SetParLimits(10, 0 , 10);
	Li6_Fit_Func -> FixParameter(11, cyclevalveclose[i]);
	Li6_Fit_Func -> SetParameter(12,5 );
	Li6_Fit_Func -> SetParLimits(12, 0,15);
	Li6_Fit_Func -> SetNpx(10000);
	par1Err = Li6_Fit_Func -> GetParError(1);
	par3Err = Li6_Fit_Func -> GetParError(3);
	par6Err = Li6_Fit_Func -> GetParError(6);
	par7Err = Li6_Fit_Func -> GetParError(7);
	par8Err = Li6_Fit_Func -> GetParError(8);
	par9Err = Li6_Fit_Func -> GetParError(9);	
	par10Err = Li6_Fit_Func -> GetParError(10);
	par12Err = Li6_Fit_Func -> GetParError(12);
	//baseline_before_irrad[i] = Li6_Fit_Func -> GetParameter(0);
	baseline_during_irrad[i] = Li6_Fit_Func -> GetParameter(1);
	baseline_after_irrad[i] = Li6_Fit_Func -> GetParameter(3);
	amp[i] = Li6_Fit_Func -> GetParameter(6);
	Gmu[i] = Li6_Fit_Func -> GetParameter(7);
	Gsig[i] = Li6_Fit_Func -> GetParameter(8);
	tau_li6[i] = Li6_Fit_Func -> GetParameter(9);
	baseline_valveClose[i] = Li6_Fit_Func -> GetParameter(12);
	Li6_Fit_Func-> Draw("");
	UCN_rate_li6->Fit(Li6_Fit_Func,"R+");
	cout << "***********************************************************" << endl;
      }
      
      
     
      UCN_rate_li6 -> SetBins(NBins, minXrange , maxXrange);
      UCN_rate_Li6_all -> Add (UCN_rate_li6);
      //***********************************************************************
      // FILLING THE TREE     
      //***********************************************************************
      
      for ( int i = 0 ; i < cycleStartTimes.size(); i++ ){
	irradStartTimes.push_back(irradiationStartTime[i]);
	StartofCycle.push_back(cycleStartTimes[i]);
	cycleValveOpenTimes.push_back(cyclevalveopen[i]);
	cycleValveCloseTimes.push_back(cyclevalveclose[i]);
	AVE_B1CUR.push_back(b1_ave[i]);
	AVE_PRDCUR.push_back(prdcur_ave[i]);
	AVE_TNIM.push_back(tnim_ave[i]);
	AVE_TARGETTEMP1.push_back(targettemp1_ave[i]);
	AVE_TARGETTEMP2.push_back(targettemp2_ave[i]);	   
	AVE_WTEMP1.push_back(wtemp1_ave[i]);
	AVE_WTEMP2.push_back(wtemp2_ave[i]);
	AVE_COL2UP.push_back(col2up_ave[i]);
	AVE_COL2DOWN.push_back(col2down_ave[i]);
	AVE_COL2RIGHT.push_back(col2right_ave[i]);
	AVE_COL2LEFT.push_back(col2left_ave[i]);
	AVE_TS12_IRRAD.push_back (avets12_temperature_irrad[i]);
	AVE_TS12_VALVEOPEN.push_back(avets12_temperature_valveOpen[i]);
	AVE_FM1.push_back (fm1_ave[i]);
	AVE_FM4.push_back (fm4_ave[i]);
	AVE_FM5.push_back (fm5_ave[i]);
	MAX_B1CUR.push_back( b1_max[i] );
	MIN_B1CUR.push_back( b1_min[i] );
	MAX_PRDCUR.push_back( prdcur_max[i] );
	MIN_PRDCUR.push_back( prdcur_min[i] );
	MAX_TNIM.push_back( tnim_max[i] );
	MIN_TNIM.push_back( tnim_min[i] );
	MAX_TARGETTEMP1.push_back( targettemp1_max[i] );
	MIN_TARGETTEMP1.push_back( targettemp1_min[i] );
	MAX_TARGETTEMP2.push_back( targettemp2_max[i] );
	MIN_TARGETTEMP2.push_back( targettemp2_min[i] );
	MAX_WTEMP1.push_back( wtemp1_max[i] );
	MIN_WTEMP1.push_back( wtemp1_min[i] );
	MAX_WTEMP2.push_back( wtemp2_max[i] );
	MIN_WTEMP2.push_back( wtemp2_min[i] );
	MAX_COL2UP.push_back( col2up_max[i] );
	MIN_COL2UP.push_back( col2up_min[i] );
	MAX_COL2DOWN.push_back( col2down_max[i] );
	MIN_COL2DOWN.push_back( col2down_min[i] );
	MAX_COL2RIGHT.push_back(col2right_max[i] );
	MIN_COL2RIGHT.push_back(col2right_min[i] );
	MAX_COL2LEFT.push_back( col2left_max[i] );
	MIN_COL2LEFT.push_back( col2left_min[i] );
	MAX_TS12_IRRAD.push_back( maxts12_temperature_irrad[i] );
	MIN_TS12_IRRAD.push_back( mints12_temperature_irrad[i] );
       	MAX_TS12_VALVEOPEN.push_back( maxts12_temperature_valveOpen[i]);
       	MIN_TS12_VALVEOPEN.push_back( mints12_temperature_valveOpen[i]);
	MAX_FM1.push_back(fm1_max[i]);
	MIN_FM1.push_back(fm1_min[i]);
	AVE_LND.push_back(LND_ave[i]);
	MAX_LND.push_back(LND_max[i]);
	MIN_LND.push_back(LND_min[i]);
	//	BaselineBeforeIrrad.push_back( baseline_before_irrad[i]*scale);
	BaselineDuringIrrad.push_back(baseline_during_irrad[i]*BinWidth);
	BaselineAfterIrrad.push_back(baseline_after_irrad[i]*BinWidth*prdcur_ave[i]);
	Amplitude.push_back(amp[i]);
	GaussianMean.push_back(Gmu[i]);
	GaussianSigma.push_back(Gsig[i]);
	Tau.push_back(tau_li6[i]);
      }
      
  
      
     
      //***************************************************************
      // Writing the tree
      

      fin->Close();
      delete fin;
      
  }

  outputTree -> Fill();
  //  outputTree -> Print();
  
  hfile -> Write();
  hfile-> Close("R");
  
  
}

