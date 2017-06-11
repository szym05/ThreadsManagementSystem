
#include <iostream>
#include "SlaveManagement.h"
namespace ThreadsManagementSystem {
    void SlaveManagement::addTask(
            std::unique_ptr<ThreadsManagementSystem::TaskInterface> &&task) {

        sendTaskQueue.push(std::move(task));
    }

    void SlaveManagement::addMessage(
            std::unique_ptr<ThreadsManagementSystem::MessageInterface> &&message) {

        sendMessageInterfaceQueue.push(std::move(message));
    }

    std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface>
    SlaveManagement::getStateTask(TypeIdJob idJob, TypeIdTask idTask) {

        TypeIdSlave idSlave = jobRelatedSlaves.getSlaveFromJobTask(idJob, idSlave);
        if(idSlave != std::numeric_limits<TypeIdSlave>::max())
             return vecSlaves->getStateTask(idSlave);

        return std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface>{nullptr};
    }

    std::unique_ptr<const ThreadsManagementSystem::StateTaskInterface>
    SlaveManagement::getStateTask() {
        return stateTasks.pop();
    }

    TypeNumberSlave SlaveManagement::getNumberSlave() {
        return vecSlaves->size();
    }

    TypeNumberSlave SlaveManagement::getNumberAvaibleSlaves() {
        return availableSlaves.size();
    }


    double SlaveManagement::getTimeTaskExecute(TypeIdJob idJob) {
        return jobRelatedSlaves.getTimeTaskExecute(idJob);
    }

    void SlaveManagement::addStateTask(
            std::unique_ptr<ThreadsManagementSystem::StateTaskInterface> &&stateTask) {

        stateTasks.push(std::move(stateTask));
    }

    void SlaveManagement::addSlaveToAvailable(TypeIdSlave idSlave, TypeIdJob idJob,
                                                                                TypeIdTask idTask) {

        jobRelatedSlaves.removeSlaveFromJob(idJob, idTask, idSlave);
        availableSlaves.push(idSlave);
    }


    void SlaveManagement::registerSlave(TypeIdSlave slave) {
        availableSlaves.push(slave);
    }


///////// TASK MENAGEMENT////////////////////


    void SlaveManagement::run() {
        while (tRunning) {
            sendTaskToSlave();
            sendMessageToSlave();


            std::this_thread::sleep_for(std::chrono::seconds(interval));
        }
    }


///SEND
    void SlaveManagement::sendTaskToSlave() {
        while ((availableSlaves.size() > 0) && (sendTaskQueue.size() > 0)) {

            TypeIdSlave slave = availableSlaves.pop();
            auto task = sendTaskQueue.pop();

            ///Add slave to related job and task
            jobRelatedSlaves.addSlaveToJob(task->getIdJob(), task->getIdTask(), slave);

            ///SEND TASK TO SLAVE
            if (!vecSlaves->start(slave, std::move(task))) {
                std::cout << "\n\n\n ERROR Bad assignment of tasks in SlaveManagement sendTaskToSlave \n\n\n ";
            }
        }
    }

    void SlaveManagement::sendMessageToSlave() {
        if (sendMessageInterfaceQueue.size() > 0) {
            auto message = sendMessageInterfaceQueue.pop();

            switch (message->getTypeMessage()){
                case TypeMessage::terminate:
                    messageTerminateAllSlave(message->getIdJob());
                    break;
            }
        }
    }

    void SlaveManagement::messageTerminateAllSlave(TypeIdJob idJob) {
        auto list = jobRelatedSlaves.getListJobRelatedSlaves(idJob);
        jobRelatedSlaves.removeAll(idJob);

        for (TypeIdSlave &slave : *list) {
            if(!vecSlaves->terminate(slave)){
                std::cout << "\n\n\n ERROR Slave is not terminating in SlaveManagement sendTaskToSlave \n\n\n ";
            }
        }

    }


    SlaveManagement::SlaveManagement(TypeNumberSlave numberSlave) {

        using std::placeholders::_1;
        using std::placeholders::_2;
        using std::placeholders::_3;

        std::function<void(std::unique_ptr<StateTaskInterface> &&)> addStateTask =  std::bind(&SlaveManagement::addStateTask, this, _1);

        std::function< void ( TypeIdSlave , TypeIdJob , TypeIdTask ) > addSlaveToAvailable =  std::bind(&SlaveManagement::addSlaveToAvailable, this, _1, _2, _3);

        std::function< void ( TypeIdSlave ) > registerSlave =   std::bind(&SlaveManagement::registerSlave, this, _1);


        vecSlaves = std::make_unique<VectorSlaves>(
                numberSlave,
                addStateTask,
                addSlaveToAvailable,
                registerSlave
        );
    }

}
