#include "gitCommit.h"

#include <string>

using std::string;

GitCommit::GitCommit(std::string commitMessage)
    : GitCommand("commit -m \"" + commitMessage + "\"")
{}

void GitCommit::run()
{
    string output = runCommand();
}
