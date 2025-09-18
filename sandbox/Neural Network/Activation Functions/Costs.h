#ifndef COSTS_H
#define COSTS_H
#include "CostType.h"

class Costs {
    public:
        virtual double Output(double* traversed_outputs, double* expected_outputs, int outputs_length);
        virtual double Der(double traversed_outputs, double expected_outputs);
        virtual CostType GetType();
};

#endif