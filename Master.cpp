
#include <iostream>
#include "Master.h"
#include "SlaveManagement.h"
#include "JobFactoryPass.h"
#include "StateTaskPass.h"

namespace ThreadsManagementSystem {
    void Master::run() {
        while (tRunning) {
            getJobFromDataBaseMenagment();
            getTaskFromJobManagement();
            getSolutionTaskFromSlaveManagment();

            jobNotHaveSolution();

            std::this_thread::sleep_for(std::chrono::seconds(interval));
        }
    }

/**********************************************************************************************/
    void Master::getTaskFromJobManagementAddToSlaveManagment() {
            if (jobs.top()->isTask()) {
                slaveMenagment->addTask(jobs.top()->getTask());
                ///UpLoad state job to frotend
#ifdef DEBUG_SYSTEM_CONSOL
                dataBaseMenagment->addStateJob(std::move(jobs.top()->getState()));
#endif
            }
            else
            {
                if (!jobs.top()->isSolutions()) {
                    jobsExecutedWaitSolution.push_back(jobs.top());
                }
                jobs.pop();
            }
    }

    void Master::getTaskFromJobManagement() {
        try {
            while ((slaveMenagment->getNumberAvaibleSlaves() > 0) && (jobs.size() > 0)) {
                getTaskFromJobManagementAddToSlaveManagment();
            }
        }
        catch (...) {
            std::cout << " \n\n Exception in Master in getTaskFromJobManagement ";
            std::exception_ptr p = std::current_exception();
            std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
        }
    }

/**********************************************************************************************/
    void Master::getJobFromDataBaseMenagment() {
        try {
            if (dataBaseMenagment->getNumberJob() > 0) {
                std::unique_ptr<const JobInterface> job = dataBaseMenagment->getJob();


                std::shared_ptr<JobManagementInterface> jobManagment = jobManagmnetFactory->getJobManagment(std::move(job));

                jobs.push(jobManagment);
                jobsWaitSolution.insert(std::make_pair<TypeIdJob, std::shared_ptr<JobManagementInterface>>
                                                (jobManagment->getIdJob(), std::move(jobManagment)));
            }
        } catch (...) {
            std::cout << " \n\n Exception in Master in getJobFromDataBaseMenagment ";
            std::exception_ptr p = std::current_exception();
            std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
        }
    }

/**********************************************************************************************/
    void Master::getSolutionTaskFromSlaveManagment() {
        try {
            if (slaveMenagment->getNumberStateTask() > 0) {

                std::unique_ptr<const StateTaskInterface> solution = slaveMenagment->getStateTask();

                if(jobsWaitSolution.find(solution->getIdJob()) != jobsWaitSolution.end()) {

                    std::shared_ptr<JobManagementInterface> jobManagment = jobsWaitSolution[solution->getIdJob()];

                    jobManagment->setTimeExcuteTask(slaveMenagment->getTimeTaskExecute(solution->getIdJob()));

                    jobManagment->addSatateTask(std::move(solution));

                    dataBaseMenagment->addStateJob(jobManagment->getState());

                    if (jobManagment->isSolutions()) {
                        slaveMenagment->addMessage(jobManagment->getMessage());
                        jobsWaitSolution.erase(jobManagment->getIdJob());
                        jobsExecutedWaitSolution.remove(jobManagment);
                    }
                }
            }
        } catch (...) {
            std::cout << " \n\n Exception in Master in getSolutionTaskFromSlaveManagment ";
            std::exception_ptr p = std::current_exception();
            std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
        }
    }

    void Master::jobNotHaveSolution() {
        try {
            if (jobsExecutedWaitSolution.size() > 0) {

                for (std::list<std::shared_ptr<JobManagementInterface>>::iterator it = jobsExecutedWaitSolution.begin();
                     it != jobsExecutedWaitSolution.end(); ++it) {

                    if ((*it)->hasExecuted()) {
                        std::cout << "\n\n Has EXECUTED ";
                        std::unique_ptr<const StateTaskInterface> solution = std::make_unique<const ThreadsManagementSystemPassBreak::StateTaskPass>(TypeStateTask::solution);

                        (*it)->addSatateTask(std::move(solution));
                        dataBaseMenagment->addStateJob((*it)->getState());
                        jobsWaitSolution.erase((*it)->getIdJob());
                        jobsExecutedWaitSolution.erase(it);
                        break;
                    }
                }


            }
        } catch (...) {
            std::cout << " \n\n Exception in Master in jobNotHaveSolution ";
            std::exception_ptr p = std::current_exception();
            std::clog << (p ? p.__cxa_exception_type()->name() : "null") << std::endl;
        }

    }

    Master::Master(std::shared_ptr<ConnectionApiInterface> && connect) {
        slaveMenagment = std::make_unique<SlaveManagement>(60);
        dataBaseMenagment = std::make_unique<ThreadsManagementSystemPassBreak::JobFactoryPass>(connect);
    }

    bool Master::start() {
        slaveMenagment->start();
        dataBaseMenagment->start();

        if(!tRunning) {
            tRunning = true;
            tWorker = std::make_unique<std::thread>(&Master::run, this);
            return true;
        }
        return false;
    }

    bool Master::stop() {
        slaveMenagment->stop();
        dataBaseMenagment->stop();

        if(tRunning) {
            tRunning = false;
            tWorker->join();
            tWorker.reset(nullptr);
            return true;
        }
        return false;
    }
}


