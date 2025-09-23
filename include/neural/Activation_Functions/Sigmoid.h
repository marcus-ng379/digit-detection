#ifndef SIGMOID_H
#define SIGMOID_H
#include "neural/Activation_Functions/Activations.h"

class Sigmoid : public Activations {
    public:
        double Activate(double* inputs, int inputs_length, int index);
        double Der(double* inputs, int inputs_length, int index);
        ActivationType GetType();
};

#endif