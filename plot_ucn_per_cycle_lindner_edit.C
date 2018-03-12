//             UCN 2017 analysis
//**********************************************************

void plot_ucn_per_cycle_lindner_edit(std::string infile){
  
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
  

// The irrad time does not make sense. It seems it is because the beam off value has decimal places 
// and the beam on does not. I am not sure how to fix it.
  // TL: I think you were looking at the wrong variable... see above...

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

truntime->SetBranchAddress("cycleStartTime",&cycleStart); 
truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime); // time that valve opened
truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); // time that valve closed
truntime->SetBranchAddress("cycleDelayTime",&delayTime);   
truntime->SetBranchAddress("cycleOpenInterval",&openTime); // valve open time

eventTot = (Double_t)truntime->GetEntries();

 for(ULong64_t j=0;j<eventTot;j++) {
    truntime->GetEvent(j);
    std::cout << "times: " <<  (int)cycleStart << " " 
	      << (int) valveOpenTime << " " 
	      << (int) valveCloseTime << " " 
	      << (int) delayTime << " " 
	      << (int) openTime << " " 
      
      " sec." << std::endl;
    cycleStartTimes.push_back(cycleStart);
    cycleValveOpenTimes.push_back(valveOpenTime);
    cycleValveCloseTimes.push_back(valveCloseTime);
    numberEventsPerCycle.push_back(0);
}
 
 
 std::cout << "The last cycle started (irradiation ended) at  " << (int)cycleStart << " sec." << std::endl;
 std::cout << "The delay time for the last cycle was " << delayTime << " sec." << std::endl;
 std::cout << "The valve opened at: "<< valveOpenTime<< " for last cycle " << std::endl;
 std::cout << "The valve closed at: "<< valveCloseTime<< " for last cycle " << std::endl;
 std::cout << "The valve open time for the last cycle was " << openTime << " sec." << std::endl;
 cout<<"**********************************************************"<<endl;
 
 //  the valve open and close time does not make sense. Why??
 // TL : valve open and close time are the times in 'unix time' format; ie, time in seconds since 1970 (or somewhere around there)...
 // so I think the numbers do make sense.  In fact all the timestamps in the root tree are in unix time format.


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
  Double_t IrradTime, B1V_KSM_RDBEAMON_VAL1, B1V_KSM_PREDCUR, B1_FOIL_ADJCUR, B1V_KSM_PREDCUR_last = 0;
  int timestamp_beamline;
  int timestamp_beamline_min=1512512046, timestamp_beamline_max=0;
  
  
  BeamlineEpicsTree -> SetBranchAddress("timestamp",&timestamp_beamline);
  BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_RDBEAMON_VAL1",&B1V_KSM_RDBEAMON_VAL1);
  BeamlineEpicsTree -> SetBranchAddress("B1V_KSM_PREDCUR",&B1V_KSM_PREDCUR);
  BeamlineEpicsTree -> SetBranchAddress("B1_FOIL_ADJCUR",&B1_FOIL_ADJCUR);
  
  Double_t beamlineEvent = (Double_t) BeamlineEpicsTree-> GetEntries();
  for(ULong64_t j=0;j<beamlineEvent ;j++) {



    BeamlineEpicsTree->GetEvent(j);

    // 
    for(int i = 0; i < cycleStartTimes.size(); i++){
      if(beamlineFoundEntry[i] == 1) continue;

      if(timestamp_beamline > cycleStartTimes[i]){
	cycleIrradiationTime.push_back(B1V_KSM_RDBEAMON_VAL1 *0.0008881);
	cycleB1U_BeamCurrent.push_back(B1V_KSM_PREDCUR_last);
	cycleB1_BeamCurrent.push_back(B1_FOIL_ADJCUR);	
	beamlineFoundEntry[i] = 1;
      }
    }

    beamlineReadTimes.push_back(timestamp_beamline);
    if (timestamp_beamline >= timestamp_beamline_max)
      timestamp_beamline_max=timestamp_beamline; 
    if (timestamp_beamline <= timestamp_beamline_min)
      timestamp_beamline_min=timestamp_beamline; 
    IrradTime = timestamp_beamline_max - timestamp_beamline_min;

    B1V_KSM_PREDCUR_last = B1V_KSM_PREDCUR;
  }
  
  for(int i = 0; i < cycleIrradiationTime.size(); i++){
    std::cout << "Irradiation time for cycle " << i << " was " << cycleIrradiationTime[i] << " sec.  B1 current =  "
	      << cycleB1_BeamCurrent[i] << "uA.  B1U current = " << cycleB1U_BeamCurrent[i]<< "uA " << std::endl;
  }

  //  std::cout << "Irradiation time in minutes is: " << irradiationTime/60.0 << std::endl;
  //std::cout << "Finished beamlineEpics loop " << std::endl;

  cout<<"**********************************************************"<<endl;



 
 //***************************************************************************
 //Average, max, min isopure temperature during irradiation (plus IV1 delay): 
 //average over irradiation time of TS12
 //The temperature must be in the sourceEpicsTree

