

#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORYINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORYINTERFACE_H

#include "JobInterface.h"
#include "JobManagementInterface.h"
namespace ThreadsManagementSystem {

    class JobManagementFactoryInterface {
    public:
        virtual std::shared_ptr<JobManagementInterface> getJobManagment(std::unique_ptr<const JobInterface> &&job) const = 0;

    };

}
#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORYINTERFACE_H
