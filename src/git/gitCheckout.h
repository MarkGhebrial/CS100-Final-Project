#ifndef _GIT_CHECKOUT_H_
#define _GIT_CHECKOUT_H_

#include "gitCommand.h"

class GitCheckout : public GitCommand {
    public:
        GitCheckout(std::string branchName);

        void run();
    private:
        std::string branchName;
};

#endif
