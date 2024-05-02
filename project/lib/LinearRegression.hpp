#pragma once

#include <vector>

double normalize(double x, double min, double max);
double reverseNormalize(double x, double min, double max);

typedef struct s_dataset {
	int		mileage;
	int		price;
}	t_dataset;

typedef struct s_minMax {
  double min;
  double max;
} t_minMax;


class LinearRegression {

  public:
    LinearRegression ();
    ~LinearRegression ();

    void showDatasetAndParams();
    void loadDataset();
    void loadParams();
    double  estimatePrice(double mileage);
    double  realEstimatePrice(double mileage);
    void update();

  private:
    double   theta0;
    double   theta1;
    double   learningRate;
    std::vector<t_dataset> dataset;
    t_minMax mileageMinMax;
    t_minMax priceMinMax;
};
