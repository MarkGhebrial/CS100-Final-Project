#ifndef _GIT_PULL_H_
#define _GIT_PULL_H_

#include "gitCommand.h"

class GitPull : public GitCommand
{
    public:
        /// Create a new GitPull object
        GitPull() : GitCommand("pull --porcelain") { };

        void run();
        void pullFailed(std::string runOutput);
    private:
        std::string message;
};

#endif