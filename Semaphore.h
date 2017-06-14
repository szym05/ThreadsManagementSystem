//
// Created by szymon on 14.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_SEMAPHORE_H
#define THREADSMANAGEMENTSYSTEM_SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include <atomic>

namespace ThreadsManagementSystem {
    class Semaphore {
        std::mutex mutSemaphore;
        std::condition_variable conSemaphore;
        std::atomic_int_least64_t cunter{1};

    public:
        Semaphore(const size_t N) : cunter(N) {}

        void wait(){
            std::unique_lock<std::mutex> lck{mutSemaphore};
            while(cunter == 0){
                conSemaphore.wait(lck);
            }
            --cunter;
        }

        void post(){
            std::unique_lock<std::mutex> lck{mutSemaphore};
            ++cunter;
            lck.unlock();
            conSemaphore.notify_one();
        }

    };
}


#endif //THREADSMANAGEMENTSYSTEM_SEMAPHORE_H
