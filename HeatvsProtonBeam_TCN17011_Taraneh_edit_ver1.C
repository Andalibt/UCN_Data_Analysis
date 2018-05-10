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
  sourceEpics766 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1766);
  sourceEpics767 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1767);
  sourceEpics768 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1768);
  sourceEpics769 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1769);
  sourceEpics770 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1770);
  sourceEpics771 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1771);
  sourceEpics772 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1772);
  sourceEpics773 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1773);
  sourceEpics778 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1778);
  sourceEpics779 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1779);


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

  //Defining the canvasas
  //run 765
  //TCanvas *cSource765 = new TCanvas("cSource765" , "cSource765" , 1200, 900);
  // cSource765 -> Divide (3,2);

  
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
  TCanvas *c765 = new TCanvas ("c765" , "c765" , 1200 , 900);
  c765 -> Divide(3,2);
  c765 -> cd(1);
  UCNRate765 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate765 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate765 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate765 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate765 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate765 -> Draw();

  //run 766
  TCanvas *c766 = new TCanvas ("c766" , "c766" , 1200 , 900);
  c766 -> Divide(3,2);
  c766 -> cd(1);
  UCNRate766 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate766 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate766 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate766 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate766 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate766 -> Draw();

  //run 767
  TCanvas *c767 = new TCanvas ("c767" , "c767" , 1200 , 900);
  c767 -> Divide(3,2);
  c767 -> cd(1);
  UCNRate767 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate767 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate767 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate767 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate767 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate767 -> Draw();

  //run 768
  TCanvas *c768 = new TCanvas ("c768" , "c768" , 1200 , 900);
  c768 -> Divide(3,2);
  c768 -> cd(1);
  UCNRate768 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate768 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate768 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate768 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate768 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate768 -> Draw();

  //run 769
  TCanvas *c769 = new TCanvas ("c769" , "c769" , 1200 , 900);
  c769 -> Divide(3,2);
  c769 -> cd(1);
  UCNRate769 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate769 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate769 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate769 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate769 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate769 -> Draw();

  //run 770
  TCanvas *c770 = new TCanvas ("c770" , "c770" , 1200 , 900);
  c770 -> Divide(3,2);
  c770 -> cd(1);
  UCNRate770 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate770 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate770 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate770 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate770 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate770 -> Draw();


  //run 771
  TCanvas *c771 = new TCanvas ("c771" , "c771" , 1200 , 900);
  c771 -> Divide(3,2);
  c771 -> cd(1);
  UCNRate771 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate771 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate771 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate771 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate771 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate771 -> Draw();

  //run 772
  TCanvas *c772 = new TCanvas ("c772" , "c772" , 1200 , 900);
  c772 -> Divide(3,2);
  c772 -> cd(1);
  UCNRate772 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate772 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate772 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate772 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate772 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate772 -> Draw();

  //run 773
  TCanvas *c773 = new TCanvas ("c773" , "c773" , 1200 , 900);
  c773 -> Divide(3,2);
  c773 -> cd(1);
  UCNRate773 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate773 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate773 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate773 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate773 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate773 -> Draw();

  //run 778
  TCanvas *c778 = new TCanvas ("c778" , "c778" , 1200 , 900);
  c778 -> Divide(3,2);
  c778 -> cd(1);
  UCNRate778 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate778 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate778 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate778 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate778 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate778 -> Draw();

  //run 779
  TCanvas *c779 = new TCanvas ("c779" , "c779" , 1200 , 900);
  c779 -> Divide(3,2);
  c779 -> cd(1);
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

  //***********************************
  // Loop over the beamline Tree values
  //***********************************

  //run 765
  for (ULong64_t j = 0; j < blEvent765 ; j++){
    TSblArray765[j] = timestamp_bl765;
    curArray765[j] = cur765;
  }

  //run 766
  for (ULong64_t j = 0; j < blEvent766 ; j++){
    TSblArray766[j] = timestamp_bl766;
    curArray766[j] = cur766;
  }

  //run 767
  for (ULong64_t j = 0; j < blEvent767 ; j++){
    TSblArray767[j] = timestamp_bl767;
    curArray767[j] = cur767;
  }

  //run 768
  for (ULong64_t j = 0; j < blEvent768 ; j++){
    TSblArray768[j] = timestamp_bl768;
    curArray768[j] = cur768;
  }

  //run 769
  for (ULong64_t j = 0; j < blEvent769 ; j++){
    TSblArray769[j] = timestamp_bl769;
    curArray769[j] = cur769;
  }

  //run 770
  for (ULong64_t j = 0; j < blEvent770 ; j++){
    TSblArray770[j] = timestamp_bl770;
    curArray770[j] = cur770;
  }

  //run 771
  for (ULong64_t j = 0; j < blEvent771 ; j++){
    TSblArray771[j] = timestamp_bl771;
    curArray771[j] = cur771;
  }

  //run 772
  for (ULong64_t j = 0; j < blEvent772 ; j++){
    TSblArray772[j] = timestamp_bl772;
    curArray772[j] = cur772;
  }

  //run 773
  for (ULong64_t j = 0; j < blEvent773 ; j++){
    TSblArray773[j] = timestamp_bl773;
    curArray773[j] = cur773;
  }

  //run 778
  for (ULong64_t j = 0; j < blEvent778 ; j++){
    TSblArray778[j] = timestamp_bl778;
    curArray778[j] = cur778;
  }

  //run 779
  for (ULong64_t j = 0; j < blEvent779 ; j++){
    TSblArray779[j] = timestamp_bl779;
    curArray779[j] = cur779;
  }


  // **********************************
  // graph the temperature and flow
  // **********************************

  //run 765

  c765 -> cd(2);
  TGraph *grtemp765 = new TGraph(seEvents765 , TSseArray765 , tempArray765);
  grtemp765 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp765 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp765 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp765 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp765 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp765 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp765 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp765 -> GetXaxis() -> SetNdivisions(10);
  grtemp765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp765 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp765 -> GetXaxis() -> SetLabelSize(.04);
  grtemp765 -> SetMarkerStyle(20);
  grtemp765 -> Draw("AP");

  c765 -> cd(3);
  TGraph *grFM4765 = new TGraph (seEvents765 , TSseArray765 , FM4Array765);
  grFM4765 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4765 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4765 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4765 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4765 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4765 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4765 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4765 -> GetXaxis() -> SetNdivisions(10);
  grFM4765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4765 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4765 -> GetXaxis() -> SetLabelSize(.04);
  grFM4765 -> SetMarkerStyle(20);
  grFM4765 -> Draw("AP");
  
  c765 -> cd(4);
  TGraph *grFM1765 = new TGraph (seEvents765 , TSseArray765 , FM1Array765);
  grFM1765 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1765 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1765 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1765 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1765 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1765 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1765 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1765 -> GetXaxis() -> SetNdivisions(10);
  grFM1765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1765 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1765 -> GetXaxis() -> SetLabelSize(.04);
  grFM1765 -> SetMarkerStyle(20);
  grFM1765 -> Draw("AP");
  
  c765 -> cd(5);
  TGraph *grFM5765 = new TGraph (seEvents765 , TSseArray765 , FM5Array765);
  grFM5765 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5765 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5765 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5765 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5765 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5765 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5765 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5765 -> GetXaxis() -> SetNdivisions(10);
  grFM5765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5765 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5765 -> GetXaxis() -> SetLabelSize(.04);
  grFM5765 -> SetMarkerStyle(20);
  grFM5765 -> Draw("AP");

  c765 -> cd(6);
  TGraph *grBL765 = new TGraph (blEvent765 , TSblArray765 , curArray765);
  grBL765 -> SetTitle(" Predicted current vs Time ");
  grBL765 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL765 -> GetXaxis() -> SetTitleSize(0.05);
  grBL765 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL765 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL765 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL765 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL765 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL765 -> GetXaxis() -> SetNdivisions(10);
  grBL765 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL765 -> GetXaxis() -> SetLabelOffset(.03);
  grBL765 -> GetXaxis() -> SetLabelSize(.04);
  grBL765 -> SetMarkerStyle(20);
  grBL765 -> Draw("AP");
  

  //run 766
  c766 -> cd(2);
  TGraph *grtemp766 = new TGraph(seEvents766 , TSseArray766 , tempArray766);
  grtemp766 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp766 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp766 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp766 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp766 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp766 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp766 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp766 -> GetXaxis() -> SetNdivisions(10);
  grtemp766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp766 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp766 -> GetXaxis() -> SetLabelSize(.04);
  grtemp766 -> SetMarkerStyle(20);
  grtemp766 -> Draw("AP");

  c766 -> cd(3);
  TGraph *grFM4766 = new TGraph (seEvents766 , TSseArray766 , FM4Array766);
  grFM4766 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4766 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4766 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4766 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4766 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4766 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4766 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4766 -> GetXaxis() -> SetNdivisions(10);
  grFM4766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4766 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4766 -> GetXaxis() -> SetLabelSize(.04);
  grFM4766 -> SetMarkerStyle(20);
  grFM4766 -> Draw("AP");
  
  c766 -> cd(4);
  TGraph *grFM1766 = new TGraph (seEvents766 , TSseArray766 , FM1Array766);
  grFM1766 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1766 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1766 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1766 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1766 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1766 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1766 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1766 -> GetXaxis() -> SetNdivisions(10);
  grFM1766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1766 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1766 -> GetXaxis() -> SetLabelSize(.04);
  grFM1766 -> SetMarkerStyle(20);
  grFM1766 -> Draw("AP");
  
  c766 -> cd(5);
  TGraph *grFM5766 = new TGraph (seEvents766 , TSseArray766 , FM5Array766);
  grFM5766 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5766 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5766 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5766 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5766 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5766 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5766 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5766 -> GetXaxis() -> SetNdivisions(10);
  grFM5766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5766 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5766 -> GetXaxis() -> SetLabelSize(.04);
  grFM5766 -> SetMarkerStyle(20);
  grFM5766 -> Draw("AP");

  c766 -> cd(6);
  TGraph *grBL766 = new TGraph (blEvent766 , TSblArray766 , curArray766);
  grBL766 -> SetTitle(" Predicted current vs Time ");
  grBL766 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL766 -> GetXaxis() -> SetTitleSize(0.05);
  grBL766 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL766 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL766 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL766 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL766 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL766 -> GetXaxis() -> SetNdivisions(10);
  grBL766 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL766 -> GetXaxis() -> SetLabelOffset(.03);
  grBL766 -> GetXaxis() -> SetLabelSize(.04);
  grBL766 -> SetMarkerStyle(20);
  grBL766 -> Draw("AP");
  
  //run 767
  c767 -> cd(2);
  TGraph *grtemp767 = new TGraph(seEvents767 , TSseArray767 , tempArray767);
  grtemp767 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp767 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp767 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp767 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp767 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp767 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp767 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp767 -> GetXaxis() -> SetNdivisions(10);
  grtemp767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp767 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp767 -> GetXaxis() -> SetLabelSize(.04);
  grtemp767 -> SetMarkerStyle(20);
  grtemp767 -> Draw("AP");

  c767 -> cd(3);
  TGraph *grFM4767 = new TGraph (seEvents767 , TSseArray767 , FM4Array767);
  grFM4767 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4767 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4767 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4767 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4767 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4767 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4767 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4767 -> GetXaxis() -> SetNdivisions(10);
  grFM4767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4767 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4767 -> GetXaxis() -> SetLabelSize(.04);
  grFM4767 -> SetMarkerStyle(20);
  grFM4767 -> Draw("AP");
  
  c767 -> cd(4);
  TGraph *grFM1767 = new TGraph (seEvents767 , TSseArray767 , FM1Array767);
  grFM1767 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1767 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1767 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1767 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1767 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1767 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1767 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1767 -> GetXaxis() -> SetNdivisions(10);
  grFM1767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1767 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1767 -> GetXaxis() -> SetLabelSize(.04);
  grFM1767 -> SetMarkerStyle(20);
  grFM1767 -> Draw("AP");
  
  c767 -> cd(5);
  TGraph *grFM5767 = new TGraph (seEvents767 , TSseArray767 , FM5Array767);
  grFM5767 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5767 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5767 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5767 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5767 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5767 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5767 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5767 -> GetXaxis() -> SetNdivisions(10);
  grFM5767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5767 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5767 -> GetXaxis() -> SetLabelSize(.04);
  grFM5767 -> SetMarkerStyle(20);
  grFM5767 -> Draw("AP");

  c767 -> cd(6);
  TGraph *grBL767 = new TGraph (blEvent767 , TSblArray767 , curArray767);
  grBL767 -> SetTitle(" Predicted current vs Time ");
  grBL767 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL767 -> GetXaxis() -> SetTitleSize(0.05);
  grBL767 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL767 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL767 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL767 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL767 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL767 -> GetXaxis() -> SetNdivisions(10);
  grBL767 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL767 -> GetXaxis() -> SetLabelOffset(.03);
  grBL767 -> GetXaxis() -> SetLabelSize(.04);
  grBL767 -> SetMarkerStyle(20);
  grBL767 -> Draw("AP");


  //run 768
  c768 -> cd(2);
  TGraph *grtemp768 = new TGraph(seEvents768 , TSseArray768 , tempArray768);
  grtemp768 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp768 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp768 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp768 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp768 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp768 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp768 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp768 -> GetXaxis() -> SetNdivisions(10);
  grtemp768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp768 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp768 -> GetXaxis() -> SetLabelSize(.04);
  grtemp768 -> SetMarkerStyle(20);
  grtemp768 -> Draw("AP");

  c768 -> cd(3);
  TGraph *grFM4768 = new TGraph (seEvents768 , TSseArray768 , FM4Array768);
  grFM4768 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4768 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4768 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4768 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4768 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4768 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4768 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4768 -> GetXaxis() -> SetNdivisions(10);
  grFM4768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4768 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4768 -> GetXaxis() -> SetLabelSize(.04);
  grFM4768 -> SetMarkerStyle(20);
  grFM4768 -> Draw("AP");
  
  c768 -> cd(4);
  TGraph *grFM1768 = new TGraph (seEvents768 , TSseArray768 , FM1Array768);
  grFM1768 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1768 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1768 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1768 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1768 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1768 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1768 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1768 -> GetXaxis() -> SetNdivisions(10);
  grFM1768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1768 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1768 -> GetXaxis() -> SetLabelSize(.04);
  grFM1768 -> SetMarkerStyle(20);
  grFM1768 -> Draw("AP");
  
  c768 -> cd(5);
  TGraph *grFM5768 = new TGraph (seEvents768 , TSseArray768 , FM5Array768);
  grFM5768 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5768 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5768 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5768 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5768 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5768 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5768 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5768 -> GetXaxis() -> SetNdivisions(10);
  grFM5768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5768 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5768 -> GetXaxis() -> SetLabelSize(.04);
  grFM5768 -> SetMarkerStyle(20);
  grFM5768 -> Draw("AP");

  c768 -> cd(6);
  TGraph *grBL768 = new TGraph (blEvent768 , TSblArray768 , curArray768);
  grBL768 -> SetTitle(" Predicted current vs Time ");
  grBL768 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL768 -> GetXaxis() -> SetTitleSize(0.05);
  grBL768 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL768 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL768 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL768 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL768 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL768 -> GetXaxis() -> SetNdivisions(10);
  grBL768 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL768 -> GetXaxis() -> SetLabelOffset(.03);
  grBL768 -> GetXaxis() -> SetLabelSize(.04);
  grBL768 -> SetMarkerStyle(20);
  grBL768 -> Draw("AP");
  
  //run 769
  c769 -> cd(2);
  TGraph *grtemp769 = new TGraph(seEvents769 , TSseArray769 , tempArray769);
  grtemp769 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp769 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp769 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp769 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp769 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp769 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp769 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp769 -> GetXaxis() -> SetNdivisions(10);
  grtemp769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp769 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp769 -> GetXaxis() -> SetLabelSize(.04);
  grtemp769 -> SetMarkerStyle(20);
  grtemp769 -> Draw("AP");

  c769 -> cd(3);
  TGraph *grFM4769 = new TGraph (seEvents769 , TSseArray769 , FM4Array769);
  grFM4769 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4769 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4769 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4769 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4769 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4769 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4769 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4769 -> GetXaxis() -> SetNdivisions(10);
  grFM4769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4769 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4769 -> GetXaxis() -> SetLabelSize(.04);
  grFM4769 -> SetMarkerStyle(20);
  grFM4769 -> Draw("AP");
  
  c769 -> cd(4);
  TGraph *grFM1769 = new TGraph (seEvents769 , TSseArray769 , FM1Array769);
  grFM1769 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1769 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1769 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1769 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1769 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1769 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1769 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1769 -> GetXaxis() -> SetNdivisions(10);
  grFM1769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1769 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1769 -> GetXaxis() -> SetLabelSize(.04);
  grFM1769 -> SetMarkerStyle(20);
  grFM1769 -> Draw("AP");
  
  c769 -> cd(5);
  TGraph *grFM5769 = new TGraph (seEvents769 , TSseArray769 , FM5Array769);
  grFM5769 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5769 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5769 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5769 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5769 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5769 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5769 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5769 -> GetXaxis() -> SetNdivisions(10);
  grFM5769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5769 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5769 -> GetXaxis() -> SetLabelSize(.04);
  grFM5769 -> SetMarkerStyle(20);
  grFM5769 -> Draw("AP");


  c769 -> cd(6);
  TGraph *grBL769 = new TGraph (blEvent769 , TSblArray769 , curArray769);
  grBL769 -> SetTitle(" Predicted current vs Time ");
  grBL769 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL769 -> GetXaxis() -> SetTitleSize(0.05);
  grBL769 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL769 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL769 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL769 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL769 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL769 -> GetXaxis() -> SetNdivisions(10);
  grBL769 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL769 -> GetXaxis() -> SetLabelOffset(.03);
  grBL769 -> GetXaxis() -> SetLabelSize(.04);
  grBL769 -> SetMarkerStyle(20);
  grBL769 -> Draw("AP");

  //run 770
  c770 -> cd(2);
  TGraph *grtemp770 = new TGraph(seEvents770 , TSseArray770 , tempArray770);
  grtemp770 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp770 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp770 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp770 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp770 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp770 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp770 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp770 -> GetXaxis() -> SetNdivisions(10);
  grtemp770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp770 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp770 -> GetXaxis() -> SetLabelSize(.04);
  grtemp770 -> SetMarkerStyle(20);
  grtemp770 -> Draw("AP");

  c770 -> cd(3);
  TGraph *grFM4770 = new TGraph (seEvents770 , TSseArray770 , FM4Array770);
  grFM4770 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4770 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4770 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4770 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4770 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4770 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4770 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4770 -> GetXaxis() -> SetNdivisions(10);
  grFM4770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4770 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4770 -> GetXaxis() -> SetLabelSize(.04);
  grFM4770 -> SetMarkerStyle(20);
  grFM4770 -> Draw("AP");
  
  c770 -> cd(4);
  TGraph *grFM1770 = new TGraph (seEvents770 , TSseArray770 , FM1Array770);
  grFM1770 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1770 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1770 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1770 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1770 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1770 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1770 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1770 -> GetXaxis() -> SetNdivisions(10);
  grFM1770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1770 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1770 -> GetXaxis() -> SetLabelSize(.04);
  grFM1770 -> SetMarkerStyle(20);
  grFM1770 -> Draw("AP");
  
  c770 -> cd(5);
  TGraph *grFM5770 = new TGraph (seEvents770 , TSseArray770 , FM5Array770);
  grFM5770 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5770 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5770 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5770 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5770 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5770 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5770 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5770 -> GetXaxis() -> SetNdivisions(10);
  grFM5770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5770 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5770 -> GetXaxis() -> SetLabelSize(.04);
  grFM5770 -> SetMarkerStyle(20);
  grFM5770 -> Draw("AP");

  c770 -> cd(6);
  TGraph *grBL770 = new TGraph (blEvent770 , TSblArray770 , curArray770);
  grBL770 -> SetTitle(" Predicted current vs Time ");
  grBL770 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL770 -> GetXaxis() -> SetTitleSize(0.05);
  grBL770 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL770 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL770 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL770 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL770 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL770 -> GetXaxis() -> SetNdivisions(10);
  grBL770 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL770 -> GetXaxis() -> SetLabelOffset(.03);
  grBL770 -> GetXaxis() -> SetLabelSize(.04);
  grBL770 -> SetMarkerStyle(20);
  grBL770 -> Draw("AP");

  //run 771
  c771 -> cd(2);
  TGraph *grtemp771 = new TGraph(seEvents771 , TSseArray771 , tempArray771);
  grtemp771 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp771 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp771 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp771 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp771 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp771 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp771 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp771 -> GetXaxis() -> SetNdivisions(10);
  grtemp771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp771 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp771 -> GetXaxis() -> SetLabelSize(.04);
  grtemp771 -> SetMarkerStyle(20);
  grtemp771 -> Draw("AP");

  c771 -> cd(3);
  TGraph *grFM4771 = new TGraph (seEvents771 , TSseArray771 , FM4Array771);
  grFM4771 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4771 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4771 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4771 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4771 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4771 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4771 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4771 -> GetXaxis() -> SetNdivisions(10);
  grFM4771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4771 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4771 -> GetXaxis() -> SetLabelSize(.04);
  grFM4771 -> SetMarkerStyle(20);
  grFM4771 -> Draw("AP");
  
  c771 -> cd(4);
  TGraph *grFM1771 = new TGraph (seEvents771 , TSseArray771 , FM1Array771);
  grFM1771 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1771 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1771 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1771 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1771 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1771 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1771 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1771 -> GetXaxis() -> SetNdivisions(10);
  grFM1771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1771 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1771 -> GetXaxis() -> SetLabelSize(.04);
  grFM1771 -> SetMarkerStyle(20);
  grFM1771 -> Draw("AP");
  
  c771 -> cd(5);
  TGraph *grFM5771 = new TGraph (seEvents771 , TSseArray771 , FM5Array771);
  grFM5771 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5771 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5771 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5771 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5771 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5771 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5771 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5771 -> GetXaxis() -> SetNdivisions(10);
  grFM5771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5771 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5771 -> GetXaxis() -> SetLabelSize(.04);
  grFM5771 -> SetMarkerStyle(20);
  grFM5771 -> Draw("AP");

  c771 -> cd(6);
  TGraph *grBL771 = new TGraph (blEvent771 , TSblArray771 , curArray771);
  grBL771 -> SetTitle(" Predicted current vs Time ");
  grBL771 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL771 -> GetXaxis() -> SetTitleSize(0.05);
  grBL771 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL771 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL771 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL771 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL771 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL771 -> GetXaxis() -> SetNdivisions(10);
  grBL771 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL771 -> GetXaxis() -> SetLabelOffset(.03);
  grBL771 -> GetXaxis() -> SetLabelSize(.04);
  grBL771 -> SetMarkerStyle(20);
  grBL771 -> Draw("AP");

  
  //run 772
  c772 -> cd(2);
  TGraph *grtemp772 = new TGraph(seEvents772 , TSseArray772 , tempArray772);
  grtemp772 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp772 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp772 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp772 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp772 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp772 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp772 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp772 -> GetXaxis() -> SetNdivisions(10);
  grtemp772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp772 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp772 -> GetXaxis() -> SetLabelSize(.04);
  grtemp772 -> SetMarkerStyle(20);
  grtemp772 -> Draw("AP");

  c772 -> cd(3);
  TGraph *grFM4772 = new TGraph (seEvents772 , TSseArray772 , FM4Array772);
  grFM4772 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4772 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4772 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4772 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4772 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4772 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4772 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4772 -> GetXaxis() -> SetNdivisions(10);
  grFM4772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4772 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4772 -> GetXaxis() -> SetLabelSize(.04);
  grFM4772 -> SetMarkerStyle(20);
  grFM4772 -> Draw("AP");
  
  c772 -> cd(4);
  TGraph *grFM1772 = new TGraph (seEvents772 , TSseArray772 , FM1Array772);
  grFM1772 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1772 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1772 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1772 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1772 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1772 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1772 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1772 -> GetXaxis() -> SetNdivisions(10);
  grFM1772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1772 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1772 -> GetXaxis() -> SetLabelSize(.04);
  grFM1772 -> SetMarkerStyle(20);
  grFM1772 -> Draw("AP");
  
  c772 -> cd(5);
  TGraph *grFM5772 = new TGraph (seEvents772 , TSseArray772 , FM5Array772);
  grFM5772 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5772 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5772 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5772 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5772 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5772 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5772 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5772 -> GetXaxis() -> SetNdivisions(10);
  grFM5772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5772 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5772 -> GetXaxis() -> SetLabelSize(.04);
  grFM5772 -> SetMarkerStyle(20);
  grFM5772 -> Draw("AP");

  c772 -> cd(6);
  TGraph *grBL772 = new TGraph (blEvent772 , TSblArray772 , curArray772);
  grBL772 -> SetTitle(" Predicted current vs Time ");
  grBL772 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL772 -> GetXaxis() -> SetTitleSize(0.05);
  grBL772 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL772 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL772 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL772 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL772 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL772 -> GetXaxis() -> SetNdivisions(10);
  grBL772 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL772 -> GetXaxis() -> SetLabelOffset(.03);
  grBL772 -> GetXaxis() -> SetLabelSize(.04);
  grBL772 -> SetMarkerStyle(20);
  grBL772 -> Draw("AP");

  //run 773
  c773 -> cd(2);
  TGraph *grtemp773 = new TGraph(seEvents773 , TSseArray773 , tempArray773);
  grtemp773 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp773 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp773 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp773 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp773 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp773 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp773 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp773 -> GetXaxis() -> SetNdivisions(10);
  grtemp773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp773 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp773 -> GetXaxis() -> SetLabelSize(.04);
  grtemp773 -> SetMarkerStyle(20);
  grtemp773 -> Draw("AP");

  c773 -> cd(3);
  TGraph *grFM4773 = new TGraph (seEvents773 , TSseArray773 , FM4Array773);
  grFM4773 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4773 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4773 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4773 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4773 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4773 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4773 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4773 -> GetXaxis() -> SetNdivisions(10);
  grFM4773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4773 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4773 -> GetXaxis() -> SetLabelSize(.04);
  grFM4773 -> SetMarkerStyle(20);
  grFM4773 -> Draw("AP");
  
  c773 -> cd(4);
  TGraph *grFM1773 = new TGraph (seEvents773 , TSseArray773 , FM1Array773);
  grFM1773 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1773 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1773 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1773 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1773 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1773 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1773 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1773 -> GetXaxis() -> SetNdivisions(10);
  grFM1773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1773 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1773 -> GetXaxis() -> SetLabelSize(.04);
  grFM1773 -> SetMarkerStyle(20);
  grFM1773 -> Draw("AP");
  
  c773 -> cd(5);
  TGraph *grFM5773 = new TGraph (seEvents773 , TSseArray773 , FM5Array773);
  grFM5773 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5773 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5773 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5773 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5773 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5773 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5773 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5773 -> GetXaxis() -> SetNdivisions(10);
  grFM5773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5773 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5773 -> GetXaxis() -> SetLabelSize(.04);
  grFM5773 -> SetMarkerStyle(20);
  grFM5773 -> Draw("AP");


  c773 -> cd(6);
  TGraph *grBL773 = new TGraph (blEvent773 , TSblArray773 , curArray773);
  grBL773 -> SetTitle(" Predicted current vs Time ");
  grBL773 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL773 -> GetXaxis() -> SetTitleSize(0.05);
  grBL773 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL773 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL773 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL773 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL773 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL773 -> GetXaxis() -> SetNdivisions(10);
  grBL773 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL773 -> GetXaxis() -> SetLabelOffset(.03);
  grBL773 -> GetXaxis() -> SetLabelSize(.04);
  grBL773 -> SetMarkerStyle(20);
  grBL773 -> Draw("AP");

  //run 778
  c778 -> cd(2);
  TGraph *grtemp778 = new TGraph(seEvents778 , TSseArray778 , tempArray778);
  grtemp778 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp778 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp778 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp778 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp778 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp778 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp778 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp778 -> GetXaxis() -> SetNdivisions(10);
  grtemp778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp778 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp778 -> GetXaxis() -> SetLabelSize(.04);
  grtemp778 -> SetMarkerStyle(20);
  grtemp778 -> Draw("AP");

  c778 -> cd(3);
  TGraph *grFM4778 = new TGraph (seEvents778 , TSseArray778 , FM4Array778);
  grFM4778 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4778 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4778 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4778 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4778 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4778 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4778 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4778 -> GetXaxis() -> SetNdivisions(10);
  grFM4778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4778 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4778 -> GetXaxis() -> SetLabelSize(.04);
  grFM4778 -> SetMarkerStyle(20);
  grFM4778 -> Draw("AP");
  
  c778 -> cd(4);
  TGraph *grFM1778 = new TGraph (seEvents778 , TSseArray778 , FM1Array778);
  grFM1778 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1778 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1778 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1778 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1778 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1778 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1778 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1778 -> GetXaxis() -> SetNdivisions(10);
  grFM1778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1778 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1778 -> GetXaxis() -> SetLabelSize(.04);
  grFM1778 -> SetMarkerStyle(20);
  grFM1778 -> Draw("AP");
  
  c778 -> cd(5);
  TGraph *grFM5778 = new TGraph (seEvents778 , TSseArray778 , FM5Array778);
  grFM5778 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5778 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5778 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5778 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5778 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5778 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5778 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5778 -> GetXaxis() -> SetNdivisions(10);
  grFM5778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5778 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5778 -> GetXaxis() -> SetLabelSize(.04);
  grFM5778 -> SetMarkerStyle(20);
  grFM5778 -> Draw("AP");


  c778 -> cd(6);
  TGraph *grBL778 = new TGraph (blEvent778 , TSblArray778 , curArray778);
  grBL778 -> SetTitle(" Predicted current vs Time ");
  grBL778 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL778 -> GetXaxis() -> SetTitleSize(0.05);
  grBL778 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL778 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL778 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL778 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL778 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL778 -> GetXaxis() -> SetNdivisions(10);
  grBL778 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL778 -> GetXaxis() -> SetLabelOffset(.03);
  grBL778 -> GetXaxis() -> SetLabelSize(.04);
  grBL778 -> SetMarkerStyle(20);
  grBL778 -> Draw("AP");
  
  //run 779
  c779 -> cd(2);
  TGraph *grtemp779 = new TGraph(seEvents779 , TSseArray779 , tempArray779);
  grtemp779 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp779 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp779 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp779 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp779 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp779 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp779 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp779 -> GetXaxis() -> SetNdivisions(10);
  grtemp779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp779 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp779 -> GetXaxis() -> SetLabelSize(.04);
  grtemp779 -> SetMarkerStyle(20);
  grtemp779 -> Draw("AP");

  c779 -> cd(3);
  TGraph *grFM4779 = new TGraph (seEvents779 , TSseArray779 , FM4Array779);
  grFM4779 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4779 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4779 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4779 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4779 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4779 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4779 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4779 -> GetXaxis() -> SetNdivisions(10);
  grFM4779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4779 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4779 -> GetXaxis() -> SetLabelSize(.04);
  grFM4779 -> SetMarkerStyle(20);
  grFM4779 -> Draw("AP");
  
  c779 -> cd(4);
  TGraph *grFM1779 = new TGraph (seEvents779 , TSseArray779 , FM1Array779);
  grFM1779 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1779 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1779 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1779 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1779 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1779 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1779 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1779 -> GetXaxis() -> SetNdivisions(10);
  grFM1779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1779 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1779 -> GetXaxis() -> SetLabelSize(.04);
  grFM1779 -> SetMarkerStyle(20);
  grFM1779 -> Draw("AP");
  
  c779 -> cd(5);
  TGraph *grFM5779 = new TGraph (seEvents779 , TSseArray779 , FM5Array779);
  grFM5779 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5779 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5779 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5779 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5779 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5779 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5779 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5779 -> GetXaxis() -> SetNdivisions(10);
  grFM5779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5779 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5779 -> GetXaxis() -> SetLabelSize(.04);
  grFM5779 -> SetMarkerStyle(20);
  grFM5779 -> Draw("AP");


  c779 -> cd(6);
  TGraph *grBL779 = new TGraph (blEvent779 , TSblArray779 , curArray779);
  grBL779 -> SetTitle(" Predicted current vs Time ");
  grBL779 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL779 -> GetXaxis() -> SetTitleSize(0.05);
  grBL779 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL779 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL779 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL779 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL779 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL779 -> GetXaxis() -> SetNdivisions(10);
  grBL779 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL779 -> GetXaxis() -> SetLabelOffset(.03);
  grBL779 -> GetXaxis() -> SetLabelSize(.04);
  grBL779 -> SetMarkerStyle(20);
  grBL779 -> Draw("AP");
  
}
