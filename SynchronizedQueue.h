
#ifndef THREADSMANAGEMENTSYSTEM_SYNCHRONIZEDQUEUE_H
#define THREADSMANAGEMENTSYSTEM_SYNCHRONIZEDQUEUE_H

#include <queue>
#include <condition_variable>
#include <mutex>
#include <stdexcept>

namespace ThreadsManagementSystem {



    template<typename T>
    class SynchronizedQueue {
    private:
        std::queue<T> fifo;
        std::mutex mut;
    public:
        T pop();  // throw out_of_range exception when queue is empty
        void push(const T &element);

        void push(T &&element);

        size_t size();
    };




//IMPLEMENTATION
/*********************************************************************/

    template <typename T>
    T SynchronizedQueue<T>::pop()
    {
        std::unique_lock<std::mutex> mlock(mut);
        if (fifo.empty()) {
            throw std::out_of_range("Queue is empty!");
        }
        auto element = fifo.front();
        fifo.pop();
        return element;
    }
    /*********************************************************************/
    template <typename T>
    void SynchronizedQueue<T>::push(const T& element)
    {
        std::unique_lock<std::mutex> mlock(mut);
        fifo.push(element);
        mlock.unlock();
    }
    /*********************************************************************/
    template <typename T>
    void SynchronizedQueue<T>::push(T&& element) {
        std::unique_lock<std::mutex> mlock(mut);
        fifo.push(std::move(element));
        mlock.unlock();
    }
    /*********************************************************************/
    template <typename T>
    size_t SynchronizedQueue<T>::size(){
        std::unique_lock<std::mutex> mlock(mut);
        return fifo.size();
    }
};


/*********************************************************************/
/*********************************************************************/
///Specialization for std::unique_ptr<T>

namespace ThreadsManagementSystem {
    template<typename T>
    class SynchronizedQueue<std::unique_ptr<T>> {
    private:
        std::queue<std::unique_ptr<T>> fifo;
        std::mutex mut;
    public:
        std::unique_ptr<T> pop();  // throw out_of_range exception when queue is empty
        void push(std::unique_ptr<T> &element); // element is move to fifo
        void push(std::unique_ptr<T> &&element);

        size_t size();
    };



//IMPLEMENTATION
/*********************************************************************/

    template<typename T>
    std::unique_ptr<T> SynchronizedQueue<std::unique_ptr<T>>::pop() {
        std::unique_lock<std::mutex> mlock(mut);
        if (fifo.empty()) {
            throw std::out_of_range("Queue is empty!");
        }
        auto element = std::move(fifo.front());
        fifo.pop();
        return element;
    }

/*********************************************************************/
    template<typename T>
    void SynchronizedQueue<std::unique_ptr<T>>::push(std::unique_ptr<T> &element) {
        std::unique_lock<std::mutex> mlock(mut);
        fifo.push(std::move(element));
        mlock.unlock();
    }

/*********************************************************************/
    template<typename T>
    void SynchronizedQueue<std::unique_ptr<T>>::push(std::unique_ptr<T> &&element) {
        std::unique_lock<std::mutex> mlock(mut);
        fifo.push(std::move(element));
        mlock.unlock();
    }

/*********************************************************************/
    template<typename T>
    size_t SynchronizedQueue<std::unique_ptr<T>>::size() {
        std::unique_lock<std::mutex> mlock(mut);
        return fifo.size();
    }
};

#endif //THREADSMANAGEMENTSYSTEM_SYNCHRONIZEDQUEUE_H
