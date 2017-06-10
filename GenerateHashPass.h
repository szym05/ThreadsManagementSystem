//
// Created by szymon on 09.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H
#define THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H

#include "TypesPassBreak.h"
#include <QCryptographicHash>

namespace ThreadsManagementSystemPassBreak{
    class GenerateHashPass{
    public:
        static Hash getHashMethodMD5(TypeSolution pass){
            return QCryptographicHash::hash(pass.c_str(), QCryptographicHash::Md5).toHex().toStdString();
        }
    };
}
#endif //THREADSMANAGEMENTSYSTEM_GENERATEHASHPASS_H
