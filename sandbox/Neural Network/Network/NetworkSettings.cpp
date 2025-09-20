#include "NetworkSettings.h"

NetworkSettings::NetworkSettings() {
    this->activation_type = new CallActivation(relu);
    this->output_activation_type = new CallActivation(softmax);
    this->cost_type = new CallCost(crossEntropy);
    this->initial_learning_rate = 0.05;
    this->learn_rate_decay = 0.075;
    this->mini_batch_size = 32;
    this->momentum = 0.9;
    this->regularization = 0.1;
}

void NetworkSettings::set_layer_sizes(int* layer_sizes) {
    this->layer_sizes = layer_sizes;
}
        
void NetworkSettings::set_num_layers(int num_layers) {
    this->num_layers = num_layers;
}
        
int* NetworkSettings::get_layer_sizes() {
    return this->layer_sizes;
}
        
int NetworkSettings::get_num_layers() {
    return this->num_layers;
}
        
Activations* NetworkSettings::get_activation_type() {
    return this->activation_type->get_activation();
}
        
Activations* NetworkSettings::get_output_activation_type() {
    return this->output_activation_type->get_activation();
}
        
Costs* NetworkSettings::get_cost_type() {
    return this->cost_type->get_activation();
}
        
double NetworkSettings::get_initial_learning_rate() {
    return this->initial_learning_rate;
}
        
double NetworkSettings::get_learn_rate_decay() {
    return this->learn_rate_decay;
}
        
int NetworkSettings::get_mini_batch_size() {
    return this->mini_batch_size;
}
        
double NetworkSettings::get_momentum() {
    return this->momentum;
}
        
double NetworkSettings::get_regularization() {
    return this->regularization;
}