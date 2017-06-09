//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_GENERATEPASS_H
#define THREADSMANAGEMENTSYSTEM_GENERATEPASS_H

#include <bits/unique_ptr.h>
#include <bits/shared_ptr.h>
#include <vector>
#include "Alphabet.h"
namespace ThreadsManagementSystemPassBreak {
    class GeneratePass {
    public:

        GeneratePass(TypeNumberSteps numberSteps, size_t sizeAlphabet);

        bool next();

        size_t size();

        size_t operator[](long long i);

        GeneratePass& operator++();

        void next(size_t n);

    protected:
        void initializeNextPass();

    protected:
        TypeNumberSteps numberStepsMax {};
        TypeNumberSteps numberStepsExecuted {};
        size_t sizeAlphabet {};
        std::vector<size_t> nextPass{0};
    };
};

#endif //THREADSMANAGEMENTSYSTEM_GENERATEPASS_H
