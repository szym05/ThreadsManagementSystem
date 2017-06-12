
#ifndef THREADSMANAGEMENTSYSTEM_TYPES_H
#define THREADSMANAGEMENTSYSTEM_TYPES_H

/***********************************************/
//#define DEBUG_SYSTEM_CONSOL
/*********************************************/
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
    empty = 0,
    terminate = 1
};


enum class TypeStateTask : char{
    empty = 0,
    state = 1,
    solution = 2
};


template <typename Enumeration>
auto as_integer(Enumeration const value)
-> typename std::underlying_type<Enumeration>::type
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}


#endif //THREADSMANAGEMENTSYSTEM_TYPES_H
