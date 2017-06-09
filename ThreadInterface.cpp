
#include "ThreadInterface.h"

namespace ThreadsManagementSystem {

    bool ThreadInterface::start() {
        if (!tRunning) {
            tRunning = true;
            tWorker = std::make_unique<std::thread>(&ThreadInterface::run, this);
            return true;
        }
        return false;
    }

/*********************************************************************/
    bool ThreadInterface::stop() {
        if (tRunning) {
            tRunning = false;
            tWorker->join();
            tWorker.reset(nullptr);
            return true;
        }
        return false;
    }

/*********************************************************************/
    bool ThreadInterface::isRunning() {
        return tRunning;
    }

/*********************************************************************/
    const std::atomic_uint_fast64_t &ThreadInterface::getInterval() const {
        return interval;
    }

/*********************************************************************/
    void ThreadInterface::setInterval(const size_t &interval) {
        ThreadInterface::interval = interval;
    }

};