//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H

#include "JobManagementInterface.h"
#include "StateJobPass.h"
#include "StateTaskPass.h"
#include "MessageInterface.h"
#include "JobPass.h"

namespace ThreadsManagementSystemPassBreak {


    class JobManagementPass : virtual public ThreadsManagementSystem::JobManagementInterface {
        using MessageInterface = ThreadsManagementSystem::MessageInterface;

    public:
        JobManagementPass( std::unique_ptr<const JobPass> &&job);

        bool isSolutions() override;


    protected:
        StateJobPass stateJob = StateJobPass(empty_TypeIdJob);
        MessageInterface message = MessageInterface(all_TypeIdTask, TypeMessage::terminate);
        const std::unique_ptr<const JobPass> job;
        bool haveStateJob = false;
        bool haveTasks = true;
        bool haveMessage = false;
        bool haveSolution = false;
        bool hasExecutedB = false;
        const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        double timeExcuteTask = 0.0;
        TypeIdTask idTask{first_TypeIdTask};
        TypeNumberSteps numberTaskSend = 0;
        TypeNumberSteps numberTaskExecuted = 0;

    protected:

        virtual void setTimeForStartInStateJob();
        virtual void noHaveTask();
        virtual void haveState();
        virtual void noHaveSate();
        virtual void haveMessageF();
        virtual void noHaveMessageF();
        virtual void setTimeToEnd(double tasksToEnd);



        void setTimeExcuteTask(double timeExcuteTask) override ;



        bool isTask() override;

        bool isState() override;

        void addSatateTask(std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface> &&stateTask) override;

        bool isMessage() override;

        std::unique_ptr<const ThreadsManagementSystem::MessageInterface> getMessage() override;

        std::unique_ptr<const ThreadsManagementSystem::StateJobInterface> getState() override;

        TypeIdJob getIdJob() override;

    public:
        virtual void nothing() = 0;

        bool hasExecuted() override;

    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMENTPASS_H
