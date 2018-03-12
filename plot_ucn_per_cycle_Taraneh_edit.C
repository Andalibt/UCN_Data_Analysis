//             UCN 2017 analysis
//**********************************************************
#include <time.h>
void plot_ucn_per_cycle_Taraneh_edit(std::string infile){
  
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



  //**************************************************************************
  //  TCNxxxxx number that the cycle belongs to
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
  
  //**************************************************************************
  //  Irradiation start and stop time
  //  Irradiation time
  //  This information is in the  "BeamlineEpicsTree;1" and in the
  //  "B1V_KSM_RDBEAMON_VAL1" and "B1V_KSM_RDBEAMOFF_VAL1" branch.

  
  TTree* BeamlineEpicsTree = (TTree*) fin-> Get ("BeamlineEpicsTree");
  std::vector<double> beamlineReadTimes;
  Double_t IrradTime,
  TFile* fin = new TFile(infile.c_str(),"READ");
  if (fin == NULL) {
    std::cout<<"could not open file : "<<infile<<std::endl;
    return;
  } 
  if ( fin->IsOpen() == false ) {
    std::cout<<"file not open : "<<infile<<std::endl;
    
    return;
  }



  //**************************************************************************
  //  TCNxxxxx number that the cycle belongs to
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
  
  //**************************************************************************
  //  Irradiation start and stop time
  //  Irradiation time
  //  This information is in the  "BeamlineEpicsTree;1" and in the
  //  "B1V_KSM_RDBEAMON_VAL1" and "B1V_KSM_RDBEAMOFF_VAL1" branch.

  
  TTree* BeamlineEpicsTree = (TTree*) fin-> Get ("BeamlineEpicsTree");
  std::vector<double> beamlineReadTimes;
  Double_t IrradTime,B1V_KSM_RDBEAMON_VAL1;
  int timestamp_beamline;
  int timestamp_beamline_min=1512512046, timestamp_beamline_max=0;
  struct tm timestamp_min, timestamp_max;
  char buf_min[80], buf_max[80];

  BeamlineEpicsTree -> SetBranchAddress("timestamp",&timestamp_beamline);
  BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_RDBEAMON_VAL1",&B1V_KSM_RDBEAMON_VAL1);
  
  beamlineEvent = (Double_t) BeamlineEpicsTree-> GetEntries();
  for(ULong64_t j=0;j<beamlineEvent ;j++) {
    BeamlineEpicsTree->GetEvent(j);
    beamlineReadTimes.push_back(timestamp_beamline);
    //if (timestamp_beamline >= timestamp_beamline_max)
    //  timestamp_beamline_max=timestamp_beamline; 
    //  if (timestamp_beamline <= timestamp_beamline_min)
    //  timestamp_beamline_min=timestamp_beamline; 
    // IrradTime = timestamp_beamline_max - timestamp_beamline_min;
  }
  //timestamp_min=*localtime(&timestamp_beamline_min);
  // timestamp_max=*localtime(&timestamp_beamline_max);
  // strftime(buf_min, sizeof(buf_min), "%a %b %d %H:%M:%S %Z", &timestamp_min);
  // strftime(buf_max, sizeof(buf_max), "%a %b %d %H:%M:%S %Z", &timestamp_max);
  // std::cout << "The radiation time started at " << buf_min << std::endl;
  // std::cout << "The irradiation start time in unix time is: "<< timestamp_beamline_min << std::endl;
  // std::cout << "The radiation time stopped at "<< buf_max << std::endl;
  // std::cout << "The irradiation time in minutes is: "<< IrradTime/60 << std::endl;
  double irradiationTime = B1V_KSM_RDBEAMON_VAL1 *0.0008881; // in seconds.
  cout << "The irradiation time in seconds is " << setprecision(7)<< irradiationTime << endl;
  //std::cout << "Finished beamlineEpics loop " << std::endl;

  //cout<<"**********************************************************"<<endl;

  
  // Everytime I run the code I get a different date!!! Why is that?
  
  //************************************************************************
  // IV1 open and close time.
  // These information must be in RunTransitions_Li-6 tree.
  
  
  TTree* truntime = (TTree*) fin -> Get("RunTransitions_Li-6");
  double cycleStart, valveOpenTime, valveCloseTime, delayTime, openTime;
  std::vector <double> cycleStartTimes;
  std::vector<int> numberEventsPerCycle;
  ULong64_t eventTot;
  
  truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
  truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime); // time that valve opened
  truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); // time that valve closed
  truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
  truntime->SetBranchAddress("cycleOpenInterval",&openTime); // valve open time
  
  eventTot = (Double_t)truntime->GetEntries();
  
  for(ULong64_t j=0;j<eventTot;j++) {
    truntime->GetEvent(j);
    cycleStartTimes.push_back(cycleStart);
    numberEventsPerCycle.push_back(0);
  }
  
  
  struct tm cycleStart_dt, valveOpen_dt, valveClose_dt;
  char cycleStart_buf[80], valveOpen_buf[80], valveClose_buf[80];
  
  //cycleStart_dt = *localtime(&cycleStart);
  //valveOpen_dt = *localtime(&valveOpenTime);
  //valveClose_dt = *localtime(&valveCloseTime);
  //strftime(cycleStart_buf, sizeof(cycleStart_buf), "%a %b %d %H:%M:%S %Z", &cycleStart_dt);
  //strftime(valveOpen_buf, sizeof(valveOpen_buf), "%a %b %d %H:%M:%S %Z", &valveOpen_dt);
  //strftime(valveClose_buf, sizeof(valveClose_buf), "%a %b %d %H:%M:%S %Z", &valveClose_dt); 
  
  //std::cout << "The last cycle started (irradiation ended) at  " << cycleStart_buf << std::endl;
  //std::cout << "The delay time for the last cycle was " << delayTime << " sec." << std::endl;
  //std::cout << "The valve opened at: "<< valveOpen_buf << std::endl;
  //std::cout << "The valve closed at: "<< valveClose_buf << std::endl;
  //std::cout << "The valve open time for the last cycle was " << openTime << " sec." << std::endl;
  cout.setf(ios::fixed);
  std::cout << "The last cycle started (irradiation ended) at  " << setprecision(0) <<cycleStart << std::endl;
  std::cout << "The delay time for the last cycle was " << delayTime << " sec." << std::endl;
  std::cout << "The valve opened at: "<< valveOpenTime << std::endl;
  std::cout << "The valve closed at: "<< valveCloseTime << std::endl;
  std::cout << "The valve open time for the last cycle was " << openTime << " sec." << std::endl;
 double irradiationEndTime = valveOpenTime - delayTime;
 double irradiationStartTime = irradiationEndTime - irradiationTime;

 std::cout << "The irradition start time is: " << irradiationStartTime << std::endl;
 cout << "The irradiation end time is: " << irradiationEndTime << endl;


  cout<<"**********************************************************"<<endl;
  
  // I cannot convert the unix timestamp to actual date and time here. It breaks root every time.
  // The interesting point is that the same method worked for the previous section where I converted the
  // radiation start and stop time. But for some reason it does not work here.
  
  //***************************************************************************
  //Average, max, min isopure temperature during irradiation (plus IV1 delay): 
  //average over irradiation time of TS12
  //The temperature must be in the sourceEpicsTree
  
  sourceTree = (TTree*) fin->Get("SourceEpicsTree");
  double UCN_ISO_TS12_RDTEMP;
  int timestamp;
  std::vector<double> sourceReadTimes;
  std::vector<double> ts12_temperature;
  std::vector<double> temperaturePerCycle;
  double avetemp12,maxtemp12=0,mintemp12=100;
  
  sourceTree->SetBranchAddress("UCN_ISO_TS12_RDTEMP",&UCN_ISO_TS12_RDTEMP);
  sourceTree->SetBranchAddress("timestamp",&timestamp);
  
  
  eventTot = (Double_t)sourceTree->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    sourceTree->GetEvent(j);
    sourceReadTimes.push_back(timestamp);
    ts12_temperature.push_back(UCN_ISO_TS12_RDTEMP);
  }
