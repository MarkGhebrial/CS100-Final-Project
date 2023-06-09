#include "gitNewBranch.h"
#include "gitError.h"

#include <string>

using std::string;

GitNewBranch::GitNewBranch(string branchName) : GitCommand("branch " + branchName) { }

void GitNewBranch::run()
{
    string output = runCommand();
}