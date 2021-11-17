#include "standard.hpp"           //for mat_t, vec_t
#include "Layer_Dense.hpp"        //for Layer_Dense class
#include "spiralData.hpp"         //for spiralData
#include "Activation_ReLU.hpp"    //for Activation_ReLU class
#include "Activation_Softmax.hpp" //for Activation_Softmax class
#include <iostream>               //for std::cout
#include <tuple>                  //for std::get<>

int main()
{
    const int samples{100}; //100 2D points per sample.
    const int classes{3};   //3 samples.

    //auto [X, y] = spiralData(100, 3); // Why the fuck does this give VSCode an intellisense error.
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

    return 0;
}