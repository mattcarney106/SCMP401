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

  for(int i=0;i<10;i++)
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
  std::random_device rd;

  //Random seed generator
  std::mt19937 gen(rd());

  //Instantiate normal distribution
  std::normal_distribution<double> draw(meanWatthrs, varianceWatthrs);
  random_watts = draw(gen);


  cout << random_watts << endl;
  return random_watts;
}

vector<double> get_random_watts_vec(double meanWatthrs, double varianceWatthrs, size_t size)
{
  //Declare vector to carry watt-hour data
  vector<double> random_watts(size_t);

  //Instantiate random class
  std::random_device rd;

  //Random seed generator
  std::mt19937 gen(rd());

  //Populate vector with watt-hour data
  for(int i=0;i < size;i++)
  {
    //Instantiate normal distribution
    std::normal_distribution<double> draw(meanWatthrs, varianceWatthrs);
    random_watts[i] = draw(gen);
  }

  return random_watts;
}
