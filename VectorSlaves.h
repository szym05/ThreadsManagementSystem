//
// Created by szymon on 11.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_VECTORSLAVES_H
#define THREADSMANAGEMENTSYSTEM_VECTORSLAVES_H

#include <vector>
#include <mutex>
#include "Types.h"
#include "Slave.h"
#include <functional>


namespace ThreadsManagementSystem {
    class VectorSlaves {

    protected:
        std::mutex mut;
         std::unique_ptr<  std::vector<Slave> > vecSlaves;

    public:
        VectorSlaves(
                TypeNumberSlave numberSlave,
                std::function<void(std::unique_ptr<StateTaskInterface> &&)> addStateTask,
                std::function<void(TypeIdSlave, TypeIdJob, TypeIdTask)> addSlaveToAvailable, std::function< void ( TypeIdSlave ) > registerSlave);

        bool terminate(TypeIdSlave slave) ;
        bool isExecutingTask(TypeIdSlave slave);
        bool start(TypeIdSlave slave, std::unique_ptr<TaskInterface> &&task);
        std::unique_ptr<StateTaskInterface> getStateTask(TypeIdSlave slave);

        size_t size();


    };
}

#endif //THREADSMANAGEMENTSYSTEM_VECTORSLAVES_H
