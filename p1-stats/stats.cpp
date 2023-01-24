// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
  assert(!v.empty());
  sort(v);
  int frequency = 0;
  double current = v.at(0);
  vector<pair< double, int> > points;
  for(int i = 0; i < v.size(); ++i){
    double atI = v[i];
    if(atI == current){
        frequency++;
    }else {
        points.push_back({current, frequency});
        current = atI;
        frequency = 1;
    }
  }
    points.push_back({current, frequency});
    return points;

}

int count(vector<double> v) {
  return(v.size());
}

double sum(vector<double> v) {
  assert(!v.empty());
  double sum = 0;
  for(int i=0; i < int(v.size()); ++i) {
    sum += v[i];
  }
  return sum;
}

double mean(vector<double> v) {
  assert(!v.empty());
  return sum(v) / count(v);
}

double median(vector<double> v) {
  assert(!v.empty());
  sort(v);
  
  if(count(v) % 2 == 0){
    return(v[count(v) / 2 -1] + v[count(v) / 2]) / 2;
  } else{
    return v[count(v) / 2];
  }
}

double mode(vector<double> v) {
  assert(!v.empty());
  sort(v);

  double num = v.at(0);
  int current = 1;
  int max = 1;

  for(int i = 0; i < v.size(); ++i){
    current = 1;
    for(int k = i + 1; k < v.size(); ++k){
        if(v[i] == v[k]){
            current++;
        }
        if(current > max){
            max = current;
            num = v[i];

        }
        else if(current == max){
            if(v[i] < num){
                num = v[i];
            }
        }
    }
    
  }
  return num;
}

double min(vector<double> v) {
  assert(!v.empty());
  sort(v);
  return v[0];
}

double max(vector<double> v) {
  assert(!v.empty());
  sort(v);
  return v.back();
}

double stdev(vector<double> v) {
  assert(v.size() >= 2);
  double dev = 0.0;
  double standard;
  double denom = count(v) - 1;
  for(int i = 0; i < v.size(); ++i){
    dev += pow(v.at(i) - mean(v), 2);
  }
   standard = sqrt(dev / denom);
   return standard;
}

double percentile(vector<double> v, double p) {
  assert(!v.empty());
  assert(p >= 0 && p <= 1);

  sort(v);
  
  double n;
  double intpart;
  double fracpart;
  double ans;
  double sum;

  int size = v.size() - 1;
  
  if(p == 1){
    ans = v.at(v.size() -1);
  }
  else{
    n = (p * size) + 1;
    fracpart = modf(n, &intpart);

    sum = fracpart * (v[intpart] - v[intpart - 1]);
    ans = v[intpart - 1] + (sum);
  }

  return ans;

}

