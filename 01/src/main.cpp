#include "standard.hpp"
#include <iostream>
#include <vector>
#include "Layer_Dense.hpp"
#include "MyRandom.hpp"
#include "dot.hpp"

mat_t X = {{1, 2, 3, 2.5},
           {2, 5, -1, 2},
           {-1.5, 2.7, 3.3, -0.8}};

int main()
{
    Layer_Dense layer1{4, 5};
    Layer_Dense layer2{5, 5};
    Layer_Dense layer3{5, 2};
    layer1.forward(X);
    layer2.forward(layer1.outputs());
    layer3.forward(layer2.outputs());
    layer3.print();

    return 0;
}