//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_MONITOR_H
#define THREADSMANAGEMENTSYSTEM_MONITOR_H


#include <unordered_map>
#include <list>
#include "MonitorObject.h"
#include "MonitorThread.h"

namespace SystemMonitoring {

    class Monitor {
    protected:
        std::unordered_map<std::string, MonitorThread> mapMonitoringObjects;

    public:
        void addMonitoredObjectParameter(const std::string nameThread, const std::string nameObject,  std::unique_ptr<const MonitorObject> && parametr);

    };
}


#endif //THREADSMANAGEMENTSYSTEM_MONITOR_H
