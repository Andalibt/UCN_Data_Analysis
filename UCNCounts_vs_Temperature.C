// ***********************************************
// This script is to analyze the two experiments
// TCN17003A and TCN17003B.
// Taraneh Andalib, June 11 2018
// ***********************************************

#define max 100

void UCNCounts_vs_Temperature(){

  ifstream myfile1;
  ifstream myfile2;

  myfile1.open("./2ndpass/TCN17003A_Data.csv");
  myfile2.open("./2ndpass/TCN17003B_Data.csv");


  double HistIntegral1[max];
  double HistIntegralErr1[max];
  double UCNCounts1[max];
  double UCNCountsErr1[max];
  double avecur1[max];
  double avecurErr1[max];
  double avets11VO1[max];
  double avets12VO1[max];
  double avets14VO1[max];
  double avets16VO1[max];
  double ts11VOErr1[max];
  double ts12VOErr1[max];
  double ts14VOErr1[max];
  double ts16VOErr1[max];
  double run1[max];



  double HistIntegral2[max];
  double HistIntegralErr2[max];
  double UCNCounts2[max];
  double UCNCountsErr2[max];
  double avecur2[max];
  double avecurErr2[max];
  double avets11VO2[max];
  double avets12VO2[max];
  double avets14VO2[max];
  double avets16VO2[max];
  double ts11VOErr2[max];
  double ts12VOErr2[max];
  double ts14VOErr2[max];
  double ts16VOErr2[max];
  double run2[max];

  
  int i1 = 0;
  int i2 = 0;



  double HistIntAll[max];
  double HistErrAll[max];
  double CountsAll[max];
  double CountsErrAll[max];
  double ts12All[max];
  double ts12ErrAll[max];
  int k = 0;


  
  while (myfile1 >> HistIntegral1[i1] >> HistIntegralErr1[i1] >> UCNCounts1[i1] >> UCNCountsErr1[i1] >> avecur1[i1] >> avecurErr1[i1] >> avets11VO1[i1] >> ts11VOErr1[i1] >> avets12VO1[i1] >> ts12VOErr1[i1] >> avets14VO1[i1] >> ts14VOErr1[i1] >> avets16VO1[i1] >> ts16VOErr1[i1] >> run1[i1]){
    HistIntAll[k] = HistIntegral1[i1];
    HistErrAll[k] = HistIntegralErr1[i1];
    CountsAll[k] = UCNCounts1[i1];
    CountsErrAll[k] = UCNCountsErr1[i1];
    ts12All[k] = avets12VO1[i1];
    ts12ErrAll[k] = ts12VOErr1[i1];
    i1++;
    k = i1;
  }
    


  while (myfile2 >> HistIntegral2[i2] >> HistIntegralErr2[i2] >> UCNCounts2[i2] >> UCNCountsErr2[i2] >> avets12VO2[i2] >> ts12VOErr2[i2] >> avets11VO2[i2] >> ts11VOErr2[i2] >> avets14VO2[i2] >> ts14VOErr2[i2] >> avets16VO2[i2] >> ts16VOErr2[i2] >> run2[i2]){
    cout << i2 << " " << HistIntegral2[i2] << " " << HistIntegralErr2[i2] << " " <<  avets12VO2[i2] << endl;
    HistIntAll[k] = HistIntegral2[i2];
    HistErrAll[k] = HistIntegralErr2[i2];
    CountsAll[k] = UCNCounts2[i2];
    CountsErrAll[k] = UCNCountsErr2[i2];
    ts12All[k] = avets12VO2[i2];
    ts12ErrAll[k] = ts12VOErr2[i2];
    i2++;
    k = k+1;
  }





  

  TF1 *f1 = new TF1("f1" , "[0]/(1-exp(-x/[1]))" , 0.8 , 2.);
  f1 -> SetParameter(0, 50000);
  f1 -> SetParameter (1, 20);
  

  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200, 900);

  //TS12
  TGraphErrors *gr1WB_ts12 = new TGraphErrors (k, ts12All, HistIntAll, ts12ErrAll , HistErrAll );
  gr1WB_ts12 -> GetYaxis() -> SetRangeUser (0, 50000);
  gr1WB_ts12 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr1WB_ts12 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1WB_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1WB_ts12 -> SetMarkerStyle(20);
  gr1WB_ts12 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WB_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WB_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WB_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WB_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WB_ts12 -> SetMarkerColor(1);


  TGraphErrors *gr1WOB_ts12 = new TGraphErrors (k, ts12All , CountsAll , ts12ErrAll, CountsErrAll);
  gr1WOB_ts12 -> SetMarkerStyle(25);
  gr1WOB_ts12 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WOB_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WOB_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WOB_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WOB_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WOB_ts12 -> SetMarkerColor(1);

  
  TGraphErrors *gr2WB_ts12 = new TGraphErrors (i2, avets12VO2, HistIntegral2, ts12VOErr2 , HistIntegralErr2 );
  gr2WB_ts12 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr2WB_ts12 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr2WB_ts12 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2WB_ts12 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2WB_ts12 -> SetMarkerStyle(20);
  gr2WB_ts12 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WB_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WB_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WB_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WB_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WB_ts12 -> SetMarkerColor(1);


  TGraphErrors *gr2WOB_ts12 = new TGraphErrors (i2, avets12VO2 , UCNCounts2 , ts12VOErr2, UCNCountsErr2);
  gr2WOB_ts12 -> SetMarkerStyle(25);
  gr2WOB_ts12 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WOB_ts12 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WOB_ts12 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WOB_ts12 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WOB_ts12 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WOB_ts12 -> SetMarkerColor(1);


  //TS11
  TGraphErrors *gr1WB_ts11 = new TGraphErrors (i1, avets11VO1, HistIntegral1, ts11VOErr1 , HistIntegralErr1 );
  gr1WB_ts11 -> GetYaxis() -> SetRangeUser (0, 50000);
  gr1WB_ts11 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr1WB_ts11 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1WB_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1WB_ts11 -> SetMarkerStyle(20);
  gr1WB_ts11 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WB_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WB_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WB_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WB_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WB_ts11 -> SetMarkerColor(2);


  TGraphErrors *gr1WOB_ts11 = new TGraphErrors (i1, avets11VO1 , UCNCounts1 , ts11VOErr1, UCNCountsErr1);
  gr1WOB_ts11 -> SetMarkerStyle(25);
  gr1WOB_ts11 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WOB_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WOB_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WOB_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WOB_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WOB_ts11 -> SetMarkerColor(2);

  
  TGraphErrors *gr2WB_ts11 = new TGraphErrors (i2, avets11VO2, HistIntegral2, ts11VOErr2 , HistIntegralErr2 );
  gr2WB_ts11 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr2WB_ts11 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr2WB_ts11 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2WB_ts11 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2WB_ts11 -> SetMarkerStyle(20);
  gr2WB_ts11 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WB_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WB_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WB_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WB_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WB_ts11 -> SetMarkerColor(2);


  TGraphErrors *gr2WOB_ts11 = new TGraphErrors (i2, avets11VO2 , UCNCounts2 , ts11VOErr2, UCNCountsErr2);
  gr2WOB_ts11 -> SetMarkerStyle(25);
  gr2WOB_ts11 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WOB_ts11 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WOB_ts11 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WOB_ts11 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WOB_ts11 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WOB_ts11 -> SetMarkerColor(2);


  //TS14
  TGraphErrors *gr1WB_ts14 = new TGraphErrors (i1, avets14VO1, HistIntegral1, ts14VOErr1 , HistIntegralErr1 );
  gr1WB_ts14 -> GetYaxis() -> SetRangeUser (0, 50000);
  gr1WB_ts14 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr1WB_ts14 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1WB_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1WB_ts14 -> SetMarkerStyle(20);
  gr1WB_ts14 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WB_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WB_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WB_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WB_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WB_ts14 -> SetMarkerColor(3);


  TGraphErrors *gr1WOB_ts14 = new TGraphErrors (i1, avets14VO1 , UCNCounts1 , ts14VOErr1, UCNCountsErr1);
  gr1WOB_ts14 -> SetMarkerStyle(25);
  gr1WOB_ts14 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WOB_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WOB_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WOB_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WOB_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WOB_ts14 -> SetMarkerColor(3);

  
  TGraphErrors *gr2WB_ts14 = new TGraphErrors (i2, avets14VO2, HistIntegral2, ts14VOErr2 , HistIntegralErr2 );
  gr2WB_ts14 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr2WB_ts14 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr2WB_ts14 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2WB_ts14 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2WB_ts14 -> SetMarkerStyle(20);
  gr2WB_ts14 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WB_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WB_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WB_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WB_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WB_ts14 -> SetMarkerColor(3);


  TGraphErrors *gr2WOB_ts14 = new TGraphErrors (i2, avets14VO2 , UCNCounts2 , ts14VOErr2, UCNCountsErr2);
  gr2WOB_ts14 -> SetMarkerStyle(25);
  gr2WOB_ts14 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WOB_ts14 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WOB_ts14 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WOB_ts14 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WOB_ts14 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WOB_ts14 -> SetMarkerColor(3);


  //TS16
  TGraphErrors *gr1WB_ts16 = new TGraphErrors (i1, avets16VO1, HistIntegral1, ts16VOErr1 , HistIntegralErr1 );
  gr1WB_ts16 -> GetYaxis() -> SetRangeUser (0, 50000);
  gr1WB_ts16 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr1WB_ts16 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr1WB_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr1WB_ts16 -> SetMarkerStyle(20);
  gr1WB_ts16 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WB_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WB_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WB_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WB_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WB_ts16 -> SetMarkerColor(4);


  TGraphErrors *gr1WOB_ts16 = new TGraphErrors (i1, avets16VO1 , UCNCounts1 , ts16VOErr1, UCNCountsErr1);
  gr1WOB_ts16 -> SetMarkerStyle(25);
  gr1WOB_ts16 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr1WOB_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr1WOB_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr1WOB_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr1WOB_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr1WOB_ts16 -> SetMarkerColor(4);

  
  TGraphErrors *gr2WB_ts16 = new TGraphErrors (i2, avets16VO2, HistIntegral2, ts16VOErr2 , HistIntegralErr2 );
  gr2WB_ts16 -> GetYaxis() -> SetRangeUser (0, 7000);
  gr2WB_ts16 -> SetTitle( "UCN Counts vs Average Isopure Temperature");
  gr2WB_ts16 -> GetXaxis()-> SetTitle("Average Isopure Temperature (K)" );
  gr2WB_ts16 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2WB_ts16 -> SetMarkerStyle(20);
  gr2WB_ts16 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WB_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WB_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WB_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WB_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WB_ts16 -> SetMarkerColor(4);


  TGraphErrors *gr2WOB_ts16 = new TGraphErrors (i2, avets16VO2 , UCNCounts2 , ts16VOErr2, UCNCountsErr2);
  gr2WOB_ts16 -> SetMarkerStyle(25);
  gr2WOB_ts16 -> GetXaxis()-> SetLimits(0.8, 2.4);
  gr2WOB_ts16 -> GetXaxis() -> SetTitleSize(0.05);
  gr2WOB_ts16 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2WOB_ts16 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2WOB_ts16 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2WOB_ts16 -> SetMarkerColor(4);


  TLegend *leg = new TLegend (0.6, 0.7 , 0.9, 0.9);
  //leg -> AddEntry(gr1WB_ts11 , "Counts With Background, TS11" , "p");
  //leg -> AddEntry(gr1WOB_ts11 , "counts Without Background, TS11" , "p");
  leg -> AddEntry(gr1WB_ts12 , "Counts With Background, TS12" , "p");
  leg -> AddEntry(gr1WOB_ts12 , "counts Without Background, TS12" , "p");
  //leg -> AddEntry(gr1WB_ts14 , "Counts With Background, TS14" , "p");
  //leg -> AddEntry(gr1WOB_ts14 , "counts Without Background, TS14" , "p");
  //leg -> AddEntry(gr1WB_ts16, "Counts With Background, TS16" , "p");
  //leg -> AddEntry(gr1WOB_ts16 , "counts Without Background, TS16" , "p");

   gr1WB_ts12 -> Draw("Ap");
   gr1WOB_ts12 -> Draw("p");
   //gr1WB_ts12 -> Fit(f1);
   //gr2WB_ts12 -> Draw("p");
   //gr2WOB_ts12-> Draw("p");
   //gr1WB_ts11 -> Draw("p");
   //gr1WOB_ts11 -> Draw("p");
   //gr2WB_ts11 -> Draw("p");
   // gr2WOB_ts11-> Draw("p");
   //gr1WB_ts14 -> Draw("p");
   //gr1WOB_ts14 -> Draw("p");
   //gr2WB_ts14 -> Draw("p");
   // gr2WOB_ts14-> Draw("p");
   //gr1WB_ts16 -> Draw("p");
   //gr1WOB_ts16 -> Draw("p");
   //gr2WB_ts16 -> Draw("p");
   ///gr2WOB_ts16-> Draw("p");
   leg -> Draw();
   
}
