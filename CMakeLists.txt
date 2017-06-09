cmake_minimum_required(VERSION 3.7)
project(ThreadsManagementSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp SynchronizedQueue.h ThreadInterface.cpp ThreadInterface.h JobInterface.h JobManagmentInterface.h TaskInterface.h StateTaskInterface.h StateJobInterface.h MessageInterface.h Types.h SlaveManagementInterface.h SlaveInterface.h MasterInterface.h JobFactoryInterface.h SlaveManagement.cpp SlaveManagement.h Slave.cpp Slave.h GenerateHashPass.h)
add_executable(ThreadsManagementSystem ${SOURCE_FILES})



target_link_libraries(ThreadsManagementSystem  -lpthread)