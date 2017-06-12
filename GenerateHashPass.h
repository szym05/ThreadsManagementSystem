

#ifndef THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H
#define THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H

#include "TypesPassBreak.h"
#include <QCryptographicHash>

namespace ThreadsManagementSystemPassBreak{
    class GenerateHashPass{
    public:
        static Hash getHashMethodMD5(const TypeSolution pass){
            return QCryptographicHash::hash(pass.c_str(), QCryptographicHash::Md5).toHex().toStdString();
        }
    };
}
#endif //THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H
