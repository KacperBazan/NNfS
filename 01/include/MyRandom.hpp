#pragma once

#include "standard.hpp"
#include <random>
#include <ctime>

class MyRandom
{
    static std::mt19937 rng;
    static int randi(int min, int max);
    static double rand(double min, double max);
    static mat_t rand_mat(int rows, int cols, double min, double max);
};

std::mt19937 MyRandom::rng{static_cast<std::mt19937::result_type>(std::time(nullptr))};