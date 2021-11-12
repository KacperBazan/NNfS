#include <vector>

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

class Layer_Dense
{
private:
    mat_t m_weights{};
    mat_t m_biases{};
    mat_t m_outputs{};

public:
    Layer_Dense(int n_inputs, int n_outputs);
    vec_t forward(const mat_t &inputs);
};
