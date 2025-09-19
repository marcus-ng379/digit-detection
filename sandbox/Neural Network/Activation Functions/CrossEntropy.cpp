#include "CrossEntropy.h"
#include <cmath>

double CrossEntropy::Output(double* traversed_outputs, double* expected_outputs, int outputs_length) {
    double cost = 0;
    for (int i = 0; i < outputs_length; i++) {
        double x = traversed_outputs[i]; 
        double y = expected_outputs[i];
        double v = (y == 1.0)? -std::log10(x) : -std::log10(1 - x);
        cost += std::isnan(v)? 0 : v;
    }
    return cost;
}
        
double CrossEntropy::Der(double traversed_outputs, double expected_outputs) {
    double x = traversed_outputs;
    double y = expected_outputs;
    if (x == 0.0 || x == 1.0) {
        return 0;
    }
    return (-x + y) / (x * (x - 1));
}
        
CostType CrossEntropy::GetType() {
    return CostType::crossEntropy;
}