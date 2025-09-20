#ifndef DATASETHANDLING_H
#define DATASETHANDLING_H
#include "Batch.h"
#include <utility>

// Class for Dataset preparation for training
class DatasetHandling {
    public:
        std::pair<DataPoint**, DataPoint**> SplitData(DataPoint** all_data, int all_data_length, float training_split = 0.75, bool shuffle = true);
        Batch** CreateMiniBatches(DataPoint** all_data, int all_data_length, int size, bool shuffle = true);
        static void ShuffleBatches(Batch** batches, int num_batches);
        static void ShuffleArray(auto** array);
}

#endif