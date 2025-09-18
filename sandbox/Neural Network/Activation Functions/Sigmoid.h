#ifndef SIGMOID_H
#define SIGMOID_H
#include "Activations.h"

class Sigmoid : public Activations {
    public:
        Sigmoid();
        double Activate(double* inputs, int inputs_length, int index);
        double Der(double* inputs, int inputs_length, int index);
        ActivationType GetType();
};

#endif