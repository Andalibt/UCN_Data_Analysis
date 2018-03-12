//********************************************************
//             UCN 2017 analysis
//********************************************************
// IN THIS VERSION I WILL WRITE THE OUTPUTS IN A ROOT TREE
//*******************************************************
void plot_ucn_per_cycle_Taraneh_edit_ver3(std::string infile){
  
  // Get the file
  
  TFile* fin = new TFile(infile.c_str(),"READ");
  if (fin == NULL) {
    std::cout<<"could not open file : "<<infile<<std::endl;
    return;
  } 
  if ( fin->IsOpen() == false ) {
    std::cout<<"file not open : "<<infile<<std::endl;
    
    return;
  }
  
  
  //************************************************************************
  // Create a root tree
  
  TFile hfile ("outputTree.root", "RECREATE");
  TTree *outputTree_beamline_ave = new TTree ("Beamline_cycle_info_ave", "output tree");
  TTree *outputTree_beamline_maxmin =  new TTree(" Beamline_cycle_info_maxmin", "output tree");
  TTree *outputTree_runtransition = new TTree ("Runtransision_cycle_info", "output tree");
  TTree *outputTree_epics_ave = new TTree ("Epics_cycle_info_ave", "output tree");
  TTree *outputTree_epics_maxmin = new TTree ("Epics_cycle_info_maxmin", "output tree");
  
  
  
  //**************************************************************************
  //TCNxxxxx number that the cycle belongs to
  //  This information is in the "headerTree;1" in the "experimetNumber" branch.
  //  The other run information such as the shifter and the run comments are 
  //  also added here.
  
  TTree* headerTree = (TTree*) fin->Get("headerTree");
  
  
  std::string *expNumber = new std::string(); 
  headerTree->SetBranchAddress("experimentNumber",&expNumber);
  
  std::string *shifter = new std::string(); 
  headerTree->SetBranchAddress("shifter",&shifter);
  
  std::string *comment = new std::string(); 
  headerTree->SetBranchAddress("comment",&comment);
  
  headerTree->GetEntry(0);
  
  cout<<"**********************************************************"<<endl;
  std::cout << "The Experiment Number is:" << *expNumber << std::endl;
  std::cout << "The shifter was: "<< *shifter<<std::endl;
  std::cout << "Run comment: "<< *comment << std::endl;
  cout<<"**********************************************************"<<endl;
  
  
  
  // Create branches. 
  outputTree_runtransition -> Branch ("expNumber" , &expNumber );
  outputTree_runtransition -> Branch ("shifter", &shifter);
  outputTree_runtransition -> Branch ("comment", &comment);
  
  
  //************************************************************************
  // IV1 open and close time.
  // These information must be in RunTransitions_Li-6 tree.
  
  
  TTree* truntime = (TTree*) fin -> Get("RunTransitions_Li-6");
  double cycleStart, valveOpenTime, valveCloseTime, delayTime, openTime;
  std::vector <double> cycleStartTimes;
  std::vector <double> cycleValveOpenTimes;
  std::vector <double> cycleValveCloseTimes;
  std::vector<int> numberEventsPerCycle;
  ULong64_t eventTot;
  int numcycle;
  
  truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
  truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime);// time that valve opened
  truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); //time that valve closed
  truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
  truntime->SetBranchAddress("cycleOpenInterval",&openTime); // valve open time
  
  eventTot = (Double_t)truntime->GetEntries();
  //  cout << "cycle start    velve open time    valve close time" << 
  //    "    delay time    valve open duration "<< endl;
  
  outputTree_runtransition -> Branch ("cycleStart" , &cycleStart );
  outputTree_runtransition -> Branch ("valveOpenTime", &valveOpenTime);
  outputTree_runtransition -> Branch ("valveCloseTime", &valveCloseTime);
  outputTree_runtransition -> Branch ("delayTime", &delayTime);
  outputTree_runtransition -> Branch ("openTime", &openTime);
  outputTree_runtransition -> Branch ("numcycle", &numcycle);
  
  for(ULong64_t j=0;j<eventTot;j++) {
    truntime->GetEvent(j);
    //  std::cout  <<  (int)cycleStart << "        " 
    //	       << (int) valveOpenTime << "        " 
    //	       << (int) valveCloseTime << "               " 
    //	       << (int) delayTime << "        " 
    //	       << (int) openTime << " " 
    //     " sec." << std::endl;
    outputTree_runtransition->Fill();
    cycleStartTimes.push_back(cycleStart);
    cycleValveOpenTimes.push_back(valveOpenTime);
    cycleValveCloseTimes.push_back(valveCloseTime);
    numberEventsPerCycle.push_back(0);
    numcycle=j+1;
  }
  outputTree_runtransition->Fill();
  cout << "Total number of cycles " << numcycle << endl;
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
  std::vector<double> cycleIrradiationTime;
  std::vector<double> cycleB1V_Fraction;
  std::vector<double> cycleTNIM_raw;
  
  
  
  
  Double_t IrradTime, B1V_KSM_RDBEAMON_VAL1, B1V_KSM_PREDCUR, B1_FOIL_ADJCUR, B1V_KSM_PREDCUR_last = 0;
  Double_t B1V_KSM_RDFRCTN_VAL1, B1U_TNIM2_RAW;
  Double_t B1U_TGTTEMP1_RDTEMP, B1U_TGTTEMP2_RDTEMP; //Target Temperature
  Double_t B1U_WTEMP1_RDTEMP, B1U_WTEMP2_RDTEMP;
  Double_t B1U_COL2RIGHT_RDTEMP, B1U_COL2DOWN_RDTEMP, B1U_COL2UP_RDTEMP,B1U_COL2LEFT_RDTEMP;
  int timestamp_beamline;
  //std::vector<double> irradStart;
  // int timestamp_beamline_min=1512512046, timestamp_beamline_max=0;
  
  
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
  Double_t irradiationStartTime;
  
  std::vector<double> b1_max;
  std::vector<double> b1_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) b1_max.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) b1_min.push_back(300);
  
  std::vector<double> prdcur_max;
  std::vector<double> prdcur_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) prdcur_max.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) prdcur_min.push_back(100);
  
  
  std::vector<double> tnim_max;
  std::vector<double> tnim_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) tnim_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) tnim_min.push_back(1000);
  
  std::vector<double> targettemp1_max;
  std::vector<double> targettemp1_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) targettemp1_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) targettemp1_min.push_back(1000);
  
  std::vector<double> targettemp2_max;
  std::vector<double> targettemp2_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) targettemp2_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) targettemp2_min.push_back(1000);
  
  std::vector<double> wtemp1_max;
  std::vector<double> wtemp1_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) wtemp1_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) wtemp1_min.push_back(1000);
  
  std::vector<double> wtemp2_max;
  std::vector<double> wtemp2_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) wtemp2_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) wtemp2_min.push_back(1000);
  
  std::vector<double> col2up_max;
  std::vector<double> col2up_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) col2up_max.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) col2up_min.push_back(100);
  
  std::vector<double> col2right_max;
  std::vector<double> col2right_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) col2right_max.push_back(0);
   for(int i = 0; i < cycleStartTimes.size(); i++) col2right_min.push_back(100);

   std::vector<double> col2left_max;
   std::vector<double> col2left_min;
   for(int i = 0; i < cycleStartTimes.size(); i++) col2left_max.push_back(0);
   for(int i = 0; i < cycleStartTimes.size(); i++) col2left_min.push_back(100);

   std::vector<double> col2down_max;
   std::vector<double> col2down_min;
   for(int i = 0; i < cycleStartTimes.size(); i++) col2down_max.push_back(0);
   for(int i = 0; i < cycleStartTimes.size(); i++) col2down_min.push_back(100);
  
  
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
	 //cout << cycleIrradiationTime << endl;
       }
       B1V_KSM_PREDCUR_last = B1V_KSM_PREDCUR;
     }
   }
   
   
   for(int i = 0; i < cycleIrradiationTime.size(); i++){
     std::cout << "Irradiation time for cycle " << i << " was " << 
       cycleIrradiationTime[i] << " sec.  B1 current =  "
	       << cycleB1_BeamCurrent[i] << " uA,  B1U current = " << 
       cycleB1U_BeamCurrent[i]<< " uA." <<  std::endl;
   }
   
   
   
   cout<<"**********************************************************"<<endl;
   
   outputTree_beamline_ave -> Branch ("irradiationStartTime", &irradiationStartTime[i]);
   outputTree_beamline_ave -> Branch ("B1_ave", &b1_ave[i]);
   outputTree_beamline_ave -> Branch ("PRDCUR_ave", &prdcur_ave[i]);
   outputTree_beamline_ave -> Branch ("TNIM_ave", &tnim_ave[i]);
   outputTree_beamline_ave -> Branch ("TargetTemp1_ave", &targettemp1_ave[i]);
   outputTree_beamline_ave -> Branch ("TargetTemp2_ave", &targettemp2_ave[i]);
   outputTree_beamline_ave -> Branch ("WindowTemp1_ave", &wtemp1_ave[i]);
   outputTree_beamline_ave -> Branch ("WindowTemp2_ave", &wtemp2_ave[i]);
   outputTree_beamline_ave -> Branch ("ColUp_ave", &col2up_ave[i]);
   outputTree_beamline_ave -> Branch ("ColDown_ave", &col2down_ave[i]);
   outputTree_beamline_ave -> Branch ("ColRight_ave", &col2right_ave[i]);
   outputTree_beamline_ave -> Branch ("ColLeft_ave", &col2left_ave[i]);
   
   
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
	   //cout << "For cycle ("<< oldi_3 << ")" << endl;
	   //cout <<"The irradiation start time is "<< irradiationStartTime[i]<< endl;
	   //cout << "The B1 average current is  " << 
	   //b1_ave[i] << " uA." <<endl;
	   //cout << "The average predicted current is "<<
	   //  prdcur_ave[i] <<" uA." << endl;
	   // cout << "The average TNIM current is "<<
	   //   tnim_ave[i] << endl;
	   //  cout << "The average target temperature (1) is " << 
	   //   targettemp1_ave[i] <<  " C." << endl;
	   // cout << "The average target temperature (2) is " << 
	   //  targettemp2_ave[i] <<  " C." << endl;
	   // cout << "The average window temperature (1) is " << 
	   //  wtemp1_ave[i] <<  " C." << endl;
	   //  cout << "The average window temperature (2) is " << 
	   //   wtemp2_ave[i] <<  " C." << endl;
	   //  cout << "The average collimator temperature (up) is " << 
	   //    col2up_ave[i] <<  " C." << endl;
	   //  cout << "The average collimator temperature (down) is " << 
	   //   col2down_ave[i] <<  " C." << endl;
	   //    cout << "The average collimator temperature (right) is " << 
	   //  col2right_ave[i] <<  " C." << endl;
	   //cout << "The average collimator temperature (left) is " << 
	   //  col2left_ave[i] <<  " C." << endl;
	   //// counter counts how many temperature readings are withing this cycle
	   //// from the start of the irradiation to the valve open.
	   outputTree_beamline_ave -> Fill();
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
	   //cout << ".................................."<< endl;
	   /*  cout << "\n For cycle ("<< oldi_3 << ")" << endl; 
	       cout<<  "The irradiation time started at "<<
	       irradiationStartTime[i]<< "." << endl;
	       cout << "The B1 average current is "<<b1_ave[i]/(counter_3-1) << "uA." << endl;
	       cout <<"The average predicted current is " << 
	       prdcur_ave[i]/(counter_3-1) << " uA." << endl; 
	       cout << "The average TNIM current is "<<
	       tnim_ave[i]/(counter_3-1) << endl;
	       cout << "The average target temperature (1) is " << 
	       targettemp1_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average target temperature (2) is " << 
	       targettemp2_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average window temperature (1) is " << 
	       wtemp1_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average window temperature (2) is " << 
	       wtemp2_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average collimator temperature (up) is " << 
	       col2up_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average collimator temperature (down) is " << 
	       col2down_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average collimator temperature (right) is " << 
	       col2right_ave[i]/(counter_3-1) <<  " C." << endl;
	       cout << "The average collimator temperature (left) is " << 
	       col2left_ave[i]/(counter_3-1) <<  " C." << endl;*/
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
	   outputTree_beamline_ave -> Fill();
	   final_counter++;
	 } 
       } 
     } 
   }
   
   
   final_counter=1;
   
   
   outputTree_beamline_maxmin -> Branch ("B1_max", &b1_max);
   outputTree_beamline_maxmin -> Branch ("B1_min", &b1_min);
   outputTree_beamline_maxmin -> Branch ("PRDCUR_max", &prdcur_max);
   outputTree_beamline_maxmin -> Branch ("PRDCUR_min", &prdcur_min);
   outputTree_beamline_maxmin -> Branch ("TNIM_max", &tnim_max);
   outputTree_beamline_maxmin -> Branch ("TNIM_min", &tnim_min);
   outputTree_beamline_maxmin -> Branch ("TargetTemp1_max", &targettemp1_max);
   outputTree_beamline_maxmin -> Branch ("TargetTemp1_min", &targettemp1_min);
   outputTree_beamline_maxmin -> Branch ("TargetTemp2_max", &targettemp2_max);
   outputTree_beamline_maxmin -> Branch ("TargetTemp2_min", &targettemp2_min);
   outputTree_beamline_maxmin -> Branch ("WindowTemp1_max", &wtemp1_max);
   outputTree_beamline_maxmin -> Branch ("WindowTemp1_min", &wtemp1_min);
   outputTree_beamline_maxmin -> Branch ("WindowTemp2_max", &wtemp2_max);
   outputTree_beamline_maxmin -> Branch ("WindowTemp2_min", &wtemp2_min);
   outputTree_beamline_maxmin -> Branch ("ColUp_max", &col2up_max);
   outputTree_beamline_maxmin -> Branch ("ColUp_min", &col2up_min);
   outputTree_beamline_maxmin -> Branch ("ColDown_max", &col2down_max);
   outputTree_beamline_maxmin -> Branch ("ColDown_min", &col2down_min);
   outputTree_beamline_maxmin -> Branch ("ColRight_max", &col2right_max);
   outputTree_beamline_maxmin -> Branch ("ColRight_min", &col2right_min);
   outputTree_beamline_maxmin -> Branch ("ColLeft_max", &col2left_max);
   outputTree_beamline_maxmin -> Branch ("ColLeft_min", &col2left_min);
   
  cout<<"**********************************************************"<<endl;  
  
  cout << "  MAXIMUM B1 CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<b1_max.size() ; i++){
    std::cout << "Maximum B1 current reading during irradiation for cycle (" << i << ") was "
 	      << b1_max[i] << " uA. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MINIMUM B1 CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<b1_min.size() ; i++){
    std::cout << "Minimum B1 current reading during irradiation for cycle (" << i << ") was "
 	      << b1_min[i] << " uA. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MAXIMUM PREDICTED CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<prdcur_max.size() ; i++){
    std::cout << "Maximum B1 current reading during irradiation for cycle (" << i << ") was "
 	      << prdcur_max[i] << " uA. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MINIMUM PREDICTED CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<b1_min.size() ; i++){
    std::cout << "Minimum predicted current reading during irradiation for cycle (" << i << ") was "
 	      << prdcur_min[i] << " uA. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MAXIMUM TNIM CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<prdcur_max.size() ; i++){
    std::cout << "Maximum B1 current reading during irradiation for cycle (" << i << ") was "
 	      << tnim_max[i] << " uA. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MINIMUM TNIM PREDICTED CURRENT DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<b1_min.size() ; i++){
    std::cout << "Minimum predicted current reading during irradiation for cycle (" << i << ") was "
 	      << tnim_min[i] << " uA. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM TARGET TEMPERATURE (1) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < targettemp1_max.size(); i++){
    std::cout << "Maximum target temparature (1) reading during irradiation for cycle (" << i << ") was "
 	      << targettemp1_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM TARGET TEMPERATURE (1) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < targettemp1_min.size(); i++){
    std::cout << "Minimum target temperature (1) reading during irradiation for cycle (" << i << ") was "
 	      << targettemp1_min[i] << " C. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM TARGET TEMPERATURE (2) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < targettemp2_max.size(); i++){
    std::cout << "Maximum target temparature (2) reading during irradiation for cycle (" << i << ") was "
 	      << targettemp2_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM TARGET TEMPERATURE (2) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < targettemp2_min.size(); i++){
    std::cout << "Minimum target temperature (2) reading during irradiation for cycle (" << i << ") was "
 	      << targettemp2_min[i] << " C. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM WINDOW TEMPERATURE (1) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < wtemp1_max.size(); i++){
    std::cout << "Maximum window temparature (1) reading during irradiation for cycle (" << i << ") was "
 	      << wtemp1_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM WINDOW TEMPERATURE (1) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < wtemp1_min.size(); i++){
    std::cout << "Minimum window temperature (1) reading during irradiation for cycle (" << i << ") was "
 	      << wtemp1_min[i] << " C. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM WINDOW TEMPERATURE (2) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < wtemp2_max.size(); i++){
    std::cout << "Maximum window temparature (2) reading during irradiation for cycle (" << i << ") was "
 	      << wtemp2_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM WINDOW TEMPERATURE (2) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < wtemp2_min.size(); i++){
    std::cout << "Minimum window temperature (2) reading during irradiation for cycle (" << i << ") was "
 	      << wtemp2_min[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM COLLIMATOR TEMPERATURE (UP) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < col2up_max.size(); i++){
    std::cout << "Maximum collimator temparature (up) reading during irradiation for cycle (" << i << ") was "
 	      << col2up_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM COLLIMATOR TEMPERATURE (UP) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < col2up_min.size(); i++){
    std::cout << "Minimum collimator temperature (up) reading during irradiation for cycle (" << i << ") was "
 	      << col2up_min[i] << " C. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM COLLIMATOR TEMPERATURE (DOWN) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < col2down_max.size(); i++){
    std::cout << "Maximum collimator temparature (down) reading during irradiation for cycle (" << i << ") was "
 	      << col2down_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM COLLIMATOR TEMPERATURE (DOWN) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < col2down_min.size(); i++){
    std::cout << "Minimum collimator temperature (down) reading during irradiation for cycle (" << i << ") was "
 	      << col2down_min[i] << " C. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM COLLIMATOR TEMPERATURE (RIGHT) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < col2right_max.size(); i++){
    std::cout << "Maximum collimator temparature (right) reading during irradiation for cycle (" << i << ") was "
 	      << col2right_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM COLLIMATOR TEMPERATURE (RIGHT) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < col2right_min.size(); i++){
    std::cout << "Minimum collimator temperature (right) reading during irradiation for cycle (" << i << ") was "
 	      << col2right_min[i] << " C. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << " MAXIMUM COLLIMATOR TEMPERATURE (LEFT) DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < col2left_max.size(); i++){
    std::cout << "Maximum collimator temparature (left) reading during irradiation for cycle (" << i << ") was "
 	      << col2left_max[i] << " C. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM COLLIMATOR TEMPERATURE (LEFT) DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < col2left_min.size(); i++){
    std::cout << "Minimum collimator temperature (left) reading during irradiation for cycle (" << i << ") was "
 	      << col2left_min[i] << " C. " << std::endl;
  }
  
  
  outputTree_beamline_maxmin -> Fill();
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
  
  
  std::vector<double> maxts12_temperature_irrad;
  std::vector<double> mints12_temperature_irrad;
  for(int i = 0; i < cycleStartTimes.size(); i++) maxts12_temperature_irrad.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) mints12_temperature_irrad.push_back(100);
  
  std::vector<double> maxts12_temperature_valveOpen;
  std::vector<double> mints12_temperature_valveOpen;
  for(int i = 0; i < cycleStartTimes.size(); i++) maxts12_temperature_valveOpen.push_back(0);
  for(int i = 0; i < cycleStartTimes.size(); i++) mints12_temperature_valveOpen.push_back(100);
  
  std::vector<double> fm1_max;
  std::vector<double> fm1_min;
  for(int i = 0; i < cycleStartTimes.size(); i++) fm1_max.push_back(0.);
  for(int i = 0; i < cycleStartTimes.size(); i++) fm1_min.push_back(100);
  
  
  
  
  sourceTree->SetBranchAddress("UCN_ISO_TS12_RDTEMP",&UCN_ISO_TS12_RDTEMP);
  sourceTree->SetBranchAddress("UCN_HE3_FM1_RDFLOW",&UCN_HE3_FM1_RDFLOW);
  sourceTree->SetBranchAddress("timestamp",&timestamp);
  int counter=1, counter_2=1;
  int oldi=0, oldi_2=0 ;
  // int final_counter=1;
  
 


  outputTree_epics_ave -> Branch("TS12_AVE_Irrad", &avets12_temperature_irrad);
  outputTree_epics_ave -> Branch("TS12_AVE_valveOpen", &avets12_temperature_valveOpen);
  outputTree_epics_ave -> Branch("FM1_AVE", &fm1_ave);



  eventTot = (Double_t)sourceTree->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    sourceTree->GetEvent(j);
    sourceReadTimes.push_back(timestamp);
    for(int i = 0; i < cycleStartTimes.size(); i++){
      //checks within which cycle we are.
      //cout << B1_FOIL_ADJCUR << " " << i << endl;
      irradiationStartTime[i] = cycleStartTimes[i] - cycleIrradiationTime[i];
      //cout <<"irradiation start time: " << irradiationStartTime[i]<< endl;
      //---------------------
      // IRRADIATION CYCLE 
      // ----------------------
      if(timestamp > irradiationStartTime && timestamp < cycleValveOpenTimes[i]){
 	//	cout << "cycle " << i << endl;
 	if (oldi!=i ){
 	  // This loop means that we are within the next cycle. so we can get the 
 	  // average temperatures for the previous cycle.
 	  cout << ".................................."<< endl;
 	  avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter-1);
 	  fm1_ave[i]=fm1_ave[i]/(counter-1);
	  //	  cout << "For cycle ("<< oldi << ")" << endl;
 	  //	  cout <<  "TS12 average during irradiation is "<< avets12_temperature_irrad[i]<< 
	  //	    " K. " << endl;
 	  //	  cout <<"The irradiation start time is "<< irradiationStartTime[i]<< endl;
 	  //	  cout << "The average He3 gas flow is "<<
 	  //	    fm1_ave[i]<< " slm." << endl;
 	  // counter counts how many temperature readings are withing this cycle
	  //  from the start of the irradiation to the valve open.
 	  outputTree_epics_ave->Fill();
 	  counter=1;
 	  avets12_temperature_irrad[i]=0;
 	  fm1_ave[i]=0;
 	}
 	//	cout << i <<" " << counter << " " << oldi <<endl;
 	avets12_temperature_irrad[i]+=UCN_ISO_TS12_RDTEMP;
 	fm1_ave[i]+=UCN_HE3_FM1_RDFLOW;
 	counter++;
 	oldi=i;
 	//	cout << avets12_temperature_irrad[i]<< " " << UCN_ISO_TS12_RDTEMP << endl;
	
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
 	//	cout << "now valve is open and i is"<< i << " and counter is " << counter_2 <<  endl;	
	if (oldi_2!=i ){
	  avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_2-1);
	  //	  cout << "For cycle ("<< oldi_2 <<
	  //	    ") TS12 average during valve open is "<< avets12_temperature_valveOpen[i]<< 
	  //	    " K. "<< endl;
	  outputTree_epics_ave->Fill();
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
	  // cout << ".................................."<< endl;
	  ////cout << counter << " " << counter_2 << endl;
	  ////	  cout << "now what " << endl;
	  ///  cout << "For cycle ("<< oldi << ")" << endl;
	  //  cout << "TS12 average during irradiation is "<< 
	  //    avets12_temperature_irrad[i]/(counter-1)<< " K." << endl;  
	  //	  cout<<  "The irradiation time started at "<<
	  //	    irradiationStartTime[i]<< "." << endl;
	  //  cout <<"The average He3 gas flow is "<<fm1_ave[i]/(counter-1)<< " slm." << endl;
	  //  cout << "For cycle ("<< oldi_2 << ") TS12 average during valve open is "<< 
	  //	    avets12_temperature_valveOpen[i]/(counter_2-1)<< " K." <<
	  //    endl;
	  avets12_temperature_irrad[i]=avets12_temperature_irrad[i]/(counter-1);
	  fm1_ave[i]=fm1_ave[i]/(counter-1);
	  avets12_temperature_valveOpen[i]=avets12_temperature_valveOpen[i]/(counter_2-1);
	  outputTree_epics_ave->Fill();
	  final_counter++;
	} 
      }
    }
  }
  
  
  outputTree_epics_maxmin -> Branch("TS12_MAX_Irrad", &maxts12_temperature_irrad);
  outputTree_epics_maxmin -> Branch("TS12_MIN_Irrad", &mints12_temperature_irrad);
  outputTree_epics_maxmin -> Branch("TS12_MAX_valveOpen", &maxts12_temperature_valveOpen);
  outputTree_epics_maxmin -> Branch("TS12_MIN_valveOpen", &mints12_temperature_valveOpen);
  outputTree_epics_maxmin -> Branch("FM1_MAX", &fm1_max); 
  outputTree_epics_maxmin -> Branch("FM1_MIN", &fm1_min);
  
