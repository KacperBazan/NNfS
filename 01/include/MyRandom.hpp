#pragma once

#include "standard.hpp"
#include <random>
#include <ctime>

class MyRandom
{
private:
    static std::mt19937 rng;

public:
    static int randi(int min, int max);
    static double rand(double min, double max);
    static mat_t rand_mat(int rows, int cols, double min, double max);

    
};