#ifndef _GIT_PULL_H_
#define _GIT_PULL_H_

#include "gitCommand.h"

class GitPull : public GitCommand
{
    public:
        /// Create a new GitPull object
        GitPull() : GitCommand("pull") { };

        void run();
        void checkForErrors(std::string runOutput);
    private:
        std::string message;
};

#endif