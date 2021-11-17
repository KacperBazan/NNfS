#pragma once

#include "standard.hpp"
#include <iostream>

class Activation_ReLU
{
private:
    mat_t m_outputs{};

public:
    //---Forward pass through the activation function.
    mat_t forward(const mat_t &inputs);

    //---Overloaded std::ostream operator for printing.
    friend std::ostream &operator<<(std::ostream &out, const Activation_ReLU &A);

    //---Getter for the m_outputs.
    const mat_t &outputs() const { return m_outputs; }
};