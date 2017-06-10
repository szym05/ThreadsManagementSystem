
#ifndef THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
#include <memory>
#include "Types.h"

namespace ThreadsManagementSystem {
    class MessageInterface{
    public:
        ///CONSTRUCTOR
        MessageInterface(TypeIdJob idJob, TypeIdTask idtask, TypeMessage typeMessage) :
                idJob(idJob),
                idTask(idtask),
                typeMessage(typeMessage) {}

        MessageInterface(TypeIdTask idtask, TypeMessage typeMessage) :
                idTask(idtask),
                typeMessage(typeMessage) {}

        ///GETTER
        TypeMessage getTypeMessage() const {
            return typeMessage;
        }

        TypeIdJob getIdJob() const {
            return idJob;
        }

        TypeIdTask getIdtask() const {
            return idTask;
        }
       //////// //SETTER
       void setIdtask(TypeIdTask idtask) {
           MessageInterface::idTask = idtask;
       }

        void setTypeMessage(TypeMessage typeMessage) {
            MessageInterface::typeMessage = typeMessage;
        }

        void setIdJob(TypeIdJob idJob) {
            MessageInterface::idJob = idJob;
        }


    protected:
        TypeIdJob idJob {empty_TypeIdJob};
        TypeIdTask idTask {empty_TypeIdTask};
        TypeMessage typeMessage = TypeMessage::empty;

    };
}

#endif //THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
