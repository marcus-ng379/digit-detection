#include "DataPoint.h"

DataPoint::DataPoint(double* inputs, int inputs_length, int label, int num_labels) {
    this->inputs = inputs;
    this->inputs_length = inputs_length;
    this->label = label;
    this->expected_outputs = this->CreateOneHot(label, num_labels);
}

double* DataPoint::get_inputs() {
    return this->inputs;
}

int DataPoint::get_inputs_length() {
    return this->inputs_length;
}

double* DataPoint::get_expected_outputs() {
    return this->expected_outputs;
}

double* DataPoint::CreateOneHot(int index, int num) {
    double* one_hot = new double[num];
    one_hot[index] = 1;
    return one_hot;
}