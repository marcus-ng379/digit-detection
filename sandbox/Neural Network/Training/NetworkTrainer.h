#ifndef NETWORKTRAINER_H
#define NETWORKTRAINER_H
#include "Batch.h"
#include "NetworkEvaluator.h"
#include "NetworkSettings.h"

class NetworkTrainer {
    private:
        DatasetHandling data_helper;
        NetworkEvaluator evaluator;
        float training_split;
        NetworkSettings* network_settings;

        DataPoint** all_data;
        int all_data_length;
        DataPoint** training_data;
        int trainin_data_length;
        DataPoint** validation_data;
        int validation_data_length;
        Batch** training_batches;
        int num_training_batches;

        double current_learn_rate;
        bool data_loaded;
        int epoch;
    public:
        NetworkTrainer();
        void StartTrainingSession(int num_epochs);
        void LoadData();

        //Network trainer testing functions
        void _set_data(DataPoint** data, int data_length);
};

#endif