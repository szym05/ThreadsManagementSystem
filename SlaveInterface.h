
#ifndef THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H

#include "ThreadInterface.h"
#include "StateTaskInterface.h"
#include "TaskInterface.h"

namespace ThreadsManagementSystem {
    class SlaveInterface{
    protected:
        /*
        *:brief: Function have to be called when the task is complete.
        *:params:
        * 	theEnd -
        *:return: none.
        */
        virtual void theEnd() = 0;

    public:

        virtual std::unique_ptr<StateTaskInterface> getStateTask() = 0;

        virtual void terminate()=0;

        virtual void start(std::unique_ptr<TaskInterface> task) = 0;

        virtual bool isExecutingTask() = 0;
    };
}
#endif //THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H
