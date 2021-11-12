#include "standard.hpp"
#include "MyRandom.hpp"
#include <random>
#include <vector>
#include <ctime>

int randi(int min, int max)
{
    std::uniform_int_distribution<int> range{min, max};
    return range(MyRandom::rng);
}

double rand(double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    return range(MyRandom::rng);
}

mat_t rand_mat(int rows, int cols, double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    return mat_t(rows, vec_t(cols, range(MyRandom::rng)));
}