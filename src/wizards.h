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
    // vector <string> menuPrompts; // This is going to be the vector of file names that Charlie 
    // //is working on
    // if (menuPrompts.size() < 2) {
    //     cout << "There is no other branch to checkout to." << endl;
    // }

    MenuPrompt menuObject(menuPrompts, SINGLE); // We create a menu object from the vector that we recieve

    vector<string> userSelection = menuObject.presentPrompt();  // This will present the menu so user can select which branch they want to checkout to

    // for (auto s : userSelection) {
    //     cout << s << endl;              // This couts their selection to the terminal, used for testing
    // }
    
    // Call the menu function to display the branch that the user can select from

    // If the user selects more than one branch, throw exeption
    // Todo(if we have time), make a new menu that only takes one selection from the user

    // After the user selects the branch, the menu is going to return a string vector with that branch
        // cout << "You have selected " << <branchName> << " branch." << endl;
        // cout << "Do you want to checkout to this branch?" << endl;
    // Ask the user to confirm if they want to checkout to this branch

    // create new git checkout object
}

// Not implementing functions below due to lack of time

void discardWizard() {}

void revertWizard() {}

void resetWizard() {}

void ignoreWizard() {}