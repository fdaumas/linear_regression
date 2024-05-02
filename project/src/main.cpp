#include "../lib/LinearRegression.hpp"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
  LinearRegression linearRegression;
  try {
    linearRegression.loadDataset();
    linearRegression.loadParams();
  } catch (std::ifstream::failure e) {
    std::cerr << "failed to load data.csv" << std::endl;
  }

  linearRegression.update();
  linearRegression.showDatasetAndParams();
  std::cout << "estimate price for 300000 milage: "<< linearRegression.realEstimatePrice(400000) << std::endl;;
}
