//
// Created by szymon on 14.06.17.
//

#ifndef THREADSMANAGEMENTSYSTEM_BARRIER_H
#define THREADSMANAGEMENTSYSTEM_BARRIER_H


#include <condition_variable>
#include <atomic>

namespace ThreadsManagementSystem {
    class Barrier {
        std::mutex mutSemaphore;
        std::condition_variable conSemaphore;
        std::atomic_uint_fast64_t cunter{0};
        const size_t MAX;

    public:
        Barrier(const size_t N) : MAX(N) {}

        void wait(){
            std::unique_lock<std::mutex> lck{mutSemaphore};
            while(cunter < MAX){
                conSemaphore.wait(lck);
            }
        }

        void post(){
            std::unique_lock<std::mutex> lck{mutSemaphore};
            ++cunter;
            lck.unlock();
            if(cunter >= MAX) {
                conSemaphore.notify_all();
            }
        }

    };
};


#endif //THREADSMANAGEMENTSYSTEM_BARRIER_H
