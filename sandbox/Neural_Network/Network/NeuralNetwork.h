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
        int layers_length;
        int* layer_sizes;
        Costs* cost;
        NetworkLearningData** batch_learn_data;
        int batch_learn_data_length;

        int output_layer_size;
    public:
        NeuralNetwork(int* layer_sizes, int num_layers);
        // Neural Network Output
        std::pair<int, double*> Run(double* inputs);
        int max_value_index(double* values);
        double* CalculateOutputs(double* inputs);

        // Learning
        void Learn(DataPoint** training_data, int training_data_length, double learn_rate, double regularization = 0.0, double momentum = 0.0);
        void update_gradients(DataPoint* data, NetworkLearningData* learn_data);

        // Setting functions
        void set_cost_function(Costs* cost_function);
        void set_activation_function(Activations* activation);
        void set_activation_function(Activations* activation, Activations* output_layer_activation);

        ~NeuralNetwork();
};

#endif