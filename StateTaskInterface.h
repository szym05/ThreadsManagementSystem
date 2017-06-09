

#ifndef THREADSMANAGEMENTSYSTEM_SOLUTION_H
#define THREADSMANAGEMENTSYSTEM_SOLUTION_H

#include "Types.h"
#include <memory>

namespace ThreadsManagementSystem {
    class StateTaskInterface{
    public:
        TypeStateTask getState() const {
            return state;
        }

        void setState(TypeStateTask state) {
            StateTaskInterface::state = state;
        }

    protected:
        TypeStateTask state = TypeStateTask::empty;

    };
}


#endif //THREADSMANAGEMENTSYSTEM_SOLUTION_H
