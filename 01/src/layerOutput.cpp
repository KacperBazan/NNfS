#include "layerOutput.hpp"
#include "dot.hpp"
#include <vector>

typedef std::vector<double> vec_t;

vec_t layerOutput(const vec_t inputs, const std::vector<vec_t> weights, const vec_t biases)
{
    vec_t out{};
    for (size_t i = 0; i < biases.size(); ++i)
        out.push_back(biases[i] + dot(inputs, weights[i]));
    return out;
}