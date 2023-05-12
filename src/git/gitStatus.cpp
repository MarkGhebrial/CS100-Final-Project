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

    // string status;
    // string fileName;
    // while (stream >> status >> fileName) {
    //     if (status == "M") { // Modified
    //         result.unstagedChanges.push_back(fileName);
    //     } else if (status == "??") { // Untracked
    //         result.untrackedChanges.push_back(fileName);
    //     } else if (status == "AM") { // Modified since it was last staged
    //         result.unstagedChanges.push_back(fileName);
    //         result.stagedChanges.push_back(fileName);
    //     } else if (status == "A") { // Staged
    //         result.stagedChanges.push_back(fileName);
    //     }
    // }



    // string line;
    // while (getline(stream, line)) {
    //     char x = line.at(0);
    //     char y = line.at(1);
    //     string filename = line.substr(3, line.size() - 1);

    //     if (x == '?' and y == '?') {
    //         result.untrackedChanges.push_back(filename);
    //         continue;
    //     }

    //     if (x != ' ') {
    //         result.stagedChanges.push_back(filename);
    //     }
    //     if (y != ' ') {
    //         result.unstagedChanges.push_back(filename);
    //     }
    // }

    return result;
}