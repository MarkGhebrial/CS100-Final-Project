// This file will only be included once (in main.cpp), so the functions can be defined inline

#include "ui/prompts.h"
#include "git/gitCommands.h"

#include <iostream>
#include <vector>
using namespace std;

void commitWizard() {
    GitStatusResult result = GitStatus().run();

    // TODO: make this code nicer
    if (result.unstagedChanges.size() == 0) {
        cout << "Unstaged Changes: none" << endl;
    } else {
        cout << "Unstaged Changes: " << endl;
        for (string s : result.unstagedChanges) {
            cout << "    " << s << endl;
        }
    }

    if (result.untrackedChanges.size() == 0) {
        cout << "Untracked Changes: none" << endl;
    } else {
        cout << "Untracked Changes: " << endl;
        for (string s : result.untrackedChanges) {
            cout << "    " << s << endl;
        }
    }

    if (result.stagedChanges.size() == 0) {
        cout << "Staged Changes: none" << endl;
    } else {
        cout << "Staged Changes: " << endl;
        for (string s : result.stagedChanges) {
            cout << "    " << s << endl;
        }
    }

    GitAdd addCommand;

    // Ask the user if they want to stage all changes
    auto stageAllChangesPrompt = YesOrNoPrompt("Do you want to stage all changes?", YesOrNo::YES);
    if (stageAllChangesPrompt.presentPrompt(cout, cin) == YesOrNo::NO) {
        // If not, let them select the files they want to stage

        // Combine the vectors of unstaged and untracked files into menuItems
        vector<string> menuItems;
        for (string s : result.unstagedChanges) {
            menuItems.push_back(s);
        }
        for (string s : result.untrackedChanges) {
            menuItems.push_back(s);
        }

        // Create and show a menu to the user
        MenuPrompt fileMenu = MenuPrompt("Select files to stage:", menuItems);
        vector<string> selectedFiles = fileMenu.presentPrompt();

        if (selectedFiles.size() == 0) {
            cout << "No files selected, exiting." << endl;
            return;
        }

        addCommand = GitAdd(selectedFiles);
    } else {
        addCommand = GitAdd();
    }
}

void mergeWizard() {}

void branchWizard() {}

void checkoutWizard() {}

void discardWizard() {}

void revertWizard() {}

void resetWizard() {}

void ignoreWizard() {}