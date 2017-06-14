//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_MONITOR_H
#define THREADSMANAGEMENTSYSTEM_MONITOR_H


#include <unordered_map>
#include <list>
#include "MonitorObject.h"
#include "MonitorThread.h"
#include "NcursesWrapper.h"
#include "ThreadInterface.h"
#include "ConnectionApiPass.h"

namespace SystemMonitoring {

    class Monitor : public ThreadsManagementSystem::ThreadInterface {
    protected:
        std::unordered_map<std::string, MonitorThread> mapMonitoringObjects;
        std::shared_ptr<ThreadsManagementSystemPassBreak::ConnectionApiPass> connect;

    public:
        Monitor(const std::shared_ptr<ThreadsManagementSystemPassBreak::ConnectionApiPass> &connect);

    public:
        void addMonitoredObjectParameter(const std::string nameThread, const std::string nameObject,  std::unique_ptr<const MonitorObject> && parametr);

        void display(size_t &row);

    protected:
        void run() override;
    };


}


#endif //THREADSMANAGEMENTSYSTEM_MONITOR_H
