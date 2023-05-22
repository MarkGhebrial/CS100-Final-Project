#include "gitPush.h"
#include "gitError.h"

#include <string>

using std::string;

void GitPush::run()
{
    string output = runCommand();
    pushFailed(output);
}

void GitPush::pushFailed(string runOutput)
{
    for (char& character : runOutput)
    {
        if (character == '!')
        {
            throw GitError(GitErrorType::GIT_FAILED_TO_PUSH);
        }
    }
}