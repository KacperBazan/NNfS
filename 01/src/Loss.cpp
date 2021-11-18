//---Function definitions for the class Loss.

#include "Loss.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <cassert>
#include <math.h>
#include <algorithm>

//---Loss function that takes softmax values and returns an average loss.
void Loss::calculate(const mat_t &softmax_vals, const vec_t &target_classes)
{
    //The length of the batch must equal the length of the class identifiers for said batch.
    assert(softmax_vals.size() == target_classes.size() && "Size Mismatch - Target Classes");

    m_sample_losses = vec_t(softmax_vals.size());

    for (size_t i = 0; i < target_classes.size(); i++)
    {
        /*The index is held by value in the target_classes vector. Converted to an int since
        vec_t is a double vector by default.*/
        int index{static_cast<int>(target_classes[i])};

        /*-ln(x) returns inf if x = 0. We clamp the values to be slightly above 0 and slightly
        below 1.*/
        double clamped_val{std::clamp(softmax_vals[i][index], 1.0e-7, 1.0 - 1.0e-7)};
        m_sample_losses[i] = -log(clamped_val);
    }
}