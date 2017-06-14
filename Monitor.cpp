//
// Created by szymon on 13.06.17.
//

#include "Monitor.h"


void SystemMonitoring::Monitor::addMonitoredObjectParameter(const std::string nameThread, const std::string nameObject, std::unique_ptr<const MonitorObject> &&parametr) {

    mapMonitoringObjects[nameThread].addMonitoredObjectParameter(nameObject, std::move(parametr));

}

void SystemMonitoring::Monitor::display(size_t &row) {
    for(std::unordered_map<std::string, MonitorThread>::iterator it = mapMonitoringObjects.begin();
    it != mapMonitoringObjects.end(); ++it){
        SystemMonitoring::NcursesWrapper::TextView(row, 0, "Thread", it->first);
        ++row;
        it->second.display(row);
    }
}


void SystemMonitoring::Monitor::run() {
    size_t row = 0;
    while (tRunning){
        row = 0;
        display(row);
        while(connect->getNumberStateJob() > 0){
            auto stateJob = connect->getStateJob();
            NcursesWrapper::TextView(row, 0 , "State Job",stateJob->toString() + "         ");
            NcursesWrapper::ProgressBar(row+1, 0, stateJob->getProgress());
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        std::this_thread::sleep_for (std::chrono::seconds(1));
    }
}

SystemMonitoring::Monitor::Monitor(const std::shared_ptr<ThreadsManagementSystemPassBreak::ConnectionApiPass> &connect)
        : connect(connect) {}
