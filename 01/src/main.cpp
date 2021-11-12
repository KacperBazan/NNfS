#include "standard.hpp"
#include <iostream>
#include <vector>
#include "Layer_Dense.hpp"
#include "MyRandom.hpp"

mat_t X = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

mat_t test1 = {{1.4, 5.6, -0.1, 4.4},
               {6.7, -5.5, -4.0, -0.1},
               {1.1, 0.0, -0.3, 5.5}};

mat_t test2 = {{0.9, -0.1, -0.1, 7.7, 0.8},
               {1.1, 6.6, 5.5, 2.2, 0.1},
               {-1.1, -6.6, -5.5, -2.2, -0.1},
               {2.1, 2.3, 2.5, 2.6, 2.89}};

int main()
{
    Layer_Dense layer1{4, 5};
    mat_t outputs = layer1.forward(X);
    layer1.print();
    return 0;
}