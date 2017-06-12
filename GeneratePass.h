
#ifndef THREADSMANAGEMENTSYSTEM_GENERATEPASS_H
#define THREADSMANAGEMENTSYSTEM_GENERATEPASS_H

#include <memory>
#include <vector>
#include <ostream>
#include "Alphabet.h"
namespace ThreadsManagementSystemPassBreak {
    class GeneratePass {
    public:

        GeneratePass(TypeNumberSteps numberSteps, size_t sizeAlphabet);
        GeneratePass(const GeneratePass & generatePass);

        bool next();

        size_t size() const;

        size_t operator[](long long i) const;

        size_t getDigit(long long i);

        GeneratePass& operator++();

        void next(size_t n);

        void setNumberStepsMax(TypeNumberSteps numberStepsMax);

        void setNumberStepsExecuted(TypeNumberSteps numberStepsExecuted);

    protected:
        void initializeNextPass();

    protected:
        TypeNumberSteps numberStepsMax {};
        TypeNumberSteps numberStepsExecuted {};
        size_t baseAlphabet {};
        std::vector<size_t> nextPass{0};

    public:
        friend std::ostream &operator<<(std::ostream &os, const GeneratePass &pass);
    };
};

#endif //THREADSMANAGEMENTSYSTEM_GENERATEPASS_H
