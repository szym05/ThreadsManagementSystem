

#ifndef THREADSMANAGEMENTSYSTEM_STATEJOBINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_STATEJOBINTERFACE_H

namespace ThreadsManagementSystem {
    class StateJobInterface{
    public:
        StateJobInterface(TypeIdJob idJob) : idJob(idJob) {}

        virtual TypeIdJob getIdJob() = 0;

        void setIdJob(TypeIdJob idJob) {
            StateJobInterface::idJob = idJob;
        }

    protected:
        TypeIdJob idJob {};
    };
}



#endif //THREADSMANAGEMENTSYSTEM_STATEJOBINTERFACE_H
