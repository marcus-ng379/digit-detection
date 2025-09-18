#ifndef CALLACTIVATION_H
#define CALLACTIVATION_H
#include "Activations.h"

class CallActivation {
    private:
        Activations* activation;
    public:
        CallActivation(ActivationType activation);
        ~CallActivation();
};

#endif