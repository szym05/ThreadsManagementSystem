//
// Created by szymon on 09.06.17.
//

#include <iostream>
#include "JobManagementPass.h"



void ThreadsManagementSystemPassBreak::JobManagementPass::setTimeForStartInStateJob() {
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    double elapsed_seconds =  std::chrono::duration_cast<
            std::chrono::duration<double> >(end - start).count();
    stateJob.setTimeReal(elapsed_seconds);
}

void ThreadsManagementSystemPassBreak::JobManagementPass::noHaveTask() {
    haveTasks = false;
}

void ThreadsManagementSystemPassBreak::JobManagementPass::setTimeToEnd(double tasksToEnd) {
    stateJob.setTimeEnd(tasksToEnd * timeExcuteTask);
}

void ThreadsManagementSystemPassBreak::JobManagementPass::setTimeExcuteTask(double timeExcuteTask) {
    this->timeExcuteTask = timeExcuteTask;

}

void ThreadsManagementSystemPassBreak::JobManagementPass::haveState() {
    haveStateJob = true;
}



void ThreadsManagementSystemPassBreak::JobManagementPass::haveMessageF() {
    haveMessage = true;
}

void ThreadsManagementSystemPassBreak::JobManagementPass::noHaveMessageF() {
    haveMessage = false;
}


///////OVERRIDE

bool ThreadsManagementSystemPassBreak::JobManagementPass::isSolutions() {
    return haveSolution;
}

bool ThreadsManagementSystemPassBreak::JobManagementPass::isTask() {
    return haveTasks;
}

bool ThreadsManagementSystemPassBreak::JobManagementPass::isState() {
    return haveStateJob;
}


void ThreadsManagementSystemPassBreak::JobManagementPass::addSatateTask(
        std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface> && stateTask) {

    if(stateTask->getState() == TypeStateTask::solution) {
        const StateTaskPass* stateTaspPtr = dynamic_cast<const StateTaskPass*>(stateTask.release());
        if(stateTaspPtr != nullptr) {
            std::cout << "\n\n JobManagement Reciv solution => " << stateTaspPtr->getSolution() << "\n\n" ;

            std::unique_ptr<const StateTaskPass> stateTask_P{stateTaspPtr};
            noHaveTask();
            haveState();
            haveSolution = true;
            stateJob.setProgress(1.0);
            stateJob.setTimeEnd(0.0);
            stateJob.setSolution(stateTask_P->getSolution());
            haveMessageF();
        }
        else{
            std::cout << " \n\n JobManagementPass error bad cast in function addSatateTask \n\n ";
        }
    } else if(stateTask->getState() == TypeStateTask::state){
        ++numberTaskExecuted;
    }
}

bool ThreadsManagementSystemPassBreak::JobManagementPass::isMessage() {
    return haveMessage;
}


std::unique_ptr<const ThreadsManagementSystem::MessageInterface>
ThreadsManagementSystemPassBreak::JobManagementPass::getMessage() {
    noHaveMessageF();
    return std::make_unique<const MessageInterface>(message);
}



std::unique_ptr<const ThreadsManagementSystem::StateJobInterface>
ThreadsManagementSystemPassBreak::JobManagementPass::getState() {
    return std::make_unique<const StateJobPass>(stateJob);
}




TypeIdJob ThreadsManagementSystemPassBreak::JobManagementPass::getIdJob() {
    return job->getId();
}

ThreadsManagementSystemPassBreak::JobManagementPass::JobManagementPass(
         std::unique_ptr<const JobPass> &&job) : JobManagementInterface(), job(std::move(job))
{
    stateJob.setIdJob(this->job->getId());
    message.setIdJob(this->job->getId());
}

void ThreadsManagementSystemPassBreak::JobManagementPass::noHaveSate() {
    haveStateJob = false;
}

bool ThreadsManagementSystemPassBreak::JobManagementPass::hasExecuted() {
    if(isTask() == false) {
        if(numberTaskExecuted == numberTaskSend){
            return true;
        }
    }
    return false;
}

