#include "standard.hpp"
#include "Activation_ReLU.hpp"
#include <algorithm>
#include <iostream>

//---Forward pass through the activation function.
mat_t Activation_ReLU::forward(const mat_t &inputs)
{
    m_outputs = mat_t(inputs.size(), vec_t(inputs[0].size()));
    for (size_t i = 0; i < inputs.size(); i++)
    {
        for (size_t j = 0; j < inputs[0].size(); j++)
        {
            //ReLU is defined by clamping negative values to 0.
            m_outputs[i][j] = std::max(0.0, inputs[i][j]);
        }
    }
    return m_outputs;
}

//---Overloaded std::ostream operator for printing.
std::ostream &operator<<(std::ostream &out, const Activation_ReLU &a)
{
    for (const auto &row : a.m_outputs)
    {
        for (const auto &col : row)
            out << col << "\t";
        out << "\n";
    }
    return out;
}