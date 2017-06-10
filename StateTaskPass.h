//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_STATETASKPASS_H
#define THREADSMANAGEMENTSYSTEM_STATETASKPASS_H

#include "StateTaskInterface.h"
#include "TypesPassBreak.h"

namespace ThreadsManagementSystemPassBreak {
    class StateTaskPass : public ThreadsManagementSystem::StateTaskInterface {
    public:
        StateTaskPass(TypeIdJob idJob, TypeIdTask idTask, TypeStateTask state, const TypeSolution &solution,
                      TypeNumberSteps numberStepsExecuted) : StateTaskInterface(idJob, idTask, state),
                                                             solution(solution),
                                                             numberStepsExecuted(numberStepsExecuted) {}

        virtual TypeStateTask getState() const {
            return state;
        };

        const TypeSolution &getSolution() const {
            return solution;
        }

        TypeNumberSteps getNumberStepsExecuted() const {
            return numberStepsExecuted;
        }

    protected:
        TypeSolution solution {empty_TypeSolution};
        TypeNumberSteps numberStepsExecuted {};
    };
}


#endif //THREADSMANAGEMENTSYSTEM_STATETASKPASS_H
