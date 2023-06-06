
#ifndef _GIT_NEW_BRANCH_H_
#define _GIT_NEW_BRANCH_H_

#include "gitCommand.h"

class GitNewBranch : public GitCommand {
    public:
        /// Parameterized constructor that creates a new branch
        GitNewBranch(std::string branchName);

        void run();
    private:
        std::string branchName;
};

#endif

