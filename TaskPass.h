
#ifndef THREADSMANAGEMENTSYSTEM_TASK_H
#define THREADSMANAGEMENTSYSTEM_TASK_H

#include <mutex>
#include "TaskInterface.h"
#include "TypesPassBreak.h"
#include "Alphabet.h"

namespace ThreadsManagementSystemPassBreak {
    class TaskPass : public ThreadsManagementSystem::TaskInterface {
    public:
          TaskPass(TypeIdJob idJob, TypeIdTask idTask, TypeHash typeHash, TypeMethod method, const Hash &hash,
                  std::unique_ptr<const Alphabet> &&alphabet)
                : TaskInterface(idJob, idTask), typeHash(typeHash),
                                                                    method(method), hash(hash), alphabet(std::move(alphabet)) {}

        virtual TypeIdJob getIdJob(){
            return idJob;
        }

        virtual TypeNumberSteps getNumberStepsExecuted() = 0;

    protected:
        TypeHash typeHash {TypeHash::empty};
        TypeMethod method {TypeMethod::empty};
        Hash hash { empty_Hash };
        std::unique_ptr<const Alphabet> alphabet {nullptr};
        TypeSolution solution{empty_TypeSolution};
        std::atomic<TypeNumberSteps> numberStepsExecuted{};
    };
}


#endif //THREADSMANAGEMENTSYSTEM_TASK_H
