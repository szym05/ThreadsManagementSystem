cmake_minimum_required(VERSION 3.7)
project(ThreadsManagementSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp SynchronizedQueue.h ThreadInterface.cpp ThreadInterface.h JobInterface.h JobManagementInterface.h TaskInterface.h StateTaskInterface.h StateJobInterface.h MessageInterface.h Types.h SlaveManagementInterface.h SlaveInterface.h MasterInterface.h JobFactoryInterface.h SlaveManagement.cpp SlaveManagement.h Slave.cpp Slave.h GenerateHashPass.h JobPass.h JobManagementPass.cpp JobManagementPass.h StateJobPass.h JobFactoryPass.cpp JobFactoryPass.h ConnectionApiInterface.h ConnectionApiPass.cpp ConnectionApiPass.h JobManagemetPassBruteForce.cpp JobManagemetPassBruteForce.h Alphabet.h Alphabet.cpp GeneratePass.h GeneratePass.cpp TaskPass.h TypesPassBreak.h TaskPassBruteForce.h TaskPassBruteForce.cpp StateTaskPass.h JobRelatedSlaves.cpp JobRelatedSlaves.h SlaveRelatedTasks.cpp SlaveRelatedTasks.h VectorSlaves.cpp VectorSlaves.h)


find_package(Qt5Widgets REQUIRED)

add_executable(ThreadsManagementSystem ${SOURCE_FILES})

target_link_libraries(ThreadsManagementSystem Qt5::Widgets)

target_link_libraries(ThreadsManagementSystem  -lpthread)