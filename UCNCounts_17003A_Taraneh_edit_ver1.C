// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17003A WHICH IS THE
// UCN COUNT VS THE ISOPURE TEMPERATURE.
// DURING THE DATA ACQUISITON, THE ISOPURE HELIUM
// TEMPERATURE INCREASED.
// ***************************************************

#include <string>
#include <fstream>

#define max 100

void UCNCounts_17003A_Taraneh_edit_ver1(){

  TFile *fin548 = new TFile ("outputTree_548.root", "READ");
  
  TTree *outputTree548 = (TTree*) fin548 -> Get("cycle_info");


  // ADD THE IMPORTANT VARIABLES AND READ OFF THE TREE

  double cycleDelayTime548;
  outputTree548 -> SetBranchAddress("cycleDelayTime" , &cycleDelayTime548);

  double cycleNumber548;
  ouputTree548 -> SetBranchAddress("cycleNumber", &cycleNumber548);
  double cycleNumberArray548 [100];
  
  double UCNIntegral548;
  outputTree548 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral548);
  double UCNIntegralArray548 [100];

  UCNIntegralErr548;
  outputTree548 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr548);
  double UCNIntegralErrArray548 [100];

  double HistIntegral548;
  outputTree548 -> SetBranchAddress ("HistIntegral" , &HistIntegral548); 
  double HistIntegralArray [100];

  double HistIntegralErr548;
  outputTree548 -> SetBranchAddress ("HistIntegralErr", &HistIntegralErr548);
  double HistIntegralErrArray[100];

  double avets12Irrad548;
  outputTree548 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad548);
  double avets12IrradArray548 [100];
  
  double avets12ValveOpen548;
  outputTree548 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen548);
  double avets12ValveOpenArray548 [100];

  double maxts12Irrad548;
  outputTree548 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad548);
  double maxts12IrradArray548 [100];
  
  double maxts12ValveOpen548;
  outputTree548 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen548);
  double maxts12ValveOpenArray548 [100];

  double mints12Irrad548;
  outputTree548 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad548);
  double mints12IrradArray548 [100];
  
  double mints12ValveOpen548;
  outputTree548 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen548);
  double mints12ValveOpenArray548 [100];

  double ts12IrradErr548 [100];
  double ts12ValveOpenErr548 [100];

  double avecur548;
  outputTree548 -> SetBranchAddress ("AVE_PRDCUR" , &avecur548);
  double avecurArray548 [100];

  double maxcur548;
  outputTree548 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur548);
  double maxcurArray548 [100];

  double mincur548;
  outputTree548 -> SetBranchAddress ("MIN_PRDCUR" , &mincur548);
  double mincurArray548 [100];

  double ErrcurArray548 [100];

  double Baseline548;
  outputTree548 -> SetBranchAddress ("Baseline" , &Baseline548);
  double BaselineArray548 [100];

  double BaselineErr548;
  outputTree548 -> SetBranchAddress ("BaselineErr" , &BaselineErr548);
  double BaselineErrArray548 [100];

  double BaselineIrrad548;
  outputTree548 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad548);
  double BaselineIrradArray548 [100];

  double BaselineIrradErr548;
  outputTree548 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr548);
  double BaselineIrradErrArray548 [100];

  double BaselineIntegral548;
  outputTree548 -> SetBranchAddress ("BaselineIntegral" , &BaselineIntegral548);
  double BaselineIntegralArray548[100];

  double BaselineIrradIntegral548;
  outputTree548 -> SetBranchAddress ("BaselineIrradIntegral" , &BaselineIrradIntegral548);
  double BaselineIrradIntegralArray548[100];

  double UCNIntegralManualArray548 [100];
  double UCNIntegralManualErrArray548[100];


  int counts_548 = 0;
  
  ULong64_t events548;
  events548 = (Double_t) outputTree548 -> GetEntries();

  for (ULong64_t j = 0 ; j < events548 ; j++){
    outputTree548 -> GetEvent(j);
    UCNIntegralArray548[counts_548] = UCNIntegral548;
    UCNIntegralErrArray548[counts_548] = UCNIntegralErr548;
    HistIntegralArray548[counts_548] = HistIntegral548;
    HistIntegralErrArray548[counts_548] = sqrt (HistIntegral548);
    avets12IrradArray548[counts_548] = avets12Irrad548;
    avets12ValveOpenArray548[counts_548] = avets12ValveOpen548;
    maxts12IrradArray548[counts_548] = maxts12Irrad548;
    maxts12ValveOpenArray548[counts_548] = maxts12ValveOpen548;
    mints12IrradArray548[counts_548] = mints12Irrad548; 
    mints12ValveOpenArray548[counts_548] = mints12ValveOpen548;
    ts12IrradErr548[counts_548] = (maxts12Irrad548 - mints12Irrad548)/2;
    ts12ValveOpenErr548[counts_548] = (maxts12ValveOpen548 - mints12ValveOpen548)/2;
    avecurArray548[counts_548] = avecur548;
    maxcurArray548[counts_548] = maxcur548;
    mincurArray548[counts_548] = mincur548;
    ErrcurArray548[counts_548] = (maxcur548 - mincur548)/2;
    delaytimeArray548[counts_548] = cycleDelayTime548;
    cycleNumberArray548[counts_548] = cycleNumber548;
    BaselineArray548[counts_548] = Baseline548;
    BaselineIrradArray548[counts_548] = BaselineIrrad548;
    BaselineIrradErrArray548[counts_548] = BaselineIrradErr548;
    BaselineIntegralArray548[counts_548] = BaselineIntegral548;
    BaselineIrradIntegralArray[counts_548] = BaselineIrradIntegral548;
    UCNIntegralManualArray548[counts_548] = HistIntegral548 - BaselineIntegral548;
    UCNIntegralManualErrArray548[counts_548] = sqrt(HistIntegral548 - BaselineIntegral548);
    counts_548++;
  }

}
