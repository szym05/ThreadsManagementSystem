
#ifndef THREADSMANAGEMENTSYSTEM_CONNECTIONAPIINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_CONNECTIONAPIINTERFACE_H

#include "JobInterface.h"
#include "StateJobInterface.h"


namespace ThreadsManagementSystem {
    class ConnectionApiInterface{
    public:
        virtual  void uploadStateJob(std::unique_ptr<std::vector<std::unique_ptr<const StateJobInterface>>> &vecStateJob ) = 0;

        virtual std::unique_ptr<std::vector<std::unique_ptr<const JobInterface>>> downloadJob() = 0;
    };
}
#endif //THREADSMANAGEMENTSYSTEM_CONNECTIONAPIINTERFACE_H
