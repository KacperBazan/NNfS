#pragma once

#include "standard.hpp"
#include <iostream>

class Layer_Dense
{
private:
    mat_t m_weights{};
    mat_t m_outputs{};
    vec_t m_biases{};

public:
    Layer_Dense(const int n_inputs, const int n_outputs);

    //---Forward pass through the layer.
    mat_t forward(const mat_t &inputs);

    //---Overloaded std::ostream operator for printing.
    friend std::ostream &operator<<(std::ostream &out, const Layer_Dense &L);

    //---Getters for weights matrix, outputs matrix and biases vector.
    const mat_t &weights() const { return m_weights; }
    const mat_t &outputs() const { return m_outputs; }
    const vec_t &biases() const { return m_biases; }
};
