//
// Created by szymon on 10.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBRELATEDSLAVES_H
#define THREADSMANAGEMENTSYSTEM_JOBRELATEDSLAVES_H


#include <list>
#include "Types.h"
#include <unordered_map>
#include <mutex>
#include <memory>
#include "SlaveRelatedTasks.h"

namespace ThreadsManagementSystem {
    class JobRelatedSlaves {
        using TypeTime = std::chrono::steady_clock::time_point ;

        std::unordered_map<TypeIdJob,SlaveRelatedTasks> jobRelatedSlaves;

        std::unordered_map<TypeIdJob,TypeTime> jobTimeStartTask;
        std::unordered_map<TypeIdJob,bool> jobTimeComputeTask;
        std::unordered_map<TypeIdJob,TypeIdSlave > jobSlaveTime;
        std::unordered_map<TypeIdJob,double> jobTimeTask;

        void computeTimeForJobTask(TypeIdJob idJob);
        void remove(TypeIdJob idJob);

        std::mutex mut;
    public:
        TypeNumberSlave numberSlaveExecuteTaskWithJob(TypeIdJob idJob);
        void addSlaveToJob(TypeIdJob idJob,  TypeIdTask idTask,  TypeIdSlave slave);
        void removeSlaveFromJob(TypeIdJob idJob, TypeIdTask idTask, TypeIdSlave slave);
        void removeAll(TypeIdJob idJob);
        std::shared_ptr< std::list<TypeIdSlave>> getListJobRelatedSlaves(TypeIdJob idJob);

        TypeIdSlave getSlaveFromJobTask(TypeIdJob idJob,  TypeIdTask idTask);

        double getTimeTaskExecute(TypeIdJob idJob);

    };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBRELATEDSLAVES_H
