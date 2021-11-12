#pragma once

#include "standard.hpp"
#include <vector>

int randi(int min, int max);
double rand(double min = 0, double max = 1.0);
mat_t rand_mat(int rows, int cols, double min, double max)