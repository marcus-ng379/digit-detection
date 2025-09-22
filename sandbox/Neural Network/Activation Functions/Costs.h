#ifndef COSTS_H
#define COSTS_H
#include "CostType.h"

class Costs {
    public:
        virtual double Output(double* traversed_outputs, double* expected_outputs, int outputs_length) = 0;
        virtual double Der(double traversed_outputs, double expected_outputs) = 0;
        virtual CostType GetType() = 0;
};

#endif