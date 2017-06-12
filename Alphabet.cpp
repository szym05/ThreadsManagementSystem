//
// Created by szymon on 09.06.17.
//

#include "Alphabet.h"

ThreadsManagementSystemPassBreak::Alphabet::Alphabet(const TypeAlphabet &alphabet) : alphabet(alphabet) {}

size_t ThreadsManagementSystemPassBreak::Alphabet::size() const {
    return alphabet.size();
}

TypeSignAlphabet ThreadsManagementSystemPassBreak::Alphabet::operator[](long long  i) const {
    if( i > 0 && i < alphabet.size()) {
        return alphabet[i];
    }
    return empty_TypeSignAlphabet;
}

TypeSignAlphabet ThreadsManagementSystemPassBreak::Alphabet::getSign(long long i) const {
    if( i > 0 && i < alphabet.size()) {
        char z = alphabet[i];
        return z;
    }
    return empty_TypeSignAlphabet;
}


ThreadsManagementSystemPassBreak::Alphabet::Alphabet(const ThreadsManagementSystemPassBreak::Alphabet &alphabet) {

    this->alphabet = alphabet.alphabet;
}

std::unique_ptr<ThreadsManagementSystemPassBreak::Alphabet>  ThreadsManagementSystemPassBreak::Alphabet::operator=(const ThreadsManagementSystemPassBreak::Alphabet &alphabet) {

    if(this != &alphabet){
        this->alphabet = alphabet.alphabet;
    }

    return std::unique_ptr<Alphabet>(this);
}
