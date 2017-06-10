

#ifndef THREADSMANAGEMENTSYSTEM_TYPESPASSBREAK_H
#define THREADSMANAGEMENTSYSTEM_TYPESPASSBREAK_H

#include <string>

using Hash = std::string;
#define empty_Hash ""
using TypeAlphabet = std::string;
#define empty_TypeAlphabet ""
using TypeSolution = std::string;
#define empty_TypeSolution ""
using TypeSignAlphabet = char;
#define empty_TypeSignAlphabet '\0'

using TypeLengthPassw = unsigned int;

using TypeNumberSteps = unsigned long long;

enum class TypeHash : char {
    empty,
    md5,
};

enum class TypeMethod : char{
    empty,
    brute_force
};


#endif //THREADSMANAGEMENTSYSTEM_TYPESPASSBREAK_H
