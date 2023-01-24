/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();

// Add prototypes for you test functions here.
void testsummarize();
void testsummarize2();
void testsummarize3();

void testcount();
void testcount2();

void testmean();
void testmean2();
void testmean3();
void testmean4();

void testmedian();
void testmedian2();
void testmedian3();

void testmode();
void testmode2();
void testmode3();
void testmode4();

void testmin();
void testmin2();
void testmin3();

void testmax();
void testmax2();
void testmax3();
void testmax4();

void teststdev();
void teststdev2();
void teststdev3();

void testpercentile();
void testpercentile2();
void testpercentile3();

int main() {
  test_sum_small_data_set();
  
  // Call your test functions here
  testsummarize();
  testsummarize2();
  testsummarize3();

  testcount();
  testcount2();

  testmean();
  testmean2();
  testmean3();
  testmean4();

  testmedian();
  testmedian2();
  testmedian3();

  testmode();
  testmode2();
  testmode3();
  testmode4();

  testmin();
  testmin2();
  testmin3();

  testmax();
  testmax2();
  testmax3();
  testmax4();

  teststdev();
  teststdev2();
  teststdev3();

  testpercentile();
  testpercentile2();
  testpercentile3();

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

// Add the test function implementations here.

//summarize test cases
void testsummarize() {
  cout << "testsummarize" << endl;
  
  vector<double> data = {1, 1, 2, 3, 3};
  vector<pair<double, int> > ans = {{1, 2}, {2, 1}, {3, 2}};
  vector<pair<double, int> > test = summarize(data);
  assert(ans == test);

  cout << "PASS!" << endl;

}

void testsummarize2() {
  cout << "testsummarize2" << endl;
  
  vector<double> data = {1, 2, 3};
  vector<pair<double, int> > ans = {{1, 1}, {2, 1}, {3, 1}};
  vector<pair<double, int> > test = summarize(data);
  assert(ans == test);

  cout << "PASS!" << endl;

}

void testsummarize3() {
  cout << "testsummarize3" << endl;
  
  vector<double> data = {.7, .7, 1, 2, 2.3, 2.3};
  vector<pair<double, int> > ans = {{.7, 2}, {1, 1}, {2, 1}, {2.3, 2.3}};
  vector<pair<double, int> > test = summarize(data);
  assert(ans == test);

  cout << "PASS!" << endl;

}

//count test cases
void testcount() {
  cout << "testcount" << endl;
  
  vector<double> data = {1, 2, 3};
  double result = count(data);
  
  assert(result == 3);

  cout << "PASS!" << endl;

}

void testcount2() {
  cout << "testcount2" << endl;

  vector<double> data = {1, .6, .9, 2};
  double result = count(data);

  assert(result == 4);

  cout << "PASS!" << endl;
}

//mean test cases
void testmean() {
  cout << "testmean" << endl;
  
  vector<double> data = {1, 2, 3};
  double result = mean(data);
  
  assert(result == 2);

  cout << "PASS!" << endl;

}

void testmean2() {
  cout << "testmean2" << endl;
  
  vector<double> data = {1, 2, 3, 4};
  double result = mean(data);
  
  assert(result == 2.5);

  cout << "PASS!" << endl;

}

void testmean3() {
  cout << "testmean3" << endl;
  
  vector<double> data = {5};
  double result = mean(data);
  
  assert(result == 5);

  cout << "PASS!" << endl;

}

void testmean4() {
  cout << "testmean4" << endl;
  
  vector<double> data = {.3, .2, .1, .4};
  double result = mean(data);
  
  assert(result == .25);

  cout << "PASS!" << endl;

}

//median test cases
void testmedian() {
  cout << "testmedian" << endl;
  
  vector<double> data = {1, 2, 3};
  double result = median(data);
  
  assert(result == 2);

  cout << "PASS!" << endl;

}

void testmedian2() {
  cout << "testmedian2" << endl;
  
  vector<double> data = {1, 2, 3, 4};
  double result = median(data);
  
  assert(result == 2.5);

  cout << "PASS!" << endl;

}

void testmedian3() {
  cout << "testmedian3" << endl;
  
  vector<double> data = {.3, .2, .1, .4};
  double result = median(data);
  
  assert(result == .25);

  cout << "PASS!" << endl;

}

//mode test cases
void testmode() {
  cout << "testmode" << endl;
  
  vector<double> data = {2, 2, 3};
  double result = mode(data);
  
  assert(result == 2);

  cout << "PASS!" << endl;

}

void testmode2() {
  cout << "testmode2" << endl;
  
  vector<double> data = {6, 7, 8, 9, 10};
  double result = mode(data);
  
  assert(result == 6);

  cout << "PASS!" << endl;

}

void testmode3() {
  cout << "testmode3" << endl;
  
  vector<double> data = {.2, .2, .1, .1, .1, .4, .4, 5, 6};
  double result = mode(data);
  
  assert(result == .1);

  cout << "PASS!" << endl;

}

void testmode4() {
  cout << "testmode4" << endl;
  
  vector<double> data = {2};
  double result = mode(data);
  
  assert(result == 2);

  cout << "PASS!" << endl;

}

//min test cases
void testmin() {
  cout << "testmin" << endl;
  
  vector<double> data = {1, 2, 3};
  double result = min(data);
  
  assert(result == 1);

  cout << "PASS!" << endl;

}

void testmin2() {
  cout << "testmin2" << endl;
  
  vector<double> data = {1};
  double result = min(data);
  
  assert(result == 1);

  cout << "PASS!" << endl;

}

void testmin3() {
  cout << "testmin3" << endl;
  
  vector<double> data = {5, 3, 9, 10, 11, 34, 2};
  double result = min(data);
  
  assert(result == 2);

  cout << "PASS!" << endl;

}

//max test cases
void testmax() {
  cout << "testmax" << endl;
  
  vector<double> data = {1, 2, 3};
  double result = max(data);
  
  assert(result == 3);

  cout << "PASS!" << endl;

}

void testmax2() {
  cout << "testmax2" << endl;
  
  vector<double> data = {1};
  double result = max(data);
  
  assert(result == 1);

  cout << "PASS!" << endl;

}

void testmax3() {
  cout << "testmax3" << endl;
  
  vector<double> data = {5, 3, 9, 10, 11, 34, 2};
  double result = max(data);
  
  assert(result == 34);

  cout << "PASS!" << endl;

}

void testmax4() {
  cout << "testmax4" << endl;
  
  vector<double> data = {.3, .3, .2, .5};
  double result = max(data);
  
  assert(result == .5);

  cout << "PASS!" << endl;

}

//stdev test cases
void teststdev() { 
  cout << "teststdev" << endl;

  vector<double> data = {1, 2, 3};
  double result = stdev(data);
  
  assert(result == 1);

  cout << "PASS!" << endl;
  
}

void teststdev2() { 
  cout << "teststdev2" << endl;

  vector<double> data = {3, 2, 5, 7, 9};
  double result = stdev(data);
  
  assert(result == 2.8635642126552709);

  cout << "PASS!" << endl;
  
}

void teststdev3() { 
  cout << "teststdev3" << endl;

  vector<double> data = {.1, .4, 2.9, 2.2, 1.3, 7.9};
  double result = stdev(data);
  
  assert(result == 2.864029795003304);

  cout << "PASS!" << endl;
  
}

//percentile test cases
void testpercentile() { 
  cout << "testpercentile" << endl;

  vector<double> data = {15, 20, 35, 40, 50};
  double p = .4;
  double result = percentile(data, p);
  
  assert(result == 29);

  cout << "PASS!" << endl;
  
}

void testpercentile2() { 
  cout << "testpercentile2" << endl;

  vector<double> data = {1, 2, 3, 4};
  double p = 1;
  double result = percentile(data, p);
  
  assert(result == 4);

  cout << "PASS!" << endl;
  
}

void testpercentile3() { 
  cout << "testpercentile3" << endl;

  vector<double> data = {1, 2, 3, 4};
  double p = 0;
  double result = percentile(data, p);
  
  assert(result == 1);

  cout << "PASS!" << endl;
  
}