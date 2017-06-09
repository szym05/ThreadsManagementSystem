
#ifndef THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H
#define THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H

#include "TaskInterface.h"
#include "StateJobInterface.h"
#include "StateTaskInterface.h"


namespace ThreadsManagementSystem {

    class SlaveManagementInterface {
    public:
        virtual void addTask(std::unique_ptr<TaskInterface> task) = 0;

        virtual void addMessage(std::unique_ptr<MessageInterface> message) = 0;

        virtual std::unique_ptr<StateTaskInterface> getStateTask(TypeIdJob idJob, TypeIdTask idTask) = 0;

        virtual std::unique_ptr<StateTaskInterface> getSolution() = 0;

    };
}
#endif //THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H
