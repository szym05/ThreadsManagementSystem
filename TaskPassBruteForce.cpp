//
// Created by szymon on 09.06.17.
//

#include <iostream>
#include "TaskPassBruteForce.h"

std::unique_ptr<ThreadsManagementSystem::StateTaskInterface>
ThreadsManagementSystemPassBreak::TaskPassBruteForce::getStateTask() {
    std::lock_guard<std::mutex> lck{mBlock};
    return std::make_unique<StateTaskPass>(idJob, idTask, state, solution, numberStepsExecuted);
}

void ThreadsManagementSystemPassBreak::TaskPassBruteForce::terminate() {
    tRunning = false;
}

void ThreadsManagementSystemPassBreak::TaskPassBruteForce::addMessage(
        std::unique_ptr<ThreadsManagementSystem::MessageInterface> message) {

}

int ThreadsManagementSystemPassBreak::TaskPassBruteForce::run() {
    tRunning = true;

    switch(typeHash){
        case TypeHash::md5 :     passBreakMd5();
            break;
    }

    tRunning = false;
    return 0;
}

bool ThreadsManagementSystemPassBreak::TaskPassBruteForce::isRunning() {
    return tRunning;
}

void ThreadsManagementSystemPassBreak::TaskPassBruteForce::passBreakMd5() {
    std::unique_lock<std::mutex> lck{mBlock};
    lck.unlock();

    Hash hash_TMP;
    TypeSolution solutionTmp;
#ifdef DEBUG_SYSTEM_CONSOL
    std::cout << "\n pre nextPass " << nextPass->size() << "size alhabet " << alphabet->size() << " generator " << *nextPass << "\n";
#endif

   while(tRunning && nextPass->next())
   {
       solutionTmp.clear();

       for(size_t i = 0; i < nextPass->size(); ++i){
           char k = (*alphabet)[(*nextPass)[i]];

           solutionTmp.push_back(k);
       }

       hash_TMP = GenerateHashPass::getHashMethodMD5(solutionTmp);
#ifdef DEBUG_SYSTEM_CONSOL
       if(solutionTmp == "asdf"){
           std::cout<<  "\n spultion = " << solutionTmp << " hash " <<hash ;
       }
#endif

       ++numberStepsExecuted;

       if(hash_TMP == hash){
           lck.lock();
#ifdef DEBUG_SYSTEM_CONSOL
           std::cout<<  "\n soultion = " << solutionTmp;
#endif
           solution = solutionTmp;
           state = TypeStateTask ::solution;
           lck.unlock();
           break;
       }
       ++(*nextPass);
   }
}


ThreadsManagementSystemPassBreak::TaskPassBruteForce::TaskPassBruteForce(
        TypeIdJob idJob,
        TypeIdTask idTask,
        TypeHash typeHash,
        TypeMethod method,
        const Hash &hash,
        std::unique_ptr<const ThreadsManagementSystemPassBreak::Alphabet> &&alphabet,
        std::unique_ptr<GeneratePass> &&nextPass)

        : TaskPass(idJob, idTask, typeHash, method, hash, std::move(alphabet)),
nextPass(std::move(nextPass)){

}



TypeNumberSteps ThreadsManagementSystemPassBreak::TaskPassBruteForce::getNumberStepsExecuted(){
    return numberStepsExecuted;
}
