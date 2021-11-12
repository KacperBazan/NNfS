#include "dot.hpp"
#include <vector>
#include <cassert>

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

mat_t dot(const mat_t &a, const mat_t &b)
{
    assert(a[0].size() == b.size() && "Size Mismatch - Matrix");
    mat_t out{mat_t(a.size(), vec_t(b[0].size()))};

    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < b[0].size(); ++j)
        {
            double val{0.0};
            for (size_t k = 0; k < a[0].size(); k++)
            {
                val += a[i][j + k] * b[i + k][j];
            }
        }
    }
}