cout<<"**********************************************************"<<endl;  

cout.setf(ios::fixed);
  cout << " MAXIMUM TS12 TEMPERATURE DURING IRRADIATION:" << endl;
  cout << ""<< endl;
  for(int  i = 0; i < maxts12_temperature_irrad.size(); i++){
    std::cout << "Maximum TS12 reading during irradiation for cycle (" << i << ") was "
 	      << maxts12_temperature_irrad[i] << " K. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM TS12 TEMPERATURE DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < mints12_temperature_irrad.size(); i++){
    std::cout << "Minimum TS12 reading during irradiation for cycle (" << i << ") was "
 	      << mints12_temperature_irrad[i] << " K. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl;   
  
  cout << " MAXIMUM TS12 TEMPERATURE DURING VALVE OPEN:" << endl;
  cout << "" << endl;
  for(int  i = 0; i < maxts12_temperature_valveOpen.size(); i++){
    std::cout << "Maximum TS12 reading when valve was open for cycle (" << i << ") was "
 	      << maxts12_temperature_valveOpen[i] << " K. " << std::endl;
  }
  cout<<"**********************************************************"<<endl; 
  
  cout << " MINIMUM TS12 TEMPERATURE DURING VALVE OPEN:" << endl; 
  cout << "" << endl;
  for(int  i = 0; i < mints12_temperature_valveOpen.size(); i++){
    std::cout << "Minimum TS12 reading when valve was open for cycle (" << i << ") was "
 	      << mints12_temperature_valveOpen[i] << " K. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MAXIMUM HE3 FLOW READING DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<fm1_max.size() ; i++){
    std::cout << "Maximum He3 flow reading during irradiation for cycle (" << i << ") was "
 	      << fm1_max[i] << " slm. " << std::endl;
  }
  
  cout<<"**********************************************************"<<endl; 
  
  cout << "  MINIMUM HE3 FLOW READING DURING IRRADIATION:" << endl;
  cout << "" << endl;
  for (int i=0 ; i<fm1_min.size() ; i++){
    std::cout << "Minimum He3 flow reading during irradiation for cycle (" << i << ") was "
 	      << fm1_min[i] << " slm. " << std::endl;
  }
  
  
  cout<<"**********************************************************"<<endl; 
  outputTree_epics_maxmin->Fill();

  //***************************************************************************************
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
  
  
  
  
  //***************************************************************
  // Writing the tree
  
  // outputTree ->Fill();
  //outputTree -> Print();
  hfile ->Write();
  hfile-> Close();
  

}

