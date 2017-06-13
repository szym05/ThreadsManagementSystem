//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H
#define THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H

#include "MonitorObject.h"
#include <list>
#include <unordered_map>

namespace SystemMonitoring {
    class MonitorThread {
        std::unordered_map<std::string, std::list<std::unique_ptr<const MonitorObject>>> mapMonitoringObjects;

    public:
        void addMonitoredObjectParameter(const std::string nameObject, std::unique_ptr<const MonitorObject> && parametr){
            mapMonitoringObjects[nameObject].push_back(std::move(parametr));
        }

    };
}

#endif //THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H
