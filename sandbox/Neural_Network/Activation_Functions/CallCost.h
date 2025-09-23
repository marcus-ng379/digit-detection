#ifndef CALLCOST_H
#define CALLCOST_H
#include "Costs.h"

class CallCost {
    private:
        Costs* activation;
    public:
        CallCost(CostType activation);
        Costs* get_activation();
        void set_activation(CostType activation);
        ~CallCost();
};

#endif