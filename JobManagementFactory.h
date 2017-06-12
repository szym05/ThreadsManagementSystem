#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORY_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORY_H

#include "JobManagementFactoryInterface.h"
#include "JobManagemetPassBruteForce.h"
#include "JobPass.h"

namespace ThreadsManagementSystemPassBreak {
    class JobManagementFactory : public ThreadsManagementSystem::JobManagementFactoryInterface {
    public:
        std::shared_ptr<ThreadsManagementSystem::JobManagementInterface>
        getJobManagment(std::unique_ptr<const ThreadsManagementSystem::JobInterface>
        && job)
        const override;

    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTFACTORY_H
