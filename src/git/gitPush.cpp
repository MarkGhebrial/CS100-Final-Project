#include "gitPush.h"
#include "gitError.h"

#include <string>

using std::string;
#include <iostream>
#include <sstream>
using std::string;
using std::istringstream;


void GitPush::run()
{
    string output = runCommand();
    checkForErrors(output);
}

void GitPush::checkForErrors(string output)
{
    istringstream stream(output);

    string line = "";
    string str;
    while (getline(stream, line))
    {
        str = line.substr(0, 5);

        if (str == "error" || str == "fatal")
        {
            throw GitError(GitErrorType::GIT_FAILED_TO_PUSH);
        }
    }
}