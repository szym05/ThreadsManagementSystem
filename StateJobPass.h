//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_STATEJOBPASS_H
#define THREADSMANAGEMENTSYSTEM_STATEJOBPASS_H

#include "Types.h"
#include "TypesPassBreak.h"
#include "StateJobInterface.h"

namespace ThreadsManagementSystemPassBreak {
    class StateJobPass : public ThreadsManagementSystem::StateJobInterface {
    public:
        ////CONSTRUCTOR
        StateJobPass(TypeIdJob idJob, double progress, double timeEnd, double timeReal, const TypeSolution &solution,
                     TypeNumberSteps numberExecutedSteps, TypeLengthPassw lengthOfCheckedPasswords) :
                StateJobInterface(idJob),
                progress(progress),
                timeEnd(timeEnd),
                timeReal(timeReal),
                solution(solution),
                numberExecutedSteps(numberExecutedSteps),
                lengthOfCheckedPasswords(lengthOfCheckedPasswords) {}

        StateJobPass(TypeIdJob idJob) : StateJobInterface(idJob) {}


        /////////// GETTER

        TypeIdJob getIdJob() override {
            return idJob;
        }


        double getProgress() const {
            return progress;
        }

        double getTimeEnd() const {
            return timeEnd;
        }

        double getTimeReal() const {
            return timeReal;
        }

        const TypeSolution &getSolution() const {
            return solution;
        }

        TypeNumberSteps getNumberExecutedSteps() const {
            return numberExecutedSteps;
        }

        TypeLengthPassw getLengthOfCheckedPasswords() const {
            return lengthOfCheckedPasswords;
        }

        /////////// SETTER
        void setProgress(double progress) {
            StateJobPass::progress = progress;
        }

        void setTimeEnd(double timeEnd) {
            StateJobPass::timeEnd = timeEnd;
        }

        void setTimeReal(double timeReal) {
            StateJobPass::timeReal = timeReal;
        }

        void setSolution(const TypeSolution &solution) {
            StateJobPass::solution = solution;
        }

        void setNumberExecutedSteps(TypeNumberSteps numberExecutedSteps) {
            StateJobPass::numberExecutedSteps = numberExecutedSteps;
        }

        void setLengthOfCheckedPasswords(TypeLengthPassw lengthOfCheckedPasswords) {
            StateJobPass::lengthOfCheckedPasswords = lengthOfCheckedPasswords;
        }

        void addnumberExecutedStep(TypeNumberSteps resolutionSteps){
            numberExecutedSteps += resolutionSteps;
        }


    protected:
        double progress {};
        double timeEnd {};
        double timeReal {};
        TypeSolution solution {empty_TypeSolution};
        TypeNumberSteps numberExecutedSteps {};
        TypeLengthPassw lengthOfCheckedPasswords {};
    };
}
#endif //THREADSMANAGEMENTSYSTEM_STATEJOBPASS_H
