#pragma once
#include "standard.hpp"

#include <vector>
#include <random>
#include <vector>
#include <ctime>

namespace MyRandom
{
    std::mt19937 rng{static_cast<std::mt19937::result_type>(std::time(nullptr))};
}

int randi(int min, int max);
double rand(double min = 0, double max = 1.0);
mat_t rand_mat(int rows, int cols, double min, double max)