// ***************************************************
// THIS SCRIPT IS TO ANALYZE TCN17007A.
// STEADY STATE PRODUCTION
// ***************************************************

#include <string>
#include <fstream>

#define max 100

// Define the time offset as 2017, November 18
TDatime T0(2017,11,18,00,00,00);
int X0 = T0.Convert();
gStyle->SetTimeOffset(X0);

// Define the lowest histogram limit as 2017, Nov 18
TDatime T1(2017,11,18,13,00,46);
int X1 = T1.Convert();

// Define the highest histogram limit as 2017, Nov 18
TDatime T2(2017,11,18,13,12,58);
int X2 = T2.Convert()-X1;

// Define beam on time for run 654
TDatime T3(2017,11,18,13,01,16);
int bontime654 = T3.Convert();

// Define beam off time for run 659
TDatime T4(2017,11,18,13,11,14);
int bofftime = T4.Convert();

double temp(double time) {
  double t1 = 1511038876; // beam on for 654
  double t2 = 1511039474; // beam off for 654
  double temptemp;
  //temptemp=0.87+(1.24-.87)*(time - )/(b - X1);
  temptemp = (1.24 - 0.87)*time/ (t2 - t1) + ((0.87*t2 - 1.24*t1)/(t2 - t1));
  if(time>t2){
    temptemp=1.24;
  }
  return temptemp;
}


double dndetdt(double time) {
  double t1 = 1511038876; // beam on for 654
  double t2 = 1511039474; // beam off for 654
  
  double tau_loss=35.; //s
  double area=3.14159*.0425*.0425; // m^2
  double vsource=27./1000.; //m^3
  double vheii=8.5/1000.; //m^3
  double vguide=3.6*3.14159*pow(.085/2,2);//m^3
  double volume=vsource+vguide; //m^3    
  double v=1.;//m/s
  double tau_det=1./(v*area/(4*volume));//s
  double f=vheii/volume; //volume fraction of He-II
  double b=.032;//s^-1K^-7
  double mytemp=temp(time);//K
  double tau_tot=1./(f*b*pow(mytemp,7)+1./tau_loss+1./tau_det);//s
  double p=7200.;//s^-1
  double n_tot=p*tau_tot*(1-exp(-(time - t1)/tau_tot));
  if(time>t2)
    //n_tot=p*tau_tot*(1-exp(-10*60/tau_tot))*exp(-(time+X0 -10*60)/tau_tot);
    n_tot=p*tau_tot*(1-exp(-t2/tau_tot))*exp(-(time -t2)/tau_tot);
  return n_tot/tau_det;
}

double testfunc(double *x, double *par) {
   double s;
   s = dndetdt(x[0]);
   return s;
}

double tempfunc(double *x, double *par) {
   double s;
   s = temp(x[0]);
   return s;
}