cout.setf(ios::fixed);
  
for(ULong64_t j=0;j<eventTot;j++) {
    // Find the temperature for this cycle.
    double temperature = 0;
    for( int i = 0; i < sourceReadTimes.size()-1; i++){
      if(cycleStart >= sourceReadTimes[i] && cycleStart < sourceReadTimes[i+1]){
        temperature[i] = ts12_temperature[i];
	break;
      }
      //cout << "Temperature of the cycle " << i << "is " <<setprecision(3) << temperature[i] << endl;
      //avetemp12+=temperature[i];
      //if (maxtemp12 <= temperature[i]){
      //maxtemp12=temperature[i];}
      //  if (mintemp12 >=ts12_temperature[i]){
      //	mintemp12=ts12_temperature[i];
      //   }
    }
    avetemp12=avetemp12/(sourceReadTimes.size());
    temperaturePerCycle.push_back(temperature);

 }
cout.setf(ios::fixed);

 std::cout << "The average isopure temperature at this cycle was " << setprecision(3)<<avetemp12 << " K"<<std::endl;
 std::cout << "The maximum isopure temperature at this cycle was " << maxtemp12 << " K"<<std::endl
   //std::cout << "The minimum isopure temperature at this cycle was " << mintemp12 << " K"<<std::endl
;cout<<"**********************************************************"<<endl;
 //It does not make sense. Something is not right here.


 //*************************************************************************************
 // Average, max and min isopure temperature during IV1 open time










 //***************************************************************************************





}
