#include "Layer.h"
#include "Sigmoid.h"
#include <cstdlib>
#include <utility>

Layer::Layer(int num_input_nodes, int num_output_nodes) {
    this->num_input_nodes = num_input_nodes;
    this->num_output_nodes = num_output_nodes;
    this->activation = new Sigmoid();

    this->len_weights = num_input_nodes * num_output_nodes;
    this->len_biases = num_output_nodes;
    this->weights = new double[this->len_weights];
    this->cost_gradient_w = new double[this->len_weights];
    this->biases = new double[this->len_biases];
    this->cost_gradient_b = new double[this->len_biases];

    this->weight_vels = new double[this->len_weights];
    this->bias_vels = new double[this->len_biases];

    this->init_random_weights();
}

//Encapsulation Methods
int Layer::get_num_input_nodes() {
    return this->num_input_nodes;
}
        
int Layer::get_num_output_nodes() {
    return this->num_output_nodes;
}
        
void Layer::set_activation(Activations* activation) {
    this->activation = activation;
}
        
double Layer::get_weight(int input_node, int output_node) {
    int flat_index = output_node * this->num_input_nodes + input_node;
    return this->weights[flat_index];
}

int Layer::get_flat_weight_index(int input_node_index, int output_node_index) {
    return output_node_index * this->num_input_nodes + input_node_index;
}

// Initialization with random values
void Layer::init_random_weights() {

    for (int i = 0; i < this->len_weights; i++) {
        // For now, all weights are initialized with a random value between -3 and 3
        weights[i] = -3.0 + static_cast<double>(rand() / RAND_MAX * 6);
    }
}

// Calculate Output of the layer
double* Layer::Output(double* inputs) {
    double* weighted_inputs = new double[this->num_output_nodes];

    for (int output_node = 0; output_node < this->num_output_nodes; output_node++) {
        double weighted_input = this->biases[output_node];

        for (int input_node = 0; input_node < this->num_input_nodes; input_node++) {
            weighted_input += inputs[input_node] * this->get_weight(input_node, output_node);
        }
        weighted_inputs[output_node] = weighted_input;
    }

    double* activated = new double[this->num_output_nodes];
    for (int output_node = 0; output_node < this->num_output_nodes; output_node++) {
        activated[output_node] = this->activation->Activate(weighted_inputs, this->num_output_nodes, output_node);
    }

    return activated;
}
        
std::pair<double*, int> Layer::Output(double* inputs, int inputs_length, LayerLearningData* learn_data) {
    learn_data->set_inputs(inputs);

    for (int output_node = 0; output_node < this->num_output_nodes; output_node++) {
        double weighted_input = this->biases[output_node];

        for (int input_node = 0; input_node < this->num_input_nodes; input_node++) {
            weighted_input += inputs[input_node] * this->get_weight(input_node, output_node);
        }
        learn_data->set_weighted_inputs(output_node, weighted_input);
    }

    for (int output_node = 0; output_node < learn_data->get_size(); output_node++) {
        learn_data->set_activations(output_node, this->activation->Activate(learn_data->get_weighted_inputs(), this->num_output_nodes, output_node));
    }

    return std::make_pair(learn_data->get_activations(), learn_data->get_size());
}

// Apply previously calculated gradients, updating weights and biases, and resetting the gradients
void Layer::ApplyGradients(double learn_rate, double regularization, double momentum) {
    double weight_decay = 1.0 - regularization * learn_rate;

    for (int i = 0; i < this->len_weights; i++) {
        double weight = this->weights[i];
        double velocity = this->weight_vels[i] * momentum - this->cost_gradient_w[i] * learn_rate;
        this->weight_vels[i] = velocity;
        this->weights[i] = weight * weight_decay + velocity;
        this->cost_gradient_w[i] = 0;
    }

    for (int i = 0; i < this->len_biases; i++) {
        double velocity = this->bias_vels[i] * momentum - this->cost_gradient_b[i] * learn_rate;
        this->bias_vels[i] = velocity;
        this->biases[i] += velocity;
        this->cost_gradient_b[i] = 0;
    }
}

// Calculates node values for the output layer -> the partial derivative of the cost with respect to weighted input
void Layer::OutputLayerNodeValues(LayerLearningData* learn_data, double* expected_outputs, Costs* cost) {
    for (int i = 0; i < learn_data->get_size(); i++) {
        // Partial Derivatives for the current node: cost/activation and activation/weighted_input
        double cost_derivative = cost->Der(learn_data->get_activations()[i], expected_outputs[i]);
        double activation_derivative = this->activation->Der(learn_data->get_weighted_inputs(), learn_data->get_size(), i);
        learn_data->set_node_values(i, cost_derivative * activation_derivative);
    }
}

// Calculates node values for the hidden layers, same thing as above
void Layer::HiddenLayerNodeValues(LayerLearningData* learn_data, Layer* old_layer, double* old_node_values, int len_old_node_values) {
    for (int new_node_index = 0; new_node_index < this->num_output_nodes; new_node_index++) {
        double new_node_value = 0.0;
        for (int old_node_index = 0; old_node_index < len_old_node_values; old_node_index++) {
            // Partial Derivative of the weighted input with respect to the input
            double weighted_input_derivative = old_layer->get_weight(new_node_index, old_node_index);
            new_node_value += weighted_input_derivative * old_node_values[old_node_index];
        }
        new_node_value *= this->activation->Der(learn_data->get_weighted_inputs(), learn_data->get_size(), new_node_index);
        learn_data->set_node_values(new_node_index, new_node_value);
    }
}

// Update Gradients
void Layer::UpdateGradients(LayerLearningData* learn_data) {
    for (int output_node = 0; output_node < this->num_output_nodes; output_node++) {
        double node_value = learn_data->get_node_values(output_node);
        for (int input_node = 0; input_node < this->num_input_nodes; input_node++) {
            // Partial Derivative of cost/weight of current connection
            double derivativeCost_Weight = learn_data->get_inputs(input_node) * node_value;
            // cost_gradient_w stores these partial derivatives for each weight
            // NOTE: Gradient is added instead of set to calculate average gradient for the batch
            this->cost_gradient_w[this->get_flat_weight_index(input_node, output_node)] += derivativeCost_Weight;
        }
    }

    for (int output_node = 0; output_node < this->num_output_nodes; output_node++) {
        // Partial Derivative of cost/bias
        double derivativeCost_Bias = 1.0 * learn_data->get_node_values(output_node);
        this->cost_gradient_b[output_node] += derivativeCost_Bias;
    }
}