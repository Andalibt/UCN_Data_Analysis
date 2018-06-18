//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17002.
// Second pass of analysis.
// Taraneh Andalib June 18, 2018
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17002_Taraneh_edit_ver3(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin532 = new TFile("./2ndpass/outputTree_532.root","READ");
  TFile *fin533 = new TFile("./2ndpass/outputTree_533.root","READ");
  TFile *fin534 = new TFile("./2ndpass/outputTree_534.root","READ");
  TFile *fin535 = new TFile("./2ndpass/outputTree_535.root","READ");
  TFile *fin536 = new TFile("./2ndpass/outputTree_536.root","READ");
  TFile *fin537 = new TFile("./2ndpass/outputTree_537.root","READ");
  TFile *fin538 = new TFile("./2ndpass/outputTree_538.root","READ");
  TFile *fin539 = new TFile("./2ndpass/outputTree_539.root","READ");
  TFile *fin540 = new TFile("./2ndpass/outputTree_540.root","READ");

  
  TTree *outputTree532 = (TTree*) fin532 -> Get("cycle_info");
  TTree *outputTree533 = (TTree*) fin533 -> Get("cycle_info");
  TTree *outputTree534 = (TTree*) fin534 -> Get("cycle_info");
  TTree *outputTree535 = (TTree*) fin535 -> Get("cycle_info");
  TTree *outputTree536 = (TTree*) fin536 -> Get("cycle_info");
  TTree *outputTree537 = (TTree*) fin537 -> Get("cycle_info");
  TTree *outputTree538 = (TTree*) fin538 -> Get("cycle_info");
  TTree *outputTree539 = (TTree*) fin539 -> Get("cycle_info");
  TTree *outputTree540 = (TTree*) fin540 -> Get("cycle_info");
  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime532;
  double cycleDelayTime533;
  double cycleDelayTime534;
  double cycleDelayTime535;
  double cycleDelayTime536;
  double cycleDelayTime537;
  double cycleDelayTime538;
  double cycleDelayTime539;
  double cycleDelayTime540;


  outputTree532 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime532);
  outputTree533 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime533);
  outputTree534 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime534);
  outputTree535 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime535);
  outputTree536 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime536);
  outputTree537 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime537);
  outputTree538 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime538);
  outputTree539 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime539);
  outputTree540 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime540);


  // DELAY TIME (ARRAY)
  double delaytimeArray532 [100];
  double delaytimeArray533 [100];
  double delaytimeArray534 [100];
  double delaytimeArray535 [100];
  double delaytimeArray536 [100];
  double delaytimeArray537 [100];
  double delaytimeArray538 [100];
  double delaytimeArray539 [100];
  double delaytimeArray540 [100];


  double cycleValveOpenTime532;
  double cycleValveOpenTime533;
  double cycleValveOpenTime534;
  double cycleValveOpenTime535;
  double cycleValveOpenTime536;
  double cycleValveOpenTime537;
  double cycleValveOpenTime538;
  double cycleValveOpenTime539;
  double cycleValveOpenTime540;

  outputTree532 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime532);
  outputTree533 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime533);
  outputTree534 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime534);
  outputTree535 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime535);
  outputTree536 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime536);
  outputTree537 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime537);
  outputTree538 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime538);
  outputTree539 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime539);
  outputTree540 -> SetBranchAddress ("cycleValveOpenTime" , &cycleValveOpenTime540);
  
  double cycleValveCloseTime532;
  double cycleValveCloseTime533;
  double cycleValveCloseTime534;
  double cycleValveCloseTime535;
  double cycleValveCloseTime536;
  double cycleValveCloseTime537;
  double cycleValveCloseTime538;
  double cycleValveCloseTime539;
  double cycleValveCloseTime540;

  outputTree532 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime532);
  outputTree533 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime533);
  outputTree534 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime534);
  outputTree535 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime535);
  outputTree536 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime536);
  outputTree537 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime537);
  outputTree538 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime538);
  outputTree539 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime539);
  outputTree540 -> SetBranchAddress ("cycleValveCloseTime" , &cycleValveCloseTime540);

  // CYCLE NUMBER
  int cycleNumber532;
  int cycleNumber533;
  int cycleNumber534;
  int cycleNumber535;
  int cycleNumber536;
  int cycleNumber537;
  int cycleNumber538;
  int cycleNumber539;
  int cycleNumber540;

  outputTree532 -> SetBranchAddress ("cycleNumber" , &cycleNumber532);
  outputTree533 -> SetBranchAddress ("cycleNumber" , &cycleNumber533);
  outputTree534 -> SetBranchAddress ("cycleNumber" , &cycleNumber534);
  outputTree535 -> SetBranchAddress ("cycleNumber" , &cycleNumber535);
  outputTree536 -> SetBranchAddress ("cycleNumber" , &cycleNumber536);
  outputTree537 -> SetBranchAddress ("cycleNumber" , &cycleNumber537);
  outputTree538 -> SetBranchAddress ("cycleNumber" , &cycleNumber538);
  outputTree539 -> SetBranchAddress ("cycleNumber" , &cycleNumber539);
  outputTree540 -> SetBranchAddress ("cycleNumber" , &cycleNumber540);


  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray532 [100];
  double cycleNumberArray533 [100];
  double cycleNumberArray534 [100];
  double cycleNumberArray535 [100];
  double cycleNumberArray536 [100];
  double cycleNumberArray537 [100];
  double cycleNumberArray538 [100];
  double cycleNumberArray539 [100];
  double cycleNumberArray540 [100];


  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral532;
  double HistIntegral533;
  double HistIntegral534;
  double HistIntegral535;
  double HistIntegral536;
  double HistIntegral537;
  double HistIntegral538;
  double HistIntegral539;
  double HistIntegral540;

  outputTree532 -> SetBranchAddress ("HistIntegral" , &HistIntegral532); 
  outputTree533 -> SetBranchAddress ("HistIntegral" , &HistIntegral533);
  outputTree534 -> SetBranchAddress ("HistIntegral" , &HistIntegral534);
  outputTree535 -> SetBranchAddress ("HistIntegral" , &HistIntegral535);
  outputTree536 -> SetBranchAddress ("HistIntegral" , &HistIntegral536);
  outputTree537 -> SetBranchAddress ("HistIntegral" , &HistIntegral537);
  outputTree538 -> SetBranchAddress ("HistIntegral" , &HistIntegral538);
  outputTree539 -> SetBranchAddress ("HistIntegral" , &HistIntegral539);
  outputTree540 -> SetBranchAddress ("HistIntegral" , &HistIntegral540);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray532 [100];
  double HistIntegralArray533 [100];
  double HistIntegralArray534 [100];
  double HistIntegralArray535 [100];
  double HistIntegralArray536 [100];
  double HistIntegralArray537 [100];
  double HistIntegralArray538 [100];
  double HistIntegralArray539 [100];
  double HistIntegralArray540 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray532 [100];
  double HistIntegralErrArray533 [100];
  double HistIntegralErrArray534 [100];
  double HistIntegralErrArray535 [100];
  double HistIntegralErrArray536 [100];
  double HistIntegralErrArray537 [100];
  double HistIntegralErrArray538 [100];
  double HistIntegralErrArray539 [100];
  double HistIntegralErrArray540 [100];



  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen532;
  double avets12ValveOpen533;
  double avets12ValveOpen534;
  double avets12ValveOpen535;
  double avets12ValveOpen536;
  double avets12ValveOpen537;
  double avets12ValveOpen538;
  double avets12ValveOpen539;
  double avets12ValveOpen540;

  outputTree532 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen532);
  outputTree533 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen533);
  outputTree534 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen534);
  outputTree535 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen535);
  outputTree536 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen536);
  outputTree537 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen537);
  outputTree538 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen538);
  outputTree539 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen539);
  outputTree540 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen540);


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray532 [100];
  double avets12ValveOpenArray533 [100];
  double avets12ValveOpenArray534 [100];
  double avets12ValveOpenArray535 [100];
  double avets12ValveOpenArray536 [100];
  double avets12ValveOpenArray537 [100];
  double avets12ValveOpenArray538 [100];
  double avets12ValveOpenArray539 [100];
  double avets12ValveOpenArray540 [100];


 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen532;
  double maxts12ValveOpen533;
  double maxts12ValveOpen534;
  double maxts12ValveOpen535;
  double maxts12ValveOpen536;
  double maxts12ValveOpen537;
  double maxts12ValveOpen538;
  double maxts12ValveOpen539;
  double maxts12ValveOpen540;

  outputTree532 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen532);
  outputTree533 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen533);
  outputTree534 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen534);
  outputTree535 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen535);
  outputTree536 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen536);
  outputTree537 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen537);
  outputTree538 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen538);
  outputTree539 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen539);
  outputTree540 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen540);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen532;
  double mints12ValveOpen533;
  double mints12ValveOpen534;
  double mints12ValveOpen535;
  double mints12ValveOpen536;
  double mints12ValveOpen537;
  double mints12ValveOpen538;
  double mints12ValveOpen539;
  double mints12ValveOpen540;
  
  outputTree532 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen532);
  outputTree533 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen533);
  outputTree534 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen534);
  outputTree535 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen535);
  outputTree536 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen536);
  outputTree537 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen537);
  outputTree538 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen538);
  outputTree539 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen539);
  outputTree540 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen540);



  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr532 [100];
  double ts12ValveOpenErr533 [100];
  double ts12ValveOpenErr534 [100];
  double ts12ValveOpenErr535 [100];
  double ts12ValveOpenErr536 [100];
  double ts12ValveOpenErr537 [100];
  double ts12ValveOpenErr538 [100];
  double ts12ValveOpenErr539 [100];
  double ts12ValveOpenErr540 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur532;
  double avecur533;
  double avecur534;
  double avecur535;
  double avecur536;
  double avecur537;
  double avecur538;
  double avecur539;
  double avecur540;

  outputTree532 -> SetBranchAddress ("AVE_PRDCUR" , &avecur532);
  outputTree533 -> SetBranchAddress ("AVE_PRDCUR" , &avecur533);
  outputTree534 -> SetBranchAddress ("AVE_PRDCUR" , &avecur534);
  outputTree535 -> SetBranchAddress ("AVE_PRDCUR" , &avecur535);
  outputTree536 -> SetBranchAddress ("AVE_PRDCUR" , &avecur536);
  outputTree537 -> SetBranchAddress ("AVE_PRDCUR" , &avecur537);
  outputTree538 -> SetBranchAddress ("AVE_PRDCUR" , &avecur538);
  outputTree539 -> SetBranchAddress ("AVE_PRDCUR" , &avecur539);
  outputTree540 -> SetBranchAddress ("AVE_PRDCUR" , &avecur540);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray532 [100];
  double avecurArray533 [100];
  double avecurArray534 [100];
  double avecurArray535 [100];
  double avecurArray536 [100];
  double avecurArray537 [100];
  double avecurArray538 [100];
  double avecurArray539 [100];
  double avecurArray540 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur532;
  double maxcur533;
  double maxcur534;
  double maxcur535;
  double maxcur536;
  double maxcur537;
  double maxcur538;
  double maxcur539;
  double maxcur540;

  outputTree532 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur532);
  outputTree533 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur533);
  outputTree534 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur534);
  outputTree535 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur535);
  outputTree536 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur536);
  outputTree537 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur537);
  outputTree538 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur538);
  outputTree539 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur539);
  outputTree540 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur540);


  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur532;
  double mincur533;
  double mincur534;
  double mincur535;
  double mincur536;
  double mincur537;
  double mincur538;
  double mincur539;
  double mincur540;

  outputTree532 -> SetBranchAddress ("MIN_PRDCUR" , &mincur532);
  outputTree533 -> SetBranchAddress ("MIN_PRDCUR" , &mincur533);
  outputTree534 -> SetBranchAddress ("MIN_PRDCUR" , &mincur534);
  outputTree535 -> SetBranchAddress ("MIN_PRDCUR" , &mincur535);
  outputTree536 -> SetBranchAddress ("MIN_PRDCUR" , &mincur536);
  outputTree537 -> SetBranchAddress ("MIN_PRDCUR" , &mincur537);
  outputTree538 -> SetBranchAddress ("MIN_PRDCUR" , &mincur538);
  outputTree539 -> SetBranchAddress ("MIN_PRDCUR" , &mincur539);
  outputTree540 -> SetBranchAddress ("MIN_PRDCUR" , &mincur540);


  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray532 [100];
  double ErrcurArray533 [100];
  double ErrcurArray534 [100];
  double ErrcurArray535 [100];
  double ErrcurArray536 [100];
  double ErrcurArray537 [100];
  double ErrcurArray538 [100];
  double ErrcurArray539 [100];
  double ErrcurArray540 [100];



  double BASELINERATE532;
  double BASELINERATE533;
  double BASELINERATE534;
  double BASELINERATE535;
  double BASELINERATE536;
  double BASELINERATE537;
  double BASELINERATE538;
  double BASELINERATE539;
  double BASELINERATE540;
  
 
  outputTree532 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE532);
  outputTree533 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE533);
  outputTree534 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE534);
  outputTree535 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE535);
  outputTree536 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE536);
  outputTree537 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE537);
  outputTree538 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE538);
  outputTree539 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE539);
  outputTree540 -> SetBranchAddress ("BASELINERATE" , &BASELINERATE540);

  double UCNCounts532[100];
  double UCNCounts533[100];
  double UCNCounts534[100];
  double UCNCounts535[100];
  double UCNCounts536[100];
  double UCNCounts537[100];
  double UCNCounts538[100];
  double UCNCounts539[100];
  double UCNCounts540[100];


  double UCNCountsErr532[100];
  double UCNCountsErr533[100];
  double UCNCountsErr534[100];
  double UCNCountsErr535[100];
  double UCNCountsErr536[100];
  double UCNCountsErr537[100];
  double UCNCountsErr538[100];
  double UCNCountsErr539[100];
  double UCNCountsErr540[100];


  
  // STORAGE LIFETIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage532;
  double storage533;
  double storage534;
  double storage535;
  double storage536;
  double storage537;
  double storage538;
  double storage539;
  double storage540;

  // STORAGE LIFETIME ERR FROM THE FIT
  double storageErr532;
  double storageErr533;
  double storageErr534;
  double storageErr535;
  double storageErr536;
  double storageErr537;
  double storageErr538;
  double storageErr539;
  double storageErr540;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_532 = 0;
  int counts_533 = 0;
  int counts_534 = 0;
  int counts_535 = 0;
  int counts_536 = 0;
  int counts_537 = 0;
  int counts_538 = 0;
  int counts_539 = 0;
  int counts_540 = 0;

  double UCNCountsAll[100];
  double UCNCountsErrAll[100];
  double delayTimeAll[100];
  
  ULong64_t events532;
  events532 = (Double_t)outputTree532 -> GetEntries();

  for (ULong64_t j = 0 ; j < events532 ; j++){
    outputTree532 -> GetEvent(j);

    HistIntegralArray532[counts_532] = HistIntegral532;
    HistIntegralErrArray532[counts_532] = sqrt (HistIntegral532);
    UCNCounts532[counts_532] = HistIntegral532 - BASELINERATE532*(cycleValveCloseTime532 - cycleValveOpenTime532);
    UCNCountsErr532[counts_532] = sqrt(UCNCounts532[counts_532]);
    avets12ValveOpenArray532[counts_532] = avets12ValveOpen532;
    ts12ValveOpenErr532[counts_532] = (maxts12ValveOpen532 - mints12ValveOpen532)/2;
    avecurArray532[counts_532] = avecur532;
    ErrcurArray532[counts_532] = (maxcur532 - mincur532)/2;
    delaytimeArray532[counts_532] = cycleDelayTime532;
    cycleNumberArray532[counts_532] = cycleNumber532;
    UCNCountsAll[counts_532] = HistIntegral532 - BASELINERATE532*(cycleValveCloseTime532 - cycleValveOpenTime532);
    UCNCountsErrAll[counts_532] = sqrt (UCNCounts532[counts_532]);
    delayTimeAll[counts_532] = cycleDelayTime532;
    counts_532++;
  }


  ULong64_t events533;
  events533 = (Double_t)outputTree533 -> GetEntries();

  for (ULong64_t j = 0 ; j < events533 ; j++){
    outputTree533 -> GetEvent(j);
   
    HistIntegralArray533[counts_533] = HistIntegral533;
    HistIntegralErrArray533[counts_533] = sqrt (HistIntegral533);
    UCNCounts533[counts_533] = HistIntegral533 - BASELINERATE533*(cycleValveCloseTime533 - cycleValveOpenTime533);
    UCNCountsErr533[counts_533] = sqrt(UCNCounts533[counts_533]);
    avets12ValveOpenArray533[counts_533] = avets12ValveOpen533;
    ts12ValveOpenErr533[counts_533] = (maxts12ValveOpen533 - mints12ValveOpen533)/2;
    avecurArray533[counts_533] = avecur533;
    ErrcurArray533[counts_533] = (maxcur533 - mincur533)/2;
    delaytimeArray533[counts_533] = cycleDelayTime533;
    cycleNumberArray533[counts_533] = cycleNumber533;
    UCNCountsAll[counts_532 +counts_533] = HistIntegral533 - BASELINERATE533*(cycleValveCloseTime533 - cycleValveOpenTime533);
    UCNCountsErrAll[counts_532 + counts_533] = sqrt (UCNCounts533[counts_533]);
    delayTimeAll[counts_532 + counts_533] = cycleDelayTime533;
    counts_533++;
  }

  ULong64_t events534;
  events534 = (Double_t)outputTree534 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events534 ; j++){
    outputTree534 -> GetEvent(j);

       
    HistIntegralArray534[counts_534] = HistIntegral534;
    HistIntegralErrArray534[counts_534] = sqrt (HistIntegral534);
    UCNCounts534[counts_534] = HistIntegral534 - BASELINERATE534*(cycleValveCloseTime534 - cycleValveOpenTime534);
    UCNCountsErr534[counts_534] = sqrt(UCNCounts534[counts_534]);
    avets12ValveOpenArray534[counts_534] = avets12ValveOpen534;
    ts12ValveOpenErr534[counts_534] = (maxts12ValveOpen534 - mints12ValveOpen534)/2;
    avecurArray534[counts_534] = avecur534;
    ErrcurArray534[counts_534] = (maxcur534 - mincur534)/2;
    delaytimeArray534[counts_534] = cycleDelayTime534;
    cycleNumberArray534[counts_534] = cycleNumber534;
    UCNCountsAll[counts_532 +counts_533 + counts_534] = HistIntegral534 - BASELINERATE534*(cycleValveCloseTime534 - cycleValveOpenTime534);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534] = sqrt (UCNCounts534[counts_534]);
    delayTimeAll[counts_532 + counts_533 + counts_534] = cycleDelayTime534;
    counts_534++;
  }
  
  ULong64_t events535;
  events535 = (Double_t)outputTree535 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events535 ; j++){
    outputTree535 -> GetEvent(j);

   
    HistIntegralArray535[counts_535] = HistIntegral535;
    HistIntegralErrArray535[counts_535] = sqrt (HistIntegral535);
    UCNCounts535[counts_535] = HistIntegral535 - BASELINERATE535*(cycleValveCloseTime535 - cycleValveOpenTime535);
    UCNCountsErr535[counts_535] = sqrt(UCNCounts535[counts_535]);
    avets12ValveOpenArray535[counts_535] = avets12ValveOpen535;
    ts12ValveOpenErr535[counts_535] = (maxts12ValveOpen535 - mints12ValveOpen535)/2;
    avecurArray535[counts_535] = avecur535;
    ErrcurArray535[counts_535] = (maxcur535 - mincur535)/2;
    delaytimeArray535[counts_535] = cycleDelayTime535;
    cycleNumberArray535[counts_535] = cycleNumber535;
    UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535] = HistIntegral535 - BASELINERATE535*(cycleValveCloseTime535 - cycleValveOpenTime535);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535] = sqrt (UCNCounts535[counts_535]);
    delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535] = cycleDelayTime535;
    counts_535++;
  }

  
  ULong64_t events536;
  events536 = (Double_t)outputTree536 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events536 ; j++){
    outputTree536 -> GetEvent(j);
    if (j == 4)
      continue;
       
    HistIntegralArray536[counts_536] = HistIntegral536;
    HistIntegralErrArray536[counts_536] = sqrt (HistIntegral536);
    UCNCounts536[counts_536] = HistIntegral536 - BASELINERATE536*(cycleValveCloseTime536 - cycleValveOpenTime536);
    UCNCountsErr536[counts_536] = sqrt(UCNCounts536[counts_536]);
    avets12ValveOpenArray536[counts_536] = avets12ValveOpen536;
    ts12ValveOpenErr536[counts_536] = (maxts12ValveOpen536 - mints12ValveOpen536)/2;
    avecurArray536[counts_536] = avecur536;
    ErrcurArray536[counts_536] = (maxcur536 - mincur536)/2;
    delaytimeArray536[counts_536] = cycleDelayTime536;
    cycleNumberArray536[counts_536] = cycleNumber536;
    UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535 + counts_536] = HistIntegral536 - BASELINERATE536*(cycleValveCloseTime536 - cycleValveOpenTime536);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536] = sqrt (UCNCounts536[counts_536]);
    delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536] = cycleDelayTime536;
    counts_536++;
  }

  ULong64_t events537;
  events537 = (Double_t)outputTree537 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events537 ; j++){
    outputTree537 -> GetEvent(j);

      
    HistIntegralArray537[counts_537] = HistIntegral537;
    HistIntegralErrArray537[counts_537] = sqrt (HistIntegral537);
    UCNCounts537[counts_537] = HistIntegral537 - BASELINERATE537*(cycleValveCloseTime537 - cycleValveOpenTime537);
    UCNCountsErr537[counts_537] = sqrt(UCNCounts537[counts_537]);
    avets12ValveOpenArray537[counts_537] = avets12ValveOpen537;
    ts12ValveOpenErr537[counts_537] = (maxts12ValveOpen537 - mints12ValveOpen537)/2;
    avecurArray537[counts_537] = avecur537;
    ErrcurArray537[counts_537] = (maxcur537 - mincur537)/2;
    delaytimeArray537[counts_537] = cycleDelayTime537;
    cycleNumberArray537[counts_537] = cycleNumber537;
    UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535 + counts_536 + counts_537] = HistIntegral537 - BASELINERATE537*(cycleValveCloseTime537 - cycleValveOpenTime537);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537] = sqrt (UCNCounts537[counts_537]);
    delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537] = cycleDelayTime537;
    counts_537++;
  }


  ULong64_t events538;
  events538 = (Double_t)outputTree538 -> GetEntries();


  for (ULong64_t j = 0 ; j < events538 ; j++){
    outputTree538 -> GetEvent(j);
      
    HistIntegralArray538[counts_538] = HistIntegral538;
    HistIntegralErrArray538[counts_538] = sqrt (HistIntegral538);
    UCNCounts538[counts_538] = HistIntegral538 - BASELINERATE538*(cycleValveCloseTime538 - cycleValveOpenTime538);
    UCNCountsErr538[counts_538] = sqrt(UCNCounts538[counts_538]);
    avets12ValveOpenArray538[counts_538] = avets12ValveOpen538;
    ts12ValveOpenErr538[counts_538] = (maxts12ValveOpen538 - mints12ValveOpen538)/2;
    avecurArray538[counts_538] = avecur538;
    ErrcurArray538[counts_538] = (maxcur538 - mincur538)/2;
    delaytimeArray538[counts_538] = cycleDelayTime538;
    cycleNumberArray538[counts_538] = cycleNumber538;
    //UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535 + counts_536 + counts_537 + counts_538] = HistIntegral538 - BASELINERATE538*(cycleValveCloseTime538 - cycleValveOpenTime538);
    //UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537 + counts_538] = sqrt (UCNCounts538[counts_538]);
    //delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537 + counts_538] = cycleDelayTime538;
    counts_538++;
  }


  ULong64_t events539;
  events539 = (Double_t)outputTree539 -> GetEntries();

  for (ULong64_t j = 0 ; j < events539 ; j++){
    outputTree539 -> GetEvent(j);
    if (j==3)
      continue;
    
    HistIntegralArray539[counts_539] = HistIntegral539;
    HistIntegralErrArray539[counts_539] = sqrt (HistIntegral539);
    UCNCounts539[counts_539] = HistIntegral539 - BASELINERATE539*(cycleValveCloseTime539 - cycleValveOpenTime539);
    UCNCountsErr539[counts_539] = sqrt(UCNCounts539[counts_539]);
    avets12ValveOpenArray539[counts_539] = avets12ValveOpen539;
    ts12ValveOpenErr539[counts_539] = (maxts12ValveOpen539 - mints12ValveOpen539)/2;
    avecurArray539[counts_539] = avecur539;
    ErrcurArray539[counts_539] = (maxcur539 - mincur539)/2;
    delaytimeArray539[counts_539] = cycleDelayTime539;
    cycleNumberArray539[counts_539] = cycleNumber539;
    UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535 + counts_536 + counts_537  + counts_539] = HistIntegral539 - BASELINERATE539*(cycleValveCloseTime539 - cycleValveOpenTime539);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537  + counts_539] = sqrt (UCNCounts539[counts_539]);
    delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537  + counts_539] = cycleDelayTime539;
    counts_539++;
  }


  ULong64_t events540;
  events540 = (Double_t)outputTree540 -> GetEntries();


  for (ULong64_t j = 0 ; j < events540 ; j++){
    outputTree540 -> GetEvent(j);

          
    HistIntegralArray540[counts_540] = HistIntegral540;
    HistIntegralErrArray540[counts_540] = sqrt (HistIntegral540);
    UCNCounts540[counts_540] = HistIntegral540 - BASELINERATE540*(cycleValveCloseTime540 - cycleValveOpenTime540);
    UCNCountsErr540[counts_540] = sqrt(UCNCounts540[counts_540]);
    avets12ValveOpenArray540[counts_540] = avets12ValveOpen540;
    ts12ValveOpenErr540[counts_540] = (maxts12ValveOpen540 - mints12ValveOpen540)/2;
    avecurArray540[counts_540] = avecur540;
    ErrcurArray540[counts_540] = (maxcur540 - mincur540)/2;
    delaytimeArray540[counts_540] = cycleDelayTime540;
    cycleNumberArray540[counts_540] = cycleNumber540;
    UCNCountsAll[counts_532 +counts_533 + counts_534 + counts_535 + counts_536 + counts_537  + counts_539 + counts_540] = HistIntegral540 - BASELINERATE540*(cycleValveCloseTime540 - cycleValveOpenTime540);
    UCNCountsErrAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537 + counts_539 + counts_540] = sqrt (UCNCounts540[counts_540]);
    delayTimeAll[counts_532 + counts_533 + counts_534 + counts_535 + counts_536 + counts_537  + counts_539 + counts_540] = cycleDelayTime540;
    counts_540++;
  }


  // ONE EXPONENTIAL FIT
  TF1 *fit = new TF1 ("fit" , "[0]*exp(-x/[1]) ", 0, 120);
  fit -> SetParNames("Amplitude" , "Storage Lifetime");  
  fit -> SetParameters(100000,30);
  fit -> SetParLimits(0, 7000, 190000);
  fit -> SetParLimits(1, 10, 45);

  // **************************************************************************
  //               GRAPHS
  // **************************************************************************


  //*********************************
  //*********************************
  //              532
  //*********************************
  //*********************************

  TCanvas *c532_cycleNum = new TCanvas("c532_cycleNum" , "c532_cycleNum" , 1200, 800);
  c532_cycleNum -> Divide(2,2);
  TPad *p5 = c532_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr532_cyclecounts = new TGraphErrors (counts_532 , cycleNumberArray532, UCNCounts532, 0 , UCNCountsErr532);
  gr532_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr532_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr532_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr532_cyclehist = new TGraphErrors(counts_532, cycleNumberArray532 , HistIntegralArray532, 0, HistIntegralErrArray532);

  gr532_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr532_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr532_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr532_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr532_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr532_cyclehist -> SetMarkerColor(2);
  gr532_cyclehist -> SetMarkerStyle(20);

  TLegend *leg2 = new TLegend (0.4, 0.7 , 0.9 , 0.9);
  leg2 -> AddEntry(gr532_cyclecounts, "UCN counts without background" , "p");
  leg2 -> AddEntry(gr532_cyclehist, "UCN counts with background" , "p");

  
  gr532_cyclecounts -> Draw("Ap");
  gr532_cyclehist -> Draw("p");

  leg2-> Draw();

  c532_cycleNum -> cd(2);
  TGraphErrors *gr532_cycledelay = new TGraphErrors (counts_532 , cycleNumberArray532, delaytimeArray532, 0 , 0);
  gr532_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr532_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr532_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr532_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cycledelay -> SetMarkerStyle(20);

  gr532_cycledelay -> Draw("Ap");


  c532_cycleNum -> cd(3);

  TGraphErrors *gr532_cycletempValveOpen = new TGraphErrors (counts_532 , cycleNumberArray532, avets12ValveOpenArray532, 0 , ts12ValveOpenErr532);

  gr532_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr532_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr532_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr532_cycletempValveOpen -> SetMarkerStyle(20);
  gr532_cycletempValveOpen -> SetMarkerColor(2);
  gr532_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr532_cycletempValveOpen -> Draw("Ap");

  c532_cycleNum -> cd(4);
  TGraphErrors *gr532_cyclecur = new TGraphErrors (counts_532 , cycleNumberArray532 , avecurArray532, 0, ErrcurArray532 );
  gr532_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr532_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr532_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr532_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr532_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr532_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr532_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr532_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr532_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr532_cyclecur -> SetMarkerStyle(20);
  gr532_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              533
  //*********************************
  //*********************************


  TCanvas *c533_cycleNum = new TCanvas("c533_cycleNum" , "c533_cycleNum" , 1200, 800);
  c533_cycleNum -> Divide(2,2);
  TPad *p533_4 = c533_cycleNum->cd(1);
  p533_4->SetLogy(); 
  TGraphErrors *gr533_cyclecounts = new TGraphErrors (counts_533 , cycleNumberArray533, UCNCounts533, 0 , UCNCountsErr533);
  gr533_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr533_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr533_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr533_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr533_cyclehist = new TGraphErrors(counts_533, cycleNumberArray533 , HistIntegralArray533, 0, HistIntegralErrArray533);

  gr533_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr533_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr533_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr533_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr533_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr533_cyclehist -> SetMarkerColor(2);
  gr533_cyclehist -> SetMarkerStyle(20);

  gr533_cyclecounts -> Draw("Ap");
  gr533_cyclehist -> Draw("p");

  leg2-> Draw();

  c533_cycleNum -> cd(2);
  TGraphErrors *gr533_cycledelay = new TGraphErrors (counts_533 , cycleNumberArray533, delaytimeArray533, 0 , 0);
  gr533_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr533_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr533_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr533_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cycledelay -> SetMarkerStyle(20);

  gr533_cycledelay -> Draw("Ap");


  c533_cycleNum -> cd(3);

  TGraphErrors *gr533_cycletempValveOpen = new TGraphErrors (counts_533 , cycleNumberArray533, avets12ValveOpenArray533, 0 , ts12ValveOpenErr533);

  gr533_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr533_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr533_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr533_cycletempValveOpen -> SetMarkerStyle(20);
  gr533_cycletempValveOpen -> SetMarkerColor(2);
  gr533_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cycletempValveOpen -> Draw("Ap");


  c533_cycleNum -> cd(4);
  TGraphErrors *gr533_cyclecur = new TGraphErrors (counts_533 , cycleNumberArray533 , avecurArray533, 0, ErrcurArray533 );
  gr533_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr533_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr533_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr533_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr533_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr533_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr533_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr533_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr533_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr533_cyclecur -> SetMarkerStyle(20);
  gr533_cyclecur -> Draw("Ap");

  //*********************************
  //*********************************
  //              534
  //*********************************
  //*********************************


  TCanvas *c534_cycleNum = new TCanvas("c534_cycleNum" , "c534_cycleNum" , 1200, 800);
  c534_cycleNum -> Divide(2,2);
  TPad *p534_4 = c534_cycleNum->cd(1);
  p534_4->SetLogy(); 
  TGraphErrors *gr534_cyclecounts = new TGraphErrors (counts_534 , cycleNumberArray534, UCNCounts534, 0 , UCNCountsErr534);
  gr534_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr534_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr534_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr534_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr534_cyclehist = new TGraphErrors(counts_534, cycleNumberArray534 , HistIntegralArray534, 0, HistIntegralErrArray534);

  gr534_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr534_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr534_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr534_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr534_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr534_cyclehist -> SetMarkerColor(2);
  gr534_cyclehist -> SetMarkerStyle(20);

  gr534_cyclecounts -> Draw("Ap");
  gr534_cyclehist -> Draw("p");

  leg2-> Draw();

  c534_cycleNum -> cd(2);
 TGraphErrors *gr534_cycledelay = new TGraphErrors (counts_534 , cycleNumberArray534, delaytimeArray534, 0 , 0);
  gr534_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr534_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr534_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr534_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cycledelay -> SetMarkerStyle(20);

  gr534_cycledelay -> Draw("Ap");


  c534_cycleNum -> cd(3);

  TGraphErrors *gr534_cycletempValveOpen = new TGraphErrors (counts_534 , cycleNumberArray534, avets12ValveOpenArray534, 0 , ts12ValveOpenErr534);

  gr534_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr534_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr534_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr534_cycletempValveOpen -> SetMarkerStyle(20);
  gr534_cycletempValveOpen -> SetMarkerColor(2);
  gr534_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr534_cycletempValveOpen -> Draw("Ap");

  c534_cycleNum -> cd(4);
  TGraphErrors *gr534_cyclecur = new TGraphErrors (counts_534 , cycleNumberArray534 , avecurArray534, 0, ErrcurArray534 );
  gr534_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr534_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr534_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr534_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr534_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr534_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr534_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr534_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr534_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr534_cyclecur -> SetMarkerStyle(20);
  gr534_cyclecur -> Draw("Ap");




  //*********************************
  //*********************************
  //              535
  //*********************************
  //*********************************


  TCanvas *c535_cycleNum = new TCanvas("c535_cycleNum" , "c535_cycleNum" , 1200, 800);
  c535_cycleNum -> Divide(2,2);
  TPad *p535_4 = c535_cycleNum->cd(1);
  p535_4->SetLogy(); 
  TGraphErrors *gr535_cyclecounts = new TGraphErrors (counts_535 , cycleNumberArray535, UCNCounts535, 0 , UCNCountsErr535);
  gr535_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr535_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr535_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr535_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr535_cyclehist = new TGraphErrors(counts_535, cycleNumberArray535 , HistIntegralArray535, 0, HistIntegralErrArray535);

  gr535_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr535_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr535_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr535_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr535_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr535_cyclehist -> SetMarkerColor(2);
  gr535_cyclehist -> SetMarkerStyle(20);

  gr535_cyclecounts -> Draw("Ap");
  gr535_cyclehist -> Draw("p");

  leg2-> Draw();

  c535_cycleNum -> cd(2);
 TGraphErrors *gr535_cycledelay = new TGraphErrors (counts_535 , cycleNumberArray535, delaytimeArray535, 0 , 0);
  gr535_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr535_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr535_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr535_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cycledelay -> SetMarkerStyle(20);

  gr535_cycledelay -> Draw("Ap");


  c535_cycleNum -> cd(3);

  TGraphErrors *gr535_cycletempValveOpen = new TGraphErrors (counts_535 , cycleNumberArray535, avets12ValveOpenArray535, 0 , ts12ValveOpenErr535);

  gr535_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr535_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr535_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr535_cycletempValveOpen -> SetMarkerStyle(20);
  gr535_cycletempValveOpen -> SetMarkerColor(2);
  gr535_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cycletempValveOpen -> Draw("Ap");


  c535_cycleNum -> cd(4);
  TGraphErrors *gr535_cyclecur = new TGraphErrors (counts_535 , cycleNumberArray535 , avecurArray535, 0, ErrcurArray535 );
  gr535_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr535_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr535_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr535_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr535_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr535_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr535_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr535_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr535_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr535_cyclecur -> SetMarkerStyle(20);
  gr535_cyclecur -> Draw("Ap");


  //*********************************
  //*********************************
  //              536
  //*********************************
  //*********************************

  TCanvas *c536_cycleNum = new TCanvas("c536_cycleNum" , "c536_cycleNum" , 1200, 800);
  c536_cycleNum -> Divide(2,2);
  TPad *p536_4 = c536_cycleNum->cd(1);
  p536_4->SetLogy(); 
  TGraphErrors *gr536_cyclecounts = new TGraphErrors (counts_536 , cycleNumberArray536, UCNCounts536, 0 , UCNCountsErr536);
  gr536_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr536_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr536_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr536_cyclehist = new TGraphErrors(counts_536, cycleNumberArray536 , HistIntegralArray536, 0, HistIntegralErrArray536);

  gr536_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr536_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr536_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr536_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr536_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr536_cyclehist -> SetMarkerColor(2);
  gr536_cyclehist -> SetMarkerStyle(20);

  gr536_cyclecounts -> Draw("Ap");
  gr536_cyclehist -> Draw("p");

  leg2-> Draw();

  c536_cycleNum -> cd(2);
 TGraphErrors *gr536_cycledelay = new TGraphErrors (counts_536 , cycleNumberArray536, delaytimeArray536, 0 , 0);
  gr536_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr536_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr536_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr536_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cycledelay -> SetMarkerStyle(20);

  gr536_cycledelay -> Draw("Ap");


  c536_cycleNum -> cd(3);

  TGraphErrors *gr536_cycletempValveOpen = new TGraphErrors (counts_536 , cycleNumberArray536, avets12ValveOpenArray536, 0 , ts12ValveOpenErr536);

  gr536_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr536_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr536_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr536_cycletempValveOpen -> SetMarkerStyle(20);
  gr536_cycletempValveOpen -> SetMarkerColor(2);
  gr536_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cycletempValveOpen -> Draw("Ap");


  c536_cycleNum -> cd(4);
  TGraphErrors *gr536_cyclecur = new TGraphErrors (counts_536 , cycleNumberArray536 , avecurArray536, 0, ErrcurArray536 );
  gr536_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr536_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr536_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr536_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr536_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr536_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr536_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr536_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr536_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr536_cyclecur -> SetMarkerStyle(20);
  gr536_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              537
  //*********************************
  //*********************************

  TCanvas *c537_cycleNum = new TCanvas("c537_cycleNum" , "c537_cycleNum" , 1200, 800);
  c537_cycleNum -> Divide(2,2);
  TPad *p537_4 = c537_cycleNum->cd(1);
  p537_4->SetLogy(); 
  TGraphErrors *gr537_cyclecounts = new TGraphErrors (counts_537 , cycleNumberArray537, UCNCounts537, 0 , UCNCountsErr537);
  gr537_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr537_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr537_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr537_cyclehist = new TGraphErrors(counts_537, cycleNumberArray537 , HistIntegralArray537, 0, HistIntegralErrArray537);

  gr537_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr537_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr537_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr537_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr537_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr537_cyclehist -> SetMarkerColor(2);
  gr537_cyclehist -> SetMarkerStyle(20);

  gr537_cyclecounts -> Draw("Ap");
  gr537_cyclehist -> Draw("p");

  leg2-> Draw();

  c537_cycleNum -> cd(2);
 TGraphErrors *gr537_cycledelay = new TGraphErrors (counts_537 , cycleNumberArray537, delaytimeArray537, 0 , 0);
  gr537_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr537_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr537_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr537_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cycledelay -> SetMarkerStyle(20);

  gr537_cycledelay -> Draw("Ap");


  c537_cycleNum -> cd(3);

  TGraphErrors *gr537_cycletempValveOpen = new TGraphErrors (counts_537 , cycleNumberArray537, avets12ValveOpenArray537, 0 , ts12ValveOpenErr537);

  gr537_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr537_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr537_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr537_cycletempValveOpen -> SetMarkerStyle(20);
  gr537_cycletempValveOpen -> SetMarkerColor(2);
  gr537_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr537_cycletempValveOpen -> Draw("Ap");


  c537_cycleNum -> cd(4);
  TGraphErrors *gr537_cyclecur = new TGraphErrors (counts_537 , cycleNumberArray537 , avecurArray537, 0, ErrcurArray537 );
  gr537_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr537_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr537_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr537_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr537_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr537_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr537_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr537_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr537_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr537_cyclecur -> SetMarkerStyle(20);
  gr537_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              538
  //*********************************
  //*********************************

  TCanvas *c538_cycleNum = new TCanvas("c538_cycleNum" , "c538_cycleNum" , 1200, 800);
  c538_cycleNum -> Divide(2,2);
  TPad *p538_4 = c538_cycleNum->cd(1);
  p538_4->SetLogy(); 
  TGraphErrors *gr538_cyclecounts = new TGraphErrors (counts_538 , cycleNumberArray538, UCNCounts538, 0 , UCNCountsErr538);
  gr538_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr538_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr538_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr538_cyclehist = new TGraphErrors(counts_538, cycleNumberArray538 , HistIntegralArray538, 0, HistIntegralErrArray538);

  gr538_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr538_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr538_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr538_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr538_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr538_cyclehist -> SetMarkerColor(2);
  gr538_cyclehist -> SetMarkerStyle(20);

  gr538_cyclecounts -> Draw("Ap");
  gr538_cyclehist -> Draw("p");

  leg2-> Draw();

  c538_cycleNum -> cd(2);
 TGraphErrors *gr538_cycledelay = new TGraphErrors (counts_538 , cycleNumberArray538, delaytimeArray538, 0 , 0);
  gr538_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr538_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr538_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr538_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cycledelay -> SetMarkerStyle(20);

  gr538_cycledelay -> Draw("Ap");


  c538_cycleNum -> cd(3);
  TGraphErrors *gr538_cycletempValveOpen = new TGraphErrors (counts_538 , cycleNumberArray538, avets12ValveOpenArray538, 0 , ts12ValveOpenErr538);

  gr538_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr538_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr538_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr538_cycletempValveOpen -> SetMarkerStyle(20);
  gr538_cycletempValveOpen -> SetMarkerColor(2);
  gr538_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr538_cycletempValveOpen -> Draw("Ap");


  c538_cycleNum -> cd(4);
  TGraphErrors *gr538_cyclecur = new TGraphErrors (counts_538 , cycleNumberArray538 , avecurArray538, 0, ErrcurArray538 );
  gr538_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr538_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr538_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr538_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr538_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr538_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr538_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr538_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr538_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr538_cyclecur -> SetMarkerStyle(20);
  gr538_cyclecur -> Draw("Ap");



  //*********************************
  //*********************************
  //              539
  //*********************************
  //*********************************

  TCanvas *c539_cycleNum = new TCanvas("c539_cycleNum" , "c539_cycleNum" , 1200, 800);
  c539_cycleNum -> Divide(2,2);
  TPad *p539_4 = c539_cycleNum->cd(1);
  p539_4->SetLogy(); 
  TGraphErrors *gr539_cyclecounts = new TGraphErrors (counts_539 , cycleNumberArray539, UCNCounts539, 0 , UCNCountsErr539);
  gr539_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr539_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr539_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr539_cyclehist = new TGraphErrors(counts_539, cycleNumberArray539 , HistIntegralArray539, 0, HistIntegralErrArray539);

  gr539_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr539_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr539_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr539_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr539_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr539_cyclehist -> SetMarkerColor(2);
  gr539_cyclehist -> SetMarkerStyle(20);

  gr539_cyclecounts -> Draw("Ap");
  gr539_cyclehist -> Draw("p");

  leg2-> Draw();

  c539_cycleNum -> cd(2);
 TGraphErrors *gr539_cycledelay = new TGraphErrors (counts_539 , cycleNumberArray539, delaytimeArray539, 0 , 0);
  gr539_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr539_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr539_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr539_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cycledelay -> SetMarkerStyle(20);

  gr539_cycledelay -> Draw("Ap");


  c539_cycleNum -> cd(3);

  TGraphErrors *gr539_cycletempValveOpen = new TGraphErrors (counts_539 , cycleNumberArray539, avets12ValveOpenArray539, 0 , ts12ValveOpenErr539);

  gr539_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr539_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr539_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr539_cycletempValveOpen -> SetMarkerStyle(20);
  gr539_cycletempValveOpen -> SetMarkerColor(2);
  gr539_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cycletempValveOpen -> Draw("Ap");


  c539_cycleNum -> cd(4);
  TGraphErrors *gr539_cyclecur = new TGraphErrors (counts_539 , cycleNumberArray539 , avecurArray539, 0, ErrcurArray539 );
  gr539_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr539_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr539_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr539_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr539_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr539_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr539_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr539_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr539_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr539_cyclecur -> SetMarkerStyle(20);
  gr539_cyclecur -> Draw("Ap");

 
  //*********************************
  //*********************************
  //              540
  //*********************************
  //*********************************

  TCanvas *c540_cycleNum = new TCanvas("c540_cycleNum" , "c540_cycleNum" , 1200, 800);
  c540_cycleNum -> Divide(2,2);
  TPad *p540_4 = c540_cycleNum->cd(1);
  p540_4->SetLogy(); 
  TGraphErrors *gr540_cyclecounts = new TGraphErrors (counts_540 , cycleNumberArray540, UCNCounts540, 0 , UCNCountsErr540);
  gr540_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr540_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr540_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclecounts -> SetMarkerStyle(20);


  TGraphErrors *gr540_cyclehist = new TGraphErrors(counts_540, cycleNumberArray540 , HistIntegralArray540, 0, HistIntegralErrArray540);

  gr540_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr540_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr540_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr540_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr540_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr540_cyclehist -> SetMarkerColor(2);
  gr540_cyclehist -> SetMarkerStyle(20);

  gr540_cyclecounts -> Draw("Ap");
  gr540_cyclehist -> Draw("p");

  leg2-> Draw();

  c540_cycleNum -> cd(2);
 TGraphErrors *gr540_cycledelay = new TGraphErrors (counts_540 , cycleNumberArray540, delaytimeArray540, 0 , 0);
  gr540_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr540_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr540_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr540_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cycledelay -> SetMarkerStyle(20);

  gr540_cycledelay -> Draw("Ap");


  c540_cycleNum -> cd(3);

  TGraphErrors *gr540_cycletempValveOpen = new TGraphErrors (counts_540 , cycleNumberArray540, avets12ValveOpenArray540, 0 , ts12ValveOpenErr540);

  gr540_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr540_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr540_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr540_cycletempValveOpen -> SetMarkerStyle(20);
  gr540_cycletempValveOpen -> SetMarkerColor(2);
  gr540_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr540_cycletempValveOpen -> Draw("Ap");


  c540_cycleNum -> cd(4);
  TGraphErrors *gr540_cyclecur = new TGraphErrors (counts_540 , cycleNumberArray540 , avecurArray540, 0, ErrcurArray540 );
  gr540_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr540_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr540_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr540_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr540_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr540_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr540_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr540_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr540_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr540_cyclecur -> SetMarkerStyle(20);
  gr540_cyclecur -> Draw("Ap");




  /*

  double StorageAll [100] = {storage532, storage533, storage535, storage536, storage537, storage540};
  double StorageErrAll[100] = {storageErr532, storageErr533, storageErr535, storageErr535, storageErr536, storageErr537, storageErr540};
  double runNum[100] = {532, 533, 535, 536, 537, 540};
  double tempIrradAll[100] = {aveAllts12Irrad532, aveAllts12Irrad533, aveAllts12Irrad535, aveAllts12Irrad536, aveAllts12Irrad537, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad532,  aveAllErrts12Irrad533,  aveAllErrts12Irrad534,  aveAllErrts12Irrad536,  aveAllErrts12Irrad537,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_532 +counts_533 +counts_534 +counts_535 +counts_536 +counts_537  +counts_539 +counts_540 , delayTimeAll, UCNCountsAll , 0, UCNCountsErrAll);
  
  grAll -> SetTitle("UCN Count vs cycle Delay Time ");
  grAll -> GetYaxis()-> SetTitle("UCN Count" );
  grAll -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  //grAll -> GetXaxis()-> SetLimits(0.8 ,1.3);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> Fit(fit);

  grAll -> SetMarkerStyle(20);
  grAll -> Draw("Ap");
  




}
