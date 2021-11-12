#include "MyRandom.hpp"
#include <random>
#include <vector>
#include <ctime>

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

namespace MyRandom
{
    std::mt19937 rng{static_cast<std::mt19937::result_type>(std::time(nullptr))};
}

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