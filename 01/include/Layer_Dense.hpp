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
    void print() const;

    const mat_t &weights() const { return m_weights; }
    const mat_t &biases() const { return m_biases; }
    const mat_t &outputs() const { return m_outputs; }

    //Layer_Dense operator+(const vec_t &biases);
};
