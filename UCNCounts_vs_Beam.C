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

  double maxts12VO1[max];
  double mints12VO1[max];

  double maxts12VO2[max];
  double mints12VO2[max];

  int midasrun2[max];
  int i1;
  int i2;

  while (fin1 >> countsWB1[i1] >> countsWBErr1[i1] >> countsWOB1[i1] >> countsWOBErr1[i1] >> avecur1[i1] >> avecurErr1[i1] >> avets11Irrad1[i1] >> avets11IrradErr1[i1] >> avets12Irrad1[i1] >> avets12IrradErr1[i1] >> avets14Irrad1[i1] >> avets14IrradErr1[i1] >> avets16Irrad1[i1] >> avets16IrradErr1[i1] >> avets11VO1[i1] >> avets11VOErr1[i1] >> avets12VO1[i1] >> avets12VOErr1[i1] >> avets14VO1[i1] >> avets14VOErr1[i1] >> avets16VO1[i1] >>  avets16VOErr1[i1] >> maxts12VO1[i1] >> mints12VO1[i1])
    i1++;

  while (fin2 >> countsWB2[i2] >> countsWBErr2[i2] >> countsWOB2[i2] >> countsWOBErr2[i2] >> avecur2[i2] >> avecurErr2[i2] >> avets11VO2[i2] >> avets11VOErr2[i2] >> avets12VO2[i2] >> avets12VOErr2[i2] >> avets14VO2[i2] >> avets14VOErr2[i2] >> avets16VO2[i2] >> avets16VOErr2[i2] >> maxts12VO2[i2] >> mints12VO2[i2]>>midasrun2[i2])
    i2++;


  TF1 *f1 = new TF1 ("f1" , "[0]*x" , 0 , 2);
  f1 -> SetParameter(0,100000);
  f1 -> SetParName(0, "slope");

  TF1 *f2 = new TF1 ("f2" , "[0]*x" , 2, 10);
  f2 -> SetParameter(0, 30000);

  gStyle -> SetOptFit (0000);
  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200, 900);
  //c1 -> SetLogy();
  TGraphErrors *gr1 = new TGraphErrors(i1, avecur1 , countsWOB1 , avecurErr1 , countsWOBErr1);

  gr1 -> GetYaxis() -> SetRangeUser (1, 400000);
  gr1 -> SetTitle( "UCN Counts vs Average Predicted Beam Current");
  gr1 -> GetXaxis()-> SetTitle("Average Predicted Current (#muA)" );
  gr1 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1 -> SetMarkerStyle(20);
  gr1 -> GetXaxis()-> SetLimits(0, 17);
  gr1 -> GetXaxis() -> SetTitleSize(0.07);
  gr1 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1 -> GetYaxis() -> SetTitleSize(0.07); 
  gr1 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1 -> GetXaxis() -> SetLabelSize(0.07);
  gr1 -> GetYaxis() -> SetLabelSize(0.07);
  gr1 -> SetMarkerColor(1);
  f1 -> SetLineColor(8);

  TGraphErrors *gr2 = new TGraphErrors(i2, avecur2 , countsWOB2 , avecurErr2 , countsWOBErr2);

  gr2 -> GetYaxis() -> SetRangeUser (1, 500000);
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
  //gr1 -> Fit("f1");
  f1 -> SetLineColor(2);
  gr2 -> Draw("p");
  // gr2 -> Fit("f2");

  cout << "i2 is " << i2 << endl;
  


  double avets12_15 = 0;
  double avets12_3 = 0;
  double avets12_5 = 0;
  double avets12_7 = 0;
  double avets12_10 = 0;

  double maxts12_15 = 0;
  double maxts12_3 = 0;
  double maxts12_5 = 0;
  double maxts12_7 = 0;
  double maxts12_10 = 0;

  double mints12_15 = 100;
  double mints12_3 = 100;
  double mints12_5 = 100;
  double mints12_7 = 100;
  double mints12_10 = 100;

  int counter15 = 0;
  int counter3 = 0;
  int counter5 = 0;
  int counter7 = 0;
  int counter10 = 0;

  
  
  for (int i = 0; i < i2; i++){
    cout << avecur2[i] << " " << countsWOB2[i] << " " <<  avets12VO2[i] << " " << midasrun2[i]<< endl;

    // for 1.5 muA
    if (avecur2[i] > 1.4 && avecur2[i] < 1.6){
      avets12_15+= avets12VO2[i];
      counter15++;
      if (maxts12_15 < maxts12VO2[i])
	maxts12_15 = maxts12VO2[i];
      
      if (mints12_15 > mints12VO2[i])
	mints12_15 = mints12VO2[i];
    }

    // for 3 muA
    if (avecur2[i] > 2.9 && avecur2[i] < 3.1){
      avets12_3+= avets12VO2[i];
      counter3++;
      if (maxts12_3 < maxts12VO2[i])
	maxts12_3 = maxts12VO2[i];
      
      if (mints12_3 > mints12VO2[i])
	mints12_3 = mints12VO2[i];
    }

    // for 5 muA
    if (avecur2[i] > 4.9  && avecur2[i] < 5.1){
      avets12_5+= avets12VO2[i];
      counter5++;
      if (maxts12_5 < maxts12VO2[i])
	maxts12_5 = maxts12VO2[i];
      
      if (mints12_5 > mints12VO2[i])
	mints12_5 = mints12VO2[i];
    }

    //for 7 muA
    if (avecur2[i] > 6.9  && avecur2[i] < 7.2){
      avets12_7+= avets12VO2[i];
      counter7++;
      if (maxts12_7 < maxts12VO2[i])
	maxts12_7 = maxts12VO2[i];
      
      if (mints12_7 > mints12VO2[i])
	mints12_7 = mints12VO2[i];
    }

    // for 10 muA
    if (avecur2[i] > 9.9  && avecur2[i] < 10.1){
      avets12_10+= avets12VO2[i];
      counter10++;
      if (maxts12_10 < maxts12VO2[i])
	maxts12_10 = maxts12VO2[i];
      
      if (mints12_10 > mints12VO2[i])
	mints12_10 = mints12VO2[i];
    }

  }

  double avets12_005 = 0;
  double avets12_02 = 0;
  double avets12_05 = 0;
  double avets12_07 = 0;
  double avets12_1 = 0;

  double maxts12_005 = 0;
  double maxts12_02 = 0;
  double maxts12_05 = 0;
  double maxts12_07 = 0;
  double maxts12_1 = 0;

  double mints12_005 = 100;
  double mints12_02 = 100;
  double mints12_05 = 100;
  double mints12_07 = 100;
  double mints12_1 = 100;

  int counter005 =  0 ;
  int counter02 = 0;
  int counter05 = 0;
  int counter07 = 0;
  int counter1 = 0;
    
  for (int i = 0; i < i1; i++){
    cout << avecur1[i] << " " << countsWOB1[i] << " " <<  avets12VO1[i] << endl;

    //for 0.05 muA
    if (avecur1[i] > 0.04 && avecur1[i] < 0.06){
      avets12_005+= avets12VO1[i];
      counter005++;
      if (maxts12_005 < maxts12VO1[i])
	maxts12_005 = maxts12VO1[i];
    
    if (mints12_005 > mints12VO1[i])
	mints12_005 = mints12VO1[i];
    }
    
    //for 0.2 muA
    if (avecur1[i] > 0.1 && avecur1[i] < 0.3){
      avets12_02+= avets12VO1[i];
      counter02++;
      if (maxts12_02 < maxts12VO1[i])
	maxts12_02 = maxts12VO1[i];
    
      if (mints12_02 > mints12VO1[i])
	mints12_02 = mints12VO1[i];
    }
    
    //for 0.5 muA
    if (avecur1[i] > 0.4 && avecur1[i] < 0.6){
      avets12_05+= avets12VO1[i];
      counter05++;
      if (maxts12_05 < maxts12VO1[i])
	maxts12_05 = maxts12VO1[i];
      
      if (mints12_05 > mints12VO1[i])
	mints12_05 = mints12VO1[i];
    }

    // for 0.7 muA
    if (avecur1[i] > 0.6 && avecur1[i] < 0.8){
      avets12_07+= avets12VO1[i];
      counter07++;
      if (maxts12_07 < maxts12VO1[i])
	maxts12_07 = maxts12VO1[i];
      
      if (mints12_07 > mints12VO1[i])
	mints12_07 = mints12VO1[i];
    }
    
    // for 1 muA
    if (avecur1[i] > 0.9 && avecur1[i] < 1.1){
      avets12_1+=  avets12VO1[i];
      counter1++;
      if (maxts12_1 < maxts12VO1[i])
	maxts12_1 = maxts12VO1[i];
      
      if (mints12_1 > mints12VO1[i])
	mints12_1 = mints12VO1[i];
    }

    
  }

  avets12_005 = avets12_005/counter005;
  avets12_02 = avets12_02/counter02;
  avets12_05 = avets12_05/counter05;
  avets12_07 = avets12_07/counter07;
  avets12_1 = avets12_1/counter1;
  avets12_15 = avets12_15/counter15;
  avets12_3 = avets12_3/counter3;
  avets12_5 = avets12_5/counter5;
  avets12_7 = avets12_7/counter7;
  avets12_10 = avets12_10/counter10;


  double Errts12_005;
  double Errts12_02;
  double Errts12_05;
  double Errts12_07;
  double Errts12_1;
  double Errts12_15;
  double Errts12_3;
  double Errts12_5;
  double Errts12_7;
  double Errts12_10;

  Errts12_005 = (maxts12_005 - mints12_005 )/2;
  Errts12_02 = (maxts12_02 - mints12_02 )/2;
  Errts12_05 = (maxts12_05 - mints12_05 )/2;
  Errts12_07 = (maxts12_07 - mints12_07 )/2;
  Errts12_1 = (maxts12_1 - mints12_1 )/2;
  Errts12_15 = (maxts12_15 - mints12_15 )/2;
  Errts12_3 = (maxts12_3 - mints12_3 )/2;
  Errts12_5 = (maxts12_5 - mints12_5 )/2;
  Errts12_7 = (maxts12_7 - mints12_7 )/2;
  Errts12_10 = (maxts12_10 - mints12_10 )/2;
 
  
  TLatex l2;
  l2.SetTextSize(0.05);
  //l2.SetTextFont(15);

  
  // l2.DrawLatex(0.05 + 0.2, 2409.11 ,Form("%4.2f K #pm %4.2f K " , avets12_005, Errts12_005));
  //l2.DrawLatex(0.2+0.2, 11973.5 ,Form("%4.2f K #pm %4.2f K " , avets12_02, Errts12_02));
  //l2.DrawLatex(0.5 + 0.2, 23588.2 ,Form("%4.2f K #pm %4.2f K" , avets12_05, Errts12_05));
  l2.DrawLatex(0.5 + 0.5, 22000 ,Form("%4.2f K #pm %4.2f K" , 0.85 , 0.01));
  //l2.DrawLatex(0.7+0.2, 35908.1, Form("%4.2f K #pm %4.2f K" , avets12_07, Errts12_07));
  //l2.DrawLatex(1.0+0.2, 45600.5, Form("%4.2f K #pm %4.2f K" , avets12_1, Errts12_1));
  l2.DrawLatex(1.5+0.3, 60582+1000 , Form("%4.2f K #pm %4.2f K" , avets12_15, Errts12_15) );
  l2.DrawLatex(3.+0.3 , 116397+3000, Form("%4.2f K #pm %4.2f K" , avets12_3 , Errts12_3));
  l2.DrawLatex(5.-3.3 , 180000+15000 , Form("%4.2f K #pm %4.2f K" , avets12_5 , Errts12_5));
  l2.DrawLatex(7.+0.3 ,236279+3000, Form("%4.2f K #pm %4.2f K" , avets12_7 , Errts12_7));
  l2.DrawLatex(10.+0.3 ,325218+3000, Form("%4.2f K #pm %4.2f K" , avets12_10 , Errts12_10));
  //l2.Paint();

  
  cout << "average temperature for low currents: " << (avets12_005 + avets12_02 + avets12_05 + avets12_07 + avets12_1)/5 << endl;
  cout << "The error is " << sqrt(Errts12_005*Errts12_005 + Errts12_02*Errts12_02 + Errts12_05*Errts12_05 + Errts12_07*Errts12_07 + Errts12_1*Errts12_1) << endl;







}
