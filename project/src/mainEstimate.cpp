
#include "../lib/LinearRegression.hpp"
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: ./LinearRegressionEstimate {car mileage}" << std::endl;
    return 1;
  }

  LinearRegression linearRegression;
  try {
    linearRegression.loadParams();
    linearRegression.loadDataset();
  } catch (...) {
    std::cerr << "failed to load data or params" << std::endl;
  }
  try {
    int mileage = std::stoi(argv[1]);
    std::cout << "estimate price for " << argv[1] << " milage: "<< linearRegression.realEstimatePrice(mileage) << std::endl;;
  } catch (...) {
    std::cerr << "Invalid car mileage" << std::endl;
  }
}
