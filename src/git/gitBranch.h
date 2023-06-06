#ifndef _GIT_BRANCH_H_
#define _GIT_BRANCH_H_

#include "gitCommand.h"

class GitBranch : public GitCommand {
    public:
        /// Default constructor that outputs all local branches
            /// to the terminal
        GitBranch() : GitCommand("branch");

        /// Parameterized constructor that creates a new branch
        GitBranch(std::string branchName);

        void run();
    private:
        std::string branchName;
};

#endif