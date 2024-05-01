#include "LinearRegression.hpp"
#include <ostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

bool rowIsValid(t_dataset row) {
  if (row.price && row.mileage)
    return 1;
  return 0;
}

LinearRegression::LinearRegression() {

}

LinearRegression::~LinearRegression() {}


void LinearRegression::showDataset() {
    for(std::vector<t_dataset>::iterator it = dataset.begin(); it != dataset.end(); it++) {
      std::cout << it->mileage << ',' << it->price << std::endl;
    }
}

void LinearRegression::loadDataset() {
  std::ifstream file("data.csv");
  std::string tmp;

  std::getline(file, tmp);
  while (!file.eof()) {
    t_dataset row;

    std::getline(file, tmp, ',');
    if (tmp.length())
      row.mileage = std::stoi(tmp);

    std::getline(file, tmp);
    if (tmp.length())
      row.price = std::stoi(tmp);

    if (rowIsValid(row))
      dataset.push_back(row);
  }
}

void LinearRegression::loadParams() {
  std::ifstream file("params");
  std::string tmp;

  std::getline(file, tmp);
  std::getline(file, tmp, ',');

}
