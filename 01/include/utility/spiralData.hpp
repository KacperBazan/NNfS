#pragma once

#include "standard.hpp"
#include <tuple>

std::tuple<mat_t, vec_t> spiralData(const int points, const int classes);
std::ostream &operator<<(std::ostream &out, const std::tuple<mat_t, vec_t> &T);
