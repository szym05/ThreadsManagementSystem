
#ifndef THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H

#include "ThreadInterface.h"
#include "StateTaskInterface.h"
#include "TaskInterface.h"

namespace ThreadsManagementSystem {
    class SlaveInterface{
    protected:
        virtual void run() = 0;

    public:

        virtual std::unique_ptr<StateTaskInterface> getStateTask() = 0;

        virtual bool terminate()=0;

        virtual bool start(std::unique_ptr<TaskInterface> &&task) = 0;

        virtual bool isExecutingTask() = 0;
    };
}
#endif //THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H
