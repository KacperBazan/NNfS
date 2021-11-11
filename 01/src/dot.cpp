#include "dot.hpp"
#include <vector>
#include <cassert>
typedef std::vector<double> vec_t;

double dot(vec_t a, vec_t b)
{
    assert(a.size() == b.size() && "Dot Product Error: Vectors must be of same size.");
    double out{0.0};
    for (size_t i = 0; i < a.size(); ++i)
        out += a[i] * b[i];
    return out;
}

