//
// Created by szymon on 10.06.17.
//

#include "JobFactoryPass.h"
#include <iostream>

std::unique_ptr<const JobInterface> ThreadsManagementSystemPassBreak::JobFactoryPass::getJob() {
    std::unique_ptr<const JobInterface> element {nullptr};
    try {
        if(jobsToDo.size() > 0)
            element = std::move(jobsToDo.pop());
    }catch(...){
        std::cout << " \n\n Exception in JobFactoryPass in getJob ";
        std::exception_ptr p = std::current_exception();
        std::clog <<(p ? p.__cxa_exception_type()->name() : "null") << std::endl;
    }
    return element;
}

void ThreadsManagementSystemPassBreak::JobFactoryPass::addStateJob(
        std::unique_ptr<const StateJobInterface> && stateJob) {
    try {
        stateJobsToUpload.push(std::move(stateJob));
    }catch (...){
        std::cout << " \n\n Exception in JobFactoryPass in addJobState ";
        std::exception_ptr p = std::current_exception();
        std::clog <<(p ? p.__cxa_exception_type()->name() : "null") << std::endl;
    }
}

size_t ThreadsManagementSystemPassBreak::JobFactoryPass::getNumberJob() {
    return jobsToDo.size();
}


void ThreadsManagementSystemPassBreak::JobFactoryPass::uploadStateJobs() {
    if (stateJobsToUpload.size() > 0) {
        auto stateJobs = std::make_unique<std::vector<std::unique_ptr<const StateJobInterface>>>(
                stateJobsToUpload.size());

        for (auto it = stateJobs->begin(); it != stateJobs->end(); ++it) {
            *it = std::move(stateJobsToUpload.pop());
        }
        apiConnect->uploadStateJob(stateJobs);
    }
}


void ThreadsManagementSystemPassBreak::JobFactoryPass::downloadJobs() {
    std::unique_ptr<std::vector<std::unique_ptr<const JobInterface>>> jobs = apiConnect->downloadJob();
    if(jobs->size() > 0) {

        for (auto it = jobs->begin(); it != jobs->end(); ++it) {
            jobsToDo.push(std::move(*it));
        }
    }
}


void ThreadsManagementSystemPassBreak::JobFactoryPass::run() {
    while (tRunning){
        downloadJobs();
        uploadStateJobs();

        std::this_thread::sleep_for (std::chrono::seconds(interval));
    }
}

ThreadsManagementSystemPassBreak::JobFactoryPass::JobFactoryPass(
         std::unique_ptr<ConnectionApiInterface> &&apiConnect) : apiConnect(std::move(apiConnect)) {}

