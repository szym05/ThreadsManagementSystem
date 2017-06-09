
#ifndef THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H

#include "ThreadInterface.h"
#include "StateTaskInterface.h"
#include "MessageInterface.h"
#include <memory>

namespace ThreadsManagementSystem {


    class TaskInterface{
    public:
        virtual std::unique_ptr<StateTaskInterface> getStateTask() = 0;

        virtual void terminate() = 0;

        virtual void addMessage(std::unique_ptr<MessageInterface> message) = 0;


        virtual int run() = 0;

        virtual bool isRunning() = 0;
    };

}
#endif //THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H
