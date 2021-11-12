#pragma once

#include "standard.hpp"
#include <vector>

class Layer_Dense
{
private:
    mat_t m_weights{};
    mat_t m_biases{};
    mat_t m_outputs{};

public:
    Layer_Dense(int n_inputs, int n_outputs);
    mat_t forward(const mat_t &inputs);

    //Layer_Dense operator+(const vec_t &biases);
};
