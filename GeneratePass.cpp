
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
        if(nextPass[index] < baseAlphabet)
        {
            ++nextPass[index];
            break;
        }
        else{
            nextPass[index] = 0;
            ++index;
            if(nextPass.size() <= index){
                nextPass.push_back(1);
                break;
            }
        }
    }

    ++numberStepsExecuted;

    return *this;
}

void ThreadsManagementSystemPassBreak::GeneratePass::next(size_t n) {
    for(size_t i = 0; i < n; ++i){
        ++(*this);
    }
}

void ThreadsManagementSystemPassBreak::GeneratePass::initializeNextPass() {
    for(auto it = nextPass.begin(); it != nextPass.end(); ++it){
        *it = 0;
    }
}

size_t ThreadsManagementSystemPassBreak::GeneratePass::getDigit(long long i) {
    if(i > 0 && i < nextPass.size())
    {
        return nextPass[i];
    }
    return 0;
}


bool ThreadsManagementSystemPassBreak::GeneratePass::next() {
    return numberStepsExecuted < numberStepsMax;
}



///CONSTRUCTORS
ThreadsManagementSystemPassBreak::GeneratePass::GeneratePass(TypeNumberSteps numberSteps, size_t sizeAlphabet)
        : numberStepsMax(numberSteps), baseAlphabet(sizeAlphabet-1) {}



