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
            break;
        case relu:
            this->activation = new ReLU();
            break;
        case softmax:
            this->activation = new Softmax();
            break;
        default:
            this->activation = new Sigmoid();
            break;
    }
}

CallActivation::~CallActivation() {
    delete this->activation;
}