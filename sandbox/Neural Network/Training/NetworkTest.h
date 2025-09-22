#include <iostream>
#include "NetworkTrainer.h"

class NetworkTest {
    public:
        void runTests() {
            testSimpleData();
        }
    private:
        void testSimpleData() {
            {
                NetworkTrainer network_trainer = NetworkTrainer();

                // SAMPLE DATA: If inputs[0] < 0 or inputs[1] > 30, label 1, else label 0
                DataPoint** data = new DataPoint*[100];
                double* inputs = new double[2];
                int label = 0;
                for (int i = 0; i < 100; i++) {
                    for (int j = 0; j < 2; j++) {
                        inputs[j] = (i - 50) * 2.43 * (j + 1) / 1.4;
                    }
                    if (inputs[0] < 0.0 || inputs[1] > 30.0) {
                        label = 1;
                    }
                    else {
                        label = 0;
                    }
                    data[i] = new DataPoint(inputs, 2, label, 2);
                }
                network_trainer._set_data(data, 100);
                network_trainer.LoadData();
                network_trainer.StartTrainingSession(3);
            }
        }
};

