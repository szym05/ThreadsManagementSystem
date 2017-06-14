//
// Created by szymon on 13.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H
#define THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H

#include "MonitorObject.h"
#include <list>
#include <unordered_map>
#include "NcursesWrapper.h"

namespace SystemMonitoring {
    class MonitorThread {
        std::unordered_map<std::string, std::list<std::unique_ptr<const MonitorObject>>> mapMonitoringObjects;

    public:
        void addMonitoredObjectParameter(const std::string nameObject, std::unique_ptr<const MonitorObject> && parametr){
            mapMonitoringObjects[nameObject].push_back(std::move(parametr));
        }

        void display(size_t &row){
            for (auto it = mapMonitoringObjects.begin(); it != mapMonitoringObjects.end(); ++it ) {
                SystemMonitoring::NcursesWrapper::TextView(row, 0, "Object", it->first);
                ++row;
                for (auto it_2 = it->second.begin(); it_2 != it->second.end(); ++it_2 ) {
                    (*it_2)->display(row);
                }
            }
        }

    };
}

#endif //THREADSMANAGEMENTSYSTEM_MONITORTHREAD_H
