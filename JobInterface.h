
#ifndef THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H

#include <memory>
#include "JobManagementInterface.h"
#include "TypesPassBreak.h"
#include "Types.h"


namespace ThreadsManagementSystem {

    class JobInterface {
    public:
        JobInterface(TypeIdJob id, TypePriority priority) : id(id), priority(priority) {}

        virtual std::unique_ptr<JobManagementInterface> getJobManagment() = 0;

        TypeIdJob getId() const {
            return id;
        }

        TypePriority getPriority() const {
            return priority;
        }

    protected:
        TypeIdJob id;
        TypePriority priority;
    };

};
#endif //THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H
