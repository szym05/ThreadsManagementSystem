

#ifndef THREADSMANAGEMENTSYSTEM_SOLUTION_H
#define THREADSMANAGEMENTSYSTEM_SOLUTION_H

#include "Types.h"
#include <memory>

namespace ThreadsManagementSystem {
    class StateTaskInterface{
    public:
        StateTaskInterface(TypeIdJob idJob, TypeIdTask idTask, TypeStateTask state) : idJob(idJob), idTask(idTask),
                                                                                      state(state) {}

        virtual TypeStateTask getState() const = 0;

        TypeIdJob getIdJob() const {
            return idJob;
        }

        TypeIdTask getIdTask() const {
            return idTask;
        }


    protected:
        TypeIdJob idJob {empty_TypeIdJob};
        TypeIdTask idTask {empty_TypeIdTask};
        TypeStateTask state {TypeStateTask::empty};

    };
}


#endif //THREADSMANAGEMENTSYSTEM_SOLUTION_H
