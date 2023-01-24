// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <iostream>

using namespace std;

int main() {
  string filename;
  string column;
  
  cout << "enter a filename" << endl;
  cin >> filename;


  cout << "enter a column name" << endl;
  cin >> column;

  vector<double> v = extract_column(filename, column);

  cout << "reading column " << column << " from " << filename << endl;
  cout << "Summary (value: frequency)" << endl;

  vector<pair<double, int> > summary = summarize(v);
  for(auto i: summary){
    cout << i.first << ": " << i.second << endl;
  }



  cout << endl;
  cout << "count = " << count(v) << endl;
  cout << "sum = " << sum(v) << endl;
  cout << "mean = " << mean(v) << endl;
  cout << "stdev = " << stdev(v) << endl;
  cout << "median = " << median(v) << endl;
  cout << "mode = " << mode(v) << endl;
  cout << "min = " << min(v) << endl;
  cout << "max = " << max(v) << endl;

  vector<double> p = {0, .25, .5, .75, 1.0};


  cout << "  0th percentile = " << percentile(v, p[0]) << endl;
  cout << " 25th percentile = " << percentile(v, p[1]) << endl;
  cout << " 50th percentile = " << percentile(v, p[2]) << endl;
  cout << " 75th percentile = " << percentile(v, p[3]) << endl;
  cout << "100th percentile = " << percentile(v, p[4]) << endl;




}