//********************************************************
//             UCN 2017 analysis
//********************************************************
// IN THIS VERSION I LOOP OVER ALL THE EXISTING FILES.
//*******************************************************

#include <string>
#define max 1000

void plot_ucn_per_cycle_Taraneh_edit_ver4(){  
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
  
  TFile hfile ("outputTree.root", "UPDATE");
  TTree *outputTree = new TTree ("cycle_info", "output tree");
  
  
  std::string *expNumber = new std::string(); 
  std::string *shifter = new std::string(); 
  std::string *comment = new std::string(); 

  std::vector <double> cycleStartTimes;
  std::vector <double> cycleValveOpenTimes;
  std::vector <double> cycleValveCloseTimes;
  std::vector <double> cycleValveOpenDuration;
  std::vector <double> cycleDelayTimes;  

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


  std::vector<double> MAX_B1CUR;
  std::vector<double> MIN_B1CUR;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_B1CUR.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_B1CUR.push_back(300);
  
  std::vector<double> MAX_PRDCUR;
  std::vector<double> MIN_PRDCUR;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_PRDCUR.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_PRDCUR.push_back(100);
  
  
  std::vector<double> MAX_TNIM;
  std::vector<double> MIN_TNIM;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_TNIM.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_TNIM.push_back(1000);
  
  std::vector<double> MAX_TARGETTEMP1;
  std::vector<double> MIN_TARGETTEMP1;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_TARGETTEMP1.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_TARGETTEMP1.push_back(1000);
  
  std::vector<double> MAX_TARGETTEMP2;
  std::vector<double> MIN_TARGETTEMP2;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_TARGETTEMP2.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_TARGETTEMP2.push_back(1000);
  
  std::vector<double> MAX_WTEMP1;
  std::vector<double> MIN_WTEMP1;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_WTEMP1.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_WTEMP1.push_back(1000);
  
  std::vector<double> MAX_WTEMP2;
  std::vector<double> MIN_WTEMP2;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_WTEMP2.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_WTEMP2.push_back(1000);
  
  
  std::vector<double> MAX_COL2UP;
  std::vector<double> MIN_COL2UP;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_COL2UP.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_COL2UP.push_back(100);
  
  std::vector<double> MAX_COL2RIGHT;
  std::vector<double> MIN_COL2RIGHT;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_COL2RIGHT.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_COL2RIGHT.push_back(100);

  std::vector<double> MAX_COL2LEFT;
  std::vector<double> MIN_COL2LEFT;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_COL2LEFT.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_COL2LEFT.push_back(100);

  std::vector<double> MAX_COL2DOWN;
  std::vector<double> MIN_COL2DOWN;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_COL2DOWN.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_COL2DOWN.push_back(100);


  std::vector <double> irradStartTimes;
  std::vector <double> AVE_TS12_IRRAD;
  std::vector <double> AVE_TS12_VALVEOPEN;
  std::vector <double> AVE_FM1;

   
  std::vector<double> MAX_TS12_IRRAD;
  std::vector<double> MIN_TS12_IRRAD;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_TS12_IRRAD.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_TS12_IRRAD.push_back(100);
  
  std::vector<double> MAX_TS12_VALVEOPEN;
  std::vector<double> MIN_TS12_VALVEOPEN;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_TS12_VALVEOPEN.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_TS12_VALVEOPEN.push_back(100);
  
  std::vector<double> MAX_FM1;
  std::vector<double> MIN_FM1;
  for(int i = 0; i < cycleStartTimes.size(); i++) MAX_FM1.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) MIN_FM1.push_back(100);
  

  // Create branches. 
  outputTree -> Branch ("expNumber" , &expNumber );
  outputTree -> Branch ("shifter", &shifter);
  outputTree -> Branch ("comment", &comment);
  outputTree -> Branch ("irradStartTimes",&irradStartTimes);
  outputTree -> Branch ("cycleStartTimes" , &cycleStartTimes );
  outputTree -> Branch ("cycleValveOpenTime", &cycleValveOpenTimes);
  outputTree -> Branch ("cycleValveCloseTime", &cycleValveCloseTimes);
  outputTree -> Branch ("cycleDelayTime", &cycleDelayTimes);
  outputTree -> Branch ("cycleValveOpenDuration", &cycleValveOpenDuration);
  outputTree -> Branch ("numcycle", &numcycle);
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


  // *************************************************************
  // STARTING THE LOOP OVER THE FILES.
  // *************************************************************

  for ( midasrun =523 ; midasrun <524 ; midasrun++){
    runs++;
    cout << midasrun << endl;
    sprintf (filename , "/data/ucn/root_files/ucn_tree_00000%d.root",midasrun);
    printf("%s\n",filename); 
    
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
      
      cout<<"**********************************************************"<<endl;
      std::cout << "The Experiment Number is:" << *expNumber << std::endl;
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
      ULong64_t eventTot;
      //numcycle = 0;
      

      double cycleStart;
      double valveOpenTime;
      double valveCloseTime;
      double delayTime;
      double valveOpenDuration;

      truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
      truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime);// time that valve opened
      truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); //time that valve closed
      truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
      truntime->SetBranchAddress("cycleOpenInterval",&valveOpenDuration); // valve open time
      
      eventTot = (Double_t)truntime->GetEntries();
      
      for(ULong64_t j=0;j<eventTot;j++) {
	truntime->GetEvent(j);
	cycleStartTimes.push_back(cycleStart);
	cycleValveOpenTimes.push_back(valveOpenTime);
	cycleValveCloseTimes.push_back(valveCloseTime);
	cycleValveOpenDuration.push_back(valveOpenDuration);
	cycleDelayTimes.push_back(delayTime);
	numberEventsPerCycle.push_back(0);
	numcycle=j+1;
      }
      cout << "Total number of cycles in this run is " << numcycle << endl;
      cout<<"**********************************************************"<<endl;
      
      //**************************************************************************
      //  Irradiation start and stop time
      //  Irradiation time
      //  This information is in the  "BeamlineEpicsTree;1" and in the
      //  "B1V_KSM_RDBEAMON_VAL1" and "B1V_KSM_RDBEAMOFF_VAL1" branch.
      
      
      TTree* BeamlineEpicsTree = (TTree*) fin-> Get ("BeamlineEpicsTree");
      std::vector<double> beamlineReadTimes;
      std::vector<int> beamlineFoundEntry;
      for(int i = 0; i < cycleStartTimes.size(); i++) beamlineFoundEntry.push_back(0);
      
      
      std::vector<double> cycleIrradiationTime;
      std::vector<double> cycleB1U_BeamCurrent;
      std::vector<double> cycleB1_BeamCurrent;
      std::vector<double> cycleB1V_Fraction;
      std::vector<double> cycleTNIM_raw;
      
      
      double B1V_KSM_RDBEAMON_VAL1, B1V_KSM_PREDCUR, B1_FOIL_ADJCUR, B1V_KSM_PREDCUR_last = 0;
      double B1V_KSM_RDFRCTN_VAL1, B1U_TNIM2_RAW;
      double B1U_TGTTEMP1_RDTEMP, B1U_TGTTEMP2_RDTEMP; //Target Temperature
      double B1U_WTEMP1_RDTEMP, B1U_WTEMP2_RDTEMP;
      double B1U_COL2RIGHT_RDTEMP, B1U_COL2DOWN_RDTEMP, B1U_COL2UP_RDTEMP,B1U_COL2LEFT_RDTEMP;
      int timestamp_beamline;
      
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
  
  
      double prdcur_ave=0, tnim_ave=0, b1_ave=0, targettemp1_ave = 0, targettemp2_ave=0;  //These all should have been vectors
      double wtemp1_ave=0, wtemp2_ave=0 ;
      double col2up_ave=0, col2left_ave=0, col2right_ave=0, col2down_ave=0;
      double irradiationStartTime[max];
      
      double b1_max=0, b1_min=300;
      double prdcur_max = 0 , prdcur_min = 100;
      double tnim_max = 0, tnim_min = 1000;
      double targettemp1_max = 0, targettemp1_min = 1000;
      double targettemp2_max = 0, targettemp2_min = 1000;
      double wtemp1_max = 0 , wtemp1_min = 1000;
      double wtemp2_max = 0 , wtemp2_min = 1000;
      double col2up_max = 0 , col2up_min = 100;
      double col2down_max = 0 , col2down_min = 100;
      double col2right_max = 0 , col2right_min = 100;
      double col2left_max = 0 , col2left_min = 100;
      int counter_3=1, final_counter=1, oldi_3=0;
      
      Double_t beamlineEvent = (Double_t) BeamlineEpicsTree-> GetEntries();

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

      
          
      // THIS LOOP IS FOR BEAMLINE EPICS TO CALCULATE THE AVERAGE, MIN AND MAX.
      for(ULong64_t j=0;j < beamlineEvent ;j++) {
	BeamlineEpicsTree -> GetEvent(j);
	beamlineReadTimes.push_back(timestamp_beamline);
	for (int i=0 ; i < cycleStartTimes.size(); i++ ){
	  irradiationStartTime[i] = cycleStartTimes[i] - cycleIrradiationTime[i];
	  //---------------------
	  // IRRADIATION CYCLE 
	  // ----------------------    
	  if (timestamp_beamline > irradiationStartTime && timestamp_beamline < cycleValveOpenTimes[i]){ 
	    if (oldi_3!=i ){
	      // This loop means that we are within the next cycle. so we can get the 
	      // average temperatures for the previous cycle.
	      //cout << ".................................."<< endl;
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

	      irradStartTimes.push_back(irradiationStartTime[i]);
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
	      cout << "it gets to here" << endl;
	      
	      counter_3=1;
	      b1_ave[i]=0;
	      prdcur_ave[i]=0;
	      tnim_ave[i]=0;
	      targettemp1_ave[i]=0;
	      targettemp2_ave[i]=0;
	      wtemp1_ave[i]=0;
	      wtemp2_ave[i]=0;
	      col2up_ave[i]=0;
	      col2down_ave[i]=0;
	      col2right_ave[i]=0;
	      col2left_ave[i]=0;
	    } 
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
	    oldi_3=i;
	    
	    if(B1_FOIL_ADJCUR > b1_max[i]){
	      b1_max[i]=B1_FOIL_ADJCUR;
	    }
	    if(B1_FOIL_ADJCUR< b1_min[i]){
	      b1_min[i]=B1_FOIL_ADJCUR;
	    }
	    if (B1V_KSM_PREDCUR> prdcur_max[i]){
	      prdcur_max[i]=B1V_KSM_PREDCUR;
	    }
	    if (B1V_KSM_PREDCUR < prdcur_min[i]){
	      prdcur_min[i]=B1V_KSM_PREDCUR;
	    }
	    if (B1U_TNIM2_RAW> tnim_max[i]){
	      tnim_max[i]= B1U_TNIM2_RAW;
	    }
	    if (B1U_TNIM2_RAW < tnim_min[i]){
	      tnim_min[i]=B1U_TNIM2_RAW;
	    }
	    if (B1U_TGTTEMP1_RDTEMP> targettemp1_max[i]){
	      targettemp1_max[i]=B1U_TGTTEMP1_RDTEMP ;
	    }
	    if (B1U_TGTTEMP1_RDTEMP < targettemp1_min[i]){
	      targettemp1_min[i]=B1U_TGTTEMP1_RDTEMP;
	    }
	    if (B1U_TGTTEMP2_RDTEMP> targettemp2_max[i]){
	      targettemp2_max[i]=B1U_TGTTEMP2_RDTEMP ;
	    }
	    if (B1U_TGTTEMP2_RDTEMP < targettemp2_min[i]){
	      targettemp2_min[i]=B1U_TGTTEMP2_RDTEMP;
	    }
	    if (B1U_WTEMP1_RDTEMP> wtemp1_max[i]){
	      wtemp1_max[i]=B1U_WTEMP1_RDTEMP ;
	    }
	    if (B1U_WTEMP1_RDTEMP < wtemp1_min[i]){
	      wtemp1_min[i]=B1U_WTEMP1_RDTEMP;
	    }
	    if (B1U_WTEMP2_RDTEMP> wtemp2_max[i]){
	      wtemp2_max[i]=B1U_WTEMP2_RDTEMP ;
	    }
	    if (B1U_WTEMP2_RDTEMP < wtemp2_min[i]){
	      wtemp2_min[i]=B1U_WTEMP2_RDTEMP;
	    }
	    if (B1U_COL2UP_RDTEMP > col2up_max[i] ){
	      col2up_max[i]=B1U_COL2UP_RDTEMP;
	    }
	    if (B1U_COL2UP_RDTEMP < col2up_min[i] ){
	      col2up_min[i]=B1U_COL2UP_RDTEMP;
	    }
	    if (B1U_COL2DOWN_RDTEMP > col2down_max[i] ){
	      col2down_max[i]=B1U_COL2DOWN_RDTEMP;
	    }
	    if (B1U_COL2DOWN_RDTEMP < col2down_min[i] ){
	      col2down_min[i]=B1U_COL2DOWN_RDTEMP;
	    }
	    if (B1U_COL2RIGHT_RDTEMP > col2right_max[i] ){
	      col2right_max[i]=B1U_COL2RIGHT_RDTEMP;
	    }
	    if (B1U_COL2RIGHT_RDTEMP < col2right_min[i] ){
	      col2right_min[i]=B1U_COL2RIGHT_RDTEMP;
	    }
	    if (B1U_COL2LEFT_RDTEMP > col2left_max[i] ){
	      col2left_max[i]=B1U_COL2LEFT_RDTEMP;
	    }
	    if (B1U_COL2LEFT_RDTEMP < col2left_min[i] ){
	      col2left_min[i]=B1U_COL2LEFT_RDTEMP;
	    }	
	  }
	  
	  if(timestamp_beamline > cycleValveCloseTimes[i] ){
	    if (i==cycleStartTimes.size()-1 && oldi_3==i &&  final_counter==1){ 
	      
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
	      
	      
	      final_counter++;
	    } 
	  } 
	} 
      }
      
      
      final_counter=1;
      
     
      //***************************************************************************
      //Average, max, min isopure temperature during irradiation (plus IV1 delay): 
      //average over irradiation time of TS12
      //The temperature must be in the sourceEpicsTree
      
      TTree* sourceTree = (TTree*) fin->Get("SourceEpicsTree");
      double UCN_ISO_TS12_RDTEMP;
      double UCN_HE3_FM1_RDFLOW;
      int timestamp;
      std::vector<double> sourceReadTimes;
      
      
      //that was for initializing.
      std::vector<double> temperaturePerCycle;
      Double_t irradiationStartTime;
      double avets12_temperature_irrad=0,avets12_temperature_valveOpen=0, fm1_ave=0;
      

      double maxts12_temperature_irrad = 0 , mints12_temperature_irrad = 100;
      double maxts12_temperature_valveOpen = 0 , mints12_temperature_valveOpen = 100;
      double fm1_max = 0, fm1_min = 100;

      
      sourceTree->SetBranchAddress("UCN_ISO_TS12_RDTEMP",&UCN_ISO_TS12_RDTEMP);
      sourceTree->SetBranchAddress("UCN_HE3_FM1_RDFLOW",&UCN_HE3_FM1_RDFLOW);
      sourceTree->SetBranchAddress("timestamp",&timestamp);
      int counter=1, counter_2=1;
      int oldi=0, oldi_2=0 ;
      
      eventTot = (Double_t)sourceTree->GetEntries();
      for(ULong64_t j=0;j<eventTot;j++) {
	sourceTree->GetEvent(j);
	sourceReadTimes.push_back(timestamp);
	for(int i = 0; i < cycleStartTimes.size(); i++){
	  //checks within which cycle we are.
	  irradiationStartTime[i] = cycleStartTimes[i] - cycleIrradiationTime[i];
	  //---------------------
	  // IRRADIATION CYCLE 
	  // ----------------------
	  if(timestamp > irradiationStartTime && timestamp < cycleValveOpenTimes[i]){
	    if (oldi!=i ){
	      // This loop means that we are within the next cycle. so we can get the 
	      // average temperatures for the previous cycle.
	      avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter-1);
	      fm1_ave[i]=fm1_ave[i]/(counter-1);
	      AVE_TS12_IRRAD.push_back ( avets12_temperature_irrad[i]);
	      AVE_FM1.push_back (fm1_ave[i]);
	      counter=1;
	      avets12_temperature_irrad[i]=0;
	      fm1_ave[i]=0;
	    }
	    avets12_temperature_irrad[i]+=UCN_ISO_TS12_RDTEMP;
	    fm1_ave[i]+=UCN_HE3_FM1_RDFLOW;
	    counter++;
	    oldi=i;
	    
	    if(UCN_ISO_TS12_RDTEMP > maxts12_temperature_irrad[i]){
	      maxts12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
	    }
	    if(UCN_ISO_TS12_RDTEMP < mints12_temperature_irrad[i]){
	      mints12_temperature_irrad[i] = UCN_ISO_TS12_RDTEMP;
	    }
	    if(UCN_HE3_FM1_RDFLOW > fm1_max[i]){
	      fm1_max[i]=UCN_HE3_FM1_RDFLOW;
	    }
	    if(UCN_HE3_FM1_RDFLOW < fm1_min[i]){
	      fm1_min[i]=UCN_HE3_FM1_RDFLOW;
	    }		
	  }
	  //----------------------------
	  // VALVE OPEN CYCLE
	  //---------------------------
	  if (timestamp > cycleValveOpenTimes[i] && timestamp < cycleValveCloseTimes[i]){	
	    if (oldi_2!=i ){
	      avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_2-1);
	      AVE_TS12_VALVEOPEN.push_back(avets12_temperature_valveOpen[i]);
	      counter_2=1;
	      avets12_temperature_valveOpen[i]=0;
	    }
	    avets12_temperature_valveOpen[i]+=UCN_ISO_TS12_RDTEMP;
	    counter_2++;
	    oldi_2=i;
	    
	    if(UCN_ISO_TS12_RDTEMP > maxts12_temperature_valveOpen[i]){
	      maxts12_temperature_valveOpen[i] = UCN_ISO_TS12_RDTEMP;
	    }
	    if(UCN_ISO_TS12_RDTEMP < mints12_temperature_valveOpen[i]){
	      mints12_temperature_valveOpen[i] = UCN_ISO_TS12_RDTEMP;
	    }	
	  }
	  
	  if(timestamp > cycleValveCloseTimes[i] ){
	    if (i==cycleStartTimes.size()-1 && oldi==i && oldi_2 ==i && final_counter==1){ 
	      avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter-1);
	      fm1_ave[i]=fm1_ave[i]/(counter-1);
	      avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_2-1);
	      
	      AVE_TS12_IRRAD.push_back ( avets12_temperature_irrad[i]);
	      AVE_FM1.push_back (fm1_ave[i]);
	      AVE_TS12_VALVEOPEN.push_back(avets12_temperature_valveOpen[i]);
	      
	      final_counter++;
	    } 
	  }
	}
      }
      
      
      for ( int i = 0 ; i <= numcycle ; i++ ){
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
	MAX_COL2RIGHT.push_back( col2right_max[i] );
	MIN_COL2RIGHT.push_back( col2right_min[i] );
	MAX_COL2LEFT.push_back( col2left_max[i] );
	MIN_COL2LEFT.push_back( col2left_min[i] );
	MAX_TS12_IRRAD.push_back( maxts12_temperature_irrad[i] );
	MIN_TS12_IRRAD.push_back( mints12_temperature_irrad[i] );
	MAX_TS12_VALVEOPEN.push_back(  maxts12_temperature_valveOpen[i]);
	MIN_TS12_VALVEOPEN.push_back(  mints12_temperature_valveOpen[i]);
	MAX_FM1.push_back( fm1_max[i]);
	MIN_FM1.push_back( fm1_min[i]);
      }


      //*****************************************************************************
      // UCN hits
      // This information is all in the UCNhits_Li-6 tree

      TTree* uin = (TTree*) fin->Get("UCNHits_Li-6");
      

      double tUnixTimePrecise, tUnixTime;
      Float_t tPSD;  
      UShort_t tChargeL;
      UShort_t tIsUCN, tChannel;
      
      uin->SetBranchAddress("tUnixTimePrecise",&tUnixTimePrecise);
      uin->SetBranchAddress("tUnixTime",&tUnixTime);
      uin->SetBranchAddress("tIsUCN",&tIsUCN);
      uin->SetBranchAddress("tChannel",&tChannel);
      uin->SetBranchAddress("tPSD",&tPSD);
      uin->SetBranchAddress("tChargeL",&tChargeL);
      
      // Make plots to show PSD vs QL for all 16 channels.
      
      TH2F *psd_vs_ql[16];
      for(int i = 0; i < 16; i++){
	char name[100],title[100];
	sprintf(name,"psd_vs_ql_%i",i);
	sprintf(title,"PSD vs QL ch %i",i); 
	psd_vs_ql[i] = new TH2F(name,title,200,0,15000,200,-1,1);
      }



      // pointer for closeSourceEPics reads;
      int source_index = 0;
      
      
      
      // This is for during the whole sequence.
      eventTot = (Double_t)uin->GetEntries();
      for(ULong64_t j=0;j<eventTot;j++) {
	uin->GetEvent(j);
	//Check if this is a UCN hit.
	if(tIsUCN && cycleStartTimes.size() > 1){
	  // check which cycle this is in...
	  for(int i = 0; i < cycleStartTimes.size()-1; i++){
	    if(tUnixTimePrecise >= cycleStartTimes[i] && tUnixTimePrecise < cycleStartTimes[i+1]){
 	  numberEventsPerCycle[i]++;
 	  break;
	    }
	  }
	}
	psd_vs_ql[tChannel]->Fill(tChargeL,tPSD);
      }
      
      
      // Plot PSD vs QL
      //
      TCanvas *c1 = new TCanvas("c1","PSD vs QL",1200,800);
      c1->Divide(4,3);
      for(int i = 0; i < 12; i++){
	c1->cd(i+1);
	psd_vs_ql[i]->Draw("COL");
      }
      
      //Plot the UCN counts per cycle
      
      TCanvas *c2 = new TCanvas("c2","UCN vs cycle");
      TH2* UCN_vs_cycle = new TH2F("UCN_vs_cycle", "UCN vs cycle", 100, 0.0, 10000, 100, 1500000000, 152000000);
      if(cycleStartTimes.size() > 0){
	for( int i = 0; i < cycleStartTimes.size()-1; i++){
	  UCN_vs_cycle->Fill(cycleStartTimes[i],numberEventsPerCycle[i]);
	}
	UCN_vs_cycle->SetMarkerStyle(20);
	UCN_vs_cycle->Draw("PLC PMC");
      }
      /*
	TCanvas *c3 = new TCanvas("c3","UCN-rate Histogram");
	TH1* UCN_rate= new TH1F("UCN_rate", "UCN-rate Histogram", 10, 1500000000, 152000000);
	
	for(ULong64_t j=0;j<eventTot;j++) {
	uin->GetEvent(j);
	if (tIsUCN >0 && tUnixTime >20e6 && cycleStartTimes.size() > 1){
	for(int i = 0; i < cycleStartTimes.size()-1; i++){
	UCN_rate->Fill (tUnixTimePrecise );
	//std::cout << tUnixTimePrecise << endl;
	}
	}
	}
	//UCN_rate-> GetXaxis()->SetRange(
	UCN_rate->Draw("");
	
      */
      
      
      
      
      
      //**************************************************************
      // FOR THE WARNINGS
      //*************************************************************
      gROOT->SetBatch(kTRUE); // To get rid of empty canvas pop up
      
      
      
      
      
      

      //***************************************************************
      // Writing the tree
      

      fin->Close();
      delete fin;
      
  }
  outputTree -> Fill();
  outputTree -> Print();
      
  hfile ->Write();
  hfile-> Close("R");
  
  
}

