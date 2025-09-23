#include "neural/Training/Batch.h"

Batch::Batch(DataPoint** data, int data_length) {
    this->data = data;
    this->data_length = data_length;
}

DataPoint** Batch::get_data() {
    return this->data;
}

Batch::~Batch() {
    for (int i = 0; i < this->data_length; i++) {
        delete this->data[i];
    }
    delete[] this->data;
}