//---Fucntion definitions for the static class MyRandom.

#include "MyRandom.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <random>       //for std::mt19937
#include <ctime>        //for std::time

//---Produces random integer between min and max.
int MyRandom::randi(int min, int max)
{
    std::uniform_int_distribution<int> range{min, max};
    return range(MyRandom::rng);
}

//---Produces random double between min and max.
double MyRandom::rand(double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    return range(MyRandom::rng);
}

/*---Produces a matrix of size [rows,cols] with each value being in
    the range between min and max.*/
mat_t MyRandom::rand_mat(int rows, int cols, double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    mat_t out{mat_t(rows, vec_t(cols))};
    for (auto &row : out)
    {
        for (auto &col : row)
            col = range(MyRandom::rng);
    }
    return out;
}

/*---Produces a vector of length rows with each value being in the 
    range between min and max.*/
vec_t MyRandom::rand_vec(int cols, double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    vec_t out{vec_t(cols)};
    for (auto &col : out)
        col = range(MyRandom::rng);
    return out;
}

//---RNG generator set up with system clock.
std::mt19937 MyRandom::rng{static_cast<std::mt19937::result_type>(std::time(nullptr))};
