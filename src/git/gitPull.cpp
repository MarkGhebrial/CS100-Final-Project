#include "gitPull.h"
#include "gitError.h"

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using std::string;
using std::istringstream;

void GitPull::run()
{
    string output = runCommand();
    checkForErrors(output);
}

void GitPull::checkForErrors(string output)
{
    istringstream stream(output);

    std::vector<string> errorMessage;
    string line;
    while (getline(stream, line))
    {
        errorMessage.push_back(line.substr(0, 6));
    }

    for (string errorMessageLine : errorMessage)
    {
        if (errorMessageLine == "error" || errorMessageLine == "fatal")
        {
            throw GitError(GitErrorType::GIT_FAILED_TO_PULL);
        }
    }
}