#ifndef _GIT_STATUS_H_
#define _GIT_STATUS_H_

#include <vector>
using std::vector;

#include "gitCommand.h"

struct GitStatusResult {
    GitStatusResult();

    /// Construct a new GitStatusResult by parsing the output of "git status --porcelain=v1"
    GitStatusResult(string gitOutput);

    vector<string> unstagedChanges;
    vector<string> stagedChanges;
    vector<string> untrackedChanges;
};

class GitStatus : GitCommand {
    public:
        GitStatus() : GitCommand("status --porcelain=v1") {}

        GitStatusResult run();
};



#endif