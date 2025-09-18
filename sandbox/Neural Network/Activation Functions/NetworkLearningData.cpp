#include "NetworkLearningData.h"

NetworkLearningData::NetworkLearningData(Layer** layer, int num_layers) {
    this->layer_data = new LayerLearningData*[num_layers];
    for (int i = 0; i < num_layers; i++) {
        this->layer_data[i] = new LayerLearningData(layer[i]);
    }
}