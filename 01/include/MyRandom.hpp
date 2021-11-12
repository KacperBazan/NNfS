#pragma once

#include <vector>

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

int randi(int min, int max);
double rand(double min = 0, double max = 1.0);
mat_t rand_mat(int rows, int cols, double min, double max)