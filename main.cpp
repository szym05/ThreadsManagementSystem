#include <iostream>

#include "Slave.h"

#include <QtCore>

#include "TaskPassBruteForce.h"

#include "ConnectionApiPass.h"
#include "JobPass.h"
#include "Master.h"
#include "NcursesWrapper.h"
#include <ncurses.h>



void testSystem();
int testNcurses();
std::unique_ptr<const ThreadsManagementSystemPassBreak::JobPass> addJobMain(size_t  & row);

int main() {
#ifdef DEBUG_SYSTEM_CONSOL
 std::cout << "\n\nstart\n\n";
#endif
    std::string pas = "1123";


    //testSystem();
return testNcurses();

    //return 0;
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
                    2,
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

    SystemMonitoring::Monitor monitor(connect);

    ThreadsManagementSystem::Master master(connect, monitor);
    if(!master.start()){
        std::cout << "\n\n ERROR START MASTER \n\n";
    }

    while(true){
        std::this_thread::sleep_for (std::chrono::seconds(1));
        if(connect->getNumberStateJob() > 0){
            auto stateJob = connect->getStateJob();
            std::cout << "\n\n Main " << *stateJob << "\n\n";
            //if(stateJob->getProgress() == 1.0)return;
        }
    }
}


int testNcurses() {
    const std::string menu = "\nMenu:"
            "\n a => Add job"
            "\n F4 => close\n\n";

    std::shared_ptr<ThreadsManagementSystemPassBreak::ConnectionApiPass> connect = std::make_shared<ThreadsManagementSystemPassBreak::ConnectionApiPass >() ;

    SystemMonitoring::Monitor monitor(connect);

    ThreadsManagementSystem::Master master(connect, monitor);
    if(!master.start()){
        std::cout << "\n\n ERROR START MASTER \n\n";
        getch();
        return 0;
    }

    if(!monitor.start()){
        std::cout << "\n\n ERROR START MONITOR \n\n";
        getch();
        return 0;
    }


    int ch;

    initscr();			/* Start curses mode 		*/
    raw();				/* Line buffering disabled	*/
    keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
    noecho();			/* Don't echo() while we do getch */
    /* If raw() hadn't been called
					 * we have to press enter before it
					 * gets to the program 		*/



    connect->addJob(
            std::make_unique<const ThreadsManagementSystemPassBreak::JobPass>(
                    1,
                    1,
                    TypeHash ::md5,
                    "c83b2d5bb1fb4d93d9d064593ed6eea2|",
                    TypeMethod ::brute_force,
                    std::make_unique<ThreadsManagementSystemPassBreak::Alphabet>("asdfghjklp"),
                    1,
                    8,
                    1000000
            )
    );

    size_t row = 40;

    do {
        row = 40;
        mvprintw(row,0,menu.c_str());
        row++;
        refresh();
        ch = getch();

         switch (ch){
            case KEY_UP:
                connect->addJob(std::move(addJobMain(row)));
                break;
        }
    }while ( ch != KEY_F(4));	/* Without keypad enabled this will */
        mvprintw(50,0,"F4 Key pressed! press any key...");/*  not get to us either	*/
        /* Without noecho() some ugly escape
         * charachters might have been printed
         * on screen			*/

    refresh();			/* Print it on to the real screen */
    getch();			/* Wait for user input */
    endwin();			/* End curses mode		  */

    monitor.stop();
    master.stop();

    return 0;
}

std::unique_ptr<const ThreadsManagementSystemPassBreak::JobPass> addJobMain(size_t  & row){
    static size_t idJob = 2;
    std::string hash = SystemMonitoring::NcursesWrapper::EnterString(row, 0,"Enter MD5 hash", 200);
    std::string alphabet = SystemMonitoring::NcursesWrapper::EnterString(++row, 0,"Enter alphabet of pass", 200);


    return      std::make_unique<const ThreadsManagementSystemPassBreak::JobPass>(
            ++idJob,
            1,
            TypeHash ::md5,
            hash,
            TypeMethod ::brute_force,
            std::make_unique<ThreadsManagementSystemPassBreak::Alphabet>(alphabet),
            1,
            8,
            10000000
    );
}