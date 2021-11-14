#include "standard.hpp"
#include "Activation_ReLU.hpp"
#include <algorithm>
#include <iostream>

mat_t Activation_ReLU::forward(const mat_t &inputs)
{
    m_outputs = mat_t(inputs.size(), vec_t(inputs[0].size()));
    for (size_t i = 0; i < inputs.size(); i++)
    {
        for (size_t j = 0; j < inputs[0].size(); j++)
        {
            m_outputs[i][j] = std::max(0.0, inputs[i][j]);
        }
    }
    return m_outputs;
}

void Activation_ReLU::print() const
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