TTree* sourceTree = (TTree*) fin->Get("SourceEpicsTree");
 double UCN_ISO_TS12_RDTEMP;
 int timestamp;
std::vector<double> sourceReadTimes;
std::vector<double> maxts12_temperature;
 for(int i = 0; i < cycleStartTimes.size(); i++) maxts12_temperature.push_back(0);
std::vector<double> temperaturePerCycle;

 double avetemp12=0,maxtemp12=0,mintemp12=100;
 double temp12_readings = 0;
 
 sourceTree->SetBranchAddress("UCN_ISO_TS12_RDTEMP",&UCN_ISO_TS12_RDTEMP);
 sourceTree->SetBranchAddress("timestamp",&timestamp);


 eventTot = (Double_t)sourceTree->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    sourceTree->GetEvent(j);
    sourceReadTimes.push_back(timestamp);
    //    ts12_temperature.push_back(UCN_ISO_TS12_RDTEMP);

    // TL check for timestamps between the start of irradiation and the valve opentime (for last cycle)
    for(int i = 0; i < cycleStartTimes.size(); i++){
      double irradiationStartTime = cycleStartTimes[i] - cycleIrradiationTime[i];
      if(timestamp > irradiationStartTime && timestamp < cycleValveOpenTimes[i]){
	if(UCN_ISO_TS12_RDTEMP > maxts12_temperature[i]){
	  maxts12_temperature[i] = UCN_ISO_TS12_RDTEMP;
	}
      }
    }

  }

  for(int  i = 0; i < maxts12_temperature.size(); i++){

    std::cout << "Maximum TS12 reading during last cycle ("<< i << ") was "
	      << maxts12_temperature[i] << "K. " << std::endl;
  }

    

  /*
for(ULong64_t j=0;j<eventTot;j++) {
    // Find the temperature for this cycle.
    double temperature = 0;
    for( int i = 0; i < sourceReadTimes.size()-1; i++){
      if(cycleStart >= sourceReadTimes[i] && cycleStart < sourceReadTimes[i+1]){
        temperature = ts12_temperature[i];
	break;
      }
      avetemp12+=ts12_temperature[i];
      if (maxtemp12 <= ts12_temperature[i]){
	maxtemp12=ts12_temperature[i];}
      //  if (mintemp12 >=ts12_temperature[i]){
      //	mintemp12=ts12_temperature[i];
      //   }
    }
    avetemp12=avetemp12/(sourceReadTimes.size());
    temperaturePerCycle.push_back(temperature);

 }


 std::cout << "The average isopure temperature at this cycle was " << avetemp12 << " K"<<std::endl;
 std::cout << "The maximum isopure temperature at this cycle was " << maxtemp12 << " K"<<std::endl
   //std::cout << "The minimum isopure temperature at this cycle was " << mintemp12 << " K"<<std::endl
;cout<<"**********************************************************"<<endl;
 //It does not make sense. Something is not right here.
 */

 //*************************************************************************************
 // Average, max and min isopure temperature during IV1 open time










 //***************************************************************************************





}
