#include "LinearRegression.hpp"
#include <climits>
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

LinearRegression::LinearRegression(): 
  theta0(0),
  theta1(0),
  learningRate(0.5),
  dataset(std::vector<t_dataset>()),
  mileageMinMax({}),
  priceMinMax({})
{
  priceMinMax.min = INT_MAX;
  mileageMinMax.min = INT_MAX;
}

LinearRegression::~LinearRegression() {}


void LinearRegression::showDatasetAndParams() {
  std::cout << "dataset:\n" ; 
  for(std::vector<t_dataset>::iterator it = dataset.begin(); it != dataset.end(); it++) {
    std::cout << it->mileage << ',' << it->price << std::endl;
  }
  std::cout << "params: " << "learningRate: " << learningRate << ", theta0: " 
    << theta0 << ", theta1: " << theta1 << std::endl ;
  std::cout << "mileage min: " << mileageMinMax.min << ", mileage max: " << mileageMinMax.max << std::endl;
  std::cout << "price min: " << priceMinMax.min << ", price max: " << priceMinMax.max << std::endl;
}

void LinearRegression::loadDataset() {
  std::ifstream file("./csv/data.csv");
  std::string tmp;

  std::getline(file, tmp);
  while (!file.eof()) {
    t_dataset row = {};

    std::getline(file, tmp, ',');
    if (tmp.length())
      row.mileage = std::stoi(tmp);

    std::getline(file, tmp);
    if (tmp.length())
      row.price = std::stoi(tmp);

    if (rowIsValid(row)) {
      dataset.push_back(row);

      if (row.mileage > mileageMinMax.max)
        mileageMinMax.max = row.mileage;
      if (row.mileage < mileageMinMax.min)
        mileageMinMax.min = row.mileage;

      if (row.price > priceMinMax.max)
        priceMinMax.max = row.price;
      if (row.price < priceMinMax.min)
        priceMinMax.min = row.price;}
  }
}

void LinearRegression::loadParams() {
  std::ifstream file("./csv/params.csv");
  std::string tmp;

  std::getline(file, tmp);
  std::getline(file, tmp, ',');
  learningRate = std::stod(tmp);
  std::getline(file, tmp, ',');
  theta0 = std::stod(tmp);
  std::getline(file, tmp, ',');
  theta1 = std::stod(tmp);
}

double LinearRegression::estimatePrice(double mileage) {
  return (theta0 + (theta1 * mileage));
}

double LinearRegression::realEstimatePrice(double mileage) {
  if (theta0 == 0.0 || theta1 == 0.0) return 0;
  double mileageNormalized = normalize(mileage, mileageMinMax.min, mileageMinMax.max);

  return reverseNormalize(estimatePrice(mileageNormalized), priceMinMax.min, priceMinMax.max);
}

void LinearRegression::update() {
  double tmp_theta0;
  double tmp_theta1;

  for(int idx = 0; idx < 1000; idx++) { 

    tmp_theta0 = 0;
    tmp_theta1 = 0;

    for(std::vector<t_dataset>::iterator it = dataset.begin(); it != dataset.end(); it++) {
      double mileageNormalized = normalize(it->mileage, mileageMinMax.min, mileageMinMax.max);
      double priceNormalized = normalize(it->price, priceMinMax.min, priceMinMax.max);

      tmp_theta0 += estimatePrice(mileageNormalized) - priceNormalized;
      tmp_theta1 += (estimatePrice(mileageNormalized) - priceNormalized) * mileageNormalized;
    }
    theta0 -= (learningRate * (1.0 / dataset.size()) * tmp_theta0);
    theta1 -= (learningRate * (1.0 / dataset.size()) * tmp_theta1);
  }
  saveTraining(theta0, theta1);
}

void LinearRegression::saveTraining(double t0, double t1) {
  std::ofstream file("./csv/params.csv");
  file << "learningRate,theta0,teta1\n" << 0.5 << "," << t0 << "," << t1 << std::endl;
}
