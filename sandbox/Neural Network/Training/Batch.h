#ifndef BATCH_H
#define BATCH_H
#include "DataPoint.h"

class Batch {
    private:
        DataPoint** data;
    public:
        Batch(DataPoint** data);
        DataPoint** get_data();
};

#endif