// **************************************************************
// IN THIS CODE I SUMMARIZE THE RESULT FOR THE BEAM CURRENT AND
// IRRADIATION TIME EXPERIMENTS. THEY ARE 17009 AND 17009A.
// **************************************************************

void storage_17009_and_17009A(){

  double storage[20] = {32.7, 31.9, 29.6, 29.4, 32.7, 31.4, 31.3, 32.7, 33.5, 28.2, 29.7 , 34.33, 27.6};
  double storageErr[20] = {0.5, 0.3, 0.3, 0.3, 0.5, 0.4, 0.4, 0.4, 0.6, 0.2, 0.2, 0.7, 0.2};
  double beamCur[20] = { 5, 5, 5, 10, 2.5, 2.5, 2.5, 2.5, 7.1, 7.1, 7.1 , 1, 10};
  double irradTime [20] = {10, 30, 60, 10, 10, 120, 30, 60, 10, 60, 30, 60, 30};

  double b5muA_10s = 32.7 , b5muA_10sErr = 0.5;
  double b5muA_30s = 31.9 , b5muA_30sErr = 0.3;
  double b5muA_60s = 29.6 , b5muA_60sErr = 0.3;
  double b10muA_10s = 29.4 , b10muA_10sErr = 0.3;
  double b2muA_10s = 32.7 , b2muA_10sErr = 0.5;
  double b2muA_120s = 31.4 , b2muA_120sErr = 0.4;
  double b2muA_30s = 31.3 , b2muA_30sErr = 0.4;
  double b2muA_60s = 32.7 , b2muA_60sErr = 0.4;
  double b7muA_10s = 33.5 , b7muA_10sErr = 0.6;
  double b7muA_60s = 28.2 , b7muA_60sErr = 0.2;
  double b7muA_30s = 29.7 , b7muA_30sErr = 0.2;
  double b1muA_60s = 34.3 , b1muA_60sErr = 0.7;
  double b10muA_30s = 27.6 , b10muA_30sErr = 0.2;


  double storage_b5muA[20] = {b5muA_10s, b5muA_30s, b5muA_60s};
  double storageErr_b5muA[20] = {b5muA_10sErr, b5muA_30sErr, b5muA_60sErr};
  double irrad_b5muA[20] = {10. , 30. , 60. };

  double storage_b2muA[20] = {b2muA_10s, b2muA_30s, b2muA_60s, b2muA_120s};
  double storageErr_b2muA[20] = {b2muA_10sErr,  b2muA_30sErr, b2muA_60sErr, b2muA_120sErr};
  double irrad_b2muA[20] = {10. , 30. , 60., 120.};

  double storage_b10muA[20] = {b10muA_10s, b10muA_30s};
  double storageErr_b10muA[20] = {b10muA_10sErr, b10muA_30sErr};
  double irrad_b10muA[20] = {10. , 30. };
  
  double storage_b7muA[20] = {b7muA_10s, b7muA_30s, b7muA_60s};
  double storageErr_b7muA[20] = {b7muA_10sErr, b7muA_30sErr, b7muA_60sErr};
  double irrad_b7muA[20] = {10. , 30. , 60. };

  double storage_b1muA[20] = {b1muA_60s};
  double storageErr_b1muA[20] = {b1muA_60sErr};
  double irrad_b1muA[20] = {60.};
  

  TCanvas *c = new TCanvas("c" , "c" , 1200, 800);
  //  c -> Divide (2,1);
  // c-> cd(1);
  
  TGraphErrors *gr_b5muA = new TGraphErrors(3, irrad_b5muA,  storage_b5muA , 0, storageErr_b5muA);
  
  gr_b5muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr_b5muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr_b5muA -> GetXaxis()-> SetTitle("Irradiation Time");
  gr_b5muA -> GetYaxis()-> SetRangeUser(25, 38);
  gr_b5muA -> GetXaxis() -> SetLimits(0,130);
  gr_b5muA -> GetXaxis() -> SetTitleSize(0.05);
  gr_b5muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b5muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b5muA -> GetYaxis() -> SetTitleOffset(0.9);

  gr_b5muA -> SetMarkerStyle(20);

  TGraphErrors *gr_b2muA = new TGraphErrors(4, irrad_b2muA,  storage_b2muA , 0, storageErr_b2muA);
  
  gr_b2muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr_b2muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr_b2muA -> GetXaxis()-> SetTitle("Irradiation Time");
  // gr -> GetYaxis()-> SetRangeUser(100, 500000);
  gr_b2muA -> GetXaxis() -> SetTitleSize(0.05);
  gr_b2muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b2muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b2muA -> GetYaxis() -> SetTitleOffset(0.9);

  gr_b2muA -> SetMarkerStyle(24);


  TGraphErrors *gr_b7muA = new TGraphErrors(4, irrad_b7muA,  storage_b7muA , 0, storageErr_b7muA);
  
  gr_b7muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr_b7muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr_b7muA -> GetXaxis()-> SetTitle("Irradiation Time");
  // gr -> GetYaxis()-> SetRangeUser(100, 500000);
  gr_b7muA -> GetXaxis() -> SetTitleSize(0.05);
  gr_b7muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b7muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b7muA -> GetYaxis() -> SetTitleOffset(0.9);

  gr_b7muA -> SetMarkerStyle(21);

  TGraphErrors *gr_b10muA = new TGraphErrors(2, irrad_b10muA,  storage_b10muA , 0, storageErr_b10muA);
  
  gr_b10muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr_b10muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr_b10muA -> GetXaxis()-> SetTitle("Irradiation Time");
  // gr -> GetYaxis()-> SetRangeUser(100, 500000);
  gr_b10muA -> GetXaxis() -> SetTitleSize(0.05);
  gr_b10muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b10muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b10muA -> GetYaxis() -> SetTitleOffset(0.9);

  gr_b10muA -> SetMarkerStyle(25);

  TGraphErrors *gr_b1muA = new TGraphErrors(2, irrad_b1muA,  storage_b1muA , 0, storageErr_b1muA);
  
  gr_b1muA -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr_b1muA -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr_b1muA -> GetXaxis()-> SetTitle("Irradiation Time");
  // gr -> GetYaxis()-> SetRangeUser(100, 500000);
  gr_b1muA -> GetXaxis() -> SetTitleSize(0.05);
  gr_b1muA -> GetXaxis() -> SetTitleOffset(1.0);
  gr_b1muA -> GetYaxis() -> SetTitleSize(0.05); 
  gr_b1muA -> GetYaxis() -> SetTitleOffset(0.9);

  gr_b1muA -> SetMarkerStyle(27);


  TLegend *leg = new TLegend(0.5,0.7, 0.9, 0.9);
  leg -> AddEntry(gr_b5muA, "5 #muA Beam Current" , "p");
  leg -> AddEntry(gr_b7muA, "7.1 #muA Beam Current" , "p");
  leg -> AddEntry(gr_b10muA, "10 #muA Beam Current" , "p");
  leg -> AddEntry(gr_b1muA, "1 #muA Beam Current" , "p");
  leg -> AddEntry(gr_b2muA, "2.5 #muA Beam Current" , "p");
  
  gr_b5muA -> Draw("Ap");
  gr_b2muA  -> Draw("p");
  gr_b7muA -> Draw("p");
  gr_b10muA -> Draw("p");
  gr_b1muA -> Draw("p");
  leg -> Draw();





  /*
  c -> cd(2);
  TGraphErrors *gr2 = new TGraphErrors(13, irradTime,  storage, 0, storageErr);

  gr2 -> SetTitle("Storage Lifetime vs Irradiation Time");
  gr2 -> GetYaxis()-> SetTitle("Storage Lifetime (s)" );
  gr2 -> GetXaxis()-> SetTitle("Irradiation Time (s)");
  //  gr2 -> GetYaxis()-> SetRangeUser(1000, 500000);
  gr2 -> GetXaxis() -> SetTitleSize(0.05);
  gr2 -> GetXaxis() -> SetTitleOffset(1.0);
  gr2 -> GetYaxis() -> SetTitleSize(0.05); 
  gr2 -> GetYaxis() -> SetTitleOffset(0.9);
  gr2 -> SetMarkerColor(2);
  gr2 -> SetMarkerStyle(20);

  gr2 -> Draw("Ap");
    
  */	





}
