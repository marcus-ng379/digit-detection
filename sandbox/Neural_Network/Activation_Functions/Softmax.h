#ifndef SOFTMAX_H
#define SOFTMAX_H
#include "Activations.h"

class Softmax : public Activations {
    public:
        double Activate(double* inputs, int inputs_length, int index);
        double Der(double* inputs, int inputs_length, int index);
        ActivationType GetType();
};

#endif