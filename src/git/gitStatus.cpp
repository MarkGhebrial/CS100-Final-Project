#include "gitStatus.h"

#include <string>
#include <iostream>
#include <sstream>
using std::string;
using std::istringstream;

GitStatusResult::GitStatusResult(string gitOutput) {
    istringstream stream(gitOutput);

    // See the "Short Format" section of "git status --help" for more info
    string line;
    while (getline(stream, line)) {
        // The git documentation calls these characters "X" and "Y", so I am doing the same
        char x = line.at(0);
        char y = line.at(1);
        string filename = line.substr(3, line.size() - 1);

        if (x == '?' and y == '?') {
            untrackedChanges.push_back(filename);
            continue;
        }

        if (x != ' ') {
            stagedChanges.push_back(filename);
        }
        if (y != ' ') {
            unstagedChanges.push_back(filename);
        }
    }
}

GitStatusResult GitStatus::run() {
    string output = runCommand();
    istringstream stream(output);

    GitStatusResult result = GitStatusResult(output);

    return result;
}