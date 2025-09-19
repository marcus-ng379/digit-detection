#include "MeanSquaredError.h"

double MeanSquaredError::Output(double* traversed_outputs, double* expected_outputs, int outputs_length) {
    double cost = 0;
    for (int i = 0; i < outputs_length; i++) {
        double error = traversed_outputs[i] - expected_outputs[i];
        cost += error * error;
    }
    return 0.5 * cost;
}
        
double MeanSquaredError::Der(double traversed_outputs, double expected_outputs) {
    return traversed_outputs - expected_outputs;
}
        
CostType MeanSquaredError::GetType() {
    return CostType::meanSquaredError;
}