//---Function definitions for the class Loss.

#include "Loss.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <cassert>
#include <math.h>
#include <algorithm>
#include <iostream>

//---Loss function that takes softmax values and returns an average loss.
double Loss::calculate(const mat_t &softmax_vals, const vec_t &target_classes)
{
    //The length of the batch must equal the length of the class identifiers for said batch.
    assert(softmax_vals.size() == target_classes.size() && "Size Mismatch - Target Classes");

    m_sample_losses = vec_t(softmax_vals.size());
    double run_sum{0.0};

    for (size_t i = 0; i < target_classes.size(); i++)
    {
        /*The index is held by value in the target_classes vector. Converted to an int since
        vec_t is a double vector by default.*/
        int index{static_cast<int>(target_classes[i])};

        /*-ln(x) returns inf if x = 0. We clamp the values to be slightly above 0 and slightly
        below 1.*/
        double clamped_val{std::clamp(softmax_vals[i][index], 1.0e-7, 1.0 - 1.0e-7)};
        m_sample_losses[i] = -log(clamped_val);
        run_sum += m_sample_losses[i];
    }

    m_data_loss = run_sum / static_cast<double>(target_classes.size());
    return m_data_loss;
}

double Loss::calculate(const mat_t &softmax_vals, const mat_t &one_hot_encoded)
{
    vec_t target_classes{vec_t(one_hot_encoded.size())};
    for (size_t i = 0; i < one_hot_encoded.size(); i++)
    {
        for (size_t j = 0; j < one_hot_encoded[0].size(); j++)
        {
            if (static_cast<int>(one_hot_encoded[i][j]) == 1)
            {
                target_classes[i] = j;
                break;
            }
            target_classes[i] = -1;
        }
    }
    return calculate(softmax_vals, target_classes);
}

std::ostream &operator<<(std::ostream &out, const Loss &L)
{
    out << "Losses:\n";
    for (const auto &col : L.m_sample_losses)
        out
            << col << "  ";
    out << "\n\n";

    out << "Average Loss: " << L.m_data_loss << '\n';
    return out;
}