//
// Created by szymon on 09.06.17.
//

#include "TaskPassBruteForce.h"

std::unique_ptr<ThreadsManagementSystem::StateTaskInterface>
ThreadsManagementSystemPassBreak::TaskPassBruteForce::getStateTask() {
    std::lock_guard<std::mutex> lck{mBlock};
    return new StateTaskPass(idJob, idTask, TypeStateTask::state, solution, numberStepsExecuted);
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

    TypeHash hash_TMP;
    TypeSolution solutionTmp;

   while(tRunning && nextPass->next())
   {
       solutionTmp = empty_TypeSolution;
       for(size_t i = 0; i < nextPass->size(); ++i){
           solutionTmp += alphabet[nextPass[i]];
       }

       hash_TMP = getHashMethodMD5(solutionTmp);
       lck.lock();
       ++numberStepsExecuted;
       lck.unlock();
       if(hash_TMP == hash){
           lck.lock();
           solution = solutionTmp;
           lck.unlock();
           break;
       }
       ++(*nextPass);
   }
}






ThreadsManagementSystemPassBreak::TaskPassBruteForce::TaskPassBruteForce(TypeIdJob idJob, TypeIdTask idTask,
                                                                         TypeHash typeHash, TypeMethod method,
                                                                         const Hash &hash,
                                                                         std::unique_ptr<const ThreadsManagementSystemPassBreak::Alphabet> &&alphabet)
        : TaskPass(idJob, idTask, typeHash, method, hash, std::move(alphabet)) {

}

