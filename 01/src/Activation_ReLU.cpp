//---Fucntion definitions for the class Activation_ReLU

#include "Activation_ReLU.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <algorithm>    //for std::max
#include <iostream>     //for std::ostream

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
std::ostream &operator<<(std::ostream &out, const Activation_ReLU &A)
{
    for (const auto &row : A.m_outputs)
    {
        for (const auto &col : row)
            out << col << "  ";
        out << "\n";
    }
    return out;
}