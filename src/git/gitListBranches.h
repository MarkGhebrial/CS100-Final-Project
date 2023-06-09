#ifndef _GIT_LIST_BRANCHES_H_
#define _GIT_LIST_BRANCHES_H_

#include "gitCommand.h"

class GitListBranches : public GitCommand {
    public:
        /// Default constructor that outputs all local branches
            /// to the terminal
        GitListBranches() : GitCommand("branch");

        std::vector<std::string> run();
    private:
        std::string branchName;
};

#endif