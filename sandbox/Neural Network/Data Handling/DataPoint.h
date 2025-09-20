#ifndef DATAPOINT_H
#define DATAPOINT_H

class DataPoint {
    private:
        double* inputs;
        int inputs_length;
        double* expected_outputs;
        int label;
    public:
        DataPoint(double* inputs, int inputs_length, int label, int num_labels);
        double* get_inputs();
        int get_inputs_length();
        double* get_expected_outputs();
        double* CreateOneHot(int index, int num);
};

#endif