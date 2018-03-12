// Macro for finding the number of UCN per cycle.



void plot_ucn_per_cycle(std::string infile){
  
  
  
  ULong64_t eventTot;
  double cycleStart, valveOpenTime, valveCloseTime, delayTime, openTime;

  TFile* fin = new TFile(infile.c_str(),"READ");
  if (fin == NULL) {
    std::cout<<"could not open file : "<<infile<<std::endl;
    return;
  } 
  if ( fin->IsOpen() == false ) {
    std::cout<<"file not open : "<<infile<<std::endl;
    
    return;
  }

  //fin->ls();
  
  
  TTree* uin = (TTree*) fin->Get("UCNHits_Li-6");
  TTree* headerTree = (TTree*) fin->Get("headerTree");
  TTree* truntime = (TTree*) fin->Get("RunTransitions_Li-6");
  TTree* sourceTree = (TTree*) fin->Get("SourceEpicsTree");
  uin->Print();  
  truntime->Print();
  headerTree->Print();

  
  // Dump the header information
  std::string *comment = new std::string(); 
  headerTree->SetBranchAddress("comment",&comment);
  
  std::string *shifter = new std::string(); 
  headerTree->SetBranchAddress("shifter",&shifter);

  std::string *expNumber = new std::string(); 
  headerTree->SetBranchAddress("experimentNumber",&expNumber);
  
  
  headerTree->GetEntry(0);
  
  std::cout << "Run comment: " << *comment << std::endl;
  std::cout << "Shifter: " << *shifter << std::endl;
  std::cout << "ExpNumber: " << *expNumber << std::endl;
  std::cout <<"Done... " << std::endl;
  
  // Loop over the UCN source EPICS reads, saving the temperature
  std::vector<double> sourceReadTimes;
  std::vector<double> ts27_temperaturs;
  int timestamp;
  double UCN_D2O_TS7_RDTEMP;
  sourceTree = (TTree*) fin->Get("SourceEpicsTree");
  sourceTree->SetBranchAddress("timestamp",&timestamp);
  sourceTree->SetBranchAddress("UCN_D2O_TS7_RDTEMP",&UCN_D2O_TS7_RDTEMP);
  
  eventTot = (Double_t)sourceTree->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    sourceTree->GetEvent(j);
    sourceReadTimes.push_back(timestamp);
    ts27_temperaturs.push_back(UCN_D2O_TS7_RDTEMP);
  }


  std::cout << "Finished SourceEpics loop " << std::endl;
  
  // Loop over the transitions, save the start of each transition and make a counter.
  std::vector<double> cycleStartTimes;
  std::vector<int> numberEventsPerCycle;
  std::vector<double> temperaturePerCycle;

  truntime->SetBranchAddress("cycleStartTime",&cycleStart); // time that cycle started (end of irradiation)
  truntime->SetBranchAddress("cycleValveOpenTime",&valveOpenTime); // time that valve opened
  truntime->SetBranchAddress("cycleValveCloseTime",&valveCloseTime); // time that valve closed
  truntime->SetBranchAddress("cycleDelayTime",&delayTime);   // delay time (between cycle start and valve open)
  truntime->SetBranchAddress("cycleOpenInterval",&openTime); // valve open time
  
  eventTot = (Double_t)truntime->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    truntime->GetEvent(j);
    cycleStartTimes.push_back(cycleStart);
    numberEventsPerCycle.push_back(0);
    // Find the temperature for this cycle.
    double temperature = 0;
    for( int i = 0; i < sourceReadTimes.size()-1; i++){
      if(cycleStart >= sourceReadTimes[i] && cycleStart < sourceReadTimes[i+1]){
        temperature = ts27_temperaturs[i];
        break;
      }

    }
    temperaturePerCycle.push_back(temperature);
  }

  std::cout << "The last cycle started (irradiation ended) at  " << (int)cycleStart << " sec." << std::endl;
  std::cout << "The delay time for the last cycle was " << delayTime << " sec." << std::endl;
  std::cout << "The valve open time for the last cycle was " << openTime << " sec." << std::endl;

  std::cout << "Finished transition loop " << std::endl;
  
  //  Now loop over the UCN hits.  Calculate the right number of hits for each cycle.
  double tUnixTimePrecise;
  Float_t tPSD;  
  UShort_t tChargeL;
  UShort_t tIsUCN, tChannel;
  uin->SetBranchAddress("tUnixTimePrecise",&tUnixTimePrecise);
  uin->SetBranchAddress("tIsUCN",&tIsUCN);
  uin->SetBranchAddress("tChannel",&tChannel);
  uin->SetBranchAddress("tPSD",&tPSD);
  uin->SetBranchAddress("tChargeL",&tChargeL);

  // Make on plot showing PSD vs QL for channel 0.
  TH2F *psd_vs_ql[16];
  for(int i = 0; i < 16; i++){
    char name[100],title[100];
    sprintf(name,"psd_vs_ql_%i",i);
    sprintf(title,"PSD vs QL ch %i",i);
    
    psd_vs_ql[i] = new TH2F(name,title,200,0,15000,200,-1,1);
  }

  // pointer for closeSourceEPics reads;
  int source_index = 0;
  
  eventTot = (Double_t)uin->GetEntries();
  for(ULong64_t j=0;j<eventTot;j++) {
    uin->GetEvent(j);
    // Check if this is a UCN hit.
    if(tIsUCN && cycleStartTimes.size() > 1){
      // check which cycle this is in...
      for(int i = 0; i < cycleStartTimes.size()-1; i++){
	//std::cout << tUnixTimePrecise << " " <<  cycleStartTimes[i] << " " << cycleStartTimes[i+1] << std::endl;
	if(tUnixTimePrecise >= cycleStartTimes[i] && tUnixTimePrecise < cycleStartTimes[i+1]){
	  numberEventsPerCycle[i]++;
	  break;
	}
      }
      
    }

    psd_vs_ql[tChannel]->Fill(tChargeL,tPSD);
    
  }

  std::cout << "Finished Li6 loop " << std::endl;

  // Plot PSD vs QL
  TCanvas *c1 = new TCanvas("c1","PSD vs QL",1200,800);
  c1->Divide(4,3);
  for(int i = 0; i < 12; i++){
    c1->cd(i+1);
    psd_vs_ql[i]->Draw("COL");
  }

  // Plot the UCN counts per cycle
  TCanvas *c2 = new TCanvas("c2","UCN vs cycle");

  TGraph *ucn_per_cycle = new TGraph();
  if(cycleStartTimes.size() > 0){
    for( int i = 0; i < cycleStartTimes.size()-1; i++){
      ucn_per_cycle->SetPoint(i,cycleStartTimes[i],numberEventsPerCycle[i]);
    }

    ucn_per_cycle->Draw("AP*");
    ucn_per_cycle->GetXaxis()->SetTitle("Cycle time");
    ucn_per_cycle->GetYaxis()->SetTitle("Number of UCN");
  }

  // Plot the UCN counts vs temperature
  TCanvas *c3 = new TCanvas("c3","UCN counts vs TS27 temperature");
  TGraph *ucn_vs_temperature = new TGraph();
  if(cycleStartTimes.size() > 0){
    for( int i = 0; i < cycleStartTimes.size()-1; i++){
      ucn_vs_temperature->SetPoint(i,temperaturePerCycle[i],numberEventsPerCycle[i]);
    }
    
    
    
    ucn_vs_temperature->Draw("AP*");
    ucn_vs_temperature->GetXaxis()->SetTitle("TS27 temperature");
    ucn_vs_temperature->GetYaxis()->SetTitle("Number of UCN");
  }




  
  
  
}
