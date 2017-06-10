//
// Created by szymon on 10.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBFACTORYPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBFACTORYPASS_H

#include "JobFactoryInterface.h"
#include "JobInterface.h"
#include "ThreadInterface.h"
#include "ConnectionApiInterface.h"

using ThreadsManagementSystem::JobInterface;
using ThreadsManagementSystem::SynchronizedQueue;
using ThreadsManagementSystem::StateJobInterface;
using ThreadsManagementSystem::ConnectionApiInterface;

namespace ThreadsManagementSystemPassBreak {
    using ThreadsManagementSystem::JobFactoryInterface;
    using ThreadsManagementSystem::ThreadInterface;
    using ThreadsManagementSystem::ConnectionApiInterface;
    using ThreadsManagementSystem::SynchronizedQueue;

    class JobFactoryPass : public JobFactoryInterface, public ThreadInterface {
        using JobInterface = ThreadsManagementSystem::JobInterface;
        using StateJobInterface =ThreadsManagementSystem::StateJobInterface;

    protected:
        SynchronizedQueue<std::unique_ptr<const JobInterface>> jobsToDo;
        SynchronizedQueue<std::unique_ptr<const StateJobInterface>> stateJobsToUpload;
        std::unique_ptr<ConnectionApiInterface> apiConnect;

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
