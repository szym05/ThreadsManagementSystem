
#ifndef THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H

#include <memory>
#include "JobInterface.h"
#include "StateJobInterface.h"

namespace ThreadsManagementSystem {

    class JobFactoryInterface {

    public:
        virtual std::unique_ptr<const JobInterface> getJob() = 0;

        virtual void addStateJob(std::unique_ptr<const StateJobInterface> &&stateJob) = 0 ;

        virtual size_t getNumberJob() = 0;

    };

};
#endif //THREADSMANAGEMENTSYSTEM_JOBFACTORYINTERFACE_H
