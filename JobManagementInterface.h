
#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H

#include <memory>
#include "SynchronizedQueue.h"
#include "TaskInterface.h"
#include "MessageInterface.h"
#include "StateTaskInterface.h"
#include "StateJobInterface.h"

namespace ThreadsManagementSystem {

    class JobManagementInterface {
    public:
        virtual bool isTask() = 0;

        virtual bool isState() = 0;

        virtual std::unique_ptr<const TaskInterface> getTask() = 0;

        virtual void addSatateTask(std::unique_ptr<const StateTaskInterface> stateTask) = 0;

        virtual bool isMessage() = 0;

        virtual std::unique_ptr<const MessageInterface> getMessage() = 0;

        virtual std::unique_ptr<const StateJobInterface> getState() = 0;

        virtual TypeIdJob getIdJob() = 0;
    };

}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGMENTINTERFACE_H
