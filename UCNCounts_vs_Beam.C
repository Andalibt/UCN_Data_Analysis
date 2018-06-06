// *******************************************************
// This analysis script analyzed the data from the two TCN
// experiments 17007 and 17001 which are the UCN counts vs
// different beam currents (and in case of 17007 at diffe-
// rent irradiation times.
// Taraneh June 06, 2018
// ******************************************************

#define max 200



void UCNCounts_vs_Beam(){

  ifstream fin1;
  fin1.open("./2ndpass/TCN17001_Data.csv");
  ifstream fin2;
  fin2.open("./2ndpass/TCN17007_Data.csv");
  
  //TFile *fin1 = new TFile ("./2ndpass/TCN17001_Data.csv" , "READ" );
  //TFile *fin2 = new TFile ("./2ndpass/TCN17007_Data.csv" , "READ" );
  

  double countsWB1[max]; // counts with background for file 1
  double countsWBErr1[max]; // counts with background error for file 1
  double countsWOB1[max]; // counts without background for file 1
  double countsWOBErr1[max]; // counts without background error for file 1


  double countsWB2[max]; // counts with background for file 2
  double countsWBErr2[max]; // counts with background error for file 2
  double countsWOB2[max]; // counts without background for file 2
  double countsWOBErr2[max]; // counts without background error for file 2

  double avecur1[max]; // average predicted current for file 1
  double avecurErr1[max]; // average predicted current error for file 1

  double avecur2[max]; // average predicted current for file 2
  double avecurErr2[max]; // average predicted current error for file 2

  double avets11Irrad1[max];
  double avets12Irrad1[max];
  double avets14Irrad1[max];
  double avets16Irrad1[max];

  double avets11IrradErr1[max];
  double avets12IrradErr1[max];
  double avets14IrradErr1[max];
  double avets16IrradErr1[max];

  double avets11VO1[max];
  double avets12VO1[max];
  double avets14VO1[max];
  double avets16VO1[max];

  double avets11VOErr1[max];
  double avets12VOErr1[max];
  double avets14VOErr1[max];
  double avets16VOErr1[max];

  double avets11VO2[max];
  double avets12VO2[max];
  double avets14VO2[max];
  double avets16VO2[max];

  double avets11VOErr2[max];
  double avets12VOErr2[max];
  double avets14VOErr2[max];
  double avets16VOErr2[max];


  int i1;
  int i2;

  while (fin1 >> countsWB1[i1] >> countsWBErr1[i1] >> countsWOB1[i1] >> countsWOBErr1[i1] >> avecur1[i1] >> avecurErr1[i1] >> avets11Irrad1[i1] >> avets11IrradErr1[i1] >> avets12Irrad1[i1] >> avets12IrradErr1[i1] >> avets14Irrad1[i1] >> avets14IrradErr1[i1] >> avets16Irrad1[i1] >> avets16IrradErr1[i1] >> avets11VO1[i1] >> avets11VOErr1[i1] >> avets12VO1[i1] >> avets12VOErr1[i1] >> avets14VO1[i1] >> avets14VOErr1[i1] >> avets16VO1[i1] >>  avets16VOErr1[i1])
    i1++;

  while (fin2 >> countsWB2[i2] >> countsWBErr2[i2] >> countsWOB2[i2] >> countsWOBErr2[i2] >> avecur2[i2] >> avecurErr2[i2] >> avets11VO2[i2] >> avets11VOErr2[i2] >> avets12VO2[i2] >> avets12VOErr2[i2] >> avets14VO2[i2] >> avets14VOErr2[i2] >> avets16VO2[i2] >> avets16VOErr2[i2] )
    i2++;
  
  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200, 900);
  //c1 -> SetLogy();
  TGraphErrors *gr1 = new TGraphErrors(i1, avecur1 , countsWB1 , avecurErr1 , countsWBErr1);

  gr1 -> GetYaxis() -> SetRangeUser (1, 400000);
  gr1 -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr1 -> GetXaxis()-> SetTitle("Average Predicted Current (#muA)" );
  gr1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1 -> SetMarkerStyle(20);
  gr1 -> GetXaxis()-> SetLimits(0, 12);
  gr1 -> GetXaxis() -> SetTitleSize(0.05);
  gr1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1 -> SetMarkerColor(1);

  TGraphErrors *gr2 = new TGraphErrors(i2, avecur2 , countsWB2 , avecurErr2 , countsWBErr2);

  gr2 -> GetYaxis() -> SetRangeUser (1, 400000);
  gr2 -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr2 -> GetXaxis()-> SetTitle("Average Predicted Current (#muA)" );
  gr2 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2 -> SetMarkerStyle(20);
  gr2 -> GetXaxis()-> SetLimits(0, 12);
  gr2 -> GetXaxis() -> SetTitleSize(0.05);
  gr2 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2 -> SetMarkerColor(1);

  

  gr1 -> Draw("Ap");
  gr2 -> Draw("p");

  /*
  TLatex l2;
  for (int i; i < i2; i++){
    cout << avecur2[i] << " " << countsWB2[i] << " " <<  avets12VO2[i] << endl;
    l2.DrawLatex(avecur2[i] , countsWB2[i]+10. , Form("%4.2f K " , avets12VO2[i]));
    l2.SetTextSize(0.03);
    //l2.SetTextFont(42);
    //l2.SetTextAlign(21);
    l2.Paint();
  }


  
  TLatex l1;
  for (int i; i < i1; i++){
    //cout << avecur1[i] << " " << countsWB1[i] << " " <<  avets12VO1[i] << endl;
    l1.DrawLatex(avecur1[i] , countsWB1[i]+100. , Form("%4.2f K" , avets12VO1[i]));
    l1.SetTextSize(0.03);
    l1.SetTextFont(42);
    l1.SetTextAlign(21);
    l1.Paint();
  }

  */








}
