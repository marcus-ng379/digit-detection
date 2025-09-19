#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int* layer_sizes) {
    this->layer_sizes = layer_sizes;
    
}
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