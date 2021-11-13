#include "standard.hpp"
#include "spiralData.hpp"
#include "MyRandom.hpp"
#include <math.h>

std::tuple<mat_t, vec_t> spiralData(const int points, const int classes)
{
    mat_t X{mat_t(points * classes, vec_t(2))};
    vec_t y{vec_t(points * classes)};
    double r{};
    double t{};
    for (size_t i = 0; i < classes; ++i)
    {
        for (size_t j = 0; j < points; j++)
        {
            r = double(j) / double(points);
            t = i * 4 + (4 * r);
            X[i * points + j][0] = r * cos(t * 2.5) + MyRandom::rand(-0.15, 0.15);
            X[i * points + j][1] = r * sin(t * 2.5) + MyRandom::rand(-0.15, 0.15);
            y[i * points + j] = i;
        }
    }
    return std::make_tuple(X, y);
}