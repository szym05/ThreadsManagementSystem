
#ifndef THREADSMANAGEMENTSYSTEM_MASTER_H
#define THREADSMANAGEMENTSYSTEM_MASTER_H

#include "MasterInterface.h"
#include "SlaveManagementInterface.h"
#include "JobFactoryInterface.h"
#include "ConnectionApiInterface.h"
#include <unordered_map>
#include <list>
#include "JobManagementFactory.h"

namespace ThreadsManagementSystem {

    class Master : public MasterInterface{
        std::unique_ptr<JobManagementFactoryInterface> jobManagmnetFactory = std::make_unique<ThreadsManagementSystemPassBreak::JobManagementFactory>();

        std::unique_ptr<SlaveManagementInterface> slaveMenagment;
        std::unique_ptr<JobFactoryInterface> dataBaseMenagment;
        std::priority_queue<std::shared_ptr<JobManagementInterface>> jobs;
        std::unordered_map<TypeIdJob ,std::shared_ptr<JobManagementInterface>> jobsWaitSolution;
        std::list<std::shared_ptr<JobManagementInterface>> jobsExecutedWaitSolution;


        void getTaskFromJobManagementAddToSlaveManagment();

        void getTaskFromJobManagement();

        void getJobFromDataBaseMenagment();

        void getSolutionFromSlaveManagment();

        void jobNotHaveSolution();

    protected:
    public:
        Master(std::unique_ptr<ConnectionApiInterface> && connect);

        bool start() override;

        bool stop() override;

    protected:
        void run() override;
    };
}


#endif //THREADSMANAGEMENTSYSTEM_MASTER_H
