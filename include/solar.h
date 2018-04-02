/* Functions used for solar panel data analysis */

void helloWorld();
double CalcBELRate(double powerOutput);
std::vector<double> get_random_watts_vec(double meanWatthrs, double varianceWatthrs, size_t size);
std::vector<double> money_saved(std::vector<double> watthrs);
std::vector<double> amount_unpaid(double initial_cost, std::vector<double> money_saved);
