#include "standard.hpp"
#include <iostream>
#include <vector>
#include "Layer_Dense.hpp"
#include "MyRandom.hpp"

mat_t X = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

int main()
{
    Layer_Dense layer1{4, 5};
    mat_t outputs = layer1.forward(X);

    for (size_t i = 0; i < 20; i++)
    {
        std::cout << MyRandom::rand(0.0, 10.0) << ' ';
    }

    return 0;
}