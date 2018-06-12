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

  fin1.open("./2ndpass/TCN17007_Data.csv");
  fin2.open("./2ndpass/TCN17004_Data.csv");

  int i1 = 0;
  int i2 = 0;

  double HistIntegral1[max];
  double HistIntegralErr1[max];
  double UCNCounts1[max];
  double UCNCountsErr1[max];
  double avecur1[max];
  double avecurErr1[max];
  double ts11VO1[max];
  double ts11VOErr1[max];
  double ts12VO1[max];
  double ts12VOErr1[max];
  double ts14VO1[max];
  double ts14VOErr1[max];
  double ts16VO1[max];
  double ts16VOErr1[max];
  double maxts12VO1[max];
  double mints12VO1[max];
  double run1[max];
  // need to add the irradiation time

  while (fin1 >> HistIntegral1[i1] >> HistIntegralErr1[i1] >> UCNCounts1[i1] >> UCNCountsErr1[i1] >> avecur1[i1] >> avecurErr1[i1] >> ts11VO1[i1] >> ts11VOErr1[i1] >> ts12VO1[i1] >> ts12VOErr1[i1] >> ts14VO1[i1] >> ts14VOErr1[i1] >> ts16VO1[i1] >> ts16VOErr1[i1] >> maxts12VO1[i1] >> mints12VO1[i1] >> run1[i1] )
    i1++;


  double HistIntegral2[max];
  double HistIntegralErr2[max];
  double UCNCounts2[max];
  double UCNCountsErr2[max];
  double avecur2[max];
  double avecurErr2[max];
  double ts12VO2[max];
  dobule ts12VOErr2[max];
  double irradTime2[max];
  











}
