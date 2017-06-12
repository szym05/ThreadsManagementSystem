//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_ALPHABET_H
#define THREADSMANAGEMENTSYSTEM_ALPHABET_H

#include <bits/unique_ptr.h>
#include <ostream>
#include "Alphabet.h"
#include "TypesPassBreak.h"

namespace ThreadsManagementSystemPassBreak {
    class Alphabet {
    public:
        Alphabet(const TypeAlphabet &alphabet);

        Alphabet(const Alphabet & alphabet);

        std::unique_ptr<Alphabet> operator=(const Alphabet & alphabet);

        size_t size() const;

        TypeSignAlphabet operator[](long long i) const;

        TypeSignAlphabet getSign(long long i) const ;

    private:
        TypeAlphabet alphabet {empty_TypeAlphabet};

    public:
        friend std::ostream &operator<<(std::ostream &os, const Alphabet &alphabet);

    };
}


#endif //THREADSMANAGEMENTSYSTEM_ALPHABET_H
