
#ifndef THREADSMANAGEMENTSYSTEM_THREADINTERFACE_H
#define THREADSMANAGEMENTSYSTEM_THREADINTERFACE_H


#include <atomic>
#include <thread>
#include <memory>
#include <chrono>

namespace ThreadsManagementSystem {

    class ThreadInterface {
    protected:
        std::atomic_bool tRunning{false};
        std::unique_ptr<std::thread> tWorker;
        std::atomic_uint_fast64_t interval{1}; // In seconds

        virtual void run() = 0;
        /*
         * Example implementation for function run
         * while(tRunning)
         * {
         *      to do
         *
         *      std::this_thread::sleep_for (std::chrono::seconds(interval));
         * }
         *
         */
    public:

        virtual bool start();

        virtual bool stop();

        virtual bool isRunning();

        const std::atomic_uint_fast64_t &getInterval() const;

        void setInterval(const size_t &interval);

    };

};
#endif //THREADSMANAGEMENTSYSTEM_THREADINTERFACE_H
