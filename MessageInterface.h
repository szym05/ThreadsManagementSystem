
#ifndef THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
#include <memory>
#include "Types.h"

namespace ThreadsManagementSystem {
    class MessageInterface{
    public:
        TypeMessage getTypeMessage() const {
            return typeMessage;
        }

        void setTypeMessage(TypeMessage typeMessage) {
            MessageInterface::typeMessage = typeMessage;
        }

    protected:
        TypeMessage typeMessage = TypeMessage::empty;


    };
}

#endif //THREADSMANAGEMENTSYSTEM_MESSAGEINTERFACE_H
