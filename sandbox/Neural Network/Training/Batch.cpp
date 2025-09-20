#include "Batch.h"

Batch::Batch(DataPoint** data) {
    this->data = data;
}

DataPoint** Batch::get_data() {
    return this->data;
}