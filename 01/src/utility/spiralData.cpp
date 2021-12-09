#include "spiralData.hpp"
#include "standard.hpp" //for mat_t, vec_t
#include "MyRandom.hpp" //for MyRandom
#include <math.h>       //for cos, sin
#include <iostream>

//---Makes tuple of matrix of 2D points and vector classifying points.
std::tuple<mat_t, vec_t> spiralData(const int points, const int classes)
{
    mat_t X{mat_t(points * classes, vec_t(2))}; //Holds (x,y) coordinates
    vec_t y{vec_t(points * classes)};           //Distinguishes the type of class
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

//---Overloaded std::ostream operator for printing.
std::ostream &operator<<(std::ostream &out, const std::tuple<mat_t, vec_t> &T)
{
    std::cout << "X [Coordinates]:\n";
    for (const auto &row : std::get<0>(T))
    {
        for (const auto &col : row)
            out << col << "  ";
        out << "\n";
    }
    std::cout << "y [Classes]:\n";
    for (const auto &row : std::get<1>(T))
    {
        out << row << "  ";
    }
    std::cout << '\n';
    return out;
}