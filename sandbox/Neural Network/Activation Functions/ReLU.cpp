#include "ReLU.h"
#include <algorithm>

double ReLU::Activate(double* inputs, int inputs_length, int index) {
    return std::max(0.0, inputs[index]);
}

double ReLU::Der(double* inputs, int inputs_length, int index) {
    return (inputs[index] > 0)? 1: 0;
}

ActivationType ReLU::GetType() {
    return ActivationType::ReLU;
}