#include "standard.hpp"
#include "Layer_Dense.hpp"
#include "MyRandom.hpp"
#include "dot.hpp"
#include <cassert>

Layer_Dense::Layer_Dense(int n_inputs, int n_outputs)
{
    m_weights = rand_mat(n_inputs, n_outputs, -0.1, 0.1);
    m_biases = rand_mat(1, n_outputs, 0.0, 0.0);
}

mat_t Layer_Dense::forward(const mat_t &inputs)
{
    m_outputs = dot(inputs, m_weights);
    for (size_t i = 0; i < m_outputs.size(); i++)
    {
        for (size_t j = 0; j < m_outputs[0].size(); j++)
        {
            m_outputs[i][j] += m_biases[1][j];
        }
    }
    return m_outputs;
}

// Layer_Dense::Layer_Dense operator+(const vec_t &biases)
// {
// }
