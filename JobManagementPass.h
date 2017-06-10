//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H

#include "JobManagementInterface.h"
#include "JobPass.h"
#include "StateJobPass.h"
#include "StateTaskPass.h"
#include "MessageInterface.h"

namespace ThreadsManagementSystemPassBreak {
    class JobManagementPass : public ThreadsManagementSystem::JobManagementInterface {
        using MessageInterface = ThreadsManagementSystem::MessageInterface;

    public:
        JobManagementPass( std::unique_ptr<const JobPass> &&job);

    protected:
        StateJobPass stateJob = StateJobPass(empty_TypeIdJob);
        MessageInterface message = MessageInterface(all_TypeIdTask, TypeMessage::terminate);
        const std::unique_ptr<const JobPass> job;
        bool haveStateJob = false;
        bool haveTasks = true;
        bool haveMessage = false;
        const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        double timeExcuteTask = 0.0;
        TypeIdTask idTask{first_TypeIdTask};

    protected:

        virtual void setTimeForStartInStateJob();
        virtual void noHaveTask();
        virtual void haveState();
        virtual void noHaveSate();
        virtual void haveMessageF();
        virtual void noHaveMessageF();
        virtual void setTimeToEnd(double tasksToEnd);



        void setTimeExcuteTask(double timeExcuteTask);



        bool isTask() override;

        bool isState() override;

        void addSatateTask(std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface> stateTask) override;

        bool isMessage() override;

        std::unique_ptr<const ThreadsManagementSystem::MessageInterface> getMessage() override;

        std::unique_ptr<const ThreadsManagementSystem::StateJobInterface> getState() override;

        TypeIdJob getIdJob() override;



    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H
