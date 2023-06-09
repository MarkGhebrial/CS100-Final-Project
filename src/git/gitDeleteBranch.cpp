#include "gitDeleteBranch.h"
#include "gitError.h"

#include <string>

using std::string;

GitDeleteBranch::GitDeleteBranch(string branchName) : GitCommand("branch -d " + branchName) { }

void GitDeleteBranch::run()
{
    string output = runCommand();
}