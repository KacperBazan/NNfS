#pragma once
#include "standard.hpp"

class Activation_Softmax
{
private:
    mat_t m_outputs{};

public:
    mat_t forward(const mat_t &inputs);
    void print() const;
    const mat_t &outputs() const { return m_outputs; }
};