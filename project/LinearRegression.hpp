#pragma once

#include <vector>

typedef struct s_dataset
{
	int		mileage;
	int		price;
}	t_dataset;

class LinearRegression {
public:
  LinearRegression ();
  ~LinearRegression ();

  void showDataset();
  void loadDataset();
  void loadParams();

private:
  float   theta0;
  float   theta1;
  float   learningRate;
  std::vector<t_dataset> dataset;
};
