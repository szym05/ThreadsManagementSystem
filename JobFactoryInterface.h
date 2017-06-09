
#ifndef THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H

#include <memory>
#include "JobInterface.h"
#include "StateJobInterface.h"

namespace ThreadsManagementSystem {

    class JobFactoryInterface {

    public:
        virtual std::unique_ptr<JobInterface> getJob() = 0;

        virtual void addStateJob(std::unique_ptr<StateJobInterface> stateJob) = 0 ;

    };

};
#endif //THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H
