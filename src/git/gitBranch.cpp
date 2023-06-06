#include "gitBranch.h"
#include "gitError.h"

#include <string>

using std::string;

GitBranch::GitBranch(string branchName) : GitCommand("branch " + branchName) { }

void run()
{
    string output = runCommand();
}