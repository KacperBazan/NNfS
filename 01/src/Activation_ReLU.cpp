#include "standard.hpp"
#include "Activation_ReLU.hpp"
#include <algorithm>

mat_t Activation_ReLU::forward(const mat_t &inputs)
{
    mat_t out{mat_t(inputs.size(), vec_t(inputs[0].size()))};
    for (size_t i = 0; i < inputs.size(); i++)
    {
        for (size_t j = 0; j < inputs[0].size(); j++)
        {
            out[i][j] = std::max(0.0, inputs[i][j]);
        }
    }
    return out;
}