void UCNRate_analysis_TCN17007A_Taraneh_edit_ver1(){

  TF1 *f1 = new TF1("f1",testfunc,1511038846,1511039578,0); // fit function for the rate
  TF1 *f2 = new TF1 ("f2" , tempfunc ,1511038846 , 1511039578, 0 );

  TFile *fin654 = new TFile ("~/raw_Data/ucn_tree_00000654.root", "READ");
  TFile *fin659 = new TFile ("~/raw_Data/ucn_tree_00000659.root", "READ");

  
  TTree *uinli6654 = (TTree*) fin654 -> Get("UCNHits_Li-6");
  TTree *uinli6659 = (TTree*) fin659 -> Get("UCNHits_Li-6");
  
  TTree *bl654 = (TTree*) fin654 -> Get("BeamlineEpicsTree");
  TTree *bl659 = (TTree*) fin659 -> Get("BeamlineEpicsTree");
  
  TTree *sourceEpics654 = (TTree*) fin654 -> Get("SourceEpicsTree");
  TTree *sourceEpics659 = (TTree*) fin659 -> Get("SourceEpicsTree");  
  

  double tUnixTimePrecise654;
  double tUnixTimePrecise659;
  
  double tUnixTime654;
  double tUnixTime659;
  
  UShort_t tIsUCN654;
  UShort_t tIsUCN659;
  
  double cur654;
  double cur659;
  
  double ts12654;
  double ts12659;

  double curArray654 [1000000];
  double curArray659 [1000000];

  double curAve654;
  double curAve659;

  double ts12Ave654;
  double ts12Ave659;

  int timestamp_bl654;
  int timestamp_bl659;

  int timestamp_se654;
  int timestamp_se659;

  double TSArray654 [1000000];
  double TSArray659 [1000000];

  double TSArrayse654 [1000000];
  double TSArrayse659 [1000000];

  double tempArray654 [1000000];
  double tempArray659 [1000000];

  Double_t min654 = 15400000000;
  Double_t min659 = 15400000000;

  Double_t max654 = 0.;
  Double_t max659 = 0.;
    
  Int_t NBins654;
  Int_t NBins659;

  uinli6654 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise654);
  uinli6659 -> SetBranchAddress ("tUnixTimePrecise", &tUnixTimePrecise659);
  
  uinli6654 -> SetBranchAddress ("tUnixTime", &tUnixTime654);
  uinli6659 -> SetBranchAddress ("tUnixTime", &tUnixTime659);

  uinli6654 -> SetBranchAddress ("tIsUCN" , &tIsUCN654);
  uinli6659 -> SetBranchAddress ("tIsUCN" , &tIsUCN659);

  bl654 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur654);
  bl659 -> SetBranchAddress ("B1V_KSM_PREDCUR", &cur659);

  bl654 -> SetBranchAddress ("timestamp", &timestamp_bl654);
  bl659 -> SetBranchAddress ("timestamp", &timestamp_bl659);

  sourceEpics654 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12654);
  sourceEpics659 -> SetBranchAddress ("UCN_ISO_TS12_RDTEMP" , &ts12659);

  sourceEpics654 -> SetBranchAddress ("timestamp", &timestamp_se654);
  sourceEpics659 -> SetBranchAddress ("timestamp", &timestamp_se659);


  // ***************************************************
  // FOR RUN 654
  // ***************************************************
  
  int counts654 = 0;
  int boCounts654;
  int timecounter = 0;
  double timeaxis654[1000000];
  

  
  double beamlineEvent654 = (Double_t) bl654-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 654 " << endl;
  // beamline epics tree readings
  for(ULong64_t j=0 ; j < beamlineEvent654 ;j++) {
    bl654 -> GetEvent(j);
    TSArray654[counts654] = timestamp_bl654;
    curArray654[counts654] = cur654*2000;
    //cout << std::fixed << TSArray654[counts654] << endl;
    timeaxis654[counts654] = timecounter;
    //cout << timeaxis654[counts654] << endl;
    if (counts654 > 1){
      if (curArray654[counts654 - 1] < 0.08 && curArray654[counts654] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl654 << endl;
	curAve654 += cur654;
	boCounts654++;
      }
      if (curArray654[counts654-1] > 0.08 && curArray654[counts654] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl654 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl654 < min654 ){
      min654 = timestamp_bl654;
    }
    // MAX TIME STAMP
    if (timestamp_bl654 > max654){
      max654 = timestamp_bl654;
    }
    timecounter = timecounter+5;
    counts654++;
    }
  cout << std::fixed << TSArray654[0] << " " << TSArray654[beamlineEvent654-1] << endl;
  int SEcounts654;
  double sourceEpicsEvents654 = (double) sourceEpics654 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents654 ; j++){
    sourceEpics654 -> GetEvent(j);
    TSArrayse654[j] = timestamp_se654; // source epics timestamp array
    tempArray654[j] = ts12654; // temperature array
    //cout << tempArray654[j] << " "<< TSArrayse
    ts12Ave654 += ts12654;
    SEcounts654++; // total counts for the source epics tree
  }


  curAve654 = curAve654 / boCounts654;
  ts12Ave654 = ts12Ave654/SEcounts654;
  NBins654 = max654 - min654;

  TH1* UCNrate_li6654 = new TH1F ("UCNrate_li6654" , "UCN_rate Histogram" , NBins654, min654, max654);
  
  int points654;
  int rate1654 = 0;
  int interval1654;
  int X3;

  ULong64_t eventTot654 = (Double_t) uinli6654 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot654 ; j++) {
    uinli6654 -> GetEvent(j);
    // cout <<std::fixed << tUnixTimePrecise654 << endl;
    if (tIsUCN654 > 0 && tUnixTime654 > 20e6){
      X3 = T1.Convert() - X1;
      UCNrate_li6654 -> Fill( tUnixTimePrecise654);
      // UCNrate_li6654 -> Fill(X3);
      if (tUnixTimePrecise654 > 1511038876 + 20 && tUnixTimePrecise654 < 1511039474 - 20){
	rate1654++;
 
      }
    }
    points654++;
    
  }

  interval1654 = -(1511038876 + 20) + (1511039474 - 20);

  cout << rate1654/interval1654 << endl;
  cout << "The average current for this run was " << curAve654 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave654 << endl;


  double tave1654;
  int cts1654 = 0;

  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents654 ; j++){
    sourceEpics654 -> GetEvent(j);
    if (timestamp_se654 > 1511038876  && timestamp_se654 < 1511039474 ){
      tave1654 += ts12654;
      cts1654++;
    }
  }

  tave1654 = tave1654/ cts1654;
  cout << tave1654 <<  endl;


  
  cout << "*******************************************" << endl;

  
  // **************************************************
  // FOR RUN 659
  // **************************************************

  int counts659 = 0;
  int boCounts659;
  

  double beamlineEvent659 = (Double_t) bl659-> GetEntries();
  cout << "*******************************************" << endl;
  cout << "For midas run 659 " << endl;
  for(ULong64_t j=0 ; j < beamlineEvent659 ;j++) {
    bl659 -> GetEvent(j);
    TSArray659[counts659] = timestamp_bl659;
    curArray659[counts659] = cur659*2000;

    if (counts659 > 1){
      if (curArray659[counts659 - 1] < 0.08 && curArray659[counts659] > 0.08){

	cout << "Beam goes on" << " "<<  timestamp_bl659 << endl;
	curAve659 += cur659;
	boCounts659++;
      }
      if (curArray659[counts659-1] > 0.08 && curArray659[counts659] < 0.08){
	cout << "beam goes off" << " "<< timestamp_bl659 << endl;
      }
    }
    // MIN TIME STAMP
    if (timestamp_bl659 < min659 ){
      min659 = timestamp_bl659;
    }
    // MAX TIME STAMP
    if (timestamp_bl659 > max659){
      max659 = timestamp_bl659;
    }

    counts659++;
    }

  int SEcounts659;
  double sourceEpicsEvents659 = (double) sourceEpics659 -> GetEntries();
  for (ULong64_t j = 0 ; j < sourceEpicsEvents659 ; j++){
    sourceEpics659 -> GetEvent(j);
    TSArrayse659[j] = timestamp_se659;
    tempArray659[j] = ts12659;
    ts12Ave659 += ts12659;
    SEcounts659++;
  }

  
  curAve659 = curAve659 / boCounts659;
  ts12Ave659 = ts12Ave659/SEcounts659;
  NBins659 = max659 - min659;

  TH1* UCNrate_li6659 = new TH1F ("UCNrate_li6659" , "UCN_rate Histogram" , NBins659, min659, max659);
  
  int points659;
  int rate1659 = 0;
  int interval1659;

  ULong64_t eventTot659 = (Double_t) uinli6659 -> GetEntries();
  for (ULong64_t j = 0 ; j < eventTot659 ; j++) {
    uinli6659 -> GetEvent(j);
      
    if (tIsUCN659 > 0 && tUnixTime659 > 20e6){
      UCNrate_li6659 -> Fill(tUnixTimePrecise659);
      if (tUnixTimePrecise659 > 1511042729 + 20 && tUnixTimePrecise659 < 1511043339 - 20){
	rate1659++;
      }
    }
    points659++;
    
  }

  interval1659 = - (1511042729 + 20) + (1511043339 - 20);
  cout << rate1659/interval1659 <<  endl;
  cout << "The average current for this run was " << curAve659 << endl;
  cout << "The average isopure temperature for this run was " << ts12Ave659 << endl;


  double tave1659;
  int cts1659 = 0;
  
  
  for (ULong64_t j = 0 ; j < sourceEpicsEvents659 ; j++){
    sourceEpics659 -> GetEvent(j);
    if (timestamp_se659 > 1511042729  && timestamp_se659 < 1511043339 ){
      tave1659 += ts12659;
      cts1659++;
    }
  }

  tave1659 = tave1659/ cts1659;
  
  cout << tave1659  << endl;

  cout << "*******************************************" << endl;

  // **********************************************************************
  // GRAPHS
  //************************************************************************



  
  // *****
  // 654
  // *****
  
  TCanvas *c1654 = new TCanvas ("c1654", "c1654", 1200, 900);
  UCNrate_li6654 -> GetYaxis() -> SetTitle("Counts/s");
  UCNrate_li6654 -> GetXaxis() -> SetTitle("Unixtime (s)");
  UCNrate_li6654 -> Draw();
  f1 -> Draw("same");

  TCanvas *c2654 = new TCanvas ("c2654" , "c2654", 1200, 900);

  TGraphErrors *gr_b654 = new TGraphErrors (counts654 , TSArray654 , curArray654, 0 , 0);
  //TGraphErrors *gr_b654 = new TGraphErrors (counts654 , timeaxis654 , curArray654, 0 , 0);

  gr_b654 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  //gr_b654 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b654 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b654 -> SetMarkerStyle(20);
  
  gr_b654 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b654 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b654 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b654 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b654 -> GetXaxis() -> SetTimeDisplay(1);
  gr_b654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr_b654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr_b654 -> GetXaxis() -> SetLabelOffset(.03);
  gr_b654 -> GetXaxis() -> SetLabelSize(.04);
  gr_b654 -> SetMarkerColor(1);

  

  gr_b654 -> Draw("Ap");
  UCNrate_li6654 -> Draw("same");

  

  TF1 *f654 = new TF1("f654","140", min654 ,max654 );
  TCanvas *c3654 = new TCanvas ("c3654" , "c3654" , 1200, 900);

  TGraph *gr_s654 = new TGraph (SEcounts654 , TSArrayse654, tempArray654);
  gr_s654 -> SetTitle(" Isopure Temperature vs Unix Time ");
  // gr_s654 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s654 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  //gr_s654 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s654 -> SetMarkerStyle(20);
  
  gr_s654 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s654 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s654 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s654 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s654 -> GetXaxis() -> SetTimeDisplay(1);
  gr_s654 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr_s654 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr_s654 -> GetXaxis() -> SetLabelOffset(.03);
  gr_s654 -> GetXaxis() -> SetLabelSize(.04);
  gr_s654 -> SetMarkerColor(1);

  gr_s654 -> Draw("ap");
  f2 -> Draw("same");
  //  UCNrate_li6654 -> Divide(f654);
  //UCNrate_li6654 -> Draw("same");
  break;

  
  // *************************************************
  // I want to graph the ucn rate vs temperature but
  // they have different number of points. As a result,
  // I have to find a way to make it work.

  int aveRate654 = 0;
  double aveRateArray654[10000000];
  double btempArray654[1000000];
  int counter654 = 0;
  

  for (int k = 0 ; k < SEcounts654 - 2 ; k++ ){
    //cout << " k " << k << endl;
    //cout << tempArray654[k] << " " << TSArrayse654[k] << endl;
    if (TSArrayse654[k] > 1511038876 +50  && TSArrayse654[k] < 1511039474 - 70   ){ //if the time stamp is when the beam in on
      // cout << "timestamp is within the beam on time" << endl;
      btempArray654[counter654] = tempArray654[k];
      //cout << " k and counter654 are " << k << " "<< counter654 << " " << btempArray654[counter654] << " " << tempArray654[k] << endl;
       for (ULong64_t j = 0 ; j < eventTot654 ; j++) {
      	uinli6654 -> GetEvent(j);

      	if (tUnixTime654 > TSArrayse654[k] && tUnixTime654 < TSArrayse654[k+1]  ){
	  //cout << " " <<sdt::fixed << tUnixTime654 << " " << TSArray654[k] << endl;
	  //cout << " now the beam timestamp is between the two successive epics data points" << endl;
	  if (tIsUCN654 > 0 && tUnixTime654 > 20e6){
	    aveRate654++;
          }
	  //   cout << " just added up the rate" << endl;
      	}
       }
 
       aveRateArray654[counter654] = aveRate654/ (TSArrayse654[k+1] - TSArrayse654[k] )/3; // the time difference between timestamp k and k+1 is 5 seconds. And divided by 2 muA
       //cout << "k " << k << " counter " << counter654 << " temp " << btempArray654[counter654] << " "<< tempArray654[k] <<  " rate " << aveRateArray654[counter654] << " " << std::fixed << TSArray654[k] << endl;
       aveRate654 = 0;
       counter654++;
       
    }
  }
  
  //*********************************************************
  
  TCanvas *c654ratetemp = new TCanvas ("c654ratetemp", "c654ratetemp", 1200, 900);
  
  TGraph *gr654ratetemp = new TGraph (counter654, btempArray654, aveRateArray654 );
  gr654ratetemp -> SetTitle(" UCN Rate Average vs Isopure Helium Temperature ");
  gr654ratetemp -> GetXaxis() -> SetTitle("Isopure Helium Temperature (K)");
  gr654ratetemp -> GetYaxis() -> SetTitle("UCN Rate Average (average counts/s*#muA)");
  gr654ratetemp -> SetMarkerStyle(20);
  
  gr654ratetemp -> GetXaxis() -> SetTitleSize(0.05);
  gr654ratetemp -> GetXaxis() -> SetTitleOffset(1.0);
  gr654ratetemp -> GetYaxis() -> SetTitleSize(0.05); 
  gr654ratetemp -> GetYaxis() -> SetTitleOffset(0.9);
  
  gr654ratetemp -> SetMarkerColor(1);

  gr654ratetemp -> Draw("ap");
  
 
  // ******
  //  659
  // *****
  TCanvas *c1659 = new TCanvas ("c1659", "c1659", 1200, 900);
  UCNrate_li6659 -> Draw();



  TCanvas *c2659 = new TCanvas ("c2659" , "c2659", 1200, 900);

  TGraphErrors *gr_b659 = new TGraphErrors (counts659 , TSArray659 , curArray659, 0 , 0);

  gr_b659 -> SetTitle(" Predicted Beam Current vs Unix Time ");
  gr_b659 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_b659 -> GetYaxis() -> SetTitle("Predicted Beam Current (#muA)* 2000");
  gr_b659 -> SetMarkerStyle(20);
  
  gr_b659 -> GetXaxis() -> SetTitleSize(0.05);
  gr_b659 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b659 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b659 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_b659 -> GetXaxis() -> SetTimeDisplay(1);
  gr_b659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr_b659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr_b659 -> GetXaxis() -> SetLabelOffset(.03);
  gr_b659 -> GetXaxis() -> SetLabelSize(.04);
  gr_b659 -> SetMarkerColor(1);

  

  gr_b659 -> Draw("Ap");
  UCNrate_li6659 -> Draw("same");

  TF1 *f659 = new TF1("f659","140", min659 ,max659 );
  TCanvas *c3659 = new TCanvas ("c3659" , "c3659" , 1200, 900);

  TGraph *gr_s659 = new TGraph (SEcounts659 , TSArrayse659, tempArray659);
  gr_s659 -> SetTitle(" Isopure Temperature vs Unix Time ");
  gr_s659 -> GetXaxis() -> SetTitle("Unix Time" );
  gr_s659 -> GetYaxis() -> SetTitle("Isopure Temperature (K)");
  gr_s659 -> GetXaxis() -> SetTimeDisplay(1);
  gr_s659 -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  gr_s659 -> GetXaxis() -> SetTimeOffset(0, "pdt");
  gr_s659 -> GetXaxis() -> SetLabelOffset(.03);
  gr_s659 -> GetXaxis() -> SetLabelSize(.04);
  //gr_s659 -> GetYaxis() -> SetRangeUser (0, 200);
  gr_s659 -> SetMarkerStyle(20);
  
  gr_s659 -> GetXaxis() -> SetTitleSize(0.05);
  gr_s659 -> GetXaxis() -> SetTitleOffset(1.0);
  gr_s659 -> GetYaxis() -> SetTitleSize(0.05); 
  gr_s659 -> GetYaxis() -> SetTitleOffset(0.9);
  gr_s659 -> SetMarkerColor(1);

  gr_s659 -> Draw("ap");
  //  UCNrate_li6659 -> Divide(f659);
  //UCNrate_li6659 -> Draw("same");


  // *************************************************
  // I want to graph the ucn rate vs temperature but
  // they have different number of points. As a result,
  // I have to find a way to make it work.

  int aveRate659 = 0;
  double aveRateArray659[1000000];
  double btempArray659[1000000];
  int counter659 = 0;
  

  for (int k = 0 ; k < SEcounts659 - 2 ; k++ ){
    //cout << " k " << k << endl;
    // cout << tempArray659[k] << " " << TSArrayse659[k] << endl;
    if (TSArrayse659[k] > 1511042729 +50  && TSArrayse659[k] < 1511043339 - 70   ){ //if the time stamp is when the beam in on
      // cout << "timestamp is within the beam on time" << endl;
      btempArray659[counter659] = tempArray659[k];
      //cout << " k and counter659 are " << k << " "<< counter659 << " " << btempArray659[counter659] << " " << tempArray659[k] << endl;
       for (ULong64_t j = 0 ; j < eventTot659 ; j++) {
      	uinli6659 -> GetEvent(j);

      	if (tUnixTime659 > TSArrayse659[k] && tUnixTime659 < TSArrayse659[k+1]  ){
	  //cout << " " <<sdt::fixed << tUnixTime659 << " " << TSArray659[k] << endl;
	  //cout << " now the beam timestamp is between the two successive epics data points" << endl;
	  if (tIsUCN659 > 0 && tUnixTime659 > 20e6){
	    aveRate659++;
          }
	  //   cout << " just added up the rate" << endl;
      	}
       }
 
       aveRateArray659[counter659] = aveRate659/ (TSArrayse659[k+1] - TSArrayse659[k] )/2; // the time difference between timestamp k and k+1 is 5 seconds. And divided by 2 muA
       //cout << "k " << k << " counter " << counter659 << " temp " << btempArray659[counter659] << " "<< tempArray659[k] <<  " rate " << aveRateArray659[counter659] << " " << std::fixed << TSArray659[k] << endl;
       aveRate659 = 0;
       counter659++;       
    }
  }
  
  
  //*********************************************************
  
  TCanvas *c659ratetemp = new TCanvas ("c659ratetemp", "c659ratetemp", 1200, 900);

  TGraph *gr659ratetemp = new TGraph (counter659, btempArray659, aveRateArray659 );
  gr659ratetemp -> SetTitle(" UCN Rate Average vs Isopure Helium Temperature ");
  gr659ratetemp -> GetXaxis() -> SetTitle("Isopure Helium Temperature (K)");
  gr659ratetemp -> GetYaxis() -> SetTitle("UCN Rate Average (average counts/s*#muA)");
  gr659ratetemp -> SetMarkerStyle(20);
  
  gr659ratetemp -> GetXaxis() -> SetTitleSize(0.05);
  gr659ratetemp -> GetXaxis() -> SetTitleOffset(1.0);
  gr659ratetemp -> GetYaxis() -> SetTitleSize(0.05); 
  gr659ratetemp -> GetYaxis() -> SetTitleOffset(0.9);
  //  gr659ratetemp -> GetXaxis() -> SetTimeDisplay(1);
  //  gr659ratetemp -> GetXaxis() -> SetTimeFormat(" #splitline{%H:%M}{%b\ %d}");
  //  gr659ratetemp -> GetXaxis() -> SetTimeOffset(0, "pdt");
  // gr659ratetemp -> GetXaxis() -> SetLabelOffset(.03);
  //  gr659ratetemp -> GetXaxis() -> SetLabelSize(.04);
  // gr659ratetemp -> SetMarkerColor(1);

  gr659ratetemp -> Draw("ap");

  // ********************************************
  // THE OVERAL RESULT

  /*
  double rateAll[3] = {2139, 2152, 2152};
  double tempAll[3] = {0.94, 0.94, 0.94};
  double rateOnline[3] = {2100, 2100, 2100};
  double tempOnline[3] = {0.95, 0.95, 0.95};

  TCanvas *c1 = new TCanvas ("c1", "c1", 1200, 900);
  TGraph *grAll = new TGraph (3, tempAll, rateAll);
  grAll -> SetTitle(" UCN rate vs Average Isopure Helium Temperature");
  grAll -> GetXaxis() -> SetTitle("Average Isopure Helium Temperature (K)" );
  grAll -> GetYaxis() -> SetTitle("UCN rate (counts/s)");
  grAll -> GetYaxis() -> SetRangeUser (2100, 2160);
  grAll -> SetMarkerStyle(20);
  
  grAll -> GetXaxis() -> SetTitleSize(0.05);
  grAll -> GetXaxis() -> SetTitleOffset(1.0);
  grAll -> GetYaxis() -> SetTitleSize(0.05); 
  grAll -> GetYaxis() -> SetTitleOffset(0.9);
  grAll -> SetMarkerColor(1);

  TGraph *grOnline = new TGraph (3, tempOnline, rateOnline);
  grOnline -> SetMarkerColor(8);
  grOnline -> SetMarkerStyle(3);

  grAll -> Draw("Ap");
  grOnline -> Draw("p");

  */
}
