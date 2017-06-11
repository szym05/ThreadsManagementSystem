//
// Created by szymon on 11.06.17.
//
#include <numeric>
#include <limits>
#include "SlaveRelatedTasks.h"


void ThreadsManagementSystem::SlaveRelatedTasks::addTaskToSlave(TypeIdTask idTask, TypeIdSlave idSlave) {
    slaveLists->push_back(idSlave);
    taskRelatedSlave[idTask] = idSlave;
}

std::shared_ptr<std::list<TypeIdSlave>>
ThreadsManagementSystem::SlaveRelatedTasks::getListJobRelatedSlaves() {
    return slaveLists;
}

void ThreadsManagementSystem::SlaveRelatedTasks::removeSlaveFromTask(TypeIdTask idTask, TypeIdSlave idSlave) {
    slaveLists->remove(idSlave);
    taskRelatedSlave.erase(idTask);
}

TypeNumberSlave ThreadsManagementSystem::SlaveRelatedTasks::size() {
    return slaveLists->size();
}

//////CONSTRUCTORS
ThreadsManagementSystem::SlaveRelatedTasks::SlaveRelatedTasks() {
    slaveLists = std::make_shared< std::list<TypeIdSlave> > ();
}


TypeIdSlave ThreadsManagementSystem::SlaveRelatedTasks::getSlaveFromTask(TypeIdTask idTask) {
    std::unordered_map<TypeIdTask ,TypeIdSlave > ::iterator it;
    if((it=taskRelatedSlave.find(idTask)) != taskRelatedSlave.end()){
        return it->second;
    }
    return std::numeric_limits<TypeIdSlave>::max();
}
