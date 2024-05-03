#include "../lib/LinearRegression.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
  LinearRegression linearRegression;
  try {
    linearRegression.loadDataset();
    linearRegression.loadParams();
  } catch (...) {
    std::cerr << "failed to load data or params" << std::endl;
  }

  try {
    linearRegression.update();
  } catch(...) {
    std::cerr << "an error as occured" << std::endl;
  }
}
