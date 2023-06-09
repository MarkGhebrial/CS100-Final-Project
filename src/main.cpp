#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include "wizards.h"

#include "git/gitCommand.h"
#include "git/gitPull.h"
#include "git/gitPush.h"
#include "git/gitStatus.h"

#include "ui/prompts.h"

void printHelpMessage() {
    cout << R"(Usage: gb <command>

Commands:
  commit    Stage and commit your changes
  merge     Merge one branch into another
  branch    Create or delete a branch
  checkout  Switch to another branch
  sync      Pull and push your current branch
  discard   Discard changes on the working tree
  revert    Select commits to revert
  reset     Select a commit to roll history back to
  ignore    Untrack files and add them to .gitignore)" << endl;
}

int main(int argc, char** argv) {
    // Print the help message if the user did not provide a command line argument
    if (argc < 2) {
        printHelpMessage();
        return 0;
    }

    // The command line argument specified by the user
    string argument(argv[1]);

    if (argument == "commit") {
        commitWizard();
    }
    else if (argument == "merge") {
        mergeWizard();
    }
    else if (argument == "branch") {
        branchWizard();
    }
    else if (argument == "checkout") {
        checkoutWizard();
    }
    else if (argument == "sync") {
        sync();
    }
    else if (argument == "discard") {
        discardWizard();
    }
    else if (argument == "revert") {
        revertWizard();
    }
    else if (argument == "reset") {
        resetWizard();
    }
    else if (argument == "ignore") {
        ignoreWizard();
    } else {
        printHelpMessage();
    }
}