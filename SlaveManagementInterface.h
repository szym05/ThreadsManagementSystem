
#ifndef THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H
#define THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H

#include "TaskInterface.h"
#include "StateJobInterface.h"
#include "StateTaskInterface.h"
#include "ThreadInterface.h"
#include <functional>

namespace ThreadsManagementSystem {

    class SlaveManagementInterface : public ThreadInterface {
    public:
        virtual void addTask(std::unique_ptr<TaskInterface> &&task) = 0;

        virtual void addMessage(std::unique_ptr<MessageInterface> &&message) = 0;

        virtual std::unique_ptr<const StateTaskInterface> getStateTask(TypeIdJob idJob, TypeIdTask idTask) = 0;

        virtual std::unique_ptr<const StateTaskInterface> getStateTask() = 0;

        virtual TypeNumberSlave getNumberSlave() = 0;

        virtual TypeNumberSlave getNumberAvaibleSlaves() = 0;

        virtual  double getTimeTaskExecute(TypeIdJob idJob) = 0;

    public:

        virtual void addStateTask(std::unique_ptr<StateTaskInterface> &&stateTask) = 0;

        virtual void addSlaveToAvailable( TypeIdSlave idSlave, TypeIdJob idJob, TypeIdTask idTask) = 0;

        virtual void registerSlave(TypeIdSlave slave) = 0;

    };
}
#endif //THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENTINTERFACE_H_H
