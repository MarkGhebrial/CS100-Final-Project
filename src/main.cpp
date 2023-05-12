#include <iostream>
using std::cout;
using std::endl;

#include "git/gitCommand.h"
#include "git/gitStatus.h"

int main() {
    std::cout << "Hello, world!" << std::endl;

    GitStatus cmd = GitStatus();
    auto result = cmd.run();

    for (auto fileName : result.stagedChanges) {
        cout << "Staged change: " << fileName << endl;
    }
    for (auto fileName : result.unstagedChanges) {
        cout << "Unstaged change: " << fileName << endl;
    }
    for (auto fileName : result.untrackedChanges) {
        cout << "Untracked change: " << fileName << endl;
    } 
}