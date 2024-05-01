#include "LinearRegression.hpp"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
  LinearRegression test;
  try {
    test.loadDataset();
  } catch (std::ifstream::failure e) {
    std::cerr << "failed to load data.csv" << std::endl;
  }

  test.showDataset();
}
