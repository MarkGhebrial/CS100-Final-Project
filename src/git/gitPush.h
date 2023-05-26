#ifndef _GIT_PUSH_H_
#define _GIT_PUSH_H_

#include "gitCommand.h"

class GitPush : public GitCommand
{
    public:
        /// Construct a new GitPush object
        GitPush() : GitCommand("push --porcelain") { };

        void run();
        void checkForErrors(std::string runOutput);
};

#endif