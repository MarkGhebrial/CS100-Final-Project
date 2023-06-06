#include "gitCommit.h"

#include <string>

using std::string;

GitCommit::GitCommit(std::string commitMessage) : GitCommand("git commit -m")
{
    string message = commitMessage;
}

void GitCommit::run()
{
    string output = runCommand();
}
