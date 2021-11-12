#pragma once
#include <vector>

typedef std::vector<std::vector<double>> mat_t;
typedef std::vector<double> vec_t;

mat_t dot(const mat_t &a, const mat_t &b);