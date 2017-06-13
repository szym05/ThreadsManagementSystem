//
// Created by szymon on 10.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H


#include "GeneratePass.h"
#include "TaskPassBruteForce.h"
#include "TaskInterface.h"
#include "JobManagementPass.h"

namespace ThreadsManagementSystemPassBreak {


    class JobManagemetPassBruteForce : virtual public JobManagementPass {

        using TaskInterface = ThreadsManagementSystem::TaskInterface;
    public:
        JobManagemetPassBruteForce(std::unique_ptr<const JobPass> &&job);

        virtual std::unique_ptr< TaskInterface> getTask() override;

        void nothing() override;

    protected:
        std::unique_ptr<GeneratePass> nextTaskGenerator {nullptr};
        const TypeNumberSteps maxNumberSteps = 0;
        TypeLengthPassw currentLengthPassw = 0;
        TypeLengthPassw currentLengthStateTask = 0;


    protected:
        void calculationMaxNumberSteps();
        void intializeCurrentLengthPassw();
        void updateStateJobInGetTask();

        void addSatateTask(std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface> &&stateTask) override;

    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H
