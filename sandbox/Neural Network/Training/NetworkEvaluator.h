#ifndef NETWORKEVALUATOR_H
#define NETWORKEVALUATOR_H
#include "EvaluationData.h"
#include "NeuralNetwork.h"
#include "DataPoint.h"

class NetworkEvaluator {
    public:
        static EvaluationData* Evaluate(NeuralNetwork* network, DataPoint** data, int data_length);
};

#endif