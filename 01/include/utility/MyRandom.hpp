#pragma once

#include "standard.hpp"
#include <random>

class MyRandom
{
private:
    static std::mt19937 rng;

public:
    static int randi(int min, int max);                                //Random integer
    static double rand(double min, double max);                        //Random double
    static mat_t rand_mat(int rows, int cols, double min, double max); //Matrix with random doubles.
    static vec_t rand_vec(int cols, double min, double max);           //Veco with random doubles
};