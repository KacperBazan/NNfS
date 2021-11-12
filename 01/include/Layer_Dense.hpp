#include <vector>

typedef std::vector<std::vector<double>> mat_t;

class Layer_Dense
{
private:
    mat_t m_weights{};
    mat_t m_biases{};

public:
    Layer_Dense(int n_inputs, int n_outputs);
};
