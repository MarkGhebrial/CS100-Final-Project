#include "gitPull.h"
#include "gitError.h"

#include <vector>
#include <string>

void GitPull::run()
{
    std::string output = runCommand();
}

void GitPull::pullFailed(std::string output)
{
    std::vector<char> v;
    std::string err = "error";
    for (unsigned i = 0; i < 5; i++)
    {
        v.push_back(output[i]);
    }

    int count = 0;
    unsigned index = 0;
    for (char& character : err)
    {
        if (character == v.at(index))
        {
            count++;
        }
        else
        {
            break;
        }
        index++;
    }

    if (count == 5)
    {
        throw GitError(GitErrorType::GIT_FAILED_TO_PULL);
    }
}