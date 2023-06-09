#include "gitAdd.h"
#include "gitError.h"

#include <string>
#include <sstream>
using std::string;
using std::istringstream;

void GitAdd::run() {
    string output = runCommand();
    istringstream stream(output);

    string line;
    while (getline(stream, line)) {
        if (line.substr(0, 5) == "fatal") {
            throw GitError(GitErrorType::GIT_ADD_ERROR);
        }
    }
}