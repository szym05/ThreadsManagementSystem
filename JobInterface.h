
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


        JobInterface(const JobInterface & job) {
            id = job.id;
            priority = job.priority;
        }

       virtual TypeIdJob getId()const = 0;

        TypePriority getPriority()const {
            return priority;
        }

    protected:
        TypeIdJob id;
        TypePriority priority;
    };

};
#endif //THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H
