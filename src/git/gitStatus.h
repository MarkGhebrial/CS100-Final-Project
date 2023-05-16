#ifndef _GIT_STATUS_H_
#define _GIT_STATUS_H_

#include <vector>

#include "gitCommand.h"

struct GitStatusResult {
    GitStatusResult();

    /// Construct a new GitStatusResult by parsing the output of "git status --porcelain=v1"
    GitStatusResult(std::string gitOutput);

    std::vector<std::string> unstagedChanges;
    std::vector<std::string> stagedChanges;
    std::vector<std::string> untrackedChanges;
};

class GitStatus : GitCommand {
    public:
        GitStatus() : GitCommand("status --porcelain=v1") {}

        GitStatusResult run();
};



#endif