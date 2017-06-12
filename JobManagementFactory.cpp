
#include <iostream>
#include "JobManagementFactory.h"



std::shared_ptr<ThreadsManagementSystem::JobManagementInterface>
ThreadsManagementSystemPassBreak::JobManagementFactory::getJobManagment(
        std::unique_ptr<const ThreadsManagementSystem::JobInterface> &&job) const {

    std::shared_ptr<ThreadsManagementSystem::JobManagementInterface> jobManagment{nullptr};

        const JobPass * jobPassPtr = dynamic_cast<const JobPass *>(job.release());

    if(jobPassPtr != nullptr) {

        std::cout << "\n\n Job in Master \n "  << *jobPassPtr << "\n\n";

        jobManagment =   std::make_shared<JobManagemetPassBruteForce>(std::unique_ptr<const JobPass>(jobPassPtr));
    } else{
        std::cout << "\n\n\n ERROR Bad cast in JobManagementFactory getJobManagment \n\n\n";
    }

    return jobManagment;
}
