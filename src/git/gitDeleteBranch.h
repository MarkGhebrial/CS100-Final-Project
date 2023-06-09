#ifndef _GIT_DELETE_BRANCH_H_
#define _GIT_DELETE_BRANCH_H_

#include "gitCommand.h"

class GitDeleteBranch : public GitCommand {
    public:
        GitDeleteBranch(std::string branchName);

        void run();
    private:
        std::string branchName;
};

#endif