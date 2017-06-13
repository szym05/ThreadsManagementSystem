
#ifndef THREADSMANAGEMENTSYSTEM_JOBFACTORYPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBFACTORYPASS_H

#include "JobFactoryInterface.h"
#include "JobInterface.h"
#include "ThreadInterface.h"
#include "ConnectionApiInterface.h"
#include "Monitor.h"

using ThreadsManagementSystem::JobInterface;
using ThreadsManagementSystem::SynchronizedQueue;
using ThreadsManagementSystem::StateJobInterface;
using ThreadsManagementSystem::ConnectionApiInterface;

namespace ThreadsManagementSystemPassBreak {
    using ThreadsManagementSystem::JobFactoryInterface;
    using ThreadsManagementSystem::ThreadInterface;
    using ThreadsManagementSystem::ConnectionApiInterface;
    using ThreadsManagementSystem::SynchronizedQueue;

    class JobFactoryPass : public JobFactoryInterface {
    public:
        JobFactoryPass( std::shared_ptr<ConnectionApiInterface> &apiConnect, SystemMonitoring::Monitor &monitor);

        using JobInterface = ThreadsManagementSystem::JobInterface;
        using StateJobInterface =ThreadsManagementSystem::StateJobInterface;

    protected:
        SynchronizedQueue<std::unique_ptr<const JobInterface>> jobsToDo;
        SynchronizedQueue<std::unique_ptr<const StateJobInterface>> stateJobsToUpload;
        std::shared_ptr<ConnectionApiInterface> apiConnect;

    public:
        std::unique_ptr<const JobInterface> getJob() override;

        void addStateJob(std::unique_ptr<const StateJobInterface> &&stateJob) override;

        size_t getNumberJob() override;

    protected:
        void run() override;

        void uploadStateJobs();

        void downloadJobs();

    };
}


#endif //THREADSMANAGEMENTSYSTEM_JOBFACTORYPASS_H
