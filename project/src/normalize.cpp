double normalize(double x, double min, double max) {
  return (x - min) / (max - min);
}

double reverseNormalize(double x, double min, double max) {
  return x * (max - min) + min;
}
