//
// Created by szymon on 09.06.17.
//

#include "GeneratePass.h"

size_t ThreadsManagementSystemPassBreak::GeneratePass::size() {
    return nextPass.size();
}

size_t ThreadsManagementSystemPassBreak::GeneratePass::operator[](long long i) {
    if(i > 0 && i < nextPass.size())
    {
        return nextPass[i];
    }
    return 0;
}

ThreadsManagementSystemPassBreak::GeneratePass &ThreadsManagementSystemPassBreak::GeneratePass::operator++() {

    size_t index = 0;

    while(true){
        if(nextPass[index] < (sizeAlphabet-1))
        {
            ++nextPass[index];
            break;
        }
        else{
            nextPass[index] = 0;
            ++index;
        }
    }

    ++numberStepsExecuted;

    return *this;
}

void ThreadsManagementSystemPassBreak::GeneratePass::next(size_t n) {
    for(size_t i = 0; i < n; ++i){
        this->operator++();
    }
}

void ThreadsManagementSystemPassBreak::GeneratePass::initializeNextPass() {
    for(auto it = nextPass.begin(); it != nextPass.end(); ++it){
        *it = 0;
    }
}


bool ThreadsManagementSystemPassBreak::GeneratePass::next() {
    return numberStepsExecuted < numberStepsMax;
}


ThreadsManagementSystemPassBreak::GeneratePass::GeneratePass(TypeNumberSteps numberSteps, size_t sizeAlphabet)
        : numberStepsMax(numberSteps), sizeAlphabet(sizeAlphabet) {}
