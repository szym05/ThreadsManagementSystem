//
// Created by szymon on 13.06.17.
//

#include "Monitor.h"


void SystemMonitoring::Monitor::addMonitoredObjectParameter(const std::string nameThread, const std::string nameObject, std::unique_ptr<const MonitorObject> &&parametr) {

    mapMonitoringObjects[nameThread].addMonitoredObjectParameter(nameObject, std::move(parametr));

}
