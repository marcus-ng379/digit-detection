#ifndef RELU_H
#define RELUH
#include "neural/Activation_Functions/Activations.h"

class ReLU : public Activations {
    public:
        double Activate(double* inputs, int inputs_length, int index);
        double Der(double* inputs, int inputs_length, int index);
        ActivationType GetType();
};

#endif