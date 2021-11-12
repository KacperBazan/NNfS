#include "standard.hpp"
#include "Layer_Dense.hpp"
#include "MyRandom.hpp"
#include "dot.hpp"
#include <cassert>
#include <iostream>

Layer_Dense::Layer_Dense(int n_inputs, int n_outputs)
{
    m_weights = MyRandom::rand_mat(n_inputs, n_outputs, -0.1, 0.1);
    std::cout << '\n';
    m_biases = MyRandom::rand_mat(1, n_outputs, 0.0, 0.0);
    std::cout << "---------------------\n";
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

void Layer_Dense::print() const
{
    std::cout << "Weights\n";
    // for (const auto &row : m_weights)
    // {
    //     std::cout << "| ";
    //     for (const auto &col : row)
    //     {
    //         std::cout << col << " | ";
    //     }
    //     std::cout << "\n";
    // }
}

// Layer_Dense::Layer_Dense operator+(const vec_t &biases)
// {
// }
