#ifndef SIGMOID_H
#define SIGMOID_H
#include "Activations.h"

class Sigmoid : public Activations {
    public:
        double Activate(double* inputs, int inputs_length, int index);
        double Der(double* inputs, int inputs_length, int index);
        ActivationType GetType();
};

#endif