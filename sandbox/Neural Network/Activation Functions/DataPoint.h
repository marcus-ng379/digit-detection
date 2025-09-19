#ifndef DATAPOINT_H
#define DATAPOINT_H

class DataPoint {
    private:
        double* inputs;
        double* expected_outputs;
        int label;
    public:
        DataPoint(double* inputs, int label, int num_labels);
        double* CreateOneHot(int index, int num);
};

#endif