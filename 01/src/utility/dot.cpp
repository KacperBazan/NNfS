#include "dot.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include <cassert>      //for assert

//---Matrix Dot Product
mat_t dot(const mat_t &a, const mat_t &b)
{
    //Matrices can only be multiplied with inner dimensions match.
    assert(a[0].size() == b.size() && "Size Mismatch - Matrix Dot Product");

    mat_t out{mat_t(a.size(), vec_t(b[0].size()))};

    for (size_t i = 0; i < a.size(); ++i)
    {
        for (size_t j = 0; j < b[0].size(); ++j)
        {
            double val{0.0};
            for (size_t k = 0; k < a[0].size(); k++)
            {
                val += a[i][k] * b[k][j];
            }
            out[i][j] = val;
        }
    }
    return out;
}

//---Adding a vector to a matrix
mat_t operator+(const mat_t &a, const vec_t &b)
{
    assert(a[0].size() == b.size() && "Size Mismatch - Matrix Addition");
    mat_t out{mat_t(a.size(), vec_t(a[0].size()))};
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < a[0].size(); j++)
        {
            out[i][j] = a[i][j] + b[j];
        }
    }
    return out;
}
