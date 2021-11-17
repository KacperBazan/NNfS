//---Function definitions for the class Layer_Dense

#include "Layer_Dense.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include "MyRandom.hpp" //for MyRandom
#include "dot.hpp"      //for dot and overloaded addition
#include <iostream>     //for std::ostream

Layer_Dense::Layer_Dense(const int n_inputs, const int n_outputs)
{
    m_weights = MyRandom::rand_mat(n_inputs, n_outputs, -0.1, 0.1);

    /* If the network is dead upon reaching the output layer, then
        initializing the biases to non-zero values might help it. */
    m_biases = MyRandom::rand_vec(n_outputs, 0.0, 0.0);
}

//---Forward pass through the layer.
mat_t Layer_Dense::forward(const mat_t &inputs)
{
    m_outputs = dot(inputs, m_weights) + m_biases;
    return m_outputs;
}

//---Overloaded std::ostream operator for printing.
std::ostream &operator<<(std::ostream &out, const Layer_Dense &L)
{
    std::cout << "Weights:\n";
    for (const auto &row : L.m_weights)
    {
        for (const auto &col : row)
        {
            std::cout << col << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\nBiases:\n";
    for (const auto &row : L.m_biases)
    {
        std::cout << row << "  ";
    }
    std::cout << "\n";

    std::cout << "\nOutputs:\n";
    for (const auto &row : L.m_outputs)
    {
        for (const auto &col : row)
        {
            std::cout << col << "  ";
        }
        std::cout << "\n";
    }
}
