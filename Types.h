
#ifndef THREADSMANAGEMENTSYSTEM_TYPES_H
#define THREADSMANAGEMENTSYSTEM_TYPES_H

#include <memory>

using TypeIdJob = unsigned long long;
#define empty_TypeIdJob  0
using TypeIdTask = unsigned long long;
#define empty_TypeIdTask  0


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
