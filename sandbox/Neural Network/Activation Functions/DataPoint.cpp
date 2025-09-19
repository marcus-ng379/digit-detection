#include "DataPoint.h"

DataPoint::DataPoint(double* inputs, int label, int num_labels) {
    this->inputs = inputs;
    this->label = label;
    this->expected_outputs = this->CreateOneHot(label, num_labels);
}

double* DataPoint::CreateOneHot(int index, int num) {
    double* one_hot = new double[num];
    one_hot[index] = 1;
    return one_hot;
}