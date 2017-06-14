
#include <iostream>
#include "VectorSlaves.h"


bool ThreadsManagementSystem::VectorSlaves::terminate(TypeIdSlave slave){

    std::unique_lock<std::mutex> lck{mut};
    return (*vecSlaves)[slave].terminate();
}

bool ThreadsManagementSystem::VectorSlaves::isExecutingTask(TypeIdSlave slave) {

    std::lock_guard<std::mutex> lck {mut};
    return (*vecSlaves)[slave].isExecutingTask();
}

bool ThreadsManagementSystem::VectorSlaves::start(TypeIdSlave slave,
                                                  std::unique_ptr<ThreadsManagementSystem::TaskInterface> &&task) {

    std::unique_lock<std::mutex> lck{mut};
    //std::cout<< "\n Start Slave " << slave;
    return (*vecSlaves)[slave].start(std::move(task));
}


std::unique_ptr<ThreadsManagementSystem::StateTaskInterface>
ThreadsManagementSystem::VectorSlaves::getStateTask(TypeIdSlave slave) {

    std::unique_lock<std::mutex> lck{mut};
    return (*vecSlaves)[slave].getStateTask();
}

ThreadsManagementSystem::VectorSlaves::VectorSlaves(TypeNumberSlave numberSlave,  std::function<void(std::unique_ptr<StateTaskInterface> &&)> addStateTask,  std::function<void(TypeIdSlave, TypeIdJob, TypeIdTask)> addSlaveToAvailable, std::function< void ( TypeIdSlave ) > registerSlave) {
    vecSlaves = std::make_unique<  std::vector<Slave> >(numberSlave);

    for(size_t i = 0 ; i < numberSlave; ++i)
    {
        (*vecSlaves)[i].setId(i);
        (*vecSlaves)[i].setAddSlaveToAvailable(addSlaveToAvailable);
        (*vecSlaves)[i].setAddStateTask(addStateTask);
        (*vecSlaves)[i].registerSlave(registerSlave);
    }

}

size_t ThreadsManagementSystem::VectorSlaves::size() {
    return (*vecSlaves).size();
}
