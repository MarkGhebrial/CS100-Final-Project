#include "gitListBranches.h"
#include "gitError.h"

#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::istringstream;

std::vector<string> GitListBranches::run()
{
    string output = runCommand();

    istringstream stream(output);

    std::vector<string> branchVector;
    string line;
    while (getline(stream, line))
    {
        string branchName = line.substr(2, line.size() - 1);

        branchVector.push_back(branchName);
    }

    return branchVector;
}