#ifndef _GIT_COMMIT_H_
#define _GIT_COMMIT_H_

#include "gitCommand.h"

class GitCommit : public GitCommand {
    public:
        /// Default constructor that doesn't implement a commit message
            /// The user will instead type in the message through vim
        GitCommit() : GitCommand("git commit") { };

        /// Parameterized constructor that implements a user inputted commit message
        GitCommit(std::string commitMessage);

        void run();
};

#endif