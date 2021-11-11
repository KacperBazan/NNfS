#pragma once
#include <vector>
typedef std::vector<double> vec_t;

vec_t layerOutput(const vec_t inputs, const std::vector<vec_t> weights, const vec_t biases);