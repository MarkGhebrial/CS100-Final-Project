#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "git/gitCommand.h"
#include "git/gitStatus.h"

#include "ui/prompts.h"

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

    YesOrNoPrompt prompt("Print hello world?", YesOrNo::YES);
    auto promptResult = prompt.presentPrompt(cout, cin);

    if (promptResult == YesOrNo::YES) {
        cout << "Hello world" << endl;
    }
}