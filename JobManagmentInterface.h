
#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H

#include <memory>
#include "SynchronizedQueue.h"
#include "TaskInterface.h"
#include "MessageInterface.h"
#include "StateTaskInterface.h"

namespace ThreadsManagementSystem {

    class JobManagmentInterface {
    public:
        virtual bool isTask() = 0;

        virtual std::unique_ptr<TaskInterface> getTask() = 0;

        virtual void addSatateTask(std::unique_ptr<StateTaskInterface> stateTask) = 0;

        virtual bool isMessage() = 0;

        virtual std::unique_ptr<MessageInterface> getMessage() = 0;

        virtual TypeIdJob getIdJob() = 0;
    };

}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H
