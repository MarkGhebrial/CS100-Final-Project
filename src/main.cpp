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
    cout << "TODO: Write a help message" << endl;
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

    }
    else if (argument == "merge") {

    }
    else if (argument == "branch") {

    }
    else if (argument == "checkout") {

    }
    else if (argument == "sync") {
        GitPull pull = GitPull();
        pull.run();

        GitPush push = GitPush();
        push.run();
    }
    else if (argument == "discard") {

    }
    else if (argument == "revert") {

    }
    else if (argument == "reset") {

    }
    else if (argument == "ignore") {

    } else {
        printHelpMessage();
    }
}