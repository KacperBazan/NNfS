#include "standard.hpp"
#include "MyRandom.hpp"
#include <random>
#include <iostream>
#include <ctime>

int MyRandom::randi(int min, int max)
{
    std::uniform_int_distribution<int> range{min, max};
    return range(MyRandom::rng);
}

double MyRandom::rand(double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    return range(MyRandom::rng);
}

mat_t MyRandom::rand_mat(int rows, int cols, double min, double max)
{
    std::uniform_real_distribution<double> range{min, max};
    mat_t out{mat_t(rows, vec_t(cols))};
    for (auto &row : out)
    {
        for (auto &col : row)
            col = range(MyRandom::rng);
    }

    std::cout << "Random Mat: [" << rows << "," << cols << "]\n";
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << out[i][j] << ", ";
        }
        std::cout << '\n';
    }
    return out;
}

std::mt19937 MyRandom::rng{static_cast<std::mt19937::result_type>(std::time(nullptr))};
