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
  TFile *fin587 = new TFile ("~/raw_Data/ucn_tree_00000587.root", "READ");
  TFile *fin588 = new TFile ("~/raw_Data/ucn_tree_00000588.root", "READ");
  TFile *fin589 = new TFile ("~/raw_Data/ucn_tree_00000589.root", "READ");
  TFile *fin590 = new TFile ("~/raw_Data/ucn_tree_00000590.root", "READ");
  TFile *fin591 = new TFile ("~/raw_Data/ucn_tree_00000591.root", "READ");
  TFile *fin592 = new TFile ("~/raw_Data/ucn_tree_00000592.root", "READ");
  TFile *fin593 = new TFile ("~/raw_Data/ucn_tree_00000593.root", "READ");
  TFile *fin654 = new TFile ("~/raw_Data/ucn_tree_00000654.root", "READ");
  TFile *fin659 = new TFile ("~/raw_Data/ucn_tree_00000659.root", "READ");


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
  TTree *uinli6587 = (TTree*) fin587 -> Get("UCNHits_Li-6");
  TTree *uinli6588 = (TTree*) fin588 -> Get("UCNHits_Li-6");
  TTree *uinli6589 = (TTree*) fin589 -> Get("UCNHits_Li-6");
  TTree *uinli6590 = (TTree*) fin590 -> Get("UCNHits_Li-6");
  TTree *uinli6591 = (TTree*) fin591 -> Get("UCNHits_Li-6");
  TTree *uinli6592 = (TTree*) fin592 -> Get("UCNHits_Li-6");
  TTree *uinli6593 = (TTree*) fin593 -> Get("UCNHits_Li-6");
  TTree *uinli6654 = (TTree*) fin654 -> Get("UCNHits_Li-6");
  TTree *uinli6659 = (TTree*) fin659 -> Get("UCNHits_Li-6");


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
  TTree *bl587 = (TTree*) fin587 -> Get("BeamlineEpicsTree");
  TTree *bl588 = (TTree*) fin588 -> Get("BeamlineEpicsTree");
  TTree *bl589 = (TTree*) fin589 -> Get("BeamlineEpicsTree");
  TTree *bl590 = (TTree*) fin590 -> Get("BeamlineEpicsTree");
  TTree *bl591 = (TTree*) fin591 -> Get("BeamlineEpicsTree");
  TTree *bl592 = (TTree*) fin592 -> Get("BeamlineEpicsTree");
  TTree *bl593 = (TTree*) fin593 -> Get("BeamlineEpicsTree");
  TTree *bl587 = (TTree*) fin587 -> Get("BeamlineEpicsTree");
  TTree *bl588 = (TTree*) fin588 -> Get("BeamlineEpicsTree");
  TTree *bl589 = (TTree*) fin589 -> Get("BeamlineEpicsTree");
  TTree *bl590 = (TTree*) fin590 -> Get("BeamlineEpicsTree");
  TTree *bl591 = (TTree*) fin591 -> Get("BeamlineEpicsTree");
  TTree *bl592 = (TTree*) fin592 -> Get("BeamlineEpicsTree");
  TTree *bl593 = (TTree*) fin593 -> Get("BeamlineEpicsTree");
  TTree *bl654 = (TTree*) fin654 -> Get("BeamlineEpicsTree");
  TTree *bl659 = (TTree*) fin659 -> Get("BeamlineEpicsTree");



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
  TTree *sourceEpics587 = (TTree*) fin587 -> Get("SourceEpicsTree");
  TTree *sourceEpics588 = (TTree*) fin588 -> Get("SourceEpicsTree");
  TTree *sourceEpics589 = (TTree*) fin589 -> Get("SourceEpicsTree");
  TTree *sourceEpics590 = (TTree*) fin590 -> Get("SourceEpicsTree");
  TTree *sourceEpics591 = (TTree*) fin591 -> Get("SourceEpicsTree");
  TTree *sourceEpics592 = (TTree*) fin592 -> Get("SourceEpicsTree");
  TTree *sourceEpics593 = (TTree*) fin593 -> Get("SourceEpicsTree");
  TTree *sourceEpics654 = (TTree*) fin654 -> Get("SourceEpicsTree");
  TTree *sourceEpics659 = (TTree*) fin659 -> Get("SourceEpicsTree");


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
  double tUnixTimePrecise587;
  double tUnixTimePrecise588;
  double tUnixTimePrecise589;
  double tUnixTimePrecise590;
  double tUnixTimePrecise591;
  double tUnixTimePrecise592;
  double tUnixTimePrecise593;
  double tUnixTimePrecise654;
  double tUnixTimePrecise659;
  

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
  uinli6587 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise587);
  uinli6588 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise588);
  uinli6589 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise589);
  uinli6590 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise590);
  uinli6591 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise591);
  uinli6592 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise592);
  uinli6593 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise593);
  uinli6654 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise654);
  uinli6659 -> SetBranchAddress ("tUnixTimePrecise" , &tUnixTimePrecise659);


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
  double tUnixTime587;
  double tUnixTime588;
  double tUnixTime589;
  double tUnixTime590;
  double tUnixTime591;
  double tUnixTime592;
  double tUnixTime593;
  double tUnixTime654;
  double tUnixTime659;


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
  uinli6587 -> SetBranchAddress ("tUnixTime" , &tUnixTime587);
  uinli6588 -> SetBranchAddress ("tUnixTime" , &tUnixTime588);
  uinli6589 -> SetBranchAddress ("tUnixTime" , &tUnixTime589);
  uinli6590 -> SetBranchAddress ("tUnixTime" , &tUnixTime590);
  uinli6591 -> SetBranchAddress ("tUnixTime" , &tUnixTime591);
  uinli6592 -> SetBranchAddress ("tUnixTime" , &tUnixTime592);
  uinli6593 -> SetBranchAddress ("tUnixTime" , &tUnixTime593);
  uinli6654 -> SetBranchAddress ("tUnixTime" , &tUnixTime654);
  uinli6659 -> SetBranchAddress ("tUnixTime" , &tUnixTime659);
  
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
  UShort_t tIsUCN587;
  UShort_t tIsUCN588;
  UShort_t tIsUCN589;
  UShort_t tIsUCN590;
  UShort_t tIsUCN591;
  UShort_t tIsUCN592;
  UShort_t tIsUCN593;
  UShort_t tIsUCN654;
  UShort_t tIsUCN659;


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
  uinli6587 -> SetBranchAddress ("tIsUCN" , &tIsUCN587);
  uinli6588 -> SetBranchAddress ("tIsUCN" , &tIsUCN588);
  uinli6589 -> SetBranchAddress ("tIsUCN" , &tIsUCN589);
  uinli6590 -> SetBranchAddress ("tIsUCN" , &tIsUCN590);
  uinli6591 -> SetBranchAddress ("tIsUCN" , &tIsUCN591);
  uinli6592 -> SetBranchAddress ("tIsUCN" , &tIsUCN592);
  uinli6593 -> SetBranchAddress ("tIsUCN" , &tIsUCN593);
  uinli6654 -> SetBranchAddress ("tIsUCN" , &tIsUCN654);
  uinli6659 -> SetBranchAddress ("tIsUCN" , &tIsUCN659);

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
  ULong64_t ucnli6Events587 = (Double_t) uinli6587 -> GetEntries();
  ULong64_t ucnli6Events588 = (Double_t) uinli6588 -> GetEntries();
  ULong64_t ucnli6Events589 = (Double_t) uinli6589 -> GetEntries();
  ULong64_t ucnli6Events590 = (Double_t) uinli6590 -> GetEntries();
  ULong64_t ucnli6Events591 = (Double_t) uinli6591 -> GetEntries();
  ULong64_t ucnli6Events592 = (Double_t) uinli6592 -> GetEntries();
  ULong64_t ucnli6Events593 = (Double_t) uinli6593 -> GetEntries();
  ULong64_t ucnli6Events654 = (Double_t) uinli6654 -> GetEntries();
  ULong64_t ucnli6Events659 = (Double_t) uinli6659 -> GetEntries();



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
  double cur587;
  double cur588;
  double cur589;
  double cur590;
  double cur591;
  double cur592;
  double cur593;
  double cur654;
  double cur659;

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
  bl587 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur587);
  bl588 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur588);
  bl589 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur589);
  bl590 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur590);
  bl591 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur591);
  bl592 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur592);
  bl593 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur593);
  bl654 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur654);
  bl659 -> SetBranchAddress ("B1V_KSM_PREDCUR" , &cur659);


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
  double curArray587[max];
  double curArray588[max];
  double curArray589[max];
  double curArray590[max];
  double curArray591[max];
  double curArray592[max];
  double curArray593[max];
  double curArray654[max];
  double curArray659[max];

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
  double curAve587;
  double curAve588;
  double curAve589;
  double curAve590;
  double curAve591;
  double curAve592;
  double curAve593;
  double curAve654;
  double curAve659;

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
  int timestamp_bl587;
  int timestamp_bl588;
  int timestamp_bl589;
  int timestamp_bl590;
  int timestamp_bl591;
  int timestamp_bl592;
  int timestamp_bl593;
  int timestamp_bl654;
  int timestamp_bl659;

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
  bl587 -> SetBranchAddress ("timestamp" , &timestamp_bl587);
  bl588 -> SetBranchAddress ("timestamp" , &timestamp_bl588);
  bl589 -> SetBranchAddress ("timestamp" , &timestamp_bl589);
  bl590 -> SetBranchAddress ("timestamp" , &timestamp_bl590);
  bl591 -> SetBranchAddress ("timestamp" , &timestamp_bl591);
  bl592 -> SetBranchAddress ("timestamp" , &timestamp_bl592);
  bl593 -> SetBranchAddress ("timestamp" , &timestamp_bl593);
  bl654 -> SetBranchAddress ("timestamp" , &timestamp_bl654);
  bl659 -> SetBranchAddress ("timestamp" , &timestamp_bl659);
  

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
  double TSblArray587[max];
  double TSblArray588[max];
  double TSblArray589[max];
  double TSblArray590[max];
  double TSblArray591[max];
  double TSblArray592[max];
  double TSblArray593[max];
  double TSblArray654[max];
  double TSblArray659[max];

  ULong64_t blEvent765 =  bl765 -> GetEntries();  //Total number of events in the beamline tree
  ULong64_t blEvent766 =  bl766 -> GetEntries();  
  ULong64_t blEvent767 =  bl767 -> GetEntries();  
  ULong64_t blEvent768 =  bl768 -> GetEntries();
  ULong64_t blEvent769 =  bl769 -> GetEntries();  
  ULong64_t blEvent770 =  bl770 -> GetEntries();  
  ULong64_t blEvent771 =  bl771 -> GetEntries();  
  ULong64_t blEvent772 =  bl772 -> GetEntries();  
  ULong64_t blEvent773 =  bl773 -> GetEntries();  
  ULong64_t blEvent778 =  bl778 -> GetEntries();  
  ULong64_t blEvent779 =  bl779 -> GetEntries();  
  ULong64_t blEvent587 =  bl587 -> GetEntries();  
  ULong64_t blEvent588 =  bl588 -> GetEntries();  
  ULong64_t blEvent589 =  bl589 -> GetEntries();  
  ULong64_t blEvent590 =  bl590 -> GetEntries();  
  ULong64_t blEvent591 =  bl591 -> GetEntries();  
  ULong64_t blEvent592 =  bl592 -> GetEntries();  
  ULong64_t blEvent593 =  bl593 -> GetEntries();  
  ULong64_t blEvent654 =  bl654 -> GetEntries();  
  ULong64_t blEvent659 =  bl659 -> GetEntries();  

  
  
  
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
  double ts12587;
  double ts12588;
  double ts12589;
  double ts12590;
  double ts12591;
  double ts12592;
  double ts12593;
  double ts12654;
  double ts12659;

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
  sourceEpics587 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12587);
  sourceEpics588 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12588);
  sourceEpics589 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12589);
  sourceEpics590 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12590);
  sourceEpics591 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12591);
  sourceEpics592 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12592);
  sourceEpics593 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12593);
  sourceEpics654 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12654);
  sourceEpics659 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12659);
  
  

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
  double tempArray587[max];
  double tempArray588[max];
  double tempArray589[max];
  double tempArray590[max];
  double tempArray591[max];
  double tempArray592[max];
  double tempArray593[max];
  double tempArray654[max];
  double tempArray659[max];
  
  

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
  int timestamp_se587;
  int timestamp_se588;
  int timestamp_se589;
  int timestamp_se590;
  int timestamp_se591;
  int timestamp_se592;
  int timestamp_se593;
  int timestamp_se654;
  int timestamp_se659;

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
  sourceEpics587 -> SetBranchAddress ("timestamp" , &timestamp_se587);
  sourceEpics588 -> SetBranchAddress ("timestamp" , &timestamp_se588);
  sourceEpics589 -> SetBranchAddress ("timestamp" , &timestamp_se589);
  sourceEpics590 -> SetBranchAddress ("timestamp" , &timestamp_se590);
  sourceEpics591 -> SetBranchAddress ("timestamp" , &timestamp_se591);
  sourceEpics592 -> SetBranchAddress ("timestamp" , &timestamp_se592);
  sourceEpics593 -> SetBranchAddress ("timestamp" , &timestamp_se593);
  sourceEpics654 -> SetBranchAddress ("timestamp" , &timestamp_se654);
  sourceEpics659 -> SetBranchAddress ("timestamp" , &timestamp_se659);

  
  
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
  double TSseArray587[max];
  double TSseArray588[max];
  double TSseArray589[max];
  double TSseArray590[max];
  double TSseArray591[max];
  double TSseArray592[max];
  double TSseArray593[max];
  double TSseArray654[max];
  double TSseArray659[max];


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
  double FM1587;    
  double FM1588;    
  double FM1589;    
  double FM1590;    
  double FM1591;    
  double FM1592;    
  double FM1593;    
  double FM1654;    
  double FM1659;    

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
  sourceEpics587 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1587);
  sourceEpics588 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1588);
  sourceEpics589 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1589);
  sourceEpics590 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1590);
  sourceEpics591 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1591);
  sourceEpics592 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1592);
  sourceEpics593 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1593);
  sourceEpics654 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1654);
  sourceEpics659 -> SetBranchAddress ("UCN_HE3_FM1_RDFLOW" , &FM1659);


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
  double FM1Array587[max];
  double FM1Array588[max];
  double FM1Array589[max];
  double FM1Array590[max];
  double FM1Array591[max];
  double FM1Array592[max];
  double FM1Array593[max];
  double FM1Array654[max];
  double FM1Array659[max];
  

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
  double FM4587;
  double FM4588;
  double FM4589;
  double FM4590;
  double FM4591;
  double FM4592;
  double FM4593;
  double FM4654;
  double FM4659;

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
  sourceEpics587 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4587);
  sourceEpics588 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4588);
  sourceEpics589 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4589);
  sourceEpics590 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4590);
  sourceEpics591 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4591);
  sourceEpics592 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4592);
  sourceEpics593 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4593);
  sourceEpics654 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4654);
  sourceEpics659 -> SetBranchAddress ("UCN_HE4_FM4_RDFLOW" , &FM4659);

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
  double FM4Array587[max];
  double FM4Array588[max];
  double FM4Array589[max];
  double FM4Array590[max];
  double FM4Array591[max];
  double FM4Array592[max];
  double FM4Array593[max];
  double FM4Array654[max];
  double FM4Array659[max];

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
  double FM5587;
  double FM5588;
  double FM5589;
  double FM5590;
  double FM5591;
  double FM5592;
  double FM5593;
  double FM5654;
  double FM5659;
  

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
  sourceEpics587 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5587);
  sourceEpics588 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5588);
  sourceEpics589 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5589);
  sourceEpics590 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5590);
  sourceEpics591 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5591);
  sourceEpics592 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5592);
  sourceEpics593 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5593);
  sourceEpics654 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5654);
  sourceEpics659 -> SetBranchAddress ("UCN_HE4_FM5_RDFLOW" , &FM5659);

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
  double FM5Array587[max];
  double FM5Array588[max];
  double FM5Array589[max];
  double FM5Array590[max];
  double FM5Array591[max];
  double FM5Array592[max];
  double FM5Array593[max];
  double FM5Array654[max];
  double FM5Array659[max];

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
  ULong64_t seEvents587 = sourceEpics587 -> GetEntries();
  ULong64_t seEvents588 = sourceEpics588 -> GetEntries();
  ULong64_t seEvents589 = sourceEpics589 -> GetEntries();
  ULong64_t seEvents590 = sourceEpics590 -> GetEntries();
  ULong64_t seEvents591 = sourceEpics591 -> GetEntries();
  ULong64_t seEvents592 = sourceEpics592 -> GetEntries();
  ULong64_t seEvents593 = sourceEpics593 -> GetEntries();
  ULong64_t seEvents654 = sourceEpics654 -> GetEntries();
  ULong64_t seEvents659 = sourceEpics659 -> GetEntries();


  double maxts12765 = 0;
  double maxts12766 = 0;
  double maxts12767 = 0;
  double maxts12768 = 0;
  double maxts12769 = 0;
  double maxts12770 = 0;
  double maxts12771 = 0;
  double maxts12772 = 0;
  double maxts12773 = 0;
  double maxts12778 = 0;
  double maxts12779 = 0;
  double maxts12587 = 0;
  double maxts12588 = 0;
  double maxts12589 = 0;
  double maxts12590 = 0;
  double maxts12591 = 0;
  double maxts12592 = 0;
  double maxts12593 = 0;
  double maxts12654 = 0;
  double maxts12659 = 0;


  double maxFM1765 = 0;
  double maxFM1766 = 0;
  double maxFM1767 = 0;
  double maxFM1768 = 0;
  double maxFM1769 = 0;
  double maxFM1770 = 0;
  double maxFM1771 = 0;
  double maxFM1772 = 0;
  double maxFM1773 = 0;
  double maxFM1778 = 0;
  double maxFM1779 = 0;
  double maxFM1587 = 0;
  double maxFM1588 = 0;
  double maxFM1589 = 0;
  double maxFM1590 = 0;
  double maxFM1591 = 0;
  double maxFM1592 = 0;
  double maxFM1593 = 0;
  double maxFM1654 = 0;
  double maxFM1659 = 0;
  

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
  int NBins587 = 1;
  int NBins588 = 1;
  int NBins589 = 1;
  int NBins590 = 1;
  int NBins591 = 1;
  int NBins592 = 1;
  int NBins593 = 1;
  int NBins654 = 1;
  int NBins659 = 1;

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
  int maxXrange587 = 0, minXrange587 = 1540000000.;
  int maxXrange588 = 0, minXrange588 = 1540000000.;
  int maxXrange589 = 0, minXrange589 = 1540000000.;
  int maxXrange590 = 0, minXrange590 = 1540000000.;
  int maxXrange591 = 0, minXrange591 = 1540000000.;
  int maxXrange592 = 0, minXrange592 = 1540000000.;
  int maxXrange593 = 0, minXrange593 = 1540000000.;
  int maxXrange654 = 0, minXrange654 = 1540000000.;
  int maxXrange659 = 0, minXrange659 = 1540000000.;

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
  TH1* UCNRate587 = new TH1F("UCNRate587", "UCN-rate Histogram", NBins587 , minXrange587, maxXrange587);
  TH1* UCNRate588 = new TH1F("UCNRate588", "UCN-rate Histogram", NBins588 , minXrange588, maxXrange588);
  TH1* UCNRate589 = new TH1F("UCNRate589", "UCN-rate Histogram", NBins589 , minXrange589, maxXrange589);
  TH1* UCNRate590 = new TH1F("UCNRate590", "UCN-rate Histogram", NBins590 , minXrange590, maxXrange590);
  TH1* UCNRate591 = new TH1F("UCNRate591", "UCN-rate Histogram", NBins591 , minXrange591, maxXrange591);
  TH1* UCNRate592 = new TH1F("UCNRate592", "UCN-rate Histogram", NBins592 , minXrange592, maxXrange592);
  TH1* UCNRate593 = new TH1F("UCNRate593", "UCN-rate Histogram", NBins593 , minXrange593, maxXrange593);
  TH1* UCNRate654 = new TH1F("UCNRate654", "UCN-rate Histogram", NBins654 , minXrange654, maxXrange654);
  TH1* UCNRate659 = new TH1F("UCNRate659", "UCN-rate Histogram", NBins659 , minXrange659, maxXrange659);


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

  //run 587
  for(ULong64_t j = 0 ; j < blEvent587 ;j++) {
    bl587 -> GetEvent(j);
    if (timestamp_bl587 < minXrange587 ){
      minXrange587 = timestamp_bl587;
    }
    if (timestamp_bl587 > maxXrange587){
      maxXrange587 = timestamp_bl587;
    }
  }


  //run 588
  for(ULong64_t j = 0 ; j < blEvent588 ;j++) {
    bl588 -> GetEvent(j);
    if (timestamp_bl588 < minXrange588 ){
      minXrange588 = timestamp_bl588;
    }
    if (timestamp_bl588 > maxXrange588){
      maxXrange588 = timestamp_bl588;
    }
  }

  //run 589
  for(ULong64_t j = 0 ; j < blEvent589 ;j++) {
    bl589 -> GetEvent(j);
    if (timestamp_bl589 < minXrange589 ){
      minXrange589 = timestamp_bl589;
    }
    if (timestamp_bl589 > maxXrange589){
      maxXrange589 = timestamp_bl589;
    }
  }


  //run 590
  for(ULong64_t j = 0 ; j < blEvent590 ;j++) {
    bl590 -> GetEvent(j);
    if (timestamp_bl590 < minXrange590 ){
      minXrange590 = timestamp_bl590;
    }
    if (timestamp_bl590 > maxXrange590){
      maxXrange590 = timestamp_bl590;
    }
  }


  //run 591
  for(ULong64_t j = 0 ; j < blEvent591 ;j++) {
    bl591 -> GetEvent(j);
    if (timestamp_bl591 < minXrange591 ){
      minXrange591 = timestamp_bl591;
    }
    if (timestamp_bl591 > maxXrange591){
      maxXrange591 = timestamp_bl591;
    }
  }


  //run 592
  for(ULong64_t j = 0 ; j < blEvent592 ;j++) {
    bl592 -> GetEvent(j);
    if (timestamp_bl592 < minXrange592 ){
      minXrange592 = timestamp_bl592;
    }
    if (timestamp_bl592 > maxXrange592){
      maxXrange592 = timestamp_bl592;
    }
  }


  //run 593
  for(ULong64_t j = 0 ; j < blEvent593 ;j++) {
    bl593 -> GetEvent(j);
    if (timestamp_bl593 < minXrange593 ){
      minXrange593 = timestamp_bl593;
    }
    if (timestamp_bl593 > maxXrange593){
      maxXrange593 = timestamp_bl593;
    }
  }


  //run 654
  for(ULong64_t j = 0 ; j < blEvent654 ;j++) {
    bl654 -> GetEvent(j);
    if (timestamp_bl654 < minXrange654 ){
      minXrange654 = timestamp_bl654;
    }
    if (timestamp_bl654 > maxXrange654){
      maxXrange654 = timestamp_bl654;
    }
  }


  //run 659
  for(ULong64_t j = 0 ; j < blEvent659 ;j++) {
    bl659 -> GetEvent(j);
    if (timestamp_bl659 < minXrange659 ){
      minXrange659 = timestamp_bl659;
    }
    if (timestamp_bl659 > maxXrange659){
      maxXrange659 = timestamp_bl659;
    }
  }
  
  // setting the bin numbers
  
  NBins765 = (maxXrange765 - minXrange765 )/BinWidth ;
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
  NBins587 = (maxXrange587 - minXrange587 )/BinWidth ;
  NBins588 = (maxXrange588 - minXrange588 )/BinWidth ;
  NBins589 = (maxXrange589 - minXrange589 )/BinWidth ;
  NBins590 = (maxXrange590 - minXrange590 )/BinWidth ;
  NBins591 = (maxXrange591 - minXrange591 )/BinWidth ;
  NBins592 = (maxXrange592 - minXrange592 )/BinWidth ;
  NBins593 = (maxXrange593 - minXrange593 )/BinWidth ;
  NBins654 = (maxXrange654 - minXrange654 )/BinWidth ;
  NBins659 = (maxXrange659 - minXrange659 )/BinWidth ;

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
  UCNRate587 -> Reset();
  UCNRate588 -> Reset();
  UCNRate589 -> Reset();
  UCNRate590 -> Reset();
  UCNRate591 -> Reset();
  UCNRate592 -> Reset();
  UCNRate593 -> Reset();
  UCNRate654 -> Reset();
  UCNRate659 -> Reset();
  
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
  UCNRate587 -> SetBins(NBins587 , minXrange587 , maxXrange587);
  UCNRate588 -> SetBins(NBins588 , minXrange588 , maxXrange588);
  UCNRate589 -> SetBins(NBins589 , minXrange589 , maxXrange589);
  UCNRate590 -> SetBins(NBins590 , minXrange590 , maxXrange590);
  UCNRate591 -> SetBins(NBins591 , minXrange591 , maxXrange591);
  UCNRate592 -> SetBins(NBins592 , minXrange592 , maxXrange592);
  UCNRate593 -> SetBins(NBins593 , minXrange593 , maxXrange593);
  UCNRate654 -> SetBins(NBins654 , minXrange654 , maxXrange654);
  UCNRate659 -> SetBins(NBins659 , minXrange659 , maxXrange659);

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

  //run 587
  for (ULong64_t j = 0 ; j < ucnli6Events587; j++){
    uinli6587 -> GetEvent(j);
    if (tUnixTimePrecise587 > 20e6 && tIsUCN587 > 0){
      UCNRate587 -> Fill(tUnixTimePrecise587);
    }
  }

  //run 588
  for (ULong64_t j = 0 ; j < ucnli6Events588; j++){
    uinli6588 -> GetEvent(j);
    if (tUnixTimePrecise588 > 20e6 && tIsUCN588 > 0){
      UCNRate588 -> Fill(tUnixTimePrecise588);
    }
  }

  //run 589
  for (ULong64_t j = 0 ; j < ucnli6Events589; j++){
    uinli6589 -> GetEvent(j);
    if (tUnixTimePrecise589 > 20e6 && tIsUCN589 > 0){
      UCNRate589 -> Fill(tUnixTimePrecise589);
    }
  }

  //run 590
  for (ULong64_t j = 0 ; j < ucnli6Events590; j++){
    uinli6590 -> GetEvent(j);
    if (tUnixTimePrecise590 > 20e6 && tIsUCN590 > 0){
      UCNRate590 -> Fill(tUnixTimePrecise590);
    }
  }

  //run 591
  for (ULong64_t j = 0 ; j < ucnli6Events591; j++){
    uinli6591 -> GetEvent(j);
    if (tUnixTimePrecise591 > 20e6 && tIsUCN591 > 0){
      UCNRate591 -> Fill(tUnixTimePrecise591);
    }
  }

  //run 592
  for (ULong64_t j = 0 ; j < ucnli6Events592; j++){
    uinli6592 -> GetEvent(j);
    if (tUnixTimePrecise592 > 20e6 && tIsUCN592 > 0){
      UCNRate592 -> Fill(tUnixTimePrecise592);
    }
  }

  //run 593
  for (ULong64_t j = 0 ; j < ucnli6Events593; j++){
    uinli6593 -> GetEvent(j);
    if (tUnixTimePrecise593 > 20e6 && tIsUCN593 > 0){
      UCNRate593 -> Fill(tUnixTimePrecise593);
    }
  }

  //run 654
  for (ULong64_t j = 0 ; j < ucnli6Events654; j++){
    uinli6654 -> GetEvent(j);
    if (tUnixTimePrecise654 > 20e6 && tIsUCN654 > 0){
      UCNRate654 -> Fill(tUnixTimePrecise654);
    }
  }

  //run 659
  for (ULong64_t j = 0 ; j < ucnli6Events659; j++){
    uinli6659 -> GetEvent(j);
    if (tUnixTimePrecise659 > 20e6 && tIsUCN659 > 0){
      UCNRate659 -> Fill(tUnixTimePrecise659);
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


  //run 587
  TCanvas *c587 = new TCanvas ("c587" , "c587" , 1200 , 900);
  c587 -> Divide(3,2);
  c587 -> cd(1);
  UCNRate587 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate587 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate587 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate587 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate587 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate587 -> Draw();


  //run 588
  TCanvas *c588 = new TCanvas ("c588" , "c588" , 1200 , 900);
  c588 -> Divide(3,2);
  c588 -> cd(1);
  UCNRate588 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate588 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate588 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate588 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate588 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate588 -> Draw();


  //run 589
  TCanvas *c589 = new TCanvas ("c589" , "c589" , 1200 , 900);
  c589 -> Divide(3,2);
  c589 -> cd(1);
  UCNRate589 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate589 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate589 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate589 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate589 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate589 -> Draw();

  //run 590
  TCanvas *c590 = new TCanvas ("c590" , "c590" , 1200 , 900);
  c590 -> Divide(3,2);
  c590 -> cd(1);
  UCNRate590 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate590 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate590 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate590 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate590 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate590 -> Draw();


  //run 591
  TCanvas *c591 = new TCanvas ("c591" , "c591" , 1200 , 900);
  c591 -> Divide(3,2);
  c591 -> cd(1);
  UCNRate591 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate591 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate591 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate591 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate591 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate591 -> Draw();


  //run 592
  TCanvas *c592 = new TCanvas ("c592" , "c592" , 1200 , 900);
  c592 -> Divide(3,2);
  c592 -> cd(1);
  UCNRate592 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate592 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate592 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate592 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate592 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate592 -> Draw();


  //run 593
  TCanvas *c593 = new TCanvas ("c593" , "c593" , 1200 , 900);
  c593 -> Divide(3,2);
  c593 -> cd(1);
  UCNRate593 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate593 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate593 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate593 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate593 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate593 -> Draw();


  //run 654
  TCanvas *c654 = new TCanvas ("c654" , "c654" , 1200 , 900);
  c654 -> Divide(3,2);
  c654 -> cd(1);
  UCNRate654 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate654 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate654 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate654 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate654 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate654 -> Draw();


  //run 659
  TCanvas *c659 = new TCanvas ("c659" , "c659" , 1200 , 900);
  c659 -> Divide(3,2);
  c659 -> cd(1);
  UCNRate659 -> GetYaxis() -> SetTitle("UCN Counts/s");
  UCNRate659 -> GetXaxis() -> SetTimeDisplay(1);
  UCNRate659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  UCNRate659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  UCNRate659 -> GetXaxis() -> SetTitleSize(0.05);
  UCNRate659 -> GetXaxis() -> SetLabelOffset(.03);
  UCNRate659 -> GetXaxis() -> SetLabelSize(.04);
  UCNRate659 -> Draw();
  
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
    if (maxFM1765 < FM1765)
      maxFM1765 = FM1765;
    if (maxts12765 < ts12765)
      maxts12765 = ts12765;
  }

  //run 766
  for (ULong64_t j = 0 ; j < seEvents766 ; j++){
    sourceEpics766 -> GetEvent(j);
    TSseArray766[j] = timestamp_se766;
    tempArray766[j] = ts12766;
    FM1Array766[j] = FM1766;
    FM4Array766[j] = FM4766;
    FM5Array766[j] = FM5766;
    if (maxFM1766 < FM1766)
      maxFM1766 = FM1766;
    if (maxts12766 < ts12766)
      maxts12766 = ts12766;
  }

  //run 767
  for (ULong64_t j = 0 ; j < seEvents767 ; j++){
    sourceEpics767 -> GetEvent(j);
    TSseArray767[j] = timestamp_se767;
    tempArray767[j] = ts12767;
    FM1Array767[j] = FM1767;
    FM4Array767[j] = FM4767;
    FM5Array767[j] = FM5767;
    if (maxFM1767 < FM1767)
      maxFM1767 = FM1767;
    if (maxts12767 < ts12767)
      maxts12767 = ts12767;
  }

  //run 768
  for (ULong64_t j = 0 ; j < seEvents768 ; j++){
    sourceEpics768 -> GetEvent(j);
    TSseArray768[j] = timestamp_se768;
    tempArray768[j] = ts12768;
    FM1Array768[j] = FM1768;
    FM4Array768[j] = FM4768;
    FM5Array768[j] = FM5768;
    if (maxFM1768 < FM1768)
      maxFM1768 = FM1768;
    if (maxts12768 < ts12768)
      maxts12768 = ts12768;
  }

  //run 769
  for (ULong64_t j = 0 ; j < seEvents769 ; j++){
    sourceEpics769 -> GetEvent(j);
    TSseArray769[j] = timestamp_se769;
    tempArray769[j] = ts12769;
    FM1Array769[j] = FM1769;
    FM4Array769[j] = FM4769;
    FM5Array769[j] = FM5769;
    if (maxFM1769 < FM1769)
      maxFM1769 = FM1769;
    if (maxts12769 < ts12769)
      maxts12769 = ts12769;
  }

  //run 770
  for (ULong64_t j = 0 ; j < seEvents770 ; j++){
    sourceEpics770 -> GetEvent(j);
    TSseArray770[j] = timestamp_se770;
    tempArray770[j] = ts12770;
    FM1Array770[j] = FM1770;
    FM4Array770[j] = FM4770;
    FM5Array770[j] = FM5770;
    if (maxFM1770 < FM1770)
      maxFM1770 = FM1770;
    if (maxts12770 < ts12770)
      maxts12770 = ts12770;
  }

  //run 771
  for (ULong64_t j = 0 ; j < seEvents771 ; j++){
    sourceEpics771 -> GetEvent(j);
    TSseArray771[j] = timestamp_se771;
    tempArray771[j] = ts12771;
    FM1Array771[j] = FM1771;
    FM4Array771[j] = FM4771;
    FM5Array771[j] = FM5771;
    if (maxFM1771 < FM1771)
      maxFM1771 = FM1771;
    if (maxts12771 < ts12771)
      maxts12771 = ts12771;
  }
  
  //run 772
  for (ULong64_t j = 0 ; j < seEvents772 ; j++){
    sourceEpics772 -> GetEvent(j);
    TSseArray772[j] = timestamp_se772;
    tempArray772[j] = ts12772;
    FM1Array772[j] = FM1772;
    FM4Array772[j] = FM4772;
    FM5Array772[j] = FM5772;
    if (maxFM1772 < FM1772)
      maxFM1772 = FM1772;
    if (maxts12772 < ts12772)
      maxts12772 = ts12772;
  }

  //run 773
  for (ULong64_t j = 0 ; j < seEvents773 ; j++){
    sourceEpics773 -> GetEvent(j);
    TSseArray773[j] = timestamp_se773;
    tempArray773[j] = ts12773;
    FM1Array773[j] = FM1773;
    FM4Array773[j] = FM4773;
    FM5Array773[j] = FM5773;
    if (maxFM1773 < FM1773)
      maxFM1773 = FM1773;
    if (maxts12773 < ts12773)
      maxts12773 = ts12773;
  }

  //run 778
  for (ULong64_t j = 0 ; j < seEvents778 ; j++){
    sourceEpics778 -> GetEvent(j);
    TSseArray778[j] = timestamp_se778;
    tempArray778[j] = ts12778;
    FM1Array778[j] = FM1778;
    FM4Array778[j] = FM4778;
    FM5Array778[j] = FM5778;
    if (maxFM1778 < FM1778)
      maxFM1778 = FM1778;
    if (maxts12778 < ts12778)
      maxts12778 = ts12778;
  }

  //run 779
  for (ULong64_t j = 0 ; j < seEvents779 ; j++){
    sourceEpics779 -> GetEvent(j);
    TSseArray779[j] = timestamp_se779;
    tempArray779[j] = ts12779;
    FM1Array779[j] = FM1779;
    FM4Array779[j] = FM4779;
    FM5Array779[j] = FM5779;
    if (maxFM1779 < FM1779)
      maxFM1779 = FM1779;
    if (maxts12779 < ts12779)
      maxts12779 = ts12779;
  }


  //run 587
  for (ULong64_t j = 0 ; j < seEvents587 ; j++){
    sourceEpics587 -> GetEvent(j);
    TSseArray587[j] = timestamp_se587;
    tempArray587[j] = ts12587;
    FM1Array587[j] = FM1587;
    FM4Array587[j] = FM4587;
    FM5Array587[j] = FM5587;
    if (maxFM1587 < FM1587)
      maxFM1587 = FM1587;
    if (maxts12587 < ts12587)
      maxts12587 = ts12587;
  }

  //run 588
  for (ULong64_t j = 0 ; j < seEvents588 ; j++){
    sourceEpics588 -> GetEvent(j);
    TSseArray588[j] = timestamp_se588;
    tempArray588[j] = ts12588;
    FM1Array588[j] = FM1588;
    FM4Array588[j] = FM4588;
    FM5Array588[j] = FM5588;
    if (maxFM1588 < FM1588)
      maxFM1588 = FM1588;
    if (maxts12588 < ts12588)
      maxts12588 = ts12588;
  }


  //run 589
  for (ULong64_t j = 0 ; j < seEvents589 ; j++){
    sourceEpics589 -> GetEvent(j);
    TSseArray589[j] = timestamp_se589;
    tempArray589[j] = ts12589;
    FM1Array589[j] = FM1589;
    FM4Array589[j] = FM4589;
    FM5Array589[j] = FM5589;
    if (maxFM1589 < FM1589)
      maxFM1589 = FM1589;
    if (maxts12589 < ts12589)
      maxts12589 = ts12589;
  }


  //run 590
  for (ULong64_t j = 0 ; j < seEvents590 ; j++){
    sourceEpics590 -> GetEvent(j);
    TSseArray590[j] = timestamp_se590;
    tempArray590[j] = ts12590;
    FM1Array590[j] = FM1590;
    FM4Array590[j] = FM4590;
    FM5Array590[j] = FM5590;
    if (maxFM1590 < FM1590)
      maxFM1590 = FM1590;
    if (maxts12590 < ts12590)
      maxts12590 = ts12590;
  }


  //run 591
  for (ULong64_t j = 0 ; j < seEvents591 ; j++){
    sourceEpics591 -> GetEvent(j);
    TSseArray591[j] = timestamp_se591;
    tempArray591[j] = ts12591;
    FM1Array591[j] = FM1591;
    FM4Array591[j] = FM4591;
    FM5Array591[j] = FM5591;
    if (maxFM1591 < FM1591)
      maxFM1591 = FM1591;
    if (maxts12591 < ts12591)
      maxts12591 = ts12591;
  }


  //run 592
  for (ULong64_t j = 0 ; j < seEvents592 ; j++){
    sourceEpics592 -> GetEvent(j);
    TSseArray592[j] = timestamp_se592;
    tempArray592[j] = ts12592;
    FM1Array592[j] = FM1592;
    FM4Array592[j] = FM4592;
    FM5Array592[j] = FM5592;
    if (maxFM1592 < FM1592)
      maxFM1592 = FM1592;
    if (maxts12592 < ts12592)
      maxts12592 = ts12592;
  }


  //run 593
  for (ULong64_t j = 0 ; j < seEvents593 ; j++){
    sourceEpics593 -> GetEvent(j);
    TSseArray593[j] = timestamp_se593;
    tempArray593[j] = ts12593;
    FM1Array593[j] = FM1593;
    FM4Array593[j] = FM4593;
    FM5Array593[j] = FM5593;
    if (maxFM1593 < FM1593)
      maxFM1593 = FM1593;
    if (maxts12593 < ts12593)
      maxts12593 = ts12593;
  }

  //run 654
  for (ULong64_t j = 0 ; j < seEvents654 ; j++){
    sourceEpics654 -> GetEvent(j);
    TSseArray654[j] = timestamp_se654;
    tempArray654[j] = ts12654;
    FM1Array654[j] = FM1654;
    FM4Array654[j] = FM4654;
    FM5Array654[j] = FM5654;
    if (maxFM1654 < FM1654)
      maxFM1654 = FM1654;
    if (maxts12654 < ts12654)
      maxts12654 = ts12654;
  }


  //run 659
  for (ULong64_t j = 0 ; j < seEvents659 ; j++){
    sourceEpics659 -> GetEvent(j);
    TSseArray659[j] = timestamp_se659;
    tempArray659[j] = ts12659;
    FM1Array659[j] = FM1659;
    FM4Array659[j] = FM4659;
    FM5Array659[j] = FM5659;
    if (maxFM1659 < FM1659)
      maxFM1659 = FM1659;
    if (maxts12659 < ts12659)
      maxts12659 = ts12659;
  }



  //***********************************
  // Loop over the beamline Tree values
  //***********************************

  //run 765
  for (ULong64_t j = 0; j < blEvent765 ; j++){
    bl765 -> GetEvent(j);
    TSblArray765[j] = timestamp_bl765;
    curArray765[j] = cur765;
  }

  //run 766
  for (ULong64_t j = 0; j < blEvent766 ; j++){
    bl766 -> GetEvent(j);
    TSblArray766[j] = timestamp_bl766;
    curArray766[j] = cur766;
  }

  //run 767
  for (ULong64_t j = 0; j < blEvent767 ; j++){
    bl767 -> GetEvent(j);
    TSblArray767[j] = timestamp_bl767;
    curArray767[j] = cur767;
  }

  //run 768
  for (ULong64_t j = 0; j < blEvent768 ; j++){
    bl768 -> GetEvent(j);
    TSblArray768[j] = timestamp_bl768;
    curArray768[j] = cur768;
  }

  //run 769
  for (ULong64_t j = 0; j < blEvent769 ; j++){
    bl769 -> GetEvent(j);
    TSblArray769[j] = timestamp_bl769;
    curArray769[j] = cur769;
  }

  //run 770
  for (ULong64_t j = 0; j < blEvent770 ; j++){
    bl770 -> GetEvent(j);
    TSblArray770[j] = timestamp_bl770;
    curArray770[j] = cur770;
  }

  //run 771
  for (ULong64_t j = 0; j < blEvent771 ; j++){
    bl771 -> GetEvent(j);
    TSblArray771[j] = timestamp_bl771;
    curArray771[j] = cur771;
  }

  //run 772
  for (ULong64_t j = 0; j < blEvent772 ; j++){
    bl772 -> GetEvent(j);
    TSblArray772[j] = timestamp_bl772;
    curArray772[j] = cur772;
  }

  //run 773
  for (ULong64_t j = 0; j < blEvent773 ; j++){
    bl773 -> GetEvent(j);
    TSblArray773[j] = timestamp_bl773;
    curArray773[j] = cur773;
  }

  //run 778
  for (ULong64_t j = 0; j < blEvent778 ; j++){
    bl778 -> GetEvent(j);
    TSblArray778[j] = timestamp_bl778;
    curArray778[j] = cur778;
  }

  //run 779
  for (ULong64_t j = 0; j < blEvent779 ; j++){
    bl779 -> GetEvent(j);
    TSblArray779[j] = timestamp_bl779;
    curArray779[j] = cur779;
  }

  //run 587
  for (ULong64_t j = 0; j < blEvent587 ; j++){
    bl587 -> GetEvent(j);
    TSblArray587[j] = timestamp_bl587;
    curArray587[j] = cur587;
  }


  //run 588
  for (ULong64_t j = 0; j < blEvent588 ; j++){
    bl588 -> GetEvent(j);
    TSblArray588[j] = timestamp_bl588;
    curArray588[j] = cur588;
  }


  //run 589
  for (ULong64_t j = 0; j < blEvent589 ; j++){
    bl589 -> GetEvent(j);
    TSblArray589[j] = timestamp_bl589;
    curArray589[j] = cur589;
  }

  //run 590
  for (ULong64_t j = 0; j < blEvent590 ; j++){
    bl590 -> GetEvent(j);
    TSblArray590[j] = timestamp_bl590;
    curArray590[j] = cur590;
  }


  //run 591
  for (ULong64_t j = 0; j < blEvent591 ; j++){
    bl591 -> GetEvent(j);
    TSblArray591[j] = timestamp_bl591;
    curArray591[j] = cur591;
  }


  //run 592
  for (ULong64_t j = 0; j < blEvent592 ; j++){
    bl592 -> GetEvent(j);
    TSblArray592[j] = timestamp_bl592;
    curArray592[j] = cur592;
  }


  //run 593
  for (ULong64_t j = 0; j < blEvent593 ; j++){
    bl593 -> GetEvent(j);
    TSblArray593[j] = timestamp_bl593;
    curArray593[j] = cur593;
  }

  //run 654
  for (ULong64_t j = 0; j < blEvent654 ; j++){
    bl654 -> GetEvent(j);
    TSblArray654[j] = timestamp_bl654;
    curArray654[j] = cur654;
  }

  //run 659
  for (ULong64_t j = 0; j < blEvent659 ; j++){
    bl659 -> GetEvent(j);
    TSblArray659[j] = timestamp_bl659;
    curArray659[j] = cur659;
  }

  

#if 1
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



  //run 587
  c587 -> cd(2);
  TGraph *grtemp587 = new TGraph(seEvents587 , TSseArray587 , tempArray587);
  grtemp587 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp587 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp587 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp587 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp587 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp587 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp587 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp587 -> GetXaxis() -> SetNdivisions(10);
  grtemp587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp587 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp587 -> GetXaxis() -> SetLabelSize(.04);
  grtemp587 -> SetMarkerStyle(20);
  grtemp587 -> Draw("AP");

  c587 -> cd(3);
  TGraph *grFM4587 = new TGraph (seEvents587 , TSseArray587 , FM4Array587);
  grFM4587 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4587 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4587 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4587 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4587 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4587 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4587 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4587 -> GetXaxis() -> SetNdivisions(10);
  grFM4587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4587 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4587 -> GetXaxis() -> SetLabelSize(.04);
  grFM4587 -> SetMarkerStyle(20);
  grFM4587 -> Draw("AP");
  
  c587 -> cd(4);
  TGraph *grFM1587 = new TGraph (seEvents587 , TSseArray587 , FM1Array587);
  grFM1587 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1587 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1587 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1587 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1587 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1587 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1587 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1587 -> GetXaxis() -> SetNdivisions(10);
  grFM1587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1587 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1587 -> GetXaxis() -> SetLabelSize(.04);
  grFM1587 -> SetMarkerStyle(20);
  grFM1587 -> Draw("AP");
  
  c587 -> cd(5);
  TGraph *grFM5587 = new TGraph (seEvents587 , TSseArray587 , FM5Array587);
  grFM5587 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5587 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5587 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5587 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5587 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5587 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5587 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5587 -> GetXaxis() -> SetNdivisions(10);
  grFM5587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5587 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5587 -> GetXaxis() -> SetLabelSize(.04);
  grFM5587 -> SetMarkerStyle(20);
  grFM5587 -> Draw("AP");


  c587 -> cd(6);
  TGraph *grBL587 = new TGraph (blEvent587 , TSblArray587 , curArray587);
  grBL587 -> SetTitle(" Predicted current vs Time ");
  grBL587 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL587 -> GetXaxis() -> SetTitleSize(0.05);
  grBL587 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL587 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL587 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL587 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL587 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL587 -> GetXaxis() -> SetNdivisions(10);
  grBL587 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL587 -> GetXaxis() -> SetLabelOffset(.03);
  grBL587 -> GetXaxis() -> SetLabelSize(.04);
  grBL587 -> SetMarkerStyle(20);
  grBL587 -> Draw("AP");




  //run 588
  c588 -> cd(2);
  TGraph *grtemp588 = new TGraph(seEvents588 , TSseArray588 , tempArray588);
  grtemp588 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp588 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp588 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp588 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp588 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp588 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp588 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp588 -> GetXaxis() -> SetNdivisions(10);
  grtemp588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp588 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp588 -> GetXaxis() -> SetLabelSize(.04);
  grtemp588 -> SetMarkerStyle(20);
  grtemp588 -> Draw("AP");

  c588 -> cd(3);
  TGraph *grFM4588 = new TGraph (seEvents588 , TSseArray588 , FM4Array588);
  grFM4588 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4588 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4588 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4588 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4588 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4588 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4588 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4588 -> GetXaxis() -> SetNdivisions(10);
  grFM4588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4588 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4588 -> GetXaxis() -> SetLabelSize(.04);
  grFM4588 -> SetMarkerStyle(20);
  grFM4588 -> Draw("AP");
  
  c588 -> cd(4);
  TGraph *grFM1588 = new TGraph (seEvents588 , TSseArray588 , FM1Array588);
  grFM1588 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1588 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1588 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1588 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1588 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1588 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1588 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1588 -> GetXaxis() -> SetNdivisions(10);
  grFM1588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1588 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1588 -> GetXaxis() -> SetLabelSize(.04);
  grFM1588 -> SetMarkerStyle(20);
  grFM1588 -> Draw("AP");
  
  c588 -> cd(5);
  TGraph *grFM5588 = new TGraph (seEvents588 , TSseArray588 , FM5Array588);
  grFM5588 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5588 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5588 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5588 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5588 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5588 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5588 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5588 -> GetXaxis() -> SetNdivisions(10);
  grFM5588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5588 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5588 -> GetXaxis() -> SetLabelSize(.04);
  grFM5588 -> SetMarkerStyle(20);
  grFM5588 -> Draw("AP");


  c588 -> cd(6);
  TGraph *grBL588 = new TGraph (blEvent588 , TSblArray588 , curArray588);
  grBL588 -> SetTitle(" Predicted current vs Time ");
  grBL588 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL588 -> GetXaxis() -> SetTitleSize(0.05);
  grBL588 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL588 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL588 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL588 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL588 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL588 -> GetXaxis() -> SetNdivisions(10);
  grBL588 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL588 -> GetXaxis() -> SetLabelOffset(.03);
  grBL588 -> GetXaxis() -> SetLabelSize(.04);
  grBL588 -> SetMarkerStyle(20);
  grBL588 -> Draw("AP");
  


  //run 589
  c589 -> cd(2);
  TGraph *grtemp589 = new TGraph(seEvents589 , TSseArray589 , tempArray589);
  grtemp589 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp589 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp589 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp589 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp589 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp589 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp589 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp589 -> GetXaxis() -> SetNdivisions(10);
  grtemp589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp589 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp589 -> GetXaxis() -> SetLabelSize(.04);
  grtemp589 -> SetMarkerStyle(20);
  grtemp589 -> Draw("AP");

  c589 -> cd(3);
  TGraph *grFM4589 = new TGraph (seEvents589 , TSseArray589 , FM4Array589);
  grFM4589 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4589 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4589 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4589 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4589 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4589 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4589 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4589 -> GetXaxis() -> SetNdivisions(10);
  grFM4589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4589 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4589 -> GetXaxis() -> SetLabelSize(.04);
  grFM4589 -> SetMarkerStyle(20);
  grFM4589 -> Draw("AP");
  
  c589 -> cd(4);
  TGraph *grFM1589 = new TGraph (seEvents589 , TSseArray589 , FM1Array589);
  grFM1589 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1589 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1589 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1589 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1589 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1589 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1589 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1589 -> GetXaxis() -> SetNdivisions(10);
  grFM1589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1589 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1589 -> GetXaxis() -> SetLabelSize(.04);
  grFM1589 -> SetMarkerStyle(20);
  grFM1589 -> Draw("AP");
  
  c589 -> cd(5);
  TGraph *grFM5589 = new TGraph (seEvents589 , TSseArray589 , FM5Array589);
  grFM5589 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5589 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5589 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5589 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5589 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5589 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5589 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5589 -> GetXaxis() -> SetNdivisions(10);
  grFM5589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5589 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5589 -> GetXaxis() -> SetLabelSize(.04);
  grFM5589 -> SetMarkerStyle(20);
  grFM5589 -> Draw("AP");


  c589 -> cd(6);
  TGraph *grBL589 = new TGraph (blEvent589 , TSblArray589 , curArray589);
  grBL589 -> SetTitle(" Predicted current vs Time ");
  grBL589 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL589 -> GetXaxis() -> SetTitleSize(0.05);
  grBL589 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL589 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL589 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL589 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL589 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL589 -> GetXaxis() -> SetNdivisions(10);
  grBL589 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL589 -> GetXaxis() -> SetLabelOffset(.03);
  grBL589 -> GetXaxis() -> SetLabelSize(.04);
  grBL589 -> SetMarkerStyle(20);
  grBL589 -> Draw("AP");



  //run 590
  c590 -> cd(2);
  TGraph *grtemp590 = new TGraph(seEvents590 , TSseArray590 , tempArray590);
  grtemp590 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp590 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp590 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp590 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp590 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp590 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp590 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp590 -> GetXaxis() -> SetNdivisions(10);
  grtemp590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp590 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp590 -> GetXaxis() -> SetLabelSize(.04);
  grtemp590 -> SetMarkerStyle(20);
  grtemp590 -> Draw("AP");

  c590 -> cd(3);
  TGraph *grFM4590 = new TGraph (seEvents590 , TSseArray590 , FM4Array590);
  grFM4590 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4590 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4590 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4590 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4590 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4590 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4590 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4590 -> GetXaxis() -> SetNdivisions(10);
  grFM4590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4590 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4590 -> GetXaxis() -> SetLabelSize(.04);
  grFM4590 -> SetMarkerStyle(20);
  grFM4590 -> Draw("AP");
  
  c590 -> cd(4);
  TGraph *grFM1590 = new TGraph (seEvents590 , TSseArray590 , FM1Array590);
  grFM1590 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1590 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1590 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1590 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1590 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1590 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1590 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1590 -> GetXaxis() -> SetNdivisions(10);
  grFM1590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1590 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1590 -> GetXaxis() -> SetLabelSize(.04);
  grFM1590 -> SetMarkerStyle(20);
  grFM1590 -> Draw("AP");
  
  c590 -> cd(5);
  TGraph *grFM5590 = new TGraph (seEvents590 , TSseArray590 , FM5Array590);
  grFM5590 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5590 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5590 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5590 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5590 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5590 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5590 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5590 -> GetXaxis() -> SetNdivisions(10);
  grFM5590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5590 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5590 -> GetXaxis() -> SetLabelSize(.04);
  grFM5590 -> SetMarkerStyle(20);
  grFM5590 -> Draw("AP");


  c590 -> cd(6);
  TGraph *grBL590 = new TGraph (blEvent590 , TSblArray590 , curArray590);
  grBL590 -> SetTitle(" Predicted current vs Time ");
  grBL590 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL590 -> GetXaxis() -> SetTitleSize(0.05);
  grBL590 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL590 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL590 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL590 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL590 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL590 -> GetXaxis() -> SetNdivisions(10);
  grBL590 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL590 -> GetXaxis() -> SetLabelOffset(.03);
  grBL590 -> GetXaxis() -> SetLabelSize(.04);
  grBL590 -> SetMarkerStyle(20);
  grBL590 -> Draw("AP");



  //run 591
  c591 -> cd(2);
  TGraph *grtemp591 = new TGraph(seEvents591 , TSseArray591 , tempArray591);
  grtemp591 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp591 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp591 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp591 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp591 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp591 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp591 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp591 -> GetXaxis() -> SetNdivisions(10);
  grtemp591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp591 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp591 -> GetXaxis() -> SetLabelSize(.04);
  grtemp591 -> SetMarkerStyle(20);
  grtemp591 -> Draw("AP");

  c591 -> cd(3);
  TGraph *grFM4591 = new TGraph (seEvents591 , TSseArray591 , FM4Array591);
  grFM4591 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4591 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4591 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4591 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4591 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4591 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4591 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4591 -> GetXaxis() -> SetNdivisions(10);
  grFM4591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4591 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4591 -> GetXaxis() -> SetLabelSize(.04);
  grFM4591 -> SetMarkerStyle(20);
  grFM4591 -> Draw("AP");
  
  c591 -> cd(4);
  TGraph *grFM1591 = new TGraph (seEvents591 , TSseArray591 , FM1Array591);
  grFM1591 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1591 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1591 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1591 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1591 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1591 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1591 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1591 -> GetXaxis() -> SetNdivisions(10);
  grFM1591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1591 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1591 -> GetXaxis() -> SetLabelSize(.04);
  grFM1591 -> SetMarkerStyle(20);
  grFM1591 -> Draw("AP");
  
  c591 -> cd(5);
  TGraph *grFM5591 = new TGraph (seEvents591 , TSseArray591 , FM5Array591);
  grFM5591 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5591 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5591 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5591 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5591 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5591 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5591 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5591 -> GetXaxis() -> SetNdivisions(10);
  grFM5591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5591 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5591 -> GetXaxis() -> SetLabelSize(.04);
  grFM5591 -> SetMarkerStyle(20);
  grFM5591 -> Draw("AP");


  c591 -> cd(6);
  TGraph *grBL591 = new TGraph (blEvent591 , TSblArray591 , curArray591);
  grBL591 -> SetTitle(" Predicted current vs Time ");
  grBL591 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL591 -> GetXaxis() -> SetTitleSize(0.05);
  grBL591 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL591 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL591 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL591 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL591 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL591 -> GetXaxis() -> SetNdivisions(10);
  grBL591 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL591 -> GetXaxis() -> SetLabelOffset(.03);
  grBL591 -> GetXaxis() -> SetLabelSize(.04);
  grBL591 -> SetMarkerStyle(20);
  grBL591 -> Draw("AP");


  //run 592
  c592 -> cd(2);
  TGraph *grtemp592 = new TGraph(seEvents592 , TSseArray592 , tempArray592);
  grtemp592 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp592 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp592 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp592 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp592 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp592 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp592 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp592 -> GetXaxis() -> SetNdivisions(10);
  grtemp592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp592 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp592 -> GetXaxis() -> SetLabelSize(.04);
  grtemp592 -> SetMarkerStyle(20);
  grtemp592 -> Draw("AP");

  c592 -> cd(3);
  TGraph *grFM4592 = new TGraph (seEvents592 , TSseArray592 , FM4Array592);
  grFM4592 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4592 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4592 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4592 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4592 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4592 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4592 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4592 -> GetXaxis() -> SetNdivisions(10);
  grFM4592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4592 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4592 -> GetXaxis() -> SetLabelSize(.04);
  grFM4592 -> SetMarkerStyle(20);
  grFM4592 -> Draw("AP");
  
  c592 -> cd(4);
  TGraph *grFM1592 = new TGraph (seEvents592 , TSseArray592 , FM1Array592);
  grFM1592 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1592 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1592 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1592 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1592 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1592 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1592 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1592 -> GetXaxis() -> SetNdivisions(10);
  grFM1592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1592 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1592 -> GetXaxis() -> SetLabelSize(.04);
  grFM1592 -> SetMarkerStyle(20);
  grFM1592 -> Draw("AP");
  
  c592 -> cd(5);
  TGraph *grFM5592 = new TGraph (seEvents592 , TSseArray592 , FM5Array592);
  grFM5592 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5592 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5592 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5592 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5592 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5592 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5592 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5592 -> GetXaxis() -> SetNdivisions(10);
  grFM5592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5592 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5592 -> GetXaxis() -> SetLabelSize(.04);
  grFM5592 -> SetMarkerStyle(20);
  grFM5592 -> Draw("AP");


  c592 -> cd(6);
  TGraph *grBL592 = new TGraph (blEvent592 , TSblArray592 , curArray592);
  grBL592 -> SetTitle(" Predicted current vs Time ");
  grBL592 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL592 -> GetXaxis() -> SetTitleSize(0.05);
  grBL592 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL592 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL592 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL592 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL592 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL592 -> GetXaxis() -> SetNdivisions(10);
  grBL592 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL592 -> GetXaxis() -> SetLabelOffset(.03);
  grBL592 -> GetXaxis() -> SetLabelSize(.04);
  grBL592 -> SetMarkerStyle(20);
  grBL592 -> Draw("AP");
  

  //run 593
  c593 -> cd(2);
  TGraph *grtemp593 = new TGraph(seEvents593 , TSseArray593 , tempArray593);
  grtemp593 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp593 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp593 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp593 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp593 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp593 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp593 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp593 -> GetXaxis() -> SetNdivisions(10);
  grtemp593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp593 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp593 -> GetXaxis() -> SetLabelSize(.04);
  grtemp593 -> SetMarkerStyle(20);
  grtemp593 -> Draw("AP");

  c593 -> cd(3);
  TGraph *grFM4593 = new TGraph (seEvents593 , TSseArray593 , FM4Array593);
  grFM4593 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4593 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4593 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4593 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4593 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4593 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4593 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4593 -> GetXaxis() -> SetNdivisions(10);
  grFM4593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4593 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4593 -> GetXaxis() -> SetLabelSize(.04);
  grFM4593 -> SetMarkerStyle(20);
  grFM4593 -> Draw("AP");
  
  c593 -> cd(4);
  TGraph *grFM1593 = new TGraph (seEvents593 , TSseArray593 , FM1Array593);
  grFM1593 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1593 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1593 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1593 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1593 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1593 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1593 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1593 -> GetXaxis() -> SetNdivisions(10);
  grFM1593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1593 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1593 -> GetXaxis() -> SetLabelSize(.04);
  grFM1593 -> SetMarkerStyle(20);
  grFM1593 -> Draw("AP");
  
  c593 -> cd(5);
  TGraph *grFM5593 = new TGraph (seEvents593 , TSseArray593 , FM5Array593);
  grFM5593 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5593 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5593 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5593 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5593 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5593 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5593 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5593 -> GetXaxis() -> SetNdivisions(10);
  grFM5593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5593 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5593 -> GetXaxis() -> SetLabelSize(.04);
  grFM5593 -> SetMarkerStyle(20);
  grFM5593 -> Draw("AP");


  c593 -> cd(6);
  TGraph *grBL593 = new TGraph (blEvent593 , TSblArray593 , curArray593);
  grBL593 -> SetTitle(" Predicted current vs Time ");
  grBL593 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL593 -> GetXaxis() -> SetTitleSize(0.05);
  grBL593 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL593 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL593 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL593 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL593 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL593 -> GetXaxis() -> SetNdivisions(10);
  grBL593 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL593 -> GetXaxis() -> SetLabelOffset(.03);
  grBL593 -> GetXaxis() -> SetLabelSize(.04);
  grBL593 -> SetMarkerStyle(20);
  grBL593 -> Draw("AP");


  //run 654
  c654 -> cd(2);
  TGraph *grtemp654 = new TGraph(seEvents654 , TSseArray654 , tempArray654);
  grtemp654 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp654 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp654 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp654 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp654 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp654 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp654 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp654 -> GetXaxis() -> SetNdivisions(10);
  grtemp654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp654 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp654 -> GetXaxis() -> SetLabelSize(.04);
  grtemp654 -> SetMarkerStyle(20);
  grtemp654 -> Draw("AP");

  c654 -> cd(3);
  TGraph *grFM4654 = new TGraph (seEvents654 , TSseArray654 , FM4Array654);
  grFM4654 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4654 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4654 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4654 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4654 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4654 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4654 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4654 -> GetXaxis() -> SetNdivisions(10);
  grFM4654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4654 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4654 -> GetXaxis() -> SetLabelSize(.04);
  grFM4654 -> SetMarkerStyle(20);
  grFM4654 -> Draw("AP");
  
  c654 -> cd(4);
  TGraph *grFM1654 = new TGraph (seEvents654 , TSseArray654 , FM1Array654);
  grFM1654 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1654 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1654 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1654 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1654 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1654 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1654 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1654 -> GetXaxis() -> SetNdivisions(10);
  grFM1654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1654 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1654 -> GetXaxis() -> SetLabelSize(.04);
  grFM1654 -> SetMarkerStyle(20);
  grFM1654 -> Draw("AP");
  
  c654 -> cd(5);
  TGraph *grFM5654 = new TGraph (seEvents654 , TSseArray654 , FM5Array654);
  grFM5654 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5654 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5654 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5654 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5654 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5654 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5654 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5654 -> GetXaxis() -> SetNdivisions(10);
  grFM5654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5654 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5654 -> GetXaxis() -> SetLabelSize(.04);
  grFM5654 -> SetMarkerStyle(20);
  grFM5654 -> Draw("AP");


  c654 -> cd(6);
  TGraph *grBL654 = new TGraph (blEvent654 , TSblArray654 , curArray654);
  grBL654 -> SetTitle(" Predicted current vs Time ");
  grBL654 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL654 -> GetXaxis() -> SetTitleSize(0.05);
  grBL654 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL654 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL654 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL654 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL654 -> GetXaxis() -> SetNdivisions(10);
  grBL654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL654 -> GetXaxis() -> SetLabelOffset(.03);
  grBL654 -> GetXaxis() -> SetLabelSize(.04);
  grBL654 -> SetMarkerStyle(20);
  grBL654 -> Draw("AP");


  //run 659
  c659 -> cd(2);
  TGraph *grtemp659 = new TGraph(seEvents659 , TSseArray659 , tempArray659);
  grtemp659 -> SetTitle(" Isopure Helium Temperature vs Time ");
  grtemp659 -> GetYaxis()-> SetTitle("Isopure Helium Temperature (K)" );
  grtemp659 -> GetXaxis() -> SetTitleSize(0.05);
  grtemp659 -> GetXaxis() -> SetTitleOffset(1.3);
  grtemp659 -> GetYaxis() -> SetTitleSize(0.05); 
  grtemp659 -> GetYaxis() -> SetTitleOffset(0.9);
  grtemp659 -> GetXaxis() -> SetTimeDisplay(1);
  //grtemp659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grtemp659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grtemp659 -> GetXaxis() -> SetNdivisions(10);
  grtemp659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grtemp659 -> GetXaxis() -> SetLabelOffset(.03);
  grtemp659 -> GetXaxis() -> SetLabelSize(.04);
  grtemp659 -> SetMarkerStyle(20);
  grtemp659 -> Draw("AP");

  c659 -> cd(3);
  TGraph *grFM4659 = new TGraph (seEvents659 , TSseArray659 , FM4Array659);
  grFM4659 -> SetTitle(" ^{4}He Flow Rate (FM4) vs Time ");
  grFM4659 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM4659 -> GetXaxis() -> SetTitleSize(0.05);
  grFM4659 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM4659 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM4659 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM4659 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM4659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM4659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM4659 -> GetXaxis() -> SetNdivisions(10);
  grFM4659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM4659 -> GetXaxis() -> SetLabelOffset(.03);
  grFM4659 -> GetXaxis() -> SetLabelSize(.04);
  grFM4659 -> SetMarkerStyle(20);
  grFM4659 -> Draw("AP");
  
  c659 -> cd(4);
  TGraph *grFM1659 = new TGraph (seEvents659 , TSseArray659 , FM1Array659);
  grFM1659 -> SetTitle(" ^{3}He Flow Rate vs Time ");
  grFM1659 -> GetYaxis()-> SetTitle("^{3}He Flow Rate (lpm)" );
  grFM1659 -> GetXaxis() -> SetTitleSize(0.05);
  grFM1659 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM1659 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM1659 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM1659 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM1659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM1659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM1659 -> GetXaxis() -> SetNdivisions(10);
  grFM1659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM1659 -> GetXaxis() -> SetLabelOffset(.03);
  grFM1659 -> GetXaxis() -> SetLabelSize(.04);
  grFM1659 -> SetMarkerStyle(20);
  grFM1659 -> Draw("AP");
  
  c659 -> cd(5);
  TGraph *grFM5659 = new TGraph (seEvents659 , TSseArray659 , FM5Array659);
  grFM5659 -> SetTitle(" ^{4}He Flow Rate (FM5) vs Time ");
  grFM5659 -> GetYaxis()-> SetTitle("^{4}He Flow Rate (lpm)" );
  grFM5659 -> GetXaxis() -> SetTitleSize(0.05);
  grFM5659 -> GetXaxis() -> SetTitleOffset(1.3);
  grFM5659 -> GetYaxis() -> SetTitleSize(0.05); 
  grFM5659 -> GetYaxis() -> SetTitleOffset(0.9);
  grFM5659 -> GetXaxis() -> SetTimeDisplay(1);
  //grFM5659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grFM5659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grFM5659 -> GetXaxis() -> SetNdivisions(10);
  grFM5659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grFM5659 -> GetXaxis() -> SetLabelOffset(.03);
  grFM5659 -> GetXaxis() -> SetLabelSize(.04);
  grFM5659 -> SetMarkerStyle(20);
  grFM5659 -> Draw("AP");


  c659 -> cd(6);
  TGraph *grBL659 = new TGraph (blEvent659 , TSblArray659 , curArray659);
  grBL659 -> SetTitle(" Predicted current vs Time ");
  grBL659 -> GetYaxis()-> SetTitle("Predicted Current (#muA)" );
  grBL659 -> GetXaxis() -> SetTitleSize(0.05);
  grBL659 -> GetXaxis() -> SetTitleOffset(1.3);
  grBL659 -> GetYaxis() -> SetTitleSize(0.05); 
  grBL659 -> GetYaxis() -> SetTitleOffset(0.9);
  grBL659 -> GetXaxis() -> SetTimeDisplay(1);
  //grBL659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  grBL659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b %d}");
  grBL659 -> GetXaxis() -> SetNdivisions(10);
  grBL659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  grBL659 -> GetXaxis() -> SetLabelOffset(.03);
  grBL659 -> GetXaxis() -> SetLabelSize(.04);
  grBL659 -> SetMarkerStyle(20);
  grBL659 -> Draw("AP");
  
  
  
#endif 
  // *************************************************************
  // I like to make a graph of Florian Rehm's data written in his
  // thesis.
  // ************************************************************


  double power[17] = {2.5, 12.5, 25, 75, 250, 25, 50, 75, 100, 150, 200, 250, 25, 50, 75, 100, 200}; //mW
  double ts12_low[17] = {0.926, 0.924, 0.919, 0.922, 0.93, 0.84, 0.84, 0.85, 0.85, 0.84, 0.84, 0.84,0.93, 0.93, 0.93, 0.93, 0.93};
  double ts12_high[17] = {0.9271, 0.929, 0.929, 0.952, 1, 0.86, 0.9, 0.92, 0.96, 0.99, 1.23, 1.345, 0.95, 0.97, 0.99, 1.075, 1.225};
  double deltaT[17];

  //double beam[] = {0.1};
  // double ts12_low_run[] = {0.84};
  //  double ts12_

    
  int size = (sizeof(power)/sizeof(*power));

  
  for (int i=0 ; i < size ; i++){
    deltaT[i] = ts12_high[i] - ts12_low[i] ;
  }

  TF1 *f1 = new TF1("f1" , "pow(x,[0])*exp([1])", 0.00, 1);
  f1 -> SetParameter(0, 0.8);
  f1 -> SetParameter(1,6.3);
  f1 -> SetParLimits(0, 0.73, 0.8);
  f1 -> SetParLimits(1, 6.15, 6.4);


  TCanvas *cHT = new TCanvas ("cHT" , "cHT", 1200 , 900);
  cHT -> SetLogx();
  cHT -> SetLogy();
  TGraph * grHT = new TGraph(i , deltaT, power);
  grHT -> SetTitle(" Heater power vs Change in the TS12 Temperature  ");
  grHT -> GetYaxis()-> SetTitle("Heater Power (mW)" );
  grHT -> GetXaxis() -> SetTitle(" Change in TS12 Temperature(K)");
  grHT -> GetXaxis() -> SetLimits(0., 1);
  grHT -> GetYaxis() -> SetRangeUser(0,500);
  grHT -> GetXaxis() -> SetTitleSize(0.05);
  grHT -> GetXaxis() -> SetTitleOffset(0.9);
  grHT -> GetYaxis() -> SetTitleSize(0.05); 
  grHT -> GetYaxis() -> SetTitleOffset(0.9);
  grHT -> SetMarkerStyle(20);
  //  grHT -> Fit("f1");
  grHT -> Draw("AP");


  double FM1_low[17] = {11, 11, 10.7, 11, 11,  13.9, 13.9, 14.4, 14.8, 14.8, 14, 14.2, 12.5, 11.75, 11.8, 11.8, 12.2};
  double FM1_high[17] = {11.5, 12., 11.8, 14.8, 22.,14.6, 15.7, 17.7, 18.7, 21.2, 20.8, 22.6,13.2, 13.7, 14.7, 15.2, 19.5  };
  double deltaFM1[17];

  for (int i=0 ; i < size ; i++){
    deltaFM1[i] = FM1_high[i] - FM1_low[i] ;
  }


  TF1 *f2 = new TF1 ("f2" , "[0]*x", 0, 15);
  
  TF1 *ftheory = new TF1 ("ftheory" , "[0] *x" , 0 , 15);
  ftheory -> SetParameter(0, 25.63);

  TCanvas *cHFM = new TCanvas ("cHFM" , "cHFM", 1200 , 900);
  //cHFM -> SetLogx();
  //cHFM -> SetLogy();
  TGraph * grHFM = new TGraph(i , deltaFM1, power);
  grHFM -> SetTitle(" Heater power vs Change in the FM1 Flow Rate  ");
  grHFM -> GetYaxis()-> SetTitle("Heater Power (mW)" );
  grHFM -> GetXaxis() -> SetTitle(" Change in FM1 (He3) Flow Rate (LPM)");
  // grHFM -> GetXaxis() -> SetLimits(0., 1);
  grHFM -> GetXaxis() -> SetTitleSize(0.05);
  grHFM -> GetXaxis() -> SetTitleOffset(0.9);
  grHFM -> GetYaxis() -> SetTitleSize(0.05); 
  grHFM -> GetYaxis() -> SetTitleOffset(0.9);
  grHFM -> SetMarkerStyle(20);
  grHFM -> Fit("f2");

  TLegend *leg1 = new TLegend (0.8, 0.8, 1, 1);
  leg1 -> AddEntry(ftheory, "Calculation From Hepack" , "l");
  leg1 -> AddEntry(f2, "Fit Function" , "l");
  
  grHFM -> Draw("AP");
  ftheory -> SetLineColor(8);
  ftheory -> Draw("same");
  leg1 -> Draw();

  double slope1 = f2 -> GetParameter(0);
  double slope1Err = 0;
  //slope1Err = f2 -> GetParError(0);

  double runs[5] = { 766, 768, 779, 654, 659};
  double beam[5] = {0.1, 0.5, 0.9, 3, 2};
  double DeltaFM1Measured[5];
  double FM1_low_measured[5] = {14.4 , 16.5 , 15.5, 15.4, 14.5};
  double FM1_high_measured[5] = {15.8, 18.2, 19.1, 21.4, 16.9};

  for (int i = 0; i < 5 ; i++){
    DeltaFM1Measured[i] = FM1_high_measured[i] - FM1_low_measured[i];
  }


  
  TCanvas *cHFMm = new TCanvas ("cHFMm" , "cHFMm", 1200 , 900);
  cHFMm -> Divide(2,1);
  //cHFMm -> SetLogx();
  //cHFMm -> SetLogy();
  cHFMm -> cd(1);
  TGraph * grHFMm = new TGraph(5 , DeltaFM1Measured, beam);
  grHFMm -> SetTitle(" Beam Current vs Change in the FM1 Flow Rate  ");
  grHFMm -> GetYaxis()-> SetTitle("Beam Current (#muA)" );
  grHFMm -> GetXaxis() -> SetTitle(" Change in FM1 (He3) Flow Rate (LPM)");
  // grHFMm -> GetXaxis() -> SetLimits(0., 1);
  grHFMm -> GetXaxis() -> SetTitleSize(0.05);
  grHFMm -> GetXaxis() -> SetTitleOffset(0.9);
  grHFMm -> GetYaxis() -> SetTitleSize(0.05); 
  grHFMm -> GetYaxis() -> SetTitleOffset(0.9);
  grHFMm -> SetMarkerStyle(20);
  grHFMm -> Fit("f2");
  grHFMm -> Draw("AP");

  double slope2 = f2 -> GetParameter(0);
  double slope2Err = f2 -> GetParError(0);

  double slope = slope1/slope2;
  double slopeErr = slope * sqrt(slope1Err*slope1Err/ (slope1*slope1) + slope2Err*slope2Err/(slope2*slope2));

  TCanvas *cQB = new TCanvas("cQB" , "cQB" , 1200, 900);
  TF1 *f1QB = new TF1("f1QB" , "[0]*x" , 0, 10);
  f1QB -> SetParameter(0, slope+slopeErr);

  
  TF1 *f2QB = new TF1("f2QB" , "[0]*x" , 0, 10);
  f2QB -> SetParameter(0, slope-slopeErr);

  TF1 *fQB = new TF1 ("fQB" , "[0]*x" , 0 , 10);
   fQB -> SetParameter(0, slope);
  
  f1QB -> SetTitle ("Heat Load vs Beam Current" );
  f1QB -> GetXaxis() -> SetTitle("Beam Current (#muA)");
  f1QB -> GetYaxis() -> SetTitle("Heat Load (mW)");
  f1QB -> SetLineColor(8);

  TLegend *leg2 = new TLegend (0.7, 0.7 , 0.9, 0.9);
  leg2 -> AddEntry(f1QB , "Upper Limit" , "l");
  leg2 -> AddEntry(f2QB , "Lower Limit" , "l");

  
  f1QB -> Draw();
  f2QB -> Draw("same");
  fQB -> SetLineColor(1);
  fQB -> SetLineStyle(9);
  fQB -> Draw("same");
  leg2 -> Draw();
  
  cout << "slope1 " << slope1 << " slope1Err " << slope1Err<< endl;
  cout << "slope2 " << slope2 << " slope2Err " << slope2Err << endl;
  cout << "slope " << slope<< " slopeErr " << slopeErr << endl;



  //*************************************************************
  // now with total flow

  double FM1tot [5] = {maxFM1766 , maxFM1768, maxFM1779, maxFM1654, maxFM1659};

  TF1 *ftotB = new TF1 ("ftotB" , "[0]*x + [1]", 0 , 25);

  //TCanvas *cFtotB = new TCanvas ("cFtotB" , "cFtotB" , 1200, 900);
  cHFMm -> cd(2);
  TGraph * grFtotB = new TGraph(5 , FM1tot, beam);
  grFtotB -> SetTitle(" Beam Current vs Saturated FM1 Flow Rate  ");
  grFtotB -> GetYaxis()-> SetTitle("Beam Current (#muA)" );
  grFtotB -> GetXaxis() -> SetTitle(" Saturated FM1 (He3) Flow Rate (LPM)");
  // grFtotB -> GetXaxis() -> SetLimits(0., 1);
  grFtotB -> GetXaxis() -> SetTitleSize(0.05);
  grFtotB -> GetXaxis() -> SetTitleOffset(0.9);
  grFtotB -> GetYaxis() -> SetTitleSize(0.05); 
  grFtotB -> GetYaxis() -> SetTitleOffset(0.9);
  grFtotB -> SetMarkerStyle(20);
  grFtotB -> Fit(ftotB);
  grFtotB -> Draw("AP");
  
}
