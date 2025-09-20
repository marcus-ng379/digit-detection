#include "NetworkEvaluator.h"

EvaluationData* NetworkEvaluator::Evaluate(NeuralNetwork* network, DataPoint** data, int data_length) {
    EvaluationData* eval_data = new EvaluationData(data[0]->get_expected_outputs_length());
    eval_data->set_total(data_length);

    for (int i = 0; i < data_length; i++) {
        double* output = network->CalculateOutputs(data[i]->get_inputs());
        int traversed_label = network->max_value_index(output);

        eval_data->increment_total_per_label(data[i]->get_label());
        if (traversed_label == data[i]->get_label()) {
            eval_data->increment_num_correct_per_label(data[i]->get_label());
            eval_data->increment_num_correct();
        }
        else {
            eval_data->increment_falsely_labelled(data[i]->get_label());
        }
    }

    return eval_data;
}