//
// Created by szymon on 11.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_SLAVERELATEDTASKS_H
#define THREADSMANAGEMENTSYSTEM_SLAVERELATEDTASKS_H

#include "Types.h"
#include <list>
#include <unordered_map>

namespace ThreadsManagementSystem {
    class SlaveRelatedTasks {
    private:
        std::shared_ptr< std::list<TypeIdSlave> > slaveLists{};
        std::unordered_map<TypeIdTask ,TypeIdSlave > taskRelatedSlave;
    public:

        SlaveRelatedTasks();

        void addTaskToSlave(TypeIdTask idTask, TypeIdSlave idSlave);
        std::shared_ptr< std::list<TypeIdSlave>> getListJobRelatedSlaves();
        void removeSlaveFromTask(TypeIdTask idTask, TypeIdSlave idSlave);

        TypeNumberSlave size();

        TypeIdSlave getSlaveFromTask(TypeIdTask idTask);



    };
}

#endif //THREADSMANAGEMENTSYSTEM_SLAVERELATEDTASKS_H
