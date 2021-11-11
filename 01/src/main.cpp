#include "layerOutput.hpp"
#include <iostream>
#include <vector>
typedef std::vector<double> vec_t;

//vec_t inputs = {1.0, 2.0, 3.0, 2.5};
std::vector<vec_t> inputs = {{1.0, 2.0, 3.0, 2.5},
                             {2.0, 5.0, -1.0, 2.0},
                             {-1.5, 2.7, 3.3, -0.8}};

std::vector<vec_t> weights = {{0.2, 0.8, -0.5, 1.0},
                              {0.5, -0.91, 0.26, -0.5},
                              {-0.26, -0.27, 0.17, 0.87}};
vec_t biases = {2.0, 3.0, 0.5};

int main()
{
    vec_t outputs = layerOutput(inputs, weights, biases);

    return 0;
}