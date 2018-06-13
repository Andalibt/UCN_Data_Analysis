// **************************************************
// This script is to analyze experiment TCN17004 and
// TCN17007 for the total UCN counts vs the irradia-
// tion time.
// Taraneh Andalib , June 12, 2018
// **************************************************

#define max 100

void UCNCounts_vs_irradTime(){

  ifstream fin1;
  ifstream fin2;

  fin1.open("./2ndpass/TCN17007_Data_all.csv");
  fin2.open("./2ndpass/TCN17004_Data.csv");

  int i1 = 0;
  int i2 = 0;

  double HistIntegral1[max];
  double HistIntegralErr1[max];
  double UCNCounts1[max];
  double UCNCountsErr1[max];
  double avecur1[max];
  double avecurErr1[max];
  double ts12VO1[max];
  double ts12VOErr1[max];
  double irradTime1[max];
  double run1[max];
  // need to add the irradiation time


  
  while (fin1 >> HistIntegral1[i1] >> HistIntegralErr1[i1] >> UCNCounts1[i1] >> UCNCountsErr1[i1] >> avecur1[i1] >> avecurErr1[i1] >> ts12VO1[i1] >> ts12VOErr1[i1] >> irradTime1[i1] >> run1[i1] )
    i1++;

  // Categorize for different beam currents

  // for 1.5 muA
  double HistIntegral_1muA[max];
  double HistIntegralErr_1muA[max];
  double UCNCounts_1muA[max];
  double UCNCountsErr_1muA[max];
  double avecur_1muA[max];
  double avecurErr_1muA[max];
  double ts12VO_1muA[max];
  double ts12VOErr_1muA[max];
  double irradTime_1muA[max];


  // for 3 muA
  double HistIntegral_3muA[max];
  double HistIntegralErr_3muA[max];
  double UCNCounts_3muA[max];
  double UCNCountsErr_3muA[max];
  double avecur_3muA[max];
  double avecurErr_3muA[max];
  double ts12VO_3muA[max];
  double ts12VOErr_3muA[max];
  double irradTime_3muA[max];

  // for 5 muA
  double HistIntegral_5muA[max];
  double HistIntegralErr_5muA[max];
  double UCNCounts_5muA[max];
  double UCNCountsErr_5muA[max];
  double avecur_5muA[max];
  double avecurErr_5muA[max];
  double ts12VO_5muA[max];
  double ts12VOErr_5muA[max];
  double irradTime_5muA[max];

  // for 7.1 muA
  double HistIntegral_7muA[max];
  double HistIntegralErr_7muA[max];
  double UCNCounts_7muA[max];
  double UCNCountsErr_7muA[max];
  double avecur_7muA[max];
  double avecurErr_7muA[max];
  double ts12VO_7muA[max];
  double ts12VOErr_7muA[max];
  double irradTime_7muA[max];


  // for 10 muA
  double HistIntegral_10muA[max];
  double HistIntegralErr_10muA[max];
  double UCNCounts_10muA[max];
  double UCNCountsErr_10muA[max];
  double avecur_10muA[max];
  double avecurErr_10muA[max];
  double ts12VO_10muA[max];
  double ts12VOErr_10muA[max];
  double irradTime_10muA[max];

  int counts_1muA = 0;
  int counts_3muA = 0;
  int counts_5muA = 0;
  int counts_7muA = 0;
  int counts_10muA = 0;

  
  for (int k = 0 ; k< i1 ; k++){

    // for 1.5 muA
    if ( avecur1[k] > 1.4 && avecur1[k] < 1.6){
      HistIntegral_1muA [counts_1muA] = HistIntegral1[k];
      HistIntegralErr_1muA [counts_1muA] = HistIntegralErr1[k];
      UCNCounts_1muA[counts_1muA] = UCNCounts1[k] ;
      UCNCountsErr_1muA[counts_1muA] = UCNCountsErr1[k] ;
      avecur_1muA[counts_1muA] = avecur1[k];
      avecurErr_1muA[counts_1muA] = avecurErr1[k];
      ts12VO_1muA[counts_1muA] = ts12VO1[k] ;
      ts12VOErr_1muA[counts_1muA] = ts12VOErr1[k];
      irradTime_1muA[counts_1muA] = irradTime1[k];
      counts_1muA++;
    }

    // for 3muA
    if ( avecur1[k] > 2.9 && avecur1[k] < 3.1){
      HistIntegral_3muA [counts_3muA] = HistIntegral1[k];
      HistIntegralErr_3muA [counts_3muA] = HistIntegralErr1[k];
      UCNCounts_3muA[counts_3muA] = UCNCounts1[k] ;
      UCNCountsErr_3muA[counts_3muA] = UCNCountsErr1[k] ;
      avecur_3muA[counts_3muA] = avecur1[k];
      avecurErr_3muA[counts_3muA] = avecurErr1[k];
      ts12VO_3muA[counts_3muA] = ts12VO1[k] ;
      ts12VOErr_3muA[counts_3muA] = ts12VOErr1[k];
      irradTime_3muA[counts_3muA] = irradTime1[k];
      counts_3muA++;
    }

    // for 5muA
    if ( avecur1[k] > 4.9 && avecur1[k] < 5.1){
      HistIntegral_5muA [counts_5muA] = HistIntegral1[k];
      HistIntegralErr_5muA [counts_5muA] = HistIntegralErr1[k];
      UCNCounts_5muA[counts_5muA] = UCNCounts1[k] ;
      UCNCountsErr_5muA[counts_5muA] = UCNCountsErr1[k] ;
      avecur_5muA[counts_5muA] = avecur1[k];
      avecurErr_5muA[counts_5muA] = avecurErr1[k];
      ts12VO_5muA[counts_5muA] = ts12VO1[k] ;
      ts12VOErr_5muA[counts_5muA] = ts12VOErr1[k];
      irradTime_5muA[counts_5muA] = irradTime1[k];
      counts_5muA++;
    }

    //for 7.1muA
    if ( avecur1[k] > 6.9 && avecur1[k] < 7.2){
      HistIntegral_7muA [counts_7muA] = HistIntegral1[k];
      HistIntegralErr_7muA [counts_7muA] = HistIntegralErr1[k];
      UCNCounts_7muA[counts_7muA] = UCNCounts1[k] ;
      UCNCountsErr_7muA[counts_7muA] = UCNCountsErr1[k] ;
      avecur_7muA[counts_7muA] = avecur1[k];
      avecurErr_7muA[counts_7muA] = avecurErr1[k];
      ts12VO_7muA[counts_7muA] = ts12VO1[k] ;
      ts12VOErr_7muA[counts_7muA] = ts12VOErr1[k];
      irradTime_7muA[counts_7muA] = irradTime1[k];
      counts_7muA++;
    }

    // for 10muA
    if ( avecur1[k] > 9.9 && avecur1[k] < 10.2){
      HistIntegral_10muA [counts_10muA] = HistIntegral1[k];
      HistIntegralErr_10muA [counts_10muA] = HistIntegralErr1[k];
      UCNCounts_10muA[counts_10muA] = UCNCounts1[k] ;
      UCNCountsErr_10muA[counts_10muA] = UCNCountsErr1[k] ;
      avecur_10muA[counts_10muA] = avecur1[k];
      avecurErr_10muA[counts_10muA] = avecurErr1[k];
      ts12VO_10muA[counts_10muA] = ts12VO1[k] ;
      ts12VOErr_10muA[counts_10muA] = ts12VOErr1[k];
      irradTime_10muA[counts_10muA] = irradTime1[k];
      counts_10muA++;
    }

  }




  
  
  double HistIntegral2[max];
  double HistIntegralErr2[max];
  double UCNCounts2[max];
  double UCNCountsErr2[max];
  double avecur2[max];
  double avecurErr2[max];
  double ts12VO2[max];
  double ts12VOErr2[max];
  double irradTime2[max];
  

  while (fin2 >> HistIntegral2[i2] >> HistIntegralErr2[i2] >> UCNCounts2[i2] >> UCNCountsErr2[i2] >> avecur2[i2] >> avecurErr2[i2] >> ts12VO2[i2] >> ts12VOErr2[i2] >> irradTime2[i2] )
    i2++;
													    
  TCanvas *c1 = new TCanvas ("c1" , "c1" , 1200 , 900);

  TGraphErrors *gr2 = new TGraphErrors (i2, irradTime2, UCNCounts2, 0 , UCNCountsErr2);
  gr2 -> SetTitle( "UCN Counts vs Irradiation Time");
  gr2 -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr2 -> GetYaxis()-> SetTitle("UCN Counts");
  gr2 -> GetYaxis() -> SetRangeUser (1, 350000);
  gr2 -> SetMarkerStyle(3);
  gr2 -> GetXaxis()-> SetLimits(0, 150);
  gr2 -> GetXaxis() -> SetTitleSize(0.05);
  gr2 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2 -> SetMarkerColor(1);

  TGraphErrors *gr1muA = new TGraphErrors (i2, irradTime_1muA, UCNCounts_1muA, 0 , UCNCountsErr_1muA);
  gr1muA -> SetTitle( "UCN Counts vs Irradiation Time");
  gr1muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr1muA -> GetYaxis()-> SetTitle("UCN Counts");
  gr1muA -> SetMarkerStyle(20);
  gr1muA -> GetXaxis()-> SetLimits(0, 150);
  gr1muA -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA -> SetMarkerColor(1);

  TGraphErrors *gr3muA = new TGraphErrors (i2, irradTime_3muA, UCNCounts_3muA, 0 , UCNCountsErr_3muA);
  gr3muA -> SetTitle( "UCN Counts vs Irradiation Time");
  gr3muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr3muA -> GetYaxis()-> SetTitle("UCN Counts");
  gr3muA -> SetMarkerStyle(21);
  gr3muA -> GetXaxis()-> SetLimits(0, 150);
  gr3muA -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA -> SetMarkerColor(1);


  TGraphErrors *gr5muA = new TGraphErrors (i2, irradTime_5muA, UCNCounts_5muA, 0 , UCNCountsErr_5muA);
  gr5muA -> SetTitle( "UCN Counts vs Irradiation Time");
  gr5muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr5muA -> GetYaxis()-> SetTitle("UCN Counts");
  gr5muA -> SetMarkerStyle(24);
  gr5muA -> GetXaxis()-> SetLimits(0, 150);
  gr5muA -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA -> SetMarkerColor(1);

  TGraphErrors *gr7muA = new TGraphErrors (i2, irradTime_7muA, UCNCounts_7muA, 0 , UCNCountsErr_7muA);
  gr7muA -> SetTitle( "UCN Counts vs Irradiation Time");
  gr7muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr7muA -> GetYaxis()-> SetTitle("UCN Counts");
  gr7muA -> SetMarkerStyle(25);
  gr7muA -> GetXaxis()-> SetLimits(0, 150);
  gr7muA -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA -> SetMarkerColor(1);

  TGraphErrors *gr10muA = new TGraphErrors (i2, irradTime_10muA, UCNCounts_10muA, 0 , UCNCountsErr_10muA);
  gr10muA -> SetTitle( "UCN Counts vs Irradiation Time");
  gr10muA -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr10muA -> GetYaxis()-> SetTitle("UCN Counts");
  gr10muA -> SetMarkerStyle(29);
  gr10muA -> GetXaxis()-> SetLimits(0, 150);
  gr10muA -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA -> SetMarkerColor(1);


  TLegend *leg = new TLegend (0.7, 0.7 , 0.9, 0.9);
  leg -> AddEntry(gr2 , "1 #muA Beam Current" , "p");
  leg -> AddEntry(gr1muA , "1.5 #muA Beam Current" , "p");
  leg -> AddEntry(gr3muA , "3 #muA Beam Current" , "p");
  leg -> AddEntry(gr5muA , "5 #muA Beam Current" , "p");
  leg -> AddEntry(gr7muA , "7 #muA Beam Current" , "p");
  leg -> AddEntry(gr10muA , "10 #muA Beam Current" , "p");

  gr2 -> Draw("ap");
  gr1muA -> Draw("p");
  gr3muA -> Draw("p");
  gr5muA -> Draw("p");
  gr7muA -> Draw("p");
  gr10muA -> Draw("p");
  leg -> Draw();


  // average isopure helium temperature vs irradiation time for
  // each beam current

  TCanvas *c2 = new TCanvas ("c2" , "c2" , 1200, 900);

  TGraphErrors *gr2_temp_irrad = new TGraphErrors (i2, irradTime2, ts12VO2, 0 , ts12VOErr2);
  gr2_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr2_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr2_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr2_temp_irrad -> SetMarkerStyle(20);
  gr2_temp_irrad -> GetYaxis() -> SetRangeUser (0.8, 1.4);
  gr2_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr2_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr2_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr2_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr2_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr2_temp_irrad -> SetMarkerColor(1);


  TGraphErrors *gr1muA_temp_irrad = new TGraphErrors (i2, irradTime_1muA, ts12VO_1muA, 0 , ts12VOErr_1muA);
  gr1muA_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr1muA_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr1muA_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr1muA_temp_irrad -> SetMarkerStyle(20);
  gr1muA_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr1muA_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr1muA_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr1muA_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr1muA_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr1muA_temp_irrad -> SetMarkerColor(1);
  
  TGraphErrors *gr3muA_temp_irrad = new TGraphErrors (i2, irradTime_3muA, ts12VO_3muA, 0 , ts12VOErr_3muA);
  gr3muA_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr3muA_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr3muA_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr3muA_temp_irrad -> SetMarkerStyle(21);
  gr3muA_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr3muA_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr3muA_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr3muA_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr3muA_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr3muA_temp_irrad -> SetMarkerColor(1);


  TGraphErrors *gr5muA_temp_irrad = new TGraphErrors (i2, irradTime_5muA, ts12VO_5muA, 0 , ts12VOErr_5muA);
  gr5muA_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr5muA_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr5muA_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr5muA_temp_irrad -> SetMarkerStyle(24);
  gr5muA_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr5muA_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr5muA_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr5muA_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr5muA_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr5muA_temp_irrad -> SetMarkerColor(1);

  TGraphErrors *gr7muA_temp_irrad = new TGraphErrors (i2, irradTime_7muA, ts12VO_7muA, 0 , ts12VOErr_7muA);
  gr7muA_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr7muA_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr7muA_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr7muA_temp_irrad -> SetMarkerStyle(25);
  gr7muA_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr7muA_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr7muA_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr7muA_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr7muA_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr7muA_temp_irrad -> SetMarkerColor(1);

  TGraphErrors *gr10muA_temp_irrad = new TGraphErrors (i2, irradTime_10muA, ts12VO_10muA, 0 , ts12VOErr_10muA);
  gr10muA_temp_irrad -> SetTitle( "Average Isopure Helium Temperature vs Irradiation Time");
  gr10muA_temp_irrad -> GetXaxis()-> SetTitle("Irradiation Time (s)" );
  gr10muA_temp_irrad -> GetYaxis()-> SetTitle("Average Isopure Helium Temperature (K)");
  gr10muA_temp_irrad -> SetMarkerStyle(29);
  gr10muA_temp_irrad -> GetXaxis()-> SetLimits(0, 150);
  gr10muA_temp_irrad -> GetXaxis() -> SetTitleSize(0.05);
  gr10muA_temp_irrad -> GetXaxis() -> SetTitleOffset(1.0);
  gr10muA_temp_irrad -> GetYaxis() -> SetTitleSize(0.05); 
  gr10muA_temp_irrad -> GetYaxis() -> SetTitleOffset(0.9);
  gr10muA_temp_irrad -> SetMarkerColor(1);

  gr2_temp_irrad -> Draw("ap");
  gr1muA_temp_irrad -> Draw("p");
  gr3muA_temp_irrad -> Draw("P");
  gr5muA_temp_irrad -> Draw("p");
  gr7muA_temp_irrad -> Draw("p");
  gr10muA_temp_irrad -> Draw("p");
  leg -> Draw("P");
  

}
