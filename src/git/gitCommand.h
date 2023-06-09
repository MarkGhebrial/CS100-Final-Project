#ifndef _GIT_COMMAND_H_
#define _GIT_COMMAND_H_

#include <string>

class GitCommand {
    public:
        /// @brief Construct a new GitCommand
        /// @param command The command to be run. "git " will be automatically prepended to it.
        GitCommand(std::string command);
        
    protected:
        /// @brief Run the command in a shell and return its output
        /// @return The command's output
        std::string runCommand();

        std::string command;
};

#endif