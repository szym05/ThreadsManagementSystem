
#ifndef THREADSMANAGEMENTSYSTEM_STATETASKPASS_H
#define THREADSMANAGEMENTSYSTEM_STATETASKPASS_H

#include "StateTaskInterface.h"
#include "TypesPassBreak.h"

namespace ThreadsManagementSystemPassBreak {
    class StateTaskPass : public ThreadsManagementSystem::StateTaskInterface {
    public:
        StateTaskPass(TypeIdJob idJob,
                      TypeIdTask idTask,
                      TypeStateTask state,
                      const TypeSolution &solution,
                      TypeNumberSteps numberStepsExecuted,
                      TypeLengthPassw currentLengthPassw)
                :
                StateTaskInterface(
                idJob,
                idTask,
                state),
                solution(solution),
                numberStepsExecuted(numberStepsExecuted),
                currentLengthPassw(currentLengthPassw) {}

        StateTaskPass(TypeStateTask state) : StateTaskInterface(state) {}

        virtual TypeStateTask getState() const {
            return state;
        };

        const TypeSolution &getSolution() const {
            return solution;
        }

        TypeNumberSteps getNumberStepsExecuted() const {
            return numberStepsExecuted;
        }

        TypeLengthPassw getCurrentLengthPassw() const {
            return currentLengthPassw;
        }

    protected:
        TypeSolution solution {empty_TypeSolution};
        TypeNumberSteps numberStepsExecuted {};
        TypeLengthPassw currentLengthPassw {0};
    };
}


#endif //THREADSMANAGEMENTSYSTEM_STATETASKPASS_H
