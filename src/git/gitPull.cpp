#include "gitPull.h"
#include "gitError.h"

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::istringstream;

void GitPull::run()
{
    string output = runCommand();
    checkForErrors(output);
}

void GitPull::checkForErrors(std::string output)
{
    istringstream stream(output);

    string line = "";
    string str;
    while (getline(stream, line))
    {
        str = line.substr(0, 5);
    }

    if (str == "error" || str == "fatal")
    {
        throw GitError(GitErrorType::GIT_FAILED_TO_PULL);
    }
}