#include <iostream>
#include "cnn.h"
#include "fully_connected_layer.h"
#include "convolutional_layer.h"

using namespace nn;

int main(void) {
    cnn nn(0.3, 0.3);
    fully_connected_layer layer(3, 2, new sigmoid_activation());
    nn.add(&layer);

    vec_t a(3, 0.0), t(2, 0.0);

    vec_t inv(32*32, 0);

    std::vector<vec_t> data, train;

    a[0] = 3.0; a[2] = -1.0;
    t[0] = 0.3; t[1] = 0.7;

    data.push_back(a);
    train.push_back(t);

    for (int i = 0; i < 100; i++)
        nn.train(data, train);

    vec_t predicted;
    nn.predict(a, &predicted);


}