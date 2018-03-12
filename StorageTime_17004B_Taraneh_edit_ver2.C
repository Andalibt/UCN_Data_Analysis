//****************************************************************
// THIS FILE IS TO ANALYZE THE STORAGE LIFETIME MEASUREMENTS
// FOR TCN17004B.
//****************************************************************
#include <string>
#include <fstream>

#define max 100

void StorageTime_17004B_Taraneh_edit_ver2(){
  gStyle->SetOptFit(1111);
  gStyle->SetTitleFontSize(.07);
  gStyle->SetLabelSize(.05, "XY");
  
  TFile *fin573 = new TFile("outputTree_StorageTime_573.root","READ");
  TFile *fin574 = new TFile("outputTree_StorageTime_574.root","READ");
  TFile *fin575 = new TFile("outputTree_StorageTime_575.root","READ");
  TFile *fin576 = new TFile("outputTree_StorageTime_576.root","READ");
  TFile *fin577 = new TFile("outputTree_StorageTime_577.root","READ");
  TFile *fin578 = new TFile("outputTree_StorageTime_578.root","READ");
  TFile *fin579 = new TFile("outputTree_StorageTime_579.root","READ");
  TFile *fin580 = new TFile("outputTree_StorageTime_580.root","READ");
  TFile *fin581 = new TFile("outputTree_StorageTime_581.root","READ");


  
  TTree *outputTree573 = (TTree*) fin573 -> Get("cycle_info");
  TTree *outputTree574 = (TTree*) fin574 -> Get("cycle_info");
  TTree *outputTree575 = (TTree*) fin575 -> Get("cycle_info");
  TTree *outputTree576 = (TTree*) fin576 -> Get("cycle_info");
  TTree *outputTree577 = (TTree*) fin577 -> Get("cycle_info");
  TTree *outputTree578 = (TTree*) fin578 -> Get("cycle_info");
  TTree *outputTree579 = (TTree*) fin579 -> Get("cycle_info");
  TTree *outputTree580 = (TTree*) fin580 -> Get("cycle_info");
  TTree *outputTree581 = (TTree*) fin581 -> Get("cycle_info");
  


  // VARIABLES FOR THE TREE

  // DELAY TIME
  double cycleDelayTime573;
  double cycleDelayTime574;
  double cycleDelayTime575;
  double cycleDelayTime576;
  double cycleDelayTime577;
  double cycleDelayTime578;
  double cycleDelayTime579;
  double cycleDelayTime580;
  double cycleDelayTime581;




  outputTree573 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime573);
  outputTree574 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime574);
  outputTree575 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime575);
  outputTree576 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime576);
  outputTree577 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime577);
  outputTree578 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime578);
  outputTree579 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime579);
  outputTree580 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime580);
  outputTree581 -> SetBranchAddress ("cycleDelayTime" , &cycleDelayTime581);



  // DELAY TIME (ARRAY)
  double delaytimeArray573 [100];
  double delaytimeArray574 [100];
  double delaytimeArray575 [100];
  double delaytimeArray576 [100];
  double delaytimeArray577 [100];
  double delaytimeArray578 [100];
  double delaytimeArray579 [100];
  double delaytimeArray580 [100];
  double delaytimeArray581 [100];


  // CYCLE NUMBER
  int cycleNumber573;
  int cycleNumber574;
  int cycleNumber575;
  int cycleNumber576;
  int cycleNumber577;
  int cycleNumber578;
  int cycleNumber579;
  int cycleNumber580;
  int cycleNumber581;


  outputTree573 -> SetBranchAddress ("cycleNumber" , &cycleNumber573);
  outputTree574 -> SetBranchAddress ("cycleNumber" , &cycleNumber574);
  outputTree575 -> SetBranchAddress ("cycleNumber" , &cycleNumber575);
  outputTree576 -> SetBranchAddress ("cycleNumber" , &cycleNumber576);
  outputTree577 -> SetBranchAddress ("cycleNumber" , &cycleNumber577);
  outputTree578 -> SetBranchAddress ("cycleNumber" , &cycleNumber578);
  outputTree579 -> SetBranchAddress ("cycleNumber" , &cycleNumber579);
  outputTree580 -> SetBranchAddress ("cycleNumber" , &cycleNumber580);
  outputTree581 -> SetBranchAddress ("cycleNumber" , &cycleNumber581);



  //CYCLE NUMBER (ARRAY)
  double cycleNumberArray573 [100];
  double cycleNumberArray574 [100];
  double cycleNumberArray575 [100];
  double cycleNumberArray576 [100];
  double cycleNumberArray577 [100];
  double cycleNumberArray578 [100];
  double cycleNumberArray579 [100];
  double cycleNumberArray580 [100];
  double cycleNumberArray581 [100];




  // UCN INTEGRAL FROM THE FIT FUNCTION
  double UCNIntegral573;
  double UCNIntegral574;
  double UCNIntegral575;
  double UCNIntegral576;
  double UCNIntegral577;
  double UCNIntegral578;
  double UCNIntegral579;
  double UCNIntegral580;
  double UCNIntegral581;



  outputTree573 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral573);
  outputTree574 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral574);
  outputTree575 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral575);
  outputTree576 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral576);
  outputTree577 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral577);
  outputTree578 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral578);
  outputTree579 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral579);
  outputTree580 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral580);
  outputTree581 -> SetBranchAddress ("UCNIntegral" , &UCNIntegral581);


  // UCN INTEGRAL FROM THE FIT FUNCTION (ARRAY)
  double UCNIntegralArray573 [100];
  double UCNIntegralArray574 [100];
  double UCNIntegralArray575 [100];
  double UCNIntegralArray576 [100];
  double UCNIntegralArray577 [100];
  double UCNIntegralArray578 [100];
  double UCNIntegralArray579 [100];
  double UCNIntegralArray580 [100];
  double UCNIntegralArray581 [100];


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM
  double UCNIntegralErr573;
  double UCNIntegralErr574;
  double UCNIntegralErr575;
  double UCNIntegralErr576;
  double UCNIntegralErr577;
  double UCNIntegralErr578;
  double UCNIntegralErr579;
  double UCNIntegralErr580;
  double UCNIntegralErr581;


  outputTree573 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr573);
  outputTree574 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr574);
  outputTree575 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr575);
  outputTree576 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr576);
  outputTree577 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr577);
  outputTree578 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr578);
  outputTree579 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr579);
  outputTree580 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr580);
  outputTree581 -> SetBranchAddress ("UCNIntegralErr" , &UCNIntegralErr581);


  // THE ERROR ASSOCIATED WITH THE UCN INTEGRAL CALCULATED FROM THE FIT TO THE UCN RATE HISTOGRAM (ARRAY)
  double UCNIntegralErrArray573 [100];
  double UCNIntegralErrArray574 [100];
  double UCNIntegralErrArray575 [100];
  double UCNIntegralErrArray576 [100];
  double UCNIntegralErrArray577 [100];
  double UCNIntegralErrArray578 [100];
  double UCNIntegralErrArray579 [100];
  double UCNIntegralErrArray580 [100];
  double UCNIntegralErrArray581 [100];


  // THE UCN RATE HISTOGRAM INTEGRAL 
  double HistIntegral573;
  double HistIntegral574;
  double HistIntegral575;
  double HistIntegral576;
  double HistIntegral577;
  double HistIntegral578;
  double HistIntegral579;
  double HistIntegral580;
  double HistIntegral581;


  outputTree573 -> SetBranchAddress ("HistIntegral" , &HistIntegral573); 
  outputTree574 -> SetBranchAddress ("HistIntegral" , &HistIntegral574);
  outputTree575 -> SetBranchAddress ("HistIntegral" , &HistIntegral575);
  outputTree576 -> SetBranchAddress ("HistIntegral" , &HistIntegral576);
  outputTree577 -> SetBranchAddress ("HistIntegral" , &HistIntegral577);
  outputTree578 -> SetBranchAddress ("HistIntegral" , &HistIntegral578);
  outputTree579 -> SetBranchAddress ("HistIntegral" , &HistIntegral579);
  outputTree580 -> SetBranchAddress ("HistIntegral" , &HistIntegral580);
  outputTree581 -> SetBranchAddress ("HistIntegral" , &HistIntegral581);


  // THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralArray573 [100];
  double HistIntegralArray574 [100];
  double HistIntegralArray575 [100];
  double HistIntegralArray576 [100];
  double HistIntegralArray577 [100];
  double HistIntegralArray578 [100];
  double HistIntegralArray579 [100];
  double HistIntegralArray580 [100];
  double HistIntegralArray581 [100];


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL
  double HistIntegralErr573;
  double HistIntegralErr574;
  double HistIntegralErr575;
  double HistIntegralErr576;
  double HistIntegralErr577;
  double HistIntegralErr578;
  double HistIntegralErr579;
  double HistIntegralErr580;
  double HistIntegralErr581;


  // ERROR ASSOCIATED WITH THE UCN RATE HISTOGRAM INTEGRAL (ARRAY)
  double HistIntegralErrArray573 [100];
  double HistIntegralErrArray574 [100];
  double HistIntegralErrArray575 [100];
  double HistIntegralErrArray576 [100];
  double HistIntegralErrArray577 [100];
  double HistIntegralErrArray578 [100];
  double HistIntegralErrArray579 [100];
  double HistIntegralErrArray580 [100];
  double HistIntegralErrArray581 [100];


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME
  double avets12Irrad573;
  double avets12Irrad574;
  double avets12Irrad575;
  double avets12Irrad576;
  double avets12Irrad577;
  double avets12Irrad578;
  double avets12Irrad579;
  double avets12Irrad580;
  double avets12Irrad581;

  outputTree573 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad573);
  outputTree574 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad574);
  outputTree575 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad575);
  outputTree576 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad576);
  outputTree577 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad577);
  outputTree578 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad578);
  outputTree579 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad579);
  outputTree580 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad580);
  outputTree581 -> SetBranchAddress ("AVE_TS12_IRRAD" , &avets12Irrad581);



  // AVERAGE TS12 DURING VALVE OPEN
  double avets12ValveOpen573;
  double avets12ValveOpen574;
  double avets12ValveOpen575;
  double avets12ValveOpen576;
  double avets12ValveOpen577;
  double avets12ValveOpen578;
  double avets12ValveOpen579;
  double avets12ValveOpen580;
  double avets12ValveOpen581;


  outputTree573 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen573);
  outputTree574 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen574);
  outputTree575 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen575);
  outputTree576 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen576);
  outputTree577 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen577);
  outputTree578 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen578);
  outputTree579 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen579);
  outputTree580 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen580);
  outputTree581 -> SetBranchAddress ("AVE_TS12_VALVEOPEN" , &avets12ValveOpen581);


  // AVERAGE TS12 DURING IRRADIATION AND DELAY TIME (ARRAY)
  double avets12IrradArray573 [100];
  double avets12IrradArray574 [100];
  double avets12IrradArray575 [100];
  double avets12IrradArray576 [100];
  double avets12IrradArray577 [100];
  double avets12IrradArray578 [100];
  double avets12IrradArray579 [100];
  double avets12IrradArray580 [100];
  double avets12IrradArray581 [100];


  // AVERAGE TS12 DURING VALVE OPEN (ARRAY)
  double avets12ValveOpenArray573 [100];
  double avets12ValveOpenArray574 [100];
  double avets12ValveOpenArray575 [100];
  double avets12ValveOpenArray576 [100];
  double avets12ValveOpenArray577 [100];
  double avets12ValveOpenArray578 [100];
  double avets12ValveOpenArray579 [100];
  double avets12ValveOpenArray580 [100];
  double avets12ValveOpenArray581 [100];


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double maxts12Irrad573;
  double maxts12Irrad574;
  double maxts12Irrad575;
  double maxts12Irrad576;
  double maxts12Irrad577;
  double maxts12Irrad578;
  double maxts12Irrad579;
  double maxts12Irrad580;
  double maxts12Irrad581;

  outputTree573 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad573);
  outputTree574 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad574);
  outputTree575 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad575);
  outputTree576 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad576);
  outputTree577 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad577);
  outputTree578 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad578);
  outputTree579 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad579);
  outputTree580 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad580);
  outputTree581 -> SetBranchAddress ("MAX_TS12_IRRAD" , &maxts12Irrad581);


 // MAXIMUM TS12 DURING VALVE OPEN
  double maxts12ValveOpen573;
  double maxts12ValveOpen574;
  double maxts12ValveOpen575;
  double maxts12ValveOpen576;
  double maxts12ValveOpen577;
  double maxts12ValveOpen578;
  double maxts12ValveOpen579;
  double maxts12ValveOpen580;
  double maxts12ValveOpen581;


  outputTree573 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen573);
  outputTree574 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen574);
  outputTree575 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen575);
  outputTree576 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen576);
  outputTree577 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen577);
  outputTree578 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen578);
  outputTree579 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen579);
  outputTree580 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen580);
  outputTree581 -> SetBranchAddress ("MAX_TS12_VALVEOPEN" , &maxts12ValveOpen581);


  // MAXIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double maxts12IrradArray573 [100];
  double maxts12IrradArray574 [100];
  double maxts12IrradArray575 [100];
  double maxts12IrradArray576 [100];
  double maxts12IrradArray577 [100];
  double maxts12IrradArray578 [100];
  double maxts12IrradArray579 [100];
  double maxts12IrradArray580 [100];
  double maxts12IrradArray581 [100];

  // MAXIMUM TS12 DURING VALVE OPEN (ARRAY)
  double maxts12ValveOpenArray573 [100];
  double maxts12ValveOpenArray574 [100];
  double maxts12ValveOpenArray575 [100];
  double maxts12ValveOpenArray576 [100];
  double maxts12ValveOpenArray577 [100];
  double maxts12ValveOpenArray578 [100];
  double maxts12ValveOpenArray579 [100];
  double maxts12ValveOpenArray580 [100];
  double maxts12ValveOpenArray581 [100];

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME
  double mints12Irrad573;
  double mints12Irrad574;
  double mints12Irrad575;
  double mints12Irrad576;
  double mints12Irrad577;
  double mints12Irrad578;
  double mints12Irrad579;
  double mints12Irrad580;
  double mints12Irrad581;


  outputTree573 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad573);
  outputTree574 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad574);
  outputTree575 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad575);
  outputTree576 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad576);
  outputTree577 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad577);
  outputTree578 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad578);
  outputTree579 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad579);
  outputTree580 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad580);
  outputTree581 -> SetBranchAddress ("MIN_TS12_IRRAD" , &mints12Irrad581);

  // MINIMUM TS12 DURING VALVE OPEN
  double mints12ValveOpen573;
  double mints12ValveOpen574;
  double mints12ValveOpen575;
  double mints12ValveOpen576;
  double mints12ValveOpen577;
  double mints12ValveOpen578;
  double mints12ValveOpen579;
  double mints12ValveOpen580;
  double mints12ValveOpen581;
  
  outputTree573 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen573);
  outputTree574 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen574);
  outputTree575 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen575);
  outputTree576 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen576);
  outputTree577 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen577);
  outputTree578 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen578);
  outputTree579 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen579);
  outputTree580 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen580);
  outputTree581 -> SetBranchAddress ("MIN_TS12_VALVEOPEN" , &mints12ValveOpen581);

  // MINIMUM TS12 DURING IRRADIATION TIME AND DELAY TIME (ARRAY)
  double mints12IrradArray573 [100];
  double mints12IrradArray574 [100];
  double mints12IrradArray575 [100];
  double mints12IrradArray576 [100];
  double mints12IrradArray577 [100];
  double mints12IrradArray578 [100];
  double mints12IrradArray579 [100];
  double mints12IrradArray580 [100];
  double mints12IrradArray581 [100];

  // MINIMUM TS12 DURING VALVE OPEN (ARRAY)
  double mints12ValveOpenArray573 [100];
  double mints12ValveOpenArray574 [100];
  double mints12ValveOpenArray575 [100];
  double mints12ValveOpenArray576 [100];
  double mints12ValveOpenArray577 [100];
  double mints12ValveOpenArray578 [100];
  double mints12ValveOpenArray579 [100];
  double mints12ValveOpenArray580 [100];
  double mints12ValveOpenArray581 [100];


  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12IrradErr573 [100];
  double ts12IrradErr574 [100];
  double ts12IrradErr575 [100];
  double ts12IrradErr576 [100];
  double ts12IrradErr577 [100];
  double ts12IrradErr578 [100];
  double ts12IrradErr579 [100];
  double ts12IrradErr580 [100];
  double ts12IrradErr581 [100];

  // TEMPERATURE ERROR BAR (ARRAY)
  double ts12ValveOpenErr573 [100];
  double ts12ValveOpenErr574 [100];
  double ts12ValveOpenErr575 [100];
  double ts12ValveOpenErr576 [100];
  double ts12ValveOpenErr577 [100];
  double ts12ValveOpenErr578 [100];
  double ts12ValveOpenErr579 [100];
  double ts12ValveOpenErr580 [100];
  double ts12ValveOpenErr581 [100];


  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION
  double avecur573;
  double avecur574;
  double avecur575;
  double avecur576;
  double avecur577;
  double avecur578;
  double avecur579;
  double avecur580;
  double avecur581;

  outputTree573 -> SetBranchAddress ("AVE_PRDCUR" , &avecur573);
  outputTree574 -> SetBranchAddress ("AVE_PRDCUR" , &avecur574);
  outputTree575 -> SetBranchAddress ("AVE_PRDCUR" , &avecur575);
  outputTree576 -> SetBranchAddress ("AVE_PRDCUR" , &avecur576);
  outputTree577 -> SetBranchAddress ("AVE_PRDCUR" , &avecur577);
  outputTree578 -> SetBranchAddress ("AVE_PRDCUR" , &avecur578);
  outputTree579 -> SetBranchAddress ("AVE_PRDCUR" , &avecur579);
  outputTree580 -> SetBranchAddress ("AVE_PRDCUR" , &avecur580);
  outputTree581 -> SetBranchAddress ("AVE_PRDCUR" , &avecur581);

  // AVERAGE PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double avecurArray573 [100];
  double avecurArray574 [100];
  double avecurArray575 [100];
  double avecurArray576 [100];
  double avecurArray577 [100];
  double avecurArray578 [100];
  double avecurArray579 [100];
  double avecurArray580 [100];
  double avecurArray581 [100];

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double maxcur573;
  double maxcur574;
  double maxcur575;
  double maxcur576;
  double maxcur577;
  double maxcur578;
  double maxcur579;
  double maxcur580;
  double maxcur581;

  outputTree573 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur573);
  outputTree574 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur574);
  outputTree575 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur575);
  outputTree576 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur576);
  outputTree577 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur577);
  outputTree578 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur578);
  outputTree579 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur579);
  outputTree580 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur580);
  outputTree581 -> SetBranchAddress ("MAX_PRDCUR" , &maxcur581);

  // MAXIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double maxcurArray573 [100];
  double maxcurArray574 [100];
  double maxcurArray575 [100];
  double maxcurArray576 [100];
  double maxcurArray577 [100];
  double maxcurArray578 [100];
  double maxcurArray579 [100];
  double maxcurArray580 [100];
  double maxcurArray581 [100];

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION
  double mincur573;
  double mincur574;
  double mincur575;
  double mincur576;
  double mincur577;
  double mincur578;
  double mincur579;
  double mincur580;
  double mincur581;

  outputTree573 -> SetBranchAddress ("MIN_PRDCUR" , &mincur573);
  outputTree574 -> SetBranchAddress ("MIN_PRDCUR" , &mincur574);
  outputTree575 -> SetBranchAddress ("MIN_PRDCUR" , &mincur575);
  outputTree576 -> SetBranchAddress ("MIN_PRDCUR" , &mincur576);
  outputTree577 -> SetBranchAddress ("MIN_PRDCUR" , &mincur577);
  outputTree578 -> SetBranchAddress ("MIN_PRDCUR" , &mincur578);
  outputTree579 -> SetBranchAddress ("MIN_PRDCUR" , &mincur579);
  outputTree580 -> SetBranchAddress ("MIN_PRDCUR" , &mincur580);
  outputTree581 -> SetBranchAddress ("MIN_PRDCUR" , &mincur581);

  // MINIMUM PREDICTED BEAM CURRENT DURING IRRADTIATION (ARRAY)
  double mincurArray573 [100];
  double mincurArray574 [100];
  double mincurArray575 [100];
  double mincurArray576 [100];
  double mincurArray577 [100];
  double mincurArray578 [100];
  double mincurArray579 [100];
  double mincurArray580 [100];
  double mincurArray581 [100];

  // ERROR (MAX - MIN) OF THE PREDICTED CURRENT (ARRAY)
  double ErrcurArray573 [100];
  double ErrcurArray574 [100];
  double ErrcurArray575 [100];
  double ErrcurArray576 [100];
  double ErrcurArray577 [100];
  double ErrcurArray578 [100];
  double ErrcurArray579 [100];
  double ErrcurArray580 [100];
  double ErrcurArray581 [100];

  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT
  double Baseline573;
  double Baseline574;
  double Baseline575;
  double Baseline576;
  double Baseline577;
  double Baseline578;
  double Baseline579;
  double Baseline580;
  double Baseline581;

  outputTree573 -> SetBranchAddress ("Baseline" , &Baseline573);
  outputTree574 -> SetBranchAddress ("Baseline" , &Baseline574);
  outputTree575 -> SetBranchAddress ("Baseline" , &Baseline575);
  outputTree576 -> SetBranchAddress ("Baseline" , &Baseline576);
  outputTree577 -> SetBranchAddress ("Baseline" , &Baseline577);
  outputTree578 -> SetBranchAddress ("Baseline" , &Baseline578);
  outputTree579 -> SetBranchAddress ("Baseline" , &Baseline579);
  outputTree580 -> SetBranchAddress ("Baseline" , &Baseline580);
  outputTree581 -> SetBranchAddress ("Baseline" , &Baseline581);
  
  // BACKGROUND BEFORE IRRADIATION FROM UCN RATE FIT (ARRAY)
  double BaselineArray573 [100];
  double BaselineArray574 [100];
  double BaselineArray575 [100];
  double BaselineArray576 [100];
  double BaselineArray577 [100];
  double BaselineArray578 [100];
  double BaselineArray579 [100];
  double BaselineArray580 [100];
  double BaselineArray581 [100];

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT
  double BaselineErr573;
  double BaselineErr574;
  double BaselineErr575;
  double BaselineErr576;
  double BaselineErr577;
  double BaselineErr578;
  double BaselineErr579;
  double BaselineErr580;
  double BaselineErr581;
 
  outputTree573 -> SetBranchAddress ("BaselineErr" , &BaselineErr573);
  outputTree574 -> SetBranchAddress ("BaselineErr" , &BaselineErr574);
  outputTree575 -> SetBranchAddress ("BaselineErr" , &BaselineErr575);
  outputTree576 -> SetBranchAddress ("BaselineErr" , &BaselineErr576);
  outputTree577 -> SetBranchAddress ("BaselineErr" , &BaselineErr577);
  outputTree578 -> SetBranchAddress ("BaselineErr" , &BaselineErr578);
  outputTree579 -> SetBranchAddress ("BaselineErr" , &BaselineErr579);
  outputTree580 -> SetBranchAddress ("BaselineErr" , &BaselineErr580);
  outputTree581 -> SetBranchAddress ("BaselineErr" , &BaselineErr581);

  // BACKGROUND ERROR BEFORE IRRADIATION FROM UCN FIT (ARRAY)
  double BaselineErrArray573 [100];
  double BaselineErrArray574 [100];
  double BaselineErrArray575 [100];
  double BaselineErrArray576 [100];
  double BaselineErrArray577 [100];
  double BaselineErrArray578 [100];
  double BaselineErrArray579 [100];
  double BaselineErrArray580 [100];
  double BaselineErrArray581 [100];


  // BACKGROUND DURING IRRADIAITON FRO THE UCN RATE FIT
  double BaselineIrrad573;
  double BaselineIrrad574;
  double BaselineIrrad575;
  double BaselineIrrad576;
  double BaselineIrrad577;
  double BaselineIrrad578;
  double BaselineIrrad579;
  double BaselineIrrad580;
  double BaselineIrrad581;
 
  outputTree573 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad573);
  outputTree574 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad574);
  outputTree575 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad575);
  outputTree576 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad576);
  outputTree577 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad577);
  outputTree578 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad578);
  outputTree579 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad579);
  outputTree580 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad580);
  outputTree581 -> SetBranchAddress ("BaselineDuringIrrad" , &BaselineIrrad581);

  // BACKGROUND DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradArray573 [100];
  double BaselineIrradArray574 [100];
  double BaselineIrradArray575 [100];
  double BaselineIrradArray576 [100];
  double BaselineIrradArray577 [100];
  double BaselineIrradArray578 [100];
  double BaselineIrradArray579 [100];
  double BaselineIrradArray580 [100];
  double BaselineIrradArray581 [100];


  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT
  double BaselineIrradErr573;
  double BaselineIrradErr574;
  double BaselineIrradErr575;
  double BaselineIrradErr576;
  double BaselineIrradErr577;
  double BaselineIrradErr578;
  double BaselineIrradErr579;
  double BaselineIrradErr580;
  double BaselineIrradErr581;

  outputTree573 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr573);
  outputTree574 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr574);
  outputTree575 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr575);
  outputTree576 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr576);
  outputTree577 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr577);
  outputTree578 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr578);
  outputTree579 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr579);
  outputTree580 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr580);
  outputTree581 -> SetBranchAddress ("BaselineDuringIrradErr" , &BaselineIrradErr581);

  // BACKGROUND ERROR DURING IRRADIAITON FROM THE UCN RATE FIT (ARRAY)
  double BaselineIrradErrArray573 [100];
  double BaselineIrradErrArray574 [100];
  double BaselineIrradErrArray575 [100];
  double BaselineIrradErrArray576 [100];
  double BaselineIrradErrArray577 [100];
  double BaselineIrradErrArray578 [100];
  double BaselineIrradErrArray579 [100];
  double BaselineIrradErrArray580 [100];
  double BaselineIrradErrArray581 [100];

  // FALL TIME FROM THE UCN RATE FIT
  double FallTime573;
  double FallTime574;
  double FallTime575;
  double FallTime576;
  double FallTime577;
  double FallTime578;
  double FallTime579;
  double FallTime580;
  double FallTime581;

  outputTree573 -> SetBranchAddress ("FallTime" , &FallTime573);
  outputTree574 -> SetBranchAddress ("FallTime" , &FallTime574);
  outputTree575 -> SetBranchAddress ("FallTime" , &FallTime575);
  outputTree576 -> SetBranchAddress ("FallTime" , &FallTime576);
  outputTree577 -> SetBranchAddress ("FallTime" , &FallTime577);
  outputTree578 -> SetBranchAddress ("FallTime" , &FallTime578);
  outputTree579 -> SetBranchAddress ("FallTime" , &FallTime579);
  outputTree580 -> SetBranchAddress ("FallTime" , &FallTime580);
  outputTree581 -> SetBranchAddress ("FallTime" , &FallTime581);

  // FALL TIME FROM THE UCN RATE FIT (ARRAY)
  double FallTimeArray573 [100];
  double FallTimeArray574 [100];
  double FallTimeArray575 [100];
  double FallTimeArray576 [100];
  double FallTimeArray577 [100];
  double FallTimeArray578 [100];
  double FallTimeArray579 [100];
  double FallTimeArray580 [100];
  double FallTimeArray581 [100];

  // FALL TIME ERR FROM THE FIT TO THE UCN RATE
  double FallTimeErr573;
  double FallTimeErr574;
  double FallTimeErr575;
  double FallTimeErr576;
  double FallTimeErr577;
  double FallTimeErr578;
  double FallTimeErr579;
  double FallTimeErr580;
  double FallTimeErr581;

  outputTree573 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr573);
  outputTree574 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr574);
  outputTree575 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr575);
  outputTree576 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr576);
  outputTree577 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr577);
  outputTree578 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr578);
  outputTree579 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr579);
  outputTree580 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr580);
  outputTree581 -> SetBranchAddress ("FallTimeErr" , &FallTimeErr581);


  // FALL TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double FallTimeErrArray573 [100];
  double FallTimeErrArray574 [100];
  double FallTimeErrArray575 [100];
  double FallTimeErrArray576 [100];
  double FallTimeErrArray577 [100];
  double FallTimeErrArray578 [100];
  double FallTimeErrArray579 [100];
  double FallTimeErrArray580 [100];
  double FallTimeErrArray581 [100];
  


  // RISE TIME FROM THE UCN RATE FIT
  double RiseTime573;
  double RiseTime574;
  double RiseTime575;
  double RiseTime576;
  double RiseTime577;
  double RiseTime578;
  double RiseTime579;
  double RiseTime580;
  double RiseTime581;

  outputTree573 -> SetBranchAddress ("RiseTime" , &RiseTime573);
  outputTree574 -> SetBranchAddress ("RiseTime" , &RiseTime574);
  outputTree575 -> SetBranchAddress ("RiseTime" , &RiseTime575);
  outputTree576 -> SetBranchAddress ("RiseTime" , &RiseTime576);
  outputTree577 -> SetBranchAddress ("RiseTime" , &RiseTime577);
  outputTree578 -> SetBranchAddress ("RiseTime" , &RiseTime578);
  outputTree579 -> SetBranchAddress ("RiseTime" , &RiseTime579);
  outputTree580 -> SetBranchAddress ("RiseTime" , &RiseTime580);
  outputTree581 -> SetBranchAddress ("RiseTime" , &RiseTime581);

  // RISE TIME FROM THE UCN RATE FIT (ARRAY)
  double RiseTimeArray573 [100];
  double RiseTimeArray574 [100];
  double RiseTimeArray575 [100];
  double RiseTimeArray576 [100];
  double RiseTimeArray577 [100];
  double RiseTimeArray578 [100];
  double RiseTimeArray579 [100];
  double RiseTimeArray580 [100];
  double RiseTimeArray581 [100];

  // RISE TIME ERR FROM THE FIT TO THE UCN RATE
  double RiseTimeErr573;
  double RiseTimeErr574;
  double RiseTimeErr575;
  double RiseTimeErr576;
  double RiseTimeErr577;
  double RiseTimeErr578;
  double RiseTimeErr579;
  double RiseTimeErr580;
  double RiseTimeErr581;

  outputTree573 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr573);
  outputTree574 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr574);
  outputTree575 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr575);
  outputTree576 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr576);
  outputTree577 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr577);
  outputTree578 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr578);
  outputTree579 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr579);
  outputTree580 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr580);
  outputTree581 -> SetBranchAddress ("RiseTimeErr" , &RiseTimeErr581);


  // RISE TIME ERROR FROM THE FIT TO THE UCN RATE (ARRAY)
  double RiseTimeErrArray573 [100];
  double RiseTimeErrArray574 [100];
  double RiseTimeErrArray575 [100];
  double RiseTimeErrArray576 [100];
  double RiseTimeErrArray577 [100];
  double RiseTimeErrArray578 [100];
  double RiseTimeErrArray579 [100];
  double RiseTimeErrArray580 [100];
  double RiseTimeErrArray581 [100];


  // OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllts12Irrad573;
  double aveAllts12Irrad574;
  double aveAllts12Irrad575;
  double aveAllts12Irrad576;
  double aveAllts12Irrad577;
  double aveAllts12Irrad578;
  double aveAllts12Irrad579;
  double aveAllts12Irrad580;
  double aveAllts12Irrad581;

  //ERROR OF THE OVERALL AVERAGE OF TS12 DURING IRRADIAITON
  double aveAllErrts12Irrad573;
  double aveAllErrts12Irrad574;
  double aveAllErrts12Irrad575;
  double aveAllErrts12Irrad576;
  double aveAllErrts12Irrad577;
  double aveAllErrts12Irrad578;
  double aveAllErrts12Irrad579;
  double aveAllErrts12Irrad580;
  double aveAllErrts12Irrad581;

  // AVERAGE OF THE MAXIMUM TS12 DURING IRRADIAITON
  double maxAllts12Irrad573;
  double maxAllts12Irrad574;
  double maxAllts12Irrad575;
  double maxAllts12Irrad576;
  double maxAllts12Irrad577;
  double maxAllts12Irrad578;
  double maxAllts12Irrad579;
  double maxAllts12Irrad580;
  double maxAllts12Irrad581;
  

  // AVERAGE OF THE MINIMUM TS12 DURING IRRADIAITON
  double minAllts12Irrad573;
  double minAllts12Irrad574;
  double minAllts12Irrad575;
  double minAllts12Irrad576;
  double minAllts12Irrad577;
  double minAllts12Irrad578;
  double minAllts12Irrad579;
  double minAllts12Irrad580;
  double minAllts12Irrad581;

  // STORAGE TIME EXTRACTED FROM THE ONE EXPONENTIAL FIT
  double storage573;
  double storage574;
  double storage575;
  double storage576;
  double storage577;
  double storage578;
  double storage579;
  double storage580;
  double storage581;

  // STORAGE TIME ERR FROM THE FIT
  double storageErr573;
  double storageErr574;
  double storageErr575;
  double storageErr576;
  double storageErr577;
  double storageErr578;
  double storageErr579;
  double storageErr580;
  double storageErr581;


  // NUMBER OF COUNTS IN EACH LOOP
  int counts_573 = 0;
  int counts_574 = 0;
  int counts_575 = 0;
  int counts_576 = 0;
  int counts_577 = 0;
  int counts_578 = 0;
  int counts_579 = 0;
  int counts_580 = 0;
  int counts_581 = 0;
  
  double UCNIntegralArrayAll[100];
  double UCNIntegralErrArrayAll[100];
  double delayTimeAll[100];
  double HistIntegralArrayAll[100];
  double HistIntegralErrArrayAll[100];
  
  ULong64_t events573;
  events573 = (Double_t)outputTree573 -> GetEntries();

  for (ULong64_t j = 0 ; j < events573 ; j++){
    outputTree573 -> GetEvent(j);
    if (j == 2)
      continue;
    UCNIntegralArray573[counts_573] = UCNIntegral573;
    UCNIntegralErrArray573[counts_573] = UCNIntegralErr573;
    HistIntegralArray573[counts_573] = HistIntegral573;
    HistIntegralErrArray573[counts_573] = sqrt (HistIntegral573);
    avets12IrradArray573[counts_573] = avets12Irrad573;
    avets12ValveOpenArray573[counts_573] = avets12ValveOpen573;
    maxts12IrradArray573[counts_573] = maxts12Irrad573;
    maxts12ValveOpenArray573[counts_573] = maxts12ValveOpen573;
    mints12IrradArray573[counts_573] = mints12Irrad573; 
    mints12ValveOpenArray573[counts_573] = mints12ValveOpen573;
    ts12IrradErr573[counts_573] = maxts12Irrad573 - mints12Irrad573;
    ts12ValveOpenErr573[counts_573] = maxts12ValveOpen573 - mints12ValveOpen573;
    avecurArray573[counts_573] = avecur573;
    maxcurArray573[counts_573] = maxcur573;
    mincurArray573[counts_573] = mincur573;
    ErrcurArray573[counts_573] = maxcur573 - mincur573;
    delaytimeArray573[counts_573] = cycleDelayTime573;
    cycleNumberArray573[counts_573] = cycleNumber573;
    BaselineArray573[counts_573] = Baseline573;
    BaselineIrradArray573[counts_573] = BaselineIrrad573;
    BaselineIrradErrArray573[counts_573] = BaselineIrradErr573;
    FallTimeArray573[counts_573] = FallTime573;
    FallTimeErrArray573[counts_573] = FallTimeErr573;
    RiseTimeArray573[counts_573] = RiseTime573;
    RiseTimeErrArray573[counts_573] = RiseTimeErr573;
    aveAllts12Irrad573 += avets12Irrad573;
    maxAllts12Irrad573 += maxts12Irrad573;
    minAllts12Irrad573 += mints12Irrad573;
    UCNIntegralArrayAll[counts_573] = UCNIntegral573;
    UCNIntegralErrArrayAll[counts_573] = UCNIntegralErr573;
    delayTimeAll[counts_573] = cycleDelayTime573;
    HistIntegralArrayAll[counts_573] = HistIntegral573;
    HistIntegralErrArrayAll[counts_573] = sqrt (HistIntegral573);
    counts_573++;
  }
  aveAllts12Irrad573 = aveAllts12Irrad573/counts_573;
  maxAllts12Irrad573 = maxAllts12Irrad573/counts_573;
  minAllts12Irrad573 = minAllts12Irrad573/counts_573;
  aveAllErrts12Irrad573 = maxAllts12Irrad573 - minAllts12Irrad573;

  ULong64_t events574;
  events574 = (Double_t)outputTree574 -> GetEntries();

  for (ULong64_t j = 0 ; j < events574 ; j++){
    outputTree574 -> GetEvent(j);
    UCNIntegralArray574[j] = UCNIntegral574;
    UCNIntegralErrArray574[j] = UCNIntegralErr574;
    HistIntegralArray574[j] = HistIntegral574;
    HistIntegralErrArray574[j] = sqrt (HistIntegral574);
    avets12IrradArray574[j] = avets12Irrad574;
    avets12ValveOpenArray574[j] = avets12ValveOpen574;
    maxts12IrradArray574[j] = maxts12Irrad574;
    maxts12ValveOpenArray574[j] = maxts12ValveOpen574;
    mints12IrradArray574[j] = mints12Irrad574; 
    mints12ValveOpenArray574[j] = mints12ValveOpen574;
    ts12IrradErr574[j] = maxts12Irrad574 - mints12Irrad574;
    ts12ValveOpenErr574[j] = maxts12ValveOpen574 - mints12ValveOpen574;
    avecurArray574[j] = avecur574;
    maxcurArray574[j] = maxcur574;
    mincurArray574[j] = mincur574;
    ErrcurArray574[j] = maxcur574 - mincur574;
    delaytimeArray574[j] = cycleDelayTime574;
    cycleNumberArray574[j] = cycleNumber574;
    BaselineArray574[j] = Baseline574;
    BaselineIrradArray574[j] = BaselineIrrad574;
    BaselineIrradErrArray574[j] = BaselineIrradErr574;
    FallTimeArray574[j] = FallTime574;
    FallTimeErrArray574[j] = FallTimeErr574;
    RiseTimeArray574[j] = RiseTime574;
    RiseTimeErrArray574[j] = RiseTimeErr574;
    aveAllts12Irrad574 += avets12Irrad574;
    maxAllts12Irrad574 += maxts12Irrad574;
    minAllts12Irrad574 += mints12Irrad574;
    cout << aveAllts12Irrad574 << endl;
    UCNIntegralArrayAll[counts_573+ counts_574] = UCNIntegral574;
    UCNIntegralErrArrayAll[counts_573+ counts_574] = UCNIntegralErr574;
    delayTimeAll[counts_573+ counts_574] = cycleDelayTime574;
    HistIntegralArrayAll[counts_573 + counts_574] = HistIntegral574;
    HistIntegralErrArrayAll[counts_573+counts_574] = sqrt (HistIntegral574);
    counts_574++;
  }
  aveAllts12Irrad574 = aveAllts12Irrad574/counts_574;
  maxAllts12Irrad574 = maxAllts12Irrad574/counts_574;
  minAllts12Irrad574 = minAllts12Irrad574/counts_574;
  aveAllErrts12Irrad574 = maxAllts12Irrad574 - minAllts12Irrad574;

  ULong64_t events575;
  events575 = (Double_t)outputTree575 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events575 ; j++){
    outputTree575 -> GetEvent(j);
    UCNIntegralArray575[counts_575] = UCNIntegral575;
    UCNIntegralErrArray575[counts_575] = UCNIntegralErr575;
    HistIntegralArray575[counts_575] = HistIntegral575;
    HistIntegralErrArray575[counts_575] = sqrt (HistIntegral575);
    avets12IrradArray575[counts_575] = avets12Irrad575;
    avets12ValveOpenArray575[counts_575] = avets12ValveOpen575;
    maxts12IrradArray575[counts_575] = maxts12Irrad575;
    maxts12ValveOpenArray575[counts_575] = maxts12ValveOpen575;
    mints12IrradArray575[counts_575] = mints12Irrad575; 
    mints12ValveOpenArray575[counts_575] = mints12ValveOpen575;
    ts12IrradErr575[counts_575] = maxts12Irrad575 - mints12Irrad575;
    ts12ValveOpenErr575[counts_575] = maxts12ValveOpen575 - mints12ValveOpen575;
    avecurArray575[counts_575] = avecur575;
    maxcurArray575[counts_575] = maxcur575;
    mincurArray575[counts_575] = mincur575;
    ErrcurArray575[counts_575] = maxcur575 - mincur575;
    delaytimeArray575[counts_575] = cycleDelayTime575;
    cycleNumberArray575[counts_575] = cycleNumber575;
    BaselineArray575[counts_575] = Baseline575;
    BaselineIrradArray575[counts_575] = BaselineIrrad575;
    BaselineIrradErrArray575[counts_575] = BaselineIrradErr575;
    FallTimeArray575[counts_575] = FallTime575;
    FallTimeErrArray575[counts_575] = FallTimeErr575;
    RiseTimeArray575[counts_575] = RiseTime575;
    RiseTimeErrArray575[counts_575] = RiseTimeErr575;
    aveAllts12Irrad575 += avets12Irrad575;
    maxAllts12Irrad575 += maxts12Irrad575;
    minAllts12Irrad575 += mints12Irrad575;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575] = UCNIntegral575;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575] = UCNIntegralErr575;
    delayTimeAll[counts_573+ counts_574+counts_575] = cycleDelayTime575;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575] = HistIntegral575;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575] = sqrt (HistIntegral575);
    counts_575++;
  }
  aveAllts12Irrad575 = aveAllts12Irrad575/counts_575;
  maxAllts12Irrad575 = maxAllts12Irrad575/counts_575;
  minAllts12Irrad575 = minAllts12Irrad575/counts_575;
  aveAllErrts12Irrad575 = maxAllts12Irrad575 - minAllts12Irrad575;
  
  ULong64_t events576;
  events576 = (Double_t)outputTree576 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events576 ; j++){
    outputTree576 -> GetEvent(j);
    UCNIntegralArray576[j] = UCNIntegral576;
    UCNIntegralErrArray576[j] = UCNIntegralErr576;
    HistIntegralArray576[j] = HistIntegral576;
    HistIntegralErrArray576[j] = sqrt (HistIntegral576);
    avets12IrradArray576[j] = avets12Irrad576;
    avets12ValveOpenArray576[j] = avets12ValveOpen576;
    maxts12IrradArray576[j] = maxts12Irrad576;
    maxts12ValveOpenArray576[j] = maxts12ValveOpen576;
    mints12IrradArray576[j] = mints12Irrad576; 
    mints12ValveOpenArray576[j] = mints12ValveOpen576;
    ts12IrradErr576[j] = maxts12Irrad576 - mints12Irrad576;
    ts12ValveOpenErr576[j] = maxts12ValveOpen576 - mints12ValveOpen576;
    avecurArray576[j] = avecur576;
    maxcurArray576[j] = maxcur576;
    mincurArray576[j] = mincur576;
    ErrcurArray576[j] = maxcur576 - mincur576;
    delaytimeArray576[j] = cycleDelayTime576;
    cycleNumberArray576[j] = cycleNumber576;
    BaselineArray576[j] = Baseline576;
    BaselineIrradArray576[j] = BaselineIrrad576;
    BaselineIrradErrArray576[j] = BaselineIrradErr576;
    FallTimeArray576[j] = FallTime576;
    FallTimeErrArray576[j] = FallTimeErr576;
    RiseTimeArray576[j] = RiseTime576;
    RiseTimeErrArray576[j] = RiseTimeErr576;
    aveAllts12Irrad576 += avets12Irrad576;
    maxAllts12Irrad576 += maxts12Irrad576;
    minAllts12Irrad576 += mints12Irrad576;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576] = UCNIntegral576;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576] = UCNIntegralErr576;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576] = cycleDelayTime576;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576] = HistIntegral576;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576] = sqrt (HistIntegral576);
    counts_576++;
  }
  aveAllts12Irrad576 = aveAllts12Irrad576/counts_576;
  maxAllts12Irrad576 = maxAllts12Irrad576/counts_576;
  minAllts12Irrad576 = minAllts12Irrad576/counts_576;
  aveAllErrts12Irrad576 = maxAllts12Irrad576 - minAllts12Irrad576;
  
  ULong64_t events577;
  events577 = (Double_t)outputTree577 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events577 ; j++){
    outputTree577 -> GetEvent(j);
    UCNIntegralArray577[counts_577] = UCNIntegral577;
    UCNIntegralErrArray577[counts_577] = UCNIntegralErr577;
    HistIntegralArray577[counts_577] = HistIntegral577;
    HistIntegralErrArray577[counts_577] = sqrt (HistIntegral577);
    avets12IrradArray577[counts_577] = avets12Irrad577;
    avets12ValveOpenArray577[counts_577] = avets12ValveOpen577;
    maxts12IrradArray577[counts_577] = maxts12Irrad577;
    maxts12ValveOpenArray577[counts_577] = maxts12ValveOpen577;
    mints12IrradArray577[counts_577] = mints12Irrad577; 
    mints12ValveOpenArray577[counts_577] = mints12ValveOpen577;
    ts12IrradErr577[counts_577] = maxts12Irrad577 - mints12Irrad577;
    ts12ValveOpenErr577[counts_577] = maxts12ValveOpen577 - mints12ValveOpen577;
    avecurArray577[counts_577] = avecur577;
    maxcurArray577[counts_577] = maxcur577;
    mincurArray577[counts_577] = mincur577;
    ErrcurArray577[counts_577] = maxcur577 - mincur577;
    delaytimeArray577[counts_577] = cycleDelayTime577;
    cycleNumberArray577[counts_577] = cycleNumber577;
    BaselineArray577[counts_577] = Baseline577;
    BaselineIrradArray577[counts_577] = BaselineIrrad577;
    BaselineIrradErrArray577[counts_577] = BaselineIrradErr577;
    FallTimeArray577[counts_577] = FallTime577;
    FallTimeErrArray577[counts_577] = FallTimeErr577;
    RiseTimeArray577[counts_577] = RiseTime577;
    RiseTimeErrArray577[counts_577] = RiseTimeErr577;
    aveAllts12Irrad577 += avets12Irrad577;
    maxAllts12Irrad577 += maxts12Irrad577;
    minAllts12Irrad577 += mints12Irrad577;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577] = UCNIntegral577;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577] = UCNIntegralErr577;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576+ counts_577] = cycleDelayTime577;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576+counts_577] = HistIntegral577;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576+counts_577] = sqrt (HistIntegral577);
    counts_577++;
  }
  aveAllts12Irrad577 = aveAllts12Irrad577/counts_577;
  maxAllts12Irrad577 = maxAllts12Irrad577/counts_577;
  minAllts12Irrad577 = minAllts12Irrad577/counts_577;
  aveAllErrts12Irrad577 = maxAllts12Irrad577 - minAllts12Irrad577;
  
  ULong64_t events578;
  events578 = (Double_t)outputTree578 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events578 ; j++){
    outputTree578 -> GetEvent(j);
    UCNIntegralArray578[counts_578] = UCNIntegral578;
    UCNIntegralErrArray578[counts_578] = UCNIntegralErr578;
    HistIntegralArray578[counts_578] = HistIntegral578;
    HistIntegralErrArray578[counts_578] = sqrt (HistIntegral578);
    avets12IrradArray578[counts_578] = avets12Irrad578;
    avets12ValveOpenArray578[counts_578] = avets12ValveOpen578;
    maxts12IrradArray578[counts_578] = maxts12Irrad578;
    maxts12ValveOpenArray578[counts_578] = maxts12ValveOpen578;
    mints12IrradArray578[counts_578] = mints12Irrad578; 
    mints12ValveOpenArray578[counts_578] = mints12ValveOpen578;
    ts12IrradErr578[counts_578] = maxts12Irrad578 - mints12Irrad578;
    ts12ValveOpenErr578[counts_578] = maxts12ValveOpen578 - mints12ValveOpen578;
    avecurArray578[counts_578] = avecur578;
    maxcurArray578[counts_578] = maxcur578;
    mincurArray578[counts_578] = mincur578;
    ErrcurArray578[counts_578] = maxcur578 - mincur578;
    delaytimeArray578[counts_578] = cycleDelayTime578;
    cycleNumberArray578[counts_578] = cycleNumber578;
    BaselineArray578[counts_578] = Baseline578;
    BaselineIrradArray578[counts_578] = BaselineIrrad578;
    BaselineIrradErrArray578[counts_578] = BaselineIrradErr578;
    FallTimeArray578[counts_578] = FallTime578;
    FallTimeErrArray578[counts_578] = FallTimeErr578;
    RiseTimeArray578[counts_578] = RiseTime578;
    RiseTimeErrArray578[counts_578] = RiseTimeErr578;
    aveAllts12Irrad578 += avets12Irrad578;
    maxAllts12Irrad578 += maxts12Irrad578;
    minAllts12Irrad578 += mints12Irrad578;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577 + counts_578] = UCNIntegral578;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577+counts_578] = UCNIntegralErr578;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576+ counts_577+counts_578] = cycleDelayTime578;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576+counts_577+counts_578] = HistIntegral578;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576+counts_577+counts_578] = sqrt (HistIntegral578);
    counts_578++;
  }
  aveAllts12Irrad578 = aveAllts12Irrad578/counts_578;
  maxAllts12Irrad578 = maxAllts12Irrad578/counts_578;
  minAllts12Irrad578 = minAllts12Irrad578/counts_578;
  aveAllErrts12Irrad578 = maxAllts12Irrad578 - minAllts12Irrad578;




  ULong64_t events579;
  events579 = (Double_t)outputTree579 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events579 ; j++){
    outputTree579 -> GetEvent(j);
    UCNIntegralArray579[counts_579] = UCNIntegral579;
    UCNIntegralErrArray579[counts_579] = UCNIntegralErr579;
    HistIntegralArray579[counts_579] = HistIntegral579;
    HistIntegralErrArray579[counts_579] = sqrt (HistIntegral579);
    avets12IrradArray579[counts_579] = avets12Irrad579;
    avets12ValveOpenArray579[counts_579] = avets12ValveOpen579;
    maxts12IrradArray579[counts_579] = maxts12Irrad579;
    maxts12ValveOpenArray579[counts_579] = maxts12ValveOpen579;
    mints12IrradArray579[counts_579] = mints12Irrad579; 
    mints12ValveOpenArray579[counts_579] = mints12ValveOpen579;
    ts12IrradErr579[counts_579] = maxts12Irrad579 - mints12Irrad579;
    ts12ValveOpenErr579[counts_579] = maxts12ValveOpen579 - mints12ValveOpen579;
    avecurArray579[counts_579] = avecur579;
    maxcurArray579[counts_579] = maxcur579;
    mincurArray579[counts_579] = mincur579;
    ErrcurArray579[counts_579] = maxcur579 - mincur579;
    delaytimeArray579[counts_579] = cycleDelayTime579;
    cycleNumberArray579[counts_579] = cycleNumber579;
    BaselineArray579[counts_579] = Baseline579;
    BaselineIrradArray579[counts_579] = BaselineIrrad579;
    BaselineIrradErrArray579[counts_579] = BaselineIrradErr579;
    FallTimeArray579[counts_579] = FallTime579;
    FallTimeErrArray579[counts_579] = FallTimeErr579;
    RiseTimeArray579[counts_579] = RiseTime579;
    RiseTimeErrArray579[counts_579] = RiseTimeErr579;
    aveAllts12Irrad579 += avets12Irrad579;
    maxAllts12Irrad579 += maxts12Irrad579;
    minAllts12Irrad579 += mints12Irrad579;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577 + counts_578+counts_579] = UCNIntegral579;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577+ counts_578+ counts_579] = UCNIntegralErr579;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576+ counts_577+ counts_578+ counts_579] = cycleDelayTime579;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576+counts_577+ counts_578+ counts_579] = HistIntegral579;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576+counts_577+ counts_578+ counts_579] = sqrt (HistIntegral579);
    counts_579++;
  }
  aveAllts12Irrad579 = aveAllts12Irrad579/counts_579;
  maxAllts12Irrad579 = maxAllts12Irrad579/counts_579;
  minAllts12Irrad579 = minAllts12Irrad579/counts_579;
  aveAllErrts12Irrad579 = maxAllts12Irrad579 - minAllts12Irrad579;




  ULong64_t events580;
  events580 = (Double_t)outputTree580 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events580 ; j++){
    outputTree580 -> GetEvent(j);
    UCNIntegralArray580[counts_580] = UCNIntegral580;
    UCNIntegralErrArray580[counts_580] = UCNIntegralErr580;
    HistIntegralArray580[counts_580] = HistIntegral580;
    HistIntegralErrArray580[counts_580] = sqrt (HistIntegral580);
    avets12IrradArray580[counts_580] = avets12Irrad580;
    avets12ValveOpenArray580[counts_580] = avets12ValveOpen580;
    maxts12IrradArray580[counts_580] = maxts12Irrad580;
    maxts12ValveOpenArray580[counts_580] = maxts12ValveOpen580;
    mints12IrradArray580[counts_580] = mints12Irrad580; 
    mints12ValveOpenArray580[counts_580] = mints12ValveOpen580;
    ts12IrradErr580[counts_580] = maxts12Irrad580 - mints12Irrad580;
    ts12ValveOpenErr580[counts_580] = maxts12ValveOpen580 - mints12ValveOpen580;
    avecurArray580[counts_580] = avecur580;
    maxcurArray580[counts_580] = maxcur580;
    mincurArray580[counts_580] = mincur580;
    ErrcurArray580[counts_580] = maxcur580 - mincur580;
    delaytimeArray580[counts_580] = cycleDelayTime580;
    cycleNumberArray580[counts_580] = cycleNumber580;
    BaselineArray580[counts_580] = Baseline580;
    BaselineIrradArray580[counts_580] = BaselineIrrad580;
    BaselineIrradErrArray580[counts_580] = BaselineIrradErr580;
    FallTimeArray580[counts_580] = FallTime580;
    FallTimeErrArray580[counts_580] = FallTimeErr580;
    RiseTimeArray580[counts_580] = RiseTime580;
    RiseTimeErrArray580[counts_580] = RiseTimeErr580;
    aveAllts12Irrad580 += avets12Irrad580;
    maxAllts12Irrad580 += maxts12Irrad580;
    minAllts12Irrad580 += mints12Irrad580;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577 + counts_578+counts_579+counts_580] = UCNIntegral580;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577+counts_578+counts_579+counts_580] = UCNIntegralErr580;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576+ counts_577+counts_578+counts_579+counts_580] = cycleDelayTime580;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576+counts_577+counts_578+counts_579+counts_580] = HistIntegral580;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576+counts_577+counts_578+counts_579+counts_580] = sqrt (HistIntegral580);
    counts_580++;
  }
  aveAllts12Irrad580 = aveAllts12Irrad580/counts_580;
  maxAllts12Irrad580 = maxAllts12Irrad580/counts_580;
  minAllts12Irrad580 = minAllts12Irrad580/counts_580;
  aveAllErrts12Irrad580 = maxAllts12Irrad580 - minAllts12Irrad580;



  ULong64_t events581;
  events581 = (Double_t)outputTree581 -> GetEntries();
  
  for (ULong64_t j = 0 ; j < events581 ; j++){
    outputTree581 -> GetEvent(j);
    UCNIntegralArray581[counts_581] = UCNIntegral581;
    UCNIntegralErrArray581[counts_581] = UCNIntegralErr581;
    HistIntegralArray581[counts_581] = HistIntegral581;
    HistIntegralErrArray581[counts_581] = sqrt (HistIntegral581);
    avets12IrradArray581[counts_581] = avets12Irrad581;
    avets12ValveOpenArray581[counts_581] = avets12ValveOpen581;
    maxts12IrradArray581[counts_581] = maxts12Irrad581;
    maxts12ValveOpenArray581[counts_581] = maxts12ValveOpen581;
    mints12IrradArray581[counts_581] = mints12Irrad581; 
    mints12ValveOpenArray581[counts_581] = mints12ValveOpen581;
    ts12IrradErr581[counts_581] = maxts12Irrad581 - mints12Irrad581;
    ts12ValveOpenErr581[counts_581] = maxts12ValveOpen581 - mints12ValveOpen581;
    avecurArray581[counts_581] = avecur581;
    maxcurArray581[counts_581] = maxcur581;
    mincurArray581[counts_581] = mincur581;
    ErrcurArray581[counts_581] = maxcur581 - mincur581;
    delaytimeArray581[counts_581] = cycleDelayTime581;
    cycleNumberArray581[counts_581] = cycleNumber581;
    BaselineArray581[counts_581] = Baseline581;
    BaselineIrradArray581[counts_581] = BaselineIrrad581;
    BaselineIrradErrArray581[counts_581] = BaselineIrradErr581;
    FallTimeArray581[counts_581] = FallTime581;
    FallTimeErrArray581[counts_581] = FallTimeErr581;
    RiseTimeArray581[counts_581] = RiseTime581;
    RiseTimeErrArray581[counts_581] = RiseTimeErr581;
    aveAllts12Irrad581 += avets12Irrad581;
    maxAllts12Irrad581 += maxts12Irrad581;
    minAllts12Irrad581 += mints12Irrad581;
    UCNIntegralArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577 + counts_578+counts_579+counts_580+counts_581] = UCNIntegral581;
    UCNIntegralErrArrayAll[counts_573+ counts_574+counts_575+counts_576 + counts_577+ counts_578+ counts_579+counts_580+counts_581] = UCNIntegralErr581;
    delayTimeAll[counts_573+ counts_574+counts_575+counts_576+ counts_577+ counts_578+counts_579+counts_580+ counts_581] = cycleDelayTime581;
    HistIntegralArrayAll[counts_573 + counts_574+ counts_575+ counts_576+counts_577+ counts_578+counts_579+counts_580+ counts_581] = HistIntegral581;
    HistIntegralErrArrayAll[counts_573+counts_574+counts_575+counts_576+counts_577+ counts_578+counts_579+counts_580+ counts_581] = sqrt (HistIntegral581);
    counts_581++;
  }
  aveAllts12Irrad581 = aveAllts12Irrad581/counts_581;
  maxAllts12Irrad581 = maxAllts12Irrad581/counts_581;
  minAllts12Irrad581 = minAllts12Irrad581/counts_581;
  aveAllErrts12Irrad581 = maxAllts12Irrad581 - minAllts12Irrad581;



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
  //              573
  //*********************************
  //*********************************
  TCanvas *c573 = new TCanvas("c573" , "c573" , 1200, 800);
  c573 -> Divide(2,2);
  //c573 -> cd(1);
  TPad *p1 = c573->cd(1);
  p1->SetLogy(); 
  TGraphErrors *gr573_delaycounts = new TGraphErrors(counts_573, delaytimeArray573 , UCNIntegralArray573, 0, UCNIntegralErrArray573);

  gr573_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr573_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr573_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_delaycounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr573_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr573_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_delaycounts -> SetMarkerStyle(7);
  gr573_delaycounts -> Fit(fit);
  storage573 = fit -> GetParameter(1);
  storageErr573 = fit -> GetParError(1);
  
  TGraphErrors *gr573_delayhist = new TGraphErrors(counts_573, delaytimeArray573 , HistIntegralArray573, 0, HistIntegralErrArray573);

  gr573_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr573_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr573_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_delayhist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr573_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr573_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr573_delayhist -> SetMarkerColor(2);
  gr573_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr573_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr573_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr573_delaycounts -> Draw("Ap");
  gr573_delayhist -> Draw("p");
  leg2 -> Draw();

  //c573 -> cd(2);
  TPad *p2 = c573->cd(2);
  p2->SetLogy(); 
  TGraphErrors *gr573_tempIrradcounts = new TGraphErrors (counts_573 , avets12IrradArray573, UCNIntegralArray573 , ts12IrradErr573 , UCNIntegralErrArray573);
  gr573_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr573_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr573_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_tempIrradcounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr573_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr573_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr573_tempValveOpencounts = new TGraphErrors (counts_573 , avets12ValveOpenArray573, UCNIntegralArray573 , ts12ValveOpenErr573 , UCNIntegralErrArray573);
  gr573_tempValveOpencounts -> SetMarkerStyle(7);
  gr573_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr573_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr573_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr573_tempIrradcounts -> Draw("Ap");
  gr573_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c573 -> cd(3);
  TGraphErrors *gr573_delaytempIrrad = new TGraphErrors (counts_573 , delaytimeArray573, avets12IrradArray573, 0 , ts12IrradErr573);

  gr573_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr573_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr573_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr573_delaytempIrrad -> SetMarkerStyle(7);
  gr573_delaytempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.9);
  gr573_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr573_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr573_delaytempValveOpen = new TGraphErrors (counts_573 , delaytimeArray573, avets12ValveOpenArray573, 0 , ts12ValveOpenErr573);

  gr573_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr573_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr573_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr573_delaytempValveOpen -> SetMarkerStyle(7);
  gr573_delaytempValveOpen -> SetMarkerColor(2);
  gr573_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr573_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr573_delaytempIrrad -> Draw("AP");
  gr573_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p4 = c573->cd(4);
  p4->SetLogy(); 
  TGraphErrors *gr573_curcounts = new TGraphErrors (counts_573 , avecurArray573, UCNIntegralArray573 , ErrcurArray573 , UCNIntegralErrArray573);
  gr573_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr573_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr573_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr573_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr573_curhist = new TGraphErrors (counts_573 , avecurArray573, UCNIntegralArray573 , ErrcurArray573 , UCNIntegralErrArray573);
  gr573_curhist -> SetTitle("UCN Counts vs Avqerage Beam Current");
  gr573_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr573_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr573_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr573_curhist -> SetMarkerColor(2);
  gr573_curhist -> SetMarkerStyle(7);

  gr573_curcounts -> Draw("Ap");
  gr573_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c573_cycleNum = new TCanvas("c573_cycleNum" , "c573_cycleNum" , 1200, 800);
  c573_cycleNum -> Divide(2,2);
  TPad *p5 = c573_cycleNum->cd(1);
  p5->SetLogy(); 
  TGraphErrors *gr573_cyclecounts = new TGraphErrors (counts_573 , cycleNumberArray573, UCNIntegralArray573, 0 , UCNIntegralErrArray573);
  gr573_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr573_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr573_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr573_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr573_cyclehist = new TGraphErrors(counts_573, cycleNumberArray573 , HistIntegralArray573, 0, HistIntegralErrArray573);

  gr573_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr573_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr573_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr573_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr573_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr573_cyclehist -> SetMarkerColor(2);
  gr573_cyclehist -> SetMarkerStyle(7);

  gr573_cyclecounts -> Draw("Ap");
  gr573_cyclehist -> Draw("p");

  leg2-> Draw();

  c573_cycleNum -> cd(2);
 TGraphErrors *gr573_cycledelay = new TGraphErrors (counts_573 , cycleNumberArray573, delaytimeArray573, 0 , 0);
  gr573_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr573_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr573_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr573_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cycledelay -> SetMarkerStyle(7);

  gr573_cycledelay -> Draw("Ap");


  c573_cycleNum -> cd(3);
  TGraphErrors *gr573_cycletempIrrad = new TGraphErrors (counts_573 , cycleNumberArray573, avets12IrradArray573, 0 , ts12IrradErr573);

  gr573_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr573_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr573_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr573_cycletempIrrad -> SetMarkerStyle(7);
  gr573_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.84, 1.1);
  gr573_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr573_cycletempValveOpen = new TGraphErrors (counts_573 , cycleNumberArray573, avets12ValveOpenArray573, 0 , ts12ValveOpenErr573);

  gr573_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr573_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr573_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr573_cycletempValveOpen -> SetMarkerStyle(7);
  gr573_cycletempValveOpen -> SetMarkerColor(2);
  gr573_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr573_cycletempIrrad -> Draw("AP");
  gr573_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c573_cycleNum -> cd(4);
  TGraphErrors *gr573_cyclecur = new TGraphErrors (counts_573 , cycleNumberArray573 , avecurArray573, 0, ErrcurArray573 );
  gr573_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr573_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr573_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr573_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclecur -> SetMarkerStyle(7);
  gr573_cyclecur -> Draw("Ap");


  TCanvas *c573_cycleNumFit = new TCanvas("c573_cycleNumFit" , "c573_cycleNumFit" , 1200, 800);
  c573_cycleNumFit -> Divide(2,2);

  c573_cycleNumFit -> cd(1);
  TGraphErrors *gr573_cyclefall = new TGraphErrors (counts_573, cycleNumberArray573, FallTimeArray573 , 0, FallTimeErrArray573);

  gr573_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr573_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr573_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr573_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclefall -> SetMarkerStyle(7);
  gr573_cyclefall -> Draw("Ap");


  c573_cycleNumFit -> cd(2);
  TGraphErrors *gr573_cyclebaseline = new TGraphErrors (counts_573, cycleNumberArray573, BaselineArray573 , 0, BaselineErrArray573);

  gr573_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr573_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr573_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr573_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclebaseline -> SetMarkerStyle(7);
  gr573_cyclebaseline -> Draw("Ap");

  c573_cycleNumFit -> cd(3);
  TGraphErrors *gr573_cyclebaselineirrad = new TGraphErrors (counts_573, cycleNumberArray573, BaselineIrradArray573 , 0, BaselineIrradErrArray573);

  gr573_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr573_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr573_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr573_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclebaselineirrad -> SetMarkerStyle(7);
  gr573_cyclebaselineirrad -> Draw("Ap");

  c573_cycleNumFit -> cd(4);
  TGraphErrors *gr573_cyclerise = new TGraphErrors (counts_573, cycleNumberArray573, RiseTimeArray573 , 0, RiseTimeErrArray573);

  gr573_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr573_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr573_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr573_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr573_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr573_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr573_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr573_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr573_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr573_cyclerise -> SetMarkerStyle(7);
  gr573_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              574
  //*********************************
  //*********************************
  TCanvas *c574 = new TCanvas("c574" , "c574" , 1200, 800);
  c574 -> Divide(2,2);
  //c574 -> cd(1);
  TPad *p574_1 = c574->cd(1);
  p574_1->SetLogy(); 
  TGraphErrors *gr574_delaycounts = new TGraphErrors(counts_574, delaytimeArray574 , UCNIntegralArray574, 0, UCNIntegralErrArray574);

  gr574_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr574_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr574_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr574_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr574_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_delaycounts -> SetMarkerStyle(7);
  gr574_delaycounts -> Fit(fit);
  storage574 = fit -> GetParameter(1);
  storageErr574 = fit -> GetParError(1);
  
  TGraphErrors *gr574_delayhist = new TGraphErrors(counts_574, delaytimeArray574 , HistIntegralArray574, 0, HistIntegralErrArray574);

  gr574_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr574_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr574_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr574_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr574_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr574_delayhist -> SetMarkerColor(2);
  gr574_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr574_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr574_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr574_delaycounts -> Draw("Ap");
  gr574_delayhist -> Draw("p");
  leg2 -> Draw();

  //c574 -> cd(2);
  TPad *p574_2 = c574->cd(2);
  p574_2->SetLogy(); 
  TGraphErrors *gr574_tempIrradcounts = new TGraphErrors (counts_574 , avets12IrradArray574, UCNIntegralArray574 , ts12IrradErr574 , UCNIntegralErrArray574);
  gr574_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr574_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr574_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr574_tempIrradcounts -> GetXaxis()-> SetLimits(0.8 ,1.3);
  gr574_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr574_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr574_tempValveOpencounts = new TGraphErrors (counts_574 , avets12ValveOpenArray574, UCNIntegralArray574 , ts12ValveOpenErr574 , UCNIntegralErrArray574);
  gr574_tempValveOpencounts -> SetMarkerStyle(7);
  gr574_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr574_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr574_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr574_tempIrradcounts -> Draw("Ap");
  gr574_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c574 -> cd(3);
  TGraphErrors *gr574_delaytempIrrad = new TGraphErrors (counts_574 , delaytimeArray574, avets12IrradArray574, 0 , ts12IrradErr574);

  gr574_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr574_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr574_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr574_delaytempIrrad -> SetMarkerStyle(7);
  gr574_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr574_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr574_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr574_delaytempValveOpen = new TGraphErrors (counts_574 , delaytimeArray574, avets12ValveOpenArray574, 0 , ts12ValveOpenErr574);

  gr574_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr574_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr574_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr574_delaytempValveOpen -> SetMarkerStyle(7);
  gr574_delaytempValveOpen -> SetMarkerColor(2);
  gr574_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr574_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr574_delaytempIrrad -> Draw("AP");
  gr574_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p574_3 = c574->cd(4);
  p574_3->SetLogy(); 
  TGraphErrors *gr574_curcounts = new TGraphErrors (counts_574 , avecurArray574, UCNIntegralArray574 , ErrcurArray574 , UCNIntegralErrArray574);
  gr574_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr574_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr574_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr574_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr574_curhist = new TGraphErrors (counts_574 , avecurArray574, UCNIntegralArray574 , ErrcurArray574 , UCNIntegralErrArray574);
  gr574_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr574_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr574_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr574_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr574_curhist -> SetMarkerColor(2);
  gr574_curhist -> SetMarkerStyle(7);

  gr574_curcounts -> Draw("Ap");
  gr574_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c574_cycleNum = new TCanvas("c574_cycleNum" , "c574_cycleNum" , 1200, 800);
  c574_cycleNum -> Divide(2,2);
  TPad *p574_4 = c574_cycleNum->cd(1);
  p574_4->SetLogy(); 
  TGraphErrors *gr574_cyclecounts = new TGraphErrors (counts_574 , cycleNumberArray574, UCNIntegralArray574, 0 , UCNIntegralErrArray574);
  gr574_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr574_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr574_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr574_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr574_cyclehist = new TGraphErrors(counts_574, cycleNumberArray574 , HistIntegralArray574, 0, HistIntegralErrArray574);

  gr574_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr574_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr574_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr574_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr574_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr574_cyclehist -> SetMarkerColor(2);
  gr574_cyclehist -> SetMarkerStyle(7);

  gr574_cyclecounts -> Draw("Ap");
  gr574_cyclehist -> Draw("p");

  leg2-> Draw();

  c574_cycleNum -> cd(2);
 TGraphErrors *gr574_cycledelay = new TGraphErrors (counts_574 , cycleNumberArray574, delaytimeArray574, 0 , 0);
  gr574_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr574_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr574_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr574_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cycledelay -> SetMarkerStyle(7);

  gr574_cycledelay -> Draw("Ap");


  c574_cycleNum -> cd(3);
  TGraphErrors *gr574_cycletempIrrad = new TGraphErrors (counts_574 , cycleNumberArray574, avets12IrradArray574, 0 , ts12IrradErr574);

  gr574_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr574_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr574_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr574_cycletempIrrad -> SetMarkerStyle(7);
  gr574_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.8, 1.2);
  gr574_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr574_cycletempValveOpen = new TGraphErrors (counts_574 , cycleNumberArray574, avets12ValveOpenArray574, 0 , ts12ValveOpenErr574);

  gr574_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr574_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr574_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr574_cycletempValveOpen -> SetMarkerStyle(7);
  gr574_cycletempValveOpen -> SetMarkerColor(2);
  gr574_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr574_cycletempIrrad -> Draw("AP");
  gr574_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c574_cycleNum -> cd(4);
  TGraphErrors *gr574_cyclecur = new TGraphErrors (counts_574 , cycleNumberArray574 , avecurArray574, 0, ErrcurArray574 );
  gr574_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr574_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr574_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr574_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclecur -> SetMarkerStyle(7);
  gr574_cyclecur -> Draw("Ap");


  TCanvas *c574_cycleNumFit = new TCanvas("c574_cycleNumFit" , "c574_cycleNumFit" , 1200, 800);
  c574_cycleNumFit -> Divide(2,2);

  c574_cycleNumFit -> cd(1);
  TGraphErrors *gr574_cyclefall = new TGraphErrors (counts_574, cycleNumberArray574, FallTimeArray574 , 0, FallTimeErrArray574);

  gr574_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr574_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr574_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr574_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclefall -> SetMarkerStyle(7);
  gr574_cyclefall -> Draw("Ap");


  c574_cycleNumFit -> cd(2);
  TGraphErrors *gr574_cyclebaseline = new TGraphErrors (counts_574, cycleNumberArray574, BaselineArray574 , 0, BaselineErrArray574);

  gr574_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr574_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr574_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr574_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclebaseline -> SetMarkerStyle(7);
  gr574_cyclebaseline -> Draw("Ap");

  c574_cycleNumFit -> cd(3);
  TGraphErrors *gr574_cyclebaselineirrad = new TGraphErrors (counts_574, cycleNumberArray574, BaselineIrradArray574 , 0, BaselineIrradErrArray574);

  gr574_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr574_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr574_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr574_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclebaselineirrad -> SetMarkerStyle(7);
  gr574_cyclebaselineirrad -> Draw("Ap");

  c574_cycleNumFit -> cd(4);
  TGraphErrors *gr574_cyclerise = new TGraphErrors (counts_574, cycleNumberArray574, RiseTimeArray574 , 0, RiseTimeErrArray574);

  gr574_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr574_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr574_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr574_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr574_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr574_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr574_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr574_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr574_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr574_cyclerise -> SetMarkerStyle(7);
  gr574_cyclerise -> Draw("Ap");



  //*********************************
  //*********************************
  //              575
  //*********************************
  //*********************************
  TCanvas *c575 = new TCanvas("c575" , "c575" , 1200, 800);
  c575 -> Divide(2,2);
  //c575 -> cd(1);
  TPad *p575_1 = c575->cd(1);
  p575_1->SetLogy(); 
  TGraphErrors *gr575_delaycounts = new TGraphErrors(counts_575, delaytimeArray575 , UCNIntegralArray575, 0, UCNIntegralErrArray575);

  gr575_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr575_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr575_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr575_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr575_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_delaycounts -> SetMarkerStyle(7);
  gr575_delaycounts -> Fit(fit);
  storage575 = fit -> GetParameter(1);
  storageErr575 = fit -> GetParError(1);
  
  TGraphErrors *gr575_delayhist = new TGraphErrors(counts_575, delaytimeArray575 , HistIntegralArray575, 0, HistIntegralErrArray575);

  gr575_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr575_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr575_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr575_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr575_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr575_delayhist -> SetMarkerColor(2);
  gr575_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr575_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr575_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr575_delaycounts -> Draw("Ap");
  gr575_delayhist -> Draw("p");
  leg2 -> Draw();

  //c575 -> cd(2);
  TPad *p575_2 = c575->cd(2);
  p575_2->SetLogy(); 
  TGraphErrors *gr575_tempIrradcounts = new TGraphErrors (counts_575 , avets12IrradArray575, UCNIntegralArray575 , ts12IrradErr575 , UCNIntegralErrArray575);
  gr575_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr575_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr575_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr575_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr575_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr575_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr575_tempValveOpencounts = new TGraphErrors (counts_575 , avets12ValveOpenArray575, UCNIntegralArray575 , ts12ValveOpenErr575 , UCNIntegralErrArray575);
  gr575_tempValveOpencounts -> SetMarkerStyle(7);
  gr575_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr575_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr575_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr575_tempIrradcounts -> Draw("Ap");
  gr575_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c575 -> cd(3);
  TGraphErrors *gr575_delaytempIrrad = new TGraphErrors (counts_575 , delaytimeArray575, avets12IrradArray575, 0 , ts12IrradErr575);

  gr575_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr575_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr575_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr575_delaytempIrrad -> SetMarkerStyle(7);
  gr575_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr575_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr575_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr575_delaytempValveOpen = new TGraphErrors (counts_575 , delaytimeArray575, avets12ValveOpenArray575, 0 , ts12ValveOpenErr575);

  gr575_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr575_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr575_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr575_delaytempValveOpen -> SetMarkerStyle(7);
  gr575_delaytempValveOpen -> SetMarkerColor(2);
  gr575_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr575_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr575_delaytempIrrad -> Draw("AP");
  gr575_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p575_3 = c575->cd(4);
  p575_3->SetLogy(); 
  TGraphErrors *gr575_curcounts = new TGraphErrors (counts_575 , avecurArray575, UCNIntegralArray575 , ErrcurArray575 , UCNIntegralErrArray575);
  gr575_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr575_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr575_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr575_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr575_curhist = new TGraphErrors (counts_575 , avecurArray575, UCNIntegralArray575 , ErrcurArray575 , UCNIntegralErrArray575);
  gr575_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr575_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr575_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr575_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr575_curhist -> SetMarkerColor(2);
  gr575_curhist -> SetMarkerStyle(7);

  gr575_curcounts -> Draw("Ap");
  gr575_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c575_cycleNum = new TCanvas("c575_cycleNum" , "c575_cycleNum" , 1200, 800);
  c575_cycleNum -> Divide(2,2);
  TPad *p575_4 = c575_cycleNum->cd(1);
  p575_4->SetLogy(); 
  TGraphErrors *gr575_cyclecounts = new TGraphErrors (counts_575 , cycleNumberArray575, UCNIntegralArray575, 0 , UCNIntegralErrArray575);
  gr575_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr575_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr575_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr575_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr575_cyclehist = new TGraphErrors(counts_575, cycleNumberArray575 , HistIntegralArray575, 0, HistIntegralErrArray575);

  gr575_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr575_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr575_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr575_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr575_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr575_cyclehist -> SetMarkerColor(2);
  gr575_cyclehist -> SetMarkerStyle(7);

  gr575_cyclecounts -> Draw("Ap");
  gr575_cyclehist -> Draw("p");

  leg2-> Draw();

  c575_cycleNum -> cd(2);
 TGraphErrors *gr575_cycledelay = new TGraphErrors (counts_575 , cycleNumberArray575, delaytimeArray575, 0 , 0);
  gr575_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr575_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr575_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr575_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cycledelay -> SetMarkerStyle(7);

  gr575_cycledelay -> Draw("Ap");


  c575_cycleNum -> cd(3);
  TGraphErrors *gr575_cycletempIrrad = new TGraphErrors (counts_575 , cycleNumberArray575, avets12IrradArray575, 0 , ts12IrradErr575);

  gr575_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr575_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr575_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr575_cycletempIrrad -> SetMarkerStyle(7);
  gr575_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr575_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr575_cycletempValveOpen = new TGraphErrors (counts_575 , cycleNumberArray575, avets12ValveOpenArray575, 0 , ts12ValveOpenErr575);

  gr575_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr575_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr575_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr575_cycletempValveOpen -> SetMarkerStyle(7);
  gr575_cycletempValveOpen -> SetMarkerColor(2);
  gr575_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr575_cycletempIrrad -> Draw("AP");
  gr575_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c575_cycleNum -> cd(4);
  TGraphErrors *gr575_cyclecur = new TGraphErrors (counts_575 , cycleNumberArray575 , avecurArray575, 0, ErrcurArray575 );
  gr575_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr575_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr575_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr575_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclecur -> SetMarkerStyle(7);
  gr575_cyclecur -> Draw("Ap");


  TCanvas *c575_cycleNumFit = new TCanvas("c575_cycleNumFit" , "c575_cycleNumFit" , 1200, 800);
  c575_cycleNumFit -> Divide(2,2);

  c575_cycleNumFit -> cd(1);
  TGraphErrors *gr575_cyclefall = new TGraphErrors (counts_575, cycleNumberArray575, FallTimeArray575 , 0, FallTimeErrArray575);

  gr575_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr575_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr575_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr575_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclefall -> SetMarkerStyle(7);
  gr575_cyclefall -> Draw("Ap");


  c575_cycleNumFit -> cd(2);
  TGraphErrors *gr575_cyclebaseline = new TGraphErrors (counts_575, cycleNumberArray575, BaselineArray575 , 0, BaselineErrArray575);

  gr575_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr575_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr575_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr575_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclebaseline -> SetMarkerStyle(7);
  gr575_cyclebaseline -> Draw("Ap");

  c575_cycleNumFit -> cd(3);
  TGraphErrors *gr575_cyclebaselineirrad = new TGraphErrors (counts_575, cycleNumberArray575, BaselineIrradArray575 , 0, BaselineIrradErrArray575);

  gr575_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr575_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr575_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr575_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclebaselineirrad -> SetMarkerStyle(7);
  gr575_cyclebaselineirrad -> Draw("Ap");

  c575_cycleNumFit -> cd(4);
  TGraphErrors *gr575_cyclerise = new TGraphErrors (counts_575, cycleNumberArray575, RiseTimeArray575 , 0, RiseTimeErrArray575);

  gr575_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr575_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr575_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr575_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr575_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr575_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr575_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr575_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr575_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr575_cyclerise -> SetMarkerStyle(7);
  gr575_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              576
  //*********************************
  //*********************************
  TCanvas *c576 = new TCanvas("c576" , "c576" , 1200, 800);
  c576 -> Divide(2,2);
  //c576 -> cd(1);
  TPad *p576_1 = c576->cd(1);
  p576_1->SetLogy(); 
  TGraphErrors *gr576_delaycounts = new TGraphErrors(counts_576, delaytimeArray576 , UCNIntegralArray576, 0, UCNIntegralErrArray576);

  gr576_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr576_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr576_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr576_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr576_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_delaycounts -> SetMarkerStyle(7);
  gr576_delaycounts -> Fit(fit);
  storage576 = fit -> GetParameter(1);
  storageErr576 = fit -> GetParError(1);
  
  TGraphErrors *gr576_delayhist = new TGraphErrors(counts_576, delaytimeArray576 , HistIntegralArray576, 0, HistIntegralErrArray576);

  gr576_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr576_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr576_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr576_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr576_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr576_delayhist -> SetMarkerColor(2);
  gr576_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr576_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr576_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr576_delaycounts -> Draw("Ap");
  gr576_delayhist -> Draw("p");
  leg2 -> Draw();

  //c576 -> cd(2);
  TPad *p576_2 = c576->cd(2);
  p576_2->SetLogy(); 
  TGraphErrors *gr576_tempIrradcounts = new TGraphErrors (counts_576 , avets12IrradArray576, UCNIntegralArray576 , ts12IrradErr576 , UCNIntegralErrArray576);
  gr576_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr576_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr576_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr576_tempIrradcounts -> GetXaxis()-> SetLimits(0.82 ,1.0);
  gr576_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr576_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr576_tempValveOpencounts = new TGraphErrors (counts_576 , avets12ValveOpenArray576, UCNIntegralArray576 , ts12ValveOpenErr576 , UCNIntegralErrArray576);
  gr576_tempValveOpencounts -> SetMarkerStyle(7);
  gr576_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr576_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr576_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr576_tempIrradcounts -> Draw("Ap");
  gr576_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c576 -> cd(3);
  TGraphErrors *gr576_delaytempIrrad = new TGraphErrors (counts_576 , delaytimeArray576, avets12IrradArray576, 0 , ts12IrradErr576);

  gr576_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr576_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr576_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr576_delaytempIrrad -> SetMarkerStyle(7);
  gr576_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.82, 1.);
  gr576_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr576_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr576_delaytempValveOpen = new TGraphErrors (counts_576 , delaytimeArray576, avets12ValveOpenArray576, 0 , ts12ValveOpenErr576);

  gr576_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr576_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr576_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr576_delaytempValveOpen -> SetMarkerStyle(7);
  gr576_delaytempValveOpen -> SetMarkerColor(2);
  gr576_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr576_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr576_delaytempIrrad -> Draw("AP");
  gr576_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p576_3 = c576->cd(4);
  p576_3->SetLogy(); 
  TGraphErrors *gr576_curcounts = new TGraphErrors (counts_576 , avecurArray576, UCNIntegralArray576 , ErrcurArray576 , UCNIntegralErrArray576);
  gr576_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr576_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr576_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr576_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr576_curhist = new TGraphErrors (counts_576 , avecurArray576, UCNIntegralArray576 , ErrcurArray576 , UCNIntegralErrArray576);
  gr576_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr576_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr576_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr576_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr576_curhist -> SetMarkerColor(2);
  gr576_curhist -> SetMarkerStyle(7);

  gr576_curcounts -> Draw("Ap");
  gr576_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c576_cycleNum = new TCanvas("c576_cycleNum" , "c576_cycleNum" , 1200, 800);
  c576_cycleNum -> Divide(2,2);
  TPad *p576_4 = c576_cycleNum->cd(1);
  p576_4->SetLogy(); 
  TGraphErrors *gr576_cyclecounts = new TGraphErrors (counts_576 , cycleNumberArray576, UCNIntegralArray576, 0 , UCNIntegralErrArray576);
  gr576_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr576_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr576_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_cyclecounts -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr576_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr576_cyclehist = new TGraphErrors(counts_576, cycleNumberArray576 , HistIntegralArray576, 0, HistIntegralErrArray576);

  gr576_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr576_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr576_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr576_cyclehist -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr576_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr576_cyclehist -> SetMarkerColor(2);
  gr576_cyclehist -> SetMarkerStyle(7);

  gr576_cyclecounts -> Draw("Ap");
  gr576_cyclehist -> Draw("p");

  leg2-> Draw();

  c576_cycleNum -> cd(2);
 TGraphErrors *gr576_cycledelay = new TGraphErrors (counts_576 , cycleNumberArray576, delaytimeArray576, 0 , 0);
  gr576_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr576_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr576_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr576_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cycledelay -> SetMarkerStyle(7);

  gr576_cycledelay -> Draw("Ap");


  c576_cycleNum -> cd(3);
  TGraphErrors *gr576_cycletempIrrad = new TGraphErrors (counts_576 , cycleNumberArray576, avets12IrradArray576, 0 , ts12IrradErr576);

  gr576_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr576_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr576_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr576_cycletempIrrad -> SetMarkerStyle(7);
  gr576_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.);
  gr576_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr576_cycletempValveOpen = new TGraphErrors (counts_576 , cycleNumberArray576, avets12ValveOpenArray576, 0 , ts12ValveOpenErr576);

  gr576_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr576_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr576_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr576_cycletempValveOpen -> SetMarkerStyle(7);
  gr576_cycletempValveOpen -> SetMarkerColor(2);
  gr576_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr576_cycletempIrrad -> Draw("AP");
  gr576_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c576_cycleNum -> cd(4);
  TGraphErrors *gr576_cyclecur = new TGraphErrors (counts_576 , cycleNumberArray576 , avecurArray576, 0, ErrcurArray576 );
  gr576_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr576_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr576_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr576_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclecur -> SetMarkerStyle(7);
  gr576_cyclecur -> Draw("Ap");


  TCanvas *c576_cycleNumFit = new TCanvas("c576_cycleNumFit" , "c576_cycleNumFit" , 1200, 800);
  c576_cycleNumFit -> Divide(2,2);

  c576_cycleNumFit -> cd(1);
  TGraphErrors *gr576_cyclefall = new TGraphErrors (counts_576, cycleNumberArray576, FallTimeArray576 , 0, FallTimeErrArray576);

  gr576_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr576_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr576_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr576_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclefall -> SetMarkerStyle(7);
  gr576_cyclefall -> Draw("Ap");


  c576_cycleNumFit -> cd(2);
  TGraphErrors *gr576_cyclebaseline = new TGraphErrors (counts_576, cycleNumberArray576, BaselineArray576 , 0, BaselineErrArray576);

  gr576_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr576_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr576_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr576_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclebaseline -> SetMarkerStyle(7);
  gr576_cyclebaseline -> Draw("Ap");

  c576_cycleNumFit -> cd(3);
  TGraphErrors *gr576_cyclebaselineirrad = new TGraphErrors (counts_576, cycleNumberArray576, BaselineIrradArray576 , 0, BaselineIrradErrArray576);

  gr576_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr576_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr576_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr576_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclebaselineirrad -> SetMarkerStyle(7);
  gr576_cyclebaselineirrad -> Draw("Ap");

  c576_cycleNumFit -> cd(4);
  TGraphErrors *gr576_cyclerise = new TGraphErrors (counts_576, cycleNumberArray576, RiseTimeArray576 , 0, RiseTimeErrArray576);

  gr576_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr576_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr576_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr576_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr576_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr576_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr576_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr576_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr576_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr576_cyclerise -> SetMarkerStyle(7);
  gr576_cyclerise -> Draw("Ap");


  
  //*********************************
  //*********************************
  //              577
  //*********************************
  //*********************************
  TCanvas *c577 = new TCanvas("c577" , "c577" , 1200, 800);
  c577 -> Divide(2,2);
  //c577 -> cd(1);
  TPad *p577_1 = c577->cd(1);
  p577_1->SetLogy(); 
  TGraphErrors *gr577_delaycounts = new TGraphErrors(counts_577, delaytimeArray577 , UCNIntegralArray577, 0, UCNIntegralErrArray577);

  gr577_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr577_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr577_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr577_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr577_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_delaycounts -> SetMarkerStyle(7);
  gr577_delaycounts -> Fit(fit);
  storage577 = fit -> GetParameter(1);
  storageErr577 = fit -> GetParError(1);
  
  TGraphErrors *gr577_delayhist = new TGraphErrors(counts_577, delaytimeArray577 , HistIntegralArray577, 0, HistIntegralErrArray577);

  gr577_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr577_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr577_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr577_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr577_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr577_delayhist -> SetMarkerColor(2);
  gr577_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr577_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr577_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr577_delaycounts -> Draw("Ap");
  gr577_delayhist -> Draw("p");
  leg2 -> Draw();

  //c577 -> cd(2);
  TPad *p577_2 = c577->cd(2);
  p577_2->SetLogy(); 
  TGraphErrors *gr577_tempIrradcounts = new TGraphErrors (counts_577 , avets12IrradArray577, UCNIntegralArray577 , ts12IrradErr577 , UCNIntegralErrArray577);
  gr577_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr577_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr577_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr577_tempIrradcounts -> GetXaxis()-> SetLimits(1.1 ,1.5);
  gr577_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr577_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr577_tempValveOpencounts = new TGraphErrors (counts_577 , avets12ValveOpenArray577, UCNIntegralArray577 , ts12ValveOpenErr577 , UCNIntegralErrArray577);
  gr577_tempValveOpencounts -> SetMarkerStyle(7);
  gr577_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr577_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr577_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr577_tempIrradcounts -> Draw("Ap");
  gr577_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c577 -> cd(3);
  TGraphErrors *gr577_delaytempIrrad = new TGraphErrors (counts_577 , delaytimeArray577, avets12IrradArray577, 0 , ts12IrradErr577);

  gr577_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr577_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr577_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr577_delaytempIrrad -> SetMarkerStyle(7);
  gr577_delaytempIrrad -> GetYaxis() -> SetRangeUser(1.1, 1.5);
  gr577_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr577_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr577_delaytempValveOpen = new TGraphErrors (counts_577 , delaytimeArray577, avets12ValveOpenArray577, 0 , ts12ValveOpenErr577);

  gr577_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr577_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr577_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr577_delaytempValveOpen -> SetMarkerStyle(7);
  gr577_delaytempValveOpen -> SetMarkerColor(2);
  gr577_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr577_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr577_delaytempIrrad -> Draw("AP");
  gr577_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p577_3 = c577->cd(4);
  p577_3->SetLogy(); 
  TGraphErrors *gr577_curcounts = new TGraphErrors (counts_577 , avecurArray577, UCNIntegralArray577 , ErrcurArray577 , UCNIntegralErrArray577);
  gr577_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr577_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr577_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr577_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr577_curhist = new TGraphErrors (counts_577 , avecurArray577, UCNIntegralArray577 , ErrcurArray577 , UCNIntegralErrArray577);
  gr577_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr577_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr577_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr577_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr577_curhist -> SetMarkerColor(2);
  gr577_curhist -> SetMarkerStyle(7);

  gr577_curcounts -> Draw("Ap");
  gr577_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c577_cycleNum = new TCanvas("c577_cycleNum" , "c577_cycleNum" , 1200, 800);
  c577_cycleNum -> Divide(2,2);
  TPad *p577_4 = c577_cycleNum->cd(1);
  p577_4->SetLogy(); 
  TGraphErrors *gr577_cyclecounts = new TGraphErrors (counts_577 , cycleNumberArray577, UCNIntegralArray577, 0 , UCNIntegralErrArray577);
  gr577_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr577_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr577_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr577_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr577_cyclehist = new TGraphErrors(counts_577, cycleNumberArray577 , HistIntegralArray577, 0, HistIntegralErrArray577);

  gr577_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr577_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr577_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr577_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr577_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr577_cyclehist -> SetMarkerColor(2);
  gr577_cyclehist -> SetMarkerStyle(7);

  gr577_cyclecounts -> Draw("Ap");
  gr577_cyclehist -> Draw("p");

  leg2-> Draw();

  c577_cycleNum -> cd(2);
 TGraphErrors *gr577_cycledelay = new TGraphErrors (counts_577 , cycleNumberArray577, delaytimeArray577, 0 , 0);
  gr577_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr577_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr577_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr577_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cycledelay -> SetMarkerStyle(7);

  gr577_cycledelay -> Draw("Ap");


  c577_cycleNum -> cd(3);
  TGraphErrors *gr577_cycletempIrrad = new TGraphErrors (counts_577 , cycleNumberArray577, avets12IrradArray577, 0 , ts12IrradErr577);

  gr577_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr577_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr577_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr577_cycletempIrrad -> SetMarkerStyle(7);
  gr577_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 1.1);
  gr577_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr577_cycletempValveOpen = new TGraphErrors (counts_577 , cycleNumberArray577, avets12ValveOpenArray577, 0 , ts12ValveOpenErr577);

  gr577_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr577_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr577_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr577_cycletempValveOpen -> SetMarkerStyle(7);
  gr577_cycletempValveOpen -> SetMarkerColor(2);
  gr577_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr577_cycletempIrrad -> Draw("AP");
  gr577_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c577_cycleNum -> cd(4);
  TGraphErrors *gr577_cyclecur = new TGraphErrors (counts_577 , cycleNumberArray577 , avecurArray577, 0, ErrcurArray577 );
  gr577_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr577_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr577_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr577_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclecur -> SetMarkerStyle(7);
  gr577_cyclecur -> Draw("Ap");


  TCanvas *c577_cycleNumFit = new TCanvas("c577_cycleNumFit" , "c577_cycleNumFit" , 1200, 800);
  c577_cycleNumFit -> Divide(2,2);

  c577_cycleNumFit -> cd(1);
  TGraphErrors *gr577_cyclefall = new TGraphErrors (counts_577, cycleNumberArray577, FallTimeArray577 , 0, FallTimeErrArray577);

  gr577_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr577_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr577_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr577_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclefall -> SetMarkerStyle(7);
  gr577_cyclefall -> Draw("Ap");


  c577_cycleNumFit -> cd(2);
  TGraphErrors *gr577_cyclebaseline = new TGraphErrors (counts_577, cycleNumberArray577, BaselineArray577 , 0, BaselineErrArray577);

  gr577_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr577_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr577_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr577_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclebaseline -> SetMarkerStyle(7);
  gr577_cyclebaseline -> Draw("Ap");

  c577_cycleNumFit -> cd(3);
  TGraphErrors *gr577_cyclebaselineirrad = new TGraphErrors (counts_577, cycleNumberArray577, BaselineIrradArray577 , 0, BaselineIrradErrArray577);

  gr577_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr577_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr577_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr577_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclebaselineirrad -> SetMarkerStyle(7);
  gr577_cyclebaselineirrad -> Draw("Ap");

  c577_cycleNumFit -> cd(4);
  TGraphErrors *gr577_cyclerise = new TGraphErrors (counts_577, cycleNumberArray577, RiseTimeArray577 , 0, RiseTimeErrArray577);

  gr577_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr577_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr577_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr577_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr577_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr577_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr577_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr577_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr577_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr577_cyclerise -> SetMarkerStyle(7);
  gr577_cyclerise -> Draw("Ap");





  //*********************************
  //*********************************
  //              578
  //*********************************
  //*********************************
  TCanvas *c578 = new TCanvas("c578" , "c578" , 1200, 800);
  c578 -> Divide(2,2);
  //c578 -> cd(1);
  TPad *p578_1 = c578->cd(1);
  p578_1->SetLogy(); 
  TGraphErrors *gr578_delaycounts = new TGraphErrors(counts_578, delaytimeArray578 , UCNIntegralArray578, 0, UCNIntegralErrArray578);

  gr578_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr578_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr578_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr578_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr578_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_delaycounts -> SetMarkerStyle(7);
  gr578_delaycounts -> Fit(fit);
  storage578 = fit -> GetParameter(1);
  storageErr578 = fit -> GetParError(1);
  
  TGraphErrors *gr578_delayhist = new TGraphErrors(counts_578, delaytimeArray578 , HistIntegralArray578, 0, HistIntegralErrArray578);

  gr578_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr578_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr578_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr578_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr578_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr578_delayhist -> SetMarkerColor(2);
  gr578_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr578_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr578_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr578_delaycounts -> Draw("Ap");
  gr578_delayhist -> Draw("p");
  leg2 -> Draw();

  //c578 -> cd(2);
  TPad *p578_2 = c578->cd(2);
  p578_2->SetLogy(); 
  TGraphErrors *gr578_tempIrradcounts = new TGraphErrors (counts_578 , avets12IrradArray578, UCNIntegralArray578 , ts12IrradErr578 , UCNIntegralErrArray578);
  gr578_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr578_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr578_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr578_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr578_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr578_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr578_tempValveOpencounts = new TGraphErrors (counts_578 , avets12ValveOpenArray578, UCNIntegralArray578 , ts12ValveOpenErr578 , UCNIntegralErrArray578);
  gr578_tempValveOpencounts -> SetMarkerStyle(7);
  gr578_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr578_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr578_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr578_tempIrradcounts -> Draw("Ap");
  gr578_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c578 -> cd(3);
  TGraphErrors *gr578_delaytempIrrad = new TGraphErrors (counts_578 , delaytimeArray578, avets12IrradArray578, 0 , ts12IrradErr578);

  gr578_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr578_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr578_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr578_delaytempIrrad -> SetMarkerStyle(7);
  gr578_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr578_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr578_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr578_delaytempValveOpen = new TGraphErrors (counts_578 , delaytimeArray578, avets12ValveOpenArray578, 0 , ts12ValveOpenErr578);

  gr578_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr578_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr578_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr578_delaytempValveOpen -> SetMarkerStyle(7);
  gr578_delaytempValveOpen -> SetMarkerColor(2);
  gr578_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr578_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr578_delaytempIrrad -> Draw("AP");
  gr578_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p578_3 = c578->cd(4);
  p578_3->SetLogy(); 
  TGraphErrors *gr578_curcounts = new TGraphErrors (counts_578 , avecurArray578, UCNIntegralArray578 , ErrcurArray578 , UCNIntegralErrArray578);
  gr578_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr578_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr578_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr578_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr578_curhist = new TGraphErrors (counts_578 , avecurArray578, UCNIntegralArray578 , ErrcurArray578 , UCNIntegralErrArray578);
  gr578_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr578_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr578_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr578_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr578_curhist -> SetMarkerColor(2);
  gr578_curhist -> SetMarkerStyle(7);

  gr578_curcounts -> Draw("Ap");
  gr578_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c578_cycleNum = new TCanvas("c578_cycleNum" , "c578_cycleNum" , 1200, 800);
  c578_cycleNum -> Divide(2,2);
  TPad *p578_4 = c578_cycleNum->cd(1);
  p578_4->SetLogy(); 
  TGraphErrors *gr578_cyclecounts = new TGraphErrors (counts_578 , cycleNumberArray578, UCNIntegralArray578, 0 , UCNIntegralErrArray578);
  gr578_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr578_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr578_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr578_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr578_cyclehist = new TGraphErrors(counts_578, cycleNumberArray578 , HistIntegralArray578, 0, HistIntegralErrArray578);

  gr578_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr578_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr578_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr578_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr578_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr578_cyclehist -> SetMarkerColor(2);
  gr578_cyclehist -> SetMarkerStyle(7);

  gr578_cyclecounts -> Draw("Ap");
  gr578_cyclehist -> Draw("p");

  leg2-> Draw();

  c578_cycleNum -> cd(2);
 TGraphErrors *gr578_cycledelay = new TGraphErrors (counts_578 , cycleNumberArray578, delaytimeArray578, 0 , 0);
  gr578_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr578_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr578_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr578_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cycledelay -> SetMarkerStyle(7);

  gr578_cycledelay -> Draw("Ap");


  c578_cycleNum -> cd(3);
  TGraphErrors *gr578_cycletempIrrad = new TGraphErrors (counts_578 , cycleNumberArray578, avets12IrradArray578, 0 , ts12IrradErr578);

  gr578_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr578_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr578_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr578_cycletempIrrad -> SetMarkerStyle(7);
  gr578_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr578_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr578_cycletempValveOpen = new TGraphErrors (counts_578 , cycleNumberArray578, avets12ValveOpenArray578, 0 , ts12ValveOpenErr578);

  gr578_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr578_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr578_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr578_cycletempValveOpen -> SetMarkerStyle(7);
  gr578_cycletempValveOpen -> SetMarkerColor(2);
  gr578_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr578_cycletempIrrad -> Draw("AP");
  gr578_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c578_cycleNum -> cd(4);
  TGraphErrors *gr578_cyclecur = new TGraphErrors (counts_578 , cycleNumberArray578 , avecurArray578, 0, ErrcurArray578 );
  gr578_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr578_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr578_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr578_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclecur -> SetMarkerStyle(7);
  gr578_cyclecur -> Draw("Ap");


  TCanvas *c578_cycleNumFit = new TCanvas("c578_cycleNumFit" , "c578_cycleNumFit" , 1200, 800);
  c578_cycleNumFit -> Divide(2,2);

  c578_cycleNumFit -> cd(1);
  TGraphErrors *gr578_cyclefall = new TGraphErrors (counts_578, cycleNumberArray578, FallTimeArray578 , 0, FallTimeErrArray578);

  gr578_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr578_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr578_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr578_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclefall -> SetMarkerStyle(7);
  gr578_cyclefall -> Draw("Ap");


  c578_cycleNumFit -> cd(2);
  TGraphErrors *gr578_cyclebaseline = new TGraphErrors (counts_578, cycleNumberArray578, BaselineArray578 , 0, BaselineErrArray578);

  gr578_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr578_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr578_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr578_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclebaseline -> SetMarkerStyle(7);
  gr578_cyclebaseline -> Draw("Ap");

  c578_cycleNumFit -> cd(3);
  TGraphErrors *gr578_cyclebaselineirrad = new TGraphErrors (counts_578, cycleNumberArray578, BaselineIrradArray578 , 0, BaselineIrradErrArray578);

  gr578_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr578_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr578_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr578_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclebaselineirrad -> SetMarkerStyle(7);
  gr578_cyclebaselineirrad -> Draw("Ap");

  c578_cycleNumFit -> cd(4);
  TGraphErrors *gr578_cyclerise = new TGraphErrors (counts_578, cycleNumberArray578, RiseTimeArray578 , 0, RiseTimeErrArray578);

  gr578_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr578_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr578_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr578_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr578_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr578_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr578_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr578_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr578_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr578_cyclerise -> SetMarkerStyle(7);
  gr578_cyclerise -> Draw("Ap");






  //*********************************
  //*********************************
  //              579
  //*********************************
  //*********************************
  TCanvas *c579 = new TCanvas("c579" , "c579" , 1200, 800);
  c579 -> Divide(2,2);
  //c579 -> cd(1);
  TPad *p579_1 = c579->cd(1);
  p579_1->SetLogy(); 
  TGraphErrors *gr579_delaycounts = new TGraphErrors(counts_579, delaytimeArray579 , UCNIntegralArray579, 0, UCNIntegralErrArray579);

  gr579_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr579_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr579_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr579_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr579_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_delaycounts -> SetMarkerStyle(7);
  gr579_delaycounts -> Fit(fit);
  storage579 = fit -> GetParameter(1);
  storageErr579 = fit -> GetParError(1);
  
  TGraphErrors *gr579_delayhist = new TGraphErrors(counts_579, delaytimeArray579 , HistIntegralArray579, 0, HistIntegralErrArray579);

  gr579_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr579_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr579_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr579_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr579_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr579_delayhist -> SetMarkerColor(2);
  gr579_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr579_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr579_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr579_delaycounts -> Draw("Ap");
  gr579_delayhist -> Draw("p");
  leg2 -> Draw();

  //c579 -> cd(2);
  TPad *p579_2 = c579->cd(2);
  p579_2->SetLogy(); 
  TGraphErrors *gr579_tempIrradcounts = new TGraphErrors (counts_579 , avets12IrradArray579, UCNIntegralArray579 , ts12IrradErr579 , UCNIntegralErrArray579);
  gr579_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr579_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr579_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr579_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr579_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr579_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr579_tempValveOpencounts = new TGraphErrors (counts_579 , avets12ValveOpenArray579, UCNIntegralArray579 , ts12ValveOpenErr579 , UCNIntegralErrArray579);
  gr579_tempValveOpencounts -> SetMarkerStyle(7);
  gr579_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr579_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr579_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr579_tempIrradcounts -> Draw("Ap");
  gr579_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c579 -> cd(3);
  TGraphErrors *gr579_delaytempIrrad = new TGraphErrors (counts_579 , delaytimeArray579, avets12IrradArray579, 0 , ts12IrradErr579);

  gr579_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr579_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr579_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr579_delaytempIrrad -> SetMarkerStyle(7);
  gr579_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr579_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr579_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr579_delaytempValveOpen = new TGraphErrors (counts_579 , delaytimeArray579, avets12ValveOpenArray579, 0 , ts12ValveOpenErr579);

  gr579_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr579_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr579_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr579_delaytempValveOpen -> SetMarkerStyle(7);
  gr579_delaytempValveOpen -> SetMarkerColor(2);
  gr579_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr579_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr579_delaytempIrrad -> Draw("AP");
  gr579_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p579_3 = c579->cd(4);
  p579_3->SetLogy(); 
  TGraphErrors *gr579_curcounts = new TGraphErrors (counts_579 , avecurArray579, UCNIntegralArray579 , ErrcurArray579 , UCNIntegralErrArray579);
  gr579_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr579_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr579_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr579_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr579_curhist = new TGraphErrors (counts_579 , avecurArray579, UCNIntegralArray579 , ErrcurArray579 , UCNIntegralErrArray579);
  gr579_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr579_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr579_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr579_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr579_curhist -> SetMarkerColor(2);
  gr579_curhist -> SetMarkerStyle(7);

  gr579_curcounts -> Draw("Ap");
  gr579_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c579_cycleNum = new TCanvas("c579_cycleNum" , "c579_cycleNum" , 1200, 800);
  c579_cycleNum -> Divide(2,2);
  TPad *p579_4 = c579_cycleNum->cd(1);
  p579_4->SetLogy(); 
  TGraphErrors *gr579_cyclecounts = new TGraphErrors (counts_579 , cycleNumberArray579, UCNIntegralArray579, 0 , UCNIntegralErrArray579);
  gr579_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr579_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr579_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr579_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr579_cyclehist = new TGraphErrors(counts_579, cycleNumberArray579 , HistIntegralArray579, 0, HistIntegralErrArray579);

  gr579_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr579_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr579_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr579_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr579_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr579_cyclehist -> SetMarkerColor(2);
  gr579_cyclehist -> SetMarkerStyle(7);

  gr579_cyclecounts -> Draw("Ap");
  gr579_cyclehist -> Draw("p");

  leg2-> Draw();

  c579_cycleNum -> cd(2);
 TGraphErrors *gr579_cycledelay = new TGraphErrors (counts_579 , cycleNumberArray579, delaytimeArray579, 0 , 0);
  gr579_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr579_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr579_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr579_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cycledelay -> SetMarkerStyle(7);

  gr579_cycledelay -> Draw("Ap");


  c579_cycleNum -> cd(3);
  TGraphErrors *gr579_cycletempIrrad = new TGraphErrors (counts_579 , cycleNumberArray579, avets12IrradArray579, 0 , ts12IrradErr579);

  gr579_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr579_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr579_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr579_cycletempIrrad -> SetMarkerStyle(7);
  gr579_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr579_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr579_cycletempValveOpen = new TGraphErrors (counts_579 , cycleNumberArray579, avets12ValveOpenArray579, 0 , ts12ValveOpenErr579);

  gr579_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr579_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr579_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr579_cycletempValveOpen -> SetMarkerStyle(7);
  gr579_cycletempValveOpen -> SetMarkerColor(2);
  gr579_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr579_cycletempIrrad -> Draw("AP");
  gr579_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c579_cycleNum -> cd(4);
  TGraphErrors *gr579_cyclecur = new TGraphErrors (counts_579 , cycleNumberArray579 , avecurArray579, 0, ErrcurArray579 );
  gr579_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr579_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr579_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr579_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclecur -> SetMarkerStyle(7);
  gr579_cyclecur -> Draw("Ap");


  TCanvas *c579_cycleNumFit = new TCanvas("c579_cycleNumFit" , "c579_cycleNumFit" , 1200, 800);
  c579_cycleNumFit -> Divide(2,2);

  c579_cycleNumFit -> cd(1);
  TGraphErrors *gr579_cyclefall = new TGraphErrors (counts_579, cycleNumberArray579, FallTimeArray579 , 0, FallTimeErrArray579);

  gr579_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr579_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr579_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr579_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclefall -> SetMarkerStyle(7);
  gr579_cyclefall -> Draw("Ap");


  c579_cycleNumFit -> cd(2);
  TGraphErrors *gr579_cyclebaseline = new TGraphErrors (counts_579, cycleNumberArray579, BaselineArray579 , 0, BaselineErrArray579);

  gr579_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr579_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr579_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr579_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclebaseline -> SetMarkerStyle(7);
  gr579_cyclebaseline -> Draw("Ap");

  c579_cycleNumFit -> cd(3);
  TGraphErrors *gr579_cyclebaselineirrad = new TGraphErrors (counts_579, cycleNumberArray579, BaselineIrradArray579 , 0, BaselineIrradErrArray579);

  gr579_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr579_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr579_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr579_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclebaselineirrad -> SetMarkerStyle(7);
  gr579_cyclebaselineirrad -> Draw("Ap");

  c579_cycleNumFit -> cd(4);
  TGraphErrors *gr579_cyclerise = new TGraphErrors (counts_579, cycleNumberArray579, RiseTimeArray579 , 0, RiseTimeErrArray579);

  gr579_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr579_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr579_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr579_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr579_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr579_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr579_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr579_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr579_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr579_cyclerise -> SetMarkerStyle(7);
  gr579_cyclerise -> Draw("Ap");







  //*********************************
  //*********************************
  //              580
  //*********************************
  //*********************************
  TCanvas *c580 = new TCanvas("c580" , "c580" , 1200, 800);
  c580 -> Divide(2,2);
  //c580 -> cd(1);
  TPad *p580_1 = c580->cd(1);
  p580_1->SetLogy(); 
  TGraphErrors *gr580_delaycounts = new TGraphErrors(counts_580, delaytimeArray580 , UCNIntegralArray580, 0, UCNIntegralErrArray580);

  gr580_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr580_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr580_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr580_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr580_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_delaycounts -> SetMarkerStyle(7);
  gr580_delaycounts -> Fit(fit);
  storage580 = fit -> GetParameter(1);
  storageErr580 = fit -> GetParError(1);
  
  TGraphErrors *gr580_delayhist = new TGraphErrors(counts_580, delaytimeArray580 , HistIntegralArray580, 0, HistIntegralErrArray580);

  gr580_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr580_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr580_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr580_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr580_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr580_delayhist -> SetMarkerColor(2);
  gr580_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr580_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr580_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr580_delaycounts -> Draw("Ap");
  gr580_delayhist -> Draw("p");
  leg2 -> Draw();

  //c580 -> cd(2);
  TPad *p580_2 = c580->cd(2);
  p580_2->SetLogy(); 
  TGraphErrors *gr580_tempIrradcounts = new TGraphErrors (counts_580 , avets12IrradArray580, UCNIntegralArray580 , ts12IrradErr580 , UCNIntegralErrArray580);
  gr580_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr580_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr580_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr580_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr580_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr580_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr580_tempValveOpencounts = new TGraphErrors (counts_580 , avets12ValveOpenArray580, UCNIntegralArray580 , ts12ValveOpenErr580 , UCNIntegralErrArray580);
  gr580_tempValveOpencounts -> SetMarkerStyle(7);
  gr580_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr580_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr580_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr580_tempIrradcounts -> Draw("Ap");
  gr580_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c580 -> cd(3);
  TGraphErrors *gr580_delaytempIrrad = new TGraphErrors (counts_580 , delaytimeArray580, avets12IrradArray580, 0 , ts12IrradErr580);

  gr580_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr580_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr580_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr580_delaytempIrrad -> SetMarkerStyle(7);
  gr580_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr580_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr580_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr580_delaytempValveOpen = new TGraphErrors (counts_580 , delaytimeArray580, avets12ValveOpenArray580, 0 , ts12ValveOpenErr580);

  gr580_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr580_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr580_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr580_delaytempValveOpen -> SetMarkerStyle(7);
  gr580_delaytempValveOpen -> SetMarkerColor(2);
  gr580_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr580_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr580_delaytempIrrad -> Draw("AP");
  gr580_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p580_3 = c580->cd(4);
  p580_3->SetLogy(); 
  TGraphErrors *gr580_curcounts = new TGraphErrors (counts_580 , avecurArray580, UCNIntegralArray580 , ErrcurArray580 , UCNIntegralErrArray580);
  gr580_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr580_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr580_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr580_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr580_curhist = new TGraphErrors (counts_580 , avecurArray580, UCNIntegralArray580 , ErrcurArray580 , UCNIntegralErrArray580);
  gr580_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr580_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr580_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr580_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr580_curhist -> SetMarkerColor(2);
  gr580_curhist -> SetMarkerStyle(7);

  gr580_curcounts -> Draw("Ap");
  gr580_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c580_cycleNum = new TCanvas("c580_cycleNum" , "c580_cycleNum" , 1200, 800);
  c580_cycleNum -> Divide(2,2);
  TPad *p580_4 = c580_cycleNum->cd(1);
  p580_4->SetLogy(); 
  TGraphErrors *gr580_cyclecounts = new TGraphErrors (counts_580 , cycleNumberArray580, UCNIntegralArray580, 0 , UCNIntegralErrArray580);
  gr580_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr580_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr580_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr580_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr580_cyclehist = new TGraphErrors(counts_580, cycleNumberArray580 , HistIntegralArray580, 0, HistIntegralErrArray580);

  gr580_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr580_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr580_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr580_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr580_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr580_cyclehist -> SetMarkerColor(2);
  gr580_cyclehist -> SetMarkerStyle(7);

  gr580_cyclecounts -> Draw("Ap");
  gr580_cyclehist -> Draw("p");

  leg2-> Draw();

  c580_cycleNum -> cd(2);
 TGraphErrors *gr580_cycledelay = new TGraphErrors (counts_580 , cycleNumberArray580, delaytimeArray580, 0 , 0);
  gr580_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr580_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr580_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr580_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cycledelay -> SetMarkerStyle(7);

  gr580_cycledelay -> Draw("Ap");


  c580_cycleNum -> cd(3);
  TGraphErrors *gr580_cycletempIrrad = new TGraphErrors (counts_580 , cycleNumberArray580, avets12IrradArray580, 0 , ts12IrradErr580);

  gr580_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr580_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr580_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr580_cycletempIrrad -> SetMarkerStyle(7);
  gr580_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr580_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr580_cycletempValveOpen = new TGraphErrors (counts_580 , cycleNumberArray580, avets12ValveOpenArray580, 0 , ts12ValveOpenErr580);

  gr580_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr580_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr580_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr580_cycletempValveOpen -> SetMarkerStyle(7);
  gr580_cycletempValveOpen -> SetMarkerColor(2);
  gr580_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr580_cycletempIrrad -> Draw("AP");
  gr580_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c580_cycleNum -> cd(4);
  TGraphErrors *gr580_cyclecur = new TGraphErrors (counts_580 , cycleNumberArray580 , avecurArray580, 0, ErrcurArray580 );
  gr580_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr580_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr580_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr580_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclecur -> SetMarkerStyle(7);
  gr580_cyclecur -> Draw("Ap");


  TCanvas *c580_cycleNumFit = new TCanvas("c580_cycleNumFit" , "c580_cycleNumFit" , 1200, 800);
  c580_cycleNumFit -> Divide(2,2);

  c580_cycleNumFit -> cd(1);
  TGraphErrors *gr580_cyclefall = new TGraphErrors (counts_580, cycleNumberArray580, FallTimeArray580 , 0, FallTimeErrArray580);

  gr580_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr580_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr580_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr580_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclefall -> SetMarkerStyle(7);
  gr580_cyclefall -> Draw("Ap");


  c580_cycleNumFit -> cd(2);
  TGraphErrors *gr580_cyclebaseline = new TGraphErrors (counts_580, cycleNumberArray580, BaselineArray580 , 0, BaselineErrArray580);

  gr580_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr580_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr580_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr580_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclebaseline -> SetMarkerStyle(7);
  gr580_cyclebaseline -> Draw("Ap");

  c580_cycleNumFit -> cd(3);
  TGraphErrors *gr580_cyclebaselineirrad = new TGraphErrors (counts_580, cycleNumberArray580, BaselineIrradArray580 , 0, BaselineIrradErrArray580);

  gr580_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr580_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr580_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr580_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclebaselineirrad -> SetMarkerStyle(7);
  gr580_cyclebaselineirrad -> Draw("Ap");

  c580_cycleNumFit -> cd(4);
  TGraphErrors *gr580_cyclerise = new TGraphErrors (counts_580, cycleNumberArray580, RiseTimeArray580 , 0, RiseTimeErrArray580);

  gr580_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr580_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr580_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr580_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr580_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr580_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr580_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr580_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr580_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr580_cyclerise -> SetMarkerStyle(7);
  gr580_cyclerise -> Draw("Ap");




  //*********************************
  //*********************************
  //              581
  //*********************************
  //*********************************
  TCanvas *c581 = new TCanvas("c581" , "c581" , 1200, 800);
  c581 -> Divide(2,2);
  //c581 -> cd(1);
  TPad *p581_1 = c581->cd(1);
  p581_1->SetLogy(); 
  TGraphErrors *gr581_delaycounts = new TGraphErrors(counts_581, delaytimeArray581 , UCNIntegralArray581, 0, UCNIntegralErrArray581);

  gr581_delaycounts -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr581_delaycounts -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr581_delaycounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_delaycounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr581_delaycounts -> GetXaxis() -> SetTitleSize(0.05);
  gr581_delaycounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_delaycounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_delaycounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_delaycounts -> SetMarkerStyle(7);
  gr581_delaycounts -> Fit(fit);
  storage581 = fit -> GetParameter(1);
  storageErr581 = fit -> GetParError(1);
  
  TGraphErrors *gr581_delayhist = new TGraphErrors(counts_581, delaytimeArray581 , HistIntegralArray581, 0, HistIntegralErrArray581);

  gr581_delayhist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr581_delayhist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr581_delayhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_delayhist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr581_delayhist -> GetXaxis() -> SetTitleSize(0.05);
  gr581_delayhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_delayhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_delayhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr581_delayhist -> SetMarkerColor(2);
  gr581_delayhist -> SetMarkerStyle(7);

  TLegend *leg2 = new TLegend(0.4,0.7, 0.9, 0.9);
  leg2 -> AddEntry(gr581_delaycounts , "Without Background" , "p") ;
  leg2 -> AddEntry(gr581_delayhist , "With Background" , "p") ;
  leg2 -> SetTextSize(0.05);


  gr581_delaycounts -> Draw("Ap");
  gr581_delayhist -> Draw("p");
  leg2 -> Draw();

  //c581 -> cd(2);
  TPad *p581_2 = c581->cd(2);
  p581_2->SetLogy(); 
  TGraphErrors *gr581_tempIrradcounts = new TGraphErrors (counts_581 , avets12IrradArray581, UCNIntegralArray581 , ts12IrradErr581 , UCNIntegralErrArray581);
  gr581_tempIrradcounts -> SetTitle("UCN Counts vs Average Isopure Temperature");
  gr581_tempIrradcounts -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr581_tempIrradcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_tempIrradcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr581_tempIrradcounts -> GetXaxis()-> SetLimits(0.9 ,1.3);
  gr581_tempIrradcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr581_tempIrradcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_tempIrradcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_tempIrradcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_tempIrradcounts -> SetMarkerStyle(7);

  TGraphErrors *gr581_tempValveOpencounts = new TGraphErrors (counts_581 , avets12ValveOpenArray581, UCNIntegralArray581 , ts12ValveOpenErr581 , UCNIntegralErrArray581);
  gr581_tempValveOpencounts -> SetMarkerStyle(7);
  gr581_tempValveOpencounts -> SetMarkerColor(2);

  TLegend *leg = new TLegend(0.4,0.7, 0.9, 0.9);
  leg -> AddEntry(gr581_tempIrradcounts , "Irradiation time + delay time" , "p") ;
  leg -> AddEntry(gr581_tempValveOpencounts , "Valve open" , "p") ;
  leg -> SetTextSize(0.05);
  gr581_tempIrradcounts -> Draw("Ap");
  gr581_tempValveOpencounts -> Draw("p");
  leg -> Draw();

  c581 -> cd(3);
  TGraphErrors *gr581_delaytempIrrad = new TGraphErrors (counts_581 , delaytimeArray581, avets12IrradArray581, 0 , ts12IrradErr581);

  gr581_delaytempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr581_delaytempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr581_delaytempIrrad -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr581_delaytempIrrad -> SetMarkerStyle(7);
  gr581_delaytempIrrad -> GetYaxis() -> SetRangeUser(0.9, 1.3);
  gr581_delaytempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr581_delaytempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_delaytempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_delaytempIrrad -> GetYaxis() -> SetTitleOffset(0.9);


  TGraphErrors *gr581_delaytempValveOpen = new TGraphErrors (counts_581 , delaytimeArray581, avets12ValveOpenArray581, 0 , ts12ValveOpenErr581);

  gr581_delaytempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Delay Time");
  gr581_delaytempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr581_delaytempValveOpen -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  gr581_delaytempValveOpen -> SetMarkerStyle(7);
  gr581_delaytempValveOpen -> SetMarkerColor(2);
  gr581_delaytempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr581_delaytempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_delaytempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_delaytempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr581_delaytempIrrad -> Draw("AP");
  gr581_delaytempValveOpen -> Draw("p");
  leg -> Draw();


  TPad *p581_3 = c581->cd(4);
  p581_3->SetLogy(); 
  TGraphErrors *gr581_curcounts = new TGraphErrors (counts_581 , avecurArray581, UCNIntegralArray581 , ErrcurArray581 , UCNIntegralErrArray581);
  gr581_curcounts -> SetTitle("UCN Counts vs Average Beam Current");
  gr581_curcounts -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr581_curcounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_curcounts -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_curcounts -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_curcounts -> GetXaxis() -> SetTitleSize(0.05);
  gr581_curcounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_curcounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_curcounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_curcounts -> SetMarkerStyle(7);

  TGraphErrors *gr581_curhist = new TGraphErrors (counts_581 , avecurArray581, UCNIntegralArray581 , ErrcurArray581 , UCNIntegralErrArray581);
  gr581_curhist -> SetTitle("UCN Counts vs Average Beam Current");
  gr581_curhist -> GetXaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr581_curhist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_curhist -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_curhist -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_curhist -> GetXaxis() -> SetTitleSize(0.05);
  gr581_curhist -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_curhist -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_curhist -> GetYaxis() -> SetTitleOffset(0.9);
  gr581_curhist -> SetMarkerColor(2);
  gr581_curhist -> SetMarkerStyle(7);

  gr581_curcounts -> Draw("Ap");
  gr581_curhist -> Draw("p");
  leg2 -> Draw();

  TCanvas *c581_cycleNum = new TCanvas("c581_cycleNum" , "c581_cycleNum" , 1200, 800);
  c581_cycleNum -> Divide(2,2);
  TPad *p581_4 = c581_cycleNum->cd(1);
  p581_4->SetLogy(); 
  TGraphErrors *gr581_cyclecounts = new TGraphErrors (counts_581 , cycleNumberArray581, UCNIntegralArray581, 0 , UCNIntegralErrArray581);
  gr581_cyclecounts -> SetTitle("UCN Counts vs Cycle Number");
  gr581_cyclecounts -> GetXaxis()-> SetTitle("Cycle Number" );
  gr581_cyclecounts -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_cyclecounts -> GetYaxis()-> SetRangeUser(1, 500000);
  gr581_cyclecounts -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclecounts -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclecounts -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclecounts -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclecounts -> SetMarkerStyle(7);


  TGraphErrors *gr581_cyclehist = new TGraphErrors(counts_581, cycleNumberArray581 , HistIntegralArray581, 0, HistIntegralErrArray581);

  gr581_cyclehist -> SetTitle("UCN Counts vs Cycle Delay Time");
  gr581_cyclehist -> GetXaxis()-> SetTitle("Cycle Delay Time (s)" );
  gr581_cyclehist -> GetYaxis()-> SetTitle("Cycle UCN Counts");
  gr581_cyclehist -> GetYaxis()-> SetRangeUser(1, 500000);
  gr581_cyclehist -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclehist -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclehist -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclehist -> GetYaxis() -> SetTitleOffset(0.9);
  gr581_cyclehist -> SetMarkerColor(2);
  gr581_cyclehist -> SetMarkerStyle(7);

  gr581_cyclecounts -> Draw("Ap");
  gr581_cyclehist -> Draw("p");

  leg2-> Draw();

  c581_cycleNum -> cd(2);
 TGraphErrors *gr581_cycledelay = new TGraphErrors (counts_581 , cycleNumberArray581, delaytimeArray581, 0 , 0);
  gr581_cycledelay -> SetTitle("Delay Time vs Cycle Number");
  gr581_cycledelay -> GetXaxis()-> SetTitle("Cycle Number" );
  gr581_cycledelay -> GetYaxis()-> SetTitle("Cycle Delay Time (s)");
  gr581_cycledelay -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cycledelay -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cycledelay -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cycledelay -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cycledelay -> SetMarkerStyle(7);

  gr581_cycledelay -> Draw("Ap");


  c581_cycleNum -> cd(3);
  TGraphErrors *gr581_cycletempIrrad = new TGraphErrors (counts_581 , cycleNumberArray581, avets12IrradArray581, 0 , ts12IrradErr581);

  gr581_cycletempIrrad -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr581_cycletempIrrad -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr581_cycletempIrrad -> GetXaxis()-> SetTitle("Cycle Number");
  gr581_cycletempIrrad -> SetMarkerStyle(7);
  gr581_cycletempIrrad -> GetYaxis()-> SetRangeUser(0.82, 0.94);
  gr581_cycletempIrrad -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cycletempIrrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cycletempIrrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cycletempIrrad -> GetYaxis() -> SetTitleOffset(0.9);

  TGraphErrors *gr581_cycletempValveOpen = new TGraphErrors (counts_581 , cycleNumberArray581, avets12ValveOpenArray581, 0 , ts12ValveOpenErr581);

  gr581_cycletempValveOpen -> SetTitle( "Average Isopure Temperature vs Cycle Number");
  gr581_cycletempValveOpen -> GetYaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr581_cycletempValveOpen -> GetXaxis()-> SetTitle("Cycle Number");
  gr581_cycletempValveOpen -> SetMarkerStyle(7);
  gr581_cycletempValveOpen -> SetMarkerColor(2);
  gr581_cycletempValveOpen -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cycletempValveOpen -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cycletempValveOpen -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cycletempValveOpen -> GetYaxis() -> SetTitleOffset(0.9);


  gr581_cycletempIrrad -> Draw("AP");
  gr581_cycletempValveOpen -> Draw("p");
  leg -> Draw();

  c581_cycleNum -> cd(4);
  TGraphErrors *gr581_cyclecur = new TGraphErrors (counts_581 , cycleNumberArray581 , avecurArray581, 0, ErrcurArray581 );
  gr581_cyclecur -> SetTitle(" Average Beam Current vs Cycle Number");
  gr581_cyclecur -> GetYaxis()-> SetTitle("Average Beam Current (#muA)" );
  gr581_cyclecur -> GetXaxis()-> SetTitle("Cycle Number");
  //gr581_cyclecur -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_cyclecur -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_cyclecur -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclecur -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclecur -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclecur -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclecur -> SetMarkerStyle(7);
  gr581_cyclecur -> Draw("Ap");


  TCanvas *c581_cycleNumFit = new TCanvas("c581_cycleNumFit" , "c581_cycleNumFit" , 1200, 800);
  c581_cycleNumFit -> Divide(2,2);

  c581_cycleNumFit -> cd(1);
  TGraphErrors *gr581_cyclefall = new TGraphErrors (counts_581, cycleNumberArray581, FallTimeArray581 , 0, FallTimeErrArray581);

  gr581_cyclefall -> SetTitle(" Fall Time vs Cycle Number");
  gr581_cyclefall -> GetYaxis()-> SetTitle("Fall Time (s)" );
  gr581_cyclefall -> GetXaxis()-> SetTitle("Cycle Number");
  //gr581_cyclefall -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_cyclefall -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_cyclefall -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclefall -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclefall -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclefall -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclefall -> SetMarkerStyle(7);
  gr581_cyclefall -> Draw("Ap");


  c581_cycleNumFit -> cd(2);
  TGraphErrors *gr581_cyclebaseline = new TGraphErrors (counts_581, cycleNumberArray581, BaselineArray581 , 0, BaselineErrArray581);

  gr581_cyclebaseline -> SetTitle(" Baseline Before Irradiation vs Cycle Number");
  gr581_cyclebaseline -> GetYaxis()-> SetTitle("Baseline (1/s)" );
  gr581_cyclebaseline -> GetXaxis()-> SetTitle("Cycle Number");
  //gr581_cyclebaseline -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_cyclebaseline -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_cyclebaseline -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclebaseline -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclebaseline -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclebaseline -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclebaseline -> SetMarkerStyle(7);
  gr581_cyclebaseline -> Draw("Ap");

  c581_cycleNumFit -> cd(3);
  TGraphErrors *gr581_cyclebaselineirrad = new TGraphErrors (counts_581, cycleNumberArray581, BaselineIrradArray581 , 0, BaselineIrradErrArray581);

  gr581_cyclebaselineirrad -> SetTitle(" Baseline During Irradiation vs Cycle Number");
  gr581_cyclebaselineirrad -> GetYaxis()-> SetTitle("Baseline (1/(s#muA))" );
  gr581_cyclebaselineirrad -> GetXaxis()-> SetTitle("Cycle Number");
  //gr581_cyclebaselineirrad -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_cyclebaselineirrad -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_cyclebaselineirrad -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclebaselineirrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclebaselineirrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclebaselineirrad -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclebaselineirrad -> SetMarkerStyle(7);
  gr581_cyclebaselineirrad -> Draw("Ap");

  c581_cycleNumFit -> cd(4);
  TGraphErrors *gr581_cyclerise = new TGraphErrors (counts_581, cycleNumberArray581, RiseTimeArray581 , 0, RiseTimeErrArray581);

  gr581_cyclerise -> SetTitle(" Rise Time vs Cycle Number");
  gr581_cyclerise -> GetYaxis()-> SetTitle("Rise Time (s)" );
  gr581_cyclerise -> GetXaxis()-> SetTitle("Cycle Number");
  //gr581_cyclerise -> GetYaxis()-> SetRangeUser(1, 500000);
  //  gr581_cyclerise -> GetXaxis()-> SetLimits(0.82 ,0.90);
  gr581_cyclerise -> GetXaxis() -> SetTitleSize(0.05);
  gr581_cyclerise -> GetXaxis() -> SetTitleOffset(1.0);
  gr581_cyclerise -> GetYaxis() -> SetTitleSize(0.05); 
  gr581_cyclerise -> GetYaxis() -> SetTitleOffset(0.9);

  gr581_cyclerise -> SetMarkerStyle(7);
  gr581_cyclerise -> Draw("Ap");





  /*

  double StorageAll [100] = {storage573, storage574, storage576, storage577, storage578, storage540};
  double StorageErrAll[100] = {storageErr573, storageErr574, storageErr576, storageErr576, storageErr577, storageErr578, storageErr540};
  double runNum[100] = {573, 574, 576, 577, 578, 540};
  double tempIrradAll[100] = {aveAllts12Irrad573, aveAllts12Irrad574, aveAllts12Irrad576, aveAllts12Irrad577, aveAllts12Irrad578, aveAllts12Irrad540};
  double tempErrIrradAll[100] = {aveAllErrts12Irrad573,  aveAllErrts12Irrad574,  aveAllErrts12Irrad575,  aveAllErrts12Irrad577,  aveAllErrts12Irrad578,  aveAllErrts12Irrad538};
  */
  TCanvas *cStorage = new TCanvas ("cStorage" , "cStorage" , 800, 400);
  cStorage-> SetLogy();
  TGraphErrors *grAll = new TGraphErrors (counts_573 +counts_574 +counts_575 +counts_576 +counts_577 +counts_578+counts_580 +counts_579 + counts_581 , delayTimeAll, UCNIntegralArrayAll , 0, UCNIntegralErrArrayAll);
  TGraphErrors *grAllHist = new TGraphErrors (counts_573 +counts_574 +counts_575 +counts_576 +counts_577 +counts_578 +counts_579+counts_580+ counts_581 , delayTimeAll, HistIntegralArrayAll , 0, HistIntegralErrArrayAll);
  grAllHist -> SetMarkerStyle(7);
  grAllHist -> SetMarkerColor(2);

  
  grAll -> SetTitle("UCN Count vs cycle Delay Time ");
  grAll -> GetYaxis()-> SetTitle("UCN Count" );
  grAll -> GetXaxis()-> SetTitle("Cycle Delay Time (s)");
  grAll -> GetYaxis()-> SetRangeUser(1, 500000);
  grAll -> GetXaxis()-> SetLimits(0 ,180);
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> Fit(fit);

  grAll -> SetMarkerStyle(7);
  grAll -> Draw("Ap");
  grAllHist -> Draw("p");
  




}
