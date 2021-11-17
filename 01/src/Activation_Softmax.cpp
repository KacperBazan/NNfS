//---Fucntion definitions for the class Activation_Softmax

#include "Activation_Softmax.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <math.h>       //for exp
#include <iostream>     //for std::ostream

//---Forward pass through the activation function.
mat_t Activation_Softmax::forward(const mat_t &inputs)
{
    m_outputs = mat_t(inputs.size(), vec_t(inputs[0].size()));

    for (size_t i = 0; i < inputs.size(); i++)
    {
        //Find the max for each row.
        double max{inputs[i][0]};
        for (size_t j = 1; j < inputs[0].size(); j++)
            max = (inputs[i][j] > max) ? inputs[i][j] : max;

        double sum{0.0};
        for (size_t j = 0; j < inputs[0].size(); j++)
        {
            //Exponentiate each value by subtracting max.
            m_outputs[i][j] = exp(inputs[i][j] - max);
            sum += m_outputs[i][j]; //Running sum.
        }

        //Divide by total to final outputs ranging from 0 to 1.
        for (size_t j = 0; j < inputs[0].size(); j++)
            m_outputs[i][j] /= sum;
    }
    return m_outputs;
}

//---Overloaded std::ostream operator for printing.
std::ostream &operator<<(std::ostream &out, const Activation_Softmax &S)
{
    for (const auto &row : S.m_outputs)
    {
        for (const auto &col : row)
            out << col << "\t";
        out << "\n";
    }
    return out;
}