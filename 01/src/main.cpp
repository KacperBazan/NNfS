#include "standard.hpp"
#include "Layer_Dense.hpp"
#include "spiralData.hpp"
#include "Activation_ReLU.hpp"
#include "Activation_Softmax.hpp"
#include <iostream>
#include <tuple>

int main()
{
    const int samples{100};
    const int classes{3};

    //auto [X,y] = spiralData(100, 3);
    auto data = spiralData(samples, classes);
    auto X = std::get<0>(data);
    auto y = std::get<1>(data);

    Layer_Dense dense1{2, 3};
    Activation_ReLU act1{};

    Layer_Dense dense2{3, classes};
    Activation_Softmax act2{};

    dense1.forward(X);              // X --> d1 layer --> d1.out
    act1.forward(dense1.outputs()); //d1.out --> ReLU --> act1.out

    dense2.forward(act1.outputs()); //act1.out --> d2 layer --> d2.out
    act2.forward(dense2.outputs()); //d2.out --> SoftMax --> act2.out

    act2.print();

    return 0;
}