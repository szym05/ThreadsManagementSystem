//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_TASKPASSBRUTEFORCE_H
#define THREADSMANAGEMENTSYSTEM_TASKPASSBRUTEFORCE_H

#include "TaskPass.h"
#include "GeneratePass.h"
#include "StateTaskPass.h"

namespace ThreadsManagementSystemPassBreak {
    class TaskPassBruteForce : public TaskPass {
    public:
        TaskPassBruteForce(TypeIdJob idJob, TypeIdTask idTask, TypeHash typeHash, TypeMethod method, const Hash &hash,
                           std::unique_ptr<const Alphabet> &&alphabet);

        std::unique_ptr<ThreadsManagementSystem::StateTaskInterface> getStateTask() override;

        void terminate() override;

        void addMessage(std::unique_ptr<ThreadsManagementSystem::MessageInterface> message) override;

        int run() override;

        bool isRunning() override;

    protected:
        std::mutex mBlock;
        std::atomic_bool tRunning{false};

    protected:
        std::unique_ptr<GeneratePass> nextPass;


        void passBreakMd5();
    };
}

#endif //THREADSMANAGEMENTSYSTEM_TASKPASSBRUTEFORCE_H
