

#ifndef THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENT_H
#define THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENT_H

#include <unordered_map>
#include "SlaveManagementInterface.h"
#include "SynchronizedQueue.h"
#include "TaskInterface.h"
#include "StateTaskInterface.h"
#include "JobRelatedSlaves.h"
#include "MessageInterface.h"
#include "SlaveInterface.h"
#include "Slave.h"
#include "VectorSlaves.h"

namespace ThreadsManagementSystem{

    class SlaveManagement : public ThreadsManagementSystem::SlaveManagementInterface {

    protected:
        void run() override;;
    public:
        void addStateTask(std::unique_ptr<StateTaskInterface> &&stateTask) override;

        void addSlaveToAvailable(TypeIdSlave idSlave, TypeIdJob idJob, TypeIdTask idTask) override;


    public:
        SlaveManagement(TypeNumberSlave numberSlave);

        void addTask(std::unique_ptr<TaskInterface> &&task) override;

        void addMessage(std::unique_ptr<const MessageInterface> &&message) override;

        std::unique_ptr<const StateTaskInterface> getStateTask(TypeIdJob idJob, TypeIdTask idTask) override;

        std::unique_ptr<const StateTaskInterface> getStateTask() override;

        TypeNumberSlave getNumberSlave() override;

        TypeNumberSlave getNumberAvaibleSlaves() override;

        double getTimeTaskExecute(TypeIdJob idJob) override;

        void registerSlave(TypeIdSlave slave) override;

        size_t getNumberStateTask() override;

        TypeNumberSlave getNumberSlaveExecuteJob(TypeIdJob idJob) override;


    protected:
        SynchronizedQueue<TypeIdSlave> availableSlaves;
        JobRelatedSlaves jobRelatedSlaves;

         std::unique_ptr<VectorSlaves> vecSlaves;

        SynchronizedQueue<std::unique_ptr<TaskInterface>> sendTaskQueue;

        SynchronizedQueue<std::unique_ptr<const MessageInterface>> sendMessageInterfaceQueue;
        SynchronizedQueue<std::unique_ptr<const StateTaskInterface>> stateTasks;

    protected:
        void  sendTaskToSlave();
        void  sendMessageToSlave();
        void  messageTerminateAllSlave(TypeIdJob idJob);


    };
}


#endif //THREADSMANAGEMENTSYSTEM_SLAVEMANAGEMENT_H
