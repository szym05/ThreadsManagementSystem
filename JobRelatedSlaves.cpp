//
// Created by szymon on 10.06.17.
//

#include "JobRelatedSlaves.h"
namespace ThreadsManagementSystem {

    TypeNumberSlave JobRelatedSlaves::numberSlaveExecuteTaskWithJob(TypeIdJob idJob) {
        std::unique_lock<std::mutex> mlock(mut);

        std::unordered_map<TypeIdJob,SlaveRelatedTasks>::iterator it;
        if((it=jobRelatedSlaves.find(idJob)) != jobRelatedSlaves.end()){
            return it->second.size();
        }
        return 0;
    }

    void JobRelatedSlaves::addSlaveToJob(TypeIdJob idJob, TypeIdTask idTask, TypeIdSlave slave) {
        std::unique_lock<std::mutex> mlock(mut);
        jobRelatedSlaves[idJob].addTaskToSlave(idTask, slave);

        if(jobTimeComputeTask.find(idJob) == jobTimeComputeTask.end()) {
            jobTimeComputeTask[idJob] = false;
            jobTimeTask[idJob] = 0.0;
        }


        if (jobTimeComputeTask[idJob] != true) {
            jobTimeComputeTask[idJob] = true;
            jobTimeStartTask[idJob] = std::chrono::steady_clock::now();
            jobSlaveTime[idJob] = slave;
        }

    }

    void JobRelatedSlaves::removeSlaveFromJob(TypeIdJob idJob,TypeIdTask idTask, TypeIdSlave slave) {
        std::unique_lock<std::mutex> mlock(mut);
        std::unordered_map<TypeIdJob,SlaveRelatedTasks>::iterator it;
        if((it=jobRelatedSlaves.find(idJob)) != jobRelatedSlaves.end()){
            if(it->second.size() == 1)
            {
                remove(idJob);
            }
            else {
                it->second.removeSlaveFromTask(idTask, slave);
            }
            if((jobTimeComputeTask[idJob] == true) && (jobSlaveTime[idJob] == slave) ){
                computeTimeForJobTask(idJob);
                jobTimeComputeTask[idJob] = false;
            }
        }
    }

    void JobRelatedSlaves::removeAll(TypeIdJob idJob) {
        std::unique_lock<std::mutex> mlock(mut);
        remove(idJob);

    }

    std::shared_ptr<std::list<TypeIdSlave>> JobRelatedSlaves::getListJobRelatedSlaves(TypeIdJob idJob) {
        std::unique_lock<std::mutex> mlock(mut);
        return jobRelatedSlaves[idJob].getListJobRelatedSlaves();
    }


    TypeIdSlave JobRelatedSlaves::getSlaveFromJobTask(TypeIdJob idJob, TypeIdTask idTask) {
        std::unique_lock<std::mutex> mlock(mut);
        std::unordered_map<TypeIdJob,SlaveRelatedTasks>::iterator it;
        if((it=jobRelatedSlaves.find(idJob)) != jobRelatedSlaves.end()){
            return it->second.getSlaveFromTask(idTask);
        }
        return std::numeric_limits<TypeIdSlave>::max();
    }




    double JobRelatedSlaves::getTimeTaskExecute(TypeIdJob idJob) {
        std::unique_lock<std::mutex> mlock(mut);
        if(jobTimeTask.find(idJob) == jobTimeTask.end()){
            return 0.0;
        }
        return jobTimeTask[idJob];
    }



    ///PROTECTED


    void JobRelatedSlaves::computeTimeForJobTask(TypeIdJob idJob) {
        const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        double elapsed_seconds =  std::chrono::duration_cast<
                std::chrono::duration<double> >(end - jobTimeStartTask[idJob]).count();

        jobTimeTask[idJob] = elapsed_seconds;
    }


    void JobRelatedSlaves::remove(TypeIdJob idJob){
        jobRelatedSlaves.erase(idJob);
        jobTimeStartTask.erase(idJob);
        jobTimeComputeTask.erase(idJob);
        jobSlaveTime.erase(idJob);
        jobTimeTask.erase(idJob);
    }



    ////////
}