
#ifndef THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H

#include <memory>
#include "JobManagmentInterface.h"

namespace ThreadsManagementSystem {

    class JobInterface {
    public:
        virtual std::unique_ptr<JobManagmentInterface> getJobManagment() = 0;

    };

};
#endif //THREADSMANAGEMENTSYSTEM_JOBINTERFACE_H
