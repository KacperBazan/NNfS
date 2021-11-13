#include "standard.hpp"
#include "Layer_Dense.hpp"
#include <iostream>

mat_t X = {{1, 2, 3, 2.5},
           {2, 5, -1, 2},
           {-1.5, 2.7, 3.3, -0.8}};

int main()
{
    Layer_Dense layer1{4, 5};
    Layer_Dense layer2{5, 5};
    layer1.forward(X);
    layer2.forward(layer1.outputs());
    layer2.print();
    return 0;
}