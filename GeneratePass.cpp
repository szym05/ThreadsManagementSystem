
#include <iostream>
#include "GeneratePass.h"

size_t ThreadsManagementSystemPassBreak::GeneratePass::size() const{
    return nextPass.size();
}

size_t ThreadsManagementSystemPassBreak::GeneratePass::operator[](long long i)const {
    if(i >= 0 && i < nextPass.size())
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
            if(nextPass.size() == index){
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
    if(i >= 0 && i < nextPass.size())
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


ThreadsManagementSystemPassBreak::GeneratePass::GeneratePass(
        const ThreadsManagementSystemPassBreak::GeneratePass &generatePass) {

    numberStepsMax = generatePass.numberStepsMax;
    numberStepsExecuted = generatePass.numberStepsExecuted;
    nextPass.resize(generatePass.size());
    baseAlphabet = generatePass.baseAlphabet;

    for (int i = 0; i < nextPass.size(); ++i) {
        nextPass[i] = generatePass.nextPass[i];
    }

}

void ThreadsManagementSystemPassBreak::GeneratePass::setNumberStepsMax(TypeNumberSteps numberStepsMax) {
    GeneratePass::numberStepsMax = numberStepsMax;
}

void ThreadsManagementSystemPassBreak::GeneratePass::setNumberStepsExecuted(TypeNumberSteps numberStepsExecuted) {
    GeneratePass::numberStepsExecuted = numberStepsExecuted;
}

std::ostream &ThreadsManagementSystemPassBreak::operator<<(std::ostream &os,
                                                           const ThreadsManagementSystemPassBreak::GeneratePass &pass) {
    os << "numberStepsMax: " << pass.numberStepsMax << " numberStepsExecuted: " << pass.numberStepsExecuted
       << " baseAlphabet: " << pass.baseAlphabet << " nextPass: ";
    for( const size_t & k : pass.nextPass)
         os << k;
    return os;
}
