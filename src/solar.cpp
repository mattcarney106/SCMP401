#include <iostream>
#include <vector>
#include <random>
#include "solar.h"

using namespace std;

int main()
{
 helloWorld(); 
}

void helloWorld()
{
  double meanWatthrs = 100.0;
  double varianceWatthrs = 10.;

  for(int i=0;i>10;i++)
  {
    cout << get_random_watts(meanWatthrs, varianceWatthrs) << endl;
  }
}

/* Takes in powerOutput and returns
   The BEL rate in USD per kWhr
*/
double CalcBELRate(double powerOutput)
{
  double rate;
  if(powerOutput >= 0.0 && powerOutput < 51.0){
    rate = 0.30;
  }else if(powerOutput >= 51.0 && powerOutput < 201.0){
    rate = 0.36;
  }else if(powerOutput >= 201.0){
    rate = 0.40;
  }else{
    cout << "INVALID POWER OUTPUT\n";
  }

  return rate;
}

double get_random_watts(double meanWatthrs, double varianceWatthrs)
{
  double random_watts;
  //Instantiate random class
  random_device rd;

  //Random seed generator
  mt19937 gen(rd());

  //Instantiate normal distribution
  normal_distribution<double> d(double meanWatthrs, double varianceWatthrs);
  random_watts = d(gen);

  return random_watts;
}
