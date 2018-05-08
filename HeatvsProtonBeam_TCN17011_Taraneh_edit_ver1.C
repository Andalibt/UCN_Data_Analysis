// *********************************************************
// THIS SCRIPT IS FOR THE ANALYSIS OF TCN17011 WHICH IS THE
// COMPARISON BETWEEN THE PROTON BEAM CURRENT AND THE HEATER
// POWERS.
// Taraneh Andalib April 27, 2018
// *********************************************************

#define max 1000000

void HeatvsProtonBeam_TCN17011_Taraneh_edit_ver1(){

  // LOADING THE MIDAS ROOT FILES ...
  TFile *fin765 = new TFile ("~/raw_Data/ucn_tree_00000765.root", "READ");
  TFile *fin766 = new TFile ("~/raw_Data/ucn_tree_00000766.root", "READ");
  TFile *fin767 = new TFile ("~/raw_Data/ucn_tree_00000767.root", "READ");
  TFile *fin768 = new TFile ("~/raw_Data/ucn_tree_00000768.root", "READ");
  TFile *fin769 = new TFile ("~/raw_Data/ucn_tree_00000769.root", "READ");
  TFile *fin770 = new TFile ("~/raw_Data/ucn_tree_00000770.root", "READ");
  TFile *fin771 = new TFile ("~/raw_Data/ucn_tree_00000771.root", "READ");
  TFile *fin772 = new TFile ("~/raw_Data/ucn_tree_00000772.root", "READ");
  TFile *fin773 = new TFile ("~/raw_Data/ucn_tree_00000773.root", "READ");
  TFile *fin778 = new TFile ("~/raw_Data/ucn_tree_00000778.root", "READ");
  TFile *fin779 = new TFile ("~/raw_Data/ucn_tree_00000779.root", "READ");


  // READING THE UCN HIT Li6 TREE
  TTree *uinli6765 = (TTree*) fin765 -> Get("UCNHits_Li-6");
  TTree *uinli6766 = (TTree*) fin766 -> Get("UCNHits_Li-6");
  TTree *uinli6767 = (TTree*) fin767 -> Get("UCNHits_Li-6");
  TTree *uinli6768 = (TTree*) fin768 -> Get("UCNHits_Li-6");
  TTree *uinli6769 = (TTree*) fin769 -> Get("UCNHits_Li-6");
  TTree *uinli6770 = (TTree*) fin770 -> Get("UCNHits_Li-6");
  TTree *uinli6771 = (TTree*) fin771 -> Get("UCNHits_Li-6");
  TTree *uinli6772 = (TTree*) fin772 -> Get("UCNHits_Li-6");
  TTree *uinli6773 = (TTree*) fin773 -> Get("UCNHits_Li-6");
  TTree *uinli6778 = (TTree*) fin778 -> Get("UCNHits_Li-6");
  TTree *uinli6779 = (TTree*) fin779 -> Get("UCNHits_Li-6");


  // READING THE BEAMLINE TREE
  TTree *bl765 = (TTree*) fin765 -> Get("BeamlineEpicsTree");
  TTree *bl766 = (TTree*) fin766 -> Get("BeamlineEpicsTree");
  TTree *bl767 = (TTree*) fin767 -> Get("BeamlineEpicsTree");
  TTree *bl768 = (TTree*) fin768 -> Get("BeamlineEpicsTree");
  TTree *bl769 = (TTree*) fin769 -> Get("BeamlineEpicsTree");
  TTree *bl770 = (TTree*) fin770 -> Get("BeamlineEpicsTree");
  TTree *bl771 = (TTree*) fin771 -> Get("BeamlineEpicsTree");
  TTree *bl772 = (TTree*) fin772 -> Get("BeamlineEpicsTree");
  TTree *bl773 = (TTree*) fin773 -> Get("BeamlineEpicsTree");
  TTree *bl778 = (TTree*) fin778 -> Get("BeamlineEpicsTree");
  TTree *bl779 = (TTree*) fin779 -> Get("BeamlineEpicsTree");


  // READING THE EPICS TREE
  TTree *sourceEpics765 = (TTree*) fin765 -> Get("SourceEpicsTree");
  TTree *sourceEpics766 = (TTree*) fin766 -> Get("SourceEpicsTree");
  TTree *sourceEpics767 = (TTree*) fin767 -> Get("SourceEpicsTree");
  TTree *sourceEpics768 = (TTree*) fin768 -> Get("SourceEpicsTree");
  TTree *sourceEpics769 = (TTree*) fin769 -> Get("SourceEpicsTree");
  TTree *sourceEpics770 = (TTree*) fin770 -> Get("SourceEpicsTree");
  TTree *sourceEpics771 = (TTree*) fin771 -> Get("SourceEpicsTree");
  TTree *sourceEpics772 = (TTree*) fin772 -> Get("SourceEpicsTree");
  TTree *sourceEpics773 = (TTree*) fin773 -> Get("SourceEpicsTree");
  TTree *sourceEpics778 = (TTree*) fin778 -> Get("SourceEpicsTree");
  TTree *sourceEpics779 = (TTree*) fin779 -> Get("SourceEpicsTree");


  // VARIABLES FOR THE Li6 COUNTS TREE
  double tUnixTimePrecise765;
  double tUnixTimePrecise766;
  double tUnixTimePrecise767;
  double tUnixTimePrecise768;
  double tUnixTimePrecise769;
  double tUnixTimePrecise770;
  double tUnixTimePrecise771;
  double tUnixTimePrecise772;
  double tUnixTimePrecise773;
  double tUnixTimePrecise778;
  double tUnixTimePrecise779;

  uinli6765 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise765);
  uinli6766 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise766);
  uinli6767 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise767);
  uinli6768 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise768);
  uinli6769 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise769);
  uinli6770 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise770);
  uinli6771 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise771);
  uinli6772 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise772);
  uinli6773 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise773);
  uinli6778 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise778);
  uinli6779 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise779);

  

  double tUnixTime765;
  double tUnixTime766;
  double tUnixTime767;
  double tUnixTime768;
  double tUnixTime769;
  double tUnixTime770;
  double tUnixTime771;
  double tUnixTime772;
  double tUnixTime773;
  double tUnixTime778;
  double tUnixTime779;

  uinli6765 -> SetBranchAddress ("tUnixTime" , &tUnixTime765);
  uinli6766 -> SetBranchAddress ("tUnixTime" , &tUnixTime766);
  uinli6767 -> SetBranchAddress ("tUnixTime" , &tUnixTime767);
  uinli6768 -> SetBranchAddress ("tUnixTime" , &tUnixTime768);
  uinli6769 -> SetBranchAddress ("tUnixTime" , &tUnixTime769);
  uinli6770 -> SetBranchAddress ("tUnixTime" , &tUnixTime770);
  uinli6771 -> SetBranchAddress ("tUnixTime" , &tUnixTime771);
  uinli6772 -> SetBranchAddress ("tUnixTime" , &tUnixTime772);
  uinli6773 -> SetBranchAddress ("tUnixTime" , &tUnixTime773);
  uinli6778 -> SetBranchAddress ("tUnixTime" , &tUnixTime778);
  uinli6779 -> SetBranchAddress ("tUnixTime" , &tUnixTime779);
  
  UShort_t tIsUCN765;
  UShort_t tIsUCN766;
  UShort_t tIsUCN767;
  UShort_t tIsUCN768;
  UShort_t tIsUCN769;
  UShort_t tIsUCN770;
  UShort_t tIsUCN771;
  UShort_t tIsUCN772;
  UShort_t tIsUCN773;
  UShort_t tIsUCN778;
  UShort_t tIsUCN779;


  uinli6765 -> SetBranchAddress ("tIsUCN" , &tIsUCN765);
  uinli6766 -> SetBranchAddress ("tIsUCN" , &tIsUCN766);
  uinli6767 -> SetBranchAddress ("tIsUCN" , &tIsUCN767);
  uinli6768 -> SetBranchAddress ("tIsUCN" , &tIsUCN768);
  uinli6769 -> SetBranchAddress ("tIsUCN" , &tIsUCN769);
  uinli6770 -> SetBranchAddress ("tIsUCN" , &tIsUCN770);
  uinli6771 -> SetBranchAddress ("tIsUCN" , &tIsUCN771);
  uinli6772 -> SetBranchAddress ("tIsUCN" , &tIsUCN772);
  uinli6773 -> SetBranchAddress ("tIsUCN" , &tIsUCN773);
  uinli6778 -> SetBranchAddress ("tIsUCN" , &tIsUCN778);
  uinli6779 -> SetBranchAddress ("tIsUCN" , &tIsUCN779);

  ULong64_t ucnli6Events765 = (Double_t) uinli6765 -> GetEntries(); //Total events of the UCNHits_Li-6 tree
  ULong64_t ucnli6Events766 = (Double_t) uinli6766 -> GetEntries();
  ULong64_t ucnli6Events767 = (Double_t) uinli6767 -> GetEntries();
  ULong64_t ucnli6Events768 = (Double_t) uinli6768 -> GetEntries();
  ULong64_t ucnli6Events769 = (Double_t) uinli6769 -> GetEntries();
  ULong64_t ucnli6Events770 = (Double_t) uinli6770 -> GetEntries();
  ULong64_t ucnli6Events771 = (Double_t) uinli6771 -> GetEntries();
  ULong64_t ucnli6Events772 = (Double_t) uinli6772 -> GetEntries();
  ULong64_t ucnli6Events773 = (Double_t) uinli6773 -> GetEntries();
  ULong64_t ucnli6Events778 = (Double_t) uinli6778 -> GetEntries();
  ULong64_t ucnli6Events779 = (Double_t) uinli6779 -> GetEntries();



  //**************************************
  // VARIALBES FOR THE BEAMLINE TREE
  //**************************************
  
  double cur765;
  double cur766;
  double cur767;
  double cur768;
  double cur769;
  double cur770;
  double cur771;
  double cur772;
  double cur773;
  double cur778;
  double cur779;

  bl765 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur765);
  bl766 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur766);
  bl767 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur767);
  bl768 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur768);
  bl769 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur769);
  bl770 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur770);
  bl771 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur771);
  bl772 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur772);
  bl773 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur773);
  bl778 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur778);
  bl779 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur779);
  

  double curArray765[max];
  double curArray766[max];
  double curArray767[max];
  double curArray768[max];
  double curArray769[max];
  double curArray770[max];
  double curArray771[max];
  double curArray772[max];
  double curArray773[max];
  double curArray778[max];
  double curArray779[max];

  double curAve765;
  double curAve766;
  double curAve767;
  double curAve768;
  double curAve769;
  double curAve770;
  double curAve771;
  double curAve772;
  double curAve773;
  double curAve778;
  double curAve779;

  int timestamp_bl765;
  int timestamp_bl766;
  int timestamp_bl767;
  int timestamp_bl768;
  int timestamp_bl769;
  int timestamp_bl770;
  int timestamp_bl771;
  int timestamp_bl772;
  int timestamp_bl773;
  int timestamp_bl778;
  int timestamp_bl779;

  bl765 -> SetBranchAddress ("timestamp" , &timestamp_bl765);
  bl766 -> SetBranchAddress ("timestamp" , &timestamp_bl766);
  bl767 -> SetBranchAddress ("timestamp" , &timestamp_bl767);
  bl768 -> SetBranchAddress ("timestamp" , &timestamp_bl768);
  bl769 -> SetBranchAddress ("timestamp" , &timestamp_bl769);
  bl770 -> SetBranchAddress ("timestamp" , &timestamp_bl770);
  bl771 -> SetBranchAddress ("timestamp" , &timestamp_bl771);
  bl772 -> SetBranchAddress ("timestamp" , &timestamp_bl772);
  bl773 -> SetBranchAddress ("timestamp" , &timestamp_bl773);
  bl778 -> SetBranchAddress ("timestamp" , &timestamp_bl778);
  bl779 -> SetBranchAddress ("timestamp" , &timestamp_bl779);
  

  double TSblArray765[max];
  double TSblArray766[max];
  double TSblArray767[max];
  double TSblArray768[max];
  double TSblArray769[max];
  double TSblArray770[max];
  double TSblArray771[max];
  double TSblArray772[max];
  double TSblArray773[max];
  double TSblArray778[max];
  double TSblArray779[max];

  ULong64_t blEvent765 = (Double_t) bl765 -> GetEntries();  //Total number of events in the beamline tree
  ULong64_t blEvent766 = (Double_t) bl766 -> GetEntries();  
  ULong64_t blEvent767 = (Double_t) bl767 -> GetEntries();  
  ULong64_t blEvent768 = (Double_t) bl768 -> GetEntries();
  ULong64_t blEvent769 = (Double_t) bl769 -> GetEntries();  
  ULong64_t blEvent770 = (Double_t) bl770 -> GetEntries();  
  ULong64_t blEvent771 = (Double_t) bl771 -> GetEntries();  
  ULong64_t blEvent772 = (Double_t) bl772 -> GetEntries();  
  ULong64_t blEvent773 = (Double_t) bl773 -> GetEntries();  
  ULong64_t blEvent778 = (Double_t) bl778 -> GetEntries();  
  ULong64_t blEvent779 = (Double_t) bl779 -> GetEntries();  

  
  
  
  //**************************************
  // VARIABLES FOR EPICS TREE
  //**************************************

  double ts12765; // TS12 temperature sensor
  double ts12766;
  double ts12767;
  double ts12768;
  double ts12769;
  double ts12770;
  double ts12771;
  double ts12772;
  double ts12773;
  double ts12778;
  double ts12779;

  sourceEpics765 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12765);
  sourceEpics766 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12766);
  sourceEpics767 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12767);
  sourceEpics768 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12768);
  sourceEpics769 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12769);
  sourceEpics770 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12770);
  sourceEpics771 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12771);
  sourceEpics772 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12772);
  sourceEpics773 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12773);
  sourceEpics778 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12778);
  sourceEpics779 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12779);
  
  

  double ts12Ave765; // TS12 average
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;
  double ts12Ave765;

  double tempArray765[max];
  double tempArray766[max];
  double tempArray767[max];
  double tempArray768[max];
  double tempArray769[max];
  double tempArray770[max];
  double tempArray771[max];
  double tempArray772[max];
  double tempArray773[max];
  double tempArray778[max];
  double tempArray779[max];
  
  

  int timestamp_se765; // timestamp for the source epics
  int timestamp_se766;
  int timestamp_se767;
  int timestamp_se768;
  int timestamp_se769;
  int timestamp_se770;
  int timestamp_se771;
  int timestamp_se772;
  int timestamp_se773;
  int timestamp_se778;
  int timestamp_se779;

  sourceEpics765 -> SetBranchAddress ("timestamp" , &timestamp_se765);
  sourceEpics766 -> SetBranchAddress ("timestamp" , &timestamp_se766);
  sourceEpics767 -> SetBranchAddress ("timestamp" , &timestamp_se767);
  sourceEpics768 -> SetBranchAddress ("timestamp" , &timestamp_se768);
  sourceEpics769 -> SetBranchAddress ("timestamp" , &timestamp_se769);
  sourceEpics770 -> SetBranchAddress ("timestamp" , &timestamp_se770);
  sourceEpics771 -> SetBranchAddress ("timestamp" , &timestamp_se771);
  sourceEpics772 -> SetBranchAddress ("timestamp" , &timestamp_se772);
  sourceEpics773 -> SetBranchAddress ("timestamp" , &timestamp_se773);
  sourceEpics778 -> SetBranchAddress ("timestamp" , &timestamp_se778);
  sourceEpics779 -> SetBranchAddress ("timestamp" , &timestamp_se779);

  
  
  double TSseArray765[max]; // timestamp array for the source epics
  double TSseArray766[max];
  double TSseArray767[max];
  double TSseArray768[max];
  double TSseArray769[max];
  double TSseArray770[max];
  double TSseArray771[max];
  double TSseArray772[max];
  double TSseArray773[max];
  double TSseArray778[max];
  double TSseArray779[max];


  double FM1765; // Flow of the He3 gas (FM1)
  double FM1766;    
  double FM1767;    
  double FM1768;    
  double FM1769;    
  double FM1770;    
  double FM1771;    
  double FM1772;    
  double FM1773;    
  double FM1778;    
  double FM1779;    

  sourceEpics765 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics766 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics767 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics768 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics769 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics770 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics771 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics772 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics773 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics778 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);
  sourceEpics779 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1765);


  double FM1Array765[max];
  double FM1Array766[max];
  double FM1Array767[max];
  double FM1Array768[max];
  double FM1Array769[max];
  double FM1Array770[max];
  double FM1Array771[max];
  double FM1Array772[max];
  double FM1Array773[max];
  double FM1Array778[max];
  double FM1Array779[max];
  

  double FM4765; //Flow rate in the 4K reservoir (chimney)
  double FM4766;
  double FM4767;
  double FM4768;
  double FM4769;
  double FM4770;
  double FM4771;
  double FM4772;
  double FM4773;
  double FM4778;
  double FM4779;

  sourceEpics765 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4765);
  sourceEpics766 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4766);
  sourceEpics767 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4767);
  sourceEpics768 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4768);
  sourceEpics769 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4769);
  sourceEpics770 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4770);
  sourceEpics771 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4771);
  sourceEpics772 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4772);
  sourceEpics773 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4773);
  sourceEpics778 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4778);
  sourceEpics779 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4779);

  double FM4Array765[max];
  double FM4Array766[max];
  double FM4Array767[max];
  double FM4Array768[max];
  double FM4Array769[max];
  double FM4Array770[max];
  double FM4Array771[max];
  double FM4Array772[max];
  double FM4Array773[max];
  double FM4Array778[max];
  double FM4Array779[max];




  double FM5765; // Flow rate of the 4K reservoir
  double FM5766;
  double FM5767;
  double FM5768;
  double FM5769;
  double FM5770;
  double FM5771;
  double FM5772;
  double FM5773;
  double FM5778;
  double FM5779;
  

  sourceEpics765 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5765);
  sourceEpics766 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5766);
  sourceEpics767 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5767);
  sourceEpics768 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5768);
  sourceEpics769 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5769);
  sourceEpics770 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5770);
  sourceEpics771 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5771);
  sourceEpics772 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5772);
  sourceEpics773 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5773);
  sourceEpics778 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5778);
  sourceEpics779 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5779);

  double FM5Array765[max];
  double FM5Array766[max];
  double FM5Array767[max];
  double FM5Array768[max];
  double FM5Array769[max];
  double FM5Array770[max];
  double FM5Array771[max];
  double FM5Array772[max];
  double FM5Array773[max];
  double FM5Array778[max];
  double FM5Array779[max];

  ULong64_t seEvents765 = sourceEpics765 -> GetEntries(); // Total number of events in Source Epics tree
  ULong64_t seEvents766 = sourceEpics766 -> GetEntries();
  ULong64_t seEvents767 = sourceEpics767 -> GetEntries();
  ULong64_t seEvents768 = sourceEpics768 -> GetEntries();
  ULong64_t seEvents769 = sourceEpics769 -> GetEntries();
  ULong64_t seEvents770 = sourceEpics770 -> GetEntries();
  ULong64_t seEvents771 = sourceEpics771 -> GetEntries();
  ULong64_t seEvents772 = sourceEpics772 -> GetEntries();
  ULong64_t seEvents773 = sourceEpics773 -> GetEntries();
  ULong64_t seEvents778 = sourceEpics778 -> GetEntries();
  ULong64_t seEvents779 = sourceEpics779 -> GetEntries();



  // *******************************************************************************
  // FILLING THE HISTOGRAMS
  // *******************************************************************************

  int NBins765 = 1; // Total number of bins for the run 765
  int NBins766 = 1;
  int NBins767 = 1;
  int NBins768 = 1;
  int NBins769 = 1;
  int NBins770 = 1;
  int NBins771 = 1;
  int NBins772 = 1;
  int NBins773 = 1;
  int NBins778 = 1;
  int NBins779 = 1;

  int BinWidth = 1;
  

  int maxXrange765 = 0, minXrange765 = 1540000000.; // max and min range to draw the histogram 
  int maxXrange766 = 0, minXrange766 = 1540000000.;
  int maxXrange767 = 0, minXrange767 = 1540000000.;
  int maxXrange768 = 0, minXrange768 = 1540000000.;
  int maxXrange769 = 0, minXrange769 = 1540000000.;
  int maxXrange770 = 0, minXrange770 = 1540000000.;
  int maxXrange771 = 0, minXrange771 = 1540000000.;
  int maxXrange772 = 0, minXrange772 = 1540000000.;
  int maxXrange773 = 0, minXrange773 = 1540000000.;
  int maxXrange778 = 0, minXrange778 = 1540000000.;
  int maxXrange779 = 0, minXrange779 = 1540000000.;

  

  TH1* UCNRate765 = new TH1F("UCNRate765", "UCN-rate Histogram", NBins765 , minXrange765, maxXrange765); // defining the rate histogram for each run
  TH1* UCNRate766 = new TH1F("UCNRate766", "UCN-rate Histogram", NBins766 , minXrange766, maxXrange766);
  TH1* UCNRate767 = new TH1F("UCNRate767", "UCN-rate Histogram", NBins767 , minXrange767, maxXrange767);
  TH1* UCNRate768 = new TH1F("UCNRate768", "UCN-rate Histogram", NBins768 , minXrange768, maxXrange768);
  TH1* UCNRate769 = new TH1F("UCNRate769", "UCN-rate Histogram", NBins769 , minXrange769, maxXrange769);
  TH1* UCNRate770 = new TH1F("UCNRate770", "UCN-rate Histogram", NBins770 , minXrange770, maxXrange770);
  TH1* UCNRate771 = new TH1F("UCNRate771", "UCN-rate Histogram", NBins771 , minXrange771, maxXrange771);
  TH1* UCNRate772 = new TH1F("UCNRate772", "UCN-rate Histogram", NBins772 , minXrange772, maxXrange772);
  TH1* UCNRate773 = new TH1F("UCNRate773", "UCN-rate Histogram", NBins773 , minXrange773, maxXrange773);
  TH1* UCNRate778 = new TH1F("UCNRate778", "UCN-rate Histogram", NBins778 , minXrange778, maxXrange778);
  TH1* UCNRate779 = new TH1F("UCNRate779", "UCN-rate Histogram", NBins779 , minXrange779, maxXrange779);


  //***************************************
  // get the max and min for each run
  //***************************************
 
  // run 765
  for(ULong64_t j = 0 ; j < blEvent765 ;j++) {
    bl765 -> GetEvent(j);
    if (timestamp_bl765 < minXrange765 ){
      minXrange765 = timestamp_bl765;
    }
    if (timestamp_bl765 > maxXrange765){
      maxXrange765 = timestamp_bl765;
    }
  }
  
  // run 766
  for(ULong64_t j = 0 ; j < blEvent766 ;j++) {
    bl766 -> GetEvent(j);
    if (timestamp_bl766 < minXrange766 ){
      minXrange766 = timestamp_bl766;
    }
    if (timestamp_bl766 > maxXrange766){
      maxXrange766 = timestamp_bl766;
    }
  }
  

  //run767
  for(ULong64_t j = 0 ; j < blEvent767 ;j++) {
    bl767 -> GetEvent(j);
    if (timestamp_bl767 < minXrange767 ){
      minXrange767 = timestamp_bl767;
    }
    if (timestamp_bl767 > maxXrange767){
      maxXrange767 = timestamp_bl767;
    }
  }
  
  //run 768
  for(ULong64_t j = 0 ; j < blEvent768 ;j++) {
    bl768 -> GetEvent(j);
    if (timestamp_bl768 < minXrange768 ){
      minXrange768 = timestamp_bl768;
    }
    if (timestamp_bl768 > maxXrange768){
      maxXrange768 = timestamp_bl768;
    }
  }
  
  // run 769
  for(ULong64_t j = 0 ; j < blEvent769 ;j++) {
    bl769 -> GetEvent(j);
    if (timestamp_bl769 < minXrange769 ){
      minXrange769 = timestamp_bl769;
    }
    if (timestamp_bl769 > maxXrange769){
      maxXrange769 = timestamp_bl769;
    }
  }
  
  //run 770
  for(ULong64_t j = 0 ; j < blEvent770 ;j++) {
    bl770 -> GetEvent(j);
    if (timestamp_bl770 < minXrange770 ){
      minXrange770 = timestamp_bl770;
    }
    if (timestamp_bl770 > maxXrange770){
      maxXrange770 = timestamp_bl770;
    }
  }

  //run 771
  for(ULong64_t j = 0 ; j < blEvent771 ;j++) {
    bl771 -> GetEvent(j);
    if (timestamp_bl771 < minXrange771 ){
      minXrange771 = timestamp_bl771;
    }
    if (timestamp_bl771 > maxXrange771){
      maxXrange771 = timestamp_bl771;
    }
  }

  //run 772
  for(ULong64_t j = 0 ; j < blEvent772 ;j++) {
    bl772 -> GetEvent(j);
    if (timestamp_bl772 < minXrange772 ){
      minXrange772 = timestamp_bl772;
    }
    if (timestamp_bl772 > maxXrange772){
      maxXrange772 = timestamp_bl772;
    }
  }

  //run773
  for(ULong64_t j = 0 ; j < blEvent773 ;j++) {
    bl773 -> GetEvent(j);
    if (timestamp_bl773 < minXrange773 ){
      minXrange773 = timestamp_bl773;
    }
    if (timestamp_bl773 > maxXrange773){
      maxXrange773 = timestamp_bl773;
    }
  }

  //run778
  for(ULong64_t j = 0 ; j < blEvent778 ;j++) {
    bl778 -> GetEvent(j);
    if (timestamp_bl778 < minXrange778 ){
      minXrange778 = timestamp_bl778;
    }
    if (timestamp_bl778 > maxXrange778){
      maxXrange778 = timestamp_bl778;
    }
  }
  
  //run 779
  for(ULong64_t j = 0 ; j < blEvent779 ;j++) {
    bl779 -> GetEvent(j);
    if (timestamp_bl779 < minXrange779 ){
      minXrange779 = timestamp_bl779;
    }
    if (timestamp_bl779 > maxXrange779){
      maxXrange779 = timestamp_bl779;
    }
  }
  // setting the bin numbers
  
  NBins765 = (maxXrange765 - minXrange765)/BinWidth ;
  NBins766 = (maxXrange766 - minXrange766 )/BinWidth ;
  NBins767 = (maxXrange767 - minXrange767 )/BinWidth ;
  NBins768 = (maxXrange768 - minXrange768 )/BinWidth ;
  NBins769 = (maxXrange769 - minXrange769 )/BinWidth ;
  NBins770 = (maxXrange770 - minXrange770 )/BinWidth ;
  NBins771 = (maxXrange771 - minXrange771 )/BinWidth ;
  NBins772 = (maxXrange772 - minXrange772 )/BinWidth ;
  NBins773 = (maxXrange773 - minXrange773 )/BinWidth ;
  NBins778 = (maxXrange778 - minXrange778 )/BinWidth ;
  NBins779 = (maxXrange779 - minXrange779 )/BinWidth ;

  UCNRate765 -> Reset();
  UCNRate766 -> Reset();
  UCNRate767 -> Reset();
  UCNRate768 -> Reset();
  UCNRate769 -> Reset();
  UCNRate770 -> Reset();
  UCNRate771 -> Reset();
  UCNRate772 -> Reset();
  UCNRate773 -> Reset();
  UCNRate778 -> Reset();
  UCNRate779 -> Reset();
  
  UCNRate765 -> SetBins(NBins765 , minXrange765 , maxXrange765);
  UCNRate766 -> SetBins(NBins766 , minXrange766 , maxXrange766);
  UCNRate767 -> SetBins(NBins767 , minXrange767 , maxXrange767);
  UCNRate768 -> SetBins(NBins768 , minXrange768 , maxXrange768);
  UCNRate769 -> SetBins(NBins769 , minXrange769 , maxXrange769);
  UCNRate770 -> SetBins(NBins770 , minXrange770 , maxXrange770);
  UCNRate771 -> SetBins(NBins771 , minXrange771 , maxXrange771);
  UCNRate772 -> SetBins(NBins772 , minXrange772 , maxXrange772);
  UCNRate773 -> SetBins(NBins773 , minXrange773 , maxXrange773);
  UCNRate778 -> SetBins(NBins778 , minXrange778 , maxXrange778);
  UCNRate779 -> SetBins(NBins779 , minXrange779 , maxXrange779);

  // filling the histogram

  //run 765
  for (ULong64_t j = 0 ; j < ucnli6Events765; j++){
    uinli6765 -> GetEvent(j);
    if (tUnixTimePrecise765 > 20e6 && tIsUCN765 > 0){
      UCNRate765 -> Fill(tUnixTimePrecise765);
    }
  }

  //run 766
  for (ULong64_t j = 0 ; j < ucnli6Events766; j++){
    uinli6766 -> GetEvent(j);
    if (tUnixTimePrecise766 > 20e6 && tIsUCN766 > 0){
      UCNRate766 -> Fill(tUnixTimePrecise766);
    }
  }

  //run 767
  for (ULong64_t j = 0 ; j < ucnli6Events767 ; j++){
    uinli6767 -> GetEvent(j);
    if (tUnixTimePrecise767 > 20e6 && tIsUCN767 > 0){
      UCNRate767 -> Fill(tUnixTimePrecise767);
    }
  }

  //run 768
  for (ULong64_t j = 0 ; j < ucnli6Events768; j++){
    uinli6768 -> GetEvent(j);
    if (tUnixTimePrecise768 > 20e6 && tIsUCN768 > 0){
      UCNRate768 -> Fill(tUnixTimePrecise768);
    }
  }

  //run 769
  for (ULong64_t j = 0 ; j < ucnli6Events769; j++){
    uinli6769 -> GetEvent(j);
    if (tUnixTimePrecise769 > 20e6 && tIsUCN769 > 0){
      UCNRate769 -> Fill(tUnixTimePrecise769);
    }
  }

  //run 770
  for (ULong64_t j = 0 ; j < ucnli6Events770; j++){
    uinli6770 -> GetEvent(j);
    if (tUnixTimePrecise770 > 20e6 && tIsUCN770 > 0){
      UCNRate770 -> Fill(tUnixTimePrecise770);
    }
  }

  //run 771
  for (ULong64_t j = 0 ; j < ucnli6Events771; j++){
    uinli6771 -> GetEvent(j);
    if (tUnixTimePrecise771 > 20e6 && tIsUCN771 > 0){
      UCNRate771 -> Fill(tUnixTimePrecise771);
    }
  }

  //run 772
  for (ULong64_t j = 0 ; j < ucnli6Events772; j++){
    uinli6772 -> GetEvent(j);
    if (tUnixTimePrecise772 > 20e6 && tIsUCN772 > 0){
      UCNRate772 -> Fill(tUnixTimePrecise772);
    }
  }

  //run 773
  for (ULong64_t j = 0 ; j < ucnli6Events773; j++){
    uinli6773 -> GetEvent(j);
    if (tUnixTimePrecise773 > 20e6 && tIsUCN773 > 0){
      UCNRate773 -> Fill(tUnixTimePrecise773);
    }
  }

  //run 778
  for (ULong64_t j = 0 ; j < ucnli6Events778; j++){
    uinli6778 -> GetEvent(j);
    if (tUnixTimePrecise778 > 20e6 && tIsUCN778 > 0){
      UCNRate778 -> Fill(tUnixTimePrecise778);
    }
  }

  //run 779
  for (ULong64_t j = 0 ; j < ucnli6Events779; j++){
    uinli6779 -> GetEvent(j);
    if (tUnixTimePrecise779 > 20e6 && tIsUCN779 > 0){
      UCNRate779 -> Fill(tUnixTimePrecise779);
    }
  }

  // ***************************
  // graph the UCN rate
  // **************************

  //run 765
  TCanvas *cRate765 = new TCanvas ("cRate765" , "cRate765" , 1200 , 900);
  UCNRate765 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate765 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate765 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate765 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate765 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate765 -> Draw();

  //run 766
  TCanvas *cRate766 = new TCanvas ("cRate766" , "cRate766" , 1200 , 900);
  UCNRate766 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate766 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate766 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate766 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate766 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate766 -> Draw();

  //run 767
  TCanvas *cRate767 = new TCanvas ("cRate767" , "cRate767" , 1200 , 900);
  UCNRate767 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate767 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate767 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate767 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate767 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate767 -> Draw();

  //run 768
  TCanvas *cRate768 = new TCanvas ("cRate768" , "cRate768" , 1200 , 900);
  UCNRate768 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate768 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate768 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate768 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate768 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate768 -> Draw();

  //run 769
  TCanvas *cRate769 = new TCanvas ("cRate769" , "cRate769" , 1200 , 900);
  UCNRate769 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate769 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate769 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate769 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate769 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate769 -> Draw();

  //run 770
  TCanvas *cRate770 = new TCanvas ("cRate770" , "cRate770" , 1200 , 900);
  UCNRate770 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate770 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate770 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate770 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate770 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate770 -> Draw();


  //run 771
  TCanvas *cRate771 = new TCanvas ("cRate771" , "cRate771" , 1200 , 900);
  UCNRate771 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate771 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate771 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate771 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate771 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate771 -> Draw();

  //run 772
  TCanvas *cRate772 = new TCanvas ("cRate772" , "cRate772" , 1200 , 900);
  UCNRate772 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate772 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate772 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate772 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate772 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate772 -> Draw();

  //run 773
  TCanvas *cRate773 = new TCanvas ("cRate773" , "cRate773" , 1200 , 900);
  UCNRate773 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate773 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate773 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate773 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate773 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate773 -> Draw();

  //run 778
  TCanvas *cRate778 = new TCanvas ("cRate778" , "cRate778" , 1200 , 900);
  UCNRate778 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate778 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate778 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate778 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate778 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate778 -> Draw();

  //run 779
  TCanvas *cRate779 = new TCanvas ("cRate779" , "cRate779" , 1200 , 900);
  UCNRate779 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate779 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate779 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate779 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate779 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate779 -> Draw();

  // *****************************************************************
  // Loop to put the source Epics stuff in arrays
  // *****************************************************************

  // run 765
  for (ULong64_t j = 0 ; j < seEvents765 ; j++){
    sourceEpics765 -> GetEvent(j);
    TSseArray765[j] = timestamp_se765;
    tempArray765[j] = ts12765;
    FM1Array765[j] = FM1765;
    FM4Array765[j] = FM4765;
    FM5Array765[j] = FM5765;
  }

  //run 766
  for (ULong64_t j = 0 ; j < seEvents766 ; j++){
    sourceEpics766 -> GetEvent(j);
    TSseArray766[j] = timestamp_se766;
    tempArray766[j] = ts12766;
    FM1Array766[j] = FM1766;
    FM4Array766[j] = FM4766;
    FM5Array766[j] = FM5766;
  }

  //run 767
  for (ULong64_t j = 0 ; j < seEvents767 ; j++){
    sourceEpics767 -> GetEvent(j);
    TSseArray767[j] = timestamp_se767;
    tempArray767[j] = ts12767;
    FM1Array767[j] = FM1767;
    FM4Array767[j] = FM4767;
    FM5Array767[j] = FM5767;
  }

  //run 768
  for (ULong64_t j = 0 ; j < seEvents768 ; j++){
    sourceEpics768 -> GetEvent(j);
    TSseArray768[j] = timestamp_se768;
    tempArray768[j] = ts12768;
    FM1Array768[j] = FM1768;
    FM4Array768[j] = FM4768;
    FM5Array768[j] = FM5768;
  }

  //run 769
  for (ULong64_t j = 0 ; j < seEvents769 ; j++){
    sourceEpics769 -> GetEvent(j);
    TSseArray769[j] = timestamp_se769;
    tempArray769[j] = ts12769;
    FM1Array769[j] = FM1769;
    FM4Array769[j] = FM4769;
    FM5Array769[j] = FM5769;
  }

  //run 770
  for (ULong64_t j = 0 ; j < seEvents770 ; j++){
    sourceEpics770 -> GetEvent(j);
    TSseArray770[j] = timestamp_se770;
    tempArray770[j] = ts12770;
    FM1Array770[j] = FM1770;
    FM4Array770[j] = FM4770;
    FM5Array770[j] = FM5770;
  }

  //run 771
  for (ULong64_t j = 0 ; j < seEvents771 ; j++){
    sourceEpics771 -> GetEvent(j);
    TSseArray771[j] = timestamp_se771;
    tempArray771[j] = ts12771;
    FM1Array771[j] = FM1771;
    FM4Array771[j] = FM4771;
    FM5Array771[j] = FM5771;
  }
  
  //run 772
  for (ULong64_t j = 0 ; j < seEvents772 ; j++){
    sourceEpics772 -> GetEvent(j);
    TSseArray772[j] = timestamp_se772;
    tempArray772[j] = ts12772;
    FM1Array772[j] = FM1772;
    FM4Array772[j] = FM4772;
    FM5Array772[j] = FM5772;
  }

  //run 773
  for (ULong64_t j = 0 ; j < seEvents773 ; j++){
    sourceEpics773 -> GetEvent(j);
    TSseArray773[j] = timestamp_se773;
    tempArray773[j] = ts12773;
    FM1Array773[j] = FM1773;
    FM4Array773[j] = FM4773;
    FM5Array773[j] = FM5773;
  }

  //run 778
  for (ULong64_t j = 0 ; j < seEvents778 ; j++){
    sourceEpics778 -> GetEvent(j);
    TSseArray778[j] = timestamp_se778;
    tempArray778[j] = ts12778;
    FM1Array778[j] = FM1778;
    FM4Array778[j] = FM4778;
    FM5Array778[j] = FM5778;
  }

  //run 779
  for (ULong64_t j = 0 ; j < seEvents779 ; j++){
    sourceEpics779 -> GetEvent(j);
    TSseArray779[j] = timestamp_se779;
    tempArray779[j] = ts12779;
    FM1Array779[j] = FM1779;
    FM4Array779[j] = FM4779;
    FM5Array779[j] = FM5779;
  }


  // **********************************
  // graph the temperature and flow
  // **********************************

  //run 765
  TCanvas *cSource765 = new TCanvas("cSource765" , "cSource765" , 1200, 900);
  // TGraph *grtemp765 = new TGraph(seEvents765 , TSseArray765 , 






  
}
