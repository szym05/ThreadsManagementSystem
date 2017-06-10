//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_ALPHABET_H
#define THREADSMANAGEMENTSYSTEM_ALPHABET_H

#include "Alphabet.h"
#include "TypesPassBreak.h"

namespace ThreadsManagementSystemPassBreak {
    class Alphabet {
    public:
        Alphabet(const TypeAlphabet &alphabet);

        size_t size() const;

        TypeSignAlphabet operator[](long long i) const;

        TypeSignAlphabet getSign(long long i) const ;

    private:
        TypeAlphabet alphabet {empty_TypeAlphabet};

    };
}


#endif //THREADSMANAGEMENTSYSTEM_ALPHABET_H
