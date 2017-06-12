
#include "JobManagemetPassBruteForce.h"
#include <iostream>
#include <cmath>

void ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::nothing() {

}


void ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::calculationMaxNumberSteps() {
    TypeNumberSteps max = static_cast<TypeNumberSteps>(std::pow(
            job->getAlphabet()->size(),
            job->getMaxLengthPassword()));

    *(const_cast<TypeNumberSteps*>(&maxNumberSteps)) = max;
}



void ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::intializeCurrentLengthPassw() {
    currentLengthPassw = job->getMinLengthPassword();
}



void ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::updateStateJobInGetTask() {
    haveState();

    double tasksToEnd = (double)(maxNumberSteps - stateJob.getNumberExecutedSteps()) / (double) job->getResolutionStepTask();

    setTimeToEnd(tasksToEnd);


    stateJob.addnumberExecutedStep(job->getResolutionStepTask());
    if(stateJob.getNumberExecutedSteps() >= maxNumberSteps){
        stateJob.setNumberExecutedSteps(maxNumberSteps);
        noHaveTask();
        stateJob.setTimeEnd(0.0);
    }


    const double doubMaxNumberSteps = maxNumberSteps + 0.01 * (double)maxNumberSteps;

    double progresss =(double)stateJob.getNumberExecutedSteps()/doubMaxNumberSteps;
    std::cout << "\n\n PROGRES => " << progresss << " MAX STEPS " <<  maxNumberSteps  << "\n\n";
    stateJob.setProgress(progresss);

    if(nextTaskGenerator->size() > currentLengthPassw){
        stateJob.setLengthOfCheckedPasswords(currentLengthPassw);
        currentLengthPassw = (TypeLengthPassw)nextTaskGenerator->size();
    }

    setTimeForStartInStateJob();
}




std::unique_ptr< ThreadsManagementSystem::TaskInterface>
ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::getTask() {
    if(stateJob.getNumberExecutedSteps() >= maxNumberSteps)
    {
        throw std::out_of_range("JobManagment: The NumberStep is out of range the maxNumberSteps");
    }

    auto passwordBeginSearch = std::make_unique<GeneratePass>(*nextTaskGenerator);
    passwordBeginSearch->setNumberStepsExecuted(0);
    passwordBeginSearch->setNumberStepsMax(job->getResolutionStepTask());

    auto alphabetP = std::make_unique<const Alphabet>( *(job->getAlphabet()));

    std::unique_ptr< ThreadsManagementSystem::TaskInterface> task = std::make_unique< TaskPassBruteForce>(
            job->getId(),
            idTask++,
            job->getHashType(),
            job->getMethod(),
            job->getHash(),
            std::move(alphabetP),
            std::move(passwordBeginSearch)
            );

    nextTaskGenerator->next(job->getResolutionStepTask() + 1);

    updateStateJobInGetTask();

    ++numberTaskSend;

    return task;
}

ThreadsManagementSystemPassBreak::JobManagemetPassBruteForce::JobManagemetPassBruteForce(
        std::unique_ptr<const ThreadsManagementSystemPassBreak::JobPass> &&job) : JobManagementPass(std::move(job)) {

    calculationMaxNumberSteps();
    intializeCurrentLengthPassw();
    nextTaskGenerator = std::make_unique<GeneratePass>(maxNumberSteps,this->job->getAlphabet()->size());
}

