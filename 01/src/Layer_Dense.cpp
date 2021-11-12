#include "Layer_Dense.hpp"
#include "MyRandom.hpp"

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

Layer_Dense::Layer_Dense(int n_inputs, int n_outputs)
{
    m_weights = rand_mat(n_inputs, n_outputs, -0.1, 0.1);
    m_biases = rand_mat(1, n_outputs, 0.0, 0.0);
}

vec_t Layer_Dense::forward(const mat_t &inputs)
{
    
}
