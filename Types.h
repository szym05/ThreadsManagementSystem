
#ifndef THREADSMANAGEMENTSYSTEM_TYPES_H
#define THREADSMANAGEMENTSYSTEM_TYPES_H

#include <memory>

using TypeIdJob = unsigned long long;
#define empty_TypeIdJob  0
using TypeIdTask = unsigned long long;
#define empty_TypeIdTask  0
#define all_TypeIdTask  1
#define first_TypeIdTask 2
using TypePriority = unsigned int;
using TypeIdSlave = unsigned int;
#define empty_TypeSlave 0
#define all_TypeSlave 1
#define first_TypeSlave 2
using TypeNumberSlave = unsigned int;


enum class TypeMessage : char{
    empty,
    terminate
};


enum class TypeStateTask : char{
    empty,
    state,
    solution
};


#endif //THREADSMANAGEMENTSYSTEM_TYPES_H
