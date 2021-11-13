#pragma once
#include "standard.hpp"

class Activation_ReLU
{
private:
    mat_t m_outputs{};

public:
    mat_t forward(const mat_t &inputs);
};