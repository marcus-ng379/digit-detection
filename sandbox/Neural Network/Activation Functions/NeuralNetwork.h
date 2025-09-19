#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "Layer.h"
#include "Costs.h"
#include "NetworkLearningData.h"
#include "DataPoint.h"
#include <utility>

class NeuralNetwork {
    private:
        Layer** layers;
        int* layer_sizes;
        Costs* cost;
        NetworkLearningData* batch_learn_data;
    public:
        NeuralNetwork(int* layer_sizes);
        // Neural Network Output
        std::pair<int, double*> Run(double* inputs);
        int max_value_index(double* values);
        double* CalculateOutputs(double* inputs);

        // Learning
        void Learn(DataPoint** training_data, double learn_rate, double regularization = 0.0, double momentum = 0.0);

        // Setting functions
        void set_cost_function(Costs* cost_function);
        void set_activation_function(Activations* activation);
        void set_activation_function(Activations* activation, Activations* output_layer_activation);      
};

#endif