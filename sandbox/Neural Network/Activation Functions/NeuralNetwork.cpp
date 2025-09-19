#include "NeuralNetwork.h"
#include "MeanSquaredError.h"
#include <utility>
#include <cstdlib>
#include <ctime>
#include <limits>

NeuralNetwork::NeuralNetwork(int* layer_sizes, int num_layers) {
    this->layer_sizes = layer_sizes;
    this->layers_length = num_layers - 1;
    // RNG seed
    srand(static_cast<unsigned int>(time(0)));
    this->layers = new Layer*[this->layers_length];
    for (int i = 0; i < this->layers_length; i++) {
        this->layers[i] = new Layer(layer_sizes[i], layer_sizes[i + 1]);
    }

    this->output_layer_size = layer_sizes[this->layers_length];
    this->cost = new MeanSquaredError();
}
        
// Neural Network Output
        
std::pair<int, double*> NeuralNetwork::Run(double* inputs) {
    double* outputs = this->CalculateOutputs(inputs);
    int neural_network_output = this->max_value_index(outputs);
    return std::make_pair(neural_network_output, outputs);
}
        
int NeuralNetwork::max_value_index(double* values) {
    double max_value = std::numeric_limits<double>::lowest();
    int index = 0;
    for (int i = 0; i < this->output_layer_size; i++) {
        if (values[i] > max_value) {
            max_value = values[i];
            index = i;
        }
    }
    return index;
}
        
double* NeuralNetwork::CalculateOutputs(double* inputs) {
    for (int i = 0; i < this->layers_length; i++) {
        inputs = this->layers[i]->Output(inputs);
    }
    return inputs;
}

// Learning
void NeuralNetwork::Learn(DataPoint** training_data, int training_data_length, double learn_rate, double regularization = 0.0, double momentum = 0.0) {
    void update_gradients(DataPoint* data, NetworkLearningData* learn_data) {
        //Generate outputs from data 
    }

    // LEARN Scripts
    // Initialize batch
    if (this->batch_learn_data == NULL || this->batch_learn_data_length != training_data_length) {
        this->batch_learn_data = new NetworkLearningData*[training_data_length];
        this->batch_learn_data_length = training_data_length;
        for (int i = 0; i < this->batch_learn_data_length; i++) {
            this->batch_learn_data[i] = new NetworkLearningData(this->layers, this->layers_length);
        }
    }

    for (int i = 0; i < training_data_length; i++) {
        update_gradients(training_data[i], batch_learn_data[i]);
    }

    for (int i = 0; i < this->layers_length; i++) {
        layers[i]->ApplyGradients(learn_rate / training_data_length, regularization, momentum);
    }
}

        // Setting functions
        void set_cost_function(Costs* cost_function);
        void set_activation_function(Activations* activation);
        void set_activation_function(Activations* activation, Activations* output_layer_activation);