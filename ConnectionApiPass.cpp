//
// Created by szymon on 10.06.17.
//

#include "ConnectionApiPass.h"

#include <iostream>

void ThreadsManagementSystemPassBreak::ConnectionApiPass::uploadStateJob(
        std::unique_ptr<std::vector<std::unique_ptr<const ThreadsManagementSystem::StateJobInterface>>> &vecStateJob) {

    const StateJobPass* stateJobPass;
    std::unique_ptr<const ThreadsManagementSystem::StateJobInterface> stateJobInter;

   for( auto it = vecStateJob->begin(); it != vecStateJob->end(); ++it){

       stateJobInter = std::move(*it);
       const ThreadsManagementSystem::StateJobInterface * stateJobPtr  =stateJobInter.release();
       stateJobPass = dynamic_cast<const StateJobPass*>(stateJobPtr);

       if(stateJobPass != nullptr)
       {
           std::unique_ptr<const StateJobPass> stateJobpass(stateJobPass);
           stateJobs.push(std::move(stateJobpass));
       }
   }
}

std::unique_ptr<std::vector<std::unique_ptr<const ThreadsManagementSystem::JobInterface>>>
ThreadsManagementSystemPassBreak::ConnectionApiPass::downloadJob() {

    auto vec = std::make_unique<std::vector<std::unique_ptr<const ThreadsManagementSystem::JobInterface>>>(jobs.size());

    for( auto it = vec->begin(); it != vec->end(); ++it){
        *it = jobs.pop();
    }

    return vec;
}


void ThreadsManagementSystemPassBreak::ConnectionApiPass::addJob(
        std::unique_ptr<const ThreadsManagementSystemPassBreak::JobPass>&& job) {    try {
        jobs.push(std::move(job));
    }catch (...){
        std::cout << " \n\n Exception in ConnectionApiPass in addJob ";
        std::exception_ptr p = std::current_exception();
        std::clog <<(p ? p.__cxa_exception_type()->name() : "null") << std::endl;
    }
}

std::unique_ptr<const ThreadsManagementSystemPassBreak::StateJobPass>
ThreadsManagementSystemPassBreak::ConnectionApiPass::getStateJob() {
    std::unique_ptr<const StateJobPass> element {nullptr};
    try {
        if(stateJobs.size() > 0)
            element = std::move(stateJobs.pop());
    }catch(...){
        std::cout << " \n\n Exception in ConnectionApiPass in getStateJob ";
        std::exception_ptr p = std::current_exception();
        std::clog <<(p ? p.__cxa_exception_type()->name() : "null") << std::endl;
    }
    return element;

}


size_t ThreadsManagementSystemPassBreak::ConnectionApiPass::getNumberStateJob() {
    return stateJobs.size();
}
