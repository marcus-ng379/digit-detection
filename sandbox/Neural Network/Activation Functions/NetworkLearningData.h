#ifndef NETWORKLEARINGDATA_H
#define NETWORKLEARNINGDATA_H
#include "LayerLearningData.h"

class NetworkLearningData {
    private:
        LayerLearningData** layer_data;
    public:
        NetworkLearningData(Layer** layer, int num_layers);
        LayerLearningData* get_layer_data(int index);
};

#endif