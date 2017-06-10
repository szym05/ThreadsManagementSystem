//
// Created by szymon on 10.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_CONNECTIONAPIPASS_H
#define THREADSMANAGEMENTSYSTEM_CONNECTIONAPIPASS_H


#include "ConnectionApiInterface.h"
#include "JobPass.h"
#include "StateJobPass.h"

namespace ThreadsManagementSystemPassBreak {
    using ThreadsManagementSystem::ConnectionApiInterface;
    using ThreadsManagementSystem::SynchronizedQueue;

    class ConnectionApiPass : public ConnectionApiInterface{
    protected:
        SynchronizedQueue<std::unique_ptr<const JobPass>> jobs;
        SynchronizedQueue<std::unique_ptr<const StateJobPass>> stateJobs;

    public:
        void uploadStateJob(
                std::unique_ptr<std::vector<std::unique_ptr<const ThreadsManagementSystem::StateJobInterface>>> &vecStateJob) override;

        std::unique_ptr<std::vector<std::unique_ptr<const ThreadsManagementSystem::JobInterface>>>
        downloadJob() override;

        void addJob(std::unique_ptr<const JobPass> &&job);
        std::unique_ptr<const StateJobPass> getStateJob();
        size_t getNumberStateJob();

    };
}

#endif //THREADSMANAGEMENTSYSTEM_CONNECTIONAPIPASS_H
