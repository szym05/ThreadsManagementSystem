#include <iostream>

#include "Slave.h"

#include <QtCore>

#include "TaskPassBruteForce.h"

#include "ConnectionApiPass.h"
#include "JobPass.h"
#include "Master.h"
#include <curses.h>



void testSystem();

int main() {
#ifdef DEBUG_SYSTEM_CONSOL
 std::cout << "\n\nstart\n\n";
#endif
    std::string pas = "1123";


    testSystem();


    return 0;
}

void testSystem(){
    std::shared_ptr<ThreadsManagementSystemPassBreak::ConnectionApiPass> connect = std::make_shared<ThreadsManagementSystemPassBreak::ConnectionApiPass >() ;

    connect->addJob(
            std::make_unique<const ThreadsManagementSystemPassBreak::JobPass>(
               1,
               1,
               TypeHash ::md5,
               "c83b2d5bb1fb4d93d9d064593ed6eea2|",
               TypeMethod ::brute_force,
               std::make_unique<ThreadsManagementSystemPassBreak::Alphabet>("asdfghjklp"),
               1,
               4,
               1000
            )
    );
    connect->addJob(
            std::make_unique<const ThreadsManagementSystemPassBreak::JobPass>(
                    1,
                    1,
                    TypeHash ::md5,
                    "c83b2d5bb1fb4d93d9d064593ed6eea2|",
                    TypeMethod ::brute_force,
                    std::make_unique<ThreadsManagementSystemPassBreak::Alphabet>("asdfghjklp"),
                    1,
                    4,
                    1000
            )
    );

    SystemMonitoring::Monitor monitor;

    ThreadsManagementSystem::Master master(connect, monitor);
    if(!master.start()){
        std::cout << "\n\n ERROR START MASTER \n\n";
    }

    while(true){
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if(connect->getNumberStateJob() > 0){
            auto stateJob = connect->getStateJob();
            std::cout << "\n\n Main " << *stateJob << "\n\n";
            if(stateJob->getProgress() == 1.0)return;
        }
    }
}