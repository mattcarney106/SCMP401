#include <iostream>
#include <vector>
#include <random>
#include "solar.h"

using namespace std;

int main()
{
  double meanWatthrs = 100.0;
  double varianceWatthrs = 50.;
  double initial_cost = 10000;

  vector<double> test_vec = get_random_watts_vec(meanWatthrs, varianceWatthrs, 30000);
  vector<double> money_saved_test = money_saved(test_vec);
  vector<double> unpaid = amount_unpaid(initial_cost, money_saved_test);

  //Prints out random Watt data
  for(int i=0;i<test_vec.size();i++)
  {
    cout << unpaid[i]<< endl;
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


vector<double> get_random_watts_vec(double meanWatthrs, double varianceWatthrs, size_t size)
{
  //Declare vector to carry watt-hour data
  vector<double> random_watts;

  //Instantiate random class
  std::random_device rd;

  //Random seed generator
  std::mt19937 gen(rd());

  //Populate vector with watt-hour data
  for(int i=0;i < size;i++)
  {
    //Instantiate normal distribution
    std::normal_distribution<double> draw(meanWatthrs, varianceWatthrs);
    random_watts.push_back(draw(gen));
  }

  return random_watts;
}

vector<double> money_saved(vector<double> watthrs)
{
  double BELRate = 0.;
  //Since each data point is for 1 hour, BEL rate is money saved for that hour
  vector<double> money_saved(watthrs.size());
  for(int i=0;i<money_saved.size();i++)
  {
    BELRate = CalcBELRate(watthrs[i]);
    money_saved[i] = BELRate;
  }
  return money_saved;
}

vector<double> amount_unpaid(double initial_cost, vector<double> money_saved)
{
  vector<double> amount_unpaid(money_saved.size());
  double current_unpaid = initial_cost;
  for(int i=0;i<amount_unpaid.size();i++)
  {
    amount_unpaid[i] = current_unpaid - money_saved[i];
    current_unpaid = amount_unpaid[i];
  }
  return amount_unpaid;
}
