#pragma once

#include "standard.hpp" // for mat_t, vec_t

class Loss
{
private:
    vec_t m_sample_losses{};
    double m_data_loss{};

public:
    vec_t calculate(const mat_t &softmax_outputs, const vec_t &targets);
    vec_t calculate(const mat_t &softmax_outputs, const mat_t &one_hot_encoded);
};
