
#include "Slave.h"

std::unique_ptr<ThreadsManagementSystem::StateTaskInterface> ThreadsManagementSystem::Slave::getStateTask() {
    std::lock_guard<std::mutex> lck {mBlockTask};
    if(task != nullptr) {
        return task->getStateTask();
    }

    return nullptr;
}

bool ThreadsManagementSystem::Slave::terminate() {
    std::lock_guard<std::mutex> lck {mBlockTask};
    if(task != nullptr) {
        task->terminate();
        return true;
    }
    return false;
}

bool ThreadsManagementSystem::Slave::start(std::unique_ptr<ThreadsManagementSystem::TaskInterface> &&task) {
    std::unique_lock<std::mutex> lck {mBlockTask};
    if(task != nullptr) {
        this->task = std::move(task);
        waitFinishThread();
        taskWorker = std::make_unique<std::thread>(this->run);
        return true;
    }
    return false;
}

bool ThreadsManagementSystem::Slave::isExecutingTask() {
    std::lock_guard<std::mutex> lck {mBlockTask};
    return task != nullptr;
}

void ThreadsManagementSystem::Slave::run() {
    int state = task->run();
    addStateTask(task->getStateTask());
    task = nullptr;
}

void ThreadsManagementSystem::Slave::waitFinishThread() {
    if(taskWorker != nullptr)
    {
        taskWorker->join();
    }
    taskWorker = nullptr;
}

ThreadsManagementSystem::Slave::~Slave() {
    waitFinishThread();
}
