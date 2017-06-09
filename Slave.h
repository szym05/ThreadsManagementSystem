

#ifndef THREADSMANAGEMENTSYSTEM_SLAVE_H
#define THREADSMANAGEMENTSYSTEM_SLAVE_H

#include "SlaveInterface.h"
#include "TaskInterface.h"
#include "StateTaskInterface.h"
#include <mutex>

namespace ThreadsManagementSystem {
    class Slave : public SlaveInterface{
    public:
        std::unique_ptr<StateTaskInterface> getStateTask() override;

        bool terminate() override;

        bool start(std::unique_ptr<TaskInterface> &&task) override;

        bool isExecutingTask() override;

        virtual ~Slave();

        TypeIdJob getIdJobExecuting() override;

        TypeIdTask getIdTaskExecuting() override;

    protected:
        void run() override;
        void waitFinishThread();

    protected:
        std::mutex mBlockTask;
        std::unique_ptr<TaskInterface> task {nullptr};
        std::unique_ptr<std::thread> taskWorker {nullptr};
        std::function< void (std::unique_ptr<StateTaskInterface>) > addStateTask;

    };

}
#endif //THREADSMANAGEMENTSYSTEM_SLAVE_H
