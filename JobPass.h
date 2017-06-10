//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBPASS_H

#include "JobInterface.h"
#include "Alphabet.h"

namespace ThreadsManagementSystemPassBreak {
 class JobPass : public  ThreadsManagementSystem::JobInterface{
 public:
     JobPass(TypeIdJob id, TypePriority priority, TypeHash hashType, const Hash &hash, TypeMethod method,
              std::unique_ptr<Alphabet> &&alphabet, TypeLengthPassw minLengthPassword,
             TypeLengthPassw maxLengthPassword, TypeNumberSteps resolutionStepTask) :
             JobInterface(id, priority),
             hashType(hashType),
             hash(hash),
             method(method),
             alphabet(std::move(alphabet)),
             minLengthPassword(minLengthPassword),
             maxLengthPassword(maxLengthPassword),
             resolutionStepTask(resolutionStepTask) {}

     std::unique_ptr<ThreadsManagementSystem::JobManagementInterface> getJobManagment() override {
         return nullptr;
     }

     TypeHash getHashType() const {
         return hashType;
     }

     const Hash &getHash() const {
         return hash;
     }

     TypeMethod getMethod() const {
         return method;
     }

     const std::unique_ptr<Alphabet> &getAlphabet() const {
         return alphabet;
     }

     TypeLengthPassw getMinLengthPassword() const {
         return minLengthPassword;
     }

     TypeLengthPassw getMaxLengthPassword() const {
         return maxLengthPassword;
     }

     TypeNumberSteps getResolutionStepTask() const {
         return resolutionStepTask;
     }

 protected:
     TypeHash hashType{TypeHash::empty};
     Hash hash{empty_Hash};
     TypeMethod method{};
     std::unique_ptr<Alphabet> alphabet{};
     TypeLengthPassw minLengthPassword{};
     TypeLengthPassw maxLengthPassword{};
     TypeNumberSteps  resolutionStepTask{};
 };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBPASS_H
