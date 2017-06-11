
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

        SlaveInterface(TypeIdSlave id) : id(id) {}

        SlaveInterface() {}

        virtual std::unique_ptr<StateTaskInterface> getStateTask() = 0;

        virtual bool terminate()=0;

        virtual bool start(std::unique_ptr<TaskInterface> &&task) = 0;

        virtual bool isExecutingTask() = 0;

        virtual TypeIdJob getIdJobExecuting() = 0;

        virtual TypeIdTask getIdTaskExecuting() = 0;

        void setId(TypeIdSlave id) {
            SlaveInterface::id = id;
        }

        void setAddStateTask( std::function<void(std::unique_ptr<StateTaskInterface> &&)> addStateTask) {
            SlaveInterface::addStateTask = addStateTask;
        }

        void
        setAddSlaveToAvailable( std::function<void(TypeIdSlave, TypeIdJob, TypeIdTask)> addSlaveToAvailable) {
            SlaveInterface::addSlaveToAvailable = addSlaveToAvailable;
        }

        void registerSlave(  std::function< void ( TypeIdSlave ) > registerSlave){
            registerSlave(id);
        }

    protected:
        TypeIdSlave id{empty_TypeSlave};
        std::function< void (std::unique_ptr<StateTaskInterface> &&) > addStateTask;
        std::function< void ( TypeIdSlave , TypeIdJob , TypeIdTask ) > addSlaveToAvailable;


    };
}
#endif //THREADSMANAGEMENTSYSTEM_SLAVEINTERFACE_H
