#pragma once

#include "standard.hpp" // for mat_t, vec_t

class Loss
{
private:
    vec_t m_sample_losses{};
    double m_data_loss{};

public:
    void calculate(const mat_t &softmax_outputs, const vec_t &targets);
};

#include <cassert>
#include <math.h>
#include <algorithm>

//---Loss function that takes softmax values and returns an average loss.
vec_t Loss(const mat_t &softmax_vals, const vec_t &target_classes)
{
    //The length of the batch must equal the length of the class identifiers for said batch.
    assert(softmax_vals.size() == target_classes.size() && "Size Mismatch - Target Classes");

    vec_t out{vec_t(softmax_vals.size())};

    for (size_t i = 0; i < target_classes.size(); i++)
    {
        /*The index is held by value in the target_classes vector. Converted to an int since
        vec_t is a double vector by default.*/
        int index{static_cast<int>(target_classes[i])};

        /*-ln(x) returns inf if x = 0. We clamp the values to be slightly above 0 and slightly
        below 1.*/
        double clamped_val{std::clamp(softmax_vals[i][index], 1.0e-7, 1.0 - 1.0e-7)};
        out[i] = -log(clamped_val);
    }
    return out;
}