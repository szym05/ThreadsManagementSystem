//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_JOBPASS_H
#define THREADSMANAGEMENTSYSTEM_JOBPASS_H

#include <ostream>
#include "JobInterface.h"
#include "Alphabet.h"


namespace ThreadsManagementSystemPassBreak {

 class JobPass : public  ThreadsManagementSystem::JobInterface{
 public:
     JobPass(
             TypeIdJob id,
             TypePriority priority,
             TypeHash hashType,
             const Hash &hash,
             TypeMethod method,
             std::unique_ptr<Alphabet> &&alphabet,
             TypeLengthPassw minLengthPassword,
             TypeLengthPassw maxLengthPassword,
             TypeNumberSteps resolutionStepTask) :

             JobInterface(id, priority),
             hashType(hashType),
             hash(hash),
             method(method),
             alphabet(std::move(alphabet)),
             minLengthPassword(minLengthPassword),
             maxLengthPassword(maxLengthPassword),
             resolutionStepTask(resolutionStepTask) {}

     JobPass(const JobPass &job) : JobInterface(job) {
         hashType = job.hashType;
         hash = job.hash;
         method = job.method;
         alphabet = std::make_unique<Alphabet>(*(job.alphabet));
         minLengthPassword = job.minLengthPassword;
         maxLengthPassword = job.maxLengthPassword;
         resolutionStepTask = job.resolutionStepTask;
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

     TypeIdJob getId() const override {
         return id;
     }

 protected:
     TypeHash hashType{TypeHash::empty};
     Hash hash{empty_Hash};
     TypeMethod method{TypeMethod ::empty};
     std::unique_ptr<Alphabet> alphabet{};
     TypeLengthPassw minLengthPassword{};
     TypeLengthPassw maxLengthPassword{};
     TypeNumberSteps  resolutionStepTask{};


 public:
     friend std::ostream &operator<<(std::ostream &os, const JobPass &pass)  {
         os <<  " hashType: " << as_integer(pass.hashType)
            << " hash: " << pass.hash << " method: " << as_integer(pass.method) << " alphabet: " << *pass.alphabet
            << " minLengthPassword: " << pass.minLengthPassword << " maxLengthPassword: " << pass.maxLengthPassword
            << " resolutionStepTask: " << pass.resolutionStepTask;
         return os;
     }
 };
}

#endif //THREADSMANAGEMENTSYSTEM_JOBPASS_H
