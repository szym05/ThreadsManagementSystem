
#ifndef THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H

#include "ThreadInterface.h"
#include "StateTaskInterface.h"
#include "MessageInterface.h"
#include <memory>
#include "Types.h"

namespace ThreadsManagementSystem {


    class TaskInterface{
    public:
        TaskInterface(TypeIdJob idJob, TypeIdTask idTask) : idJob(idJob), idTask(idTask) {}


        virtual std::unique_ptr<StateTaskInterface> getStateTask() = 0;

        virtual void terminate() = 0;

        virtual void addMessage(std::unique_ptr<MessageInterface> message) = 0;


        virtual int run() = 0;

        virtual bool isRunning() = 0;

        virtual TypeIdJob getIdJob(){
            return idJob;
        };

        virtual TypeIdTask getIdTask(){
            return idTask;
        };

    protected:
        TypeIdJob idJob {empty_TypeIdJob};
        TypeIdTask idTask {empty_TypeIdTask};

    };

}
#endif //THREADSMANAGEMENTSYSTEM_TASKINTERFACE_H
