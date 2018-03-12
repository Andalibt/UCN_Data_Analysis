//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS.
// TO CREATE THE RELEVANT ROOT FILE FOR THOSE MEASUREMENTS RUN
// plot_ucn_per_cycle_Taraneh_edit_StorageTime.C
// THE ROOT FILE IS CALLED outputTree_StorageTime.root
//****************************************************************
#include <string>
#include <fstream>

#define max 352

void Storage_time_analysis_Taraneh_ver1(){
gROOT->ProcessLine("#include <vector>");
  // READ THE TREE

  //TFile* fin = new TFile("outputTree_StorageTime.root","READ");
  TFile fin("outputTree_StorageTime.root","READ");
  `if ( fin->IsOpen() ){
    printf("File opened successfully\n");
  }
    if (fin.IsZombie()) {
       cout << "Error opening file" << endl;
       exit(-1);
    }


    TH2* StorageTime = new TH2F("Counts vs Delay Time", "Counts vs Delay Time", 100, 0, 200 , 100, 0.0, 80000);
  TTree *outputTree = (TTree*) fin.Get("cycle_info");
  
  ULong64_t events;
  events = (Double_t)outputTree->GetEntries();

  vector<double> * delayTime(events);
  vector<int> *Li6CountsCycleStart(events);
  vector<int> *runNumber(events);


  outputTree -> SetBranchAddress ("runNumber" , &runNumber);
  outputTree -> SetBranchAddress ("cycleDelayTime", &delayTime);
  outputTree -> SetBranchAddress ("Li6CountsCycleStart", &Li6CountsCycleStart);
  double n = (double) outputTree->GetEntries();

  cout << "Tree Entries " << n << endl;
  for (int i = 0; i < n; i++){
    outputTree->GetEntry(i);
    double delay = delayTime->size();
    double counts= Li6CountsCycleStart-> size()
      StorageTime -> Fill(counts,delay);
  }



  break;
  for (int j = 0; j < delayTime.size(); ++j){
    //delayTimeArray[j] = delayTime.at(j) ;
    //Li6CountsCycleStartArray[j] = Li6CountsCycleStart.at(j) ;
    cout << Li6CountsCycleStart[j] << endl;
    cout << delayTime[j] << endl;
    cout << j << endl;
  }


  
  /*  TH2* StorageTime = new TH2F("Counts vs Delay Time", "Counts vs Delay Time", 100, 0, 150000000 , 100, 0.0, 70000);
  for (int i =0 ; i < delayTimeArray.size(); i++){
    //StorageTime -> Fill(delayTimeArray[i] , Li6CountsCycleStartArray[i]);
    cout << delayTimeArray[i] << endl;
    } */
}
