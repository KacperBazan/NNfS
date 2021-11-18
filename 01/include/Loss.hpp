#pragma once

#include "standard.hpp"
#include <iostream>

class Loss
{
private:
    vec_t m_sample_losses{};
    double m_data_loss{};

public:
    double calculate(const mat_t &softmax_outputs, const vec_t &targets);
    double calculate(const mat_t &softmax_outputs, const mat_t &one_hot_encoded);

    friend std::ostream &operator<<(std::ostream &out, const Loss &L);
};
