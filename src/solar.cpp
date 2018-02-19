#include <iostream>
#include <vector>
#include "solar.h"

using namespace std;

int main()
{
 helloWorld(); 
}

void helloWorld()
{
  cout << "Hello, world!\n";
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

double 
