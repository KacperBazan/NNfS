#include "standard.hpp"
#include "Activation_Softmax.hpp"
#include <math.h>
#include <iostream>

mat_t Activation_Softmax::forward(const mat_t &inputs)
{
    m_outputs = mat_t(inputs.size(), vec_t(inputs[0].size()));

    for (size_t i = 0; i < inputs.size(); i++)
    {
        double max{inputs[i][0]};
        for (size_t j = 1; j < inputs[0].size(); j++)
        {
            max = (inputs[i][j] > max) ? inputs[i][j] : max;
        }
        double sum{0.0};
        for (size_t j = 0; j < inputs[0].size(); j++)
        {
            m_outputs[i][j] = exp(inputs[i][j] - max);
            sum += m_outputs[i][j];
        }
        for (size_t j = 0; j < inputs[0].size(); j++)
            m_outputs[i][j] /= sum;
    }
    return m_outputs;
}

void Activation_Softmax::print() const
{
    for (const auto &row : m_outputs)
    {
        for (const auto &col : row)
        {
            std::cout << col << "\t";
        }
        std::cout << "\n";
    }
}