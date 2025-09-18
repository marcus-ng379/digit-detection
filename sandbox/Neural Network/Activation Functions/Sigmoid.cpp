#include "Sigmoid.h"
#include <cmath>

double Sigmoid::Activate(double* inputs, int inputs_length, int index) {
    return 1.0 / (1 + std::exp(-inputs[index]));
}

double Sigmoid::Der(double* inputs, int inputs_length, int index) {
    double a = Activate(inputs, inputs_length, index);
    return a * (1 - a);
}

ActivationType Sigmoid::GetType() {
    return ActivationType::Sigmoid;
}