//
// Created by szymon on 10.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H
#define THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H

#include "JobManagementPass.h"
#include "GeneratePass.h"
#include "TaskPassBruteForce.h"
#include "TaskInterface.h"

namespace ThreadsManagementSystemPassBreak {
    class JobManagemetPassBruteForce : public JobManagementPass {

        using TaskInterface = ThreadsManagementSystem::TaskInterface;
    public:
        JobManagemetPassBruteForce(std::unique_ptr<const JobPass> &&job);

        std::unique_ptr<const TaskInterface> getTask() override;

    private:
        std::unique_ptr<GeneratePass> nextTaskGenerator;
        const TypeNumberSteps maxNumberSteps = 0;
        TypeLengthPassw currentLengthPassw {0};


    private:
        void calculationMaxNumberSteps();
        void intializeCurrentLengthPassw();
        void updateStateJobInGetTask();
    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBMANAGEMETPASSBRUTEFORCE_H
