#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H
#include "ActivationType.h"

class Activations {
    public:
        virtual double Activate(double* inputs, int inputs_length, int index);
        virtual double Der(double* inputs, int inputs_length, int index);
        virtual ActivationType GetType();
};

#endif