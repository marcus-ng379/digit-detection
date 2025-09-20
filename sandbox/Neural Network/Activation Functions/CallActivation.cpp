#include "CallActivation.h"
#include "Sigmoid.h"
#include "ReLU.h"
#include "Softmax.h"

CallActivation::CallActivation(ActivationType activation) {
    this->set_activation(activation);
}

Activations* CallActivation::get_activation() {
    return this->activation;
}

void CallActivation::set_activation(ActivationType activation) {
    switch (activation) {
        case sigmoid:
            this->activation = new Sigmoid();
        case relu:
            this->activation = new ReLU();
        case softmax:
            this->activation = new Softmax();
        default:
            this->activation = new Sigmoid();
    }
}

CallActivation::~CallActivation() {
    delete[] this->activation;
}