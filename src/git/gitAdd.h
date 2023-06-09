#ifndef __GIT_ADD_H__
#define __GIT_ADD_H__

#include "gitCommand.h"

#include <vector>
#include <string>

class GitAdd : public GitCommand {
    public:
        /// Construct `GitAdd` that will stage all files (using `git add --all`)
        GitAdd() : GitCommand("add --all") { };

        //
        GitAdd(std::vector<std::string> filesToStage) : GitCommand("add") {
            for (std::string s : filesToStage) {
                command += (" " + s);
            }
        };

        void run();
};

#endif