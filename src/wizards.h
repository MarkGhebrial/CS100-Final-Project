// This file will only be included once (in main.cpp), so the functions can be defined inline

#include "ui/prompts.h"
#include "git/gitCommands.h"

#include <iostream>
#include <vector>
using namespace std;

/// Run git pull and git push
void sync() {
    GitPull pull = GitPull();
    pull.run();

    GitPush push = GitPush();
    push.run();
}

void commitWizard() {
    GitStatusResult result = GitStatus().run();

    // Print the status of the repository
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
    YesOrNoPrompt stageAllChangesPrompt = YesOrNoPrompt("Do you want to stage all changes?", YesOrNo::YES);
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
        MenuPrompt fileMenu = MenuPrompt("Select files to stage:", menuItems, MULTI);
        vector<string> selectedFiles = fileMenu.presentPrompt();

        if (selectedFiles.size() == 0) {
            cout << "No files selected, exiting." << endl;
            return;
        }

        addCommand = GitAdd(selectedFiles);
    } else {
        addCommand = GitAdd();
    }

    // Ask the user for a commit message
    StringPrompt commitMessagePrompt = StringPrompt("Enter a commit message");
    string commitMessage = commitMessagePrompt.presentPrompt(cout, cin);

    if (commitMessage == "") {
        cout << "TODO: Handle empty commit messages" << endl;
        return;
    }
    GitCommit commitCommand = GitCommit(commitMessage);

    // Ask if the user wants to pull and push
    YesOrNoPrompt syncPrompt = YesOrNoPrompt("Sync with remote?", YesOrNo::YES);
    YesOrNo syncResponse = syncPrompt.presentPrompt(cout, cin);

    // Confirm the user's intentions
    YesOrNoPrompt confirmChangesPrompt = YesOrNoPrompt("Apply changes?", YesOrNo::YES);
    if (confirmChangesPrompt.presentPrompt(cout, cin) == YesOrNo::NO) {
        cout << "Canceled. Your repository is untouched.";
        return;
    }

    // Run the git commands
    addCommand.run();
    commitCommand.run();
    if (syncResponse == YesOrNo::YES) sync();

    cout << "Done :)" << endl;
}

void mergeWizard() {} // Not implementing due to lack of time

void branchWizard() {}

void checkoutWizard() {
    GitListBranches userBranches = GitListBranches();

    vector <string> branches = userBranches.run();

    if (branches.size() < 2) {
        cout << "There is no other branch to checkout to." << endl;
        return;
    }
    else {
        MenuPrompt menuObject("Select a branch to checkout to:", branches, SINGLE); // We create a menu object from the vector that we recieve

        vector<string> userSelection = menuObject.presentPrompt();  // This will present the menu so user can select which branch they want to checkout to

        // If the user selects no files, then we just quit
        if (userSelection.size() == 0) {
            cout << "No files selected, exiting." << endl;
            return;
        }

        // Confirm the user's intentions
            YesOrNoPrompt confirmCheckoutPrompt = YesOrNoPrompt("Checkout to this branch?", YesOrNo::YES);
            if (confirmCheckoutPrompt.presentPrompt(cout, cin) == YesOrNo::NO) {
                cout << "Canceled. You did not checkout to that branch.";
                return;
            }

        // Run the git commands
        GitCheckout checkoutCommand(userSelection.at(0));
        checkoutCommand.run();
      

        cout << "Done :)" << endl;
    }

    //checkoutCommand.run();
}

// Not implementing functions below due to lack of time

void discardWizard() {}

void revertWizard() {}

void resetWizard() {}

void ignoreWizard() {}